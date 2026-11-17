

#ifndef __UPHY_PDE_TFE_OM_H__
#define __UPHY_PDE_TFE_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_SER_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_SER_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_SER_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_LTE_SSS_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_LTE_SSS_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_LTE_SSS_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_IC0_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_IC0_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_IC0_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_IC1_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_IC1_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_IC1_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_IC_PB_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_IC_PB_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CRS_IC_PB_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC0_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC0_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC0_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC1_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC1_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC1_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC2_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC2_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC2_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC3_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC3_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_RSC3_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC0_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC0_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC0_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC1_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC1_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC1_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC2_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC2_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC2_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC3_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC3_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_CSI_RSC3_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC0_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC0_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC0_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC1_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC1_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC1_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC2_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC2_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC2_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC3_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC3_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC3_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC4_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC4_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC4_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC5_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC5_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC5_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC6_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC6_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC6_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC7_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC7_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC7_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC8_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC8_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TFS_RSC8_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC0_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC0_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC0_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC1_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC1_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC1_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC2_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC2_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC2_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC3_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC3_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_PB_RSC3_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TRS_TFS_RSC9_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TRS_TFS_RSC9_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_SSB_TRS_TFS_RSC9_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_TFS_RSC10_SCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_TFS_RSC10_SCH_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_sub_task_type;
    unsigned int                                                      tfe_sub_task_idx;
} TFE_SID_TFE_TRS_TFS_RSC10_SCH_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      usr_bitmap;
    unsigned int                                                      sch_loop_num;
} TFE_SID_TFE_V2X_PSB_SCH;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      usr_bitmap;
    unsigned int                                                      sch_loop_num;
} TFE_SID_TFE_V2X_PSB_SCH_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      usr_bitmap;
    unsigned int                                                      sch_loop_num;
} TFE_SID_TFE_V2X_PSB_SCH_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      usr_bitmap;
    unsigned int                                                      sch_loop_num;
} TFE_SID_TFE_V2X_PSC_SCH;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      usr_bitmap;
    unsigned int                                                      sch_loop_num;
} TFE_SID_TFE_V2X_PSC_SCH_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      usr_bitmap;
    unsigned int                                                      sch_loop_num;
} TFE_SID_TFE_V2X_PSC_SCH_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      usr_bitmap;
    unsigned int                                                      sch_loop_num;
} TFE_SID_TFE_V2X_PSS_SCH;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      usr_bitmap;
    unsigned int                                                      sch_loop_num;
} TFE_SID_TFE_V2X_PSS_SCH_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      usr_bitmap;
    unsigned int                                                      sch_loop_num;
} TFE_SID_TFE_V2X_PSS_SCH_BBP_MC;

typedef union {
    struct {
        unsigned int sub_task_id                                      :   4               ;    /* 3:0 */
        unsigned int task_id                                          :   4               ;    /* 7:4 */
        unsigned int cfg_idx                                          :   8               ;    /* 15:8 */
        unsigned int slot_idx                                         :   1               ;    /* 16 */
        unsigned int rsv1_0                                           :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TOP_OUT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_TOP_OUT_SUB0                                          om_data0;
    unsigned int                                                      return_val;
} TFE_SID_TFE_TOP_OUT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_TOP_OUT_SUB0                                          om_data0;
    unsigned int                                                      return_val;
} TFE_SID_TFE_TOP_OUT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_TOP_OUT_SUB0                                          om_data0;
    unsigned int                                                      return_val;
} TFE_SID_TFE_TOP_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      agc_bit_r0;
    unsigned int                                                      agc_bit_r1;
    unsigned int                                                      agc_bit_r2;
    unsigned int                                                      agc_bit_r3;
    unsigned int                                                      npw_r0;
    unsigned int                                                      npw_r1;
    unsigned int                                                      npw_r2;
    unsigned int                                                      npw_r3;
    unsigned int                                                      par0;
    unsigned int                                                      par1;
    unsigned int                                                      par2;
    unsigned int                                                      par3;
    unsigned int                                                      par4;
    unsigned int                                                      par5;
    unsigned int                                                      par6;
    unsigned int                                                      par7;
    unsigned int                                                      par8;
    unsigned int                                                      par9;
    unsigned int                                                      par10;
    unsigned int                                                      par11;
    unsigned int                                                      par12;
    unsigned int                                                      par13;
    unsigned int                                                      par14;
    unsigned int                                                      par15;
} TFE_SID_TFE_PDP_BURST_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      agc_bit_r0;
    unsigned int                                                      agc_bit_r1;
    unsigned int                                                      agc_bit_r2;
    unsigned int                                                      agc_bit_r3;
    unsigned int                                                      npw_r0;
    unsigned int                                                      npw_r1;
    unsigned int                                                      npw_r2;
    unsigned int                                                      npw_r3;
    unsigned int                                                      par0;
    unsigned int                                                      par1;
    unsigned int                                                      par2;
    unsigned int                                                      par3;
    unsigned int                                                      par4;
    unsigned int                                                      par5;
    unsigned int                                                      par6;
    unsigned int                                                      par7;
    unsigned int                                                      par8;
    unsigned int                                                      par9;
    unsigned int                                                      par10;
    unsigned int                                                      par11;
    unsigned int                                                      par12;
    unsigned int                                                      par13;
    unsigned int                                                      par14;
    unsigned int                                                      par15;
} TFE_SID_TFE_PDP_BURST_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      agc_bit_r0;
    unsigned int                                                      agc_bit_r1;
    unsigned int                                                      agc_bit_r2;
    unsigned int                                                      agc_bit_r3;
    unsigned int                                                      npw_r0;
    unsigned int                                                      npw_r1;
    unsigned int                                                      npw_r2;
    unsigned int                                                      npw_r3;
    unsigned int                                                      par0;
    unsigned int                                                      par1;
    unsigned int                                                      par2;
    unsigned int                                                      par3;
    unsigned int                                                      par4;
    unsigned int                                                      par5;
    unsigned int                                                      par6;
    unsigned int                                                      par7;
    unsigned int                                                      par8;
    unsigned int                                                      par9;
    unsigned int                                                      par10;
    unsigned int                                                      par11;
    unsigned int                                                      par12;
    unsigned int                                                      par13;
    unsigned int                                                      par14;
    unsigned int                                                      par15;
} TFE_SID_TFE_PDP_BURST_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int sym_offset                                       :   16              ;    /* 15:0 */
        unsigned int rxtx_offset                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_AFC_SYM_INFO_0_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_AFC_SYM_INFO_0_SUB0                                   om_data0;
    unsigned int                                                      ls_len;
    unsigned int                                                      zs_sym_offset;
    unsigned int                                                      path_overthd_ind;
} TFE_SID_TFE_AFC_SYM_INFO_0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_AFC_SYM_INFO_0_SUB0                                   om_data0;
    unsigned int                                                      ls_len;
    unsigned int                                                      zs_sym_offset;
    unsigned int                                                      path_overthd_ind;
} TFE_SID_TFE_AFC_SYM_INFO_0_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_AFC_SYM_INFO_0_SUB0                                   om_data0;
    unsigned int                                                      ls_len;
    unsigned int                                                      zs_sym_offset;
    unsigned int                                                      path_overthd_ind;
} TFE_SID_TFE_AFC_SYM_INFO_0_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      effe_path_pos0;
    unsigned int                                                      effe_path_pos1;
    unsigned int                                                      effe_path_pos2;
    unsigned int                                                      data3;
} TFE_SID_TFE_AFC_SYM_INFO_1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      effe_path_pos0;
    unsigned int                                                      effe_path_pos1;
    unsigned int                                                      effe_path_pos2;
    unsigned int                                                      data3;
} TFE_SID_TFE_AFC_SYM_INFO_1_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      effe_path_pos0;
    unsigned int                                                      effe_path_pos1;
    unsigned int                                                      effe_path_pos2;
    unsigned int                                                      data3;
} TFE_SID_TFE_AFC_SYM_INFO_1_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tim_est;
    unsigned int                                                      frq_est;
    unsigned int                                                      par_thr;
    unsigned int                                                      trms_rpt_v2x_trms_flag;
} TFE_SID_TFE_V2X_RPT_INFO_0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tim_est;
    unsigned int                                                      frq_est;
    unsigned int                                                      par_thr;
    unsigned int                                                      trms_rpt_v2x_trms_flag;
} TFE_SID_TFE_V2X_RPT_INFO_0_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tim_est;
    unsigned int                                                      frq_est;
    unsigned int                                                      par_thr;
    unsigned int                                                      trms_rpt_v2x_trms_flag;
} TFE_SID_TFE_V2X_RPT_INFO_0_BBP_MC;

typedef union {
    struct {
        unsigned int npw_re_r0                                        :   16              ;    /* 15:0 */
        unsigned int npw_re_r1                                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_V2X_RPT_INFO_1_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cs;
    TFE_SID_TFE_V2X_RPT_INFO_1_SUB1                                   om_data1;
    unsigned int                                                      snrdb_r0;
    unsigned int                                                      snrdb_r1;
} TFE_SID_TFE_V2X_RPT_INFO_1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      cs;
    TFE_SID_TFE_V2X_RPT_INFO_1_SUB1                                   om_data1;
    unsigned int                                                      snrdb_r0;
    unsigned int                                                      snrdb_r1;
} TFE_SID_TFE_V2X_RPT_INFO_1_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cs;
    TFE_SID_TFE_V2X_RPT_INFO_1_SUB1                                   om_data1;
    unsigned int                                                      snrdb_r0;
    unsigned int                                                      snrdb_r1;
} TFE_SID_TFE_V2X_RPT_INFO_1_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_V2X_PSB_SMP;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_V2X_PSB_SMP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_V2X_PSB_SMP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_V2X_PSC_SMP;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_V2X_PSC_SMP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_V2X_PSC_SMP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_V2X_PSS_SMP;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_V2X_PSS_SMP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_V2X_PSS_SMP_BBP_MC;

