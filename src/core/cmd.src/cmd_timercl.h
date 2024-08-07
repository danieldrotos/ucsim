/*
 * Simulator of microcontrollers (cmd.src/timercl.h)
 *
 * Copyright (C) 2001,01 Drotos Daniel
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

#ifndef CMD_CMD_TIMERCL_HEADER
#define CMD_CMD_TIMERCL_HEADER

#include "newcmdcl.h"


extern void set_timer_help(class cl_cmd *cmd);

COMMAND_HEAD(cl_timer_cmd)
public:
  class cl_ticker *ticker;
  bool as_nr;
  int id_nr;
  chars id_str;
COMMAND_METHODS_ON(uc,cl_timer_cmd)
  void set_ticker(class cl_uc *uc,
		  class cl_cmd_arg *param);
COMMAND_TAIL;


COMMAND_ANCESTOR_ON(uc,cl_timer_add_cmd,cl_timer_cmd);
COMMAND_ANCESTOR_ON(uc,cl_timer_delete_cmd,cl_timer_cmd);
COMMAND_ANCESTOR_ON(uc,cl_timer_get_cmd,cl_timer_cmd);
COMMAND_ANCESTOR_ON(uc,cl_timer_run_cmd,cl_timer_cmd);
COMMAND_ANCESTOR_ON(uc,cl_timer_stop_cmd,cl_timer_cmd);
COMMAND_ANCESTOR_ON(uc,cl_timer_value_cmd,cl_timer_cmd);
COMMAND_ON(uc,cl_timer_list_cmd);


#endif

/* End of cmd.src/cmd_timercl.h */
