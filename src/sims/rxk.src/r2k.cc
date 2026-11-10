/*
 * Simulator of microcontrollers (r2k.cc)
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
#include "tbcl.h"

#include "r2kcl.h"


cl_r2k::cl_r2k(class cl_sim *asim):
  cl_rxk(asim)
{
}

cl_r2k::cl_r2k(class cl_sim *asim, t_addr arom_size):
  cl_rxk(asim)
{
  rom_size= arom_size;
}

const char *
cl_r2k::id_string(void)
{
  return "R2K";
}

void
cl_r2k::mk_hw_elements(void)
{
  class cl_hw *h;
  cl_uc::mk_hw_elements();

  add_hw(h= mk_ta1());
  h->init();
  add_hw(h= mk_tb());
  h->init();

  add_hw(h= new cl_tax(this, 2, 0xa4, 0x04, rxkhw_ta1_out)); h->init();
  add_hw(h= new cl_tax(this, 3, 0xa4, 0x08, rxkhw_ta1_out)); h->init();
  add_hw(h= new cl_tax(this, 4, 0xa4, 0x10, rxkhw_ta1_out)); h->init();
  add_hw(h= new cl_tax(this, 5, 0xa4, 0x20, rxkhw_ta1_out)); h->init();
  add_hw(h= new cl_tax(this, 6, 0xa4, 0x40, rxkhw_ta1_out)); h->init();
  add_hw(h= new cl_tax(this, 7, 0xa4, 0x80, rxkhw_ta1_out)); h->init();

  make_ta8_10();

  if ((h= mk_tc()) != 0)
    {
      add_hw(h);
      h->init();
    }
}

class cl_hw *
cl_r2k::mk_ta1(void)
{
  return new cl_ta1(this, 0);
}

class cl_hw *
cl_r2k::mk_tb(void)
{
  return new cl_tb(this);
}


/* End of rxk.src/r2k.cc */
