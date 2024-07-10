/*
 * Simulator of microcontrollers (pc16550cl.h)
 *
 * Copyright (C) 2024 Drotos Daniel
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

#ifndef PC16550_HEADER
#define PC16550_HEADER

#include "serial_hwcl.h"

enum pc16550_reg_idx
  {
  };

enum pc16550_cfg
  {
    pc16550_cfg_base	= serconf_nr+0,
  };

class cl_pc16550: public cl_serial_hw
{
 protected:
  class cl_address_space *as;
  t_addr base;
  class cl_memory_cell *regs[10];
 public:
  cl_pc16550(class cl_uc *auc, int aid);
};


#endif

/* End of sim.src/pc16550cl.h */
