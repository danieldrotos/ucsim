/*
 * Simulator of microcontrollers (misc16.cc)
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

#include "misc16cl.h"


/*

  MISC16 CPU design by:
  - Juergen Pintaske
  - Harry Siebert
  - Bernd Paysan

  Toolset is by Steve Teal, at https://github.com/Steve-Teal/eforth-misc16
  
+---------+-------------+------------------+
| Address | Source      | Destination      |
+---------+-------------+------------------+
| 0x0000  | PC          | PC               |   
| 0x0001  | PC+2        | PC if A < 0      |
| 0x0002  | PC+4        | PC if A = 0      |
| 0x0003  | PC+6        | -                |
| 0x0004  | -           | PC if C = 1      |
| 0x0005  | -           | -                |
| 0x0006  | -           | -                |
| 0x0007  | [A]         | [A]              |
| 0x0008  | A           | A                |
| 0x0009  | -           | A = A - source   |
| 0x000A  | -           | -                |
| 0x000B  | -           | A = A + source   |
| 0x000C  | -           | A = A xor source |
| 0x000D  | -           | A = A or source  |
| 0x000E  | -           | A = A and source |
| 0x000F  | -           | A = source >> 1  | 
+---------+-------------+------------------+
*/

cl_misc16::cl_misc16(class cl_sim *asim):
  cl_oisc(asim)
{
}

void
cl_misc16::reset(void)
{
  cl_oisc::reset();
  PC= 0x10;
}

u16_t
cl_misc16::sub(u16_t a, u16_t b)
{
  u16_t s;

  b= ~b;
  s= a+b+1;
  rC= (((a&b)|((a|b)&~s))&0x8000)?1:0;
  return s;
}

u16_t
cl_misc16::add(u16_t a, u16_t b)
{
  u16_t s;
  s= a+b;
  rC= (((a&b)|((a|b)&~s))&0x8000)?1:0;
  return s;
}

u16_t
cl_misc16::shift(u16_t a)
{
  u16_t s;
  s= a>>1;
  if (rC) s|= 0x8000;
  rC= a&1;
  return s;
}  

void
cl_misc16::init_alu(void)
{
  id_str= "MISC16";
  reg_cell_var(&cC, &rC, "C", "Carry flag");
  cC.append_operator(new cl_cy_op(&cC));
  class cl_memory_cell *c;
  c= rom->get_cell(0); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(1); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(2); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(3); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(4); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(7); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(8); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(9); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(11); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(12); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(13); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(14); c->append_operator(new cl_op_pass(c, this));
  c= rom->get_cell(15); c->append_operator(new cl_op_pass(c, this));
}

void
cl_misc16::print_regs(class cl_console_base *con)
{
  print_acc(con);
  con->dd_printf("CY= %d", rC);
  con->dd_printf("\n");
  print_disass(PC, con);
}

u16_t
cl_misc16::read(u16_t addr)
{
  switch (addr)
    {
    case 0: return PC;
    case 1: return (PC+2)&0xffff;
    case 2: return (PC+4)&0xffff;
    case 3: return (PC+6)&0xffff;
    case 7: return rom->read(rA);
    case 8: return rA;
    }
  return rom->get(addr);
}

u16_t
cl_misc16::write(u16_t addr, u16_t val)
{
  switch (addr)
    {
    case 0: PC= val; break;
    case 1: if ((i16_t)rA < 0) PC= val; break;
    case 2: if (!rA) PC= val; break;
    case 4: if (rC) PC= val; break;
    case 7: if (rA != 7) rom->write(rA, val); break;
    case 8: cA.W(val); break;
    case 9: cA.W(val= sub(rA, val)); break;
    case 11: cA.W(val= add(rA, val)); break;
    case 12: cA.W(val= rA^val); break;
    case 13: cA.W(val= rA|val); break;
    case 14: cA.W(val= rA&val); break;
    case 15: cA.W(val= shift(rA)); break;
    }
  return val;
}


/* End of oisc.src/misc16.cc */
