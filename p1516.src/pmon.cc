#include "pmon.h"

t_mem pmon[]= {
0x00000000, 0x01f2f825, /* 01f2f825 //C 00000 jmp	cold_start */
0x0000f800, 0x01f2f80e, /* 01f2f80e //C 0f800 _f800:	jmp	callin */
0x0000f801, 0x01f2f825, /* 01f2f825 //C 0f801 _f801:	jmp	cold_start */
0x0000f802, 0x01f2fa99, /* 01f2fa99 //C 0f802 _f802:	jmp	strchr */
0x0000f803, 0x01f2fad4, /* 01f2fad4 //C 0f803 _f803:	jmp	streq */
0x0000f804, 0x01f2fadb, /* 01f2fadb //C 0f804 _f804:	jmp	strieq */
0x0000f805, 0x01f2fae2, /* 01f2fae2 //C 0f805 _f805:	jmp	hexchar2value */
0x0000f806, 0x01f2fb11, /* 01f2fb11 //C 0f806 _f806:	jmp	value2hexchar */
0x0000f807, 0x01f2fb16, /* 01f2fb16 //C 0f807 _f807:	jmp	htoi */
0x0000f808, 0x01f2fb38, /* 01f2fb38 //C 0f808 _f808:	jmp	check_uart */
0x0000f809, 0x01f2fb3f, /* 01f2fb3f //C 0f809 _f809:	jmp	read */
0x0000f80a, 0x01f2fb41, /* 01f2fb41 //C 0f80a _f80a:	jmp	putchar */
0x0000f80b, 0x01f2fb48, /* 01f2fb48 //C 0f80b _f80b:	jmp	prints */
0x0000f80c, 0x01f2fb5c, /* 01f2fb5c //C 0f80c _f80c:	jmp	printsnl */
0x0000f80d, 0x01f2fb64, /* 01f2fb64 //C 0f80d _f80d:	jmp	print_vhex */
0x0000f80e, 0x0600fbf8, /* 0600fbf8 //C 0f80e st	r0,reg0 */
0x0000f80f, 0x0610fbf9, /* 0610fbf9 //C 0f80f st	r1,reg1 */
0x0000f810, 0x0620fbfa, /* 0620fbfa //C 0f810 st	r2,reg2 */
0x0000f811, 0x0630fbfb, /* 0630fbfb //C 0f811 st	r3,reg3 */
0x0000f812, 0x0640fbfc, /* 0640fbfc //C 0f812 st	r4,reg4 */
0x0000f813, 0x0650fbfd, /* 0650fbfd //C 0f813 st	r5,reg5 */
0x0000f814, 0x0660fbfe, /* 0660fbfe //C 0f814 st	r6,reg6 */
0x0000f815, 0x0670fbff, /* 0670fbff //C 0f815 st	r7,reg7 */
0x0000f816, 0x0680fc00, /* 0680fc00 //C 0f816 st	r8,reg8 */
0x0000f817, 0x0690fc01, /* 0690fc01 //C 0f817 st	r9,reg9 */
0x0000f818, 0x06a0fc02, /* 06a0fc02 //C 0f818 st	r10,reg10 */
0x0000f819, 0x06b0fc03, /* 06b0fc03 //C 0f819 st	r11,reg11 */
0x0000f81a, 0x06c0fc04, /* 06c0fc04 //C 0f81a st	r12,reg12 */
0x0000f81b, 0x06d0fc05, /* 06d0fc05 //C 0f81b st	r13,reg13 */
0x0000f81c, 0x06e0fc06, /* 06e0fc06 //C 0f81c st	r14,reg14 */
0x0000f81d, 0x06e0fc07, /* 06e0fc07 //C 0f81d st	r14,reg15 */
0x0000f81e, 0x020e0000, /* 020e0000 //C 0f81e getf	r0 */
0x0000f81f, 0x0600fc08, /* 0600fc08 //C 0f81f st	r0,regf */
0x0000f820, 0x01020001, /* 01020001 //C 0f820 mvzl	r0,1 */
0x0000f821, 0x0600fbf7, /* 0600fbf7 //C 0f821 st	r0,called */
0x0000f822, 0x01f2f82f, /* 01f2f82f //C 0f822 jmp	common_start */
0x0000f823, 0x01f2f82f, /* 01f2f82f //C 0f823 jmp	common_start */
0x0000f824, 0x01f2f825, /* 01f2f825 //C 0f824 jmp	cold_start */
0x0000f825, 0x01020000, /* 01020000 //C 0f825 mvzl	r0,0 */
0x0000f826, 0x0600fbf7, /* 0600fbf7 //C 0f826 st	r0,called */
0x0000f827, 0x0102f824, /* 0102f824 //C 0f827 mvzl	r0,def_zero	; restore jmp to monitor at zero */
0x0000f828, 0x0e000000, /* 0e000000 //C 0f828 ld	r0,r0 */
0x0000f829, 0x06000000, /* 06000000 //C 0f829 st	r0,0 */
0x0000f82a, 0x01020000, /* 01020000 //C 0f82a mvzl	r0,0		; def values of some regs */
0x0000f82b, 0x0600fc08, /* 0600fc08 //C 0f82b st	r0,regf		; FALGS= 0 */
0x0000f82c, 0x0102f7ff, /* 0102f7ff //C 0f82c mvzl	r0,0xf7ff	; R13= 0xf7ff */
0x0000f82d, 0x0600fc05, /* 0600fc05 //C 0f82d st	r0,reg13 */
0x0000f82e, 0x01f2f82f, /* 01f2f82f //C 0f82e jmp	common_start: */
0x0000f82f, 0x01d2fe57, /* 01d2fe57 //C 0f82f mvzl	sp,stack_end */
0x0000f830, 0x01020001, /* 01020001 //C 0f830 mvzl	r0,1 */
0x0000f831, 0x0600fbf6, /* 0600fbf6 //C 0f831 st	r0,echo */
0x0000f832, 0x01020000, /* 01020000 //C 0f832 mvzl	r0,0 */
0x0000f833, 0x020f0000, /* 020f0000 //C 0f833 setf	r0 */
0x0000f834, 0x011200d9, /* 011200d9 //C 0f834 mvzl	r1,217 */
0x0000f835, 0x0610ff44, /* 0610ff44 //C 0f835 st	r1,UART_CPB */
0x0000f836, 0x01120003, /* 01120003 //C 0f836 mvzl	r1,3 */
0x0000f837, 0x0610ff41, /* 0610ff41 //C 0f837 st	r1,UART_CTRL */
0x0000f838, 0x0102fc09, /* 0102fc09 //C 0f838 mvzl	r0,msg_start */
0x0000f839, 0x0400fb5c, /* 0400fb5c //C 0f839 call	printsnl */
0x0000f83a, 0x0400f83c, /* 0400f83c //C 0f83a call	setup_line */
0x0000f83b, 0x01f2f846, /* 01f2f846 //C 0f83b jmp	main */
0x0000f83c, 0x0ded0000, /* 0ded0000 //C 0f83c push	lr */
0x0000f83d, 0x01120000, /* 01120000 //C 0f83d mvzl	r1,0		; lptr= 0 */
0x0000f83e, 0x0610fbef, /* 0610fbef //C 0f83e st	r1,line_ptr */
0x0000f83f, 0x0610fb8b, /* 0610fb8b //C 0f83f st	r1,line		; line[0]= 0 */
0x0000f840, 0x01120001, /* 01120001 //C 0f840 mvzl	r1,1		; at_eol= 1 */
0x0000f841, 0x0610fbf0, /* 0610fbf0 //C 0f841 st	r1,at_eol */
0x0000f842, 0x0102fc17, /* 0102fc17 //C 0f842 mvzl	r0,prompt */
0x0000f843, 0x0400fb48, /* 0400fb48 //C 0f843 call	prints */
0x0000f844, 0x0fed0000, /* 0fed0000 //C 0f844 pop	lr */
0x0000f845, 0x00f00e00, /* 00f00e00 //C 0f845 ret */
0x0000f846, 0x0400fb38, /* 0400fb38 //C 0f846 call	check_uart */
0x0000f847, 0x41f2f84d, /* 41f2f84d //C 0f847 C0 jmp	no_input */
0x0000f848, 0x0400fb3f, /* 0400fb3f //C 0f848 call	read */
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
0x0000f854, 0x0620fbf0, /* 0620fbf0 //C 0f854 st	r2,at_eol */
0x0000f855, 0x0112fbef, /* 0112fbef //C 0f855 mvzl	r1,line_ptr	; line[line_ptr]= char */
0x0000f856, 0x0e310000, /* 0e310000 //C 0f856 ld	r3,r1 */
0x0000f857, 0x0122fb8b, /* 0122fb8b //C 0f857 mvzl	r2,line */
0x0000f858, 0x08020300, /* 08020300 //C 0f858 st	r0,r2,r3 */
0x0000f859, 0x013a0001, /* 013a0001 //C 0f859 plus	r3,1		; line_ptr++ */
0x0000f85a, 0x0c310000, /* 0c310000 //C 0f85a st	r3,r1 */
0x0000f85b, 0x01420000, /* 01420000 //C 0f85b mvzl	r4,0 */
0x0000f85c, 0x09438200, /* 09438200 //C 0f85c st	r4,r3+,r2	; line[line_ptr]= 0 */
0x0000f85d, 0x08430200, /* 08430200 //C 0f85d st	r4,r3,r2	; double 0 at end, needed by tokenizer */
0x0000f85e, 0x0142fbf6, /* 0142fbf6 //C 0f85e mvzl	r4,echo		; check if echo is turned on */
0x0000f85f, 0x0e440000, /* 0e440000 //C 0f85f ld	r4,r4 */
0x0000f860, 0x024b0000, /* 024b0000 //C 0f860 sz	r4 */
0x0000f861, 0x2400fb41, /* 2400fb41 //C 0f861 NZ call	putchar		; echo */
0x0000f862, 0x020d0000, /* 020d0000 //C 0f862 clc */
0x0000f863, 0x01f2f869, /* 01f2f869 //C 0f863 jmp	proc_input_ret */
0x0000f864, 0x0112fbf0, /* 0112fbf0 //C 0f864 mvzl	r1,at_eol */
0x0000f865, 0x0e110000, /* 0e110000 //C 0f865 ld	r1,r1 */
0x0000f866, 0x021b0000, /* 021b0000 //C 0f866 sz	r1		; Z=0 at eol -> skip, not ready */
0x0000f867, 0x220d0000, /* 220d0000 //C 0f867 Z0 clc */
0x0000f868, 0x120c0000, /* 120c0000 //C 0f868 Z1 sec */
0x0000f869, 0x0fed0000, /* 0fed0000 //C 0f869 pop	lr */
0x0000f86a, 0x00f00e00, /* 00f00e00 //C 0f86a ret */
0x0000f86b, 0x0ded0000, /* 0ded0000 //C 0f86b push	lr */
0x0000f86c, 0x0102000a, /* 0102000a //C 0f86c mvzl	r0,LF */
0x0000f86d, 0x0400fb41, /* 0400fb41 //C 0f86d call	putchar */
0x0000f86e, 0x0400f893, /* 0400f893 //C 0f86e call	tokenize */
0x0000f86f, 0x0400f8b4, /* 0400f8b4 //C 0f86f call	find_cmd */
0x0000f870, 0x41f2f873, /* 41f2f873 //C 0f870 C0 jmp	cmd_not_found */
0x0000f871, 0x05000000, /* 05000000 //C 0f871 call	r0,0 */
0x0000f872, 0x01f2f875, /* 01f2f875 //C 0f872 jmp	proc_line_ret */
0x0000f873, 0x0102f87e, /* 0102f87e //C 0f873 mvzl	r0,snotfound */
0x0000f874, 0x0400fb5c, /* 0400fb5c //C 0f874 call	printsnl */
0x0000f875, 0x01120001, /* 01120001 //C 0f875 mvzl	r1,1		; at_eol= 1 */
0x0000f876, 0x0610fbf0, /* 0610fbf0 //C 0f876 st	r1,at_eol */
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
0x0000f88f, 0x0112fc19, /* 0112fc19 //C 0f88f mvzl	r1,delimiters */
0x0000f890, 0x0400fa99, /* 0400fa99 //C 0f890 call	strchr */
0x0000f891, 0x0fed0000, /* 0fed0000 //C 0f891 pop	lr */
0x0000f892, 0x00f00e00, /* 00f00e00 //C 0f892 ret */
0x0000f893, 0x0ded0000, /* 0ded0000 //C 0f893 push	lr */
0x0000f894, 0x0142fbf1, /* 0142fbf1 //C 0f894 mvzl	r4,words	; array of result */
0x0000f895, 0x0152fb8b, /* 0152fb8b //C 0f895 mvzl	r5,line		; address of next char */
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
0x0000f8b9, 0x0700fbf1, /* 0700fbf1 //C 0f8b9 ld	r0,words	; R0= 1st word of command */
0x0000f8ba, 0x020b0000, /* 020b0000 //C 0f8ba sz	r0 */
0x0000f8bb, 0x11f2f8d0, /* 11f2f8d0 //C 0f8bb jz	find_cmd_false */
0x0000f8bc, 0x01a2fc29, /* 01a2fc29 //C 0f8bc mvzl	r10,commands */
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
0x0000f8c7, 0x0400fad4, /* 0400fad4 //C 0f8c7 call	streq */
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
0x0000f8d5, 0x0400fad4, /* 0400fad4 //C 0f8d5 call	streq */
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
0x0000f8e2, 0x0122fbf1, /* 0122fbf1 //C 0f8e2 mvzl	r2,words */
0x0000f8e3, 0x01020000, /* 01020000 //C 0f8e3 mvzl	r0,0 */
0x0000f8e4, 0x0e420001, /* 0e420001 //C 0f8e4 ld	r4,r2,1		; addr */
0x0000f8e5, 0x0e520002, /* 0e520002 //C 0f8e5 ld	r5,r2,2		; value */
0x0000f8e6, 0x024b0000, /* 024b0000 //C 0f8e6 sz 	r4 */
0x0000f8e7, 0x11f2f908, /* 11f2f908 //C 0f8e7 jz	m_ret */
0x0000f8e8, 0x00000400, /* 00000400 //C 0f8e8 mov	r0,r4 */
0x0000f8e9, 0x0400fb16, /* 0400fb16 //C 0f8e9 call	htoi */
0x0000f8ea, 0x00400100, /* 00400100 //C 0f8ea mov	r4,r1 */
0x0000f8eb, 0x31f2f8ef, /* 31f2f8ef //C 0f8eb C1 jmp	m_addr_ok */
0x0000f8ec, 0x0102f90a, /* 0102f90a //C 0f8ec mvzl	r0,m_err_addr */
0x0000f8ed, 0x0400fb5c, /* 0400fb5c //C 0f8ed call	printsnl */
0x0000f8ee, 0x01f2f908, /* 01f2f908 //C 0f8ee jmp	m_ret */
0x0000f8ef, 0x025b0000, /* 025b0000 //C 0f8ef sz	r5 */
0x0000f8f0, 0x11f2f8fe, /* 11f2f8fe //C 0f8f0 jz	m_read */
0x0000f8f1, 0x0148fe66, /* 0148fe66 //C 0f8f1 cmp	r4,the_end */
0x0000f8f2, 0x91f2f8f6, /* 91f2f8f6 //C 0f8f2 HI jmp	m_addrv_ok */
0x0000f8f3, 0x0102f918, /* 0102f918 //C 0f8f3 mvzl	r0,m_err_addrv */
0x0000f8f4, 0x0400fb5c, /* 0400fb5c //C 0f8f4 call	printsnl */
0x0000f8f5, 0x01f2f908, /* 01f2f908 //C 0f8f5 jmp	m_ret */
0x0000f8f6, 0x00000500, /* 00000500 //C 0f8f6 mov	r0,r5 */
0x0000f8f7, 0x0400fb16, /* 0400fb16 //C 0f8f7 call	htoi */
0x0000f8f8, 0x00500100, /* 00500100 //C 0f8f8 mov	r5,r1 */
0x0000f8f9, 0x31f2f8fd, /* 31f2f8fd //C 0f8f9 C1 jmp	m_value_ok */
0x0000f8fa, 0x0102f92a, /* 0102f92a //C 0f8fa mvzl	r0,m_err_value */
0x0000f8fb, 0x0400fb5c, /* 0400fb5c //C 0f8fb call	printsnl */
0x0000f8fc, 0x01f2f908, /* 01f2f908 //C 0f8fc jmp	m_ret */
0x0000f8fd, 0x0c540000, /* 0c540000 //C 0f8fd st	r5,r4 */
0x0000f8fe, 0x00000400, /* 00000400 //C 0f8fe mov	r0,r4 */
0x0000f8ff, 0x01120004, /* 01120004 //C 0f8ff mvzl	r1,4 */
0x0000f900, 0x0400fb64, /* 0400fb64 //C 0f900 call	print_vhex */
0x0000f901, 0x01020020, /* 01020020 //C 0f901 mvzl	r0,0x20 */
0x0000f902, 0x0400fb41, /* 0400fb41 //C 0f902 call	putchar */
0x0000f903, 0x0e040000, /* 0e040000 //C 0f903 ld	r0,r4 */
0x0000f904, 0x01120004, /* 01120004 //C 0f904 mvzl	r1,4 */
0x0000f905, 0x0400fb64, /* 0400fb64 //C 0f905 call	print_vhex */
0x0000f906, 0x0102000a, /* 0102000a //C 0f906 mvzl	r0,LF */
0x0000f907, 0x0400fb41, /* 0400fb41 //C 0f907 call	putchar */
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
0x0000f937, 0x0122fbf1, /* 0122fbf1 //C 0f937 mvzl	r2,words */
0x0000f938, 0x0e020001, /* 0e020001 //C 0f938 ld	r0,r2,1		; start address */
0x0000f939, 0x0400fb16, /* 0400fb16 //C 0f939 call	htoi */
0x0000f93a, 0x00300100, /* 00300100 //C 0f93a mov	r3,r1 */
0x0000f93b, 0x0e020002, /* 0e020002 //C 0f93b ld	r0,r2,2		; end address */
0x0000f93c, 0x020b0000, /* 020b0000 //C 0f93c sz	r0 */
0x0000f93d, 0x21f2f941, /* 21f2f941 //C 0f93d jnz	d_end_ok */
0x0000f93e, 0x00400300, /* 00400300 //C 0f93e mov	r4,r3 */
0x0000f93f, 0x01440010, /* 01440010 //C 0f93f add	r4,0x10 */
0x0000f940, 0x01f2f943, /* 01f2f943 //C 0f940 jmp	d_chk_end */
0x0000f941, 0x0400fb16, /* 0400fb16 //C 0f941 call	htoi */
0x0000f942, 0x00400100, /* 00400100 //C 0f942 mov	r4,r1 */
0x0000f943, 0x00380400, /* 00380400 //C 0f943 cmp	r3,r4		; check if start>end */
0x0000f944, 0x91f2f953, /* 91f2f953 //C 0f944 HI jmp d_bad */
0x0000f945, 0x00000300, /* 00000300 //C 0f945 mov	r0,r3		; print address */
0x0000f946, 0x01120004, /* 01120004 //C 0f946 mvzl	r1,4 */
0x0000f947, 0x0400fb64, /* 0400fb64 //C 0f947 call	print_vhex */
0x0000f948, 0x01020020, /* 01020020 //C 0f948 mvzl	r0,0x20		; print one space */
0x0000f949, 0x0400fb41, /* 0400fb41 //C 0f949 call	putchar */
0x0000f94a, 0x0e030000, /* 0e030000 //C 0f94a ld	r0,r3		; load data */
0x0000f94b, 0x01120004, /* 01120004 //C 0f94b mvzl	r1,4		; print data */
0x0000f94c, 0x0400fb64, /* 0400fb64 //C 0f94c call	print_vhex */
0x0000f94d, 0x0102000a, /* 0102000a //C 0f94d mvzl	r0,LF		; print new line */
0x0000f94e, 0x0400fb41, /* 0400fb41 //C 0f94e call	putchar */
0x0000f94f, 0x00380400, /* 00380400 //C 0f94f cmp	r3,r4 */
0x0000f950, 0x11f2f955, /* 11f2f955 //C 0f950 jz	d_ret */
0x0000f951, 0x01340001, /* 01340001 //C 0f951 add	r3,1 */
0x0000f952, 0x01f2f945, /* 01f2f945 //C 0f952 jmp	d_cyc */
0x0000f953, 0x0102f957, /* 0102f957 //C 0f953 mvzl	r0,d_err_bad */
0x0000f954, 0x0400fb5c, /* 0400fb5c //C 0f954 call	printsnl */
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
0x0000f96f, 0x0400fb38, /* 0400fb38 //C 0f96f call	check_uart */
0x0000f970, 0x41f2f96f, /* 41f2f96f //C 0f970 C0 jmp	l_cyc */
0x0000f971, 0x0400fb3f, /* 0400fb3f //C 0f971 call	read */
0x0000f972, 0x00b00000, /* 00b00000 //C 0f972 mov	r11,r0		; Copy of char in R11 */
0x0000f973, 0x0108000a, /* 0108000a //C 0f973 cmp	r0,10		; check EOL chars */
0x0000f974, 0x11f2f9be, /* 11f2f9be //C 0f974 jz	l_eol */
0x0000f975, 0x0108000d, /* 0108000d //C 0f975 cmp	r0,13 */
0x0000f976, 0x11f2f9be, /* 11f2f9be //C 0f976 jz	l_eol */
0x0000f977, 0x01a80000, /* 01a80000 //C 0f977 cmp	r10,0 */
0x0000f978, 0x21f2f988, /* 21f2f988 //C 0f978 jnz	l_no0 */
0x0000f979, 0x0400fae2, /* 0400fae2 //C 0f979 call	hexchar2value */
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
0x0000f99e, 0x0400fb41, /* 0400fb41 //C 0f99e call	putchar		; print record type */
0x0000f99f, 0x01a2000f, /* 01a2000f //C 0f99f mvzl	r10,0xf		; special state: skip everything */
0x0000f9a0, 0x01f2f96f, /* 01f2f96f //C 0f9a0 jmp	l_cyc */
0x0000f9a1, 0x01a80002, /* 01a80002 //C 0f9a1 cmp	r10,2 */
0x0000f9a2, 0x21f2f9b6, /* 21f2f9b6 //C 0f9a2 jnz	l_no2 */
0x0000f9a3, 0x01580000, /* 01580000 //C 0f9a3 cmp	r5,0 */
0x0000f9a4, 0x21f2f9af, /* 21f2f9af //C 0f9a4 jnz	l_s2_no0 */
0x0000f9a5, 0x0400fae2, /* 0400fae2 //C 0f9a5 call	hexchar2value */
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
0x0000f9b1, 0x0400fae2, /* 0400fae2 //C 0f9b1 call	hexchar2value */
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
0x0000f9cd, 0x0400fb41, /* 0400fb41 //C 0f9cd call	putchar */
0x0000f9ce, 0x0102002e, /* 0102002e //C 0f9ce mvzl	r0,'.' */
0x0000f9cf, 0x0400fb41, /* 0400fb41 //C 0f9cf call	putchar */
0x0000f9d0, 0x01a20000, /* 01a20000 //C 0f9d0 mvzl	r10,0 */
0x0000f9d1, 0x01820000, /* 01820000 //C 0f9d1 mvzl	r8,0 */
0x0000f9d2, 0x0162003f, /* 0162003f //C 0f9d2 mvzl	r6,'?' */
0x0000f9d3, 0x01f2f96f, /* 01f2f96f //C 0f9d3 jmp	l_cyc */
0x0000f9d4, 0x0102000a, /* 0102000a //C 0f9d4 mvzl	r0,LF */
0x0000f9d5, 0x0400fb41, /* 0400fb41 //C 0f9d5 call	putchar */
0x0000f9d6, 0x0fed0000, /* 0fed0000 //C 0f9d6 pop	lr */
0x0000f9d7, 0x00f00e00, /* 00f00e00 //C 0f9d7 ret */
0x0000f9d8, 0x0ded0000, /* 0ded0000 //C 0f9d8 push	lr */
0x0000f9d9, 0x0122fbf1, /* 0122fbf1 //C 0f9d9 mvzl	r2,words */
0x0000f9da, 0x0e020001, /* 0e020001 //C 0f9da ld	r0,r2,1		; address */
0x0000f9db, 0x020b0000, /* 020b0000 //C 0f9db sz	r0 */
0x0000f9dc, 0x11f2f9ff, /* 11f2f9ff //C 0f9dc jz	g_no_addr */
0x0000f9dd, 0x0400fb16, /* 0400fb16 //C 0f9dd call	htoi */
0x0000f9de, 0x00b00100, /* 00b00100 //C 0f9de mov	r11,r1 */
0x0000f9df, 0x0102fa13, /* 0102fa13 //C 0f9df mvzl	r0,d_msg_run */
0x0000f9e0, 0x0400fb48, /* 0400fb48 //C 0f9e0 call	prints */
0x0000f9e1, 0x00000b00, /* 00000b00 //C 0f9e1 mov	r0,r11 */
0x0000f9e2, 0x01120004, /* 01120004 //C 0f9e2 mvzl	r1,4 */
0x0000f9e3, 0x0400fb64, /* 0400fb64 //C 0f9e3 call	print_vhex */
0x0000f9e4, 0x0102000a, /* 0102000a //C 0f9e4 mvzl	r0,LF */
0x0000f9e5, 0x0400fb41, /* 0400fb41 //C 0f9e5 call	putchar */
0x0000f9e6, 0x06b0fc07, /* 06b0fc07 //C 0f9e6 st	r11,reg15 */
0x0000f9e7, 0x0122ff43, /* 0122ff43 //C 0f9e7 mvzl	r2,UART_TSTAT */
0x0000f9e8, 0x0e920000, /* 0e920000 //C 0f9e8 ld	r9,r2 */
0x0000f9e9, 0x019c0001, /* 019c0001 //C 0f9e9 test	r9,1 */
0x0000f9ea, 0x11f2f9e8, /* 11f2f9e8 //C 0f9ea jz	g_wait_tc */
0x0000f9eb, 0x07000000, /* 07000000 //C 0f9eb ld	r0,0 */
0x0000f9ec, 0x0600fbf7, /* 0600fbf7 //C 0f9ec st	r0,called */
0x0000f9ed, 0x0700fc08, /* 0700fc08 //C 0f9ed ld	r0,regf */
0x0000f9ee, 0x020f0000, /* 020f0000 //C 0f9ee setf	r0 */
0x0000f9ef, 0x0700fbf8, /* 0700fbf8 //C 0f9ef ld	r0,reg0 */
0x0000f9f0, 0x0710fbf9, /* 0710fbf9 //C 0f9f0 ld	r1,reg1 */
0x0000f9f1, 0x0720fbfa, /* 0720fbfa //C 0f9f1 ld	r2,reg2 */
0x0000f9f2, 0x0730fbfb, /* 0730fbfb //C 0f9f2 ld	r3,reg3 */
0x0000f9f3, 0x0740fbfc, /* 0740fbfc //C 0f9f3 ld	r4,reg4 */
0x0000f9f4, 0x0750fbfd, /* 0750fbfd //C 0f9f4 ld	r5,reg5 */
0x0000f9f5, 0x0760fbfe, /* 0760fbfe //C 0f9f5 ld	r6,reg6 */
0x0000f9f6, 0x0770fbff, /* 0770fbff //C 0f9f6 ld	r7,reg7 */
0x0000f9f7, 0x0780fc00, /* 0780fc00 //C 0f9f7 ld	r8,reg8 */
0x0000f9f8, 0x0790fc01, /* 0790fc01 //C 0f9f8 ld	r9,reg9 */
0x0000f9f9, 0x07a0fc02, /* 07a0fc02 //C 0f9f9 ld	r10,reg10 */
0x0000f9fa, 0x07b0fc03, /* 07b0fc03 //C 0f9fa ld	r11,reg11 */
0x0000f9fb, 0x07c0fc04, /* 07c0fc04 //C 0f9fb ld	r12,reg12 */
0x0000f9fc, 0x07d0fc05, /* 07d0fc05 //C 0f9fc ld	r13,reg13 */
0x0000f9fd, 0x07e0fc06, /* 07e0fc06 //C 0f9fd ld	r14,reg14 */
0x0000f9fe, 0x07f0fc07, /* 07f0fc07 //C 0f9fe ld	r15,reg15 */
0x0000f9ff, 0x0700fbf7, /* 0700fbf7 //C 0f9ff ld	r0,called */
0x0000fa00, 0x020b0000, /* 020b0000 //C 0fa00 sz	r0 */
0x0000fa01, 0x11f2fa04, /* 11f2fa04 //C 0fa01 jz	g_err */
0x0000fa02, 0x07b0fc07, /* 07b0fc07 //C 0fa02 ld	r11,reg15 */
0x0000fa03, 0x01f2f9df, /* 01f2f9df //C 0fa03 jmp	g_go11 */
0x0000fa04, 0x0102fa08, /* 0102fa08 //C 0fa04 mvzl	r0,g_err_addr */
0x0000fa05, 0x0400fb5c, /* 0400fb5c //C 0fa05 call	printsnl */
0x0000fa06, 0x0fed0000, /* 0fed0000 //C 0fa06 pop	lr */
0x0000fa07, 0x00f00e00, /* 00f00e00 //C 0fa07 ret */
0x0000fa08, 0x0000004e, /* 0000004e //C 0fa08 db	78 */
0x0000fa09, 0x0000006f, /* 0000006f //C 0fa09 db	111 */
0x0000fa0a, 0x00000020, /* 00000020 //C 0fa0a db	32 */
0x0000fa0b, 0x00000061, /* 00000061 //C 0fa0b db	97 */
0x0000fa0c, 0x00000064, /* 00000064 //C 0fa0c db	100 */
0x0000fa0d, 0x00000064, /* 00000064 //C 0fa0d db	100 */
0x0000fa0e, 0x00000072, /* 00000072 //C 0fa0e db	114 */
0x0000fa0f, 0x00000065, /* 00000065 //C 0fa0f db	101 */
0x0000fa10, 0x00000073, /* 00000073 //C 0fa10 db	115 */
0x0000fa11, 0x00000073, /* 00000073 //C 0fa11 db	115 */
0x0000fa12, 0x00000000, /* 00000000 //C 0fa12 db */
0x0000fa13, 0x00000052, /* 00000052 //C 0fa13 db	82 */
0x0000fa14, 0x00000075, /* 00000075 //C 0fa14 db	117 */
0x0000fa15, 0x0000006e, /* 0000006e //C 0fa15 db	110 */
0x0000fa16, 0x00000020, /* 00000020 //C 0fa16 db	32 */
0x0000fa17, 0x00000000, /* 00000000 //C 0fa17 db */
0x0000fa18, 0x0ded0000, /* 0ded0000 //C 0fa18 push	lr */
0x0000fa19, 0x0122fc6e, /* 0122fc6e //C 0fa19 mvzl	r2,helps */
0x0000fa1a, 0x01320000, /* 01320000 //C 0fa1a mvzl	r3,0 */
0x0000fa1b, 0x0b038200, /* 0b038200 //C 0fa1b ld	r0,r3+,r2	; pick a char */
0x0000fa1c, 0x020b0000, /* 020b0000 //C 0fa1c sz	r0		; is it eos? */
0x0000fa1d, 0x21f2fa21, /* 21f2fa21 //C 0fa1d jnz	h_print */
0x0000fa1e, 0x0b038200, /* 0b038200 //C 0fa1e ld	r0,r3+,r2	; get first char of next string */
0x0000fa1f, 0x020b0000, /* 020b0000 //C 0fa1f sz	r0 */
0x0000fa20, 0x11f2fa23, /* 11f2fa23 //C 0fa20 jz	h_eof */
0x0000fa21, 0x0400fb41, /* 0400fb41 //C 0fa21 call	putchar */
0x0000fa22, 0x01f2fa1b, /* 01f2fa1b //C 0fa22 jmp	h_cyc */
0x0000fa23, 0x0fed0000, /* 0fed0000 //C 0fa23 pop	lr */
0x0000fa24, 0x00f00e00, /* 00f00e00 //C 0fa24 ret */
0x0000fa25, 0x0ded0000, /* 0ded0000 //C 0fa25 push	lr */
0x0000fa26, 0x0d1d0000, /* 0d1d0000 //C 0fa26 push	r1 */
0x0000fa27, 0x00100000, /* 00100000 //C 0fa27 mov	r1,r0 */
0x0000fa28, 0x01180010, /* 01180010 //C 0fa28 cmp	r1,16		; go out if nr>16 */
0x0000fa29, 0x91f2fa5d, /* 91f2fa5d //C 0fa29 HI jmp	prn_ret */
0x0000fa2a, 0x0118000f, /* 0118000f //C 0fa2a cmp	r1,15		; nr=Flag? */
0x0000fa2b, 0xa1f2fa32, /* a1f2fa32 //C 0fa2b LS jmp	prn_015 */
0x0000fa2c, 0x01020046, /* 01020046 //C 0fa2c mvzl	r0,'F' */
0x0000fa2d, 0x0400fb41, /* 0400fb41 //C 0fa2d call	putchar */
0x0000fa2e, 0x01020020, /* 01020020 //C 0fa2e mvzl	r0,32 */
0x0000fa2f, 0x0400fb41, /* 0400fb41 //C 0fa2f call	putchar */
0x0000fa30, 0x0400fb41, /* 0400fb41 //C 0fa30 call	putchar */
0x0000fa31, 0x01f2fa5d, /* 01f2fa5d //C 0fa31 jmp	prn_ret */
0x0000fa32, 0x0118000f, /* 0118000f //C 0fa32 cmp	r1,15 */
0x0000fa33, 0x21f2fa3b, /* 21f2fa3b //C 0fa33 jnz	prn_no15 */
0x0000fa34, 0x0102fa37, /* 0102fa37 //C 0fa34 mvzl	r0,prn_PC */
0x0000fa35, 0x0400fb48, /* 0400fb48 //C 0fa35 call	prints */
0x0000fa36, 0x01f2fa5d, /* 01f2fa5d //C 0fa36 jmp	prn_ret */
0x0000fa37, 0x00000050, /* 00000050 //C 0fa37 db	80 */
0x0000fa38, 0x00000043, /* 00000043 //C 0fa38 db	67 */
0x0000fa39, 0x00000020, /* 00000020 //C 0fa39 db	32 */
0x0000fa3a, 0x00000000, /* 00000000 //C 0fa3a db */
0x0000fa3b, 0x0118000e, /* 0118000e //C 0fa3b cmp	r1,14 */
0x0000fa3c, 0x21f2fa44, /* 21f2fa44 //C 0fa3c jnz	prn_no14 */
0x0000fa3d, 0x0102fa40, /* 0102fa40 //C 0fa3d mvzl	r0,prn_LR */
0x0000fa3e, 0x0400fb48, /* 0400fb48 //C 0fa3e call	prints */
0x0000fa3f, 0x01f2fa5d, /* 01f2fa5d //C 0fa3f jmp	prn_ret */
0x0000fa40, 0x0000004c, /* 0000004c //C 0fa40 db	76 */
0x0000fa41, 0x00000052, /* 00000052 //C 0fa41 db	82 */
0x0000fa42, 0x00000020, /* 00000020 //C 0fa42 db	32 */
0x0000fa43, 0x00000000, /* 00000000 //C 0fa43 db */
0x0000fa44, 0x0118000d, /* 0118000d //C 0fa44 cmp	r1,13 */
0x0000fa45, 0x21f2fa4d, /* 21f2fa4d //C 0fa45 jnz	prn_no13 */
0x0000fa46, 0x0102fa49, /* 0102fa49 //C 0fa46 mvzl	r0,prn_SP */
0x0000fa47, 0x0400fb48, /* 0400fb48 //C 0fa47 call	prints */
0x0000fa48, 0x01f2fa5d, /* 01f2fa5d //C 0fa48 jmp	prn_ret */
0x0000fa49, 0x00000053, /* 00000053 //C 0fa49 db	83 */
0x0000fa4a, 0x00000050, /* 00000050 //C 0fa4a db	80 */
0x0000fa4b, 0x00000020, /* 00000020 //C 0fa4b db	32 */
0x0000fa4c, 0x00000000, /* 00000000 //C 0fa4c db */
0x0000fa4d, 0x01020052, /* 01020052 //C 0fa4d mvzl	r0,'R' */
0x0000fa4e, 0x0400fb41, /* 0400fb41 //C 0fa4e call	putchar */
0x0000fa4f, 0x01180009, /* 01180009 //C 0fa4f cmp	r1,9 */
0x0000fa50, 0x91f2fa57, /* 91f2fa57 //C 0fa50 HI jmp	prn_1015 */
0x0000fa51, 0x00000100, /* 00000100 //C 0fa51 mov	r0,r1 */
0x0000fa52, 0x01040030, /* 01040030 //C 0fa52 add	r0,'0' */
0x0000fa53, 0x0400fb41, /* 0400fb41 //C 0fa53 call	putchar */
0x0000fa54, 0x01020020, /* 01020020 //C 0fa54 mvzl	r0,32 */
0x0000fa55, 0x0400fb41, /* 0400fb41 //C 0fa55 call	putchar */
0x0000fa56, 0x01f2fa5d, /* 01f2fa5d //C 0fa56 jmp	prn_ret */
0x0000fa57, 0x01020031, /* 01020031 //C 0fa57 mvzl	r0,'1' */
0x0000fa58, 0x0400fb41, /* 0400fb41 //C 0fa58 call	putchar */
0x0000fa59, 0x00000100, /* 00000100 //C 0fa59 mov	r0,r1 */
0x0000fa5a, 0x0106000a, /* 0106000a //C 0fa5a sub	r0,10 */
0x0000fa5b, 0x01040030, /* 01040030 //C 0fa5b add	r0,'0' */
0x0000fa5c, 0x0400fb41, /* 0400fb41 //C 0fa5c call	putchar */
0x0000fa5d, 0x0f1d0000, /* 0f1d0000 //C 0fa5d pop	r1 */
0x0000fa5e, 0x0fed0000, /* 0fed0000 //C 0fa5e pop	lr */
0x0000fa5f, 0x00f00e00, /* 00f00e00 //C 0fa5f ret */
0x0000fa60, 0x0ded0000, /* 0ded0000 //C 0fa60 push	lr */
0x0000fa61, 0x0d1d0000, /* 0d1d0000 //C 0fa61 push	r1 */
0x0000fa62, 0x01080010, /* 01080010 //C 0fa62 cmp	r0,16 */
0x0000fa63, 0x91f2fa68, /* 91f2fa68 //C 0fa63 HI jmp	prv_ret */
0x0000fa64, 0x0112fbf8, /* 0112fbf8 //C 0fa64 mvzl	r1,reg0 */
0x0000fa65, 0x0a010000, /* 0a010000 //C 0fa65 ld	r0,r1,r0 */
0x0000fa66, 0x01120004, /* 01120004 //C 0fa66 mvzl	r1,4 */
0x0000fa67, 0x0400fb64, /* 0400fb64 //C 0fa67 call	print_vhex */
0x0000fa68, 0x0f1d0000, /* 0f1d0000 //C 0fa68 pop	r1 */
0x0000fa69, 0x0fed0000, /* 0fed0000 //C 0fa69 pop	lr */
0x0000fa6a, 0x00f00e00, /* 00f00e00 //C 0fa6a ret */
0x0000fa6b, 0x0ded0000, /* 0ded0000 //C 0fa6b push	lr */
0x0000fa6c, 0x0400fb41, /* 0400fb41 //C 0fa6c call	putchar */
0x0000fa6d, 0x001c0200, /* 001c0200 //C 0fa6d test	r1,r2 */
0x0000fa6e, 0x21020031, /* 21020031 //C 0fa6e NZ mvzl r0,'1' */
0x0000fa6f, 0x11020030, /* 11020030 //C 0fa6f Z  mvzl r0,'0' */
0x0000fa70, 0x0400fb41, /* 0400fb41 //C 0fa70 call	putchar */
0x0000fa71, 0x00000300, /* 00000300 //C 0fa71 mov	r0,r3 */
0x0000fa72, 0x0400fb41, /* 0400fb41 //C 0fa72 call	putchar */
0x0000fa73, 0x0fed0000, /* 0fed0000 //C 0fa73 pop	lr */
0x0000fa74, 0x00f00e00, /* 00f00e00 //C 0fa74 ret */
0x0000fa75, 0x0ded0000, /* 0ded0000 //C 0fa75 push	lr */
0x0000fa76, 0x01a20000, /* 01a20000 //C 0fa76 mvzl	r10,0 */
0x0000fa77, 0x00000a00, /* 00000a00 //C 0fa77 mov	r0,r10 */
0x0000fa78, 0x0400fa25, /* 0400fa25 //C 0fa78 call	print_reg_name */
0x0000fa79, 0x01020020, /* 01020020 //C 0fa79 mvzl	r0,32 */
0x0000fa7a, 0x0400fb41, /* 0400fb41 //C 0fa7a call	putchar */
0x0000fa7b, 0x00000a00, /* 00000a00 //C 0fa7b mov	r0,r10 */
0x0000fa7c, 0x0400fa60, /* 0400fa60 //C 0fa7c call	print_reg_value */
0x0000fa7d, 0x0102000a, /* 0102000a //C 0fa7d mvzl	r0,LF */
0x0000fa7e, 0x0400fb41, /* 0400fb41 //C 0fa7e call	putchar */
0x0000fa7f, 0x01a40001, /* 01a40001 //C 0fa7f add	r10,1 */
0x0000fa80, 0x01a80011, /* 01a80011 //C 0fa80 cmp	r10,17 */
0x0000fa81, 0x21f2fa77, /* 21f2fa77 //C 0fa81 jnz	r_cyc */
0x0000fa82, 0x0710fc08, /* 0710fc08 //C 0fa82 ld	r1,regf */
0x0000fa83, 0x01320020, /* 01320020 //C 0fa83 mvzl	r3,32 */
0x0000fa84, 0x01020055, /* 01020055 //C 0fa84 mvzl	r0,'U' */
0x0000fa85, 0x01220020, /* 01220020 //C 0fa85 mvzl	r2,0x20 */
0x0000fa86, 0x0400fa6b, /* 0400fa6b //C 0fa86 call	print_flag */
0x0000fa87, 0x01020050, /* 01020050 //C 0fa87 mvzl	r0,'P' */
0x0000fa88, 0x01220010, /* 01220010 //C 0fa88 mvzl	r2,0x10 */
0x0000fa89, 0x0400fa6b, /* 0400fa6b //C 0fa89 call	print_flag */
0x0000fa8a, 0x0102004f, /* 0102004f //C 0fa8a mvzl	r0,'O' */
0x0000fa8b, 0x01220008, /* 01220008 //C 0fa8b mvzl	r2,8 */
0x0000fa8c, 0x0400fa6b, /* 0400fa6b //C 0fa8c call	print_flag */
0x0000fa8d, 0x0102005a, /* 0102005a //C 0fa8d mvzl	r0,'Z' */
0x0000fa8e, 0x01220004, /* 01220004 //C 0fa8e mvzl	r2,4 */
0x0000fa8f, 0x0400fa6b, /* 0400fa6b //C 0fa8f call	print_flag */
0x0000fa90, 0x01020043, /* 01020043 //C 0fa90 mvzl	r0,'C' */
0x0000fa91, 0x01220002, /* 01220002 //C 0fa91 mvzl	r2,2 */
0x0000fa92, 0x0400fa6b, /* 0400fa6b //C 0fa92 call	print_flag */
0x0000fa93, 0x01020053, /* 01020053 //C 0fa93 mvzl	r0,'S' */
0x0000fa94, 0x01220001, /* 01220001 //C 0fa94 mvzl	r2,1 */
0x0000fa95, 0x0132000a, /* 0132000a //C 0fa95 mvzl	r3,LF */
0x0000fa96, 0x0400fa6b, /* 0400fa6b //C 0fa96 call	print_flag */
0x0000fa97, 0x0fed0000, /* 0fed0000 //C 0fa97 pop	lr */
0x0000fa98, 0x00f00e00, /* 00f00e00 //C 0fa98 ret */
0x0000fa99, 0x0d1d0000, /* 0d1d0000 //C 0fa99 push	r1 */
0x0000fa9a, 0x0d2d0000, /* 0d2d0000 //C 0fa9a push	r2 */
0x0000fa9b, 0x0e210000, /* 0e210000 //C 0fa9b ld	r2,r1 */
0x0000fa9c, 0x022b0000, /* 022b0000 //C 0fa9c sz	r2 */
0x0000fa9d, 0x11f2faa4, /* 11f2faa4 //C 0fa9d jz	strchr_no	; eof string found */
0x0000fa9e, 0x00280000, /* 00280000 //C 0fa9e cmp	r2,r0		; compare */
0x0000fa9f, 0x11f2faa2, /* 11f2faa2 //C 0fa9f jz	strchr_yes */
0x0000faa0, 0x011a0001, /* 011a0001 //C 0faa0 plus	r1,1		; go to next char */
0x0000faa1, 0x01f2fa9b, /* 01f2fa9b //C 0faa1 jmp	strchr_cyc */
0x0000faa2, 0x020c0000, /* 020c0000 //C 0faa2 sec */
0x0000faa3, 0x01f2faa6, /* 01f2faa6 //C 0faa3 jmp	strchr_ret */
0x0000faa4, 0x01120000, /* 01120000 //C 0faa4 mvzl	r1,0 */
0x0000faa5, 0x020d0000, /* 020d0000 //C 0faa5 clc */
0x0000faa6, 0x0f2d0000, /* 0f2d0000 //C 0faa6 pop	r2 */
0x0000faa7, 0x0f1d0000, /* 0f1d0000 //C 0faa7 pop	r1 */
0x0000faa8, 0x00f00e00, /* 00f00e00 //C 0faa8 ret */
0x0000faa9, 0x0ded0000, /* 0ded0000 //C 0faa9 push	lr		; Save used registers */
0x0000faaa, 0x0d0d0000, /* 0d0d0000 //C 0faaa push	r0		; and input parameters */
0x0000faab, 0x0d1d0000, /* 0d1d0000 //C 0faab push	r1 */
0x0000faac, 0x0d2d0000, /* 0d2d0000 //C 0faac push	r2 */
0x0000faad, 0x0d4d0000, /* 0d4d0000 //C 0faad push	r4 */
0x0000faae, 0x0d5d0000, /* 0d5d0000 //C 0faae push	r5 */
0x0000faaf, 0x0d6d0000, /* 0d6d0000 //C 0faaf push	r6 */
0x0000fab0, 0x0e200000, /* 0e200000 //C 0fab0 ld	r2,r0		; Got one-one char */
0x0000fab1, 0x0e610000, /* 0e610000 //C 0fab1 ld	r6,r1		; from two strings */
0x0000fab2, 0x023b0000, /* 023b0000 //C 0fab2 sz	r3		; Prepare for comparing */
0x0000fab3, 0x112d0020, /* 112d0020 //C 0fab3 Z1 or	r2,0x20		; if insensitive case */
0x0000fab4, 0x023b0000, /* 023b0000 //C 0fab4 sz	r3 */
0x0000fab5, 0x116d0020, /* 116d0020 //C 0fab5 Z1 or	r6,0x20 */
0x0000fab6, 0x00280600, /* 00280600 //C 0fab6 cmp	r2,r6		; compare them */
0x0000fab7, 0x21f2fac9, /* 21f2fac9 //C 0fab7 jnz	streq_no	; if differs: strings are not equal */
0x0000fab8, 0x0e200000, /* 0e200000 //C 0fab8 ld	r2,r0		; Pick original (non-prepared) */
0x0000fab9, 0x0e610000, /* 0e610000 //C 0fab9 ld	r6,r1		; chars to check EOS */
0x0000faba, 0x022b0000, /* 022b0000 //C 0faba sz	r2		; convert them to boolean */
0x0000fabb, 0x21220001, /* 21220001 //C 0fabb Z0 mvzl	r2,1		; values in R2,R6 */
0x0000fabc, 0x11220000, /* 11220000 //C 0fabc Z1 mvzl	r2,0		; and copy in R4,R5 */
0x0000fabd, 0x00400200, /* 00400200 //C 0fabd mov	r4,r2 */
0x0000fabe, 0x026b0000, /* 026b0000 //C 0fabe sz	r6 */
0x0000fabf, 0x21620001, /* 21620001 //C 0fabf Z0 mvzl	r6,1 */
0x0000fac0, 0x11620000, /* 11620000 //C 0fac0 Z1 mvzl r6,0 */
0x0000fac1, 0x00500600, /* 00500600 //C 0fac1 mov	r5,r6 */
0x0000fac2, 0x004d0500, /* 004d0500 //C 0fac2 or	r4,r5		; if both are EOS: equal */
0x0000fac3, 0x11f2facb, /* 11f2facb //C 0fac3 jz	streq_yes */
0x0000fac4, 0x002f0600, /* 002f0600 //C 0fac4 and 	r2,r6		; just one is EOS: not equal */
0x0000fac5, 0x11f2fac9, /* 11f2fac9 //C 0fac5 jz	streq_no */
0x0000fac6, 0x010a0001, /* 010a0001 //C 0fac6 plus	r0,1		; non are EOS: go to check next char */
0x0000fac7, 0x011a0001, /* 011a0001 //C 0fac7 plus	r1,1 */
0x0000fac8, 0x01f2fab0, /* 01f2fab0 //C 0fac8 jmp	streq_cyc */
0x0000fac9, 0x020d0000, /* 020d0000 //C 0fac9 clc			; False result */
0x0000faca, 0x01f2facc, /* 01f2facc //C 0faca jmp	streq_ret */
0x0000facb, 0x020c0000, /* 020c0000 //C 0facb sec			; True result */
0x0000facc, 0x0f6d0000, /* 0f6d0000 //C 0facc pop	r6 */
0x0000facd, 0x0f5d0000, /* 0f5d0000 //C 0facd pop	r5 */
0x0000face, 0x0f4d0000, /* 0f4d0000 //C 0face pop	r4 */
0x0000facf, 0x0f2d0000, /* 0f2d0000 //C 0facf pop	r2 */
0x0000fad0, 0x0f1d0000, /* 0f1d0000 //C 0fad0 pop	r1 */
0x0000fad1, 0x0f0d0000, /* 0f0d0000 //C 0fad1 pop	r0 */
0x0000fad2, 0x0fed0000, /* 0fed0000 //C 0fad2 pop	lr */
0x0000fad3, 0x00f00e00, /* 00f00e00 //C 0fad3 ret */
0x0000fad4, 0x0ded0000, /* 0ded0000 //C 0fad4 push	lr */
0x0000fad5, 0x0d3d0000, /* 0d3d0000 //C 0fad5 push	r3 */
0x0000fad6, 0x01320001, /* 01320001 //C 0fad6 mvzl	r3,1 */
0x0000fad7, 0x0400faa9, /* 0400faa9 //C 0fad7 call	str_cmp_eq */
0x0000fad8, 0x0f3d0000, /* 0f3d0000 //C 0fad8 pop	r3 */
0x0000fad9, 0x0fed0000, /* 0fed0000 //C 0fad9 pop	lr */
0x0000fada, 0x00f00e00, /* 00f00e00 //C 0fada ret */
0x0000fadb, 0x0ded0000, /* 0ded0000 //C 0fadb push	lr */
0x0000fadc, 0x0d3d0000, /* 0d3d0000 //C 0fadc push	r3 */
0x0000fadd, 0x01320000, /* 01320000 //C 0fadd mvzl	r3,0 */
0x0000fade, 0x0400faa9, /* 0400faa9 //C 0fade call	str_cmp_eq */
0x0000fadf, 0x0f3d0000, /* 0f3d0000 //C 0fadf pop	r3 */
0x0000fae0, 0x0fed0000, /* 0fed0000 //C 0fae0 pop	lr */
0x0000fae1, 0x00f00e00, /* 00f00e00 //C 0fae1 ret */
0x0000fae2, 0x0108002f, /* 0108002f //C 0fae2 cmp	r0,'/' */
0x0000fae3, 0xa1f2faf8, /* a1f2faf8 //C 0fae3 LS jmp	hc2v_nok */
0x0000fae4, 0x01080039, /* 01080039 //C 0fae4 cmp	r0,'9' */
0x0000fae5, 0xa1f2faf5, /* a1f2faf5 //C 0fae5 LS jmp	hc2v_0_9 */
0x0000fae6, 0x01080040, /* 01080040 //C 0fae6 cmp	r0,'@' */
0x0000fae7, 0xa1f2faf8, /* a1f2faf8 //C 0fae7 LS jmp	hc2v_nok */
0x0000fae8, 0x01080046, /* 01080046 //C 0fae8 cmp	r0,'F' */
0x0000fae9, 0xa1f2faf2, /* a1f2faf2 //C 0fae9 LS jmp	hc2v_A_F */
0x0000faea, 0x01080060, /* 01080060 //C 0faea cmp	r0,'`' */
0x0000faeb, 0xa1f2faf8, /* a1f2faf8 //C 0faeb LS jmp	hc2v_nok */
0x0000faec, 0x01080066, /* 01080066 //C 0faec cmp	r0,'f' */
0x0000faed, 0xa1f2faef, /* a1f2faef //C 0faed LS jmp	hc2v_a_f */
0x0000faee, 0x01f2faf8, /* 01f2faf8 //C 0faee jmp	hc2v_nok */
0x0000faef, 0x0104000a, /* 0104000a //C 0faef add	r0,10 */
0x0000faf0, 0x01060061, /* 01060061 //C 0faf0 sub	r0,'a' */
0x0000faf1, 0x01f2faf6, /* 01f2faf6 //C 0faf1 jmp	hc2v_ok */
0x0000faf2, 0x0104000a, /* 0104000a //C 0faf2 add	r0,10 */
0x0000faf3, 0x01060041, /* 01060041 //C 0faf3 sub	r0,'A' */
0x0000faf4, 0x01f2faf6, /* 01f2faf6 //C 0faf4 jmp	hc2v_ok */
0x0000faf5, 0x01060030, /* 01060030 //C 0faf5 sub	r0,'0' */
0x0000faf6, 0x020c0000, /* 020c0000 //C 0faf6 sec */
0x0000faf7, 0x00f00e00, /* 00f00e00 //C 0faf7 ret */
0x0000faf8, 0x020d0000, /* 020d0000 //C 0faf8 clc */
0x0000faf9, 0x00f00e00, /* 00f00e00 //C 0faf9 ret */
0x0000fafa, 0x0d1d0000, /* 0d1d0000 //C 0fafa push	r1 */
0x0000fafb, 0x010f000f, /* 010f000f //C 0fafb and	r0,0xf */
0x0000fafc, 0x0112fb00, /* 0112fb00 //C 0fafc mvzl	r1,v2hc_table */
0x0000fafd, 0x0a010000, /* 0a010000 //C 0fafd ld	r0,r1,r0 */
0x0000fafe, 0x0f1d0000, /* 0f1d0000 //C 0fafe pop	r1 */
0x0000faff, 0x00f00e00, /* 00f00e00 //C 0faff ret */
0x0000fb00, 0x00000030, /* 00000030 //C 0fb00 db	48 */
0x0000fb01, 0x00000031, /* 00000031 //C 0fb01 db	49 */
0x0000fb02, 0x00000032, /* 00000032 //C 0fb02 db	50 */
0x0000fb03, 0x00000033, /* 00000033 //C 0fb03 db	51 */
0x0000fb04, 0x00000034, /* 00000034 //C 0fb04 db	52 */
0x0000fb05, 0x00000035, /* 00000035 //C 0fb05 db	53 */
0x0000fb06, 0x00000036, /* 00000036 //C 0fb06 db	54 */
0x0000fb07, 0x00000037, /* 00000037 //C 0fb07 db	55 */
0x0000fb08, 0x00000038, /* 00000038 //C 0fb08 db	56 */
0x0000fb09, 0x00000039, /* 00000039 //C 0fb09 db	57 */
0x0000fb0a, 0x00000041, /* 00000041 //C 0fb0a db	65 */
0x0000fb0b, 0x00000042, /* 00000042 //C 0fb0b db	66 */
0x0000fb0c, 0x00000043, /* 00000043 //C 0fb0c db	67 */
0x0000fb0d, 0x00000044, /* 00000044 //C 0fb0d db	68 */
0x0000fb0e, 0x00000045, /* 00000045 //C 0fb0e db	69 */
0x0000fb0f, 0x00000046, /* 00000046 //C 0fb0f db	70 */
0x0000fb10, 0x00000000, /* 00000000 //C 0fb10 db */
0x0000fb11, 0x0ded0000, /* 0ded0000 //C 0fb11 push	lr */
0x0000fb12, 0x0400fafa, /* 0400fafa //C 0fb12 call	value2Hexchar */
0x0000fb13, 0x010d0020, /* 010d0020 //C 0fb13 or	r0,0x20 */
0x0000fb14, 0x0fed0000, /* 0fed0000 //C 0fb14 pop	lr */
0x0000fb15, 0x00f00e00, /* 00f00e00 //C 0fb15 ret */
0x0000fb16, 0x0ded0000, /* 0ded0000 //C 0fb16 push	lr */
0x0000fb17, 0x0d2d0000, /* 0d2d0000 //C 0fb17 push	r2 */
0x0000fb18, 0x0d3d0000, /* 0d3d0000 //C 0fb18 push	r3 */
0x0000fb19, 0x01120000, /* 01120000 //C 0fb19 mvzl	r1,0		; return value */
0x0000fb1a, 0x01320000, /* 01320000 //C 0fb1a mvzl	r3,0		; index */
0x0000fb1b, 0x0b238000, /* 0b238000 //C 0fb1b ld	r2,r3+,r0	; pick a char */
0x0000fb1c, 0x022b0000, /* 022b0000 //C 0fb1c sz	r2		; check eof string */
0x0000fb1d, 0x11f2fb31, /* 11f2fb31 //C 0fb1d jz	htoi_eos */
0x0000fb1e, 0x0128002e, /* 0128002e //C 0fb1e cmp	r2,'.'		; skip separators */
0x0000fb1f, 0x11f2fb1b, /* 11f2fb1b //C 0fb1f jz	htoi_cyc */
0x0000fb20, 0x0128005f, /* 0128005f //C 0fb20 cmp	r2,'_' */
0x0000fb21, 0x11f2fb1b, /* 11f2fb1b //C 0fb21 jz	htoi_cyc */
0x0000fb22, 0x0d0d0000, /* 0d0d0000 //C 0fb22 push	r0 */
0x0000fb23, 0x00000200, /* 00000200 //C 0fb23 mov	r0,r2 */
0x0000fb24, 0x0400fae2, /* 0400fae2 //C 0fb24 call	hexchar2value */
0x0000fb25, 0x00200000, /* 00200000 //C 0fb25 mov	r2,r0 */
0x0000fb26, 0x0f0d0000, /* 0f0d0000 //C 0fb26 pop	r0 */
0x0000fb27, 0x41f2fb2f, /* 41f2fb2f //C 0fb27 C0 jmp	htoi_nok */
0x0000fb28, 0x02180000, /* 02180000 //C 0fb28 shl	r1 */
0x0000fb29, 0x02180000, /* 02180000 //C 0fb29 shl	r1 */
0x0000fb2a, 0x02180000, /* 02180000 //C 0fb2a shl	r1 */
0x0000fb2b, 0x02180000, /* 02180000 //C 0fb2b shl	r1 */
0x0000fb2c, 0x012f000f, /* 012f000f //C 0fb2c and	r2,0xf */
0x0000fb2d, 0x001d0200, /* 001d0200 //C 0fb2d or	r1,r2 */
0x0000fb2e, 0x01f2fb1b, /* 01f2fb1b //C 0fb2e jmp	htoi_cyc */
0x0000fb2f, 0x020d0000, /* 020d0000 //C 0fb2f clc */
0x0000fb30, 0x01f2fb34, /* 01f2fb34 //C 0fb30 jmp	htoi_ret */
0x0000fb31, 0x01380001, /* 01380001 //C 0fb31 cmp	r3,1 */
0x0000fb32, 0x920d0000, /* 920d0000 //C 0fb32 HI clc */
0x0000fb33, 0xa20c0000, /* a20c0000 //C 0fb33 LS sec */
0x0000fb34, 0x0f3d0000, /* 0f3d0000 //C 0fb34 pop	r3 */
0x0000fb35, 0x0f2d0000, /* 0f2d0000 //C 0fb35 pop	r2 */
0x0000fb36, 0x0fed0000, /* 0fed0000 //C 0fb36 pop	lr */
0x0000fb37, 0x00f00e00, /* 00f00e00 //C 0fb37 ret */
0x0000fb38, 0x0d0d0000, /* 0d0d0000 //C 0fb38 push	r0 */
0x0000fb39, 0x0700ff42, /* 0700ff42 //C 0fb39 ld	r0,UART_RSTAT */
0x0000fb3a, 0x010c0001, /* 010c0001 //C 0fb3a test	r0,1 */
0x0000fb3b, 0x020d0000, /* 020d0000 //C 0fb3b clc */
0x0000fb3c, 0x220c0000, /* 220c0000 //C 0fb3c Z0 sec */
0x0000fb3d, 0x0f0d0000, /* 0f0d0000 //C 0fb3d pop	r0 */
0x0000fb3e, 0x00f00e00, /* 00f00e00 //C 0fb3e ret */
0x0000fb3f, 0x0700ff40, /* 0700ff40 //C 0fb3f ld	r0,UART_DR */
0x0000fb40, 0x00f00e00, /* 00f00e00 //C 0fb40 ret */
0x0000fb41, 0x0d9d0000, /* 0d9d0000 //C 0fb41 push	r9 */
0x0000fb42, 0x0790ff43, /* 0790ff43 //C 0fb42 ld	r9,UART_TSTAT */
0x0000fb43, 0x019c0001, /* 019c0001 //C 0fb43 test	r9,1 */
0x0000fb44, 0x11f2fb42, /* 11f2fb42 //C 0fb44 jz	wait_tc */
0x0000fb45, 0x0600ff40, /* 0600ff40 //C 0fb45 st	r0,UART_DR */
0x0000fb46, 0x0f9d0000, /* 0f9d0000 //C 0fb46 pop	r9 */
0x0000fb47, 0x00f00e00, /* 00f00e00 //C 0fb47 ret */
0x0000fb48, 0x0ded0000, /* 0ded0000 //C 0fb48 push	lr */
0x0000fb49, 0x0d0d0000, /* 0d0d0000 //C 0fb49 push	r0 */
0x0000fb4a, 0x0d3d0000, /* 0d3d0000 //C 0fb4a push	r3 */
0x0000fb4b, 0x0d4d0000, /* 0d4d0000 //C 0fb4b push	r4 */
0x0000fb4c, 0x01420000, /* 01420000 //C 0fb4c mvzl	r4,0 */
0x0000fb4d, 0x020b0000, /* 020b0000 //C 0fb4d sz	r0 */
0x0000fb4e, 0x1102fc22, /* 1102fc22 //C 0fb4e Z1 mvzl	r0,null_str */
0x0000fb4f, 0x0b348000, /* 0b348000 //C 0fb4f ld	r3,r4+,r0 */
0x0000fb50, 0x023b0000, /* 023b0000 //C 0fb50 sz	r3 */
0x0000fb51, 0x11f2fb57, /* 11f2fb57 //C 0fb51 jz	prints_done */
0x0000fb52, 0x0d0d0000, /* 0d0d0000 //C 0fb52 push	r0 */
0x0000fb53, 0x00000300, /* 00000300 //C 0fb53 mov	r0,r3 */
0x0000fb54, 0x0400fb41, /* 0400fb41 //C 0fb54 call	putchar */
0x0000fb55, 0x0f0d0000, /* 0f0d0000 //C 0fb55 pop	r0 */
0x0000fb56, 0x01f2fb4f, /* 01f2fb4f //C 0fb56 jmp	prints_go */
0x0000fb57, 0x0f4d0000, /* 0f4d0000 //C 0fb57 pop	r4 */
0x0000fb58, 0x0f3d0000, /* 0f3d0000 //C 0fb58 pop	r3 */
0x0000fb59, 0x0f0d0000, /* 0f0d0000 //C 0fb59 pop	r0 */
0x0000fb5a, 0x0fed0000, /* 0fed0000 //C 0fb5a pop	lr */
0x0000fb5b, 0x00f00e00, /* 00f00e00 //C 0fb5b ret */
0x0000fb5c, 0x0ded0000, /* 0ded0000 //C 0fb5c push	lr */
0x0000fb5d, 0x0400fb48, /* 0400fb48 //C 0fb5d call	prints */
0x0000fb5e, 0x0d0d0000, /* 0d0d0000 //C 0fb5e push	r0 */
0x0000fb5f, 0x0102000a, /* 0102000a //C 0fb5f mvzl	r0,LF */
0x0000fb60, 0x0400fb41, /* 0400fb41 //C 0fb60 call	putchar */
0x0000fb61, 0x0f0d0000, /* 0f0d0000 //C 0fb61 pop	r0 */
0x0000fb62, 0x0fed0000, /* 0fed0000 //C 0fb62 pop	lr */
0x0000fb63, 0x00f00e00, /* 00f00e00 //C 0fb63 ret */
0x0000fb64, 0x0ded0000, /* 0ded0000 //C 0fb64 push	lr */
0x0000fb65, 0x0d0d0000, /* 0d0d0000 //C 0fb65 push	r0 */
0x0000fb66, 0x0d1d0000, /* 0d1d0000 //C 0fb66 push	r1 */
0x0000fb67, 0x0d2d0000, /* 0d2d0000 //C 0fb67 push	r2 */
0x0000fb68, 0x0d3d0000, /* 0d3d0000 //C 0fb68 push	r3 */
0x0000fb69, 0x0d4d0000, /* 0d4d0000 //C 0fb69 push	r4 */
0x0000fb6a, 0x00300000, /* 00300000 //C 0fb6a mov	r3,r0 */
0x0000fb6b, 0x01220000, /* 01220000 //C 0fb6b mvzl	r2,0 */
0x0000fb6c, 0x01420001, /* 01420001 //C 0fb6c mvzl	r4,1 */
0x0000fb6d, 0x01020000, /* 01020000 //C 0fb6d mvzl	r0,0 */
0x0000fb6e, 0x02380000, /* 02380000 //C 0fb6e shl	r3 */
0x0000fb6f, 0x02070000, /* 02070000 //C 0fb6f rol	r0 */
0x0000fb70, 0x02380000, /* 02380000 //C 0fb70 shl	r3 */
0x0000fb71, 0x02070000, /* 02070000 //C 0fb71 rol	r0 */
0x0000fb72, 0x02380000, /* 02380000 //C 0fb72 shl	r3 */
0x0000fb73, 0x02070000, /* 02070000 //C 0fb73 rol	r0 */
0x0000fb74, 0x02380000, /* 02380000 //C 0fb74 shl	r3 */
0x0000fb75, 0x02070000, /* 02070000 //C 0fb75 rol	r0 */
0x0000fb76, 0x0400fafa, /* 0400fafa //C 0fb76 call	value2Hexchar */
0x0000fb77, 0x0400fb41, /* 0400fb41 //C 0fb77 call	putchar */
0x0000fb78, 0x01240001, /* 01240001 //C 0fb78 add	r2,1 */
0x0000fb79, 0x01280008, /* 01280008 //C 0fb79 cmp	r2,8 */
0x0000fb7a, 0x11f2fb84, /* 11f2fb84 //C 0fb7a jz	print_vhex_ret */
0x0000fb7b, 0x021b0000, /* 021b0000 //C 0fb7b sz	r1 */
0x0000fb7c, 0x11f2fb82, /* 11f2fb82 //C 0fb7c jz	print_vhex_nosep */
0x0000fb7d, 0x00480100, /* 00480100 //C 0fb7d cmp	r4,r1 */
0x0000fb7e, 0x21f2fb82, /* 21f2fb82 //C 0fb7e jnz	print_vhex_nosep */
0x0000fb7f, 0x0102005f, /* 0102005f //C 0fb7f mvzl	r0,'_' */
0x0000fb80, 0x0400fb41, /* 0400fb41 //C 0fb80 call	putchar */
0x0000fb81, 0x01420000, /* 01420000 //C 0fb81 mvzl	r4,0 */
0x0000fb82, 0x01440001, /* 01440001 //C 0fb82 add	r4,1 */
0x0000fb83, 0x01f2fb6d, /* 01f2fb6d //C 0fb83 jmp	print_vhex_cyc */
0x0000fb84, 0x0f4d0000, /* 0f4d0000 //C 0fb84 pop	r4 */
0x0000fb85, 0x0f3d0000, /* 0f3d0000 //C 0fb85 pop	r3 */
0x0000fb86, 0x0f2d0000, /* 0f2d0000 //C 0fb86 pop	r2 */
0x0000fb87, 0x0f1d0000, /* 0f1d0000 //C 0fb87 pop	r1 */
0x0000fb88, 0x0f0d0000, /* 0f0d0000 //C 0fb88 pop	r0 */
0x0000fb89, 0x0fed0000, /* 0fed0000 //C 0fb89 pop	lr */
0x0000fb8a, 0x00f00e00, /* 00f00e00 //C 0fb8a ret */
0x0000fbf7, 0x00000000, /* 00000000 //C 0fbf7 dd	0 */
0x0000fbf8, 0x00000000, /* 00000000 //C 0fbf8 dd	0 */
0x0000fbf9, 0x00000000, /* 00000000 //C 0fbf9 dd	0 */
0x0000fbfa, 0x00000000, /* 00000000 //C 0fbfa dd	0 */
0x0000fbfb, 0x00000000, /* 00000000 //C 0fbfb dd	0 */
0x0000fbfc, 0x00000000, /* 00000000 //C 0fbfc dd	0 */
0x0000fbfd, 0x00000000, /* 00000000 //C 0fbfd dd	0 */
0x0000fbfe, 0x00000000, /* 00000000 //C 0fbfe dd	0 */
0x0000fbff, 0x00000000, /* 00000000 //C 0fbff dd	0 */
0x0000fc00, 0x00000000, /* 00000000 //C 0fc00 dd	0 */
0x0000fc01, 0x00000000, /* 00000000 //C 0fc01 dd	0 */
0x0000fc02, 0x00000000, /* 00000000 //C 0fc02 dd	0 */
0x0000fc03, 0x00000000, /* 00000000 //C 0fc03 dd	0 */
0x0000fc04, 0x00000000, /* 00000000 //C 0fc04 dd	0 */
0x0000fc05, 0x00000000, /* 00000000 //C 0fc05 dd	0 */
0x0000fc06, 0x00000000, /* 00000000 //C 0fc06 dd	0 */
0x0000fc07, 0x00000000, /* 00000000 //C 0fc07 dd	0 */
0x0000fc08, 0x00000000, /* 00000000 //C 0fc08 dd	0 */
0x0000fc09, 0x00000050, /* 00000050 //C 0fc09 db	80 */
0x0000fc0a, 0x0000004d, /* 0000004d //C 0fc0a db	77 */
0x0000fc0b, 0x0000006f, /* 0000006f //C 0fc0b db	111 */
0x0000fc0c, 0x0000006e, /* 0000006e //C 0fc0c db	110 */
0x0000fc0d, 0x00000069, /* 00000069 //C 0fc0d db	105 */
0x0000fc0e, 0x00000074, /* 00000074 //C 0fc0e db	116 */
0x0000fc0f, 0x0000006f, /* 0000006f //C 0fc0f db	111 */
0x0000fc10, 0x00000072, /* 00000072 //C 0fc10 db	114 */
0x0000fc11, 0x00000020, /* 00000020 //C 0fc11 db	32 */
0x0000fc12, 0x00000076, /* 00000076 //C 0fc12 db	118 */
0x0000fc13, 0x00000031, /* 00000031 //C 0fc13 db	49 */
0x0000fc14, 0x0000002e, /* 0000002e //C 0fc14 db	46 */
0x0000fc15, 0x00000030, /* 00000030 //C 0fc15 db	48 */
0x0000fc16, 0x00000000, /* 00000000 //C 0fc16 db */
0x0000fc17, 0x0000003e, /* 0000003e //C 0fc17 db	62 */
0x0000fc18, 0x00000000, /* 00000000 //C 0fc18 db */
0x0000fc19, 0x00000020, /* 00000020 //C 0fc19 db	32 */
0x0000fc1a, 0x0000003b, /* 0000003b //C 0fc1a db	59 */
0x0000fc1b, 0x00000009, /* 00000009 //C 0fc1b db	9 */
0x0000fc1c, 0x0000000b, /* 0000000b //C 0fc1c db	11 */
0x0000fc1d, 0x0000002c, /* 0000002c //C 0fc1d db	44 */
0x0000fc1e, 0x0000003d, /* 0000003d //C 0fc1e db	61 */
0x0000fc1f, 0x0000005b, /* 0000005b //C 0fc1f db	91 */
0x0000fc20, 0x0000005d, /* 0000005d //C 0fc20 db	93 */
0x0000fc21, 0x00000000, /* 00000000 //C 0fc21 db */
0x0000fc22, 0x00000028, /* 00000028 //C 0fc22 db	40 */
0x0000fc23, 0x0000006e, /* 0000006e //C 0fc23 db	110 */
0x0000fc24, 0x00000075, /* 00000075 //C 0fc24 db	117 */
0x0000fc25, 0x0000006c, /* 0000006c //C 0fc25 db	108 */
0x0000fc26, 0x0000006c, /* 0000006c //C 0fc26 db	108 */
0x0000fc27, 0x00000029, /* 00000029 //C 0fc27 db	41 */
0x0000fc28, 0x00000000, /* 00000000 //C 0fc28 db */
0x0000fc29, 0x0000f8e1, /* 0000f8e1 //C 0fc29 dd	cmd_m */
0x0000fc2a, 0x0000006d, /* 0000006d //C 0fc2a db	109 */
0x0000fc2b, 0x00000000, /* 00000000 //C 0fc2b db */
0x0000fc2c, 0x0000f8e1, /* 0000f8e1 //C 0fc2c dd	cmd_m */
0x0000fc2d, 0x0000006d, /* 0000006d //C 0fc2d db	109 */
0x0000fc2e, 0x00000065, /* 00000065 //C 0fc2e db	101 */
0x0000fc2f, 0x0000006d, /* 0000006d //C 0fc2f db	109 */
0x0000fc30, 0x00000000, /* 00000000 //C 0fc30 db */
0x0000fc31, 0x0000f936, /* 0000f936 //C 0fc31 dd	cmd_d */
0x0000fc32, 0x00000064, /* 00000064 //C 0fc32 db	100 */
0x0000fc33, 0x00000000, /* 00000000 //C 0fc33 db */
0x0000fc34, 0x0000f936, /* 0000f936 //C 0fc34 dd	cmd_d */
0x0000fc35, 0x00000064, /* 00000064 //C 0fc35 db	100 */
0x0000fc36, 0x00000075, /* 00000075 //C 0fc36 db	117 */
0x0000fc37, 0x0000006d, /* 0000006d //C 0fc37 db	109 */
0x0000fc38, 0x00000070, /* 00000070 //C 0fc38 db	112 */
0x0000fc39, 0x00000000, /* 00000000 //C 0fc39 db */
0x0000fc3a, 0x0000f969, /* 0000f969 //C 0fc3a dd	cmd_e */
0x0000fc3b, 0x00000065, /* 00000065 //C 0fc3b db	101 */
0x0000fc3c, 0x00000000, /* 00000000 //C 0fc3c db */
0x0000fc3d, 0x0000f96b, /* 0000f96b //C 0fc3d dd	cmd_l */
0x0000fc3e, 0x0000006c, /* 0000006c //C 0fc3e db	108 */
0x0000fc3f, 0x00000000, /* 00000000 //C 0fc3f db */
0x0000fc40, 0x0000f96b, /* 0000f96b //C 0fc40 dd	cmd_l */
0x0000fc41, 0x0000006c, /* 0000006c //C 0fc41 db	108 */
0x0000fc42, 0x0000006f, /* 0000006f //C 0fc42 db	111 */
0x0000fc43, 0x00000061, /* 00000061 //C 0fc43 db	97 */
0x0000fc44, 0x00000064, /* 00000064 //C 0fc44 db	100 */
0x0000fc45, 0x00000000, /* 00000000 //C 0fc45 db */
0x0000fc46, 0x0000f9d8, /* 0000f9d8 //C 0fc46 dd	cmd_g */
0x0000fc47, 0x00000067, /* 00000067 //C 0fc47 db	103 */
0x0000fc48, 0x00000000, /* 00000000 //C 0fc48 db */
0x0000fc49, 0x0000f9d8, /* 0000f9d8 //C 0fc49 dd	cmd_g */
0x0000fc4a, 0x00000067, /* 00000067 //C 0fc4a db	103 */
0x0000fc4b, 0x0000006f, /* 0000006f //C 0fc4b db	111 */
0x0000fc4c, 0x00000000, /* 00000000 //C 0fc4c db */
0x0000fc4d, 0x0000f9d8, /* 0000f9d8 //C 0fc4d dd	cmd_g */
0x0000fc4e, 0x00000072, /* 00000072 //C 0fc4e db	114 */
0x0000fc4f, 0x00000075, /* 00000075 //C 0fc4f db	117 */
0x0000fc50, 0x0000006e, /* 0000006e //C 0fc50 db	110 */
0x0000fc51, 0x00000000, /* 00000000 //C 0fc51 db */
0x0000fc52, 0x0000fa18, /* 0000fa18 //C 0fc52 dd	cmd_h */
0x0000fc53, 0x0000003f, /* 0000003f //C 0fc53 db	63 */
0x0000fc54, 0x00000000, /* 00000000 //C 0fc54 db */
0x0000fc55, 0x0000fa18, /* 0000fa18 //C 0fc55 dd	cmd_h */
0x0000fc56, 0x00000068, /* 00000068 //C 0fc56 db	104 */
0x0000fc57, 0x00000000, /* 00000000 //C 0fc57 db */
0x0000fc58, 0x0000fa18, /* 0000fa18 //C 0fc58 dd	cmd_h */
0x0000fc59, 0x00000068, /* 00000068 //C 0fc59 db	104 */
0x0000fc5a, 0x00000065, /* 00000065 //C 0fc5a db	101 */
0x0000fc5b, 0x0000006c, /* 0000006c //C 0fc5b db	108 */
0x0000fc5c, 0x00000070, /* 00000070 //C 0fc5c db	112 */
0x0000fc5d, 0x00000000, /* 00000000 //C 0fc5d db */
0x0000fc5e, 0x0000fa75, /* 0000fa75 //C 0fc5e dd	cmd_r */
0x0000fc5f, 0x00000072, /* 00000072 //C 0fc5f db	114 */
0x0000fc60, 0x00000000, /* 00000000 //C 0fc60 db */
0x0000fc61, 0x0000fa75, /* 0000fa75 //C 0fc61 dd	cmd_r */
0x0000fc62, 0x00000072, /* 00000072 //C 0fc62 db	114 */
0x0000fc63, 0x00000065, /* 00000065 //C 0fc63 db	101 */
0x0000fc64, 0x00000067, /* 00000067 //C 0fc64 db	103 */
0x0000fc65, 0x00000000, /* 00000000 //C 0fc65 db */
0x0000fc66, 0x0000fa75, /* 0000fa75 //C 0fc66 dd	cmd_r */
0x0000fc67, 0x00000072, /* 00000072 //C 0fc67 db	114 */
0x0000fc68, 0x00000065, /* 00000065 //C 0fc68 db	101 */
0x0000fc69, 0x00000067, /* 00000067 //C 0fc69 db	103 */
0x0000fc6a, 0x00000073, /* 00000073 //C 0fc6a db	115 */
0x0000fc6b, 0x00000000, /* 00000000 //C 0fc6b db */
0x0000fc6c, 0x00000000, /* 00000000 //C 0fc6c dd	0 */
0x0000fc6d, 0x00000000, /* 00000000 //C 0fc6d dd	0 */
0x0000fc6e, 0x0000006d, /* 0000006d //C 0fc6e db	109 */
0x0000fc6f, 0x0000005b, /* 0000005b //C 0fc6f db	91 */
0x0000fc70, 0x00000065, /* 00000065 //C 0fc70 db	101 */
0x0000fc71, 0x0000006d, /* 0000006d //C 0fc71 db	109 */
0x0000fc72, 0x0000005d, /* 0000005d //C 0fc72 db	93 */
0x0000fc73, 0x00000020, /* 00000020 //C 0fc73 db	32 */
0x0000fc74, 0x00000020, /* 00000020 //C 0fc74 db	32 */
0x0000fc75, 0x00000061, /* 00000061 //C 0fc75 db	97 */
0x0000fc76, 0x00000064, /* 00000064 //C 0fc76 db	100 */
0x0000fc77, 0x00000064, /* 00000064 //C 0fc77 db	100 */
0x0000fc78, 0x00000072, /* 00000072 //C 0fc78 db	114 */
0x0000fc79, 0x00000020, /* 00000020 //C 0fc79 db	32 */
0x0000fc7a, 0x0000005b, /* 0000005b //C 0fc7a db	91 */
0x0000fc7b, 0x00000076, /* 00000076 //C 0fc7b db	118 */
0x0000fc7c, 0x00000061, /* 00000061 //C 0fc7c db	97 */
0x0000fc7d, 0x0000006c, /* 0000006c //C 0fc7d db	108 */
0x0000fc7e, 0x00000075, /* 00000075 //C 0fc7e db	117 */
0x0000fc7f, 0x00000065, /* 00000065 //C 0fc7f db	101 */
0x0000fc80, 0x0000005d, /* 0000005d //C 0fc80 db	93 */
0x0000fc81, 0x00000020, /* 00000020 //C 0fc81 db	32 */
0x0000fc82, 0x00000020, /* 00000020 //C 0fc82 db	32 */
0x0000fc83, 0x00000047, /* 00000047 //C 0fc83 db	71 */
0x0000fc84, 0x00000065, /* 00000065 //C 0fc84 db	101 */
0x0000fc85, 0x00000074, /* 00000074 //C 0fc85 db	116 */
0x0000fc86, 0x0000002f, /* 0000002f //C 0fc86 db	47 */
0x0000fc87, 0x00000073, /* 00000073 //C 0fc87 db	115 */
0x0000fc88, 0x00000065, /* 00000065 //C 0fc88 db	101 */
0x0000fc89, 0x00000074, /* 00000074 //C 0fc89 db	116 */
0x0000fc8a, 0x00000020, /* 00000020 //C 0fc8a db	32 */
0x0000fc8b, 0x0000006d, /* 0000006d //C 0fc8b db	109 */
0x0000fc8c, 0x00000065, /* 00000065 //C 0fc8c db	101 */
0x0000fc8d, 0x0000006d, /* 0000006d //C 0fc8d db	109 */
0x0000fc8e, 0x0000006f, /* 0000006f //C 0fc8e db	111 */
0x0000fc8f, 0x00000072, /* 00000072 //C 0fc8f db	114 */
0x0000fc90, 0x00000079, /* 00000079 //C 0fc90 db	121 */
0x0000fc91, 0x0000000a, /* 0000000a //C 0fc91 db	10 */
0x0000fc92, 0x00000000, /* 00000000 //C 0fc92 db */
0x0000fc93, 0x00000064, /* 00000064 //C 0fc93 db	100 */
0x0000fc94, 0x0000005b, /* 0000005b //C 0fc94 db	91 */
0x0000fc95, 0x00000075, /* 00000075 //C 0fc95 db	117 */
0x0000fc96, 0x0000006d, /* 0000006d //C 0fc96 db	109 */
0x0000fc97, 0x00000070, /* 00000070 //C 0fc97 db	112 */
0x0000fc98, 0x0000005d, /* 0000005d //C 0fc98 db	93 */
0x0000fc99, 0x00000020, /* 00000020 //C 0fc99 db	32 */
0x0000fc9a, 0x00000073, /* 00000073 //C 0fc9a db	115 */
0x0000fc9b, 0x00000074, /* 00000074 //C 0fc9b db	116 */
0x0000fc9c, 0x00000061, /* 00000061 //C 0fc9c db	97 */
0x0000fc9d, 0x00000072, /* 00000072 //C 0fc9d db	114 */
0x0000fc9e, 0x00000074, /* 00000074 //C 0fc9e db	116 */
0x0000fc9f, 0x00000020, /* 00000020 //C 0fc9f db	32 */
0x0000fca0, 0x00000065, /* 00000065 //C 0fca0 db	101 */
0x0000fca1, 0x0000006e, /* 0000006e //C 0fca1 db	110 */
0x0000fca2, 0x00000064, /* 00000064 //C 0fca2 db	100 */
0x0000fca3, 0x00000020, /* 00000020 //C 0fca3 db	32 */
0x0000fca4, 0x00000020, /* 00000020 //C 0fca4 db	32 */
0x0000fca5, 0x00000020, /* 00000020 //C 0fca5 db	32 */
0x0000fca6, 0x00000020, /* 00000020 //C 0fca6 db	32 */
0x0000fca7, 0x00000020, /* 00000020 //C 0fca7 db	32 */
0x0000fca8, 0x00000044, /* 00000044 //C 0fca8 db	68 */
0x0000fca9, 0x00000075, /* 00000075 //C 0fca9 db	117 */
0x0000fcaa, 0x0000006d, /* 0000006d //C 0fcaa db	109 */
0x0000fcab, 0x00000070, /* 00000070 //C 0fcab db	112 */
0x0000fcac, 0x00000020, /* 00000020 //C 0fcac db	32 */
0x0000fcad, 0x0000006d, /* 0000006d //C 0fcad db	109 */
0x0000fcae, 0x00000065, /* 00000065 //C 0fcae db	101 */
0x0000fcaf, 0x0000006d, /* 0000006d //C 0fcaf db	109 */
0x0000fcb0, 0x0000006f, /* 0000006f //C 0fcb0 db	111 */
0x0000fcb1, 0x00000072, /* 00000072 //C 0fcb1 db	114 */
0x0000fcb2, 0x00000079, /* 00000079 //C 0fcb2 db	121 */
0x0000fcb3, 0x00000020, /* 00000020 //C 0fcb3 db	32 */
0x0000fcb4, 0x00000063, /* 00000063 //C 0fcb4 db	99 */
0x0000fcb5, 0x0000006f, /* 0000006f //C 0fcb5 db	111 */
0x0000fcb6, 0x0000006e, /* 0000006e //C 0fcb6 db	110 */
0x0000fcb7, 0x00000074, /* 00000074 //C 0fcb7 db	116 */
0x0000fcb8, 0x00000065, /* 00000065 //C 0fcb8 db	101 */
0x0000fcb9, 0x0000006e, /* 0000006e //C 0fcb9 db	110 */
0x0000fcba, 0x00000074, /* 00000074 //C 0fcba db	116 */
0x0000fcbb, 0x0000000a, /* 0000000a //C 0fcbb db	10 */
0x0000fcbc, 0x00000000, /* 00000000 //C 0fcbc db */
0x0000fcbd, 0x00000065, /* 00000065 //C 0fcbd db	101 */
0x0000fcbe, 0x0000000a, /* 0000000a //C 0fcbe db	10 */
0x0000fcbf, 0x00000000, /* 00000000 //C 0fcbf db */
0x0000fcc0, 0x0000006c, /* 0000006c //C 0fcc0 db	108 */
0x0000fcc1, 0x0000005b, /* 0000005b //C 0fcc1 db	91 */
0x0000fcc2, 0x0000006f, /* 0000006f //C 0fcc2 db	111 */
0x0000fcc3, 0x00000061, /* 00000061 //C 0fcc3 db	97 */
0x0000fcc4, 0x00000064, /* 00000064 //C 0fcc4 db	100 */
0x0000fcc5, 0x0000005d, /* 0000005d //C 0fcc5 db	93 */
0x0000fcc6, 0x00000020, /* 00000020 //C 0fcc6 db	32 */
0x0000fcc7, 0x00000020, /* 00000020 //C 0fcc7 db	32 */
0x0000fcc8, 0x00000020, /* 00000020 //C 0fcc8 db	32 */
0x0000fcc9, 0x00000020, /* 00000020 //C 0fcc9 db	32 */
0x0000fcca, 0x00000020, /* 00000020 //C 0fcca db	32 */
0x0000fccb, 0x00000020, /* 00000020 //C 0fccb db	32 */
0x0000fccc, 0x00000020, /* 00000020 //C 0fccc db	32 */
0x0000fccd, 0x00000020, /* 00000020 //C 0fccd db	32 */
0x0000fcce, 0x00000020, /* 00000020 //C 0fcce db	32 */
0x0000fccf, 0x00000020, /* 00000020 //C 0fccf db	32 */
0x0000fcd0, 0x00000020, /* 00000020 //C 0fcd0 db	32 */
0x0000fcd1, 0x00000020, /* 00000020 //C 0fcd1 db	32 */
0x0000fcd2, 0x00000020, /* 00000020 //C 0fcd2 db	32 */
0x0000fcd3, 0x00000020, /* 00000020 //C 0fcd3 db	32 */
0x0000fcd4, 0x00000020, /* 00000020 //C 0fcd4 db	32 */
0x0000fcd5, 0x0000004c, /* 0000004c //C 0fcd5 db	76 */
0x0000fcd6, 0x0000006f, /* 0000006f //C 0fcd6 db	111 */
0x0000fcd7, 0x00000061, /* 00000061 //C 0fcd7 db	97 */
0x0000fcd8, 0x00000064, /* 00000064 //C 0fcd8 db	100 */
0x0000fcd9, 0x00000020, /* 00000020 //C 0fcd9 db	32 */
0x0000fcda, 0x00000068, /* 00000068 //C 0fcda db	104 */
0x0000fcdb, 0x00000065, /* 00000065 //C 0fcdb db	101 */
0x0000fcdc, 0x00000078, /* 00000078 //C 0fcdc db	120 */
0x0000fcdd, 0x00000020, /* 00000020 //C 0fcdd db	32 */
0x0000fcde, 0x00000066, /* 00000066 //C 0fcde db	102 */
0x0000fcdf, 0x00000069, /* 00000069 //C 0fcdf db	105 */
0x0000fce0, 0x0000006c, /* 0000006c //C 0fce0 db	108 */
0x0000fce1, 0x00000065, /* 00000065 //C 0fce1 db	101 */
0x0000fce2, 0x00000020, /* 00000020 //C 0fce2 db	32 */
0x0000fce3, 0x00000074, /* 00000074 //C 0fce3 db	116 */
0x0000fce4, 0x0000006f, /* 0000006f //C 0fce4 db	111 */
0x0000fce5, 0x00000020, /* 00000020 //C 0fce5 db	32 */
0x0000fce6, 0x0000006d, /* 0000006d //C 0fce6 db	109 */
0x0000fce7, 0x00000065, /* 00000065 //C 0fce7 db	101 */
0x0000fce8, 0x0000006d, /* 0000006d //C 0fce8 db	109 */
0x0000fce9, 0x0000006f, /* 0000006f //C 0fce9 db	111 */
0x0000fcea, 0x00000072, /* 00000072 //C 0fcea db	114 */
0x0000fceb, 0x00000079, /* 00000079 //C 0fceb db	121 */
0x0000fcec, 0x0000000a, /* 0000000a //C 0fcec db	10 */
0x0000fced, 0x00000000, /* 00000000 //C 0fced db */
0x0000fcee, 0x00000067, /* 00000067 //C 0fcee db	103 */
0x0000fcef, 0x00000028, /* 00000028 //C 0fcef db	40 */
0x0000fcf0, 0x0000006f, /* 0000006f //C 0fcf0 db	111 */
0x0000fcf1, 0x00000029, /* 00000029 //C 0fcf1 db	41 */
0x0000fcf2, 0x0000007c, /* 0000007c //C 0fcf2 db	124 */
0x0000fcf3, 0x00000072, /* 00000072 //C 0fcf3 db	114 */
0x0000fcf4, 0x00000075, /* 00000075 //C 0fcf4 db	117 */
0x0000fcf5, 0x0000006e, /* 0000006e //C 0fcf5 db	110 */
0x0000fcf6, 0x00000020, /* 00000020 //C 0fcf6 db	32 */
0x0000fcf7, 0x00000061, /* 00000061 //C 0fcf7 db	97 */
0x0000fcf8, 0x00000064, /* 00000064 //C 0fcf8 db	100 */
0x0000fcf9, 0x00000064, /* 00000064 //C 0fcf9 db	100 */
0x0000fcfa, 0x00000072, /* 00000072 //C 0fcfa db	114 */
0x0000fcfb, 0x00000020, /* 00000020 //C 0fcfb db	32 */
0x0000fcfc, 0x00000020, /* 00000020 //C 0fcfc db	32 */
0x0000fcfd, 0x00000020, /* 00000020 //C 0fcfd db	32 */
0x0000fcfe, 0x00000020, /* 00000020 //C 0fcfe db	32 */
0x0000fcff, 0x00000020, /* 00000020 //C 0fcff db	32 */
0x0000fd00, 0x00000020, /* 00000020 //C 0fd00 db	32 */
0x0000fd01, 0x00000020, /* 00000020 //C 0fd01 db	32 */
0x0000fd02, 0x00000020, /* 00000020 //C 0fd02 db	32 */
0x0000fd03, 0x00000052, /* 00000052 //C 0fd03 db	82 */
0x0000fd04, 0x00000075, /* 00000075 //C 0fd04 db	117 */
0x0000fd05, 0x0000006e, /* 0000006e //C 0fd05 db	110 */
0x0000fd06, 0x00000020, /* 00000020 //C 0fd06 db	32 */
0x0000fd07, 0x00000066, /* 00000066 //C 0fd07 db	102 */
0x0000fd08, 0x00000072, /* 00000072 //C 0fd08 db	114 */
0x0000fd09, 0x0000006f, /* 0000006f //C 0fd09 db	111 */
0x0000fd0a, 0x0000006d, /* 0000006d //C 0fd0a db	109 */
0x0000fd0b, 0x00000020, /* 00000020 //C 0fd0b db	32 */
0x0000fd0c, 0x00000061, /* 00000061 //C 0fd0c db	97 */
0x0000fd0d, 0x00000064, /* 00000064 //C 0fd0d db	100 */
0x0000fd0e, 0x00000064, /* 00000064 //C 0fd0e db	100 */
0x0000fd0f, 0x00000072, /* 00000072 //C 0fd0f db	114 */
0x0000fd10, 0x00000065, /* 00000065 //C 0fd10 db	101 */
0x0000fd11, 0x00000073, /* 00000073 //C 0fd11 db	115 */
0x0000fd12, 0x00000073, /* 00000073 //C 0fd12 db	115 */
0x0000fd13, 0x0000000a, /* 0000000a //C 0fd13 db	10 */
0x0000fd14, 0x00000000, /* 00000000 //C 0fd14 db */
0x0000fd15, 0x00000072, /* 00000072 //C 0fd15 db	114 */
0x0000fd16, 0x0000005b, /* 0000005b //C 0fd16 db	91 */
0x0000fd17, 0x00000065, /* 00000065 //C 0fd17 db	101 */
0x0000fd18, 0x00000067, /* 00000067 //C 0fd18 db	103 */
0x0000fd19, 0x0000005b, /* 0000005b //C 0fd19 db	91 */
0x0000fd1a, 0x00000073, /* 00000073 //C 0fd1a db	115 */
0x0000fd1b, 0x0000005d, /* 0000005d //C 0fd1b db	93 */
0x0000fd1c, 0x0000005d, /* 0000005d //C 0fd1c db	93 */
0x0000fd1d, 0x00000020, /* 00000020 //C 0fd1d db	32 */
0x0000fd1e, 0x00000020, /* 00000020 //C 0fd1e db	32 */
0x0000fd1f, 0x00000020, /* 00000020 //C 0fd1f db	32 */
0x0000fd20, 0x00000020, /* 00000020 //C 0fd20 db	32 */
0x0000fd21, 0x00000020, /* 00000020 //C 0fd21 db	32 */
0x0000fd22, 0x00000020, /* 00000020 //C 0fd22 db	32 */
0x0000fd23, 0x00000020, /* 00000020 //C 0fd23 db	32 */
0x0000fd24, 0x00000020, /* 00000020 //C 0fd24 db	32 */
0x0000fd25, 0x00000020, /* 00000020 //C 0fd25 db	32 */
0x0000fd26, 0x00000020, /* 00000020 //C 0fd26 db	32 */
0x0000fd27, 0x00000020, /* 00000020 //C 0fd27 db	32 */
0x0000fd28, 0x00000020, /* 00000020 //C 0fd28 db	32 */
0x0000fd29, 0x00000020, /* 00000020 //C 0fd29 db	32 */
0x0000fd2a, 0x00000050, /* 00000050 //C 0fd2a db	80 */
0x0000fd2b, 0x00000072, /* 00000072 //C 0fd2b db	114 */
0x0000fd2c, 0x00000069, /* 00000069 //C 0fd2c db	105 */
0x0000fd2d, 0x0000006e, /* 0000006e //C 0fd2d db	110 */
0x0000fd2e, 0x00000074, /* 00000074 //C 0fd2e db	116 */
0x0000fd2f, 0x00000020, /* 00000020 //C 0fd2f db	32 */
0x0000fd30, 0x00000072, /* 00000072 //C 0fd30 db	114 */
0x0000fd31, 0x00000065, /* 00000065 //C 0fd31 db	101 */
0x0000fd32, 0x00000067, /* 00000067 //C 0fd32 db	103 */
0x0000fd33, 0x00000069, /* 00000069 //C 0fd33 db	105 */
0x0000fd34, 0x00000073, /* 00000073 //C 0fd34 db	115 */
0x0000fd35, 0x00000074, /* 00000074 //C 0fd35 db	116 */
0x0000fd36, 0x00000065, /* 00000065 //C 0fd36 db	101 */
0x0000fd37, 0x00000072, /* 00000072 //C 0fd37 db	114 */
0x0000fd38, 0x00000073, /* 00000073 //C 0fd38 db	115 */
0x0000fd39, 0x0000000a, /* 0000000a //C 0fd39 db	10 */
0x0000fd3a, 0x00000000, /* 00000000 //C 0fd3a db */
0x0000fd3b, 0x00000068, /* 00000068 //C 0fd3b db	104 */
0x0000fd3c, 0x0000002c, /* 0000002c //C 0fd3c db	44 */
0x0000fd3d, 0x0000003f, /* 0000003f //C 0fd3d db	63 */
0x0000fd3e, 0x00000020, /* 00000020 //C 0fd3e db	32 */
0x0000fd3f, 0x00000020, /* 00000020 //C 0fd3f db	32 */
0x0000fd40, 0x00000020, /* 00000020 //C 0fd40 db	32 */
0x0000fd41, 0x00000020, /* 00000020 //C 0fd41 db	32 */
0x0000fd42, 0x00000020, /* 00000020 //C 0fd42 db	32 */
0x0000fd43, 0x00000020, /* 00000020 //C 0fd43 db	32 */
0x0000fd44, 0x00000020, /* 00000020 //C 0fd44 db	32 */
0x0000fd45, 0x00000020, /* 00000020 //C 0fd45 db	32 */
0x0000fd46, 0x00000020, /* 00000020 //C 0fd46 db	32 */
0x0000fd47, 0x00000020, /* 00000020 //C 0fd47 db	32 */
0x0000fd48, 0x00000020, /* 00000020 //C 0fd48 db	32 */
0x0000fd49, 0x00000020, /* 00000020 //C 0fd49 db	32 */
0x0000fd4a, 0x00000020, /* 00000020 //C 0fd4a db	32 */
0x0000fd4b, 0x00000020, /* 00000020 //C 0fd4b db	32 */
0x0000fd4c, 0x00000020, /* 00000020 //C 0fd4c db	32 */
0x0000fd4d, 0x00000020, /* 00000020 //C 0fd4d db	32 */
0x0000fd4e, 0x00000020, /* 00000020 //C 0fd4e db	32 */
0x0000fd4f, 0x00000020, /* 00000020 //C 0fd4f db	32 */
0x0000fd50, 0x00000048, /* 00000048 //C 0fd50 db	72 */
0x0000fd51, 0x00000065, /* 00000065 //C 0fd51 db	101 */
0x0000fd52, 0x0000006c, /* 0000006c //C 0fd52 db	108 */
0x0000fd53, 0x00000070, /* 00000070 //C 0fd53 db	112 */
0x0000fd54, 0x0000000a, /* 0000000a //C 0fd54 db	10 */
0x0000fd55, 0x00000000, /* 00000000 //C 0fd55 db */
0x0000fd56, 0x00000000, /* 00000000 //C 0fd56 dd	0 */
0x0000fe58, 0x00000045, /* 00000045 //C 0fe58 db	69 */
0x0000fe59, 0x0000004f, /* 0000004f //C 0fe59 db	79 */
0x0000fe5a, 0x00000046, /* 00000046 //C 0fe5a db	70 */
0x0000fe5b, 0x00000020, /* 00000020 //C 0fe5b db	32 */
0x0000fe5c, 0x00000050, /* 00000050 //C 0fe5c db	80 */
0x0000fe5d, 0x0000004d, /* 0000004d //C 0fe5d db	77 */
0x0000fe5e, 0x0000006f, /* 0000006f //C 0fe5e db	111 */
0x0000fe5f, 0x0000006e, /* 0000006e //C 0fe5f db	110 */
0x0000fe60, 0x00000069, /* 00000069 //C 0fe60 db	105 */
0x0000fe61, 0x00000074, /* 00000074 //C 0fe61 db	116 */
0x0000fe62, 0x0000006f, /* 0000006f //C 0fe62 db	111 */
0x0000fe63, 0x00000072, /* 00000072 //C 0fe63 db	114 */
0x0000fe64, 0x0000000a, /* 0000000a //C 0fe64 db	10 */
0x0000fe65, 0x00000000, /* 00000000 //C 0fe65 db */
0xffffffff, 0xffffffff
};
