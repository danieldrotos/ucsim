/*
 * Simulator of microcontrollers (ialu.cc)
 *
 * Copyright (C) 2022 Drotos Daniel
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

#include "i8080cl.h"

int
cl_i8080::add8(u8_t op, bool add_c, bool is_daa)
{
  u16_t res;
  /* Take the incoming carry as a separate term; do NOT fold it into op with
     op++, which overflows the u8_t to 0x00 when op==0xff and then loses both
     the carry-out and the half-carry (e.g. 0xff + 0xff + 1). */
  u8_t carry_in = (add_c && (rF & flagC)) ? 1 : 0;
  res= rA+op+carry_in;
  rF&= ~fAll_A;
  if (!is_daa) rF&= ~flagA;
  if (res>0xff) rF|= flagC;
  if (res&0x80) rF|= flagS;
  res&= 0xff;
  if (!res) rF|= flagZ;
  if (!is_daa)
    if ((rA&0xf)+(op&0xf)+carry_in > 0xf)
      rF|= flagA;
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
  u16_t orga= rA, orgb= op;
  u8_t borrow_in= (sub_c && (rF & flagC)) ? 1 : 0;
  if (borrow_in)
    op++;
  op= ~op+1;
  u16_t res= rA+op;
  rF&= ~fAll;
  /* A borrow (carry) occurs when A < operand + incoming-borrow.  orgb is a
     u16_t so orgb+borrow_in does not overflow when the operand byte is 0xff. */
  if (orga < orgb + borrow_in) rF|= flagC;
  if (res&0x80) rF|= flagS;
  res&= 0xff;
  if (!res) rF|= flagZ;
  if ((rA&0xf)+(op&0xf) > 0xf) rF|= flagA;
  /* V (overflow) is carry-in XOR carry-out of bit 7 of the real ALU operation
     A + ~b + carry. Applying the sign-based overflow formula to the two's-
     complement operand (op) folds the +1 into the operand and loses the carry
     propagation, giving the wrong V when ~b+1 itself overflows (b == 0x80). Use
     the one's-complement of the original operand instead; res already carries
     the +1, so ADDV8(A, ~orgb, res) matches the silicon (see Shirriff's 8085
     flag analysis) and makes the K/X5 flag a correct signed comparison. */
  rF|= ADDV8(rA,(u8_t)~orgb,res);
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
  u8_t newc= (rA&0x80)?flagC:flagNON;
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
  u8_t newc= (rA&1)?flagC:flagNON;
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
  u8_t newc= (rA&0x80)?flagC:flagNON;
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
  u8_t newc= (rA&1)?flagC:flagNON;
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
  u8_t corr= 0;
  if (((rA & 0xf) > 9) || (rF & flagA))
    corr= 6;
  u8_t v= rA>>4, c= 10;
  if (corr==6)
    c= 9;
  if ((v >= c) || (rF & flagC))
    corr|= 0x60;
  if (corr)
    {
      /*u8_t org= rA;
      rF&= ~(flagS|flagZ|flagV|flagP|flagK);
      rA+= corr;
      if (rA&0x80) rF|= flagS;
      if (!rA) rF|= flagZ;
      rF|= ADDV8(org, corr, rA);
      rF|= X5(rA);
      rF|= ptab[rA];
      cF.W(rF);
      cA.W(rA);*/
      add8(corr, false, true);
    }
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
