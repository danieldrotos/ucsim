#include "pmon.h"

const char * p12cpu_version= "2.2.7";

t_mem pmon[]= {
0x00000000, 0x01f2f03c, /* 01f2f03c //C 00000    21 jmp	cold_start */
0x0000f000, 0x01f2f025, /* 01f2f025 //C 0f000    26 _f000:	jmp	callin */
0x0000f001, 0x01f2f016, /* 01f2f016 //C 0f001    27 _f001:	jmp	enter_by_uart */
0x0000f002, 0x01f2f490, /* 01f2f490 //C 0f002    28 _f002:	jmp	getchar */
0x0000f003, 0x00f00e00, /* 00f00e00 //C 0f003    29 _f003:	ret */
0x0000f004, 0x00f00e00, /* 00f00e00 //C 0f004    30 _f004:	ret */
0x0000f005, 0x01f2f03c, /* 01f2f03c //C 0f005    31 _f005:	jmp	cold_start */
0x0000f006, 0x01f2f3a2, /* 01f2f3a2 //C 0f006    32 _f006:	jmp	strchr */
0x0000f007, 0x01f2f414, /* 01f2f414 //C 0f007    33 _f007:	jmp	streq */
0x0000f008, 0x01f2f485, /* 01f2f485 //C 0f008    34 _f008:	jmp	check_uart */
0x0000f009, 0x01f2f424, /* 01f2f424 //C 0f009    35 _f009:	jmp	hexchar2value */
0x0000f00a, 0x01f2f453, /* 01f2f453 //C 0f00a    36 _f00a:	jmp	value2hexchar */
0x0000f00b, 0x01f2f457, /* 01f2f457 //C 0f00b    37 _f00b:	jmp	htoi */
0x0000f00c, 0x01f2f41c, /* 01f2f41c //C 0f00c    38 _f00c:	jmp	strieq */
0x0000f00d, 0x01f2f48d, /* 01f2f48d //C 0f00d    39 _f00d:	jmp	read */
0x0000f00e, 0x01f2f494, /* 01f2f494 //C 0f00e    40 _f00e:	jmp	putchar */
0x0000f00f, 0x01f2f49b, /* 01f2f49b //C 0f00f    41 _f00f:	jmp	prints */
0x0000f010, 0x01f2f4d4, /* 01f2f4d4 //C 0f010    42 _f010:	jmp	printsnl */
0x0000f011, 0x01f2f4db, /* 01f2f4db //C 0f011    43 _f011:	jmp	print_vhex */
0x0000f012, 0x01f2f4ba, /* 01f2f4ba //C 0f012    44 _f012:	jmp	pes */
0x0000f013, 0x01f2f559, /* 01f2f559 //C 0f013    45 _f013:	jmp	printd */
0x0000f014, 0x01f2f55e, /* 01f2f55e //C 0f014    46 _f014:	jmp	printf */
0x0000f015, 0x01f2f5dc, /* 01f2f5dc //C 0f015    47 _f015:	jmp	pesf */
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
0x0000f025, 0x0600f653, /* 0600f653 //C 0f025    69 st	r0,reg0 */
0x0000f026, 0x0610f654, /* 0610f654 //C 0f026    70 st	r1,reg1 */
0x0000f027, 0x0620f655, /* 0620f655 //C 0f027    71 st	r2,reg2 */
0x0000f028, 0x0630f656, /* 0630f656 //C 0f028    72 st	r3,reg3 */
0x0000f029, 0x0640f657, /* 0640f657 //C 0f029    73 st	r4,reg4 */
0x0000f02a, 0x0650f658, /* 0650f658 //C 0f02a    74 st	r5,reg5 */
0x0000f02b, 0x0660f659, /* 0660f659 //C 0f02b    75 st	r6,reg6 */
0x0000f02c, 0x0670f65a, /* 0670f65a //C 0f02c    76 st	r7,reg7 */
0x0000f02d, 0x0680f65b, /* 0680f65b //C 0f02d    77 st	r8,reg8 */
0x0000f02e, 0x0690f65c, /* 0690f65c //C 0f02e    78 st	r9,reg9 */
0x0000f02f, 0x06a0f65d, /* 06a0f65d //C 0f02f    79 st	r10,reg10 */
0x0000f030, 0x06b0f65e, /* 06b0f65e //C 0f030    80 st	r11,reg11 */
0x0000f031, 0x06c0f65f, /* 06c0f65f //C 0f031    81 st	r12,reg12 */
0x0000f032, 0x06d0f660, /* 06d0f660 //C 0f032    82 st	r13,reg13 */
0x0000f033, 0x06e0f661, /* 06e0f661 //C 0f033    83 st	r14,reg14 */
0x0000f034, 0x06e0f662, /* 06e0f662 //C 0f034    84 st	r14,reg15 */
0x0000f035, 0x020e0000, /* 020e0000 //C 0f035    85 getf	r0 */
0x0000f036, 0x0600f663, /* 0600f663 //C 0f036    86 st	r0,regf */
0x0000f037, 0x01020001, /* 01020001 //C 0f037    87 mvzl	r0,1 */
0x0000f038, 0x0600f651, /* 0600f651 //C 0f038    88 st	r0,called */
0x0000f039, 0x01f2f046, /* 01f2f046 //C 0f039    89 jmp	common_start */
0x0000f03a, 0x01f2f046, /* 01f2f046 //C 0f03a    91 jmp	common_start */
0x0000f03b, 0x01f2f03c, /* 01f2f03c //C 0f03b    93 jmp	cold_start */
0x0000f03c, 0x01020000, /* 01020000 //C 0f03c    95 mvzl	r0,0 */
0x0000f03d, 0x0600f651, /* 0600f651 //C 0f03d    96 st	r0,called */
0x0000f03e, 0x0102f03b, /* 0102f03b //C 0f03e    97 mvzl	r0,def_zero	; restore jmp to monitor at zero */
0x0000f03f, 0x0e000000, /* 0e000000 //C 0f03f    98 ld	r0,r0 */
0x0000f040, 0x06000000, /* 06000000 //C 0f040    99 st	r0,0 */
0x0000f041, 0x01020000, /* 01020000 //C 0f041   100 mvzl	r0,0		; def values of some regs */
0x0000f042, 0x0600f663, /* 0600f663 //C 0f042   101 st	r0,regf		; FALGS= 0 */
0x0000f043, 0x0102f7ff, /* 0102f7ff //C 0f043   102 mvzl	r0,0xf7ff	; R13= 0xf7ff */
0x0000f044, 0x0600f660, /* 0600f660 //C 0f044   103 st	r0,reg13 */
0x0000f045, 0x01f2f046, /* 01f2f046 //C 0f045   104 jmp	common_start */
0x0000f046, 0x01d2f8b4, /* 01d2f8b4 //C 0f046   107 mvzl	sp,stack_end */
0x0000f047, 0x01020001, /* 01020001 //C 0f047   108 mvzl	r0,1 */
0x0000f048, 0x0600f650, /* 0600f650 //C 0f048   109 st	r0,echo */
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
0x0000f054, 0x0400f494, /* 0400f494 //C 0f054   129 call	putchar */
0x0000f055, 0x06020100, /* 06020100 //C 0f055   130 rds	r0,sver */
0x0000f056, 0x0611c002, /* 0611c002 //C 0f056   131 getbz	r1,r0,2 */
0x0000f057, 0x0621c001, /* 0621c001 //C 0f057   132 getbz	r2,r0,1 */
0x0000f058, 0x0631c000, /* 0631c000 //C 0f058   133 getbz	r3,r0,0 */
0x0000f059, 0x0102f664, /* 0102f664 //C 0f059   134 mvzl	r0,msg_start */
0x0000f05a, 0x0400f55e, /* 0400f55e //C 0f05a   135 call	printf */
0x0000f05b, 0x0700f651, /* 0700f651 //C 0f05b   137 ld	r0,called */
0x0000f05c, 0x020b0000, /* 020b0000 //C 0f05c   138 sz	r0 */
0x0000f05d, 0x11f2f067, /* 11f2f067 //C 0f05d   139 jz	no_called_from */
0x0000f05e, 0x0102000a, /* 0102000a //C 0f05e   140 mvzl	r0,LF */
0x0000f05f, 0x0400f494, /* 0400f494 //C 0f05f   141 call	putchar */
0x0000f060, 0x0102f683, /* 0102f683 //C 0f060   142 mvzl	r0,msg_stopat */
0x0000f061, 0x0400f49b, /* 0400f49b //C 0f061   143 call	prints */
0x0000f062, 0x0700f661, /* 0700f661 //C 0f062   144 ld	r0,reg14 */
0x0000f063, 0x01120004, /* 01120004 //C 0f063   145 mvzl	r1,4 */
0x0000f064, 0x0400f4db, /* 0400f4db //C 0f064   146 call	print_vhex */
0x0000f065, 0x0102000a, /* 0102000a //C 0f065   147 mvzl	r0,LF */
0x0000f066, 0x0400f494, /* 0400f494 //C 0f066   148 call	putchar */
0x0000f067, 0x0400f069, /* 0400f069 //C 0f067   152 call	setup_line */
0x0000f068, 0x01f2f072, /* 01f2f072 //C 0f068   156 jmp	main */
0x0000f069, 0x0ded0000, /* 0ded0000 //C 0f069   162 push	lr */
0x0000f06a, 0x01120000, /* 01120000 //C 0f06a   163 mvzl	r1,0		; lptr= 0 */
0x0000f06b, 0x0610f649, /* 0610f649 //C 0f06b   164 st	r1,line_ptr */
0x0000f06c, 0x0610f5e5, /* 0610f5e5 //C 0f06c   165 st	r1,line		; line[0]= 0 */
0x0000f06d, 0x01120000, /* 01120000 //C 0f06d   166 mvzl	r1,0		; at_eol= 0 */
0x0000f06e, 0x0610f64a, /* 0610f64a //C 0f06e   167 st	r1,at_eol */
0x0000f06f, 0x0102f691, /* 0102f691 //C 0f06f   169 mvzl	r0,prompt */
0x0000f070, 0x0400f49b, /* 0400f49b //C 0f070   170 call	prints */
0x0000f071, 0x0ffd0000, /* 0ffd0000 //C 0f071   171 pop	pc */
0x0000f072, 0x0400f485, /* 0400f485 //C 0f072   178 call	check_uart */
0x0000f073, 0x41f2f079, /* 41f2f079 //C 0f073   179 C0 jmp	no_input */
0x0000f074, 0x0400f48d, /* 0400f48d //C 0f074   181 call	read */
0x0000f075, 0x0400f07a, /* 0400f07a //C 0f075   182 call	proc_input */
0x0000f076, 0x41f2f079, /* 41f2f079 //C 0f076   183 C0 jmp	no_line */
0x0000f077, 0x0400f0ab, /* 0400f0ab //C 0f077   186 call	proc_line */
0x0000f078, 0x0400f069, /* 0400f069 //C 0f078   187 call	setup_line */
0x0000f079, 0x01f2f072, /* 01f2f072 //C 0f079   190 jmp	main */
0x0000f07a, 0x0ded0000, /* 0ded0000 //C 0f07a   196 push	lr */
0x0000f07b, 0x0108000a, /* 0108000a //C 0f07b   197 cmp	r0,LF */
0x0000f07c, 0x11f2f0a5, /* 11f2f0a5 //C 0f07c   198 EQ jmp	got_eol */
0x0000f07d, 0x0108000d, /* 0108000d //C 0f07d   199 cmp	r0,CR */
0x0000f07e, 0x11f2f0a5, /* 11f2f0a5 //C 0f07e   200 EQ jmp	got_eol */
0x0000f07f, 0x01080008, /* 01080008 //C 0f07f   201 cmp	r0,8 */
0x0000f080, 0x11f2f084, /* 11f2f084 //C 0f080   202 jz	got_BS */
0x0000f081, 0x0108007f, /* 0108007f //C 0f081   203 cmp	r0,127 */
0x0000f082, 0x11f2f084, /* 11f2f084 //C 0f082   204 jz	got_DEL */
0x0000f083, 0x01f2f090, /* 01f2f090 //C 0f083   205 jmp	got_char */
0x0000f084, 0x0700f649, /* 0700f649 //C 0f084   208 ld	r0,line_ptr */
0x0000f085, 0x020b0000, /* 020b0000 //C 0f085   209 sz	r0 */
0x0000f086, 0x11f2f08e, /* 11f2f08e //C 0f086   210 jz	got_done */
0x0000f087, 0x01060001, /* 01060001 //C 0f087   211 sub	r0,1 */
0x0000f088, 0x0600f649, /* 0600f649 //C 0f088   212 st	r0,line_ptr */
0x0000f089, 0x0112f5e5, /* 0112f5e5 //C 0f089   213 mvzl	r1,line */
0x0000f08a, 0x01220000, /* 01220000 //C 0f08a   214 mvzl	r2,0 */
0x0000f08b, 0x08210000, /* 08210000 //C 0f08b   215 st	r2,r1,r0 */
0x0000f08c, 0x0102f68d, /* 0102f68d //C 0f08c   216 mvzl	r0,msg_BS */
0x0000f08d, 0x0400f49b, /* 0400f49b //C 0f08d   217 call	prints */
0x0000f08e, 0x020d0000, /* 020d0000 //C 0f08e   219 clc */
0x0000f08f, 0x01f2f0aa, /* 01f2f0aa //C 0f08f   220 jmp	proc_input_ret */
0x0000f090, 0x0108001f, /* 0108001f //C 0f090   222 cmp	r0,31		; refuse control chars */
0x0000f091, 0xa1f2f0aa, /* a1f2f0aa //C 0f091   223 LS jmp	proc_input_ret */
0x0000f092, 0x0108007e, /* 0108007e //C 0f092   224 cmp	r0,126		; refuse graph chars */
0x0000f093, 0x91f2f0aa, /* 91f2f0aa //C 0f093   225 HI jmp	proc_input_ret */
0x0000f094, 0x01220000, /* 01220000 //C 0f094   226 mvzl	r2,0		; at_aol= 0 */
0x0000f095, 0x0620f64a, /* 0620f64a //C 0f095   227 st	r2,at_eol */
0x0000f096, 0x0112f649, /* 0112f649 //C 0f096   228 mvzl	r1,line_ptr	; line[line_ptr]= char */
0x0000f097, 0x0e310000, /* 0e310000 //C 0f097   229 ld	r3,r1 */
0x0000f098, 0x0122f5e5, /* 0122f5e5 //C 0f098   230 mvzl	r2,line */
0x0000f099, 0x08020300, /* 08020300 //C 0f099   231 st	r0,r2,r3 */
0x0000f09a, 0x013a0001, /* 013a0001 //C 0f09a   233 plus	r3,1		; line_ptr++ */
0x0000f09b, 0x0c310000, /* 0c310000 //C 0f09b   234 st	r3,r1 */
0x0000f09c, 0x01420000, /* 01420000 //C 0f09c   235 mvzl	r4,0 */
0x0000f09d, 0x09438200, /* 09438200 //C 0f09d   236 st	r4,r3+,r2	; line[line_ptr]= 0 */
0x0000f09e, 0x08430200, /* 08430200 //C 0f09e   237 st	r4,r3,r2	; double 0 at end, needed by tokenizer */
0x0000f09f, 0x0142f650, /* 0142f650 //C 0f09f   238 mvzl	r4,echo		; check if echo is turned on */
0x0000f0a0, 0x0e440000, /* 0e440000 //C 0f0a0   239 ld	r4,r4 */
0x0000f0a1, 0x024b0000, /* 024b0000 //C 0f0a1   240 sz	r4 */
0x0000f0a2, 0x2400f494, /* 2400f494 //C 0f0a2   241 NZ call	putchar		; echo */
0x0000f0a3, 0x020d0000, /* 020d0000 //C 0f0a3   242 clc */
0x0000f0a4, 0x01f2f0aa, /* 01f2f0aa //C 0f0a4   243 jmp	proc_input_ret */
0x0000f0a5, 0x0112f64a, /* 0112f64a //C 0f0a5   245 mvzl	r1,at_eol */
0x0000f0a6, 0x0e110000, /* 0e110000 //C 0f0a6   246 ld	r1,r1 */
0x0000f0a7, 0x021b0000, /* 021b0000 //C 0f0a7   247 sz	r1		; Z=0 at eol -> skip, not ready */
0x0000f0a8, 0x220d0000, /* 220d0000 //C 0f0a8   248 Z0 clc */
0x0000f0a9, 0x120c0000, /* 120c0000 //C 0f0a9   249 Z1 sec */
0x0000f0aa, 0x0ffd0000, /* 0ffd0000 //C 0f0aa   251 pop	pc */
0x0000f0ab, 0x0ded0000, /* 0ded0000 //C 0f0ab   260 push	lr */
0x0000f0ac, 0x0102000a, /* 0102000a //C 0f0ac   262 mvzl	r0,LF */
0x0000f0ad, 0x0400f494, /* 0400f494 //C 0f0ad   263 call	putchar */
0x0000f0ae, 0x0700f5e5, /* 0700f5e5 //C 0f0ae   265 ld	r0,line */
0x0000f0af, 0x020b0000, /* 020b0000 //C 0f0af   266 sz	r0 */
0x0000f0b0, 0x11f2f0b8, /* 11f2f0b8 //C 0f0b0   267 jz	proc_line_ret */
0x0000f0b1, 0x0400f0d4, /* 0400f0d4 //C 0f0b1   275 call	tokenize */
0x0000f0b2, 0x0400f0f4, /* 0400f0f4 //C 0f0b2   286 call	find_cmd */
0x0000f0b3, 0x41f2f0b6, /* 41f2f0b6 //C 0f0b3   287 C0 jmp	cmd_not_found */
0x0000f0b4, 0x05000000, /* 05000000 //C 0f0b4   290 call	r0,0 */
0x0000f0b5, 0x01f2f0b8, /* 01f2f0b8 //C 0f0b5   292 jmp	proc_line_ret */
0x0000f0b6, 0x0102f0c0, /* 0102f0c0 //C 0f0b6   294 mvzl	r0,snotfound */
0x0000f0b7, 0x0400f4d4, /* 0400f4d4 //C 0f0b7   295 call	printsnl */
0x0000f0b8, 0x01120001, /* 01120001 //C 0f0b8   298 mvzl	r1,1		; at_eol= 1 */
0x0000f0b9, 0x0610f64a, /* 0610f64a //C 0f0b9   299 st	r1,at_eol */
0x0000f0ba, 0x0ffd0000, /* 0ffd0000 //C 0f0ba   300 pop	pc */
0x0000f0bb, 0x00000047, /* 00000047 //C 0f0bb   302 db	71 */
0x0000f0bc, 0x0000006f, /* 0000006f //C 0f0bc   302 db	111 */
0x0000f0bd, 0x00000074, /* 00000074 //C 0f0bd   302 db	116 */
0x0000f0be, 0x0000003a, /* 0000003a //C 0f0be   302 db	58 */
0x0000f0bf, 0x00000000, /* 00000000 //C 0f0bf   302 db */
0x0000f0c0, 0x00000055, /* 00000055 //C 0f0c0   303 db	85 */
0x0000f0c1, 0x0000006e, /* 0000006e //C 0f0c1   303 db	110 */
0x0000f0c2, 0x0000006b, /* 0000006b //C 0f0c2   303 db	107 */
0x0000f0c3, 0x0000006e, /* 0000006e //C 0f0c3   303 db	110 */
0x0000f0c4, 0x0000006f, /* 0000006f //C 0f0c4   303 db	111 */
0x0000f0c5, 0x00000077, /* 00000077 //C 0f0c5   303 db	119 */
0x0000f0c6, 0x0000006e, /* 0000006e //C 0f0c6   303 db	110 */
0x0000f0c7, 0x00000020, /* 00000020 //C 0f0c7   303 db	32 */
0x0000f0c8, 0x00000063, /* 00000063 //C 0f0c8   303 db	99 */
0x0000f0c9, 0x0000006f, /* 0000006f //C 0f0c9   303 db	111 */
0x0000f0ca, 0x0000006d, /* 0000006d //C 0f0ca   303 db	109 */
0x0000f0cb, 0x0000006d, /* 0000006d //C 0f0cb   303 db	109 */
0x0000f0cc, 0x00000061, /* 00000061 //C 0f0cc   303 db	97 */
0x0000f0cd, 0x0000006e, /* 0000006e //C 0f0cd   303 db	110 */
0x0000f0ce, 0x00000064, /* 00000064 //C 0f0ce   303 db	100 */
0x0000f0cf, 0x00000000, /* 00000000 //C 0f0cf   303 db */
0x0000f0d0, 0x0ded0000, /* 0ded0000 //C 0f0d0   311 push	lr */
0x0000f0d1, 0x0112f693, /* 0112f693 //C 0f0d1   312 mvzl	r1,delimiters */
0x0000f0d2, 0x0400f3a2, /* 0400f3a2 //C 0f0d2   313 call	strchr */
0x0000f0d3, 0x0ffd0000, /* 0ffd0000 //C 0f0d3   314 pop	pc */
0x0000f0d4, 0x0ded0000, /* 0ded0000 //C 0f0d4   323 push	lr */
0x0000f0d5, 0x0142f64b, /* 0142f64b //C 0f0d5   324 mvzl	r4,words	; array of result */
0x0000f0d6, 0x0152f5e5, /* 0152f5e5 //C 0f0d6   325 mvzl	r5,line		; address of next char */
0x0000f0d7, 0x01620000, /* 01620000 //C 0f0d7   326 mvzl	r6,0		; nuof words found */
0x0000f0d8, 0x01720000, /* 01720000 //C 0f0d8   327 mvzl	r7,0		; bool in_word */
0x0000f0d9, 0x0e050000, /* 0e050000 //C 0f0d9   329 ld	r0,r5		; pick a char */
0x0000f0da, 0x020b0000, /* 020b0000 //C 0f0da   330 sz	r0		; check end */
0x0000f0db, 0x11f2f0e5, /* 11f2f0e5 //C 0f0db   331 jz	tok_delimiter	; found end, pretend delim */
0x0000f0dc, 0x0400f0d0, /* 0400f0d0 //C 0f0dc   333 call	is_delimiter */
0x0000f0dd, 0x31f2f0e5, /* 31f2f0e5 //C 0f0dd   334 C1 jmp	tok_delimiter */
0x0000f0de, 0x027b0000, /* 027b0000 //C 0f0de   336 sz	r7 */
0x0000f0df, 0x21f2f0ea, /* 21f2f0ea //C 0f0df   337 jnz	tok_next	; still inside word */
0x0000f0e0, 0x01720001, /* 01720001 //C 0f0e0   339 mvzl	r7,1		; in_word=true */
0x0000f0e1, 0x09568400, /* 09568400 //C 0f0e1   340 st	r5,r6+,r4	; record word address */
0x0000f0e2, 0x01680005, /* 01680005 //C 0f0e2   341 cmp	r6,MAX_WORDS	; If no more space */
0x0000f0e3, 0x11f2f0ee, /* 11f2f0ee //C 0f0e3   342 EQ jmp	tok_ret		; then return */
0x0000f0e4, 0x01f2f0ea, /* 01f2f0ea //C 0f0e4   343 jmp	tok_next */
0x0000f0e5, 0x027b0000, /* 027b0000 //C 0f0e5   345 sz	r7 */
0x0000f0e6, 0x11f2f0ea, /* 11f2f0ea //C 0f0e6   346 jz	tok_next	; still between words */
0x0000f0e7, 0x01720000, /* 01720000 //C 0f0e7   348 mvzl	r7,0		; in_word=false */
0x0000f0e8, 0x01120000, /* 01120000 //C 0f0e8   349 mvzl	r1,0		; put a 0 at the end of word */
0x0000f0e9, 0x08150100, /* 08150100 //C 0f0e9   350 st	r1,r5,r1 */
0x0000f0ea, 0x020b0000, /* 020b0000 //C 0f0ea   352 sz	r0		; check EOL */
0x0000f0eb, 0x11f2f0ee, /* 11f2f0ee //C 0f0eb   353 jz	tok_ret		; jump out if char==0 */
0x0000f0ec, 0x01540001, /* 01540001 //C 0f0ec   354 add	r5,1 */
0x0000f0ed, 0x01f2f0d9, /* 01f2f0d9 //C 0f0ed   355 jmp	tok_cycle */
0x0000f0ee, 0x01120000, /* 01120000 //C 0f0ee   357 mvzl	r1,0 */
0x0000f0ef, 0x01680005, /* 01680005 //C 0f0ef   358 cmp	r6,MAX_WORDS */
0x0000f0f0, 0x11f2f0f3, /* 11f2f0f3 //C 0f0f0   359 jz	tok_end */
0x0000f0f1, 0x09168400, /* 09168400 //C 0f0f1   360 st	r1,r6+,r4 */
0x0000f0f2, 0x01f2f0ee, /* 01f2f0ee //C 0f0f2   361 jmp	tok_ret */
0x0000f0f3, 0x0ffd0000, /* 0ffd0000 //C 0f0f3   363 pop	pc */
0x0000f0f4, 0x0ded0000, /* 0ded0000 //C 0f0f4   372 push	lr */
0x0000f0f5, 0x0d1d0000, /* 0d1d0000 //C 0f0f5   373 push	r1 */
0x0000f0f6, 0x0d2d0000, /* 0d2d0000 //C 0f0f6   374 push	r2 */
0x0000f0f7, 0x0d3d0000, /* 0d3d0000 //C 0f0f7   375 push	r3 */
0x0000f0f8, 0x0dad0000, /* 0dad0000 //C 0f0f8   376 push	r10 */
0x0000f0f9, 0x0700f64b, /* 0700f64b //C 0f0f9   377 ld	r0,words	; R0= 1st word of command */
0x0000f0fa, 0x020b0000, /* 020b0000 //C 0f0fa   378 sz	r0 */
0x0000f0fb, 0x11f2f12b, /* 11f2f12b //C 0f0fb   379 jz	find_cmd_false */
0x0000f0fc, 0x0e100000, /* 0e100000 //C 0f0fc   382 ld	r1,r0		; 1st char of word1 */
0x0000f0fd, 0x0e200001, /* 0e200001 //C 0f0fd   383 ld	r2,r0,1		; 2nd char */
0x0000f0fe, 0x0e300002, /* 0e300002 //C 0f0fe   384 ld	r3,r0,2		; 3rd char */
0x0000f0ff, 0x011fffdf, /* 011fffdf //C 0f0ff   385 and	r1,0xffdf	; upcase 1st char */
0x0000f100, 0x01180052, /* 01180052 //C 0f100   386 cmp	r1,'R' */
0x0000f101, 0x21f2f117, /* 21f2f117 //C 0f101   387 jnz	find_not_rx */
0x0000f102, 0x0128002f, /* 0128002f //C 0f102   388 cmp	r2,'/'		; '0'-1 */
0x0000f103, 0xa1f2f117, /* a1f2f117 //C 0f103   389 LS jmp	find_not_rx */
0x0000f104, 0x01280039, /* 01280039 //C 0f104   390 cmp	r2,'9' */
0x0000f105, 0x91f2f117, /* 91f2f117 //C 0f105   391 HI jmp	find_not_rx */
0x0000f106, 0x023b0000, /* 023b0000 //C 0f106   392 sz	r3 */
0x0000f107, 0x11f2f112, /* 11f2f112 //C 0f107   393 jz	find_rx_09 */
0x0000f108, 0x01280031, /* 01280031 //C 0f108   395 cmp	r2,'1'		; first char must be '1' */
0x0000f109, 0x21f2f117, /* 21f2f117 //C 0f109   396 jnz	find_not_rx */
0x0000f10a, 0x0138002f, /* 0138002f //C 0f10a   397 cmp	r3,'/'		; '0'-1 */
0x0000f10b, 0xa1f2f117, /* a1f2f117 //C 0f10b   398 LS jmp	find_not_rx */
0x0000f10c, 0x01380035, /* 01380035 //C 0f10c   399 cmp	r3,'5' */
0x0000f10d, 0x91f2f117, /* 91f2f117 //C 0f10d   400 HI jmp	find_not_rx */
0x0000f10e, 0x01360030, /* 01360030 //C 0f10e   401 sub	r3,'0' */
0x0000f10f, 0x0134000a, /* 0134000a //C 0f10f   402 add	r3,10 */
0x0000f110, 0x0630f652, /* 0630f652 //C 0f110   403 st	r3,nuof_reg */
0x0000f111, 0x01f2f114, /* 01f2f114 //C 0f111   404 jmp	find_rx */
0x0000f112, 0x01260030, /* 01260030 //C 0f112   406 sub	r2,'0' */
0x0000f113, 0x0620f652, /* 0620f652 //C 0f113   407 st	r2,nuof_reg */
0x0000f114, 0x0102f361, /* 0102f361 //C 0f114   409 mvzl	r0,cmd_rx */
0x0000f115, 0x020c0000, /* 020c0000 //C 0f115   410 sec */
0x0000f116, 0x01f2f136, /* 01f2f136 //C 0f116   411 jmp	find_cmd_ret */
0x0000f117, 0x01a2f6af, /* 01a2f6af //C 0f117   414 mvzl	r10,commands */
0x0000f118, 0x0e2a0000, /* 0e2a0000 //C 0f118   416 ld	r2,r10		; R2= cmd addr */
0x0000f119, 0x022b0000, /* 022b0000 //C 0f119   417 sz	r2 */
0x0000f11a, 0x11f2f12b, /* 11f2f12b //C 0f11a   418 jz	find_cmd_false */
0x0000f11b, 0x01a40001, /* 01a40001 //C 0f11b   419 add	r10,1 */
0x0000f11c, 0x00100a00, /* 00100a00 //C 0f11c   420 mov	r1,r10		; R1= cmd string */
0x0000f11d, 0x01a40001, /* 01a40001 //C 0f11d   423 add	r10,1 */
0x0000f11e, 0x0e3a0000, /* 0e3a0000 //C 0f11e   424 ld	r3,r10 */
0x0000f11f, 0x023b0000, /* 023b0000 //C 0f11f   425 sz	r3 */
0x0000f120, 0x21f2f11d, /* 21f2f11d //C 0f120   426 jnz	find_cmd_fw */
0x0000f121, 0x01a40001, /* 01a40001 //C 0f121   427 add	r10,1 */
0x0000f122, 0x0400f414, /* 0400f414 //C 0f122   429 call	streq */
0x0000f123, 0x41f2f118, /* 41f2f118 //C 0f123   430 C0 jmp	find_cmd_cyc */
0x0000f124, 0x00000200, /* 00000200 //C 0f124   432 mov	r0,r2 */
0x0000f125, 0x020c0000, /* 020c0000 //C 0f125   433 sec */
0x0000f126, 0x01f2f136, /* 01f2f136 //C 0f126   434 jmp	find_cmd_ret */
0x0000f127, 0x0000002f, /* 0000002f //C 0f127   435 db	47 */
0x0000f128, 0x0000002f, /* 0000002f //C 0f128   435 db	47 */
0x0000f129, 0x00000043, /* 00000043 //C 0f129   435 db	67 */
0x0000f12a, 0x00000000, /* 00000000 //C 0f12a   435 db */
0x0000f12b, 0x01040001, /* 01040001 //C 0f12b   437 add	r0,1		; check second word */
0x0000f12c, 0x0e100000, /* 0e100000 //C 0f12c   438 ld	r1,r0		; for //C command */
0x0000f12d, 0x021b0000, /* 021b0000 //C 0f12d   439 sz	r1 */
0x0000f12e, 0x11f2f134, /* 11f2f134 //C 0f12e   440 jz	find_cmd_very_false */
0x0000f12f, 0x0102f127, /* 0102f127 //C 0f12f   441 mvzl	r0,c_cmd_name */
0x0000f130, 0x0400f414, /* 0400f414 //C 0f130   442 call	streq */
0x0000f131, 0x21f2f134, /* 21f2f134 //C 0f131   443 jnz	find_cmd_very_false */
0x0000f132, 0x0122f1e9, /* 0122f1e9 //C 0f132   444 mvzl	r2,cmd_c */
0x0000f133, 0x01f2f124, /* 01f2f124 //C 0f133   445 jmp	find_cmd_true */
0x0000f134, 0x020d0000, /* 020d0000 //C 0f134   447 clc */
0x0000f135, 0x01020000, /* 01020000 //C 0f135   448 mvzl	r0,0 */
0x0000f136, 0x0fad0000, /* 0fad0000 //C 0f136   450 pop	r10 */
0x0000f137, 0x0f3d0000, /* 0f3d0000 //C 0f137   451 pop	r3 */
0x0000f138, 0x0f2d0000, /* 0f2d0000 //C 0f138   452 pop	r2 */
0x0000f139, 0x0f1d0000, /* 0f1d0000 //C 0f139   453 pop	r1 */
0x0000f13a, 0x0ffd0000, /* 0ffd0000 //C 0f13a   454 pop	pc */
0x0000f13b, 0x0ded0000, /* 0ded0000 //C 0f13b   459 push	lr */
0x0000f13c, 0x0122f64b, /* 0122f64b //C 0f13c   460 mvzl	r2,words */
0x0000f13d, 0x01020000, /* 01020000 //C 0f13d   461 mvzl	r0,0 */
0x0000f13e, 0x0e420001, /* 0e420001 //C 0f13e   463 ld	r4,r2,1		; addr */
0x0000f13f, 0x0e520002, /* 0e520002 //C 0f13f   464 ld	r5,r2,2		; value */
0x0000f140, 0x024b0000, /* 024b0000 //C 0f140   465 sz 	r4 */
0x0000f141, 0x11f2f167, /* 11f2f167 //C 0f141   466 jz	m_ret */
0x0000f142, 0x00000400, /* 00000400 //C 0f142   468 mov	r0,r4 */
0x0000f143, 0x0400f457, /* 0400f457 //C 0f143   469 call	htoi */
0x0000f144, 0x00400100, /* 00400100 //C 0f144   470 mov	r4,r1 */
0x0000f145, 0x31f2f149, /* 31f2f149 //C 0f145   471 C1 jmp	m_addr_ok */
0x0000f146, 0x0102f168, /* 0102f168 //C 0f146   472 mvzl	r0,m_err_addr */
0x0000f147, 0x0400f4d4, /* 0400f4d4 //C 0f147   473 call	printsnl */
0x0000f148, 0x01f2f167, /* 01f2f167 //C 0f148   474 jmp	m_ret */
0x0000f149, 0x025b0000, /* 025b0000 //C 0f149   476 sz	r5 */
0x0000f14a, 0x11f2f15d, /* 11f2f15d //C 0f14a   477 jz	m_read */
0x0000f14b, 0x0132f000, /* 0132f000 //C 0f14b   479 mvzl	r3,the_begin */
0x0000f14c, 0x00380400, /* 00380400 //C 0f14c   480 cmp	r3,r4 */
0x0000f14d, 0x91f2f155, /* 91f2f155 //C 0f14d   481 HI jmp	m_addrv_ok */
0x0000f14e, 0x0132f8b5, /* 0132f8b5 //C 0f14e   482 mvzl	r3,the_end */
0x0000f14f, 0x00380400, /* 00380400 //C 0f14f   483 cmp	r3,r4 */
0x0000f150, 0x91f2f152, /* 91f2f152 //C 0f150   484 HI jmp	m_addrv_nok */
0x0000f151, 0x01f2f155, /* 01f2f155 //C 0f151   485 jmp	m_addrv_ok */
0x0000f152, 0x0102f176, /* 0102f176 //C 0f152   493 mvzl	r0,m_err_addrv */
0x0000f153, 0x0400f4d4, /* 0400f4d4 //C 0f153   494 call	printsnl */
0x0000f154, 0x01f2f167, /* 01f2f167 //C 0f154   495 jmp	m_ret */
0x0000f155, 0x00000500, /* 00000500 //C 0f155   497 mov	r0,r5 */
0x0000f156, 0x0400f457, /* 0400f457 //C 0f156   498 call	htoi */
0x0000f157, 0x00500100, /* 00500100 //C 0f157   499 mov	r5,r1 */
0x0000f158, 0x31f2f15c, /* 31f2f15c //C 0f158   500 C1 jmp	m_value_ok */
0x0000f159, 0x0102f188, /* 0102f188 //C 0f159   501 mvzl	r0,m_err_value */
0x0000f15a, 0x0400f4d4, /* 0400f4d4 //C 0f15a   502 call	printsnl */
0x0000f15b, 0x01f2f167, /* 01f2f167 //C 0f15b   503 jmp	m_ret */
0x0000f15c, 0x0c540000, /* 0c540000 //C 0f15c   505 st	r5,r4 */
0x0000f15d, 0x00000400, /* 00000400 //C 0f15d   508 mov	r0,r4 */
0x0000f15e, 0x01120004, /* 01120004 //C 0f15e   509 mvzl	r1,4 */
0x0000f15f, 0x0400f4db, /* 0400f4db //C 0f15f   510 call	print_vhex */
0x0000f160, 0x01020020, /* 01020020 //C 0f160   511 mvzl	r0,0x20 */
0x0000f161, 0x0400f494, /* 0400f494 //C 0f161   512 call	putchar */
0x0000f162, 0x0e040000, /* 0e040000 //C 0f162   513 ld	r0,r4 */
0x0000f163, 0x01120004, /* 01120004 //C 0f163   514 mvzl	r1,4 */
0x0000f164, 0x0400f4db, /* 0400f4db //C 0f164   515 call	print_vhex */
0x0000f165, 0x0102000a, /* 0102000a //C 0f165   516 mvzl	r0,LF */
0x0000f166, 0x0400f494, /* 0400f494 //C 0f166   517 call	putchar */
0x0000f167, 0x0ffd0000, /* 0ffd0000 //C 0f167   519 pop	pc */
0x0000f168, 0x00000041, /* 00000041 //C 0f168   521 db	65 */
0x0000f169, 0x00000064, /* 00000064 //C 0f169   521 db	100 */
0x0000f16a, 0x00000064, /* 00000064 //C 0f16a   521 db	100 */
0x0000f16b, 0x00000072, /* 00000072 //C 0f16b   521 db	114 */
0x0000f16c, 0x00000065, /* 00000065 //C 0f16c   521 db	101 */
0x0000f16d, 0x00000073, /* 00000073 //C 0f16d   521 db	115 */
0x0000f16e, 0x00000073, /* 00000073 //C 0f16e   521 db	115 */
0x0000f16f, 0x00000020, /* 00000020 //C 0f16f   521 db	32 */
0x0000f170, 0x00000065, /* 00000065 //C 0f170   521 db	101 */
0x0000f171, 0x00000072, /* 00000072 //C 0f171   521 db	114 */
0x0000f172, 0x00000072, /* 00000072 //C 0f172   521 db	114 */
0x0000f173, 0x0000006f, /* 0000006f //C 0f173   521 db	111 */
0x0000f174, 0x00000072, /* 00000072 //C 0f174   521 db	114 */
0x0000f175, 0x00000000, /* 00000000 //C 0f175   521 db */
0x0000f176, 0x0000004d, /* 0000004d //C 0f176   522 db	77 */
0x0000f177, 0x0000006f, /* 0000006f //C 0f177   522 db	111 */
0x0000f178, 0x0000006e, /* 0000006e //C 0f178   522 db	110 */
0x0000f179, 0x00000069, /* 00000069 //C 0f179   522 db	105 */
0x0000f17a, 0x00000074, /* 00000074 //C 0f17a   522 db	116 */
0x0000f17b, 0x0000006f, /* 0000006f //C 0f17b   522 db	111 */
0x0000f17c, 0x00000072, /* 00000072 //C 0f17c   522 db	114 */
0x0000f17d, 0x00000027, /* 00000027 //C 0f17d   522 db	39 */
0x0000f17e, 0x00000073, /* 00000073 //C 0f17e   522 db	115 */
0x0000f17f, 0x00000020, /* 00000020 //C 0f17f   522 db	32 */
0x0000f180, 0x00000061, /* 00000061 //C 0f180   522 db	97 */
0x0000f181, 0x00000064, /* 00000064 //C 0f181   522 db	100 */
0x0000f182, 0x00000064, /* 00000064 //C 0f182   522 db	100 */
0x0000f183, 0x00000072, /* 00000072 //C 0f183   522 db	114 */
0x0000f184, 0x00000065, /* 00000065 //C 0f184   522 db	101 */
0x0000f185, 0x00000073, /* 00000073 //C 0f185   522 db	115 */
0x0000f186, 0x00000073, /* 00000073 //C 0f186   522 db	115 */
0x0000f187, 0x00000000, /* 00000000 //C 0f187   522 db */
0x0000f188, 0x00000056, /* 00000056 //C 0f188   523 db	86 */
0x0000f189, 0x00000061, /* 00000061 //C 0f189   523 db	97 */
0x0000f18a, 0x0000006c, /* 0000006c //C 0f18a   523 db	108 */
0x0000f18b, 0x00000075, /* 00000075 //C 0f18b   523 db	117 */
0x0000f18c, 0x00000065, /* 00000065 //C 0f18c   523 db	101 */
0x0000f18d, 0x00000020, /* 00000020 //C 0f18d   523 db	32 */
0x0000f18e, 0x00000065, /* 00000065 //C 0f18e   523 db	101 */
0x0000f18f, 0x00000072, /* 00000072 //C 0f18f   523 db	114 */
0x0000f190, 0x00000072, /* 00000072 //C 0f190   523 db	114 */
0x0000f191, 0x0000006f, /* 0000006f //C 0f191   523 db	111 */
0x0000f192, 0x00000072, /* 00000072 //C 0f192   523 db	114 */
0x0000f193, 0x00000000, /* 00000000 //C 0f193   523 db */
0x0000f194, 0x0ded0000, /* 0ded0000 //C 0f194   528 push	lr */
0x0000f195, 0x0122f64b, /* 0122f64b //C 0f195   529 mvzl	r2,words */
0x0000f196, 0x01020000, /* 01020000 //C 0f196   530 mvzl	r0,0 */
0x0000f197, 0x0e420001, /* 0e420001 //C 0f197   532 ld	r4,r2,1		; addr */
0x0000f198, 0x0e520002, /* 0e520002 //C 0f198   533 ld	r5,r2,2		; value */
0x0000f199, 0x024b0000, /* 024b0000 //C 0f199   534 sz 	r4 */
0x0000f19a, 0x11f2f167, /* 11f2f167 //C 0f19a   535 jz	m_ret */
0x0000f19b, 0x00000400, /* 00000400 //C 0f19b   537 mov	r0,r4 */
0x0000f19c, 0x0400f457, /* 0400f457 //C 0f19c   538 call	htoi */
0x0000f19d, 0x00400100, /* 00400100 //C 0f19d   539 mov	r4,r1 */
0x0000f19e, 0x31f2f1a2, /* 31f2f1a2 //C 0f19e   540 C1 jmp	sm_addr_ok */
0x0000f19f, 0x0102f168, /* 0102f168 //C 0f19f   541 mvzl	r0,m_err_addr */
0x0000f1a0, 0x0400f4d4, /* 0400f4d4 //C 0f1a0   542 call	printsnl */
0x0000f1a1, 0x01f2f1b6, /* 01f2f1b6 //C 0f1a1   543 jmp	sm_ret */
0x0000f1a2, 0x025b0000, /* 025b0000 //C 0f1a2   545 sz	r5 */
0x0000f1a3, 0x11f2f1b6, /* 11f2f1b6 //C 0f1a3   546 jz	sm_ret */
0x0000f1a4, 0x0132f000, /* 0132f000 //C 0f1a4   548 mvzl	r3,the_begin */
0x0000f1a5, 0x00380400, /* 00380400 //C 0f1a5   549 cmp	r3,r4 */
0x0000f1a6, 0x91f2f1ae, /* 91f2f1ae //C 0f1a6   550 HI jmp	sm_addrv_ok */
0x0000f1a7, 0x0132f8b5, /* 0132f8b5 //C 0f1a7   551 mvzl	r3,the_end */
0x0000f1a8, 0x00380400, /* 00380400 //C 0f1a8   552 cmp	r3,r4 */
0x0000f1a9, 0x91f2f1ab, /* 91f2f1ab //C 0f1a9   553 HI jmp	sm_addrv_nok */
0x0000f1aa, 0x01f2f1ae, /* 01f2f1ae //C 0f1aa   554 jmp	sm_addrv_ok */
0x0000f1ab, 0x0102f176, /* 0102f176 //C 0f1ab   556 mvzl	r0,m_err_addrv */
0x0000f1ac, 0x0400f4d4, /* 0400f4d4 //C 0f1ac   557 call	printsnl */
0x0000f1ad, 0x01f2f1b6, /* 01f2f1b6 //C 0f1ad   558 jmp	sm_ret */
0x0000f1ae, 0x00000500, /* 00000500 //C 0f1ae   560 mov	r0,r5 */
0x0000f1af, 0x0400f457, /* 0400f457 //C 0f1af   561 call	htoi */
0x0000f1b0, 0x00500100, /* 00500100 //C 0f1b0   562 mov	r5,r1 */
0x0000f1b1, 0x31f2f1b5, /* 31f2f1b5 //C 0f1b1   563 C1 jmp	sm_value_ok */
0x0000f1b2, 0x0102f188, /* 0102f188 //C 0f1b2   564 mvzl	r0,m_err_value */
0x0000f1b3, 0x0400f4d4, /* 0400f4d4 //C 0f1b3   565 call	printsnl */
0x0000f1b4, 0x01f2f1b6, /* 01f2f1b6 //C 0f1b4   566 jmp	sm_ret */
0x0000f1b5, 0x0c540000, /* 0c540000 //C 0f1b5   568 st	r5,r4 */
0x0000f1b6, 0x0ffd0000, /* 0ffd0000 //C 0f1b6   571 pop	pc */
0x0000f1b7, 0x0ded0000, /* 0ded0000 //C 0f1b7   577 push	lr */
0x0000f1b8, 0x0122f64b, /* 0122f64b //C 0f1b8   578 mvzl	r2,words */
0x0000f1b9, 0x0e020001, /* 0e020001 //C 0f1b9   579 ld	r0,r2,1		; start address */
0x0000f1ba, 0x0400f457, /* 0400f457 //C 0f1ba   580 call	htoi */
0x0000f1bb, 0x00300100, /* 00300100 //C 0f1bb   581 mov	r3,r1 */
0x0000f1bc, 0x0e020002, /* 0e020002 //C 0f1bc   582 ld	r0,r2,2		; end address */
0x0000f1bd, 0x020b0000, /* 020b0000 //C 0f1bd   583 sz	r0 */
0x0000f1be, 0x21f2f1c2, /* 21f2f1c2 //C 0f1be   584 jnz	d_end_ok */
0x0000f1bf, 0x00400300, /* 00400300 //C 0f1bf   585 mov	r4,r3 */
0x0000f1c0, 0x01440010, /* 01440010 //C 0f1c0   586 add	r4,0x10 */
0x0000f1c1, 0x01f2f1c4, /* 01f2f1c4 //C 0f1c1   587 jmp	d_chk_end */
0x0000f1c2, 0x0400f457, /* 0400f457 //C 0f1c2   589 call	htoi */
0x0000f1c3, 0x00400100, /* 00400100 //C 0f1c3   590 mov	r4,r1 */
0x0000f1c4, 0x00380400, /* 00380400 //C 0f1c4   592 cmp	r3,r4		; check if start>end */
0x0000f1c5, 0x91f2f1d4, /* 91f2f1d4 //C 0f1c5   593 HI jmp d_bad */
0x0000f1c6, 0x00000300, /* 00000300 //C 0f1c6   601 mov	r0,r3		; print address */
0x0000f1c7, 0x01120004, /* 01120004 //C 0f1c7   602 mvzl	r1,4 */
0x0000f1c8, 0x0400f4db, /* 0400f4db //C 0f1c8   603 call	print_vhex */
0x0000f1c9, 0x01020020, /* 01020020 //C 0f1c9   604 mvzl	r0,0x20		; print one space */
0x0000f1ca, 0x0400f494, /* 0400f494 //C 0f1ca   605 call	putchar */
0x0000f1cb, 0x0e030000, /* 0e030000 //C 0f1cb   606 ld	r0,r3		; load data */
0x0000f1cc, 0x01120004, /* 01120004 //C 0f1cc   607 mvzl	r1,4		; print data */
0x0000f1cd, 0x0400f4db, /* 0400f4db //C 0f1cd   608 call	print_vhex */
0x0000f1ce, 0x0102000a, /* 0102000a //C 0f1ce   609 mvzl	r0,LF		; print new line */
0x0000f1cf, 0x0400f494, /* 0400f494 //C 0f1cf   610 call	putchar */
0x0000f1d0, 0x00380400, /* 00380400 //C 0f1d0   611 cmp	r3,r4 */
0x0000f1d1, 0x11f2f1d6, /* 11f2f1d6 //C 0f1d1   612 jz	d_ret */
0x0000f1d2, 0x01340001, /* 01340001 //C 0f1d2   613 add	r3,1 */
0x0000f1d3, 0x01f2f1c6, /* 01f2f1c6 //C 0f1d3   614 jmp	d_cyc */
0x0000f1d4, 0x0102f1d7, /* 0102f1d7 //C 0f1d4   616 mvzl	r0,d_err_bad */
0x0000f1d5, 0x0400f4d4, /* 0400f4d4 //C 0f1d5   617 call	printsnl */
0x0000f1d6, 0x0ffd0000, /* 0ffd0000 //C 0f1d6   619 pop	pc */
0x0000f1d7, 0x00000057, /* 00000057 //C 0f1d7   621 db	87 */
0x0000f1d8, 0x00000072, /* 00000072 //C 0f1d8   621 db	114 */
0x0000f1d9, 0x0000006f, /* 0000006f //C 0f1d9   621 db	111 */
0x0000f1da, 0x0000006e, /* 0000006e //C 0f1da   621 db	110 */
0x0000f1db, 0x00000067, /* 00000067 //C 0f1db   621 db	103 */
0x0000f1dc, 0x00000020, /* 00000020 //C 0f1dc   621 db	32 */
0x0000f1dd, 0x00000065, /* 00000065 //C 0f1dd   621 db	101 */
0x0000f1de, 0x0000006e, /* 0000006e //C 0f1de   621 db	110 */
0x0000f1df, 0x00000064, /* 00000064 //C 0f1df   621 db	100 */
0x0000f1e0, 0x00000020, /* 00000020 //C 0f1e0   621 db	32 */
0x0000f1e1, 0x00000061, /* 00000061 //C 0f1e1   621 db	97 */
0x0000f1e2, 0x00000064, /* 00000064 //C 0f1e2   621 db	100 */
0x0000f1e3, 0x00000064, /* 00000064 //C 0f1e3   621 db	100 */
0x0000f1e4, 0x00000072, /* 00000072 //C 0f1e4   621 db	114 */
0x0000f1e5, 0x00000065, /* 00000065 //C 0f1e5   621 db	101 */
0x0000f1e6, 0x00000073, /* 00000073 //C 0f1e6   621 db	115 */
0x0000f1e7, 0x00000073, /* 00000073 //C 0f1e7   621 db	115 */
0x0000f1e8, 0x00000000, /* 00000000 //C 0f1e8   621 db */
0x0000f1e9, 0x00f00e00, /* 00f00e00 //C 0f1e9   626 ret */
0x0000f1ea, 0x0ded0000, /* 0ded0000 //C 0f1ea   631 push	lr */
0x0000f1eb, 0x01a20000, /* 01a20000 //C 0f1eb   632 mvzl	r10,0		; state (nr of words) */
0x0000f1ec, 0x01820000, /* 01820000 //C 0f1ec   633 mvzl	r8,0		; value */
0x0000f1ed, 0x0162003f, /* 0162003f //C 0f1ed   634 mvzl	r6,'?'		; Record type */
0x0000f1ee, 0x01c20000, /* 01c20000 //C 0f1ee   635 mvzl	r12,0		; Checksum */
0x0000f1ef, 0x0400f485, /* 0400f485 //C 0f1ef   637 call	check_uart */
0x0000f1f0, 0x41f2f1ef, /* 41f2f1ef //C 0f1f0   638 C0 jmp	l_cyc */
0x0000f1f1, 0x0400f48d, /* 0400f48d //C 0f1f1   639 call	read */
0x0000f1f2, 0x00b00000, /* 00b00000 //C 0f1f2   641 mov	r11,r0		; Copy of char in R11 */
0x0000f1f3, 0x0108000a, /* 0108000a //C 0f1f3   642 cmp	r0,10		; check EOL chars */
0x0000f1f4, 0x11f2f240, /* 11f2f240 //C 0f1f4   643 jz	l_eol */
0x0000f1f5, 0x0108000d, /* 0108000d //C 0f1f5   644 cmp	r0,13 */
0x0000f1f6, 0x11f2f240, /* 11f2f240 //C 0f1f6   645 jz	l_eol */
0x0000f1f7, 0x01a80000, /* 01a80000 //C 0f1f7   647 cmp	r10,0 */
0x0000f1f8, 0x21f2f208, /* 21f2f208 //C 0f1f8   648 jnz	l_no0 */
0x0000f1f9, 0x0400f424, /* 0400f424 //C 0f1f9   650 call	hexchar2value */
0x0000f1fa, 0x41f2f202, /* 41f2f202 //C 0f1fa   651 C0 jmp	l_eof_0 */
0x0000f1fb, 0x02880000, /* 02880000 //C 0f1fb   652 shl	r8		; shift val(char) into value */
0x0000f1fc, 0x02880000, /* 02880000 //C 0f1fc   653 shl	r8 */
0x0000f1fd, 0x02880000, /* 02880000 //C 0f1fd   654 shl	r8 */
0x0000f1fe, 0x02880000, /* 02880000 //C 0f1fe   655 shl	r8 */
0x0000f1ff, 0x010b000f, /* 010b000f //C 0f1ff   656 btst	r0,0xf */
0x0000f200, 0x008d0000, /* 008d0000 //C 0f200   657 or	r8,r0 */
0x0000f201, 0x01f2f1ef, /* 01f2f1ef //C 0f201   658 jmp	l_cyc */
0x0000f202, 0x01a20001, /* 01a20001 //C 0f202   660 mvzl	r10,1		; state0 -> state1 */
0x0000f203, 0x0162003f, /* 0162003f //C 0f203   661 mvzl	r6,'?'		; No //C yet */
0x0000f204, 0x01b8002f, /* 01b8002f //C 0f204   662 cmp	r11,'/'		; is it start of // */
0x0000f205, 0x11720001, /* 11720001 //C 0f205   663 z1 mvzl	r7,1		; Yes, first / found */
0x0000f206, 0x21720000, /* 21720000 //C 0f206   664 z0 mvzl	r7,0		; No '/' yet */
0x0000f207, 0x01f2f1ef, /* 01f2f1ef //C 0f207   665 jmp	l_cyc */
0x0000f208, 0x01a80001, /* 01a80001 //C 0f208   668 cmp	r10,1 */
0x0000f209, 0x21f2f223, /* 21f2f223 //C 0f209   669 jnz	l_no1 */
0x0000f20a, 0x027b0000, /* 027b0000 //C 0f20a   671 sz	r7 */
0x0000f20b, 0x21f2f210, /* 21f2f210 //C 0f20b   672 jnz	l_s1_2nd */
0x0000f20c, 0x0108002f, /* 0108002f //C 0f20c   674 cmp	r0,'/' */
0x0000f20d, 0x21f2f1ef, /* 21f2f1ef //C 0f20d   675 jnz	l_cyc */
0x0000f20e, 0x01720001, /* 01720001 //C 0f20e   676 mvzl	r7,1 */
0x0000f20f, 0x01f2f1ef, /* 01f2f1ef //C 0f20f   677 jmp	l_cyc */
0x0000f210, 0x0108002f, /* 0108002f //C 0f210   679 cmp	r0,'/' */
0x0000f211, 0x11f2f1ef, /* 11f2f1ef //C 0f211   680 jz	l_cyc */
0x0000f212, 0x01080043, /* 01080043 //C 0f212   681 cmp	r0,'C' */
0x0000f213, 0x11f2f216, /* 11f2f216 //C 0f213   682 jz	l_s1_C */
0x0000f214, 0x01080049, /* 01080049 //C 0f214   683 cmp	r0,'I' */
0x0000f215, 0x21f2f21b, /* 21f2f21b //C 0f215   684 jnz	l_s1_noC */
0x0000f216, 0x00600000, /* 00600000 //C 0f216   687 mov	r6,r0		; record type is in r0, store in r6 */
0x0000f217, 0x01a20002, /* 01a20002 //C 0f217   689 mvzl	r10,2 */
0x0000f218, 0x01920000, /* 01920000 //C 0f218   690 mvzl	r9,0		; address= 0 */
0x0000f219, 0x01520000, /* 01520000 //C 0f219   691 mvzl	r5,0		; where we are in word: before */
0x0000f21a, 0x01f2f1ef, /* 01f2f1ef //C 0f21a   692 jmp	l_cyc */
0x0000f21b, 0x01080045, /* 01080045 //C 0f21b   694 cmp	r0,'E' */
0x0000f21c, 0x21f2f220, /* 21f2f220 //C 0f21c   695 jnz	l_s1_noE */
0x0000f21d, 0x01620045, /* 01620045 //C 0f21d   697 mvzl	r6,'E' */
0x0000f21e, 0x01a20003, /* 01a20003 //C 0f21e   699 mvzl	r10,3 */
0x0000f21f, 0x01f2f1ef, /* 01f2f1ef //C 0f21f   700 jmp	l_cyc */
0x0000f220, 0x0400f494, /* 0400f494 //C 0f220   704 call	putchar		; print record type */
0x0000f221, 0x01a2000f, /* 01a2000f //C 0f221   705 mvzl	r10,0xf		; special state: skip everything */
0x0000f222, 0x01f2f1ef, /* 01f2f1ef //C 0f222   706 jmp	l_cyc */
0x0000f223, 0x01a80002, /* 01a80002 //C 0f223   709 cmp	r10,2 */
0x0000f224, 0x21f2f238, /* 21f2f238 //C 0f224   710 jnz	l_no2 */
0x0000f225, 0x01580000, /* 01580000 //C 0f225   712 cmp	r5,0 */
0x0000f226, 0x21f2f231, /* 21f2f231 //C 0f226   713 jnz	l_s2_no0 */
0x0000f227, 0x0400f424, /* 0400f424 //C 0f227   715 call	hexchar2value */
0x0000f228, 0x41f2f1ef, /* 41f2f1ef //C 0f228   716 C0 jmp	l_cyc */
0x0000f229, 0x01520001, /* 01520001 //C 0f229   717 mvzl	r5,1 */
0x0000f22a, 0x02980000, /* 02980000 //C 0f22a   719 shl	r9 */
0x0000f22b, 0x02980000, /* 02980000 //C 0f22b   720 shl	r9 */
0x0000f22c, 0x02980000, /* 02980000 //C 0f22c   721 shl	r9 */
0x0000f22d, 0x02980000, /* 02980000 //C 0f22d   722 shl	r9 */
0x0000f22e, 0x010b000f, /* 010b000f //C 0f22e   723 btst	r0,0xf */
0x0000f22f, 0x009d0000, /* 009d0000 //C 0f22f   724 or	r9,r0 */
0x0000f230, 0x01f2f1ef, /* 01f2f1ef //C 0f230   726 jmp	l_cyc */
0x0000f231, 0x01580001, /* 01580001 //C 0f231   728 cmp	r5,1 */
0x0000f232, 0x21f2f237, /* 21f2f237 //C 0f232   729 jnz	l_s2_no1 */
0x0000f233, 0x0400f424, /* 0400f424 //C 0f233   731 call	hexchar2value */
0x0000f234, 0x31f2f22a, /* 31f2f22a //C 0f234   732 C1 jmp	l_s2_got */
0x0000f235, 0x01520002, /* 01520002 //C 0f235   733 mvzl	r5,2 */
0x0000f236, 0x01f2f1ef, /* 01f2f1ef //C 0f236   734 jmp	l_cyc */
0x0000f237, 0x01f2f1ef, /* 01f2f1ef //C 0f237   736 jmp	l_cyc */
0x0000f238, 0x01a80003, /* 01a80003 //C 0f238   738 cmp	r10,3 */
0x0000f239, 0x21f2f23b, /* 21f2f23b //C 0f239   739 jnz	l_no3 */
0x0000f23a, 0x01f2f1ef, /* 01f2f1ef //C 0f23a   741 jmp	l_cyc		; do nothing, just wait EOL */
0x0000f23b, 0x01a8000f, /* 01a8000f //C 0f23b   744 cmp	r10,0xf */
0x0000f23c, 0x01f2f23e, /* 01f2f23e //C 0f23c   745 jmp	l_nof */
0x0000f23d, 0x01f2f1ef, /* 01f2f1ef //C 0f23d   746 jmp	l_cyc		; just skip */
0x0000f23e, 0x01f2f1ef, /* 01f2f1ef //C 0f23e   749 jmp	l_cyc */
0x0000f23f, 0x01f2f258, /* 01f2f258 //C 0f23f   750 jmp	l_ret */
0x0000f240, 0x01a80000, /* 01a80000 //C 0f240   754 cmp	r10,0		; in state0 */
0x0000f241, 0x11f2f254, /* 11f2f254 //C 0f241   755 jz	l_back_to_0	; just restart */
0x0000f242, 0x01a80001, /* 01a80001 //C 0f242   756 cmp	r10,1		; in state1 */
0x0000f243, 0x11f2f254, /* 11f2f254 //C 0f243   757 jz	l_back_to_0 	;l_cyc ;l_bad ; garbage */
0x0000f244, 0x01a80002, /* 01a80002 //C 0f244   758 cmp	r10,2		; in state2 */
0x0000f245, 0x11f2f24c, /* 11f2f24c //C 0f245   759 jz	l_proc		; process record */
0x0000f246, 0x01a80003, /* 01a80003 //C 0f246   760 cmp	r10,3		; in state3 */
0x0000f247, 0x11f2f258, /* 11f2f258 //C 0f247   761 jz	l_ret		; eol in end record: finish */
0x0000f248, 0x01a8000f, /* 01a8000f //C 0f248   762 cmp	r10,0xf		; in state skip */
0x0000f249, 0x11f2f254, /* 11f2f254 //C 0f249   763 jz	l_back_to_0	; reset state for new line */
0x0000f24a, 0x01f2f1ef, /* 01f2f1ef //C 0f24a   764 jmp	l_cyc */
0x0000f24b, 0x01f2f258, /* 01f2f258 //C 0f24b   766 jmp	l_ret */
0x0000f24c, 0x01680043, /* 01680043 //C 0f24c   768 cmp	r6,'C'		; is it a C or I record? */
0x0000f24d, 0x1c890000, /* 1c890000 //C 0f24d   769 z st	r8,r9		; then store */
0x0000f24e, 0x10c40800, /* 10c40800 //C 0f24e   770 z add	r12,r8		; and add to checksum */
0x0000f24f, 0x01680049, /* 01680049 //C 0f24f   771 cmp	r6,'I' */
0x0000f250, 0x1c890000, /* 1c890000 //C 0f250   772 z st	r8,r9 */
0x0000f251, 0x10c40800, /* 10c40800 //C 0f251   773 z add	r12,r8 */
0x0000f252, 0x00000600, /* 00000600 //C 0f252   774 mov	r0,r6		; echo record type */
0x0000f253, 0x0400f494, /* 0400f494 //C 0f253   775 call	putchar */
0x0000f254, 0x01a20000, /* 01a20000 //C 0f254   780 mvzl	r10,0 */
0x0000f255, 0x01820000, /* 01820000 //C 0f255   781 mvzl	r8,0 */
0x0000f256, 0x0162003f, /* 0162003f //C 0f256   782 mvzl	r6,'?' */
0x0000f257, 0x01f2f1ef, /* 01f2f1ef //C 0f257   783 jmp	l_cyc */
0x0000f258, 0x0102000a, /* 0102000a //C 0f258   785 mvzl	r0,LF */
0x0000f259, 0x0400f494, /* 0400f494 //C 0f259   786 call	putchar */
0x0000f25a, 0x00000c00, /* 00000c00 //C 0f25a   788 mov	r0,r12 */
0x0000f25b, 0x01120004, /* 01120004 //C 0f25b   789 mvzl	r1,4 */
0x0000f25c, 0x0400f4db, /* 0400f4db //C 0f25c   790 call	print_vhex */
0x0000f25d, 0x0102000a, /* 0102000a //C 0f25d   791 mvzl	r0,LF */
0x0000f25e, 0x0400f494, /* 0400f494 //C 0f25e   792 call	putchar */
0x0000f25f, 0x0ffd0000, /* 0ffd0000 //C 0f25f   793 pop	pc */
0x0000f260, 0x0ded0000, /* 0ded0000 //C 0f260   799 push	lr */
0x0000f261, 0x0122f64b, /* 0122f64b //C 0f261   800 mvzl	r2,words */
0x0000f262, 0x0e020001, /* 0e020001 //C 0f262   801 ld	r0,r2,1		; address */
0x0000f263, 0x020b0000, /* 020b0000 //C 0f263   802 sz	r0 */
0x0000f264, 0x11f2f287, /* 11f2f287 //C 0f264   803 jz	g_no_addr */
0x0000f265, 0x0400f457, /* 0400f457 //C 0f265   804 call	htoi */
0x0000f266, 0x00b00100, /* 00b00100 //C 0f266   805 mov	r11,r1 */
0x0000f267, 0x0102f29a, /* 0102f29a //C 0f267   807 mvzl	r0,d_msg_run */
0x0000f268, 0x0400f49b, /* 0400f49b //C 0f268   808 call	prints */
0x0000f269, 0x00000b00, /* 00000b00 //C 0f269   809 mov	r0,r11 */
0x0000f26a, 0x01120004, /* 01120004 //C 0f26a   810 mvzl	r1,4 */
0x0000f26b, 0x0400f4db, /* 0400f4db //C 0f26b   811 call	print_vhex */
0x0000f26c, 0x0102000a, /* 0102000a //C 0f26c   812 mvzl	r0,LF */
0x0000f26d, 0x0400f494, /* 0400f494 //C 0f26d   813 call	putchar */
0x0000f26e, 0x06b0f662, /* 06b0f662 //C 0f26e   814 st	r11,reg15 */
0x0000f26f, 0x0122ff43, /* 0122ff43 //C 0f26f   816 mvzl	r2,UART_TSTAT */
0x0000f270, 0x0e920000, /* 0e920000 //C 0f270   818 ld	r9,r2 */
0x0000f271, 0x019c0001, /* 019c0001 //C 0f271   819 test	r9,1 */
0x0000f272, 0x11f2f270, /* 11f2f270 //C 0f272   820 jz	g_wait_tc */
0x0000f273, 0x07000000, /* 07000000 //C 0f273   822 ld	r0,0 */
0x0000f274, 0x0600f651, /* 0600f651 //C 0f274   823 st	r0,called */
0x0000f275, 0x0700f663, /* 0700f663 //C 0f275   825 ld	r0,regf */
0x0000f276, 0x020f0000, /* 020f0000 //C 0f276   826 setf	r0 */
0x0000f277, 0x0700f653, /* 0700f653 //C 0f277   827 ld	r0,reg0 */
0x0000f278, 0x0710f654, /* 0710f654 //C 0f278   828 ld	r1,reg1 */
0x0000f279, 0x0720f655, /* 0720f655 //C 0f279   829 ld	r2,reg2 */
0x0000f27a, 0x0730f656, /* 0730f656 //C 0f27a   830 ld	r3,reg3 */
0x0000f27b, 0x0740f657, /* 0740f657 //C 0f27b   831 ld	r4,reg4 */
0x0000f27c, 0x0750f658, /* 0750f658 //C 0f27c   832 ld	r5,reg5 */
0x0000f27d, 0x0760f659, /* 0760f659 //C 0f27d   833 ld	r6,reg6 */
0x0000f27e, 0x0770f65a, /* 0770f65a //C 0f27e   834 ld	r7,reg7 */
0x0000f27f, 0x0780f65b, /* 0780f65b //C 0f27f   835 ld	r8,reg8 */
0x0000f280, 0x0790f65c, /* 0790f65c //C 0f280   836 ld	r9,reg9 */
0x0000f281, 0x07a0f65d, /* 07a0f65d //C 0f281   837 ld	r10,reg10 */
0x0000f282, 0x07b0f65e, /* 07b0f65e //C 0f282   838 ld	r11,reg11 */
0x0000f283, 0x07c0f65f, /* 07c0f65f //C 0f283   839 ld	r12,reg12 */
0x0000f284, 0x07d0f660, /* 07d0f660 //C 0f284   840 ld	r13,reg13 */
0x0000f285, 0x07e0f661, /* 07e0f661 //C 0f285   841 ld	r14,reg14 */
0x0000f286, 0x07f0f662, /* 07f0f662 //C 0f286   843 ld	r15,reg15 */
0x0000f287, 0x0700f651, /* 0700f651 //C 0f287   846 ld	r0,called */
0x0000f288, 0x020b0000, /* 020b0000 //C 0f288   847 sz	r0 */
0x0000f289, 0x11f2f28c, /* 11f2f28c //C 0f289   848 jz	g_err */
0x0000f28a, 0x07b0f662, /* 07b0f662 //C 0f28a   849 ld	r11,reg15 */
0x0000f28b, 0x01f2f267, /* 01f2f267 //C 0f28b   850 jmp	g_go11 */
0x0000f28c, 0x0102f28f, /* 0102f28f //C 0f28c   852 mvzl	r0,g_err_addr */
0x0000f28d, 0x0400f4d4, /* 0400f4d4 //C 0f28d   853 call	printsnl */
0x0000f28e, 0x0ffd0000, /* 0ffd0000 //C 0f28e   855 pop	pc */
0x0000f28f, 0x0000004e, /* 0000004e //C 0f28f   857 db	78 */
0x0000f290, 0x0000006f, /* 0000006f //C 0f290   857 db	111 */
0x0000f291, 0x00000020, /* 00000020 //C 0f291   857 db	32 */
0x0000f292, 0x00000061, /* 00000061 //C 0f292   857 db	97 */
0x0000f293, 0x00000064, /* 00000064 //C 0f293   857 db	100 */
0x0000f294, 0x00000064, /* 00000064 //C 0f294   857 db	100 */
0x0000f295, 0x00000072, /* 00000072 //C 0f295   857 db	114 */
0x0000f296, 0x00000065, /* 00000065 //C 0f296   857 db	101 */
0x0000f297, 0x00000073, /* 00000073 //C 0f297   857 db	115 */
0x0000f298, 0x00000073, /* 00000073 //C 0f298   857 db	115 */
0x0000f299, 0x00000000, /* 00000000 //C 0f299   857 db */
0x0000f29a, 0x00000052, /* 00000052 //C 0f29a   858 db	82 */
0x0000f29b, 0x00000075, /* 00000075 //C 0f29b   858 db	117 */
0x0000f29c, 0x0000006e, /* 0000006e //C 0f29c   858 db	110 */
0x0000f29d, 0x00000020, /* 00000020 //C 0f29d   858 db	32 */
0x0000f29e, 0x00000000, /* 00000000 //C 0f29e   858 db */
0x0000f29f, 0x0ded0000, /* 0ded0000 //C 0f29f   863 push	lr */
0x0000f2a0, 0x0122f704, /* 0122f704 //C 0f2a0   864 mvzl	r2,helps */
0x0000f2a1, 0x01320000, /* 01320000 //C 0f2a1   865 mvzl	r3,0 */
0x0000f2a2, 0x0b038200, /* 0b038200 //C 0f2a2   867 ld	r0,r3+,r2	; pick a char */
0x0000f2a3, 0x020b0000, /* 020b0000 //C 0f2a3   868 sz	r0		; is it eos? */
0x0000f2a4, 0x21f2f2a8, /* 21f2f2a8 //C 0f2a4   869 jnz	h_print */
0x0000f2a5, 0x0b038200, /* 0b038200 //C 0f2a5   872 ld	r0,r3+,r2	; get first char of next string */
0x0000f2a6, 0x020b0000, /* 020b0000 //C 0f2a6   873 sz	r0 */
0x0000f2a7, 0x11f2f2aa, /* 11f2f2aa //C 0f2a7   874 jz	h_eof */
0x0000f2a8, 0x0400f494, /* 0400f494 //C 0f2a8   876 call	putchar */
0x0000f2a9, 0x01f2f2a2, /* 01f2f2a2 //C 0f2a9   877 jmp	h_cyc */
0x0000f2aa, 0x0ffd0000, /* 0ffd0000 //C 0f2aa   879 pop	pc */
0x0000f2ab, 0x0ded0000, /* 0ded0000 //C 0f2ab   885 push	lr */
0x0000f2ac, 0x0d1d0000, /* 0d1d0000 //C 0f2ac   886 push	r1 */
0x0000f2ad, 0x00100000, /* 00100000 //C 0f2ad   887 mov	r1,r0 */
0x0000f2ae, 0x01180010, /* 01180010 //C 0f2ae   888 cmp	r1,16		; go out if nr>16 */
0x0000f2af, 0x91f2f2e3, /* 91f2f2e3 //C 0f2af   889 HI jmp	prn_ret */
0x0000f2b0, 0x0118000f, /* 0118000f //C 0f2b0   890 cmp	r1,15		; nr=Flag? */
0x0000f2b1, 0xa1f2f2b8, /* a1f2f2b8 //C 0f2b1   891 LS jmp	prn_015 */
0x0000f2b2, 0x01020046, /* 01020046 //C 0f2b2   893 mvzl	r0,'F' */
0x0000f2b3, 0x0400f494, /* 0400f494 //C 0f2b3   894 call	putchar */
0x0000f2b4, 0x01020020, /* 01020020 //C 0f2b4   895 mvzl	r0,32 */
0x0000f2b5, 0x0400f494, /* 0400f494 //C 0f2b5   896 call	putchar */
0x0000f2b6, 0x0400f494, /* 0400f494 //C 0f2b6   897 call	putchar */
0x0000f2b7, 0x01f2f2e3, /* 01f2f2e3 //C 0f2b7   898 jmp	prn_ret */
0x0000f2b8, 0x0118000f, /* 0118000f //C 0f2b8   900 cmp	r1,15 */
0x0000f2b9, 0x21f2f2c1, /* 21f2f2c1 //C 0f2b9   901 jnz	prn_no15 */
0x0000f2ba, 0x0102f2bd, /* 0102f2bd //C 0f2ba   902 mvzl	r0,prn_PC */
0x0000f2bb, 0x0400f49b, /* 0400f49b //C 0f2bb   903 call	prints */
0x0000f2bc, 0x01f2f2e3, /* 01f2f2e3 //C 0f2bc   904 jmp	prn_ret */
0x0000f2bd, 0x00000050, /* 00000050 //C 0f2bd   905 db	80 */
0x0000f2be, 0x00000043, /* 00000043 //C 0f2be   905 db	67 */
0x0000f2bf, 0x00000020, /* 00000020 //C 0f2bf   905 db	32 */
0x0000f2c0, 0x00000000, /* 00000000 //C 0f2c0   905 db */
0x0000f2c1, 0x0118000e, /* 0118000e //C 0f2c1   907 cmp	r1,14 */
0x0000f2c2, 0x21f2f2ca, /* 21f2f2ca //C 0f2c2   908 jnz	prn_no14 */
0x0000f2c3, 0x0102f2c6, /* 0102f2c6 //C 0f2c3   909 mvzl	r0,prn_LR */
0x0000f2c4, 0x0400f49b, /* 0400f49b //C 0f2c4   910 call	prints */
0x0000f2c5, 0x01f2f2e3, /* 01f2f2e3 //C 0f2c5   911 jmp	prn_ret */
0x0000f2c6, 0x0000004c, /* 0000004c //C 0f2c6   912 db	76 */
0x0000f2c7, 0x00000052, /* 00000052 //C 0f2c7   912 db	82 */
0x0000f2c8, 0x00000020, /* 00000020 //C 0f2c8   912 db	32 */
0x0000f2c9, 0x00000000, /* 00000000 //C 0f2c9   912 db */
0x0000f2ca, 0x0118000d, /* 0118000d //C 0f2ca   914 cmp	r1,13 */
0x0000f2cb, 0x21f2f2d3, /* 21f2f2d3 //C 0f2cb   915 jnz	prn_no13 */
0x0000f2cc, 0x0102f2cf, /* 0102f2cf //C 0f2cc   916 mvzl	r0,prn_SP */
0x0000f2cd, 0x0400f49b, /* 0400f49b //C 0f2cd   917 call	prints */
0x0000f2ce, 0x01f2f2e3, /* 01f2f2e3 //C 0f2ce   918 jmp	prn_ret */
0x0000f2cf, 0x00000053, /* 00000053 //C 0f2cf   919 db	83 */
0x0000f2d0, 0x00000050, /* 00000050 //C 0f2d0   919 db	80 */
0x0000f2d1, 0x00000020, /* 00000020 //C 0f2d1   919 db	32 */
0x0000f2d2, 0x00000000, /* 00000000 //C 0f2d2   919 db */
0x0000f2d3, 0x01020052, /* 01020052 //C 0f2d3   921 mvzl	r0,'R' */
0x0000f2d4, 0x0400f494, /* 0400f494 //C 0f2d4   922 call	putchar */
0x0000f2d5, 0x01180009, /* 01180009 //C 0f2d5   923 cmp	r1,9 */
0x0000f2d6, 0x91f2f2dd, /* 91f2f2dd //C 0f2d6   924 HI jmp	prn_1015 */
0x0000f2d7, 0x00000100, /* 00000100 //C 0f2d7   926 mov	r0,r1 */
0x0000f2d8, 0x01040030, /* 01040030 //C 0f2d8   927 add	r0,'0' */
0x0000f2d9, 0x0400f494, /* 0400f494 //C 0f2d9   928 call	putchar */
0x0000f2da, 0x01020020, /* 01020020 //C 0f2da   929 mvzl	r0,32 */
0x0000f2db, 0x0400f494, /* 0400f494 //C 0f2db   930 call	putchar */
0x0000f2dc, 0x01f2f2e3, /* 01f2f2e3 //C 0f2dc   931 jmp	prn_ret */
0x0000f2dd, 0x01020031, /* 01020031 //C 0f2dd   933 mvzl	r0,'1' */
0x0000f2de, 0x0400f494, /* 0400f494 //C 0f2de   934 call	putchar */
0x0000f2df, 0x00000100, /* 00000100 //C 0f2df   935 mov	r0,r1 */
0x0000f2e0, 0x0106000a, /* 0106000a //C 0f2e0   936 sub	r0,10 */
0x0000f2e1, 0x01040030, /* 01040030 //C 0f2e1   937 add	r0,'0' */
0x0000f2e2, 0x0400f494, /* 0400f494 //C 0f2e2   938 call	putchar */
0x0000f2e3, 0x0f1d0000, /* 0f1d0000 //C 0f2e3   940 pop	r1 */
0x0000f2e4, 0x0ffd0000, /* 0ffd0000 //C 0f2e4   941 pop	pc */
0x0000f2e5, 0x0ded0000, /* 0ded0000 //C 0f2e5   946 push	lr */
0x0000f2e6, 0x0d1d0000, /* 0d1d0000 //C 0f2e6   947 push	r1 */
0x0000f2e7, 0x01080010, /* 01080010 //C 0f2e7   948 cmp	r0,16 */
0x0000f2e8, 0x91f2f2ed, /* 91f2f2ed //C 0f2e8   949 HI jmp	prv_ret */
0x0000f2e9, 0x0112f653, /* 0112f653 //C 0f2e9   950 mvzl	r1,reg0 */
0x0000f2ea, 0x0a010000, /* 0a010000 //C 0f2ea   951 ld	r0,r1,r0 */
0x0000f2eb, 0x01120004, /* 01120004 //C 0f2eb   952 mvzl	r1,4 */
0x0000f2ec, 0x0400f4db, /* 0400f4db //C 0f2ec   953 call	print_vhex */
0x0000f2ed, 0x0f1d0000, /* 0f1d0000 //C 0f2ed   955 pop	r1 */
0x0000f2ee, 0x0ffd0000, /* 0ffd0000 //C 0f2ee   956 pop	pc */
0x0000f2ef, 0x0ded0000, /* 0ded0000 //C 0f2ef   963 push	lr */
0x0000f2f0, 0x0dad0000, /* 0dad0000 //C 0f2f0   964 push	r10 */
0x0000f2f1, 0x0d0d0000, /* 0d0d0000 //C 0f2f1   965 push	r0 */
0x0000f2f2, 0x00000a00, /* 00000a00 //C 0f2f2   966 mov	r0,r10 */
0x0000f2f3, 0x0400f2ab, /* 0400f2ab //C 0f2f3   967 call	print_reg_name */
0x0000f2f4, 0x01020020, /* 01020020 //C 0f2f4   968 mvzl	r0,32 */
0x0000f2f5, 0x0400f494, /* 0400f494 //C 0f2f5   969 call	putchar */
0x0000f2f6, 0x00000a00, /* 00000a00 //C 0f2f6   970 mov	r0,r10 */
0x0000f2f7, 0x0400f2e5, /* 0400f2e5 //C 0f2f7   971 call	print_reg_value */
0x0000f2f8, 0x0102000a, /* 0102000a //C 0f2f8   972 mvzl	r0,LF */
0x0000f2f9, 0x0400f494, /* 0400f494 //C 0f2f9   973 call	putchar */
0x0000f2fa, 0x0f0d0000, /* 0f0d0000 //C 0f2fa   974 pop	r0 */
0x0000f2fb, 0x0fad0000, /* 0fad0000 //C 0f2fb   975 pop	r10 */
0x0000f2fc, 0x0ffd0000, /* 0ffd0000 //C 0f2fc   976 pop	pc */
0x0000f2fd, 0x0ded0000, /* 0ded0000 //C 0f2fd   984 push	lr */
0x0000f2fe, 0x0400f494, /* 0400f494 //C 0f2fe   985 call	putchar */
0x0000f2ff, 0x001c0200, /* 001c0200 //C 0f2ff   986 test	r1,r2 */
0x0000f300, 0x21020031, /* 21020031 //C 0f300   987 NZ mvzl r0,'1' */
0x0000f301, 0x11020030, /* 11020030 //C 0f301   988 Z  mvzl r0,'0' */
0x0000f302, 0x0400f494, /* 0400f494 //C 0f302   989 call	putchar */
0x0000f303, 0x00000300, /* 00000300 //C 0f303   990 mov	r0,r3 */
0x0000f304, 0x0400f494, /* 0400f494 //C 0f304   991 call	putchar */
0x0000f305, 0x0ffd0000, /* 0ffd0000 //C 0f305   992 pop	pc */
0x0000f306, 0x0ded0000, /* 0ded0000 //C 0f306   997 push	lr */
0x0000f307, 0x0700f651, /* 0700f651 //C 0f307   998 ld	r0,called */
0x0000f308, 0x020b0000, /* 020b0000 //C 0f308   999 sz	r0 */
0x0000f309, 0x11f2f312, /* 11f2f312 //C 0f309  1000 jz	r_not_called */
0x0000f30a, 0x0102f32f, /* 0102f32f //C 0f30a  1002 mvzl	r0,msg_r_called */
0x0000f30b, 0x0400f49b, /* 0400f49b //C 0f30b  1003 call	prints */
0x0000f30c, 0x0700f662, /* 0700f662 //C 0f30c  1004 ld	r0,reg15 */
0x0000f30d, 0x01120004, /* 01120004 //C 0f30d  1005 mvzl	r1,4 */
0x0000f30e, 0x0400f4db, /* 0400f4db //C 0f30e  1006 call	print_vhex */
0x0000f30f, 0x0102000a, /* 0102000a //C 0f30f  1007 mvzl	r0,LF */
0x0000f310, 0x0400f494, /* 0400f494 //C 0f310  1008 call	putchar */
0x0000f311, 0x01f2f314, /* 01f2f314 //C 0f311  1009 jmp	r_start */
0x0000f312, 0x0102f345, /* 0102f345 //C 0f312  1011 mvzl	r0,msg_r_notcalled */
0x0000f313, 0x0400f49b, /* 0400f49b //C 0f313  1012 call	prints */
0x0000f314, 0x01a20000, /* 01a20000 //C 0f314  1014 mvzl	r10,0 */
0x0000f315, 0x0400f2ef, /* 0400f2ef //C 0f315  1016 call	print_reg_name_value */
0x0000f316, 0x01a40001, /* 01a40001 //C 0f316  1017 add	r10,1 */
0x0000f317, 0x01a80011, /* 01a80011 //C 0f317  1018 cmp	r10,17 */
0x0000f318, 0x21f2f315, /* 21f2f315 //C 0f318  1019 jnz	r_cyc */
0x0000f319, 0x0710f663, /* 0710f663 //C 0f319  1021 ld	r1,regf */
0x0000f31a, 0x01320020, /* 01320020 //C 0f31a  1022 mvzl	r3,32 */
0x0000f31b, 0x01020055, /* 01020055 //C 0f31b  1023 mvzl	r0,'U' */
0x0000f31c, 0x01220020, /* 01220020 //C 0f31c  1024 mvzl	r2,0x20 */
0x0000f31d, 0x0400f2fd, /* 0400f2fd //C 0f31d  1025 call	print_flag */
0x0000f31e, 0x01020050, /* 01020050 //C 0f31e  1026 mvzl	r0,'P' */
0x0000f31f, 0x01220010, /* 01220010 //C 0f31f  1027 mvzl	r2,0x10 */
0x0000f320, 0x0400f2fd, /* 0400f2fd //C 0f320  1028 call	print_flag */
0x0000f321, 0x0102004f, /* 0102004f //C 0f321  1029 mvzl	r0,'O' */
0x0000f322, 0x01220008, /* 01220008 //C 0f322  1030 mvzl	r2,8 */
0x0000f323, 0x0400f2fd, /* 0400f2fd //C 0f323  1031 call	print_flag */
0x0000f324, 0x0102005a, /* 0102005a //C 0f324  1032 mvzl	r0,'Z' */
0x0000f325, 0x01220004, /* 01220004 //C 0f325  1033 mvzl	r2,4 */
0x0000f326, 0x0400f2fd, /* 0400f2fd //C 0f326  1034 call	print_flag */
0x0000f327, 0x01020043, /* 01020043 //C 0f327  1035 mvzl	r0,'C' */
0x0000f328, 0x01220002, /* 01220002 //C 0f328  1036 mvzl	r2,2 */
0x0000f329, 0x0400f2fd, /* 0400f2fd //C 0f329  1037 call	print_flag */
0x0000f32a, 0x01020053, /* 01020053 //C 0f32a  1038 mvzl	r0,'S' */
0x0000f32b, 0x01220001, /* 01220001 //C 0f32b  1039 mvzl	r2,1 */
0x0000f32c, 0x0132000a, /* 0132000a //C 0f32c  1040 mvzl	r3,LF */
0x0000f32d, 0x0400f2fd, /* 0400f2fd //C 0f32d  1041 call	print_flag */
0x0000f32e, 0x0ffd0000, /* 0ffd0000 //C 0f32e  1042 pop	pc */
0x0000f32f, 0x0000004d, /* 0000004d //C 0f32f  1044 db	77 */
0x0000f330, 0x0000006f, /* 0000006f //C 0f330  1044 db	111 */
0x0000f331, 0x0000006e, /* 0000006e //C 0f331  1044 db	110 */
0x0000f332, 0x00000069, /* 00000069 //C 0f332  1044 db	105 */
0x0000f333, 0x00000074, /* 00000074 //C 0f333  1044 db	116 */
0x0000f334, 0x0000006f, /* 0000006f //C 0f334  1044 db	111 */
0x0000f335, 0x00000072, /* 00000072 //C 0f335  1044 db	114 */
0x0000f336, 0x00000020, /* 00000020 //C 0f336  1044 db	32 */
0x0000f337, 0x00000063, /* 00000063 //C 0f337  1044 db	99 */
0x0000f338, 0x00000061, /* 00000061 //C 0f338  1044 db	97 */
0x0000f339, 0x0000006c, /* 0000006c //C 0f339  1044 db	108 */
0x0000f33a, 0x0000006c, /* 0000006c //C 0f33a  1044 db	108 */
0x0000f33b, 0x00000065, /* 00000065 //C 0f33b  1044 db	101 */
0x0000f33c, 0x00000064, /* 00000064 //C 0f33c  1044 db	100 */
0x0000f33d, 0x00000020, /* 00000020 //C 0f33d  1044 db	32 */
0x0000f33e, 0x00000066, /* 00000066 //C 0f33e  1044 db	102 */
0x0000f33f, 0x00000072, /* 00000072 //C 0f33f  1044 db	114 */
0x0000f340, 0x0000006f, /* 0000006f //C 0f340  1044 db	111 */
0x0000f341, 0x0000006d, /* 0000006d //C 0f341  1044 db	109 */
0x0000f342, 0x0000003a, /* 0000003a //C 0f342  1044 db	58 */
0x0000f343, 0x00000020, /* 00000020 //C 0f343  1044 db	32 */
0x0000f344, 0x00000000, /* 00000000 //C 0f344  1044 db */
0x0000f345, 0x0000004d, /* 0000004d //C 0f345  1045 db	77 */
0x0000f346, 0x0000006f, /* 0000006f //C 0f346  1045 db	111 */
0x0000f347, 0x0000006e, /* 0000006e //C 0f347  1045 db	110 */
0x0000f348, 0x00000069, /* 00000069 //C 0f348  1045 db	105 */
0x0000f349, 0x00000074, /* 00000074 //C 0f349  1045 db	116 */
0x0000f34a, 0x0000006f, /* 0000006f //C 0f34a  1045 db	111 */
0x0000f34b, 0x00000072, /* 00000072 //C 0f34b  1045 db	114 */
0x0000f34c, 0x00000020, /* 00000020 //C 0f34c  1045 db	32 */
0x0000f34d, 0x0000006e, /* 0000006e //C 0f34d  1045 db	110 */
0x0000f34e, 0x0000006f, /* 0000006f //C 0f34e  1045 db	111 */
0x0000f34f, 0x00000074, /* 00000074 //C 0f34f  1045 db	116 */
0x0000f350, 0x00000020, /* 00000020 //C 0f350  1045 db	32 */
0x0000f351, 0x00000063, /* 00000063 //C 0f351  1045 db	99 */
0x0000f352, 0x00000061, /* 00000061 //C 0f352  1045 db	97 */
0x0000f353, 0x0000006c, /* 0000006c //C 0f353  1045 db	108 */
0x0000f354, 0x0000006c, /* 0000006c //C 0f354  1045 db	108 */
0x0000f355, 0x00000065, /* 00000065 //C 0f355  1045 db	101 */
0x0000f356, 0x00000064, /* 00000064 //C 0f356  1045 db	100 */
0x0000f357, 0x00000020, /* 00000020 //C 0f357  1045 db	32 */
0x0000f358, 0x00000062, /* 00000062 //C 0f358  1045 db	98 */
0x0000f359, 0x00000079, /* 00000079 //C 0f359  1045 db	121 */
0x0000f35a, 0x00000020, /* 00000020 //C 0f35a  1045 db	32 */
0x0000f35b, 0x00000075, /* 00000075 //C 0f35b  1045 db	117 */
0x0000f35c, 0x00000073, /* 00000073 //C 0f35c  1045 db	115 */
0x0000f35d, 0x00000065, /* 00000065 //C 0f35d  1045 db	101 */
0x0000f35e, 0x00000072, /* 00000072 //C 0f35e  1045 db	114 */
0x0000f35f, 0x0000000a, /* 0000000a //C 0f35f  1045 db	10 */
0x0000f360, 0x00000000, /* 00000000 //C 0f360  1045 db */
0x0000f361, 0x0ded0000, /* 0ded0000 //C 0f361  1050 push	lr */
0x0000f362, 0x07a0f652, /* 07a0f652 //C 0f362  1051 ld	r10,nuof_reg	; Reg num is in R10 */
0x0000f363, 0x01a80010, /* 01a80010 //C 0f363  1052 cmp	r10,16 */
0x0000f364, 0xa1f2f379, /* a1f2f379 //C 0f364  1053 LS jmp	rx_nr_ok */
0x0000f365, 0x0102f368, /* 0102f368 //C 0f365  1054 mvzl	r0,rx_err_nr */
0x0000f366, 0x0400f4d4, /* 0400f4d4 //C 0f366  1055 call	printsnl */
0x0000f367, 0x01f2f395, /* 01f2f395 //C 0f367  1056 jmp	rx_ret */
0x0000f368, 0x0000004e, /* 0000004e //C 0f368  1058 db	78 */
0x0000f369, 0x0000006f, /* 0000006f //C 0f369  1058 db	111 */
0x0000f36a, 0x00000020, /* 00000020 //C 0f36a  1058 db	32 */
0x0000f36b, 0x00000073, /* 00000073 //C 0f36b  1058 db	115 */
0x0000f36c, 0x00000075, /* 00000075 //C 0f36c  1058 db	117 */
0x0000f36d, 0x00000063, /* 00000063 //C 0f36d  1058 db	99 */
0x0000f36e, 0x00000068, /* 00000068 //C 0f36e  1058 db	104 */
0x0000f36f, 0x00000020, /* 00000020 //C 0f36f  1058 db	32 */
0x0000f370, 0x00000072, /* 00000072 //C 0f370  1058 db	114 */
0x0000f371, 0x00000065, /* 00000065 //C 0f371  1058 db	101 */
0x0000f372, 0x00000067, /* 00000067 //C 0f372  1058 db	103 */
0x0000f373, 0x00000069, /* 00000069 //C 0f373  1058 db	105 */
0x0000f374, 0x00000073, /* 00000073 //C 0f374  1058 db	115 */
0x0000f375, 0x00000074, /* 00000074 //C 0f375  1058 db	116 */
0x0000f376, 0x00000065, /* 00000065 //C 0f376  1058 db	101 */
0x0000f377, 0x00000072, /* 00000072 //C 0f377  1058 db	114 */
0x0000f378, 0x00000000, /* 00000000 //C 0f378  1058 db */
0x0000f379, 0x0122f64b, /* 0122f64b //C 0f379  1060 mvzl	r2,words */
0x0000f37a, 0x0e420001, /* 0e420001 //C 0f37a  1061 ld	r4,r2,1		; get aof first parameter */
0x0000f37b, 0x024b0000, /* 024b0000 //C 0f37b  1062 sz	r4		; is it NULL? */
0x0000f37c, 0x11f2f394, /* 11f2f394 //C 0f37c  1063 jz	rx_print */
0x0000f37d, 0x00000400, /* 00000400 //C 0f37d  1064 mov	r0,r4 */
0x0000f37e, 0x0400f457, /* 0400f457 //C 0f37e  1065 call	htoi */
0x0000f37f, 0x00500100, /* 00500100 //C 0f37f  1066 mov	r5,r1		; Value is in R5 */
0x0000f380, 0x31f2f390, /* 31f2f390 //C 0f380  1067 C1 jmp	rx_val_ok */
0x0000f381, 0x0102f384, /* 0102f384 //C 0f381  1068 mvzl	r0,rx_err_val */
0x0000f382, 0x0400f4d4, /* 0400f4d4 //C 0f382  1069 call	printsnl */
0x0000f383, 0x01f2f395, /* 01f2f395 //C 0f383  1070 jmp	rx_ret */
0x0000f384, 0x00000056, /* 00000056 //C 0f384  1072 db	86 */
0x0000f385, 0x00000061, /* 00000061 //C 0f385  1072 db	97 */
0x0000f386, 0x0000006c, /* 0000006c //C 0f386  1072 db	108 */
0x0000f387, 0x00000075, /* 00000075 //C 0f387  1072 db	117 */
0x0000f388, 0x00000065, /* 00000065 //C 0f388  1072 db	101 */
0x0000f389, 0x00000020, /* 00000020 //C 0f389  1072 db	32 */
0x0000f38a, 0x00000065, /* 00000065 //C 0f38a  1072 db	101 */
0x0000f38b, 0x00000072, /* 00000072 //C 0f38b  1072 db	114 */
0x0000f38c, 0x00000072, /* 00000072 //C 0f38c  1072 db	114 */
0x0000f38d, 0x0000006f, /* 0000006f //C 0f38d  1072 db	111 */
0x0000f38e, 0x00000072, /* 00000072 //C 0f38e  1072 db	114 */
0x0000f38f, 0x00000000, /* 00000000 //C 0f38f  1072 db */
0x0000f390, 0x01a80010, /* 01a80010 //C 0f390  1074 cmp	r10,16		; Flag reg? */
0x0000f391, 0x115f003f, /* 115f003f //C 0f391  1075 EQ and	r5,0x3f */
0x0000f392, 0x0102f653, /* 0102f653 //C 0f392  1076 mvzl	r0,reg0 */
0x0000f393, 0x08500a00, /* 08500a00 //C 0f393  1077 st	r5,r0,r10 */
0x0000f394, 0x0400f2ef, /* 0400f2ef //C 0f394  1079 call	print_reg_name_value */
0x0000f395, 0x0ffd0000, /* 0ffd0000 //C 0f395  1081 pop	pc */
0x0000f396, 0x0102000d, /* 0102000d //C 0f396  1087 mvzl	r0,13 */
0x0000f397, 0x0600f652, /* 0600f652 //C 0f397  1088 st	r0,nuof_reg */
0x0000f398, 0x01f2f361, /* 01f2f361 //C 0f398  1089 jmp	cmd_rx */
0x0000f399, 0x0102000e, /* 0102000e //C 0f399  1094 mvzl	r0,14 */
0x0000f39a, 0x0600f652, /* 0600f652 //C 0f39a  1095 st	r0,nuof_reg */
0x0000f39b, 0x01f2f361, /* 01f2f361 //C 0f39b  1096 jmp	cmd_rx */
0x0000f39c, 0x0102000f, /* 0102000f //C 0f39c  1101 mvzl	r0,15 */
0x0000f39d, 0x0600f652, /* 0600f652 //C 0f39d  1102 st	r0,nuof_reg */
0x0000f39e, 0x01f2f361, /* 01f2f361 //C 0f39e  1103 jmp	cmd_rx */
0x0000f39f, 0x01020010, /* 01020010 //C 0f39f  1108 mvzl	r0,16 */
0x0000f3a0, 0x0600f652, /* 0600f652 //C 0f3a0  1109 st	r0,nuof_reg */
0x0000f3a1, 0x01f2f361, /* 01f2f361 //C 0f3a1  1110 jmp	cmd_rx */
0x0000f3a2, 0x0d3d0000, /* 0d3d0000 //C 0f3a2  1123 push	r3 */
0x0000f3a3, 0x0d4d0000, /* 0d4d0000 //C 0f3a3  1124 push	r4 */
0x0000f3a4, 0x01220000, /* 01220000 //C 0f3a4  1126 mvzl	r2,0		; byte index re-start */
0x0000f3a5, 0x0e310000, /* 0e310000 //C 0f3a5  1127 ld	r3,r1		; get next word */
0x0000f3a6, 0x023b0000, /* 023b0000 //C 0f3a6  1128 sz	r3		; check for eof */
0x0000f3a7, 0x11f2f3b4, /* 11f2f3b4 //C 0f3a7  1129 jz	strchr_no	; eof string found */
0x0000f3a8, 0x06414302, /* 06414302 //C 0f3a8  1131 getbz	r4,r3,r2	; pick a byte */
0x0000f3a9, 0x024b0000, /* 024b0000 //C 0f3a9  1132 sz	r4		; is it zero? */
0x0000f3aa, 0x11f2f3b0, /* 11f2f3b0 //C 0f3aa  1133 jz	strchr_word	; if yes, pick next word */
0x0000f3ab, 0x00480000, /* 00480000 //C 0f3ab  1134 cmp	r4,r0		; compare */
0x0000f3ac, 0x11f2f3b2, /* 11f2f3b2 //C 0f3ac  1135 jz	strchr_yes	; found it */
0x0000f3ad, 0x01240001, /* 01240001 //C 0f3ad  1137 inc	r2		; advance byte index */
0x0000f3ae, 0x01280004, /* 01280004 //C 0f3ae  1138 cmp	r2,4		; check byte overflow */
0x0000f3af, 0x21f2f3a8, /* 21f2f3a8 //C 0f3af  1139 jnz	strchr_go	; no, overflow, go on */
0x0000f3b0, 0x011a0001, /* 011a0001 //C 0f3b0  1141 plus	r1,1		; go to next char */
0x0000f3b1, 0x01f2f3a4, /* 01f2f3a4 //C 0f3b1  1142 jmp	strchr_cyc */
0x0000f3b2, 0x020c0000, /* 020c0000 //C 0f3b2  1144 sec */
0x0000f3b3, 0x01f2f3b6, /* 01f2f3b6 //C 0f3b3  1145 jmp	strchr_ret */
0x0000f3b4, 0x01120000, /* 01120000 //C 0f3b4  1147 mvzl	r1,0 */
0x0000f3b5, 0x020d0000, /* 020d0000 //C 0f3b5  1148 clc */
0x0000f3b6, 0x0f4d0000, /* 0f4d0000 //C 0f3b6  1150 pop	r4 */
0x0000f3b7, 0x0f3d0000, /* 0f3d0000 //C 0f3b7  1151 pop	r3 */
0x0000f3b8, 0x00f00e00, /* 00f00e00 //C 0f3b8  1154 ret */
0x0000f3b9, 0x0ded0000, /* 0ded0000 //C 0f3b9  1165 push	lr		; Save used registers */
0x0000f3ba, 0x0d0d0000, /* 0d0d0000 //C 0f3ba  1166 push	r0		; and input parameters */
0x0000f3bb, 0x0d2d0000, /* 0d2d0000 //C 0f3bb  1168 push	r2 */
0x0000f3bc, 0x0d4d0000, /* 0d4d0000 //C 0f3bc  1169 push	r4 */
0x0000f3bd, 0x0d5d0000, /* 0d5d0000 //C 0f3bd  1170 push	r5 */
0x0000f3be, 0x0d6d0000, /* 0d6d0000 //C 0f3be  1171 push	r6 */
0x0000f3bf, 0x0d7d0000, /* 0d7d0000 //C 0f3bf  1172 push	r7		; byte idx in string 1 */
0x0000f3c0, 0x0d8d0000, /* 0d8d0000 //C 0f3c0  1173 push	r8		; byte idx in string 2 */
0x0000f3c1, 0x01720000, /* 01720000 //C 0f3c1  1174 mvzl	r7,0 */
0x0000f3c2, 0x01820000, /* 01820000 //C 0f3c2  1175 mvzl	r8,0 */
0x0000f3c3, 0x0e200000, /* 0e200000 //C 0f3c3  1177 ld	r2,r0		; Got one char from first str */
0x0000f3c4, 0x022b0000, /* 022b0000 //C 0f3c4  1178 sz	r2		; is it eos? */
0x0000f3c5, 0x11f2f3d4, /* 11f2f3d4 //C 0f3c5  1179 jz	streq_pick2	; if yes, go on */
0x0000f3c6, 0x06214207, /* 06214207 //C 0f3c6  1180 getbz	r2,r2,r7	; pick one byte */
0x0000f3c7, 0x022b0000, /* 022b0000 //C 0f3c7  1181 sz	r2		; is it 0? */
0x0000f3c8, 0x21f2f3d4, /* 21f2f3d4 //C 0f3c8  1182 jnz	streq_pick2	; if not, go on */
0x0000f3c9, 0x01740001, /* 01740001 //C 0f3c9  1183 inc	r7		; step to next byte */
0x0000f3ca, 0x01780004, /* 01780004 //C 0f3ca  1184 cmp	r7,4		; word is overflowed? */
0x0000f3cb, 0x11f2f3d0, /* 11f2f3d0 //C 0f3cb  1185 jz	streq_p1ov */
0x0000f3cc, 0x0e200000, /* 0e200000 //C 0f3cc  1187 ld	r2,r0		; pick orig word, and */
0x0000f3cd, 0x06214207, /* 06214207 //C 0f3cd  1188 getbz	r2,r2,r7	; check next byte */
0x0000f3ce, 0x022b0000, /* 022b0000 //C 0f3ce  1189 sz	r2		; is it 0? */
0x0000f3cf, 0x21f2f3d4, /* 21f2f3d4 //C 0f3cf  1190 jnz	streq_pick2	; if not, go on */
0x0000f3d0, 0x01040001, /* 01040001 //C 0f3d0  1192 inc	r0		; if yes, move pointer */
0x0000f3d1, 0x01720000, /* 01720000 //C 0f3d1  1193 mvzl	r7,0		; and reset byte counter */
0x0000f3d2, 0x0e200000, /* 0e200000 //C 0f3d2  1194 ld	r2,r0		; get first byte of next word */
0x0000f3d3, 0x06214207, /* 06214207 //C 0f3d3  1195 getbz	r2,r2,r7 */
0x0000f3d4, 0x0e610000, /* 0e610000 //C 0f3d4  1198 ld	r6,r1		; pick from second string */
0x0000f3d5, 0x026b0000, /* 026b0000 //C 0f3d5  1199 sz	r6		; is it eos? */
0x0000f3d6, 0x11f2f3e5, /* 11f2f3e5 //C 0f3d6  1200 jz	streq_prep	; if yes, go to compare */
0x0000f3d7, 0x06614608, /* 06614608 //C 0f3d7  1201 getbz	r6,r6,r8	; pick a byte */
0x0000f3d8, 0x026b0000, /* 026b0000 //C 0f3d8  1202 sz	r6		; is it 0? */
0x0000f3d9, 0x21f2f3e5, /* 21f2f3e5 //C 0f3d9  1203 jnz	streq_prep	; if not, go to compare */
0x0000f3da, 0x01840001, /* 01840001 //C 0f3da  1204 inc	r8		; step to next byte */
0x0000f3db, 0x01880004, /* 01880004 //C 0f3db  1205 cmp	r8,4		; is word overflowed? */
0x0000f3dc, 0x11f2f3e1, /* 11f2f3e1 //C 0f3dc  1206 jz	streq_p2ov */
0x0000f3dd, 0x0e610000, /* 0e610000 //C 0f3dd  1208 ld	r6,r1		; pick orig word, and */
0x0000f3de, 0x06614608, /* 06614608 //C 0f3de  1209 getbz	r6,r6,r8	; check next byte */
0x0000f3df, 0x026b0000, /* 026b0000 //C 0f3df  1210 sz	r6		; is it 0? */
0x0000f3e0, 0x21f2f3e5, /* 21f2f3e5 //C 0f3e0  1211 jnz	streq_prep	; if not, go on */
0x0000f3e1, 0x01140001, /* 01140001 //C 0f3e1  1213 inc	r1		; if yes, move pointer */
0x0000f3e2, 0x01820000, /* 01820000 //C 0f3e2  1214 mvzl	r8,0		; and reset byte counter */
0x0000f3e3, 0x0e610000, /* 0e610000 //C 0f3e3  1215 ld	r6,r1		; get next word */
0x0000f3e4, 0x06614608, /* 06614608 //C 0f3e4  1216 getbz	r6,r6,r8	; and pick first byte */
0x0000f3e5, 0x023b0000, /* 023b0000 //C 0f3e5  1219 sz	r3		; Prepare for comparing */
0x0000f3e6, 0x112d0020, /* 112d0020 //C 0f3e6  1220 Z1 or	r2,0x20		; if insensitive case */
0x0000f3e7, 0x023b0000, /* 023b0000 //C 0f3e7  1221 sz	r3 */
0x0000f3e8, 0x116d0020, /* 116d0020 //C 0f3e8  1222 Z1 or	r6,0x20 */
0x0000f3e9, 0x00280600, /* 00280600 //C 0f3e9  1223 cmp	r2,r6		; compare them */
0x0000f3ea, 0x21f2f404, /* 21f2f404 //C 0f3ea  1224 jnz	streq_no	; if differs: strings are not equal */
0x0000f3eb, 0x0e200000, /* 0e200000 //C 0f3eb  1226 ld	r2,r0		; Pick original (non-prepared) */
0x0000f3ec, 0x0e610000, /* 0e610000 //C 0f3ec  1227 ld	r6,r1		; chars to check EOS */
0x0000f3ed, 0x06214207, /* 06214207 //C 0f3ed  1228 getbz	r2,r2,r7 */
0x0000f3ee, 0x06614608, /* 06614608 //C 0f3ee  1229 getbz	r6,r6,r8 */
0x0000f3ef, 0x022b0000, /* 022b0000 //C 0f3ef  1230 sz	r2		; convert them to boolean */
0x0000f3f0, 0x21220001, /* 21220001 //C 0f3f0  1231 Z0 mvzl	r2,1		; values in R2,R6 */
0x0000f3f1, 0x11220000, /* 11220000 //C 0f3f1  1232 Z1 mvzl	r2,0		; and copy in R4,R5 */
0x0000f3f2, 0x00400200, /* 00400200 //C 0f3f2  1233 mov	r4,r2 */
0x0000f3f3, 0x026b0000, /* 026b0000 //C 0f3f3  1234 sz	r6 */
0x0000f3f4, 0x21620001, /* 21620001 //C 0f3f4  1235 Z0 mvzl	r6,1 */
0x0000f3f5, 0x11620000, /* 11620000 //C 0f3f5  1236 Z1 mvzl r6,0 */
0x0000f3f6, 0x00500600, /* 00500600 //C 0f3f6  1237 mov	r5,r6 */
0x0000f3f7, 0x004d0500, /* 004d0500 //C 0f3f7  1238 or	r4,r5		; if both are EOS: equal */
0x0000f3f8, 0x11f2f406, /* 11f2f406 //C 0f3f8  1239 jz	streq_yes */
0x0000f3f9, 0x002f0600, /* 002f0600 //C 0f3f9  1240 and 	r2,r6		; just one is EOS: not equal */
0x0000f3fa, 0x11f2f404, /* 11f2f404 //C 0f3fa  1241 jz	streq_no */
0x0000f3fb, 0x01740001, /* 01740001 //C 0f3fb  1244 inc	r7		; step byte count */
0x0000f3fc, 0x01780004, /* 01780004 //C 0f3fc  1245 cmp	r7,4		; if word overflows */
0x0000f3fd, 0x110a0001, /* 110a0001 //C 0f3fd  1246 Z plus	r0,1		; then step the pointer */
0x0000f3fe, 0x11720000, /* 11720000 //C 0f3fe  1247 Z mvzl	r7,0		; and reset the byte counter */
0x0000f3ff, 0x01840001, /* 01840001 //C 0f3ff  1249 inc	r8 */
0x0000f400, 0x01880004, /* 01880004 //C 0f400  1250 cmp	r8,4 */
0x0000f401, 0x111a0001, /* 111a0001 //C 0f401  1251 Z plus	r1,1 */
0x0000f402, 0x11820000, /* 11820000 //C 0f402  1252 Z mvzl	r8,0 */
0x0000f403, 0x01f2f3c3, /* 01f2f3c3 //C 0f403  1253 jmp	streq_cyc */
0x0000f404, 0x020d0000, /* 020d0000 //C 0f404  1256 clc			; False result */
0x0000f405, 0x01f2f407, /* 01f2f407 //C 0f405  1257 jmp	streq_ret */
0x0000f406, 0x020c0000, /* 020c0000 //C 0f406  1260 sec			; True result */
0x0000f407, 0x0e610000, /* 0e610000 //C 0f407  1263 ld	r6,r1		; forward R1 to EOS */
0x0000f408, 0x026b0000, /* 026b0000 //C 0f408  1264 sz	r6 */
0x0000f409, 0x11f2f40c, /* 11f2f40c //C 0f409  1265 jz	streq_ret_ret */
0x0000f40a, 0x01140001, /* 01140001 //C 0f40a  1266 inc	r1 */
0x0000f40b, 0x01f2f407, /* 01f2f407 //C 0f40b  1267 jmp	streq_ret */
0x0000f40c, 0x0f8d0000, /* 0f8d0000 //C 0f40c  1269 pop	r8 */
0x0000f40d, 0x0f7d0000, /* 0f7d0000 //C 0f40d  1270 pop	r7 */
0x0000f40e, 0x0f6d0000, /* 0f6d0000 //C 0f40e  1271 pop	r6 */
0x0000f40f, 0x0f5d0000, /* 0f5d0000 //C 0f40f  1272 pop	r5 */
0x0000f410, 0x0f4d0000, /* 0f4d0000 //C 0f410  1273 pop	r4 */
0x0000f411, 0x0f2d0000, /* 0f2d0000 //C 0f411  1274 pop	r2 */
0x0000f412, 0x0f0d0000, /* 0f0d0000 //C 0f412  1276 pop	r0 */
0x0000f413, 0x0ffd0000, /* 0ffd0000 //C 0f413  1277 pop	pc */
0x0000f414, 0x0ded0000, /* 0ded0000 //C 0f414  1285 push	lr */
0x0000f415, 0x0d1d0000, /* 0d1d0000 //C 0f415  1286 push	r1 */
0x0000f416, 0x0d3d0000, /* 0d3d0000 //C 0f416  1287 push	r3 */
0x0000f417, 0x01320001, /* 01320001 //C 0f417  1288 mvzl	r3,1 */
0x0000f418, 0x0400f3b9, /* 0400f3b9 //C 0f418  1289 call	str_cmp_eq */
0x0000f419, 0x0f3d0000, /* 0f3d0000 //C 0f419  1290 pop	r3 */
0x0000f41a, 0x0f1d0000, /* 0f1d0000 //C 0f41a  1291 pop	r1 */
0x0000f41b, 0x0ffd0000, /* 0ffd0000 //C 0f41b  1292 pop	pc */
0x0000f41c, 0x0ded0000, /* 0ded0000 //C 0f41c  1300 push	lr */
0x0000f41d, 0x0d1d0000, /* 0d1d0000 //C 0f41d  1301 push	r1 */
0x0000f41e, 0x0d3d0000, /* 0d3d0000 //C 0f41e  1302 push	r3 */
0x0000f41f, 0x01320000, /* 01320000 //C 0f41f  1303 mvzl	r3,0 */
0x0000f420, 0x0400f3b9, /* 0400f3b9 //C 0f420  1304 call	str_cmp_eq */
0x0000f421, 0x0f3d0000, /* 0f3d0000 //C 0f421  1305 pop	r3 */
0x0000f422, 0x0f1d0000, /* 0f1d0000 //C 0f422  1306 pop	r1 */
0x0000f423, 0x0ffd0000, /* 0ffd0000 //C 0f423  1307 pop	pc */
0x0000f424, 0x0108002f, /* 0108002f //C 0f424  1316 cmp	r0,'/' */
0x0000f425, 0xa1f2f43a, /* a1f2f43a //C 0f425  1317 LS jmp	hc2v_nok */
0x0000f426, 0x01080039, /* 01080039 //C 0f426  1318 cmp	r0,'9' */
0x0000f427, 0xa1f2f437, /* a1f2f437 //C 0f427  1319 LS jmp	hc2v_0_9 */
0x0000f428, 0x01080040, /* 01080040 //C 0f428  1320 cmp	r0,'@' */
0x0000f429, 0xa1f2f43a, /* a1f2f43a //C 0f429  1321 LS jmp	hc2v_nok */
0x0000f42a, 0x01080046, /* 01080046 //C 0f42a  1322 cmp	r0,'F' */
0x0000f42b, 0xa1f2f434, /* a1f2f434 //C 0f42b  1323 LS jmp	hc2v_A_F */
0x0000f42c, 0x01080060, /* 01080060 //C 0f42c  1324 cmp	r0,'`' */
0x0000f42d, 0xa1f2f43a, /* a1f2f43a //C 0f42d  1325 LS jmp	hc2v_nok */
0x0000f42e, 0x01080066, /* 01080066 //C 0f42e  1326 cmp	r0,'f' */
0x0000f42f, 0xa1f2f431, /* a1f2f431 //C 0f42f  1327 LS jmp	hc2v_a_f */
0x0000f430, 0x01f2f43a, /* 01f2f43a //C 0f430  1328 jmp	hc2v_nok */
0x0000f431, 0x0104000a, /* 0104000a //C 0f431  1330 add	r0,10 */
0x0000f432, 0x01060061, /* 01060061 //C 0f432  1331 sub	r0,'a' */
0x0000f433, 0x01f2f438, /* 01f2f438 //C 0f433  1332 jmp	hc2v_ok */
0x0000f434, 0x0104000a, /* 0104000a //C 0f434  1334 add	r0,10 */
0x0000f435, 0x01060041, /* 01060041 //C 0f435  1335 sub	r0,'A' */
0x0000f436, 0x01f2f438, /* 01f2f438 //C 0f436  1336 jmp	hc2v_ok */
0x0000f437, 0x01060030, /* 01060030 //C 0f437  1338 sub	r0,'0' */
0x0000f438, 0x020c0000, /* 020c0000 //C 0f438  1340 sec */
0x0000f439, 0x00f00e00, /* 00f00e00 //C 0f439  1341 ret */
0x0000f43a, 0x020d0000, /* 020d0000 //C 0f43a  1343 clc */
0x0000f43b, 0x00f00e00, /* 00f00e00 //C 0f43b  1344 ret */
0x0000f43c, 0x0d1d0000, /* 0d1d0000 //C 0f43c  1348 push	r1 */
0x0000f43d, 0x010f000f, /* 010f000f //C 0f43d  1349 and	r0,0xf */
0x0000f43e, 0x0112f442, /* 0112f442 //C 0f43e  1350 mvzl	r1,v2hc_table */
0x0000f43f, 0x0a010000, /* 0a010000 //C 0f43f  1351 ld	r0,r1,r0 */
0x0000f440, 0x0f1d0000, /* 0f1d0000 //C 0f440  1352 pop	r1 */
0x0000f441, 0x00f00e00, /* 00f00e00 //C 0f441  1353 ret */
0x0000f442, 0x00000030, /* 00000030 //C 0f442  1354 db	48 */
0x0000f443, 0x00000031, /* 00000031 //C 0f443  1354 db	49 */
0x0000f444, 0x00000032, /* 00000032 //C 0f444  1354 db	50 */
0x0000f445, 0x00000033, /* 00000033 //C 0f445  1354 db	51 */
0x0000f446, 0x00000034, /* 00000034 //C 0f446  1354 db	52 */
0x0000f447, 0x00000035, /* 00000035 //C 0f447  1354 db	53 */
0x0000f448, 0x00000036, /* 00000036 //C 0f448  1354 db	54 */
0x0000f449, 0x00000037, /* 00000037 //C 0f449  1354 db	55 */
0x0000f44a, 0x00000038, /* 00000038 //C 0f44a  1354 db	56 */
0x0000f44b, 0x00000039, /* 00000039 //C 0f44b  1354 db	57 */
0x0000f44c, 0x00000041, /* 00000041 //C 0f44c  1354 db	65 */
0x0000f44d, 0x00000042, /* 00000042 //C 0f44d  1354 db	66 */
0x0000f44e, 0x00000043, /* 00000043 //C 0f44e  1354 db	67 */
0x0000f44f, 0x00000044, /* 00000044 //C 0f44f  1354 db	68 */
0x0000f450, 0x00000045, /* 00000045 //C 0f450  1354 db	69 */
0x0000f451, 0x00000046, /* 00000046 //C 0f451  1354 db	70 */
0x0000f452, 0x00000000, /* 00000000 //C 0f452  1354 db */
0x0000f453, 0x0ded0000, /* 0ded0000 //C 0f453  1357 push	lr */
0x0000f454, 0x0400f43c, /* 0400f43c //C 0f454  1358 call	value2Hexchar */
0x0000f455, 0x010d0020, /* 010d0020 //C 0f455  1359 or	r0,0x20 */
0x0000f456, 0x0ffd0000, /* 0ffd0000 //C 0f456  1360 pop	pc */
0x0000f457, 0x0ded0000, /* 0ded0000 //C 0f457  1369 push	lr */
0x0000f458, 0x0d2d0000, /* 0d2d0000 //C 0f458  1370 push	r2 */
0x0000f459, 0x0d3d0000, /* 0d3d0000 //C 0f459  1371 push	r3 */
0x0000f45a, 0x0d4d0000, /* 0d4d0000 //C 0f45a  1372 push	r4 */
0x0000f45b, 0x0d5d0000, /* 0d5d0000 //C 0f45b  1373 push	r5 */
0x0000f45c, 0x01120000, /* 01120000 //C 0f45c  1374 mvzl	r1,0		; return value */
0x0000f45d, 0x01320000, /* 01320000 //C 0f45d  1375 mvzl	r3,0		; index */
0x0000f45e, 0x01520000, /* 01520000 //C 0f45e  1377 mvzl	r5,0 */
0x0000f45f, 0x0b438000, /* 0b438000 //C 0f45f  1378 ld	r4,r3+,r0	; pick a char */
0x0000f460, 0x024b0000, /* 024b0000 //C 0f460  1379 sz	r4		; check eof string */
0x0000f461, 0x11f2f47d, /* 11f2f47d //C 0f461  1380 jz	htoi_eos */
0x0000f462, 0x06214405, /* 06214405 //C 0f462  1382 getbz	r2,r4,r5 */
0x0000f463, 0x022b0000, /* 022b0000 //C 0f463  1383 sz	r2 */
0x0000f464, 0x11f2f45e, /* 11f2f45e //C 0f464  1384 jz	htoi_cyc */
0x0000f465, 0x0128002e, /* 0128002e //C 0f465  1385 cmp	r2,'.'		; skip separators */
0x0000f466, 0x11f2f477, /* 11f2f477 //C 0f466  1386 jz	htoi_next */
0x0000f467, 0x0128005f, /* 0128005f //C 0f467  1387 cmp	r2,'_' */
0x0000f468, 0x11f2f477, /* 11f2f477 //C 0f468  1388 jz	htoi_next */
0x0000f469, 0x0128002d, /* 0128002d //C 0f469  1389 cmp	r2,'-' */
0x0000f46a, 0x11f2f477, /* 11f2f477 //C 0f46a  1390 jz	htoi_next */
0x0000f46b, 0x0d0d0000, /* 0d0d0000 //C 0f46b  1391 push	r0 */
0x0000f46c, 0x00000200, /* 00000200 //C 0f46c  1392 mov	r0,r2 */
0x0000f46d, 0x0400f424, /* 0400f424 //C 0f46d  1393 call	hexchar2value */
0x0000f46e, 0x00200000, /* 00200000 //C 0f46e  1394 mov	r2,r0 */
0x0000f46f, 0x0f0d0000, /* 0f0d0000 //C 0f46f  1395 pop	r0 */
0x0000f470, 0x41f2f47b, /* 41f2f47b //C 0f470  1396 C0 jmp	htoi_nok */
0x0000f471, 0x02180000, /* 02180000 //C 0f471  1397 shl	r1 */
0x0000f472, 0x02180000, /* 02180000 //C 0f472  1398 shl	r1 */
0x0000f473, 0x02180000, /* 02180000 //C 0f473  1399 shl	r1 */
0x0000f474, 0x02180000, /* 02180000 //C 0f474  1400 shl	r1 */
0x0000f475, 0x012f000f, /* 012f000f //C 0f475  1401 and	r2,0xf */
0x0000f476, 0x001d0200, /* 001d0200 //C 0f476  1402 or	r1,r2 */
0x0000f477, 0x01540001, /* 01540001 //C 0f477  1404 inc	r5 */
0x0000f478, 0x01580004, /* 01580004 //C 0f478  1405 cmp	r5,4 */
0x0000f479, 0x11f2f45e, /* 11f2f45e //C 0f479  1406 jz	htoi_cyc */
0x0000f47a, 0x01f2f462, /* 01f2f462 //C 0f47a  1407 jmp	htoi_byte */
0x0000f47b, 0x020d0000, /* 020d0000 //C 0f47b  1409 clc */
0x0000f47c, 0x01f2f480, /* 01f2f480 //C 0f47c  1410 jmp	htoi_ret */
0x0000f47d, 0x01380001, /* 01380001 //C 0f47d  1412 cmp	r3,1 */
0x0000f47e, 0x920d0000, /* 920d0000 //C 0f47e  1413 HI clc */
0x0000f47f, 0xa20c0000, /* a20c0000 //C 0f47f  1414 LS sec */
0x0000f480, 0x0f5d0000, /* 0f5d0000 //C 0f480  1416 pop	r5 */
0x0000f481, 0x0f4d0000, /* 0f4d0000 //C 0f481  1417 pop	r4 */
0x0000f482, 0x0f3d0000, /* 0f3d0000 //C 0f482  1418 pop	r3 */
0x0000f483, 0x0f2d0000, /* 0f2d0000 //C 0f483  1419 pop	r2 */
0x0000f484, 0x0ffd0000, /* 0ffd0000 //C 0f484  1420 pop	pc */
0x0000f485, 0x0d0d0000, /* 0d0d0000 //C 0f485  1432 push	r0 */
0x0000f486, 0x0700ff42, /* 0700ff42 //C 0f486  1433 ld	r0,UART_RSTAT */
0x0000f487, 0x010c0001, /* 010c0001 //C 0f487  1435 test	r0,1		; check if queue is not empty */
0x0000f488, 0x020d0000, /* 020d0000 //C 0f488  1436 clc */
0x0000f489, 0x220c0000, /* 220c0000 //C 0f489  1437 Z0 sec */
0x0000f48a, 0x0f0d0000, /* 0f0d0000 //C 0f48a  1438 pop	r0 */
0x0000f48b, 0x30f00e00, /* 30f00e00 //C 0f48b  1439 C1 ret */
0x0000f48c, 0x00f00e00, /* 00f00e00 //C 0f48c  1440 ret */
0x0000f48d, 0x0700ff40, /* 0700ff40 //C 0f48d  1485 ld	r0,UART_DR */
0x0000f48e, 0x0600ff46, /* 0600ff46 //C 0f48e  1486 st	r0,UART_IRA */
0x0000f48f, 0x00f00e00, /* 00f00e00 //C 0f48f  1487 ret */
0x0000f490, 0x0400f485, /* 0400f485 //C 0f490  1519 call	check_uart */
0x0000f491, 0x41f2f490, /* 41f2f490 //C 0f491  1520 C0 jmp	getchar */
0x0000f492, 0x0400f48d, /* 0400f48d //C 0f492  1521 call	read */
0x0000f493, 0x00f00e00, /* 00f00e00 //C 0f493  1522 ret */
0x0000f494, 0x0d9d0000, /* 0d9d0000 //C 0f494  1530 push	r9 */
0x0000f495, 0x0790ff43, /* 0790ff43 //C 0f495  1537 ld	r9,UART_TSTAT */
0x0000f496, 0x019c0001, /* 019c0001 //C 0f496  1538 test	r9,1 */
0x0000f497, 0x11f2f495, /* 11f2f495 //C 0f497  1539 jz	wait_tc */
0x0000f498, 0x0600ff40, /* 0600ff40 //C 0f498  1540 st	r0,UART_DR */
0x0000f499, 0x0f9d0000, /* 0f9d0000 //C 0f499  1542 pop	r9 */
0x0000f49a, 0x00f00e00, /* 00f00e00 //C 0f49a  1543 ret */
0x0000f49b, 0x0ded0000, /* 0ded0000 //C 0f49b  1551 push	lr */
0x0000f49c, 0x0d0d0000, /* 0d0d0000 //C 0f49c  1552 push	r0 */
0x0000f49d, 0x0d3d0000, /* 0d3d0000 //C 0f49d  1553 push	r3 */
0x0000f49e, 0x0d4d0000, /* 0d4d0000 //C 0f49e  1554 push	r4 */
0x0000f49f, 0x0d2d0000, /* 0d2d0000 //C 0f49f  1555 push	r2 */
0x0000f4a0, 0x0d1d0000, /* 0d1d0000 //C 0f4a0  1556 push	r1 */
0x0000f4a1, 0x0d5d0000, /* 0d5d0000 //C 0f4a1  1557 push	r5 */
0x0000f4a2, 0x01420000, /* 01420000 //C 0f4a2  1559 mvzl	r4,0 */
0x0000f4a3, 0x020b0000, /* 020b0000 //C 0f4a3  1560 sz	r0 */
0x0000f4a4, 0x1102f69c, /* 1102f69c //C 0f4a4  1561 Z1 mvzl	r0,null_str */
0x0000f4a5, 0x00200000, /* 00200000 //C 0f4a5  1562 mov	r2,r0 */
0x0000f4a6, 0x0b148200, /* 0b148200 //C 0f4a6  1564 ld	r1,r4+,r2 */
0x0000f4a7, 0x021b0000, /* 021b0000 //C 0f4a7  1565 sz	r1 */
0x0000f4a8, 0x01520000, /* 01520000 //C 0f4a8  1566 mvzl	r5,0 */
0x0000f4a9, 0x11f2f4b2, /* 11f2f4b2 //C 0f4a9  1567 jz	prints_done */
0x0000f4aa, 0x06014105, /* 06014105 //C 0f4aa  1569 getbz	r0,r1,r5 */
0x0000f4ab, 0x020b0000, /* 020b0000 //C 0f4ab  1570 sz	r0 */
0x0000f4ac, 0x2400f494, /* 2400f494 //C 0f4ac  1571 NZ call	putchar */
0x0000f4ad, 0x11f2f4a6, /* 11f2f4a6 //C 0f4ad  1572 jz 	prints_go */
0x0000f4ae, 0x01540001, /* 01540001 //C 0f4ae  1573 inc	r5 */
0x0000f4af, 0x01580004, /* 01580004 //C 0f4af  1574 cmp	r5,4 */
0x0000f4b0, 0x21f2f4aa, /* 21f2f4aa //C 0f4b0  1575 jnz	prints_byte */
0x0000f4b1, 0x01f2f4a6, /* 01f2f4a6 //C 0f4b1  1576 jmp	prints_go */
0x0000f4b2, 0x0f5d0000, /* 0f5d0000 //C 0f4b2  1579 pop	r5 */
0x0000f4b3, 0x0f1d0000, /* 0f1d0000 //C 0f4b3  1580 pop	r1 */
0x0000f4b4, 0x0f2d0000, /* 0f2d0000 //C 0f4b4  1581 pop	r2 */
0x0000f4b5, 0x0f4d0000, /* 0f4d0000 //C 0f4b5  1582 pop	r4 */
0x0000f4b6, 0x0f3d0000, /* 0f3d0000 //C 0f4b6  1583 pop	r3 */
0x0000f4b7, 0x0f0d0000, /* 0f0d0000 //C 0f4b7  1584 pop	r0 */
0x0000f4b8, 0x0ffd0000, /* 0ffd0000 //C 0f4b8  1585 pop	pc */
0x0000f4b9, 0x00000000, /* 00000000 //C 0f4b9  1593 dd	0 */
0x0000f4ba, 0x0ded0000, /* 0ded0000 //C 0f4ba  1596 push	lr */
0x0000f4bb, 0x0d0d0000, /* 0d0d0000 //C 0f4bb  1597 push	r0 */
0x0000f4bc, 0x0d1d0000, /* 0d1d0000 //C 0f4bc  1598 push	r1 */
0x0000f4bd, 0x0d2d0000, /* 0d2d0000 //C 0f4bd  1599 push	r2 */
0x0000f4be, 0x0d3d0000, /* 0d3d0000 //C 0f4be  1600 push	r3 */
0x0000f4bf, 0x00100e00, /* 00100e00 //C 0f4bf  1601 mov	r1,lr */
0x0000f4c0, 0x0e210000, /* 0e210000 //C 0f4c0  1603 ld	r2,r1 */
0x0000f4c1, 0x01140001, /* 01140001 //C 0f4c1  1604 inc	r1 */
0x0000f4c2, 0x022b0000, /* 022b0000 //C 0f4c2  1605 sz	r2 */
0x0000f4c3, 0x11f2f4cd, /* 11f2f4cd //C 0f4c3  1606 jz	pes_done */
0x0000f4c4, 0x01320000, /* 01320000 //C 0f4c4  1607 mvzl	r3,0 */
0x0000f4c5, 0x06014203, /* 06014203 //C 0f4c5  1609 getbz	r0,r2,r3 */
0x0000f4c6, 0x020b0000, /* 020b0000 //C 0f4c6  1610 sz	r0 */
0x0000f4c7, 0x2400f494, /* 2400f494 //C 0f4c7  1611 NZ call	putchar */
0x0000f4c8, 0x11f2f4c0, /* 11f2f4c0 //C 0f4c8  1612 jz	pes_next */
0x0000f4c9, 0x01340001, /* 01340001 //C 0f4c9  1613 inc	r3 */
0x0000f4ca, 0x01380004, /* 01380004 //C 0f4ca  1614 cmp	r3,4 */
0x0000f4cb, 0x21f2f4c5, /* 21f2f4c5 //C 0f4cb  1615 jnz	pes_byte */
0x0000f4cc, 0x01f2f4c0, /* 01f2f4c0 //C 0f4cc  1616 jmp	pes_next */
0x0000f4cd, 0x0610f4b9, /* 0610f4b9 //C 0f4cd  1618 st	r1,pes_ret_to */
0x0000f4ce, 0x0f3d0000, /* 0f3d0000 //C 0f4ce  1619 pop	r3 */
0x0000f4cf, 0x0f2d0000, /* 0f2d0000 //C 0f4cf  1620 pop	r2 */
0x0000f4d0, 0x0f1d0000, /* 0f1d0000 //C 0f4d0  1621 pop	r1 */
0x0000f4d1, 0x0f0d0000, /* 0f0d0000 //C 0f4d1  1622 pop	r0 */
0x0000f4d2, 0x0fed0000, /* 0fed0000 //C 0f4d2  1623 pop	lr */
0x0000f4d3, 0x07f0f4b9, /* 07f0f4b9 //C 0f4d3  1624 ld	pc,pes_ret_to */
0x0000f4d4, 0x0ded0000, /* 0ded0000 //C 0f4d4  1632 push	lr */
0x0000f4d5, 0x0400f49b, /* 0400f49b //C 0f4d5  1633 call	prints */
0x0000f4d6, 0x0d0d0000, /* 0d0d0000 //C 0f4d6  1634 push	r0 */
0x0000f4d7, 0x0102000a, /* 0102000a //C 0f4d7  1635 mvzl	r0,LF */
0x0000f4d8, 0x0400f494, /* 0400f494 //C 0f4d8  1636 call	putchar */
0x0000f4d9, 0x0f0d0000, /* 0f0d0000 //C 0f4d9  1637 pop	r0 */
0x0000f4da, 0x0ffd0000, /* 0ffd0000 //C 0f4da  1638 pop	pc */
0x0000f4db, 0x0ded0000, /* 0ded0000 //C 0f4db  1646 push	lr */
0x0000f4dc, 0x0d0d0000, /* 0d0d0000 //C 0f4dc  1647 push	r0 */
0x0000f4dd, 0x0d1d0000, /* 0d1d0000 //C 0f4dd  1648 push	r1 */
0x0000f4de, 0x0d2d0000, /* 0d2d0000 //C 0f4de  1649 push	r2 */
0x0000f4df, 0x0d3d0000, /* 0d3d0000 //C 0f4df  1650 push	r3 */
0x0000f4e0, 0x0d4d0000, /* 0d4d0000 //C 0f4e0  1651 push	r4 */
0x0000f4e1, 0x00300000, /* 00300000 //C 0f4e1  1652 mov	r3,r0 */
0x0000f4e2, 0x01220000, /* 01220000 //C 0f4e2  1653 mvzl	r2,0 */
0x0000f4e3, 0x01420001, /* 01420001 //C 0f4e3  1654 mvzl	r4,1 */
0x0000f4e4, 0x01020000, /* 01020000 //C 0f4e4  1657 mvzl	r0,0 */
0x0000f4e5, 0x02380000, /* 02380000 //C 0f4e5  1658 shl	r3 */
0x0000f4e6, 0x02070000, /* 02070000 //C 0f4e6  1659 rol	r0 */
0x0000f4e7, 0x02380000, /* 02380000 //C 0f4e7  1660 shl	r3 */
0x0000f4e8, 0x02070000, /* 02070000 //C 0f4e8  1661 rol	r0 */
0x0000f4e9, 0x02380000, /* 02380000 //C 0f4e9  1662 shl	r3 */
0x0000f4ea, 0x02070000, /* 02070000 //C 0f4ea  1663 rol	r0 */
0x0000f4eb, 0x02380000, /* 02380000 //C 0f4eb  1664 shl	r3 */
0x0000f4ec, 0x02070000, /* 02070000 //C 0f4ec  1665 rol	r0 */
0x0000f4ed, 0x0400f43c, /* 0400f43c //C 0f4ed  1666 call	value2Hexchar */
0x0000f4ee, 0x0400f494, /* 0400f494 //C 0f4ee  1667 call	putchar */
0x0000f4ef, 0x01240001, /* 01240001 //C 0f4ef  1668 add	r2,1 */
0x0000f4f0, 0x01280008, /* 01280008 //C 0f4f0  1669 cmp	r2,8 */
0x0000f4f1, 0x11f2f4fb, /* 11f2f4fb //C 0f4f1  1670 jz	print_vhex_ret */
0x0000f4f2, 0x021b0000, /* 021b0000 //C 0f4f2  1671 sz	r1 */
0x0000f4f3, 0x11f2f4f9, /* 11f2f4f9 //C 0f4f3  1672 jz	print_vhex_nosep */
0x0000f4f4, 0x00480100, /* 00480100 //C 0f4f4  1673 cmp	r4,r1 */
0x0000f4f5, 0x21f2f4f9, /* 21f2f4f9 //C 0f4f5  1674 jnz	print_vhex_nosep */
0x0000f4f6, 0x0102005f, /* 0102005f //C 0f4f6  1675 mvzl	r0,'_' */
0x0000f4f7, 0x0400f494, /* 0400f494 //C 0f4f7  1676 call	putchar */
0x0000f4f8, 0x01420000, /* 01420000 //C 0f4f8  1677 mvzl	r4,0 */
0x0000f4f9, 0x01440001, /* 01440001 //C 0f4f9  1679 add	r4,1 */
0x0000f4fa, 0x01f2f4e4, /* 01f2f4e4 //C 0f4fa  1680 jmp	print_vhex_cyc */
0x0000f4fb, 0x0f4d0000, /* 0f4d0000 //C 0f4fb  1682 pop	r4 */
0x0000f4fc, 0x0f3d0000, /* 0f3d0000 //C 0f4fc  1683 pop	r3 */
0x0000f4fd, 0x0f2d0000, /* 0f2d0000 //C 0f4fd  1684 pop	r2 */
0x0000f4fe, 0x0f1d0000, /* 0f1d0000 //C 0f4fe  1685 pop	r1 */
0x0000f4ff, 0x0f0d0000, /* 0f0d0000 //C 0f4ff  1686 pop	r0 */
0x0000f500, 0x0ffd0000, /* 0ffd0000 //C 0f500  1687 pop	pc */
0x0000f501, 0x0ded0000, /* 0ded0000 //C 0f501  1695 push	lr */
0x0000f502, 0x0d4d0000, /* 0d4d0000 //C 0f502  1696 push	r4 */
0x0000f503, 0x021b0000, /* 021b0000 //C 0f503  1698 sz	r1 */
0x0000f504, 0x21f2f508, /* 21f2f508 //C 0f504  1699 NZ jmp	div_dok */
0x0000f505, 0x00200000, /* 00200000 //C 0f505  1700 mov	r2,r0		; div by zero */
0x0000f506, 0x01320000, /* 01320000 //C 0f506  1701 mvzl	r3,0 */
0x0000f507, 0x01f2f519, /* 01f2f519 //C 0f507  1702 jmp	div_ret */
0x0000f508, 0x01220000, /* 01220000 //C 0f508  1704 mvzl	r2,0		; Q= 0 */
0x0000f509, 0x01320000, /* 01320000 //C 0f509  1705 mvzl	r3,0		; R= 0 */
0x0000f50a, 0x01418000, /* 01418000 //C 0f50a  1706 mvh	r4,0x80000000	; m= 1<<31 */
0x0000f50b, 0x01400000, /* 01400000 //C 0f50b  1707 mvl	r4,0x80000000 */
0x0000f50c, 0x024b0000, /* 024b0000 //C 0f50c  1709 sz	r4 */
0x0000f50d, 0x11f2f519, /* 11f2f519 //C 0f50d  1710 Z jmp	div_ret */
0x0000f50e, 0x02380000, /* 02380000 //C 0f50e  1711 shl	r3		; r<<= 1 */
0x0000f50f, 0x000c0400, /* 000c0400 //C 0f50f  1712 test	r0,r4		; if (n&m) */
0x0000f510, 0x213d0001, /* 213d0001 //C 0f510  1713 NZ or	r3,1		; r|= 1 */
0x0000f511, 0x00380100, /* 00380100 //C 0f511  1714 cmp	r3,r1		; if (r>=d) */
0x0000f512, 0x41f2f517, /* 41f2f517 //C 0f512  1715 LO jmp	div_cyc_next */
0x0000f513, 0x00360100, /* 00360100 //C 0f513  1716 sub	r3,r1		;r-= d */
0x0000f514, 0x002d0400, /* 002d0400 //C 0f514  1717 or	r2,r4		;q|= m */
0x0000f515, 0x01f2f517, /* 01f2f517 //C 0f515  1718 jmp	div_cyc_next */
0x0000f516, 0x01f2f50c, /* 01f2f50c //C 0f516  1719 jmp	div_cyc */
0x0000f517, 0x02490000, /* 02490000 //C 0f517  1721 shr	r4		; m>>= 1 */
0x0000f518, 0x01f2f50c, /* 01f2f50c //C 0f518  1722 jmp	div_cyc */
0x0000f519, 0x0f4d0000, /* 0f4d0000 //C 0f519  1724 pop	r4 */
0x0000f51a, 0x0ffd0000, /* 0ffd0000 //C 0f51a  1725 pop	pc */
0x0000f51b, 0x0ded0000, /* 0ded0000 //C 0f51b  1733 push	lr */
0x0000f51c, 0x0d0d0000, /* 0d0d0000 //C 0f51c  1734 push	r0 */
0x0000f51d, 0x0d1d0000, /* 0d1d0000 //C 0f51d  1735 push	r1 */
0x0000f51e, 0x0d2d0000, /* 0d2d0000 //C 0f51e  1736 push	r2 */
0x0000f51f, 0x0d3d0000, /* 0d3d0000 //C 0f51f  1737 push	r3 */
0x0000f520, 0x0dad0000, /* 0dad0000 //C 0f520  1738 push	r10 */
0x0000f521, 0x0dbd0000, /* 0dbd0000 //C 0f521  1739 push	r11 */
0x0000f522, 0x0dcd0000, /* 0dcd0000 //C 0f522  1740 push	r12 */
0x0000f523, 0x01c2f543, /* 01c2f543 //C 0f523  1742 mvzl	r12,itoa_buffer	; pointer to output buffer */
0x0000f524, 0x01b2f54e, /* 01b2f54e //C 0f524  1743 mvzl	r11,itoa_divs	; pointer to dividers */
0x0000f525, 0x01a20000, /* 01a20000 //C 0f525  1744 mvzl	r10,0		; bool: first non-zero char found */
0x0000f526, 0x0e1b0000, /* 0e1b0000 //C 0f526  1746 ld	r1,r11		; get next divider */
0x0000f527, 0x021b0000, /* 021b0000 //C 0f527  1747 sz	r1		; if 0, then */
0x0000f528, 0x11f2f53b, /* 11f2f53b //C 0f528  1748 jz	itoa_ret	; finish */
0x0000f529, 0x01180001, /* 01180001 //C 0f529  1749 cmp	r1,1		; last divider? */
0x0000f52a, 0x11a20001, /* 11a20001 //C 0f52a  1750 EQ mvzl	r10,1		; always print last char */
0x0000f52b, 0x0400f501, /* 0400f501 //C 0f52b  1751 call	div		; R2,R3= R0/R1 */
0x0000f52c, 0x022b0000, /* 022b0000 //C 0f52c  1752 sz	r2		; is the result zero? */
0x0000f52d, 0x11f2f538, /* 11f2f538 //C 0f52d  1753 jz	itoa_f0 */
0x0000f52e, 0x01a20001, /* 01a20001 //C 0f52e  1755 mvzl	r10,1		; non-zero: start to print */
0x0000f52f, 0x00000200, /* 00000200 //C 0f52f  1757 mov	r0,r2		; convert result to ASCII char */
0x0000f530, 0x0400f453, /* 0400f453 //C 0f530  1758 call	value2hexchar */
0x0000f531, 0x0c0c0000, /* 0c0c0000 //C 0f531  1759 st	r0,r12		; and store it in buffer */
0x0000f532, 0x01c40001, /* 01c40001 //C 0f532  1760 inc	r12		; inc buf ptr */
0x0000f533, 0x01020000, /* 01020000 //C 0f533  1761 mvzl	r0,0		; put 0 after last char */
0x0000f534, 0x0c0c0000, /* 0c0c0000 //C 0f534  1762 st	r0,r12 */
0x0000f535, 0x00000300, /* 00000300 //C 0f535  1764 mov	r0,r3		; continue with the reminder */
0x0000f536, 0x01b40001, /* 01b40001 //C 0f536  1765 inc	r11		; and next divider */
0x0000f537, 0x01f2f526, /* 01f2f526 //C 0f537  1766 jmp	itoa_cyc */
0x0000f538, 0x02ab0000, /* 02ab0000 //C 0f538  1768 sz	r10		; just zeros so far? */
0x0000f539, 0x21f2f52f, /* 21f2f52f //C 0f539  1769 jnz	itoa_store	; no, print */
0x0000f53a, 0x01f2f535, /* 01f2f535 //C 0f53a  1770 jmp	itoa_next */
0x0000f53b, 0x0fcd0000, /* 0fcd0000 //C 0f53b  1772 pop	r12 */
0x0000f53c, 0x0fbd0000, /* 0fbd0000 //C 0f53c  1773 pop	r11 */
0x0000f53d, 0x0fad0000, /* 0fad0000 //C 0f53d  1774 pop	r10 */
0x0000f53e, 0x0f3d0000, /* 0f3d0000 //C 0f53e  1775 pop	r3 */
0x0000f53f, 0x0f2d0000, /* 0f2d0000 //C 0f53f  1776 pop	r2 */
0x0000f540, 0x0f1d0000, /* 0f1d0000 //C 0f540  1777 pop	r1 */
0x0000f541, 0x0f0d0000, /* 0f0d0000 //C 0f541  1778 pop	r0 */
0x0000f542, 0x0ffd0000, /* 0ffd0000 //C 0f542  1779 pop	pc */
0x0000f543, 0x00000000, /* 00000000 //C 0f543  1781 itoa_buffer:	ds	11 */
0x0000f54e, 0x3b9aca00, /* 3b9aca00 //C 0f54e  1783 dd	1000000000 */
0x0000f54f, 0x05f5e100, /* 05f5e100 //C 0f54f  1784 dd	100000000 */
0x0000f550, 0x00989680, /* 00989680 //C 0f550  1785 dd	10000000 */
0x0000f551, 0x000f4240, /* 000f4240 //C 0f551  1786 dd	1000000 */
0x0000f552, 0x000186a0, /* 000186a0 //C 0f552  1787 dd	100000 */
0x0000f553, 0x00002710, /* 00002710 //C 0f553  1788 dd	10000 */
0x0000f554, 0x000003e8, /* 000003e8 //C 0f554  1789 dd	1000 */
0x0000f555, 0x00000064, /* 00000064 //C 0f555  1790 dd	100 */
0x0000f556, 0x0000000a, /* 0000000a //C 0f556  1791 dd	10 */
0x0000f557, 0x00000001, /* 00000001 //C 0f557  1792 dd	1 */
0x0000f558, 0x00000000, /* 00000000 //C 0f558  1793 dd	0 */
0x0000f559, 0x0ded0000, /* 0ded0000 //C 0f559  1800 push	lr */
0x0000f55a, 0x0400f51b, /* 0400f51b //C 0f55a  1801 call	itoa */
0x0000f55b, 0x0102f543, /* 0102f543 //C 0f55b  1802 mvzl	r0,itoa_buffer */
0x0000f55c, 0x0400f49b, /* 0400f49b //C 0f55c  1803 call	prints */
0x0000f55d, 0x0ffd0000, /* 0ffd0000 //C 0f55d  1804 pop	pc */
0x0000f55e, 0x0ded0000, /* 0ded0000 //C 0f55e  1813 push	lr */
0x0000f55f, 0x0d0d0000, /* 0d0d0000 //C 0f55f  1814 push	r0 */
0x0000f560, 0x0d1d0000, /* 0d1d0000 //C 0f560  1815 push	r1 */
0x0000f561, 0x0d3d0000, /* 0d3d0000 //C 0f561  1816 push	r3 */
0x0000f562, 0x0610f654, /* 0610f654 //C 0f562  1818 st	r1,reg1 */
0x0000f563, 0x0620f655, /* 0620f655 //C 0f563  1819 st	r2,reg2 */
0x0000f564, 0x0630f656, /* 0630f656 //C 0f564  1820 st	r3,reg3 */
0x0000f565, 0x0640f657, /* 0640f657 //C 0f565  1821 st	r4,reg4 */
0x0000f566, 0x0650f658, /* 0650f658 //C 0f566  1822 st	r5,reg5 */
0x0000f567, 0x0660f659, /* 0660f659 //C 0f567  1823 st	r6,reg6 */
0x0000f568, 0x0670f65a, /* 0670f65a //C 0f568  1824 st	r7,reg7 */
0x0000f569, 0x0680f65b, /* 0680f65b //C 0f569  1825 st	r8,reg8 */
0x0000f56a, 0x0690f65c, /* 0690f65c //C 0f56a  1826 st	r9,reg9 */
0x0000f56b, 0x06a0f65d, /* 06a0f65d //C 0f56b  1827 st	r10,reg10 */
0x0000f56c, 0x06b0f65e, /* 06b0f65e //C 0f56c  1828 st	r11,reg11 */
0x0000f56d, 0x06c0f65f, /* 06c0f65f //C 0f56d  1829 st	r12,reg12 */
0x0000f56e, 0x00200000, /* 00200000 //C 0f56e  1831 mov	r2,r0		; pointer to format string */
0x0000f56f, 0x0112f654, /* 0112f654 //C 0f56f  1832 mvzl	r1,reg1		; pointer to params */
0x0000f570, 0x01320000, /* 01320000 //C 0f570  1833 mvzl	r3,0		; byte idx in packed str */
0x0000f571, 0x0e020000, /* 0e020000 //C 0f571  1835 ld	r0,r2		; get next char */
0x0000f572, 0x020b0000, /* 020b0000 //C 0f572  1836 sz	r0		; is it EOS? */
0x0000f573, 0x11f2f5d8, /* 11f2f5d8 //C 0f573  1837 jz	printf_ret */
0x0000f574, 0x06014003, /* 06014003 //C 0f574  1838 getbz	r0,r0,r3	; pick next byte */
0x0000f575, 0x020b0000, /* 020b0000 //C 0f575  1839 sz	r0		; is it null? */
0x0000f576, 0x11f2f5d5, /* 11f2f5d5 //C 0f576  1840 jz	printf_nextword	; no more non-nulls */
0x0000f577, 0x0108005c, /* 0108005c //C 0f577  1842 cmp	r0,'\\' */
0x0000f578, 0x21f2f5a3, /* 21f2f5a3 //C 0f578  1843 jnz	printf_notescape */
0x0000f579, 0x01340001, /* 01340001 //C 0f579  1845 inc	r3 */
0x0000f57a, 0x01380004, /* 01380004 //C 0f57a  1846 cmp	r3,4 */
0x0000f57b, 0x21f2f581, /* 21f2f581 //C 0f57b  1847 jnz	printf_l1 */
0x0000f57c, 0x01320000, /* 01320000 //C 0f57c  1849 mvzl	r3,0 */
0x0000f57d, 0x01240001, /* 01240001 //C 0f57d  1850 inc	r2 */
0x0000f57e, 0x0e020000, /* 0e020000 //C 0f57e  1851 ld	r0,r2 */
0x0000f57f, 0x020b0000, /* 020b0000 //C 0f57f  1852 sz	r0 */
0x0000f580, 0x11f2f5d8, /* 11f2f5d8 //C 0f580  1853 jz	printf_ret */
0x0000f581, 0x0e020000, /* 0e020000 //C 0f581  1855 ld	r0,r2 */
0x0000f582, 0x06014003, /* 06014003 //C 0f582  1856 getbz	r0,r0,r3 */
0x0000f583, 0x020b0000, /* 020b0000 //C 0f583  1857 sz	r0 */
0x0000f584, 0x11f2f57c, /* 11f2f57c //C 0f584  1858 jz	printf_l2 */
0x0000f585, 0x01080061, /* 01080061 //C 0f585  1860 cmp	r0,'a' */
0x0000f586, 0x11020007, /* 11020007 //C 0f586  1861 Z mvzl	r0,7 */
0x0000f587, 0x11f2f5d1, /* 11f2f5d1 //C 0f587  1862 Z jmp	printf_print */
0x0000f588, 0x01080062, /* 01080062 //C 0f588  1863 cmp	r0,'b' */
0x0000f589, 0x11020008, /* 11020008 //C 0f589  1864 Z mvzl	r0,8 */
0x0000f58a, 0x11f2f5d1, /* 11f2f5d1 //C 0f58a  1865 Z jmp	printf_print */
0x0000f58b, 0x01080065, /* 01080065 //C 0f58b  1866 cmp	r0,'e' */
0x0000f58c, 0x1102001b, /* 1102001b //C 0f58c  1867 Z mvzl	r0,0x1b */
0x0000f58d, 0x11f2f5d1, /* 11f2f5d1 //C 0f58d  1868 Z jmp	printf_print */
0x0000f58e, 0x01080066, /* 01080066 //C 0f58e  1869 cmp	r0,'f' */
0x0000f58f, 0x1102000c, /* 1102000c //C 0f58f  1870 Z mvzl	r0,0xc */
0x0000f590, 0x11f2f5d1, /* 11f2f5d1 //C 0f590  1871 Z jmp	printf_print */
0x0000f591, 0x0108006e, /* 0108006e //C 0f591  1872 cmp	r0,'n' */
0x0000f592, 0x1102000a, /* 1102000a //C 0f592  1873 Z mvzl	r0,0xa */
0x0000f593, 0x11f2f5d1, /* 11f2f5d1 //C 0f593  1874 Z jmp	printf_print */
0x0000f594, 0x01080072, /* 01080072 //C 0f594  1875 cmp	r0,'r' */
0x0000f595, 0x1102000d, /* 1102000d //C 0f595  1876 Z mvzl	r0,0xd */
0x0000f596, 0x11f2f5d1, /* 11f2f5d1 //C 0f596  1877 Z jmp	printf_print */
0x0000f597, 0x01080074, /* 01080074 //C 0f597  1878 cmp	r0,'t' */
0x0000f598, 0x11020009, /* 11020009 //C 0f598  1879 Z mvzl	r0,9 */
0x0000f599, 0x11f2f5d1, /* 11f2f5d1 //C 0f599  1880 Z jmp	printf_print */
0x0000f59a, 0x01080076, /* 01080076 //C 0f59a  1881 cmp	r0,'v' */
0x0000f59b, 0x1102000b, /* 1102000b //C 0f59b  1882 Z mvzl	r0,0xb */
0x0000f59c, 0x11f2f5d1, /* 11f2f5d1 //C 0f59c  1883 Z jmp	printf_print */
0x0000f59d, 0x0108005c, /* 0108005c //C 0f59d  1884 cmp	r0,0x5c */
0x0000f59e, 0x11f2f5d1, /* 11f2f5d1 //C 0f59e  1885 Z jmp	printf_print */
0x0000f59f, 0x01080030, /* 01080030 //C 0f59f  1886 cmp	r0,'0' */
0x0000f5a0, 0x11020000, /* 11020000 //C 0f5a0  1887 Z mvzl	r0,0 */
0x0000f5a1, 0x11f2f5d1, /* 11f2f5d1 //C 0f5a1  1888 Z jmp	printf_print */
0x0000f5a2, 0x01f2f5d1, /* 01f2f5d1 //C 0f5a2  1890 jmp	printf_print */
0x0000f5a3, 0x01080025, /* 01080025 //C 0f5a3  1893 cmp	r0,'%'		; is it a format char? */
0x0000f5a4, 0x21f2f5d1, /* 21f2f5d1 //C 0f5a4  1894 jnz	printf_print */
0x0000f5a5, 0x01340001, /* 01340001 //C 0f5a5  1896 inc	r3 */
0x0000f5a6, 0x01380004, /* 01380004 //C 0f5a6  1897 cmp	r3,4 */
0x0000f5a7, 0x21f2f5ad, /* 21f2f5ad //C 0f5a7  1898 jnz	printf_l3 */
0x0000f5a8, 0x01320000, /* 01320000 //C 0f5a8  1900 mvzl	r3,0 */
0x0000f5a9, 0x01240001, /* 01240001 //C 0f5a9  1901 inc	r2		; go to format char */
0x0000f5aa, 0x0e020000, /* 0e020000 //C 0f5aa  1902 ld	r0,r2 */
0x0000f5ab, 0x022b0000, /* 022b0000 //C 0f5ab  1903 sz	r2		; is it EOS? */
0x0000f5ac, 0x11f2f5d8, /* 11f2f5d8 //C 0f5ac  1904 jz	printf_ret */
0x0000f5ad, 0x0e020000, /* 0e020000 //C 0f5ad  1906 ld	r0,r2 */
0x0000f5ae, 0x06014003, /* 06014003 //C 0f5ae  1907 getbz	r0,r0,r3 */
0x0000f5af, 0x020b0000, /* 020b0000 //C 0f5af  1908 sz	r0 */
0x0000f5b0, 0x11f2f5a8, /* 11f2f5a8 //C 0f5b0  1909 jz	printf_l4 */
0x0000f5b1, 0x01080025, /* 01080025 //C 0f5b1  1911 cmp	r0,'%'		; % is used to print % */
0x0000f5b2, 0x11f2f5d1, /* 11f2f5d1 //C 0f5b2  1912 jz	printf_print */
0x0000f5b3, 0x01080075, /* 01080075 //C 0f5b3  1914 cmp	r0,'u'		; u,d print in decimal */
0x0000f5b4, 0x11f2f5b7, /* 11f2f5b7 //C 0f5b4  1915 jz	printf_d */
0x0000f5b5, 0x01080064, /* 01080064 //C 0f5b5  1916 cmp	r0,'d' */
0x0000f5b6, 0x21f2f5bb, /* 21f2f5bb //C 0f5b6  1917 jnz	printf_notd */
0x0000f5b7, 0x0e010000, /* 0e010000 //C 0f5b7  1919 ld	r0,r1 */
0x0000f5b8, 0x01140001, /* 01140001 //C 0f5b8  1920 inc	r1 */
0x0000f5b9, 0x0400f559, /* 0400f559 //C 0f5b9  1921 call	printd */
0x0000f5ba, 0x01f2f5d2, /* 01f2f5d2 //C 0f5ba  1922 jmp	printf_next */
0x0000f5bb, 0x01080078, /* 01080078 //C 0f5bb  1925 cmp	r0,'x' */
0x0000f5bc, 0x21f2f5c4, /* 21f2f5c4 //C 0f5bc  1926 jnz	printf_notx */
0x0000f5bd, 0x0e010000, /* 0e010000 //C 0f5bd  1928 ld	r0,r1 */
0x0000f5be, 0x01140001, /* 01140001 //C 0f5be  1929 inc	r1 */
0x0000f5bf, 0x0d1d0000, /* 0d1d0000 //C 0f5bf  1930 push	r1 */
0x0000f5c0, 0x01120000, /* 01120000 //C 0f5c0  1931 mvzl	r1,0 */
0x0000f5c1, 0x0400f4db, /* 0400f4db //C 0f5c1  1932 call	print_vhex */
0x0000f5c2, 0x0f1d0000, /* 0f1d0000 //C 0f5c2  1933 pop	r1 */
0x0000f5c3, 0x01f2f5d2, /* 01f2f5d2 //C 0f5c3  1934 jmp	printf_next */
0x0000f5c4, 0x01080073, /* 01080073 //C 0f5c4  1937 cmp	r0,'s' */
0x0000f5c5, 0x21f2f5ca, /* 21f2f5ca //C 0f5c5  1938 jnz	printf_nots */
0x0000f5c6, 0x0e010000, /* 0e010000 //C 0f5c6  1940 ld	r0,r1 */
0x0000f5c7, 0x01140001, /* 01140001 //C 0f5c7  1941 inc	r1 */
0x0000f5c8, 0x0400f49b, /* 0400f49b //C 0f5c8  1942 call	prints */
0x0000f5c9, 0x01f2f5d2, /* 01f2f5d2 //C 0f5c9  1943 jmp	printf_next */
0x0000f5ca, 0x01080063, /* 01080063 //C 0f5ca  1946 cmp	r0,'c' */
0x0000f5cb, 0x21f2f5d0, /* 21f2f5d0 //C 0f5cb  1947 jnz	printf_notc */
0x0000f5cc, 0x0e010000, /* 0e010000 //C 0f5cc  1948 ld	r0,r1 */
0x0000f5cd, 0x01140001, /* 01140001 //C 0f5cd  1949 inc	r1 */
0x0000f5ce, 0x0400f494, /* 0400f494 //C 0f5ce  1950 call	putchar */
0x0000f5cf, 0x01f2f5d2, /* 01f2f5d2 //C 0f5cf  1951 jmp	printf_next */
0x0000f5d0, 0x01f2f5d2, /* 01f2f5d2 //C 0f5d0  1954 jmp	printf_next */
0x0000f5d1, 0x0400f494, /* 0400f494 //C 0f5d1  1956 call	putchar		; print actual char */
0x0000f5d2, 0x01340001, /* 01340001 //C 0f5d2  1958 inc	r3		; next byte in word */
0x0000f5d3, 0x01380004, /* 01380004 //C 0f5d3  1959 cmp	r3,4		; all 4 processed? */
0x0000f5d4, 0x21f2f571, /* 21f2f571 //C 0f5d4  1960 jnz	printf_cyc */
0x0000f5d5, 0x01240001, /* 01240001 //C 0f5d5  1962 inc	r2		; inc string ptr */
0x0000f5d6, 0x01320000, /* 01320000 //C 0f5d6  1963 mvzl	r3,0		; restart byte idx */
0x0000f5d7, 0x01f2f571, /* 01f2f571 //C 0f5d7  1964 jmp	printf_cyc */
0x0000f5d8, 0x0f3d0000, /* 0f3d0000 //C 0f5d8  1967 pop	r3 */
0x0000f5d9, 0x0f1d0000, /* 0f1d0000 //C 0f5d9  1968 pop	r1 */
0x0000f5da, 0x0f0d0000, /* 0f0d0000 //C 0f5da  1969 pop	r0 */
0x0000f5db, 0x0ffd0000, /* 0ffd0000 //C 0f5db  1970 pop	pc */
0x0000f5dc, 0x0d0d0000, /* 0d0d0000 //C 0f5dc  1975 push	r0 */
0x0000f5dd, 0x0d2d0000, /* 0d2d0000 //C 0f5dd  1976 push	r2 */
0x0000f5de, 0x00000e00, /* 00000e00 //C 0f5de  1977 mov	r0,LR */
0x0000f5df, 0x0400f55e, /* 0400f55e //C 0f5df  1978 call	printf */
0x0000f5e0, 0x01240001, /* 01240001 //C 0f5e0  1979 inc	r2 */
0x0000f5e1, 0x0620f655, /* 0620f655 //C 0f5e1  1980 st	r2,reg2 */
0x0000f5e2, 0x0f2d0000, /* 0f2d0000 //C 0f5e2  1981 pop	r2 */
0x0000f5e3, 0x0f0d0000, /* 0f0d0000 //C 0f5e3  1982 pop	r0 */
0x0000f5e4, 0x07f0f655, /* 07f0f655 //C 0f5e4  1983 ld	PC,reg2 */
0x0000f5e5, 0x00000000, /* 00000000 //C 0f5e5  1988 line:		ds	100		; line buffer */
0x0000f649, 0x00000000, /* 00000000 //C 0f649  1989 line_ptr:	ds	1		; line pointer (index) */
0x0000f64a, 0x00000000, /* 00000000 //C 0f64a  1990 at_eol:		ds	1		; bool, true if EOL arrived */
0x0000f64b, 0x00000000, /* 00000000 //C 0f64b  1991 words:		ds	5		; Tokens of line */
0x0000f650, 0x00000000, /* 00000000 //C 0f650  1992 echo:		ds	1		; bool, do echo or not */
0x0000f651, 0x00000000, /* 00000000 //C 0f651  1993 dd	0 */
0x0000f652, 0x00000000, /* 00000000 //C 0f652  1994 dd	0 */
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
0x0000f660, 0x00000000, /* 00000000 //C 0f660  2009 dd	0 */
0x0000f661, 0x00000000, /* 00000000 //C 0f661  2010 dd	0 */
0x0000f662, 0x00000000, /* 00000000 //C 0f662  2011 dd	0 */
0x0000f663, 0x00000000, /* 00000000 //C 0f663  2012 dd	0 */
0x0000f664, 0x00000050, /* 00000050 //C 0f664  2014 db	80 */
0x0000f665, 0x0000004d, /* 0000004d //C 0f665  2014 db	77 */
0x0000f666, 0x0000006f, /* 0000006f //C 0f666  2014 db	111 */
0x0000f667, 0x0000006e, /* 0000006e //C 0f667  2014 db	110 */
0x0000f668, 0x00000069, /* 00000069 //C 0f668  2014 db	105 */
0x0000f669, 0x00000074, /* 00000074 //C 0f669  2014 db	116 */
0x0000f66a, 0x0000006f, /* 0000006f //C 0f66a  2014 db	111 */
0x0000f66b, 0x00000072, /* 00000072 //C 0f66b  2014 db	114 */
0x0000f66c, 0x00000020, /* 00000020 //C 0f66c  2014 db	32 */
0x0000f66d, 0x00000076, /* 00000076 //C 0f66d  2014 db	118 */
0x0000f66e, 0x00000031, /* 00000031 //C 0f66e  2014 db	49 */
0x0000f66f, 0x0000002e, /* 0000002e //C 0f66f  2014 db	46 */
0x0000f670, 0x00000031, /* 00000031 //C 0f670  2014 db	49 */
0x0000f671, 0x00000020, /* 00000020 //C 0f671  2014 db	32 */
0x0000f672, 0x00000028, /* 00000028 //C 0f672  2014 db	40 */
0x0000f673, 0x00000063, /* 00000063 //C 0f673  2014 db	99 */
0x0000f674, 0x00000070, /* 00000070 //C 0f674  2014 db	112 */
0x0000f675, 0x00000075, /* 00000075 //C 0f675  2014 db	117 */
0x0000f676, 0x00000020, /* 00000020 //C 0f676  2014 db	32 */
0x0000f677, 0x00000076, /* 00000076 //C 0f677  2014 db	118 */
0x0000f678, 0x00000025, /* 00000025 //C 0f678  2014 db	37 */
0x0000f679, 0x00000064, /* 00000064 //C 0f679  2014 db	100 */
0x0000f67a, 0x0000002e, /* 0000002e //C 0f67a  2014 db	46 */
0x0000f67b, 0x00000025, /* 00000025 //C 0f67b  2014 db	37 */
0x0000f67c, 0x00000064, /* 00000064 //C 0f67c  2014 db	100 */
0x0000f67d, 0x0000002e, /* 0000002e //C 0f67d  2014 db	46 */
0x0000f67e, 0x00000025, /* 00000025 //C 0f67e  2014 db	37 */
0x0000f67f, 0x00000064, /* 00000064 //C 0f67f  2014 db	100 */
0x0000f680, 0x00000029, /* 00000029 //C 0f680  2014 db	41 */
0x0000f681, 0x0000000a, /* 0000000a //C 0f681  2014 db	10 */
0x0000f682, 0x00000000, /* 00000000 //C 0f682  2014 db */
0x0000f683, 0x00000053, /* 00000053 //C 0f683  2015 db	83 */
0x0000f684, 0x00000074, /* 00000074 //C 0f684  2015 db	116 */
0x0000f685, 0x0000006f, /* 0000006f //C 0f685  2015 db	111 */
0x0000f686, 0x00000070, /* 00000070 //C 0f686  2015 db	112 */
0x0000f687, 0x00000020, /* 00000020 //C 0f687  2015 db	32 */
0x0000f688, 0x00000061, /* 00000061 //C 0f688  2015 db	97 */
0x0000f689, 0x00000074, /* 00000074 //C 0f689  2015 db	116 */
0x0000f68a, 0x0000003a, /* 0000003a //C 0f68a  2015 db	58 */
0x0000f68b, 0x00000020, /* 00000020 //C 0f68b  2015 db	32 */
0x0000f68c, 0x00000000, /* 00000000 //C 0f68c  2015 db */
0x0000f68d, 0x00000008, /* 00000008 //C 0f68d  2016 db	8 */
0x0000f68e, 0x00000020, /* 00000020 //C 0f68e  2016 db	32 */
0x0000f68f, 0x00000008, /* 00000008 //C 0f68f  2016 db	8 */
0x0000f690, 0x00000000, /* 00000000 //C 0f690  2016 db	0 */
0x0000f691, 0x0000003a, /* 0000003a //C 0f691  2017 db	58 */
0x0000f692, 0x00000000, /* 00000000 //C 0f692  2017 db */
0x0000f693, 0x00000020, /* 00000020 //C 0f693  2018 db	32 */
0x0000f694, 0x0000003b, /* 0000003b //C 0f694  2018 db	59 */
0x0000f695, 0x00000009, /* 00000009 //C 0f695  2018 db	9 */
0x0000f696, 0x0000000b, /* 0000000b //C 0f696  2018 db	11 */
0x0000f697, 0x0000002c, /* 0000002c //C 0f697  2018 db	44 */
0x0000f698, 0x0000003d, /* 0000003d //C 0f698  2018 db	61 */
0x0000f699, 0x0000005b, /* 0000005b //C 0f699  2018 db	91 */
0x0000f69a, 0x0000005d, /* 0000005d //C 0f69a  2018 db	93 */
0x0000f69b, 0x00000000, /* 00000000 //C 0f69b  2018 db */
0x0000f69c, 0x00000028, /* 00000028 //C 0f69c  2019 db	40 */
0x0000f69d, 0x0000006e, /* 0000006e //C 0f69d  2019 db	110 */
0x0000f69e, 0x00000075, /* 00000075 //C 0f69e  2019 db	117 */
0x0000f69f, 0x0000006c, /* 0000006c //C 0f69f  2019 db	108 */
0x0000f6a0, 0x0000006c, /* 0000006c //C 0f6a0  2019 db	108 */
0x0000f6a1, 0x00000029, /* 00000029 //C 0f6a1  2019 db	41 */
0x0000f6a2, 0x00000000, /* 00000000 //C 0f6a2  2019 db */
0x0000f6a3, 0x00000000, /* 00000000 //C 0f6a3  2020 db	0 */
0x0000f6a4, 0x00000000, /* 00000000 //C 0f6a4  2021 db	0 */
0x0000f6a5, 0x00000000, /* 00000000 //C 0f6a5  2022 sc_buffer:	ds	10 */
0x0000f6af, 0x0000f194, /* 0000f194 //C 0f6af  2026 dd	cmd_sm */
0x0000f6b0, 0x00000073, /* 00000073 //C 0f6b0  2027 db	115 */
0x0000f6b1, 0x0000006d, /* 0000006d //C 0f6b1  2027 db	109 */
0x0000f6b2, 0x00000000, /* 00000000 //C 0f6b2  2027 db */
0x0000f6b3, 0x0000f13b, /* 0000f13b //C 0f6b3  2028 dd	cmd_m */
0x0000f6b4, 0x0000006d, /* 0000006d //C 0f6b4  2029 db	109 */
0x0000f6b5, 0x00000000, /* 00000000 //C 0f6b5  2029 db */
0x0000f6b6, 0x0000f13b, /* 0000f13b //C 0f6b6  2030 dd	cmd_m */
0x0000f6b7, 0x0000006d, /* 0000006d //C 0f6b7  2031 db	109 */
0x0000f6b8, 0x00000065, /* 00000065 //C 0f6b8  2031 db	101 */
0x0000f6b9, 0x0000006d, /* 0000006d //C 0f6b9  2031 db	109 */
0x0000f6ba, 0x00000000, /* 00000000 //C 0f6ba  2031 db */
0x0000f6bb, 0x0000f1b7, /* 0000f1b7 //C 0f6bb  2032 dd	cmd_d */
0x0000f6bc, 0x00000064, /* 00000064 //C 0f6bc  2033 db	100 */
0x0000f6bd, 0x00000000, /* 00000000 //C 0f6bd  2033 db */
0x0000f6be, 0x0000f1b7, /* 0000f1b7 //C 0f6be  2034 dd	cmd_d */
0x0000f6bf, 0x00000064, /* 00000064 //C 0f6bf  2035 db	100 */
0x0000f6c0, 0x00000075, /* 00000075 //C 0f6c0  2035 db	117 */
0x0000f6c1, 0x0000006d, /* 0000006d //C 0f6c1  2035 db	109 */
0x0000f6c2, 0x00000070, /* 00000070 //C 0f6c2  2035 db	112 */
0x0000f6c3, 0x00000000, /* 00000000 //C 0f6c3  2035 db */
0x0000f6c4, 0x0000f1ea, /* 0000f1ea //C 0f6c4  2036 dd	cmd_l */
0x0000f6c5, 0x0000006c, /* 0000006c //C 0f6c5  2037 db	108 */
0x0000f6c6, 0x00000000, /* 00000000 //C 0f6c6  2037 db */
0x0000f6c7, 0x0000f1ea, /* 0000f1ea //C 0f6c7  2038 dd	cmd_l */
0x0000f6c8, 0x0000006c, /* 0000006c //C 0f6c8  2039 db	108 */
0x0000f6c9, 0x0000006f, /* 0000006f //C 0f6c9  2039 db	111 */
0x0000f6ca, 0x00000061, /* 00000061 //C 0f6ca  2039 db	97 */
0x0000f6cb, 0x00000064, /* 00000064 //C 0f6cb  2039 db	100 */
0x0000f6cc, 0x00000000, /* 00000000 //C 0f6cc  2039 db */
0x0000f6cd, 0x0000f260, /* 0000f260 //C 0f6cd  2040 dd	cmd_g */
0x0000f6ce, 0x00000067, /* 00000067 //C 0f6ce  2041 db	103 */
0x0000f6cf, 0x00000000, /* 00000000 //C 0f6cf  2041 db */
0x0000f6d0, 0x0000f260, /* 0000f260 //C 0f6d0  2042 dd	cmd_g */
0x0000f6d1, 0x00000067, /* 00000067 //C 0f6d1  2043 db	103 */
0x0000f6d2, 0x0000006f, /* 0000006f //C 0f6d2  2043 db	111 */
0x0000f6d3, 0x00000000, /* 00000000 //C 0f6d3  2043 db */
0x0000f6d4, 0x0000f260, /* 0000f260 //C 0f6d4  2044 dd	cmd_g */
0x0000f6d5, 0x00000072, /* 00000072 //C 0f6d5  2045 db	114 */
0x0000f6d6, 0x00000075, /* 00000075 //C 0f6d6  2045 db	117 */
0x0000f6d7, 0x0000006e, /* 0000006e //C 0f6d7  2045 db	110 */
0x0000f6d8, 0x00000000, /* 00000000 //C 0f6d8  2045 db */
0x0000f6d9, 0x0000f29f, /* 0000f29f //C 0f6d9  2046 dd	cmd_h */
0x0000f6da, 0x0000003f, /* 0000003f //C 0f6da  2047 db	63 */
0x0000f6db, 0x00000000, /* 00000000 //C 0f6db  2047 db */
0x0000f6dc, 0x0000f29f, /* 0000f29f //C 0f6dc  2048 dd	cmd_h */
0x0000f6dd, 0x00000068, /* 00000068 //C 0f6dd  2049 db	104 */
0x0000f6de, 0x00000000, /* 00000000 //C 0f6de  2049 db */
0x0000f6df, 0x0000f29f, /* 0000f29f //C 0f6df  2050 dd	cmd_h */
0x0000f6e0, 0x00000068, /* 00000068 //C 0f6e0  2051 db	104 */
0x0000f6e1, 0x00000065, /* 00000065 //C 0f6e1  2051 db	101 */
0x0000f6e2, 0x0000006c, /* 0000006c //C 0f6e2  2051 db	108 */
0x0000f6e3, 0x00000070, /* 00000070 //C 0f6e3  2051 db	112 */
0x0000f6e4, 0x00000000, /* 00000000 //C 0f6e4  2051 db */
0x0000f6e5, 0x0000f306, /* 0000f306 //C 0f6e5  2052 dd	cmd_r */
0x0000f6e6, 0x00000072, /* 00000072 //C 0f6e6  2053 db	114 */
0x0000f6e7, 0x00000000, /* 00000000 //C 0f6e7  2053 db */
0x0000f6e8, 0x0000f306, /* 0000f306 //C 0f6e8  2054 dd	cmd_r */
0x0000f6e9, 0x00000072, /* 00000072 //C 0f6e9  2055 db	114 */
0x0000f6ea, 0x00000065, /* 00000065 //C 0f6ea  2055 db	101 */
0x0000f6eb, 0x00000067, /* 00000067 //C 0f6eb  2055 db	103 */
0x0000f6ec, 0x00000000, /* 00000000 //C 0f6ec  2055 db */
0x0000f6ed, 0x0000f306, /* 0000f306 //C 0f6ed  2056 dd	cmd_r */
0x0000f6ee, 0x00000072, /* 00000072 //C 0f6ee  2057 db	114 */
0x0000f6ef, 0x00000065, /* 00000065 //C 0f6ef  2057 db	101 */
0x0000f6f0, 0x00000067, /* 00000067 //C 0f6f0  2057 db	103 */
0x0000f6f1, 0x00000073, /* 00000073 //C 0f6f1  2057 db	115 */
0x0000f6f2, 0x00000000, /* 00000000 //C 0f6f2  2057 db */
0x0000f6f3, 0x0000f396, /* 0000f396 //C 0f6f3  2058 dd	cmd_sp */
0x0000f6f4, 0x00000073, /* 00000073 //C 0f6f4  2059 db	115 */
0x0000f6f5, 0x00000070, /* 00000070 //C 0f6f5  2059 db	112 */
0x0000f6f6, 0x00000000, /* 00000000 //C 0f6f6  2059 db */
0x0000f6f7, 0x0000f399, /* 0000f399 //C 0f6f7  2060 dd	cmd_lr */
0x0000f6f8, 0x0000006c, /* 0000006c //C 0f6f8  2061 db	108 */
0x0000f6f9, 0x00000072, /* 00000072 //C 0f6f9  2061 db	114 */
0x0000f6fa, 0x00000000, /* 00000000 //C 0f6fa  2061 db */
0x0000f6fb, 0x0000f39c, /* 0000f39c //C 0f6fb  2062 dd	cmd_pc */
0x0000f6fc, 0x00000070, /* 00000070 //C 0f6fc  2063 db	112 */
0x0000f6fd, 0x00000063, /* 00000063 //C 0f6fd  2063 db	99 */
0x0000f6fe, 0x00000000, /* 00000000 //C 0f6fe  2063 db */
0x0000f6ff, 0x0000f39f, /* 0000f39f //C 0f6ff  2064 dd	cmd_f */
0x0000f700, 0x00000066, /* 00000066 //C 0f700  2065 db	102 */
0x0000f701, 0x00000000, /* 00000000 //C 0f701  2065 db */
0x0000f702, 0x00000000, /* 00000000 //C 0f702  2066 dd	0 */
0x0000f703, 0x00000000, /* 00000000 //C 0f703  2067 dd	0 */
0x0000f704, 0x0000006d, /* 0000006d //C 0f704  2069 db	109 */
0x0000f705, 0x0000005b, /* 0000005b //C 0f705  2069 db	91 */
0x0000f706, 0x00000065, /* 00000065 //C 0f706  2069 db	101 */
0x0000f707, 0x0000006d, /* 0000006d //C 0f707  2069 db	109 */
0x0000f708, 0x0000005d, /* 0000005d //C 0f708  2069 db	93 */
0x0000f709, 0x00000020, /* 00000020 //C 0f709  2069 db	32 */
0x0000f70a, 0x00000061, /* 00000061 //C 0f70a  2069 db	97 */
0x0000f70b, 0x00000064, /* 00000064 //C 0f70b  2069 db	100 */
0x0000f70c, 0x00000064, /* 00000064 //C 0f70c  2069 db	100 */
0x0000f70d, 0x00000072, /* 00000072 //C 0f70d  2069 db	114 */
0x0000f70e, 0x00000020, /* 00000020 //C 0f70e  2069 db	32 */
0x0000f70f, 0x0000005b, /* 0000005b //C 0f70f  2069 db	91 */
0x0000f710, 0x00000076, /* 00000076 //C 0f710  2069 db	118 */
0x0000f711, 0x00000061, /* 00000061 //C 0f711  2069 db	97 */
0x0000f712, 0x0000006c, /* 0000006c //C 0f712  2069 db	108 */
0x0000f713, 0x0000005d, /* 0000005d //C 0f713  2069 db	93 */
0x0000f714, 0x00000020, /* 00000020 //C 0f714  2069 db	32 */
0x0000f715, 0x00000020, /* 00000020 //C 0f715  2069 db	32 */
0x0000f716, 0x00000047, /* 00000047 //C 0f716  2069 db	71 */
0x0000f717, 0x00000065, /* 00000065 //C 0f717  2069 db	101 */
0x0000f718, 0x00000074, /* 00000074 //C 0f718  2069 db	116 */
0x0000f719, 0x0000002f, /* 0000002f //C 0f719  2069 db	47 */
0x0000f71a, 0x00000073, /* 00000073 //C 0f71a  2069 db	115 */
0x0000f71b, 0x00000065, /* 00000065 //C 0f71b  2069 db	101 */
0x0000f71c, 0x00000074, /* 00000074 //C 0f71c  2069 db	116 */
0x0000f71d, 0x00000020, /* 00000020 //C 0f71d  2069 db	32 */
0x0000f71e, 0x0000006d, /* 0000006d //C 0f71e  2069 db	109 */
0x0000f71f, 0x00000065, /* 00000065 //C 0f71f  2069 db	101 */
0x0000f720, 0x0000006d, /* 0000006d //C 0f720  2069 db	109 */
0x0000f721, 0x0000006f, /* 0000006f //C 0f721  2069 db	111 */
0x0000f722, 0x00000072, /* 00000072 //C 0f722  2069 db	114 */
0x0000f723, 0x00000079, /* 00000079 //C 0f723  2069 db	121 */
0x0000f724, 0x0000000a, /* 0000000a //C 0f724  2069 db	10 */
0x0000f725, 0x00000000, /* 00000000 //C 0f725  2069 db */
0x0000f726, 0x00000064, /* 00000064 //C 0f726  2070 db	100 */
0x0000f727, 0x0000005b, /* 0000005b //C 0f727  2070 db	91 */
0x0000f728, 0x00000075, /* 00000075 //C 0f728  2070 db	117 */
0x0000f729, 0x0000006d, /* 0000006d //C 0f729  2070 db	109 */
0x0000f72a, 0x00000070, /* 00000070 //C 0f72a  2070 db	112 */
0x0000f72b, 0x0000005d, /* 0000005d //C 0f72b  2070 db	93 */
0x0000f72c, 0x00000020, /* 00000020 //C 0f72c  2070 db	32 */
0x0000f72d, 0x00000073, /* 00000073 //C 0f72d  2070 db	115 */
0x0000f72e, 0x00000074, /* 00000074 //C 0f72e  2070 db	116 */
0x0000f72f, 0x00000061, /* 00000061 //C 0f72f  2070 db	97 */
0x0000f730, 0x00000072, /* 00000072 //C 0f730  2070 db	114 */
0x0000f731, 0x00000074, /* 00000074 //C 0f731  2070 db	116 */
0x0000f732, 0x00000020, /* 00000020 //C 0f732  2070 db	32 */
0x0000f733, 0x00000065, /* 00000065 //C 0f733  2070 db	101 */
0x0000f734, 0x0000006e, /* 0000006e //C 0f734  2070 db	110 */
0x0000f735, 0x00000064, /* 00000064 //C 0f735  2070 db	100 */
0x0000f736, 0x00000020, /* 00000020 //C 0f736  2070 db	32 */
0x0000f737, 0x00000020, /* 00000020 //C 0f737  2070 db	32 */
0x0000f738, 0x00000044, /* 00000044 //C 0f738  2070 db	68 */
0x0000f739, 0x00000075, /* 00000075 //C 0f739  2070 db	117 */
0x0000f73a, 0x0000006d, /* 0000006d //C 0f73a  2070 db	109 */
0x0000f73b, 0x00000070, /* 00000070 //C 0f73b  2070 db	112 */
0x0000f73c, 0x00000020, /* 00000020 //C 0f73c  2070 db	32 */
0x0000f73d, 0x0000006d, /* 0000006d //C 0f73d  2070 db	109 */
0x0000f73e, 0x00000065, /* 00000065 //C 0f73e  2070 db	101 */
0x0000f73f, 0x0000006d, /* 0000006d //C 0f73f  2070 db	109 */
0x0000f740, 0x0000006f, /* 0000006f //C 0f740  2070 db	111 */
0x0000f741, 0x00000072, /* 00000072 //C 0f741  2070 db	114 */
0x0000f742, 0x00000079, /* 00000079 //C 0f742  2070 db	121 */
0x0000f743, 0x00000020, /* 00000020 //C 0f743  2070 db	32 */
0x0000f744, 0x00000063, /* 00000063 //C 0f744  2070 db	99 */
0x0000f745, 0x0000006f, /* 0000006f //C 0f745  2070 db	111 */
0x0000f746, 0x0000006e, /* 0000006e //C 0f746  2070 db	110 */
0x0000f747, 0x00000074, /* 00000074 //C 0f747  2070 db	116 */
0x0000f748, 0x00000065, /* 00000065 //C 0f748  2070 db	101 */
0x0000f749, 0x0000006e, /* 0000006e //C 0f749  2070 db	110 */
0x0000f74a, 0x00000074, /* 00000074 //C 0f74a  2070 db	116 */
0x0000f74b, 0x0000000a, /* 0000000a //C 0f74b  2070 db	10 */
0x0000f74c, 0x00000000, /* 00000000 //C 0f74c  2070 db */
0x0000f74d, 0x0000006c, /* 0000006c //C 0f74d  2071 db	108 */
0x0000f74e, 0x0000005b, /* 0000005b //C 0f74e  2071 db	91 */
0x0000f74f, 0x0000006f, /* 0000006f //C 0f74f  2071 db	111 */
0x0000f750, 0x00000061, /* 00000061 //C 0f750  2071 db	97 */
0x0000f751, 0x00000064, /* 00000064 //C 0f751  2071 db	100 */
0x0000f752, 0x0000005d, /* 0000005d //C 0f752  2071 db	93 */
0x0000f753, 0x00000020, /* 00000020 //C 0f753  2071 db	32 */
0x0000f754, 0x00000020, /* 00000020 //C 0f754  2071 db	32 */
0x0000f755, 0x00000020, /* 00000020 //C 0f755  2071 db	32 */
0x0000f756, 0x00000020, /* 00000020 //C 0f756  2071 db	32 */
0x0000f757, 0x00000020, /* 00000020 //C 0f757  2071 db	32 */
0x0000f758, 0x00000020, /* 00000020 //C 0f758  2071 db	32 */
0x0000f759, 0x00000020, /* 00000020 //C 0f759  2071 db	32 */
0x0000f75a, 0x00000020, /* 00000020 //C 0f75a  2071 db	32 */
0x0000f75b, 0x00000020, /* 00000020 //C 0f75b  2071 db	32 */
0x0000f75c, 0x00000020, /* 00000020 //C 0f75c  2071 db	32 */
0x0000f75d, 0x00000020, /* 00000020 //C 0f75d  2071 db	32 */
0x0000f75e, 0x00000020, /* 00000020 //C 0f75e  2071 db	32 */
0x0000f75f, 0x0000004c, /* 0000004c //C 0f75f  2071 db	76 */
0x0000f760, 0x0000006f, /* 0000006f //C 0f760  2071 db	111 */
0x0000f761, 0x00000061, /* 00000061 //C 0f761  2071 db	97 */
0x0000f762, 0x00000064, /* 00000064 //C 0f762  2071 db	100 */
0x0000f763, 0x00000020, /* 00000020 //C 0f763  2071 db	32 */
0x0000f764, 0x00000068, /* 00000068 //C 0f764  2071 db	104 */
0x0000f765, 0x00000065, /* 00000065 //C 0f765  2071 db	101 */
0x0000f766, 0x00000078, /* 00000078 //C 0f766  2071 db	120 */
0x0000f767, 0x00000020, /* 00000020 //C 0f767  2071 db	32 */
0x0000f768, 0x00000066, /* 00000066 //C 0f768  2071 db	102 */
0x0000f769, 0x00000069, /* 00000069 //C 0f769  2071 db	105 */
0x0000f76a, 0x0000006c, /* 0000006c //C 0f76a  2071 db	108 */
0x0000f76b, 0x00000065, /* 00000065 //C 0f76b  2071 db	101 */
0x0000f76c, 0x00000020, /* 00000020 //C 0f76c  2071 db	32 */
0x0000f76d, 0x00000074, /* 00000074 //C 0f76d  2071 db	116 */
0x0000f76e, 0x0000006f, /* 0000006f //C 0f76e  2071 db	111 */
0x0000f76f, 0x00000020, /* 00000020 //C 0f76f  2071 db	32 */
0x0000f770, 0x0000006d, /* 0000006d //C 0f770  2071 db	109 */
0x0000f771, 0x00000065, /* 00000065 //C 0f771  2071 db	101 */
0x0000f772, 0x0000006d, /* 0000006d //C 0f772  2071 db	109 */
0x0000f773, 0x0000006f, /* 0000006f //C 0f773  2071 db	111 */
0x0000f774, 0x00000072, /* 00000072 //C 0f774  2071 db	114 */
0x0000f775, 0x00000079, /* 00000079 //C 0f775  2071 db	121 */
0x0000f776, 0x0000000a, /* 0000000a //C 0f776  2071 db	10 */
0x0000f777, 0x00000000, /* 00000000 //C 0f777  2071 db */
0x0000f778, 0x00000067, /* 00000067 //C 0f778  2072 db	103 */
0x0000f779, 0x0000005b, /* 0000005b //C 0f779  2072 db	91 */
0x0000f77a, 0x0000006f, /* 0000006f //C 0f77a  2072 db	111 */
0x0000f77b, 0x0000005d, /* 0000005d //C 0f77b  2072 db	93 */
0x0000f77c, 0x0000007c, /* 0000007c //C 0f77c  2072 db	124 */
0x0000f77d, 0x00000072, /* 00000072 //C 0f77d  2072 db	114 */
0x0000f77e, 0x00000075, /* 00000075 //C 0f77e  2072 db	117 */
0x0000f77f, 0x0000006e, /* 0000006e //C 0f77f  2072 db	110 */
0x0000f780, 0x00000020, /* 00000020 //C 0f780  2072 db	32 */
0x0000f781, 0x0000005b, /* 0000005b //C 0f781  2072 db	91 */
0x0000f782, 0x00000061, /* 00000061 //C 0f782  2072 db	97 */
0x0000f783, 0x00000064, /* 00000064 //C 0f783  2072 db	100 */
0x0000f784, 0x00000064, /* 00000064 //C 0f784  2072 db	100 */
0x0000f785, 0x00000072, /* 00000072 //C 0f785  2072 db	114 */
0x0000f786, 0x0000005d, /* 0000005d //C 0f786  2072 db	93 */
0x0000f787, 0x00000020, /* 00000020 //C 0f787  2072 db	32 */
0x0000f788, 0x00000020, /* 00000020 //C 0f788  2072 db	32 */
0x0000f789, 0x00000020, /* 00000020 //C 0f789  2072 db	32 */
0x0000f78a, 0x00000052, /* 00000052 //C 0f78a  2072 db	82 */
0x0000f78b, 0x00000075, /* 00000075 //C 0f78b  2072 db	117 */
0x0000f78c, 0x0000006e, /* 0000006e //C 0f78c  2072 db	110 */
0x0000f78d, 0x00000020, /* 00000020 //C 0f78d  2072 db	32 */
0x0000f78e, 0x00000066, /* 00000066 //C 0f78e  2072 db	102 */
0x0000f78f, 0x00000072, /* 00000072 //C 0f78f  2072 db	114 */
0x0000f790, 0x0000006f, /* 0000006f //C 0f790  2072 db	111 */
0x0000f791, 0x0000006d, /* 0000006d //C 0f791  2072 db	109 */
0x0000f792, 0x00000020, /* 00000020 //C 0f792  2072 db	32 */
0x0000f793, 0x00000061, /* 00000061 //C 0f793  2072 db	97 */
0x0000f794, 0x00000064, /* 00000064 //C 0f794  2072 db	100 */
0x0000f795, 0x00000064, /* 00000064 //C 0f795  2072 db	100 */
0x0000f796, 0x00000072, /* 00000072 //C 0f796  2072 db	114 */
0x0000f797, 0x00000065, /* 00000065 //C 0f797  2072 db	101 */
0x0000f798, 0x00000073, /* 00000073 //C 0f798  2072 db	115 */
0x0000f799, 0x00000073, /* 00000073 //C 0f799  2072 db	115 */
0x0000f79a, 0x0000000a, /* 0000000a //C 0f79a  2072 db	10 */
0x0000f79b, 0x00000000, /* 00000000 //C 0f79b  2072 db */
0x0000f79c, 0x00000072, /* 00000072 //C 0f79c  2073 db	114 */
0x0000f79d, 0x0000005b, /* 0000005b //C 0f79d  2073 db	91 */
0x0000f79e, 0x00000065, /* 00000065 //C 0f79e  2073 db	101 */
0x0000f79f, 0x00000067, /* 00000067 //C 0f79f  2073 db	103 */
0x0000f7a0, 0x0000005b, /* 0000005b //C 0f7a0  2073 db	91 */
0x0000f7a1, 0x00000073, /* 00000073 //C 0f7a1  2073 db	115 */
0x0000f7a2, 0x0000005d, /* 0000005d //C 0f7a2  2073 db	93 */
0x0000f7a3, 0x0000005d, /* 0000005d //C 0f7a3  2073 db	93 */
0x0000f7a4, 0x00000020, /* 00000020 //C 0f7a4  2073 db	32 */
0x0000f7a5, 0x00000020, /* 00000020 //C 0f7a5  2073 db	32 */
0x0000f7a6, 0x00000020, /* 00000020 //C 0f7a6  2073 db	32 */
0x0000f7a7, 0x00000020, /* 00000020 //C 0f7a7  2073 db	32 */
0x0000f7a8, 0x00000020, /* 00000020 //C 0f7a8  2073 db	32 */
0x0000f7a9, 0x00000020, /* 00000020 //C 0f7a9  2073 db	32 */
0x0000f7aa, 0x00000020, /* 00000020 //C 0f7aa  2073 db	32 */
0x0000f7ab, 0x00000020, /* 00000020 //C 0f7ab  2073 db	32 */
0x0000f7ac, 0x00000020, /* 00000020 //C 0f7ac  2073 db	32 */
0x0000f7ad, 0x00000020, /* 00000020 //C 0f7ad  2073 db	32 */
0x0000f7ae, 0x00000050, /* 00000050 //C 0f7ae  2073 db	80 */
0x0000f7af, 0x00000072, /* 00000072 //C 0f7af  2073 db	114 */
0x0000f7b0, 0x00000069, /* 00000069 //C 0f7b0  2073 db	105 */
0x0000f7b1, 0x0000006e, /* 0000006e //C 0f7b1  2073 db	110 */
0x0000f7b2, 0x00000074, /* 00000074 //C 0f7b2  2073 db	116 */
0x0000f7b3, 0x00000020, /* 00000020 //C 0f7b3  2073 db	32 */
0x0000f7b4, 0x00000072, /* 00000072 //C 0f7b4  2073 db	114 */
0x0000f7b5, 0x00000065, /* 00000065 //C 0f7b5  2073 db	101 */
0x0000f7b6, 0x00000067, /* 00000067 //C 0f7b6  2073 db	103 */
0x0000f7b7, 0x00000069, /* 00000069 //C 0f7b7  2073 db	105 */
0x0000f7b8, 0x00000073, /* 00000073 //C 0f7b8  2073 db	115 */
0x0000f7b9, 0x00000074, /* 00000074 //C 0f7b9  2073 db	116 */
0x0000f7ba, 0x00000065, /* 00000065 //C 0f7ba  2073 db	101 */
0x0000f7bb, 0x00000072, /* 00000072 //C 0f7bb  2073 db	114 */
0x0000f7bc, 0x00000073, /* 00000073 //C 0f7bc  2073 db	115 */
0x0000f7bd, 0x0000000a, /* 0000000a //C 0f7bd  2073 db	10 */
0x0000f7be, 0x00000000, /* 00000000 //C 0f7be  2073 db */
0x0000f7bf, 0x00000072, /* 00000072 //C 0f7bf  2074 db	114 */
0x0000f7c0, 0x00000058, /* 00000058 //C 0f7c0  2074 db	88 */
0x0000f7c1, 0x00000020, /* 00000020 //C 0f7c1  2074 db	32 */
0x0000f7c2, 0x0000005b, /* 0000005b //C 0f7c2  2074 db	91 */
0x0000f7c3, 0x00000076, /* 00000076 //C 0f7c3  2074 db	118 */
0x0000f7c4, 0x00000061, /* 00000061 //C 0f7c4  2074 db	97 */
0x0000f7c5, 0x0000006c, /* 0000006c //C 0f7c5  2074 db	108 */
0x0000f7c6, 0x0000005d, /* 0000005d //C 0f7c6  2074 db	93 */
0x0000f7c7, 0x00000020, /* 00000020 //C 0f7c7  2074 db	32 */
0x0000f7c8, 0x00000020, /* 00000020 //C 0f7c8  2074 db	32 */
0x0000f7c9, 0x00000020, /* 00000020 //C 0f7c9  2074 db	32 */
0x0000f7ca, 0x00000020, /* 00000020 //C 0f7ca  2074 db	32 */
0x0000f7cb, 0x00000020, /* 00000020 //C 0f7cb  2074 db	32 */
0x0000f7cc, 0x00000020, /* 00000020 //C 0f7cc  2074 db	32 */
0x0000f7cd, 0x00000020, /* 00000020 //C 0f7cd  2074 db	32 */
0x0000f7ce, 0x00000020, /* 00000020 //C 0f7ce  2074 db	32 */
0x0000f7cf, 0x00000020, /* 00000020 //C 0f7cf  2074 db	32 */
0x0000f7d0, 0x00000020, /* 00000020 //C 0f7d0  2074 db	32 */
0x0000f7d1, 0x00000047, /* 00000047 //C 0f7d1  2074 db	71 */
0x0000f7d2, 0x00000065, /* 00000065 //C 0f7d2  2074 db	101 */
0x0000f7d3, 0x00000074, /* 00000074 //C 0f7d3  2074 db	116 */
0x0000f7d4, 0x0000002f, /* 0000002f //C 0f7d4  2074 db	47 */
0x0000f7d5, 0x00000073, /* 00000073 //C 0f7d5  2074 db	115 */
0x0000f7d6, 0x00000065, /* 00000065 //C 0f7d6  2074 db	101 */
0x0000f7d7, 0x00000074, /* 00000074 //C 0f7d7  2074 db	116 */
0x0000f7d8, 0x00000020, /* 00000020 //C 0f7d8  2074 db	32 */
0x0000f7d9, 0x00000052, /* 00000052 //C 0f7d9  2074 db	82 */
0x0000f7da, 0x00000058, /* 00000058 //C 0f7da  2074 db	88 */
0x0000f7db, 0x0000000a, /* 0000000a //C 0f7db  2074 db	10 */
0x0000f7dc, 0x00000000, /* 00000000 //C 0f7dc  2074 db */
0x0000f7dd, 0x00000073, /* 00000073 //C 0f7dd  2075 db	115 */
0x0000f7de, 0x00000070, /* 00000070 //C 0f7de  2075 db	112 */
0x0000f7df, 0x00000020, /* 00000020 //C 0f7df  2075 db	32 */
0x0000f7e0, 0x0000005b, /* 0000005b //C 0f7e0  2075 db	91 */
0x0000f7e1, 0x00000076, /* 00000076 //C 0f7e1  2075 db	118 */
0x0000f7e2, 0x00000061, /* 00000061 //C 0f7e2  2075 db	97 */
0x0000f7e3, 0x0000006c, /* 0000006c //C 0f7e3  2075 db	108 */
0x0000f7e4, 0x0000005d, /* 0000005d //C 0f7e4  2075 db	93 */
0x0000f7e5, 0x00000020, /* 00000020 //C 0f7e5  2075 db	32 */
0x0000f7e6, 0x00000020, /* 00000020 //C 0f7e6  2075 db	32 */
0x0000f7e7, 0x00000020, /* 00000020 //C 0f7e7  2075 db	32 */
0x0000f7e8, 0x00000020, /* 00000020 //C 0f7e8  2075 db	32 */
0x0000f7e9, 0x00000020, /* 00000020 //C 0f7e9  2075 db	32 */
0x0000f7ea, 0x00000020, /* 00000020 //C 0f7ea  2075 db	32 */
0x0000f7eb, 0x00000020, /* 00000020 //C 0f7eb  2075 db	32 */
0x0000f7ec, 0x00000020, /* 00000020 //C 0f7ec  2075 db	32 */
0x0000f7ed, 0x00000020, /* 00000020 //C 0f7ed  2075 db	32 */
0x0000f7ee, 0x00000020, /* 00000020 //C 0f7ee  2075 db	32 */
0x0000f7ef, 0x00000047, /* 00000047 //C 0f7ef  2075 db	71 */
0x0000f7f0, 0x00000065, /* 00000065 //C 0f7f0  2075 db	101 */
0x0000f7f1, 0x00000074, /* 00000074 //C 0f7f1  2075 db	116 */
0x0000f7f2, 0x0000002f, /* 0000002f //C 0f7f2  2075 db	47 */
0x0000f7f3, 0x00000073, /* 00000073 //C 0f7f3  2075 db	115 */
0x0000f7f4, 0x00000065, /* 00000065 //C 0f7f4  2075 db	101 */
0x0000f7f5, 0x00000074, /* 00000074 //C 0f7f5  2075 db	116 */
0x0000f7f6, 0x00000020, /* 00000020 //C 0f7f6  2075 db	32 */
0x0000f7f7, 0x00000052, /* 00000052 //C 0f7f7  2075 db	82 */
0x0000f7f8, 0x00000031, /* 00000031 //C 0f7f8  2075 db	49 */
0x0000f7f9, 0x00000033, /* 00000033 //C 0f7f9  2075 db	51 */
0x0000f7fa, 0x0000000a, /* 0000000a //C 0f7fa  2075 db	10 */
0x0000f7fb, 0x00000000, /* 00000000 //C 0f7fb  2075 db */
0x0000f7fc, 0x0000006c, /* 0000006c //C 0f7fc  2076 db	108 */
0x0000f7fd, 0x00000072, /* 00000072 //C 0f7fd  2076 db	114 */
0x0000f7fe, 0x00000020, /* 00000020 //C 0f7fe  2076 db	32 */
0x0000f7ff, 0x0000005b, /* 0000005b //C 0f7ff  2076 db	91 */
0x0000f800, 0x00000076, /* 00000076 //C 0f800  2076 db	118 */
0x0000f801, 0x00000061, /* 00000061 //C 0f801  2076 db	97 */
0x0000f802, 0x0000006c, /* 0000006c //C 0f802  2076 db	108 */
0x0000f803, 0x0000005d, /* 0000005d //C 0f803  2076 db	93 */
0x0000f804, 0x00000020, /* 00000020 //C 0f804  2076 db	32 */
0x0000f805, 0x00000020, /* 00000020 //C 0f805  2076 db	32 */
0x0000f806, 0x00000020, /* 00000020 //C 0f806  2076 db	32 */
0x0000f807, 0x00000020, /* 00000020 //C 0f807  2076 db	32 */
0x0000f808, 0x00000020, /* 00000020 //C 0f808  2076 db	32 */
0x0000f809, 0x00000020, /* 00000020 //C 0f809  2076 db	32 */
0x0000f80a, 0x00000020, /* 00000020 //C 0f80a  2076 db	32 */
0x0000f80b, 0x00000020, /* 00000020 //C 0f80b  2076 db	32 */
0x0000f80c, 0x00000020, /* 00000020 //C 0f80c  2076 db	32 */
0x0000f80d, 0x00000020, /* 00000020 //C 0f80d  2076 db	32 */
0x0000f80e, 0x00000047, /* 00000047 //C 0f80e  2076 db	71 */
0x0000f80f, 0x00000065, /* 00000065 //C 0f80f  2076 db	101 */
0x0000f810, 0x00000074, /* 00000074 //C 0f810  2076 db	116 */
0x0000f811, 0x0000002f, /* 0000002f //C 0f811  2076 db	47 */
0x0000f812, 0x00000073, /* 00000073 //C 0f812  2076 db	115 */
0x0000f813, 0x00000065, /* 00000065 //C 0f813  2076 db	101 */
0x0000f814, 0x00000074, /* 00000074 //C 0f814  2076 db	116 */
0x0000f815, 0x00000020, /* 00000020 //C 0f815  2076 db	32 */
0x0000f816, 0x00000052, /* 00000052 //C 0f816  2076 db	82 */
0x0000f817, 0x00000031, /* 00000031 //C 0f817  2076 db	49 */
0x0000f818, 0x00000034, /* 00000034 //C 0f818  2076 db	52 */
0x0000f819, 0x0000000a, /* 0000000a //C 0f819  2076 db	10 */
0x0000f81a, 0x00000000, /* 00000000 //C 0f81a  2076 db */
0x0000f81b, 0x00000070, /* 00000070 //C 0f81b  2077 db	112 */
0x0000f81c, 0x00000063, /* 00000063 //C 0f81c  2077 db	99 */
0x0000f81d, 0x00000020, /* 00000020 //C 0f81d  2077 db	32 */
0x0000f81e, 0x0000005b, /* 0000005b //C 0f81e  2077 db	91 */
0x0000f81f, 0x00000076, /* 00000076 //C 0f81f  2077 db	118 */
0x0000f820, 0x00000061, /* 00000061 //C 0f820  2077 db	97 */
0x0000f821, 0x0000006c, /* 0000006c //C 0f821  2077 db	108 */
0x0000f822, 0x0000005d, /* 0000005d //C 0f822  2077 db	93 */
0x0000f823, 0x00000020, /* 00000020 //C 0f823  2077 db	32 */
0x0000f824, 0x00000020, /* 00000020 //C 0f824  2077 db	32 */
0x0000f825, 0x00000020, /* 00000020 //C 0f825  2077 db	32 */
0x0000f826, 0x00000020, /* 00000020 //C 0f826  2077 db	32 */
0x0000f827, 0x00000020, /* 00000020 //C 0f827  2077 db	32 */
0x0000f828, 0x00000020, /* 00000020 //C 0f828  2077 db	32 */
0x0000f829, 0x00000020, /* 00000020 //C 0f829  2077 db	32 */
0x0000f82a, 0x00000020, /* 00000020 //C 0f82a  2077 db	32 */
0x0000f82b, 0x00000020, /* 00000020 //C 0f82b  2077 db	32 */
0x0000f82c, 0x00000020, /* 00000020 //C 0f82c  2077 db	32 */
0x0000f82d, 0x00000047, /* 00000047 //C 0f82d  2077 db	71 */
0x0000f82e, 0x00000065, /* 00000065 //C 0f82e  2077 db	101 */
0x0000f82f, 0x00000074, /* 00000074 //C 0f82f  2077 db	116 */
0x0000f830, 0x0000002f, /* 0000002f //C 0f830  2077 db	47 */
0x0000f831, 0x00000073, /* 00000073 //C 0f831  2077 db	115 */
0x0000f832, 0x00000065, /* 00000065 //C 0f832  2077 db	101 */
0x0000f833, 0x00000074, /* 00000074 //C 0f833  2077 db	116 */
0x0000f834, 0x00000020, /* 00000020 //C 0f834  2077 db	32 */
0x0000f835, 0x00000052, /* 00000052 //C 0f835  2077 db	82 */
0x0000f836, 0x00000031, /* 00000031 //C 0f836  2077 db	49 */
0x0000f837, 0x00000035, /* 00000035 //C 0f837  2077 db	53 */
0x0000f838, 0x0000000a, /* 0000000a //C 0f838  2077 db	10 */
0x0000f839, 0x00000000, /* 00000000 //C 0f839  2077 db */
0x0000f83a, 0x00000066, /* 00000066 //C 0f83a  2078 db	102 */
0x0000f83b, 0x00000020, /* 00000020 //C 0f83b  2078 db	32 */
0x0000f83c, 0x0000005b, /* 0000005b //C 0f83c  2078 db	91 */
0x0000f83d, 0x00000076, /* 00000076 //C 0f83d  2078 db	118 */
0x0000f83e, 0x00000061, /* 00000061 //C 0f83e  2078 db	97 */
0x0000f83f, 0x0000006c, /* 0000006c //C 0f83f  2078 db	108 */
0x0000f840, 0x0000005d, /* 0000005d //C 0f840  2078 db	93 */
0x0000f841, 0x00000020, /* 00000020 //C 0f841  2078 db	32 */
0x0000f842, 0x00000020, /* 00000020 //C 0f842  2078 db	32 */
0x0000f843, 0x00000020, /* 00000020 //C 0f843  2078 db	32 */
0x0000f844, 0x00000020, /* 00000020 //C 0f844  2078 db	32 */
0x0000f845, 0x00000020, /* 00000020 //C 0f845  2078 db	32 */
0x0000f846, 0x00000020, /* 00000020 //C 0f846  2078 db	32 */
0x0000f847, 0x00000020, /* 00000020 //C 0f847  2078 db	32 */
0x0000f848, 0x00000020, /* 00000020 //C 0f848  2078 db	32 */
0x0000f849, 0x00000020, /* 00000020 //C 0f849  2078 db	32 */
0x0000f84a, 0x00000020, /* 00000020 //C 0f84a  2078 db	32 */
0x0000f84b, 0x00000020, /* 00000020 //C 0f84b  2078 db	32 */
0x0000f84c, 0x00000047, /* 00000047 //C 0f84c  2078 db	71 */
0x0000f84d, 0x00000065, /* 00000065 //C 0f84d  2078 db	101 */
0x0000f84e, 0x00000074, /* 00000074 //C 0f84e  2078 db	116 */
0x0000f84f, 0x0000002f, /* 0000002f //C 0f84f  2078 db	47 */
0x0000f850, 0x00000073, /* 00000073 //C 0f850  2078 db	115 */
0x0000f851, 0x00000065, /* 00000065 //C 0f851  2078 db	101 */
0x0000f852, 0x00000074, /* 00000074 //C 0f852  2078 db	116 */
0x0000f853, 0x00000020, /* 00000020 //C 0f853  2078 db	32 */
0x0000f854, 0x00000066, /* 00000066 //C 0f854  2078 db	102 */
0x0000f855, 0x0000006c, /* 0000006c //C 0f855  2078 db	108 */
0x0000f856, 0x00000061, /* 00000061 //C 0f856  2078 db	97 */
0x0000f857, 0x00000067, /* 00000067 //C 0f857  2078 db	103 */
0x0000f858, 0x00000073, /* 00000073 //C 0f858  2078 db	115 */
0x0000f859, 0x0000000a, /* 0000000a //C 0f859  2078 db	10 */
0x0000f85a, 0x00000000, /* 00000000 //C 0f85a  2078 db */
0x0000f85b, 0x00000068, /* 00000068 //C 0f85b  2079 db	104 */
0x0000f85c, 0x0000005b, /* 0000005b //C 0f85c  2079 db	91 */
0x0000f85d, 0x00000065, /* 00000065 //C 0f85d  2079 db	101 */
0x0000f85e, 0x0000006c, /* 0000006c //C 0f85e  2079 db	108 */
0x0000f85f, 0x00000070, /* 00000070 //C 0f85f  2079 db	112 */
0x0000f860, 0x0000005d, /* 0000005d //C 0f860  2079 db	93 */
0x0000f861, 0x0000002c, /* 0000002c //C 0f861  2079 db	44 */
0x0000f862, 0x0000003f, /* 0000003f //C 0f862  2079 db	63 */
0x0000f863, 0x00000020, /* 00000020 //C 0f863  2079 db	32 */
0x0000f864, 0x00000020, /* 00000020 //C 0f864  2079 db	32 */
0x0000f865, 0x00000020, /* 00000020 //C 0f865  2079 db	32 */
0x0000f866, 0x00000020, /* 00000020 //C 0f866  2079 db	32 */
0x0000f867, 0x00000020, /* 00000020 //C 0f867  2079 db	32 */
0x0000f868, 0x00000020, /* 00000020 //C 0f868  2079 db	32 */
0x0000f869, 0x00000020, /* 00000020 //C 0f869  2079 db	32 */
0x0000f86a, 0x00000020, /* 00000020 //C 0f86a  2079 db	32 */
0x0000f86b, 0x00000020, /* 00000020 //C 0f86b  2079 db	32 */
0x0000f86c, 0x00000020, /* 00000020 //C 0f86c  2079 db	32 */
0x0000f86d, 0x00000048, /* 00000048 //C 0f86d  2079 db	72 */
0x0000f86e, 0x00000065, /* 00000065 //C 0f86e  2079 db	101 */
0x0000f86f, 0x0000006c, /* 0000006c //C 0f86f  2079 db	108 */
0x0000f870, 0x00000070, /* 00000070 //C 0f870  2079 db	112 */
0x0000f871, 0x0000000a, /* 0000000a //C 0f871  2079 db	10 */
0x0000f872, 0x00000000, /* 00000000 //C 0f872  2079 db */
0x0000f873, 0x00000000, /* 00000000 //C 0f873  2080 dd	0 */
0x0000f874, 0x00000000, /* 00000000 //C 0f874  2086 ds	0x40 */
0x0000f8b4, 0x00000000, /* 00000000 //C 0f8b4  2088 ds	1 */
0x0000f8b5, 0x00000000, /* 00000000 //C 0f8b5     3  */
0xffffffff, 0xffffffff
};
