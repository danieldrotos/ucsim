/*
 * Simulator of microcontrollers (ibranch.cc)
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

#include "f8cl.h"


int
cl_f8::JP_I(t_mem code)
{
  u16_t a= fetch();
  a+= fetch()*256;
  PC= a;
  return resGO;
}

int
cl_f8::JP_A(t_mem code)
{
  PC= acc16->get();
  return resGO;
}

int
cl_f8::CALL_I(t_mem code)
{
  u16_t a= fetch();
  a+= fetch()*256;
  push2(PC);
  PC= a;
  return resGO;
}

int
cl_f8::CALL_A(t_mem code)
{
  push2(PC);
  PC= acc16->get();
  return resGO;
}

int
cl_f8::RET(t_mem code)
{
  set_PC(pop2());
  return resGO;
}

int
cl_f8::RETI(t_mem code)
{
  // TODO
  set_PC(pop2());
  return resGO;
}


/* End of f8.src/ibranch.cc */
