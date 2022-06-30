/*
 * Simulator of microcontrollers (i8085.cc)
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

#include "i8085cl.h"


cl_i8085::cl_i8085(class cl_sim *asim):
  cl_i8080(asim)
{
}

int
cl_i8085::init(void)
{
  cl_i8080::init();
  fill_def_wrappers(itab);
  set_xtal(1000000);
  return 0;
}


const char *
cl_i8085::id_string(void)
{
  return "i8085";
}

void
cl_i8085::reset(void)
{
  cl_i8080::reset();
}

void
cl_i8085::set_PC(t_addr addr)
{
  PC= addr;
}


void
cl_i8085::mk_hw_elements(void)
{
  //class cl_hw *h;
  cl_i8080::mk_hw_elements();
}


void
cl_i8085::make_cpu_hw(void)
{
  cpu= new cl_i8085_cpu(this);
  add_hw(cpu);
  cpu->init();
}

void
cl_i8085::make_memories(void)
{
  /*
  class cl_address_space *as;
  class cl_address_decoder *ad;
  class cl_memory_chip *chip;
  */
  
  cl_i8080::make_memories();
}


struct dis_entry *
cl_i8085::get_dis_entry(t_addr addr)
{
  t_mem code= rom->get(addr);

  for (struct dis_entry *de = disass_8085; de && de->mnemonic; de++)
    {
      if ((code & de->mask) == de->code)
        return de;
    }
  for (struct dis_entry *de = disass_common; de && de->mnemonic; de++)
    {
      if ((code & de->mask) == de->code)
        return de;
    }

  return NULL;
}

void
cl_i8085::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("SZ-A-P-C  Flags= 0x%02x %3d %c  ",
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

  int i;
  con->dd_cprintf("answer", "SP= ");
  con->dd_cprintf("dump_address", "0x%04x ->", rSP);
  for (i= 0; i < 2*12; i+= 2)
    {
      t_addr al, ah;
      al= (rSP+i)&0xffff;
      ah= (al+1)&0xffff;
      con->dd_cprintf("dump_number", " %02x%02x",
		      (u8_t)(rom->read(al)),
		      (u8_t)(rom->read(ah)));
    }
  con->dd_printf("\n");
  
  print_disass(PC, con);
}


cl_i8085_cpu::cl_i8085_cpu(class cl_uc *auc):
  cl_hw(auc, HW_CPU, 0, "cpu")
{
}

int
cl_i8085_cpu::init(void)
{
  cl_hw::init();

  cl_var *v;
  uc->vars->add(v= new cl_var("sp_limit", cfg, i8085cpu_sp_limit,
			      cfg_help(i8085cpu_sp_limit)));
  v->init();

  return 0;
}

const char *
cl_i8085_cpu::cfg_help(t_addr addr)
{
  switch (addr)
    {
    case i8085cpu_sp_limit:
      return "Stack overflows when SP is below this limit";
    }
  return "Not used";
}

t_mem
cl_i8085_cpu::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  class cl_i8085 *u= (class cl_i8085 *)uc;
  if (val)
    cell->set(*val);
  switch ((enum i8085cpu_confs)addr)
    {
    case i8085cpu_sp_limit:
      if (val)
	u->sp_limit= *val & 0xffff;
      else
	cell->set(u->sp_limit);
      break;
    case i8080cpu_nuof: break;
    }
  return cell->get();
}


/* End of i8085.src/i8085.cc */
