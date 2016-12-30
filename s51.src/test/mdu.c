#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "hw.h"
#include "serial.h"
#include "print.h"

#include "c517.h"

__xdata char *simif;

char
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

void
test_32div16()
{
  uint32_t op1, res, mdu_res;
  uint16_t op2, rem, mdu_rem;
  int ok= 0, fail= 0, i;
  uint8_t r;
  
  for (i= 0; i<1; i++)
    {
      op1= (uint32_t)abs(rand()) * (uint32_t)abs(rand());
      do {
	op2= abs(rand());
      }
      while (!op2);

      res= op1 / op2;
      rem= op1 % op2;

      printf("%8lx/%4x %10lu/%5u=%10lu,%5u ", op1, op2,
	     op1, op2,
	     res, rem);
      r= mdu_32div16(op1, op2, &mdu_res, &mdu_rem);
      printf("mdu=%10lu/%5u ", mdu_res, mdu_rem);
      if ((res != mdu_res) ||
	  (rem != mdu_rem))
	{
	  printf("fail ");
	  fail++;
	}
      else
	{
	  printf("ok ");
	  ok++;
	}
      if (r)
	{
	  if (r&0x80)
	    printf("err ");
	  if (r&0x40)
	    printf("ovr ");
	  //fail++;
	}
      printf("\n");
    }
  printf("32div16 test: succ=%d fails=%d\n\n", ok, fail);
}

void main(void)
{
  simif= (__xdata char *)0xffff;
  serial_init(9600);
  test_32div16();

  *simif= 's';
  while (1)
    {
    }
}
