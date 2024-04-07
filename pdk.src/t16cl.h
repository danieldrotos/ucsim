/*
 * Simulator of microcontrollers (t16cl.h)
 *
 * Copyright (C) 2020,2024 Drotos Daniel, Talker Bt.
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

#ifndef T16CL_HEADER
#define T16CL_HEADER

#include "hwcl.h"


class cl_t16: public cl_hw
{
 public:
  class cl_memory_cell *mod;
  u16_t cnt;
 public:
  cl_t16(class cl_uc *auc, const char *aname);
  virtual int init(void);
  virtual void reset(void);
  virtual void write(class cl_memory_cell *cell, t_mem *val);
  virtual int tick(int cycles);
  
  virtual void print_info(class cl_console_base *con);
};


#endif

/* End of pdk.src/t16cl.h */
