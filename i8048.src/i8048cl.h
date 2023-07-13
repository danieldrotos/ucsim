/*
 * Simulator of microcontrollers (i8048cl.h)
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
  cl_i8048(class cl_sim *asim);
  cl_i8048(class cl_sim *asim,
	   unsigned int rom_siz,
	   unsigned int ram_siz);
  virtual int init(void);
  virtual class cl_memory_operator *make_flagop(void);
  virtual void decode_regs(void);
  // 48 specific insts to implement:
  //OUTLB
  //INS
  int JNT0(MP) { return jif(cpu->cfg_read(i8020cpu_t0)==0); }
  int JT0 (MP) { return jif(cpu->cfg_read(i8020cpu_t0)!=0); }
  int JF1 (MP) { return jif(cflagF1.R() != 0); }
  int MOVXAIR0(MP) { RD; xram->read(R[0]->R()); return resGO; }
  int MOVXAIR1(MP) { RD; xram->read(R[1]->R()); return resGO; }
  int MOVXIR0A(MP) { WR; xram->write(R[0]->R(), rA); return resGO; }
  int MOVXIR1A(MP) { WR; xram->write(R[1]->R(), rA); return resGO; }
};


#endif

/* End of i8048.src/i8048cl.h */
