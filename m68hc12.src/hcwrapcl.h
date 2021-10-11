#ifndef HCWRAPCL_HEADER
#define HCWRAPCL_HEADER

#include "m68hc12cl.h"

#define _A_B	uc->cA,uc->rB
#define _A_i8	uc->cA,uc->i8()
#define _A_dop	uc->cA,uc->dop()
#define _A_eop	uc->cA,uc->eop()

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
