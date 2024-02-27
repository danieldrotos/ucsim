/*
 * Simulator of microcontrollers (fpga.cc)
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

#include "globals.h"

#include "fpgacl.h"


/*
                                                                        LED
  -------------------------------------------------------------------------
*/

cl_led::cl_led(class cl_fpga *the_fpga, int ax, int ay, uint32_t amask):
  cl_base()
{
  fpga= the_fpga;
  x= ax;
  y= ay;
  mask= amask;
}

void
cl_led::refresh(bool force)
{
  class cl_hw_io *io= fpga->get_io();
  uint32_t act= fpga->pb->get() & mask;
  uint32_t last= fpga->lb & mask;
  if (force || (act != last))
    {
      io->tu_go(x, y);
      if (act)
	{
	  io->dd_cprintf("led_on", "@");
	  fpga->lb|= mask;
	}
      else
	{
	  io->dd_cprintf("led_off", ".");
	  fpga->lb&= ~mask;
	}
    }
}

void
cl_led::draw(void)
{
}


/*
                                                                       FPGA
  -------------------------------------------------------------------------
*/

cl_fpga::cl_fpga(class cl_uc *auc, int aid, chars aid_string):
  cl_hw(auc, HW_DUMMY, aid, aid_string)
{
  int i;
  for (i= 0; i<16; i++)
    leds[i]= NULL;
  pa= (class cl_cell32 *)register_cell(uc->rom, 0xff00);
  pb= (class cl_cell32 *)register_cell(uc->rom, 0xff01);
  pc= (class cl_cell32 *)register_cell(uc->rom, 0xff02);
  pd= (class cl_cell32 *)register_cell(uc->rom, 0xff03);
  pi= (class cl_cell32 *)register_cell(uc->rom, 0xff20);
  pj= (class cl_cell32 *)register_cell(uc->rom, 0xff10);
  la= pa->R();
  lb= pb->R();
  lc= pc->R();
  ld= pd->R();
  li= pi->R();
  lj= pj->R();
}


int
cl_fpga::init(void)
{
  mk_leds();
  return 0;
}


void
cl_fpga::make_io()
{
  if (!io)
    {
      io= new cl_hw_io(this);
      io->init();
      application->get_commander()->add_console(io);
    }
}


void
cl_fpga::new_io(class cl_f *f_in, class cl_f *f_out)
{
  cl_hw::new_io(f_in, f_out);
  io->tu_mouse_on();
  io->dd_printf("\033[2 q");
  if (f_in)
    f_in->set_escape(true);
}


bool
cl_fpga::proc_input(void)
{
  return cl_hw::proc_input();
}


bool
cl_fpga::handle_input(int c)
{
  int ret= cl_hw::handle_input(c); // handle default keys
  return ret;
}


void
cl_fpga::refresh_leds(bool force)
{
  int i;
  for (i=0; i<16; i++)
    {
      if (leds[i])
	leds[i]->refresh(force);
    }
}


void
cl_fpga::refresh_display(bool force)
{
  int i;
  
  if (!io)
    return;

  //io->tu_hide();
  refresh_leds(force);
}


void
cl_fpga::draw_display(void)
{
  int i;
  if (!io)
    return;
  io->tu_hide();
  io->dd_color("led_on");
  io->tu_cls();
  cl_hw::draw_display();
  draw_fpga();
  for (i=0; i<16; i++)
    if (leds[i])
      leds[i]->draw();
  refresh_display(true);
}


t_mem
cl_fpga::read(class cl_memory_cell *cell)
{
  if (cell == pi)
    {
    }
  conf(cell, NULL);
  return cell->get();
}

void
cl_fpga::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;
  if (cell == pa)
    {
    }
  else if (cell == pb)
    {
      refresh_leds(false);
    }
  cell->set(*val);
}


/*
                                                                 Nexys4 DDR
  -------------------------------------------------------------------------
*/

cl_n4::cl_n4(class cl_uc *auc, int aid, chars aid_string):
  cl_fpga(auc, aid, aid_string)
{
  basey= 13; // row of leds
  board= "Nexys4DDR";
}


void
cl_n4::mk_leds(void)
{
  int i, m;
  for (i=0, m=1; i<16; i++, m<<=1)
    leds[i]= new cl_led(this, 2+16*3-i*3,basey, m);
}


void
cl_n4::draw_fpga(void)
{
  int i;
  io->tu_go(1,4);
  io->dd_printf("%s", board.c_str());
  for (i=0; i<16; i++)
    {
      io->tu_go(2+16*3-i*3-1,basey+1);
      io->dd_cprintf("ui_label", "%2d", i);
    }
}


/*
                                                                    Boolean
  -------------------------------------------------------------------------
*/

cl_bool::cl_bool(class cl_uc *auc, int aid, chars aid_string):
  cl_n4(auc, aid, aid_string)
{
}


void
cl_bool::draw_fpga(void)
{
  cl_n4::draw_fpga();
}

/* End of p1516.src/fpga.cc */
