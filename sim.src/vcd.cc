/*
 * Simulator of microcontrollers (sim.src/vcd.cc)
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

// prj

// sim
#include "argcl.h"

// local
#include "vcdcl.h"


cl_vcd::cl_vcd(class cl_uc *auc, int aid, chars aid_string):
       cl_hw(auc, HW_DUMMY, aid, aid_string)
{
  locs= new cl_list(2, 2, "vcd_locs");
  started= false;
  paused= false;
  fout= 0;
}


void
cl_vcd::set_cmd(class cl_cmdline *cmdline, class cl_console_base *con)
{
  class cl_cmd_arg *params[3]= {
    cmdline->param(0),
    cmdline->param(1),
    cmdline->param(2)
  };

  if (cmdline->syntax_match(uc, MEMORY ADDRESS))
    {
      class cl_memory *mem= params[0]->value.memory.memory;
      t_addr a= params[1]->value.address;
      if (!mem->is_address_space())
	{
	  con->dd_printf("%s is not an address space\n");
	  return;
	}
      if (!mem->valid_address(a))
	{
	  con->dd_printf("Address must be between 0x%x and 0x%x\n",
			 mem->lowest_valid_address(),
			 mem->highest_valid_address());
	  return;
	}
    }
  else if (cmdline->syntax_match(uc, STRING MEMORY ADDRESS))
    {}
  else if (cmdline->syntax_match(uc, STRING NUMBER))
    {}
  else if (cmdline->syntax_match(uc, STRING STRING))
    {}
  else if (cmdline->syntax_match(uc, STRING))
    {
      char *p1= params[0]->value.string.string;
      char *p2= params[1]->value.string.string;
    }
  else
    {
      con->dd_printf("set hardware vcd[id] memory address\n");
      con->dd_printf("set hardware vcd[id] del[ete] memory address\n");
      con->dd_printf("set hardware vcd[id] fout|file \"vcd_file_name\"|gtkwave\n");
      con->dd_printf("set hardware vcd[id] mod[ule] module_name\n");
      con->dd_printf("set hardware vcd[id] start\n");
      con->dd_printf("set hardware vcd[id] pause\n");
      con->dd_printf("set hardware vcd[id] [re]start\n");
      con->dd_printf("set hardware vcd[id] stop\n");
      con->dd_printf("set hardware vcd[id] new id\n");
    }
}

void
cl_vcd::print_info(class cl_console_base *con)
{
  
}


/* End of sim.src/vcd.cc */
