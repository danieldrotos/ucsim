/*
 * Simulator of microcontrollers (m68hc12.cc)
 *
 * Copyright (C) 2020,20 Drotos Daniel, Talker Bt.
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
#include <string.h>

#include "globals.h"
#include "utils.h"

#include "dregcl.h"

#include "wraps.h"
#include "hcwrapcl.h"
#include "glob12.h"
#include "m68hc12cl.h"

class cl_m68hc12 *uc;


/*
 * CCR
 */

t_mem
cl_ccr::write(t_mem val)
{
  u8_t act= d();
  act&= flagX;
  if (act == 0)
    val&= ~flagX;
  return cl_cell8::write(val);
}


/*
 * M68HC12 processor
 */

int
cl_m68hc12::proba(int i, t_mem code)
{
  return i;
}



cl_m68hc12::cl_m68hc12(class cl_sim *asim):
  cl_m68hcbase(asim)
{
  IRQ_AT	= 0xfff2;
  XIRQ_AT	= 0xfff4;
  SWI_AT	= 0xfff6;
  TRAP_AT	= 0xfff8;
  COP_AT	= 0xfffa;
  CMR_AT	= 0xfffc;
  RESET_AT	= 0xfffe;
  class cl_ccr c;
  memcpy((void*)&cCC, (void*)&c, sizeof(class cl_cell8));
  hc12wrap= new cl_12wrap();
  hc12wrap->init();
}

int
cl_m68hc12::init(void)
{
  int i;
  
  cl_m68hcbase::init();
#define RCV(R) reg_cell_var(&c ## R , &r ## R , "" #R "" , "CPU register " #R "")
  RCV(TMP2);
  RCV(TMP3);
  
  set_xtal(8000000);

  for (i= 0; i<=255; i++)
    itab[i]= instruction_wrapper_invalid;

  tex_cells[0]= &cA;
  tex_cells[1]= &cB;
  tex_cells[2]= &cCC;
  tex_cells[3]= &cTMP3;
  tex_cells[4]= &cD;
  tex_cells[5]= &cX;
  tex_cells[6]= &cY;
  tex_cells[7]= &cSP;

  tex_names[0]= "A";
  tex_names[1]= "B";
  tex_names[2]= "CCR";
  tex_names[3]= "TMP3";
  tex_names[4]= "D";
  tex_names[5]= "X";
  tex_names[6]= "Y";
  tex_names[7]= "SP";
  
  return 0;
}


const char *
cl_m68hc12::id_string(void)
{
  return "M68HC12";
}

void
cl_m68hc12::reset(void)
{
  cl_m68hcbase::reset();
  rCC= 0x80;
  //post_inc_dec= 0;
}

