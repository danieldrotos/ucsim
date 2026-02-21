/*
 * Simulator of microcontrollers (49wrap.cc)
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

#include "rxkcl.h"

#include "49wrap.h"

int instruction_wrapper_49_none(class cl_uc *uc, t_mem code) { return resINV_INST; }

int instruction_wrapper_49_00(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_00(code); }
int instruction_wrapper_49_01(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_01(code); }
int instruction_wrapper_49_02(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_02(code); }
int instruction_wrapper_49_03(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_03(code); }
int instruction_wrapper_49_04(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_04(code); }
int instruction_wrapper_49_05(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_05(code); }
int instruction_wrapper_49_06(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_06(code); }
int instruction_wrapper_49_07(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_07(code); }
int instruction_wrapper_49_08(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_08(code); }
int instruction_wrapper_49_09(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_09(code); }
int instruction_wrapper_49_0a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_0a(code); }
int instruction_wrapper_49_0b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_0b(code); }
int instruction_wrapper_49_0c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_0c(code); }
int instruction_wrapper_49_0d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_0d(code); }
int instruction_wrapper_49_0e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_0e(code); }
int instruction_wrapper_49_0f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_0f(code); }

int instruction_wrapper_49_10(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_10(code); }
int instruction_wrapper_49_11(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_11(code); }
int instruction_wrapper_49_12(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_12(code); }
int instruction_wrapper_49_13(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_13(code); }
int instruction_wrapper_49_14(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_14(code); }
int instruction_wrapper_49_15(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_15(code); }
int instruction_wrapper_49_16(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_16(code); }
int instruction_wrapper_49_17(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_17(code); }
int instruction_wrapper_49_18(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_18(code); }
int instruction_wrapper_49_19(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_19(code); }
int instruction_wrapper_49_1a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_1a(code); }
int instruction_wrapper_49_1b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_1b(code); }
int instruction_wrapper_49_1c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_1c(code); }
int instruction_wrapper_49_1d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_1d(code); }
int instruction_wrapper_49_1e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_1e(code); }
int instruction_wrapper_49_1f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_1f(code); }

int instruction_wrapper_49_20(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_20(code); }
int instruction_wrapper_49_21(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_21(code); }
int instruction_wrapper_49_22(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_22(code); }
int instruction_wrapper_49_23(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_23(code); }
int instruction_wrapper_49_24(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_24(code); }
int instruction_wrapper_49_25(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_25(code); }
int instruction_wrapper_49_26(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_26(code); }
int instruction_wrapper_49_27(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_27(code); }
int instruction_wrapper_49_28(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_28(code); }
int instruction_wrapper_49_29(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_29(code); }
int instruction_wrapper_49_2a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_2a(code); }
int instruction_wrapper_49_2b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_2b(code); }
int instruction_wrapper_49_2c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_2c(code); }
int instruction_wrapper_49_2d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_2d(code); }
int instruction_wrapper_49_2e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_2e(code); }
int instruction_wrapper_49_2f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_2f(code); }

int instruction_wrapper_49_30(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_30(code); }
int instruction_wrapper_49_31(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_31(code); }
int instruction_wrapper_49_32(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_32(code); }
int instruction_wrapper_49_33(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_33(code); }
int instruction_wrapper_49_34(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_34(code); }
int instruction_wrapper_49_35(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_35(code); }
int instruction_wrapper_49_36(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_36(code); }
int instruction_wrapper_49_37(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_37(code); }
int instruction_wrapper_49_38(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_38(code); }
int instruction_wrapper_49_39(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_39(code); }
int instruction_wrapper_49_3a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_3a(code); }
int instruction_wrapper_49_3b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_3b(code); }
int instruction_wrapper_49_3c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_3c(code); }
int instruction_wrapper_49_3d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_3d(code); }
int instruction_wrapper_49_3e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_3e(code); }
int instruction_wrapper_49_3f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_3f(code); }

int instruction_wrapper_49_40(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_40(code); }
int instruction_wrapper_49_41(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_41(code); }
int instruction_wrapper_49_42(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_42(code); }
int instruction_wrapper_49_43(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_43(code); }
int instruction_wrapper_49_44(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_44(code); }
int instruction_wrapper_49_45(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_45(code); }
int instruction_wrapper_49_46(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_46(code); }
int instruction_wrapper_49_47(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_47(code); }
int instruction_wrapper_49_48(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_48(code); }
int instruction_wrapper_49_49(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_49(code); }
int instruction_wrapper_49_4a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_4a(code); }
int instruction_wrapper_49_4b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_4b(code); }
int instruction_wrapper_49_4c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_4c(code); }
int instruction_wrapper_49_4d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_4d(code); }
int instruction_wrapper_49_4e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_4e(code); }
int instruction_wrapper_49_4f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_4f(code); }

int instruction_wrapper_49_50(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_50(code); }
int instruction_wrapper_49_51(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_51(code); }
int instruction_wrapper_49_52(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_52(code); }
int instruction_wrapper_49_53(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_53(code); }
int instruction_wrapper_49_54(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_54(code); }
int instruction_wrapper_49_55(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_55(code); }
int instruction_wrapper_49_56(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_56(code); }
int instruction_wrapper_49_57(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_57(code); }
int instruction_wrapper_49_58(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_58(code); }
int instruction_wrapper_49_59(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_59(code); }
int instruction_wrapper_49_5a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_5a(code); }
int instruction_wrapper_49_5b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_5b(code); }
int instruction_wrapper_49_5c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_5c(code); }
int instruction_wrapper_49_5d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_5d(code); }
int instruction_wrapper_49_5e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_5e(code); }
int instruction_wrapper_49_5f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_5f(code); }

int instruction_wrapper_49_60(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_60(code); }
int instruction_wrapper_49_61(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_61(code); }
int instruction_wrapper_49_62(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_62(code); }
int instruction_wrapper_49_63(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_63(code); }
int instruction_wrapper_49_64(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_64(code); }
int instruction_wrapper_49_65(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_65(code); }
int instruction_wrapper_49_66(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_66(code); }
int instruction_wrapper_49_67(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_67(code); }
int instruction_wrapper_49_68(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_68(code); }
int instruction_wrapper_49_69(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_69(code); }
int instruction_wrapper_49_6a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_6a(code); }
int instruction_wrapper_49_6b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_6b(code); }
int instruction_wrapper_49_6c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_6c(code); }
int instruction_wrapper_49_6d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_6d(code); }
int instruction_wrapper_49_6e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_6e(code); }
int instruction_wrapper_49_6f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_6f(code); }

int instruction_wrapper_49_70(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_70(code); }
int instruction_wrapper_49_71(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_71(code); }
int instruction_wrapper_49_72(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_72(code); }
int instruction_wrapper_49_73(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_73(code); }
int instruction_wrapper_49_74(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_74(code); }
int instruction_wrapper_49_75(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_75(code); }
int instruction_wrapper_49_76(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_76(code); }
int instruction_wrapper_49_77(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_77(code); }
int instruction_wrapper_49_78(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_78(code); }
int instruction_wrapper_49_79(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_79(code); }
int instruction_wrapper_49_7a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_7a(code); }
int instruction_wrapper_49_7b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_7b(code); }
int instruction_wrapper_49_7c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_7c(code); }
int instruction_wrapper_49_7d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_7d(code); }
int instruction_wrapper_49_7e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_7e(code); }
int instruction_wrapper_49_7f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_7f(code); }

int instruction_wrapper_49_89(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_89(code); }
int instruction_wrapper_49_8a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_8a(code); }
int instruction_wrapper_49_8b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_8b(code); }
int instruction_wrapper_49_8c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_8c(code); }
int instruction_wrapper_49_8d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_8d(code); }
int instruction_wrapper_49_8e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_8e(code); }
int instruction_wrapper_49_8f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_8f(code); }

int instruction_wrapper_49_90(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_90(code); }
int instruction_wrapper_49_98(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_98(code); }
int instruction_wrapper_49_99(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_99(code); }
int instruction_wrapper_49_9a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_9a(code); }
int instruction_wrapper_49_9b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_9b(code); }
int instruction_wrapper_49_9c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_9c(code); }
int instruction_wrapper_49_9d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_9d(code); }
int instruction_wrapper_49_9e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_9e(code); }
int instruction_wrapper_49_9f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_9f(code); }

int instruction_wrapper_49_a0(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_a0(code); }
int instruction_wrapper_49_a2(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_a2(code); }
int instruction_wrapper_49_a3(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_a3(code); }
int instruction_wrapper_49_a4(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_a4(code); }
int instruction_wrapper_49_a5(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_a5(code); }
int instruction_wrapper_49_a6(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_a6(code); }
int instruction_wrapper_49_a7(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_a7(code); }
int instruction_wrapper_49_a8(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_a8(code); }
int instruction_wrapper_49_a9(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_a9(code); }
int instruction_wrapper_49_aa(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_aa(code); }
int instruction_wrapper_49_ab(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ab(code); }
int instruction_wrapper_49_ac(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ac(code); }
int instruction_wrapper_49_ad(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ad(code); }
int instruction_wrapper_49_ae(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ae(code); }
int instruction_wrapper_49_af(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_af(code); }

int instruction_wrapper_49_b0(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_b0(code); }
int instruction_wrapper_49_b2(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_b2(code); }
int instruction_wrapper_49_b3(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_b3(code); }
int instruction_wrapper_49_b4(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_b4(code); }
int instruction_wrapper_49_b5(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_b5(code); }
int instruction_wrapper_49_b6(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_b6(code); }
int instruction_wrapper_49_b7(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_b7(code); }
int instruction_wrapper_49_b8(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_b8(code); }
int instruction_wrapper_49_b9(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_b9(code); }
int instruction_wrapper_49_ba(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ba(code); }
int instruction_wrapper_49_bb(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_bb(code); }
int instruction_wrapper_49_bc(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_bc(code); }
int instruction_wrapper_49_bd(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_bd(code); }
int instruction_wrapper_49_be(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_be(code); }
int instruction_wrapper_49_bf(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_bf(code); }

int instruction_wrapper_49_c0(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_c0(code); }
int instruction_wrapper_49_c2(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_c2(code); }
int instruction_wrapper_49_c3(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_c3(code); }
int instruction_wrapper_49_c8(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_c8(code); }
int instruction_wrapper_49_c9(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_c9(code); }
int instruction_wrapper_49_ca(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ca(code); }
int instruction_wrapper_49_cb(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_cb(code); }
int instruction_wrapper_49_cc(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_cc(code); }
int instruction_wrapper_49_cd(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_cd(code); }
int instruction_wrapper_49_ce(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ce(code); }
int instruction_wrapper_49_cf(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_cf(code); }

int instruction_wrapper_49_d0(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_d0(code); }
int instruction_wrapper_49_d2(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_d2(code); }
int instruction_wrapper_49_d3(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_d3(code); }
int instruction_wrapper_49_d8(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_d8(code); }
int instruction_wrapper_49_d9(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_d9(code); }
int instruction_wrapper_49_da(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_da(code); }
int instruction_wrapper_49_db(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_db(code); }
int instruction_wrapper_49_dc(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dc(code); }
int instruction_wrapper_49_dd(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd(code); }
int instruction_wrapper_49_de(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_de(code); }
int instruction_wrapper_49_df(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_df(code); }

int instruction_wrapper_49_e2(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_e2(code); }
int instruction_wrapper_49_e3(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_e3(code); }
int instruction_wrapper_49_e9(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_e9(code); }
int instruction_wrapper_49_ea(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ea(code); }
int instruction_wrapper_49_eb(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_eb(code); }
int instruction_wrapper_49_ec(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ec(code); }
int instruction_wrapper_49_ed(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ed(code); }
int instruction_wrapper_49_ee(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ee(code); }
int instruction_wrapper_49_ef(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ef(code); }

int instruction_wrapper_49_f0(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_f0(code); }
int instruction_wrapper_49_f8(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_f8(code); }
int instruction_wrapper_49_f9(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_f9(code); }
int instruction_wrapper_49_fa(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_fa(code); }
int instruction_wrapper_49_fb(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_fb(code); }
int instruction_wrapper_49_fc(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_fc(code); }
int instruction_wrapper_49_fd(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_fd(code); }
int instruction_wrapper_49_fe(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_fe(code); }
int instruction_wrapper_49_ff(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_ff(code); }


void fill_49_wrappers(instruction_wrapper_fn itab[])
{
  int i;
  for (i=0; i<256; i++)
    {
      itab[i]= instruction_wrapper_49_none;
    }
  itab[0x00]= instruction_wrapper_49_00;
  itab[0x01]= instruction_wrapper_49_01;
  itab[0x02]= instruction_wrapper_49_02;
  itab[0x03]= instruction_wrapper_49_03;
  itab[0x04]= instruction_wrapper_49_04;
  itab[0x05]= instruction_wrapper_49_05;
  itab[0x06]= instruction_wrapper_49_06;
  itab[0x07]= instruction_wrapper_49_07;
  itab[0x08]= instruction_wrapper_49_08;
  itab[0x09]= instruction_wrapper_49_09;
  itab[0x0a]= instruction_wrapper_49_0a;
  itab[0x0b]= instruction_wrapper_49_0b;
  itab[0x0c]= instruction_wrapper_49_0c;
  itab[0x0d]= instruction_wrapper_49_0d;
  itab[0x0e]= instruction_wrapper_49_0e;
  itab[0x0f]= instruction_wrapper_49_0f;
  itab[0x10]= instruction_wrapper_49_10;
  itab[0x11]= instruction_wrapper_49_11;
  itab[0x12]= instruction_wrapper_49_12;
  itab[0x13]= instruction_wrapper_49_13;
  itab[0x14]= instruction_wrapper_49_14;
  itab[0x15]= instruction_wrapper_49_15;
  itab[0x16]= instruction_wrapper_49_16;
  itab[0x17]= instruction_wrapper_49_17;
  itab[0x18]= instruction_wrapper_49_18;
  itab[0x19]= instruction_wrapper_49_19;
  itab[0x1a]= instruction_wrapper_49_1a;
  itab[0x1b]= instruction_wrapper_49_1b;
  itab[0x1c]= instruction_wrapper_49_1c;
  itab[0x1d]= instruction_wrapper_49_1d;
  itab[0x1e]= instruction_wrapper_49_1e;
  itab[0x1f]= instruction_wrapper_49_1f;
  itab[0x20]= instruction_wrapper_49_20;
  itab[0x21]= instruction_wrapper_49_21;
  itab[0x22]= instruction_wrapper_49_22;
  itab[0x23]= instruction_wrapper_49_23;
  itab[0x24]= instruction_wrapper_49_24;
  itab[0x25]= instruction_wrapper_49_25;
  itab[0x26]= instruction_wrapper_49_26;
  itab[0x27]= instruction_wrapper_49_27;
  itab[0x28]= instruction_wrapper_49_28;
  itab[0x29]= instruction_wrapper_49_29;
  itab[0x2a]= instruction_wrapper_49_2a;
  itab[0x2b]= instruction_wrapper_49_2b;
  itab[0x2c]= instruction_wrapper_49_2c;
  itab[0x2d]= instruction_wrapper_49_2d;
  itab[0x2e]= instruction_wrapper_49_2e;
  itab[0x2f]= instruction_wrapper_49_2f;
  itab[0x30]= instruction_wrapper_49_30;
  itab[0x31]= instruction_wrapper_49_31;
  itab[0x32]= instruction_wrapper_49_32;
  itab[0x33]= instruction_wrapper_49_33;
  itab[0x34]= instruction_wrapper_49_34;
  itab[0x35]= instruction_wrapper_49_35;
  itab[0x36]= instruction_wrapper_49_36;
  itab[0x37]= instruction_wrapper_49_37;
  itab[0x38]= instruction_wrapper_49_38;
  itab[0x39]= instruction_wrapper_49_39;
  itab[0x3a]= instruction_wrapper_49_3a;
  itab[0x3b]= instruction_wrapper_49_3b;
  itab[0x3c]= instruction_wrapper_49_3c;
  itab[0x3d]= instruction_wrapper_49_3d;
  itab[0x3e]= instruction_wrapper_49_3e;
  itab[0x3f]= instruction_wrapper_49_3f;
  itab[0x40]= instruction_wrapper_49_40;
  itab[0x41]= instruction_wrapper_49_41;
  itab[0x42]= instruction_wrapper_49_42;
  itab[0x43]= instruction_wrapper_49_43;
  itab[0x44]= instruction_wrapper_49_44;
  itab[0x45]= instruction_wrapper_49_45;
  itab[0x46]= instruction_wrapper_49_46;
  itab[0x47]= instruction_wrapper_49_47;
  itab[0x48]= instruction_wrapper_49_48;
  itab[0x49]= instruction_wrapper_49_49;
  itab[0x4a]= instruction_wrapper_49_4a;
  itab[0x4b]= instruction_wrapper_49_4b;
  itab[0x4c]= instruction_wrapper_49_4c;
  itab[0x4d]= instruction_wrapper_49_4d;
  itab[0x4e]= instruction_wrapper_49_4e;
  itab[0x4f]= instruction_wrapper_49_4f;
  itab[0x50]= instruction_wrapper_49_50;
  itab[0x51]= instruction_wrapper_49_51;
  itab[0x52]= instruction_wrapper_49_52;
  itab[0x53]= instruction_wrapper_49_53;
  itab[0x54]= instruction_wrapper_49_54;
  itab[0x55]= instruction_wrapper_49_55;
  itab[0x56]= instruction_wrapper_49_56;
  itab[0x57]= instruction_wrapper_49_57;
  itab[0x58]= instruction_wrapper_49_58;
  itab[0x59]= instruction_wrapper_49_59;
  itab[0x5a]= instruction_wrapper_49_5a;
  itab[0x5b]= instruction_wrapper_49_5b;
  itab[0x5c]= instruction_wrapper_49_5c;
  itab[0x5d]= instruction_wrapper_49_5d;
  itab[0x5e]= instruction_wrapper_49_5e;
  itab[0x5f]= instruction_wrapper_49_5f;
  itab[0x60]= instruction_wrapper_49_60;
  itab[0x61]= instruction_wrapper_49_61;
  itab[0x62]= instruction_wrapper_49_62;
  itab[0x63]= instruction_wrapper_49_63;
  itab[0x64]= instruction_wrapper_49_64;
  itab[0x65]= instruction_wrapper_49_65;
  itab[0x66]= instruction_wrapper_49_66;
  itab[0x67]= instruction_wrapper_49_67;
  itab[0x68]= instruction_wrapper_49_68;
  itab[0x69]= instruction_wrapper_49_69;
  itab[0x6a]= instruction_wrapper_49_6a;
  itab[0x6b]= instruction_wrapper_49_6b;
  itab[0x6c]= instruction_wrapper_49_6c;
  itab[0x6d]= instruction_wrapper_49_6d;
  itab[0x6e]= instruction_wrapper_49_6e;
  itab[0x6f]= instruction_wrapper_49_6f;
  itab[0x70]= instruction_wrapper_49_70;
  itab[0x71]= instruction_wrapper_49_71;
  itab[0x72]= instruction_wrapper_49_72;
  itab[0x73]= instruction_wrapper_49_73;
  itab[0x74]= instruction_wrapper_49_74;
  itab[0x75]= instruction_wrapper_49_75;
  itab[0x76]= instruction_wrapper_49_76;
  itab[0x77]= instruction_wrapper_49_77;
  itab[0x78]= instruction_wrapper_49_78;
  itab[0x79]= instruction_wrapper_49_79;
  itab[0x7a]= instruction_wrapper_49_7a;
  itab[0x7b]= instruction_wrapper_49_7b;
  itab[0x7c]= instruction_wrapper_49_7c;
  itab[0x7d]= instruction_wrapper_49_7d;
  itab[0x7e]= instruction_wrapper_49_7e;
  itab[0x7f]= instruction_wrapper_49_7f;
  itab[0x89]= instruction_wrapper_49_89;
  itab[0x8a]= instruction_wrapper_49_8a;
  itab[0x8b]= instruction_wrapper_49_8b;
  itab[0x8c]= instruction_wrapper_49_8c;
  itab[0x8d]= instruction_wrapper_49_8d;
  itab[0x8e]= instruction_wrapper_49_8e;
  itab[0x8f]= instruction_wrapper_49_8f;
  itab[0x90]= instruction_wrapper_49_90;
  itab[0x98]= instruction_wrapper_49_98;
  itab[0x99]= instruction_wrapper_49_99;
  itab[0x9a]= instruction_wrapper_49_9a;
  itab[0x9b]= instruction_wrapper_49_9b;
  itab[0x9c]= instruction_wrapper_49_9c;
  itab[0x9d]= instruction_wrapper_49_9d;
  itab[0x9e]= instruction_wrapper_49_9e;
  itab[0x9f]= instruction_wrapper_49_9f;
  itab[0xa0]= instruction_wrapper_49_a0;
  itab[0xa2]= instruction_wrapper_49_a2;
  itab[0xa3]= instruction_wrapper_49_a3;
  itab[0xa4]= instruction_wrapper_49_a4;
  itab[0xa5]= instruction_wrapper_49_a5;
  itab[0xa6]= instruction_wrapper_49_a6;
  itab[0xa7]= instruction_wrapper_49_a7;
  itab[0xa8]= instruction_wrapper_49_a8;
  itab[0xa9]= instruction_wrapper_49_a9;
  itab[0xaa]= instruction_wrapper_49_aa;
  itab[0xab]= instruction_wrapper_49_ab;
  itab[0xac]= instruction_wrapper_49_ac;
  itab[0xad]= instruction_wrapper_49_ad;
  itab[0xae]= instruction_wrapper_49_ae;
  itab[0xaf]= instruction_wrapper_49_af;
  itab[0xb0]= instruction_wrapper_49_b0;
  itab[0xb2]= instruction_wrapper_49_b2;
  itab[0xb3]= instruction_wrapper_49_b3;
  itab[0xb4]= instruction_wrapper_49_b4;
  itab[0xb5]= instruction_wrapper_49_b5;
  itab[0xb6]= instruction_wrapper_49_b6;
  itab[0xb7]= instruction_wrapper_49_b7;
  itab[0xb8]= instruction_wrapper_49_b8;
  itab[0xb9]= instruction_wrapper_49_b9;
  itab[0xba]= instruction_wrapper_49_ba;
  itab[0xbb]= instruction_wrapper_49_bb;
  itab[0xbc]= instruction_wrapper_49_bc;
  itab[0xbd]= instruction_wrapper_49_bd;
  itab[0xbe]= instruction_wrapper_49_be;
  itab[0xbf]= instruction_wrapper_49_bf;
  itab[0xc0]= instruction_wrapper_49_c0;
  itab[0xc2]= instruction_wrapper_49_c2;
  itab[0xc3]= instruction_wrapper_49_c3;
  itab[0xc8]= instruction_wrapper_49_c8;
  itab[0xc9]= instruction_wrapper_49_c9;
  itab[0xca]= instruction_wrapper_49_ca;
  itab[0xcb]= instruction_wrapper_49_cb;
  itab[0xcc]= instruction_wrapper_49_cc;
  itab[0xcd]= instruction_wrapper_49_cd;
  itab[0xce]= instruction_wrapper_49_ce;
  itab[0xcf]= instruction_wrapper_49_cf;
  itab[0xd0]= instruction_wrapper_49_d0;
  itab[0xd2]= instruction_wrapper_49_d2;
  itab[0xd3]= instruction_wrapper_49_d3;
  itab[0xd8]= instruction_wrapper_49_d8;
  itab[0xd9]= instruction_wrapper_49_d9;
  itab[0xda]= instruction_wrapper_49_da;
  itab[0xdb]= instruction_wrapper_49_db;
  itab[0xdc]= instruction_wrapper_49_dc;
  itab[0xdd]= instruction_wrapper_49_dd;
  itab[0xde]= instruction_wrapper_49_de;
  itab[0xdf]= instruction_wrapper_49_df;
  itab[0xe2]= instruction_wrapper_49_e2;
  itab[0xe3]= instruction_wrapper_49_e3;
  itab[0xe9]= instruction_wrapper_49_e9;
  itab[0xea]= instruction_wrapper_49_ea;
  itab[0xeb]= instruction_wrapper_49_eb;
  itab[0xec]= instruction_wrapper_49_ec;
  itab[0xed]= instruction_wrapper_49_ed;
  itab[0xee]= instruction_wrapper_49_ee;
  itab[0xef]= instruction_wrapper_49_ef;
  itab[0xf0]= instruction_wrapper_49_f0;
  itab[0xf8]= instruction_wrapper_49_f8;
  itab[0xf9]= instruction_wrapper_49_f9;
  itab[0xfa]= instruction_wrapper_49_fa;
  itab[0xfb]= instruction_wrapper_49_fb;
  itab[0xfc]= instruction_wrapper_49_fc;
  itab[0xfd]= instruction_wrapper_49_fd;
  itab[0xfe]= instruction_wrapper_49_fe;
  itab[0xff]= instruction_wrapper_49_ff;
}

/* End of rxk.src/49wrap.cc */
