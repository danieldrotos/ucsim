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

// 0 20 - 0 2f
#define INC_rA                  instruction_20
#define INC_rW                  instruction_21
#define INC_rC                  instruction_22
#define INC_rB                  instruction_23
#define INC_rE                  instruction_24
#define INC_rD                  instruction_25
#define INC_rL                  instruction_26
#define INC_rH                  instruction_27
#define DEC_rA                  instruction_28
#define DEC_rW                  instruction_29
#define DEC_rC                  instruction_2a
#define DEC_rB                  instruction_2b
#define DEC_rE                  instruction_2c
#define DEC_rD                  instruction_2d
#define DEC_rL                  instruction_2e
#define DEC_rH                  instruction_2f

// 0 30 - 0 3f
#define INC_rrWA                instruction_30
#define INC_rrBC                instruction_31
#define INC_rrDE                instruction_32
#define INC_rrHL                instruction_33
#define INC_rrIX                instruction_34
#define INC_rrIY                instruction_35
#define INC_rrSP                instruction_36
#define LD_SP_Pd                instruction_37
#define DEC_rrWA                instruction_38
#define DEC_rrBC                instruction_39
#define DEC_rrDE                instruction_3a
#define DEC_rrHL                instruction_3b
#define DEC_rrIX                instruction_3c
#define DEC_rrIY                instruction_3d
#define DEC_rrSP                instruction_3e
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

// 0 60 - 0 6f
#define ADC_A_n                 instruction_60
#define ADD_A_n                 instruction_61
#define SUBB_A_n		instruction_62
#define SUB_A_n			instruction_63
#define AND_A_n                 instruction_64
#define XOR_A_n                 instruction_65
#define OR_A_n                  instruction_66
#define CMP_A_n                 instruction_67

// 0 80 - 0 8f
#define JRS_T_a00               instruction_80
#define JRS_T_a01               instruction_81
#define JRS_T_a02               instruction_82
#define JRS_T_a03               instruction_83
#define JRS_T_a04               instruction_84
#define JRS_T_a05               instruction_85
#define JRS_T_a06               instruction_86
#define JRS_T_a07               instruction_87
#define JRS_T_a08               instruction_88
#define JRS_T_a09               instruction_89
#define JRS_T_a0a               instruction_8a
#define JRS_T_a0b               instruction_8b
#define JRS_T_a0c               instruction_8c
#define JRS_T_a0d               instruction_8d
#define JRS_T_a0e               instruction_8e
#define JRS_T_a0f               instruction_8f

// 0 90 - 0 9f
#define JRS_T_a10               instruction_90
#define JRS_T_a11               instruction_91
#define JRS_T_a12               instruction_92
#define JRS_T_a13               instruction_93
#define JRS_T_a14               instruction_94
#define JRS_T_a15               instruction_95
#define JRS_T_a16               instruction_96
#define JRS_T_a17               instruction_97
#define JRS_T_a18               instruction_98
#define JRS_T_a19               instruction_99
#define JRS_T_a1a               instruction_9a
#define JRS_T_a1b               instruction_9b
#define JRS_T_a1c               instruction_9c
#define JRS_T_a1d               instruction_9d
#define JRS_T_a1e               instruction_9e
#define JRS_T_a1f               instruction_9f

// 0 a0 - 0 af
#define JRS_F_a00               instruction_a0
#define JRS_F_a01               instruction_a1
#define JRS_F_a02               instruction_a2
#define JRS_F_a03               instruction_a3
#define JRS_F_a04               instruction_a4
#define JRS_F_a05               instruction_a5
#define JRS_F_a06               instruction_a6
#define JRS_F_a07               instruction_a7
#define JRS_F_a08               instruction_a8
#define JRS_F_a09               instruction_a9
#define JRS_F_a0a               instruction_aa
#define JRS_F_a0b               instruction_ab
#define JRS_F_a0c               instruction_ac
#define JRS_F_a0d               instruction_ad
#define JRS_F_a0e               instruction_ae
#define JRS_F_a0f               instruction_af

// 0 b0 - 0 bf
#define JRS_F_a10               instruction_b0
#define JRS_F_a11               instruction_b1
#define JRS_F_a12               instruction_b2
#define JRS_F_a13               instruction_b3
#define JRS_F_a14               instruction_b4
#define JRS_F_a15               instruction_b5
#define JRS_F_a16               instruction_b6
#define JRS_F_a17               instruction_b7
#define JRS_F_a18               instruction_b8
#define JRS_F_a19               instruction_b9
#define JRS_F_a1a               instruction_ba
#define JRS_F_a1b               instruction_bb
#define JRS_F_a1c               instruction_bc
#define JRS_F_a1d               instruction_bd
#define JRS_F_a1e               instruction_be
#define JRS_F_a1f               instruction_bf

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
#define JR_a                    instruction_fc
#define JP_mn                   instruction_fe

