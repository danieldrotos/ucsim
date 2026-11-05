/*
 * Simulator of microcontrollers (tb.cc)
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

#include "tbcl.h"


cl_tb::cl_tb(class cl_uc *auc):
  cl_hw(auc, HW_TIMER, 0, "tb")
{
  ruc= (class cl_rxk *)auc;
  in_clks= 0;
  divby= 1;
  cnt= 0;
  cmp1= cmp2= 0;
}


int
cl_tb::init(void)
{
  cl_hw::init();
  tbstat = register_cell(ruc->hw8msg, rxkhw_tbstat);
  tbctrl = register_cell(ruc->hw8msg, rxkhw_tbctrl);
  a1in   = register_cell(ruc->hw8msg, rxkhw_ta1_in);
  a1out  = register_cell(ruc->hw8msg, rxkhw_ta1_out);
  tbcsr  = register_cell(ruc->ioi, 0xb0);
  tbcr   = register_cell(ruc->ioi, 0xb1);
  tbm1r  = register_cell(ruc->ioi, 0xb2);
  tbl1r  = register_cell(ruc->ioi, 0xb3);
  tbm2r  = register_cell(ruc->ioi, 0xb4);
  tbl2r  = register_cell(ruc->ioi, 0xb5);
  tbcmr  = register_cell(ruc->ioi, 0xbe);
  tbclr  = register_cell(ruc->ioi, 0xbf);
  
  ruc->mk_mvar(ruc->ioi, 0xb0, "TBCSR", "Timer B Control and Status Register");
  ruc->mk_mvar(ruc->ioi, 0xb1, "TBCR" , "Timer B Control Register");
  ruc->mk_mvar(ruc->ioi, 0xb2, "TBM1R" , "Timer B MSB 1 Register");
  ruc->mk_mvar(ruc->ioi, 0xb3, "TBL1R" , "Timer B LSB 1 Register");
  ruc->mk_mvar(ruc->ioi, 0xb4, "TBM2R" , "Timer B MSB 2 Register");
  ruc->mk_mvar(ruc->ioi, 0xb5, "TBL2R" , "Timer B LSB 2 Register");
  ruc->mk_mvar(ruc->ioi, 0xb4, "TBCMR" , "Timer B Count MSB Register");
  ruc->mk_mvar(ruc->ioi, 0xb5, "TBCLR" , "Timer B Count LSB Register");

  return 0;
}

void
cl_tb::reset(void)
{
  tbcsr->W(0);
  tbcr->W(0);
}


t_mem
cl_tb::read(class cl_memory_cell *cell)
{
  if (0)
    ;

  /* Real SFRs */
  if (cell == tbcsr)
    {
      u8_t v= cell->get();
      v&= ~(0x06);
      v|= (tbstat->get() & 0x06);
      cell->set(v);
      // Read of tbcsr clears stat bits
      tbstat->set(0);
    }
  
  //conf(cell, NULL);
  return cell->get();
}


void
cl_tb::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;
  
  if (0)
    ;

  else if (cell == clk_src)
    Tick(*val);

  /* Message registers */
  else if (cell == tbstat)
    {
      *val&= 0x06;
    }

  else if (cell == tbctrl)
    {}

  /* Real SFRs */
  else if (cell == tbcsr)
    {
      tbctrl->set(*val);
    }

  else if (cell == tbcr)
    {
      set_clk(*val);
    }

  else if (cell == tbm1r)
    {
      cmp1&= 0x00ff;
      cmp1|= ((*val & 0xc0)>>6);
    }
  else if (cell == tbm2r)
    {
      cmp2&= 0x00ff;
      cmp2|= ((*val & 0xc0)>>6);
    }

  else if (cell == tbl1r)
    {
      cmp1&= 0x300;
      cmp1|= (*val & 0xff);
    }
  else if (cell == tbl2r)
    {
      cmp2&= 0x300;
      cmp2|= (*val & 0xff);
    }
  
  else if (cell == tbcmr) // read-only
    return;
  else if (cell == tbclr) // read-only
    return;
  
  cell->set(*val);
}

