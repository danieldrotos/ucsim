/*
 * Simulator of microcontrollers (dp0m6.h)
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

#ifndef DP0M6_HEADER
#define DP0M6_HEADER


/*
+ add iy, #d	fd/dd c5
+ and hl, d(ix)	fd/dd a0
+ cp hl, d(ix)	fd/dd b1
+ or hl, d(ix)	fd/dd b0
+ sbc hl, d(ix)	fd/dd 91
+ xor hl, d(ix)	fd/dd a1

and hl, n(sp)	49 ca
cp hl, n(sp)	49 fa
or hl, n(sp)	49 ea
sbc hl, n(sp)	49 ba
xor hl, n(sp)	49 da

+ jp ge, mn	00-m11 43
+ jp le, mn	00-m11 53
+ jp leu, mn	00-m11 4b
+ jr ge, e	00-m11 80
+ jr le, e	00-m11 90
+ jr leu, e	00-m11 88

+ swap bc	ed 87
+ swap de	ed a7
+ swap hl	ed c7
*/

#define JP_GE_MN		instruction_6k11_43
#define EX_JKHL_BCDE_		instruction_6k11_44
#define JP_LEU_MN		instruction_6k11_4b
#define JP_LE_MN		instruction_6k11_53
#define MUL_HL_DE		instruction_6k11_59
#define MULU_HL_DE		instruction_6k11_69
#define JR_GE_E			instruction_6k11_80
#define JR_LEU_E		instruction_6k11_88
#define JR_LE_E			instruction_6k11_90

#define TEST_DE			instruction_6ked_5c
#define TSTNULL_PW		instruction_6ked_86
#define SWAP_B			instruction_6ked_87
#define TSTNULL_PX		instruction_6ked_96
#define SWAP_C			instruction_6ked_97
#define LLJP_LEU_LXPC_MN	instruction_6ked_9a
#define JRE_LEU_EE		instruction_6ked_9b
#define FLAG_LEU_HL		instruction_6ked_9c
#define TSTNULL_PY		instruction_6ked_a6
#define SWAP_D			instruction_6ked_a7
#define TSTNULL_PZ		instruction_6ked_b6
#define SWAP_E			instruction_6ked_b7
#define SWAP_H			instruction_6ked_c7
#define SWAP_BC			instruction_6ked_cf
#define SWAP_L			instruction_6ked_d7
#define SWAP_DE			instruction_6ked_df
#define LLJP_GE_LXPC_MN		instruction_6ked_e2
#define JRE_GE_EE		instruction_6ked_e3
#define FLAG_GE_HL		instruction_6ked_e4
#define SWAP_HL			instruction_6ked_ef
#define LLJP_LE_LXPC_MN		instruction_6ked_f2
#define JRE_LE_EE		instruction_6ked_f3
#define FLAG_LE_HL		instruction_6ked_f4
#define SWAP_A			instruction_6ked_f7
#define SWAP_JK			instruction_6ked_ff

#define SWAP_IRR		instruction_6kdd_32
#define ADD_HL_iIRd		instruction_6kdd_80
#define ADC_HL_iIRd		instruction_6kdd_81
#define SUB_HL_iIRd		instruction_6kdd_90
#define SBC_HL_iIRd		instruction_6kdd_91
#define AND_HL_iIRd		instruction_6kdd_a0
#define XOR_HL_iIRd		instruction_6kdd_a1
#define AND_JKHL_iIRd		instruction_6kdd_a2
#define XOR_JKHL_iIRd		instruction_6kdd_a3
#define OR_HL_iIRd		instruction_6kdd_b0
#define CP_HL_iIRd		instruction_6kdd_b1
#define OR_JKHL_iIRd		instruction_6kdd_b2
#define ADD_IR_D		instruction_6kdd_c5


#endif

/* End of rxk.src/dp0m6.h */
