/*
 * Simulator of microcontrollers (gp0m4.cc)
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

#include "gp0m4.h"

struct dis_entry disass_p0m4[]=
  {
    { 0x42, 0xff, ' ', 1, "RL HL" },
    { 0x62, 0xff, ' ', 1, "RL BC" },
    { 0x45, 0xff, ' ', 1, "SUB HL,JK" },
    { 0x55, 0xff, ' ', 1, "SUB HL,DE" },
    { 0x4c, 0xff, ' ', 1, "TEST HL" },
    { 0x48, 0xff, ' ', 2, "CP HL,%d" },
    { 0x60, 0xff, ' ', 1, "RLC BC" },
    { 0x50, 0xff, ' ', 1, "RLC DE" },
    { 0x61, 0xff, ' ', 1, "RRC BC" },
    { 0x51, 0xff, ' ', 1, "RRC DE" },
    { 0x54, 0xff, ' ', 1, "XOR HL,DE" },
    { 0x63, 0xff, ' ', 1, "RR BC" },
    { 0x65, 0xff, ' ', 1, "ADD HL,JK" },
    { 0x81, 0xff, ' ', 1, "LD HL,BC" },
    { 0x91, 0xff, ' ', 1, "LD BC,HL" },
    { 0xa1, 0xff, ' ', 1, "LD HL,DE" },
    { 0x82, 0xff, ' ', 4, "LD (%l),HL" },
    { 0x82, 0xff, ' ', 4, "LD HL,(%l)" },
    { 0x83, 0xff, ' ', 3, "LD (%w),BCDE" },
    { 0x84, 0xff, ' ', 3, "LD (%w),JKHL" },
    { 0x93, 0xff, ' ', 3, "LD BCDE,(%w)" },
    { 0x94, 0xff, ' ', 3, "LD JKHL,(%w)" },
    
    { 0, 0, 0, 0, 0, 0, 0 }
  };
  
/* End of rxk.src/gp0m4.cc */
