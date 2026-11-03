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


static t_addr tat_regs[13]= {
  /*  0 */ 0,
  /*  1 */ 0xa3,
  /*  2 */ 0xa5,
  /*  3 */ 0xa7,
  /*  4 */ 0xa9,
  /*  5 */ 0xab,
  /*  6 */ 0xad,
  /*  7 */ 0xaf,
  /*  8 */ 0xa6,
  /*  9 */ 0xa8,
  /* 10 */ 0xaa,
  /* 11 */ 0xac,
  /* 12 */ 0xae
};

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

  ruc->mk_mvar(ruc->ioi, 0xa0, "TACSR", "Timer A Control and Status Register");
  ruc->mk_mvar(ruc->ioi, 0xa4, "TACR" , "Timer A Control Register");
  chars c, n;
  c.format("TAT%dR", id);
  n.format("Timer A%d Time Constant Register", id);
  ruc->mk_mvar(ruc->ioi, tat_regs[id], c, n);
  
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
  if (tacsr->get() & 1)
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
  con->dd_printf("\n");
}


/*********************************************************************/

cl_ta1::cl_ta1(class cl_uc *auc, u8_t atapr_mask):
  cl_ta(auc, 1)
{
  tapr_mask= atapr_mask;
}

int
cl_ta1::init(void)
{
  cl_ta::init();
  tapr= register_cell(ruc->ioi, 0xa1);
  if (tapr_mask)
    {
      pre_div= tapr->read();
      ruc->mk_mvar(ruc->ioi, 0xa1, "TAPR", "Timer A Prescale Register");
    }
  else
    pre_div= 1;
  return 0;
}

void
cl_ta1::reset(void)
{
  if (tapr_mask)
    tapr->write(1);
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
      int c= *val, t= 0;
      while (c--)
	{
	  if (pre_div == 0)
	    {
	      pre_div= tapr_mask?(tapr->read()):1;
	      t++;
	    }
	  else
	    pre_div--;
	}
      Tick(t);
    }
  
  // Real SFRs
  else if (cell==tapr)
    {
    }
  
  cell->set(*val);
}

void
cl_ta1::print_info(class cl_console_base *con)
{
  cl_ta::print_info(con);
  con->dd_printf("tapr_mask=0x%02x", tapr_mask);
  con->dd_printf(" in=perclk/%d", tapr_mask?(tapr->read()+1):2);
  con->dd_printf("\n");
}


/*********************************************************************/

cl_tax::cl_tax(class cl_uc *auc, int aid,
	       t_addr aclk_sel_addr, u8_t aclk_sel_mask,
	       t_addr aclk_alt_addr):
  cl_ta(auc, aid)
{
  clk_sel_addr= aclk_sel_addr;
  clk_sel_mask= aclk_sel_mask;
  clk_alt_addr= aclk_alt_addr;
}

int
cl_tax::init(void)
{
  cl_ta::init();
  clk_alt= clk_alt_addr?register_cell(ruc->hw8msg, clk_alt_addr):0;
  ta1_in = register_cell(ruc->hw8msg, rxkhw_ta1_in);
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

  /* Alternate clk source is used if masked bit in
     selector reg is 1.
     Default source is input of TA1 */
  bool alt= clk_alt_addr?
    (ruc->ioi->read(clk_sel_addr) & clk_sel_mask):
    false;
  
  cl_ta::write(cell, val);

  if (0)
    ;

  else if (alt?(cell == clk_alt):(cell == ta1_in))
    Tick(*val);
      
  cell->set(*val);
}

void
cl_tax::print_info(class cl_console_base *con)
{
  cl_ta::print_info(con);
  bool alt= clk_alt_addr?
    (ruc->ioi->read(clk_sel_addr) & clk_sel_mask):
    false;
  con->dd_printf("in=%s of timer a", alt?"output":"input");
  con->dd_printf("\n");
}


/* End of rxk.src/ta.cc */
