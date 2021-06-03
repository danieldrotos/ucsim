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
  vc.rd++;
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
  vc.rd++;
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
  vc.rd++;
  tick(1);
  return resGO;
}

/*
void MathsOpcodeHandlerContainer::adc(Machine& machine, uint8_t value) {
        auto& cpu = machine.get_cpu();
        auto init_a = cpu.get_a().get_value();

        // allow for operation to breach 8 bits
        uint16_t result = value + init_a;
        if (cpu.get_ps().is_carry_set())
            result += 1;

        cpu.get_a().set_value(result); // will chop off bit 8 if set
        auto a = cpu.get_a().get_value();

        // 'a' may be 0 if the result wasn't 0, i.e. the cary bit is set
        set_zero_and_neg_flags(cpu.get_ps(), a);
        cpu.get_ps().set_carry(result > 0xFF);
        cpu.get_ps().set_overflow(
                (value < 0x7F && init_a < 0x7F && a > 0x7F) ||
                (value > 0x7F && init_a > 0x7F && a < 0x7F));
    }
*/
/*
#define adc_x(len) 	\
		register uchar sa,sx=a;\
		if(!dez) {\
		  sa=cpu.a;\
		  a+=cpu.a+carry1();\
		  overfl=((a^sa)&0x80)&&!((sa^sx)&0x80);\
		  setc(a);\
		  a&=0xff;\
		  setnz(a);\
		} else {\
		  register scnt al,ah;\
		  al=(cpu.a&0x0f)+(a&0x0f)+carry1();\
		  ah=(cpu.a>>4)+(a>>4)+al>15;\
		  if(al>9) al+=6;\
		  zero=!((cpu.a+a+carry1())&0xff);\
		  neg=ah&8;\
		  overfl=(((ah<<4)^cpu.a) & 128) && !((cpu.a^a)&128);\
		  if(ah>9) ah+=6;\
		  carry=ah>15;\
		  a=((ah<<4)|(al&0x0f))&0xff; \
		}\
		cpu.a=a;\
		cpu.pc+=len
*/

/* End of mcs6502.src/ialu.cc */
