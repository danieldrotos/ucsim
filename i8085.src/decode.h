/*
 * Simulator of microcontrollers (decode.h)
 *
 * Copyright (C) 2020,20 Drotos Daniel, Talker Bt.
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

#ifndef DECODE_HEADER
#define DECODE_HEADER

#include "dcmovrr.h"

#define NOP	instruction_00
#define HLT	instruction_76

#define MVI_Ai8		instruction_3e
#define MVI_Bi8		instruction_06
#define MVI_Ci8		instruction_0e
#define MVI_Di8		instruction_16
#define MVI_Ei8		instruction_1e
#define MVI_Hi8		instruction_26
#define MVI_Li8		instruction_2e
#define MVI_Mi8		instruction_36

#define LXI_Bi16	instruction_01
#define LXI_Di16	instruction_11
#define LXI_Hi16	instruction_21
#define LXI_Si16	instruction_31

#define LDA_a16		instruction_3a
#define STA_a16		instruction_32
#define LHLD_a16	instruction_2a
#define SHLD_a16	instruction_22
#define LDAX_B		instruction_0a
#define LDAX_D		instruction_1a
#define STAX_B		instruction_02
#define STAX_D		instruction_12
#define XCHG		instruction_eb

#define ADD_A		instruction_87
#define ADD_B		instruction_80
#define ADD_C		instruction_81
#define ADD_D		instruction_82
#define ADD_E		instruction_83
#define ADD_H		instruction_84
#define ADD_L		instruction_85
#define ADD_M		instruction_86
#define ADI		instruction_c6

#define ADC_A		instruction_8f
#define ADC_B		instruction_88
#define ADC_C		instruction_89
#define ADC_D		instruction_8a
#define ADC_E		instruction_8b
#define ADC_H		instruction_8c
#define ADC_L		instruction_8d
#define ADC_M		instruction_8e
#define ACI		instruction_ce

#define SUB_A		instruction_97
#define SUB_B		instruction_90
#define SUB_C		instruction_91
#define SUB_D		instruction_92
#define SUB_E		instruction_93
#define SUB_H		instruction_94
#define SUB_L		instruction_95
#define SUB_M		instruction_96
#define SUI		instruction_d6

#define SBB_A		instruction_9f
#define SBB_B		instruction_98
#define SBB_C		instruction_99
#define SBB_D		instruction_9a
#define SBB_E		instruction_9b
#define SBB_H		instruction_9c
#define SBB_L		instruction_9d
#define SBB_M		instruction_9e
#define SBI		instruction_de


#endif

/* End of i8085.src/decode.h */
