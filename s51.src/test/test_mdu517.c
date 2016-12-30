#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "hw.h"
#include "serial.h"
#include "print.h"

#include "c517.h"

#include "mdu517.h"

__xdata char *simif;

void
test_32div16(char verbose)
{
  unsigned long op1, res, mdu_res;
  unsigned int op2, rem, mdu_rem;
  int ok= 0, fail= 0, i;
  uint8_t r;
  
  for (i= 0; i<100; i++)
    {
      op1= labs(rand()) * abs(rand());
      do {
	op2= abs(rand()) * abs(rand()%3);
      }
      while (!op2);

      res= op1 / op2;
      rem= op1 % op2;

      if (verbose)
	printf("%8lx/%4x %10lu/%5u=%10lu,%5u ", op1, op2, op1, op2, res, rem);
      r= mdu_32div16(op1, op2, &mdu_res, &mdu_rem);
      if (verbose)
	printf("mdu=%10lu,%5u ", mdu_res, mdu_rem);
      if ((res != mdu_res) ||
	  (rem != mdu_rem))
	{
	  if (verbose)
	    printf("fail ");
	  fail++;
	}
      else
	{
	  if (verbose)
	    printf("ok ");
	  ok++;
	}
      if (r &&
	  verbose)
	{
	  if (r&0x80)
	    printf("err ");
	  if (r&0x40)
	    printf("ovr ");
	}
      if (verbose)
	printf("\n");
    }
  printf("32div16 test: succ=%d fails=%d\n\n", ok, fail);
}

void
test_16div16(char verbose)
{
  unsigned int op1, res, mdu_res;
  unsigned int op2, rem, mdu_rem;
  int ok= 0, fail= 0, i;
  uint8_t r;
  
  for (i= 0; i<100; i++)
    {
      op1= abs(rand()) * 1+abs(rand()%2);
      do {
	op2= abs(rand());
      }
      while (!op2);

      res= op1 / op2;
      rem= op1 % op2;

      if (verbose)
	printf("%4x/%4x %5u/%5u=%5u,%5u ", op1, op2, op1, op2, res, rem);
      r= mdu_16div16(op1, op2, &mdu_res, &mdu_rem);
      if (verbose)
	printf("mdu=%5u,%5u ", mdu_res, mdu_rem);
      if ((res != mdu_res) ||
	  (rem != mdu_rem))
	{
	  if (verbose)
	    printf("fail ");
	  fail++;
	}
      else
	{
	  if (verbose)
	    printf("ok ");
	  ok++;
	}
      if (r &&
	  verbose)
	{
	  if (r&0x80)
	    printf("err ");
	  if (r&0x40)
	    printf("ovr ");
	}
      if (verbose)
	printf("\n");
    }
  printf("16div16 test: succ=%d fails=%d\n\n", ok, fail);
}

void
test_16mul16(char verbose)
{
  unsigned int op1;
  unsigned int op2;
  unsigned long res, mdu_res;
  int ok= 0, fail= 0, i;
  uint8_t r;
  
  for (i= 0; i<100; i++)
    {
      op1= abs(rand()) /*+abs(rand())*/;
      op2= abs(rand()) /*+abs(rand())*/;

      res= (unsigned long)op1 * (unsigned long)op2;

      if (verbose)
	printf("%4x*%4x %5u*%5u=%10lu ", op1, op2, op1, op2, res);
      r= mdu_16mul16(op1, op2, &mdu_res);
      if (verbose)
	printf("mdu=%10lu ", mdu_res);
      if (res != mdu_res)
	{
	  if (verbose)
	    printf("fail ");
	  fail++;
	}
      else
	{
	  if (verbose)
	    printf("ok ");
	  ok++;
	}
      if (r &&
	  verbose)
	{
	  if (r&0x80)
	    printf("err ");
	}
      if (verbose)
	printf("\n");
    }
  printf("16mul16 test: succ=%d fails=%d\n\n", ok, fail);
}

void main(void)
{
  simif= (__xdata char *)0xffff;
  serial_init(9600);

  test_32div16(0);
  test_16div16(0);
  test_16mul16(0);
  
  *simif= 's';
  while (1)
    {
    }
}
