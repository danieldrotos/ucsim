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
#include <ctype.h>

#include "utils.h"

// local
#include "t870ccl.h"


cl_t870c_psw_op::cl_t870c_psw_op(class cl_memory_cell *acell, class cl_t870c *auc):
  cl_memory_operator(acell)
{
  uc= auc;
}

t_mem
cl_t870c_psw_op::write(t_mem val)
{
  val&= 0xfc;
  return val;
}


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

  def_data= 0xff;
}

int
cl_t870c::init(void)
{
  cl_uc::init();
  mk_rbanks();
  
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

  part_init();
  return 0;
}

void
cl_t870c::part_init(void)
{
  class cl_memory_operator *o= new cl_t870c_psw_op(&cPSW, this);
  o->init();
  cPSW.append_operator(o);
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


void
cl_t870c::make_memories(void)
{
  class cl_address_space *as;

  rom= asc= asd= as= new cl_address_space("nas", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  class cl_address_decoder *ad;
  class cl_memory_chip *chip;

  bootrom_chip= chip= new cl_chip8("bootrom_chip", 0x800, 8, 0xff);
  chip->init();
  memchips->add(chip);
  
  rom_chip= chip= new cl_chip8("rom_chip", 0x8000, 8, 0xff);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= rom,
                             chip, 0x8000, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
  
  int rs= 0x400 * 3;
  ram_chip= chip= new cl_chip8("ram_chip", rs, 8);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= rom,
                             chip, 0x40, 0x40+rs-1, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
  
  chip= new cl_chip8("sfr_chip", 64, 8, 0);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= rom,
                             chip, 0, 63, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);

  chip= new cl_chip8("dbr_chip", 128, 8, 0);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= rom,
                             chip, 0xf80, 0xfff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}


void
cl_t870c::make_cpu_hw(void)
{
  add_hw(cpu= new cl_t870c_cpu(this));
  cpu->init();
}


void
cl_t870c::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("JZCHSV--  Flags= 0x%02x  ", rF);
  con->dd_printf("A= 0x%02x %3d %c\n",
		 rA, rA, isprint(rA)?rA:'.');
  con->dd_printf("%s\n", cbin(rF,8).c_str());
  con->dd_printf("WA0=0x%04x [WA]=%02x  ", rWA, asd->read(rWA));
  con->dd_printf("BC0=0x%04x [BC]=%02x  ", rBC, asd->read(rBC));
  con->dd_printf("DE0=0x%04x [DE]=%02x\n", rDE, asd->read(rDE));
  con->dd_printf("HL0=0x%04x [HL]=%02x  ", rHL, asd->read(rHL));
  con->dd_printf("IX0=0x%04x [IX]=%02x  ", rIX, asd->read(rIX));
  con->dd_printf("IY0=0x%04x [IY]=%02x\n", rIY, asd->read(rIY));
  con->dd_printf("SP =0x%04x [SP]=%02x  ", rSP, asd->read(rSP));
  con->dd_printf("\n");
  print_disass(PC, con);
}


/**************************************************************************/

cl_t870c_cpu::cl_t870c_cpu(class cl_uc *auc):
  cl_hw(auc, HW_DUMMY, 0, "cpu")
{
  uc= (class cl_t870c *)auc;
}

int
cl_t870c_cpu::init(void)
{
  cl_hw::init();
  psw= register_cell(uc->asd, 0x3f);
  return 0;
}

void
cl_t870c_cpu::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;
  if (cell == psw)
    {
      *val= uc->rPSW;
    }
}

t_mem
cl_t870c_cpu::read(class cl_memory_cell *cell)
{
  t_mem v= cell->get();
  if (conf(cell, NULL))
    return v;
  if (cell == psw)
    {
      v= uc->rPSW;
    }
  return v;
}

t_mem
cl_t870c_cpu::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  switch ((enum t870c_cpu_cfg)addr)
    {
    case t870c_sp_limit:
      if (val)
	uc->sp_limit= *val & 0xffff;
      return uc->sp_limit;
      break;
    default:
      if (val)
	cell->set(*val);
    }
  return cell->get();
}

const char *
cl_t870c_cpu::cfg_help(t_addr addr)
{
  switch (addr)
    {
    case t870c_sp_limit:
      return "Stack overflows when SP reaches this limit";
    }
  return "Not used";
}


/* End of tlcs.src/t870c.cc */
