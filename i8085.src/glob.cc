/*
 * Simulator of microcontrollers (glob.cc)
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

#include "glob.h"

instruction_wrapper_fn itab[256];

// code mask branch len mn call tick
struct dis_entry disass_common[]=
  {  
    { 0x00, 0xff, ' ', 1, "NOP" },
    { 0x76, 0xff, ' ', 1, "HLT" },
    { 0xfb, 0xff, ' ', 1, "EI" },
    { 0xf3, 0xff, ' ', 1, "DI" },
    
    { 0x40, 0xc0, ' ', 1, "MOV 'rm5','rm2'" },
    { 0x06, 0xc7, ' ', 2, "MVI 'rm5',#'i8'" },
    { 0x01, 0xcf, ' ', 3, "LXI 'rp5',#'i16'" },
    { 0x3a, 0xff, ' ', 3, "LDA 'a16_8'" },
    { 0x32, 0xff, ' ', 3, "STA 'a16_8'" },
    { 0x2a, 0xff, ' ', 3, "LHLD 'a16_16'" },
    { 0x22, 0xff, ' ', 3, "SHLD 'a16_16'" },
    { 0x0a, 0xff, ' ', 1, "LDAX 'rp5_8'" },
    { 0x1a, 0xff, ' ', 1, "LDAX 'rp5_8'" },
    { 0x02, 0xff, ' ', 1, "STAX 'rp5_8'" },
    { 0x12, 0xff, ' ', 1, "STAX 'rp5_8'" },
    { 0xeb, 0xff, ' ', 1, "XCHG" },
    { 0xdb, 0xff, ' ', 2, "IN 'in'" },
    { 0xd3, 0xff, ' ', 2, "OUT 'out'" },
    { 0xc5, 0xcf, ' ', 1, "PUSH 'srp'" },
    { 0xc1, 0xcf, ' ', 1, "POP 'srp'" },
    { 0xe3, 0xff, ' ', 1, "XTHL" },
    { 0xf9, 0xff, ' ', 1, "SPHL" },
    
    { 0x80, 0xf8, ' ', 1, "ADD 'rm2'" },
    { 0xc6, 0xff, ' ', 2, "ADI #'i8'" },
    { 0x88, 0xf8, ' ', 1, "ADC 'rm2'" },
    { 0xce, 0xff, ' ', 2, "ACI #'i8'" },
    { 0x90, 0xf8, ' ', 1, "SUB 'rm2'" },
    { 0xd6, 0xff, ' ', 2, "SUI #'i8'" },
    { 0x98, 0xf8, ' ', 1, "SBB 'rm2'" },
    { 0xde, 0xff, ' ', 2, "SBI #'i8'" },
    { 0xb8, 0xf8, ' ', 1, "CMP 'rm2'" },
    { 0xfe, 0xff, ' ', 2, "CPI #'i8'" },
    { 0x09, 0xcf, ' ', 1, "DAD 'rp5_16'" },
    { 0x04, 0xc7, ' ', 1, "INR 'rm5'" },
    { 0x05, 0xc7, ' ', 1, "DCR 'rm5'" },
    { 0x03, 0xcf, ' ', 1, "INX 'rp5'" },
    { 0x0b, 0xcf, ' ', 1, "DCX 'rp5'" },
    { 0xa0, 0xf8, ' ', 1, "ANA 'rm2'" },
    { 0xe6, 0xff, ' ', 2, "ANI #'i8'" },
    { 0xb0, 0xf8, ' ', 1, "ORA 'rm2'" },
    { 0xf6, 0xff, ' ', 2, "ORI #'i8'" },
    { 0xa8, 0xf8, ' ', 1, "XOR 'rm2'" },
    { 0xee, 0xff, ' ', 2, "XRI #'i8'" },

    { 0x07, 0xff, ' ', 1, "RLC" },
    { 0x0f, 0xff, ' ', 1, "RRC" },
    { 0x17, 0xff, ' ', 1, "RAL" },
    { 0x1f, 0xff, ' ', 1, "RAR" },
    
    { 0x27, 0xff, ' ', 1, "DAA" },
    { 0x2f, 0xff, ' ', 1, "CMA" },
    { 0x3f, 0xff, ' ', 1, "CMC" },
    { 0x37, 0xff, ' ', 1, "STC" },

    { 0xc3, 0xff, ' ', 3, "JMP 'a16'" },
    { 0xc2, 0xff, ' ', 3, "JNZ 'a16'" },
    { 0xca, 0xff, ' ', 3, "JZ 'a16'" },
    { 0xd2, 0xff, ' ', 3, "JNC 'a16'" },
    { 0xda, 0xff, ' ', 3, "JC 'a16'" },
    { 0xe2, 0xff, ' ', 3, "JPO 'a16'" },
    { 0xea, 0xff, ' ', 3, "JPE 'a16'" },
    { 0xf2, 0xff, ' ', 3, "JP 'a16'" },
    { 0xfa, 0xff, ' ', 3, "JM 'a16'" },
    
    { 0xcd, 0xff, ' ', 3, "CALL 'a16'" },
    { 0xc4, 0xff, ' ', 3, "CNZ 'a16'" },
    { 0xcc, 0xff, ' ', 3, "CZ 'a16'" },
    { 0xd4, 0xff, ' ', 3, "CNC 'a16'" },
    { 0xdc, 0xff, ' ', 3, "CC 'a16'" },
    { 0xe4, 0xff, ' ', 3, "CPO 'a16'" },
    { 0xec, 0xff, ' ', 3, "CPE 'a16'" },
    { 0xf4, 0xff, ' ', 3, "CP 'a16'" },
    { 0xfc, 0xff, ' ', 3, "CM 'a16'" },
    
    { 0xc9, 0xff, ' ', 1, "RET" },
    { 0xc0, 0xff, ' ', 1, "RNZ" },
    { 0xc8, 0xff, ' ', 1, "RZ" },
    { 0xd0, 0xff, ' ', 1, "RNC" },
    { 0xd8, 0xff, ' ', 1, "RC" },
    { 0xe0, 0xff, ' ', 1, "RPO" },
    { 0xe8, 0xff, ' ', 1, "RPE" },
    { 0xf0, 0xff, ' ', 1, "RP" },
    { 0xf8, 0xff, ' ', 1, "RM" },

    { 0xc7, 0xc7, ' ', 1, "RST 'rst'" },
    { 0xe9, 0xff, ' ', 1, "PCHL" },

    { 0, 0, 0, 0, 0, 0 }
  };

struct dis_entry disass_8080[]=
  {
    { 0x10, 0xff, ' ', 1, "*NOP" },
    { 0x20, 0xff, ' ', 1, "*NOP" },
    { 0x30, 0xff, ' ', 1, "*NOP" },
    { 0x08, 0xff, ' ', 1, "*NOP" },
    { 0x18, 0xff, ' ', 1, "*NOP" },
    { 0x28, 0xff, ' ', 1, "*NOP" },
    { 0x38, 0xff, ' ', 1, "*NOP" },
    { 0xd9, 0xff, ' ', 1, "*RET" },
    { 0xcb, 0xff, ' ', 3, "*JMP 'a16'" },
    { 0xdd, 0xff, ' ', 3, "*CALL 'a16'" },
    { 0xed, 0xff, ' ', 3, "*CALL 'a16'" },
    { 0xfd, 0xff, ' ', 3, "*CALL 'a16'" },
    { 0, 0, 0, 0, 0, 0 }
  };

struct dis_entry disass_8085[]=
  {
    { 0x20, 0xff, ' ', 1, "RIM" },
    { 0x30, 0xff, ' ', 1, "SIM" },

    { 0x10, 0xff, ' ', 1, "ARHL" },
    { 0xdd, 0xff, ' ', 3, "JNX5 'a16'" },
    { 0xfd, 0xff, ' ', 3, "JX5 'a16'" },
    { 0x28, 0xff, ' ', 2, "LDHI 'hli8'" },
    { 0x38, 0xff, ' ', 2, "LDSI 'spi8'" },
    { 0xed, 0xff, ' ', 1, "LHLX 'de16'" },
    
    { 0, 0, 0, 0, 0, 0 }
  };

struct cpu_entry cpus_8085[]=
  {
    {"I8080"	, CPU_I8080, 0		, "I8080", ""},
    {"8080"	, CPU_I8080, 0		, "I8080", ""},
    {"80"	, CPU_I8080, 0		, "I8080", ""},
    {"0"	, CPU_I8080, 0		, "I8080", ""},
    {"I8085"	, CPU_I8085, 0		, "I8085", ""},
    {"8085"	, CPU_I8085, 0		, "I8085", ""},
    {"85"	, CPU_I8085, 0		, "I8085", ""},
    {"5"	, CPU_I8085, 0		, "I8085", ""},

    {NULL, CPU_NONE, 0, "", ""}
  };

/* 1 values will be replaced by flagP before start */
u8_t ptab[256]= {
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1
};

