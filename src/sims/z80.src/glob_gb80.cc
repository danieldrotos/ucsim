/*
 * Disassembly table for LR35902, a Z-80 derivative used
 * by the Gameboy (glob_gb80.cc)
 *
 */
/* Derived from z80 glob.cc by Leland Morrison 2011 */

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
   02111-1307, USA. 
*/
/*@1@*/
#include <stdio.h>

#include "stypes.h"

#define  DISASS_NAME(X)  disass_gb80##X


/* 
%d - signed compl.,byte jump 
%w - 2-byte jump or imm. value
%b - byte imm. value
  */
/*  uint  code, mask;  char  branch;  uchar length;  char  *mnemonic; */

struct dis_entry /*DISASS_NAME()*/disass_gb80 []= {
  { 0x0000, 0x00ff, ' ', 1, "NOP" },
  { 0x0001, 0x00ff, ' ', 3, "LD BC,%w" },
  { 0x0002, 0x00ff, ' ', 1, "LD (BC),A" },
  { 0x0003, 0x00ff, ' ', 1, "INC BC" },
  { 0x0004, 0x00ff, ' ', 1, "INC B" },
  { 0x0005, 0x00ff, ' ', 1, "DEC B" },
  { 0x0006, 0x00ff, ' ', 2, "LD b,%b" },
  { 0x0007, 0x00ff, ' ', 1, "RLCA" },

  { 0x0008, 0x00ff, ' ', 3, "LD (%w),SP" },  // unique to GB80
  { 0x0009, 0x00ff, ' ', 1, "ADD HL,BC" },
  { 0x000a, 0x00ff, ' ', 1, "LD A,(BC)" },
  { 0x000b, 0x00ff, ' ', 1, "DEC BC" },
  { 0x000c, 0x00ff, ' ', 1, "INC C" },
  { 0x000d, 0x00ff, ' ', 1, "DEC C" },
  { 0x000e, 0x00ff, ' ', 2, "LD C,%b" },
  { 0x000f, 0x00ff, ' ', 1, "RRCA" },

#if 1
  { 0x0010, 0x00ff, ' ', 2, "STOP 0" },  // unique to GB80
#else
  { 0x0010, 0x00ff, 'R', 2, "DJNZ %d" },
#endif
  { 0x0011, 0x00ff, ' ', 3, "LD DE,%w" },
  { 0x0012, 0x00ff, ' ', 1, "LD (DE),A" },
  { 0x0013, 0x00ff, ' ', 1, "INC DE" },
  { 0x0014, 0x00ff, ' ', 1, "INC D" },
  { 0x0015, 0x00ff, ' ', 1, "DEC D" },
  { 0x0016, 0x00ff, ' ', 2, "LD D,%b" },
  { 0x0017, 0x00ff, ' ', 1, "RLA" },

  { 0x0018, 0x00ff, 'R', 2, "JR %d" },
  { 0x0019, 0x00ff, ' ', 3, "ADD HL,DE" },
  { 0x001a, 0x00ff, ' ', 1, "LD A,(DE)" },
  { 0x001b, 0x00ff, ' ', 1, "DEC DE" },
  { 0x001c, 0x00ff, ' ', 1, "INC E" },
  { 0x001d, 0x00ff, ' ', 1, "DEC E" },
  { 0x001e, 0x00ff, ' ', 2, "LD E,%b" },
  { 0x001f, 0x00ff, ' ', 1, "RRA" },

  { 0x0020, 0x00ff, 'R', 2, "JR NZ,%d" },
  { 0x0021, 0x00ff, ' ', 3, "LD HL,%w" },
#if 1
  { 0x0022, 0x00ff, ' ', 1, "LD (HL+),A" },
#else
  { 0x0022, 0x00ff, ' ', 1, "LDI (HL),A" },// unique to GB80
#endif
  { 0x0023, 0x00ff, ' ', 1, "INC HL" },
  { 0x0024, 0x00ff, ' ', 1, "INC H" },
  { 0x0025, 0x00ff, ' ', 1, "DEC H" },
  { 0x0026, 0x00ff, ' ', 2, "LD H,%b" },
  { 0x0027, 0x00ff, ' ', 1, "DAA" },

  { 0x0028, 0x00ff, 'R', 2, "JR Z,%d" },
  { 0x0029, 0x00ff, ' ', 1, "ADD HL,HL" },
#if 1
  { 0x002a, 0x00ff, ' ', 1, "LD A,(HL+)" },
#else
  { 0x002a, 0x00ff, ' ', 1, "LDI A,(HL)" },// unique to GB80
#endif
  { 0x002b, 0x00ff, ' ', 1, "DEC HL" },
  { 0x002c, 0x00ff, ' ', 1, "INC L" },
  { 0x002d, 0x00ff, ' ', 1, "DEC L" },
  { 0x002e, 0x00ff, ' ', 2, "LD L, %b" },
  { 0x002f, 0x00ff, ' ', 1, "CPL" },

  { 0x0030, 0x00ff, 'R', 2, "JR NC,%d" },
  { 0x0031, 0x00ff, ' ', 3, "LD SP,%w" },
#if 1
  { 0x0032, 0x00ff, ' ', 1, "LD (HL-),A" },
#else
  { 0x0032, 0x00ff, ' ', 1, "LDD (HL),A" },  // unique to GB80
#endif
  { 0x0033, 0x00ff, ' ', 1, "INC SP" },
  { 0x0034, 0x00ff, ' ', 1, "INC (HL)" },
  { 0x0035, 0x00ff, ' ', 1, "DEC (HL)" },
  { 0x0036, 0x00ff, ' ', 2, "LD (HL),%b" },
  { 0x0037, 0x00ff, ' ', 1, "SCF" },

