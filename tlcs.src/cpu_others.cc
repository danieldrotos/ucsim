/*
 * Simulator of microcontrollers (tlcs.src/cpu_others.cc)
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


// 0B
int
cl_tlcs::daa_a()
{
  if (((reg.a & 0x0f) > 9) ||
      (reg.f & FLAG_H))
    {
      int al= reg.a & 0x0f;
      if (al + 6 > 15)
	reg.f|= FLAG_H;
      else
	reg.f&= ~FLAG_H;
      if ((int)reg.a + 6 > 255)
	reg.f|= FLAG_C|FLAG_X;
      else
	reg.f&= ~(FLAG_C|FLAG_X);
      reg.a+= 6;
    }
  if (((reg.a & 0xf0) > 0x90) ||
      (reg.f & FLAG_C))
    {
      if ((int)reg.a + 0x60 > 255)
	reg.f|= FLAG_C;
      else
	reg.f&= ~FLAG_C;
      reg.a+= 0x60;
    }
  return resGO;
}


// 10
int
cl_tlcs::cpl_a()
{
  reg.a= ~reg.a;
  reg.f|= FLAG_H|FLAG_N;
  return resGO;
}


// 11
int
cl_tlcs::neg_a()
{
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H/*|FLAG_X*/|FLAG_V|FLAG_C);
  reg.f|= FLAG_N;
  if (reg.a == 0x80)
    reg.f|= FLAG_V;
  if (reg.a)
    reg.f|= (FLAG_C|FLAG_X);

  //uint8_t a= ~reg.a;
  if ((reg.a & 0x0f) == 0)//if (a&0xf + 1 > 15)
    reg.f|= FLAG_H;
  reg.a= 0-reg.a;

  if (reg.a & 0x80)
    reg.f|= FLAG_S;
  if (!reg.a)
    reg.f|= FLAG_Z;
  
  return resGO;
}


// 0e
int
cl_tlcs::ccf()
{
  if (reg.f & FLAG_C)
    reg.f&= ~(FLAG_C);
  else
    reg.f|= FLAG_C;
  if (reg.f & FLAG_X)
    reg.f&= ~(FLAG_X);
  else
    reg.f|= FLAG_X;
  reg.f&= ~FLAG_N;
  return resGO;
}


// 0d
int
cl_tlcs::scf()
{
  reg.f|= FLAG_C|FLAG_X;
  reg.f&= ~(FLAG_N|FLAG_H);
  return resGO;
}


// 0c
int
cl_tlcs::rcf()
{
  reg.f&= ~(FLAG_C|FLAG_X|FLAG_N|FLAG_H);
  return resGO;
}


// ff
int
cl_tlcs::swi()
{
  t_addr iPC= PC-1;
  reg.f&= ~FLAG_I;
  exec_intr(iPC, 0x0010, PC);
  exec_push(iPC, reg.af);
  PC= 0x0010;
  return resGO;
}


/* End of tlcs.src/cpu_others.cc */