void
cl_tb::set_clk(u8_t val)
{
  switch (val & 0xc0)
    {
    case 0x00: clk_src= a1in ; divby= 1; break;
    case 0x04: clk_src= a1out; divby= 1; break;
    case 0x08: clk_src= a1in ; divby= 8; break;
    case 0x0c: clk_src= a1in ; divby= 8; break;
    }
}

int
cl_tb::Tick(int cycles)
{
  if (tbcsr->get() & 1)
    {
      in_clks+= cycles;
      int c= in_clks / divby;
      in_clks%= divby;
      while (c--)
	{
	  cnt= (cnt+1) & 0x3ff;
	  counted();
	}
    }
  return 0;
}

void
cl_tb::counted(void)
{
  if (cnt == cmp1)
    {
      tbstat->write(tbstat->get() | 0x02);
      ruc->hw8msg->write(rxkhw_tb1_out, 1);
    }
  if (cnt == cmp2)
    {
      tbstat->write(tbstat->get() | 0x04);
      ruc->hw8msg->write(rxkhw_tb2_out, 1);
    }
}

void
cl_tb::print_info(class cl_console_base *con)
{
  con->dd_printf("%s[%d]", get_name(), id);
  con->dd_printf(" CTRL= ");
  con->print_bin(tbctrl->get(), 8);
  con->dd_printf(" STAT= ");
  con->print_bin(tbstat->get(), 8);
  con->dd_printf(" CNT= 0x%03x,%4d", cnt, cnt);
  con->dd_printf("\n");
  con->dd_printf("inclks=%d divby=%d", in_clks, divby);
  con->dd_printf("\n");
  u16_t m1= ((tbm1r->get()&0xc0)>>6)|tbl1r->get();
  u16_t m2= ((tbm2r->get()&0xc0)>>6)|tbl2r->get();
  con->dd_printf("Compare1= 0x%03x,%4d Compare2= 0x%03x,%4d",
		 cmp1, cmp1, cmp2, cmp2);
  con->dd_printf("\n");
}


/*
 */

int
cl_tbs::init(void)
{
  cl_tb::init();
  tbsm1r  = register_cell(ruc->ioi, 0xba);
  tbsl1r  = register_cell(ruc->ioi, 0xbb);
  tbsm2r  = register_cell(ruc->ioi, 0xbc);
  tbsl2r  = register_cell(ruc->ioi, 0xbd);
  
  ruc->mk_mvar(ruc->ioi, 0xba, "TBSM1R" , "Timer B Step MSB 1 Register");
  ruc->mk_mvar(ruc->ioi, 0xbb, "TBSL1R" , "Timer B Step LSB 1 Register");
  ruc->mk_mvar(ruc->ioi, 0xbc, "TBSM2R" , "Timer B Step MSB 2 Register");
  ruc->mk_mvar(ruc->ioi, 0xbd, "TBSL2R" , "Timer B Step LSB 2 Register");
  return 0;
}

void
cl_tbs::counted(void)
{
  u8_t c= tbcr->read();
  if (cnt == cmp1)
    {
      tbstat->write(tbstat->get() | 0x02);
      ruc->hw8msg->write(rxkhw_tb1_out, 1);
      if (c & 0x10)
	{
	  u16_t s1= (tbsm1r->read() & 3)*256 + tbsl1r->read();
	  cmp1= (cmp1+s1)&0x3ff;
	}
    }
  if (cnt == cmp2)
    {
      tbstat->write(tbstat->get() | 0x04);
      ruc->hw8msg->write(rxkhw_tb2_out, 1);
      if (c & 0x20)
	{
	  u16_t s2= (tbsm2r->read() & 3)*256 + tbsl2r->read();
	  cmp1= (cmp1+s2)&0x3ff;
	}
    }
}

void
cl_tbs::print_info(class cl_console_base *con)
{
  cl_tb::print_info(con);
}


/*
 */

int
cl_tbs6::init(void)
{
  cl_tbs::init();
  a11out  = register_cell(ruc->hw8msg, rxkhw_ta11_out);
  return 0;
}


void
cl_tbs6::set_clk(u8_t val)
{
  if ((val & 0xc0) == 0xc0)
    {
      clk_src= a11out;
      divby= 1;
    }
}


/* End of rxk.src/tb.cc */
