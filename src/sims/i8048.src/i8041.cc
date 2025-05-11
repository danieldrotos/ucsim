/*
 * Simulator of microcontrollers (i8041.cc)
 *
 * Copyright (C) 2022 Drotos Daniel
 * 
 * To contact author send email to dr.dkdb@gmail.com
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

#include "i8041cl.h"


/*
 * CPU
 */

cl_i8041::cl_i8041(class cl_sim *asim):
  cl_i8048(asim)
{
  rom_size= 1024;
  ram_size= 64;
  info_ch= '4';
}

cl_i8041::cl_i8041(class cl_sim *asim,
		   unsigned int rom_siz,
		   unsigned int ram_siz):
  cl_i8048(asim, rom_siz, ram_siz)
{
  info_ch= '4';
}

int
cl_i8041::init(void)
{
  class cl_it_src *is;

  cl_i8048::init();

  it_sources->add
    (
     is= new cl_it_src
     (this, 0,
      &ints->cene, 1, // enable cell/mask
      &((class cl_i8020_cpu*)cpu)->cpins, ipm_wr, // requ cell/mask
      3, // addr
      false, //clr
      false, // indirect
      "External", // name
      1 // poll_priority
      ));
  is->init();
  is->src_value= 0; // External is low level

  it_sources->add
    (
     is= new cl_it_src
     (this, 1,
      &timer->cint_enabled, 1, // enable cell/mask
      &timer->cint_request, 1, // requ cell/mask
      7, // addr
      true, //clr
      false, // indirect
      "Timer", // name
      2 // poll_priority
      ));
  is->init();

  return 0;
}

class cl_memory_operator *
cl_i8041::make_flagop(void)
{
  class cl_memory_operator *o;
  o= new cl_flag48_op(cpsw);
  o->init();
  o->set_name("MCS41 flag operator");
  return o;
}

void
cl_i8041::decode_regs(void)
{
  int i;
  cl_banker *b= new cl_banker(aspsw, 0, flagBS, //0,
			      regs, 0, 7);
  b->init();
  b->set_name("def_regs_banker");
  regs->decoders->add(b);
  b->add_bank(0, memory("iram_chip"), 0);
  b->add_bank(1, memory("iram_chip"), 24);
  cpsw->write(0);
  for (i= 0; i < 8; i++)
    R[i]= (cl_cell8*)regs->get_cell(i);
}


/* End of i8048.src/i8041.cc */
