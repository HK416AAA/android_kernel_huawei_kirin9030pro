#ifndef __APS_ALF_C_UNION_DEFINE_H__
#define __APS_ALF_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int alf_coef_l_0 : 8 ;
        unsigned int alf_clip_idx_l_0 : 2 ;
        unsigned int alf_coef_l_1 : 8 ;
        unsigned int alf_clip_idx_l_1 : 2 ;
        unsigned int alf_coef_l_2 : 8 ;
        unsigned int alf_clip_idx_l_2 : 2 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_APS_ALF0_D0;
typedef union {
    struct {
        unsigned int alf_coef_l_3 : 8 ;
        unsigned int alf_clip_idx_l_3 : 2 ;
        unsigned int alf_coef_l_4 : 8 ;
        unsigned int alf_clip_idx_l_4 : 2 ;
        unsigned int alf_coef_l_5 : 8 ;
        unsigned int alf_clip_idx_l_5 : 2 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_APS_ALF0_D1;
typedef union {
    struct {
        unsigned int alf_coef_l_6 : 8 ;
        unsigned int alf_clip_idx_l_6 : 2 ;
        unsigned int alf_coef_l_7 : 8 ;
        unsigned int alf_clip_idx_l_7 : 2 ;
        unsigned int alf_coef_l_8 : 8 ;
        unsigned int alf_clip_idx_l_8 : 2 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_APS_ALF0_D2;
typedef union {
    struct {
        unsigned int alf_coef_l_9 : 8 ;
        unsigned int alf_clip_idx_l_9 : 2 ;
        unsigned int alf_coef_l_10 : 8 ;
        unsigned int alf_clip_idx_l_10 : 2 ;
        unsigned int alf_coef_l_11 : 8 ;
        unsigned int alf_clip_idx_l_11 : 2 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_APS_ALF0_D3;
typedef union {
    struct {
        unsigned int alf_coef_c_0 : 8 ;
        unsigned int alf_clip_idx_c_0 : 2 ;
        unsigned int alf_coef_c_1 : 8 ;
        unsigned int alf_clip_idx_c_1 : 2 ;
        unsigned int alf_coef_c_2 : 8 ;
        unsigned int alf_clip_idx_c_2 : 2 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_APS_ALF0_D128;
typedef union {
    struct {
        unsigned int alf_coef_c_3 : 8 ;
        unsigned int alf_clip_idx_c_3 : 2 ;
        unsigned int alf_coef_c_4 : 8 ;
        unsigned int alf_clip_idx_c_4 : 2 ;
        unsigned int alf_coef_c_5 : 8 ;
        unsigned int alf_clip_idx_c_5 : 2 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_APS_ALF0_D129;
typedef union {
    struct {
        unsigned int alf_coef_cc_cb_0 : 8 ;
        unsigned int alf_coef_cc_cb_1 : 8 ;
        unsigned int alf_coef_cc_cb_2 : 8 ;
        unsigned int alf_coef_cc_cb_3 : 8 ;
    } bits;
    unsigned int u32;
} U_APS_ALF0_D144;
typedef union {
    struct {
        unsigned int alf_coef_cc_cb_4 : 8 ;
        unsigned int alf_coef_cc_cb_5 : 8 ;
        unsigned int alf_coef_cc_cb_6 : 8 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_APS_ALF0_D145;
typedef union {
    struct {
        unsigned int alf_coef_cc_cr_0 : 8 ;
        unsigned int alf_coef_cc_cr_1 : 8 ;
        unsigned int alf_coef_cc_cr_2 : 8 ;
        unsigned int alf_coef_cc_cr_3 : 8 ;
    } bits;
    unsigned int u32;
} U_APS_ALF0_D152;
typedef union {
    struct {
        unsigned int alf_coef_cc_cr_4 : 8 ;
        unsigned int alf_coef_cc_cr_5 : 8 ;
        unsigned int alf_coef_cc_cr_6 : 8 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_APS_ALF0_D153;
typedef struct {
    volatile U_APS_ALF0_D0 APS_ALF0_D0 ;
    volatile U_APS_ALF0_D1 APS_ALF0_D1 ;
    volatile U_APS_ALF0_D2 APS_ALF0_D2 ;
    volatile U_APS_ALF0_D3 APS_ALF0_D3 ;
    volatile unsigned int APS_ALF0_D4[96] ;
    volatile unsigned int reserved_0[28] ;
    volatile U_APS_ALF0_D128 APS_ALF0_D128 ;
    volatile U_APS_ALF0_D129 APS_ALF0_D129 ;
    volatile unsigned int APS_ALF0_D130[14] ;
    volatile U_APS_ALF0_D144 APS_ALF0_D144 ;
    volatile U_APS_ALF0_D145 APS_ALF0_D145 ;
    volatile unsigned int APS_ALF0_D146[6] ;
    volatile U_APS_ALF0_D152 APS_ALF0_D152 ;
    volatile U_APS_ALF0_D153 APS_ALF0_D153 ;
    volatile unsigned int APS_ALF0_D154[6] ;
    volatile unsigned int APS_ALF1[160] ;
    volatile unsigned int APS_ALF2[160] ;
    volatile unsigned int APS_ALF3[160] ;
    volatile unsigned int APS_ALF4[160] ;
    volatile unsigned int APS_ALF5[160] ;
    volatile unsigned int APS_ALF6[160] ;
    volatile unsigned int APS_ALF7[160] ;
} S_APS_ALF_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_APS_ALF0_D0 APS_ALF0_D0;
    volatile U_APS_ALF0_D1 APS_ALF0_D1;
    volatile U_APS_ALF0_D2 APS_ALF0_D2;
    volatile U_APS_ALF0_D3 APS_ALF0_D3;
    volatile U_APS_ALF0_D128 APS_ALF0_D128;
    volatile U_APS_ALF0_D129 APS_ALF0_D129;
    volatile U_APS_ALF0_D144 APS_ALF0_D144;
    volatile U_APS_ALF0_D145 APS_ALF0_D145;
    volatile U_APS_ALF0_D152 APS_ALF0_D152;
    volatile U_APS_ALF0_D153 APS_ALF0_D153;
} U_APS_ALF_REGS_TYPE;
#endif
