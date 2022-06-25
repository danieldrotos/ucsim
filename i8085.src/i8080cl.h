/*
 * Simulator of microcontrollers (i8080cl.h)
 *
 * Copyright (C) @@S@@,@@Y@@ Drotos Daniel, Talker Bt.
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

#ifndef I8080CL_HEADER
#define I8080CL_HEADER

#include "uccl.h"

#include "glob.h"
#include "decode.h"


#ifdef WORDS_BIGENDIAN
#define RP(N,N16,NH,NL) union			\
		      {				\
			u16_t N16;		\
			struct {		\
			  u8_t NH;		\
			  u8_t NL;		\
			} r;			\
  } N
#else
#define RP(N,N16,NH,NL) union			\
		      {				\
			u16_t N16;		\
			struct {		\
			  u8_t NL;		\
			  u8_t NH;		\
			} r;			\
  } N
#endif

#define rAF (rpAF.AF)
#define rA  (rpAF.r.A)
#define rF  (rpAF.r.F)

#define rBC (rpBC.BC)
#define rB  (rpBC.r.B)
#define rC  (rpBC.r.C)

#define rDE (rpDE.DE)
#define rD  (rpDE.r.D)
#define rE  (rpDE.r.E)

#define rHL (rpHL.HL)
#define rH  (rpHL.r.H)
#define rL  (rpHL.r.L)

#define rM  (rom->read(rHL))


enum {
  flagC	= 0x01,
  flagP	= 0x04,
  flagA	= 0x10,
  flagZ	= 0x40,
  flagS	= 0x80
};


/*
 * Special handling of flags
 */

class cl_flags: public cl_cell8
{
public:
  virtual t_mem write(t_mem val);
};


/*
 * Base of i8080 processor
 */

class cl_i8080: public cl_uc
{
public:
  class cl_flags cF;
  RP(rpAF, AF, A, F);  class cl_cell8 cA    ;  class cl_cell16 cAF;
  RP(rpBC, BC, B, C);  class cl_cell8 cB, cC;  class cl_cell16 cBC;
  RP(rpDE, DE, D, E);  class cl_cell8 cD, cE;  class cl_cell16 cDE;
  RP(rpHL, HL, H, L);  class cl_cell8 cH, cL;  class cl_cell16 cHL;
  u16_t rSP; class cl_cell16 cSP;
public:
  cl_i8080(class cl_sim *asim);
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
  virtual void dis_M(chars *comment);
  virtual char *disassc(t_addr addr, chars *comment=NULL);

  virtual void print_regs(class cl_console_base *con);

  virtual int exec_inst(void);

  virtual int NOP(t_mem code) { return resGO; }
  virtual int HLT(t_mem code);
#include "imovrr.h"
};


#endif

/* End of i8085.src/i8080cl.h */
