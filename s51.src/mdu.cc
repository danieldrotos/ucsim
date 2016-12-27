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

#include "mducl.h"


cl_mdu517::cl_mdu517(class cl_uc *auc, int aid):
  cl_hw(auc, HW_CALC, aid, "mdu")
{
}


t_mem
cl_mdu517::read(class cl_memory_cell *cell)
{
  conf(cell, NULL);
  return cell->get();
}

void
cl_mdu517::write(class cl_memory_cell *cell, t_mem *val)
{
  conf(cell, val);    
}

t_mem
cl_mdu517::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  return cell->get();
}


/* End of s51.src/mdu.cc */
