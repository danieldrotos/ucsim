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
  u8_t flagF1, mb, rA, ien;
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

  virtual void push(void);
  virtual void stack_check_overflow(t_addr sp_after);
  
  virtual void reset(void);
  virtual int exec_inst(void);

  virtual class cl_memory_cell *iram_ir(int regnr);
  virtual u8_t read_ir(int regnr);
  
  virtual int add(u8_t op2, bool addc);
  virtual int dec(class cl_memory_cell *op);
  virtual int inc(class cl_memory_cell *op);
  virtual int orl(class cl_memory_cell *op);
  virtual int anl(class cl_memory_cell *op);
  virtual int daa(void);
    
  virtual int jmp(MP);
  virtual int call(MP);
  virtual int jb(MP);
  
  virtual int in(int port_addr);
  virtual int out(int port_addr);
  virtual int xch(class cl_memory_cell *op);
  virtual int xchd(class cl_memory_cell *op);
  
  /*
#define GEN_METHOD
#include "decode.h"
#undef GEN_METHOD
  */
  /* Other instructions */
  int NOP(MP) { return resGO; }
  int DISI(MP) { ien= 0; return resGO; }
  int ENI(MP) { ien= 1; return resGO; }

  /* Arithmetics */
  int ADDI8(MP) { return add(fetch(), false); }
  int ADCI8(MP) { return add(fetch(), true); }
  int ADDIR0(MP) { return add(read_ir(0), false); }
  int ADDIR1(MP) { return add(read_ir(1), false); }
  int ADDR0(MP) { return add(R[0]->read(), false); }
  int ADDR1(MP) { return add(R[1]->read(), false); }
  int ADDR2(MP) { return add(R[2]->read(), false); }
  int ADDR3(MP) { return add(R[3]->read(), false); }
  int ADDR4(MP) { return add(R[4]->read(), false); }
  int ADDR5(MP) { return add(R[5]->read(), false); }
  int ADDR6(MP) { return add(R[6]->read(), false); }
  int ADDR7(MP) { return add(R[7]->read(), false); }
  int DECA(MP) { cA.W(rA-1); return resGO; }
  int CPLA(MP) { cA.W(~(cA.R())); return resGO; }
  int INCIR0(MP) { RDWR; return inc(iram_ir(0)); }
  int INCIR1(MP) { RDWR; return inc(iram_ir(1)); }
  int INCA(MP) { cA.W(rA+1); return resGO; }
  int INCR0(MP) { return inc(R[0]); }
  int INCR1(MP) { return inc(R[1]); }
  int INCR2(MP) { return inc(R[2]); }
  int INCR3(MP) { return inc(R[3]); }
  int INCR4(MP) { return inc(R[4]); }
  int INCR5(MP) { return inc(R[5]); }
  int INCR6(MP) { return inc(R[6]); }
  int INCR7(MP) { return inc(R[7]); }
  int ORLIR0(MP) { RD; return orl(iram_ir(0)); }
  int ORLIR1(MP) { RD; return orl(iram_ir(1)); }
  int ORLI8(MP) { cA.W(rA | fetch()); return resGO; }
  int ORLR0(MP) { cA.W(rA | R[0]->read()); return resGO; }
  int ORLR1(MP) { cA.W(rA | R[1]->read()); return resGO; }
  int ORLR2(MP) { cA.W(rA | R[2]->read()); return resGO; }
  int ORLR3(MP) { cA.W(rA | R[3]->read()); return resGO; }
  int ORLR4(MP) { cA.W(rA | R[4]->read()); return resGO; }
  int ORLR5(MP) { cA.W(rA | R[5]->read()); return resGO; }
  int ORLR6(MP) { cA.W(rA | R[6]->read()); return resGO; }
  int ORLR7(MP) { cA.W(rA | R[7]->read()); return resGO; }
  int ANLIR0(MP) { RD; return anl(iram_ir(0)); }
  int ANLIR1(MP) { RD; return anl(iram_ir(1)); }
  int ANLI8(MP) { cA.W(rA & fetch()); return resGO; }
  int DAA(MP) { return daa(); }
  int ANLR0(MP) { cA.W(rA & R[0]->read()); return resGO; }
  int ANLR1(MP) { cA.W(rA & R[1]->read()); return resGO; }
  int ANLR2(MP) { cA.W(rA & R[2]->read()); return resGO; }
  int ANLR3(MP) { cA.W(rA & R[3]->read()); return resGO; }
  int ANLR4(MP) { cA.W(rA & R[4]->read()); return resGO; }
  int ANLR5(MP) { cA.W(rA & R[5]->read()); return resGO; }
  int ANLR6(MP) { cA.W(rA & R[6]->read()); return resGO; }
  int ANLR7(MP) { cA.W(rA & R[7]->read()); return resGO; }
  int RRCA(MP);
  
  /* Branching */
  int JMP0(MP) { return jmp(code); }
  int JMP1(MP) { return jmp(code); }
  int JMP2(MP) { return jmp(code); }
  int JMP3(MP) { return jmp(code); }
  int JMP4(MP) { return jmp(code); }
  int JMP5(MP) { return jmp(code); }
  int JMP6(MP) { return jmp(code); }
  int JMP7(MP) { return jmp(code); }
  int CALL0(MP) { return call(code); }
  int CALL1(MP) { return call(code); }
  int CALL2(MP) { return call(code); }
  int CALL3(MP) { return call(code); }
  int CALL4(MP) { return call(code); }
  int CALL5(MP) { return call(code); }
  int CALL6(MP) { return call(code); }
  int CALL7(MP) { return call(code); }
  int JB0(MP) { return jb(code); }
  int JB1(MP) { return jb(code); }
  int JB2(MP) { return jb(code); }
  int JB3(MP) { return jb(code); }
  int JB4(MP) { return jb(code); }
  int JB5(MP) { return jb(code); }
  int JB6(MP) { return jb(code); }
  int JB7(MP) { return jb(code); }
  
  /* Data movement */
  int IN1(MP) { RD; return in(1); }
  int IN2(MP) { RD; return in(2); }
  int MOVDAP4(MP) { RD; return in(4); }
  int MOVDAP5(MP) { RD; return in(5); }
  int MOVDAP6(MP) { RD; return in(6); }
  int MOVDAP7(MP) { RD; return in(7); }
  int MOVDP4A(MP) { WR; return out(4); }
  int MOVDP5A(MP) { WR; return out(5); }
  int MOVDP6A(MP) { WR; return out(6); }
  int MOVDP7A(MP) { WR; return out(7); }
  int XCHIR0(MP) { RDWR; return xch(iram_ir(0)); }
  int XCHIR1(MP) { RDWR; return xch(iram_ir(1)); }
  int MOVAI8(MP) { cA.W(fetch()); return resGO; }
  int CLRA(MP) { cA.W(0); return resGO; }
  int XCHR0(MP) { RDWR; return xch(R[0]); }
  int XCHR1(MP) { RDWR; return xch(R[1]); }
  int XCHR2(MP) { RDWR; return xch(R[2]); }
  int XCHR3(MP) { RDWR; return xch(R[3]); }
  int XCHR4(MP) { RDWR; return xch(R[4]); }
  int XCHR5(MP) { RDWR; return xch(R[5]); }
  int XCHR6(MP) { RDWR; return xch(R[6]); }
  int XCHR7(MP) { RDWR; return xch(R[7]); }
  int XCHDIR0(MP) { RDWR; return xchd(iram_ir(0)); }
  int XCHDIR1(MP) { RDWR; return xchd(iram_ir(1)); }
  int SWAPA(MP);
};


#endif

/* End of i8048.src/i8020cl.h */
