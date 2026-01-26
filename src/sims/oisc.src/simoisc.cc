/*
 * Simulator of microcontrollers (simoisc.cc)
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

#include "simoisccl.h"
#include "oisccl.h"
#include "urisccl.h"
#include "misc16cl.h"
#include "emcl.h"
#include "glob.h"


cl_simoisc::cl_simoisc(class cl_app *the_app):
  cl_sim(the_app)
{}

class cl_uc *
cl_simoisc::mk_controller(void)
{
  class cl_oisc *uc;
  struct cpu_entry *ct;

  if ((ct= type_entry("")) == NULL)
    return NULL;
  
  switch (ct->type)
    {
    case CPU_OISC:
      uc= new cl_oisc(this);
      uc->type= ct;
      return uc;
    case CPU_URISC:
      uc= new cl_urisc(this);
      uc->type= ct;
      return uc;
    case CPU_MISC16:
      uc= new cl_misc16(this);
      uc->type= ct;
      return uc;
    case CPU_EM:
      uc= new cl_em(this);
      uc->type= ct;
      return uc;
    default:
      return NULL;
    }
  return NULL;
}


/* End of oisc.src/simoisc.cc */