// 1 00 - 1 3f ALU r,g
#define ADDC_rA_g	        instruction_100
#define ADDC_rW_g	        instruction_108
#define ADDC_rC_g	        instruction_110
#define ADDC_rB_g	        instruction_118
#define ADDC_rE_g	        instruction_120
#define ADDC_rD_g	        instruction_128
#define ADDC_rL_g	        instruction_130
#define ADDC_rH_g	        instruction_138

#define ADD_rA_g	        instruction_101
#define ADD_rW_g	        instruction_109
#define ADD_rC_g	        instruction_111
#define ADD_rB_g	        instruction_119
#define ADD_rE_g	        instruction_121
#define ADD_rD_g	        instruction_129
#define ADD_rL_g	        instruction_131
#define ADD_rH_g	        instruction_139

#define SUBB_rA_g		instruction_102
#define SUBB_rW_g		instruction_10a
#define SUBB_rC_g		instruction_112
#define SUBB_rB_g		instruction_11a
#define SUBB_rE_g		instruction_122
#define SUBB_rD_g		instruction_12a
#define SUBB_rL_g		instruction_132
#define SUBB_rH_g		instruction_13a

#define SUB_rA_g		instruction_103
#define SUB_rW_g		instruction_10b
#define SUB_rC_g		instruction_113
#define SUB_rB_g		instruction_11b
#define SUB_rE_g		instruction_123
#define SUB_rD_g		instruction_12b
#define SUB_rL_g		instruction_133
#define SUB_rH_g		instruction_13b

#define AND_rA_g		instruction_104
#define AND_rW_g		instruction_10c
#define AND_rC_g		instruction_114
#define AND_rB_g		instruction_11c
#define AND_rE_g		instruction_124
#define AND_rD_g		instruction_12c
#define AND_rL_g		instruction_134
#define AND_rH_g		instruction_13c

#define XOR_rA_g		instruction_105
#define XOR_rW_g		instruction_10d
#define XOR_rC_g		instruction_115
#define XOR_rB_g		instruction_11d
#define XOR_rE_g		instruction_125
#define XOR_rD_g		instruction_12d
#define XOR_rL_g		instruction_135
#define XOR_rH_g		instruction_13d

#define OR_rA_g			instruction_106
#define OR_rW_g			instruction_10e
#define OR_rC_g			instruction_116
#define OR_rB_g			instruction_11e
#define OR_rE_g			instruction_126
#define OR_rD_g			instruction_12e
#define OR_rL_g			instruction_136
#define OR_rH_g			instruction_13e

#define CMP_rA_g		instruction_107
#define CMP_rW_g		instruction_10f
#define CMP_rC_g		instruction_117
#define CMP_rB_g		instruction_11f
#define CMP_rE_g		instruction_127
#define CMP_rD_g		instruction_12f
#define CMP_rL_g		instruction_137
#define CMP_rH_g		instruction_13f

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
#define XOR_CF_g_0              instruction_150
#define XOR_CF_g_1              instruction_151
#define XOR_CF_g_2              instruction_152
#define XOR_CF_g_3              instruction_153
#define XOR_CF_g_4              instruction_154
#define XOR_CF_g_5              instruction_155
#define XOR_CF_g_6              instruction_156
#define XOR_CF_g_7              instruction_157
#define LD_CF_g_0               instruction_158
#define LD_CF_g_1               instruction_159
#define LD_CF_g_2               instruction_15a
#define LD_CF_g_3               instruction_15b
#define LD_CF_g_4               instruction_15c
#define LD_CF_g_5               instruction_15d
#define LD_CF_g_6               instruction_15e
#define LD_CF_g_7               instruction_15f

// 1 60 - 1 6f
#define ADDC_g_n                instruction_160
#define ADD_g_n                 instruction_161
#define SUBB_g_n                instruction_162
#define SUB_g_n                 instruction_163
#define AND_g_n                 instruction_164
#define XOR_g_n                 instruction_165
#define OR_g_n                  instruction_166
#define CMP_g_n                 instruction_167

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

// 1 80 - 1 bf ALU rr,gg
#define ADDC_rrWA_gg		instruction_180
#define ADDC_rrBC_gg		instruction_188
#define ADDC_rrDE_gg		instruction_190
#define ADDC_rrHL9_gg		instruction_198
#define ADDC_rrIX_gg		instruction_1a0
#define ADDC_rrIY_gg		instruction_1a8
#define ADDC_rrSP_gg		instruction_1b0
#define ADDC_rrHLb_gg		instruction_1b8

