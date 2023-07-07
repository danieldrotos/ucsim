/*
 * Simulator of microcontrollers (arith.cc)
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

#include "i8020cl.h"


int
cl_i8020::add(u8_t op2, bool addc)
{
  u16_t r;
  rF&= ~flagCA;
  r= cA.R()+op2;
  if (r > 0xff) rF|= flagC;
  if (((rA&0xf) + (op2&0xf)) > 0xf) rF|= flagA;
  cF.W(rF);
  cA.W(r);
  return resGO;
}


/* End of i8085.src/arith.cc */
