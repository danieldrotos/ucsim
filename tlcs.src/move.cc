/*@1@*/

#include "tlcscl.h"


// 58+qq
int
cl_tlcs::pop(t_mem c1)
{
  t_mem data;
  exec_pop(PC-1, &data);
  *aof_reg16_qq(c1)= data;
  return resGO;
}

/* End of tlcs/move.cc */