  { 0x0038, 0x00ff, 'R', 2, "JR C,%d" },
  { 0x0039, 0x00ff, ' ', 1, "ADD HL,SP" },
#if 1
  { 0x003a, 0x00ff, ' ', 1, "LD A,(HL-)" },
#else
  { 0x003a, 0x00ff, ' ', 1, "LDD A,(HL)" },  // unique to GB80
#endif
  { 0x003b, 0x00ff, ' ', 1, "DEC SP" },
  { 0x003c, 0x00ff, ' ', 1, "INC A" },
  { 0x003d, 0x00ff, ' ', 1, "DEC A" },
  { 0x003e, 0x00ff, ' ', 2, "LD A,%b" },
  { 0x003f, 0x00ff, ' ', 1, "CCF" },

  { 0x0040, 0x00ff, ' ', 1, "LD B,B" },
  { 0x0041, 0x00ff, ' ', 1, "LD B,C" },
  { 0x0042, 0x00ff, ' ', 1, "LD B,D" },
  { 0x0043, 0x00ff, ' ', 1, "LD B,E" },
  { 0x0044, 0x00ff, ' ', 1, "LD B,H" },
  { 0x0045, 0x00ff, ' ', 1, "LD B,L" },
  { 0x0046, 0x00ff, ' ', 1, "LD B,(HL)" },
  { 0x0047, 0x00ff, ' ', 1, "LD B,a" },

  { 0x0048, 0x00ff, ' ', 1, "LD C,B" },
  { 0x0049, 0x00ff, ' ', 1, "LD C,C" },
  { 0x004a, 0x00ff, ' ', 1, "LD C,D" },
  { 0x004b, 0x00ff, ' ', 1, "LD C,E" },
  { 0x004c, 0x00ff, ' ', 1, "LD C,H" },
  { 0x004d, 0x00ff, ' ', 1, "LD C,L" },
  { 0x004e, 0x00ff, ' ', 1, "LD C,(HL)" },
  { 0x004f, 0x00ff, ' ', 1, "LD C,A" },

  { 0x0050, 0x00ff, ' ', 1, "LD D,B" },
  { 0x0051, 0x00ff, ' ', 1, "LD D,C" },
  { 0x0052, 0x00ff, ' ', 1, "LD D,D" },
  { 0x0053, 0x00ff, ' ', 1, "LD D,E" },
  { 0x0054, 0x00ff, ' ', 1, "LD D,H" },
  { 0x0055, 0x00ff, ' ', 1, "LD D,L" },
  { 0x0056, 0x00ff, ' ', 1, "LD D,(HL)" },
  { 0x0057, 0x00ff, ' ', 1, "LD D,A" },

  { 0x0058, 0x00ff, ' ', 1, "LD E,B" },
  { 0x0059, 0x00ff, ' ', 1, "LD E,C" },
  { 0x005a, 0x00ff, ' ', 1, "LD E,D" },
  { 0x005b, 0x00ff, ' ', 1, "LD E,E" },
  { 0x005c, 0x00ff, ' ', 1, "LD E,H" },
  { 0x005d, 0x00ff, ' ', 1, "LD E,L" },
  { 0x005e, 0x00ff, ' ', 1, "LD E,(HL)" },
  { 0x005f, 0x00ff, ' ', 1, "LD E,A" },

  { 0x0060, 0x00ff, ' ', 1, "LD H,B" },
  { 0x0061, 0x00ff, ' ', 1, "LD H,C" },
  { 0x0062, 0x00ff, ' ', 1, "LD H,D" },
  { 0x0063, 0x00ff, ' ', 1, "LD H,E" },
  { 0x0064, 0x00ff, ' ', 1, "LD H,H" },
  { 0x0065, 0x00ff, ' ', 1, "LD H,L" },
  { 0x0066, 0x00ff, ' ', 1, "LD H,(HL)" },
  { 0x0067, 0x00ff, ' ', 1, "LD H,A" },

  { 0x0068, 0x00ff, ' ', 1, "LD L,B" },
  { 0x0069, 0x00ff, ' ', 1, "LD L,C" },
  { 0x006a, 0x00ff, ' ', 1, "LD L,D" },
  { 0x006b, 0x00ff, ' ', 1, "LD L,E" },
  { 0x006c, 0x00ff, ' ', 1, "LD L,H" },
  { 0x006d, 0x00ff, ' ', 1, "LD L,L" },
  { 0x006e, 0x00ff, ' ', 1, "LD L,(HL)" },
  { 0x006f, 0x00ff, ' ', 1, "LD L,A" },

  { 0x0070, 0x00ff, ' ', 1, "LD (HL),B" },
  { 0x0071, 0x00ff, ' ', 1, "LD (HL),C" },
  { 0x0072, 0x00ff, ' ', 1, "LD (HL),D" },
  { 0x0073, 0x00ff, ' ', 1, "LD (HL),E" },
  { 0x0074, 0x00ff, ' ', 1, "LD (HL),H" },
  { 0x0075, 0x00ff, ' ', 1, "LD (HL),L" },
  { 0x0076, 0x00ff, ' ', 1, "HALT" },
  { 0x0077, 0x00ff, ' ', 1, "LD (HL),A" },

  { 0x0078, 0x00ff, ' ', 1, "LD A,B" },
  { 0x0079, 0x00ff, ' ', 1, "LD A,C" },
  { 0x007a, 0x00ff, ' ', 1, "LD A,D" },
  { 0x007b, 0x00ff, ' ', 1, "LD A,E" },
  { 0x007c, 0x00ff, ' ', 1, "LD A,H" },
  { 0x007d, 0x00ff, ' ', 1, "LD A,L" },
  { 0x007e, 0x00ff, ' ', 1, "LD A,(HL)" },
  { 0x007f, 0x00ff, ' ', 1, "LD A,A" },

