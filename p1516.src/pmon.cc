#include "pmon.h"

t_mem pmon[]= {
0x00000000, 0x01f2f025, /* 01f2f025 //C 00000 jmp	cold_start */
0x0000f000, 0x01f2f00e, /* 01f2f00e //C 0f000 _f000:	jmp	callin */
0x0000f001, 0x01f2f025, /* 01f2f025 //C 0f001 _f001:	jmp	cold_start */
0x0000f002, 0x01f2f306, /* 01f2f306 //C 0f002 _f002:	jmp	strchr */
0x0000f003, 0x01f2f341, /* 01f2f341 //C 0f003 _f003:	jmp	streq */
0x0000f004, 0x01f2f348, /* 01f2f348 //C 0f004 _f004:	jmp	strieq */
0x0000f005, 0x01f2f34f, /* 01f2f34f //C 0f005 _f005:	jmp	hexchar2value */
0x0000f006, 0x01f2f37e, /* 01f2f37e //C 0f006 _f006:	jmp	value2hexchar */
0x0000f007, 0x01f2f383, /* 01f2f383 //C 0f007 _f007:	jmp	htoi */
0x0000f008, 0x01f2f3a5, /* 01f2f3a5 //C 0f008 _f008:	jmp	check_uart */
0x0000f009, 0x01f2f3ce, /* 01f2f3ce //C 0f009 _f009:	jmp	read */
0x0000f00a, 0x01f2f3e0, /* 01f2f3e0 //C 0f00a _f00a:	jmp	putchar */
0x0000f00b, 0x01f2f3ec, /* 01f2f3ec //C 0f00b _f00b:	jmp	prints */
0x0000f00c, 0x01f2f400, /* 01f2f400 //C 0f00c _f00c:	jmp	printsnl */
0x0000f00d, 0x01f2f408, /* 01f2f408 //C 0f00d _f00d:	jmp	print_vhex */
0x0000f00e, 0x0600f49d, /* 0600f49d //C 0f00e st	r0,reg0 */
0x0000f00f, 0x0610f49e, /* 0610f49e //C 0f00f st	r1,reg1 */
0x0000f010, 0x0620f49f, /* 0620f49f //C 0f010 st	r2,reg2 */
0x0000f011, 0x0630f4a0, /* 0630f4a0 //C 0f011 st	r3,reg3 */
0x0000f012, 0x0640f4a1, /* 0640f4a1 //C 0f012 st	r4,reg4 */
0x0000f013, 0x0650f4a2, /* 0650f4a2 //C 0f013 st	r5,reg5 */
0x0000f014, 0x0660f4a3, /* 0660f4a3 //C 0f014 st	r6,reg6 */
0x0000f015, 0x0670f4a4, /* 0670f4a4 //C 0f015 st	r7,reg7 */
0x0000f016, 0x0680f4a5, /* 0680f4a5 //C 0f016 st	r8,reg8 */
0x0000f017, 0x0690f4a6, /* 0690f4a6 //C 0f017 st	r9,reg9 */
0x0000f018, 0x06a0f4a7, /* 06a0f4a7 //C 0f018 st	r10,reg10 */
0x0000f019, 0x06b0f4a8, /* 06b0f4a8 //C 0f019 st	r11,reg11 */
0x0000f01a, 0x06c0f4a9, /* 06c0f4a9 //C 0f01a st	r12,reg12 */
0x0000f01b, 0x06d0f4aa, /* 06d0f4aa //C 0f01b st	r13,reg13 */
0x0000f01c, 0x06e0f4ab, /* 06e0f4ab //C 0f01c st	r14,reg14 */
0x0000f01d, 0x06e0f4ac, /* 06e0f4ac //C 0f01d st	r14,reg15 */
0x0000f01e, 0x020e0000, /* 020e0000 //C 0f01e getf	r0 */
0x0000f01f, 0x0600f4ad, /* 0600f4ad //C 0f01f st	r0,regf */
0x0000f020, 0x01020001, /* 01020001 //C 0f020 mvzl	r0,1 */
0x0000f021, 0x0600f49b, /* 0600f49b //C 0f021 st	r0,called */
0x0000f022, 0x01f2f02f, /* 01f2f02f //C 0f022 jmp	common_start */
0x0000f023, 0x01f2f02f, /* 01f2f02f //C 0f023 jmp	common_start */
0x0000f024, 0x01f2f025, /* 01f2f025 //C 0f024 jmp	cold_start */
0x0000f025, 0x01020000, /* 01020000 //C 0f025 mvzl	r0,0 */
0x0000f026, 0x0600f49b, /* 0600f49b //C 0f026 st	r0,called */
0x0000f027, 0x0102f024, /* 0102f024 //C 0f027 mvzl	r0,def_zero	; restore jmp to monitor at zero */
0x0000f028, 0x0e000000, /* 0e000000 //C 0f028 ld	r0,r0 */
0x0000f029, 0x06000000, /* 06000000 //C 0f029 st	r0,0 */
0x0000f02a, 0x01020000, /* 01020000 //C 0f02a mvzl	r0,0		; def values of some regs */
0x0000f02b, 0x0600f4ad, /* 0600f4ad //C 0f02b st	r0,regf		; FALGS= 0 */
0x0000f02c, 0x0102f7ff, /* 0102f7ff //C 0f02c mvzl	r0,0xf7ff	; R13= 0xf7ff */
0x0000f02d, 0x0600f4aa, /* 0600f4aa //C 0f02d st	r0,reg13 */
0x0000f02e, 0x01f2f02f, /* 01f2f02f //C 0f02e jmp	common_start: */
0x0000f02f, 0x01d2f6db, /* 01d2f6db //C 0f02f mvzl	sp,stack_end */
0x0000f030, 0x01020001, /* 01020001 //C 0f030 mvzl	r0,1 */
0x0000f031, 0x0600f49a, /* 0600f49a //C 0f031 st	r0,echo */
0x0000f032, 0x01020000, /* 01020000 //C 0f032 mvzl	r0,0 */
0x0000f033, 0x020f0000, /* 020f0000 //C 0f033 setf	r0 */
0x0000f034, 0x011200d9, /* 011200d9 //C 0f034 mvzl	r1,217 */
0x0000f035, 0x0610ff44, /* 0610ff44 //C 0f035 st	r1,UART_CPB */
0x0000f036, 0x01120003, /* 01120003 //C 0f036 mvzl	r1,3 */
0x0000f037, 0x0610ff41, /* 0610ff41 //C 0f037 st	r1,UART_CTRL */
0x0000f038, 0x0102f4ae, /* 0102f4ae //C 0f038 mvzl	r0,msg_start */
0x0000f039, 0x0400f400, /* 0400f400 //C 0f039 call	printsnl */
0x0000f03a, 0x0400f03c, /* 0400f03c //C 0f03a call	setup_line */
0x0000f03b, 0x01f2f046, /* 01f2f046 //C 0f03b jmp	main */
0x0000f03c, 0x0ded0000, /* 0ded0000 //C 0f03c push	lr */
0x0000f03d, 0x01120000, /* 01120000 //C 0f03d mvzl	r1,0		; lptr= 0 */
0x0000f03e, 0x0610f493, /* 0610f493 //C 0f03e st	r1,line_ptr */
0x0000f03f, 0x0610f42f, /* 0610f42f //C 0f03f st	r1,line		; line[0]= 0 */
0x0000f040, 0x01120000, /* 01120000 //C 0f040 mvzl	r1,0		; at_eol= 0 */
0x0000f041, 0x0610f494, /* 0610f494 //C 0f041 st	r1,at_eol */
0x0000f042, 0x0102f4bc, /* 0102f4bc //C 0f042 mvzl	r0,prompt */
0x0000f043, 0x0400f3ec, /* 0400f3ec //C 0f043 call	prints */
0x0000f044, 0x0fed0000, /* 0fed0000 //C 0f044 pop	lr */
0x0000f045, 0x00f00e00, /* 00f00e00 //C 0f045 ret */
0x0000f046, 0x0400f3a5, /* 0400f3a5 //C 0f046 call	check_uart */
0x0000f047, 0x41f2f053, /* 41f2f053 //C 0f047 C0 jmp	no_input */
0x0000f048, 0x0400f3ce, /* 0400f3ce //C 0f048 call	read */
0x0000f049, 0x0400f054, /* 0400f054 //C 0f049 call	proc_input */
0x0000f04a, 0x41f2f053, /* 41f2f053 //C 0f04a C0 jmp	no_line */
0x0000f04b, 0x01020080, /* 01020080 //C 0f04b mvzl	r0,0x80 */
0x0000f04c, 0x020f0000, /* 020f0000 //C 0f04c setf	r0 */
0x0000f04d, 0x0400f071, /* 0400f071 //C 0f04d call	proc_line */
0x0000f04e, 0x01020040, /* 01020040 //C 0f04e mvzl	r0,0x40 */
0x0000f04f, 0x020f0000, /* 020f0000 //C 0f04f setf	r0 */
0x0000f050, 0x01020000, /* 01020000 //C 0f050 mvzl	r0,0 */
0x0000f051, 0x020f0000, /* 020f0000 //C 0f051 setf	r0 */
0x0000f052, 0x0400f03c, /* 0400f03c //C 0f052 call	setup_line */
0x0000f053, 0x01f2f046, /* 01f2f046 //C 0f053 jmp	main */
0x0000f054, 0x0ded0000, /* 0ded0000 //C 0f054 push	lr */
0x0000f055, 0x0108000a, /* 0108000a //C 0f055 cmp	r0,LF */
0x0000f056, 0x11f2f06a, /* 11f2f06a //C 0f056 EQ jmp	got_eol */
0x0000f057, 0x0108000d, /* 0108000d //C 0f057 cmp	r0,CR */
0x0000f058, 0x11f2f06a, /* 11f2f06a //C 0f058 EQ jmp	got_eol */
0x0000f059, 0x01220000, /* 01220000 //C 0f059 mvzl	r2,0		; at_aol= 0 */
0x0000f05a, 0x0620f494, /* 0620f494 //C 0f05a st	r2,at_eol */
0x0000f05b, 0x0112f493, /* 0112f493 //C 0f05b mvzl	r1,line_ptr	; line[line_ptr]= char */
0x0000f05c, 0x0e310000, /* 0e310000 //C 0f05c ld	r3,r1 */
0x0000f05d, 0x0122f42f, /* 0122f42f //C 0f05d mvzl	r2,line */
0x0000f05e, 0x08020300, /* 08020300 //C 0f05e st	r0,r2,r3 */
0x0000f05f, 0x013a0001, /* 013a0001 //C 0f05f plus	r3,1		; line_ptr++ */
0x0000f060, 0x0c310000, /* 0c310000 //C 0f060 st	r3,r1 */
0x0000f061, 0x01420000, /* 01420000 //C 0f061 mvzl	r4,0 */
0x0000f062, 0x09438200, /* 09438200 //C 0f062 st	r4,r3+,r2	; line[line_ptr]= 0 */
0x0000f063, 0x08430200, /* 08430200 //C 0f063 st	r4,r3,r2	; double 0 at end, needed by tokenizer */
0x0000f064, 0x0142f49a, /* 0142f49a //C 0f064 mvzl	r4,echo		; check if echo is turned on */
0x0000f065, 0x0e440000, /* 0e440000 //C 0f065 ld	r4,r4 */
0x0000f066, 0x024b0000, /* 024b0000 //C 0f066 sz	r4 */
0x0000f067, 0x2400f3e0, /* 2400f3e0 //C 0f067 NZ call	putchar		; echo */
0x0000f068, 0x020d0000, /* 020d0000 //C 0f068 clc */
0x0000f069, 0x01f2f06f, /* 01f2f06f //C 0f069 jmp	proc_input_ret */
0x0000f06a, 0x0112f494, /* 0112f494 //C 0f06a mvzl	r1,at_eol */
0x0000f06b, 0x0e110000, /* 0e110000 //C 0f06b ld	r1,r1 */
0x0000f06c, 0x021b0000, /* 021b0000 //C 0f06c sz	r1		; Z=0 at eol -> skip, not ready */
0x0000f06d, 0x220d0000, /* 220d0000 //C 0f06d Z0 clc */
0x0000f06e, 0x120c0000, /* 120c0000 //C 0f06e Z1 sec */
0x0000f06f, 0x0fed0000, /* 0fed0000 //C 0f06f pop	lr */
0x0000f070, 0x00f00e00, /* 00f00e00 //C 0f070 ret */
0x0000f071, 0x0ded0000, /* 0ded0000 //C 0f071 push	lr */
0x0000f072, 0x0102000a, /* 0102000a //C 0f072 mvzl	r0,LF */
0x0000f073, 0x0400f3e0, /* 0400f3e0 //C 0f073 call	putchar */
0x0000f074, 0x0700f42f, /* 0700f42f //C 0f074 ld	r0,line */
0x0000f075, 0x020b0000, /* 020b0000 //C 0f075 sz	r0 */
0x0000f076, 0x11f2f07e, /* 11f2f07e //C 0f076 jz	proc_line_ret */
0x0000f077, 0x0400f09c, /* 0400f09c //C 0f077 call	tokenize */
0x0000f078, 0x0400f0bd, /* 0400f0bd //C 0f078 call	find_cmd */
0x0000f079, 0x41f2f07c, /* 41f2f07c //C 0f079 C0 jmp	cmd_not_found */
0x0000f07a, 0x05000000, /* 05000000 //C 0f07a call	r0,0 */
0x0000f07b, 0x01f2f07e, /* 01f2f07e //C 0f07b jmp	proc_line_ret */
0x0000f07c, 0x0102f087, /* 0102f087 //C 0f07c mvzl	r0,snotfound */
0x0000f07d, 0x0400f400, /* 0400f400 //C 0f07d call	printsnl */
0x0000f07e, 0x01120001, /* 01120001 //C 0f07e mvzl	r1,1		; at_eol= 1 */
0x0000f07f, 0x0610f494, /* 0610f494 //C 0f07f st	r1,at_eol */
0x0000f080, 0x0fed0000, /* 0fed0000 //C 0f080 pop	lr */
0x0000f081, 0x00f00e00, /* 00f00e00 //C 0f081 ret */
0x0000f082, 0x00000047, /* 00000047 //C 0f082 db	71 */
0x0000f083, 0x0000006f, /* 0000006f //C 0f083 db	111 */
0x0000f084, 0x00000074, /* 00000074 //C 0f084 db	116 */
0x0000f085, 0x0000003a, /* 0000003a //C 0f085 db	58 */
0x0000f086, 0x00000000, /* 00000000 //C 0f086 db */
0x0000f087, 0x00000055, /* 00000055 //C 0f087 db	85 */
0x0000f088, 0x0000006e, /* 0000006e //C 0f088 db	110 */
0x0000f089, 0x0000006b, /* 0000006b //C 0f089 db	107 */
0x0000f08a, 0x0000006e, /* 0000006e //C 0f08a db	110 */
0x0000f08b, 0x0000006f, /* 0000006f //C 0f08b db	111 */
0x0000f08c, 0x00000077, /* 00000077 //C 0f08c db	119 */
0x0000f08d, 0x0000006e, /* 0000006e //C 0f08d db	110 */
0x0000f08e, 0x00000020, /* 00000020 //C 0f08e db	32 */
0x0000f08f, 0x00000063, /* 00000063 //C 0f08f db	99 */
0x0000f090, 0x0000006f, /* 0000006f //C 0f090 db	111 */
0x0000f091, 0x0000006d, /* 0000006d //C 0f091 db	109 */
0x0000f092, 0x0000006d, /* 0000006d //C 0f092 db	109 */
0x0000f093, 0x00000061, /* 00000061 //C 0f093 db	97 */
0x0000f094, 0x0000006e, /* 0000006e //C 0f094 db	110 */
0x0000f095, 0x00000064, /* 00000064 //C 0f095 db	100 */
0x0000f096, 0x00000000, /* 00000000 //C 0f096 db */
0x0000f097, 0x0ded0000, /* 0ded0000 //C 0f097 push	lr */
0x0000f098, 0x0112f4be, /* 0112f4be //C 0f098 mvzl	r1,delimiters */
0x0000f099, 0x0400f306, /* 0400f306 //C 0f099 call	strchr */
0x0000f09a, 0x0fed0000, /* 0fed0000 //C 0f09a pop	lr */
0x0000f09b, 0x00f00e00, /* 00f00e00 //C 0f09b ret */
0x0000f09c, 0x0ded0000, /* 0ded0000 //C 0f09c push	lr */
0x0000f09d, 0x0142f495, /* 0142f495 //C 0f09d mvzl	r4,words	; array of result */
0x0000f09e, 0x0152f42f, /* 0152f42f //C 0f09e mvzl	r5,line		; address of next char */
0x0000f09f, 0x01620000, /* 01620000 //C 0f09f mvzl	r6,0		; nuof words found */
0x0000f0a0, 0x01720000, /* 01720000 //C 0f0a0 mvzl	r7,0		; bool in_word */
0x0000f0a1, 0x0e050000, /* 0e050000 //C 0f0a1 ld	r0,r5		; pick a char */
0x0000f0a2, 0x020b0000, /* 020b0000 //C 0f0a2 sz	r0		; check end */
0x0000f0a3, 0x11f2f0ad, /* 11f2f0ad //C 0f0a3 jz	tok_delimiter	; found end, pretend delim */
0x0000f0a4, 0x0400f097, /* 0400f097 //C 0f0a4 call	is_delimiter */
0x0000f0a5, 0x31f2f0ad, /* 31f2f0ad //C 0f0a5 C1 jmp	tok_delimiter */
0x0000f0a6, 0x027b0000, /* 027b0000 //C 0f0a6 sz	r7 */
0x0000f0a7, 0x21f2f0b2, /* 21f2f0b2 //C 0f0a7 jnz	tok_next	; still inside word */
0x0000f0a8, 0x01720001, /* 01720001 //C 0f0a8 mvzl	r7,1		; in_word=true */
0x0000f0a9, 0x09568400, /* 09568400 //C 0f0a9 st	r5,r6+,r4	; record word address */
0x0000f0aa, 0x01680005, /* 01680005 //C 0f0aa cmp	r6,MAX_WORDS	; If no more space */
0x0000f0ab, 0x11f2f0b6, /* 11f2f0b6 //C 0f0ab EQ jmp	tok_ret		; then return */
0x0000f0ac, 0x01f2f0b2, /* 01f2f0b2 //C 0f0ac jmp	tok_next */
0x0000f0ad, 0x027b0000, /* 027b0000 //C 0f0ad sz	r7 */
0x0000f0ae, 0x11f2f0b2, /* 11f2f0b2 //C 0f0ae jz	tok_next	; still between words */
0x0000f0af, 0x01720000, /* 01720000 //C 0f0af mvzl	r7,0		; in_word=false */
0x0000f0b0, 0x01120000, /* 01120000 //C 0f0b0 mvzl	r1,0		; put a 0 at the end of word */
0x0000f0b1, 0x08150100, /* 08150100 //C 0f0b1 st	r1,r5,r1 */
0x0000f0b2, 0x020b0000, /* 020b0000 //C 0f0b2 sz	r0		; check EOL */
0x0000f0b3, 0x11f2f0b6, /* 11f2f0b6 //C 0f0b3 jz	tok_ret		; jump out if char==0 */
0x0000f0b4, 0x01540001, /* 01540001 //C 0f0b4 add	r5,1 */
0x0000f0b5, 0x01f2f0a1, /* 01f2f0a1 //C 0f0b5 jmp	tok_cycle */
0x0000f0b6, 0x01120000, /* 01120000 //C 0f0b6 mvzl	r1,0 */
0x0000f0b7, 0x01680005, /* 01680005 //C 0f0b7 cmp	r6,MAX_WORDS */
0x0000f0b8, 0x11f2f0bb, /* 11f2f0bb //C 0f0b8 jz	tok_end */
0x0000f0b9, 0x09168400, /* 09168400 //C 0f0b9 st	r1,r6+,r4 */
0x0000f0ba, 0x01f2f0b6, /* 01f2f0b6 //C 0f0ba jmp	tok_ret */
0x0000f0bb, 0x0fed0000, /* 0fed0000 //C 0f0bb pop	lr */
0x0000f0bc, 0x00f00e00, /* 00f00e00 //C 0f0bc ret */
0x0000f0bd, 0x0ded0000, /* 0ded0000 //C 0f0bd push	lr */
0x0000f0be, 0x0d1d0000, /* 0d1d0000 //C 0f0be push	r1 */
0x0000f0bf, 0x0d2d0000, /* 0d2d0000 //C 0f0bf push	r2 */
0x0000f0c0, 0x0d3d0000, /* 0d3d0000 //C 0f0c0 push	r3 */
0x0000f0c1, 0x0dad0000, /* 0dad0000 //C 0f0c1 push	r10 */
0x0000f0c2, 0x0700f495, /* 0700f495 //C 0f0c2 ld	r0,words	; R0= 1st word of command */
0x0000f0c3, 0x020b0000, /* 020b0000 //C 0f0c3 sz	r0 */
0x0000f0c4, 0x11f2f0f4, /* 11f2f0f4 //C 0f0c4 jz	find_cmd_false */
0x0000f0c5, 0x0e100000, /* 0e100000 //C 0f0c5 ld	r1,r0		; 1st char of word1 */
0x0000f0c6, 0x0e200001, /* 0e200001 //C 0f0c6 ld	r2,r0,1		; 2nd char */
0x0000f0c7, 0x0e300002, /* 0e300002 //C 0f0c7 ld	r3,r0,2		; 3rd char */
0x0000f0c8, 0x011fffdf, /* 011fffdf //C 0f0c8 and	r1,0xffdf	; upcase 1st char */
0x0000f0c9, 0x01180052, /* 01180052 //C 0f0c9 cmp	r1,'R' */
0x0000f0ca, 0x21f2f0e0, /* 21f2f0e0 //C 0f0ca jnz	find_not_rx */
0x0000f0cb, 0x0128002f, /* 0128002f //C 0f0cb cmp	r2,'/'		; '0'-1 */
0x0000f0cc, 0xa1f2f0e0, /* a1f2f0e0 //C 0f0cc LS jmp	find_not_rx */
0x0000f0cd, 0x01280039, /* 01280039 //C 0f0cd cmp	r2,'9' */
0x0000f0ce, 0x91f2f0e0, /* 91f2f0e0 //C 0f0ce HI jmp	find_not_rx */
0x0000f0cf, 0x023b0000, /* 023b0000 //C 0f0cf sz	r3 */
0x0000f0d0, 0x11f2f0db, /* 11f2f0db //C 0f0d0 jz	find_rx_09 */
0x0000f0d1, 0x01280031, /* 01280031 //C 0f0d1 cmp	r2,'1'		; first char must be '1' */
0x0000f0d2, 0x21f2f0e0, /* 21f2f0e0 //C 0f0d2 jnz	find_not_rx */
0x0000f0d3, 0x0138002f, /* 0138002f //C 0f0d3 cmp	r3,'/'		; '0'-1 */
0x0000f0d4, 0xa1f2f0e0, /* a1f2f0e0 //C 0f0d4 LS jmp	find_not_rx */
0x0000f0d5, 0x01380035, /* 01380035 //C 0f0d5 cmp	r3,'5' */
0x0000f0d6, 0x91f2f0e0, /* 91f2f0e0 //C 0f0d6 HI jmp	find_not_rx */
0x0000f0d7, 0x01360030, /* 01360030 //C 0f0d7 sub	r3,'0' */
0x0000f0d8, 0x0134000a, /* 0134000a //C 0f0d8 add	r3,10 */
0x0000f0d9, 0x0630f49c, /* 0630f49c //C 0f0d9 st	r3,nuof_reg */
0x0000f0da, 0x01f2f0dd, /* 01f2f0dd //C 0f0da jmp	find_rx */
0x0000f0db, 0x01260030, /* 01260030 //C 0f0db sub	r2,'0' */
0x0000f0dc, 0x0620f49c, /* 0620f49c //C 0f0dc st	r2,nuof_reg */
0x0000f0dd, 0x0102f2c4, /* 0102f2c4 //C 0f0dd mvzl	r0,cmd_rx */
0x0000f0de, 0x020c0000, /* 020c0000 //C 0f0de sec */
0x0000f0df, 0x01f2f0ff, /* 01f2f0ff //C 0f0df jmp	find_cmd_ret */
0x0000f0e0, 0x01a2f4da, /* 01a2f4da //C 0f0e0 mvzl	r10,commands */
0x0000f0e1, 0x0e2a0000, /* 0e2a0000 //C 0f0e1 ld	r2,r10		; R2= cmd addr */
0x0000f0e2, 0x022b0000, /* 022b0000 //C 0f0e2 sz	r2 */
0x0000f0e3, 0x11f2f0f4, /* 11f2f0f4 //C 0f0e3 jz	find_cmd_false */
0x0000f0e4, 0x01a40001, /* 01a40001 //C 0f0e4 add	r10,1 */
0x0000f0e5, 0x00100a00, /* 00100a00 //C 0f0e5 mov	r1,r10		; R1= cmd string */
0x0000f0e6, 0x01a40001, /* 01a40001 //C 0f0e6 add	r10,1 */
0x0000f0e7, 0x0e3a0000, /* 0e3a0000 //C 0f0e7 ld	r3,r10 */
0x0000f0e8, 0x023b0000, /* 023b0000 //C 0f0e8 sz	r3 */
0x0000f0e9, 0x21f2f0e6, /* 21f2f0e6 //C 0f0e9 jnz	find_cmd_fw */
0x0000f0ea, 0x01a40001, /* 01a40001 //C 0f0ea add	r10,1 */
0x0000f0eb, 0x0400f341, /* 0400f341 //C 0f0eb call	streq */
0x0000f0ec, 0x41f2f0e1, /* 41f2f0e1 //C 0f0ec C0 jmp	find_cmd_cyc */
0x0000f0ed, 0x00000200, /* 00000200 //C 0f0ed mov	r0,r2 */
0x0000f0ee, 0x020c0000, /* 020c0000 //C 0f0ee sec */
0x0000f0ef, 0x01f2f0ff, /* 01f2f0ff //C 0f0ef jmp	find_cmd_ret */
0x0000f0f0, 0x0000002f, /* 0000002f //C 0f0f0 db	47 */
0x0000f0f1, 0x0000002f, /* 0000002f //C 0f0f1 db	47 */
0x0000f0f2, 0x00000043, /* 00000043 //C 0f0f2 db	67 */
0x0000f0f3, 0x00000000, /* 00000000 //C 0f0f3 db */
0x0000f0f4, 0x01040001, /* 01040001 //C 0f0f4 add	r0,1		; check second word */
0x0000f0f5, 0x0e100000, /* 0e100000 //C 0f0f5 ld	r1,r0		; for //C command */
0x0000f0f6, 0x021b0000, /* 021b0000 //C 0f0f6 sz	r1 */
0x0000f0f7, 0x11f2f0fd, /* 11f2f0fd //C 0f0f7 jz	find_cmd_very_false */
0x0000f0f8, 0x0102f0f0, /* 0102f0f0 //C 0f0f8 mvzl	r0,c_cmd_name */
0x0000f0f9, 0x0400f341, /* 0400f341 //C 0f0f9 call	streq */
0x0000f0fa, 0x21f2f0fd, /* 21f2f0fd //C 0f0fa jnz	find_cmd_very_false */
0x0000f0fb, 0x0122f18d, /* 0122f18d //C 0f0fb mvzl	r2,cmd_c */
0x0000f0fc, 0x01f2f0ed, /* 01f2f0ed //C 0f0fc jmp	find_cmd_true */
0x0000f0fd, 0x020d0000, /* 020d0000 //C 0f0fd clc */
0x0000f0fe, 0x01020000, /* 01020000 //C 0f0fe mvzl	r0,0 */
0x0000f0ff, 0x0fad0000, /* 0fad0000 //C 0f0ff pop	r10 */
0x0000f100, 0x0f3d0000, /* 0f3d0000 //C 0f100 pop	r3 */
0x0000f101, 0x0f2d0000, /* 0f2d0000 //C 0f101 pop	r2 */
0x0000f102, 0x0f1d0000, /* 0f1d0000 //C 0f102 pop	r1 */
0x0000f103, 0x0fed0000, /* 0fed0000 //C 0f103 pop	lr */
0x0000f104, 0x00f00e00, /* 00f00e00 //C 0f104 ret */
0x0000f105, 0x0ded0000, /* 0ded0000 //C 0f105 push	lr */
0x0000f106, 0x0122f495, /* 0122f495 //C 0f106 mvzl	r2,words */
0x0000f107, 0x01020000, /* 01020000 //C 0f107 mvzl	r0,0 */
0x0000f108, 0x0e420001, /* 0e420001 //C 0f108 ld	r4,r2,1		; addr */
0x0000f109, 0x0e520002, /* 0e520002 //C 0f109 ld	r5,r2,2		; value */
0x0000f10a, 0x024b0000, /* 024b0000 //C 0f10a sz 	r4 */
0x0000f10b, 0x11f2f12c, /* 11f2f12c //C 0f10b jz	m_ret */
0x0000f10c, 0x00000400, /* 00000400 //C 0f10c mov	r0,r4 */
0x0000f10d, 0x0400f383, /* 0400f383 //C 0f10d call	htoi */
0x0000f10e, 0x00400100, /* 00400100 //C 0f10e mov	r4,r1 */
0x0000f10f, 0x31f2f113, /* 31f2f113 //C 0f10f C1 jmp	m_addr_ok */
0x0000f110, 0x0102f12e, /* 0102f12e //C 0f110 mvzl	r0,m_err_addr */
0x0000f111, 0x0400f400, /* 0400f400 //C 0f111 call	printsnl */
0x0000f112, 0x01f2f12c, /* 01f2f12c //C 0f112 jmp	m_ret */
0x0000f113, 0x025b0000, /* 025b0000 //C 0f113 sz	r5 */
0x0000f114, 0x11f2f122, /* 11f2f122 //C 0f114 jz	m_read */
0x0000f115, 0x0148f6ea, /* 0148f6ea //C 0f115 cmp	r4,the_end */
0x0000f116, 0x91f2f11a, /* 91f2f11a //C 0f116 HI jmp	m_addrv_ok */
0x0000f117, 0x0102f13c, /* 0102f13c //C 0f117 mvzl	r0,m_err_addrv */
0x0000f118, 0x0400f400, /* 0400f400 //C 0f118 call	printsnl */
0x0000f119, 0x01f2f12c, /* 01f2f12c //C 0f119 jmp	m_ret */
0x0000f11a, 0x00000500, /* 00000500 //C 0f11a mov	r0,r5 */
0x0000f11b, 0x0400f383, /* 0400f383 //C 0f11b call	htoi */
0x0000f11c, 0x00500100, /* 00500100 //C 0f11c mov	r5,r1 */
0x0000f11d, 0x31f2f121, /* 31f2f121 //C 0f11d C1 jmp	m_value_ok */
0x0000f11e, 0x0102f14e, /* 0102f14e //C 0f11e mvzl	r0,m_err_value */
0x0000f11f, 0x0400f400, /* 0400f400 //C 0f11f call	printsnl */
0x0000f120, 0x01f2f12c, /* 01f2f12c //C 0f120 jmp	m_ret */
0x0000f121, 0x0c540000, /* 0c540000 //C 0f121 st	r5,r4 */
0x0000f122, 0x00000400, /* 00000400 //C 0f122 mov	r0,r4 */
0x0000f123, 0x01120004, /* 01120004 //C 0f123 mvzl	r1,4 */
0x0000f124, 0x0400f408, /* 0400f408 //C 0f124 call	print_vhex */
0x0000f125, 0x01020020, /* 01020020 //C 0f125 mvzl	r0,0x20 */
0x0000f126, 0x0400f3e0, /* 0400f3e0 //C 0f126 call	putchar */
0x0000f127, 0x0e040000, /* 0e040000 //C 0f127 ld	r0,r4 */
0x0000f128, 0x01120004, /* 01120004 //C 0f128 mvzl	r1,4 */
0x0000f129, 0x0400f408, /* 0400f408 //C 0f129 call	print_vhex */
0x0000f12a, 0x0102000a, /* 0102000a //C 0f12a mvzl	r0,LF */
0x0000f12b, 0x0400f3e0, /* 0400f3e0 //C 0f12b call	putchar */
0x0000f12c, 0x0fed0000, /* 0fed0000 //C 0f12c pop	lr */
0x0000f12d, 0x00f00e00, /* 00f00e00 //C 0f12d ret */
0x0000f12e, 0x00000041, /* 00000041 //C 0f12e db	65 */
0x0000f12f, 0x00000064, /* 00000064 //C 0f12f db	100 */
0x0000f130, 0x00000064, /* 00000064 //C 0f130 db	100 */
0x0000f131, 0x00000072, /* 00000072 //C 0f131 db	114 */
0x0000f132, 0x00000065, /* 00000065 //C 0f132 db	101 */
0x0000f133, 0x00000073, /* 00000073 //C 0f133 db	115 */
0x0000f134, 0x00000073, /* 00000073 //C 0f134 db	115 */
0x0000f135, 0x00000020, /* 00000020 //C 0f135 db	32 */
0x0000f136, 0x00000065, /* 00000065 //C 0f136 db	101 */
0x0000f137, 0x00000072, /* 00000072 //C 0f137 db	114 */
0x0000f138, 0x00000072, /* 00000072 //C 0f138 db	114 */
0x0000f139, 0x0000006f, /* 0000006f //C 0f139 db	111 */
0x0000f13a, 0x00000072, /* 00000072 //C 0f13a db	114 */
0x0000f13b, 0x00000000, /* 00000000 //C 0f13b db */
0x0000f13c, 0x0000004d, /* 0000004d //C 0f13c db	77 */
0x0000f13d, 0x0000006f, /* 0000006f //C 0f13d db	111 */
0x0000f13e, 0x0000006e, /* 0000006e //C 0f13e db	110 */
0x0000f13f, 0x00000069, /* 00000069 //C 0f13f db	105 */
0x0000f140, 0x00000074, /* 00000074 //C 0f140 db	116 */
0x0000f141, 0x0000006f, /* 0000006f //C 0f141 db	111 */
0x0000f142, 0x00000072, /* 00000072 //C 0f142 db	114 */
0x0000f143, 0x00000027, /* 00000027 //C 0f143 db	39 */
0x0000f144, 0x00000073, /* 00000073 //C 0f144 db	115 */
0x0000f145, 0x00000020, /* 00000020 //C 0f145 db	32 */
0x0000f146, 0x00000061, /* 00000061 //C 0f146 db	97 */
0x0000f147, 0x00000064, /* 00000064 //C 0f147 db	100 */
0x0000f148, 0x00000064, /* 00000064 //C 0f148 db	100 */
0x0000f149, 0x00000072, /* 00000072 //C 0f149 db	114 */
0x0000f14a, 0x00000065, /* 00000065 //C 0f14a db	101 */
0x0000f14b, 0x00000073, /* 00000073 //C 0f14b db	115 */
0x0000f14c, 0x00000073, /* 00000073 //C 0f14c db	115 */
0x0000f14d, 0x00000000, /* 00000000 //C 0f14d db */
0x0000f14e, 0x00000056, /* 00000056 //C 0f14e db	86 */
0x0000f14f, 0x00000061, /* 00000061 //C 0f14f db	97 */
0x0000f150, 0x0000006c, /* 0000006c //C 0f150 db	108 */
0x0000f151, 0x00000075, /* 00000075 //C 0f151 db	117 */
0x0000f152, 0x00000065, /* 00000065 //C 0f152 db	101 */
0x0000f153, 0x00000020, /* 00000020 //C 0f153 db	32 */
0x0000f154, 0x00000065, /* 00000065 //C 0f154 db	101 */
0x0000f155, 0x00000072, /* 00000072 //C 0f155 db	114 */
0x0000f156, 0x00000072, /* 00000072 //C 0f156 db	114 */
0x0000f157, 0x0000006f, /* 0000006f //C 0f157 db	111 */
0x0000f158, 0x00000072, /* 00000072 //C 0f158 db	114 */
0x0000f159, 0x00000000, /* 00000000 //C 0f159 db */
0x0000f15a, 0x0ded0000, /* 0ded0000 //C 0f15a push	lr */
0x0000f15b, 0x0122f495, /* 0122f495 //C 0f15b mvzl	r2,words */
0x0000f15c, 0x0e020001, /* 0e020001 //C 0f15c ld	r0,r2,1		; start address */
0x0000f15d, 0x0400f383, /* 0400f383 //C 0f15d call	htoi */
0x0000f15e, 0x00300100, /* 00300100 //C 0f15e mov	r3,r1 */
0x0000f15f, 0x0e020002, /* 0e020002 //C 0f15f ld	r0,r2,2		; end address */
0x0000f160, 0x020b0000, /* 020b0000 //C 0f160 sz	r0 */
0x0000f161, 0x21f2f165, /* 21f2f165 //C 0f161 jnz	d_end_ok */
0x0000f162, 0x00400300, /* 00400300 //C 0f162 mov	r4,r3 */
0x0000f163, 0x01440010, /* 01440010 //C 0f163 add	r4,0x10 */
0x0000f164, 0x01f2f167, /* 01f2f167 //C 0f164 jmp	d_chk_end */
0x0000f165, 0x0400f383, /* 0400f383 //C 0f165 call	htoi */
0x0000f166, 0x00400100, /* 00400100 //C 0f166 mov	r4,r1 */
0x0000f167, 0x00380400, /* 00380400 //C 0f167 cmp	r3,r4		; check if start>end */
0x0000f168, 0x91f2f177, /* 91f2f177 //C 0f168 HI jmp d_bad */
0x0000f169, 0x00000300, /* 00000300 //C 0f169 mov	r0,r3		; print address */
0x0000f16a, 0x01120004, /* 01120004 //C 0f16a mvzl	r1,4 */
0x0000f16b, 0x0400f408, /* 0400f408 //C 0f16b call	print_vhex */
0x0000f16c, 0x01020020, /* 01020020 //C 0f16c mvzl	r0,0x20		; print one space */
0x0000f16d, 0x0400f3e0, /* 0400f3e0 //C 0f16d call	putchar */
0x0000f16e, 0x0e030000, /* 0e030000 //C 0f16e ld	r0,r3		; load data */
0x0000f16f, 0x01120004, /* 01120004 //C 0f16f mvzl	r1,4		; print data */
0x0000f170, 0x0400f408, /* 0400f408 //C 0f170 call	print_vhex */
0x0000f171, 0x0102000a, /* 0102000a //C 0f171 mvzl	r0,LF		; print new line */
0x0000f172, 0x0400f3e0, /* 0400f3e0 //C 0f172 call	putchar */
0x0000f173, 0x00380400, /* 00380400 //C 0f173 cmp	r3,r4 */
0x0000f174, 0x11f2f179, /* 11f2f179 //C 0f174 jz	d_ret */
0x0000f175, 0x01340001, /* 01340001 //C 0f175 add	r3,1 */
0x0000f176, 0x01f2f169, /* 01f2f169 //C 0f176 jmp	d_cyc */
0x0000f177, 0x0102f17b, /* 0102f17b //C 0f177 mvzl	r0,d_err_bad */
0x0000f178, 0x0400f400, /* 0400f400 //C 0f178 call	printsnl */
0x0000f179, 0x0fed0000, /* 0fed0000 //C 0f179 pop	lr */
0x0000f17a, 0x00f00e00, /* 00f00e00 //C 0f17a ret */
0x0000f17b, 0x00000057, /* 00000057 //C 0f17b db	87 */
0x0000f17c, 0x00000072, /* 00000072 //C 0f17c db	114 */
0x0000f17d, 0x0000006f, /* 0000006f //C 0f17d db	111 */
0x0000f17e, 0x0000006e, /* 0000006e //C 0f17e db	110 */
0x0000f17f, 0x00000067, /* 00000067 //C 0f17f db	103 */
0x0000f180, 0x00000020, /* 00000020 //C 0f180 db	32 */
0x0000f181, 0x00000065, /* 00000065 //C 0f181 db	101 */
0x0000f182, 0x0000006e, /* 0000006e //C 0f182 db	110 */
0x0000f183, 0x00000064, /* 00000064 //C 0f183 db	100 */
0x0000f184, 0x00000020, /* 00000020 //C 0f184 db	32 */
0x0000f185, 0x00000061, /* 00000061 //C 0f185 db	97 */
0x0000f186, 0x00000064, /* 00000064 //C 0f186 db	100 */
0x0000f187, 0x00000064, /* 00000064 //C 0f187 db	100 */
0x0000f188, 0x00000072, /* 00000072 //C 0f188 db	114 */
0x0000f189, 0x00000065, /* 00000065 //C 0f189 db	101 */
0x0000f18a, 0x00000073, /* 00000073 //C 0f18a db	115 */
0x0000f18b, 0x00000073, /* 00000073 //C 0f18b db	115 */
0x0000f18c, 0x00000000, /* 00000000 //C 0f18c db */
0x0000f18d, 0x00f00e00, /* 00f00e00 //C 0f18d ret */
0x0000f18e, 0x0ded0000, /* 0ded0000 //C 0f18e push	lr */
0x0000f18f, 0x01a20000, /* 01a20000 //C 0f18f mvzl	r10,0		; state (nr of words) */
0x0000f190, 0x01820000, /* 01820000 //C 0f190 mvzl	r8,0		; value */
0x0000f191, 0x0162003f, /* 0162003f //C 0f191 mvzl	r6,'?'		; Record type */
0x0000f192, 0x0400f3a5, /* 0400f3a5 //C 0f192 call	check_uart */
0x0000f193, 0x41f2f192, /* 41f2f192 //C 0f193 C0 jmp	l_cyc */
0x0000f194, 0x0400f3ce, /* 0400f3ce //C 0f194 call	read */
0x0000f195, 0x00b00000, /* 00b00000 //C 0f195 mov	r11,r0		; Copy of char in R11 */
0x0000f196, 0x0108000a, /* 0108000a //C 0f196 cmp	r0,10		; check EOL chars */
0x0000f197, 0x11f2f1e1, /* 11f2f1e1 //C 0f197 jz	l_eol */
0x0000f198, 0x0108000d, /* 0108000d //C 0f198 cmp	r0,13 */
0x0000f199, 0x11f2f1e1, /* 11f2f1e1 //C 0f199 jz	l_eol */
0x0000f19a, 0x01a80000, /* 01a80000 //C 0f19a cmp	r10,0 */
0x0000f19b, 0x21f2f1ab, /* 21f2f1ab //C 0f19b jnz	l_no0 */
0x0000f19c, 0x0400f34f, /* 0400f34f //C 0f19c call	hexchar2value */
0x0000f19d, 0x41f2f1a5, /* 41f2f1a5 //C 0f19d C0 jmp	l_eof_0 */
0x0000f19e, 0x02880000, /* 02880000 //C 0f19e shl	r8		; shift val(char) into value */
0x0000f19f, 0x02880000, /* 02880000 //C 0f19f shl	r8 */
0x0000f1a0, 0x02880000, /* 02880000 //C 0f1a0 shl	r8 */
0x0000f1a1, 0x02880000, /* 02880000 //C 0f1a1 shl	r8 */
0x0000f1a2, 0x010b000f, /* 010b000f //C 0f1a2 btst	r0,0xf */
0x0000f1a3, 0x008d0000, /* 008d0000 //C 0f1a3 or	r8,r0 */
0x0000f1a4, 0x01f2f192, /* 01f2f192 //C 0f1a4 jmp	l_cyc */
0x0000f1a5, 0x01a20001, /* 01a20001 //C 0f1a5 mvzl	r10,1		; state0 -> state1 */
0x0000f1a6, 0x0162003f, /* 0162003f //C 0f1a6 mvzl	r6,'?'		; No //C yet */
0x0000f1a7, 0x01b8002f, /* 01b8002f //C 0f1a7 cmp	r11,'/'		; is it start of // */
0x0000f1a8, 0x11720001, /* 11720001 //C 0f1a8 z1 mvzl	r7,1		; Yes, first / found */
0x0000f1a9, 0x21720000, /* 21720000 //C 0f1a9 z0 mvzl	r7,0		; No '/' yet */
0x0000f1aa, 0x01f2f192, /* 01f2f192 //C 0f1aa jmp	l_cyc */
0x0000f1ab, 0x01a80001, /* 01a80001 //C 0f1ab cmp	r10,1 */
0x0000f1ac, 0x21f2f1c4, /* 21f2f1c4 //C 0f1ac jnz	l_no1 */
0x0000f1ad, 0x027b0000, /* 027b0000 //C 0f1ad sz	r7 */
0x0000f1ae, 0x21f2f1b3, /* 21f2f1b3 //C 0f1ae jnz	l_s1_2nd */
0x0000f1af, 0x0108002f, /* 0108002f //C 0f1af cmp	r0,'/' */
0x0000f1b0, 0x21f2f192, /* 21f2f192 //C 0f1b0 jnz	l_cyc */
0x0000f1b1, 0x01720001, /* 01720001 //C 0f1b1 mvzl	r7,1 */
0x0000f1b2, 0x01f2f192, /* 01f2f192 //C 0f1b2 jmp	l_cyc */
0x0000f1b3, 0x0108002f, /* 0108002f //C 0f1b3 cmp	r0,'/' */
0x0000f1b4, 0x11f2f192, /* 11f2f192 //C 0f1b4 jz	l_cyc */
0x0000f1b5, 0x01080043, /* 01080043 //C 0f1b5 cmp	r0,'C' */
0x0000f1b6, 0x21f2f1bc, /* 21f2f1bc //C 0f1b6 jnz	l_s1_noC */
0x0000f1b7, 0x01620043, /* 01620043 //C 0f1b7 mvzl	r6,'C' */
0x0000f1b8, 0x01a20002, /* 01a20002 //C 0f1b8 mvzl	r10,2 */
0x0000f1b9, 0x01920000, /* 01920000 //C 0f1b9 mvzl	r9,0		; address= 0 */
0x0000f1ba, 0x01520000, /* 01520000 //C 0f1ba mvzl	r5,0		; where we are in word: before */
0x0000f1bb, 0x01f2f192, /* 01f2f192 //C 0f1bb jmp	l_cyc */
0x0000f1bc, 0x01080045, /* 01080045 //C 0f1bc cmp	r0,'E' */
0x0000f1bd, 0x21f2f1c1, /* 21f2f1c1 //C 0f1bd jnz	l_s1_noE */
0x0000f1be, 0x01620045, /* 01620045 //C 0f1be mvzl	r6,'E' */
0x0000f1bf, 0x01a20003, /* 01a20003 //C 0f1bf mvzl	r10,3 */
0x0000f1c0, 0x01f2f192, /* 01f2f192 //C 0f1c0 jmp	l_cyc */
0x0000f1c1, 0x0400f3e0, /* 0400f3e0 //C 0f1c1 call	putchar		; print record type */
0x0000f1c2, 0x01a2000f, /* 01a2000f //C 0f1c2 mvzl	r10,0xf		; special state: skip everything */
0x0000f1c3, 0x01f2f192, /* 01f2f192 //C 0f1c3 jmp	l_cyc */
0x0000f1c4, 0x01a80002, /* 01a80002 //C 0f1c4 cmp	r10,2 */
0x0000f1c5, 0x21f2f1d9, /* 21f2f1d9 //C 0f1c5 jnz	l_no2 */
0x0000f1c6, 0x01580000, /* 01580000 //C 0f1c6 cmp	r5,0 */
0x0000f1c7, 0x21f2f1d2, /* 21f2f1d2 //C 0f1c7 jnz	l_s2_no0 */
0x0000f1c8, 0x0400f34f, /* 0400f34f //C 0f1c8 call	hexchar2value */
0x0000f1c9, 0x41f2f192, /* 41f2f192 //C 0f1c9 C0 jmp	l_cyc */
0x0000f1ca, 0x01520001, /* 01520001 //C 0f1ca mvzl	r5,1 */
0x0000f1cb, 0x02980000, /* 02980000 //C 0f1cb shl	r9 */
0x0000f1cc, 0x02980000, /* 02980000 //C 0f1cc shl	r9 */
0x0000f1cd, 0x02980000, /* 02980000 //C 0f1cd shl	r9 */
0x0000f1ce, 0x02980000, /* 02980000 //C 0f1ce shl	r9 */
0x0000f1cf, 0x010b000f, /* 010b000f //C 0f1cf btst	r0,0xf */
0x0000f1d0, 0x009d0000, /* 009d0000 //C 0f1d0 or	r9,r0 */
0x0000f1d1, 0x01f2f192, /* 01f2f192 //C 0f1d1 jmp	l_cyc */
0x0000f1d2, 0x01580001, /* 01580001 //C 0f1d2 cmp	r5,1 */
0x0000f1d3, 0x21f2f1d8, /* 21f2f1d8 //C 0f1d3 jnz	l_s2_no1 */
0x0000f1d4, 0x0400f34f, /* 0400f34f //C 0f1d4 call	hexchar2value */
0x0000f1d5, 0x31f2f1cb, /* 31f2f1cb //C 0f1d5 C1 jmp	l_s2_got */
0x0000f1d6, 0x01520002, /* 01520002 //C 0f1d6 mvzl	r5,2 */
0x0000f1d7, 0x01f2f192, /* 01f2f192 //C 0f1d7 jmp	l_cyc */
0x0000f1d8, 0x01f2f192, /* 01f2f192 //C 0f1d8 jmp	l_cyc */
0x0000f1d9, 0x01a80003, /* 01a80003 //C 0f1d9 cmp	r10,3 */
0x0000f1da, 0x21f2f1dc, /* 21f2f1dc //C 0f1da jnz	l_no3 */
0x0000f1db, 0x01f2f192, /* 01f2f192 //C 0f1db jmp	l_cyc		; do nothing, just wait EOL */
0x0000f1dc, 0x01a8000f, /* 01a8000f //C 0f1dc cmp	r10,0xf */
0x0000f1dd, 0x01f2f1df, /* 01f2f1df //C 0f1dd jmp	l_nof */
0x0000f1de, 0x01f2f192, /* 01f2f192 //C 0f1de jmp	l_cyc		; just skip */
0x0000f1df, 0x01f2f192, /* 01f2f192 //C 0f1df jmp	l_cyc */
0x0000f1e0, 0x01f2f1f7, /* 01f2f1f7 //C 0f1e0 jmp	l_ret */
0x0000f1e1, 0x01a80000, /* 01a80000 //C 0f1e1 cmp	r10,0		; in state0 */
0x0000f1e2, 0x11f2f1f1, /* 11f2f1f1 //C 0f1e2 jz	l_back_to_0	; just restart */
0x0000f1e3, 0x01a80001, /* 01a80001 //C 0f1e3 cmp	r10,1		; in state1 */
0x0000f1e4, 0x11f2f1f1, /* 11f2f1f1 //C 0f1e4 jz	l_back_to_0 	;l_cyc ;l_bad ; garbage */
0x0000f1e5, 0x01a80002, /* 01a80002 //C 0f1e5 cmp	r10,2		; in state2 */
0x0000f1e6, 0x11f2f1ed, /* 11f2f1ed //C 0f1e6 jz	l_proc		; process record */
0x0000f1e7, 0x01a80003, /* 01a80003 //C 0f1e7 cmp	r10,3		; in state3 */
0x0000f1e8, 0x11f2f1f7, /* 11f2f1f7 //C 0f1e8 jz	l_ret		; eol in end record: finish */
0x0000f1e9, 0x01a8000f, /* 01a8000f //C 0f1e9 cmp	r10,0xf		; in state skip */
0x0000f1ea, 0x11f2f1f1, /* 11f2f1f1 //C 0f1ea jz	l_back_to_0	; reset state for new line */
0x0000f1eb, 0x01f2f192, /* 01f2f192 //C 0f1eb jmp	l_cyc */
0x0000f1ec, 0x01f2f1f7, /* 01f2f1f7 //C 0f1ec jmp	l_ret */
0x0000f1ed, 0x01680043, /* 01680043 //C 0f1ed cmp	r6,'C'		; is it a C record? */
0x0000f1ee, 0x1c890000, /* 1c890000 //C 0f1ee z st	r8,r9		; store */
0x0000f1ef, 0x00000600, /* 00000600 //C 0f1ef mov	r0,r6		; echo record type */
0x0000f1f0, 0x0400f3e0, /* 0400f3e0 //C 0f1f0 call	putchar */
0x0000f1f1, 0x0102002e, /* 0102002e //C 0f1f1 mvzl	r0,'.' */
0x0000f1f2, 0x0400f3e0, /* 0400f3e0 //C 0f1f2 call	putchar */
0x0000f1f3, 0x01a20000, /* 01a20000 //C 0f1f3 mvzl	r10,0 */
0x0000f1f4, 0x01820000, /* 01820000 //C 0f1f4 mvzl	r8,0 */
0x0000f1f5, 0x0162003f, /* 0162003f //C 0f1f5 mvzl	r6,'?' */
0x0000f1f6, 0x01f2f192, /* 01f2f192 //C 0f1f6 jmp	l_cyc */
0x0000f1f7, 0x0102000a, /* 0102000a //C 0f1f7 mvzl	r0,LF */
0x0000f1f8, 0x0400f3e0, /* 0400f3e0 //C 0f1f8 call	putchar */
0x0000f1f9, 0x0fed0000, /* 0fed0000 //C 0f1f9 pop	lr */
0x0000f1fa, 0x00f00e00, /* 00f00e00 //C 0f1fa ret */
0x0000f1fb, 0x0ded0000, /* 0ded0000 //C 0f1fb push	lr */
0x0000f1fc, 0x0122f495, /* 0122f495 //C 0f1fc mvzl	r2,words */
0x0000f1fd, 0x0e020001, /* 0e020001 //C 0f1fd ld	r0,r2,1		; address */
0x0000f1fe, 0x020b0000, /* 020b0000 //C 0f1fe sz	r0 */
0x0000f1ff, 0x11f2f222, /* 11f2f222 //C 0f1ff jz	g_no_addr */
0x0000f200, 0x0400f383, /* 0400f383 //C 0f200 call	htoi */
0x0000f201, 0x00b00100, /* 00b00100 //C 0f201 mov	r11,r1 */
0x0000f202, 0x0102f236, /* 0102f236 //C 0f202 mvzl	r0,d_msg_run */
0x0000f203, 0x0400f3ec, /* 0400f3ec //C 0f203 call	prints */
0x0000f204, 0x00000b00, /* 00000b00 //C 0f204 mov	r0,r11 */
0x0000f205, 0x01120004, /* 01120004 //C 0f205 mvzl	r1,4 */
0x0000f206, 0x0400f408, /* 0400f408 //C 0f206 call	print_vhex */
0x0000f207, 0x0102000a, /* 0102000a //C 0f207 mvzl	r0,LF */
0x0000f208, 0x0400f3e0, /* 0400f3e0 //C 0f208 call	putchar */
0x0000f209, 0x06b0f4ac, /* 06b0f4ac //C 0f209 st	r11,reg15 */
0x0000f20a, 0x0122ff43, /* 0122ff43 //C 0f20a mvzl	r2,UART_TSTAT */
0x0000f20b, 0x0e920000, /* 0e920000 //C 0f20b ld	r9,r2 */
0x0000f20c, 0x019c0001, /* 019c0001 //C 0f20c test	r9,1 */
0x0000f20d, 0x11f2f20b, /* 11f2f20b //C 0f20d jz	g_wait_tc */
0x0000f20e, 0x07000000, /* 07000000 //C 0f20e ld	r0,0 */
0x0000f20f, 0x0600f49b, /* 0600f49b //C 0f20f st	r0,called */
0x0000f210, 0x0700f4ad, /* 0700f4ad //C 0f210 ld	r0,regf */
0x0000f211, 0x020f0000, /* 020f0000 //C 0f211 setf	r0 */
0x0000f212, 0x0700f49d, /* 0700f49d //C 0f212 ld	r0,reg0 */
0x0000f213, 0x0710f49e, /* 0710f49e //C 0f213 ld	r1,reg1 */
0x0000f214, 0x0720f49f, /* 0720f49f //C 0f214 ld	r2,reg2 */
0x0000f215, 0x0730f4a0, /* 0730f4a0 //C 0f215 ld	r3,reg3 */
0x0000f216, 0x0740f4a1, /* 0740f4a1 //C 0f216 ld	r4,reg4 */
0x0000f217, 0x0750f4a2, /* 0750f4a2 //C 0f217 ld	r5,reg5 */
0x0000f218, 0x0760f4a3, /* 0760f4a3 //C 0f218 ld	r6,reg6 */
0x0000f219, 0x0770f4a4, /* 0770f4a4 //C 0f219 ld	r7,reg7 */
0x0000f21a, 0x0780f4a5, /* 0780f4a5 //C 0f21a ld	r8,reg8 */
0x0000f21b, 0x0790f4a6, /* 0790f4a6 //C 0f21b ld	r9,reg9 */
0x0000f21c, 0x07a0f4a7, /* 07a0f4a7 //C 0f21c ld	r10,reg10 */
0x0000f21d, 0x07b0f4a8, /* 07b0f4a8 //C 0f21d ld	r11,reg11 */
0x0000f21e, 0x07c0f4a9, /* 07c0f4a9 //C 0f21e ld	r12,reg12 */
0x0000f21f, 0x07d0f4aa, /* 07d0f4aa //C 0f21f ld	r13,reg13 */
0x0000f220, 0x07e0f4ab, /* 07e0f4ab //C 0f220 ld	r14,reg14 */
0x0000f221, 0x07f0f4ac, /* 07f0f4ac //C 0f221 ld	r15,reg15 */
0x0000f222, 0x0700f49b, /* 0700f49b //C 0f222 ld	r0,called */
0x0000f223, 0x020b0000, /* 020b0000 //C 0f223 sz	r0 */
0x0000f224, 0x11f2f227, /* 11f2f227 //C 0f224 jz	g_err */
0x0000f225, 0x07b0f4ac, /* 07b0f4ac //C 0f225 ld	r11,reg15 */
0x0000f226, 0x01f2f202, /* 01f2f202 //C 0f226 jmp	g_go11 */
0x0000f227, 0x0102f22b, /* 0102f22b //C 0f227 mvzl	r0,g_err_addr */
0x0000f228, 0x0400f400, /* 0400f400 //C 0f228 call	printsnl */
0x0000f229, 0x0fed0000, /* 0fed0000 //C 0f229 pop	lr */
0x0000f22a, 0x00f00e00, /* 00f00e00 //C 0f22a ret */
0x0000f22b, 0x0000004e, /* 0000004e //C 0f22b db	78 */
0x0000f22c, 0x0000006f, /* 0000006f //C 0f22c db	111 */
0x0000f22d, 0x00000020, /* 00000020 //C 0f22d db	32 */
0x0000f22e, 0x00000061, /* 00000061 //C 0f22e db	97 */
0x0000f22f, 0x00000064, /* 00000064 //C 0f22f db	100 */
0x0000f230, 0x00000064, /* 00000064 //C 0f230 db	100 */
0x0000f231, 0x00000072, /* 00000072 //C 0f231 db	114 */
0x0000f232, 0x00000065, /* 00000065 //C 0f232 db	101 */
0x0000f233, 0x00000073, /* 00000073 //C 0f233 db	115 */
0x0000f234, 0x00000073, /* 00000073 //C 0f234 db	115 */
0x0000f235, 0x00000000, /* 00000000 //C 0f235 db */
0x0000f236, 0x00000052, /* 00000052 //C 0f236 db	82 */
0x0000f237, 0x00000075, /* 00000075 //C 0f237 db	117 */
0x0000f238, 0x0000006e, /* 0000006e //C 0f238 db	110 */
0x0000f239, 0x00000020, /* 00000020 //C 0f239 db	32 */
0x0000f23a, 0x00000000, /* 00000000 //C 0f23a db */
0x0000f23b, 0x0ded0000, /* 0ded0000 //C 0f23b push	lr */
0x0000f23c, 0x0122f52b, /* 0122f52b //C 0f23c mvzl	r2,helps */
0x0000f23d, 0x01320000, /* 01320000 //C 0f23d mvzl	r3,0 */
0x0000f23e, 0x0b038200, /* 0b038200 //C 0f23e ld	r0,r3+,r2	; pick a char */
0x0000f23f, 0x020b0000, /* 020b0000 //C 0f23f sz	r0		; is it eos? */
0x0000f240, 0x21f2f244, /* 21f2f244 //C 0f240 jnz	h_print */
0x0000f241, 0x0b038200, /* 0b038200 //C 0f241 ld	r0,r3+,r2	; get first char of next string */
0x0000f242, 0x020b0000, /* 020b0000 //C 0f242 sz	r0 */
0x0000f243, 0x11f2f246, /* 11f2f246 //C 0f243 jz	h_eof */
0x0000f244, 0x0400f3e0, /* 0400f3e0 //C 0f244 call	putchar */
0x0000f245, 0x01f2f23e, /* 01f2f23e //C 0f245 jmp	h_cyc */
0x0000f246, 0x0fed0000, /* 0fed0000 //C 0f246 pop	lr */
0x0000f247, 0x00f00e00, /* 00f00e00 //C 0f247 ret */
0x0000f248, 0x0ded0000, /* 0ded0000 //C 0f248 push	lr */
0x0000f249, 0x0d1d0000, /* 0d1d0000 //C 0f249 push	r1 */
0x0000f24a, 0x00100000, /* 00100000 //C 0f24a mov	r1,r0 */
0x0000f24b, 0x01180010, /* 01180010 //C 0f24b cmp	r1,16		; go out if nr>16 */
0x0000f24c, 0x91f2f280, /* 91f2f280 //C 0f24c HI jmp	prn_ret */
0x0000f24d, 0x0118000f, /* 0118000f //C 0f24d cmp	r1,15		; nr=Flag? */
0x0000f24e, 0xa1f2f255, /* a1f2f255 //C 0f24e LS jmp	prn_015 */
0x0000f24f, 0x01020046, /* 01020046 //C 0f24f mvzl	r0,'F' */
0x0000f250, 0x0400f3e0, /* 0400f3e0 //C 0f250 call	putchar */
0x0000f251, 0x01020020, /* 01020020 //C 0f251 mvzl	r0,32 */
0x0000f252, 0x0400f3e0, /* 0400f3e0 //C 0f252 call	putchar */
0x0000f253, 0x0400f3e0, /* 0400f3e0 //C 0f253 call	putchar */
0x0000f254, 0x01f2f280, /* 01f2f280 //C 0f254 jmp	prn_ret */
0x0000f255, 0x0118000f, /* 0118000f //C 0f255 cmp	r1,15 */
0x0000f256, 0x21f2f25e, /* 21f2f25e //C 0f256 jnz	prn_no15 */
0x0000f257, 0x0102f25a, /* 0102f25a //C 0f257 mvzl	r0,prn_PC */
0x0000f258, 0x0400f3ec, /* 0400f3ec //C 0f258 call	prints */
0x0000f259, 0x01f2f280, /* 01f2f280 //C 0f259 jmp	prn_ret */
0x0000f25a, 0x00000050, /* 00000050 //C 0f25a db	80 */
0x0000f25b, 0x00000043, /* 00000043 //C 0f25b db	67 */
0x0000f25c, 0x00000020, /* 00000020 //C 0f25c db	32 */
0x0000f25d, 0x00000000, /* 00000000 //C 0f25d db */
0x0000f25e, 0x0118000e, /* 0118000e //C 0f25e cmp	r1,14 */
0x0000f25f, 0x21f2f267, /* 21f2f267 //C 0f25f jnz	prn_no14 */
0x0000f260, 0x0102f263, /* 0102f263 //C 0f260 mvzl	r0,prn_LR */
0x0000f261, 0x0400f3ec, /* 0400f3ec //C 0f261 call	prints */
0x0000f262, 0x01f2f280, /* 01f2f280 //C 0f262 jmp	prn_ret */
0x0000f263, 0x0000004c, /* 0000004c //C 0f263 db	76 */
0x0000f264, 0x00000052, /* 00000052 //C 0f264 db	82 */
0x0000f265, 0x00000020, /* 00000020 //C 0f265 db	32 */
0x0000f266, 0x00000000, /* 00000000 //C 0f266 db */
0x0000f267, 0x0118000d, /* 0118000d //C 0f267 cmp	r1,13 */
0x0000f268, 0x21f2f270, /* 21f2f270 //C 0f268 jnz	prn_no13 */
0x0000f269, 0x0102f26c, /* 0102f26c //C 0f269 mvzl	r0,prn_SP */
0x0000f26a, 0x0400f3ec, /* 0400f3ec //C 0f26a call	prints */
0x0000f26b, 0x01f2f280, /* 01f2f280 //C 0f26b jmp	prn_ret */
0x0000f26c, 0x00000053, /* 00000053 //C 0f26c db	83 */
0x0000f26d, 0x00000050, /* 00000050 //C 0f26d db	80 */
0x0000f26e, 0x00000020, /* 00000020 //C 0f26e db	32 */
0x0000f26f, 0x00000000, /* 00000000 //C 0f26f db */
0x0000f270, 0x01020052, /* 01020052 //C 0f270 mvzl	r0,'R' */
0x0000f271, 0x0400f3e0, /* 0400f3e0 //C 0f271 call	putchar */
0x0000f272, 0x01180009, /* 01180009 //C 0f272 cmp	r1,9 */
0x0000f273, 0x91f2f27a, /* 91f2f27a //C 0f273 HI jmp	prn_1015 */
0x0000f274, 0x00000100, /* 00000100 //C 0f274 mov	r0,r1 */
0x0000f275, 0x01040030, /* 01040030 //C 0f275 add	r0,'0' */
0x0000f276, 0x0400f3e0, /* 0400f3e0 //C 0f276 call	putchar */
0x0000f277, 0x01020020, /* 01020020 //C 0f277 mvzl	r0,32 */
0x0000f278, 0x0400f3e0, /* 0400f3e0 //C 0f278 call	putchar */
0x0000f279, 0x01f2f280, /* 01f2f280 //C 0f279 jmp	prn_ret */
0x0000f27a, 0x01020031, /* 01020031 //C 0f27a mvzl	r0,'1' */
0x0000f27b, 0x0400f3e0, /* 0400f3e0 //C 0f27b call	putchar */
0x0000f27c, 0x00000100, /* 00000100 //C 0f27c mov	r0,r1 */
0x0000f27d, 0x0106000a, /* 0106000a //C 0f27d sub	r0,10 */
0x0000f27e, 0x01040030, /* 01040030 //C 0f27e add	r0,'0' */
0x0000f27f, 0x0400f3e0, /* 0400f3e0 //C 0f27f call	putchar */
0x0000f280, 0x0f1d0000, /* 0f1d0000 //C 0f280 pop	r1 */
0x0000f281, 0x0fed0000, /* 0fed0000 //C 0f281 pop	lr */
0x0000f282, 0x00f00e00, /* 00f00e00 //C 0f282 ret */
0x0000f283, 0x0ded0000, /* 0ded0000 //C 0f283 push	lr */
0x0000f284, 0x0d1d0000, /* 0d1d0000 //C 0f284 push	r1 */
0x0000f285, 0x01080010, /* 01080010 //C 0f285 cmp	r0,16 */
0x0000f286, 0x91f2f28b, /* 91f2f28b //C 0f286 HI jmp	prv_ret */
0x0000f287, 0x0112f49d, /* 0112f49d //C 0f287 mvzl	r1,reg0 */
0x0000f288, 0x0a010000, /* 0a010000 //C 0f288 ld	r0,r1,r0 */
0x0000f289, 0x01120004, /* 01120004 //C 0f289 mvzl	r1,4 */
0x0000f28a, 0x0400f408, /* 0400f408 //C 0f28a call	print_vhex */
0x0000f28b, 0x0f1d0000, /* 0f1d0000 //C 0f28b pop	r1 */
0x0000f28c, 0x0fed0000, /* 0fed0000 //C 0f28c pop	lr */
0x0000f28d, 0x00f00e00, /* 00f00e00 //C 0f28d ret */
0x0000f28e, 0x0ded0000, /* 0ded0000 //C 0f28e push	lr */
0x0000f28f, 0x0dad0000, /* 0dad0000 //C 0f28f push	r10 */
0x0000f290, 0x0d0d0000, /* 0d0d0000 //C 0f290 push	r0 */
0x0000f291, 0x00000a00, /* 00000a00 //C 0f291 mov	r0,r10 */
0x0000f292, 0x0400f248, /* 0400f248 //C 0f292 call	print_reg_name */
0x0000f293, 0x01020020, /* 01020020 //C 0f293 mvzl	r0,32 */
0x0000f294, 0x0400f3e0, /* 0400f3e0 //C 0f294 call	putchar */
0x0000f295, 0x00000a00, /* 00000a00 //C 0f295 mov	r0,r10 */
0x0000f296, 0x0400f283, /* 0400f283 //C 0f296 call	print_reg_value */
0x0000f297, 0x0102000a, /* 0102000a //C 0f297 mvzl	r0,LF */
0x0000f298, 0x0400f3e0, /* 0400f3e0 //C 0f298 call	putchar */
0x0000f299, 0x0f0d0000, /* 0f0d0000 //C 0f299 pop	r0 */
0x0000f29a, 0x0fad0000, /* 0fad0000 //C 0f29a pop	r10 */
0x0000f29b, 0x0fed0000, /* 0fed0000 //C 0f29b pop	lr */
0x0000f29c, 0x00f00e00, /* 00f00e00 //C 0f29c ret */
0x0000f29d, 0x0ded0000, /* 0ded0000 //C 0f29d push	lr */
0x0000f29e, 0x0400f3e0, /* 0400f3e0 //C 0f29e call	putchar */
0x0000f29f, 0x001c0200, /* 001c0200 //C 0f29f test	r1,r2 */
0x0000f2a0, 0x21020031, /* 21020031 //C 0f2a0 NZ mvzl r0,'1' */
0x0000f2a1, 0x11020030, /* 11020030 //C 0f2a1 Z  mvzl r0,'0' */
0x0000f2a2, 0x0400f3e0, /* 0400f3e0 //C 0f2a2 call	putchar */
0x0000f2a3, 0x00000300, /* 00000300 //C 0f2a3 mov	r0,r3 */
0x0000f2a4, 0x0400f3e0, /* 0400f3e0 //C 0f2a4 call	putchar */
0x0000f2a5, 0x0fed0000, /* 0fed0000 //C 0f2a5 pop	lr */
0x0000f2a6, 0x00f00e00, /* 00f00e00 //C 0f2a6 ret */
0x0000f2a7, 0x0ded0000, /* 0ded0000 //C 0f2a7 push	lr */
0x0000f2a8, 0x01a20000, /* 01a20000 //C 0f2a8 mvzl	r10,0 */
0x0000f2a9, 0x0400f28e, /* 0400f28e //C 0f2a9 call	print_reg_name_value */
0x0000f2aa, 0x01a40001, /* 01a40001 //C 0f2aa add	r10,1 */
0x0000f2ab, 0x01a80011, /* 01a80011 //C 0f2ab cmp	r10,17 */
0x0000f2ac, 0x21f2f2a9, /* 21f2f2a9 //C 0f2ac jnz	r_cyc */
0x0000f2ad, 0x0710f4ad, /* 0710f4ad //C 0f2ad ld	r1,regf */
0x0000f2ae, 0x01320020, /* 01320020 //C 0f2ae mvzl	r3,32 */
0x0000f2af, 0x01020055, /* 01020055 //C 0f2af mvzl	r0,'U' */
0x0000f2b0, 0x01220020, /* 01220020 //C 0f2b0 mvzl	r2,0x20 */
0x0000f2b1, 0x0400f29d, /* 0400f29d //C 0f2b1 call	print_flag */
0x0000f2b2, 0x01020050, /* 01020050 //C 0f2b2 mvzl	r0,'P' */
0x0000f2b3, 0x01220010, /* 01220010 //C 0f2b3 mvzl	r2,0x10 */
0x0000f2b4, 0x0400f29d, /* 0400f29d //C 0f2b4 call	print_flag */
0x0000f2b5, 0x0102004f, /* 0102004f //C 0f2b5 mvzl	r0,'O' */
0x0000f2b6, 0x01220008, /* 01220008 //C 0f2b6 mvzl	r2,8 */
0x0000f2b7, 0x0400f29d, /* 0400f29d //C 0f2b7 call	print_flag */
0x0000f2b8, 0x0102005a, /* 0102005a //C 0f2b8 mvzl	r0,'Z' */
0x0000f2b9, 0x01220004, /* 01220004 //C 0f2b9 mvzl	r2,4 */
0x0000f2ba, 0x0400f29d, /* 0400f29d //C 0f2ba call	print_flag */
0x0000f2bb, 0x01020043, /* 01020043 //C 0f2bb mvzl	r0,'C' */
0x0000f2bc, 0x01220002, /* 01220002 //C 0f2bc mvzl	r2,2 */
0x0000f2bd, 0x0400f29d, /* 0400f29d //C 0f2bd call	print_flag */
0x0000f2be, 0x01020053, /* 01020053 //C 0f2be mvzl	r0,'S' */
0x0000f2bf, 0x01220001, /* 01220001 //C 0f2bf mvzl	r2,1 */
0x0000f2c0, 0x0132000a, /* 0132000a //C 0f2c0 mvzl	r3,LF */
0x0000f2c1, 0x0400f29d, /* 0400f29d //C 0f2c1 call	print_flag */
0x0000f2c2, 0x0fed0000, /* 0fed0000 //C 0f2c2 pop	lr */
0x0000f2c3, 0x00f00e00, /* 00f00e00 //C 0f2c3 ret */
0x0000f2c4, 0x0ded0000, /* 0ded0000 //C 0f2c4 push	lr */
0x0000f2c5, 0x07a0f49c, /* 07a0f49c //C 0f2c5 ld	r10,nuof_reg	; Reg num is in R10 */
0x0000f2c6, 0x01a80010, /* 01a80010 //C 0f2c6 cmp	r10,16 */
0x0000f2c7, 0xa1f2f2dc, /* a1f2f2dc //C 0f2c7 LS jmp	rx_nr_ok */
0x0000f2c8, 0x0102f2cb, /* 0102f2cb //C 0f2c8 mvzl	r0,rx_err_nr */
0x0000f2c9, 0x0400f400, /* 0400f400 //C 0f2c9 call	printsnl */
0x0000f2ca, 0x01f2f2f8, /* 01f2f2f8 //C 0f2ca jmp	rx_ret */
0x0000f2cb, 0x0000004e, /* 0000004e //C 0f2cb db	78 */
0x0000f2cc, 0x0000006f, /* 0000006f //C 0f2cc db	111 */
0x0000f2cd, 0x00000020, /* 00000020 //C 0f2cd db	32 */
0x0000f2ce, 0x00000073, /* 00000073 //C 0f2ce db	115 */
0x0000f2cf, 0x00000075, /* 00000075 //C 0f2cf db	117 */
0x0000f2d0, 0x00000063, /* 00000063 //C 0f2d0 db	99 */
0x0000f2d1, 0x00000068, /* 00000068 //C 0f2d1 db	104 */
0x0000f2d2, 0x00000020, /* 00000020 //C 0f2d2 db	32 */
0x0000f2d3, 0x00000072, /* 00000072 //C 0f2d3 db	114 */
0x0000f2d4, 0x00000065, /* 00000065 //C 0f2d4 db	101 */
0x0000f2d5, 0x00000067, /* 00000067 //C 0f2d5 db	103 */
0x0000f2d6, 0x00000069, /* 00000069 //C 0f2d6 db	105 */
0x0000f2d7, 0x00000073, /* 00000073 //C 0f2d7 db	115 */
0x0000f2d8, 0x00000074, /* 00000074 //C 0f2d8 db	116 */
0x0000f2d9, 0x00000065, /* 00000065 //C 0f2d9 db	101 */
0x0000f2da, 0x00000072, /* 00000072 //C 0f2da db	114 */
0x0000f2db, 0x00000000, /* 00000000 //C 0f2db db */
0x0000f2dc, 0x0122f495, /* 0122f495 //C 0f2dc mvzl	r2,words */
0x0000f2dd, 0x0e420001, /* 0e420001 //C 0f2dd ld	r4,r2,1		; get aof first parameter */
0x0000f2de, 0x024b0000, /* 024b0000 //C 0f2de sz	r4		; is it NULL? */
0x0000f2df, 0x11f2f2f7, /* 11f2f2f7 //C 0f2df jz	rx_print */
0x0000f2e0, 0x00000400, /* 00000400 //C 0f2e0 mov	r0,r4 */
0x0000f2e1, 0x0400f383, /* 0400f383 //C 0f2e1 call	htoi */
0x0000f2e2, 0x00500100, /* 00500100 //C 0f2e2 mov	r5,r1		; Value is in R5 */
0x0000f2e3, 0x31f2f2f3, /* 31f2f2f3 //C 0f2e3 C1 jmp	rx_val_ok */
0x0000f2e4, 0x0102f2e7, /* 0102f2e7 //C 0f2e4 mvzl	r0,rx_err_val */
0x0000f2e5, 0x0400f400, /* 0400f400 //C 0f2e5 call	printsnl */
0x0000f2e6, 0x01f2f2f8, /* 01f2f2f8 //C 0f2e6 jmp	rx_ret */
0x0000f2e7, 0x00000056, /* 00000056 //C 0f2e7 db	86 */
0x0000f2e8, 0x00000061, /* 00000061 //C 0f2e8 db	97 */
0x0000f2e9, 0x0000006c, /* 0000006c //C 0f2e9 db	108 */
0x0000f2ea, 0x00000075, /* 00000075 //C 0f2ea db	117 */
0x0000f2eb, 0x00000065, /* 00000065 //C 0f2eb db	101 */
0x0000f2ec, 0x00000020, /* 00000020 //C 0f2ec db	32 */
0x0000f2ed, 0x00000065, /* 00000065 //C 0f2ed db	101 */
0x0000f2ee, 0x00000072, /* 00000072 //C 0f2ee db	114 */
0x0000f2ef, 0x00000072, /* 00000072 //C 0f2ef db	114 */
0x0000f2f0, 0x0000006f, /* 0000006f //C 0f2f0 db	111 */
0x0000f2f1, 0x00000072, /* 00000072 //C 0f2f1 db	114 */
0x0000f2f2, 0x00000000, /* 00000000 //C 0f2f2 db */
0x0000f2f3, 0x01a80010, /* 01a80010 //C 0f2f3 cmp	r10,16		; Flag reg? */
0x0000f2f4, 0x115f003f, /* 115f003f //C 0f2f4 EQ and	r5,0x3f */
0x0000f2f5, 0x0102f49d, /* 0102f49d //C 0f2f5 mvzl	r0,reg0 */
0x0000f2f6, 0x08500a00, /* 08500a00 //C 0f2f6 st	r5,r0,r10 */
0x0000f2f7, 0x0400f28e, /* 0400f28e //C 0f2f7 call	print_reg_name_value */
0x0000f2f8, 0x0fed0000, /* 0fed0000 //C 0f2f8 pop	lr */
0x0000f2f9, 0x00f00e00, /* 00f00e00 //C 0f2f9 ret */
0x0000f2fa, 0x0102000d, /* 0102000d //C 0f2fa mvzl	r0,13 */
0x0000f2fb, 0x0600f49c, /* 0600f49c //C 0f2fb st	r0,nuof_reg */
0x0000f2fc, 0x01f2f2c4, /* 01f2f2c4 //C 0f2fc jmp	cmd_rx */
0x0000f2fd, 0x0102000e, /* 0102000e //C 0f2fd mvzl	r0,14 */
0x0000f2fe, 0x0600f49c, /* 0600f49c //C 0f2fe st	r0,nuof_reg */
0x0000f2ff, 0x01f2f2c4, /* 01f2f2c4 //C 0f2ff jmp	cmd_rx */
0x0000f300, 0x0102000f, /* 0102000f //C 0f300 mvzl	r0,15 */
0x0000f301, 0x0600f49c, /* 0600f49c //C 0f301 st	r0,nuof_reg */
0x0000f302, 0x01f2f2c4, /* 01f2f2c4 //C 0f302 jmp	cmd_rx */
0x0000f303, 0x01020010, /* 01020010 //C 0f303 mvzl	r0,16 */
0x0000f304, 0x0600f49c, /* 0600f49c //C 0f304 st	r0,nuof_reg */
0x0000f305, 0x01f2f2c4, /* 01f2f2c4 //C 0f305 jmp	cmd_rx */
0x0000f306, 0x0d1d0000, /* 0d1d0000 //C 0f306 push	r1 */
0x0000f307, 0x0d2d0000, /* 0d2d0000 //C 0f307 push	r2 */
0x0000f308, 0x0e210000, /* 0e210000 //C 0f308 ld	r2,r1 */
0x0000f309, 0x022b0000, /* 022b0000 //C 0f309 sz	r2 */
0x0000f30a, 0x11f2f311, /* 11f2f311 //C 0f30a jz	strchr_no	; eof string found */
0x0000f30b, 0x00280000, /* 00280000 //C 0f30b cmp	r2,r0		; compare */
0x0000f30c, 0x11f2f30f, /* 11f2f30f //C 0f30c jz	strchr_yes */
0x0000f30d, 0x011a0001, /* 011a0001 //C 0f30d plus	r1,1		; go to next char */
0x0000f30e, 0x01f2f308, /* 01f2f308 //C 0f30e jmp	strchr_cyc */
0x0000f30f, 0x020c0000, /* 020c0000 //C 0f30f sec */
0x0000f310, 0x01f2f313, /* 01f2f313 //C 0f310 jmp	strchr_ret */
0x0000f311, 0x01120000, /* 01120000 //C 0f311 mvzl	r1,0 */
0x0000f312, 0x020d0000, /* 020d0000 //C 0f312 clc */
0x0000f313, 0x0f2d0000, /* 0f2d0000 //C 0f313 pop	r2 */
0x0000f314, 0x0f1d0000, /* 0f1d0000 //C 0f314 pop	r1 */
0x0000f315, 0x00f00e00, /* 00f00e00 //C 0f315 ret */
0x0000f316, 0x0ded0000, /* 0ded0000 //C 0f316 push	lr		; Save used registers */
0x0000f317, 0x0d0d0000, /* 0d0d0000 //C 0f317 push	r0		; and input parameters */
0x0000f318, 0x0d1d0000, /* 0d1d0000 //C 0f318 push	r1 */
0x0000f319, 0x0d2d0000, /* 0d2d0000 //C 0f319 push	r2 */
0x0000f31a, 0x0d4d0000, /* 0d4d0000 //C 0f31a push	r4 */
0x0000f31b, 0x0d5d0000, /* 0d5d0000 //C 0f31b push	r5 */
0x0000f31c, 0x0d6d0000, /* 0d6d0000 //C 0f31c push	r6 */
0x0000f31d, 0x0e200000, /* 0e200000 //C 0f31d ld	r2,r0		; Got one-one char */
0x0000f31e, 0x0e610000, /* 0e610000 //C 0f31e ld	r6,r1		; from two strings */
0x0000f31f, 0x023b0000, /* 023b0000 //C 0f31f sz	r3		; Prepare for comparing */
0x0000f320, 0x112d0020, /* 112d0020 //C 0f320 Z1 or	r2,0x20		; if insensitive case */
0x0000f321, 0x023b0000, /* 023b0000 //C 0f321 sz	r3 */
0x0000f322, 0x116d0020, /* 116d0020 //C 0f322 Z1 or	r6,0x20 */
0x0000f323, 0x00280600, /* 00280600 //C 0f323 cmp	r2,r6		; compare them */
0x0000f324, 0x21f2f336, /* 21f2f336 //C 0f324 jnz	streq_no	; if differs: strings are not equal */
0x0000f325, 0x0e200000, /* 0e200000 //C 0f325 ld	r2,r0		; Pick original (non-prepared) */
0x0000f326, 0x0e610000, /* 0e610000 //C 0f326 ld	r6,r1		; chars to check EOS */
0x0000f327, 0x022b0000, /* 022b0000 //C 0f327 sz	r2		; convert them to boolean */
0x0000f328, 0x21220001, /* 21220001 //C 0f328 Z0 mvzl	r2,1		; values in R2,R6 */
0x0000f329, 0x11220000, /* 11220000 //C 0f329 Z1 mvzl	r2,0		; and copy in R4,R5 */
0x0000f32a, 0x00400200, /* 00400200 //C 0f32a mov	r4,r2 */
0x0000f32b, 0x026b0000, /* 026b0000 //C 0f32b sz	r6 */
0x0000f32c, 0x21620001, /* 21620001 //C 0f32c Z0 mvzl	r6,1 */
0x0000f32d, 0x11620000, /* 11620000 //C 0f32d Z1 mvzl r6,0 */
0x0000f32e, 0x00500600, /* 00500600 //C 0f32e mov	r5,r6 */
0x0000f32f, 0x004d0500, /* 004d0500 //C 0f32f or	r4,r5		; if both are EOS: equal */
0x0000f330, 0x11f2f338, /* 11f2f338 //C 0f330 jz	streq_yes */
0x0000f331, 0x002f0600, /* 002f0600 //C 0f331 and 	r2,r6		; just one is EOS: not equal */
0x0000f332, 0x11f2f336, /* 11f2f336 //C 0f332 jz	streq_no */
0x0000f333, 0x010a0001, /* 010a0001 //C 0f333 plus	r0,1		; non are EOS: go to check next char */
0x0000f334, 0x011a0001, /* 011a0001 //C 0f334 plus	r1,1 */
0x0000f335, 0x01f2f31d, /* 01f2f31d //C 0f335 jmp	streq_cyc */
0x0000f336, 0x020d0000, /* 020d0000 //C 0f336 clc			; False result */
0x0000f337, 0x01f2f339, /* 01f2f339 //C 0f337 jmp	streq_ret */
0x0000f338, 0x020c0000, /* 020c0000 //C 0f338 sec			; True result */
0x0000f339, 0x0f6d0000, /* 0f6d0000 //C 0f339 pop	r6 */
0x0000f33a, 0x0f5d0000, /* 0f5d0000 //C 0f33a pop	r5 */
0x0000f33b, 0x0f4d0000, /* 0f4d0000 //C 0f33b pop	r4 */
0x0000f33c, 0x0f2d0000, /* 0f2d0000 //C 0f33c pop	r2 */
0x0000f33d, 0x0f1d0000, /* 0f1d0000 //C 0f33d pop	r1 */
0x0000f33e, 0x0f0d0000, /* 0f0d0000 //C 0f33e pop	r0 */
0x0000f33f, 0x0fed0000, /* 0fed0000 //C 0f33f pop	lr */
0x0000f340, 0x00f00e00, /* 00f00e00 //C 0f340 ret */
0x0000f341, 0x0ded0000, /* 0ded0000 //C 0f341 push	lr */
0x0000f342, 0x0d3d0000, /* 0d3d0000 //C 0f342 push	r3 */
0x0000f343, 0x01320001, /* 01320001 //C 0f343 mvzl	r3,1 */
0x0000f344, 0x0400f316, /* 0400f316 //C 0f344 call	str_cmp_eq */
0x0000f345, 0x0f3d0000, /* 0f3d0000 //C 0f345 pop	r3 */
0x0000f346, 0x0fed0000, /* 0fed0000 //C 0f346 pop	lr */
0x0000f347, 0x00f00e00, /* 00f00e00 //C 0f347 ret */
0x0000f348, 0x0ded0000, /* 0ded0000 //C 0f348 push	lr */
0x0000f349, 0x0d3d0000, /* 0d3d0000 //C 0f349 push	r3 */
0x0000f34a, 0x01320000, /* 01320000 //C 0f34a mvzl	r3,0 */
0x0000f34b, 0x0400f316, /* 0400f316 //C 0f34b call	str_cmp_eq */
0x0000f34c, 0x0f3d0000, /* 0f3d0000 //C 0f34c pop	r3 */
0x0000f34d, 0x0fed0000, /* 0fed0000 //C 0f34d pop	lr */
0x0000f34e, 0x00f00e00, /* 00f00e00 //C 0f34e ret */
0x0000f34f, 0x0108002f, /* 0108002f //C 0f34f cmp	r0,'/' */
0x0000f350, 0xa1f2f365, /* a1f2f365 //C 0f350 LS jmp	hc2v_nok */
0x0000f351, 0x01080039, /* 01080039 //C 0f351 cmp	r0,'9' */
0x0000f352, 0xa1f2f362, /* a1f2f362 //C 0f352 LS jmp	hc2v_0_9 */
0x0000f353, 0x01080040, /* 01080040 //C 0f353 cmp	r0,'@' */
0x0000f354, 0xa1f2f365, /* a1f2f365 //C 0f354 LS jmp	hc2v_nok */
0x0000f355, 0x01080046, /* 01080046 //C 0f355 cmp	r0,'F' */
0x0000f356, 0xa1f2f35f, /* a1f2f35f //C 0f356 LS jmp	hc2v_A_F */
0x0000f357, 0x01080060, /* 01080060 //C 0f357 cmp	r0,'`' */
0x0000f358, 0xa1f2f365, /* a1f2f365 //C 0f358 LS jmp	hc2v_nok */
0x0000f359, 0x01080066, /* 01080066 //C 0f359 cmp	r0,'f' */
0x0000f35a, 0xa1f2f35c, /* a1f2f35c //C 0f35a LS jmp	hc2v_a_f */
0x0000f35b, 0x01f2f365, /* 01f2f365 //C 0f35b jmp	hc2v_nok */
0x0000f35c, 0x0104000a, /* 0104000a //C 0f35c add	r0,10 */
0x0000f35d, 0x01060061, /* 01060061 //C 0f35d sub	r0,'a' */
0x0000f35e, 0x01f2f363, /* 01f2f363 //C 0f35e jmp	hc2v_ok */
0x0000f35f, 0x0104000a, /* 0104000a //C 0f35f add	r0,10 */
0x0000f360, 0x01060041, /* 01060041 //C 0f360 sub	r0,'A' */
0x0000f361, 0x01f2f363, /* 01f2f363 //C 0f361 jmp	hc2v_ok */
0x0000f362, 0x01060030, /* 01060030 //C 0f362 sub	r0,'0' */
0x0000f363, 0x020c0000, /* 020c0000 //C 0f363 sec */
0x0000f364, 0x00f00e00, /* 00f00e00 //C 0f364 ret */
0x0000f365, 0x020d0000, /* 020d0000 //C 0f365 clc */
0x0000f366, 0x00f00e00, /* 00f00e00 //C 0f366 ret */
0x0000f367, 0x0d1d0000, /* 0d1d0000 //C 0f367 push	r1 */
0x0000f368, 0x010f000f, /* 010f000f //C 0f368 and	r0,0xf */
0x0000f369, 0x0112f36d, /* 0112f36d //C 0f369 mvzl	r1,v2hc_table */
0x0000f36a, 0x0a010000, /* 0a010000 //C 0f36a ld	r0,r1,r0 */
0x0000f36b, 0x0f1d0000, /* 0f1d0000 //C 0f36b pop	r1 */
0x0000f36c, 0x00f00e00, /* 00f00e00 //C 0f36c ret */
0x0000f36d, 0x00000030, /* 00000030 //C 0f36d db	48 */
0x0000f36e, 0x00000031, /* 00000031 //C 0f36e db	49 */
0x0000f36f, 0x00000032, /* 00000032 //C 0f36f db	50 */
0x0000f370, 0x00000033, /* 00000033 //C 0f370 db	51 */
0x0000f371, 0x00000034, /* 00000034 //C 0f371 db	52 */
0x0000f372, 0x00000035, /* 00000035 //C 0f372 db	53 */
0x0000f373, 0x00000036, /* 00000036 //C 0f373 db	54 */
0x0000f374, 0x00000037, /* 00000037 //C 0f374 db	55 */
0x0000f375, 0x00000038, /* 00000038 //C 0f375 db	56 */
0x0000f376, 0x00000039, /* 00000039 //C 0f376 db	57 */
0x0000f377, 0x00000041, /* 00000041 //C 0f377 db	65 */
0x0000f378, 0x00000042, /* 00000042 //C 0f378 db	66 */
0x0000f379, 0x00000043, /* 00000043 //C 0f379 db	67 */
0x0000f37a, 0x00000044, /* 00000044 //C 0f37a db	68 */
0x0000f37b, 0x00000045, /* 00000045 //C 0f37b db	69 */
0x0000f37c, 0x00000046, /* 00000046 //C 0f37c db	70 */
0x0000f37d, 0x00000000, /* 00000000 //C 0f37d db */
0x0000f37e, 0x0ded0000, /* 0ded0000 //C 0f37e push	lr */
0x0000f37f, 0x0400f367, /* 0400f367 //C 0f37f call	value2Hexchar */
0x0000f380, 0x010d0020, /* 010d0020 //C 0f380 or	r0,0x20 */
0x0000f381, 0x0fed0000, /* 0fed0000 //C 0f381 pop	lr */
0x0000f382, 0x00f00e00, /* 00f00e00 //C 0f382 ret */
0x0000f383, 0x0ded0000, /* 0ded0000 //C 0f383 push	lr */
0x0000f384, 0x0d2d0000, /* 0d2d0000 //C 0f384 push	r2 */
0x0000f385, 0x0d3d0000, /* 0d3d0000 //C 0f385 push	r3 */
0x0000f386, 0x01120000, /* 01120000 //C 0f386 mvzl	r1,0		; return value */
0x0000f387, 0x01320000, /* 01320000 //C 0f387 mvzl	r3,0		; index */
0x0000f388, 0x0b238000, /* 0b238000 //C 0f388 ld	r2,r3+,r0	; pick a char */
0x0000f389, 0x022b0000, /* 022b0000 //C 0f389 sz	r2		; check eof string */
0x0000f38a, 0x11f2f39e, /* 11f2f39e //C 0f38a jz	htoi_eos */
0x0000f38b, 0x0128002e, /* 0128002e //C 0f38b cmp	r2,'.'		; skip separators */
0x0000f38c, 0x11f2f388, /* 11f2f388 //C 0f38c jz	htoi_cyc */
0x0000f38d, 0x0128005f, /* 0128005f //C 0f38d cmp	r2,'_' */
0x0000f38e, 0x11f2f388, /* 11f2f388 //C 0f38e jz	htoi_cyc */
0x0000f38f, 0x0d0d0000, /* 0d0d0000 //C 0f38f push	r0 */
0x0000f390, 0x00000200, /* 00000200 //C 0f390 mov	r0,r2 */
0x0000f391, 0x0400f34f, /* 0400f34f //C 0f391 call	hexchar2value */
0x0000f392, 0x00200000, /* 00200000 //C 0f392 mov	r2,r0 */
0x0000f393, 0x0f0d0000, /* 0f0d0000 //C 0f393 pop	r0 */
0x0000f394, 0x41f2f39c, /* 41f2f39c //C 0f394 C0 jmp	htoi_nok */
0x0000f395, 0x02180000, /* 02180000 //C 0f395 shl	r1 */
0x0000f396, 0x02180000, /* 02180000 //C 0f396 shl	r1 */
0x0000f397, 0x02180000, /* 02180000 //C 0f397 shl	r1 */
0x0000f398, 0x02180000, /* 02180000 //C 0f398 shl	r1 */
0x0000f399, 0x012f000f, /* 012f000f //C 0f399 and	r2,0xf */
0x0000f39a, 0x001d0200, /* 001d0200 //C 0f39a or	r1,r2 */
0x0000f39b, 0x01f2f388, /* 01f2f388 //C 0f39b jmp	htoi_cyc */
0x0000f39c, 0x020d0000, /* 020d0000 //C 0f39c clc */
0x0000f39d, 0x01f2f3a1, /* 01f2f3a1 //C 0f39d jmp	htoi_ret */
0x0000f39e, 0x01380001, /* 01380001 //C 0f39e cmp	r3,1 */
0x0000f39f, 0x920d0000, /* 920d0000 //C 0f39f HI clc */
0x0000f3a0, 0xa20c0000, /* a20c0000 //C 0f3a0 LS sec */
0x0000f3a1, 0x0f3d0000, /* 0f3d0000 //C 0f3a1 pop	r3 */
0x0000f3a2, 0x0f2d0000, /* 0f2d0000 //C 0f3a2 pop	r2 */
0x0000f3a3, 0x0fed0000, /* 0fed0000 //C 0f3a3 pop	lr */
0x0000f3a4, 0x00f00e00, /* 00f00e00 //C 0f3a4 ret */
0x0000f3a5, 0x0d0d0000, /* 0d0d0000 //C 0f3a5 push	r0 */
0x0000f3a6, 0x0700ff42, /* 0700ff42 //C 0f3a6 ld	r0,UART_RSTAT */
0x0000f3a7, 0x010c0001, /* 010c0001 //C 0f3a7 test	r0,1 */
0x0000f3a8, 0x020d0000, /* 020d0000 //C 0f3a8 clc */
0x0000f3a9, 0x220c0000, /* 220c0000 //C 0f3a9 Z0 sec */
0x0000f3aa, 0x0f0d0000, /* 0f0d0000 //C 0f3aa pop	r0 */
0x0000f3ab, 0x30f00e00, /* 30f00e00 //C 0f3ab C1 ret */
0x0000f3ac, 0x0d0d0000, /* 0d0d0000 //C 0f3ac push	r0 */
0x0000f3ad, 0x0d1d0000, /* 0d1d0000 //C 0f3ad push	r1 */
0x0000f3ae, 0x0d2d0000, /* 0d2d0000 //C 0f3ae push	r2 */
0x0000f3af, 0x0700f4ce, /* 0700f4ce //C 0f3af ld	r0,sc_active */
0x0000f3b0, 0x020b0000, /* 020b0000 //C 0f3b0 sz	r0 */
0x0000f3b1, 0x21f2f3c6, /* 21f2f3c6 //C 0f3b1 jnz	check_uart_ret_true */
0x0000f3b2, 0x0700ff20, /* 0700ff20 //C 0f3b2 ld	r0,GPIO_PORTI */
0x0000f3b3, 0x010b0001, /* 010b0001 //C 0f3b3 btst	r0,1 */
0x0000f3b4, 0x0710f3cd, /* 0710f3cd //C 0f3b4 ld	r1,prev_porti */
0x0000f3b5, 0x011b0001, /* 011b0001 //C 0f3b5 btst	r1,1 */
0x0000f3b6, 0x00080100, /* 00080100 //C 0f3b6 cmp	r0,r1 */
0x0000f3b7, 0x11f2f3c8, /* 11f2f3c8 //C 0f3b7 EQ jmp	check_uart_ret_false */
0x0000f3b8, 0x0600f3cd, /* 0600f3cd //C 0f3b8 st	r0,prev_porti */
0x0000f3b9, 0x010b0001, /* 010b0001 //C 0f3b9 btst	r0,1 */
0x0000f3ba, 0x11f2f3c8, /* 11f2f3c8 //C 0f3ba jz	check_uart_ret_false */
0x0000f3bb, 0x01220000, /* 01220000 //C 0f3bb mvzl	r2,0 */
0x0000f3bc, 0x01020001, /* 01020001 //C 0f3bc mvzl	r0,1 */
0x0000f3bd, 0x0600f4ce, /* 0600f4ce //C 0f3bd st	r0,sc_active */
0x0000f3be, 0x0102f4d0, /* 0102f4d0 //C 0f3be mvzl	r0,sc_buffer */
0x0000f3bf, 0x0600f4cf, /* 0600f4cf //C 0f3bf st	r0,sc_ptr */
0x0000f3c0, 0x01120068, /* 01120068 //C 0f3c0 mvzl	r1,'h' */
0x0000f3c1, 0x09108200, /* 09108200 //C 0f3c1 st	r1,r0+,r2 */
0x0000f3c2, 0x0112000d, /* 0112000d //C 0f3c2 mvzl	r1,CR */
0x0000f3c3, 0x09108200, /* 09108200 //C 0f3c3 st	r1,r0+,r2 */
0x0000f3c4, 0x01120000, /* 01120000 //C 0f3c4 mvzl	r1,0 */
0x0000f3c5, 0x09108200, /* 09108200 //C 0f3c5 st	r1,r0+,r2 */
0x0000f3c6, 0x020c0000, /* 020c0000 //C 0f3c6 sec */
0x0000f3c7, 0x01f2f3c9, /* 01f2f3c9 //C 0f3c7 jmp	check_uart_ret */
0x0000f3c8, 0x020d0000, /* 020d0000 //C 0f3c8 clc */
0x0000f3c9, 0x0f2d0000, /* 0f2d0000 //C 0f3c9 pop	r2 */
0x0000f3ca, 0x0f1d0000, /* 0f1d0000 //C 0f3ca pop	r1 */
0x0000f3cb, 0x0f0d0000, /* 0f0d0000 //C 0f3cb pop	r0 */
0x0000f3cc, 0x00f00e00, /* 00f00e00 //C 0f3cc ret */
0x0000f3cd, 0x00000000, /* 00000000 //C 0f3cd db	0 */
0x0000f3ce, 0x0d1d0000, /* 0d1d0000 //C 0f3ce push	r1 */
0x0000f3cf, 0x0d2d0000, /* 0d2d0000 //C 0f3cf push	r2 */
0x0000f3d0, 0x0710f4ce, /* 0710f4ce //C 0f3d0 ld	r1,sc_active */
0x0000f3d1, 0x021b0000, /* 021b0000 //C 0f3d1 sz	r1 */
0x0000f3d2, 0x11f2f3dc, /* 11f2f3dc //C 0f3d2 jz	read_uart */
0x0000f3d3, 0x0710f4cf, /* 0710f4cf //C 0f3d3 ld	r1,sc_ptr */
0x0000f3d4, 0x0e010000, /* 0e010000 //C 0f3d4 ld	r0,r1 */
0x0000f3d5, 0x01140001, /* 01140001 //C 0f3d5 add	r1,1 */
0x0000f3d6, 0x0610f4cf, /* 0610f4cf //C 0f3d6 st	r1,sc_ptr */
0x0000f3d7, 0x0e210000, /* 0e210000 //C 0f3d7 ld	r2,r1 */
0x0000f3d8, 0x022b0000, /* 022b0000 //C 0f3d8 sz	r2 */
0x0000f3d9, 0x21f2f3dd, /* 21f2f3dd //C 0f3d9 jnz	read_sc_ret */
0x0000f3da, 0x0620f4ce, /* 0620f4ce //C 0f3da st	r2,sc_active */
0x0000f3db, 0x01f2f3dd, /* 01f2f3dd //C 0f3db jmp	read_sc_ret */
0x0000f3dc, 0x0700ff40, /* 0700ff40 //C 0f3dc ld	r0,UART_DR */
0x0000f3dd, 0x0f2d0000, /* 0f2d0000 //C 0f3dd pop	r2 */
0x0000f3de, 0x0f1d0000, /* 0f1d0000 //C 0f3de pop	r1 */
0x0000f3df, 0x00f00e00, /* 00f00e00 //C 0f3df ret */
0x0000f3e0, 0x0d9d0000, /* 0d9d0000 //C 0f3e0 push	r9 */
0x0000f3e1, 0x01920070, /* 01920070 //C 0f3e1 mvzl	r9,'p' */
0x0000f3e2, 0x0690ffff, /* 0690ffff //C 0f3e2 st	r9,SIMIF */
0x0000f3e3, 0x0600ffff, /* 0600ffff //C 0f3e3 st	r0,SIMIF */
0x0000f3e4, 0x0600ff00, /* 0600ff00 //C 0f3e4 st	r0,GPIO_PORTA */
0x0000f3e5, 0x01f2f3ea, /* 01f2f3ea //C 0f3e5 jmp	putchar_ret */
0x0000f3e6, 0x0790ff43, /* 0790ff43 //C 0f3e6 ld	r9,UART_TSTAT */
0x0000f3e7, 0x019c0001, /* 019c0001 //C 0f3e7 test	r9,1 */
0x0000f3e8, 0x11f2f3e6, /* 11f2f3e6 //C 0f3e8 jz	wait_tc */
0x0000f3e9, 0x0600ff40, /* 0600ff40 //C 0f3e9 st	r0,UART_DR */
0x0000f3ea, 0x0f9d0000, /* 0f9d0000 //C 0f3ea pop	r9 */
0x0000f3eb, 0x00f00e00, /* 00f00e00 //C 0f3eb ret */
0x0000f3ec, 0x0ded0000, /* 0ded0000 //C 0f3ec push	lr */
0x0000f3ed, 0x0d0d0000, /* 0d0d0000 //C 0f3ed push	r0 */
0x0000f3ee, 0x0d3d0000, /* 0d3d0000 //C 0f3ee push	r3 */
0x0000f3ef, 0x0d4d0000, /* 0d4d0000 //C 0f3ef push	r4 */
0x0000f3f0, 0x0d2d0000, /* 0d2d0000 //C 0f3f0 push	r2 */
0x0000f3f1, 0x01420000, /* 01420000 //C 0f3f1 mvzl	r4,0 */
0x0000f3f2, 0x020b0000, /* 020b0000 //C 0f3f2 sz	r0 */
0x0000f3f3, 0x1102f4c7, /* 1102f4c7 //C 0f3f3 Z1 mvzl	r0,null_str */
0x0000f3f4, 0x00200000, /* 00200000 //C 0f3f4 mov	r2,r0 */
0x0000f3f5, 0x0b048200, /* 0b048200 //C 0f3f5 ld	r0,r4+,r2 */
0x0000f3f6, 0x020b0000, /* 020b0000 //C 0f3f6 sz	r0 */
0x0000f3f7, 0x11f2f3fa, /* 11f2f3fa //C 0f3f7 jz	prints_done */
0x0000f3f8, 0x0400f3e0, /* 0400f3e0 //C 0f3f8 call	putchar */
0x0000f3f9, 0x01f2f3f5, /* 01f2f3f5 //C 0f3f9 jmp	prints_go */
0x0000f3fa, 0x0f2d0000, /* 0f2d0000 //C 0f3fa pop	r2 */
0x0000f3fb, 0x0f4d0000, /* 0f4d0000 //C 0f3fb pop	r4 */
0x0000f3fc, 0x0f3d0000, /* 0f3d0000 //C 0f3fc pop	r3 */
0x0000f3fd, 0x0f0d0000, /* 0f0d0000 //C 0f3fd pop	r0 */
0x0000f3fe, 0x0fed0000, /* 0fed0000 //C 0f3fe pop	lr */
0x0000f3ff, 0x00f00e00, /* 00f00e00 //C 0f3ff ret */
0x0000f400, 0x0ded0000, /* 0ded0000 //C 0f400 push	lr */
0x0000f401, 0x0400f3ec, /* 0400f3ec //C 0f401 call	prints */
0x0000f402, 0x0d0d0000, /* 0d0d0000 //C 0f402 push	r0 */
0x0000f403, 0x0102000a, /* 0102000a //C 0f403 mvzl	r0,LF */
0x0000f404, 0x0400f3e0, /* 0400f3e0 //C 0f404 call	putchar */
0x0000f405, 0x0f0d0000, /* 0f0d0000 //C 0f405 pop	r0 */
0x0000f406, 0x0fed0000, /* 0fed0000 //C 0f406 pop	lr */
0x0000f407, 0x00f00e00, /* 00f00e00 //C 0f407 ret */
0x0000f408, 0x0ded0000, /* 0ded0000 //C 0f408 push	lr */
0x0000f409, 0x0d0d0000, /* 0d0d0000 //C 0f409 push	r0 */
0x0000f40a, 0x0d1d0000, /* 0d1d0000 //C 0f40a push	r1 */
0x0000f40b, 0x0d2d0000, /* 0d2d0000 //C 0f40b push	r2 */
0x0000f40c, 0x0d3d0000, /* 0d3d0000 //C 0f40c push	r3 */
0x0000f40d, 0x0d4d0000, /* 0d4d0000 //C 0f40d push	r4 */
0x0000f40e, 0x00300000, /* 00300000 //C 0f40e mov	r3,r0 */
0x0000f40f, 0x01220000, /* 01220000 //C 0f40f mvzl	r2,0 */
0x0000f410, 0x01420001, /* 01420001 //C 0f410 mvzl	r4,1 */
0x0000f411, 0x01020000, /* 01020000 //C 0f411 mvzl	r0,0 */
0x0000f412, 0x02380000, /* 02380000 //C 0f412 shl	r3 */
0x0000f413, 0x02070000, /* 02070000 //C 0f413 rol	r0 */
0x0000f414, 0x02380000, /* 02380000 //C 0f414 shl	r3 */
0x0000f415, 0x02070000, /* 02070000 //C 0f415 rol	r0 */
0x0000f416, 0x02380000, /* 02380000 //C 0f416 shl	r3 */
0x0000f417, 0x02070000, /* 02070000 //C 0f417 rol	r0 */
0x0000f418, 0x02380000, /* 02380000 //C 0f418 shl	r3 */
0x0000f419, 0x02070000, /* 02070000 //C 0f419 rol	r0 */
0x0000f41a, 0x0400f367, /* 0400f367 //C 0f41a call	value2Hexchar */
0x0000f41b, 0x0400f3e0, /* 0400f3e0 //C 0f41b call	putchar */
0x0000f41c, 0x01240001, /* 01240001 //C 0f41c add	r2,1 */
0x0000f41d, 0x01280008, /* 01280008 //C 0f41d cmp	r2,8 */
0x0000f41e, 0x11f2f428, /* 11f2f428 //C 0f41e jz	print_vhex_ret */
0x0000f41f, 0x021b0000, /* 021b0000 //C 0f41f sz	r1 */
0x0000f420, 0x11f2f426, /* 11f2f426 //C 0f420 jz	print_vhex_nosep */
0x0000f421, 0x00480100, /* 00480100 //C 0f421 cmp	r4,r1 */
0x0000f422, 0x21f2f426, /* 21f2f426 //C 0f422 jnz	print_vhex_nosep */
0x0000f423, 0x0102005f, /* 0102005f //C 0f423 mvzl	r0,'_' */
0x0000f424, 0x0400f3e0, /* 0400f3e0 //C 0f424 call	putchar */
0x0000f425, 0x01420000, /* 01420000 //C 0f425 mvzl	r4,0 */
0x0000f426, 0x01440001, /* 01440001 //C 0f426 add	r4,1 */
0x0000f427, 0x01f2f411, /* 01f2f411 //C 0f427 jmp	print_vhex_cyc */
0x0000f428, 0x0f4d0000, /* 0f4d0000 //C 0f428 pop	r4 */
0x0000f429, 0x0f3d0000, /* 0f3d0000 //C 0f429 pop	r3 */
0x0000f42a, 0x0f2d0000, /* 0f2d0000 //C 0f42a pop	r2 */
0x0000f42b, 0x0f1d0000, /* 0f1d0000 //C 0f42b pop	r1 */
0x0000f42c, 0x0f0d0000, /* 0f0d0000 //C 0f42c pop	r0 */
0x0000f42d, 0x0fed0000, /* 0fed0000 //C 0f42d pop	lr */
0x0000f42e, 0x00f00e00, /* 00f00e00 //C 0f42e ret */
0x0000f49b, 0x00000000, /* 00000000 //C 0f49b dd	0 */
0x0000f49c, 0x00000000, /* 00000000 //C 0f49c dd	0 */
0x0000f49d, 0x00000000, /* 00000000 //C 0f49d dd	0 */
0x0000f49e, 0x00000000, /* 00000000 //C 0f49e dd	0 */
0x0000f49f, 0x00000000, /* 00000000 //C 0f49f dd	0 */
0x0000f4a0, 0x00000000, /* 00000000 //C 0f4a0 dd	0 */
0x0000f4a1, 0x00000000, /* 00000000 //C 0f4a1 dd	0 */
0x0000f4a2, 0x00000000, /* 00000000 //C 0f4a2 dd	0 */
0x0000f4a3, 0x00000000, /* 00000000 //C 0f4a3 dd	0 */
0x0000f4a4, 0x00000000, /* 00000000 //C 0f4a4 dd	0 */
0x0000f4a5, 0x00000000, /* 00000000 //C 0f4a5 dd	0 */
0x0000f4a6, 0x00000000, /* 00000000 //C 0f4a6 dd	0 */
0x0000f4a7, 0x00000000, /* 00000000 //C 0f4a7 dd	0 */
0x0000f4a8, 0x00000000, /* 00000000 //C 0f4a8 dd	0 */
0x0000f4a9, 0x00000000, /* 00000000 //C 0f4a9 dd	0 */
0x0000f4aa, 0x00000000, /* 00000000 //C 0f4aa dd	0 */
0x0000f4ab, 0x00000000, /* 00000000 //C 0f4ab dd	0 */
0x0000f4ac, 0x00000000, /* 00000000 //C 0f4ac dd	0 */
0x0000f4ad, 0x00000000, /* 00000000 //C 0f4ad dd	0 */
0x0000f4ae, 0x00000050, /* 00000050 //C 0f4ae db	80 */
0x0000f4af, 0x0000004d, /* 0000004d //C 0f4af db	77 */
0x0000f4b0, 0x0000006f, /* 0000006f //C 0f4b0 db	111 */
0x0000f4b1, 0x0000006e, /* 0000006e //C 0f4b1 db	110 */
0x0000f4b2, 0x00000069, /* 00000069 //C 0f4b2 db	105 */
0x0000f4b3, 0x00000074, /* 00000074 //C 0f4b3 db	116 */
0x0000f4b4, 0x0000006f, /* 0000006f //C 0f4b4 db	111 */
0x0000f4b5, 0x00000072, /* 00000072 //C 0f4b5 db	114 */
0x0000f4b6, 0x00000020, /* 00000020 //C 0f4b6 db	32 */
0x0000f4b7, 0x00000076, /* 00000076 //C 0f4b7 db	118 */
0x0000f4b8, 0x00000031, /* 00000031 //C 0f4b8 db	49 */
0x0000f4b9, 0x0000002e, /* 0000002e //C 0f4b9 db	46 */
0x0000f4ba, 0x00000030, /* 00000030 //C 0f4ba db	48 */
0x0000f4bb, 0x00000000, /* 00000000 //C 0f4bb db */
0x0000f4bc, 0x0000003e, /* 0000003e //C 0f4bc db	62 */
0x0000f4bd, 0x00000000, /* 00000000 //C 0f4bd db */
0x0000f4be, 0x00000020, /* 00000020 //C 0f4be db	32 */
0x0000f4bf, 0x0000003b, /* 0000003b //C 0f4bf db	59 */
0x0000f4c0, 0x00000009, /* 00000009 //C 0f4c0 db	9 */
0x0000f4c1, 0x0000000b, /* 0000000b //C 0f4c1 db	11 */
0x0000f4c2, 0x0000002c, /* 0000002c //C 0f4c2 db	44 */
0x0000f4c3, 0x0000003d, /* 0000003d //C 0f4c3 db	61 */
0x0000f4c4, 0x0000005b, /* 0000005b //C 0f4c4 db	91 */
0x0000f4c5, 0x0000005d, /* 0000005d //C 0f4c5 db	93 */
0x0000f4c6, 0x00000000, /* 00000000 //C 0f4c6 db */
0x0000f4c7, 0x00000028, /* 00000028 //C 0f4c7 db	40 */
0x0000f4c8, 0x0000006e, /* 0000006e //C 0f4c8 db	110 */
0x0000f4c9, 0x00000075, /* 00000075 //C 0f4c9 db	117 */
0x0000f4ca, 0x0000006c, /* 0000006c //C 0f4ca db	108 */
0x0000f4cb, 0x0000006c, /* 0000006c //C 0f4cb db	108 */
0x0000f4cc, 0x00000029, /* 00000029 //C 0f4cc db	41 */
0x0000f4cd, 0x00000000, /* 00000000 //C 0f4cd db */
0x0000f4ce, 0x00000000, /* 00000000 //C 0f4ce db	0 */
0x0000f4cf, 0x00000000, /* 00000000 //C 0f4cf db	0 */
0x0000f4da, 0x0000f105, /* 0000f105 //C 0f4da dd	cmd_m */
0x0000f4db, 0x0000006d, /* 0000006d //C 0f4db db	109 */
0x0000f4dc, 0x00000000, /* 00000000 //C 0f4dc db */
0x0000f4dd, 0x0000f105, /* 0000f105 //C 0f4dd dd	cmd_m */
0x0000f4de, 0x0000006d, /* 0000006d //C 0f4de db	109 */
0x0000f4df, 0x00000065, /* 00000065 //C 0f4df db	101 */
0x0000f4e0, 0x0000006d, /* 0000006d //C 0f4e0 db	109 */
0x0000f4e1, 0x00000000, /* 00000000 //C 0f4e1 db */
0x0000f4e2, 0x0000f15a, /* 0000f15a //C 0f4e2 dd	cmd_d */
0x0000f4e3, 0x00000064, /* 00000064 //C 0f4e3 db	100 */
0x0000f4e4, 0x00000000, /* 00000000 //C 0f4e4 db */
0x0000f4e5, 0x0000f15a, /* 0000f15a //C 0f4e5 dd	cmd_d */
0x0000f4e6, 0x00000064, /* 00000064 //C 0f4e6 db	100 */
0x0000f4e7, 0x00000075, /* 00000075 //C 0f4e7 db	117 */
0x0000f4e8, 0x0000006d, /* 0000006d //C 0f4e8 db	109 */
0x0000f4e9, 0x00000070, /* 00000070 //C 0f4e9 db	112 */
0x0000f4ea, 0x00000000, /* 00000000 //C 0f4ea db */
0x0000f4eb, 0x0000f18e, /* 0000f18e //C 0f4eb dd	cmd_l */
0x0000f4ec, 0x0000006c, /* 0000006c //C 0f4ec db	108 */
0x0000f4ed, 0x00000000, /* 00000000 //C 0f4ed db */
0x0000f4ee, 0x0000f18e, /* 0000f18e //C 0f4ee dd	cmd_l */
0x0000f4ef, 0x0000006c, /* 0000006c //C 0f4ef db	108 */
0x0000f4f0, 0x0000006f, /* 0000006f //C 0f4f0 db	111 */
0x0000f4f1, 0x00000061, /* 00000061 //C 0f4f1 db	97 */
0x0000f4f2, 0x00000064, /* 00000064 //C 0f4f2 db	100 */
0x0000f4f3, 0x00000000, /* 00000000 //C 0f4f3 db */
0x0000f4f4, 0x0000f1fb, /* 0000f1fb //C 0f4f4 dd	cmd_g */
0x0000f4f5, 0x00000067, /* 00000067 //C 0f4f5 db	103 */
0x0000f4f6, 0x00000000, /* 00000000 //C 0f4f6 db */
0x0000f4f7, 0x0000f1fb, /* 0000f1fb //C 0f4f7 dd	cmd_g */
0x0000f4f8, 0x00000067, /* 00000067 //C 0f4f8 db	103 */
0x0000f4f9, 0x0000006f, /* 0000006f //C 0f4f9 db	111 */
0x0000f4fa, 0x00000000, /* 00000000 //C 0f4fa db */
0x0000f4fb, 0x0000f1fb, /* 0000f1fb //C 0f4fb dd	cmd_g */
0x0000f4fc, 0x00000072, /* 00000072 //C 0f4fc db	114 */
0x0000f4fd, 0x00000075, /* 00000075 //C 0f4fd db	117 */
0x0000f4fe, 0x0000006e, /* 0000006e //C 0f4fe db	110 */
0x0000f4ff, 0x00000000, /* 00000000 //C 0f4ff db */
0x0000f500, 0x0000f23b, /* 0000f23b //C 0f500 dd	cmd_h */
0x0000f501, 0x0000003f, /* 0000003f //C 0f501 db	63 */
0x0000f502, 0x00000000, /* 00000000 //C 0f502 db */
0x0000f503, 0x0000f23b, /* 0000f23b //C 0f503 dd	cmd_h */
0x0000f504, 0x00000068, /* 00000068 //C 0f504 db	104 */
0x0000f505, 0x00000000, /* 00000000 //C 0f505 db */
0x0000f506, 0x0000f23b, /* 0000f23b //C 0f506 dd	cmd_h */
0x0000f507, 0x00000068, /* 00000068 //C 0f507 db	104 */
0x0000f508, 0x00000065, /* 00000065 //C 0f508 db	101 */
0x0000f509, 0x0000006c, /* 0000006c //C 0f509 db	108 */
0x0000f50a, 0x00000070, /* 00000070 //C 0f50a db	112 */
0x0000f50b, 0x00000000, /* 00000000 //C 0f50b db */
0x0000f50c, 0x0000f2a7, /* 0000f2a7 //C 0f50c dd	cmd_r */
0x0000f50d, 0x00000072, /* 00000072 //C 0f50d db	114 */
0x0000f50e, 0x00000000, /* 00000000 //C 0f50e db */
0x0000f50f, 0x0000f2a7, /* 0000f2a7 //C 0f50f dd	cmd_r */
0x0000f510, 0x00000072, /* 00000072 //C 0f510 db	114 */
0x0000f511, 0x00000065, /* 00000065 //C 0f511 db	101 */
0x0000f512, 0x00000067, /* 00000067 //C 0f512 db	103 */
0x0000f513, 0x00000000, /* 00000000 //C 0f513 db */
0x0000f514, 0x0000f2a7, /* 0000f2a7 //C 0f514 dd	cmd_r */
0x0000f515, 0x00000072, /* 00000072 //C 0f515 db	114 */
0x0000f516, 0x00000065, /* 00000065 //C 0f516 db	101 */
0x0000f517, 0x00000067, /* 00000067 //C 0f517 db	103 */
0x0000f518, 0x00000073, /* 00000073 //C 0f518 db	115 */
0x0000f519, 0x00000000, /* 00000000 //C 0f519 db */
0x0000f51a, 0x0000f2fa, /* 0000f2fa //C 0f51a dd	cmd_sp */
0x0000f51b, 0x00000073, /* 00000073 //C 0f51b db	115 */
0x0000f51c, 0x00000070, /* 00000070 //C 0f51c db	112 */
0x0000f51d, 0x00000000, /* 00000000 //C 0f51d db */
0x0000f51e, 0x0000f2fd, /* 0000f2fd //C 0f51e dd	cmd_lr */
0x0000f51f, 0x0000006c, /* 0000006c //C 0f51f db	108 */
0x0000f520, 0x00000072, /* 00000072 //C 0f520 db	114 */
0x0000f521, 0x00000000, /* 00000000 //C 0f521 db */
0x0000f522, 0x0000f300, /* 0000f300 //C 0f522 dd	cmd_pc */
0x0000f523, 0x00000070, /* 00000070 //C 0f523 db	112 */
0x0000f524, 0x00000063, /* 00000063 //C 0f524 db	99 */
0x0000f525, 0x00000000, /* 00000000 //C 0f525 db */
0x0000f526, 0x0000f303, /* 0000f303 //C 0f526 dd	cmd_f */
0x0000f527, 0x00000066, /* 00000066 //C 0f527 db	102 */
0x0000f528, 0x00000000, /* 00000000 //C 0f528 db */
0x0000f529, 0x00000000, /* 00000000 //C 0f529 dd	0 */
0x0000f52a, 0x00000000, /* 00000000 //C 0f52a dd	0 */
0x0000f52b, 0x0000006d, /* 0000006d //C 0f52b db	109 */
0x0000f52c, 0x0000005b, /* 0000005b //C 0f52c db	91 */
0x0000f52d, 0x00000065, /* 00000065 //C 0f52d db	101 */
0x0000f52e, 0x0000006d, /* 0000006d //C 0f52e db	109 */
0x0000f52f, 0x0000005d, /* 0000005d //C 0f52f db	93 */
0x0000f530, 0x00000020, /* 00000020 //C 0f530 db	32 */
0x0000f531, 0x00000061, /* 00000061 //C 0f531 db	97 */
0x0000f532, 0x00000064, /* 00000064 //C 0f532 db	100 */
0x0000f533, 0x00000064, /* 00000064 //C 0f533 db	100 */
0x0000f534, 0x00000072, /* 00000072 //C 0f534 db	114 */
0x0000f535, 0x00000020, /* 00000020 //C 0f535 db	32 */
0x0000f536, 0x0000005b, /* 0000005b //C 0f536 db	91 */
0x0000f537, 0x00000076, /* 00000076 //C 0f537 db	118 */
0x0000f538, 0x00000061, /* 00000061 //C 0f538 db	97 */
0x0000f539, 0x0000006c, /* 0000006c //C 0f539 db	108 */
0x0000f53a, 0x0000005d, /* 0000005d //C 0f53a db	93 */
0x0000f53b, 0x00000020, /* 00000020 //C 0f53b db	32 */
0x0000f53c, 0x00000020, /* 00000020 //C 0f53c db	32 */
0x0000f53d, 0x00000047, /* 00000047 //C 0f53d db	71 */
0x0000f53e, 0x00000065, /* 00000065 //C 0f53e db	101 */
0x0000f53f, 0x00000074, /* 00000074 //C 0f53f db	116 */
0x0000f540, 0x0000002f, /* 0000002f //C 0f540 db	47 */
0x0000f541, 0x00000073, /* 00000073 //C 0f541 db	115 */
0x0000f542, 0x00000065, /* 00000065 //C 0f542 db	101 */
0x0000f543, 0x00000074, /* 00000074 //C 0f543 db	116 */
0x0000f544, 0x00000020, /* 00000020 //C 0f544 db	32 */
0x0000f545, 0x0000006d, /* 0000006d //C 0f545 db	109 */
0x0000f546, 0x00000065, /* 00000065 //C 0f546 db	101 */
0x0000f547, 0x0000006d, /* 0000006d //C 0f547 db	109 */
0x0000f548, 0x0000006f, /* 0000006f //C 0f548 db	111 */
0x0000f549, 0x00000072, /* 00000072 //C 0f549 db	114 */
0x0000f54a, 0x00000079, /* 00000079 //C 0f54a db	121 */
0x0000f54b, 0x0000000a, /* 0000000a //C 0f54b db	10 */
0x0000f54c, 0x00000000, /* 00000000 //C 0f54c db */
0x0000f54d, 0x00000064, /* 00000064 //C 0f54d db	100 */
0x0000f54e, 0x0000005b, /* 0000005b //C 0f54e db	91 */
0x0000f54f, 0x00000075, /* 00000075 //C 0f54f db	117 */
0x0000f550, 0x0000006d, /* 0000006d //C 0f550 db	109 */
0x0000f551, 0x00000070, /* 00000070 //C 0f551 db	112 */
0x0000f552, 0x0000005d, /* 0000005d //C 0f552 db	93 */
0x0000f553, 0x00000020, /* 00000020 //C 0f553 db	32 */
0x0000f554, 0x00000073, /* 00000073 //C 0f554 db	115 */
0x0000f555, 0x00000074, /* 00000074 //C 0f555 db	116 */
0x0000f556, 0x00000061, /* 00000061 //C 0f556 db	97 */
0x0000f557, 0x00000072, /* 00000072 //C 0f557 db	114 */
0x0000f558, 0x00000074, /* 00000074 //C 0f558 db	116 */
0x0000f559, 0x00000020, /* 00000020 //C 0f559 db	32 */
0x0000f55a, 0x00000065, /* 00000065 //C 0f55a db	101 */
0x0000f55b, 0x0000006e, /* 0000006e //C 0f55b db	110 */
0x0000f55c, 0x00000064, /* 00000064 //C 0f55c db	100 */
0x0000f55d, 0x00000020, /* 00000020 //C 0f55d db	32 */
0x0000f55e, 0x00000020, /* 00000020 //C 0f55e db	32 */
0x0000f55f, 0x00000044, /* 00000044 //C 0f55f db	68 */
0x0000f560, 0x00000075, /* 00000075 //C 0f560 db	117 */
0x0000f561, 0x0000006d, /* 0000006d //C 0f561 db	109 */
0x0000f562, 0x00000070, /* 00000070 //C 0f562 db	112 */
0x0000f563, 0x00000020, /* 00000020 //C 0f563 db	32 */
0x0000f564, 0x0000006d, /* 0000006d //C 0f564 db	109 */
0x0000f565, 0x00000065, /* 00000065 //C 0f565 db	101 */
0x0000f566, 0x0000006d, /* 0000006d //C 0f566 db	109 */
0x0000f567, 0x0000006f, /* 0000006f //C 0f567 db	111 */
0x0000f568, 0x00000072, /* 00000072 //C 0f568 db	114 */
0x0000f569, 0x00000079, /* 00000079 //C 0f569 db	121 */
0x0000f56a, 0x00000020, /* 00000020 //C 0f56a db	32 */
0x0000f56b, 0x00000063, /* 00000063 //C 0f56b db	99 */
0x0000f56c, 0x0000006f, /* 0000006f //C 0f56c db	111 */
0x0000f56d, 0x0000006e, /* 0000006e //C 0f56d db	110 */
0x0000f56e, 0x00000074, /* 00000074 //C 0f56e db	116 */
0x0000f56f, 0x00000065, /* 00000065 //C 0f56f db	101 */
0x0000f570, 0x0000006e, /* 0000006e //C 0f570 db	110 */
0x0000f571, 0x00000074, /* 00000074 //C 0f571 db	116 */
0x0000f572, 0x0000000a, /* 0000000a //C 0f572 db	10 */
0x0000f573, 0x00000000, /* 00000000 //C 0f573 db */
0x0000f574, 0x0000006c, /* 0000006c //C 0f574 db	108 */
0x0000f575, 0x0000005b, /* 0000005b //C 0f575 db	91 */
0x0000f576, 0x0000006f, /* 0000006f //C 0f576 db	111 */
0x0000f577, 0x00000061, /* 00000061 //C 0f577 db	97 */
0x0000f578, 0x00000064, /* 00000064 //C 0f578 db	100 */
0x0000f579, 0x0000005d, /* 0000005d //C 0f579 db	93 */
0x0000f57a, 0x00000020, /* 00000020 //C 0f57a db	32 */
0x0000f57b, 0x00000020, /* 00000020 //C 0f57b db	32 */
0x0000f57c, 0x00000020, /* 00000020 //C 0f57c db	32 */
0x0000f57d, 0x00000020, /* 00000020 //C 0f57d db	32 */
0x0000f57e, 0x00000020, /* 00000020 //C 0f57e db	32 */
0x0000f57f, 0x00000020, /* 00000020 //C 0f57f db	32 */
0x0000f580, 0x00000020, /* 00000020 //C 0f580 db	32 */
0x0000f581, 0x00000020, /* 00000020 //C 0f581 db	32 */
0x0000f582, 0x00000020, /* 00000020 //C 0f582 db	32 */
0x0000f583, 0x00000020, /* 00000020 //C 0f583 db	32 */
0x0000f584, 0x00000020, /* 00000020 //C 0f584 db	32 */
0x0000f585, 0x00000020, /* 00000020 //C 0f585 db	32 */
0x0000f586, 0x0000004c, /* 0000004c //C 0f586 db	76 */
0x0000f587, 0x0000006f, /* 0000006f //C 0f587 db	111 */
0x0000f588, 0x00000061, /* 00000061 //C 0f588 db	97 */
0x0000f589, 0x00000064, /* 00000064 //C 0f589 db	100 */
0x0000f58a, 0x00000020, /* 00000020 //C 0f58a db	32 */
0x0000f58b, 0x00000068, /* 00000068 //C 0f58b db	104 */
0x0000f58c, 0x00000065, /* 00000065 //C 0f58c db	101 */
0x0000f58d, 0x00000078, /* 00000078 //C 0f58d db	120 */
0x0000f58e, 0x00000020, /* 00000020 //C 0f58e db	32 */
0x0000f58f, 0x00000066, /* 00000066 //C 0f58f db	102 */
0x0000f590, 0x00000069, /* 00000069 //C 0f590 db	105 */
0x0000f591, 0x0000006c, /* 0000006c //C 0f591 db	108 */
0x0000f592, 0x00000065, /* 00000065 //C 0f592 db	101 */
0x0000f593, 0x00000020, /* 00000020 //C 0f593 db	32 */
0x0000f594, 0x00000074, /* 00000074 //C 0f594 db	116 */
0x0000f595, 0x0000006f, /* 0000006f //C 0f595 db	111 */
0x0000f596, 0x00000020, /* 00000020 //C 0f596 db	32 */
0x0000f597, 0x0000006d, /* 0000006d //C 0f597 db	109 */
0x0000f598, 0x00000065, /* 00000065 //C 0f598 db	101 */
0x0000f599, 0x0000006d, /* 0000006d //C 0f599 db	109 */
0x0000f59a, 0x0000006f, /* 0000006f //C 0f59a db	111 */
0x0000f59b, 0x00000072, /* 00000072 //C 0f59b db	114 */
0x0000f59c, 0x00000079, /* 00000079 //C 0f59c db	121 */
0x0000f59d, 0x0000000a, /* 0000000a //C 0f59d db	10 */
0x0000f59e, 0x00000000, /* 00000000 //C 0f59e db */
0x0000f59f, 0x00000067, /* 00000067 //C 0f59f db	103 */
0x0000f5a0, 0x0000005b, /* 0000005b //C 0f5a0 db	91 */
0x0000f5a1, 0x0000006f, /* 0000006f //C 0f5a1 db	111 */
0x0000f5a2, 0x0000005d, /* 0000005d //C 0f5a2 db	93 */
0x0000f5a3, 0x0000007c, /* 0000007c //C 0f5a3 db	124 */
0x0000f5a4, 0x00000072, /* 00000072 //C 0f5a4 db	114 */
0x0000f5a5, 0x00000075, /* 00000075 //C 0f5a5 db	117 */
0x0000f5a6, 0x0000006e, /* 0000006e //C 0f5a6 db	110 */
0x0000f5a7, 0x00000020, /* 00000020 //C 0f5a7 db	32 */
0x0000f5a8, 0x0000005b, /* 0000005b //C 0f5a8 db	91 */
0x0000f5a9, 0x00000061, /* 00000061 //C 0f5a9 db	97 */
0x0000f5aa, 0x00000064, /* 00000064 //C 0f5aa db	100 */
0x0000f5ab, 0x00000064, /* 00000064 //C 0f5ab db	100 */
0x0000f5ac, 0x00000072, /* 00000072 //C 0f5ac db	114 */
0x0000f5ad, 0x0000005d, /* 0000005d //C 0f5ad db	93 */
0x0000f5ae, 0x00000020, /* 00000020 //C 0f5ae db	32 */
0x0000f5af, 0x00000020, /* 00000020 //C 0f5af db	32 */
0x0000f5b0, 0x00000020, /* 00000020 //C 0f5b0 db	32 */
0x0000f5b1, 0x00000052, /* 00000052 //C 0f5b1 db	82 */
0x0000f5b2, 0x00000075, /* 00000075 //C 0f5b2 db	117 */
0x0000f5b3, 0x0000006e, /* 0000006e //C 0f5b3 db	110 */
0x0000f5b4, 0x00000020, /* 00000020 //C 0f5b4 db	32 */
0x0000f5b5, 0x00000066, /* 00000066 //C 0f5b5 db	102 */
0x0000f5b6, 0x00000072, /* 00000072 //C 0f5b6 db	114 */
0x0000f5b7, 0x0000006f, /* 0000006f //C 0f5b7 db	111 */
0x0000f5b8, 0x0000006d, /* 0000006d //C 0f5b8 db	109 */
0x0000f5b9, 0x00000020, /* 00000020 //C 0f5b9 db	32 */
0x0000f5ba, 0x00000061, /* 00000061 //C 0f5ba db	97 */
0x0000f5bb, 0x00000064, /* 00000064 //C 0f5bb db	100 */
0x0000f5bc, 0x00000064, /* 00000064 //C 0f5bc db	100 */
0x0000f5bd, 0x00000072, /* 00000072 //C 0f5bd db	114 */
0x0000f5be, 0x00000065, /* 00000065 //C 0f5be db	101 */
0x0000f5bf, 0x00000073, /* 00000073 //C 0f5bf db	115 */
0x0000f5c0, 0x00000073, /* 00000073 //C 0f5c0 db	115 */
0x0000f5c1, 0x0000000a, /* 0000000a //C 0f5c1 db	10 */
0x0000f5c2, 0x00000000, /* 00000000 //C 0f5c2 db */
0x0000f5c3, 0x00000072, /* 00000072 //C 0f5c3 db	114 */
0x0000f5c4, 0x0000005b, /* 0000005b //C 0f5c4 db	91 */
0x0000f5c5, 0x00000065, /* 00000065 //C 0f5c5 db	101 */
0x0000f5c6, 0x00000067, /* 00000067 //C 0f5c6 db	103 */
0x0000f5c7, 0x0000005b, /* 0000005b //C 0f5c7 db	91 */
0x0000f5c8, 0x00000073, /* 00000073 //C 0f5c8 db	115 */
0x0000f5c9, 0x0000005d, /* 0000005d //C 0f5c9 db	93 */
0x0000f5ca, 0x0000005d, /* 0000005d //C 0f5ca db	93 */
0x0000f5cb, 0x00000020, /* 00000020 //C 0f5cb db	32 */
0x0000f5cc, 0x00000020, /* 00000020 //C 0f5cc db	32 */
0x0000f5cd, 0x00000020, /* 00000020 //C 0f5cd db	32 */
0x0000f5ce, 0x00000020, /* 00000020 //C 0f5ce db	32 */
0x0000f5cf, 0x00000020, /* 00000020 //C 0f5cf db	32 */
0x0000f5d0, 0x00000020, /* 00000020 //C 0f5d0 db	32 */
0x0000f5d1, 0x00000020, /* 00000020 //C 0f5d1 db	32 */
0x0000f5d2, 0x00000020, /* 00000020 //C 0f5d2 db	32 */
0x0000f5d3, 0x00000020, /* 00000020 //C 0f5d3 db	32 */
0x0000f5d4, 0x00000020, /* 00000020 //C 0f5d4 db	32 */
0x0000f5d5, 0x00000050, /* 00000050 //C 0f5d5 db	80 */
0x0000f5d6, 0x00000072, /* 00000072 //C 0f5d6 db	114 */
0x0000f5d7, 0x00000069, /* 00000069 //C 0f5d7 db	105 */
0x0000f5d8, 0x0000006e, /* 0000006e //C 0f5d8 db	110 */
0x0000f5d9, 0x00000074, /* 00000074 //C 0f5d9 db	116 */
0x0000f5da, 0x00000020, /* 00000020 //C 0f5da db	32 */
0x0000f5db, 0x00000072, /* 00000072 //C 0f5db db	114 */
0x0000f5dc, 0x00000065, /* 00000065 //C 0f5dc db	101 */
0x0000f5dd, 0x00000067, /* 00000067 //C 0f5dd db	103 */
0x0000f5de, 0x00000069, /* 00000069 //C 0f5de db	105 */
0x0000f5df, 0x00000073, /* 00000073 //C 0f5df db	115 */
0x0000f5e0, 0x00000074, /* 00000074 //C 0f5e0 db	116 */
0x0000f5e1, 0x00000065, /* 00000065 //C 0f5e1 db	101 */
0x0000f5e2, 0x00000072, /* 00000072 //C 0f5e2 db	114 */
0x0000f5e3, 0x00000073, /* 00000073 //C 0f5e3 db	115 */
0x0000f5e4, 0x0000000a, /* 0000000a //C 0f5e4 db	10 */
0x0000f5e5, 0x00000000, /* 00000000 //C 0f5e5 db */
0x0000f5e6, 0x00000072, /* 00000072 //C 0f5e6 db	114 */
0x0000f5e7, 0x00000058, /* 00000058 //C 0f5e7 db	88 */
0x0000f5e8, 0x00000020, /* 00000020 //C 0f5e8 db	32 */
0x0000f5e9, 0x0000005b, /* 0000005b //C 0f5e9 db	91 */
0x0000f5ea, 0x00000076, /* 00000076 //C 0f5ea db	118 */
0x0000f5eb, 0x00000061, /* 00000061 //C 0f5eb db	97 */
0x0000f5ec, 0x0000006c, /* 0000006c //C 0f5ec db	108 */
0x0000f5ed, 0x0000005d, /* 0000005d //C 0f5ed db	93 */
0x0000f5ee, 0x00000020, /* 00000020 //C 0f5ee db	32 */
0x0000f5ef, 0x00000020, /* 00000020 //C 0f5ef db	32 */
0x0000f5f0, 0x00000020, /* 00000020 //C 0f5f0 db	32 */
0x0000f5f1, 0x00000020, /* 00000020 //C 0f5f1 db	32 */
0x0000f5f2, 0x00000020, /* 00000020 //C 0f5f2 db	32 */
0x0000f5f3, 0x00000020, /* 00000020 //C 0f5f3 db	32 */
0x0000f5f4, 0x00000020, /* 00000020 //C 0f5f4 db	32 */
0x0000f5f5, 0x00000020, /* 00000020 //C 0f5f5 db	32 */
0x0000f5f6, 0x00000020, /* 00000020 //C 0f5f6 db	32 */
0x0000f5f7, 0x00000020, /* 00000020 //C 0f5f7 db	32 */
0x0000f5f8, 0x00000047, /* 00000047 //C 0f5f8 db	71 */
0x0000f5f9, 0x00000065, /* 00000065 //C 0f5f9 db	101 */
0x0000f5fa, 0x00000074, /* 00000074 //C 0f5fa db	116 */
0x0000f5fb, 0x0000002f, /* 0000002f //C 0f5fb db	47 */
0x0000f5fc, 0x00000073, /* 00000073 //C 0f5fc db	115 */
0x0000f5fd, 0x00000065, /* 00000065 //C 0f5fd db	101 */
0x0000f5fe, 0x00000074, /* 00000074 //C 0f5fe db	116 */
0x0000f5ff, 0x00000020, /* 00000020 //C 0f5ff db	32 */
0x0000f600, 0x00000052, /* 00000052 //C 0f600 db	82 */
0x0000f601, 0x00000058, /* 00000058 //C 0f601 db	88 */
0x0000f602, 0x0000000a, /* 0000000a //C 0f602 db	10 */
0x0000f603, 0x00000000, /* 00000000 //C 0f603 db */
0x0000f604, 0x00000073, /* 00000073 //C 0f604 db	115 */
0x0000f605, 0x00000070, /* 00000070 //C 0f605 db	112 */
0x0000f606, 0x00000020, /* 00000020 //C 0f606 db	32 */
0x0000f607, 0x0000005b, /* 0000005b //C 0f607 db	91 */
0x0000f608, 0x00000076, /* 00000076 //C 0f608 db	118 */
0x0000f609, 0x00000061, /* 00000061 //C 0f609 db	97 */
0x0000f60a, 0x0000006c, /* 0000006c //C 0f60a db	108 */
0x0000f60b, 0x0000005d, /* 0000005d //C 0f60b db	93 */
0x0000f60c, 0x00000020, /* 00000020 //C 0f60c db	32 */
0x0000f60d, 0x00000020, /* 00000020 //C 0f60d db	32 */
0x0000f60e, 0x00000020, /* 00000020 //C 0f60e db	32 */
0x0000f60f, 0x00000020, /* 00000020 //C 0f60f db	32 */
0x0000f610, 0x00000020, /* 00000020 //C 0f610 db	32 */
0x0000f611, 0x00000020, /* 00000020 //C 0f611 db	32 */
0x0000f612, 0x00000020, /* 00000020 //C 0f612 db	32 */
0x0000f613, 0x00000020, /* 00000020 //C 0f613 db	32 */
0x0000f614, 0x00000020, /* 00000020 //C 0f614 db	32 */
0x0000f615, 0x00000020, /* 00000020 //C 0f615 db	32 */
0x0000f616, 0x00000047, /* 00000047 //C 0f616 db	71 */
0x0000f617, 0x00000065, /* 00000065 //C 0f617 db	101 */
0x0000f618, 0x00000074, /* 00000074 //C 0f618 db	116 */
0x0000f619, 0x0000002f, /* 0000002f //C 0f619 db	47 */
0x0000f61a, 0x00000073, /* 00000073 //C 0f61a db	115 */
0x0000f61b, 0x00000065, /* 00000065 //C 0f61b db	101 */
0x0000f61c, 0x00000074, /* 00000074 //C 0f61c db	116 */
0x0000f61d, 0x00000020, /* 00000020 //C 0f61d db	32 */
0x0000f61e, 0x00000052, /* 00000052 //C 0f61e db	82 */
0x0000f61f, 0x00000031, /* 00000031 //C 0f61f db	49 */
0x0000f620, 0x00000033, /* 00000033 //C 0f620 db	51 */
0x0000f621, 0x0000000a, /* 0000000a //C 0f621 db	10 */
0x0000f622, 0x00000000, /* 00000000 //C 0f622 db */
0x0000f623, 0x0000006c, /* 0000006c //C 0f623 db	108 */
0x0000f624, 0x00000072, /* 00000072 //C 0f624 db	114 */
0x0000f625, 0x00000020, /* 00000020 //C 0f625 db	32 */
0x0000f626, 0x0000005b, /* 0000005b //C 0f626 db	91 */
0x0000f627, 0x00000076, /* 00000076 //C 0f627 db	118 */
0x0000f628, 0x00000061, /* 00000061 //C 0f628 db	97 */
0x0000f629, 0x0000006c, /* 0000006c //C 0f629 db	108 */
0x0000f62a, 0x0000005d, /* 0000005d //C 0f62a db	93 */
0x0000f62b, 0x00000020, /* 00000020 //C 0f62b db	32 */
0x0000f62c, 0x00000020, /* 00000020 //C 0f62c db	32 */
0x0000f62d, 0x00000020, /* 00000020 //C 0f62d db	32 */
0x0000f62e, 0x00000020, /* 00000020 //C 0f62e db	32 */
0x0000f62f, 0x00000020, /* 00000020 //C 0f62f db	32 */
0x0000f630, 0x00000020, /* 00000020 //C 0f630 db	32 */
0x0000f631, 0x00000020, /* 00000020 //C 0f631 db	32 */
0x0000f632, 0x00000020, /* 00000020 //C 0f632 db	32 */
0x0000f633, 0x00000020, /* 00000020 //C 0f633 db	32 */
0x0000f634, 0x00000020, /* 00000020 //C 0f634 db	32 */
0x0000f635, 0x00000047, /* 00000047 //C 0f635 db	71 */
0x0000f636, 0x00000065, /* 00000065 //C 0f636 db	101 */
0x0000f637, 0x00000074, /* 00000074 //C 0f637 db	116 */
0x0000f638, 0x0000002f, /* 0000002f //C 0f638 db	47 */
0x0000f639, 0x00000073, /* 00000073 //C 0f639 db	115 */
0x0000f63a, 0x00000065, /* 00000065 //C 0f63a db	101 */
0x0000f63b, 0x00000074, /* 00000074 //C 0f63b db	116 */
0x0000f63c, 0x00000020, /* 00000020 //C 0f63c db	32 */
0x0000f63d, 0x00000052, /* 00000052 //C 0f63d db	82 */
0x0000f63e, 0x00000031, /* 00000031 //C 0f63e db	49 */
0x0000f63f, 0x00000034, /* 00000034 //C 0f63f db	52 */
0x0000f640, 0x0000000a, /* 0000000a //C 0f640 db	10 */
0x0000f641, 0x00000000, /* 00000000 //C 0f641 db */
0x0000f642, 0x00000070, /* 00000070 //C 0f642 db	112 */
0x0000f643, 0x00000063, /* 00000063 //C 0f643 db	99 */
0x0000f644, 0x00000020, /* 00000020 //C 0f644 db	32 */
0x0000f645, 0x0000005b, /* 0000005b //C 0f645 db	91 */
0x0000f646, 0x00000076, /* 00000076 //C 0f646 db	118 */
0x0000f647, 0x00000061, /* 00000061 //C 0f647 db	97 */
0x0000f648, 0x0000006c, /* 0000006c //C 0f648 db	108 */
0x0000f649, 0x0000005d, /* 0000005d //C 0f649 db	93 */
0x0000f64a, 0x00000020, /* 00000020 //C 0f64a db	32 */
0x0000f64b, 0x00000020, /* 00000020 //C 0f64b db	32 */
0x0000f64c, 0x00000020, /* 00000020 //C 0f64c db	32 */
0x0000f64d, 0x00000020, /* 00000020 //C 0f64d db	32 */
0x0000f64e, 0x00000020, /* 00000020 //C 0f64e db	32 */
0x0000f64f, 0x00000020, /* 00000020 //C 0f64f db	32 */
0x0000f650, 0x00000020, /* 00000020 //C 0f650 db	32 */
0x0000f651, 0x00000020, /* 00000020 //C 0f651 db	32 */
0x0000f652, 0x00000020, /* 00000020 //C 0f652 db	32 */
0x0000f653, 0x00000020, /* 00000020 //C 0f653 db	32 */
0x0000f654, 0x00000047, /* 00000047 //C 0f654 db	71 */
0x0000f655, 0x00000065, /* 00000065 //C 0f655 db	101 */
0x0000f656, 0x00000074, /* 00000074 //C 0f656 db	116 */
0x0000f657, 0x0000002f, /* 0000002f //C 0f657 db	47 */
0x0000f658, 0x00000073, /* 00000073 //C 0f658 db	115 */
0x0000f659, 0x00000065, /* 00000065 //C 0f659 db	101 */
0x0000f65a, 0x00000074, /* 00000074 //C 0f65a db	116 */
0x0000f65b, 0x00000020, /* 00000020 //C 0f65b db	32 */
0x0000f65c, 0x00000052, /* 00000052 //C 0f65c db	82 */
0x0000f65d, 0x00000031, /* 00000031 //C 0f65d db	49 */
0x0000f65e, 0x00000035, /* 00000035 //C 0f65e db	53 */
0x0000f65f, 0x0000000a, /* 0000000a //C 0f65f db	10 */
0x0000f660, 0x00000000, /* 00000000 //C 0f660 db */
0x0000f661, 0x00000066, /* 00000066 //C 0f661 db	102 */
0x0000f662, 0x00000020, /* 00000020 //C 0f662 db	32 */
0x0000f663, 0x0000005b, /* 0000005b //C 0f663 db	91 */
0x0000f664, 0x00000076, /* 00000076 //C 0f664 db	118 */
0x0000f665, 0x00000061, /* 00000061 //C 0f665 db	97 */
0x0000f666, 0x0000006c, /* 0000006c //C 0f666 db	108 */
0x0000f667, 0x0000005d, /* 0000005d //C 0f667 db	93 */
0x0000f668, 0x00000020, /* 00000020 //C 0f668 db	32 */
0x0000f669, 0x00000020, /* 00000020 //C 0f669 db	32 */
0x0000f66a, 0x00000020, /* 00000020 //C 0f66a db	32 */
0x0000f66b, 0x00000020, /* 00000020 //C 0f66b db	32 */
0x0000f66c, 0x00000020, /* 00000020 //C 0f66c db	32 */
0x0000f66d, 0x00000020, /* 00000020 //C 0f66d db	32 */
0x0000f66e, 0x00000020, /* 00000020 //C 0f66e db	32 */
0x0000f66f, 0x00000020, /* 00000020 //C 0f66f db	32 */
0x0000f670, 0x00000020, /* 00000020 //C 0f670 db	32 */
0x0000f671, 0x00000020, /* 00000020 //C 0f671 db	32 */
0x0000f672, 0x00000020, /* 00000020 //C 0f672 db	32 */
0x0000f673, 0x00000047, /* 00000047 //C 0f673 db	71 */
0x0000f674, 0x00000065, /* 00000065 //C 0f674 db	101 */
0x0000f675, 0x00000074, /* 00000074 //C 0f675 db	116 */
0x0000f676, 0x0000002f, /* 0000002f //C 0f676 db	47 */
0x0000f677, 0x00000073, /* 00000073 //C 0f677 db	115 */
0x0000f678, 0x00000065, /* 00000065 //C 0f678 db	101 */
0x0000f679, 0x00000074, /* 00000074 //C 0f679 db	116 */
0x0000f67a, 0x00000020, /* 00000020 //C 0f67a db	32 */
0x0000f67b, 0x00000066, /* 00000066 //C 0f67b db	102 */
0x0000f67c, 0x0000006c, /* 0000006c //C 0f67c db	108 */
0x0000f67d, 0x00000061, /* 00000061 //C 0f67d db	97 */
0x0000f67e, 0x00000067, /* 00000067 //C 0f67e db	103 */
0x0000f67f, 0x00000073, /* 00000073 //C 0f67f db	115 */
0x0000f680, 0x0000000a, /* 0000000a //C 0f680 db	10 */
0x0000f681, 0x00000000, /* 00000000 //C 0f681 db */
0x0000f682, 0x00000068, /* 00000068 //C 0f682 db	104 */
0x0000f683, 0x0000002c, /* 0000002c //C 0f683 db	44 */
0x0000f684, 0x0000003f, /* 0000003f //C 0f684 db	63 */
0x0000f685, 0x00000020, /* 00000020 //C 0f685 db	32 */
0x0000f686, 0x00000020, /* 00000020 //C 0f686 db	32 */
0x0000f687, 0x00000020, /* 00000020 //C 0f687 db	32 */
0x0000f688, 0x00000020, /* 00000020 //C 0f688 db	32 */
0x0000f689, 0x00000020, /* 00000020 //C 0f689 db	32 */
0x0000f68a, 0x00000020, /* 00000020 //C 0f68a db	32 */
0x0000f68b, 0x00000020, /* 00000020 //C 0f68b db	32 */
0x0000f68c, 0x00000020, /* 00000020 //C 0f68c db	32 */
0x0000f68d, 0x00000020, /* 00000020 //C 0f68d db	32 */
0x0000f68e, 0x00000020, /* 00000020 //C 0f68e db	32 */
0x0000f68f, 0x00000020, /* 00000020 //C 0f68f db	32 */
0x0000f690, 0x00000020, /* 00000020 //C 0f690 db	32 */
0x0000f691, 0x00000020, /* 00000020 //C 0f691 db	32 */
0x0000f692, 0x00000020, /* 00000020 //C 0f692 db	32 */
0x0000f693, 0x00000020, /* 00000020 //C 0f693 db	32 */
0x0000f694, 0x00000048, /* 00000048 //C 0f694 db	72 */
0x0000f695, 0x00000065, /* 00000065 //C 0f695 db	101 */
0x0000f696, 0x0000006c, /* 0000006c //C 0f696 db	108 */
0x0000f697, 0x00000070, /* 00000070 //C 0f697 db	112 */
0x0000f698, 0x0000000a, /* 0000000a //C 0f698 db	10 */
0x0000f699, 0x00000000, /* 00000000 //C 0f699 db */
0x0000f69a, 0x00000000, /* 00000000 //C 0f69a dd	0 */
0x0000f6dc, 0x00000045, /* 00000045 //C 0f6dc db	69 */
0x0000f6dd, 0x0000004f, /* 0000004f //C 0f6dd db	79 */
0x0000f6de, 0x00000046, /* 00000046 //C 0f6de db	70 */
0x0000f6df, 0x00000020, /* 00000020 //C 0f6df db	32 */
0x0000f6e0, 0x00000050, /* 00000050 //C 0f6e0 db	80 */
0x0000f6e1, 0x0000004d, /* 0000004d //C 0f6e1 db	77 */
0x0000f6e2, 0x0000006f, /* 0000006f //C 0f6e2 db	111 */
0x0000f6e3, 0x0000006e, /* 0000006e //C 0f6e3 db	110 */
0x0000f6e4, 0x00000069, /* 00000069 //C 0f6e4 db	105 */
0x0000f6e5, 0x00000074, /* 00000074 //C 0f6e5 db	116 */
0x0000f6e6, 0x0000006f, /* 0000006f //C 0f6e6 db	111 */
0x0000f6e7, 0x00000072, /* 00000072 //C 0f6e7 db	114 */
0x0000f6e8, 0x0000000a, /* 0000000a //C 0f6e8 db	10 */
0x0000f6e9, 0x00000000, /* 00000000 //C 0f6e9 db */
0xffffffff, 0xffffffff
};
