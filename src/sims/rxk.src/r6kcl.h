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
};


#endif

/* End of rxk.src/r6kcl.h */
