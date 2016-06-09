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
}

int
cl_tlcs::init(void)
{
  cl_uc::init(); /* Memories now exist */
  //ram= address_space(MEM_IRAM_ID);
  //rom= address_space(MEM_ROM_ID);

  reg.bc= 0;
  reg.d= 0;
  reg.e= 0;
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
cl_tlcs::disass(t_addr addr, const char *sep)
{
  struct dis_entry *de;
  uint64_t c;
  int i;
  chars s("");
  char *buf, *t;
  
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
	    case 'r': s+= regname_r(c); break;
	    case 'R': s+= regname_R(c); break;
	    case 'Q': s+= regname_Q(c); break;
	    default: s+= '?'; break;
	    }
	}
      else
	s+= *t;
    }
  
  buf= strdup(s);
  return buf;
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
    case 0x0b: res= daa_a(); break;
    case 0x10: res= cpl_a(); break;
    case 0x11: res= neg_a(); break;
    case 0x0e: res= ccf(); break;
    case 0x0d: res= scf(); break;
    case 0x0c: res= rcf(); break;
    case 0x00: break; // NOP //res= resGO;
    case 0x01: res= resHALT; break; // HALT
    case 0x02: reg.f&= ~FLAG_I; break; // DI
    case 0x03: reg.f|= FLAG_I; break; // EI
    case 0xff: res= swi(); break;
    case 0xa0: reg.a= rlc(reg.a, false); break; // RLCA
    case 0xa1: reg.a= rrc(reg.a, false); break; // RRCA
    case 0xa2: reg.a= rl(reg.a, false); break; // RLA
    case 0xa3: reg.a= rl(reg.a, false); break; // RRA
    case 0xa4: reg.a= sla(reg.a, false); break; // SLAA
    case 0xa5: reg.a= sra(reg.a, false); break; // SRAA
    case 0xa6: reg.a= sla(reg.a, false); break; // SLLA (=SLAA)
    case 0xa7: reg.a= srl(reg.a, false); break; // SRLA
    case 0x1e: res= ret(); break;
    case 0x1f: res= reti(); break;
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
	  case 0x58: res= pop(c1); break; // POP qq
	  case 0x80: *aof_reg8(c1)= inc(*aof_reg8(c1)); break; // INC r
	  case 0x88: *aof_reg8(c1)= dec(*aof_reg8(c1)); break; // DEC r
	  case 0x90: *aof_reg16_rr(c1)= inc16(*aof_reg16_rr(c1)); break; // INC rr
	  case 0x98: *aof_reg16_rr(c1)= dec16(*aof_reg16_rr(c1)); break; // DEC rr
	  }
      }
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


/* End of tlcs.src/tlcs.cc */
