/*
 * Simulator of microcontrollers (r3k.cc)
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

#include "tacl.h"

#include "r3kcl.h"


cl_r3k::cl_r3k(class cl_sim *asim):
  cl_r2k(asim)
{
}

const char *
cl_r3k::id_string(void)
{
  return "R3K";
}

/*
void
cl_r3k::mk_hw_elements(void)
{
  cl_r2k::mk_hw_elements();
}
*/

class cl_hw *
cl_r3k::mk_ta1(void)
{
  return new cl_ta1(this, 1);
}

void
cl_r3k::make_ta8_10(void)
{
  class cl_hw *h;
  add_hw(h= new cl_tax(this,  8, 0, 0, rxkhw_ta1_in)); h->init();
  add_hw(h= new cl_tax(this,  9, 0, 0, rxkhw_ta1_in)); h->init();
  add_hw(h= new cl_tax(this, 10, 0, 0, rxkhw_ta1_in)); h->init();
}


/* End of rxk.src/r3k.cc */
