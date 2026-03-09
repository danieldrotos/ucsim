/*
 * Simulator of microcontrollers (r6k.cc)
 *
 * Copyright (C) 2020 Drotos Daniel
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

#include "glob.h"
#include "49wrap.h"
#include "r6kwrap.h"

#include "r6kcl.h"


cl_r6k::cl_r6k(class cl_sim *asim):
  cl_r5k(asim)
{
}

const char *
cl_r6k::id_string(void)
{
  return "R6K";
}

int
cl_r6k::init(void)
{
  cl_r5k::init();
  fill_49_wrappers(itab_49);
  // 6k specific stuff on 7f page in 10 mode
  itab_7f10[0x43]= instruction_wrapper_6k11_43;
  itab_7f10[0x44]= instruction_wrapper_6k11_44;
  itab_7f10[0x4b]= instruction_wrapper_6k11_4b;
  itab_7f10[0x53]= instruction_wrapper_6k11_53;
  itab_7f10[0x59]= instruction_wrapper_6k11_59;
  itab_7f10[0x69]= instruction_wrapper_6k11_69;
  itab_7f10[0x80]= instruction_wrapper_6k11_80;
  itab_7f10[0x88]= instruction_wrapper_6k11_88;
  itab_7f10[0x90]= instruction_wrapper_6k11_90;

#define WRAPPER_FILLER
#include "gen6k.h"
#undef WRAPPER_FILLER
  
  return 0;
}


struct dis_entry *
cl_r6k::dis_entry(t_addr addr)
{
  u8_t code0= rom->read(addr);
  t_mem codew= code0 + 256*(rom->read(addr+1));
  struct dis_entry *de;
  int i;
  i= 0;
  while (disass_r6k[i].mnemonic)
    {
      int em, km;
      de= &disass_r6k[i];
      em= de->code >> 16;
      km= 1<<kmode;
      if (em & km)
	{
	  t_mem mc= codew & de->mask;
	  t_mem cc= de->code & 0xffff;
	  if (mc == cc)
	    return de;
	}
      i++;
    }
  return cl_r5k::dis_entry(addr);
}


int page49_wrapper(class cl_uc *uc, t_mem code)
{
  return ((class cl_r6k *)uc)->PAGE_6K49(code);
}

void
cl_r6k::mode3k(void)
{
  cl_r5k::mode3k();
}


void
cl_r6k::mode01(void)
{
  cl_r5k::mode01();
  itab[0x49]= page49_wrapper;
}


void
cl_r6k::mode10(void)
{
  cl_r5k::mode10();
  itab[0x49]= page49_wrapper;
}

void
cl_r6k::mode4k(void)
{
  cl_r5k::mode4k();
  itab[0x43]= instruction_wrapper_6k11_43;
  itab[0x44]= instruction_wrapper_6k11_44;
  itab[0x49]= page49_wrapper;
  itab[0x4b]= instruction_wrapper_6k11_4b;
  itab[0x53]= instruction_wrapper_6k11_53;
  itab[0x59]= instruction_wrapper_6k11_59;
  itab[0x69]= instruction_wrapper_6k11_69;
  itab[0x80]= instruction_wrapper_6k11_80;
  itab[0x88]= instruction_wrapper_6k11_88;
  itab[0x90]= instruction_wrapper_6k11_90;
}

int
cl_r6k::EX_JKHL_BCDE_(MP)
{
  u32_t t;
  if (altd)
    {
      t= rJKHL;
      cJKHL.W(raBCDE);
      caBCDE.W(t);
    }
  else
    {
      t= raJKHL;
      caJKHL.W(raBCDE);
      caBCDE.W(t);
    }
  return resGO;
}

int
cl_r6k::MUL_HL_DE(MP)
{
  i32_t a= (i16_t)rHL;
  i32_t b= (i16_t)rDE;
  destJKHL().W(a * b);
  tick(10);
  return resGO;
}

int
cl_r6k::MULU_HL_DE(MP)
{
  destJKHL().W((u32_t)rHL * (u32_t)rDE);
  tick(11);
  return resGO;
}

int
cl_r6k::tstnull_pp(u32_t pp)
{
  class cl_cell8 &rf= destF();
  u8_t f= rF & ~(flagZ|flagC);
  if (pp == 0xffff0000)
    f|= (flagZ|flagC);
  if (pp == 0)
    f|= flagZ;
  rf.W(f);
  tick(3);
  return resGO;
}

int
cl_r6k::swap_r(u8_t sr, C8 &dr)
{
  u8_t v2= 0;
  int i, m;
  for (i= 0, m= 0x80; i<8; i++, m>>=1)
    {
      v2>>= 1;
      v2|= ((sr&m)?0x80:0);
    }
  dr.W(v2);
  tick(3);
  return resGO;
}

int
cl_r6k::swap_rp(u16_t sr, C16 &dr)
{
  u16_t v2= (sr<<8)|(sr>>8);
  dr.W(v2);
  tick(3);
  return resGO;
}

int
cl_r6k::lljp_cc(bool cond)
{
  u16_t mn, lxpc;
  mn= fetch();
  mn+= fetch() * 256;
  lxpc= fetch();
  lxpc+= fetch() * 256;
  lxpc&= 0xfff;
  if (cond)
    {
      PC= mn;
      LXPC->W(lxpc);
    }
  tick(13);
  return resGO;
}

int
cl_r6k::swap_32(u32_t sr, C32 &dr)
{
  sr= ((sr << 8) & 0xFF00FF00) | ((sr >> 8) & 0x00FF00FF);
  sr= (sr << 16) | (sr >> 16);
  dr.W(sr);
  tick(3);
  return resGO;
}

int
cl_r6k::ADD_IR_D(MP)
{
  u8_t forg= rF & ~flagC;
  u32_t v= cIR->get();
  i8_t d= fetch();
  v+= d;
  if (v > 0xffff)
    forg|= flagC;
  else
    forg&= ~flagC;
  destF().W(forg);
  cIR->W(v);
  tick(5);
  return resGO;
}

int
cl_r6k::PAGE_6K49(MP)
{
  code= fetch();
  return itab_49[code](this, code);
}

int
cl_r6k::inc_r(class cl_cell8 &cr, u8_t op)
{
  return add8(cr, op, 1, false);
}

int
cl_r6k::inc_i8(t_addr addr)
{
  C8 *cell= (C8*)rwas->get_cell(addr);
  vc.rd++;
  vc.wr++;
  return add8(*cell, cell->R(), 1, false);
}

int
cl_r6k::dec_r(class cl_cell8 &cr, u8_t op)
{
  return sub8(cr, op, 1, false);
}

int
cl_r6k::dec_i8(t_addr addr)
{
  C8 *cell= (C8*)rwas->get_cell(addr);
  vc.rd++;
  vc.wr++;
  return sub8(*cell, cell->R(), 1, false);
}

int
cl_r6k::inc_iPSd(u32_t ps, i8_t d)
{
  class cl_cell8 &f= destF();
  t_addr a= px8se(ps, d);
  u8_t forg= f.R() & ~(flagS|flagZ|flagV|flagC);
  u8_t org= mem->pxread(a);
  u16_t res= org+1;
  if (res > 0xff) forg|= flagC;
  if (res & 0x80) forg|= flagS;
  if (!(res&0xff)) forg|= flagZ;
  if (!(org&0x80) && (res&0x80)) forg|= flagV;
  f.W(forg);
  mem->pxwrite(a, res);
  vc.rd++;
  vc.wr++;
  return resGO;
}

int
cl_r6k::dec_iPSd(u32_t ps, i8_t d)
{
  class cl_cell8 &f= destF();
  t_addr a= px8se(ps, d);
  u8_t org= mem->pxread(a);
  u8_t v1= org, op1= org;
  u8_t forg;
  u8_t res;
  u8_t a7, b7, r7, na7, nb7, nr7;
  i8_t o2= 1, op2= 1;
  i8_t r= org-o2;
  res= r;
  forg= rF & ~(flagZ|flagS|flagV);
  a7=  v1&0x80; na7= a7^0x80;
  b7= op2&0x80; nb7= b7^0x80;
  r7= res&0x80; nr7= r7^0x80;
  if ((a7&nb7&nr7) | (na7&b7&r7)) forg|= flagV;
  if (op1<op2) forg|= flagC;
  if ((op1>op2) || (op1==op2)) forg&= ~flagC;
  if (!res) forg|= flagZ;
  if (res & 0x80) forg|= flagS;
  mem->pxwrite(a, res);
  f.W(forg);
  vc.rd++;
  vc.wr++;
  return resGO;
}

/* shift/rotate regs */

