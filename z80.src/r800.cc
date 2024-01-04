/*
 * Simulator of microcontrollers (r800.cc)
 *
 * Copyright (C) 1999,2023 Drotos Daniel, Talker Bt.
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

#include "glob.h"

#include "r800cl.h"


cl_r800::cl_r800(struct cpu_entry *Itype, class cl_sim *asim):
  cl_ez80(Itype, asim)
{
}

int
cl_r800::init(void)
{
  return cl_ez80::init();
  // FIXME
  ttab_ed[0xc1]= 15;
  ttab_ed[0xc9]= 15;
  ttab_ed[0xd1]= 15;
  ttab_ed[0xd9]= 15;
  ttab_ed[0xc3]= 37;
}

const char *
cl_r800::id_string(void)
{
  return ("R800");
}


int
cl_r800::inst_ed_(t_mem code)
{
  switch (code)
    {
    // Z280/R800 multu
    case 0xc1:
    case 0xc9:
    case 0xd1:
    case 0xd9:
      {
	unsigned int result = (unsigned int)(regs.raf.A) * reg_g_read((code >> 3) & 0x07);
	regs.HL = result;
	regs.raf.F &= ~(BIT_S | BIT_Z | BIT_P | BIT_C);
	if (!result)
	  regs.raf.F |= BIT_Z;
	if (result >= 0x100)
	  regs.raf.F |= BIT_C;
	//tick (14);
	return(resGO);
      }
      

    // Z280/R800 multuw
    case 0xc3: // multuw hl, bc
      {
	unsigned long result = (unsigned long)(regs.HL) *  (unsigned long)(regs.BC);
	regs.HL = (result >> 0) & 0xff;
	regs.DE = (result >> 16) & 0xff;
	regs.raf.F &= ~(BIT_S | BIT_Z | BIT_P | BIT_C);
	if (!result)
	  regs.raf.F |= BIT_Z;
	if (regs.DE)
	  regs.raf.F |= BIT_C;
	//tick (36);
	return(resGO);
      }

    default:
      return cl_ez80::inst_ed_(code);
    }
  
  return resINV_INST;
}


/* End of z80.src/r800.cc */
