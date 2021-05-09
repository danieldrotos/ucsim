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

#include "m6800cl.h"


int
cl_m6800::INX(t_mem code)
{
  if (++rIX)
    rF&= ~mZ;
  else
    rF|= mZ;
  tick(3);
  return resGO;
}

int
cl_m6800::DEX(t_mem code)
{
  if (--rIX)
    rF&= ~mZ;
  else
    rF|= mZ;
  tick(3);
  return resGO;
}

int
cl_m6800::CLV(t_mem code)
{
  rF&= ~mV;
  tick(1);
  return resGO;
}

int
cl_m6800::SEV(t_mem code)
{
  rF|= mV;
  tick(1);
  return resGO;
}

int
cl_m6800::CLC(t_mem code)
{
  rF&= ~mC;
  tick(1);
  return resGO;
}

int
cl_m6800::SEC(t_mem code)
{
  rF|= mC;
  tick(1);
  return resGO;
}

int
cl_m6800::CLI(t_mem code)
{
  rF&= ~mI;
  tick(1);
  return resGO;
}

int
cl_m6800::SEI(t_mem code)
{
  rF|= mI;
  tick(1);
  return resGO;
}

int
cl_m6800::sub(class cl_cell8 &dest, u8_t op, bool c)
{
  u8_t f= CC & ~(flagN|flagZ|flagV|flagC);
  u8_t a= dest.read(), b= op, r;
  u8_t a7, b7, r7, na7, nb7, nr7;
  r= a-b;
  a7= a&0x80; na7= a7^0x80;
  b7= b&0x80; nb7= b7^0x80;
  r7= r&0x80; nr7= r7^0x80;
  if (r7) f|= flagN;
  if (!r) f|= flagZ;
  if ((a7&nb7&nr7) | (na7&b7&r7)) f|= flagV;
  if ((na7&b7) | (b7&r7) | (r7&na7)) f|= flagC;
  dest.W(r);
  cCC.W(f);
  tick(1);
  return resGO;
}

int
cl_m6800::cmp(u8_t op1, u8_t op2)
{
  u8_t f= CC & ~(flagN|flagZ|flagV|flagC);
  u8_t a= op1, b= op2, r;
  u8_t a7, b7, r7, na7, nb7, nr7;
  r= a-b;
  a7= a&0x80; na7= a7^0x80;
  b7= b&0x80; nb7= b7^0x80;
  r7= r&0x80; nr7= r7^0x80;
  if (r7) f|= flagN;
  if (!r) f|= flagZ;
  if ((a7&nb7&nr7) | (na7&b7&r7)) f|= flagV;
  if ((na7&b7) | (b7&r7) | (r7&na7)) f|= flagC;
  cCC.W(f);
  tick(1);
  return resGO;
}

int
cl_m6800::DAA(t_mem code)
{
  int i;
  if ((rA & 0xf) > 9 ||
      (rF & flagH))
    {
      i= rA+6;
      if (i > 255)
	rF|= flagC;
      rA= i;
    }
  if ((rA & 0xf0) > 0x90 ||
      (rF & flagC))
    {
      i= rA + 0x90;
      if (i > 255)
	rF|= flagC;
      rA= i;
    }
  rF&= ~(flagZ|flagS);
  if (rA&0x80)
    rF|= flagS;
  if (!rA)
    rF|= flagZ;
  cF.W(rF);
  cA.W(rA);
  tick(1);
  return resGO;
}


int
cl_m6800::add(class cl_cell8 &dest, u8_t op, bool c)
{
  u8_t f= CC & ~(flagN|flagZ|flagV|flagC|flagH);
  u8_t a= dest.read(), b= op, r;
  u8_t a7, b7, r7, na7, nb7, nr7;
  r= a+b;
  a7= a&0x80; na7= a7^0x80;
  b7= b&0x80; nb7= b7^0x80;
  r7= r&0x80; nr7= r7^0x80;
  if ((a&0xf) + (b&0xf) > 0xf) f|= flagH;
  if (r7) f|= flagN;
  if (!r) f|= flagZ;
  if ((a7&b7&nr7) | (na7&nb7&r7)) f|= flagV;
  if ((a7&b7) | (b7&nr7) | (nr7&a7)) f|= flagC;
  dest.W(r);
  cCC.W(f);
  tick(1);
  return resGO;
}

int
cl_m6800::INS(t_mem code)
{
  cSP.W(rSP+1);
  tick(3);
  return resGO;
}

int
cl_m6800::DES(t_mem code)
{
  cSP.W(rSP-1);
  tick(3);
  return resGO;
}


/* End of m6800.src/ialu.cc */
