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

#define NOP	instruction_ea
#define BRK	instruction_00
#define RTI	instruction_40
#define CLI	instruction_58
#define SEI	instruction_78
#define PHP	instruction_08
#define CLC	instruction_18
#define PLP	instruction_28
#define SEc	instruction_38
#define PHA	instruction_48
#define PLA	instruction_68
#define DEY	instruction_88
#define TYA	instruction_98
#define TAY	instruction_a8
#define CLV	instruction_b8
#define INY	instruction_c8
#define CLD	instruction_d8
#define INX	instruction_e8
#define SED	instruction_f8
#define TXA	instruction_8a
#define TXS	instruction_9a
#define TAX	instruction_aa
#define TSX	instruction_ba
#define DEX	instruction_ca

#define ORAix	instruction_01
#define ORAiy	instruction_11
#define ORAz	instruction_05
#define ORAzx	instruction_15
#define ORA8	instruction_09
#define ORAay	instruction_19
#define ORAa	instruction_0d
#define ORAax	instruction_1d

#define ANDix	instruction_21
#define ANDiy	instruction_31
#define ANDz	instruction_25
#define ANDzx	instruction_35
#define AND8	instruction_29
#define ANDay	instruction_39
#define ANDa	instruction_2d
#define ANDax	instruction_3d

#define EORix	instruction_41
#define EORiy	instruction_51
#define EORz	instruction_45
#define EORzx	instruction_55
#define EOR8	instruction_49
#define EORay	instruction_59
#define EORa	instruction_4d
#define EORax	instruction_5d

#define ADCix	instruction_61
#define ADCiy	instruction_71
#define ADCz	instruction_65
#define ADCzx	instruction_75
#define ADC8	instruction_69
#define ADCay	instruction_79
#define ADCa	instruction_6d
#define ADCax	instruction_7d

#define STAix	instruction_81
#define STAiy	instruction_91
#define STAz	instruction_85
#define STAzx	instruction_95
#define STAay	instruction_99
#define STAa	instruction_8d
#define STAax	instruction_9d

#define LDAix	instruction_a1
#define LDAiy	instruction_b1
#define LDAz	instruction_a5
#define LDAzx	instruction_b5
#define LDA8	instruction_a9
#define LDAay	instruction_b9
#define LDAa	instruction_ad
#define LDAax	instruction_bd

#define CMPix	instruction_c1
#define CMPiy	instruction_d1
#define CMPz	instruction_c5
#define CMPzx	instruction_d5
#define CMP8	instruction_c9
#define CMPay	instruction_d9
#define CMPa	instruction_cd
#define CMPax	instruction_dd

#define SBCix	instruction_e1
#define SBCiy	instruction_f1
#define SBCz	instruction_e5
#define SBCzx	instruction_f5
#define SBC8	instruction_e9
#define SBCay	instruction_f9
#define SBCa	instruction_ed
#define SBCax	instruction_fd

#define STYz	instruction_84
#define STYzx	instruction_94
#define STYa    instruction_8c
#define STXz	instruction_86
#define STXzy	instruction_96
#define STXa    instruction_8e

#define LDY8    instruction_a0
#define LDYz    instruction_a4
#define LDYzx   instruction_b4
#define LDYa	instruction_ac
#define LDYax	instruction_bc
#define LDX8    instruction_a2
#define LDXz    instruction_a6
#define LDXzy   instruction_b6
#define LDXa	instruction_ae
#define LDXay	instruction_be

#endif

/* End of mcs6502.src/decode.h */
