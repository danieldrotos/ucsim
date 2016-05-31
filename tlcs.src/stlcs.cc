/*@1@*/

#include <stdio.h>

// prj
#include "globals.h"

// sim.src
#include "appcl.h"

// local
#include "simtlcscl.h"

int
main(int argc, char *argv[])
{
  int retval;
  class cl_sim *sim;
  
  application= new cl_app();
  application->init(argc, argv);
  sim= new cl_simtlcs(application);
  if (sim->init())
    return(1);
  application->set_simulator(sim);
  retval= application->run();
  application->done();
  delete application;
  
  return(retval);
}

/* End of tlcs.src/stlcs.cc */
