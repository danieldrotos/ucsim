#ifndef FUIOCL_HEADER
#define FUIOCL_HEADER


#include "fiocl.h"

class cl_io: public cl_f
{
 public:
 cl_io(): cl_f () {}
 cl_io(chars fn, chars mode): cl_f(fn, mode) {}
};


#endif

/* End of fuiocl.h */
