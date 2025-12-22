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
  virtual int inst_length(t_addr addr);

  virtual int exec_inst(void);
  virtual int exec_inst_page(int page);

  // Set sdc/sda for indirect addressing modes
  virtual class cl_cell8 *sd_x(void);
  virtual void sd_vw(void);
  virtual void sd_bc(void) { sdc= (class cl_cell8 *)asd->get_cell(sda= rBC); }
  virtual void sd_de(void) { sdc= (class cl_cell8 *)asd->get_cell(sda= rDE); }
  virtual class cl_cell8 *sd_hl(void) { return sdc= (class cl_cell8 *)asd->get_cell(sda= rHL); }
  virtual void sd_ix(void) { sdc= (class cl_cell8 *)asd->get_cell(sda= rIX); }
  virtual void sd_iy(void) { sdc= (class cl_cell8 *)asd->get_cell(sda= rIY); }
  virtual void sd_sp(void) { sdc= (class cl_cell8 *)asd->get_cell(sda= rSP); }
  virtual void sd_ixd(void);
  virtual void sd_iyd(void);
  virtual void sd_spd(void);
  virtual void sd_hld(void);
  virtual void sd_pca(void); // uses actual PC
  virtual void sd_Psp(void);
  virtual void sd_spM(void);
  virtual u16_t mn(void);
  
  // Common parametrized operations
  virtual int ld8(class cl_cell8 *reg, class cl_memory_cell *src);
  virtual int ldi8(class cl_cell8 *reg, u8_t n);
  virtual int ldi8nz(class cl_cell8 *reg, u8_t n);
  virtual int ld16(class cl_cell16 *reg, u16_t addr);
  virtual int ldi16(class cl_cell16 *reg, u16_t n);
  virtual int st8(class cl_memory_cell *dst, u8_t n);
  virtual int st16(t_addr addr, u16_t n);
  
#include "alias870c.h"
  // 0 00 - 0 00
  virtual int NOP(MP) { return resGO; }
  virtual int CLR_CF(MP);
  virtual int SET_CF(MP);
  virtual int CPL_CF(MP);
  virtual int LDW_mx_mn(MP);
  virtual int LDW_mhl_mn(MP);
  virtual int LD_mx_n(MP) { sd_x(); return st8(sdc, fetch()); }
  virtual int LD_mhl_n(MP) { sd_hl(); return st8(sdc, fetch()); }
  virtual int LD_A_mx(MP) { return ld8(&cA, sd_x()); }
  virtual int LD_A_mhl(MP) { return ld8(&cA, sd_hl()); }
  virtual int LD_mx_A(MP) { return st8(sd_x(), rA); }
  virtual int LD_mhl_A(MP) { return st8(sd_hl(), rA); }
  
  // 0 10 - 0 1f
  virtual int LD_A_rA(MP) { return ldi8(&cA, rA); }
  virtual int LD_A_rW(MP) { return ldi8(&cA, rW); }
  virtual int LD_A_rC(MP) { return ldi8(&cA, rC); }
  virtual int LD_A_rB(MP) { return ldi8(&cA, rB); }
  virtual int LD_A_rE(MP) { return ldi8(&cA, rE); }
  virtual int LD_A_rD(MP) { return ldi8(&cA, rD); }
  virtual int LD_A_rL(MP) { return ldi8(&cA, rL); }
  virtual int LD_A_rH(MP) { return ldi8(&cA, rH); }
  virtual int LD_rA_n(MP) { return ldi8nz(&cA, fetch()); }
  virtual int LD_rW_n(MP) { return ldi8nz(&cW, fetch()); }
  virtual int LD_rC_n(MP) { return ldi8nz(&cC, fetch()); }
  virtual int LD_rB_n(MP) { return ldi8nz(&cB, fetch()); }
  virtual int LD_rE_n(MP) { return ldi8nz(&cE, fetch()); }
  virtual int LD_rD_n(MP) { return ldi8nz(&cD, fetch()); }
  virtual int LD_rL_n(MP) { return ldi8nz(&cL, fetch()); }
  virtual int LD_rH_n(MP) { return ldi8nz(&cH, fetch()); }
  // 0 40 - 0 4f
  virtual int LD_rA_A(MP) { return ldi8(&cA, rA); }
  virtual int LD_rW_A(MP) { return ldi8(&cW, rA); }
  virtual int LD_rC_A(MP) { return ldi8(&cC, rA); }
  virtual int LD_rB_A(MP) { return ldi8(&cB, rA); }
  virtual int LD_rE_A(MP) { return ldi8(&cE, rA); }
  virtual int LD_rD_A(MP) { return ldi8(&cD, rA); }
  virtual int LD_rL_A(MP) { return ldi8(&cL, rA); }
  virtual int LD_rH_A(MP) { return ldi8(&cH, rA); }
  virtual int LD_rrWA_mn(MP) { return ldi16(&cWA, mn()); }
  virtual int LD_rrBC_mn(MP) { return ldi16(&cBC, mn()); }
  virtual int LD_rrDE_mn(MP) { return ldi16(&cDE, mn()); }
  virtual int LD_rrHL_mn(MP) { return ldi16(&cHL, mn()); }
  virtual int LD_rrIX_mn(MP) { return ldi16(&cIX, mn()); }
  virtual int LD_rrIY_mn(MP) { return ldi16(&cIY, mn()); }
  virtual int LD_rrSP_mn(MP) { return ldi16(&cSP, mn()); }
  // 0 e0 - 0 ef
  virtual int instruction_e8(MP) { sda=0; return exec_inst_page(0x100); }
  virtual int instruction_e9(MP) { sda=1; return exec_inst_page(0x100); }
  virtual int instruction_ea(MP) { sda=2; return exec_inst_page(0x100); }
  virtual int instruction_eb(MP) { sda=3; return exec_inst_page(0x100); }
  virtual int instruction_ec(MP) { sda=4; return exec_inst_page(0x100); }
  virtual int instruction_ed(MP) { sda=5; return exec_inst_page(0x100); }
  virtual int instruction_ee(MP) { sda=6; return exec_inst_page(0x100); }
  virtual int instruction_ef(MP) { sda=7; return exec_inst_page(0x100); }
  // 0 f0 - 0 f1
  virtual int LD_RBS(MP);
  // 1 40 - 1 4f
  virtual int LD_rA_g(MP) { return ldi8(&cA, regs8[sda]->R()); }
  virtual int LD_rW_g(MP) { return ldi8(&cW, regs8[sda]->R()); }
  virtual int LD_rC_g(MP) { return ldi8(&cC, regs8[sda]->R()); }
  virtual int LD_rB_g(MP) { return ldi8(&cB, regs8[sda]->R()); }
  virtual int LD_rE_g(MP) { return ldi8(&cE, regs8[sda]->R()); }
  virtual int LD_rD_g(MP) { return ldi8(&cD, regs8[sda]->R()); }
  virtual int LD_rL_g(MP) { return ldi8(&cL, regs8[sda]->R()); }
  virtual int LD_rH_g(MP) { return ldi8(&cH, regs8[sda]->R()); }
  // 1 d0 - 1 df
  virtual int LD_PSW_n(MP) { cF.W(fetch()); return resGO; }
  // 1 f0 - 1 ff
  virtual int SWAP_g(MP);
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
