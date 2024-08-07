/*
 * Simulator of microcontrollers (inst_ddcb.cc)
 *   DD CB escaped multi-byte opcodes for Z80.
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

//#include "ddconfig.h"

// local
#include "z80cl.h"
//#include "regsz80.h"
#include "z80mac.h"


#define regs_IX_OR_IY regs.IX
#define inst_XXcb_rlc inst_ddcb_rlc
#define inst_XXcb_rrc inst_ddcb_rrc
#define inst_XXcb_rl inst_ddcb_rl
#define inst_XXcb_rr inst_ddcb_rr
#define inst_XXcb_sla inst_ddcb_sla
#define inst_XXcb_sra inst_ddcb_sra
#define inst_XXcb_slia inst_ddcb_slia
#define inst_XXcb_srl inst_ddcb_srl
#define inst_XXcb_bit inst_ddcb_bit
#define inst_XXcb_res inst_ddcb_res
#define inst_XXcb_set inst_ddcb_set
#define inst_XXcb inst_ddcb

#include "inst_xxcb.cc"

/* End of z80.src/inst_ddcb.cc */
