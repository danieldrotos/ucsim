#include <stdint.h>
#include <stdio.h>

#include "stm8.h"

#define CLK_DIVR	(*(volatile uint8_t *)0x50c6)
#define CLK_PCKENR1	(*(volatile uint8_t *)0x50c7)

int putchar(int c)
{
	while(!(UART2_SR & UART_SR_TXE));
	UART2_DR = c;
	return c;
}

void main(void)
{
	unsigned long i = 0;

	CLK_DIVR = 0x00; // Set the frequency to 16 MHz
	CLK_PCKENR1 = 0xFF; // Enable peripherals

	UART2_CR2 = UART_CR2_TEN; // Allow TX and RX
	UART2_CR3 &= ~(UART_CR3_STOP1 | UART_CR3_STOP2); // 1 stop bit
	UART2_BRR2 = 0x03; UART2_BRR1 = 0x68; // 9600 baud

	printf("Hello World!\n");
	for (;;) ;
}