typedef union {
    struct {
        unsigned int afc_burst_idx                                    :   8               ;    /* 7:0 */
        unsigned int afc_cross_gain_shift                             :   8               ;    /* 15:8 */
        unsigned int afc_path_overthd_ind                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_SSB_COMMON_INFO_SUB6;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_SSB_COMMON_INFO_SUB6                                  om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_SSB_COMMON_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_SSB_COMMON_INFO_SUB6                                  om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_SSB_COMMON_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_SSB_COMMON_INFO_SUB6                                  om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_SSB_COMMON_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int afc_burst_idx                                    :   8               ;    /* 7:0 */
        unsigned int afc_cross_gain_shift                             :   8               ;    /* 15:8 */
        unsigned int afc_path_overthd_ind                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TRS_COMMON_INFO_SUB6;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_TRS_COMMON_INFO_SUB6                                  om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_TRS_COMMON_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_TRS_COMMON_INFO_SUB6                                  om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_TRS_COMMON_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_TRS_COMMON_INFO_SUB6                                  om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_TRS_COMMON_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int afc_burst_idx                                    :   8               ;    /* 7:0 */
        unsigned int afc_cross_gain_shift                             :   8               ;    /* 15:8 */
        unsigned int afc_path_overthd_ind                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_CSI_COMMON_INFO_SUB6;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_CSI_COMMON_INFO_SUB6                                  om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_CSI_COMMON_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_CSI_COMMON_INFO_SUB6                                  om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_CSI_COMMON_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_CSI_COMMON_INFO_SUB6                                  om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_CSI_COMMON_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int afc_burst_idx                                    :   8               ;    /* 7:0 */
        unsigned int afc_cross_gain_shift                             :   8               ;    /* 15:8 */
        unsigned int afc_path_overthd_ind                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_SSB_PB_COMMON_INFO_SUB6;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_SSB_PB_COMMON_INFO_SUB6                               om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_SSB_PB_COMMON_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_SSB_PB_COMMON_INFO_SUB6                               om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_SSB_PB_COMMON_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_SSB_PB_COMMON_INFO_SUB6                               om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_SSB_PB_COMMON_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int afc_burst_idx                                    :   8               ;    /* 7:0 */
        unsigned int afc_cross_gain_shift                             :   8               ;    /* 15:8 */
        unsigned int afc_path_overthd_ind                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_SERV_CRS_SSS_COMMON_INFO_SUB6;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_SERV_CRS_SSS_COMMON_INFO_SUB6                         om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_SERV_CRS_SSS_COMMON_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_SERV_CRS_SSS_COMMON_INFO_SUB6                         om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_SERV_CRS_SSS_COMMON_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_SERV_CRS_SSS_COMMON_INFO_SUB6                         om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_SERV_CRS_SSS_COMMON_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int afc_burst_idx                                    :   8               ;    /* 7:0 */
        unsigned int afc_cross_gain_shift                             :   8               ;    /* 15:8 */
        unsigned int afc_path_overthd_ind                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_CRS_IC_COMMON_INFO_SUB6;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_CRS_IC_COMMON_INFO_SUB6                               om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_CRS_IC_COMMON_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_CRS_IC_COMMON_INFO_SUB6                               om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_CRS_IC_COMMON_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_state_rpt;
    unsigned int                                                      peri_cal_tim_npw_avg;
    unsigned int                                                      peri_cal_org_npw_avg;
    unsigned int                                                      peri_cal_pdp_sft_bit;
    unsigned int                                                      pdp_peri_phas_cexp;
    unsigned int                                                      pdp_peri_cross_comp_flag;
    TFE_SID_TFE_CRS_IC_COMMON_INFO_SUB6                               om_data6;
    unsigned int                                                      afc_path_thd;
    unsigned int                                                      afc_om_sfm_idx;
    unsigned int                                                      afc_par;
} TFE_SID_TFE_CRS_IC_COMMON_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_node0_addr;
    unsigned int                                                      tfe_node1_addr;
} TFE_SID_TFE_DAE_NODE_ADDR;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_node0_addr;
    unsigned int                                                      tfe_node1_addr;
} TFE_SID_TFE_DAE_NODE_ADDR_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_node0_addr;
    unsigned int                                                      tfe_node1_addr;
} TFE_SID_TFE_DAE_NODE_ADDR_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rx_num;
    unsigned int                                                      port_num;
    unsigned int                                                      sym_num;
    unsigned int                                                      ifft_idx;
} TFE_SID_TFE_PARA_DAT_EXCEPTION_RPT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      rx_num;
    unsigned int                                                      port_num;
    unsigned int                                                      sym_num;
    unsigned int                                                      ifft_idx;
} TFE_SID_TFE_PARA_DAT_EXCEPTION_RPT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rx_num;
    unsigned int                                                      port_num;
    unsigned int                                                      sym_num;
    unsigned int                                                      ifft_idx;
} TFE_SID_TFE_PARA_DAT_EXCEPTION_RPT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_OM_SMP_IN_DATA;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_OM_SMP_IN_DATA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_OM_SMP_IN_DATA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_SSB_PDP;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_SSB_PDP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_SSB_PDP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_TRS_PDP;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_TRS_PDP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_TRS_PDP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_CSI_PDP;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_CSI_PDP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_CSI_PDP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_SSB_PB_PDP;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_SSB_PB_PDP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_SSB_PB_PDP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_SERV_CRS_SSS_PDP;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_SERV_CRS_SSS_PDP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_SERV_CRS_SSS_PDP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_CRS_IC_PDP;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_CRS_IC_PDP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_CRS_IC_PDP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_SSB_PKT_HEAD;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_SSB_PKT_HEAD_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_SSB_PKT_HEAD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_TRS_PKT_HEAD;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_TRS_PKT_HEAD_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_TRS_PKT_HEAD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_CSI_PKT_HEAD;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_CSI_PKT_HEAD_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_CSI_PKT_HEAD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_SSB_PB_PKT_HEAD;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_SSB_PB_PKT_HEAD_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_SSB_PB_PKT_HEAD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_SERV_CRS_SSS_PKT_HEAD;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_SERV_CRS_SSS_PKT_HEAD_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_SERV_CRS_SSS_PKT_HEAD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_CRS_IC_PKT_HEAD;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_CRS_IC_PKT_HEAD_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
} TFE_SID_TFE_CRS_IC_PKT_HEAD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      td_irc_ruu00_re;
    unsigned int                                                      td_irc_ruu00_im;
    unsigned int                                                      td_irc_ruu11_re;
    unsigned int                                                      td_irc_ruu11_im;
    unsigned int                                                      td_irc_ruu22_re;
    unsigned int                                                      td_irc_ruu22_im;
    unsigned int                                                      td_irc_ruu33_re;
    unsigned int                                                      td_irc_ruu33_im;
    unsigned int                                                      td_irc_ruu32_re;
    unsigned int                                                      td_irc_ruu32_im;
    unsigned int                                                      td_irc_ruu30_re;
    unsigned int                                                      td_irc_ruu30_im;
    unsigned int                                                      td_irc_ruu10_re;
    unsigned int                                                      td_irc_ruu10_im;
    unsigned int                                                      td_irc_ruu21_re;
    unsigned int                                                      td_irc_ruu21_im;
    unsigned int                                                      td_irc_ruu31_re;
    unsigned int                                                      td_irc_ruu31_im;
    unsigned int                                                      td_irc_ruu20_re;
    unsigned int                                                      td_irc_ruu20_im;
    unsigned int                                                      td_irc_vld_flag;
    unsigned int                                                      td_irc_dire_same;
    unsigned int                                                      td_irc_npw_idx;
    unsigned int                                                      td_irc_path_idx1;
    unsigned int                                                      td_irc_path_idx0;
    unsigned int                                                      td_irc_path_idx3;
    unsigned int                                                      td_irc_path_idx2;
    unsigned int                                                      td_irc_rsv1_0;
} TFE_SID_TFE_TD_IRC_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      td_irc_ruu00_re;
    unsigned int                                                      td_irc_ruu00_im;
    unsigned int                                                      td_irc_ruu11_re;
    unsigned int                                                      td_irc_ruu11_im;
    unsigned int                                                      td_irc_ruu22_re;
    unsigned int                                                      td_irc_ruu22_im;
    unsigned int                                                      td_irc_ruu33_re;
    unsigned int                                                      td_irc_ruu33_im;
    unsigned int                                                      td_irc_ruu32_re;
    unsigned int                                                      td_irc_ruu32_im;
    unsigned int                                                      td_irc_ruu30_re;
    unsigned int                                                      td_irc_ruu30_im;
    unsigned int                                                      td_irc_ruu10_re;
    unsigned int                                                      td_irc_ruu10_im;
    unsigned int                                                      td_irc_ruu21_re;
    unsigned int                                                      td_irc_ruu21_im;
    unsigned int                                                      td_irc_ruu31_re;
    unsigned int                                                      td_irc_ruu31_im;
    unsigned int                                                      td_irc_ruu20_re;
    unsigned int                                                      td_irc_ruu20_im;
    unsigned int                                                      td_irc_vld_flag;
    unsigned int                                                      td_irc_dire_same;
    unsigned int                                                      td_irc_npw_idx;
    unsigned int                                                      td_irc_path_idx1;
    unsigned int                                                      td_irc_path_idx0;
    unsigned int                                                      td_irc_path_idx3;
    unsigned int                                                      td_irc_path_idx2;
    unsigned int                                                      td_irc_rsv1_0;
} TFE_SID_TFE_TD_IRC_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      td_irc_ruu00_re;
    unsigned int                                                      td_irc_ruu00_im;
    unsigned int                                                      td_irc_ruu11_re;
    unsigned int                                                      td_irc_ruu11_im;
    unsigned int                                                      td_irc_ruu22_re;
    unsigned int                                                      td_irc_ruu22_im;
    unsigned int                                                      td_irc_ruu33_re;
    unsigned int                                                      td_irc_ruu33_im;
    unsigned int                                                      td_irc_ruu32_re;
    unsigned int                                                      td_irc_ruu32_im;
    unsigned int                                                      td_irc_ruu30_re;
    unsigned int                                                      td_irc_ruu30_im;
    unsigned int                                                      td_irc_ruu10_re;
    unsigned int                                                      td_irc_ruu10_im;
    unsigned int                                                      td_irc_ruu21_re;
    unsigned int                                                      td_irc_ruu21_im;
    unsigned int                                                      td_irc_ruu31_re;
    unsigned int                                                      td_irc_ruu31_im;
    unsigned int                                                      td_irc_ruu20_re;
    unsigned int                                                      td_irc_ruu20_im;
    unsigned int                                                      td_irc_vld_flag;
    unsigned int                                                      td_irc_dire_same;
    unsigned int                                                      td_irc_npw_idx;
    unsigned int                                                      td_irc_path_idx1;
    unsigned int                                                      td_irc_path_idx0;
    unsigned int                                                      td_irc_path_idx3;
    unsigned int                                                      td_irc_path_idx2;
    unsigned int                                                      td_irc_rsv1_0;
} TFE_SID_TFE_TD_IRC_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
} TFE_SID_TFE_AFC_PATH_IDX;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
} TFE_SID_TFE_AFC_PATH_IDX_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
} TFE_SID_TFE_AFC_PATH_IDX_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_AFC_CROSS_SEL;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_AFC_CROSS_SEL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} TFE_SID_TFE_AFC_CROSS_SEL_BBP_MC;

