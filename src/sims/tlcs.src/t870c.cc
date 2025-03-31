/*
 * Simulator of microcontrollers (t870c.cc)
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
#include "t870ccl.h"


cl_t870c::cl_t870c(class cl_sim *asim):
  cl_uc(asim)
{
}

int
cl_t870c::init(void)
{
  rbanks= (struct rbank_870c_t *)malloc(sizeof(*rbanks));
  rbank= &rbanks[0];
  return 0;
}


/* End of tlcs.src/t870c.cc */
