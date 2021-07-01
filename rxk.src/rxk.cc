/*
 * Simulator of microcontrollers (rxk.cc)
 *
 * Copyright (C) 2020,2021 Drotos Daniel, Talker Bt.
 * 
 * To contact author send email to drdani@mazsola.iit.uni-miskolc.hu
 *
 */

/* This file is part of microcontroller simulator: ucsim.

UCSIM is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

UCSIM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with UCSIM; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA. */
/*@1@*/

#include <stdlib.h>
#include <ctype.h>

#include "globals.h"
#include "utils.h"

#include "dregcl.h"

#include "glob.h"
#include "gp0m3.h"
#include "rmemcl.h"
#include "ddwrap.h"

#include "rxkcl.h"


cl_rxk::cl_rxk(class cl_sim *asim):
  cl_uc(asim)
{
  altd= 0;
  cRtab[0]= cB;
  cRtab[1]= cC;
  cRtab[2]= cD;
  cRtab[3]= cE;
  cRtab[4]= cH;
  cRtab[5]= cL;
  cRtab[7]= cA;
  caRtab[0]= caB;
  caRtab[1]= caC;
  caRtab[2]= caD;
  caRtab[3]= caE;
  caRtab[4]= caH;
  caRtab[5]= caL;
  caRtab[7]= caA;
}

int
cl_rxk::init(void)
{
  cl_uc::init();
  altd= prefix= false;
  fill_def_wrappers(itab);
  fill_dd_wrappers(itab_dd);
  
  xtal= 1000000;

#define RCV(R) reg_cell_var(&c ## R , &r ## R , "" #R "" , "CPU register " #R "")
  RCV(A);
  RCV(aA);
  RCV(F);
  RCV(aF);
  RCV(AF);
  RCV(aAF);
  RCV(B);
  RCV(aB);
  RCV(C);
  RCV(aC);
  RCV(BC);
  RCV(aBC);
  RCV(D);
  RCV(aD);
  RCV(E);
  RCV(aE);
  RCV(DE);
  RCV(aDE);
  RCV(H);
  RCV(aH);
  RCV(L);
  RCV(aL);
  RCV(HL);
  RCV(aHL);

  RCV(IX);
  RCV(IY);
  RCV(SP);

  RCV(IP);
  RCV(IIR);
  RCV(EIR);
#undef RCV

  XPC= new cl_cell8(8);
  reg_cell_var(XPC, &(mem->xpc),
	       "XPC", "MMU register: XPC");

  return 0;
}


const char *
cl_rxk::id_string(void)
{
  return "RXK";
}

void
cl_rxk::reset(void)
{
  cl_uc::reset();

  // MMU reset
  mem->dataseg= 0;
  mem->segsize= 0xff;
  mem->stackseg= 0;
  mem->xpc= 0;

  rIP= 0xff;
  rIIR= 0;
  rEIR= 0;
  rSP= 0;
}

  
void
cl_rxk::set_PC(t_addr addr)
{
  PC= addr;
}

void
cl_rxk::mk_hw_elements(void)
{
  class cl_hw *h;
  
  cl_uc::mk_hw_elements();

  add_hw(h= new cl_dreg(this, 0, "dreg"));
  h->init();
}

void
cl_rxk::make_cpu_hw(void)
{
  add_hw(cpu= new cl_rxk_cpu(this));
  cpu->init();
}

