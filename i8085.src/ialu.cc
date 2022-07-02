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
  u16_t res;
  if (add_c && (rF & flagC))
    op++;
  res= rA+op;
  rF&= ~fAll;
  if (res>0xff) rF|= flagC;
  if (res&0x80) rF|= flagS;
  res&= 0xff;
  if (!res) rF|= flagZ;
  if ((rA&0xf)+(op&0xf) > 0xf) rF|= flagA;
  rF|= ADDV8(rA,op,res);
  rF|= X5(res);
  rF|= ptab[res];
  cA.W(res);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::sub8(u8_t op, bool sub_c, bool cmp)
{
  if (sub_c && (rF & flagC))
    op++;
  op= ~op+1;
  u16_t res= rA+op;
  rF&= ~fAll;
  if (res<=0xff) rF|= flagC;
  if (res&0x80) rF|= flagS;
  res&= 0xff;
  if (!res) rF|= flagZ;
  if ((rA&0xf)+(op&0xf) > 0xf) rF|= flagA;
  rF|= ADDV8(rA,op,res);
  rF|= X5(res);
  rF|= ptab[res];
  if (!cmp) cA.W(res);
  cF.W(rF);
  return 0;
}

int
cl_i8080::dad(u16_t op)
{
  u32_t res= rHL + op;
  rF&= ~(flagC|flagV);
  if (res > 0xffff) rF|= flagC;
  rF|= ADDV16(rHL,op,res);
  cHL.W(res);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::inr(class cl_memory_cell &op)
{
  rF&= ~fAll_C;
  u8_t a, res;
  a= op.read();
  res= a+1;
  if (!res) rF|= flagZ;
  if (res&0x80) rF|= flagS;
  if ((a&0xf) == 0xf) rF|= flagA;
  rF|= ADDV8(a,1,res);
  rF|= X5(res);
  rF|= ptab[res];
  op.W(res);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::dcr(class cl_memory_cell &op)
{
  u8_t a= op.read(), m1= ~1 + 1;
  u8_t res= a+m1;
  rF&= ~fAll_C;
  if (!res) rF|= flagZ;
  if (res&0x80) rF|= flagS;
  if (((a&0xf)+(m1&0xf)) > 0xf) rF|= flagA;
  rF|= ADDV8(a, m1, res);
  rF|= X5(res);
  rF|= ptab[res];
  op.W(res);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::inx(class cl_memory_cell &op)
{
  u32_t r= op.get();
  r++;
  op.W(r);
  return resGO;
}

int
cl_i8080::dcx(class cl_memory_cell &op)
{
  u32_t r= op.get();
  r--;
  op.W(r);
  return resGO;
}

int
cl_i8080::ana(u8_t op)
{
  u8_t res= rA & op;
  rF&= ~fAll;
  rF|= flagA;
  if (!res) rF|= flagZ;
  if (res&0x80) rF|= flagS;
  rF|= X5(res);
  rF|= ptab[res];
  cA.W(res);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::ora(u8_t op)
{
  u8_t res= rA | op;
  rF&= ~fAll;
  if (!res) rF|= flagZ;
  if (res&0x80) rF|= flagS;
  rF|= X5(res);
  rF|= ptab[res];
  cA.W(res);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::xra(u8_t op)
{
  u8_t res= rA ^ op;
  rF&= ~fAll;
  if (!res) rF|= flagZ;
  if (res&0x80) rF|= flagS;
  rF|= X5(res);
  rF|= ptab[res];
  cA.W(res);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::RLC(t_mem code)
{
  u8_t newc= (rA&0x80)?flagC:0;
  u8_t newa= rA<<1;
  if (newc)
    newa|= 1;
  rF&= ~flagC;
  rF|= ADDV8(rA, rA, newa);
  rF|= newc;
  cA.W(newa);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::RRC(t_mem code)
{
  u8_t newc= (rA&1)?flagC:0;
  u8_t newa= rA>>1;
  if (newc)
    newa|= 0x80;
  rF&= ~flagC;
  rF|= newc;
  cA.W(newa);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::RAL(t_mem code)
{
  bool oldc= rF&flagC;
  u8_t newc= (rA&0x80)?flagC:0;
  u8_t newa= rA<<1;
  if (oldc)
    newa|= 1;
  rF&= ~flagC;
  rF|= ADDV8(rA, rA, newa);
  rF|= newc;
  cA.W(newa);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::RAR(t_mem code)
{
  bool oldc= rF&flagC;
  u8_t newc= (rA&1)?flagC:0;
  u8_t newa= rA>>1;
  if (oldc)
    newa|= 0x80;
  rF&= ~flagC;
  rF|= newc;
  cA.W(newa);
  cF.W(rF);
  return resGO;
}

int
cl_i8080::DAA(t_mem code)
{
  if (((rA & 0xf) > 0x9) || (rF & flagA))
    add8(6, false);
  if (((rA & 0xf0) > 0x90) || (rF & flagC))
    add8(0x60, false);
  return resGO;
}

int
cl_i8080::CMA(t_mem code)
{
  cA.W(~rA);
  return resGO;
}

int
cl_i8080::CMC(t_mem code)
{
  cF.W(rF ^ flagC);
  return resGO;
}

int
cl_i8080::STC(t_mem code)
{
  cF.W(rF | flagC);
  return resGO;
}


/* End of i8085.src/ialu.cc */
