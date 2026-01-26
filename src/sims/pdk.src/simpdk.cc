/*
 * Simulator of microcontrollers (simpdk.cc)
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

#include <stdio.h>
#include <strings.h>

// prj

// local
#include "glob.h"
#include "pdk16cl.h"

#include "simpdkcl.h"


cl_simpdk::cl_simpdk(class cl_app *the_app):
  cl_sim(the_app)
{}

class cl_uc *
cl_simpdk::mk_controller(void)
{
  class cl_uc *u;
  struct cpu_entry *ct;

  if ((ct= type_entry("")) == NULL)
    return NULL;
  
  switch (ct->type)
    {
    case CPU_PDK13: // SYM_84B
      u= new cl_pdk(ct, this);
      return u;
    case CPU_PDK14: // SYM_85A
      u= new cl_pdk(ct, this);
      return u;
    case CPU_PDK15: // SYM_86B
      u= new cl_pdk(ct, this);
      return u;
    case CPU_PDK16: // SYM_83A
      u= new cl_pdk(ct, this);
      return u;
    case CPU_PDKX:
      u= new cl_pdk(ct, this);
      return u;
    default:
      return NULL;
    }
  return NULL;
}


/* End of pdk.src/simpdk.cc */
