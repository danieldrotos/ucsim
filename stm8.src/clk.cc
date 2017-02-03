/*
 * Simulator of microcontrollers (stm8.src/clk.cc)
 *
 * Copyright (C) 2017,17 Drotos Daniel, Talker Bt.
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

#include "clkcl.h"


cl_clk::cl_clk(class cl_uc *auc):
       cl_hw(auc, HW_CLOCK, 0, "clk")
{
  base= 0x50C0;
  ckdivr= NULL;
  pckenr1= NULL;
  pckenr2= NULL;
  pckenr3= NULL;
}

int
cl_clk::init(void)
{
  cl_hw::init();

  make_partner(HW_TIMER, 1);
  make_partner(HW_TIMER, 2);
  make_partner(HW_TIMER, 3);
  make_partner(HW_TIMER, 4);
  make_partner(HW_TIMER, 5);
  make_partner(HW_TIMER, 6);
  
  return 0;
}

void
cl_clk::write(class cl_memory_cell *cell, t_mem *val)
{
  cl_clk_event e;
  
  if ((cell == pckenr1) ||
      (cell == pckenr2) ||
      (cell == pckenr3))
    {
      cell->set(*val);
      e.set(HW_TIMER, 1);
      inform_partners(tim(e.id++)?EV_CLK_ON:EV_CLK_OFF, &e);
      inform_partners(tim(e.id++)?EV_CLK_ON:EV_CLK_OFF, &e);
      inform_partners(tim(e.id++)?EV_CLK_ON:EV_CLK_OFF, &e);
      inform_partners(tim(e.id++)?EV_CLK_ON:EV_CLK_OFF, &e);
      inform_partners(tim(e.id++)?EV_CLK_ON:EV_CLK_OFF, &e);
      inform_partners(tim(e.id  )?EV_CLK_ON:EV_CLK_OFF, &e);
    }
}


/* SAF */

cl_clk_saf::cl_clk_saf(class cl_uc *auc):
  cl_clk(auc)
{
}

int
cl_clk_saf::init(void)
{
  cl_clk::init();
  ckdivr= register_cell(uc->rom, base+6);
  pckenr1= register_cell(uc->rom, base+7);
  pckenr2= register_cell(uc->rom, base+10);
  return 0;
}

void
cl_clk_saf::reset(void)
{
  //ickr->write(0x01);
  //eckr->write(0);
  //cmsr->write(0xe1);
  //swr->write(0xe1);
  //swcr->write(0);
  ckdivr->write(0x18);
  pckenr1->write(0xff);
  //cssr->write(0);
  //ccor->write(0);
  pckenr2->write(0xff);
  //hsitrimr->write(0);
  //swimccr->write(0);
}

bool
cl_clk_saf::tim(int id)
{
  switch (id)
    {
    case 1:
      return pckenr1 && (pckenr1->get() & 0x80);
    case 2: case 5:
      return pckenr1 && (pckenr1->get() & 0x20);
    case 3:
      return pckenr1 && (pckenr1->get() & 0x40);
    case 4: case 6:
      return pckenr1 && (pckenr1->get() & 0x10);
    }
  return false;
}

/* ALL */

cl_clk_all::cl_clk_all(class cl_uc *auc):
  cl_clk(auc)
{
}

int
cl_clk_all::init(void)
{
  cl_clk::init();
  ckdivr= register_cell(uc->rom, base+0);
  pckenr1= register_cell(uc->rom, base+3);
  pckenr2= register_cell(uc->rom, base+4);
  pckenr3= register_cell(uc->rom, base+16);
  return 0;
}

bool
cl_clk_all::tim(int id)
{
  switch (id)
    {
    case 1:
      return pckenr2 && (pckenr2->get() & 0x01);
    case 2:
      return pckenr1 && (pckenr1->get() & 0x01);
    case 3:
      return pckenr1 && (pckenr1->get() & 0x02);
    case 4:
      return pckenr1 && (pckenr1->get() & 0x04);
    case 5:
      return pckenr3 && (pckenr3->get() & 0x02);
    }
  return false;
}


/* L101 */

cl_clk_l101::cl_clk_l101(class cl_uc *auc):
  cl_clk(auc)
{
}

int
cl_clk_l101::init(void)
{
  cl_clk::init();
  ckdivr= register_cell(uc->rom, base+0);
  pckenr1= register_cell(uc->rom, base+3);
  return 0;
}

bool
cl_clk_l101::tim(int id)
{
  switch (id)
    {
    case 2:
      return pckenr1 && (pckenr1->get() & 0x01);
    case 3:
      return pckenr1 && (pckenr1->get() & 0x02);
    case 4:
      return pckenr1 && (pckenr1->get() & 0x04);
    }
  return false;
}


/* End of stm8.src/clk.cc */
