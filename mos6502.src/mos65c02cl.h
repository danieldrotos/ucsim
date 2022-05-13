/*
 * Simulator of microcontrollers (mos65c02cl.h)
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

#ifndef MOS65C02CL_HEADER
#define MOS65C02CL_HEADER

#include "mos6502cl.h"

#include "decc02.h"

class cl_mos65c02: public cl_mos6502
{
 public:
  cl_mos65c02(class cl_sim *asim);
  virtual int init(void);
  virtual const char *id_string(void);
  virtual void reset(void);

  virtual struct dis_entry *get_dis_entry(t_addr addr);
  virtual int inst_length(t_addr addr);

  virtual int nopft(int nuof_fetches, int nuof_ticks);
  
  // New insts in column 2
  virtual int ORAzi(t_mem code) { return ora(zind()); }
  virtual int ANDzi(t_mem code) { return And(zind()); }
  virtual int EORzi(t_mem code) { return eor(zind()); }
  virtual int ADCzi(t_mem code) { return adc(zind()); }
  virtual int STAzi(t_mem code) { return sta(dstzind()); }
  virtual int LDAzi(t_mem code) { return lda(zind()); }
  virtual int CMPzi(t_mem code) { return cmp(cA, zind()); }
  virtual int SBCzi(t_mem code) { return sbc(zind()); }
  // NOPs of column 2
  virtual int instruction_02(t_mem code) { return nopft(1,1); }
  virtual int instruction_22(t_mem code) { return nopft(1,1); }
  virtual int instruction_42(t_mem code) { return nopft(1,1); }
  virtual int instruction_62(t_mem code) { return nopft(1,1); }
  virtual int instruction_82(t_mem code) { return nopft(1,1); }
  virtual int instruction_c2(t_mem code) { return nopft(1,1); }
  virtual int instruction_e2(t_mem code) { return nopft(1,1); }
  // New insts in column 4
  virtual int BITzx(t_mem code) { return bit(zpgX()); }
  // New insts in column 8
  virtual int BIT8(t_mem code) { return bit(imm8()); }
  // New insts in column A
  virtual int INA(t_mem code);
  virtual int DEA(t_mem code);
  // New insts in column C
  virtual int BITax(t_mem code) { return bit(absX()); }
  virtual int JMP7c(t_mem code);
  virtual int NOP5c(t_mem code) { return nopft(2,7); }
  virtual int NOPdc(t_mem code) { return nopft(2,3); }
  virtual int NOPfc(t_mem code) { return nopft(2,3); }
};


#endif

/* End of mos6502.src/mos65c02.cc */
