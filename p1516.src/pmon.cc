#include "pmon.h"

t_mem pmon[]= {
0x00000000, 0x01f2f823, /* 01f2f823 //C 00000 jmp	cold_start */
0x0000f800, 0x01f2f80d, /* 01f2f80d //C 0f800 _f800:	jmp	callin */
0x0000f801, 0x01f2fa17, /* 01f2fa17 //C 0f801 _f801:	jmp	strchr */
0x0000f802, 0x01f2fa52, /* 01f2fa52 //C 0f802 _f802:	jmp	streq */
0x0000f803, 0x01f2fa59, /* 01f2fa59 //C 0f803 _f803:	jmp	strieq */
0x0000f804, 0x01f2fa60, /* 01f2fa60 //C 0f804 _f804:	jmp	hexchar2value */
0x0000f805, 0x01f2fa8f, /* 01f2fa8f //C 0f805 _f805:	jmp	value2hexchar */
0x0000f806, 0x01f2fa94, /* 01f2fa94 //C 0f806 _f806:	jmp	htoi */
0x0000f807, 0x01f2fab6, /* 01f2fab6 //C 0f807 _f807:	jmp	check_uart */
0x0000f808, 0x01f2fabd, /* 01f2fabd //C 0f808 _f808:	jmp	read */
0x0000f809, 0x01f2fabf, /* 01f2fabf //C 0f809 _f809:	jmp	putchar */
0x0000f80a, 0x01f2fac6, /* 01f2fac6 //C 0f80a _f80a:	jmp	prints */
0x0000f80b, 0x01f2fada, /* 01f2fada //C 0f80b _f80b:	jmp	printsnl */
0x0000f80c, 0x01f2fae2, /* 01f2fae2 //C 0f80c _f80c:	jmp	print_vhex */
0x0000f80d, 0x0600fb76, /* 0600fb76 //C 0f80d st	r0,reg0 */
0x0000f80e, 0x0610fb77, /* 0610fb77 //C 0f80e st	r1,reg1 */
0x0000f80f, 0x0620fb78, /* 0620fb78 //C 0f80f st	r2,reg2 */
0x0000f810, 0x0630fb79, /* 0630fb79 //C 0f810 st	r3,reg3 */
0x0000f811, 0x0640fb7a, /* 0640fb7a //C 0f811 st	r4,reg4 */
0x0000f812, 0x0650fb7b, /* 0650fb7b //C 0f812 st	r5,reg5 */
0x0000f813, 0x0660fb7c, /* 0660fb7c //C 0f813 st	r6,reg6 */
0x0000f814, 0x0670fb7d, /* 0670fb7d //C 0f814 st	r7,reg7 */
0x0000f815, 0x0680fb7e, /* 0680fb7e //C 0f815 st	r8,reg8 */
0x0000f816, 0x0690fb7f, /* 0690fb7f //C 0f816 st	r9,reg9 */
0x0000f817, 0x06a0fb80, /* 06a0fb80 //C 0f817 st	r10,reg10 */
0x0000f818, 0x06b0fb81, /* 06b0fb81 //C 0f818 st	r11,reg11 */
0x0000f819, 0x06c0fb82, /* 06c0fb82 //C 0f819 st	r12,reg12 */
0x0000f81a, 0x06d0fb83, /* 06d0fb83 //C 0f81a st	r13,reg13 */
0x0000f81b, 0x06e0fb84, /* 06e0fb84 //C 0f81b st	r14,reg14 */
0x0000f81c, 0x06e0fb85, /* 06e0fb85 //C 0f81c st	r14,reg15 */
0x0000f81d, 0x020e0000, /* 020e0000 //C 0f81d getf	r0 */
0x0000f81e, 0x0600fb86, /* 0600fb86 //C 0f81e st	r0,regf */
0x0000f81f, 0x01020001, /* 01020001 //C 0f81f mvzl	r0,1 */
0x0000f820, 0x0600fb75, /* 0600fb75 //C 0f820 st	r0,called */
0x0000f821, 0x01f2f826, /* 01f2f826 //C 0f821 jmp	common_start */
0x0000f822, 0x01f2f826, /* 01f2f826 //C 0f822 jmp	common_start */
0x0000f823, 0x01020000, /* 01020000 //C 0f823 mvzl	r0,0 */
0x0000f824, 0x0600fb75, /* 0600fb75 //C 0f824 st	r0,called */
0x0000f825, 0x01f2f826, /* 01f2f826 //C 0f825 jmp	common_start: */
0x0000f826, 0x01d2fd86, /* 01d2fd86 //C 0f826 mvzl	sp,stack_end */
0x0000f827, 0x01020001, /* 01020001 //C 0f827 mvzl	r0,1 */
0x0000f828, 0x0600fb74, /* 0600fb74 //C 0f828 st	r0,echo */
0x0000f829, 0x01020000, /* 01020000 //C 0f829 mvzl	r0,0 */
0x0000f82a, 0x020f0000, /* 020f0000 //C 0f82a setf	r0 */
0x0000f82b, 0x011200d9, /* 011200d9 //C 0f82b mvzl	r1,217 */
0x0000f82c, 0x0610ff44, /* 0610ff44 //C 0f82c st	r1,UART_CPB */
0x0000f82d, 0x01120003, /* 01120003 //C 0f82d mvzl	r1,3 */
0x0000f82e, 0x0610ff41, /* 0610ff41 //C 0f82e st	r1,UART_CTRL */
0x0000f82f, 0x0102fb87, /* 0102fb87 //C 0f82f mvzl	r0,msg_start */
0x0000f830, 0x0400fada, /* 0400fada //C 0f830 call	printsnl */
0x0000f831, 0x0400f833, /* 0400f833 //C 0f831 call	setup_line */
0x0000f832, 0x01f2f83d, /* 01f2f83d //C 0f832 jmp	main */
0x0000f833, 0x0ded0000, /* 0ded0000 //C 0f833 push	lr */
0x0000f834, 0x01120000, /* 01120000 //C 0f834 mvzl	r1,0		; lptr= 0 */
0x0000f835, 0x0610fb6d, /* 0610fb6d //C 0f835 st	r1,line_ptr */
0x0000f836, 0x0610fb09, /* 0610fb09 //C 0f836 st	r1,line		; line[0]= 0 */
0x0000f837, 0x01120001, /* 01120001 //C 0f837 mvzl	r1,1		; at_eol= 1 */
0x0000f838, 0x0610fb6e, /* 0610fb6e //C 0f838 st	r1,at_eol */
0x0000f839, 0x0102fb95, /* 0102fb95 //C 0f839 mvzl	r0,prompt */
0x0000f83a, 0x0400fac6, /* 0400fac6 //C 0f83a call	prints */
0x0000f83b, 0x0fed0000, /* 0fed0000 //C 0f83b pop	lr */
0x0000f83c, 0x00f00e00, /* 00f00e00 //C 0f83c ret */
0x0000f83d, 0x0400fab6, /* 0400fab6 //C 0f83d call	check_uart */
0x0000f83e, 0x41f2f844, /* 41f2f844 //C 0f83e C0 jmp	no_input */
0x0000f83f, 0x0400fabd, /* 0400fabd //C 0f83f call	read */
0x0000f840, 0x0400f845, /* 0400f845 //C 0f840 call	proc_input */
0x0000f841, 0x41f2f844, /* 41f2f844 //C 0f841 C0 jmp	no_line */
0x0000f842, 0x0400f862, /* 0400f862 //C 0f842 call	proc_line */
0x0000f843, 0x0400f833, /* 0400f833 //C 0f843 call	setup_line */
0x0000f844, 0x01f2f83d, /* 01f2f83d //C 0f844 jmp	main */
0x0000f845, 0x0ded0000, /* 0ded0000 //C 0f845 push	lr */
0x0000f846, 0x0108000a, /* 0108000a //C 0f846 cmp	r0,LF */
0x0000f847, 0x11f2f85b, /* 11f2f85b //C 0f847 EQ jmp	got_eol */
0x0000f848, 0x0108000d, /* 0108000d //C 0f848 cmp	r0,CR */
0x0000f849, 0x11f2f85b, /* 11f2f85b //C 0f849 EQ jmp	got_eol */
0x0000f84a, 0x01220000, /* 01220000 //C 0f84a mvzl	r2,0		; at_aol= 0 */
0x0000f84b, 0x0620fb6e, /* 0620fb6e //C 0f84b st	r2,at_eol */
0x0000f84c, 0x0112fb6d, /* 0112fb6d //C 0f84c mvzl	r1,line_ptr	; line[line_ptr]= char */
0x0000f84d, 0x0e310000, /* 0e310000 //C 0f84d ld	r3,r1 */
0x0000f84e, 0x0122fb09, /* 0122fb09 //C 0f84e mvzl	r2,line */
0x0000f84f, 0x08020300, /* 08020300 //C 0f84f st	r0,r2,r3 */
0x0000f850, 0x013a0001, /* 013a0001 //C 0f850 plus	r3,1		; line_ptr++ */
0x0000f851, 0x0c310000, /* 0c310000 //C 0f851 st	r3,r1 */
0x0000f852, 0x01420000, /* 01420000 //C 0f852 mvzl	r4,0 */
0x0000f853, 0x09438200, /* 09438200 //C 0f853 st	r4,r3+,r2	; line[line_ptr]= 0 */
0x0000f854, 0x08430200, /* 08430200 //C 0f854 st	r4,r3,r2	; double 0 at end, needed by tokenizer */
0x0000f855, 0x0142fb74, /* 0142fb74 //C 0f855 mvzl	r4,echo		; check if echo is turned on */
0x0000f856, 0x0e440000, /* 0e440000 //C 0f856 ld	r4,r4 */
0x0000f857, 0x024b0000, /* 024b0000 //C 0f857 sz	r4 */
0x0000f858, 0x2400fabf, /* 2400fabf //C 0f858 NZ call	putchar		; echo */
0x0000f859, 0x020d0000, /* 020d0000 //C 0f859 clc */
0x0000f85a, 0x01f2f860, /* 01f2f860 //C 0f85a jmp	proc_input_ret */
0x0000f85b, 0x0112fb6e, /* 0112fb6e //C 0f85b mvzl	r1,at_eol */
0x0000f85c, 0x0e110000, /* 0e110000 //C 0f85c ld	r1,r1 */
0x0000f85d, 0x021b0000, /* 021b0000 //C 0f85d sz	r1		; Z=0 at eol -> skip, not ready */
0x0000f85e, 0x220d0000, /* 220d0000 //C 0f85e Z0 clc */
0x0000f85f, 0x120c0000, /* 120c0000 //C 0f85f Z1 sec */
0x0000f860, 0x0fed0000, /* 0fed0000 //C 0f860 pop	lr */
0x0000f861, 0x00f00e00, /* 00f00e00 //C 0f861 ret */
0x0000f862, 0x0ded0000, /* 0ded0000 //C 0f862 push	lr */
0x0000f863, 0x0102000a, /* 0102000a //C 0f863 mvzl	r0,LF */
0x0000f864, 0x0400fabf, /* 0400fabf //C 0f864 call	putchar */
0x0000f865, 0x0400f88a, /* 0400f88a //C 0f865 call	tokenize */
0x0000f866, 0x0400f8ab, /* 0400f8ab //C 0f866 call	find_cmd */
0x0000f867, 0x41f2f86a, /* 41f2f86a //C 0f867 C0 jmp	cmd_not_found */
0x0000f868, 0x05000000, /* 05000000 //C 0f868 call	r0,0 */
0x0000f869, 0x01f2f86c, /* 01f2f86c //C 0f869 jmp	proc_line_ret */
0x0000f86a, 0x0102f875, /* 0102f875 //C 0f86a mvzl	r0,snotfound */
0x0000f86b, 0x0400fada, /* 0400fada //C 0f86b call	printsnl */
0x0000f86c, 0x01120001, /* 01120001 //C 0f86c mvzl	r1,1		; at_eol= 1 */
0x0000f86d, 0x0610fb6e, /* 0610fb6e //C 0f86d st	r1,at_eol */
0x0000f86e, 0x0fed0000, /* 0fed0000 //C 0f86e pop	lr */
0x0000f86f, 0x00f00e00, /* 00f00e00 //C 0f86f ret */
0x0000f870, 0x00000047, /* 00000047 //C 0f870 db	71 */
0x0000f871, 0x0000006f, /* 0000006f //C 0f871 db	111 */
0x0000f872, 0x00000074, /* 00000074 //C 0f872 db	116 */
0x0000f873, 0x0000003a, /* 0000003a //C 0f873 db	58 */
0x0000f874, 0x00000000, /* 00000000 //C 0f874 db */
0x0000f875, 0x00000055, /* 00000055 //C 0f875 db	85 */
0x0000f876, 0x0000006e, /* 0000006e //C 0f876 db	110 */
0x0000f877, 0x0000006b, /* 0000006b //C 0f877 db	107 */
0x0000f878, 0x0000006e, /* 0000006e //C 0f878 db	110 */
0x0000f879, 0x0000006f, /* 0000006f //C 0f879 db	111 */
0x0000f87a, 0x00000077, /* 00000077 //C 0f87a db	119 */
0x0000f87b, 0x0000006e, /* 0000006e //C 0f87b db	110 */
0x0000f87c, 0x00000020, /* 00000020 //C 0f87c db	32 */
0x0000f87d, 0x00000063, /* 00000063 //C 0f87d db	99 */
0x0000f87e, 0x0000006f, /* 0000006f //C 0f87e db	111 */
0x0000f87f, 0x0000006d, /* 0000006d //C 0f87f db	109 */
0x0000f880, 0x0000006d, /* 0000006d //C 0f880 db	109 */
0x0000f881, 0x00000061, /* 00000061 //C 0f881 db	97 */
0x0000f882, 0x0000006e, /* 0000006e //C 0f882 db	110 */
0x0000f883, 0x00000064, /* 00000064 //C 0f883 db	100 */
0x0000f884, 0x00000000, /* 00000000 //C 0f884 db */
0x0000f885, 0x0ded0000, /* 0ded0000 //C 0f885 push	lr */
0x0000f886, 0x0112fb97, /* 0112fb97 //C 0f886 mvzl	r1,delimiters */
0x0000f887, 0x0400fa17, /* 0400fa17 //C 0f887 call	strchr */
0x0000f888, 0x0fed0000, /* 0fed0000 //C 0f888 pop	lr */
0x0000f889, 0x00f00e00, /* 00f00e00 //C 0f889 ret */
0x0000f88a, 0x0ded0000, /* 0ded0000 //C 0f88a push	lr */
0x0000f88b, 0x0142fb6f, /* 0142fb6f //C 0f88b mvzl	r4,words	; array of result */
0x0000f88c, 0x0152fb09, /* 0152fb09 //C 0f88c mvzl	r5,line		; address of next char */
0x0000f88d, 0x01620000, /* 01620000 //C 0f88d mvzl	r6,0		; nuof words found */
0x0000f88e, 0x01720000, /* 01720000 //C 0f88e mvzl	r7,0		; bool in_word */
0x0000f88f, 0x0e050000, /* 0e050000 //C 0f88f ld	r0,r5		; pick a char */
0x0000f890, 0x020b0000, /* 020b0000 //C 0f890 sz	r0		; check end */
0x0000f891, 0x11f2f89b, /* 11f2f89b //C 0f891 jz	tok_delimiter	; found end, pretend delim */
0x0000f892, 0x0400f885, /* 0400f885 //C 0f892 call	is_delimiter */
0x0000f893, 0x31f2f89b, /* 31f2f89b //C 0f893 C1 jmp	tok_delimiter */
0x0000f894, 0x027b0000, /* 027b0000 //C 0f894 sz	r7 */
0x0000f895, 0x21f2f8a0, /* 21f2f8a0 //C 0f895 jnz	tok_next	; still inside word */
0x0000f896, 0x01720001, /* 01720001 //C 0f896 mvzl	r7,1		; in_word=true */
0x0000f897, 0x09568400, /* 09568400 //C 0f897 st	r5,r6+,r4	; record word address */
0x0000f898, 0x01680005, /* 01680005 //C 0f898 cmp	r6,MAX_WORDS	; If no more space */
0x0000f899, 0x11f2f8a4, /* 11f2f8a4 //C 0f899 EQ jmp	tok_ret		; then return */
0x0000f89a, 0x01f2f8a0, /* 01f2f8a0 //C 0f89a jmp	tok_next */
0x0000f89b, 0x027b0000, /* 027b0000 //C 0f89b sz	r7 */
0x0000f89c, 0x11f2f8a0, /* 11f2f8a0 //C 0f89c jz	tok_next	; still between words */
0x0000f89d, 0x01720000, /* 01720000 //C 0f89d mvzl	r7,0		; in_word=false */
0x0000f89e, 0x01120000, /* 01120000 //C 0f89e mvzl	r1,0		; put a 0 at the end of word */
0x0000f89f, 0x08150100, /* 08150100 //C 0f89f st	r1,r5,r1 */
0x0000f8a0, 0x020b0000, /* 020b0000 //C 0f8a0 sz	r0		; check EOL */
0x0000f8a1, 0x11f2f8a4, /* 11f2f8a4 //C 0f8a1 jz	tok_ret		; jump out if char==0 */
0x0000f8a2, 0x01540001, /* 01540001 //C 0f8a2 add	r5,1 */
0x0000f8a3, 0x01f2f88f, /* 01f2f88f //C 0f8a3 jmp	tok_cycle */
0x0000f8a4, 0x01120000, /* 01120000 //C 0f8a4 mvzl	r1,0 */
0x0000f8a5, 0x01680005, /* 01680005 //C 0f8a5 cmp	r6,MAX_WORDS */
0x0000f8a6, 0x11f2f8a9, /* 11f2f8a9 //C 0f8a6 jz	tok_end */
0x0000f8a7, 0x09168400, /* 09168400 //C 0f8a7 st	r1,r6+,r4 */
0x0000f8a8, 0x01f2f8a4, /* 01f2f8a4 //C 0f8a8 jmp	tok_ret */
0x0000f8a9, 0x0fed0000, /* 0fed0000 //C 0f8a9 pop	lr */
0x0000f8aa, 0x00f00e00, /* 00f00e00 //C 0f8aa ret */
0x0000f8ab, 0x0ded0000, /* 0ded0000 //C 0f8ab push	lr */
0x0000f8ac, 0x0d1d0000, /* 0d1d0000 //C 0f8ac push	r1 */
0x0000f8ad, 0x0d2d0000, /* 0d2d0000 //C 0f8ad push	r2 */
0x0000f8ae, 0x0d3d0000, /* 0d3d0000 //C 0f8ae push	r3 */
0x0000f8af, 0x0dad0000, /* 0dad0000 //C 0f8af push	r10 */
0x0000f8b0, 0x0700fb6f, /* 0700fb6f //C 0f8b0 ld	r0,words	; R0= 1st word of command */
0x0000f8b1, 0x020b0000, /* 020b0000 //C 0f8b1 sz	r0 */
0x0000f8b2, 0x11f2f8c7, /* 11f2f8c7 //C 0f8b2 jz	find_cmd_false */
0x0000f8b3, 0x01a2fba7, /* 01a2fba7 //C 0f8b3 mvzl	r10,commands */
0x0000f8b4, 0x0e2a0000, /* 0e2a0000 //C 0f8b4 ld	r2,r10		; R2= cmd addr */
0x0000f8b5, 0x022b0000, /* 022b0000 //C 0f8b5 sz	r2 */
0x0000f8b6, 0x11f2f8c7, /* 11f2f8c7 //C 0f8b6 jz	find_cmd_false */
0x0000f8b7, 0x01a40001, /* 01a40001 //C 0f8b7 add	r10,1 */
0x0000f8b8, 0x00100a00, /* 00100a00 //C 0f8b8 mov	r1,r10		; R1= cmd string */
0x0000f8b9, 0x01a40001, /* 01a40001 //C 0f8b9 add	r10,1 */
0x0000f8ba, 0x0e3a0000, /* 0e3a0000 //C 0f8ba ld	r3,r10 */
0x0000f8bb, 0x023b0000, /* 023b0000 //C 0f8bb sz	r3 */
0x0000f8bc, 0x21f2f8b9, /* 21f2f8b9 //C 0f8bc jnz	find_cmd_fw */
0x0000f8bd, 0x01a40001, /* 01a40001 //C 0f8bd add	r10,1 */
0x0000f8be, 0x0400fa52, /* 0400fa52 //C 0f8be call	streq */
0x0000f8bf, 0x41f2f8b4, /* 41f2f8b4 //C 0f8bf C0 jmp	find_cmd_cyc */
0x0000f8c0, 0x00000200, /* 00000200 //C 0f8c0 mov	r0,r2 */
0x0000f8c1, 0x020c0000, /* 020c0000 //C 0f8c1 sec */
0x0000f8c2, 0x01f2f8d2, /* 01f2f8d2 //C 0f8c2 jmp	find_cmd_ret */
0x0000f8c3, 0x0000002f, /* 0000002f //C 0f8c3 db	47 */
0x0000f8c4, 0x0000002f, /* 0000002f //C 0f8c4 db	47 */
0x0000f8c5, 0x00000043, /* 00000043 //C 0f8c5 db	67 */
0x0000f8c6, 0x00000000, /* 00000000 //C 0f8c6 db */
0x0000f8c7, 0x01040001, /* 01040001 //C 0f8c7 add	r0,1		; check second word */
0x0000f8c8, 0x0e100000, /* 0e100000 //C 0f8c8 ld	r1,r0		; for //C command */
0x0000f8c9, 0x021b0000, /* 021b0000 //C 0f8c9 sz	r1 */
0x0000f8ca, 0x11f2f8d0, /* 11f2f8d0 //C 0f8ca jz	find_cmd_very_false */
0x0000f8cb, 0x0102f8c3, /* 0102f8c3 //C 0f8cb mvzl	r0,c_cmd_name */
0x0000f8cc, 0x0400fa52, /* 0400fa52 //C 0f8cc call	streq */
0x0000f8cd, 0x21f2f8d0, /* 21f2f8d0 //C 0f8cd jnz	find_cmd_very_false */
0x0000f8ce, 0x0122f961, /* 0122f961 //C 0f8ce mvzl	r2,cmd_c */
0x0000f8cf, 0x01f2f8c0, /* 01f2f8c0 //C 0f8cf jmp	find_cmd_true */
0x0000f8d0, 0x020d0000, /* 020d0000 //C 0f8d0 clc */
0x0000f8d1, 0x01020000, /* 01020000 //C 0f8d1 mvzl	r0,0 */
0x0000f8d2, 0x0fad0000, /* 0fad0000 //C 0f8d2 pop	r10 */
0x0000f8d3, 0x0f3d0000, /* 0f3d0000 //C 0f8d3 pop	r3 */
0x0000f8d4, 0x0f2d0000, /* 0f2d0000 //C 0f8d4 pop	r2 */
0x0000f8d5, 0x0f1d0000, /* 0f1d0000 //C 0f8d5 pop	r1 */
0x0000f8d6, 0x0fed0000, /* 0fed0000 //C 0f8d6 pop	lr */
0x0000f8d7, 0x00f00e00, /* 00f00e00 //C 0f8d7 ret */
0x0000f8d8, 0x0ded0000, /* 0ded0000 //C 0f8d8 push	lr */
0x0000f8d9, 0x0122fb6f, /* 0122fb6f //C 0f8d9 mvzl	r2,words */
0x0000f8da, 0x01020000, /* 01020000 //C 0f8da mvzl	r0,0 */
0x0000f8db, 0x0e420001, /* 0e420001 //C 0f8db ld	r4,r2,1		; addr */
0x0000f8dc, 0x0e520002, /* 0e520002 //C 0f8dc ld	r5,r2,2		; value */
0x0000f8dd, 0x024b0000, /* 024b0000 //C 0f8dd sz 	r4 */
0x0000f8de, 0x11f2f8ff, /* 11f2f8ff //C 0f8de jz	m_ret */
0x0000f8df, 0x00000400, /* 00000400 //C 0f8df mov	r0,r4 */
0x0000f8e0, 0x0400fa94, /* 0400fa94 //C 0f8e0 call	htoi */
0x0000f8e1, 0x00400100, /* 00400100 //C 0f8e1 mov	r4,r1 */
0x0000f8e2, 0x31f2f8e6, /* 31f2f8e6 //C 0f8e2 C1 jmp	m_addr_ok */
0x0000f8e3, 0x0102f901, /* 0102f901 //C 0f8e3 mvzl	r0,m_err_addr */
0x0000f8e4, 0x0400fada, /* 0400fada //C 0f8e4 call	printsnl */
0x0000f8e5, 0x01f2f8ff, /* 01f2f8ff //C 0f8e5 jmp	m_ret */
0x0000f8e6, 0x025b0000, /* 025b0000 //C 0f8e6 sz	r5 */
0x0000f8e7, 0x11f2f8f5, /* 11f2f8f5 //C 0f8e7 jz	m_read */
0x0000f8e8, 0x0148fd95, /* 0148fd95 //C 0f8e8 cmp	r4,the_end */
0x0000f8e9, 0x91f2f8ed, /* 91f2f8ed //C 0f8e9 HI jmp	m_addrv_ok */
0x0000f8ea, 0x0102f90f, /* 0102f90f //C 0f8ea mvzl	r0,m_err_addrv */
0x0000f8eb, 0x0400fada, /* 0400fada //C 0f8eb call	printsnl */
0x0000f8ec, 0x01f2f8ff, /* 01f2f8ff //C 0f8ec jmp	m_ret */
0x0000f8ed, 0x00000500, /* 00000500 //C 0f8ed mov	r0,r5 */
0x0000f8ee, 0x0400fa94, /* 0400fa94 //C 0f8ee call	htoi */
0x0000f8ef, 0x00500100, /* 00500100 //C 0f8ef mov	r5,r1 */
0x0000f8f0, 0x31f2f8f4, /* 31f2f8f4 //C 0f8f0 C1 jmp	m_value_ok */
0x0000f8f1, 0x0102f921, /* 0102f921 //C 0f8f1 mvzl	r0,m_err_value */
0x0000f8f2, 0x0400fada, /* 0400fada //C 0f8f2 call	printsnl */
0x0000f8f3, 0x01f2f8ff, /* 01f2f8ff //C 0f8f3 jmp	m_ret */
0x0000f8f4, 0x0c540000, /* 0c540000 //C 0f8f4 st	r5,r4 */
0x0000f8f5, 0x00000400, /* 00000400 //C 0f8f5 mov	r0,r4 */
0x0000f8f6, 0x01120004, /* 01120004 //C 0f8f6 mvzl	r1,4 */
0x0000f8f7, 0x0400fae2, /* 0400fae2 //C 0f8f7 call	print_vhex */
0x0000f8f8, 0x01020020, /* 01020020 //C 0f8f8 mvzl	r0,0x20 */
0x0000f8f9, 0x0400fabf, /* 0400fabf //C 0f8f9 call	putchar */
0x0000f8fa, 0x0e040000, /* 0e040000 //C 0f8fa ld	r0,r4 */
0x0000f8fb, 0x01120004, /* 01120004 //C 0f8fb mvzl	r1,4 */
0x0000f8fc, 0x0400fae2, /* 0400fae2 //C 0f8fc call	print_vhex */
0x0000f8fd, 0x0102000a, /* 0102000a //C 0f8fd mvzl	r0,LF */
0x0000f8fe, 0x0400fabf, /* 0400fabf //C 0f8fe call	putchar */
0x0000f8ff, 0x0fed0000, /* 0fed0000 //C 0f8ff pop	lr */
0x0000f900, 0x00f00e00, /* 00f00e00 //C 0f900 ret */
0x0000f901, 0x00000041, /* 00000041 //C 0f901 db	65 */
0x0000f902, 0x00000064, /* 00000064 //C 0f902 db	100 */
0x0000f903, 0x00000064, /* 00000064 //C 0f903 db	100 */
0x0000f904, 0x00000072, /* 00000072 //C 0f904 db	114 */
0x0000f905, 0x00000065, /* 00000065 //C 0f905 db	101 */
0x0000f906, 0x00000073, /* 00000073 //C 0f906 db	115 */
0x0000f907, 0x00000073, /* 00000073 //C 0f907 db	115 */
0x0000f908, 0x00000020, /* 00000020 //C 0f908 db	32 */
0x0000f909, 0x00000065, /* 00000065 //C 0f909 db	101 */
0x0000f90a, 0x00000072, /* 00000072 //C 0f90a db	114 */
0x0000f90b, 0x00000072, /* 00000072 //C 0f90b db	114 */
0x0000f90c, 0x0000006f, /* 0000006f //C 0f90c db	111 */
0x0000f90d, 0x00000072, /* 00000072 //C 0f90d db	114 */
0x0000f90e, 0x00000000, /* 00000000 //C 0f90e db */
0x0000f90f, 0x0000004d, /* 0000004d //C 0f90f db	77 */
0x0000f910, 0x0000006f, /* 0000006f //C 0f910 db	111 */
0x0000f911, 0x0000006e, /* 0000006e //C 0f911 db	110 */
0x0000f912, 0x00000069, /* 00000069 //C 0f912 db	105 */
0x0000f913, 0x00000074, /* 00000074 //C 0f913 db	116 */
0x0000f914, 0x0000006f, /* 0000006f //C 0f914 db	111 */
0x0000f915, 0x00000072, /* 00000072 //C 0f915 db	114 */
0x0000f916, 0x00000027, /* 00000027 //C 0f916 db	39 */
0x0000f917, 0x00000073, /* 00000073 //C 0f917 db	115 */
0x0000f918, 0x00000020, /* 00000020 //C 0f918 db	32 */
0x0000f919, 0x00000061, /* 00000061 //C 0f919 db	97 */
0x0000f91a, 0x00000064, /* 00000064 //C 0f91a db	100 */
0x0000f91b, 0x00000064, /* 00000064 //C 0f91b db	100 */
0x0000f91c, 0x00000072, /* 00000072 //C 0f91c db	114 */
0x0000f91d, 0x00000065, /* 00000065 //C 0f91d db	101 */
0x0000f91e, 0x00000073, /* 00000073 //C 0f91e db	115 */
0x0000f91f, 0x00000073, /* 00000073 //C 0f91f db	115 */
0x0000f920, 0x00000000, /* 00000000 //C 0f920 db */
0x0000f921, 0x00000056, /* 00000056 //C 0f921 db	86 */
0x0000f922, 0x00000061, /* 00000061 //C 0f922 db	97 */
0x0000f923, 0x0000006c, /* 0000006c //C 0f923 db	108 */
0x0000f924, 0x00000075, /* 00000075 //C 0f924 db	117 */
0x0000f925, 0x00000065, /* 00000065 //C 0f925 db	101 */
0x0000f926, 0x00000020, /* 00000020 //C 0f926 db	32 */
0x0000f927, 0x00000065, /* 00000065 //C 0f927 db	101 */
0x0000f928, 0x00000072, /* 00000072 //C 0f928 db	114 */
0x0000f929, 0x00000072, /* 00000072 //C 0f929 db	114 */
0x0000f92a, 0x0000006f, /* 0000006f //C 0f92a db	111 */
0x0000f92b, 0x00000072, /* 00000072 //C 0f92b db	114 */
0x0000f92c, 0x00000000, /* 00000000 //C 0f92c db */
0x0000f92d, 0x0ded0000, /* 0ded0000 //C 0f92d push	lr */
0x0000f92e, 0x0122fb6f, /* 0122fb6f //C 0f92e mvzl	r2,words */
0x0000f92f, 0x0e020001, /* 0e020001 //C 0f92f ld	r0,r2,1		; start address */
0x0000f930, 0x0400fa94, /* 0400fa94 //C 0f930 call	htoi */
0x0000f931, 0x00300100, /* 00300100 //C 0f931 mov	r3,r1 */
0x0000f932, 0x0e020002, /* 0e020002 //C 0f932 ld	r0,r2,2		; end address */
0x0000f933, 0x020b0000, /* 020b0000 //C 0f933 sz	r0 */
0x0000f934, 0x21f2f938, /* 21f2f938 //C 0f934 jnz	d_end_ok */
0x0000f935, 0x00400300, /* 00400300 //C 0f935 mov	r4,r3 */
0x0000f936, 0x01440010, /* 01440010 //C 0f936 add	r4,0x10 */
0x0000f937, 0x01f2f93a, /* 01f2f93a //C 0f937 jmp	d_chk_end */
0x0000f938, 0x0400fa94, /* 0400fa94 //C 0f938 call	htoi */
0x0000f939, 0x00400100, /* 00400100 //C 0f939 mov	r4,r1 */
0x0000f93a, 0x00380400, /* 00380400 //C 0f93a cmp	r3,r4		; check if start>end */
0x0000f93b, 0x91f2f94a, /* 91f2f94a //C 0f93b HI jmp d_bad */
0x0000f93c, 0x00000300, /* 00000300 //C 0f93c mov	r0,r3		; print address */
0x0000f93d, 0x01120004, /* 01120004 //C 0f93d mvzl	r1,4 */
0x0000f93e, 0x0400fae2, /* 0400fae2 //C 0f93e call	print_vhex */
0x0000f93f, 0x01020020, /* 01020020 //C 0f93f mvzl	r0,0x20		; print one space */
0x0000f940, 0x0400fabf, /* 0400fabf //C 0f940 call	putchar */
0x0000f941, 0x0e030000, /* 0e030000 //C 0f941 ld	r0,r3		; load data */
0x0000f942, 0x01120004, /* 01120004 //C 0f942 mvzl	r1,4		; print data */
0x0000f943, 0x0400fae2, /* 0400fae2 //C 0f943 call	print_vhex */
0x0000f944, 0x0102000a, /* 0102000a //C 0f944 mvzl	r0,LF		; print new line */
0x0000f945, 0x0400fabf, /* 0400fabf //C 0f945 call	putchar */
0x0000f946, 0x00380400, /* 00380400 //C 0f946 cmp	r3,r4 */
0x0000f947, 0x11f2f94c, /* 11f2f94c //C 0f947 jz	d_ret */
0x0000f948, 0x01340001, /* 01340001 //C 0f948 add	r3,1 */
0x0000f949, 0x01f2f93c, /* 01f2f93c //C 0f949 jmp	d_cyc */
0x0000f94a, 0x0102f94e, /* 0102f94e //C 0f94a mvzl	r0,d_err_bad */
0x0000f94b, 0x0400fada, /* 0400fada //C 0f94b call	printsnl */
0x0000f94c, 0x0fed0000, /* 0fed0000 //C 0f94c pop	lr */
0x0000f94d, 0x00f00e00, /* 00f00e00 //C 0f94d ret */
0x0000f94e, 0x00000057, /* 00000057 //C 0f94e db	87 */
0x0000f94f, 0x00000072, /* 00000072 //C 0f94f db	114 */
0x0000f950, 0x0000006f, /* 0000006f //C 0f950 db	111 */
0x0000f951, 0x0000006e, /* 0000006e //C 0f951 db	110 */
0x0000f952, 0x00000067, /* 00000067 //C 0f952 db	103 */
0x0000f953, 0x00000020, /* 00000020 //C 0f953 db	32 */
0x0000f954, 0x00000065, /* 00000065 //C 0f954 db	101 */
0x0000f955, 0x0000006e, /* 0000006e //C 0f955 db	110 */
0x0000f956, 0x00000064, /* 00000064 //C 0f956 db	100 */
0x0000f957, 0x00000020, /* 00000020 //C 0f957 db	32 */
0x0000f958, 0x00000061, /* 00000061 //C 0f958 db	97 */
0x0000f959, 0x00000064, /* 00000064 //C 0f959 db	100 */
0x0000f95a, 0x00000064, /* 00000064 //C 0f95a db	100 */
0x0000f95b, 0x00000072, /* 00000072 //C 0f95b db	114 */
0x0000f95c, 0x00000065, /* 00000065 //C 0f95c db	101 */
0x0000f95d, 0x00000073, /* 00000073 //C 0f95d db	115 */
0x0000f95e, 0x00000073, /* 00000073 //C 0f95e db	115 */
0x0000f95f, 0x00000000, /* 00000000 //C 0f95f db */
0x0000f960, 0x00f00e00, /* 00f00e00 //C 0f960 ret */
0x0000f961, 0x00f00e00, /* 00f00e00 //C 0f961 ret */
0x0000f962, 0x0ded0000, /* 0ded0000 //C 0f962 push	lr */
0x0000f963, 0x01a20000, /* 01a20000 //C 0f963 mvzl	r10,0		; state (nr of words) */
0x0000f964, 0x01820000, /* 01820000 //C 0f964 mvzl	r8,0		; value */
0x0000f965, 0x0162003f, /* 0162003f //C 0f965 mvzl	r6,'?'		; Record type */
0x0000f966, 0x0400fab6, /* 0400fab6 //C 0f966 call	check_uart */
0x0000f967, 0x41f2f966, /* 41f2f966 //C 0f967 C0 jmp	l_cyc */
0x0000f968, 0x0400fabd, /* 0400fabd //C 0f968 call	read */
0x0000f969, 0x00b00000, /* 00b00000 //C 0f969 mov	r11,r0		; Copy of char in R11 */
0x0000f96a, 0x0108000a, /* 0108000a //C 0f96a cmp	r0,10		; check EOL chars */
0x0000f96b, 0x11f2f9b5, /* 11f2f9b5 //C 0f96b jz	l_eol */
0x0000f96c, 0x0108000d, /* 0108000d //C 0f96c cmp	r0,13 */
0x0000f96d, 0x11f2f9b5, /* 11f2f9b5 //C 0f96d jz	l_eol */
0x0000f96e, 0x01a80000, /* 01a80000 //C 0f96e cmp	r10,0 */
0x0000f96f, 0x21f2f97f, /* 21f2f97f //C 0f96f jnz	l_no0 */
0x0000f970, 0x0400fa60, /* 0400fa60 //C 0f970 call	hexchar2value */
0x0000f971, 0x41f2f979, /* 41f2f979 //C 0f971 C0 jmp	l_eof_0 */
0x0000f972, 0x02880000, /* 02880000 //C 0f972 shl	r8		; shift val(char) into value */
0x0000f973, 0x02880000, /* 02880000 //C 0f973 shl	r8 */
0x0000f974, 0x02880000, /* 02880000 //C 0f974 shl	r8 */
0x0000f975, 0x02880000, /* 02880000 //C 0f975 shl	r8 */
0x0000f976, 0x010b000f, /* 010b000f //C 0f976 btst	r0,0xf */
0x0000f977, 0x008d0000, /* 008d0000 //C 0f977 or	r8,r0 */
0x0000f978, 0x01f2f966, /* 01f2f966 //C 0f978 jmp	l_cyc */
0x0000f979, 0x01a20001, /* 01a20001 //C 0f979 mvzl	r10,1		; state0 -> state1 */
0x0000f97a, 0x0162003f, /* 0162003f //C 0f97a mvzl	r6,'?'		; No //C yet */
0x0000f97b, 0x01b8002f, /* 01b8002f //C 0f97b cmp	r11,'/'		; is it start of // */
0x0000f97c, 0x11720001, /* 11720001 //C 0f97c z1 mvzl	r7,1		; Yes, first / found */
0x0000f97d, 0x21720000, /* 21720000 //C 0f97d z0 mvzl	r7,0		; No '/' yet */
0x0000f97e, 0x01f2f966, /* 01f2f966 //C 0f97e jmp	l_cyc */
0x0000f97f, 0x01a80001, /* 01a80001 //C 0f97f cmp	r10,1 */
0x0000f980, 0x21f2f998, /* 21f2f998 //C 0f980 jnz	l_no1 */
0x0000f981, 0x027b0000, /* 027b0000 //C 0f981 sz	r7 */
0x0000f982, 0x21f2f987, /* 21f2f987 //C 0f982 jnz	l_s1_2nd */
0x0000f983, 0x0108002f, /* 0108002f //C 0f983 cmp	r0,'/' */
0x0000f984, 0x21f2f966, /* 21f2f966 //C 0f984 jnz	l_cyc */
0x0000f985, 0x01720001, /* 01720001 //C 0f985 mvzl	r7,1 */
0x0000f986, 0x01f2f966, /* 01f2f966 //C 0f986 jmp	l_cyc */
0x0000f987, 0x0108002f, /* 0108002f //C 0f987 cmp	r0,'/' */
0x0000f988, 0x11f2f966, /* 11f2f966 //C 0f988 jz	l_cyc */
0x0000f989, 0x01080043, /* 01080043 //C 0f989 cmp	r0,'C' */
0x0000f98a, 0x21f2f990, /* 21f2f990 //C 0f98a jnz	l_s1_noC */
0x0000f98b, 0x01620043, /* 01620043 //C 0f98b mvzl	r6,'C' */
0x0000f98c, 0x01a20002, /* 01a20002 //C 0f98c mvzl	r10,2 */
0x0000f98d, 0x01920000, /* 01920000 //C 0f98d mvzl	r9,0		; address= 0 */
0x0000f98e, 0x01520000, /* 01520000 //C 0f98e mvzl	r5,0		; where we are in word: before */
0x0000f98f, 0x01f2f966, /* 01f2f966 //C 0f98f jmp	l_cyc */
0x0000f990, 0x01080045, /* 01080045 //C 0f990 cmp	r0,'E' */
0x0000f991, 0x21f2f995, /* 21f2f995 //C 0f991 jnz	l_s1_noE */
0x0000f992, 0x01620045, /* 01620045 //C 0f992 mvzl	r6,'E' */
0x0000f993, 0x01a20003, /* 01a20003 //C 0f993 mvzl	r10,3 */
0x0000f994, 0x01f2f966, /* 01f2f966 //C 0f994 jmp	l_cyc */
0x0000f995, 0x0400fabf, /* 0400fabf //C 0f995 call	putchar		; print record type */
0x0000f996, 0x01a2000f, /* 01a2000f //C 0f996 mvzl	r10,0xf		; special state: skip everything */
0x0000f997, 0x01f2f966, /* 01f2f966 //C 0f997 jmp	l_cyc */
0x0000f998, 0x01a80002, /* 01a80002 //C 0f998 cmp	r10,2 */
0x0000f999, 0x21f2f9ad, /* 21f2f9ad //C 0f999 jnz	l_no2 */
0x0000f99a, 0x01580000, /* 01580000 //C 0f99a cmp	r5,0 */
0x0000f99b, 0x21f2f9a6, /* 21f2f9a6 //C 0f99b jnz	l_s2_no0 */
0x0000f99c, 0x0400fa60, /* 0400fa60 //C 0f99c call	hexchar2value */
0x0000f99d, 0x41f2f966, /* 41f2f966 //C 0f99d C0 jmp	l_cyc */
0x0000f99e, 0x01520001, /* 01520001 //C 0f99e mvzl	r5,1 */
0x0000f99f, 0x02980000, /* 02980000 //C 0f99f shl	r9 */
0x0000f9a0, 0x02980000, /* 02980000 //C 0f9a0 shl	r9 */
0x0000f9a1, 0x02980000, /* 02980000 //C 0f9a1 shl	r9 */
0x0000f9a2, 0x02980000, /* 02980000 //C 0f9a2 shl	r9 */
0x0000f9a3, 0x010b000f, /* 010b000f //C 0f9a3 btst	r0,0xf */
0x0000f9a4, 0x009d0000, /* 009d0000 //C 0f9a4 or	r9,r0 */
0x0000f9a5, 0x01f2f966, /* 01f2f966 //C 0f9a5 jmp	l_cyc */
0x0000f9a6, 0x01580001, /* 01580001 //C 0f9a6 cmp	r5,1 */
0x0000f9a7, 0x21f2f9ac, /* 21f2f9ac //C 0f9a7 jnz	l_s2_no1 */
0x0000f9a8, 0x0400fa60, /* 0400fa60 //C 0f9a8 call	hexchar2value */
0x0000f9a9, 0x31f2f99f, /* 31f2f99f //C 0f9a9 C1 jmp	l_s2_got */
0x0000f9aa, 0x01520002, /* 01520002 //C 0f9aa mvzl	r5,2 */
0x0000f9ab, 0x01f2f966, /* 01f2f966 //C 0f9ab jmp	l_cyc */
0x0000f9ac, 0x01f2f966, /* 01f2f966 //C 0f9ac jmp	l_cyc */
0x0000f9ad, 0x01a80003, /* 01a80003 //C 0f9ad cmp	r10,3 */
0x0000f9ae, 0x21f2f9b0, /* 21f2f9b0 //C 0f9ae jnz	l_no3 */
0x0000f9af, 0x01f2f966, /* 01f2f966 //C 0f9af jmp	l_cyc		; do nothing, just wait EOL */
0x0000f9b0, 0x01a8000f, /* 01a8000f //C 0f9b0 cmp	r10,0xf */
0x0000f9b1, 0x01f2f9b3, /* 01f2f9b3 //C 0f9b1 jmp	l_nof */
0x0000f9b2, 0x01f2f966, /* 01f2f966 //C 0f9b2 jmp	l_cyc		; just skip */
0x0000f9b3, 0x01f2f966, /* 01f2f966 //C 0f9b3 jmp	l_cyc */
0x0000f9b4, 0x01f2f9cb, /* 01f2f9cb //C 0f9b4 jmp	l_ret */
0x0000f9b5, 0x01a80000, /* 01a80000 //C 0f9b5 cmp	r10,0		; in state0 */
0x0000f9b6, 0x11f2f9c5, /* 11f2f9c5 //C 0f9b6 jz	l_back_to_0	; just restart */
0x0000f9b7, 0x01a80001, /* 01a80001 //C 0f9b7 cmp	r10,1		; in state1 */
0x0000f9b8, 0x11f2f9c5, /* 11f2f9c5 //C 0f9b8 jz	l_back_to_0 	;l_cyc ;l_bad ; garbage */
0x0000f9b9, 0x01a80002, /* 01a80002 //C 0f9b9 cmp	r10,2		; in state2 */
0x0000f9ba, 0x11f2f9c1, /* 11f2f9c1 //C 0f9ba jz	l_proc		; process record */
0x0000f9bb, 0x01a80003, /* 01a80003 //C 0f9bb cmp	r10,3		; in state3 */
0x0000f9bc, 0x11f2f9cb, /* 11f2f9cb //C 0f9bc jz	l_ret		; eol in end record: finish */
0x0000f9bd, 0x01a8000f, /* 01a8000f //C 0f9bd cmp	r10,0xf		; in state skip */
0x0000f9be, 0x11f2f9c5, /* 11f2f9c5 //C 0f9be jz	l_back_to_0	; reset state for new line */
0x0000f9bf, 0x01f2f966, /* 01f2f966 //C 0f9bf jmp	l_cyc */
0x0000f9c0, 0x01f2f9cb, /* 01f2f9cb //C 0f9c0 jmp	l_ret */
0x0000f9c1, 0x01680043, /* 01680043 //C 0f9c1 cmp	r6,'C'		; is it a C record? */
0x0000f9c2, 0x1c890000, /* 1c890000 //C 0f9c2 z st	r8,r9		; store */
0x0000f9c3, 0x00000600, /* 00000600 //C 0f9c3 mov	r0,r6		; echo record type */
0x0000f9c4, 0x0400fabf, /* 0400fabf //C 0f9c4 call	putchar */
0x0000f9c5, 0x0102002e, /* 0102002e //C 0f9c5 mvzl	r0,'.' */
0x0000f9c6, 0x0400fabf, /* 0400fabf //C 0f9c6 call	putchar */
0x0000f9c7, 0x01a20000, /* 01a20000 //C 0f9c7 mvzl	r10,0 */
0x0000f9c8, 0x01820000, /* 01820000 //C 0f9c8 mvzl	r8,0 */
0x0000f9c9, 0x0162003f, /* 0162003f //C 0f9c9 mvzl	r6,'?' */
0x0000f9ca, 0x01f2f966, /* 01f2f966 //C 0f9ca jmp	l_cyc */
0x0000f9cb, 0x0102000a, /* 0102000a //C 0f9cb mvzl	r0,LF */
0x0000f9cc, 0x0400fabf, /* 0400fabf //C 0f9cc call	putchar */
0x0000f9cd, 0x0fed0000, /* 0fed0000 //C 0f9cd pop	lr */
0x0000f9ce, 0x00f00e00, /* 00f00e00 //C 0f9ce ret */
0x0000f9cf, 0x0ded0000, /* 0ded0000 //C 0f9cf push	lr */
0x0000f9d0, 0x0122fb6f, /* 0122fb6f //C 0f9d0 mvzl	r2,words */
0x0000f9d1, 0x0e020001, /* 0e020001 //C 0f9d1 ld	r0,r2,1		; address */
0x0000f9d2, 0x020b0000, /* 020b0000 //C 0f9d2 sz	r0 */
0x0000f9d3, 0x11f2f9f6, /* 11f2f9f6 //C 0f9d3 jz	g_no_addr */
0x0000f9d4, 0x0400fa94, /* 0400fa94 //C 0f9d4 call	htoi */
0x0000f9d5, 0x00b00100, /* 00b00100 //C 0f9d5 mov	r11,r1 */
0x0000f9d6, 0x0102fa05, /* 0102fa05 //C 0f9d6 mvzl	r0,d_msg_run */
0x0000f9d7, 0x0400fac6, /* 0400fac6 //C 0f9d7 call	prints */
0x0000f9d8, 0x00000b00, /* 00000b00 //C 0f9d8 mov	r0,r11 */
0x0000f9d9, 0x01120004, /* 01120004 //C 0f9d9 mvzl	r1,4 */
0x0000f9da, 0x0400fae2, /* 0400fae2 //C 0f9da call	print_vhex */
0x0000f9db, 0x0102000a, /* 0102000a //C 0f9db mvzl	r0,LF */
0x0000f9dc, 0x0400fabf, /* 0400fabf //C 0f9dc call	putchar */
0x0000f9dd, 0x06b0fb85, /* 06b0fb85 //C 0f9dd st	r11,reg15 */
0x0000f9de, 0x0122ff43, /* 0122ff43 //C 0f9de mvzl	r2,UART_TSTAT */
0x0000f9df, 0x0e920000, /* 0e920000 //C 0f9df ld	r9,r2 */
0x0000f9e0, 0x019c0001, /* 019c0001 //C 0f9e0 test	r9,1 */
0x0000f9e1, 0x11f2f9df, /* 11f2f9df //C 0f9e1 jz	g_wait_tc */
0x0000f9e2, 0x07000000, /* 07000000 //C 0f9e2 ld	r0,0 */
0x0000f9e3, 0x0600fb75, /* 0600fb75 //C 0f9e3 st	r0,called */
0x0000f9e4, 0x0700fb86, /* 0700fb86 //C 0f9e4 ld	r0,regf */
0x0000f9e5, 0x020f0000, /* 020f0000 //C 0f9e5 setf	r0 */
0x0000f9e6, 0x0700fb76, /* 0700fb76 //C 0f9e6 ld	r0,reg0 */
0x0000f9e7, 0x0710fb77, /* 0710fb77 //C 0f9e7 ld	r1,reg1 */
0x0000f9e8, 0x0720fb78, /* 0720fb78 //C 0f9e8 ld	r2,reg2 */
0x0000f9e9, 0x0730fb79, /* 0730fb79 //C 0f9e9 ld	r3,reg3 */
0x0000f9ea, 0x0740fb7a, /* 0740fb7a //C 0f9ea ld	r4,reg4 */
0x0000f9eb, 0x0750fb7b, /* 0750fb7b //C 0f9eb ld	r5,reg5 */
0x0000f9ec, 0x0760fb7c, /* 0760fb7c //C 0f9ec ld	r6,reg6 */
0x0000f9ed, 0x0770fb7d, /* 0770fb7d //C 0f9ed ld	r7,reg7 */
0x0000f9ee, 0x0780fb7e, /* 0780fb7e //C 0f9ee ld	r8,reg8 */
0x0000f9ef, 0x0790fb7f, /* 0790fb7f //C 0f9ef ld	r9,reg9 */
0x0000f9f0, 0x07a0fb80, /* 07a0fb80 //C 0f9f0 ld	r10,reg10 */
0x0000f9f1, 0x07b0fb81, /* 07b0fb81 //C 0f9f1 ld	r11,reg11 */
0x0000f9f2, 0x07c0fb82, /* 07c0fb82 //C 0f9f2 ld	r12,reg12 */
0x0000f9f3, 0x07d0fb83, /* 07d0fb83 //C 0f9f3 ld	r13,reg13 */
0x0000f9f4, 0x07e0fb84, /* 07e0fb84 //C 0f9f4 ld	r14,reg14 */
0x0000f9f5, 0x07f0fb85, /* 07f0fb85 //C 0f9f5 ld	r15,reg15 */
0x0000f9f6, 0x0102f9fa, /* 0102f9fa //C 0f9f6 mvzl	r0,g_err_addr */
0x0000f9f7, 0x0400fada, /* 0400fada //C 0f9f7 call	printsnl */
0x0000f9f8, 0x0fed0000, /* 0fed0000 //C 0f9f8 pop	lr */
0x0000f9f9, 0x00f00e00, /* 00f00e00 //C 0f9f9 ret */
0x0000f9fa, 0x0000004e, /* 0000004e //C 0f9fa db	78 */
0x0000f9fb, 0x0000006f, /* 0000006f //C 0f9fb db	111 */
0x0000f9fc, 0x00000020, /* 00000020 //C 0f9fc db	32 */
0x0000f9fd, 0x00000061, /* 00000061 //C 0f9fd db	97 */
0x0000f9fe, 0x00000064, /* 00000064 //C 0f9fe db	100 */
0x0000f9ff, 0x00000064, /* 00000064 //C 0f9ff db	100 */
0x0000fa00, 0x00000072, /* 00000072 //C 0fa00 db	114 */
0x0000fa01, 0x00000065, /* 00000065 //C 0fa01 db	101 */
0x0000fa02, 0x00000073, /* 00000073 //C 0fa02 db	115 */
0x0000fa03, 0x00000073, /* 00000073 //C 0fa03 db	115 */
0x0000fa04, 0x00000000, /* 00000000 //C 0fa04 db */
0x0000fa05, 0x00000052, /* 00000052 //C 0fa05 db	82 */
0x0000fa06, 0x00000075, /* 00000075 //C 0fa06 db	117 */
0x0000fa07, 0x0000006e, /* 0000006e //C 0fa07 db	110 */
0x0000fa08, 0x00000020, /* 00000020 //C 0fa08 db	32 */
0x0000fa09, 0x00000000, /* 00000000 //C 0fa09 db */
0x0000fa0a, 0x0ded0000, /* 0ded0000 //C 0fa0a push	lr */
0x0000fa0b, 0x0122fbde, /* 0122fbde //C 0fa0b mvzl	r2,helps */
0x0000fa0c, 0x01320000, /* 01320000 //C 0fa0c mvzl	r3,0 */
0x0000fa0d, 0x0b038200, /* 0b038200 //C 0fa0d ld	r0,r3+,r2	; pick a char */
0x0000fa0e, 0x020b0000, /* 020b0000 //C 0fa0e sz	r0		; is it eos? */
0x0000fa0f, 0x21f2fa13, /* 21f2fa13 //C 0fa0f jnz	h_print */
0x0000fa10, 0x0b038200, /* 0b038200 //C 0fa10 ld	r0,r3+,r2	; get first char of next string */
0x0000fa11, 0x020b0000, /* 020b0000 //C 0fa11 sz	r0 */
0x0000fa12, 0x11f2fa15, /* 11f2fa15 //C 0fa12 jz	h_eof */
0x0000fa13, 0x0400fabf, /* 0400fabf //C 0fa13 call	putchar */
0x0000fa14, 0x01f2fa0d, /* 01f2fa0d //C 0fa14 jmp	h_cyc */
0x0000fa15, 0x0fed0000, /* 0fed0000 //C 0fa15 pop	lr */
0x0000fa16, 0x00f00e00, /* 00f00e00 //C 0fa16 ret */
0x0000fa17, 0x0d1d0000, /* 0d1d0000 //C 0fa17 push	r1 */
0x0000fa18, 0x0d2d0000, /* 0d2d0000 //C 0fa18 push	r2 */
0x0000fa19, 0x0e210000, /* 0e210000 //C 0fa19 ld	r2,r1 */
0x0000fa1a, 0x022b0000, /* 022b0000 //C 0fa1a sz	r2 */
0x0000fa1b, 0x11f2fa22, /* 11f2fa22 //C 0fa1b jz	strchr_no	; eof string found */
0x0000fa1c, 0x00280000, /* 00280000 //C 0fa1c cmp	r2,r0		; compare */
0x0000fa1d, 0x11f2fa20, /* 11f2fa20 //C 0fa1d jz	strchr_yes */
0x0000fa1e, 0x011a0001, /* 011a0001 //C 0fa1e plus	r1,1		; go to next char */
0x0000fa1f, 0x01f2fa19, /* 01f2fa19 //C 0fa1f jmp	strchr_cyc */
0x0000fa20, 0x020c0000, /* 020c0000 //C 0fa20 sec */
0x0000fa21, 0x01f2fa24, /* 01f2fa24 //C 0fa21 jmp	strchr_ret */
0x0000fa22, 0x01120000, /* 01120000 //C 0fa22 mvzl	r1,0 */
0x0000fa23, 0x020d0000, /* 020d0000 //C 0fa23 clc */
0x0000fa24, 0x0f2d0000, /* 0f2d0000 //C 0fa24 pop	r2 */
0x0000fa25, 0x0f1d0000, /* 0f1d0000 //C 0fa25 pop	r1 */
0x0000fa26, 0x00f00e00, /* 00f00e00 //C 0fa26 ret */
0x0000fa27, 0x0ded0000, /* 0ded0000 //C 0fa27 push	lr		; Save used registers */
0x0000fa28, 0x0d0d0000, /* 0d0d0000 //C 0fa28 push	r0		; and input parameters */
0x0000fa29, 0x0d1d0000, /* 0d1d0000 //C 0fa29 push	r1 */
0x0000fa2a, 0x0d2d0000, /* 0d2d0000 //C 0fa2a push	r2 */
0x0000fa2b, 0x0d4d0000, /* 0d4d0000 //C 0fa2b push	r4 */
0x0000fa2c, 0x0d5d0000, /* 0d5d0000 //C 0fa2c push	r5 */
0x0000fa2d, 0x0d6d0000, /* 0d6d0000 //C 0fa2d push	r6 */
0x0000fa2e, 0x0e200000, /* 0e200000 //C 0fa2e ld	r2,r0		; Got one-one char */
0x0000fa2f, 0x0e610000, /* 0e610000 //C 0fa2f ld	r6,r1		; from two strings */
0x0000fa30, 0x023b0000, /* 023b0000 //C 0fa30 sz	r3		; Prepare for comparing */
0x0000fa31, 0x112d0020, /* 112d0020 //C 0fa31 Z1 or	r2,0x20		; if insensitive case */
0x0000fa32, 0x023b0000, /* 023b0000 //C 0fa32 sz	r3 */
0x0000fa33, 0x116d0020, /* 116d0020 //C 0fa33 Z1 or	r6,0x20 */
0x0000fa34, 0x00280600, /* 00280600 //C 0fa34 cmp	r2,r6		; compare them */
0x0000fa35, 0x21f2fa47, /* 21f2fa47 //C 0fa35 jnz	streq_no	; if differs: strings are not equal */
0x0000fa36, 0x0e200000, /* 0e200000 //C 0fa36 ld	r2,r0		; Pick original (non-prepared) */
0x0000fa37, 0x0e610000, /* 0e610000 //C 0fa37 ld	r6,r1		; chars to check EOS */
0x0000fa38, 0x022b0000, /* 022b0000 //C 0fa38 sz	r2		; convert them to boolean */
0x0000fa39, 0x21220001, /* 21220001 //C 0fa39 Z0 mvzl	r2,1		; values in R2,R6 */
0x0000fa3a, 0x11220000, /* 11220000 //C 0fa3a Z1 mvzl	r2,0		; and copy in R4,R5 */
0x0000fa3b, 0x00400200, /* 00400200 //C 0fa3b mov	r4,r2 */
0x0000fa3c, 0x026b0000, /* 026b0000 //C 0fa3c sz	r6 */
0x0000fa3d, 0x21620001, /* 21620001 //C 0fa3d Z0 mvzl	r6,1 */
0x0000fa3e, 0x11620000, /* 11620000 //C 0fa3e Z1 mvzl r6,0 */
0x0000fa3f, 0x00500600, /* 00500600 //C 0fa3f mov	r5,r6 */
0x0000fa40, 0x004d0500, /* 004d0500 //C 0fa40 or	r4,r5		; if both are EOS: equal */
0x0000fa41, 0x11f2fa49, /* 11f2fa49 //C 0fa41 jz	streq_yes */
0x0000fa42, 0x002f0600, /* 002f0600 //C 0fa42 and 	r2,r6		; just one is EOS: not equal */
0x0000fa43, 0x11f2fa47, /* 11f2fa47 //C 0fa43 jz	streq_no */
0x0000fa44, 0x010a0001, /* 010a0001 //C 0fa44 plus	r0,1		; non are EOS: go to check next char */
0x0000fa45, 0x011a0001, /* 011a0001 //C 0fa45 plus	r1,1 */
0x0000fa46, 0x01f2fa2e, /* 01f2fa2e //C 0fa46 jmp	streq_cyc */
0x0000fa47, 0x020d0000, /* 020d0000 //C 0fa47 clc			; False result */
0x0000fa48, 0x01f2fa4a, /* 01f2fa4a //C 0fa48 jmp	streq_ret */
0x0000fa49, 0x020c0000, /* 020c0000 //C 0fa49 sec			; True result */
0x0000fa4a, 0x0f6d0000, /* 0f6d0000 //C 0fa4a pop	r6 */
0x0000fa4b, 0x0f5d0000, /* 0f5d0000 //C 0fa4b pop	r5 */
0x0000fa4c, 0x0f4d0000, /* 0f4d0000 //C 0fa4c pop	r4 */
0x0000fa4d, 0x0f2d0000, /* 0f2d0000 //C 0fa4d pop	r2 */
0x0000fa4e, 0x0f1d0000, /* 0f1d0000 //C 0fa4e pop	r1 */
0x0000fa4f, 0x0f0d0000, /* 0f0d0000 //C 0fa4f pop	r0 */
0x0000fa50, 0x0fed0000, /* 0fed0000 //C 0fa50 pop	lr */
0x0000fa51, 0x00f00e00, /* 00f00e00 //C 0fa51 ret */
0x0000fa52, 0x0ded0000, /* 0ded0000 //C 0fa52 push	lr */
0x0000fa53, 0x0d3d0000, /* 0d3d0000 //C 0fa53 push	r3 */
0x0000fa54, 0x01320001, /* 01320001 //C 0fa54 mvzl	r3,1 */
0x0000fa55, 0x0400fa27, /* 0400fa27 //C 0fa55 call	str_cmp_eq */
0x0000fa56, 0x0f3d0000, /* 0f3d0000 //C 0fa56 pop	r3 */
0x0000fa57, 0x0fed0000, /* 0fed0000 //C 0fa57 pop	lr */
0x0000fa58, 0x00f00e00, /* 00f00e00 //C 0fa58 ret */
0x0000fa59, 0x0ded0000, /* 0ded0000 //C 0fa59 push	lr */
0x0000fa5a, 0x0d3d0000, /* 0d3d0000 //C 0fa5a push	r3 */
0x0000fa5b, 0x01320000, /* 01320000 //C 0fa5b mvzl	r3,0 */
0x0000fa5c, 0x0400fa27, /* 0400fa27 //C 0fa5c call	str_cmp_eq */
0x0000fa5d, 0x0f3d0000, /* 0f3d0000 //C 0fa5d pop	r3 */
0x0000fa5e, 0x0fed0000, /* 0fed0000 //C 0fa5e pop	lr */
0x0000fa5f, 0x00f00e00, /* 00f00e00 //C 0fa5f ret */
0x0000fa60, 0x0108002f, /* 0108002f //C 0fa60 cmp	r0,'/' */
0x0000fa61, 0xa1f2fa76, /* a1f2fa76 //C 0fa61 LS jmp	hc2v_nok */
0x0000fa62, 0x01080039, /* 01080039 //C 0fa62 cmp	r0,'9' */
0x0000fa63, 0xa1f2fa73, /* a1f2fa73 //C 0fa63 LS jmp	hc2v_0_9 */
0x0000fa64, 0x01080040, /* 01080040 //C 0fa64 cmp	r0,'@' */
0x0000fa65, 0xa1f2fa76, /* a1f2fa76 //C 0fa65 LS jmp	hc2v_nok */
0x0000fa66, 0x01080046, /* 01080046 //C 0fa66 cmp	r0,'F' */
0x0000fa67, 0xa1f2fa70, /* a1f2fa70 //C 0fa67 LS jmp	hc2v_A_F */
0x0000fa68, 0x01080060, /* 01080060 //C 0fa68 cmp	r0,'`' */
0x0000fa69, 0xa1f2fa76, /* a1f2fa76 //C 0fa69 LS jmp	hc2v_nok */
0x0000fa6a, 0x01080066, /* 01080066 //C 0fa6a cmp	r0,'f' */
0x0000fa6b, 0xa1f2fa6d, /* a1f2fa6d //C 0fa6b LS jmp	hc2v_a_f */
0x0000fa6c, 0x01f2fa76, /* 01f2fa76 //C 0fa6c jmp	hc2v_nok */
0x0000fa6d, 0x0104000a, /* 0104000a //C 0fa6d add	r0,10 */
0x0000fa6e, 0x01060061, /* 01060061 //C 0fa6e sub	r0,'a' */
0x0000fa6f, 0x01f2fa74, /* 01f2fa74 //C 0fa6f jmp	hc2v_ok */
0x0000fa70, 0x0104000a, /* 0104000a //C 0fa70 add	r0,10 */
0x0000fa71, 0x01060041, /* 01060041 //C 0fa71 sub	r0,'A' */
0x0000fa72, 0x01f2fa74, /* 01f2fa74 //C 0fa72 jmp	hc2v_ok */
0x0000fa73, 0x01060030, /* 01060030 //C 0fa73 sub	r0,'0' */
0x0000fa74, 0x020c0000, /* 020c0000 //C 0fa74 sec */
0x0000fa75, 0x00f00e00, /* 00f00e00 //C 0fa75 ret */
0x0000fa76, 0x020d0000, /* 020d0000 //C 0fa76 clc */
0x0000fa77, 0x00f00e00, /* 00f00e00 //C 0fa77 ret */
0x0000fa78, 0x0d1d0000, /* 0d1d0000 //C 0fa78 push	r1 */
0x0000fa79, 0x010f000f, /* 010f000f //C 0fa79 and	r0,0xf */
0x0000fa7a, 0x0112fa7e, /* 0112fa7e //C 0fa7a mvzl	r1,v2hc_table */
0x0000fa7b, 0x0a010000, /* 0a010000 //C 0fa7b ld	r0,r1,r0 */
0x0000fa7c, 0x0f1d0000, /* 0f1d0000 //C 0fa7c pop	r1 */
0x0000fa7d, 0x00f00e00, /* 00f00e00 //C 0fa7d ret */
0x0000fa7e, 0x00000030, /* 00000030 //C 0fa7e db	48 */
0x0000fa7f, 0x00000031, /* 00000031 //C 0fa7f db	49 */
0x0000fa80, 0x00000032, /* 00000032 //C 0fa80 db	50 */
0x0000fa81, 0x00000033, /* 00000033 //C 0fa81 db	51 */
0x0000fa82, 0x00000034, /* 00000034 //C 0fa82 db	52 */
0x0000fa83, 0x00000035, /* 00000035 //C 0fa83 db	53 */
0x0000fa84, 0x00000036, /* 00000036 //C 0fa84 db	54 */
0x0000fa85, 0x00000037, /* 00000037 //C 0fa85 db	55 */
0x0000fa86, 0x00000038, /* 00000038 //C 0fa86 db	56 */
0x0000fa87, 0x00000039, /* 00000039 //C 0fa87 db	57 */
0x0000fa88, 0x00000041, /* 00000041 //C 0fa88 db	65 */
0x0000fa89, 0x00000042, /* 00000042 //C 0fa89 db	66 */
0x0000fa8a, 0x00000043, /* 00000043 //C 0fa8a db	67 */
0x0000fa8b, 0x00000044, /* 00000044 //C 0fa8b db	68 */
0x0000fa8c, 0x00000045, /* 00000045 //C 0fa8c db	69 */
0x0000fa8d, 0x00000046, /* 00000046 //C 0fa8d db	70 */
0x0000fa8e, 0x00000000, /* 00000000 //C 0fa8e db */
0x0000fa8f, 0x0ded0000, /* 0ded0000 //C 0fa8f push	lr */
0x0000fa90, 0x0400fa78, /* 0400fa78 //C 0fa90 call	value2Hexchar */
0x0000fa91, 0x010d0020, /* 010d0020 //C 0fa91 or	r0,0x20 */
0x0000fa92, 0x0fed0000, /* 0fed0000 //C 0fa92 pop	lr */
0x0000fa93, 0x00f00e00, /* 00f00e00 //C 0fa93 ret */
0x0000fa94, 0x0ded0000, /* 0ded0000 //C 0fa94 push	lr */
0x0000fa95, 0x0d2d0000, /* 0d2d0000 //C 0fa95 push	r2 */
0x0000fa96, 0x0d3d0000, /* 0d3d0000 //C 0fa96 push	r3 */
0x0000fa97, 0x01120000, /* 01120000 //C 0fa97 mvzl	r1,0		; return value */
0x0000fa98, 0x01320000, /* 01320000 //C 0fa98 mvzl	r3,0		; index */
0x0000fa99, 0x0b238000, /* 0b238000 //C 0fa99 ld	r2,r3+,r0	; pick a char */
0x0000fa9a, 0x022b0000, /* 022b0000 //C 0fa9a sz	r2		; check eof string */
0x0000fa9b, 0x11f2faaf, /* 11f2faaf //C 0fa9b jz	htoi_eos */
0x0000fa9c, 0x0128002e, /* 0128002e //C 0fa9c cmp	r2,'.'		; skip separators */
0x0000fa9d, 0x11f2fa99, /* 11f2fa99 //C 0fa9d jz	htoi_cyc */
0x0000fa9e, 0x0128005f, /* 0128005f //C 0fa9e cmp	r2,'_' */
0x0000fa9f, 0x11f2fa99, /* 11f2fa99 //C 0fa9f jz	htoi_cyc */
0x0000faa0, 0x0d0d0000, /* 0d0d0000 //C 0faa0 push	r0 */
0x0000faa1, 0x00000200, /* 00000200 //C 0faa1 mov	r0,r2 */
0x0000faa2, 0x0400fa60, /* 0400fa60 //C 0faa2 call	hexchar2value */
0x0000faa3, 0x00200000, /* 00200000 //C 0faa3 mov	r2,r0 */
0x0000faa4, 0x0f0d0000, /* 0f0d0000 //C 0faa4 pop	r0 */
0x0000faa5, 0x41f2faad, /* 41f2faad //C 0faa5 C0 jmp	htoi_nok */
0x0000faa6, 0x02180000, /* 02180000 //C 0faa6 shl	r1 */
0x0000faa7, 0x02180000, /* 02180000 //C 0faa7 shl	r1 */
0x0000faa8, 0x02180000, /* 02180000 //C 0faa8 shl	r1 */
0x0000faa9, 0x02180000, /* 02180000 //C 0faa9 shl	r1 */
0x0000faaa, 0x012f000f, /* 012f000f //C 0faaa and	r2,0xf */
0x0000faab, 0x001d0200, /* 001d0200 //C 0faab or	r1,r2 */
0x0000faac, 0x01f2fa99, /* 01f2fa99 //C 0faac jmp	htoi_cyc */
0x0000faad, 0x020d0000, /* 020d0000 //C 0faad clc */
0x0000faae, 0x01f2fab2, /* 01f2fab2 //C 0faae jmp	htoi_ret */
0x0000faaf, 0x01380001, /* 01380001 //C 0faaf cmp	r3,1 */
0x0000fab0, 0x920d0000, /* 920d0000 //C 0fab0 HI clc */
0x0000fab1, 0xa20c0000, /* a20c0000 //C 0fab1 LS sec */
0x0000fab2, 0x0f3d0000, /* 0f3d0000 //C 0fab2 pop	r3 */
0x0000fab3, 0x0f2d0000, /* 0f2d0000 //C 0fab3 pop	r2 */
0x0000fab4, 0x0fed0000, /* 0fed0000 //C 0fab4 pop	lr */
0x0000fab5, 0x00f00e00, /* 00f00e00 //C 0fab5 ret */
0x0000fab6, 0x0d0d0000, /* 0d0d0000 //C 0fab6 push	r0 */
0x0000fab7, 0x0700ff42, /* 0700ff42 //C 0fab7 ld	r0,UART_RSTAT */
0x0000fab8, 0x010c0001, /* 010c0001 //C 0fab8 test	r0,1 */
0x0000fab9, 0x020d0000, /* 020d0000 //C 0fab9 clc */
0x0000faba, 0x220c0000, /* 220c0000 //C 0faba Z0 sec */
0x0000fabb, 0x0f0d0000, /* 0f0d0000 //C 0fabb pop	r0 */
0x0000fabc, 0x00f00e00, /* 00f00e00 //C 0fabc ret */
0x0000fabd, 0x0700ff40, /* 0700ff40 //C 0fabd ld	r0,UART_DR */
0x0000fabe, 0x00f00e00, /* 00f00e00 //C 0fabe ret */
0x0000fabf, 0x0d9d0000, /* 0d9d0000 //C 0fabf push	r9 */
0x0000fac0, 0x0790ff43, /* 0790ff43 //C 0fac0 ld	r9,UART_TSTAT */
0x0000fac1, 0x019c0001, /* 019c0001 //C 0fac1 test	r9,1 */
0x0000fac2, 0x11f2fac0, /* 11f2fac0 //C 0fac2 jz	wait_tc */
0x0000fac3, 0x0600ff40, /* 0600ff40 //C 0fac3 st	r0,UART_DR */
0x0000fac4, 0x0f9d0000, /* 0f9d0000 //C 0fac4 pop	r9 */
0x0000fac5, 0x00f00e00, /* 00f00e00 //C 0fac5 ret */
0x0000fac6, 0x0ded0000, /* 0ded0000 //C 0fac6 push	lr */
0x0000fac7, 0x0d0d0000, /* 0d0d0000 //C 0fac7 push	r0 */
0x0000fac8, 0x0d3d0000, /* 0d3d0000 //C 0fac8 push	r3 */
0x0000fac9, 0x0d4d0000, /* 0d4d0000 //C 0fac9 push	r4 */
0x0000faca, 0x01420000, /* 01420000 //C 0faca mvzl	r4,0 */
0x0000facb, 0x020b0000, /* 020b0000 //C 0facb sz	r0 */
0x0000facc, 0x1102fba0, /* 1102fba0 //C 0facc Z1 mvzl	r0,null_str */
0x0000facd, 0x0b348000, /* 0b348000 //C 0facd ld	r3,r4+,r0 */
0x0000face, 0x023b0000, /* 023b0000 //C 0face sz	r3 */
0x0000facf, 0x11f2fad5, /* 11f2fad5 //C 0facf jz	prints_done */
0x0000fad0, 0x0d0d0000, /* 0d0d0000 //C 0fad0 push	r0 */
0x0000fad1, 0x00000300, /* 00000300 //C 0fad1 mov	r0,r3 */
0x0000fad2, 0x0400fabf, /* 0400fabf //C 0fad2 call	putchar */
0x0000fad3, 0x0f0d0000, /* 0f0d0000 //C 0fad3 pop	r0 */
0x0000fad4, 0x01f2facd, /* 01f2facd //C 0fad4 jmp	prints_go */
0x0000fad5, 0x0f4d0000, /* 0f4d0000 //C 0fad5 pop	r4 */
0x0000fad6, 0x0f3d0000, /* 0f3d0000 //C 0fad6 pop	r3 */
0x0000fad7, 0x0f0d0000, /* 0f0d0000 //C 0fad7 pop	r0 */
0x0000fad8, 0x0fed0000, /* 0fed0000 //C 0fad8 pop	lr */
0x0000fad9, 0x00f00e00, /* 00f00e00 //C 0fad9 ret */
0x0000fada, 0x0ded0000, /* 0ded0000 //C 0fada push	lr */
0x0000fadb, 0x0400fac6, /* 0400fac6 //C 0fadb call	prints */
0x0000fadc, 0x0d0d0000, /* 0d0d0000 //C 0fadc push	r0 */
0x0000fadd, 0x0102000a, /* 0102000a //C 0fadd mvzl	r0,LF */
0x0000fade, 0x0400fabf, /* 0400fabf //C 0fade call	putchar */
0x0000fadf, 0x0f0d0000, /* 0f0d0000 //C 0fadf pop	r0 */
0x0000fae0, 0x0fed0000, /* 0fed0000 //C 0fae0 pop	lr */
0x0000fae1, 0x00f00e00, /* 00f00e00 //C 0fae1 ret */
0x0000fae2, 0x0ded0000, /* 0ded0000 //C 0fae2 push	lr */
0x0000fae3, 0x0d0d0000, /* 0d0d0000 //C 0fae3 push	r0 */
0x0000fae4, 0x0d1d0000, /* 0d1d0000 //C 0fae4 push	r1 */
0x0000fae5, 0x0d2d0000, /* 0d2d0000 //C 0fae5 push	r2 */
0x0000fae6, 0x0d3d0000, /* 0d3d0000 //C 0fae6 push	r3 */
0x0000fae7, 0x0d4d0000, /* 0d4d0000 //C 0fae7 push	r4 */
0x0000fae8, 0x00300000, /* 00300000 //C 0fae8 mov	r3,r0 */
0x0000fae9, 0x01220000, /* 01220000 //C 0fae9 mvzl	r2,0 */
0x0000faea, 0x01420001, /* 01420001 //C 0faea mvzl	r4,1 */
0x0000faeb, 0x01020000, /* 01020000 //C 0faeb mvzl	r0,0 */
0x0000faec, 0x02380000, /* 02380000 //C 0faec shl	r3 */
0x0000faed, 0x02070000, /* 02070000 //C 0faed rol	r0 */
0x0000faee, 0x02380000, /* 02380000 //C 0faee shl	r3 */
0x0000faef, 0x02070000, /* 02070000 //C 0faef rol	r0 */
0x0000faf0, 0x02380000, /* 02380000 //C 0faf0 shl	r3 */
0x0000faf1, 0x02070000, /* 02070000 //C 0faf1 rol	r0 */
0x0000faf2, 0x02380000, /* 02380000 //C 0faf2 shl	r3 */
0x0000faf3, 0x02070000, /* 02070000 //C 0faf3 rol	r0 */
0x0000faf4, 0x0400fa78, /* 0400fa78 //C 0faf4 call	value2Hexchar */
0x0000faf5, 0x0400fabf, /* 0400fabf //C 0faf5 call	putchar */
0x0000faf6, 0x01240001, /* 01240001 //C 0faf6 add	r2,1 */
0x0000faf7, 0x01280008, /* 01280008 //C 0faf7 cmp	r2,8 */
0x0000faf8, 0x11f2fb02, /* 11f2fb02 //C 0faf8 jz	print_vhex_ret */
0x0000faf9, 0x021b0000, /* 021b0000 //C 0faf9 sz	r1 */
0x0000fafa, 0x11f2fb00, /* 11f2fb00 //C 0fafa jz	print_vhex_nosep */
0x0000fafb, 0x00480100, /* 00480100 //C 0fafb cmp	r4,r1 */
0x0000fafc, 0x21f2fb00, /* 21f2fb00 //C 0fafc jnz	print_vhex_nosep */
0x0000fafd, 0x0102005f, /* 0102005f //C 0fafd mvzl	r0,'_' */
0x0000fafe, 0x0400fabf, /* 0400fabf //C 0fafe call	putchar */
0x0000faff, 0x01420000, /* 01420000 //C 0faff mvzl	r4,0 */
0x0000fb00, 0x01440001, /* 01440001 //C 0fb00 add	r4,1 */
0x0000fb01, 0x01f2faeb, /* 01f2faeb //C 0fb01 jmp	print_vhex_cyc */
0x0000fb02, 0x0f4d0000, /* 0f4d0000 //C 0fb02 pop	r4 */
0x0000fb03, 0x0f3d0000, /* 0f3d0000 //C 0fb03 pop	r3 */
0x0000fb04, 0x0f2d0000, /* 0f2d0000 //C 0fb04 pop	r2 */
0x0000fb05, 0x0f1d0000, /* 0f1d0000 //C 0fb05 pop	r1 */
0x0000fb06, 0x0f0d0000, /* 0f0d0000 //C 0fb06 pop	r0 */
0x0000fb07, 0x0fed0000, /* 0fed0000 //C 0fb07 pop	lr */
0x0000fb08, 0x00f00e00, /* 00f00e00 //C 0fb08 ret */
0x0000fb75, 0x00000000, /* 00000000 //C 0fb75 dd	0 */
0x0000fb76, 0x00000000, /* 00000000 //C 0fb76 dd	0 */
0x0000fb77, 0x00000000, /* 00000000 //C 0fb77 dd	0 */
0x0000fb78, 0x00000000, /* 00000000 //C 0fb78 dd	0 */
0x0000fb79, 0x00000000, /* 00000000 //C 0fb79 dd	0 */
0x0000fb7a, 0x00000000, /* 00000000 //C 0fb7a dd	0 */
0x0000fb7b, 0x00000000, /* 00000000 //C 0fb7b dd	0 */
0x0000fb7c, 0x00000000, /* 00000000 //C 0fb7c dd	0 */
0x0000fb7d, 0x00000000, /* 00000000 //C 0fb7d dd	0 */
0x0000fb7e, 0x00000000, /* 00000000 //C 0fb7e dd	0 */
0x0000fb7f, 0x00000000, /* 00000000 //C 0fb7f dd	0 */
0x0000fb80, 0x00000000, /* 00000000 //C 0fb80 dd	0 */
0x0000fb81, 0x00000000, /* 00000000 //C 0fb81 dd	0 */
0x0000fb82, 0x00000000, /* 00000000 //C 0fb82 dd	0 */
0x0000fb83, 0x00000000, /* 00000000 //C 0fb83 dd	0 */
0x0000fb84, 0x00000000, /* 00000000 //C 0fb84 dd	0 */
0x0000fb85, 0x00000000, /* 00000000 //C 0fb85 dd	0 */
0x0000fb86, 0x00000000, /* 00000000 //C 0fb86 dd	0 */
0x0000fb87, 0x00000050, /* 00000050 //C 0fb87 db	80 */
0x0000fb88, 0x0000004d, /* 0000004d //C 0fb88 db	77 */
0x0000fb89, 0x0000006f, /* 0000006f //C 0fb89 db	111 */
0x0000fb8a, 0x0000006e, /* 0000006e //C 0fb8a db	110 */
0x0000fb8b, 0x00000069, /* 00000069 //C 0fb8b db	105 */
0x0000fb8c, 0x00000074, /* 00000074 //C 0fb8c db	116 */
0x0000fb8d, 0x0000006f, /* 0000006f //C 0fb8d db	111 */
0x0000fb8e, 0x00000072, /* 00000072 //C 0fb8e db	114 */
0x0000fb8f, 0x00000020, /* 00000020 //C 0fb8f db	32 */
0x0000fb90, 0x00000076, /* 00000076 //C 0fb90 db	118 */
0x0000fb91, 0x00000031, /* 00000031 //C 0fb91 db	49 */
0x0000fb92, 0x0000002e, /* 0000002e //C 0fb92 db	46 */
0x0000fb93, 0x00000030, /* 00000030 //C 0fb93 db	48 */
0x0000fb94, 0x00000000, /* 00000000 //C 0fb94 db */
0x0000fb95, 0x0000003e, /* 0000003e //C 0fb95 db	62 */
0x0000fb96, 0x00000000, /* 00000000 //C 0fb96 db */
0x0000fb97, 0x00000020, /* 00000020 //C 0fb97 db	32 */
0x0000fb98, 0x0000003b, /* 0000003b //C 0fb98 db	59 */
0x0000fb99, 0x00000009, /* 00000009 //C 0fb99 db	9 */
0x0000fb9a, 0x0000000b, /* 0000000b //C 0fb9a db	11 */
0x0000fb9b, 0x0000002c, /* 0000002c //C 0fb9b db	44 */
0x0000fb9c, 0x0000003d, /* 0000003d //C 0fb9c db	61 */
0x0000fb9d, 0x0000005b, /* 0000005b //C 0fb9d db	91 */
0x0000fb9e, 0x0000005d, /* 0000005d //C 0fb9e db	93 */
0x0000fb9f, 0x00000000, /* 00000000 //C 0fb9f db */
0x0000fba0, 0x00000028, /* 00000028 //C 0fba0 db	40 */
0x0000fba1, 0x0000006e, /* 0000006e //C 0fba1 db	110 */
0x0000fba2, 0x00000075, /* 00000075 //C 0fba2 db	117 */
0x0000fba3, 0x0000006c, /* 0000006c //C 0fba3 db	108 */
0x0000fba4, 0x0000006c, /* 0000006c //C 0fba4 db	108 */
0x0000fba5, 0x00000029, /* 00000029 //C 0fba5 db	41 */
0x0000fba6, 0x00000000, /* 00000000 //C 0fba6 db */
0x0000fba7, 0x0000f8d8, /* 0000f8d8 //C 0fba7 dd	cmd_m */
0x0000fba8, 0x0000006d, /* 0000006d //C 0fba8 db	109 */
0x0000fba9, 0x00000000, /* 00000000 //C 0fba9 db */
0x0000fbaa, 0x0000f8d8, /* 0000f8d8 //C 0fbaa dd	cmd_m */
0x0000fbab, 0x0000006d, /* 0000006d //C 0fbab db	109 */
0x0000fbac, 0x00000065, /* 00000065 //C 0fbac db	101 */
0x0000fbad, 0x0000006d, /* 0000006d //C 0fbad db	109 */
0x0000fbae, 0x00000000, /* 00000000 //C 0fbae db */
0x0000fbaf, 0x0000f92d, /* 0000f92d //C 0fbaf dd	cmd_d */
0x0000fbb0, 0x00000064, /* 00000064 //C 0fbb0 db	100 */
0x0000fbb1, 0x00000000, /* 00000000 //C 0fbb1 db */
0x0000fbb2, 0x0000f92d, /* 0000f92d //C 0fbb2 dd	cmd_d */
0x0000fbb3, 0x00000064, /* 00000064 //C 0fbb3 db	100 */
0x0000fbb4, 0x00000075, /* 00000075 //C 0fbb4 db	117 */
0x0000fbb5, 0x0000006d, /* 0000006d //C 0fbb5 db	109 */
0x0000fbb6, 0x00000070, /* 00000070 //C 0fbb6 db	112 */
0x0000fbb7, 0x00000000, /* 00000000 //C 0fbb7 db */
0x0000fbb8, 0x0000f960, /* 0000f960 //C 0fbb8 dd	cmd_e */
0x0000fbb9, 0x00000065, /* 00000065 //C 0fbb9 db	101 */
0x0000fbba, 0x00000000, /* 00000000 //C 0fbba db */
0x0000fbbb, 0x0000f962, /* 0000f962 //C 0fbbb dd	cmd_l */
0x0000fbbc, 0x0000006c, /* 0000006c //C 0fbbc db	108 */
0x0000fbbd, 0x00000000, /* 00000000 //C 0fbbd db */
0x0000fbbe, 0x0000f962, /* 0000f962 //C 0fbbe dd	cmd_l */
0x0000fbbf, 0x0000006c, /* 0000006c //C 0fbbf db	108 */
0x0000fbc0, 0x0000006f, /* 0000006f //C 0fbc0 db	111 */
0x0000fbc1, 0x00000061, /* 00000061 //C 0fbc1 db	97 */
0x0000fbc2, 0x00000064, /* 00000064 //C 0fbc2 db	100 */
0x0000fbc3, 0x00000000, /* 00000000 //C 0fbc3 db */
0x0000fbc4, 0x0000f9cf, /* 0000f9cf //C 0fbc4 dd	cmd_g */
0x0000fbc5, 0x00000067, /* 00000067 //C 0fbc5 db	103 */
0x0000fbc6, 0x00000000, /* 00000000 //C 0fbc6 db */
0x0000fbc7, 0x0000f9cf, /* 0000f9cf //C 0fbc7 dd	cmd_g */
0x0000fbc8, 0x00000067, /* 00000067 //C 0fbc8 db	103 */
0x0000fbc9, 0x0000006f, /* 0000006f //C 0fbc9 db	111 */
0x0000fbca, 0x00000000, /* 00000000 //C 0fbca db */
0x0000fbcb, 0x0000f9cf, /* 0000f9cf //C 0fbcb dd	cmd_g */
0x0000fbcc, 0x00000072, /* 00000072 //C 0fbcc db	114 */
0x0000fbcd, 0x00000075, /* 00000075 //C 0fbcd db	117 */
0x0000fbce, 0x0000006e, /* 0000006e //C 0fbce db	110 */
0x0000fbcf, 0x00000000, /* 00000000 //C 0fbcf db */
0x0000fbd0, 0x0000fa0a, /* 0000fa0a //C 0fbd0 dd	cmd_h */
0x0000fbd1, 0x0000003f, /* 0000003f //C 0fbd1 db	63 */
0x0000fbd2, 0x00000000, /* 00000000 //C 0fbd2 db */
0x0000fbd3, 0x0000fa0a, /* 0000fa0a //C 0fbd3 dd	cmd_h */
0x0000fbd4, 0x00000068, /* 00000068 //C 0fbd4 db	104 */
0x0000fbd5, 0x00000000, /* 00000000 //C 0fbd5 db */
0x0000fbd6, 0x0000fa0a, /* 0000fa0a //C 0fbd6 dd	cmd_h */
0x0000fbd7, 0x00000068, /* 00000068 //C 0fbd7 db	104 */
0x0000fbd8, 0x00000065, /* 00000065 //C 0fbd8 db	101 */
0x0000fbd9, 0x0000006c, /* 0000006c //C 0fbd9 db	108 */
0x0000fbda, 0x00000070, /* 00000070 //C 0fbda db	112 */
0x0000fbdb, 0x00000000, /* 00000000 //C 0fbdb db */
0x0000fbdc, 0x00000000, /* 00000000 //C 0fbdc dd	0 */
0x0000fbdd, 0x00000000, /* 00000000 //C 0fbdd dd	0 */
0x0000fbde, 0x0000006d, /* 0000006d //C 0fbde db	109 */
0x0000fbdf, 0x0000005b, /* 0000005b //C 0fbdf db	91 */
0x0000fbe0, 0x00000065, /* 00000065 //C 0fbe0 db	101 */
0x0000fbe1, 0x0000006d, /* 0000006d //C 0fbe1 db	109 */
0x0000fbe2, 0x0000005d, /* 0000005d //C 0fbe2 db	93 */
0x0000fbe3, 0x00000020, /* 00000020 //C 0fbe3 db	32 */
0x0000fbe4, 0x00000020, /* 00000020 //C 0fbe4 db	32 */
0x0000fbe5, 0x00000061, /* 00000061 //C 0fbe5 db	97 */
0x0000fbe6, 0x00000064, /* 00000064 //C 0fbe6 db	100 */
0x0000fbe7, 0x00000064, /* 00000064 //C 0fbe7 db	100 */
0x0000fbe8, 0x00000072, /* 00000072 //C 0fbe8 db	114 */
0x0000fbe9, 0x00000020, /* 00000020 //C 0fbe9 db	32 */
0x0000fbea, 0x0000005b, /* 0000005b //C 0fbea db	91 */
0x0000fbeb, 0x00000076, /* 00000076 //C 0fbeb db	118 */
0x0000fbec, 0x00000061, /* 00000061 //C 0fbec db	97 */
0x0000fbed, 0x0000006c, /* 0000006c //C 0fbed db	108 */
0x0000fbee, 0x00000075, /* 00000075 //C 0fbee db	117 */
0x0000fbef, 0x00000065, /* 00000065 //C 0fbef db	101 */
0x0000fbf0, 0x0000005d, /* 0000005d //C 0fbf0 db	93 */
0x0000fbf1, 0x00000020, /* 00000020 //C 0fbf1 db	32 */
0x0000fbf2, 0x00000020, /* 00000020 //C 0fbf2 db	32 */
0x0000fbf3, 0x00000047, /* 00000047 //C 0fbf3 db	71 */
0x0000fbf4, 0x00000065, /* 00000065 //C 0fbf4 db	101 */
0x0000fbf5, 0x00000074, /* 00000074 //C 0fbf5 db	116 */
0x0000fbf6, 0x0000002f, /* 0000002f //C 0fbf6 db	47 */
0x0000fbf7, 0x00000073, /* 00000073 //C 0fbf7 db	115 */
0x0000fbf8, 0x00000065, /* 00000065 //C 0fbf8 db	101 */
0x0000fbf9, 0x00000074, /* 00000074 //C 0fbf9 db	116 */
0x0000fbfa, 0x00000020, /* 00000020 //C 0fbfa db	32 */
0x0000fbfb, 0x0000006d, /* 0000006d //C 0fbfb db	109 */
0x0000fbfc, 0x00000065, /* 00000065 //C 0fbfc db	101 */
0x0000fbfd, 0x0000006d, /* 0000006d //C 0fbfd db	109 */
0x0000fbfe, 0x0000006f, /* 0000006f //C 0fbfe db	111 */
0x0000fbff, 0x00000072, /* 00000072 //C 0fbff db	114 */
0x0000fc00, 0x00000079, /* 00000079 //C 0fc00 db	121 */
0x0000fc01, 0x0000000a, /* 0000000a //C 0fc01 db	10 */
0x0000fc02, 0x00000000, /* 00000000 //C 0fc02 db */
0x0000fc03, 0x00000064, /* 00000064 //C 0fc03 db	100 */
0x0000fc04, 0x0000005b, /* 0000005b //C 0fc04 db	91 */
0x0000fc05, 0x00000075, /* 00000075 //C 0fc05 db	117 */
0x0000fc06, 0x0000006d, /* 0000006d //C 0fc06 db	109 */
0x0000fc07, 0x00000070, /* 00000070 //C 0fc07 db	112 */
0x0000fc08, 0x0000005d, /* 0000005d //C 0fc08 db	93 */
0x0000fc09, 0x00000020, /* 00000020 //C 0fc09 db	32 */
0x0000fc0a, 0x00000073, /* 00000073 //C 0fc0a db	115 */
0x0000fc0b, 0x00000074, /* 00000074 //C 0fc0b db	116 */
0x0000fc0c, 0x00000061, /* 00000061 //C 0fc0c db	97 */
0x0000fc0d, 0x00000072, /* 00000072 //C 0fc0d db	114 */
0x0000fc0e, 0x00000074, /* 00000074 //C 0fc0e db	116 */
0x0000fc0f, 0x00000020, /* 00000020 //C 0fc0f db	32 */
0x0000fc10, 0x00000065, /* 00000065 //C 0fc10 db	101 */
0x0000fc11, 0x0000006e, /* 0000006e //C 0fc11 db	110 */
0x0000fc12, 0x00000064, /* 00000064 //C 0fc12 db	100 */
0x0000fc13, 0x00000020, /* 00000020 //C 0fc13 db	32 */
0x0000fc14, 0x00000020, /* 00000020 //C 0fc14 db	32 */
0x0000fc15, 0x00000020, /* 00000020 //C 0fc15 db	32 */
0x0000fc16, 0x00000020, /* 00000020 //C 0fc16 db	32 */
0x0000fc17, 0x00000020, /* 00000020 //C 0fc17 db	32 */
0x0000fc18, 0x00000044, /* 00000044 //C 0fc18 db	68 */
0x0000fc19, 0x00000075, /* 00000075 //C 0fc19 db	117 */
0x0000fc1a, 0x0000006d, /* 0000006d //C 0fc1a db	109 */
0x0000fc1b, 0x00000070, /* 00000070 //C 0fc1b db	112 */
0x0000fc1c, 0x00000020, /* 00000020 //C 0fc1c db	32 */
0x0000fc1d, 0x0000006d, /* 0000006d //C 0fc1d db	109 */
0x0000fc1e, 0x00000065, /* 00000065 //C 0fc1e db	101 */
0x0000fc1f, 0x0000006d, /* 0000006d //C 0fc1f db	109 */
0x0000fc20, 0x0000006f, /* 0000006f //C 0fc20 db	111 */
0x0000fc21, 0x00000072, /* 00000072 //C 0fc21 db	114 */
0x0000fc22, 0x00000079, /* 00000079 //C 0fc22 db	121 */
0x0000fc23, 0x00000020, /* 00000020 //C 0fc23 db	32 */
0x0000fc24, 0x00000063, /* 00000063 //C 0fc24 db	99 */
0x0000fc25, 0x0000006f, /* 0000006f //C 0fc25 db	111 */
0x0000fc26, 0x0000006e, /* 0000006e //C 0fc26 db	110 */
0x0000fc27, 0x00000074, /* 00000074 //C 0fc27 db	116 */
0x0000fc28, 0x00000065, /* 00000065 //C 0fc28 db	101 */
0x0000fc29, 0x0000006e, /* 0000006e //C 0fc29 db	110 */
0x0000fc2a, 0x00000074, /* 00000074 //C 0fc2a db	116 */
0x0000fc2b, 0x0000000a, /* 0000000a //C 0fc2b db	10 */
0x0000fc2c, 0x00000000, /* 00000000 //C 0fc2c db */
0x0000fc2d, 0x00000065, /* 00000065 //C 0fc2d db	101 */
0x0000fc2e, 0x0000000a, /* 0000000a //C 0fc2e db	10 */
0x0000fc2f, 0x00000000, /* 00000000 //C 0fc2f db */
0x0000fc30, 0x0000006c, /* 0000006c //C 0fc30 db	108 */
0x0000fc31, 0x0000005b, /* 0000005b //C 0fc31 db	91 */
0x0000fc32, 0x0000006f, /* 0000006f //C 0fc32 db	111 */
0x0000fc33, 0x00000061, /* 00000061 //C 0fc33 db	97 */
0x0000fc34, 0x00000064, /* 00000064 //C 0fc34 db	100 */
0x0000fc35, 0x0000005d, /* 0000005d //C 0fc35 db	93 */
0x0000fc36, 0x00000020, /* 00000020 //C 0fc36 db	32 */
0x0000fc37, 0x00000020, /* 00000020 //C 0fc37 db	32 */
0x0000fc38, 0x00000020, /* 00000020 //C 0fc38 db	32 */
0x0000fc39, 0x00000020, /* 00000020 //C 0fc39 db	32 */
0x0000fc3a, 0x00000020, /* 00000020 //C 0fc3a db	32 */
0x0000fc3b, 0x00000020, /* 00000020 //C 0fc3b db	32 */
0x0000fc3c, 0x00000020, /* 00000020 //C 0fc3c db	32 */
0x0000fc3d, 0x00000020, /* 00000020 //C 0fc3d db	32 */
0x0000fc3e, 0x00000020, /* 00000020 //C 0fc3e db	32 */
0x0000fc3f, 0x00000020, /* 00000020 //C 0fc3f db	32 */
0x0000fc40, 0x00000020, /* 00000020 //C 0fc40 db	32 */
0x0000fc41, 0x00000020, /* 00000020 //C 0fc41 db	32 */
0x0000fc42, 0x00000020, /* 00000020 //C 0fc42 db	32 */
0x0000fc43, 0x00000020, /* 00000020 //C 0fc43 db	32 */
0x0000fc44, 0x00000020, /* 00000020 //C 0fc44 db	32 */
0x0000fc45, 0x0000004c, /* 0000004c //C 0fc45 db	76 */
0x0000fc46, 0x0000006f, /* 0000006f //C 0fc46 db	111 */
0x0000fc47, 0x00000061, /* 00000061 //C 0fc47 db	97 */
0x0000fc48, 0x00000064, /* 00000064 //C 0fc48 db	100 */
0x0000fc49, 0x00000020, /* 00000020 //C 0fc49 db	32 */
0x0000fc4a, 0x00000068, /* 00000068 //C 0fc4a db	104 */
0x0000fc4b, 0x00000065, /* 00000065 //C 0fc4b db	101 */
0x0000fc4c, 0x00000078, /* 00000078 //C 0fc4c db	120 */
0x0000fc4d, 0x00000020, /* 00000020 //C 0fc4d db	32 */
0x0000fc4e, 0x00000066, /* 00000066 //C 0fc4e db	102 */
0x0000fc4f, 0x00000069, /* 00000069 //C 0fc4f db	105 */
0x0000fc50, 0x0000006c, /* 0000006c //C 0fc50 db	108 */
0x0000fc51, 0x00000065, /* 00000065 //C 0fc51 db	101 */
0x0000fc52, 0x00000020, /* 00000020 //C 0fc52 db	32 */
0x0000fc53, 0x00000074, /* 00000074 //C 0fc53 db	116 */
0x0000fc54, 0x0000006f, /* 0000006f //C 0fc54 db	111 */
0x0000fc55, 0x00000020, /* 00000020 //C 0fc55 db	32 */
0x0000fc56, 0x0000006d, /* 0000006d //C 0fc56 db	109 */
0x0000fc57, 0x00000065, /* 00000065 //C 0fc57 db	101 */
0x0000fc58, 0x0000006d, /* 0000006d //C 0fc58 db	109 */
0x0000fc59, 0x0000006f, /* 0000006f //C 0fc59 db	111 */
0x0000fc5a, 0x00000072, /* 00000072 //C 0fc5a db	114 */
0x0000fc5b, 0x00000079, /* 00000079 //C 0fc5b db	121 */
0x0000fc5c, 0x0000000a, /* 0000000a //C 0fc5c db	10 */
0x0000fc5d, 0x00000000, /* 00000000 //C 0fc5d db */
0x0000fc5e, 0x00000067, /* 00000067 //C 0fc5e db	103 */
0x0000fc5f, 0x00000028, /* 00000028 //C 0fc5f db	40 */
0x0000fc60, 0x0000006f, /* 0000006f //C 0fc60 db	111 */
0x0000fc61, 0x00000029, /* 00000029 //C 0fc61 db	41 */
0x0000fc62, 0x0000007c, /* 0000007c //C 0fc62 db	124 */
0x0000fc63, 0x00000072, /* 00000072 //C 0fc63 db	114 */
0x0000fc64, 0x00000075, /* 00000075 //C 0fc64 db	117 */
0x0000fc65, 0x0000006e, /* 0000006e //C 0fc65 db	110 */
0x0000fc66, 0x00000020, /* 00000020 //C 0fc66 db	32 */
0x0000fc67, 0x00000061, /* 00000061 //C 0fc67 db	97 */
0x0000fc68, 0x00000064, /* 00000064 //C 0fc68 db	100 */
0x0000fc69, 0x00000064, /* 00000064 //C 0fc69 db	100 */
0x0000fc6a, 0x00000072, /* 00000072 //C 0fc6a db	114 */
0x0000fc6b, 0x00000020, /* 00000020 //C 0fc6b db	32 */
0x0000fc6c, 0x00000020, /* 00000020 //C 0fc6c db	32 */
0x0000fc6d, 0x00000020, /* 00000020 //C 0fc6d db	32 */
0x0000fc6e, 0x00000020, /* 00000020 //C 0fc6e db	32 */
0x0000fc6f, 0x00000020, /* 00000020 //C 0fc6f db	32 */
0x0000fc70, 0x00000020, /* 00000020 //C 0fc70 db	32 */
0x0000fc71, 0x00000020, /* 00000020 //C 0fc71 db	32 */
0x0000fc72, 0x00000020, /* 00000020 //C 0fc72 db	32 */
0x0000fc73, 0x00000052, /* 00000052 //C 0fc73 db	82 */
0x0000fc74, 0x00000075, /* 00000075 //C 0fc74 db	117 */
0x0000fc75, 0x0000006e, /* 0000006e //C 0fc75 db	110 */
0x0000fc76, 0x00000020, /* 00000020 //C 0fc76 db	32 */
0x0000fc77, 0x00000066, /* 00000066 //C 0fc77 db	102 */
0x0000fc78, 0x00000072, /* 00000072 //C 0fc78 db	114 */
0x0000fc79, 0x0000006f, /* 0000006f //C 0fc79 db	111 */
0x0000fc7a, 0x0000006d, /* 0000006d //C 0fc7a db	109 */
0x0000fc7b, 0x00000020, /* 00000020 //C 0fc7b db	32 */
0x0000fc7c, 0x00000061, /* 00000061 //C 0fc7c db	97 */
0x0000fc7d, 0x00000064, /* 00000064 //C 0fc7d db	100 */
0x0000fc7e, 0x00000064, /* 00000064 //C 0fc7e db	100 */
0x0000fc7f, 0x00000072, /* 00000072 //C 0fc7f db	114 */
0x0000fc80, 0x00000065, /* 00000065 //C 0fc80 db	101 */
0x0000fc81, 0x00000073, /* 00000073 //C 0fc81 db	115 */
0x0000fc82, 0x00000073, /* 00000073 //C 0fc82 db	115 */
0x0000fc83, 0x0000000a, /* 0000000a //C 0fc83 db	10 */
0x0000fc84, 0x00000000, /* 00000000 //C 0fc84 db */
0x0000fc85, 0x00000000, /* 00000000 //C 0fc85 dd	0 */
0x0000fd87, 0x00000045, /* 00000045 //C 0fd87 db	69 */
0x0000fd88, 0x0000004f, /* 0000004f //C 0fd88 db	79 */
0x0000fd89, 0x00000046, /* 00000046 //C 0fd89 db	70 */
0x0000fd8a, 0x00000020, /* 00000020 //C 0fd8a db	32 */
0x0000fd8b, 0x00000050, /* 00000050 //C 0fd8b db	80 */
0x0000fd8c, 0x0000004d, /* 0000004d //C 0fd8c db	77 */
0x0000fd8d, 0x0000006f, /* 0000006f //C 0fd8d db	111 */
0x0000fd8e, 0x0000006e, /* 0000006e //C 0fd8e db	110 */
0x0000fd8f, 0x00000069, /* 00000069 //C 0fd8f db	105 */
0x0000fd90, 0x00000074, /* 00000074 //C 0fd90 db	116 */
0x0000fd91, 0x0000006f, /* 0000006f //C 0fd91 db	111 */
0x0000fd92, 0x00000072, /* 00000072 //C 0fd92 db	114 */
0x0000fd93, 0x0000000a, /* 0000000a //C 0fd93 db	10 */
0x0000fd94, 0x00000000, /* 00000000 //C 0fd94 db */
0xffffffff, 0xffffffff
};
