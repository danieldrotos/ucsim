#include "pmon.h"

t_mem pmon[]= {
0x00000000, 0x01f2f80e, /* 01f2f80e //C 00000 jmp	start */
0x0000f800, 0x01f2f80d, /* 01f2f80d //C 0f800 _f800:	jmp	callin */
0x0000f801, 0x01f2f9b2, /* 01f2f9b2 //C 0f801 _f801:	jmp	strchr */
0x0000f802, 0x01f2f9ed, /* 01f2f9ed //C 0f802 _f802:	jmp	streq */
0x0000f803, 0x01f2f9f4, /* 01f2f9f4 //C 0f803 _f803:	jmp	strieq */
0x0000f804, 0x01f2f9fb, /* 01f2f9fb //C 0f804 _f804:	jmp	hexchar2value */
0x0000f805, 0x01f2fa2a, /* 01f2fa2a //C 0f805 _f805:	jmp	value2hexchar */
0x0000f806, 0x01f2fa2f, /* 01f2fa2f //C 0f806 _f806:	jmp	htoi */
0x0000f807, 0x01f2fa51, /* 01f2fa51 //C 0f807 _f807:	jmp	check_uart */
0x0000f808, 0x01f2fa59, /* 01f2fa59 //C 0f808 _f808:	jmp	read */
0x0000f809, 0x01f2fa5c, /* 01f2fa5c //C 0f809 _f809:	jmp	putchar */
0x0000f80a, 0x01f2fa67, /* 01f2fa67 //C 0f80a _f80a:	jmp	prints */
0x0000f80b, 0x01f2fa7b, /* 01f2fa7b //C 0f80b _f80b:	jmp	printsnl */
0x0000f80c, 0x01f2fa83, /* 01f2fa83 //C 0f80c _f80c:	jmp	print_vhex */
0x0000f80d, 0x01f2f80e, /* 01f2f80e //C 0f80d jmp	start */
0x0000f80e, 0x01d2fc55, /* 01d2fc55 //C 0f80e mvzl	sp,stack_end */
0x0000f80f, 0x01020001, /* 01020001 //C 0f80f mvzl	r0,1 */
0x0000f810, 0x0112fb15, /* 0112fb15 //C 0f810 mvzl	r1,echo */
0x0000f811, 0x0c010000, /* 0c010000 //C 0f811 st	r0,r1 */
0x0000f812, 0x0102ff44, /* 0102ff44 //C 0f812 mvzl	r0,UART_CPB */
0x0000f813, 0x011200d9, /* 011200d9 //C 0f813 mvzl	r1,217 */
0x0000f814, 0x0c100000, /* 0c100000 //C 0f814 st	r1,r0 */
0x0000f815, 0x0102ff41, /* 0102ff41 //C 0f815 mvzl	r0,UART_CTRL */
0x0000f816, 0x01120003, /* 01120003 //C 0f816 mvzl	r1,3 */
0x0000f817, 0x0c100000, /* 0c100000 //C 0f817 st	r1,r0 */
0x0000f818, 0x0102fb16, /* 0102fb16 //C 0f818 mvzl	r0,msg_start */
0x0000f819, 0x0400fa7b, /* 0400fa7b //C 0f819 call	printsnl */
0x0000f81a, 0x0400f81c, /* 0400f81c //C 0f81a call	setup_line */
0x0000f81b, 0x01f2f829, /* 01f2f829 //C 0f81b jmp	main */
0x0000f81c, 0x0ded0000, /* 0ded0000 //C 0f81c push	lr */
0x0000f81d, 0x0102fb0e, /* 0102fb0e //C 0f81d mvzl	r0,line_ptr	; lptr= 0 */
0x0000f81e, 0x01120000, /* 01120000 //C 0f81e mvzl	r1,0 */
0x0000f81f, 0x0c100000, /* 0c100000 //C 0f81f st	r1,r0 */
0x0000f820, 0x0102faaa, /* 0102faaa //C 0f820 mvzl	r0,line		; line[0]= 0 */
0x0000f821, 0x0c100000, /* 0c100000 //C 0f821 st	r1,r0 */
0x0000f822, 0x0102fb0f, /* 0102fb0f //C 0f822 mvzl	r0,at_eol	; at_eol= 1 */
0x0000f823, 0x01120001, /* 01120001 //C 0f823 mvzl	r1,1 */
0x0000f824, 0x0c100000, /* 0c100000 //C 0f824 st	r1,r0 */
0x0000f825, 0x0102fb24, /* 0102fb24 //C 0f825 mvzl	r0,prompt */
0x0000f826, 0x0400fa67, /* 0400fa67 //C 0f826 call	prints */
0x0000f827, 0x0fed0000, /* 0fed0000 //C 0f827 pop	lr */
0x0000f828, 0x00f00e00, /* 00f00e00 //C 0f828 ret */
0x0000f829, 0x0400fa51, /* 0400fa51 //C 0f829 call	check_uart */
0x0000f82a, 0x41f2f830, /* 41f2f830 //C 0f82a C0 jmp	no_input */
0x0000f82b, 0x0400fa59, /* 0400fa59 //C 0f82b call	read */
0x0000f82c, 0x0400f831, /* 0400f831 //C 0f82c call	proc_input */
0x0000f82d, 0x41f2f830, /* 41f2f830 //C 0f82d C0 jmp	no_line */
0x0000f82e, 0x0400f84f, /* 0400f84f //C 0f82e call	proc_line */
0x0000f82f, 0x0400f81c, /* 0400f81c //C 0f82f call	setup_line */
0x0000f830, 0x01f2f829, /* 01f2f829 //C 0f830 jmp	main */
0x0000f831, 0x0ded0000, /* 0ded0000 //C 0f831 push	lr */
0x0000f832, 0x0108000a, /* 0108000a //C 0f832 cmp	r0,LF */
0x0000f833, 0x11f2f848, /* 11f2f848 //C 0f833 EQ jmp	got_eol */
0x0000f834, 0x0108000d, /* 0108000d //C 0f834 cmp	r0,CR */
0x0000f835, 0x11f2f848, /* 11f2f848 //C 0f835 EQ jmp	got_eol */
0x0000f836, 0x0112fb0f, /* 0112fb0f //C 0f836 mvzl	r1,at_eol	; at_aol= 0 */
0x0000f837, 0x01220000, /* 01220000 //C 0f837 mvzl	r2,0 */
0x0000f838, 0x0c210000, /* 0c210000 //C 0f838 st	r2,r1 */
0x0000f839, 0x0112fb0e, /* 0112fb0e //C 0f839 mvzl	r1,line_ptr	; line[line_ptr]= char */
0x0000f83a, 0x0e310000, /* 0e310000 //C 0f83a ld	r3,r1 */
0x0000f83b, 0x0122faaa, /* 0122faaa //C 0f83b mvzl	r2,line */
0x0000f83c, 0x08020300, /* 08020300 //C 0f83c st	r0,r2,r3 */
0x0000f83d, 0x013a0001, /* 013a0001 //C 0f83d plus	r3,1		; line_ptr++ */
0x0000f83e, 0x0c310000, /* 0c310000 //C 0f83e st	r3,r1 */
0x0000f83f, 0x01420000, /* 01420000 //C 0f83f mvzl	r4,0 */
0x0000f840, 0x09438200, /* 09438200 //C 0f840 st	r4,r3+,r2	; line[line_ptr]= 0 */
0x0000f841, 0x08430200, /* 08430200 //C 0f841 st	r4,r3,r2	; double 0 at end, needed by tokenizer */
0x0000f842, 0x0142fb15, /* 0142fb15 //C 0f842 mvzl	r4,echo		; check if echo is turned on */
0x0000f843, 0x0e440000, /* 0e440000 //C 0f843 ld	r4,r4 */
0x0000f844, 0x024b0000, /* 024b0000 //C 0f844 sz	r4 */
0x0000f845, 0x2400fa5c, /* 2400fa5c //C 0f845 NZ call	putchar		; echo */
0x0000f846, 0x020d0000, /* 020d0000 //C 0f846 clc */
0x0000f847, 0x01f2f84d, /* 01f2f84d //C 0f847 jmp	proc_input_ret */
0x0000f848, 0x0112fb0f, /* 0112fb0f //C 0f848 mvzl	r1,at_eol */
0x0000f849, 0x0e110000, /* 0e110000 //C 0f849 ld	r1,r1 */
0x0000f84a, 0x021b0000, /* 021b0000 //C 0f84a sz	r1		; Z=0 at eol -> skip, not ready */
0x0000f84b, 0x220d0000, /* 220d0000 //C 0f84b Z0 clc */
0x0000f84c, 0x120c0000, /* 120c0000 //C 0f84c Z1 sec */
0x0000f84d, 0x0fed0000, /* 0fed0000 //C 0f84d pop	lr */
0x0000f84e, 0x00f00e00, /* 00f00e00 //C 0f84e ret */
0x0000f84f, 0x0ded0000, /* 0ded0000 //C 0f84f push	lr */
0x0000f850, 0x0102000a, /* 0102000a //C 0f850 mvzl	r0,LF */
0x0000f851, 0x0400fa5c, /* 0400fa5c //C 0f851 call	putchar */
0x0000f852, 0x0400f878, /* 0400f878 //C 0f852 call	tokenize */
0x0000f853, 0x0400f899, /* 0400f899 //C 0f853 call	find_cmd */
0x0000f854, 0x41f2f857, /* 41f2f857 //C 0f854 C0 jmp	cmd_not_found */
0x0000f855, 0x05000000, /* 05000000 //C 0f855 call	r0,0 */
0x0000f856, 0x01f2f859, /* 01f2f859 //C 0f856 jmp	proc_line_ret */
0x0000f857, 0x0102f863, /* 0102f863 //C 0f857 mvzl	r0,snotfound */
0x0000f858, 0x0400fa7b, /* 0400fa7b //C 0f858 call	printsnl */
0x0000f859, 0x0102fb0f, /* 0102fb0f //C 0f859 mvzl	r0,at_eol	; at_eol= 1 */
0x0000f85a, 0x01120001, /* 01120001 //C 0f85a mvzl	r1,1 */
0x0000f85b, 0x0c100000, /* 0c100000 //C 0f85b st	r1,r0 */
0x0000f85c, 0x0fed0000, /* 0fed0000 //C 0f85c pop	lr */
0x0000f85d, 0x00f00e00, /* 00f00e00 //C 0f85d ret */
0x0000f85e, 0x00000047, /* 00000047 //C 0f85e db	71 */
0x0000f85f, 0x0000006f, /* 0000006f //C 0f85f db	111 */
0x0000f860, 0x00000074, /* 00000074 //C 0f860 db	116 */
0x0000f861, 0x0000003a, /* 0000003a //C 0f861 db	58 */
0x0000f862, 0x00000000, /* 00000000 //C 0f862 db */
0x0000f863, 0x00000055, /* 00000055 //C 0f863 db	85 */
0x0000f864, 0x0000006e, /* 0000006e //C 0f864 db	110 */
0x0000f865, 0x0000006b, /* 0000006b //C 0f865 db	107 */
0x0000f866, 0x0000006e, /* 0000006e //C 0f866 db	110 */
0x0000f867, 0x0000006f, /* 0000006f //C 0f867 db	111 */
0x0000f868, 0x00000077, /* 00000077 //C 0f868 db	119 */
0x0000f869, 0x0000006e, /* 0000006e //C 0f869 db	110 */
0x0000f86a, 0x00000020, /* 00000020 //C 0f86a db	32 */
0x0000f86b, 0x00000063, /* 00000063 //C 0f86b db	99 */
0x0000f86c, 0x0000006f, /* 0000006f //C 0f86c db	111 */
0x0000f86d, 0x0000006d, /* 0000006d //C 0f86d db	109 */
0x0000f86e, 0x0000006d, /* 0000006d //C 0f86e db	109 */
0x0000f86f, 0x00000061, /* 00000061 //C 0f86f db	97 */
0x0000f870, 0x0000006e, /* 0000006e //C 0f870 db	110 */
0x0000f871, 0x00000064, /* 00000064 //C 0f871 db	100 */
0x0000f872, 0x00000000, /* 00000000 //C 0f872 db */
0x0000f873, 0x0ded0000, /* 0ded0000 //C 0f873 push	lr */
0x0000f874, 0x0112fb26, /* 0112fb26 //C 0f874 mvzl	r1,delimiters */
0x0000f875, 0x0400f9b2, /* 0400f9b2 //C 0f875 call	strchr */
0x0000f876, 0x0fed0000, /* 0fed0000 //C 0f876 pop	lr */
0x0000f877, 0x00f00e00, /* 00f00e00 //C 0f877 ret */
0x0000f878, 0x0ded0000, /* 0ded0000 //C 0f878 push	lr */
0x0000f879, 0x0142fb10, /* 0142fb10 //C 0f879 mvzl	r4,words	; array of result */
0x0000f87a, 0x0152faaa, /* 0152faaa //C 0f87a mvzl	r5,line		; address of next char */
0x0000f87b, 0x01620000, /* 01620000 //C 0f87b mvzl	r6,0		; nuof words found */
0x0000f87c, 0x01720000, /* 01720000 //C 0f87c mvzl	r7,0		; bool in_word */
0x0000f87d, 0x0e050000, /* 0e050000 //C 0f87d ld	r0,r5		; pick a char */
0x0000f87e, 0x020b0000, /* 020b0000 //C 0f87e sz	r0		; check end */
0x0000f87f, 0x11f2f889, /* 11f2f889 //C 0f87f jz	tok_delimiter	; found end, pretend delim */
0x0000f880, 0x0400f873, /* 0400f873 //C 0f880 call	is_delimiter */
0x0000f881, 0x31f2f889, /* 31f2f889 //C 0f881 C1 jmp	tok_delimiter */
0x0000f882, 0x027b0000, /* 027b0000 //C 0f882 sz	r7 */
0x0000f883, 0x21f2f88e, /* 21f2f88e //C 0f883 jnz	tok_next	; still inside word */
0x0000f884, 0x01720001, /* 01720001 //C 0f884 mvzl	r7,1		; in_word=true */
0x0000f885, 0x09568400, /* 09568400 //C 0f885 st	r5,r6+,r4	; record word address */
0x0000f886, 0x01680005, /* 01680005 //C 0f886 cmp	r6,MAX_WORDS	; If no more space */
0x0000f887, 0x11f2f892, /* 11f2f892 //C 0f887 EQ jmp	tok_ret		; then return */
0x0000f888, 0x01f2f88e, /* 01f2f88e //C 0f888 jmp	tok_next */
0x0000f889, 0x027b0000, /* 027b0000 //C 0f889 sz	r7 */
0x0000f88a, 0x11f2f88e, /* 11f2f88e //C 0f88a jz	tok_next	; still between words */
0x0000f88b, 0x01720000, /* 01720000 //C 0f88b mvzl	r7,0		; in_word=false */
0x0000f88c, 0x01120000, /* 01120000 //C 0f88c mvzl	r1,0		; put a 0 at the end of word */
0x0000f88d, 0x08150100, /* 08150100 //C 0f88d st	r1,r5,r1 */
0x0000f88e, 0x020b0000, /* 020b0000 //C 0f88e sz	r0		; check EOL */
0x0000f88f, 0x11f2f892, /* 11f2f892 //C 0f88f jz	tok_ret		; jump out if char==0 */
0x0000f890, 0x01540001, /* 01540001 //C 0f890 add	r5,1 */
0x0000f891, 0x01f2f87d, /* 01f2f87d //C 0f891 jmp	tok_cycle */
0x0000f892, 0x01120000, /* 01120000 //C 0f892 mvzl	r1,0 */
0x0000f893, 0x01680005, /* 01680005 //C 0f893 cmp	r6,MAX_WORDS */
0x0000f894, 0x11f2f897, /* 11f2f897 //C 0f894 jz	tok_end */
0x0000f895, 0x09168400, /* 09168400 //C 0f895 st	r1,r6+,r4 */
0x0000f896, 0x01f2f892, /* 01f2f892 //C 0f896 jmp	tok_ret */
0x0000f897, 0x0fed0000, /* 0fed0000 //C 0f897 pop	lr */
0x0000f898, 0x00f00e00, /* 00f00e00 //C 0f898 ret */
0x0000f899, 0x0ded0000, /* 0ded0000 //C 0f899 push	lr */
0x0000f89a, 0x0d1d0000, /* 0d1d0000 //C 0f89a push	r1 */
0x0000f89b, 0x0d2d0000, /* 0d2d0000 //C 0f89b push	r2 */
0x0000f89c, 0x0d3d0000, /* 0d3d0000 //C 0f89c push	r3 */
0x0000f89d, 0x0dad0000, /* 0dad0000 //C 0f89d push	r10 */
0x0000f89e, 0x0102fb10, /* 0102fb10 //C 0f89e mvzl	r0,words	; R0= 1st word of command */
0x0000f89f, 0x0e000000, /* 0e000000 //C 0f89f ld	r0,r0 */
0x0000f8a0, 0x020b0000, /* 020b0000 //C 0f8a0 sz	r0 */
0x0000f8a1, 0x11f2f8b6, /* 11f2f8b6 //C 0f8a1 jz	find_cmd_false */
0x0000f8a2, 0x01a2fb36, /* 01a2fb36 //C 0f8a2 mvzl	r10,commands */
0x0000f8a3, 0x0e2a0000, /* 0e2a0000 //C 0f8a3 ld	r2,r10		; R2= cmd addr */
0x0000f8a4, 0x022b0000, /* 022b0000 //C 0f8a4 sz	r2 */
0x0000f8a5, 0x11f2f8b6, /* 11f2f8b6 //C 0f8a5 jz	find_cmd_false */
0x0000f8a6, 0x01a40001, /* 01a40001 //C 0f8a6 add	r10,1 */
0x0000f8a7, 0x00100a00, /* 00100a00 //C 0f8a7 mov	r1,r10		; R1= cmd string */
0x0000f8a8, 0x01a40001, /* 01a40001 //C 0f8a8 add	r10,1 */
0x0000f8a9, 0x0e3a0000, /* 0e3a0000 //C 0f8a9 ld	r3,r10 */
0x0000f8aa, 0x023b0000, /* 023b0000 //C 0f8aa sz	r3 */
0x0000f8ab, 0x21f2f8a8, /* 21f2f8a8 //C 0f8ab jnz	find_cmd_fw */
0x0000f8ac, 0x01a40001, /* 01a40001 //C 0f8ac add	r10,1 */
0x0000f8ad, 0x0400f9ed, /* 0400f9ed //C 0f8ad call	streq */
0x0000f8ae, 0x41f2f8a3, /* 41f2f8a3 //C 0f8ae C0 jmp	find_cmd_cyc */
0x0000f8af, 0x00000200, /* 00000200 //C 0f8af mov	r0,r2 */
0x0000f8b0, 0x020c0000, /* 020c0000 //C 0f8b0 sec */
0x0000f8b1, 0x01f2f8c1, /* 01f2f8c1 //C 0f8b1 jmp	find_cmd_ret */
0x0000f8b2, 0x0000002f, /* 0000002f //C 0f8b2 db	47 */
0x0000f8b3, 0x0000002f, /* 0000002f //C 0f8b3 db	47 */
0x0000f8b4, 0x00000043, /* 00000043 //C 0f8b4 db	67 */
0x0000f8b5, 0x00000000, /* 00000000 //C 0f8b5 db */
0x0000f8b6, 0x01040001, /* 01040001 //C 0f8b6 add	r0,1		; check second word */
0x0000f8b7, 0x0e100000, /* 0e100000 //C 0f8b7 ld	r1,r0		; for //C command */
0x0000f8b8, 0x021b0000, /* 021b0000 //C 0f8b8 sz	r1 */
0x0000f8b9, 0x11f2f8bf, /* 11f2f8bf //C 0f8b9 jz	find_cmd_very_false */
0x0000f8ba, 0x0102f8b2, /* 0102f8b2 //C 0f8ba mvzl	r0,c_cmd_name */
0x0000f8bb, 0x0400f9ed, /* 0400f9ed //C 0f8bb call	streq */
0x0000f8bc, 0x21f2f8bf, /* 21f2f8bf //C 0f8bc jnz	find_cmd_very_false */
0x0000f8bd, 0x0122f950, /* 0122f950 //C 0f8bd mvzl	r2,cmd_c */
0x0000f8be, 0x01f2f8af, /* 01f2f8af //C 0f8be jmp	find_cmd_true */
0x0000f8bf, 0x020d0000, /* 020d0000 //C 0f8bf clc */
0x0000f8c0, 0x01020000, /* 01020000 //C 0f8c0 mvzl	r0,0 */
0x0000f8c1, 0x0fad0000, /* 0fad0000 //C 0f8c1 pop	r10 */
0x0000f8c2, 0x0f3d0000, /* 0f3d0000 //C 0f8c2 pop	r3 */
0x0000f8c3, 0x0f2d0000, /* 0f2d0000 //C 0f8c3 pop	r2 */
0x0000f8c4, 0x0f1d0000, /* 0f1d0000 //C 0f8c4 pop	r1 */
0x0000f8c5, 0x0fed0000, /* 0fed0000 //C 0f8c5 pop	lr */
0x0000f8c6, 0x00f00e00, /* 00f00e00 //C 0f8c6 ret */
0x0000f8c7, 0x0ded0000, /* 0ded0000 //C 0f8c7 push	lr */
0x0000f8c8, 0x0122fb10, /* 0122fb10 //C 0f8c8 mvzl	r2,words */
0x0000f8c9, 0x01020000, /* 01020000 //C 0f8c9 mvzl	r0,0 */
0x0000f8ca, 0x0e420001, /* 0e420001 //C 0f8ca ld	r4,r2,1		; addr */
0x0000f8cb, 0x0e520002, /* 0e520002 //C 0f8cb ld	r5,r2,2		; value */
0x0000f8cc, 0x024b0000, /* 024b0000 //C 0f8cc sz 	r4 */
0x0000f8cd, 0x11f2f8ee, /* 11f2f8ee //C 0f8cd jz	m_ret */
0x0000f8ce, 0x00000400, /* 00000400 //C 0f8ce mov	r0,r4 */
0x0000f8cf, 0x0400fa2f, /* 0400fa2f //C 0f8cf call	htoi */
0x0000f8d0, 0x00400100, /* 00400100 //C 0f8d0 mov	r4,r1 */
0x0000f8d1, 0x31f2f8d5, /* 31f2f8d5 //C 0f8d1 C1 jmp	m_addr_ok */
0x0000f8d2, 0x0102f8f0, /* 0102f8f0 //C 0f8d2 mvzl	r0,m_err_addr */
0x0000f8d3, 0x0400fa7b, /* 0400fa7b //C 0f8d3 call	printsnl */
0x0000f8d4, 0x01f2f8ee, /* 01f2f8ee //C 0f8d4 jmp	m_ret */
0x0000f8d5, 0x025b0000, /* 025b0000 //C 0f8d5 sz	r5 */
0x0000f8d6, 0x11f2f8e4, /* 11f2f8e4 //C 0f8d6 jz	m_read */
0x0000f8d7, 0x0148fc64, /* 0148fc64 //C 0f8d7 cmp	r4,the_end */
0x0000f8d8, 0x91f2f8dc, /* 91f2f8dc //C 0f8d8 HI jmp	m_addrv_ok */
0x0000f8d9, 0x0102f8fe, /* 0102f8fe //C 0f8d9 mvzl	r0,m_err_addrv */
0x0000f8da, 0x0400fa7b, /* 0400fa7b //C 0f8da call	printsnl */
0x0000f8db, 0x01f2f8ee, /* 01f2f8ee //C 0f8db jmp	m_ret */
0x0000f8dc, 0x00000500, /* 00000500 //C 0f8dc mov	r0,r5 */
0x0000f8dd, 0x0400fa2f, /* 0400fa2f //C 0f8dd call	htoi */
0x0000f8de, 0x00500100, /* 00500100 //C 0f8de mov	r5,r1 */
0x0000f8df, 0x31f2f8e3, /* 31f2f8e3 //C 0f8df C1 jmp	m_value_ok */
0x0000f8e0, 0x0102f910, /* 0102f910 //C 0f8e0 mvzl	r0,m_err_value */
0x0000f8e1, 0x0400fa7b, /* 0400fa7b //C 0f8e1 call	printsnl */
0x0000f8e2, 0x01f2f8ee, /* 01f2f8ee //C 0f8e2 jmp	m_ret */
0x0000f8e3, 0x0c540000, /* 0c540000 //C 0f8e3 st	r5,r4 */
0x0000f8e4, 0x00000400, /* 00000400 //C 0f8e4 mov	r0,r4 */
0x0000f8e5, 0x01120004, /* 01120004 //C 0f8e5 mvzl	r1,4 */
0x0000f8e6, 0x0400fa83, /* 0400fa83 //C 0f8e6 call	print_vhex */
0x0000f8e7, 0x01020020, /* 01020020 //C 0f8e7 mvzl	r0,0x20 */
0x0000f8e8, 0x0400fa5c, /* 0400fa5c //C 0f8e8 call	putchar */
0x0000f8e9, 0x0e040000, /* 0e040000 //C 0f8e9 ld	r0,r4 */
0x0000f8ea, 0x01120004, /* 01120004 //C 0f8ea mvzl	r1,4 */
0x0000f8eb, 0x0400fa83, /* 0400fa83 //C 0f8eb call	print_vhex */
0x0000f8ec, 0x0102000a, /* 0102000a //C 0f8ec mvzl	r0,LF */
0x0000f8ed, 0x0400fa5c, /* 0400fa5c //C 0f8ed call	putchar */
0x0000f8ee, 0x0fed0000, /* 0fed0000 //C 0f8ee pop	lr */
0x0000f8ef, 0x00f00e00, /* 00f00e00 //C 0f8ef ret */
0x0000f8f0, 0x00000041, /* 00000041 //C 0f8f0 db	65 */
0x0000f8f1, 0x00000064, /* 00000064 //C 0f8f1 db	100 */
0x0000f8f2, 0x00000064, /* 00000064 //C 0f8f2 db	100 */
0x0000f8f3, 0x00000072, /* 00000072 //C 0f8f3 db	114 */
0x0000f8f4, 0x00000065, /* 00000065 //C 0f8f4 db	101 */
0x0000f8f5, 0x00000073, /* 00000073 //C 0f8f5 db	115 */
0x0000f8f6, 0x00000073, /* 00000073 //C 0f8f6 db	115 */
0x0000f8f7, 0x00000020, /* 00000020 //C 0f8f7 db	32 */
0x0000f8f8, 0x00000065, /* 00000065 //C 0f8f8 db	101 */
0x0000f8f9, 0x00000072, /* 00000072 //C 0f8f9 db	114 */
0x0000f8fa, 0x00000072, /* 00000072 //C 0f8fa db	114 */
0x0000f8fb, 0x0000006f, /* 0000006f //C 0f8fb db	111 */
0x0000f8fc, 0x00000072, /* 00000072 //C 0f8fc db	114 */
0x0000f8fd, 0x00000000, /* 00000000 //C 0f8fd db */
0x0000f8fe, 0x0000004d, /* 0000004d //C 0f8fe db	77 */
0x0000f8ff, 0x0000006f, /* 0000006f //C 0f8ff db	111 */
0x0000f900, 0x0000006e, /* 0000006e //C 0f900 db	110 */
0x0000f901, 0x00000069, /* 00000069 //C 0f901 db	105 */
0x0000f902, 0x00000074, /* 00000074 //C 0f902 db	116 */
0x0000f903, 0x0000006f, /* 0000006f //C 0f903 db	111 */
0x0000f904, 0x00000072, /* 00000072 //C 0f904 db	114 */
0x0000f905, 0x00000027, /* 00000027 //C 0f905 db	39 */
0x0000f906, 0x00000073, /* 00000073 //C 0f906 db	115 */
0x0000f907, 0x00000020, /* 00000020 //C 0f907 db	32 */
0x0000f908, 0x00000061, /* 00000061 //C 0f908 db	97 */
0x0000f909, 0x00000064, /* 00000064 //C 0f909 db	100 */
0x0000f90a, 0x00000064, /* 00000064 //C 0f90a db	100 */
0x0000f90b, 0x00000072, /* 00000072 //C 0f90b db	114 */
0x0000f90c, 0x00000065, /* 00000065 //C 0f90c db	101 */
0x0000f90d, 0x00000073, /* 00000073 //C 0f90d db	115 */
0x0000f90e, 0x00000073, /* 00000073 //C 0f90e db	115 */
0x0000f90f, 0x00000000, /* 00000000 //C 0f90f db */
0x0000f910, 0x00000056, /* 00000056 //C 0f910 db	86 */
0x0000f911, 0x00000061, /* 00000061 //C 0f911 db	97 */
0x0000f912, 0x0000006c, /* 0000006c //C 0f912 db	108 */
0x0000f913, 0x00000075, /* 00000075 //C 0f913 db	117 */
0x0000f914, 0x00000065, /* 00000065 //C 0f914 db	101 */
0x0000f915, 0x00000020, /* 00000020 //C 0f915 db	32 */
0x0000f916, 0x00000065, /* 00000065 //C 0f916 db	101 */
0x0000f917, 0x00000072, /* 00000072 //C 0f917 db	114 */
0x0000f918, 0x00000072, /* 00000072 //C 0f918 db	114 */
0x0000f919, 0x0000006f, /* 0000006f //C 0f919 db	111 */
0x0000f91a, 0x00000072, /* 00000072 //C 0f91a db	114 */
0x0000f91b, 0x00000000, /* 00000000 //C 0f91b db */
0x0000f91c, 0x0ded0000, /* 0ded0000 //C 0f91c push	lr */
0x0000f91d, 0x0122fb10, /* 0122fb10 //C 0f91d mvzl	r2,words */
0x0000f91e, 0x0e020001, /* 0e020001 //C 0f91e ld	r0,r2,1		; start address */
0x0000f91f, 0x0400fa2f, /* 0400fa2f //C 0f91f call	htoi */
0x0000f920, 0x00300100, /* 00300100 //C 0f920 mov	r3,r1 */
0x0000f921, 0x0e020002, /* 0e020002 //C 0f921 ld	r0,r2,2		; end address */
0x0000f922, 0x020b0000, /* 020b0000 //C 0f922 sz	r0 */
0x0000f923, 0x21f2f927, /* 21f2f927 //C 0f923 jnz	d_end_ok */
0x0000f924, 0x00400300, /* 00400300 //C 0f924 mov	r4,r3 */
0x0000f925, 0x01440010, /* 01440010 //C 0f925 add	r4,0x10 */
0x0000f926, 0x01f2f929, /* 01f2f929 //C 0f926 jmp	d_chk_end */
0x0000f927, 0x0400fa2f, /* 0400fa2f //C 0f927 call	htoi */
0x0000f928, 0x00400100, /* 00400100 //C 0f928 mov	r4,r1 */
0x0000f929, 0x00380400, /* 00380400 //C 0f929 cmp	r3,r4		; check if start>end */
0x0000f92a, 0x91f2f939, /* 91f2f939 //C 0f92a HI jmp d_bad */
0x0000f92b, 0x00000300, /* 00000300 //C 0f92b mov	r0,r3		; print address */
0x0000f92c, 0x01120004, /* 01120004 //C 0f92c mvzl	r1,4 */
0x0000f92d, 0x0400fa83, /* 0400fa83 //C 0f92d call	print_vhex */
0x0000f92e, 0x01020020, /* 01020020 //C 0f92e mvzl	r0,0x20		; print one space */
0x0000f92f, 0x0400fa5c, /* 0400fa5c //C 0f92f call	putchar */
0x0000f930, 0x0e030000, /* 0e030000 //C 0f930 ld	r0,r3		; load data */
0x0000f931, 0x01120004, /* 01120004 //C 0f931 mvzl	r1,4		; print data */
0x0000f932, 0x0400fa83, /* 0400fa83 //C 0f932 call	print_vhex */
0x0000f933, 0x0102000a, /* 0102000a //C 0f933 mvzl	r0,LF		; print new line */
0x0000f934, 0x0400fa5c, /* 0400fa5c //C 0f934 call	putchar */
0x0000f935, 0x00380400, /* 00380400 //C 0f935 cmp	r3,r4 */
0x0000f936, 0x11f2f93b, /* 11f2f93b //C 0f936 jz	d_ret */
0x0000f937, 0x01340001, /* 01340001 //C 0f937 add	r3,1 */
0x0000f938, 0x01f2f92b, /* 01f2f92b //C 0f938 jmp	d_cyc */
0x0000f939, 0x0102f93d, /* 0102f93d //C 0f939 mvzl	r0,d_err_bad */
0x0000f93a, 0x0400fa7b, /* 0400fa7b //C 0f93a call	printsnl */
0x0000f93b, 0x0fed0000, /* 0fed0000 //C 0f93b pop	lr */
0x0000f93c, 0x00f00e00, /* 00f00e00 //C 0f93c ret */
0x0000f93d, 0x00000057, /* 00000057 //C 0f93d db	87 */
0x0000f93e, 0x00000072, /* 00000072 //C 0f93e db	114 */
0x0000f93f, 0x0000006f, /* 0000006f //C 0f93f db	111 */
0x0000f940, 0x0000006e, /* 0000006e //C 0f940 db	110 */
0x0000f941, 0x00000067, /* 00000067 //C 0f941 db	103 */
0x0000f942, 0x00000020, /* 00000020 //C 0f942 db	32 */
0x0000f943, 0x00000065, /* 00000065 //C 0f943 db	101 */
0x0000f944, 0x0000006e, /* 0000006e //C 0f944 db	110 */
0x0000f945, 0x00000064, /* 00000064 //C 0f945 db	100 */
0x0000f946, 0x00000020, /* 00000020 //C 0f946 db	32 */
0x0000f947, 0x00000061, /* 00000061 //C 0f947 db	97 */
0x0000f948, 0x00000064, /* 00000064 //C 0f948 db	100 */
0x0000f949, 0x00000064, /* 00000064 //C 0f949 db	100 */
0x0000f94a, 0x00000072, /* 00000072 //C 0f94a db	114 */
0x0000f94b, 0x00000065, /* 00000065 //C 0f94b db	101 */
0x0000f94c, 0x00000073, /* 00000073 //C 0f94c db	115 */
0x0000f94d, 0x00000073, /* 00000073 //C 0f94d db	115 */
0x0000f94e, 0x00000000, /* 00000000 //C 0f94e db */
0x0000f94f, 0x00f00e00, /* 00f00e00 //C 0f94f ret */
0x0000f950, 0x00f00e00, /* 00f00e00 //C 0f950 ret */
0x0000f951, 0x0ded0000, /* 0ded0000 //C 0f951 push	lr */
0x0000f952, 0x01a20000, /* 01a20000 //C 0f952 mvzl	r10,0		; state (nr of words) */
0x0000f953, 0x01820000, /* 01820000 //C 0f953 mvzl	r8,0		; value */
0x0000f954, 0x0162003f, /* 0162003f //C 0f954 mvzl	r6,'?'		; Record type */
0x0000f955, 0x0400fa51, /* 0400fa51 //C 0f955 call	check_uart */
0x0000f956, 0x41f2f955, /* 41f2f955 //C 0f956 C0 jmp	l_cyc */
0x0000f957, 0x0400fa59, /* 0400fa59 //C 0f957 call	read */
0x0000f958, 0x00b00000, /* 00b00000 //C 0f958 mov	r11,r0		; Copy of char in R11 */
0x0000f959, 0x0108000a, /* 0108000a //C 0f959 cmp	r0,10		; check EOL chars */
0x0000f95a, 0x11f2f99c, /* 11f2f99c //C 0f95a jz	l_eol */
0x0000f95b, 0x0108000d, /* 0108000d //C 0f95b cmp	r0,13 */
0x0000f95c, 0x11f2f99c, /* 11f2f99c //C 0f95c jz	l_eol */
0x0000f95d, 0x01a80000, /* 01a80000 //C 0f95d cmp	r10,0 */
0x0000f95e, 0x21f2f96c, /* 21f2f96c //C 0f95e jnz	l_no0 */
0x0000f95f, 0x0400f9fb, /* 0400f9fb //C 0f95f call	hexchar2value */
0x0000f960, 0x41f2f968, /* 41f2f968 //C 0f960 C0 jmp	l_eof_0 */
0x0000f961, 0x02880000, /* 02880000 //C 0f961 shl	r8		; shift val(char) into value */
0x0000f962, 0x02880000, /* 02880000 //C 0f962 shl	r8 */
0x0000f963, 0x02880000, /* 02880000 //C 0f963 shl	r8 */
0x0000f964, 0x02880000, /* 02880000 //C 0f964 shl	r8 */
0x0000f965, 0x010b000f, /* 010b000f //C 0f965 btst	r0,0xf */
0x0000f966, 0x008d0000, /* 008d0000 //C 0f966 or	r8,r0 */
0x0000f967, 0x01f2f955, /* 01f2f955 //C 0f967 jmp	l_cyc */
0x0000f968, 0x01a20001, /* 01a20001 //C 0f968 mvzl	r10,1		; state0 -> state1 */
0x0000f969, 0x0162003f, /* 0162003f //C 0f969 mvzl	r6,'?'		; No //C yet */
0x0000f96a, 0x01720000, /* 01720000 //C 0f96a mvzl	r7,0		; No '/' yet */
0x0000f96b, 0x01f2f955, /* 01f2f955 //C 0f96b jmp	l_cyc */
0x0000f96c, 0x01a80001, /* 01a80001 //C 0f96c cmp	r10,1 */
0x0000f96d, 0x21f2f983, /* 21f2f983 //C 0f96d jnz	l_no1 */
0x0000f96e, 0x027b0000, /* 027b0000 //C 0f96e sz	r7 */
0x0000f96f, 0x21f2f974, /* 21f2f974 //C 0f96f jnz	l_s1_2nd */
0x0000f970, 0x0108002f, /* 0108002f //C 0f970 cmp	r0,'/' */
0x0000f971, 0x21f2f955, /* 21f2f955 //C 0f971 jnz	l_cyc */
0x0000f972, 0x01720001, /* 01720001 //C 0f972 mvzl	r7,1 */
0x0000f973, 0x01f2f955, /* 01f2f955 //C 0f973 jmp	l_cyc */
0x0000f974, 0x0108002f, /* 0108002f //C 0f974 cmp	r0,'/' */
0x0000f975, 0x11f2f955, /* 11f2f955 //C 0f975 jz	l_cyc */
0x0000f976, 0x01080043, /* 01080043 //C 0f976 cmp	r0,'C' */
0x0000f977, 0x21f2f97d, /* 21f2f97d //C 0f977 jnz	l_s1_noC */
0x0000f978, 0x01620043, /* 01620043 //C 0f978 mvzl	r6,'C' */
0x0000f979, 0x01a20002, /* 01a20002 //C 0f979 mvzl	r10,2 */
0x0000f97a, 0x01920000, /* 01920000 //C 0f97a mvzl	r9,0		; address= 0 */
0x0000f97b, 0x01520000, /* 01520000 //C 0f97b mvzl	r5,0		; where we are in word: before */
0x0000f97c, 0x01f2f955, /* 01f2f955 //C 0f97c jmp	l_cyc */
0x0000f97d, 0x01080045, /* 01080045 //C 0f97d cmp	r0,'E' */
0x0000f97e, 0x21f2f982, /* 21f2f982 //C 0f97e jnz	l_s1_noE */
0x0000f97f, 0x01620045, /* 01620045 //C 0f97f mvzl	r6,'E' */
0x0000f980, 0x01a20003, /* 01a20003 //C 0f980 mvzl	r10,3 */
0x0000f981, 0x01f2f955, /* 01f2f955 //C 0f981 jmp	l_cyc */
0x0000f982, 0x01f2f955, /* 01f2f955 //C 0f982 jmp	l_cyc */
0x0000f983, 0x01a80002, /* 01a80002 //C 0f983 cmp	r10,2 */
0x0000f984, 0x21f2f998, /* 21f2f998 //C 0f984 jnz	l_no2 */
0x0000f985, 0x01580000, /* 01580000 //C 0f985 cmp	r5,0 */
0x0000f986, 0x21f2f991, /* 21f2f991 //C 0f986 jnz	l_s2_no0 */
0x0000f987, 0x0400f9fb, /* 0400f9fb //C 0f987 call	hexchar2value */
0x0000f988, 0x41f2f955, /* 41f2f955 //C 0f988 C0 jmp	l_cyc */
0x0000f989, 0x01520001, /* 01520001 //C 0f989 mvzl	r5,1 */
0x0000f98a, 0x02980000, /* 02980000 //C 0f98a shl	r9 */
0x0000f98b, 0x02980000, /* 02980000 //C 0f98b shl	r9 */
0x0000f98c, 0x02980000, /* 02980000 //C 0f98c shl	r9 */
0x0000f98d, 0x02980000, /* 02980000 //C 0f98d shl	r9 */
0x0000f98e, 0x010b000f, /* 010b000f //C 0f98e btst	r0,0xf */
0x0000f98f, 0x009d0000, /* 009d0000 //C 0f98f or	r9,r0 */
0x0000f990, 0x01f2f955, /* 01f2f955 //C 0f990 jmp	l_cyc */
0x0000f991, 0x01580001, /* 01580001 //C 0f991 cmp	r5,1 */
0x0000f992, 0x21f2f997, /* 21f2f997 //C 0f992 jnz	l_s2_no1 */
0x0000f993, 0x0400f9fb, /* 0400f9fb //C 0f993 call	hexchar2value */
0x0000f994, 0x31f2f98a, /* 31f2f98a //C 0f994 C1 jmp	l_s2_got */
0x0000f995, 0x01520002, /* 01520002 //C 0f995 mvzl	r5,2 */
0x0000f996, 0x01f2f955, /* 01f2f955 //C 0f996 jmp	l_cyc */
0x0000f997, 0x01f2f955, /* 01f2f955 //C 0f997 jmp	l_cyc */
0x0000f998, 0x01a80003, /* 01a80003 //C 0f998 cmp	r10,3 */
0x0000f999, 0x21f2f99b, /* 21f2f99b //C 0f999 jnz	l_no3 */
0x0000f99a, 0x01f2f955, /* 01f2f955 //C 0f99a jmp	l_cyc		; do nothing, just wait EOL */
0x0000f99b, 0x01f2f9ae, /* 01f2f9ae //C 0f99b jmp	l_ret */
0x0000f99c, 0x01a80000, /* 01a80000 //C 0f99c cmp	r10,0		; in state0 */
0x0000f99d, 0x11f2f955, /* 11f2f955 //C 0f99d jz	l_cyc		; just skip */
0x0000f99e, 0x01a80001, /* 01a80001 //C 0f99e cmp	r10,1		; in state1 */
0x0000f99f, 0x11f2f9a5, /* 11f2f9a5 //C 0f99f jz	l_bad		; garbage */
0x0000f9a0, 0x01a80002, /* 01a80002 //C 0f9a0 cmp	r10,2		; in state2 */
0x0000f9a1, 0x11f2f9a6, /* 11f2f9a6 //C 0f9a1 jz	l_proc		; process record */
0x0000f9a2, 0x01a80003, /* 01a80003 //C 0f9a2 cmp	r10,3		; in state3 */
0x0000f9a3, 0x11f2f9ae, /* 11f2f9ae //C 0f9a3 jz	l_ret		; eol in end record: finish */
0x0000f9a4, 0x01f2f955, /* 01f2f955 //C 0f9a4 jmp	l_cyc */
0x0000f9a5, 0x01f2f9ae, /* 01f2f9ae //C 0f9a5 jmp	l_ret */
0x0000f9a6, 0x01680043, /* 01680043 //C 0f9a6 cmp	r6,'C'		; is it a C record? */
0x0000f9a7, 0x1c890000, /* 1c890000 //C 0f9a7 z st	r8,r9		; store */
0x0000f9a8, 0x00000600, /* 00000600 //C 0f9a8 mov	r0,r6		; echo record type */
0x0000f9a9, 0x0400fa5c, /* 0400fa5c //C 0f9a9 call	putchar */
0x0000f9aa, 0x01a20000, /* 01a20000 //C 0f9aa mvzl	r10,0 */
0x0000f9ab, 0x01820000, /* 01820000 //C 0f9ab mvzl	r8,0 */
0x0000f9ac, 0x0162003f, /* 0162003f //C 0f9ac mvzl	r6,'?' */
0x0000f9ad, 0x01f2f955, /* 01f2f955 //C 0f9ad jmp	l_cyc */
0x0000f9ae, 0x0102000a, /* 0102000a //C 0f9ae mvzl	r0,LF */
0x0000f9af, 0x0400fa5c, /* 0400fa5c //C 0f9af call	putchar */
0x0000f9b0, 0x0fed0000, /* 0fed0000 //C 0f9b0 pop	lr */
0x0000f9b1, 0x00f00e00, /* 00f00e00 //C 0f9b1 ret */
0x0000f9b2, 0x0d1d0000, /* 0d1d0000 //C 0f9b2 push	r1 */
0x0000f9b3, 0x0d2d0000, /* 0d2d0000 //C 0f9b3 push	r2 */
0x0000f9b4, 0x0e210000, /* 0e210000 //C 0f9b4 ld	r2,r1 */
0x0000f9b5, 0x022b0000, /* 022b0000 //C 0f9b5 sz	r2 */
0x0000f9b6, 0x11f2f9bd, /* 11f2f9bd //C 0f9b6 jz	strchr_no	; eof string found */
0x0000f9b7, 0x00280000, /* 00280000 //C 0f9b7 cmp	r2,r0		; compare */
0x0000f9b8, 0x11f2f9bb, /* 11f2f9bb //C 0f9b8 jz	strchr_yes */
0x0000f9b9, 0x011a0001, /* 011a0001 //C 0f9b9 plus	r1,1		; go to next char */
0x0000f9ba, 0x01f2f9b4, /* 01f2f9b4 //C 0f9ba jmp	strchr_cyc */
0x0000f9bb, 0x020c0000, /* 020c0000 //C 0f9bb sec */
0x0000f9bc, 0x01f2f9bf, /* 01f2f9bf //C 0f9bc jmp	strchr_ret */
0x0000f9bd, 0x01120000, /* 01120000 //C 0f9bd mvzl	r1,0 */
0x0000f9be, 0x020d0000, /* 020d0000 //C 0f9be clc */
0x0000f9bf, 0x0f2d0000, /* 0f2d0000 //C 0f9bf pop	r2 */
0x0000f9c0, 0x0f1d0000, /* 0f1d0000 //C 0f9c0 pop	r1 */
0x0000f9c1, 0x00f00e00, /* 00f00e00 //C 0f9c1 ret */
0x0000f9c2, 0x0ded0000, /* 0ded0000 //C 0f9c2 push	lr		; Save used registers */
0x0000f9c3, 0x0d0d0000, /* 0d0d0000 //C 0f9c3 push	r0		; and input parameters */
0x0000f9c4, 0x0d1d0000, /* 0d1d0000 //C 0f9c4 push	r1 */
0x0000f9c5, 0x0d2d0000, /* 0d2d0000 //C 0f9c5 push	r2 */
0x0000f9c6, 0x0d4d0000, /* 0d4d0000 //C 0f9c6 push	r4 */
0x0000f9c7, 0x0d5d0000, /* 0d5d0000 //C 0f9c7 push	r5 */
0x0000f9c8, 0x0d6d0000, /* 0d6d0000 //C 0f9c8 push	r6 */
0x0000f9c9, 0x0e200000, /* 0e200000 //C 0f9c9 ld	r2,r0		; Got one-one char */
0x0000f9ca, 0x0e610000, /* 0e610000 //C 0f9ca ld	r6,r1		; from two strings */
0x0000f9cb, 0x023b0000, /* 023b0000 //C 0f9cb sz	r3		; Prepare for comparing */
0x0000f9cc, 0x112d0020, /* 112d0020 //C 0f9cc Z1 or	r2,0x20		; if insensitive case */
0x0000f9cd, 0x023b0000, /* 023b0000 //C 0f9cd sz	r3 */
0x0000f9ce, 0x116d0020, /* 116d0020 //C 0f9ce Z1 or	r6,0x20 */
0x0000f9cf, 0x00280600, /* 00280600 //C 0f9cf cmp	r2,r6		; compare them */
0x0000f9d0, 0x21f2f9e2, /* 21f2f9e2 //C 0f9d0 jnz	streq_no	; if differs: strings are not equal */
0x0000f9d1, 0x0e200000, /* 0e200000 //C 0f9d1 ld	r2,r0		; Pick original (non-prepared) */
0x0000f9d2, 0x0e610000, /* 0e610000 //C 0f9d2 ld	r6,r1		; chars to check EOS */
0x0000f9d3, 0x022b0000, /* 022b0000 //C 0f9d3 sz	r2		; convert them to boolean */
0x0000f9d4, 0x21220001, /* 21220001 //C 0f9d4 Z0 mvzl	r2,1		; values in R2,R6 */
0x0000f9d5, 0x11220000, /* 11220000 //C 0f9d5 Z1 mvzl	r2,0		; and copy in R4,R5 */
0x0000f9d6, 0x00400200, /* 00400200 //C 0f9d6 mov	r4,r2 */
0x0000f9d7, 0x026b0000, /* 026b0000 //C 0f9d7 sz	r6 */
0x0000f9d8, 0x21620001, /* 21620001 //C 0f9d8 Z0 mvzl	r6,1 */
0x0000f9d9, 0x11620000, /* 11620000 //C 0f9d9 Z1 mvzl r6,0 */
0x0000f9da, 0x00500600, /* 00500600 //C 0f9da mov	r5,r6 */
0x0000f9db, 0x004d0500, /* 004d0500 //C 0f9db or	r4,r5		; if both are EOS: equal */
0x0000f9dc, 0x11f2f9e4, /* 11f2f9e4 //C 0f9dc jz	streq_yes */
0x0000f9dd, 0x002f0600, /* 002f0600 //C 0f9dd and 	r2,r6		; just one is EOS: not equal */
0x0000f9de, 0x11f2f9e2, /* 11f2f9e2 //C 0f9de jz	streq_no */
0x0000f9df, 0x010a0001, /* 010a0001 //C 0f9df plus	r0,1		; non are EOS: go to check next char */
0x0000f9e0, 0x011a0001, /* 011a0001 //C 0f9e0 plus	r1,1 */
0x0000f9e1, 0x01f2f9c9, /* 01f2f9c9 //C 0f9e1 jmp	streq_cyc */
0x0000f9e2, 0x020d0000, /* 020d0000 //C 0f9e2 clc			; False result */
0x0000f9e3, 0x01f2f9e5, /* 01f2f9e5 //C 0f9e3 jmp	streq_ret */
0x0000f9e4, 0x020c0000, /* 020c0000 //C 0f9e4 sec			; True result */
0x0000f9e5, 0x0f6d0000, /* 0f6d0000 //C 0f9e5 pop	r6 */
0x0000f9e6, 0x0f5d0000, /* 0f5d0000 //C 0f9e6 pop	r5 */
0x0000f9e7, 0x0f4d0000, /* 0f4d0000 //C 0f9e7 pop	r4 */
0x0000f9e8, 0x0f2d0000, /* 0f2d0000 //C 0f9e8 pop	r2 */
0x0000f9e9, 0x0f1d0000, /* 0f1d0000 //C 0f9e9 pop	r1 */
0x0000f9ea, 0x0f0d0000, /* 0f0d0000 //C 0f9ea pop	r0 */
0x0000f9eb, 0x0fed0000, /* 0fed0000 //C 0f9eb pop	lr */
0x0000f9ec, 0x00f00e00, /* 00f00e00 //C 0f9ec ret */
0x0000f9ed, 0x0ded0000, /* 0ded0000 //C 0f9ed push	lr */
0x0000f9ee, 0x0d3d0000, /* 0d3d0000 //C 0f9ee push	r3 */
0x0000f9ef, 0x01320001, /* 01320001 //C 0f9ef mvzl	r3,1 */
0x0000f9f0, 0x0400f9c2, /* 0400f9c2 //C 0f9f0 call	str_cmp_eq */
0x0000f9f1, 0x0f3d0000, /* 0f3d0000 //C 0f9f1 pop	r3 */
0x0000f9f2, 0x0fed0000, /* 0fed0000 //C 0f9f2 pop	lr */
0x0000f9f3, 0x00f00e00, /* 00f00e00 //C 0f9f3 ret */
0x0000f9f4, 0x0ded0000, /* 0ded0000 //C 0f9f4 push	lr */
0x0000f9f5, 0x0d3d0000, /* 0d3d0000 //C 0f9f5 push	r3 */
0x0000f9f6, 0x01320000, /* 01320000 //C 0f9f6 mvzl	r3,0 */
0x0000f9f7, 0x0400f9c2, /* 0400f9c2 //C 0f9f7 call	str_cmp_eq */
0x0000f9f8, 0x0f3d0000, /* 0f3d0000 //C 0f9f8 pop	r3 */
0x0000f9f9, 0x0fed0000, /* 0fed0000 //C 0f9f9 pop	lr */
0x0000f9fa, 0x00f00e00, /* 00f00e00 //C 0f9fa ret */
0x0000f9fb, 0x0108002f, /* 0108002f //C 0f9fb cmp	r0,'/' */
0x0000f9fc, 0xa1f2fa11, /* a1f2fa11 //C 0f9fc LS jmp	hc2v_nok */
0x0000f9fd, 0x01080039, /* 01080039 //C 0f9fd cmp	r0,'9' */
0x0000f9fe, 0xa1f2fa0e, /* a1f2fa0e //C 0f9fe LS jmp	hc2v_0_9 */
0x0000f9ff, 0x01080040, /* 01080040 //C 0f9ff cmp	r0,'@' */
0x0000fa00, 0xa1f2fa11, /* a1f2fa11 //C 0fa00 LS jmp	hc2v_nok */
0x0000fa01, 0x01080046, /* 01080046 //C 0fa01 cmp	r0,'F' */
0x0000fa02, 0xa1f2fa0b, /* a1f2fa0b //C 0fa02 LS jmp	hc2v_A_F */
0x0000fa03, 0x01080060, /* 01080060 //C 0fa03 cmp	r0,'`' */
0x0000fa04, 0xa1f2fa11, /* a1f2fa11 //C 0fa04 LS jmp	hc2v_nok */
0x0000fa05, 0x01080066, /* 01080066 //C 0fa05 cmp	r0,'f' */
0x0000fa06, 0xa1f2fa08, /* a1f2fa08 //C 0fa06 LS jmp	hc2v_a_f */
0x0000fa07, 0x01f2fa11, /* 01f2fa11 //C 0fa07 jmp	hc2v_nok */
0x0000fa08, 0x0104000a, /* 0104000a //C 0fa08 add	r0,10 */
0x0000fa09, 0x01060061, /* 01060061 //C 0fa09 sub	r0,'a' */
0x0000fa0a, 0x01f2fa0f, /* 01f2fa0f //C 0fa0a jmp	hc2v_ok */
0x0000fa0b, 0x0104000a, /* 0104000a //C 0fa0b add	r0,10 */
0x0000fa0c, 0x01060041, /* 01060041 //C 0fa0c sub	r0,'A' */
0x0000fa0d, 0x01f2fa0f, /* 01f2fa0f //C 0fa0d jmp	hc2v_ok */
0x0000fa0e, 0x01060030, /* 01060030 //C 0fa0e sub	r0,'0' */
0x0000fa0f, 0x020c0000, /* 020c0000 //C 0fa0f sec */
0x0000fa10, 0x00f00e00, /* 00f00e00 //C 0fa10 ret */
0x0000fa11, 0x020d0000, /* 020d0000 //C 0fa11 clc */
0x0000fa12, 0x00f00e00, /* 00f00e00 //C 0fa12 ret */
0x0000fa13, 0x0d1d0000, /* 0d1d0000 //C 0fa13 push	r1 */
0x0000fa14, 0x010f000f, /* 010f000f //C 0fa14 and	r0,0xf */
0x0000fa15, 0x0112fa19, /* 0112fa19 //C 0fa15 mvzl	r1,v2hc_table */
0x0000fa16, 0x0a010000, /* 0a010000 //C 0fa16 ld	r0,r1,r0 */
0x0000fa17, 0x0f1d0000, /* 0f1d0000 //C 0fa17 pop	r1 */
0x0000fa18, 0x00f00e00, /* 00f00e00 //C 0fa18 ret */
0x0000fa19, 0x00000030, /* 00000030 //C 0fa19 db	48 */
0x0000fa1a, 0x00000031, /* 00000031 //C 0fa1a db	49 */
0x0000fa1b, 0x00000032, /* 00000032 //C 0fa1b db	50 */
0x0000fa1c, 0x00000033, /* 00000033 //C 0fa1c db	51 */
0x0000fa1d, 0x00000034, /* 00000034 //C 0fa1d db	52 */
0x0000fa1e, 0x00000035, /* 00000035 //C 0fa1e db	53 */
0x0000fa1f, 0x00000036, /* 00000036 //C 0fa1f db	54 */
0x0000fa20, 0x00000037, /* 00000037 //C 0fa20 db	55 */
0x0000fa21, 0x00000038, /* 00000038 //C 0fa21 db	56 */
0x0000fa22, 0x00000039, /* 00000039 //C 0fa22 db	57 */
0x0000fa23, 0x00000041, /* 00000041 //C 0fa23 db	65 */
0x0000fa24, 0x00000042, /* 00000042 //C 0fa24 db	66 */
0x0000fa25, 0x00000043, /* 00000043 //C 0fa25 db	67 */
0x0000fa26, 0x00000044, /* 00000044 //C 0fa26 db	68 */
0x0000fa27, 0x00000045, /* 00000045 //C 0fa27 db	69 */
0x0000fa28, 0x00000046, /* 00000046 //C 0fa28 db	70 */
0x0000fa29, 0x00000000, /* 00000000 //C 0fa29 db */
0x0000fa2a, 0x0ded0000, /* 0ded0000 //C 0fa2a push	lr */
0x0000fa2b, 0x0400fa13, /* 0400fa13 //C 0fa2b call	value2Hexchar */
0x0000fa2c, 0x010d0020, /* 010d0020 //C 0fa2c or	r0,0x20 */
0x0000fa2d, 0x0fed0000, /* 0fed0000 //C 0fa2d pop	lr */
0x0000fa2e, 0x00f00e00, /* 00f00e00 //C 0fa2e ret */
0x0000fa2f, 0x0ded0000, /* 0ded0000 //C 0fa2f push	lr */
0x0000fa30, 0x0d2d0000, /* 0d2d0000 //C 0fa30 push	r2 */
0x0000fa31, 0x0d3d0000, /* 0d3d0000 //C 0fa31 push	r3 */
0x0000fa32, 0x01120000, /* 01120000 //C 0fa32 mvzl	r1,0		; return value */
0x0000fa33, 0x01320000, /* 01320000 //C 0fa33 mvzl	r3,0		; index */
0x0000fa34, 0x0b238000, /* 0b238000 //C 0fa34 ld	r2,r3+,r0	; pick a char */
0x0000fa35, 0x022b0000, /* 022b0000 //C 0fa35 sz	r2		; check eof string */
0x0000fa36, 0x11f2fa4a, /* 11f2fa4a //C 0fa36 jz	htoi_eos */
0x0000fa37, 0x0128002e, /* 0128002e //C 0fa37 cmp	r2,'.'		; skip separators */
0x0000fa38, 0x11f2fa34, /* 11f2fa34 //C 0fa38 jz	htoi_cyc */
0x0000fa39, 0x0128005f, /* 0128005f //C 0fa39 cmp	r2,'_' */
0x0000fa3a, 0x11f2fa34, /* 11f2fa34 //C 0fa3a jz	htoi_cyc */
0x0000fa3b, 0x0d0d0000, /* 0d0d0000 //C 0fa3b push	r0 */
0x0000fa3c, 0x00000200, /* 00000200 //C 0fa3c mov	r0,r2 */
0x0000fa3d, 0x0400f9fb, /* 0400f9fb //C 0fa3d call	hexchar2value */
0x0000fa3e, 0x00200000, /* 00200000 //C 0fa3e mov	r2,r0 */
0x0000fa3f, 0x0f0d0000, /* 0f0d0000 //C 0fa3f pop	r0 */
0x0000fa40, 0x41f2fa48, /* 41f2fa48 //C 0fa40 C0 jmp	htoi_nok */
0x0000fa41, 0x02180000, /* 02180000 //C 0fa41 shl	r1 */
0x0000fa42, 0x02180000, /* 02180000 //C 0fa42 shl	r1 */
0x0000fa43, 0x02180000, /* 02180000 //C 0fa43 shl	r1 */
0x0000fa44, 0x02180000, /* 02180000 //C 0fa44 shl	r1 */
0x0000fa45, 0x012f000f, /* 012f000f //C 0fa45 and	r2,0xf */
0x0000fa46, 0x001d0200, /* 001d0200 //C 0fa46 or	r1,r2 */
0x0000fa47, 0x01f2fa34, /* 01f2fa34 //C 0fa47 jmp	htoi_cyc */
0x0000fa48, 0x020d0000, /* 020d0000 //C 0fa48 clc */
0x0000fa49, 0x01f2fa4d, /* 01f2fa4d //C 0fa49 jmp	htoi_ret */
0x0000fa4a, 0x01380001, /* 01380001 //C 0fa4a cmp	r3,1 */
0x0000fa4b, 0x920d0000, /* 920d0000 //C 0fa4b HI clc */
0x0000fa4c, 0xa20c0000, /* a20c0000 //C 0fa4c LS sec */
0x0000fa4d, 0x0f3d0000, /* 0f3d0000 //C 0fa4d pop	r3 */
0x0000fa4e, 0x0f2d0000, /* 0f2d0000 //C 0fa4e pop	r2 */
0x0000fa4f, 0x0fed0000, /* 0fed0000 //C 0fa4f pop	lr */
0x0000fa50, 0x00f00e00, /* 00f00e00 //C 0fa50 ret */
0x0000fa51, 0x0d0d0000, /* 0d0d0000 //C 0fa51 push	r0 */
0x0000fa52, 0x0102ff42, /* 0102ff42 //C 0fa52 mvzl	r0,UART_RSTAT */
0x0000fa53, 0x0e000000, /* 0e000000 //C 0fa53 ld	r0,r0 */
0x0000fa54, 0x010c0001, /* 010c0001 //C 0fa54 test	r0,1 */
0x0000fa55, 0x020d0000, /* 020d0000 //C 0fa55 clc */
0x0000fa56, 0x220c0000, /* 220c0000 //C 0fa56 Z0 sec */
0x0000fa57, 0x0f0d0000, /* 0f0d0000 //C 0fa57 pop	r0 */
0x0000fa58, 0x00f00e00, /* 00f00e00 //C 0fa58 ret */
0x0000fa59, 0x0102ff40, /* 0102ff40 //C 0fa59 mvzl	r0,UART_DR */
0x0000fa5a, 0x0e000000, /* 0e000000 //C 0fa5a ld	r0,r0 */
0x0000fa5b, 0x00f00e00, /* 00f00e00 //C 0fa5b ret */
0x0000fa5c, 0x0d2d0000, /* 0d2d0000 //C 0fa5c push	r2 */
0x0000fa5d, 0x0d9d0000, /* 0d9d0000 //C 0fa5d push	r9 */
0x0000fa5e, 0x0122ff43, /* 0122ff43 //C 0fa5e mvzl	r2,UART_TSTAT */
0x0000fa5f, 0x0e920000, /* 0e920000 //C 0fa5f ld	r9,r2 */
0x0000fa60, 0x019c0001, /* 019c0001 //C 0fa60 test	r9,1 */
0x0000fa61, 0x11f2fa5f, /* 11f2fa5f //C 0fa61 jz	wait_tc */
0x0000fa62, 0x0122ff40, /* 0122ff40 //C 0fa62 mvzl	r2,UART_DR */
0x0000fa63, 0x0c020000, /* 0c020000 //C 0fa63 st	r0,r2 */
0x0000fa64, 0x0f9d0000, /* 0f9d0000 //C 0fa64 pop	r9 */
0x0000fa65, 0x0f2d0000, /* 0f2d0000 //C 0fa65 pop	r2 */
0x0000fa66, 0x00f00e00, /* 00f00e00 //C 0fa66 ret */
0x0000fa67, 0x0ded0000, /* 0ded0000 //C 0fa67 push	lr */
0x0000fa68, 0x0d0d0000, /* 0d0d0000 //C 0fa68 push	r0 */
0x0000fa69, 0x0d3d0000, /* 0d3d0000 //C 0fa69 push	r3 */
0x0000fa6a, 0x0d4d0000, /* 0d4d0000 //C 0fa6a push	r4 */
0x0000fa6b, 0x01420000, /* 01420000 //C 0fa6b mvzl	r4,0 */
0x0000fa6c, 0x020b0000, /* 020b0000 //C 0fa6c sz	r0 */
0x0000fa6d, 0x1102fb2f, /* 1102fb2f //C 0fa6d Z1 mvzl	r0,null_str */
0x0000fa6e, 0x0b348000, /* 0b348000 //C 0fa6e ld	r3,r4+,r0 */
0x0000fa6f, 0x023b0000, /* 023b0000 //C 0fa6f sz	r3 */
0x0000fa70, 0x11f2fa76, /* 11f2fa76 //C 0fa70 jz	prints_done */
0x0000fa71, 0x0d0d0000, /* 0d0d0000 //C 0fa71 push	r0 */
0x0000fa72, 0x00000300, /* 00000300 //C 0fa72 mov	r0,r3 */
0x0000fa73, 0x0400fa5c, /* 0400fa5c //C 0fa73 call	putchar */
0x0000fa74, 0x0f0d0000, /* 0f0d0000 //C 0fa74 pop	r0 */
0x0000fa75, 0x01f2fa6e, /* 01f2fa6e //C 0fa75 jmp	prints_go */
0x0000fa76, 0x0f4d0000, /* 0f4d0000 //C 0fa76 pop	r4 */
0x0000fa77, 0x0f3d0000, /* 0f3d0000 //C 0fa77 pop	r3 */
0x0000fa78, 0x0f0d0000, /* 0f0d0000 //C 0fa78 pop	r0 */
0x0000fa79, 0x0fed0000, /* 0fed0000 //C 0fa79 pop	lr */
0x0000fa7a, 0x00f00e00, /* 00f00e00 //C 0fa7a ret */
0x0000fa7b, 0x0ded0000, /* 0ded0000 //C 0fa7b push	lr */
0x0000fa7c, 0x0400fa67, /* 0400fa67 //C 0fa7c call	prints */
0x0000fa7d, 0x0d0d0000, /* 0d0d0000 //C 0fa7d push	r0 */
0x0000fa7e, 0x0102000a, /* 0102000a //C 0fa7e mvzl	r0,LF */
0x0000fa7f, 0x0400fa5c, /* 0400fa5c //C 0fa7f call	putchar */
0x0000fa80, 0x0f0d0000, /* 0f0d0000 //C 0fa80 pop	r0 */
0x0000fa81, 0x0fed0000, /* 0fed0000 //C 0fa81 pop	lr */
0x0000fa82, 0x00f00e00, /* 00f00e00 //C 0fa82 ret */
0x0000fa83, 0x0ded0000, /* 0ded0000 //C 0fa83 push	lr */
0x0000fa84, 0x0d0d0000, /* 0d0d0000 //C 0fa84 push	r0 */
0x0000fa85, 0x0d1d0000, /* 0d1d0000 //C 0fa85 push	r1 */
0x0000fa86, 0x0d2d0000, /* 0d2d0000 //C 0fa86 push	r2 */
0x0000fa87, 0x0d3d0000, /* 0d3d0000 //C 0fa87 push	r3 */
0x0000fa88, 0x0d4d0000, /* 0d4d0000 //C 0fa88 push	r4 */
0x0000fa89, 0x00300000, /* 00300000 //C 0fa89 mov	r3,r0 */
0x0000fa8a, 0x01220000, /* 01220000 //C 0fa8a mvzl	r2,0 */
0x0000fa8b, 0x01420001, /* 01420001 //C 0fa8b mvzl	r4,1 */
0x0000fa8c, 0x01020000, /* 01020000 //C 0fa8c mvzl	r0,0 */
0x0000fa8d, 0x02380000, /* 02380000 //C 0fa8d shl	r3 */
0x0000fa8e, 0x02070000, /* 02070000 //C 0fa8e rol	r0 */
0x0000fa8f, 0x02380000, /* 02380000 //C 0fa8f shl	r3 */
0x0000fa90, 0x02070000, /* 02070000 //C 0fa90 rol	r0 */
0x0000fa91, 0x02380000, /* 02380000 //C 0fa91 shl	r3 */
0x0000fa92, 0x02070000, /* 02070000 //C 0fa92 rol	r0 */
0x0000fa93, 0x02380000, /* 02380000 //C 0fa93 shl	r3 */
0x0000fa94, 0x02070000, /* 02070000 //C 0fa94 rol	r0 */
0x0000fa95, 0x0400fa13, /* 0400fa13 //C 0fa95 call	value2Hexchar */
0x0000fa96, 0x0400fa5c, /* 0400fa5c //C 0fa96 call	putchar */
0x0000fa97, 0x01240001, /* 01240001 //C 0fa97 add	r2,1 */
0x0000fa98, 0x01280008, /* 01280008 //C 0fa98 cmp	r2,8 */
0x0000fa99, 0x11f2faa3, /* 11f2faa3 //C 0fa99 jz	print_vhex_ret */
0x0000fa9a, 0x021b0000, /* 021b0000 //C 0fa9a sz	r1 */
0x0000fa9b, 0x11f2faa1, /* 11f2faa1 //C 0fa9b jz	print_vhex_nosep */
0x0000fa9c, 0x00480100, /* 00480100 //C 0fa9c cmp	r4,r1 */
0x0000fa9d, 0x21f2faa1, /* 21f2faa1 //C 0fa9d jnz	print_vhex_nosep */
0x0000fa9e, 0x0102005f, /* 0102005f //C 0fa9e mvzl	r0,'_' */
0x0000fa9f, 0x0400fa5c, /* 0400fa5c //C 0fa9f call	putchar */
0x0000faa0, 0x01420000, /* 01420000 //C 0faa0 mvzl	r4,0 */
0x0000faa1, 0x01440001, /* 01440001 //C 0faa1 add	r4,1 */
0x0000faa2, 0x01f2fa8c, /* 01f2fa8c //C 0faa2 jmp	print_vhex_cyc */
0x0000faa3, 0x0f4d0000, /* 0f4d0000 //C 0faa3 pop	r4 */
0x0000faa4, 0x0f3d0000, /* 0f3d0000 //C 0faa4 pop	r3 */
0x0000faa5, 0x0f2d0000, /* 0f2d0000 //C 0faa5 pop	r2 */
0x0000faa6, 0x0f1d0000, /* 0f1d0000 //C 0faa6 pop	r1 */
0x0000faa7, 0x0f0d0000, /* 0f0d0000 //C 0faa7 pop	r0 */
0x0000faa8, 0x0fed0000, /* 0fed0000 //C 0faa8 pop	lr */
0x0000faa9, 0x00f00e00, /* 00f00e00 //C 0faa9 ret */
0x0000fb16, 0x00000050, /* 00000050 //C 0fb16 db	80 */
0x0000fb17, 0x0000004d, /* 0000004d //C 0fb17 db	77 */
0x0000fb18, 0x0000006f, /* 0000006f //C 0fb18 db	111 */
0x0000fb19, 0x0000006e, /* 0000006e //C 0fb19 db	110 */
0x0000fb1a, 0x00000069, /* 00000069 //C 0fb1a db	105 */
0x0000fb1b, 0x00000074, /* 00000074 //C 0fb1b db	116 */
0x0000fb1c, 0x0000006f, /* 0000006f //C 0fb1c db	111 */
0x0000fb1d, 0x00000072, /* 00000072 //C 0fb1d db	114 */
0x0000fb1e, 0x00000020, /* 00000020 //C 0fb1e db	32 */
0x0000fb1f, 0x00000076, /* 00000076 //C 0fb1f db	118 */
0x0000fb20, 0x00000031, /* 00000031 //C 0fb20 db	49 */
0x0000fb21, 0x0000002e, /* 0000002e //C 0fb21 db	46 */
0x0000fb22, 0x00000030, /* 00000030 //C 0fb22 db	48 */
0x0000fb23, 0x00000000, /* 00000000 //C 0fb23 db */
0x0000fb24, 0x0000003e, /* 0000003e //C 0fb24 db	62 */
0x0000fb25, 0x00000000, /* 00000000 //C 0fb25 db */
0x0000fb26, 0x00000020, /* 00000020 //C 0fb26 db	32 */
0x0000fb27, 0x0000003b, /* 0000003b //C 0fb27 db	59 */
0x0000fb28, 0x00000009, /* 00000009 //C 0fb28 db	9 */
0x0000fb29, 0x0000000b, /* 0000000b //C 0fb29 db	11 */
0x0000fb2a, 0x0000002c, /* 0000002c //C 0fb2a db	44 */
0x0000fb2b, 0x0000003d, /* 0000003d //C 0fb2b db	61 */
0x0000fb2c, 0x0000005b, /* 0000005b //C 0fb2c db	91 */
0x0000fb2d, 0x0000005d, /* 0000005d //C 0fb2d db	93 */
0x0000fb2e, 0x00000000, /* 00000000 //C 0fb2e db */
0x0000fb2f, 0x00000028, /* 00000028 //C 0fb2f db	40 */
0x0000fb30, 0x0000006e, /* 0000006e //C 0fb30 db	110 */
0x0000fb31, 0x00000075, /* 00000075 //C 0fb31 db	117 */
0x0000fb32, 0x0000006c, /* 0000006c //C 0fb32 db	108 */
0x0000fb33, 0x0000006c, /* 0000006c //C 0fb33 db	108 */
0x0000fb34, 0x00000029, /* 00000029 //C 0fb34 db	41 */
0x0000fb35, 0x00000000, /* 00000000 //C 0fb35 db */
0x0000fb36, 0x0000f8c7, /* 0000f8c7 //C 0fb36 dd	cmd_m */
0x0000fb37, 0x0000006d, /* 0000006d //C 0fb37 db	109 */
0x0000fb38, 0x00000000, /* 00000000 //C 0fb38 db */
0x0000fb39, 0x0000f8c7, /* 0000f8c7 //C 0fb39 dd	cmd_m */
0x0000fb3a, 0x0000006d, /* 0000006d //C 0fb3a db	109 */
0x0000fb3b, 0x00000065, /* 00000065 //C 0fb3b db	101 */
0x0000fb3c, 0x0000006d, /* 0000006d //C 0fb3c db	109 */
0x0000fb3d, 0x00000000, /* 00000000 //C 0fb3d db */
0x0000fb3e, 0x0000f91c, /* 0000f91c //C 0fb3e dd	cmd_d */
0x0000fb3f, 0x00000064, /* 00000064 //C 0fb3f db	100 */
0x0000fb40, 0x00000000, /* 00000000 //C 0fb40 db */
0x0000fb41, 0x0000f91c, /* 0000f91c //C 0fb41 dd	cmd_d */
0x0000fb42, 0x00000064, /* 00000064 //C 0fb42 db	100 */
0x0000fb43, 0x00000075, /* 00000075 //C 0fb43 db	117 */
0x0000fb44, 0x0000006d, /* 0000006d //C 0fb44 db	109 */
0x0000fb45, 0x00000070, /* 00000070 //C 0fb45 db	112 */
0x0000fb46, 0x00000000, /* 00000000 //C 0fb46 db */
0x0000fb47, 0x0000f94f, /* 0000f94f //C 0fb47 dd	cmd_e */
0x0000fb48, 0x00000065, /* 00000065 //C 0fb48 db	101 */
0x0000fb49, 0x00000000, /* 00000000 //C 0fb49 db */
0x0000fb4a, 0x0000f951, /* 0000f951 //C 0fb4a dd	cmd_l */
0x0000fb4b, 0x0000006c, /* 0000006c //C 0fb4b db	108 */
0x0000fb4c, 0x00000000, /* 00000000 //C 0fb4c db */
0x0000fb4d, 0x0000f951, /* 0000f951 //C 0fb4d dd	cmd_l */
0x0000fb4e, 0x0000006c, /* 0000006c //C 0fb4e db	108 */
0x0000fb4f, 0x0000006f, /* 0000006f //C 0fb4f db	111 */
0x0000fb50, 0x00000061, /* 00000061 //C 0fb50 db	97 */
0x0000fb51, 0x00000064, /* 00000064 //C 0fb51 db	100 */
0x0000fb52, 0x00000000, /* 00000000 //C 0fb52 db */
0x0000fb53, 0x00000000, /* 00000000 //C 0fb53 dd	0 */
0x0000fb54, 0x00000000, /* 00000000 //C 0fb54 db	0 */
0x0000fc56, 0x00000045, /* 00000045 //C 0fc56 db	69 */
0x0000fc57, 0x0000004f, /* 0000004f //C 0fc57 db	79 */
0x0000fc58, 0x00000046, /* 00000046 //C 0fc58 db	70 */
0x0000fc59, 0x00000020, /* 00000020 //C 0fc59 db	32 */
0x0000fc5a, 0x00000050, /* 00000050 //C 0fc5a db	80 */
0x0000fc5b, 0x0000004d, /* 0000004d //C 0fc5b db	77 */
0x0000fc5c, 0x0000006f, /* 0000006f //C 0fc5c db	111 */
0x0000fc5d, 0x0000006e, /* 0000006e //C 0fc5d db	110 */
0x0000fc5e, 0x00000069, /* 00000069 //C 0fc5e db	105 */
0x0000fc5f, 0x00000074, /* 00000074 //C 0fc5f db	116 */
0x0000fc60, 0x0000006f, /* 0000006f //C 0fc60 db	111 */
0x0000fc61, 0x00000072, /* 00000072 //C 0fc61 db	114 */
0x0000fc62, 0x0000000a, /* 0000000a //C 0fc62 db	10 */
0x0000fc63, 0x00000000, /* 00000000 //C 0fc63 db */
0xffffffff, 0xffffffff
};
