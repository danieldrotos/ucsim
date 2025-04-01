/*
 * Simulator of microcontrollers (t870cl.h)
 *
 * Copyright (C) 2016 Drotos Daniel
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

#ifndef T870CL_HEADER
#define T870CL_HEADER

#include "uccl.h"


class cl_t870: public cl_uc
{
public:
  class cl_cell8 cW, cA;
  class cl_cell8 cB, cC;
  class cl_cell8 cD, cE;
  class cl_cell8 cH, cL;
  class cl_cell8 *regs8[8];
  class cl_cell16 cWA;
  class cl_cell16 cBC;
  class cl_cell16 cDE;
  class cl_cell16 cHL;
  class cl_cell16 *regs16[8];
public:
  cl_t870(class cl_sim *asim);
  virtual int init(void);
};


#endif

/* End of tlcs.src/tl870cl.h */
