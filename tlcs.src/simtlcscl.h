/*@1@*/

#ifndef SIMTLCSCL_HEADER
#define SIMTLCSCL_HEADER

#include "simcl.h"


class cl_simtlcs: public cl_sim
{
 public:
  cl_simtlcs(class cl_app *the_app);

  virtual class cl_uc *mk_controller(void);
};


#endif

/* End of tlcs.src/simtlcscl.h */
