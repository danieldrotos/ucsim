/*
 * Simulator of microcontrollers (r4kcl.h)
 *
 * Copyright (C) 2020,2021 Drotos Daniel, Talker Bt.
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

#ifndef R4KCL_HEADER
#define R4KCL_HEADER

#include "r3kacl.h"
#include "dp0m4.h"
#include "dpedm4.h"
#include "dpddm4.h"


extern inline u32_t px8(u32_t px, u8_t offset);
extern inline u32_t px8se(u32_t px, u8_t offset);
extern inline u32_t px16(u32_t px, u16_t offset);
extern inline u32_t px16se(u32_t px, u16_t offset);

//#define raJ	(aJK.r.J)
//#define raK	(aJK.r.K)
//#define raJK	(aJK.JK)
//#define raJKHL	(((u32_t)aJK.JK<<16)+aHL.HL)
//#define raBCDE	(((u32_t)aBC.BC<<16)+aDE.DE)

class cl_r4k: public cl_r3ka
{
public:
  RP(aJK,JK,J,K);
  u32_t rPW, rPX, rPY, rPZ;
  u32_t raPW, raPX, raPY, raPZ;
  u8_t rHTR;
  class cl_cell8 cJ, caJ, cK, caK;
  class cl_cell16 cJK, caJK;
  class cl_cell32 cJKHL, cPW, cPX, cPY, cPZ;
  class cl_cell32 caJKHL, caPW, caPX, caPY, caPZ;
  class cl_cell8 cHTR;
  class cl_cell16 *LXPC;
  class cl_cell32 *cIRR, *caIRR;
 public:
  cl_r4k(class cl_sim *asim);
  virtual int init();
  virtual const char *id_string(void);
  virtual void reset(void);
  
  virtual void make_cpu_hw(void);
  virtual t_addr chip_size() { return 0x1000000; }

  virtual struct dis_entry *dis_entry(t_addr addr);
  virtual struct dis_entry *dis_6d_entry(t_addr addr);
  virtual int longest_inst(void) { return 6; }
  virtual void disass_irr(chars *work, bool dd);
  
  virtual void select_IRR(bool dd);
  virtual class cl_cell32 *destIRR(void) { return altd?caIRR:cIRR; }
  
  virtual void print_regs(class cl_console_base *con);

  // move
  virtual int ld_pd_ihtr_hl(class cl_cell32 &dest);
  virtual int ld_irr_iird(class cl_cell16 &ir);			// 1f,14t,0w,4r
  virtual int ld_iird_irr(class cl_cell16 &ir);			// 1f,19t,4w,0r
  
  // arith
  virtual int subhl(class cl_cell16 &dest, u16_t op);
  virtual int test8(u8_t op);					// 0f,2t,0w,0r
  virtual int test16(u16_t op);					// 0f,2t,0w,0r
  virtual int test32(u32_t op);					// 0f,2t,0w,0r
  virtual int flag_cc_hl(t_mem code);				// 0f,4t,0w,0r
  
  // brach
  virtual int lljp_cx(t_mem code);				// 4f,14t,0w,0r
  virtual int lljp_cc(t_mem code);				// 4f,14t,0w,0r
  virtual int jre_cx_cc(bool cond);				// 2f,9t,0w,0r
  
  virtual void mode3k(void);
  virtual void mode4k(void);

  virtual int EXX(t_mem code);

  // Page 0, m4 mode
  virtual int RL_HL(t_mem code) { return rot17left(destHL(), rHL); }
  virtual int RL_BC(t_mem code) { return rot17left(destBC(), rBC); }
  virtual int SUB_HL_JK(t_mem code) { return subhl(destHL(), rJK); }
  virtual int SUB_HL_DE(t_mem code) { return subhl(destHL(), rDE); }
  virtual int TEST_HL(t_mem code) { return test16(rHL); }
  
  // Page ED, m4 mode
  virtual int CBM_N(t_mem code);
  virtual int LD_PW_iHTR_HL(t_mem code) { return ld_pd_ihtr_hl(cPW); }
  virtual int LD_PX_iHTR_HL(t_mem code) { return ld_pd_ihtr_hl(cPX); }
  virtual int LD_PY_iHTR_HL(t_mem code) { return ld_pd_ihtr_hl(cPY); }
  virtual int LD_PZ_iHTR_HL(t_mem code) { return ld_pd_ihtr_hl(cPZ); }
  virtual int SBOX_A(t_mem code);
  virtual int IBOX_A(t_mem code);
  virtual int DWJNZ(t_mem code);
  virtual int CP_HL_DE(t_mem code) { return cp16(rHL, rDE); }
  virtual int TEST_BC(t_mem code) { tick(2); return test16(rBC); }
  virtual int LLJP_GT_LXPC_MN(t_mem code)  { return lljp_cx(code); }
  virtual int LLJP_GTU_LXPC_MN(t_mem code) { return lljp_cx(code); }
  virtual int LLJP_LT_LXPC_MN(t_mem code)  { return lljp_cx(code); }
  virtual int LLJP_V_LXPC_MN(t_mem code)   { return lljp_cx(code); }
  virtual int LLJP_NZ_LXPC_MN(t_mem code)  { return lljp_cc(code); }
  virtual int LLJP_Z_LXPC_MN(t_mem code)   { return lljp_cc(code); }
  virtual int LLJP_NC_LXPC_MN(t_mem code)  { return lljp_cc(code); }
  virtual int LLJP_C_LXPC_MN(t_mem code)   { return lljp_cc(code); }
  virtual int PUSH_MN(t_mem code);
  virtual int JRE_GT_EE(t_mem code)  { return jre_cx_cc(cond_GT(rF)); }
  virtual int JRE_LT_EE(t_mem code)  { return jre_cx_cc(cond_LT(rF)); }
  virtual int JRE_GTU_EE(t_mem code) { return jre_cx_cc(cond_GTU(rF)); }
  virtual int JRE_V_EE(t_mem code)   { return jre_cx_cc(rF&flagV); }
  virtual int JRE_NZ_EE(t_mem code)  { return jre_cx_cc(!(rF&flagZ)); }
  virtual int JRE_Z_EE(t_mem code)   { return jre_cx_cc(rF&flagZ); }
  virtual int JRE_NC_EE(t_mem code)  { return jre_cx_cc(!(rF&flagC)); }
  virtual int JRE_C_EE(t_mem code)   { return jre_cx_cc(rF&flagC); }
  virtual int FLAG_NZ_HL(t_mem code) { return flag_cc_hl(code); }
  virtual int FLAG_Z_HL(t_mem code)   { return flag_cc_hl(code); }
  virtual int FLAG_NC_HL(t_mem code)  { return flag_cc_hl(code); }
  virtual int FLAG_C_HL(t_mem code)   { return flag_cc_hl(code); }
  virtual int FLAG_GT_HL(t_mem code)  { return flag_cc_hl(code); }
  virtual int FLAG_LT_HL(t_mem code)  { return flag_cc_hl(code); }
  virtual int FLAG_GTU_HL(t_mem code) { return flag_cc_hl(code); }
  virtual int FLAG_V_HL(t_mem code)   { return flag_cc_hl(code); }
  
  // Page DD/FD
  virtual int LD_A_iIRA(t_mem code);
  virtual int TEST_IR(t_mem code) { tick(2); return test16(cIR->get()); }
  virtual int LD_IRR_iHL(t_mem code);
  virtual int LD_IRR_iIXd(t_mem code) { return ld_irr_iird(cIX); }
  virtual int LD_IRR_iIYd(t_mem code) { return ld_irr_iird(cIY); }
  virtual int LD_IRR_iSPn(t_mem code);
  virtual int LD_iHL_IRR(t_mem code);
  virtual int LD_iIXd_IRR(t_mem code) { return ld_iird_irr(cIX); }
  virtual int LD_iIYd_IRR(t_mem code) { return ld_iird_irr(cIY); }
  virtual int LD_iSPn_IRR(t_mem code);
  virtual int NEG_IRR(t_mem coed) { return sub32(0, cIRR->get(),
						 *cIRR, false); }
  virtual int POP_IRR(t_mem code);
  virtual int PUSH_IRR(t_mem code);
    
  // Starter of extra pages
  virtual int PAGE_4K6D(t_mem code);
  virtual int PAGE_4K7F(t_mem code);
};

class cl_r4k_cpu: public cl_rxk_cpu
{
protected:
  class cl_r4k *r4uc;
  class cl_cell8 *edmr;
  class cl_memory_cell *stacksegl, *stacksegh;
  class cl_memory_cell *datasegl , *datasegh;
public:
  cl_r4k_cpu(class cl_uc *auc);
  virtual int init(void);
  virtual t_mem read(class cl_memory_cell *cell);
  virtual void write(class cl_memory_cell *cell, t_mem *val);
  virtual const char *cfg_help(t_addr addr);
  
  //virtual t_mem conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val);

  virtual void print_info(class cl_console_base *con);
};


#endif

/* End of rxk.src/r4kcl.h */
