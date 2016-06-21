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
  { 0xff, 0xff, ' ', 1, "SWI", true },
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

  { 0x14f3, 0xfcff, 'i', 2, "ADD %i,(HL+A)" },
  { 0x18f3, 0xf8ff, 'b', 2, "TSET %b,(HL+A)" },
  { 0x28f3, 0xf8ff, 'p', 2, "LD %p,(HL+A)" },
  { 0x48f3, 0xf8ff, 's', 2, "LD %s,(HL+A)" },
  { 0x50f3, 0xf8ff, 's', 2, "EX (HL+A),%s" },
  { 0xa8f3, 0xf8ff, 'b', 2, "BIT %b,(HL+A)" },
  { 0xb0f3, 0xf8ff, 'b', 2, "RES %b,(HL+A)" },
  { 0xb8f3, 0xf8ff, 'b', 2, "SET %b,(HL+A)" },
  
  { 0x58fe, 0xffff, ' ', 2, "LDI" },
  { 0x59fe, 0xffff, ' ', 2, "LDIR" },
  { 0x5afe, 0xffff, ' ', 2, "LDD" },
  { 0x5bfe, 0xffff, ' ', 2, "LDDR" },
  { 0x5cfe, 0xffff, ' ', 2, "CPI" },
  { 0x5dfe, 0xffff, ' ', 2, "CPIR" },
  { 0x5efe, 0xffff, ' ', 2, "CPD" },
  { 0x5ffe, 0xffff, ' ', 2, "CPDR" },
  { 0xf0fe, 0xf0ff, 'C', 2, "RET %C" },
  
  { 0x20f7, 0xf8ff, 'p', 2, "LD (HL+A),%p" },
  { 0x38f7, 0xf8ff, 's', 2, "LDA %s,HL+A" },
  { 0x40f7, 0xf8ff, 's', 2, "LD (HL+A),%s" },
  { 0xc0f7, 0xf0ff, 'c', 2, "JP %cHL+A" },
  { 0xd0f7, 0xf0ff, 'c', 2, "CALL %cHL+A" },

  { 0x10e0, 0xfff8, 'R', 2, "RLD (%R)" },
  { 0x11e0, 0xfff8, 'R', 2, "RRD (%R)" },
  { 0x12e0, 0xfff8, 'R', 2, "MUL HL,(%R)" },
  { 0x13e0, 0xfff8, 'R', 2, "DIV HL,(%R)" },
  { 0x14e0, 0xfcf8, 'R', 2, "ADD %i,(%R)" },
  { 0x18e0, 0xf8f8, 'R', 2, "TSET %b,(%R)" },
  { 0x28e0, 0xf8f8, 'R', 2, "LD %p,(%R)" },
  { 0x48e0, 0xf8f8, 'R', 2, "LD %s,(%R)" },
  { 0x50e0, 0xf8f8, 'R', 2, "EX (%R),$s" },
  { 0xa8e0, 0xf8f8, 'R', 2, "BIT %b,(%R)" },
  { 0xb0e0, 0xf8f8, 'R', 2, "RES %b,(%R)" },
  { 0xb8e0, 0xf8f8, 'R', 2, "SET %b,(%R)" },
  { 0x60e0, 0xfff8, 'R', 2, "ADD A,(%R)" },
  { 0x61e0, 0xfff8, 'R', 2, "ADC A,(%R)" },
  { 0x62e0, 0xfff8, 'R', 2, "SUB A,(%R)" },
  { 0x63e0, 0xfff8, 'R', 2, "SBC A,(%R)" },
  { 0x64e0, 0xfff8, 'R', 2, "AND A,(%R)" },
  { 0x65e0, 0xfff8, 'R', 2, "XOR A,(%R)" },
  { 0x66e0, 0xfff8, 'R', 2, "OR A,(%R)" },
  { 0x67e0, 0xfff8, 'R', 2, "CP A,(%R)" },
  { 0x70e0, 0xfff8, 'R', 2, "ADD HL,(%R)" },
  { 0x71e0, 0xfff8, 'R', 2, "ADC HL,(%R)" },
  { 0x72e0, 0xfff8, 'R', 2, "SUB HL,(%R)" },
  { 0x73e0, 0xfff8, 'R', 2, "SBC HL,(%R)" },
  { 0x70e0, 0xfff8, 'R', 2, "AND HL,(%R)" },
  { 0x75e0, 0xfff8, 'R', 2, "XOR HL,(%R)" },
  { 0x76e0, 0xfff8, 'R', 2, "OR HL,(%R)" },
  { 0x77e0, 0xfff8, 'R', 2, "CP HL,(%R)" },
  { 0x87a0, 0xfff8, 'R', 2, "INC (%R)" },
  { 0x8fa0, 0xfff8, 'R', 2, "DEC (%R)" },
  { 0x97a0, 0xfff8, 'R', 2, "INCW (%R)" },
  { 0x9fa0, 0xfff8, 'R', 2, "DECW (%R)" },
  { 0xa0e0, 0xfff8, 'R', 2, "RLC (%R)" },
  { 0xa1e0, 0xfff8, 'R', 2, "RRC (%R)" },
  { 0xa2e0, 0xfff8, 'R', 2, "RL (%R)" },
  { 0xa3e0, 0xfff8, 'R', 2, "RR (%R)" },
  { 0xa4e0, 0xfff8, 'R', 2, "SLA (%R)" },
  { 0xa5e0, 0xfff8, 'R', 2, "SRA (%R)" },
  { 0xa6e0, 0xfff8, 'R', 2, "SLL (%R)" },
  { 0xa7e0, 0xfff8, 'R', 2, "SRL (%R)" },

  { 0x20e8, 0xf8f8, 'R', 2, "LD (%R),%p" },
  { 0x40e8, 0xf8f8, 'R', 2, "LD (%R),%s" },
  
  { 0xc0e8, 0xf0f8, 'R', 2, "JP %c$R" },
  { 0xd0e8, 0xf0f8, 'R', 2, "CALL %c%R" },

  { 0x12f8, 0xfff8, 'g', 2, "MUL HL,%r" },
  { 0x13f8, 0xfff8, 'g', 2, "DIV HL,%r" },
  { 0x14f8, 0xf8f8, 'g', 2, "ADD %i,%R" },
  { 0x18f8, 0xf8f8, 'g', 2, "TSET %b,%r" },
  { 0x30f8, 0xf8f8, 'g', 2, "LD %p,%r" },
  { 0x38f8, 0xf8f8, 'g', 2, "LD %s,%R" },
  { 0x60f8, 0xfff8, 'g', 2, "ADD A,%r" },
  { 0x61f8, 0xfff8, 'g', 2, "ADC A,%r" },
  { 0x62f8, 0xfff8, 'g', 2, "SUB A,%r" },
  { 0x63f8, 0xfff8, 'g', 2, "SBC A,%r" },
  { 0x64f8, 0xfff8, 'g', 2, "AND A,%r" },
  { 0x65f8, 0xfff8, 'g', 2, "XOR A,%r" },
  { 0x66f8, 0xfff8, 'g', 2, "OR A,%r" },
  { 0x67f8, 0xfff8, 'g', 2, "CP A,%r" },
  { 0x70f8, 0xfff8, 'g', 2, "ADD HL,%R" },
  { 0x71f8, 0xfff8, 'g', 2, "ADC HL,%R" },
  { 0x72f8, 0xfff8, 'g', 2, "SUB HL,%R" },
  { 0x73f8, 0xfff8, 'g', 2, "SBC HL,%R" },
  { 0x74f8, 0xfff8, 'g', 2, "AND HL,%R" },
  { 0x75f8, 0xfff8, 'g', 2, "XOR HL,%R" },
  { 0x76f8, 0xfff8, 'g', 2, "OR HL,%R" },
  { 0x77f8, 0xfff8, 'g', 2, "CP HL,%R" },
  { 0xA0f8, 0xfff8, 'g', 2, "RLC %r" },
  { 0xA1f8, 0xfff8, 'g', 2, "RRC %r" },
  { 0xA2f8, 0xfff8, 'g', 2, "RL %r" },
  { 0xA3f8, 0xfff8, 'g', 2, "RR %r" },
  { 0xA4f8, 0xfff8, 'g', 2, "SLA %r" },
  { 0xA5f8, 0xfff8, 'g', 2, "SRA %r" },
  { 0xA6f8, 0xfff8, 'g', 2, "SLL %r" },
  { 0xA7f8, 0xfff8, 'g', 2, "SRL %r" },
  { 0xA8f8, 0xf8f8, 'g', 2, "BIT %b,%r" },
  { 0xB0f8, 0xf8f8, 'g', 2, "RES %b,%r" },
  { 0xB8f8, 0xf8f8, 'g', 2, "SET %b,%r" },

  { 0x1000e7, 0xff00ff, 'n', 3, "RLD (0xff%n)" },
  { 0x1100e7, 0xff00ff, 'n', 3, "RRD (0xff%n)" },
  { 0x1200e7, 0xff00ff, 'n', 3, "MUL HL,(0xff%n)" },
  { 0x1300e7, 0xff00ff, 'n', 3, "DIV HL,(0xff%n)" },
  { 0x1400e7, 0xfc00ff, 'n', 3, "ADD %j,(0xff%n)" },
  { 0x1800e7, 0xf800ff, 'n', 3, "TSET %B,(0xff%n)" },
  { 0x2800e7, 0xf800ff, 'n', 3, "LD %t,(0xff%n)" },
  { 0x4800e7, 0xf800ff, 'n', 3, "LD %u,(0xff%n)" },
  { 0xA000e7, 0xff00ff, 'n', 3, "RLC (0xff%n)" },
  { 0xA100e7, 0xff00ff, 'n', 3, "RRC (0xff%n)" },
  { 0xA200e7, 0xff00ff, 'n', 3, "RL (0xff%n)" },
  { 0xA300e7, 0xff00ff, 'n', 3, "RR (0xff%n)" },
  { 0xA400e7, 0xff00ff, 'n', 3, "SLA (0xff%n)" },
  { 0xA500e7, 0xff00ff, 'n', 3, "SRA (0xff%n)" },
  { 0xA600e7, 0xff00ff, 'n', 3, "SLL (0xff%n)" },
  { 0xA700e7, 0xff00ff, 'n', 3, "SRL (0xff%n)" },

  { 0, 0, ' ', 0, NULL }
};

