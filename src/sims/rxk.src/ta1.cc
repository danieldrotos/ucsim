/*
 * Simulator of microcontrollers (ta1.cc)
 *
 * Copyright (C) 2026 Drotos Daniel
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

#include "rtypes.h"

#include "ta1cl.h"


cl_ta1::cl_ta1(class cl_uc *auc, bool ause_tapr):
  cl_hw(auc, HW_TIMER, 0, "A1")
{
  ruc= (class cl_rxk *)auc;
  use_tapr= ause_tapr;
  divby= use_tapr?1:2;
  in_clks= 0;
  cnt= 0;
}

int
cl_ta1::init(void)
{
  cl_hw::init();
  perclk = register_cell(ruc->hw8msg, rxkhw_perclk);
  tastat = register_cell(ruc->hw8msg, rxkhw_tastat);
  tactrl = register_cell(ruc->hw8msg, rxkhw_tactrl);
  tacsr  = register_cell(ruc->ioi, 0xa0);
  tapr   = use_tapr?register_cell(ruc->ioi, 0xa1):0;
  tat1r  = register_cell(ruc->ioi, 0xa3);
  tacr   = register_cell(ruc->ioi, 0xa4);
  return 0;
}

void
cl_ta1::reset(void)
{
  tacsr->W(0);
  if (use_tapr) tapr->W(1);
  tacr->W(0);
}

t_mem
cl_ta1::read(class cl_memory_cell *cell)
{
  if (0)
    ;

  // hw msg regs
  else if (cell == tastat)
    {}

  else if (cell == tactrl)
    {}
  
  // real SFRs
  else if (cell == tapr)
    {}

  else if (cell == tacsr)
    {
      // read value from tastat
      cell->set(tastat->get());
      // read of TACSR clears status bits
      tastat->set(0);
    }
  
  conf(cell, NULL);
  return cell->get();
}

void
cl_ta1::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;

  if (0)
    ;

  // hw msg regs
  else if (cell==perclk)
    {
      int c;
      in_clks+= *val;
      if ((c= in_clks/divby))
	Tick(c);
      in_clks%= divby;
    }

  else if (cell == tastat)
    {}

  else if (cell == tactrl)
    {}

  // Real SFRs
  else if (use_tapr && (cell==tapr))
    {
      *val&= 0x1;
      divby= *val+1;
    }
  
  else if (cell==tacsr)
    {
      // copy out written value to tactrl
      tactrl->set(*val);
    }
  
  cell->set(*val);
}

int
cl_ta1::Tick(int cycles)
{
  if (tactrl->get() & 1)
    {
      while (cycles--)
	{
	  if (cnt==0)
	    {
	      cnt= tat1r->get();
	      tastat->set(tastat->get() | 2);
	    }
	  else
	    {
	      cnt--;
	    }
	}
    }
  return 0;
}

void
cl_ta1::print_info(class cl_console_base *con)
{
}


/* End of rxk.src/ta1.cc */
