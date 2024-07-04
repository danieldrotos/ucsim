/*
 * Simulator of microcontrollers (s51.src/uc517.cc)
 *
 * Copyright (C) 2017,17 Drotos Daniel
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

#include "mducl.h"

#include "uc517cl.h"


cl_uc517::cl_uc517(struct cpu_entry *Itype, class cl_sim *asim):
  cl_uc52(Itype, asim)
{
}

int
cl_uc517::init(void)
{
  int ret;
  ret= cl_uc52::init();

  cpu->cfg_set(uc51cpu_aof_mdpc, 0x92);
  cpu->cfg_set(uc51cpu_mask_mdpc, 7);
  class cl_memory_chip *dptr_chip=
    new cl_chip8("dptr_chip", 3*8, 8);
  dptr_chip->init();
  memchips->add(dptr_chip);
  decode_dptr();

  return ret;
}

void
cl_uc517::mk_hw_elements(void)
{
  cl_uc52::mk_hw_elements();

  class cl_mdu517 *mdu= new cl_mdu517(this, 0);
  add_hw(mdu);
  mdu->init();
}

/* End of s51.src/uc517.cc */
