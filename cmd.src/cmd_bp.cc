/*
 * Simulator of microcontrollers (cmd.src/bp.cc)
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

#include "ddconfig.h"

#include "stdlib.h"

// sim
#include "brkcl.h"
#include "argcl.h"
#include "simcl.h"

// cmd
#include "cmd_bpcl.h"


/*
 * BREAK command
 */

//int
//cl_break_cmd::do_work(class cl_sim *sim,
//		      class cl_cmdline *cmdline, class cl_console *con)
COMMAND_DO_WORK_UC(cl_break_cmd)
{
  t_addr addr= 0;
  int hit= 1;
  char op;
  chars cond= "";
  chars s;
  class cl_address_space *mem;
  class cl_cmd_arg *params[6]= { cmdline->param(0),
				 cmdline->param(1),
				 cmdline->param(2),
				 cmdline->param(3),
				 cmdline->param(4),
				 cmdline->param(5) };

  if (0) {}
  else if (cmdline->syntax_match(uc, CELL NUMBER STRING STRING)) {
    hit= params[1]->value.number;
    mem= uc->address_space(params[0]->value.cell, &addr);
    if (!mem)
      return con->dd_printf("%s\n", short_help?short_help:"Error: wrong syntax\n"),
	false;
    s= params[2]->get_svalue();
    if (s && *s &&
	(strcmp(s, "if") == 0))
      cond= params[3]->get_svalue();
    if (mem == uc->rom)
      do_fetch(uc, addr, hit, cond, con);
    else
      {
	do_event(uc, mem, 'r', addr, hit, cond, con);
	do_event(uc, mem, 'w', addr, hit, cond, con);
      }
  }
  else if (cmdline->syntax_match(uc, CELL STRING STRING)) {
    hit= 1;
    mem= uc->address_space(params[0]->value.cell, &addr);
    if (!mem)
      return con->dd_printf("%s\n", short_help?short_help:"Error: wrong syntax\n"),
	false;
    s= params[1]->get_svalue();
    if (s && *s &&
	(strcmp(s, "if") == 0))
      cond= params[2]->get_svalue();
    if (mem == uc->rom)
      do_fetch(uc, addr, hit, cond, con);
    else
      {
	do_event(uc, mem, 'r', addr, hit, cond, con);
	do_event(uc, mem, 'w', addr, hit, cond, con);
      }
  }
  else if (cmdline->syntax_match(uc, CELL NUMBER)) {
    hit= params[1]->value.number;
    mem= uc->address_space(params[0]->value.cell, &addr);
    if (!mem)
      return con->dd_printf("%s\n", short_help?short_help:"Error: wrong syntax\n"),
	false;
    if (mem == uc->rom)
      do_fetch(uc, addr, hit, cond, con);
    else
      {
	do_event(uc, mem, 'r', addr, hit, cond, con);
	do_event(uc, mem, 'w', addr, hit, cond, con);
      }
  }
  else if (cmdline->syntax_match(uc, CELL)) {
    hit= 1;
    mem= uc->address_space(params[0]->value.cell, &addr);
    if (!mem)
      return con->dd_printf("%s\n", short_help?short_help:"Error: wrong syntax\n"),
	false;
    if (mem == uc->rom)
      do_fetch(uc, addr, hit, cond, con);
    else
      {
	do_event(uc, mem, 'r', addr, hit, cond, con);
	do_event(uc, mem, 'w', addr, hit, cond, con);
      }
  }
  else if (cmdline->syntax_match(uc, MEMORY STRING ADDRESS NUMBER STRING STRING)) {
    mem= params[0]->value.memory.address_space;
    op= *(params[1]->get_svalue());
    addr= params[2]->value.address;
    hit= params[3]->value.number;
    s= params[4]->get_svalue();
    if (s && *s && (s=="if"))
      cond= params[5]->get_svalue();
    do_event(uc, mem, op, addr, hit, cond, con);
  }
  else if (cmdline->syntax_match(uc, MEMORY STRING ADDRESS NUMBER)) {
    mem= params[0]->value.memory.address_space;
    op= *(params[1]->get_svalue());
    addr= params[2]->value.address;
    hit= params[3]->value.number;
    do_event(uc, mem, op, addr, hit, cond, con);
  }
  else if (cmdline->syntax_match(uc, MEMORY STRING ADDRESS STRING STRING)) {
    mem= params[0]->value.memory.address_space;
    op= *(params[1]->get_svalue());
    addr= params[2]->value.address;
    hit= 1;
    s= params[3]->get_svalue();
    if (s && *s && (s=="if"))
      cond= params[4]->get_svalue();
    do_event(uc, mem, op, addr, hit, cond, con);
  }
  else if (cmdline->syntax_match(uc, MEMORY STRING ADDRESS)) {
    mem= params[0]->value.memory.address_space;
    op= *(params[1]->get_svalue());
    addr= params[2]->value.address;
    hit= 1;
    do_event(uc, mem, op, addr, hit, cond, con);
  }
  else if (cmdline->syntax_match(uc, ADDRESS NUMBER STRING STRING)) {
    addr= params[0]->value.address;
    hit= params[1]->value.number;
    s= params[2]->get_svalue();
    if (s && *s && (s=="if"))
      cond= params[3]->get_svalue();
    do_fetch(uc, addr, hit, cond, con);
  }
  else if (cmdline->syntax_match(uc, ADDRESS NUMBER)) {
    addr= params[0]->value.address;
    hit= params[1]->value.number;
    do_fetch(uc, addr, hit, cond, con);
  }
  else if (cmdline->syntax_match(uc, ADDRESS STRING STRING)) {
    addr= params[0]->value.address;
    hit= 1;
    s= params[1]->get_svalue();
    if (s && *s && (s=="if"))
      cond= params[2]->get_svalue();
    do_fetch(uc, addr, hit, cond, con);
  }
  else if (cmdline->syntax_match(uc, ADDRESS)) {
    addr= params[0]->value.address;
    hit= 1;
    do_fetch(uc, addr, hit, cond, con);
  }
  else
    {
      con->dd_printf("%s\n", short_help?short_help:"Error: wrong syntax\n");
      return(false);
    }
  return(false);
}

