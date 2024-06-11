/*
 * Simulator of microcontrollers (oisc.cc)
 *
 * Copyright (C) 2022 Drotos Daniel, Talker Bt.
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

#include <ctype.h>

#include "utils.h"

#include "dregcl.h"

#include "glob.h"

#include "oisccl.h"


/*
 * CPU
 */

cl_oisc::cl_oisc(class cl_sim *asim):
  cl_uc(asim)
{
}


int
cl_oisc::init(void)
{
  cl_uc::init();
  return 0;
}


void
cl_oisc::make_cpu_hw(void)
{
  /*
  cpu= new cl_oisc_cpu(this);
  add_hw(cpu);
  cpu->init();
  */
}


void
cl_oisc::mk_hw_elements(void)
{
  cl_uc::mk_hw_elements();
  class cl_hw *h;
  /*
  p0= new cl_qport(this, 0, ports, 0, port_8bit);
  p0->init();
  add_hw(p0);
  p1= new cl_qport(this, 1, ports, 1, port_8bit);
  p1->init();
  add_hw(p1);
  p2= new cl_p2(this, 2, ports, 2, port_4bit);
  p2->init();
  add_hw(p2);
  */

  h= new cl_dreg(this, 0, "dreg");
  h->init();
  add_hw(h);
}

void
cl_oisc::make_memories(void)
{
  class cl_address_space *as;
  class cl_address_decoder *ad;
  class cl_memory_chip *chip;
  
  rom= as= new cl_address_space("rom", 0, 0x10000, 16);
  as->init();
  address_spaces->add(as);

  chip= new cl_chip8("rom_chip", 0x10000, 16);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as= rom,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}


struct dis_entry *
cl_oisc::dis_tbl(void)
{
  return NULL;
}

char *
cl_oisc::disassc(t_addr addr, chars *comment)
{
  chars work= chars(), temp= chars(), fmt= chars();
  const char *b;
  int i;
  bool first;
  //u8_t h, l, r;
  u16_t code;
  u16_t a;

  code= rom->read(addr);
  
  b= "mov %d,%s";

  first= true;
  work= "";
  for (i=0; b[i]; i++)
    {
      if ((b[i] == ' ') && first)
	{
	  first= false;
	  while (work.len() < 6) work.append(' ');
	}
      if (b[i] == '\'')
	{
	  fmt= "";
	  i++;
	  while (b[i] && (b[i]!='\''))
	    fmt.append(b[i++]);
	  if (!b[i]) i--;
	  if (fmt.empty())
	    work.append("'");
	  /*
	  if (strcmp(fmt.c_str(), "i8") == 0)
	    {
	      work.appendf("#0x%02x", rom->read(addr+1));
	    }
	  */
	  if (comment && temp.nempty())
	    comment->append(temp);
	  continue;
	}
      if (b[i] == '%')
	{
	  i++;
	  temp= "";
	  switch (b[i])
	    {
	    case 's':
	      work.appendf("0x%04x", code);
	      break;
	    case 'd':
	      work.appendf("0x%04x", rom->read(addr+1));
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

int
cl_oisc::inst_length(t_addr addr)
{
  return 2;
}

void
cl_oisc::reset(void)
{
}

int
cl_oisc::exec_inst(void)
{
  bool ret= do_brk();
  if (!ret)
    {
      u16_t src= rom->read(PC);
      u16_t dst= rom->read((PC+1) & 0xffff);
      u16_t tmp= rom->read(src);
      PC+= 2;
      PC&= 0xffff;
      rom->write(dst, tmp);
    }
  return ret;
}


void
cl_oisc::print_regs(class cl_console_base *con)
{
  /*
  int start, stop, i;
  //t_mem data;
  u16_t dp;
  // show regs
  start= (psw & flagBS)?24:0;
  con->dd_color("answer");
  con->dd_printf("        R0 R1 R2 R3 R4 R5 R6 R7    PSW= CAF%c-SSS    ACC= ",
		 (type->type & CPU_MCS21)?'-':'B');
  con->dd_color("dump_number");
  con->dd_printf("0x%02x %+3d %c", ACC, ACC, (isprint(ACC)?ACC:'?'));
  con->dd_printf("\n");
  con->dd_cprintf("dump_address", "   0x%02x", start);
  for (int ii= 0; ii < 8; ii++)
    con->dd_cprintf("dump_number", " %02x", iram->get(start + ii));
  con->dd_cprintf("dump_number", "    0x%02x ", psw);
  con->dd_color("dump_number");
  con->print_bin(psw, 8);
  con->dd_printf("    DBF=%d F1=%d", mb, flagF1);
  con->dd_printf("\n");
  // show indirectly addressed IRAM and some basic regs
  start= R[0]->get();
  stop= start+7;
  con->dd_color("answer");
  con->dd_printf("R0=");
  class cl_dump_ads ads(start, stop);
  iram->dump(0, &ads, 8, con);
  start= R[1]->get();
  stop= start+7;
  con->dd_color("answer");
  con->dd_printf("R1=");
  ads._ss(start, stop);
  iram->dump(0, &ads, 8, con);

  con->dd_cprintf("answer", "SP=%d", psw&7);
  start= 8;
  stop= psw&7;
  for (i= 7; i>=0; i--)
    {
      dp= iram->read(start+2*i+1) * 256 + iram->read(start+2*i);
      con->dd_cprintf("dump_address", " %x", dp>>12);
      if (i<stop)
	con->dd_color("dump_address");
      else
	con->dd_color("dump_number");
      con->dd_printf(".%03x", dp&0xfff);
    }
  con->dd_printf("\n ");
  con->dd_color("answer");
  for (i= 7; i>=0; i--)
    {
      con->dd_printf("    %d", i);
      con->dd_printf("%c", (i==(psw&7))?'^':' ');
	
    }
  con->dd_printf("\n");
  */
  print_disass(PC, con);
}

/* End of oisc.src/oisc.cc */
