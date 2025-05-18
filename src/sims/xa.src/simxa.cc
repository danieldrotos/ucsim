/*
 * Simulator of microcontrollers (simxa.cc)
 *
 * Copyright (C) 2002 Drotos Daniel
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
#include "simxacl.h"
#include "xacl.h"


cl_simxa::cl_simxa(class cl_app *the_app):
  cl_sim(the_app)
{}

class cl_uc *
cl_simxa::mk_controller(void)
{
  struct cpu_entry *ct;

  if ((ct= type_entry("")) == NULL)
    return NULL;

  if (ct->type == CPU_XA)
    {
      return(new cl_xa(this));
    }
  return NULL;
}


/* End of xa.src/simxa.cc */
