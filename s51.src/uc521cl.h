/*@1@*/

#ifndef UC521CL_HEADER
#define UC521CL_HEADER

#include "uc52cl.h"

class cl_uc521: public cl_uc52
{
 public:
  cl_uc521(int Itype, int Itech, class cl_sim *asim);
  virtual int init(void);
};


#endif

/* End of s51.src/uc521cl.h */
