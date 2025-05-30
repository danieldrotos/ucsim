/*
 * Simulator of microcontrollers (i8048cl.h)
 *
 * Copyright (C) 2022 Drotos Daniel
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


#ifndef I8048CL_HEADER
#define I8048CL_HEADER

#include "i8020cl.h"


class cl_flag48_op: public cl_memory_operator
{
public:
  cl_flag48_op(class cl_memory_cell *acell): cl_memory_operator(acell) {}
  virtual t_mem write(t_mem val);
};


/*
 * i8048 processor
 */

class cl_i8048: public cl_i8020
{
public:
  u8_t flagF1;
  class cl_bit_cell8 cflagF1;
 public:
  cl_i8048(class cl_sim *asim);
  cl_i8048(class cl_sim *asim,
	   unsigned int rom_siz,
	   unsigned int ram_siz);
  virtual int init(void);
  virtual void reset(void);
  virtual void make_irq_sources(void);
  virtual void mk_hw_elements(void);
  virtual void mk_dport(void);
  virtual class cl_memory_operator *make_flagop(void);
  virtual void make_cpu_hw(void);
  virtual void decode_regs(void);
  virtual u8_t movxrd(u8_t addr);
  virtual void movxwr(u8_t addr, u8_t val);
  virtual int orlbus(u8_t i8);
  virtual int anlbus(u8_t i8);
  virtual int call(MP);
  virtual int accept_it(class it_level *il);
  virtual void print_regs(class cl_console_base *con);
  // 48 specific insts to implement:
  int ENTCNTI(MP);
  int DISTCNTI(MP);
  int OUTLB(MP);
  int INS(MP);
  int JNT0(MP) { return jif(cpu->cfg_read(i8020cpu_t0)==0); }
  int JT0 (MP) { return jif(cpu->cfg_read(i8020cpu_t0)!=0); }
  int JF0 (MP) { return jif(psw & flagF0); }
  int JF1 (MP) { return jif(cflagF1.R() != 0); }
  int JNI(MP);
  int MOVXAIR0(MP) { RD; cA.W(movxrd(R[0]->R())); return resGO; }
  int MOVXAIR1(MP) { RD; cA.W(movxrd(R[1]->R())); return resGO; }
  int MOVXIR0A(MP) { WR; movxwr(R[0]->R(), rA); return resGO; }
  int MOVXIR1A(MP) { WR; movxwr(R[1]->R(), rA); return resGO; }
  int MOVP3AIA(MP) { RD; return movp3(); }
  int CPLF0(MP) { cF.W(rF ^ flagF0); return resGO; }
  int CPLF1(MP) { cflagF1.W(flagF1^1); return resGO; }
  int CLRF1(MP) { cflagF1.W(0); return resGO; }
  int SELRB0(MP) { cF.W(rF & ~flagBS); return resGO; }
  int SELRB1(MP) { cF.W(rF | flagBS); return resGO; }
  int MOVAF(MP) { cA.W(psw); return resGO; }
  int MOVFA(MP) { cF.W(rA); return resGO; }
  int SELMB0(MP) { mb= 0; return resGO; }
  int SELMB1(MP) { mb= 1; return resGO; }
  int ENT0CLK(MP) { return resGO; }
  int ORLBUSI8(MP) { return orlbus(fetch()); }
  int ANLBUSI8(MP) { return anlbus(fetch()); }
  int ORLP1I8(MP);
  int ORLP2I8(MP);
  int ANLP1I8(MP);
  int ANLP2I8(MP);
  int RETR(MP);
};


enum i8048cpu_confs
  {
    i8048cpu_int	= i8020cpu_nuof+0,
    i8048cpu_nuof	= i8020cpu_nuof+1
  };


class cl_i8048_cpu: public cl_i8020_cpu
{
public:
  cl_i8048_cpu(class cl_uc *auc);
  virtual int init(void);
  virtual unsigned int cfg_size(void) { return i8048cpu_nuof; }
  virtual const char *cfg_help(t_addr addr);
  virtual t_mem conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val);
};


#endif

/* End of i8048.src/i8048cl.h */
