/*
 * Simulator of microcontrollers (ialu.cc)
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

#include "i8080cl.h"


int
cl_i8080::add8(u8_t op, bool add_c)
{
  u16_t res= rA+op;
  if (add_c && (rF & flagC))
    res++;
  rF&= ~fAll;
  if (res>0xff) rF|= flagC;
  if (res&0x80) rF|= flagS;
  if (!(res&=0xff)) rF|= flagZ;
  if ((rA&0xf)+(op&0xf) > 0xf) rF|= flagA;
  rF|= ptab[res];
  cA.W(res);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::sub8(u8_t op, bool sub_c)
{
  if (sub_c && (rF & flagC))
    op+= 1;
  op= ~op+1;
  u16_t res= rA+op;
  rF&= ~fAll;
  if (res<=0xff) rF|= flagC;
  if (res&0x80) rF|= flagS;
  if (!(res&=0xff)) rF|= flagZ;
  if ((rA&0xf)+(op&0xf) > 0xf) rF|= flagA;
  rF|= ptab[res];
  cA.W(res);
  cF.W(rF);
  return 0;
}

int
cl_i8080::dad(u16_t op)
{
  u32_t res= rHL + op;
  rF&= ~flagC;
  if (res > 0xffff) rF|= flagC;
  cHL.W(res);
  cF.W(rF);
  return resGO;
}


/* End of i8085.src/ialu.cc */
