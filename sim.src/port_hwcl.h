/* $Id$ */

#ifndef PORT_HW_HEADER
#define PORT_HW_HEADER

#include "newcmdposixcl.h"

#include "hwcl.h"


class cl_port_io: public cl_hw_io
{
 public:
  virtual bool input_avail(void);  
};

class cl_port_hw: public cl_hw
{
 public:
  class cl_memory_cell *cell_p, *bit_cells[32], *cell_in;
 public:
  cl_port_hw(class cl_uc *auc, int aid, chars aid_string);

  virtual void proc_input(void);
  virtual void refresh_display(void);
};


#endif

/* End of sim.src/port_hwcl.h */