void
cl_rxk::make_memories(void)
{
  class cl_memory_chip *chip;
  class cl_address_space *as;
  class cl_address_decoder *ad;

  chip= new cl_chip8("rom_chip", 0x100000, 8);
  chip->init();
  memchips->add(chip);

  rwas= rom= as= mem= new cl_ras("rom", chip);
  as->init();
  address_spaces->add(as);

  /* IO */
  ioas= as= new cl_address_space("ioas", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  chip= new cl_chip8("io_chip", 0x10000, 8);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}

/*
struct dis_entry *
cl_rxk::dis_tbl(void)
{
  return(disass_rxk);
}
*/

struct dis_entry *
cl_rxk::dis_entry(t_addr addr)
{
  u8_t code= rom->get(addr);
  int i;
  struct dis_entry *dt= disass_rxk;
  i= 0;
  while (((code & dt[i].mask) != dt[i].code) &&
	 dt[i].mnemonic)
    i++;
  if (dt[i].mnemonic != NULL)
    return &dt[i];

  dt= disass_p0m3;
  i= 0;
  while (((code & dt[i].mask) != dt[i].code) &&
	 dt[i].mnemonic)
    i++;
  if (dt[i].mnemonic != NULL)
    return &dt[i];
  
  return &dt[i];
}

char *
cl_rxk::disassc(t_addr addr, chars *comment)
{
  chars work, temp;
  const char *b;
  t_mem code= rom->get(addr);
  struct dis_entry *dt;//= dis_tbl();//, *dis_e;
  int i;
  bool first;
  unsigned int x, h, l;

  if (code == 0xcb)
    return disassc_cb(addr, comment);
  
  dt= dis_entry(addr);
  if (!dt)
    return NULL;
  /*
  i= 0;
  while (((code & dt[i].mask) != dt[i].code) &&
	 dt[i].mnemonic)
    i++;
  //dis_e= &dt[i];
  */
  if (dt->mnemonic == NULL)
    return strdup("-- UNKNOWN/INVALID");
  b= dt->mnemonic;

  first= true;
  work= "";
  for (i=0; b[i]; i++)
    {
      if ((b[i] == ' ') && first)
	{
	  first= false;
	  while (work.len() < 6) work.append(' ');
	}
      if (b[i] == '%')
	{
	  temp= "";
	  i++;
	  switch (b[i])
	    {
	    case 'l': // 24 bit unsigned
	      l= rom->get(++addr);
	      h= rom->get(++addr);
	      x= rom->get(++addr);
	      work.appendf("0x%06x", x*0x10000+h*256+l);
	      break;
	    case 'w': // 16 bit unsigned
	      l= rom->get(++addr);
	      h= rom->get(++addr);
	      work.appendf("0x%04x", h*256+l);
	      break;
	    case 'b': // 8 bit unsigned
	      l= rom->get(++addr);
	      work.appendf("0x%02x", l);
	      break;
	    case 'd': // 8 bit signed
	      {
		i8_t r= rom->read(++addr);
		work.appendf("%d", r);
	      }
	      break;
	    case 'r': // 8 bit relative jump
	      {
		i8_t r= rom->get(++addr);
		t_addr a= addr + 1 + r;
		work.appendf("0x%04x", AU16(a));
	      }
	      break;
	    }
	  if (comment && temp.nempty())
	    comment->append(temp);
	}
      else
	work+= b[i];
    }

  return(strdup(work.c_str()));
}


char *
cl_rxk::disassc_cb(t_addr addr, chars *comment)
{
  u8_t code= rom->get(++addr);
  u8_t x, y, z;
  chars work, temp;
  char b[100];
  bool first= true;
  int i;
  const char *r[8]= { "B","C","D","E","H","L","(HL)","A" };

  x= code>>6;
  y= (code>>3)&7;
  z= code&7;
  switch (x)
    {
    case 0:
      switch (y)
	{
	case 0: strcpy(b, "RLC %r"); break;
	case 1: strcpy(b, "RRC %r"); break;
	case 2: strcpy(b, "RL %r"); break;
	case 3: strcpy(b, "RR %r"); break;
	case 4: strcpy(b, "SLA %r"); break;
	case 5: strcpy(b, "SRA %r"); break;
	case 6: return strdup("-- UNKNOWN/INVALID");
	case 7: strcpy(b, "SRL %r"); break;
	}
      break;
    case 1:
      strcpy(b, "BIT %y,%r");
      break;
    case 2:
      strcpy(b, "RES %y,%r");
      break;
    case 3:
      strcpy(b, "SET %y,%r");
      break;
    }
  temp= "";
  work= "";
  for (i= 0; b[i]; i++)
    {
      if ((b[i] == ' ') && first)
	{
	  first= false;
	  while (work.len() < 6) work.append(' ');
	}
      if (b[i] == '%')
	{
	  temp= "";
	  i++;
	  switch (b[i])
	    {
	    case 'y': work.appendf("%d", y); break;
	    case 'r': work.append(r[z]); break;
	    }
	  if (comment && temp.nempty())
	    comment->append(temp);
	}
      else
	work+= b[i];
    }

  return(strdup(work.c_str()));
}

int
cl_rxk::inst_length(t_addr addr)
{
  u8_t code= rom->get(addr);
  if (code == 0xcb)
    return 2;
  struct dis_entry *dt= dis_entry(addr);
  if (!dt) return 1;
  if (dt->mnemonic == NULL) return 1;
  return dt->length;
}

void
cl_rxk::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("A= 0x%02x %3d %c  ",
                 rA, rA, isprint(rA)?rA:'.');
  con->dd_printf("F= "); con->print_bin(rF, 8);
  con->dd_printf(" 0x%02x %3d %c", rF, rF, isprint(rF)?rF:'.');
  con->dd_printf("\n");
  con->dd_printf("                  SZxxxVxC\n");

  con->dd_printf("XPC= 0x%02x IP= 0x%02x IIR= 0x%02x EIR= 0x%02x\n",
		 mem->xpc, rIP, rIIR, rEIR);
  
  con->dd_printf("BC= ");
  rom->dump(0, rBC, rBC+7, 8, con);
  con->dd_color("answer");
  con->dd_printf("DE= ");
  rom->dump(0, rDE, rDE+7, 8, con);
  con->dd_color("answer");
  con->dd_printf("HL= ");
  rom->dump(0, rHL, rHL+7, 8, con);
  con->dd_color("answer");
  con->dd_printf("IX= ");
  rom->dump(0, rIX, rIX+7, 8, con);
  con->dd_color("answer");
  con->dd_printf("IY= ");
  rom->dump(0, rIY, rIY+7, 8, con);
  con->dd_color("answer");
  con->dd_printf("SP= ");
  rom->dump(0, rSP, rSP+7, 8, con);
  con->dd_color("answer");

  con->dd_printf("aAF= 0x%02x-0x%02x  ", raA, raF);
  con->dd_printf("aBC= 0x%02x-0x%02x  ", raB, raC);
  con->dd_printf("aDE= 0x%02x-0x%02x  ", raD, raE);
  con->dd_printf("aHL= 0x%02x-0x%02x  ", raH, raL);
  con->dd_printf("\n");
  
  print_disass(PC, con);
}

