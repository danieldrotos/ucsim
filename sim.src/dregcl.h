/*@1@*/

#ifndef DREG_HEADER
#define DREG_HEADER

#include "hwcl.h"


class cl_dreg: public cl_hw
{
 public:
  cl_dreg(class cl_uc *auc, int aid, const char *aid_string);
 public:
  //virtual void refresh_display(bool force);
  virtual void print_info(class cl_console_base *con);
};


#endif

/* End of sim.src/dregcl.h */
