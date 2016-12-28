/*
 * Simulator of microcontrollers (s51.src/mdu.cc)
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

#include "uc51cl.h"

#include "mducl.h"


cl_mdu517::cl_mdu517(class cl_uc *auc, int aid):
  cl_hw(auc, HW_CALC, aid, "mdu")
{
}

int
cl_mdu517::init(void)
{
  int i;
  class cl_51core *u= (cl_51core*)uc;
  
  //arcon= register_cell(u->sfr, 0xef);
  for (i= 0; i<7; i++)
    {
      regs[i]= register_cell(u->sfr, 0xe9+i);
      v[i]= regs[i]->get();
    }
  nuof_writes= 0;
  writes= 0xffffffffffff;
  calcing= 0;
  return 0;
}

t_mem
cl_mdu517::read(class cl_memory_cell *cell)
{
  if (conf(cell, NULL))
    return cell->get();

  return cell->get();
}

void
cl_mdu517::write(class cl_memory_cell *cell, t_mem *val)
{
  cl_address_space *sfr= ((cl_51core*)uc)->sfr;
  t_addr a;
  u8_t ar= regs[6]->get();
  
  if (conf(cell, val))
    return;
  if (sfr->is_owned(cell, &a))
    {
      a-= 0xe9;
      if ((a < 0) ||
	  (a > 5))
	return;
      if (calcing)
	{
	  regs[6]->set(ar | 0x80);
	  return;
	}
      if (a == 0)
	{
	  writes= 0xffffffffffff;
	  nuof_writes= 0;
	}
      if (nuof_writes > 5)
	{
	  regs[6]->set(ar | 0x80);
	  return;
	}
      writes&= (a << (nuof_writes*8));
      v[nuof_writes]= *val;
      nuof_writes++;

      switch (writes)
	{
	  //   665544332211
	case 0x050403020100:
	  {
	    // 32/16
	    u32_t dend= v[3]*256*256*256 + v[2]*256*256 + v[1]*256 + v[0];
	    u16_t dor= v[5]*256 + v[4];
	    u32_t quo= 0;
	    u16_t rem= 0;
	    if (dor == 0)
	      regs[6]->set(ar | 0x40);
	    else
	      {
		quo= dend / dor;
		rem= dend % dor;
		regs[6]->set(ar & ~0x40);
	      }
	    regs[0]->set(quo & 0xff);
	    regs[1]->set((quo>>8) & 0xff);
	    regs[2]->set((quo>>16) & 0xff);
	    regs[3]->set((quo>>24) & 0xff);
	    regs[4]->set(rem & 0xff);
	    regs[5]->set((rem>>8) & 0xff);
	    calcing= 6;
	    break;
	  }
	  //   665544332211
	case 0xffff05040100:
	  // 16/16
	  break;
	  //   665544332211
	case 0xffff05010400:
	  // 16*16
	  break;
	  //   665544332211
	case 0xff0603020100:
	  // norm, shift
	  break;
	default:
	  if (nuof_writes > 5)
	    regs[6]->set(ar | 0x80);
	  break;
	}
    }
}

t_mem
cl_mdu517::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  return cell->get();
}


/* End of s51.src/mdu.cc */
