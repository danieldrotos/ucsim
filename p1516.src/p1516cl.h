/*
 * Simulator of microcontrollers (p1516cl.h)
 *
 * Copyright (C) 2020,20 Drotos Daniel, Talker Bt.
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

#ifndef P1516CL_HEADER
#define P1516CL_HEADER

#include "uccl.h"
#include "memcl.h"


/*
 * Base of P1516 processor
 */

class cl_p1516: public cl_uc
{
 public:
  class cl_address_space *rom;
 public:
  cl_p1516(class cl_sim *asim);
  virtual int init(void);
  virtual char *id_string(void);
};


#endif

/* End of p1516.src/p1516.cc */
