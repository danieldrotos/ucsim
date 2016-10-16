/* $Id$ */

#include "port_hwcl.h"


cl_port_hw::cl_port_hw(class cl_uc *auc, int aid, chars aid_string):
  cl_hw(auc, HW_PORT, aid, aid_string)
{
}

void
cl_port_hw::proc_input(void)
{
}

void
cl_port_hw::refresh_display(void)
{
}


bool
cl_port_io::input_avail(void)
{
  if (hw)
    hw->refresh_display();
  return cl_console::input_avail();
}


/* End of sim.src/port_hw.cc */
