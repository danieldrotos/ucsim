#ifndef MDU517_HEADER
#define MDU517_HEADER

#include <stdint.h>

extern uint8_t mdu_32div16(uint32_t op1, uint16_t op2,
			   uint32_t *res, uint16_t *rem);
extern uint8_t mdu_16div16(uint16_t op1, uint16_t op2,
			   uint16_t *res, uint16_t *rem);
extern uint8_t mdu_16mul16(uint16_t op1, uint16_t op2,
			   uint32_t *res);

#endif
