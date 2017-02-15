// Source code under CC0 1.0
#include <stdint.h>

#include "stm8.h"

#define PC GPIOC
#define PE GPIOE

volatile unsigned int clk= 0;

void tim1_up_isr(void) __interrupt(TIM1_UP_IRQ)
{
  TIM1->ier&= ~TIM_IER_UIE;
  clk++;
}

unsigned int clock(void)
{
  unsigned int c;
  TIM1->ier&= ~TIM_IER_UIE;
  c= clk;
  TIM1->ier|= TIM_IER_UIE;
  return c;
}

void main(void)
{
  CLK->ckdivr = 0x00; // Set the frequency to 16 MHz
  CLK->pckenr2 |= 0x02; // Enable clock to timer

  // Configure timer
  // 16 MHz clock for timer
  TIM1->pscrh = 0;//0x3e;
  TIM1->pscrl = 0;//0x80;
  // Update event at every 1 ms (16000 count)
  TIM1->arrh = 0x3e;
  TIM1->arrl = 0x80;
  // Enable timer
  TIM1->cr1 = TIM_CR1_CEN;

  // Enable interrupt for timer1 update
  TIM1->ier|= TIM_IER_UIE;
  EI;
  
  // Configure pins
  PE->ddr = 0x80;
  PE->cr1 = 0x80;

  PC->ddr = 0x80;
  PC->cr1 = 0x80;

  for(;;)
    {
      if (clock() % 1000 <= 500)
	PE->odr |= 0x80;
      else
	PE->odr &= 0x7f;
      if (clock() % 2000 <= 1000)
	PC->odr |= 0x80;
      else
	PC->odr &= 0x7f;
    }
}
