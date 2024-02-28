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
  uint32_t last;
public:
  cl_led(class cl_fpga *the_fpga, int ax, int ay, uint32_t amask);
  virtual void refresh(bool force);
  virtual void draw(void);
};


class cl_seg: public cl_led
{
public:
  int digit;
public:
  cl_seg(class cl_fpga *the_fpga, int ax, int ay, int adigit);
  virtual void refresh(bool force);
  virtual void draw(void);
};


class cl_fpga: public cl_hw
{
public:
  cl_cell32 *pa, *pb, *pc, *pd;
  cl_cell32 *pi, *pj;
  class cl_led *leds[16];
  class cl_seg *segs[8];
  int basey;
  chars board;
public:
  cl_fpga(class cl_uc *auc, int aid, chars aid_string);
  virtual int init(void);
  virtual void mk_leds(void) {}
  virtual void mk_segs(void) {}
  virtual void make_io(void);
  virtual void new_io(class cl_f *f_in, class cl_f *f_out);
  virtual bool proc_input(void);
  virtual bool handle_input(int c);
  virtual void refresh_leds(bool force);
  virtual void refresh_segs(bool force);
  virtual void refresh_display(bool force);
  virtual void draw_display(void);
  virtual void draw_fpga(void) {}
  
  virtual t_mem read(class cl_memory_cell *cell);
  virtual void write(class cl_memory_cell *cell, t_mem *val);
};


class cl_n4: public cl_fpga
{
public:
  cl_n4(class cl_uc *auc, int aid, chars aid_string);
  virtual void mk_leds(void);
  virtual void mk_segs(void);
  virtual void draw_fpga(void);
};


class cl_bool: public cl_n4
{
public:
  cl_bool(class cl_uc *auc, int aid, chars aid_string);
  virtual void draw_fpga(void);
};


class cl_logsys: public cl_fpga
{
public:
  cl_logsys(class cl_uc *auc, int aid, chars aid_string);
  virtual void mk_leds(void);
  virtual void mk_segs(void);
  virtual void draw_fpga(void);
};


#endif

/* End of p1516.src/fpgacl.h */
