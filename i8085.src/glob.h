/*
 * Simulator of microcontrollers (glob.h)
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

#ifndef I8085_GLOB_HEADER
#define I8085_GLOB_HEADER

#include "stypes.h"
#include "iwrap.h"


extern instruction_wrapper_fn itab[256];

extern struct cpu_entry cpus_8085[];
extern struct dis_entry disass_i8080[];
extern u8_t ptab[256];


#endif

/* End of i8085.src/glob.h */