void
cl_m68hc12::make_memories(void)
{
  class cl_address_space *as;
  class cl_address_decoder *ad;
  class cl_memory_chip *chip;
  
  rom= as= new cl_address_space("rom", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  chip= new cl_chip8("rom_chip", 0x400000, 8);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as= rom,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}

void
cl_m68hc12::make_cpu_hw(void)
{
  add_hw(cpu12= new cl_hc12_cpu(this));
  cpu12->init();
  cpu= cpu12;
}

int
CL12::exec_inst(void)
{
  int res= resGO;
  t_mem code;
  hcwrapper_fn fn= NULL;
  cI= &cIX;
  code= fetch();
  if (code==0x18)
    {
      code= fetch();
      fn= hc12wrap->page0x18[code];
    }
  else
    {
      fn= hc12wrap->page0[code];
    }
  if (fn)
    fn(this, code);
  post_inst();
  if (res != resNOT_DONE)
    return res;

  inst_unknown(rom->read(instPC));
  return(res);
}

void
CL12::post_inst(void)
{
  /*
  if (post_inc_dec)
    post_idx_reg->W(post_idx_reg->R() + post_inc_dec);
  post_inc_dec= 0;
  */
}

i16_t
CL12::s8_16(u8_t op)
{
  if (op&0x80)
    return 0xff00 | op;
  return op;
}

t_addr
CL12::naddr(t_addr *addr /* of xb */)
{
  u8_t p, h, l;
  i16_t offset= 0;
  u16_t ival= 0, a= 0;
  //i8_t post_inc_dec= 0;
  class cl_cell16 *post_idx_reg= NULL;

  if (addr)
    {
      p= rom->read(*addr);
      (*addr)++;
    }
  else
    p= fetch();
  
  if ((p & 0x20) == 0)
    {
      // 1. rr0n nnnn n5,r rr={X,Y,SP,PC}
      switch (p & 0xc0)
	{
	case 0x00: ival= rX; break;
	case 0x40: ival= rY; break;
	case 0x80: ival= rSP; break;
	case 0xc0:
	  if (addr)
	    ival= (*addr)&0xffff;
	  else
	    ival= PC&0xffff;
	  break;
	}
      offset= p&0x1f;
      if (p&0x10) offset|= 0xffe0;
      return ival+offset;
    }
  
  else if ((p&0xe7) == 0xe7)
    {
      // 6. 111r r111 [D,r] rr={X,Y,SP,PC}
      switch (p & 0x18)
	{
	case 0x00: ival= rX; break;
	case 0x10: ival= rY; break;
	case 0x08: ival= rSP; break;
	case 0x18:
	  if (addr)
	    ival= (*addr)&0xffff;
	  else
	    ival= PC&0xffff;
	  break;
	}
      offset= rD;
      a= ival+offset;
      return read_addr(rom, a);
    }
  
  else if ((p&0xe7) == 0xe3)
    {
      // 5. 111r r011 [n16,r] rr={X,Y,SP,PC}
      switch (p & 0x18)
	{
	case 0x00: ival= rX; break;
	case 0x10: ival= rY; break;
	case 0x08: ival= rSP; break;
	case 0x18:
	  if (addr)
	    ival= (*addr)&0xffff;
	  else
	    ival= PC&0xffff;
	  break;
	}
      if (addr)
	{
	  h= rom->read(*addr);
	  (*addr)++;
	  l= rom->read(*addr);
	  (*addr)++;
	}
      else
	{
	  h= fetch();
	  l= fetch();
	}
      offset= h*256+l;
      a= ival+offset;
      return read_addr(rom, a);
    }
  
  else if ((p&0xc0) != 0xc0)
    {
      // 3. rr1p nnnn n4,+-r+- rr={X,Y,SP}
      switch (p & 0xc0)
	{
	case 0x00: ival= rX; post_idx_reg= &cX; break;
	case 0x40: ival= rY; post_idx_reg= &cY; break;
	case 0x80: ival= rSP; post_idx_reg= &cSP; break;
	}
      i8_t n= p&0xf;
      if (n&0x08) n|= 0xf0;
      if (p&0x10)
	{
	  // post +-
	  if (!addr)
	    {
	      //post_inc_dec= n;
	      post_idx_reg->W(post_idx_reg->R() + n);
	    }
	}
      else
	{
	  // pre +-
	  ival= (post_idx_reg->R() + n);
	  if (!addr)
	    post_idx_reg->W(ival);
	}
      return ival;
    }
  
  else if ((p&0xe4) == 0xe0)
    {
      // 2. 111r r0zs n9/16,r rr={X,Y,SP,PC}
      switch (p & 0x18)
	{
	case 0x00: ival= rX; break;
	case 0x10: ival= rY; break;
	case 0x08: ival= rSP; break;
	case 0x18:
	  if (addr)
	    ival= (*addr)&0xffff;
	  else
	    ival= PC&0xffff;
	  break;
	}
      if ((p&0x02) == 0x00)
	{
	  // 9 bit
	  if (addr)
	    {
	      offset= rom->read(*addr);
	      (*addr)++;
	    }
	  else
	    offset= fetch();
	  if (p&0x01) offset|= 0xff00;
	}
      else
	{
	  // 16 bit
	  if (addr)
	    {
	      h= rom->read(*addr);
	      (*addr)++;
	      l= rom->read(*addr);
	      (*addr)++;
	    }
	  else
	    {
	      h= fetch();
	      l= fetch();
	    }
	  offset= h*256+l;
	}
      return ival+offset;
    }
  
  else // if ((p&0xe4) == 0xe4)
    {
      // 4. 111r r1aa {A,B,D},r rr={X,Y,SP,PC}
      switch (p & 0x18)
	{
	case 0x00: ival= rX; break;
	case 0x10: ival= rY; break;
	case 0x08: ival= rSP; break;
	case 0x18:
	  if (addr)
	    ival= (*addr)&0xffff;
	  else
	    ival= PC&0xffff;
	  break;
	}
      switch (p&0x03)
	{
	case 0x00: offset= s8_16(rA); break;
	case 0x01: offset= s8_16(rB); break;
	case 0x02: offset= rD; break;
	}
      return ival+offset;
    }
  
  return a;
}

u8_t
CL12::xbop8()
{
  u16_t a= naddr(NULL);
  return rom->read(a);
}

u16_t
CL12::xbop16()
{
  u16_t a= naddr(NULL);
  u8_t h, l;
  h= rom->read(a);
  l= rom->read(a+1);
  return h*256+l;
}

class cl_memory_cell &
CL12::xb(void)
{
  t_addr a= naddr(NULL);
  class cl_cell8 *c= (class cl_cell8 *)rom->get_cell(a);
  return *c;
}

void
CL12::push_regs(bool inst_part)
{
  rom->write(--rSP, PC&0xff);
  rom->write(--rSP, PC>>8);
  rom->write(--rSP, rIY&0xff);
  rom->write(--rSP, rIY>>8);
  rom->write(--rSP, rIX&0xff);
  rom->write(--rSP, rIX>>8);
  rom->write(--rSP, rA);
  rom->write(--rSP, rB);
  rom->write(--rSP, rCC);
}

void
CL12::pull_regs(bool inst_part)
{
  u8_t l, h;
  rCC= rom->read(rSP++);
  rB= rom->read(rSP++);
  rA= rom->read(rSP++);
  h= rom->read(rSP++);
  l= rom->read(rSP++);
  rIX= h*256+l;
  h= rom->read(rSP++);
  l= rom->read(rSP++);
  rIY= h*256+l;
  h= rom->read(rSP++);
  l= rom->read(rSP++);
  PC= h*256+l;
}

int
CL12::trap(t_mem code)
{
  push_regs(true);
  PC= read_addr(rom, TRAP_AT);
  return resGO;
}


void
cl_m68hc12::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("A= $%02x %3d %+4d %c  ", rA, rA, (i8_t)rA, isprint(rA)?rA:'.');
  con->dd_printf("B= $%02x %3d %+4d %c  ", rB, rB, (i8_t)rB, isprint(rB)?rB:'.');
  con->dd_printf("   D= $%04x %5d %+5d ", rD, rD, (i16_t)rD);
  con->dd_printf("\n");
  con->dd_printf("CC= "); con->print_bin(rF, 8);
  con->dd_printf("                          TMP2= $%04x %5d %+5d",
		 rTMP2, rTMP2, rTMP2);
  con->dd_printf("\n");
  con->dd_printf("    SXHINZVC");
  con->dd_printf("                          TMP3= $%04x %5d %+5d",
		 rTMP3, rTMP3, rTMP3);
  con->dd_printf("\n");

  con->dd_printf("IX= ");
  rom->dump(0, IX, IX+7, 8, con);
  con->dd_color("answer");
  
  con->dd_printf("IY= ");
  rom->dump(0, IY, IY+7, 8, con);
  con->dd_color("answer");
  
  con->dd_printf("SP= ");
  rom->dump(0, SP, SP+7, 8, con);
  con->dd_color("answer");
  
  print_disass(PC, con);
}


