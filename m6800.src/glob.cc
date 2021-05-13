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

#include "glob.h"


instruction_wrapper_fn itab[256];

// code mask branch len mn call tick
struct dis_entry disass_m6800[]=
  {
    { 0x01, 0xff, ' ', 1, "NOP" },
    { 0x06, 0xff, ' ', 1, "TAP" },
    { 0x07, 0xff, ' ', 1, "TAP" },
    { 0x08, 0xff, ' ', 1, "INX" },
    { 0x09, 0xff, ' ', 1, "DEX" },
    { 0x0a, 0xff, ' ', 1, "CLV" },
    { 0x0b, 0xff, ' ', 1, "SEV" },
    { 0x0c, 0xff, ' ', 1, "CLC" },
    { 0x0d, 0xff, ' ', 1, "SEC" },
    { 0x0e, 0xff, ' ', 1, "CLI" },
    { 0x0f, 0xff, ' ', 1, "SEI" },

    { 0x10, 0xff, ' ', 1, "SBA" },
    { 0x11, 0xff, ' ', 1, "CBA" },
    { 0x16, 0xff, ' ', 1, "TAB" },
    { 0x17, 0xff, ' ', 1, "TBA" },
    { 0x19, 0xff, ' ', 1, "DAA" },
    { 0x1b, 0xff, ' ', 1, "ABA" },

    { 0x30, 0xff, ' ', 1, "TSX" },
    { 0x31, 0xff, ' ', 1, "INS" },
    { 0x32, 0xff, ' ', 1, "PUL A" },
    { 0x33, 0xff, ' ', 1, "PUL B" },
    { 0x34, 0xff, ' ', 1, "DES" },
    { 0x35, 0xff, ' ', 1, "TXS" },
    { 0x36, 0xff, ' ', 1, "PSH A" },
    { 0x37, 0xff, ' ', 1, "PSH B" },
    { 0x39, 0xff, ' ', 1, "RTS" },

    { 0x40, 0xff, ' ', 1, "NEG A" },
    { 0x43, 0xff, ' ', 1, "COM A" },
    { 0x44, 0xff, ' ', 1, "LSR A" },
    { 0x46, 0xff, ' ', 1, "ROR A" },
    { 0x47, 0xff, ' ', 1, "ASR A" },
    { 0x48, 0xff, ' ', 1, "ASL A" },
    { 0x49, 0xff, ' ', 1, "ROL A" },
    { 0x4a, 0xff, ' ', 1, "DEC A" },
    { 0x4c, 0xff, ' ', 1, "INC A" },
    { 0x4d, 0xff, ' ', 1, "TST A" },
    { 0x4f, 0xff, ' ', 1, "CLR A" },
    
    { 0x50, 0xff, ' ', 1, "NEG B" },
    { 0x53, 0xff, ' ', 1, "COM B" },
    { 0x54, 0xff, ' ', 1, "LSR B" },
    { 0x56, 0xff, ' ', 1, "ROR B" },
    { 0x57, 0xff, ' ', 1, "ASR B" },
    { 0x58, 0xff, ' ', 1, "ASL B" },
    { 0x59, 0xff, ' ', 1, "ROL B" },
    { 0x5a, 0xff, ' ', 1, "DEC B" },
    { 0x5c, 0xff, ' ', 1, "INC B" },
    { 0x5d, 0xff, ' ', 1, "TST B" },
    { 0x5f, 0xff, ' ', 1, "CLR B" },
    
    { 0x60, 0xff, ' ', 2, "NEG %x" },
    { 0x63, 0xff, ' ', 2, "COM %x" },
    { 0x64, 0xff, ' ', 2, "LSR %x" },
    { 0x66, 0xff, ' ', 2, "ROR %x" },
    { 0x67, 0xff, ' ', 2, "ASR %x" },
    { 0x68, 0xff, ' ', 2, "ASL %x" },
    { 0x69, 0xff, ' ', 2, "ROL %x" },
    { 0x6a, 0xff, ' ', 2, "DEC %x" },
    { 0x6c, 0xff, ' ', 2, "INC %x" },
    { 0x6d, 0xff, ' ', 2, "TST %x" },
    { 0x6e, 0xff, ' ', 2, "JMP %x" },
    { 0x6f, 0xff, ' ', 2, "CLR %x" },
    
    { 0x70, 0xff, ' ', 3, "NEG %e" },
    { 0x73, 0xff, ' ', 3, "COM %e" },
    { 0x74, 0xff, ' ', 3, "LSR %e" },
    { 0x76, 0xff, ' ', 3, "ROR %e" },
    { 0x77, 0xff, ' ', 3, "ASR %e" },
    { 0x78, 0xff, ' ', 3, "ASL %e" },
    { 0x79, 0xff, ' ', 3, "ROL %e" },
    { 0x7a, 0xff, ' ', 3, "DEC %e" },
    { 0x7c, 0xff, ' ', 3, "INC %e" },
    { 0x7d, 0xff, ' ', 3, "TST %e" },
    { 0x7e, 0xff, ' ', 3, "JMP %e" },
    { 0x7f, 0xff, ' ', 3, "CLR %e" },
    
    { 0x80, 0xff, ' ', 2, "SUB A,%b" },
    { 0x81, 0xff, ' ', 2, "CMP A,%b" },
    { 0x82, 0xff, ' ', 2, "SBC A,%b" },
    { 0x84, 0xff, ' ', 2, "AND A,%b" },
    { 0x85, 0xff, ' ', 2, "BIT A,%b" },
    { 0x86, 0xff, ' ', 2, "LDA A,%b" },
    { 0x88, 0xff, ' ', 2, "EOR A,%b" },
    { 0x89, 0xff, ' ', 2, "ADC A,%b" },
    { 0x8a, 0xff, ' ', 2, "ORA A,%b" },
    { 0x8b, 0xff, ' ', 2, "ADD A,%b" },
    { 0x8c, 0xff, ' ', 3, "CPX %B" },
    { 0x8e, 0xff, ' ', 3, "LDS %B" },

    { 0x90, 0xff, ' ', 2, "SUB A,%d" },
    { 0x91, 0xff, ' ', 2, "CMP A,%d" },
    { 0x92, 0xff, ' ', 2, "SBC A,%d" },
    { 0x94, 0xff, ' ', 2, "AND A,%d" },
    { 0x95, 0xff, ' ', 2, "BIT A,%d" },
    { 0x96, 0xff, ' ', 2, "LDA A,%d" },
    { 0x97, 0xff, ' ', 2, "STA A,%d" },
    { 0x98, 0xff, ' ', 2, "EOR A,%d" },
    { 0x99, 0xff, ' ', 2, "ADC A,%d" },
    { 0x9a, 0xff, ' ', 2, "ORA A,%d" },
    { 0x9b, 0xff, ' ', 2, "ADD A,%d" },
    { 0x9c, 0xff, ' ', 3, "CPX %d" },
    { 0x9e, 0xff, ' ', 3, "LDS %d" },

    { 0, 0, 0, 0, 0, 0 }
  };

/* End of m6800.src/glob.cc */
