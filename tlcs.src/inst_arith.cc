/*
 * Simulator of microcontrollers (tlcs.src/inst_arith.cc)
 *
 * Copyright (C) 2016,16 Drotos Daniel, Talker Bt.
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

/* $Id$ */

#include "tlcscl.h"


// INC 8-bit
uint8_t
cl_tlcs::inc(uint8_t data)
{
  uint16_t n= data+1;
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X);

  if (n > 255)
    reg.f|= FLAG_X;
  if (n & 0x80)
    reg.f|= FLAG_S;
  if ((n & 0xff) == 0)
    reg.f|= FLAG_Z;
  if (data == 0x7f)
    reg.f|= FLAG_V;
  if ((n & 0x0f) == 0x00)
    reg.f|= FLAG_H;

  return n;
}


// INC mem
void
cl_tlcs::inc(cl_memory_cell *cell)
{
  uint8_t d= cell->read();
  d= inc(d);
  cell->write(d);
}


// INC 8-bit
uint8_t
cl_tlcs::dec(uint8_t data)
{
  uint16_t n= data-1;
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X);
  reg.f|= FLAG_N;
  
  if (n > 255)
    reg.f|= FLAG_X;
  if (n & 0x80)
    reg.f|= FLAG_S;
  if ((n & 0xff) == 0)
    reg.f|= FLAG_Z;
  if (data == 0x80)
    reg.f|= FLAG_V;
  if ((n & 0x0f) == 0x00)
    reg.f|= FLAG_H;

  return n & 0xff;
}


// DEC mem
void
cl_tlcs::dec(cl_memory_cell *cell)
{
  uint8_t d= cell->read();
  d= dec(d);
  cell->write(d);
}


// INC 16-bit
uint16_t
cl_tlcs::inc16(uint16_t data)
{
  uint16_t n= data+1;
  reg.f&= ~(FLAG_X);

  if (n == 0)
    reg.f|= FLAG_X;

  return n;
}


// INCW mem
uint16_t
cl_tlcs::inc16(t_addr addr)
{
  uint8_t l= nas->read(addr);
  uint8_t h= nas->read(addr+1);
  uint16_t d= h*256 + l;

  if (((int)d + 1) > 0xffff)
    reg.f|= FLAG_V;
  
  d= inc16(d);
  reg.f&= ~FLAG_N;
  if (d & 0x8000)
    reg.f|= FLAG_S;
  if (d == 0)
    reg.f|= FLAG_Z;

  nas->write(addr, d & 0xff);
  nas->write(addr+1, d >> 8);
  
  return d;
}


// DEC 16-bit
uint16_t
cl_tlcs::dec16(uint16_t data)
{
  uint16_t n= data-1;
  reg.f&= ~(FLAG_X);

  if (n == 0xffff)
    reg.f|= FLAG_X;

  return n;
}


// DECW mem
uint16_t
cl_tlcs::dec16(t_addr addr)
{
  uint8_t l= nas->read(addr);
  uint8_t h= nas->read(addr+1);
  uint16_t d= h*256 + l;

  if (((int)d - 1) < 0)
    reg.f|= FLAG_V;
  
  d= dec16(d);
  reg.f&= ~FLAG_N;
  if (d & 0x8000)
    reg.f|= FLAG_S;
  if (d == 0)
    reg.f|= FLAG_Z;

  nas->write(addr, d & 0xff);
  nas->write(addr+1, d >> 8);
  
  return d;
}


// ADD A,8-bit
uint8_t
cl_tlcs::add_a(uint8_t d)
{
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X|FLAG_V|FLAG_N|FLAG_C);

  uint8_t m= d;
  int r= reg.a + m;
  int new_c= 0, new_c6;
  
  if (((reg.a & 0xf) + (m & 0xf)) > 0xf)
    reg.f|= FLAG_H;
  new_c6= (((reg.a&0x7f) + (m&0x7f)) > 0x7f)?1:0;
  
  //reg.a= r;

  if (m & 0x80)
    reg.f|= FLAG_S;
  if ((r&0xff) == 0)
    reg.f|= FLAG_Z;
  if (m > 255)
    {
      reg.f|= FLAG_X|FLAG_C;
      new_c= 1;
    }
  if (new_c ^ new_c6)
    reg.f|= FLAG_V;

  return r & 0xff;
}