class cl_cell8 &
cl_rxk::cR(u8_t z)
{
  if (z == 6)
    return *((cl_cell8*)(rom->get_cell(rHL)));
  return cRtab[z];
}

u8_t
cl_rxk::rR(u8_t z)
{
  return cR(z).R();
}

class cl_cell8 &
cl_rxk::destR(u8_t z)
{
  if (z == 6)
    {
      return *((cl_cell8*)(rwas->get_cell(rHL)));
    }
  if (altd)
    return caRtab[z];
  return cRtab[z];
}

int
cl_rxk::exec_inst(void)
{
  t_mem code;
  int res= resGO;

  if (!prefix)
    {
      rwas= rom;
      altd= false;
    }
  prefix= false;
  if ((res= exec_inst_tab(itab)) == resNOT_DONE)
    {
      fetch(&code);
      res= inst_unknown(code);
    }
  
  return res;
}

int
cl_rxk::inst_unknown(t_mem code)
{
  cl_uc::inst_unknown(code);
  return resINV_INST;
}

u8_t
cl_rxk::op8_BC(void)
{
  u8_t v= rom->read(rBC);
  vc.rd++;
  return v;
}

u8_t
cl_rxk::op8_DE(void)
{
  u8_t v= rom->read(rDE);
  vc.rd++;
  return v;
}


u8_t
cl_rxk::op8_HL(void)
{
  u8_t v= rom->read(rHL);
  vc.rd++;
  return v;
}

u16_t
cl_rxk::op16_BC(void)
{
  u8_t l, h;
  l= rom->read(rBC);
  h= rom->read(rBC+1);
  vc.rd+= 2;
  return h*256+l;
}

u16_t
cl_rxk::op16_DE(void)
{
  u8_t l, h;
  l= rom->read(rDE);
  h= rom->read(rDE+1);
  vc.rd+= 2;
  return h*256+l;
}

u16_t
cl_rxk::op16_HL(void)
{
  u8_t l, h;
  l= rom->read(rHL);
  h= rom->read(rHL+1);
  vc.rd+= 2;
  return h*256+l;
}


/*
 * CPU peripheral: MMU functions
 */

cl_rxk_cpu::cl_rxk_cpu(class cl_uc *auc):
  cl_hw(auc, HW_CPU, 0, "cpu")
{
  ruc= (class cl_rxk *)auc;
}

int
cl_rxk_cpu::init(void)
{
  cl_hw::init();

  stackseg= (cl_cell8*)ruc->ioas->get_cell(0x11);
  dataseg = (cl_cell8*)ruc->ioas->get_cell(0x12);
  segsize = (cl_cell8*)ruc->ioas->get_cell(0x13);

  uc->reg_cell_var(stackseg, &(ruc->mem->stackseg),
		   "STACKSEG", "MMU register: STACKSEG");
  uc->reg_cell_var(dataseg, &(ruc->mem->dataseg),
		   "DATASEG", "MMU register: DATASEG");
  uc->reg_cell_var(segsize, &(ruc->mem->segsize),
		   "SEGSIZE", "MMU register: SEGSIZE");

  return 0;
}

const char *
cl_rxk_cpu::cfg_help(t_addr addr)
{
  switch (addr)
    {
      //case rxk_cpu_xpc: return "MMU register: XPC";
      //case rxk_cpu_nuof: return "";
    }
  return "Not used";
}

/*
t_mem
cl_rxk_cpu::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  switch ((enum rxkcpu_cfg)addr)
    {
    case rxk_cpu_xpc:
      if (val) cell->set(ruc->mem->xpc= *val);
      return ruc->mem->xpc;
    case rxk_cpu_nuof:
      return 0;
    }
  return 0;

  if (val)
    cell->set(*val);
  return cell->get();
}
*/

void
cl_rxk_cpu::print_info(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("%s[%d]\n", id_string, id);
  con->dd_printf("SEGSIZE : 0x%02x\n", segsize->read());
  con->dd_printf("DATASEG : 0x%02x\n", dataseg->read());
  con->dd_printf("STACKSEG: 0x%02x\n", stackseg->read());
  //con->dd_printf("XPC     : 0x%02x\n", xpc->read());
  con->dd_printf("Prefix: %s\n", ruc->prefix?"true":"false");
  con->dd_printf("ALTD  : %s\n", ruc->altd?"true":"false");
  con->dd_printf("Mem op: %s\n", ruc->rwas->get_name());
}


/* End of rxk.src/rxk.cc */
