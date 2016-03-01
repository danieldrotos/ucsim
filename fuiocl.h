#ifndef FUIOCL_HEADER
#define FUIOCL_HEADER


#include "fiocl.h"

class cl_io: public cl_f
{
 public:
  cl_io();
  cl_io(chars fn, chars mode);
  cl_io(int the_server_port);
 public:
  virtual enum file_type determine_type(void);
  virtual int close(void);
  virtual int check_dev(void);
};


#endif

/* End of fuiocl.h */
