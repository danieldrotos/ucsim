/*
 * Simulator of microcontrollers (i8048.cc)
 *
 * Copyright (C) 2022 Drotos Daniel
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

#include <ctype.h>

#include "utils.h"

#include "dregcl.h"

#include "i8048cl.h"


t_mem
cl_flag48_op::write(t_mem val)
{
  val|= 0x08;
  return val;
}


/*
 * CPU
 */

cl_i8048::cl_i8048(class cl_sim *asim):
  cl_i8020(asim)
{
  rom_size= 1024;
  ram_size= 64;
  info_ch= '8';
  inner_rom= rom_size;
}

cl_i8048::cl_i8048(class cl_sim *asim,
		   unsigned int rom_siz,
		   unsigned int ram_siz):
  cl_i8020(asim)
{
  rom_size= rom_siz;
  ram_size= ram_siz;
  info_ch= '8';
  inner_rom= rom_size;
}

int
cl_i8048::init(void)
{
  cl_i8020::init();
  return 0;
}

void
cl_i8048::mk_hw_elements(void)
{
  cl_uc::mk_hw_elements();
  class cl_hw *h;
  
  timer= new cl_timer(this);
  timer->init();
  add_hw(timer);

  ints= new cl_ints(this);
  ints->init();
  add_hw(ints);
  
  bus= new cl_bus(this);
  bus->init();
  add_hw(bus);

  p0= NULL;
  p1= new cl_qport(this, 1, ports, 1, port_8bit);
  p1->init();
  add_hw(p1);
  p2= new cl_p2(this, 2, ports, 2, port_8bit);
  p2->init();
  add_hw(p2);
  
  pext= new cl_pext(this, 0, ports, 4, p2);
  pext->init();
  add_hw(pext);

  h= new cl_dreg(this, 0, "dreg");
  h->init();
  add_hw(h);

  mk_dport();
}

class cl_memory_operator *
cl_i8048::make_flagop(void)
{
  class cl_memory_operator *o;
  o= new cl_flag48_op(cpsw);
  o->init();
  o->set_name("MCS48 flag operator");
  return o;
}

void
cl_i8048::make_cpu_hw(void)
{
  cpu= new cl_i8048_cpu(this);
  add_hw(cpu);
  cpu->init();
}

void
cl_i8048::decode_regs(void)
{
  int i;
  cl_banker *b= new cl_banker(aspsw, 0, flagBS, //0,
			      regs, 0, 7);
  b->init();
  b->set_name("def_regs_banker");
  regs->decoders->add(b);
  b->add_bank(0, memory("iram_chip"), 0);
  b->add_bank(1, memory("iram_chip"), 24);
  cpsw->write(0);
  for (i= 0; i < 8; i++)
    R[i]= (cl_cell8*)regs->get_cell(i);
}

u8_t
cl_i8048::movxrd(u8_t addr)
{
  bus->latch(addr);
  return xram->read(addr);
}

void
cl_i8048::movxwr(u8_t addr, u8_t val)
{
  xram->write(addr, val);
  bus->latch(val);
}

int
cl_i8048::orlbus(u8_t i8)
{
  RD;
  WR;
  bus->orl(i8);
  return resGO;
}

int
cl_i8048::anlbus(u8_t i8)
{
  RD;
  WR;
  bus->anl(i8);
  return resGO;
}

int
cl_i8048::call(MP)
{
  u16_t a= (code&0xe0)<<3;
  a+= fetch();
  if (A11) a|= 0x800;
  push(true);
  PC= a;
  return resGO;
}

int
cl_i8048::OUTLB(MP)
{
  bus->latch(rA);
  return resGO;
}

int
cl_i8048::INS(MP)
{
  cA.W(bus->cfg_read(tbus_in));
  return resGO;
}


int
cl_i8048::ORLP1I8(MP)
{
  u8_t i8= fetch();
  u8_t v= p1->get_odr();
  RD;
  v|= i8;
  ports->write(1, v);
  WR;
  return resGO;
}

int
cl_i8048::ORLP2I8(MP)
{
  u8_t i8= fetch();
  u8_t v= p2->get_odr();
  RD;
  v|= i8;
  ports->write(2, v);
  WR;
  return resGO;
}


int
cl_i8048::ANLP1I8(MP)
{
  u8_t i8= fetch();
  u8_t v= p1->get_odr();
  RD;
  v&= i8;
  ports->write(1, v);
  WR;
  return resGO;
}

int
cl_i8048::ANLP2I8(MP)
{
  u8_t i8= fetch();
  u8_t v= p2->get_odr();
  RD;
  v&= i8;
  ports->write(2, v);
  WR;
  return resGO;
}

int
cl_i8048::RETR(MP)
{
  PC= pop(true);
  return resGO;
}



cl_i8048_cpu::cl_i8048_cpu(class cl_uc *auc):
  cl_i8020_cpu(auc)
{
}


/* End of i8048.src/i8048.cc */
