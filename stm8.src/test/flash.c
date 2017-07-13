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
flash_byte_mode(void)
{
  FLASH->cr2= 0;
#if (DEVICE & DEV_STM8SAF)
  FLASH->ncr2= 0xff;
#endif
}

/* End of stm8.src/test/flash.c */
