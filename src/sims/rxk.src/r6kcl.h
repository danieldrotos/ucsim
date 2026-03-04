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
  virtual int ADC_JKHL_BCDE(MP) {return add32(rJKHL, rBCDE, destJKHL(), true); }
  virtual int SBC_JKHL_BCDE(MP) {return sub32(rJKHL, rBCDE, destJKHL(), true); }
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
  virtual int ADD_HL_iIRd(MP) { tick(8); return add16(rHL, op16_iIRd(), destHL(), false); }
  virtual int ADD_JKHL_iIRd(MP) { tick(12); return add32(rJKHL, op32_iIRd(), destJKHL(), false); }
  virtual int ADC_HL_iIRd(MP) { tick(8); return add16(rHL, op16_iIRd(), destHL(), true); }
  virtual int ADC_JKHL_iIRd(MP) { tick(12); return add32(rJKHL, op32_iIRd(), destJKHL(), true); }
  virtual int SUB_HL_iIRd(MP) { tick(8); return sub16(op16_iIRd(), false); }
  virtual int SUB_JKHL_iIRd(MP) { tick(12); return sub32(rJKHL, op32_iIRd(), destJKHL(), false); }
  virtual int SBC_HL_iIRd(MP) { tick(8); return sub16(op16_iIRd(), true); }
  virtual int SBC_JKHL_iIRd(MP) { tick(12); return sub32(rJKHL, op32_iIRd(), destJKHL(), true); }

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
  virtual int ADD_HL_iSPn(MP) { tick(8);  return add16(rHL, op16_iSPn(), destHL(), false); }
  virtual int ADC_HL_iSPn(MP) { tick(8);  return add16(rHL, op16_iSPn(), destHL(), true); }
  virtual int SUB_HL_iSPn(MP) { tick(8);  return sub16(rHL, op16_iSPn(), destHL(), false); }
  virtual int SBC_HL_iSPn(MP) { tick(8);  return sub16(rHL, op16_iSPn(), destHL(), true); }
  virtual int AND_HL_iSPn(MP) { tick(10); return and16(destHL(), rHL, op16_iSPn()); }
  virtual int XOR_HL_iSPn(MP) { tick(8);  return xor16(destHL(), rHL, op16_iSPn()); }
  virtual int OR_HL_iSPn(MP)  { tick(10); return or16 (destHL(), rHL, op16_iSPn()); }
  virtual int CP_HL_iSPn(MP)  { tick(8);  return cp16 (rHL, op16_iSPn()); }
  // ALU 32 bit, SP+n
  virtual int ADD_JKHL_iSPn(MP) { tick(12); return add32(rJKHL, op32_iSPn(), destJKHL(), false); }
  virtual int ADC_JKHL_iSPn(MP) { tick(12); return add32(rJKHL, op32_iSPn(), destJKHL(), true); }
  virtual int SUB_JKHL_iSPn(MP) { tick(12); return sub32(rJKHL, op32_iSPn(), destJKHL(), false); }
  virtual int SBC_JKHL_iSPn(MP) { tick(12); return sub32(rJKHL, op32_iSPn(), destJKHL(), true); }
  virtual int AND_JKHL_iSPn(MP) { tick(14); return and32(destJKHL(), rJKHL, op32_iSPn()); }
  virtual int XOR_JKHL_iSPn(MP) { tick(12); return xor32(destJKHL(), rJKHL, op32_iSPn()); }
  virtual int OR_JKHL_iSPn(MP)  { tick(14); return or32 (destJKHL(), rJKHL, op32_iSPn()); }
  virtual int CP_JKHL_iSPn(MP)  { tick(12); return cp32 (rJKHL, op32_iSPn()); }
  // 00-10
  virtual int ADD_JKHL_PW(MP)   { return add32(rJKHL, rPW, destJKHL(), false); }
  virtual int ADD_JKHL_PX(MP)   { return add32(rJKHL, rPX, destJKHL(), false); }
  virtual int ADD_JKHL_PY(MP)   { return add32(rJKHL, rPY, destJKHL(), false); }
  virtual int ADD_JKHL_PZ(MP)   { return add32(rJKHL, rPZ, destJKHL(), false); }
  virtual int ADD_A_iPWd(MP)    { tick(6); return add8 (op8_iPSd(rPW, fetch()), false); }
  virtual int ADD_A_iPXd(MP)    { tick(6); return add8 (op8_iPSd(rPW, fetch()), false); }
  virtual int ADD_A_iPYd(MP)    { tick(6); return add8 (op8_iPSd(rPW, fetch()), false); }
  virtual int ADD_A_iPZd(MP)    { tick(6); return add8 (op8_iPSd(rPW, fetch()), false); }
  virtual int ADD_HL_iPWd(MP)   { tick(8); return add16(rHL, op16_iPSd(rPW, fetch()), destHL(), false); }
  virtual int ADD_HL_iPXd(MP)   { tick(8); return add16(rHL, op16_iPSd(rPX, fetch()), destHL(), false); }
  virtual int ADD_HL_iPYd(MP)   { tick(8); return add16(rHL, op16_iPSd(rPY, fetch()), destHL(), false); }
  virtual int ADD_HL_iPZd(MP)   { tick(8); return add16(rHL, op16_iPSd(rPZ, fetch()), destHL(), false); }
  virtual int ADD_JKHL_iPWd(MP) { tick(12); return add32(rJKHL, op32_iPSd(rPW, fetch()), destJKHL(), false); }
  virtual int ADD_JKHL_iPXd(MP) { tick(12); return add32(rJKHL, op32_iPSd(rPX, fetch()), destJKHL(), false); }
  virtual int ADD_JKHL_iPYd(MP) { tick(12); return add32(rJKHL, op32_iPSd(rPY, fetch()), destJKHL(), false); }
  virtual int ADD_JKHL_iPZd(MP) { tick(12); return add32(rJKHL, op32_iPSd(rPZ, fetch()), destJKHL(), false); }
};


#endif

/* End of rxk.src/r6kcl.h */
