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
DEC( 12, JB0		, "jb0 'a8'"	, ' ', 2, false, 2 ) //48,41A,41
DEC( 13, ADCI8		, "addc a,'i8'"	, ' ', 2, false, 2 )
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

DEC( 20, XCHIR0		, "xch a,@r0"	, ' ', 1, false, 1 )
DEC( 21, XCHIR1		, "xch a,@r1"	, ' ', 1, false, 1 )
// 22 IN A,DBB 41A,41
DEC( 23, MOVAI8		, "mov a,'i8'"	, ' ', 2, false, 2 )
DEC( 24, JMP1   	, "jmp 'a11'"   , ' ', 2, false, 2 )
// 25 EN TCNTI 48,41A,41,22
// 26 JNT0 48,41A,41,22
DEC( 27, CLRA		, "clr a"	, ' ', 1, false, 1 )
DEC( 28, XCHR0		, "xch a,r0"	, ' ', 1, false, 1 )
DEC( 29, XCHR1		, "xch a,r1"	, ' ', 1, false, 1 )
DEC( 2a, XCHR2		, "xch a,r2"	, ' ', 1, false, 1 )
DEC( 2b, XCHR3		, "xch a,r3"	, ' ', 1, false, 1 )
DEC( 2c, XCHR4		, "xch a,r4"	, ' ', 1, false, 1 )
DEC( 2d, XCHR5		, "xch a,r5"	, ' ', 1, false, 1 )
DEC( 2e, XCHR6		, "xch a,r6"	, ' ', 1, false, 1 )
DEC( 2f, XCHR7		, "xch a,r7"	, ' ', 1, false, 1 )

DEC( 30, XCHDIR0	, "xchd a,@r0"	, ' ', 1, false, 1 )
DEC( 31, XCHDIR1	, "xchd a,@r1"	, ' ', 1, false, 1 )
DEC( 32, JB1		, "jb1 'a8'"	, ' ', 2, false, 2 ) //48,41A,41
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

DEC( 40, ORLIR0		, "orl a,@r0"	, ' ', 1, false, 1 )
DEC( 41, ORLIR1		, "orl a,@r1"	, ' ', 1, false, 1 )
// 42 MOV A,T
DEC( 43, ORLI8		, "orl a,'i8'"	, ' ', 2, false, 2 )
DEC( 44, JMP2   	, "jmp 'a11'"   , ' ', 2, false, 2 )
// 45 STRT CNT
// 46 JNTI
DEC( 47, SWAPA		, "swap a"	, ' ', 1, false, 1 )
DEC( 48, ORLR0		, "orl a,r0"	, ' ', 1, false, 1 )
DEC( 49, ORLR1		, "orl a,r1"	, ' ', 1, false, 1 )
DEC( 4a, ORLR2		, "orl a,r2"	, ' ', 1, false, 1 )
DEC( 4b, ORLR3		, "orl a,r3"	, ' ', 1, false, 1 )
DEC( 4c, ORLR4		, "orl a,r4"	, ' ', 1, false, 1 )
DEC( 4d, ORLR5		, "orl a,r5"	, ' ', 1, false, 1 )
DEC( 4e, ORLR6		, "orl a,r6"	, ' ', 1, false, 1 )
DEC( 4f, ORLR7		, "orl a,r7"	, ' ', 1, false, 1 )

DEC( 50, ANLIR0		, "anl a,@r0"	, ' ', 1, false, 1 )
DEC( 51, ANLIR1		, "anl a,@r1"	, ' ', 1, false, 1 )
DEC( 52, JB2		, "jb2 'a8'"	, ' ', 2, false, 2 ) //48,41A,41
DEC( 53, ANLI8		, "anl a,'i8'"	, ' ', 2, false, 1 )
DEC( 54, CALL2  	, "call 'a11'"	, ' ', 2, false, 2 )
// 55 STRT T
// 56 JT1
DEC( 57, DAA		, "da a"	, ' ', 1, false, 1 )
DEC( 58, ANLR0		, "anl a,r0"	, ' ', 1, false, 1 )
DEC( 59, ANLR1		, "anl a,r1"	, ' ', 1, false, 1 )
DEC( 5a, ANLR2		, "anl a,r2"	, ' ', 1, false, 1 )
DEC( 5b, ANLR3		, "anl a,r3"	, ' ', 1, false, 1 )
DEC( 5c, ANLR4		, "anl a,r4"	, ' ', 1, false, 1 )
DEC( 5d, ANLR5		, "anl a,r5"	, ' ', 1, false, 1 )
DEC( 5e, ANLR6		, "anl a,r6"	, ' ', 1, false, 1 )
DEC( 5f, ANLR7		, "anl a,r7"	, ' ', 1, false, 1 )

DEC( 60, ADDIR0		, "add a,@r0"	, ' ', 1, false, 1 )
DEC( 61, ADDIR1		, "add a,@r1"	, ' ', 1, false, 1 )
// 62 MOV T,A
// 63 undefined
DEC( 64, JMP3   	, "jmp 'a11'"   , ' ', 2, false, 2 )
// 65 STOP TCNT
// 66 undefined
DEC( 67, RRCA		, "rrc a"	, ' ', 1, false, 1 )
DEC( 68, ADDR0		, "add a,r0"	, ' ', 1, false, 1 )
DEC( 69, ADDR1		, "add a,r1"	, ' ', 1, false, 1 )
DEC( 6a, ADDR2		, "add a,r2"	, ' ', 1, false, 1 )
DEC( 6b, ADDR3		, "add a,r3"	, ' ', 1, false, 1 )
DEC( 6c, ADDR4		, "add a,r4"	, ' ', 1, false, 1 )
DEC( 6d, ADDR5		, "add a,r5"	, ' ', 1, false, 1 )
DEC( 6e, ADDR6		, "add a,r6"	, ' ', 1, false, 1 )
DEC( 6f, ADDR7		, "add a,r7"	, ' ', 1, false, 1 )

DEC( 72, JB3		, "jb3 'a8'"	, ' ', 2, false, 2 ) //48,41A,41
DEC( 74, CALL3  	, "call 'a11'"	, ' ', 2, false, 2 )
DEC( 84, JMP4   	, "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( 92, JB4		, "jb4 'a8'"	, ' ', 2, false, 2 ) //48,41A,41
DEC( 94, CALL4  	, "call 'a11'"	, ' ', 2, false, 2 )
DEC( a4, JMP5   	, "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( b2, JB5		, "jb5 'a8'"	, ' ', 2, false, 2 ) //48,41A,41
DEC( b4, CALL5  	, "call 'a11'"	, ' ', 2, false, 2 )
DEC( c4, JMP6   	, "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( d2, JB6		, "jb6 'a8'"	, ' ', 2, false, 2 ) //48,41A,41
DEC( d4, CALL6  	, "call 'a11'"	, ' ', 2, false, 2 )
DEC( e4, JMP7   	, "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( f2, JB7		, "jb7 'a8'"	, ' ', 2, false, 2 ) //48,41A,41
DEC( f4, CALL7  	, "call 'a11'"	, ' ', 2, false, 2 )
