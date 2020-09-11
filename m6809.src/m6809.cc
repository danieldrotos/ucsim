/*
 * Simulator of microcontrollers (m6809.cc)
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

#include <stdlib.h>
#include <ctype.h>

#include "glob.h"

#include "m6809cl.h"


cl_m6809::cl_m6809(class cl_sim *asim):
  cl_uc(asim)
{
}

int
cl_m6809::init(void)
{
  cl_uc::init();
  reg.DP= 0;
  PC= 0;
  return 0;
}

const char *
cl_m6809::id_string(void)
{
  return "M6809";
}

void
cl_m6809::reset(void)
{
  PC= 0;
  reg.DP= 0;
}
  
void
cl_m6809::set_PC(t_addr addr)
{
  PC= addr;
}

void
cl_m6809::mk_hw_elements(void)
{
  cl_uc::mk_hw_elements();
}

void
cl_m6809::make_memories(void)
{
  class cl_address_space *as;
  
  rom= as= new cl_address_space("rom"/*MEM_ROM_ID*/, 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  class cl_address_decoder *ad;
  class cl_memory_chip *chip;

  chip= new cl_memory_chip("rom_chip", 0x10000, 8);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as= rom/*address_space(MEM_ROM_ID)*/,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);

  /*
  regs= new cl_address_space("regs", 0, 16, 32);
  regs->init();
  for (i= 0; i<16; i++)
    {
      RC[i]= regs->get_cell(i);
      RC[i]->decode((t_mem*)&R[i]);
    }
  address_spaces->add(regs);

  class cl_var *v;
  for (i=0; i<16; i++)
    {
      v= new cl_var(chars("", "R%d", i), regs, i, chars("", "CPU register %d",i));
      v->init();
      vars->add(v);
    }
  */
}


struct dis_entry *
cl_m6809::dis_tbl(void)
{
  return(disass_m6809);
}

char *
cl_m6809::disass(t_addr addr, const char *sep)
{
  chars work= chars(), temp= chars();
  const char *b;
  t_mem code;
  int i;

  //work= "";
  //p= (char*)work;

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

  work= b;
  
  return strdup(work.c_str());
}

void
cl_m6809::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("A= 0x%02x %3d %c  ", A, A, isprint(A)?A:'.');
  con->dd_printf("B= 0x%02x %3d %c  ", B, B, isprint(B)?B:'.');
  con->dd_printf("D= 0x%04x %5d\n", D, D);
  con->dd_printf("CC= "); con->print_bin(reg.CC, 8); con->dd_printf("\n");
  con->dd_printf("    EFHINZVC\n");

  con->dd_printf("X= ");
  rom->dump(reg.X, reg.X+7, 8, con);
  con->dd_color("answer");
  
  con->dd_printf("Y= ");
  rom->dump(reg.Y, reg.Y+7, 8, con);
  con->dd_color("answer");
  
  con->dd_printf("S= ");
  rom->dump(reg.S, reg.S+7, 8, con);
  con->dd_color("answer");
  
  con->dd_printf("U= ");
  rom->dump(reg.U, reg.U+7, 8, con);
  con->dd_color("answer");
  
  print_disass(PC, con);
}


int
cl_m6809::inst_add8(t_mem code, u8_t *dest, u8_t op, int c, bool store)
{
  u8_t r;
  unsigned int d= *dest;
  unsigned int o= op;
  signed int res= (signed char)d + (signed char)o;

  if (c) { ++res, ++o; }
  
  reg.CC= ~(H|V|S|Z);
  if ((d & 0xf) + (o & 0xf) > 0xf)  reg.CC|= H;
  if ((res < -128) || (res > +127)) reg.CC|= V;
  if (d + o > 0xff)                 reg.CC|= C;

  r= res & 0xff;
  if (r == 0)   reg.CC|= Z;
  if (r & 0x80) reg.CC|= S;

  if (store)
    *dest= r;
  
  return resGO;
}

int
cl_m6809::inst_bool(t_mem code, char bop, u8_t *dest, u8_t op, bool store)
{
  u8_t r;

  switch (bop)
    {
    case '&': r= *dest & op; break;
    case '|': r= *dest | op; break;
    case '^': r= *dest ^ op; break;
    }

  if (store)
    *dest= r;

  SET_O(0);
  SET_Z(r);
  SET_S(r&0x80);
  
  return resGO;
}

