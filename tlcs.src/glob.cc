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
  { 0x00, 0xff, ' ', 1, "NOP" },
  { 0x01, 0xff, ' ', 1, "HALT" },
  { 0x02, 0xff, ' ', 1, "DI" },
  { 0x03, 0xff, ' ', 1, "EI" },
  { 0x08, 0xff, ' ', 1, "EX DE,HL" },
  { 0x09, 0xff, ' ', 1, "EX AF,AF'" },
  { 0x0a, 0xff, ' ', 1, "EXX" },
  { 0x0b, 0xff, ' ', 1, "DAA A" },
  { 0x0c, 0xff, ' ', 1, "RCF" },
  { 0x0d, 0xff, ' ', 1, "SCF" },
  { 0x0e, 0xff, ' ', 1, "CCF" },
  { 0x10, 0xff, ' ', 1, "CPL A" },
  { 0x11, 0xff, ' ', 1, "NEG A" },
  { 0x000017, 0x0000ff, 'D', 3, "LDAR HL,%D" },
  { 0x1e, 0xff, ' ', 1, "RET" },
  { 0x1f, 0xff, ' ', 1, "RETI" },
  { 0x000037, 0x0000ff, 'n', 3, "LD (0xff%n),%N" },
  { 0x00003f, 0x0000ff, 'm', 3, "LDW (0xff%n),%m" },
  { 0x0097, 0x00ff, 'n', 2, "INCW (0xff%n)" },
  { 0x009F, 0x00ff, 'n', 2, "DECW (0xff%n)" },
  { 0xa0, 0xff, ' ', 1, "RLCA" },
  { 0xa1, 0xff, ' ', 1, "RRCA" },
  { 0xa2, 0xff, ' ', 1, "RLA" },
  { 0xa3, 0xff, ' ', 1, "RRA" },
  { 0xa4, 0xff, ' ', 1, "SLAA" },
  { 0xa5, 0xff, ' ', 1, "SRAA" },
  { 0xa6, 0xff, ' ', 1, "SLLA" },
  { 0xa7, 0xff, ' ', 1, "SRLA" },
  { 0xff, 0xff, ' ', 1, "SWI", true },
  /* E3 group */
  { 0x100000e3, 0xff0000ff, ' ', 4, "RLD (%M)" },
  { 0x110000e3, 0xff0000ff, ' ', 4, "RRD (%M)" },
  { 0x120000e3, 0xff0000ff, ' ', 4, "MUL HL,(%M)" },
  { 0x130000e3, 0xff0000ff, ' ', 4, "DIV HL,(%M)" },
  { 0x600000e3, 0xff0000ff, ' ', 4, "ADD A,(%M)" },
  { 0x610000e3, 0xff0000ff, ' ', 4, "ADC A,(%M)" },
  { 0x620000e3, 0xff0000ff, ' ', 4, "SUB A,(%M)" },
  { 0x630000e3, 0xff0000ff, ' ', 4, "SBC A,(%M)" },
  { 0x640000e3, 0xff0000ff, ' ', 4, "AND A,(%M)" },
  { 0x650000e3, 0xff0000ff, ' ', 4, "XOR A,(%M)" },
  { 0x660000e3, 0xff0000ff, ' ', 4, "OR A,(%M)" },
  { 0x670000e3, 0xff0000ff, ' ', 4, "CP A,(%M)" },
  { 0x700000e3, 0xff0000ff, ' ', 4, "ADD HL,(%M)" },
  { 0x710000e3, 0xff0000ff, ' ', 4, "ADC HL,(%M)" },
  { 0x720000e3, 0xff0000ff, ' ', 4, "SUB HL,(%M)" },
  { 0x730000e3, 0xff0000ff, ' ', 4, "SBC HL,(%M)" },
  { 0x740000e3, 0xff0000ff, ' ', 4, "AND HL,(%M)" },
  { 0x750000e3, 0xff0000ff, ' ', 4, "XOR HL,(%M)" },
  { 0x760000e3, 0xff0000ff, ' ', 4, "OR HL,(%M)" },
  { 0x770000e3, 0xff0000ff, ' ', 4, "CP HL,(%M)" },
  { 0x870000e3, 0xff0000ff, ' ', 4, "INC (%M)" },
  { 0x8F0000e3, 0xff0000ff, ' ', 4, "DEC (%M)" },
  { 0x970000e3, 0xff0000ff, ' ', 4, "INCW (%M)" },
  { 0x9F0000e3, 0xff0000ff, ' ', 4, "DECW (%M)" },
  { 0xA00000e3, 0xff0000ff, ' ', 4, "RLC (%M)" },
  { 0xA10000e3, 0xff0000ff, ' ', 4, "RRC (%M)" },
  { 0xA20000e3, 0xff0000ff, ' ', 4, "RL (%M)" },
  { 0xA30000e3, 0xff0000ff, ' ', 4, "RR (%M)" },
  { 0xA40000e3, 0xff0000ff, ' ', 4, "SLA (%M)" },
  { 0xA50000e3, 0xff0000ff, ' ', 4, "SRA (%M)" },
  { 0xA60000e3, 0xff0000ff, ' ', 4, "SLL (%M)" },
  { 0xA70000e3, 0xff0000ff, ' ', 4, "SRL (%M)" },
  { 0x140000e3, 0xfc0000ff, ' ', 4, "ADD %J,(%M)" },
  { 0x180000e3, 0xf80000ff, ' ', 4, "TSET %e,(%M)" },
  { 0x280000e3, 0xf80000ff, ' ', 4, "LD %T,(%M)" },
  { 0x480000e3, 0xf80000ff, ' ', 4, "LD %U,(nm)" },
  { 0x500000e3, 0xf80000ff, ' ', 4, "ex (%M),rr" },
  { 0xA80000e3, 0xf80000ff, ' ', 4, "BIT %e,(%M)" },
  { 0xB00000e3, 0xf80000ff, ' ', 4, "RES %e,(%M)" },
  { 0xB80000e3, 0xf80000ff, ' ', 4, "SET %e,(%M)" }, 
  /* E7 group */
  { 0x1000e7, 0xff00ff, 'n', 3, "RLD (0xff%n)" },
  { 0x1100e7, 0xff00ff, 'n', 3, "RRD (0xff%n)" },
  { 0x1200e7, 0xff00ff, 'n', 3, "MUL HL,(0xff%n)" },
  { 0x1300e7, 0xff00ff, 'n', 3, "DIV HL,(0xff%n)" },
  { 0xA000e7, 0xff00ff, 'n', 3, "RLC (0xff%n)" },
  { 0xA100e7, 0xff00ff, 'n', 3, "RRC (0xff%n)" },
  { 0xA200e7, 0xff00ff, 'n', 3, "RL (0xff%n)" },
  { 0xA300e7, 0xff00ff, 'n', 3, "RR (0xff%n)" },
  { 0xA400e7, 0xff00ff, 'n', 3, "SLA (0xff%n)" },
  { 0xA500e7, 0xff00ff, 'n', 3, "SRA (0xff%n)" },
  { 0xA600e7, 0xff00ff, 'n', 3, "SLL (0xff%n)" },
  { 0xA700e7, 0xff00ff, 'n', 3, "SRL (0xff%n)" },
  { 0x1400e7, 0xfc00ff, 'n', 3, "ADD %j,(0xff%n)" },
  { 0x1800e7, 0xf800ff, 'n', 3, "TSET %B,(0xff%n)" },
  { 0x2800e7, 0xf800ff, 'n', 3, "LD %t,(0xff%n)" },
  { 0x4800e7, 0xf800ff, 'n', 3, "LD %u,(0xff%n)" },
  { 0x5000e7, 0xf800ff, 'n', 3, "EX (0xff%n),%u" },
  /* EB group */

  /* EF group */

  /* F3 group */

  /* F7 group */

  /* FE group */

  /* Others in exec_inst: c1&0xfc */
  { 0x000014, 0x0000fc, 'm', 3, "ADD %I,%M" },
  /* F0+ix group */

  /* F4+ix group */

  /* Others in exec_inst: c1&0xf8 */
  { 0x20, 0xf8, 'r', 1, "LD A,%r" },
  { 0x28, 0xf8, 'r', 1, "LD %r,A" },
  { 0x000038, 0x0000f8, 'm', 3, "LD %R,%M" },
  { 0x40, 0xf8, 'R', 1, "LD HL,%R" },
  { 0x48, 0xf8, 'R', 1, "LD %R,HL" },
  { 0x50, 0xf8, 'Q', 1, "PUSH %Q" },
  { 0x58, 0xf8, 'Q', 1, "POP %Q" },
  { 0x80, 0xf8, 'r', 1, "INC %r" },
  { 0x88, 0xf8, 'r', 1, "DEC %r" },
  { 0x90, 0xf8, 'R', 1, "INC %R" },
  { 0x98, 0xf8, 'R', 1, "DEC %R" },

  /* exec_inst2 */
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////



  { 0x00001a, 0x0000ff, 'm', 3, "JP %M" },
  { 0x00001b, 0x0000ff, 'D', 3, "JRL %D" },
  { 0x00001c, 0x0000ff, 'M', 3, "CALL %M" },
  { 0x00001d, 0x0000ff, 'D', 3, "CALR %D" },
  { 0x000078, 0x0000ff, 'm', 3, "ADD HL,%M" },
  { 0x000079, 0x0000ff, 'm', 3, "ADC HL,%M" },
  { 0x00007a, 0x0000ff, 'm', 3, "SUB HL,%M" },
  { 0x00007b, 0x0000ff, 'm', 3, "SBC HL,%M" },
  { 0x00007c, 0x0000ff, 'm', 3, "AND HL,%M" },
  { 0x00007d, 0x0000ff, 'm', 3, "XOR HL,%M" },
  { 0x00007e, 0x0000ff, 'm', 3, "OR HL,%M" },
  { 0x00007f, 0x0000ff, 'm', 3, "CP HL,%M" },
  
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

  { 0x0007, 0x00ff, 'n', 2, "INCX (0xff%n)" },
  { 0x000F, 0x00ff, 'n', 2, "DECX (0xff%n)" },
  { 0x0012, 0x00ff, 'n', 2, "MUL HL,%n" },
  { 0x0013, 0x00ff, 'n', 2, "DIV HL,%n" },
  { 0x0018, 0x00ff, 'd', 2, "DJNZ %d" },
  { 0x0019, 0x00ff, 'd', 2, "DJNZ BC,%d" },
  { 0x0027, 0x00ff, 'n', 2, "LD A,(0xff%n)" },
  { 0x002F, 0x00ff, 'n', 2, "LD (0xff%n),A" },
  { 0x0047, 0x00ff, 'n', 2, "LD HL,(0xff%n)" },
  { 0x0060, 0x00ff, 'n', 2, "ADD A,(0xff%n)" },
  { 0x0061, 0x00ff, 'n', 2, "ADC A,(0xff%n)" },
  { 0x0062, 0x00ff, 'n', 2, "SUB A,(0xff%n)" },
  { 0x0063, 0x00ff, 'n', 2, "SBC A,(0xff%n)" },
  { 0x0064, 0x00ff, 'n', 2, "AND A,(0xff%n)" },
  { 0x0065, 0x00ff, 'n', 2, "XOR A,(0xff%n)" },
  { 0x0066, 0x00ff, 'n', 2, "OR A,(0xff%n)" },
  { 0x0067, 0x00ff, 'n', 2, "CP A,(0xff%n)" },
  { 0x0068, 0x00ff, 'n', 2, "ADD A,%n" },
  { 0x0069, 0x00ff, 'n', 2, "ADC A,%n" },
  { 0x006A, 0x00ff, 'n', 2, "SUB A,%n" },
  { 0x006B, 0x00ff, 'n', 2, "SBC A,%n" },
  { 0x006C, 0x00ff, 'n', 2, "AND A,%n" },
  { 0x006D, 0x00ff, 'n', 2, "XOR A,%n" },
  { 0x006E, 0x00ff, 'n', 2, "OR A,%n" },
  { 0x006F, 0x00ff, 'n', 2, "CP A,%n" },
  { 0x0070, 0x00ff, 'n', 2, "ADD HL,(0xff%n)" },
  { 0x0071, 0x00ff, 'n', 2, "ADC HL,(0xff%n)" },
  { 0x0072, 0x00ff, 'n', 2, "SUB HL,(0xff%n)" },
  { 0x0073, 0x00ff, 'n', 2, "SBC HL,(0xff%n)" },
  { 0x0074, 0x00ff, 'n', 2, "AND HL,(0xff%n)" },
  { 0x0075, 0x00ff, 'n', 2, "XOR HL,(0xff%n)" },
  { 0x0076, 0x00ff, 'n', 2, "OR HL,(0xff%n)" },
  { 0x0077, 0x00ff, 'n', 2, "CP HL,(0xff%n)" },
  { 0x0087, 0x00ff, 'n', 2, "INC (0xff%n)" },
  { 0x008F, 0x00ff, 'n', 2, "DEC (0xff%n)" },

  { 0x0030, 0x00f8, ' ', 2, "LD %r,%n" },
  { 0x00c0, 0x00f0, ' ', 2, "JR %y%d" },
    
  { 0x006800ef, 0x00ff00ff, ' ', 4, "ADD (0xff%n),%o" },
  { 0x006900ef, 0x00ff00ff, ' ', 4, "ADC (0xff%n),%o" },
  { 0x006a00ef, 0x00ff00ff, ' ', 4, "SUB (0xff%n),%o" },
  { 0x006b00ef, 0x00ff00ff, ' ', 4, "SBC (0xff%n),%o" },
  { 0x006c00ef, 0x00ff00ff, ' ', 4, "AND (0xff%n),%o" },
  { 0x006d00ef, 0x00ff00ff, ' ', 4, "XOR (0xff%n),%o" },
  { 0x006e00ef, 0x00ff00ff, ' ', 4, "OR (0xff%n),%o" },
  { 0x006f00ef, 0x00ff00ff, ' ', 4, "CP (0xff%n),%o" },
  {   0x2000ef,   0xf800ff, ' ', 3, "LD (0xff%n),%t" },
  {   0x4000ef,   0xf800ff, ' ', 3, "LD (0xff%n),%u" },
  
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

  {     0x200000eb,     0xf80000ff, ' ', 4, "LD (%M),%T" },
  {   0x00370000eb,   0x00ff0000ff, ' ', 5, "LD (%M),%O" },
  { 0x00003F0000eb, 0x0000ff0000ff, ' ', 6, "LDW (%M),%x" },
  {     0x400000eb,     0xf80000ff, ' ', 4, "LD (%M),%U" },
  {   0x00680000eb,   0x00ff0000ff, ' ', 5, "ADD (%M),%O" },
  {   0x00690000eb,   0x00ff0000ff, ' ', 5, "ADC (%M),%O" },
  {   0x006A0000eb,   0x00ff0000ff, ' ', 5, "SUB (%M),%O" },
  {   0x006B0000eb,   0x00ff0000ff, ' ', 5, "SBC (%M),%O" },
  {   0x006C0000eb,   0x00ff0000ff, ' ', 5, "AND (%M),%O" },
  {   0x006D0000eb,   0x00ff0000ff, ' ', 5, "XOR (%M),%O" },
  {   0x006E0000eb,   0x00ff0000ff, ' ', 5, "OR (%M),%O" },
  {   0x006F0000eb,   0x00ff0000ff, ' ', 5, "CP (%M),%O" },
  {     0xC00000eb,   0x00f00000ff, ' ', 4, "JP %f%M" },
  {     0xD00000eb,   0x00f00000ff, ' ', 4, "CALL %f%M" },
  
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
  { 0x50e0, 0xf8f8, 'R', 2, "EX (%R),%s" },
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

