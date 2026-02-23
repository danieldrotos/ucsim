/*
 * Simulator of microcontrollers (r6k.cc)
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

#include "glob.h"
#include "49wrap.h"

#include "r6kcl.h"


cl_r6k::cl_r6k(class cl_sim *asim):
  cl_r5k(asim)
{
  fill_49_wrappers(itab_49);
}

const char *
cl_r6k::id_string(void)
{
  return "R6K";
}

struct dis_entry *
cl_r6k::dis_entry(t_addr addr)
{
  u8_t code0= rom->read(addr);
  t_mem codew= code0 + 256*(rom->read(addr+1));
  struct dis_entry *de;
  int i;
  i= 0;
  while (disass_r6k[i].mnemonic)
    {
      int em, km;
      de= &disass_r6k[i];
      em= de->code >> 16;
      km= 1<<kmode;
      if (em & km)
	{
	  t_mem mc= codew & de->mask;
	  t_mem cc= de->code & 0xffff;
	  if (mc == cc)
	    return de;
	}
      i++;
    }
  return cl_r5k::dis_entry(addr);
}


void
cl_r6k::mode3k(void)
{
  cl_r5k::mode3k();
}


void
cl_r6k::mode01(void)
{
  cl_r5k::mode01();
}


void
cl_r6k::mode10(void)
{
  cl_r5k::mode10();
}

void
cl_r6k::mode4k(void)
{
  cl_r5k::mode4k();
  itab[0x43]= instruction_wrapper_6k11_43;
}


/* End of rxk.src/r6k.cc */
