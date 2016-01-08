#ifndef FWIOCL_HEADER
#define FWIOCL_HEADER


#include <winsock2.h>


enum e_handle_type {
  CH_UNDEF,
  CH_FILE,
  CH_SOCKET,
  CH_CONSOLE,
  CH_SERIAL
};

#include "fiocl.h"

class cl_io: public cl_f
{
 private:
  HANDLE handle;
  enum e_handle_type type;
 public:
 cl_io(): cl_f () {}
 cl_io(chars fn, chars mode): cl_f(fn, mode) {}
 protected:
  enum e_handle_type get_handle_type();
 public:
  virtual void changed(void);
  virtual int input_avail(void);
};


#endif

/* End of fwiocl.h */
