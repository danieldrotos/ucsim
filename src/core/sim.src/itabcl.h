/*
 * Simulator of microcontrollers (itabcl.h)
 *
 * Copyright (C) 1999 Daniel
 * 
 * To contact author send email to dr.dkdb@gmail.com
 *
 */

/*
  This file is part of microcontroller simulator: ucsim.

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
  02111-1307, USA.
*/

#ifndef SIM_ITAB_HEADER
#define SIM_ITAB_HEADER

#include "pobjcl.h"
#include "stypes.h"


class cl_itab: public cl_base
{
 public:
  int (cl_itab::*uc_itab[257])(t_mem code);
 public:
  cl_itab(void);
 public:
  virtual int invalid_instruction(t_mem code) { return resINV; }
  virtual int instruction_00(t_mem code) { return resNOT_DONE; }
  virtual int instruction_01(t_mem code) { return resNOT_DONE; }
  virtual int instruction_02(t_mem code) { return resNOT_DONE; }
  virtual int instruction_03(t_mem code) { return resNOT_DONE; }
  virtual int instruction_04(t_mem code) { return resNOT_DONE; }
  virtual int instruction_05(t_mem code) { return resNOT_DONE; }
  virtual int instruction_06(t_mem code) { return resNOT_DONE; }
  virtual int instruction_07(t_mem code) { return resNOT_DONE; }
  virtual int instruction_08(t_mem code) { return resNOT_DONE; }
  virtual int instruction_09(t_mem code) { return resNOT_DONE; }
  virtual int instruction_0a(t_mem code) { return resNOT_DONE; }
  virtual int instruction_0b(t_mem code) { return resNOT_DONE; }
  virtual int instruction_0c(t_mem code) { return resNOT_DONE; }
  virtual int instruction_0d(t_mem code) { return resNOT_DONE; }
  virtual int instruction_0e(t_mem code) { return resNOT_DONE; }
  virtual int instruction_0f(t_mem code) { return resNOT_DONE; }
  virtual int instruction_10(t_mem code) { return resNOT_DONE; }
  virtual int instruction_11(t_mem code) { return resNOT_DONE; }
  virtual int instruction_12(t_mem code) { return resNOT_DONE; }
  virtual int instruction_13(t_mem code) { return resNOT_DONE; }
  virtual int instruction_14(t_mem code) { return resNOT_DONE; }
  virtual int instruction_15(t_mem code) { return resNOT_DONE; }
  virtual int instruction_16(t_mem code) { return resNOT_DONE; }
  virtual int instruction_17(t_mem code) { return resNOT_DONE; }
  virtual int instruction_18(t_mem code) { return resNOT_DONE; }
  virtual int instruction_19(t_mem code) { return resNOT_DONE; }
  virtual int instruction_1a(t_mem code) { return resNOT_DONE; }
  virtual int instruction_1b(t_mem code) { return resNOT_DONE; }
  virtual int instruction_1c(t_mem code) { return resNOT_DONE; }
  virtual int instruction_1d(t_mem code) { return resNOT_DONE; }
  virtual int instruction_1e(t_mem code) { return resNOT_DONE; }
  virtual int instruction_1f(t_mem code) { return resNOT_DONE; }
  virtual int instruction_20(t_mem code) { return resNOT_DONE; }
  virtual int instruction_21(t_mem code) { return resNOT_DONE; }
  virtual int instruction_22(t_mem code) { return resNOT_DONE; }
  virtual int instruction_23(t_mem code) { return resNOT_DONE; }
  virtual int instruction_24(t_mem code) { return resNOT_DONE; }
  virtual int instruction_25(t_mem code) { return resNOT_DONE; }
  virtual int instruction_26(t_mem code) { return resNOT_DONE; }
  virtual int instruction_27(t_mem code) { return resNOT_DONE; }
  virtual int instruction_28(t_mem code) { return resNOT_DONE; }
  virtual int instruction_29(t_mem code) { return resNOT_DONE; }
  virtual int instruction_2a(t_mem code) { return resNOT_DONE; }
  virtual int instruction_2b(t_mem code) { return resNOT_DONE; }
  virtual int instruction_2c(t_mem code) { return resNOT_DONE; }
  virtual int instruction_2d(t_mem code) { return resNOT_DONE; }
  virtual int instruction_2e(t_mem code) { return resNOT_DONE; }
  virtual int instruction_2f(t_mem code) { return resNOT_DONE; }
  virtual int instruction_30(t_mem code) { return resNOT_DONE; }
  virtual int instruction_31(t_mem code) { return resNOT_DONE; }
  virtual int instruction_32(t_mem code) { return resNOT_DONE; }
  virtual int instruction_33(t_mem code) { return resNOT_DONE; }
  virtual int instruction_34(t_mem code) { return resNOT_DONE; }
  virtual int instruction_35(t_mem code) { return resNOT_DONE; }
  virtual int instruction_36(t_mem code) { return resNOT_DONE; }
  virtual int instruction_37(t_mem code) { return resNOT_DONE; }
  virtual int instruction_38(t_mem code) { return resNOT_DONE; }
  virtual int instruction_39(t_mem code) { return resNOT_DONE; }
  virtual int instruction_3a(t_mem code) { return resNOT_DONE; }
  virtual int instruction_3b(t_mem code) { return resNOT_DONE; }
  virtual int instruction_3c(t_mem code) { return resNOT_DONE; }
  virtual int instruction_3d(t_mem code) { return resNOT_DONE; }
  virtual int instruction_3e(t_mem code) { return resNOT_DONE; }
  virtual int instruction_3f(t_mem code) { return resNOT_DONE; }
  virtual int instruction_40(t_mem code) { return resNOT_DONE; }
  virtual int instruction_41(t_mem code) { return resNOT_DONE; }
  virtual int instruction_42(t_mem code) { return resNOT_DONE; }
  virtual int instruction_43(t_mem code) { return resNOT_DONE; }
  virtual int instruction_44(t_mem code) { return resNOT_DONE; }
  virtual int instruction_45(t_mem code) { return resNOT_DONE; }
  virtual int instruction_46(t_mem code) { return resNOT_DONE; }
  virtual int instruction_47(t_mem code) { return resNOT_DONE; }
  virtual int instruction_48(t_mem code) { return resNOT_DONE; }
  virtual int instruction_49(t_mem code) { return resNOT_DONE; }
  virtual int instruction_4a(t_mem code) { return resNOT_DONE; }
  virtual int instruction_4b(t_mem code) { return resNOT_DONE; }
  virtual int instruction_4c(t_mem code) { return resNOT_DONE; }
  virtual int instruction_4d(t_mem code) { return resNOT_DONE; }
  virtual int instruction_4e(t_mem code) { return resNOT_DONE; }
  virtual int instruction_4f(t_mem code) { return resNOT_DONE; }
  virtual int instruction_50(t_mem code) { return resNOT_DONE; }
  virtual int instruction_51(t_mem code) { return resNOT_DONE; }
  virtual int instruction_52(t_mem code) { return resNOT_DONE; }
  virtual int instruction_53(t_mem code) { return resNOT_DONE; }
  virtual int instruction_54(t_mem code) { return resNOT_DONE; }
  virtual int instruction_55(t_mem code) { return resNOT_DONE; }
  virtual int instruction_56(t_mem code) { return resNOT_DONE; }
  virtual int instruction_57(t_mem code) { return resNOT_DONE; }
  virtual int instruction_58(t_mem code) { return resNOT_DONE; }
  virtual int instruction_59(t_mem code) { return resNOT_DONE; }
  virtual int instruction_5a(t_mem code) { return resNOT_DONE; }
  virtual int instruction_5b(t_mem code) { return resNOT_DONE; }
  virtual int instruction_5c(t_mem code) { return resNOT_DONE; }
  virtual int instruction_5d(t_mem code) { return resNOT_DONE; }
  virtual int instruction_5e(t_mem code) { return resNOT_DONE; }
  virtual int instruction_5f(t_mem code) { return resNOT_DONE; }
  virtual int instruction_60(t_mem code) { return resNOT_DONE; }
  virtual int instruction_61(t_mem code) { return resNOT_DONE; }
  virtual int instruction_62(t_mem code) { return resNOT_DONE; }
  virtual int instruction_63(t_mem code) { return resNOT_DONE; }
  virtual int instruction_64(t_mem code) { return resNOT_DONE; }
  virtual int instruction_65(t_mem code) { return resNOT_DONE; }
  virtual int instruction_66(t_mem code) { return resNOT_DONE; }
  virtual int instruction_67(t_mem code) { return resNOT_DONE; }
  virtual int instruction_68(t_mem code) { return resNOT_DONE; }
  virtual int instruction_69(t_mem code) { return resNOT_DONE; }
  virtual int instruction_6a(t_mem code) { return resNOT_DONE; }
  virtual int instruction_6b(t_mem code) { return resNOT_DONE; }
  virtual int instruction_6c(t_mem code) { return resNOT_DONE; }
  virtual int instruction_6d(t_mem code) { return resNOT_DONE; }
  virtual int instruction_6e(t_mem code) { return resNOT_DONE; }
  virtual int instruction_6f(t_mem code) { return resNOT_DONE; }
  virtual int instruction_70(t_mem code) { return resNOT_DONE; }
  virtual int instruction_71(t_mem code) { return resNOT_DONE; }
  virtual int instruction_72(t_mem code) { return resNOT_DONE; }
  virtual int instruction_73(t_mem code) { return resNOT_DONE; }
  virtual int instruction_74(t_mem code) { return resNOT_DONE; }
  virtual int instruction_75(t_mem code) { return resNOT_DONE; }
  virtual int instruction_76(t_mem code) { return resNOT_DONE; }
  virtual int instruction_77(t_mem code) { return resNOT_DONE; }
  virtual int instruction_78(t_mem code) { return resNOT_DONE; }
  virtual int instruction_79(t_mem code) { return resNOT_DONE; }
  virtual int instruction_7a(t_mem code) { return resNOT_DONE; }
  virtual int instruction_7b(t_mem code) { return resNOT_DONE; }
  virtual int instruction_7c(t_mem code) { return resNOT_DONE; }
  virtual int instruction_7d(t_mem code) { return resNOT_DONE; }
  virtual int instruction_7e(t_mem code) { return resNOT_DONE; }
  virtual int instruction_7f(t_mem code) { return resNOT_DONE; }
  virtual int instruction_80(t_mem code) { return resNOT_DONE; }
  virtual int instruction_81(t_mem code) { return resNOT_DONE; }
  virtual int instruction_82(t_mem code) { return resNOT_DONE; }
  virtual int instruction_83(t_mem code) { return resNOT_DONE; }
  virtual int instruction_84(t_mem code) { return resNOT_DONE; }
  virtual int instruction_85(t_mem code) { return resNOT_DONE; }
  virtual int instruction_86(t_mem code) { return resNOT_DONE; }
  virtual int instruction_87(t_mem code) { return resNOT_DONE; }
  virtual int instruction_88(t_mem code) { return resNOT_DONE; }
  virtual int instruction_89(t_mem code) { return resNOT_DONE; }
  virtual int instruction_8a(t_mem code) { return resNOT_DONE; }
  virtual int instruction_8b(t_mem code) { return resNOT_DONE; }
  virtual int instruction_8c(t_mem code) { return resNOT_DONE; }
  virtual int instruction_8d(t_mem code) { return resNOT_DONE; }
  virtual int instruction_8e(t_mem code) { return resNOT_DONE; }
  virtual int instruction_8f(t_mem code) { return resNOT_DONE; }
  virtual int instruction_90(t_mem code) { return resNOT_DONE; }
  virtual int instruction_91(t_mem code) { return resNOT_DONE; }
  virtual int instruction_92(t_mem code) { return resNOT_DONE; }
  virtual int instruction_93(t_mem code) { return resNOT_DONE; }
  virtual int instruction_94(t_mem code) { return resNOT_DONE; }
  virtual int instruction_95(t_mem code) { return resNOT_DONE; }
  virtual int instruction_96(t_mem code) { return resNOT_DONE; }
  virtual int instruction_97(t_mem code) { return resNOT_DONE; }
  virtual int instruction_98(t_mem code) { return resNOT_DONE; }
  virtual int instruction_99(t_mem code) { return resNOT_DONE; }
  virtual int instruction_9a(t_mem code) { return resNOT_DONE; }
  virtual int instruction_9b(t_mem code) { return resNOT_DONE; }
  virtual int instruction_9c(t_mem code) { return resNOT_DONE; }
  virtual int instruction_9d(t_mem code) { return resNOT_DONE; }
  virtual int instruction_9e(t_mem code) { return resNOT_DONE; }
  virtual int instruction_9f(t_mem code) { return resNOT_DONE; }
  virtual int instruction_a0(t_mem code) { return resNOT_DONE; }
  virtual int instruction_a1(t_mem code) { return resNOT_DONE; }
  virtual int instruction_a2(t_mem code) { return resNOT_DONE; }
  virtual int instruction_a3(t_mem code) { return resNOT_DONE; }
  virtual int instruction_a4(t_mem code) { return resNOT_DONE; }
  virtual int instruction_a5(t_mem code) { return resNOT_DONE; }
  virtual int instruction_a6(t_mem code) { return resNOT_DONE; }
  virtual int instruction_a7(t_mem code) { return resNOT_DONE; }
  virtual int instruction_a8(t_mem code) { return resNOT_DONE; }
  virtual int instruction_a9(t_mem code) { return resNOT_DONE; }
  virtual int instruction_aa(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ab(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ac(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ad(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ae(t_mem code) { return resNOT_DONE; }
  virtual int instruction_af(t_mem code) { return resNOT_DONE; }
  virtual int instruction_b0(t_mem code) { return resNOT_DONE; }
  virtual int instruction_b1(t_mem code) { return resNOT_DONE; }
  virtual int instruction_b2(t_mem code) { return resNOT_DONE; }
  virtual int instruction_b3(t_mem code) { return resNOT_DONE; }
  virtual int instruction_b4(t_mem code) { return resNOT_DONE; }
  virtual int instruction_b5(t_mem code) { return resNOT_DONE; }
  virtual int instruction_b6(t_mem code) { return resNOT_DONE; }
  virtual int instruction_b7(t_mem code) { return resNOT_DONE; }
  virtual int instruction_b8(t_mem code) { return resNOT_DONE; }
  virtual int instruction_b9(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ba(t_mem code) { return resNOT_DONE; }
  virtual int instruction_bb(t_mem code) { return resNOT_DONE; }
  virtual int instruction_bc(t_mem code) { return resNOT_DONE; }
  virtual int instruction_bd(t_mem code) { return resNOT_DONE; }
  virtual int instruction_be(t_mem code) { return resNOT_DONE; }
  virtual int instruction_bf(t_mem code) { return resNOT_DONE; }
  virtual int instruction_c0(t_mem code) { return resNOT_DONE; }
  virtual int instruction_c1(t_mem code) { return resNOT_DONE; }
  virtual int instruction_c2(t_mem code) { return resNOT_DONE; }
  virtual int instruction_c3(t_mem code) { return resNOT_DONE; }
  virtual int instruction_c4(t_mem code) { return resNOT_DONE; }
  virtual int instruction_c5(t_mem code) { return resNOT_DONE; }
  virtual int instruction_c6(t_mem code) { return resNOT_DONE; }
  virtual int instruction_c7(t_mem code) { return resNOT_DONE; }
  virtual int instruction_c8(t_mem code) { return resNOT_DONE; }
  virtual int instruction_c9(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ca(t_mem code) { return resNOT_DONE; }
  virtual int instruction_cb(t_mem code) { return resNOT_DONE; }
  virtual int instruction_cc(t_mem code) { return resNOT_DONE; }
  virtual int instruction_cd(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ce(t_mem code) { return resNOT_DONE; }
  virtual int instruction_cf(t_mem code) { return resNOT_DONE; }
  virtual int instruction_d0(t_mem code) { return resNOT_DONE; }
  virtual int instruction_d1(t_mem code) { return resNOT_DONE; }
  virtual int instruction_d2(t_mem code) { return resNOT_DONE; }
  virtual int instruction_d3(t_mem code) { return resNOT_DONE; }
  virtual int instruction_d4(t_mem code) { return resNOT_DONE; }
  virtual int instruction_d5(t_mem code) { return resNOT_DONE; }
  virtual int instruction_d6(t_mem code) { return resNOT_DONE; }
  virtual int instruction_d7(t_mem code) { return resNOT_DONE; }
  virtual int instruction_d8(t_mem code) { return resNOT_DONE; }
  virtual int instruction_d9(t_mem code) { return resNOT_DONE; }
  virtual int instruction_da(t_mem code) { return resNOT_DONE; }
  virtual int instruction_db(t_mem code) { return resNOT_DONE; }
  virtual int instruction_dc(t_mem code) { return resNOT_DONE; }
  virtual int instruction_dd(t_mem code) { return resNOT_DONE; }
  virtual int instruction_de(t_mem code) { return resNOT_DONE; }
  virtual int instruction_df(t_mem code) { return resNOT_DONE; }
  virtual int instruction_e0(t_mem code) { return resNOT_DONE; }
  virtual int instruction_e1(t_mem code) { return resNOT_DONE; }
  virtual int instruction_e2(t_mem code) { return resNOT_DONE; }
  virtual int instruction_e3(t_mem code) { return resNOT_DONE; }
  virtual int instruction_e4(t_mem code) { return resNOT_DONE; }
  virtual int instruction_e5(t_mem code) { return resNOT_DONE; }
  virtual int instruction_e6(t_mem code) { return resNOT_DONE; }
  virtual int instruction_e7(t_mem code) { return resNOT_DONE; }
  virtual int instruction_e8(t_mem code) { return resNOT_DONE; }
  virtual int instruction_e9(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ea(t_mem code) { return resNOT_DONE; }
  virtual int instruction_eb(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ec(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ed(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ee(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ef(t_mem code) { return resNOT_DONE; }
  virtual int instruction_f0(t_mem code) { return resNOT_DONE; }
  virtual int instruction_f1(t_mem code) { return resNOT_DONE; }
  virtual int instruction_f2(t_mem code) { return resNOT_DONE; }
  virtual int instruction_f3(t_mem code) { return resNOT_DONE; }
  virtual int instruction_f4(t_mem code) { return resNOT_DONE; }
  virtual int instruction_f5(t_mem code) { return resNOT_DONE; }
  virtual int instruction_f6(t_mem code) { return resNOT_DONE; }
  virtual int instruction_f7(t_mem code) { return resNOT_DONE; }
  virtual int instruction_f8(t_mem code) { return resNOT_DONE; }
  virtual int instruction_f9(t_mem code) { return resNOT_DONE; }
  virtual int instruction_fa(t_mem code) { return resNOT_DONE; }
  virtual int instruction_fb(t_mem code) { return resNOT_DONE; }
  virtual int instruction_fc(t_mem code) { return resNOT_DONE; }
  virtual int instruction_fd(t_mem code) { return resNOT_DONE; }
  virtual int instruction_fe(t_mem code) { return resNOT_DONE; }
  virtual int instruction_ff(t_mem code) { return resNOT_DONE; }

};


#endif

/* End of sim.src/itabcl.h */
