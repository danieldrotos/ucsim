/*
 * Simulator of microcontrollers (tacl.h)
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

#ifndef RXK_TACL_HEADER
#define RXK_TACL_HEADER

#include "hwcl.h"

#include "rxkcl.h"


class cl_ta: public cl_hw
{
 public:
  class cl_rxk *ruc;
  MCELL *perclk, *tastat, *tactrl;
  MCELL *tacsr, *tacr, *tatxr;
  u8_t cnt; // value of downcounter
  int in_clks;
 public:
  cl_ta(class cl_uc *auc, int aid);
  virtual int init(void);
  virtual void reset(void);
  virtual t_mem read(class cl_memory_cell *cell);
  virtual void write(class cl_memory_cell *cell, t_mem *val);
  virtual int tick(int cycles) {return(0);}
  virtual int Tick(int cycles);
  virtual void print_info(class cl_console_base *con);
};


class cl_ta1: public cl_ta
{
 public:
  u8_t tapr_mask, pre_div;
  MCELL *tapr;
public:
  cl_ta1(class cl_uc *auc, u8_t atapr_mask);
  virtual int init(void);
  virtual void reset(void);
  virtual t_mem read(class cl_memory_cell *cell);
  virtual void write(class cl_memory_cell *cell, t_mem *val);
  virtual void print_info(class cl_console_base *con);
};


class cl_tax: public cl_ta
{
 public:
  t_addr clk_sel_addr, clk_alt_addr;
  MCELL /* *clk_sel,*/ *clk_alt, *ta1_in;
  u8_t clk_sel_mask;
 public:
  cl_tax(class cl_uc *auc, int aid,
	 t_addr aclk_sel_addr, u8_t aclk_sel_mask,
	 t_addr aclk_alt_addr);
  virtual int init(void);
  virtual void reset(void);
  virtual t_mem read(class cl_memory_cell *cell);
  virtual void write(class cl_memory_cell *cell, t_mem *val);
  virtual void print_info(class cl_console_base *con);
};


#endif

/* End of rxk.src/ta1cl.h */
