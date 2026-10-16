/*
 * Simulator of microcontrollers (types51.h)
 *
 * Copyright (C) 2002 Drotos Daniel
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

#ifndef TYPES51_HEADER
#define TYPES51_HEADER

#include "ddconfig.h"

#define SFR_SET_BIT(newbit, reg, bitmask)	\
  if (newbit)					\
    sfr->set(reg, sfr->get(reg) | (bitmask));	\
  else						\
    sfr->set(reg, sfr->get(reg) & ~(bitmask));

/* Event parameters */
struct ev_port_changed {
  int id;
  t_addr addr;
  t_mem prev_value, new_value, pins, new_pins;
};

#endif

/* End of s51.src/types51.h */
