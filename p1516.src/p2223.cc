/*
 * Simulator of microcontrollers (p2223.cc)
 *
 * Copyright (C) 2020,20 Drotos Daniel, Talker Bt.
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

#include "glob.h"

#include "p2223cl.h"


CLP2::cl_p2223(class cl_sim *asim):
  cl_p1516(asim)
{
}

int
CLP2::init(void)
{
  cl_p1516::init();
  return 0;
}
  
const char *
CLP2::id_string(void)
{
  return "p2223";
}

struct dis_entry *
CLP2::dis_tbl(void)
{
  return(disass_p2223);
}

char *
CLP2::disassc(t_addr addr, chars *comment)
{
  chars work= chars(), temp= chars();
  const char *b;
  t_mem code, data= 0;
  int i;

  code= rom->get(addr);
  
  i= 0;
  while ((code & dis_tbl()[i].mask) != dis_tbl()[i].code &&
	 dis_tbl()[i].mnemonic)
    i++;
  if (dis_tbl()[i].mnemonic == NULL)
    {
      return strdup("-- UNKNOWN/INVALID");
    }
  b= dis_tbl()[i].mnemonic;

  data= (code&0xf0000000)>>28;
  if (((data & 1) == 0) || (dis_tbl()[i].branch == 'M'))
    work.append("   ");
  else
    {
      switch (data>>2)
	{
	case 0: work.append("S"); break;
	case 1: work.append("C"); break;
	case 2: work.append("Z"); break;
	case 3: work.append("O"); break;
	}
      if (data&2)
	work.append("1 ");
      else
	work+= "0 ";
    }

  while (*b)
    {
      if (*b == '%')
	{
	  b++;
	  switch (*(b++))
	    {
	    case 'd': // Rd
	      data= (code & 0x00f00000)>>20;
	      work.appendf("r%d", data);
	      break;
	    case 'a': // Ra
	      data= (code & 0x000f0000)>>16;
	      work.appendf("r%d", data);
	      break;
	    case 'R': // Ra in LD, ST
	      data= (code & 0x000f0000)>>16;
	      work.appendf("r%d", data);
	      if (comment)
		{
		  chars n= "";
		  addr_name(R[data], rom, &n);
		  comment->format("; [%08x%s]= %08x",
				  R[data],
				  n.c_str(),
				  rom->get(R[data]));
		}
	      break;
	    case 'b': // Rb
	      data= (code & 0x0000f000)>>12;
	      work.appendf("r%d", data);
	      break;
	    case '0': // LDL0
	      data= (code & 0x0000ffff);
	      work.appendf("0x0000%04x", data);
	      addr_name(data, rom, &work);
	      break;
	    case 'O': // LDL0 -> jump
	      data= (code & 0x0000ffff);
	      work.appendf("0x%04x", data);
	      addr_name(data, rom, &work);
	      break;
	    case 'l': // LDL
	      data= (code & 0x0000ffff);
	      work.appendf("0x....%04x", data);
	      break;
	    case 'h': // LDH
	      data= (code & 0x0000ffff);
	      work.appendf("0x%04x....", data);
	      break;
	    case 'A': // CALL
	      data= (code & 0x07ffffff);
	      work.appendf("0x%x", data);
	      addr_name(data, rom, &work);
	      break;
	    default:
	      temp= "?";
	      break;
	    }
	  if (comment && temp.nempty())
	    comment->append(temp);
	}
      else
	work.append(*(b++));
    }

  return strdup(work.c_str());
}

/*
void
CLP2::analyze_start(void)
{
}
*/

void
CLP2::analyze(t_addr addr)
{
  struct dis_entry *de;
  int i;
  
  while (!inst_at(addr))
    {
      t_mem code= rom->read(addr);
      i= 0;
      while ((code & dis_tbl()[i].mask) != dis_tbl()[i].code &&
	     dis_tbl()[i].mnemonic)
	i++;
      de= &dis_tbl()[i];
      if (de->mnemonic == NULL)
	return;
      set_inst_at(addr);
      if (de->branch!=' ')
	switch (de->branch)
	  {
	  case 'x': case '_': // non-followable
	    return;
	  case 'M': // LDL0 r15,#imm
	    {
	      t_addr target= rom->read(addr) & 0xffff;
	      analyze_jump(addr, target, de->branch);
	      break;
	    }
	  }
      addr= rom->validate_address(addr+1);
    }
}


bool
CLP2::cond(t_mem code)
{
  t_mem cond= (code & 0xf0000000) >> 28;
  u8_t n= (F&N)?1:0, v= (F&V)?1:0;
  switch (cond)
    {
    case 0x0: return true;		// AL
    case 0x1: return F&Z;		// EQ
    case 0x2: return !(F&Z);		// NE
    case 0x3: return F&C;		// CS HS
    case 0x4: return !(F&C);		// CC LO
    case 0x5: return F&S;		// MI
    case 0x6: return !(F&S);		// PL
    case 0x7: return F&O;		// VS
    case 0x8: return !(F&O);		// VC
    case 0x9: return (F&C) && !(F&Z);	// HI
    case 0xa: return !(F&C) || (F&Z);	// LS
    case 0xb: return !(n^v);		// GE
    case 0xc: return n^v;		// LT
    case 0xd: return !(F&Z) && !(n^v);	// GT
    case 0xe: return (F&Z) || (n^v);	// LE
    }
  return true;
}

int
CLP2::exec_inst(void)
{
  t_mem code;
  u8_t inst;
  u8_t cond;
  bool fe;
  
  PC= R[15];
  instPC= PC;
  fe= fetch(&code);
  tick(1);
  R[15]= PC;
  if (fe)
    return(resBREAKPOINT);

  cond= (code & 0xf0000000) >> 28;
  if ((cond&1) == 1)
    {
      u8_t flag= 0, fv, v;
      switch (cond>>2)
	{
	case 0: flag= F&S; break;
	case 1: flag= F&C; break;
	case 2: flag= F&Z; break;
	case 3: flag= F&O; break;
	}
      fv= flag?1:0;
      v= (cond&2)?1:0;
      if (fv != v)
	return resGO;
    }
  
  inst= (code & 0x0f000000) >> 24;
  if (code & 0x08000000)
    {
      // CALL
      t_addr data= (code & 0x07ffffff);
      RC[14]->W(R[15]);
      RC[15]->W(PC= data);
      return resGO;
    }

  /*u8_t d, a;
  d= (code & 0x00f00000) >> 20;
  a= (code & 0x000f0000) >> 16;*/
  switch (inst)
    {
    case 0: // nop
      break;
    }
  PC= R[15];
  
  return resGO;
}

/* End of p1516.src/p2223.cc */
