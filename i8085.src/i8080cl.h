/*
 * Simulator of microcontrollers (i8080cl.h)
 *
 * Copyright (C) @@S@@,@@Y@@ Drotos Daniel, Talker Bt.
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

#ifndef I8080CL_HEADER
#define I8080CL_HEADER

#include "uccl.h"

#include "glob.h"
#include "decode.h"


#ifdef WORDS_BIGENDIAN
#define RP(N,N16,NH,NL) union			\
		      {				\
			u16_t N16;		\
			struct {		\
			  u8_t NH;		\
			  u8_t NL;		\
			} r;			\
  } N
#else
#define RP(N,N16,NH,NL) union			\
		      {				\
			u16_t N16;		\
			struct {		\
			  u8_t NL;		\
			  u8_t NH;		\
			} r;			\
  } N
#endif

#define rAF (rpAF.AF)
#define rA  (rpAF.r.A)
#define rF  (rpAF.r.F)

#define rBC (rpBC.BC)
#define rB  (rpBC.r.B)
#define rC  (rpBC.r.C)

#define rDE (rpDE.DE)
#define rD  (rpDE.r.D)
#define rE  (rpDE.r.E)

#define rHL (rpHL.HL)
#define rH  (rpHL.r.H)
#define rL  (rpHL.r.L)

#define rM  (vc.rd++,rom->read(rHL))


enum {
  flagC	= 0x01,
  flagP	= 0x04,
  flagA	= 0x10,
  flagZ	= 0x40,
  flagS	= 0x80,
  fAll= flagC|flagP|flagA|flagZ|flagS,
  fAll_C= flagP|flagA|flagZ|flagS
};


/*
 * Special handling of flags
 */

class cl_flags: public cl_cell8
{
public:
  virtual t_mem write(t_mem val);
};


/*
 * Base of i8080 processor
 */

class cl_i8080: public cl_uc
{
public:
  class cl_flags cF;
  RP(rpAF, AF, A, F);  class cl_cell8 cA    ;  class cl_cell16 cAF;
  RP(rpBC, BC, B, C);  class cl_cell8 cB, cC;  class cl_cell16 cBC;
  RP(rpDE, DE, D, E);  class cl_cell8 cD, cE;  class cl_cell16 cDE;
  RP(rpHL, HL, H, L);  class cl_cell8 cH, cL;  class cl_cell16 cHL;
  u16_t rSP; class cl_cell16 cSP;
public:
  cl_i8080(class cl_sim *asim);
  virtual int init(void);
  virtual const char *id_string(void);
  virtual void reset(void);
  virtual void set_PC(t_addr addr);

  virtual void mk_hw_elements(void);
  virtual void make_cpu_hw(void);
  virtual void make_memories(void);

  virtual int clock_per_cycle(void) { return 1; }
  virtual struct dis_entry *dis_tbl(void);
  virtual struct dis_entry *get_dis_entry(t_addr addr);
  virtual void dis_M(chars *comment);
  virtual void dis_rp8(chars *comment, int rp);
  virtual void dis_rp16(chars *comment, int rp);
  virtual char *disassc(t_addr addr, chars *comment=NULL);

  virtual void print_regs(class cl_console_base *con);

  virtual class cl_memory_cell &cM(void);
  virtual u16_t fetch16(void);
  virtual int exec_inst(void);
  
  virtual int NOP(t_mem code) { return resGO; }
  virtual int HLT(t_mem code);

  // Data transfer
  virtual int mvi8(class cl_memory_cell &dst);
  virtual int lxi16(class cl_memory_cell &dst);
  virtual int ldax(u16_t a);
  virtual int stax(u16_t a);
#include "imovrr.h"
  virtual int MVI_Ai8(t_mem code) { return mvi8(cA); }
  virtual int MVI_Bi8(t_mem code) { return mvi8(cB); }
  virtual int MVI_Ci8(t_mem code) { return mvi8(cC); }
  virtual int MVI_Di8(t_mem code) { return mvi8(cD); }
  virtual int MVI_Ei8(t_mem code) { return mvi8(cE); }
  virtual int MVI_Hi8(t_mem code) { return mvi8(cH); }
  virtual int MVI_Li8(t_mem code) { return mvi8(cL); }
  virtual int MVI_Mi8(t_mem code) { return mvi8(cM()); }

  virtual int LXI_Bi16(t_mem code) { return lxi16(cBC); }
  virtual int LXI_Di16(t_mem code) { return lxi16(cDE); }
  virtual int LXI_Hi16(t_mem code) { return lxi16(cHL); }
  virtual int LXI_Si16(t_mem code) { return lxi16(cSP); }

