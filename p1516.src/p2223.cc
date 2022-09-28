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
  chars work= chars(), temp= chars(), fmt;
  const char *b;
  t_mem code, data= 0;
  int i;
  bool first= true;
  t_addr a;
    
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

  work= "";
  
  data= (code&0xf0000000)>>28;
  if ((dis_tbl()[i].branch == 'M'))
    work.append("   ");
  else
    {
      switch (data)
	{
	case   0: work.append("   "); break;
	case   1: work.append("EQ "); break;
	case   2: work.append("NE "); break;
	case   3: work.append("CS "); break;
	case   4: work.append("CC "); break;
	case   5: work.append("MI "); break;
	case   6: work.append("PL "); break;
	case   7: work.append("VS "); break;
	case   8: work.append("VC "); break;
	case 0x9: work.append("HI "); break;
	case 0xA: work.append("LS "); break;
	case 0xB: work.append("GE "); break;
	case 0xC: work.append("LT "); break;
	case 0xD: work.append("GT "); break;
	case 0xE: work.append("LE "); break;
	case 0xF: work.append("   "); break;
	}
    }

  first= true;
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
	  if (strcmp(fmt.c_str(), "*Ra") == 0)
	    {
	      data= (code & 0x000f0000)>>16;
	      work.appendf("*r%d", data);
	    }
	  if (strcmp(fmt.c_str(), "ar") == 0)
	    {
	      // CALL abs/rel
	      if (F & A)
		{
		  work.appendf("0x%x", a= (code & 0x03ffffff));
		}
	      else
		{
		  i32_t ia;
		  ia= (code & 0x03ffffff);
		  if (ia    & 0x02000000)
		    ia|= 0xfc000000;
		  a= addr+1+ia;
		  work.appendf("pc%c0x%x", (ia<0)?'-':'+', (ia<0)?-ia:ia);
		  if (comment)
		    comment->format("; 0x%x", a);
		}
	    }
	  if (strcmp(fmt.c_str(), "s20") == 0)
	    {
	      // CALL Rd,s20 ; indexed
	      i32_t ia= (code & 0x000fffff);
	      if (ia & 0x00080000) ia|= 0xfff00000;
	      data= (code & 0x00f00000)>>20;
	      work.appendf("r%d,%c0x%x", data, (ia<0)?'-':'+', (ia<0)?-ia:ia);
	      a= R[data]+ia;
	      if (comment)
		comment->format("; 0x%x%c0x%x=0x%x", R[data],
				(ia<0)?'-':'+',
				(ia<0)?-ia:ia, a);
	    }
	  
	}
      if (b[i] == '%')
	{
	  b++;
	  switch (b[i])
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
	      data= (code & 0x00000f00)>>8;
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
	work+= b[i];
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