// ADC A,8-bit
int
cl_tlcs::adc_a(uint8_t d)
{
  int oldc= (reg.f&FLAG_C)?1:0;
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X|FLAG_V|FLAG_N|FLAG_C);

  uint8_t m= d;
  int r= reg.a + m + oldc;
  int new_c= 0, new_c6;
  
  if (((reg.a & 0xf) + (m & 0xf) + oldc) > 0xf)
    reg.f|= FLAG_H;
  new_c6= (((reg.a&0x7f) + (m&0x7f) + oldc) > 0x7f)?1:0;
  
  reg.a= r;

  if (m & 0x80)
    reg.f|= FLAG_S;
  if (reg.a == 0)
    reg.f|= FLAG_Z;
  if (m > 255)
    {
      reg.f|= FLAG_X|FLAG_C;
      new_c= 1;
    }
  if (new_c ^ new_c6)
    reg.f|= FLAG_V;

  return resGO;
}


// SUB A,8-bit
int
cl_tlcs::sub_a(uint8_t d)
{
  reg.a= add_a(~d + 1);
  reg.f|= FLAG_N;
  return resGO;
}


// SBC A,8-bit
int
cl_tlcs::sbc_a(uint8_t d)
{
  adc_a(~d + 1);
  reg.f|= FLAG_N;
  return resGO;
}


// AND A,8-bit
int
cl_tlcs::and_a(uint8_t d)
{
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_X|FLAG_N|FLAG_C);
  reg.f|= FLAG_H;

  reg.a&= d;
  set_p(reg.a);
  if (reg.a & 0x80)
    reg.f|= FLAG_S;
  if (reg.a == 0)
    reg.f|= FLAG_Z;

  return resGO;
}


// XOR A,8-bit
int
cl_tlcs::xor_a(uint8_t d)
{
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X|FLAG_N|FLAG_C);

  reg.a^= d;
  set_p(reg.a);
  if (reg.a & 0x80)
    reg.f|= FLAG_S;
  if (reg.a == 0)
    reg.f|= FLAG_Z;

  return resGO;
}


// OR A,8-bit
int
cl_tlcs::or_a(uint8_t d)
{
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X|FLAG_N|FLAG_C);

  reg.a|= d;
  set_p(reg.a);
  if (reg.a & 0x80)
    reg.f|= FLAG_S;
  if (reg.a == 0)
    reg.f|= FLAG_Z;

  return resGO;
}


// CP A,8-bit
int
cl_tlcs::cp_a(uint8_t d)
{
  add_a(~d + 1);
  reg.f|= FLAG_N;
  return resGO;
}


// ADD A,mem
int
cl_tlcs::add_a(class cl_memory_cell *cell)
{
  reg.a= add_a((uint8_t)(cell->read()));
  return resGO;
}


// ADC A,mem
int
cl_tlcs::adc_a(class cl_memory_cell *cell)
{
  return adc_a((uint8_t)(cell->read()));
}


// SUB A,mem
int
cl_tlcs::sub_a(class cl_memory_cell *cell)
{
  return sub_a((uint8_t)(cell->read()));
}


// SBC A,mem
int
cl_tlcs::sbc_a(class cl_memory_cell *cell)
{
  return sbc_a((uint8_t)(cell->read()));
}


// AND A,mem
int
cl_tlcs::and_a(class cl_memory_cell *cell)
{
  return and_a((uint8_t)(cell->read()));
}


// XOR A,mem
int
cl_tlcs::xor_a(class cl_memory_cell *cell)
{
  return xor_a((uint8_t)(cell->read()));
}


// OR A,mem
int
cl_tlcs::or_a(class cl_memory_cell *cell)
{
  return or_a((uint8_t)(cell->read()));
}


// CP A,mem
int
cl_tlcs::cp_a(class cl_memory_cell *cell)
{
  return cp_a((uint8_t)(cell->read()));
}


// ADD HL,mem
uint16_t
cl_tlcs::add_hl(t_addr addr)
{
  uint8_t dh, dl;
  uint16_t d;
  int r, newc15;
  
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_X|FLAG_N|FLAG_C);
  
  dl= nas->read(addr);
  dh= nas->read(addr+1);
  d= dh*256 + dl;

  r= reg.hl + d;
  newc15= (((reg.hl&0x7fff)+(d&0x7fff)) > 0x7fff)?0x10000:0;
  
  if (r & 0x8000)
    reg.f|= FLAG_S;
  if ((r & 0xffff) == 0)
    reg.f|= FLAG_Z;
  if (r > 0xffff)
    reg.f|= FLAG_C|FLAG_X;
  if (newc15 ^ (r&0x10000))
    reg.f|= FLAG_V;
  
  return r & 0xffff;
}


// ADD HL,16-bit
uint16_t
cl_tlcs::add_hl(t_mem val)
{
  uint16_t d;
  int r, newc15;
  
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_X|FLAG_N|FLAG_C);
  
  d= val;

  r= reg.hl + d;
  newc15= (((reg.hl&0x7fff)+(d&0x7fff)) > 0x7fff)?0x10000:0;
  
  if (r & 0x8000)
    reg.f|= FLAG_S;
  if ((r & 0xffff) == 0)
    reg.f|= FLAG_Z;
  if (r > 0xffff)
    reg.f|= FLAG_C|FLAG_X;
  if (newc15 ^ (r&0x10000))
    reg.f|= FLAG_V;
  
  return r & 0xffff;
}