u16_t tick_tab_8080[256]= {
  /*           _0    _1    _2    _3      _4    _5    _6    _7      _8    _9    _a    _b      _c    _d    _e    _f */
  /* 0_ */    0x04, 0x0a, 0x07, 0x05,   0x05, 0x05, 0x07, 0x04,   0x04, 0x0a, 0x07, 0x05,   0x05, 0x05, 0x07, 0x04, 
  /* 1_ */    0x04, 0x0a, 0x07, 0x05,   0x05, 0x05, 0x07, 0x04,   0x04, 0x0a, 0x07, 0x05,   0x05, 0x05, 0x07, 0x04, 
  /* 2_ */    0x04, 0x0a, 0x10, 0x05,   0x05, 0x05, 0x07, 0x04,   0x04, 0x0a, 0x10, 0x05,   0x05, 0x05, 0x07, 0x04, 
  /* 3_ */    0x04, 0x0a, 0x0d, 0x05,   0x0a, 0x0a, 0x0a, 0x04,   0x04, 0x0a, 0x0d, 0x05,   0x05, 0x05, 0x07, 0x04, 
  /* 4_ */    0x05, 0x05, 0x05, 0x05,   0x05, 0x05, 0x07, 0x05,   0x05, 0x05, 0x05, 0x05,   0x05, 0x05, 0x07, 0x05, 
  /* 5_ */    0x05, 0x05, 0x05, 0x05,   0x05, 0x05, 0x07, 0x05,   0x05, 0x05, 0x05, 0x05,   0x05, 0x05, 0x07, 0x05, 
  /* 6_ */    0x05, 0x05, 0x05, 0x05,   0x05, 0x05, 0x07, 0x05,   0x05, 0x05, 0x05, 0x05,   0x05, 0x05, 0x07, 0x05, 
  /* 7_ */    0x07, 0x07, 0x07, 0x07,   0x07, 0x07, 0x07, 0x07,   0x05, 0x05, 0x05, 0x05,   0x05, 0x05, 0x07, 0x05, 
  /* 8_ */    0x04, 0x04, 0x04, 0x04,   0x04, 0x04, 0x07, 0x04,   0x04, 0x04, 0x04, 0x04,   0x04, 0x04, 0x07, 0x04, 
  /* 9_ */    0x04, 0x04, 0x04, 0x04,   0x04, 0x04, 0x07, 0x04,   0x04, 0x04, 0x04, 0x04,   0x04, 0x04, 0x07, 0x04, 
  /* a_ */    0x04, 0x04, 0x04, 0x04,   0x04, 0x04, 0x07, 0x04,   0x04, 0x04, 0x04, 0x04,   0x04, 0x04, 0x07, 0x04, 
  /* b_ */    0x04, 0x04, 0x04, 0x04,   0x04, 0x04, 0x07, 0x04,   0x04, 0x04, 0x04, 0x04,   0x04, 0x04, 0x07, 0x04, 
  /* c_ */  0x0b05, 0x0a, 0x0a, 0x0a, 0x110b, 0x0b, 0x07, 0x0b, 0x0b05, 0x0a, 0x0a, 0x0a, 0x110b, 0x11, 0x07, 0x0b, 
  /* d_ */  0x0b05, 0x0a, 0x0a, 0x0a, 0x110b, 0x0b, 0x07, 0x0b, 0x0b05, 0x0a, 0x0a, 0x0a, 0x110b, 0x11, 0x07, 0x0b, 
  /* e_ */  0x0b05, 0x0a, 0x0a, 0x12, 0x110b, 0x0b, 0x07, 0x0b, 0x0b05, 0x05, 0x0a, 0x05, 0x110b, 0x11, 0x07, 0x0b, 
  /* f_ */  0x0b05, 0x0a, 0x0a, 0x04, 0x110b, 0x0b, 0x07, 0x0b, 0x0b05, 0x05, 0x0a, 0x04, 0x110b, 0x11, 0x07, 0x0b
};

