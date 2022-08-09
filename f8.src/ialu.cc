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

int
cl_f8::sub16(u16_t opaddr, bool usec)
{
  u16_t op2= read_addr(rom, opaddr);
  vc.rd+= 2;
  int c= 1;
  if (usec && !(rF&flagC)) c= 0;
  u16_t r= add16(acc16->get(), op2, c, true);
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
cl_f8::sub16(/*op2=x*/bool usec)
{
  class cl_cell16 *op1= acc16, *op2= &cX;
  IFSWAP
    {
      op1= &cX;
      op2= acc16;
    }
  int c= 1;
  if (usec && !(rF&flagC)) c= 0;
  op1->W(add16(op1->get(), op2->get(), c, true));
  return resGO;
}

u16_t
cl_f8::or16(u16_t a, u16_t b)
{
  u16_t r= a|b;
  rF&= flagOZN;
  if (!r) rF|= flagZ;
  if (r&0x8000) rF|= flagN;
  // TODO flagO ?
  cF.W(rF);
  return r;
}

int
cl_f8::or16(u16_t opaddr)
{
  u16_t op2= read_addr(rom, opaddr);
  vc.rd+= 2;
  u16_t r= or16(acc16->get(), op2);
  IFSWAP
    {
      // Mem= Mem | acc;
      rom->write(opaddr, r);
      rom->write(opaddr+1, r>>8);
      vc.wr+= 2;
    }
  else
    {
      // Acc= Mem | acc
      acc16->W(r);
    }
  return resGO;
}

int
cl_f8::or16(void)
{
  // op2=x
  class cl_cell16 *op1= acc16, *op2= &cX;
  IFSWAP
    {
      op1= &cX;
      op2= acc16;
    }
  op1->W(or16(op1->get(), op2->get()));
  return resGO;
}


/* 0->XXXXXXXX->C */

int
cl_f8::SRL_M(t_mem code)
{
  class cl_cell8 &c= m_mm();
  u8_t v= c.read();
  vc.rd++;
  rF&= ~flagCZ;
  if (v&1) rF|= flagC;
  v>>= 1;
  if (!v) rF|= flagZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::SRL_NSP(t_mem code)
{
  class cl_cell8 &c= m_n_sp();
  u8_t v= c.read();
  vc.rd++;
  rF&= ~flagCZ;
  if (v&1) rF|= flagC;
  v>>= 1;
  if (!v) rF|= flagZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::SRL_A(t_mem code)
{
  u8_t v= acc8->read();
  rF&= ~flagCZ;
  if (v&1) rF|= flagC;
  v>>= 1;
  if (!v) rF|= flagZ;
  acc8->W(v);
  cF.W(rF);
  return resGO;
}

int
cl_f8::SRL_ZH(t_mem code)
{
  u8_t v= rZH;
  rF&= ~flagCZ;
  if (v&1) rF|= flagC;
  v>>= 1;
  if (!v) rF|= flagZ;
  cZH.W(v);
  cF.W(rF);
  return resGO;
}

/* C<-XXXXXXXX<-0 */

int
cl_f8::SLL_M(t_mem code)
{
  class cl_cell8 &c= m_mm();
  u8_t v= c.read();
  vc.rd++;
  rF&= ~flagCZ;
  if (v&0x80) rF|= flagC;
  v<<= 1;
  if (!v) rF|= flagZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::SLL_NSP(t_mem code)
{
  class cl_cell8 &c= m_n_sp();
  u8_t v= c.read();
  vc.rd++;
  rF&= ~flagCZ;
  if (v&0x80) rF|= flagC;
  v<<= 1;
  if (!v) rF|= flagZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::SLL_A(t_mem code)
{
  u8_t v= acc8->read();
  rF&= ~flagCZ;
  if (v&0x80) rF|= flagC;
  v<<= 1;
  if (!v) rF|= flagZ;
  acc8->W(v);
  cF.W(rF);
  return resGO;
}

int
cl_f8::SLL_ZH(t_mem code)
{
  u8_t v= rZH;
  rF&= ~flagCZ;
  if (v&0x80) rF|= flagC;
  v<<= 1;
  if (!v) rF|= flagZ;
  cZH.W(v);
  cF.W(rF);
  return resGO;
}

/* +->XXXXXXXX->C
   |____________|
*/

int
cl_f8::RRC_M(t_mem code)
{
  class cl_cell8 &c= m_mm();
  u8_t v= c.read();
  vc.rd++;
  u8_t oldc= (rF&flagC)?0x80:0;
  rF&= ~flagCZ;
  if (v&1) rF|= flagC;
  v>>= 1;
  v|= oldc;
  if (!v) rF|= flagZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::RRC_NSP(t_mem code)
{
  class cl_cell8 &c= m_n_sp();
  u8_t v= c.read();
  vc.rd++;
  u8_t oldc= (rF&flagC)?0x80:0;
  rF&= ~flagCZ;
  if (v&1) rF|= flagC;
  v>>= 1;
  v|= oldc;
  if (!v) rF|= flagZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::RRC_A(t_mem code)
{
  u8_t v= acc8->read();
  u8_t oldc= (rF&flagC)?0x80:0;
  rF&= ~flagCZ;
  if (v&1) rF|= flagC;
  v>>= 1;
  v|= oldc;
  if (!v) rF|= flagZ;
  acc8->W(v);
  cF.W(rF);
  return resGO;
}

int
cl_f8::RRC_ZH(t_mem code)
{
  u8_t v= rZH;
  u8_t oldc= (rF&flagC)?0x80:0;
  rF&= ~flagCZ;
  if (v&1) rF|= flagC;
  v>>= 1;
  v|= oldc;
  if (!v) rF|= flagZ;
  cZH.W(v);
  cF.W(rF);
  return resGO;
}

/* C<-XXXXXXXX<-+
   |____________|
*/

int
cl_f8::RLC_M(t_mem code)
{
  class cl_cell8 &c= m_mm();
  u8_t v= c.read();
  vc.rd++;
  u8_t oldc= (rF&flagC)?1:0;
  rF&= ~flagCZ;
  if (v&0x80) rF|= flagC;
  v<<= 1;
  v|= oldc;
  if (!v) rF|= flagZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::RLC_NSP(t_mem code)
{
  class cl_cell8 &c= m_n_sp();
  u8_t v= c.read();
  vc.rd++;
  u8_t oldc= (rF&flagC)?1:0;
  rF&= ~flagCZ;
  if (v&0x80) rF|= flagC;
  v<<= 1;
  v|= oldc;
  if (!v) rF|= flagZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::RLC_A(t_mem code)
{
  u8_t v= acc8->read();
  u8_t oldc= (rF&flagC)?1:0;
  rF&= ~flagCZ;
  if (v&0x80) rF|= flagC;
  v<<= 1;
  v|= oldc;
  if (!v) rF|= flagZ;
  acc8->W(v);
  cF.W(rF);
  return resGO;
}

int
cl_f8::RLC_ZH(t_mem code)
{
  u8_t v= rZH;
  u8_t oldc= (rF&flagC)?1:0;
  rF&= ~flagCZ;
  if (v&0x80) rF|= flagC;
  v<<= 1;
  v|= oldc;
  if (!v) rF|= flagZ;
  cZH.W(v);
  cF.W(rF);
  return resGO;
}

int
cl_f8::INC_M(t_mem code)
{
  class cl_cell8 &c= m_mm();
  u8_t v= c.read()+1;
  vc.rd++;
  rF&= ~flagCZ;
  if (!v) rF|= flagCZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::INC_NSP(t_mem code)
{
  class cl_cell8 &c= m_n_sp();
  u8_t v= c.read()+1;
  vc.rd++;
  rF&= ~flagCZ;
  if (!v) rF|= flagCZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::INC_A(t_mem code)
{
  u8_t v= acc8->read()+1;
  rF&= ~flagCZ;
  if (!v) rF|= flagCZ;
  acc8->W(v);
  cF.W(rF);
  return resGO;
}

int
cl_f8::INC_ZH(t_mem code)
{
  u8_t v= rZH+1;
  rF&= ~flagCZ;
  if (!v) rF|= flagCZ;
  cZH.W(v);
  cF.W(rF);
  return resGO;
}

int
cl_f8::DEC_M(t_mem code)
{
  class cl_cell8 &c= m_mm();
  u8_t v= c.read()-1;
  vc.rd++;
  rF&= ~flagCZ;
  if (v==0xff) rF|= flagC;
  if (!v) rF|= flagZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::DEC_NSP(t_mem code)
{
  class cl_cell8 &c= m_n_sp();
  u8_t v= c.read()-1;
  vc.rd++;
  rF&= ~flagCZ;
  if (v==0xff) rF|= flagC;
  if (!v) rF|= flagZ;
  c.W(v);
  vc.wr++;
  cF.W(rF);
  return resGO;
}

int
cl_f8::DEC_A(t_mem code)
{
  u8_t v= acc8->read()-1;
  rF&= ~flagCZ;
  if (v==0xff) rF|= flagC;
  if (!v) rF|= flagZ;
  acc8->W(v);
  cF.W(rF);
  return resGO;
}

int
cl_f8::DEC_ZH(t_mem code)
{
  u8_t v= rZH-1;
  rF&= ~flagCZ;
  if (v==0xff) rF|= flagC;
  if (!v) rF|= flagZ;
  cZH.W(v);
  cF.W(rF);
  return resGO;
}

int
cl_f8::TST_M(t_mem code)
{
  class cl_cell8 &c= m_mm();
  u8_t v= c.read();
  vc.rd++;
  rF&= ~fAll_H;
  if (v&0x80) rF|= flagN;
  if (!v) rF|= flagZ;
  rF|= ptab[v];
  cF.W(rF);
  return resGO;
}

int
cl_f8::TST_NSP(t_mem code)
{
  class cl_cell8 &c= m_n_sp();
  u8_t v= c.read();
  vc.rd++;
  rF&= ~fAll_H;
  if (v&0x80) rF|= flagN;
  if (!v) rF|= flagZ;
  rF|= ptab[v];
  cF.W(rF);
  return resGO;
}

int
cl_f8::TST_A(t_mem code)
{
  u8_t v= acc8->read();
  rF&= ~fAll_H;
  if (v&0x80) rF|= flagN;
  if (!v) rF|= flagZ;
  rF|= ptab[v];
  cF.W(rF);
  return resGO;
}

int
cl_f8::TST_ZH(t_mem code)
{
  u8_t v= rZH;
  rF&= ~fAll_H;
  if (v&0x80) rF|= flagN;
  if (!v) rF|= flagZ;
  rF|= ptab[v];
  cF.W(rF);
  return resGO;
}


int
cl_f8::INCW_M(t_mem code)
{
  u16_t a= a_mm();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  add16(v, 1, 0, false);
  rom->write(a  , v);
  rom->write(a+1, v>>8);
  vc.wr+= 2;
  return resGO;
}

int
cl_f8::INCW_NSP(t_mem code)
{
  u16_t a= a_n_sp();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  add16(v, 1, 0, false);
  rom->write(a  , v);
  rom->write(a+1, v>>8);
  vc.wr+= 2;
  return resGO;
}

int
cl_f8::INCW_NNZ(t_mem code)
{
  u16_t a= a_nn_z();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  add16(v, 1, 0, false);
  rom->write(a  , v);
  rom->write(a+1, v>>8);
  vc.wr+= 2;
  return resGO;
}

int
cl_f8::INCW_A(t_mem code)
{
  u16_t v= acc16->get();
  add16(v, 1, 0, false);
  acc16->write(v);
  return resGO;
}

int
cl_f8::ADCW1_M(t_mem code)
{
  u16_t a= a_mm();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  add16(v, 0, (rF&flagC)?1:0, false);
  rom->write(a  , v);
  rom->write(a+1, v>>8);
  vc.wr+= 2;
  return resGO;
}

int
cl_f8::ADCW1_NSP(t_mem code)
{
  u16_t a= a_n_sp();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  add16(v, 0, (rF&flagC)?1:0, false);
  rom->write(a  , v);
  rom->write(a+1, v>>8);
  vc.wr+= 2;
  return resGO;
}

int
cl_f8::ADCW1_NNZ(t_mem code)
{
  u16_t a= a_nn_z();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  add16(v, 0, (rF&flagC)?1:0, false);
  rom->write(a  , v);
  rom->write(a+1, v>>8);
  vc.wr+= 2;
  return resGO;
}

int
cl_f8::ADCW1_A(t_mem code)
{
  u16_t v= acc16->get();
  add16(v, 0, (rF&flagC)?1:0, false);
  acc16->write(v);
  return resGO;
}

int
cl_f8::SBCW1_M(t_mem code)
{
  u16_t a= a_mm();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  add16(v, 0xffff, (rF&flagC)?1:0, false);
  rom->write(a  , v);
  rom->write(a+1, v>>8);
  vc.wr+= 2;
  return resGO;
}

int
cl_f8::SBCW1_NSP(t_mem code)
{
  u16_t a= a_n_sp();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  add16(v, 0xffff, (rF&flagC)?1:0, false);
  rom->write(a  , v);
  rom->write(a+1, v>>8);
  vc.wr+= 2;
  return resGO;
}

int
cl_f8::SBCW1_NNZ(t_mem code)
{
  u16_t a= a_nn_z();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  add16(v, 0xffff, (rF&flagC)?1:0, false);
  rom->write(a  , v);
  rom->write(a+1, v>>8);
  vc.wr+= 2;
  return resGO;
}

int
cl_f8::SBCW1_A(t_mem code)
{
  u16_t v= acc16->get();
  add16(v, 0xffff, (rF&flagC)?1:0, false);
  acc16->write(v);
  return resGO;
}

int
cl_f8::TSTW1_M(t_mem code)
{
  u16_t a= a_mm();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  rF&= ~flagOZN;
  rF|= flagC;
  if (!v) rF|= flagZ;
  if (v&0x8000) rF|= flagN;
  rF|= ((ptab[v&0xff])^(ptab[v>>8])); // TODO: need to negate?
  cF.W(rF);
  return resGO;
}

int
cl_f8::TSTW1_NSP(t_mem code)
{
  u16_t a= a_n_sp();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  rF&= ~flagOZN;
  rF|= flagC;
  if (!v) rF|= flagZ;
  if (v&0x8000) rF|= flagN;
  rF|= ((ptab[v&0xff])^(ptab[v>>8])); // TODO: need to negate?
  cF.W(rF);
  return resGO;
}

int
cl_f8::TSTW1_NNZ(t_mem code)
{
  u16_t a= a_nn_z();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  rF&= ~flagOZN;
  rF|= flagC;
  if (!v) rF|= flagZ;
  if (v&0x8000) rF|= flagN;
  rF|= ((ptab[v&0xff])^(ptab[v>>8])); // TODO: need to negate?
  cF.W(rF);
  return resGO;
}

int
cl_f8::TSTW1_A(t_mem code)
{
  u16_t v= acc16->get();
  rF&= ~flagOZN;
  rF|= flagC;
  if (!v) rF|= flagZ;
  if (v&0x8000) rF|= flagN;
  rF|= ((ptab[v&0xff])^(ptab[v>>8])); // TODO: need to negate?
  cF.W(rF);
  return resGO;
}


int
cl_f8::ROT(t_mem code)
{
  u8_t i= fetch(), v= acc8->get();
  while (i--)
    {
      u8_t u= v&0x80;
      v<<= 1;
      if (u)
	v|= 1;
    }
  acc8->W(v);
  return resGO;
}

int
cl_f8::SRA(t_mem code)
{
  i8_t v= acc8->get();
  rF&= ~flagC;
  if (v&1) rF|= flagC;
  v>>= 1;
  cF.W(rF);
  acc8->W(v);
  return resGO;
}

// TODO: ?
int
cl_f8::DAA(t_mem code)
{
  // Method of 8080...
  u8_t rA= acc8->get();
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
      rA+= corr;
      acc8->W(rA);
    }
  return resGO;
}

int
cl_f8::BOOL_A(t_mem code)
{
  u8_t v= acc8->get();
  if (v==0) // TODO: what is TRUE?
    rF|= flagZ; // TODO: need negate?
  else
    rF&= ~flagZ;
  cF.W(rF);
  v= v?1:0;
  acc8->W(v); // TODO: needed?
  return resGO;
}

int
cl_f8::MSK(t_mem code)
{
  // yl = (yl & i) | (yh & ~i) - really a 16-bit inst
  REGPAIR(a,A,h,l);
  a.A= acc16->get();
  u8_t i= fetch();
  u8_t r= (a.r.l & i) | (a.r.h & ~i);
  a.r.l= r;
  acc16->W(a.A);
  return resGO;
}

int
cl_f8::mad(class cl_cell8 &op)
{
  // x <- m * yl + xh + c
  u32_t r= op.read();
  r*= rYL;
  r+= rXH;
  if (rF&flagC) r++;
  rF&= ~flagC;
  if (r>0xffff) rF|= flagC;
  cF.W(rF);
  cX.W(r);
  return resGO;
}


int
cl_f8::MUL(t_mem code)
{
  REGPAIR(a,A,h,l);
  a.A= acc16->get();
  u16_t r= a.r.l * a.r.h;
  rF&= ~flagCZN;
  if (!r) rF|= flagZ;
  if (r&0x8000) rF|= flagN;
  cF.W(rF);
  acc16->W(r);
  return resGO;
}

int
cl_f8::NEGW(t_mem code)
{
  u16_t a= acc16->get();
  u16_t r= add16(~a, 1, 0, 0);
  acc16->W(r);
  return resGO;
}


/* End of f8.src/ialu.cc */
