/*
 * Simulator of microcontrollers (sim.cc)
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

#include "ddconfig.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "i_string.h"

// prj
#include "globals.h"
#include "utils.h"

// cmd
#include "cmdsetcl.h"
#include "cmdguicl.h"

// local, sim.src
#include "simcl.h"
#include "appcl.h"


/*
 * Simulator
 */

cl_sim::cl_sim(class cl_app *the_app):
  cl_base()
{
  app= the_app;
  uc= 0;
  state= SIM_NONE;
  //arguments= new cl_list(2, 2);
  //accept_args= more_args?strdup(more_args):0;
  gui= new cl_gui(this);
}

int
cl_sim::init(void)
{
  cl_base::init();
  build_cmdset(app->get_commander()->cmdset);
  if (!(uc= mk_controller()))
    return(1);
  uc->init();
  return(0);
}

cl_sim::~cl_sim(void)
{
  if (uc)
    delete uc;
}

class cl_uc *
cl_sim::mk_controller(void)
{
  return(new cl_uc(this));
}


int
cl_sim::step(void)
{
  if (state & SIM_GO)
    {
      uc->do_inst(1);
      steps_done++;
      if ((steps_todo > 0) &&
	  (steps_done >= steps_todo))
	stop(resSTEP);
    }
  return(0);
}

/*int
cl_sim::do_cmd(char *cmdstr, class cl_console *console)
{
  class cl_cmdline *cmdline;
  class cl_cmd *cm;
  int retval= 0;

  cmdline= new cl_cmdline(cmdstr, console);
  cmdline->init();
  cm= cmd->cmdset->get_cmd(cmdline);
  if (cm)
    retval= cm->work(cmdline, console);
  delete cmdline;
  if (cm)
    return(retval);
  return(console->interpret(cmdstr));
}*/

void
cl_sim::start(class cl_console_base *con, unsigned long steps_to_do)
{
  state|= SIM_GO;
  if (con)
    {
      con->flags|= CONS_FROZEN;
      app->get_commander()->frozen_console= con;
      app->get_commander()->update_active();
    }
  start_at= dnow();
  if (uc)
    start_tick= uc->ticks->ticks;
  steps_done= 0;
  steps_todo= steps_to_do;
}

void
cl_sim::stop(int reason)
{
  class cl_commander_base *cmd= app->get_commander();

  state&= ~SIM_GO;
  if (cmd->frozen_console)
    {
      if (reason == resUSER &&
	  cmd->frozen_console->input_avail())
	cmd->frozen_console->read_line();
      cmd->frozen_console->dd_printf("Stop at 0x%06x: (%d) ", uc->PC, reason);
      switch (reason)
	{
	case resHALT:
	  cmd->frozen_console->dd_printf("Halted\n");
	  break;
	case resINV_ADDR:
	  cmd->frozen_console->dd_printf("Invalid address\n");
	  break;
	case resSTACK_OV:
	  cmd->frozen_console->dd_printf("Stack overflow\n");
	  break;
	case resBREAKPOINT:
	  cmd->frozen_console->dd_printf("Breakpoint\n");
	  uc->print_regs(cmd->frozen_console);
	  break;
	case resINTERRUPT:
	  cmd->frozen_console->dd_printf("Interrupt\n");
	  break;
	case resWDTRESET:
	  cmd->frozen_console->dd_printf("Watchdog reset\n");
	  break;
	case resUSER:
	  cmd->frozen_console->dd_printf("User stopped\n");
	  break;
	case resINV_INST:
	  {
	    cmd->frozen_console->dd_printf("Invalid instruction");
	    if (uc->rom)
	      cmd->frozen_console->dd_printf(" 0x%04x\n",
					     uc->rom->get(uc->PC));
	  }
         break;
	case resSTEP:
	  uc->print_regs(cmd->frozen_console);
	  break;
	case resERROR:
	  // uc::check_error prints error messages...
	  break;
	default:
	  cmd->frozen_console->dd_printf("Unknown reason\n");
	  break;
	}
      cmd->frozen_console->dd_printf("F 0x%06x\n", uc->PC); // for sdcdb
      unsigned long dt= uc?(uc->ticks->ticks - start_tick):0;
      if (reason != resSTEP)
	cmd->frozen_console->dd_printf("Simulated %lu ticks in %f sec, rate=%f\n",
				       dt,
				       dnow() - start_at,
				       (dt*(1/uc->xtal)) / (dnow() - start_at));
      //if (cmd->actual_console != cmd->frozen_console)
      cmd->frozen_console->flags&= ~CONS_FROZEN;
      //cmd->frozen_console->dd_printf("_s_");
      cmd->frozen_console->print_prompt();
      cmd->frozen_console= 0;
    }
  cmd->update_active();
}

void
cl_sim::stop(class cl_ev_brk *brk)
{
  class cl_commander_base *cmd= app->get_commander();

  state&= ~SIM_GO;
  if (cmd->frozen_console)
    {
      class cl_console_base *con= cmd->frozen_console;
      /*
      if (reason == resUSER &&
	  cmd->frozen_console->input_avail())
	cmd->frozen_console->read_line();
      */
      //con->dd_printf("Stop at 0x%06x\n", uc->PC);
      con->dd_printf("Event `%s' at %s[0x%x]: 0x%x %s\n",
		     brk->id, brk->get_mem()->get_name(), (int)brk->addr,
		     (int)uc->instPC,
		     uc->disass(uc->instPC, " "));
      //con->flags&= ~CONS_FROZEN;
      //con->print_prompt();
      //cmd->frozen_console= 0;
    }
}


/*
 */

void
cl_sim::build_cmdset(class cl_cmdset *cmdset)
{
  class cl_cmd *cmd;
  class cl_cmdset *cset;

  cmdset->add(cmd= new cl_run_cmd("run", 0,
"run [start [stop]] Go",
"long help of run"));
  cmd->init();
  cmd->add_name("go");
  cmd->add_name("r");

  cmdset->add(cmd= new cl_stop_cmd("stop", 0,
"stop               Stop",
"long help of stop"));
  cmd->init();

  cmdset->add(cmd= new cl_step_cmd("step", DD_TRUE,
"step               Step",
"long help of step"));
  cmd->init();
  cmd->add_name("s");

  cmdset->add(cmd= new cl_next_cmd("next", DD_TRUE,
"next               Next",
"long help of next"));
  cmd->init();
  cmd->add_name("n");

  {
    cset= new cl_cmdset();
    cset->init();
    cset->add(cmd= new cl_gui_start_cmd("start", 0, 
"gui start          Start interfacing with GUI tool",
"long help of gui start"));
    cmd->init();
    cset->add(cmd= new cl_gui_stop_cmd("stop", 0, 
"gui stop           Stop interfacing with GUI tool",
"long help of gui stop"));
    cmd->init();
  }
  cmdset->add(cmd= new cl_super_cmd("gui", 0,
"gui subcommand     Operations to support GUI tools",
"long help of gui", cset));
  cmd->init();
}


/*
 * Messages to broadcast
 */
/*
void
cl_sim::mem_cell_changed(class cl_address_space *mem, t_addr addr)
{
  if (uc)
    uc->mem_cell_changed(mem, addr);
  else
    printf("JAJ sim\n");
}
*/

/* End of sim.src/sim.cc */