{     0x2000f4,     0xf800fc, ' ', 3, "LD (%I+%d),%t" },
{   0x003700f4,   0x00ff00fc, ' ', 4, "LD (%I+%d),%o" },
{     0x3800f4,     0xf800fc, ' ', 3, "LDA %u,%I+%d" },
{ 0x00003F00f4, 0x0000ff00fc, ' ', 5, "LDW (%I+%d),%X" },
{     0x4000f4,     0xf800fc, ' ', 4, "LD (%I+%d),%u" },
{   0x006800f4,   0x00ff00fc, ' ', 4, "ADD (%I+%d),%o" },
{   0x006900f4,   0x00ff00fc, ' ', 4, "ADC (%I+%d),%o" },
{   0x006A00f4,   0x00ff00fc, ' ', 4, "SUB (%I+%d),%o" },
{   0x006B00f4,   0x00ff00fc, ' ', 4, "SBC (%I+%d),%o" },
{   0x006C00f4,   0x00ff00fc, ' ', 4, "AND (%I+%d),%o" },
{   0x006D00f4,   0x00ff00fc, ' ', 4, "XOR (%I+%d),%o" },
{   0x006E00f4,   0x00ff00fc, ' ', 4, "OR (%I+%d),%o" },
{   0x006F00f4,   0x00ff00fc, ' ', 4, "CP (%I+%d),%o" },
{     0xC000f4,     0xf000fc, ' ', 3, "JP %F%I+%d" },
{     0xD000f4,     0xf000fc, ' ', 3, "CALL %F%I+%d" },

  { 0x0037e8, 0x00fff8, 'n', 3,	"LD (%R),%N" },
  { 0x00003Fe8, 0x0000fff8, 'n', 4, "LDW (%R),%m" },
  { 0x0068e8, 0x00fff8, 'n', 3,	"ADD (%R),%N" },
  { 0x0069e8, 0x00fff8, 'n', 3,	"ADC (%R),%N" },
  { 0x006Ae8, 0x00fff8, 'n', 3,	"SUB (%R),%N" },
  { 0x006Be8, 0x00fff8, 'n', 3,	"SBC (%R),%N" },
  { 0x006Ce8, 0x00fff8, 'n', 3,	"AND (%R),%N" },
  { 0x006De8, 0x00fff8, 'n', 3,	"XOR (%R),%N" },
  { 0x006Ee8, 0x00fff8, 'n', 3,	"OR (%R),%N" },
  { 0x006Fe8, 0x00fff8, 'n', 3,	"CP (%R),%N" },
  
  { 0x20e8, 0xf8f8, 'R', 2, "LD (%R),%p" },
  { 0x40e8, 0xf8f8, 'R', 2, "LD (%R),%s" },
  
  { 0xc0e8, 0xf0f8, 'R', 2, "JP %c%R" },
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

  { 0x00a8, 0x00f8, ' ', 2, "BIT %a,(0xff%n)" },
  { 0x00b0, 0x00f8, ' ', 2, "RES %a,(0xff%n)" },
  { 0x00b8, 0x00f8, ' ', 2, "SET %a,(0xff%n)" },
  
  { 0x0068f8, 0x00fff8, 'n', 3, "ADD %r,%N" },
  { 0x0068f8, 0x00fff8, 'n', 3, "ADC %r,%N" },
  { 0x0068f8, 0x00fff8, 'n', 3, "SUB %r,%N" },
  { 0x0068f8, 0x00fff8, 'n', 3, "SBC %r,%N" },
  { 0x0068f8, 0x00fff8, 'n', 3, "AND %r,%N" },
  { 0x0068f8, 0x00fff8, 'n', 3, "XOR %r,%N" },
  { 0x0068f8, 0x00fff8, 'n', 3, "OR %r,%N" },
  { 0x0068f8, 0x00fff8, 'n', 3, "CP %r,%N" },

  { 0x0037f7, 0x00ffff, 'n', 3, "LD (HL+A),%N" },
  { 0x0068f7, 0x00ffff, 'n', 3, "ADD (HL+A),%N" },
  { 0x0069f7, 0x00ffff, 'n', 3, "ADC (HL+A),%N" },
  { 0x006Af7, 0x00ffff, 'n', 3, "SUB (HL+A),%N" },
  { 0x006Bf7, 0x00ffff, 'n', 3, "SBC (HL+A),%N" },
  { 0x006Cf7, 0x00ffff, 'n', 3, "AND (HL+A),%N" },
  { 0x006Df7, 0x00ffff, 'n', 3, "XOR (HL+A),%N" },
  { 0x006Ef7, 0x00ffff, 'n', 3, "OR (HL+A),%N" },
  { 0x006Ff7, 0x00ffff, 'n', 3, "CP (HL+A),%N" },

  { 0x00003Ff7, 0x0000ffff, 'm', 4, "LDW (HL+A),%m" },


  { 0x1000f0, 0xff00fc, 'd', 3, "RLD (%I+%n)" },
  { 0x1100f0, 0xff00fc, 'd', 3, "RRD (%I+%n)" },
  { 0x1200f0, 0xff00fc, 'd', 3, "MUL HL,(%I+%n)" },
  { 0x1300f0, 0xff00fc, 'd', 3, "DIV HL,(%I+%n)" },
  { 0x6000f0, 0xff00fc, 'd', 3, "ADD A,(%I+%n)" },
  { 0x6100f0, 0xff00fc, 'd', 3, "ADC A,(%I+%n)" },
  { 0x6200f0, 0xff00fc, 'd', 3, "SUB A,(%I+%n)" },
  { 0x6300f0, 0xff00fc, 'd', 3, "SBC A,(%I+%n)" },
  { 0x6400f0, 0xff00fc, 'd', 3, "AND A,(%I+%n)" },
  { 0x6500f0, 0xff00fc, 'd', 3, "XOR A,(%I+%n)" },
  { 0x6600f0, 0xff00fc, 'd', 3, "OR A,(%I+%n)" },
  { 0x6700f0, 0xff00fc, 'd', 3, "CP A,(%I+%n)" },
  { 0x7000f0, 0xff00fc, 'd', 3, "ADD HL,(%I+%n)" },
  { 0x7100f0, 0xff00fc, 'd', 3, "ADC HL,(%I+%n)" },
  { 0x7200f0, 0xff00fc, 'd', 3, "SUB HL,(%I+%n)" },
  { 0x7300f0, 0xff00fc, 'd', 3, "SBC HL,(%I+%n)" },
  { 0x7400f0, 0xff00fc, 'd', 3, "AND HL,(%I+%n)" },
  { 0x7500f0, 0xff00fc, 'd', 3, "XOR HL,(%I+%n)" },
  { 0x7600f0, 0xff00fc, 'd', 3, "OR HL,(%I+%n)" },
  { 0x7700f0, 0xff00fc, 'd', 3, "CP HL,(%I+%n)" },
  { 0x8700f0, 0xff00fc, 'd', 3, "INC (%I+%n)" },
  { 0x8F00f0, 0xff00fc, 'd', 3, "DEC (%I+%n)" },
  { 0x9700f0, 0xff00fc, 'd', 3, "INCW (%I+%n)" },
  { 0x9F00f0, 0xff00fc, 'd', 3, "DECW (%I+%n)" },
  { 0xA000f0, 0xff00fc, 'd', 3, "RLC (%I+%n)" },
  { 0xA100f0, 0xff00fc, 'd', 3, "RRC (%I+%n)" },
  { 0xA200f0, 0xff00fc, 'd', 3, "RL (%I+%n)" },
  { 0xA300f0, 0xff00fc, 'd', 3, "RR (%I+%n)" },
  { 0xA400f0, 0xff00fc, 'd', 3, "SLA (%I+%n)" },
  { 0xA500f0, 0xff00fc, 'd', 3, "SRA (%I+%n)" },
  { 0xA600f0, 0xff00fc, 'd', 3, "SLL (%I+%n)" },
  { 0xA700f0, 0xff00fc, 'd', 3, "SRL (%I+%n)" },
  { 0x1400f0, 0xff00fc, 'd', 3, "ADD %j,(%I+%n)" },
  { 0x1800f0, 0xff00fc, 'd', 3, "TSET %B,(%I+%n)" },
  { 0x2800f0, 0xff00fc, 'd', 3, "LD %t,(%I+%n)" },
  { 0x4800f0, 0xff00fc, 'd', 3, "LD %u,(%I+%n)" },
  { 0x5000f0, 0xff00fc, 'd', 3, "EX (%I+%n),%u" },
  { 0xA800f0, 0xff00fc, 'd', 3, "BIT %B,(%I+%n)" },
  { 0xB000f0, 0xff00fc, 'd', 3, "RES %B,(%I+%n)" },
  { 0xB800f0, 0xff00fc, 'd', 3, "SET %B,(%I+%n)" },

  

  { 0, 0, ' ', 0, NULL }
};

