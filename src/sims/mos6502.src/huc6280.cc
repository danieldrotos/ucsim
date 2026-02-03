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

#include "glob.h"

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
  int i;
  cl_mos6502::init();
  // Map all 0x_b into NOP 1,1
  for (i=0x0b; i<=0xfb; i+= 0x10)
    itab[i]= instruction_wrapper_03;
  // some other non-codes
  itab[0xe2]= instruction_wrapper_03;
  itab[0x33]= instruction_wrapper_03;
  itab[0x63]= instruction_wrapper_03;
  itab[0x5c]= instruction_wrapper_03;
  itab[0xdc]= instruction_wrapper_03;
  itab[0xfc]= instruction_wrapper_03;
  
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
  //class cl_memory_chip *chip;
  class cl_banker *b;
  
  rom= as= new cl_as65("rom", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  romchip= new cl_chip8("rom_chip", 0x200000, 8);
  romchip->init();
  memchips->add(romchip);

  int pagenr;
  int i;
  for (pagenr= 0; pagenr < 8; pagenr++)
    {
      b= new cl_banker(mpras, pagenr, 0xff,
		       rom, pagenr * 0x2000, pagenr*0x2000 + 0x1fff);
      b->init();
      rom->decoders->add(b);
      for (i= 0; i<0x100; i++)
	b->add_bank(i, romchip, i*0x2000);
      b->activate(0);
    }
}


