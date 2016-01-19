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
#ifdef HAVE_TERMIOS_H
#include <termios.h>
#endif
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <strings.h>
#include <assert.h>

// prj
#include "globals.h"
#include "utils.h"

// cmd
#include "cmdutil.h"

// local
#include "serialcl.h"
#include "regs51.h"
#include "uc51cl.h"


cl_serial::cl_serial(class cl_uc *auc):
  cl_hw(auc, HW_UART, 0, "uart")
{
  //serial_in= serial_out= 0;
  fin= 0;
  fout= 0;
}

cl_serial::~cl_serial(void)
{
  if (fout/*serial_out*/)
    {
#ifdef HAVE_TERMIOS_H
      if (fout->tty/*isatty(fileno(serial_out))*/)
	  tcsetattr(fout->file_id/*fileno(serial_out)*/, TCSANOW, &saved_attributes_out);
#endif
      //fclose(serial_out);
      delete fout;
    }
  if (fin/*serial_in*/)
    {
#ifdef HAVE_TERMIOS_H
      if (fin->tty/*isatty(fileno(serial_in))*/)
	tcsetattr(fin->file_id/*fileno(serial_in)*/, TCSANOW, &saved_attributes_in);
#endif
      //fclose(serial_in);
      delete fin;
    }
  delete serial_in_file_option;
  delete serial_out_file_option;
}

int
cl_serial::init(void)
{
#ifdef HAVE_TERMIOS_H
  int i;
  struct termios tattr;
#endif
  char *s;
  
  set_name("mcs51_uart");
  sfr= uc->address_space(MEM_SFR_ID);
  if (sfr)
    {
      //sbuf= sfr->register_hw(SBUF, this, 0);
      //pcon= sfr->register_hw(PCON, this, 0);
      //scon= sfr->register_hw(SCON, this, 0);
      register_cell(sfr, SBUF, &sbuf, wtd_restore_write);
      register_cell(sfr, PCON, &pcon, wtd_restore_write);
      register_cell(sfr, SCON, &scon, wtd_restore_write);
    }

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
  
  /*FILE*/char *f_serial_in = (/*FILE*/char*)serial_in_file_option->get_value((/*void*/char*)0);
  /*FILE*/char *f_serial_out= (/*FILE*/char*)serial_out_file_option->get_value((/*void*/char*)0);
  if (f_serial_in)
    {
      if (f_serial_in[0] == '\001')
	fin= (class cl_f *)(strtol(&f_serial_in[1], 0, 0));
      else
	fin= mk_io(chars(f_serial_in), cchars("r"));
      // making `serial' unbuffered
      //if (setvbuf(fin->file_f, NULL, _IONBF, 0)) perror("Unbuffer serial input channel");
#if defined HAVE_TERMIOS_H
      // setting O_NONBLOCK
      if ((i= fcntl(fin->file_id, F_GETFL, 0)) < 0)
	perror("Get flags of serial input");
      i|= O_NONBLOCK;
      if (fcntl(fin->file_id, F_SETFL, i) < 0)
	perror("Set flags of serial input");
      // switching terminal to noncanonical mode
      if (isatty(fin->file_id))
	{
	  tcgetattr(fin->file_id, &saved_attributes_in);
	  tcgetattr(fin->file_id, &tattr);
	  tattr.c_lflag&= ~(ICANON|ECHO);
	  tattr.c_cc[VMIN] = 1;
	  tattr.c_cc[VTIME]= 0;
	  tcsetattr(fin->file_id, TCSAFLUSH, &tattr);
	}
      else
#endif
	fprintf(stderr, "Warning: serial input interface connected to a "
		"non-terminal file.\n");
    }
  else
    fin= mk_io(chars(""), chars(""));
  if (f_serial_out)
    {
      if (f_serial_out[0] == '\001')
	fout= (class cl_f *)(strtol(&f_serial_out[1], 0, 0));
      else
	fout= mk_io(chars(f_serial_out), "w");
      // making `serial' unbuffered
      //if (setvbuf(fout->file_f, NULL, _IONBF, 0)) perror("Unbuffer serial output channel");
#if defined HAVE_TERMIOS_H
      // setting O_NONBLOCK
      if ((i= fcntl(fout->file_id, F_GETFL, 0)) < 0)
	perror("Get flags of serial output");
      i|= O_NONBLOCK;
      if (fcntl(fout->file_id, F_SETFL, i) < 0)
	perror("Set flags of serial output");
      // switching terminal to noncanonical mode
      if (isatty(fout->file_id))
	{
	  tcgetattr(fout->file_id, &saved_attributes_out);
	  tcgetattr(fout->file_id, &tattr);
	  tattr.c_lflag&= ~(ICANON|ECHO);
	  tattr.c_cc[VMIN] = 1;
	  tattr.c_cc[VTIME]= 0;
	  tcsetattr(fout->file_id, TCSAFLUSH, &tattr);
	}
      else
#endif
	fprintf(stderr, "Warning: serial output interface connected to a "
		"non-terminal file.\n");
    }
  else
    fout= mk_io(chars(""), chars(""));
  class cl_hw *t2= uc->get_hw(HW_TIMER, 2, 0);
  if ((there_is_t2= t2 != 0))
    {
      t_mem d= sfr->get(T2CON);
      t2_baud= d & (bmRCLK | bmTCLK);
    }
  else
    t2_baud= DD_FALSE;

  return(0);
}

