/*
 * Simulator of microcontrollers (wd.cc)
 *
 * Copyright (C) 2026 Drotos Daniel
 * 
 * To contact author send email to dr.dkdb@gmail.com
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

#include "wdcl.h"


cl_wd::cl_wd(class cl_uc *auc, t_addr the_addr, const char *aname):
  cl_hw(auc, HW_WDT, 0, aname)
{
  addr= the_addr;
  set_name(aname);
  zero= 0;
  ctrl= 0;
  cntl= 0;
  cnth= 0;
}


/*
	// Watchdog
	localparam WATCHDOG_CONFIG_ADDR = WATCHDOGADDRBASE + 0;
	localparam WATCHDOG_COUNTER_ADDR = WATCHDOGADDRBASE + 2;

	logic [7:0] watchdog_config_dread;
	logic [15:0] watchdog_counter_dread;
	
		WATCHDOG_CONFIG_ADDR / 2:
			read_data_even = watchdog_config_dread;
		WATCHDOG_COUNTER_ADDR / 2:
			read_data_even = watchdog_counter_dread[7:0];
		(WATCHDOG_COUNTER_ADDR + 1) / 2:
			read_data_odd = watchdog_counter_dread[15:8];
 */
int
cl_wd::init(void)
{
  cl_hw::init();
  zero= register_cell(uc->rom, 0);
  ctrl= register_cell(uc->rom, addr);
  cntl= register_cell(uc->rom, addr+2);
  cnth= register_cell(uc->rom, addr+3);
  ctrl->W(0);
  return 0;
}


void
cl_wd::reset(void)
{
  ctrl->W(0);
  pre= 0;
  cnt= 0;
}


t_mem
cl_wd::read(class cl_memory_cell *cell)
{
  if (cell == cntl)
    {
      return cell->set(cnt&0xff);
    }
  else if (cell == cnth)
    {
      return cell->set( (cnt>>8)&0xff );
    }
  conf(cell, NULL);
  return cell->get();
}

void
cl_wd::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;
  if (on && (cell == zero))
    {
      do_reset(8);
      *val= cell->get();
    }
  else if (cell == ctrl)
    {
      u8_t old= ctrl->R();
      if (((old & 1) == 0) && (*val & 1))
	{
	  pre= 0;
	  cnt= 0;
	}
    }
  else if (cntl && (cell == cntl))
    {
      cnt&= 0xff00;
      cnt|= (*val & 0xff);
    }
  else if (cnth && (cell == cnth))
    {
      cnt&= 0x00ff;
      cnt|= ((*val & 0xff) << 8);
    }
  cell->set(*val);
}


int
cl_wd::tick(int cycles)
{
  if (ctrl->R() & 1)
    {
      pre+= cycles;
      while (pre > 16)
	{
	  cnt++;
	  pre-= 16;
	  check();
	}
    }
  return 0;
}


void
cl_wd::check(void)
{
  if (cnt == 0xffff)
    {
      do_reset(2);
    }
}


void
cl_wd::do_reset(u8_t reason)
{
  u8_t old= ctrl->R();
  uc->reset();
  ctrl->W((old & 1) | reason);
}


void
cl_wd::print_info(class cl_console_base *con)
{
  u8_t v= ctrl->R();
  con->dd_printf("Simulation of %s[%d] is turned %s\n", get_name(), id,
		 on?"ON":"OFF");
  con->dd_printf("Addr= 0x%04x\n", AU(addr));
  con->dd_printf("Ctrl= 0x%02x ", v);
  con->dd_printf("Active=%d ", (v&1)?1:0);
  con->dd_printf("Dog=%d ", (v&2)?1:0);
  con->dd_printf("Trap=%d ", (v&4)?1:0);
  con->dd_printf("Null=%d\n", (v&8)?1:0);
  con->dd_printf("Pre= %u             \n", pre);
  con->dd_printf("Cnt= %u             \n", cnt);
}


/* End of f8.src/wd.cc */
