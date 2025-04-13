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

// 1 d0 - 1 df
#define LD_PSW_n		instruction_1de

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

// 2 60 - 2 6f
#define LD_dst_rrWA             instruction_268
#define LD_dst_rrBC             instruction_269
#define LD_dst_rrDE             instruction_26a
#define LD_dst_rrHL             instruction_26b
#define LD_dst_rrIX             instruction_26c
#define LD_dst_rrIY             instruction_26d
#define LD_dst_rrSP             instruction_26e

// 2 70 - 2 7f
#define LD_dst_rA               instruction_278
#define LD_dst_rW               instruction_279
#define LD_dst_rC               instruction_27a
#define LD_dst_rB               instruction_27b
#define LD_dst_rE               instruction_27c
#define LD_dst_rD               instruction_27d
#define LD_dst_rL               instruction_27e
#define LD_dst_rH               instruction_27f

// 2 f0 - 2 ff
#define LD_dst_n                instruction_2f9
