/*
 * Simulator of microcontrollers (timercl.h)
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

#ifndef TIMERCL_HEADER
#define TIMERCL_HEADER

#include "hwcl.h"


enum timer_modes {
  tm_stop= 0,
  tm_counter= 1,
  tm_timer= 2
};


class cl_timer: public cl_hw
{
 protected:
  unsigned int pre, pre16, tmr;
  enum timer_modes mode;
  bool int_enabled, int_active, overflow_flag;
 public:
  cl_timer(class cl_uc *auc);
  virtual void reset(void);
  virtual void print_info(class cl_console_base *con);
  virtual int tick(int cycles);
  virtual void do_timer(unsigned int cyc);
};


#endif

/* End of i8048.src/timercl.h */
