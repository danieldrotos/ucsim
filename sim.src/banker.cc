/*
 * Simulator of microcontrollers (sim.src/banker.cc)
 *
 * Copyright (C) 2016,16 Drotos Daniel, Talker Bt.
 * 
 * To contact author send email to drdani@mazsola.iit.uni-miskolc.hu
 *
 */

/*
  This file is part of microcontroller simulator: ucsim.

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
  02111-1307, USA.
*/
/*@1@*/

#include "bankercl.h"


cl_banker::cl_banker(class cl_uc *auc,
		     class cl_address_space *the_as,
		     t_addr the_addr,
		     t_mem the_mask):
  cl_hw(auc, HW_BANKER, 0, "banker")
{
  as= the_as;
  address= the_addr;
  mask= the_mask;
  id= uc->get_max_hw_id(HW_BANKER) + 1;
}

int
cl_banker::init()
{
}


/* End of sim.src/banker.cc */
