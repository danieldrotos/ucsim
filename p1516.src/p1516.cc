/*
 * Simulator of microcontrollers (p1516.cc)
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

#include "glob.h"

#include "p1516cl.h"


cl_p1516::cl_p1516(class cl_sim *asim):
  cl_uc(asim)
{
}

int
cl_p1516::init(void)
{
  int i;
  cl_uc::init();
  F= 0;
  for (i=0; i<16; i++)
    R[i]= 0;
  return 0;
}

char *
cl_p1516::id_string(void)
{
  return (char*)"P1516";
}

void
cl_p1516::reset(void)
{
  PC= R[15]= 0;
}
  
void
cl_p1516::set_PC(t_addr addr)
{
  PC= R[15]= addr;
}

void
cl_p1516::mk_hw_elements(void)
{
  //class cl_hw *h;
  cl_uc::mk_hw_elements();
  //add_hw(h= new cl_port(this));
  //h->init();
}

void
cl_p1516::make_memories(void)
{
  class cl_address_space *as;

  rom= as= new cl_address_space("rom"/*MEM_ROM_ID*/, 0, 0x10000, 32);
  as->init();
  address_spaces->add(as);

  class cl_address_decoder *ad;
  class cl_memory_chip *chip;

  chip= new cl_memory_chip("rom_chip", 0x10000, 32);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as= rom/*address_space(MEM_ROM_ID)*/,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}


struct dis_entry *
cl_p1516::dis_tbl(void)
{
  return(disass_p1516);
}

char *
cl_p1516::disass(t_addr addr, const char *sep)
{
  chars work= chars(), temp= chars();
  char *buf, *p;
  const char *b;
  t_mem code, data= 0;
  int i;

  //work= "";
  //p= (char*)work;

  code= rom->get(addr);
  
  i= 0;
  while ((code & dis_tbl()[i].mask) != dis_tbl()[i].code &&
	 dis_tbl()[i].mnemonic)
    i++;
  if (dis_tbl()[i].mnemonic == NULL)
    {
      buf= (char*)malloc(40);
      strcpy(buf, "-- UNKNOWN/INVALID");
      return(buf);
    }
  b= dis_tbl()[i].mnemonic;

  data= (code&0xf0000000)>>28;
  if (((data & 1) == 0) || (dis_tbl()[i].branch == 'M'))
    work.append("   ");
  else
    {
      switch (data>>2)
	{
	case 0: work.append("S"); break;
	case 1: work.append("C"); break;
	case 2: work.append("Z"); break;
	case 3: work.append("O"); break;
	}
      if (data&2)
	work.append("1 ");
      else
	work+= "0 ";
    }

  while (*b)
    {
      if (*b == '%')
	{
	  b++;
	  switch (*(b++))
	    {
	    case 'd': // Rd
	      data= (code & 0x00f00000)>>20;
	      temp.format("r%d", data);
	      break;
	    case 'a': // Ra
	      data= (code & 0x000f0000)>>16;
	      temp.format("r%d", data);
	      break;
	    case 'b': // Rb
	      data= (code & 0x0000f000)>>12;
	      temp.format("r%d", data);
	      break;
	    case '0': // LDL0
	      data= (code & 0x0000ffff);
	      temp.format("0x0000%04x", data);
	      break;
	    case 'O': // LDL0
	      data= (code & 0x0000ffff);
	      temp.format("0x%04x", data);
	      break;
	    case 'l': // LDL
	      data= (code & 0x0000ffff);
	      temp.format("0x....%04x", data);
	      break;
	    case 'h': // LDH
	      data= (code & 0x0000ffff);
	      temp.format("0x%04x....", data);
	      break;
	    case 'A': // CALL
	      data= (code & 0x07ffffff);
	      temp.format("0x%x", data);
	      break;
	    default:
	      temp= (char*)"?";
	      break;
	    }
	  //t= temp;
	  //while (*t) *(p++)= *(t++);
	  work+= temp;
	}
      else
	work.append(*(b++));
    }
  //*p= '\0';

  p= (char*)work;
  buf= strdup(p);
  return(buf);
}

void
cl_p1516::print_regs(class cl_console_base *con)
{
  int i;
  con->dd_color("answer");
  con->dd_printf("  F= 0x%x  ", F);
  con->dd_printf("S=%c ", (F&S)?'1':'0');
  con->dd_printf("C=%c ", (F&C)?'1':'0');
  con->dd_printf("Z=%c ", (F&Z)?'1':'0');
  con->dd_printf("O=%c ", (F&O)?'1':'0');
  con->dd_printf("\n");
  for (i= 0; i<16; i++)
    {
      if (i<10) con->dd_printf(" ");
      con->dd_printf("R%d= 0x%08x ", i, R[i]);
      if (i<10) con->dd_printf(" ");
      con->dd_printf("[R%d]= 0x%08x", i, rom->get(R[i]));
      if (i%2)
	con->dd_printf("\n");
      else
	con->dd_printf(" ");
    }
  print_disass(PC, con);
}


int
cl_p1516::inst_alu(t_mem code)
{
  u8_t Rd, Ra, Rb, Op;

  Rd= (code & 0x00f00000) >> 20;
  Ra= (code & 0x000f0000) >> 16;
  Rb= (code & 0x0000f000) >> 12;
  Op= (code & 0x00000f80) >> 7;

  switch (Op)
    {
    case 0:
      R[Rd]= R[Ra] + R[Rb];
      break;
    }
  
  return resGO;
}

int
cl_p1516::exec_inst(void)
{
  t_mem code;
  u8_t inst;
  u8_t cond;
  bool fe;
  
  PC= R[15];
  instPC= PC;
  fe= fetch(&code);
  tick(1);
  R[15]= PC;
  if (fe)
    return(resBREAKPOINT);

  cond= (code & 0xf0000000) >> 28;
  if ((cond&1) == 1)
    {
      u8_t flag, fv, v;
      switch (cond>>2)
	{
	case 0: flag= F&S; break;
	case 1: flag= F&C; break;
	case 2: flag= F&Z; break;
	case 3: flag= F&O; break;
	}
      fv= flag?1:0;
      v= (cond&2)?1:0;
      if (fv != v)
	return resGO;
    }
  
  inst= (code & 0x0f000000) >> 24;
  if (code & 0x08000000)
    {
      // CALL
      return resGO;
    }

  u8_t Rd, Ra;
  Rd= (code & 0x00f00000) >> 20;
  Ra= (code & 0x000f0000) >> 16;
  switch (inst)
    {
    case 0: // nop
      break;
    case 1: // LD Rd,Ra
      R[Rd]= rom->read(R[Ra]);
      vc.rd++;
      break;
    case 2: // ST Rd,Ra
      rom->write(R[Ra], R[Rd]);
      vc.wr++;
      break;
    case 3: // MOV Rd,Ra
      R[Rd]= R[Ra];
      break;
    case 4: // LDL0 Rd,data
      R[Rd]= code & 0x0000ffff;
      break;
    case 5: // LDL Rd,data
      R[Rd]= (R[Rd] & 0xffff0000) | (code & 0x0000ffff);
      break;
    case 6: // LDH Rd,data
      R[Rd]= (R[Rd] & 0x0000ffff) | (code << 16);
      break;
    case 7: // ALU
      inst_alu(code);
      break;
    }
  PC= R[15];
  
  return resGO;
}


/* End of p1516.src/p1516.cc */