int
cl_r6k::SL1REG(MP)
{
  cJKHL.set(cPW.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RL1REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPW.get());
  cPW.set(t);
  tick(3);
  return resGO;
}

int
cl_r6k::SR1REG(MP)
{
  cJKHL.set(cPW.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RR1REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPW.get());
  cPW.set(t);
  tick(3);
  return resGO;
}

/* shift/rotate regs */

int
cl_r6k::SL2REG(MP)
{
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RL2REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(t);
  tick(3);
  return resGO;
}

int
cl_r6k::SR2REG(MP)
{
  cJKHL.set(cPX.get());
  cPX.set(cPW.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RR2REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPX.get());
  cPX.set(cPW.get());
  cPW.set(t);
  tick(3);
  return resGO;
}

/* shift/rotate regs */

int
cl_r6k::SL3REG(MP)
{
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RL3REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  cPY.set(t);
  tick(3);
  return resGO;
}

int
cl_r6k::SR3REG(MP)
{
  cJKHL.set(cPY.get());
  cPY.set(cPX.get());
  cPX.set(cPW.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RR3REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPY.get());
  cPY.set(cPX.get());
  cPX.set(cPW.get());
  cPW.set(t);
  tick(3);
  return resGO;
}

/* shift/rotate regs */

