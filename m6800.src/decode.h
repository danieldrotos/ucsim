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

#define NOP   instruction_01
#define TAP   instruction_06
#define TPA   instruction_07
#define INX   instruction_08
#define DEX   instruction_09
#define CLV   instruction_0a
#define SEV   instruction_0b
#define CLC   instruction_0c
#define SEc   instruction_0d
#define CLI   instruction_0e
#define SEI   instruction_0f

#define SBA   instruction_10
#define CBA   instruction_11
#define TAB   instruction_16
#define TBA   instruction_17
#define DAA   instruction_19
#define ABA   instruction_1b

#define TSX   instruction_30
#define INS   instruction_31
#define PULA  instruction_32
#define PULB  instruction_33
#define DES   instruction_34
#define TXS   instruction_35
#define PSHA  instruction_36
#define PSHB  instruction_37
#define RTS   instruction_39

#endif

/* End of m6800.src/decode.h */
