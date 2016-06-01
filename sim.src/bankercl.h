/*
 * Simulator of microcontrollers (sim.src/bankercl.h)
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

#ifndef SIM_BANKERCL_HEADER
#define SIM_BANKERCL_HEADER

#include "hwcl.h"


class cl_banker: public cl_hw
{
 protected:
  // location specifying actual bank
  class cl_address_space *banker_as;
  t_addr banker_addr;
  t_mem banker_mask;
  // banked area
  class cl_address_space *banked_as;
  t_addr banked_start;
  t_addr banked_size;
 public:
  cl_banker(class cl_uc *auc,
	    class cl_address_space *the_as, t_addr the_addr, t_mem the_mask);
  virtual int init();
};


#endif

/* End of sim.src/bankercl.h */
