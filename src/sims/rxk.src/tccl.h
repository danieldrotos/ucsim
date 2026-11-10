/*
 * Simulator of microcontrollers (tccl.h)
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

#ifndef RXK_TCCL_HEADER
#define RXK_TCCL_HEADER

#include "hwcl.h"

#include "rxkcl.h"


class cl_tc: public cl_hw
{
 public:
  class cl_rxk *ruc;
  MCELL *clk_src, *a1in, *a1out;
  MCELL *tccsr, *tccr, *tcbar, *tcbpr;
  int in_clks, divby;
  u16_t cnt, cmp1, cmp2;
 public:
  cl_tc(class cl_uc *auc);
  virtual int init(void);
  virtual void reset(void);
  virtual t_mem read(class cl_memory_cell *cell);
  virtual void write(class cl_memory_cell *cell, t_mem *val);
  virtual void set_clk(u8_t val);
  virtual int tick(int cycles) {return(0);}
  virtual int Tick(int cycles);
  virtual void counted(void);
  virtual void inc_bpr(void);
  virtual void print_info(class cl_console_base *con);
};


class cl_tc6: public cl_tc
{
public:
  MCELL *a11out;
public:
  cl_tc6(class cl_uc *auc): cl_tc(auc) {}
  virtual int init(void);
  virtual void set_clk(u8_t val);
};

  
#endif

/* End of rxk.src/tccl.h */
