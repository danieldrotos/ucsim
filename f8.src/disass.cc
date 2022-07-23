/*
 * Simulator of microcontrollers (disass.cc)
 *
 * Copyright (C) 2022 Drotos Daniel, Talker Bt.
 * 
 * To contact author send email to drdani@mazsola.iit.uni-miskolc.hu
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

#include "f8cl.h"


struct dis_entry *
cl_f8::dis_tbl(void)
{
  return(disass_f8);
}

struct dis_entry *
cl_f8::get_dis_entry(t_addr addr)
{
  t_mem code= rom->get(addr);
  int i= 0;
  while ((code & PREF)==PREF)
    {
      i++;
      code= rom->get(addr+i);
    }
  for (struct dis_entry *de = disass_f8; de && de->mnemonic; de++)
    {
      if ((code & de->mask) == de->code)
        return de;
    }

  return NULL;
}

char *
cl_f8::disassc(t_addr addr, chars *comment)
{
  chars work= chars(), temp= chars(), fmt= chars();
  const char *b;
  struct dis_entry *de;
  int i, prefs= P_NONE;
  bool first;
  u8_t /*h, l, r,*/ code;
  u16_t a;

  code= rom->get(addr);
  while ((code & PREF)==PREF)
    {
      code&= ~PREF;
      code>>= PREF_SHIFT;
      prefs|= (1 << code);
      code= rom->get(++addr);
    }
  de= get_dis_entry(addr);
  //code= rom->read(addr);
  
  if (!de || !de->mnemonic)
    return strdup("-- UNKNOWN/INVALID");

  b= de->mnemonic;

  first= true;
  work= "";
  for (i=0; b[i]; i++)
    {
      if ((b[i] == ' ') && first)
	{
	  first= false;
	  while (work.len() < 6) work.append(' ');
	}
      if (b[i] == '\'')
	{
	  fmt= "";
	  i++;
	  while (b[i] && (b[i]!='\''))
	    fmt.append(b[i++]);
	  if (!b[i]) i--;
	  if (fmt.empty())
	    work.append("'");
	  if (strcmp(fmt.c_str(), "i8") == 0)
	    {
	      work.appendf("0x%02x", rom->read(addr+1));
	    }
	  if (strcmp(fmt.c_str(), "i16") == 0)
	    {
	      work.appendf("0x%04x", read_addr(rom, addr+1));
	    }
	  if (strcmp(fmt.c_str(), "a16") == 0)
	    {
	      a= read_addr(rom, addr+1);
	      work.appendf("0x%04x", a);
	    }
	  if (strcmp(fmt.c_str(), "a16_8") == 0)
	    {
	      a= read_addr(rom, addr+1);
	      work.appendf("0x%04x", a);
	      comment->appendf("; [0x%04x]= 0x%02x", a, rom->read(a));
	    }
	  if (strcmp(fmt.c_str(), "a16_16") == 0)
	    {
	      a= read_addr(rom, addr+1);
	      work.appendf("0x%04x", a);
	      comment->appendf("; [0x%04x]= 0x%04x", a, read_addr(rom, a));
	    }
	  continue;
	}
      if (b[i] == '%')
	{
	  i++;
	  temp= "";
	  switch (b[i])
	    {
	    }
	  if (comment && temp.nempty())
	    comment->append(temp);
	}
      else
	work+= b[i];
    }

  return(strdup(work.c_str()));
}


/* End of f8.src/disass.cc */
