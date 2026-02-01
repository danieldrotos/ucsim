/*
 * Simulator of microcontrollers (huc6280.cc)
 *
 * Copyright (C) 2020 Drotos Daniel
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

#include <ctype.h>

#include "huc6280cl.h"


cl_huc6280::cl_huc6280(class cl_sim *asim):
  cl_mos65c02s(asim)
{
  *my_id= "HUC6280";
  mprch= new cl_chip8("mpr_chip", 8, 8, 0);
  mpras= new cl_address_space("mpr_as", 0, 8, 8);
  mprad= new cl_address_decoder(mpras, mprch, 0, 7, 0);
  mprch->init();
  mpras->init();
  mprad->init();
  SPh= 0x2100;
};


void
cl_huc6280::reset(void)
{
  mpras->write(7, 0);
  cl_uc::reset();
}


int
cl_huc6280::init(void)
{
  cl_mos65c02s::init();
  address_spaces->add(mpras);
  memchips->add(mprch);
  mpras->decoders->add(mprad);
  mprad->activate(0);
  mk_mvar(mpras, 0, "MPR0", "Mapping Register 0");
  mk_mvar(mpras, 1, "MPR1", "Mapping Register 1");
  mk_mvar(mpras, 2, "MPR2", "Mapping Register 2");
  mk_mvar(mpras, 3, "MPR3", "Mapping Register 3");
  mk_mvar(mpras, 4, "MPR4", "Mapping Register 4");
  mk_mvar(mpras, 5, "MPR5", "Mapping Register 5");
  mk_mvar(mpras, 6, "MPR6", "Mapping Register 6");
  mk_mvar(mpras, 7, "MPR7", "Mapping Register 7");
  return 0;
}


void
cl_huc6280::make_memories(void)
{
  class cl_address_space *as;
  class cl_address_decoder *ad;
  class cl_memory_chip *chip;
  class cl_banker *b;
  
  rom= as= new cl_as65("rom", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  chip= new cl_chip8("rom_chip", 0x200000, 8);
  chip->init();
  memchips->add(chip);

  int pagenr;
  int i;
  for (pagenr= 0; pagenr < 8; pagenr++)
    {
      b= new cl_banker(mpras, pagenr, 0xff,
		       rom, pagenr * 0x2000, pagenr*0x2000 + 0x1fff);
      b->init();
      rom->decoders->add(b);
      for (i= 0; i<0x100; i++)
	b->add_bank(i, chip, i*0x2000);
      b->activate(0);
    }
}


void
cl_huc6280::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("A= $%02x %3d %+4d %c  ", A, A, (i8_t)A, isprint(A)?A:'.');
  con->dd_printf("X= $%02x %3d %+4d %c  ", X, X, (i8_t)X, isprint(X)?X:'.');
  con->dd_printf("Y= $%02x %3d %+4d %c  ", Y, Y, (i8_t)Y, isprint(Y)?Y:'.');
  con->dd_printf("\n");
  con->dd_printf("P= "); con->print_bin(CC, 8); con->dd_printf("\n");
  con->dd_printf("   NVTBDIZC\n");

  con->dd_printf("S= ");
  class cl_dump_ads ads(SPh+SP, SPh+SP+7);
  rom->dump(0, /*0x100+SP, 0x100+SP+7*/&ads, 8, con);
  con->dd_color("answer");
  
  print_disass(PC, con);
}


/* End of mos6502.src/huc6280.cc */
