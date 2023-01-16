#include "pmon.h"

t_mem pmon[]= {
0x00000000, 0x01f2f025, /* 01f2f025 //C 00000 jmp	cold_start */
0x0000f000, 0x01f2f00e, /* 01f2f00e //C 0f000 _f000:	jmp	callin */
0x0000f001, 0x01f2f025, /* 01f2f025 //C 0f001 _f001:	jmp	cold_start */
0x0000f002, 0x01f2f300, /* 01f2f300 //C 0f002 _f002:	jmp	strchr */
0x0000f003, 0x01f2f33b, /* 01f2f33b //C 0f003 _f003:	jmp	streq */
0x0000f004, 0x01f2f342, /* 01f2f342 //C 0f004 _f004:	jmp	strieq */
0x0000f005, 0x01f2f349, /* 01f2f349 //C 0f005 _f005:	jmp	hexchar2value */
0x0000f006, 0x01f2f378, /* 01f2f378 //C 0f006 _f006:	jmp	value2hexchar */
0x0000f007, 0x01f2f37d, /* 01f2f37d //C 0f007 _f007:	jmp	htoi */
0x0000f008, 0x01f2f39f, /* 01f2f39f //C 0f008 _f008:	jmp	check_uart */
0x0000f009, 0x01f2f3a6, /* 01f2f3a6 //C 0f009 _f009:	jmp	read */
0x0000f00a, 0x01f2f3a8, /* 01f2f3a8 //C 0f00a _f00a:	jmp	putchar */
0x0000f00b, 0x01f2f3b2, /* 01f2f3b2 //C 0f00b _f00b:	jmp	prints */
0x0000f00c, 0x01f2f3c6, /* 01f2f3c6 //C 0f00c _f00c:	jmp	printsnl */
0x0000f00d, 0x01f2f3ce, /* 01f2f3ce //C 0f00d _f00d:	jmp	print_vhex */
0x0000f00e, 0x0600f463, /* 0600f463 //C 0f00e st	r0,reg0 */
0x0000f00f, 0x0610f464, /* 0610f464 //C 0f00f st	r1,reg1 */
0x0000f010, 0x0620f465, /* 0620f465 //C 0f010 st	r2,reg2 */
0x0000f011, 0x0630f466, /* 0630f466 //C 0f011 st	r3,reg3 */
0x0000f012, 0x0640f467, /* 0640f467 //C 0f012 st	r4,reg4 */
0x0000f013, 0x0650f468, /* 0650f468 //C 0f013 st	r5,reg5 */
0x0000f014, 0x0660f469, /* 0660f469 //C 0f014 st	r6,reg6 */
0x0000f015, 0x0670f46a, /* 0670f46a //C 0f015 st	r7,reg7 */
0x0000f016, 0x0680f46b, /* 0680f46b //C 0f016 st	r8,reg8 */
0x0000f017, 0x0690f46c, /* 0690f46c //C 0f017 st	r9,reg9 */
0x0000f018, 0x06a0f46d, /* 06a0f46d //C 0f018 st	r10,reg10 */
0x0000f019, 0x06b0f46e, /* 06b0f46e //C 0f019 st	r11,reg11 */
0x0000f01a, 0x06c0f46f, /* 06c0f46f //C 0f01a st	r12,reg12 */
0x0000f01b, 0x06d0f470, /* 06d0f470 //C 0f01b st	r13,reg13 */
0x0000f01c, 0x06e0f471, /* 06e0f471 //C 0f01c st	r14,reg14 */
0x0000f01d, 0x06e0f472, /* 06e0f472 //C 0f01d st	r14,reg15 */
0x0000f01e, 0x020e0000, /* 020e0000 //C 0f01e getf	r0 */
0x0000f01f, 0x0600f473, /* 0600f473 //C 0f01f st	r0,regf */
0x0000f020, 0x01020001, /* 01020001 //C 0f020 mvzl	r0,1 */
0x0000f021, 0x0600f461, /* 0600f461 //C 0f021 st	r0,called */
0x0000f022, 0x01f2f02f, /* 01f2f02f //C 0f022 jmp	common_start */
0x0000f023, 0x01f2f02f, /* 01f2f02f //C 0f023 jmp	common_start */
0x0000f024, 0x01f2f025, /* 01f2f025 //C 0f024 jmp	cold_start */
0x0000f025, 0x01020000, /* 01020000 //C 0f025 mvzl	r0,0 */
0x0000f026, 0x0600f461, /* 0600f461 //C 0f026 st	r0,called */
0x0000f027, 0x0102f024, /* 0102f024 //C 0f027 mvzl	r0,def_zero	; restore jmp to monitor at zero */
0x0000f028, 0x0e000000, /* 0e000000 //C 0f028 ld	r0,r0 */
0x0000f029, 0x06000000, /* 06000000 //C 0f029 st	r0,0 */
0x0000f02a, 0x01020000, /* 01020000 //C 0f02a mvzl	r0,0		; def values of some regs */
0x0000f02b, 0x0600f473, /* 0600f473 //C 0f02b st	r0,regf		; FALGS= 0 */
0x0000f02c, 0x0102f7ff, /* 0102f7ff //C 0f02c mvzl	r0,0xf7ff	; R13= 0xf7ff */
0x0000f02d, 0x0600f470, /* 0600f470 //C 0f02d st	r0,reg13 */
0x0000f02e, 0x01f2f02f, /* 01f2f02f //C 0f02e jmp	common_start: */
0x0000f02f, 0x01d2f695, /* 01d2f695 //C 0f02f mvzl	sp,stack_end */
0x0000f030, 0x01020001, /* 01020001 //C 0f030 mvzl	r0,1 */
0x0000f031, 0x0600f460, /* 0600f460 //C 0f031 st	r0,echo */
0x0000f032, 0x01020000, /* 01020000 //C 0f032 mvzl	r0,0 */
0x0000f033, 0x020f0000, /* 020f0000 //C 0f033 setf	r0 */
0x0000f034, 0x011200d9, /* 011200d9 //C 0f034 mvzl	r1,217 */
0x0000f035, 0x0610ff44, /* 0610ff44 //C 0f035 st	r1,UART_CPB */
0x0000f036, 0x01120003, /* 01120003 //C 0f036 mvzl	r1,3 */
0x0000f037, 0x0610ff41, /* 0610ff41 //C 0f037 st	r1,UART_CTRL */
0x0000f038, 0x0102f474, /* 0102f474 //C 0f038 mvzl	r0,msg_start */
0x0000f039, 0x0400f3c6, /* 0400f3c6 //C 0f039 call	printsnl */
0x0000f03a, 0x0400f03c, /* 0400f03c //C 0f03a call	setup_line */
0x0000f03b, 0x01f2f046, /* 01f2f046 //C 0f03b jmp	main */
0x0000f03c, 0x0ded0000, /* 0ded0000 //C 0f03c push	lr */
0x0000f03d, 0x01120000, /* 01120000 //C 0f03d mvzl	r1,0		; lptr= 0 */
0x0000f03e, 0x0610f459, /* 0610f459 //C 0f03e st	r1,line_ptr */
0x0000f03f, 0x0610f3f5, /* 0610f3f5 //C 0f03f st	r1,line		; line[0]= 0 */
0x0000f040, 0x01120000, /* 01120000 //C 0f040 mvzl	r1,0		; at_eol= 0 */
0x0000f041, 0x0610f45a, /* 0610f45a //C 0f041 st	r1,at_eol */
0x0000f042, 0x0102f482, /* 0102f482 //C 0f042 mvzl	r0,prompt */
0x0000f043, 0x0400f3b2, /* 0400f3b2 //C 0f043 call	prints */
0x0000f044, 0x0fed0000, /* 0fed0000 //C 0f044 pop	lr */
0x0000f045, 0x00f00e00, /* 00f00e00 //C 0f045 ret */
0x0000f046, 0x0400f39f, /* 0400f39f //C 0f046 call	check_uart */
0x0000f047, 0x41f2f04d, /* 41f2f04d //C 0f047 C0 jmp	no_input */
0x0000f048, 0x0400f3a6, /* 0400f3a6 //C 0f048 call	read */
0x0000f049, 0x0400f04e, /* 0400f04e //C 0f049 call	proc_input */
0x0000f04a, 0x41f2f04d, /* 41f2f04d //C 0f04a C0 jmp	no_line */
0x0000f04b, 0x0400f06b, /* 0400f06b //C 0f04b call	proc_line */
0x0000f04c, 0x0400f03c, /* 0400f03c //C 0f04c call	setup_line */
0x0000f04d, 0x01f2f046, /* 01f2f046 //C 0f04d jmp	main */
0x0000f04e, 0x0ded0000, /* 0ded0000 //C 0f04e push	lr */
0x0000f04f, 0x0108000a, /* 0108000a //C 0f04f cmp	r0,LF */
0x0000f050, 0x11f2f064, /* 11f2f064 //C 0f050 EQ jmp	got_eol */
0x0000f051, 0x0108000d, /* 0108000d //C 0f051 cmp	r0,CR */
0x0000f052, 0x11f2f064, /* 11f2f064 //C 0f052 EQ jmp	got_eol */
0x0000f053, 0x01220000, /* 01220000 //C 0f053 mvzl	r2,0		; at_aol= 0 */
0x0000f054, 0x0620f45a, /* 0620f45a //C 0f054 st	r2,at_eol */
0x0000f055, 0x0112f459, /* 0112f459 //C 0f055 mvzl	r1,line_ptr	; line[line_ptr]= char */
0x0000f056, 0x0e310000, /* 0e310000 //C 0f056 ld	r3,r1 */
0x0000f057, 0x0122f3f5, /* 0122f3f5 //C 0f057 mvzl	r2,line */
0x0000f058, 0x08020300, /* 08020300 //C 0f058 st	r0,r2,r3 */
0x0000f059, 0x013a0001, /* 013a0001 //C 0f059 plus	r3,1		; line_ptr++ */
0x0000f05a, 0x0c310000, /* 0c310000 //C 0f05a st	r3,r1 */
0x0000f05b, 0x01420000, /* 01420000 //C 0f05b mvzl	r4,0 */
0x0000f05c, 0x09438200, /* 09438200 //C 0f05c st	r4,r3+,r2	; line[line_ptr]= 0 */
0x0000f05d, 0x08430200, /* 08430200 //C 0f05d st	r4,r3,r2	; double 0 at end, needed by tokenizer */
0x0000f05e, 0x0142f460, /* 0142f460 //C 0f05e mvzl	r4,echo		; check if echo is turned on */
0x0000f05f, 0x0e440000, /* 0e440000 //C 0f05f ld	r4,r4 */
0x0000f060, 0x024b0000, /* 024b0000 //C 0f060 sz	r4 */
0x0000f061, 0x2400f3a8, /* 2400f3a8 //C 0f061 NZ call	putchar		; echo */
0x0000f062, 0x020d0000, /* 020d0000 //C 0f062 clc */
0x0000f063, 0x01f2f069, /* 01f2f069 //C 0f063 jmp	proc_input_ret */
0x0000f064, 0x0112f45a, /* 0112f45a //C 0f064 mvzl	r1,at_eol */
0x0000f065, 0x0e110000, /* 0e110000 //C 0f065 ld	r1,r1 */
0x0000f066, 0x021b0000, /* 021b0000 //C 0f066 sz	r1		; Z=0 at eol -> skip, not ready */
0x0000f067, 0x220d0000, /* 220d0000 //C 0f067 Z0 clc */
0x0000f068, 0x120c0000, /* 120c0000 //C 0f068 Z1 sec */
0x0000f069, 0x0fed0000, /* 0fed0000 //C 0f069 pop	lr */
0x0000f06a, 0x00f00e00, /* 00f00e00 //C 0f06a ret */
0x0000f06b, 0x0ded0000, /* 0ded0000 //C 0f06b push	lr */
0x0000f06c, 0x0102000a, /* 0102000a //C 0f06c mvzl	r0,LF */
0x0000f06d, 0x0400f3a8, /* 0400f3a8 //C 0f06d call	putchar */
0x0000f06e, 0x0700f3f5, /* 0700f3f5 //C 0f06e ld	r0,line */
0x0000f06f, 0x020b0000, /* 020b0000 //C 0f06f sz	r0 */
0x0000f070, 0x11f2f078, /* 11f2f078 //C 0f070 jz	proc_line_ret */
0x0000f071, 0x0400f096, /* 0400f096 //C 0f071 call	tokenize */
0x0000f072, 0x0400f0b7, /* 0400f0b7 //C 0f072 call	find_cmd */
0x0000f073, 0x41f2f076, /* 41f2f076 //C 0f073 C0 jmp	cmd_not_found */
0x0000f074, 0x05000000, /* 05000000 //C 0f074 call	r0,0 */
0x0000f075, 0x01f2f078, /* 01f2f078 //C 0f075 jmp	proc_line_ret */
0x0000f076, 0x0102f081, /* 0102f081 //C 0f076 mvzl	r0,snotfound */
0x0000f077, 0x0400f3c6, /* 0400f3c6 //C 0f077 call	printsnl */
0x0000f078, 0x01120001, /* 01120001 //C 0f078 mvzl	r1,1		; at_eol= 1 */
0x0000f079, 0x0610f45a, /* 0610f45a //C 0f079 st	r1,at_eol */
0x0000f07a, 0x0fed0000, /* 0fed0000 //C 0f07a pop	lr */
0x0000f07b, 0x00f00e00, /* 00f00e00 //C 0f07b ret */
0x0000f07c, 0x00000047, /* 00000047 //C 0f07c db	71 */
0x0000f07d, 0x0000006f, /* 0000006f //C 0f07d db	111 */
0x0000f07e, 0x00000074, /* 00000074 //C 0f07e db	116 */
0x0000f07f, 0x0000003a, /* 0000003a //C 0f07f db	58 */
0x0000f080, 0x00000000, /* 00000000 //C 0f080 db */
0x0000f081, 0x00000055, /* 00000055 //C 0f081 db	85 */
0x0000f082, 0x0000006e, /* 0000006e //C 0f082 db	110 */
0x0000f083, 0x0000006b, /* 0000006b //C 0f083 db	107 */
0x0000f084, 0x0000006e, /* 0000006e //C 0f084 db	110 */
0x0000f085, 0x0000006f, /* 0000006f //C 0f085 db	111 */
0x0000f086, 0x00000077, /* 00000077 //C 0f086 db	119 */
0x0000f087, 0x0000006e, /* 0000006e //C 0f087 db	110 */
0x0000f088, 0x00000020, /* 00000020 //C 0f088 db	32 */
0x0000f089, 0x00000063, /* 00000063 //C 0f089 db	99 */
0x0000f08a, 0x0000006f, /* 0000006f //C 0f08a db	111 */
0x0000f08b, 0x0000006d, /* 0000006d //C 0f08b db	109 */
0x0000f08c, 0x0000006d, /* 0000006d //C 0f08c db	109 */
0x0000f08d, 0x00000061, /* 00000061 //C 0f08d db	97 */
0x0000f08e, 0x0000006e, /* 0000006e //C 0f08e db	110 */
0x0000f08f, 0x00000064, /* 00000064 //C 0f08f db	100 */
0x0000f090, 0x00000000, /* 00000000 //C 0f090 db */
0x0000f091, 0x0ded0000, /* 0ded0000 //C 0f091 push	lr */
0x0000f092, 0x0112f484, /* 0112f484 //C 0f092 mvzl	r1,delimiters */
0x0000f093, 0x0400f300, /* 0400f300 //C 0f093 call	strchr */
0x0000f094, 0x0fed0000, /* 0fed0000 //C 0f094 pop	lr */
0x0000f095, 0x00f00e00, /* 00f00e00 //C 0f095 ret */
0x0000f096, 0x0ded0000, /* 0ded0000 //C 0f096 push	lr */
0x0000f097, 0x0142f45b, /* 0142f45b //C 0f097 mvzl	r4,words	; array of result */
0x0000f098, 0x0152f3f5, /* 0152f3f5 //C 0f098 mvzl	r5,line		; address of next char */
0x0000f099, 0x01620000, /* 01620000 //C 0f099 mvzl	r6,0		; nuof words found */
0x0000f09a, 0x01720000, /* 01720000 //C 0f09a mvzl	r7,0		; bool in_word */
0x0000f09b, 0x0e050000, /* 0e050000 //C 0f09b ld	r0,r5		; pick a char */
0x0000f09c, 0x020b0000, /* 020b0000 //C 0f09c sz	r0		; check end */
0x0000f09d, 0x11f2f0a7, /* 11f2f0a7 //C 0f09d jz	tok_delimiter	; found end, pretend delim */
0x0000f09e, 0x0400f091, /* 0400f091 //C 0f09e call	is_delimiter */
0x0000f09f, 0x31f2f0a7, /* 31f2f0a7 //C 0f09f C1 jmp	tok_delimiter */
0x0000f0a0, 0x027b0000, /* 027b0000 //C 0f0a0 sz	r7 */
0x0000f0a1, 0x21f2f0ac, /* 21f2f0ac //C 0f0a1 jnz	tok_next	; still inside word */
0x0000f0a2, 0x01720001, /* 01720001 //C 0f0a2 mvzl	r7,1		; in_word=true */
0x0000f0a3, 0x09568400, /* 09568400 //C 0f0a3 st	r5,r6+,r4	; record word address */
0x0000f0a4, 0x01680005, /* 01680005 //C 0f0a4 cmp	r6,MAX_WORDS	; If no more space */
0x0000f0a5, 0x11f2f0b0, /* 11f2f0b0 //C 0f0a5 EQ jmp	tok_ret		; then return */
0x0000f0a6, 0x01f2f0ac, /* 01f2f0ac //C 0f0a6 jmp	tok_next */
0x0000f0a7, 0x027b0000, /* 027b0000 //C 0f0a7 sz	r7 */
0x0000f0a8, 0x11f2f0ac, /* 11f2f0ac //C 0f0a8 jz	tok_next	; still between words */
0x0000f0a9, 0x01720000, /* 01720000 //C 0f0a9 mvzl	r7,0		; in_word=false */
0x0000f0aa, 0x01120000, /* 01120000 //C 0f0aa mvzl	r1,0		; put a 0 at the end of word */
0x0000f0ab, 0x08150100, /* 08150100 //C 0f0ab st	r1,r5,r1 */
0x0000f0ac, 0x020b0000, /* 020b0000 //C 0f0ac sz	r0		; check EOL */
0x0000f0ad, 0x11f2f0b0, /* 11f2f0b0 //C 0f0ad jz	tok_ret		; jump out if char==0 */
0x0000f0ae, 0x01540001, /* 01540001 //C 0f0ae add	r5,1 */
0x0000f0af, 0x01f2f09b, /* 01f2f09b //C 0f0af jmp	tok_cycle */
0x0000f0b0, 0x01120000, /* 01120000 //C 0f0b0 mvzl	r1,0 */
0x0000f0b1, 0x01680005, /* 01680005 //C 0f0b1 cmp	r6,MAX_WORDS */
0x0000f0b2, 0x11f2f0b5, /* 11f2f0b5 //C 0f0b2 jz	tok_end */
0x0000f0b3, 0x09168400, /* 09168400 //C 0f0b3 st	r1,r6+,r4 */
0x0000f0b4, 0x01f2f0b0, /* 01f2f0b0 //C 0f0b4 jmp	tok_ret */
0x0000f0b5, 0x0fed0000, /* 0fed0000 //C 0f0b5 pop	lr */
0x0000f0b6, 0x00f00e00, /* 00f00e00 //C 0f0b6 ret */
0x0000f0b7, 0x0ded0000, /* 0ded0000 //C 0f0b7 push	lr */
0x0000f0b8, 0x0d1d0000, /* 0d1d0000 //C 0f0b8 push	r1 */
0x0000f0b9, 0x0d2d0000, /* 0d2d0000 //C 0f0b9 push	r2 */
0x0000f0ba, 0x0d3d0000, /* 0d3d0000 //C 0f0ba push	r3 */
0x0000f0bb, 0x0dad0000, /* 0dad0000 //C 0f0bb push	r10 */
0x0000f0bc, 0x0700f45b, /* 0700f45b //C 0f0bc ld	r0,words	; R0= 1st word of command */
0x0000f0bd, 0x020b0000, /* 020b0000 //C 0f0bd sz	r0 */
0x0000f0be, 0x11f2f0ee, /* 11f2f0ee //C 0f0be jz	find_cmd_false */
0x0000f0bf, 0x0e100000, /* 0e100000 //C 0f0bf ld	r1,r0		; 1st char of word1 */
0x0000f0c0, 0x0e200001, /* 0e200001 //C 0f0c0 ld	r2,r0,1		; 2nd char */
0x0000f0c1, 0x0e300002, /* 0e300002 //C 0f0c1 ld	r3,r0,2		; 3rd char */
0x0000f0c2, 0x011fffdf, /* 011fffdf //C 0f0c2 and	r1,0xffdf	; upcase 1st char */
0x0000f0c3, 0x01180052, /* 01180052 //C 0f0c3 cmp	r1,'R' */
0x0000f0c4, 0x21f2f0da, /* 21f2f0da //C 0f0c4 jnz	find_not_rx */
0x0000f0c5, 0x0128002f, /* 0128002f //C 0f0c5 cmp	r2,'/'		; '0'-1 */
0x0000f0c6, 0xa1f2f0da, /* a1f2f0da //C 0f0c6 LS jmp	find_not_rx */
0x0000f0c7, 0x01280039, /* 01280039 //C 0f0c7 cmp	r2,'9' */
0x0000f0c8, 0x91f2f0da, /* 91f2f0da //C 0f0c8 HI jmp	find_not_rx */
0x0000f0c9, 0x023b0000, /* 023b0000 //C 0f0c9 sz	r3 */
0x0000f0ca, 0x11f2f0d5, /* 11f2f0d5 //C 0f0ca jz	find_rx_09 */
0x0000f0cb, 0x01280031, /* 01280031 //C 0f0cb cmp	r2,'1'		; first char must be '1' */
0x0000f0cc, 0x21f2f0da, /* 21f2f0da //C 0f0cc jnz	find_not_rx */
0x0000f0cd, 0x0138002f, /* 0138002f //C 0f0cd cmp	r3,'/'		; '0'-1 */
0x0000f0ce, 0xa1f2f0da, /* a1f2f0da //C 0f0ce LS jmp	find_not_rx */
0x0000f0cf, 0x01380035, /* 01380035 //C 0f0cf cmp	r3,'5' */
0x0000f0d0, 0x91f2f0da, /* 91f2f0da //C 0f0d0 HI jmp	find_not_rx */
0x0000f0d1, 0x01360030, /* 01360030 //C 0f0d1 sub	r3,'0' */
0x0000f0d2, 0x0134000a, /* 0134000a //C 0f0d2 add	r3,10 */
0x0000f0d3, 0x0630f462, /* 0630f462 //C 0f0d3 st	r3,nuof_reg */
0x0000f0d4, 0x01f2f0d7, /* 01f2f0d7 //C 0f0d4 jmp	find_rx */
0x0000f0d5, 0x01260030, /* 01260030 //C 0f0d5 sub	r2,'0' */
0x0000f0d6, 0x0620f462, /* 0620f462 //C 0f0d6 st	r2,nuof_reg */
0x0000f0d7, 0x0102f2be, /* 0102f2be //C 0f0d7 mvzl	r0,cmd_rx */
0x0000f0d8, 0x020c0000, /* 020c0000 //C 0f0d8 sec */
0x0000f0d9, 0x01f2f0f9, /* 01f2f0f9 //C 0f0d9 jmp	find_cmd_ret */
0x0000f0da, 0x01a2f494, /* 01a2f494 //C 0f0da mvzl	r10,commands */
0x0000f0db, 0x0e2a0000, /* 0e2a0000 //C 0f0db ld	r2,r10		; R2= cmd addr */
0x0000f0dc, 0x022b0000, /* 022b0000 //C 0f0dc sz	r2 */
0x0000f0dd, 0x11f2f0ee, /* 11f2f0ee //C 0f0dd jz	find_cmd_false */
0x0000f0de, 0x01a40001, /* 01a40001 //C 0f0de add	r10,1 */
0x0000f0df, 0x00100a00, /* 00100a00 //C 0f0df mov	r1,r10		; R1= cmd string */
0x0000f0e0, 0x01a40001, /* 01a40001 //C 0f0e0 add	r10,1 */
0x0000f0e1, 0x0e3a0000, /* 0e3a0000 //C 0f0e1 ld	r3,r10 */
0x0000f0e2, 0x023b0000, /* 023b0000 //C 0f0e2 sz	r3 */
0x0000f0e3, 0x21f2f0e0, /* 21f2f0e0 //C 0f0e3 jnz	find_cmd_fw */
0x0000f0e4, 0x01a40001, /* 01a40001 //C 0f0e4 add	r10,1 */
0x0000f0e5, 0x0400f33b, /* 0400f33b //C 0f0e5 call	streq */
0x0000f0e6, 0x41f2f0db, /* 41f2f0db //C 0f0e6 C0 jmp	find_cmd_cyc */
0x0000f0e7, 0x00000200, /* 00000200 //C 0f0e7 mov	r0,r2 */
0x0000f0e8, 0x020c0000, /* 020c0000 //C 0f0e8 sec */
0x0000f0e9, 0x01f2f0f9, /* 01f2f0f9 //C 0f0e9 jmp	find_cmd_ret */
0x0000f0ea, 0x0000002f, /* 0000002f //C 0f0ea db	47 */
0x0000f0eb, 0x0000002f, /* 0000002f //C 0f0eb db	47 */
0x0000f0ec, 0x00000043, /* 00000043 //C 0f0ec db	67 */
0x0000f0ed, 0x00000000, /* 00000000 //C 0f0ed db */
0x0000f0ee, 0x01040001, /* 01040001 //C 0f0ee add	r0,1		; check second word */
0x0000f0ef, 0x0e100000, /* 0e100000 //C 0f0ef ld	r1,r0		; for //C command */
0x0000f0f0, 0x021b0000, /* 021b0000 //C 0f0f0 sz	r1 */
0x0000f0f1, 0x11f2f0f7, /* 11f2f0f7 //C 0f0f1 jz	find_cmd_very_false */
0x0000f0f2, 0x0102f0ea, /* 0102f0ea //C 0f0f2 mvzl	r0,c_cmd_name */
0x0000f0f3, 0x0400f33b, /* 0400f33b //C 0f0f3 call	streq */
0x0000f0f4, 0x21f2f0f7, /* 21f2f0f7 //C 0f0f4 jnz	find_cmd_very_false */
0x0000f0f5, 0x0122f187, /* 0122f187 //C 0f0f5 mvzl	r2,cmd_c */
0x0000f0f6, 0x01f2f0e7, /* 01f2f0e7 //C 0f0f6 jmp	find_cmd_true */
0x0000f0f7, 0x020d0000, /* 020d0000 //C 0f0f7 clc */
0x0000f0f8, 0x01020000, /* 01020000 //C 0f0f8 mvzl	r0,0 */
0x0000f0f9, 0x0fad0000, /* 0fad0000 //C 0f0f9 pop	r10 */
0x0000f0fa, 0x0f3d0000, /* 0f3d0000 //C 0f0fa pop	r3 */
0x0000f0fb, 0x0f2d0000, /* 0f2d0000 //C 0f0fb pop	r2 */
0x0000f0fc, 0x0f1d0000, /* 0f1d0000 //C 0f0fc pop	r1 */
0x0000f0fd, 0x0fed0000, /* 0fed0000 //C 0f0fd pop	lr */
0x0000f0fe, 0x00f00e00, /* 00f00e00 //C 0f0fe ret */
0x0000f0ff, 0x0ded0000, /* 0ded0000 //C 0f0ff push	lr */
0x0000f100, 0x0122f45b, /* 0122f45b //C 0f100 mvzl	r2,words */
0x0000f101, 0x01020000, /* 01020000 //C 0f101 mvzl	r0,0 */
0x0000f102, 0x0e420001, /* 0e420001 //C 0f102 ld	r4,r2,1		; addr */
0x0000f103, 0x0e520002, /* 0e520002 //C 0f103 ld	r5,r2,2		; value */
0x0000f104, 0x024b0000, /* 024b0000 //C 0f104 sz 	r4 */
0x0000f105, 0x11f2f126, /* 11f2f126 //C 0f105 jz	m_ret */
0x0000f106, 0x00000400, /* 00000400 //C 0f106 mov	r0,r4 */
0x0000f107, 0x0400f37d, /* 0400f37d //C 0f107 call	htoi */
0x0000f108, 0x00400100, /* 00400100 //C 0f108 mov	r4,r1 */
0x0000f109, 0x31f2f10d, /* 31f2f10d //C 0f109 C1 jmp	m_addr_ok */
0x0000f10a, 0x0102f128, /* 0102f128 //C 0f10a mvzl	r0,m_err_addr */
0x0000f10b, 0x0400f3c6, /* 0400f3c6 //C 0f10b call	printsnl */
0x0000f10c, 0x01f2f126, /* 01f2f126 //C 0f10c jmp	m_ret */
0x0000f10d, 0x025b0000, /* 025b0000 //C 0f10d sz	r5 */
0x0000f10e, 0x11f2f11c, /* 11f2f11c //C 0f10e jz	m_read */
0x0000f10f, 0x0148f6a4, /* 0148f6a4 //C 0f10f cmp	r4,the_end */
0x0000f110, 0x91f2f114, /* 91f2f114 //C 0f110 HI jmp	m_addrv_ok */
0x0000f111, 0x0102f136, /* 0102f136 //C 0f111 mvzl	r0,m_err_addrv */
0x0000f112, 0x0400f3c6, /* 0400f3c6 //C 0f112 call	printsnl */
0x0000f113, 0x01f2f126, /* 01f2f126 //C 0f113 jmp	m_ret */
0x0000f114, 0x00000500, /* 00000500 //C 0f114 mov	r0,r5 */
0x0000f115, 0x0400f37d, /* 0400f37d //C 0f115 call	htoi */
0x0000f116, 0x00500100, /* 00500100 //C 0f116 mov	r5,r1 */
0x0000f117, 0x31f2f11b, /* 31f2f11b //C 0f117 C1 jmp	m_value_ok */
0x0000f118, 0x0102f148, /* 0102f148 //C 0f118 mvzl	r0,m_err_value */
0x0000f119, 0x0400f3c6, /* 0400f3c6 //C 0f119 call	printsnl */
0x0000f11a, 0x01f2f126, /* 01f2f126 //C 0f11a jmp	m_ret */
0x0000f11b, 0x0c540000, /* 0c540000 //C 0f11b st	r5,r4 */
0x0000f11c, 0x00000400, /* 00000400 //C 0f11c mov	r0,r4 */
0x0000f11d, 0x01120004, /* 01120004 //C 0f11d mvzl	r1,4 */
0x0000f11e, 0x0400f3ce, /* 0400f3ce //C 0f11e call	print_vhex */
0x0000f11f, 0x01020020, /* 01020020 //C 0f11f mvzl	r0,0x20 */
0x0000f120, 0x0400f3a8, /* 0400f3a8 //C 0f120 call	putchar */
0x0000f121, 0x0e040000, /* 0e040000 //C 0f121 ld	r0,r4 */
0x0000f122, 0x01120004, /* 01120004 //C 0f122 mvzl	r1,4 */
0x0000f123, 0x0400f3ce, /* 0400f3ce //C 0f123 call	print_vhex */
0x0000f124, 0x0102000a, /* 0102000a //C 0f124 mvzl	r0,LF */
0x0000f125, 0x0400f3a8, /* 0400f3a8 //C 0f125 call	putchar */
0x0000f126, 0x0fed0000, /* 0fed0000 //C 0f126 pop	lr */
0x0000f127, 0x00f00e00, /* 00f00e00 //C 0f127 ret */
0x0000f128, 0x00000041, /* 00000041 //C 0f128 db	65 */
0x0000f129, 0x00000064, /* 00000064 //C 0f129 db	100 */
0x0000f12a, 0x00000064, /* 00000064 //C 0f12a db	100 */
0x0000f12b, 0x00000072, /* 00000072 //C 0f12b db	114 */
0x0000f12c, 0x00000065, /* 00000065 //C 0f12c db	101 */
0x0000f12d, 0x00000073, /* 00000073 //C 0f12d db	115 */
0x0000f12e, 0x00000073, /* 00000073 //C 0f12e db	115 */
0x0000f12f, 0x00000020, /* 00000020 //C 0f12f db	32 */
0x0000f130, 0x00000065, /* 00000065 //C 0f130 db	101 */
0x0000f131, 0x00000072, /* 00000072 //C 0f131 db	114 */
0x0000f132, 0x00000072, /* 00000072 //C 0f132 db	114 */
0x0000f133, 0x0000006f, /* 0000006f //C 0f133 db	111 */
0x0000f134, 0x00000072, /* 00000072 //C 0f134 db	114 */
0x0000f135, 0x00000000, /* 00000000 //C 0f135 db */
0x0000f136, 0x0000004d, /* 0000004d //C 0f136 db	77 */
0x0000f137, 0x0000006f, /* 0000006f //C 0f137 db	111 */
0x0000f138, 0x0000006e, /* 0000006e //C 0f138 db	110 */
0x0000f139, 0x00000069, /* 00000069 //C 0f139 db	105 */
0x0000f13a, 0x00000074, /* 00000074 //C 0f13a db	116 */
0x0000f13b, 0x0000006f, /* 0000006f //C 0f13b db	111 */
0x0000f13c, 0x00000072, /* 00000072 //C 0f13c db	114 */
0x0000f13d, 0x00000027, /* 00000027 //C 0f13d db	39 */
0x0000f13e, 0x00000073, /* 00000073 //C 0f13e db	115 */
0x0000f13f, 0x00000020, /* 00000020 //C 0f13f db	32 */
0x0000f140, 0x00000061, /* 00000061 //C 0f140 db	97 */
0x0000f141, 0x00000064, /* 00000064 //C 0f141 db	100 */
0x0000f142, 0x00000064, /* 00000064 //C 0f142 db	100 */
0x0000f143, 0x00000072, /* 00000072 //C 0f143 db	114 */
0x0000f144, 0x00000065, /* 00000065 //C 0f144 db	101 */
0x0000f145, 0x00000073, /* 00000073 //C 0f145 db	115 */
0x0000f146, 0x00000073, /* 00000073 //C 0f146 db	115 */
0x0000f147, 0x00000000, /* 00000000 //C 0f147 db */
0x0000f148, 0x00000056, /* 00000056 //C 0f148 db	86 */
0x0000f149, 0x00000061, /* 00000061 //C 0f149 db	97 */
0x0000f14a, 0x0000006c, /* 0000006c //C 0f14a db	108 */
0x0000f14b, 0x00000075, /* 00000075 //C 0f14b db	117 */
0x0000f14c, 0x00000065, /* 00000065 //C 0f14c db	101 */
0x0000f14d, 0x00000020, /* 00000020 //C 0f14d db	32 */
0x0000f14e, 0x00000065, /* 00000065 //C 0f14e db	101 */
0x0000f14f, 0x00000072, /* 00000072 //C 0f14f db	114 */
0x0000f150, 0x00000072, /* 00000072 //C 0f150 db	114 */
0x0000f151, 0x0000006f, /* 0000006f //C 0f151 db	111 */
0x0000f152, 0x00000072, /* 00000072 //C 0f152 db	114 */
0x0000f153, 0x00000000, /* 00000000 //C 0f153 db */
0x0000f154, 0x0ded0000, /* 0ded0000 //C 0f154 push	lr */
0x0000f155, 0x0122f45b, /* 0122f45b //C 0f155 mvzl	r2,words */
0x0000f156, 0x0e020001, /* 0e020001 //C 0f156 ld	r0,r2,1		; start address */
0x0000f157, 0x0400f37d, /* 0400f37d //C 0f157 call	htoi */
0x0000f158, 0x00300100, /* 00300100 //C 0f158 mov	r3,r1 */
0x0000f159, 0x0e020002, /* 0e020002 //C 0f159 ld	r0,r2,2		; end address */
0x0000f15a, 0x020b0000, /* 020b0000 //C 0f15a sz	r0 */
0x0000f15b, 0x21f2f15f, /* 21f2f15f //C 0f15b jnz	d_end_ok */
0x0000f15c, 0x00400300, /* 00400300 //C 0f15c mov	r4,r3 */
0x0000f15d, 0x01440010, /* 01440010 //C 0f15d add	r4,0x10 */
0x0000f15e, 0x01f2f161, /* 01f2f161 //C 0f15e jmp	d_chk_end */
0x0000f15f, 0x0400f37d, /* 0400f37d //C 0f15f call	htoi */
0x0000f160, 0x00400100, /* 00400100 //C 0f160 mov	r4,r1 */
0x0000f161, 0x00380400, /* 00380400 //C 0f161 cmp	r3,r4		; check if start>end */
0x0000f162, 0x91f2f171, /* 91f2f171 //C 0f162 HI jmp d_bad */
0x0000f163, 0x00000300, /* 00000300 //C 0f163 mov	r0,r3		; print address */
0x0000f164, 0x01120004, /* 01120004 //C 0f164 mvzl	r1,4 */
0x0000f165, 0x0400f3ce, /* 0400f3ce //C 0f165 call	print_vhex */
0x0000f166, 0x01020020, /* 01020020 //C 0f166 mvzl	r0,0x20		; print one space */
0x0000f167, 0x0400f3a8, /* 0400f3a8 //C 0f167 call	putchar */
0x0000f168, 0x0e030000, /* 0e030000 //C 0f168 ld	r0,r3		; load data */
0x0000f169, 0x01120004, /* 01120004 //C 0f169 mvzl	r1,4		; print data */
0x0000f16a, 0x0400f3ce, /* 0400f3ce //C 0f16a call	print_vhex */
0x0000f16b, 0x0102000a, /* 0102000a //C 0f16b mvzl	r0,LF		; print new line */
0x0000f16c, 0x0400f3a8, /* 0400f3a8 //C 0f16c call	putchar */
0x0000f16d, 0x00380400, /* 00380400 //C 0f16d cmp	r3,r4 */
0x0000f16e, 0x11f2f173, /* 11f2f173 //C 0f16e jz	d_ret */
0x0000f16f, 0x01340001, /* 01340001 //C 0f16f add	r3,1 */
0x0000f170, 0x01f2f163, /* 01f2f163 //C 0f170 jmp	d_cyc */
0x0000f171, 0x0102f175, /* 0102f175 //C 0f171 mvzl	r0,d_err_bad */
0x0000f172, 0x0400f3c6, /* 0400f3c6 //C 0f172 call	printsnl */
0x0000f173, 0x0fed0000, /* 0fed0000 //C 0f173 pop	lr */
0x0000f174, 0x00f00e00, /* 00f00e00 //C 0f174 ret */
0x0000f175, 0x00000057, /* 00000057 //C 0f175 db	87 */
0x0000f176, 0x00000072, /* 00000072 //C 0f176 db	114 */
0x0000f177, 0x0000006f, /* 0000006f //C 0f177 db	111 */
0x0000f178, 0x0000006e, /* 0000006e //C 0f178 db	110 */
0x0000f179, 0x00000067, /* 00000067 //C 0f179 db	103 */
0x0000f17a, 0x00000020, /* 00000020 //C 0f17a db	32 */
0x0000f17b, 0x00000065, /* 00000065 //C 0f17b db	101 */
0x0000f17c, 0x0000006e, /* 0000006e //C 0f17c db	110 */
0x0000f17d, 0x00000064, /* 00000064 //C 0f17d db	100 */
0x0000f17e, 0x00000020, /* 00000020 //C 0f17e db	32 */
0x0000f17f, 0x00000061, /* 00000061 //C 0f17f db	97 */
0x0000f180, 0x00000064, /* 00000064 //C 0f180 db	100 */
0x0000f181, 0x00000064, /* 00000064 //C 0f181 db	100 */
0x0000f182, 0x00000072, /* 00000072 //C 0f182 db	114 */
0x0000f183, 0x00000065, /* 00000065 //C 0f183 db	101 */
0x0000f184, 0x00000073, /* 00000073 //C 0f184 db	115 */
0x0000f185, 0x00000073, /* 00000073 //C 0f185 db	115 */
0x0000f186, 0x00000000, /* 00000000 //C 0f186 db */
0x0000f187, 0x00f00e00, /* 00f00e00 //C 0f187 ret */
0x0000f188, 0x0ded0000, /* 0ded0000 //C 0f188 push	lr */
0x0000f189, 0x01a20000, /* 01a20000 //C 0f189 mvzl	r10,0		; state (nr of words) */
0x0000f18a, 0x01820000, /* 01820000 //C 0f18a mvzl	r8,0		; value */
0x0000f18b, 0x0162003f, /* 0162003f //C 0f18b mvzl	r6,'?'		; Record type */
0x0000f18c, 0x0400f39f, /* 0400f39f //C 0f18c call	check_uart */
0x0000f18d, 0x41f2f18c, /* 41f2f18c //C 0f18d C0 jmp	l_cyc */
0x0000f18e, 0x0400f3a6, /* 0400f3a6 //C 0f18e call	read */
0x0000f18f, 0x00b00000, /* 00b00000 //C 0f18f mov	r11,r0		; Copy of char in R11 */
0x0000f190, 0x0108000a, /* 0108000a //C 0f190 cmp	r0,10		; check EOL chars */
0x0000f191, 0x11f2f1db, /* 11f2f1db //C 0f191 jz	l_eol */
0x0000f192, 0x0108000d, /* 0108000d //C 0f192 cmp	r0,13 */
0x0000f193, 0x11f2f1db, /* 11f2f1db //C 0f193 jz	l_eol */
0x0000f194, 0x01a80000, /* 01a80000 //C 0f194 cmp	r10,0 */
0x0000f195, 0x21f2f1a5, /* 21f2f1a5 //C 0f195 jnz	l_no0 */
0x0000f196, 0x0400f349, /* 0400f349 //C 0f196 call	hexchar2value */
0x0000f197, 0x41f2f19f, /* 41f2f19f //C 0f197 C0 jmp	l_eof_0 */
0x0000f198, 0x02880000, /* 02880000 //C 0f198 shl	r8		; shift val(char) into value */
0x0000f199, 0x02880000, /* 02880000 //C 0f199 shl	r8 */
0x0000f19a, 0x02880000, /* 02880000 //C 0f19a shl	r8 */
0x0000f19b, 0x02880000, /* 02880000 //C 0f19b shl	r8 */
0x0000f19c, 0x010b000f, /* 010b000f //C 0f19c btst	r0,0xf */
0x0000f19d, 0x008d0000, /* 008d0000 //C 0f19d or	r8,r0 */
0x0000f19e, 0x01f2f18c, /* 01f2f18c //C 0f19e jmp	l_cyc */
0x0000f19f, 0x01a20001, /* 01a20001 //C 0f19f mvzl	r10,1		; state0 -> state1 */
0x0000f1a0, 0x0162003f, /* 0162003f //C 0f1a0 mvzl	r6,'?'		; No //C yet */
0x0000f1a1, 0x01b8002f, /* 01b8002f //C 0f1a1 cmp	r11,'/'		; is it start of // */
0x0000f1a2, 0x11720001, /* 11720001 //C 0f1a2 z1 mvzl	r7,1		; Yes, first / found */
0x0000f1a3, 0x21720000, /* 21720000 //C 0f1a3 z0 mvzl	r7,0		; No '/' yet */
0x0000f1a4, 0x01f2f18c, /* 01f2f18c //C 0f1a4 jmp	l_cyc */
0x0000f1a5, 0x01a80001, /* 01a80001 //C 0f1a5 cmp	r10,1 */
0x0000f1a6, 0x21f2f1be, /* 21f2f1be //C 0f1a6 jnz	l_no1 */
0x0000f1a7, 0x027b0000, /* 027b0000 //C 0f1a7 sz	r7 */
0x0000f1a8, 0x21f2f1ad, /* 21f2f1ad //C 0f1a8 jnz	l_s1_2nd */
0x0000f1a9, 0x0108002f, /* 0108002f //C 0f1a9 cmp	r0,'/' */
0x0000f1aa, 0x21f2f18c, /* 21f2f18c //C 0f1aa jnz	l_cyc */
0x0000f1ab, 0x01720001, /* 01720001 //C 0f1ab mvzl	r7,1 */
0x0000f1ac, 0x01f2f18c, /* 01f2f18c //C 0f1ac jmp	l_cyc */
0x0000f1ad, 0x0108002f, /* 0108002f //C 0f1ad cmp	r0,'/' */
0x0000f1ae, 0x11f2f18c, /* 11f2f18c //C 0f1ae jz	l_cyc */
0x0000f1af, 0x01080043, /* 01080043 //C 0f1af cmp	r0,'C' */
0x0000f1b0, 0x21f2f1b6, /* 21f2f1b6 //C 0f1b0 jnz	l_s1_noC */
0x0000f1b1, 0x01620043, /* 01620043 //C 0f1b1 mvzl	r6,'C' */
0x0000f1b2, 0x01a20002, /* 01a20002 //C 0f1b2 mvzl	r10,2 */
0x0000f1b3, 0x01920000, /* 01920000 //C 0f1b3 mvzl	r9,0		; address= 0 */
0x0000f1b4, 0x01520000, /* 01520000 //C 0f1b4 mvzl	r5,0		; where we are in word: before */
0x0000f1b5, 0x01f2f18c, /* 01f2f18c //C 0f1b5 jmp	l_cyc */
0x0000f1b6, 0x01080045, /* 01080045 //C 0f1b6 cmp	r0,'E' */
0x0000f1b7, 0x21f2f1bb, /* 21f2f1bb //C 0f1b7 jnz	l_s1_noE */
0x0000f1b8, 0x01620045, /* 01620045 //C 0f1b8 mvzl	r6,'E' */
0x0000f1b9, 0x01a20003, /* 01a20003 //C 0f1b9 mvzl	r10,3 */
0x0000f1ba, 0x01f2f18c, /* 01f2f18c //C 0f1ba jmp	l_cyc */
0x0000f1bb, 0x0400f3a8, /* 0400f3a8 //C 0f1bb call	putchar		; print record type */
0x0000f1bc, 0x01a2000f, /* 01a2000f //C 0f1bc mvzl	r10,0xf		; special state: skip everything */
0x0000f1bd, 0x01f2f18c, /* 01f2f18c //C 0f1bd jmp	l_cyc */
0x0000f1be, 0x01a80002, /* 01a80002 //C 0f1be cmp	r10,2 */
0x0000f1bf, 0x21f2f1d3, /* 21f2f1d3 //C 0f1bf jnz	l_no2 */
0x0000f1c0, 0x01580000, /* 01580000 //C 0f1c0 cmp	r5,0 */
0x0000f1c1, 0x21f2f1cc, /* 21f2f1cc //C 0f1c1 jnz	l_s2_no0 */
0x0000f1c2, 0x0400f349, /* 0400f349 //C 0f1c2 call	hexchar2value */
0x0000f1c3, 0x41f2f18c, /* 41f2f18c //C 0f1c3 C0 jmp	l_cyc */
0x0000f1c4, 0x01520001, /* 01520001 //C 0f1c4 mvzl	r5,1 */
0x0000f1c5, 0x02980000, /* 02980000 //C 0f1c5 shl	r9 */
0x0000f1c6, 0x02980000, /* 02980000 //C 0f1c6 shl	r9 */
0x0000f1c7, 0x02980000, /* 02980000 //C 0f1c7 shl	r9 */
0x0000f1c8, 0x02980000, /* 02980000 //C 0f1c8 shl	r9 */
0x0000f1c9, 0x010b000f, /* 010b000f //C 0f1c9 btst	r0,0xf */
0x0000f1ca, 0x009d0000, /* 009d0000 //C 0f1ca or	r9,r0 */
0x0000f1cb, 0x01f2f18c, /* 01f2f18c //C 0f1cb jmp	l_cyc */
0x0000f1cc, 0x01580001, /* 01580001 //C 0f1cc cmp	r5,1 */
0x0000f1cd, 0x21f2f1d2, /* 21f2f1d2 //C 0f1cd jnz	l_s2_no1 */
0x0000f1ce, 0x0400f349, /* 0400f349 //C 0f1ce call	hexchar2value */
0x0000f1cf, 0x31f2f1c5, /* 31f2f1c5 //C 0f1cf C1 jmp	l_s2_got */
0x0000f1d0, 0x01520002, /* 01520002 //C 0f1d0 mvzl	r5,2 */
0x0000f1d1, 0x01f2f18c, /* 01f2f18c //C 0f1d1 jmp	l_cyc */
0x0000f1d2, 0x01f2f18c, /* 01f2f18c //C 0f1d2 jmp	l_cyc */
0x0000f1d3, 0x01a80003, /* 01a80003 //C 0f1d3 cmp	r10,3 */
0x0000f1d4, 0x21f2f1d6, /* 21f2f1d6 //C 0f1d4 jnz	l_no3 */
0x0000f1d5, 0x01f2f18c, /* 01f2f18c //C 0f1d5 jmp	l_cyc		; do nothing, just wait EOL */
0x0000f1d6, 0x01a8000f, /* 01a8000f //C 0f1d6 cmp	r10,0xf */
0x0000f1d7, 0x01f2f1d9, /* 01f2f1d9 //C 0f1d7 jmp	l_nof */
0x0000f1d8, 0x01f2f18c, /* 01f2f18c //C 0f1d8 jmp	l_cyc		; just skip */
0x0000f1d9, 0x01f2f18c, /* 01f2f18c //C 0f1d9 jmp	l_cyc */
0x0000f1da, 0x01f2f1f1, /* 01f2f1f1 //C 0f1da jmp	l_ret */
0x0000f1db, 0x01a80000, /* 01a80000 //C 0f1db cmp	r10,0		; in state0 */
0x0000f1dc, 0x11f2f1eb, /* 11f2f1eb //C 0f1dc jz	l_back_to_0	; just restart */
0x0000f1dd, 0x01a80001, /* 01a80001 //C 0f1dd cmp	r10,1		; in state1 */
0x0000f1de, 0x11f2f1eb, /* 11f2f1eb //C 0f1de jz	l_back_to_0 	;l_cyc ;l_bad ; garbage */
0x0000f1df, 0x01a80002, /* 01a80002 //C 0f1df cmp	r10,2		; in state2 */
0x0000f1e0, 0x11f2f1e7, /* 11f2f1e7 //C 0f1e0 jz	l_proc		; process record */
0x0000f1e1, 0x01a80003, /* 01a80003 //C 0f1e1 cmp	r10,3		; in state3 */
0x0000f1e2, 0x11f2f1f1, /* 11f2f1f1 //C 0f1e2 jz	l_ret		; eol in end record: finish */
0x0000f1e3, 0x01a8000f, /* 01a8000f //C 0f1e3 cmp	r10,0xf		; in state skip */
0x0000f1e4, 0x11f2f1eb, /* 11f2f1eb //C 0f1e4 jz	l_back_to_0	; reset state for new line */
0x0000f1e5, 0x01f2f18c, /* 01f2f18c //C 0f1e5 jmp	l_cyc */
0x0000f1e6, 0x01f2f1f1, /* 01f2f1f1 //C 0f1e6 jmp	l_ret */
0x0000f1e7, 0x01680043, /* 01680043 //C 0f1e7 cmp	r6,'C'		; is it a C record? */
0x0000f1e8, 0x1c890000, /* 1c890000 //C 0f1e8 z st	r8,r9		; store */
0x0000f1e9, 0x00000600, /* 00000600 //C 0f1e9 mov	r0,r6		; echo record type */
0x0000f1ea, 0x0400f3a8, /* 0400f3a8 //C 0f1ea call	putchar */
0x0000f1eb, 0x0102002e, /* 0102002e //C 0f1eb mvzl	r0,'.' */
0x0000f1ec, 0x0400f3a8, /* 0400f3a8 //C 0f1ec call	putchar */
0x0000f1ed, 0x01a20000, /* 01a20000 //C 0f1ed mvzl	r10,0 */
0x0000f1ee, 0x01820000, /* 01820000 //C 0f1ee mvzl	r8,0 */
0x0000f1ef, 0x0162003f, /* 0162003f //C 0f1ef mvzl	r6,'?' */
0x0000f1f0, 0x01f2f18c, /* 01f2f18c //C 0f1f0 jmp	l_cyc */
0x0000f1f1, 0x0102000a, /* 0102000a //C 0f1f1 mvzl	r0,LF */
0x0000f1f2, 0x0400f3a8, /* 0400f3a8 //C 0f1f2 call	putchar */
0x0000f1f3, 0x0fed0000, /* 0fed0000 //C 0f1f3 pop	lr */
0x0000f1f4, 0x00f00e00, /* 00f00e00 //C 0f1f4 ret */
0x0000f1f5, 0x0ded0000, /* 0ded0000 //C 0f1f5 push	lr */
0x0000f1f6, 0x0122f45b, /* 0122f45b //C 0f1f6 mvzl	r2,words */
0x0000f1f7, 0x0e020001, /* 0e020001 //C 0f1f7 ld	r0,r2,1		; address */
0x0000f1f8, 0x020b0000, /* 020b0000 //C 0f1f8 sz	r0 */
0x0000f1f9, 0x11f2f21c, /* 11f2f21c //C 0f1f9 jz	g_no_addr */
0x0000f1fa, 0x0400f37d, /* 0400f37d //C 0f1fa call	htoi */
0x0000f1fb, 0x00b00100, /* 00b00100 //C 0f1fb mov	r11,r1 */
0x0000f1fc, 0x0102f230, /* 0102f230 //C 0f1fc mvzl	r0,d_msg_run */
0x0000f1fd, 0x0400f3b2, /* 0400f3b2 //C 0f1fd call	prints */
0x0000f1fe, 0x00000b00, /* 00000b00 //C 0f1fe mov	r0,r11 */
0x0000f1ff, 0x01120004, /* 01120004 //C 0f1ff mvzl	r1,4 */
0x0000f200, 0x0400f3ce, /* 0400f3ce //C 0f200 call	print_vhex */
0x0000f201, 0x0102000a, /* 0102000a //C 0f201 mvzl	r0,LF */
0x0000f202, 0x0400f3a8, /* 0400f3a8 //C 0f202 call	putchar */
0x0000f203, 0x06b0f472, /* 06b0f472 //C 0f203 st	r11,reg15 */
0x0000f204, 0x0122ff43, /* 0122ff43 //C 0f204 mvzl	r2,UART_TSTAT */
0x0000f205, 0x0e920000, /* 0e920000 //C 0f205 ld	r9,r2 */
0x0000f206, 0x019c0001, /* 019c0001 //C 0f206 test	r9,1 */
0x0000f207, 0x11f2f205, /* 11f2f205 //C 0f207 jz	g_wait_tc */
0x0000f208, 0x07000000, /* 07000000 //C 0f208 ld	r0,0 */
0x0000f209, 0x0600f461, /* 0600f461 //C 0f209 st	r0,called */
0x0000f20a, 0x0700f473, /* 0700f473 //C 0f20a ld	r0,regf */
0x0000f20b, 0x020f0000, /* 020f0000 //C 0f20b setf	r0 */
0x0000f20c, 0x0700f463, /* 0700f463 //C 0f20c ld	r0,reg0 */
0x0000f20d, 0x0710f464, /* 0710f464 //C 0f20d ld	r1,reg1 */
0x0000f20e, 0x0720f465, /* 0720f465 //C 0f20e ld	r2,reg2 */
0x0000f20f, 0x0730f466, /* 0730f466 //C 0f20f ld	r3,reg3 */
0x0000f210, 0x0740f467, /* 0740f467 //C 0f210 ld	r4,reg4 */
0x0000f211, 0x0750f468, /* 0750f468 //C 0f211 ld	r5,reg5 */
0x0000f212, 0x0760f469, /* 0760f469 //C 0f212 ld	r6,reg6 */
0x0000f213, 0x0770f46a, /* 0770f46a //C 0f213 ld	r7,reg7 */
0x0000f214, 0x0780f46b, /* 0780f46b //C 0f214 ld	r8,reg8 */
0x0000f215, 0x0790f46c, /* 0790f46c //C 0f215 ld	r9,reg9 */
0x0000f216, 0x07a0f46d, /* 07a0f46d //C 0f216 ld	r10,reg10 */
0x0000f217, 0x07b0f46e, /* 07b0f46e //C 0f217 ld	r11,reg11 */
0x0000f218, 0x07c0f46f, /* 07c0f46f //C 0f218 ld	r12,reg12 */
0x0000f219, 0x07d0f470, /* 07d0f470 //C 0f219 ld	r13,reg13 */
0x0000f21a, 0x07e0f471, /* 07e0f471 //C 0f21a ld	r14,reg14 */
0x0000f21b, 0x07f0f472, /* 07f0f472 //C 0f21b ld	r15,reg15 */
0x0000f21c, 0x0700f461, /* 0700f461 //C 0f21c ld	r0,called */
0x0000f21d, 0x020b0000, /* 020b0000 //C 0f21d sz	r0 */
0x0000f21e, 0x11f2f221, /* 11f2f221 //C 0f21e jz	g_err */
0x0000f21f, 0x07b0f472, /* 07b0f472 //C 0f21f ld	r11,reg15 */
0x0000f220, 0x01f2f1fc, /* 01f2f1fc //C 0f220 jmp	g_go11 */
0x0000f221, 0x0102f225, /* 0102f225 //C 0f221 mvzl	r0,g_err_addr */
0x0000f222, 0x0400f3c6, /* 0400f3c6 //C 0f222 call	printsnl */
0x0000f223, 0x0fed0000, /* 0fed0000 //C 0f223 pop	lr */
0x0000f224, 0x00f00e00, /* 00f00e00 //C 0f224 ret */
0x0000f225, 0x0000004e, /* 0000004e //C 0f225 db	78 */
0x0000f226, 0x0000006f, /* 0000006f //C 0f226 db	111 */
0x0000f227, 0x00000020, /* 00000020 //C 0f227 db	32 */
0x0000f228, 0x00000061, /* 00000061 //C 0f228 db	97 */
0x0000f229, 0x00000064, /* 00000064 //C 0f229 db	100 */
0x0000f22a, 0x00000064, /* 00000064 //C 0f22a db	100 */
0x0000f22b, 0x00000072, /* 00000072 //C 0f22b db	114 */
0x0000f22c, 0x00000065, /* 00000065 //C 0f22c db	101 */
0x0000f22d, 0x00000073, /* 00000073 //C 0f22d db	115 */
0x0000f22e, 0x00000073, /* 00000073 //C 0f22e db	115 */
0x0000f22f, 0x00000000, /* 00000000 //C 0f22f db */
0x0000f230, 0x00000052, /* 00000052 //C 0f230 db	82 */
0x0000f231, 0x00000075, /* 00000075 //C 0f231 db	117 */
0x0000f232, 0x0000006e, /* 0000006e //C 0f232 db	110 */
0x0000f233, 0x00000020, /* 00000020 //C 0f233 db	32 */
0x0000f234, 0x00000000, /* 00000000 //C 0f234 db */
0x0000f235, 0x0ded0000, /* 0ded0000 //C 0f235 push	lr */
0x0000f236, 0x0122f4e5, /* 0122f4e5 //C 0f236 mvzl	r2,helps */
0x0000f237, 0x01320000, /* 01320000 //C 0f237 mvzl	r3,0 */
0x0000f238, 0x0b038200, /* 0b038200 //C 0f238 ld	r0,r3+,r2	; pick a char */
0x0000f239, 0x020b0000, /* 020b0000 //C 0f239 sz	r0		; is it eos? */
0x0000f23a, 0x21f2f23e, /* 21f2f23e //C 0f23a jnz	h_print */
0x0000f23b, 0x0b038200, /* 0b038200 //C 0f23b ld	r0,r3+,r2	; get first char of next string */
0x0000f23c, 0x020b0000, /* 020b0000 //C 0f23c sz	r0 */
0x0000f23d, 0x11f2f240, /* 11f2f240 //C 0f23d jz	h_eof */
0x0000f23e, 0x0400f3a8, /* 0400f3a8 //C 0f23e call	putchar */
0x0000f23f, 0x01f2f238, /* 01f2f238 //C 0f23f jmp	h_cyc */
0x0000f240, 0x0fed0000, /* 0fed0000 //C 0f240 pop	lr */
0x0000f241, 0x00f00e00, /* 00f00e00 //C 0f241 ret */
0x0000f242, 0x0ded0000, /* 0ded0000 //C 0f242 push	lr */
0x0000f243, 0x0d1d0000, /* 0d1d0000 //C 0f243 push	r1 */
0x0000f244, 0x00100000, /* 00100000 //C 0f244 mov	r1,r0 */
0x0000f245, 0x01180010, /* 01180010 //C 0f245 cmp	r1,16		; go out if nr>16 */
0x0000f246, 0x91f2f27a, /* 91f2f27a //C 0f246 HI jmp	prn_ret */
0x0000f247, 0x0118000f, /* 0118000f //C 0f247 cmp	r1,15		; nr=Flag? */
0x0000f248, 0xa1f2f24f, /* a1f2f24f //C 0f248 LS jmp	prn_015 */
0x0000f249, 0x01020046, /* 01020046 //C 0f249 mvzl	r0,'F' */
0x0000f24a, 0x0400f3a8, /* 0400f3a8 //C 0f24a call	putchar */
0x0000f24b, 0x01020020, /* 01020020 //C 0f24b mvzl	r0,32 */
0x0000f24c, 0x0400f3a8, /* 0400f3a8 //C 0f24c call	putchar */
0x0000f24d, 0x0400f3a8, /* 0400f3a8 //C 0f24d call	putchar */
0x0000f24e, 0x01f2f27a, /* 01f2f27a //C 0f24e jmp	prn_ret */
0x0000f24f, 0x0118000f, /* 0118000f //C 0f24f cmp	r1,15 */
0x0000f250, 0x21f2f258, /* 21f2f258 //C 0f250 jnz	prn_no15 */
0x0000f251, 0x0102f254, /* 0102f254 //C 0f251 mvzl	r0,prn_PC */
0x0000f252, 0x0400f3b2, /* 0400f3b2 //C 0f252 call	prints */
0x0000f253, 0x01f2f27a, /* 01f2f27a //C 0f253 jmp	prn_ret */
0x0000f254, 0x00000050, /* 00000050 //C 0f254 db	80 */
0x0000f255, 0x00000043, /* 00000043 //C 0f255 db	67 */
0x0000f256, 0x00000020, /* 00000020 //C 0f256 db	32 */
0x0000f257, 0x00000000, /* 00000000 //C 0f257 db */
0x0000f258, 0x0118000e, /* 0118000e //C 0f258 cmp	r1,14 */
0x0000f259, 0x21f2f261, /* 21f2f261 //C 0f259 jnz	prn_no14 */
0x0000f25a, 0x0102f25d, /* 0102f25d //C 0f25a mvzl	r0,prn_LR */
0x0000f25b, 0x0400f3b2, /* 0400f3b2 //C 0f25b call	prints */
0x0000f25c, 0x01f2f27a, /* 01f2f27a //C 0f25c jmp	prn_ret */
0x0000f25d, 0x0000004c, /* 0000004c //C 0f25d db	76 */
0x0000f25e, 0x00000052, /* 00000052 //C 0f25e db	82 */
0x0000f25f, 0x00000020, /* 00000020 //C 0f25f db	32 */
0x0000f260, 0x00000000, /* 00000000 //C 0f260 db */
0x0000f261, 0x0118000d, /* 0118000d //C 0f261 cmp	r1,13 */
0x0000f262, 0x21f2f26a, /* 21f2f26a //C 0f262 jnz	prn_no13 */
0x0000f263, 0x0102f266, /* 0102f266 //C 0f263 mvzl	r0,prn_SP */
0x0000f264, 0x0400f3b2, /* 0400f3b2 //C 0f264 call	prints */
0x0000f265, 0x01f2f27a, /* 01f2f27a //C 0f265 jmp	prn_ret */
0x0000f266, 0x00000053, /* 00000053 //C 0f266 db	83 */
0x0000f267, 0x00000050, /* 00000050 //C 0f267 db	80 */
0x0000f268, 0x00000020, /* 00000020 //C 0f268 db	32 */
0x0000f269, 0x00000000, /* 00000000 //C 0f269 db */
0x0000f26a, 0x01020052, /* 01020052 //C 0f26a mvzl	r0,'R' */
0x0000f26b, 0x0400f3a8, /* 0400f3a8 //C 0f26b call	putchar */
0x0000f26c, 0x01180009, /* 01180009 //C 0f26c cmp	r1,9 */
0x0000f26d, 0x91f2f274, /* 91f2f274 //C 0f26d HI jmp	prn_1015 */
0x0000f26e, 0x00000100, /* 00000100 //C 0f26e mov	r0,r1 */
0x0000f26f, 0x01040030, /* 01040030 //C 0f26f add	r0,'0' */
0x0000f270, 0x0400f3a8, /* 0400f3a8 //C 0f270 call	putchar */
0x0000f271, 0x01020020, /* 01020020 //C 0f271 mvzl	r0,32 */
0x0000f272, 0x0400f3a8, /* 0400f3a8 //C 0f272 call	putchar */
0x0000f273, 0x01f2f27a, /* 01f2f27a //C 0f273 jmp	prn_ret */
0x0000f274, 0x01020031, /* 01020031 //C 0f274 mvzl	r0,'1' */
0x0000f275, 0x0400f3a8, /* 0400f3a8 //C 0f275 call	putchar */
0x0000f276, 0x00000100, /* 00000100 //C 0f276 mov	r0,r1 */
0x0000f277, 0x0106000a, /* 0106000a //C 0f277 sub	r0,10 */
0x0000f278, 0x01040030, /* 01040030 //C 0f278 add	r0,'0' */
0x0000f279, 0x0400f3a8, /* 0400f3a8 //C 0f279 call	putchar */
0x0000f27a, 0x0f1d0000, /* 0f1d0000 //C 0f27a pop	r1 */
0x0000f27b, 0x0fed0000, /* 0fed0000 //C 0f27b pop	lr */
0x0000f27c, 0x00f00e00, /* 00f00e00 //C 0f27c ret */
0x0000f27d, 0x0ded0000, /* 0ded0000 //C 0f27d push	lr */
0x0000f27e, 0x0d1d0000, /* 0d1d0000 //C 0f27e push	r1 */
0x0000f27f, 0x01080010, /* 01080010 //C 0f27f cmp	r0,16 */
0x0000f280, 0x91f2f285, /* 91f2f285 //C 0f280 HI jmp	prv_ret */
0x0000f281, 0x0112f463, /* 0112f463 //C 0f281 mvzl	r1,reg0 */
0x0000f282, 0x0a010000, /* 0a010000 //C 0f282 ld	r0,r1,r0 */
0x0000f283, 0x01120004, /* 01120004 //C 0f283 mvzl	r1,4 */
0x0000f284, 0x0400f3ce, /* 0400f3ce //C 0f284 call	print_vhex */
0x0000f285, 0x0f1d0000, /* 0f1d0000 //C 0f285 pop	r1 */
0x0000f286, 0x0fed0000, /* 0fed0000 //C 0f286 pop	lr */
0x0000f287, 0x00f00e00, /* 00f00e00 //C 0f287 ret */
0x0000f288, 0x0ded0000, /* 0ded0000 //C 0f288 push	lr */
0x0000f289, 0x0dad0000, /* 0dad0000 //C 0f289 push	r10 */
0x0000f28a, 0x0d0d0000, /* 0d0d0000 //C 0f28a push	r0 */
0x0000f28b, 0x00000a00, /* 00000a00 //C 0f28b mov	r0,r10 */
0x0000f28c, 0x0400f242, /* 0400f242 //C 0f28c call	print_reg_name */
0x0000f28d, 0x01020020, /* 01020020 //C 0f28d mvzl	r0,32 */
0x0000f28e, 0x0400f3a8, /* 0400f3a8 //C 0f28e call	putchar */
0x0000f28f, 0x00000a00, /* 00000a00 //C 0f28f mov	r0,r10 */
0x0000f290, 0x0400f27d, /* 0400f27d //C 0f290 call	print_reg_value */
0x0000f291, 0x0102000a, /* 0102000a //C 0f291 mvzl	r0,LF */
0x0000f292, 0x0400f3a8, /* 0400f3a8 //C 0f292 call	putchar */
0x0000f293, 0x0f0d0000, /* 0f0d0000 //C 0f293 pop	r0 */
0x0000f294, 0x0fad0000, /* 0fad0000 //C 0f294 pop	r10 */
0x0000f295, 0x0fed0000, /* 0fed0000 //C 0f295 pop	lr */
0x0000f296, 0x00f00e00, /* 00f00e00 //C 0f296 ret */
0x0000f297, 0x0ded0000, /* 0ded0000 //C 0f297 push	lr */
0x0000f298, 0x0400f3a8, /* 0400f3a8 //C 0f298 call	putchar */
0x0000f299, 0x001c0200, /* 001c0200 //C 0f299 test	r1,r2 */
0x0000f29a, 0x21020031, /* 21020031 //C 0f29a NZ mvzl r0,'1' */
0x0000f29b, 0x11020030, /* 11020030 //C 0f29b Z  mvzl r0,'0' */
0x0000f29c, 0x0400f3a8, /* 0400f3a8 //C 0f29c call	putchar */
0x0000f29d, 0x00000300, /* 00000300 //C 0f29d mov	r0,r3 */
0x0000f29e, 0x0400f3a8, /* 0400f3a8 //C 0f29e call	putchar */
0x0000f29f, 0x0fed0000, /* 0fed0000 //C 0f29f pop	lr */
0x0000f2a0, 0x00f00e00, /* 00f00e00 //C 0f2a0 ret */
0x0000f2a1, 0x0ded0000, /* 0ded0000 //C 0f2a1 push	lr */
0x0000f2a2, 0x01a20000, /* 01a20000 //C 0f2a2 mvzl	r10,0 */
0x0000f2a3, 0x0400f288, /* 0400f288 //C 0f2a3 call	print_reg_name_value */
0x0000f2a4, 0x01a40001, /* 01a40001 //C 0f2a4 add	r10,1 */
0x0000f2a5, 0x01a80011, /* 01a80011 //C 0f2a5 cmp	r10,17 */
0x0000f2a6, 0x21f2f2a3, /* 21f2f2a3 //C 0f2a6 jnz	r_cyc */
0x0000f2a7, 0x0710f473, /* 0710f473 //C 0f2a7 ld	r1,regf */
0x0000f2a8, 0x01320020, /* 01320020 //C 0f2a8 mvzl	r3,32 */
0x0000f2a9, 0x01020055, /* 01020055 //C 0f2a9 mvzl	r0,'U' */
0x0000f2aa, 0x01220020, /* 01220020 //C 0f2aa mvzl	r2,0x20 */
0x0000f2ab, 0x0400f297, /* 0400f297 //C 0f2ab call	print_flag */
0x0000f2ac, 0x01020050, /* 01020050 //C 0f2ac mvzl	r0,'P' */
0x0000f2ad, 0x01220010, /* 01220010 //C 0f2ad mvzl	r2,0x10 */
0x0000f2ae, 0x0400f297, /* 0400f297 //C 0f2ae call	print_flag */
0x0000f2af, 0x0102004f, /* 0102004f //C 0f2af mvzl	r0,'O' */
0x0000f2b0, 0x01220008, /* 01220008 //C 0f2b0 mvzl	r2,8 */
0x0000f2b1, 0x0400f297, /* 0400f297 //C 0f2b1 call	print_flag */
0x0000f2b2, 0x0102005a, /* 0102005a //C 0f2b2 mvzl	r0,'Z' */
0x0000f2b3, 0x01220004, /* 01220004 //C 0f2b3 mvzl	r2,4 */
0x0000f2b4, 0x0400f297, /* 0400f297 //C 0f2b4 call	print_flag */
0x0000f2b5, 0x01020043, /* 01020043 //C 0f2b5 mvzl	r0,'C' */
0x0000f2b6, 0x01220002, /* 01220002 //C 0f2b6 mvzl	r2,2 */
0x0000f2b7, 0x0400f297, /* 0400f297 //C 0f2b7 call	print_flag */
0x0000f2b8, 0x01020053, /* 01020053 //C 0f2b8 mvzl	r0,'S' */
0x0000f2b9, 0x01220001, /* 01220001 //C 0f2b9 mvzl	r2,1 */
0x0000f2ba, 0x0132000a, /* 0132000a //C 0f2ba mvzl	r3,LF */
0x0000f2bb, 0x0400f297, /* 0400f297 //C 0f2bb call	print_flag */
0x0000f2bc, 0x0fed0000, /* 0fed0000 //C 0f2bc pop	lr */
0x0000f2bd, 0x00f00e00, /* 00f00e00 //C 0f2bd ret */
0x0000f2be, 0x0ded0000, /* 0ded0000 //C 0f2be push	lr */
0x0000f2bf, 0x07a0f462, /* 07a0f462 //C 0f2bf ld	r10,nuof_reg	; Reg num is in R10 */
0x0000f2c0, 0x01a80010, /* 01a80010 //C 0f2c0 cmp	r10,16 */
0x0000f2c1, 0xa1f2f2d6, /* a1f2f2d6 //C 0f2c1 LS jmp	rx_nr_ok */
0x0000f2c2, 0x0102f2c5, /* 0102f2c5 //C 0f2c2 mvzl	r0,rx_err_nr */
0x0000f2c3, 0x0400f3c6, /* 0400f3c6 //C 0f2c3 call	printsnl */
0x0000f2c4, 0x01f2f2f2, /* 01f2f2f2 //C 0f2c4 jmp	rx_ret */
0x0000f2c5, 0x0000004e, /* 0000004e //C 0f2c5 db	78 */
0x0000f2c6, 0x0000006f, /* 0000006f //C 0f2c6 db	111 */
0x0000f2c7, 0x00000020, /* 00000020 //C 0f2c7 db	32 */
0x0000f2c8, 0x00000073, /* 00000073 //C 0f2c8 db	115 */
0x0000f2c9, 0x00000075, /* 00000075 //C 0f2c9 db	117 */
0x0000f2ca, 0x00000063, /* 00000063 //C 0f2ca db	99 */
0x0000f2cb, 0x00000068, /* 00000068 //C 0f2cb db	104 */
0x0000f2cc, 0x00000020, /* 00000020 //C 0f2cc db	32 */
0x0000f2cd, 0x00000072, /* 00000072 //C 0f2cd db	114 */
0x0000f2ce, 0x00000065, /* 00000065 //C 0f2ce db	101 */
0x0000f2cf, 0x00000067, /* 00000067 //C 0f2cf db	103 */
0x0000f2d0, 0x00000069, /* 00000069 //C 0f2d0 db	105 */
0x0000f2d1, 0x00000073, /* 00000073 //C 0f2d1 db	115 */
0x0000f2d2, 0x00000074, /* 00000074 //C 0f2d2 db	116 */
0x0000f2d3, 0x00000065, /* 00000065 //C 0f2d3 db	101 */
0x0000f2d4, 0x00000072, /* 00000072 //C 0f2d4 db	114 */
0x0000f2d5, 0x00000000, /* 00000000 //C 0f2d5 db */
0x0000f2d6, 0x0122f45b, /* 0122f45b //C 0f2d6 mvzl	r2,words */
0x0000f2d7, 0x0e420001, /* 0e420001 //C 0f2d7 ld	r4,r2,1		; get aof first parameter */
0x0000f2d8, 0x024b0000, /* 024b0000 //C 0f2d8 sz	r4		; is it NULL? */
0x0000f2d9, 0x11f2f2f1, /* 11f2f2f1 //C 0f2d9 jz	rx_print */
0x0000f2da, 0x00000400, /* 00000400 //C 0f2da mov	r0,r4 */
0x0000f2db, 0x0400f37d, /* 0400f37d //C 0f2db call	htoi */
0x0000f2dc, 0x00500100, /* 00500100 //C 0f2dc mov	r5,r1		; Value is in R5 */
0x0000f2dd, 0x31f2f2ed, /* 31f2f2ed //C 0f2dd C1 jmp	rx_val_ok */
0x0000f2de, 0x0102f2e1, /* 0102f2e1 //C 0f2de mvzl	r0,rx_err_val */
0x0000f2df, 0x0400f3c6, /* 0400f3c6 //C 0f2df call	printsnl */
0x0000f2e0, 0x01f2f2f2, /* 01f2f2f2 //C 0f2e0 jmp	rx_ret */
0x0000f2e1, 0x00000056, /* 00000056 //C 0f2e1 db	86 */
0x0000f2e2, 0x00000061, /* 00000061 //C 0f2e2 db	97 */
0x0000f2e3, 0x0000006c, /* 0000006c //C 0f2e3 db	108 */
0x0000f2e4, 0x00000075, /* 00000075 //C 0f2e4 db	117 */
0x0000f2e5, 0x00000065, /* 00000065 //C 0f2e5 db	101 */
0x0000f2e6, 0x00000020, /* 00000020 //C 0f2e6 db	32 */
0x0000f2e7, 0x00000065, /* 00000065 //C 0f2e7 db	101 */
0x0000f2e8, 0x00000072, /* 00000072 //C 0f2e8 db	114 */
0x0000f2e9, 0x00000072, /* 00000072 //C 0f2e9 db	114 */
0x0000f2ea, 0x0000006f, /* 0000006f //C 0f2ea db	111 */
0x0000f2eb, 0x00000072, /* 00000072 //C 0f2eb db	114 */
0x0000f2ec, 0x00000000, /* 00000000 //C 0f2ec db */
0x0000f2ed, 0x01a80010, /* 01a80010 //C 0f2ed cmp	r10,16		; Flag reg? */
0x0000f2ee, 0x115f003f, /* 115f003f //C 0f2ee EQ and	r5,0x3f */
0x0000f2ef, 0x0102f463, /* 0102f463 //C 0f2ef mvzl	r0,reg0 */
0x0000f2f0, 0x08500a00, /* 08500a00 //C 0f2f0 st	r5,r0,r10 */
0x0000f2f1, 0x0400f288, /* 0400f288 //C 0f2f1 call	print_reg_name_value */
0x0000f2f2, 0x0fed0000, /* 0fed0000 //C 0f2f2 pop	lr */
0x0000f2f3, 0x00f00e00, /* 00f00e00 //C 0f2f3 ret */
0x0000f2f4, 0x0102000d, /* 0102000d //C 0f2f4 mvzl	r0,13 */
0x0000f2f5, 0x0600f462, /* 0600f462 //C 0f2f5 st	r0,nuof_reg */
0x0000f2f6, 0x01f2f2be, /* 01f2f2be //C 0f2f6 jmp	cmd_rx */
0x0000f2f7, 0x0102000e, /* 0102000e //C 0f2f7 mvzl	r0,14 */
0x0000f2f8, 0x0600f462, /* 0600f462 //C 0f2f8 st	r0,nuof_reg */
0x0000f2f9, 0x01f2f2be, /* 01f2f2be //C 0f2f9 jmp	cmd_rx */
0x0000f2fa, 0x0102000f, /* 0102000f //C 0f2fa mvzl	r0,15 */
0x0000f2fb, 0x0600f462, /* 0600f462 //C 0f2fb st	r0,nuof_reg */
0x0000f2fc, 0x01f2f2be, /* 01f2f2be //C 0f2fc jmp	cmd_rx */
0x0000f2fd, 0x01020010, /* 01020010 //C 0f2fd mvzl	r0,16 */
0x0000f2fe, 0x0600f462, /* 0600f462 //C 0f2fe st	r0,nuof_reg */
0x0000f2ff, 0x01f2f2be, /* 01f2f2be //C 0f2ff jmp	cmd_rx */
0x0000f300, 0x0d1d0000, /* 0d1d0000 //C 0f300 push	r1 */
0x0000f301, 0x0d2d0000, /* 0d2d0000 //C 0f301 push	r2 */
0x0000f302, 0x0e210000, /* 0e210000 //C 0f302 ld	r2,r1 */
0x0000f303, 0x022b0000, /* 022b0000 //C 0f303 sz	r2 */
0x0000f304, 0x11f2f30b, /* 11f2f30b //C 0f304 jz	strchr_no	; eof string found */
0x0000f305, 0x00280000, /* 00280000 //C 0f305 cmp	r2,r0		; compare */
0x0000f306, 0x11f2f309, /* 11f2f309 //C 0f306 jz	strchr_yes */
0x0000f307, 0x011a0001, /* 011a0001 //C 0f307 plus	r1,1		; go to next char */
0x0000f308, 0x01f2f302, /* 01f2f302 //C 0f308 jmp	strchr_cyc */
0x0000f309, 0x020c0000, /* 020c0000 //C 0f309 sec */
0x0000f30a, 0x01f2f30d, /* 01f2f30d //C 0f30a jmp	strchr_ret */
0x0000f30b, 0x01120000, /* 01120000 //C 0f30b mvzl	r1,0 */
0x0000f30c, 0x020d0000, /* 020d0000 //C 0f30c clc */
0x0000f30d, 0x0f2d0000, /* 0f2d0000 //C 0f30d pop	r2 */
0x0000f30e, 0x0f1d0000, /* 0f1d0000 //C 0f30e pop	r1 */
0x0000f30f, 0x00f00e00, /* 00f00e00 //C 0f30f ret */
0x0000f310, 0x0ded0000, /* 0ded0000 //C 0f310 push	lr		; Save used registers */
0x0000f311, 0x0d0d0000, /* 0d0d0000 //C 0f311 push	r0		; and input parameters */
0x0000f312, 0x0d1d0000, /* 0d1d0000 //C 0f312 push	r1 */
0x0000f313, 0x0d2d0000, /* 0d2d0000 //C 0f313 push	r2 */
0x0000f314, 0x0d4d0000, /* 0d4d0000 //C 0f314 push	r4 */
0x0000f315, 0x0d5d0000, /* 0d5d0000 //C 0f315 push	r5 */
0x0000f316, 0x0d6d0000, /* 0d6d0000 //C 0f316 push	r6 */
0x0000f317, 0x0e200000, /* 0e200000 //C 0f317 ld	r2,r0		; Got one-one char */
0x0000f318, 0x0e610000, /* 0e610000 //C 0f318 ld	r6,r1		; from two strings */
0x0000f319, 0x023b0000, /* 023b0000 //C 0f319 sz	r3		; Prepare for comparing */
0x0000f31a, 0x112d0020, /* 112d0020 //C 0f31a Z1 or	r2,0x20		; if insensitive case */
0x0000f31b, 0x023b0000, /* 023b0000 //C 0f31b sz	r3 */
0x0000f31c, 0x116d0020, /* 116d0020 //C 0f31c Z1 or	r6,0x20 */
0x0000f31d, 0x00280600, /* 00280600 //C 0f31d cmp	r2,r6		; compare them */
0x0000f31e, 0x21f2f330, /* 21f2f330 //C 0f31e jnz	streq_no	; if differs: strings are not equal */
0x0000f31f, 0x0e200000, /* 0e200000 //C 0f31f ld	r2,r0		; Pick original (non-prepared) */
0x0000f320, 0x0e610000, /* 0e610000 //C 0f320 ld	r6,r1		; chars to check EOS */
0x0000f321, 0x022b0000, /* 022b0000 //C 0f321 sz	r2		; convert them to boolean */
0x0000f322, 0x21220001, /* 21220001 //C 0f322 Z0 mvzl	r2,1		; values in R2,R6 */
0x0000f323, 0x11220000, /* 11220000 //C 0f323 Z1 mvzl	r2,0		; and copy in R4,R5 */
0x0000f324, 0x00400200, /* 00400200 //C 0f324 mov	r4,r2 */
0x0000f325, 0x026b0000, /* 026b0000 //C 0f325 sz	r6 */
0x0000f326, 0x21620001, /* 21620001 //C 0f326 Z0 mvzl	r6,1 */
0x0000f327, 0x11620000, /* 11620000 //C 0f327 Z1 mvzl r6,0 */
0x0000f328, 0x00500600, /* 00500600 //C 0f328 mov	r5,r6 */
0x0000f329, 0x004d0500, /* 004d0500 //C 0f329 or	r4,r5		; if both are EOS: equal */
0x0000f32a, 0x11f2f332, /* 11f2f332 //C 0f32a jz	streq_yes */
0x0000f32b, 0x002f0600, /* 002f0600 //C 0f32b and 	r2,r6		; just one is EOS: not equal */
0x0000f32c, 0x11f2f330, /* 11f2f330 //C 0f32c jz	streq_no */
0x0000f32d, 0x010a0001, /* 010a0001 //C 0f32d plus	r0,1		; non are EOS: go to check next char */
0x0000f32e, 0x011a0001, /* 011a0001 //C 0f32e plus	r1,1 */
0x0000f32f, 0x01f2f317, /* 01f2f317 //C 0f32f jmp	streq_cyc */
0x0000f330, 0x020d0000, /* 020d0000 //C 0f330 clc			; False result */
0x0000f331, 0x01f2f333, /* 01f2f333 //C 0f331 jmp	streq_ret */
0x0000f332, 0x020c0000, /* 020c0000 //C 0f332 sec			; True result */
0x0000f333, 0x0f6d0000, /* 0f6d0000 //C 0f333 pop	r6 */
0x0000f334, 0x0f5d0000, /* 0f5d0000 //C 0f334 pop	r5 */
0x0000f335, 0x0f4d0000, /* 0f4d0000 //C 0f335 pop	r4 */
0x0000f336, 0x0f2d0000, /* 0f2d0000 //C 0f336 pop	r2 */
0x0000f337, 0x0f1d0000, /* 0f1d0000 //C 0f337 pop	r1 */
0x0000f338, 0x0f0d0000, /* 0f0d0000 //C 0f338 pop	r0 */
0x0000f339, 0x0fed0000, /* 0fed0000 //C 0f339 pop	lr */
0x0000f33a, 0x00f00e00, /* 00f00e00 //C 0f33a ret */
0x0000f33b, 0x0ded0000, /* 0ded0000 //C 0f33b push	lr */
0x0000f33c, 0x0d3d0000, /* 0d3d0000 //C 0f33c push	r3 */
0x0000f33d, 0x01320001, /* 01320001 //C 0f33d mvzl	r3,1 */
0x0000f33e, 0x0400f310, /* 0400f310 //C 0f33e call	str_cmp_eq */
0x0000f33f, 0x0f3d0000, /* 0f3d0000 //C 0f33f pop	r3 */
0x0000f340, 0x0fed0000, /* 0fed0000 //C 0f340 pop	lr */
0x0000f341, 0x00f00e00, /* 00f00e00 //C 0f341 ret */
0x0000f342, 0x0ded0000, /* 0ded0000 //C 0f342 push	lr */
0x0000f343, 0x0d3d0000, /* 0d3d0000 //C 0f343 push	r3 */
0x0000f344, 0x01320000, /* 01320000 //C 0f344 mvzl	r3,0 */
0x0000f345, 0x0400f310, /* 0400f310 //C 0f345 call	str_cmp_eq */
0x0000f346, 0x0f3d0000, /* 0f3d0000 //C 0f346 pop	r3 */
0x0000f347, 0x0fed0000, /* 0fed0000 //C 0f347 pop	lr */
0x0000f348, 0x00f00e00, /* 00f00e00 //C 0f348 ret */
0x0000f349, 0x0108002f, /* 0108002f //C 0f349 cmp	r0,'/' */
0x0000f34a, 0xa1f2f35f, /* a1f2f35f //C 0f34a LS jmp	hc2v_nok */
0x0000f34b, 0x01080039, /* 01080039 //C 0f34b cmp	r0,'9' */
0x0000f34c, 0xa1f2f35c, /* a1f2f35c //C 0f34c LS jmp	hc2v_0_9 */
0x0000f34d, 0x01080040, /* 01080040 //C 0f34d cmp	r0,'@' */
0x0000f34e, 0xa1f2f35f, /* a1f2f35f //C 0f34e LS jmp	hc2v_nok */
0x0000f34f, 0x01080046, /* 01080046 //C 0f34f cmp	r0,'F' */
0x0000f350, 0xa1f2f359, /* a1f2f359 //C 0f350 LS jmp	hc2v_A_F */
0x0000f351, 0x01080060, /* 01080060 //C 0f351 cmp	r0,'`' */
0x0000f352, 0xa1f2f35f, /* a1f2f35f //C 0f352 LS jmp	hc2v_nok */
0x0000f353, 0x01080066, /* 01080066 //C 0f353 cmp	r0,'f' */
0x0000f354, 0xa1f2f356, /* a1f2f356 //C 0f354 LS jmp	hc2v_a_f */
0x0000f355, 0x01f2f35f, /* 01f2f35f //C 0f355 jmp	hc2v_nok */
0x0000f356, 0x0104000a, /* 0104000a //C 0f356 add	r0,10 */
0x0000f357, 0x01060061, /* 01060061 //C 0f357 sub	r0,'a' */
0x0000f358, 0x01f2f35d, /* 01f2f35d //C 0f358 jmp	hc2v_ok */
0x0000f359, 0x0104000a, /* 0104000a //C 0f359 add	r0,10 */
0x0000f35a, 0x01060041, /* 01060041 //C 0f35a sub	r0,'A' */
0x0000f35b, 0x01f2f35d, /* 01f2f35d //C 0f35b jmp	hc2v_ok */
0x0000f35c, 0x01060030, /* 01060030 //C 0f35c sub	r0,'0' */
0x0000f35d, 0x020c0000, /* 020c0000 //C 0f35d sec */
0x0000f35e, 0x00f00e00, /* 00f00e00 //C 0f35e ret */
0x0000f35f, 0x020d0000, /* 020d0000 //C 0f35f clc */
0x0000f360, 0x00f00e00, /* 00f00e00 //C 0f360 ret */
0x0000f361, 0x0d1d0000, /* 0d1d0000 //C 0f361 push	r1 */
0x0000f362, 0x010f000f, /* 010f000f //C 0f362 and	r0,0xf */
0x0000f363, 0x0112f367, /* 0112f367 //C 0f363 mvzl	r1,v2hc_table */
0x0000f364, 0x0a010000, /* 0a010000 //C 0f364 ld	r0,r1,r0 */
0x0000f365, 0x0f1d0000, /* 0f1d0000 //C 0f365 pop	r1 */
0x0000f366, 0x00f00e00, /* 00f00e00 //C 0f366 ret */
0x0000f367, 0x00000030, /* 00000030 //C 0f367 db	48 */
0x0000f368, 0x00000031, /* 00000031 //C 0f368 db	49 */
0x0000f369, 0x00000032, /* 00000032 //C 0f369 db	50 */
0x0000f36a, 0x00000033, /* 00000033 //C 0f36a db	51 */
0x0000f36b, 0x00000034, /* 00000034 //C 0f36b db	52 */
0x0000f36c, 0x00000035, /* 00000035 //C 0f36c db	53 */
0x0000f36d, 0x00000036, /* 00000036 //C 0f36d db	54 */
0x0000f36e, 0x00000037, /* 00000037 //C 0f36e db	55 */
0x0000f36f, 0x00000038, /* 00000038 //C 0f36f db	56 */
0x0000f370, 0x00000039, /* 00000039 //C 0f370 db	57 */
0x0000f371, 0x00000041, /* 00000041 //C 0f371 db	65 */
0x0000f372, 0x00000042, /* 00000042 //C 0f372 db	66 */
0x0000f373, 0x00000043, /* 00000043 //C 0f373 db	67 */
0x0000f374, 0x00000044, /* 00000044 //C 0f374 db	68 */
0x0000f375, 0x00000045, /* 00000045 //C 0f375 db	69 */
0x0000f376, 0x00000046, /* 00000046 //C 0f376 db	70 */
0x0000f377, 0x00000000, /* 00000000 //C 0f377 db */
0x0000f378, 0x0ded0000, /* 0ded0000 //C 0f378 push	lr */
0x0000f379, 0x0400f361, /* 0400f361 //C 0f379 call	value2Hexchar */
0x0000f37a, 0x010d0020, /* 010d0020 //C 0f37a or	r0,0x20 */
0x0000f37b, 0x0fed0000, /* 0fed0000 //C 0f37b pop	lr */
0x0000f37c, 0x00f00e00, /* 00f00e00 //C 0f37c ret */
0x0000f37d, 0x0ded0000, /* 0ded0000 //C 0f37d push	lr */
0x0000f37e, 0x0d2d0000, /* 0d2d0000 //C 0f37e push	r2 */
0x0000f37f, 0x0d3d0000, /* 0d3d0000 //C 0f37f push	r3 */
0x0000f380, 0x01120000, /* 01120000 //C 0f380 mvzl	r1,0		; return value */
0x0000f381, 0x01320000, /* 01320000 //C 0f381 mvzl	r3,0		; index */
0x0000f382, 0x0b238000, /* 0b238000 //C 0f382 ld	r2,r3+,r0	; pick a char */
0x0000f383, 0x022b0000, /* 022b0000 //C 0f383 sz	r2		; check eof string */
0x0000f384, 0x11f2f398, /* 11f2f398 //C 0f384 jz	htoi_eos */
0x0000f385, 0x0128002e, /* 0128002e //C 0f385 cmp	r2,'.'		; skip separators */
0x0000f386, 0x11f2f382, /* 11f2f382 //C 0f386 jz	htoi_cyc */
0x0000f387, 0x0128005f, /* 0128005f //C 0f387 cmp	r2,'_' */
0x0000f388, 0x11f2f382, /* 11f2f382 //C 0f388 jz	htoi_cyc */
0x0000f389, 0x0d0d0000, /* 0d0d0000 //C 0f389 push	r0 */
0x0000f38a, 0x00000200, /* 00000200 //C 0f38a mov	r0,r2 */
0x0000f38b, 0x0400f349, /* 0400f349 //C 0f38b call	hexchar2value */
0x0000f38c, 0x00200000, /* 00200000 //C 0f38c mov	r2,r0 */
0x0000f38d, 0x0f0d0000, /* 0f0d0000 //C 0f38d pop	r0 */
0x0000f38e, 0x41f2f396, /* 41f2f396 //C 0f38e C0 jmp	htoi_nok */
0x0000f38f, 0x02180000, /* 02180000 //C 0f38f shl	r1 */
0x0000f390, 0x02180000, /* 02180000 //C 0f390 shl	r1 */
0x0000f391, 0x02180000, /* 02180000 //C 0f391 shl	r1 */
0x0000f392, 0x02180000, /* 02180000 //C 0f392 shl	r1 */
0x0000f393, 0x012f000f, /* 012f000f //C 0f393 and	r2,0xf */
0x0000f394, 0x001d0200, /* 001d0200 //C 0f394 or	r1,r2 */
0x0000f395, 0x01f2f382, /* 01f2f382 //C 0f395 jmp	htoi_cyc */
0x0000f396, 0x020d0000, /* 020d0000 //C 0f396 clc */
0x0000f397, 0x01f2f39b, /* 01f2f39b //C 0f397 jmp	htoi_ret */
0x0000f398, 0x01380001, /* 01380001 //C 0f398 cmp	r3,1 */
0x0000f399, 0x920d0000, /* 920d0000 //C 0f399 HI clc */
0x0000f39a, 0xa20c0000, /* a20c0000 //C 0f39a LS sec */
0x0000f39b, 0x0f3d0000, /* 0f3d0000 //C 0f39b pop	r3 */
0x0000f39c, 0x0f2d0000, /* 0f2d0000 //C 0f39c pop	r2 */
0x0000f39d, 0x0fed0000, /* 0fed0000 //C 0f39d pop	lr */
0x0000f39e, 0x00f00e00, /* 00f00e00 //C 0f39e ret */
0x0000f39f, 0x0d0d0000, /* 0d0d0000 //C 0f39f push	r0 */
0x0000f3a0, 0x0700ff42, /* 0700ff42 //C 0f3a0 ld	r0,UART_RSTAT */
0x0000f3a1, 0x010c0001, /* 010c0001 //C 0f3a1 test	r0,1 */
0x0000f3a2, 0x020d0000, /* 020d0000 //C 0f3a2 clc */
0x0000f3a3, 0x220c0000, /* 220c0000 //C 0f3a3 Z0 sec */
0x0000f3a4, 0x0f0d0000, /* 0f0d0000 //C 0f3a4 pop	r0 */
0x0000f3a5, 0x00f00e00, /* 00f00e00 //C 0f3a5 ret */
0x0000f3a6, 0x0700ff40, /* 0700ff40 //C 0f3a6 ld	r0,UART_DR */
0x0000f3a7, 0x00f00e00, /* 00f00e00 //C 0f3a7 ret */
0x0000f3a8, 0x0d9d0000, /* 0d9d0000 //C 0f3a8 push	r9 */
0x0000f3a9, 0x01920070, /* 01920070 //C 0f3a9 mvzl	r9,'p' */
0x0000f3aa, 0x0690ffff, /* 0690ffff //C 0f3aa st	r9,SIMIF */
0x0000f3ab, 0x0600ffff, /* 0600ffff //C 0f3ab st	r0,SIMIF */
0x0000f3ac, 0x0790ff43, /* 0790ff43 //C 0f3ac ld	r9,UART_TSTAT */
0x0000f3ad, 0x019c0001, /* 019c0001 //C 0f3ad test	r9,1 */
0x0000f3ae, 0x11f2f3ac, /* 11f2f3ac //C 0f3ae jz	wait_tc */
0x0000f3af, 0x0600ff40, /* 0600ff40 //C 0f3af st	r0,UART_DR */
0x0000f3b0, 0x0f9d0000, /* 0f9d0000 //C 0f3b0 pop	r9 */
0x0000f3b1, 0x00f00e00, /* 00f00e00 //C 0f3b1 ret */
0x0000f3b2, 0x0ded0000, /* 0ded0000 //C 0f3b2 push	lr */
0x0000f3b3, 0x0d0d0000, /* 0d0d0000 //C 0f3b3 push	r0 */
0x0000f3b4, 0x0d3d0000, /* 0d3d0000 //C 0f3b4 push	r3 */
0x0000f3b5, 0x0d4d0000, /* 0d4d0000 //C 0f3b5 push	r4 */
0x0000f3b6, 0x0d2d0000, /* 0d2d0000 //C 0f3b6 push	r2 */
0x0000f3b7, 0x01420000, /* 01420000 //C 0f3b7 mvzl	r4,0 */
0x0000f3b8, 0x020b0000, /* 020b0000 //C 0f3b8 sz	r0 */
0x0000f3b9, 0x1102f48d, /* 1102f48d //C 0f3b9 Z1 mvzl	r0,null_str */
0x0000f3ba, 0x00200000, /* 00200000 //C 0f3ba mov	r2,r0 */
0x0000f3bb, 0x0b048200, /* 0b048200 //C 0f3bb ld	r0,r4+,r2 */
0x0000f3bc, 0x020b0000, /* 020b0000 //C 0f3bc sz	r0 */
0x0000f3bd, 0x11f2f3c0, /* 11f2f3c0 //C 0f3bd jz	prints_done */
0x0000f3be, 0x0400f3a8, /* 0400f3a8 //C 0f3be call	putchar */
0x0000f3bf, 0x01f2f3bb, /* 01f2f3bb //C 0f3bf jmp	prints_go */
0x0000f3c0, 0x0f2d0000, /* 0f2d0000 //C 0f3c0 pop	r2 */
0x0000f3c1, 0x0f4d0000, /* 0f4d0000 //C 0f3c1 pop	r4 */
0x0000f3c2, 0x0f3d0000, /* 0f3d0000 //C 0f3c2 pop	r3 */
0x0000f3c3, 0x0f0d0000, /* 0f0d0000 //C 0f3c3 pop	r0 */
0x0000f3c4, 0x0fed0000, /* 0fed0000 //C 0f3c4 pop	lr */
0x0000f3c5, 0x00f00e00, /* 00f00e00 //C 0f3c5 ret */
0x0000f3c6, 0x0ded0000, /* 0ded0000 //C 0f3c6 push	lr */
0x0000f3c7, 0x0400f3b2, /* 0400f3b2 //C 0f3c7 call	prints */
0x0000f3c8, 0x0d0d0000, /* 0d0d0000 //C 0f3c8 push	r0 */
0x0000f3c9, 0x0102000a, /* 0102000a //C 0f3c9 mvzl	r0,LF */
0x0000f3ca, 0x0400f3a8, /* 0400f3a8 //C 0f3ca call	putchar */
0x0000f3cb, 0x0f0d0000, /* 0f0d0000 //C 0f3cb pop	r0 */
0x0000f3cc, 0x0fed0000, /* 0fed0000 //C 0f3cc pop	lr */
0x0000f3cd, 0x00f00e00, /* 00f00e00 //C 0f3cd ret */
0x0000f3ce, 0x0ded0000, /* 0ded0000 //C 0f3ce push	lr */
0x0000f3cf, 0x0d0d0000, /* 0d0d0000 //C 0f3cf push	r0 */
0x0000f3d0, 0x0d1d0000, /* 0d1d0000 //C 0f3d0 push	r1 */
0x0000f3d1, 0x0d2d0000, /* 0d2d0000 //C 0f3d1 push	r2 */
0x0000f3d2, 0x0d3d0000, /* 0d3d0000 //C 0f3d2 push	r3 */
0x0000f3d3, 0x0d4d0000, /* 0d4d0000 //C 0f3d3 push	r4 */
0x0000f3d4, 0x00300000, /* 00300000 //C 0f3d4 mov	r3,r0 */
0x0000f3d5, 0x01220000, /* 01220000 //C 0f3d5 mvzl	r2,0 */
0x0000f3d6, 0x01420001, /* 01420001 //C 0f3d6 mvzl	r4,1 */
0x0000f3d7, 0x01020000, /* 01020000 //C 0f3d7 mvzl	r0,0 */
0x0000f3d8, 0x02380000, /* 02380000 //C 0f3d8 shl	r3 */
0x0000f3d9, 0x02070000, /* 02070000 //C 0f3d9 rol	r0 */
0x0000f3da, 0x02380000, /* 02380000 //C 0f3da shl	r3 */
0x0000f3db, 0x02070000, /* 02070000 //C 0f3db rol	r0 */
0x0000f3dc, 0x02380000, /* 02380000 //C 0f3dc shl	r3 */
0x0000f3dd, 0x02070000, /* 02070000 //C 0f3dd rol	r0 */
0x0000f3de, 0x02380000, /* 02380000 //C 0f3de shl	r3 */
0x0000f3df, 0x02070000, /* 02070000 //C 0f3df rol	r0 */
0x0000f3e0, 0x0400f361, /* 0400f361 //C 0f3e0 call	value2Hexchar */
0x0000f3e1, 0x0400f3a8, /* 0400f3a8 //C 0f3e1 call	putchar */
0x0000f3e2, 0x01240001, /* 01240001 //C 0f3e2 add	r2,1 */
0x0000f3e3, 0x01280008, /* 01280008 //C 0f3e3 cmp	r2,8 */
0x0000f3e4, 0x11f2f3ee, /* 11f2f3ee //C 0f3e4 jz	print_vhex_ret */
0x0000f3e5, 0x021b0000, /* 021b0000 //C 0f3e5 sz	r1 */
0x0000f3e6, 0x11f2f3ec, /* 11f2f3ec //C 0f3e6 jz	print_vhex_nosep */
0x0000f3e7, 0x00480100, /* 00480100 //C 0f3e7 cmp	r4,r1 */
0x0000f3e8, 0x21f2f3ec, /* 21f2f3ec //C 0f3e8 jnz	print_vhex_nosep */
0x0000f3e9, 0x0102005f, /* 0102005f //C 0f3e9 mvzl	r0,'_' */
0x0000f3ea, 0x0400f3a8, /* 0400f3a8 //C 0f3ea call	putchar */
0x0000f3eb, 0x01420000, /* 01420000 //C 0f3eb mvzl	r4,0 */
0x0000f3ec, 0x01440001, /* 01440001 //C 0f3ec add	r4,1 */
0x0000f3ed, 0x01f2f3d7, /* 01f2f3d7 //C 0f3ed jmp	print_vhex_cyc */
0x0000f3ee, 0x0f4d0000, /* 0f4d0000 //C 0f3ee pop	r4 */
0x0000f3ef, 0x0f3d0000, /* 0f3d0000 //C 0f3ef pop	r3 */
0x0000f3f0, 0x0f2d0000, /* 0f2d0000 //C 0f3f0 pop	r2 */
0x0000f3f1, 0x0f1d0000, /* 0f1d0000 //C 0f3f1 pop	r1 */
0x0000f3f2, 0x0f0d0000, /* 0f0d0000 //C 0f3f2 pop	r0 */
0x0000f3f3, 0x0fed0000, /* 0fed0000 //C 0f3f3 pop	lr */
0x0000f3f4, 0x00f00e00, /* 00f00e00 //C 0f3f4 ret */
0x0000f461, 0x00000000, /* 00000000 //C 0f461 dd	0 */
0x0000f462, 0x00000000, /* 00000000 //C 0f462 dd	0 */
0x0000f463, 0x00000000, /* 00000000 //C 0f463 dd	0 */
0x0000f464, 0x00000000, /* 00000000 //C 0f464 dd	0 */
0x0000f465, 0x00000000, /* 00000000 //C 0f465 dd	0 */
0x0000f466, 0x00000000, /* 00000000 //C 0f466 dd	0 */
0x0000f467, 0x00000000, /* 00000000 //C 0f467 dd	0 */
0x0000f468, 0x00000000, /* 00000000 //C 0f468 dd	0 */
0x0000f469, 0x00000000, /* 00000000 //C 0f469 dd	0 */
0x0000f46a, 0x00000000, /* 00000000 //C 0f46a dd	0 */
0x0000f46b, 0x00000000, /* 00000000 //C 0f46b dd	0 */
0x0000f46c, 0x00000000, /* 00000000 //C 0f46c dd	0 */
0x0000f46d, 0x00000000, /* 00000000 //C 0f46d dd	0 */
0x0000f46e, 0x00000000, /* 00000000 //C 0f46e dd	0 */
0x0000f46f, 0x00000000, /* 00000000 //C 0f46f dd	0 */
0x0000f470, 0x00000000, /* 00000000 //C 0f470 dd	0 */
0x0000f471, 0x00000000, /* 00000000 //C 0f471 dd	0 */
0x0000f472, 0x00000000, /* 00000000 //C 0f472 dd	0 */
0x0000f473, 0x00000000, /* 00000000 //C 0f473 dd	0 */
0x0000f474, 0x00000050, /* 00000050 //C 0f474 db	80 */
0x0000f475, 0x0000004d, /* 0000004d //C 0f475 db	77 */
0x0000f476, 0x0000006f, /* 0000006f //C 0f476 db	111 */
0x0000f477, 0x0000006e, /* 0000006e //C 0f477 db	110 */
0x0000f478, 0x00000069, /* 00000069 //C 0f478 db	105 */
0x0000f479, 0x00000074, /* 00000074 //C 0f479 db	116 */
0x0000f47a, 0x0000006f, /* 0000006f //C 0f47a db	111 */
0x0000f47b, 0x00000072, /* 00000072 //C 0f47b db	114 */
0x0000f47c, 0x00000020, /* 00000020 //C 0f47c db	32 */
0x0000f47d, 0x00000076, /* 00000076 //C 0f47d db	118 */
0x0000f47e, 0x00000031, /* 00000031 //C 0f47e db	49 */
0x0000f47f, 0x0000002e, /* 0000002e //C 0f47f db	46 */
0x0000f480, 0x00000030, /* 00000030 //C 0f480 db	48 */
0x0000f481, 0x00000000, /* 00000000 //C 0f481 db */
0x0000f482, 0x0000003e, /* 0000003e //C 0f482 db	62 */
0x0000f483, 0x00000000, /* 00000000 //C 0f483 db */
0x0000f484, 0x00000020, /* 00000020 //C 0f484 db	32 */
0x0000f485, 0x0000003b, /* 0000003b //C 0f485 db	59 */
0x0000f486, 0x00000009, /* 00000009 //C 0f486 db	9 */
0x0000f487, 0x0000000b, /* 0000000b //C 0f487 db	11 */
0x0000f488, 0x0000002c, /* 0000002c //C 0f488 db	44 */
0x0000f489, 0x0000003d, /* 0000003d //C 0f489 db	61 */
0x0000f48a, 0x0000005b, /* 0000005b //C 0f48a db	91 */
0x0000f48b, 0x0000005d, /* 0000005d //C 0f48b db	93 */
0x0000f48c, 0x00000000, /* 00000000 //C 0f48c db */
0x0000f48d, 0x00000028, /* 00000028 //C 0f48d db	40 */
0x0000f48e, 0x0000006e, /* 0000006e //C 0f48e db	110 */
0x0000f48f, 0x00000075, /* 00000075 //C 0f48f db	117 */
0x0000f490, 0x0000006c, /* 0000006c //C 0f490 db	108 */
0x0000f491, 0x0000006c, /* 0000006c //C 0f491 db	108 */
0x0000f492, 0x00000029, /* 00000029 //C 0f492 db	41 */
0x0000f493, 0x00000000, /* 00000000 //C 0f493 db */
0x0000f494, 0x0000f0ff, /* 0000f0ff //C 0f494 dd	cmd_m */
0x0000f495, 0x0000006d, /* 0000006d //C 0f495 db	109 */
0x0000f496, 0x00000000, /* 00000000 //C 0f496 db */
0x0000f497, 0x0000f0ff, /* 0000f0ff //C 0f497 dd	cmd_m */
0x0000f498, 0x0000006d, /* 0000006d //C 0f498 db	109 */
0x0000f499, 0x00000065, /* 00000065 //C 0f499 db	101 */
0x0000f49a, 0x0000006d, /* 0000006d //C 0f49a db	109 */
0x0000f49b, 0x00000000, /* 00000000 //C 0f49b db */
0x0000f49c, 0x0000f154, /* 0000f154 //C 0f49c dd	cmd_d */
0x0000f49d, 0x00000064, /* 00000064 //C 0f49d db	100 */
0x0000f49e, 0x00000000, /* 00000000 //C 0f49e db */
0x0000f49f, 0x0000f154, /* 0000f154 //C 0f49f dd	cmd_d */
0x0000f4a0, 0x00000064, /* 00000064 //C 0f4a0 db	100 */
0x0000f4a1, 0x00000075, /* 00000075 //C 0f4a1 db	117 */
0x0000f4a2, 0x0000006d, /* 0000006d //C 0f4a2 db	109 */
0x0000f4a3, 0x00000070, /* 00000070 //C 0f4a3 db	112 */
0x0000f4a4, 0x00000000, /* 00000000 //C 0f4a4 db */
0x0000f4a5, 0x0000f188, /* 0000f188 //C 0f4a5 dd	cmd_l */
0x0000f4a6, 0x0000006c, /* 0000006c //C 0f4a6 db	108 */
0x0000f4a7, 0x00000000, /* 00000000 //C 0f4a7 db */
0x0000f4a8, 0x0000f188, /* 0000f188 //C 0f4a8 dd	cmd_l */
0x0000f4a9, 0x0000006c, /* 0000006c //C 0f4a9 db	108 */
0x0000f4aa, 0x0000006f, /* 0000006f //C 0f4aa db	111 */
0x0000f4ab, 0x00000061, /* 00000061 //C 0f4ab db	97 */
0x0000f4ac, 0x00000064, /* 00000064 //C 0f4ac db	100 */
0x0000f4ad, 0x00000000, /* 00000000 //C 0f4ad db */
0x0000f4ae, 0x0000f1f5, /* 0000f1f5 //C 0f4ae dd	cmd_g */
0x0000f4af, 0x00000067, /* 00000067 //C 0f4af db	103 */
0x0000f4b0, 0x00000000, /* 00000000 //C 0f4b0 db */
0x0000f4b1, 0x0000f1f5, /* 0000f1f5 //C 0f4b1 dd	cmd_g */
0x0000f4b2, 0x00000067, /* 00000067 //C 0f4b2 db	103 */
0x0000f4b3, 0x0000006f, /* 0000006f //C 0f4b3 db	111 */
0x0000f4b4, 0x00000000, /* 00000000 //C 0f4b4 db */
0x0000f4b5, 0x0000f1f5, /* 0000f1f5 //C 0f4b5 dd	cmd_g */
0x0000f4b6, 0x00000072, /* 00000072 //C 0f4b6 db	114 */
0x0000f4b7, 0x00000075, /* 00000075 //C 0f4b7 db	117 */
0x0000f4b8, 0x0000006e, /* 0000006e //C 0f4b8 db	110 */
0x0000f4b9, 0x00000000, /* 00000000 //C 0f4b9 db */
0x0000f4ba, 0x0000f235, /* 0000f235 //C 0f4ba dd	cmd_h */
0x0000f4bb, 0x0000003f, /* 0000003f //C 0f4bb db	63 */
0x0000f4bc, 0x00000000, /* 00000000 //C 0f4bc db */
0x0000f4bd, 0x0000f235, /* 0000f235 //C 0f4bd dd	cmd_h */
0x0000f4be, 0x00000068, /* 00000068 //C 0f4be db	104 */
0x0000f4bf, 0x00000000, /* 00000000 //C 0f4bf db */
0x0000f4c0, 0x0000f235, /* 0000f235 //C 0f4c0 dd	cmd_h */
0x0000f4c1, 0x00000068, /* 00000068 //C 0f4c1 db	104 */
0x0000f4c2, 0x00000065, /* 00000065 //C 0f4c2 db	101 */
0x0000f4c3, 0x0000006c, /* 0000006c //C 0f4c3 db	108 */
0x0000f4c4, 0x00000070, /* 00000070 //C 0f4c4 db	112 */
0x0000f4c5, 0x00000000, /* 00000000 //C 0f4c5 db */
0x0000f4c6, 0x0000f2a1, /* 0000f2a1 //C 0f4c6 dd	cmd_r */
0x0000f4c7, 0x00000072, /* 00000072 //C 0f4c7 db	114 */
0x0000f4c8, 0x00000000, /* 00000000 //C 0f4c8 db */
0x0000f4c9, 0x0000f2a1, /* 0000f2a1 //C 0f4c9 dd	cmd_r */
0x0000f4ca, 0x00000072, /* 00000072 //C 0f4ca db	114 */
0x0000f4cb, 0x00000065, /* 00000065 //C 0f4cb db	101 */
0x0000f4cc, 0x00000067, /* 00000067 //C 0f4cc db	103 */
0x0000f4cd, 0x00000000, /* 00000000 //C 0f4cd db */
0x0000f4ce, 0x0000f2a1, /* 0000f2a1 //C 0f4ce dd	cmd_r */
0x0000f4cf, 0x00000072, /* 00000072 //C 0f4cf db	114 */
0x0000f4d0, 0x00000065, /* 00000065 //C 0f4d0 db	101 */
0x0000f4d1, 0x00000067, /* 00000067 //C 0f4d1 db	103 */
0x0000f4d2, 0x00000073, /* 00000073 //C 0f4d2 db	115 */
0x0000f4d3, 0x00000000, /* 00000000 //C 0f4d3 db */
0x0000f4d4, 0x0000f2f4, /* 0000f2f4 //C 0f4d4 dd	cmd_sp */
0x0000f4d5, 0x00000073, /* 00000073 //C 0f4d5 db	115 */
0x0000f4d6, 0x00000070, /* 00000070 //C 0f4d6 db	112 */
0x0000f4d7, 0x00000000, /* 00000000 //C 0f4d7 db */
0x0000f4d8, 0x0000f2f7, /* 0000f2f7 //C 0f4d8 dd	cmd_lr */
0x0000f4d9, 0x0000006c, /* 0000006c //C 0f4d9 db	108 */
0x0000f4da, 0x00000072, /* 00000072 //C 0f4da db	114 */
0x0000f4db, 0x00000000, /* 00000000 //C 0f4db db */
0x0000f4dc, 0x0000f2fa, /* 0000f2fa //C 0f4dc dd	cmd_pc */
0x0000f4dd, 0x00000070, /* 00000070 //C 0f4dd db	112 */
0x0000f4de, 0x00000063, /* 00000063 //C 0f4de db	99 */
0x0000f4df, 0x00000000, /* 00000000 //C 0f4df db */
0x0000f4e0, 0x0000f2fd, /* 0000f2fd //C 0f4e0 dd	cmd_f */
0x0000f4e1, 0x00000066, /* 00000066 //C 0f4e1 db	102 */
0x0000f4e2, 0x00000000, /* 00000000 //C 0f4e2 db */
0x0000f4e3, 0x00000000, /* 00000000 //C 0f4e3 dd	0 */
0x0000f4e4, 0x00000000, /* 00000000 //C 0f4e4 dd	0 */
0x0000f4e5, 0x0000006d, /* 0000006d //C 0f4e5 db	109 */
0x0000f4e6, 0x0000005b, /* 0000005b //C 0f4e6 db	91 */
0x0000f4e7, 0x00000065, /* 00000065 //C 0f4e7 db	101 */
0x0000f4e8, 0x0000006d, /* 0000006d //C 0f4e8 db	109 */
0x0000f4e9, 0x0000005d, /* 0000005d //C 0f4e9 db	93 */
0x0000f4ea, 0x00000020, /* 00000020 //C 0f4ea db	32 */
0x0000f4eb, 0x00000061, /* 00000061 //C 0f4eb db	97 */
0x0000f4ec, 0x00000064, /* 00000064 //C 0f4ec db	100 */
0x0000f4ed, 0x00000064, /* 00000064 //C 0f4ed db	100 */
0x0000f4ee, 0x00000072, /* 00000072 //C 0f4ee db	114 */
0x0000f4ef, 0x00000020, /* 00000020 //C 0f4ef db	32 */
0x0000f4f0, 0x0000005b, /* 0000005b //C 0f4f0 db	91 */
0x0000f4f1, 0x00000076, /* 00000076 //C 0f4f1 db	118 */
0x0000f4f2, 0x00000061, /* 00000061 //C 0f4f2 db	97 */
0x0000f4f3, 0x0000006c, /* 0000006c //C 0f4f3 db	108 */
0x0000f4f4, 0x0000005d, /* 0000005d //C 0f4f4 db	93 */
0x0000f4f5, 0x00000020, /* 00000020 //C 0f4f5 db	32 */
0x0000f4f6, 0x00000020, /* 00000020 //C 0f4f6 db	32 */
0x0000f4f7, 0x00000047, /* 00000047 //C 0f4f7 db	71 */
0x0000f4f8, 0x00000065, /* 00000065 //C 0f4f8 db	101 */
0x0000f4f9, 0x00000074, /* 00000074 //C 0f4f9 db	116 */
0x0000f4fa, 0x0000002f, /* 0000002f //C 0f4fa db	47 */
0x0000f4fb, 0x00000073, /* 00000073 //C 0f4fb db	115 */
0x0000f4fc, 0x00000065, /* 00000065 //C 0f4fc db	101 */
0x0000f4fd, 0x00000074, /* 00000074 //C 0f4fd db	116 */
0x0000f4fe, 0x00000020, /* 00000020 //C 0f4fe db	32 */
0x0000f4ff, 0x0000006d, /* 0000006d //C 0f4ff db	109 */
0x0000f500, 0x00000065, /* 00000065 //C 0f500 db	101 */
0x0000f501, 0x0000006d, /* 0000006d //C 0f501 db	109 */
0x0000f502, 0x0000006f, /* 0000006f //C 0f502 db	111 */
0x0000f503, 0x00000072, /* 00000072 //C 0f503 db	114 */
0x0000f504, 0x00000079, /* 00000079 //C 0f504 db	121 */
0x0000f505, 0x0000000a, /* 0000000a //C 0f505 db	10 */
0x0000f506, 0x00000000, /* 00000000 //C 0f506 db */
0x0000f507, 0x00000064, /* 00000064 //C 0f507 db	100 */
0x0000f508, 0x0000005b, /* 0000005b //C 0f508 db	91 */
0x0000f509, 0x00000075, /* 00000075 //C 0f509 db	117 */
0x0000f50a, 0x0000006d, /* 0000006d //C 0f50a db	109 */
0x0000f50b, 0x00000070, /* 00000070 //C 0f50b db	112 */
0x0000f50c, 0x0000005d, /* 0000005d //C 0f50c db	93 */
0x0000f50d, 0x00000020, /* 00000020 //C 0f50d db	32 */
0x0000f50e, 0x00000073, /* 00000073 //C 0f50e db	115 */
0x0000f50f, 0x00000074, /* 00000074 //C 0f50f db	116 */
0x0000f510, 0x00000061, /* 00000061 //C 0f510 db	97 */
0x0000f511, 0x00000072, /* 00000072 //C 0f511 db	114 */
0x0000f512, 0x00000074, /* 00000074 //C 0f512 db	116 */
0x0000f513, 0x00000020, /* 00000020 //C 0f513 db	32 */
0x0000f514, 0x00000065, /* 00000065 //C 0f514 db	101 */
0x0000f515, 0x0000006e, /* 0000006e //C 0f515 db	110 */
0x0000f516, 0x00000064, /* 00000064 //C 0f516 db	100 */
0x0000f517, 0x00000020, /* 00000020 //C 0f517 db	32 */
0x0000f518, 0x00000020, /* 00000020 //C 0f518 db	32 */
0x0000f519, 0x00000044, /* 00000044 //C 0f519 db	68 */
0x0000f51a, 0x00000075, /* 00000075 //C 0f51a db	117 */
0x0000f51b, 0x0000006d, /* 0000006d //C 0f51b db	109 */
0x0000f51c, 0x00000070, /* 00000070 //C 0f51c db	112 */
0x0000f51d, 0x00000020, /* 00000020 //C 0f51d db	32 */
0x0000f51e, 0x0000006d, /* 0000006d //C 0f51e db	109 */
0x0000f51f, 0x00000065, /* 00000065 //C 0f51f db	101 */
0x0000f520, 0x0000006d, /* 0000006d //C 0f520 db	109 */
0x0000f521, 0x0000006f, /* 0000006f //C 0f521 db	111 */
0x0000f522, 0x00000072, /* 00000072 //C 0f522 db	114 */
0x0000f523, 0x00000079, /* 00000079 //C 0f523 db	121 */
0x0000f524, 0x00000020, /* 00000020 //C 0f524 db	32 */
0x0000f525, 0x00000063, /* 00000063 //C 0f525 db	99 */
0x0000f526, 0x0000006f, /* 0000006f //C 0f526 db	111 */
0x0000f527, 0x0000006e, /* 0000006e //C 0f527 db	110 */
0x0000f528, 0x00000074, /* 00000074 //C 0f528 db	116 */
0x0000f529, 0x00000065, /* 00000065 //C 0f529 db	101 */
0x0000f52a, 0x0000006e, /* 0000006e //C 0f52a db	110 */
0x0000f52b, 0x00000074, /* 00000074 //C 0f52b db	116 */
0x0000f52c, 0x0000000a, /* 0000000a //C 0f52c db	10 */
0x0000f52d, 0x00000000, /* 00000000 //C 0f52d db */
0x0000f52e, 0x0000006c, /* 0000006c //C 0f52e db	108 */
0x0000f52f, 0x0000005b, /* 0000005b //C 0f52f db	91 */
0x0000f530, 0x0000006f, /* 0000006f //C 0f530 db	111 */
0x0000f531, 0x00000061, /* 00000061 //C 0f531 db	97 */
0x0000f532, 0x00000064, /* 00000064 //C 0f532 db	100 */
0x0000f533, 0x0000005d, /* 0000005d //C 0f533 db	93 */
0x0000f534, 0x00000020, /* 00000020 //C 0f534 db	32 */
0x0000f535, 0x00000020, /* 00000020 //C 0f535 db	32 */
0x0000f536, 0x00000020, /* 00000020 //C 0f536 db	32 */
0x0000f537, 0x00000020, /* 00000020 //C 0f537 db	32 */
0x0000f538, 0x00000020, /* 00000020 //C 0f538 db	32 */
0x0000f539, 0x00000020, /* 00000020 //C 0f539 db	32 */
0x0000f53a, 0x00000020, /* 00000020 //C 0f53a db	32 */
0x0000f53b, 0x00000020, /* 00000020 //C 0f53b db	32 */
0x0000f53c, 0x00000020, /* 00000020 //C 0f53c db	32 */
0x0000f53d, 0x00000020, /* 00000020 //C 0f53d db	32 */
0x0000f53e, 0x00000020, /* 00000020 //C 0f53e db	32 */
0x0000f53f, 0x00000020, /* 00000020 //C 0f53f db	32 */
0x0000f540, 0x0000004c, /* 0000004c //C 0f540 db	76 */
0x0000f541, 0x0000006f, /* 0000006f //C 0f541 db	111 */
0x0000f542, 0x00000061, /* 00000061 //C 0f542 db	97 */
0x0000f543, 0x00000064, /* 00000064 //C 0f543 db	100 */
0x0000f544, 0x00000020, /* 00000020 //C 0f544 db	32 */
0x0000f545, 0x00000068, /* 00000068 //C 0f545 db	104 */
0x0000f546, 0x00000065, /* 00000065 //C 0f546 db	101 */
0x0000f547, 0x00000078, /* 00000078 //C 0f547 db	120 */
0x0000f548, 0x00000020, /* 00000020 //C 0f548 db	32 */
0x0000f549, 0x00000066, /* 00000066 //C 0f549 db	102 */
0x0000f54a, 0x00000069, /* 00000069 //C 0f54a db	105 */
0x0000f54b, 0x0000006c, /* 0000006c //C 0f54b db	108 */
0x0000f54c, 0x00000065, /* 00000065 //C 0f54c db	101 */
0x0000f54d, 0x00000020, /* 00000020 //C 0f54d db	32 */
0x0000f54e, 0x00000074, /* 00000074 //C 0f54e db	116 */
0x0000f54f, 0x0000006f, /* 0000006f //C 0f54f db	111 */
0x0000f550, 0x00000020, /* 00000020 //C 0f550 db	32 */
0x0000f551, 0x0000006d, /* 0000006d //C 0f551 db	109 */
0x0000f552, 0x00000065, /* 00000065 //C 0f552 db	101 */
0x0000f553, 0x0000006d, /* 0000006d //C 0f553 db	109 */
0x0000f554, 0x0000006f, /* 0000006f //C 0f554 db	111 */
0x0000f555, 0x00000072, /* 00000072 //C 0f555 db	114 */
0x0000f556, 0x00000079, /* 00000079 //C 0f556 db	121 */
0x0000f557, 0x0000000a, /* 0000000a //C 0f557 db	10 */
0x0000f558, 0x00000000, /* 00000000 //C 0f558 db */
0x0000f559, 0x00000067, /* 00000067 //C 0f559 db	103 */
0x0000f55a, 0x0000005b, /* 0000005b //C 0f55a db	91 */
0x0000f55b, 0x0000006f, /* 0000006f //C 0f55b db	111 */
0x0000f55c, 0x0000005d, /* 0000005d //C 0f55c db	93 */
0x0000f55d, 0x0000007c, /* 0000007c //C 0f55d db	124 */
0x0000f55e, 0x00000072, /* 00000072 //C 0f55e db	114 */
0x0000f55f, 0x00000075, /* 00000075 //C 0f55f db	117 */
0x0000f560, 0x0000006e, /* 0000006e //C 0f560 db	110 */
0x0000f561, 0x00000020, /* 00000020 //C 0f561 db	32 */
0x0000f562, 0x0000005b, /* 0000005b //C 0f562 db	91 */
0x0000f563, 0x00000061, /* 00000061 //C 0f563 db	97 */
0x0000f564, 0x00000064, /* 00000064 //C 0f564 db	100 */
0x0000f565, 0x00000064, /* 00000064 //C 0f565 db	100 */
0x0000f566, 0x00000072, /* 00000072 //C 0f566 db	114 */
0x0000f567, 0x0000005d, /* 0000005d //C 0f567 db	93 */
0x0000f568, 0x00000020, /* 00000020 //C 0f568 db	32 */
0x0000f569, 0x00000020, /* 00000020 //C 0f569 db	32 */
0x0000f56a, 0x00000020, /* 00000020 //C 0f56a db	32 */
0x0000f56b, 0x00000052, /* 00000052 //C 0f56b db	82 */
0x0000f56c, 0x00000075, /* 00000075 //C 0f56c db	117 */
0x0000f56d, 0x0000006e, /* 0000006e //C 0f56d db	110 */
0x0000f56e, 0x00000020, /* 00000020 //C 0f56e db	32 */
0x0000f56f, 0x00000066, /* 00000066 //C 0f56f db	102 */
0x0000f570, 0x00000072, /* 00000072 //C 0f570 db	114 */
0x0000f571, 0x0000006f, /* 0000006f //C 0f571 db	111 */
0x0000f572, 0x0000006d, /* 0000006d //C 0f572 db	109 */
0x0000f573, 0x00000020, /* 00000020 //C 0f573 db	32 */
0x0000f574, 0x00000061, /* 00000061 //C 0f574 db	97 */
0x0000f575, 0x00000064, /* 00000064 //C 0f575 db	100 */
0x0000f576, 0x00000064, /* 00000064 //C 0f576 db	100 */
0x0000f577, 0x00000072, /* 00000072 //C 0f577 db	114 */
0x0000f578, 0x00000065, /* 00000065 //C 0f578 db	101 */
0x0000f579, 0x00000073, /* 00000073 //C 0f579 db	115 */
0x0000f57a, 0x00000073, /* 00000073 //C 0f57a db	115 */
0x0000f57b, 0x0000000a, /* 0000000a //C 0f57b db	10 */
0x0000f57c, 0x00000000, /* 00000000 //C 0f57c db */
0x0000f57d, 0x00000072, /* 00000072 //C 0f57d db	114 */
0x0000f57e, 0x0000005b, /* 0000005b //C 0f57e db	91 */
0x0000f57f, 0x00000065, /* 00000065 //C 0f57f db	101 */
0x0000f580, 0x00000067, /* 00000067 //C 0f580 db	103 */
0x0000f581, 0x0000005b, /* 0000005b //C 0f581 db	91 */
0x0000f582, 0x00000073, /* 00000073 //C 0f582 db	115 */
0x0000f583, 0x0000005d, /* 0000005d //C 0f583 db	93 */
0x0000f584, 0x0000005d, /* 0000005d //C 0f584 db	93 */
0x0000f585, 0x00000020, /* 00000020 //C 0f585 db	32 */
0x0000f586, 0x00000020, /* 00000020 //C 0f586 db	32 */
0x0000f587, 0x00000020, /* 00000020 //C 0f587 db	32 */
0x0000f588, 0x00000020, /* 00000020 //C 0f588 db	32 */
0x0000f589, 0x00000020, /* 00000020 //C 0f589 db	32 */
0x0000f58a, 0x00000020, /* 00000020 //C 0f58a db	32 */
0x0000f58b, 0x00000020, /* 00000020 //C 0f58b db	32 */
0x0000f58c, 0x00000020, /* 00000020 //C 0f58c db	32 */
0x0000f58d, 0x00000020, /* 00000020 //C 0f58d db	32 */
0x0000f58e, 0x00000020, /* 00000020 //C 0f58e db	32 */
0x0000f58f, 0x00000050, /* 00000050 //C 0f58f db	80 */
0x0000f590, 0x00000072, /* 00000072 //C 0f590 db	114 */
0x0000f591, 0x00000069, /* 00000069 //C 0f591 db	105 */
0x0000f592, 0x0000006e, /* 0000006e //C 0f592 db	110 */
0x0000f593, 0x00000074, /* 00000074 //C 0f593 db	116 */
0x0000f594, 0x00000020, /* 00000020 //C 0f594 db	32 */
0x0000f595, 0x00000072, /* 00000072 //C 0f595 db	114 */
0x0000f596, 0x00000065, /* 00000065 //C 0f596 db	101 */
0x0000f597, 0x00000067, /* 00000067 //C 0f597 db	103 */
0x0000f598, 0x00000069, /* 00000069 //C 0f598 db	105 */
0x0000f599, 0x00000073, /* 00000073 //C 0f599 db	115 */
0x0000f59a, 0x00000074, /* 00000074 //C 0f59a db	116 */
0x0000f59b, 0x00000065, /* 00000065 //C 0f59b db	101 */
0x0000f59c, 0x00000072, /* 00000072 //C 0f59c db	114 */
0x0000f59d, 0x00000073, /* 00000073 //C 0f59d db	115 */
0x0000f59e, 0x0000000a, /* 0000000a //C 0f59e db	10 */
0x0000f59f, 0x00000000, /* 00000000 //C 0f59f db */
0x0000f5a0, 0x00000072, /* 00000072 //C 0f5a0 db	114 */
0x0000f5a1, 0x00000058, /* 00000058 //C 0f5a1 db	88 */
0x0000f5a2, 0x00000020, /* 00000020 //C 0f5a2 db	32 */
0x0000f5a3, 0x0000005b, /* 0000005b //C 0f5a3 db	91 */
0x0000f5a4, 0x00000076, /* 00000076 //C 0f5a4 db	118 */
0x0000f5a5, 0x00000061, /* 00000061 //C 0f5a5 db	97 */
0x0000f5a6, 0x0000006c, /* 0000006c //C 0f5a6 db	108 */
0x0000f5a7, 0x0000005d, /* 0000005d //C 0f5a7 db	93 */
0x0000f5a8, 0x00000020, /* 00000020 //C 0f5a8 db	32 */
0x0000f5a9, 0x00000020, /* 00000020 //C 0f5a9 db	32 */
0x0000f5aa, 0x00000020, /* 00000020 //C 0f5aa db	32 */
0x0000f5ab, 0x00000020, /* 00000020 //C 0f5ab db	32 */
0x0000f5ac, 0x00000020, /* 00000020 //C 0f5ac db	32 */
0x0000f5ad, 0x00000020, /* 00000020 //C 0f5ad db	32 */
0x0000f5ae, 0x00000020, /* 00000020 //C 0f5ae db	32 */
0x0000f5af, 0x00000020, /* 00000020 //C 0f5af db	32 */
0x0000f5b0, 0x00000020, /* 00000020 //C 0f5b0 db	32 */
0x0000f5b1, 0x00000020, /* 00000020 //C 0f5b1 db	32 */
0x0000f5b2, 0x00000047, /* 00000047 //C 0f5b2 db	71 */
0x0000f5b3, 0x00000065, /* 00000065 //C 0f5b3 db	101 */
0x0000f5b4, 0x00000074, /* 00000074 //C 0f5b4 db	116 */
0x0000f5b5, 0x0000002f, /* 0000002f //C 0f5b5 db	47 */
0x0000f5b6, 0x00000073, /* 00000073 //C 0f5b6 db	115 */
0x0000f5b7, 0x00000065, /* 00000065 //C 0f5b7 db	101 */
0x0000f5b8, 0x00000074, /* 00000074 //C 0f5b8 db	116 */
0x0000f5b9, 0x00000020, /* 00000020 //C 0f5b9 db	32 */
0x0000f5ba, 0x00000052, /* 00000052 //C 0f5ba db	82 */
0x0000f5bb, 0x00000058, /* 00000058 //C 0f5bb db	88 */
0x0000f5bc, 0x0000000a, /* 0000000a //C 0f5bc db	10 */
0x0000f5bd, 0x00000000, /* 00000000 //C 0f5bd db */
0x0000f5be, 0x00000073, /* 00000073 //C 0f5be db	115 */
0x0000f5bf, 0x00000070, /* 00000070 //C 0f5bf db	112 */
0x0000f5c0, 0x00000020, /* 00000020 //C 0f5c0 db	32 */
0x0000f5c1, 0x0000005b, /* 0000005b //C 0f5c1 db	91 */
0x0000f5c2, 0x00000076, /* 00000076 //C 0f5c2 db	118 */
0x0000f5c3, 0x00000061, /* 00000061 //C 0f5c3 db	97 */
0x0000f5c4, 0x0000006c, /* 0000006c //C 0f5c4 db	108 */
0x0000f5c5, 0x0000005d, /* 0000005d //C 0f5c5 db	93 */
0x0000f5c6, 0x00000020, /* 00000020 //C 0f5c6 db	32 */
0x0000f5c7, 0x00000020, /* 00000020 //C 0f5c7 db	32 */
0x0000f5c8, 0x00000020, /* 00000020 //C 0f5c8 db	32 */
0x0000f5c9, 0x00000020, /* 00000020 //C 0f5c9 db	32 */
0x0000f5ca, 0x00000020, /* 00000020 //C 0f5ca db	32 */
0x0000f5cb, 0x00000020, /* 00000020 //C 0f5cb db	32 */
0x0000f5cc, 0x00000020, /* 00000020 //C 0f5cc db	32 */
0x0000f5cd, 0x00000020, /* 00000020 //C 0f5cd db	32 */
0x0000f5ce, 0x00000020, /* 00000020 //C 0f5ce db	32 */
0x0000f5cf, 0x00000020, /* 00000020 //C 0f5cf db	32 */
0x0000f5d0, 0x00000047, /* 00000047 //C 0f5d0 db	71 */
0x0000f5d1, 0x00000065, /* 00000065 //C 0f5d1 db	101 */
0x0000f5d2, 0x00000074, /* 00000074 //C 0f5d2 db	116 */
0x0000f5d3, 0x0000002f, /* 0000002f //C 0f5d3 db	47 */
0x0000f5d4, 0x00000073, /* 00000073 //C 0f5d4 db	115 */
0x0000f5d5, 0x00000065, /* 00000065 //C 0f5d5 db	101 */
0x0000f5d6, 0x00000074, /* 00000074 //C 0f5d6 db	116 */
0x0000f5d7, 0x00000020, /* 00000020 //C 0f5d7 db	32 */
0x0000f5d8, 0x00000052, /* 00000052 //C 0f5d8 db	82 */
0x0000f5d9, 0x00000031, /* 00000031 //C 0f5d9 db	49 */
0x0000f5da, 0x00000033, /* 00000033 //C 0f5da db	51 */
0x0000f5db, 0x0000000a, /* 0000000a //C 0f5db db	10 */
0x0000f5dc, 0x00000000, /* 00000000 //C 0f5dc db */
0x0000f5dd, 0x0000006c, /* 0000006c //C 0f5dd db	108 */
0x0000f5de, 0x00000072, /* 00000072 //C 0f5de db	114 */
0x0000f5df, 0x00000020, /* 00000020 //C 0f5df db	32 */
0x0000f5e0, 0x0000005b, /* 0000005b //C 0f5e0 db	91 */
0x0000f5e1, 0x00000076, /* 00000076 //C 0f5e1 db	118 */
0x0000f5e2, 0x00000061, /* 00000061 //C 0f5e2 db	97 */
0x0000f5e3, 0x0000006c, /* 0000006c //C 0f5e3 db	108 */
0x0000f5e4, 0x0000005d, /* 0000005d //C 0f5e4 db	93 */
0x0000f5e5, 0x00000020, /* 00000020 //C 0f5e5 db	32 */
0x0000f5e6, 0x00000020, /* 00000020 //C 0f5e6 db	32 */
0x0000f5e7, 0x00000020, /* 00000020 //C 0f5e7 db	32 */
0x0000f5e8, 0x00000020, /* 00000020 //C 0f5e8 db	32 */
0x0000f5e9, 0x00000020, /* 00000020 //C 0f5e9 db	32 */
0x0000f5ea, 0x00000020, /* 00000020 //C 0f5ea db	32 */
0x0000f5eb, 0x00000020, /* 00000020 //C 0f5eb db	32 */
0x0000f5ec, 0x00000020, /* 00000020 //C 0f5ec db	32 */
0x0000f5ed, 0x00000020, /* 00000020 //C 0f5ed db	32 */
0x0000f5ee, 0x00000020, /* 00000020 //C 0f5ee db	32 */
0x0000f5ef, 0x00000047, /* 00000047 //C 0f5ef db	71 */
0x0000f5f0, 0x00000065, /* 00000065 //C 0f5f0 db	101 */
0x0000f5f1, 0x00000074, /* 00000074 //C 0f5f1 db	116 */
0x0000f5f2, 0x0000002f, /* 0000002f //C 0f5f2 db	47 */
0x0000f5f3, 0x00000073, /* 00000073 //C 0f5f3 db	115 */
0x0000f5f4, 0x00000065, /* 00000065 //C 0f5f4 db	101 */
0x0000f5f5, 0x00000074, /* 00000074 //C 0f5f5 db	116 */
0x0000f5f6, 0x00000020, /* 00000020 //C 0f5f6 db	32 */
0x0000f5f7, 0x00000052, /* 00000052 //C 0f5f7 db	82 */
0x0000f5f8, 0x00000031, /* 00000031 //C 0f5f8 db	49 */
0x0000f5f9, 0x00000034, /* 00000034 //C 0f5f9 db	52 */
0x0000f5fa, 0x0000000a, /* 0000000a //C 0f5fa db	10 */
0x0000f5fb, 0x00000000, /* 00000000 //C 0f5fb db */
0x0000f5fc, 0x00000070, /* 00000070 //C 0f5fc db	112 */
0x0000f5fd, 0x00000063, /* 00000063 //C 0f5fd db	99 */
0x0000f5fe, 0x00000020, /* 00000020 //C 0f5fe db	32 */
0x0000f5ff, 0x0000005b, /* 0000005b //C 0f5ff db	91 */
0x0000f600, 0x00000076, /* 00000076 //C 0f600 db	118 */
0x0000f601, 0x00000061, /* 00000061 //C 0f601 db	97 */
0x0000f602, 0x0000006c, /* 0000006c //C 0f602 db	108 */
0x0000f603, 0x0000005d, /* 0000005d //C 0f603 db	93 */
0x0000f604, 0x00000020, /* 00000020 //C 0f604 db	32 */
0x0000f605, 0x00000020, /* 00000020 //C 0f605 db	32 */
0x0000f606, 0x00000020, /* 00000020 //C 0f606 db	32 */
0x0000f607, 0x00000020, /* 00000020 //C 0f607 db	32 */
0x0000f608, 0x00000020, /* 00000020 //C 0f608 db	32 */
0x0000f609, 0x00000020, /* 00000020 //C 0f609 db	32 */
0x0000f60a, 0x00000020, /* 00000020 //C 0f60a db	32 */
0x0000f60b, 0x00000020, /* 00000020 //C 0f60b db	32 */
0x0000f60c, 0x00000020, /* 00000020 //C 0f60c db	32 */
0x0000f60d, 0x00000020, /* 00000020 //C 0f60d db	32 */
0x0000f60e, 0x00000047, /* 00000047 //C 0f60e db	71 */
0x0000f60f, 0x00000065, /* 00000065 //C 0f60f db	101 */
0x0000f610, 0x00000074, /* 00000074 //C 0f610 db	116 */
0x0000f611, 0x0000002f, /* 0000002f //C 0f611 db	47 */
0x0000f612, 0x00000073, /* 00000073 //C 0f612 db	115 */
0x0000f613, 0x00000065, /* 00000065 //C 0f613 db	101 */
0x0000f614, 0x00000074, /* 00000074 //C 0f614 db	116 */
0x0000f615, 0x00000020, /* 00000020 //C 0f615 db	32 */
0x0000f616, 0x00000052, /* 00000052 //C 0f616 db	82 */
0x0000f617, 0x00000031, /* 00000031 //C 0f617 db	49 */
0x0000f618, 0x00000035, /* 00000035 //C 0f618 db	53 */
0x0000f619, 0x0000000a, /* 0000000a //C 0f619 db	10 */
0x0000f61a, 0x00000000, /* 00000000 //C 0f61a db */
0x0000f61b, 0x00000066, /* 00000066 //C 0f61b db	102 */
0x0000f61c, 0x00000020, /* 00000020 //C 0f61c db	32 */
0x0000f61d, 0x0000005b, /* 0000005b //C 0f61d db	91 */
0x0000f61e, 0x00000076, /* 00000076 //C 0f61e db	118 */
0x0000f61f, 0x00000061, /* 00000061 //C 0f61f db	97 */
0x0000f620, 0x0000006c, /* 0000006c //C 0f620 db	108 */
0x0000f621, 0x0000005d, /* 0000005d //C 0f621 db	93 */
0x0000f622, 0x00000020, /* 00000020 //C 0f622 db	32 */
0x0000f623, 0x00000020, /* 00000020 //C 0f623 db	32 */
0x0000f624, 0x00000020, /* 00000020 //C 0f624 db	32 */
0x0000f625, 0x00000020, /* 00000020 //C 0f625 db	32 */
0x0000f626, 0x00000020, /* 00000020 //C 0f626 db	32 */
0x0000f627, 0x00000020, /* 00000020 //C 0f627 db	32 */
0x0000f628, 0x00000020, /* 00000020 //C 0f628 db	32 */
0x0000f629, 0x00000020, /* 00000020 //C 0f629 db	32 */
0x0000f62a, 0x00000020, /* 00000020 //C 0f62a db	32 */
0x0000f62b, 0x00000020, /* 00000020 //C 0f62b db	32 */
0x0000f62c, 0x00000020, /* 00000020 //C 0f62c db	32 */
0x0000f62d, 0x00000047, /* 00000047 //C 0f62d db	71 */
0x0000f62e, 0x00000065, /* 00000065 //C 0f62e db	101 */
0x0000f62f, 0x00000074, /* 00000074 //C 0f62f db	116 */
0x0000f630, 0x0000002f, /* 0000002f //C 0f630 db	47 */
0x0000f631, 0x00000073, /* 00000073 //C 0f631 db	115 */
0x0000f632, 0x00000065, /* 00000065 //C 0f632 db	101 */
0x0000f633, 0x00000074, /* 00000074 //C 0f633 db	116 */
0x0000f634, 0x00000020, /* 00000020 //C 0f634 db	32 */
0x0000f635, 0x00000066, /* 00000066 //C 0f635 db	102 */
0x0000f636, 0x0000006c, /* 0000006c //C 0f636 db	108 */
0x0000f637, 0x00000061, /* 00000061 //C 0f637 db	97 */
0x0000f638, 0x00000067, /* 00000067 //C 0f638 db	103 */
0x0000f639, 0x00000073, /* 00000073 //C 0f639 db	115 */
0x0000f63a, 0x0000000a, /* 0000000a //C 0f63a db	10 */
0x0000f63b, 0x00000000, /* 00000000 //C 0f63b db */
0x0000f63c, 0x00000068, /* 00000068 //C 0f63c db	104 */
0x0000f63d, 0x0000002c, /* 0000002c //C 0f63d db	44 */
0x0000f63e, 0x0000003f, /* 0000003f //C 0f63e db	63 */
0x0000f63f, 0x00000020, /* 00000020 //C 0f63f db	32 */
0x0000f640, 0x00000020, /* 00000020 //C 0f640 db	32 */
0x0000f641, 0x00000020, /* 00000020 //C 0f641 db	32 */
0x0000f642, 0x00000020, /* 00000020 //C 0f642 db	32 */
0x0000f643, 0x00000020, /* 00000020 //C 0f643 db	32 */
0x0000f644, 0x00000020, /* 00000020 //C 0f644 db	32 */
0x0000f645, 0x00000020, /* 00000020 //C 0f645 db	32 */
0x0000f646, 0x00000020, /* 00000020 //C 0f646 db	32 */
0x0000f647, 0x00000020, /* 00000020 //C 0f647 db	32 */
0x0000f648, 0x00000020, /* 00000020 //C 0f648 db	32 */
0x0000f649, 0x00000020, /* 00000020 //C 0f649 db	32 */
0x0000f64a, 0x00000020, /* 00000020 //C 0f64a db	32 */
0x0000f64b, 0x00000020, /* 00000020 //C 0f64b db	32 */
0x0000f64c, 0x00000020, /* 00000020 //C 0f64c db	32 */
0x0000f64d, 0x00000020, /* 00000020 //C 0f64d db	32 */
0x0000f64e, 0x00000048, /* 00000048 //C 0f64e db	72 */
0x0000f64f, 0x00000065, /* 00000065 //C 0f64f db	101 */
0x0000f650, 0x0000006c, /* 0000006c //C 0f650 db	108 */
0x0000f651, 0x00000070, /* 00000070 //C 0f651 db	112 */
0x0000f652, 0x0000000a, /* 0000000a //C 0f652 db	10 */
0x0000f653, 0x00000000, /* 00000000 //C 0f653 db */
0x0000f654, 0x00000000, /* 00000000 //C 0f654 dd	0 */
0x0000f696, 0x00000045, /* 00000045 //C 0f696 db	69 */
0x0000f697, 0x0000004f, /* 0000004f //C 0f697 db	79 */
0x0000f698, 0x00000046, /* 00000046 //C 0f698 db	70 */
0x0000f699, 0x00000020, /* 00000020 //C 0f699 db	32 */
0x0000f69a, 0x00000050, /* 00000050 //C 0f69a db	80 */
0x0000f69b, 0x0000004d, /* 0000004d //C 0f69b db	77 */
0x0000f69c, 0x0000006f, /* 0000006f //C 0f69c db	111 */
0x0000f69d, 0x0000006e, /* 0000006e //C 0f69d db	110 */
0x0000f69e, 0x00000069, /* 00000069 //C 0f69e db	105 */
0x0000f69f, 0x00000074, /* 00000074 //C 0f69f db	116 */
0x0000f6a0, 0x0000006f, /* 0000006f //C 0f6a0 db	111 */
0x0000f6a1, 0x00000072, /* 00000072 //C 0f6a1 db	114 */
0x0000f6a2, 0x0000000a, /* 0000000a //C 0f6a2 db	10 */
0x0000f6a3, 0x00000000, /* 00000000 //C 0f6a3 db */
0xffffffff, 0xffffffff
};
