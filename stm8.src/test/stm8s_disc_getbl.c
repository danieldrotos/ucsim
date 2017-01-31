// Source code under CC0 1.0
#include <stdint.h>
#include <stdio.h>

#include "stm8.h"

#include "serial.h"

#define CLK_DIVR	(*(volatile uint8_t *)0x50c6)
#define CLK_PCKENR1	(*(volatile uint8_t *)0x50c7)

#define USART_CR2_TEN (1 << 3)
#define UART_CR2_REN (1 << 2)
#define UART_CR2_RIEN (1 << 5)
#define USART_CR3_STOP2 (1 << 5)
#define USART_CR3_STOP1 (1 << 4)
#define USART_SR_TXE (1 << 7)
#define UART_SR_RXNE (1 << 5)

void
print_bl()
{
  int a, l;
  uint8_t *p= (uint8_t *)0x6000;
  printf("%c\n", 2);
  printf("$A6000,\n", 0x6000);
  for (a= 0, l= 0; a < 0x800; a++)
    {
      print_cx2(p[a]);
      printf(" ");
      l++;
      if ((l % 16) == 0)
	{
	  l= 0;
	  printf("\n");
	}
    }
  printf("%c\n", 3);
}
	 
void main(void)
{
  unsigned long i = 0;
  
  CLK_DIVR = 0x00; // Set the frequency to 16 MHz
  CLK_PCKENR1 = 0xFF; // Enable peripherals

  USART->cr2 = USART_CR2_TEN | UART_CR2_REN; // Allow TX and RX
  USART->cr3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
  USART->brr2 = 0x03;
  USART->brr1 = 0x68; // 9600 baud

  USART->cr2|= UART_CR2_RIEN;
  EI;

  for(;;)
    {
      if (serial_received())
	{
	  char c= getchar();
	  if (c == '=')
	    {
	      print_bl();
	    }
	  else if (c == '*')
	    {
	      printf("0x%04x\n", 0x6000);
	    }
	  else
	    printf("%c", c);
	}
    }
}