//	    case 'r': /*  r in 1st byte */ s+= regname_r(c); break;
//	    case 'p': /*  r in 2nd byte */ s+= regname_r(c>>8); break;
//	    case 't': /*  r in 3rd byte */ s+= regname_r(c>>16); break;
//	    case 'R': /* rr in 1st byte */ s+= regname_R(c); break;
//	    case 's': /* rr in 2nd byte */ s+= regname_R(c>>8); break;
//	    case 'u': /* rr in 3rd byte */ s+= regname_R(c>>16); break;
//	    case 'Q': /* qq in 1st byte */ s+= regname_Q(c); break;
//	    case 'I': /* ix in 1st byte */ s+= regname_i(c); break;
//	    case 'i': /* ix in 2nd byte */ s+= regname_i(c>>8); break;
//	    case 'j': /* ix in 3rd byte */ s+= regname_i(c>>16); break;
//	    case 'b': /*  b in 2nd byte */ s+= bitname(c>>8); break;
//	    case 'B': /*  b in 3rd byte */ s+= bitname(c>>16); break;
//	    case 'c': /* cc in 2nd byte */ s+= condname_cc(c>>8); break; // with ,
//	    case 'C': /* cc in 2nd byte */ s+= condname_C(c>>8); break; // without ,
//	    case 'n': /*  n in 2nd byte */ snprintf(l,19,"%02x",(int)(c>>8));s+= l; break;

/* End of tlcs.src/glob.cc */
