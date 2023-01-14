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

//#include "ddconfig.h"

#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <string.h>
//#include "i_string.h"

// prj
#include "globals.h"
#include "utils.h"

// cmd
#include "cmd_execcl.h"

// local, sim.src
//#include "simcl.h"
//#include "appcl.h"
#include "simifcl.h"


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
  simif= uc->get_hw("simif", 0);
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
  int res;
  if (state & SIM_GO)
    {
      if (steps_done == 0)
	start_at= dnow();

      res= uc->do_inst(); 

      if (res < resSTOP)
	steps_done++;
      else
	{
	  if (res >= resSTOP)
	    stop(res);
	}
      
      if ((steps_todo > 0) &&
	  (steps_done >= steps_todo))
	stop(resSTEP);
      
      if (uc->stop_at_time &&
	  uc->stop_at_time->reached())
	{
	  delete uc->stop_at_time;
	  uc->stop_at_time= NULL;
	  stop(resBREAKPOINT);
	}
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
  class cl_commander_base *cmd= app->get_commander();
  state|= SIM_GO;
  if (con)
    {
      con->set_flag(CONS_FROZEN, true);
      cmd->freeze(con);
      cmd->update_active();
    }
  if (uc)
    start_tick= uc->ticks->get_ticks();
  steps_done= 0;
  steps_todo= steps_to_do;
}

void
cl_sim::stop(int reason)
{
  class cl_commander_base *cmd= app->get_commander();
  class cl_option *o= app->options->get_option("quit");
  unsigned long dt= uc?(uc->ticks->get_ticks() - start_tick):0;
  class cl_console_base *con= (cmd==NULL)?NULL:(cmd->frozen_or_actual());

  state&= ~SIM_GO;
  stop_at= dnow();
  if (simif)
    simif->cfg_set(simif_reason, reason);

  class cl_brk *b= NULL;
  if (reason == resBREAKPOINT)
    {
      b= uc->fbrk_at(uc->PC);
    }
  if (b)
    {
      class cl_option *o;
      o= app->options->get_option("beep_break");
      bool e= false;
      if (o) o->get_value(&e);
      if (e)
	if (con) con->dd_printf("\007");

      b->breaking();
      steps_done= 0;
    }
  
  if (!(state & SIM_GO) &&
      cmd->frozen())
    {
      fflush(stdout); // Needed to make sure we get the right simulator output order
      
      if (reason == resUSER &&
	  cmd->frozen() && cmd->frozen()->input_avail())
	cmd->frozen()->read_line();
      if (con) con->un_redirect();
      if (con) con->dd_color("debug");
      // Stop message should start with a newline, to avoid mixing this line with previous output from simulated program
      if (con) con->dd_printf("\nStop at 0x%06x: (%d) ", AU(uc->PC), reason);
      switch (reason)
	{
	case resHALT:
	  if (con) con->dd_printf("Halted\n");
	  break;
	case resINV_ADDR:
	  if (con) con->dd_printf("Invalid address\n");
	  break;
	case resSTACK_OV:
	  if (con) con->dd_printf("Stack overflow\n");
	  break;
	case resBREAKPOINT:
	  if (con) {
	    con->dd_printf("Breakpoint\n");
	    uc->print_regs(cmd->frozen());
	  }
	  steps_done= 0;
	  break;
	case resEVENTBREAK:
	  if (con) {
	    con->dd_printf("Event break\n");
	    uc->print_regs(con);
	  }
	  steps_done= 0;
	  break;
	case resINTERRUPT:
	  if (con) con->dd_printf("Interrupt\n");
	  break;
	case resWDTRESET:
	  if (con) con->dd_printf("Watchdog reset\n");
	  break;
	case resUSER:
	  if (con) con->dd_printf("User stopped\n");
	  break;
	case resINV_INST:
	  {
	    if (con) con->dd_printf("Invalid instruction");
	    if (uc->rom)
	      if (con) con->dd_printf(" 0x%04x\n",
				      MU32(uc->rom->get(uc->instPC)));
	  }
         break;
	case resSTEP:
	  if (con) {
	    con->dd_printf("stepped %ld ticks\n", dt);
	    uc->print_regs(con);
	  }
	  break;
	case resERROR:
	  // uc::check_error prints error messages...
	  break;
	case resSIMIF:
	  if (con) con->dd_printf("Program stopped itself\n");
	  break;
	case resSELFJUMP:
	  if (con) con->dd_printf("Jump to itself\n");
	  break;
        case resNOT_DONE:
          if (con) con->dd_printf("Instruction is still executing\n");
          break;
	default:
	  if (con) con->dd_printf("Unknown reason\n");
	  break;
	}
      if (con) con->dd_cprintf("answer", "F 0x%06x\n", AU(uc->PC)); // for sdcdb
      if ((reason != resSTEP) ||
	  (steps_done > 1))
	{
	  if (!application->quiet)
	    {
	      if (con) {
		con->dd_printf("Simulated %lu ticks (%.3e sec)\n",
			       dt,
			       dt*(1/uc->get_xtal()));
		con->dd_printf("Host usage: %f sec, rate=%f\n",
			       stop_at - start_at,
			       (dt*(1/uc->get_xtal())) / (stop_at - start_at));
	      }
	    }
	}
      if ((reason == resBREAKPOINT) ||
	  (reason == resEVENTBREAK))
	uc->displays->do_display(NULL);	  
      if (con == cmd->frozen()) {
	con->set_flag(CONS_FROZEN, false);
	con->print_prompt();
      }
      cmd->freeze(0);
    }

  bool q_opt= false;
  if (o)
    o->get_value(&q_opt);
  if (!(state & SIM_GO) &&
      q_opt)
    state|= SIM_QUIT;
  
  cmd->update_active();
}

void
cl_sim::change_run(int reason)
{
  if (state & SIM_GO)
    stop(reason);
  else
    start(0, 0);
}

/*
 */

void
cl_sim::build_cmdset(class cl_cmdset *cmdset)
{
  class cl_cmd *cmd;

  cmdset->add(cmd= new cl_run_cmd("run", 0));
  cmd->init();
  cmd->add_name("go");
  cmd->add_name("r");
  cmd->add_name("continue");
  
  cmdset->add(cmd= new cl_stop_cmd("stop", 0));
  cmd->init();

  cmdset->add(cmd= new cl_step_cmd("step", true));
  cmd->init();
  cmd->add_name("s");

  cmdset->add(cmd= new cl_next_cmd("next", true));
  cmd->init();
  cmd->add_name("n");

  //class cl_super_cmd *super_cmd;
  //class cl_cmdset *cset;
  /*
    {
    // info
    super_cmd= (class cl_super_cmd *)(cmdset->get_cmd("info"));
    if (super_cmd)
      cset= super_cmd->get_subcommands();
    else {
      cset= new cl_cmdset();
      cset->init();
    }
    if (!super_cmd) {
    cmdset->add(cmd= new cl_super_cmd("info", 0, cset));
    cmd->init();
    set_info_help(cmd);
    }
    }
  */
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
