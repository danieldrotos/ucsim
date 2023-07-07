#include "gen.h"

DEC( 00, NOP	, "nop"		, ' ', 1, false, 1 )
DEC( 03, ADDI8	, "add a,'i8'"	, ' ', 2, false, 2 )

DEC( 04, JMP0   , "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( 24, JMP1   , "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( 44, JMP2   , "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( 64, JMP3   , "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( 84, JMP4   , "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( a4, JMP5   , "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( c4, JMP6   , "jmp 'a11'"   , ' ', 2, false, 2 )
DEC( e4, JMP7   , "jmp 'a11'"   , ' ', 2, false, 2 )

DEC( 07, DECA	, "dec a"	, ' ', 1, false, 1 )

DEC( 09, IN1    , "in a,p1"     , ' ', 1, false, 2 )
DEC( 0a, IN2    , "in a,p2"     , ' ', 1, false, 2 )
DEC( 0c, MOVDAP4, "movd a,p4"	, ' ', 1, false, 2 )
DEC( 0d, MOVDAP5, "movd a,p5"	, ' ', 1, false, 2 )
DEC( 0e, MOVDAP6, "movd a,p6"	, ' ', 1, false, 2 )
DEC( 0f, MOVDAP7, "movd a,p7"	, ' ', 1, false, 2 )
