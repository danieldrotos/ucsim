/*
 * Simulator of microcontrollers (tbcl.h)
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

#ifndef RXK_TBCL_HEADER
#define RXK_TBCL_HEADER

#include "hwcl.h"

#include "rxkcl.h"


class cl_tb: public cl_hw
{
 public:
  class cl_rxk *ruc;
  MCELL *clk_src, *a1in, *a1out;
  MCELL *tbcsr, *tbcr, *tbcmr, *tbclr;
  MCELL *tbm1r, *tbl1r, *tbm2r, *tbl2r;
  MCELL *tbstat, *tbctrl;
  int in_clks, divby;
  u16_t cnt, cmp1, cmp2;
 public:
  cl_tb(class cl_uc *auc);
  virtual int init(void);
  virtual void reset(void);
  virtual t_mem read(class cl_memory_cell *cell);
  virtual void write(class cl_memory_cell *cell, t_mem *val);
  virtual void set_clk(u8_t val);
  virtual int tick(int cycles) {return(0);}
  virtual int Tick(int cycles);
  virtual void counted(void);
  virtual void print_info(class cl_console_base *con);
};


/* Timer B with step register extension, r4k and up */

class cl_tbs: public cl_tb
{
public:
  MCELL *tbsl1r, *tbsm1r, *tbsl2r, *tbsm2r;
public:
  cl_tbs(class cl_uc *auc): cl_tb(auc) {}
  virtual int init(void);
  virtual int tick(int cycles) {return(0);}
  virtual void counted(void);
  virtual void print_info(class cl_console_base *con);
};

class cl_tbs6: public cl_tbs
{
public:
  MCELL *a11out;
public:
  cl_tbs6(class cl_uc *auc): cl_tbs(auc) {}
  virtual int init(void);
  virtual void set_clk(u8_t val);
};

  
#endif

/* End of rxk.src/tbcl.h */
