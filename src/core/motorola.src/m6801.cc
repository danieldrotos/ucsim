/*
 * Simulator of microcontrollers (m6801.h)
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

#include <stdio.h>
#include <ctype.h>

#include "glob68.h"

#include "m6801cl.h"



i8_t m6801ticks[256]= {
  /*      0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f  */
  /* 0 */ 0, 2, 0, 0, 3, 3, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2,
  /* 1 */ 2, 2, 0, 0, 0, 0, 2, 2, 0, 2, 0, 2, 0, 0, 0, 0,
  /* 2 */ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  /* 3 */ 3, 3, 4, 4, 3, 3, 3, 3, 5, 5, 3,10, 4,10, 9,12,
  /* 4 */ 2, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2,
  /* 5 */ 2, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2,
  /* 6 */ 6, 0, 0, 6, 6, 0, 6, 6, 6, 6, 6, 0, 6, 6, 3, 6,
  /* 7 */ 6, 0, 0, 6, 6, 0, 6, 6, 6, 6, 6, 0, 6, 6, 3, 6,
  /* 8 */ 2, 2, 2, 4, 2, 2, 2, 0, 2, 2, 2, 2, 4, 6, 3, 0,
  /* 9 */ 3, 3, 3, 5, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 4, 4,
  /* a */ 4, 4, 4, 6, 4, 4, 4, 4, 4, 4, 4, 4, 6, 6, 5, 5,
  /* b */ 4, 4, 4, 6, 4, 4, 4, 4, 4, 4, 4, 4, 6, 6, 5, 5,
  /* c */ 2, 2, 2, 4, 2, 2, 2, 0, 2, 2, 2, 2, 3, 0, 3, 0,
  /* d */ 3, 3, 3, 5, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4,
  /* e */ 4, 4, 4, 6, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5,
  /* f */ 4, 4, 4, 6, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5
};


cl_m6801::cl_m6801(class cl_sim *asim):
  cl_m6800(asim)
{
}


const char *
cl_m6801::id_string(void)
{
  return "M6801";
}


int
cl_m6801::init(void)
{
  cl_m6800::init();
  #define RCV(R) reg_cell_var(&c ## R , &r ## R , "" #R "" , "CPU register " #R "")
  RCV(D);
#undef RCV

  return 0;
}


struct dis_entry *
cl_m6801::get_dis_entry(t_addr addr)
{
  struct dis_entry *dt= disass_m6801;
  int i= 0;
  t_mem code= rom->get(addr);

  if (dt == NULL)
    return NULL;
  while (((code & dt[i].mask) != dt[i].code) &&
	 dt[i].mnemonic)
    i++;
  if (dt[i].mnemonic)
    return &dt[i];
  return cl_m6800::get_dis_entry(addr);
}


void
cl_m6801::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("A= $%02x %3d %+4d %c  ", A, A, (i8_t)A, isprint(A)?A:'.');
  con->dd_printf("B= $%02x %3d %+4d %c  ", B, B, (i8_t)B, isprint(B)?B:'.');
  con->dd_printf("D= $%04x %5d %+5d ", rD, rD, (i16_t)rD);
  con->dd_printf("\n");
  con->dd_printf("CC= "); con->print_bin(rF, 8); con->dd_printf("\n");
  con->dd_printf("      HINZVC\n");

  con->dd_printf("IX= ");
  class cl_dump_ads ads(IX, IX+7);
  rom->dump(0, /*IX, IX+7*/&ads, 8, con);
  con->dd_color("answer");
  
  con->dd_printf("SP= ");
  ads._ss(SP, SP+7);
  rom->dump(0, /*SP, SP+7*/&ads, 8, con);
  con->dd_color("answer");
  
  print_disass(PC, con);
}


int
cl_m6801::add16(class cl_memory_cell &dest, u16_t op)
{
  u8_t f= rF & ~(flagN|flagZ|flagV|flagC);
  u16_t a= dest.read(), b= op, r;
  u8_t a15, b15, r15, na15, nb15, nr15;
  r= a+b;
  a15= a&0x8000; na15= a15^0x8000;
  b15= b&0x8000; nb15= b15^0x8000;
  r15= r&0x8000; nr15= r15^0x8000;
  if (r15) f|= flagN;
  if (!r) f|= flagZ;
  if ((a15&b15&nr15) | (na15&nb15&r15)) f|= flagV;
  if ((a15&b15) | (b15&nr15) | (nr15&a15)) f|= flagC;
  dest.W(r);
  cCC.W(f);
  return resGO;
}


