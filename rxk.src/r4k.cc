/*
 * Simulator of microcontrollers (r4k.cc)
 *
 * Copyright (C) @@S@@,@@Y@@ Drotos Daniel, Talker Bt.
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

#include "r4kwrap.h"
#include "glob.h"

#include "r4kcl.h"


cl_r4k::cl_r4k(class cl_sim *asim):
  cl_r3ka(asim)
{
}

int
cl_r4k::init(void)
{
  cl_r3ka::init();
  //mode2k();
  return 0;
}

const char *
cl_r4k::id_string(void)
{
  return "R4K";
}

void
cl_r4k::reset(void)
{
  cl_r3ka::reset();
  edmr= 0;
  mode3k();  
}

void
cl_r4k::make_cpu_hw(void)
{
  add_hw(cpu= new cl_r4k_cpu(this));
  cpu->init();
}

void
cl_r4k::mode3k(void)
{
  itab[0x40]= instruction_wrapper_40;
}

void
cl_r4k::mode4k(void)
{
  itab[0x40]= instruction_wrapper_4k40;
}


/*
 * CPU peripheral for r4k
 */

cl_r4k_cpu::cl_r4k_cpu(class cl_uc *auc):
  cl_rxk_cpu(auc)
{
  r4uc= (class cl_r4k *)auc;
  edmr= new cl_cell8();
}

int
cl_r4k_cpu::init(void)
{
  cl_rxk_cpu::init();

  uc->reg_cell_var(edmr, &(r4uc->edmr),
		   "EDMR", "Enable dual-mode register");
  
  return 0;
}


const char *
cl_r4k_cpu::cfg_help(t_addr addr)
{
  switch (addr)
    {
      //case rxk_cpu_xpc: return "MMU register: XPC";
      //case rxk_cpu_nuof: return "";
    }
  return "Not used";
}


void
cl_r4k_cpu::print_info(class cl_console_base *con)
{
  cl_rxk_cpu::print_info(con);
  con->dd_printf("EDMR    : 0x%02x\n", edmr->read());
}

/* End of rxk.src/r4k.cc */
