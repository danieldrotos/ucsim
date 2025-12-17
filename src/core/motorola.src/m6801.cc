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

#include "glob68.h"

#include "m6801cl.h"



i8_t m6801ticks[256]= {
  /*      0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f  */
  /* 0 */ 0, 2, 0, 0, 0, 0, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2,
  /* 1 */ 2, 2, 0, 0, 0, 0, 2, 2, 0, 2, 0, 2, 0, 0, 0, 0,
  /* 2 */ 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  /* 3 */ 4, 4, 4, 4, 4, 4, 4, 4, 0, 5, 0,10, 0, 0, 9,12,
  /* 4 */ 2, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2,
  /* 5 */ 2, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2,
  /* 6 */ 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 4, 7,
  /* 7 */ 6, 0, 0, 6, 6, 0, 6, 6, 6, 6, 6, 0, 6, 6, 3, 6,
  /* 8 */ 2, 2, 2, 0, 2, 2, 2, 0, 2, 2, 2, 2, 3, 8, 3, 0,
  /* 9 */ 3, 3, 3, 0, 3, 3, 3, 4, 3, 3, 3, 3, 4, 0, 4, 5,
  /* a */ 5, 5, 5, 0, 5, 5, 5, 6, 5, 5, 5, 5, 6, 8, 6, 7,
  /* b */ 4, 4, 4, 0, 4, 4, 4, 5, 4, 4, 4, 4, 5, 9, 5, 6,
  /* c */ 2, 2, 2, 0, 2, 2, 2, 0, 2, 2, 2, 2, 0, 0, 3, 0,
  /* d */ 3, 3, 3, 0, 3, 3, 3, 4, 3, 3, 3, 3, 0, 0, 4, 5,
  /* e */ 5, 5, 5, 0, 5, 5, 5, 6, 5, 5, 5, 5, 0, 0, 6, 7,
  /* f */ 4, 4, 4, 0, 4, 4, 4, 5, 4, 4, 4, 4, 0, 0, 5, 6
};


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


struct dis_entry *
cl_m6801::dis_tbl(void)
{
  return(disass_m6801);
}


struct dis_entry *
cl_m6801::get_dis_entry(t_addr addr)
{
  struct dis_entry *dt= dis_tbl();
  int i= 0;
  t_mem code= rom->get(addr);

  if (dt == NULL)
    return NULL;
  while (((code & dt[i].mask) != dt[i].code) &&
	 dt[i].mnemonic)
    i++;
  if (dt[i].mnemonic)
    return &dt[i];
  return cl_m6800::get_dis_entry(addr);
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
