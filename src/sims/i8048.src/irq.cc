/*
 * Simulator of microcontrollers (interrupt.cc)
 *
 * Copyright (C) 1999 Drotos Daniel
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

//#include <stdarg.h>

// prj
#include "utils.h"

// sim
#include "itsrccl.h"

// local
#include "irqcl.h"


cl_irq::cl_irq(class cl_uc *auc):
  cl_hw(auc, HW_INTERRUPT, 0, "irq")
{
}

int
cl_irq::init(void)
{
  cl_hw::init();
  cene.init();
  cene.decode(&ene);
  cent.decode(&ent);
  crqe.decode(&rqe);
  crqt.decode(&rqt);
  return 0;
}

void
cl_irq::added_to_uc(void)
{
  class cl_it_src *is;
  
  uc->it_sources->add(is= new cl_it_src(uc, 0,
					&cene, 1, // enable cell/mask
					&crqe, 1, // requ cell/mask
					3, // addr
					true, //clr
					false, // indirect
					"External", // name
					2 // priority
					));
  is->init();

  uc->it_sources->add(is= new cl_it_src(uc, 0,
					&cent, 1, // enable cell/mask
					&crqt, 1, // requ cell/mask
					7, // addr
					true, //clr
					false, // indirect
					"Timer", // name
					1 // priority
					));
  is->init();
  
}

void
cl_irq::write(MC *cell, t_mem *val)
{
  
}

int
cl_irq::tick(int cycles)
{
  return resGO;
}

void
cl_irq::reset(void)
{
  ene= ent= 0;
  rqe= rqt= 0;
}

void
cl_irq::print_info(class cl_console_base *con)
{
  int i;

  con->dd_printf("Interrupts are %s. Interrupt sources:\n",
		 (uc->it_enabled())?"enabled":"disabled");
  con->dd_printf("  Handler  En  Pr Req Act Name\n");
  for (i= 0; i < uc->it_sources->count; i++)
    {
      class cl_it_src *is= (class cl_it_src *)(uc->it_sources->at(i));
      con->dd_printf("  0x%06x", AU(is->addr));
      con->dd_printf(" %-3s", (is->enabled())?"en":"dis");
      con->dd_printf(" %2d", uc->priority_of(is->ie_mask));
      con->dd_printf(" %-3s", (is->pending())?"YES":"no");
      con->dd_printf(" %-3s", (is->active)?"act":"no");
      con->dd_printf(" %s", object_name(is));
      con->dd_printf("\n");
    }
  con->dd_printf("Active interrupt service(s):\n");
  con->dd_printf("  Pr Handler  PC       Source\n");
  for (i= 0; i < uc->it_levels->count; i++)
    {
      class it_level *il= (class it_level *)(uc->it_levels->at(i));
      if (il->level >= 0)
	{
	  con->dd_printf("  %2d", il->level);
	  con->dd_printf(" 0x%06x", AU(il->addr));
	  con->dd_printf(" 0x%06x", AU(il->PC));
	  con->dd_printf(" %s", (il->source)?(object_name(il->source)):
			 "nothing");
	  con->dd_printf("\n");
	}
    }
}


/* End of i8048.src/irq.cc */
