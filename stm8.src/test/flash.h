/* */

#ifndef FLASH_HEADER
#define FLASH_HEADER

extern void flash_punlock(void);
extern void flash_dunlock(void);
extern void flash_plock(void);
extern void flash_dlock(void);
extern void flash_lock(void);

extern void flash_byte_mode(void);

#endif

/* End of stm8.src/test/flash.h */
