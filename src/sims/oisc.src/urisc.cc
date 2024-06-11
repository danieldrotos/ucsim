/*
 * Simulator of microcontrollers (urisc.cc)
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

#include "urisccl.h"

cl_urisc::cl_urisc(class cl_sim *asim):
  cl_oisc(asim)
{
}
  
void
cl_urisc::init_alu(void)
{
  id_str= "Ultimate_RISC";
  reg_cell_var(&cF, &rF, "F", "Flags");
}

void
cl_urisc::print_regs(class cl_console_base *con)
{
  print_acc(con);
  con->dd_printf("   ONCZ\n");
  con->dd_printf("F= ");
  con->print_bin(rF, 4);
  con->dd_printf(" 0x%02x", rF);
  con->dd_printf("\n");
  print_disass(PC, con);
}

u16_t
cl_urisc::read(u16_t addr)
{
  return rom->get(addr);
}

u16_t
cl_urisc::write(u16_t addr, u16_t val)
{
  return val;
}


/* End of oisc.src/urisc.cc */
