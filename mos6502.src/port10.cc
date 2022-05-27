/*
 * Simulator of microcontrollers (port10.cc)
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
/*@1@*/

#include "port10cl.h"


cl_port10::cl_port10(class cl_uc *auc, const char *aname):
  cl_hw(auc, HW_PORT, 0, aname)
{
}

int
cl_port10::init(void)
{
  cl_hw::init();
  // 1= output, 0= input
  cddr= (class cl_cell8 *)register_cell(uc->rom, 0);
  cdr= (class cl_cell8 *)register_cell(uc->rom, 1);
  cpin= (class cl_cell8 *)cfg->get_cell(port10_pin);
  return 0;
}

void
cl_port10::reset(void)
{
  cl_hw::reset();
  cddr->W(0);
}

t_mem
cl_port10::read(class cl_memory_cell *cell)
{
  if (conf(cell, NULL))
    return cell->get();
  if (cell == cddr)
    return cddr->R();
  if (cell == cdr)
    {
      
    }
  return cell->R();
}

t_mem
cl_port10::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  switch (addr)
    {
    case port10_on: break;
    case port10_pin: break;
    }
  return cell->get();
}

void
cl_port10::print_info(class cl_console_base *con)
{
  con->dd_printf("%s[%d] %s\n", id_string, id, on?"ON":"OFF");
  con->dd_printf("Dir : 0x%02x ", cddr->get());
  con->dd_printf("\n");
  con->dd_printf("Pin : 0x%02x ", cpin->get());
  con->dd_printf("\n");
  con->dd_printf("Data: 0x%02x ", cdr->get());
  con->dd_printf("\n");
}


/* End of mos6502.src/port10.cc */
