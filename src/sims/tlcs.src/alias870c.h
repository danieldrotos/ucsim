// 0 00 - 0 0f
#define NOP                     instruction_00
#define CLR_CF 			instruction_04
#define SET_CF 			instruction_05
#define CPL_CF 			instruction_06
#define LDW_mx_mn               instruction_08
#define LDW_mhl_mn              instruction_09
#define LD_mx_n                 instruction_0a
#define LD_mhl_n                instruction_0b
#define LD_A_mx                 instruction_0c
#define LD_A_mhl                instruction_0d
#define LD_mx_A                 instruction_0e
#define LD_mhl_A                instruction_0f

// 0 10 - 0 1f
#define LD_A_rA                 instruction_10
#define LD_A_rW                 instruction_11
#define LD_A_rC                 instruction_12
#define LD_A_rB                 instruction_13
#define LD_A_rE                 instruction_14
#define LD_A_rD                 instruction_15
#define LD_A_rL                 instruction_16
#define LD_A_rH                 instruction_17
#define LD_rA_n                 instruction_18
#define LD_rW_n                 instruction_19
#define LD_rC_n                 instruction_1a
#define LD_rB_n                 instruction_1b
#define LD_rE_n                 instruction_1c
#define LD_rD_n                 instruction_1d
#define LD_rL_n                 instruction_1e
#define LD_rH_n                 instruction_1f

// 0 30 - 0 3f
#define LD_SP_Pd                instruction_37
#define LD_SP_Md                instruction_3f

// 0 40 - 0 4f
#define LD_rA_A                 instruction_40
#define LD_rW_A                 instruction_41
#define LD_rC_A                 instruction_42
#define LD_rB_A                 instruction_43
#define LD_rE_A                 instruction_44
#define LD_rD_A                 instruction_45
#define LD_rL_A                 instruction_46
#define LD_rH_A                 instruction_47
#define LD_rrWA_mn              instruction_48
#define LD_rrBC_mn              instruction_49
#define LD_rrDE_mn              instruction_4a
#define LD_rrHL_mn              instruction_4b
#define LD_rrIX_mn              instruction_4c
#define LD_rrIY_mn              instruction_4d
#define LD_rrSP_mn              instruction_4e

// 0 50 - 0 5f
#define LD_CF_mx_0              instruction_58
#define LD_CF_mx_1              instruction_59
#define LD_CF_mx_2              instruction_5a
#define LD_CF_mx_3              instruction_5b
#define LD_CF_mx_4              instruction_5c
#define LD_CF_mx_5              instruction_5d
#define LD_CF_mx_6              instruction_5e
#define LD_CF_mx_7              instruction_5f

// 0 c0 - 0 cf
#define SET_mx_0                instruction_c0
#define SET_mx_1                instruction_c1
#define SET_mx_2                instruction_c2
#define SET_mx_3                instruction_c3
#define SET_mx_4                instruction_c4
#define SET_mx_5                instruction_c5
#define SET_mx_6                instruction_c6
#define SET_mx_7                instruction_c7
#define CLR_mx_0                instruction_c8
#define CLR_mx_1                instruction_c9
#define CLR_mx_2                instruction_ca
#define CLR_mx_3                instruction_cb
#define CLR_mx_4                instruction_cc
#define CLR_mx_5                instruction_cd
#define CLR_mx_6                instruction_ce
#define CLR_mx_7                instruction_cf

// 0 e0 - 0 ef

// 0 f0 - 0 ff
#define LD_RBS                  instruction_f9

// 1 40 - 1 4f
#define LD_rA_g                 instruction_140
#define LD_rW_g                 instruction_141
#define LD_rC_g                 instruction_142
#define LD_rB_g                 instruction_143
#define LD_rE_g                 instruction_144
#define LD_rD_g                 instruction_145
#define LD_rL_g                 instruction_146
#define LD_rH_g                 instruction_147
#define LD_rrWA_gg              instruction_148
#define LD_rrBC_gg              instruction_149
#define LD_rrDE_gg              instruction_14a
#define LD_rrHL_gg              instruction_14b
#define LD_rrIX_gg              instruction_14c
#define LD_rrIY_gg              instruction_14d
#define LD_rrSP_gg              instruction_14e

// 1 50 - 1 5f
#define LD_CF_g_0               instruction_158
#define LD_CF_g_1               instruction_159
#define LD_CF_g_2               instruction_15a
#define LD_CF_g_3               instruction_15b
#define LD_CF_g_4               instruction_15c
#define LD_CF_g_5               instruction_15d
#define LD_CF_g_6               instruction_15e
#define LD_CF_g_7               instruction_15f

// 1 70 - 1 7f
#define XCH_rA_g                instruction_170
#define XCH_rW_g                instruction_171
#define XCH_rC_g                instruction_172
#define XCH_rB_g                instruction_173
#define XCH_rE_g                instruction_174
#define XCH_rD_g                instruction_175
#define XCH_rL_g                instruction_176
#define XCH_rH_g                instruction_177
#define XCH_rrWA_gg             instruction_178
#define XCH_rrBC_gg             instruction_179
#define XCH_rrDE_gg             instruction_17a
#define XCH_rrHL_gg             instruction_17b
#define XCH_rrIX_gg             instruction_17c
#define XCH_rrIY_gg             instruction_17d
#define XCH_rrSP_gg             instruction_17e

