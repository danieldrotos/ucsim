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
#define LD8_YL_I	instruction_94

#define LDW_A_I		instruction_d0
#define LDW_A_M		instruction_d1
#define LDW_A_NSP	instruction_d2
#define LDW_A_NNZ	instruction_d3
#define LDW_A_NY	instruction_d4
#define LDW_A_Y		instruction_d5
#define LDW_A_X		instruction_d6
#define LDW_A_D		instruction_d7
#define LDW_M_A		instruction_d8
#define LDW_NSP_A	instruction_d9
#define LDW_NNZ_A	instruction_da
#define LDW_X_A		instruction_db
#define LDW_Z_A		instruction_dc
#define LDW_AM_X	instruction_dd
#define LDW_NAM_X	instruction_de
#define LDW_NNAM_X	instruction_df
#define LDW_SP_A	instruction_70
#define LDW_DSP_A	instruction_74

// arithmetic instructions

// branches

// other instructions
#define NOP		instruction_08
#define TRAP		instruction_00

#endif

/* End of f8.src/decode.h */
