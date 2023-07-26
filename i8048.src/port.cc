/*
 * Simulator of microcontrollers (port.cc)
 *
 * Copyright (C) 1999,99 Drotos Daniel, Talker Bt.
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

#include "portcl.h"


cl_qport::cl_qport(class cl_uc *auc, int aid,
		   class cl_address_space *apas, t_addr aaddr,
		   enum port_widths awidth):
  cl_hw(auc, HW_PORT, aid, "port")
{
  port_as= apas;
  addr= aaddr;
  width= awidth;
  switch (width)
    {
    case port_4bit: mask= 0x0f; break;
    case port_8bit: mask= 0xff; break;
    }
}


/*
 * P2 port
 */

cl_p2::cl_p2(class cl_uc *auc, int aid,
	     class cl_address_space *apas, t_addr aaddr,
	     enum port_widths awidth):
  cl_qport(auc, aid, apas, aaddr, awidth)
{
}


/* End of i8048.src/port.cc */
