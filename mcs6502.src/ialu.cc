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

#include "mcs6502cl.h"


int
cl_mcs6502::DEY(t_mem code)
{
  cY.W(rY-1);
  if (rY)
    rF&= ~flagZ;
  else
    rF|= flagZ;
  if (rY & 0x80)
    rF|= flagS;
  else
    rF&= ~flagS;
  cF.W(rF);
  tick(1);
  return resGO;
}

int
cl_mcs6502::INY(t_mem code)
{
  cY.W(rY+1);
  if (rY)
    rF&= ~flagZ;
  else
    rF|= flagZ;
  if (rY & 0x80)
    rF|= flagS;
  else
    rF&= ~flagS;
  cF.W(rF);
  tick(1);
  return resGO;
}

int
cl_mcs6502::INX(t_mem code)
{
  cX.W(rX+1);
  if (rX)
    rF&= ~flagZ;
  else
    rF|= flagZ;
  if (rX & 0x80)
    rF|= flagS;
  else
    rF&= ~flagS;
  cF.W(rF);
  tick(1);
  return resGO;
}

int
cl_mcs6502::DEX(t_mem code)
{
  cX.W(rX-1);
  if (rX)
    rF&= ~flagZ;
  else
    rF|= flagZ;
  if (rX & 0x80)
    rF|= flagS;
  else
    rF&= ~flagS;
  cF.W(rF);
  tick(1);
  return resGO;
}

int
cl_mcs6502::ora(class cl_cell8 &op)
{
  u8_t f= rF & ~(flagZ|flagS);
  cA.W(rA | op.R());
  if (!rA) f|= flagZ;
  if (rA&0x80) f|= flagS;
  cF.W(f);
  tick(1);
  return resGO;
}

int
cl_mcs6502::And(class cl_cell8 &op)
{
  u8_t f= rF & ~(flagZ|flagS);
  cA.W(rA & op.R());
  if (!rA) f|= flagZ;
  if (rA&0x80) f|= flagS;
  cF.W(f);
  tick(1);
  return resGO;
}

int
cl_mcs6502::eor(class cl_cell8 &op)
{
  u8_t f= rF & ~(flagZ|flagS);
  cA.W(rA ^ op.R());
  if (!rA) f|= flagZ;
  if (rA&0x80) f|= flagS;
  cF.W(f);
  tick(1);
  return resGO;
}

int
cl_mcs6502::adc(class cl_cell8 &op)
{
  u8_t ah, al, s= op.R(), f, sA= rA;
  u16_t res;
  u8_t C= (rF&flagC)?1:0;

  f= rF & ~(flagZ|flagC|flagN|flagV);

  if (rF & flagD)
    {
      al= (rA & 0xf) + (s & 0xf) + C;
      ah= (rA >> 4) + (s >> 4) + ((al>15)?1:0);
      if (al > 9) al+= 6;
      if ((rA + s + C) & 0xff) f|= flagZ;

      if (ah & 8) f|= flagN;
      if ( (((ah << 4) ^ rA) & 0x80) && !((rA ^ s) & 0x80))  f|= flagV;

      if (ah > 9) ah+= 6;

      if (ah > 15) f|= flagC;

      cA.W((ah << 4) | (al & 0xf));
    }
  else
    {
      res= rA + s + C;
      cA.W(res);
      if (!rA) f|= flagZ;
      if (rA & 0x80) f|= flagN;
      if (res > 255) f|= flagC;
      if (((res^sA)&0x80) && !((sA^s)&0x80)) f|= flagV;
    }
  cF.W(f);
  
  tick(1);
  return resGO;
}


/* End of mcs6502.src/ialu.cc */