int
cl_m6801::sub16(class cl_memory_cell &dest, u16_t op)
{
  u8_t orgc= rF&flagC;
  u8_t f= rF & ~(flagN|flagZ|flagV|flagC);
  u16_t a= dest.read(), b= op, r;
  u8_t a15, b15, r15, na15, nb15, nr15;
  r= a-b;
  a15= a&0x8000; na15= a15^0x8000;
  b15= b&0x8000; nb15= b15^0x8000;
  r15= r&0x8000; nr15= r15^0x8000;
  if (r15) f|= flagN;
  if (!r) f|= flagZ;
  if ((a15&nb15&nr15) | (na15&b15&r15)) f|= flagV;
  if ((na15&b15) | (b15&r15) | (r15&na15)) f|= flagC;
  dest.W(r);
  cCC.W(f);
  return resGO;
}


int
cl_m6801::cpx(u16_t op)
{
  u32_t r;
  u16_t x= rX, r2;
  u8_t f= rF & ~(flagN|flagZ|flagV|flagC);
  op= ~op+1;
  r= x+op;
  r2= (x&0x7fff) + (op&0x7fff);
  if (r&0x8000) f|= flagN;
  if (!(r&0xffff)) f|= flagZ;
  r &= ~0xffff;
  r2&= ~0x7fff;
  if ((r && !r2) ||
      (!r && r2)) f|= flagV;
  if (op > x)
    f|= flagC;
  cCC.W(f);
  return resGO;
}


int
cl_m6801::ldd(u16_t op)
{
  rF&= ~(flagN|flagZ|flagV);
  cD.W(op);
  if (!op)
    rF|= flagZ;
  if (op&0x8000)
    rF|= flagN;
  cCC.W(rF);
  return resGO;
}


int
cl_m6801::std(t_addr addr)
{
  rF&= ~(flagN|flagZ|flagV);
  if (rD & 0x8000)
    rF|= flagN;
  if (!rD)
    rF|= flagZ;
  cCC.W(rF);
  rom->write(addr, rA);
  rom->write(addr+1, rB);
  vc.wr+= 2;
  return resGO;
}


int
cl_m6801::PSHX(t_mem code)
{
  rom->write(rSP  , rIX);
  rom->write(rSP-1, rIX>>8);
  cSP.W(rSP-2);
  vc.wr+= 2;
  return resGO;
}


int
cl_m6801::PULX(t_mem code)
{
  rIX= rom->read(rSP+1) * 256 + rom->read(rSP+2);
  cIX.W(rIX);
  cSP.W(rSP+2);
  vc.rd+= 2;
  return resGO;
}


int
cl_m6801::LSRD(t_mem code)
{
  u8_t newc= (rD&0x1)?flagC:0;
  u16_t r= rD>>1;
  rF&= ~(flagN|flagZ|flagV|flagC);
  u8_t newv= newc?flagV:0;
  cD.W(r);
  if (!r)
    rF|= flagZ;
  cCC.W(rF|newc|newv);
  return resGO;
}


int
cl_m6801::ASLD(t_mem code)
{
  u8_t newc= (rD&0x8000)?flagC:0;
  u16_t r= rD<<1;
  u8_t newn= (r&0x8000)?flagN:0;
  rF&= ~(flagN|flagZ|flagV|flagC);
  u8_t newv= (newn && !newc) || (!newn && newc);
  newv= newv?flagV:0;
  cD.W(r);
  if (!r)
    rF|= flagZ;
  cCC.W(rF|newc|newn|newv);
  return resGO;
}


int
cl_m6801::ABX(t_mem code)
{
  u16_t op= rB;
  cX.W(rX + op);
  return resGO;
}


int
cl_m6801::MUL(t_mem code)
{
  rF&= ~flagC;
  cD.W(rA*rB);
  if (rB&0x80)
    rF|= flagC;
  cCC.W(rF);
  return resGO;
}


/* End of motorola.src/m6801.cc */
