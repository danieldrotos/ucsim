#include "pmon.h"

const char * p12cpu_version= "2.2.5";

t_mem pmon[]= {
0x00000000, 0x01f2f03c, /* 01f2f03c //C 00000    21 jmp	cold_start */
0x0000f000, 0x01f2f025, /* 01f2f025 //C 0f000    26 _f000:	jmp	callin */
0x0000f001, 0x01f2f016, /* 01f2f016 //C 0f001    27 _f001:	jmp	enter_by_uart */
0x0000f002, 0x01f2f48c, /* 01f2f48c //C 0f002    28 _f002:	jmp	getchar */
0x0000f003, 0x00f00e00, /* 00f00e00 //C 0f003    29 _f003:	ret */
0x0000f004, 0x00f00e00, /* 00f00e00 //C 0f004    30 _f004:	ret */
0x0000f005, 0x01f2f03c, /* 01f2f03c //C 0f005    31 _f005:	jmp	cold_start */
0x0000f006, 0x01f2f39e, /* 01f2f39e //C 0f006    32 _f006:	jmp	strchr */
0x0000f007, 0x01f2f410, /* 01f2f410 //C 0f007    33 _f007:	jmp	streq */
0x0000f008, 0x01f2f481, /* 01f2f481 //C 0f008    34 _f008:	jmp	check_uart */
0x0000f009, 0x01f2f420, /* 01f2f420 //C 0f009    35 _f009:	jmp	hexchar2value */
0x0000f00a, 0x01f2f44f, /* 01f2f44f //C 0f00a    36 _f00a:	jmp	value2hexchar */
0x0000f00b, 0x01f2f453, /* 01f2f453 //C 0f00b    37 _f00b:	jmp	htoi */
0x0000f00c, 0x01f2f418, /* 01f2f418 //C 0f00c    38 _f00c:	jmp	strieq */
0x0000f00d, 0x01f2f489, /* 01f2f489 //C 0f00d    39 _f00d:	jmp	read */
0x0000f00e, 0x01f2f490, /* 01f2f490 //C 0f00e    40 _f00e:	jmp	putchar */
0x0000f00f, 0x01f2f497, /* 01f2f497 //C 0f00f    41 _f00f:	jmp	prints */
0x0000f010, 0x01f2f4d0, /* 01f2f4d0 //C 0f010    42 _f010:	jmp	printsnl */
0x0000f011, 0x01f2f4d7, /* 01f2f4d7 //C 0f011    43 _f011:	jmp	print_vhex */
0x0000f012, 0x01f2f4b6, /* 01f2f4b6 //C 0f012    44 _f012:	jmp	pes */
0x0000f013, 0x01f2f555, /* 01f2f555 //C 0f013    45 _f013:	jmp	printd */
0x0000f014, 0x01f2f55a, /* 01f2f55a //C 0f014    46 _f014:	jmp	printf */
0x0000f015, 0x01f2f5d8, /* 01f2f5d8 //C 0f015    47 _f015:	jmp	pesf */
0x0000f016, 0x0d0d0000, /* 0d0d0000 //C 0f016    50 push	r0 */
0x0000f017, 0x020e0000, /* 020e0000 //C 0f017    51 getf	r0 */
0x0000f018, 0x0d0d0000, /* 0d0d0000 //C 0f018    52 push	r0 */
0x0000f019, 0x0700ff42, /* 0700ff42 //C 0f019    53 ld	r0,UART_RSTAT */
0x0000f01a, 0x010c0001, /* 010c0001 //C 0f01a    54 test	r0,1 */
0x0000f01b, 0x21f2f020, /* 21f2f020 //C 0f01b    55 jnz	ebu_callin */
0x0000f01c, 0x0f0d0000, /* 0f0d0000 //C 0f01c    57 pop	r0 */
0x0000f01d, 0x020f0000, /* 020f0000 //C 0f01d    58 setf	r0 */
0x0000f01e, 0x0f0d0000, /* 0f0d0000 //C 0f01e    59 pop	r0 */
0x0000f01f, 0x00f00e00, /* 00f00e00 //C 0f01f    60 ret */
0x0000f020, 0x0700ff40, /* 0700ff40 //C 0f020    62 ld	r0,UART_DR */
0x0000f021, 0x0f0d0000, /* 0f0d0000 //C 0f021    63 pop	r0 */
0x0000f022, 0x020f0000, /* 020f0000 //C 0f022    64 setf	r0 */
0x0000f023, 0x0f0d0000, /* 0f0d0000 //C 0f023    65 pop	r0 */
0x0000f024, 0x01f2f025, /* 01f2f025 //C 0f024    66 jmp	callin */
0x0000f025, 0x0600f64f, /* 0600f64f //C 0f025    69 st	r0,reg0 */
0x0000f026, 0x0610f650, /* 0610f650 //C 0f026    70 st	r1,reg1 */
0x0000f027, 0x0620f651, /* 0620f651 //C 0f027    71 st	r2,reg2 */
0x0000f028, 0x0630f652, /* 0630f652 //C 0f028    72 st	r3,reg3 */
0x0000f029, 0x0640f653, /* 0640f653 //C 0f029    73 st	r4,reg4 */
0x0000f02a, 0x0650f654, /* 0650f654 //C 0f02a    74 st	r5,reg5 */
0x0000f02b, 0x0660f655, /* 0660f655 //C 0f02b    75 st	r6,reg6 */
0x0000f02c, 0x0670f656, /* 0670f656 //C 0f02c    76 st	r7,reg7 */
0x0000f02d, 0x0680f657, /* 0680f657 //C 0f02d    77 st	r8,reg8 */
0x0000f02e, 0x0690f658, /* 0690f658 //C 0f02e    78 st	r9,reg9 */
0x0000f02f, 0x06a0f659, /* 06a0f659 //C 0f02f    79 st	r10,reg10 */
0x0000f030, 0x06b0f65a, /* 06b0f65a //C 0f030    80 st	r11,reg11 */
0x0000f031, 0x06c0f65b, /* 06c0f65b //C 0f031    81 st	r12,reg12 */
0x0000f032, 0x06d0f65c, /* 06d0f65c //C 0f032    82 st	r13,reg13 */
0x0000f033, 0x06e0f65d, /* 06e0f65d //C 0f033    83 st	r14,reg14 */
0x0000f034, 0x06e0f65e, /* 06e0f65e //C 0f034    84 st	r14,reg15 */
0x0000f035, 0x020e0000, /* 020e0000 //C 0f035    85 getf	r0 */
0x0000f036, 0x0600f65f, /* 0600f65f //C 0f036    86 st	r0,regf */
0x0000f037, 0x01020001, /* 01020001 //C 0f037    87 mvzl	r0,1 */
0x0000f038, 0x0600f64d, /* 0600f64d //C 0f038    88 st	r0,called */
0x0000f039, 0x01f2f046, /* 01f2f046 //C 0f039    89 jmp	common_start */
0x0000f03a, 0x01f2f046, /* 01f2f046 //C 0f03a    91 jmp	common_start */
0x0000f03b, 0x01f2f03c, /* 01f2f03c //C 0f03b    93 jmp	cold_start */
0x0000f03c, 0x01020000, /* 01020000 //C 0f03c    95 mvzl	r0,0 */
0x0000f03d, 0x0600f64d, /* 0600f64d //C 0f03d    96 st	r0,called */
0x0000f03e, 0x0102f03b, /* 0102f03b //C 0f03e    97 mvzl	r0,def_zero	; restore jmp to monitor at zero */
0x0000f03f, 0x0e000000, /* 0e000000 //C 0f03f    98 ld	r0,r0 */
0x0000f040, 0x06000000, /* 06000000 //C 0f040    99 st	r0,0 */
0x0000f041, 0x01020000, /* 01020000 //C 0f041   100 mvzl	r0,0		; def values of some regs */
0x0000f042, 0x0600f65f, /* 0600f65f //C 0f042   101 st	r0,regf		; FALGS= 0 */
0x0000f043, 0x0102f7ff, /* 0102f7ff //C 0f043   102 mvzl	r0,0xf7ff	; R13= 0xf7ff */
0x0000f044, 0x0600f65c, /* 0600f65c //C 0f044   103 st	r0,reg13 */
0x0000f045, 0x01f2f046, /* 01f2f046 //C 0f045   104 jmp	common_start: */
0x0000f046, 0x01d2f89f, /* 01d2f89f //C 0f046   107 mvzl	sp,stack_end */
0x0000f047, 0x01020001, /* 01020001 //C 0f047   108 mvzl	r0,1 */
0x0000f048, 0x0600f64c, /* 0600f64c //C 0f048   109 st	r0,echo */
0x0000f049, 0x01020000, /* 01020000 //C 0f049   110 mvzl	r0,0 */
0x0000f04a, 0x020f0000, /* 020f0000 //C 0f04a   111 setf	r0 */
0x0000f04b, 0x0710ff41, /* 0710ff41 //C 0f04b   116 ld	r1,UART_CTRL	; check if transmit is enabled */
0x0000f04c, 0x011c0002, /* 011c0002 //C 0f04c   117 test	r1,2 */
0x0000f04d, 0x11f2f051, /* 11f2f051 //C 0f04d   118 jz	tr_is_off */
0x0000f04e, 0x0710ff43, /* 0710ff43 //C 0f04e   120 ld	r1,UART_TSTAT	; if transmit is ongoing */
0x0000f04f, 0x011c0001, /* 011c0001 //C 0f04f   121 test	r1,1		; wait it to finish */
0x0000f050, 0x11f2f04e, /* 11f2f04e //C 0f050   122 jz	wait_uart_tr */
0x0000f051, 0x01120003, /* 01120003 //C 0f051   124 mvzl	r1,3		; turn on rx and tx */
0x0000f052, 0x0610ff41, /* 0610ff41 //C 0f052   125 st	r1,UART_CTRL */
0x0000f053, 0x0102000a, /* 0102000a //C 0f053   128 mvzl	r0,LF */
0x0000f054, 0x0400f490, /* 0400f490 //C 0f054   129 call	putchar */
0x0000f055, 0x0102f660, /* 0102f660 //C 0f055   130 mvzl	r0,msg_start */
0x0000f056, 0x0400f4d0, /* 0400f4d0 //C 0f056   131 call	printsnl */
0x0000f057, 0x0700f64d, /* 0700f64d //C 0f057   133 ld	r0,called */
0x0000f058, 0x020b0000, /* 020b0000 //C 0f058   134 sz	r0 */
0x0000f059, 0x11f2f063, /* 11f2f063 //C 0f059   135 jz	no_called_from */
0x0000f05a, 0x0102000a, /* 0102000a //C 0f05a   136 mvzl	r0,LF */
0x0000f05b, 0x0400f490, /* 0400f490 //C 0f05b   137 call	putchar */
0x0000f05c, 0x0102f66e, /* 0102f66e //C 0f05c   138 mvzl	r0,msg_stopat */
0x0000f05d, 0x0400f497, /* 0400f497 //C 0f05d   139 call	prints */
0x0000f05e, 0x0700f65d, /* 0700f65d //C 0f05e   140 ld	r0,reg14 */
0x0000f05f, 0x01120004, /* 01120004 //C 0f05f   141 mvzl	r1,4 */
0x0000f060, 0x0400f4d7, /* 0400f4d7 //C 0f060   142 call	print_vhex */
0x0000f061, 0x0102000a, /* 0102000a //C 0f061   143 mvzl	r0,LF */
0x0000f062, 0x0400f490, /* 0400f490 //C 0f062   144 call	putchar */
0x0000f063, 0x0400f065, /* 0400f065 //C 0f063   148 call	setup_line */
0x0000f064, 0x01f2f06e, /* 01f2f06e //C 0f064   152 jmp	main */
0x0000f065, 0x0ded0000, /* 0ded0000 //C 0f065   158 push	lr */
0x0000f066, 0x01120000, /* 01120000 //C 0f066   159 mvzl	r1,0		; lptr= 0 */
0x0000f067, 0x0610f645, /* 0610f645 //C 0f067   160 st	r1,line_ptr */
0x0000f068, 0x0610f5e1, /* 0610f5e1 //C 0f068   161 st	r1,line		; line[0]= 0 */
0x0000f069, 0x01120000, /* 01120000 //C 0f069   162 mvzl	r1,0		; at_eol= 0 */
0x0000f06a, 0x0610f646, /* 0610f646 //C 0f06a   163 st	r1,at_eol */
0x0000f06b, 0x0102f67c, /* 0102f67c //C 0f06b   165 mvzl	r0,prompt */
0x0000f06c, 0x0400f497, /* 0400f497 //C 0f06c   166 call	prints */
0x0000f06d, 0x0ffd0000, /* 0ffd0000 //C 0f06d   167 pop	pc */
0x0000f06e, 0x0400f481, /* 0400f481 //C 0f06e   174 call	check_uart */
0x0000f06f, 0x41f2f075, /* 41f2f075 //C 0f06f   175 C0 jmp	no_input */
0x0000f070, 0x0400f489, /* 0400f489 //C 0f070   177 call	read */
0x0000f071, 0x0400f076, /* 0400f076 //C 0f071   178 call	proc_input */
0x0000f072, 0x41f2f075, /* 41f2f075 //C 0f072   179 C0 jmp	no_line */
0x0000f073, 0x0400f0a7, /* 0400f0a7 //C 0f073   182 call	proc_line */
0x0000f074, 0x0400f065, /* 0400f065 //C 0f074   183 call	setup_line */
0x0000f075, 0x01f2f06e, /* 01f2f06e //C 0f075   186 jmp	main */
0x0000f076, 0x0ded0000, /* 0ded0000 //C 0f076   192 push	lr */
0x0000f077, 0x0108000a, /* 0108000a //C 0f077   193 cmp	r0,LF */
0x0000f078, 0x11f2f0a1, /* 11f2f0a1 //C 0f078   194 EQ jmp	got_eol */
0x0000f079, 0x0108000d, /* 0108000d //C 0f079   195 cmp	r0,CR */
0x0000f07a, 0x11f2f0a1, /* 11f2f0a1 //C 0f07a   196 EQ jmp	got_eol */
0x0000f07b, 0x01080008, /* 01080008 //C 0f07b   197 cmp	r0,8 */
0x0000f07c, 0x11f2f080, /* 11f2f080 //C 0f07c   198 jz	got_BS */
0x0000f07d, 0x0108007f, /* 0108007f //C 0f07d   199 cmp	r0,127 */
0x0000f07e, 0x11f2f080, /* 11f2f080 //C 0f07e   200 jz	got_DEL */
0x0000f07f, 0x01f2f08c, /* 01f2f08c //C 0f07f   201 jmp	got_char */
0x0000f080, 0x0700f645, /* 0700f645 //C 0f080   204 ld	r0,line_ptr */
0x0000f081, 0x020b0000, /* 020b0000 //C 0f081   205 sz	r0 */
0x0000f082, 0x11f2f08a, /* 11f2f08a //C 0f082   206 jz	got_done */
0x0000f083, 0x01060001, /* 01060001 //C 0f083   207 sub	r0,1 */
0x0000f084, 0x0600f645, /* 0600f645 //C 0f084   208 st	r0,line_ptr */
0x0000f085, 0x0112f5e1, /* 0112f5e1 //C 0f085   209 mvzl	r1,line */
0x0000f086, 0x01220000, /* 01220000 //C 0f086   210 mvzl	r2,0 */
0x0000f087, 0x08210000, /* 08210000 //C 0f087   211 st	r2,r1,r0 */
0x0000f088, 0x0102f678, /* 0102f678 //C 0f088   212 mvzl	r0,msg_BS */
0x0000f089, 0x0400f497, /* 0400f497 //C 0f089   213 call	prints */
0x0000f08a, 0x020d0000, /* 020d0000 //C 0f08a   215 clc */
0x0000f08b, 0x01f2f0a6, /* 01f2f0a6 //C 0f08b   216 jmp	proc_input_ret */
0x0000f08c, 0x0108001f, /* 0108001f //C 0f08c   218 cmp	r0,31		; refuse control chars */
0x0000f08d, 0xa1f2f0a6, /* a1f2f0a6 //C 0f08d   219 LS jmp	proc_input_ret */
0x0000f08e, 0x0108007e, /* 0108007e //C 0f08e   220 cmp	r0,126		; refuse graph chars */
0x0000f08f, 0x91f2f0a6, /* 91f2f0a6 //C 0f08f   221 HI jmp	proc_input_ret */
0x0000f090, 0x01220000, /* 01220000 //C 0f090   222 mvzl	r2,0		; at_aol= 0 */
0x0000f091, 0x0620f646, /* 0620f646 //C 0f091   223 st	r2,at_eol */
0x0000f092, 0x0112f645, /* 0112f645 //C 0f092   224 mvzl	r1,line_ptr	; line[line_ptr]= char */
0x0000f093, 0x0e310000, /* 0e310000 //C 0f093   225 ld	r3,r1 */
0x0000f094, 0x0122f5e1, /* 0122f5e1 //C 0f094   226 mvzl	r2,line */
0x0000f095, 0x08020300, /* 08020300 //C 0f095   227 st	r0,r2,r3 */
0x0000f096, 0x013a0001, /* 013a0001 //C 0f096   229 plus	r3,1		; line_ptr++ */
0x0000f097, 0x0c310000, /* 0c310000 //C 0f097   230 st	r3,r1 */
0x0000f098, 0x01420000, /* 01420000 //C 0f098   231 mvzl	r4,0 */
0x0000f099, 0x09438200, /* 09438200 //C 0f099   232 st	r4,r3+,r2	; line[line_ptr]= 0 */
0x0000f09a, 0x08430200, /* 08430200 //C 0f09a   233 st	r4,r3,r2	; double 0 at end, needed by tokenizer */
0x0000f09b, 0x0142f64c, /* 0142f64c //C 0f09b   234 mvzl	r4,echo		; check if echo is turned on */
0x0000f09c, 0x0e440000, /* 0e440000 //C 0f09c   235 ld	r4,r4 */
0x0000f09d, 0x024b0000, /* 024b0000 //C 0f09d   236 sz	r4 */
0x0000f09e, 0x2400f490, /* 2400f490 //C 0f09e   237 NZ call	putchar		; echo */
0x0000f09f, 0x020d0000, /* 020d0000 //C 0f09f   238 clc */
0x0000f0a0, 0x01f2f0a6, /* 01f2f0a6 //C 0f0a0   239 jmp	proc_input_ret */
0x0000f0a1, 0x0112f646, /* 0112f646 //C 0f0a1   241 mvzl	r1,at_eol */
0x0000f0a2, 0x0e110000, /* 0e110000 //C 0f0a2   242 ld	r1,r1 */
0x0000f0a3, 0x021b0000, /* 021b0000 //C 0f0a3   243 sz	r1		; Z=0 at eol -> skip, not ready */
0x0000f0a4, 0x220d0000, /* 220d0000 //C 0f0a4   244 Z0 clc */
0x0000f0a5, 0x120c0000, /* 120c0000 //C 0f0a5   245 Z1 sec */
0x0000f0a6, 0x0ffd0000, /* 0ffd0000 //C 0f0a6   247 pop	pc */
0x0000f0a7, 0x0ded0000, /* 0ded0000 //C 0f0a7   256 push	lr */
0x0000f0a8, 0x0102000a, /* 0102000a //C 0f0a8   258 mvzl	r0,LF */
0x0000f0a9, 0x0400f490, /* 0400f490 //C 0f0a9   259 call	putchar */
0x0000f0aa, 0x0700f5e1, /* 0700f5e1 //C 0f0aa   261 ld	r0,line */
0x0000f0ab, 0x020b0000, /* 020b0000 //C 0f0ab   262 sz	r0 */
0x0000f0ac, 0x11f2f0b4, /* 11f2f0b4 //C 0f0ac   263 jz	proc_line_ret */
0x0000f0ad, 0x0400f0d0, /* 0400f0d0 //C 0f0ad   271 call	tokenize */
0x0000f0ae, 0x0400f0f0, /* 0400f0f0 //C 0f0ae   282 call	find_cmd */
0x0000f0af, 0x41f2f0b2, /* 41f2f0b2 //C 0f0af   283 C0 jmp	cmd_not_found */
0x0000f0b0, 0x05000000, /* 05000000 //C 0f0b0   286 call	r0,0 */
0x0000f0b1, 0x01f2f0b4, /* 01f2f0b4 //C 0f0b1   288 jmp	proc_line_ret */
0x0000f0b2, 0x0102f0bc, /* 0102f0bc //C 0f0b2   290 mvzl	r0,snotfound */
0x0000f0b3, 0x0400f4d0, /* 0400f4d0 //C 0f0b3   291 call	printsnl */
0x0000f0b4, 0x01120001, /* 01120001 //C 0f0b4   294 mvzl	r1,1		; at_eol= 1 */
0x0000f0b5, 0x0610f646, /* 0610f646 //C 0f0b5   295 st	r1,at_eol */
0x0000f0b6, 0x0ffd0000, /* 0ffd0000 //C 0f0b6   296 pop	pc */
0x0000f0b7, 0x00000047, /* 00000047 //C 0f0b7   298 db	71 */
0x0000f0b8, 0x0000006f, /* 0000006f //C 0f0b8   298 db	111 */
0x0000f0b9, 0x00000074, /* 00000074 //C 0f0b9   298 db	116 */
0x0000f0ba, 0x0000003a, /* 0000003a //C 0f0ba   298 db	58 */
0x0000f0bb, 0x00000000, /* 00000000 //C 0f0bb   298 db */
0x0000f0bc, 0x00000055, /* 00000055 //C 0f0bc   299 db	85 */
0x0000f0bd, 0x0000006e, /* 0000006e //C 0f0bd   299 db	110 */
0x0000f0be, 0x0000006b, /* 0000006b //C 0f0be   299 db	107 */
0x0000f0bf, 0x0000006e, /* 0000006e //C 0f0bf   299 db	110 */
0x0000f0c0, 0x0000006f, /* 0000006f //C 0f0c0   299 db	111 */
0x0000f0c1, 0x00000077, /* 00000077 //C 0f0c1   299 db	119 */
0x0000f0c2, 0x0000006e, /* 0000006e //C 0f0c2   299 db	110 */
0x0000f0c3, 0x00000020, /* 00000020 //C 0f0c3   299 db	32 */
0x0000f0c4, 0x00000063, /* 00000063 //C 0f0c4   299 db	99 */
0x0000f0c5, 0x0000006f, /* 0000006f //C 0f0c5   299 db	111 */
0x0000f0c6, 0x0000006d, /* 0000006d //C 0f0c6   299 db	109 */
0x0000f0c7, 0x0000006d, /* 0000006d //C 0f0c7   299 db	109 */
0x0000f0c8, 0x00000061, /* 00000061 //C 0f0c8   299 db	97 */
0x0000f0c9, 0x0000006e, /* 0000006e //C 0f0c9   299 db	110 */
0x0000f0ca, 0x00000064, /* 00000064 //C 0f0ca   299 db	100 */
0x0000f0cb, 0x00000000, /* 00000000 //C 0f0cb   299 db */
0x0000f0cc, 0x0ded0000, /* 0ded0000 //C 0f0cc   307 push	lr */
0x0000f0cd, 0x0112f67e, /* 0112f67e //C 0f0cd   308 mvzl	r1,delimiters */
0x0000f0ce, 0x0400f39e, /* 0400f39e //C 0f0ce   309 call	strchr */
0x0000f0cf, 0x0ffd0000, /* 0ffd0000 //C 0f0cf   310 pop	pc */
0x0000f0d0, 0x0ded0000, /* 0ded0000 //C 0f0d0   319 push	lr */
0x0000f0d1, 0x0142f647, /* 0142f647 //C 0f0d1   320 mvzl	r4,words	; array of result */
0x0000f0d2, 0x0152f5e1, /* 0152f5e1 //C 0f0d2   321 mvzl	r5,line		; address of next char */
0x0000f0d3, 0x01620000, /* 01620000 //C 0f0d3   322 mvzl	r6,0		; nuof words found */
0x0000f0d4, 0x01720000, /* 01720000 //C 0f0d4   323 mvzl	r7,0		; bool in_word */
0x0000f0d5, 0x0e050000, /* 0e050000 //C 0f0d5   325 ld	r0,r5		; pick a char */
0x0000f0d6, 0x020b0000, /* 020b0000 //C 0f0d6   326 sz	r0		; check end */
0x0000f0d7, 0x11f2f0e1, /* 11f2f0e1 //C 0f0d7   327 jz	tok_delimiter	; found end, pretend delim */
0x0000f0d8, 0x0400f0cc, /* 0400f0cc //C 0f0d8   329 call	is_delimiter */
0x0000f0d9, 0x31f2f0e1, /* 31f2f0e1 //C 0f0d9   330 C1 jmp	tok_delimiter */
0x0000f0da, 0x027b0000, /* 027b0000 //C 0f0da   332 sz	r7 */
0x0000f0db, 0x21f2f0e6, /* 21f2f0e6 //C 0f0db   333 jnz	tok_next	; still inside word */
0x0000f0dc, 0x01720001, /* 01720001 //C 0f0dc   335 mvzl	r7,1		; in_word=true */
0x0000f0dd, 0x09568400, /* 09568400 //C 0f0dd   336 st	r5,r6+,r4	; record word address */
0x0000f0de, 0x01680005, /* 01680005 //C 0f0de   337 cmp	r6,MAX_WORDS	; If no more space */
0x0000f0df, 0x11f2f0ea, /* 11f2f0ea //C 0f0df   338 EQ jmp	tok_ret		; then return */
0x0000f0e0, 0x01f2f0e6, /* 01f2f0e6 //C 0f0e0   339 jmp	tok_next */
0x0000f0e1, 0x027b0000, /* 027b0000 //C 0f0e1   341 sz	r7 */
0x0000f0e2, 0x11f2f0e6, /* 11f2f0e6 //C 0f0e2   342 jz	tok_next	; still between words */
0x0000f0e3, 0x01720000, /* 01720000 //C 0f0e3   344 mvzl	r7,0		; in_word=false */
0x0000f0e4, 0x01120000, /* 01120000 //C 0f0e4   345 mvzl	r1,0		; put a 0 at the end of word */
0x0000f0e5, 0x08150100, /* 08150100 //C 0f0e5   346 st	r1,r5,r1 */
0x0000f0e6, 0x020b0000, /* 020b0000 //C 0f0e6   348 sz	r0		; check EOL */
0x0000f0e7, 0x11f2f0ea, /* 11f2f0ea //C 0f0e7   349 jz	tok_ret		; jump out if char==0 */
0x0000f0e8, 0x01540001, /* 01540001 //C 0f0e8   350 add	r5,1 */
0x0000f0e9, 0x01f2f0d5, /* 01f2f0d5 //C 0f0e9   351 jmp	tok_cycle */
0x0000f0ea, 0x01120000, /* 01120000 //C 0f0ea   353 mvzl	r1,0 */
0x0000f0eb, 0x01680005, /* 01680005 //C 0f0eb   354 cmp	r6,MAX_WORDS */
0x0000f0ec, 0x11f2f0ef, /* 11f2f0ef //C 0f0ec   355 jz	tok_end */
0x0000f0ed, 0x09168400, /* 09168400 //C 0f0ed   356 st	r1,r6+,r4 */
0x0000f0ee, 0x01f2f0ea, /* 01f2f0ea //C 0f0ee   357 jmp	tok_ret */
0x0000f0ef, 0x0ffd0000, /* 0ffd0000 //C 0f0ef   359 pop	pc */
0x0000f0f0, 0x0ded0000, /* 0ded0000 //C 0f0f0   368 push	lr */
0x0000f0f1, 0x0d1d0000, /* 0d1d0000 //C 0f0f1   369 push	r1 */
0x0000f0f2, 0x0d2d0000, /* 0d2d0000 //C 0f0f2   370 push	r2 */
0x0000f0f3, 0x0d3d0000, /* 0d3d0000 //C 0f0f3   371 push	r3 */
0x0000f0f4, 0x0dad0000, /* 0dad0000 //C 0f0f4   372 push	r10 */
0x0000f0f5, 0x0700f647, /* 0700f647 //C 0f0f5   373 ld	r0,words	; R0= 1st word of command */
0x0000f0f6, 0x020b0000, /* 020b0000 //C 0f0f6   374 sz	r0 */
0x0000f0f7, 0x11f2f127, /* 11f2f127 //C 0f0f7   375 jz	find_cmd_false */
0x0000f0f8, 0x0e100000, /* 0e100000 //C 0f0f8   378 ld	r1,r0		; 1st char of word1 */
0x0000f0f9, 0x0e200001, /* 0e200001 //C 0f0f9   379 ld	r2,r0,1		; 2nd char */
0x0000f0fa, 0x0e300002, /* 0e300002 //C 0f0fa   380 ld	r3,r0,2		; 3rd char */
0x0000f0fb, 0x011fffdf, /* 011fffdf //C 0f0fb   381 and	r1,0xffdf	; upcase 1st char */
0x0000f0fc, 0x01180052, /* 01180052 //C 0f0fc   382 cmp	r1,'R' */
0x0000f0fd, 0x21f2f113, /* 21f2f113 //C 0f0fd   383 jnz	find_not_rx */
0x0000f0fe, 0x0128002f, /* 0128002f //C 0f0fe   384 cmp	r2,'/'		; '0'-1 */
0x0000f0ff, 0xa1f2f113, /* a1f2f113 //C 0f0ff   385 LS jmp	find_not_rx */
0x0000f100, 0x01280039, /* 01280039 //C 0f100   386 cmp	r2,'9' */
0x0000f101, 0x91f2f113, /* 91f2f113 //C 0f101   387 HI jmp	find_not_rx */
0x0000f102, 0x023b0000, /* 023b0000 //C 0f102   388 sz	r3 */
0x0000f103, 0x11f2f10e, /* 11f2f10e //C 0f103   389 jz	find_rx_09 */
0x0000f104, 0x01280031, /* 01280031 //C 0f104   391 cmp	r2,'1'		; first char must be '1' */
0x0000f105, 0x21f2f113, /* 21f2f113 //C 0f105   392 jnz	find_not_rx */
0x0000f106, 0x0138002f, /* 0138002f //C 0f106   393 cmp	r3,'/'		; '0'-1 */
0x0000f107, 0xa1f2f113, /* a1f2f113 //C 0f107   394 LS jmp	find_not_rx */
0x0000f108, 0x01380035, /* 01380035 //C 0f108   395 cmp	r3,'5' */
0x0000f109, 0x91f2f113, /* 91f2f113 //C 0f109   396 HI jmp	find_not_rx */
0x0000f10a, 0x01360030, /* 01360030 //C 0f10a   397 sub	r3,'0' */
0x0000f10b, 0x0134000a, /* 0134000a //C 0f10b   398 add	r3,10 */
0x0000f10c, 0x0630f64e, /* 0630f64e //C 0f10c   399 st	r3,nuof_reg */
0x0000f10d, 0x01f2f110, /* 01f2f110 //C 0f10d   400 jmp	find_rx */
0x0000f10e, 0x01260030, /* 01260030 //C 0f10e   402 sub	r2,'0' */
0x0000f10f, 0x0620f64e, /* 0620f64e //C 0f10f   403 st	r2,nuof_reg */
0x0000f110, 0x0102f35d, /* 0102f35d //C 0f110   405 mvzl	r0,cmd_rx */
0x0000f111, 0x020c0000, /* 020c0000 //C 0f111   406 sec */
0x0000f112, 0x01f2f132, /* 01f2f132 //C 0f112   407 jmp	find_cmd_ret */
0x0000f113, 0x01a2f69a, /* 01a2f69a //C 0f113   410 mvzl	r10,commands */
0x0000f114, 0x0e2a0000, /* 0e2a0000 //C 0f114   412 ld	r2,r10		; R2= cmd addr */
0x0000f115, 0x022b0000, /* 022b0000 //C 0f115   413 sz	r2 */
0x0000f116, 0x11f2f127, /* 11f2f127 //C 0f116   414 jz	find_cmd_false */
0x0000f117, 0x01a40001, /* 01a40001 //C 0f117   415 add	r10,1 */
0x0000f118, 0x00100a00, /* 00100a00 //C 0f118   416 mov	r1,r10		; R1= cmd string */
0x0000f119, 0x01a40001, /* 01a40001 //C 0f119   419 add	r10,1 */
0x0000f11a, 0x0e3a0000, /* 0e3a0000 //C 0f11a   420 ld	r3,r10 */
0x0000f11b, 0x023b0000, /* 023b0000 //C 0f11b   421 sz	r3 */
0x0000f11c, 0x21f2f119, /* 21f2f119 //C 0f11c   422 jnz	find_cmd_fw */
0x0000f11d, 0x01a40001, /* 01a40001 //C 0f11d   423 add	r10,1 */
0x0000f11e, 0x0400f410, /* 0400f410 //C 0f11e   425 call	streq */
0x0000f11f, 0x41f2f114, /* 41f2f114 //C 0f11f   426 C0 jmp	find_cmd_cyc */
0x0000f120, 0x00000200, /* 00000200 //C 0f120   428 mov	r0,r2 */
0x0000f121, 0x020c0000, /* 020c0000 //C 0f121   429 sec */
0x0000f122, 0x01f2f132, /* 01f2f132 //C 0f122   430 jmp	find_cmd_ret */
0x0000f123, 0x0000002f, /* 0000002f //C 0f123   431 db	47 */
0x0000f124, 0x0000002f, /* 0000002f //C 0f124   431 db	47 */
0x0000f125, 0x00000043, /* 00000043 //C 0f125   431 db	67 */
0x0000f126, 0x00000000, /* 00000000 //C 0f126   431 db */
0x0000f127, 0x01040001, /* 01040001 //C 0f127   433 add	r0,1		; check second word */
0x0000f128, 0x0e100000, /* 0e100000 //C 0f128   434 ld	r1,r0		; for //C command */
0x0000f129, 0x021b0000, /* 021b0000 //C 0f129   435 sz	r1 */
0x0000f12a, 0x11f2f130, /* 11f2f130 //C 0f12a   436 jz	find_cmd_very_false */
0x0000f12b, 0x0102f123, /* 0102f123 //C 0f12b   437 mvzl	r0,c_cmd_name */
0x0000f12c, 0x0400f410, /* 0400f410 //C 0f12c   438 call	streq */
0x0000f12d, 0x21f2f130, /* 21f2f130 //C 0f12d   439 jnz	find_cmd_very_false */
0x0000f12e, 0x0122f1e5, /* 0122f1e5 //C 0f12e   440 mvzl	r2,cmd_c */
0x0000f12f, 0x01f2f120, /* 01f2f120 //C 0f12f   441 jmp	find_cmd_true */
0x0000f130, 0x020d0000, /* 020d0000 //C 0f130   443 clc */
0x0000f131, 0x01020000, /* 01020000 //C 0f131   444 mvzl	r0,0 */
0x0000f132, 0x0fad0000, /* 0fad0000 //C 0f132   446 pop	r10 */
0x0000f133, 0x0f3d0000, /* 0f3d0000 //C 0f133   447 pop	r3 */
0x0000f134, 0x0f2d0000, /* 0f2d0000 //C 0f134   448 pop	r2 */
0x0000f135, 0x0f1d0000, /* 0f1d0000 //C 0f135   449 pop	r1 */
0x0000f136, 0x0ffd0000, /* 0ffd0000 //C 0f136   450 pop	pc */
0x0000f137, 0x0ded0000, /* 0ded0000 //C 0f137   455 push	lr */
0x0000f138, 0x0122f647, /* 0122f647 //C 0f138   456 mvzl	r2,words */
0x0000f139, 0x01020000, /* 01020000 //C 0f139   457 mvzl	r0,0 */
0x0000f13a, 0x0e420001, /* 0e420001 //C 0f13a   459 ld	r4,r2,1		; addr */
0x0000f13b, 0x0e520002, /* 0e520002 //C 0f13b   460 ld	r5,r2,2		; value */
0x0000f13c, 0x024b0000, /* 024b0000 //C 0f13c   461 sz 	r4 */
0x0000f13d, 0x11f2f163, /* 11f2f163 //C 0f13d   462 jz	m_ret */
0x0000f13e, 0x00000400, /* 00000400 //C 0f13e   464 mov	r0,r4 */
0x0000f13f, 0x0400f453, /* 0400f453 //C 0f13f   465 call	htoi */
0x0000f140, 0x00400100, /* 00400100 //C 0f140   466 mov	r4,r1 */
0x0000f141, 0x31f2f145, /* 31f2f145 //C 0f141   467 C1 jmp	m_addr_ok */
0x0000f142, 0x0102f164, /* 0102f164 //C 0f142   468 mvzl	r0,m_err_addr */
0x0000f143, 0x0400f4d0, /* 0400f4d0 //C 0f143   469 call	printsnl */
0x0000f144, 0x01f2f163, /* 01f2f163 //C 0f144   470 jmp	m_ret */
0x0000f145, 0x025b0000, /* 025b0000 //C 0f145   472 sz	r5 */
0x0000f146, 0x11f2f159, /* 11f2f159 //C 0f146   473 jz	m_read */
0x0000f147, 0x0132f000, /* 0132f000 //C 0f147   475 mvzl	r3,the_begin */
0x0000f148, 0x00380400, /* 00380400 //C 0f148   476 cmp	r3,r4 */
0x0000f149, 0x91f2f151, /* 91f2f151 //C 0f149   477 HI jmp	m_addrv_ok */
0x0000f14a, 0x0132f8a0, /* 0132f8a0 //C 0f14a   478 mvzl	r3,the_end */
0x0000f14b, 0x00380400, /* 00380400 //C 0f14b   479 cmp	r3,r4 */
0x0000f14c, 0x91f2f14e, /* 91f2f14e //C 0f14c   480 HI jmp	m_addrv_nok */
0x0000f14d, 0x01f2f151, /* 01f2f151 //C 0f14d   481 jmp	m_addrv_ok */
0x0000f14e, 0x0102f172, /* 0102f172 //C 0f14e   489 mvzl	r0,m_err_addrv */
0x0000f14f, 0x0400f4d0, /* 0400f4d0 //C 0f14f   490 call	printsnl */
0x0000f150, 0x01f2f163, /* 01f2f163 //C 0f150   491 jmp	m_ret */
0x0000f151, 0x00000500, /* 00000500 //C 0f151   493 mov	r0,r5 */
0x0000f152, 0x0400f453, /* 0400f453 //C 0f152   494 call	htoi */
0x0000f153, 0x00500100, /* 00500100 //C 0f153   495 mov	r5,r1 */
0x0000f154, 0x31f2f158, /* 31f2f158 //C 0f154   496 C1 jmp	m_value_ok */
0x0000f155, 0x0102f184, /* 0102f184 //C 0f155   497 mvzl	r0,m_err_value */
0x0000f156, 0x0400f4d0, /* 0400f4d0 //C 0f156   498 call	printsnl */
0x0000f157, 0x01f2f163, /* 01f2f163 //C 0f157   499 jmp	m_ret */
0x0000f158, 0x0c540000, /* 0c540000 //C 0f158   501 st	r5,r4 */
0x0000f159, 0x00000400, /* 00000400 //C 0f159   504 mov	r0,r4 */
0x0000f15a, 0x01120004, /* 01120004 //C 0f15a   505 mvzl	r1,4 */
0x0000f15b, 0x0400f4d7, /* 0400f4d7 //C 0f15b   506 call	print_vhex */
0x0000f15c, 0x01020020, /* 01020020 //C 0f15c   507 mvzl	r0,0x20 */
0x0000f15d, 0x0400f490, /* 0400f490 //C 0f15d   508 call	putchar */
0x0000f15e, 0x0e040000, /* 0e040000 //C 0f15e   509 ld	r0,r4 */
0x0000f15f, 0x01120004, /* 01120004 //C 0f15f   510 mvzl	r1,4 */
0x0000f160, 0x0400f4d7, /* 0400f4d7 //C 0f160   511 call	print_vhex */
0x0000f161, 0x0102000a, /* 0102000a //C 0f161   512 mvzl	r0,LF */
0x0000f162, 0x0400f490, /* 0400f490 //C 0f162   513 call	putchar */
0x0000f163, 0x0ffd0000, /* 0ffd0000 //C 0f163   515 pop	pc */
0x0000f164, 0x00000041, /* 00000041 //C 0f164   517 db	65 */
0x0000f165, 0x00000064, /* 00000064 //C 0f165   517 db	100 */
0x0000f166, 0x00000064, /* 00000064 //C 0f166   517 db	100 */
0x0000f167, 0x00000072, /* 00000072 //C 0f167   517 db	114 */
0x0000f168, 0x00000065, /* 00000065 //C 0f168   517 db	101 */
0x0000f169, 0x00000073, /* 00000073 //C 0f169   517 db	115 */
0x0000f16a, 0x00000073, /* 00000073 //C 0f16a   517 db	115 */
0x0000f16b, 0x00000020, /* 00000020 //C 0f16b   517 db	32 */
0x0000f16c, 0x00000065, /* 00000065 //C 0f16c   517 db	101 */
0x0000f16d, 0x00000072, /* 00000072 //C 0f16d   517 db	114 */
0x0000f16e, 0x00000072, /* 00000072 //C 0f16e   517 db	114 */
0x0000f16f, 0x0000006f, /* 0000006f //C 0f16f   517 db	111 */
0x0000f170, 0x00000072, /* 00000072 //C 0f170   517 db	114 */
0x0000f171, 0x00000000, /* 00000000 //C 0f171   517 db */
0x0000f172, 0x0000004d, /* 0000004d //C 0f172   518 db	77 */
0x0000f173, 0x0000006f, /* 0000006f //C 0f173   518 db	111 */
0x0000f174, 0x0000006e, /* 0000006e //C 0f174   518 db	110 */
0x0000f175, 0x00000069, /* 00000069 //C 0f175   518 db	105 */
0x0000f176, 0x00000074, /* 00000074 //C 0f176   518 db	116 */
0x0000f177, 0x0000006f, /* 0000006f //C 0f177   518 db	111 */
0x0000f178, 0x00000072, /* 00000072 //C 0f178   518 db	114 */
0x0000f179, 0x00000027, /* 00000027 //C 0f179   518 db	39 */
0x0000f17a, 0x00000073, /* 00000073 //C 0f17a   518 db	115 */
0x0000f17b, 0x00000020, /* 00000020 //C 0f17b   518 db	32 */
0x0000f17c, 0x00000061, /* 00000061 //C 0f17c   518 db	97 */
0x0000f17d, 0x00000064, /* 00000064 //C 0f17d   518 db	100 */
0x0000f17e, 0x00000064, /* 00000064 //C 0f17e   518 db	100 */
0x0000f17f, 0x00000072, /* 00000072 //C 0f17f   518 db	114 */
0x0000f180, 0x00000065, /* 00000065 //C 0f180   518 db	101 */
0x0000f181, 0x00000073, /* 00000073 //C 0f181   518 db	115 */
0x0000f182, 0x00000073, /* 00000073 //C 0f182   518 db	115 */
0x0000f183, 0x00000000, /* 00000000 //C 0f183   518 db */
0x0000f184, 0x00000056, /* 00000056 //C 0f184   519 db	86 */
0x0000f185, 0x00000061, /* 00000061 //C 0f185   519 db	97 */
0x0000f186, 0x0000006c, /* 0000006c //C 0f186   519 db	108 */
0x0000f187, 0x00000075, /* 00000075 //C 0f187   519 db	117 */
0x0000f188, 0x00000065, /* 00000065 //C 0f188   519 db	101 */
0x0000f189, 0x00000020, /* 00000020 //C 0f189   519 db	32 */
0x0000f18a, 0x00000065, /* 00000065 //C 0f18a   519 db	101 */
0x0000f18b, 0x00000072, /* 00000072 //C 0f18b   519 db	114 */
0x0000f18c, 0x00000072, /* 00000072 //C 0f18c   519 db	114 */
0x0000f18d, 0x0000006f, /* 0000006f //C 0f18d   519 db	111 */
0x0000f18e, 0x00000072, /* 00000072 //C 0f18e   519 db	114 */
0x0000f18f, 0x00000000, /* 00000000 //C 0f18f   519 db */
0x0000f190, 0x0ded0000, /* 0ded0000 //C 0f190   524 push	lr */
0x0000f191, 0x0122f647, /* 0122f647 //C 0f191   525 mvzl	r2,words */
0x0000f192, 0x01020000, /* 01020000 //C 0f192   526 mvzl	r0,0 */
0x0000f193, 0x0e420001, /* 0e420001 //C 0f193   528 ld	r4,r2,1		; addr */
0x0000f194, 0x0e520002, /* 0e520002 //C 0f194   529 ld	r5,r2,2		; value */
0x0000f195, 0x024b0000, /* 024b0000 //C 0f195   530 sz 	r4 */
0x0000f196, 0x11f2f163, /* 11f2f163 //C 0f196   531 jz	m_ret */
0x0000f197, 0x00000400, /* 00000400 //C 0f197   533 mov	r0,r4 */
0x0000f198, 0x0400f453, /* 0400f453 //C 0f198   534 call	htoi */
0x0000f199, 0x00400100, /* 00400100 //C 0f199   535 mov	r4,r1 */
0x0000f19a, 0x31f2f19e, /* 31f2f19e //C 0f19a   536 C1 jmp	sm_addr_ok */
0x0000f19b, 0x0102f164, /* 0102f164 //C 0f19b   537 mvzl	r0,m_err_addr */
0x0000f19c, 0x0400f4d0, /* 0400f4d0 //C 0f19c   538 call	printsnl */
0x0000f19d, 0x01f2f1b2, /* 01f2f1b2 //C 0f19d   539 jmp	sm_ret */
0x0000f19e, 0x025b0000, /* 025b0000 //C 0f19e   541 sz	r5 */
0x0000f19f, 0x11f2f1b2, /* 11f2f1b2 //C 0f19f   542 jz	sm_ret */
0x0000f1a0, 0x0132f000, /* 0132f000 //C 0f1a0   544 mvzl	r3,the_begin */
0x0000f1a1, 0x00380400, /* 00380400 //C 0f1a1   545 cmp	r3,r4 */
0x0000f1a2, 0x91f2f1aa, /* 91f2f1aa //C 0f1a2   546 HI jmp	sm_addrv_ok */
0x0000f1a3, 0x0132f8a0, /* 0132f8a0 //C 0f1a3   547 mvzl	r3,the_end */
0x0000f1a4, 0x00380400, /* 00380400 //C 0f1a4   548 cmp	r3,r4 */
0x0000f1a5, 0x91f2f1a7, /* 91f2f1a7 //C 0f1a5   549 HI jmp	sm_addrv_nok */
0x0000f1a6, 0x01f2f1aa, /* 01f2f1aa //C 0f1a6   550 jmp	sm_addrv_ok */
0x0000f1a7, 0x0102f172, /* 0102f172 //C 0f1a7   552 mvzl	r0,m_err_addrv */
0x0000f1a8, 0x0400f4d0, /* 0400f4d0 //C 0f1a8   553 call	printsnl */
0x0000f1a9, 0x01f2f1b2, /* 01f2f1b2 //C 0f1a9   554 jmp	sm_ret */
0x0000f1aa, 0x00000500, /* 00000500 //C 0f1aa   556 mov	r0,r5 */
0x0000f1ab, 0x0400f453, /* 0400f453 //C 0f1ab   557 call	htoi */
0x0000f1ac, 0x00500100, /* 00500100 //C 0f1ac   558 mov	r5,r1 */
0x0000f1ad, 0x31f2f1b1, /* 31f2f1b1 //C 0f1ad   559 C1 jmp	sm_value_ok */
0x0000f1ae, 0x0102f184, /* 0102f184 //C 0f1ae   560 mvzl	r0,m_err_value */
0x0000f1af, 0x0400f4d0, /* 0400f4d0 //C 0f1af   561 call	printsnl */
0x0000f1b0, 0x01f2f1b2, /* 01f2f1b2 //C 0f1b0   562 jmp	sm_ret */
0x0000f1b1, 0x0c540000, /* 0c540000 //C 0f1b1   564 st	r5,r4 */
0x0000f1b2, 0x0ffd0000, /* 0ffd0000 //C 0f1b2   567 pop	pc */
0x0000f1b3, 0x0ded0000, /* 0ded0000 //C 0f1b3   573 push	lr */
0x0000f1b4, 0x0122f647, /* 0122f647 //C 0f1b4   574 mvzl	r2,words */
0x0000f1b5, 0x0e020001, /* 0e020001 //C 0f1b5   575 ld	r0,r2,1		; start address */
0x0000f1b6, 0x0400f453, /* 0400f453 //C 0f1b6   576 call	htoi */
0x0000f1b7, 0x00300100, /* 00300100 //C 0f1b7   577 mov	r3,r1 */
0x0000f1b8, 0x0e020002, /* 0e020002 //C 0f1b8   578 ld	r0,r2,2		; end address */
0x0000f1b9, 0x020b0000, /* 020b0000 //C 0f1b9   579 sz	r0 */
0x0000f1ba, 0x21f2f1be, /* 21f2f1be //C 0f1ba   580 jnz	d_end_ok */
0x0000f1bb, 0x00400300, /* 00400300 //C 0f1bb   581 mov	r4,r3 */
0x0000f1bc, 0x01440010, /* 01440010 //C 0f1bc   582 add	r4,0x10 */
0x0000f1bd, 0x01f2f1c0, /* 01f2f1c0 //C 0f1bd   583 jmp	d_chk_end */
0x0000f1be, 0x0400f453, /* 0400f453 //C 0f1be   585 call	htoi */
0x0000f1bf, 0x00400100, /* 00400100 //C 0f1bf   586 mov	r4,r1 */
0x0000f1c0, 0x00380400, /* 00380400 //C 0f1c0   588 cmp	r3,r4		; check if start>end */
0x0000f1c1, 0x91f2f1d0, /* 91f2f1d0 //C 0f1c1   589 HI jmp d_bad */
0x0000f1c2, 0x00000300, /* 00000300 //C 0f1c2   597 mov	r0,r3		; print address */
0x0000f1c3, 0x01120004, /* 01120004 //C 0f1c3   598 mvzl	r1,4 */
0x0000f1c4, 0x0400f4d7, /* 0400f4d7 //C 0f1c4   599 call	print_vhex */
0x0000f1c5, 0x01020020, /* 01020020 //C 0f1c5   600 mvzl	r0,0x20		; print one space */
0x0000f1c6, 0x0400f490, /* 0400f490 //C 0f1c6   601 call	putchar */
0x0000f1c7, 0x0e030000, /* 0e030000 //C 0f1c7   602 ld	r0,r3		; load data */
0x0000f1c8, 0x01120004, /* 01120004 //C 0f1c8   603 mvzl	r1,4		; print data */
0x0000f1c9, 0x0400f4d7, /* 0400f4d7 //C 0f1c9   604 call	print_vhex */
0x0000f1ca, 0x0102000a, /* 0102000a //C 0f1ca   605 mvzl	r0,LF		; print new line */
0x0000f1cb, 0x0400f490, /* 0400f490 //C 0f1cb   606 call	putchar */
0x0000f1cc, 0x00380400, /* 00380400 //C 0f1cc   607 cmp	r3,r4 */
0x0000f1cd, 0x11f2f1d2, /* 11f2f1d2 //C 0f1cd   608 jz	d_ret */
0x0000f1ce, 0x01340001, /* 01340001 //C 0f1ce   609 add	r3,1 */
0x0000f1cf, 0x01f2f1c2, /* 01f2f1c2 //C 0f1cf   610 jmp	d_cyc */
0x0000f1d0, 0x0102f1d3, /* 0102f1d3 //C 0f1d0   612 mvzl	r0,d_err_bad */
0x0000f1d1, 0x0400f4d0, /* 0400f4d0 //C 0f1d1   613 call	printsnl */
0x0000f1d2, 0x0ffd0000, /* 0ffd0000 //C 0f1d2   615 pop	pc */
0x0000f1d3, 0x00000057, /* 00000057 //C 0f1d3   617 db	87 */
0x0000f1d4, 0x00000072, /* 00000072 //C 0f1d4   617 db	114 */
0x0000f1d5, 0x0000006f, /* 0000006f //C 0f1d5   617 db	111 */
0x0000f1d6, 0x0000006e, /* 0000006e //C 0f1d6   617 db	110 */
0x0000f1d7, 0x00000067, /* 00000067 //C 0f1d7   617 db	103 */
0x0000f1d8, 0x00000020, /* 00000020 //C 0f1d8   617 db	32 */
0x0000f1d9, 0x00000065, /* 00000065 //C 0f1d9   617 db	101 */
0x0000f1da, 0x0000006e, /* 0000006e //C 0f1da   617 db	110 */
0x0000f1db, 0x00000064, /* 00000064 //C 0f1db   617 db	100 */
0x0000f1dc, 0x00000020, /* 00000020 //C 0f1dc   617 db	32 */
0x0000f1dd, 0x00000061, /* 00000061 //C 0f1dd   617 db	97 */
0x0000f1de, 0x00000064, /* 00000064 //C 0f1de   617 db	100 */
0x0000f1df, 0x00000064, /* 00000064 //C 0f1df   617 db	100 */
0x0000f1e0, 0x00000072, /* 00000072 //C 0f1e0   617 db	114 */
0x0000f1e1, 0x00000065, /* 00000065 //C 0f1e1   617 db	101 */
0x0000f1e2, 0x00000073, /* 00000073 //C 0f1e2   617 db	115 */
0x0000f1e3, 0x00000073, /* 00000073 //C 0f1e3   617 db	115 */
0x0000f1e4, 0x00000000, /* 00000000 //C 0f1e4   617 db */
0x0000f1e5, 0x00f00e00, /* 00f00e00 //C 0f1e5   622 ret */
0x0000f1e6, 0x0ded0000, /* 0ded0000 //C 0f1e6   627 push	lr */
0x0000f1e7, 0x01a20000, /* 01a20000 //C 0f1e7   628 mvzl	r10,0		; state (nr of words) */
0x0000f1e8, 0x01820000, /* 01820000 //C 0f1e8   629 mvzl	r8,0		; value */
0x0000f1e9, 0x0162003f, /* 0162003f //C 0f1e9   630 mvzl	r6,'?'		; Record type */
0x0000f1ea, 0x01c20000, /* 01c20000 //C 0f1ea   631 mvzl	r12,0		; Checksum */
0x0000f1eb, 0x0400f481, /* 0400f481 //C 0f1eb   633 call	check_uart */
0x0000f1ec, 0x41f2f1eb, /* 41f2f1eb //C 0f1ec   634 C0 jmp	l_cyc */
0x0000f1ed, 0x0400f489, /* 0400f489 //C 0f1ed   635 call	read */
0x0000f1ee, 0x00b00000, /* 00b00000 //C 0f1ee   637 mov	r11,r0		; Copy of char in R11 */
0x0000f1ef, 0x0108000a, /* 0108000a //C 0f1ef   638 cmp	r0,10		; check EOL chars */
0x0000f1f0, 0x11f2f23c, /* 11f2f23c //C 0f1f0   639 jz	l_eol */
0x0000f1f1, 0x0108000d, /* 0108000d //C 0f1f1   640 cmp	r0,13 */
0x0000f1f2, 0x11f2f23c, /* 11f2f23c //C 0f1f2   641 jz	l_eol */
0x0000f1f3, 0x01a80000, /* 01a80000 //C 0f1f3   643 cmp	r10,0 */
0x0000f1f4, 0x21f2f204, /* 21f2f204 //C 0f1f4   644 jnz	l_no0 */
0x0000f1f5, 0x0400f420, /* 0400f420 //C 0f1f5   646 call	hexchar2value */
0x0000f1f6, 0x41f2f1fe, /* 41f2f1fe //C 0f1f6   647 C0 jmp	l_eof_0 */
0x0000f1f7, 0x02880000, /* 02880000 //C 0f1f7   648 shl	r8		; shift val(char) into value */
0x0000f1f8, 0x02880000, /* 02880000 //C 0f1f8   649 shl	r8 */
0x0000f1f9, 0x02880000, /* 02880000 //C 0f1f9   650 shl	r8 */
0x0000f1fa, 0x02880000, /* 02880000 //C 0f1fa   651 shl	r8 */
0x0000f1fb, 0x010b000f, /* 010b000f //C 0f1fb   652 btst	r0,0xf */
0x0000f1fc, 0x008d0000, /* 008d0000 //C 0f1fc   653 or	r8,r0 */
0x0000f1fd, 0x01f2f1eb, /* 01f2f1eb //C 0f1fd   654 jmp	l_cyc */
0x0000f1fe, 0x01a20001, /* 01a20001 //C 0f1fe   656 mvzl	r10,1		; state0 -> state1 */
0x0000f1ff, 0x0162003f, /* 0162003f //C 0f1ff   657 mvzl	r6,'?'		; No //C yet */
0x0000f200, 0x01b8002f, /* 01b8002f //C 0f200   658 cmp	r11,'/'		; is it start of // */
0x0000f201, 0x11720001, /* 11720001 //C 0f201   659 z1 mvzl	r7,1		; Yes, first / found */
0x0000f202, 0x21720000, /* 21720000 //C 0f202   660 z0 mvzl	r7,0		; No '/' yet */
0x0000f203, 0x01f2f1eb, /* 01f2f1eb //C 0f203   661 jmp	l_cyc */
0x0000f204, 0x01a80001, /* 01a80001 //C 0f204   664 cmp	r10,1 */
0x0000f205, 0x21f2f21f, /* 21f2f21f //C 0f205   665 jnz	l_no1 */
0x0000f206, 0x027b0000, /* 027b0000 //C 0f206   667 sz	r7 */
0x0000f207, 0x21f2f20c, /* 21f2f20c //C 0f207   668 jnz	l_s1_2nd */
0x0000f208, 0x0108002f, /* 0108002f //C 0f208   670 cmp	r0,'/' */
0x0000f209, 0x21f2f1eb, /* 21f2f1eb //C 0f209   671 jnz	l_cyc */
0x0000f20a, 0x01720001, /* 01720001 //C 0f20a   672 mvzl	r7,1 */
0x0000f20b, 0x01f2f1eb, /* 01f2f1eb //C 0f20b   673 jmp	l_cyc */
0x0000f20c, 0x0108002f, /* 0108002f //C 0f20c   675 cmp	r0,'/' */
0x0000f20d, 0x11f2f1eb, /* 11f2f1eb //C 0f20d   676 jz	l_cyc */
0x0000f20e, 0x01080043, /* 01080043 //C 0f20e   677 cmp	r0,'C' */
0x0000f20f, 0x11f2f212, /* 11f2f212 //C 0f20f   678 jz	l_s1_C */
0x0000f210, 0x01080049, /* 01080049 //C 0f210   679 cmp	r0,'I' */
0x0000f211, 0x21f2f217, /* 21f2f217 //C 0f211   680 jnz	l_s1_noC */
0x0000f212, 0x00600000, /* 00600000 //C 0f212   683 mov	r6,r0		; record type is in r0, store in r6 */
0x0000f213, 0x01a20002, /* 01a20002 //C 0f213   685 mvzl	r10,2 */
0x0000f214, 0x01920000, /* 01920000 //C 0f214   686 mvzl	r9,0		; address= 0 */
0x0000f215, 0x01520000, /* 01520000 //C 0f215   687 mvzl	r5,0		; where we are in word: before */
0x0000f216, 0x01f2f1eb, /* 01f2f1eb //C 0f216   688 jmp	l_cyc */
0x0000f217, 0x01080045, /* 01080045 //C 0f217   690 cmp	r0,'E' */
0x0000f218, 0x21f2f21c, /* 21f2f21c //C 0f218   691 jnz	l_s1_noE */
0x0000f219, 0x01620045, /* 01620045 //C 0f219   693 mvzl	r6,'E' */
0x0000f21a, 0x01a20003, /* 01a20003 //C 0f21a   695 mvzl	r10,3 */
0x0000f21b, 0x01f2f1eb, /* 01f2f1eb //C 0f21b   696 jmp	l_cyc */
0x0000f21c, 0x0400f490, /* 0400f490 //C 0f21c   700 call	putchar		; print record type */
0x0000f21d, 0x01a2000f, /* 01a2000f //C 0f21d   701 mvzl	r10,0xf		; special state: skip everything */
0x0000f21e, 0x01f2f1eb, /* 01f2f1eb //C 0f21e   702 jmp	l_cyc */
0x0000f21f, 0x01a80002, /* 01a80002 //C 0f21f   705 cmp	r10,2 */
0x0000f220, 0x21f2f234, /* 21f2f234 //C 0f220   706 jnz	l_no2 */
0x0000f221, 0x01580000, /* 01580000 //C 0f221   708 cmp	r5,0 */
0x0000f222, 0x21f2f22d, /* 21f2f22d //C 0f222   709 jnz	l_s2_no0 */
0x0000f223, 0x0400f420, /* 0400f420 //C 0f223   711 call	hexchar2value */
0x0000f224, 0x41f2f1eb, /* 41f2f1eb //C 0f224   712 C0 jmp	l_cyc */
0x0000f225, 0x01520001, /* 01520001 //C 0f225   713 mvzl	r5,1 */
0x0000f226, 0x02980000, /* 02980000 //C 0f226   715 shl	r9 */
0x0000f227, 0x02980000, /* 02980000 //C 0f227   716 shl	r9 */
0x0000f228, 0x02980000, /* 02980000 //C 0f228   717 shl	r9 */
0x0000f229, 0x02980000, /* 02980000 //C 0f229   718 shl	r9 */
0x0000f22a, 0x010b000f, /* 010b000f //C 0f22a   719 btst	r0,0xf */
0x0000f22b, 0x009d0000, /* 009d0000 //C 0f22b   720 or	r9,r0 */
0x0000f22c, 0x01f2f1eb, /* 01f2f1eb //C 0f22c   722 jmp	l_cyc */
0x0000f22d, 0x01580001, /* 01580001 //C 0f22d   724 cmp	r5,1 */
0x0000f22e, 0x21f2f233, /* 21f2f233 //C 0f22e   725 jnz	l_s2_no1 */
0x0000f22f, 0x0400f420, /* 0400f420 //C 0f22f   727 call	hexchar2value */
0x0000f230, 0x31f2f226, /* 31f2f226 //C 0f230   728 C1 jmp	l_s2_got */
0x0000f231, 0x01520002, /* 01520002 //C 0f231   729 mvzl	r5,2 */
0x0000f232, 0x01f2f1eb, /* 01f2f1eb //C 0f232   730 jmp	l_cyc */
0x0000f233, 0x01f2f1eb, /* 01f2f1eb //C 0f233   732 jmp	l_cyc */
0x0000f234, 0x01a80003, /* 01a80003 //C 0f234   734 cmp	r10,3 */
0x0000f235, 0x21f2f237, /* 21f2f237 //C 0f235   735 jnz	l_no3 */
0x0000f236, 0x01f2f1eb, /* 01f2f1eb //C 0f236   737 jmp	l_cyc		; do nothing, just wait EOL */
0x0000f237, 0x01a8000f, /* 01a8000f //C 0f237   740 cmp	r10,0xf */
0x0000f238, 0x01f2f23a, /* 01f2f23a //C 0f238   741 jmp	l_nof */
0x0000f239, 0x01f2f1eb, /* 01f2f1eb //C 0f239   742 jmp	l_cyc		; just skip */
0x0000f23a, 0x01f2f1eb, /* 01f2f1eb //C 0f23a   745 jmp	l_cyc */
0x0000f23b, 0x01f2f254, /* 01f2f254 //C 0f23b   746 jmp	l_ret */
0x0000f23c, 0x01a80000, /* 01a80000 //C 0f23c   750 cmp	r10,0		; in state0 */
0x0000f23d, 0x11f2f250, /* 11f2f250 //C 0f23d   751 jz	l_back_to_0	; just restart */
0x0000f23e, 0x01a80001, /* 01a80001 //C 0f23e   752 cmp	r10,1		; in state1 */
0x0000f23f, 0x11f2f250, /* 11f2f250 //C 0f23f   753 jz	l_back_to_0 	;l_cyc ;l_bad ; garbage */
0x0000f240, 0x01a80002, /* 01a80002 //C 0f240   754 cmp	r10,2		; in state2 */
0x0000f241, 0x11f2f248, /* 11f2f248 //C 0f241   755 jz	l_proc		; process record */
0x0000f242, 0x01a80003, /* 01a80003 //C 0f242   756 cmp	r10,3		; in state3 */
0x0000f243, 0x11f2f254, /* 11f2f254 //C 0f243   757 jz	l_ret		; eol in end record: finish */
0x0000f244, 0x01a8000f, /* 01a8000f //C 0f244   758 cmp	r10,0xf		; in state skip */
0x0000f245, 0x11f2f250, /* 11f2f250 //C 0f245   759 jz	l_back_to_0	; reset state for new line */
0x0000f246, 0x01f2f1eb, /* 01f2f1eb //C 0f246   760 jmp	l_cyc */
0x0000f247, 0x01f2f254, /* 01f2f254 //C 0f247   762 jmp	l_ret */
0x0000f248, 0x01680043, /* 01680043 //C 0f248   764 cmp	r6,'C'		; is it a C or I record? */
0x0000f249, 0x1c890000, /* 1c890000 //C 0f249   765 z st	r8,r9		; then store */
0x0000f24a, 0x10c40800, /* 10c40800 //C 0f24a   766 z add	r12,r8		; and add to checksum */
0x0000f24b, 0x01680049, /* 01680049 //C 0f24b   767 cmp	r6,'I' */
0x0000f24c, 0x1c890000, /* 1c890000 //C 0f24c   768 z st	r8,r9 */
0x0000f24d, 0x10c40800, /* 10c40800 //C 0f24d   769 z add	r12,r8 */
0x0000f24e, 0x00000600, /* 00000600 //C 0f24e   770 mov	r0,r6		; echo record type */
0x0000f24f, 0x0400f490, /* 0400f490 //C 0f24f   771 call	putchar */
0x0000f250, 0x01a20000, /* 01a20000 //C 0f250   776 mvzl	r10,0 */
0x0000f251, 0x01820000, /* 01820000 //C 0f251   777 mvzl	r8,0 */
0x0000f252, 0x0162003f, /* 0162003f //C 0f252   778 mvzl	r6,'?' */
0x0000f253, 0x01f2f1eb, /* 01f2f1eb //C 0f253   779 jmp	l_cyc */
0x0000f254, 0x0102000a, /* 0102000a //C 0f254   781 mvzl	r0,LF */
0x0000f255, 0x0400f490, /* 0400f490 //C 0f255   782 call	putchar */
0x0000f256, 0x00000c00, /* 00000c00 //C 0f256   784 mov	r0,r12 */
0x0000f257, 0x01120004, /* 01120004 //C 0f257   785 mvzl	r1,4 */
0x0000f258, 0x0400f4d7, /* 0400f4d7 //C 0f258   786 call	print_vhex */
0x0000f259, 0x0102000a, /* 0102000a //C 0f259   787 mvzl	r0,LF */
0x0000f25a, 0x0400f490, /* 0400f490 //C 0f25a   788 call	putchar */
0x0000f25b, 0x0ffd0000, /* 0ffd0000 //C 0f25b   789 pop	pc */
0x0000f25c, 0x0ded0000, /* 0ded0000 //C 0f25c   795 push	lr */
0x0000f25d, 0x0122f647, /* 0122f647 //C 0f25d   796 mvzl	r2,words */
0x0000f25e, 0x0e020001, /* 0e020001 //C 0f25e   797 ld	r0,r2,1		; address */
0x0000f25f, 0x020b0000, /* 020b0000 //C 0f25f   798 sz	r0 */
0x0000f260, 0x11f2f283, /* 11f2f283 //C 0f260   799 jz	g_no_addr */
0x0000f261, 0x0400f453, /* 0400f453 //C 0f261   800 call	htoi */
0x0000f262, 0x00b00100, /* 00b00100 //C 0f262   801 mov	r11,r1 */
0x0000f263, 0x0102f296, /* 0102f296 //C 0f263   803 mvzl	r0,d_msg_run */
0x0000f264, 0x0400f497, /* 0400f497 //C 0f264   804 call	prints */
0x0000f265, 0x00000b00, /* 00000b00 //C 0f265   805 mov	r0,r11 */
0x0000f266, 0x01120004, /* 01120004 //C 0f266   806 mvzl	r1,4 */
0x0000f267, 0x0400f4d7, /* 0400f4d7 //C 0f267   807 call	print_vhex */
0x0000f268, 0x0102000a, /* 0102000a //C 0f268   808 mvzl	r0,LF */
0x0000f269, 0x0400f490, /* 0400f490 //C 0f269   809 call	putchar */
0x0000f26a, 0x06b0f65e, /* 06b0f65e //C 0f26a   810 st	r11,reg15 */
0x0000f26b, 0x0122ff43, /* 0122ff43 //C 0f26b   812 mvzl	r2,UART_TSTAT */
0x0000f26c, 0x0e920000, /* 0e920000 //C 0f26c   814 ld	r9,r2 */
0x0000f26d, 0x019c0001, /* 019c0001 //C 0f26d   815 test	r9,1 */
0x0000f26e, 0x11f2f26c, /* 11f2f26c //C 0f26e   816 jz	g_wait_tc */
0x0000f26f, 0x07000000, /* 07000000 //C 0f26f   818 ld	r0,0 */
0x0000f270, 0x0600f64d, /* 0600f64d //C 0f270   819 st	r0,called */
0x0000f271, 0x0700f65f, /* 0700f65f //C 0f271   821 ld	r0,regf */
0x0000f272, 0x020f0000, /* 020f0000 //C 0f272   822 setf	r0 */
0x0000f273, 0x0700f64f, /* 0700f64f //C 0f273   823 ld	r0,reg0 */
0x0000f274, 0x0710f650, /* 0710f650 //C 0f274   824 ld	r1,reg1 */
0x0000f275, 0x0720f651, /* 0720f651 //C 0f275   825 ld	r2,reg2 */
0x0000f276, 0x0730f652, /* 0730f652 //C 0f276   826 ld	r3,reg3 */
0x0000f277, 0x0740f653, /* 0740f653 //C 0f277   827 ld	r4,reg4 */
0x0000f278, 0x0750f654, /* 0750f654 //C 0f278   828 ld	r5,reg5 */
0x0000f279, 0x0760f655, /* 0760f655 //C 0f279   829 ld	r6,reg6 */
0x0000f27a, 0x0770f656, /* 0770f656 //C 0f27a   830 ld	r7,reg7 */
0x0000f27b, 0x0780f657, /* 0780f657 //C 0f27b   831 ld	r8,reg8 */
0x0000f27c, 0x0790f658, /* 0790f658 //C 0f27c   832 ld	r9,reg9 */
0x0000f27d, 0x07a0f659, /* 07a0f659 //C 0f27d   833 ld	r10,reg10 */
0x0000f27e, 0x07b0f65a, /* 07b0f65a //C 0f27e   834 ld	r11,reg11 */
0x0000f27f, 0x07c0f65b, /* 07c0f65b //C 0f27f   835 ld	r12,reg12 */
0x0000f280, 0x07d0f65c, /* 07d0f65c //C 0f280   836 ld	r13,reg13 */
0x0000f281, 0x07e0f65d, /* 07e0f65d //C 0f281   837 ld	r14,reg14 */
0x0000f282, 0x07f0f65e, /* 07f0f65e //C 0f282   839 ld	r15,reg15 */
0x0000f283, 0x0700f64d, /* 0700f64d //C 0f283   842 ld	r0,called */
0x0000f284, 0x020b0000, /* 020b0000 //C 0f284   843 sz	r0 */
0x0000f285, 0x11f2f288, /* 11f2f288 //C 0f285   844 jz	g_err */
0x0000f286, 0x07b0f65e, /* 07b0f65e //C 0f286   845 ld	r11,reg15 */
0x0000f287, 0x01f2f263, /* 01f2f263 //C 0f287   846 jmp	g_go11 */
0x0000f288, 0x0102f28b, /* 0102f28b //C 0f288   848 mvzl	r0,g_err_addr */
0x0000f289, 0x0400f4d0, /* 0400f4d0 //C 0f289   849 call	printsnl */
0x0000f28a, 0x0ffd0000, /* 0ffd0000 //C 0f28a   851 pop	pc */
0x0000f28b, 0x0000004e, /* 0000004e //C 0f28b   853 db	78 */
0x0000f28c, 0x0000006f, /* 0000006f //C 0f28c   853 db	111 */
0x0000f28d, 0x00000020, /* 00000020 //C 0f28d   853 db	32 */
0x0000f28e, 0x00000061, /* 00000061 //C 0f28e   853 db	97 */
0x0000f28f, 0x00000064, /* 00000064 //C 0f28f   853 db	100 */
0x0000f290, 0x00000064, /* 00000064 //C 0f290   853 db	100 */
0x0000f291, 0x00000072, /* 00000072 //C 0f291   853 db	114 */
0x0000f292, 0x00000065, /* 00000065 //C 0f292   853 db	101 */
0x0000f293, 0x00000073, /* 00000073 //C 0f293   853 db	115 */
0x0000f294, 0x00000073, /* 00000073 //C 0f294   853 db	115 */
0x0000f295, 0x00000000, /* 00000000 //C 0f295   853 db */
0x0000f296, 0x00000052, /* 00000052 //C 0f296   854 db	82 */
0x0000f297, 0x00000075, /* 00000075 //C 0f297   854 db	117 */
0x0000f298, 0x0000006e, /* 0000006e //C 0f298   854 db	110 */
0x0000f299, 0x00000020, /* 00000020 //C 0f299   854 db	32 */
0x0000f29a, 0x00000000, /* 00000000 //C 0f29a   854 db */
0x0000f29b, 0x0ded0000, /* 0ded0000 //C 0f29b   859 push	lr */
0x0000f29c, 0x0122f6ef, /* 0122f6ef //C 0f29c   860 mvzl	r2,helps */
0x0000f29d, 0x01320000, /* 01320000 //C 0f29d   861 mvzl	r3,0 */
0x0000f29e, 0x0b038200, /* 0b038200 //C 0f29e   863 ld	r0,r3+,r2	; pick a char */
0x0000f29f, 0x020b0000, /* 020b0000 //C 0f29f   864 sz	r0		; is it eos? */
0x0000f2a0, 0x21f2f2a4, /* 21f2f2a4 //C 0f2a0   865 jnz	h_print */
0x0000f2a1, 0x0b038200, /* 0b038200 //C 0f2a1   868 ld	r0,r3+,r2	; get first char of next string */
0x0000f2a2, 0x020b0000, /* 020b0000 //C 0f2a2   869 sz	r0 */
0x0000f2a3, 0x11f2f2a6, /* 11f2f2a6 //C 0f2a3   870 jz	h_eof */
0x0000f2a4, 0x0400f490, /* 0400f490 //C 0f2a4   872 call	putchar */
0x0000f2a5, 0x01f2f29e, /* 01f2f29e //C 0f2a5   873 jmp	h_cyc */
0x0000f2a6, 0x0ffd0000, /* 0ffd0000 //C 0f2a6   875 pop	pc */
0x0000f2a7, 0x0ded0000, /* 0ded0000 //C 0f2a7   881 push	lr */
0x0000f2a8, 0x0d1d0000, /* 0d1d0000 //C 0f2a8   882 push	r1 */
0x0000f2a9, 0x00100000, /* 00100000 //C 0f2a9   883 mov	r1,r0 */
0x0000f2aa, 0x01180010, /* 01180010 //C 0f2aa   884 cmp	r1,16		; go out if nr>16 */
0x0000f2ab, 0x91f2f2df, /* 91f2f2df //C 0f2ab   885 HI jmp	prn_ret */
0x0000f2ac, 0x0118000f, /* 0118000f //C 0f2ac   886 cmp	r1,15		; nr=Flag? */
0x0000f2ad, 0xa1f2f2b4, /* a1f2f2b4 //C 0f2ad   887 LS jmp	prn_015 */
0x0000f2ae, 0x01020046, /* 01020046 //C 0f2ae   889 mvzl	r0,'F' */
0x0000f2af, 0x0400f490, /* 0400f490 //C 0f2af   890 call	putchar */
0x0000f2b0, 0x01020020, /* 01020020 //C 0f2b0   891 mvzl	r0,32 */
0x0000f2b1, 0x0400f490, /* 0400f490 //C 0f2b1   892 call	putchar */
0x0000f2b2, 0x0400f490, /* 0400f490 //C 0f2b2   893 call	putchar */
0x0000f2b3, 0x01f2f2df, /* 01f2f2df //C 0f2b3   894 jmp	prn_ret */
0x0000f2b4, 0x0118000f, /* 0118000f //C 0f2b4   896 cmp	r1,15 */
0x0000f2b5, 0x21f2f2bd, /* 21f2f2bd //C 0f2b5   897 jnz	prn_no15 */
0x0000f2b6, 0x0102f2b9, /* 0102f2b9 //C 0f2b6   898 mvzl	r0,prn_PC */
0x0000f2b7, 0x0400f497, /* 0400f497 //C 0f2b7   899 call	prints */
0x0000f2b8, 0x01f2f2df, /* 01f2f2df //C 0f2b8   900 jmp	prn_ret */
0x0000f2b9, 0x00000050, /* 00000050 //C 0f2b9   901 db	80 */
0x0000f2ba, 0x00000043, /* 00000043 //C 0f2ba   901 db	67 */
0x0000f2bb, 0x00000020, /* 00000020 //C 0f2bb   901 db	32 */
0x0000f2bc, 0x00000000, /* 00000000 //C 0f2bc   901 db */
0x0000f2bd, 0x0118000e, /* 0118000e //C 0f2bd   903 cmp	r1,14 */
0x0000f2be, 0x21f2f2c6, /* 21f2f2c6 //C 0f2be   904 jnz	prn_no14 */
0x0000f2bf, 0x0102f2c2, /* 0102f2c2 //C 0f2bf   905 mvzl	r0,prn_LR */
0x0000f2c0, 0x0400f497, /* 0400f497 //C 0f2c0   906 call	prints */
0x0000f2c1, 0x01f2f2df, /* 01f2f2df //C 0f2c1   907 jmp	prn_ret */
0x0000f2c2, 0x0000004c, /* 0000004c //C 0f2c2   908 db	76 */
0x0000f2c3, 0x00000052, /* 00000052 //C 0f2c3   908 db	82 */
0x0000f2c4, 0x00000020, /* 00000020 //C 0f2c4   908 db	32 */
0x0000f2c5, 0x00000000, /* 00000000 //C 0f2c5   908 db */
0x0000f2c6, 0x0118000d, /* 0118000d //C 0f2c6   910 cmp	r1,13 */
0x0000f2c7, 0x21f2f2cf, /* 21f2f2cf //C 0f2c7   911 jnz	prn_no13 */
0x0000f2c8, 0x0102f2cb, /* 0102f2cb //C 0f2c8   912 mvzl	r0,prn_SP */
0x0000f2c9, 0x0400f497, /* 0400f497 //C 0f2c9   913 call	prints */
0x0000f2ca, 0x01f2f2df, /* 01f2f2df //C 0f2ca   914 jmp	prn_ret */
0x0000f2cb, 0x00000053, /* 00000053 //C 0f2cb   915 db	83 */
0x0000f2cc, 0x00000050, /* 00000050 //C 0f2cc   915 db	80 */
0x0000f2cd, 0x00000020, /* 00000020 //C 0f2cd   915 db	32 */
0x0000f2ce, 0x00000000, /* 00000000 //C 0f2ce   915 db */
0x0000f2cf, 0x01020052, /* 01020052 //C 0f2cf   917 mvzl	r0,'R' */
0x0000f2d0, 0x0400f490, /* 0400f490 //C 0f2d0   918 call	putchar */
0x0000f2d1, 0x01180009, /* 01180009 //C 0f2d1   919 cmp	r1,9 */
0x0000f2d2, 0x91f2f2d9, /* 91f2f2d9 //C 0f2d2   920 HI jmp	prn_1015 */
0x0000f2d3, 0x00000100, /* 00000100 //C 0f2d3   922 mov	r0,r1 */
0x0000f2d4, 0x01040030, /* 01040030 //C 0f2d4   923 add	r0,'0' */
0x0000f2d5, 0x0400f490, /* 0400f490 //C 0f2d5   924 call	putchar */
0x0000f2d6, 0x01020020, /* 01020020 //C 0f2d6   925 mvzl	r0,32 */
0x0000f2d7, 0x0400f490, /* 0400f490 //C 0f2d7   926 call	putchar */
0x0000f2d8, 0x01f2f2df, /* 01f2f2df //C 0f2d8   927 jmp	prn_ret */
0x0000f2d9, 0x01020031, /* 01020031 //C 0f2d9   929 mvzl	r0,'1' */
0x0000f2da, 0x0400f490, /* 0400f490 //C 0f2da   930 call	putchar */
0x0000f2db, 0x00000100, /* 00000100 //C 0f2db   931 mov	r0,r1 */
0x0000f2dc, 0x0106000a, /* 0106000a //C 0f2dc   932 sub	r0,10 */
0x0000f2dd, 0x01040030, /* 01040030 //C 0f2dd   933 add	r0,'0' */
0x0000f2de, 0x0400f490, /* 0400f490 //C 0f2de   934 call	putchar */
0x0000f2df, 0x0f1d0000, /* 0f1d0000 //C 0f2df   936 pop	r1 */
0x0000f2e0, 0x0ffd0000, /* 0ffd0000 //C 0f2e0   937 pop	pc */
0x0000f2e1, 0x0ded0000, /* 0ded0000 //C 0f2e1   942 push	lr */
0x0000f2e2, 0x0d1d0000, /* 0d1d0000 //C 0f2e2   943 push	r1 */
0x0000f2e3, 0x01080010, /* 01080010 //C 0f2e3   944 cmp	r0,16 */
0x0000f2e4, 0x91f2f2e9, /* 91f2f2e9 //C 0f2e4   945 HI jmp	prv_ret */
0x0000f2e5, 0x0112f64f, /* 0112f64f //C 0f2e5   946 mvzl	r1,reg0 */
0x0000f2e6, 0x0a010000, /* 0a010000 //C 0f2e6   947 ld	r0,r1,r0 */
0x0000f2e7, 0x01120004, /* 01120004 //C 0f2e7   948 mvzl	r1,4 */
0x0000f2e8, 0x0400f4d7, /* 0400f4d7 //C 0f2e8   949 call	print_vhex */
0x0000f2e9, 0x0f1d0000, /* 0f1d0000 //C 0f2e9   951 pop	r1 */
0x0000f2ea, 0x0ffd0000, /* 0ffd0000 //C 0f2ea   952 pop	pc */
0x0000f2eb, 0x0ded0000, /* 0ded0000 //C 0f2eb   959 push	lr */
0x0000f2ec, 0x0dad0000, /* 0dad0000 //C 0f2ec   960 push	r10 */
0x0000f2ed, 0x0d0d0000, /* 0d0d0000 //C 0f2ed   961 push	r0 */
0x0000f2ee, 0x00000a00, /* 00000a00 //C 0f2ee   962 mov	r0,r10 */
0x0000f2ef, 0x0400f2a7, /* 0400f2a7 //C 0f2ef   963 call	print_reg_name */
0x0000f2f0, 0x01020020, /* 01020020 //C 0f2f0   964 mvzl	r0,32 */
0x0000f2f1, 0x0400f490, /* 0400f490 //C 0f2f1   965 call	putchar */
0x0000f2f2, 0x00000a00, /* 00000a00 //C 0f2f2   966 mov	r0,r10 */
0x0000f2f3, 0x0400f2e1, /* 0400f2e1 //C 0f2f3   967 call	print_reg_value */
0x0000f2f4, 0x0102000a, /* 0102000a //C 0f2f4   968 mvzl	r0,LF */
0x0000f2f5, 0x0400f490, /* 0400f490 //C 0f2f5   969 call	putchar */
0x0000f2f6, 0x0f0d0000, /* 0f0d0000 //C 0f2f6   970 pop	r0 */
0x0000f2f7, 0x0fad0000, /* 0fad0000 //C 0f2f7   971 pop	r10 */
0x0000f2f8, 0x0ffd0000, /* 0ffd0000 //C 0f2f8   972 pop	pc */
0x0000f2f9, 0x0ded0000, /* 0ded0000 //C 0f2f9   980 push	lr */
0x0000f2fa, 0x0400f490, /* 0400f490 //C 0f2fa   981 call	putchar */
0x0000f2fb, 0x001c0200, /* 001c0200 //C 0f2fb   982 test	r1,r2 */
0x0000f2fc, 0x21020031, /* 21020031 //C 0f2fc   983 NZ mvzl r0,'1' */
0x0000f2fd, 0x11020030, /* 11020030 //C 0f2fd   984 Z  mvzl r0,'0' */
0x0000f2fe, 0x0400f490, /* 0400f490 //C 0f2fe   985 call	putchar */
0x0000f2ff, 0x00000300, /* 00000300 //C 0f2ff   986 mov	r0,r3 */
0x0000f300, 0x0400f490, /* 0400f490 //C 0f300   987 call	putchar */
0x0000f301, 0x0ffd0000, /* 0ffd0000 //C 0f301   988 pop	pc */
0x0000f302, 0x0ded0000, /* 0ded0000 //C 0f302   993 push	lr */
0x0000f303, 0x0700f64d, /* 0700f64d //C 0f303   994 ld	r0,called */
0x0000f304, 0x020b0000, /* 020b0000 //C 0f304   995 sz	r0 */
0x0000f305, 0x11f2f30e, /* 11f2f30e //C 0f305   996 jz	r_not_called */
0x0000f306, 0x0102f32b, /* 0102f32b //C 0f306   998 mvzl	r0,msg_r_called */
0x0000f307, 0x0400f497, /* 0400f497 //C 0f307   999 call	prints */
0x0000f308, 0x0700f65e, /* 0700f65e //C 0f308  1000 ld	r0,reg15 */
0x0000f309, 0x01120004, /* 01120004 //C 0f309  1001 mvzl	r1,4 */
0x0000f30a, 0x0400f4d7, /* 0400f4d7 //C 0f30a  1002 call	print_vhex */
0x0000f30b, 0x0102000a, /* 0102000a //C 0f30b  1003 mvzl	r0,LF */
0x0000f30c, 0x0400f490, /* 0400f490 //C 0f30c  1004 call	putchar */
0x0000f30d, 0x01f2f310, /* 01f2f310 //C 0f30d  1005 jmp	r_start */
0x0000f30e, 0x0102f341, /* 0102f341 //C 0f30e  1007 mvzl	r0,msg_r_notcalled */
0x0000f30f, 0x0400f497, /* 0400f497 //C 0f30f  1008 call	prints */
0x0000f310, 0x01a20000, /* 01a20000 //C 0f310  1010 mvzl	r10,0 */
0x0000f311, 0x0400f2eb, /* 0400f2eb //C 0f311  1012 call	print_reg_name_value */
0x0000f312, 0x01a40001, /* 01a40001 //C 0f312  1013 add	r10,1 */
0x0000f313, 0x01a80011, /* 01a80011 //C 0f313  1014 cmp	r10,17 */
0x0000f314, 0x21f2f311, /* 21f2f311 //C 0f314  1015 jnz	r_cyc */
0x0000f315, 0x0710f65f, /* 0710f65f //C 0f315  1017 ld	r1,regf */
0x0000f316, 0x01320020, /* 01320020 //C 0f316  1018 mvzl	r3,32 */
0x0000f317, 0x01020055, /* 01020055 //C 0f317  1019 mvzl	r0,'U' */
0x0000f318, 0x01220020, /* 01220020 //C 0f318  1020 mvzl	r2,0x20 */
0x0000f319, 0x0400f2f9, /* 0400f2f9 //C 0f319  1021 call	print_flag */
0x0000f31a, 0x01020050, /* 01020050 //C 0f31a  1022 mvzl	r0,'P' */
0x0000f31b, 0x01220010, /* 01220010 //C 0f31b  1023 mvzl	r2,0x10 */
0x0000f31c, 0x0400f2f9, /* 0400f2f9 //C 0f31c  1024 call	print_flag */
0x0000f31d, 0x0102004f, /* 0102004f //C 0f31d  1025 mvzl	r0,'O' */
0x0000f31e, 0x01220008, /* 01220008 //C 0f31e  1026 mvzl	r2,8 */
0x0000f31f, 0x0400f2f9, /* 0400f2f9 //C 0f31f  1027 call	print_flag */
0x0000f320, 0x0102005a, /* 0102005a //C 0f320  1028 mvzl	r0,'Z' */
0x0000f321, 0x01220004, /* 01220004 //C 0f321  1029 mvzl	r2,4 */
0x0000f322, 0x0400f2f9, /* 0400f2f9 //C 0f322  1030 call	print_flag */
0x0000f323, 0x01020043, /* 01020043 //C 0f323  1031 mvzl	r0,'C' */
0x0000f324, 0x01220002, /* 01220002 //C 0f324  1032 mvzl	r2,2 */
0x0000f325, 0x0400f2f9, /* 0400f2f9 //C 0f325  1033 call	print_flag */
0x0000f326, 0x01020053, /* 01020053 //C 0f326  1034 mvzl	r0,'S' */
0x0000f327, 0x01220001, /* 01220001 //C 0f327  1035 mvzl	r2,1 */
0x0000f328, 0x0132000a, /* 0132000a //C 0f328  1036 mvzl	r3,LF */
0x0000f329, 0x0400f2f9, /* 0400f2f9 //C 0f329  1037 call	print_flag */
0x0000f32a, 0x0ffd0000, /* 0ffd0000 //C 0f32a  1038 pop	pc */
0x0000f32b, 0x0000004d, /* 0000004d //C 0f32b  1040 db	77 */
0x0000f32c, 0x0000006f, /* 0000006f //C 0f32c  1040 db	111 */
0x0000f32d, 0x0000006e, /* 0000006e //C 0f32d  1040 db	110 */
0x0000f32e, 0x00000069, /* 00000069 //C 0f32e  1040 db	105 */
0x0000f32f, 0x00000074, /* 00000074 //C 0f32f  1040 db	116 */
0x0000f330, 0x0000006f, /* 0000006f //C 0f330  1040 db	111 */
0x0000f331, 0x00000072, /* 00000072 //C 0f331  1040 db	114 */
0x0000f332, 0x00000020, /* 00000020 //C 0f332  1040 db	32 */
0x0000f333, 0x00000063, /* 00000063 //C 0f333  1040 db	99 */
0x0000f334, 0x00000061, /* 00000061 //C 0f334  1040 db	97 */
0x0000f335, 0x0000006c, /* 0000006c //C 0f335  1040 db	108 */
0x0000f336, 0x0000006c, /* 0000006c //C 0f336  1040 db	108 */
0x0000f337, 0x00000065, /* 00000065 //C 0f337  1040 db	101 */
0x0000f338, 0x00000064, /* 00000064 //C 0f338  1040 db	100 */
0x0000f339, 0x00000020, /* 00000020 //C 0f339  1040 db	32 */
0x0000f33a, 0x00000066, /* 00000066 //C 0f33a  1040 db	102 */
0x0000f33b, 0x00000072, /* 00000072 //C 0f33b  1040 db	114 */
0x0000f33c, 0x0000006f, /* 0000006f //C 0f33c  1040 db	111 */
0x0000f33d, 0x0000006d, /* 0000006d //C 0f33d  1040 db	109 */
0x0000f33e, 0x0000003a, /* 0000003a //C 0f33e  1040 db	58 */
0x0000f33f, 0x00000020, /* 00000020 //C 0f33f  1040 db	32 */
0x0000f340, 0x00000000, /* 00000000 //C 0f340  1040 db */
0x0000f341, 0x0000004d, /* 0000004d //C 0f341  1041 db	77 */
0x0000f342, 0x0000006f, /* 0000006f //C 0f342  1041 db	111 */
0x0000f343, 0x0000006e, /* 0000006e //C 0f343  1041 db	110 */
0x0000f344, 0x00000069, /* 00000069 //C 0f344  1041 db	105 */
0x0000f345, 0x00000074, /* 00000074 //C 0f345  1041 db	116 */
0x0000f346, 0x0000006f, /* 0000006f //C 0f346  1041 db	111 */
0x0000f347, 0x00000072, /* 00000072 //C 0f347  1041 db	114 */
0x0000f348, 0x00000020, /* 00000020 //C 0f348  1041 db	32 */
0x0000f349, 0x0000006e, /* 0000006e //C 0f349  1041 db	110 */
0x0000f34a, 0x0000006f, /* 0000006f //C 0f34a  1041 db	111 */
0x0000f34b, 0x00000074, /* 00000074 //C 0f34b  1041 db	116 */
0x0000f34c, 0x00000020, /* 00000020 //C 0f34c  1041 db	32 */
0x0000f34d, 0x00000063, /* 00000063 //C 0f34d  1041 db	99 */
0x0000f34e, 0x00000061, /* 00000061 //C 0f34e  1041 db	97 */
0x0000f34f, 0x0000006c, /* 0000006c //C 0f34f  1041 db	108 */
0x0000f350, 0x0000006c, /* 0000006c //C 0f350  1041 db	108 */
0x0000f351, 0x00000065, /* 00000065 //C 0f351  1041 db	101 */
0x0000f352, 0x00000064, /* 00000064 //C 0f352  1041 db	100 */
0x0000f353, 0x00000020, /* 00000020 //C 0f353  1041 db	32 */
0x0000f354, 0x00000062, /* 00000062 //C 0f354  1041 db	98 */
0x0000f355, 0x00000079, /* 00000079 //C 0f355  1041 db	121 */
0x0000f356, 0x00000020, /* 00000020 //C 0f356  1041 db	32 */
0x0000f357, 0x00000075, /* 00000075 //C 0f357  1041 db	117 */
0x0000f358, 0x00000073, /* 00000073 //C 0f358  1041 db	115 */
0x0000f359, 0x00000065, /* 00000065 //C 0f359  1041 db	101 */
0x0000f35a, 0x00000072, /* 00000072 //C 0f35a  1041 db	114 */
0x0000f35b, 0x0000000a, /* 0000000a //C 0f35b  1041 db	10 */
0x0000f35c, 0x00000000, /* 00000000 //C 0f35c  1041 db */
0x0000f35d, 0x0ded0000, /* 0ded0000 //C 0f35d  1046 push	lr */
0x0000f35e, 0x07a0f64e, /* 07a0f64e //C 0f35e  1047 ld	r10,nuof_reg	; Reg num is in R10 */
0x0000f35f, 0x01a80010, /* 01a80010 //C 0f35f  1048 cmp	r10,16 */
0x0000f360, 0xa1f2f375, /* a1f2f375 //C 0f360  1049 LS jmp	rx_nr_ok */
0x0000f361, 0x0102f364, /* 0102f364 //C 0f361  1050 mvzl	r0,rx_err_nr */
0x0000f362, 0x0400f4d0, /* 0400f4d0 //C 0f362  1051 call	printsnl */
0x0000f363, 0x01f2f391, /* 01f2f391 //C 0f363  1052 jmp	rx_ret */
0x0000f364, 0x0000004e, /* 0000004e //C 0f364  1054 db	78 */
0x0000f365, 0x0000006f, /* 0000006f //C 0f365  1054 db	111 */
0x0000f366, 0x00000020, /* 00000020 //C 0f366  1054 db	32 */
0x0000f367, 0x00000073, /* 00000073 //C 0f367  1054 db	115 */
0x0000f368, 0x00000075, /* 00000075 //C 0f368  1054 db	117 */
0x0000f369, 0x00000063, /* 00000063 //C 0f369  1054 db	99 */
0x0000f36a, 0x00000068, /* 00000068 //C 0f36a  1054 db	104 */
0x0000f36b, 0x00000020, /* 00000020 //C 0f36b  1054 db	32 */
0x0000f36c, 0x00000072, /* 00000072 //C 0f36c  1054 db	114 */
0x0000f36d, 0x00000065, /* 00000065 //C 0f36d  1054 db	101 */
0x0000f36e, 0x00000067, /* 00000067 //C 0f36e  1054 db	103 */
0x0000f36f, 0x00000069, /* 00000069 //C 0f36f  1054 db	105 */
0x0000f370, 0x00000073, /* 00000073 //C 0f370  1054 db	115 */
0x0000f371, 0x00000074, /* 00000074 //C 0f371  1054 db	116 */
0x0000f372, 0x00000065, /* 00000065 //C 0f372  1054 db	101 */
0x0000f373, 0x00000072, /* 00000072 //C 0f373  1054 db	114 */
0x0000f374, 0x00000000, /* 00000000 //C 0f374  1054 db */
0x0000f375, 0x0122f647, /* 0122f647 //C 0f375  1056 mvzl	r2,words */
0x0000f376, 0x0e420001, /* 0e420001 //C 0f376  1057 ld	r4,r2,1		; get aof first parameter */
0x0000f377, 0x024b0000, /* 024b0000 //C 0f377  1058 sz	r4		; is it NULL? */
0x0000f378, 0x11f2f390, /* 11f2f390 //C 0f378  1059 jz	rx_print */
0x0000f379, 0x00000400, /* 00000400 //C 0f379  1060 mov	r0,r4 */
0x0000f37a, 0x0400f453, /* 0400f453 //C 0f37a  1061 call	htoi */
0x0000f37b, 0x00500100, /* 00500100 //C 0f37b  1062 mov	r5,r1		; Value is in R5 */
0x0000f37c, 0x31f2f38c, /* 31f2f38c //C 0f37c  1063 C1 jmp	rx_val_ok */
0x0000f37d, 0x0102f380, /* 0102f380 //C 0f37d  1064 mvzl	r0,rx_err_val */
0x0000f37e, 0x0400f4d0, /* 0400f4d0 //C 0f37e  1065 call	printsnl */
0x0000f37f, 0x01f2f391, /* 01f2f391 //C 0f37f  1066 jmp	rx_ret */
0x0000f380, 0x00000056, /* 00000056 //C 0f380  1068 db	86 */
0x0000f381, 0x00000061, /* 00000061 //C 0f381  1068 db	97 */
0x0000f382, 0x0000006c, /* 0000006c //C 0f382  1068 db	108 */
0x0000f383, 0x00000075, /* 00000075 //C 0f383  1068 db	117 */
0x0000f384, 0x00000065, /* 00000065 //C 0f384  1068 db	101 */
0x0000f385, 0x00000020, /* 00000020 //C 0f385  1068 db	32 */
0x0000f386, 0x00000065, /* 00000065 //C 0f386  1068 db	101 */
0x0000f387, 0x00000072, /* 00000072 //C 0f387  1068 db	114 */
0x0000f388, 0x00000072, /* 00000072 //C 0f388  1068 db	114 */
0x0000f389, 0x0000006f, /* 0000006f //C 0f389  1068 db	111 */
0x0000f38a, 0x00000072, /* 00000072 //C 0f38a  1068 db	114 */
0x0000f38b, 0x00000000, /* 00000000 //C 0f38b  1068 db */
0x0000f38c, 0x01a80010, /* 01a80010 //C 0f38c  1070 cmp	r10,16		; Flag reg? */
0x0000f38d, 0x115f003f, /* 115f003f //C 0f38d  1071 EQ and	r5,0x3f */
0x0000f38e, 0x0102f64f, /* 0102f64f //C 0f38e  1072 mvzl	r0,reg0 */
0x0000f38f, 0x08500a00, /* 08500a00 //C 0f38f  1073 st	r5,r0,r10 */
0x0000f390, 0x0400f2eb, /* 0400f2eb //C 0f390  1075 call	print_reg_name_value */
0x0000f391, 0x0ffd0000, /* 0ffd0000 //C 0f391  1077 pop	pc */
0x0000f392, 0x0102000d, /* 0102000d //C 0f392  1083 mvzl	r0,13 */
0x0000f393, 0x0600f64e, /* 0600f64e //C 0f393  1084 st	r0,nuof_reg */
0x0000f394, 0x01f2f35d, /* 01f2f35d //C 0f394  1085 jmp	cmd_rx */
0x0000f395, 0x0102000e, /* 0102000e //C 0f395  1090 mvzl	r0,14 */
0x0000f396, 0x0600f64e, /* 0600f64e //C 0f396  1091 st	r0,nuof_reg */
0x0000f397, 0x01f2f35d, /* 01f2f35d //C 0f397  1092 jmp	cmd_rx */
0x0000f398, 0x0102000f, /* 0102000f //C 0f398  1097 mvzl	r0,15 */
0x0000f399, 0x0600f64e, /* 0600f64e //C 0f399  1098 st	r0,nuof_reg */
0x0000f39a, 0x01f2f35d, /* 01f2f35d //C 0f39a  1099 jmp	cmd_rx */
0x0000f39b, 0x01020010, /* 01020010 //C 0f39b  1104 mvzl	r0,16 */
0x0000f39c, 0x0600f64e, /* 0600f64e //C 0f39c  1105 st	r0,nuof_reg */
0x0000f39d, 0x01f2f35d, /* 01f2f35d //C 0f39d  1106 jmp	cmd_rx */
0x0000f39e, 0x0d3d0000, /* 0d3d0000 //C 0f39e  1119 push	r3 */
0x0000f39f, 0x0d4d0000, /* 0d4d0000 //C 0f39f  1120 push	r4 */
0x0000f3a0, 0x01220000, /* 01220000 //C 0f3a0  1122 mvzl	r2,0		; byte index re-start */
0x0000f3a1, 0x0e310000, /* 0e310000 //C 0f3a1  1123 ld	r3,r1		; get next word */
0x0000f3a2, 0x023b0000, /* 023b0000 //C 0f3a2  1124 sz	r3		; check for eof */
0x0000f3a3, 0x11f2f3b0, /* 11f2f3b0 //C 0f3a3  1125 jz	strchr_no	; eof string found */
0x0000f3a4, 0x06414302, /* 06414302 //C 0f3a4  1127 getbz	r4,r3,r2	; pick a byte */
0x0000f3a5, 0x024b0000, /* 024b0000 //C 0f3a5  1128 sz	r4		; is it zero? */
0x0000f3a6, 0x11f2f3ac, /* 11f2f3ac //C 0f3a6  1129 jz	strchr_word	; if yes, pick next word */
0x0000f3a7, 0x00480000, /* 00480000 //C 0f3a7  1130 cmp	r4,r0		; compare */
0x0000f3a8, 0x11f2f3ae, /* 11f2f3ae //C 0f3a8  1131 jz	strchr_yes	; found it */
0x0000f3a9, 0x01240001, /* 01240001 //C 0f3a9  1133 inc	r2		; advance byte index */
0x0000f3aa, 0x01280004, /* 01280004 //C 0f3aa  1134 cmp	r2,4		; check byte overflow */
0x0000f3ab, 0x21f2f3a4, /* 21f2f3a4 //C 0f3ab  1135 jnz	strchr_go	; no, overflow, go on */
0x0000f3ac, 0x011a0001, /* 011a0001 //C 0f3ac  1137 plus	r1,1		; go to next char */
0x0000f3ad, 0x01f2f3a0, /* 01f2f3a0 //C 0f3ad  1138 jmp	strchr_cyc */
0x0000f3ae, 0x020c0000, /* 020c0000 //C 0f3ae  1140 sec */
0x0000f3af, 0x01f2f3b2, /* 01f2f3b2 //C 0f3af  1141 jmp	strchr_ret */
0x0000f3b0, 0x01120000, /* 01120000 //C 0f3b0  1143 mvzl	r1,0 */
0x0000f3b1, 0x020d0000, /* 020d0000 //C 0f3b1  1144 clc */
0x0000f3b2, 0x0f4d0000, /* 0f4d0000 //C 0f3b2  1146 pop	r4 */
0x0000f3b3, 0x0f3d0000, /* 0f3d0000 //C 0f3b3  1147 pop	r3 */
0x0000f3b4, 0x00f00e00, /* 00f00e00 //C 0f3b4  1150 ret */
0x0000f3b5, 0x0ded0000, /* 0ded0000 //C 0f3b5  1161 push	lr		; Save used registers */
0x0000f3b6, 0x0d0d0000, /* 0d0d0000 //C 0f3b6  1162 push	r0		; and input parameters */
0x0000f3b7, 0x0d2d0000, /* 0d2d0000 //C 0f3b7  1164 push	r2 */
0x0000f3b8, 0x0d4d0000, /* 0d4d0000 //C 0f3b8  1165 push	r4 */
0x0000f3b9, 0x0d5d0000, /* 0d5d0000 //C 0f3b9  1166 push	r5 */
0x0000f3ba, 0x0d6d0000, /* 0d6d0000 //C 0f3ba  1167 push	r6 */
0x0000f3bb, 0x0d7d0000, /* 0d7d0000 //C 0f3bb  1168 push	r7		; byte idx in string 1 */
0x0000f3bc, 0x0d8d0000, /* 0d8d0000 //C 0f3bc  1169 push	r8		; byte idx in string 2 */
0x0000f3bd, 0x01720000, /* 01720000 //C 0f3bd  1170 mvzl	r7,0 */
0x0000f3be, 0x01820000, /* 01820000 //C 0f3be  1171 mvzl	r8,0 */
0x0000f3bf, 0x0e200000, /* 0e200000 //C 0f3bf  1173 ld	r2,r0		; Got one char from first str */
0x0000f3c0, 0x022b0000, /* 022b0000 //C 0f3c0  1174 sz	r2		; is it eos? */
0x0000f3c1, 0x11f2f3d0, /* 11f2f3d0 //C 0f3c1  1175 jz	streq_pick2	; if yes, go on */
0x0000f3c2, 0x06214207, /* 06214207 //C 0f3c2  1176 getbz	r2,r2,r7	; pick one byte */
0x0000f3c3, 0x022b0000, /* 022b0000 //C 0f3c3  1177 sz	r2		; is it 0? */
0x0000f3c4, 0x21f2f3d0, /* 21f2f3d0 //C 0f3c4  1178 jnz	streq_pick2	; if not, go on */
0x0000f3c5, 0x01740001, /* 01740001 //C 0f3c5  1179 inc	r7		; step to next byte */
0x0000f3c6, 0x01780004, /* 01780004 //C 0f3c6  1180 cmp	r7,4		; word is overflowed? */
0x0000f3c7, 0x11f2f3cc, /* 11f2f3cc //C 0f3c7  1181 jz	streq_p1ov */
0x0000f3c8, 0x0e200000, /* 0e200000 //C 0f3c8  1183 ld	r2,r0		; pick orig word, and */
0x0000f3c9, 0x06214207, /* 06214207 //C 0f3c9  1184 getbz	r2,r2,r7	; check next byte */
0x0000f3ca, 0x022b0000, /* 022b0000 //C 0f3ca  1185 sz	r2		; is it 0? */
0x0000f3cb, 0x21f2f3d0, /* 21f2f3d0 //C 0f3cb  1186 jnz	streq_pick2	; if not, go on */
0x0000f3cc, 0x01040001, /* 01040001 //C 0f3cc  1188 inc	r0		; if yes, move pointer */
0x0000f3cd, 0x01720000, /* 01720000 //C 0f3cd  1189 mvzl	r7,0		; and reset byte counter */
0x0000f3ce, 0x0e200000, /* 0e200000 //C 0f3ce  1190 ld	r2,r0		; get first byte of next word */
0x0000f3cf, 0x06214207, /* 06214207 //C 0f3cf  1191 getbz	r2,r2,r7 */
0x0000f3d0, 0x0e610000, /* 0e610000 //C 0f3d0  1194 ld	r6,r1		; pick from second string */
0x0000f3d1, 0x026b0000, /* 026b0000 //C 0f3d1  1195 sz	r6		; is it eos? */
0x0000f3d2, 0x11f2f3e1, /* 11f2f3e1 //C 0f3d2  1196 jz	streq_prep	; if yes, go to compare */
0x0000f3d3, 0x06614608, /* 06614608 //C 0f3d3  1197 getbz	r6,r6,r8	; pick a byte */
0x0000f3d4, 0x026b0000, /* 026b0000 //C 0f3d4  1198 sz	r6		; is it 0? */
0x0000f3d5, 0x21f2f3e1, /* 21f2f3e1 //C 0f3d5  1199 jnz	streq_prep	; if not, go to compare */
0x0000f3d6, 0x01840001, /* 01840001 //C 0f3d6  1200 inc	r8		; step to next byte */
0x0000f3d7, 0x01880004, /* 01880004 //C 0f3d7  1201 cmp	r8,4		; is word overflowed? */
0x0000f3d8, 0x11f2f3dd, /* 11f2f3dd //C 0f3d8  1202 jz	streq_p2ov */
0x0000f3d9, 0x0e610000, /* 0e610000 //C 0f3d9  1204 ld	r6,r1		; pick orig word, and */
0x0000f3da, 0x06614608, /* 06614608 //C 0f3da  1205 getbz	r6,r6,r8	; check next byte */
0x0000f3db, 0x026b0000, /* 026b0000 //C 0f3db  1206 sz	r6		; is it 0? */
0x0000f3dc, 0x21f2f3e1, /* 21f2f3e1 //C 0f3dc  1207 jnz	streq_prep	; if not, go on */
0x0000f3dd, 0x01140001, /* 01140001 //C 0f3dd  1209 inc	r1		; if yes, move pointer */
0x0000f3de, 0x01820000, /* 01820000 //C 0f3de  1210 mvzl	r8,0		; and reset byte counter */
0x0000f3df, 0x0e610000, /* 0e610000 //C 0f3df  1211 ld	r6,r1		; get next word */
0x0000f3e0, 0x06614608, /* 06614608 //C 0f3e0  1212 getbz	r6,r6,r8	; and pick first byte */
0x0000f3e1, 0x023b0000, /* 023b0000 //C 0f3e1  1215 sz	r3		; Prepare for comparing */
0x0000f3e2, 0x112d0020, /* 112d0020 //C 0f3e2  1216 Z1 or	r2,0x20		; if insensitive case */
0x0000f3e3, 0x023b0000, /* 023b0000 //C 0f3e3  1217 sz	r3 */
0x0000f3e4, 0x116d0020, /* 116d0020 //C 0f3e4  1218 Z1 or	r6,0x20 */
0x0000f3e5, 0x00280600, /* 00280600 //C 0f3e5  1219 cmp	r2,r6		; compare them */
0x0000f3e6, 0x21f2f400, /* 21f2f400 //C 0f3e6  1220 jnz	streq_no	; if differs: strings are not equal */
0x0000f3e7, 0x0e200000, /* 0e200000 //C 0f3e7  1222 ld	r2,r0		; Pick original (non-prepared) */
0x0000f3e8, 0x0e610000, /* 0e610000 //C 0f3e8  1223 ld	r6,r1		; chars to check EOS */
0x0000f3e9, 0x06214207, /* 06214207 //C 0f3e9  1224 getbz	r2,r2,r7 */
0x0000f3ea, 0x06614608, /* 06614608 //C 0f3ea  1225 getbz	r6,r6,r8 */
0x0000f3eb, 0x022b0000, /* 022b0000 //C 0f3eb  1226 sz	r2		; convert them to boolean */
0x0000f3ec, 0x21220001, /* 21220001 //C 0f3ec  1227 Z0 mvzl	r2,1		; values in R2,R6 */
0x0000f3ed, 0x11220000, /* 11220000 //C 0f3ed  1228 Z1 mvzl	r2,0		; and copy in R4,R5 */
0x0000f3ee, 0x00400200, /* 00400200 //C 0f3ee  1229 mov	r4,r2 */
0x0000f3ef, 0x026b0000, /* 026b0000 //C 0f3ef  1230 sz	r6 */
0x0000f3f0, 0x21620001, /* 21620001 //C 0f3f0  1231 Z0 mvzl	r6,1 */
0x0000f3f1, 0x11620000, /* 11620000 //C 0f3f1  1232 Z1 mvzl r6,0 */
0x0000f3f2, 0x00500600, /* 00500600 //C 0f3f2  1233 mov	r5,r6 */
0x0000f3f3, 0x004d0500, /* 004d0500 //C 0f3f3  1234 or	r4,r5		; if both are EOS: equal */
0x0000f3f4, 0x11f2f402, /* 11f2f402 //C 0f3f4  1235 jz	streq_yes */
0x0000f3f5, 0x002f0600, /* 002f0600 //C 0f3f5  1236 and 	r2,r6		; just one is EOS: not equal */
0x0000f3f6, 0x11f2f400, /* 11f2f400 //C 0f3f6  1237 jz	streq_no */
0x0000f3f7, 0x01740001, /* 01740001 //C 0f3f7  1240 inc	r7		; step byte count */
0x0000f3f8, 0x01780004, /* 01780004 //C 0f3f8  1241 cmp	r7,4		; if word overflows */
0x0000f3f9, 0x110a0001, /* 110a0001 //C 0f3f9  1242 Z plus	r0,1		; then step the pointer */
0x0000f3fa, 0x11720000, /* 11720000 //C 0f3fa  1243 Z mvzl	r7,0		; and reset the byte counter */
0x0000f3fb, 0x01840001, /* 01840001 //C 0f3fb  1245 inc	r8 */
0x0000f3fc, 0x01880004, /* 01880004 //C 0f3fc  1246 cmp	r8,4 */
0x0000f3fd, 0x111a0001, /* 111a0001 //C 0f3fd  1247 Z plus	r1,1 */
0x0000f3fe, 0x11820000, /* 11820000 //C 0f3fe  1248 Z mvzl	r8,0 */
0x0000f3ff, 0x01f2f3bf, /* 01f2f3bf //C 0f3ff  1249 jmp	streq_cyc */
0x0000f400, 0x020d0000, /* 020d0000 //C 0f400  1252 clc			; False result */
0x0000f401, 0x01f2f403, /* 01f2f403 //C 0f401  1253 jmp	streq_ret */
0x0000f402, 0x020c0000, /* 020c0000 //C 0f402  1256 sec			; True result */
0x0000f403, 0x0e610000, /* 0e610000 //C 0f403  1259 ld	r6,r1		; forward R1 to EOS */
0x0000f404, 0x026b0000, /* 026b0000 //C 0f404  1260 sz	r6 */
0x0000f405, 0x11f2f408, /* 11f2f408 //C 0f405  1261 jz	streq_ret_ret */
0x0000f406, 0x01140001, /* 01140001 //C 0f406  1262 inc	r1 */
0x0000f407, 0x01f2f403, /* 01f2f403 //C 0f407  1263 jmp	streq_ret */
0x0000f408, 0x0f8d0000, /* 0f8d0000 //C 0f408  1265 pop	r8 */
0x0000f409, 0x0f7d0000, /* 0f7d0000 //C 0f409  1266 pop	r7 */
0x0000f40a, 0x0f6d0000, /* 0f6d0000 //C 0f40a  1267 pop	r6 */
0x0000f40b, 0x0f5d0000, /* 0f5d0000 //C 0f40b  1268 pop	r5 */
0x0000f40c, 0x0f4d0000, /* 0f4d0000 //C 0f40c  1269 pop	r4 */
0x0000f40d, 0x0f2d0000, /* 0f2d0000 //C 0f40d  1270 pop	r2 */
0x0000f40e, 0x0f0d0000, /* 0f0d0000 //C 0f40e  1272 pop	r0 */
0x0000f40f, 0x0ffd0000, /* 0ffd0000 //C 0f40f  1273 pop	pc */
0x0000f410, 0x0ded0000, /* 0ded0000 //C 0f410  1281 push	lr */
0x0000f411, 0x0d1d0000, /* 0d1d0000 //C 0f411  1282 push	r1 */
0x0000f412, 0x0d3d0000, /* 0d3d0000 //C 0f412  1283 push	r3 */
0x0000f413, 0x01320001, /* 01320001 //C 0f413  1284 mvzl	r3,1 */
0x0000f414, 0x0400f3b5, /* 0400f3b5 //C 0f414  1285 call	str_cmp_eq */
0x0000f415, 0x0f3d0000, /* 0f3d0000 //C 0f415  1286 pop	r3 */
0x0000f416, 0x0f1d0000, /* 0f1d0000 //C 0f416  1287 pop	r1 */
0x0000f417, 0x0ffd0000, /* 0ffd0000 //C 0f417  1288 pop	pc */
0x0000f418, 0x0ded0000, /* 0ded0000 //C 0f418  1296 push	lr */
0x0000f419, 0x0d1d0000, /* 0d1d0000 //C 0f419  1297 push	r1 */
0x0000f41a, 0x0d3d0000, /* 0d3d0000 //C 0f41a  1298 push	r3 */
0x0000f41b, 0x01320000, /* 01320000 //C 0f41b  1299 mvzl	r3,0 */
0x0000f41c, 0x0400f3b5, /* 0400f3b5 //C 0f41c  1300 call	str_cmp_eq */
0x0000f41d, 0x0f3d0000, /* 0f3d0000 //C 0f41d  1301 pop	r3 */
0x0000f41e, 0x0f1d0000, /* 0f1d0000 //C 0f41e  1302 pop	r1 */
0x0000f41f, 0x0ffd0000, /* 0ffd0000 //C 0f41f  1303 pop	pc */
0x0000f420, 0x0108002f, /* 0108002f //C 0f420  1312 cmp	r0,'/' */
0x0000f421, 0xa1f2f436, /* a1f2f436 //C 0f421  1313 LS jmp	hc2v_nok */
0x0000f422, 0x01080039, /* 01080039 //C 0f422  1314 cmp	r0,'9' */
0x0000f423, 0xa1f2f433, /* a1f2f433 //C 0f423  1315 LS jmp	hc2v_0_9 */
0x0000f424, 0x01080040, /* 01080040 //C 0f424  1316 cmp	r0,'@' */
0x0000f425, 0xa1f2f436, /* a1f2f436 //C 0f425  1317 LS jmp	hc2v_nok */
0x0000f426, 0x01080046, /* 01080046 //C 0f426  1318 cmp	r0,'F' */
0x0000f427, 0xa1f2f430, /* a1f2f430 //C 0f427  1319 LS jmp	hc2v_A_F */
0x0000f428, 0x01080060, /* 01080060 //C 0f428  1320 cmp	r0,'`' */
0x0000f429, 0xa1f2f436, /* a1f2f436 //C 0f429  1321 LS jmp	hc2v_nok */
0x0000f42a, 0x01080066, /* 01080066 //C 0f42a  1322 cmp	r0,'f' */
0x0000f42b, 0xa1f2f42d, /* a1f2f42d //C 0f42b  1323 LS jmp	hc2v_a_f */
0x0000f42c, 0x01f2f436, /* 01f2f436 //C 0f42c  1324 jmp	hc2v_nok */
0x0000f42d, 0x0104000a, /* 0104000a //C 0f42d  1326 add	r0,10 */
0x0000f42e, 0x01060061, /* 01060061 //C 0f42e  1327 sub	r0,'a' */
0x0000f42f, 0x01f2f434, /* 01f2f434 //C 0f42f  1328 jmp	hc2v_ok */
0x0000f430, 0x0104000a, /* 0104000a //C 0f430  1330 add	r0,10 */
0x0000f431, 0x01060041, /* 01060041 //C 0f431  1331 sub	r0,'A' */
0x0000f432, 0x01f2f434, /* 01f2f434 //C 0f432  1332 jmp	hc2v_ok */
0x0000f433, 0x01060030, /* 01060030 //C 0f433  1334 sub	r0,'0' */
0x0000f434, 0x020c0000, /* 020c0000 //C 0f434  1336 sec */
0x0000f435, 0x00f00e00, /* 00f00e00 //C 0f435  1337 ret */
0x0000f436, 0x020d0000, /* 020d0000 //C 0f436  1339 clc */
0x0000f437, 0x00f00e00, /* 00f00e00 //C 0f437  1340 ret */
0x0000f438, 0x0d1d0000, /* 0d1d0000 //C 0f438  1344 push	r1 */
0x0000f439, 0x010f000f, /* 010f000f //C 0f439  1345 and	r0,0xf */
0x0000f43a, 0x0112f43e, /* 0112f43e //C 0f43a  1346 mvzl	r1,v2hc_table */
0x0000f43b, 0x0a010000, /* 0a010000 //C 0f43b  1347 ld	r0,r1,r0 */
0x0000f43c, 0x0f1d0000, /* 0f1d0000 //C 0f43c  1348 pop	r1 */
0x0000f43d, 0x00f00e00, /* 00f00e00 //C 0f43d  1349 ret */
0x0000f43e, 0x00000030, /* 00000030 //C 0f43e  1350 db	48 */
0x0000f43f, 0x00000031, /* 00000031 //C 0f43f  1350 db	49 */
0x0000f440, 0x00000032, /* 00000032 //C 0f440  1350 db	50 */
0x0000f441, 0x00000033, /* 00000033 //C 0f441  1350 db	51 */
0x0000f442, 0x00000034, /* 00000034 //C 0f442  1350 db	52 */
0x0000f443, 0x00000035, /* 00000035 //C 0f443  1350 db	53 */
0x0000f444, 0x00000036, /* 00000036 //C 0f444  1350 db	54 */
0x0000f445, 0x00000037, /* 00000037 //C 0f445  1350 db	55 */
0x0000f446, 0x00000038, /* 00000038 //C 0f446  1350 db	56 */
0x0000f447, 0x00000039, /* 00000039 //C 0f447  1350 db	57 */
0x0000f448, 0x00000041, /* 00000041 //C 0f448  1350 db	65 */
0x0000f449, 0x00000042, /* 00000042 //C 0f449  1350 db	66 */
0x0000f44a, 0x00000043, /* 00000043 //C 0f44a  1350 db	67 */
0x0000f44b, 0x00000044, /* 00000044 //C 0f44b  1350 db	68 */
0x0000f44c, 0x00000045, /* 00000045 //C 0f44c  1350 db	69 */
0x0000f44d, 0x00000046, /* 00000046 //C 0f44d  1350 db	70 */
0x0000f44e, 0x00000000, /* 00000000 //C 0f44e  1350 db */
0x0000f44f, 0x0ded0000, /* 0ded0000 //C 0f44f  1353 push	lr */
0x0000f450, 0x0400f438, /* 0400f438 //C 0f450  1354 call	value2Hexchar */
0x0000f451, 0x010d0020, /* 010d0020 //C 0f451  1355 or	r0,0x20 */
0x0000f452, 0x0ffd0000, /* 0ffd0000 //C 0f452  1356 pop	pc */
0x0000f453, 0x0ded0000, /* 0ded0000 //C 0f453  1365 push	lr */
0x0000f454, 0x0d2d0000, /* 0d2d0000 //C 0f454  1366 push	r2 */
0x0000f455, 0x0d3d0000, /* 0d3d0000 //C 0f455  1367 push	r3 */
0x0000f456, 0x0d4d0000, /* 0d4d0000 //C 0f456  1368 push	r4 */
0x0000f457, 0x0d5d0000, /* 0d5d0000 //C 0f457  1369 push	r5 */
0x0000f458, 0x01120000, /* 01120000 //C 0f458  1370 mvzl	r1,0		; return value */
0x0000f459, 0x01320000, /* 01320000 //C 0f459  1371 mvzl	r3,0		; index */
0x0000f45a, 0x01520000, /* 01520000 //C 0f45a  1373 mvzl	r5,0 */
0x0000f45b, 0x0b438000, /* 0b438000 //C 0f45b  1374 ld	r4,r3+,r0	; pick a char */
0x0000f45c, 0x024b0000, /* 024b0000 //C 0f45c  1375 sz	r4		; check eof string */
0x0000f45d, 0x11f2f479, /* 11f2f479 //C 0f45d  1376 jz	htoi_eos */
0x0000f45e, 0x06214405, /* 06214405 //C 0f45e  1378 getbz	r2,r4,r5 */
0x0000f45f, 0x022b0000, /* 022b0000 //C 0f45f  1379 sz	r2 */
0x0000f460, 0x11f2f45a, /* 11f2f45a //C 0f460  1380 jz	htoi_cyc */
0x0000f461, 0x0128002e, /* 0128002e //C 0f461  1381 cmp	r2,'.'		; skip separators */
0x0000f462, 0x11f2f473, /* 11f2f473 //C 0f462  1382 jz	htoi_next */
0x0000f463, 0x0128005f, /* 0128005f //C 0f463  1383 cmp	r2,'_' */
0x0000f464, 0x11f2f473, /* 11f2f473 //C 0f464  1384 jz	htoi_next */
0x0000f465, 0x0128002d, /* 0128002d //C 0f465  1385 cmp	r2,'-' */
0x0000f466, 0x11f2f473, /* 11f2f473 //C 0f466  1386 jz	htoi_next */
0x0000f467, 0x0d0d0000, /* 0d0d0000 //C 0f467  1387 push	r0 */
0x0000f468, 0x00000200, /* 00000200 //C 0f468  1388 mov	r0,r2 */
0x0000f469, 0x0400f420, /* 0400f420 //C 0f469  1389 call	hexchar2value */
0x0000f46a, 0x00200000, /* 00200000 //C 0f46a  1390 mov	r2,r0 */
0x0000f46b, 0x0f0d0000, /* 0f0d0000 //C 0f46b  1391 pop	r0 */
0x0000f46c, 0x41f2f477, /* 41f2f477 //C 0f46c  1392 C0 jmp	htoi_nok */
0x0000f46d, 0x02180000, /* 02180000 //C 0f46d  1393 shl	r1 */
0x0000f46e, 0x02180000, /* 02180000 //C 0f46e  1394 shl	r1 */
0x0000f46f, 0x02180000, /* 02180000 //C 0f46f  1395 shl	r1 */
0x0000f470, 0x02180000, /* 02180000 //C 0f470  1396 shl	r1 */
0x0000f471, 0x012f000f, /* 012f000f //C 0f471  1397 and	r2,0xf */
0x0000f472, 0x001d0200, /* 001d0200 //C 0f472  1398 or	r1,r2 */
0x0000f473, 0x01540001, /* 01540001 //C 0f473  1400 inc	r5 */
0x0000f474, 0x01580004, /* 01580004 //C 0f474  1401 cmp	r5,4 */
0x0000f475, 0x11f2f45a, /* 11f2f45a //C 0f475  1402 jz	htoi_cyc */
0x0000f476, 0x01f2f45e, /* 01f2f45e //C 0f476  1403 jmp	htoi_byte */
0x0000f477, 0x020d0000, /* 020d0000 //C 0f477  1405 clc */
0x0000f478, 0x01f2f47c, /* 01f2f47c //C 0f478  1406 jmp	htoi_ret */
0x0000f479, 0x01380001, /* 01380001 //C 0f479  1408 cmp	r3,1 */
0x0000f47a, 0x920d0000, /* 920d0000 //C 0f47a  1409 HI clc */
0x0000f47b, 0xa20c0000, /* a20c0000 //C 0f47b  1410 LS sec */
0x0000f47c, 0x0f5d0000, /* 0f5d0000 //C 0f47c  1412 pop	r5 */
0x0000f47d, 0x0f4d0000, /* 0f4d0000 //C 0f47d  1413 pop	r4 */
0x0000f47e, 0x0f3d0000, /* 0f3d0000 //C 0f47e  1414 pop	r3 */
0x0000f47f, 0x0f2d0000, /* 0f2d0000 //C 0f47f  1415 pop	r2 */
0x0000f480, 0x0ffd0000, /* 0ffd0000 //C 0f480  1416 pop	pc */
0x0000f481, 0x0d0d0000, /* 0d0d0000 //C 0f481  1428 push	r0 */
0x0000f482, 0x0700ff42, /* 0700ff42 //C 0f482  1429 ld	r0,UART_RSTAT */
0x0000f483, 0x010c0001, /* 010c0001 //C 0f483  1431 test	r0,1		; check if queue is not empty */
0x0000f484, 0x020d0000, /* 020d0000 //C 0f484  1432 clc */
0x0000f485, 0x220c0000, /* 220c0000 //C 0f485  1433 Z0 sec */
0x0000f486, 0x0f0d0000, /* 0f0d0000 //C 0f486  1434 pop	r0 */
0x0000f487, 0x30f00e00, /* 30f00e00 //C 0f487  1435 C1 ret */
0x0000f488, 0x00f00e00, /* 00f00e00 //C 0f488  1436 ret */
0x0000f489, 0x0700ff40, /* 0700ff40 //C 0f489  1481 ld	r0,UART_DR */
0x0000f48a, 0x0600ff46, /* 0600ff46 //C 0f48a  1482 st	r0,UART_IRA */
0x0000f48b, 0x00f00e00, /* 00f00e00 //C 0f48b  1483 ret */
0x0000f48c, 0x0400f481, /* 0400f481 //C 0f48c  1515 call	check_uart */
0x0000f48d, 0x41f2f48c, /* 41f2f48c //C 0f48d  1516 C0 jmp	getchar */
0x0000f48e, 0x0400f489, /* 0400f489 //C 0f48e  1517 call	read */
0x0000f48f, 0x00f00e00, /* 00f00e00 //C 0f48f  1518 ret */
0x0000f490, 0x0d9d0000, /* 0d9d0000 //C 0f490  1526 push	r9 */
0x0000f491, 0x0790ff43, /* 0790ff43 //C 0f491  1533 ld	r9,UART_TSTAT */
0x0000f492, 0x019c0001, /* 019c0001 //C 0f492  1534 test	r9,1 */
0x0000f493, 0x11f2f491, /* 11f2f491 //C 0f493  1535 jz	wait_tc */
0x0000f494, 0x0600ff40, /* 0600ff40 //C 0f494  1536 st	r0,UART_DR */
0x0000f495, 0x0f9d0000, /* 0f9d0000 //C 0f495  1538 pop	r9 */
0x0000f496, 0x00f00e00, /* 00f00e00 //C 0f496  1539 ret */
0x0000f497, 0x0ded0000, /* 0ded0000 //C 0f497  1547 push	lr */
0x0000f498, 0x0d0d0000, /* 0d0d0000 //C 0f498  1548 push	r0 */
0x0000f499, 0x0d3d0000, /* 0d3d0000 //C 0f499  1549 push	r3 */
0x0000f49a, 0x0d4d0000, /* 0d4d0000 //C 0f49a  1550 push	r4 */
0x0000f49b, 0x0d2d0000, /* 0d2d0000 //C 0f49b  1551 push	r2 */
0x0000f49c, 0x0d1d0000, /* 0d1d0000 //C 0f49c  1552 push	r1 */
0x0000f49d, 0x0d5d0000, /* 0d5d0000 //C 0f49d  1553 push	r5 */
0x0000f49e, 0x01420000, /* 01420000 //C 0f49e  1555 mvzl	r4,0 */
0x0000f49f, 0x020b0000, /* 020b0000 //C 0f49f  1556 sz	r0 */
0x0000f4a0, 0x1102f687, /* 1102f687 //C 0f4a0  1557 Z1 mvzl	r0,null_str */
0x0000f4a1, 0x00200000, /* 00200000 //C 0f4a1  1558 mov	r2,r0 */
0x0000f4a2, 0x0b148200, /* 0b148200 //C 0f4a2  1560 ld	r1,r4+,r2 */
0x0000f4a3, 0x021b0000, /* 021b0000 //C 0f4a3  1561 sz	r1 */
0x0000f4a4, 0x01520000, /* 01520000 //C 0f4a4  1562 mvzl	r5,0 */
0x0000f4a5, 0x11f2f4ae, /* 11f2f4ae //C 0f4a5  1563 jz	prints_done */
0x0000f4a6, 0x06014105, /* 06014105 //C 0f4a6  1565 getbz	r0,r1,r5 */
0x0000f4a7, 0x020b0000, /* 020b0000 //C 0f4a7  1566 sz	r0 */
0x0000f4a8, 0x2400f490, /* 2400f490 //C 0f4a8  1567 NZ call	putchar */
0x0000f4a9, 0x11f2f4a2, /* 11f2f4a2 //C 0f4a9  1568 jz 	prints_go */
0x0000f4aa, 0x01540001, /* 01540001 //C 0f4aa  1569 inc	r5 */
0x0000f4ab, 0x01580004, /* 01580004 //C 0f4ab  1570 cmp	r5,4 */
0x0000f4ac, 0x21f2f4a6, /* 21f2f4a6 //C 0f4ac  1571 jnz	prints_byte */
0x0000f4ad, 0x01f2f4a2, /* 01f2f4a2 //C 0f4ad  1572 jmp	prints_go */
0x0000f4ae, 0x0f5d0000, /* 0f5d0000 //C 0f4ae  1575 pop	r5 */
0x0000f4af, 0x0f1d0000, /* 0f1d0000 //C 0f4af  1576 pop	r1 */
0x0000f4b0, 0x0f2d0000, /* 0f2d0000 //C 0f4b0  1577 pop	r2 */
0x0000f4b1, 0x0f4d0000, /* 0f4d0000 //C 0f4b1  1578 pop	r4 */
0x0000f4b2, 0x0f3d0000, /* 0f3d0000 //C 0f4b2  1579 pop	r3 */
0x0000f4b3, 0x0f0d0000, /* 0f0d0000 //C 0f4b3  1580 pop	r0 */
0x0000f4b4, 0x0ffd0000, /* 0ffd0000 //C 0f4b4  1581 pop	pc */
0x0000f4b5, 0x00000000, /* 00000000 //C 0f4b5  1589 dd	0 */
0x0000f4b6, 0x0ded0000, /* 0ded0000 //C 0f4b6  1592 push	lr */
0x0000f4b7, 0x0d0d0000, /* 0d0d0000 //C 0f4b7  1593 push	r0 */
0x0000f4b8, 0x0d1d0000, /* 0d1d0000 //C 0f4b8  1594 push	r1 */
0x0000f4b9, 0x0d2d0000, /* 0d2d0000 //C 0f4b9  1595 push	r2 */
0x0000f4ba, 0x0d3d0000, /* 0d3d0000 //C 0f4ba  1596 push	r3 */
0x0000f4bb, 0x00100e00, /* 00100e00 //C 0f4bb  1597 mov	r1,lr */
0x0000f4bc, 0x0e210000, /* 0e210000 //C 0f4bc  1599 ld	r2,r1 */
0x0000f4bd, 0x01140001, /* 01140001 //C 0f4bd  1600 inc	r1 */
0x0000f4be, 0x022b0000, /* 022b0000 //C 0f4be  1601 sz	r2 */
0x0000f4bf, 0x11f2f4c9, /* 11f2f4c9 //C 0f4bf  1602 jz	pes_done */
0x0000f4c0, 0x01320000, /* 01320000 //C 0f4c0  1603 mvzl	r3,0 */
0x0000f4c1, 0x06014203, /* 06014203 //C 0f4c1  1605 getbz	r0,r2,r3 */
0x0000f4c2, 0x020b0000, /* 020b0000 //C 0f4c2  1606 sz	r0 */
0x0000f4c3, 0x2400f490, /* 2400f490 //C 0f4c3  1607 NZ call	putchar */
0x0000f4c4, 0x11f2f4bc, /* 11f2f4bc //C 0f4c4  1608 jz	pes_next */
0x0000f4c5, 0x01340001, /* 01340001 //C 0f4c5  1609 inc	r3 */
0x0000f4c6, 0x01380004, /* 01380004 //C 0f4c6  1610 cmp	r3,4 */
0x0000f4c7, 0x21f2f4c1, /* 21f2f4c1 //C 0f4c7  1611 jnz	pes_byte */
0x0000f4c8, 0x01f2f4bc, /* 01f2f4bc //C 0f4c8  1612 jmp	pes_next */
0x0000f4c9, 0x0610f4b5, /* 0610f4b5 //C 0f4c9  1614 st	r1,pes_ret_to */
0x0000f4ca, 0x0f3d0000, /* 0f3d0000 //C 0f4ca  1615 pop	r3 */
0x0000f4cb, 0x0f2d0000, /* 0f2d0000 //C 0f4cb  1616 pop	r2 */
0x0000f4cc, 0x0f1d0000, /* 0f1d0000 //C 0f4cc  1617 pop	r1 */
0x0000f4cd, 0x0f0d0000, /* 0f0d0000 //C 0f4cd  1618 pop	r0 */
0x0000f4ce, 0x0fed0000, /* 0fed0000 //C 0f4ce  1619 pop	lr */
0x0000f4cf, 0x07f0f4b5, /* 07f0f4b5 //C 0f4cf  1620 ld	pc,pes_ret_to */
0x0000f4d0, 0x0ded0000, /* 0ded0000 //C 0f4d0  1628 push	lr */
0x0000f4d1, 0x0400f497, /* 0400f497 //C 0f4d1  1629 call	prints */
0x0000f4d2, 0x0d0d0000, /* 0d0d0000 //C 0f4d2  1630 push	r0 */
0x0000f4d3, 0x0102000a, /* 0102000a //C 0f4d3  1631 mvzl	r0,LF */
0x0000f4d4, 0x0400f490, /* 0400f490 //C 0f4d4  1632 call	putchar */
0x0000f4d5, 0x0f0d0000, /* 0f0d0000 //C 0f4d5  1633 pop	r0 */
0x0000f4d6, 0x0ffd0000, /* 0ffd0000 //C 0f4d6  1634 pop	pc */
0x0000f4d7, 0x0ded0000, /* 0ded0000 //C 0f4d7  1642 push	lr */
0x0000f4d8, 0x0d0d0000, /* 0d0d0000 //C 0f4d8  1643 push	r0 */
0x0000f4d9, 0x0d1d0000, /* 0d1d0000 //C 0f4d9  1644 push	r1 */
0x0000f4da, 0x0d2d0000, /* 0d2d0000 //C 0f4da  1645 push	r2 */
0x0000f4db, 0x0d3d0000, /* 0d3d0000 //C 0f4db  1646 push	r3 */
0x0000f4dc, 0x0d4d0000, /* 0d4d0000 //C 0f4dc  1647 push	r4 */
0x0000f4dd, 0x00300000, /* 00300000 //C 0f4dd  1648 mov	r3,r0 */
0x0000f4de, 0x01220000, /* 01220000 //C 0f4de  1649 mvzl	r2,0 */
0x0000f4df, 0x01420001, /* 01420001 //C 0f4df  1650 mvzl	r4,1 */
0x0000f4e0, 0x01020000, /* 01020000 //C 0f4e0  1653 mvzl	r0,0 */
0x0000f4e1, 0x02380000, /* 02380000 //C 0f4e1  1654 shl	r3 */
0x0000f4e2, 0x02070000, /* 02070000 //C 0f4e2  1655 rol	r0 */
0x0000f4e3, 0x02380000, /* 02380000 //C 0f4e3  1656 shl	r3 */
0x0000f4e4, 0x02070000, /* 02070000 //C 0f4e4  1657 rol	r0 */
0x0000f4e5, 0x02380000, /* 02380000 //C 0f4e5  1658 shl	r3 */
0x0000f4e6, 0x02070000, /* 02070000 //C 0f4e6  1659 rol	r0 */
0x0000f4e7, 0x02380000, /* 02380000 //C 0f4e7  1660 shl	r3 */
0x0000f4e8, 0x02070000, /* 02070000 //C 0f4e8  1661 rol	r0 */
0x0000f4e9, 0x0400f438, /* 0400f438 //C 0f4e9  1662 call	value2Hexchar */
0x0000f4ea, 0x0400f490, /* 0400f490 //C 0f4ea  1663 call	putchar */
0x0000f4eb, 0x01240001, /* 01240001 //C 0f4eb  1664 add	r2,1 */
0x0000f4ec, 0x01280008, /* 01280008 //C 0f4ec  1665 cmp	r2,8 */
0x0000f4ed, 0x11f2f4f7, /* 11f2f4f7 //C 0f4ed  1666 jz	print_vhex_ret */
0x0000f4ee, 0x021b0000, /* 021b0000 //C 0f4ee  1667 sz	r1 */
0x0000f4ef, 0x11f2f4f5, /* 11f2f4f5 //C 0f4ef  1668 jz	print_vhex_nosep */
0x0000f4f0, 0x00480100, /* 00480100 //C 0f4f0  1669 cmp	r4,r1 */
0x0000f4f1, 0x21f2f4f5, /* 21f2f4f5 //C 0f4f1  1670 jnz	print_vhex_nosep */
0x0000f4f2, 0x0102005f, /* 0102005f //C 0f4f2  1671 mvzl	r0,'_' */
0x0000f4f3, 0x0400f490, /* 0400f490 //C 0f4f3  1672 call	putchar */
0x0000f4f4, 0x01420000, /* 01420000 //C 0f4f4  1673 mvzl	r4,0 */
0x0000f4f5, 0x01440001, /* 01440001 //C 0f4f5  1675 add	r4,1 */
0x0000f4f6, 0x01f2f4e0, /* 01f2f4e0 //C 0f4f6  1676 jmp	print_vhex_cyc */
0x0000f4f7, 0x0f4d0000, /* 0f4d0000 //C 0f4f7  1678 pop	r4 */
0x0000f4f8, 0x0f3d0000, /* 0f3d0000 //C 0f4f8  1679 pop	r3 */
0x0000f4f9, 0x0f2d0000, /* 0f2d0000 //C 0f4f9  1680 pop	r2 */
0x0000f4fa, 0x0f1d0000, /* 0f1d0000 //C 0f4fa  1681 pop	r1 */
0x0000f4fb, 0x0f0d0000, /* 0f0d0000 //C 0f4fb  1682 pop	r0 */
0x0000f4fc, 0x0ffd0000, /* 0ffd0000 //C 0f4fc  1683 pop	pc */
0x0000f4fd, 0x0ded0000, /* 0ded0000 //C 0f4fd  1691 push	lr */
0x0000f4fe, 0x0d4d0000, /* 0d4d0000 //C 0f4fe  1692 push	r4 */
0x0000f4ff, 0x021b0000, /* 021b0000 //C 0f4ff  1694 sz	r1 */
0x0000f500, 0x21f2f504, /* 21f2f504 //C 0f500  1695 NZ jmp	div_dok */
0x0000f501, 0x00200000, /* 00200000 //C 0f501  1696 mov	r2,r0		; div by zero */
0x0000f502, 0x01320000, /* 01320000 //C 0f502  1697 mvzl	r3,0 */
0x0000f503, 0x01f2f515, /* 01f2f515 //C 0f503  1698 jmp	div_ret */
0x0000f504, 0x01220000, /* 01220000 //C 0f504  1700 mvzl	r2,0		; Q= 0 */
0x0000f505, 0x01320000, /* 01320000 //C 0f505  1701 mvzl	r3,0		; R= 0 */
0x0000f506, 0x01418000, /* 01418000 //C 0f506  1702 mvh	r4,0x80000000	; m= 1<<31 */
0x0000f507, 0x01400000, /* 01400000 //C 0f507  1703 mvl	r4,0x80000000 */
0x0000f508, 0x024b0000, /* 024b0000 //C 0f508  1705 sz	r4 */
0x0000f509, 0x11f2f515, /* 11f2f515 //C 0f509  1706 Z jmp	div_ret */
0x0000f50a, 0x02380000, /* 02380000 //C 0f50a  1707 shl	r3		; r<<= 1 */
0x0000f50b, 0x000c0400, /* 000c0400 //C 0f50b  1708 test	r0,r4		; if (n&m) */
0x0000f50c, 0x213d0001, /* 213d0001 //C 0f50c  1709 NZ or	r3,1		; r|= 1 */
0x0000f50d, 0x00380100, /* 00380100 //C 0f50d  1710 cmp	r3,r1		; if (r>=d) */
0x0000f50e, 0x41f2f513, /* 41f2f513 //C 0f50e  1711 LO jmp	div_cyc_next */
0x0000f50f, 0x00360100, /* 00360100 //C 0f50f  1712 sub	r3,r1		;r-= d */
0x0000f510, 0x002d0400, /* 002d0400 //C 0f510  1713 or	r2,r4		;q|= m */
0x0000f511, 0x01f2f513, /* 01f2f513 //C 0f511  1714 jmp	div_cyc_next */
0x0000f512, 0x01f2f508, /* 01f2f508 //C 0f512  1715 jmp	div_cyc */
0x0000f513, 0x02490000, /* 02490000 //C 0f513  1717 shr	r4		; m>>= 1 */
0x0000f514, 0x01f2f508, /* 01f2f508 //C 0f514  1718 jmp	div_cyc */
0x0000f515, 0x0f4d0000, /* 0f4d0000 //C 0f515  1720 pop	r4 */
0x0000f516, 0x0ffd0000, /* 0ffd0000 //C 0f516  1721 pop	pc */
0x0000f517, 0x0ded0000, /* 0ded0000 //C 0f517  1729 push	lr */
0x0000f518, 0x0d0d0000, /* 0d0d0000 //C 0f518  1730 push	r0 */
0x0000f519, 0x0d1d0000, /* 0d1d0000 //C 0f519  1731 push	r1 */
0x0000f51a, 0x0d2d0000, /* 0d2d0000 //C 0f51a  1732 push	r2 */
0x0000f51b, 0x0d3d0000, /* 0d3d0000 //C 0f51b  1733 push	r3 */
0x0000f51c, 0x0dad0000, /* 0dad0000 //C 0f51c  1734 push	r10 */
0x0000f51d, 0x0dbd0000, /* 0dbd0000 //C 0f51d  1735 push	r11 */
0x0000f51e, 0x0dcd0000, /* 0dcd0000 //C 0f51e  1736 push	r12 */
0x0000f51f, 0x01c2f53f, /* 01c2f53f //C 0f51f  1738 mvzl	r12,itoa_buffer	; pointer to output buffer */
0x0000f520, 0x01b2f54a, /* 01b2f54a //C 0f520  1739 mvzl	r11,itoa_divs	; pointer to dividers */
0x0000f521, 0x01a20000, /* 01a20000 //C 0f521  1740 mvzl	r10,0		; bool: first non-zero char found */
0x0000f522, 0x0e1b0000, /* 0e1b0000 //C 0f522  1742 ld	r1,r11		; get next divider */
0x0000f523, 0x021b0000, /* 021b0000 //C 0f523  1743 sz	r1		; if 0, then */
0x0000f524, 0x11f2f537, /* 11f2f537 //C 0f524  1744 jz	itoa_ret	; finish */
0x0000f525, 0x01180001, /* 01180001 //C 0f525  1745 cmp	r1,1		; last divider? */
0x0000f526, 0x11a20001, /* 11a20001 //C 0f526  1746 EQ mvzl	r10,1		; always print last char */
0x0000f527, 0x0400f4fd, /* 0400f4fd //C 0f527  1747 call	div		; R2,R3= R0/R1 */
0x0000f528, 0x022b0000, /* 022b0000 //C 0f528  1748 sz	r2		; is the result zero? */
0x0000f529, 0x11f2f534, /* 11f2f534 //C 0f529  1749 jz	itoa_f0 */
0x0000f52a, 0x01a20001, /* 01a20001 //C 0f52a  1751 mvzl	r10,1		; non-zero: start to print */
0x0000f52b, 0x00000200, /* 00000200 //C 0f52b  1753 mov	r0,r2		; convert result to ASCII char */
0x0000f52c, 0x0400f44f, /* 0400f44f //C 0f52c  1754 call	value2hexchar */
0x0000f52d, 0x0c0c0000, /* 0c0c0000 //C 0f52d  1755 st	r0,r12		; and store it in buffer */
0x0000f52e, 0x01c40001, /* 01c40001 //C 0f52e  1756 inc	r12		; inc buf ptr */
0x0000f52f, 0x01020000, /* 01020000 //C 0f52f  1757 mvzl	r0,0		; put 0 after last char */
0x0000f530, 0x0c0c0000, /* 0c0c0000 //C 0f530  1758 st	r0,r12 */
0x0000f531, 0x00000300, /* 00000300 //C 0f531  1760 mov	r0,r3		; continue with the reminder */
0x0000f532, 0x01b40001, /* 01b40001 //C 0f532  1761 inc	r11		; and next divider */
0x0000f533, 0x01f2f522, /* 01f2f522 //C 0f533  1762 jmp	itoa_cyc */
0x0000f534, 0x02ab0000, /* 02ab0000 //C 0f534  1764 sz	r10		; just zeros so far? */
0x0000f535, 0x21f2f52b, /* 21f2f52b //C 0f535  1765 jnz	itoa_store	; no, print */
0x0000f536, 0x01f2f531, /* 01f2f531 //C 0f536  1766 jmp	itoa_next */
0x0000f537, 0x0fcd0000, /* 0fcd0000 //C 0f537  1768 pop	r12 */
0x0000f538, 0x0fbd0000, /* 0fbd0000 //C 0f538  1769 pop	r11 */
0x0000f539, 0x0fad0000, /* 0fad0000 //C 0f539  1770 pop	r10 */
0x0000f53a, 0x0f3d0000, /* 0f3d0000 //C 0f53a  1771 pop	r3 */
0x0000f53b, 0x0f2d0000, /* 0f2d0000 //C 0f53b  1772 pop	r2 */
0x0000f53c, 0x0f1d0000, /* 0f1d0000 //C 0f53c  1773 pop	r1 */
0x0000f53d, 0x0f0d0000, /* 0f0d0000 //C 0f53d  1774 pop	r0 */
0x0000f53e, 0x0ffd0000, /* 0ffd0000 //C 0f53e  1775 pop	pc */
0x0000f53f, 0x00000000, /* 00000000 //C 0f53f  1777 itoa_buffer:	ds	11 */
0x0000f54a, 0x3b9aca00, /* 3b9aca00 //C 0f54a  1779 dd	1000000000 */
0x0000f54b, 0x05f5e100, /* 05f5e100 //C 0f54b  1780 dd	100000000 */
0x0000f54c, 0x00989680, /* 00989680 //C 0f54c  1781 dd	10000000 */
0x0000f54d, 0x000f4240, /* 000f4240 //C 0f54d  1782 dd	1000000 */
0x0000f54e, 0x000186a0, /* 000186a0 //C 0f54e  1783 dd	100000 */
0x0000f54f, 0x00002710, /* 00002710 //C 0f54f  1784 dd	10000 */
0x0000f550, 0x000003e8, /* 000003e8 //C 0f550  1785 dd	1000 */
0x0000f551, 0x00000064, /* 00000064 //C 0f551  1786 dd	100 */
0x0000f552, 0x0000000a, /* 0000000a //C 0f552  1787 dd	10 */
0x0000f553, 0x00000001, /* 00000001 //C 0f553  1788 dd	1 */
0x0000f554, 0x00000000, /* 00000000 //C 0f554  1789 dd	0 */
0x0000f555, 0x0ded0000, /* 0ded0000 //C 0f555  1796 push	lr */
0x0000f556, 0x0400f517, /* 0400f517 //C 0f556  1797 call	itoa */
0x0000f557, 0x0102f53f, /* 0102f53f //C 0f557  1798 mvzl	r0,itoa_buffer */
0x0000f558, 0x0400f497, /* 0400f497 //C 0f558  1799 call	prints */
0x0000f559, 0x0ffd0000, /* 0ffd0000 //C 0f559  1800 pop	pc */
0x0000f55a, 0x0ded0000, /* 0ded0000 //C 0f55a  1809 push	lr */
0x0000f55b, 0x0d0d0000, /* 0d0d0000 //C 0f55b  1810 push	r0 */
0x0000f55c, 0x0d1d0000, /* 0d1d0000 //C 0f55c  1811 push	r1 */
0x0000f55d, 0x0d3d0000, /* 0d3d0000 //C 0f55d  1812 push	r3 */
0x0000f55e, 0x0610f650, /* 0610f650 //C 0f55e  1814 st	r1,reg1 */
0x0000f55f, 0x0620f651, /* 0620f651 //C 0f55f  1815 st	r2,reg2 */
0x0000f560, 0x0630f652, /* 0630f652 //C 0f560  1816 st	r3,reg3 */
0x0000f561, 0x0640f653, /* 0640f653 //C 0f561  1817 st	r4,reg4 */
0x0000f562, 0x0650f654, /* 0650f654 //C 0f562  1818 st	r5,reg5 */
0x0000f563, 0x0660f655, /* 0660f655 //C 0f563  1819 st	r6,reg6 */
0x0000f564, 0x0670f656, /* 0670f656 //C 0f564  1820 st	r7,reg7 */
0x0000f565, 0x0680f657, /* 0680f657 //C 0f565  1821 st	r8,reg8 */
0x0000f566, 0x0690f658, /* 0690f658 //C 0f566  1822 st	r9,reg9 */
0x0000f567, 0x06a0f659, /* 06a0f659 //C 0f567  1823 st	r10,reg10 */
0x0000f568, 0x06b0f65a, /* 06b0f65a //C 0f568  1824 st	r11,reg11 */
0x0000f569, 0x06c0f65b, /* 06c0f65b //C 0f569  1825 st	r12,reg12 */
0x0000f56a, 0x00200000, /* 00200000 //C 0f56a  1827 mov	r2,r0		; pointer to format string */
0x0000f56b, 0x0112f650, /* 0112f650 //C 0f56b  1828 mvzl	r1,reg1		; pointer to params */
0x0000f56c, 0x01320000, /* 01320000 //C 0f56c  1829 mvzl	r3,0		; byte idx in packed str */
0x0000f56d, 0x0e020000, /* 0e020000 //C 0f56d  1831 ld	r0,r2		; get next char */
0x0000f56e, 0x020b0000, /* 020b0000 //C 0f56e  1832 sz	r0		; is it EOS? */
0x0000f56f, 0x11f2f5d4, /* 11f2f5d4 //C 0f56f  1833 jz	printf_ret */
0x0000f570, 0x06014003, /* 06014003 //C 0f570  1834 getbz	r0,r0,r3	; pick next byte */
0x0000f571, 0x020b0000, /* 020b0000 //C 0f571  1835 sz	r0		; is it null? */
0x0000f572, 0x11f2f5d1, /* 11f2f5d1 //C 0f572  1836 jz	printf_nextword	; no more non-nulls */
0x0000f573, 0x0108005c, /* 0108005c //C 0f573  1838 cmp	r0,'\\' */
0x0000f574, 0x21f2f59f, /* 21f2f59f //C 0f574  1839 jnz	printf_notescape */
0x0000f575, 0x01340001, /* 01340001 //C 0f575  1841 inc	r3 */
0x0000f576, 0x01380004, /* 01380004 //C 0f576  1842 cmp	r3,4 */
0x0000f577, 0x21f2f57d, /* 21f2f57d //C 0f577  1843 jnz	printf_l1 */
0x0000f578, 0x01320000, /* 01320000 //C 0f578  1845 mvzl	r3,0 */
0x0000f579, 0x01240001, /* 01240001 //C 0f579  1846 inc	r2 */
0x0000f57a, 0x0e020000, /* 0e020000 //C 0f57a  1847 ld	r0,r2 */
0x0000f57b, 0x020b0000, /* 020b0000 //C 0f57b  1848 sz	r0 */
0x0000f57c, 0x11f2f5d4, /* 11f2f5d4 //C 0f57c  1849 jz	printf_ret */
0x0000f57d, 0x0e020000, /* 0e020000 //C 0f57d  1851 ld	r0,r2 */
0x0000f57e, 0x06014003, /* 06014003 //C 0f57e  1852 getbz	r0,r0,r3 */
0x0000f57f, 0x020b0000, /* 020b0000 //C 0f57f  1853 sz	r0 */
0x0000f580, 0x11f2f578, /* 11f2f578 //C 0f580  1854 jz	printf_l2 */
0x0000f581, 0x01080061, /* 01080061 //C 0f581  1856 cmp	r0,'a' */
0x0000f582, 0x11020007, /* 11020007 //C 0f582  1857 Z mvzl	r0,7 */
0x0000f583, 0x11f2f5cd, /* 11f2f5cd //C 0f583  1858 Z jmp	printf_print */
0x0000f584, 0x01080062, /* 01080062 //C 0f584  1859 cmp	r0,'b' */
0x0000f585, 0x11020008, /* 11020008 //C 0f585  1860 Z mvzl	r0,8 */
0x0000f586, 0x11f2f5cd, /* 11f2f5cd //C 0f586  1861 Z jmp	printf_print */
0x0000f587, 0x01080065, /* 01080065 //C 0f587  1862 cmp	r0,'e' */
0x0000f588, 0x1102001b, /* 1102001b //C 0f588  1863 Z mvzl	r0,0x1b */
0x0000f589, 0x11f2f5cd, /* 11f2f5cd //C 0f589  1864 Z jmp	printf_print */
0x0000f58a, 0x01080066, /* 01080066 //C 0f58a  1865 cmp	r0,'f' */
0x0000f58b, 0x1102000c, /* 1102000c //C 0f58b  1866 Z mvzl	r0,0xc */
0x0000f58c, 0x11f2f5cd, /* 11f2f5cd //C 0f58c  1867 Z jmp	printf_print */
0x0000f58d, 0x0108006e, /* 0108006e //C 0f58d  1868 cmp	r0,'n' */
0x0000f58e, 0x1102000a, /* 1102000a //C 0f58e  1869 Z mvzl	r0,0xa */
0x0000f58f, 0x11f2f5cd, /* 11f2f5cd //C 0f58f  1870 Z jmp	printf_print */
0x0000f590, 0x01080072, /* 01080072 //C 0f590  1871 cmp	r0,'r' */
0x0000f591, 0x1102000d, /* 1102000d //C 0f591  1872 Z mvzl	r0,0xd */
0x0000f592, 0x11f2f5cd, /* 11f2f5cd //C 0f592  1873 Z jmp	printf_print */
0x0000f593, 0x01080074, /* 01080074 //C 0f593  1874 cmp	r0,'t' */
0x0000f594, 0x11020009, /* 11020009 //C 0f594  1875 Z mvzl	r0,9 */
0x0000f595, 0x11f2f5cd, /* 11f2f5cd //C 0f595  1876 Z jmp	printf_print */
0x0000f596, 0x01080076, /* 01080076 //C 0f596  1877 cmp	r0,'v' */
0x0000f597, 0x1102000b, /* 1102000b //C 0f597  1878 Z mvzl	r0,0xb */
0x0000f598, 0x11f2f5cd, /* 11f2f5cd //C 0f598  1879 Z jmp	printf_print */
0x0000f599, 0x0108005c, /* 0108005c //C 0f599  1880 cmp	r0,0x5c */
0x0000f59a, 0x11f2f5cd, /* 11f2f5cd //C 0f59a  1881 Z jmp	printf_print */
0x0000f59b, 0x01080030, /* 01080030 //C 0f59b  1882 cmp	r0,'0' */
0x0000f59c, 0x11020000, /* 11020000 //C 0f59c  1883 Z mvzl	r0,0 */
0x0000f59d, 0x11f2f5cd, /* 11f2f5cd //C 0f59d  1884 Z jmp	printf_print */
0x0000f59e, 0x01f2f5cd, /* 01f2f5cd //C 0f59e  1886 jmp	printf_print */
0x0000f59f, 0x01080025, /* 01080025 //C 0f59f  1889 cmp	r0,'%'		; is it a format char? */
0x0000f5a0, 0x21f2f5cd, /* 21f2f5cd //C 0f5a0  1890 jnz	printf_print */
0x0000f5a1, 0x01340001, /* 01340001 //C 0f5a1  1892 inc	r3 */
0x0000f5a2, 0x01380004, /* 01380004 //C 0f5a2  1893 cmp	r3,4 */
0x0000f5a3, 0x21f2f5a9, /* 21f2f5a9 //C 0f5a3  1894 jnz	printf_l3 */
0x0000f5a4, 0x01320000, /* 01320000 //C 0f5a4  1896 mvzl	r3,0 */
0x0000f5a5, 0x01240001, /* 01240001 //C 0f5a5  1897 inc	r2		; go to format char */
0x0000f5a6, 0x0e020000, /* 0e020000 //C 0f5a6  1898 ld	r0,r2 */
0x0000f5a7, 0x022b0000, /* 022b0000 //C 0f5a7  1899 sz	r2		; is it EOS? */
0x0000f5a8, 0x11f2f5d4, /* 11f2f5d4 //C 0f5a8  1900 jz	printf_ret */
0x0000f5a9, 0x0e020000, /* 0e020000 //C 0f5a9  1902 ld	r0,r2 */
0x0000f5aa, 0x06014003, /* 06014003 //C 0f5aa  1903 getbz	r0,r0,r3 */
0x0000f5ab, 0x020b0000, /* 020b0000 //C 0f5ab  1904 sz	r0 */
0x0000f5ac, 0x11f2f5a4, /* 11f2f5a4 //C 0f5ac  1905 jz	printf_l4 */
0x0000f5ad, 0x01080025, /* 01080025 //C 0f5ad  1907 cmp	r0,'%'		; % is used to print % */
0x0000f5ae, 0x11f2f5cd, /* 11f2f5cd //C 0f5ae  1908 jz	printf_print */
0x0000f5af, 0x01080075, /* 01080075 //C 0f5af  1910 cmp	r0,'u'		; u,d print in decimal */
0x0000f5b0, 0x11f2f5b3, /* 11f2f5b3 //C 0f5b0  1911 jz	printf_d */
0x0000f5b1, 0x01080064, /* 01080064 //C 0f5b1  1912 cmp	r0,'d' */
0x0000f5b2, 0x21f2f5b7, /* 21f2f5b7 //C 0f5b2  1913 jnz	printf_notd */
0x0000f5b3, 0x0e010000, /* 0e010000 //C 0f5b3  1915 ld	r0,r1 */
0x0000f5b4, 0x01140001, /* 01140001 //C 0f5b4  1916 inc	r1 */
0x0000f5b5, 0x0400f555, /* 0400f555 //C 0f5b5  1917 call	printd */
0x0000f5b6, 0x01f2f5ce, /* 01f2f5ce //C 0f5b6  1918 jmp	printf_next */
0x0000f5b7, 0x01080078, /* 01080078 //C 0f5b7  1921 cmp	r0,'x' */
0x0000f5b8, 0x21f2f5c0, /* 21f2f5c0 //C 0f5b8  1922 jnz	printf_notx */
0x0000f5b9, 0x0e010000, /* 0e010000 //C 0f5b9  1924 ld	r0,r1 */
0x0000f5ba, 0x01140001, /* 01140001 //C 0f5ba  1925 inc	r1 */
0x0000f5bb, 0x0d1d0000, /* 0d1d0000 //C 0f5bb  1926 push	r1 */
0x0000f5bc, 0x01120000, /* 01120000 //C 0f5bc  1927 mvzl	r1,0 */
0x0000f5bd, 0x0400f4d7, /* 0400f4d7 //C 0f5bd  1928 call	print_vhex */
0x0000f5be, 0x0f1d0000, /* 0f1d0000 //C 0f5be  1929 pop	r1 */
0x0000f5bf, 0x01f2f5ce, /* 01f2f5ce //C 0f5bf  1930 jmp	printf_next */
0x0000f5c0, 0x01080073, /* 01080073 //C 0f5c0  1933 cmp	r0,'s' */
0x0000f5c1, 0x21f2f5c6, /* 21f2f5c6 //C 0f5c1  1934 jnz	printf_nots */
0x0000f5c2, 0x0e010000, /* 0e010000 //C 0f5c2  1936 ld	r0,r1 */
0x0000f5c3, 0x01140001, /* 01140001 //C 0f5c3  1937 inc	r1 */
0x0000f5c4, 0x0400f497, /* 0400f497 //C 0f5c4  1938 call	prints */
0x0000f5c5, 0x01f2f5ce, /* 01f2f5ce //C 0f5c5  1939 jmp	printf_next */
0x0000f5c6, 0x01080063, /* 01080063 //C 0f5c6  1942 cmp	r0,'c' */
0x0000f5c7, 0x21f2f5cc, /* 21f2f5cc //C 0f5c7  1943 jnz	printf_notc */
0x0000f5c8, 0x0e010000, /* 0e010000 //C 0f5c8  1944 ld	r0,r1 */
0x0000f5c9, 0x01140001, /* 01140001 //C 0f5c9  1945 inc	r1 */
0x0000f5ca, 0x0400f490, /* 0400f490 //C 0f5ca  1946 call	putchar */
0x0000f5cb, 0x01f2f5ce, /* 01f2f5ce //C 0f5cb  1947 jmp	printf_next */
0x0000f5cc, 0x01f2f5ce, /* 01f2f5ce //C 0f5cc  1950 jmp	printf_next */
0x0000f5cd, 0x0400f490, /* 0400f490 //C 0f5cd  1952 call	putchar		; print actual char */
0x0000f5ce, 0x01340001, /* 01340001 //C 0f5ce  1954 inc	r3		; next byte in word */
0x0000f5cf, 0x01380004, /* 01380004 //C 0f5cf  1955 cmp	r3,4		; all 4 processed? */
0x0000f5d0, 0x21f2f56d, /* 21f2f56d //C 0f5d0  1956 jnz	printf_cyc */
0x0000f5d1, 0x01240001, /* 01240001 //C 0f5d1  1958 inc	r2		; inc string ptr */
0x0000f5d2, 0x01320000, /* 01320000 //C 0f5d2  1959 mvzl	r3,0		; restart byte idx */
0x0000f5d3, 0x01f2f56d, /* 01f2f56d //C 0f5d3  1960 jmp	printf_cyc */
0x0000f5d4, 0x0f3d0000, /* 0f3d0000 //C 0f5d4  1963 pop	r3 */
0x0000f5d5, 0x0f1d0000, /* 0f1d0000 //C 0f5d5  1964 pop	r1 */
0x0000f5d6, 0x0f0d0000, /* 0f0d0000 //C 0f5d6  1965 pop	r0 */
0x0000f5d7, 0x0ffd0000, /* 0ffd0000 //C 0f5d7  1966 pop	pc */
0x0000f5d8, 0x0d0d0000, /* 0d0d0000 //C 0f5d8  1971 push	r0 */
0x0000f5d9, 0x0d2d0000, /* 0d2d0000 //C 0f5d9  1972 push	r2 */
0x0000f5da, 0x00000e00, /* 00000e00 //C 0f5da  1973 mov	r0,LR */
0x0000f5db, 0x0400f55a, /* 0400f55a //C 0f5db  1974 call	printf */
0x0000f5dc, 0x01240001, /* 01240001 //C 0f5dc  1975 inc	r2 */
0x0000f5dd, 0x0620f651, /* 0620f651 //C 0f5dd  1976 st	r2,reg2 */
0x0000f5de, 0x0f2d0000, /* 0f2d0000 //C 0f5de  1977 pop	r2 */
0x0000f5df, 0x0f0d0000, /* 0f0d0000 //C 0f5df  1978 pop	r0 */
0x0000f5e0, 0x07f0f651, /* 07f0f651 //C 0f5e0  1979 ld	PC,reg2 */
0x0000f5e1, 0x00000000, /* 00000000 //C 0f5e1  1984 line:		ds	100		; line buffer */
0x0000f645, 0x00000000, /* 00000000 //C 0f645  1985 line_ptr:	ds	1		; line pointer (index) */
0x0000f646, 0x00000000, /* 00000000 //C 0f646  1986 at_eol:		ds	1		; bool, true if EOL arrived */
0x0000f647, 0x00000000, /* 00000000 //C 0f647  1987 words:		ds	5		; Tokens of line */
0x0000f64c, 0x00000000, /* 00000000 //C 0f64c  1988 echo:		ds	1		; bool, do echo or not */
0x0000f64d, 0x00000000, /* 00000000 //C 0f64d  1989 dd	0 */
0x0000f64e, 0x00000000, /* 00000000 //C 0f64e  1990 dd	0 */
0x0000f64f, 0x00000000, /* 00000000 //C 0f64f  1992 dd	0 */
0x0000f650, 0x00000000, /* 00000000 //C 0f650  1993 dd	0 */
0x0000f651, 0x00000000, /* 00000000 //C 0f651  1994 dd	0 */
0x0000f652, 0x00000000, /* 00000000 //C 0f652  1995 dd	0 */
0x0000f653, 0x00000000, /* 00000000 //C 0f653  1996 dd	0 */
0x0000f654, 0x00000000, /* 00000000 //C 0f654  1997 dd	0 */
0x0000f655, 0x00000000, /* 00000000 //C 0f655  1998 dd	0 */
0x0000f656, 0x00000000, /* 00000000 //C 0f656  1999 dd	0 */
0x0000f657, 0x00000000, /* 00000000 //C 0f657  2000 dd	0 */
0x0000f658, 0x00000000, /* 00000000 //C 0f658  2001 dd	0 */
0x0000f659, 0x00000000, /* 00000000 //C 0f659  2002 dd	0 */
0x0000f65a, 0x00000000, /* 00000000 //C 0f65a  2003 dd	0 */
0x0000f65b, 0x00000000, /* 00000000 //C 0f65b  2004 dd	0 */
0x0000f65c, 0x00000000, /* 00000000 //C 0f65c  2005 dd	0 */
0x0000f65d, 0x00000000, /* 00000000 //C 0f65d  2006 dd	0 */
0x0000f65e, 0x00000000, /* 00000000 //C 0f65e  2007 dd	0 */
0x0000f65f, 0x00000000, /* 00000000 //C 0f65f  2008 dd	0 */
0x0000f660, 0x00000050, /* 00000050 //C 0f660  2010 db	80 */
0x0000f661, 0x0000004d, /* 0000004d //C 0f661  2010 db	77 */
0x0000f662, 0x0000006f, /* 0000006f //C 0f662  2010 db	111 */
0x0000f663, 0x0000006e, /* 0000006e //C 0f663  2010 db	110 */
0x0000f664, 0x00000069, /* 00000069 //C 0f664  2010 db	105 */
0x0000f665, 0x00000074, /* 00000074 //C 0f665  2010 db	116 */
0x0000f666, 0x0000006f, /* 0000006f //C 0f666  2010 db	111 */
0x0000f667, 0x00000072, /* 00000072 //C 0f667  2010 db	114 */
0x0000f668, 0x00000020, /* 00000020 //C 0f668  2010 db	32 */
0x0000f669, 0x00000076, /* 00000076 //C 0f669  2010 db	118 */
0x0000f66a, 0x00000031, /* 00000031 //C 0f66a  2010 db	49 */
0x0000f66b, 0x0000002e, /* 0000002e //C 0f66b  2010 db	46 */
0x0000f66c, 0x00000030, /* 00000030 //C 0f66c  2010 db	48 */
0x0000f66d, 0x00000000, /* 00000000 //C 0f66d  2010 db */
0x0000f66e, 0x00000053, /* 00000053 //C 0f66e  2011 db	83 */
0x0000f66f, 0x00000074, /* 00000074 //C 0f66f  2011 db	116 */
0x0000f670, 0x0000006f, /* 0000006f //C 0f670  2011 db	111 */
0x0000f671, 0x00000070, /* 00000070 //C 0f671  2011 db	112 */
0x0000f672, 0x00000020, /* 00000020 //C 0f672  2011 db	32 */
0x0000f673, 0x00000061, /* 00000061 //C 0f673  2011 db	97 */
0x0000f674, 0x00000074, /* 00000074 //C 0f674  2011 db	116 */
0x0000f675, 0x0000003a, /* 0000003a //C 0f675  2011 db	58 */
0x0000f676, 0x00000020, /* 00000020 //C 0f676  2011 db	32 */
0x0000f677, 0x00000000, /* 00000000 //C 0f677  2011 db */
0x0000f678, 0x00000008, /* 00000008 //C 0f678  2012 db	8 */
0x0000f679, 0x00000020, /* 00000020 //C 0f679  2012 db	32 */
0x0000f67a, 0x00000008, /* 00000008 //C 0f67a  2012 db	8 */
0x0000f67b, 0x00000000, /* 00000000 //C 0f67b  2012 db	0 */
0x0000f67c, 0x0000003a, /* 0000003a //C 0f67c  2013 db	58 */
0x0000f67d, 0x00000000, /* 00000000 //C 0f67d  2013 db */
0x0000f67e, 0x00000020, /* 00000020 //C 0f67e  2014 db	32 */
0x0000f67f, 0x0000003b, /* 0000003b //C 0f67f  2014 db	59 */
0x0000f680, 0x00000009, /* 00000009 //C 0f680  2014 db	9 */
0x0000f681, 0x0000000b, /* 0000000b //C 0f681  2014 db	11 */
0x0000f682, 0x0000002c, /* 0000002c //C 0f682  2014 db	44 */
0x0000f683, 0x0000003d, /* 0000003d //C 0f683  2014 db	61 */
0x0000f684, 0x0000005b, /* 0000005b //C 0f684  2014 db	91 */
0x0000f685, 0x0000005d, /* 0000005d //C 0f685  2014 db	93 */
0x0000f686, 0x00000000, /* 00000000 //C 0f686  2014 db */
0x0000f687, 0x00000028, /* 00000028 //C 0f687  2015 db	40 */
0x0000f688, 0x0000006e, /* 0000006e //C 0f688  2015 db	110 */
0x0000f689, 0x00000075, /* 00000075 //C 0f689  2015 db	117 */
0x0000f68a, 0x0000006c, /* 0000006c //C 0f68a  2015 db	108 */
0x0000f68b, 0x0000006c, /* 0000006c //C 0f68b  2015 db	108 */
0x0000f68c, 0x00000029, /* 00000029 //C 0f68c  2015 db	41 */
0x0000f68d, 0x00000000, /* 00000000 //C 0f68d  2015 db */
0x0000f68e, 0x00000000, /* 00000000 //C 0f68e  2016 db	0 */
0x0000f68f, 0x00000000, /* 00000000 //C 0f68f  2017 db	0 */
0x0000f690, 0x00000000, /* 00000000 //C 0f690  2018 sc_buffer:	ds	10 */
0x0000f69a, 0x0000f190, /* 0000f190 //C 0f69a  2022 dd	cmd_sm */
0x0000f69b, 0x00000073, /* 00000073 //C 0f69b  2023 db	115 */
0x0000f69c, 0x0000006d, /* 0000006d //C 0f69c  2023 db	109 */
0x0000f69d, 0x00000000, /* 00000000 //C 0f69d  2023 db */
0x0000f69e, 0x0000f137, /* 0000f137 //C 0f69e  2024 dd	cmd_m */
0x0000f69f, 0x0000006d, /* 0000006d //C 0f69f  2025 db	109 */
0x0000f6a0, 0x00000000, /* 00000000 //C 0f6a0  2025 db */
0x0000f6a1, 0x0000f137, /* 0000f137 //C 0f6a1  2026 dd	cmd_m */
0x0000f6a2, 0x0000006d, /* 0000006d //C 0f6a2  2027 db	109 */
0x0000f6a3, 0x00000065, /* 00000065 //C 0f6a3  2027 db	101 */
0x0000f6a4, 0x0000006d, /* 0000006d //C 0f6a4  2027 db	109 */
0x0000f6a5, 0x00000000, /* 00000000 //C 0f6a5  2027 db */
0x0000f6a6, 0x0000f1b3, /* 0000f1b3 //C 0f6a6  2028 dd	cmd_d */
0x0000f6a7, 0x00000064, /* 00000064 //C 0f6a7  2029 db	100 */
0x0000f6a8, 0x00000000, /* 00000000 //C 0f6a8  2029 db */
0x0000f6a9, 0x0000f1b3, /* 0000f1b3 //C 0f6a9  2030 dd	cmd_d */
0x0000f6aa, 0x00000064, /* 00000064 //C 0f6aa  2031 db	100 */
0x0000f6ab, 0x00000075, /* 00000075 //C 0f6ab  2031 db	117 */
0x0000f6ac, 0x0000006d, /* 0000006d //C 0f6ac  2031 db	109 */
0x0000f6ad, 0x00000070, /* 00000070 //C 0f6ad  2031 db	112 */
0x0000f6ae, 0x00000000, /* 00000000 //C 0f6ae  2031 db */
0x0000f6af, 0x0000f1e6, /* 0000f1e6 //C 0f6af  2032 dd	cmd_l */
0x0000f6b0, 0x0000006c, /* 0000006c //C 0f6b0  2033 db	108 */
0x0000f6b1, 0x00000000, /* 00000000 //C 0f6b1  2033 db */
0x0000f6b2, 0x0000f1e6, /* 0000f1e6 //C 0f6b2  2034 dd	cmd_l */
0x0000f6b3, 0x0000006c, /* 0000006c //C 0f6b3  2035 db	108 */
0x0000f6b4, 0x0000006f, /* 0000006f //C 0f6b4  2035 db	111 */
0x0000f6b5, 0x00000061, /* 00000061 //C 0f6b5  2035 db	97 */
0x0000f6b6, 0x00000064, /* 00000064 //C 0f6b6  2035 db	100 */
0x0000f6b7, 0x00000000, /* 00000000 //C 0f6b7  2035 db */
0x0000f6b8, 0x0000f25c, /* 0000f25c //C 0f6b8  2036 dd	cmd_g */
0x0000f6b9, 0x00000067, /* 00000067 //C 0f6b9  2037 db	103 */
0x0000f6ba, 0x00000000, /* 00000000 //C 0f6ba  2037 db */
0x0000f6bb, 0x0000f25c, /* 0000f25c //C 0f6bb  2038 dd	cmd_g */
0x0000f6bc, 0x00000067, /* 00000067 //C 0f6bc  2039 db	103 */
0x0000f6bd, 0x0000006f, /* 0000006f //C 0f6bd  2039 db	111 */
0x0000f6be, 0x00000000, /* 00000000 //C 0f6be  2039 db */
0x0000f6bf, 0x0000f25c, /* 0000f25c //C 0f6bf  2040 dd	cmd_g */
0x0000f6c0, 0x00000072, /* 00000072 //C 0f6c0  2041 db	114 */
0x0000f6c1, 0x00000075, /* 00000075 //C 0f6c1  2041 db	117 */
0x0000f6c2, 0x0000006e, /* 0000006e //C 0f6c2  2041 db	110 */
0x0000f6c3, 0x00000000, /* 00000000 //C 0f6c3  2041 db */
0x0000f6c4, 0x0000f29b, /* 0000f29b //C 0f6c4  2042 dd	cmd_h */
0x0000f6c5, 0x0000003f, /* 0000003f //C 0f6c5  2043 db	63 */
0x0000f6c6, 0x00000000, /* 00000000 //C 0f6c6  2043 db */
0x0000f6c7, 0x0000f29b, /* 0000f29b //C 0f6c7  2044 dd	cmd_h */
0x0000f6c8, 0x00000068, /* 00000068 //C 0f6c8  2045 db	104 */
0x0000f6c9, 0x00000000, /* 00000000 //C 0f6c9  2045 db */
0x0000f6ca, 0x0000f29b, /* 0000f29b //C 0f6ca  2046 dd	cmd_h */
0x0000f6cb, 0x00000068, /* 00000068 //C 0f6cb  2047 db	104 */
0x0000f6cc, 0x00000065, /* 00000065 //C 0f6cc  2047 db	101 */
0x0000f6cd, 0x0000006c, /* 0000006c //C 0f6cd  2047 db	108 */
0x0000f6ce, 0x00000070, /* 00000070 //C 0f6ce  2047 db	112 */
0x0000f6cf, 0x00000000, /* 00000000 //C 0f6cf  2047 db */
0x0000f6d0, 0x0000f302, /* 0000f302 //C 0f6d0  2048 dd	cmd_r */
0x0000f6d1, 0x00000072, /* 00000072 //C 0f6d1  2049 db	114 */
0x0000f6d2, 0x00000000, /* 00000000 //C 0f6d2  2049 db */
0x0000f6d3, 0x0000f302, /* 0000f302 //C 0f6d3  2050 dd	cmd_r */
0x0000f6d4, 0x00000072, /* 00000072 //C 0f6d4  2051 db	114 */
0x0000f6d5, 0x00000065, /* 00000065 //C 0f6d5  2051 db	101 */
0x0000f6d6, 0x00000067, /* 00000067 //C 0f6d6  2051 db	103 */
0x0000f6d7, 0x00000000, /* 00000000 //C 0f6d7  2051 db */
0x0000f6d8, 0x0000f302, /* 0000f302 //C 0f6d8  2052 dd	cmd_r */
0x0000f6d9, 0x00000072, /* 00000072 //C 0f6d9  2053 db	114 */
0x0000f6da, 0x00000065, /* 00000065 //C 0f6da  2053 db	101 */
0x0000f6db, 0x00000067, /* 00000067 //C 0f6db  2053 db	103 */
0x0000f6dc, 0x00000073, /* 00000073 //C 0f6dc  2053 db	115 */
0x0000f6dd, 0x00000000, /* 00000000 //C 0f6dd  2053 db */
0x0000f6de, 0x0000f392, /* 0000f392 //C 0f6de  2054 dd	cmd_sp */
0x0000f6df, 0x00000073, /* 00000073 //C 0f6df  2055 db	115 */
0x0000f6e0, 0x00000070, /* 00000070 //C 0f6e0  2055 db	112 */
0x0000f6e1, 0x00000000, /* 00000000 //C 0f6e1  2055 db */
0x0000f6e2, 0x0000f395, /* 0000f395 //C 0f6e2  2056 dd	cmd_lr */
0x0000f6e3, 0x0000006c, /* 0000006c //C 0f6e3  2057 db	108 */
0x0000f6e4, 0x00000072, /* 00000072 //C 0f6e4  2057 db	114 */
0x0000f6e5, 0x00000000, /* 00000000 //C 0f6e5  2057 db */
0x0000f6e6, 0x0000f398, /* 0000f398 //C 0f6e6  2058 dd	cmd_pc */
0x0000f6e7, 0x00000070, /* 00000070 //C 0f6e7  2059 db	112 */
0x0000f6e8, 0x00000063, /* 00000063 //C 0f6e8  2059 db	99 */
0x0000f6e9, 0x00000000, /* 00000000 //C 0f6e9  2059 db */
0x0000f6ea, 0x0000f39b, /* 0000f39b //C 0f6ea  2060 dd	cmd_f */
0x0000f6eb, 0x00000066, /* 00000066 //C 0f6eb  2061 db	102 */
0x0000f6ec, 0x00000000, /* 00000000 //C 0f6ec  2061 db */
0x0000f6ed, 0x00000000, /* 00000000 //C 0f6ed  2062 dd	0 */
0x0000f6ee, 0x00000000, /* 00000000 //C 0f6ee  2063 dd	0 */
0x0000f6ef, 0x0000006d, /* 0000006d //C 0f6ef  2065 db	109 */
0x0000f6f0, 0x0000005b, /* 0000005b //C 0f6f0  2065 db	91 */
0x0000f6f1, 0x00000065, /* 00000065 //C 0f6f1  2065 db	101 */
0x0000f6f2, 0x0000006d, /* 0000006d //C 0f6f2  2065 db	109 */
0x0000f6f3, 0x0000005d, /* 0000005d //C 0f6f3  2065 db	93 */
0x0000f6f4, 0x00000020, /* 00000020 //C 0f6f4  2065 db	32 */
0x0000f6f5, 0x00000061, /* 00000061 //C 0f6f5  2065 db	97 */
0x0000f6f6, 0x00000064, /* 00000064 //C 0f6f6  2065 db	100 */
0x0000f6f7, 0x00000064, /* 00000064 //C 0f6f7  2065 db	100 */
0x0000f6f8, 0x00000072, /* 00000072 //C 0f6f8  2065 db	114 */
0x0000f6f9, 0x00000020, /* 00000020 //C 0f6f9  2065 db	32 */
0x0000f6fa, 0x0000005b, /* 0000005b //C 0f6fa  2065 db	91 */
0x0000f6fb, 0x00000076, /* 00000076 //C 0f6fb  2065 db	118 */
0x0000f6fc, 0x00000061, /* 00000061 //C 0f6fc  2065 db	97 */
0x0000f6fd, 0x0000006c, /* 0000006c //C 0f6fd  2065 db	108 */
0x0000f6fe, 0x0000005d, /* 0000005d //C 0f6fe  2065 db	93 */
0x0000f6ff, 0x00000020, /* 00000020 //C 0f6ff  2065 db	32 */
0x0000f700, 0x00000020, /* 00000020 //C 0f700  2065 db	32 */
0x0000f701, 0x00000047, /* 00000047 //C 0f701  2065 db	71 */
0x0000f702, 0x00000065, /* 00000065 //C 0f702  2065 db	101 */
0x0000f703, 0x00000074, /* 00000074 //C 0f703  2065 db	116 */
0x0000f704, 0x0000002f, /* 0000002f //C 0f704  2065 db	47 */
0x0000f705, 0x00000073, /* 00000073 //C 0f705  2065 db	115 */
0x0000f706, 0x00000065, /* 00000065 //C 0f706  2065 db	101 */
0x0000f707, 0x00000074, /* 00000074 //C 0f707  2065 db	116 */
0x0000f708, 0x00000020, /* 00000020 //C 0f708  2065 db	32 */
0x0000f709, 0x0000006d, /* 0000006d //C 0f709  2065 db	109 */
0x0000f70a, 0x00000065, /* 00000065 //C 0f70a  2065 db	101 */
0x0000f70b, 0x0000006d, /* 0000006d //C 0f70b  2065 db	109 */
0x0000f70c, 0x0000006f, /* 0000006f //C 0f70c  2065 db	111 */
0x0000f70d, 0x00000072, /* 00000072 //C 0f70d  2065 db	114 */
0x0000f70e, 0x00000079, /* 00000079 //C 0f70e  2065 db	121 */
0x0000f70f, 0x0000000a, /* 0000000a //C 0f70f  2065 db	10 */
0x0000f710, 0x00000000, /* 00000000 //C 0f710  2065 db */
0x0000f711, 0x00000064, /* 00000064 //C 0f711  2066 db	100 */
0x0000f712, 0x0000005b, /* 0000005b //C 0f712  2066 db	91 */
0x0000f713, 0x00000075, /* 00000075 //C 0f713  2066 db	117 */
0x0000f714, 0x0000006d, /* 0000006d //C 0f714  2066 db	109 */
0x0000f715, 0x00000070, /* 00000070 //C 0f715  2066 db	112 */
0x0000f716, 0x0000005d, /* 0000005d //C 0f716  2066 db	93 */
0x0000f717, 0x00000020, /* 00000020 //C 0f717  2066 db	32 */
0x0000f718, 0x00000073, /* 00000073 //C 0f718  2066 db	115 */
0x0000f719, 0x00000074, /* 00000074 //C 0f719  2066 db	116 */
0x0000f71a, 0x00000061, /* 00000061 //C 0f71a  2066 db	97 */
0x0000f71b, 0x00000072, /* 00000072 //C 0f71b  2066 db	114 */
0x0000f71c, 0x00000074, /* 00000074 //C 0f71c  2066 db	116 */
0x0000f71d, 0x00000020, /* 00000020 //C 0f71d  2066 db	32 */
0x0000f71e, 0x00000065, /* 00000065 //C 0f71e  2066 db	101 */
0x0000f71f, 0x0000006e, /* 0000006e //C 0f71f  2066 db	110 */
0x0000f720, 0x00000064, /* 00000064 //C 0f720  2066 db	100 */
0x0000f721, 0x00000020, /* 00000020 //C 0f721  2066 db	32 */
0x0000f722, 0x00000020, /* 00000020 //C 0f722  2066 db	32 */
0x0000f723, 0x00000044, /* 00000044 //C 0f723  2066 db	68 */
0x0000f724, 0x00000075, /* 00000075 //C 0f724  2066 db	117 */
0x0000f725, 0x0000006d, /* 0000006d //C 0f725  2066 db	109 */
0x0000f726, 0x00000070, /* 00000070 //C 0f726  2066 db	112 */
0x0000f727, 0x00000020, /* 00000020 //C 0f727  2066 db	32 */
0x0000f728, 0x0000006d, /* 0000006d //C 0f728  2066 db	109 */
0x0000f729, 0x00000065, /* 00000065 //C 0f729  2066 db	101 */
0x0000f72a, 0x0000006d, /* 0000006d //C 0f72a  2066 db	109 */
0x0000f72b, 0x0000006f, /* 0000006f //C 0f72b  2066 db	111 */
0x0000f72c, 0x00000072, /* 00000072 //C 0f72c  2066 db	114 */
0x0000f72d, 0x00000079, /* 00000079 //C 0f72d  2066 db	121 */
0x0000f72e, 0x00000020, /* 00000020 //C 0f72e  2066 db	32 */
0x0000f72f, 0x00000063, /* 00000063 //C 0f72f  2066 db	99 */
0x0000f730, 0x0000006f, /* 0000006f //C 0f730  2066 db	111 */
0x0000f731, 0x0000006e, /* 0000006e //C 0f731  2066 db	110 */
0x0000f732, 0x00000074, /* 00000074 //C 0f732  2066 db	116 */
0x0000f733, 0x00000065, /* 00000065 //C 0f733  2066 db	101 */
0x0000f734, 0x0000006e, /* 0000006e //C 0f734  2066 db	110 */
0x0000f735, 0x00000074, /* 00000074 //C 0f735  2066 db	116 */
0x0000f736, 0x0000000a, /* 0000000a //C 0f736  2066 db	10 */
0x0000f737, 0x00000000, /* 00000000 //C 0f737  2066 db */
0x0000f738, 0x0000006c, /* 0000006c //C 0f738  2067 db	108 */
0x0000f739, 0x0000005b, /* 0000005b //C 0f739  2067 db	91 */
0x0000f73a, 0x0000006f, /* 0000006f //C 0f73a  2067 db	111 */
0x0000f73b, 0x00000061, /* 00000061 //C 0f73b  2067 db	97 */
0x0000f73c, 0x00000064, /* 00000064 //C 0f73c  2067 db	100 */
0x0000f73d, 0x0000005d, /* 0000005d //C 0f73d  2067 db	93 */
0x0000f73e, 0x00000020, /* 00000020 //C 0f73e  2067 db	32 */
0x0000f73f, 0x00000020, /* 00000020 //C 0f73f  2067 db	32 */
0x0000f740, 0x00000020, /* 00000020 //C 0f740  2067 db	32 */
0x0000f741, 0x00000020, /* 00000020 //C 0f741  2067 db	32 */
0x0000f742, 0x00000020, /* 00000020 //C 0f742  2067 db	32 */
0x0000f743, 0x00000020, /* 00000020 //C 0f743  2067 db	32 */
0x0000f744, 0x00000020, /* 00000020 //C 0f744  2067 db	32 */
0x0000f745, 0x00000020, /* 00000020 //C 0f745  2067 db	32 */
0x0000f746, 0x00000020, /* 00000020 //C 0f746  2067 db	32 */
0x0000f747, 0x00000020, /* 00000020 //C 0f747  2067 db	32 */
0x0000f748, 0x00000020, /* 00000020 //C 0f748  2067 db	32 */
0x0000f749, 0x00000020, /* 00000020 //C 0f749  2067 db	32 */
0x0000f74a, 0x0000004c, /* 0000004c //C 0f74a  2067 db	76 */
0x0000f74b, 0x0000006f, /* 0000006f //C 0f74b  2067 db	111 */
0x0000f74c, 0x00000061, /* 00000061 //C 0f74c  2067 db	97 */
0x0000f74d, 0x00000064, /* 00000064 //C 0f74d  2067 db	100 */
0x0000f74e, 0x00000020, /* 00000020 //C 0f74e  2067 db	32 */
0x0000f74f, 0x00000068, /* 00000068 //C 0f74f  2067 db	104 */
0x0000f750, 0x00000065, /* 00000065 //C 0f750  2067 db	101 */
0x0000f751, 0x00000078, /* 00000078 //C 0f751  2067 db	120 */
0x0000f752, 0x00000020, /* 00000020 //C 0f752  2067 db	32 */
0x0000f753, 0x00000066, /* 00000066 //C 0f753  2067 db	102 */
0x0000f754, 0x00000069, /* 00000069 //C 0f754  2067 db	105 */
0x0000f755, 0x0000006c, /* 0000006c //C 0f755  2067 db	108 */
0x0000f756, 0x00000065, /* 00000065 //C 0f756  2067 db	101 */
0x0000f757, 0x00000020, /* 00000020 //C 0f757  2067 db	32 */
0x0000f758, 0x00000074, /* 00000074 //C 0f758  2067 db	116 */
0x0000f759, 0x0000006f, /* 0000006f //C 0f759  2067 db	111 */
0x0000f75a, 0x00000020, /* 00000020 //C 0f75a  2067 db	32 */
0x0000f75b, 0x0000006d, /* 0000006d //C 0f75b  2067 db	109 */
0x0000f75c, 0x00000065, /* 00000065 //C 0f75c  2067 db	101 */
0x0000f75d, 0x0000006d, /* 0000006d //C 0f75d  2067 db	109 */
0x0000f75e, 0x0000006f, /* 0000006f //C 0f75e  2067 db	111 */
0x0000f75f, 0x00000072, /* 00000072 //C 0f75f  2067 db	114 */
0x0000f760, 0x00000079, /* 00000079 //C 0f760  2067 db	121 */
0x0000f761, 0x0000000a, /* 0000000a //C 0f761  2067 db	10 */
0x0000f762, 0x00000000, /* 00000000 //C 0f762  2067 db */
0x0000f763, 0x00000067, /* 00000067 //C 0f763  2068 db	103 */
0x0000f764, 0x0000005b, /* 0000005b //C 0f764  2068 db	91 */
0x0000f765, 0x0000006f, /* 0000006f //C 0f765  2068 db	111 */
0x0000f766, 0x0000005d, /* 0000005d //C 0f766  2068 db	93 */
0x0000f767, 0x0000007c, /* 0000007c //C 0f767  2068 db	124 */
0x0000f768, 0x00000072, /* 00000072 //C 0f768  2068 db	114 */
0x0000f769, 0x00000075, /* 00000075 //C 0f769  2068 db	117 */
0x0000f76a, 0x0000006e, /* 0000006e //C 0f76a  2068 db	110 */
0x0000f76b, 0x00000020, /* 00000020 //C 0f76b  2068 db	32 */
0x0000f76c, 0x0000005b, /* 0000005b //C 0f76c  2068 db	91 */
0x0000f76d, 0x00000061, /* 00000061 //C 0f76d  2068 db	97 */
0x0000f76e, 0x00000064, /* 00000064 //C 0f76e  2068 db	100 */
0x0000f76f, 0x00000064, /* 00000064 //C 0f76f  2068 db	100 */
0x0000f770, 0x00000072, /* 00000072 //C 0f770  2068 db	114 */
0x0000f771, 0x0000005d, /* 0000005d //C 0f771  2068 db	93 */
0x0000f772, 0x00000020, /* 00000020 //C 0f772  2068 db	32 */
0x0000f773, 0x00000020, /* 00000020 //C 0f773  2068 db	32 */
0x0000f774, 0x00000020, /* 00000020 //C 0f774  2068 db	32 */
0x0000f775, 0x00000052, /* 00000052 //C 0f775  2068 db	82 */
0x0000f776, 0x00000075, /* 00000075 //C 0f776  2068 db	117 */
0x0000f777, 0x0000006e, /* 0000006e //C 0f777  2068 db	110 */
0x0000f778, 0x00000020, /* 00000020 //C 0f778  2068 db	32 */
0x0000f779, 0x00000066, /* 00000066 //C 0f779  2068 db	102 */
0x0000f77a, 0x00000072, /* 00000072 //C 0f77a  2068 db	114 */
0x0000f77b, 0x0000006f, /* 0000006f //C 0f77b  2068 db	111 */
0x0000f77c, 0x0000006d, /* 0000006d //C 0f77c  2068 db	109 */
0x0000f77d, 0x00000020, /* 00000020 //C 0f77d  2068 db	32 */
0x0000f77e, 0x00000061, /* 00000061 //C 0f77e  2068 db	97 */
0x0000f77f, 0x00000064, /* 00000064 //C 0f77f  2068 db	100 */
0x0000f780, 0x00000064, /* 00000064 //C 0f780  2068 db	100 */
0x0000f781, 0x00000072, /* 00000072 //C 0f781  2068 db	114 */
0x0000f782, 0x00000065, /* 00000065 //C 0f782  2068 db	101 */
0x0000f783, 0x00000073, /* 00000073 //C 0f783  2068 db	115 */
0x0000f784, 0x00000073, /* 00000073 //C 0f784  2068 db	115 */
0x0000f785, 0x0000000a, /* 0000000a //C 0f785  2068 db	10 */
0x0000f786, 0x00000000, /* 00000000 //C 0f786  2068 db */
0x0000f787, 0x00000072, /* 00000072 //C 0f787  2069 db	114 */
0x0000f788, 0x0000005b, /* 0000005b //C 0f788  2069 db	91 */
0x0000f789, 0x00000065, /* 00000065 //C 0f789  2069 db	101 */
0x0000f78a, 0x00000067, /* 00000067 //C 0f78a  2069 db	103 */
0x0000f78b, 0x0000005b, /* 0000005b //C 0f78b  2069 db	91 */
0x0000f78c, 0x00000073, /* 00000073 //C 0f78c  2069 db	115 */
0x0000f78d, 0x0000005d, /* 0000005d //C 0f78d  2069 db	93 */
0x0000f78e, 0x0000005d, /* 0000005d //C 0f78e  2069 db	93 */
0x0000f78f, 0x00000020, /* 00000020 //C 0f78f  2069 db	32 */
0x0000f790, 0x00000020, /* 00000020 //C 0f790  2069 db	32 */
0x0000f791, 0x00000020, /* 00000020 //C 0f791  2069 db	32 */
0x0000f792, 0x00000020, /* 00000020 //C 0f792  2069 db	32 */
0x0000f793, 0x00000020, /* 00000020 //C 0f793  2069 db	32 */
0x0000f794, 0x00000020, /* 00000020 //C 0f794  2069 db	32 */
0x0000f795, 0x00000020, /* 00000020 //C 0f795  2069 db	32 */
0x0000f796, 0x00000020, /* 00000020 //C 0f796  2069 db	32 */
0x0000f797, 0x00000020, /* 00000020 //C 0f797  2069 db	32 */
0x0000f798, 0x00000020, /* 00000020 //C 0f798  2069 db	32 */
0x0000f799, 0x00000050, /* 00000050 //C 0f799  2069 db	80 */
0x0000f79a, 0x00000072, /* 00000072 //C 0f79a  2069 db	114 */
0x0000f79b, 0x00000069, /* 00000069 //C 0f79b  2069 db	105 */
0x0000f79c, 0x0000006e, /* 0000006e //C 0f79c  2069 db	110 */
0x0000f79d, 0x00000074, /* 00000074 //C 0f79d  2069 db	116 */
0x0000f79e, 0x00000020, /* 00000020 //C 0f79e  2069 db	32 */
0x0000f79f, 0x00000072, /* 00000072 //C 0f79f  2069 db	114 */
0x0000f7a0, 0x00000065, /* 00000065 //C 0f7a0  2069 db	101 */
0x0000f7a1, 0x00000067, /* 00000067 //C 0f7a1  2069 db	103 */
0x0000f7a2, 0x00000069, /* 00000069 //C 0f7a2  2069 db	105 */
0x0000f7a3, 0x00000073, /* 00000073 //C 0f7a3  2069 db	115 */
0x0000f7a4, 0x00000074, /* 00000074 //C 0f7a4  2069 db	116 */
0x0000f7a5, 0x00000065, /* 00000065 //C 0f7a5  2069 db	101 */
0x0000f7a6, 0x00000072, /* 00000072 //C 0f7a6  2069 db	114 */
0x0000f7a7, 0x00000073, /* 00000073 //C 0f7a7  2069 db	115 */
0x0000f7a8, 0x0000000a, /* 0000000a //C 0f7a8  2069 db	10 */
0x0000f7a9, 0x00000000, /* 00000000 //C 0f7a9  2069 db */
0x0000f7aa, 0x00000072, /* 00000072 //C 0f7aa  2070 db	114 */
0x0000f7ab, 0x00000058, /* 00000058 //C 0f7ab  2070 db	88 */
0x0000f7ac, 0x00000020, /* 00000020 //C 0f7ac  2070 db	32 */
0x0000f7ad, 0x0000005b, /* 0000005b //C 0f7ad  2070 db	91 */
0x0000f7ae, 0x00000076, /* 00000076 //C 0f7ae  2070 db	118 */
0x0000f7af, 0x00000061, /* 00000061 //C 0f7af  2070 db	97 */
0x0000f7b0, 0x0000006c, /* 0000006c //C 0f7b0  2070 db	108 */
0x0000f7b1, 0x0000005d, /* 0000005d //C 0f7b1  2070 db	93 */
0x0000f7b2, 0x00000020, /* 00000020 //C 0f7b2  2070 db	32 */
0x0000f7b3, 0x00000020, /* 00000020 //C 0f7b3  2070 db	32 */
0x0000f7b4, 0x00000020, /* 00000020 //C 0f7b4  2070 db	32 */
0x0000f7b5, 0x00000020, /* 00000020 //C 0f7b5  2070 db	32 */
0x0000f7b6, 0x00000020, /* 00000020 //C 0f7b6  2070 db	32 */
0x0000f7b7, 0x00000020, /* 00000020 //C 0f7b7  2070 db	32 */
0x0000f7b8, 0x00000020, /* 00000020 //C 0f7b8  2070 db	32 */
0x0000f7b9, 0x00000020, /* 00000020 //C 0f7b9  2070 db	32 */
0x0000f7ba, 0x00000020, /* 00000020 //C 0f7ba  2070 db	32 */
0x0000f7bb, 0x00000020, /* 00000020 //C 0f7bb  2070 db	32 */
0x0000f7bc, 0x00000047, /* 00000047 //C 0f7bc  2070 db	71 */
0x0000f7bd, 0x00000065, /* 00000065 //C 0f7bd  2070 db	101 */
0x0000f7be, 0x00000074, /* 00000074 //C 0f7be  2070 db	116 */
0x0000f7bf, 0x0000002f, /* 0000002f //C 0f7bf  2070 db	47 */
0x0000f7c0, 0x00000073, /* 00000073 //C 0f7c0  2070 db	115 */
0x0000f7c1, 0x00000065, /* 00000065 //C 0f7c1  2070 db	101 */
0x0000f7c2, 0x00000074, /* 00000074 //C 0f7c2  2070 db	116 */
0x0000f7c3, 0x00000020, /* 00000020 //C 0f7c3  2070 db	32 */
0x0000f7c4, 0x00000052, /* 00000052 //C 0f7c4  2070 db	82 */
0x0000f7c5, 0x00000058, /* 00000058 //C 0f7c5  2070 db	88 */
0x0000f7c6, 0x0000000a, /* 0000000a //C 0f7c6  2070 db	10 */
0x0000f7c7, 0x00000000, /* 00000000 //C 0f7c7  2070 db */
0x0000f7c8, 0x00000073, /* 00000073 //C 0f7c8  2071 db	115 */
0x0000f7c9, 0x00000070, /* 00000070 //C 0f7c9  2071 db	112 */
0x0000f7ca, 0x00000020, /* 00000020 //C 0f7ca  2071 db	32 */
0x0000f7cb, 0x0000005b, /* 0000005b //C 0f7cb  2071 db	91 */
0x0000f7cc, 0x00000076, /* 00000076 //C 0f7cc  2071 db	118 */
0x0000f7cd, 0x00000061, /* 00000061 //C 0f7cd  2071 db	97 */
0x0000f7ce, 0x0000006c, /* 0000006c //C 0f7ce  2071 db	108 */
0x0000f7cf, 0x0000005d, /* 0000005d //C 0f7cf  2071 db	93 */
0x0000f7d0, 0x00000020, /* 00000020 //C 0f7d0  2071 db	32 */
0x0000f7d1, 0x00000020, /* 00000020 //C 0f7d1  2071 db	32 */
0x0000f7d2, 0x00000020, /* 00000020 //C 0f7d2  2071 db	32 */
0x0000f7d3, 0x00000020, /* 00000020 //C 0f7d3  2071 db	32 */
0x0000f7d4, 0x00000020, /* 00000020 //C 0f7d4  2071 db	32 */
0x0000f7d5, 0x00000020, /* 00000020 //C 0f7d5  2071 db	32 */
0x0000f7d6, 0x00000020, /* 00000020 //C 0f7d6  2071 db	32 */
0x0000f7d7, 0x00000020, /* 00000020 //C 0f7d7  2071 db	32 */
0x0000f7d8, 0x00000020, /* 00000020 //C 0f7d8  2071 db	32 */
0x0000f7d9, 0x00000020, /* 00000020 //C 0f7d9  2071 db	32 */
0x0000f7da, 0x00000047, /* 00000047 //C 0f7da  2071 db	71 */
0x0000f7db, 0x00000065, /* 00000065 //C 0f7db  2071 db	101 */
0x0000f7dc, 0x00000074, /* 00000074 //C 0f7dc  2071 db	116 */
0x0000f7dd, 0x0000002f, /* 0000002f //C 0f7dd  2071 db	47 */
0x0000f7de, 0x00000073, /* 00000073 //C 0f7de  2071 db	115 */
0x0000f7df, 0x00000065, /* 00000065 //C 0f7df  2071 db	101 */
0x0000f7e0, 0x00000074, /* 00000074 //C 0f7e0  2071 db	116 */
0x0000f7e1, 0x00000020, /* 00000020 //C 0f7e1  2071 db	32 */
0x0000f7e2, 0x00000052, /* 00000052 //C 0f7e2  2071 db	82 */
0x0000f7e3, 0x00000031, /* 00000031 //C 0f7e3  2071 db	49 */
0x0000f7e4, 0x00000033, /* 00000033 //C 0f7e4  2071 db	51 */
0x0000f7e5, 0x0000000a, /* 0000000a //C 0f7e5  2071 db	10 */
0x0000f7e6, 0x00000000, /* 00000000 //C 0f7e6  2071 db */
0x0000f7e7, 0x0000006c, /* 0000006c //C 0f7e7  2072 db	108 */
0x0000f7e8, 0x00000072, /* 00000072 //C 0f7e8  2072 db	114 */
0x0000f7e9, 0x00000020, /* 00000020 //C 0f7e9  2072 db	32 */
0x0000f7ea, 0x0000005b, /* 0000005b //C 0f7ea  2072 db	91 */
0x0000f7eb, 0x00000076, /* 00000076 //C 0f7eb  2072 db	118 */
0x0000f7ec, 0x00000061, /* 00000061 //C 0f7ec  2072 db	97 */
0x0000f7ed, 0x0000006c, /* 0000006c //C 0f7ed  2072 db	108 */
0x0000f7ee, 0x0000005d, /* 0000005d //C 0f7ee  2072 db	93 */
0x0000f7ef, 0x00000020, /* 00000020 //C 0f7ef  2072 db	32 */
0x0000f7f0, 0x00000020, /* 00000020 //C 0f7f0  2072 db	32 */
0x0000f7f1, 0x00000020, /* 00000020 //C 0f7f1  2072 db	32 */
0x0000f7f2, 0x00000020, /* 00000020 //C 0f7f2  2072 db	32 */
0x0000f7f3, 0x00000020, /* 00000020 //C 0f7f3  2072 db	32 */
0x0000f7f4, 0x00000020, /* 00000020 //C 0f7f4  2072 db	32 */
0x0000f7f5, 0x00000020, /* 00000020 //C 0f7f5  2072 db	32 */
0x0000f7f6, 0x00000020, /* 00000020 //C 0f7f6  2072 db	32 */
0x0000f7f7, 0x00000020, /* 00000020 //C 0f7f7  2072 db	32 */
0x0000f7f8, 0x00000020, /* 00000020 //C 0f7f8  2072 db	32 */
0x0000f7f9, 0x00000047, /* 00000047 //C 0f7f9  2072 db	71 */
0x0000f7fa, 0x00000065, /* 00000065 //C 0f7fa  2072 db	101 */
0x0000f7fb, 0x00000074, /* 00000074 //C 0f7fb  2072 db	116 */
0x0000f7fc, 0x0000002f, /* 0000002f //C 0f7fc  2072 db	47 */
0x0000f7fd, 0x00000073, /* 00000073 //C 0f7fd  2072 db	115 */
0x0000f7fe, 0x00000065, /* 00000065 //C 0f7fe  2072 db	101 */
0x0000f7ff, 0x00000074, /* 00000074 //C 0f7ff  2072 db	116 */
0x0000f800, 0x00000020, /* 00000020 //C 0f800  2072 db	32 */
0x0000f801, 0x00000052, /* 00000052 //C 0f801  2072 db	82 */
0x0000f802, 0x00000031, /* 00000031 //C 0f802  2072 db	49 */
0x0000f803, 0x00000034, /* 00000034 //C 0f803  2072 db	52 */
0x0000f804, 0x0000000a, /* 0000000a //C 0f804  2072 db	10 */
0x0000f805, 0x00000000, /* 00000000 //C 0f805  2072 db */
0x0000f806, 0x00000070, /* 00000070 //C 0f806  2073 db	112 */
0x0000f807, 0x00000063, /* 00000063 //C 0f807  2073 db	99 */
0x0000f808, 0x00000020, /* 00000020 //C 0f808  2073 db	32 */
0x0000f809, 0x0000005b, /* 0000005b //C 0f809  2073 db	91 */
0x0000f80a, 0x00000076, /* 00000076 //C 0f80a  2073 db	118 */
0x0000f80b, 0x00000061, /* 00000061 //C 0f80b  2073 db	97 */
0x0000f80c, 0x0000006c, /* 0000006c //C 0f80c  2073 db	108 */
0x0000f80d, 0x0000005d, /* 0000005d //C 0f80d  2073 db	93 */
0x0000f80e, 0x00000020, /* 00000020 //C 0f80e  2073 db	32 */
0x0000f80f, 0x00000020, /* 00000020 //C 0f80f  2073 db	32 */
0x0000f810, 0x00000020, /* 00000020 //C 0f810  2073 db	32 */
0x0000f811, 0x00000020, /* 00000020 //C 0f811  2073 db	32 */
0x0000f812, 0x00000020, /* 00000020 //C 0f812  2073 db	32 */
0x0000f813, 0x00000020, /* 00000020 //C 0f813  2073 db	32 */
0x0000f814, 0x00000020, /* 00000020 //C 0f814  2073 db	32 */
0x0000f815, 0x00000020, /* 00000020 //C 0f815  2073 db	32 */
0x0000f816, 0x00000020, /* 00000020 //C 0f816  2073 db	32 */
0x0000f817, 0x00000020, /* 00000020 //C 0f817  2073 db	32 */
0x0000f818, 0x00000047, /* 00000047 //C 0f818  2073 db	71 */
0x0000f819, 0x00000065, /* 00000065 //C 0f819  2073 db	101 */
0x0000f81a, 0x00000074, /* 00000074 //C 0f81a  2073 db	116 */
0x0000f81b, 0x0000002f, /* 0000002f //C 0f81b  2073 db	47 */
0x0000f81c, 0x00000073, /* 00000073 //C 0f81c  2073 db	115 */
0x0000f81d, 0x00000065, /* 00000065 //C 0f81d  2073 db	101 */
0x0000f81e, 0x00000074, /* 00000074 //C 0f81e  2073 db	116 */
0x0000f81f, 0x00000020, /* 00000020 //C 0f81f  2073 db	32 */
0x0000f820, 0x00000052, /* 00000052 //C 0f820  2073 db	82 */
0x0000f821, 0x00000031, /* 00000031 //C 0f821  2073 db	49 */
0x0000f822, 0x00000035, /* 00000035 //C 0f822  2073 db	53 */
0x0000f823, 0x0000000a, /* 0000000a //C 0f823  2073 db	10 */
0x0000f824, 0x00000000, /* 00000000 //C 0f824  2073 db */
0x0000f825, 0x00000066, /* 00000066 //C 0f825  2074 db	102 */
0x0000f826, 0x00000020, /* 00000020 //C 0f826  2074 db	32 */
0x0000f827, 0x0000005b, /* 0000005b //C 0f827  2074 db	91 */
0x0000f828, 0x00000076, /* 00000076 //C 0f828  2074 db	118 */
0x0000f829, 0x00000061, /* 00000061 //C 0f829  2074 db	97 */
0x0000f82a, 0x0000006c, /* 0000006c //C 0f82a  2074 db	108 */
0x0000f82b, 0x0000005d, /* 0000005d //C 0f82b  2074 db	93 */
0x0000f82c, 0x00000020, /* 00000020 //C 0f82c  2074 db	32 */
0x0000f82d, 0x00000020, /* 00000020 //C 0f82d  2074 db	32 */
0x0000f82e, 0x00000020, /* 00000020 //C 0f82e  2074 db	32 */
0x0000f82f, 0x00000020, /* 00000020 //C 0f82f  2074 db	32 */
0x0000f830, 0x00000020, /* 00000020 //C 0f830  2074 db	32 */
0x0000f831, 0x00000020, /* 00000020 //C 0f831  2074 db	32 */
0x0000f832, 0x00000020, /* 00000020 //C 0f832  2074 db	32 */
0x0000f833, 0x00000020, /* 00000020 //C 0f833  2074 db	32 */
0x0000f834, 0x00000020, /* 00000020 //C 0f834  2074 db	32 */
0x0000f835, 0x00000020, /* 00000020 //C 0f835  2074 db	32 */
0x0000f836, 0x00000020, /* 00000020 //C 0f836  2074 db	32 */
0x0000f837, 0x00000047, /* 00000047 //C 0f837  2074 db	71 */
0x0000f838, 0x00000065, /* 00000065 //C 0f838  2074 db	101 */
0x0000f839, 0x00000074, /* 00000074 //C 0f839  2074 db	116 */
0x0000f83a, 0x0000002f, /* 0000002f //C 0f83a  2074 db	47 */
0x0000f83b, 0x00000073, /* 00000073 //C 0f83b  2074 db	115 */
0x0000f83c, 0x00000065, /* 00000065 //C 0f83c  2074 db	101 */
0x0000f83d, 0x00000074, /* 00000074 //C 0f83d  2074 db	116 */
0x0000f83e, 0x00000020, /* 00000020 //C 0f83e  2074 db	32 */
0x0000f83f, 0x00000066, /* 00000066 //C 0f83f  2074 db	102 */
0x0000f840, 0x0000006c, /* 0000006c //C 0f840  2074 db	108 */
0x0000f841, 0x00000061, /* 00000061 //C 0f841  2074 db	97 */
0x0000f842, 0x00000067, /* 00000067 //C 0f842  2074 db	103 */
0x0000f843, 0x00000073, /* 00000073 //C 0f843  2074 db	115 */
0x0000f844, 0x0000000a, /* 0000000a //C 0f844  2074 db	10 */
0x0000f845, 0x00000000, /* 00000000 //C 0f845  2074 db */
0x0000f846, 0x00000068, /* 00000068 //C 0f846  2075 db	104 */
0x0000f847, 0x0000005b, /* 0000005b //C 0f847  2075 db	91 */
0x0000f848, 0x00000065, /* 00000065 //C 0f848  2075 db	101 */
0x0000f849, 0x0000006c, /* 0000006c //C 0f849  2075 db	108 */
0x0000f84a, 0x00000070, /* 00000070 //C 0f84a  2075 db	112 */
0x0000f84b, 0x0000005d, /* 0000005d //C 0f84b  2075 db	93 */
0x0000f84c, 0x0000002c, /* 0000002c //C 0f84c  2075 db	44 */
0x0000f84d, 0x0000003f, /* 0000003f //C 0f84d  2075 db	63 */
0x0000f84e, 0x00000020, /* 00000020 //C 0f84e  2075 db	32 */
0x0000f84f, 0x00000020, /* 00000020 //C 0f84f  2075 db	32 */
0x0000f850, 0x00000020, /* 00000020 //C 0f850  2075 db	32 */
0x0000f851, 0x00000020, /* 00000020 //C 0f851  2075 db	32 */
0x0000f852, 0x00000020, /* 00000020 //C 0f852  2075 db	32 */
0x0000f853, 0x00000020, /* 00000020 //C 0f853  2075 db	32 */
0x0000f854, 0x00000020, /* 00000020 //C 0f854  2075 db	32 */
0x0000f855, 0x00000020, /* 00000020 //C 0f855  2075 db	32 */
0x0000f856, 0x00000020, /* 00000020 //C 0f856  2075 db	32 */
0x0000f857, 0x00000020, /* 00000020 //C 0f857  2075 db	32 */
0x0000f858, 0x00000048, /* 00000048 //C 0f858  2075 db	72 */
0x0000f859, 0x00000065, /* 00000065 //C 0f859  2075 db	101 */
0x0000f85a, 0x0000006c, /* 0000006c //C 0f85a  2075 db	108 */
0x0000f85b, 0x00000070, /* 00000070 //C 0f85b  2075 db	112 */
0x0000f85c, 0x0000000a, /* 0000000a //C 0f85c  2075 db	10 */
0x0000f85d, 0x00000000, /* 00000000 //C 0f85d  2075 db */
0x0000f85e, 0x00000000, /* 00000000 //C 0f85e  2076 dd	0 */
0x0000f85f, 0x00000000, /* 00000000 //C 0f85f  2082 ds	0x40 */
0x0000f89f, 0x00000000, /* 00000000 //C 0f89f  2084 ds	1 */
0x0000f8a0, 0x00000000, /* 00000000 //C 0f8a0     3  */
0xffffffff, 0xffffffff
};