int
cl_r6k::SL4REG(MP)
{
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  cPY.set(cPZ.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RL4REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  cPY.set(cPZ.get());
  cPZ.set(t);
  tick(3);
  return resGO;
}

int
cl_r6k::SR4REG(MP)
{
  cJKHL.set(cPZ.get());
  cPZ.set(cPY.get());
  cPY.set(cPX.get());
  cPX.set(cPW.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RR4REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPZ.get());
  cPZ.set(cPY.get());
  cPY.set(cPX.get());
  cPX.set(cPW.get());
  cPW.set(t);
  tick(3);
  return resGO;
}

/* shift/rotate regs */

int
cl_r6k::SL5REG(MP)
{
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  cPY.set(cPZ.get());
  cPZ.set(caPW.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RL5REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  cPY.set(cPZ.get());
  cPZ.set(caPW.get());
  caPW.set(t);
  tick(3);
  return resGO;
}

int
cl_r6k::SR5REG(MP)
{
  cJKHL.set(caPW.get());
  caPW.set(cPZ.get());
  cPZ.set(cPY.get());
  cPY.set(cPX.get());
  cPX.set(cPW.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RR5REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(caPW.get());
  caPW.set(cPZ.get());
  cPZ.set(cPY.get());
  cPY.set(cPX.get());
  cPX.set(cPW.get());
  cPW.set(t);
  tick(3);
  return resGO;
}

/* shift/rotate regs */

int
cl_r6k::SL6REG(MP)
{
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  cPY.set(cPZ.get());
  cPZ.set(caPW.get());
  caPW.set(caPX.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RL6REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  cPY.set(cPZ.get());
  cPZ.set(caPW.get());
  caPW.set(caPX.get());
  caPX.set(t);
  tick(3);
  return resGO;
}

int
cl_r6k::SR6REG(MP)
{
  cJKHL.set(caPX.get());
  caPX.set(caPW.get());
  caPW.set(cPZ.get());
  cPZ.set(cPY.get());
  cPY.set(cPX.get());
  cPX.set(cPW.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RR6REG(MP)
{
  tick(3);
  return resGO;
}

/* shift/rotate regs */

int
cl_r6k::SL7REG(MP)
{
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  cPY.set(cPZ.get());
  cPZ.set(caPW.get());
  caPW.set(caPX.get());
  caPX.set(caPY.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RL7REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  cPY.set(cPZ.get());
  cPZ.set(caPW.get());
  caPW.set(caPX.get());
  caPX.set(caPY.get());
  caPY.set(t);
  tick(3);
  return resGO;
}

int
cl_r6k::SR7REG(MP)
{
  cJKHL.set(caPY.get());
  caPY.set(caPX.get());
  caPX.set(caPW.get());
  caPW.set(cPZ.get());
  cPZ.set(cPY.get());
  cPY.set(cPX.get());
  cPX.set(cPW.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RR7REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(caPY.get());
  caPY.set(caPX.get());
  caPX.set(caPW.get());
  caPW.set(cPZ.get());
  cPZ.set(cPY.get());
  cPY.set(cPX.get());
  cPX.set(cPW.get());
  cPW.set(t);
  tick(3);
  return resGO;
}

/* shift/rotate regs */

int
cl_r6k::SL8REG(MP)
{
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  cPY.set(cPZ.get());
  cPZ.set(caPW.get());
  caPW.set(caPX.get());
  caPX.set(caPY.get());
  caPY.set(caPZ.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RL8REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(cPW.get());
  cPW.set(cPX.get());
  cPX.set(cPY.get());
  cPY.set(cPZ.get());
  cPZ.set(caPW.get());
  caPW.set(caPX.get());
  caPX.set(caPY.get());
  caPY.set(caPZ.get());
  caPZ.set(t);
  tick(3);
  return resGO;
}

int
cl_r6k::SR8REG(MP)
{
  cJKHL.set(caPZ.get());
  caPZ.set(caPY.get());
  caPY.set(caPX.get());
  caPX.set(caPW.get());
  caPW.set(cPZ.get());
  cPZ.set(cPY.get());
  cPY.set(cPX.get());
  cPX.set(cPW.get());
  tick(3);
  return resGO;
}

int
cl_r6k::RR8REG(MP)
{
  u32_t t= cJKHL.get();
  cJKHL.set(caPZ.get());
  caPZ.set(caPY.get());
  caPY.set(caPX.get());
  caPX.set(caPW.get());
  caPW.set(cPZ.get());
  cPZ.set(cPY.get());
  cPY.set(cPX.get());
  cPX.set(cPW.get());
  cPW.set(t);
  tick(3);
  return resGO;
}

/* JKHL = ((PX ^ PY) & PW) ^ PY */

int
cl_r6k::SHAF1(MP)
{
  u32_t v= cPX.get() ^ cPY.get();
  v&= cPW.get();
  v^= cPY.get();
  cJKHL.W(v);
  tick(3);
  return resGO;
}

/* JKHL = ((PW | PX) & PY) | (PW & PX) */

int
cl_r6k::SHAF2(MP)
{
  u32_t v1= cPW.get() | cPX.get();
  v1&= cPY.get();
  u32_t v2= cPW.get() & cPX.get();
  v1|= v2;
  cJKHL.W(v1);
  tick(3);
  return resGO;
}

/* JKHL = PW ^ PX ^ PY */

int
cl_r6k::SHAF3(MP)
{
  u32_t v= cPW.get();
  v^= cPX.get();
  v^= cPY.get();
  cJKHL.W(v);
  tick(3);
  return resGO;
}

/* JKHL + (PW & PX) | ((~PW) & PY) */

int
cl_r6k::MD5F1(MP)
{
  u32_t v1= cPW.get();
  v1&= cPX.get();
  u32_t v2= ~cPW.get();
  v2&= cPY.get();
  v1|= v2;
  cJKHL.W(v1);
  tick(3);
  return resGO;
}

/* JKHL = (PY & PW) | ((~PY) & PX) */

int
cl_r6k::MD5F2(MP)
{
  u32_t v1= cPY.get();
  v1&= cPW.get();
  u32_t v2= ~cPY.get();
  v2&= cPX.get();
  v1|= v2;
  cJKHL.W(v1);
  tick(3);
  return resGO;
}

/* JKHL = PX ^ (PW | (~PY)) */

int
cl_r6k::MD5F3(MP)
{
  u32_t v= ~cPY.get();
  v|= cPW.get();
  v^= cPX.get();
  cJKHL.W(v);
  tick(3);
  return resGO;
}

/* IO:d (PX) = (PY); BC = BC-1; PX = PX+1; PY = PY+1 */

void
cl_r6k::pldi(void)
{
  u8_t f= cF.get();
  f&= ~flagV;
  u8_t v= mem->pxread(cPY.get());
  pxwriteio(cPX.get(), v);
  cBC.W(cBC.get()-1);
  u32_t p= px8(cPX.get(), 1);
  cPX.W(p);
  p= px8(cPY.get(), 1);
  cPY.W(p);
  // TODO: how to set V?
  cF.W(f);
}

int
cl_r6k::PLDIR(MP)
{
  u8_t f= cF.get() & ~flagV;
  tick(6);
  do {
    pldi();
    tick(6);
  }
  while (cBC.get());
  cF.W(f);
  return resGO;
}

/* IO:d (PX) = (PY); BC = BC-1; PY = PY+1; repeat while {BC != 0} */

int
cl_r6k::PLDISR(MP)
{
  u8_t f= cF.get(), v;
  u32_t p, bc;
  f&= ~flagV;
  tick(6);
  do {
    v= mem->pxread(cPY.get());
    pxwriteio(cPX.get(), v);
    cBC.W(bc= cBC.get()-1);
    p= px8(cPY.get(), 1);
    cPY.W(p);
    tick(6);
  }
  while (bc);
  // TODO: how to set V?
  cF.W(f);
  return resGO;
}

/* IO:d  (PX) = (PY); BC = BC-1; PX = PX-1; PY = PY-1 */

void
cl_r6k::pldd(void)
{
  u8_t f= cF.get();
  f&= ~flagV;
  u8_t v= mem->pxread(cPY.get());
  pxwriteio(cPX.get(), v);
  cBC.W(cBC.get()-1);
  u32_t p= px8se(cPX.get(), -1);
  cPX.W(p);
  p= px8se(cPY.get(), -1);
  cPY.W(p);
  // TODO: how to set V?
  cF.W(f);
}


int
cl_r6k::PLDDR(MP)
{
  u8_t f= cF.get() & ~flagV;
  tick(6);
  do {
    pldd();
    tick(6);
  }
  while (cBC.get());
  cF.W(f);
  return resGO;
}

/* IO:d (PX) = (PY); BC = BC-1; PY = PY-1; repeat while {BC != 0} */

int
cl_r6k::PLDDSR(MP)
{
  u8_t f= cF.get(), v;
  u32_t p, bc;
  f&= ~flagV;
  tick(6);
  do {
    v= mem->pxread(cPY.get());
    pxwriteio(cPX.get(), v);
    cBC.W(bc= cBC.get()-1);
    p= px8se(cPY.get(), -1);
    cPY.W(p);
    tick(6);
  }
  while (bc);
  // TODO: how to set V?
  cF.W(f);
  return resGO;
}

/* IO:s (PX) = (PY); BC = BC-1; PX = PX+1; PY = PY+1; repeat while {BC != 0} */

int
cl_r6k::PLSIR(MP)
{
  u8_t f= cF.get() & ~flagV, v;
  u32_t p, bc;
  tick(6);
  do {
    v= pxreadio(cPY.get());
    mem->pxwrite(cPX.get(), v);
    p= px8(cPX.get(), 1);
    cPX.W(p);
    p= px8(cPY.get(), 1);
    cPY.W(p);
    cBC.W(bc= cBC.get()-1);
    tick(6);
  }
  while (bc);
  cF.W(f);
  return resGO;
}


/* IO:s (PX) = (PY); BC = BC-1; PX = PX+1; repeat while {BC != 0} */

int
cl_r6k::PLSIDR(MP)
{
  u8_t f= cF.get() & ~flagV, v;
  u32_t p, bc;
  tick(6);
  do {
    v= pxreadio(cPY.get());
    mem->pxwrite(cPX.get(), v);
    p= px8(cPX.get(), 1);
    cPX.W(p);
    cBC.W(bc= cBC.get()-1);
    tick(6);
  }
  while (bc);
  cF.W(f);
  return resGO;
}


/* IO:s (PX) = (PY); BC = BC-1; PX = PX-1; PY = PY-1; repeat while {BC != 0} */

int
cl_r6k::PLSDR(MP)
{
  u8_t f= cF.get() & ~flagV, v;
  u32_t p, bc;
  tick(6);
  do {
    v= pxreadio(cPY.get());
    mem->pxwrite(cPX.get(), v);
    p= px8se(cPX.get(), -1);
    cPX.W(p);
    p= px8se(cPY.get(), -1);
    cPY.W(p);
    cBC.W(bc= cBC.get()-1);
    tick(6);
  }
  while (bc);
  cF.W(f);
  return resGO;
}


/* IO:s (PX) = (PY); BC = BC-1; PX = PX-1; repeat while {BC != 0} */

int
cl_r6k::PLSDDR(MP)
{
  u8_t f= cF.get() & ~flagV, v;
  u32_t p, bc;
  tick(6);
  do {
    v= pxreadio(cPY.get());
    mem->pxwrite(cPX.get(), v);
    p= px8se(cPX.get(), -1);
    cPX.W(p);
    cBC.W(bc= cBC.get()-1);
    tick(6);
  }
  while (bc);
  cF.W(f);
  return resGO;
}


/* End of rxk.src/r6k.cc */
