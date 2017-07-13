/* */

#include "stm8.h"

#include "flash.h"

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

void
flash_byte_mode(void)
{
  FLASH->cr2= 0;
#if (DEVICE & DEV_STM8SAF)
  FLASH->ncr2= 0xff;
#endif
}

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

/* End of stm8.src/test/flash.c */
