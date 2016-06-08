/*@1@*/

#include "tlcscl.h"


uint8_t
cl_tlcs::rlc(uint8_t data, bool set_sz)
{
  uint8_t c= data & 0x80;
  reg.f&= ~((set_sz?(FLAG_S|FLAG_Z):0)|FLAG_H|FLAG_N|FLAG_C);
  data<<= 1;
  if (c)
    {
      data|= 1;
      reg.f|= FLAG_C;
    }

  if (set_sz)
    {
      if (!data)
	reg.f|= FLAG_Z;
      if (data&0x80)
	reg.f|= FLAG_S;
    }
  
  return data;
}


uint8_t
cl_tlcs::rrc(uint8_t data, bool set_sz)
{
  uint8_t c= data & 0x01;
  reg.f&= ~((set_sz?(FLAG_S|FLAG_Z):0)|FLAG_H|FLAG_N|FLAG_C);
  data>>= 1;
  if (c)
    {
      data|= 0x80;
      reg.f|= FLAG_C;
    }

  if (set_sz)
    {
      if (!data)
	reg.f|= FLAG_Z;
      if (data&0x80)
	reg.f|= FLAG_S;
    }
  
  return data;
}


uint8_t
cl_tlcs::rl(uint8_t data, bool set_sz)
{
  uint8_t c= data & 0x80;
  data<<= 1;
  if (reg.f & FLAG_C)
    data|= 1;
  reg.f&= ~((set_sz?(FLAG_S|FLAG_Z):0)|FLAG_H|FLAG_N|FLAG_C);
  if (c)
    reg.f|= FLAG_C;

  if (set_sz)
    {
      if (!data)
	reg.f|= FLAG_Z;
      if (data&0x80)
	reg.f|= FLAG_S;
    }
  
  return data;
}


uint8_t
cl_tlcs::rr(uint8_t data, bool set_sz)
{
  uint8_t c= data & 0x01;
  data>>= 1;
  if (reg.f & FLAG_C)
    data|= 0x80;
  reg.f&= ~((set_sz?(FLAG_S|FLAG_Z):0)|FLAG_H|FLAG_N|FLAG_C);
  if (c)
    reg.f|= FLAG_C;

  if (set_sz)
    {
      if (!data)
	reg.f|= FLAG_Z;
      if (data&0x80)
	reg.f|= FLAG_S;
    }
  
  return data;
}


uint8_t
cl_tlcs::sla(uint8_t data, bool set_sz)
{
  uint8_t c= data & 0x80;
  data<<= 1;
  reg.f&= ~((set_sz?(FLAG_S|FLAG_Z):0)|FLAG_H|FLAG_N|FLAG_C);
  if (c)
    reg.f|= FLAG_C;

  if (set_sz)
    {
      if (!data)
	reg.f|= FLAG_Z;
      if (data&0x80)
	reg.f|= FLAG_S;
    }
  
  return data;
}


uint8_t
cl_tlcs::sra(uint8_t data, bool set_sz)
{
  uint8_t c7= data & 0x80;
  uint8_t c0= data & 0x01;
  data>>= 1;
  reg.f&= ~((set_sz?(FLAG_S|FLAG_Z):0)|FLAG_H|FLAG_N|FLAG_C);
  if (c0)
    reg.f|= FLAG_C;
  data|= c7;
  
  if (set_sz)
    {
      if (!data)
	reg.f|= FLAG_Z;
      if (data&0x80)
	reg.f|= FLAG_S;
    }
  
  return data;
}


uint8_t
cl_tlcs::srl(uint8_t data, bool set_sz)
{
  uint8_t c0= data & 0x01;
  data>>= 1;
  reg.f&= ~((set_sz?(FLAG_S|FLAG_Z):0)|FLAG_H|FLAG_N|FLAG_C);
  if (c0)
    reg.f|= FLAG_C;
  
  if (set_sz)
    {
      if (!data)
	reg.f|= FLAG_Z;
      if (data&0x80)
	reg.f|= FLAG_S;
    }
  
  return data;
}


/* End of tlcs.src/rot_sh.cc */
