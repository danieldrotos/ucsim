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

// code mask branch len mn call tick
struct dis_entry disass_m6809[]=
  {
   { 0x3a, 0xff, ' ', 1, "ABX"		, 0, 0 },
   { 0x48, 0xff, ' ', 1, "ASLA"		, 0, 0 },
   { 0x58, 0xff, ' ', 1, "ASLB"		, 0, 0 },
   { 0x47, 0xff, ' ', 1, "ASRA"		, 0, 0 },
   { 0x57, 0xff, ' ', 1, "ASRB"		, 0, 0 },
   { 0x4f, 0xff, ' ', 1, "CLRA"		, 0, 0 },
   { 0x5f, 0xff, ' ', 1, "CLRB"		, 0, 0 },
   { 0x43, 0xff, ' ', 1, "COMA"		, 0, 0 },
   { 0x53, 0xff, ' ', 1, "COMB"		, 0, 0 },
   { 0x19, 0xff, ' ', 1, "DAA"		, 0, 0 },
   { 0x4a, 0xff, ' ', 1, "DECA"		, 0, 0 },
   { 0x5a, 0xff, ' ', 1, "DECB"		, 0, 0 },
   { 0x4c, 0xff, ' ', 1, "INCA"		, 0, 0 },
   { 0x5c, 0xff, ' ', 1, "INCB"		, 0, 0 },
   { 0x44, 0xff, ' ', 1, "LSRA"		, 0, 0 },
   { 0x54, 0xff, ' ', 1, "LSRB"		, 0, 0 },
   { 0x3d, 0xff, ' ', 1, "MUL"		, 0, 0 },
   { 0x40, 0xff, ' ', 1, "NEGA"		, 0, 0 },
   { 0x50, 0xff, ' ', 1, "NEGB"		, 0, 0 },
   { 0x12, 0xff, ' ', 1, "NOP"		, 0, 0 },
   { 0x49, 0xff, ' ', 1, "ROLA"		, 0, 0 },
   { 0x59, 0xff, ' ', 1, "ROLB"		, 0, 0 },
   { 0x46, 0xff, ' ', 1, "RORA"		, 0, 0 },
   { 0x56, 0xff, ' ', 1, "RORB"		, 0, 0 },
   { 0x3b, 0xff, ' ', 1, "RTI"		, 0, 0 },
   { 0x39, 0xff, ' ', 1, "RTS"		, 0, 0 },
   { 0x1d, 0xff, ' ', 1, "SEX"		, 0, 0 },
   { 0x3f, 0xff, ' ', 1, "SWI"		, 0, 0 },
   { 0x13, 0xff, ' ', 1, "SYNC"		, 0, 0 },
   { 0x4d, 0xff, ' ', 1, "TSTA"		, 0, 0 },
   { 0x5d, 0xff, ' ', 1, "TSTB"		, 0, 0 },
   
   { 0x89, 0xcf, ' ', 1, "ADCA %u"	, 0, 0 },
   { 0xc9, 0xcf, ' ', 1, "ADCB %u"	, 0, 0 },
   { 0x8b, 0xcf, ' ', 1, "ADDA %u"	, 0, 0 },
   { 0xcb, 0xcf, ' ', 1, "ADDB %u"	, 0, 0 },
   { 0x84, 0xcf, ' ', 1, "ANDA %u"	, 0, 0 },
   { 0xc4, 0xcf, ' ', 1, "ANDB %u"	, 0, 0 },
   { 0x85, 0xcf, ' ', 1, "BITA %u"	, 0, 0 },
   { 0xc5, 0xcf, ' ', 1, "BITB %u"	, 0, 0 },
   { 0x81, 0xcf, ' ', 1, "CMPA %u"	, 0, 0 },
   { 0xc1, 0xcf, ' ', 1, "CMPB %u"	, 0, 0 },
   { 0x88, 0xcf, ' ', 1, "EORA %u"	, 0, 0 },
   { 0xc8, 0xcf, ' ', 1, "EORB %u"	, 0, 0 },
   { 0x86, 0xcf, ' ', 1, "LDA %u"	, 0, 0 },
   { 0xc6, 0xcf, ' ', 1, "LDB %u"	, 0, 0 },
   { 0x8a, 0xcf, ' ', 1, "ORA %u"	, 0, 0 },
   { 0xca, 0xcf, ' ', 1, "ORB %u"	, 0, 0 },
   { 0x82, 0xcf, ' ', 1, "SBCA %u"	, 0, 0 },
   { 0xc2, 0xcf, ' ', 1, "SBCB %u"	, 0, 0 },
   { 0x80, 0xcf, ' ', 1, "SUBA %u"	, 0, 0 },
   { 0xc0, 0xcf, ' ', 1, "SUBB %u"	, 0, 0 },

   { 0x87, 0xcf, ' ', 1, "STA %n"	, 0, 0 },
   { 0xc7, 0xcf, ' ', 1, "STB %n"	, 0, 0 },

   { 0xc3, 0xcf, ' ', 1, "ADDD %U"	, 0, 0 },
   { 0xcc, 0xcf, ' ', 1, "LDD %U"	, 0, 0 },
   { 0xce, 0xcf, ' ', 1, "LDU %U"	, 0, 0 },
   { 0x8e, 0xcf, ' ', 1, "LDX %U"	, 0, 0 },
   { 0x83, 0xcf, ' ', 1, "SUBD %U"	, 0, 0 },
   
   { 0xcd, 0xcf, ' ', 1, "STD %N"	, 0, 0 },
   { 0x8f, 0xcf, ' ', 1, "STX %N"	, 0, 0 },

   { 0x08, 0xcf, ' ', 1, "LSL %n"	, 0, 0 },
   { 0x04, 0xcf, ' ', 1, "LSR %n"	, 0, 0 },
   { 0x00, 0xcf, ' ', 1, "NEG %n"	, 0, 0 },
   { 0x09, 0xcf, ' ', 1, "ROL %n"	, 0, 0 },
   { 0x06, 0xcf, ' ', 1, "ROR %n"	, 0, 0 },
   { 0x0d, 0xcf, ' ', 1, "TST %n"	, 0, 0 },
  
   { 0, 0, 0, 0, 0, 0 }
  };

struct dis_entry disass_m6809_10[]=
  {
   { 0x83, 0xcf, ' ', 1, "CMPD %U"	, 0, 0 },
   { 0x8c, 0xcf, ' ', 1, "CMPY %U"	, 0, 0 },
   { 0xce, 0xcf, ' ', 1, "LDS %U"	, 0, 0 },
   { 0x8e, 0xcf, ' ', 1, "LDY %U"	, 0, 0 },

   { 0x3f, 0xff, ' ', 1, "SWI2"		, 0, 0 },
   
   { 0, 0, 0, 0, 0, 0 }
  };

struct dis_entry disass_m6809_11[]=
  {
   { 0x83, 0xcf, ' ', 1, "CMPU %U"	, 0, 0 },
   { 0x8c, 0xcf, ' ', 1, "CMPS %U"	, 0, 0 },
   
   { 0x3f, 0xff, ' ', 1, "SWI3"		, 0, 0 },

   { 0, 0, 0, 0, 0, 0 }
  };

/* End of m6809.src/glob.cc */