struct dis_entry *
cl_huc6280::get_dis_entry(t_addr addr)
{
  struct dis_entry *de;
  
  t_mem code= rom->read(addr);
  for (de = disass_huc6280; de && de->mnemonic; de++)
    {
      if ((code & de->mask) == de->code)
        return de;
    }
  
  return cl_mos65c02s::get_dis_entry(addr);
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


int
cl_huc6280::SXY(MP)
{
  u8_t t= rX;
  cX.W(rY);
  cY.W(t);
  tick(2);
  return resGO;
}

int
cl_huc6280::SAX(MP)
{
  u8_t t= rX;
  cX.W(rA);
  cA.W(t);
  tick(2);
  return resGO;
}

int
cl_huc6280::SAY(MP)
{
  u8_t t= rY;
  cY.W(rA);
  cA.W(t);
  tick(2);
  return resGO;
}

/* 1FE000
   0001.1111.1110. 0000.0000.0000
      20   16   12    8    4    0
*/

int
cl_huc6280::STO(MP)
{
  u8_t v= fetch();
  romchip->set(0x1fe000, v);
  WR;
  tick(3);
  return resGO;
}

int
cl_huc6280::ST1(MP)
{
  u8_t v= fetch();
  romchip->set(0x1fe000+2, v);
  WR;
  tick(3);
  return resGO;
}

int
cl_huc6280::ST2(MP)
{
  u8_t v= fetch();
  romchip->set(0x1fe000+3, v);
  WR;
  tick(3);
  return resGO;
}

int
cl_huc6280::TMA(MP)
{
  u8_t i= L2i(fetch()) & 7;
  u8_t v= mpras->read(i);
  cA.W(v);
  tick(3);
  return resGO;
}

int
cl_huc6280::TAM(MP)
{
  u8_t i= L2i(fetch()) & 7;
  mpras->write(i, rA);
  tick(4);
  return resGO;
}

int
cl_huc6280::TII(MP)
{
  u16_t s, d, l;
  s= fetch(); s+= 256*fetch();
  d= fetch(); d+= 256*fetch();
  l= fetch(); l+= 256*fetch();
  push_reg(&cY);
  push_reg(&cA);
  push_reg(&cX);
  tick(16);
  do {
    u8_t v= rom->read(s);
    rom->write(d, v);
    s++, d++, l--;
    RDWR;
    tick(6);
  }
  while (l);
  pop_reg(&cX);
  pop_reg(&cA);
  pop_reg(&cY);
  return resGO;
}

int
cl_huc6280::TDD(MP)
{
  u16_t s, d, l;
  s= fetch(); s+= 256*fetch();
  d= fetch(); d+= 256*fetch();
  l= fetch(); l+= 256*fetch();
  push_reg(&cY);
  push_reg(&cA);
  push_reg(&cX);
  tick(16);
  do {
    u8_t v= rom->read(s);
    rom->write(d, v);
    s--, d--, l--;
    RDWR;
    tick(6);
  }
  while (l);
  pop_reg(&cX);
  pop_reg(&cA);
  pop_reg(&cY);
  return resGO;
}

int
cl_huc6280::TIN(MP)
{
  u16_t s, d, l;
  s= fetch(); s+= 256*fetch();
  d= fetch(); d+= 256*fetch();
  l= fetch(); l+= 256*fetch();
  push_reg(&cY);
  push_reg(&cA);
  push_reg(&cX);
  tick(16);
  do {
    u8_t v= rom->read(s);
    rom->write(d, v);
    s++, l--;
    RDWR;
    tick(6);
  }
  while (l);
  pop_reg(&cX);
  pop_reg(&cA);
  pop_reg(&cY);
  return resGO;
}

int
cl_huc6280::TIA(MP)
{
  u16_t s, d, l;
  int da= +1;
  s= fetch(); s+= 256*fetch();
  d= fetch(); d+= 256*fetch();
  l= fetch(); l+= 256*fetch();
  push_reg(&cY);
  push_reg(&cA);
  push_reg(&cX);
  tick(16);
  do {
    u8_t v= rom->read(s);
    rom->write(d, v);
    s++, d+= da, l--, da*= -1;
    RDWR;
    tick(6);
  }
  while (l);
  pop_reg(&cX);
  pop_reg(&cA);
  pop_reg(&cY);
  return resGO;
}

int
cl_huc6280::TAI(MP)
{
  u16_t s, d, l;
  int da= +1;
  s= fetch(); s+= 256*fetch();
  d= fetch(); d+= 256*fetch();
  l= fetch(); l+= 256*fetch();
  push_reg(&cY);
  push_reg(&cA);
  push_reg(&cX);
  tick(16);
  do {
    u8_t v= rom->read(s);
    rom->write(d, v);
    s+= da, d++, l--, da*= -1;
    RDWR;
    tick(6);
  }
  while (l);
  pop_reg(&cX);
  pop_reg(&cA);
  pop_reg(&cY);
  return resGO;
}

int
cl_huc6280::tst(u8_t n, C8 &c)
{
  u8_t v= c.R();
  RD;
  rF&= ~(mN|mV|mZ);
  if ((rA & v) == 0)
    rF|= mZ;
  if (v & 0x80)
    rF|= mN;
  if (v & 0x40)
    rF|= mV;
  cF.W(rF);
  tick(4);
  return resGO;
}

int
cl_huc6280::BSR(MP)
{
  t_addr pc= PC;
  i8_t rel= fetch();
  u16_t a= PC+rel;
  u8_t spbef= rSP;
  push_addr(pc);
  if ((u16_t)(PC&0xff00) != (u16_t)(a&0xff00))
    tick(1);
  class cl_stack_call *op= new cl_stack_call(instPC, a, PC, spbef, rSP);
  op->init();
  stack_write(op);
  PC= a;
  return resGO;
}


int
cl_huc6280::PHP(MP)
{
  cF.W(rF & ~mT);
  return cl_mos6502::PHP(code);
}

int
cl_huc6280::PLP(MP)
{
  int r= cl_mos6502::PLP(code);
  cF.W(rF & ~mT);
  return r;
}

int
cl_huc6280::ora(class cl_cell8 &op)
{
  if (!(rF & mT))
    return cl_mos6502::ora(op);
  u8_t f= rF & ~(flagZ|flagS|mT);
  C8 *m= (C8*)rom->get_cell(rX);
  u8_t v= m->read();
  v|= op.R();
  m->write(v);
  if (!v) f|= flagZ;
  if (v&0x80) f|= flagS;
  cF.W(f);
  RDWR;
  tick(3);
  return resGO;
}


int
cl_huc6280::And(class cl_cell8 &op)
{
  if (!(rF & mT))
    return cl_mos6502::And(op);
  u8_t f= rF & ~(flagZ|flagS|mT);
  C8 *m= (C8*)rom->get_cell(rX);
  u8_t v= m->read();
  v&= op.R();
  m->write(v);
  if (!v) f|= flagZ;
  if (v&0x80) f|= flagS;
  cF.W(f);
  RDWR;
  tick(3);
  return resGO;
}


int
cl_huc6280::eor(class cl_cell8 &op)
{
  if (!(rF & mT))
    return cl_mos6502::eor(op);
  u8_t f= rF & ~(flagZ|flagS|mT);
  C8 *m= (C8*)rom->get_cell(rX);
  u8_t v= m->read();
  v^= op.R();
  m->write(v);
  if (!v) f|= flagZ;
  if (v&0x80) f|= flagS;
  cF.W(f);
  RDWR;
  tick(3);
  return resGO;
}

int
cl_huc6280::adc(class cl_cell8 &op)
{
  if (!(rF & mT))
    return cl_mos6502::adc(op);

  C8 *m= (C8*)rom->get_cell(rX);
  u8_t Op= op.R(), f, oA= m->read();;
  u16_t res;
  u8_t C= (rF&flagC)?1:0;
  f= rF & ~(flagZ|flagC|flagN|mT);

  if (!(rF & flagD))
    {
      f&= ~flagV;
      res= rA + Op + C;
      m->write(res);
      if (!rA) f|= flagZ;
      if (rA & 0x80) f|= flagN;
      if (res > 255) f|= flagC;
      if ( ((res^oA)&0x80) && !((oA^Op)&0x80) ) f|= flagV;
    }
  else
    {
      int opint= ((Op & 0xf0) >> 4) * 10;
      opint+= (Op & 0x0f);
      int accint= ((oA & 0xf0) >> 4) * 10;
      accint+= (oA & 0x0f);
      int sum= opint + accint + C;
      if (sum > 99)
	{
	  f|= flagC;
	  sum-= 100;
	}
      else
	{
	  f&= ~flagC;
	}
      u8_t resA= 0;
      if (sum >= 0 && sum < 100)
	{
	  int tens= sum/10;
	  int units= sum%10;
	  resA= ((u8_t)tens << 4 | (u8_t)units);
	}
      m->write(resA);
      if (!resA) f|= flagZ;
      if (resA&0x80) f|= flagN;
    }
  cF.W(f);
  RDWR;
  tick(3);
  return resGO;
}


/* End of mos6502.src/huc6280.cc */