int
cl_m6809::inst_alu(t_mem code)
{
  u8_t *dest, op8;
  t_addr ea;
  
  if (code == 0x87 ||
      code == 0xc7 ||
      code == 0xcd ||
      code == 0x8f ||
      code == 0xcf)
    return resINV_INST;
  
  dest= (code & 0x40)? (&B) : (&A);

  switch (code & 0x30)
    {
    case 0x00: // immed
      op8= fetch();
      break;
    case 0x10: // direct
      ea= reg.DP*256 + fetch();
      op8= rom->read(ea);
      break;
    case 0x20: // index
      break;
    case 0x30: // extend
      ea= fetch()*256 + fetch();
      op8= rom->read(ea);
      break;
    }

  switch (code & 0x0f)
    {
      //          8    9    A    B    C    D    E    F
    case 0x00: // SUB  SUB  SUB  SUB  SUB  SUB  SUB  SUB
      return inst_add8(code, dest, ~op8, 1, true);
      break;
    case 0x01: // CMP  CMP  CMP  CMP  CMP  CMP  CMP  CMP
      return inst_add8(code, dest, ~op8, 1, false);
      break;
    case 0x02: // SBC  SBC  SBC  SBC  SBC  SBC  SBC  SBC
      return inst_add8(code, dest, ~op8, (reg.CC&C)?1:0, true);
      break;
    case 0x03: // SUBD SUBD SUBD SUBD ADDD ADDD ADDD ADDD
      break;
    case 0x04: // AND  AND  AND  AND  AND  AND  AND  AND
      return inst_bool(code, '&', dest, op8, true);
      break;
    case 0x05: // BIT  BIT  BIT  BIT  BIT  BIT  BIT  BIT
      break;
    case 0x06: // LD   LD   LD   LD   LD   LD   LD   LD
      break;
    case 0x07: // --   STA  STA  STA  --   STB  STB  STB
      break;
    case 0x08: // EOR  EOR  EOR  EOR  EOR  EOR  EOR  EOR
      return inst_bool(code, '^', dest, op8, true);
      break;
    case 0x09: // ADC  ADC  ADC  ADC  ADC  ADC  ADC  ADC
      return inst_add8(code, dest, op8, (reg.CC&C)?1:0, true);
      break;
    case 0x0a: // OR   OR   OR   OR   OR   OR   OR   OR
      return inst_bool(code, '|', dest, op8, true);
      break;
    case 0x0b: // ADD  ADD  ADD  ADD  ADD  ADD  ADD  ADD
      return inst_add8(code, dest, op8, 0, true);
      break;
    case 0x0c: // CMPX CMPX CMPX CMPX LDD  LDD  LDD  LDD
      break;
    case 0x0d: // BSR  JSR  JSR  JSR  --   STD  STD  STD
      break;
    case 0x0e: // LDX  LDX  LDX  LDX  LDX  LDX  LDX  LDX
      break;
    case 0x0f: // --   STX  STX  STX  --   STU  STU  STU
      break;
    }
  
  return resGO;
}

int
cl_m6809::inst_low(t_mem code)
{
  switch (code & 0x0f)
    {
      //          0     1     2     3     4     5     6     7
    case 0x00: // NEG   pg1   BRA   LEAX  NEGA  NEGB  NEG   NEG
      break;
    case 0x01: // --    pg2   BRN   LEAY  --    --    --    --
      break;
    case 0x02: // --    NOP   BHI   LEAS  --    --    --    --
      break;
    case 0x03: // COM   SYNC  BLS   LEAU  COMA  COMB  COM   COM
      break;
    case 0x04: // LSR   --    BHS   PSHS  LSRA  LSRB  LSR   LSR
      break;
    case 0x05: // --    --    BLO   PULS  --    --    --    --
      break;
    case 0x06: // ROR   LBRA  BNE   PSHU  RORA  RORB  ROR   ROR
      break;
    case 0x07: // ASR   LBSR  BEQ   PULU  ASRA  ASRB  ASR   ASR
      break;
    case 0x08: // ALSL  --    BVC   --    ALSLA ALSLB ALSL  ALSL
      break;
    case 0x09: // ROL   DAA   BVS   RTS   ROLA  ROLB  ROL   ROL
      break;
    case 0x0a: // DEC   ORCC  BPL   ABX   DECA  DECB  DEC   DEC
      break;
    case 0x0b: // --    --    BMI   RTI   --    --    --    --
      break;
    case 0x0c: // INC   ANDCC BGE   CWAI  INCA  INCB  INC   INC
      break;
    case 0x0d: // TST   SEX   BLT   MUL   TSTA  TSTB  TST   TST
      break;
    case 0x0e: // JMP   EXG   BGT   RESET --    --    JMP   JMP
      break;
    case 0x0f: // CLR   TFR   BLE   SWI   CLRA  CLRB  CLR   CLR
      break;
    }
  
  return resGO;
}

int
cl_m6809::exec_inst(void)
{
  t_mem code;
  bool fe;
  
  fe= fetch(&code);
  tick(1);
  if (fe)
    return(resBREAKPOINT);

  if (code & 0x80)
    return inst_alu(code);
  else
    return inst_low(code);
  
  return resGO;
}


/* End of m6809.src/m6809.cc */
