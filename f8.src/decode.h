/*
 * Simulator of microcontrollers (decode.h)
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

#ifndef F8_DECODE_HEADER
#define F8_DECODE_HEADER

#define PREF		0x9c
#define PREF_MASK	0xfc
#define PREF_SHIFT	0

// Opcodes of prefixes
#define PREF_SWAPOP	0x9c
#define PREF_ALT0	0x9d
#define PREF_ALT1	0x9e
#define PREF_ALT2	0x9f


// data moves
#define LD8_A_I		instruction_80
#define LD8_A_M		instruction_81
#define LD8_A_NSP	instruction_82
#define LD8_A_NNZ	instruction_83
#define LD8_A_Y		instruction_84
#define LD8_A_NY	instruction_85
#define LD8_A_XH	instruction_86
#define LD8_A_YL	instruction_87
#define LD8_A_YH	instruction_88
#define LD8_A_ZL	instruction_89
#define LD8_A_ZH	instruction_8a
#define LD8_M_A		instruction_8b
#define LD8_NSP_A	instruction_8c
#define LD8_NNZ_A	instruction_8d
#define LD8_Y_A		instruction_8e
#define LD8_NY_A	instruction_8f
#define LD8_YH_I	instruction_94

#define LDW_A_I		instruction_c0
#define LDW_A_M		instruction_c1
#define LDW_A_NSP	instruction_c2
#define LDW_A_NNZ	instruction_c3
#define LDW_A_NY	instruction_c4
#define LDW_A_Y		instruction_c5
#define LDW_A_X		instruction_c6
#define LDW_A_D		instruction_c7
#define LDW_M_A		instruction_c8
#define LDW_NSP_A	instruction_c9
#define LDW_NNZ_A	instruction_ca
#define LDW_X_A		instruction_cb
#define LDW_Z_A		instruction_cc
#define LDW_AM_X	instruction_cd
#define LDW_NAM_X	instruction_ce
#define LDW_NNAM_X	instruction_cf
#define LDW_SP_A	instruction_70
#define LDW_DSP_A	instruction_74

#define PUSH_M		instruction_60
#define PUSH_NSP	instruction_61
#define PUSH_A		instruction_62
#define PUSH_ZH		instruction_63
#define PUSH_I		instruction_90

#define PUSHW_M		instruction_b0
#define PUSHW_NSP	instruction_b1
#define PUSHW_NNZ	instruction_b2
#define PUSHW_A		instruction_b3
#define PUSHW_I		instruction_e8

#define POP_A		instruction_99
#define POPW_A		instruction_e9

#define XCH_A_NSP	instruction_91
#define XCH_A_Y		instruction_92
#define XCH_A_A		instruction_93
#define XCHW_Y_Z	instruction_f4
#define XCHW_Z_NSP	instruction_f5

#define CAX		instruction_9b
#define CAXW		instruction_f9

#define CLR_M		instruction_58
#define CLR_NSP		instruction_59
#define CLR_A		instruction_5a
#define CLR_ZH		instruction_5b
#define CLRW_M		instruction_a0
#define CLRW_NSP	instruction_a1
#define CLRW_NNZ	instruction_a2
#define CLRW_A		instruction_a3

#define XCHB_0		instruction_68
#define XCHB_1		instruction_69
#define XCHB_2		instruction_6a
#define XCHB_3		instruction_6b
#define XCHB_4		instruction_6c
#define XCHB_5		instruction_6d
#define XCHB_6		instruction_6e
#define XCHB_7		instruction_6f

// arithmetic instructions
#define ADD_I		instruction_10
#define ADD_M		instruction_12
#define ADD_NSP		instruction_13
#define ADD_NNZ		instruction_14
#define ADD_ZL		instruction_15
#define ADD_XH		instruction_16
#define ADD_YL		instruction_17
#define ADD_YH		instruction_18

// branches
#define JP_I		instruction_64
#define JP_A		instruction_65
#define CALL_I		instruction_66
#define CALL_A		instruction_67
#define RET		instruction_ba
#define RETI		instruction_bb

#define JR		instruction_d0
#define DNJNZ		instruction_d1
#define JRZ		instruction_d2
#define JRNZ		instruction_d3
#define JRC		instruction_d4
#define JRNC		instruction_d5
#define JRN		instruction_d6
#define JRNN		instruction_d7
#define JRO		instruction_d8
#define JRNO		instruction_d9
#define JRSGE		instruction_da
#define JRSLT		instruction_db
#define JRSGT		instruction_dc
#define JRSLE		instruction_dd
#define JRGT		instruction_de
#define JRLE		instruction_df

// other instructions
#define NOP		instruction_08
#define TRAP		instruction_00

#endif

/* End of f8.src/decode.h */
