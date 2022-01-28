#include "gen.h"

DEC(0, 89,	adc	, _A_i8  	, "ADCA %b"	, ' ', 2	, 1)
DEC(0, 99,	adc	, _A_dop	, "ADCA %d"	, ' ', 2	, 3)
DEC(0, a9,	adc	, _A_xbop8	, "ADCA %p"	, ' ', -2	, 0x66433)
DEC(0, b9,	adc	, _A_eop 	, "ADCA %e"	, ' ', 3	, 3)

DEC(0, c9,	adc	, _B_i8  	, "ADCB %b"	, ' ', 2	, 1)
DEC(0, d9,	adc	, _B_dop	, "ADCB %d"	, ' ', 2	, 3)
DEC(0, e9,	adc	, _B_xbop8	, "ADCB %p"	, ' ', -2	, 0x66433)
DEC(0, f9,	adc	, _B_eop 	, "ADCB %e"	, ' ', 3	, 3)

DEC(0, 8b,	add	, _A_i8  	, "ADDA %b"	, ' ', 2	, 1)
DEC(0, 9b,	add	, _A_dop	, "ADDA %d"	, ' ', 2	, 3)
DEC(0, ab,	add	, _A_xbop8	, "ADDA %p"	, ' ', -2	, 0x66433)
DEC(0, bb,	add	, _A_eop 	, "ADDA %e"	, ' ', 3	, 3)

DEC(0, cb,	add	, _B_i8  	, "ADDB %b"	, ' ', 2	, 1)
DEC(0, db,	add	, _B_dop	, "ADDB %d"	, ' ', 2	, 3)
DEC(0, eb,	add	, _B_xbop8	, "ADDB %p"	, ' ', -2	, 0x66433)
DEC(0, fb,	add	, _B_eop 	, "ADDB %e"	, ' ', 3	, 3)

DEC(0, 84,	And	, _A_i8  	, "ANDA %b"	, ' ', 2	, 1)
DEC(0, 94,	And	, _A_dop	, "ANDA %d"	, ' ', 2	, 3)
DEC(0, a4,	And	, _A_xbop8	, "ANDA %p"	, ' ', -2	, 0x66433)
DEC(0, b4,	And	, _A_eop 	, "ANDA %e"	, ' ', 3	, 3)

DEC(0, c4,	And	, _B_i8  	, "ANDB %b"	, ' ', 2	, 1)
DEC(0, d4,	And	, _B_dop	, "ANDB %d"	, ' ', 2	, 3)
DEC(0, e4,	And	, _B_xbop8	, "ANDB %p"	, ' ', -2	, 0x66433)
DEC(0, f4,	And	, _B_eop 	, "ANDB %e"	, ' ', 3	, 3)

DEC(0, 88,	eor	, _A_i8  	, "EORA %b"	, ' ', 2	, 1)
DEC(0, 98,	eor	, _A_dop	, "EORA %d"	, ' ', 2	, 3)
DEC(0, a8,	eor	, _A_xbop8	, "EORA %p"	, ' ', -2	, 0x66433)
DEC(0, b8,	eor	, _A_eop 	, "EORA %e"	, ' ', 3	, 3)

DEC(0, c8,	eor	, _B_i8  	, "EORB %b"	, ' ', 2	, 1)
DEC(0, d8,	eor	, _B_dop	, "EORB %d"	, ' ', 2	, 3)
DEC(0, e8,	eor	, _B_xbop8	, "EORB %p"	, ' ', -2	, 0x66433)
DEC(0, f8,	eor 	, _B_eop 	, "EORB %e"	, ' ', 3	, 3)

DEC(0, 8a,	Or	, _A_i8  	, "ORAA %b"	, ' ', 2	, 1)
DEC(0, 9a,	Or	, _A_dop	, "ORAA %d"	, ' ', 2	, 3)
DEC(0, aa,	Or	, _A_xbop8	, "ORAA %p"	, ' ', -2	, 0x66433)
DEC(0, ba,	Or	, _A_eop 	, "ORAA %e"	, ' ', 3	, 3)

DEC(0, ca,	Or	, _B_i8  	, "ORAB %b"	, ' ', 2	, 1)
DEC(0, da,	Or	, _B_dop	, "ORAB %d"	, ' ', 2	, 3)
DEC(0, ea,	Or	, _B_xbop8	, "ORAB %p"	, ' ', -2	, 0x66433)
DEC(0, fa,	Or 	, _B_eop 	, "ORAB %e"	, ' ', 3	, 3)

DEC(0, 85,	bit	, _Aop_i8  	, "BITA %b"	, ' ', 2	, 1)
DEC(0, 95,	bit	, _Aop_dop	, "BITA %d"	, ' ', 2	, 3)
DEC(0, a5,	bit	, _Aop_xbop8	, "BITA %p"	, ' ', -2	, 0x66433)
DEC(0, b5,	bit	, _Aop_eop 	, "BITA %e"	, ' ', 3	, 3)

