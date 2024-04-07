/*
 * Simulator of microcontrollers (osc.cc)
 *
 * Copyright (C) 2024,2024 Drotos Daniel, Talker Bt.
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

#include "pdkcl.h"

#include "osccl.h"


cl_osc::cl_osc(class cl_uc *auc, const char *aname):
  cl_hw(auc, HW_TIMER, 0, aname)
{
  pdk= (class cl_pdk *)auc;
}

int
cl_osc::init(void)
{
  clkmd= register_cell(pdk->sfr, 3);
  eoscr= register_cell(pdk->sfr, 0xa);
  fre= pdk->get_xtal();
  frh= 16000000;
  frl= 24000;
  cl_hw::init();
  return 0;
}

void
cl_osc::reset(void)
{
  t_mem v;
  ihrc= 0;
  ilrc= 0;
  eosc= 0;
  v= 0xf4;
  write(clkmd, &v);
  v= 0x80;
  write(eoscr, &v);
}

void
cl_osc::write(class cl_memory_cell *cell, t_mem *val)
{
  u8_t v= *val;
  if (conf(cell, val))
    return;
  if (cell == eoscr)
    {
      rune= v & 0x80;
    }
  else if (cell == clkmd)
    {
      runh= v & 0x10;
      runl= v & 0x04;
      if (!(v & 0x08))
	{
	  // Type 0
	  switch ((v>>5) & 7)
	    {
	    case 0: setup(frh, 4); break;
	    case 1: setup(frh, 2); break;
	    case 2: break;
	    case 3: setup(fre, 4); break;
	    case 4: setup(fre, 2); break;
	    case 5: setup(fre, 1); break;
	    case 6: setup(frl, 4); break;
	    case 7: setup(frl, 1); break;
	    }
	}
      else
	{
	  // Type 1
	  switch ((v>>5) & 7)
	    {
	    case 0: setup(frh,16); break;
	    case 1: setup(frh, 8); break;
	    case 2: setup(frl,16); break;
	    case 3: setup(frh,32); break;
	    case 4: setup(frh,64); break;
	    case 5: setup(fre, 8); break;
	    case 6: setup(frl, 2); break;
	    case 7: break;
	    }
	}
    }
  cell->set(*val);
}

int
cl_osc::tick(int cycles)
{
  if (runh) ihrc+= cycles * mh;
  if (runl) ilrc+= cycles * ml;
  if (rune) eosc+= cycles * me;
  return 0;
}

void
cl_osc::setup(double src_fr, unsigned int div_by)
{
  frsys= src_fr/div_by;
  mh= frh/frsys;
  ml= frl/frsys;
  me= fre/frsys;
  pdk->set_xtal(frsys);
}

void
cl_osc::print_info(class cl_console_base *con)
{
  con->dd_printf("frsys=%f\n", frsys);
  con->dd_printf("Hon=%d Lon=%d Eon=%d\n", runh?1:0, runl?1:0, rune?1:0);
  con->dd_printf("Th=%f Tl=%f Te=%f\n", ihrc, ilrc, eosc);
  con->dd_printf("frh=%f frl=%f fre=%f\n", frh, frl, fre);
  con->dd_printf("mh=%f ml=%f me=%f\n", mh, ml, me);
}


/* End of pdk.src/osc.cc */
