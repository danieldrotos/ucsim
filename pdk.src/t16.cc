/*
 * Simulator of microcontrollers (t16.cc)
 *
 * Copyright (C) 2020,2024 Drotos Daniel, Talker Bt.
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

#include "t16cl.h"


cl_t16::cl_t16(class cl_uc *auc, const char *aname):
  cl_hw(auc, HW_TIMER, 0, aname)
{
}

int
cl_t16::init(void)
{
  cl_hw::init();

  uc->mk_mvar(cfg, t16_cnt, "T16", cfg_help(t16_cnt));
  
  return 0;
}

const char *
cl_t16::cfg_help(t_addr addr)
{
  switch ((enum t16_cfg)addr)
    {
    case t16_on: return "Turn ticking of T16 on/off (bool, RW)";
    case t16_cnt: return "T16 counter value (RW)";
    case t16_nuof: return "";
    }
  return "Not used";
}

void
cl_t16::reset(void)
{
  cnt= 0;
}

void
cl_t16::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;
  if (cell == mod)
    {
    }
  cell->set(*val);
}

t_mem
cl_t16::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  switch (addr)
    {
    case t16_on: // turn this HW on/off
      if (val)
	on= *val;
      else
	cell->set(on?1:0);
      break;
    default:
      if (val)
	cnt= *val & 0xffff;
      else
	cell->set(cnt);
      break;
    }
    return cell->get();
}

int
cl_t16::tick(int cycles)
{
  cnt+= cycles;
  return 0;
}

void
cl_t16::print_info(class cl_console_base *con)
{
  con->dd_printf("cnt= %5u\n", cnt);
}


/* End of pdk.src/t16.cc */
