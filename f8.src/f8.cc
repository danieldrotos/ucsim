/*
 * Simulator of microcontrollers (i8080.cc)
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

#include "f8cl.h"


/* 
 * CPU
 */

cl_f8::cl_f8(class cl_sim *asim):
  cl_uc(asim)
{
}

int
cl_f8::init(void)
{
  cl_uc::init();
  fill_def_wrappers(itab);
  set_xtal(25000000);

#define RCV(R) reg_cell_var(&c ## R , &r ## R , "" #R "" , "CPU register " #R "")
  RCV(X); RCV(XH); RCV(XL);
  RCV(Y); RCV(YH); RCV(YL);
  RCV(Z); RCV(ZH); RCV(ZL);
  RCV(SP);
  RCV(F);
#undef RCV
  sp_limit= 0;

  reset();
  return 0;
}

const char *
cl_f8::id_string(void)
{
  return "F8";
}

void
cl_f8::reset(void)
{
  cl_uc::reset();
  PC= 0;
}

void
cl_f8::set_PC(t_addr addr)
{
  PC= addr&0xffff;
}


void
cl_f8::mk_hw_elements(void)
{
  class cl_hw *h;
  cl_uc::mk_hw_elements();

  add_hw(h= new cl_dreg(this, 0, "dreg"));
  h->init();
}

void
cl_f8::make_cpu_hw(void)
{
  /*
  cpu= new cl_f8_cpu(this);
  add_hw(cpu);
  cpu->init();
  */
}

void
cl_f8::make_memories(void)
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


/* End of f8.src/i8080.cc */