/*
 * CPU peripheral for HC12 cpu
 */

cl_hc12_cpu::cl_hc12_cpu(class cl_uc *auc):
  cl_hw(auc, HW_CPU, 0, "cpu")
{
  muc= (class cl_m68hc12 *)auc;
}

int
cl_hc12_cpu::init(void)
{
  class cl_cvar *v;
  cl_hw::init();
  
  ppage= register_cell(muc->rom, 0x0035);
  dpage= register_cell(muc->rom, 0x0034);
  epage= register_cell(muc->rom, 0x0036);
  windef= register_cell(muc->rom, 0x0037);

  uc->vars->add(v= new cl_var("PPAGE", muc->rom, 0x0035,
			      "Program page register"));
  v->init();
  uc->vars->add(v= new cl_var("DPAGE", muc->rom, 0x0034,
			      "Data page register"));
  v->init();
  uc->vars->add(v= new cl_var("EPAGE", muc->rom, 0x0036,
			      "Extra page register"));
  v->init();
  uc->vars->add(v= new cl_var("WINDEF", muc->rom, 0x0037,
			      "Window definition register"));
  v->init();
  return 0;
}

void
cl_hc12_cpu::reset(void)
{
  ppage->write(0);
  dpage->write(0);
  epage->write(0);
  windef->write(0);
}

void
cl_hc12_cpu::print_info(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("PPAGE= $%02x\n", ppage->read());
  con->dd_printf("DPAGE= $%02x\n", dpage->read());
  con->dd_printf("EPAGE= $%02x\n", epage->read());
  u8_t w= windef->read();
  con->dd_printf("PWEN= %d\n", (w&0x40)?1:0);
  con->dd_printf("DWEN= %d\n", (w&0x80)?1:0);
  con->dd_printf("EWEN= %d\n", (w&0x20)?1:0);
}

t_mem
cl_hc12_cpu::ppage_write(u8_t val)
{
  return ppage->write(val);
}


/* End of m68hc12.src/m68hc12.cc */