  { 0x0080, 0x00ff, ' ', 1, "ADD A,B" },
  { 0x0081, 0x00ff, ' ', 1, "ADD A,C" },
  { 0x0082, 0x00ff, ' ', 1, "ADD A,D" },
  { 0x0083, 0x00ff, ' ', 1, "ADD A,E" },
  { 0x0084, 0x00ff, ' ', 1, "ADD A,H" },
  { 0x0085, 0x00ff, ' ', 1, "ADD A,L" },
  { 0x0086, 0x00ff, ' ', 1, "ADD A,(HL)" },
  { 0x0087, 0x00ff, ' ', 1, "ADD A,A" },

  { 0x0088, 0x00ff, ' ', 1, "ADC A,B" },
  { 0x0089, 0x00ff, ' ', 1, "ADC A,C" },
  { 0x008a, 0x00ff, ' ', 1, "ADC A,D" },
  { 0x008b, 0x00ff, ' ', 1, "ADC A,E" },
  { 0x008c, 0x00ff, ' ', 1, "ADC A,H" },
  { 0x008d, 0x00ff, ' ', 1, "ADC A,L" },
  { 0x008e, 0x00ff, ' ', 1, "ADC A,(HL)" },
  { 0x008f, 0x00ff, ' ', 1, "ADC A,A" },

  { 0x0090, 0x00ff, ' ', 1, "SUB A,B"},
  { 0x0091, 0x00ff, ' ', 1, "SUB A,C"},
  { 0x0092, 0x00ff, ' ', 1, "SUB A,D"},
  { 0x0093, 0x00ff, ' ', 1, "SUB A,E"},
  { 0x0094, 0x00ff, ' ', 1, "SUB A,H"},
  { 0x0095, 0x00ff, ' ', 1, "SUB A,L"},
  { 0x0096, 0x00ff, ' ', 1, "SUB A,(HL)"},
  { 0x0097, 0x00ff, ' ', 1, "SUB A,A"},

  { 0x0098, 0x00ff, ' ', 1, "SBC A,B" },
  { 0x0099, 0x00ff, ' ', 1, "SBC A,C" },
  { 0x009a, 0x00ff, ' ', 1, "SBC A,D" },
  { 0x009b, 0x00ff, ' ', 1, "SBC A,E" },
  { 0x009c, 0x00ff, ' ', 1, "SBC A,H" },
  { 0x009d, 0x00ff, ' ', 1, "SBC A,L" },
  { 0x009e, 0x00ff, ' ', 1, "SBC A,(HL)" },
  { 0x009f, 0x00ff, ' ', 1, "SBC A,A" },

  { 0x00a0, 0x00ff, ' ', 1, "AND B" },
  { 0x00a1, 0x00ff, ' ', 1, "AND C" },
  { 0x00a2, 0x00ff, ' ', 1, "AND D" },
  { 0x00a3, 0x00ff, ' ', 1, "AND E" },
  { 0x00a4, 0x00ff, ' ', 1, "AND H" },
  { 0x00a5, 0x00ff, ' ', 1, "AND L" },
  { 0x00a6, 0x00ff, ' ', 1, "AND (HL)" },
  { 0x00a7, 0x00ff, ' ', 1, "AND A" },

  { 0x00a8, 0x00ff, ' ', 1, "XOR B" },
  { 0x00a9, 0x00ff, ' ', 1, "XOR C" },
  { 0x00aa, 0x00ff, ' ', 1, "XOR D" },
  { 0x00ab, 0x00ff, ' ', 1, "XOR E" },
  { 0x00ac, 0x00ff, ' ', 1, "XOR H" },
  { 0x00ad, 0x00ff, ' ', 1, "XOR L" },
  { 0x00ae, 0x00ff, ' ', 1, "XOR (HL)" },
  { 0x00af, 0x00ff, ' ', 1, "XOR A" },

  { 0x00b0, 0x00ff, ' ', 1, "OR B" },
  { 0x00b1, 0x00ff, ' ', 1, "OR C" },
  { 0x00b2, 0x00ff, ' ', 1, "OR D" },
  { 0x00b3, 0x00ff, ' ', 1, "OR E" },
  { 0x00b4, 0x00ff, ' ', 1, "OR H" },
  { 0x00b5, 0x00ff, ' ', 1, "OR L" },
  { 0x00b6, 0x00ff, ' ', 1, "OR (HL)" },
  { 0x00b7, 0x00ff, ' ', 1, "OR A" },

  { 0x00b8, 0x00ff, ' ', 1, "CP B" },
  { 0x00b9, 0x00ff, ' ', 1, "CP C" },
  { 0x00ba, 0x00ff, ' ', 1, "CP D" },
  { 0x00bb, 0x00ff, ' ', 1, "CP E" },
  { 0x00bc, 0x00ff, ' ', 1, "CP H" },
  { 0x00bd, 0x00ff, ' ', 1, "CP L" },
  { 0x00be, 0x00ff, ' ', 1, "CP (HL)" },
  { 0x00bf, 0x00ff, ' ', 1, "CP A" },

  { 0x00c0, 0x00ff, ' ', 1, "RET NZ" },
  { 0x00c1, 0x00ff, ' ', 1, "POP BC" },
  { 0x00c2, 0x00ff, 'A', 3, "JP NZ, %w" },
  { 0x00c3, 0x00ff, 'A', 3, "JP %w" },
  { 0x00c4, 0x00ff, 'l', 3, "CALL NZ,%w" },
  { 0x00c5, 0x00ff, ' ', 1, "PUSH BC" },
  { 0x00c6, 0x00ff, ' ', 2, "ADD A,%b" },
  { 0x00c7, 0x00ff, ' ', 1, "RST 0" },

  { 0x00c8, 0x00ff, ' ', 1, "RET Z" },
  { 0x00c9, 0x00ff, ' ', 1, "RET" },
  { 0x00ca, 0x00ff, 'A', 3, "JP Z,%w" },
  { 0x00cb, 0x00ff, ' ', 2, "?cb?" }, /* ESC code to lots of op-codes, all 2-byte */

