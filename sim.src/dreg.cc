/*@1@*/

#include "dregcl.h"


cl_dreg::cl_dreg(class cl_uc *auc, int aid, const char *aid_string):
  cl_hw(auc, HW_DUMMY, aid, aid_string)
{
}

/*
void
cl_dreg::refresh_display(bool force)
{
}
*/

void
cl_dreg::print_info(class cl_console_base *con)
{
  if (uc) uc->print_regs(con);
}


/* End of sim.src/dreg.cc */
