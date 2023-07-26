/*
 * Simulator of microcontrollers (portcl.h)
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

#ifndef PORTCL_HEADER
#define PORTCL_HEADER

#include "port_hwcl.h"


enum port_cfg {
  port_on	= 0,
  port_pin	= 1,
  port_value	= 2,
  port_odr	= 3,
  port_nuof	= 4
};

enum port_widths {
  port_4bit	= 4,
  port_8bit	= 8
};

class cl_qport: public cl_hw
{
 public:
  class cl_address_space *port_as;
  t_addr addr;
  u8_t mask, width;
 public:
  cl_qport(class cl_uc *auc, int aid,
	   class cl_address_space *apas, t_addr aaddr,
	   enum port_widths awidth);
  virtual unsigned int cfg_size(void) { return port_nuof; }
};


class cl_p2: public cl_qport
{
 public:
  cl_p2(class cl_uc *auc, int aid,
	class cl_address_space *apas, t_addr aaddr,
	enum port_widths awidth);
};


#endif

/* End of i8048.src/portcl.h */
