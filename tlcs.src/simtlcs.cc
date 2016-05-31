/*@1@*/

// sim.src
#include "appcl.h"

// local
#include "simtlcscl.h"
#include "tlcscl.h"


cl_simtlcs::cl_simtlcs(class cl_app *the_app):
  cl_sim(the_app)
{}

class cl_uc *
cl_simtlcs::mk_controller(void)
{
  return(new cl_tlcs(this));
}


/* End of tlcs.src/simtlcs.cc */
