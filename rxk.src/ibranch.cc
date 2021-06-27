/*
 * Simulator of microcontrollers (ibranch.cc)
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

#include "rxkcl.h"


int
cl_rxk::DJNZ(t_mem code)
{
  u8_t v= rB - 1;
  i8_t r= fetch();
  destB().W(v);
  if (v)
    PC+= r;
  tick5p1(4);
  return resGO;
}

int
cl_rxk::JR(t_mem code)
{
  i8_t r= fetch();
  PC+= r;
  tick5p1(4);
  return resGO;
}

int
cl_rxk::LJP(t_mem code)
{
  u8_t x, h, l;
  l= fetch();
  h= fetch();
  x= fetch();
  cpu->cfg_write(rxk_cpu_xpc, x);
  PC= h*256+l;
  tick(9);
  return resGO;
}

int
cl_rxk::jr_cc(bool cond)
{
  i8_t r= fetch();
  if (cond)
    PC+= r;
  tick5p1(4);
  return resGO;
}

int
cl_rxk::ret_f(bool f)
{
  if (f)
    {
      u8_t l, h;
      l= mem->read(rSP);
      rSP++;
      h= mem->read(rSP);
      cSP.W(++rSP);
      vc.rd+= 2;
      PC= h*256 + l;
    }
  tick(7);
  return resGO;
}

int
cl_rxk::jp_f_mn(bool f)
{
  u8_t l, h;
  l= fetch();
  h= fetch();
  if (f)
    {
      PC= h*256+l;
    }
  tick(6);
  return resGO;
}


/* End of rxk.src/ibranch.cc */
