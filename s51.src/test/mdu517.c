#include "c517.h"

#include "mdu517.h"

uint8_t
mdu_32div16(uint32_t op1, uint16_t op2, uint32_t *res, uint16_t *rem)
{
  uint16_t v;
  uint32_t d;
 
  MD0= op1 & 0xff;
  MD1= (op1 >> 8) & 0xff;
  MD2= (op1 >> 16) & 0xff;
  MD3= (op1 >> 24) & 0xff;

  MD4= op2 & 0xff;
  MD5= (op2 >> 8) & 0xff;

  __asm__ ("nop");

  d= (uint32_t)MD0 + (uint32_t)MD1*256l + (uint32_t)MD2*256l*256l + (uint32_t)MD3*256l*256l*256l;
  if (res)
    *res= d;
  v= MD5*256 + MD4;
  if (rem)
    *rem= v;

  return ARCON & 0xc0;
}

uint8_t
mdu_16div16(uint16_t op1, uint16_t op2, uint16_t *res, uint16_t *rem)
{
  uint16_t v;
 
  MD0= op1 & 0xff;
  MD1= (op1 >> 8) & 0xff;
  MD4= op2 & 0xff;
  MD5= (op2 >> 8) & 0xff;

  __asm__ ("nop");

  v= MD1*256 + MD0;
  if (res)
    *res= v;
  v= MD5*256 + MD4;
  if (rem)
    *rem= v;

  return ARCON & 0xc0;
}
