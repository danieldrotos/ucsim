/*
 * Simulator of microcontrollers (simz80.cc)
 *
 * Copyright (C) 1999 Drotos Daniel
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
#include <stdlib.h>
#include <string.h>

#include "globals.h"

// local
#include "glob.h"
#include "simz80cl.h"
#include "gb80cl.h"
#include "lr35902cl.h"
#include "ez80cl.h"
#include "r800cl.h"


cl_simz80::cl_simz80(class cl_app *the_app):
  cl_sim(the_app)
{}

class cl_uc *
cl_simz80::mk_controller(void)
{
  struct cpu_entry *ct;

  if ((ct= type_entry("")) == NULL)
    return NULL;

  switch (ct->type)
    {
    case CPU_Z80:
    case CPU_Z180:
    case CPU_Z80N:
      return(new cl_z80(ct, this));
    // Add Rabbits, etc here.

    case CPU_R2K:
    case CPU_R3KA:
      {
	printf("\nTo simulate Rabbit use ucsim_rxk\n");
	return NULL;
      }
      
    case CPU_LR35902:
      return(new cl_lr35902(ct, this));
    case CPU_GB80:
      return(new cl_gb80(ct, this));

    case CPU_EZ80:
      return(new cl_ez80(ct, this));

    case CPU_R800:
      return(new cl_r800(ct, this));
      
    default:
      return NULL;
    }

  return(NULL);
}


/* End of z80.src/simz80.cc */
