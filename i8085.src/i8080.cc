/*
 * Simulator of microcontrollers (i8080.cc)
 *
 * Copyright (C) @@S@@,@@Y@@ Drotos Daniel, Talker Bt.
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

#include <ctype.h>

#include "utils.h"

#include "i8080cl.h"

cl_i8080::cl_i8080(class cl_sim *asim):
  cl_uc(asim)
{
}

int
cl_i8080::init(void)
{
  cl_uc::init();
  fill_def_wrappers(itab);
  set_xtal(1000000);

#define RCV(R) reg_cell_var(&c ## R , &r ## R , "" #R "" , "CPU register " #R "")
  RCV(AF); RCV(A); RCV(F);
  RCV(BC); RCV(B); RCV(C);
  RCV(DE); RCV(D); RCV(E);
  RCV(HL); RCV(H); RCV(L);
#undef RCV
  
  return 0;
}

const char *
cl_i8080::id_string(void)
{
  return "i8080";
}

void
cl_i8080::reset(void)
{
  cl_uc::reset();
  PC= 0;
}

void
cl_i8080::set_PC(t_addr addr)
{
  PC= addr;
}

void
cl_i8080::mk_hw_elements(void)
{
  cl_uc::mk_hw_elements();
}

void
cl_i8080::make_cpu_hw(void)
{
}

void
cl_i8080::make_memories(void)
{
  class cl_address_space *as;
  class cl_address_decoder *ad;
  class cl_memory_chip *chip;
  
  rom= as= new cl_address_space("rom", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  chip= new cl_chip8("rom_chip", 0x10000, 8);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as= rom,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}


struct dis_entry *
cl_i8080::dis_tbl(void)
{
  return(disass_i8080);
}

struct dis_entry *
cl_i8080::get_dis_entry(t_addr addr)
{
  t_mem code= rom->get(addr);

  for (struct dis_entry *de = dis_tbl(); de && de->mnemonic; de++)
    {
      if ((code & de->mask) == de->code)
        return de;
    }

  return NULL;
}

char *
cl_i8080::disassc(t_addr addr, chars *comment)
{
  chars work= chars(), temp= chars();
  const char *b;
  struct dis_entry *de;
  int i;
  bool first;
  u8_t h, l;
  u16_t a;

  de= get_dis_entry(addr);

  if (!de || !de->mnemonic)
    return strdup("-- UNKNOWN/INVALID");

  b= de->mnemonic;

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
	  i++;
	  temp= "";
	  switch (b[i])
	    {
	    }
	  if (comment && temp.nempty())
	    comment->append(temp);
	}
      else
	work+= b[i];
    }

  return(strdup(work.c_str()));
}

void
cl_i8080::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("SZ-A-PNC  Flags= 0x%02x %3d %c  ",
                 rF, rF, isprint(rF)?rF:'.');
  con->dd_printf("A= 0x%02x %3d %c\n",
                 rA, rA, isprint(rA)?rA:'.');
  con->dd_printf("%s\n", cbin(rF, 8).c_str());
  con->dd_printf("BC= 0x%04x [BC]= 0x%02x %3d %c\n",
                 rBC, rom->get(rBC), rom->get(rBC),
                 isprint(rom->get(rBC))?rom->get(rBC):'.');
  con->dd_printf("DE= 0x%04x [DE]= 0x%02x %3d %c\n",
                 rDE, rom->get(rDE), rom->get(rDE),
                 isprint(rom->get(rDE))?rom->get(rDE):'.');
  con->dd_printf("HL= 0x%04x [HL]= 0x%02x %3d %c\n",
                 rHL, rom->get(rHL), rom->get(rHL),
                 isprint(rom->get(rHL))?rom->get(rHL):'.');
  print_disass(PC, con);
}


int
cl_i8080::exec_inst(void)
{
  int res;

  if ((res= exec_inst_tab(itab)) != resNOT_DONE)
    return res;

  inst_unknown(rom->read(instPC));
  return(resINV_INST);
}

/* End of i8085.src/i8080.cc */
