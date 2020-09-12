/*
 * Simulator of microcontrollers (m6809cl.h)
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

#ifndef M6809CL_HEADER
#define M6809CL_HEADER

#include "uccl.h"
#include "memcl.h"


/*
 * Base of M6809 processor
 */

struct reg_t {
  u16_t U;
  u16_t S;
  u16_t X;
  u16_t Y;
  union {
    u16_t rD;
    struct {
#ifdef WORDS_BIGENDIAN
      u8_t rA;
      u8_t rB;
#else
      u8_t rB;
      u8_t rA;
#endif      
    } a8;
  } acc;
  u8_t DP;
  u8_t CC;
};

#define A (reg.acc.a8.rA)
#define B (reg.acc.a8.rB)
#define D (reg.acc.rD)

enum flags
  {
   C= 1,
   V= 2,
   O= 2,
   Z= 4,
   N= 8,
   S= 8,
   I= 16,
   H= 32,
   F= 64,
   E= 128
  };

class cl_m6809: public cl_uc
{
public:
  struct reg_t reg;
  //cl_address_space *regs;
  class cl_porto *pa, *pb, *pc, *pd;
  class cl_porti *pi, *pj;
public:
  class cl_address_space *rom;
public:
  cl_m6809(class cl_sim *asim);
  virtual int init(void);
  virtual const char *id_string(void);
  virtual void reset(void);
  virtual void set_PC(t_addr addr);

  virtual void mk_hw_elements(void);
  virtual void make_memories(void);
  virtual int clock_per_cycle(void) { return 1; }
  
  virtual struct dis_entry *dis_tbl(void);
  virtual char *disass(t_addr addr, const char *sep);
  virtual void print_regs(class cl_console_base *con);

  virtual int inst_add8(t_mem code, u8_t *dest, u8_t op, int c, bool store);
  virtual int inst_bool(t_mem code, char bop, u8_t *dest, u8_t op, bool store);
  
  virtual int inst_alu(t_mem code);
  virtual int inst_low(t_mem code);
  virtual int exec_inst(void);
};

#define SET_C(v) ( (reg.CC)= ((reg.CC)&~C) | ((v)?C:0) )
#define SET_Z(v) ( (reg.CC)= ((reg.CC)&~Z) | ((v==0)?Z:0) )
#define SET_S(v) ( (reg.CC)= ((reg.CC)&~S) | ((v)?S:0) )
#define SET_O(v) ( (reg.CC)= ((reg.CC)&~V) | ((v)?V:0) )
#define SET_H(v) ( (reg.CC)= ((reg.CC)&~H) | ((v)?H:0) )

#endif

/* End of m6809.src/m6809.cc */