u16_t tick_tab_8085[256]= {
  /*           _0    _1      _2    _3      _4    _5    _6    _7      _8    _9      _a    _b      _c      _d    _e    _f */
  /* 0_ */    0x04, 0x0a,   0x07, 0x06,   0x04, 0x04, 0x07, 0x04,   0x0a, 0x0a,   0x07,   0x06,   0x04,   0x04, 0x07, 0x04, 
  /* 1_ */    0x07, 0x0a,   0x07, 0x06,   0x04, 0x04, 0x07, 0x04,   0x0a, 0x0a,   0x07,   0x06,   0x04,   0x04, 0x07, 0x04, 
  /* 2_ */    0x04, 0x0a,   0x10, 0x06,   0x04, 0x04, 0x07, 0x04,   0x0a, 0x0a,   0x10,   0x06,   0x04,   0x04, 0x07, 0x04, 
  /* 3_ */    0x04, 0x0a,   0x0d, 0x06,   0x0a, 0x0a, 0x0a, 0x04,   0x0a, 0x0a,   0x0d,   0x06,   0x04,   0x04, 0x07, 0x04, 
  /* 4_ */    0x04, 0x04,   0x04, 0x04,   0x04, 0x04, 0x07, 0x04,   0x04, 0x04,   0x04,   0x04,   0x04,   0x04, 0x07, 0x04, 
  /* 5_ */    0x04, 0x04,   0x04, 0x04,   0x04, 0x04, 0x07, 0x04,   0x04, 0x04,   0x04,   0x04,   0x04,   0x04, 0x07, 0x04, 
  /* 6_ */    0x04, 0x04,   0x04, 0x04,   0x04, 0x04, 0x07, 0x04,   0x04, 0x04,   0x04,   0x04,   0x04,   0x04, 0x07, 0x04, 
  /* 7_ */    0x07, 0x07,   0x07, 0x07,   0x07, 0x07, 0x05, 0x07,   0x04, 0x04,   0x04,   0x04,   0x05,   0x04, 0x07, 0x04, 
  /* 8_ */    0x04, 0x04,   0x04, 0x04,   0x04, 0x04, 0x07, 0x04,   0x04, 0x04,   0x04,   0x04,   0x04,   0x04, 0x07, 0x04, 
  /* 9_ */    0x04, 0x04,   0x04, 0x04,   0x04, 0x04, 0x07, 0x04,   0x04, 0x04,   0x04,   0x04,   0x04,   0x04, 0x07, 0x04, 
  /* a_ */    0x04, 0x04,   0x04, 0x04,   0x04, 0x04, 0x07, 0x04,   0x04, 0x04,   0x04,   0x04,   0x04,   0x04, 0x07, 0x04, 
  /* b_ */    0x04, 0x04,   0x04, 0x04,   0x04, 0x04, 0x07, 0x04,   0x04, 0x04,   0x04,   0x04,   0x04,   0x04, 0x07, 0x04, 
  /* c_ */  0x0c06, 0x0a, 0x0a07, 0x0a, 0x1209, 0x0c, 0x07, 0x0c, 0x0c06, 0x0a, 0x0a07, 0x0c06, 0x1209,   0x12, 0x07, 0x0c, 
  /* d_ */  0x0c06, 0x0a, 0x0a07, 0x0a, 0x1209, 0x0c, 0x07, 0x0c, 0x0c06, 0x0a, 0x0a07,   0x0a, 0x1209, 0x0a07, 0x07, 0x0c, 
  /* e_ */  0x0c06, 0x0a, 0x0a07, 0x10, 0x1209, 0x0c, 0x07, 0x0c, 0x0c06, 0x06, 0x0a07,   0x04, 0x1209,   0x1a, 0x07, 0x0c, 
  /* f_ */  0x0c06, 0x0a, 0x0a07, 0x04, 0x1209, 0x0c, 0x07, 0x0c, 0x0c06, 0x06, 0x0a07,   0x04, 0x1209, 0x0a07, 0x07, 0x0c 
};

/* End of i8085.src/glob.cc */