void
cl_serial::new_hw_added(class cl_hw *new_hw)
{
  if (new_hw->cathegory == HW_TIMER &&
      new_hw->id == 2)
    {
      there_is_t2= DD_TRUE;
      t_mem d= sfr->get(T2CON);
      t2_baud= d & (bmRCLK | bmTCLK);
    }
}

void
cl_serial::added_to_uc(void)
{
  uc->it_sources->add(new cl_it_src(bmES , SCON, bmTI , 0x0023, false,
				    "serial transmit", 6));
  uc->it_sources->add(new cl_it_src(bmES , SCON, bmRI , 0x0023, false,
				    "serial receive", 6));
}

t_mem
cl_serial::read(class cl_memory_cell *cell)
{
  if (cell == sbuf)
    return(s_in);
  else
    return(cell->get());
}

void
cl_serial::write(class cl_memory_cell *cell, t_mem *val)
{
  if (cell == sbuf)
    {
      s_out= *val;
      s_sending= DD_TRUE;
      s_tr_bit = 0;
      s_tr_tick= 0;
      s_tr_t1= 0;
    }
  if (cell == scon)
    {
      _mode= *val >> 6;
      _bmREN= *val & bmREN;
      _bits= 8;
      switch (_mode)
	{
	case 0:
	  _bits= 8;
	  _divby= 12;
	  break;
	case 1:
	  _bits= 10;
	  _divby= _bmSMOD?16:32;
	  break;
	case 2:
	  _bits= 11;
	  _divby= _bmSMOD?16:32;
	  break;
	case 3:
	  _bits= 11;
	  _divby= _bmSMOD?16:32;
	  break;
	}
    }
  else if (cell == pcon)
    {
      _bmSMOD= *val & bmSMOD;
      /*switch (_mode)
	{
	case 1:
	  _divby= _bmSMOD?16:32;
	  break;
	case 2:
	  _divby= _bmSMOD?16:32;
	  break;
	case 3:
	  _divby= _bmSMOD?16:32;
	  break;
	  }*/
      if (_mode)
	_divby= _bmSMOD?16:32;
    }
}

/*void
cl_serial::mem_cell_changed(class cl_m *mem, t_addr addr)
{
  t_mem d;

  d= sbuf->get();
  write(sbuf, &d);
  d= pcon->get();
  write(pcon, &d);
  d= scon->get();
  write(scon, &d);
}*/

int
cl_serial::serial_bit_cnt(void)
{
  //int divby= 12;
  int *tr_src= 0, *rec_src= 0;

  switch (_mode)
    {
    case 0:
      //divby  = 12;
      tr_src = &s_tr_tick;
      rec_src= &s_rec_tick;
      break;
    case 1:
    case 3:
      //divby  = (/*pcon->get()&bmSMOD*/_bmSMOD)?16:32;
      tr_src = &s_tr_t1;
      rec_src= &s_rec_t1;
      break;
    case 2:
      //divby  = (/*pcon->get()&bmSMOD*/_bmSMOD)?16:32;
      tr_src = &s_tr_tick;
      rec_src= &s_rec_tick;
      break;
    }
  if (t2_baud)
    _divby= 16;
  if (s_sending)
    {
      while (*tr_src >= _divby)
	{
	  (*tr_src)-= _divby;
	  s_tr_bit++;
	  //printf("serial bit sent %d\n",uc->ticks->ticks);
	}
    }
  if (s_receiving)
    {
      while (*rec_src >= _divby)
	{
	  (*rec_src)-= _divby;
	  s_rec_bit++;
	}
    }
  return(0);
}

