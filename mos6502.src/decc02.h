/*
 * Simulator of microcontrollers (decc02.h)
 *
 * Copyright (C) @@S@@,@@Y@@ Drotos Daniel, Talker Bt.
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

#ifndef DECC02_HEADER
#define DECC02_HEADER

#define ORAzi	instruction_12
#define ANDzi	instruction_32
#define EORzi	instruction_52
#define ADCzi	instruction_72
#define STAzi	instruction_92
#define LDAzi	instruction_b2
#define CMPzi	instruction_d2
#define SBCzi	instruction_f2

#define BITzx	instruction_34

#define BIT8	instruction_88

#define BITax	instruction_3c
#define JMP7c	instruction_7c

#define INA	instruction_1a
#define DEA	instruction_3a

#endif

/* End of mos6502.src/decc02.h */