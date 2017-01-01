/*@1@*/

#include "uc521cl.h"


cl_uc521::cl_uc521(int Itype, int Itech, class cl_sim *asim):
  cl_uc52(Itype, Itech, asim)
{
}

int
cl_uc521::init(void)
{
  int ret;
  ret= cl_uc52::init();

  cpu->cfg_set(uc51cpu_aof_mdps, 0x86);
  cpu->cfg_set(uc51cpu_mask_mdps, 1);
  cpu->cfg_set(uc51cpu_aof_mdps1l, 0x84);
  cpu->cfg_set(uc51cpu_aof_mdps1h, 0x85);
  decode_dptr();

  return ret;
}


/* End of s51.src/uc521.cc */
