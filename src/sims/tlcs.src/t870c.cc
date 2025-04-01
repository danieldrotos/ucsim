/*
 * Simulator of microcontrollers (t870c.cc)
 *
 * Copyright (C) 2016 Drotos Daniel
 * 
 * To contact author send email to dr.dkdb@gmail.com
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

// local
#include "t870ccl.h"


cl_t870c::cl_t870c(class cl_sim *asim):
  cl_uc(asim)
{
  regs8[0]= &cA;
  regs8[1]= &cW;
  regs8[2]= &cC;
  regs8[3]= &cB;
  regs8[4]= &cE;
  regs8[5]= &cD;
  regs8[6]= &cL;
  regs8[7]= &cH;
  regs16[0]= &cWA;
  regs16[1]= &cBC;
  regs16[2]= &cDE;
  regs16[3]= &cHL;
  regs16[4]= &cIX;
  regs16[5]= &cIY;
  regs16[6]= &cSP;
  regs16[7]= &cHL;
}

int
cl_t870c::init(void)
{
  cl_uc::init();
  mk_rbanks();
  rF&= ~MRBS;
  
  reg_cell_var(&cW, &rW, "W", "W register");
  reg_cell_var(&cA, &rA, "A", "A register");
  reg_cell_var(&cB, &rB, "B", "B register");
  reg_cell_var(&cC, &rC, "C", "C register");
  reg_cell_var(&cD, &rD, "D", "D register");
  reg_cell_var(&cE, &rE, "E", "E register");
  reg_cell_var(&cH, &rH, "H", "H register");
  reg_cell_var(&cL, &rL, "L", "L register");
  reg_cell_var(&cF, &rF, "PSW", "PSW register");

  reg_cell_var(&cWA, &rWA, "WA", "WA register");
  reg_cell_var(&cBC, &rBC, "BC", "BC register");
  reg_cell_var(&cDE, &rDE, "DE", "DE register");
  reg_cell_var(&cHL, &rHL, "HL", "HL register");
  reg_cell_var(&cIX, &rIX, "IX", "IX register");
  reg_cell_var(&cIY, &rIY, "IY", "IY register");
  reg_cell_var(&cSP, &rSP, "SP", "SP register");
  return 0;
}

void
cl_t870c::mk_rbanks(void)
{
  rbanks= (struct rbank_870c_t *)malloc(sizeof(*rbanks));
  rbank= &rbanks[0];
}

void
cl_t870c::decode_regs(void)
{
  cW.decode(&rW);
  cA.decode(&rA);
  cB.decode(&rB);
  cC.decode(&rC);
  cD.decode(&rD);
  cE.decode(&rE);
  cH.decode(&rH);
  cL.decode(&rL);
}


/* End of tlcs.src/t870c.cc */
