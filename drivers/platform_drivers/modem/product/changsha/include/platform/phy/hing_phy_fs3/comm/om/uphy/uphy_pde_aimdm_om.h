
#ifndef __UPHY_PDE_AIMDM_OM_H__
#define __UPHY_PDE_AIMDM_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int mode2_nsample                                    :   12              ;    /* 11:0 */
        unsigned int mode2_recv_idx                                   :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_COUNT_SUB0;

typedef union {
    struct {
        unsigned int mode1_nsample                                    :   12              ;    /* 11:0 */
        unsigned int mode1_recv_idx                                   :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_COUNT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    AIMDM_SID_AIMDM_OM_PRED_SCH_COUNT_SUB0                            om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_COUNT_SUB1                            om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_COUNT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    AIMDM_SID_AIMDM_OM_PRED_SCH_COUNT_SUB0                            om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_COUNT_SUB1                            om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_COUNT_BBP_MC;

typedef union {
    struct {
        unsigned int missing_flag                                     :   1               ;    /* 0 */
        unsigned int dynamicth18                                      :   22              ;    /* 22:1 */
        unsigned int pred_sch1_dyn_flag                               :   1               ;    /* 23 */
        unsigned int periodicity                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH1_SUB0;

typedef union {
    struct {
        unsigned int predindex                                        :   7               ;    /* 6:0 */
        unsigned int model_type                                       :   2               ;    /* 8:7 */
        unsigned int insysfn                                          :   10              ;    /* 18:9 */
        unsigned int inslot                                           :   8               ;    /* 26:19 */
        unsigned int inscs                                            :   3               ;    /* 29:27 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH1_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    AIMDM_SID_AIMDM_OM_PRED_SCH1_SUB0                                 om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH1_SUB1                                 om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    AIMDM_SID_AIMDM_OM_PRED_SCH1_SUB0                                 om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH1_SUB1                                 om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH1_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pred1_result0;
    unsigned int                                                      pred1_result1;
} AIMDM_SID_AIMDM_OM_PRED_SCH1_OUT0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pred1_result0;
    unsigned int                                                      pred1_result1;
} AIMDM_SID_AIMDM_OM_PRED_SCH1_OUT0_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pred1_result2;
    unsigned int                                                      pred1_result3;
} AIMDM_SID_AIMDM_OM_PRED_SCH1_OUT1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pred1_result2;
    unsigned int                                                      pred1_result3;
} AIMDM_SID_AIMDM_OM_PRED_SCH1_OUT1_BBP_MC;

typedef union {
    struct {
        unsigned int pred2_soft_out0                                  :   16              ;    /* 15:0 */
        unsigned int pred2_soft_out1                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT0_SUB0;

typedef union {
    struct {
        unsigned int pred2_soft_out2                                  :   16              ;    /* 15:0 */
        unsigned int pred2_soft_out3                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT0_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT0_SUB0                  om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT0_SUB1                  om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT0_SUB0                  om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT0_SUB1                  om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT0_BBP_MC;

typedef union {
    struct {
        unsigned int pred2_soft_out4                                  :   16              ;    /* 15:0 */
        unsigned int pred2_soft_out5                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT1_SUB0;

typedef union {
    struct {
        unsigned int pred2_soft_out6                                  :   16              ;    /* 15:0 */
        unsigned int pred2_soft_out7                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT1_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT1_SUB0                  om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT1_SUB1                  om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT1_SUB0                  om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT1_SUB1                  om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT1_BBP_MC;

typedef union {
    struct {
        unsigned int pred2_soft_out8                                  :   16              ;    /* 15:0 */
        unsigned int pred2_soft_out9                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT2_SUB0;

typedef union {
    struct {
        unsigned int pred2_soft_out10                                 :   16              ;    /* 15:0 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT2_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT2_SUB0                  om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT2_SUB1                  om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT2;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT2_SUB0                  om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT2_SUB1                  om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_SOFT_OUT2_BBP_MC;

typedef union {
    struct {
        unsigned int pred2_recv_flag                                  :   16              ;    /* 15:0 */
        unsigned int pred2_th                                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_DECISION_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_DECISION_SUB0                   om_data0;
    unsigned int                                                      pred2_dynamic_th_18;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_DECISION;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_DECISION_SUB0                   om_data0;
    unsigned int                                                      pred2_dynamic_th_18;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_DECISION_BBP_MC;

typedef union {
    struct {
        unsigned int pred2_grad_calc_cnt                              :   17              ;    /* 16:0 */
        unsigned int pred2_batch_size                                 :   5               ;    /* 21:17 */
        unsigned int pred2_grad_upd_flag                              :   1               ;    /* 22 */
        unsigned int pred2_pds_ind                                    :   1               ;    /* 23 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_WEIGHT_UPD_SUB0;

typedef union {
    struct {
        unsigned int pred2_grad_calc_bm                               :   16              ;    /* 15:0 */
        unsigned int pred2_grad_calc_bv                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_WEIGHT_UPD_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_WEIGHT_UPD_SUB0                 om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_WEIGHT_UPD_SUB1                 om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_WEIGHT_UPD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_WEIGHT_UPD_SUB0                 om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_WEIGHT_UPD_SUB1                 om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_PRED2_WEIGHT_UPD_BBP_MC;

typedef union {
    struct {
        unsigned int sfn_sel                                          :   10              ;    /* 9:0 */
        unsigned int curr_predicted1                                  :   1               ;    /* 10 */
        unsigned int curr_predicted2                                  :   1               ;    /* 11 */
        unsigned int dyn_sel_rst_record                               :   1               ;    /* 12 */
        unsigned int reserved_0                                       :   19              ;    /* 31:13 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_SEL_PARA_SUB0;

typedef union {
    struct {
        unsigned int gain1                                            :   16              ;    /* 15:0 */
        unsigned int gain2                                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_SEL_PARA_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    AIMDM_SID_AIMDM_OM_PRED_SCH_SEL_PARA_SUB0                         om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_SEL_PARA_SUB1                         om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_SEL_PARA;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    AIMDM_SID_AIMDM_OM_PRED_SCH_SEL_PARA_SUB0                         om_data0;
    AIMDM_SID_AIMDM_OM_PRED_SCH_SEL_PARA_SUB1                         om_data1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_SEL_PARA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      gain_filter2;
    unsigned int                                                      gain_filter1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_SEL_GAIN_FILTER;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      gain_filter2;
    unsigned int                                                      gain_filter1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_SEL_GAIN_FILTER_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      mr_filter2;
    unsigned int                                                      mr_filter1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_OUT_MR_FILTER;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      mr_filter2;
    unsigned int                                                      mr_filter1;
} AIMDM_SID_AIMDM_OM_PRED_SCH_OUT_MR_FILTER_BBP_MC;

typedef union {
    struct {
        unsigned int slot_idx_pre                                     :   8               ;    /* 7:0 */
        unsigned int sfn_pre                                          :   10              ;    /* 17:8 */
        unsigned int mode1_r_new                                      :   8               ;    /* 25:18 */
        unsigned int mode2_start                                      :   1               ;    /* 26 */
        unsigned int mode1_start                                      :   1               ;    /* 27 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_SCH_OUT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    AIMDM_SID_AIMDM_OM_PRED_SCH_OUT_SUB0                              om_data0;
    unsigned int                                                      skip_slot_num;
} AIMDM_SID_AIMDM_OM_PRED_SCH_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    AIMDM_SID_AIMDM_OM_PRED_SCH_OUT_SUB0                              om_data0;
    unsigned int                                                      skip_slot_num;
} AIMDM_SID_AIMDM_OM_PRED_SCH_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      commo_init_en;
    unsigned int                                                      cfg_addr;
} AIMDM_SID_AIMDM_OM_PRED_PARA_DIF_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      commo_init_en;
    unsigned int                                                      cfg_addr;
} AIMDM_SID_AIMDM_OM_PRED_PARA_DIF_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      return_flag;
    unsigned int                                                      reserved_0;
} AIMDM_SID_AIMDM_OM_PRED_PARA_DIF_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      return_flag;
    unsigned int                                                      reserved_0;
} AIMDM_SID_AIMDM_OM_PRED_PARA_DIF_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int action_shift                                     :   16              ;    /* 15:0 */
        unsigned int state_shift                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_PARA_CALC_IN_SUB0;

typedef union {
    struct {
        unsigned int q_weight                                         :   16              ;    /* 15:0 */
        unsigned int q_bias                                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} AIMDM_SID_AIMDM_OM_PRED_PARA_CALC_IN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    AIMDM_SID_AIMDM_OM_PRED_PARA_CALC_IN_SUB0                         om_data0;
    AIMDM_SID_AIMDM_OM_PRED_PARA_CALC_IN_SUB1                         om_data1;
} AIMDM_SID_AIMDM_OM_PRED_PARA_CALC_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    AIMDM_SID_AIMDM_OM_PRED_PARA_CALC_IN_SUB0                         om_data0;
    AIMDM_SID_AIMDM_OM_PRED_PARA_CALC_IN_SUB1                         om_data1;
} AIMDM_SID_AIMDM_OM_PRED_PARA_CALC_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} AIMDM_SID_AIMDM_OM_PRED_PARA_CALC_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} AIMDM_SID_AIMDM_OM_PRED_PARA_CALC_OUT_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
