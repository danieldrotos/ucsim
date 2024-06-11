/*
 * Simulator of microcontrollers (misc16.cc)
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

#include "misc16cl.h"


cl_misc16::cl_misc16(class cl_sim *asim):
  cl_oisc(asim)
{
}
  
void
cl_misc16::init_alu(void)
{
  id_str= "MISC16";
  reg_cell_var(&cC, &rC, "C", "Carry flag");
  cC.append_operator(new cl_cy_op(&cC));
}

u16_t
cl_misc16::read(u16_t addr)
{
  return rom->get(addr);
}

u16_t
cl_misc16::write(u16_t addr, u16_t val)
{
  return val;
}


/* End of oisc.src/misc16.cc */
