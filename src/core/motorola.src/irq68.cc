/*
 * Simulator of microcontrollers (irq68.cc)
 *
 * Copyright (C) 2020 Drotos Daniel
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

#include "globals.h"
#include "utils.h"

#include "itsrccl.h"

#include "irq68cl.h"


/* IRQ handling peripheral */

cl_irq_hw::cl_irq_hw(class cl_uc *auc):
  cl_itctr(auc, 0, "irq")
{
  muc= (class cl_m6800 *)auc;
}

int
cl_irq_hw::init()
{
  //class cl_var *v;

  cl_hw::init();

  return 0;
}

const char *
cl_irq_hw::cfg_help(t_addr addr)
{
  switch (addr)
    {
    case m68_nmi_en	: return "NMI enable (RO)";
    case m68_nmi	: return "NMI request/clear (RW)";
    case m68_irq_en	: return "IRQ enable (RO)";
    case m68_irq	: return "IRQ request/clear (RW)";
    case m68_swi_en	: return "SWI enable (RW)";
    case m68_swi	: return "SWI request/clear (RW)";
    }
  return cl_hw::cfg_help(addr);
}


/* End of motorola.src/irq68.cc */
