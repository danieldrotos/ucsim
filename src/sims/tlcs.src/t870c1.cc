/*
 * Simulator of microcontrollers (t870c1.cc)
 *
 * Copyright (C) 2016 Drotos Daniel
 * 
 * To contact author send email to dr.dkdb@gmail.com
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

#include <stdlib.h>
#include <ctype.h>

#include "utils.h"

// local
#include "t870c1cl.h"


cl_t870c1::cl_t870c1(class cl_sim *asim):
  cl_t870c(asim)
{
}


int
cl_t870c1::init(void)
{
  cl_t870c::init();
  return 0;
}

void
cl_t870c1::mk_rbanks(void)
{
  rbanks= (struct rbank_870c_t *)malloc(sizeof(*rbanks));
  rbank= &rbanks[0];
}


void
cl_t870c1::make_memories(void)
{
  class cl_address_space *as;

  rom= asc= as= new cl_address_space("code", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  asd= as= new cl_address_space("data", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  class cl_address_decoder *ad;
  class cl_memory_chip *chip;

  bootrom_chip= chip= new cl_chip8("bootrom_chip", 0x800, 8, 0xff);
  chip->init();
  memchips->add(chip);
  
  rom_chip= chip= new cl_chip8("rom_chip", 0x8000, 8, 0xff);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= rom,
                             chip, 0x8000, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);

  ad= new cl_address_decoder(as= asd,
                             chip, 0x8000, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);

  ram_chip= chip= new cl_chip8("ram_chip", 0x800, 8);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= asd,
                             chip, 0x40, 0x83f, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);

  chip= new cl_chip8("sfr1_chip", 64, 8, 0);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= asd,
                             chip, 0, 63, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);

  chip= new cl_chip8("sfr2_chip", 256, 8, 0);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= asd,
                             chip, 0xf00, 0xfff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);

  chip= new cl_chip8("sfr3_chip", 192, 8, 0);
  chip->init();
  memchips->add(chip);
  
  ad= new cl_address_decoder(as= asd,
                             chip, 0xe40, 0xeff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}


void
cl_t870c1::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("JZCHSVB-  Flags= 0x%02x  ", rF);
  con->dd_printf("A= 0x%02x %3d %c\n",
		 rA, rA, isprint(rA)?rA:'.');
  con->dd_printf("%s\n", cbin(rF,8).c_str());
  if ((rF & MRBS) == 0)
    con->dd_color("answer");
  else
    con->dd_color("gray_answer");
  con->dd_printf("WA0=0x%04x [WA]=%02x  ", rWA0, asd->read(rWA0));
  con->dd_printf("BC0=0x%04x [BC]=%02x  ", rBC0, asd->read(rBC0));
  con->dd_printf("DE0=0x%04x [DE]=%02x\n", rDE0, asd->read(rDE0));
  con->dd_printf("HL0=0x%04x [HL]=%02x  ", rHL0, asd->read(rHL0));
  con->dd_printf("IX0=0x%04x [IX]=%02x  ", rIX0, asd->read(rIX0));
  con->dd_printf("IY0=0x%04x [IY]=%02x\n", rIY0, asd->read(rIY0));
  if ((rF & MRBS) != 0)
    con->dd_color("answer");
  else
    con->dd_color("gray_answer");
  con->dd_printf("WA1=0x%04x [WA]=%02x  ", rWA1, asd->read(rWA1));
  con->dd_printf("BC1=0x%04x [BC]=%02x  ", rBC1, asd->read(rBC1));
  con->dd_printf("DE1=0x%04x [DE]=%02x\n", rDE1, asd->read(rDE1));
  con->dd_printf("HL1=0x%04x [HL]=%02x  ", rHL1, asd->read(rHL1));
  con->dd_printf("IX1=0x%04x [IX]=%02x  ", rIX1, asd->read(rIX1));
  con->dd_printf("IY1=0x%04x [IY]=%02x\n", rIY1, asd->read(rIY1));

  con->dd_color("answer");
  con->dd_printf("SP =0x%04x [SP]=%02x  ", rSP, asd->read(rSP));
  con->dd_printf("\n");
  print_disass(PC, con);
}


/* End of tlcs.src/t870c1.cc */
