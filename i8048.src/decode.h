#include "gen.h"

DEC( 00, NOP		, "nop"		, ' ', 1, false, 1 )
// 01 undefined
// 02 OUTL BUS,A 48
// 02 OUT DBB,A 41A,41
DEC( 03, ADDI8		, "add a,'i8'"	, ' ', 2, false, 2 )
DEC( 04, JMP0   	, "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( 05, ENI    	, "en i"	, ' ', 1, false, 1 )
// 06 undefined
DEC( 07, DECA		, "dec a"	, ' ', 1, false, 1 )
// 08 INS A,BUS 48
// 08 IN A,P0 21,22
DEC( 09, IN1    	, "in a,p1"     , ' ', 1, false, 2 )
DEC( 0a, IN2    	, "in a,p2"     , ' ', 1, false, 2 )
// 0b undefined
DEC( 0c, MOVDAP4	, "movd a,p4"	, ' ', 1, false, 2 )
DEC( 0d, MOVDAP5	, "movd a,p5"	, ' ', 1, false, 2 )
DEC( 0e, MOVDAP6	, "movd a,p6"	, ' ', 1, false, 2 )
DEC( 0f, MOVDAP7	, "movd a,p7"	, ' ', 1, false, 2 )

DEC( 10, INCIR0 	, "inc @r0"	, ' ', 1, false, 1 )
DEC( 11, INCIR1 	, "inc @r1"	, ' ', 1, false, 1 )
// 12 JB0 48,41A,41
DEC( 13, ADDCI8		, "addc a,'i8'"	, ' ', 2, false, 2 )
DEC( 14, CALL0  	, "call 'a11'"	, ' ', 2, false, 2 )
DEC( 15, DISI		, "dis i"	, ' ', 1, false, 1 )
// 16 JTF
DEC( 17, INCA   	, "inc a"	, ' ', 1, false, 1 )
DEC( 18, INCR0		, "inc r0"	, ' ', 1, false, 1 )
DEC( 19, INCR1		, "inc r1"	, ' ', 1, false, 1 )
DEC( 1a, INCR2		, "inc r2"	, ' ', 1, false, 1 )
DEC( 1b, INCR3		, "inc r3"	, ' ', 1, false, 1 )
DEC( 1c, INCR4		, "inc r4"	, ' ', 1, false, 1 )
DEC( 1d, INCR5		, "inc r5"	, ' ', 1, false, 1 )
DEC( 1e, INCR6		, "inc r6"	, ' ', 1, false, 1 )
DEC( 1f, INCR7		, "inc r7"	, ' ', 1, false, 1 )

DEC( 20, XCHAIR0	, "xch a,@r0"	, ' ', 1, false, 1 )
DEC( 21, XCHAIR1	, "xch a,@r1"	, ' ', 1, false, 1 )
// 22 IN A,DBB 41A,41
DEC( 23, MOVAI8		, "mov a,'i8'"	, ' ', 2, false, 2 )
DEC( 24, JMP1   	, "jmp 'a11'"   , ' ', 2, false, 2 )
// 25 EN TCNTI 48,41A,41,22
// 26 JNT0 48,41A,41,22
DEC( 27, CLRA		, "clr a"	, ' ', 1, false, 1 )
DEC( 28, XCHAR0		, "xch a,r0"	, ' ', 1, false, 1 )
DEC( 29, XCHAR1		, "xch a,r1"	, ' ', 1, false, 1 )
DEC( 2a, XCHAR2		, "xch a,r2"	, ' ', 1, false, 1 )
DEC( 2b, XCHAR3		, "xch a,r3"	, ' ', 1, false, 1 )
DEC( 2c, XCHAR4		, "xch a,r4"	, ' ', 1, false, 1 )
DEC( 2d, XCHAR5		, "xch a,r5"	, ' ', 1, false, 1 )
DEC( 2e, XCHAR6		, "xch a,r6"	, ' ', 1, false, 1 )
DEC( 2f, XCHAR7		, "xch a,r7"	, ' ', 1, false, 1 )

DEC( 30, XCHDAIR0	, "xchd a,@r0"	, ' ', 1, false, 1 )
DEC( 31, XCHDAIR1	, "xchd a,@r1"	, ' ', 1, false, 1 )
// 32 JB1 48,41A,41
// 33 undefined
DEC( 34, CALL1  	, "call 'a11'"	, ' ', 2, false, 2 )
// 35 DIS TCNTI 48,41A,41,22
// 36 JT0 48,41A,41,22
DEC( 37, CPLA		, "cpl a"	, ' ', 1, false, 1 )
// 38 undefined
// 39 OUTL P1,A
// 3a OUTL P2,A
// 3b undefined
DEC( 3c, MOVDP4A	, "movd p4,a"	, ' ', 1, false, 2 )
DEC( 3d, MOVDP5A	, "movd p5,a"	, ' ', 1, false, 2 )
DEC( 3e, MOVDP6A	, "movd p6,a"	, ' ', 1, false, 2 )
DEC( 3f, MOVDP7A	, "movd p7,a"	, ' ', 1, false, 2 )

DEC( 40, ORLAIR0	, "orl a,@r0"	, ' ', 1, false, 1 )
DEC( 41, ORLAIR1	, "orl a,@r1"	, ' ', 1, false, 1 )
// 42 MOV A,T
DEC( 43, ORLAI8		, "orl a,'i8'"	, ' ', 2, false, 2 )
DEC( 44, JMP2   	, "jmp 'a11'"   , ' ', 2, false, 2 )
// 45 STRT CNT
// 46 JNTI
DEC( 47, SWAPA		, "swap a"	, ' ', 1, false, 1 )
DEC( 48, ORLAR0		, "orl a,r0"	, ' ', 1, false, 1 )
DEC( 49, ORLAR1		, "orl a,r1"	, ' ', 1, false, 1 )
DEC( 4a, ORLAR2		, "orl a,r2"	, ' ', 1, false, 1 )
DEC( 4b, ORLAR3		, "orl a,r3"	, ' ', 1, false, 1 )
DEC( 4c, ORLAR4		, "orl a,r4"	, ' ', 1, false, 1 )
DEC( 4d, ORLAR5		, "orl a,r5"	, ' ', 1, false, 1 )
DEC( 4e, ORLAR6		, "orl a,r6"	, ' ', 1, false, 1 )
DEC( 4f, ORLAR7		, "orl a,r7"	, ' ', 1, false, 1 )

DEC( 54, CALL2  	, "call 'a11'"	, ' ', 2, false, 2 )
DEC( 64, JMP3   	, "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( 74, CALL3  	, "call 'a11'"	, ' ', 2, false, 2 )
DEC( 84, JMP4   	, "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( 94, CALL4  	, "call 'a11'"	, ' ', 2, false, 2 )
DEC( a4, JMP5   	, "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( b4, CALL5  	, "call 'a11'"	, ' ', 2, false, 2 )
DEC( c4, JMP6   	, "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( d4, CALL6  	, "call 'a11'"	, ' ', 2, false, 2 )
DEC( e4, JMP7   	, "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( f4, CALL7  	, "call 'a11'"	, ' ', 2, false, 2 )
