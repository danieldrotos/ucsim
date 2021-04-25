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
#include "rmemcl.h"

#include "rxkcl.h"


cl_rxk::cl_rxk(class cl_sim *asim):
  cl_uc(asim)
{
  cA.init();
  cA.decode(&rA);
  cF.init();
  cF.decode(&rF);
  cAF.init();
  cAF.decode(&rAF);
  
  cB.init();
  cB.decode(&rB);
  cC.init();
  cC.decode(&rB);
  cBC.init();
  cBC.decode(&rBC);

  cD.init();
  cD.decode(&rD);
  cE.init();
  cE.decode(&rE);
  cDE.init();
  cDE.decode(&rDE);

  cH.init();
  cH.decode(&rH);
  cL.init();
  cL.decode(&rL);
  cHL.init();
  cHL.decode(&rHL);

  cIX.init();
  cIX.decode(&IX);
  cIY.init();
  cIY.decode(&IY);
  cSP.init();
  cSP.decode(&SP);

  cIP.init();
  cIP.decode(&IP);
  cIIR.init();
  cIIR.decode(&IIR);
  cEIR.init();
  cEIR.decode(&EIR);
}

int
cl_rxk::init(void)
{
  cl_uc::init();
  ioi_prefix= false;
  ioe_prefix= false;
  
  xtal= 1000000;

  class cl_cvar *v;
  vars->add(v= new cl_cvar("A",  &cA , "CPU register A" )); v->init();
  vars->add(v= new cl_cvar("F",  &cF , "CPU register F" )); v->init();
  vars->add(v= new cl_cvar("AF", &cAF, "CPU register AF")); v->init();
  vars->add(v= new cl_cvar("B",  &cB , "CPU register B" )); v->init();
  vars->add(v= new cl_cvar("C",  &cC , "CPU register C" )); v->init();
  vars->add(v= new cl_cvar("BC", &cBC, "CPU register BC")); v->init();
  vars->add(v= new cl_cvar("H",  &cH , "CPU register H" )); v->init();
  vars->add(v= new cl_cvar("L",  &cL , "CPU register L" )); v->init();
  vars->add(v= new cl_cvar("HL", &cHL, "CPU register HL")); v->init();
  vars->add(v= new cl_cvar("IX", &cIX, "CPU register IX")); v->init();
  vars->add(v= new cl_cvar("IY", &cIY, "CPU register IY")); v->init();
  vars->add(v= new cl_cvar("SP", &cSP, "CPU register SP")); v->init();
  
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

  // MMU reset
  mem->segsize= 0;
  mem->dataseg= 0;
  mem->dataseg= 0;
  mem->stackseg= 0;
  mem->xpc= 0;

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
  add_hw(cpu= new cl_rxk_cpu(this));
  cpu->init();
}

void
cl_rxk::make_memories(void)
{
  class cl_memory_chip *chip;
  class cl_address_space *as;
  class cl_address_decoder *ad;

  chip= new cl_chip8("rom_chip", 0x100000, 8);
  chip->init();
  memchips->add(chip);

  rom= as= mem= new cl_ras("rom", chip);
  as->init();
  address_spaces->add(as);

  /* IO */
  ioi= as= new cl_address_space("ioi", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  chip= new cl_chip8("ioi_chip", 0x10000, 8);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);

  ioe= as= new cl_address_space("ioe", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  chip= new cl_chip8("ioe_chip", 0x10000, 8);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}

void
cl_rxk::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("A= 0x%02x %3d %c  ",
                 rA, rA, isprint(rA)?rA:'.');
  con->dd_printf("F= "); con->print_bin(rF, 8);
  con->dd_printf(" 0x%02x %3d %c", rF, rF, isprint(rF)?rF:'.');
  con->dd_printf("\n");
  con->dd_printf("                  SZxxxVxC\n");

  con->dd_printf("BC= ");
  rom->dump(0, rBC, rBC+7, 8, con);
  con->dd_color("answer");
  con->dd_printf("DE= ");
  rom->dump(0, rDE, rDE+7, 8, con);
  con->dd_color("answer");
  con->dd_printf("HL= ");
  rom->dump(0, rHL, rHL+7, 8, con);
  con->dd_color("answer");
  con->dd_printf("IX= ");
  rom->dump(0, rIX, rIX+7, 8, con);
  con->dd_color("answer");
  con->dd_printf("IY= ");
  rom->dump(0, rIY, rIY+7, 8, con);
  con->dd_color("answer");
  con->dd_printf("SP= ");
  rom->dump(0, rSP, rSP+7, 8, con);
  con->dd_color("answer");

  print_disass(PC, con);
}


/*
 * CPU peripheral: MMU functions
 */

cl_rxk_cpu::cl_rxk_cpu(class cl_uc *auc):
  cl_hw(auc, HW_CPU, 0, "cpu")
{
  ruc= (class cl_rxk *)auc;
}

int
cl_rxk_cpu::init(void)
{
  cl_hw::init();
  stackseg= (cl_cell8*)ruc->ioi->get_cell(0x11);
  dataseg = (cl_cell8*)ruc->ioi->get_cell(0x12);
  segsize = (cl_cell8*)ruc->ioi->get_cell(0x13);
  stackseg->decode((t_mem*)&(ruc->mem->stackseg));
  dataseg ->decode((t_mem*)&(ruc->mem->dataseg));
  segsize ->decode((t_mem*)&(ruc->mem->segsize));

  xpc= new cl_cell8(8);
  xpc->decode((t_mem*)(&(ruc->mem->xpc)));

  class cl_cvar *v;
  uc->vars->add(v= new cl_cvar("STACKSEG", stackseg, "MMU register: STACKSEG"));
  v->init();
  uc->vars->add(v= new cl_cvar("DATASEG", dataseg, "MMU register: DATASEG"));
  v->init();
  uc->vars->add(v= new cl_cvar("SEGSIZE", segsize, "MMU register: SEGSIZE"));
  v->init();
  uc->vars->add(v= new cl_cvar("XPC", xpc, "MMU register: XPC"));
  v->init();

  return 0;
}

const char *
cl_rxk_cpu::cfg_help(t_addr addr)
{
  switch (addr)
    {
    case rxk_cpu_xpc: return "MMU register: XPC";
    case rxk_cpu_nuof: return "";
    }
  return "Not used";
}

/*
t_mem
cl_rxk_cpu::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  switch ((enum rxkcpu_cfg)addr)
    {
    case rxk_cpu_xpc:
      if (val) cell->set(ruc->mem->xpc= *val);
      return ruc->mem->xpc;
    case rxk_cpu_nuof:
      return 0;
    }
  return 0;

  if (val)
    cell->set(*val);
  return cell->get();
}
*/

void
cl_rxk_cpu::print_info(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("%s[%d]\n", id_string, id);
  con->dd_printf("SEGSIZE : 0x%02x\n", segsize->read());
  con->dd_printf("DATASEG : 0x%02x\n", dataseg->read());
  con->dd_printf("STACKSEG: 0x%02x\n", stackseg->read());
  con->dd_printf("XPC     : 0x%02x\n", xpc->read());
}


/* End of rxk.src/rxk.cc */
