/*
 * Simulator of microcontrollers (t870c1.cc)
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

#include <stdlib.h>
#include <ctype.h>

#include "utils.h"

// local
#include "t870c1cl.h"


cl_t870c1::cl_t870c1(class cl_sim *asim):
  cl_t870c(asim)
{
}


int
cl_t870c1::init(void)
{
  cl_t870c::init();
  return 0;
}

void
cl_t870c1::mk_rbanks(void)
{
  rbanks= (struct rbank_870c_t *)malloc(sizeof(*rbanks));
  rbank= &rbanks[0];
}


void
cl_t870c1::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("JZCHSVB-  Flags= 0x%02x  ", rF);
  con->dd_printf("A= 0x%02x %3d %c\n",
		 rA, rA, isprint(rA)?rA:'.');
  con->dd_printf("%s\n", cbin(rF,8).c_str());
  if ((rF & MRBS) == 0)
    con->dd_color("answer");
  else
    con->dd_color("gray_answer");
  con->dd_printf("WA0=0x%04x [WA]=%02x  ", rWA0, nas->read(rWA0));
  con->dd_printf("BC0=0x%04x [BC]=%02x  ", rBC0, nas->read(rBC0));
  con->dd_printf("DE0=0x%04x [DE]=%02x\n", rDE0, nas->read(rDE0));
  con->dd_printf("HL0=0x%04x [HL]=%02x  ", rHL0, nas->read(rHL0));
  con->dd_printf("IX0=0x%04x [IX]=%02x  ", rIX0, nas->read(rIX0));
  con->dd_printf("IY0=0x%04x [IY]=%02x\n", rIY0, nas->read(rIY0));
  if ((rF & MRBS) != 0)
    con->dd_color("answer");
  else
    con->dd_color("gray_answer");
  con->dd_printf("WA1=0x%04x [WA]=%02x  ", rWA1, nas->read(rWA1));
  con->dd_printf("BC1=0x%04x [BC]=%02x  ", rBC1, nas->read(rBC1));
  con->dd_printf("DE1=0x%04x [DE]=%02x\n", rDE1, nas->read(rDE1));
  con->dd_printf("HL1=0x%04x [HL]=%02x  ", rHL1, nas->read(rHL1));
  con->dd_printf("IX1=0x%04x [IX]=%02x  ", rIX1, nas->read(rIX1));
  con->dd_printf("IY1=0x%04x [IY]=%02x\n", rIY1, nas->read(rIY1));

  con->dd_color("answer");
  con->dd_printf("SP =0x%04x [SP]=%02x  ", rSP, nas->read(rSP));
  con->dd_printf("\n");
  print_disass(PC, con);
}


/* End of tlcs.src/t870c1.cc */
