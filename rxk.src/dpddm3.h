/*
 * Simulator of microcontrollers (dpddm3.h)
 *
 * Copyright (C) 2020,2021 Drotos Daniel, Talker Bt.
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

#ifndef DPDDM3_HEADER
#define DPDDM3_HEADER

#define LD_IR_mn	instruction_dd_21

#define ADD_IR_BC	instruction_dd_09
#define ADD_IR_DE	instruction_dd_19
#define ADD_IR_IR	instruction_dd_29
#define ADD_IR_SP	instruction_dd_39

#define OR_A_iIRd	instruction_dd_b6

#define POP_IR		instruction_dd_e1
#define PUSH_IR		instruction_dd_e5

#define LD_iIRd_A	instruction_dd_77
#define LD_iIRd_B	instruction_dd_70
#define LD_iIRd_C	instruction_dd_71
#define LD_iIRd_D	instruction_dd_72
#define LD_iIRd_E	instruction_dd_73
#define LD_iIRd_H	instruction_dd_74
#define LD_iIRd_L	instruction_dd_75
#define LD_A_iIRd	instruction_dd_7e
#define LD_B_iIRd	instruction_dd_46
#define LD_C_iIRd	instruction_dd_4e
#define LD_D_iIRd	instruction_dd_56
#define LD_E_iIRd	instruction_dd_5e
#define LD_H_iIRd	instruction_dd_66
#define LD_L_iIRd	instruction_dd_6e

#define LD_SP_IR	instruction_dd_f9
#define LD_IR_iSPn 	instruction_dd_c4
#define LD_iSPn_IR 	instruction_dd_d4

#endif

/* End of rxk.src/dpddm3.h */
