/*
 * Simulator of microcontrollers (tlcs.src/arith.cc)
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

#include "tlcscl.h"


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

  return n & 0xff;
}


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


uint16_t
cl_tlcs::inc16(uint16_t data)
{
  uint16_t n= data+1;
  reg.f&= ~(FLAG_X);

  if (n == 0)
    reg.f|= FLAG_X;

  return n;
}


uint16_t
cl_tlcs::dec16(uint16_t data)
{
  uint16_t n= data-1;
  reg.f&= ~(FLAG_X);

  if (n == 0xffff)
    reg.f|= FLAG_X;

  return n;
}


// ADD A,8-bit
int
cl_tlcs::add_a(uint8_t d)
{
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X|FLAG_V|FLAG_N|FLAG_C);

  uint8_t m= d;
  int r= reg.a + m;
  bool new_c= false, new_c6;
  
  if (((reg.a & 0xf) + (m & 0xf)) > 0xf)
    reg.f|= FLAG_H;
  new_c6= ((reg.a&0x7f) + (m&0x7f)) > 0x7f;
  
  reg.a= r;

  if (m & 0x80)
    reg.f|= FLAG_S;
  if (reg.a == 0)
    reg.f|= FLAG_Z;
  if (m > 255)
    {
      reg.f|= FLAG_X|FLAG_C;
      new_c= true;
    }
  if (new_c ^ new_c6)
    reg.f|= FLAG_V;

  return resGO;
}


// ADC A,8-bit
int
cl_tlcs::adc_a(uint8_t d)
{
  int oldc= (reg.f&FLAG_C)?1:0;
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X|FLAG_V|FLAG_N|FLAG_C);

  uint8_t m= d;
  int r= reg.a + m + oldc;
  bool new_c= false, new_c6;
  
  if (((reg.a & 0xf) + (m & 0xf) + oldc) > 0xf)
    reg.f|= FLAG_H;
  new_c6= ((reg.a&0x7f) + (m&0x7f) + oldc) > 0x7f;
  
  reg.a= r;

  if (m & 0x80)
    reg.f|= FLAG_S;
  if (reg.a == 0)
    reg.f|= FLAG_Z;
  if (m > 255)
    {
      reg.f|= FLAG_X|FLAG_C;
      new_c= true;
    }
  if (new_c ^ new_c6)
    reg.f|= FLAG_V;

  return resGO;
}


// SUB A,8-bit
int
cl_tlcs::sub_a(uint8_t d)
{
  add_a(~d + 1);
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


// ADD A,mem
int
cl_tlcs::add_a(class cl_memory_cell *cell)
{
  return add_a((uint8_t)(cell->read()));
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


/* End of tlcs/arith.cc */
