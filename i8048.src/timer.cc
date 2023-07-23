/*
 * Simulator of microcontrollers (timer.cc)
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

#include "timercl.h"


cl_timer::cl_timer(class cl_uc *auc):
  cl_hw(auc, HW_TIMER, 0, "timer")
{
  pre16= 0;
}

void
cl_timer::reset(void)
{
  pre= pre16= tmr= 0;
  mode= tm_stop;
  int_enabled= false;
  int_active= false;
  overflow_flag= false;
}

void
cl_timer::print_info(class cl_console_base *con)
{
  con->dd_printf("pre16=%u pre32=%u tmr=%u ",
		 pre16, pre, tmr);
  con->dd_printf("mode=%s ",
		 (mode==tm_counter)?"COUNTER":
		 (mode==tm_timer)?"TIMER":
		 "STOP");
  con->dd_printf("ovf=%s int=%s %s",
		 overflow_flag?"ON":"off",
		 int_active?"ON":"off",
		 int_enabled?"enabled":"disabled");
  con->dd_printf("\n");
}

int
cl_timer::tick(int cycles)
{
  unsigned int c;
  if (!on)
    return resGO;
  pre16+= cycles;
  c= pre16/16;
  if (c)
    {
      pre16%= 16;
      pre+= c;
      c= pre/32;
      if (c)
	pre%= 32;
    }
  switch (mode)
    {
    case tm_stop:
      break;
    case tm_counter:
      break;
    case tm_timer:
      do_timer(c);
      break;
    }
  return resGO;
}

void
cl_timer::do_timer(unsigned int cyc)
{
  tmr+= cyc;
  if (tmr > 0xff)
    {
      overflow_flag= true;
      if (int_enabled)
	int_active= true;
    }
  tmr&= 0xff;
}


/* End of i8048.src/timer.cc */
