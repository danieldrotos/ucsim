/*
 * Simulator of microcontrollers (huc6280.cc)
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

#include "huc6280cl.h"


cl_huc6280::cl_huc6280(class cl_sim *asim):
  cl_mos65c02s(asim)
{
  *my_id= "HUC6280";
  mprch= new cl_chip8("mpr_chip", 8, 8, 0);
  mpras= new cl_address_space("mpr_as", 0, 8, 8);
  mprad= new cl_address_decoder(mpras, mprch, 0, 7, 0);
  mprch->init();
  mpras->init();
  mprad->init();
};


int
cl_huc6280::init(void)
{
  cl_mos65c02s::init();
  address_spaces->add(mpras);
  memchips->add(mprch);
  mpras->decoders->add(mprad);
  mprad->activate(0);
  return 0;
}


/* End of mos6502.src/huc6280.cc */
