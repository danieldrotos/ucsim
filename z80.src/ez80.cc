/*
 * Simulator of microcontrollers (ez80.cc)
 *
 * Copyright (C) 1999,99 Drotos Daniel, Talker Bt.
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

#include "ez80cl.h"

struct dis_entry disass_ez80_ed[]=
  {
   { 0x000f, 0x00ff, ' ', 1, "LD (HL),BC" },
   { 0x001f, 0x00ff, ' ', 1, "LD (HL),DE" },
   { 0x002f, 0x00ff, ' ', 1, "LD (HL),HL" },
   { 0x0037, 0x00ff, ' ', 1, "LD IX,(HL)" },
   { 0x0031, 0x00ff, ' ', 1, "LD IY,(HL)" },
   { 0x0007, 0x00ff, ' ', 1, "LD BC,(HL)" },
   { 0x0017, 0x00ff, ' ', 1, "LD DE,(HL)" },
   { 0x0027, 0x00ff, ' ', 1, "LD HL,(HL)" },
   { 0, 0, 0, 0, NULL }
  };

cl_ez80::cl_ez80(struct cpu_entry *Itype, class cl_sim *asim):
	cl_z80(Itype, asim)
{
}

int
cl_ez80::init(void)
{
  return cl_z80::init();
}

char *
cl_ez80::id_string(void)
{
  return ((char*)"EZ80");
}


const char *
cl_ez80::get_disasm_info(t_addr addr,
			 int *ret_len,
			 int *ret_branch,
			 int *immed_offset,
			 struct dis_entry **dentry)
{
  const char *b = NULL;
  uint code;
  t_addr addr_org= addr;
  int start_addr = addr;
  int i;
  int len= 0;
  int immed_n = 0;
  struct dis_entry *dis_e= NULL;
  
  code= rom->get(addr++);
  switch (code)
    {
    case 0xed:
      code= rom->get(addr++);
      i= 0;
      while ((code & disass_ez80_ed[i].mask) != disass_ez80_ed[i].code &&
	     disass_ez80_ed[i].mnemonic)
	i++;
      dis_e= &disass_ez80_ed[i];
      b= dis_e->mnemonic;
      if (b == NULL)
	return cl_z80::get_disasm_info(addr_org, ret_len, ret_branch, immed_offset, dentry);
      len+= dis_e->length+1;
      break;
    }

  if (ret_branch)
    *ret_branch = dis_e->branch;

  if (immed_offset) {
    if (immed_n > 0)
         *immed_offset = immed_n;
    else *immed_offset = (addr - start_addr);
  }

  if (len == 0)
    len = 1;

  if (ret_len)
    *ret_len = len;

  if (dentry)
    *dentry= dis_e;
  
  return b;
}

int
cl_ez80::inst_ed_ez80(t_mem code)
{
  switch (code)
    {
    case 0x0f: // LD (HL),BC
      store2(regs.HL, regs.BC);
      return resGO;
    case 0x1f: // LD (HL),DE
      store2(regs.HL, regs.DE);
      return resGO;
    case 0x2f: // LD (HL),HL
      store2(regs.HL, regs.HL);
      return resGO;
    case 0x37: // LD IX,(HL)
      regs.IX= get2(regs.HL);
      return resGO;
    case 0x31: // LD IY,(HL)
      regs.IY= get2(regs.HL);
      return resGO;
    case 0x07: // LD BC,(HL)
      regs.BC= get2(regs.HL);
      return resGO;
    case 0x17: // LD DE,(HL)
      regs.DE= get2(regs.HL);
      return resGO;
    case 0x27: // LD HL,(HL)
      regs.HL= get2(regs.HL);
      return resGO;
    default: // fall back to original Z80
      return inst_ed_(code);
    }
}

int
cl_ez80::inst_ed(void)
{
  t_mem code;

  if (fetch(&code))
    return (resBREAKPOINT);

  return inst_ed_ez80(code);
}

/* End of z80.src/ez80.cc */
