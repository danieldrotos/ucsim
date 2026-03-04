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

+ and hl, n(sp)	49 ca
+ cp hl, n(sp)	49 fa
+ or hl, n(sp)	49 ea
+ sbc hl, n(sp)	49 ba
+ xor hl, n(sp)	49 da

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
#define ADC_JKHL_BCDE		instruction_6ked_ce
#define SWAP_BC			instruction_6ked_cf
#define SWAP_L			instruction_6ked_d7
#define SWAP_DE			instruction_6ked_df
#define SBC_JKHL_BCDE		instruction_6ked_de
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
#define ADD_JKHL_iIRd		instruction_6kdd_82
#define ADC_JKHL_iIRd		instruction_6kdd_83
#define SUB_HL_iIRd		instruction_6kdd_90
#define SBC_HL_iIRd		instruction_6kdd_91
#define SUB_JKHL_iIRd		instruction_6kdd_92
#define SBC_JKHL_iIRd		instruction_6kdd_93
#define AND_HL_iIRd		instruction_6kdd_a0
#define XOR_HL_iIRd		instruction_6kdd_a1
#define AND_JKHL_iIRd		instruction_6kdd_a2
#define XOR_JKHL_iIRd		instruction_6kdd_a3
#define OR_HL_iIRd		instruction_6kdd_b0
#define CP_HL_iIRd		instruction_6kdd_b1
#define OR_JKHL_iIRd		instruction_6kdd_b2
#define CP_JKHL_iIRd		instruction_6kdd_b3
#define ADD_IR_D		instruction_6kdd_c5

