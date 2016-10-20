/* $Id$ */

#ifndef PORT_HW_HEADER
#define PORT_HW_HEADER

#include "newcmdposixcl.h"

#include "hwcl.h"


class cl_port_io: public cl_hw_io
{
 public:
  int basx, basy, keyset;
 public:
  cl_port_io(class cl_hw *ihw);
  virtual int init(void);
  //virtual bool input_avail(void);  
};

class cl_port_hw: public cl_hw
{
 public:
  class cl_memory_cell *cell_p, *bit_cells[32], *cell_in;
  t_mem cache_p, cache_in;
 public:
  cl_port_hw(class cl_uc *auc, int aid, chars aid_string);

  virtual void make_io(void);
  virtual void new_io(class cl_f *f_in, class cl_f *f_out);
  virtual void proc_input(void);
  virtual void refresh_display(bool force);
  virtual void draw_display(void);
};


#endif

/* End of sim.src/port_hwcl.h */
