/*
 * Simulator of microcontrollers (simmos6502cl.h)
 *
 * Copyright (C) 2020,20 Drotos Daniel
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

#ifndef SIMMOS6502CL_HEADER
#define SIMMOS6502CL_HEADER

#include "simcl.h"


class cl_simmos6502: public cl_sim
{
public:
  cl_simmos6502(class cl_app *the_app);

  virtual class cl_uc *mk_controller(void);
};


#endif

/* End of mos6502.src/simmos6502cl.h */
