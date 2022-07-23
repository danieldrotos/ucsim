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
public:
  cl_f8(class cl_sim *asim);
  virtual int init(void);
  virtual const char *id_string(void);
  virtual void reset(void);
  virtual void set_PC(t_addr addr);

  virtual void mk_hw_elements(void);
  virtual void make_cpu_hw(void);
  virtual void make_memories(void);
};


#endif

/* End of f8.src/f8cl.h */