// ADD 16-bit
uint16_t
cl_tlcs::add16(t_mem op1, t_mem op2)
{
  uint16_t d1, d;
  int r, newc15;
  
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_X|FLAG_N|FLAG_C);

  d1= op1;
  d= op2;

  r= d1 + d;
  newc15= (((d1&0x7fff)+(d&0x7fff)) > 0x7fff)?0x10000:0;
  
  if (r & 0x8000)
    reg.f|= FLAG_S;
  if ((r & 0xffff) == 0)
    reg.f|= FLAG_Z;
  if (r > 0xffff)
    reg.f|= FLAG_C|FLAG_X;
  if (newc15 ^ (r&0x10000))
    reg.f|= FLAG_V;
  
  return r & 0xffff;
}


// ADC HL,mem
uint16_t
cl_tlcs::adc_hl(t_addr addr)
{
  uint8_t dl= nas->read(addr);
  uint8_t dh= nas->read(addr+1);
  uint16_t d= dh*256 + dl;
  int oldc= (reg.f & FLAG_C)?1:0;
  
  return add_hl((t_mem)d + oldc);
}


// SUB HL,mem
uint16_t
cl_tlcs::sub_hl(t_addr addr)
{
  uint8_t dl= nas->read(addr);
  uint8_t dh= nas->read(addr+1);
  uint16_t d= dh*256 + dl;
  uint16_t r;

  r= add_hl((t_mem)(~d + 1));
  reg.f|= FLAG_N;

  return r;
}


// SUB 16-bit
uint16_t
cl_tlcs::sub16(t_mem op1, t_mem op2)
{
  uint16_t d= op2;
  uint16_t r;

  r= add16(op1, (t_mem)(~d + 1));
  reg.f|= FLAG_N;

  return r;
}


// SBC HL,mem
uint16_t
cl_tlcs::sbc_hl(t_addr addr)
{
  uint8_t dl= nas->read(addr);
  uint8_t dh= nas->read(addr+1);
  uint16_t d= dh*256 + dl;
  uint16_t r;
  int oldc= (reg.f & FLAG_C)?1:0;
  
  r= add_hl((t_mem)(~d + 1 + oldc));
  reg.f|= FLAG_N;

  return r;
}


// AND HL,16-bit
uint16_t
cl_tlcs::and_hl(t_mem val)
{
  uint16_t d= val;
  uint16_t r;

  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_X|FLAG_N|FLAG_C);
  reg.f|= FLAG_H;
  
  r= reg.hl & d;
  if (r & 0x8000)
    reg.f|= FLAG_S;
  if (r == 0)
    reg.f|= FLAG_Z;
  
  return r;
}


// AND HL,mem
uint16_t
cl_tlcs::and_hl(t_addr addr)
{
  uint8_t dl= nas->read(addr);
  uint8_t dh= nas->read(addr+1);
  uint16_t d= dh*256 + dl;
  
  return and_hl((t_mem)d);
}


// XOR HL,16-bit
uint16_t
cl_tlcs::xor_hl(t_mem val)
{
  uint16_t d= val;
  uint16_t r;

  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X|FLAG_N|FLAG_C);
  
  r= reg.hl ^ d;
  if (r & 0x8000)
    reg.f|= FLAG_S;
  if (r == 0)
    reg.f|= FLAG_Z;
  
  return r;
}


// XOR HL,mem
uint16_t
cl_tlcs::xor_hl(t_addr addr)
{
  uint8_t dl= nas->read(addr);
  uint8_t dh= nas->read(addr+1);
  uint16_t d= dh*256 + dl;
  
  return xor_hl((t_mem)d);
}


// OR HL,16-bit
uint16_t
cl_tlcs::or_hl(t_mem val)
{
  uint16_t d= val;
  uint16_t r;

  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X|FLAG_N|FLAG_C);
  
  r= reg.hl | d;
  if (r & 0x8000)
    reg.f|= FLAG_S;
  if (r == 0)
    reg.f|= FLAG_Z;
  
  return r;
}


// OR HL,mem
uint16_t
cl_tlcs::or_hl(t_addr addr)
{
  uint8_t dl= nas->read(addr);
  uint8_t dh= nas->read(addr+1);
  uint16_t d= dh*256 + dl;
  
  return or_hl((t_mem)d);
}


/* End of tlcs/inst_arith.cc */