#define ADD_rrWA_gg		instruction_181
#define ADD_rrBC_gg		instruction_189
#define ADD_rrDE_gg		instruction_191
#define ADD_rrHL9_gg		instruction_199
#define ADD_rrIX_gg		instruction_1a1
#define ADD_rrIY_gg		instruction_1a9
#define ADD_rrSP_gg		instruction_1b1
#define ADD_rrHLb_gg		instruction_1b9

#define SUBB_rrWA_gg		instruction_182
#define SUBB_rrBC_gg		instruction_18a
#define SUBB_rrDE_gg		instruction_192
#define SUBB_rrHL9_gg		instruction_19a
#define SUBB_rrIX_gg		instruction_1a2
#define SUBB_rrIY_gg		instruction_1aa
#define SUBB_rrSP_gg		instruction_1b2
#define SUBB_rrHLb_gg		instruction_1ba

#define SUB_rrWA_gg		instruction_183
#define SUB_rrBC_gg		instruction_18b
#define SUB_rrDE_gg		instruction_193
#define SUB_rrHL9_gg		instruction_19b
#define SUB_rrIX_gg		instruction_1a3
#define SUB_rrIY_gg		instruction_1ab
#define SUB_rrSP_gg		instruction_1b3
#define SUB_rrHLb_gg		instruction_1bb

#define AND_rrWA_gg		instruction_184
#define AND_rrBC_gg		instruction_18c
#define AND_rrDE_gg		instruction_194
#define AND_rrHL9_gg		instruction_19c
#define AND_rrIX_gg		instruction_1a4
#define AND_rrIY_gg		instruction_1ac
#define AND_rrSP_gg		instruction_1b4
#define AND_rrHLb_gg		instruction_1bc

#define XOR_rrWA_gg		instruction_185
#define XOR_rrBC_gg		instruction_18d
#define XOR_rrDE_gg		instruction_195
#define XOR_rrHL9_gg		instruction_19d
#define XOR_rrIX_gg		instruction_1a5
#define XOR_rrIY_gg		instruction_1ad
#define XOR_rrSP_gg		instruction_1b5
#define XOR_rrHLb_gg		instruction_1bd

#define OR_rrWA_gg		instruction_186
#define OR_rrBC_gg		instruction_18e
#define OR_rrDE_gg		instruction_196
#define OR_rrHL9_gg		instruction_19e
#define OR_rrIX_gg		instruction_1a6
#define OR_rrIY_gg		instruction_1ae
#define OR_rrSP_gg		instruction_1b6
#define OR_rrHLb_gg		instruction_1be

#define CMP_rrWA_gg		instruction_187
#define CMP_rrBC_gg		instruction_18f
#define CMP_rrDE_gg		instruction_197
#define CMP_rrHL9_gg		instruction_19f
#define CMP_rrIX_gg		instruction_1a7
#define CMP_rrIY_gg		instruction_1af
#define CMP_rrSP_gg		instruction_1b7
#define CMP_rrHLb_gg		instruction_1bf

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
#define CPL_g_0                 instruction_1e0
#define CPL_g_1                 instruction_1e1
#define CPL_g_2                 instruction_1e2
#define CPL_g_3                 instruction_1e3
#define CPL_g_4                 instruction_1e4
#define CPL_g_5                 instruction_1e5
#define CPL_g_6                 instruction_1e6
#define CPL_g_7                 instruction_1e7
#define LD_g_0_CF               instruction_1e8
#define LD_g_1_CF               instruction_1e9
#define LD_g_2_CF               instruction_1ea
#define LD_g_3_CF               instruction_1eb
#define LD_g_4_CF               instruction_1ec
#define LD_g_5_CF               instruction_1ed
#define LD_g_6_CF               instruction_1ee
#define LD_g_7_CF               instruction_1ef

// 1 f0 - 1 ff
#define JP_gg                   instruction_1fe
#define SWAP_g                  instruction_1ff

// 2 00 - 2 3f ALU r,(src)
#define ADDC_rA_src		instruction_200
#define ADDC_rW_src		instruction_208
#define ADDC_rC_src		instruction_210
#define ADDC_rB_src		instruction_218
#define ADDC_rE_src		instruction_220
#define ADDC_rD_src		instruction_228
#define ADDC_rL_src		instruction_230
#define ADDC_rH_src		instruction_238

