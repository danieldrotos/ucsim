/* */

#include "stm8.h"

#include "flash.h"


// Lock, unklock

void
flash_punlock(void)
{
  FLASH->pukr= 0x56;
  FLASH->pukr= 0xae;
}

void
flash_dunlock(void)
{
  FLASH->pukr= 0xae;
  FLASH->pukr= 0x56;
}

void
flash_plock(void)
{
  FLASH->iapsr&= ~0x02;
}

void
flash_dlock(void)
{
  FLASH->iapsr&= ~0x08;
}

void
flash_lock(void)
{
  FLASH->iapsr&= ~0x0a;
}


// Set programing mode

void
flash_byte_mode(void)
{
  FLASH->cr2= 0;
#if (DEVICE & DEV_STM8SAF)
  FLASH->ncr2= 0xff;
#endif
}

void
flash_word_mode(void)
{
  FLASH->cr2= 0x40;
#if (DEVICE & DEV_STM8SAF)
  FLASH->ncr2= 0xbf;
#endif
}

void
flash_erase_mode(void)
{
  FLASH->cr2= 0x20;
#if (DEVICE & DEV_STM8SAF)
  FLASH->ncr2= 0xdf;
#endif
}


// Check the result

uint8_t
flash_wait_finish(void)
{
  unsigned long int timeout= 0xfffff;
  
  while (((FLASH->iapsr & 0x05) == 0) &&
	 (timeout != 0))
    timeout--;
  if (FLASH->iapsr & 0x04)
    return 0;
  if (FLASH->iapsr & 0x01)
    return 1;
  if (timeout == 0)
    return 2;
  return 3;
}

void
flash_erase(unsigned long addr, unsigned int iapsr)
{
  ((uint8_t*)0)[addr+0]= 0;
  ((uint8_t*)0)[addr+1]= 0;
  ((uint8_t*)0)[addr+2]= 0;
  ((uint8_t*)0)[addr+3]= 0;
  while ((((uint8_t*)0)[iapsr] & 0x05) == 0) ;
}


/* End of stm8.src/test/flash.c */