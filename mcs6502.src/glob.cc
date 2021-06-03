/*
 * Simulator of microcontrollers (glob.cc)
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

#include "glob.h"


instruction_wrapper_fn itab[256];

/*	Formats
	x (ind,X)
	y (ind),Y
	a abs
	z zpg
	X zpg,X
	Y zpg,Y
	i abs,X
	p abs.Y
	r rel
	# imm8
*/

// code mask branch len mn call tick
struct dis_entry disass_mcs6502[]=
  {
    { 0xea, 0xff, ' ', 1, "NOP" },
    { 0x00, 0xff, ' ', 1, "BRK" },
    { 0x40, 0xff, ' ', 1, "RTI" },
    { 0x58, 0xff, ' ', 1, "CLI" },
    { 0x78, 0xff, ' ', 1, "SEI" },
    { 0x08, 0xff, ' ', 1, "PHP" },
    { 0x18, 0xff, ' ', 1, "CLC" },
    { 0x28, 0xff, ' ', 1, "PLP" },
    { 0x38, 0xff, ' ', 1, "SEC" },
    { 0x48, 0xff, ' ', 1, "PHA" },
    { 0x68, 0xff, ' ', 1, "PLA" },
    { 0x88, 0xff, ' ', 1, "DEY" },
    { 0x98, 0xff, ' ', 1, "TYA" },
    { 0xa8, 0xff, ' ', 1, "TAY" },
    { 0xb8, 0xff, ' ', 1, "CLV" },
    { 0xc8, 0xff, ' ', 1, "INY" },
    { 0xd8, 0xff, ' ', 1, "CLD" },
    { 0xe8, 0xff, ' ', 1, "INX" },
    { 0xf8, 0xff, ' ', 1, "SED" },
    { 0x8a, 0xff, ' ', 1, "TXA" },
    { 0x9a, 0xff, ' ', 1, "TXS" },
    { 0xaa, 0xff, ' ', 1, "TAX" },
    { 0xba, 0xff, ' ', 1, "TSX" },
    { 0xca, 0xff, ' ', 1, "DEX" },

    { 0x01, 0xff, ' ', 2, "ORA %x" },
    { 0x11, 0xff, ' ', 2, "ORA %y" },
    { 0x05, 0xff, ' ', 2, "ORA %z" },
    { 0x15, 0xff, ' ', 2, "ORA %X" },
    { 0x09, 0xff, ' ', 2, "ORA %#" },
    { 0x19, 0xff, ' ', 2, "ORA %p" },
    { 0x0d, 0xff, ' ', 3, "ORA %a" },
    { 0x1d, 0xff, ' ', 3, "ORA %i" },

    { 0x21, 0xff, ' ', 2, "AND %x" },
    { 0x31, 0xff, ' ', 2, "AND %y" },
    { 0x25, 0xff, ' ', 2, "AND %z" },
    { 0x35, 0xff, ' ', 2, "AND %X" },
    { 0x29, 0xff, ' ', 2, "AND %#" },
    { 0x39, 0xff, ' ', 2, "AND %p" },
    { 0x2d, 0xff, ' ', 3, "AND %a" },
    { 0x3d, 0xff, ' ', 3, "AND %i" },

    { 0x41, 0xff, ' ', 2, "EOR %x" },
    { 0x51, 0xff, ' ', 2, "EOR %y" },
    { 0x45, 0xff, ' ', 2, "EOR %z" },
    { 0x55, 0xff, ' ', 2, "EOR %X" },
    { 0x49, 0xff, ' ', 2, "EOR %#" },
    { 0x59, 0xff, ' ', 2, "EOR %p" },
    { 0x4d, 0xff, ' ', 3, "EOR %a" },
    { 0x5d, 0xff, ' ', 3, "EOR %i" },

    { 0, 0, 0, 0, 0, 0 }
  };

/* End of mcs6502.src/glob.cc */
