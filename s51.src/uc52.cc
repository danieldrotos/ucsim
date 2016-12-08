/*
 * Simulator of microcontrollers (uc52.cc)
 *
 * Copyright (C) 1999,99 Drotos Daniel, Talker Bt.
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

#include "ddconfig.h"

#include <stdio.h>

// local
#include "uc52cl.h"
#include "regs51.h"
#include "timer2cl.h"
#include "portcl.h"


/*
 * Making an 8052 CPU object
 */

cl_uc52::cl_uc52(int Itype, int Itech, class cl_sim *asim):
  cl_51core(Itype, Itech, asim)
{
}

void
cl_uc52::mk_hw_elements(void)
{
  class cl_hw *h;

  cl_51core::mk_hw_elements();
  add_hw(h= new cl_timer2(this, 2, "timer2", t2_default|t2_down));
  h->init();

  if (technology & CPU_F380)
    {
      h= new cl_port(this, 4, 0xc7);
      add_hw(h);
      h->init();
    }
}

void
cl_uc52::make_memories(void)
{
  cl_51core::make_memories();
}

void
cl_uc52::make_address_spaces(void)
{
  rom= new cl_address_space("rom", 0, 0x10000, 8);
  rom->init();
  address_spaces->add(rom);
  
  iram= new cl_address_space("iram", 0, 0x100, 8);
  iram->init();
  address_spaces->add(iram);

  sfr= new cl_address_space("sfr", 0x80, 0x80, 8);
  sfr->init();
  address_spaces->add(sfr);

  xram= new cl_address_space("xram", 0, 0x10000, 8);
  xram->init();
  address_spaces->add(xram);

  regs= new cl_address_space("regs", 0, 8, 8);
  regs->init();
  address_spaces->add(regs);

  bits= new cl_address_space("bits", 0, 0x100, 1);
  bits->init();
  address_spaces->add(bits);

  dptr= new cl_address_space("dptr", 0, 2, 8);
  dptr->init();
  address_spaces->add(dptr);
}


void
cl_uc52::decode_iram(void)
{
  class cl_address_decoder *ad;
  
  ad= new cl_address_decoder(iram, iram_chip, 0, 0xff, 0);
  ad->init();
  iram->decoders->add(ad);
  ad->activate(0);

}

void
cl_uc52::decode_dptr(void)
{
  cl_banker *banker;
  
  if (type == CPU_C521)
    {
      banker= new cl_banker(sfr, 0x86, 1,
			    dptr, 0, 1);
      banker->init();
      dptr->decoders->add(banker);

      banker->add_bank(0, memory("sfr_chip"), 0x82-0x80);
      banker->add_bank(1, memory("sfr_chip"), 0x84-0x80);
      banker->activate(0);
      sfr->write(0x86, 0);
    }
  else if (type == CPU_517)
    {
      cl_memory_chip *dptr_chip= new cl_memory_chip("dptr_chip", 16, 8);
      dptr_chip->init();
      memchips->add(dptr_chip);
      banker= new cl_banker(sfr, 0x92, 0x7,
			    dptr, 0, 1);
      banker->init();
      int a;
      for (a= 0; a < 8; a++)
	banker->add_bank(a, dptr_chip, a*2);
      dptr->decoders->add(banker);
      banker->activate(0);
      sfr->write(0x92, 0);
    }
  else
    cl_51core::decode_dptr();
}

void
cl_uc52::clear_sfr(void)
{
  cl_51core::clear_sfr();
  sfr->write(T2CON, 0);
  sfr->write(TH2, 0);
  sfr->write(TL2, 0);
  sfr->write(RCAP2L, 0);
  sfr->write(RCAP2H, 0);
}


/* End of s51.src/uc52.cc */
