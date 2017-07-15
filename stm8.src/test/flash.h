/* */

#ifndef FLASH_HEADER
#define FLASH_HEADER

#include <stdbool.h>

extern void flash_punlock(void);
extern void flash_dunlock(void);
extern void flash_plock(void);
extern void flash_dlock(void);
extern void flash_lock(void);

extern void flash_byte_mode(void);
extern void flash_word_mode(void);
extern void flash_erase_mode(void);

extern uint8_t flash_wait_finish(void);
extern void flash_erase(unsigned long addr, unsigned int iapsr);

#endif

/* End of stm8.src/test/flash.h */