typedef union {
    struct {
        int npw_avg                                                   :   16              ;    /* 15:0 */
        int fft_pdp                                                   :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB0;

typedef union {
    struct {
        int ofdm_win_intref                                           :   16              ;    /* 15:0 */
        int ofdm_win_into                                             :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB2;

typedef union {
    struct {
        int win_nfft_bit                                              :   16              ;    /* 15:0 */
        int tim_org_intp_sel                                          :   1               ;    /* 16 */
        int rs_type                                                   :   15              ;    /* 31:17 */
    } bits;
    int u32;
} TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB3;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB0                                  om_data0;
    int                                                               in_snr;
    TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB2                                  om_data2;
    TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB3                                  om_data3;
    int                                                               snr_thres;
    int                                                               ofdm_win_snr0;
    int                                                               var_r_all_shift0_lo;
    int                                                               var_r_all_shift0_hi;
    int                                                               var_r_all_shift1_lo;
    int                                                               var_r_all_shift1_hi;
    int                                                               var_r_all_shift2_lo;
    int                                                               var_r_all_shift2_hi;
    int                                                               var_r_all_shift3_lo;
    int                                                               var_r_all_shift3_hi;
    int                                                               var_r_all_shift4_lo;
    int                                                               var_r_all_shift4_hi;
    int                                                               var_r_all_shift5_lo;
    int                                                               var_r_all_shift5_hi;
    int                                                               var_r_all_shift6_lo;
    int                                                               var_r_all_shift6_hi;
    int                                                               var_r_all_shift7_lo;
    int                                                               var_r_all_shift7_hi;
    int                                                               var_l_all_shift0_lo;
    int                                                               var_l_all_shift0_hi;
    int                                                               var_l_all_shift1_lo;
    int                                                               var_l_all_shift1_hi;
    int                                                               var_l_all_shift2_lo;
    int                                                               var_l_all_shift2_hi;
    int                                                               var_l_all_shift3_lo;
    int                                                               var_l_all_shift3_hi;
    int                                                               var_l_all_shift4_lo;
    int                                                               var_l_all_shift4_hi;
    int                                                               var_l_all_shift5_lo;
    int                                                               var_l_all_shift5_hi;
    int                                                               var_l_all_shift6_lo;
    int                                                               var_l_all_shift6_hi;
    int                                                               var_l_all_shift7_lo;
    int                                                               var_l_all_shift7_hi;
} TFE_SID_TFE_OFDM_WIN_VAR_VM;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB0                                  om_data0;
    unsigned int                                                      in_snr;
    TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB2                                  om_data2;
    TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB3                                  om_data3;
    unsigned int                                                      snr_thres;
    unsigned int                                                      ofdm_win_snr0;
    unsigned int                                                      var_r_all_shift0_lo;
    unsigned int                                                      var_r_all_shift0_hi;
    unsigned int                                                      var_r_all_shift1_lo;
    unsigned int                                                      var_r_all_shift1_hi;
    unsigned int                                                      var_r_all_shift2_lo;
    unsigned int                                                      var_r_all_shift2_hi;
    unsigned int                                                      var_r_all_shift3_lo;
    unsigned int                                                      var_r_all_shift3_hi;
    unsigned int                                                      var_r_all_shift4_lo;
    unsigned int                                                      var_r_all_shift4_hi;
    unsigned int                                                      var_r_all_shift5_lo;
    unsigned int                                                      var_r_all_shift5_hi;
    unsigned int                                                      var_r_all_shift6_lo;
    unsigned int                                                      var_r_all_shift6_hi;
    unsigned int                                                      var_r_all_shift7_lo;
    unsigned int                                                      var_r_all_shift7_hi;
    unsigned int                                                      var_l_all_shift0_lo;
    unsigned int                                                      var_l_all_shift0_hi;
    unsigned int                                                      var_l_all_shift1_lo;
    unsigned int                                                      var_l_all_shift1_hi;
    unsigned int                                                      var_l_all_shift2_lo;
    unsigned int                                                      var_l_all_shift2_hi;
    unsigned int                                                      var_l_all_shift3_lo;
    unsigned int                                                      var_l_all_shift3_hi;
    unsigned int                                                      var_l_all_shift4_lo;
    unsigned int                                                      var_l_all_shift4_hi;
    unsigned int                                                      var_l_all_shift5_lo;
    unsigned int                                                      var_l_all_shift5_hi;
    unsigned int                                                      var_l_all_shift6_lo;
    unsigned int                                                      var_l_all_shift6_hi;
    unsigned int                                                      var_l_all_shift7_lo;
    unsigned int                                                      var_l_all_shift7_hi;
} TFE_SID_TFE_OFDM_WIN_VAR_VM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB0                                  om_data0;
    unsigned int                                                      in_snr;
    TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB2                                  om_data2;
    TFE_SID_TFE_OFDM_WIN_VAR_VM_SUB3                                  om_data3;
    unsigned int                                                      snr_thres;
    unsigned int                                                      ofdm_win_snr0;
    unsigned int                                                      var_r_all_shift0_lo;
    unsigned int                                                      var_r_all_shift0_hi;
    unsigned int                                                      var_r_all_shift1_lo;
    unsigned int                                                      var_r_all_shift1_hi;
    unsigned int                                                      var_r_all_shift2_lo;
    unsigned int                                                      var_r_all_shift2_hi;
    unsigned int                                                      var_r_all_shift3_lo;
    unsigned int                                                      var_r_all_shift3_hi;
    unsigned int                                                      var_r_all_shift4_lo;
    unsigned int                                                      var_r_all_shift4_hi;
    unsigned int                                                      var_r_all_shift5_lo;
    unsigned int                                                      var_r_all_shift5_hi;
    unsigned int                                                      var_r_all_shift6_lo;
    unsigned int                                                      var_r_all_shift6_hi;
    unsigned int                                                      var_r_all_shift7_lo;
    unsigned int                                                      var_r_all_shift7_hi;
    unsigned int                                                      var_l_all_shift0_lo;
    unsigned int                                                      var_l_all_shift0_hi;
    unsigned int                                                      var_l_all_shift1_lo;
    unsigned int                                                      var_l_all_shift1_hi;
    unsigned int                                                      var_l_all_shift2_lo;
    unsigned int                                                      var_l_all_shift2_hi;
    unsigned int                                                      var_l_all_shift3_lo;
    unsigned int                                                      var_l_all_shift3_hi;
    unsigned int                                                      var_l_all_shift4_lo;
    unsigned int                                                      var_l_all_shift4_hi;
    unsigned int                                                      var_l_all_shift5_lo;
    unsigned int                                                      var_l_all_shift5_hi;
    unsigned int                                                      var_l_all_shift6_lo;
    unsigned int                                                      var_l_all_shift6_hi;
    unsigned int                                                      var_l_all_shift7_lo;
    unsigned int                                                      var_l_all_shift7_hi;
} TFE_SID_TFE_OFDM_WIN_VAR_VM_BBP_MC;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_0                                   :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_1                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB0;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_2                                   :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_3                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB1;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_4                                   :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_5                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB2;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_6                                   :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_7                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB3;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_8                                   :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_9                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB4;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_10                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_11                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB5;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_12                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_13                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB6;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_14                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_15                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB7;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_16                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_17                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB8;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_18                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_19                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB9;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_20                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_21                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB10;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_22                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_23                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB11;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_24                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_25                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB12;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_26                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_27                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB13;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_28                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_29                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB14;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_30                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_31                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB15;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_32                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_33                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB16;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_34                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_35                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB17;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_36                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_37                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB18;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_38                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_39                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB19;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_40                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_41                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB20;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_42                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_43                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB21;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_44                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_45                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB22;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_46                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_47                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB23;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_48                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_49                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB24;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_50                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_51                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB25;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_52                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_53                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB26;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_54                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_55                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB27;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_56                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_57                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB28;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_58                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_59                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB29;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_60                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_61                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB30;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_62                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_63                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB31;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_64                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_65                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB32;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_66                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_67                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB33;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_68                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_69                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB34;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_70                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_71                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB35;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_72                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_73                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB36;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_74                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_75                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB37;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_76                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_77                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB38;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_78                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_79                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB39;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_80                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_81                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB40;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_82                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_83                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB41;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_84                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_85                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB42;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_86                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_87                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB43;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_88                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_89                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB44;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_90                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_91                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB45;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_92                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_93                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB46;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_94                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_95                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB47;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_96                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_97                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB48;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_98                                  :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_99                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB49;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_100                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_101                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB50;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_102                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_103                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB51;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_104                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_105                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB52;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_106                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_107                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB53;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_108                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_109                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB54;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_110                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_111                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB55;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_112                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_113                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB56;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_114                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_115                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB57;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_116                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_117                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB58;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_118                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_119                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB59;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_120                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_121                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB60;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_122                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_123                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB61;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_124                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_125                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB62;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_126                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_127                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB63;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_128                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_129                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB64;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_130                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_131                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB65;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_132                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_133                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB66;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_134                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_135                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB67;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_136                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_137                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB68;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_138                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_139                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB69;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_140                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_141                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB70;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_142                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_143                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB71;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_144                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_145                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB72;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_146                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_147                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB73;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_148                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_149                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB74;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_150                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_151                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB75;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_152                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_153                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB76;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_154                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_155                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB77;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_156                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_157                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB78;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_158                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_159                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB79;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_160                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_161                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB80;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_162                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_163                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB81;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_164                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_165                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB82;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_166                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_167                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB83;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_168                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_169                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB84;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_170                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_171                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB85;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_172                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_173                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB86;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_174                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_175                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB87;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_176                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_177                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB88;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_178                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_179                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB89;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_180                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_181                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB90;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_182                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_183                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB91;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_184                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_185                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB92;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_186                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_187                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB93;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_188                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_189                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB94;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_190                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_191                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB95;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_192                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_193                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB96;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_194                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_195                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB97;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_196                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_197                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB98;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_198                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_199                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB99;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_200                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_201                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB100;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_202                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_203                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB101;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_204                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_205                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB102;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_206                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_207                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB103;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_208                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_209                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB104;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_210                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_211                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB105;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_212                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_213                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB106;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_214                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_215                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB107;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_216                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_217                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB108;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_218                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_219                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB109;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_220                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_221                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB110;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_222                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_223                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB111;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_224                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_225                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB112;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_226                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_227                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB113;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_228                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_229                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB114;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_230                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_231                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB115;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_232                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_233                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB116;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_234                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_235                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB117;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_236                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_237                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB118;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_238                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_239                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB119;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_240                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_241                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB120;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_242                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_243                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB121;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_244                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_245                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB122;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_246                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_247                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB123;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_248                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_249                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB124;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_250                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_251                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB125;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_252                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_253                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB126;

typedef union {
    struct {
        unsigned int ofdm_win_pdp_254                                 :   16              ;    /* 15:0 */
        unsigned int ofdm_win_pdp_255                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB127;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB0                                om_data0;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB1                                om_data1;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB2                                om_data2;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB3                                om_data3;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB4                                om_data4;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB5                                om_data5;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB6                                om_data6;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB7                                om_data7;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB8                                om_data8;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB9                                om_data9;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB10                               om_data10;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB11                               om_data11;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB12                               om_data12;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB13                               om_data13;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB14                               om_data14;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB15                               om_data15;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB16                               om_data16;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB17                               om_data17;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB18                               om_data18;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB19                               om_data19;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB20                               om_data20;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB21                               om_data21;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB22                               om_data22;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB23                               om_data23;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB24                               om_data24;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB25                               om_data25;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB26                               om_data26;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB27                               om_data27;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB28                               om_data28;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB29                               om_data29;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB30                               om_data30;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB31                               om_data31;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB32                               om_data32;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB33                               om_data33;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB34                               om_data34;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB35                               om_data35;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB36                               om_data36;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB37                               om_data37;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB38                               om_data38;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB39                               om_data39;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB40                               om_data40;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB41                               om_data41;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB42                               om_data42;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB43                               om_data43;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB44                               om_data44;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB45                               om_data45;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB46                               om_data46;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB47                               om_data47;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB48                               om_data48;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB49                               om_data49;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB50                               om_data50;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB51                               om_data51;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB52                               om_data52;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB53                               om_data53;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB54                               om_data54;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB55                               om_data55;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB56                               om_data56;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB57                               om_data57;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB58                               om_data58;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB59                               om_data59;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB60                               om_data60;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB61                               om_data61;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB62                               om_data62;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB63                               om_data63;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB64                               om_data64;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB65                               om_data65;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB66                               om_data66;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB67                               om_data67;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB68                               om_data68;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB69                               om_data69;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB70                               om_data70;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB71                               om_data71;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB72                               om_data72;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB73                               om_data73;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB74                               om_data74;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB75                               om_data75;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB76                               om_data76;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB77                               om_data77;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB78                               om_data78;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB79                               om_data79;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB80                               om_data80;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB81                               om_data81;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB82                               om_data82;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB83                               om_data83;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB84                               om_data84;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB85                               om_data85;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB86                               om_data86;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB87                               om_data87;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB88                               om_data88;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB89                               om_data89;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB90                               om_data90;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB91                               om_data91;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB92                               om_data92;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB93                               om_data93;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB94                               om_data94;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB95                               om_data95;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB96                               om_data96;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB97                               om_data97;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB98                               om_data98;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB99                               om_data99;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB100                              om_data100;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB101                              om_data101;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB102                              om_data102;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB103                              om_data103;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB104                              om_data104;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB105                              om_data105;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB106                              om_data106;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB107                              om_data107;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB108                              om_data108;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB109                              om_data109;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB110                              om_data110;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB111                              om_data111;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB112                              om_data112;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB113                              om_data113;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB114                              om_data114;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB115                              om_data115;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB116                              om_data116;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB117                              om_data117;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB118                              om_data118;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB119                              om_data119;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB120                              om_data120;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB121                              om_data121;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB122                              om_data122;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB123                              om_data123;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB124                              om_data124;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB125                              om_data125;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB126                              om_data126;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB127                              om_data127;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB0                                om_data0;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB1                                om_data1;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB2                                om_data2;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB3                                om_data3;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB4                                om_data4;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB5                                om_data5;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB6                                om_data6;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB7                                om_data7;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB8                                om_data8;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB9                                om_data9;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB10                               om_data10;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB11                               om_data11;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB12                               om_data12;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB13                               om_data13;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB14                               om_data14;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB15                               om_data15;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB16                               om_data16;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB17                               om_data17;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB18                               om_data18;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB19                               om_data19;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB20                               om_data20;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB21                               om_data21;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB22                               om_data22;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB23                               om_data23;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB24                               om_data24;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB25                               om_data25;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB26                               om_data26;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB27                               om_data27;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB28                               om_data28;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB29                               om_data29;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB30                               om_data30;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB31                               om_data31;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB32                               om_data32;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB33                               om_data33;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB34                               om_data34;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB35                               om_data35;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB36                               om_data36;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB37                               om_data37;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB38                               om_data38;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB39                               om_data39;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB40                               om_data40;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB41                               om_data41;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB42                               om_data42;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB43                               om_data43;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB44                               om_data44;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB45                               om_data45;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB46                               om_data46;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB47                               om_data47;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB48                               om_data48;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB49                               om_data49;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB50                               om_data50;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB51                               om_data51;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB52                               om_data52;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB53                               om_data53;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB54                               om_data54;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB55                               om_data55;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB56                               om_data56;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB57                               om_data57;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB58                               om_data58;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB59                               om_data59;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB60                               om_data60;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB61                               om_data61;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB62                               om_data62;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB63                               om_data63;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB64                               om_data64;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB65                               om_data65;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB66                               om_data66;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB67                               om_data67;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB68                               om_data68;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB69                               om_data69;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB70                               om_data70;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB71                               om_data71;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB72                               om_data72;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB73                               om_data73;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB74                               om_data74;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB75                               om_data75;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB76                               om_data76;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB77                               om_data77;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB78                               om_data78;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB79                               om_data79;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB80                               om_data80;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB81                               om_data81;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB82                               om_data82;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB83                               om_data83;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB84                               om_data84;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB85                               om_data85;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB86                               om_data86;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB87                               om_data87;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB88                               om_data88;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB89                               om_data89;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB90                               om_data90;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB91                               om_data91;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB92                               om_data92;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB93                               om_data93;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB94                               om_data94;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB95                               om_data95;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB96                               om_data96;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB97                               om_data97;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB98                               om_data98;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB99                               om_data99;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB100                              om_data100;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB101                              om_data101;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB102                              om_data102;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB103                              om_data103;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB104                              om_data104;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB105                              om_data105;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB106                              om_data106;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB107                              om_data107;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB108                              om_data108;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB109                              om_data109;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB110                              om_data110;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB111                              om_data111;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB112                              om_data112;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB113                              om_data113;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB114                              om_data114;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB115                              om_data115;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB116                              om_data116;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB117                              om_data117;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB118                              om_data118;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB119                              om_data119;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB120                              om_data120;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB121                              om_data121;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB122                              om_data122;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB123                              om_data123;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB124                              om_data124;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB125                              om_data125;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB126                              om_data126;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB127                              om_data127;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB0                                om_data0;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB1                                om_data1;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB2                                om_data2;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB3                                om_data3;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB4                                om_data4;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB5                                om_data5;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB6                                om_data6;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB7                                om_data7;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB8                                om_data8;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB9                                om_data9;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB10                               om_data10;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB11                               om_data11;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB12                               om_data12;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB13                               om_data13;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB14                               om_data14;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB15                               om_data15;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB16                               om_data16;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB17                               om_data17;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB18                               om_data18;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB19                               om_data19;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB20                               om_data20;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB21                               om_data21;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB22                               om_data22;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB23                               om_data23;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB24                               om_data24;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB25                               om_data25;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB26                               om_data26;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB27                               om_data27;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB28                               om_data28;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB29                               om_data29;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB30                               om_data30;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB31                               om_data31;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB32                               om_data32;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB33                               om_data33;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB34                               om_data34;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB35                               om_data35;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB36                               om_data36;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB37                               om_data37;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB38                               om_data38;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB39                               om_data39;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB40                               om_data40;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB41                               om_data41;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB42                               om_data42;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB43                               om_data43;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB44                               om_data44;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB45                               om_data45;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB46                               om_data46;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB47                               om_data47;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB48                               om_data48;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB49                               om_data49;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB50                               om_data50;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB51                               om_data51;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB52                               om_data52;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB53                               om_data53;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB54                               om_data54;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB55                               om_data55;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB56                               om_data56;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB57                               om_data57;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB58                               om_data58;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB59                               om_data59;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB60                               om_data60;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB61                               om_data61;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB62                               om_data62;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB63                               om_data63;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB64                               om_data64;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB65                               om_data65;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB66                               om_data66;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB67                               om_data67;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB68                               om_data68;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB69                               om_data69;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB70                               om_data70;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB71                               om_data71;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB72                               om_data72;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB73                               om_data73;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB74                               om_data74;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB75                               om_data75;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB76                               om_data76;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB77                               om_data77;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB78                               om_data78;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB79                               om_data79;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB80                               om_data80;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB81                               om_data81;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB82                               om_data82;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB83                               om_data83;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB84                               om_data84;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB85                               om_data85;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB86                               om_data86;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB87                               om_data87;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB88                               om_data88;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB89                               om_data89;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB90                               om_data90;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB91                               om_data91;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB92                               om_data92;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB93                               om_data93;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB94                               om_data94;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB95                               om_data95;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB96                               om_data96;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB97                               om_data97;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB98                               om_data98;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB99                               om_data99;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB100                              om_data100;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB101                              om_data101;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB102                              om_data102;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB103                              om_data103;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB104                              om_data104;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB105                              om_data105;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB106                              om_data106;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB107                              om_data107;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB108                              om_data108;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB109                              om_data109;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB110                              om_data110;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB111                              om_data111;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB112                              om_data112;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB113                              om_data113;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB114                              om_data114;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB115                              om_data115;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB116                              om_data116;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB117                              om_data117;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB118                              om_data118;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB119                              om_data119;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB120                              om_data120;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB121                              om_data121;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB122                              om_data122;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB123                              om_data123;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB124                              om_data124;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB125                              om_data125;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB126                              om_data126;
    TFE_SID_TFE_OFDM_WIN_PDP_VM_L_SUB127                              om_data127;
} TFE_SID_TFE_OFDM_WIN_PDP_VM_L_BBP_MC;

typedef union {
    struct {
        int fcorr_rs_type                                             :   16              ;    /* 15:0 */
        int fcorr_pilot_d                                             :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB0;

typedef union {
    struct {
        int fcorr_pdp_lenth                                           :   16              ;    /* 15:0 */
        int fcorr_time_flag                                           :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB1;

typedef union {
    struct {
        int fcorr_pdp_timing_diff                                     :   16              ;    /* 15:0 */
        int fcorr_fpi_valid_flag                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB2;

typedef union {
    struct {
        int fcorr_inmaxpowerpath                                      :   16              ;    /* 15:0 */
        int fcorr_in_pdp_first_path_pos                               :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB3;

typedef union {
    struct {
        int fcorr_pdp_noise_final                                     :   16              ;    /* 15:0 */
        int fcorr_win_scs_ratio_bit                                   :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB4;

typedef union {
    struct {
        int fcorr_advance                                             :   16              ;    /* 15:0 */
        int fcorr_revise                                              :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB5;

typedef union {
    struct {
        int fcorr_zero_in_pos_origin                                  :   16              ;    /* 15:0 */
        int fcorr_zero_in_pos                                         :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB6;

typedef union {
    struct {
        int fcorr_noise_th                                            :   16              ;    /* 15:0 */
        int fcorr_add_zero_flag                                       :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB7;

typedef union {
    struct {
        int fcorr_set_zero_flag                                       :   16              ;    /* 15:0 */
        int fcorr_x_factor                                            :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB8;

typedef union {
    struct {
        int fcorr_tru_fpi_flag                                        :   16              ;    /* 15:0 */
        int fcorr_pdp_noise_factor                                    :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB9;

typedef union {
    struct {
        int fcorr_modify_factor1                                      :   16              ;    /* 15:0 */
        int fcorr_modify_factor2                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB10;

typedef union {
    struct {
        int fcorr_modify_factor3                                      :   16              ;    /* 15:0 */
        int fcorr_th1                                                 :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB11;

typedef union {
    struct {
        int fcorr_th2                                                 :   16              ;    /* 15:0 */
        int reverse1                                                  :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB12;

typedef union {
    struct {
        int reverse3                                                  :   16              ;    /* 15:0 */
        int reverse2                                                  :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB13;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB0                              om_data0;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB1                              om_data1;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB2                              om_data2;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB3                              om_data3;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB4                              om_data4;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB5                              om_data5;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB6                              om_data6;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB7                              om_data7;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB8                              om_data8;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB9                              om_data9;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB10                             om_data10;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB11                             om_data11;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB12                             om_data12;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB13                             om_data13;
} TFE_SID_TFE_FCORR_PARAMETERS_DM;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB0                              om_data0;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB1                              om_data1;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB2                              om_data2;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB3                              om_data3;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB4                              om_data4;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB5                              om_data5;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB6                              om_data6;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB7                              om_data7;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB8                              om_data8;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB9                              om_data9;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB10                             om_data10;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB11                             om_data11;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB12                             om_data12;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB13                             om_data13;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB0                              om_data0;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB1                              om_data1;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB2                              om_data2;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB3                              om_data3;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB4                              om_data4;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB5                              om_data5;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB6                              om_data6;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB7                              om_data7;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB8                              om_data8;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB9                              om_data9;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB10                             om_data10;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB11                             om_data11;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB12                             om_data12;
    TFE_SID_TFE_FCORR_PARAMETERS_DM_SUB13                             om_data13;
} TFE_SID_TFE_FCORR_PARAMETERS_DM_BBP_MC;

typedef union {
    struct {
        int fcorr_lte_out_real0                                       :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag0                                       :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB0;

typedef union {
    struct {
        int fcorr_lte_out_real1                                       :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag1                                       :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB1;

typedef union {
    struct {
        int fcorr_lte_out_real2                                       :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag2                                       :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB2;

typedef union {
    struct {
        int fcorr_lte_out_real3                                       :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag3                                       :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB3;

typedef union {
    struct {
        int fcorr_lte_out_real4                                       :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag4                                       :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB4;

typedef union {
    struct {
        int fcorr_lte_out_real5                                       :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag5                                       :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB5;

typedef union {
    struct {
        int fcorr_lte_out_real6                                       :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag6                                       :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB6;

typedef union {
    struct {
        int fcorr_lte_out_real7                                       :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag7                                       :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB7;

typedef union {
    struct {
        int fcorr_lte_out_real8                                       :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag8                                       :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB8;

typedef union {
    struct {
        int fcorr_lte_out_real9                                       :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag9                                       :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB9;

typedef union {
    struct {
        int fcorr_lte_out_real10                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag10                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB10;

typedef union {
    struct {
        int fcorr_lte_out_real11                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag11                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB11;

typedef union {
    struct {
        int fcorr_lte_out_real12                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag12                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB12;

typedef union {
    struct {
        int fcorr_lte_out_real13                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag13                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB13;

typedef union {
    struct {
        int fcorr_lte_out_real14                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag14                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB14;

typedef union {
    struct {
        int fcorr_lte_out_real15                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag15                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB15;

typedef union {
    struct {
        int fcorr_lte_out_real16                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag16                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB16;

typedef union {
    struct {
        int fcorr_lte_out_real17                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag17                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB17;

typedef union {
    struct {
        int fcorr_lte_out_real18                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag18                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB18;

typedef union {
    struct {
        int fcorr_lte_out_real19                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag19                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB19;

typedef union {
    struct {
        int fcorr_lte_out_real20                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag20                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB20;

typedef union {
    struct {
        int fcorr_lte_out_real21                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag21                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB21;

typedef union {
    struct {
        int fcorr_lte_out_real22                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag22                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB22;

typedef union {
    struct {
        int fcorr_lte_out_real23                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag23                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB23;

typedef union {
    struct {
        int fcorr_lte_out_real24                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag24                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB24;

typedef union {
    struct {
        int fcorr_lte_out_real25                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag25                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB25;

typedef union {
    struct {
        int fcorr_lte_out_real26                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag26                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB26;

typedef union {
    struct {
        int fcorr_lte_out_real27                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag27                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB27;

typedef union {
    struct {
        int fcorr_lte_out_real28                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag28                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB28;

typedef union {
    struct {
        int fcorr_lte_out_real29                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag29                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB29;

typedef union {
    struct {
        int fcorr_lte_out_real30                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag30                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB30;

typedef union {
    struct {
        int fcorr_lte_out_real31                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag31                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB31;

typedef union {
    struct {
        int fcorr_lte_out_real32                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag32                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB32;

typedef union {
    struct {
        int fcorr_lte_out_real33                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag33                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB33;

typedef union {
    struct {
        int fcorr_lte_out_real34                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag34                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB34;

typedef union {
    struct {
        int fcorr_lte_out_real35                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag35                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB35;

typedef union {
    struct {
        int fcorr_lte_out_real36                                      :   16              ;    /* 15:0 */
        int fcorr_lte_out_imag36                                      :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB36;

typedef union {
    struct {
        int reserved2_0                                               :   16              ;    /* 15:0 */
        int reserved1_1                                               :   16              ;    /* 31:16 */
    } bits;
    int u32;
} TFE_SID_TFE_FCORR_LTE_VM_SUB37;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_FCORR_LTE_VM_SUB0                                     om_data0;
    TFE_SID_TFE_FCORR_LTE_VM_SUB1                                     om_data1;
    TFE_SID_TFE_FCORR_LTE_VM_SUB2                                     om_data2;
    TFE_SID_TFE_FCORR_LTE_VM_SUB3                                     om_data3;
    TFE_SID_TFE_FCORR_LTE_VM_SUB4                                     om_data4;
    TFE_SID_TFE_FCORR_LTE_VM_SUB5                                     om_data5;
    TFE_SID_TFE_FCORR_LTE_VM_SUB6                                     om_data6;
    TFE_SID_TFE_FCORR_LTE_VM_SUB7                                     om_data7;
    TFE_SID_TFE_FCORR_LTE_VM_SUB8                                     om_data8;
    TFE_SID_TFE_FCORR_LTE_VM_SUB9                                     om_data9;
    TFE_SID_TFE_FCORR_LTE_VM_SUB10                                    om_data10;
    TFE_SID_TFE_FCORR_LTE_VM_SUB11                                    om_data11;
    TFE_SID_TFE_FCORR_LTE_VM_SUB12                                    om_data12;
    TFE_SID_TFE_FCORR_LTE_VM_SUB13                                    om_data13;
    TFE_SID_TFE_FCORR_LTE_VM_SUB14                                    om_data14;
    TFE_SID_TFE_FCORR_LTE_VM_SUB15                                    om_data15;
    TFE_SID_TFE_FCORR_LTE_VM_SUB16                                    om_data16;
    TFE_SID_TFE_FCORR_LTE_VM_SUB17                                    om_data17;
    TFE_SID_TFE_FCORR_LTE_VM_SUB18                                    om_data18;
    TFE_SID_TFE_FCORR_LTE_VM_SUB19                                    om_data19;
    TFE_SID_TFE_FCORR_LTE_VM_SUB20                                    om_data20;
    TFE_SID_TFE_FCORR_LTE_VM_SUB21                                    om_data21;
    TFE_SID_TFE_FCORR_LTE_VM_SUB22                                    om_data22;
    TFE_SID_TFE_FCORR_LTE_VM_SUB23                                    om_data23;
    TFE_SID_TFE_FCORR_LTE_VM_SUB24                                    om_data24;
    TFE_SID_TFE_FCORR_LTE_VM_SUB25                                    om_data25;
    TFE_SID_TFE_FCORR_LTE_VM_SUB26                                    om_data26;
    TFE_SID_TFE_FCORR_LTE_VM_SUB27                                    om_data27;
    TFE_SID_TFE_FCORR_LTE_VM_SUB28                                    om_data28;
    TFE_SID_TFE_FCORR_LTE_VM_SUB29                                    om_data29;
    TFE_SID_TFE_FCORR_LTE_VM_SUB30                                    om_data30;
    TFE_SID_TFE_FCORR_LTE_VM_SUB31                                    om_data31;
    TFE_SID_TFE_FCORR_LTE_VM_SUB32                                    om_data32;
    TFE_SID_TFE_FCORR_LTE_VM_SUB33                                    om_data33;
    TFE_SID_TFE_FCORR_LTE_VM_SUB34                                    om_data34;
    TFE_SID_TFE_FCORR_LTE_VM_SUB35                                    om_data35;
    TFE_SID_TFE_FCORR_LTE_VM_SUB36                                    om_data36;
    TFE_SID_TFE_FCORR_LTE_VM_SUB37                                    om_data37;
} TFE_SID_TFE_FCORR_LTE_VM;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_FCORR_LTE_VM_SUB0                                     om_data0;
    TFE_SID_TFE_FCORR_LTE_VM_SUB1                                     om_data1;
    TFE_SID_TFE_FCORR_LTE_VM_SUB2                                     om_data2;
    TFE_SID_TFE_FCORR_LTE_VM_SUB3                                     om_data3;
    TFE_SID_TFE_FCORR_LTE_VM_SUB4                                     om_data4;
    TFE_SID_TFE_FCORR_LTE_VM_SUB5                                     om_data5;
    TFE_SID_TFE_FCORR_LTE_VM_SUB6                                     om_data6;
    TFE_SID_TFE_FCORR_LTE_VM_SUB7                                     om_data7;
    TFE_SID_TFE_FCORR_LTE_VM_SUB8                                     om_data8;
    TFE_SID_TFE_FCORR_LTE_VM_SUB9                                     om_data9;
    TFE_SID_TFE_FCORR_LTE_VM_SUB10                                    om_data10;
    TFE_SID_TFE_FCORR_LTE_VM_SUB11                                    om_data11;
    TFE_SID_TFE_FCORR_LTE_VM_SUB12                                    om_data12;
    TFE_SID_TFE_FCORR_LTE_VM_SUB13                                    om_data13;
    TFE_SID_TFE_FCORR_LTE_VM_SUB14                                    om_data14;
    TFE_SID_TFE_FCORR_LTE_VM_SUB15                                    om_data15;
    TFE_SID_TFE_FCORR_LTE_VM_SUB16                                    om_data16;
    TFE_SID_TFE_FCORR_LTE_VM_SUB17                                    om_data17;
    TFE_SID_TFE_FCORR_LTE_VM_SUB18                                    om_data18;
    TFE_SID_TFE_FCORR_LTE_VM_SUB19                                    om_data19;
    TFE_SID_TFE_FCORR_LTE_VM_SUB20                                    om_data20;
    TFE_SID_TFE_FCORR_LTE_VM_SUB21                                    om_data21;
    TFE_SID_TFE_FCORR_LTE_VM_SUB22                                    om_data22;
    TFE_SID_TFE_FCORR_LTE_VM_SUB23                                    om_data23;
    TFE_SID_TFE_FCORR_LTE_VM_SUB24                                    om_data24;
    TFE_SID_TFE_FCORR_LTE_VM_SUB25                                    om_data25;
    TFE_SID_TFE_FCORR_LTE_VM_SUB26                                    om_data26;
    TFE_SID_TFE_FCORR_LTE_VM_SUB27                                    om_data27;
    TFE_SID_TFE_FCORR_LTE_VM_SUB28                                    om_data28;
    TFE_SID_TFE_FCORR_LTE_VM_SUB29                                    om_data29;
    TFE_SID_TFE_FCORR_LTE_VM_SUB30                                    om_data30;
    TFE_SID_TFE_FCORR_LTE_VM_SUB31                                    om_data31;
    TFE_SID_TFE_FCORR_LTE_VM_SUB32                                    om_data32;
    TFE_SID_TFE_FCORR_LTE_VM_SUB33                                    om_data33;
    TFE_SID_TFE_FCORR_LTE_VM_SUB34                                    om_data34;
    TFE_SID_TFE_FCORR_LTE_VM_SUB35                                    om_data35;
    TFE_SID_TFE_FCORR_LTE_VM_SUB36                                    om_data36;
    TFE_SID_TFE_FCORR_LTE_VM_SUB37                                    om_data37;
} TFE_SID_TFE_FCORR_LTE_VM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_FCORR_LTE_VM_SUB0                                     om_data0;
    TFE_SID_TFE_FCORR_LTE_VM_SUB1                                     om_data1;
    TFE_SID_TFE_FCORR_LTE_VM_SUB2                                     om_data2;
    TFE_SID_TFE_FCORR_LTE_VM_SUB3                                     om_data3;
    TFE_SID_TFE_FCORR_LTE_VM_SUB4                                     om_data4;
    TFE_SID_TFE_FCORR_LTE_VM_SUB5                                     om_data5;
    TFE_SID_TFE_FCORR_LTE_VM_SUB6                                     om_data6;
    TFE_SID_TFE_FCORR_LTE_VM_SUB7                                     om_data7;
    TFE_SID_TFE_FCORR_LTE_VM_SUB8                                     om_data8;
    TFE_SID_TFE_FCORR_LTE_VM_SUB9                                     om_data9;
    TFE_SID_TFE_FCORR_LTE_VM_SUB10                                    om_data10;
    TFE_SID_TFE_FCORR_LTE_VM_SUB11                                    om_data11;
    TFE_SID_TFE_FCORR_LTE_VM_SUB12                                    om_data12;
    TFE_SID_TFE_FCORR_LTE_VM_SUB13                                    om_data13;
    TFE_SID_TFE_FCORR_LTE_VM_SUB14                                    om_data14;
    TFE_SID_TFE_FCORR_LTE_VM_SUB15                                    om_data15;
    TFE_SID_TFE_FCORR_LTE_VM_SUB16                                    om_data16;
    TFE_SID_TFE_FCORR_LTE_VM_SUB17                                    om_data17;
    TFE_SID_TFE_FCORR_LTE_VM_SUB18                                    om_data18;
    TFE_SID_TFE_FCORR_LTE_VM_SUB19                                    om_data19;
    TFE_SID_TFE_FCORR_LTE_VM_SUB20                                    om_data20;
    TFE_SID_TFE_FCORR_LTE_VM_SUB21                                    om_data21;
    TFE_SID_TFE_FCORR_LTE_VM_SUB22                                    om_data22;
    TFE_SID_TFE_FCORR_LTE_VM_SUB23                                    om_data23;
    TFE_SID_TFE_FCORR_LTE_VM_SUB24                                    om_data24;
    TFE_SID_TFE_FCORR_LTE_VM_SUB25                                    om_data25;
    TFE_SID_TFE_FCORR_LTE_VM_SUB26                                    om_data26;
    TFE_SID_TFE_FCORR_LTE_VM_SUB27                                    om_data27;
    TFE_SID_TFE_FCORR_LTE_VM_SUB28                                    om_data28;
    TFE_SID_TFE_FCORR_LTE_VM_SUB29                                    om_data29;
    TFE_SID_TFE_FCORR_LTE_VM_SUB30                                    om_data30;
    TFE_SID_TFE_FCORR_LTE_VM_SUB31                                    om_data31;
    TFE_SID_TFE_FCORR_LTE_VM_SUB32                                    om_data32;
    TFE_SID_TFE_FCORR_LTE_VM_SUB33                                    om_data33;
    TFE_SID_TFE_FCORR_LTE_VM_SUB34                                    om_data34;
    TFE_SID_TFE_FCORR_LTE_VM_SUB35                                    om_data35;
    TFE_SID_TFE_FCORR_LTE_VM_SUB36                                    om_data36;
    TFE_SID_TFE_FCORR_LTE_VM_SUB37                                    om_data37;
} TFE_SID_TFE_FCORR_LTE_VM_BBP_MC;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real0                        :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag0                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB0;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real1                        :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag1                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB1;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real2                        :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag2                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB2;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real3                        :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag3                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB3;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real4                        :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag4                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB4;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real5                        :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag5                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB5;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real6                        :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag6                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB6;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real7                        :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag7                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB7;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real8                        :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag8                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB8;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real9                        :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag9                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB9;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real10                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag10                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB10;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real11                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag11                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB11;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real12                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag12                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB12;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real13                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag13                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB13;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real14                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag14                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB14;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real15                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag15                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB15;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real16                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag16                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB16;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real17                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag17                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB17;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real18                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag18                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB18;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real19                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag19                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB19;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real20                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag20                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB20;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real21                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag21                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB21;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real22                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag22                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB22;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real23                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag23                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB23;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real24                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag24                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB24;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real25                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag25                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB25;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real26                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag26                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB26;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real27                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag27                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB27;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real28                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag28                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB28;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real29                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag29                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB29;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real30                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag30                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB30;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real31                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag31                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB31;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real32                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag32                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB32;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real33                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag33                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB33;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real34                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag34                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB34;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real35                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag35                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB35;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real36                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag36                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB36;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real37                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag37                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB37;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real38                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag38                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB38;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real39                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag39                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB39;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real40                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag40                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB40;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real41                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag41                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB41;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real42                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag42                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB42;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real43                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag43                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB43;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real44                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag44                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB44;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real45                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag45                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB45;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real46                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag46                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB46;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real47                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag47                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB47;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real48                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag48                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB48;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real49                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag49                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB49;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real50                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag50                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB50;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real51                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag51                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB51;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real52                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag52                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB52;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real53                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag53                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB53;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real54                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag54                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB54;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real55                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag55                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB55;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real56                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag56                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB56;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real57                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag57                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB57;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real58                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag58                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB58;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real59                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag59                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB59;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real60                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag60                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB60;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real61                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag61                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB61;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real62                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag62                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB62;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real63                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag63                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB63;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real64                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag64                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB64;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real65                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag65                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB65;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real66                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag66                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB66;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real67                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag67                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB67;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real68                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag68                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB68;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real69                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag69                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB69;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real70                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag70                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB70;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real71                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag71                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB71;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real72                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag72                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB72;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real73                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag73                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB73;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real74                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag74                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB74;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real75                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag75                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB75;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real76                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag76                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB76;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real77                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag77                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB77;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real78                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag78                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB78;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real79                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag79                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB79;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real80                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag80                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB80;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real81                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag81                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB81;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real82                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag82                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB82;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real83                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag83                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB83;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real84                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag84                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB84;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real85                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag85                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB85;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real86                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag86                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB86;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real87                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag87                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB87;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real88                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag88                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB88;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real89                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag89                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB89;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real90                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag90                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB90;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real91                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag91                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB91;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real92                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag92                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB92;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real93                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag93                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB93;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real94                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag94                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB94;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_csi_real95                       :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_csi_imag95                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB95;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB0                               om_data0;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB1                               om_data1;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB2                               om_data2;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB3                               om_data3;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB4                               om_data4;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB5                               om_data5;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB6                               om_data6;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB7                               om_data7;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB8                               om_data8;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB9                               om_data9;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB10                              om_data10;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB11                              om_data11;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB12                              om_data12;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB13                              om_data13;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB14                              om_data14;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB15                              om_data15;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB16                              om_data16;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB17                              om_data17;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB18                              om_data18;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB19                              om_data19;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB20                              om_data20;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB21                              om_data21;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB22                              om_data22;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB23                              om_data23;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB24                              om_data24;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB25                              om_data25;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB26                              om_data26;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB27                              om_data27;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB28                              om_data28;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB29                              om_data29;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB30                              om_data30;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB31                              om_data31;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB32                              om_data32;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB33                              om_data33;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB34                              om_data34;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB35                              om_data35;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB36                              om_data36;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB37                              om_data37;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB38                              om_data38;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB39                              om_data39;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB40                              om_data40;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB41                              om_data41;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB42                              om_data42;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB43                              om_data43;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB44                              om_data44;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB45                              om_data45;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB46                              om_data46;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB47                              om_data47;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB48                              om_data48;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB49                              om_data49;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB50                              om_data50;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB51                              om_data51;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB52                              om_data52;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB53                              om_data53;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB54                              om_data54;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB55                              om_data55;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB56                              om_data56;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB57                              om_data57;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB58                              om_data58;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB59                              om_data59;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB60                              om_data60;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB61                              om_data61;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB62                              om_data62;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB63                              om_data63;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB64                              om_data64;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB65                              om_data65;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB66                              om_data66;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB67                              om_data67;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB68                              om_data68;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB69                              om_data69;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB70                              om_data70;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB71                              om_data71;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB72                              om_data72;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB73                              om_data73;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB74                              om_data74;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB75                              om_data75;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB76                              om_data76;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB77                              om_data77;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB78                              om_data78;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB79                              om_data79;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB80                              om_data80;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB81                              om_data81;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB82                              om_data82;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB83                              om_data83;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB84                              om_data84;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB85                              om_data85;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB86                              om_data86;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB87                              om_data87;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB88                              om_data88;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB89                              om_data89;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB90                              om_data90;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB91                              om_data91;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB92                              om_data92;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB93                              om_data93;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB94                              om_data94;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB95                              om_data95;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB0                               om_data0;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB1                               om_data1;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB2                               om_data2;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB3                               om_data3;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB4                               om_data4;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB5                               om_data5;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB6                               om_data6;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB7                               om_data7;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB8                               om_data8;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB9                               om_data9;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB10                              om_data10;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB11                              om_data11;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB12                              om_data12;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB13                              om_data13;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB14                              om_data14;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB15                              om_data15;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB16                              om_data16;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB17                              om_data17;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB18                              om_data18;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB19                              om_data19;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB20                              om_data20;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB21                              om_data21;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB22                              om_data22;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB23                              om_data23;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB24                              om_data24;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB25                              om_data25;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB26                              om_data26;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB27                              om_data27;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB28                              om_data28;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB29                              om_data29;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB30                              om_data30;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB31                              om_data31;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB32                              om_data32;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB33                              om_data33;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB34                              om_data34;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB35                              om_data35;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB36                              om_data36;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB37                              om_data37;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB38                              om_data38;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB39                              om_data39;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB40                              om_data40;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB41                              om_data41;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB42                              om_data42;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB43                              om_data43;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB44                              om_data44;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB45                              om_data45;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB46                              om_data46;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB47                              om_data47;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB48                              om_data48;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB49                              om_data49;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB50                              om_data50;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB51                              om_data51;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB52                              om_data52;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB53                              om_data53;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB54                              om_data54;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB55                              om_data55;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB56                              om_data56;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB57                              om_data57;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB58                              om_data58;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB59                              om_data59;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB60                              om_data60;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB61                              om_data61;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB62                              om_data62;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB63                              om_data63;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB64                              om_data64;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB65                              om_data65;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB66                              om_data66;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB67                              om_data67;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB68                              om_data68;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB69                              om_data69;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB70                              om_data70;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB71                              om_data71;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB72                              om_data72;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB73                              om_data73;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB74                              om_data74;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB75                              om_data75;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB76                              om_data76;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB77                              om_data77;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB78                              om_data78;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB79                              om_data79;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB80                              om_data80;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB81                              om_data81;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB82                              om_data82;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB83                              om_data83;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB84                              om_data84;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB85                              om_data85;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB86                              om_data86;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB87                              om_data87;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB88                              om_data88;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB89                              om_data89;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB90                              om_data90;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB91                              om_data91;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB92                              om_data92;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB93                              om_data93;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB94                              om_data94;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB95                              om_data95;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB0                               om_data0;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB1                               om_data1;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB2                               om_data2;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB3                               om_data3;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB4                               om_data4;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB5                               om_data5;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB6                               om_data6;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB7                               om_data7;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB8                               om_data8;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB9                               om_data9;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB10                              om_data10;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB11                              om_data11;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB12                              om_data12;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB13                              om_data13;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB14                              om_data14;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB15                              om_data15;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB16                              om_data16;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB17                              om_data17;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB18                              om_data18;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB19                              om_data19;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB20                              om_data20;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB21                              om_data21;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB22                              om_data22;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB23                              om_data23;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB24                              om_data24;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB25                              om_data25;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB26                              om_data26;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB27                              om_data27;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB28                              om_data28;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB29                              om_data29;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB30                              om_data30;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB31                              om_data31;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB32                              om_data32;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB33                              om_data33;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB34                              om_data34;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB35                              om_data35;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB36                              om_data36;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB37                              om_data37;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB38                              om_data38;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB39                              om_data39;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB40                              om_data40;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB41                              om_data41;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB42                              om_data42;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB43                              om_data43;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB44                              om_data44;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB45                              om_data45;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB46                              om_data46;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB47                              om_data47;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB48                              om_data48;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB49                              om_data49;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB50                              om_data50;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB51                              om_data51;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB52                              om_data52;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB53                              om_data53;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB54                              om_data54;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB55                              om_data55;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB56                              om_data56;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB57                              om_data57;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB58                              om_data58;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB59                              om_data59;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB60                              om_data60;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB61                              om_data61;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB62                              om_data62;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB63                              om_data63;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB64                              om_data64;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB65                              om_data65;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB66                              om_data66;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB67                              om_data67;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB68                              om_data68;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB69                              om_data69;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB70                              om_data70;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB71                              om_data71;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB72                              om_data72;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB73                              om_data73;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB74                              om_data74;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB75                              om_data75;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB76                              om_data76;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB77                              om_data77;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB78                              om_data78;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB79                              om_data79;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB80                              om_data80;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB81                              om_data81;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB82                              om_data82;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB83                              om_data83;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB84                              om_data84;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB85                              om_data85;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB86                              om_data86;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB87                              om_data87;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB88                              om_data88;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB89                              om_data89;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB90                              om_data90;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB91                              om_data91;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB92                              om_data92;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB93                              om_data93;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB94                              om_data94;
    TFE_SID_TFE_FCORR_NR_TO_CSI_VM_SUB95                              om_data95;
} TFE_SID_TFE_FCORR_NR_TO_CSI_VM_BBP_MC;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real0                    :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag0                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB0;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real1                    :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag1                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB1;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real2                    :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag2                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB2;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real3                    :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag3                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB3;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real4                    :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag4                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB4;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real5                    :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag5                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB5;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real6                    :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag6                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB6;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real7                    :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag7                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB7;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real8                    :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag8                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB8;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real9                    :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag9                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB9;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real10                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag10                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB10;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real11                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag11                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB11;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real12                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag12                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB12;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real13                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag13                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB13;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real14                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag14                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB14;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real15                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag15                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB15;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real16                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag16                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB16;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real17                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag17                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB17;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real18                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag18                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB18;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real19                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag19                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB19;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real20                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag20                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB20;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real21                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag21                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB21;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real22                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag22                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB22;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real23                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag23                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB23;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real24                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag24                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB24;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real25                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag25                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB25;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real26                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag26                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB26;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real27                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag27                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB27;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real28                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag28                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB28;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real29                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag29                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB29;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real30                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag30                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB30;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real31                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag31                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB31;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real32                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag32                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB32;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real33                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag33                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB33;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real34                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag34                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB34;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real35                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag35                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB35;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real36                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag36                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB36;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real37                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag37                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB37;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real38                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag38                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB38;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real39                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag39                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB39;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real40                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag40                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB40;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real41                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag41                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB41;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real42                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag42                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB42;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real43                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag43                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB43;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real44                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag44                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB44;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real45                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag45                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB45;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real46                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag46                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB46;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real47                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag47                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB47;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real48                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag48                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB48;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real49                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag49                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB49;

typedef union {
    struct {
        unsigned int fcorr_nr_out_to_non_csi_real50                   :   16              ;    /* 15:0 */
        unsigned int fcorr_nr_out_to_non_csi_imag50                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB50;

typedef union {
    struct {
        unsigned int reserved2_0                                      :   16              ;    /* 15:0 */
        unsigned int reserved1_1                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB51;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB0                           om_data0;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB1                           om_data1;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB2                           om_data2;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB3                           om_data3;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB4                           om_data4;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB5                           om_data5;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB6                           om_data6;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB7                           om_data7;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB8                           om_data8;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB9                           om_data9;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB10                          om_data10;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB11                          om_data11;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB12                          om_data12;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB13                          om_data13;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB14                          om_data14;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB15                          om_data15;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB16                          om_data16;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB17                          om_data17;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB18                          om_data18;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB19                          om_data19;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB20                          om_data20;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB21                          om_data21;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB22                          om_data22;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB23                          om_data23;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB24                          om_data24;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB25                          om_data25;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB26                          om_data26;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB27                          om_data27;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB28                          om_data28;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB29                          om_data29;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB30                          om_data30;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB31                          om_data31;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB32                          om_data32;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB33                          om_data33;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB34                          om_data34;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB35                          om_data35;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB36                          om_data36;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB37                          om_data37;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB38                          om_data38;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB39                          om_data39;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB40                          om_data40;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB41                          om_data41;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB42                          om_data42;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB43                          om_data43;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB44                          om_data44;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB45                          om_data45;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB46                          om_data46;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB47                          om_data47;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB48                          om_data48;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB49                          om_data49;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB50                          om_data50;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB51                          om_data51;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB0                           om_data0;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB1                           om_data1;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB2                           om_data2;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB3                           om_data3;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB4                           om_data4;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB5                           om_data5;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB6                           om_data6;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB7                           om_data7;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB8                           om_data8;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB9                           om_data9;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB10                          om_data10;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB11                          om_data11;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB12                          om_data12;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB13                          om_data13;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB14                          om_data14;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB15                          om_data15;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB16                          om_data16;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB17                          om_data17;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB18                          om_data18;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB19                          om_data19;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB20                          om_data20;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB21                          om_data21;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB22                          om_data22;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB23                          om_data23;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB24                          om_data24;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB25                          om_data25;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB26                          om_data26;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB27                          om_data27;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB28                          om_data28;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB29                          om_data29;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB30                          om_data30;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB31                          om_data31;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB32                          om_data32;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB33                          om_data33;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB34                          om_data34;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB35                          om_data35;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB36                          om_data36;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB37                          om_data37;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB38                          om_data38;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB39                          om_data39;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB40                          om_data40;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB41                          om_data41;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB42                          om_data42;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB43                          om_data43;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB44                          om_data44;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB45                          om_data45;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB46                          om_data46;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB47                          om_data47;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB48                          om_data48;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB49                          om_data49;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB50                          om_data50;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB51                          om_data51;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB0                           om_data0;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB1                           om_data1;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB2                           om_data2;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB3                           om_data3;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB4                           om_data4;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB5                           om_data5;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB6                           om_data6;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB7                           om_data7;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB8                           om_data8;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB9                           om_data9;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB10                          om_data10;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB11                          om_data11;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB12                          om_data12;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB13                          om_data13;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB14                          om_data14;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB15                          om_data15;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB16                          om_data16;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB17                          om_data17;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB18                          om_data18;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB19                          om_data19;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB20                          om_data20;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB21                          om_data21;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB22                          om_data22;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB23                          om_data23;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB24                          om_data24;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB25                          om_data25;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB26                          om_data26;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB27                          om_data27;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB28                          om_data28;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB29                          om_data29;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB30                          om_data30;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB31                          om_data31;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB32                          om_data32;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB33                          om_data33;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB34                          om_data34;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB35                          om_data35;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB36                          om_data36;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB37                          om_data37;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB38                          om_data38;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB39                          om_data39;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB40                          om_data40;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB41                          om_data41;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB42                          om_data42;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB43                          om_data43;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB44                          om_data44;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB45                          om_data45;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB46                          om_data46;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB47                          om_data47;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB48                          om_data48;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB49                          om_data49;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB50                          om_data50;
    TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_SUB51                          om_data51;
} TFE_SID_TFE_FCORR_NR_TO_NON_CSI_VM_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_tcorr_corr_validnum_r0t0;
    unsigned int                                                      tfe_tcorr_corr_validnum_r0t1;
    unsigned int                                                      tfe_tcorr_corr_validnum_r1t0;
    unsigned int                                                      tfe_tcorr_corr_validnum_r1t1;
    unsigned int                                                      psd_start_pre;
    unsigned int                                                      psd_start;
    unsigned int                                                      tcorr_tcoef_to_che_en;
    unsigned int                                                      tcorr_psd_to_che_en;
    unsigned int                                                      tfe_tcorr_except_skip_pow_result;
    unsigned int                                                      tfe_tcorr_except_skip_phase_result;
    unsigned int                                                      tfe_tcorr_dsds_bitmap;
    unsigned int                                                      tfe_tcorr_sfrm_con_flag;
} TFE_SID_TFE_TCORR_DM;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_tcorr_corr_validnum_r0t0;
    unsigned int                                                      tfe_tcorr_corr_validnum_r0t1;
    unsigned int                                                      tfe_tcorr_corr_validnum_r1t0;
    unsigned int                                                      tfe_tcorr_corr_validnum_r1t1;
    unsigned int                                                      psd_start_pre;
    unsigned int                                                      psd_start;
    unsigned int                                                      tcorr_tcoef_to_che_en;
    unsigned int                                                      tcorr_psd_to_che_en;
    unsigned int                                                      tfe_tcorr_except_skip_pow_result;
    unsigned int                                                      tfe_tcorr_except_skip_phase_result;
    unsigned int                                                      tfe_tcorr_dsds_bitmap;
    unsigned int                                                      tfe_tcorr_sfrm_con_flag;
} TFE_SID_TFE_TCORR_DM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_tcorr_corr_validnum_r0t0;
    unsigned int                                                      tfe_tcorr_corr_validnum_r0t1;
    unsigned int                                                      tfe_tcorr_corr_validnum_r1t0;
    unsigned int                                                      tfe_tcorr_corr_validnum_r1t1;
    unsigned int                                                      psd_start_pre;
    unsigned int                                                      psd_start;
    unsigned int                                                      tcorr_tcoef_to_che_en;
    unsigned int                                                      tcorr_psd_to_che_en;
    unsigned int                                                      tfe_tcorr_except_skip_pow_result;
    unsigned int                                                      tfe_tcorr_except_skip_phase_result;
    unsigned int                                                      tfe_tcorr_dsds_bitmap;
    unsigned int                                                      tfe_tcorr_sfrm_con_flag;
} TFE_SID_TFE_TCORR_DM_BBP_MC;

typedef union {
    struct {
        unsigned int tfe_tcorr_ifft_sft_bit_sub_0                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_ifft_sft_bit_sub_1                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB0;

typedef union {
    struct {
        unsigned int tfe_tcorr_ifft_sft_bit_sub_2                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_ifft_sft_bit_sub_3                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB1;

typedef union {
    struct {
        unsigned int tfe_tcorr_ifft_sft_bit_sub_4                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_ifft_sft_bit_sub_5                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB2;

typedef union {
    struct {
        unsigned int tfe_tcorr_ifft_sft_bit_sub_6                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_ifft_sft_bit_sub_7                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB3;

typedef union {
    struct {
        unsigned int tfe_tcorr_ifft_sft_bit_sub_8                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_ifft_sft_bit_sub_9                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB4;

typedef union {
    struct {
        unsigned int tfe_tcorr_ifft_sft_bit_sub_10                    :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_ifft_sft_bit_sub_11                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB5;

typedef union {
    struct {
        unsigned int tfe_tcorr_ifft_sft_bit_sub_12                    :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_ifft_sft_bit_sub_13                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB6;

typedef union {
    struct {
        unsigned int tfe_tcorr_ifft_sft_bit_sub_14                    :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_ifft_sft_bit_sub_15                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB7;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB0                           om_data0;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB1                           om_data1;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB2                           om_data2;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB3                           om_data3;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB4                           om_data4;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB5                           om_data5;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB6                           om_data6;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB7                           om_data7;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_0;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_1;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_2;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_3;
    unsigned int                                                      niose_pow_r0;
    unsigned int                                                      niose_pow_r1;
    unsigned int                                                      niose_pow_r2;
    unsigned int                                                      niose_pow_r3;
} TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB0                           om_data0;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB1                           om_data1;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB2                           om_data2;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB3                           om_data3;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB4                           om_data4;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB5                           om_data5;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB6                           om_data6;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB7                           om_data7;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_0;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_1;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_2;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_3;
    unsigned int                                                      niose_pow_r0;
    unsigned int                                                      niose_pow_r1;
    unsigned int                                                      niose_pow_r2;
    unsigned int                                                      niose_pow_r3;
} TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB0                           om_data0;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB1                           om_data1;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB2                           om_data2;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB3                           om_data3;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB4                           om_data4;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB5                           om_data5;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB6                           om_data6;
    TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_SUB7                           om_data7;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_0;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_1;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_2;
    unsigned int                                                      tfe_tcorr_agc_npw_sft_bit_3;
    unsigned int                                                      niose_pow_r0;
    unsigned int                                                      niose_pow_r1;
    unsigned int                                                      niose_pow_r2;
    unsigned int                                                      niose_pow_r3;
} TFE_SID_TFE_TCORR_IFFT_SFT_BIT_SUB_BBP_MC;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r0_real0                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r0_imag0                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB0;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r0_real1                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r0_imag1                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB1;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r0_real2                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r0_imag2                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB2;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r0_real3                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r0_imag3                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB3;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r0_real4                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r0_imag4                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB4;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r0_real5                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r0_imag5                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB5;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r0_real6                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r0_imag6                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB6;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r0_real7                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r0_imag7                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB7;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r1_real0                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r1_imag0                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB8;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r1_real1                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r1_imag1                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB9;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r1_real2                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r1_imag2                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB10;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r1_real3                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r1_imag3                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB11;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r1_real4                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r1_imag4                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB12;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r1_real5                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r1_imag5                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB13;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r1_real6                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r1_imag6                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB14;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r1_real7                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r1_imag7                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB15;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r2_real0                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r2_imag0                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB16;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r2_real1                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r2_imag1                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB17;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r2_real2                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r2_imag2                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB18;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r2_real3                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r2_imag3                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB19;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r2_real4                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r2_imag4                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB20;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r2_real5                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r2_imag5                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB21;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r2_real6                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r2_imag6                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB22;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r2_real7                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r2_imag7                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB23;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r3_real0                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r3_imag0                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB24;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r3_real1                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r3_imag1                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB25;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r3_real2                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r3_imag2                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB26;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r3_real3                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r3_imag3                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB27;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r3_real4                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r3_imag4                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB28;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r3_real5                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r3_imag5                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB29;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r3_real6                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r3_imag6                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB30;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_r3_real7                          :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_r3_imag7                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB31;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r0_data0                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r0_data1                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB32;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r0_data2                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r0_data3                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB33;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r0_data4                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r0_data5                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB34;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r0_data6                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r0_data7                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB35;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r1_data0                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r1_data1                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB36;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r1_data2                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r1_data3                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB37;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r1_data4                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r1_data5                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB38;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r1_data6                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r1_data7                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB39;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r2_data0                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r2_data1                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB40;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r2_data2                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r2_data3                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB41;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r2_data4                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r2_data5                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB42;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r2_data6                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r2_data7                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB43;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r3_data0                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r3_data1                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB44;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r3_data2                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r3_data3                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB45;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r3_data4                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r3_data5                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB46;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow1_r3_data6                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow1_r3_data7                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB47;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r0_data1                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r0_data0                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB48;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r0_data3                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r0_data2                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB49;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r0_data5                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r0_data4                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB50;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r0_data7                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r0_data6                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB51;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r1_data1                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r1_data0                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB52;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r1_data3                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r1_data2                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB53;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r1_data5                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r1_data4                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB54;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r1_data7                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r1_data6                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB55;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r2_data1                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r2_data0                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB56;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r2_data3                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r2_data2                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB57;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r2_data5                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r2_data4                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB58;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r2_data7                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r2_data6                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB59;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r3_data1                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r3_data0                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB60;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r3_data3                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r3_data2                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB61;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r3_data5                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r3_data4                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB62;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_pow2_r3_data7                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_pow2_r3_data6                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_POW12_SUB63;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB0                                 om_data0;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB1                                 om_data1;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB2                                 om_data2;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB3                                 om_data3;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB4                                 om_data4;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB5                                 om_data5;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB6                                 om_data6;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB7                                 om_data7;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB8                                 om_data8;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB9                                 om_data9;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB10                                om_data10;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB11                                om_data11;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB12                                om_data12;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB13                                om_data13;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB14                                om_data14;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB15                                om_data15;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB16                                om_data16;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB17                                om_data17;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB18                                om_data18;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB19                                om_data19;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB20                                om_data20;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB21                                om_data21;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB22                                om_data22;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB23                                om_data23;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB24                                om_data24;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB25                                om_data25;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB26                                om_data26;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB27                                om_data27;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB28                                om_data28;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB29                                om_data29;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB30                                om_data30;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB31                                om_data31;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB32                                om_data32;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB33                                om_data33;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB34                                om_data34;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB35                                om_data35;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB36                                om_data36;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB37                                om_data37;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB38                                om_data38;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB39                                om_data39;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB40                                om_data40;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB41                                om_data41;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB42                                om_data42;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB43                                om_data43;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB44                                om_data44;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB45                                om_data45;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB46                                om_data46;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB47                                om_data47;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB48                                om_data48;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB49                                om_data49;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB50                                om_data50;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB51                                om_data51;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB52                                om_data52;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB53                                om_data53;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB54                                om_data54;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB55                                om_data55;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB56                                om_data56;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB57                                om_data57;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB58                                om_data58;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB59                                om_data59;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB60                                om_data60;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB61                                om_data61;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB62                                om_data62;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB63                                om_data63;
} TFE_SID_TFE_TCORR_CORR_POW12;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB0                                 om_data0;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB1                                 om_data1;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB2                                 om_data2;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB3                                 om_data3;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB4                                 om_data4;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB5                                 om_data5;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB6                                 om_data6;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB7                                 om_data7;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB8                                 om_data8;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB9                                 om_data9;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB10                                om_data10;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB11                                om_data11;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB12                                om_data12;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB13                                om_data13;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB14                                om_data14;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB15                                om_data15;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB16                                om_data16;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB17                                om_data17;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB18                                om_data18;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB19                                om_data19;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB20                                om_data20;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB21                                om_data21;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB22                                om_data22;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB23                                om_data23;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB24                                om_data24;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB25                                om_data25;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB26                                om_data26;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB27                                om_data27;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB28                                om_data28;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB29                                om_data29;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB30                                om_data30;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB31                                om_data31;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB32                                om_data32;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB33                                om_data33;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB34                                om_data34;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB35                                om_data35;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB36                                om_data36;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB37                                om_data37;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB38                                om_data38;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB39                                om_data39;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB40                                om_data40;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB41                                om_data41;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB42                                om_data42;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB43                                om_data43;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB44                                om_data44;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB45                                om_data45;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB46                                om_data46;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB47                                om_data47;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB48                                om_data48;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB49                                om_data49;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB50                                om_data50;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB51                                om_data51;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB52                                om_data52;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB53                                om_data53;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB54                                om_data54;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB55                                om_data55;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB56                                om_data56;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB57                                om_data57;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB58                                om_data58;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB59                                om_data59;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB60                                om_data60;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB61                                om_data61;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB62                                om_data62;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB63                                om_data63;
} TFE_SID_TFE_TCORR_CORR_POW12_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB0                                 om_data0;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB1                                 om_data1;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB2                                 om_data2;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB3                                 om_data3;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB4                                 om_data4;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB5                                 om_data5;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB6                                 om_data6;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB7                                 om_data7;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB8                                 om_data8;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB9                                 om_data9;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB10                                om_data10;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB11                                om_data11;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB12                                om_data12;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB13                                om_data13;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB14                                om_data14;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB15                                om_data15;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB16                                om_data16;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB17                                om_data17;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB18                                om_data18;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB19                                om_data19;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB20                                om_data20;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB21                                om_data21;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB22                                om_data22;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB23                                om_data23;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB24                                om_data24;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB25                                om_data25;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB26                                om_data26;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB27                                om_data27;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB28                                om_data28;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB29                                om_data29;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB30                                om_data30;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB31                                om_data31;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB32                                om_data32;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB33                                om_data33;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB34                                om_data34;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB35                                om_data35;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB36                                om_data36;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB37                                om_data37;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB38                                om_data38;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB39                                om_data39;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB40                                om_data40;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB41                                om_data41;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB42                                om_data42;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB43                                om_data43;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB44                                om_data44;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB45                                om_data45;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB46                                om_data46;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB47                                om_data47;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB48                                om_data48;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB49                                om_data49;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB50                                om_data50;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB51                                om_data51;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB52                                om_data52;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB53                                om_data53;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB54                                om_data54;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB55                                om_data55;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB56                                om_data56;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB57                                om_data57;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB58                                om_data58;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB59                                om_data59;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB60                                om_data60;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB61                                om_data61;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB62                                om_data62;
    TFE_SID_TFE_TCORR_CORR_POW12_SUB63                                om_data63;
} TFE_SID_TFE_TCORR_CORR_POW12_BBP_MC;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real0                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag0                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB0;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real1                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag1                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB1;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real2                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag2                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB2;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real3                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag3                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB3;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real4                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag4                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB4;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real5                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag5                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB5;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real6                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag6                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB6;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real7                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag7                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB7;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real8                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag8                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB8;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real9                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag9                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB9;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real10                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag10                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB10;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real11                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag11                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB11;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real12                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag12                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB12;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real13                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag13                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB13;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real14                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag14                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB14;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r0_real15                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r0_imag15                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB15;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real0                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag0                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB16;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real1                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag1                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB17;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real2                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag2                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB18;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real3                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag3                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB19;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real4                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag4                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB20;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real5                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag5                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB21;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real6                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag6                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB22;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real7                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag7                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB23;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real8                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag8                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB24;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real9                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag9                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB25;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real10                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag10                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB26;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real11                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag11                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB27;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real12                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag12                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB28;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real13                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag13                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB29;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real14                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag14                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB30;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r1_real15                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r1_imag15                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB31;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real0                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag0                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB32;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real1                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag1                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB33;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real2                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag2                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB34;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real3                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag3                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB35;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real4                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag4                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB36;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real5                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag5                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB37;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real6                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag6                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB38;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real7                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag7                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB39;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real8                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag8                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB40;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real9                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag9                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB41;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real10                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag10                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB42;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real11                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag11                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB43;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real12                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag12                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB44;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real13                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag13                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB45;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real14                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag14                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB46;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r2_real15                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r2_imag15                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB47;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real0                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag0                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB48;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real1                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag1                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB49;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real2                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag2                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB50;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real3                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag3                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB51;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real4                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag4                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB52;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real5                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag5                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB53;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real6                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag6                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB54;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real7                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag7                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB55;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real8                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag8                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB56;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real9                       :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag9                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB57;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real10                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag10                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB58;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real11                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag11                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB59;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real12                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag12                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB60;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real13                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag13                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB61;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real14                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag14                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB62;

typedef union {
    struct {
        unsigned int tfe_tcorr_corr_ml_r3_real15                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_corr_ml_r3_imag15                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_CORR_ML_SUB63;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_TCORR_CORR_ML_SUB0                                    om_data0;
    TFE_SID_TFE_TCORR_CORR_ML_SUB1                                    om_data1;
    TFE_SID_TFE_TCORR_CORR_ML_SUB2                                    om_data2;
    TFE_SID_TFE_TCORR_CORR_ML_SUB3                                    om_data3;
    TFE_SID_TFE_TCORR_CORR_ML_SUB4                                    om_data4;
    TFE_SID_TFE_TCORR_CORR_ML_SUB5                                    om_data5;
    TFE_SID_TFE_TCORR_CORR_ML_SUB6                                    om_data6;
    TFE_SID_TFE_TCORR_CORR_ML_SUB7                                    om_data7;
    TFE_SID_TFE_TCORR_CORR_ML_SUB8                                    om_data8;
    TFE_SID_TFE_TCORR_CORR_ML_SUB9                                    om_data9;
    TFE_SID_TFE_TCORR_CORR_ML_SUB10                                   om_data10;
    TFE_SID_TFE_TCORR_CORR_ML_SUB11                                   om_data11;
    TFE_SID_TFE_TCORR_CORR_ML_SUB12                                   om_data12;
    TFE_SID_TFE_TCORR_CORR_ML_SUB13                                   om_data13;
    TFE_SID_TFE_TCORR_CORR_ML_SUB14                                   om_data14;
    TFE_SID_TFE_TCORR_CORR_ML_SUB15                                   om_data15;
    TFE_SID_TFE_TCORR_CORR_ML_SUB16                                   om_data16;
    TFE_SID_TFE_TCORR_CORR_ML_SUB17                                   om_data17;
    TFE_SID_TFE_TCORR_CORR_ML_SUB18                                   om_data18;
    TFE_SID_TFE_TCORR_CORR_ML_SUB19                                   om_data19;
    TFE_SID_TFE_TCORR_CORR_ML_SUB20                                   om_data20;
    TFE_SID_TFE_TCORR_CORR_ML_SUB21                                   om_data21;
    TFE_SID_TFE_TCORR_CORR_ML_SUB22                                   om_data22;
    TFE_SID_TFE_TCORR_CORR_ML_SUB23                                   om_data23;
    TFE_SID_TFE_TCORR_CORR_ML_SUB24                                   om_data24;
    TFE_SID_TFE_TCORR_CORR_ML_SUB25                                   om_data25;
    TFE_SID_TFE_TCORR_CORR_ML_SUB26                                   om_data26;
    TFE_SID_TFE_TCORR_CORR_ML_SUB27                                   om_data27;
    TFE_SID_TFE_TCORR_CORR_ML_SUB28                                   om_data28;
    TFE_SID_TFE_TCORR_CORR_ML_SUB29                                   om_data29;
    TFE_SID_TFE_TCORR_CORR_ML_SUB30                                   om_data30;
    TFE_SID_TFE_TCORR_CORR_ML_SUB31                                   om_data31;
    TFE_SID_TFE_TCORR_CORR_ML_SUB32                                   om_data32;
    TFE_SID_TFE_TCORR_CORR_ML_SUB33                                   om_data33;
    TFE_SID_TFE_TCORR_CORR_ML_SUB34                                   om_data34;
    TFE_SID_TFE_TCORR_CORR_ML_SUB35                                   om_data35;
    TFE_SID_TFE_TCORR_CORR_ML_SUB36                                   om_data36;
    TFE_SID_TFE_TCORR_CORR_ML_SUB37                                   om_data37;
    TFE_SID_TFE_TCORR_CORR_ML_SUB38                                   om_data38;
    TFE_SID_TFE_TCORR_CORR_ML_SUB39                                   om_data39;
    TFE_SID_TFE_TCORR_CORR_ML_SUB40                                   om_data40;
    TFE_SID_TFE_TCORR_CORR_ML_SUB41                                   om_data41;
    TFE_SID_TFE_TCORR_CORR_ML_SUB42                                   om_data42;
    TFE_SID_TFE_TCORR_CORR_ML_SUB43                                   om_data43;
    TFE_SID_TFE_TCORR_CORR_ML_SUB44                                   om_data44;
    TFE_SID_TFE_TCORR_CORR_ML_SUB45                                   om_data45;
    TFE_SID_TFE_TCORR_CORR_ML_SUB46                                   om_data46;
    TFE_SID_TFE_TCORR_CORR_ML_SUB47                                   om_data47;
    TFE_SID_TFE_TCORR_CORR_ML_SUB48                                   om_data48;
    TFE_SID_TFE_TCORR_CORR_ML_SUB49                                   om_data49;
    TFE_SID_TFE_TCORR_CORR_ML_SUB50                                   om_data50;
    TFE_SID_TFE_TCORR_CORR_ML_SUB51                                   om_data51;
    TFE_SID_TFE_TCORR_CORR_ML_SUB52                                   om_data52;
    TFE_SID_TFE_TCORR_CORR_ML_SUB53                                   om_data53;
    TFE_SID_TFE_TCORR_CORR_ML_SUB54                                   om_data54;
    TFE_SID_TFE_TCORR_CORR_ML_SUB55                                   om_data55;
    TFE_SID_TFE_TCORR_CORR_ML_SUB56                                   om_data56;
    TFE_SID_TFE_TCORR_CORR_ML_SUB57                                   om_data57;
    TFE_SID_TFE_TCORR_CORR_ML_SUB58                                   om_data58;
    TFE_SID_TFE_TCORR_CORR_ML_SUB59                                   om_data59;
    TFE_SID_TFE_TCORR_CORR_ML_SUB60                                   om_data60;
    TFE_SID_TFE_TCORR_CORR_ML_SUB61                                   om_data61;
    TFE_SID_TFE_TCORR_CORR_ML_SUB62                                   om_data62;
    TFE_SID_TFE_TCORR_CORR_ML_SUB63                                   om_data63;
} TFE_SID_TFE_TCORR_CORR_ML;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_TCORR_CORR_ML_SUB0                                    om_data0;
    TFE_SID_TFE_TCORR_CORR_ML_SUB1                                    om_data1;
    TFE_SID_TFE_TCORR_CORR_ML_SUB2                                    om_data2;
    TFE_SID_TFE_TCORR_CORR_ML_SUB3                                    om_data3;
    TFE_SID_TFE_TCORR_CORR_ML_SUB4                                    om_data4;
    TFE_SID_TFE_TCORR_CORR_ML_SUB5                                    om_data5;
    TFE_SID_TFE_TCORR_CORR_ML_SUB6                                    om_data6;
    TFE_SID_TFE_TCORR_CORR_ML_SUB7                                    om_data7;
    TFE_SID_TFE_TCORR_CORR_ML_SUB8                                    om_data8;
    TFE_SID_TFE_TCORR_CORR_ML_SUB9                                    om_data9;
    TFE_SID_TFE_TCORR_CORR_ML_SUB10                                   om_data10;
    TFE_SID_TFE_TCORR_CORR_ML_SUB11                                   om_data11;
    TFE_SID_TFE_TCORR_CORR_ML_SUB12                                   om_data12;
    TFE_SID_TFE_TCORR_CORR_ML_SUB13                                   om_data13;
    TFE_SID_TFE_TCORR_CORR_ML_SUB14                                   om_data14;
    TFE_SID_TFE_TCORR_CORR_ML_SUB15                                   om_data15;
    TFE_SID_TFE_TCORR_CORR_ML_SUB16                                   om_data16;
    TFE_SID_TFE_TCORR_CORR_ML_SUB17                                   om_data17;
    TFE_SID_TFE_TCORR_CORR_ML_SUB18                                   om_data18;
    TFE_SID_TFE_TCORR_CORR_ML_SUB19                                   om_data19;
    TFE_SID_TFE_TCORR_CORR_ML_SUB20                                   om_data20;
    TFE_SID_TFE_TCORR_CORR_ML_SUB21                                   om_data21;
    TFE_SID_TFE_TCORR_CORR_ML_SUB22                                   om_data22;
    TFE_SID_TFE_TCORR_CORR_ML_SUB23                                   om_data23;
    TFE_SID_TFE_TCORR_CORR_ML_SUB24                                   om_data24;
    TFE_SID_TFE_TCORR_CORR_ML_SUB25                                   om_data25;
    TFE_SID_TFE_TCORR_CORR_ML_SUB26                                   om_data26;
    TFE_SID_TFE_TCORR_CORR_ML_SUB27                                   om_data27;
    TFE_SID_TFE_TCORR_CORR_ML_SUB28                                   om_data28;
    TFE_SID_TFE_TCORR_CORR_ML_SUB29                                   om_data29;
    TFE_SID_TFE_TCORR_CORR_ML_SUB30                                   om_data30;
    TFE_SID_TFE_TCORR_CORR_ML_SUB31                                   om_data31;
    TFE_SID_TFE_TCORR_CORR_ML_SUB32                                   om_data32;
    TFE_SID_TFE_TCORR_CORR_ML_SUB33                                   om_data33;
    TFE_SID_TFE_TCORR_CORR_ML_SUB34                                   om_data34;
    TFE_SID_TFE_TCORR_CORR_ML_SUB35                                   om_data35;
    TFE_SID_TFE_TCORR_CORR_ML_SUB36                                   om_data36;
    TFE_SID_TFE_TCORR_CORR_ML_SUB37                                   om_data37;
    TFE_SID_TFE_TCORR_CORR_ML_SUB38                                   om_data38;
    TFE_SID_TFE_TCORR_CORR_ML_SUB39                                   om_data39;
    TFE_SID_TFE_TCORR_CORR_ML_SUB40                                   om_data40;
    TFE_SID_TFE_TCORR_CORR_ML_SUB41                                   om_data41;
    TFE_SID_TFE_TCORR_CORR_ML_SUB42                                   om_data42;
    TFE_SID_TFE_TCORR_CORR_ML_SUB43                                   om_data43;
    TFE_SID_TFE_TCORR_CORR_ML_SUB44                                   om_data44;
    TFE_SID_TFE_TCORR_CORR_ML_SUB45                                   om_data45;
    TFE_SID_TFE_TCORR_CORR_ML_SUB46                                   om_data46;
    TFE_SID_TFE_TCORR_CORR_ML_SUB47                                   om_data47;
    TFE_SID_TFE_TCORR_CORR_ML_SUB48                                   om_data48;
    TFE_SID_TFE_TCORR_CORR_ML_SUB49                                   om_data49;
    TFE_SID_TFE_TCORR_CORR_ML_SUB50                                   om_data50;
    TFE_SID_TFE_TCORR_CORR_ML_SUB51                                   om_data51;
    TFE_SID_TFE_TCORR_CORR_ML_SUB52                                   om_data52;
    TFE_SID_TFE_TCORR_CORR_ML_SUB53                                   om_data53;
    TFE_SID_TFE_TCORR_CORR_ML_SUB54                                   om_data54;
    TFE_SID_TFE_TCORR_CORR_ML_SUB55                                   om_data55;
    TFE_SID_TFE_TCORR_CORR_ML_SUB56                                   om_data56;
    TFE_SID_TFE_TCORR_CORR_ML_SUB57                                   om_data57;
    TFE_SID_TFE_TCORR_CORR_ML_SUB58                                   om_data58;
    TFE_SID_TFE_TCORR_CORR_ML_SUB59                                   om_data59;
    TFE_SID_TFE_TCORR_CORR_ML_SUB60                                   om_data60;
    TFE_SID_TFE_TCORR_CORR_ML_SUB61                                   om_data61;
    TFE_SID_TFE_TCORR_CORR_ML_SUB62                                   om_data62;
    TFE_SID_TFE_TCORR_CORR_ML_SUB63                                   om_data63;
} TFE_SID_TFE_TCORR_CORR_ML_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_TCORR_CORR_ML_SUB0                                    om_data0;
    TFE_SID_TFE_TCORR_CORR_ML_SUB1                                    om_data1;
    TFE_SID_TFE_TCORR_CORR_ML_SUB2                                    om_data2;
    TFE_SID_TFE_TCORR_CORR_ML_SUB3                                    om_data3;
    TFE_SID_TFE_TCORR_CORR_ML_SUB4                                    om_data4;
    TFE_SID_TFE_TCORR_CORR_ML_SUB5                                    om_data5;
    TFE_SID_TFE_TCORR_CORR_ML_SUB6                                    om_data6;
    TFE_SID_TFE_TCORR_CORR_ML_SUB7                                    om_data7;
    TFE_SID_TFE_TCORR_CORR_ML_SUB8                                    om_data8;
    TFE_SID_TFE_TCORR_CORR_ML_SUB9                                    om_data9;
    TFE_SID_TFE_TCORR_CORR_ML_SUB10                                   om_data10;
    TFE_SID_TFE_TCORR_CORR_ML_SUB11                                   om_data11;
    TFE_SID_TFE_TCORR_CORR_ML_SUB12                                   om_data12;
    TFE_SID_TFE_TCORR_CORR_ML_SUB13                                   om_data13;
    TFE_SID_TFE_TCORR_CORR_ML_SUB14                                   om_data14;
    TFE_SID_TFE_TCORR_CORR_ML_SUB15                                   om_data15;
    TFE_SID_TFE_TCORR_CORR_ML_SUB16                                   om_data16;
    TFE_SID_TFE_TCORR_CORR_ML_SUB17                                   om_data17;
    TFE_SID_TFE_TCORR_CORR_ML_SUB18                                   om_data18;
    TFE_SID_TFE_TCORR_CORR_ML_SUB19                                   om_data19;
    TFE_SID_TFE_TCORR_CORR_ML_SUB20                                   om_data20;
    TFE_SID_TFE_TCORR_CORR_ML_SUB21                                   om_data21;
    TFE_SID_TFE_TCORR_CORR_ML_SUB22                                   om_data22;
    TFE_SID_TFE_TCORR_CORR_ML_SUB23                                   om_data23;
    TFE_SID_TFE_TCORR_CORR_ML_SUB24                                   om_data24;
    TFE_SID_TFE_TCORR_CORR_ML_SUB25                                   om_data25;
    TFE_SID_TFE_TCORR_CORR_ML_SUB26                                   om_data26;
    TFE_SID_TFE_TCORR_CORR_ML_SUB27                                   om_data27;
    TFE_SID_TFE_TCORR_CORR_ML_SUB28                                   om_data28;
    TFE_SID_TFE_TCORR_CORR_ML_SUB29                                   om_data29;
    TFE_SID_TFE_TCORR_CORR_ML_SUB30                                   om_data30;
    TFE_SID_TFE_TCORR_CORR_ML_SUB31                                   om_data31;
    TFE_SID_TFE_TCORR_CORR_ML_SUB32                                   om_data32;
    TFE_SID_TFE_TCORR_CORR_ML_SUB33                                   om_data33;
    TFE_SID_TFE_TCORR_CORR_ML_SUB34                                   om_data34;
    TFE_SID_TFE_TCORR_CORR_ML_SUB35                                   om_data35;
    TFE_SID_TFE_TCORR_CORR_ML_SUB36                                   om_data36;
    TFE_SID_TFE_TCORR_CORR_ML_SUB37                                   om_data37;
    TFE_SID_TFE_TCORR_CORR_ML_SUB38                                   om_data38;
    TFE_SID_TFE_TCORR_CORR_ML_SUB39                                   om_data39;
    TFE_SID_TFE_TCORR_CORR_ML_SUB40                                   om_data40;
    TFE_SID_TFE_TCORR_CORR_ML_SUB41                                   om_data41;
    TFE_SID_TFE_TCORR_CORR_ML_SUB42                                   om_data42;
    TFE_SID_TFE_TCORR_CORR_ML_SUB43                                   om_data43;
    TFE_SID_TFE_TCORR_CORR_ML_SUB44                                   om_data44;
    TFE_SID_TFE_TCORR_CORR_ML_SUB45                                   om_data45;
    TFE_SID_TFE_TCORR_CORR_ML_SUB46                                   om_data46;
    TFE_SID_TFE_TCORR_CORR_ML_SUB47                                   om_data47;
    TFE_SID_TFE_TCORR_CORR_ML_SUB48                                   om_data48;
    TFE_SID_TFE_TCORR_CORR_ML_SUB49                                   om_data49;
    TFE_SID_TFE_TCORR_CORR_ML_SUB50                                   om_data50;
    TFE_SID_TFE_TCORR_CORR_ML_SUB51                                   om_data51;
    TFE_SID_TFE_TCORR_CORR_ML_SUB52                                   om_data52;
    TFE_SID_TFE_TCORR_CORR_ML_SUB53                                   om_data53;
    TFE_SID_TFE_TCORR_CORR_ML_SUB54                                   om_data54;
    TFE_SID_TFE_TCORR_CORR_ML_SUB55                                   om_data55;
    TFE_SID_TFE_TCORR_CORR_ML_SUB56                                   om_data56;
    TFE_SID_TFE_TCORR_CORR_ML_SUB57                                   om_data57;
    TFE_SID_TFE_TCORR_CORR_ML_SUB58                                   om_data58;
    TFE_SID_TFE_TCORR_CORR_ML_SUB59                                   om_data59;
    TFE_SID_TFE_TCORR_CORR_ML_SUB60                                   om_data60;
    TFE_SID_TFE_TCORR_CORR_ML_SUB61                                   om_data61;
    TFE_SID_TFE_TCORR_CORR_ML_SUB62                                   om_data62;
    TFE_SID_TFE_TCORR_CORR_ML_SUB63                                   om_data63;
} TFE_SID_TFE_TCORR_CORR_ML_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    int                                                               tfe_tcorr_q_curr_r0;
    int                                                               tfe_tcorr_q_curr_r1;
    int                                                               tfe_tcorr_q_curr_r2;
    int                                                               tfe_tcorr_q_curr_r3;
} TFE_SID_TFE_TCORR_Q_DIVNOS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_tcorr_q_curr_r0;
    unsigned int                                                      tfe_tcorr_q_curr_r1;
    unsigned int                                                      tfe_tcorr_q_curr_r2;
    unsigned int                                                      tfe_tcorr_q_curr_r3;
} TFE_SID_TFE_TCORR_Q_DIVNOS_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_tcorr_q_curr_r0;
    unsigned int                                                      tfe_tcorr_q_curr_r1;
    unsigned int                                                      tfe_tcorr_q_curr_r2;
    unsigned int                                                      tfe_tcorr_q_curr_r3;
} TFE_SID_TFE_TCORR_Q_DIVNOS_BBP_MC;

typedef union {
    struct {
        unsigned int tfe_tcorr_filter_coef_real0                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_filter_coef_imag0                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FILTER_COEF_SUB0;

typedef union {
    struct {
        unsigned int tfe_tcorr_filter_coef_real1                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_filter_coef_imag1                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FILTER_COEF_SUB1;

typedef union {
    struct {
        unsigned int tfe_tcorr_filter_coef_real2                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_filter_coef_imag2                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FILTER_COEF_SUB2;

typedef union {
    struct {
        unsigned int tfe_tcorr_filter_coef_real3                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_filter_coef_imag3                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FILTER_COEF_SUB3;

typedef union {
    struct {
        unsigned int tfe_tcorr_filter_coef_real4                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_filter_coef_imag4                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FILTER_COEF_SUB4;

typedef union {
    struct {
        unsigned int tfe_tcorr_filter_coef_real5                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_filter_coef_imag5                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FILTER_COEF_SUB5;

typedef union {
    struct {
        unsigned int tfe_tcorr_filter_coef_real6                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_filter_coef_imag6                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FILTER_COEF_SUB6;

typedef union {
    struct {
        unsigned int tfe_tcorr_filter_coef_real7                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_filter_coef_imag7                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FILTER_COEF_SUB7;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB0                                om_data0;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB1                                om_data1;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB2                                om_data2;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB3                                om_data3;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB4                                om_data4;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB5                                om_data5;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB6                                om_data6;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB7                                om_data7;
} TFE_SID_TFE_TCORR_FILTER_COEF;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB0                                om_data0;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB1                                om_data1;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB2                                om_data2;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB3                                om_data3;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB4                                om_data4;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB5                                om_data5;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB6                                om_data6;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB7                                om_data7;
} TFE_SID_TFE_TCORR_FILTER_COEF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB0                                om_data0;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB1                                om_data1;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB2                                om_data2;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB3                                om_data3;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB4                                om_data4;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB5                                om_data5;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB6                                om_data6;
    TFE_SID_TFE_TCORR_FILTER_COEF_SUB7                                om_data7;
} TFE_SID_TFE_TCORR_FILTER_COEF_BBP_MC;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real0                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag0                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB0;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real1                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag1                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB1;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real2                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag2                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB2;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real3                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag3                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB3;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real4                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag4                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB4;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real5                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag5                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB5;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real6                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag6                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB6;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real7                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag7                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB7;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real8                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag8                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB8;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real9                      :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag9                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB9;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real10                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag10                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB10;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real11                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag11                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB11;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real12                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag12                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB12;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real13                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag13                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB13;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real14                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag14                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB14;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real15                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag15                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB15;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real16                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag16                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB16;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real17                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag17                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB17;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real18                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag18                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB18;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real19                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag19                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB19;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real20                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag20                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB20;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real21                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag21                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB21;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real22                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag22                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB22;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real23                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag23                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB23;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real24                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag24                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB24;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real25                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag25                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB25;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real26                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag26                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB26;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real27                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag27                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB27;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_coef_real28                     :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_coef_imag28                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB28;

typedef union {
    struct {
        unsigned int tfe_tcorr_insert_reserved_real0_0                :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_insert_reserved_imag0_1                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_INSERT_COEF_SUB29;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB0                                om_data0;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB1                                om_data1;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB2                                om_data2;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB3                                om_data3;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB4                                om_data4;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB5                                om_data5;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB6                                om_data6;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB7                                om_data7;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB8                                om_data8;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB9                                om_data9;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB10                               om_data10;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB11                               om_data11;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB12                               om_data12;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB13                               om_data13;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB14                               om_data14;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB15                               om_data15;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB16                               om_data16;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB17                               om_data17;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB18                               om_data18;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB19                               om_data19;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB20                               om_data20;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB21                               om_data21;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB22                               om_data22;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB23                               om_data23;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB24                               om_data24;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB25                               om_data25;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB26                               om_data26;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB27                               om_data27;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB28                               om_data28;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB29                               om_data29;
} TFE_SID_TFE_TCORR_INSERT_COEF;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB0                                om_data0;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB1                                om_data1;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB2                                om_data2;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB3                                om_data3;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB4                                om_data4;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB5                                om_data5;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB6                                om_data6;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB7                                om_data7;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB8                                om_data8;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB9                                om_data9;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB10                               om_data10;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB11                               om_data11;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB12                               om_data12;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB13                               om_data13;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB14                               om_data14;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB15                               om_data15;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB16                               om_data16;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB17                               om_data17;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB18                               om_data18;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB19                               om_data19;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB20                               om_data20;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB21                               om_data21;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB22                               om_data22;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB23                               om_data23;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB24                               om_data24;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB25                               om_data25;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB26                               om_data26;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB27                               om_data27;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB28                               om_data28;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB29                               om_data29;
} TFE_SID_TFE_TCORR_INSERT_COEF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB0                                om_data0;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB1                                om_data1;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB2                                om_data2;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB3                                om_data3;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB4                                om_data4;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB5                                om_data5;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB6                                om_data6;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB7                                om_data7;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB8                                om_data8;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB9                                om_data9;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB10                               om_data10;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB11                               om_data11;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB12                               om_data12;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB13                               om_data13;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB14                               om_data14;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB15                               om_data15;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB16                               om_data16;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB17                               om_data17;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB18                               om_data18;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB19                               om_data19;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB20                               om_data20;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB21                               om_data21;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB22                               om_data22;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB23                               om_data23;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB24                               om_data24;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB25                               om_data25;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB26                               om_data26;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB27                               om_data27;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB28                               om_data28;
    TFE_SID_TFE_TCORR_INSERT_COEF_SUB29                               om_data29;
} TFE_SID_TFE_TCORR_INSERT_COEF_BBP_MC;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real0                         :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag0                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB0;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real1                         :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag1                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB1;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real2                         :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag2                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB2;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real3                         :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag3                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB3;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real4                         :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag4                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB4;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real5                         :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag5                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB5;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real6                         :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag6                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB6;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real7                         :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag7                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB7;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real8                         :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag8                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB8;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real9                         :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag9                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB9;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real10                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag10                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB10;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real11                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag11                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB11;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real12                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag12                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB12;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real13                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag13                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB13;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real14                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag14                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB14;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real15                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag15                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB15;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real16                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag16                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB16;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real17                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag17                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB17;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real18                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag18                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB18;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real19                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag19                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB19;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real20                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag20                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB20;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real21                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag21                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB21;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real22                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag22                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB22;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real23                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag23                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB23;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real24                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag24                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB24;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real25                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag25                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB25;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real26                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag26                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB26;

typedef union {
    struct {
        unsigned int tfe_tcorr_psd_coef_real27                        :   16              ;    /* 15:0 */
        unsigned int tfe_tcorr_psd_coef_imag27                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_PSD_COEF_SUB27;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB0                                   om_data0;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB1                                   om_data1;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB2                                   om_data2;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB3                                   om_data3;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB4                                   om_data4;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB5                                   om_data5;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB6                                   om_data6;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB7                                   om_data7;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB8                                   om_data8;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB9                                   om_data9;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB10                                  om_data10;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB11                                  om_data11;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB12                                  om_data12;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB13                                  om_data13;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB14                                  om_data14;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB15                                  om_data15;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB16                                  om_data16;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB17                                  om_data17;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB18                                  om_data18;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB19                                  om_data19;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB20                                  om_data20;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB21                                  om_data21;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB22                                  om_data22;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB23                                  om_data23;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB24                                  om_data24;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB25                                  om_data25;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB26                                  om_data26;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB27                                  om_data27;
} TFE_SID_TFE_TCORR_PSD_COEF;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB0                                   om_data0;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB1                                   om_data1;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB2                                   om_data2;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB3                                   om_data3;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB4                                   om_data4;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB5                                   om_data5;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB6                                   om_data6;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB7                                   om_data7;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB8                                   om_data8;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB9                                   om_data9;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB10                                  om_data10;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB11                                  om_data11;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB12                                  om_data12;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB13                                  om_data13;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB14                                  om_data14;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB15                                  om_data15;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB16                                  om_data16;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB17                                  om_data17;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB18                                  om_data18;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB19                                  om_data19;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB20                                  om_data20;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB21                                  om_data21;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB22                                  om_data22;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB23                                  om_data23;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB24                                  om_data24;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB25                                  om_data25;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB26                                  om_data26;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB27                                  om_data27;
} TFE_SID_TFE_TCORR_PSD_COEF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB0                                   om_data0;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB1                                   om_data1;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB2                                   om_data2;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB3                                   om_data3;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB4                                   om_data4;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB5                                   om_data5;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB6                                   om_data6;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB7                                   om_data7;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB8                                   om_data8;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB9                                   om_data9;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB10                                  om_data10;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB11                                  om_data11;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB12                                  om_data12;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB13                                  om_data13;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB14                                  om_data14;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB15                                  om_data15;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB16                                  om_data16;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB17                                  om_data17;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB18                                  om_data18;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB19                                  om_data19;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB20                                  om_data20;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB21                                  om_data21;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB22                                  om_data22;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB23                                  om_data23;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB24                                  om_data24;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB25                                  om_data25;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB26                                  om_data26;
    TFE_SID_TFE_TCORR_PSD_COEF_SUB27                                  om_data27;
} TFE_SID_TFE_TCORR_PSD_COEF_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_3;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_3;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_3;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_3;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r0;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r1;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r2;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r3;
} TFE_SID_TFE_TCORR_EXCEPTION_SKIP;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_3;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_3;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_3;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_3;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r0;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r1;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r2;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r3;
} TFE_SID_TFE_TCORR_EXCEPTION_SKIP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym0_3;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym1_3;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym2_3;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_0;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_1;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_2;
    unsigned int                                                      tfe_tcorr_except_skip_pow_sym3_3;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r0;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r1;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r2;
    unsigned int                                                      tfe_tcorr_except_skip_avg_pow_r3;
} TFE_SID_TFE_TCORR_EXCEPTION_SKIP_BBP_MC;

typedef union {
    struct {
        unsigned int k_slot_num                                       :   16              ;    /* 15:0 */
        unsigned int k_rs_type                                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_DM_SUB0;

typedef union {
    struct {
        unsigned int k_tx_num                                         :   16              ;    /* 15:0 */
        unsigned int k_rx_num                                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_DM_SUB1;

typedef union {
    struct {
        unsigned int k_rx_sel                                         :   16              ;    /* 15:0 */
        unsigned int k_ifft_idx                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_DM_SUB2;

typedef union {
    struct {
        unsigned int k_max_pos                                        :   16              ;    /* 15:0 */
        unsigned int k_sym_num                                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_DM_SUB3;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB0                                   om_data0;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB1                                   om_data1;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB2                                   om_data2;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB3                                   om_data3;
} TFE_SID_TFE_TCORR_FOR_K_DM;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB0                                   om_data0;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB1                                   om_data1;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB2                                   om_data2;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB3                                   om_data3;
} TFE_SID_TFE_TCORR_FOR_K_DM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB0                                   om_data0;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB1                                   om_data1;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB2                                   om_data2;
    TFE_SID_TFE_TCORR_FOR_K_DM_SUB3                                   om_data3;
} TFE_SID_TFE_TCORR_FOR_K_DM_BBP_MC;

typedef union {
    struct {
        unsigned int for_k_max_cir_real0                              :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag0                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB0;

typedef union {
    struct {
        unsigned int for_k_max_cir_real1                              :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag1                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB1;

typedef union {
    struct {
        unsigned int for_k_max_cir_real2                              :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag2                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB2;

typedef union {
    struct {
        unsigned int for_k_max_cir_real3                              :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag3                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB3;

typedef union {
    struct {
        unsigned int for_k_max_cir_real4                              :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag4                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB4;

typedef union {
    struct {
        unsigned int for_k_max_cir_real5                              :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag5                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB5;

typedef union {
    struct {
        unsigned int for_k_max_cir_real6                              :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag6                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB6;

typedef union {
    struct {
        unsigned int for_k_max_cir_real7                              :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag7                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB7;

typedef union {
    struct {
        unsigned int for_k_max_cir_real8                              :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag8                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB8;

typedef union {
    struct {
        unsigned int for_k_max_cir_real9                              :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag9                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB9;

typedef union {
    struct {
        unsigned int for_k_max_cir_real10                             :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag10                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB10;

typedef union {
    struct {
        unsigned int for_k_max_cir_real11                             :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag11                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB11;

typedef union {
    struct {
        unsigned int for_k_max_cir_real12                             :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag12                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB12;

typedef union {
    struct {
        unsigned int for_k_max_cir_real13                             :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag13                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB13;

typedef union {
    struct {
        unsigned int for_k_max_cir_real14                             :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag14                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB14;

typedef union {
    struct {
        unsigned int for_k_max_cir_real15                             :   16              ;    /* 15:0 */
        unsigned int for_k_max_cir_imag15                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB15;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB0                           om_data0;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB1                           om_data1;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB2                           om_data2;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB3                           om_data3;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB4                           om_data4;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB5                           om_data5;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB6                           om_data6;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB7                           om_data7;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB8                           om_data8;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB9                           om_data9;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB10                          om_data10;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB11                          om_data11;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB12                          om_data12;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB13                          om_data13;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB14                          om_data14;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB15                          om_data15;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB0                           om_data0;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB1                           om_data1;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB2                           om_data2;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB3                           om_data3;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB4                           om_data4;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB5                           om_data5;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB6                           om_data6;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB7                           om_data7;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB8                           om_data8;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB9                           om_data9;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB10                          om_data10;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB11                          om_data11;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB12                          om_data12;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB13                          om_data13;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB14                          om_data14;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB15                          om_data15;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB0                           om_data0;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB1                           om_data1;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB2                           om_data2;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB3                           om_data3;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB4                           om_data4;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB5                           om_data5;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB6                           om_data6;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB7                           om_data7;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB8                           om_data8;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB9                           om_data9;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB10                          om_data10;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB11                          om_data11;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB12                          om_data12;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB13                          om_data13;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB14                          om_data14;
    TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_SUB15                          om_data15;
} TFE_SID_TFE_TCORR_FOR_K_SEL_CIR_VM_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
