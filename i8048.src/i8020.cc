/*
 * Simulator of microcontrollers (i8020.cc)
 *
 * Copyright (C) 2022 Drotos Daniel, Talker Bt.
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

#include <ctype.h>

#include "utils.h"

#include "glob.h"

#include "i8020cl.h"


/*
 * Flags
 */

t_mem
cl_flag20_op::write(t_mem val)
{
  val|= 0x08;
  return val;
}


/*
 * CPU
 */

cl_i8020::cl_i8020(class cl_sim *asim):
  cl_uc(asim)
{
}

int
cl_i8020::init(void)
{
  cl_uc::init();
  fill_def_wrappers(itab);
  class cl_memory_operator *o= new cl_flag20_op(&cpsw);
  o->init();
  o->set_name("MCS48 flag operator");
  cpsw.append_operator(o);
  reg_cell_var(&cpsw, &psw, "psw", "CPU register PSW");
  cpsw.W(0);
  
  reset();
  return 0;
}

const char *
cl_i8020::id_string(void)
{
  return "i8020";
}


/* End of i8048.src/i8020.cc */
