/*
 * Simulator of microcontrollers (uc52cl.h)
 *
 * Copyright (C) 1999 Drotos Daniel
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

#ifndef UC52CL_HEADER
#define UC52CL_HEADER

#include "ddconfig.h"

#include "uc51cl.h"
#include "itsrccl.h"


class cl_uc52: public cl_51core
{
public:
  cl_uc52(struct cpu_entry *Itype, class cl_sim *asim);
  virtual int init(void);
  virtual void mk_hw_elements(void);
  virtual void make_memories(void);
  virtual void make_address_spaces(void);
  virtual void decode_iram(void);
  virtual void decode_dptr(void);
  
  virtual void clear_sfr(void);
};


#endif

/* End of s51.src/uc52cl.h */
