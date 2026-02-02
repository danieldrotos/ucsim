/*
 * Simulator of microcontrollers (huc6280cl.h)
 *
 * Copyright (C) 2020 Drotos Daniel
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

#ifndef HUC6280CL_HEADER
#define HUC6280CL_HEADER

#include "mos65c02scl.h"
#include "dechuc.h"


class cl_huc6280: public cl_mos65c02s
{
public:
  class cl_address_space *mpras;
  class cl_chip8 *mprch, *romchip;
  class cl_address_decoder *mprad;
 public:
  cl_huc6280(class cl_sim *asim);
  virtual void reset(void);
  virtual int init(void);
  virtual void make_memories(void);
  virtual struct dis_entry *get_dis_entry(t_addr addr);
  virtual int longest_inst(void) { return 7; }
  virtual void print_regs(class cl_console_base *con);

  virtual int SXY(MP);
  virtual int SAX(MP);
  virtual int SAY(MP);
  virtual int CLA(MP) { cA.W(0); tick(1); return resGO; }
  virtual int CLX(MP) { cX.W(0); tick(1); return resGO; }
  virtual int CLY(MP) { cY.W(0); tick(1); return resGO; }

  virtual int STO(MP);
  virtual int ST1(MP);
  virtual int ST2(MP);
  virtual int TMA(MP);
  virtual int TAM(MP);
  virtual int TII(MP);
  virtual int TDD(MP);
  virtual int TIN(MP);
};


#endif


/* End of mos6502.src/huc6280cl.h */
