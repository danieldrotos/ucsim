/*
 * Simulator of microcontrollers (ta1cl.h)
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

#ifndef RXK_TA1CL_HEADER
#define RXK_TA1CL_HEADER

#include "hwcl.h"

#include "rxkcl.h"


class cl_ta1: public cl_hw
{
 public:
  class cl_rxk *ruc;
  bool use_tapr;
  MCELL *perclk, *tastat, *tactrl;
  MCELL *tacsr, *tapr, *tacr, *tat1r;
  int divby, in_clks;
  u8_t cnt; // value of downcounter
 public:
  cl_ta1(class cl_uc *auc, bool ause_tapr);
  virtual int init(void);
  virtual void reset(void);
  virtual t_mem read(class cl_memory_cell *cell);
  virtual void write(class cl_memory_cell *cell, t_mem *val);
  virtual int tick(int cycles) {return(0);}
  virtual int Tick(int cycles);
  virtual void print_info(class cl_console_base *con);
};


#endif

/* End of rxk.src/ta1cl.h */
