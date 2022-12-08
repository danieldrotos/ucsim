#include "pmon.h"

t_mem pmon[]= {
0x00000000, 0x01f2f800, /* 01f2f800 //C 00000 jmp	start */
0x0000f800, 0x01d2fc47, /* 01d2fc47 //C 0f800 mvzl	sp,stack_end */
0x0000f801, 0x01020001, /* 01020001 //C 0f801 mvzl	r0,1 */
0x0000f802, 0x0112fb07, /* 0112fb07 //C 0f802 mvzl	r1,echo */
0x0000f803, 0x0c010000, /* 0c010000 //C 0f803 st	r0,r1 */
0x0000f804, 0x0102ff44, /* 0102ff44 //C 0f804 mvzl	r0,UART_CPB */
0x0000f805, 0x011200d9, /* 011200d9 //C 0f805 mvzl	r1,217 */
0x0000f806, 0x0c100000, /* 0c100000 //C 0f806 st	r1,r0 */
0x0000f807, 0x0102ff41, /* 0102ff41 //C 0f807 mvzl	r0,UART_CTRL */
0x0000f808, 0x01120003, /* 01120003 //C 0f808 mvzl	r1,3 */
0x0000f809, 0x0c100000, /* 0c100000 //C 0f809 st	r1,r0 */
0x0000f80a, 0x0102fb08, /* 0102fb08 //C 0f80a mvzl	r0,msg_start */
0x0000f80b, 0x0400fa6d, /* 0400fa6d //C 0f80b call	printsnl */
0x0000f80c, 0x0400f80e, /* 0400f80e //C 0f80c call	setup_line */
0x0000f80d, 0x01f2f81b, /* 01f2f81b //C 0f80d jmp	main */
0x0000f80e, 0x0ded0000, /* 0ded0000 //C 0f80e push	lr */
0x0000f80f, 0x0102fb00, /* 0102fb00 //C 0f80f mvzl	r0,line_ptr	; lptr= 0 */
0x0000f810, 0x01120000, /* 01120000 //C 0f810 mvzl	r1,0 */
0x0000f811, 0x0c100000, /* 0c100000 //C 0f811 st	r1,r0 */
0x0000f812, 0x0102fa9c, /* 0102fa9c //C 0f812 mvzl	r0,line		; line[0]= 0 */
0x0000f813, 0x0c100000, /* 0c100000 //C 0f813 st	r1,r0 */
0x0000f814, 0x0102fb01, /* 0102fb01 //C 0f814 mvzl	r0,at_eol	; at_eol= 1 */
0x0000f815, 0x01120001, /* 01120001 //C 0f815 mvzl	r1,1 */
0x0000f816, 0x0c100000, /* 0c100000 //C 0f816 st	r1,r0 */
0x0000f817, 0x0102fb16, /* 0102fb16 //C 0f817 mvzl	r0,prompt */
0x0000f818, 0x0400fa59, /* 0400fa59 //C 0f818 call	prints */
0x0000f819, 0x0fed0000, /* 0fed0000 //C 0f819 pop	lr */
0x0000f81a, 0x00f00e00, /* 00f00e00 //C 0f81a ret */
0x0000f81b, 0x0400fa43, /* 0400fa43 //C 0f81b call	check_uart */
0x0000f81c, 0x41f2f822, /* 41f2f822 //C 0f81c C0 jmp	no_input */
0x0000f81d, 0x0400fa4b, /* 0400fa4b //C 0f81d call	read */
0x0000f81e, 0x0400f823, /* 0400f823 //C 0f81e call	proc_input */
0x0000f81f, 0x41f2f822, /* 41f2f822 //C 0f81f C0 jmp	no_line */
0x0000f820, 0x0400f841, /* 0400f841 //C 0f820 call	proc_line */
0x0000f821, 0x0400f80e, /* 0400f80e //C 0f821 call	setup_line */
0x0000f822, 0x01f2f81b, /* 01f2f81b //C 0f822 jmp	main */
0x0000f823, 0x0ded0000, /* 0ded0000 //C 0f823 push	lr */
0x0000f824, 0x0108000a, /* 0108000a //C 0f824 cmp	r0,LF */
0x0000f825, 0x11f2f83a, /* 11f2f83a //C 0f825 EQ jmp	got_eol */
0x0000f826, 0x0108000d, /* 0108000d //C 0f826 cmp	r0,CR */
0x0000f827, 0x11f2f83a, /* 11f2f83a //C 0f827 EQ jmp	got_eol */
0x0000f828, 0x0112fb01, /* 0112fb01 //C 0f828 mvzl	r1,at_eol	; at_aol= 0 */
0x0000f829, 0x01220000, /* 01220000 //C 0f829 mvzl	r2,0 */
0x0000f82a, 0x0c210000, /* 0c210000 //C 0f82a st	r2,r1 */
0x0000f82b, 0x0112fb00, /* 0112fb00 //C 0f82b mvzl	r1,line_ptr	; line[line_ptr]= char */
0x0000f82c, 0x0e310000, /* 0e310000 //C 0f82c ld	r3,r1 */
0x0000f82d, 0x0122fa9c, /* 0122fa9c //C 0f82d mvzl	r2,line */
0x0000f82e, 0x08020300, /* 08020300 //C 0f82e st	r0,r2,r3 */
0x0000f82f, 0x013a0001, /* 013a0001 //C 0f82f plus	r3,1		; line_ptr++ */
0x0000f830, 0x0c310000, /* 0c310000 //C 0f830 st	r3,r1 */
0x0000f831, 0x01420000, /* 01420000 //C 0f831 mvzl	r4,0 */
0x0000f832, 0x09438200, /* 09438200 //C 0f832 st	r4,r3+,r2	; line[line_ptr]= 0 */
0x0000f833, 0x08430200, /* 08430200 //C 0f833 st	r4,r3,r2	; double 0 at end, needed by tokenizer */
0x0000f834, 0x0142fb07, /* 0142fb07 //C 0f834 mvzl	r4,echo		; check if echo is turned on */
0x0000f835, 0x0e440000, /* 0e440000 //C 0f835 ld	r4,r4 */
0x0000f836, 0x024b0000, /* 024b0000 //C 0f836 sz	r4 */
0x0000f837, 0x2400fa4e, /* 2400fa4e //C 0f837 NZ call	putchar		; echo */
0x0000f838, 0x020d0000, /* 020d0000 //C 0f838 clc */
0x0000f839, 0x01f2f83f, /* 01f2f83f //C 0f839 jmp	proc_input_ret */
0x0000f83a, 0x0112fb01, /* 0112fb01 //C 0f83a mvzl	r1,at_eol */
0x0000f83b, 0x0e110000, /* 0e110000 //C 0f83b ld	r1,r1 */
0x0000f83c, 0x021b0000, /* 021b0000 //C 0f83c sz	r1		; Z=0 at eol -> skip, not ready */
0x0000f83d, 0x220d0000, /* 220d0000 //C 0f83d Z0 clc */
0x0000f83e, 0x120c0000, /* 120c0000 //C 0f83e Z1 sec */
0x0000f83f, 0x0fed0000, /* 0fed0000 //C 0f83f pop	lr */
0x0000f840, 0x00f00e00, /* 00f00e00 //C 0f840 ret */
0x0000f841, 0x0ded0000, /* 0ded0000 //C 0f841 push	lr */
0x0000f842, 0x0102000a, /* 0102000a //C 0f842 mvzl	r0,LF */
0x0000f843, 0x0400fa4e, /* 0400fa4e //C 0f843 call	putchar */
0x0000f844, 0x0400f86a, /* 0400f86a //C 0f844 call	tokenize */
0x0000f845, 0x0400f88b, /* 0400f88b //C 0f845 call	find_cmd */
0x0000f846, 0x41f2f849, /* 41f2f849 //C 0f846 C0 jmp	cmd_not_found */
0x0000f847, 0x05000000, /* 05000000 //C 0f847 call	r0,0 */
0x0000f848, 0x01f2f84b, /* 01f2f84b //C 0f848 jmp	proc_line_ret */
0x0000f849, 0x0102f855, /* 0102f855 //C 0f849 mvzl	r0,snotfound */
0x0000f84a, 0x0400fa6d, /* 0400fa6d //C 0f84a call	printsnl */
0x0000f84b, 0x0102fb01, /* 0102fb01 //C 0f84b mvzl	r0,at_eol	; at_eol= 1 */
0x0000f84c, 0x01120001, /* 01120001 //C 0f84c mvzl	r1,1 */
0x0000f84d, 0x0c100000, /* 0c100000 //C 0f84d st	r1,r0 */
0x0000f84e, 0x0fed0000, /* 0fed0000 //C 0f84e pop	lr */
0x0000f84f, 0x00f00e00, /* 00f00e00 //C 0f84f ret */
0x0000f850, 0x00000047, /* 00000047 //C 0f850 db	71 */
0x0000f851, 0x0000006f, /* 0000006f //C 0f851 db	111 */
0x0000f852, 0x00000074, /* 00000074 //C 0f852 db	116 */
0x0000f853, 0x0000003a, /* 0000003a //C 0f853 db	58 */
0x0000f854, 0x00000000, /* 00000000 //C 0f854 db */
0x0000f855, 0x00000055, /* 00000055 //C 0f855 db	85 */
0x0000f856, 0x0000006e, /* 0000006e //C 0f856 db	110 */
0x0000f857, 0x0000006b, /* 0000006b //C 0f857 db	107 */
0x0000f858, 0x0000006e, /* 0000006e //C 0f858 db	110 */
0x0000f859, 0x0000006f, /* 0000006f //C 0f859 db	111 */
0x0000f85a, 0x00000077, /* 00000077 //C 0f85a db	119 */
0x0000f85b, 0x0000006e, /* 0000006e //C 0f85b db	110 */
0x0000f85c, 0x00000020, /* 00000020 //C 0f85c db	32 */
0x0000f85d, 0x00000063, /* 00000063 //C 0f85d db	99 */
0x0000f85e, 0x0000006f, /* 0000006f //C 0f85e db	111 */
0x0000f85f, 0x0000006d, /* 0000006d //C 0f85f db	109 */
0x0000f860, 0x0000006d, /* 0000006d //C 0f860 db	109 */
0x0000f861, 0x00000061, /* 00000061 //C 0f861 db	97 */
0x0000f862, 0x0000006e, /* 0000006e //C 0f862 db	110 */
0x0000f863, 0x00000064, /* 00000064 //C 0f863 db	100 */
0x0000f864, 0x00000000, /* 00000000 //C 0f864 db */
0x0000f865, 0x0ded0000, /* 0ded0000 //C 0f865 push	lr */
0x0000f866, 0x0112fb18, /* 0112fb18 //C 0f866 mvzl	r1,delimiters */
0x0000f867, 0x0400f9a4, /* 0400f9a4 //C 0f867 call	strchr */
0x0000f868, 0x0fed0000, /* 0fed0000 //C 0f868 pop	lr */
0x0000f869, 0x00f00e00, /* 00f00e00 //C 0f869 ret */
0x0000f86a, 0x0ded0000, /* 0ded0000 //C 0f86a push	lr */
0x0000f86b, 0x0142fb02, /* 0142fb02 //C 0f86b mvzl	r4,words	; array of result */
0x0000f86c, 0x0152fa9c, /* 0152fa9c //C 0f86c mvzl	r5,line		; address of next char */
0x0000f86d, 0x01620000, /* 01620000 //C 0f86d mvzl	r6,0		; nuof words found */
0x0000f86e, 0x01720000, /* 01720000 //C 0f86e mvzl	r7,0		; bool in_word */
0x0000f86f, 0x0e050000, /* 0e050000 //C 0f86f ld	r0,r5		; pick a char */
0x0000f870, 0x020b0000, /* 020b0000 //C 0f870 sz	r0		; check end */
0x0000f871, 0x11f2f87b, /* 11f2f87b //C 0f871 jz	tok_delimiter	; found end, pretend delim */
0x0000f872, 0x0400f865, /* 0400f865 //C 0f872 call	is_delimiter */
0x0000f873, 0x31f2f87b, /* 31f2f87b //C 0f873 C1 jmp	tok_delimiter */
0x0000f874, 0x027b0000, /* 027b0000 //C 0f874 sz	r7 */
0x0000f875, 0x21f2f880, /* 21f2f880 //C 0f875 jnz	tok_next	; still inside word */
0x0000f876, 0x01720001, /* 01720001 //C 0f876 mvzl	r7,1		; in_word=true */
0x0000f877, 0x09568400, /* 09568400 //C 0f877 st	r5,r6+,r4	; record word address */
0x0000f878, 0x01680005, /* 01680005 //C 0f878 cmp	r6,MAX_WORDS	; If no more space */
0x0000f879, 0x11f2f884, /* 11f2f884 //C 0f879 EQ jmp	tok_ret		; then return */
0x0000f87a, 0x01f2f880, /* 01f2f880 //C 0f87a jmp	tok_next */
0x0000f87b, 0x027b0000, /* 027b0000 //C 0f87b sz	r7 */
0x0000f87c, 0x11f2f880, /* 11f2f880 //C 0f87c jz	tok_next	; still between words */
0x0000f87d, 0x01720000, /* 01720000 //C 0f87d mvzl	r7,0		; in_word=false */
0x0000f87e, 0x01120000, /* 01120000 //C 0f87e mvzl	r1,0		; put a 0 at the end of word */
0x0000f87f, 0x08150100, /* 08150100 //C 0f87f st	r1,r5,r1 */
0x0000f880, 0x020b0000, /* 020b0000 //C 0f880 sz	r0		; check EOL */
0x0000f881, 0x11f2f884, /* 11f2f884 //C 0f881 jz	tok_ret		; jump out if char==0 */
0x0000f882, 0x01540001, /* 01540001 //C 0f882 add	r5,1 */
0x0000f883, 0x01f2f86f, /* 01f2f86f //C 0f883 jmp	tok_cycle */
0x0000f884, 0x01120000, /* 01120000 //C 0f884 mvzl	r1,0 */
0x0000f885, 0x01680005, /* 01680005 //C 0f885 cmp	r6,MAX_WORDS */
0x0000f886, 0x11f2f889, /* 11f2f889 //C 0f886 jz	tok_end */
0x0000f887, 0x09168400, /* 09168400 //C 0f887 st	r1,r6+,r4 */
0x0000f888, 0x01f2f884, /* 01f2f884 //C 0f888 jmp	tok_ret */
0x0000f889, 0x0fed0000, /* 0fed0000 //C 0f889 pop	lr */
0x0000f88a, 0x00f00e00, /* 00f00e00 //C 0f88a ret */
0x0000f88b, 0x0ded0000, /* 0ded0000 //C 0f88b push	lr */
0x0000f88c, 0x0d1d0000, /* 0d1d0000 //C 0f88c push	r1 */
0x0000f88d, 0x0d2d0000, /* 0d2d0000 //C 0f88d push	r2 */
0x0000f88e, 0x0d3d0000, /* 0d3d0000 //C 0f88e push	r3 */
0x0000f88f, 0x0dad0000, /* 0dad0000 //C 0f88f push	r10 */
0x0000f890, 0x0102fb02, /* 0102fb02 //C 0f890 mvzl	r0,words	; R0= 1st word of command */
0x0000f891, 0x0e000000, /* 0e000000 //C 0f891 ld	r0,r0 */
0x0000f892, 0x020b0000, /* 020b0000 //C 0f892 sz	r0 */
0x0000f893, 0x11f2f8a8, /* 11f2f8a8 //C 0f893 jz	find_cmd_false */
0x0000f894, 0x01a2fb28, /* 01a2fb28 //C 0f894 mvzl	r10,commands */
0x0000f895, 0x0e2a0000, /* 0e2a0000 //C 0f895 ld	r2,r10		; R2= cmd addr */
0x0000f896, 0x022b0000, /* 022b0000 //C 0f896 sz	r2 */
0x0000f897, 0x11f2f8a8, /* 11f2f8a8 //C 0f897 jz	find_cmd_false */
0x0000f898, 0x01a40001, /* 01a40001 //C 0f898 add	r10,1 */
0x0000f899, 0x00100a00, /* 00100a00 //C 0f899 mov	r1,r10		; R1= cmd string */
0x0000f89a, 0x01a40001, /* 01a40001 //C 0f89a add	r10,1 */
0x0000f89b, 0x0e3a0000, /* 0e3a0000 //C 0f89b ld	r3,r10 */
0x0000f89c, 0x023b0000, /* 023b0000 //C 0f89c sz	r3 */
0x0000f89d, 0x21f2f89a, /* 21f2f89a //C 0f89d jnz	find_cmd_fw */
0x0000f89e, 0x01a40001, /* 01a40001 //C 0f89e add	r10,1 */
0x0000f89f, 0x0400f9df, /* 0400f9df //C 0f89f call	streq */
0x0000f8a0, 0x41f2f895, /* 41f2f895 //C 0f8a0 C0 jmp	find_cmd_cyc */
0x0000f8a1, 0x00000200, /* 00000200 //C 0f8a1 mov	r0,r2 */
0x0000f8a2, 0x020c0000, /* 020c0000 //C 0f8a2 sec */
0x0000f8a3, 0x01f2f8b3, /* 01f2f8b3 //C 0f8a3 jmp	find_cmd_ret */
0x0000f8a4, 0x0000002f, /* 0000002f //C 0f8a4 db	47 */
0x0000f8a5, 0x0000002f, /* 0000002f //C 0f8a5 db	47 */
0x0000f8a6, 0x00000043, /* 00000043 //C 0f8a6 db	67 */
0x0000f8a7, 0x00000000, /* 00000000 //C 0f8a7 db */
0x0000f8a8, 0x01040001, /* 01040001 //C 0f8a8 add	r0,1		; check second word */
0x0000f8a9, 0x0e100000, /* 0e100000 //C 0f8a9 ld	r1,r0		; for //C command */
0x0000f8aa, 0x021b0000, /* 021b0000 //C 0f8aa sz	r1 */
0x0000f8ab, 0x11f2f8b1, /* 11f2f8b1 //C 0f8ab jz	find_cmd_very_false */
0x0000f8ac, 0x0102f8a4, /* 0102f8a4 //C 0f8ac mvzl	r0,c_cmd_name */
0x0000f8ad, 0x0400f9df, /* 0400f9df //C 0f8ad call	streq */
0x0000f8ae, 0x21f2f8b1, /* 21f2f8b1 //C 0f8ae jnz	find_cmd_very_false */
0x0000f8af, 0x0122f942, /* 0122f942 //C 0f8af mvzl	r2,cmd_c */
0x0000f8b0, 0x01f2f8a1, /* 01f2f8a1 //C 0f8b0 jmp	find_cmd_true */
0x0000f8b1, 0x020d0000, /* 020d0000 //C 0f8b1 clc */
0x0000f8b2, 0x01020000, /* 01020000 //C 0f8b2 mvzl	r0,0 */
0x0000f8b3, 0x0fad0000, /* 0fad0000 //C 0f8b3 pop	r10 */
0x0000f8b4, 0x0f3d0000, /* 0f3d0000 //C 0f8b4 pop	r3 */
0x0000f8b5, 0x0f2d0000, /* 0f2d0000 //C 0f8b5 pop	r2 */
0x0000f8b6, 0x0f1d0000, /* 0f1d0000 //C 0f8b6 pop	r1 */
0x0000f8b7, 0x0fed0000, /* 0fed0000 //C 0f8b7 pop	lr */
0x0000f8b8, 0x00f00e00, /* 00f00e00 //C 0f8b8 ret */
0x0000f8b9, 0x0ded0000, /* 0ded0000 //C 0f8b9 push	lr */
0x0000f8ba, 0x0122fb02, /* 0122fb02 //C 0f8ba mvzl	r2,words */
0x0000f8bb, 0x01020000, /* 01020000 //C 0f8bb mvzl	r0,0 */
0x0000f8bc, 0x0e420001, /* 0e420001 //C 0f8bc ld	r4,r2,1		; addr */
0x0000f8bd, 0x0e520002, /* 0e520002 //C 0f8bd ld	r5,r2,2		; value */
0x0000f8be, 0x024b0000, /* 024b0000 //C 0f8be sz 	r4 */
0x0000f8bf, 0x11f2f8e0, /* 11f2f8e0 //C 0f8bf jz	m_ret */
0x0000f8c0, 0x00000400, /* 00000400 //C 0f8c0 mov	r0,r4 */
0x0000f8c1, 0x0400fa21, /* 0400fa21 //C 0f8c1 call	htoi */
0x0000f8c2, 0x00400100, /* 00400100 //C 0f8c2 mov	r4,r1 */
0x0000f8c3, 0x31f2f8c7, /* 31f2f8c7 //C 0f8c3 C1 jmp	m_addr_ok */
0x0000f8c4, 0x0102f8e2, /* 0102f8e2 //C 0f8c4 mvzl	r0,m_err_addr */
0x0000f8c5, 0x0400fa6d, /* 0400fa6d //C 0f8c5 call	printsnl */
0x0000f8c6, 0x01f2f8e0, /* 01f2f8e0 //C 0f8c6 jmp	m_ret */
0x0000f8c7, 0x025b0000, /* 025b0000 //C 0f8c7 sz	r5 */
0x0000f8c8, 0x11f2f8d6, /* 11f2f8d6 //C 0f8c8 jz	m_read */
0x0000f8c9, 0x0148fc56, /* 0148fc56 //C 0f8c9 cmp	r4,the_end */
0x0000f8ca, 0x91f2f8ce, /* 91f2f8ce //C 0f8ca HI jmp	m_addrv_ok */
0x0000f8cb, 0x0102f8f0, /* 0102f8f0 //C 0f8cb mvzl	r0,m_err_addrv */
0x0000f8cc, 0x0400fa6d, /* 0400fa6d //C 0f8cc call	printsnl */
0x0000f8cd, 0x01f2f8e0, /* 01f2f8e0 //C 0f8cd jmp	m_ret */
0x0000f8ce, 0x00000500, /* 00000500 //C 0f8ce mov	r0,r5 */
0x0000f8cf, 0x0400fa21, /* 0400fa21 //C 0f8cf call	htoi */
0x0000f8d0, 0x00500100, /* 00500100 //C 0f8d0 mov	r5,r1 */
0x0000f8d1, 0x31f2f8d5, /* 31f2f8d5 //C 0f8d1 C1 jmp	m_value_ok */
0x0000f8d2, 0x0102f902, /* 0102f902 //C 0f8d2 mvzl	r0,m_err_value */
0x0000f8d3, 0x0400fa6d, /* 0400fa6d //C 0f8d3 call	printsnl */
0x0000f8d4, 0x01f2f8e0, /* 01f2f8e0 //C 0f8d4 jmp	m_ret */
0x0000f8d5, 0x0c540000, /* 0c540000 //C 0f8d5 st	r5,r4 */
0x0000f8d6, 0x00000400, /* 00000400 //C 0f8d6 mov	r0,r4 */
0x0000f8d7, 0x01120004, /* 01120004 //C 0f8d7 mvzl	r1,4 */
0x0000f8d8, 0x0400fa75, /* 0400fa75 //C 0f8d8 call	print_vhex */
0x0000f8d9, 0x01020020, /* 01020020 //C 0f8d9 mvzl	r0,0x20 */
0x0000f8da, 0x0400fa4e, /* 0400fa4e //C 0f8da call	putchar */
0x0000f8db, 0x0e040000, /* 0e040000 //C 0f8db ld	r0,r4 */
0x0000f8dc, 0x01120004, /* 01120004 //C 0f8dc mvzl	r1,4 */
0x0000f8dd, 0x0400fa75, /* 0400fa75 //C 0f8dd call	print_vhex */
0x0000f8de, 0x0102000a, /* 0102000a //C 0f8de mvzl	r0,LF */
0x0000f8df, 0x0400fa4e, /* 0400fa4e //C 0f8df call	putchar */
0x0000f8e0, 0x0fed0000, /* 0fed0000 //C 0f8e0 pop	lr */
0x0000f8e1, 0x00f00e00, /* 00f00e00 //C 0f8e1 ret */
0x0000f8e2, 0x00000041, /* 00000041 //C 0f8e2 db	65 */
0x0000f8e3, 0x00000064, /* 00000064 //C 0f8e3 db	100 */
0x0000f8e4, 0x00000064, /* 00000064 //C 0f8e4 db	100 */
0x0000f8e5, 0x00000072, /* 00000072 //C 0f8e5 db	114 */
0x0000f8e6, 0x00000065, /* 00000065 //C 0f8e6 db	101 */
0x0000f8e7, 0x00000073, /* 00000073 //C 0f8e7 db	115 */
0x0000f8e8, 0x00000073, /* 00000073 //C 0f8e8 db	115 */
0x0000f8e9, 0x00000020, /* 00000020 //C 0f8e9 db	32 */
0x0000f8ea, 0x00000065, /* 00000065 //C 0f8ea db	101 */
0x0000f8eb, 0x00000072, /* 00000072 //C 0f8eb db	114 */
0x0000f8ec, 0x00000072, /* 00000072 //C 0f8ec db	114 */
0x0000f8ed, 0x0000006f, /* 0000006f //C 0f8ed db	111 */
0x0000f8ee, 0x00000072, /* 00000072 //C 0f8ee db	114 */
0x0000f8ef, 0x00000000, /* 00000000 //C 0f8ef db */
0x0000f8f0, 0x0000004d, /* 0000004d //C 0f8f0 db	77 */
0x0000f8f1, 0x0000006f, /* 0000006f //C 0f8f1 db	111 */
0x0000f8f2, 0x0000006e, /* 0000006e //C 0f8f2 db	110 */
0x0000f8f3, 0x00000069, /* 00000069 //C 0f8f3 db	105 */
0x0000f8f4, 0x00000074, /* 00000074 //C 0f8f4 db	116 */
0x0000f8f5, 0x0000006f, /* 0000006f //C 0f8f5 db	111 */
0x0000f8f6, 0x00000072, /* 00000072 //C 0f8f6 db	114 */
0x0000f8f7, 0x00000027, /* 00000027 //C 0f8f7 db	39 */
0x0000f8f8, 0x00000073, /* 00000073 //C 0f8f8 db	115 */
0x0000f8f9, 0x00000020, /* 00000020 //C 0f8f9 db	32 */
0x0000f8fa, 0x00000061, /* 00000061 //C 0f8fa db	97 */
0x0000f8fb, 0x00000064, /* 00000064 //C 0f8fb db	100 */
0x0000f8fc, 0x00000064, /* 00000064 //C 0f8fc db	100 */
0x0000f8fd, 0x00000072, /* 00000072 //C 0f8fd db	114 */
0x0000f8fe, 0x00000065, /* 00000065 //C 0f8fe db	101 */
0x0000f8ff, 0x00000073, /* 00000073 //C 0f8ff db	115 */
0x0000f900, 0x00000073, /* 00000073 //C 0f900 db	115 */
0x0000f901, 0x00000000, /* 00000000 //C 0f901 db */
0x0000f902, 0x00000056, /* 00000056 //C 0f902 db	86 */
0x0000f903, 0x00000061, /* 00000061 //C 0f903 db	97 */
0x0000f904, 0x0000006c, /* 0000006c //C 0f904 db	108 */
0x0000f905, 0x00000075, /* 00000075 //C 0f905 db	117 */
0x0000f906, 0x00000065, /* 00000065 //C 0f906 db	101 */
0x0000f907, 0x00000020, /* 00000020 //C 0f907 db	32 */
0x0000f908, 0x00000065, /* 00000065 //C 0f908 db	101 */
0x0000f909, 0x00000072, /* 00000072 //C 0f909 db	114 */
0x0000f90a, 0x00000072, /* 00000072 //C 0f90a db	114 */
0x0000f90b, 0x0000006f, /* 0000006f //C 0f90b db	111 */
0x0000f90c, 0x00000072, /* 00000072 //C 0f90c db	114 */
0x0000f90d, 0x00000000, /* 00000000 //C 0f90d db */
0x0000f90e, 0x0ded0000, /* 0ded0000 //C 0f90e push	lr */
0x0000f90f, 0x0122fb02, /* 0122fb02 //C 0f90f mvzl	r2,words */
0x0000f910, 0x0e020001, /* 0e020001 //C 0f910 ld	r0,r2,1		; start address */
0x0000f911, 0x0400fa21, /* 0400fa21 //C 0f911 call	htoi */
0x0000f912, 0x00300100, /* 00300100 //C 0f912 mov	r3,r1 */
0x0000f913, 0x0e020002, /* 0e020002 //C 0f913 ld	r0,r2,2		; end address */
0x0000f914, 0x020b0000, /* 020b0000 //C 0f914 sz	r0 */
0x0000f915, 0x21f2f919, /* 21f2f919 //C 0f915 jnz	d_end_ok */
0x0000f916, 0x00400300, /* 00400300 //C 0f916 mov	r4,r3 */
0x0000f917, 0x01440010, /* 01440010 //C 0f917 add	r4,0x10 */
0x0000f918, 0x01f2f91b, /* 01f2f91b //C 0f918 jmp	d_chk_end */
0x0000f919, 0x0400fa21, /* 0400fa21 //C 0f919 call	htoi */
0x0000f91a, 0x00400100, /* 00400100 //C 0f91a mov	r4,r1 */
0x0000f91b, 0x00380400, /* 00380400 //C 0f91b cmp	r3,r4		; check if start>end */
0x0000f91c, 0x91f2f92b, /* 91f2f92b //C 0f91c HI jmp d_bad */
0x0000f91d, 0x00000300, /* 00000300 //C 0f91d mov	r0,r3		; print address */
0x0000f91e, 0x01120004, /* 01120004 //C 0f91e mvzl	r1,4 */
0x0000f91f, 0x0400fa75, /* 0400fa75 //C 0f91f call	print_vhex */
0x0000f920, 0x01020020, /* 01020020 //C 0f920 mvzl	r0,0x20		; print one space */
0x0000f921, 0x0400fa4e, /* 0400fa4e //C 0f921 call	putchar */
0x0000f922, 0x0e030000, /* 0e030000 //C 0f922 ld	r0,r3		; load data */
0x0000f923, 0x01120004, /* 01120004 //C 0f923 mvzl	r1,4		; print data */
0x0000f924, 0x0400fa75, /* 0400fa75 //C 0f924 call	print_vhex */
0x0000f925, 0x0102000a, /* 0102000a //C 0f925 mvzl	r0,LF		; print new line */
0x0000f926, 0x0400fa4e, /* 0400fa4e //C 0f926 call	putchar */
0x0000f927, 0x00380400, /* 00380400 //C 0f927 cmp	r3,r4 */
0x0000f928, 0x11f2f92d, /* 11f2f92d //C 0f928 jz	d_ret */
0x0000f929, 0x01340001, /* 01340001 //C 0f929 add	r3,1 */
0x0000f92a, 0x01f2f91d, /* 01f2f91d //C 0f92a jmp	d_cyc */
0x0000f92b, 0x0102f92f, /* 0102f92f //C 0f92b mvzl	r0,d_err_bad */
0x0000f92c, 0x0400fa6d, /* 0400fa6d //C 0f92c call	printsnl */
0x0000f92d, 0x0fed0000, /* 0fed0000 //C 0f92d pop	lr */
0x0000f92e, 0x00f00e00, /* 00f00e00 //C 0f92e ret */
0x0000f92f, 0x00000057, /* 00000057 //C 0f92f db	87 */
0x0000f930, 0x00000072, /* 00000072 //C 0f930 db	114 */
0x0000f931, 0x0000006f, /* 0000006f //C 0f931 db	111 */
0x0000f932, 0x0000006e, /* 0000006e //C 0f932 db	110 */
0x0000f933, 0x00000067, /* 00000067 //C 0f933 db	103 */
0x0000f934, 0x00000020, /* 00000020 //C 0f934 db	32 */
0x0000f935, 0x00000065, /* 00000065 //C 0f935 db	101 */
0x0000f936, 0x0000006e, /* 0000006e //C 0f936 db	110 */
0x0000f937, 0x00000064, /* 00000064 //C 0f937 db	100 */
0x0000f938, 0x00000020, /* 00000020 //C 0f938 db	32 */
0x0000f939, 0x00000061, /* 00000061 //C 0f939 db	97 */
0x0000f93a, 0x00000064, /* 00000064 //C 0f93a db	100 */
0x0000f93b, 0x00000064, /* 00000064 //C 0f93b db	100 */
0x0000f93c, 0x00000072, /* 00000072 //C 0f93c db	114 */
0x0000f93d, 0x00000065, /* 00000065 //C 0f93d db	101 */
0x0000f93e, 0x00000073, /* 00000073 //C 0f93e db	115 */
0x0000f93f, 0x00000073, /* 00000073 //C 0f93f db	115 */
0x0000f940, 0x00000000, /* 00000000 //C 0f940 db */
0x0000f941, 0x00f00e00, /* 00f00e00 //C 0f941 ret */
0x0000f942, 0x00f00e00, /* 00f00e00 //C 0f942 ret */
0x0000f943, 0x0ded0000, /* 0ded0000 //C 0f943 push	lr */
0x0000f944, 0x01a20000, /* 01a20000 //C 0f944 mvzl	r10,0		; state (nr of words) */
0x0000f945, 0x01820000, /* 01820000 //C 0f945 mvzl	r8,0		; value */
0x0000f946, 0x0162003f, /* 0162003f //C 0f946 mvzl	r6,'?'		; Record type */
0x0000f947, 0x0400fa43, /* 0400fa43 //C 0f947 call	check_uart */
0x0000f948, 0x41f2f947, /* 41f2f947 //C 0f948 C0 jmp	l_cyc */
0x0000f949, 0x0400fa4b, /* 0400fa4b //C 0f949 call	read */
0x0000f94a, 0x00b00000, /* 00b00000 //C 0f94a mov	r11,r0		; Copy of char in R11 */
0x0000f94b, 0x0108000a, /* 0108000a //C 0f94b cmp	r0,10		; check EOL chars */
0x0000f94c, 0x11f2f98e, /* 11f2f98e //C 0f94c jz	l_eol */
0x0000f94d, 0x0108000d, /* 0108000d //C 0f94d cmp	r0,13 */
0x0000f94e, 0x11f2f98e, /* 11f2f98e //C 0f94e jz	l_eol */
0x0000f94f, 0x01a80000, /* 01a80000 //C 0f94f cmp	r10,0 */
0x0000f950, 0x21f2f95e, /* 21f2f95e //C 0f950 jnz	l_no0 */
0x0000f951, 0x0400f9ed, /* 0400f9ed //C 0f951 call	hexchar2value */
0x0000f952, 0x41f2f95a, /* 41f2f95a //C 0f952 C0 jmp	l_eof_0 */
0x0000f953, 0x02880000, /* 02880000 //C 0f953 shl	r8		; shift val(char) into value */
0x0000f954, 0x02880000, /* 02880000 //C 0f954 shl	r8 */
0x0000f955, 0x02880000, /* 02880000 //C 0f955 shl	r8 */
0x0000f956, 0x02880000, /* 02880000 //C 0f956 shl	r8 */
0x0000f957, 0x010b000f, /* 010b000f //C 0f957 btst	r0,0xf */
0x0000f958, 0x008d0000, /* 008d0000 //C 0f958 or	r8,r0 */
0x0000f959, 0x01f2f947, /* 01f2f947 //C 0f959 jmp	l_cyc */
0x0000f95a, 0x01a20001, /* 01a20001 //C 0f95a mvzl	r10,1		; state0 -> state1 */
0x0000f95b, 0x0162003f, /* 0162003f //C 0f95b mvzl	r6,'?'		; No //C yet */
0x0000f95c, 0x01720000, /* 01720000 //C 0f95c mvzl	r7,0		; No '/' yet */
0x0000f95d, 0x01f2f947, /* 01f2f947 //C 0f95d jmp	l_cyc */
0x0000f95e, 0x01a80001, /* 01a80001 //C 0f95e cmp	r10,1 */
0x0000f95f, 0x21f2f975, /* 21f2f975 //C 0f95f jnz	l_no1 */
0x0000f960, 0x027b0000, /* 027b0000 //C 0f960 sz	r7 */
0x0000f961, 0x21f2f966, /* 21f2f966 //C 0f961 jnz	l_s1_2nd */
0x0000f962, 0x0108002f, /* 0108002f //C 0f962 cmp	r0,'/' */
0x0000f963, 0x21f2f947, /* 21f2f947 //C 0f963 jnz	l_cyc */
0x0000f964, 0x01720001, /* 01720001 //C 0f964 mvzl	r7,1 */
0x0000f965, 0x01f2f947, /* 01f2f947 //C 0f965 jmp	l_cyc */
0x0000f966, 0x0108002f, /* 0108002f //C 0f966 cmp	r0,'/' */
0x0000f967, 0x11f2f947, /* 11f2f947 //C 0f967 jz	l_cyc */
0x0000f968, 0x01080043, /* 01080043 //C 0f968 cmp	r0,'C' */
0x0000f969, 0x21f2f96f, /* 21f2f96f //C 0f969 jnz	l_s1_noC */
0x0000f96a, 0x01620043, /* 01620043 //C 0f96a mvzl	r6,'C' */
0x0000f96b, 0x01a20002, /* 01a20002 //C 0f96b mvzl	r10,2 */
0x0000f96c, 0x01920000, /* 01920000 //C 0f96c mvzl	r9,0		; address= 0 */
0x0000f96d, 0x01520000, /* 01520000 //C 0f96d mvzl	r5,0		; where we are in word: before */
0x0000f96e, 0x01f2f947, /* 01f2f947 //C 0f96e jmp	l_cyc */
0x0000f96f, 0x01080045, /* 01080045 //C 0f96f cmp	r0,'E' */
0x0000f970, 0x21f2f974, /* 21f2f974 //C 0f970 jnz	l_s1_noE */
0x0000f971, 0x01620045, /* 01620045 //C 0f971 mvzl	r6,'E' */
0x0000f972, 0x01a20003, /* 01a20003 //C 0f972 mvzl	r10,3 */
0x0000f973, 0x01f2f947, /* 01f2f947 //C 0f973 jmp	l_cyc */
0x0000f974, 0x01f2f947, /* 01f2f947 //C 0f974 jmp	l_cyc */
0x0000f975, 0x01a80002, /* 01a80002 //C 0f975 cmp	r10,2 */
0x0000f976, 0x21f2f98a, /* 21f2f98a //C 0f976 jnz	l_no2 */
0x0000f977, 0x01580000, /* 01580000 //C 0f977 cmp	r5,0 */
0x0000f978, 0x21f2f983, /* 21f2f983 //C 0f978 jnz	l_s2_no0 */
0x0000f979, 0x0400f9ed, /* 0400f9ed //C 0f979 call	hexchar2value */
0x0000f97a, 0x41f2f947, /* 41f2f947 //C 0f97a C0 jmp	l_cyc */
0x0000f97b, 0x01520001, /* 01520001 //C 0f97b mvzl	r5,1 */
0x0000f97c, 0x02980000, /* 02980000 //C 0f97c shl	r9 */
0x0000f97d, 0x02980000, /* 02980000 //C 0f97d shl	r9 */
0x0000f97e, 0x02980000, /* 02980000 //C 0f97e shl	r9 */
0x0000f97f, 0x02980000, /* 02980000 //C 0f97f shl	r9 */
0x0000f980, 0x010b000f, /* 010b000f //C 0f980 btst	r0,0xf */
0x0000f981, 0x009d0000, /* 009d0000 //C 0f981 or	r9,r0 */
0x0000f982, 0x01f2f947, /* 01f2f947 //C 0f982 jmp	l_cyc */
0x0000f983, 0x01580001, /* 01580001 //C 0f983 cmp	r5,1 */
0x0000f984, 0x21f2f989, /* 21f2f989 //C 0f984 jnz	l_s2_no1 */
0x0000f985, 0x0400f9ed, /* 0400f9ed //C 0f985 call	hexchar2value */
0x0000f986, 0x31f2f97c, /* 31f2f97c //C 0f986 C1 jmp	l_s2_got */
0x0000f987, 0x01520002, /* 01520002 //C 0f987 mvzl	r5,2 */
0x0000f988, 0x01f2f947, /* 01f2f947 //C 0f988 jmp	l_cyc */
0x0000f989, 0x01f2f947, /* 01f2f947 //C 0f989 jmp	l_cyc */
0x0000f98a, 0x01a80003, /* 01a80003 //C 0f98a cmp	r10,3 */
0x0000f98b, 0x21f2f98d, /* 21f2f98d //C 0f98b jnz	l_no3 */
0x0000f98c, 0x01f2f947, /* 01f2f947 //C 0f98c jmp	l_cyc		; do nothing, just wait EOL */
0x0000f98d, 0x01f2f9a0, /* 01f2f9a0 //C 0f98d jmp	l_ret */
0x0000f98e, 0x01a80000, /* 01a80000 //C 0f98e cmp	r10,0		; in state0 */
0x0000f98f, 0x11f2f947, /* 11f2f947 //C 0f98f jz	l_cyc		; just skip */
0x0000f990, 0x01a80001, /* 01a80001 //C 0f990 cmp	r10,1		; in state1 */
0x0000f991, 0x11f2f997, /* 11f2f997 //C 0f991 jz	l_bad		; garbage */
0x0000f992, 0x01a80002, /* 01a80002 //C 0f992 cmp	r10,2		; in state2 */
0x0000f993, 0x11f2f998, /* 11f2f998 //C 0f993 jz	l_proc		; process record */
0x0000f994, 0x01a80003, /* 01a80003 //C 0f994 cmp	r10,3		; in state3 */
0x0000f995, 0x11f2f9a0, /* 11f2f9a0 //C 0f995 jz	l_ret		; eol in end record: finish */
0x0000f996, 0x01f2f947, /* 01f2f947 //C 0f996 jmp	l_cyc */
0x0000f997, 0x01f2f9a0, /* 01f2f9a0 //C 0f997 jmp	l_ret */
0x0000f998, 0x01680043, /* 01680043 //C 0f998 cmp	r6,'C'		; is it a C record? */
0x0000f999, 0x1c890000, /* 1c890000 //C 0f999 z st	r8,r9		; store */
0x0000f99a, 0x00000600, /* 00000600 //C 0f99a mov	r0,r6		; echo record type */
0x0000f99b, 0x0400fa4e, /* 0400fa4e //C 0f99b call	putchar */
0x0000f99c, 0x01a20000, /* 01a20000 //C 0f99c mvzl	r10,0 */
0x0000f99d, 0x01820000, /* 01820000 //C 0f99d mvzl	r8,0 */
0x0000f99e, 0x0162003f, /* 0162003f //C 0f99e mvzl	r6,'?' */
0x0000f99f, 0x01f2f947, /* 01f2f947 //C 0f99f jmp	l_cyc */
0x0000f9a0, 0x0102000a, /* 0102000a //C 0f9a0 mvzl	r0,LF */
0x0000f9a1, 0x0400fa4e, /* 0400fa4e //C 0f9a1 call	putchar */
0x0000f9a2, 0x0fed0000, /* 0fed0000 //C 0f9a2 pop	lr */
0x0000f9a3, 0x00f00e00, /* 00f00e00 //C 0f9a3 ret */
0x0000f9a4, 0x0d1d0000, /* 0d1d0000 //C 0f9a4 push	r1 */
0x0000f9a5, 0x0d2d0000, /* 0d2d0000 //C 0f9a5 push	r2 */
0x0000f9a6, 0x0e210000, /* 0e210000 //C 0f9a6 ld	r2,r1 */
0x0000f9a7, 0x022b0000, /* 022b0000 //C 0f9a7 sz	r2 */
0x0000f9a8, 0x11f2f9af, /* 11f2f9af //C 0f9a8 jz	strchr_no	; eof string found */
0x0000f9a9, 0x00280000, /* 00280000 //C 0f9a9 cmp	r2,r0		; compare */
0x0000f9aa, 0x11f2f9ad, /* 11f2f9ad //C 0f9aa jz	strchr_yes */
0x0000f9ab, 0x011a0001, /* 011a0001 //C 0f9ab plus	r1,1		; go to next char */
0x0000f9ac, 0x01f2f9a6, /* 01f2f9a6 //C 0f9ac jmp	strchr_cyc */
0x0000f9ad, 0x020c0000, /* 020c0000 //C 0f9ad sec */
0x0000f9ae, 0x01f2f9b1, /* 01f2f9b1 //C 0f9ae jmp	strchr_ret */
0x0000f9af, 0x01120000, /* 01120000 //C 0f9af mvzl	r1,0 */
0x0000f9b0, 0x020d0000, /* 020d0000 //C 0f9b0 clc */
0x0000f9b1, 0x0f2d0000, /* 0f2d0000 //C 0f9b1 pop	r2 */
0x0000f9b2, 0x0f1d0000, /* 0f1d0000 //C 0f9b2 pop	r1 */
0x0000f9b3, 0x00f00e00, /* 00f00e00 //C 0f9b3 ret */
0x0000f9b4, 0x0ded0000, /* 0ded0000 //C 0f9b4 push	lr		; Save used registers */
0x0000f9b5, 0x0d0d0000, /* 0d0d0000 //C 0f9b5 push	r0		; and input parameters */
0x0000f9b6, 0x0d1d0000, /* 0d1d0000 //C 0f9b6 push	r1 */
0x0000f9b7, 0x0d2d0000, /* 0d2d0000 //C 0f9b7 push	r2 */
0x0000f9b8, 0x0d4d0000, /* 0d4d0000 //C 0f9b8 push	r4 */
0x0000f9b9, 0x0d5d0000, /* 0d5d0000 //C 0f9b9 push	r5 */
0x0000f9ba, 0x0d6d0000, /* 0d6d0000 //C 0f9ba push	r6 */
0x0000f9bb, 0x0e200000, /* 0e200000 //C 0f9bb ld	r2,r0		; Got one-one char */
0x0000f9bc, 0x0e610000, /* 0e610000 //C 0f9bc ld	r6,r1		; from two strings */
0x0000f9bd, 0x023b0000, /* 023b0000 //C 0f9bd sz	r3		; Prepare for comparing */
0x0000f9be, 0x112d0020, /* 112d0020 //C 0f9be Z1 or	r2,0x20		; if insensitive case */
0x0000f9bf, 0x023b0000, /* 023b0000 //C 0f9bf sz	r3 */
0x0000f9c0, 0x116d0020, /* 116d0020 //C 0f9c0 Z1 or	r6,0x20 */
0x0000f9c1, 0x00280600, /* 00280600 //C 0f9c1 cmp	r2,r6		; compare them */
0x0000f9c2, 0x21f2f9d4, /* 21f2f9d4 //C 0f9c2 jnz	streq_no	; if differs: strings are not equal */
0x0000f9c3, 0x0e200000, /* 0e200000 //C 0f9c3 ld	r2,r0		; Pick original (non-prepared) */
0x0000f9c4, 0x0e610000, /* 0e610000 //C 0f9c4 ld	r6,r1		; chars to check EOS */
0x0000f9c5, 0x022b0000, /* 022b0000 //C 0f9c5 sz	r2		; convert them to boolean */
0x0000f9c6, 0x21220001, /* 21220001 //C 0f9c6 Z0 mvzl	r2,1		; values in R2,R6 */
0x0000f9c7, 0x11220000, /* 11220000 //C 0f9c7 Z1 mvzl	r2,0		; and copy in R4,R5 */
0x0000f9c8, 0x00400200, /* 00400200 //C 0f9c8 mov	r4,r2 */
0x0000f9c9, 0x026b0000, /* 026b0000 //C 0f9c9 sz	r6 */
0x0000f9ca, 0x21620001, /* 21620001 //C 0f9ca Z0 mvzl	r6,1 */
0x0000f9cb, 0x11620000, /* 11620000 //C 0f9cb Z1 mvzl r6,0 */
0x0000f9cc, 0x00500600, /* 00500600 //C 0f9cc mov	r5,r6 */
0x0000f9cd, 0x004d0500, /* 004d0500 //C 0f9cd or	r4,r5		; if both are EOS: equal */
0x0000f9ce, 0x11f2f9d6, /* 11f2f9d6 //C 0f9ce jz	streq_yes */
0x0000f9cf, 0x002f0600, /* 002f0600 //C 0f9cf and 	r2,r6		; just one is EOS: not equal */
0x0000f9d0, 0x11f2f9d4, /* 11f2f9d4 //C 0f9d0 jz	streq_no */
0x0000f9d1, 0x010a0001, /* 010a0001 //C 0f9d1 plus	r0,1		; non are EOS: go to check next char */
0x0000f9d2, 0x011a0001, /* 011a0001 //C 0f9d2 plus	r1,1 */
0x0000f9d3, 0x01f2f9bb, /* 01f2f9bb //C 0f9d3 jmp	streq_cyc */
0x0000f9d4, 0x020d0000, /* 020d0000 //C 0f9d4 clc			; False result */
0x0000f9d5, 0x01f2f9d7, /* 01f2f9d7 //C 0f9d5 jmp	streq_ret */
0x0000f9d6, 0x020c0000, /* 020c0000 //C 0f9d6 sec			; True result */
0x0000f9d7, 0x0f6d0000, /* 0f6d0000 //C 0f9d7 pop	r6 */
0x0000f9d8, 0x0f5d0000, /* 0f5d0000 //C 0f9d8 pop	r5 */
0x0000f9d9, 0x0f4d0000, /* 0f4d0000 //C 0f9d9 pop	r4 */
0x0000f9da, 0x0f2d0000, /* 0f2d0000 //C 0f9da pop	r2 */
0x0000f9db, 0x0f1d0000, /* 0f1d0000 //C 0f9db pop	r1 */
0x0000f9dc, 0x0f0d0000, /* 0f0d0000 //C 0f9dc pop	r0 */
0x0000f9dd, 0x0fed0000, /* 0fed0000 //C 0f9dd pop	lr */
0x0000f9de, 0x00f00e00, /* 00f00e00 //C 0f9de ret */
0x0000f9df, 0x0ded0000, /* 0ded0000 //C 0f9df push	lr */
0x0000f9e0, 0x0d3d0000, /* 0d3d0000 //C 0f9e0 push	r3 */
0x0000f9e1, 0x01320001, /* 01320001 //C 0f9e1 mvzl	r3,1 */
0x0000f9e2, 0x0400f9b4, /* 0400f9b4 //C 0f9e2 call	str_cmp_eq */
0x0000f9e3, 0x0f3d0000, /* 0f3d0000 //C 0f9e3 pop	r3 */
0x0000f9e4, 0x0fed0000, /* 0fed0000 //C 0f9e4 pop	lr */
0x0000f9e5, 0x00f00e00, /* 00f00e00 //C 0f9e5 ret */
0x0000f9e6, 0x0ded0000, /* 0ded0000 //C 0f9e6 push	lr */
0x0000f9e7, 0x0d3d0000, /* 0d3d0000 //C 0f9e7 push	r3 */
0x0000f9e8, 0x01320000, /* 01320000 //C 0f9e8 mvzl	r3,0 */
0x0000f9e9, 0x0400f9b4, /* 0400f9b4 //C 0f9e9 call	str_cmp_eq */
0x0000f9ea, 0x0f3d0000, /* 0f3d0000 //C 0f9ea pop	r3 */
0x0000f9eb, 0x0fed0000, /* 0fed0000 //C 0f9eb pop	lr */
0x0000f9ec, 0x00f00e00, /* 00f00e00 //C 0f9ec ret */
0x0000f9ed, 0x0108002f, /* 0108002f //C 0f9ed cmp	r0,'/' */
0x0000f9ee, 0xa1f2fa03, /* a1f2fa03 //C 0f9ee LS jmp	hc2v_nok */
0x0000f9ef, 0x01080039, /* 01080039 //C 0f9ef cmp	r0,'9' */
0x0000f9f0, 0xa1f2fa00, /* a1f2fa00 //C 0f9f0 LS jmp	hc2v_0_9 */
0x0000f9f1, 0x01080040, /* 01080040 //C 0f9f1 cmp	r0,'@' */
0x0000f9f2, 0xa1f2fa03, /* a1f2fa03 //C 0f9f2 LS jmp	hc2v_nok */
0x0000f9f3, 0x01080046, /* 01080046 //C 0f9f3 cmp	r0,'F' */
0x0000f9f4, 0xa1f2f9fd, /* a1f2f9fd //C 0f9f4 LS jmp	hc2v_A_F */
0x0000f9f5, 0x01080060, /* 01080060 //C 0f9f5 cmp	r0,'`' */
0x0000f9f6, 0xa1f2fa03, /* a1f2fa03 //C 0f9f6 LS jmp	hc2v_nok */
0x0000f9f7, 0x01080066, /* 01080066 //C 0f9f7 cmp	r0,'f' */
0x0000f9f8, 0xa1f2f9fa, /* a1f2f9fa //C 0f9f8 LS jmp	hc2v_a_f */
0x0000f9f9, 0x01f2fa03, /* 01f2fa03 //C 0f9f9 jmp	hc2v_nok */
0x0000f9fa, 0x0104000a, /* 0104000a //C 0f9fa add	r0,10 */
0x0000f9fb, 0x01060061, /* 01060061 //C 0f9fb sub	r0,'a' */
0x0000f9fc, 0x01f2fa01, /* 01f2fa01 //C 0f9fc jmp	hc2v_ok */
0x0000f9fd, 0x0104000a, /* 0104000a //C 0f9fd add	r0,10 */
0x0000f9fe, 0x01060041, /* 01060041 //C 0f9fe sub	r0,'A' */
0x0000f9ff, 0x01f2fa01, /* 01f2fa01 //C 0f9ff jmp	hc2v_ok */
0x0000fa00, 0x01060030, /* 01060030 //C 0fa00 sub	r0,'0' */
0x0000fa01, 0x020c0000, /* 020c0000 //C 0fa01 sec */
0x0000fa02, 0x00f00e00, /* 00f00e00 //C 0fa02 ret */
0x0000fa03, 0x020d0000, /* 020d0000 //C 0fa03 clc */
0x0000fa04, 0x00f00e00, /* 00f00e00 //C 0fa04 ret */
0x0000fa05, 0x0d1d0000, /* 0d1d0000 //C 0fa05 push	r1 */
0x0000fa06, 0x010f000f, /* 010f000f //C 0fa06 and	r0,0xf */
0x0000fa07, 0x0112fa0b, /* 0112fa0b //C 0fa07 mvzl	r1,v2hc_table */
0x0000fa08, 0x0a010000, /* 0a010000 //C 0fa08 ld	r0,r1,r0 */
0x0000fa09, 0x0f1d0000, /* 0f1d0000 //C 0fa09 pop	r1 */
0x0000fa0a, 0x00f00e00, /* 00f00e00 //C 0fa0a ret */
0x0000fa0b, 0x00000030, /* 00000030 //C 0fa0b db	48 */
0x0000fa0c, 0x00000031, /* 00000031 //C 0fa0c db	49 */
0x0000fa0d, 0x00000032, /* 00000032 //C 0fa0d db	50 */
0x0000fa0e, 0x00000033, /* 00000033 //C 0fa0e db	51 */
0x0000fa0f, 0x00000034, /* 00000034 //C 0fa0f db	52 */
0x0000fa10, 0x00000035, /* 00000035 //C 0fa10 db	53 */
0x0000fa11, 0x00000036, /* 00000036 //C 0fa11 db	54 */
0x0000fa12, 0x00000037, /* 00000037 //C 0fa12 db	55 */
0x0000fa13, 0x00000038, /* 00000038 //C 0fa13 db	56 */
0x0000fa14, 0x00000039, /* 00000039 //C 0fa14 db	57 */
0x0000fa15, 0x00000041, /* 00000041 //C 0fa15 db	65 */
0x0000fa16, 0x00000042, /* 00000042 //C 0fa16 db	66 */
0x0000fa17, 0x00000043, /* 00000043 //C 0fa17 db	67 */
0x0000fa18, 0x00000044, /* 00000044 //C 0fa18 db	68 */
0x0000fa19, 0x00000045, /* 00000045 //C 0fa19 db	69 */
0x0000fa1a, 0x00000046, /* 00000046 //C 0fa1a db	70 */
0x0000fa1b, 0x00000000, /* 00000000 //C 0fa1b db */
0x0000fa1c, 0x0ded0000, /* 0ded0000 //C 0fa1c push	lr */
0x0000fa1d, 0x0400fa05, /* 0400fa05 //C 0fa1d call	value2Hexchar */
0x0000fa1e, 0x010d0020, /* 010d0020 //C 0fa1e or	r0,0x20 */
0x0000fa1f, 0x0fed0000, /* 0fed0000 //C 0fa1f pop	lr */
0x0000fa20, 0x00f00e00, /* 00f00e00 //C 0fa20 ret */
0x0000fa21, 0x0ded0000, /* 0ded0000 //C 0fa21 push	lr */
0x0000fa22, 0x0d2d0000, /* 0d2d0000 //C 0fa22 push	r2 */
0x0000fa23, 0x0d3d0000, /* 0d3d0000 //C 0fa23 push	r3 */
0x0000fa24, 0x01120000, /* 01120000 //C 0fa24 mvzl	r1,0		; return value */
0x0000fa25, 0x01320000, /* 01320000 //C 0fa25 mvzl	r3,0		; index */
0x0000fa26, 0x0b238000, /* 0b238000 //C 0fa26 ld	r2,r3+,r0	; pick a char */
0x0000fa27, 0x022b0000, /* 022b0000 //C 0fa27 sz	r2		; check eof string */
0x0000fa28, 0x11f2fa3c, /* 11f2fa3c //C 0fa28 jz	htoi_eos */
0x0000fa29, 0x0128002e, /* 0128002e //C 0fa29 cmp	r2,'.'		; skip separators */
0x0000fa2a, 0x11f2fa26, /* 11f2fa26 //C 0fa2a jz	htoi_cyc */
0x0000fa2b, 0x0128005f, /* 0128005f //C 0fa2b cmp	r2,'_' */
0x0000fa2c, 0x11f2fa26, /* 11f2fa26 //C 0fa2c jz	htoi_cyc */
0x0000fa2d, 0x0d0d0000, /* 0d0d0000 //C 0fa2d push	r0 */
0x0000fa2e, 0x00000200, /* 00000200 //C 0fa2e mov	r0,r2 */
0x0000fa2f, 0x0400f9ed, /* 0400f9ed //C 0fa2f call	hexchar2value */
0x0000fa30, 0x00200000, /* 00200000 //C 0fa30 mov	r2,r0 */
0x0000fa31, 0x0f0d0000, /* 0f0d0000 //C 0fa31 pop	r0 */
0x0000fa32, 0x41f2fa3a, /* 41f2fa3a //C 0fa32 C0 jmp	htoi_nok */
0x0000fa33, 0x02180000, /* 02180000 //C 0fa33 shl	r1 */
0x0000fa34, 0x02180000, /* 02180000 //C 0fa34 shl	r1 */
0x0000fa35, 0x02180000, /* 02180000 //C 0fa35 shl	r1 */
0x0000fa36, 0x02180000, /* 02180000 //C 0fa36 shl	r1 */
0x0000fa37, 0x012f000f, /* 012f000f //C 0fa37 and	r2,0xf */
0x0000fa38, 0x001d0200, /* 001d0200 //C 0fa38 or	r1,r2 */
0x0000fa39, 0x01f2fa26, /* 01f2fa26 //C 0fa39 jmp	htoi_cyc */
0x0000fa3a, 0x020d0000, /* 020d0000 //C 0fa3a clc */
0x0000fa3b, 0x01f2fa3f, /* 01f2fa3f //C 0fa3b jmp	htoi_ret */
0x0000fa3c, 0x01380001, /* 01380001 //C 0fa3c cmp	r3,1 */
0x0000fa3d, 0x920d0000, /* 920d0000 //C 0fa3d HI clc */
0x0000fa3e, 0xa20c0000, /* a20c0000 //C 0fa3e LS sec */
0x0000fa3f, 0x0f3d0000, /* 0f3d0000 //C 0fa3f pop	r3 */
0x0000fa40, 0x0f2d0000, /* 0f2d0000 //C 0fa40 pop	r2 */
0x0000fa41, 0x0fed0000, /* 0fed0000 //C 0fa41 pop	lr */
0x0000fa42, 0x00f00e00, /* 00f00e00 //C 0fa42 ret */
0x0000fa43, 0x0d0d0000, /* 0d0d0000 //C 0fa43 push	r0 */
0x0000fa44, 0x0102ff42, /* 0102ff42 //C 0fa44 mvzl	r0,UART_RSTAT */
0x0000fa45, 0x0e000000, /* 0e000000 //C 0fa45 ld	r0,r0 */
0x0000fa46, 0x010c0001, /* 010c0001 //C 0fa46 test	r0,1 */
0x0000fa47, 0x020d0000, /* 020d0000 //C 0fa47 clc */
0x0000fa48, 0x220c0000, /* 220c0000 //C 0fa48 Z0 sec */
0x0000fa49, 0x0f0d0000, /* 0f0d0000 //C 0fa49 pop	r0 */
0x0000fa4a, 0x00f00e00, /* 00f00e00 //C 0fa4a ret */
0x0000fa4b, 0x0102ff40, /* 0102ff40 //C 0fa4b mvzl	r0,UART_DR */
0x0000fa4c, 0x0e000000, /* 0e000000 //C 0fa4c ld	r0,r0 */
0x0000fa4d, 0x00f00e00, /* 00f00e00 //C 0fa4d ret */
0x0000fa4e, 0x0d2d0000, /* 0d2d0000 //C 0fa4e push	r2 */
0x0000fa4f, 0x0d9d0000, /* 0d9d0000 //C 0fa4f push	r9 */
0x0000fa50, 0x0122ff43, /* 0122ff43 //C 0fa50 mvzl	r2,UART_TSTAT */
0x0000fa51, 0x0e920000, /* 0e920000 //C 0fa51 ld	r9,r2 */
0x0000fa52, 0x019c0001, /* 019c0001 //C 0fa52 test	r9,1 */
0x0000fa53, 0x11f2fa51, /* 11f2fa51 //C 0fa53 jz	wait_tc */
0x0000fa54, 0x0122ff40, /* 0122ff40 //C 0fa54 mvzl	r2,UART_DR */
0x0000fa55, 0x0c020000, /* 0c020000 //C 0fa55 st	r0,r2 */
0x0000fa56, 0x0f9d0000, /* 0f9d0000 //C 0fa56 pop	r9 */
0x0000fa57, 0x0f2d0000, /* 0f2d0000 //C 0fa57 pop	r2 */
0x0000fa58, 0x00f00e00, /* 00f00e00 //C 0fa58 ret */
0x0000fa59, 0x0ded0000, /* 0ded0000 //C 0fa59 push	lr */
0x0000fa5a, 0x0d0d0000, /* 0d0d0000 //C 0fa5a push	r0 */
0x0000fa5b, 0x0d3d0000, /* 0d3d0000 //C 0fa5b push	r3 */
0x0000fa5c, 0x0d4d0000, /* 0d4d0000 //C 0fa5c push	r4 */
0x0000fa5d, 0x01420000, /* 01420000 //C 0fa5d mvzl	r4,0 */
0x0000fa5e, 0x020b0000, /* 020b0000 //C 0fa5e sz	r0 */
0x0000fa5f, 0x1102fb21, /* 1102fb21 //C 0fa5f Z1 mvzl	r0,null_str */
0x0000fa60, 0x0b348000, /* 0b348000 //C 0fa60 ld	r3,r4+,r0 */
0x0000fa61, 0x023b0000, /* 023b0000 //C 0fa61 sz	r3 */
0x0000fa62, 0x11f2fa68, /* 11f2fa68 //C 0fa62 jz	prints_done */
0x0000fa63, 0x0d0d0000, /* 0d0d0000 //C 0fa63 push	r0 */
0x0000fa64, 0x00000300, /* 00000300 //C 0fa64 mov	r0,r3 */
0x0000fa65, 0x0400fa4e, /* 0400fa4e //C 0fa65 call	putchar */
0x0000fa66, 0x0f0d0000, /* 0f0d0000 //C 0fa66 pop	r0 */
0x0000fa67, 0x01f2fa60, /* 01f2fa60 //C 0fa67 jmp	prints_go */
0x0000fa68, 0x0f4d0000, /* 0f4d0000 //C 0fa68 pop	r4 */
0x0000fa69, 0x0f3d0000, /* 0f3d0000 //C 0fa69 pop	r3 */
0x0000fa6a, 0x0f0d0000, /* 0f0d0000 //C 0fa6a pop	r0 */
0x0000fa6b, 0x0fed0000, /* 0fed0000 //C 0fa6b pop	lr */
0x0000fa6c, 0x00f00e00, /* 00f00e00 //C 0fa6c ret */
0x0000fa6d, 0x0ded0000, /* 0ded0000 //C 0fa6d push	lr */
0x0000fa6e, 0x0400fa59, /* 0400fa59 //C 0fa6e call	prints */
0x0000fa6f, 0x0d0d0000, /* 0d0d0000 //C 0fa6f push	r0 */
0x0000fa70, 0x0102000a, /* 0102000a //C 0fa70 mvzl	r0,LF */
0x0000fa71, 0x0400fa4e, /* 0400fa4e //C 0fa71 call	putchar */
0x0000fa72, 0x0f0d0000, /* 0f0d0000 //C 0fa72 pop	r0 */
0x0000fa73, 0x0fed0000, /* 0fed0000 //C 0fa73 pop	lr */
0x0000fa74, 0x00f00e00, /* 00f00e00 //C 0fa74 ret */
0x0000fa75, 0x0ded0000, /* 0ded0000 //C 0fa75 push	lr */
0x0000fa76, 0x0d0d0000, /* 0d0d0000 //C 0fa76 push	r0 */
0x0000fa77, 0x0d1d0000, /* 0d1d0000 //C 0fa77 push	r1 */
0x0000fa78, 0x0d2d0000, /* 0d2d0000 //C 0fa78 push	r2 */
0x0000fa79, 0x0d3d0000, /* 0d3d0000 //C 0fa79 push	r3 */
0x0000fa7a, 0x0d4d0000, /* 0d4d0000 //C 0fa7a push	r4 */
0x0000fa7b, 0x00300000, /* 00300000 //C 0fa7b mov	r3,r0 */
0x0000fa7c, 0x01220000, /* 01220000 //C 0fa7c mvzl	r2,0 */
0x0000fa7d, 0x01420001, /* 01420001 //C 0fa7d mvzl	r4,1 */
0x0000fa7e, 0x01020000, /* 01020000 //C 0fa7e mvzl	r0,0 */
0x0000fa7f, 0x02380000, /* 02380000 //C 0fa7f shl	r3 */
0x0000fa80, 0x02070000, /* 02070000 //C 0fa80 rol	r0 */
0x0000fa81, 0x02380000, /* 02380000 //C 0fa81 shl	r3 */
0x0000fa82, 0x02070000, /* 02070000 //C 0fa82 rol	r0 */
0x0000fa83, 0x02380000, /* 02380000 //C 0fa83 shl	r3 */
0x0000fa84, 0x02070000, /* 02070000 //C 0fa84 rol	r0 */
0x0000fa85, 0x02380000, /* 02380000 //C 0fa85 shl	r3 */
0x0000fa86, 0x02070000, /* 02070000 //C 0fa86 rol	r0 */
0x0000fa87, 0x0400fa05, /* 0400fa05 //C 0fa87 call	value2Hexchar */
0x0000fa88, 0x0400fa4e, /* 0400fa4e //C 0fa88 call	putchar */
0x0000fa89, 0x01240001, /* 01240001 //C 0fa89 add	r2,1 */
0x0000fa8a, 0x01280008, /* 01280008 //C 0fa8a cmp	r2,8 */
0x0000fa8b, 0x11f2fa95, /* 11f2fa95 //C 0fa8b jz	print_vhex_ret */
0x0000fa8c, 0x021b0000, /* 021b0000 //C 0fa8c sz	r1 */
0x0000fa8d, 0x11f2fa93, /* 11f2fa93 //C 0fa8d jz	print_vhex_nosep */
0x0000fa8e, 0x00480100, /* 00480100 //C 0fa8e cmp	r4,r1 */
0x0000fa8f, 0x21f2fa93, /* 21f2fa93 //C 0fa8f jnz	print_vhex_nosep */
0x0000fa90, 0x0102005f, /* 0102005f //C 0fa90 mvzl	r0,'_' */
0x0000fa91, 0x0400fa4e, /* 0400fa4e //C 0fa91 call	putchar */
0x0000fa92, 0x01420000, /* 01420000 //C 0fa92 mvzl	r4,0 */
0x0000fa93, 0x01440001, /* 01440001 //C 0fa93 add	r4,1 */
0x0000fa94, 0x01f2fa7e, /* 01f2fa7e //C 0fa94 jmp	print_vhex_cyc */
0x0000fa95, 0x0f4d0000, /* 0f4d0000 //C 0fa95 pop	r4 */
0x0000fa96, 0x0f3d0000, /* 0f3d0000 //C 0fa96 pop	r3 */
0x0000fa97, 0x0f2d0000, /* 0f2d0000 //C 0fa97 pop	r2 */
0x0000fa98, 0x0f1d0000, /* 0f1d0000 //C 0fa98 pop	r1 */
0x0000fa99, 0x0f0d0000, /* 0f0d0000 //C 0fa99 pop	r0 */
0x0000fa9a, 0x0fed0000, /* 0fed0000 //C 0fa9a pop	lr */
0x0000fa9b, 0x00f00e00, /* 00f00e00 //C 0fa9b ret */
0x0000fb08, 0x00000050, /* 00000050 //C 0fb08 db	80 */
0x0000fb09, 0x0000004d, /* 0000004d //C 0fb09 db	77 */
0x0000fb0a, 0x0000006f, /* 0000006f //C 0fb0a db	111 */
0x0000fb0b, 0x0000006e, /* 0000006e //C 0fb0b db	110 */
0x0000fb0c, 0x00000069, /* 00000069 //C 0fb0c db	105 */
0x0000fb0d, 0x00000074, /* 00000074 //C 0fb0d db	116 */
0x0000fb0e, 0x0000006f, /* 0000006f //C 0fb0e db	111 */
0x0000fb0f, 0x00000072, /* 00000072 //C 0fb0f db	114 */
0x0000fb10, 0x00000020, /* 00000020 //C 0fb10 db	32 */
0x0000fb11, 0x00000076, /* 00000076 //C 0fb11 db	118 */
0x0000fb12, 0x00000031, /* 00000031 //C 0fb12 db	49 */
0x0000fb13, 0x0000002e, /* 0000002e //C 0fb13 db	46 */
0x0000fb14, 0x00000030, /* 00000030 //C 0fb14 db	48 */
0x0000fb15, 0x00000000, /* 00000000 //C 0fb15 db */
0x0000fb16, 0x0000003e, /* 0000003e //C 0fb16 db	62 */
0x0000fb17, 0x00000000, /* 00000000 //C 0fb17 db */
0x0000fb18, 0x00000020, /* 00000020 //C 0fb18 db	32 */
0x0000fb19, 0x0000003b, /* 0000003b //C 0fb19 db	59 */
0x0000fb1a, 0x00000009, /* 00000009 //C 0fb1a db	9 */
0x0000fb1b, 0x0000000b, /* 0000000b //C 0fb1b db	11 */
0x0000fb1c, 0x0000002c, /* 0000002c //C 0fb1c db	44 */
0x0000fb1d, 0x0000003d, /* 0000003d //C 0fb1d db	61 */
0x0000fb1e, 0x0000005b, /* 0000005b //C 0fb1e db	91 */
0x0000fb1f, 0x0000005d, /* 0000005d //C 0fb1f db	93 */
0x0000fb20, 0x00000000, /* 00000000 //C 0fb20 db */
0x0000fb21, 0x00000028, /* 00000028 //C 0fb21 db	40 */
0x0000fb22, 0x0000006e, /* 0000006e //C 0fb22 db	110 */
0x0000fb23, 0x00000075, /* 00000075 //C 0fb23 db	117 */
0x0000fb24, 0x0000006c, /* 0000006c //C 0fb24 db	108 */
0x0000fb25, 0x0000006c, /* 0000006c //C 0fb25 db	108 */
0x0000fb26, 0x00000029, /* 00000029 //C 0fb26 db	41 */
0x0000fb27, 0x00000000, /* 00000000 //C 0fb27 db */
0x0000fb28, 0x0000f8b9, /* 0000f8b9 //C 0fb28 dd	cmd_m */
0x0000fb29, 0x0000006d, /* 0000006d //C 0fb29 db	109 */
0x0000fb2a, 0x00000000, /* 00000000 //C 0fb2a db */
0x0000fb2b, 0x0000f8b9, /* 0000f8b9 //C 0fb2b dd	cmd_m */
0x0000fb2c, 0x0000006d, /* 0000006d //C 0fb2c db	109 */
0x0000fb2d, 0x00000065, /* 00000065 //C 0fb2d db	101 */
0x0000fb2e, 0x0000006d, /* 0000006d //C 0fb2e db	109 */
0x0000fb2f, 0x00000000, /* 00000000 //C 0fb2f db */
0x0000fb30, 0x0000f90e, /* 0000f90e //C 0fb30 dd	cmd_d */
0x0000fb31, 0x00000064, /* 00000064 //C 0fb31 db	100 */
0x0000fb32, 0x00000000, /* 00000000 //C 0fb32 db */
0x0000fb33, 0x0000f90e, /* 0000f90e //C 0fb33 dd	cmd_d */
0x0000fb34, 0x00000064, /* 00000064 //C 0fb34 db	100 */
0x0000fb35, 0x00000075, /* 00000075 //C 0fb35 db	117 */
0x0000fb36, 0x0000006d, /* 0000006d //C 0fb36 db	109 */
0x0000fb37, 0x00000070, /* 00000070 //C 0fb37 db	112 */
0x0000fb38, 0x00000000, /* 00000000 //C 0fb38 db */
0x0000fb39, 0x0000f941, /* 0000f941 //C 0fb39 dd	cmd_e */
0x0000fb3a, 0x00000065, /* 00000065 //C 0fb3a db	101 */
0x0000fb3b, 0x00000000, /* 00000000 //C 0fb3b db */
0x0000fb3c, 0x0000f943, /* 0000f943 //C 0fb3c dd	cmd_l */
0x0000fb3d, 0x0000006c, /* 0000006c //C 0fb3d db	108 */
0x0000fb3e, 0x00000000, /* 00000000 //C 0fb3e db */
0x0000fb3f, 0x0000f943, /* 0000f943 //C 0fb3f dd	cmd_l */
0x0000fb40, 0x0000006c, /* 0000006c //C 0fb40 db	108 */
0x0000fb41, 0x0000006f, /* 0000006f //C 0fb41 db	111 */
0x0000fb42, 0x00000061, /* 00000061 //C 0fb42 db	97 */
0x0000fb43, 0x00000064, /* 00000064 //C 0fb43 db	100 */
0x0000fb44, 0x00000000, /* 00000000 //C 0fb44 db */
0x0000fb45, 0x00000000, /* 00000000 //C 0fb45 dd	0 */
0x0000fb46, 0x00000000, /* 00000000 //C 0fb46 db	0 */
0x0000fc48, 0x00000045, /* 00000045 //C 0fc48 db	69 */
0x0000fc49, 0x0000004f, /* 0000004f //C 0fc49 db	79 */
0x0000fc4a, 0x00000046, /* 00000046 //C 0fc4a db	70 */
0x0000fc4b, 0x00000020, /* 00000020 //C 0fc4b db	32 */
0x0000fc4c, 0x00000050, /* 00000050 //C 0fc4c db	80 */
0x0000fc4d, 0x0000004d, /* 0000004d //C 0fc4d db	77 */
0x0000fc4e, 0x0000006f, /* 0000006f //C 0fc4e db	111 */
0x0000fc4f, 0x0000006e, /* 0000006e //C 0fc4f db	110 */
0x0000fc50, 0x00000069, /* 00000069 //C 0fc50 db	105 */
0x0000fc51, 0x00000074, /* 00000074 //C 0fc51 db	116 */
0x0000fc52, 0x0000006f, /* 0000006f //C 0fc52 db	111 */
0x0000fc53, 0x00000072, /* 00000072 //C 0fc53 db	114 */
0x0000fc54, 0x0000000a, /* 0000000a //C 0fc54 db	10 */
0x0000fc55, 0x00000000, /* 00000000 //C 0fc55 db */
0xffffffff, 0xffffffff
};
