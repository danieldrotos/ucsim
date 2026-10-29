/*
 * Simulator of microcontrollers (ta.cc)
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

#include "tacl.h"


cl_ta::cl_ta(class cl_uc *auc, int aid):
  cl_hw(auc, HW_TIMER, aid, "ta")
{
  ruc= (class cl_rxk *)auc;
  cnt= 0;
  in_clks= 0;
}

int
cl_ta::init(void)
{
  cl_hw::init();
  perclk = register_cell(ruc->hw8msg, rxkhw_perclk);
  tastat = register_cell(ruc->hw8msg, rxkhw_tastat);
  tactrl = register_cell(ruc->hw8msg, rxkhw_tactrl);
  tacsr  = register_cell(ruc->ioi, 0xa0);
  tacr   = register_cell(ruc->ioi, 0xa4);
  tatxr  = register_cell(ruc->ioi, tat_regs[id]);

  cl_var *v;
  v= new cl_var("TACSR", ruc->ioi, 0xa0, "Timer A Control and Status Register");
  v->init(); ruc->vars->add(v);
  v= new cl_var("TACR", ruc->ioi, 0xa4, "Timer A Control Register");
  v->init(); ruc->vars->add(v);
  chars c, n;
  c.format("TAT%dR", id);
  n.format("Timer A%d Time Constant Register", id);
  v= new cl_var(c, ruc->ioi, tat_regs[id], n);
  v->init(); ruc->vars->add(v);
  
  return 0;
}

void
cl_ta::reset(void)
{
  tacsr->W(0);
  tacr->W(0);
}

t_mem
cl_ta::read(class cl_memory_cell *cell)
{
  if (0)
    ;

  // hw msg regs
  /*
  else if (cell == tastat)
    {}

  else if (cell == tactrl)
    {}
  */
  
  // real SFRs
  else if (cell == tacsr)
    {
      // read value from tastat
      cell->set(tastat->get());
      // read of TACSR clears status bits
      tastat->set(0);
    }
  
  //conf(cell, NULL);
  return cell->get();
}

void
cl_ta::write(class cl_memory_cell *cell, t_mem *val)
{
  /* should be called by leaf */
  /*
  if (conf(cell, val))
    return;
  */
  
  if (0)
    ;

  /*
  else if (cell == tastat)
    {}

  else if (cell == tactrl)
    {}
  */
  
  // Real SFRs
  else if (cell==tacsr)
    {
      // copy out written value to tactrl
      tactrl->set(*val);
    }
  
  cell->set(*val);
}

int
cl_ta::Tick(int cycles)
{
  if (ruc->ta_on())
    {
      if (id == 1)
	ruc->hw8msg->write(rxkhw_ta1_in, cycles);
      while (cycles--)
	{
	  if (cnt==0)
	    {
	      cnt= tatxr->get();
	      tastat->set(tastat->get() | 2);
	      // pass underflows to users
	      ruc->hw8msg->write(rxkhw_ta1_out-1+id, 1);
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
cl_ta::print_info(class cl_console_base *con)
{
  con->dd_printf("%s[%d]", get_name(), id);
  con->dd_printf(" CTRL= ");
  con->print_bin(tactrl->get(), 8);
  con->dd_printf(" STAT= ");
  con->print_bin(tastat->get(), 8);
  con->dd_printf(" CNT= 0x%02x,%3d", cnt, cnt);
  //con->dd_printf(" use_tapr=%s", use_tapr?"yes":"no");
  //con->dd_printf(" in=preclk/%d", divby);
  con->dd_printf("\n");
}


/*********************************************************************/

cl_ta1::cl_ta1(class cl_uc *auc, bool ause_tapr):
  cl_ta(auc, 1)
{
  use_tapr= ause_tapr;
  divby= use_tapr?1:2;
}

int
cl_ta1::init(void)
{
  cl_ta::init();
  tapr   = use_tapr?register_cell(ruc->ioi, 0xa1):0;
  return 0;
}

void
cl_ta1::reset(void)
{
}

t_mem
cl_ta1::read(class cl_memory_cell *cell)
{
  cl_ta::read(cell);

  if (0) ;

  else if (cell == tapr) {}
  
  conf(cell, NULL);
  return cell->get();
}

void
cl_ta1::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;

  cl_ta::write(cell, val);
  
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
  
  // Real SFRs
  else if (use_tapr && (cell==tapr))
    {
      *val&= 0x1;
      divby= *val+1;
    }
  
  cell->set(*val);
}

void
cl_ta1::print_info(class cl_console_base *con)
{
  cl_ta::print_info(con);
  con->dd_printf(" use_tapr=%s", use_tapr?"yes":"no");
  con->dd_printf(" in=preclk/%d", divby);
  con->dd_printf("\n");
}


/*********************************************************************/

cl_tax::cl_tax(class cl_uc *auc, int aid):
  cl_ta(auc, aid)
{
}

int
cl_tax::init(void)
{
  cl_ta::init();
  return 0;
}

void
cl_tax::reset(void)
{
}

t_mem
cl_tax::read(class cl_memory_cell *cell)
{
  cl_ta::read(cell);

  if (0) ;
  
  conf(cell, NULL);
  return cell->get();
}

void
cl_tax::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;

  cl_ta::write(cell, val);
  
  cell->set(*val);
}

void
cl_tax::print_info(class cl_console_base *con)
{
  cl_ta::print_info(con);
}


/* End of rxk.src/ta.cc */
