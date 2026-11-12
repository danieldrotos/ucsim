/*
 * Simulator of microcontrollers (timer.cc)
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

#include "timercl.h"


cl_timer::cl_timer(class cl_uc *auc, t_addr the_addr, const char *aname):
  cl_hw(auc, HW_TIMER, 0, aname)
{
  addr= the_addr;
  set_name(aname);
  divby= 1;
  in_clks= 0;
}

/*
  // Bug in compare address?? Should it be 6?
  
  // Timer 0
  localparam TIMER0_CONFIG_ADDR = TIMER0ADDRBASE + 0;
  localparam TIMER0_COUNTER_ADDR = TIMER0ADDRBASE + 2;
  localparam TIMER0_RELOAD_ADDR = TIMER0ADDRBASE + 4;
  localparam TIMER0_COMPARE_ADDR = TIMER0ADDRBASE + 5;
	
  logic [7:0] timer0_config_dread;
  logic [15:0] timer0_counter_dread, timer0_reload_dread, timer0_compare_dread;
	
  TIMER0_CONFIG_ADDR / 2:
  read_data_even = timer0_config_dread;
  TIMER0_COUNTER_ADDR / 2:
  read_data_even = timer0_counter_dread[7:0];
  TIMER0_RELOAD_ADDR / 2:
  read_data_even = timer0_reload_dread[7:0];
  TIMER0_COMPARE_ADDR / 2:
  read_data_even = timer0_compare_dread[7:0];
  (TIMER0_COUNTER_ADDR + 1) / 2:
  read_data_odd = timer0_counter_dread[15:8];
  (TIMER0_RELOAD_ADDR + 1) / 2:
  read_data_odd = timer0_reload_dread[15:8];
  (TIMER0_COMPARE_ADDR + 1) / 2:
  read_data_odd = timer0_compare_dread[15:8];
 */

int
cl_timer::init(void)
{
  cl_hw::init();
  
  cfg = register_cell(uc->rom, 0);
  cntl= register_cell(uc->rom, 2);
  cnth= register_cell(uc->rom, 3);
  return 0;
}


void
cl_timer::reset(void)
{
}


t_mem
cl_timer::read(class cl_memory_cell *cell)
{
  if (0)
    ;
  else if (cell == cntl)
    cell->set(cnt);
  else if(cell == cnth)
    cell->set(cnt>>8);
  
  conf(cell, NULL);
  return cell->get();
}

void
cl_timer::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;

  if (0)
    ;
  else if (cell == cfg)
    {
      switch ((*val >> 4) & 3)
	{
	case 0: divby=  1; break;
	case 1: divby=  4; break;
	case 2: divby= 16; break;
	case 3: divby= 64; break;
	}
    }
  else if (cell == cntl)
    {
      cnt&= 0xff00;
      cnt|= (*val & 0xff);
    }
  else if (cell == cnth)
    {
      cnt&= 0x00ff;
      cnt|= ( (*val & 0xff) << 8 );
    }
  
  cell->set(*val);
}


int
cl_timer::tick(int cycles)
{
  u16_t cmp= uc->rom->read(addr+6)+256*(uc->rom->read(addr+6+1));
  if ((cfg->R() & 0x0f) == 1)
    {
      in_clks+= cycles;
      int c= in_clks / divby;
      in_clks%= divby;
      while (c--)
	{
	  cnt++;
	  if (cnt == cmp)
	    {
	      u8_t en= uc->rom->read(0x10);
	      if (en & 2)
		uc->rom->write( 0x12, uc->rom->read(0x11) | 2 );	      
	    }
	  if (cnt == 0)
	    {
	      cnt= uc->rom->read(addr+4)+256*(uc->rom->read(addr+4+1));
	      u8_t en= uc->rom->read(0x10);
	      if (en & 1)
		uc->rom->write( 0x12, uc->rom->read(0x11) | 1 );
	    }
	}
    }
  return 0;
}

void
cl_timer::print_info(class cl_console_base *con)
{
  u8_t v= cfg->R();
  con->dd_printf("Simulation of %s[%d] is turned %s\n", get_name(), id,
		 on?"ON":"OFF");
  con->dd_printf("Addr= 0x%04x\n", AU(addr));
  con->dd_printf("CFG= ");
  con->print_bin(cfg->read(), 8);
  con->dd_printf(" ARR= 0x%04x", uc->rom->read(addr+4)+256*(uc->rom->read(addr+4+1)));
  con->dd_printf(" CMP= 0x%04x", uc->rom->read(addr+6)+256*(uc->rom->read(addr+6+1)));
  con->dd_printf(" CNT= 0x%04x,%5d", cnt, cnt);
  con->dd_printf("\n");
  con->dd_printf("inclks=%d divby=%d", in_clks, divby);
  con->dd_printf("\n");
}


/* End of f8.src/timer.cc */
