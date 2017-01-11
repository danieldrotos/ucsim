#include <mcs51reg.h>
#include <stdio.h>

#include "bank1.h"
#include "bank2.h"

__sfr __at(0x88) PSBANK;

unsigned char
_sdcc_external_startup (void)
{
  /* copied from device/examples/mcs51/simple2/hi.c */
  PCON = 0x80;  /* power control byte, set SMOD bit for serial port */
  SCON = 0x40;  /* serial control byte, mode 1, RI _NOT_ active */
  TMOD = 0x21;  /* timer control mode, byte operation */
  TCON = 0;     /* timer control register, byte operation */

  TH1  = 0xFA;  /* serial reload value, 9,600 baud at 11.0952Mhz */
  TR1  = 1;     /* start serial timer */

  TI   = 1;     /* enable transmission of first byte */
  return 0;
}

int
putchar (int c)
{
  while (!TI)
    ;
  SBUF = c;
  TI = 0;
  return c;
}

int
b(int x)
{
  return x+1;
}

void
main(void)
{
  int i;
  i= 0;
  while (1)
    {
      i= b(i);
      i= b1(i);
      i= b2(i);
    }
}

void
_sdcc_banked_call(void) __naked
{
  __asm
	push	_PSBANK		;save return bank
	xch	a,r0		;save Acc in r0, do not assume any register bank
	push	acc		;push LSB address
	mov	a,r1
	push	acc		;push MSB address
	mov	a,r2		;get new bank
	anl	a,#0x0F		;remove storage class indicator
	anl	_PSBANK,#0xF0
	orl	_PSBANK,a	;select bank
	xch	a,r0		;restore Acc
	ret			;make the call
  __endasm;  
}

void
_sdcc_banked_ret(void) __naked
{
  __asm
	pop	_PSBANK		;restore bank
	ret			;return to caller
  __endasm;
}
