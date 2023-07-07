/*
 * Simulator of microcontrollers (i8020cl.h)
 *
 * Copyright (C) 2022 Drotos Daniel, Talker Bt.
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


#ifndef I8020CL_HEADER
#define I8020CL_HEADER

#include "uccl.h"

#include "aliases.h"


enum {
  flagC = 0x80,
  flagA = 0x40,
  flagAC= 0xc0,
  flagCA= 0xc0,
  flagF0= 0x20,
  flagBS= 0x10
};

#define ACC rA
#define A   rA
#define acc rA
#define rF  psw
#define cF  (*cpsw)
#define A11 mb
#define DBF mb

#define MP  t_mem code
#define CL2 cl_i8020
#define CL4 cl_i8048

#define RD   (vc.rd++)
#define WR   (vc.wr++)
#define RDWR (vc.rd++,vc.wr++)
#define WRRD (vc.rd++,vc.wr++)


/*
 * Special handling of flags
 */

class cl_flag20_op: public cl_memory_operator
{
public:
  cl_flag20_op(class cl_memory_cell *acell): cl_memory_operator(acell) {}
  virtual t_mem write(t_mem val);
};

class cl_bool_op: public cl_memory_operator
{
public:
  cl_bool_op(class cl_memory_cell *acell): cl_memory_operator(acell) {}
  virtual t_mem write(t_mem val) { return val?1:0; }
};

class cl_pc_op: public cl_memory_operator
{
public:
  cl_pc_op(class cl_memory_cell *acell): cl_memory_operator(acell) {}
  virtual t_mem write(t_mem val) { return val&0xfff; }
};


/*
 * i8048 processor
 */

class cl_i8020: public cl_uc
{
 public:
  u8_t psw;
  class cl_cell8 *cpsw;
  u8_t flagF1, mb, rA;
  class cl_bit_cell8 cflagF1, cmb;
  class cl_address_space *regs, *aspsw, *iram, *ports;
  class cl_cell8 cA, *R[8];
  class cl_memory_chip *rom_chip, *iram_chip, *ports_chip;
 public:
  cl_i8020(class cl_sim *asim);
  virtual int init(void);
  virtual const char *id_string(void);
  virtual void set_PC(t_addr addr);
  virtual void make_memories(void);
  virtual void make_address_spaces(void);
  virtual void make_chips(void);
  virtual void decode_regs(void);
  virtual void decode_rom(void);
  virtual void decode_iram(void);
  virtual struct dis_entry *dis_tbl(void);
  virtual struct dis_entry *get_dis_entry(t_addr addr);
  virtual char *disassc(t_addr addr, chars *comment);
  virtual void print_regs(class cl_console_base *con);

  virtual void reset(void);
  virtual int exec_inst(void);

  virtual class cl_memory_cell *iram_ir(int regnr);
  
  virtual int add(u8_t op2, bool addc);
  virtual int inc(class cl_memory_cell *op);
  
  virtual int jmp(MP);

  virtual int in(int port_addr);
  
  /*
#define GEN_METHOD
#include "decode.h"
#undef GEN_METHOD
  */
  int NOP(MP) { return resGO; }
  
  int ADDI8(MP) { return add(fetch(), false); }
  int ADDCI8(MP) { return add(fetch(), true); }
  int DECA(MP) { cA.W(cA.R()-1); return resGO; }
  
  int JMP0(MP) { return jmp(code); }
  int JMP1(MP) { return jmp(code); }
  int JMP2(MP) { return jmp(code); }
  int JMP3(MP) { return jmp(code); }
  int JMP4(MP) { return jmp(code); }
  int JMP5(MP) { return jmp(code); }
  int JMP6(MP) { return jmp(code); }
  int JMP7(MP) { return jmp(code); }

  int IN1(MP) { return in(code&3); }
  int IN2(MP) { return in(code&3); }
  int MOVDAP4(MP) { return in((code&3)+4); }
  int MOVDAP5(MP) { return in((code&3)+4); }
  int MOVDAP6(MP) { return in((code&3)+4); }
  int MOVDAP7(MP) { return in((code&3)+4); }

  int INCIR0(MP) { RDWR; return inc(iram_ir(0)); }
  int INCIR1(MP) { RDWR; return inc(iram_ir(1)); }
};


#endif

/* End of i8048.src/i8020cl.h */
