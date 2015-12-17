#include <mcs51reg.h>
#include <stdio.h>

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

void
putchar (char c)
{
  while (!TI)
    ;
  SBUF = c;
  TI = 0;
}

#define SIF_ADDRESS_SPACE_NAME	"xram"
#define SIF_ADDRESS_SPACE	xdata
#define SIF_ADDRESS		0xffff

unsigned char SIF_ADDRESS_SPACE *sif;

char
simulated(void)
{
  unsigned char c;
  *sif= 0x55;
  c= *sif;
  if (c != (unsigned char)~0x55)
    return(0);
  *sif= 0xaa;
  if (*sif != (unsigned char)~0xaa)
    return(0);
  return(1);
}

int nuof_commands;
unsigned char commands[100];

void
get_commands(void)
{
  int i;
  *sif= 1;
  nuof_commands= *sif;
  for (i= 0; i < nuof_commands; i++)
    commands[i]= *sif;
}

int
get_ifversion(void)
{
  *sif= 2;
  return(*sif);
}

void
print_cmd_infos(void)
{
  int i, j;
  unsigned char inf[5];
  for (i= 0; i < nuof_commands; i++)
    {
      printf("Command 0x%02x info:\n", commands[i]);
      *sif= 5;
      *sif= commands[i];
      inf[0]= *sif;
      for (j= 0; j < inf[0]; j++)
	{
	  inf[j+1]= *sif;
	  printf(" 0x%02x", inf[j+1]);
	}
      printf("\n");
    }
  
}

void
main(void)
{
  sif= (unsigned char SIF_ADDRESS_SPACE *)0xffff;
  printf("Testing simulator interface at %s[0x%x]\n",
	 SIF_ADDRESS_SPACE_NAME, SIF_ADDRESS);
  printf("%s", simulated()?"Interface found.":"Interface not found");
  if (simulated())
    {
      int i;
      i= get_ifversion();
      printf(" Version %d.\n", i);
      get_commands();
      printf("Interface knows about %d commands:\n", nuof_commands);
      for (i= 0; i < nuof_commands; i++)
	printf(" 0x%02x", commands[i]);
      printf("\n");
      print_cmd_infos();
    }
  else
    printf("\n");
}
