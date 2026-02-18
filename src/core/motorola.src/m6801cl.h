/*
 * Simulator of microcontrollers (m6801cl.h)
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

#ifndef M6801CL_HEADER
#define M6801CL_HEADER

#include "m6800cl.h"


extern i8_t m6801ticks[256];

class cl_m6801: public cl_m6800
{
public:
  class cl_cell16 cD;
public:
  cl_m6801(class cl_sim *asim);
  virtual const char *id_string(void);
  virtual int init(void);

  virtual i8_t *tick_tab(t_mem code) { return m6801ticks; }
  virtual struct dis_entry *get_dis_entry(t_addr addr);
  virtual void print_regs(class cl_console_base *con);

  virtual int add16(class cl_memory_cell &dest, u16_t op);
  virtual int sub16(class cl_memory_cell &dest, u16_t op);
  virtual int cpx(u16_t op);
  virtual int ldd(u16_t op);
  virtual int std(t_addr addr);
  
  virtual int BRN(t_mem code) { fetch(); return resGO; }
  virtual int JSRd(t_mem code) { return call(daddr()); }
  virtual int PSHX(t_mem code);
  virtual int PULX(t_mem code);
  virtual int LSRD(t_mem code);
  virtual int ASLD(t_mem code);
  virtual int ABX(t_mem code);
  virtual int MUL(t_mem code);
  virtual int ADDD16(t_mem code) { return add16(cD, i16()); }
  virtual int ADDDd (t_mem code) { return add16(cD, dop16()); }
  virtual int ADDDe (t_mem code) { return add16(cD, eop16()); }
  virtual int ADDDi (t_mem code) { return add16(cD, iop16()); }
  virtual int SUBD16(t_mem code) { return sub16(cD, i16()); }
  virtual int SUBDd (t_mem code) { return sub16(cD, dop16()); }
  virtual int SUBDe (t_mem code) { return sub16(cD, eop16()); }
  virtual int SUBDi (t_mem code) { return sub16(cD, iop16()); }
  virtual int LDD16 (t_mem code) { return ldd(i16()); }
  virtual int LDDd  (t_mem code) { return ldd(dop16()); }
  virtual int LDDe  (t_mem code) { return ldd(eop16()); }
  virtual int LDDi  (t_mem code) { return ldd(iop16()); }
  virtual int STDd  (t_mem code) { return std(daddr()); }
  virtual int STDe  (t_mem code) { return std(eaddr()); }
  virtual int STDi  (t_mem code) { return std(iaddr()); }
};


#endif

/* End of motorola.src/m6801cl.h */
