/*
 * Simulator of microcontrollers (ibranch.cc)
 *
 * Copyright (C) 2020,2021 Drotos Daniel, Talker Bt.
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

#include "appcl.h"

#include "rxkcl.h"
#include "r3kacl.h"
#include "r4kcl.h"


int
cl_rxk::DJNZ(t_mem code)
{
  u8_t v= rB - 1;
  i8_t r= fetch();
  destB().W(v);
  if (v)
    PC= (PC + r) & 0xffff;
  tick5p1(4);
  return resGO;
}

int
cl_rxk::JR(t_mem code)
{
  i8_t r= fetch();
  PC= (PC + r) & 0xffff;
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
  cXPC.W(x);
  PC= h*256+l;
  tick(9);
  return resGO;
}

int
cl_rxk::CALL_mn(t_mem code)
{
  u8_t h, l;
  l= fetch();
  h= fetch();
  rom->write(--rSP, PC>>8);
  rom->write(--rSP, PC);
  PC= h*256+l;
  cSP.W(rSP);
  tick5p1(11);
  vc.wr+= 2;
  return resGO;
}

int
cl_rxk::LCALL_lmn(t_mem code)
{
  u8_t h, l, x;
  l= fetch();
  h= fetch();
  x= fetch();
  cSP.W(rSP-1);
  rom->write(rSP, rXPC);
  cSP.W(rSP-1);
  rom->write(rSP, PC>>8);
  cSP.W(rSP-1);
  rom->write(rSP, PC);
  PC= h*256+l;
  cXPC.W(x);
  tick5p1(18);
  vc.wr+= 3;
  return resGO;
}

int
cl_rxk::rst_v(t_mem code)
{
  if ((jaj || (juj&1)) && (code == 0xef)) return resGO;
  u8_t l= (code&0x38) << 1;
  cSP.W(rSP-1);
  rom->write(rSP, PC>>8);
  cSP.W(rSP-1);
  rom->write(rSP, PC);
  PC= rIIR * 256 + l;
  vc.wr+= 2;
  tick5p3(7);
  return resGO;
}


int
cl_rxk::jr_cc(bool cond)
{
  i8_t r= fetch();
  if (cond)
    PC= (PC + r) & 0xffff;
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
      cSP.W(++rSP);
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

int
cl_rxk::LRET(t_mem code)
{
  u8_t l, h, x;
  l= mem->read(rSP);
  cSP.W(++rSP);
  h= mem->read(rSP);
  cSP.W(++rSP);
  PC= h*256+l;
  x= mem->read(rSP);
  cSP.W(++rSP);
  cXPC.W(x);
  tick(12);
  return resGO;
}

int
cl_rxk::RETI(t_mem code)
{
  u8_t l, h, x;
  x= mem->read(rSP);
  cSP.W(++rSP);
  l= mem->read(rSP);
  cSP.W(++rSP);
  h= mem->read(rSP);
  cSP.W(++rSP);
  PC= h*256+l;
  cIP.W(x);
  tick(11);
  return resGO;
}


/*
 *                                                    R3000A,R4000,R5000
 */

int
cl_r3ka::SYSCALL(t_mem code)
{
  cSP.W(rSP-1);
  rom->write(rSP, PC>>8);
  cSP.W(rSP-1);
  rom->write(rSP, PC);
  PC= rIIR * 256 + 0x60;
  vc.wr+= 2;
  tick5p3(9);
  return resGO;
}

int
cl_r4k::DWJNZ(t_mem code)
{
  i8_t e= fetch();
  u16_t v= rBC-1;
  destBC().W(v);
  if (v)
    PC= (PC + e) & 0xffff;
  tick5p1(6);
  return resGO;
}

int
cl_r4k::lljp_cx(t_mem code)
{
  u8_t cx= (code>>3) & 0x3;
  bool cond= false, z, s, v, c, sxv;
  s= rF & flagS;
  v= rF & flagV;
  z= rF & flagZ;
  c= rF & flagC;
  sxv= (!s && v) || (s && !v);
  switch (cx)
    {
    case 0: // GT: (Z or (S xor V))=0
      cond= !(z || (sxv));
      break;
    case 1: // GTU: ((C=0) and (Z=0))=1
      cond= !c && !z;
      break;
    case 2: // LT: (S xor V)=1
      cond= sxv;
      break;
    case 3: // V: V=1
      cond= rF & flagV;
      break;
    }
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
cl_r4k::lljp_cc(t_mem code)
{
  u8_t cc= (code>>3) & 0x3;
  bool cond= false, z, c;
  z= rF & flagZ;
  c= rF & flagC;
  switch (cc)
    {
    case 0: // NZ
      cond= !z;
      break;
    case 1: // Z
      cond= z;
      break;
    case 2: // NC
      cond= !c;
      break;
    case 3: // C
      cond= c;
      break;
    }
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


/* End of rxk.src/ibranch.cc */