// 1 c0 - 1 cf
#define SET_g_0                 instruction_1c0
#define SET_g_1                 instruction_1c1
#define SET_g_2                 instruction_1c2
#define SET_g_3                 instruction_1c3
#define SET_g_4                 instruction_1c4
#define SET_g_5                 instruction_1c5
#define SET_g_6                 instruction_1c6
#define SET_g_7                 instruction_1c7
#define CLR_g_0                 instruction_1c8
#define CLR_g_1                 instruction_1c9
#define CLR_g_2                 instruction_1ca
#define CLR_g_3                 instruction_1cb
#define CLR_g_4                 instruction_1cc
#define CLR_g_5                 instruction_1cd
#define CLR_g_6                 instruction_1ce
#define CLR_g_7                 instruction_1cf

// 1 d0 - 1 df
#define LD_PSW_n		instruction_1de

// 1 e0 - 1 ef
#define LD_g_0_CF               instruction_1e8
#define LD_g_1_CF               instruction_1e9
#define LD_g_2_CF               instruction_1ea
#define LD_g_3_CF               instruction_1eb
#define LD_g_4_CF               instruction_1ec
#define LD_g_5_CF               instruction_1ed
#define LD_g_6_CF               instruction_1ee
#define LD_g_7_CF               instruction_1ef

// 1 f0 - 1 ff
#define SWAP_g                  instruction_1ff

// 2 40 - 2 4f
#define LD_rA_src               instruction_240
#define LD_rW_src               instruction_241
#define LD_rC_src               instruction_242
#define LD_rB_src               instruction_243
#define LD_rE_src               instruction_244
#define LD_rD_src               instruction_245
#define LD_rL_src               instruction_246
#define LD_rH_src               instruction_247
#define LD_rrWA_src             instruction_248
#define LD_rrBC_src             instruction_249
#define LD_rrDE_src             instruction_24a
#define LD_rrHL_src             instruction_24b
#define LD_rrIX_src             instruction_24c
#define LD_rrIY_src             instruction_24d
#define LD_rrSP_src             instruction_24e

// 2 60 - 2 6f
#define LD_dst_rrWA             instruction_268
#define LD_dst_rrBC             instruction_269
#define LD_dst_rrDE             instruction_26a
#define LD_dst_rrHL             instruction_26b
#define LD_dst_rrIX             instruction_26c
#define LD_dst_rrIY             instruction_26d
#define LD_dst_rrSP             instruction_26e

// 2 70 - 2 7f
#define XCH_rA_src              instruction_270
#define XCH_rW_src              instruction_271
#define XCH_rC_src              instruction_272
#define XCH_rB_src              instruction_273
#define XCH_rE_src              instruction_274
#define XCH_rD_src              instruction_275
#define XCH_rL_src              instruction_276
#define XCH_rH_src              instruction_277
#define LD_dst_rA               instruction_278
#define LD_dst_rW               instruction_279
#define LD_dst_rC               instruction_27a
#define LD_dst_rB               instruction_27b
#define LD_dst_rE               instruction_27c
#define LD_dst_rD               instruction_27d
#define LD_dst_rL               instruction_27e
#define LD_dst_rH               instruction_27f

// 2 c0 - 2 cf
#define SET_src_0               instruction_2c0
#define SET_src_1               instruction_2c1
#define SET_src_2               instruction_2c2
#define SET_src_3               instruction_2c3
#define SET_src_4               instruction_2c4
#define SET_src_5               instruction_2c5
#define SET_src_6               instruction_2c6
#define SET_src_7               instruction_2c7
#define CLR_src_0               instruction_2c8
#define CLR_src_1               instruction_2c9
#define CLR_src_2               instruction_2ca
#define CLR_src_3               instruction_2cb
#define CLR_src_4               instruction_2cc
#define CLR_src_5               instruction_2cd
#define CLR_src_6               instruction_2ce
#define CLR_src_7               instruction_2cf

// 2 d0 - 2 df
#define XCH_rrWA_src            instruction_2d8
#define XCH_rrBC_src            instruction_2d9
#define XCH_rrDE_src            instruction_2da
#define XCH_rrHL3_src           instruction_2db
#define XCH_rrIX_src            instruction_2dc
#define XCH_rrIY_src            instruction_2dd
#define XCH_rrSP_src            instruction_2de
#define XCH_rrHL7_src           instruction_2df

// 2 e0 - 2 ef
#define LD_src_0_CF             instruction_2e8
#define LD_src_1_CF             instruction_2e9
#define LD_src_2_CF             instruction_2ea
#define LD_src_3_CF             instruction_2eb
#define LD_src_4_CF             instruction_2ec
#define LD_src_5_CF             instruction_2ed
#define LD_src_6_CF             instruction_2ee
#define LD_src_7_CF             instruction_2ef

// 2 f0 - 2 ff
#define LD_dst_n                instruction_2f9
