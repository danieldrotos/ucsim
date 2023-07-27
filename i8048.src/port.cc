/*
 * Simulator of microcontrollers (port.cc)
 *
 * Copyright (C) 1999,99 Drotos Daniel, Talker Bt.
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

#include <ctype.h>

#include "portcl.h"


cl_qport::cl_qport(class cl_uc *auc, int aid,
		   class cl_address_space *apas, t_addr aaddr,
		   enum port_widths awidth):
  cl_hw(auc, HW_PORT, aid, "port")
{
  port_as= apas;
  addr= aaddr;
  width= awidth;
  switch (width)
    {
    case port_4bit: mask= 0x0f; break;
    case port_8bit: mask= 0xff; break;
    }
}

int
cl_qport::init(void)
{
  cl_hw::init();
  pcell= register_cell(port_as, addr);
  cfg_set(port_pin, 0xff & mask);
  return 0;
}

const char *
cl_qport::cfg_help(t_addr addr)
{
  switch (addr)
    {
    case port_on: return "Turn/get on/off state (bool, RW)";
    case port_pin: return "Outside value of port pins (int, RW)";
    case port_value: return "Value of the port (int, RO)";
    case port_odr: return "Value of output register (int, RW)";
    }
  return "Not used";
}

t_mem
cl_qport::read(class cl_memory_cell *cell)
{
  if (cell == pcell)
    return(cell->get() & cfg_get(port_pin));
  conf(cell, NULL);
  return cell->get();
}

void
cl_qport::write(class cl_memory_cell *cell, t_mem *val)
{
  conf(cell, val);
}

t_mem
cl_qport::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  switch ((enum port_cfg)addr)
    {
    case port_on: // turn this HW on/off
      if (val)
	{
	  on= (*val)?1:0;
	}
      cell->set(on?1:0);
      break;
    case port_pin: // get/set PINS
      if (val)
	cell->set(*val & mask);
      break;
    case port_value: // odr & pins (RO)
      cell->set(pcell->get() & cfg_get(port_pin) & mask);
      break;
    case port_odr: // copy value into memory cell
      if (val)
	pcell->write(*val & mask);
      cell->set(pcell->get());
      break;
    case port_nuof:
      break;
    }
  return cell->get();
}

void
cl_qport::print_info(class cl_console_base *con)
{
  uchar data;

  con->dd_printf("%s[%d]\n", id_string, id);
  data= pcell->get();
  con->dd_printf("P%d    ", id);
  con->print_bin(data, 8);
  con->dd_printf(" 0x%02x %3d %c (Value in SFR register)\n",
		 data, data, isprint(data)?data:'.');

  data= cfg_get(port_pin);
  con->dd_printf("Pin%d  ", id);
  con->print_bin(data, 8);
  con->dd_printf(" 0x%02x %3d %c (Output of outside circuits)\n",
		 data, data, isprint(data)?data:'.');

  data= pcell->read();
  con->dd_printf("Port%d ", id);
  con->print_bin(data, 8);
  con->dd_printf(" 0x%02x %3d %c (Value on the port pins)\n",
		 data, data, isprint(data)?data:'.');
  //print_cfg_info(con);
}


/*
 * P2 port
 */

cl_p2::cl_p2(class cl_uc *auc, int aid,
	     class cl_address_space *apas, t_addr aaddr,
	     enum port_widths awidth):
  cl_qport(auc, aid, apas, aaddr, awidth)
{
}


/* End of i8048.src/port.cc */
