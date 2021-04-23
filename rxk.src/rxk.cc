/*
 * Simulator of microcontrollers (rxk.cc)
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

#include <stdlib.h>
#include <ctype.h>

#include "globals.h"
#include "utils.h"

#include "dregcl.h"

#include "glob.h"

#include "rxkcl.h"


cl_rxk::cl_rxk(class cl_sim *asim):
  cl_uc(asim)
{
  cA.init();
  cA.decode((t_mem*)&AF.r.A);
  cF.init();
  cF.decode((t_mem*)&AF.r.F);
  cAF.init();
  cAF.set_width(16);
  cAF.decode((t_mem*)&AF.AF);

  cB.init();
  cB.decode((t_mem*)&BC.r.B);
  cC.init();
  cC.decode((t_mem*)&BC.r.B);
  cBC.init();
  cBC.set_width(16);
  cBC.decode((t_mem*)&BC.BC);

  cD.init();
  cD.decode((t_mem*)&DE.r.D);
  cE.init();
  cE.decode((t_mem*)&DE.r.E);
  cDE.init();
  cDE.set_width(16);
  cDE.decode((t_mem*)&DE.DE);

  cH.init();
  cH.decode((t_mem*)&HL.r.H);
  cL.init();
  cL.decode((t_mem*)&HL.r.L);
  cHL.init();
  cHL.set_width(16);
  cHL.decode((t_mem*)&HL.HL);
}

int
cl_rxk::init(void)
{
  cl_uc::init();

  xtal= 1000000;
    
  return 0;
}


const char *
cl_rxk::id_string(void)
{
  return "RXK";
}

void
cl_rxk::reset(void)
{
  cl_uc::reset();
}

  
void
cl_rxk::set_PC(t_addr addr)
{
  PC= addr;
}

void
cl_rxk::mk_hw_elements(void)
{
  class cl_hw *h;
  
  cl_uc::mk_hw_elements();

  add_hw(h= new cl_dreg(this, 0, "dreg"));
  h->init();
}

void
cl_rxk::make_cpu_hw(void)
{
}

void
cl_rxk::make_memories(void)
{
  class cl_address_space *as;
  class cl_address_decoder *ad;
  class cl_memory_chip *chip;
  
  rom= as= new cl_address_space("rom", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  chip= new cl_memory_chip("rom_chip", 0x10000, 8);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as= rom,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}

void
cl_rxk::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");

  print_disass(PC, con);
}

/* End of rxk.src/rxk.cc */
