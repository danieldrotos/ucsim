/*
 * Simulator of microcontrollers (port.cc)
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

#include <stdio.h>
#include <ctype.h>

// cmd
#include "argcl.h"

// local

#include "portcl.h"


cl_port::cl_port(class cl_uc *auc, int aid):
  cl_hw(auc, HW_PORT, aid, "port")
{
  base= 0xc010;
  cra= new cl_memory_cell(8);
  ddra= new cl_memory_cell(8);
  ora= new cl_memory_cell(8);
  ina= new cl_memory_cell(8);
  crb= new cl_memory_cell(8);
  ddrb= new cl_memory_cell(8);
  orb= new cl_memory_cell(8);
  inb= new cl_memory_cell(8);
}

cl_port::cl_port(class cl_uc *auc, int aid, t_addr the_addr):
  cl_hw(auc, HW_PORT, aid, "port")
{
  base= the_addr;
  cra= new cl_memory_cell(8);
  ddra= new cl_memory_cell(8);
  ora= new cl_memory_cell(8);
  ina= new cl_memory_cell(8);
  crb= new cl_memory_cell(8);
  ddrb= new cl_memory_cell(8);
  orb= new cl_memory_cell(8);
  inb= new cl_memory_cell(8);
}

int
cl_port::init(void)
{
  cl_hw::init();

  rs[0]= register_cell(uc->rom, base+0);
  rs[1]= register_cell(uc->rom, base+1);
  rs[2]= register_cell(uc->rom, base+2);
  rs[3]= register_cell(uc->rom, base+3);

  on= 1;
  
  return(0);
}

void
cl_port::reset(void)
{
  cra->write(0);
  ddra->write(0);
  ora->write(0);
  crb->write(0);
  ddrb->write(0);
  orb->write(0);
}

const char *
cl_port::cfg_help(t_addr addr)
{
  switch ((enum port_cfg)addr)
    {
    case port_on	: return "Turn/get on/off state (bool, RW)";
    case port_base	: return "Base address of the port (int, RW)";
    case port_cra	: return "Control Register A (int, RW)";
    case port_ddra	: return "Data Direction Register A (int, RW)";
    case port_ora	: return "Peripheral Register A (int, RW)";
    case port_pin_a	: return "Outside value of port A pins (int, RW)";
    case port_crb	: return "Control Register B (int, RW)";
    case port_ddrb	: return "Data Direction Register B (int, RW)";
    case port_orb	: return "Peripheral Register B (int, RW)";
    case port_pin_b	: return "Outside value of port B pins (int, RW)";
    }
  return "Not used";
}

class cl_memory_cell *
cl_port::reg(class cl_memory_cell *cell_rs)
{
  if (cell_rs == rs[0])
    {
      if (cra->get() & 2)
	{
	  return ora;
	}
      else
	{
	  return ddra;
	}
    }
  else if (cell_rs == rs[1])
    {
      return cra;
    }
  else if (cell_rs == rs[2])
    {
      if (crb->get() & 2)
	{
	  return orb;
	}
      else
	{
	  return ddrb;
	}
    }
  else if (cell_rs == rs[3])
    {
      return crb;
    }
  return NULL;
}

t_mem
cl_port::read(class cl_memory_cell *cell)
{
  class cl_memory_cell *r= reg(cell);
  conf(cell, NULL);
  if (r != NULL)
    return r->get();
  return cell->get();
}

void
cl_port::write(class cl_memory_cell *cell, t_mem *val)
{
  class cl_memory_cell *r= reg(cell);
  conf(cell, val);
  if (!r)
    return;
  r->write(*val);
}

t_mem
cl_port::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  t_mem v;
  class cl_memory_cell *r= NULL;
  switch ((enum port_cfg)addr)
    {
    case port_on	:  // turn this HW on/off
      if (val)
	{
	  if (*val)
	    on= true;
	  else
	    on= false;
	}
      v= on?1:0;
      cell->set(v);
      break;
    case port_base:
      if (val)
	{
	  int i;
	  if (uc->rom->valid_address(*val))
	    {
	      for (i= 0; i < 3; i++)
		unregister_cell(rs[i]);
	      base= *val;
	      init();
	    }
	}
      cell->set(base);
      break;
    case port_cra	: r= cra; break;
    case port_ddra	: r= ddra; break;
    case port_ora	: r= ora; break;
    case port_pin_a	: r= ina; break;
    case port_crb	: r= crb; break;
    case port_ddrb	: r= ddrb; break;
    case port_orb	: r= orb; break;
    case port_pin_b	: r= inb; break;
    }
  if (r)
    {
      if (val)
	r->write(*val);
      v= r->get();
      cell->set(v);
    }
  v= cell->get();
  return v;
}


/* End of m6809.src/port.cc */