  { 0x00cc, 0x00ff, 'l', 3, "CALL Z,%w" },
  { 0x00cd, 0x00ff, 'l', 3, "CALL %w" },
  { 0x00ce, 0x00ff, ' ', 2, "ADC A,%b" },
  { 0x00cf, 0x00ff, ' ', 1, "RST 8" },
  
  { 0x00d0, 0x00ff, ' ', 1, "RET NC" },
  { 0x00d1, 0x00ff, ' ', 1, "POP DE" },
  { 0x00d2, 0x00ff, 'A', 3, "JP NC,%w" },
  { 0x00d3, 0x00ff, ' ', 2, "Illegal Op" },  // in/out do not exist on GB80
  { 0x00d4, 0x00ff, 'l', 3, "CALL NC,%w" },
  { 0x00d5, 0x00ff, ' ', 1, "PUSH DE" },
  { 0x00d6, 0x00ff, ' ', 2, "SUB %b" },
  { 0x00d7, 0x00ff, ' ', 1, "RST 10H" },

  { 0x00d8, 0x00ff, ' ', 1, "RET C" },
  { 0x00d9, 0x00ff, ' ', 1, "RETI" },  // unique to GB80
  { 0x00da, 0x00ff, 'A', 3, "JP C,%w" },
  { 0x00db, 0x00ff, ' ', 2, "Illegal Op" },  // in/out do not exist on GB80
  { 0x00dc, 0x00ff, 'l', 3, "CALL C,%w" },
  { 0x00dd, 0x00ff, ' ', 2, "Illegal Op" },  /* 0xdd - ESC codes,about 284, vary lengths, IX centric */
  { 0x00de, 0x00ff, ' ', 2, "SBC A,%b" },
  { 0x00df, 0x00ff, ' ', 1, "RST 18H" },

  { 0x00e0, 0x00ff, ' ', 2, "LDH (0xFF00+%b),A" },  // unique to GB80
  { 0x00e1, 0x00ff, ' ', 1, "POP HL" },
  { 0x00e2, 0x00ff, 'A', 2, "LD (0xFF00+C),A" },  // unique to GB80
  { 0x00e3, 0x00ff, ' ', 1, "Illegal Op" },
  { 0x00e4, 0x00ff, 'l', 1, "Illegal Op" },
  { 0x00e5, 0x00ff, ' ', 1, "PUSH HL" },
  { 0x00e6, 0x00ff, ' ', 2, "AND %b" },
  { 0x00e7, 0x00ff, ' ', 1, "RST 20H" },

  { 0x00e8, 0x00ff, ' ', 2, "ADD SP,%d" },  // unique to GB80
  { 0x00e9, 0x00ff, 'A', 1, "JP (HL)" },
  { 0x00ea, 0x00ff, ' ', 3, "LD (%w),A" },  // unique to GB80
  { 0x00eb, 0x00ff, ' ', 1, "Illegal Op" },
  { 0x00ec, 0x00ff, 'l', 1, "Illegal Op" },
  { 0x00ed, 0x00ff, ' ', 1, "Illegal Op" },
  { 0x00ee, 0x00ff, ' ', 2, "XOR %b" },
  { 0x00ef, 0x00ff, ' ', 1, "RST 28H" },

  { 0x00f0, 0x00ff, ' ', 2, "LDH A,(0xFF00+%b)" },  // unique to GB80
  { 0x00f1, 0x00ff, ' ', 1, "POP AF" },
  { 0x00f2, 0x00ff, ' ', 2, "LD A,(0xFF00+C)" },  // unique to GB80
  { 0x00f3, 0x00ff, ' ', 1, "DI" },
  { 0x00f4, 0x00ff, 'l', 3, "Illegal Op" },
  { 0x00f5, 0x00ff, ' ', 1, "PUSH AF" },
  { 0x00f6, 0x00ff, ' ', 2, "OR %b" },
  { 0x00f7, 0x00ff, ' ', 1, "RST 30H" },

  { 0x00f8, 0x00ff, ' ', 2, "LD HL,SP+%d" },  // unique to GB80
  { 0x00f9, 0x00ff, ' ', 1, "LD SP,HL" },
  { 0x00fa, 0x00ff, ' ', 3, "LD A,(%w)" },  // unique to GB80
  { 0x00fb, 0x00ff, ' ', 1, "EI" },
  { 0x00fc, 0x00ff, 'l', 1, "Illegal Op" },
  { 0x00fd, 0x00ff, ' ', 1, "Illegal Op" },
  { 0x00fe, 0x00ff, ' ', 2, "CP %b" },
  { 0x00ff, 0x00ff, ' ', 1, "RST 38H" },

  { 0, 0, 0, 0, NULL }
};


