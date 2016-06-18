/*
 * Simulator of microcontrollers (tlcs.src/glob.cc)
 *
 * Copyright (C) 2016,16 Drotos Daniel, Talker Bt.
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

/* $Id$ */

#include <stdio.h>

#include "glob.h"

struct dis_entry disass_tlcs[]= {
  { 0x08, 0xff, ' ', 1, "EX DE,HL" },
  { 0x09, 0xff, ' ', 1, "EX AF,AF'" },
  { 0x0a, 0xff, ' ', 1, "EXX" },
  { 0x0b, 0xff, ' ', 1, "DAA A" },
  { 0x10, 0xff, ' ', 1, "CPL A" },
  { 0x11, 0xff, ' ', 1, "NEG A" },
  { 0x0e, 0xff, ' ', 1, "CCF" },
  { 0x0d, 0xff, ' ', 1, "SCF" },
  { 0x0c, 0xff, ' ', 1, "RCF" },
  { 0x00, 0xff, ' ', 1, "NOP" },
  { 0x01, 0xff, ' ', 1, "HALT" },
  { 0x02, 0xff, ' ', 1, "DI" },
  { 0x03, 0xff, ' ', 1, "EI" },
  { 0xff, 0xff, ' ', 1, "SWI" },
  { 0xa0, 0xff, ' ', 1, "RLCA" },
  { 0xa1, 0xff, ' ', 1, "RRCA" },
  { 0xa2, 0xff, ' ', 1, "RLA" },
  { 0xa3, 0xff, ' ', 1, "RRA" },
  { 0xa4, 0xff, ' ', 1, "SLAA" },
  { 0xa5, 0xff, ' ', 1, "SRAA" },
  { 0xa6, 0xff, ' ', 1, "SLLA" },
  { 0xa7, 0xff, ' ', 1, "SRLA" },
  { 0x1e, 0xff, ' ', 1, "RET" },
  { 0x1f, 0xff, ' ', 1, "RETI" },

  { 0x20, 0xf8, 'r', 1, "LD A,%r" },
  { 0x28, 0xf8, 'r', 1, "LD %r,A" },
  { 0x40, 0xf8, 'R', 1, "LD HL,%R" },
  { 0x48, 0xf8, 'R', 1, "LD %R,HL" },
  { 0x50, 0xf8, 'Q', 1, "PUSH %Q" },
  { 0x58, 0xf8, 'Q', 1, "POP %Q" },
  { 0x80, 0xf8, 'r', 1, "INC %r" },
  { 0x88, 0xf8, 'r', 1, "DEC %r" },
  { 0x90, 0xf8, 'R', 1, "INC %R" },
  { 0x98, 0xf8, 'R', 1, "DEC %R" },

  { 0x10f3, 0xffff, ' ', 2, "RLD (HL+A)" },
  { 0x11f3, 0xffff, ' ', 2, "RRD (HL+A)" },
  { 0x12f3, 0xffff, ' ', 2, "MUL HL,(HL+A)" },
  { 0x13f3, 0xffff, ' ', 2, "DIV HL,(HL+A)" },
  { 0x60f3, 0xffff, ' ', 2, "ADD A,(HL+A)" },
  { 0x61f3, 0xffff, ' ', 2, "ADC A,(HL+A)" },
  { 0x62f3, 0xffff, ' ', 2, "SUB A,(HL+A)" },
  { 0x63f3, 0xffff, ' ', 2, "SBC A,(HL+A)" },
  { 0x64f3, 0xffff, ' ', 2, "AND A,(HL+A)" },
  { 0x65f3, 0xffff, ' ', 2, "XOR A,(HL+A)" },
  { 0x66f3, 0xffff, ' ', 2, "OR A,(HL+A)" },
  { 0x67f3, 0xffff, ' ', 2, "CP A,(HL+A)" },
  { 0x70f3, 0xffff, ' ', 2, "ADD HL,(HL+A)" },
  { 0x71f3, 0xffff, ' ', 2, "ADC HL,(HL+A)" },
  { 0x72f3, 0xffff, ' ', 2, "SUB HL,(HL+A)" },
  { 0x73f3, 0xffff, ' ', 2, "SBC HL,(HL+A)" },
  { 0x74f3, 0xffff, ' ', 2, "AND HL,(HL+A)" },
  { 0x75f3, 0xffff, ' ', 2, "XOR HL,(HL+A)" },
  { 0x76f3, 0xffff, ' ', 2, "OR HL,(HL+A)" },
  { 0x77f3, 0xffff, ' ', 2, "CP HL,(HL+A)" },
  { 0x87f3, 0xffff, ' ', 2, "INC (HL+A)" },
  { 0x8ff3, 0xffff, ' ', 2, "DEC (HL+A)" },
  { 0x97f3, 0xffff, ' ', 2, "INCW (HL+A)" },
  { 0x9ff3, 0xffff, ' ', 2, "DECW (HL+A)" },
  { 0xa0f3, 0xffff, ' ', 2, "RLC (HL+A)" },
  { 0xa1f3, 0xffff, ' ', 2, "RRC (HL+A)" },
  { 0xa2f3, 0xffff, ' ', 2, "RL (HL+A)" },
  { 0xa3f3, 0xffff, ' ', 2, "RR (HL+A)" },
  { 0xa4f3, 0xffff, ' ', 2, "SLA (HL+A)" },
  { 0xa5f3, 0xffff, ' ', 2, "SRA (HL+A)" },
  { 0xa6f3, 0xffff, ' ', 2, "SLL (HL+A)" },
  { 0xa7f3, 0xffff, ' ', 2, "SRL (HL+A)" },

  { 0x58fe, 0xffff, ' ', 2, "LDI" },
  { 0x59fe, 0xffff, ' ', 2, "LDIR" },
  { 0x5afe, 0xffff, ' ', 2, "LDD" },
  { 0x5bfe, 0xffff, ' ', 2, "LDDR" },
  { 0x5cfe, 0xffff, ' ', 2, "CPI" },
  { 0x5dfe, 0xffff, ' ', 2, "CPIR" },
  { 0x5efe, 0xffff, ' ', 2, "CPD" },
  { 0x5ffe, 0xffff, ' ', 2, "CPDR" },

  { 0x14f3, 0xfcff, 'i', 2, "ADD %i,(HL+A)" },

  { 0, 0, ' ', 0, NULL }
};

/* End of tlcs.src/glob.cc */
