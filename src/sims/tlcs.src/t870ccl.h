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

// bit nr to bit mask converter
extern u8_t bit_mask[8];

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
  C8 cW, cA, cB, cC, cD, cE, cH, cL, cPSW;
  C8 *regs8[8];
  C16 cWA, cBC, cDE, cHL, cIX, cIY, cSP;
  C16 *regs16[8];
  class cl_address_space *asc, *asd;
  class cl_memory_chip *ram_chip, *rom_chip, *bootrom_chip;
  u16_t sp_limit;
public:
  // (src) or (dst) memory cell for 8/16 bit ops
  class cl_cell8 *sdc;
  t_addr sda;
  bool is_dst;
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
  virtual u16_t aof_dstF(u32_t code32);
  virtual u16_t aof_dst5(u32_t code32);
  virtual u16_t aof_srcE(u32_t code32);
  virtual u16_t aof_srcD(u32_t code32);
  
  virtual int exec_inst(void);
  virtual int exec1(void);
  virtual int execS(void);
  virtual int execD(void);

  // Set sdc/sda for indirect addressing modes
  virtual C8 *sd_x(void);
  virtual C8 *sd_vw(void);
  virtual void sd_bc(void) { sdc= (C8 *)asd->get_cell(sda= rBC); }
  virtual void sd_de(void) { sdc= (C8 *)asd->get_cell(sda= rDE); }
  virtual C8 *sd_hl(void) { return sdc= (C8 *)asd->get_cell(sda= rHL); }
  virtual void sd_ix(void) { sdc= (C8 *)asd->get_cell(sda= rIX); }
  virtual void sd_iy(void) { sdc= (C8 *)asd->get_cell(sda= rIY); }
  virtual void sd_sp(void) { sdc= (C8 *)asd->get_cell(sda= rSP); }
  virtual void sd_ixd(void);
  virtual void sd_iyd(void);
  virtual void sd_spd(void);
  virtual void sd_hld(void);
  virtual void sd_hlc(void);
  virtual void sd_pca(void); // uses actual PC
  virtual void sd_Psp(void);
  virtual void sd_spM(void);
  virtual u16_t mn(void);
  
  // Common parametrized operations
  virtual int ld8(C8 *reg, MCELL *src);
  virtual int ldi8(C8 *reg, u8_t n);
  virtual int ldi8nz(C8 *reg, u8_t n);
  virtual int ld16(C16 *reg, u16_t addr);
  virtual int ldi16(C16 *reg, u16_t n);
  virtual int st8(MCELL *dst, u8_t n);
  virtual int st16(t_addr addr, u16_t n);
  virtual int xch8_rr(C8 *a, C8 *b);
  virtual int xch8_rm(C8 *a, C8 *b);
  virtual int xch16_rr(C16 *a, C16 *b);
  virtual int xch16_rm(C16 *a, u16_t addr);
  virtual int ld1m(C8 *src, u8_t bitnr);
  virtual int ld1r(C8 *src, u8_t bitnr);
  virtual int st1m(C8 *dst, u8_t bitnr);
  virtual int st1r(C8 *dst, u8_t bitnr);
  virtual int setr(C8 *reg, u8_t bitnr);
  virtual int setm(C8 *reg, u8_t bitnr);
  virtual int clrr(C8 *reg, u8_t bitnr);
  virtual int clrm(C8 *reg, u8_t bitnr);
  virtual int cplm(C8 *src, u8_t bitnr);
  virtual int cplr(C8 *src, u8_t bitnr);
  virtual int xor1m(C8 *src, u8_t bitnr);
  virtual int xor1r(C8 *src, u8_t bitnr);  
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
  // 0 30 - 0 3f
  virtual int LD_SP_Pd(MP);
  virtual int LD_SP_Md(MP);
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
  virtual int instruction_4f(MP) { sd_pca(); return execS(); }
  // 0 50 - 0 5f
  virtual int instruction_54(MP) { sd_ixd(); return execD(); }
  virtual int instruction_55(MP) { sd_iyd(); return execD(); }
  virtual int instruction_56(MP) { sd_spd(); return execD(); }
  virtual int instruction_57(MP) { sd_hld(); return execD(); }
  virtual int LD_CF_mx_0(MP) { sd_x(); return ld1m(sdc, 0); }
  virtual int LD_CF_mx_1(MP) { sd_x(); return ld1m(sdc, 1); }
  virtual int LD_CF_mx_2(MP) { sd_x(); return ld1m(sdc, 2); }
  virtual int LD_CF_mx_3(MP) { sd_x(); return ld1m(sdc, 3); }
  virtual int LD_CF_mx_4(MP) { sd_x(); return ld1m(sdc, 4); }
  virtual int LD_CF_mx_5(MP) { sd_x(); return ld1m(sdc, 5); }
  virtual int LD_CF_mx_6(MP) { sd_x(); return ld1m(sdc, 6); }
  virtual int LD_CF_mx_7(MP) { sd_x(); return ld1m(sdc, 7); }
  // 0 c0 - 0 cf
  virtual int SET_mx_0(MP) { sd_x(); return setm(sdc, 0); }
  virtual int SET_mx_1(MP) { sd_x(); return setm(sdc, 1); }
  virtual int SET_mx_2(MP) { sd_x(); return setm(sdc, 2); }
  virtual int SET_mx_3(MP) { sd_x(); return setm(sdc, 3); }
  virtual int SET_mx_4(MP) { sd_x(); return setm(sdc, 4); }
  virtual int SET_mx_5(MP) { sd_x(); return setm(sdc, 5); }
  virtual int SET_mx_6(MP) { sd_x(); return setm(sdc, 6); }
  virtual int SET_mx_7(MP) { sd_x(); return setm(sdc, 7); }
  virtual int CLR_mx_0(MP) { sd_x(); return clrm(sdc, 0); }
  virtual int CLR_mx_1(MP) { sd_x(); return clrm(sdc, 1); }
  virtual int CLR_mx_2(MP) { sd_x(); return clrm(sdc, 2); }
  virtual int CLR_mx_3(MP) { sd_x(); return clrm(sdc, 3); }
  virtual int CLR_mx_4(MP) { sd_x(); return clrm(sdc, 4); }
  virtual int CLR_mx_5(MP) { sd_x(); return clrm(sdc, 5); }
  virtual int CLR_mx_6(MP) { sd_x(); return clrm(sdc, 6); }
  virtual int CLR_mx_7(MP) { sd_x(); return clrm(sdc, 7); }
  // 0 d0 - 0 df
  virtual int instruction_d4(MP) { sd_ixd(); return execS(); }
  virtual int instruction_d5(MP) { sd_iyd(); return execS(); }
  virtual int instruction_d6(MP) { sd_spd(); return execS(); }
  virtual int instruction_d7(MP) { sd_hld(); return execS(); }
  // 0 e0 - 0 ef
  virtual int instruction_e0(MP) { sd_x(); return execS(); }
  virtual int instruction_e1(MP) { sd_vw(); return execS(); }
  virtual int instruction_e2(MP) { sd_de(); return execS(); }
  virtual int instruction_e3(MP) { sd_hl(); return execS(); }
  virtual int instruction_e4(MP) { sd_ix(); return execS(); }
  virtual int instruction_e5(MP) { sd_iy(); return execS(); }
  virtual int instruction_e6(MP) { sd_Psp(); return execS(); }
  virtual int instruction_e7(MP) { sd_hlc(); return execS(); }
  virtual int instruction_e8(MP) { sda=0; return exec1(); }
  virtual int instruction_e9(MP) { sda=1; return exec1(); }
  virtual int instruction_ea(MP) { sda=2; return exec1(); }
  virtual int instruction_eb(MP) { sda=3; return exec1(); }
  virtual int instruction_ec(MP) { sda=4; return exec1(); }
  virtual int instruction_ed(MP) { sda=5; return exec1(); }
  virtual int instruction_ee(MP) { sda=6; return exec1(); }
  virtual int instruction_ef(MP) { sda=7; return exec1(); }
  // 0 f0 - 0 f1
  virtual int instruction_f0(MP) { sd_x(); return execD(); }
  virtual int instruction_f1(MP) { sd_vw(); return execD(); }
  virtual int instruction_f2(MP) { sd_de(); return execD(); }
  virtual int instruction_f3(MP) { sd_hl(); return execD(); }
  virtual int instruction_f4(MP) { sd_ix(); return execD(); }
  virtual int instruction_f5(MP) { sd_iy(); return execD(); }
  virtual int instruction_f6(MP) { sd_spM(); return execD(); }
  virtual int instruction_f7(MP) { sd_hlc(); return execD(); }
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
  virtual int LD_rrWA_gg(MP) { return ldi16(&cWA, regs16[sda]->R()); }
  virtual int LD_rrBC_gg(MP) { return ldi16(&cBC, regs16[sda]->R()); }
  virtual int LD_rrDE_gg(MP) { return ldi16(&cDE, regs16[sda]->R()); }
  virtual int LD_rrHL_gg(MP) { return ldi16(&cHL, regs16[sda]->R()); }
  virtual int LD_rrIX_gg(MP) { return ldi16(&cIX, regs16[sda]->R()); }
  virtual int LD_rrIY_gg(MP) { return ldi16(&cIY, regs16[sda]->R()); }
  virtual int LD_rrSP_gg(MP) { return ldi16(&cSP, regs16[sda]->R()); }
  // 1 50 - 1 5f
  virtual int XOR_CF_g_0(MP) { return xor1r(regs8[sda], 0); }
  virtual int XOR_CF_g_1(MP) { return xor1r(regs8[sda], 1); }
  virtual int XOR_CF_g_2(MP) { return xor1r(regs8[sda], 2); }
  virtual int XOR_CF_g_3(MP) { return xor1r(regs8[sda], 3); }
  virtual int XOR_CF_g_4(MP) { return xor1r(regs8[sda], 4); }
  virtual int XOR_CF_g_5(MP) { return xor1r(regs8[sda], 5); }
  virtual int XOR_CF_g_6(MP) { return xor1r(regs8[sda], 6); }
  virtual int XOR_CF_g_7(MP) { return xor1r(regs8[sda], 7); }
  virtual int LD_CF_g_0(MP) { return ld1r(regs8[sda], 0); }
  virtual int LD_CF_g_1(MP) { return ld1r(regs8[sda], 1); }
  virtual int LD_CF_g_2(MP) { return ld1r(regs8[sda], 2); }
  virtual int LD_CF_g_3(MP) { return ld1r(regs8[sda], 3); }
  virtual int LD_CF_g_4(MP) { return ld1r(regs8[sda], 4); }
  virtual int LD_CF_g_5(MP) { return ld1r(regs8[sda], 5); }
  virtual int LD_CF_g_6(MP) { return ld1r(regs8[sda], 6); }
  virtual int LD_CF_g_7(MP) { return ld1r(regs8[sda], 7); }
  // 1 70 - 1 7f
  virtual int XCH_rA_g(MP) { return xch8_rr(&cA, regs8[sda]); }
  virtual int XCH_rW_g(MP) { return xch8_rr(&cW, regs8[sda]); }
  virtual int XCH_rC_g(MP) { return xch8_rr(&cC, regs8[sda]); }
  virtual int XCH_rB_g(MP) { return xch8_rr(&cB, regs8[sda]); }
  virtual int XCH_rE_g(MP) { return xch8_rr(&cE, regs8[sda]); }
  virtual int XCH_rD_g(MP) { return xch8_rr(&cD, regs8[sda]); }
  virtual int XCH_rL_g(MP) { return xch8_rr(&cL, regs8[sda]); }
  virtual int XCH_rH_g(MP) { return xch8_rr(&cH, regs8[sda]); }
  virtual int XCH_rrWA_g(MP) { return xch16_rr(&cWA, regs16[sda]); }
  virtual int XCH_rrBC_g(MP) { return xch16_rr(&cBC, regs16[sda]); }
  virtual int XCH_rrDE_g(MP) { return xch16_rr(&cDE, regs16[sda]); }
  virtual int XCH_rrHL_g(MP) { return xch16_rr(&cHL, regs16[sda]); }
  virtual int XCH_rrIX_g(MP) { return xch16_rr(&cIX, regs16[sda]); }
  virtual int XCH_rrIY_g(MP) { return xch16_rr(&cIY, regs16[sda]); }
  virtual int XCH_rrSP_g(MP) { return xch16_rr(&cSP, regs16[sda]); }
  // 1 c0 - 1 cf
  virtual int SET_g_0(MP) { return setr(regs8[sda], 0); }
  virtual int SET_g_1(MP) { return setr(regs8[sda], 1); }
  virtual int SET_g_2(MP) { return setr(regs8[sda], 2); }
  virtual int SET_g_3(MP) { return setr(regs8[sda], 3); }
  virtual int SET_g_4(MP) { return setr(regs8[sda], 4); }
  virtual int SET_g_5(MP) { return setr(regs8[sda], 5); }
  virtual int SET_g_6(MP) { return setr(regs8[sda], 6); }
  virtual int SET_g_7(MP) { return setr(regs8[sda], 7); }
  virtual int CLR_g_0(MP) { return clrr(regs8[sda], 0); }
  virtual int CLR_g_1(MP) { return clrr(regs8[sda], 1); }
  virtual int CLR_g_2(MP) { return clrr(regs8[sda], 2); }
  virtual int CLR_g_3(MP) { return clrr(regs8[sda], 3); }
  virtual int CLR_g_4(MP) { return clrr(regs8[sda], 4); }
  virtual int CLR_g_5(MP) { return clrr(regs8[sda], 5); }
  virtual int CLR_g_6(MP) { return clrr(regs8[sda], 6); }
  virtual int CLR_g_7(MP) { return clrr(regs8[sda], 7); }
  // 1 d0 - 1 df
  virtual int LD_PSW_n(MP) { cF.W(fetch()); return resGO; }
  // 1 e0 - 1 ef
  virtual int CPL_g_0(MP) { return cplr(regs8[sda], 0); }
  virtual int CPL_g_1(MP) { return cplr(regs8[sda], 1); }
  virtual int CPL_g_2(MP) { return cplr(regs8[sda], 2); }
  virtual int CPL_g_3(MP) { return cplr(regs8[sda], 3); }
  virtual int CPL_g_4(MP) { return cplr(regs8[sda], 4); }
  virtual int CPL_g_5(MP) { return cplr(regs8[sda], 5); }
  virtual int CPL_g_6(MP) { return cplr(regs8[sda], 6); }
  virtual int CPL_g_7(MP) { return cplr(regs8[sda], 7); }
  virtual int LD_g_0_CF(MP) { return st1r(regs8[sda], 0); }
  virtual int LD_g_1_CF(MP) { return st1r(regs8[sda], 1); }
  virtual int LD_g_2_CF(MP) { return st1r(regs8[sda], 2); }
  virtual int LD_g_3_CF(MP) { return st1r(regs8[sda], 3); }
  virtual int LD_g_4_CF(MP) { return st1r(regs8[sda], 4); }
  virtual int LD_g_5_CF(MP) { return st1r(regs8[sda], 5); }
  virtual int LD_g_6_CF(MP) { return st1r(regs8[sda], 6); }
  virtual int LD_g_7_CF(MP) { return st1r(regs8[sda], 7); }
  // 1 f0 - 1 ff
  virtual int SWAP_g(MP);
  // 2 40 - 2 4f
  virtual int LD_rA_src(MP) { return ld8(&cA, sdc); }
  virtual int LD_rW_src(MP) { return ld8(&cW, sdc); }
  virtual int LD_rC_src(MP) { return ld8(&cC, sdc); }
  virtual int LD_rB_src(MP) { return ld8(&cB, sdc); }
  virtual int LD_rE_src(MP) { return ld8(&cE, sdc); }
  virtual int LD_rD_src(MP) { return ld8(&cD, sdc); }
  virtual int LD_rL_src(MP) { return ld8(&cL, sdc); }
  virtual int LD_rH_src(MP) { return ld8(&cH, sdc); }
  virtual int LD_rrWA_src(MP) { return ld16(&cWA, sda); }
  virtual int LD_rrBC_src(MP) { return ld16(&cBC, sda); }
  virtual int LD_rrDE_src(MP) { return ld16(&cDE, sda); }
  virtual int LD_rrHL_src(MP) { return ld16(&cHL, sda); }
  virtual int LD_rrIX_src(MP) { return ld16(&cIX, sda); }
  virtual int LD_rrIY_src(MP) { return ld16(&cIY, sda); }
  virtual int LD_rrSP_src(MP) { return ld16(&cSP, sda); }
  // 2 50 - 2 5f
  virtual int XOR_CF_src_0(MP) { return xor1m(sdc, 0); }
  virtual int XOR_CF_src_1(MP) { return xor1m(sdc, 1); }
  virtual int XOR_CF_src_2(MP) { return xor1m(sdc, 2); }
  virtual int XOR_CF_src_3(MP) { return xor1m(sdc, 3); }
  virtual int XOR_CF_src_4(MP) { return xor1m(sdc, 4); }
  virtual int XOR_CF_src_5(MP) { return xor1m(sdc, 5); }
  virtual int XOR_CF_src_6(MP) { return xor1m(sdc, 6); }
  virtual int XOR_CF_src_7(MP) { return xor1m(sdc, 7); }
  virtual int LD_CF_src_0(MP) { return ld1m(sdc, 0); }
  virtual int LD_CF_src_1(MP) { return ld1m(sdc, 1); }
  virtual int LD_CF_src_2(MP) { return ld1m(sdc, 2); }
  virtual int LD_CF_src_3(MP) { return ld1m(sdc, 3); }
  virtual int LD_CF_src_4(MP) { return ld1m(sdc, 4); }
  virtual int LD_CF_src_5(MP) { return ld1m(sdc, 5); }
  virtual int LD_CF_src_6(MP) { return ld1m(sdc, 6); }
  virtual int LD_CF_src_7(MP) { return ld1m(sdc, 7); }
  // 2 60 - 2 6f
  virtual int LD_dst_rrWA(MP) { return st16(sda, rWA); }
  virtual int LD_dst_rrBC(MP) { return st16(sda, rBC); }
  virtual int LD_dst_rrDE(MP) { return st16(sda, rDE); }
  virtual int LD_dst_rrHL(MP) { return st16(sda, rHL); }
  virtual int LD_dst_rrIX(MP) { return st16(sda, rIX); }
  virtual int LD_dst_rrIY(MP) { return st16(sda, rIY); }
  virtual int LD_dst_rrSP(MP) { return st16(sda, rSP); }
  // 2 70 - 2 7f
  virtual int XCH_rA_src(MP) { return xch8_rm(&cA, sdc); }
  virtual int XCH_rW_src(MP) { return xch8_rm(&cW, sdc); }
  virtual int XCH_rC_src(MP) { return xch8_rm(&cC, sdc); }
  virtual int XCH_rB_src(MP) { return xch8_rm(&cB, sdc); }
  virtual int XCH_rE_src(MP) { return xch8_rm(&cE, sdc); }
  virtual int XCH_rD_src(MP) { return xch8_rm(&cD, sdc); }
  virtual int XCH_rL_src(MP) { return xch8_rm(&cL, sdc); }
  virtual int XCH_rH_src(MP) { return xch8_rm(&cH, sdc); }
  virtual int LD_dst_rA(MP) { return st8(sdc, rA); }
  virtual int LD_dst_rW(MP) { return st8(sdc, rW); }
  virtual int LD_dst_rC(MP) { return st8(sdc, rC); }
  virtual int LD_dst_rB(MP) { return st8(sdc, rB); }
  virtual int LD_dst_rE(MP) { return st8(sdc, rE); }
  virtual int LD_dst_rD(MP) { return st8(sdc, rD); }
  virtual int LD_dst_rL(MP) { return st8(sdc, rL); }
  virtual int LD_dst_rH(MP) { return st8(sdc, rH); }
  // 2 c0 - 2 cf
  virtual int SET_src_0(MP) { return setm(sdc, 0); }
  virtual int SET_src_1(MP) { return setm(sdc, 1); }
  virtual int SET_src_2(MP) { return setm(sdc, 2); }
  virtual int SET_src_3(MP) { return setm(sdc, 3); }
  virtual int SET_src_4(MP) { return setm(sdc, 4); }
  virtual int SET_src_5(MP) { return setm(sdc, 5); }
  virtual int SET_src_6(MP) { return setm(sdc, 6); }
  virtual int SET_src_7(MP) { return setm(sdc, 7); }
  virtual int CLR_src_0(MP) { return clrm(sdc, 0); }
  virtual int CLR_src_1(MP) { return clrm(sdc, 1); }
  virtual int CLR_src_2(MP) { return clrm(sdc, 2); }
  virtual int CLR_src_3(MP) { return clrm(sdc, 3); }
  virtual int CLR_src_4(MP) { return clrm(sdc, 4); }
  virtual int CLR_src_5(MP) { return clrm(sdc, 5); }
  virtual int CLR_src_6(MP) { return clrm(sdc, 6); }
  virtual int CLR_src_7(MP) { return clrm(sdc, 7); }
  // 2 c0 - c8
  virtual int XCH_rrWA_src(MP)  { return xch16_rm(&cWA, sda); }
  virtual int XCH_rrBC_src(MP)  { return xch16_rm(&cBC, sda); }
  virtual int XCH_rrDE_src(MP)  { return xch16_rm(&cDE, sda); }
  virtual int XCH_rrHL3_src(MP) { return xch16_rm(&cHL, sda); }
  virtual int XCH_rrIX_src(MP)  { return xch16_rm(&cIX, sda); }
  virtual int XCH_rrIY_src(MP)  { return xch16_rm(&cIY, sda); }
  virtual int XCH_rrSP_src(MP)  { return xch16_rm(&cSP, sda); }
  virtual int XCH_rrHL7_src(MP) { return xch16_rm(&cHL, sda); }
  // 2 e0 - 2 ef
  virtual int CPL_src_0(MP) { return cplm(sdc, 0); }
  virtual int CPL_src_1(MP) { return cplm(sdc, 1); }
  virtual int CPL_src_2(MP) { return cplm(sdc, 2); }
  virtual int CPL_src_3(MP) { return cplm(sdc, 3); }
  virtual int CPL_src_4(MP) { return cplm(sdc, 4); }
  virtual int CPL_src_5(MP) { return cplm(sdc, 5); }
  virtual int CPL_src_6(MP) { return cplm(sdc, 6); }
  virtual int CPL_src_7(MP) { return cplm(sdc, 7); }
  virtual int LD_src_0_CF(MP) { return st1m(sdc, 0); }
  virtual int LD_src_1_CF(MP) { return st1m(sdc, 1); }
  virtual int LD_src_2_CF(MP) { return st1m(sdc, 2); }
  virtual int LD_src_3_CF(MP) { return st1m(sdc, 3); }
  virtual int LD_src_4_CF(MP) { return st1m(sdc, 4); }
  virtual int LD_src_5_CF(MP) { return st1m(sdc, 5); }
  virtual int LD_src_6_CF(MP) { return st1m(sdc, 6); }
  virtual int LD_src_7_CF(MP) { return st1m(sdc, 7); }
  // 2 f0 - 2 ff
  virtual int SET_src_A(MP) { return setm(sdc, rA&7); }
  virtual int LD_src_A_CF(MP);
  virtual int LD_dst_n(MP) { return st8(sdc, fetch()); }
  virtual int CPL_src_A(MP) { return cplm(sdc, rA&7); }
  virtual int CLR_src_A(MP) { return clrm(sdc, rA&7); }
  virtual int LD_CF_src_A(MP);
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
