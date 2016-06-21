/*
 * Simulator of microcontrollers (tlcs.src/tlcs.cc)
 *
 * Copyright (C) 2016,16 Drotos Daniel, Talker Bt.
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

/* $Id$ */

#include "ddconfig.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "i_string.h"

// prj
#include "pobjcl.h"

// sim
#include "simcl.h"
#include "memcl.h"
#include "stackcl.h"

// local
#include "tlcscl.h"
#include "glob.h"


/*
 * Base type of TLCS microcontrollers
 */

cl_tlcs::cl_tlcs(class cl_sim *asim):
  cl_uc(asim)
{
  //type= CPU_TLCS;
  //sleep_executed= 0;
  regs8= new cl_address_space("regs8", 0, 16, 8);
  regs8->init();
  regs8->get_cell(0)->decode((t_mem*)&reg.a);
  regs8->get_cell(1)->decode((t_mem*)&reg.f);
  regs8->get_cell(2)->decode((t_mem*)&reg.b);
  regs8->get_cell(3)->decode((t_mem*)&reg.c);
  regs8->get_cell(4)->decode((t_mem*)&reg.d);
  regs8->get_cell(5)->decode((t_mem*)&reg.e);
  regs8->get_cell(6)->decode((t_mem*)&reg.h);
  regs8->get_cell(7)->decode((t_mem*)&reg.l);

  regs8->get_cell(8)->decode((t_mem*)&reg.alt_a);
  regs8->get_cell(9)->decode((t_mem*)&reg.alt_f);
  regs8->get_cell(10)->decode((t_mem*)&reg.alt_b);
  regs8->get_cell(11)->decode((t_mem*)&reg.alt_c);
  regs8->get_cell(12)->decode((t_mem*)&reg.alt_d);
  regs8->get_cell(13)->decode((t_mem*)&reg.alt_e);
  regs8->get_cell(14)->decode((t_mem*)&reg.alt_h);
  regs8->get_cell(15)->decode((t_mem*)&reg.alt_l);

  regs16= new cl_address_space("regs16", 0, 11, 16);
  regs16->init();

  regs16->get_cell(0)->decode((t_mem*)&reg.af);
  regs16->get_cell(1)->decode((t_mem*)&reg.bc);
  regs16->get_cell(2)->decode((t_mem*)&reg.de);
  regs16->get_cell(3)->decode((t_mem*)&reg.hl);
  regs16->get_cell(4)->decode((t_mem*)&reg.ix);
  regs16->get_cell(5)->decode((t_mem*)&reg.iy);
  regs16->get_cell(6)->decode((t_mem*)&reg.sp);
  regs16->get_cell(7)->decode((t_mem*)&reg.alt_af);
  regs16->get_cell(8)->decode((t_mem*)&reg.alt_bc);
  regs16->get_cell(9)->decode((t_mem*)&reg.alt_de);
  regs16->get_cell(10)->decode((t_mem*)&reg.alt_hl);

  address_spaces->add(regs8);
  address_spaces->add(regs16);
}

int
cl_tlcs::init(void)
{
  class cl_var *v;

  cl_uc::init(); /* Memories now exist */
  //ram= address_space(MEM_IRAM_ID);
  //rom= address_space(MEM_ROM_ID);

  vars->add(v= new cl_var(cchars("a"), regs8, 0));
  v->init();
  vars->add(v= new cl_var(cchars("f"), regs8, 1));
  v->init();
  vars->add(v= new cl_var(cchars("b"), regs8, 2));
  v->init();
  vars->add(v= new cl_var(cchars("c"), regs8, 3));
  v->init();
  vars->add(v= new cl_var(cchars("d"), regs8, 4));
  v->init();
  vars->add(v= new cl_var(cchars("e"), regs8, 5));
  v->init();
  vars->add(v= new cl_var(cchars("h"), regs8, 6));
  v->init();
  vars->add(v= new cl_var(cchars("l"), regs8, 7));
  v->init();

  vars->add(v= new cl_var(cchars("alt_a"), regs8, 8));
  v->init();
  vars->add(v= new cl_var(cchars("alt_f"), regs8, 9));
  v->init();
  vars->add(v= new cl_var(cchars("alt_b"), regs8, 10));
  v->init();
  vars->add(v= new cl_var(cchars("alt_c"), regs8, 11));
  v->init();
  vars->add(v= new cl_var(cchars("alt_d"), regs8, 12));
  v->init();
  vars->add(v= new cl_var(cchars("alt_e"), regs8, 13));
  v->init();
  vars->add(v= new cl_var(cchars("alt_h"), regs8, 14));
  v->init();
  vars->add(v= new cl_var(cchars("alt_l"), regs8, 15));
  v->init();

  vars->add(v= new cl_var(cchars("af"), regs16, 0));
  v->init();
  vars->add(v= new cl_var(cchars("bc"), regs16, 1));
  v->init();
  vars->add(v= new cl_var(cchars("de"), regs16, 2));
  v->init();
  vars->add(v= new cl_var(cchars("hl"), regs16, 3));
  v->init();
  vars->add(v= new cl_var(cchars("ix"), regs16, 4));
  v->init();
  vars->add(v= new cl_var(cchars("iy"), regs16, 5));
  v->init();
  vars->add(v= new cl_var(cchars("sp"), regs16, 6));
  v->init();
  vars->add(v= new cl_var(cchars("alt_af"), regs16, 7));
  v->init();
  vars->add(v= new cl_var(cchars("alt_bc"), regs16, 8));
  v->init();
  vars->add(v= new cl_var(cchars("alt_de"), regs16, 9));
  v->init();
  vars->add(v= new cl_var(cchars("alt_hl"), regs16, 11));
  v->init();

  return(0);
}

char *
cl_tlcs::id_string(void)
{
  return((char*)"unspecified TLCS");
}


