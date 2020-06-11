/*
 * Simulator of microcontrollers (port.cc)
 *
 * Copyright (C) 2020,20 Drotos Daniel, Talker Bt.
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

cl_port::cl_port(class cl_uc *auc, t_addr the_addr, const char *aname):
  cl_hw(auc, HW_PORT, 0, aname)
{
  addr= the_addr;
  set_name(aname);
}

int
cl_port::init(void)
{
  cl_hw::init();
  dr= register_cell(uc->rom, addr);

  cl_var *v;
  v= new cl_var("dr", uc->rom, addr,
		"Data register");
  v->init();
  uc->vars->add(v);

  return 0;
}

void
cl_port::reset(void)
{
}

void
cl_port::write(class cl_memory_cell *cell, t_mem *val)
{
  if (cell == dr)
    {
      cell->set(*val);
    }
}

void
cl_port::print_info(class cl_console_base *con)
{
  u32_t m;
  t_mem d= dr->get();
  con->dd_printf("%s at %04x\n", get_name(), addr);
  for (m= 0x80000000; m; m>>= 1)
    {
      //if (d & m)
	con->dd_printf("%c", (d & m)?'1':'0');
	//else 	con->dd_printf("-");
    }
  con->dd_printf("\n");
  print_cfg_info(con);
}


/* End of p1516.src/port.cc */

