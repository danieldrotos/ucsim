/*
 * Simulator of microcontrollers (serial.cc)
 *
 * Copyright (C) 1999,99 Drotos Daniel, Talker Bt.
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

#include "ddconfig.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <strings.h>

// prj
#include "globals.h"
#include "utils.h"

// cmd
#include "cmdutil.h"

// local
#include "serialcl.h"


cl_serial::cl_serial(class cl_uc *auc,
		     t_addr abase,
		     int ttype):
  cl_hw(auc, HW_UART, 0, "uart")
{
  fin= 0;
  fout= 0;
  listener= 0;
  
}


cl_serial::~cl_serial(void)
{
  if (fout)
    delete fout;
  if (fin)
    delete fin;
  delete serial_in_file_option;
  delete serial_out_file_option;
}

int
cl_serial::init(void)
{
  char *s;
  int i;
    
  set_name("stm8_uart");
  for (i= 0; i < 12; i++)
    {
      regs[i]= register_cell(uc->rom, base+i, NULL, wtd_restore_write);
    }
  set_div();
  
  s= format_string("serial%d_in_file", id);
  serial_in_file_option= new cl_optref(this);
  serial_in_file_option->init();
  serial_in_file_option->use(s);
  free(s);
  s= format_string("serial%d_out_file", id);
  serial_out_file_option= new cl_optref(this);
  serial_out_file_option->init();
  serial_out_file_option->use(s);
  free(s);
  s= format_string("serial%d_port", id);
  serial_port_option= new cl_optref(this);
  serial_port_option->init();
  class cl_option *o= serial_port_option->use(s);
  free(s);
  if (o)
    {
      int port= serial_port_option->get_value((long)0);
      if (port > 0)
	listener= new cl_serial_listener(port, application, this);
      class cl_commander_base *c= application->get_commander();
      c->add_console(listener);
    }
  
  char *f_serial_in = (char*)serial_in_file_option->get_value((char*)0);
  char *f_serial_out= (char*)serial_out_file_option->get_value((char*)0);
  if (f_serial_in)
    {
      if (f_serial_in[0] == '\001')
	fin= (class cl_f *)(strtoll(&f_serial_in[1], 0, 0));
      else
	fin= mk_io(chars(f_serial_in), cchars("r"));
      //fin->save_attributes();
      fin->set_terminal();
      if (!fin->tty)
	fprintf(stderr, "Warning: serial input interface connected to a "
		"non-terminal file.\n");
    }
  else
    fin= mk_io(chars(""), chars(""));
  if (f_serial_out)
    {
      if (f_serial_out[0] == '\001')
	fout= (class cl_f *)(strtoll(&f_serial_out[1], 0, 0));
      else
	fout= mk_io(chars(f_serial_out), "w");
      //fout->save_attributes();
      fout->set_terminal();
      if (!fout->tty)
	fprintf(stderr, "Warning: serial output interface connected to a "
		"non-terminal file.\n");
    }
  else
    fout= mk_io(chars(""), chars(""));

  return(0);
}


void
cl_serial::new_hw_added(class cl_hw *new_hw)
{
  /*  if (new_hw->cathegory == HW_TIMER &&
      new_hw->id == 2)
    {
      there_is_t2= DD_TRUE;
      t_mem d= sfr->get(T2CON);
      t2_baud= d & (bmRCLK | bmTCLK);
    }
  */
}

void
cl_serial::added_to_uc(void)
{
/*
  uc->it_sources->add(new cl_it_src(uc, IE, bmES , SCON, bmTI , 0x0023, false, false,
				    "serial transmit", 6));
  uc->it_sources->add(new cl_it_src(uc, IE, bmES , SCON, bmRI , 0x0023, false, false,
				    "serial receive", 6));
*/
}

t_mem
cl_serial::read(class cl_memory_cell *cell)
{
  return cell->get();
}

void
cl_serial::write(class cl_memory_cell *cell, t_mem *val)
{
  if ((cell == regs[brr1]) ||
      (cell == regs[brr2]))
    set_div();
  if ((cell == regs[cr1]) ||
      (cell == regs[cr2]))
    set_ctrl();
}

int
cl_serial::tick(int cycles)
{
  char c;

  if ((mcnt+= cycles) >= div)
    {
      mcnt-= div;
      if (s_sending)
	s_tr_bit++;
      if (s_receiving)
	s_rec_bit++;
    }
  else
    return 0;
  
  if (s_sending &&
      (s_tr_bit >= _bits))
    {
      s_sending= false;
      if (fout)
	{
	  fout->write((char*)(&s_out), 1);
	}
      s_tr_bit-= _bits;
    }
  if (() &&
      fin &&
      !s_receiving)
    {
      if (fin->input_avail())
	{
	  s_receiving= DD_TRUE;
	  s_rec_bit= 0;
	  s_rec_tick= s_rec_t1= 0;
	}
    }
  if (s_receiving &&
      (s_rec_bit >= _bits))
    {
      if (fin->read(&c, 1) == 1)
	{
	  s_in= c;
	  sbuf->set(s_in);
	  received(c);
	}
      s_receiving= DD_FALSE;
      s_rec_bit-= _bits;
    }
  
  int l;
  s_tr_tick+= (l= cycles * uc->clock_per_cycle());
  s_rec_tick+= l;
  return(0);
}

void
cl_serial::received(int c)
{
}

void
cl_serial::reset(void)
{
}

void
cl_serial::new_io(class cl_f *f_in, class cl_f *f_out)
{
  if (fin)
    delete fin;
  if (fout)
    delete fout;
  fin= f_in;
  fout= f_out;
  //printf("usart[%d] now using fin=%d fout=%d\n", id, fin->file_id, fout->file_id);
}


void
cl_serial::set_div()
{
  uint8_t b1= regs[bbr1]->get();
  uint8_t b2= regs[bbr2]->get();
  div= ((((b2&0xf0)<<4) + b1)<<4) + (b2&0xf);
  mcnt= 0;
}

void
cl_serial::set_ctrl()
{
  
}


cl_serial_listener::cl_serial_listener(int serverport, class cl_app *the_app,
				       class cl_serial *the_serial):
  cl_listen_console(serverport, the_app)
{
  serial_hw= the_serial;
}

int
cl_serial_listener::proc_input(class cl_cmdset *cmdset)
{
  class cl_f *i, *o;

  srv_accept(fin, &i, &o);
  serial_hw->new_io(i, o);
  return 0;
}


/* End of stm8.src/serial.cc */
