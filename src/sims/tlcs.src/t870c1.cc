/*
 * Simulator of microcontrollers (t870c1.cc)
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

#include <stdlib.h>

// local
#include "t870c1cl.h"


cl_t870c1::cl_t870c1(class cl_sim *asim):
  cl_t870c(asim)
{
}


int
cl_t870c1::init(void)
{
  cl_t870c::init();
  return 0;
}

void
cl_t870c1::mk_rbanks(void)
{
  rbanks= (struct rbank_870c_t *)malloc(sizeof(*rbanks));
  rbank= &rbanks[0];
}

/* End of tlcs.src/t870c1.cc */
