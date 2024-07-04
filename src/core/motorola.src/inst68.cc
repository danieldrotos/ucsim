/*
 * Simulator of microcontrollers (inst68.cc)
 *
 * Copyright (C) 2020 Drotos Daniel
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

#include "m6800cl.h"

int
cl_m6800::NOP(t_mem code)
{
  return resGO;
}

int
cl_m6800::RTI(t_mem code)
{
  pull_regs(true);
  return resGO;
}

int
cl_m6800::WAI(t_mem code)
{
  push_regs(true);
  wai= true;
  state= stIDLE;
  return resGO;
}

int
cl_m6800::SWI(t_mem code)
{
  src_swi->request();
  return resGO;
}


/* End of motorola.src/inst68.cc */
