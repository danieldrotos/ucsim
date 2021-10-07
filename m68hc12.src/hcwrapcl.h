#ifndef HCWRAPCL_HEADER
#define HCWRAPCL_HEADER

#include "m68hc12cl.h"

#define _II 1

extern int wrap_INV(class CL12 *uc, t_mem code);


class cl_wrap
{
 public:
  cl_wrap() {}
  virtual void init()
  {
    fill_0_00();
  }
  virtual void fill_0_00() { page0[0x00]= wrap_INV; }
};

extern class cl_wrap *hc12wrap;

#include "wdecls.h"

class cl_12wrap: public cl_wrap
{
public:
  cl_12wrap(): cl_wrap() {}

#include "wfills.h"
};


#endif