DEC(0, c5,	bit	, _Bop_i8  	, "BITB %b"	, ' ', 2	, 1)
DEC(0, d5,	bit	, _Bop_dop	, "BITB %d"	, ' ', 2	, 3)
DEC(0, e5,	bit	, _Bop_xbop8	, "BITB %p"	, ' ', -2	, 0x66433)
DEC(0, f5,	bit 	, _Bop_eop 	, "BITB %e"	, ' ', 3	, 3)

DEC(0, 81,	cmp	, _Aop_i8  	, "CMPA %b"	, ' ', 2	, 1)
DEC(0, 91,	cmp	, _Aop_dop	, "CMPA %d"	, ' ', 2	, 3)
DEC(0, a1,	cmp	, _Aop_xbop8	, "CMPA %p"	, ' ', -2	, 0x66433)
DEC(0, b1,	cmp	, _Aop_eop 	, "CMPA %e"	, ' ', 3	, 3)

DEC(0, c1,	cmp	, _Bop_i8  	, "CMPB %b"	, ' ', 2	, 1)
DEC(0, d1,	cmp	, _Bop_dop	, "CMPB %d"	, ' ', 2	, 3)
DEC(0, e1,	cmp	, _Bop_xbop8	, "CMPB %p"	, ' ', -2	, 0x66433)
DEC(0, f1,	cmp 	, _Bop_eop 	, "CMPB %e"	, ' ', 3	, 3)

DEC(0, 80,	sub	, _A_i8  	, "SUBA %b"	, ' ', 2	, 1)
DEC(0, 90,	sub	, _A_dop	, "SUBA %d"	, ' ', 2	, 3)
DEC(0, a0,	sub	, _A_xbop8	, "SUBA %p"	, ' ', -2	, 0x66433)
DEC(0, b0,	sub	, _A_eop 	, "SUBA %e"	, ' ', 3	, 3)

DEC(0, c0,	sub	, _B_i8  	, "SUBB %b"	, ' ', 2	, 1)
DEC(0, d0,	sub	, _B_dop	, "SUBB %d"	, ' ', 2	, 3)
DEC(0, e0,	sub	, _B_xbop8	, "SUBB %p"	, ' ', -2	, 0x66433)
DEC(0, f0,	sub	, _B_eop 	, "SUBB %e"	, ' ', 3	, 3)

DEC(0, 82,	sbc	, _A_i8  	, "SBCA %b"	, ' ', 2	, 1)
DEC(0, 92,	sbc	, _A_dop	, "SBCA %d"	, ' ', 2	, 3)
DEC(0, a2,	sbc	, _A_xbop8	, "SBCA %p"	, ' ', -2	, 0x66433)
DEC(0, b2,	sbc	, _A_eop 	, "SBCA %e"	, ' ', 3	, 3)

DEC(0, c2,	sbc	, _B_i8  	, "SBCB %b"	, ' ', 2	, 1)
DEC(0, d2,	sbc	, _B_dop	, "SBCB %d"	, ' ', 2	, 3)
DEC(0, e2,	sbc	, _B_xbop8	, "SBCB %p"	, ' ', -2	, 0x66433)
DEC(0, f2,	sbc	, _B_eop 	, "SBCB %e"	, ' ', 3	, 3)

DEC(0, 86,	lda	, _A_i8  	, "LDAA %b"	, ' ', 2	, 1)
DEC(0, 96,	lda	, _A_dop	, "LDAA %d"	, ' ', 2	, 3)
DEC(0, a6,	lda	, _A_xbop8	, "LDAA %p"	, ' ', -2	, 0x66433)
DEC(0, b6,	lda	, _A_eop 	, "LDAA %e"	, ' ', 3	, 3)

DEC(0, c6,	lda	, _B_i8  	, "LDAB %b"	, ' ', 2	, 1)
DEC(0, d6,	lda	, _B_dop	, "LDAB %d"	, ' ', 2	, 3)
DEC(0, e6,	lda	, _B_xbop8	, "LDAB %p"	, ' ', -2	, 0x66433)
DEC(0, f6,	lda	, _B_eop 	, "LDAB %e"	, ' ', 3	, 3)

DEC(0, 83,	sub16	, _D_i16  	, "SUBD %B"	, ' ', 3	, 2)
DEC(0, 93,	sub16	, _D_dop16	, "SUBD %D"	, ' ', 2	, 3)
DEC(0, a3,	sub16	, _D_xbop16	, "SUBD %p"	, ' ', -2	, 0x66433)
DEC(0, b3,	sub16	, _D_eop16 	, "SUBD %E"	, ' ', 3	, 3)

DEC(0, b7,	exec_b7	, _NONE		, "%T"		, ' ', 2	, 0)

DEC(0x18, 06,	add	, _A_B		, "ABA"		, ' ', 2	, 2)
