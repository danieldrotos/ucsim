/*
 * Simulator of microcontrollers (simm68hc12.cc)
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
#include "glob.h"
#include "simm68hc12cl.h"
#include "m68hc12cl.h"


cl_simm68hc12::cl_simm68hc12(class cl_app *the_app):
  cl_sim(the_app)
{}

class cl_uc *
cl_simm68hc12::mk_controller(void)
{
  class cl_i8020 *uc;
  struct cpu_entry *ct;

  if ((ct= type_entry("")) == NULL)
    return NULL;
  
  switch (ct->type)
    {
    case CPU_HC11:
      return(new cl_m68hc11(this));
    case CPU_HC12:
      return(new cl_m68hc12(this));
    default:
      return NULL;
    }
  return(NULL);
}


/* End of m68hc12.src/simm68hc12.cc */
