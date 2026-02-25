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
#include "r6kwrap.h"

#include "r6kcl.h"


cl_r6k::cl_r6k(class cl_sim *asim):
  cl_r5k(asim)
{
}

const char *
cl_r6k::id_string(void)
{
  return "R6K";
}

int
cl_r6k::init(void)
{
  cl_r5k::init();
  fill_49_wrappers(itab_49);
  // 6k specific stuff on 7f page in 10 mode
  itab_7f10[0x43]= instruction_wrapper_6k11_43;
  itab_7f10[0x44]= instruction_wrapper_6k11_44;
  itab_7f10[0x4b]= instruction_wrapper_6k11_4b;
  itab_7f10[0x53]= instruction_wrapper_6k11_53;
  itab_7f10[0x59]= instruction_wrapper_6k11_59;
  itab_7f10[0x69]= instruction_wrapper_6k11_69;
  itab_7f10[0x80]= instruction_wrapper_6k11_80;
  itab_7f10[0x88]= instruction_wrapper_6k11_88;
  itab_7f10[0x90]= instruction_wrapper_6k11_90;
  // 6k specific stuff on ed pade
  itab_ed[0x86]= instruction_wrapper_6ked_86;
  itab_ed[0x87]= instruction_wrapper_6ked_87;
  itab_ed[0x96]= instruction_wrapper_6ked_96;
  itab_ed[0x97]= instruction_wrapper_6ked_97;
  itab_ed[0xa6]= instruction_wrapper_6ked_a6;
  itab_ed[0xa7]= instruction_wrapper_6ked_a7;
  itab_ed[0xb6]= instruction_wrapper_6ked_b6;
  itab_ed[0xb7]= instruction_wrapper_6ked_b7;
  itab_ed[0xc7]= instruction_wrapper_6ked_c7;
  itab_ed[0xd7]= instruction_wrapper_6ked_d7;
  itab_ed[0xf7]= instruction_wrapper_6ked_f7;
  return 0;
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
  itab[0x44]= instruction_wrapper_6k11_44;
  itab[0x4b]= instruction_wrapper_6k11_4b;
  itab[0x53]= instruction_wrapper_6k11_53;
  itab[0x59]= instruction_wrapper_6k11_59;
  itab[0x69]= instruction_wrapper_6k11_69;
  itab[0x80]= instruction_wrapper_6k11_80;
  itab[0x88]= instruction_wrapper_6k11_88;
  itab[0x90]= instruction_wrapper_6k11_90;
}

int
cl_r6k::EX_JKHL_BCDE_(MP)
{
  u32_t t;
  if (altd)
    {
      t= rJKHL;
      cJKHL.W(raBCDE);
      caBCDE.W(t);
    }
  else
    {
      t= raJKHL;
      caJKHL.W(raBCDE);
      caBCDE.W(t);
    }
  return resGO;
}

int
cl_r6k::MUL_HL_DE(MP)
{
  i32_t a= (i16_t)rHL;
  i32_t b= (i16_t)rDE;
  destJKHL().W(a * b);
  tick(10);
  return resGO;
}

int
cl_r6k::MULU_HL_DE(MP)
{
  destJKHL().W((u32_t)rHL * (u32_t)rDE);
  tick(11);
  return resGO;
}

int
cl_r6k::tstnull_pp(u32_t pp)
{
  class cl_cell8 &rf= destF();
  u8_t f= rF & ~(flagZ|flagC);
  if (pp == 0xffff0000)
    f|= (flagZ|flagC);
  if (pp == 0)
    f|= flagZ;
  rf.W(f);
  tick(3);
  return resGO;
}

int
cl_r6k::swap_r(u8_t sr, C8 &dr)
{
  u8_t v2= 0;
  int i, m;
  for (i= 0, m= 0x80; i<8; i++, m>>=1)
    {
      v2>>= 1;
      v2|= ((sr&m)?0x80:0);
    }
  dr.W(v2);
  tick(3);
  return resGO;
}


/* End of rxk.src/r6k.cc */
