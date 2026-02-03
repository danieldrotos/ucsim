/*
 * Simulator of microcontrollers (dechuc.h)
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

#ifndef DECHUC_HEADER
#define DECHUC_HEADER


#define SXY		instruction_02
#define SAX		instruction_22
#define SAY		instruction_42
#define CLA		instruction_62
#define CLX		instruction_82
#define CLY		instruction_c2

#define STO		instruction_03
#define ST1		instruction_13
#define ST2		instruction_23
#define TMA		instruction_43
#define TAM		instruction_53
#define TII		instruction_73
#define TDD		instruction_c3
#define TIN		instruction_d3
#define TIA		instruction_e3
#define TAI		instruction_f3
#define TST_imzp	instruction_83
#define TST_imab	instruction_93
#define TST_imzpx	instruction_a3
#define TST_imabx	instruction_b3

#define BSR		instruction_44

#define CSL		instruction_54
#define CSH		instruction_d4
#define SET		instruction_f4


#endif


/* End of mos6502.src/dechuc.h */
