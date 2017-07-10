// Source code under CC0 1.0
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "stm8.h"

#include "serial.h"


void
print_bl()
{
  int a, l;
  uint8_t *p= (uint8_t *)0x6000;
  printf("%c\n", 2);
  printf("$A%04x,\n", 0x6000);
  for (a= 0, l= 0; a < 0x800; a++)
    {
      printf("%02x ", p[a]);
      l++;
      if ((l % 16) == 0)
	{
	  l= 0;
	  printf("\n");
	}
    }
  printf("%c\n", 3);
}

void
dump(int start, int len)
{
  uint8_t *p= (uint8_t *)0;
  int i= 0;
  
  printf("%06x ", start);
  while (i<len)
    {
      printf("%02x ", p[start+i]);
      i++;
      if ((i<len) && ((start+i)%8 == 0))
	{
	  printf("\n%06x ", start+i);
	}
    }
  printf("\n");
}

#define DELIM " ,"

int
xtoi(char *s)
{
  int r= 0;
  while (*s)
    {
      if (isdigit(*s))
	r= r*16 + *s-'0';
      else if ((*s >= 'a') && (*s <= 'f'))
	r= r*16 + *s-'a'+10;
      else if ((*s >= 'A') && (*s <= 'F'))
	r= r*16 + *s-'A'+10;
      s++;
    }
  return r;
}

void
proc_cmd(char *cmd)
{
  char *w= strtok(cmd, DELIM);
  char *s;
  
  if (w)
    {
      if (strcmp(w, "bl") == 0)
	print_bl();
      else if (strcmp(w, "uid") == 0)
	{
#if defined UID
	  int i;
	  uint8_t *p= UID;
	  printf("0x%04x ", p);
	  for (i= 0; i < 12; i++)
	    printf("%02x ", p[i]);
	  printf("\n");
#else
	  printf("no uid\n");
#endif
	}
      else if (strcmp(w, "dump") == 0)
	{
	  s= strtok(NULL, DELIM);
	  if (s)
	    {
	      int start= xtoi(s);
	      int len= 32;
	      s= strtok(NULL, DELIM);
	      if (s)
		len= xtoi(s);
	      dump(start, len);
	    }
	}
    }
}

char cmd[100];

void
proc_input(char c)
{
  int l= strlen(cmd);

  printf("%c", c);
  if ((c == '\n') ||
      (c == '\r'))
    {
      proc_cmd(cmd);
      cmd[0]= 0;
    }
  else
    {
      if (l < 99)
	{
	  cmd[l++]= c;
	  cmd[l]= 0;
	}
    }
}
  
void main(void)
{
  unsigned long i = 0;
  unsigned int a= 0;

  CLK->ckdivr = 0x00; // Set the frequency to 16 MHz
  CLK->pckenr1 = 0xFF; // Enable peripherals

  // USART2
  // TX: PD5, CN4.10
  // RX: PD6, CN4.11
  USART->cr2 = USART_CR2_TEN | USART_CR2_REN; // Allow TX and RX
  USART->cr3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
  USART->brr2 = 0x03;
  USART->brr1 = 0x68; // 9600 baud

  USART->cr2|= USART_CR2_RIEN;
  EI;

  cmd[0]= 0;
  for(;;)
    {
      if (serial_received())
	{
	  char c= getchar();
	  proc_input(c);
	}
    }
}