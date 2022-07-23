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
#define PREF_SWAPOP	0x9c
#define PREF_ALT0	0x9d
#define PREF_ALT1	0x9e
#define PREF_ALT2	0x9f


// data moves

// arithmetic instructions

// branches

// other instructions
#define NOP		instruction_08
#define TRAP		instruction_00

#endif

/* End of f8.src/decode.h */
