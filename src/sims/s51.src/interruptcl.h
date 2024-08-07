/*
 * Simulator of microcontrollers (interruptcl.h)
 *
 * Copyright (C) 1999 Drotos Daniel
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

#ifndef INTERRUPTCL_HEADER
#define INTERRUPTCL_HEADER

#include "stypes.h"
#include "pobjcl.h"
#include "uccl.h"

#include "newcmdcl.h"


class cl_interrupt: public cl_hw
{
public:
  class cl_address_space *sfr;
  bool was_reti, bit_IT0, bit_IT1, bit_INT0, bit_INT1;
  class cl_memory_cell *cell_tcon, *cell_it0, *cell_it1;
public:
  cl_interrupt(class cl_uc *auc);
  virtual int init(void);
  //virtual const char *cfg_help(t_addr addr);
  
  virtual void added_to_uc(void);

  //virtual t_mem read(class cl_memory_cell *cell);
  virtual void write(class cl_memory_cell *cell, t_mem *val);

  //virtual void mem_cell_changed(class cl_m *mem, t_addr addr);

  virtual int tick(int cycles);
  virtual void reset(void);
  virtual void happen(class cl_hw *where, enum hw_event he, void *params);

  virtual void print_info(class cl_console_base *con);
};


#endif

/* End of s51.src/interruptcl.h */
