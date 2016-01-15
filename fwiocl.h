#ifndef FWIOCL_HEADER
#define FWIOCL_HEADER


#include <winsock2.h>


#include "fiocl.h"

class cl_io: public cl_f
{
 private:
  HANDLE handle;
  char buffer[1024];
  int last_used, first_free;
 public:
 public:
  cl_io();
  cl_io(chars fn, chars mode);
  cl_io(int the_server_port);
 protected:
  virtual int put(char c);
  virtual int get(void);
 public:
  virtual enum file_type determine_type(void);
 public:
  virtual int read(char *buf, int max);
  virtual void changed(void);
  virtual int input_avail(void);
};


#endif

/* End of fwiocl.h */
