

#ifndef __UPHY_PDE_LTEV_OM_H__
#define __UPHY_PDE_LTEV_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VBCH_LS_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VBCH_LS_IN_BBP_MC_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VBCH_LS_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VBCH_LS_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VBCH_LS_OUT_BBP_MC_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VBCH_LS_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VBCH_CHE_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VBCH_CHE_IN_BBP_MC_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VBCH_CHE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VBCH_CHE_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VBCH_CHE_OUT_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VBCH_CHE_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VCCH_INIT_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VCCH_INIT_IN_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VCCH_INIT_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VCCH_INIT_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VCCH_INIT_OUT_BBP_MC_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VCCH_INIT_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int v2v_en                                           :   1               ;    /* 0:0 */
        unsigned int pscch_ue_num                                     :   5               ;    /* 5:1 */
        unsigned int v2v_subfrm_num                                   :   4               ;    /* 9:6 */
        unsigned int rssi_en                                          :   6               ;    /* 15:10 */
        unsigned int v2v_bw                                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VCCH_TFC_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VCCH_TFC_IN_BBP_MC_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VCCH_TFC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VCCH_TFC_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VCCH_TFC_OUT_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VCCH_TFC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VCCH_DPR_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VCCH_DPR_IN_BBP_MC_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VCCH_DPR_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VCCH_DPR_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VCCH_DPR_OUT_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VCCH_DPR_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VCCH_DPC_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VCCH_DPC_IN_BBP_MC_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VCCH_DPC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VCCH_DPC_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VCCH_DPC_OUT_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VCCH_DPC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_INIT_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_INIT_IN_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_INIT_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_INIT_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_INIT_OUT_BBP_MC_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_INIT_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int pssch_ue_num                                     :   20              ;    /* 19:0 */
        unsigned int pssch_ue_total_rbnum                             :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_ZC_GEN_TFE_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_ZC_GEN_TFE_IN_BBP_MC_SUB0                       om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_ZC_GEN_TFE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_ZC_GEN_TFE_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_ZC_GEN_TFE_OUT_BBP_MC_SUB0                      om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_ZC_GEN_TFE_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_TFC_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_TFC_IN_BBP_MC_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_TFC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_TFC_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_TFC_OUT_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_TFC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_ZC_GEN_CHE_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_ZC_GEN_CHE_IN_BBP_MC_SUB0                       om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_ZC_GEN_CHE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_ZC_GEN_CHE_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_ZC_GEN_CHE_OUT_BBP_MC_SUB0                      om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_ZC_GEN_CHE_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_DPR_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_DPR_IN_BBP_MC_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_DPR_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_DPR_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_DPR_OUT_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_DPR_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_DFT_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_DFT_IN_BBP_MC_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_DFT_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_DFT_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_DFT_OUT_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_DFT_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_IRC_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_IRC_IN_BBP_MC_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_IRC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_CHE_VSCH_IRC_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_CHE_VSCH_IRC_OUT_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_CHE_VSCH_IRC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_LTEV_PSB_AGCT_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_LTEV_PSB_AGCT_IN_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_LTEV_PSB_AGCT_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_LTEV_PSB_AGCT_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_LTEV_PSB_AGCT_OUT_BBP_MC_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_LTEV_PSB_AGCT_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_LTEV_PSB_DEM0_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_LTEV_PSB_DEM0_IN_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_LTEV_PSB_DEM0_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_LTEV_PSB_DEM0_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_LTEV_PSB_DEM0_OUT_BBP_MC_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_LTEV_PSB_DEM0_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_LTEV_PSC_DEM0_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_LTEV_PSC_DEM0_IN_BBP_MC_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_LTEV_PSC_DEM0_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_LTEV_PSC_DEM0_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_LTEV_PSC_DEM0_OUT_BBP_MC_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_LTEV_PSC_DEM0_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_PSS_LTEV_LLR_INIT_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_PSS_LTEV_LLR_INIT_IN_BBP_MC_SUB0                         om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_PSS_LTEV_LLR_INIT_IN_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_PSS_LTEV_LLR_INIT_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_PSS_LTEV_LLR_INIT_OUT_BBP_MC_SUB0                        om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_PSS_LTEV_LLR_INIT_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_PSS_LTEV_LLR_CALC_FUNC_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_PSS_LTEV_LLR_CALC_FUNC_IN_BBP_MC_SUB0                    om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_PSS_LTEV_LLR_CALC_FUNC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int pss_config_done                                  :   1               ;    /* 0:0 */
        unsigned int pss_en                                           :   1               ;    /* 1:1 */
        unsigned int pss_ue_en                                        :   20              ;    /* 21:2 */
        unsigned int ltev_task_idx                                    :   3               ;    /* 24:22 */
        unsigned int ltev_cfg_idx                                     :   3               ;    /* 27:25 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} LTEV_SID_PSS_LTEV_LLR_CALC_FUNC_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_PSS_LTEV_LLR_CALC_FUNC_OUT_BBP_MC_SUB0                   om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_PSS_LTEV_LLR_CALC_FUNC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int chan_idx                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int task_status                                      :   4               ;    /* 11:8 */
        unsigned int reserved_1                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} LTEV_SID_PSS_LTEV_LLR_CMD_MV_FUNC_IN_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_PSS_LTEV_LLR_CMD_MV_FUNC_IN_BBP_MC_SUB0                  om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_PSS_LTEV_LLR_CMD_MV_FUNC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int pss_config_done                                  :   1               ;    /* 0:0 */
        unsigned int pss_en                                           :   1               ;    /* 1:1 */
        unsigned int pss_ue_en                                        :   20              ;    /* 21:2 */
        unsigned int reserved_0                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} LTEV_SID_PSS_LTEV_LLR_CMD_MV_FUNC_OUT_BBP_MC_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LTEV_SID_PSS_LTEV_LLR_CMD_MV_FUNC_OUT_BBP_MC_SUB0                 om_data0;
    unsigned int                                                      reserved_0;
} LTEV_SID_PSS_LTEV_LLR_CMD_MV_FUNC_OUT_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} LTEV_SID_PSB_LTEV_DIF_CFG_IN_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} LTEV_SID_PSB_LTEV_DIF_CFG_OUT_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