void
cl_tlcs::mk_hw_elements(void)
{
  //class cl_base *o;
  //hws->add(o= new cl_port(this));
  //o->init();
}


void
cl_tlcs::make_memories(void)
{
  class cl_address_space *as;

  rom= nas= as= new cl_address_space(cchars("nas"), 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);
  das= as= new cl_address_space(cchars("das"), 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  class cl_address_decoder *ad;
  class cl_memory_chip *chip;

  chip= new cl_memory_chip("nas_chip", 0x10000, 8);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as= nas,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);

  //chip= new cl_memory_chip("das_chip", 0x10000, 8);
  //chip->init();
  //memchips->add(chip);
  ad= new cl_address_decoder(as= das,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}


struct dis_entry *
cl_tlcs::dis_tbl(void)
{
  return disass_tlcs;
}

//virtual struct name_entry *sfr_tbl(void);
//virtual struct name_entry *bit_tbl(void);

const char *
cl_tlcs::regname_r(uint8_t r)
{
  switch (r & 7)
    {
    case 0: return "B";
    case 1: return "C";
    case 2: return "D";
    case 3: return "E";
    case 4: return "H";
    case 5: return "L";
    case 6: return "A";
    default: return "?";
    }
}

const char *
cl_tlcs::regname_R(uint8_t R)
{
  switch (R & 7)
    {
    case 0: return "BC";
    case 1: return "DE";
    case 2: return "HL";
    case 4: return "IX";
    case 5: return "IY";
    case 6: return "SP";
    default: return "?";
    }
}

const char *
cl_tlcs::regname_Q(uint8_t Q)
{
  switch (Q & 7)
    {
    case 0: return "BC";
    case 1: return "DE";
    case 2: return "HL";
    case 4: return "IX";
    case 5: return "IY";
    case 6: return "AF";
    default: return "?";
    }
}

const char *
cl_tlcs::regname_i(uint8_t i)
{
  switch (i & 3)
    {
    case 0: return "IX";
    case 1: return "IY";
    case 2: return "SP";
    default: return "?";
    }
}

const char *
cl_tlcs::bitname(uint8_t b)
{
  switch (b & 0x07)
    {
    case 0: return "0";
    case 1: return "1";
    case 2: return "2";
    case 3: return "3";
    case 4: return "4";
    case 5: return "5";
    case 6: return "6";
    case 7: return "7";
    }
  return "?";
}

const char *
cl_tlcs::condname_cc(uint8_t cc)
{
  switch (cc & 0xf)
    {
    case 0: return "F,";
    case 1: return "LT,";
    case 2: return "LE,";
    case 3: return "ULE,";
    case 4: return "OV,";
    case 5: return "M,";
    case 6: return "Z,";
    case 7: return "C,";
    case 8: return "";
    case 9: return "GE,";
    case 10: return "GT,";
    case 11: return "UGT,";
    case 12: return "NOV,";
    case 13: return "P,";
    case 14: return "NZ,";
    case 15: return "NC,";
    }
  return "?";
}

const char *
cl_tlcs::condname_C(uint8_t cc)
{
  switch (cc & 0xf)
    {
    case 0: return "F";
    case 1: return "LT";
    case 2: return "LE";
    case 3: return "ULE";
    case 4: return "OV";
    case 5: return "M";
    case 6: return "Z";
    case 7: return "C";
    case 8: return "";
    case 9: return "GE";
    case 10: return "GT";
    case 11: return "UGT";
    case 12: return "NOV";
    case 13: return "P";
    case 14: return "NZ";
    case 15: return "NC";
    }
  return "?";
}

const char *
cl_tlcs::disass(t_addr addr, const char *sep)
{
  struct dis_entry *de;
  uint64_t c;
  int i;
  chars s("");
  char *buf, *t, l[20];
  
  c= 0;
  for (i= 7; i>=0; i--)
    {
      uint8_t cb= rom->get(addr+i);
      c<<= 8;
      c|= cb;
    }

  de= dis_tbl();
  while (de->mnemonic != NULL)
    {
      if ((c & de->mask) == de->code)
	break;
      de++;
    }
  if (de->mnemonic == NULL)
    return strdup("?");

  for (t= (char*)de->mnemonic; *t; t++)
    {
      if (*t == '%')
	{
	  t++;
	  switch (*t)
	    {
	    case 'r': /*  r in 1st byte */ s+= regname_r(c); break;
	    case 'p': /*  r in 2nd byte */ s+= regname_r(c>>8); break;
	    case 't': /*  r in 3rd byte */ s+= regname_r(c>>16); break;
	    case 'R': /* rr in 1st byte */ s+= regname_R(c); break;
	    case 's': /* rr in 2nd byte */ s+= regname_R(c>>8); break;
	    case 'u': /* rr in 3rd byte */ s+= regname_R(c>>16); break;
	    case 'Q': /* qq in 1st byte */ s+= regname_Q(c); break;
	    case 'I': /* ix in 1st byte */ s+= regname_i(c); break;
	    case 'i': /* ix in 2nd byte */ s+= regname_i(c>>8); break;
	    case 'j': /* ix in 3rd byte */ s+= regname_i(c>>16); break;
	    case 'b': /*  b in 2nd byte */ s+= bitname(c>>8); break;
	    case 'B': /*  b in 3rd byte */ s+= bitname(c>>16); break;
	    case 'c': /* cc in 2nd byte */ s+= condname_cc(c>>8); break; // with ,
	    case 'C': /* cc in 2nd byte */ s+= condname_C(c>>8); break; // without ,
	    case 'n': /*  n in 2nd byte */ snprintf(l,19,"%02x",(int)((c>>8)&0xff));s+= l; break;
	    case 'd': /*  d in 2nd byte */ snprintf(l,19,"0x%04x", (int)(addr+2+((c>>8)&0xff))); s+= l; break;
	    default: s+= '?'; break;
	    }
	}
      else
	s+= *t;
    }
  
  buf= strdup(s);
  return buf;
}

int
cl_tlcs::inst_length(t_addr addr)
{
  struct dis_entry *de;
  uint64_t c;
  int i;
  
  c= 0;
  for (i= 7; i>=0; i--)
    {
      uint8_t cb= rom->get(addr+i);
      c<<= 8;
      c|= cb;
    }

  de= dis_tbl();
  while (de->mnemonic != NULL)
    {
      if ((c & de->mask) == de->code)
	break;
      de++;
    }
  if (de->mnemonic == NULL)
    return 1;
  if (de->length == 1)
    return 1;
  else
    return de->length;
}

void
cl_tlcs::print_regs(class cl_console_base *con)
{
  con->dd_printf("SZIHXVNC  Flags= 0x%02x %3d %c  ",
                 reg.f, reg.f, isprint(reg.f)?reg.f:'.');
  con->dd_printf("A= 0x%02x %3d %c\n",
                 reg.a, reg.a, isprint(reg.a)?reg.a:'.');
  con->dd_printf("%c%c%c%c%c%c%c%c\n",
                 (reg.f&FLAG_S)?'1':'0',
                 (reg.f&FLAG_Z)?'1':'0',
		 (reg.f&FLAG_I)?'1':'0',
                 (reg.f&FLAG_H)?'1':'0',
                 (reg.f&FLAG_X)?'1':'0',
                 (reg.f&FLAG_V)?'1':'0',
                 (reg.f&FLAG_N)?'1':'0',
                 (reg.f&FLAG_C)?'1':'0');
  con->dd_printf("BC= 0x%04x [BC]= %02x %3d %c  ",
                 reg.bc, nas->get(reg.bc), nas->get(reg.bc),
                 isprint(nas->get(reg.bc))?nas->get(reg.bc):'.');
  con->dd_printf("DE= 0x%04x [DE]= %02x %3d %c  ",
                 reg.de, nas->get(reg.de), nas->get(reg.de),
                 isprint(nas->get(reg.de))?nas->get(reg.de):'.');
  con->dd_printf("HL= 0x%04x [HL]= %02x %3d %c\n",
                 reg.hl, nas->get(reg.hl), nas->get(reg.hl),
                 isprint(nas->get(reg.hl))?nas->get(reg.hl):'.');
  con->dd_printf("IX= 0x%04x [IX]= %02x %3d %c  ",
                 reg.ix, das->get(reg.ix), das->get(reg.ix),
                 isprint(das->get(reg.ix))?das->get(reg.ix):'.');
  con->dd_printf("IY= 0x%04x [IY]= %02x %3d %c  ",
                 reg.iy, das->get(reg.iy), das->get(reg.iy),
                 isprint(das->get(reg.iy))?das->get(reg.iy):'.');
  con->dd_printf("SP= 0x%04x [SP]= %02x %3d %c\n",
                 reg.sp, nas->get(reg.sp), nas->get(reg.sp),
                 isprint(nas->get(reg.sp))?nas->get(reg.sp):'.');

  print_disass(PC, con);
}

int
cl_tlcs::exec_inst(void)
{
  t_mem c1;//, c2, c3, c4, c5, c6;
  //t_addr instPC= PC;
  int res= resGO;
  
  if (fetch(&c1))
    return resBREAKPOINT;
  tick(1);

  switch (c1)
    {
    case 0x08: res= ex_de_hl(); break;
    case 0x09: res= ex_af_alt_af(); break;
    case 0x0a: res= exx(); break;
    case 0x0b: res= inst_daa_a(); break;
    case 0x10: res= inst_cpl_a(); break;
    case 0x11: res= inst_neg_a(); break;
    case 0x0e: res= inst_ccf(); break;
    case 0x0d: res= inst_scf(); break;
    case 0x0c: res= inst_rcf(); break;
    case 0x00: break; // NOP //res= resGO;
    case 0x01: res= resHALT; break; // HALT
    case 0x02: reg.f&= ~FLAG_I; break; // DI
    case 0x03: reg.f|= FLAG_I; break; // EI
    case 0xff: res= inst_swi(); break;
    case 0xa0: reg.a= op_rlc(reg.a, false); break; // RLCA
    case 0xa1: reg.a= op_rrc(reg.a, false); break; // RRCA
    case 0xa2: reg.a= op_rl(reg.a, false); break; // RLA
    case 0xa3: reg.a= op_rl(reg.a, false); break; // RRA
    case 0xa4: reg.a= op_sla(reg.a, false); break; // SLAA
    case 0xa5: reg.a= op_sra(reg.a, false); break; // SRAA
    case 0xa6: reg.a= op_sla(reg.a, false); break; // SLLA (=SLAA)
    case 0xa7: reg.a= op_srl(reg.a, false); break; // SRLA
    case 0x1e: res= inst_ret(); break;
    case 0x1f: res= inst_reti(); break;
    case 0xe7: res= exec_inst3_e7(c1, fetch(), fetch()); break;
    default:
      {
	switch (c1 & 0xf8)
	  {
	    // r, g, etc coded in single byte instruction
	  case 0x20: reg.a= *aof_reg8(c1); break; // LD A,r
	  case 0x28: *aof_reg8(c1)= reg.a; break; // LD r,A
	  case 0x40: reg.hl= *aof_reg16_rr(c1); break; // LD HL,rr
	  case 0x48: *aof_reg16_rr(c1)= reg.hl; break; // LD rr,HL
	  case 0x50: exec_push(PC-1, *aof_reg16_qq(c1)); break; // PUSH qq
	  case 0x58: res= inst_pop(c1); break; // POP qq
	  case 0x80: *aof_reg8(c1)= op_inc(*aof_reg8(c1)); break; // INC r
	  case 0x88: *aof_reg8(c1)= op_dec(*aof_reg8(c1)); break; // DEC r
	  case 0x90: *aof_reg16_rr(c1)= op_inc16(*aof_reg16_rr(c1)); break; // INC rr
	  case 0x98: *aof_reg16_rr(c1)= op_dec16(*aof_reg16_rr(c1)); break; // DEC rr
	  default:
	    // no more left, check for two byte instructions
	    res= exec_inst2(c1);
	    break;
	  }
	break;
      }
    }

  return res;
}

/*
 *                                                       Decode two byte instructions
 ************************************************************************************
 */

int
cl_tlcs::exec_inst2(uint8_t c1)
{
  uint8_t c2= fetch();
  int res= resGO;
  class cl_memory_cell *n= cell_n(c2);
  
  // first, handle cases where first byte is fix
  switch (c1)
    {
    case 0x07: inst_incx(n); break; // INCX (0ffn)
    case 0x0F: inst_decx(n); break; // DECX (0ffn)
    case 0x12: reg.hl= reg.l * c2; break; // MUL HL,n
    case 0x13: inst_div_hl(c2); break; // DIV HL,n
    case 0x18: inst_djnz_b(c2); break; // DJNZ $+2+d
    case 0x19: inst_djnz_bc(c2); break; // DJNZ BC,$+2+d
    case 0x27: reg.a= n->read(); break; // LD A,(0ffn)
    case 0x2F: n->write(reg.a); break; // LD (0ffn),A
    case 0x47: reg.hl= mem16(0xff00 + c2); break; // LD HL,(0ffn)
    case 0x60: inst_add_a(n); break; // ADD A,(0ffn)
    case 0x61: inst_adc_a(n); break; // ADC A,(0ffn)
    case 0x62: inst_sub_a(n); break; // SUB A,(0ffn)
    case 0x63: inst_sbc_a(n); break; // SBC A,(0ffn)
    case 0x64: inst_and_a(n); break; // AND A,(0ffn)
    case 0x65: inst_xor_a(n); break; // XOR A,(0ffn)
    case 0x66: inst_or_a(n); break; // OR A,(0ffn)
    case 0x67: op_cp_a(n); break; // CP A,(0ffn)
    case 0x68: reg.a= op_add_a(c2); break; // ADD A,n
    case 0x69: inst_adc_a(c2); break; // ADC A,n
    case 0x6A: inst_sub_a(c2); break; // SUB A,n
    case 0x6B: inst_sbc_a(c2); break; // SBC A,n
    case 0x6C: inst_and_a(c2); break; // AND A,n
    case 0x6D: inst_xor_a(c2); break; // XOR A,n
    case 0x6E: inst_or_a(c2); break; // OR A,n
    case 0x6F: op_cp_a(c2); break; // CP A,n
    case 0x70: reg.hl= op_add_hl(t_addr(0xff00+c2)); break; // ADD HL,(0ffn)
    case 0x71: reg.hl= op_adc_hl(t_addr(0xff00+c2)); break; // ADC HL,(0ffn)
    case 0x72: reg.hl= op_sub_hl(t_addr(0xff00+c2)); break; // SUB HL,(0ffn)
    case 0x73: reg.hl= op_sbc_hl(t_addr(0xff00+c2)); break; // SBC HL,(0ffn)
    case 0x74: reg.hl= op_and_hl(t_addr(0xff00+c2)); break; // AND HL,(0ffn)
    case 0x75: reg.hl= op_xor_hl(t_addr(0xff00+c2)); break; // XOR HL,(0ffn)
    case 0x76: reg.hl= op_or_hl(t_addr(0xff00+c2)); break; // OR HL,(0ffn)
    case 0x77: op_sub_hl(t_addr(0xff00+c2)); break; // CP HL,(0ffn)
    case 0x87: inst_inc(n); break; // INC (0ffn)
    case 0x8F: inst_dec(n); break; // DEC (0ffn)
    case 0x97: inst_inc16(t_addr(0xff00+c2)); break; // INCW (0ffn)
    case 0x9F: inst_dec16(t_addr(0xff00+c2)); break; // DECW (0ffn)
    case 0xf3: // c1
      res= exec_inst2_f3(c2);
      break;
    case 0xfe: // c1
      res= exec_inst2_fe(c2);
      break;
    case 0xf7: // c1
      res= exec_inst2_f7(c2);
      break;
    default:
      // now handle cases where first byte is not fix
      switch (c1 & 0x07)
	{
	case 0x30: break; //@ LD r,n
	case 0xe0: // e0+gg
	  res= exec_inst2_e0gg(c1, c2);
	  break;
	case 0xe8: // e8+gg
	  res= exec_inst2_e8gg(c1, c2);
	  break;
	case 0xf8: // f8+g, f8+gg
	  res= exec_inst2_f8gg(c1, c2);
	  break;
	}
      break;
    }
  
  return res;
}


/*                                                                              F3 XX
 */

int
cl_tlcs::exec_inst2_f3(uint8_t c2)
{
  int res= resGO;
  
  switch (c2)
    {
      // handle c1==f3 cases where second byte is fix
    case 0x10: res= inst_rld(cell_hl_a()); break; // RLD (HL+A)
    case 0x11: res= inst_rrd(cell_hl_a()); break; // SLL (HL+A)
    case 0x12: res= inst_mul_hl(cell_hl_a()); break; // MUL HL,(HL+A)
    case 0x13: res= inst_div_hl(cell_hl_a()); break; // DIV HL,(HL+A)
    case 0x60: res= inst_add_a(cell_hl_a()); break; // ADD A,(HL+A)
    case 0x61: res= inst_adc_a(cell_hl_a()); break; // ADC A,(HL+A)
    case 0x62: res= inst_sub_a(cell_hl_a()); break; // SUB A,(HL+A)
    case 0x63: res= inst_sbc_a(cell_hl_a()); break; // SBC A,(HL+A)
    case 0x64: res= inst_and_a(cell_hl_a()); break; // AND A,(HL+A)
    case 0x65: res= inst_xor_a(cell_hl_a()); break; // XOR A,(HL+A)
    case 0x66: res= inst_or_a(cell_hl_a()); break; // OR A,(HL+A)
    case 0x67: res= op_cp_a(cell_hl_a()); break; // CP A,(HL+A)
    case 0x70: reg.hl= op_add_hl((t_addr)(reg.hl+reg.a)); break; // ADD HL,(HL+A)
    case 0x71: reg.hl= op_adc_hl((t_addr)(reg.hl+reg.a)); break; // ADC HL,(HL+A)
    case 0x72: reg.hl= op_sub_hl((t_addr)(reg.hl+reg.a)); break; // SUB HL,(HL+A)
    case 0x73: reg.hl= op_sbc_hl((t_addr)(reg.hl+reg.a)); break; // SBC HL,(HL+A)
    case 0x74: reg.hl= op_and_hl((t_addr)(reg.hl+reg.a)); break; // AND HL,(HL+A)
    case 0x75: reg.hl= op_xor_hl((t_addr)(reg.hl+reg.a)); break; // XOR HL,(HL+A)
    case 0x76: reg.hl= op_or_hl((t_addr)(reg.hl+reg.a)); break; // OR HL,(HL+A)
    case 0x77: reg.hl= op_sub_hl((t_addr)(reg.hl+reg.a)); break; // CP HL,(HL+A)
    case 0x87: inst_inc(cell_hl_a()); break; // INC (HL+A)
    case 0x8f: inst_dec(cell_hl_a()); break; // DEC (HL+A)
    case 0x97: inst_inc16((t_addr)(reg.hl+reg.a)); break; // INCW (HL+A)
    case 0x9f: inst_dec16((t_addr)(reg.hl+reg.a)); break; // DECW (HL+A)
    case 0xa0: inst_rlc(cell_hl_a()); break; // RLC (HL+A)
    case 0xa1: inst_rrc(cell_hl_a()); break; // RRC (HL+A)
    case 0xa2: inst_rl(cell_hl_a()); break; // RL (HL+A)
    case 0xa3: inst_rr(cell_hl_a()); break; // RR (HL+A)
    case 0xa4: inst_sla(cell_hl_a()); break; // SLA (HL+A)
    case 0xa5: inst_sra(cell_hl_a()); break; // SRA (HL+A)
    case 0xa6: inst_sla(cell_hl_a()); break; // SLL (HL+A)
    case 0xa7: inst_srl(cell_hl_a()); break; // SRL (HL+A)
    default:
      // handle c1==f3 cases where second byte is not fix
      if ((c2 & 0xfc) == 0x14) // ADD ix,(HL+A)
	{
	  uint16_t *op1= aof_reg16_ix(c2);
	  uint16_t op2= mem16(reg.hl+reg.a);
	  *op1= add16(*op1, op2);
	}
      else
	switch (c2 & 0xf8)
	  {
	  case 0x18: // TSET b,(HL+A)
	    {
	      cl_memory_cell *c= cell_hl_a();
	      uint8_t v= c->read();
	      c->write(op_tset(v, c2));
	      break;
	    }
	  case 0x28: *aof_reg8(c2)= cell_hl_a()->read(); break; // LD r,(HL+A)
	  case 0x48: *aof_reg16_rr(c2)= mem16(reg.hl+reg.a); break; // LD rr,(HL+A)
	  case 0x50: // EX (HL+A),rr
	    {
	      cl_memory_cell *c= cell_hl_a();
	      uint16_t t= c->read(), *r= aof_reg16_rr(c2);
	      c->write(*r);
	      *r= t;
	      break;
	    }
	  case 0xa8: op_bit(cell_hl_a()->read(), c2); break; // BIT b,(HL+A)
	  case 0xb0: // RES b,(HL+A)
	    {
	      cl_memory_cell *c= cell_hl_a();
	      uint8_t v= op_res(c->read(), c2);
	      c->write(v);
	      break;
	    }
	  case 0xb8: // SET b,(HL+A)
	    {
	      cl_memory_cell *c= cell_hl_a();
	      uint8_t v= op_set(c->read(), c2);
	      c->write(v);
	      break;
	    }
	  default:
	    break;
	  }
      break;
    }
  return res;
}

/*                                                                              F7 XX
 */

int
cl_tlcs::exec_inst2_f7(uint8_t c2)
{
  int res= resGO;
  
  switch (c2 & 0xf0)
    {
    case 0xc0: if (cc(c2)) PC= reg.hl|reg.a; break; // JP [cc,]HL+A
    case 0xd0: if (cc(c2)) inst_call(PC-2, reg.hl+reg.a); break; // CALL [cc,]HL+A
    default:
      switch (c2 & 0xf8)
	{
	case 0x20: cell_hl_a()->write(*aof_reg8(c2)); break; // LD (HL+A),r
	case 0x38: *aof_reg16_rr(c2)= reg.hl+reg.a; break; // LDA rr,HL+A
	case 0x40: write16(reg.hl+reg.a, *aof_reg16_rr(c2)); break; // LD (HL+A),rr
	}
    }
  return res;
}

/*                                                                              FE XX
 */

int
cl_tlcs::exec_inst2_fe(uint8_t c2)
{
  int res= resGO;
  
  if ((c2 & 0xf0) == 0xd0) // RET cc
    {
      if (cc(c2)) inst_ret();
    }
  else
    switch (c2)
      {
      case 0x58: ldi(); break;
      case 0x59: ldir(); break;
      case 0x5a: ldd(); break;
      case 0x5b: lddr(); break;
      case 0x5c: cpi(); break;
      case 0x5d: cpir(); break;
      case 0x5e: cpd(); break;
      case 0x5f: cpdr(); break;
      }
  return res;
}

/*                                                                           E0+gg XX
 */

int
cl_tlcs::exec_inst2_e0gg(uint8_t c1, uint8_t c2)
{
  int res= resGO;
  cl_memory_cell *gg= cell_gg(c1);
  
  switch (c2)
    {
    case 0x10: inst_rld(gg); break; // RLD (gg)
    case 0x11: inst_rrd(gg); break; // RRD (gg)
    case 0x12: inst_mul_hl(gg); break; // MUL HL,(gg)
    case 0x13: inst_div_hl(gg); break; // DIV HL,(gg)
    case 0x60: inst_add_a(gg); break; // ADD A,(gg)
    case 0x61: inst_adc_a(gg); break; // ADC A,(gg)
    case 0x62: inst_sub_a(gg); break; // SUB,A(gg)
    case 0x63: inst_sbc_a(gg); break; // SBC A,(gg)
    case 0x64: inst_and_a(gg); break; // AND A(gg)
    case 0x65: inst_xor_a(gg); break; // XOR A(gg)
    case 0x66: inst_or_a(gg); break; // OR A,(gg)
    case 0x67: op_cp_a(gg); break; // CP A,(gg)
    case 0x70: reg.hl= op_add_hl((t_addr)*aof_reg16_gg(c1)); break; // ADD HL,(gg)
    case 0x71: reg.hl= op_adc_hl((t_addr)*aof_reg16_gg(c1)); break; // ADC HL,(gg)
    case 0x72: reg.hl= op_sub_hl((t_addr)*aof_reg16_gg(c1)); break; // SUB HL,(gg)
    case 0x73: reg.hl= op_sbc_hl((t_addr)*aof_reg16_gg(c1)); break; // SBC HL,(gg)
    case 0x74: reg.hl= op_and_hl((t_addr)*aof_reg16_gg(c1)); break; // AND HL,(gg)
    case 0x75: reg.hl= op_xor_hl((t_addr)*aof_reg16_gg(c1)); break; // XOR HL,(gg)
    case 0x76: reg.hl= op_or_hl((t_addr)*aof_reg16_gg(c1)); break; // OR HL,(gg)
    case 0x77: reg.hl= op_sub_hl((t_addr)*aof_reg16_gg(c1)); break; // CP HL,(gg)
    case 0x87: inst_inc(gg); break; // INC (gg)
    case 0x8f: inst_dec(gg); break; // DEC (gg)
    case 0x97: inst_inc16(*aof_reg16_gg(c1)); break; // INCW (gg)
    case 0x9f: inst_dec16(*aof_reg16_gg(c1)); break; // DECW (gg)
    case 0xa0: inst_rlc(gg); break; // RLC (gg)
    case 0xa1: inst_rrc(gg); break; // RRC (gg)
    case 0xa2: inst_rl(gg); break; // RL (gg)
    case 0xa3: inst_rr(gg); break; // RR (gg)
    case 0xa4: inst_sla(gg); break; // SLA (gg)
    case 0xa5: inst_sra(gg); break; // SRA (gg)
    case 0xa6: inst_sla(gg); break; // SLL (gg)
    case 0xa7: inst_srl(gg); break; // SRL (gg)
    default:
      if ((c2 & 0xfc) == 0x14) // ADD ix,(gg)
	{
	  uint16_t *ix= aof_reg16_ix(c2);
	  *ix= add16(*ix, mem16(*aof_reg16_gg(c1)));
	}
      else
	switch (c2 & 0xf8)
	  {
	  case 0x18: inst_tset(cell_gg(c1), c2); break; // TSET b,(gg)
	  case 0x28: *aof_reg8(c2)= cell_gg(c1)->read(); break; // LD r,(gg)
	  case 0x48: *aof_reg16_rr(c2)= mem16(*aof_reg16_gg(c1)); break; // LD rr,(gg)
	  case 0x50: // EX (gg),rr
	    {
	      uint16_t *ra= aof_reg16_rr(c2);
	      uint16_t r= *ra;
	      uint16_t ga= *aof_reg16_gg(c1);
	      *ra= mem16(ga);
	      write16(ga, r);
	      break;
	    }
	  case 0xa8: inst_bit(cell_gg(c1), c2); break; // BIT b,(gg)
	  case 0xb0: inst_res(cell_gg(c1), c2); break; // RES b,(gg)
	  case 0xb8: inst_set(cell_gg(c1), c2); break; // SET b,(gg)
	  }
    }
  
  return res;
}

/*                                                                           E8+gg XX
 */

int
cl_tlcs::exec_inst2_e8gg(uint8_t c1, uint8_t c2)
{
  int res= resGO;
  class cl_memory_cell *gg= cell_gg(c1);
  t_addr gv= *aof_reg16_gg(c1);
  
  switch (c2 & 0xf0)
    {
    case 0xc0: if (cc(c2)) PC= gv; break; // JP [cc,]gg
    case 0xd0: if (cc(c2)) inst_call(PC-2, gv); break; // CALL [cc,]gg
    default:
      switch (c2 & 0xf8)
	{
	case 0x20: gg->write(*aof_reg8(c2)); break; // LD (gg),r
	case 0x40: write16(gv, *aof_reg16_rr(c2)); break; // LD (gg),rr
	}
      break;
    }
  return res;
}

/*                                                                  F8+g XX, F8+gg XX
 */

int
cl_tlcs::exec_inst2_f8gg(uint8_t c1, uint8_t c2)
{
  int res= resGO;
  uint8_t *ga= aof_reg8(c1);
  uint16_t *gga= aof_reg16_gg(c1);

  switch (c2)
    {
    case 0x12: reg.hl= reg.l * (*ga); break; // MUL HL,g
    case 0x13: inst_div_hl(*ga); break; // DIV HL,g
    case 0x60: reg.a= op_add_a(*ga); break; // ADD A,g
    case 0x61: inst_adc_a(*ga); break; // ADC A,g
    case 0x62: inst_sub_a(*ga); break; // SUB A,g
    case 0x63: inst_sbc_a(*ga); break; // SBC A,g
    case 0x64: inst_and_a(*ga); break; // AND A,g
    case 0x65: inst_xor_a(*ga); break; // XOR A,g
    case 0x66: inst_or_a(*ga); break; // OR A,g
    case 0x67: op_cp_a(*ga); break; // CP A,g
    case 0x70: reg.hl= op_add_hl((t_mem)*gga); break; // ADD HL,gg
    case 0x71: reg.hl= op_adc_hl((t_mem)*gga); break; // ADC HL,gg
    case 0x72: reg.hl= op_sub_hl((t_mem)*gga); break; // SUB HL,gg
    case 0x73: reg.hl= op_sbc_hl((t_mem)*gga); break; // SBC HL,gg
    case 0x74: reg.hl= op_and_hl((t_mem)*gga); break; // AND HL,gg
    case 0x75: reg.hl= op_xor_hl((t_mem)*gga); break; // XOR HL,gg
    case 0x76: reg.hl= op_or_hl((t_mem)*gga); break; // OR HL,gg
    case 0x77: op_sub_hl((t_mem)*gga); break; // CP HL,gg
    case 0xA0: *ga= op_rlc(*ga, true); break; // RLC g
    case 0xA1: *ga= op_rrc(*ga, true); break; // RRC g
    case 0xA2: *ga= op_rl(*ga, true); break; // RL g
    case 0xA3: *ga= op_rr(*ga, true); break; // RR g
    case 0xA4: *ga= op_sla(*ga, true); break; // SLA g
    case 0xA5: *ga= op_sra(*ga, true); break; // SRA g
    case 0xA6: *ga= op_sla(*ga, true); break; // SLL g
    case 0xA7: *ga= op_srl(*ga, true); break; // SRL g
    default:
      if ((c2 & 0xfc) == 0x14) // ADD ix,gg
	*aof_reg16_ix(c2)= add16(*aof_reg16_ix(c2), *gga);
      else
	switch (c2 & 0xf8)
	  {
	  case 0x18: *ga= op_tset(*ga, c2); break; // TSET b,g
	  case 0x30: *aof_reg8(c2)= *ga; break; // LD r,g
	  case 0x38: *aof_reg16_rr(c2)= *gga; break; // LD rr,gg
	  case 0xa8: *ga= op_bit(*ga, c2); break; // BIT b,g
	  case 0xb0: *ga= op_res(*ga, c2); break; // RES b,g
	  case 0xb8: *ga= op_set(*ga, c2); break; // SET b,g
	  }
      break;
    }
  
  return res;
}

/*
 */

int
cl_tlcs::exec_inst3_e7(uint8_t c1, uint8_t c2, uint8_t c3)
{
  int res= resGO;
  cl_memory_cell *n= cell_n(c2);
  
  switch (c3)
    {
    case 0x10: inst_rld(n); break; // RLD (0ffn)
    case 0x11: inst_rrd(n); break; // RRD (0ffn)
    case 0x12: inst_mul_hl(n); break; // MUL HL,(0ffn)
    case 0x13: inst_div_hl(n); break; // DIV HL,(0ffn)
    case 0xa0: inst_rlc(n); break; // RLC (0ffn)
    case 0xa1: inst_rrc(n); break; // RRC (0ffn)
    case 0xa2: inst_rl(n); break; // RL (0ffn)
    case 0xa3: inst_rr(n); break; // RR (0ffn)
    case 0xa4: inst_sla(n); break; // SLA (0ffn)
    case 0xa5: inst_sra(n); break; // SRA (0ffn)
    case 0xa6: inst_sla(n); break; // SLL (0ffn)
    case 0xa7: inst_srl(n); break; // SRL (0ffn)
    default:
      if ((c3 & 0xfc) == 0x14) // ADD ix,(0ffn)
	{
	  uint16_t *aix= aof_reg16_ix(c3);
	  *aix= add16(*aix, mem16(0xff00 + c2));
	}
      else
	switch (c3 & 0xf8)
	  {
	  case 0x18: inst_tset(n, c3); break; // TSET b,(0ffn)
	  case 0x28: *aof_reg8(c3)= n->read(); break; // LD r,(0ffn)
	  case 0x48: *aof_reg16_rr(c3)= mem16(0xff00 + c2); break; // LD rr,(0ffn);
	  }
      break;
    }
  
  return res;
}


t_addr
cl_tlcs::do_push(t_mem data)
{
  t_addr sp_before= reg.sp;
  reg.sp-= 1;
  nas->write(reg.sp, (data>>8)&0xff);
  reg.sp-= 1;
  nas->write(reg.sp, (data&0xff));
  return sp_before;
}

t_addr
cl_tlcs::do_pop(t_mem *data)
{
  t_addr sp_before= reg.sp;
  t_mem val;
  val= nas->read(reg.sp);
  reg.sp+= 1;
  val= (nas->read(reg.sp) * 256) + val;
  reg.sp+= 1;
  if (data)
    *data= val;
  return sp_before;
}

int
cl_tlcs::exec_push(t_addr PC_of_inst, t_mem data)
{
  t_addr sp_before= do_push(data);
  class cl_stack_push *o= new cl_stack_push(PC_of_inst, data, sp_before, reg.sp);
  o->init();
  stack_write(o);
  return resGO;
}

int
cl_tlcs::exec_ret(t_addr PC_of_inst, t_mem *data)
{
  t_addr sp_before= do_pop(data);
  t_mem val= 0;
  if (data)
    val= *data;
  class cl_stack_ret *o= new cl_stack_ret(PC_of_inst, val, sp_before, reg.sp);
  o->init();
  stack_write(o);
  return resGO;
}

int
cl_tlcs::exec_reti(t_addr PC_of_inst, t_mem *data)
{
  t_addr sp_before= do_pop(data);
  t_mem val= 0;
  if (data)
    val= *data;
  class cl_stack_iret *o= new cl_stack_iret(PC_of_inst, val, sp_before, reg.sp);
  o->init();
  stack_write(o);
  return resGO;
}

int
cl_tlcs::exec_pop(t_addr PC_of_inst, t_mem *data)
{
  t_addr sp_before= do_pop(data);
  t_mem val= 0;
  if (data)
    val= *data;
  class cl_stack_pop *o= new cl_stack_pop(PC_of_inst, val, sp_before, reg.sp);
  o->init();
  stack_write(o);
  return resGO;
}

int
cl_tlcs::exec_intr(t_addr PC_of_inst, t_addr called, t_mem data)
{
  t_addr sp_before= do_push(data);
  class cl_stack_intr *o= new cl_stack_intr(PC_of_inst, called, data, sp_before, reg.sp);
  o->init();
  stack_write(o);
  return resGO;
}

int
cl_tlcs::exec_call(t_addr PC_of_inst, t_addr called, t_mem data)
{
  t_addr sp_before= do_push(data);
  class cl_stack_call *o= new cl_stack_call(PC_of_inst, called, data, sp_before, reg.sp);
  o->init();
  stack_write(o);
  return resGO;
}

void
cl_tlcs::set_p(uint8_t data)
{
  // P=1 means EVEN
  int b= 0, i;

  for (i= 0; i < 8; i++)
    {
      if (data & 1)
	b++;
      data>>= 1;
    }
  if (b&1)
    // ODD, P <- 0
    reg.f&= ~FLAG_V;
  else
    // EVEN, P <- 1
    reg.f|= FLAG_V;
}

uint8_t *
cl_tlcs::aof_reg8(uint8_t data_r)
{
  switch (data_r & 0x07)
    {
    case 0: return &reg.b;
    case 1: return &reg.c;
    case 2: return &reg.d;
    case 3: return &reg.e;
    case 4: return &reg.h;
    case 5: return &reg.l;
    case 6: return &reg.a;
    default: return &reg.dummy;
    }
}

uint16_t *
cl_tlcs::aof_reg16_rr(uint8_t data_rr)
{
  switch (data_rr & 0x07)
    {
    case 0: return &reg.bc;
    case 1: return &reg.de;
    case 2: return &reg.hl;
    case 4: return &reg.ix;
    case 5: return &reg.iy;
    case 6: return &reg.sp;
    default: return &reg.dummy16;
    }
}

uint16_t *
cl_tlcs::aof_reg16_qq(uint8_t data_qq)
{
  switch (data_qq & 0x07)
    {
    case 0: return &reg.bc;
    case 1: return &reg.de;
    case 2: return &reg.hl;
    case 4: return &reg.ix;
    case 5: return &reg.iy;
    case 6: return &reg.af;
    default: return &reg.dummy16;
    }
}

uint16_t *
cl_tlcs::aof_reg16_ix(uint8_t data_ix)
{
  switch (data_ix & 0x03)
    {
    case 0: return &reg.ix;
    case 1: return &reg.iy;
    case 2: return &reg.sp;
    default: return &reg.dummy16;
    }
}

uint16_t *
cl_tlcs::aof_reg16_gg(uint8_t data_gg)
{
  return aof_reg16_rr(data_gg);
}

class cl_memory_cell *
cl_tlcs::cell_hl_a()
{
  return nas->get_cell(reg.hl + reg.a);
}

class cl_memory_cell *
cl_tlcs::cell_gg(uint8_t gg)
{
  return nas->get_cell(*aof_reg16_gg(gg));
}

class cl_memory_cell *
cl_tlcs::cell_n(uint8_t n)
{
  return nas->get_cell(0xff00 + n);
}

uint16_t
cl_tlcs::mem16(t_addr addr)
{
  uint8_t l, h;

  l= nas->read(addr);
  h= nas->read(addr+1);

  return h*256 + l;
}

void
cl_tlcs::write16(t_addr addr, uint16_t val)
{
  nas->write(addr, val & 0xff);
  nas->write(addr|1, val / 256);
}


uint16_t
cl_tlcs::xmem16(t_addr addr)
{
  uint8_t l, h;

  l= das->read(addr);
  h= das->read(addr+1);

  return h*256 + l;
}

void
cl_tlcs::xwrite16(t_addr addr, uint16_t val)
{
  das->write(addr, val & 0xff);
  das->write(addr|1, val / 256);
}

bool
cl_tlcs::flag(enum tlcs_flags f)
{
  return (reg.f & f)?true:false;
}

bool
cl_tlcs::cc(uint8_t cc)
{
  bool s= flag(FLAG_S);
  bool v= flag(FLAG_V);
  switch (cc & 0x0f)
    {
    case 0: return false;
    case 1: return (s && !v) || (!s && v);
    case 2: return flag(FLAG_Z) || ((s && !v) || (!s && v));
    case 3: return flag(FLAG_C) || flag(FLAG_Z);
    case 4: return v;
    case 5: return s;
    case 6: return reg.f & FLAG_Z;
    case 7: return reg.f & FLAG_C;
    case 8: return true;
    case 9: return !((s && !v) || (!s && v));
    case 10: return !(flag(FLAG_Z) || ((s && !v) || (!s && v)));
    case 11: return !(flag(FLAG_C) || flag(FLAG_Z));
    case 12: return !v;
    case 13: return !s;
    case 14: return !(reg.f & FLAG_Z);
    case 15: return !(reg.f & FLAG_C);
    }
  return false;
}


/* End of tlcs.src/tlcs.cc */
