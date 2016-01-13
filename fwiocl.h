#ifndef FWIOCL_HEADER
#define FWIOCL_HEADER


#include <winsock2.h>


#include "fiocl.h"

class cl_io: public cl_f
{
 private:
  HANDLE handle;
 public:
 public:
  cl_io();
  cl_io(chars fn, chars mode);
  cl_io(int the_server_port);
 public:
  virtual enum file_type determine_type(void);
 public:
  virtual void changed(void);
  virtual int input_avail(void);
};


#endif

/* End of fwiocl.h */