struct dis_entry DISASS_NAME(_cb)[]= {
  { 0x0000, 0x00ff, ' ', 1, "RLC B" },
  { 0x0001, 0x00ff, ' ', 1, "RLC C" },
  { 0x0002, 0x00ff, ' ', 1, "RLC D" },
  { 0x0003, 0x00ff, ' ', 1, "RLC E" },
  { 0x0004, 0x00ff, ' ', 1, "RLC H" },
  { 0x0005, 0x00ff, ' ', 1, "RLC L" },
  { 0x0006, 0x00ff, ' ', 1, "RLC (HL)" },
  { 0x0007, 0x00ff, ' ', 1, "RLC A" },
  { 0x0008, 0x00ff, ' ', 1, "RRC B" },
  { 0x0009, 0x00ff, ' ', 1, "RRC C" },
  { 0x000A, 0x00ff, ' ', 1, "RRC D" },
  { 0x000B, 0x00ff, ' ', 1, "RRC E" },
  { 0x000C, 0x00ff, ' ', 1, "RRC H" },
  { 0x000D, 0x00ff, ' ', 1, "RRC L" },
  { 0x000E, 0x00ff, ' ', 1, "RRC (HL)" },
  { 0x000F, 0x00ff, ' ', 1, "RRC A" },
  { 0x0010, 0x00ff, ' ', 1, "RL B" },
  { 0x0011, 0x00ff, ' ', 1, "RL C" },
  { 0x0012, 0x00ff, ' ', 1, "RL D" },
  { 0x0013, 0x00ff, ' ', 1, "RL E" },
  { 0x0014, 0x00ff, ' ', 1, "RL H" },
  { 0x0015, 0x00ff, ' ', 1, "RL L" },
  { 0x0016, 0x00ff, ' ', 1, "RL (HL)" },
  { 0x0017, 0x00ff, ' ', 1, "RL A" },
  { 0x0018, 0x00ff, ' ', 1, "RR B" },
  { 0x0019, 0x00ff, ' ', 1, "RR C" },
  { 0x001A, 0x00ff, ' ', 1, "RR D" },
  { 0x001B, 0x00ff, ' ', 1, "RR E" },
  { 0x001C, 0x00ff, ' ', 1, "RR H" },
  { 0x001D, 0x00ff, ' ', 1, "RR L" },
  { 0x001E, 0x00ff, ' ', 1, "RR (HL)" },
  { 0x001F, 0x00ff, ' ', 1, "RR A" },
  { 0x0020, 0x00ff, ' ', 1, "SLA B" },
  { 0x0021, 0x00ff, ' ', 1, "SLA C" },
  { 0x0022, 0x00ff, ' ', 1, "SLA D" },
  { 0x0023, 0x00ff, ' ', 1, "SLA E" },
  { 0x0024, 0x00ff, ' ', 1, "SLA H" },
  { 0x0025, 0x00ff, ' ', 1, "SLA L" },
  { 0x0026, 0x00ff, ' ', 1, "SLA (HL)" },
  { 0x0027, 0x00ff, ' ', 1, "SLA A" },
  { 0x0028, 0x00ff, ' ', 1, "SRA B" },
  { 0x0029, 0x00ff, ' ', 1, "SRA C" },
  { 0x002A, 0x00ff, ' ', 1, "SRA D" },
  { 0x002B, 0x00ff, ' ', 1, "SRA E" },
  { 0x002C, 0x00ff, ' ', 1, "SRA H" },
  { 0x002D, 0x00ff, ' ', 1, "SRA L" },
  { 0x002E, 0x00ff, ' ', 1, "SRA (HL)" },
  { 0x002F, 0x00ff, ' ', 1, "SRA A" },
  { 0x0030, 0x00ff, ' ', 1, "SWAP B" },
  { 0x0031, 0x00ff, ' ', 1, "SWAP C" },
  { 0x0032, 0x00ff, ' ', 1, "SWAP D" },
  { 0x0033, 0x00ff, ' ', 1, "SWAP E" },
  { 0x0034, 0x00ff, ' ', 1, "SWAP H" },
  { 0x0035, 0x00ff, ' ', 1, "SWAP L" },
  { 0x0036, 0x00ff, ' ', 1, "SWAP (HL)" },
  { 0x0037, 0x00ff, ' ', 1, "SWAP A" },
  { 0x0038, 0x00ff, ' ', 1, "SRL B" },
  { 0x0039, 0x00ff, ' ', 1, "SRL C" },
  { 0x003A, 0x00ff, ' ', 1, "SRL D" },
  { 0x003B, 0x00ff, ' ', 1, "SRL E" },
  { 0x003C, 0x00ff, ' ', 1, "SRL H" },
  { 0x003D, 0x00ff, ' ', 1, "SRL L" },
  { 0x003E, 0x00ff, ' ', 1, "SRL (HL)" },
  { 0x003F, 0x00ff, ' ', 1, "SRL A" },
  { 0x0040, 0x00ff, ' ', 1, "BIT 0,B" },
  { 0x0041, 0x00ff, ' ', 1, "BIT 0,C" },
  { 0x0042, 0x00ff, ' ', 1, "BIT 0,D" },
  { 0x0043, 0x00ff, ' ', 1, "BIT 0,E" },
  { 0x0044, 0x00ff, ' ', 1, "BIT 0,H" },
  { 0x0045, 0x00ff, ' ', 1, "BIT 0,L" },
  { 0x0046, 0x00ff, ' ', 1, "BIT 0,(HL)" },
  { 0x0047, 0x00ff, ' ', 1, "BIT 0,A" },
  { 0x0048, 0x00ff, ' ', 1, "BIT 1,B" },
  { 0x0049, 0x00ff, ' ', 1, "BIT 1,C" },
  { 0x004A, 0x00ff, ' ', 1, "BIT 1,D" },
  { 0x004B, 0x00ff, ' ', 1, "BIT 1,E" },
  { 0x004C, 0x00ff, ' ', 1, "BIT 1,H" },
  { 0x004D, 0x00ff, ' ', 1, "BIT 1,L" },
  { 0x004E, 0x00ff, ' ', 1, "BIT 1,(HL)" },
  { 0x004F, 0x00ff, ' ', 1, "BIT 1,A" },
  { 0x0050, 0x00ff, ' ', 1, "BIT 2,B" },
  { 0x0051, 0x00ff, ' ', 1, "BIT 2,C" },
  { 0x0052, 0x00ff, ' ', 1, "BIT 2,D" },
  { 0x0053, 0x00ff, ' ', 1, "BIT 2,E" },
  { 0x0054, 0x00ff, ' ', 1, "BIT 2,H" },
  { 0x0055, 0x00ff, ' ', 1, "BIT 2,L" },
  { 0x0056, 0x00ff, ' ', 1, "BIT 2,(HL)" },
  { 0x0057, 0x00ff, ' ', 1, "BIT 2,A" },
  { 0x0058, 0x00ff, ' ', 1, "BIT 3,B" },
  { 0x0059, 0x00ff, ' ', 1, "BIT 3,C" },
  { 0x005A, 0x00ff, ' ', 1, "BIT 3,D" },
  { 0x005B, 0x00ff, ' ', 1, "BIT 3,E" },
  { 0x005C, 0x00ff, ' ', 1, "BIT 3,H" },
  { 0x005D, 0x00ff, ' ', 1, "BIT 3,L" },
  { 0x005E, 0x00ff, ' ', 1, "BIT 3,(HL)" },
  { 0x005F, 0x00ff, ' ', 1, "BIT 3,A" },
  { 0x0060, 0x00ff, ' ', 1, "BIT 4,B" },
  { 0x0061, 0x00ff, ' ', 1, "BIT 4,C" },
  { 0x0062, 0x00ff, ' ', 1, "BIT 4,D" },
  { 0x0063, 0x00ff, ' ', 1, "BIT 4,E" },
  { 0x0064, 0x00ff, ' ', 1, "BIT 4,H" },
  { 0x0065, 0x00ff, ' ', 1, "BIT 4,L" },
  { 0x0066, 0x00ff, ' ', 1, "BIT 4,(HL)" },
  { 0x0067, 0x00ff, ' ', 1, "BIT 4,A" },
  { 0x0068, 0x00ff, ' ', 1, "BIT 5,B" },
  { 0x0069, 0x00ff, ' ', 1, "BIT 5,C" },
  { 0x006A, 0x00ff, ' ', 1, "BIT 5,D" },
  { 0x006B, 0x00ff, ' ', 1, "BIT 5,E" },
  { 0x006C, 0x00ff, ' ', 1, "BIT 5,H" },
  { 0x006D, 0x00ff, ' ', 1, "BIT 5,L" },
  { 0x006E, 0x00ff, ' ', 1, "BIT 5,(HL)" },
  { 0x006F, 0x00ff, ' ', 1, "BIT 5,A" },
  { 0x0070, 0x00ff, ' ', 1, "BIT 6,B" },
  { 0x0071, 0x00ff, ' ', 1, "BIT 6,C" },
  { 0x0072, 0x00ff, ' ', 1, "BIT 6,D" },
  { 0x0073, 0x00ff, ' ', 1, "BIT 6,E" },
  { 0x0074, 0x00ff, ' ', 1, "BIT 6,H" },
  { 0x0075, 0x00ff, ' ', 1, "BIT 6,L" },
  { 0x0076, 0x00ff, ' ', 1, "BIT 6,(HL)" },
  { 0x0077, 0x00ff, ' ', 1, "BIT 6,A" },
  { 0x0078, 0x00ff, ' ', 1, "BIT 7,B" },
  { 0x0079, 0x00ff, ' ', 1, "BIT 7,C" },
  { 0x007A, 0x00ff, ' ', 1, "BIT 7,D" },
  { 0x007B, 0x00ff, ' ', 1, "BIT 7,E" },
  { 0x007C, 0x00ff, ' ', 1, "BIT 7,H" },
  { 0x007D, 0x00ff, ' ', 1, "BIT 7,L" },
  { 0x007E, 0x00ff, ' ', 1, "BIT 7,(HL)" },
  { 0x007F, 0x00ff, ' ', 1, "BIT 7,A" },
  { 0x0080, 0x00ff, ' ', 1, "RES 0,B" },
  { 0x0081, 0x00ff, ' ', 1, "RES 0,C" },
  { 0x0082, 0x00ff, ' ', 1, "RES 0,D" },
  { 0x0083, 0x00ff, ' ', 1, "RES 0,E" },
  { 0x0084, 0x00ff, ' ', 1, "RES 0,H" },
  { 0x0085, 0x00ff, ' ', 1, "RES 0,L" },
  { 0x0086, 0x00ff, ' ', 1, "RES 0,(HL)" },
  { 0x0087, 0x00ff, ' ', 1, "RES 0,A" },
  { 0x0088, 0x00ff, ' ', 1, "RES 1,B" },
  { 0x0089, 0x00ff, ' ', 1, "RES 1,C" },
  { 0x008A, 0x00ff, ' ', 1, "RES 1,D" },
  { 0x008B, 0x00ff, ' ', 1, "RES 1,E" },
  { 0x008C, 0x00ff, ' ', 1, "RES 1,H" },
  { 0x008D, 0x00ff, ' ', 1, "RES 1,L" },
  { 0x008E, 0x00ff, ' ', 1, "RES 1,(HL)" },
  { 0x008F, 0x00ff, ' ', 1, "RES 1,A" },
  { 0x0090, 0x00ff, ' ', 1, "RES 2,B" },
  { 0x0091, 0x00ff, ' ', 1, "RES 2,C" },
  { 0x0092, 0x00ff, ' ', 1, "RES 2,D" },
  { 0x0093, 0x00ff, ' ', 1, "RES 2,E" },
  { 0x0094, 0x00ff, ' ', 1, "RES 2,H" },
  { 0x0095, 0x00ff, ' ', 1, "RES 2,L" },
  { 0x0096, 0x00ff, ' ', 1, "RES 2,(HL)" },
  { 0x0097, 0x00ff, ' ', 1, "RES 2,A" },
  { 0x0098, 0x00ff, ' ', 1, "RES 3,B" },
  { 0x0099, 0x00ff, ' ', 1, "RES 3,C" },
  { 0x009A, 0x00ff, ' ', 1, "RES 3,D" },
  { 0x009B, 0x00ff, ' ', 1, "RES 3,E" },
  { 0x009C, 0x00ff, ' ', 1, "RES 3,H" },
  { 0x009D, 0x00ff, ' ', 1, "RES 3,L" },
  { 0x009E, 0x00ff, ' ', 1, "RES 3,(HL)" },
  { 0x009F, 0x00ff, ' ', 1, "RES 3,A" },
  { 0x00A0, 0x00ff, ' ', 1, "RES 4,B" },
  { 0x00A1, 0x00ff, ' ', 1, "RES 4,C" },
  { 0x00A2, 0x00ff, ' ', 1, "RES 4,D" },
  { 0x00A3, 0x00ff, ' ', 1, "RES 4,E" },
  { 0x00A4, 0x00ff, ' ', 1, "RES 4,H" },
  { 0x00A5, 0x00ff, ' ', 1, "RES 4,L" },
  { 0x00A6, 0x00ff, ' ', 1, "RES 4,(HL)" },
  { 0x00A7, 0x00ff, ' ', 1, "RES 4,A" },
  { 0x00A8, 0x00ff, ' ', 1, "RES 5,B" },
  { 0x00A9, 0x00ff, ' ', 1, "RES 5,C" },
  { 0x00AA, 0x00ff, ' ', 1, "RES 5,D" },
  { 0x00AB, 0x00ff, ' ', 1, "RES 5,E" },
  { 0x00AC, 0x00ff, ' ', 1, "RES 5,H" },
  { 0x00AD, 0x00ff, ' ', 1, "RES 5,L" },
  { 0x00AE, 0x00ff, ' ', 1, "RES 5,(HL)" },
  { 0x00AF, 0x00ff, ' ', 1, "RES 5,A" },
  { 0x00B0, 0x00ff, ' ', 1, "RES 6,B" },
  { 0x00B1, 0x00ff, ' ', 1, "RES 6,C" },
  { 0x00B2, 0x00ff, ' ', 1, "RES 6,D" },
  { 0x00B3, 0x00ff, ' ', 1, "RES 6,E" },
  { 0x00B4, 0x00ff, ' ', 1, "RES 6,H" },
  { 0x00B5, 0x00ff, ' ', 1, "RES 6,L" },
  { 0x00B6, 0x00ff, ' ', 1, "RES 6,(HL)" },
  { 0x00B7, 0x00ff, ' ', 1, "RES 6,A" },
  { 0x00B8, 0x00ff, ' ', 1, "RES 7,B" },
  { 0x00B9, 0x00ff, ' ', 1, "RES 7,C" },
  { 0x00BA, 0x00ff, ' ', 1, "RES 7,D" },
  { 0x00BB, 0x00ff, ' ', 1, "RES 7,E" },
  { 0x00BC, 0x00ff, ' ', 1, "RES 7,H" },
  { 0x00BD, 0x00ff, ' ', 1, "RES 7,L" },
  { 0x00BE, 0x00ff, ' ', 1, "RES 7,(HL)" },
  { 0x00BF, 0x00ff, ' ', 1, "RES 7,A" },
  { 0x00C0, 0x00ff, ' ', 1, "SET 0,B" },
  { 0x00C1, 0x00ff, ' ', 1, "SET 0,C" },
  { 0x00C2, 0x00ff, ' ', 1, "SET 0,D" },
  { 0x00C3, 0x00ff, ' ', 1, "SET 0,E" },
  { 0x00C4, 0x00ff, ' ', 1, "SET 0,H" },
  { 0x00C5, 0x00ff, ' ', 1, "SET 0,L" },
  { 0x00C6, 0x00ff, ' ', 1, "SET 0,(HL)" },
  { 0x00C7, 0x00ff, ' ', 1, "SET 0,A" },
  { 0x00C8, 0x00ff, ' ', 1, "SET 1,B" },
  { 0x00C9, 0x00ff, ' ', 1, "SET 1,C" },
  { 0x00CA, 0x00ff, ' ', 1, "SET 1,D" },
  { 0x00CB, 0x00ff, ' ', 1, "SET 1,E" },
  { 0x00CC, 0x00ff, ' ', 1, "SET 1,H" },
  { 0x00CD, 0x00ff, ' ', 1, "SET 1,L" },
  { 0x00CE, 0x00ff, ' ', 1, "SET 1,(HL)" },
  { 0x00CF, 0x00ff, ' ', 1, "SET 1,A" },
  { 0x00D0, 0x00ff, ' ', 1, "SET 2,B" },
  { 0x00D1, 0x00ff, ' ', 1, "SET 2,C" },
  { 0x00D2, 0x00ff, ' ', 1, "SET 2,D" },
  { 0x00D3, 0x00ff, ' ', 1, "SET 2,E" },
  { 0x00D4, 0x00ff, ' ', 1, "SET 2,H" },
  { 0x00D5, 0x00ff, ' ', 1, "SET 2,L" },
  { 0x00D6, 0x00ff, ' ', 1, "SET 2,(HL)" },
  { 0x00D7, 0x00ff, ' ', 1, "SET 2,A" },
  { 0x00D8, 0x00ff, ' ', 1, "SET 3,B" },
  { 0x00D9, 0x00ff, ' ', 1, "SET 3,C" },
  { 0x00DA, 0x00ff, ' ', 1, "SET 3,D" },
  { 0x00DB, 0x00ff, ' ', 1, "SET 3,E" },
  { 0x00DC, 0x00ff, ' ', 1, "SET 3,H" },
  { 0x00DD, 0x00ff, ' ', 1, "SET 3,L" },
  { 0x00DE, 0x00ff, ' ', 1, "SET 3,(HL)" },
  { 0x00DF, 0x00ff, ' ', 1, "SET 3,A" },
  { 0x00E0, 0x00ff, ' ', 1, "SET 4,B" },
  { 0x00E1, 0x00ff, ' ', 1, "SET 4,C" },
  { 0x00E2, 0x00ff, ' ', 1, "SET 4,D" },
  { 0x00E3, 0x00ff, ' ', 1, "SET 4,E" },
  { 0x00E4, 0x00ff, ' ', 1, "SET 4,H" },
  { 0x00E5, 0x00ff, ' ', 1, "SET 4,L" },
  { 0x00E6, 0x00ff, ' ', 1, "SET 4,(HL)" },
  { 0x00E7, 0x00ff, ' ', 1, "SET 4,A" },
  { 0x00E8, 0x00ff, ' ', 1, "SET 5,B" },
  { 0x00E9, 0x00ff, ' ', 1, "SET 5,C" },
  { 0x00EA, 0x00ff, ' ', 1, "SET 5,D" },
  { 0x00EB, 0x00ff, ' ', 1, "SET 5,E" },
  { 0x00EC, 0x00ff, ' ', 1, "SET 5,H" },
  { 0x00ED, 0x00ff, ' ', 1, "SET 5,L" },
  { 0x00EE, 0x00ff, ' ', 1, "SET 5,(HL)" },
  { 0x00EF, 0x00ff, ' ', 1, "SET 5,A" },
  { 0x00F0, 0x00ff, ' ', 1, "SET 6,B" },
  { 0x00F1, 0x00ff, ' ', 1, "SET 6,C" },
  { 0x00F2, 0x00ff, ' ', 1, "SET 6,D" },
  { 0x00F3, 0x00ff, ' ', 1, "SET 6,E" },
  { 0x00F4, 0x00ff, ' ', 1, "SET 6,H" },
  { 0x00F5, 0x00ff, ' ', 1, "SET 6,L" },
  { 0x00F6, 0x00ff, ' ', 1, "SET 6,(HL)" },
  { 0x00F7, 0x00ff, ' ', 1, "SET 6,A" },
  { 0x00F8, 0x00ff, ' ', 1, "SET 7,B" },
  { 0x00F9, 0x00ff, ' ', 1, "SET 7,C" },
  { 0x00FA, 0x00ff, ' ', 1, "SET 7,D" },
  { 0x00FB, 0x00ff, ' ', 1, "SET 7,E" },
  { 0x00FC, 0x00ff, ' ', 1, "SET 7,H" },
  { 0x00FD, 0x00ff, ' ', 1, "SET 7,L" },
  { 0x00FE, 0x00ff, ' ', 1, "SET 7,(HL)" },
  { 0x00FF, 0x00ff, ' ', 1, "SET 7,A" },
  { 0, 0, 0, 0, NULL }
};

