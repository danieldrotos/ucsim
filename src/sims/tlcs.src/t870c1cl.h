/*
 * Simulator of microcontrollers (t870c1cl.h)
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

#ifndef T870C1CL_HEADER
#define T870C1CL_HEADER

#include "t870ccl.h"

#define rW0 (rbanks[0].rwa.w)
#define rA0 (rbanks[0].rwa.a)
#define rB0 (rbanks[0].rbc.b)
#define rC0 (rbanks[0].rbc.c)
#define rD0 (rbanks[0].rde.d)
#define rE0 (rbanks[0].rde.e)
#define rH0 (rbanks[0].rhl.h)
#define rL0 (rbanks[0].rhl.l)

#define rW1 (rbanks[1].rwa.w)
#define rA1 (rbanks[1].rwa.a)
#define rB1 (rbanks[1].rbc.b)
#define rC1 (rbanks[1].rbc.c)
#define rD1 (rbanks[1].rde.d)
#define rE1 (rbanks[1].rde.e)
#define rH1 (rbanks[1].rhl.h)
#define rL1 (rbanks[1].rhl.l)

#define rWA0 (rbanks[0].wa)
#define rBC0 (rbanks[0].bc)
#define rDE0 (rbanks[0].de)
#define rHL0 (rbanks[0].hl)
#define rIX0 (rbanks[0].ix)
#define rIY0 (rbanks[0].iy)

#define rWA1 (rbanks[1].wa)
#define rBC1 (rbanks[1].bc)
#define rDE1 (rbanks[1].de)
#define rHL1 (rbanks[1].hl)
#define rIX1 (rbanks[1].ix)
#define rIY1 (rbanks[1].iy)

class cl_t870c1: public cl_t870c
{
 public:
  cl_t870c1(class cl_sim *asim);
  virtual void mk_rbanks();
  virtual int init(void);
  virtual int  nas_size(void) { return 0x20000; }

  virtual void print_regs(class cl_console_base *con);
};


#endif

/* End of tlcs.src/tl870cl.h */
