/*
 * Simulator of microcontrollers (g11p18.cc)
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
/*@1@*/

#include <stdio.h>

#include "glob11.h"

// code, mask, branch, len, mnem, iscall, ticks
struct dis_entry disass11p18[]= {

  { 0x08, 0xff, ' ', 2, "INY" },
  { 0x09, 0xff, ' ', 2, "DEY" },
  { 0x30, 0xff, ' ', 2, "TSY" },
  { 0x35, 0xff, ' ', 2, "TYS" },
  { 0x38, 0xff, ' ', 2, "PULY" },
  { 0x3a, 0xff, ' ', 2, "ABY" },
  { 0x3c, 0xff, ' ', 2, "PSHY" },
  
  { 0, 0, 0, 0, 0, 0 }
};

/* End of m6800.src/g11p18.cc */
