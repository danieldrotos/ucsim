/*
 * Simulator of microcontrollers (stm8.src/port.cc)
 *
 * Copyright (C) 2017,17 Drotos Daniel, Talker Bt.
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

#include "portcl.h"

cl_port::cl_port(class cl_uc *auc, t_addr abase/*, int aid*/, const char *aname):
	cl_hw(auc, HW_PORT, /*aid*/0, aname)
{
  base = abase;
  set_name(aname);
}

int
cl_port::init(void)
{
  cl_hw::init();
  // ODR
  cell_p= register_cell(uc->rom, base + 0);
  // IDR
  cell_in= register_cell(uc->rom, base + 1);
  // DDR: 0=input, 1=output
  cell_dir= register_cell(uc->rom, base + 2);
  return 0;
}

void
cl_port::print_info(class cl_console_base *con)
{
  int m;
  t_mem o= cell_p->get(),
    i= cell_in->get(),
    d= cell_dir->get();
  con->dd_printf("%s at 0x%04x\n", get_name(), base);
  con->dd_printf("dir: 0x%02x ", d);
  for (m= 1; m <= 0xff; m<<= 1)
    con->dd_printf("%c", (d & m)?'O':'I');
  con->dd_printf("\n");
  con->dd_printf("out: 0x%02x ", o);
  for (m= 1; m <= 0xff; m<<= 1)
    {
      if (d & m)
	con->dd_printf("%c", (o & m)?'1':'0');
      else
	con->dd_printf("-");
    }
  con->dd_printf("\n");
  con->dd_printf("in : 0x%02x ", i);
  for (m= 1; m <= 0xff; m<<= 1)
    {
      if (!(d & m))
	con->dd_printf("%c", (i & m)?'1':'0');
      else
	con->dd_printf("-");
    }
  con->dd_printf("\n");
}


/* End of stm8.src/port.cc */