#define T(a,b) ((a<<8)+b)

u16_t gb_ttab_00[256]= {
  /*           0   1        2   3        4    5   6   7       8   9        a   b        c   d   e   f */
    /*0*/      4, 12,       8,  8,       4,   4,  8,  4,     20,  8,       8,  8,       4,  4,  8,  4,
    /*1*/      4, 12,       8,  8,       4,   4,  8,  4,     12,  8,       8,  8,       4,  4,  8,  4,
    /*2*/T(12,8), 12,       8,  8,       4,   4,  8,  4,T(12,8),  8,       8,  8,       4,  4,  8,  4,
    /*3*/T(12,8), 18,       8,  8,      12,  12, 12,  4,T(12,8),  8,       8,  8,       4,  4,  8,  4,
    /*4*/      4,  4,       4,  4,       4,   4,  8,  4,      4,  4,       4,  4,       4,  4,  8,  4,
    /*5*/      4,  4,       4,  4,       4,   4,  8,  4,      4,  4,       4,  4,       4,  4,  8,  4,
    /*6*/      4,  4,       4,  4,       4,   4,  8,  4,      4,  4,       4,  4,       4,  4,  8,  4,
    /*7*/      8,  8,       8,  8,       8,   8,  4,  8,      4,  4,       4,  4,       4,  4,  8,  4,
    /*         0   1        2   3        4    5   6   7       8   9        a   b        c   d   e   f */
    /*8*/      4,  4,       4,  4,       4,   4,  8,  4,      4,  4,       4,  4,       4,  4,  8,  4,
    /*9*/      4,  4,       4,  4,       4,   4,  8,  4,      4,  4,       4,  4,       4,  4,  8,  4,
    /*a*/      4,  4,       4,  4,       4,   4,  8,  4,      4,  4,       4,  4,       4,  4,  8,  4,
    /*b*/      4,  4,       4,  4,       4,   4,  8,  4,      4,  4,       4,  4,       4,  4,  8,  4,
    /*c*/T(20,8), 12,T(16,12), 16,T(24,12),  16,  8, 16,T(20,8), 16,T(16,12),  4,T(24,12), 24,  8, 16,
    /*d*/T(20,8), 12,T(16,12),  0,T(24,12),  16,  8, 16,T(20,8), 16,T(16,12),  0,T(24,12),  0,  8, 16,
    /*e*/     12, 12,       8,  0,       0,  16,  8, 16,     16,  4,      16,  0,       0,  0,  8, 16,
    /*f*/     12, 12,       8,  4,       0,  16,  8, 16,     12,  8,      16,  4,       0,  0,  8, 16
    /*         0   1        2   3        4    5   6   7       8   9        a   b        c   d   e   f */
};

u16_t gb_ttab_cb[256]= {
  /*    0  1  2  3  4  5   6  7  8  9  a  b  c  d   e  f */
  /*0*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*1*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*2*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*3*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*4*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*5*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*6*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*7*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*    0  1  2  3  4  5   6  7  8  9  a  b  c  d   e  f */
  /*8*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*9*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*a*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*b*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*c*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*d*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*e*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8,
  /*f*/ 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8
  /*    0  1  2  3  4  5   6  7  8  9  a  b  c  d   e  f */
};

#undef T

/* End of z80.src/glob_gb80.cc */