#define ADD_rA_src		instruction_201
#define ADD_rW_src		instruction_209
#define ADD_rC_src		instruction_211
#define ADD_rB_src		instruction_219
#define ADD_rE_src		instruction_221
#define ADD_rD_src		instruction_229
#define ADD_rL_src		instruction_231
#define ADD_rH_src		instruction_239

#define SUBB_rA_src		instruction_202
#define SUBB_rW_src		instruction_20a
#define SUBB_rC_src		instruction_212
#define SUBB_rB_src		instruction_21a
#define SUBB_rE_src		instruction_222
#define SUBB_rD_src		instruction_22a
#define SUBB_rL_src		instruction_232
#define SUBB_rH_src		instruction_23a

#define SUB_rA_src		instruction_203
#define SUB_rW_src		instruction_20b
#define SUB_rC_src		instruction_213
#define SUB_rB_src		instruction_21b
#define SUB_rE_src		instruction_223
#define SUB_rD_src		instruction_22b
#define SUB_rL_src		instruction_233
#define SUB_rH_src		instruction_23b

#define AND_rA_src		instruction_204
#define AND_rW_src		instruction_20c
#define AND_rC_src		instruction_214
#define AND_rB_src		instruction_21c
#define AND_rE_src		instruction_224
#define AND_rD_src		instruction_22c
#define AND_rL_src		instruction_234
#define AND_rH_src		instruction_23c

#define XOR_rA_src		instruction_205
#define XOR_rW_src		instruction_20d
#define XOR_rC_src		instruction_215
#define XOR_rB_src		instruction_21d
#define XOR_rE_src		instruction_225
#define XOR_rD_src		instruction_22d
#define XOR_rL_src		instruction_235
#define XOR_rH_src		instruction_23d

#define OR_rA_src		instruction_206
#define OR_rW_src		instruction_20e
#define OR_rC_src		instruction_216
#define OR_rB_src		instruction_21e
#define OR_rE_src		instruction_226
#define OR_rD_src		instruction_22e
#define OR_rL_src		instruction_236
#define OR_rH_src		instruction_23e

#define CMP_rA_src		instruction_207
#define CMP_rW_src		instruction_20f
#define CMP_rC_src		instruction_217
#define CMP_rB_src		instruction_21f
#define CMP_rE_src		instruction_227
#define CMP_rD_src		instruction_22f
#define CMP_rL_src		instruction_237
#define CMP_rH_src		instruction_23f

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

// 2 50 - 2 5f
#define XOR_CF_src_0            instruction_250
#define XOR_CF_src_1            instruction_251
#define XOR_CF_src_2            instruction_252
#define XOR_CF_src_3            instruction_253
#define XOR_CF_src_4            instruction_254
#define XOR_CF_src_5            instruction_255
#define XOR_CF_src_6            instruction_256
#define XOR_CF_src_7            instruction_257
#define LD_CF_src_0             instruction_258
#define LD_CF_src_1             instruction_259
#define LD_CF_src_2             instruction_25a
#define LD_CF_src_3             instruction_25b
#define LD_CF_src_4             instruction_25c
#define LD_CF_src_5             instruction_25d
#define LD_CF_src_6             instruction_25e
#define LD_CF_src_7             instruction_25f

// 2 60 - 2 6f
#define ADDC_src_n              instruction_260
#define ADD_src_n               instruction_261
#define SUBB_src_n              instruction_262
#define SUB_src_n               instruction_263
#define AND_src_n               instruction_264
#define XOR_src_n               instruction_265
#define OR_src_n                instruction_266
#define CMP_src_n               instruction_267
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
#define CPL_src_0               instruction_2e0
#define CPL_src_1               instruction_2e1
#define CPL_src_2               instruction_2e2
#define CPL_src_3               instruction_2e3
#define CPL_src_4               instruction_2e4
#define CPL_src_5               instruction_2e5
#define CPL_src_6               instruction_2e6
#define CPL_src_7               instruction_2e7
#define LD_src_0_CF             instruction_2e8
#define LD_src_1_CF             instruction_2e9
#define LD_src_2_CF             instruction_2ea
#define LD_src_3_CF             instruction_2eb
#define LD_src_4_CF             instruction_2ec
#define LD_src_5_CF             instruction_2ed
#define LD_src_6_CF             instruction_2ee
#define LD_src_7_CF             instruction_2ef

// 2 f0 - 2 ff
#define INC_src                 instruction_2f0
#define SET_src_A               instruction_2f2
#define LD_src_A_CF             instruction_2f3
#define DEC_src                 instruction_2f8
#define LD_dst_n                instruction_2f9
#define CLR_src_A               instruction_2fa
#define CPL_src_A               instruction_2fb
#define LD_CF_src_A             instruction_2fc
#define JP_src                  instruction_2fe
