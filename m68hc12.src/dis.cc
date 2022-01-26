/*
 * Simulator of microcontrollers (dis.cc)
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

#include "glob12.h"

#include "m68hc12cl.h"


struct dis_entry *
cl_m68hc12::dis_tbl(void)
{
  return disass12p0;
}

struct dis_entry *
cl_m68hc12::get_dis_entry(t_addr addr)
{
  struct dis_entry *dt= dis_tbl();//, *dis_e;
  int i= 0;
  t_mem code= rom->get(addr);

  if (dt == NULL)
    return NULL;
  while (((code & dt[i].mask) != dt[i].code) &&
	 dt[i].mnemonic)
    i++;
  return &dt[i];

}



char *
cl_m68hc12::disassc(t_addr addr, chars *comment)
{
  chars work= chars(), temp= chars();
  const char *b;
  //t_mem code= rom->get(addr);
  struct dis_entry *dis_e;
  int i;
  bool first;
  
  if ((dis_e= get_dis_entry(addr)) == NULL)
    return NULL;
  if (dis_e->mnemonic == NULL)
    return strdup("-- UNKNOWN/INVALID");
  b= dis_e->mnemonic;

  first= true;
  work= "";
  for (i=0; b[i]; i++)
    {
      if ((b[i] == ' ') && first)
	{
	  first= false;
	  while (work.len() < 6) work.append(' ');
	}
      if (b[i] == '%')
	{
	  t_addr a;
	  u8_t h, l;
	  i++;
	  temp= "";
	  switch (b[i])
	    {
	    case 'x': case 'X': // indexed
	      h= rom->read(addr+1);
	      a= rX+h;
	      work.appendf("$%02x,X", h);
	      //add_spaces(&work, 20);
	      if (b[i]=='x')
		temp.appendf("; [$%04x]=$%02x", a, rom->read(a));
	      else
		temp.appendf("; [$%04x]=$%04x", a, read_addr(rom, a));
	      break;
	    case 'e': case 'E': // extended
	      h= rom->read(addr+1);
	      l= rom->read(addr+2);
	      a= h*256 + l;
	      work.appendf("$%04x", a);
	      //add_spaces(&work, 20);
	      if (b[i]=='e')
		temp.appendf("; [$%04x]=$%02x", a, rom->read(a));
	      else
		temp.appendf("; [$%04x]=$%04x", a,
			     read_addr(rom, a));
	      break;
	    case 'd': case 'D': // direct
	      h= a= rom->read(addr+1);
	      work.appendf("$00%02x", h);
	      //add_spaces(&work, 20);
	      if (b[i]=='d')
		temp.appendf("; [$%04x]=$%02x", a, rom->read(a));
	      else
	        temp.appendf("; [$%04x]=$%04x", a,
			     read_addr(rom, a));
	      break;
	    case 'b': // immediate 8 bit
	      work.appendf("#$%02x",
			   rom->read(addr+1));
	      break;
	    case 'B': // immediate 16 bit
	      work.appendf("#$%04x",
			   read_addr(rom, addr+1));
	      break;
	    case 'r': // relative
	      work.appendf("$%04x",
			   (addr+2+(i8_t)(rom->read(addr+1))) & 0xffff );
	      break;
	    case 'p': // xb postbyte
	      {
		t_addr a= addr+1;
		disass_xb(&a, &work, comment);
		addr= a;
		break;
	      }
	    case 'T': // TFR/EXG
	      disass_b7(&a, &work, comment);
	    }
	  //work+= temp;
	  if (comment && temp.nempty())
	    comment->append(temp);
	}
      else
	work+= b[i];
    }

  return(strdup(work.c_str()));
}

const char *rr_names[4]= { "X", "Y", "SP", "PC" };

void
CL12::disass_xb(t_addr *addr, chars *work, chars *comment)
{
  u8_t p, h, l;
  int rr= -1;
  i16_t ival= 0, offset= 0;
  t_addr aof_xb= *addr, a;
  
  p= rom->read(aof_xb);
  (*addr)++;
  
  if ((p & 0x20) == 0)
    {
      // 1. rr0n nnnn n5,r rr={X,Y,SP,PC}
      rr= (p>>6)&3;
      offset= p&0x1f;
      if (p&0x10) offset|= 0xffe0;
      if (offset)
	work->appendf("%+d,", offset);
      work->appendf("%s", rr_names[rr]);
    }
  
  else if ((p&0xe7) == 0xe7)
    {
      // 6. 111r r111 [D,r] rr={X,Y,SP,PC}
      work->appendf("[D,%s]", rr_names[(p&0x18)>>3]);
      switch (p & 0x18)
	{
	case 0x00: ival= rX; break;
	case 0x10: ival= rY; break;
	case 0x08: ival= rSP; break;
	case 0x18: ival= PC&0xffff; break;
	}
      offset= rD;
      a= ival+offset;
      //return read_addr(rom, a);
    }
  
  /*
  else if ((p&0xe7) == 0xe3)
    {
      // 5. 111r r011 [n16,r] rr={X,Y,SP,PC}
      switch (p & 0x18)
	{
	case 0x00: ival= rX; break;
	case 0x10: ival= rY; break;
	case 0x08: ival= rSP; break;
	case 0x18: ival= PC&0xffff; break;
	}
      h= fetch();
      l= fetch();
      offset= h*256+l;
      a= ival+offset;
      return read_addr(rom, a);
    }
  */
  /*
  else if ((p&0xc0) != 0xc0)
    {
      // 3. rr1p nnnn n4,+-r+- rr={X,Y,SP}
      switch (p & 0xc0)
	{
	case 0x00: ival= rX; post_idx_reg= &cX; break;
	case 0x40: ival= rY; post_idx_reg= &cY; break;
	case 0x80: ival= rSP; post_idx_reg= &cSP; break;
	}
      i8_t n= p&0xf;
      if (n&0x08) n|= 0xf0;
      if (p&0x10)
	{
	  // post +-
	  post_inc_dec= n;
	}
      else
	{
	  // pre +-
	  post_idx_reg->W(ival= (post_idx_reg->R() + n));
	}
      return ival;
    }
  */
  /*
  else if ((p&0xe4) == 0xe0)
    {
      // 2. 111r r0zs n9/16,r rr={X,Y,SP,PC}
      switch (p & 0x18)
	{
	case 0x00: ival= rX; break;
	case 0x10: ival= rY; break;
	case 0x08: ival= rSP; break;
	case 0x18: ival= PC&0xffff; break;
	}
      if ((p&0x02) == 0x00)
	{
	  // 9 bit
	  offset= fetch();
	  if (p&0x01) offset|= 0xff00;
	}
      else
	{
	  // 16 bit
	  h= fetch();
	  l= fetch();
	  offset= h*256+l;
	}
      return ival+offset;
    }
  */
  /*
  else // if ((p&0xe4) == 0xe4)
    {
      // 4. 111r r1aa {A,B,D},r rr={X,Y,SP,PC}
      switch (p & 0x18)
	{
	case 0x00: ival= rX; break;
	case 0x10: ival= rY; break;
	case 0x08: ival= rSP; break;
	case 0x18: ival= PC&0xffff; break;
	}
      switch (p&0x03)
	{
	case 0x00: offset= s8_16(rA); break;
	case 0x01: offset= s8_16(rB); break;
	case 0x02: offset= rD; break;
	}
      return ival+offset;
    }
  */
  a= naddr(&aof_xb);
  if (comment)
    {
      bool b= false;
      comment->append("; [");
      if (rr >= 0)
	comment->appendf("%s", rr_names[rr]), b= true;
      if (offset)
	comment->appendf("%+d", offset), b= true;
      if (b)
	comment->append("=");
      comment->appendf("%04x]=%02x", a, rom->read(a));
    }
  *addr= aof_xb;
}

void
CL12::disass_b7(t_addr *addr, chars *work, chars *comment)
{
  (*addr)++;
  u8_t pb= rom->read(*addr);
  if (pb & 0x08)
    work->append("TFR/EXG INVALID");
  else
    {
      if (!(pb & 0x80))
	work->append("TFR");
      else
	work->append("EXG");
      while (work->len() < 6) work->append(' ');
      u8_t ls= pb&7, ms= (pb>>4)&7;
      const char *nd= (ms==3)?("TEMP2"):(tex_names[ms]);
      work->appendf("%s", nd);
      work->append(",");
      work->appendf("%s", tex_names[ls]);
    }
}


/* End of m68hc12.src/dis.cc */
