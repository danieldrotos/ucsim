/*
 * Simulator of microcontrollers (t870ccl.h)
 *
 * Copyright (C) 2016 Drotos Daniel
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

#ifndef T870CCL_HEADER
#define T870CCL_HEADER

#include "uccl.h"


#ifdef WORDS_BIGENDIAN
# define PAIR(h,l) u8_t h, l
#else
# define PAIR(h,l) u8_t l, h
#endif

struct rbank_870c_t
{
  union { u16_t wa; struct { PAIR(w,a); } rwa; };
  union { u16_t bc; struct { PAIR(b,c); } rbc; };
  union { u16_t de; struct { PAIR(d,e); } rde; };
  union { u16_t hl; struct { PAIR(h,l); } rhl; };
  u16_t ix, iy;
};


#define rW (rbank->rwa.w)
#define rA (rbank->rwa.a)
#define rB (rbank->rbc.b)
#define rC (rbank->rbc.c)
#define rD (rbank->rde.d)
#define rE (rbank->rde.e)
#define rH (rbank->rhl.h)
#define rL (rbank->rhl.l)
#define rF (rPSW)

#define rWA (rbank->wa)
#define rBC (rbank->bc)
#define rDE (rbank->de)
#define rHL (rbank->hl)
#define rIX (rbank->ix)
#define rIY (rbank->iy)

#define cF (cPSW)


enum flag_mask_t {
  MJF= (0x80),
  MZF= (0x40),
  MCF= (0x20),
  MHF= (0x10),
  MSF= (0x08),
  MVF= (0x04),
  MRBS= (0x02)
};


class cl_t870c: public cl_uc
{
protected:
  struct rbank_870c_t *rbanks, *rbank;
public:
  u16_t rSP;
  u8_t rPSW;
  class cl_cell8 cW, cA;
  class cl_cell8 cB, cC;
  class cl_cell8 cD, cE;
  class cl_cell8 cH, cL;
  class cl_cell8 *regs8[8];
  class cl_cell16 cWA;
  class cl_cell16 cBC;
  class cl_cell16 cDE;
  class cl_cell16 cHL;
  class cl_cell16 cIX;
  class cl_cell16 cIY;
  class cl_cell16 cSP;
  class cl_cell16 *regs16[8];
  class cl_cell8 cPSW;
  class cl_address_space *nas;
public:
  cl_t870c(class cl_sim *asim);
  virtual int init(void);
  virtual void mk_rbanks();
  virtual void decode_regs(void);
  virtual void make_memories(void);
  virtual int  nas_size(void) { return 0x10000; }
  
  virtual void print_regs(class cl_console_base *con);
};


#endif

/* End of tlcs.src/tl870ccl.h */
