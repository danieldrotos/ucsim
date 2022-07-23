/*
 * Simulator of microcontrollers (glob.cc)
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

#include "f8cl.h"

#include "glob.h"

instruction_wrapper_fn itab[256];

// code mask branch len mn call tick
struct dis_entry disass_f8[]=
  {
    // move
    { 0x80, 0xff, ' ', 2, "ld %a,#'i8'" },
    { 0x81, 0xff, ' ', 3, "ld %a,'a16_8'" },
    { 0x82, 0xff, ' ', 2, "ld %a,('nsp_8')" },
    { 0x83, 0xff, ' ', 3, "ld %a,('nnz_8')" },
    { 0x84, 0xff, ' ', 1, "ld %a,('y_8')" },
    { 0x85, 0xff, ' ', 2, "ld %a,('ny_8')" },
    { 0x86, 0xff, ' ', 1, "ld %a,xh" },
    { 0x87, 0xff, ' ', 1, "ld %a,yl" },
    { 0x88, 0xff, ' ', 1, "ld %a,yh" },
    { 0x89, 0xff, ' ', 1, "ld %a,zl" },
    { 0x8a, 0xff, ' ', 1, "ld %a,zh" },
    { 0x8b, 0xff, ' ', 3, "ld 'a16_8',%a" },
    { 0x8c, 0xff, ' ', 2, "ld ('nsp_8'),%a" },
    { 0x8d, 0xff, ' ', 3, "ld ('nnz_8'),%a" },
    { 0x8e, 0xff, ' ', 1, "ld ('y_8'),%a" },
    { 0x8f, 0xff, ' ', 2, "ld ('ny_8'),%a" },
    { 0x94, 0xff, ' ', 2, "ld yl,#'i8'" },
    
    // alu

    // branch

    // other
    { 0x00, 0xff, ' ', 1, "TRAP" },
    { 0x08, 0xff, ' ', 1, "NOP" },

    { 0, 0, 0, 0, 0, 0 }
  };


struct cpu_entry cpus_f8[]=
  {
    {"F8"	, CPU_F8, 0		, "F8", ""},

    {NULL, CPU_NONE, 0, "", ""}
  };

u16_t tick_tab_f8[256]= {
  /*           _0    _1    _2    _3      _4    _5    _6    _7      _8    _9    _a    _b      _c    _d    _e    _f */
  /* 0_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* 1_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* 2_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* 3_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* 4_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* 5_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* 6_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* 7_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* 8_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* 9_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* a_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* b_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* c_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* d_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* e_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, 
  /* f_ */    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0
};

// Bitmasks of P_XXXX
u8_t allowed_prefs[256]= {
  /*          _0  _1  _2  _3    _4  _5  _6  _7    _8  _9  _a  _b    _c  _d  _e  _f */
  /* 0_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* 1_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* 2_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* 3_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* 4_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* 5_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* 6_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* 7_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* 8_ */    PD, PD, PD, PD,   PD, PD, PA, PA,   PA, PA, PA, PD,   PD, PD, PD, PD, 
  /* 9_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* a_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* b_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* c_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* d_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* e_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN, 
  /* f_ */    PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN,   PN, PN, PN, PN
};


/* End of f8.src/glob.cc */
