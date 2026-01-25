/*
 * Simulator of microcontrollers (t870c.cc)
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
#include "glob.h"
#include "t870ccl.h"


// bit nr to bit mask converter
u8_t bit_mask[8]= { 1, 2, 4, 8, 16, 32, 64, 128 };


cl_t870c_psw_op::cl_t870c_psw_op(class cl_memory_cell *acell, class cl_t870c *auc):
  cl_memory_operator(acell)
{
  uc= auc;
}

t_mem
cl_t870c_psw_op::write(t_mem val)
{
  val&= 0xfc;
  return val;
}


cl_t870c::cl_t870c(class cl_sim *asim):
  cl_uc(asim)
{
  regs8[0]= &cA;
  regs8[1]= &cW;
  regs8[2]= &cC;
  regs8[3]= &cB;
  regs8[4]= &cE;
  regs8[5]= &cD;
  regs8[6]= &cL;
  regs8[7]= &cH;
  regs16[0]= &cWA;
  regs16[1]= &cBC;
  regs16[2]= &cDE;
  regs16[3]= &cHL;
  regs16[4]= &cIX;
  regs16[5]= &cIY;
  regs16[6]= &cSP;
  regs16[7]= &cHL;

  def_data= 0xff;

  uc_itab[0x01]= &cl_itab::invalid_instruction;
  uc_itab[0x02]= &cl_itab::invalid_instruction;
  uc_itab[0x03]= &cl_itab::invalid_instruction;
  
  uc_itab[0x68]= &cl_itab::invalid_instruction;
  uc_itab[0x69]= &cl_itab::invalid_instruction;
  uc_itab[0x6a]= &cl_itab::invalid_instruction;
  uc_itab[0x6b]= &cl_itab::invalid_instruction;
  uc_itab[0x6c]= &cl_itab::invalid_instruction;
  uc_itab[0x6d]= &cl_itab::invalid_instruction;
  uc_itab[0x6e]= &cl_itab::invalid_instruction;
  uc_itab[0x6f]= &cl_itab::invalid_instruction;

  uc_itab[0xf8]= &cl_itab::invalid_instruction;
  
  uc_itab[0x14f]= &cl_itab::invalid_instruction;
  uc_itab[0x17f]= &cl_itab::invalid_instruction;
  uc_itab[0x1df]= &cl_itab::invalid_instruction;
  uc_itab[0x1f8]= &cl_itab::invalid_instruction;
  uc_itab[0x1f9]= &cl_itab::invalid_instruction;
  uc_itab[0x1fc]= &cl_itab::invalid_instruction;

  uc_itab[0x24f]= &cl_itab::invalid_instruction;
  uc_itab[0x26f]= &cl_itab::invalid_instruction;

  uc_itab[0x2f1]= &cl_itab::invalid_instruction;
  uc_itab[0x2f4]= &cl_itab::invalid_instruction;
  uc_itab[0x2f5]= &cl_itab::invalid_instruction;
  uc_itab[0x2ff]= &cl_itab::invalid_instruction;
}

int
cl_t870c::init(void)
{
  cl_uc::init();
  mk_rbanks();
  
  reg_cell_var(&cW, &rW, "W", "W register");
  reg_cell_var(&cA, &rA, "A", "A register");
  reg_cell_var(&cB, &rB, "B", "B register");
  reg_cell_var(&cC, &rC, "C", "C register");
  reg_cell_var(&cD, &rD, "D", "D register");
  reg_cell_var(&cE, &rE, "E", "E register");
  reg_cell_var(&cH, &rH, "H", "H register");
  reg_cell_var(&cL, &rL, "L", "L register");
  reg_cell_var(&cF, &rF, "PSW", "PSW register");

  reg_cell_var(&cWA, &rWA, "WA", "WA register");
  reg_cell_var(&cBC, &rBC, "BC", "BC register");
  reg_cell_var(&cDE, &rDE, "DE", "DE register");
  reg_cell_var(&cHL, &rHL, "HL", "HL register");
  reg_cell_var(&cIX, &rIX, "IX", "IX register");
  reg_cell_var(&cIY, &rIY, "IY", "IY register");
  reg_cell_var(&cSP, &rSP, "SP", "SP register");

  part_init();
  return 0;
}

void
cl_t870c::part_init(void)
{
  class cl_memory_operator *o= new cl_t870c_psw_op(&cPSW, this);
  o->init();
  cPSW.append_operator(o);
  uc_itab[0xf9]= &cl_itab::invalid_instruction;
}

void
cl_t870c::mk_rbanks(void)
{
  rbanks= (struct rbank_870c_t *)malloc(sizeof(*rbanks));
  rbank= &rbanks[0];
}

void
cl_t870c::decode_regs(void)
{
  cW.decode(&rW);
  cA.decode(&rA);
  cB.decode(&rB);
  cC.decode(&rC);
  cD.decode(&rD);
  cE.decode(&rE);
  cH.decode(&rH);
  cL.decode(&rL);
}


void
cl_t870c::make_memories(void)
{
  class cl_address_space *as;

  rom= asc= asd= as= new cl_address_space("nas", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  class cl_address_decoder *ad;
  class cl_memory_chip *chip;

  bootrom_chip= chip= new cl_chip8("bootrom_chip", 0x800, 8, 0xff);
  chip->init();
  memchips->add(chip);
  
  rom_chip= chip= new cl_chip8("rom_chip", 0x8000, 8, 0xff);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= rom,
                             chip, 0x8000, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
  
  int rs= 0x400 * 3;
  ram_chip= chip= new cl_chip8("ram_chip", rs, 8);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= rom,
                             chip, 0x40, 0x40+rs-1, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
  
  chip= new cl_chip8("sfr_chip", 64, 8, 0);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= rom,
                             chip, 0, 63, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);

  chip= new cl_chip8("dbr_chip", 128, 8, 0);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= rom,
                             chip, 0xf80, 0xfff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}


void
cl_t870c::make_cpu_hw(void)
{
  add_hw(cpu= new cl_t870c_cpu(this));
  cpu->init();
}


void
cl_t870c::reset(void)
{
  cl_uc::reset();
  PC= rom->read(0xffff) * 256 + rom->read(0xfffe);
  rSP= 0x00ff;
}


void
cl_t870c::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("JZCHSV--  Flags= 0x%02x  ", rF);
  con->dd_printf("A= 0x%02x %3d %c\n",
		 rA, rA, isprint(rA)?rA:'.');
  con->dd_printf("%s\n", cbin(rF,8).c_str());
  con->dd_printf("WA0=0x%04x [WA]=%02x  ", rWA, asd->read(rWA));
  con->dd_printf("BC0=0x%04x [BC]=%02x  ", rBC, asd->read(rBC));
  con->dd_printf("DE0=0x%04x [DE]=%02x\n", rDE, asd->read(rDE));
  con->dd_printf("HL0=0x%04x [HL]=%02x  ", rHL, asd->read(rHL));
  con->dd_printf("IX0=0x%04x [IX]=%02x  ", rIX, asd->read(rIX));
  con->dd_printf("IY0=0x%04x [IY]=%02x\n", rIY, asd->read(rIY));
  con->dd_printf("SP =0x%04x [SP]=%02x  ", rSP, asd->read(rSP));
  con->dd_printf("\n");
  print_disass(PC, con);
}


struct dis_entry *
cl_t870c::dis_tbl(void)
{
  return disass_t870c;
}

static const char *r_names[8]= { "A", "W", "C", "B", "E", "D", "L", "H" };
static const char *rr_names[8]= {
  "WA", "BC", "DE", "HL", "IX", "IY", "SP", "HL"
};
static const char *dstF[8]= {
  "x", "vw", "DE", "HL", "IX", "IY", "SP-", "HL+C"
};
static const char *dst5[4]= {
  "IX", "IY", "SP", "HL"
};
static const char *srcE[8]= {
  "x", "vw", "DE", "HL", "IX", "IY", "+SP", "HL+C"
};
static const char *srcD[4]= {
  "IX", "IY", "SP", "HL"
};
static const char *cc[16]= {
  "M",
  "P",
  "SLT",
  "SGE",
  "SLE",
  "SGT",
  "VS",
  "VC",

  "EQ/Z",
  "NE/NZ",
  "LT/CS",
  "GE/CC",
  "LE",
  "GT",
  "T",
  "F"
};

/* Byte index +1 */
static const u8_t code_loc[256]= {
  /* 0 */ 1,0,0,0, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* 1 */ 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* 2 */ 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* 3 */ 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* 4 */ 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,2,
  /* 5 */ 1,1,1,1, 3,3,3,3, 1,1,1,1, 1,1,1,1,
  /* 6 */ 1,1,1,1, 1,1,1,1, 0,0,0,0, 0,0,0,0,
  /* 7 */ 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* 8 */ 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* 9 */ 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* a */ 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* b */ 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* c */ 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* d */ 1,1,1,1, 3,3,3,3, 1,1,1,1, 1,1,1,1,
  /* e */ 3,4,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,
  /* f */ 3,4,2,2, 2,2,2,2, 0,1,1,1, 1,1,1,1
};

