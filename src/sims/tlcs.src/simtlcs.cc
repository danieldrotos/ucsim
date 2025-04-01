/*
 * Simulator of microcontrollers (simtlcs.cc)
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

// sim.src
//#include "appcl.h"

// local
#include "tlcscl.h"
#include "t870ccl.h"
#include "t870c1cl.h"
#include "glob.h"

#include "simtlcscl.h"


cl_simtlcs::cl_simtlcs(class cl_app *the_app):
  cl_sim(the_app)
{}

class cl_uc *
cl_simtlcs::mk_controller(void)
{
  int i;
  const char *typ= 0;
  class cl_optref type_option(this);
  class cl_uc *uc;

  type_option.init();
  type_option.use("cpu_type");
  i= 0;
  if ((typ= type_option.get_value(typ)) == 0)
    typ= "TLCS90";
  while ((cpus_tlcs[i].type_str != NULL) &&
	 (strcasecmp(typ, cpus_tlcs[i].type_str) != 0))
    i++;
  if (cpus_tlcs[i].type_str == NULL)
    {
      fprintf(stderr, "Unknown processor type. "
	      "Use -H option to see known types.\n");
      return(NULL);
    }
  switch (cpus_tlcs[i].type)
    {
    case CPU_TLCS90:
      uc= new cl_tlcs(this);
      return uc;
    case CPU_TLCS870C:
      uc= new cl_t870c(this);
      return uc;
    case CPU_TLCS870C1:
      uc= new cl_t870c1(this);
      return uc;
    default:
      return NULL;
    }
  return NULL;
}


/* End of tlcs.src/simtlcs.cc */
