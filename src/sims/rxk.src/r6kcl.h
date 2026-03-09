/*
 * Simulator of microcontrollers (r6kcl.h)
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

#ifndef R6KCL_HEADER
#define R6KCL_HEADER

#include "r5kcl.h"
#include "r6kwrap.h"
#include "dp0m6.h"


class cl_r6k: public cl_r5k
{
public:
  
 public:
  cl_r6k(class cl_sim *asim);
  virtual const char *id_string(void);
  virtual int init(void);

  virtual struct dis_entry *dis_entry(t_addr addr);

  virtual void mode3k(void);
  virtual void mode01(void);
  virtual void mode10(void);
  virtual void mode4k(void);

  // set flagC too
  virtual int inc_r(class cl_cell8 &cr, u8_t op);
  virtual int inc_i8(t_addr addr);
  virtual int dec_r(class cl_cell8 &cr, u8_t op);
  virtual int dec_i8(t_addr addr);
  
  // page0 (mode11) and page 7f (mode10)
  virtual int JP_GE_MN(MP) { return jp_f_mn(cond_GE(rF)); }
  virtual int JP_LE_MN(MP) { return jp_f_mn(cond_LE(rF)); }
  virtual int JP_LEU_MN(MP) { return jp_f_mn(cond_LEU(rF)); }
  virtual int JR_GE_E(MP) { return jr_cc(cond_GE(rF)); }
  virtual int JR_LE_E(MP) { return jr_cc(cond_LE(rF)); }
  virtual int JR_LEU_E(MP) { return jr_cc(cond_LEU(rF)); }
  virtual int EX_JKHL_BCDE_(MP);
  virtual int MUL_HL_DE(MP);
  virtual int MULU_HL_DE(MP);
  // page ed
  virtual int TEST_DE(MP) { return test16(rDE); }
  virtual int tstnull_pp(u32_t pp);
  virtual int TSTNULL_PW(MP) { return tstnull_pp(rPW); }
  virtual int TSTNULL_PX(MP) { return tstnull_pp(rPX); }
  virtual int TSTNULL_PY(MP) { return tstnull_pp(rPY); }
  virtual int TSTNULL_PZ(MP) { return tstnull_pp(rPZ); }
  virtual int swap_r(u8_t sr, C8 &dr);
  virtual int SWAP_B(MP) { return swap_r(rB, destB()); }
  virtual int SWAP_C(MP) { return swap_r(rC, destC()); }
  virtual int SWAP_D(MP) { return swap_r(rD, destD()); }
  virtual int SWAP_E(MP) { return swap_r(rE, destE()); }
  virtual int SWAP_H(MP) { return swap_r(rH, destH()); }
  virtual int SWAP_L(MP) { return swap_r(rL, destL()); }
  virtual int SWAP_A(MP) { return swap_r(rA, destA()); }
  virtual int swap_rp(u16_t sr, C16 &dr);
  virtual int SWAP_BC(MP) { return swap_rp(rBC, destBC()); }
  virtual int SWAP_DE(MP) { return swap_rp(rDE, destDE()); }
  virtual int SWAP_HL(MP) { return swap_rp(rHL, destHL()); }
  virtual int SWAP_JK(MP) { return swap_rp(rJK, destJK()); }
  virtual int lljp_cc(bool cond);
  virtual int LLJP_LEU_LXPC_MN(MP) { return lljp_cc((bool)cond_LEU(rF)); }
  virtual int LLJP_GE_LXPC_MN(MP) { return lljp_cc((bool)cond_GE(rF)); }
  virtual int LLJP_LE_LXPC_MN(MP) { return lljp_cc((bool)cond_LE(rF)); }
  virtual int JRE_GE_EE(MP) { return jre_cx_cc(cond_GE(rF)); }
  virtual int JRE_LE_EE(MP) { return jre_cx_cc(cond_LE(rF)); }
  virtual int JRE_LEU_EE(MP) { return jre_cx_cc(cond_LEU(rF)); }
  virtual int FLAG_GE_HL(MP) { destHL().W(cond_GE(rF)?1:0); tick(3); return resGO; }
  virtual int FLAG_LE_HL(MP) { destHL().W(cond_LE(rF)?1:0); tick(3); return resGO; }
  virtual int FLAG_LEU_HL(MP) { destHL().W(cond_LEU(rF)?1:0); tick(3); return resGO; }
  virtual int ADC_JKHL_BCDE(MP) {return add32(destJKHL(), rJKHL, rBCDE, true); }
  virtual int SBC_JKHL_BCDE(MP) {return sub32(destJKHL(), rJKHL, rBCDE, true); }
  // page dd/fd
  virtual int swap_32(u32_t sr, C32 &dr);
  virtual int SWAP_IRR(MP) { return swap_32(cIRR->get(), *cIRR); }
  virtual int AND_HL_iIRd(MP) { tick(8); return and16(destHL(), rHL, op16_iIRd()); }
  virtual int AND_JKHL_iIRd(MP) { tick(15); return and32(destJKHL(), rJKHL, op32_iIRd()); }
  virtual int XOR_HL_iIRd(MP) { tick(8); return xor16(destHL(), rHL, op16_iIRd()); }
  virtual int XOR_JKHL_iIRd(MP) { tick(15); return xor32(destJKHL(), rJKHL, op32_iIRd()); }
  virtual int OR_HL_iIRd(MP) { tick(8); return or16(destHL(), rHL, op16_iIRd()); }
  virtual int OR_JKHL_iIRd(MP) { tick(15); return or32(destJKHL(), rJKHL, op32_iIRd()); }
  virtual int CP_HL_iIRd(MP) { tick(8); return cp16(rHL, op16_iIRd()); }
  virtual int CP_JKHL_iIRd(MP) { tick(12); return cp32(rJKHL, op32_iIRd()); }
  virtual int ADD_IR_D(MP);
  virtual int ADD_HL_iIRd(MP)   { tick(8);  return add16(destHL(), rHL, op16_iIRd(), false); }
  virtual int ADD_JKHL_iIRd(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iIRd(), false); }
  virtual int ADC_HL_iIRd(MP)   { tick(8);  return add16(destHL(), rHL, op16_iIRd(), true); }
  virtual int ADC_JKHL_iIRd(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iIRd(), true); }
  virtual int SUB_HL_iIRd(MP)   { tick(8);  return sub16(destHL(), rHL, op16_iIRd(), false); }
  virtual int SUB_JKHL_iIRd(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iIRd(), false); }
  virtual int SBC_HL_iIRd(MP)   { tick(8);  return sub16(destHL(), rHL, op16_iIRd(), true); }
  virtual int SBC_JKHL_iIRd(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iIRd(), true); }

  // page 49
  virtual int PAGE_6K49(MP);
  // ALU 8bit, SP+n
  virtual int ADD_A_iSPn(MP) { tick(6); return add8(op8_iSPn(), false); }
  virtual int ADC_A_iSPn(MP) { tick(6); return add8(op8_iSPn(), true); }
  virtual int SUB_A_iSPn(MP) { tick(6); return sub8(op8_iSPn(), false); }
  virtual int SBC_A_iSPn(MP) { tick(6); return sub8(op8_iSPn(), true); }
  virtual int AND_A_iSPn(MP) { tick(8); return and8(destA(), rA, op8_iSPn()); }
  virtual int XOR_A_iSPn(MP) { tick(6); return xor8(destA(), rA, op8_iSPn()); }
  virtual int OR_A_iSPn(MP)  { tick(8); return or8 (destA(), rA, op8_iSPn()); }
  virtual int CP_A_iSPn(MP)  { tick(6); return cp8 (rA, op8_iSPn()); }
  // ALU 16 bit, SP+n
  virtual int ADD_HL_iSPn(MP) { tick(8);  return add16(destHL(), rHL, op16_iSPn(), false); }
  virtual int ADC_HL_iSPn(MP) { tick(8);  return add16(destHL(), rHL, op16_iSPn(), true); }
  virtual int SUB_HL_iSPn(MP) { tick(8);  return sub16(destHL(), rHL, op16_iSPn(), false); }
  virtual int SBC_HL_iSPn(MP) { tick(8);  return sub16(destHL(), rHL, op16_iSPn(), true); }
  virtual int AND_HL_iSPn(MP) { tick(10); return and16(destHL(), rHL, op16_iSPn()); }
  virtual int XOR_HL_iSPn(MP) { tick(8);  return xor16(destHL(), rHL, op16_iSPn()); }
  virtual int OR_HL_iSPn(MP)  { tick(10); return or16 (destHL(), rHL, op16_iSPn()); }
  virtual int CP_HL_iSPn(MP)  { tick(8);  return cp16 (rHL, op16_iSPn()); }
  // ALU 32 bit, SP+n
  virtual int ADD_JKHL_iSPn(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iSPn(), false); }
  virtual int ADC_JKHL_iSPn(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iSPn(), true); }
  virtual int SUB_JKHL_iSPn(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iSPn(), false); }
  virtual int SBC_JKHL_iSPn(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iSPn(), true); }
  virtual int AND_JKHL_iSPn(MP) { tick(14); return and32(destJKHL(), rJKHL, op32_iSPn()); }
  virtual int XOR_JKHL_iSPn(MP) { tick(12); return xor32(destJKHL(), rJKHL, op32_iSPn()); }
  virtual int OR_JKHL_iSPn(MP)  { tick(14); return or32 (destJKHL(), rJKHL, op32_iSPn()); }
  virtual int CP_JKHL_iSPn(MP)  { tick(12); return cp32 (rJKHL, op32_iSPn()); }
  // 00-10
  virtual int ADD_JKHL_PW(MP)   { return add32(destJKHL(), rJKHL, rPW, false); }
  virtual int ADD_JKHL_PX(MP)   { return add32(destJKHL(), rJKHL, rPX, false); }
  virtual int ADD_JKHL_PY(MP)   { return add32(destJKHL(), rJKHL, rPY, false); }
  virtual int ADD_JKHL_PZ(MP)   { return add32(destJKHL(), rJKHL, rPZ, false); }
  virtual int ADD_A_iPWd(MP)    { tick(9);  return add8 (destA   (),    rA, op8_iPSd (rPW, fetch()), false); }
  virtual int ADD_A_iPXd(MP)    { tick(9);  return add8 (destA   (),    rA, op8_iPSd (rPW, fetch()), false); }
  virtual int ADD_A_iPYd(MP)    { tick(9);  return add8 (destA   (),    rA, op8_iPSd (rPW, fetch()), false); }
  virtual int ADD_A_iPZd(MP)    { tick(9);  return add8 (destA   (),    rA, op8_iPSd (rPW, fetch()), false); }
  virtual int ADD_HL_iPWd(MP)   { tick(8);  return add16(destHL  (),   rHL, op16_iPSd(rPW, fetch()), false); }
  virtual int ADD_HL_iPXd(MP)   { tick(8);  return add16(destHL  (),   rHL, op16_iPSd(rPX, fetch()), false); }
  virtual int ADD_HL_iPYd(MP)   { tick(8);  return add16(destHL  (),   rHL, op16_iPSd(rPY, fetch()), false); }
  virtual int ADD_HL_iPZd(MP)   { tick(8);  return add16(destHL  (),   rHL, op16_iPSd(rPZ, fetch()), false); }
  virtual int ADD_JKHL_iPWd(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iPSd(rPW, fetch()), false); }
  virtual int ADD_JKHL_iPXd(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iPSd(rPX, fetch()), false); }
  virtual int ADD_JKHL_iPYd(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iPSd(rPY, fetch()), false); }
  virtual int ADD_JKHL_iPZd(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iPSd(rPZ, fetch()), false); }
  // 10-1f
  virtual int ADC_JKHL_PW(MP)   { return add32(destJKHL(), rJKHL, rPW, true); }
  virtual int ADC_JKHL_PX(MP)   { return add32(destJKHL(), rJKHL, rPX, true); }
  virtual int ADC_JKHL_PY(MP)   { return add32(destJKHL(), rJKHL, rPY, true); }
  virtual int ADC_JKHL_PZ(MP)   { return add32(destJKHL(), rJKHL, rPZ, true); }
  virtual int ADC_A_iPWd(MP)    { tick(9);  return add8 (destA   (),    rA, op8_iPSd (rPW, fetch()), true); }
  virtual int ADC_A_iPXd(MP)    { tick(9);  return add8 (destA   (),    rA, op8_iPSd (rPW, fetch()), true); }
  virtual int ADC_A_iPYd(MP)    { tick(9);  return add8 (destA   (),    rA, op8_iPSd (rPW, fetch()), true); }
  virtual int ADC_A_iPZd(MP)    { tick(9);  return add8 (destA   (),    rA, op8_iPSd (rPW, fetch()), true); }
  virtual int ADC_HL_iPWd(MP)   { tick(8);  return add16(destHL  (),   rHL, op16_iPSd(rPW, fetch()), true); }
  virtual int ADC_HL_iPXd(MP)   { tick(8);  return add16(destHL  (),   rHL, op16_iPSd(rPX, fetch()), true); }
  virtual int ADC_HL_iPYd(MP)   { tick(8);  return add16(destHL  (),   rHL, op16_iPSd(rPY, fetch()), true); }
  virtual int ADC_HL_iPZd(MP)   { tick(8);  return add16(destHL  (),   rHL, op16_iPSd(rPZ, fetch()), true); }
  virtual int ADC_JKHL_iPWd(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iPSd(rPW, fetch()), true); }
  virtual int ADC_JKHL_iPXd(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iPSd(rPX, fetch()), true); }
  virtual int ADC_JKHL_iPYd(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iPSd(rPY, fetch()), true); }
  virtual int ADC_JKHL_iPZd(MP) { tick(12); return add32(destJKHL(), rJKHL, op32_iPSd(rPZ, fetch()), true); }
  // 20-2f
  virtual int SUB_JKHL_PW(MP)   { return sub32(destJKHL(), rJKHL, rPW, false); }
  virtual int SUB_JKHL_PX(MP)   { return sub32(destJKHL(), rJKHL, rPX, false); }
  virtual int SUB_JKHL_PY(MP)   { return sub32(destJKHL(), rJKHL, rPY, false); }
  virtual int SUB_JKHL_PZ(MP)   { return sub32(destJKHL(), rJKHL, rPZ, false); }
  virtual int SUB_A_iPWd(MP)    { tick(6);  return sub8 (destA   (),    rA, op8_iPSd (rPW, fetch()), false); }
  virtual int SUB_A_iPXd(MP)    { tick(6);  return sub8 (destA   (),    rA, op8_iPSd (rPW, fetch()), false); }
  virtual int SUB_A_iPYd(MP)    { tick(6);  return sub8 (destA   (),    rA, op8_iPSd (rPW, fetch()), false); }
  virtual int SUB_A_iPZd(MP)    { tick(6);  return sub8 (destA   (),    rA, op8_iPSd (rPW, fetch()), false); }
  virtual int SUB_HL_iPWd(MP)   { tick(8);  return sub16(destHL  (),   rHL, op16_iPSd(rPW, fetch()), false); }
  virtual int SUB_HL_iPXd(MP)   { tick(8);  return sub16(destHL  (),   rHL, op16_iPSd(rPX, fetch()), false); }
  virtual int SUB_HL_iPYd(MP)   { tick(8);  return sub16(destHL  (),   rHL, op16_iPSd(rPY, fetch()), false); }
  virtual int SUB_HL_iPZd(MP)   { tick(8);  return sub16(destHL  (),   rHL, op16_iPSd(rPZ, fetch()), false); }
  virtual int SUB_JKHL_iPWd(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iPSd(rPW, fetch()), false); }
  virtual int SUB_JKHL_iPXd(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iPSd(rPX, fetch()), false); }
  virtual int SUB_JKHL_iPYd(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iPSd(rPY, fetch()), false); }
  virtual int SUB_JKHL_iPZd(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iPSd(rPZ, fetch()), false); }
  // 30-3f
  virtual int SBC_JKHL_PW(MP)   { return sub32(destJKHL(), rJKHL, rPW, true); }
  virtual int SBC_JKHL_PX(MP)   { return sub32(destJKHL(), rJKHL, rPX, true); }
  virtual int SBC_JKHL_PY(MP)   { return sub32(destJKHL(), rJKHL, rPY, true); }
  virtual int SBC_JKHL_PZ(MP)   { return sub32(destJKHL(), rJKHL, rPZ, true); }
  virtual int SBC_A_iPWd(MP)    { tick(6);  return sub8 (destA   (),    rA, op8_iPSd (rPW, fetch()), true); }
  virtual int SBC_A_iPXd(MP)    { tick(6);  return sub8 (destA   (),    rA, op8_iPSd (rPW, fetch()), true); }
  virtual int SBC_A_iPYd(MP)    { tick(6);  return sub8 (destA   (),    rA, op8_iPSd (rPW, fetch()), true); }
  virtual int SBC_A_iPZd(MP)    { tick(6);  return sub8 (destA   (),    rA, op8_iPSd (rPW, fetch()), true); }
  virtual int SBC_HL_iPWd(MP)   { tick(8);  return sub16(destHL  (),   rHL, op16_iPSd(rPW, fetch()), true); }
  virtual int SBC_HL_iPXd(MP)   { tick(8);  return sub16(destHL  (),   rHL, op16_iPSd(rPX, fetch()), true); }
  virtual int SBC_HL_iPYd(MP)   { tick(8);  return sub16(destHL  (),   rHL, op16_iPSd(rPY, fetch()), true); }
  virtual int SBC_HL_iPZd(MP)   { tick(8);  return sub16(destHL  (),   rHL, op16_iPSd(rPZ, fetch()), true); }
  virtual int SBC_JKHL_iPWd(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iPSd(rPW, fetch()), true); }
  virtual int SBC_JKHL_iPXd(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iPSd(rPX, fetch()), true); }
  virtual int SBC_JKHL_iPYd(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iPSd(rPY, fetch()), true); }
  virtual int SBC_JKHL_iPZd(MP) { tick(12); return sub32(destJKHL(), rJKHL, op32_iPSd(rPZ, fetch()), true); }
  // 40-4f
  virtual int AND_JKHL_PW(MP)   { tick(3);  return and32(destJKHL(), rJKHL, rPW); }
  virtual int AND_JKHL_PX(MP)   { tick(3);  return and32(destJKHL(), rJKHL, rPX); }
  virtual int AND_JKHL_PY(MP)   { tick(3);  return and32(destJKHL(), rJKHL, rPY); }
  virtual int AND_JKHL_PZ(MP)   { tick(3);  return and32(destJKHL(), rJKHL, rPZ); }
  virtual int AND_A_iPWd(MP)    { tick(8);  return and8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int AND_A_iPXd(MP)    { tick(8);  return and8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int AND_A_iPYd(MP)    { tick(8);  return and8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int AND_A_iPZd(MP)    { tick(8);  return and8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int AND_HL_iPWd(MP)   { tick(10); return and16(destHL  (),   rHL, op16_iPSd(rPW, fetch())); }
  virtual int AND_HL_iPXd(MP)   { tick(10); return and16(destHL  (),   rHL, op16_iPSd(rPX, fetch())); }
  virtual int AND_HL_iPYd(MP)   { tick(10); return and16(destHL  (),   rHL, op16_iPSd(rPY, fetch())); }
  virtual int AND_HL_iPZd(MP)   { tick(10); return and16(destHL  (),   rHL, op16_iPSd(rPZ, fetch())); }
  virtual int AND_JKHL_iPWd(MP) { tick(15); return and32(destJKHL(), rJKHL, op32_iPSd(rPW, fetch())); }
  virtual int AND_JKHL_iPXd(MP) { tick(15); return and32(destJKHL(), rJKHL, op32_iPSd(rPX, fetch())); }
  virtual int AND_JKHL_iPYd(MP) { tick(15); return and32(destJKHL(), rJKHL, op32_iPSd(rPY, fetch())); }
  virtual int AND_JKHL_iPZd(MP) { tick(15); return and32(destJKHL(), rJKHL, op32_iPSd(rPZ, fetch())); }
  // 50-5f
  virtual int XOR_JKHL_PW(MP)   { tick(3);  return xor32(destJKHL(), rJKHL, rPW); }
  virtual int XOR_JKHL_PX(MP)   { tick(3);  return xor32(destJKHL(), rJKHL, rPX); }
  virtual int XOR_JKHL_PY(MP)   { tick(3);  return xor32(destJKHL(), rJKHL, rPY); }
  virtual int XOR_JKHL_PZ(MP)   { tick(3);  return xor32(destJKHL(), rJKHL, rPZ); }
  virtual int XOR_A_iPWd(MP)    { tick(8);  return xor8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int XOR_A_iPXd(MP)    { tick(8);  return xor8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int XOR_A_iPYd(MP)    { tick(8);  return xor8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int XOR_A_iPZd(MP)    { tick(8);  return xor8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int XOR_HL_iPWd(MP)   { tick(10); return xor16(destHL  (),   rHL, op16_iPSd(rPW, fetch())); }
  virtual int XOR_HL_iPXd(MP)   { tick(10); return xor16(destHL  (),   rHL, op16_iPSd(rPX, fetch())); }
  virtual int XOR_HL_iPYd(MP)   { tick(10); return xor16(destHL  (),   rHL, op16_iPSd(rPY, fetch())); }
  virtual int XOR_HL_iPZd(MP)   { tick(10); return xor16(destHL  (),   rHL, op16_iPSd(rPZ, fetch())); }
  virtual int XOR_JKHL_iPWd(MP) { tick(15); return xor32(destJKHL(), rJKHL, op32_iPSd(rPW, fetch())); }
  virtual int XOR_JKHL_iPXd(MP) { tick(15); return xor32(destJKHL(), rJKHL, op32_iPSd(rPX, fetch())); }
  virtual int XOR_JKHL_iPYd(MP) { tick(15); return xor32(destJKHL(), rJKHL, op32_iPSd(rPY, fetch())); }
  virtual int XOR_JKHL_iPZd(MP) { tick(15); return xor32(destJKHL(), rJKHL, op32_iPSd(rPZ, fetch())); }
  // 60-6f
  virtual int OR_JKHL_PW(MP)   { tick(3);  return or32(destJKHL(), rJKHL, rPW); }
  virtual int OR_JKHL_PX(MP)   { tick(3);  return or32(destJKHL(), rJKHL, rPX); }
  virtual int OR_JKHL_PY(MP)   { tick(3);  return or32(destJKHL(), rJKHL, rPY); }
  virtual int OR_JKHL_PZ(MP)   { tick(3);  return or32(destJKHL(), rJKHL, rPZ); }
  virtual int OR_A_iPWd(MP)    { tick(8);  return or8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int OR_A_iPXd(MP)    { tick(8);  return or8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int OR_A_iPYd(MP)    { tick(8);  return or8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int OR_A_iPZd(MP)    { tick(8);  return or8 (destA   (),    rA, op8_iPSd (rPW, fetch())); }
  virtual int OR_HL_iPWd(MP)   { tick(10); return or16(destHL  (),   rHL, op16_iPSd(rPW, fetch())); }
  virtual int OR_HL_iPXd(MP)   { tick(10); return or16(destHL  (),   rHL, op16_iPSd(rPX, fetch())); }
  virtual int OR_HL_iPYd(MP)   { tick(10); return or16(destHL  (),   rHL, op16_iPSd(rPY, fetch())); }
  virtual int OR_HL_iPZd(MP)   { tick(10); return or16(destHL  (),   rHL, op16_iPSd(rPZ, fetch())); }
  virtual int OR_JKHL_iPWd(MP) { tick(15); return or32(destJKHL(), rJKHL, op32_iPSd(rPW, fetch())); }
  virtual int OR_JKHL_iPXd(MP) { tick(15); return or32(destJKHL(), rJKHL, op32_iPSd(rPX, fetch())); }
  virtual int OR_JKHL_iPYd(MP) { tick(15); return or32(destJKHL(), rJKHL, op32_iPSd(rPY, fetch())); }
  virtual int OR_JKHL_iPZd(MP) { tick(15); return or32(destJKHL(), rJKHL, op32_iPSd(rPZ, fetch())); }
  // 70-7f
  virtual int CP_JKHL_PW(MP)   { return cp32(rJKHL, rPW); }
  virtual int CP_JKHL_PX(MP)   { return cp32(rJKHL, rPX); }
  virtual int CP_JKHL_PY(MP)   { return cp32(rJKHL, rPY); }
  virtual int CP_JKHL_PZ(MP)   { return cp32(rJKHL, rPZ); }
  virtual int CP_A_iPWd(MP)    { tick(8);  return cp8 (   rA, op8_iPSd (rPW, fetch())); }
  virtual int CP_A_iPXd(MP)    { tick(8);  return cp8 (   rA, op8_iPSd (rPW, fetch())); }
  virtual int CP_A_iPYd(MP)    { tick(8);  return cp8 (   rA, op8_iPSd (rPW, fetch())); }
  virtual int CP_A_iPZd(MP)    { tick(8);  return cp8 (   rA, op8_iPSd (rPW, fetch())); }
  virtual int CP_HL_iPWd(MP)   { tick(8);  return cp16(  rHL, op16_iPSd(rPW, fetch())); }
  virtual int CP_HL_iPXd(MP)   { tick(8);  return cp16(  rHL, op16_iPSd(rPX, fetch())); }
  virtual int CP_HL_iPYd(MP)   { tick(8);  return cp16(  rHL, op16_iPSd(rPY, fetch())); }
  virtual int CP_HL_iPZd(MP)   { tick(8);  return cp16(  rHL, op16_iPSd(rPZ, fetch())); }
  virtual int CP_JKHL_iPWd(MP) { tick(12); return cp32(rJKHL, op32_iPSd(rPW, fetch())); }
  virtual int CP_JKHL_iPXd(MP) { tick(12); return cp32(rJKHL, op32_iPSd(rPX, fetch())); }
  virtual int CP_JKHL_iPYd(MP) { tick(12); return cp32(rJKHL, op32_iPSd(rPY, fetch())); }
  virtual int CP_JKHL_iPZd(MP) { tick(12); return cp32(rJKHL, op32_iPSd(rPZ, fetch())); }
  // inc-dec
  virtual int inc_iPSd(u32_t ps, i8_t d);
  virtual int INC_iPWd(MP) { tick(11); return inc_iPSd(rPW, fetch()); }
  virtual int INC_iPXd(MP) { tick(11); return inc_iPSd(rPX, fetch()); }
  virtual int INC_iPYd(MP) { tick(11); return inc_iPSd(rPY, fetch()); }
  virtual int INC_iPZd(MP) { tick(11); return inc_iPSd(rPZ, fetch()); }
  virtual int dec_iPSd(u32_t ps, i8_t d);
  virtual int DEC_iPWd(MP) { tick(11); return dec_iPSd(rPW, fetch()); }
  virtual int DEC_iPXd(MP) { tick(11); return dec_iPSd(rPX, fetch()); }
  virtual int DEC_iPYd(MP) { tick(11); return dec_iPSd(rPY, fetch()); }
  virtual int DEC_iPZd(MP) { tick(11); return dec_iPSd(rPZ, fetch()); }
  // shift-rotate reg
  virtual int SL1REG(MP);
  virtual int RL1REG(MP);
  virtual int SR1REG(MP);
  virtual int RR1REG(MP);
  virtual int SL2REG(MP);
  virtual int RL2REG(MP);
  virtual int SR2REG(MP);
  virtual int RR2REG(MP);
  virtual int SL3REG(MP);
  virtual int RL3REG(MP);
  virtual int SR3REG(MP);
  virtual int RR3REG(MP);
  virtual int SL4REG(MP);
  virtual int RL4REG(MP);
  virtual int SR4REG(MP);
  virtual int RR4REG(MP);
  virtual int SL5REG(MP);
  virtual int RL5REG(MP);
  virtual int SR5REG(MP);
  virtual int RR5REG(MP);
  virtual int SL6REG(MP);
  virtual int RL6REG(MP);
  virtual int SR6REG(MP);
  virtual int RR6REG(MP);
  virtual int SL7REG(MP);
  virtual int RL7REG(MP);
  virtual int SR7REG(MP);
  virtual int RR7REG(MP);
  virtual int SL8REG(MP);
  virtual int RL8REG(MP);
  virtual int SR8REG(MP);
  virtual int RR8REG(MP);
  // complex tasks
  virtual int SHAF1(MP);
  virtual int SHAF2(MP);
  virtual int SHAF3(MP);
  virtual int MD5F1(MP);
  virtual int MD5F2(MP);
  virtual int MD5F3(MP);
  // block stuff
  virtual void pldi(void);
  virtual int PLDI(MP) { tick(9); pldi(); return resGO; }
  virtual int PLDIR(MP);
  virtual int PLDISR(MP);
  virtual void pldd(void);
  virtual int PLDD(MP) { tick(9); pldd(); return resGO; }
  virtual int PLDDR(MP);
  virtual int PLDDSR(MP);
  virtual int PLSIR(MP);
  virtual int PLSIDR(MP);
  virtual int PLSDR(MP);
};


#endif

/* End of rxk.src/r6kcl.h */
