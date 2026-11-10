/*
 * Simulator of microcontrollers (tc.cc)
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

#include "tccl.h"


cl_tc::cl_tc(class cl_uc *auc):
  cl_hw(auc, HW_TIMER, 0, "tc")
{
  ruc= (class cl_rxk *)auc;
  in_clks= 0;
  divby= 1;
  cnt= 0;
  cmp1= cmp2= 0;
}


int
cl_tc::init(void)
{
  cl_hw::init();
  a1in   = register_cell(ruc->hw8msg, rxkhw_ta1_in);
  a1out  = register_cell(ruc->hw8msg, rxkhw_ta1_out);
  tccsr  = register_cell(ruc->ioi, 0x500);
  tccr   = register_cell(ruc->ioi, 0x501);
  tcbar  = register_cell(ruc->ioi, 0xf8);
  tcbpr  = register_cell(ruc->ioi, 0xf9);
  /*
  ruc->mk_mvar(ruc->ioi, 0xb0, "TBCSR", "Timer B Control and Status Register");
  ruc->mk_mvar(ruc->ioi, 0xb1, "TBCR" , "Timer B Control Register");
  ruc->mk_mvar(ruc->ioi, 0xb2, "TBM1R" , "Timer B MSB 1 Register");
  ruc->mk_mvar(ruc->ioi, 0xb3, "TBL1R" , "Timer B LSB 1 Register");
  ruc->mk_mvar(ruc->ioi, 0xb4, "TBM2R" , "Timer B MSB 2 Register");
  ruc->mk_mvar(ruc->ioi, 0xb5, "TBL2R" , "Timer B LSB 2 Register");
  ruc->mk_mvar(ruc->ioi, 0xb4, "TBCMR" , "Timer B Count MSB Register");
  ruc->mk_mvar(ruc->ioi, 0xb5, "TBCLR" , "Timer B Count LSB Register");
  */
  return 0;
}

void
cl_tc::reset(void)
{
  tccsr->W(0);
  tccr->W(0);
  tcbpr->W(2);
  ruc->ioi->write(0x502, 0);
  ruc->ioi->write(0x503, 0);
}


t_mem
cl_tc::read(class cl_memory_cell *cell)
{
  if (0)
    ;

  /* Real SFRs */
  else if (cell == tccsr)
    {
      // Read of tbcsr clears stat bits
      u8_t v= tccsr->get();
      v&= ~(0x02);
      tccsr->set(v);
    }

  else if (cell == tcbpr)
    return 0;

  else if (cell == tcbar)
    {
      cell->set(ruc->ioi->read(0x500+tcbpr->get()));
      inc_bpr();
    }
  
  //conf(cell, NULL);
  return cell->get();
}


void
cl_tc::write(class cl_memory_cell *cell, t_mem *val)
{
  if (conf(cell, val))
    return;
  
  if (0)
    ;

  else if (cell == clk_src)
    Tick(*val);

  /* Real SFRs */
  else if (cell == tccsr)
    {
      *val&= 0x03;
    }

  else if (cell == tccr)
    {
      set_clk(*val&= 0x0f);
    }

  else if (cell == tcbpr)
    *val&= 0x1f;

  else if (cell == tcbar)
    {
      ruc->ioi->write(0x500+tcbpr->get(), *val);
      inc_bpr();
    }
  
  cell->set(*val);
}

void
cl_tc::set_clk(u8_t val)
{
  switch (val & 0x0c)
    {
    case 0x00: clk_src= a1in ; divby= 1; break;
    case 0x04: clk_src= a1out; divby= 1; break;
    case 0x08: clk_src= a1in ; divby= 8; break;
    case 0x0c: clk_src= a1in ; divby= 8; break;
    }
}

int
cl_tc::Tick(int cycles)
{
  if (tccsr->get() & 1)
    {
      in_clks+= cycles;
      int c= in_clks / divby;
      in_clks%= divby;
      while (c--)
	{
	  cnt++;
	  counted();
	}
    }
  return 0;
}