void
cl_break_cmd::do_fetch(class cl_uc *uc,
		       t_addr addr, int hit,
		       chars cond,
		       class cl_console_base *con)
{
  if (hit > 99999)
    {
      con->dd_printf("Hit value %d is too big.\n", hit);
      return;
    }
  if (uc->fbrk->bp_at(addr))
    con->dd_printf("Breakpoint at 0x%06x is already set.\n", addr);
  else
    {
      class cl_brk *b= new cl_fetch_brk(uc->rom/*address_space(MEM_ROM_ID)*/,
					uc->make_new_brknr(),
                                        addr, perm, hit);
      b->init();
      b->cond= cond;
      uc->fbrk->add_bp(b);
      const char *s= uc->disass(addr, NULL);
      con->dd_printf("Breakpoint %d at 0x%06x: %s (cond=\"%s\")\n", b->nr, addr, s, (char*)cond);
      free((char *)s);
    }
}

void
cl_break_cmd::do_event(class cl_uc *uc,
		       class cl_address_space *mem,
		       char op, t_addr addr, int hit,
		       chars cond,
		       class cl_console_base *con)
{
  class cl_ev_brk *b= NULL;

  b= uc->mk_ebrk(perm, mem, op, addr, hit);
  if (b)
    {
      b->init();
      b->cond= cond;
      uc->ebrk->add_bp(b);
    }
  else
    con->dd_printf("Couldn't make event breakpoint\n");
}


/*
 * CLEAR address
 */

