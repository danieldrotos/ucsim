/*@1@*/

#include "tlcscl.h"


// 1e
int
cl_tlcs::ret()
{
  t_mem pushed_pc;

  exec_ret(PC-1, &pushed_pc);
  PC= pushed_pc;
  return resGO;
}


// 1f
int
cl_tlcs::reti()
{
  t_mem pushed_pc, pushed_af;
  
  exec_pop(PC-1, &pushed_af);
  exec_reti(PC-1, &pushed_pc);
  reg.af= pushed_af;
  PC= pushed_pc;
  return resGO;
}


/* End of tlcs.src/jmp.cc */
