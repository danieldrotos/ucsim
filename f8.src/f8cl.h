/*
 * Simulator of microcontrollers (f8cl.h)
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

#ifndef F8CL_HEADER
#define F8CL_HEADER

#include "uccl.h"

#include "glob.h"
#include "decode.h"

#ifdef WORDS_BIGENDIAN
#define REGPAIR(N,N16,NH,NL) union			\
		      {				\
			u16_t N16;		\
			struct {		\
			  u8_t NH;		\
			  u8_t NL;		\
			} r;			\
  } N
#else
#define REGPAIR(N,N16,NH,NL) union			\
		      {				\
			u16_t N16;		\
			struct {		\
			  u8_t NL;		\
			  u8_t NH;		\
			} r;			\
  } N
#endif

#define rX (rpX.X)
#define rXL (rpX.r.XL)
#define rXH (rpX.r.XH)
#define rY (rpY.Y)
#define rYL (rpY.r.YL)
#define rYH (rpY.r.YH)
#define rZ (rpZ.Z)
#define rZL (rpZ.r.ZL)
#define rZH (rpZ.r.ZH)


enum {
  flagO	= 0x01,
  flagZ	= 0x02,
  flagN	= 0x04,
  flagC	= 0x08,
  flagH	= 0x10,

  flagS = flagN,
  flagV = flagO,
  
  fAll  = flagO|flagZ|flagN|flagC|flagH,
  fAll_H= flagO|flagZ|flagN|flagC
};


enum {
  P_NONE	= 0,
  P_SWAP	= 0x01, // (0) swapop
  P_ALT0	= 0x02, // (1) altacc    XH
  P_ALT1	= 0x04, // (2) altacc'   YL  X
  P_ALT2	= 0x08, // (2) altacc''  ZL  Z

  // shorts for allowed prefixes
  PN		= P_NONE,                      // none
  PA		= P_SWAP|P_ALT0|P_ALT1|P_ALT2, // 012
  P8		= P_ALT0,                      // 1
  P6		= P_ALT1|P_ALT2,               // 2
  PD		= P8|P6,                       // 12
  P1		= P_SWAP|P8,                   // 01
  P2		= P_SWAP|P6,                   // 02
};

/*
 * Base of f8 processor
 */
class cl_f8: public cl_uc
{
public:
  REGPAIR(rpX, X, XH, XL); class cl_cell8 cXH, cXL; class cl_cell16 cX;
  REGPAIR(rpY, Y, YH, YL); class cl_cell8 cYH, cYL; class cl_cell16 cY;
  REGPAIR(rpZ, Z, ZH, ZL); class cl_cell8 cZH, cZL; class cl_cell16 cZ;
  u16_t rSP; class cl_cell16 cSP;
  u8_t rF; class cl_cell8 cF;
  t_addr sp_limit;
  class cl_cell8 *acc8;
  class cl_cell16 *acc16;
  int prefixes;
public:
  cl_f8(class cl_sim *asim);
  virtual int init(void);
  virtual const char *id_string(void);
  virtual void reset(void);
  virtual void set_PC(t_addr addr);

  virtual void mk_hw_elements(void);
  virtual void make_cpu_hw(void);
  virtual void make_memories(void);
  
  virtual int clock_per_cycle(void) { return 1; }
  virtual struct dis_entry *dis_tbl(void);
  virtual struct dis_entry *get_dis_entry(t_addr addr);
  virtual char *disassc(t_addr addr, chars *comment=NULL);
  virtual int longest_inst(void) { return 5; }

  virtual void print_regs(class cl_console_base *con);

  virtual void clear_prefixes();
  virtual int exec_inst(void);

  // data moves: imove.cc
  
  // aritmetic (ALU) instuctions: ialu.cc

  // branches: ibranch.cc
  
  // other instructions: inst.cc
  virtual int NOP(t_mem code);
  virtual int TRAP(t_mem code);
};


enum f8cpu_confs
  {
   f8cpu_sp_limit	= 0,
   f8cpu_nuof		= 1
  };

class cl_f8_cpu: public cl_hw
{
public:
  cl_f8_cpu(class cl_uc *auc);
  virtual int init(void);
  virtual unsigned int cfg_size(void) { return f8cpu_nuof; }
  virtual const char *cfg_help(t_addr addr);

  virtual t_mem conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val);
};


#endif

/* End of f8.src/f8cl.h */
