/*
 * Simulator of microcontrollers (glob.cc)
 *
 * Copyright (C) 2020,20 Drotos Daniel, Talker Bt.
 * 
 * To contact author send email to drdani@mazsola.iit.uni-miskolc.hu
 *
 */

/* This file is part of microcontroller simulator: ucsim.

UCSIM is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

UCSIM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with UCSIM; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA. */
/*@1@*/

#include <stdio.h>

#include "glob.h"


struct dis_entry disass_p1516[]=
  {
   { 0x08000000, 0x08000000, 'c', 1, "call  %A", false },

   { 0xb4f00000, 0xfff00000, 'M', 1, "jz    %O", false },
   { 0x94f00000, 0xfff00000, 'M', 1, "jnz   %O", false },
   { 0x74f00000, 0xfff00000, 'M', 1, "jc    %O", false },
   { 0x54f00000, 0xfff00000, 'M', 1, "jnc   %O", false },
   { 0x04f00000, 0x1ff00000, 'M', 1, "jmp   %O", false },
   { 0x04f00000, 0x0ff00000, ' ', 1, "jump  %O", false },

   { 0x00000000, 0x0f000000, ' ', 1, "nop", false },
   { 0x01000000, 0x0f000000, ' ', 1, "ld    %d:=mem[%R]", false },
   { 0x02000000, 0x0f000000, ' ', 1, "st    mem[%R]:=%d", false },
   { 0x03fe0000, 0x0fff0000, ' ', 1, "ret", false },
   { 0x03000000, 0x0f000000, ' ', 1, "mov   %d:=%a", false },
   { 0x04000000, 0x0f000000, ' ', 1, "ldl0  %d:=%0", false },
   { 0x05000000, 0x0f000000, ' ', 1, "ldl   %d:=%l", false },
   { 0x06000000, 0x0f000000, ' ', 1, "ldh   %d:=%h", false },

   { 0x07000000, 0x0f000f80, ' ', 1, "add   %d:=%a+%b", false },
   { 0x07000080, 0x0f000f80, ' ', 1, "addc  %d:=%a+%b", false },
   { 0x07000100, 0x0f000f80, ' ', 1, "sub   %d:=%a-%b", false },
   { 0x07000180, 0x0f000f80, ' ', 1, "sbb   %d:=%a-%b", false },
   { 0x07000200, 0x0f000f80, ' ', 1, "inc   %d:=%a+1", false },
   { 0x07000280, 0x0f000f80, ' ', 1, "dec   %d:=%a-1", false },
   { 0x07000300, 0x0f000f80, ' ', 1, "and   %d:=%a&%b", false },
   { 0x07000380, 0x0f000f80, ' ', 1, "or    %d:=%a|%b", false },
   { 0x07000400, 0x0f000f80, ' ', 1, "xor   %d:=%a^%b", false },
   { 0x07000480, 0x0f000f80, ' ', 1, "shl   %d:=u(%a)<<1", false },
   { 0x07000500, 0x0f000f80, ' ', 1, "shr   %d:=u(%a)>>1", false },
   { 0x07000800, 0x0f000f80, ' ', 1, "sha   %d:=s(%a)>>1", false },
   { 0x07000580, 0x0f000f80, ' ', 1, "rol   %d:=(C,%a)<<1", false },
   { 0x07000600, 0x0f000f80, ' ', 1, "ror   %d:=(%a,C)>>1", false },
   { 0x07000680, 0x0f000f80, ' ', 1, "mul   %d:=%a*%b", false },
   { 0x07000700, 0x0f000f80, ' ', 1, "div   %d:=%a/%b", false },
   { 0x07000780, 0x0f000f80, ' ', 1, "cmp   F:=%a-%b", false },
   { 0x07000880, 0x0f000f80, ' ', 1, "setc", false },
   { 0x07000900, 0x0f000f80, ' ', 1, "clrc", false },
   
   { 0, 0, 0, 0, 0, 0 }
  };

struct dis_entry disass_p2223[]=
  {
   { 0x00000000, 0x0fffffff, ' ', 1, "nop", false },

   { 0x04000000, 0x0f008000, ' ', 1, "st mem[%a,%b]:=%d", false },
   { 0x04008000, 0x0f00e000, ' ', 1, "st mem[%a-,%b]:=%d", false },
   { 0x0400a000, 0x0f00e000, ' ', 1, "st mem[-%a,%b]:=%d", false },
   { 0x0400c000, 0x0f00e000, ' ', 1, "st mem[%a+,%b]:=%d", false },
   { 0x0400e000, 0x0f00e000, ' ', 1, "st mem[+%a,%b]:=%d", false },

   { 0x05000000, 0x0f008000, ' ', 1, "ld %d:=mem[%a,%b]", false },
   { 0x05008000, 0x0f00e000, ' ', 1, "ld %d:=mem[%a-,%b]", false },
   { 0x0500a000, 0x0f00e000, ' ', 1, "ld %d:=mem[-%a,%b]", false },
   { 0x0500c000, 0x0f00e000, ' ', 1, "ld %d:=mem[%a+,%b]", false },
   { 0x0500e000, 0x0f00e000, ' ', 1, "ld %d:=mem[+%a,%b]", false },

   { 0x0c000000, 0x0c000000, ' ', 1, "call 's20'", false },
   { 0x08000000, 0x0c000000, ' ', 1, "call 'ar'", false },

   { 0x02000000, 0x0f0f0000, ' ', 1, "mov %d:=%b", false },
   { 0x02040000, 0x0f0f0000, ' ', 1, "add %d:=%d+%b", false },
   { 0x02050000, 0x0f0f0000, ' ', 1, "adc %d:=%d+%b", false },
   { 0x02060000, 0x0f0f0000, ' ', 1, "sub %d:=%d-%b", false },
   { 0x02070000, 0x0f0f0000, ' ', 1, "sbb %d:=%d-%b", false },
   { 0x02080000, 0x0f0f0000, ' ', 1, "cmp F:=%d-%b", false },
   { 0x02090000, 0x0f0f0000, ' ', 1, "mul %d:=%d*%b", false },
   { 0x020a0000, 0x0f0f0000, ' ', 1, "and %d:=%d&%b", false },
   { 0x020b0000, 0x0f0f0000, ' ', 1, "or %d:=%d&%b", false },
   { 0x020c0000, 0x0f0f0000, ' ', 1, "xor %d:=%d^%b", false },
   { 0x020d0000, 0x0f0f0000, ' ', 1, "plus %d:=%d+%b", false },
   { 0x020e0000, 0x0f0f0000, ' ', 1, "test F:=%d&~%b", false },
     
   { 0, 0, 0, 0, 0, 0 }
  };

struct cpu_entry cpus_p1516[]=
  {
    { "P1516"		, CPU_P1516, 0, "P1516", "" },
    { "1"		, CPU_P1516, 0, "P1516", "" },
    { "5"		, CPU_P1516, 0, "P1516", "" },
    { "6"		, CPU_P1516, 0, "P1516", "" },
    { "P2223"		, CPU_P2223, 0, "P2223", "" },
    { "2"		, CPU_P2223, 0, "P2223", "" },
    { "3"		, CPU_P2223, 0, "P2223", "" },

    {NULL, CPU_NONE, 0, "", ""}
  };

/* End of p1516.src/glob.cc */