int
cl_serial::tick(int cycles)
{
  char c;

  serial_bit_cnt(/*_mode*/);
  if (s_sending &&
      (s_tr_bit >= _bits))
    {
      s_sending= DD_FALSE;
      scon->set_bit1(bmTI);
      if (fout)
	{
	  fout->write((char*)(&s_out), 1);
	  fout->flush();
	}
      s_tr_bit-= _bits;
      //printf("serial out %d bit rems %d\n",s_tr_bit,uc->ticks->ticks);
    }
  if ((_bmREN) &&
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
  scon->set_bit1(bmRI);
}

void
cl_serial::reset(void)
{
  s_tr_t1    = 0;
  s_rec_t1   = 0;
  s_tr_tick  = 0;
  s_rec_tick = 0;
  s_in       = 0;
  s_out      = 0;
  s_sending  = DD_FALSE;
  s_receiving= DD_FALSE;
  s_rec_bit  = 0;
  s_tr_bit   = 0;
}

void
cl_serial::happen(class cl_hw *where, enum hw_event he, void *params)
{
  if (where->cathegory == HW_TIMER)
    {
      if (where->id == 1)
	{
	  //printf("serial: timer overflowed %ld\n", uc->ticks->ticks);
	  s_rec_t1++;
	  s_tr_t1++;
	}
      if (where->id == 2 /*&& there_is_t2*/)
	{
	  switch (he)
	    {
	    case EV_T2_MODE_CHANGED:
	      {
		if (!t2_baud)
		  s_rec_t1= s_tr_t1= 0;
		t_mem *d= (t_mem *)params;
		t2_baud= *d & (bmRCLK | bmTCLK);
		break;
	      }
	    case EV_OVERFLOW:
	      //printf("T2 baud ov r%d t%d\n",s_rec_t1,s_tr_t1);
	      s_rec_t1++;
	      s_tr_t1++;
	      break;
	    default: break;
	    }
	}
    }
}

void
cl_serial::print_info(class cl_console_base *con)
{
  const char *modes[]= { "Shift, fixed clock",
			 "8 bit UART timer clocked",
			 "9 bit UART fixed clock",
			 "9 bit UART timer clocked" };
  int sc= scon->get();

  con->dd_printf("%s[%d]", id_string, id);
  int mode= (sc&(bmSM0|bmSM1))>>6;
  con->dd_printf(" %s", modes[mode]);
  if (mode == 1 || mode == 2)
    con->dd_printf(" (timer%d)", (t2_baud)?2:1);
  con->dd_printf(" MultiProc=%s",
		 (mode&2)?((sc&bmSM2)?"ON":"OFF"):"none");
  con->dd_printf(" irq=%s", (sfr->get(IE)&bmES)?"en":"dis");
  con->dd_printf(" prio=%d", uc->it_priority(bmPS));
  con->dd_printf("\n");

  con->dd_printf("Receiver");
  con->dd_printf(" %s", (sc&bmREN)?"ON":"OFF");
  con->dd_printf(" RB8=%c", (sc&bmRB8)?'1':'0');
  con->dd_printf(" irq=%c", (sc&bmRI)?'1':'0');
  con->dd_printf("\n");

  con->dd_printf("Transmitter");
  con->dd_printf(" TB8=%c", (sc&bmTB8)?'1':'0');
  con->dd_printf(" irq=%c", (sc&bmTI)?'1':'0');
  con->dd_printf("\n");
  /*con->dd_printf("s_rec_t1=%d s_rec_bit=%d s_rec_tick=%d\n",
		 s_rec_t1, s_rec_bit, s_rec_tick);
  con->dd_printf("s_tr_t1=%d s_tr_bit=%d s_tr_tick=%d\n",
		 s_tr_t1, s_tr_bit, s_tr_tick);
		 con->dd_printf("divby=%d bits=%d\n", _divby, _bits);*/
}


/* End of s51.src/serial.cc */
