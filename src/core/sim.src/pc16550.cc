/*
 * Simulator of microcontrollers (pc16550.cc)
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

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "utils.h"
#include "globals.h"
//#include "fiocl.h"

#include "pc16550cl.h"

cl_pc16550::cl_pc16550(class cl_uc *auc, int aid):
  cl_serial_hw(auc, aid, chars("pc16550"))
{
  as= NULL;
  base= 0;
}

int
cl_pc16550::init(void)
{
}

const char *
cl_pc16550::cfg_help(t_addr addr)
{
}

/* End of sim.src/pc16550.cc */