//	    case 'r': /*  r in 1st byte */ s+= regname_r(c); break;
//	    case 'p': /*  r in 2nd byte */ s+= regname_r(c>>8); break;
//	    case 't': /*  r in 3rd byte */ s+= regname_r(c>>16); break;
//	    case 'T': /*  r in 4th byte */ s+= regname_r(c>>24); break;
//	    case 'R': /* rr in 1st byte */ s+= regname_R(c); break;
//	    case 's': /* rr in 2nd byte */ s+= regname_R(c>>8); break;
//	    case 'u': /* rr in 3rd byte */ s+= regname_R(c>>16); break;
//	    case 'U': /* rr in 4th byte */ s+= regname_R(c>>24); break;
//	    case 'Q': /* qq in 1st byte */ s+= regname_Q(c); break;
//	    case 'I': /* ix in 1st byte */ s+= regname_i(c); break;
//	    case 'i': /* ix in 2nd byte */ s+= regname_i(c>>8); break;
//	    case 'j': /* ix in 3rd byte */ s+= regname_i(c>>16); break;
//	    case 'J': /* ix in 4th byte */ s+= regname_i(c>>24); break;
//	    case 'b': /*  b in 2nd byte */ s+= bitname(c>>8); break;
//	    case 'B': /*  b in 3rd byte */ s+= bitname(c>>16); break;
//	    case 'e': /*  b in 4th byte */ s+= bitname(c>>24); break;
//	    case 'y': /* cc in 1st byte */ s+= condname_cc(c); break; // with ,
//	    case 'c': /* cc in 2nd byte */ s+= condname_cc(c>>8); break; // with ,
//	    case 'C': /* cc in 2nd byte */ s+= condname_C(c>>8); break; // without ,
//	    case 'F': /* cc in 3rd byte */ s+= condname_cc(c>>16); break; // with ,
//	    case 'f': /* cc in 4th byte */ s+= condname_cc(c>>24); break; // with ,
//	    case 'n': /*  n in 2nd byte */ snprintf(l,19,"%02x",(int)(c>>8));s+= l; break;
//	    case 'N': /*  n in 3dd byte */ snprintf(l,19,"%02x",(int)((c>>16)&0xff));s+= l; break;
//	    case 'o': /*  n in 4th byte */ snprintf(l,19,"%02x",(int)((c>>24)&0xff));s+= l; break;
//	    case 'O': /*  n in 5th byte */ snprintf(l,19,"%02x",(int)((c>>32)&0xff));s+= l; break;
//	    case 'd': /*  d in 2nd byte */ snprintf(l,19,"0x%04x", addr+2+((c>>8)&0xff)); s+= l; break;
//	    case 'D': /* cd in 2,3 byte */ snprintf(l,19,"0x%04x",(int)(addr+3+int16_t((c>>8)&0xffff))); s+= l; break;	      
//	    case 'D': /* cd in 2,3 byte */ snprintf(l,19,"0x%04x", addr+2+((c>>8)&0xffff)); s+= l; break;
//	    case 'M': /* mn in 2,3 byte */ snprintf(l,19,"0x%04x",(int)((c>>8)&0xffff)); s+= l; break;
//	    case 'm': /* mn in 3,4 byte */ snprintf(l,19,"0x%04x",(int)((c>>16)&0xffff)); s+= l; break;
//	    case 'X': /* mn in 4,5 byte */ snprintf(l,19,"0x%04x",(int)((c>>24)&0xffff)); s+= l; break;
//	    case 'x': /* mn in 5,6 byte */ snprintf(l,19,"0x%04x",(int)((c>>32)&0xffff)); s+= l; break;

/* End of tlcs.src/glob.cc */
