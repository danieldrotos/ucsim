/*
 * Simulator of microcontrollers (imove.cc)
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
cl_rxk::ld_dd_mn(class cl_cell16 &dd)
{
  u8_t l, h;
  l= fetch();
  h= fetch();
  dd.W(h*256+l);
  tick(5);
  return resGO;
}

int
cl_rxk::ld_r_n(class cl_cell8 &r)
{
  r.W(fetch());
  tick(3);
  return resGO;
}

int
cl_rxk::ld_ihl_r(u8_t op)
{
  class cl_cell8 &c= dest8iHL();
  c.W(op);
  vc.wr++;
  tick(5);
  return resGO;
}

int
cl_rxk::ld_r_ihl(class cl_cell8 &destr)
{
  u8_t v= read8(rHL);
  destr.W(v);
  tick(4);
  return resGO;
}

int
cl_rxk::ld_r_g(class cl_cell8 &destr, u8_t op)
{
  destr.W(op);
  tick(1);
  return resGO;
}

int
cl_rxk::pop_zz(class cl_cell16 &dest)
{
  u8_t l, h;
  l= rom->read(rSP++);
  h= rom->read(rSP++);
  cSP.W(rSP);
  dest.W(h*256+l);
  vc.rd+= 2;
  tick(6);
  return resGO;
}

int
cl_rxk::push_zz(u16_t op)
{
  u8_t h, l;
  h= op>>8;
  l= op&0xff;
  rom->write(rSP-1, h);
  rom->write(rSP-2, l);
  cSP.W(rSP-2);
  vc.wr+= 2;
  tick5p1(9);
  return resGO;
}

int
cl_rxk::LD_iBC_A(t_mem code)
{
  class cl_cell8 &c= dest8iBC();
  c.W(rA);
  vc.wr++;
  tick(6);
  return resGO;
}

int
cl_rxk::LD_iDE_A(t_mem code)
{
  class cl_cell8 &c= dest8iDE();
  c.W(rA);
  vc.wr++;
  tick(6);
  return resGO;
}

int
cl_rxk::LD_iMN_A(t_mem code)
{
  class cl_cell8 &c= dest8imn();
  c.W(rA);
  vc.wr++;
  tick(9);
  return resGO;
}

int
cl_rxk::LD_A_iBC(t_mem code)
{
  destA().W(read8(rBC));
  tick(5);
  return resGO;
}

int
cl_rxk::LD_A_iDE(t_mem code)
{
  destA().W(read8(rDE));
  tick(5);
  return resGO;
}

int
cl_rxk::LD_A_iMN(t_mem code)
{
  destA().W(read8(fetch16()));
  tick(8);
  return resGO;
}

int
cl_rxk::EX_AF_aAF(t_mem code)
{
  u16_t temp= rAF;
  cAF.W(raAF);
  caAF.W(temp);
  tick(1);
  return resGO;
}

int
cl_rxk::EX_aDE_HL(t_mem code)
{
  class cl_cell16 &dhl= destHL();
  u16_t t= raDE;
  caDE.W(dhl.get());
  dhl.W(t);
  tick(1);
  return resGO;
}

int
cl_rxk::LD_HL_iSPn(t_mem code)
{
  class cl_cell16 &dest= destHL();
  u8_t n= fetch(), l, h;
  l= rom->read(rSP+n);
  h= rom->read(rSP+n+1);
  dest.W(h*256+l);
  vc.rd+= 2;
  tick5p1(8);
  return resGO;
}

int
cl_rxk::LD_HL_iIXd(t_mem code)
{
  i8_t d= fetch();
  class cl_cell16 &dhl= destHL();
  t_addr a= (rIX+d)&0xffff;
  u8_t h, l;
  l= rwas->read(a);
  h= rwas->read(a+1);
  dhl.W(h*256+l);
  tick5p1(8);
  return resGO;
}

int
cl_rxk::LD_iSPn_HL(t_mem code)
{
  u8_t n= fetch();
  rom->write(rSP+n, rL);
  rom->write(rSP+n+1, rH);
  tick5p1(10);
  return resGO;
}


/* End of rxk.src/imove.cc */
