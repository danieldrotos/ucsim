/*
 * Simulator of microcontrollers (cmd.src/bpcl.h)
 *
 * Copyright (C) 1999 Drotos Daniel
 * 
 * To contact author send email to dr.dkdb#gmail.com
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

#ifndef CMD_CMD_BPCL_HEADER
#define CMD_CMD_BPCL_HEADER

#include "newcmdcl.h"


// BREAK
COMMAND_HEAD(cl_break_cmd)
public:
  enum brk_perm perm;
COMMAND_METHODS_ON(uc,cl_break_cmd)
  virtual void do_fetch(class cl_uc *uc,
			t_addr addr, int hit,
			chars cond,
			class cl_console_base *con);
  virtual void do_event(class cl_uc *uc,
			class cl_address_space *mem,
			char op, t_addr addr, int hit,
			chars cond,
			class cl_console_base *con);
  virtual void do_event(class cl_uc *uc,
			class cl_memory_cell *cell,
			char op, int hit,
			chars cond,
			class cl_console_base *con);
COMMAND_TAIL;

// TBREAK
class cl_tbreak_cmd: public cl_break_cmd
{
public:
  cl_tbreak_cmd(const char *aname,
		int  can_rep):
    cl_break_cmd(aname, can_rep) {perm=brkDYNAMIC;}
};

// CLEAR
COMMAND_ON(uc,cl_clear_cmd);

// DELETE
COMMAND_ON(uc,cl_delete_cmd);

// COMMANDS
COMMAND_ON(uc,cl_commands_cmd);

// DISPLAY
COMMAND_ON(uc,cl_display_cmd);

// UNDISPLAY
COMMAND_ON(uc,cl_undisplay_cmd);


#endif

/* End of cmd.src/cmd_bpcl.h */
