/*
 * Simulator of microcontrollers (ialu.cc)
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
cl_f8::add8(class cl_cell8 *op1, class cl_cell8 *op2, bool usec, bool memop)
{
  u8_t c= 0;
  if (usec)
    c= (rF&flagC)?1:0;
  IFSWAP
    {
      class cl_cell8 *t= op1;
      op1= op2;
      op2= t;
      if (memop)
	vc.wr++, vc.rd++;
    }
  else
    {
      if (memop)
	vc.rd++;	
    }
  u8_t a= op1->read(), b= op2->read();
  u16_t r= a+b+c;
  u8_t r8= r;
  rF&= ~fAll;
  if (r8==0) rF|= flagZ;
  if (r8&0x80) rF|= flagN;
  if (r>0xff) rF|= flagC;
  if (((a&b&~r8)|(~a&~b&r8))&0x80) rF|= flagO;
  if (((a&0xf)+(b&0xf)+c)>0xf) rF|= flagH;
  cF.W(rF);
  op1->write(r8);
  return resGO;
}

int
cl_f8::sub8(class cl_cell8 *op1, class cl_cell8 *op2, bool usec, bool memop, bool cmp)
{
  u8_t c= 1;
  if (usec)
    c= (rF&flagC)?1:0;
  IFSWAP
    {
      class cl_cell8 *t= op1;
      op1= op2;
      op2= t;
      if (memop)
	vc.wr++, vc.rd++;
    }
  else
    {
      if (memop)
	vc.rd++;	
    }
  u8_t a= op1->read(), b= op2->read();
  u16_t r= a+~b+c;
  u8_t r8= r;
  rF&= ~fAll;
  if (r8==0) rF|= flagZ;
  if (r8&0x80) rF|= flagN;
  if (r>0xff) rF|= flagC;
  if (((a&~b&~r8)|(~a&b&r8))&0x80) rF|= flagO;
  if (((a&0xf)+(~b&0xf)+c)>0xf) rF|= flagH;
  cF.W(rF);
  if (!cmp)
    op1->write(r8);
  return resGO;
}

int
cl_f8::Or8(class cl_cell8 *op1, class cl_cell8 *op2, bool memop)
{
  IFSWAP
    {
      class cl_cell8 *t= op1;
      op1= op2;
      op2= t;
      if (memop)
	vc.wr++, vc.rd++;
    }
  else
    {
      if (memop)
	vc.rd++;	
    }
  u8_t a= op1->read(), b= op2->read();
  u8_t r= a|b;
  rF&= ~flagZN;
  if (r==0) rF|= flagZ;
  if (r&0x80) rF|= flagN;
  cF.W(rF);
  op1->write(r);
  return resGO;
}

int
cl_f8::Xor8(class cl_cell8 *op1, class cl_cell8 *op2, bool memop)
{
  IFSWAP
    {
      class cl_cell8 *t= op1;
      op1= op2;
      op2= t;
      if (memop)
	vc.wr++, vc.rd++;
    }
  else
    {
      if (memop)
	vc.rd++;	
    }
  u8_t a= op1->read(), b= op2->read();
  u8_t r= a^b;
  rF&= ~flagZN;
  if (r==0) rF|= flagZ;
  if (r&0x80) rF|= flagN;
  cF.W(rF);
  op1->write(r);
  return resGO;
}

int
cl_f8::And8(class cl_cell8 *op1, class cl_cell8 *op2, bool memop)
{
  IFSWAP
    {
      class cl_cell8 *t= op1;
      op1= op2;
      op2= t;
      if (memop)
	vc.wr++, vc.rd++;
    }
  else
    {
      if (memop)
	vc.rd++;	
    }
  u8_t a= op1->read(), b= op2->read();
  u8_t r= a&b;
  rF&= ~flagZN;
  if (r==0) rF|= flagZ;
  if (r&0x80) rF|= flagN;
  cF.W(rF);
  op1->write(r);
  return resGO;
}

u16_t
cl_f8::add16(u16_t a, u16_t b, int c, bool sub)
{
  u32_t rb= a+b+c;
  u16_t r= rb;
  rF&= ~fAll_H;
  if (rb>0xffff) rF|= flagC;
  if (r&0x8000) rF|= flagC;
  if (!r) rF|= flagZ;
  if (sub)
    {
      if (((a&~b&~r)|(~a&b&r))&0x8000) rF|= flagO;
    }
  else
    {
      if (((a&b&~r)|(~a&~b&r))&0x8000) rF|= flagO;
    }
  cF.W(rF);
  return r;
}

int
cl_f8::add16(u16_t opaddr, bool usec)
{
  u16_t op2= read_addr(rom, opaddr);
  vc.rd+= 2;
  int c= 0;
  if (usec && (rF&flagC)) c= 1;
  u16_t r= add16(acc16->get(), op2, c, false);
  IFSWAP
    {
      // Mem= Mem+acc
      rom->write(opaddr, r);
      rom->write(opaddr+1, r>>8);
      vc.wr+= 2;
    }
  else
    {
      // Acc= Mem+acc
      acc16->W(r);
    }
  return resGO;
}
  
int
cl_f8::add16(/*op2=x*/bool usec)
{
  class cl_cell16 *op1= acc16, *op2= &cX;
  IFSWAP
    {
      op1= &cX;
      op2= acc16;
    }
  int c= 0;
  if (usec && (rF&flagC)) c= 1;
  op1->W(add16(op1->get(), op2->get(), c, false));
  return resGO;
}


/* End of f8.src/ialu.cc */
