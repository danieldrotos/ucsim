/*
 * Simulator of microcontrollers (port.cc)
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

#include "portcl.h"


/* OUTPUT port */

cl_porto::cl_porto(class cl_uc *auc, t_addr the_addr, const char *aname):
  cl_hw(auc, HW_PORT, 0, aname)
{
  addr= the_addr;
  set_name(aname);
}

int
cl_porto::init(void)
{
  cl_hw::init();
  dr= register_cell(uc->rom, addr);
  dr->decode((t_mem*)&value);
  
  cl_var *v;
  chars s= chars();
  s= get_name();
  s+= "_dr";
  v= new cl_var(s, uc->rom, addr, chars("", "Data register of %s", get_name()));
  v->init();
  uc->vars->add(v);
  
  v= new cl_var(get_name(), uc->rom, addr, chars("", "Data register of %s", get_name()));
  v->init();
  uc->vars->add(v);

  return 0;
}

void
cl_porto::reset(void)
{
  value= 0;
}

char *
cl_porto::cfg_help(t_addr addr)
{
  switch (addr)
    {
    case port_on: return (char*)"Turn/get on/off state (bool, RW)";
    case port_pin: return (char*)"Outside value of port pins (int, RW)";
    case port_value: return (char*)"Value of the port (int, RO)";
    }
  return (char*)"Not used";
}

void
cl_porto::write(class cl_memory_cell *cell, t_mem *val)
{
  if (cell == dr)
    {
      cell->set(*val);
    }

  conf(cell, val);
}


t_mem
cl_porto::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  switch ((enum port_cfg)addr)
    {
    case port_on: // turn this HW on/off
      if (val)
	{
	  if (*val)
	    on= true;
	  else
	    on= false;
	}
      else
	{
	  cell->set(on?1:0);
	}
      break;
    case port_pin: // get/set PINS
      break;
    case port_value:
      if (val)
	*val= dr->get();//cell->set(*val);
      break;
    }
  return cell->get();
}

void
cl_porto::print_info(class cl_console_base *con)
{
  u32_t m;
  t_mem d= value;//dr->get();
  con->dd_printf("dr->data= %p\n", dr->get_data());
  con->dd_printf("&value  = %p\n", &value);
  con->dd_printf("value   = %08x\n", value);
  con->dd_printf("get     = %08x\n", dr->get());
  con->dd_printf("read    = %08x\n", dr->read());
  con->dd_printf("%s at %04x %08x\n", get_name(), addr, d);
  for (m= 0x80000000; m; m>>= 1)
    {
      //if (d & m)
	con->dd_printf("%c", (d & m)?'1':'0');
	//else 	con->dd_printf("-");
    }
  con->dd_printf("\n");
  print_cfg_info(con);
}


/* INPUT port */

cl_porti::cl_porti(class cl_uc *auc, t_addr the_addr, const char *aname):
  cl_porto(auc, the_addr, aname)
{
  value= 0;
}

int
cl_porti::init(void)
{
  cl_porto::init();

  cl_var *v;
  chars s= chars();
  s= get_name();
  s+= "_pins";
  v= new cl_var(s, cfg, port_pin, cfg_help(port_pin));
  v->init();
  uc->vars->add(v);

  return 0;
}

void
cl_porti::write(class cl_memory_cell *cell, t_mem *val)
{
  if (cell == dr)
    {
      *val= value;
    }

  conf(cell, val);
}


t_mem
cl_porti::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  switch ((enum port_cfg)addr)
    {
    case port_pin: // get/set PINS
      if (val)
	value= *val;
      else
	return value;
      break;
    default:
      return cl_porto::conf_op(cell, addr, val);
    }
  return cell->get();
}

/* End of p1516.src/port.cc */

