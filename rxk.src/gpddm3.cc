/*
 * Simulator of microcontrollers (gpddm3.cc)
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

#include "gpddm3.h"

struct dis_entry disass_pddm3[]=
  {
    { 0x21, 0xff, ' ', 4, "LD %I,%w" },
    
    { 0x09, 0xff, ' ', 4, "ADD %I,BC" },
    { 0x19, 0xff, ' ', 4, "ADD %I,DE" },
    { 0x29, 0xff, ' ', 4, "ADD %I,%I" },
    { 0x39, 0xff, ' ', 4, "ADD %I,SP" },

    { 0, 0, 0, 0, 0, 0 }
  };
  
/* End of rxk.src/gpddm3.cc */
