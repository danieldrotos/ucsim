/*
 * Simulator of microcontrollers (ibranch.cc)
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

#include "mcs6502cl.h"


int
cl_mcs6502::JMPa(t_mem code)
{
  u16_t a= i16();
  PC= a;
  return resGO;
}

int
cl_mcs6502::JMPi(t_mem code)
{
  u16_t a= i16();
  a= read_addr(rom, a);
  PC= a;
  tick(2);
  vc.rd+= 2;
  return resGO;
}

int
cl_mcs6502::JSR(t_mem code)
{
  u16_t a= i16();
  push_addr(PC);
  PC= a;
  return resGO;
}

int
cl_mcs6502::RTS(t_mem code)
{
  PC= pop_addr();
  return resGO;
}


/* End of mcs6502.src/ibranch.cc */
