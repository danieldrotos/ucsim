/*
 * Simulator of microcontrollers (imove.cc)
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
cl_f8::ld8_a_i(u8_t op2)
{
  acc8->W(op2);
  return resGO;
}

int
cl_f8::ld8_a_m(class cl_cell8 &m)
{
  acc8->W(m.R());
  vc.rd++;
  return resGO;
}

int
cl_f8::ld8_m_a(class cl_cell8 &m)
{
  m.W(acc8->get());
  vc.wr++;
  return resGO;
}

int
cl_f8::ld8_a_r(class cl_cell8 &r)
{
  class cl_cell8 *op1, *op2;
  IFSWAP
    {
      op2= acc8;
      op1= &r;
    }
  else
    {
      op1= acc8;
      op2= &r;
    }
  op1->W(op2->R());
  return resGO;
}

int
cl_f8::LD8_YL_I(t_mem code)
{
  cYL.W(fetch());
  return resGO;
}

int
cl_f8::ldw_a_i(u16_t op2)
{
  acc16->W(op2);
  return resGO;
}

int
cl_f8::ldw_a_m(u16_t addr)
{
  u16_t v= rom->read(addr);
  v+= (rom->read(addr+1))*256;
  acc16->W(v);
  vc.rd+= 2;
  return resGO;
}

int
cl_f8::ldw_m_a(u16_t addr)
{
  u16_t v= acc16->get();
  rom->write(addr, v);
  rom->write(addr+1, v>>8);
  vc.wr+= 2;
  return resGO;
}

int
cl_f8::ldw_m_r(u16_t addr, u16_t r)
{
  rom->write(addr, r);
  rom->write(addr+1, r>>8);
  vc.wr+= 2;
  return resGO;
}

int
cl_f8::LDW_SP_A(t_mem code)
{
  cSP.W(acc16->get());
  return resGO;
}

int
cl_f8::LDW_DSP_A(t_mem code)
{
  i8_t d= fetch();
  u16_t pa= rSP+d;
  u16_t a= read_addr(rom, pa);
  vc.rd+= 2;
  u16_t v= acc16->get();
  rom->write(a++, v);
  rom->write(a, v>>8);
  vc.wr+= 2;
  return resGO;
}


int
cl_f8::PUSH_M(t_mem code)
{
  class cl_cell8 &c= m_mm();
  push1(c.R());
  vc.rd++;
  return resGO;
}

int
cl_f8::PUSH_NSP(t_mem code)
{
  class cl_cell8 &c= m_n_sp();
  push1(c.R());
  vc.rd++;
  return resGO;
}

int
cl_f8::PUSH_A(t_mem code)
{
  push1(acc8->get()); // TODO?
  return resGO;
}

int
cl_f8::PUSH_ZH(t_mem code)
{
  push1(rZH); // TODO?
  return resGO;
}

int
cl_f8::PUSH_I(t_mem code)
{
  push1(fetch());
  return resGO;
}

int
cl_f8::PUSHW_M(t_mem code)
{
  u16_t a= a_mm();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  push2(v);
  return resGO;
}

int
cl_f8::PUSHW_NSP(t_mem code)
{
  u16_t a= a_n_sp();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  push2(v);
  return resGO;
}

int
cl_f8::PUSHW_NNZ(t_mem code)
{
  u16_t a= a_nn_z();
  u16_t v= read_addr(rom, a);
  vc.rd+= 2;
  push2(v);
  return resGO;
}

int
cl_f8::PUSHW_A(t_mem code)
{
  u16_t v= acc16->get();
  push2(v);
  return resGO;
}

int
cl_f8::PUSHW_I(t_mem code)
{
  u8_t l, h;
  l= fetch();
  h= fetch();
  push2(h, l);
  return resGO;
}

int
cl_f8::POP_A(t_mem code)
{
  acc8->W(pop1());
  return resGO;
}

int
cl_f8::POPW_A(t_mem code)
{
  acc16->W(pop2());
  return resGO;
}


/* End of f8.src/imove.cc */
