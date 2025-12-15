/*
 * Simulator of microcontrollers (m6801.h)
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

#include <stdio.h>
#include <ctype.h>

#include "m6801cl.h"


cl_m6801::cl_m6801(class cl_sim *asim):
  cl_m6800(asim)
{
}


const char *
cl_m6801::id_string(void)
{
  return "M6801";
}


int
cl_m6801::init(void)
{
  cl_m6800::init();
  #define RCV(R) reg_cell_var(&c ## R , &r ## R , "" #R "" , "CPU register " #R "")
  RCV(D);
#undef RCV

  return 0;
}


void
cl_m6801::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("A= $%02x %3d %+4d %c  ", A, A, (i8_t)A, isprint(A)?A:'.');
  con->dd_printf("B= $%02x %3d %+4d %c  ", B, B, (i8_t)B, isprint(B)?B:'.');
  con->dd_printf("D= $%04x %5d %+5d ", rD, rD, (i16_t)rD);
  con->dd_printf("\n");
  con->dd_printf("CC= "); con->print_bin(rF, 8); con->dd_printf("\n");
  con->dd_printf("      HINZVC\n");

  con->dd_printf("IX= ");
  class cl_dump_ads ads(IX, IX+7);
  rom->dump(0, /*IX, IX+7*/&ads, 8, con);
  con->dd_color("answer");
  
  con->dd_printf("SP= ");
  ads._ss(SP, SP+7);
  rom->dump(0, /*SP, SP+7*/&ads, 8, con);
  con->dd_color("answer");
  
  print_disass(PC, con);
}


/* End of motorola.src/m6801.cc */
