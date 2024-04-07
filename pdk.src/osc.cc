/*
 * Simulator of microcontrollers (osc.cc)
 *
 * Copyright (C) 2024,2024 Drotos Daniel, Talker Bt.
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

#include "osccl.h"


cl_osc::cl_osc(class cl_uc *auc, const char *aname):
  cl_hw(auc, HW_TIMER, 0, aname)
{
}

int
cl_osc::init(void)
{
  cl_hw::init();
  return 0;
}

void
cl_osc::reset(void)
{
  
}

void
cl_osc::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;
  if (cell == mod)
    {
    }
  cell->set(*val);
}

int
cl_osc::tick(int cycles)
{
  return 0;
}

void
cl_osc::print_info(class cl_console_base *con)
{
  con->dd_printf("\n");
}


/* End of pdk.src/osc.cc */
