#include "pmon.h"

t_mem pmon[]= {
0x00000000, 0x01f2f825, /* 01f2f825 //C 00000 jmp	cold_start */
0x0000f800, 0x01f2f80e, /* 01f2f80e //C 0f800 _f800:	jmp	callin */
0x0000f801, 0x01f2f825, /* 01f2f825 //C 0f801 _f801:	jmp	cold_start */
0x0000f802, 0x01f2fa5a, /* 01f2fa5a //C 0f802 _f802:	jmp	strchr */
0x0000f803, 0x01f2fa95, /* 01f2fa95 //C 0f803 _f803:	jmp	streq */
0x0000f804, 0x01f2fa9c, /* 01f2fa9c //C 0f804 _f804:	jmp	strieq */
0x0000f805, 0x01f2faa3, /* 01f2faa3 //C 0f805 _f805:	jmp	hexchar2value */
0x0000f806, 0x01f2fad2, /* 01f2fad2 //C 0f806 _f806:	jmp	value2hexchar */
0x0000f807, 0x01f2fad7, /* 01f2fad7 //C 0f807 _f807:	jmp	htoi */
0x0000f808, 0x01f2faf9, /* 01f2faf9 //C 0f808 _f808:	jmp	check_uart */
0x0000f809, 0x01f2fb00, /* 01f2fb00 //C 0f809 _f809:	jmp	read */
0x0000f80a, 0x01f2fb02, /* 01f2fb02 //C 0f80a _f80a:	jmp	putchar */
0x0000f80b, 0x01f2fb09, /* 01f2fb09 //C 0f80b _f80b:	jmp	prints */
0x0000f80c, 0x01f2fb1d, /* 01f2fb1d //C 0f80c _f80c:	jmp	printsnl */
0x0000f80d, 0x01f2fb25, /* 01f2fb25 //C 0f80d _f80d:	jmp	print_vhex */
0x0000f80e, 0x0600fbb9, /* 0600fbb9 //C 0f80e st	r0,reg0 */
0x0000f80f, 0x0610fbba, /* 0610fbba //C 0f80f st	r1,reg1 */
0x0000f810, 0x0620fbbb, /* 0620fbbb //C 0f810 st	r2,reg2 */
0x0000f811, 0x0630fbbc, /* 0630fbbc //C 0f811 st	r3,reg3 */
0x0000f812, 0x0640fbbd, /* 0640fbbd //C 0f812 st	r4,reg4 */
0x0000f813, 0x0650fbbe, /* 0650fbbe //C 0f813 st	r5,reg5 */
0x0000f814, 0x0660fbbf, /* 0660fbbf //C 0f814 st	r6,reg6 */
0x0000f815, 0x0670fbc0, /* 0670fbc0 //C 0f815 st	r7,reg7 */
0x0000f816, 0x0680fbc1, /* 0680fbc1 //C 0f816 st	r8,reg8 */
0x0000f817, 0x0690fbc2, /* 0690fbc2 //C 0f817 st	r9,reg9 */
0x0000f818, 0x06a0fbc3, /* 06a0fbc3 //C 0f818 st	r10,reg10 */
0x0000f819, 0x06b0fbc4, /* 06b0fbc4 //C 0f819 st	r11,reg11 */
0x0000f81a, 0x06c0fbc5, /* 06c0fbc5 //C 0f81a st	r12,reg12 */
0x0000f81b, 0x06d0fbc6, /* 06d0fbc6 //C 0f81b st	r13,reg13 */
0x0000f81c, 0x06e0fbc7, /* 06e0fbc7 //C 0f81c st	r14,reg14 */
0x0000f81d, 0x06e0fbc8, /* 06e0fbc8 //C 0f81d st	r14,reg15 */
0x0000f81e, 0x020e0000, /* 020e0000 //C 0f81e getf	r0 */
0x0000f81f, 0x0600fbc9, /* 0600fbc9 //C 0f81f st	r0,regf */
0x0000f820, 0x01020001, /* 01020001 //C 0f820 mvzl	r0,1 */
0x0000f821, 0x0600fbb8, /* 0600fbb8 //C 0f821 st	r0,called */
0x0000f822, 0x01f2f82f, /* 01f2f82f //C 0f822 jmp	common_start */
0x0000f823, 0x01f2f82f, /* 01f2f82f //C 0f823 jmp	common_start */
0x0000f824, 0x01f2f825, /* 01f2f825 //C 0f824 jmp	cold_start */
0x0000f825, 0x01020000, /* 01020000 //C 0f825 mvzl	r0,0 */
0x0000f826, 0x0600fbb8, /* 0600fbb8 //C 0f826 st	r0,called */
0x0000f827, 0x0102f824, /* 0102f824 //C 0f827 mvzl	r0,def_zero	; restore jmp to monitor at zero */
0x0000f828, 0x0e000000, /* 0e000000 //C 0f828 ld	r0,r0 */
0x0000f829, 0x06000000, /* 06000000 //C 0f829 st	r0,0 */
0x0000f82a, 0x01020000, /* 01020000 //C 0f82a mvzl	r0,0		; def values of some regs */
0x0000f82b, 0x0600fbc9, /* 0600fbc9 //C 0f82b st	r0,regf		; FALGS= 0 */
0x0000f82c, 0x0102f7ff, /* 0102f7ff //C 0f82c mvzl	r0,0xf7ff	; R13= 0xf7ff */
0x0000f82d, 0x0600fbc6, /* 0600fbc6 //C 0f82d st	r0,reg13 */
0x0000f82e, 0x01f2f82f, /* 01f2f82f //C 0f82e jmp	common_start: */
0x0000f82f, 0x01d2fe18, /* 01d2fe18 //C 0f82f mvzl	sp,stack_end */
0x0000f830, 0x01020001, /* 01020001 //C 0f830 mvzl	r0,1 */
0x0000f831, 0x0600fbb7, /* 0600fbb7 //C 0f831 st	r0,echo */
0x0000f832, 0x01020000, /* 01020000 //C 0f832 mvzl	r0,0 */
0x0000f833, 0x020f0000, /* 020f0000 //C 0f833 setf	r0 */
0x0000f834, 0x011200d9, /* 011200d9 //C 0f834 mvzl	r1,217 */
0x0000f835, 0x0610ff44, /* 0610ff44 //C 0f835 st	r1,UART_CPB */
0x0000f836, 0x01120003, /* 01120003 //C 0f836 mvzl	r1,3 */
0x0000f837, 0x0610ff41, /* 0610ff41 //C 0f837 st	r1,UART_CTRL */
0x0000f838, 0x0102fbca, /* 0102fbca //C 0f838 mvzl	r0,msg_start */
0x0000f839, 0x0400fb1d, /* 0400fb1d //C 0f839 call	printsnl */
0x0000f83a, 0x0400f83c, /* 0400f83c //C 0f83a call	setup_line */
0x0000f83b, 0x01f2f846, /* 01f2f846 //C 0f83b jmp	main */
0x0000f83c, 0x0ded0000, /* 0ded0000 //C 0f83c push	lr */
0x0000f83d, 0x01120000, /* 01120000 //C 0f83d mvzl	r1,0		; lptr= 0 */
0x0000f83e, 0x0610fbb0, /* 0610fbb0 //C 0f83e st	r1,line_ptr */
0x0000f83f, 0x0610fb4c, /* 0610fb4c //C 0f83f st	r1,line		; line[0]= 0 */
0x0000f840, 0x01120001, /* 01120001 //C 0f840 mvzl	r1,1		; at_eol= 1 */
0x0000f841, 0x0610fbb1, /* 0610fbb1 //C 0f841 st	r1,at_eol */
0x0000f842, 0x0102fbd8, /* 0102fbd8 //C 0f842 mvzl	r0,prompt */
0x0000f843, 0x0400fb09, /* 0400fb09 //C 0f843 call	prints */
0x0000f844, 0x0fed0000, /* 0fed0000 //C 0f844 pop	lr */
0x0000f845, 0x00f00e00, /* 00f00e00 //C 0f845 ret */
0x0000f846, 0x0400faf9, /* 0400faf9 //C 0f846 call	check_uart */
0x0000f847, 0x41f2f84d, /* 41f2f84d //C 0f847 C0 jmp	no_input */
0x0000f848, 0x0400fb00, /* 0400fb00 //C 0f848 call	read */
0x0000f849, 0x0400f84e, /* 0400f84e //C 0f849 call	proc_input */
0x0000f84a, 0x41f2f84d, /* 41f2f84d //C 0f84a C0 jmp	no_line */
0x0000f84b, 0x0400f86b, /* 0400f86b //C 0f84b call	proc_line */
0x0000f84c, 0x0400f83c, /* 0400f83c //C 0f84c call	setup_line */
0x0000f84d, 0x01f2f846, /* 01f2f846 //C 0f84d jmp	main */
0x0000f84e, 0x0ded0000, /* 0ded0000 //C 0f84e push	lr */
0x0000f84f, 0x0108000a, /* 0108000a //C 0f84f cmp	r0,LF */
0x0000f850, 0x11f2f864, /* 11f2f864 //C 0f850 EQ jmp	got_eol */
0x0000f851, 0x0108000d, /* 0108000d //C 0f851 cmp	r0,CR */
0x0000f852, 0x11f2f864, /* 11f2f864 //C 0f852 EQ jmp	got_eol */
0x0000f853, 0x01220000, /* 01220000 //C 0f853 mvzl	r2,0		; at_aol= 0 */
0x0000f854, 0x0620fbb1, /* 0620fbb1 //C 0f854 st	r2,at_eol */
0x0000f855, 0x0112fbb0, /* 0112fbb0 //C 0f855 mvzl	r1,line_ptr	; line[line_ptr]= char */
0x0000f856, 0x0e310000, /* 0e310000 //C 0f856 ld	r3,r1 */
0x0000f857, 0x0122fb4c, /* 0122fb4c //C 0f857 mvzl	r2,line */
0x0000f858, 0x08020300, /* 08020300 //C 0f858 st	r0,r2,r3 */
0x0000f859, 0x013a0001, /* 013a0001 //C 0f859 plus	r3,1		; line_ptr++ */
0x0000f85a, 0x0c310000, /* 0c310000 //C 0f85a st	r3,r1 */
0x0000f85b, 0x01420000, /* 01420000 //C 0f85b mvzl	r4,0 */
0x0000f85c, 0x09438200, /* 09438200 //C 0f85c st	r4,r3+,r2	; line[line_ptr]= 0 */
0x0000f85d, 0x08430200, /* 08430200 //C 0f85d st	r4,r3,r2	; double 0 at end, needed by tokenizer */
0x0000f85e, 0x0142fbb7, /* 0142fbb7 //C 0f85e mvzl	r4,echo		; check if echo is turned on */
0x0000f85f, 0x0e440000, /* 0e440000 //C 0f85f ld	r4,r4 */
0x0000f860, 0x024b0000, /* 024b0000 //C 0f860 sz	r4 */
0x0000f861, 0x2400fb02, /* 2400fb02 //C 0f861 NZ call	putchar		; echo */
0x0000f862, 0x020d0000, /* 020d0000 //C 0f862 clc */
0x0000f863, 0x01f2f869, /* 01f2f869 //C 0f863 jmp	proc_input_ret */
0x0000f864, 0x0112fbb1, /* 0112fbb1 //C 0f864 mvzl	r1,at_eol */
0x0000f865, 0x0e110000, /* 0e110000 //C 0f865 ld	r1,r1 */
0x0000f866, 0x021b0000, /* 021b0000 //C 0f866 sz	r1		; Z=0 at eol -> skip, not ready */
0x0000f867, 0x220d0000, /* 220d0000 //C 0f867 Z0 clc */
0x0000f868, 0x120c0000, /* 120c0000 //C 0f868 Z1 sec */
0x0000f869, 0x0fed0000, /* 0fed0000 //C 0f869 pop	lr */
0x0000f86a, 0x00f00e00, /* 00f00e00 //C 0f86a ret */
0x0000f86b, 0x0ded0000, /* 0ded0000 //C 0f86b push	lr */
0x0000f86c, 0x0102000a, /* 0102000a //C 0f86c mvzl	r0,LF */
0x0000f86d, 0x0400fb02, /* 0400fb02 //C 0f86d call	putchar */
0x0000f86e, 0x0400f893, /* 0400f893 //C 0f86e call	tokenize */
0x0000f86f, 0x0400f8b4, /* 0400f8b4 //C 0f86f call	find_cmd */
0x0000f870, 0x41f2f873, /* 41f2f873 //C 0f870 C0 jmp	cmd_not_found */
0x0000f871, 0x05000000, /* 05000000 //C 0f871 call	r0,0 */
0x0000f872, 0x01f2f875, /* 01f2f875 //C 0f872 jmp	proc_line_ret */
0x0000f873, 0x0102f87e, /* 0102f87e //C 0f873 mvzl	r0,snotfound */
0x0000f874, 0x0400fb1d, /* 0400fb1d //C 0f874 call	printsnl */
0x0000f875, 0x01120001, /* 01120001 //C 0f875 mvzl	r1,1		; at_eol= 1 */
0x0000f876, 0x0610fbb1, /* 0610fbb1 //C 0f876 st	r1,at_eol */
0x0000f877, 0x0fed0000, /* 0fed0000 //C 0f877 pop	lr */
0x0000f878, 0x00f00e00, /* 00f00e00 //C 0f878 ret */
0x0000f879, 0x00000047, /* 00000047 //C 0f879 db	71 */
0x0000f87a, 0x0000006f, /* 0000006f //C 0f87a db	111 */
0x0000f87b, 0x00000074, /* 00000074 //C 0f87b db	116 */
0x0000f87c, 0x0000003a, /* 0000003a //C 0f87c db	58 */
0x0000f87d, 0x00000000, /* 00000000 //C 0f87d db */
0x0000f87e, 0x00000055, /* 00000055 //C 0f87e db	85 */
0x0000f87f, 0x0000006e, /* 0000006e //C 0f87f db	110 */
0x0000f880, 0x0000006b, /* 0000006b //C 0f880 db	107 */
0x0000f881, 0x0000006e, /* 0000006e //C 0f881 db	110 */
0x0000f882, 0x0000006f, /* 0000006f //C 0f882 db	111 */
0x0000f883, 0x00000077, /* 00000077 //C 0f883 db	119 */
0x0000f884, 0x0000006e, /* 0000006e //C 0f884 db	110 */
0x0000f885, 0x00000020, /* 00000020 //C 0f885 db	32 */
0x0000f886, 0x00000063, /* 00000063 //C 0f886 db	99 */
0x0000f887, 0x0000006f, /* 0000006f //C 0f887 db	111 */
0x0000f888, 0x0000006d, /* 0000006d //C 0f888 db	109 */
0x0000f889, 0x0000006d, /* 0000006d //C 0f889 db	109 */
0x0000f88a, 0x00000061, /* 00000061 //C 0f88a db	97 */
0x0000f88b, 0x0000006e, /* 0000006e //C 0f88b db	110 */
0x0000f88c, 0x00000064, /* 00000064 //C 0f88c db	100 */
0x0000f88d, 0x00000000, /* 00000000 //C 0f88d db */
0x0000f88e, 0x0ded0000, /* 0ded0000 //C 0f88e push	lr */
0x0000f88f, 0x0112fbda, /* 0112fbda //C 0f88f mvzl	r1,delimiters */
0x0000f890, 0x0400fa5a, /* 0400fa5a //C 0f890 call	strchr */
0x0000f891, 0x0fed0000, /* 0fed0000 //C 0f891 pop	lr */
0x0000f892, 0x00f00e00, /* 00f00e00 //C 0f892 ret */
0x0000f893, 0x0ded0000, /* 0ded0000 //C 0f893 push	lr */
0x0000f894, 0x0142fbb2, /* 0142fbb2 //C 0f894 mvzl	r4,words	; array of result */
0x0000f895, 0x0152fb4c, /* 0152fb4c //C 0f895 mvzl	r5,line		; address of next char */
0x0000f896, 0x01620000, /* 01620000 //C 0f896 mvzl	r6,0		; nuof words found */
0x0000f897, 0x01720000, /* 01720000 //C 0f897 mvzl	r7,0		; bool in_word */
0x0000f898, 0x0e050000, /* 0e050000 //C 0f898 ld	r0,r5		; pick a char */
0x0000f899, 0x020b0000, /* 020b0000 //C 0f899 sz	r0		; check end */
0x0000f89a, 0x11f2f8a4, /* 11f2f8a4 //C 0f89a jz	tok_delimiter	; found end, pretend delim */
0x0000f89b, 0x0400f88e, /* 0400f88e //C 0f89b call	is_delimiter */
0x0000f89c, 0x31f2f8a4, /* 31f2f8a4 //C 0f89c C1 jmp	tok_delimiter */
0x0000f89d, 0x027b0000, /* 027b0000 //C 0f89d sz	r7 */
0x0000f89e, 0x21f2f8a9, /* 21f2f8a9 //C 0f89e jnz	tok_next	; still inside word */
0x0000f89f, 0x01720001, /* 01720001 //C 0f89f mvzl	r7,1		; in_word=true */
0x0000f8a0, 0x09568400, /* 09568400 //C 0f8a0 st	r5,r6+,r4	; record word address */
0x0000f8a1, 0x01680005, /* 01680005 //C 0f8a1 cmp	r6,MAX_WORDS	; If no more space */
0x0000f8a2, 0x11f2f8ad, /* 11f2f8ad //C 0f8a2 EQ jmp	tok_ret		; then return */
0x0000f8a3, 0x01f2f8a9, /* 01f2f8a9 //C 0f8a3 jmp	tok_next */
0x0000f8a4, 0x027b0000, /* 027b0000 //C 0f8a4 sz	r7 */
0x0000f8a5, 0x11f2f8a9, /* 11f2f8a9 //C 0f8a5 jz	tok_next	; still between words */
0x0000f8a6, 0x01720000, /* 01720000 //C 0f8a6 mvzl	r7,0		; in_word=false */
0x0000f8a7, 0x01120000, /* 01120000 //C 0f8a7 mvzl	r1,0		; put a 0 at the end of word */
0x0000f8a8, 0x08150100, /* 08150100 //C 0f8a8 st	r1,r5,r1 */
0x0000f8a9, 0x020b0000, /* 020b0000 //C 0f8a9 sz	r0		; check EOL */
0x0000f8aa, 0x11f2f8ad, /* 11f2f8ad //C 0f8aa jz	tok_ret		; jump out if char==0 */
0x0000f8ab, 0x01540001, /* 01540001 //C 0f8ab add	r5,1 */
0x0000f8ac, 0x01f2f898, /* 01f2f898 //C 0f8ac jmp	tok_cycle */
0x0000f8ad, 0x01120000, /* 01120000 //C 0f8ad mvzl	r1,0 */
0x0000f8ae, 0x01680005, /* 01680005 //C 0f8ae cmp	r6,MAX_WORDS */
0x0000f8af, 0x11f2f8b2, /* 11f2f8b2 //C 0f8af jz	tok_end */
0x0000f8b0, 0x09168400, /* 09168400 //C 0f8b0 st	r1,r6+,r4 */
0x0000f8b1, 0x01f2f8ad, /* 01f2f8ad //C 0f8b1 jmp	tok_ret */
0x0000f8b2, 0x0fed0000, /* 0fed0000 //C 0f8b2 pop	lr */
0x0000f8b3, 0x00f00e00, /* 00f00e00 //C 0f8b3 ret */
0x0000f8b4, 0x0ded0000, /* 0ded0000 //C 0f8b4 push	lr */
0x0000f8b5, 0x0d1d0000, /* 0d1d0000 //C 0f8b5 push	r1 */
0x0000f8b6, 0x0d2d0000, /* 0d2d0000 //C 0f8b6 push	r2 */
0x0000f8b7, 0x0d3d0000, /* 0d3d0000 //C 0f8b7 push	r3 */
0x0000f8b8, 0x0dad0000, /* 0dad0000 //C 0f8b8 push	r10 */
0x0000f8b9, 0x0700fbb2, /* 0700fbb2 //C 0f8b9 ld	r0,words	; R0= 1st word of command */
0x0000f8ba, 0x020b0000, /* 020b0000 //C 0f8ba sz	r0 */
0x0000f8bb, 0x11f2f8d0, /* 11f2f8d0 //C 0f8bb jz	find_cmd_false */
0x0000f8bc, 0x01a2fbea, /* 01a2fbea //C 0f8bc mvzl	r10,commands */
0x0000f8bd, 0x0e2a0000, /* 0e2a0000 //C 0f8bd ld	r2,r10		; R2= cmd addr */
0x0000f8be, 0x022b0000, /* 022b0000 //C 0f8be sz	r2 */
0x0000f8bf, 0x11f2f8d0, /* 11f2f8d0 //C 0f8bf jz	find_cmd_false */
0x0000f8c0, 0x01a40001, /* 01a40001 //C 0f8c0 add	r10,1 */
0x0000f8c1, 0x00100a00, /* 00100a00 //C 0f8c1 mov	r1,r10		; R1= cmd string */
0x0000f8c2, 0x01a40001, /* 01a40001 //C 0f8c2 add	r10,1 */
0x0000f8c3, 0x0e3a0000, /* 0e3a0000 //C 0f8c3 ld	r3,r10 */
0x0000f8c4, 0x023b0000, /* 023b0000 //C 0f8c4 sz	r3 */
0x0000f8c5, 0x21f2f8c2, /* 21f2f8c2 //C 0f8c5 jnz	find_cmd_fw */
0x0000f8c6, 0x01a40001, /* 01a40001 //C 0f8c6 add	r10,1 */
0x0000f8c7, 0x0400fa95, /* 0400fa95 //C 0f8c7 call	streq */
0x0000f8c8, 0x41f2f8bd, /* 41f2f8bd //C 0f8c8 C0 jmp	find_cmd_cyc */
0x0000f8c9, 0x00000200, /* 00000200 //C 0f8c9 mov	r0,r2 */
0x0000f8ca, 0x020c0000, /* 020c0000 //C 0f8ca sec */
0x0000f8cb, 0x01f2f8db, /* 01f2f8db //C 0f8cb jmp	find_cmd_ret */
0x0000f8cc, 0x0000002f, /* 0000002f //C 0f8cc db	47 */
0x0000f8cd, 0x0000002f, /* 0000002f //C 0f8cd db	47 */
0x0000f8ce, 0x00000043, /* 00000043 //C 0f8ce db	67 */
0x0000f8cf, 0x00000000, /* 00000000 //C 0f8cf db */
0x0000f8d0, 0x01040001, /* 01040001 //C 0f8d0 add	r0,1		; check second word */
0x0000f8d1, 0x0e100000, /* 0e100000 //C 0f8d1 ld	r1,r0		; for //C command */
0x0000f8d2, 0x021b0000, /* 021b0000 //C 0f8d2 sz	r1 */
0x0000f8d3, 0x11f2f8d9, /* 11f2f8d9 //C 0f8d3 jz	find_cmd_very_false */
0x0000f8d4, 0x0102f8cc, /* 0102f8cc //C 0f8d4 mvzl	r0,c_cmd_name */
0x0000f8d5, 0x0400fa95, /* 0400fa95 //C 0f8d5 call	streq */
0x0000f8d6, 0x21f2f8d9, /* 21f2f8d9 //C 0f8d6 jnz	find_cmd_very_false */
0x0000f8d7, 0x0122f96a, /* 0122f96a //C 0f8d7 mvzl	r2,cmd_c */
0x0000f8d8, 0x01f2f8c9, /* 01f2f8c9 //C 0f8d8 jmp	find_cmd_true */
0x0000f8d9, 0x020d0000, /* 020d0000 //C 0f8d9 clc */
0x0000f8da, 0x01020000, /* 01020000 //C 0f8da mvzl	r0,0 */
0x0000f8db, 0x0fad0000, /* 0fad0000 //C 0f8db pop	r10 */
0x0000f8dc, 0x0f3d0000, /* 0f3d0000 //C 0f8dc pop	r3 */
0x0000f8dd, 0x0f2d0000, /* 0f2d0000 //C 0f8dd pop	r2 */
0x0000f8de, 0x0f1d0000, /* 0f1d0000 //C 0f8de pop	r1 */
0x0000f8df, 0x0fed0000, /* 0fed0000 //C 0f8df pop	lr */
0x0000f8e0, 0x00f00e00, /* 00f00e00 //C 0f8e0 ret */
0x0000f8e1, 0x0ded0000, /* 0ded0000 //C 0f8e1 push	lr */
0x0000f8e2, 0x0122fbb2, /* 0122fbb2 //C 0f8e2 mvzl	r2,words */
0x0000f8e3, 0x01020000, /* 01020000 //C 0f8e3 mvzl	r0,0 */
0x0000f8e4, 0x0e420001, /* 0e420001 //C 0f8e4 ld	r4,r2,1		; addr */
0x0000f8e5, 0x0e520002, /* 0e520002 //C 0f8e5 ld	r5,r2,2		; value */
0x0000f8e6, 0x024b0000, /* 024b0000 //C 0f8e6 sz 	r4 */
0x0000f8e7, 0x11f2f908, /* 11f2f908 //C 0f8e7 jz	m_ret */
0x0000f8e8, 0x00000400, /* 00000400 //C 0f8e8 mov	r0,r4 */
0x0000f8e9, 0x0400fad7, /* 0400fad7 //C 0f8e9 call	htoi */
0x0000f8ea, 0x00400100, /* 00400100 //C 0f8ea mov	r4,r1 */
0x0000f8eb, 0x31f2f8ef, /* 31f2f8ef //C 0f8eb C1 jmp	m_addr_ok */
0x0000f8ec, 0x0102f90a, /* 0102f90a //C 0f8ec mvzl	r0,m_err_addr */
0x0000f8ed, 0x0400fb1d, /* 0400fb1d //C 0f8ed call	printsnl */
0x0000f8ee, 0x01f2f908, /* 01f2f908 //C 0f8ee jmp	m_ret */
0x0000f8ef, 0x025b0000, /* 025b0000 //C 0f8ef sz	r5 */
0x0000f8f0, 0x11f2f8fe, /* 11f2f8fe //C 0f8f0 jz	m_read */
0x0000f8f1, 0x0148fe27, /* 0148fe27 //C 0f8f1 cmp	r4,the_end */
0x0000f8f2, 0x91f2f8f6, /* 91f2f8f6 //C 0f8f2 HI jmp	m_addrv_ok */
0x0000f8f3, 0x0102f918, /* 0102f918 //C 0f8f3 mvzl	r0,m_err_addrv */
0x0000f8f4, 0x0400fb1d, /* 0400fb1d //C 0f8f4 call	printsnl */
0x0000f8f5, 0x01f2f908, /* 01f2f908 //C 0f8f5 jmp	m_ret */
0x0000f8f6, 0x00000500, /* 00000500 //C 0f8f6 mov	r0,r5 */
0x0000f8f7, 0x0400fad7, /* 0400fad7 //C 0f8f7 call	htoi */
0x0000f8f8, 0x00500100, /* 00500100 //C 0f8f8 mov	r5,r1 */
0x0000f8f9, 0x31f2f8fd, /* 31f2f8fd //C 0f8f9 C1 jmp	m_value_ok */
0x0000f8fa, 0x0102f92a, /* 0102f92a //C 0f8fa mvzl	r0,m_err_value */
0x0000f8fb, 0x0400fb1d, /* 0400fb1d //C 0f8fb call	printsnl */
0x0000f8fc, 0x01f2f908, /* 01f2f908 //C 0f8fc jmp	m_ret */
0x0000f8fd, 0x0c540000, /* 0c540000 //C 0f8fd st	r5,r4 */
0x0000f8fe, 0x00000400, /* 00000400 //C 0f8fe mov	r0,r4 */
0x0000f8ff, 0x01120004, /* 01120004 //C 0f8ff mvzl	r1,4 */
0x0000f900, 0x0400fb25, /* 0400fb25 //C 0f900 call	print_vhex */
0x0000f901, 0x01020020, /* 01020020 //C 0f901 mvzl	r0,0x20 */
0x0000f902, 0x0400fb02, /* 0400fb02 //C 0f902 call	putchar */
0x0000f903, 0x0e040000, /* 0e040000 //C 0f903 ld	r0,r4 */
0x0000f904, 0x01120004, /* 01120004 //C 0f904 mvzl	r1,4 */
0x0000f905, 0x0400fb25, /* 0400fb25 //C 0f905 call	print_vhex */
0x0000f906, 0x0102000a, /* 0102000a //C 0f906 mvzl	r0,LF */
0x0000f907, 0x0400fb02, /* 0400fb02 //C 0f907 call	putchar */
0x0000f908, 0x0fed0000, /* 0fed0000 //C 0f908 pop	lr */
0x0000f909, 0x00f00e00, /* 00f00e00 //C 0f909 ret */
0x0000f90a, 0x00000041, /* 00000041 //C 0f90a db	65 */
0x0000f90b, 0x00000064, /* 00000064 //C 0f90b db	100 */
0x0000f90c, 0x00000064, /* 00000064 //C 0f90c db	100 */
0x0000f90d, 0x00000072, /* 00000072 //C 0f90d db	114 */
0x0000f90e, 0x00000065, /* 00000065 //C 0f90e db	101 */
0x0000f90f, 0x00000073, /* 00000073 //C 0f90f db	115 */
0x0000f910, 0x00000073, /* 00000073 //C 0f910 db	115 */
0x0000f911, 0x00000020, /* 00000020 //C 0f911 db	32 */
0x0000f912, 0x00000065, /* 00000065 //C 0f912 db	101 */
0x0000f913, 0x00000072, /* 00000072 //C 0f913 db	114 */
0x0000f914, 0x00000072, /* 00000072 //C 0f914 db	114 */
0x0000f915, 0x0000006f, /* 0000006f //C 0f915 db	111 */
0x0000f916, 0x00000072, /* 00000072 //C 0f916 db	114 */
0x0000f917, 0x00000000, /* 00000000 //C 0f917 db */
0x0000f918, 0x0000004d, /* 0000004d //C 0f918 db	77 */
0x0000f919, 0x0000006f, /* 0000006f //C 0f919 db	111 */
0x0000f91a, 0x0000006e, /* 0000006e //C 0f91a db	110 */
0x0000f91b, 0x00000069, /* 00000069 //C 0f91b db	105 */
0x0000f91c, 0x00000074, /* 00000074 //C 0f91c db	116 */
0x0000f91d, 0x0000006f, /* 0000006f //C 0f91d db	111 */
0x0000f91e, 0x00000072, /* 00000072 //C 0f91e db	114 */
0x0000f91f, 0x00000027, /* 00000027 //C 0f91f db	39 */
0x0000f920, 0x00000073, /* 00000073 //C 0f920 db	115 */
0x0000f921, 0x00000020, /* 00000020 //C 0f921 db	32 */
0x0000f922, 0x00000061, /* 00000061 //C 0f922 db	97 */
0x0000f923, 0x00000064, /* 00000064 //C 0f923 db	100 */
0x0000f924, 0x00000064, /* 00000064 //C 0f924 db	100 */
0x0000f925, 0x00000072, /* 00000072 //C 0f925 db	114 */
0x0000f926, 0x00000065, /* 00000065 //C 0f926 db	101 */
0x0000f927, 0x00000073, /* 00000073 //C 0f927 db	115 */
0x0000f928, 0x00000073, /* 00000073 //C 0f928 db	115 */
0x0000f929, 0x00000000, /* 00000000 //C 0f929 db */
0x0000f92a, 0x00000056, /* 00000056 //C 0f92a db	86 */
0x0000f92b, 0x00000061, /* 00000061 //C 0f92b db	97 */
0x0000f92c, 0x0000006c, /* 0000006c //C 0f92c db	108 */
0x0000f92d, 0x00000075, /* 00000075 //C 0f92d db	117 */
0x0000f92e, 0x00000065, /* 00000065 //C 0f92e db	101 */
0x0000f92f, 0x00000020, /* 00000020 //C 0f92f db	32 */
0x0000f930, 0x00000065, /* 00000065 //C 0f930 db	101 */
0x0000f931, 0x00000072, /* 00000072 //C 0f931 db	114 */
0x0000f932, 0x00000072, /* 00000072 //C 0f932 db	114 */
0x0000f933, 0x0000006f, /* 0000006f //C 0f933 db	111 */
0x0000f934, 0x00000072, /* 00000072 //C 0f934 db	114 */
0x0000f935, 0x00000000, /* 00000000 //C 0f935 db */
0x0000f936, 0x0ded0000, /* 0ded0000 //C 0f936 push	lr */
0x0000f937, 0x0122fbb2, /* 0122fbb2 //C 0f937 mvzl	r2,words */
0x0000f938, 0x0e020001, /* 0e020001 //C 0f938 ld	r0,r2,1		; start address */
0x0000f939, 0x0400fad7, /* 0400fad7 //C 0f939 call	htoi */
0x0000f93a, 0x00300100, /* 00300100 //C 0f93a mov	r3,r1 */
0x0000f93b, 0x0e020002, /* 0e020002 //C 0f93b ld	r0,r2,2		; end address */
0x0000f93c, 0x020b0000, /* 020b0000 //C 0f93c sz	r0 */
0x0000f93d, 0x21f2f941, /* 21f2f941 //C 0f93d jnz	d_end_ok */
0x0000f93e, 0x00400300, /* 00400300 //C 0f93e mov	r4,r3 */
0x0000f93f, 0x01440010, /* 01440010 //C 0f93f add	r4,0x10 */
0x0000f940, 0x01f2f943, /* 01f2f943 //C 0f940 jmp	d_chk_end */
0x0000f941, 0x0400fad7, /* 0400fad7 //C 0f941 call	htoi */
0x0000f942, 0x00400100, /* 00400100 //C 0f942 mov	r4,r1 */
0x0000f943, 0x00380400, /* 00380400 //C 0f943 cmp	r3,r4		; check if start>end */
0x0000f944, 0x91f2f953, /* 91f2f953 //C 0f944 HI jmp d_bad */
0x0000f945, 0x00000300, /* 00000300 //C 0f945 mov	r0,r3		; print address */
0x0000f946, 0x01120004, /* 01120004 //C 0f946 mvzl	r1,4 */
0x0000f947, 0x0400fb25, /* 0400fb25 //C 0f947 call	print_vhex */
0x0000f948, 0x01020020, /* 01020020 //C 0f948 mvzl	r0,0x20		; print one space */
0x0000f949, 0x0400fb02, /* 0400fb02 //C 0f949 call	putchar */
0x0000f94a, 0x0e030000, /* 0e030000 //C 0f94a ld	r0,r3		; load data */
0x0000f94b, 0x01120004, /* 01120004 //C 0f94b mvzl	r1,4		; print data */
0x0000f94c, 0x0400fb25, /* 0400fb25 //C 0f94c call	print_vhex */
0x0000f94d, 0x0102000a, /* 0102000a //C 0f94d mvzl	r0,LF		; print new line */
0x0000f94e, 0x0400fb02, /* 0400fb02 //C 0f94e call	putchar */
0x0000f94f, 0x00380400, /* 00380400 //C 0f94f cmp	r3,r4 */
0x0000f950, 0x11f2f955, /* 11f2f955 //C 0f950 jz	d_ret */
0x0000f951, 0x01340001, /* 01340001 //C 0f951 add	r3,1 */
0x0000f952, 0x01f2f945, /* 01f2f945 //C 0f952 jmp	d_cyc */
0x0000f953, 0x0102f957, /* 0102f957 //C 0f953 mvzl	r0,d_err_bad */
0x0000f954, 0x0400fb1d, /* 0400fb1d //C 0f954 call	printsnl */
0x0000f955, 0x0fed0000, /* 0fed0000 //C 0f955 pop	lr */
0x0000f956, 0x00f00e00, /* 00f00e00 //C 0f956 ret */
0x0000f957, 0x00000057, /* 00000057 //C 0f957 db	87 */
0x0000f958, 0x00000072, /* 00000072 //C 0f958 db	114 */
0x0000f959, 0x0000006f, /* 0000006f //C 0f959 db	111 */
0x0000f95a, 0x0000006e, /* 0000006e //C 0f95a db	110 */
0x0000f95b, 0x00000067, /* 00000067 //C 0f95b db	103 */
0x0000f95c, 0x00000020, /* 00000020 //C 0f95c db	32 */
0x0000f95d, 0x00000065, /* 00000065 //C 0f95d db	101 */
0x0000f95e, 0x0000006e, /* 0000006e //C 0f95e db	110 */
0x0000f95f, 0x00000064, /* 00000064 //C 0f95f db	100 */
0x0000f960, 0x00000020, /* 00000020 //C 0f960 db	32 */
0x0000f961, 0x00000061, /* 00000061 //C 0f961 db	97 */
0x0000f962, 0x00000064, /* 00000064 //C 0f962 db	100 */
0x0000f963, 0x00000064, /* 00000064 //C 0f963 db	100 */
0x0000f964, 0x00000072, /* 00000072 //C 0f964 db	114 */
0x0000f965, 0x00000065, /* 00000065 //C 0f965 db	101 */
0x0000f966, 0x00000073, /* 00000073 //C 0f966 db	115 */
0x0000f967, 0x00000073, /* 00000073 //C 0f967 db	115 */
0x0000f968, 0x00000000, /* 00000000 //C 0f968 db */
0x0000f969, 0x00f00e00, /* 00f00e00 //C 0f969 ret */
0x0000f96a, 0x00f00e00, /* 00f00e00 //C 0f96a ret */
0x0000f96b, 0x0ded0000, /* 0ded0000 //C 0f96b push	lr */
0x0000f96c, 0x01a20000, /* 01a20000 //C 0f96c mvzl	r10,0		; state (nr of words) */
0x0000f96d, 0x01820000, /* 01820000 //C 0f96d mvzl	r8,0		; value */
0x0000f96e, 0x0162003f, /* 0162003f //C 0f96e mvzl	r6,'?'		; Record type */
0x0000f96f, 0x0400faf9, /* 0400faf9 //C 0f96f call	check_uart */
0x0000f970, 0x41f2f96f, /* 41f2f96f //C 0f970 C0 jmp	l_cyc */
0x0000f971, 0x0400fb00, /* 0400fb00 //C 0f971 call	read */
0x0000f972, 0x00b00000, /* 00b00000 //C 0f972 mov	r11,r0		; Copy of char in R11 */
0x0000f973, 0x0108000a, /* 0108000a //C 0f973 cmp	r0,10		; check EOL chars */
0x0000f974, 0x11f2f9be, /* 11f2f9be //C 0f974 jz	l_eol */
0x0000f975, 0x0108000d, /* 0108000d //C 0f975 cmp	r0,13 */
0x0000f976, 0x11f2f9be, /* 11f2f9be //C 0f976 jz	l_eol */
0x0000f977, 0x01a80000, /* 01a80000 //C 0f977 cmp	r10,0 */
0x0000f978, 0x21f2f988, /* 21f2f988 //C 0f978 jnz	l_no0 */
0x0000f979, 0x0400faa3, /* 0400faa3 //C 0f979 call	hexchar2value */
0x0000f97a, 0x41f2f982, /* 41f2f982 //C 0f97a C0 jmp	l_eof_0 */
0x0000f97b, 0x02880000, /* 02880000 //C 0f97b shl	r8		; shift val(char) into value */
0x0000f97c, 0x02880000, /* 02880000 //C 0f97c shl	r8 */
0x0000f97d, 0x02880000, /* 02880000 //C 0f97d shl	r8 */
0x0000f97e, 0x02880000, /* 02880000 //C 0f97e shl	r8 */
0x0000f97f, 0x010b000f, /* 010b000f //C 0f97f btst	r0,0xf */
0x0000f980, 0x008d0000, /* 008d0000 //C 0f980 or	r8,r0 */
0x0000f981, 0x01f2f96f, /* 01f2f96f //C 0f981 jmp	l_cyc */
0x0000f982, 0x01a20001, /* 01a20001 //C 0f982 mvzl	r10,1		; state0 -> state1 */
0x0000f983, 0x0162003f, /* 0162003f //C 0f983 mvzl	r6,'?'		; No //C yet */
0x0000f984, 0x01b8002f, /* 01b8002f //C 0f984 cmp	r11,'/'		; is it start of // */
0x0000f985, 0x11720001, /* 11720001 //C 0f985 z1 mvzl	r7,1		; Yes, first / found */
0x0000f986, 0x21720000, /* 21720000 //C 0f986 z0 mvzl	r7,0		; No '/' yet */
0x0000f987, 0x01f2f96f, /* 01f2f96f //C 0f987 jmp	l_cyc */
0x0000f988, 0x01a80001, /* 01a80001 //C 0f988 cmp	r10,1 */
0x0000f989, 0x21f2f9a1, /* 21f2f9a1 //C 0f989 jnz	l_no1 */
0x0000f98a, 0x027b0000, /* 027b0000 //C 0f98a sz	r7 */
0x0000f98b, 0x21f2f990, /* 21f2f990 //C 0f98b jnz	l_s1_2nd */
0x0000f98c, 0x0108002f, /* 0108002f //C 0f98c cmp	r0,'/' */
0x0000f98d, 0x21f2f96f, /* 21f2f96f //C 0f98d jnz	l_cyc */
0x0000f98e, 0x01720001, /* 01720001 //C 0f98e mvzl	r7,1 */
0x0000f98f, 0x01f2f96f, /* 01f2f96f //C 0f98f jmp	l_cyc */
0x0000f990, 0x0108002f, /* 0108002f //C 0f990 cmp	r0,'/' */
0x0000f991, 0x11f2f96f, /* 11f2f96f //C 0f991 jz	l_cyc */
0x0000f992, 0x01080043, /* 01080043 //C 0f992 cmp	r0,'C' */
0x0000f993, 0x21f2f999, /* 21f2f999 //C 0f993 jnz	l_s1_noC */
0x0000f994, 0x01620043, /* 01620043 //C 0f994 mvzl	r6,'C' */
0x0000f995, 0x01a20002, /* 01a20002 //C 0f995 mvzl	r10,2 */
0x0000f996, 0x01920000, /* 01920000 //C 0f996 mvzl	r9,0		; address= 0 */
0x0000f997, 0x01520000, /* 01520000 //C 0f997 mvzl	r5,0		; where we are in word: before */
0x0000f998, 0x01f2f96f, /* 01f2f96f //C 0f998 jmp	l_cyc */
0x0000f999, 0x01080045, /* 01080045 //C 0f999 cmp	r0,'E' */
0x0000f99a, 0x21f2f99e, /* 21f2f99e //C 0f99a jnz	l_s1_noE */
0x0000f99b, 0x01620045, /* 01620045 //C 0f99b mvzl	r6,'E' */
0x0000f99c, 0x01a20003, /* 01a20003 //C 0f99c mvzl	r10,3 */
0x0000f99d, 0x01f2f96f, /* 01f2f96f //C 0f99d jmp	l_cyc */
0x0000f99e, 0x0400fb02, /* 0400fb02 //C 0f99e call	putchar		; print record type */
0x0000f99f, 0x01a2000f, /* 01a2000f //C 0f99f mvzl	r10,0xf		; special state: skip everything */
0x0000f9a0, 0x01f2f96f, /* 01f2f96f //C 0f9a0 jmp	l_cyc */
0x0000f9a1, 0x01a80002, /* 01a80002 //C 0f9a1 cmp	r10,2 */
0x0000f9a2, 0x21f2f9b6, /* 21f2f9b6 //C 0f9a2 jnz	l_no2 */
0x0000f9a3, 0x01580000, /* 01580000 //C 0f9a3 cmp	r5,0 */
0x0000f9a4, 0x21f2f9af, /* 21f2f9af //C 0f9a4 jnz	l_s2_no0 */
0x0000f9a5, 0x0400faa3, /* 0400faa3 //C 0f9a5 call	hexchar2value */
0x0000f9a6, 0x41f2f96f, /* 41f2f96f //C 0f9a6 C0 jmp	l_cyc */
0x0000f9a7, 0x01520001, /* 01520001 //C 0f9a7 mvzl	r5,1 */
0x0000f9a8, 0x02980000, /* 02980000 //C 0f9a8 shl	r9 */
0x0000f9a9, 0x02980000, /* 02980000 //C 0f9a9 shl	r9 */
0x0000f9aa, 0x02980000, /* 02980000 //C 0f9aa shl	r9 */
0x0000f9ab, 0x02980000, /* 02980000 //C 0f9ab shl	r9 */
0x0000f9ac, 0x010b000f, /* 010b000f //C 0f9ac btst	r0,0xf */
0x0000f9ad, 0x009d0000, /* 009d0000 //C 0f9ad or	r9,r0 */
0x0000f9ae, 0x01f2f96f, /* 01f2f96f //C 0f9ae jmp	l_cyc */
0x0000f9af, 0x01580001, /* 01580001 //C 0f9af cmp	r5,1 */
0x0000f9b0, 0x21f2f9b5, /* 21f2f9b5 //C 0f9b0 jnz	l_s2_no1 */
0x0000f9b1, 0x0400faa3, /* 0400faa3 //C 0f9b1 call	hexchar2value */
0x0000f9b2, 0x31f2f9a8, /* 31f2f9a8 //C 0f9b2 C1 jmp	l_s2_got */
0x0000f9b3, 0x01520002, /* 01520002 //C 0f9b3 mvzl	r5,2 */
0x0000f9b4, 0x01f2f96f, /* 01f2f96f //C 0f9b4 jmp	l_cyc */
0x0000f9b5, 0x01f2f96f, /* 01f2f96f //C 0f9b5 jmp	l_cyc */
0x0000f9b6, 0x01a80003, /* 01a80003 //C 0f9b6 cmp	r10,3 */
0x0000f9b7, 0x21f2f9b9, /* 21f2f9b9 //C 0f9b7 jnz	l_no3 */
0x0000f9b8, 0x01f2f96f, /* 01f2f96f //C 0f9b8 jmp	l_cyc		; do nothing, just wait EOL */
0x0000f9b9, 0x01a8000f, /* 01a8000f //C 0f9b9 cmp	r10,0xf */
0x0000f9ba, 0x01f2f9bc, /* 01f2f9bc //C 0f9ba jmp	l_nof */
0x0000f9bb, 0x01f2f96f, /* 01f2f96f //C 0f9bb jmp	l_cyc		; just skip */
0x0000f9bc, 0x01f2f96f, /* 01f2f96f //C 0f9bc jmp	l_cyc */
0x0000f9bd, 0x01f2f9d4, /* 01f2f9d4 //C 0f9bd jmp	l_ret */
0x0000f9be, 0x01a80000, /* 01a80000 //C 0f9be cmp	r10,0		; in state0 */
0x0000f9bf, 0x11f2f9ce, /* 11f2f9ce //C 0f9bf jz	l_back_to_0	; just restart */
0x0000f9c0, 0x01a80001, /* 01a80001 //C 0f9c0 cmp	r10,1		; in state1 */
0x0000f9c1, 0x11f2f9ce, /* 11f2f9ce //C 0f9c1 jz	l_back_to_0 	;l_cyc ;l_bad ; garbage */
0x0000f9c2, 0x01a80002, /* 01a80002 //C 0f9c2 cmp	r10,2		; in state2 */
0x0000f9c3, 0x11f2f9ca, /* 11f2f9ca //C 0f9c3 jz	l_proc		; process record */
0x0000f9c4, 0x01a80003, /* 01a80003 //C 0f9c4 cmp	r10,3		; in state3 */
0x0000f9c5, 0x11f2f9d4, /* 11f2f9d4 //C 0f9c5 jz	l_ret		; eol in end record: finish */
0x0000f9c6, 0x01a8000f, /* 01a8000f //C 0f9c6 cmp	r10,0xf		; in state skip */
0x0000f9c7, 0x11f2f9ce, /* 11f2f9ce //C 0f9c7 jz	l_back_to_0	; reset state for new line */
0x0000f9c8, 0x01f2f96f, /* 01f2f96f //C 0f9c8 jmp	l_cyc */
0x0000f9c9, 0x01f2f9d4, /* 01f2f9d4 //C 0f9c9 jmp	l_ret */
0x0000f9ca, 0x01680043, /* 01680043 //C 0f9ca cmp	r6,'C'		; is it a C record? */
0x0000f9cb, 0x1c890000, /* 1c890000 //C 0f9cb z st	r8,r9		; store */
0x0000f9cc, 0x00000600, /* 00000600 //C 0f9cc mov	r0,r6		; echo record type */
0x0000f9cd, 0x0400fb02, /* 0400fb02 //C 0f9cd call	putchar */
0x0000f9ce, 0x0102002e, /* 0102002e //C 0f9ce mvzl	r0,'.' */
0x0000f9cf, 0x0400fb02, /* 0400fb02 //C 0f9cf call	putchar */
0x0000f9d0, 0x01a20000, /* 01a20000 //C 0f9d0 mvzl	r10,0 */
0x0000f9d1, 0x01820000, /* 01820000 //C 0f9d1 mvzl	r8,0 */
0x0000f9d2, 0x0162003f, /* 0162003f //C 0f9d2 mvzl	r6,'?' */
0x0000f9d3, 0x01f2f96f, /* 01f2f96f //C 0f9d3 jmp	l_cyc */
0x0000f9d4, 0x0102000a, /* 0102000a //C 0f9d4 mvzl	r0,LF */
0x0000f9d5, 0x0400fb02, /* 0400fb02 //C 0f9d5 call	putchar */
0x0000f9d6, 0x0fed0000, /* 0fed0000 //C 0f9d6 pop	lr */
0x0000f9d7, 0x00f00e00, /* 00f00e00 //C 0f9d7 ret */
0x0000f9d8, 0x0ded0000, /* 0ded0000 //C 0f9d8 push	lr */
0x0000f9d9, 0x0122fbb2, /* 0122fbb2 //C 0f9d9 mvzl	r2,words */
0x0000f9da, 0x0e020001, /* 0e020001 //C 0f9da ld	r0,r2,1		; address */
0x0000f9db, 0x020b0000, /* 020b0000 //C 0f9db sz	r0 */
0x0000f9dc, 0x11f2f9ff, /* 11f2f9ff //C 0f9dc jz	g_no_addr */
0x0000f9dd, 0x0400fad7, /* 0400fad7 //C 0f9dd call	htoi */
0x0000f9de, 0x00b00100, /* 00b00100 //C 0f9de mov	r11,r1 */
0x0000f9df, 0x0102fa0e, /* 0102fa0e //C 0f9df mvzl	r0,d_msg_run */
0x0000f9e0, 0x0400fb09, /* 0400fb09 //C 0f9e0 call	prints */
0x0000f9e1, 0x00000b00, /* 00000b00 //C 0f9e1 mov	r0,r11 */
0x0000f9e2, 0x01120004, /* 01120004 //C 0f9e2 mvzl	r1,4 */
0x0000f9e3, 0x0400fb25, /* 0400fb25 //C 0f9e3 call	print_vhex */
0x0000f9e4, 0x0102000a, /* 0102000a //C 0f9e4 mvzl	r0,LF */
0x0000f9e5, 0x0400fb02, /* 0400fb02 //C 0f9e5 call	putchar */
0x0000f9e6, 0x06b0fbc8, /* 06b0fbc8 //C 0f9e6 st	r11,reg15 */
0x0000f9e7, 0x0122ff43, /* 0122ff43 //C 0f9e7 mvzl	r2,UART_TSTAT */
0x0000f9e8, 0x0e920000, /* 0e920000 //C 0f9e8 ld	r9,r2 */
0x0000f9e9, 0x019c0001, /* 019c0001 //C 0f9e9 test	r9,1 */
0x0000f9ea, 0x11f2f9e8, /* 11f2f9e8 //C 0f9ea jz	g_wait_tc */
0x0000f9eb, 0x07000000, /* 07000000 //C 0f9eb ld	r0,0 */
0x0000f9ec, 0x0600fbb8, /* 0600fbb8 //C 0f9ec st	r0,called */
0x0000f9ed, 0x0700fbc9, /* 0700fbc9 //C 0f9ed ld	r0,regf */
0x0000f9ee, 0x020f0000, /* 020f0000 //C 0f9ee setf	r0 */
0x0000f9ef, 0x0700fbb9, /* 0700fbb9 //C 0f9ef ld	r0,reg0 */
0x0000f9f0, 0x0710fbba, /* 0710fbba //C 0f9f0 ld	r1,reg1 */
0x0000f9f1, 0x0720fbbb, /* 0720fbbb //C 0f9f1 ld	r2,reg2 */
0x0000f9f2, 0x0730fbbc, /* 0730fbbc //C 0f9f2 ld	r3,reg3 */
0x0000f9f3, 0x0740fbbd, /* 0740fbbd //C 0f9f3 ld	r4,reg4 */
0x0000f9f4, 0x0750fbbe, /* 0750fbbe //C 0f9f4 ld	r5,reg5 */
0x0000f9f5, 0x0760fbbf, /* 0760fbbf //C 0f9f5 ld	r6,reg6 */
0x0000f9f6, 0x0770fbc0, /* 0770fbc0 //C 0f9f6 ld	r7,reg7 */
0x0000f9f7, 0x0780fbc1, /* 0780fbc1 //C 0f9f7 ld	r8,reg8 */
0x0000f9f8, 0x0790fbc2, /* 0790fbc2 //C 0f9f8 ld	r9,reg9 */
0x0000f9f9, 0x07a0fbc3, /* 07a0fbc3 //C 0f9f9 ld	r10,reg10 */
0x0000f9fa, 0x07b0fbc4, /* 07b0fbc4 //C 0f9fa ld	r11,reg11 */
0x0000f9fb, 0x07c0fbc5, /* 07c0fbc5 //C 0f9fb ld	r12,reg12 */
0x0000f9fc, 0x07d0fbc6, /* 07d0fbc6 //C 0f9fc ld	r13,reg13 */
0x0000f9fd, 0x07e0fbc7, /* 07e0fbc7 //C 0f9fd ld	r14,reg14 */
0x0000f9fe, 0x07f0fbc8, /* 07f0fbc8 //C 0f9fe ld	r15,reg15 */
0x0000f9ff, 0x0102fa03, /* 0102fa03 //C 0f9ff mvzl	r0,g_err_addr */
0x0000fa00, 0x0400fb1d, /* 0400fb1d //C 0fa00 call	printsnl */
0x0000fa01, 0x0fed0000, /* 0fed0000 //C 0fa01 pop	lr */
0x0000fa02, 0x00f00e00, /* 00f00e00 //C 0fa02 ret */
0x0000fa03, 0x0000004e, /* 0000004e //C 0fa03 db	78 */
0x0000fa04, 0x0000006f, /* 0000006f //C 0fa04 db	111 */
0x0000fa05, 0x00000020, /* 00000020 //C 0fa05 db	32 */
0x0000fa06, 0x00000061, /* 00000061 //C 0fa06 db	97 */
0x0000fa07, 0x00000064, /* 00000064 //C 0fa07 db	100 */
0x0000fa08, 0x00000064, /* 00000064 //C 0fa08 db	100 */
0x0000fa09, 0x00000072, /* 00000072 //C 0fa09 db	114 */
0x0000fa0a, 0x00000065, /* 00000065 //C 0fa0a db	101 */
0x0000fa0b, 0x00000073, /* 00000073 //C 0fa0b db	115 */
0x0000fa0c, 0x00000073, /* 00000073 //C 0fa0c db	115 */
0x0000fa0d, 0x00000000, /* 00000000 //C 0fa0d db */
0x0000fa0e, 0x00000052, /* 00000052 //C 0fa0e db	82 */
0x0000fa0f, 0x00000075, /* 00000075 //C 0fa0f db	117 */
0x0000fa10, 0x0000006e, /* 0000006e //C 0fa10 db	110 */
0x0000fa11, 0x00000020, /* 00000020 //C 0fa11 db	32 */
0x0000fa12, 0x00000000, /* 00000000 //C 0fa12 db */
0x0000fa13, 0x0ded0000, /* 0ded0000 //C 0fa13 push	lr */
0x0000fa14, 0x0122fc2f, /* 0122fc2f //C 0fa14 mvzl	r2,helps */
0x0000fa15, 0x01320000, /* 01320000 //C 0fa15 mvzl	r3,0 */
0x0000fa16, 0x0b038200, /* 0b038200 //C 0fa16 ld	r0,r3+,r2	; pick a char */
0x0000fa17, 0x020b0000, /* 020b0000 //C 0fa17 sz	r0		; is it eos? */
0x0000fa18, 0x21f2fa1c, /* 21f2fa1c //C 0fa18 jnz	h_print */
0x0000fa19, 0x0b038200, /* 0b038200 //C 0fa19 ld	r0,r3+,r2	; get first char of next string */
0x0000fa1a, 0x020b0000, /* 020b0000 //C 0fa1a sz	r0 */
0x0000fa1b, 0x11f2fa1e, /* 11f2fa1e //C 0fa1b jz	h_eof */
0x0000fa1c, 0x0400fb02, /* 0400fb02 //C 0fa1c call	putchar */
0x0000fa1d, 0x01f2fa16, /* 01f2fa16 //C 0fa1d jmp	h_cyc */
0x0000fa1e, 0x0fed0000, /* 0fed0000 //C 0fa1e pop	lr */
0x0000fa1f, 0x00f00e00, /* 00f00e00 //C 0fa1f ret */
0x0000fa20, 0x0ded0000, /* 0ded0000 //C 0fa20 push	lr */
0x0000fa21, 0x0d1d0000, /* 0d1d0000 //C 0fa21 push	r1 */
0x0000fa22, 0x00100000, /* 00100000 //C 0fa22 mov	r1,r0 */
0x0000fa23, 0x01180010, /* 01180010 //C 0fa23 cmp	r1,16		; go out if nr>16 */
0x0000fa24, 0x91f2fa3d, /* 91f2fa3d //C 0fa24 HI jmp	prn_ret */
0x0000fa25, 0x0118000f, /* 0118000f //C 0fa25 cmp	r1,15		; nr=Flag? */
0x0000fa26, 0xa1f2fa2d, /* a1f2fa2d //C 0fa26 LS jmp	prn_015 */
0x0000fa27, 0x01020046, /* 01020046 //C 0fa27 mvzl	r0,'F' */
0x0000fa28, 0x0400fb02, /* 0400fb02 //C 0fa28 call	putchar */
0x0000fa29, 0x01020020, /* 01020020 //C 0fa29 mvzl	r0,32 */
0x0000fa2a, 0x0400fb02, /* 0400fb02 //C 0fa2a call	putchar */
0x0000fa2b, 0x0400fb02, /* 0400fb02 //C 0fa2b call	putchar */
0x0000fa2c, 0x01f2fa3d, /* 01f2fa3d //C 0fa2c jmp	prn_ret */
0x0000fa2d, 0x01020052, /* 01020052 //C 0fa2d mvzl	r0,'R' */
0x0000fa2e, 0x0400fb02, /* 0400fb02 //C 0fa2e call	putchar */
0x0000fa2f, 0x01180009, /* 01180009 //C 0fa2f cmp	r1,9 */
0x0000fa30, 0x91f2fa37, /* 91f2fa37 //C 0fa30 HI jmp	prn_1015 */
0x0000fa31, 0x00000100, /* 00000100 //C 0fa31 mov	r0,r1 */
0x0000fa32, 0x01040030, /* 01040030 //C 0fa32 add	r0,'0' */
0x0000fa33, 0x0400fb02, /* 0400fb02 //C 0fa33 call	putchar */
0x0000fa34, 0x01020020, /* 01020020 //C 0fa34 mvzl	r0,32 */
0x0000fa35, 0x0400fb02, /* 0400fb02 //C 0fa35 call	putchar */
0x0000fa36, 0x01f2fa3d, /* 01f2fa3d //C 0fa36 jmp	prn_ret */
0x0000fa37, 0x01020031, /* 01020031 //C 0fa37 mvzl	r0,'1' */
0x0000fa38, 0x0400fb02, /* 0400fb02 //C 0fa38 call	putchar */
0x0000fa39, 0x00000100, /* 00000100 //C 0fa39 mov	r0,r1 */
0x0000fa3a, 0x0106000a, /* 0106000a //C 0fa3a sub	r0,10 */
0x0000fa3b, 0x01040030, /* 01040030 //C 0fa3b add	r0,'0' */
0x0000fa3c, 0x0400fb02, /* 0400fb02 //C 0fa3c call	putchar */
0x0000fa3d, 0x0f1d0000, /* 0f1d0000 //C 0fa3d pop	r1 */
0x0000fa3e, 0x0fed0000, /* 0fed0000 //C 0fa3e pop	lr */
0x0000fa3f, 0x00f00e00, /* 00f00e00 //C 0fa3f ret */
0x0000fa40, 0x0ded0000, /* 0ded0000 //C 0fa40 push	lr */
0x0000fa41, 0x0d1d0000, /* 0d1d0000 //C 0fa41 push	r1 */
0x0000fa42, 0x01080010, /* 01080010 //C 0fa42 cmp	r0,16 */
0x0000fa43, 0x91f2fa48, /* 91f2fa48 //C 0fa43 HI jmp	prv_ret */
0x0000fa44, 0x0112fbb9, /* 0112fbb9 //C 0fa44 mvzl	r1,reg0 */
0x0000fa45, 0x0a010000, /* 0a010000 //C 0fa45 ld	r0,r1,r0 */
0x0000fa46, 0x01120004, /* 01120004 //C 0fa46 mvzl	r1,4 */
0x0000fa47, 0x0400fb25, /* 0400fb25 //C 0fa47 call	print_vhex */
0x0000fa48, 0x0f1d0000, /* 0f1d0000 //C 0fa48 pop	r1 */
0x0000fa49, 0x0fed0000, /* 0fed0000 //C 0fa49 pop	lr */
0x0000fa4a, 0x00f00e00, /* 00f00e00 //C 0fa4a ret */
0x0000fa4b, 0x0ded0000, /* 0ded0000 //C 0fa4b push	lr */
0x0000fa4c, 0x01a20000, /* 01a20000 //C 0fa4c mvzl	r10,0 */
0x0000fa4d, 0x00000a00, /* 00000a00 //C 0fa4d mov	r0,r10 */
0x0000fa4e, 0x0400fa20, /* 0400fa20 //C 0fa4e call	print_reg_name */
0x0000fa4f, 0x01020020, /* 01020020 //C 0fa4f mvzl	r0,32 */
0x0000fa50, 0x0400fb02, /* 0400fb02 //C 0fa50 call	putchar */
0x0000fa51, 0x00000a00, /* 00000a00 //C 0fa51 mov	r0,r10 */
0x0000fa52, 0x0400fa40, /* 0400fa40 //C 0fa52 call	print_reg_value */
0x0000fa53, 0x0102000a, /* 0102000a //C 0fa53 mvzl	r0,LF */
0x0000fa54, 0x0400fb02, /* 0400fb02 //C 0fa54 call	putchar */
0x0000fa55, 0x01a40001, /* 01a40001 //C 0fa55 add	r10,1 */
0x0000fa56, 0x01a80011, /* 01a80011 //C 0fa56 cmp	r10,17 */
0x0000fa57, 0x21f2fa4d, /* 21f2fa4d //C 0fa57 jnz	r_cyc */
0x0000fa58, 0x0fed0000, /* 0fed0000 //C 0fa58 pop	lr */
0x0000fa59, 0x00f00e00, /* 00f00e00 //C 0fa59 ret */
0x0000fa5a, 0x0d1d0000, /* 0d1d0000 //C 0fa5a push	r1 */
0x0000fa5b, 0x0d2d0000, /* 0d2d0000 //C 0fa5b push	r2 */
0x0000fa5c, 0x0e210000, /* 0e210000 //C 0fa5c ld	r2,r1 */
0x0000fa5d, 0x022b0000, /* 022b0000 //C 0fa5d sz	r2 */
0x0000fa5e, 0x11f2fa65, /* 11f2fa65 //C 0fa5e jz	strchr_no	; eof string found */
0x0000fa5f, 0x00280000, /* 00280000 //C 0fa5f cmp	r2,r0		; compare */
0x0000fa60, 0x11f2fa63, /* 11f2fa63 //C 0fa60 jz	strchr_yes */
0x0000fa61, 0x011a0001, /* 011a0001 //C 0fa61 plus	r1,1		; go to next char */
0x0000fa62, 0x01f2fa5c, /* 01f2fa5c //C 0fa62 jmp	strchr_cyc */
0x0000fa63, 0x020c0000, /* 020c0000 //C 0fa63 sec */
0x0000fa64, 0x01f2fa67, /* 01f2fa67 //C 0fa64 jmp	strchr_ret */
0x0000fa65, 0x01120000, /* 01120000 //C 0fa65 mvzl	r1,0 */
0x0000fa66, 0x020d0000, /* 020d0000 //C 0fa66 clc */
0x0000fa67, 0x0f2d0000, /* 0f2d0000 //C 0fa67 pop	r2 */
0x0000fa68, 0x0f1d0000, /* 0f1d0000 //C 0fa68 pop	r1 */
0x0000fa69, 0x00f00e00, /* 00f00e00 //C 0fa69 ret */
0x0000fa6a, 0x0ded0000, /* 0ded0000 //C 0fa6a push	lr		; Save used registers */
0x0000fa6b, 0x0d0d0000, /* 0d0d0000 //C 0fa6b push	r0		; and input parameters */
0x0000fa6c, 0x0d1d0000, /* 0d1d0000 //C 0fa6c push	r1 */
0x0000fa6d, 0x0d2d0000, /* 0d2d0000 //C 0fa6d push	r2 */
0x0000fa6e, 0x0d4d0000, /* 0d4d0000 //C 0fa6e push	r4 */
0x0000fa6f, 0x0d5d0000, /* 0d5d0000 //C 0fa6f push	r5 */
0x0000fa70, 0x0d6d0000, /* 0d6d0000 //C 0fa70 push	r6 */
0x0000fa71, 0x0e200000, /* 0e200000 //C 0fa71 ld	r2,r0		; Got one-one char */
0x0000fa72, 0x0e610000, /* 0e610000 //C 0fa72 ld	r6,r1		; from two strings */
0x0000fa73, 0x023b0000, /* 023b0000 //C 0fa73 sz	r3		; Prepare for comparing */
0x0000fa74, 0x112d0020, /* 112d0020 //C 0fa74 Z1 or	r2,0x20		; if insensitive case */
0x0000fa75, 0x023b0000, /* 023b0000 //C 0fa75 sz	r3 */
0x0000fa76, 0x116d0020, /* 116d0020 //C 0fa76 Z1 or	r6,0x20 */
0x0000fa77, 0x00280600, /* 00280600 //C 0fa77 cmp	r2,r6		; compare them */
0x0000fa78, 0x21f2fa8a, /* 21f2fa8a //C 0fa78 jnz	streq_no	; if differs: strings are not equal */
0x0000fa79, 0x0e200000, /* 0e200000 //C 0fa79 ld	r2,r0		; Pick original (non-prepared) */
0x0000fa7a, 0x0e610000, /* 0e610000 //C 0fa7a ld	r6,r1		; chars to check EOS */
0x0000fa7b, 0x022b0000, /* 022b0000 //C 0fa7b sz	r2		; convert them to boolean */
0x0000fa7c, 0x21220001, /* 21220001 //C 0fa7c Z0 mvzl	r2,1		; values in R2,R6 */
0x0000fa7d, 0x11220000, /* 11220000 //C 0fa7d Z1 mvzl	r2,0		; and copy in R4,R5 */
0x0000fa7e, 0x00400200, /* 00400200 //C 0fa7e mov	r4,r2 */
0x0000fa7f, 0x026b0000, /* 026b0000 //C 0fa7f sz	r6 */
0x0000fa80, 0x21620001, /* 21620001 //C 0fa80 Z0 mvzl	r6,1 */
0x0000fa81, 0x11620000, /* 11620000 //C 0fa81 Z1 mvzl r6,0 */
0x0000fa82, 0x00500600, /* 00500600 //C 0fa82 mov	r5,r6 */
0x0000fa83, 0x004d0500, /* 004d0500 //C 0fa83 or	r4,r5		; if both are EOS: equal */
0x0000fa84, 0x11f2fa8c, /* 11f2fa8c //C 0fa84 jz	streq_yes */
0x0000fa85, 0x002f0600, /* 002f0600 //C 0fa85 and 	r2,r6		; just one is EOS: not equal */
0x0000fa86, 0x11f2fa8a, /* 11f2fa8a //C 0fa86 jz	streq_no */
0x0000fa87, 0x010a0001, /* 010a0001 //C 0fa87 plus	r0,1		; non are EOS: go to check next char */
0x0000fa88, 0x011a0001, /* 011a0001 //C 0fa88 plus	r1,1 */
0x0000fa89, 0x01f2fa71, /* 01f2fa71 //C 0fa89 jmp	streq_cyc */
0x0000fa8a, 0x020d0000, /* 020d0000 //C 0fa8a clc			; False result */
0x0000fa8b, 0x01f2fa8d, /* 01f2fa8d //C 0fa8b jmp	streq_ret */
0x0000fa8c, 0x020c0000, /* 020c0000 //C 0fa8c sec			; True result */
0x0000fa8d, 0x0f6d0000, /* 0f6d0000 //C 0fa8d pop	r6 */
0x0000fa8e, 0x0f5d0000, /* 0f5d0000 //C 0fa8e pop	r5 */
0x0000fa8f, 0x0f4d0000, /* 0f4d0000 //C 0fa8f pop	r4 */
0x0000fa90, 0x0f2d0000, /* 0f2d0000 //C 0fa90 pop	r2 */
0x0000fa91, 0x0f1d0000, /* 0f1d0000 //C 0fa91 pop	r1 */
0x0000fa92, 0x0f0d0000, /* 0f0d0000 //C 0fa92 pop	r0 */
0x0000fa93, 0x0fed0000, /* 0fed0000 //C 0fa93 pop	lr */
0x0000fa94, 0x00f00e00, /* 00f00e00 //C 0fa94 ret */
0x0000fa95, 0x0ded0000, /* 0ded0000 //C 0fa95 push	lr */
0x0000fa96, 0x0d3d0000, /* 0d3d0000 //C 0fa96 push	r3 */
0x0000fa97, 0x01320001, /* 01320001 //C 0fa97 mvzl	r3,1 */
0x0000fa98, 0x0400fa6a, /* 0400fa6a //C 0fa98 call	str_cmp_eq */
0x0000fa99, 0x0f3d0000, /* 0f3d0000 //C 0fa99 pop	r3 */
0x0000fa9a, 0x0fed0000, /* 0fed0000 //C 0fa9a pop	lr */
0x0000fa9b, 0x00f00e00, /* 00f00e00 //C 0fa9b ret */
0x0000fa9c, 0x0ded0000, /* 0ded0000 //C 0fa9c push	lr */
0x0000fa9d, 0x0d3d0000, /* 0d3d0000 //C 0fa9d push	r3 */
0x0000fa9e, 0x01320000, /* 01320000 //C 0fa9e mvzl	r3,0 */
0x0000fa9f, 0x0400fa6a, /* 0400fa6a //C 0fa9f call	str_cmp_eq */
0x0000faa0, 0x0f3d0000, /* 0f3d0000 //C 0faa0 pop	r3 */
0x0000faa1, 0x0fed0000, /* 0fed0000 //C 0faa1 pop	lr */
0x0000faa2, 0x00f00e00, /* 00f00e00 //C 0faa2 ret */
0x0000faa3, 0x0108002f, /* 0108002f //C 0faa3 cmp	r0,'/' */
0x0000faa4, 0xa1f2fab9, /* a1f2fab9 //C 0faa4 LS jmp	hc2v_nok */
0x0000faa5, 0x01080039, /* 01080039 //C 0faa5 cmp	r0,'9' */
0x0000faa6, 0xa1f2fab6, /* a1f2fab6 //C 0faa6 LS jmp	hc2v_0_9 */
0x0000faa7, 0x01080040, /* 01080040 //C 0faa7 cmp	r0,'@' */
0x0000faa8, 0xa1f2fab9, /* a1f2fab9 //C 0faa8 LS jmp	hc2v_nok */
0x0000faa9, 0x01080046, /* 01080046 //C 0faa9 cmp	r0,'F' */
0x0000faaa, 0xa1f2fab3, /* a1f2fab3 //C 0faaa LS jmp	hc2v_A_F */
0x0000faab, 0x01080060, /* 01080060 //C 0faab cmp	r0,'`' */
0x0000faac, 0xa1f2fab9, /* a1f2fab9 //C 0faac LS jmp	hc2v_nok */
0x0000faad, 0x01080066, /* 01080066 //C 0faad cmp	r0,'f' */
0x0000faae, 0xa1f2fab0, /* a1f2fab0 //C 0faae LS jmp	hc2v_a_f */
0x0000faaf, 0x01f2fab9, /* 01f2fab9 //C 0faaf jmp	hc2v_nok */
0x0000fab0, 0x0104000a, /* 0104000a //C 0fab0 add	r0,10 */
0x0000fab1, 0x01060061, /* 01060061 //C 0fab1 sub	r0,'a' */
0x0000fab2, 0x01f2fab7, /* 01f2fab7 //C 0fab2 jmp	hc2v_ok */
0x0000fab3, 0x0104000a, /* 0104000a //C 0fab3 add	r0,10 */
0x0000fab4, 0x01060041, /* 01060041 //C 0fab4 sub	r0,'A' */
0x0000fab5, 0x01f2fab7, /* 01f2fab7 //C 0fab5 jmp	hc2v_ok */
0x0000fab6, 0x01060030, /* 01060030 //C 0fab6 sub	r0,'0' */
0x0000fab7, 0x020c0000, /* 020c0000 //C 0fab7 sec */
0x0000fab8, 0x00f00e00, /* 00f00e00 //C 0fab8 ret */
0x0000fab9, 0x020d0000, /* 020d0000 //C 0fab9 clc */
0x0000faba, 0x00f00e00, /* 00f00e00 //C 0faba ret */
0x0000fabb, 0x0d1d0000, /* 0d1d0000 //C 0fabb push	r1 */
0x0000fabc, 0x010f000f, /* 010f000f //C 0fabc and	r0,0xf */
0x0000fabd, 0x0112fac1, /* 0112fac1 //C 0fabd mvzl	r1,v2hc_table */
0x0000fabe, 0x0a010000, /* 0a010000 //C 0fabe ld	r0,r1,r0 */
0x0000fabf, 0x0f1d0000, /* 0f1d0000 //C 0fabf pop	r1 */
0x0000fac0, 0x00f00e00, /* 00f00e00 //C 0fac0 ret */
0x0000fac1, 0x00000030, /* 00000030 //C 0fac1 db	48 */
0x0000fac2, 0x00000031, /* 00000031 //C 0fac2 db	49 */
0x0000fac3, 0x00000032, /* 00000032 //C 0fac3 db	50 */
0x0000fac4, 0x00000033, /* 00000033 //C 0fac4 db	51 */
0x0000fac5, 0x00000034, /* 00000034 //C 0fac5 db	52 */
0x0000fac6, 0x00000035, /* 00000035 //C 0fac6 db	53 */
0x0000fac7, 0x00000036, /* 00000036 //C 0fac7 db	54 */
0x0000fac8, 0x00000037, /* 00000037 //C 0fac8 db	55 */
0x0000fac9, 0x00000038, /* 00000038 //C 0fac9 db	56 */
0x0000faca, 0x00000039, /* 00000039 //C 0faca db	57 */
0x0000facb, 0x00000041, /* 00000041 //C 0facb db	65 */
0x0000facc, 0x00000042, /* 00000042 //C 0facc db	66 */
0x0000facd, 0x00000043, /* 00000043 //C 0facd db	67 */
0x0000face, 0x00000044, /* 00000044 //C 0face db	68 */
0x0000facf, 0x00000045, /* 00000045 //C 0facf db	69 */
0x0000fad0, 0x00000046, /* 00000046 //C 0fad0 db	70 */
0x0000fad1, 0x00000000, /* 00000000 //C 0fad1 db */
0x0000fad2, 0x0ded0000, /* 0ded0000 //C 0fad2 push	lr */
0x0000fad3, 0x0400fabb, /* 0400fabb //C 0fad3 call	value2Hexchar */
0x0000fad4, 0x010d0020, /* 010d0020 //C 0fad4 or	r0,0x20 */
0x0000fad5, 0x0fed0000, /* 0fed0000 //C 0fad5 pop	lr */
0x0000fad6, 0x00f00e00, /* 00f00e00 //C 0fad6 ret */
0x0000fad7, 0x0ded0000, /* 0ded0000 //C 0fad7 push	lr */
0x0000fad8, 0x0d2d0000, /* 0d2d0000 //C 0fad8 push	r2 */
0x0000fad9, 0x0d3d0000, /* 0d3d0000 //C 0fad9 push	r3 */
0x0000fada, 0x01120000, /* 01120000 //C 0fada mvzl	r1,0		; return value */
0x0000fadb, 0x01320000, /* 01320000 //C 0fadb mvzl	r3,0		; index */
0x0000fadc, 0x0b238000, /* 0b238000 //C 0fadc ld	r2,r3+,r0	; pick a char */
0x0000fadd, 0x022b0000, /* 022b0000 //C 0fadd sz	r2		; check eof string */
0x0000fade, 0x11f2faf2, /* 11f2faf2 //C 0fade jz	htoi_eos */
0x0000fadf, 0x0128002e, /* 0128002e //C 0fadf cmp	r2,'.'		; skip separators */
0x0000fae0, 0x11f2fadc, /* 11f2fadc //C 0fae0 jz	htoi_cyc */
0x0000fae1, 0x0128005f, /* 0128005f //C 0fae1 cmp	r2,'_' */
0x0000fae2, 0x11f2fadc, /* 11f2fadc //C 0fae2 jz	htoi_cyc */
0x0000fae3, 0x0d0d0000, /* 0d0d0000 //C 0fae3 push	r0 */
0x0000fae4, 0x00000200, /* 00000200 //C 0fae4 mov	r0,r2 */
0x0000fae5, 0x0400faa3, /* 0400faa3 //C 0fae5 call	hexchar2value */
0x0000fae6, 0x00200000, /* 00200000 //C 0fae6 mov	r2,r0 */
0x0000fae7, 0x0f0d0000, /* 0f0d0000 //C 0fae7 pop	r0 */
0x0000fae8, 0x41f2faf0, /* 41f2faf0 //C 0fae8 C0 jmp	htoi_nok */
0x0000fae9, 0x02180000, /* 02180000 //C 0fae9 shl	r1 */
0x0000faea, 0x02180000, /* 02180000 //C 0faea shl	r1 */
0x0000faeb, 0x02180000, /* 02180000 //C 0faeb shl	r1 */
0x0000faec, 0x02180000, /* 02180000 //C 0faec shl	r1 */
0x0000faed, 0x012f000f, /* 012f000f //C 0faed and	r2,0xf */
0x0000faee, 0x001d0200, /* 001d0200 //C 0faee or	r1,r2 */
0x0000faef, 0x01f2fadc, /* 01f2fadc //C 0faef jmp	htoi_cyc */
0x0000faf0, 0x020d0000, /* 020d0000 //C 0faf0 clc */
0x0000faf1, 0x01f2faf5, /* 01f2faf5 //C 0faf1 jmp	htoi_ret */
0x0000faf2, 0x01380001, /* 01380001 //C 0faf2 cmp	r3,1 */
0x0000faf3, 0x920d0000, /* 920d0000 //C 0faf3 HI clc */
0x0000faf4, 0xa20c0000, /* a20c0000 //C 0faf4 LS sec */
0x0000faf5, 0x0f3d0000, /* 0f3d0000 //C 0faf5 pop	r3 */
0x0000faf6, 0x0f2d0000, /* 0f2d0000 //C 0faf6 pop	r2 */
0x0000faf7, 0x0fed0000, /* 0fed0000 //C 0faf7 pop	lr */
0x0000faf8, 0x00f00e00, /* 00f00e00 //C 0faf8 ret */
0x0000faf9, 0x0d0d0000, /* 0d0d0000 //C 0faf9 push	r0 */
0x0000fafa, 0x0700ff42, /* 0700ff42 //C 0fafa ld	r0,UART_RSTAT */
0x0000fafb, 0x010c0001, /* 010c0001 //C 0fafb test	r0,1 */
0x0000fafc, 0x020d0000, /* 020d0000 //C 0fafc clc */
0x0000fafd, 0x220c0000, /* 220c0000 //C 0fafd Z0 sec */
0x0000fafe, 0x0f0d0000, /* 0f0d0000 //C 0fafe pop	r0 */
0x0000faff, 0x00f00e00, /* 00f00e00 //C 0faff ret */
0x0000fb00, 0x0700ff40, /* 0700ff40 //C 0fb00 ld	r0,UART_DR */
0x0000fb01, 0x00f00e00, /* 00f00e00 //C 0fb01 ret */
0x0000fb02, 0x0d9d0000, /* 0d9d0000 //C 0fb02 push	r9 */
0x0000fb03, 0x0790ff43, /* 0790ff43 //C 0fb03 ld	r9,UART_TSTAT */
0x0000fb04, 0x019c0001, /* 019c0001 //C 0fb04 test	r9,1 */
0x0000fb05, 0x11f2fb03, /* 11f2fb03 //C 0fb05 jz	wait_tc */
0x0000fb06, 0x0600ff40, /* 0600ff40 //C 0fb06 st	r0,UART_DR */
0x0000fb07, 0x0f9d0000, /* 0f9d0000 //C 0fb07 pop	r9 */
0x0000fb08, 0x00f00e00, /* 00f00e00 //C 0fb08 ret */
0x0000fb09, 0x0ded0000, /* 0ded0000 //C 0fb09 push	lr */
0x0000fb0a, 0x0d0d0000, /* 0d0d0000 //C 0fb0a push	r0 */
0x0000fb0b, 0x0d3d0000, /* 0d3d0000 //C 0fb0b push	r3 */
0x0000fb0c, 0x0d4d0000, /* 0d4d0000 //C 0fb0c push	r4 */
0x0000fb0d, 0x01420000, /* 01420000 //C 0fb0d mvzl	r4,0 */
0x0000fb0e, 0x020b0000, /* 020b0000 //C 0fb0e sz	r0 */
0x0000fb0f, 0x1102fbe3, /* 1102fbe3 //C 0fb0f Z1 mvzl	r0,null_str */
0x0000fb10, 0x0b348000, /* 0b348000 //C 0fb10 ld	r3,r4+,r0 */
0x0000fb11, 0x023b0000, /* 023b0000 //C 0fb11 sz	r3 */
0x0000fb12, 0x11f2fb18, /* 11f2fb18 //C 0fb12 jz	prints_done */
0x0000fb13, 0x0d0d0000, /* 0d0d0000 //C 0fb13 push	r0 */
0x0000fb14, 0x00000300, /* 00000300 //C 0fb14 mov	r0,r3 */
0x0000fb15, 0x0400fb02, /* 0400fb02 //C 0fb15 call	putchar */
0x0000fb16, 0x0f0d0000, /* 0f0d0000 //C 0fb16 pop	r0 */
0x0000fb17, 0x01f2fb10, /* 01f2fb10 //C 0fb17 jmp	prints_go */
0x0000fb18, 0x0f4d0000, /* 0f4d0000 //C 0fb18 pop	r4 */
0x0000fb19, 0x0f3d0000, /* 0f3d0000 //C 0fb19 pop	r3 */
0x0000fb1a, 0x0f0d0000, /* 0f0d0000 //C 0fb1a pop	r0 */
0x0000fb1b, 0x0fed0000, /* 0fed0000 //C 0fb1b pop	lr */
0x0000fb1c, 0x00f00e00, /* 00f00e00 //C 0fb1c ret */
0x0000fb1d, 0x0ded0000, /* 0ded0000 //C 0fb1d push	lr */
0x0000fb1e, 0x0400fb09, /* 0400fb09 //C 0fb1e call	prints */
0x0000fb1f, 0x0d0d0000, /* 0d0d0000 //C 0fb1f push	r0 */
0x0000fb20, 0x0102000a, /* 0102000a //C 0fb20 mvzl	r0,LF */
0x0000fb21, 0x0400fb02, /* 0400fb02 //C 0fb21 call	putchar */
0x0000fb22, 0x0f0d0000, /* 0f0d0000 //C 0fb22 pop	r0 */
0x0000fb23, 0x0fed0000, /* 0fed0000 //C 0fb23 pop	lr */
0x0000fb24, 0x00f00e00, /* 00f00e00 //C 0fb24 ret */
0x0000fb25, 0x0ded0000, /* 0ded0000 //C 0fb25 push	lr */
0x0000fb26, 0x0d0d0000, /* 0d0d0000 //C 0fb26 push	r0 */
0x0000fb27, 0x0d1d0000, /* 0d1d0000 //C 0fb27 push	r1 */
0x0000fb28, 0x0d2d0000, /* 0d2d0000 //C 0fb28 push	r2 */
0x0000fb29, 0x0d3d0000, /* 0d3d0000 //C 0fb29 push	r3 */
0x0000fb2a, 0x0d4d0000, /* 0d4d0000 //C 0fb2a push	r4 */
0x0000fb2b, 0x00300000, /* 00300000 //C 0fb2b mov	r3,r0 */
0x0000fb2c, 0x01220000, /* 01220000 //C 0fb2c mvzl	r2,0 */
0x0000fb2d, 0x01420001, /* 01420001 //C 0fb2d mvzl	r4,1 */
0x0000fb2e, 0x01020000, /* 01020000 //C 0fb2e mvzl	r0,0 */
0x0000fb2f, 0x02380000, /* 02380000 //C 0fb2f shl	r3 */
0x0000fb30, 0x02070000, /* 02070000 //C 0fb30 rol	r0 */
0x0000fb31, 0x02380000, /* 02380000 //C 0fb31 shl	r3 */
0x0000fb32, 0x02070000, /* 02070000 //C 0fb32 rol	r0 */
0x0000fb33, 0x02380000, /* 02380000 //C 0fb33 shl	r3 */
0x0000fb34, 0x02070000, /* 02070000 //C 0fb34 rol	r0 */
0x0000fb35, 0x02380000, /* 02380000 //C 0fb35 shl	r3 */
0x0000fb36, 0x02070000, /* 02070000 //C 0fb36 rol	r0 */
0x0000fb37, 0x0400fabb, /* 0400fabb //C 0fb37 call	value2Hexchar */
0x0000fb38, 0x0400fb02, /* 0400fb02 //C 0fb38 call	putchar */
0x0000fb39, 0x01240001, /* 01240001 //C 0fb39 add	r2,1 */
0x0000fb3a, 0x01280008, /* 01280008 //C 0fb3a cmp	r2,8 */
0x0000fb3b, 0x11f2fb45, /* 11f2fb45 //C 0fb3b jz	print_vhex_ret */
0x0000fb3c, 0x021b0000, /* 021b0000 //C 0fb3c sz	r1 */
0x0000fb3d, 0x11f2fb43, /* 11f2fb43 //C 0fb3d jz	print_vhex_nosep */
0x0000fb3e, 0x00480100, /* 00480100 //C 0fb3e cmp	r4,r1 */
0x0000fb3f, 0x21f2fb43, /* 21f2fb43 //C 0fb3f jnz	print_vhex_nosep */
0x0000fb40, 0x0102005f, /* 0102005f //C 0fb40 mvzl	r0,'_' */
0x0000fb41, 0x0400fb02, /* 0400fb02 //C 0fb41 call	putchar */
0x0000fb42, 0x01420000, /* 01420000 //C 0fb42 mvzl	r4,0 */
0x0000fb43, 0x01440001, /* 01440001 //C 0fb43 add	r4,1 */
0x0000fb44, 0x01f2fb2e, /* 01f2fb2e //C 0fb44 jmp	print_vhex_cyc */
0x0000fb45, 0x0f4d0000, /* 0f4d0000 //C 0fb45 pop	r4 */
0x0000fb46, 0x0f3d0000, /* 0f3d0000 //C 0fb46 pop	r3 */
0x0000fb47, 0x0f2d0000, /* 0f2d0000 //C 0fb47 pop	r2 */
0x0000fb48, 0x0f1d0000, /* 0f1d0000 //C 0fb48 pop	r1 */
0x0000fb49, 0x0f0d0000, /* 0f0d0000 //C 0fb49 pop	r0 */
0x0000fb4a, 0x0fed0000, /* 0fed0000 //C 0fb4a pop	lr */
0x0000fb4b, 0x00f00e00, /* 00f00e00 //C 0fb4b ret */
0x0000fbb8, 0x00000000, /* 00000000 //C 0fbb8 dd	0 */
0x0000fbb9, 0x00000000, /* 00000000 //C 0fbb9 dd	0 */
0x0000fbba, 0x00000000, /* 00000000 //C 0fbba dd	0 */
0x0000fbbb, 0x00000000, /* 00000000 //C 0fbbb dd	0 */
0x0000fbbc, 0x00000000, /* 00000000 //C 0fbbc dd	0 */
0x0000fbbd, 0x00000000, /* 00000000 //C 0fbbd dd	0 */
0x0000fbbe, 0x00000000, /* 00000000 //C 0fbbe dd	0 */
0x0000fbbf, 0x00000000, /* 00000000 //C 0fbbf dd	0 */
0x0000fbc0, 0x00000000, /* 00000000 //C 0fbc0 dd	0 */
0x0000fbc1, 0x00000000, /* 00000000 //C 0fbc1 dd	0 */
0x0000fbc2, 0x00000000, /* 00000000 //C 0fbc2 dd	0 */
0x0000fbc3, 0x00000000, /* 00000000 //C 0fbc3 dd	0 */
0x0000fbc4, 0x00000000, /* 00000000 //C 0fbc4 dd	0 */
0x0000fbc5, 0x00000000, /* 00000000 //C 0fbc5 dd	0 */
0x0000fbc6, 0x00000000, /* 00000000 //C 0fbc6 dd	0 */
0x0000fbc7, 0x00000000, /* 00000000 //C 0fbc7 dd	0 */
0x0000fbc8, 0x00000000, /* 00000000 //C 0fbc8 dd	0 */
0x0000fbc9, 0x00000000, /* 00000000 //C 0fbc9 dd	0 */
0x0000fbca, 0x00000050, /* 00000050 //C 0fbca db	80 */
0x0000fbcb, 0x0000004d, /* 0000004d //C 0fbcb db	77 */
0x0000fbcc, 0x0000006f, /* 0000006f //C 0fbcc db	111 */
0x0000fbcd, 0x0000006e, /* 0000006e //C 0fbcd db	110 */
0x0000fbce, 0x00000069, /* 00000069 //C 0fbce db	105 */
0x0000fbcf, 0x00000074, /* 00000074 //C 0fbcf db	116 */
0x0000fbd0, 0x0000006f, /* 0000006f //C 0fbd0 db	111 */
0x0000fbd1, 0x00000072, /* 00000072 //C 0fbd1 db	114 */
0x0000fbd2, 0x00000020, /* 00000020 //C 0fbd2 db	32 */
0x0000fbd3, 0x00000076, /* 00000076 //C 0fbd3 db	118 */
0x0000fbd4, 0x00000031, /* 00000031 //C 0fbd4 db	49 */
0x0000fbd5, 0x0000002e, /* 0000002e //C 0fbd5 db	46 */
0x0000fbd6, 0x00000030, /* 00000030 //C 0fbd6 db	48 */
0x0000fbd7, 0x00000000, /* 00000000 //C 0fbd7 db */
0x0000fbd8, 0x0000003e, /* 0000003e //C 0fbd8 db	62 */
0x0000fbd9, 0x00000000, /* 00000000 //C 0fbd9 db */
0x0000fbda, 0x00000020, /* 00000020 //C 0fbda db	32 */
0x0000fbdb, 0x0000003b, /* 0000003b //C 0fbdb db	59 */
0x0000fbdc, 0x00000009, /* 00000009 //C 0fbdc db	9 */
0x0000fbdd, 0x0000000b, /* 0000000b //C 0fbdd db	11 */
0x0000fbde, 0x0000002c, /* 0000002c //C 0fbde db	44 */
0x0000fbdf, 0x0000003d, /* 0000003d //C 0fbdf db	61 */
0x0000fbe0, 0x0000005b, /* 0000005b //C 0fbe0 db	91 */
0x0000fbe1, 0x0000005d, /* 0000005d //C 0fbe1 db	93 */
0x0000fbe2, 0x00000000, /* 00000000 //C 0fbe2 db */
0x0000fbe3, 0x00000028, /* 00000028 //C 0fbe3 db	40 */
0x0000fbe4, 0x0000006e, /* 0000006e //C 0fbe4 db	110 */
0x0000fbe5, 0x00000075, /* 00000075 //C 0fbe5 db	117 */
0x0000fbe6, 0x0000006c, /* 0000006c //C 0fbe6 db	108 */
0x0000fbe7, 0x0000006c, /* 0000006c //C 0fbe7 db	108 */
0x0000fbe8, 0x00000029, /* 00000029 //C 0fbe8 db	41 */
0x0000fbe9, 0x00000000, /* 00000000 //C 0fbe9 db */
0x0000fbea, 0x0000f8e1, /* 0000f8e1 //C 0fbea dd	cmd_m */
0x0000fbeb, 0x0000006d, /* 0000006d //C 0fbeb db	109 */
0x0000fbec, 0x00000000, /* 00000000 //C 0fbec db */
0x0000fbed, 0x0000f8e1, /* 0000f8e1 //C 0fbed dd	cmd_m */
0x0000fbee, 0x0000006d, /* 0000006d //C 0fbee db	109 */
0x0000fbef, 0x00000065, /* 00000065 //C 0fbef db	101 */
0x0000fbf0, 0x0000006d, /* 0000006d //C 0fbf0 db	109 */
0x0000fbf1, 0x00000000, /* 00000000 //C 0fbf1 db */
0x0000fbf2, 0x0000f936, /* 0000f936 //C 0fbf2 dd	cmd_d */
0x0000fbf3, 0x00000064, /* 00000064 //C 0fbf3 db	100 */
0x0000fbf4, 0x00000000, /* 00000000 //C 0fbf4 db */
0x0000fbf5, 0x0000f936, /* 0000f936 //C 0fbf5 dd	cmd_d */
0x0000fbf6, 0x00000064, /* 00000064 //C 0fbf6 db	100 */
0x0000fbf7, 0x00000075, /* 00000075 //C 0fbf7 db	117 */
0x0000fbf8, 0x0000006d, /* 0000006d //C 0fbf8 db	109 */
0x0000fbf9, 0x00000070, /* 00000070 //C 0fbf9 db	112 */
0x0000fbfa, 0x00000000, /* 00000000 //C 0fbfa db */
0x0000fbfb, 0x0000f969, /* 0000f969 //C 0fbfb dd	cmd_e */
0x0000fbfc, 0x00000065, /* 00000065 //C 0fbfc db	101 */
0x0000fbfd, 0x00000000, /* 00000000 //C 0fbfd db */
0x0000fbfe, 0x0000f96b, /* 0000f96b //C 0fbfe dd	cmd_l */
0x0000fbff, 0x0000006c, /* 0000006c //C 0fbff db	108 */
0x0000fc00, 0x00000000, /* 00000000 //C 0fc00 db */
0x0000fc01, 0x0000f96b, /* 0000f96b //C 0fc01 dd	cmd_l */
0x0000fc02, 0x0000006c, /* 0000006c //C 0fc02 db	108 */
0x0000fc03, 0x0000006f, /* 0000006f //C 0fc03 db	111 */
0x0000fc04, 0x00000061, /* 00000061 //C 0fc04 db	97 */
0x0000fc05, 0x00000064, /* 00000064 //C 0fc05 db	100 */
0x0000fc06, 0x00000000, /* 00000000 //C 0fc06 db */
0x0000fc07, 0x0000f9d8, /* 0000f9d8 //C 0fc07 dd	cmd_g */
0x0000fc08, 0x00000067, /* 00000067 //C 0fc08 db	103 */
0x0000fc09, 0x00000000, /* 00000000 //C 0fc09 db */
0x0000fc0a, 0x0000f9d8, /* 0000f9d8 //C 0fc0a dd	cmd_g */
0x0000fc0b, 0x00000067, /* 00000067 //C 0fc0b db	103 */
0x0000fc0c, 0x0000006f, /* 0000006f //C 0fc0c db	111 */
0x0000fc0d, 0x00000000, /* 00000000 //C 0fc0d db */
0x0000fc0e, 0x0000f9d8, /* 0000f9d8 //C 0fc0e dd	cmd_g */
0x0000fc0f, 0x00000072, /* 00000072 //C 0fc0f db	114 */
0x0000fc10, 0x00000075, /* 00000075 //C 0fc10 db	117 */
0x0000fc11, 0x0000006e, /* 0000006e //C 0fc11 db	110 */
0x0000fc12, 0x00000000, /* 00000000 //C 0fc12 db */
0x0000fc13, 0x0000fa13, /* 0000fa13 //C 0fc13 dd	cmd_h */
0x0000fc14, 0x0000003f, /* 0000003f //C 0fc14 db	63 */
0x0000fc15, 0x00000000, /* 00000000 //C 0fc15 db */
0x0000fc16, 0x0000fa13, /* 0000fa13 //C 0fc16 dd	cmd_h */
0x0000fc17, 0x00000068, /* 00000068 //C 0fc17 db	104 */
0x0000fc18, 0x00000000, /* 00000000 //C 0fc18 db */
0x0000fc19, 0x0000fa13, /* 0000fa13 //C 0fc19 dd	cmd_h */
0x0000fc1a, 0x00000068, /* 00000068 //C 0fc1a db	104 */
0x0000fc1b, 0x00000065, /* 00000065 //C 0fc1b db	101 */
0x0000fc1c, 0x0000006c, /* 0000006c //C 0fc1c db	108 */
0x0000fc1d, 0x00000070, /* 00000070 //C 0fc1d db	112 */
0x0000fc1e, 0x00000000, /* 00000000 //C 0fc1e db */
0x0000fc1f, 0x0000fa4b, /* 0000fa4b //C 0fc1f dd	cmd_r */
0x0000fc20, 0x00000072, /* 00000072 //C 0fc20 db	114 */
0x0000fc21, 0x00000000, /* 00000000 //C 0fc21 db */
0x0000fc22, 0x0000fa4b, /* 0000fa4b //C 0fc22 dd	cmd_r */
0x0000fc23, 0x00000072, /* 00000072 //C 0fc23 db	114 */
0x0000fc24, 0x00000065, /* 00000065 //C 0fc24 db	101 */
0x0000fc25, 0x00000067, /* 00000067 //C 0fc25 db	103 */
0x0000fc26, 0x00000000, /* 00000000 //C 0fc26 db */
0x0000fc27, 0x0000fa4b, /* 0000fa4b //C 0fc27 dd	cmd_r */
0x0000fc28, 0x00000072, /* 00000072 //C 0fc28 db	114 */
0x0000fc29, 0x00000065, /* 00000065 //C 0fc29 db	101 */
0x0000fc2a, 0x00000067, /* 00000067 //C 0fc2a db	103 */
0x0000fc2b, 0x00000073, /* 00000073 //C 0fc2b db	115 */
0x0000fc2c, 0x00000000, /* 00000000 //C 0fc2c db */
0x0000fc2d, 0x00000000, /* 00000000 //C 0fc2d dd	0 */
0x0000fc2e, 0x00000000, /* 00000000 //C 0fc2e dd	0 */
0x0000fc2f, 0x0000006d, /* 0000006d //C 0fc2f db	109 */
0x0000fc30, 0x0000005b, /* 0000005b //C 0fc30 db	91 */
0x0000fc31, 0x00000065, /* 00000065 //C 0fc31 db	101 */
0x0000fc32, 0x0000006d, /* 0000006d //C 0fc32 db	109 */
0x0000fc33, 0x0000005d, /* 0000005d //C 0fc33 db	93 */
0x0000fc34, 0x00000020, /* 00000020 //C 0fc34 db	32 */
0x0000fc35, 0x00000020, /* 00000020 //C 0fc35 db	32 */
0x0000fc36, 0x00000061, /* 00000061 //C 0fc36 db	97 */
0x0000fc37, 0x00000064, /* 00000064 //C 0fc37 db	100 */
0x0000fc38, 0x00000064, /* 00000064 //C 0fc38 db	100 */
0x0000fc39, 0x00000072, /* 00000072 //C 0fc39 db	114 */
0x0000fc3a, 0x00000020, /* 00000020 //C 0fc3a db	32 */
0x0000fc3b, 0x0000005b, /* 0000005b //C 0fc3b db	91 */
0x0000fc3c, 0x00000076, /* 00000076 //C 0fc3c db	118 */
0x0000fc3d, 0x00000061, /* 00000061 //C 0fc3d db	97 */
0x0000fc3e, 0x0000006c, /* 0000006c //C 0fc3e db	108 */
0x0000fc3f, 0x00000075, /* 00000075 //C 0fc3f db	117 */
0x0000fc40, 0x00000065, /* 00000065 //C 0fc40 db	101 */
0x0000fc41, 0x0000005d, /* 0000005d //C 0fc41 db	93 */
0x0000fc42, 0x00000020, /* 00000020 //C 0fc42 db	32 */
0x0000fc43, 0x00000020, /* 00000020 //C 0fc43 db	32 */
0x0000fc44, 0x00000047, /* 00000047 //C 0fc44 db	71 */
0x0000fc45, 0x00000065, /* 00000065 //C 0fc45 db	101 */
0x0000fc46, 0x00000074, /* 00000074 //C 0fc46 db	116 */
0x0000fc47, 0x0000002f, /* 0000002f //C 0fc47 db	47 */
0x0000fc48, 0x00000073, /* 00000073 //C 0fc48 db	115 */
0x0000fc49, 0x00000065, /* 00000065 //C 0fc49 db	101 */
0x0000fc4a, 0x00000074, /* 00000074 //C 0fc4a db	116 */
0x0000fc4b, 0x00000020, /* 00000020 //C 0fc4b db	32 */
0x0000fc4c, 0x0000006d, /* 0000006d //C 0fc4c db	109 */
0x0000fc4d, 0x00000065, /* 00000065 //C 0fc4d db	101 */
0x0000fc4e, 0x0000006d, /* 0000006d //C 0fc4e db	109 */
0x0000fc4f, 0x0000006f, /* 0000006f //C 0fc4f db	111 */
0x0000fc50, 0x00000072, /* 00000072 //C 0fc50 db	114 */
0x0000fc51, 0x00000079, /* 00000079 //C 0fc51 db	121 */
0x0000fc52, 0x0000000a, /* 0000000a //C 0fc52 db	10 */
0x0000fc53, 0x00000000, /* 00000000 //C 0fc53 db */
0x0000fc54, 0x00000064, /* 00000064 //C 0fc54 db	100 */
0x0000fc55, 0x0000005b, /* 0000005b //C 0fc55 db	91 */
0x0000fc56, 0x00000075, /* 00000075 //C 0fc56 db	117 */
0x0000fc57, 0x0000006d, /* 0000006d //C 0fc57 db	109 */
0x0000fc58, 0x00000070, /* 00000070 //C 0fc58 db	112 */
0x0000fc59, 0x0000005d, /* 0000005d //C 0fc59 db	93 */
0x0000fc5a, 0x00000020, /* 00000020 //C 0fc5a db	32 */
0x0000fc5b, 0x00000073, /* 00000073 //C 0fc5b db	115 */
0x0000fc5c, 0x00000074, /* 00000074 //C 0fc5c db	116 */
0x0000fc5d, 0x00000061, /* 00000061 //C 0fc5d db	97 */
0x0000fc5e, 0x00000072, /* 00000072 //C 0fc5e db	114 */
0x0000fc5f, 0x00000074, /* 00000074 //C 0fc5f db	116 */
0x0000fc60, 0x00000020, /* 00000020 //C 0fc60 db	32 */
0x0000fc61, 0x00000065, /* 00000065 //C 0fc61 db	101 */
0x0000fc62, 0x0000006e, /* 0000006e //C 0fc62 db	110 */
0x0000fc63, 0x00000064, /* 00000064 //C 0fc63 db	100 */
0x0000fc64, 0x00000020, /* 00000020 //C 0fc64 db	32 */
0x0000fc65, 0x00000020, /* 00000020 //C 0fc65 db	32 */
0x0000fc66, 0x00000020, /* 00000020 //C 0fc66 db	32 */
0x0000fc67, 0x00000020, /* 00000020 //C 0fc67 db	32 */
0x0000fc68, 0x00000020, /* 00000020 //C 0fc68 db	32 */
0x0000fc69, 0x00000044, /* 00000044 //C 0fc69 db	68 */
0x0000fc6a, 0x00000075, /* 00000075 //C 0fc6a db	117 */
0x0000fc6b, 0x0000006d, /* 0000006d //C 0fc6b db	109 */
0x0000fc6c, 0x00000070, /* 00000070 //C 0fc6c db	112 */
0x0000fc6d, 0x00000020, /* 00000020 //C 0fc6d db	32 */
0x0000fc6e, 0x0000006d, /* 0000006d //C 0fc6e db	109 */
0x0000fc6f, 0x00000065, /* 00000065 //C 0fc6f db	101 */
0x0000fc70, 0x0000006d, /* 0000006d //C 0fc70 db	109 */
0x0000fc71, 0x0000006f, /* 0000006f //C 0fc71 db	111 */
0x0000fc72, 0x00000072, /* 00000072 //C 0fc72 db	114 */
0x0000fc73, 0x00000079, /* 00000079 //C 0fc73 db	121 */
0x0000fc74, 0x00000020, /* 00000020 //C 0fc74 db	32 */
0x0000fc75, 0x00000063, /* 00000063 //C 0fc75 db	99 */
0x0000fc76, 0x0000006f, /* 0000006f //C 0fc76 db	111 */
0x0000fc77, 0x0000006e, /* 0000006e //C 0fc77 db	110 */
0x0000fc78, 0x00000074, /* 00000074 //C 0fc78 db	116 */
0x0000fc79, 0x00000065, /* 00000065 //C 0fc79 db	101 */
0x0000fc7a, 0x0000006e, /* 0000006e //C 0fc7a db	110 */
0x0000fc7b, 0x00000074, /* 00000074 //C 0fc7b db	116 */
0x0000fc7c, 0x0000000a, /* 0000000a //C 0fc7c db	10 */
0x0000fc7d, 0x00000000, /* 00000000 //C 0fc7d db */
0x0000fc7e, 0x00000065, /* 00000065 //C 0fc7e db	101 */
0x0000fc7f, 0x0000000a, /* 0000000a //C 0fc7f db	10 */
0x0000fc80, 0x00000000, /* 00000000 //C 0fc80 db */
0x0000fc81, 0x0000006c, /* 0000006c //C 0fc81 db	108 */
0x0000fc82, 0x0000005b, /* 0000005b //C 0fc82 db	91 */
0x0000fc83, 0x0000006f, /* 0000006f //C 0fc83 db	111 */
0x0000fc84, 0x00000061, /* 00000061 //C 0fc84 db	97 */
0x0000fc85, 0x00000064, /* 00000064 //C 0fc85 db	100 */
0x0000fc86, 0x0000005d, /* 0000005d //C 0fc86 db	93 */
0x0000fc87, 0x00000020, /* 00000020 //C 0fc87 db	32 */
0x0000fc88, 0x00000020, /* 00000020 //C 0fc88 db	32 */
0x0000fc89, 0x00000020, /* 00000020 //C 0fc89 db	32 */
0x0000fc8a, 0x00000020, /* 00000020 //C 0fc8a db	32 */
0x0000fc8b, 0x00000020, /* 00000020 //C 0fc8b db	32 */
0x0000fc8c, 0x00000020, /* 00000020 //C 0fc8c db	32 */
0x0000fc8d, 0x00000020, /* 00000020 //C 0fc8d db	32 */
0x0000fc8e, 0x00000020, /* 00000020 //C 0fc8e db	32 */
0x0000fc8f, 0x00000020, /* 00000020 //C 0fc8f db	32 */
0x0000fc90, 0x00000020, /* 00000020 //C 0fc90 db	32 */
0x0000fc91, 0x00000020, /* 00000020 //C 0fc91 db	32 */
0x0000fc92, 0x00000020, /* 00000020 //C 0fc92 db	32 */
0x0000fc93, 0x00000020, /* 00000020 //C 0fc93 db	32 */
0x0000fc94, 0x00000020, /* 00000020 //C 0fc94 db	32 */
0x0000fc95, 0x00000020, /* 00000020 //C 0fc95 db	32 */
0x0000fc96, 0x0000004c, /* 0000004c //C 0fc96 db	76 */
0x0000fc97, 0x0000006f, /* 0000006f //C 0fc97 db	111 */
0x0000fc98, 0x00000061, /* 00000061 //C 0fc98 db	97 */
0x0000fc99, 0x00000064, /* 00000064 //C 0fc99 db	100 */
0x0000fc9a, 0x00000020, /* 00000020 //C 0fc9a db	32 */
0x0000fc9b, 0x00000068, /* 00000068 //C 0fc9b db	104 */
0x0000fc9c, 0x00000065, /* 00000065 //C 0fc9c db	101 */
0x0000fc9d, 0x00000078, /* 00000078 //C 0fc9d db	120 */
0x0000fc9e, 0x00000020, /* 00000020 //C 0fc9e db	32 */
0x0000fc9f, 0x00000066, /* 00000066 //C 0fc9f db	102 */
0x0000fca0, 0x00000069, /* 00000069 //C 0fca0 db	105 */
0x0000fca1, 0x0000006c, /* 0000006c //C 0fca1 db	108 */
0x0000fca2, 0x00000065, /* 00000065 //C 0fca2 db	101 */
0x0000fca3, 0x00000020, /* 00000020 //C 0fca3 db	32 */
0x0000fca4, 0x00000074, /* 00000074 //C 0fca4 db	116 */
0x0000fca5, 0x0000006f, /* 0000006f //C 0fca5 db	111 */
0x0000fca6, 0x00000020, /* 00000020 //C 0fca6 db	32 */
0x0000fca7, 0x0000006d, /* 0000006d //C 0fca7 db	109 */
0x0000fca8, 0x00000065, /* 00000065 //C 0fca8 db	101 */
0x0000fca9, 0x0000006d, /* 0000006d //C 0fca9 db	109 */
0x0000fcaa, 0x0000006f, /* 0000006f //C 0fcaa db	111 */
0x0000fcab, 0x00000072, /* 00000072 //C 0fcab db	114 */
0x0000fcac, 0x00000079, /* 00000079 //C 0fcac db	121 */
0x0000fcad, 0x0000000a, /* 0000000a //C 0fcad db	10 */
0x0000fcae, 0x00000000, /* 00000000 //C 0fcae db */
0x0000fcaf, 0x00000067, /* 00000067 //C 0fcaf db	103 */
0x0000fcb0, 0x00000028, /* 00000028 //C 0fcb0 db	40 */
0x0000fcb1, 0x0000006f, /* 0000006f //C 0fcb1 db	111 */
0x0000fcb2, 0x00000029, /* 00000029 //C 0fcb2 db	41 */
0x0000fcb3, 0x0000007c, /* 0000007c //C 0fcb3 db	124 */
0x0000fcb4, 0x00000072, /* 00000072 //C 0fcb4 db	114 */
0x0000fcb5, 0x00000075, /* 00000075 //C 0fcb5 db	117 */
0x0000fcb6, 0x0000006e, /* 0000006e //C 0fcb6 db	110 */
0x0000fcb7, 0x00000020, /* 00000020 //C 0fcb7 db	32 */
0x0000fcb8, 0x00000061, /* 00000061 //C 0fcb8 db	97 */
0x0000fcb9, 0x00000064, /* 00000064 //C 0fcb9 db	100 */
0x0000fcba, 0x00000064, /* 00000064 //C 0fcba db	100 */
0x0000fcbb, 0x00000072, /* 00000072 //C 0fcbb db	114 */
0x0000fcbc, 0x00000020, /* 00000020 //C 0fcbc db	32 */
0x0000fcbd, 0x00000020, /* 00000020 //C 0fcbd db	32 */
0x0000fcbe, 0x00000020, /* 00000020 //C 0fcbe db	32 */
0x0000fcbf, 0x00000020, /* 00000020 //C 0fcbf db	32 */
0x0000fcc0, 0x00000020, /* 00000020 //C 0fcc0 db	32 */
0x0000fcc1, 0x00000020, /* 00000020 //C 0fcc1 db	32 */
0x0000fcc2, 0x00000020, /* 00000020 //C 0fcc2 db	32 */
0x0000fcc3, 0x00000020, /* 00000020 //C 0fcc3 db	32 */
0x0000fcc4, 0x00000052, /* 00000052 //C 0fcc4 db	82 */
0x0000fcc5, 0x00000075, /* 00000075 //C 0fcc5 db	117 */
0x0000fcc6, 0x0000006e, /* 0000006e //C 0fcc6 db	110 */
0x0000fcc7, 0x00000020, /* 00000020 //C 0fcc7 db	32 */
0x0000fcc8, 0x00000066, /* 00000066 //C 0fcc8 db	102 */
0x0000fcc9, 0x00000072, /* 00000072 //C 0fcc9 db	114 */
0x0000fcca, 0x0000006f, /* 0000006f //C 0fcca db	111 */
0x0000fccb, 0x0000006d, /* 0000006d //C 0fccb db	109 */
0x0000fccc, 0x00000020, /* 00000020 //C 0fccc db	32 */
0x0000fccd, 0x00000061, /* 00000061 //C 0fccd db	97 */
0x0000fcce, 0x00000064, /* 00000064 //C 0fcce db	100 */
0x0000fccf, 0x00000064, /* 00000064 //C 0fccf db	100 */
0x0000fcd0, 0x00000072, /* 00000072 //C 0fcd0 db	114 */
0x0000fcd1, 0x00000065, /* 00000065 //C 0fcd1 db	101 */
0x0000fcd2, 0x00000073, /* 00000073 //C 0fcd2 db	115 */
0x0000fcd3, 0x00000073, /* 00000073 //C 0fcd3 db	115 */
0x0000fcd4, 0x0000000a, /* 0000000a //C 0fcd4 db	10 */
0x0000fcd5, 0x00000000, /* 00000000 //C 0fcd5 db */
0x0000fcd6, 0x00000072, /* 00000072 //C 0fcd6 db	114 */
0x0000fcd7, 0x0000005b, /* 0000005b //C 0fcd7 db	91 */
0x0000fcd8, 0x00000065, /* 00000065 //C 0fcd8 db	101 */
0x0000fcd9, 0x00000067, /* 00000067 //C 0fcd9 db	103 */
0x0000fcda, 0x0000005b, /* 0000005b //C 0fcda db	91 */
0x0000fcdb, 0x00000073, /* 00000073 //C 0fcdb db	115 */
0x0000fcdc, 0x0000005d, /* 0000005d //C 0fcdc db	93 */
0x0000fcdd, 0x0000005d, /* 0000005d //C 0fcdd db	93 */
0x0000fcde, 0x00000020, /* 00000020 //C 0fcde db	32 */
0x0000fcdf, 0x00000020, /* 00000020 //C 0fcdf db	32 */
0x0000fce0, 0x00000020, /* 00000020 //C 0fce0 db	32 */
0x0000fce1, 0x00000020, /* 00000020 //C 0fce1 db	32 */
0x0000fce2, 0x00000020, /* 00000020 //C 0fce2 db	32 */
0x0000fce3, 0x00000020, /* 00000020 //C 0fce3 db	32 */
0x0000fce4, 0x00000020, /* 00000020 //C 0fce4 db	32 */
0x0000fce5, 0x00000020, /* 00000020 //C 0fce5 db	32 */
0x0000fce6, 0x00000020, /* 00000020 //C 0fce6 db	32 */
0x0000fce7, 0x00000020, /* 00000020 //C 0fce7 db	32 */
0x0000fce8, 0x00000020, /* 00000020 //C 0fce8 db	32 */
0x0000fce9, 0x00000020, /* 00000020 //C 0fce9 db	32 */
0x0000fcea, 0x00000020, /* 00000020 //C 0fcea db	32 */
0x0000fceb, 0x00000050, /* 00000050 //C 0fceb db	80 */
0x0000fcec, 0x00000072, /* 00000072 //C 0fcec db	114 */
0x0000fced, 0x00000069, /* 00000069 //C 0fced db	105 */
0x0000fcee, 0x0000006e, /* 0000006e //C 0fcee db	110 */
0x0000fcef, 0x00000074, /* 00000074 //C 0fcef db	116 */
0x0000fcf0, 0x00000020, /* 00000020 //C 0fcf0 db	32 */
0x0000fcf1, 0x00000072, /* 00000072 //C 0fcf1 db	114 */
0x0000fcf2, 0x00000065, /* 00000065 //C 0fcf2 db	101 */
0x0000fcf3, 0x00000067, /* 00000067 //C 0fcf3 db	103 */
0x0000fcf4, 0x00000069, /* 00000069 //C 0fcf4 db	105 */
0x0000fcf5, 0x00000073, /* 00000073 //C 0fcf5 db	115 */
0x0000fcf6, 0x00000074, /* 00000074 //C 0fcf6 db	116 */
0x0000fcf7, 0x00000065, /* 00000065 //C 0fcf7 db	101 */
0x0000fcf8, 0x00000072, /* 00000072 //C 0fcf8 db	114 */
0x0000fcf9, 0x00000073, /* 00000073 //C 0fcf9 db	115 */
0x0000fcfa, 0x0000000a, /* 0000000a //C 0fcfa db	10 */
0x0000fcfb, 0x00000000, /* 00000000 //C 0fcfb db */
0x0000fcfc, 0x00000068, /* 00000068 //C 0fcfc db	104 */
0x0000fcfd, 0x0000002c, /* 0000002c //C 0fcfd db	44 */
0x0000fcfe, 0x0000003f, /* 0000003f //C 0fcfe db	63 */
0x0000fcff, 0x00000020, /* 00000020 //C 0fcff db	32 */
0x0000fd00, 0x00000020, /* 00000020 //C 0fd00 db	32 */
0x0000fd01, 0x00000020, /* 00000020 //C 0fd01 db	32 */
0x0000fd02, 0x00000020, /* 00000020 //C 0fd02 db	32 */
0x0000fd03, 0x00000020, /* 00000020 //C 0fd03 db	32 */
0x0000fd04, 0x00000020, /* 00000020 //C 0fd04 db	32 */
0x0000fd05, 0x00000020, /* 00000020 //C 0fd05 db	32 */
0x0000fd06, 0x00000020, /* 00000020 //C 0fd06 db	32 */
0x0000fd07, 0x00000020, /* 00000020 //C 0fd07 db	32 */
0x0000fd08, 0x00000020, /* 00000020 //C 0fd08 db	32 */
0x0000fd09, 0x00000020, /* 00000020 //C 0fd09 db	32 */
0x0000fd0a, 0x00000020, /* 00000020 //C 0fd0a db	32 */
0x0000fd0b, 0x00000020, /* 00000020 //C 0fd0b db	32 */
0x0000fd0c, 0x00000020, /* 00000020 //C 0fd0c db	32 */
0x0000fd0d, 0x00000020, /* 00000020 //C 0fd0d db	32 */
0x0000fd0e, 0x00000020, /* 00000020 //C 0fd0e db	32 */
0x0000fd0f, 0x00000020, /* 00000020 //C 0fd0f db	32 */
0x0000fd10, 0x00000020, /* 00000020 //C 0fd10 db	32 */
0x0000fd11, 0x00000048, /* 00000048 //C 0fd11 db	72 */
0x0000fd12, 0x00000065, /* 00000065 //C 0fd12 db	101 */
0x0000fd13, 0x0000006c, /* 0000006c //C 0fd13 db	108 */
0x0000fd14, 0x00000070, /* 00000070 //C 0fd14 db	112 */
0x0000fd15, 0x0000000a, /* 0000000a //C 0fd15 db	10 */
0x0000fd16, 0x00000000, /* 00000000 //C 0fd16 db */
0x0000fd17, 0x00000000, /* 00000000 //C 0fd17 dd	0 */
0x0000fe19, 0x00000045, /* 00000045 //C 0fe19 db	69 */
0x0000fe1a, 0x0000004f, /* 0000004f //C 0fe1a db	79 */
0x0000fe1b, 0x00000046, /* 00000046 //C 0fe1b db	70 */
0x0000fe1c, 0x00000020, /* 00000020 //C 0fe1c db	32 */
0x0000fe1d, 0x00000050, /* 00000050 //C 0fe1d db	80 */
0x0000fe1e, 0x0000004d, /* 0000004d //C 0fe1e db	77 */
0x0000fe1f, 0x0000006f, /* 0000006f //C 0fe1f db	111 */
0x0000fe20, 0x0000006e, /* 0000006e //C 0fe20 db	110 */
0x0000fe21, 0x00000069, /* 00000069 //C 0fe21 db	105 */
0x0000fe22, 0x00000074, /* 00000074 //C 0fe22 db	116 */
0x0000fe23, 0x0000006f, /* 0000006f //C 0fe23 db	111 */
0x0000fe24, 0x00000072, /* 00000072 //C 0fe24 db	114 */
0x0000fe25, 0x0000000a, /* 0000000a //C 0fe25 db	10 */
0x0000fe26, 0x00000000, /* 00000000 //C 0fe26 db */
0xffffffff, 0xffffffff
};
