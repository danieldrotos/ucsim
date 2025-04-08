/*
 * Simulator of microcontrollers (t870ccl.h)
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

#ifndef T870CCL_HEADER
#define T870CCL_HEADER

#include "uccl.h"


#ifdef WORDS_BIGENDIAN
# define PAIR(h,l) u8_t h, l
#else
# define PAIR(h,l) u8_t l, h
#endif

struct rbank_870c_t
{
  union { u16_t wa; struct { PAIR(w,a); } rwa; };
  union { u16_t bc; struct { PAIR(b,c); } rbc; };
  union { u16_t de; struct { PAIR(d,e); } rde; };
  union { u16_t hl; struct { PAIR(h,l); } rhl; };
  u16_t ix, iy;
};


#define rW (rbank->rwa.w)
#define rA (rbank->rwa.a)
#define rB (rbank->rbc.b)
#define rC (rbank->rbc.c)
#define rD (rbank->rde.d)
#define rE (rbank->rde.e)
#define rH (rbank->rhl.h)
#define rL (rbank->rhl.l)
#define rF (rPSW)

#define rWA (rbank->wa)
#define rBC (rbank->bc)
#define rDE (rbank->de)
#define rHL (rbank->hl)
#define rIX (rbank->ix)
#define rIY (rbank->iy)

#define cF (cPSW)

#define MP    t_mem code
#define RD    (vc.rd++)
#define RD2   (vc.rd+=2)
#define WR    (vc.wr++)
#define WR2   (vc.wr+=2)
#define RDWR  (vc.rd++,vc.wr++)
#define WRRD  (vc.rd++,vc.wr++)


enum flag_mask_t {
  MJF= (0x80),
  MZF= (0x40),
  MCF= (0x20),
  MHF= (0x10),
  MSF= (0x08),
  MVF= (0x04),
  MRBS= (0x02)
};


class cl_t870c;

class cl_t870c_psw_op: public cl_memory_operator
{
protected:
  class cl_t870c *uc;
public:
  cl_t870c_psw_op(class cl_memory_cell *acell, class cl_t870c *auc);
  virtual t_mem write(t_mem val);
};
  

class cl_t870c: public cl_uc
{
public:
  struct rbank_870c_t *rbanks, *rbank;
  u16_t rSP;
  u8_t rPSW;
  class cl_cell8 cW, cA, cB, cC, cD, cE, cH, cL;
  class cl_cell8 *regs8[8];
  class cl_cell16 cWA, cBC, cDE, cHL, cIX, cIY, cSP;
  class cl_cell16 *regs16[8];
  class cl_cell8 cPSW;
  class cl_address_space *asc, *asd;
  class cl_memory_chip *ram_chip, *rom_chip, *bootrom_chip;
  u16_t sp_limit;
public:
  // (src) or (dst) memory cell for 8/16 bit ops
  class cl_cell8 *sdc;
  t_addr sda;
public:
  cl_t870c(class cl_sim *asim);
  virtual int init(void);
  virtual void part_init(void);
  virtual void mk_rbanks();
  virtual void decode_regs(void);
  virtual void make_memories(void);
  virtual void make_cpu_hw(void);
  virtual void reset(void);
  virtual void print_regs(class cl_console_base *con);

  virtual struct dis_entry *dis_tbl(void);
  virtual char *disassc(t_addr addr, chars *comment);
  virtual int longest_inst(void) { return 5; }

  virtual int exec_inst(void);

  virtual void sd_x(void);
  virtual void sd_vw(void);
  virtual void sd_bc(void) { sdc= (class cl_cell8 *)asd->get_cell(sda= rBC); }
  virtual void sd_de(void) { sdc= (class cl_cell8 *)asd->get_cell(sda= rDE); }
  virtual void sd_hl(void) { sdc= (class cl_cell8 *)asd->get_cell(sda= rHL); }
  virtual void sd_ix(void) { sdc= (class cl_cell8 *)asd->get_cell(sda= rIX); }
  virtual void sd_iy(void) { sdc= (class cl_cell8 *)asd->get_cell(sda= rIY); }
  virtual void sd_sp(void) { sdc= (class cl_cell8 *)asd->get_cell(sda= rSP); }
  
#include "alias870c.h"
  virtual int NOP(MP) { return resGO; }
  virtual int CLR_CF(MP);
  virtual int SET_CF(MP);
  virtual int CPL_CF(MP);
};


enum t870c_cpu_cfg
  {
    t870c_sp_limit 	= 0,
    t870c_bootmode	= 1,
    t870c_nuof     	= 2
  };
  
class cl_t870c_cpu: public cl_hw
{
public:
  class cl_t870c *uc;
  class cl_memory_cell *psw;
public:
  cl_t870c_cpu(class cl_uc *auc);
  virtual int init(void);
  virtual unsigned int cfg_size(void) { return t870c_nuof; }
  virtual void write(class cl_memory_cell *cell, t_mem *val);
  virtual t_mem read(class cl_memory_cell *cell);
  virtual t_mem conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val);
  virtual const char *cfg_help(t_addr addr);
};


#endif

/* End of tlcs.src/tl870ccl.h */