//int
//cl_clear_cmd::do_work(class cl_sim *sim,
//		      class cl_cmdline *cmdline, class cl_console *con)
COMMAND_DO_WORK_UC(cl_clear_cmd)
{
  int idx;
  class cl_brk *brk= uc->fbrk->get_bp(uc->PC, &idx);

  if (cmdline->param(0) == 0)
    {
      if (!brk)
	{
	  con->dd_printf("No breakpoint at this address.\n");
	  return(0);
	}
      uc->fbrk->del_bp(uc->PC);
      return(0);
    }

  int i= 0;
  class cl_cmd_arg *param;
  while ((param= cmdline->param(i++)))
    {
      t_addr addr;
      if (!param->as_address(uc))
	return(false);
      addr= param->value.address;
      if (uc->fbrk->bp_at(addr) == 0)
	con->dd_printf("No breakpoint at 0x%06x\n", addr);
      else
	uc->fbrk->del_bp(addr);
    }

  return(false);
}


/*
 * DELETE nr nr ...
 */

//int
//cl_delete_cmd::do_work(class cl_sim *sim,
//		       class cl_cmdline *cmdline, class cl_console *con)
COMMAND_DO_WORK_UC(cl_delete_cmd)
{
  if (cmdline->param(0) == 0)
    {
      // delete all
      uc->remove_all_breaks();
    }
  else
    {
      int i= 0;
      class cl_cmd_arg *param;
      while ((param= cmdline->param(i++)))
	{
	  long num;
	  if (param->get_ivalue(&num))
	    {
	      if (!uc->rm_brk(num))
		con->dd_printf("Error\n");
	    }
	}
    }
  return(false);
}


/*
 * COMMANDS [nr] cmdstring...
 */

COMMAND_DO_WORK_UC(cl_commands_cmd)
{
  int nr= -1/*, i*/;
  /*class cl_cmd_arg *params[10]=
    {
     cmdline->param(0),
     cmdline->param(1),
     cmdline->param(2),
     cmdline->param(3),
     cmdline->param(4),
     cmdline->param(5),
     cmdline->param(6),
     cmdline->param(7),
     cmdline->param(8),
     cmdline->param(9)
     };*/
  //for (i=0;i<10;i++)printf("p[%d]=\"%s\"\n",i,(params[i])?(params[i]->get_svalue()):"N/A");
  
  cmdline->shift();
  chars s= chars(cmdline->cmd);
  //printf("cmd(after.shift)=\"%s\"\n",(char*)s);
  //for (i=0;i<10;i++)params[i]=cmdline->param(i);
  //for (i=0;i<10;i++)printf("p[%d]=\"%s\"\n",i,(params[i])?(params[i]->get_svalue()):"N/A");
  if (cmdline->rest)
    {
      s+= ';';
      s+= cmdline->rest;
    }
  //printf("s(bef.nr.check)=\"%s\"\n",(char*)s);
  if (!s.empty())
    {
      //printf("s(not.empty)=\"%s\"\n",(char*)s);
      if (isdigit(((char*)s)[0]))
	{
	  class cl_cmd_arg *p= cmdline->param(0);
	  char *p0= (char*)s;
	  //printf("param0=\"%s\" p0=\"%s\"\n",p->get_svalue(),p0);
	  if (p)
	    {
	      long l=-2;
	      //if (p->get_ivalue(&l))
	      l= strtol(s, 0, 0);
		nr= l;
		//printf("nr=%d\n",nr);
	    }
	  cmdline->shift();
	  s= chars(cmdline->cmd);
	  //printf("S=\"%s\"\n",(char*)s);
	  if (cmdline->rest)
	    {
	      s+= ';';
	      s+= cmdline->rest;
	      //printf("S=\"%s\"\n",(char*)s);
	    }
	}
    }
  else
    return con->dd_printf("command missing\n"), false;

  if (nr < 0)
    {
      //printf("nr<0 %d\n",nr);
      nr= uc->brk_counter;
      //printf("brk_counter nr=%d\n",nr);
    }
  if (nr == 0)
    return con->dd_printf("breakpoint (%d) not found\n", nr), false;
  
  class cl_brk *b= uc->brk_by_nr(nr);
  if (!b)
    return con->dd_printf("no breakpoint (%d)\n", nr), false;

  if (!s.empty())
    {
      b->commands= s;
      //printf("USE=\"%s\"\n",(char*)s);
    }
  else
    b->commands= chars("");
  cmdline->rest= NULL;
  
  return false;
}


/* End of cmd.src/cmd_bp.cc */