// page 49
// 00-0f
#define ADD_JKHL_PW		instruction_6k49_00
#define ADD_JKHL_PX		instruction_6k49_01
#define ADD_JKHL_PY		instruction_6k49_02
#define ADD_JKHL_PZ		instruction_6k49_03
#define ADD_A_iPWd		instruction_6k49_04
#define ADD_A_iPXd		instruction_6k49_05
#define ADD_A_iPYd		instruction_6k49_06
#define ADD_A_iPZd		instruction_6k49_07
#define ADD_HL_iPWd		instruction_6k49_08
#define ADD_HL_iPXd		instruction_6k49_09
#define ADD_HL_iPYd		instruction_6k49_0a
#define ADD_HL_iPZd		instruction_6k49_0b
#define ADD_JKHL_iPWd		instruction_6k49_0c
#define ADD_JKHL_iPXd		instruction_6k49_0d
#define ADD_JKHL_iPYd		instruction_6k49_0e
#define ADD_JKHL_iPZd		instruction_6k49_0f
// 10-1f
#define ADC_JKHL_PW		instruction_6k49_10
#define ADC_JKHL_PX		instruction_6k49_11
#define ADC_JKHL_PY		instruction_6k49_12
#define ADC_JKHL_PZ		instruction_6k49_13
#define ADC_A_iPWd		instruction_6k49_14
#define ADC_A_iPXd		instruction_6k49_15
#define ADC_A_iPYd		instruction_6k49_16
#define ADC_A_iPZd		instruction_6k49_17
#define ADC_HL_iPWd		instruction_6k49_18
#define ADC_HL_iPXd		instruction_6k49_19
#define ADC_HL_iPYd		instruction_6k49_1a
#define ADC_HL_iPZd		instruction_6k49_1b
#define ADC_JKHL_iPWd		instruction_6k49_1c
#define ADC_JKHL_iPXd		instruction_6k49_1d
#define ADC_JKHL_iPYd		instruction_6k49_1e
#define ADC_JKHL_iPZd		instruction_6k49_1f
// 20-2f
#define SUB_JKHL_PW		instruction_6k49_20
#define SUB_JKHL_PX		instruction_6k49_21
#define SUB_JKHL_PY		instruction_6k49_22
#define SUB_JKHL_PZ		instruction_6k49_23
#define SUB_A_iPWd		instruction_6k49_24
#define SUB_A_iPXd		instruction_6k49_25
#define SUB_A_iPYd		instruction_6k49_26
#define SUB_A_iPZd		instruction_6k49_27
#define SUB_HL_iPWd		instruction_6k49_28
#define SUB_HL_iPXd		instruction_6k49_29
#define SUB_HL_iPYd		instruction_6k49_2a
#define SUB_HL_iPZd		instruction_6k49_2b
#define SUB_JKHL_iPWd		instruction_6k49_2c
#define SUB_JKHL_iPXd		instruction_6k49_2d
#define SUB_JKHL_iPYd		instruction_6k49_2e
#define SUB_JKHL_iPZd		instruction_6k49_2f
// 30-3f
#define SBC_JKHL_PW		instruction_6k49_30
#define SBC_JKHL_PX		instruction_6k49_31
#define SBC_JKHL_PY		instruction_6k49_32
#define SBC_JKHL_PZ		instruction_6k49_33
#define SBC_A_iPWd		instruction_6k49_34
#define SBC_A_iPXd		instruction_6k49_35
#define SBC_A_iPYd		instruction_6k49_36
#define SBC_A_iPZd		instruction_6k49_37
#define SBC_HL_iPWd		instruction_6k49_38
#define SBC_HL_iPXd		instruction_6k49_39
#define SBC_HL_iPYd		instruction_6k49_3a
#define SBC_HL_iPZd		instruction_6k49_3b
#define SBC_JKHL_iPWd		instruction_6k49_3c
#define SBC_JKHL_iPXd		instruction_6k49_3d
#define SBC_JKHL_iPYd		instruction_6k49_3e
#define SBC_JKHL_iPZd		instruction_6k49_3f
// 40-4f
#define AND_JKHL_PW		instruction_6k49_40
#define AND_JKHL_PX		instruction_6k49_41
#define AND_JKHL_PY		instruction_6k49_42
#define AND_JKHL_PZ		instruction_6k49_43
#define AND_A_iPWd		instruction_6k49_44
#define AND_A_iPXd		instruction_6k49_45
#define AND_A_iPYd		instruction_6k49_46
#define AND_A_iPZd		instruction_6k49_47
#define AND_HL_iPWd		instruction_6k49_48
#define AND_HL_iPXd		instruction_6k49_49
#define AND_HL_iPYd		instruction_6k49_4a
#define AND_HL_iPZd		instruction_6k49_4b
#define AND_JKHL_iPWd		instruction_6k49_4c
#define AND_JKHL_iPXd		instruction_6k49_4d
#define AND_JKHL_iPYd		instruction_6k49_4e
#define AND_JKHL_iPZd		instruction_6k49_4f
// 50-5f
#define XOR_JKHL_PW		instruction_6k49_50
#define XOR_JKHL_PX		instruction_6k49_51
#define XOR_JKHL_PY		instruction_6k49_52
#define XOR_JKHL_PZ		instruction_6k49_53
#define XOR_A_iPWd		instruction_6k49_54
#define XOR_A_iPXd		instruction_6k49_55
#define XOR_A_iPYd		instruction_6k49_56
#define XOR_A_iPZd		instruction_6k49_57
#define XOR_HL_iPWd		instruction_6k49_58
#define XOR_HL_iPXd		instruction_6k49_59
#define XOR_HL_iPYd		instruction_6k49_5a
#define XOR_HL_iPZd		instruction_6k49_5b
#define XOR_JKHL_iPWd		instruction_6k49_5c
#define XOR_JKHL_iPXd		instruction_6k49_5d
#define XOR_JKHL_iPYd		instruction_6k49_5e
#define XOR_JKHL_iPZd		instruction_6k49_5f
// 80-8f
#define ADD_A_iSPn		instruction_6k49_89
#define ADD_HL_iSPn		instruction_6k49_8a
#define ADD_JKHL_iSPn		instruction_6k49_8b
// 90-9f
#define ADC_A_iSPn		instruction_6k49_99
#define ADC_HL_iSPn		instruction_6k49_9a
#define ADC_JKHL_iSPn		instruction_6k49_9b
// a0-af
#define SUB_A_iSPn		instruction_6k49_a9
#define SUB_HL_iSPn		instruction_6k49_aa
#define SUB_JKHL_iSPn		instruction_6k49_ab
// b0-bf
#define SBC_A_iSPn		instruction_6k49_b9
#define SBC_HL_iSPn		instruction_6k49_ba
#define SBC_JKHL_iSPn		instruction_6k49_bb
// c0-cf
#define AND_A_iSPn		instruction_6k49_c9
#define AND_HL_iSPn		instruction_6k49_ca
#define AND_JKHL_iSPn		instruction_6k49_cb
// d0-df
#define XOR_A_iSPn		instruction_6k49_d9
#define XOR_HL_iSPn		instruction_6k49_da
#define XOR_JKHL_iSPn		instruction_6k49_db
// e0-ef
#define OR_A_iSPn		instruction_6k49_e9
#define OR_HL_iSPn		instruction_6k49_ea
#define OR_JKHL_iSPn		instruction_6k49_eb
// f0-ff
#define CP_A_iSPn		instruction_6k49_f9
#define CP_HL_iSPn		instruction_6k49_fa
#define CP_JKHL_iSPn		instruction_6k49_fb


#endif

/* End of rxk.src/dp0m6.h */