struct dis_entry *
cl_t870c::get_dis_entry(t_addr addr)
{
  t_mem code32;
  u8_t code0, code1, code2, code3, code4;
  int i;
  struct dis_entry *dtab, *de;
  
  code0= rom->get(addr);
  code1= rom->get(addr+1);
  code2= rom->get(addr+2);
  code3= rom->get(addr+3);
  code4= rom->get(addr+4);
  code32= (code3<<24) | (code2<<16) | (code1<<8) | (code0<<0);

  if ((dtab= dis_tbl()) == NULL)
    return NULL;
  u32_t cloc, cmask;
  cloc= code_loc[code0]-1;
  cmask= 0x000000ff << (8*cloc);
  if ((code0 == 0xf9) && (type->type == CPU_TLCS870C))
    return NULL;
  i= 0;
  while (
	 ((code32 & dtab[i].mask) != dtab[i].code ||
	  !(dtab[i].mask & cmask))
	 &&
	 dtab[i].mnemonic)
    i++;
  de= &dtab[i];
  return de;
}

char *
cl_t870c::disassc(t_addr addr, chars *comment)
{
  chars work= chars(), temp= chars(), fmt;
  const char *b;
  t_mem code, code32, data= 0;
  u8_t code0, code1, code2, code3, code4;
  int i;
  bool first;
  u16_t u16;
  struct dis_entry *dtab, *de;
  
  code= code0= rom->get(addr);
  code1= rom->get(addr+1);
  code2= rom->get(addr+2);
  code3= rom->get(addr+3);
  code4= rom->get(addr+4);
  code32= (code3<<24) | (code2<<16) | (code1<<8) | (code0<<0);

  if (((de= get_dis_entry(addr)) == NULL) || (de->mnemonic == NULL))
    return strdup("UNKNOWN/INVALID");
  b= de->mnemonic;
  
  first= true;
  for (i=0; b[i]; i++)
    {
      if ((b[i] == ' ') && first)
	{
	  first= false;
	  while (work.len() < 8) work.append(' ');
	}
      if (b[i] == '\'')
	{
	  fmt= "";
	  i++;
	  while (b[i] && (b[i]!='\''))
	    fmt.append(b[i++]);
	  if (!b[i]) i--;
	  if (fmt.empty()) work.append("'");
	  else if (fmt=="r_0.0")  work.append(r_names[code0&7]);
	  else if (fmt=="r_0.3")  work.append(r_names[(code0&0X38)>>3]);
	  else if (fmt=="r_1.0")  work.append(r_names[code1&7]);
	  else if (fmt=="r_1.3")  work.append(r_names[(code1&0x38)>>3]);
	  else if (fmt=="r_2.0")  work.append(r_names[code2&7]);
	  else if (fmt=="r_2.3")  work.append(r_names[(code2&0x38)>>3]);
	  else if (fmt=="r_3.0")  work.append(r_names[code3&7]);
	  else if (fmt=="r_3.3")  work.append(r_names[(code3&0x38)>>3]);
	  else if (fmt=="rr_0.0") work.append(rr_names[code0&7]);
	  else if (fmt=="rr_0.3") work.append(rr_names[(code0&0x38)>>3]);
	  else if (fmt=="rr_1.0") work.append(rr_names[code1&7]);
	  else if (fmt=="rr_1.3") work.append(rr_names[(code1&0x38)>>3]);
	  else if (fmt=="rr_2.0") work.append(rr_names[code2&7]);
	  else if (fmt=="rr_2.3") work.append(rr_names[(code2&0x38)>>3]);
	  else if (fmt=="rr_3.0") work.append(rr_names[code3&7]);
	  else if (fmt=="rr_3.3") work.append(rr_names[(code3&0x38)>>3]);
	  else if (fmt=="n_1")    work.appendf("0x%02x", code1);
	  else if (fmt=="n_2")    work.appendf("0x%02x", code2);
	  else if (fmt=="n_3")    work.appendf("0x%02x", code3);
	  else if (fmt=="n_4")    work.appendf("0x%02x", code4);
	  else if (fmt=="mn_1")   work.appendf("0x%04x", code1+code2*256);
	  else if (fmt=="mn_2")   work.appendf("0x%04x", code2+code3*256);
	  else if (fmt=="mn_3")   work.appendf("0x%04x", code3+code4*256);
	  else if (fmt=="b_0.0")  work.appendf("%d", code0&7);
	  else if (fmt=="b_1.0")  work.appendf("%d", code1&7);
	  else if (fmt=="b_2.0")  work.appendf("%d", code2&7);
	  else if (fmt=="b_3.0")  work.appendf("%d", code3&7);
	  else if (fmt=="rr_0.0h")work.append(rr_names[code0&7][0]);
	  else if (fmt=="rr_0.0l")work.append(rr_names[code0&7][1]);
	  else if (fmt=="cc")     work.append(cc[code0&0xf]);
	  else if (fmt=="cc1")    work.append(cc[code1&0xf]);
	  else if (fmt=="vw")
	    {
	      work.appendf("0x%04x", u16= code1+code2*256);
	      if (comment)
		comment->appendf("; %02x %02x",
				 asd->read(u16), asd->read(u16+1));
	    }
	  else if (fmt=="dstF")
	    {
	      work.appendf("%s", dstF[code0&7]);
	      if (comment)
		{
		  u16_t a= aof_dstF(code32);
		  comment->appendf("; [%04] %02x %02x",
				   a, asd->read(a), asd->read(a+1));
		}
	    }
	  else if (fmt=="dst5")
	    {
	      i8_t d= code1;
	      work.appendf("%s", dst5[code0&3]);
	      if (d<0)
		{
		  d= -d;
		  code1= d;
		  work.appendf("-%02x", code1);
		}
	      else
		work.appendf("+%02x", code1);
	      if (comment)
		{
		  u16_t a= aof_dst5(code32);
		  comment->appendf("; [%04x] %02x %02x",
				   a, asd->read(a), asd->read(a+1));
		}
	    }
	  else if (fmt=="srcE")
	    {
	      work.appendf("%s", srcE[code0&7]);
	      if (comment)
		{
		  u16_t a= aof_srcE(code32);
		  comment->appendf("; [%04x] %02x %02x",
				   a, asd->read(a), asd->read(a+1));
		}
	    }
	  else if (fmt=="srcD")
	    {
	      i8_t d= code1;
	      work.appendf("%s", srcD[code0&3]);
	      if (d<0)
		{
		  d= -d;
		  code1= d;
		  work.appendf("-0x%02x", code1);
		}
	      else
		work.appendf("+0x%02x", code1);
	      if (comment)
		{
		  u16_t a= aof_srcD(code32);
		  comment->appendf("; [%04x] %02x %02x",
				   a, asd->read(a), asd->read(a+1));
		}
	    }
	  else if (fmt=="src4")
	    {
	      work.appendf("PC+A");
	      if (comment)
		{
		  u16_t a= (i8_t)rA + addr + 2;
		  comment->appendf("; [%04x] %02x %02x",
				   a, asd->read(a), asd->read(a+1));
		}
	    }
	  else if (fmt=="ra5")
	    {
	      i16_t d= code0 & 0x1f;
	      if (d & 0x10) d|= 0xffe0;
	      u16_t a= ((addr+1) + d + 1);
	      if (d<0)
		{
		  d= -d;
		  code1= d;
		  work.appendf("-0x%02x", code1);
		}
	      else
		work.appendf("+0x%02x", d);
	      if (comment)
		{
		  comment->appendf("; %04x", a);
		}
	    }
	  else if (fmt=="ra8")
	    {
	      i16_t d= code1;
	      if (d & 0x80) d|= 0xff00;
	      u16_t a= ((addr+2) + d + 0);
	      if (d<0)
		{
		  d= -d;
		  code1= d;
		  work.appendf("-0x%02x", code1);
		}
	      else
		work.appendf("+0x%02x", d);
	      if (comment)
		{
		  comment->appendf("; %04x", a);
		}
	    }
	  else if (fmt=="ra8_2")
	    {
	      i16_t d= code2;
	      if (d & 0x80) d|= 0xff00;
	      u16_t a= ((addr+2) + d + 0);
	      if (d<0)
		{
		  d= -d;
		  code2= d;
		  work.appendf("-0x%02x", code2);
		}
	      else
		work.appendf("+0x%02x", d);
	      if (comment)
		{
		  comment->appendf("; %04x", a);
		}
	    }
	  else if (fmt=="a16_1")
	    {
	      u16_t a= code1 + code2*256;
	      work.appendf("0x%04x", a);
	    }
	  continue;
	}
      if (b[i] == '%')
	{
	  b++;
	  switch (b[i])
	    {
	    case 'x':
	      {
		u16_t x= rom->get(addr+1);
		work.appendf("0x%02x", x);
		if (comment)
		  comment->appendf("; [%04x] %02x %02x",
				   x, asd->read(x), asd->read(x+1));
	      }
	      break;
	    case 'b':
	      work.appendf("%d", code0&7);
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


int
cl_t870c::inst_length(t_addr addr)
{
  struct dis_entry *de= get_dis_entry(addr);

  if ((de == NULL) || (de->mnemonic == NULL))
    return 1;
  return de->length;
}

u16_t
cl_t870c::aof_dstF(u32_t code32)
{
  switch (code32&7)
    {
    case 0: return (code32>>8)&0xff;
    case 1: return (code32>>8)&0xffff;
    case 2: return rDE;
    case 3: return rHL;
    case 4: return rIX;
    case 5: return rIY;
    case 6: return rSP;
    case 7: return (i8_t)rC + rHL;
    }
  return 0;
}

u16_t
cl_t870c::aof_dst5(u32_t code32)
{
  switch (code32&0x7)
    {
    case 4: return (i8_t)((code32>>8)&0xff) + rIX;
    case 5: return (i8_t)((code32>>8)&0xff) + rIY;
    case 6: return (i8_t)((code32>>8)&0xff) + rSP;
    case 7: return (i8_t)((code32>>8)&0xff) + rHL;
    }
  return 0;
}

u16_t
cl_t870c::aof_srcE(u32_t code32)
{
  switch (code32&7)
    {
    case 0: return (code32>>8)&0xff;
    case 1: return (code32>>8)&0xffff;
    case 2: return rDE;
    case 3: return rHL;
    case 4: return rIX;
    case 5: return rIY;
    case 6: return rSP+1;
    case 7: return (i8_t)rC + rHL;
    }
  return 0;
}

u16_t
cl_t870c::aof_srcD(u32_t code32)
{
  switch (code32&0x7)
    {
    case 4: return (i8_t)((code32>>8)&0xff) + rIX;
    case 5: return (i8_t)((code32>>8)&0xff) + rIY;
    case 6: return (i8_t)((code32>>8)&0xff) + rSP;
    case 7: return (i8_t)((code32>>8)&0xff) + rHL;
    }
  return 0;
}

void
cl_t870c::stack_check_overflow(class cl_stack_op *op)
{
  if (op)
    {
      if (op->get_op() & stack_write_operation)
	{
	  t_addr a= op->get_after();
	  if (a < sp_limit)
	    {
              class cl_error_stack_overflow *e=
                new cl_error_stack_overflow(op);
              e->init();
              error(e);
	    }
	}
    }
}

int
cl_t870c::exec_inst(void)
{
  return exec_inst_uctab();
}

/*
 * Two byte opcode dispachers for reg/memory prefixes
 */

static const u8_t R_valids[256]=
  {
    /*0*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*1*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*2*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*3*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*4*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 0,
    /*5*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*6*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*7*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 0,
    /*8*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*9*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*a*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*b*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*c*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*d*/ 8, 8, 8, 8,   8, 8, 8, 8,   1, 1, 1, 1,   8, 8, 8, 0,
    /*e*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*f*/ 1, 1, 1, 1,   1, 1, 1, 1,   0, 0, 1, 8,   0, 1, 1, 1
  };

int
cl_t870c::exec1(void)
{
  int res= resGO;
  int valid;
  // prefix info fetched already
  t_mem code2= fetch();
  int page_code= code2|(page=0x100);
  valid= R_valids[code2];
  if (!valid || ((code2 != 0xe8) && (valid == 8)))
    return resINV;
  if (uc_itab[page_code] == NULL)
    {
      PC= instPC;
      return resNOT_DONE;
    }
  tickt(page_code);
  res= (this->*uc_itab[page_code])(code2);
  if (res == resNOT_DONE)
    PC= instPC;
  return res;
}

static const u8_t src_valids[256]=
  {
    /*0*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*1*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*2*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*3*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*4*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 0,
    /*5*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*6*/ 1, 1, 1, 1,   1, 1, 1, 1,   0, 0, 0, 0,   0, 0, 0, 0,
    /*7*/ 1, 1, 1, 1,   1, 1, 1, 1,   0, 0, 0, 0,   0, 0, 0, 0,
    /*8*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*9*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*a*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*b*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*c*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*d*/ 0, 0, 0, 0,   0, 0, 0, 0,   1, 1, 1, 1,   1, 1, 1, 1,
    /*e*/ 1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,   1, 1, 1, 1,
    /*f*/ 1, 0, 1, 1,   0, 0, 1, 1,   1, 1, 1, 1,   1, 1, 1, 0
  };

int
cl_t870c::execS(void)
{
  int res= resGO;
  // prefix info fetched already
  t_mem code2= fetch();
  if (!src_valids[code2])
    return resINV;
  int page_code= code2|(page=0x200);
  is_dst= false;
  if (uc_itab[page_code] == NULL)
    {
      PC= instPC;
      return resNOT_DONE;
    }
  tickt(page_code);
  res= (this->*uc_itab[page_code])(code2);
  if (res == resNOT_DONE)
    PC= instPC;
  return res;
}


static const u8_t dst_valids[256]=
  {
    /*0*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*1*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*2*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*3*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*4*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*5*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*6*/ 0, 0, 0, 0,   0, 0, 0, 0,   1, 1, 1, 1,   1, 1, 1, 0,
    /*7*/ 0, 0, 0, 0,   0, 0, 0, 0,   1, 1, 1, 1,   1, 1, 1, 1,
    /*8*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*9*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*a*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*b*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*c*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*d*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*e*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,
    /*f*/ 0, 0, 0, 0,   0, 0, 0, 0,   0, 1, 0, 0,   0, 0, 0, 0
  };

int
cl_t870c::execD(void)
{
  int res= resGO;
  // prefix info fetched already
  t_mem code2= fetch();
  if (!dst_valids[code2])
    return resINV;
  int page_code= code2|(page=0x200);
  is_dst= true;
  if (uc_itab[page_code] == NULL)
    {
      PC= instPC;
      return resNOT_DONE;
    }
  tickt(page_code);
  res= (this->*uc_itab[page_code])(code2);
  if (res == resNOT_DONE)
    PC= instPC;
  return res;
}


C8 *
cl_t870c::sd_x(void)
{
  sda= fetch();
  return sdc= (C8 *)asd->get_cell(sda);
}

C8 *
cl_t870c::sd_vw(void)
{
  sda= fetch16();
  return sdc= (C8 *)asd->get_cell(sda);
}

void
cl_t870c::sd_ixd(void)
{
  i8_t d= fetch();
  sda= rIX+d;
  sdc= (C8 *)asd->get_cell(sda);
}

void
cl_t870c::sd_iyd(void)
{
  i8_t d= fetch();
  sda= rIY+d;
  sdc= (C8 *)asd->get_cell(sda);
}

void
cl_t870c::sd_spd(void)
{
  i8_t d= fetch();
  sda= rSP+d;
  sdc= (C8 *)asd->get_cell(sda);
}

void
cl_t870c::sd_hld(void)
{
  i8_t d= fetch();
  sda= rHL+d;
  sdc= (C8 *)asd->get_cell(sda);
}

void
cl_t870c::sd_hlc(void)
{
  i8_t d= rC;
  sda= rHL+d;
  sdc= (C8 *)asd->get_cell(sda);
}

void
cl_t870c::sd_pca(void)
{
  sda= (PC+(i8_t)rA) & PCmask;
  sdc= (C8 *)asd->get_cell(sda);
}

void
cl_t870c::sd_Psp(void)
{
  cSP.W(sda= rSP+1);
  sdc= (C8 *)asd->get_cell(sda);
}

void
cl_t870c::sd_spM(void)
{
  sda= rSP;
  cSP.W(rSP-1);
  sdc= (C8 *)asd->get_cell(sda);
}

u16_t
cl_t870c::mn(void)
{
  u16_t mn= fetch16();
  return mn;
}


int
cl_t870c::ld8(C8 *reg, MCELL *src)
{
  RD;
  return ldi8(reg, src->R());
}

int
cl_t870c::ldi8(C8 *reg, u8_t n)
{
  reg->W(n);
  rF&= ~MZF;
  rF|= (MJF|(!n?MZF:0));
  cF.W(rF);
  return resGO;
}

int
cl_t870c::ldi8nz(C8 *reg, u8_t n)
{
  reg->W(n);
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::ld16(C16 *reg, u16_t addr)
{
  u16_t n;
  n= rd16(addr);
  reg->W(n);
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::ldi16(C16 *reg, u16_t n)
{
  reg->W(n);
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::st8(MCELL *dst, u8_t n)
{
  dst->W(n);
  WR;
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::st16(t_addr addr, u16_t n)
{
  wr16(addr, n);
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::xch8_rr(C8 *a, C8 *b)
{
  rF&= ~MZF;
  u8_t t= b->get();
  if (!t) rF|= MZF;
  b->W(a->get());
  a->W(t);
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::xch8_rm(C8 *a, C8 *b)
{
  rF&= ~MZF;
  u8_t t= b->read();
  if (!t) rF|= MZF;
  b->W(a->get());
  a->W(t);
  cF.W(rF|MJF);
  RDWR;
  return resGO;
}

int
cl_t870c::xch16_rr(C16 *a, C16 *b)
{
  u16_t t= b->get();
  b->W(a->get());
  a->W(t);
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::xch16_rm(C16 *a, u16_t addr)
{
  u16_t t= rd16(addr);
  wr16(addr, a->get());
  a->W(t);  
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::pop(MCELL *reg)
{
  u16_t a= rSP+1;
  u16_t v;
  v= rd16(a);
  cSP.W(a+1);
  reg->W(v);
  return resGO;
}

int
cl_t870c::push(MCELL *reg)
{
  t_addr sp_before= rSP;
  u16_t a= rSP-1;
  t_mem val;
  wr16(a, val= reg->R());
  cSP.W(a-1);
  class cl_stack_push *o= new cl_stack_push(instPC, val, sp_before, rSP);
  o->init();
  stack_write(o);
  return resGO;
}

int
cl_t870c::ld1r(C8 *src, u8_t bitnr)
{
  rF&= ~(MCF|MJF);
  if (src->get() & bit_mask[bitnr])
    cF.W(rF|MCF);
  else
    cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::ld1m(C8 *src, u8_t bitnr)
{
  rF&= ~(MCF|MJF);
  if (src->read() & bit_mask[bitnr])
    cF.W(rF|MCF);
  else
    cF.W(rF|MJF);
  RD;
  return resGO;
}

int
cl_t870c::st1r(C8 *dst, u8_t bitnr)
{
  u8_t m= bit_mask[bitnr];
  u8_t v= dst->get();
  if (rF&MCF)
    v|= m;
  else
    v&= ~m;
  dst->W(v);
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::st1m(C8 *dst, u8_t bitnr)
{
  u8_t m= bit_mask[bitnr];
  u8_t v= dst->read();
  RD;
  if (rF&MCF)
    v|= m;
  else
    v&= ~m;
  dst->W(v);
  WR;
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::setr(C8 *reg, u8_t bitnr)
{
  u8_t m= bit_mask[bitnr];
  u8_t v= reg->get();
  if (v&m)
    rF&= ~(MJF|MZF);
  else
    rF|= (MJF|MZF);
  reg->W(v | m);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::setm(C8 *reg, u8_t bitnr)
{
  u8_t m= bit_mask[bitnr];
  u8_t v= reg->read();
  RD;
  if (v&m)
    rF&= ~(MJF|MZF);
  else
    rF|= (MJF|MZF);
  reg->W(v | m);
  WR;
  cF.W(rF);
  return resGO;
}

int
cl_t870c::clrr(C8 *reg, u8_t bitnr)
{
  u8_t m= bit_mask[bitnr];
  u8_t v= reg->get();
  if (v&m)
    rF&= ~(MJF|MZF);
  else
    rF|= (MJF|MZF);
  reg->W(v & ~m);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::clrm(C8 *reg, u8_t bitnr)
{
  u8_t m= bit_mask[bitnr];
  u8_t v= reg->read();
  RD;
  if (v&m)
    rF&= ~(MJF|MZF);
  else
    rF|= (MJF|MZF);
  reg->W(v & ~m);
  WR;
  cF.W(rF);
  return resGO;
}

int
cl_t870c::cplr(C8 *src, u8_t bitnr)
{
  u8_t m= bit_mask[bitnr];
  u8_t v= src->get();
  if (v & m)
    rF&= ~(MJF|MZF);
  else
    rF|= MJF|MZF;
  src->W(v ^ m);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::cplm(C8 *src, u8_t bitnr)
{
  u8_t m= bit_mask[bitnr];
  u8_t v= src->read();
  RD;
  if (v & m)
    rF&= ~(MJF|MZF);
  else
    rF|= MJF|MZF;
  src->W(v ^ m);
  RD;
  cF.W(rF);
  return resGO;
}

int
cl_t870c::xor1r(C8 *src, u8_t bitnr)
{
  u8_t m= bit_mask[bitnr];
  u8_t v1= src->get() & m;
  u8_t v2= (rF & MCF)?m:0;
  if (v1 ^ v2)
    {
      rF|= MCF;
      rF&= ~MJF;
    }
  else
    {
      rF&= ~MCF;
      rF|= MJF;
    }
  cF.W(rF);
  return resGO;
}

int
cl_t870c::xor1m(C8 *src, u8_t bitnr)
{
  u8_t m= bit_mask[bitnr];
  u8_t v1= src->read() & m;
  u8_t v2= (rF & MCF)?m:0;
  RD;
  if (v1 & v2)
    {
      rF|= MCF;
      rF&= ~MJF;
    }
  else
    {
      rF&= ~MCF;
      rF|= MJF;
    }
  cF.W(rF);
  return resGO;
}

int
cl_t870c::inc8r(C8 *reg)
{
  u8_t v= reg->get()+1;
  if (v)
    rF&= ~(MJF|MZF);
  else
    rF|= MJF|MZF;
  reg->W(v);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::inc16r(C16 *reg)
{
  u16_t v= reg->get()+1;
  if (v)
    rF&= ~(MJF|MZF);
  else
    rF|= MJF|MZF;
  reg->W(v);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::inc8m(C8 *src)
{
  u8_t v= src->read()+1;
  RD;
  if (v)
    rF&= ~(MJF|MZF);
  else
    rF|= MJF|MZF;
  src->W(v);
  WR;
  cF.W(rF);
  return resGO;
}

int
cl_t870c::inc16m(C16 *src)
{
  u16_t v= src->read()+1;
  RD;
  if (v)
    rF&= ~(MJF|MZF);
  else
    rF|= MJF|MZF;
  src->W(v);
  WR;
  cF.W(rF);
  return resGO;
}

int
cl_t870c::dec8r(C8 *reg)
{
  u8_t v= reg->get()-1;
  if (v != 0xff)
    rF&= ~(MJF|MZF);
  else
    rF|= MJF|MZF;
  reg->W(v);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::dec16r(C16 *reg)
{
  u16_t v= reg->get()-1;
  if (v != 0xffff)
    rF&= ~(MJF|MZF);
  else
    rF|= MJF|MZF;
  reg->W(v);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::dec8m(C8 *src)
{
  u8_t v= src->read()-1;
  RD;
  if (v != 0xff)
    rF&= ~(MJF|MZF);
  else
    rF|= MJF|MZF;
  src->W(v);
  WR;
  cF.W(rF);
  return resGO;
}

int
cl_t870c::dec16m(C16 *src)
{
  u16_t v= src->read()-1;
  RD;
  if (v != 0xffff)
    rF&= ~(MJF|MZF);
  else
    rF|= MJF|MZF;
  src->W(v);
  WR;
  cF.W(rF);
  return resGO;
}

int
cl_t870c::add8(C8 *reg, u8_t n, bool c)
{
  u16_t op1, op1_7, op2, op2_7, res, res_7, c7, c8= 0;
  op1= reg->get();
  op2= n;
  res= op1 + op2 + (c?((rF&MCF)?1:0):0);
  op1_7= op1 & 0x7f;
  op2_7= op2 & 0x7f;
  res_7= op1_7 + op2_7;

  rF&= ~MALL;
  if (res > 0xff)
    (rF|= MCF|MJF), c8=1;
  if (res & 0x80)
    rF|= MSF;
  c7= (res_7>0x7f)?1:0;
  if (c7^c8)
    rF|= MVF;
  if ((res & 0xff) == 0)
    rF|= MZF;
  if (((op1&0xf) + (op2&0xf)) > 0xf)
    rF|= MHF;

  reg->W(res);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::add16(C16 *reg, u16_t n, bool c)
{
  u32_t op1, op1_15, op2, op2_15, res, res_15, c15, c16= 0;
  op1= reg->get();
  op2= n;
  res= op1 + op2 + (c?((rF&MCF)?1:0):0);
  op1_15= op1 & 0x7fff;
  op2_15= op2 & 0x7fff;
  res_15= op1_15 + op2_15;

  rF&= ~MALL;
  if (res > 0xffff)
    (rF|= MCF|MJF), c16=1;
  if (res & 0x8000)
    rF|= MSF;
  c15= (res_15>0x7fff)?1:0;
  if (c15^c16)
    rF|= MVF;
  if ((res & 0xffff) == 0)
    rF|= MZF;

  reg->W(res);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::sub8(C8 *reg, u8_t n, bool b)
{
  u16_t op1, op1_7, op2, op2_7, res, res_7, c7, c8= 0, cin;
  op1= reg->get();
  cin= b?((rF&MCF)?0:1):1;
  op2= (~n + cin) & 0xff;
  res= op1 + op2;
  op1_7= op1 & 0x7f;
  op2_7= op2 & 0x7f;
  res_7= op1_7 + op2_7;

  rF&= ~MALL;
  if (res > 0xff)
    (rF|= MCF|MJF), c8=1;
  if (res & 0x80)
    rF|= MSF;
  c7= (res_7>0x7f)?1:0;
  if (c7^c8)
    rF|= MVF;
  if ((res & 0xff) == 0)
    rF|= MZF;
  if (((op1&0xf) + (op2&0xf)) > 0xf)
    rF|= MHF;
  rF^= (MCF|MJF|MHF);
  
  reg->W(res);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::sub16(C16 *reg, u16_t n, bool b)
{
  u32_t op1, op1_15, op2, op2_15, res, res_15, c15, c16= 0, cin;
  op1= reg->get();
  cin= b?((rF&MCF)?0:1):1;
  op2= (~n + cin) & 0xffff;
  res= op1 + op2;
  op1_15= op1 & 0x7fff;
  op2_15= op2 & 0x7fff;
  res_15= op1_15 + op2_15;

  rF&= ~MALL;
  if (res > 0xffff)
    (rF|= MCF|MJF), c16=1;
  if (res & 0x8000)
    rF|= MSF;
  c15= (res_15>0x7fff)?1:0;
  if (c15^c16)
    rF|= MVF;
  if ((res & 0xffff) == 0)
    rF|= MZF;
  rF^= (MCF|MJF);
  
  reg->W(res);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::cmp8(C8 *reg, u8_t n)
{
  u16_t op1, op1_7, op2, op2_7, res, res_7, c7, c8= 0;
  op1= reg->get();
  op2= (~n + 1) & 0xff;
  res= op1 + op2;
  op1_7= op1 & 0x7f;
  op2_7= op2 & 0x7f;
  res_7= op1_7 + op2_7;

  rF&= ~MALL;
  if (res > 0xff)
    (rF|= MCF|MJF), c8=1;
  if (res & 0x80)
    rF|= MSF;
  c7= (res_7>0x7f)?1:0;
  if (c7^c8)
    rF|= MVF;
  if ((res & 0xff) == 0)
    rF|= MZF;
  if (((op1&0xf) + (op2&0xf)) > 0xf)
    rF|= MHF;
  rF^= (MCF|MJF|MHF);
  
  cF.W(rF);
  return resGO;
}

int
cl_t870c::cmp16(C16 *reg, u16_t n)
{
  u32_t op1, op1_15, op2, op2_15, res, res_15, c15, c16= 0;
  op1= reg->get();
  op2= (~n + 1) & 0xffff;
  res= op1 + op2;
  op1_15= op1 & 0x7fff;
  op2_15= op2 & 0x7fff;
  res_15= op1_15 + op2_15;

  rF&= ~MALL;
  if (res > 0xffff)
    (rF|= MCF|MJF), c16=1;
  if (res & 0x8000)
    rF|= MSF;
  c15= (res_15>0x7fff)?1:0;
  if (c15^c16)
    rF|= MVF;
  if ((res & 0xffff) == 0)
    rF|= MZF;
  rF^= (MCF|MJF);
  
  cF.W(rF);
  return resGO;
}

int
cl_t870c::and8(C8 *reg, u8_t n)
{
  rF&= ~(MJF|MZF);
  u8_t r= reg->R() & n;
  if (!r)
    rF|= (MJF|MZF);
  reg->W(r);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::and16(C16 *reg, u16_t n)
{
  rF&= ~(MJF|MZF);
  u16_t r= reg->R() & n;
  if (!r)
    rF|= (MJF|MZF);
  reg->W(r);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::xor8(C8 *reg, u8_t n)
{
  rF&= ~(MJF|MZF);
  u8_t r= reg->R() ^ n;
  if (!r)
    rF|= (MJF|MZF);
  reg->W(r);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::xor16(C16 *reg, u16_t n)
{
  rF&= ~(MJF|MZF);
  u16_t r= reg->R() ^ n;
  if (!r)
    rF|= (MJF|MZF);
  reg->W(r);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::or8(C8 *reg, u8_t n)
{
  rF&= ~(MJF|MZF);
  u8_t r= reg->R() | n;
  if (!r)
    rF|= (MJF|MZF);
  reg->W(r);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::or16(C16 *reg, u16_t n)
{
  rF&= ~(MJF|MZF);
  u16_t r= reg->R() | n;
  if (!r)
    rF|= (MJF|MZF);
  reg->W(r);
  cF.W(rF);
  return resGO;
}


int
cl_t870c::SHLCA_gg(MP)
{
  C16 *gg= regs16[sda];
  rF&= ~(MJF|MCF|MZF|MSF|MVF);
  u16_t ro= gg->R(), rn;
  if (ro & 0x8000)
    rF|= (MJF|MCF);
  rn= ro << 1;
  if ((rn ^ ro) & 0x8000)
    rF|= MVF;
  if (!rn)
    rF|= MZF;
  if (rn & 0x8000)
    rF|= MSF;
  gg->W(rn);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::SHRCA_gg(MP)
{
  C16 *gg= regs16[sda];
  rF&= ~(MJF|MCF|MZF|MSF|MVF);
  i16_t ro= gg->R(), rn;
  if (ro & 1)
    rF|= (MJF|MCF);
  rn= ro >> 1;
  if (!rn)
    rF|= MZF;
  if (rn & 0x8000)
    rF|= MSF;
  gg->W(rn);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::mul(C16 *rr)
{
  u8_t op1, op2;
  u16_t r, res;
  rF&= ~(MJF|MZF);
  r= rr->R();
  op1= r>>8;
  op2= r&0xff;
  res= op1*op2;
  if  ((res & 0xff00) == 0)
    rF|= (MJF|MZF);
  rr->W(res);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::div(C16 *rr)
{
  u16_t op1= rr->R();
  u8_t op2= cC.R();
  u16_t q= 0, rem= 0, res;
  rF&= ~(MJF|MZF|MCF);
  if (op2 == 0)
    {
      rF|= MCF;
    }
  else
    {
      q= op1/op2;
      rem= op1%op2;
      if (q > 0x100)
	rF|= MCF;
      if (rem == 0)
	rF|= (MJF|MZF);
    }
  res= (rem << 8) + (q & 0xff);
  rr->W(res);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::SHLC_g(MP)
{
  C8 *g= regs8[sda];
  rF&= ~(MJF|MCF|MZF);
  u16_t r= g->R();
  r<<= 1;
  if (r & 0x100)
    rF|= (MJF|MCF);
  if ((r & 0xff) == 0)
    rF|= MZF;
  g->W(r);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::SHRC_g(MP)
{
  C8 *g= regs8[sda];
  rF&= ~(MJF|MCF|MZF);
  u8_t r= g->R();
  if (r & 1)
    rF|= (MJF|MCF);
  r>>= 1;
  if (!r)
    rF|= MZF;
  g->W(r);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::ROLC_g(MP)
{
  C8 *g= regs8[sda];
  u8_t oldc= (rF&MCF)?1:0;
  rF&= ~(MJF|MCF|MZF);
  u8_t r= g->R();
  if (r & 0x80)
    rF|= (MJF|MCF);
  r<<= 1;
  r|= oldc;
  if (!r)
    rF|= MZF;
  g->W(r);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::RORC_g(MP)
{
  C8 *g= regs8[sda];
  u8_t oldc= (rF&MCF)?0x80:0;
  rF&= ~(MJF|MCF|MZF);
  u8_t r= g->R();
  if (r & 0x01)
    rF|= (MJF|MCF);
  r>>= 1;
  r|= oldc;
  if (!r)
    rF|= MZF;
  g->W(r);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::NEG_gg(MP)
{
  rF|= MJF;
  if (rF & MCF)
    {
      regs16[sda]->W(-(regs16[sda]->R()));
    }
  return resGO;
}

#include "dec_adj_tab.cc"

int
cl_t870c::DAA_g(MP)
{
  C8 *g= regs8[sda];
  u8_t adj;
  int cc= (rF&MCF)?2:0 + (rF&MHF)?1:0;
  adj= daa_adj_tab[g->get()] >> (cc*8);

  u16_t op1, op2, res;
  op1= g->get();
  op2= adj;
  res= op1 + op2;

  rF&= ~(MJF|MCF|MZF|MHF);
  if (res > 0xff)
    (rF|= MCF|MJF);
  if ((res & 0xff) == 0)
    rF|= MZF;
  if (((op1&0xf) + (op2&0xf)) > 0xf)
    rF|= MHF;

  g->W(res);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::DAS_g(MP)
{
  C8 *g= regs8[sda];
  u8_t adj;
  int cc= (rF&MCF)?2:0 + (rF&MHF)?1:0;
  adj= das_adj_tab[g->get()] >> (cc*8);

  u16_t op1, op2, res;
  op1= g->get();
  op2= adj;
  res= op1 + op2;

  rF&= ~(MJF|MCF|MZF|MHF);
  if (res > 0xff)
    (rF|= MCF|MJF);
  if ((res & 0xff) == 0)
    rF|= MZF;
  if (((op1&0xf) + (op2&0xf)) > 0xf)
    rF|= MHF;
  rF^= (MCF|MJF|MHF);
  
  g->W(res);
  cF.W(rF);
  return resGO;
}

int
cl_t870c::jr(u8_t a)
{
  i8_t v= a;
  PC= (PC + v + 0) & PCmask;
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::jr_cc(u8_t a, bool cond)
{
  i8_t v= a;
  if (cond)
    PC= (PC + v + 0) & PCmask;
  else
    cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::jrs(u8_t code, bool cond)
{
  i16_t v= code & 0x1f;
  if (v & 0x10)
    v|= 0xffe0;
  if (cond)
    {
      PC= (PC + v + 1) & PCmask;
      tick(extra_ticks()[page|code]);
    }
  else
    cF.W(rF|MJF);
  return resGO;
}


int
cl_t870c::CLR_CF(MP)
{
  rF&= ~MCF;
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::SET_CF(MP)
{
  rF&= ~MJF;
  rF|= MCF;
  cF.W(rF);
  return resGO;
}

int
cl_t870c::CPL_CF(MP)
{
  if (rF & MCF)
    rF|= MJF;
  else
    rF&= ~MJF;
  rF^= MCF;
  cF.W(rF);
  return resGO;
}

int
cl_t870c::LDW_mx_mn(MP)
{
  u8_t mn;
  sda= fetch();
  asd->write(sda, mn= fetch());
  asd->write(sda+1, mn= fetch());
  WR2;
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::LDW_mhl_mn(MP)
{
  u8_t mn;
  asd->write(rHL, mn= fetch());
  asd->write(rHL+1, mn= fetch());
  WR2;
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::LD_RBS(MP)
{
  if (fetch())
    cF.W(rF|MRBS);
  else
    cF.W(rF&~MRBS);
  return resGO;
}

int
cl_t870c::SWAP_g(MP)
{
  u8_t v= regs8[sda]->get();
  u8_t l= v&0xf;
  v>>= 4;
  v|= (l<<4);
  regs8[sda]->W(v);
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::LD_SP_Pd(MP)
{
  cSP.W(rSP+fetch());
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::LD_SP_Md(MP)
{
  cSP.W(rSP-fetch());
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::LD_src_A_CF(MP)
{
  u8_t m= bit_mask[rA&7];
  u8_t v= sdc->read();
  RD;
  if (rF & MCF)
    v|= m;
  else
    v&= ~m;
  sdc->write(v);
  WR;
  cF.W(rF|MJF);
  return resGO;
}

int
cl_t870c::ROLD_A_src(MP)
{
  u8_t v= sdc->read();
  u8_t vh= v>>4;
  RD;
  v= (v<<4) + (rA&0xf);
  rA= (rA&0xf0) + vh;
  cF.W(rF|MJF);
  cA.W(rA);
  sdc->write(v);
  WR;
  return resGO;
}

int
cl_t870c::LD_CF_src_A(MP)
{
  u8_t m= bit_mask[rA&7];
  u8_t v= sdc->read();
  RD;
  rF&= ~(MJF|MCF);
  if (v&m)
    rF|= MCF;
  else
    rF|= MJF;
  cF.W(rF);
  return resGO;
}


/**************************************************************************/

cl_t870c_cpu::cl_t870c_cpu(class cl_uc *auc):
  cl_hw(auc, HW_DUMMY, 0, "cpu")
{
  uc= (class cl_t870c *)auc;
}

int
cl_t870c_cpu::init(void)
{
  class cl_var *v;
  cl_hw::init();
  psw= register_cell(uc->asd, 0x3f);
  uc->vars->add(v= new cl_var(chars("sp_limit"), cfg,
			      t870c_sp_limit,
			      cfg_help(t870c_sp_limit)));
  v->init();

  uc->vars->add(v= new cl_var(chars("bootmode"), cfg,
			      t870c_bootmode,
			      cfg_help(t870c_bootmode)));
  v->init();

  return 0;
}

void
cl_t870c_cpu::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;
  if (cell == psw)
    {
      *val= uc->rPSW;
    }
}

t_mem
cl_t870c_cpu::read(class cl_memory_cell *cell)
{
  t_mem v= cell->get();
  if (conf(cell, NULL))
    return v;
  if (cell == psw)
    {
      v= uc->rPSW;
    }
  return v;
}

t_mem
cl_t870c_cpu::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  switch ((enum t870c_cpu_cfg)addr)
    {
    case t870c_sp_limit:
      if (val)
	uc->sp_limit= *val & 0xffff;
      return uc->sp_limit;
      break;
    case t870c_bootmode:
      if (val)
	{
	  *val= (*val)?1:0;
	  // TODO: remap memories
	}
      break;
    default:
      if (val)
	cell->set(*val);
    }
  return cell->get();
}

const char *
cl_t870c_cpu::cfg_help(t_addr addr)
{
  switch (addr)
    {
    case t870c_sp_limit:
      return "Stack overflows when SP reaches this limit (uint, RW)";
    case t870c_bootmode:
      return "If true, CPU works in boot mode (bool, RW)";
    }
  return "Not used";
}


/* End of tlcs.src/t870c.cc */
