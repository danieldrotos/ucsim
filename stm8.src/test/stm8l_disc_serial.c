// Source code under CC0 1.0
#include <stdint.h>
#include <stdio.h>

#include "stm8.h"

#define EI __asm__("rim")
#define DI __asm__("sim")

//#define PC_DDR	(*(volatile uint8_t *)0x500c)
//#define PC_CR1	(*(volatile uint8_t *)0x500d)

#define CLK_DIVR	(*(volatile uint8_t *)0x50c0)
#define CLK_PCKENR1	(*(volatile uint8_t *)0x50c3)

//#define USART1_SR	(*(volatile uint8_t *)0x5230)
//#define USART1_DR	(*(volatile uint8_t *)0x5231)
//#define USART1_BRR1	(*(volatile uint8_t *)0x5232)
//#define USART1_BRR2	(*(volatile uint8_t *)0x5233)
//#define USART1_CR2	(*(volatile uint8_t *)0x5235)
//#define USART1_CR3	(*(volatile uint8_t *)0x5236)

#define USART_CR2_TEN (1 << 3)
#define UART_CR2_REN (1 << 2)
#define UART_CR2_RIEN (1 << 5)
#define USART_CR3_STOP2 (1 << 5)
#define USART_CR3_STOP1 (1 << 4)
#define USART_SR_TXE (1 << 7)
#define UART_SR_RXNE (1 << 5)

int putchar(int c)
{
  while(!(USART1->sr & USART_SR_TXE));
  
  USART1->dr = c;
  return c;
}


volatile uint8_t rx_buf[8];
volatile uint8_t first_free= 0;
volatile uint8_t last_used= 0;

void isr_rx(void) __interrupt(28)
{
  volatile uint8_t d;
  if (USART1->sr & UART_SR_RXNE)
    {
      uint8_t n;
      d= USART1->dr;
      n= (first_free+1)%8;
      if (n != last_used)
	{
	  rx_buf[first_free]= d;
	  first_free= n;
	}
    }
}

char received()
{
  //return UART2_SR & UART_SR_RXNE;
  return first_free != last_used;
}

char getchar()
{
  uint8_t o;
  while (!received())
    ;
  o= last_used;
  last_used= (last_used+1)%8;
  return rx_buf[o];
}

void main(void)
{
  unsigned long i = 0;
  int a= 0;
  
  CLK_DIVR = 0x00; // Set the frequency to 16 MHz
  CLK_PCKENR1 = 0xFF; // Enable peripherals

  GPIOC->ddr = 0x08; // Put TX line on
  GPIOC->cr1 = 0x08;

  USART1->cr2 = USART_CR2_TEN | UART_CR2_REN; // Allow TX and RX
  USART1->cr3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
  USART1->brr2 = 0x03;
  USART1->brr1 = 0x68; // 9600 baud

  USART1->cr2|= UART_CR2_RIEN;
  EI;

  for(;;)
    {
      i++;
      if (received())
	{
	  char c= getchar();
	  printf("%c", c);
	  i= 0;
	}
      else
      if (i > 147456*2)
	{
	  printf("\ntick %d, press any key\n", a++);
	  i= 0;
	}
    }
}
