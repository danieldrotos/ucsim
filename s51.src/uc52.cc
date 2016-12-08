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
  class cl_address_decoder *ad;
  
  make_address_spaces();
  make_chips();

  acc= sfr->get_cell(ACC);
  psw= sfr->get_cell(PSW);
  
  decode_regs();
  decode_bits();

  ad= new cl_address_decoder(rom, rom_chip, 0, 0xffff, 0);
  ad->init();
  rom->decoders->add(ad);
  ad->activate(0);

  ad= new cl_address_decoder(iram, iram_chip, 0, 0xff, 0);
  ad->init();
  iram->decoders->add(ad);
  ad->activate(0);

  ad= new cl_address_decoder(xram, xram_chip, 0, 0xffff, 0);
  ad->init();
  xram->decoders->add(ad);
  ad->activate(0);

  ad= new cl_address_decoder(sfr, sfr_chip, 0x80, 0xff, 0);
  ad->init();
  sfr->decoders->add(ad);
  ad->activate(0);
  
  cl_var *v;
  vars->add(v= new cl_var(cchars("R0"), regs, 0));
  v->init();
  vars->add(v= new cl_var(cchars("R1"), regs, 1));
  v->init();
  vars->add(v= new cl_var(cchars("R2"), regs, 2));
  v->init();
  vars->add(v= new cl_var(cchars("R3"), regs, 3));
  v->init();
  vars->add(v= new cl_var(cchars("R4"), regs, 4));
  v->init();
  vars->add(v= new cl_var(cchars("R5"), regs, 5));
  v->init();
  vars->add(v= new cl_var(cchars("R6"), regs, 6));
  v->init();
  vars->add(v= new cl_var(cchars("R7"), regs, 7));
  v->init();

  dptr= new cl_address_space("dptr", 0, 2, 8);
  dptr->init();
  address_spaces->add(dptr);

  if (type == CPU_C521)
    {
      cl_banker *banker= new cl_banker(sfr, 0x86, 1,
				       dptr, 0, 1);
      banker->init();
      dptr->decoders->add(banker);

      banker->add_bank(0, memory("sfr_chip"), 0x82-0x80);
      banker->add_bank(1, memory("sfr_chip"), 0x84-0x80);
      banker->activate(0);
      sfr->write(0x86, 0);
    }
  else
    {
      ad= new cl_address_decoder(dptr, sfr_chip, 0, 1, DPL-0x80);
      ad->init();
      dptr->decoders->add(ad);
      ad->activate(0);
    }
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