  virtual int LDA_a16(t_mem code);
  virtual int STA_a16(t_mem code);
  virtual int LHLD_a16(t_mem code);
  virtual int SHLD_a16(t_mem code);
  virtual int LDAX_B(t_mem code) { return ldax(rBC); }
  virtual int LDAX_D(t_mem code) { return ldax(rDE); }
  virtual int STAX_B(t_mem code) { return stax(rBC); }
  virtual int STAX_D(t_mem code) { return stax(rDE); }
  virtual int XCHG(t_mem code);

  // Arithmetic
  virtual int add8(u8_t op, bool add_c);
  virtual int sub8(u8_t op, bool sub_c);
  virtual int ADD_A(t_mem code) { return add8(rA, false); }
  virtual int ADD_B(t_mem code) { return add8(rB, false); }
  virtual int ADD_C(t_mem code) { return add8(rC, false); }
  virtual int ADD_D(t_mem code) { return add8(rD, false); }
  virtual int ADD_E(t_mem code) { return add8(rE, false); }
  virtual int ADD_H(t_mem code) { return add8(rH, false); }
  virtual int ADD_L(t_mem code) { return add8(rL, false); }
  virtual int ADD_M(t_mem code) { return add8(rM, false); }
  virtual int ADI(t_mem code) { return add8(fetch(), false); }
  virtual int ADC_A(t_mem code) { return add8(rA, true); }
  virtual int ADC_B(t_mem code) { return add8(rB, true); }
  virtual int ADC_C(t_mem code) { return add8(rC, true); }
  virtual int ADC_D(t_mem code) { return add8(rD, true); }
  virtual int ADC_E(t_mem code) { return add8(rE, true); }
  virtual int ADC_H(t_mem code) { return add8(rH, true); }
  virtual int ADC_L(t_mem code) { return add8(rL, true); }
  virtual int ADC_M(t_mem code) { return add8(rM, true); }
  virtual int ACI(t_mem code) { return add8(fetch(), true); }
  
  virtual int SUB_A(t_mem code) { return sub8(rA, false); }
  virtual int SUB_B(t_mem code) { return sub8(rB, false); }
  virtual int SUB_C(t_mem code) { return sub8(rC, false); }
  virtual int SUB_D(t_mem code) { return sub8(rD, false); }
  virtual int SUB_E(t_mem code) { return sub8(rE, false); }
  virtual int SUB_H(t_mem code) { return sub8(rH, false); }
  virtual int SUB_L(t_mem code) { return sub8(rL, false); }
  virtual int SUB_M(t_mem code) { return sub8(rM, false); }
  virtual int SUI(t_mem code) { return sub8(fetch(), false); }
  virtual int SBB_A(t_mem code) { return sub8(rA, true); }
  virtual int SBB_B(t_mem code) { return sub8(rB, true); }
  virtual int SBB_C(t_mem code) { return sub8(rC, true); }
  virtual int SBB_D(t_mem code) { return sub8(rD, true); }
  virtual int SBB_E(t_mem code) { return sub8(rE, true); }
  virtual int SBB_H(t_mem code) { return sub8(rH, true); }
  virtual int SBB_L(t_mem code) { return sub8(rL, true); }
  virtual int SBB_M(t_mem code) { return sub8(rM, true); }
  virtual int SBI(t_mem code) { return sub8(fetch(), true); }
  virtual int dad(u16_t op);
  virtual int DAD_B(t_mem code) { return dad(rBC); }
  virtual int DAD_D(t_mem code) { return dad(rDE); }
  virtual int DAD_H(t_mem code) { return dad(rHL); }
  virtual int DAD_S(t_mem code) { return dad(rSP); }
  virtual int inr(class cl_memory_cell &op);
  virtual int INR_A(t_mem code) { return inr(cA); }
  virtual int INR_B(t_mem code) { return inr(cB); }
  virtual int INR_C(t_mem code) { return inr(cC); }
  virtual int INR_D(t_mem code) { return inr(cD); }
  virtual int INR_E(t_mem code) { return inr(cE); }
  virtual int INR_H(t_mem code) { return inr(cH); }
  virtual int INR_L(t_mem code) { return inr(cL); }
  virtual int INR_M(t_mem code) { vc.rd++; return inr(cM()); }
  virtual int dcr(class cl_memory_cell &op);
  virtual int DCR_A(t_mem code) { return dcr(cA); }
  virtual int DCR_B(t_mem code) { return dcr(cB); }
  virtual int DCR_C(t_mem code) { return dcr(cC); }
  virtual int DCR_D(t_mem code) { return dcr(cD); }
  virtual int DCR_E(t_mem code) { return dcr(cE); }
  virtual int DCR_H(t_mem code) { return dcr(cH); }
  virtual int DCR_L(t_mem code) { return dcr(cL); }
  virtual int DCR_M(t_mem code) { vc.rd++; return dcr(cM()); }
};


#endif

/* End of i8085.src/i8080cl.h */
