/*
 * Simulator of microcontrollers (pdk16.cc)
 *
 * Copyright (C) @@S@@,@@Y@@ Drotos Daniel, Talker Bt.
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

#include "pdk16cl.h"


cl_fppa16::cl_fppa16(int aid, class cl_pdk *the_puc, class cl_sim *asim):
  cl_fppa15(aid, the_puc, asim)
{
  type= new struct cpu_entry;
  type->type= CPU_PDK16;
}

cl_fppa16::cl_fppa16(int aid, class cl_pdk *the_puc, struct cpu_entry *IType, class cl_sim *asim):
  cl_fppa15(aid, the_puc, IType, asim)
{
}


int
cl_fppa16::init(void)
{
  cl_fppa::init();
  return 0;
}

const char *
cl_fppa16::id_string(void)
{
  return "pdk16";
}
/*
void
cl_fppa16::reset(void)
{
  cl_fppa::reset();
}
*/
int
cl_fppa16::execute(unsigned int code)
{
  switch (code & 0xffff)
    {
    case 0x0032: //push af
      return resGO;
    case 0x0033: // pop af
      return resGO;
    case 0x0010: // addc a
      return resGO;
    case 0x0011: // subc a
      return resGO;
    case 0x001a: // sr a
      return resGO;
    case 0x001c: // src a
      return resGO;
    case 0x001b: // sl a
      return resGO;
    case 0x001d: // slc a
      return resGO;
    case 0x001e: // swap a
      return resGO;
    case 0x0018: // not a
      return resGO;
    case 0x0019: // neg a
      return resGO;
    case 0x003c: // mul
      return resGO;
    case 0x0012: // izsn a
      return resGO;
    case 0x0013: // dzsn a
      return resGO;
    case 0x001f: // delay a
      return resGO;
    case 0x003a: // ret
      return resGO;
    case 0x003b: // reti
      return resGO;
    case 0x0000: // nop
      return resGO;
    case 0x0017: // pcadd a
      return resGO;
    case 0x0038: // engint
      return resGO;
    case 0x0039: // disgint
      return resGO;
    case 0x0036: // stopsys
      return resGO;
    case 0x0037: // stopexe
      return resGO;
    case 0x0035: // reset
      return resGO;
    case 0x0030: // wdtreset
      return resGO;
    }

  switch (code & 0xfff0)
    {
    case 0x0070: // pushw pcN
      return resGO;
    case 0x0060: // popw pcN
      return resGO;
    }

  switch (code & 0xffe0)
    {
    case 0x0040: // pmode k
      return resGO;
    }

  switch (code & 0xffc0)
    {
    case 0x00c0: // mov a,IO
      return resGO;
    case 0x0080: // mov IO,a
      return resGO;
    case 0x1040: // xor a,IO
      return resGO;
    case 0x1000: // xor IO,a
      return resGO;
    }

  switch (code & 0xff00)
    {
    case 0x1f00: // mov a.i
      return resGO;
    case 0x1800: // add a,i
      return resGO;
    case 0x1900: // sub a,i
      return resGO;
    case 0x1c00: // and a,i
      return resGO;
    case 0x1d00: // or a,i
      return resGO;
    case 0x1e00: // xor a,i
      return resGO;
    case 0x1a00: // ceqsn a,i
      return resGO;
    case 0x1b00: // cneqsn a,i
      return resGO;
    case 0x0e00: // delay i
      return resGO;
    case 0x0f00: // ret i
      return resGO;
    }

  switch (code & 0xfe00)
    {
    case 0x5c00: //
      return resGO;
    case 0x5e00: //
      return resGO;
    case 0x3200: //
      return resGO;
    case 0x3000: //
      return resGO;
    case 0x0400: //
      return resGO;
    case 0x0a00: //
      return resGO;
    case 0x0200: //
      return resGO;
    case 0x6e00: //
      return resGO;
    case 0x6c00: //
      return resGO;
    case 0x0800: //
      return resGO;
    case 0x4200: //
      return resGO;
    case 0x4000: //
      return resGO;
    case 0x4500: //
      return resGO;
    case 0x4800: //
      return resGO;
    case 0x6000: //
      return resGO;
    case 0x3400: //
      return resGO;
    case 0x3600: //
      return resGO;
    case 0x4600: //
      return resGO;
    case 0x4400: //
      return resGO;
    case 0x4e00: //
      return resGO;
    case 0x4c00: //
      return resGO;
    case 0x6200: //
      return resGO;
    case 0x6800: //
      return resGO;
    case 0x6a00: //
      return resGO;
    case 0x7400: //
      return resGO;
    case 0x7800: //
      return resGO;
    case 0x7600: //
      return resGO;
    case 0x7a00: //
      return resGO;
    case 0x7c00: //
      return resGO;
    case 0x5200: //
      return resGO;
    case 0x5000: //
      return resGO;
    case 0x5600: //
      return resGO;
    case 0x5400: //
      return resGO;
    case 0x5a00: //
      return resGO;
    case 0x5800: //
      return resGO;
    case 0x7000: //
      return resGO;
    case 0x7200: //
      return resGO;
    case 0x3c00: //
      return resGO;
    case 0x3e00: //
      return resGO;
    case 0x2400: //
      return resGO;
    case 0x2600: //
      return resGO;
    case 0x2e00: //
      return resGO;
    case 0x3800: //
      return resGO;
    case 0x3a00: //
      return resGO;
    case 0x1600: //
      return resGO;
    case 0x1400: //
      return resGO;
    case 0x2000: //
      return resGO;
    case 0x2200: //
      return resGO;
    case 0x6400: //
      return resGO;
    case 0x6600: //
      return resGO;
    case 0x2a00: //
      return resGO;
    case 0x2c00: //
      return resGO;
    case 0x0600: //
      return resGO;
    case 0x7e00: //
      return resGO;
    }

  switch (code & 0xf000)
    {
    case 0xa000: // set0 M,n
      return resGO;
    case 0xb000: // set1 M,n
      return resGO;
    case 0x8000: // t0sn M,n
      return resGO;
    case 0x9000: // t1sn M,n
      return resGO;
    }

  switch (code & 0xe000)
    {
    case 0xe000: // call label
      return resGO;
    case 0xc000: // call label
      return resGO;
    }
  
  return resINV;
}


/* End of pdk.src/pdk16.cc */
