/*
 * Simulator of microcontrollers (simrxk.cc)
 *
 * Copyright (C) 2020 Drotos Daniel
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

// local
#include "simrxkcl.h"
#include "r6kcl.h"


cl_simrxk::cl_simrxk(class cl_app *the_app):
  cl_sim(the_app)
{}

class cl_uc *
cl_simrxk::mk_controller(void)
{
  struct cpu_entry *ct;

  if ((ct= type_entry("")) == NULL)
    return NULL;
  
  switch (ct->type)
    {
    case CPU_R2K:
      return(new cl_r2k(this));
    case CPU_R3K:
      return(new cl_r3k(this));
    case CPU_R3KA:
      return(new cl_r3ka(this));
    case CPU_R4K:
      return(new cl_r4k(this));
    case CPU_R5K:
      return(new cl_r5k(this));
    case CPU_R6K:
      return(new cl_r6k(this));
    default:
      return NULL;
    }
  return NULL;
}


/* End of rxk.src/simrxk.cc */
