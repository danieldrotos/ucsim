/*@1@*/

#include "tlcscl.h"


// 0B
int
cl_tlcs::daa_a()
{
  if (((reg.a & 0x0f) > 9) ||
      (reg.f & FLAG_H))
    {
      int al= reg.a & 0x0f;
      if (al + 6 > 15)
	reg.f|= FLAG_H;
      else
	reg.f&= ~FLAG_H;
      if ((int)reg.a + 6 > 255)
	reg.f|= FLAG_C|FLAG_X;
      else
	reg.f&= ~(FLAG_C|FLAG_X);
      reg.a+= 6;
    }
  if (((reg.a & 0xf0) > 0x90) ||
      (reg.f & FLAG_C))
    {
      if ((int)reg.a + 0x60 > 255)
	reg.f|= FLAG_C;
      else
	reg.f&= ~FLAG_C;
      reg.a+= 0x60;
    }
  return resGO;
}


// 10
int
cl_tlcs::cpl_a()
{
  reg.a= ~reg.a;
  reg.f|= FLAG_H|FLAG_N;
  return resGO;
}


// 11
int
cl_tlcs::neg_a()
{
  reg.f&= ~(FLAG_S|FLAG_Z|FLAG_H/*|FLAG_X*/|FLAG_V|FLAG_C);
  reg.f|= FLAG_N;
  if (reg.a == 0x80)
    reg.f|= FLAG_V;
  if (reg.a)
    reg.f|= (FLAG_C|FLAG_X);

  //uint8_t a= ~reg.a;
  if ((reg.a & 0x0f) == 0)//if (a&0xf + 1 > 15)
    reg.f|= FLAG_H;
  reg.a= 0-reg.a;

  if (reg.a & 0x80)
    reg.f|= FLAG_S;
  if (!reg.a)
    reg.f|= FLAG_Z;
  
  return resGO;
}


// 0e
int
cl_tlcs::ccf()
{
  if (reg.f & FLAG_C)
    reg.f&= ~(FLAG_C);
  else
    reg.f|= FLAG_C;
  if (reg.f & FLAG_X)
    reg.f&= ~(FLAG_X);
  else
    reg.f|= FLAG_X;
  reg.f&= ~FLAG_N;
  return resGO;
}


// 0d
int
cl_tlcs::scf()
{
  reg.f|= FLAG_C|FLAG_X;
  reg.f&= ~(FLAG_N|FLAG_H);
  return resGO;
}


// 0c
int
cl_tlcs::rcf()
{
  reg.f&= ~(FLAG_C|FLAG_X|FLAG_N|FLAG_H);
  return resGO;
}


// ff
int
cl_tlcs::swi()
{
  t_addr iPC= PC-1;
  reg.f&= ~FLAG_I;
  exec_intr(iPC, 0x0010, PC);
  exec_push(iPC, reg.af);
  PC= 0x0010;
  return resGO;
}


/* End of tlcs.src/cpu_others.cc */
