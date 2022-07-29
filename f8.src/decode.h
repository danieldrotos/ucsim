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

#define INC_M		instruction_50
#define INC_NSP		instruction_51
#define INC_A		instruction_52
#define INC_ZH		instruction_53
#define DEC_M		instruction_54
#define DEC_NSP		instruction_55
#define DEC_A		instruction_56
#define DEC_ZH		instruction_57

// arithmetic instructions
#define ADD_I		instruction_10
#define ADD_M		instruction_11
#define ADD_NSP		instruction_12
#define ADD_NNZ		instruction_13
#define ADD_ZL		instruction_14
#define ADD_XH		instruction_15
#define ADD_YL		instruction_16
#define ADD_YH		instruction_17

#define ADC_I		instruction_18
#define ADC_M		instruction_19
#define ADC_NSP		instruction_1a
#define ADC_NNZ		instruction_1b
#define ADC_ZL		instruction_1c
#define ADC_XH		instruction_1d
#define ADC_YL		instruction_1e
#define ADC_YH		instruction_1f

#define SUB_M		instruction_01
#define SUB_NSP		instruction_02
#define SUB_NNZ		instruction_03
#define SUB_ZL		instruction_04
#define SUB_XH		instruction_05
#define SUB_YL		instruction_06
#define SUB_YH		instruction_07

#define SBC_M		instruction_09
#define SBC_NSP		instruction_0a
#define SBC_NNZ		instruction_0b
#define SBC_ZL		instruction_0c
#define SBC_XH		instruction_0d
#define SBC_YL		instruction_0e
#define SBC_YH		instruction_0f

#define CP_I		instruction_20
#define CP_M		instruction_21
#define CP_NSP		instruction_22
#define CP_NNZ		instruction_23
#define CP_ZL		instruction_24
#define CP_XH		instruction_25
#define CP_YL		instruction_26
#define CP_YH		instruction_27

#define OR_I		instruction_28
#define OR_M		instruction_29
#define OR_NSP		instruction_2a
#define OR_NNZ		instruction_2b
#define OR_ZL		instruction_2c
#define OR_XH		instruction_2d
#define OR_YL		instruction_2e
#define OR_YH		instruction_2f

#define AND_I		instruction_30
#define AND_M		instruction_31
#define AND_NSP		instruction_32
#define AND_NNZ		instruction_33
#define AND_ZL		instruction_34
#define AND_XH		instruction_35
#define AND_YL		instruction_36
#define AND_YH		instruction_37

#define XOR_I		instruction_38
#define XOR_M		instruction_39
#define XOR_NSP		instruction_3a
#define XOR_NNZ		instruction_3b
#define XOR_ZL		instruction_3c
#define XOR_XH		instruction_3d
#define XOR_YL		instruction_3e
#define XOR_YH		instruction_3f

#define SUBW_M		instruction_71
#define SUBW_NSP	instruction_72
#define SUBW_X		instruction_73
#define SBCW_M		instruction_75
#define SBCW_NSP	instruction_76
#define SBCW_X		instruction_77

#define ADDW_I		instruction_78
#define ADDW_M		instruction_79
#define ADDW_NSP	instruction_7a
#define ADDW_X		instruction_7b
#define ADCW_I		instruction_7c
#define ADCW_M		instruction_7d
#define ADCW_NSP	instruction_7e
#define ADCW_X		instruction_7f

#define ORW_I		instruction_f0
#define ORW_M		instruction_f1
#define ORW_NSP		instruction_f2
#define ORW_X		instruction_f3

#define SRL_M		instruction_40
#define SRL_NSP		instruction_41
#define SRL_A		instruction_42
#define SRL_ZH		instruction_43
#define SLL_M		instruction_44
#define SLL_NSP		instruction_45
#define SLL_A		instruction_46
#define SLL_ZH		instruction_47
#define RRC_M		instruction_48
#define RRC_NSP		instruction_49
#define RRC_A		instruction_4a
#define RRC_ZH		instruction_4b
#define RLC_M		instruction_4c
#define RLC_NSP		instruction_4d
#define RLC_A		instruction_4e
#define RLC_ZH		instruction_4f

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