void
cl_tc::counted(void)
{
  u16_t set[4], res[4];
  set[0]= ruc->ioi->read(0x508) + 256*(ruc->ioi->read(0x509));
  res[0]= ruc->ioi->read(0x50a) + 256*(ruc->ioi->read(0x50b));
  set[1]= ruc->ioi->read(0x50c) + 256*(ruc->ioi->read(0x50d));
  res[1]= ruc->ioi->read(0x50e) + 256*(ruc->ioi->read(0x50f));
  set[2]= ruc->ioi->read(0x518) + 256*(ruc->ioi->read(0x519));
  res[2]= ruc->ioi->read(0x51a) + 256*(ruc->ioi->read(0x51b));
  set[3]= ruc->ioi->read(0x51c) + 256*(ruc->ioi->read(0x51d));
  res[3]= ruc->ioi->read(0x51e) + 256*(ruc->ioi->read(0x51f));
  int i;
  for (i= 0; i < 4; i++)
    {
      if (cnt == set[i])
	ruc->hw8msg->write(rxkhw_tc0_out+i, 1);
      if (cnt == res[i])
	ruc->hw8msg->write(rxkhw_tc0_out+i, 0);
    }
  u16_t arr= ruc->ioi->read(0x502) + 256*(ruc->ioi->read(0x503));
  if (cnt == arr)
    {
      cnt= 0;
      tccsr->write(tccsr->read() | 0x02);
    }
}

void
cl_tc::inc_bpr(void)
{
  u8_t v= tcbpr->get();
  if (v == 2)
    v++;
  else if (v == 3)
    v= 8;
  else if ((v >= 8) && (v<0xf))
    v++;
  else if (v == 0xf)
    v= 0x18;
  else if ((v >= 0x18) && (v<0x1f))
    v++;
  else
    v= 2;
  tcbpr->set(v);
}

void
cl_tc::print_info(class cl_console_base *con)
{
  u16_t set[4], res[4];
  set[0]= ruc->ioi->read(0x508) + 256*(ruc->ioi->read(0x509));
  res[0]= ruc->ioi->read(0x50a) + 256*(ruc->ioi->read(0x50b));
  set[1]= ruc->ioi->read(0x50c) + 256*(ruc->ioi->read(0x50d));
  res[1]= ruc->ioi->read(0x50e) + 256*(ruc->ioi->read(0x50f));
  set[2]= ruc->ioi->read(0x518) + 256*(ruc->ioi->read(0x519));
  res[2]= ruc->ioi->read(0x51a) + 256*(ruc->ioi->read(0x51b));
  set[3]= ruc->ioi->read(0x51c) + 256*(ruc->ioi->read(0x51d));
  res[3]= ruc->ioi->read(0x51e) + 256*(ruc->ioi->read(0x51f));
  con->dd_printf("%s[%d]", get_name(), id);
  con->dd_printf(" CS= ");
  con->print_bin(tccsr->get(), 8);
  con->dd_printf(" BPR= 0x%02x,%3d", tcbpr->get(), tcbpr->get());
  con->dd_printf(" CNT= 0x%04x,%5d", cnt, cnt);
  con->dd_printf("\n");
  con->dd_printf(" ");
  int i;
  for (i= 0; i < 4; i++)
    con->dd_printf("set[%d]= 0x%04x reset[%d]= 0x%04x\n",
		   i, set[i], res[i]);
  con->dd_printf("inclks=%d divby=%d", in_clks, divby);
  con->dd_printf("\n");
  con->dd_printf("\n");
}


/*
 */

int
cl_tc6::init(void)
{
  cl_tc::init();
  a11out  = register_cell(ruc->hw8msg, rxkhw_ta11_out);
  return 0;
}


void
cl_tc6::set_clk(u8_t val)
{
  if ((val & 0x0c) == 0x0c)
    {
      clk_src= a11out;
      divby= 1;
    }
}


/* End of rxk.src/tc.cc */
