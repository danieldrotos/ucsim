/*@1@*/

#include "tlcscl.h"


uint8_t
cl_tlcs::inc(uint8_t data)
{
  uint8_t n= data+1;
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X);

  if (n > 255)
    reg.f|= FLAG_X;
  if (n & 0x80)
    reg.f|= FLAG_S;
  if ((n & 0xff) == 0)
    reg.f|= FLAG_Z;
  if (data == 0x7f)
    reg.f|= FLAG_V;
  if ((n & 0x0f) == 0x00)
    reg.f|= FLAG_H;

  return n & 0xff;
}


uint8_t
cl_tlcs::dec(uint8_t data)
{
  uint8_t n= data-1;
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H|FLAG_X);
  reg.f|= FLAG_N;
  
  if (n > 255)
    reg.f|= FLAG_X;
  if (n & 0x80)
    reg.f|= FLAG_S;
  if ((n & 0xff) == 0)
    reg.f|= FLAG_Z;
  if (data == 0x80)
    reg.f|= FLAG_V;
  if ((n & 0x0f) == 0x00)
    reg.f|= FLAG_H;

  return n & 0xff;
}


/* End of tlcs/arith.cc */
