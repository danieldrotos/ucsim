/*
 * Simulator of microcontrollers (fpgacl.h)
 *
 * Copyright (C) @@S@@,@@Y@@ Drotos Daniel, Talker Bt.
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

#ifndef FPGACL_HEADER
#define FPGACL_HEADER

#include "hwcl.h"


class cl_fpga;

class cl_led: public cl_base
{
public:
  class cl_fpga *fpga;
  int x, y;
  uint32_t mask;
public:
  cl_led(class cl_fpga *the_fpga, int ax, int ay, uint32_t amask);
  virtual void refresh(bool force);
  virtual void draw(void);
};


class cl_fpga: public cl_hw
{
public:
  cl_cell32 *pa, *pb, *pc, *pd;
  cl_cell32 *pi, *pj;
  uint32_t la, lb, lc, ld, li, lj; // last shown values
  class cl_led *leds[16];
public:
  cl_fpga(class cl_uc *auc, int aid, chars aid_string);
  virtual void make_io(void);
  virtual void new_io(class cl_f *f_in, class cl_f *f_out);
  virtual bool proc_input(void);
  virtual bool handle_input(int c);
  virtual void refresh_leds(bool force);
  virtual void refresh_display(bool force);
  virtual void draw_display(void);

  virtual t_mem read(class cl_memory_cell *cell);
  virtual void write(class cl_memory_cell *cell, t_mem *val);
};


#endif

/* End of p1516.src/fpgacl.h */
