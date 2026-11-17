

#ifndef __UPHY_PDE_BCL_OM_H__
#define __UPHY_PDE_BCL_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef union {
    struct {
        unsigned int cfc_en                                           :   1               ;    /* 0 */
        unsigned int cfc_cs0_en                                       :   1               ;    /* 1 */
        unsigned int cfc_cs1_en                                       :   1               ;    /* 2 */
        unsigned int cfc_cs2_en                                       :   1               ;    /* 3 */
        unsigned int cfg_idx                                          :   3               ;    /* 6:4 */
        unsigned int pei_en                                           :   1               ;    /* 7 */
        unsigned int reserved_0                                       :   16              ;    /* 23:8 */
        unsigned int cfg_idx_mst                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_CFC_INIT_S_SUB0;

typedef union {
    struct {
        unsigned int cs0_choke                                        :   1               ;    /* 0 */
        unsigned int cs1_choke                                        :   1               ;    /* 1 */
        unsigned int cs2_choke                                        :   1               ;    /* 2 */
        unsigned int reserved_0                                       :   29              ;    /* 31:3 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_CFC_INIT_S_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NPDC_CFC_INIT_S_SUB0                                  om_data0;
    BCL_SID_BCL_NPDC_CFC_INIT_S_SUB1                                  om_data1;
} BCL_SID_BCL_NPDC_CFC_INIT_S;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NPDC_CFC_INIT_S_SUB0                                  om_data0;
    BCL_SID_BCL_NPDC_CFC_INIT_S_SUB1                                  om_data1;
} BCL_SID_BCL_NPDC_CFC_INIT_S_BBP_MC;

typedef union {
    struct {
        unsigned int cc_idx                                           :   4               ;    /* 3:0 */
        unsigned int slot_dif_1st_flag                                :   1               ;    /* 4 */
        unsigned int reserved_0                                       :   3               ;    /* 7:5 */
        unsigned int cfg_idx                                          :   3               ;    /* 10:8 */
        unsigned int cfg_even_odd_flag                                :   1               ;    /* 11 */
        unsigned int reserved_1                                       :   4               ;    /* 15:12 */
        unsigned int cs0_coef_en                                      :   1               ;    /* 16 */
        unsigned int cs0_coef_pp                                      :   1               ;    /* 17 */
        unsigned int cs0_coef_upd                                     :   1               ;    /* 18 */
        unsigned int reserved_2                                       :   1               ;    /* 19 */
        unsigned int cs1_coef_en                                      :   1               ;    /* 20 */
        unsigned int cs1_coef_pp                                      :   1               ;    /* 21 */
        unsigned int cs1_coef_upd                                     :   1               ;    /* 22 */
        unsigned int reserved_3                                       :   1               ;    /* 23 */
        unsigned int cs2_coef_en                                      :   1               ;    /* 24 */
        unsigned int cs2_coef_pp                                      :   1               ;    /* 25 */
        unsigned int cs2_coef_upd                                     :   1               ;    /* 26 */
        unsigned int reserved_4                                       :   4               ;    /* 30:27 */
        unsigned int slot_para_pp                                     :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_CHE_SS_S_SUB0;

typedef union {
    struct {
        unsigned int task_num_total                                   :   8               ;    /* 7:0 */
        unsigned int task_num_cnt                                     :   8               ;    /* 15:8 */
        unsigned int cfg_idx_mst                                      :   8               ;    /* 23:16 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_CHE_SS_S_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NPDC_CHE_SS_S_SUB0                                    om_data0;
    BCL_SID_BCL_NPDC_CHE_SS_S_SUB1                                    om_data1;
} BCL_SID_BCL_NPDC_CHE_SS_S;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NPDC_CHE_SS_S_SUB0                                    om_data0;
    BCL_SID_BCL_NPDC_CHE_SS_S_SUB1                                    om_data1;
} BCL_SID_BCL_NPDC_CHE_SS_S_BBP_MC;

typedef union {
    struct {
        unsigned int cc_idx                                           :   4               ;    /* 3:0 */
        unsigned int slot_dif_1st_flag                                :   1               ;    /* 4 */
        unsigned int reserved_0                                       :   3               ;    /* 7:5 */
        unsigned int cfg_idx                                          :   3               ;    /* 10:8 */
        unsigned int cfg_odd_even                                     :   1               ;    /* 11 */
        unsigned int reserved_1                                       :   19              ;    /* 30:12 */
        unsigned int npdc_init_pp_flag                                :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DIF_INFO_S_SUB0;

typedef union {
    struct {
        unsigned int cs0_sym0_rx0_vld                                 :   1               ;    /* 0 */
        unsigned int cs0_sym0_rx1_vld                                 :   1               ;    /* 1 */
        unsigned int cs0_sym0_rx2_vld                                 :   1               ;    /* 2 */
        unsigned int cs0_sym0_rx3_vld                                 :   1               ;    /* 3 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int cs0_sym1_rx0_vld                                 :   1               ;    /* 8 */
        unsigned int cs0_sym1_rx1_vld                                 :   1               ;    /* 9 */
        unsigned int cs0_sym1_rx2_vld                                 :   1               ;    /* 10 */
        unsigned int cs0_sym1_rx3_vld                                 :   1               ;    /* 11 */
        unsigned int reserved_1                                       :   4               ;    /* 15:12 */
        unsigned int cs0_sym2_rx0_vld                                 :   1               ;    /* 16 */
        unsigned int cs0_sym2_rx1_vld                                 :   1               ;    /* 17 */
        unsigned int cs0_sym2_rx2_vld                                 :   1               ;    /* 18 */
        unsigned int cs0_sym2_rx3_vld                                 :   1               ;    /* 19 */
        unsigned int reserved_2                                       :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DIF_INFO_S_SUB22;

typedef union {
    struct {
        unsigned int cs1_sym0_rx0_vld                                 :   1               ;    /* 0 */
        unsigned int cs1_sym0_rx1_vld                                 :   1               ;    /* 1 */
        unsigned int cs1_sym0_rx2_vld                                 :   1               ;    /* 2 */
        unsigned int cs1_sym0_rx3_vld                                 :   1               ;    /* 3 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int cs1_sym1_rx0_vld                                 :   1               ;    /* 8 */
        unsigned int cs1_sym1_rx1_vld                                 :   1               ;    /* 9 */
        unsigned int cs1_sym1_rx2_vld                                 :   1               ;    /* 10 */
        unsigned int cs1_sym1_rx3_vld                                 :   1               ;    /* 11 */
        unsigned int reserved_1                                       :   4               ;    /* 15:12 */
        unsigned int cs1_sym2_rx0_vld                                 :   1               ;    /* 16 */
        unsigned int cs1_sym2_rx1_vld                                 :   1               ;    /* 17 */
        unsigned int cs1_sym2_rx2_vld                                 :   1               ;    /* 18 */
        unsigned int cs1_sym2_rx3_vld                                 :   1               ;    /* 19 */
        unsigned int reserved_2                                       :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DIF_INFO_S_SUB30;

typedef union {
    struct {
        unsigned int cs2_sym0_rx0_vld                                 :   1               ;    /* 0 */
        unsigned int cs2_sym0_rx1_vld                                 :   1               ;    /* 1 */
        unsigned int cs2_sym0_rx2_vld                                 :   1               ;    /* 2 */
        unsigned int cs2_sym0_rx3_vld                                 :   1               ;    /* 3 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int cs2_sym1_rx0_vld                                 :   1               ;    /* 8 */
        unsigned int cs2_sym1_rx1_vld                                 :   1               ;    /* 9 */
        unsigned int cs2_sym1_rx2_vld                                 :   1               ;    /* 10 */
        unsigned int cs2_sym1_rx3_vld                                 :   1               ;    /* 11 */
        unsigned int reserved_1                                       :   4               ;    /* 15:12 */
        unsigned int cs2_sym2_rx0_vld                                 :   1               ;    /* 16 */
        unsigned int cs2_sym2_rx1_vld                                 :   1               ;    /* 17 */
        unsigned int cs2_sym2_rx2_vld                                 :   1               ;    /* 18 */
        unsigned int cs2_sym2_rx3_vld                                 :   1               ;    /* 19 */
        unsigned int reserved_2                                       :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DIF_INFO_S_SUB38;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NPDC_DIF_INFO_S_SUB0                                  om_data0;
    unsigned int                                                      cfg_idx_mst;
    unsigned int                                                      agc_info0;
    unsigned int                                                      agc_info1;
    unsigned int                                                      cs0_sym_pwr_max0;
    unsigned int                                                      cs0_sym_pwr_max1;
    unsigned int                                                      cs0_sym_pwr_max2;
    unsigned int                                                      cs0_sym_pwr_max3;
    unsigned int                                                      cs1_sym_pwr_max0;
    unsigned int                                                      cs1_sym_pwr_max1;
    unsigned int                                                      cs1_sym_pwr_max2;
    unsigned int                                                      cs1_sym_pwr_max3;
    unsigned int                                                      cs2_sym_pwr_max0;
    unsigned int                                                      cs2_sym_pwr_max1;
    unsigned int                                                      cs2_sym_pwr_max2;
    unsigned int                                                      cs2_sym_pwr_max3;
    unsigned int                                                      cs0_sym0_x1_2_0;
    unsigned int                                                      cs0_sym0_x1_2_1;
    unsigned int                                                      cs0_sym1_x1_2_0;
    unsigned int                                                      cs0_sym1_x1_2_1;
    unsigned int                                                      cs0_sym2_x1_2_0;
    unsigned int                                                      cs0_sym2_x1_2_1;
    BCL_SID_BCL_NPDC_DIF_INFO_S_SUB22                                 om_data22;
    unsigned int                                                      reserved_0;
    unsigned int                                                      cs1_sym0_x1_2_0;
    unsigned int                                                      cs1_sym0_x1_2_1;
    unsigned int                                                      cs1_sym1_x1_2_0;
    unsigned int                                                      cs1_sym1_x1_2_1;
    unsigned int                                                      cs1_sym2_x1_2_0;
    unsigned int                                                      cs1_sym2_x1_2_1;
    BCL_SID_BCL_NPDC_DIF_INFO_S_SUB30                                 om_data30;
    unsigned int                                                      reserved_1;
    unsigned int                                                      cs2_sym0_x1_2_0;
    unsigned int                                                      cs2_sym0_x1_2_1;
    unsigned int                                                      cs2_sym1_x1_2_0;
    unsigned int                                                      cs2_sym1_x1_2_1;
    unsigned int                                                      cs2_sym2_x1_2_0;
    unsigned int                                                      cs2_sym2_x1_2_1;
    BCL_SID_BCL_NPDC_DIF_INFO_S_SUB38                                 om_data38;
    unsigned int                                                      reserved_2;
} BCL_SID_BCL_NPDC_DIF_INFO_S;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NPDC_DIF_INFO_S_SUB0                                  om_data0;
    unsigned int                                                      cfg_idx_mst;
    unsigned int                                                      agc_info0;
    unsigned int                                                      agc_info1;
    unsigned int                                                      cs0_sym_pwr_max0;
    unsigned int                                                      cs0_sym_pwr_max1;
    unsigned int                                                      cs0_sym_pwr_max2;
    unsigned int                                                      cs0_sym_pwr_max3;
    unsigned int                                                      cs1_sym_pwr_max0;
    unsigned int                                                      cs1_sym_pwr_max1;
    unsigned int                                                      cs1_sym_pwr_max2;
    unsigned int                                                      cs1_sym_pwr_max3;
    unsigned int                                                      cs2_sym_pwr_max0;
    unsigned int                                                      cs2_sym_pwr_max1;
    unsigned int                                                      cs2_sym_pwr_max2;
    unsigned int                                                      cs2_sym_pwr_max3;
    unsigned int                                                      cs0_sym0_x1_2_0;
    unsigned int                                                      cs0_sym0_x1_2_1;
    unsigned int                                                      cs0_sym1_x1_2_0;
    unsigned int                                                      cs0_sym1_x1_2_1;
    unsigned int                                                      cs0_sym2_x1_2_0;
    unsigned int                                                      cs0_sym2_x1_2_1;
    BCL_SID_BCL_NPDC_DIF_INFO_S_SUB22                                 om_data22;
    unsigned int                                                      reserved_0;
    unsigned int                                                      cs1_sym0_x1_2_0;
    unsigned int                                                      cs1_sym0_x1_2_1;
    unsigned int                                                      cs1_sym1_x1_2_0;
    unsigned int                                                      cs1_sym1_x1_2_1;
    unsigned int                                                      cs1_sym2_x1_2_0;
    unsigned int                                                      cs1_sym2_x1_2_1;
    BCL_SID_BCL_NPDC_DIF_INFO_S_SUB30                                 om_data30;
    unsigned int                                                      reserved_1;
    unsigned int                                                      cs2_sym0_x1_2_0;
    unsigned int                                                      cs2_sym0_x1_2_1;
    unsigned int                                                      cs2_sym1_x1_2_0;
    unsigned int                                                      cs2_sym1_x1_2_1;
    unsigned int                                                      cs2_sym2_x1_2_0;
    unsigned int                                                      cs2_sym2_x1_2_1;
    BCL_SID_BCL_NPDC_DIF_INFO_S_SUB38                                 om_data38;
    unsigned int                                                      reserved_2;
} BCL_SID_BCL_NPDC_DIF_INFO_S_BBP_MC;

typedef union {
    struct {
        unsigned int dif_int_en                                       :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   4               ;    /* 4:1 */
        unsigned int cfg_slot_idx                                     :   9               ;    /* 13:5 */
        unsigned int reserved_1                                       :   18              ;    /* 31:14 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DIF_CMD_S_SUB0;

typedef union {
    struct {
        unsigned int cfg_idx_mst                                      :   8               ;    /* 7:0 */
        unsigned int end_sym_idx                                      :   8               ;    /* 15:8 */
        unsigned int last_end_sym                                     :   8               ;    /* 23:16 */
        unsigned int cs_num                                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DIF_CMD_S_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NPDC_DIF_CMD_S_SUB0                                   om_data0;
    BCL_SID_BCL_NPDC_DIF_CMD_S_SUB1                                   om_data1;
} BCL_SID_BCL_NPDC_DIF_CMD_S;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NPDC_DIF_CMD_S_SUB0                                   om_data0;
    BCL_SID_BCL_NPDC_DIF_CMD_S_SUB1                                   om_data1;
} BCL_SID_BCL_NPDC_DIF_CMD_S_BBP_MC;

typedef union {
    struct {
        unsigned int reserved_0                                       :   16              ;    /* 15:0 */
        unsigned int cfc_en                                           :   1               ;    /* 16 */
        unsigned int cfc_cs0_en                                       :   1               ;    /* 17 */
        unsigned int cfc_cs1_en                                       :   1               ;    /* 18 */
        unsigned int cfc_cs2_en                                       :   1               ;    /* 19 */
        unsigned int cfg_idx                                          :   3               ;    /* 22:20 */
        unsigned int pei_en                                           :   1               ;    /* 23 */
        unsigned int reserved_1                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_CFC_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NPDC_CFC_SUB0                                         om_data0;
    unsigned int                                                      cfc_inv_dims;
} BCL_SID_BCL_NPDC_CFC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NPDC_CFC_SUB0                                         om_data0;
    unsigned int                                                      cfc_inv_dims;
} BCL_SID_BCL_NPDC_CFC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      task_num_cnt;
    unsigned int                                                      task_num_total;
} BCL_SID_BCL_NPDC_DIF_BUF_RELEASE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      task_num_cnt;
    unsigned int                                                      task_num_total;
} BCL_SID_BCL_NPDC_DIF_BUF_RELEASE_BBP_MC;

typedef union {
    struct {
        unsigned int nrch_idx                                         :   4               ;    /* 3:0 */
        unsigned int rpt_pde_idx                                      :   1               ;    /* 4 */
        unsigned int rpt_pde_cfg_idx                                  :   3               ;    /* 7:5 */
        unsigned int reserved_0                                       :   7               ;    /* 14:8 */
        unsigned int dci_rpt_en                                       :   1               ;    /* 15 */
        unsigned int slot_pq_flag                                     :   1               ;    /* 16 */
        unsigned int reserved_1                                       :   4               ;    /* 20:17 */
        unsigned int cmd_invld                                        :   1               ;    /* 21 */
        unsigned int span_flag                                        :   1               ;    /* 22 */
        unsigned int reserved_2                                       :   9               ;    /* 31:23 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DET_CMD_SUB0;

typedef union {
    struct {
        unsigned int slot_first_rpt                                   :   1               ;    /* 0 */
        unsigned int slot_end_rpt                                     :   1               ;    /* 1 */
        unsigned int span_first_rpt                                   :   1               ;    /* 2 */
        unsigned int area0_last_rpt                                   :   1               ;    /* 3 */
        unsigned int cfg_rf_off                                       :   1               ;    /* 4 */
        unsigned int cs0_no_dci                                       :   1               ;    /* 5 */
        unsigned int cs1_no_dci                                       :   1               ;    /* 6 */
        unsigned int cs2_no_dci                                       :   1               ;    /* 7 */
        unsigned int int_symb_idx                                     :   4               ;    /* 11:8 */
        unsigned int reserved_0                                       :   15              ;    /* 26:12 */
        unsigned int pde_idx                                          :   1               ;    /* 27 */
        unsigned int curr_cfg_idx                                     :   3               ;    /* 30:28 */
        unsigned int scheduled_flag                                   :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DET_CMD_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NPDC_DET_CMD_SUB0                                     om_data0;
    BCL_SID_BCL_NPDC_DET_CMD_SUB1                                     om_data1;
} BCL_SID_BCL_NPDC_DET_CMD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NPDC_DET_CMD_SUB0                                     om_data0;
    BCL_SID_BCL_NPDC_DET_CMD_SUB1                                     om_data1;
} BCL_SID_BCL_NPDC_DET_CMD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_bba_addr;
    unsigned int                                                      bba_bypass_cfg;
    unsigned int                                                      cfg_cfu_addr;
    unsigned int                                                      cfu_bypass_cfg;
} BCL_SID_BCL_NPDC_CFG_RF_OFF;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_bba_addr;
    unsigned int                                                      bba_bypass_cfg;
    unsigned int                                                      cfg_cfu_addr;
    unsigned int                                                      cfu_bypass_cfg;
} BCL_SID_BCL_NPDC_CFG_RF_OFF_BBP_MC;

typedef union {
    struct {
        unsigned int reserved_0                                       :   1               ;    /* 0 */
        unsigned int pdc_rx_num                                       :   4               ;    /* 4:1 */
        unsigned int reserved_1                                       :   8               ;    /* 12:5 */
        unsigned int pdc_slot_idx                                     :   9               ;    /* 21:13 */
        unsigned int reserved_2                                       :   9               ;    /* 30:22 */
        unsigned int pdc_rx_ind                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB0;

typedef union {
    struct {
        unsigned int reserved_0                                       :   1               ;    /* 0 */
        unsigned int pde_cc_idx                                       :   4               ;    /* 4:1 */
        unsigned int reserved_1                                       :   2               ;    /* 6:5 */
        unsigned int pdc_rb_num                                       :   9               ;    /* 15:7 */
        unsigned int reserved_2                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB1;

typedef union {
    struct {
        unsigned int pdc_interleaved_flag                             :   1               ;    /* 0 */
        unsigned int pdc_shift_index                                  :   9               ;    /* 9:1 */
        unsigned int pdc_interleaver_rows                             :   3               ;    /* 12:10 */
        unsigned int pdc_bundle_size                                  :   3               ;    /* 15:13 */
        unsigned int pdc_coreset_rb_num                               :   9               ;    /* 24:16 */
        unsigned int pdc_coreset_dura                                 :   2               ;    /* 26:25 */
        unsigned int pdc_coreset_id                                   :   3               ;    /* 29:27 */
        unsigned int pdc_coreset_poolidx                              :   1               ;    /* 30 */
        unsigned int pdc_coreset_scrm_en                              :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB2;

typedef union {
    struct {
        unsigned int pdc_crst_6rb_map1                                :   13              ;    /* 12:0 */
        unsigned int pdc_crst_rb0_ofst                                :   3               ;    /* 15:13 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB4;

typedef union {
    struct {
        unsigned int pdc_dmrs_nid                                     :   16              ;    /* 15:0 */
        unsigned int pdc_dmrs_k_sel                                   :   1               ;    /* 16 */
        unsigned int reserved_0                                       :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB5;

typedef union {
    struct {
        unsigned int pdc_multifactor1                                 :   4               ;    /* 3:0 */
        unsigned int pdc_snr_idx                                      :   2               ;    /* 5:4 */
        unsigned int pdc_snr_rx_sel                                   :   2               ;    /* 7:6 */
        unsigned int pdc_polar_et_snr_flag                            :   2               ;    /* 9:8 */
        unsigned int reserved_0                                       :   22              ;    /* 31:10 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB6;

typedef union {
    struct {
        unsigned int fitp_coef0_0_i                                   :   8               ;    /* 7:0 */
        unsigned int fitp_coef0_0_q                                   :   8               ;    /* 15:8 */
        unsigned int fitp_coef0_1_i                                   :   8               ;    /* 23:16 */
        unsigned int fitp_coef0_1_q                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB8;

typedef union {
    struct {
        unsigned int fitp_coef1_0_i                                   :   8               ;    /* 7:0 */
        unsigned int fitp_coef1_0_q                                   :   8               ;    /* 15:8 */
        unsigned int fitp_coef1_1_i                                   :   8               ;    /* 23:16 */
        unsigned int fitp_coef1_1_q                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB9;

typedef union {
    struct {
        unsigned int fitp_coef2_0_i                                   :   8               ;    /* 7:0 */
        unsigned int fitp_coef2_0_q                                   :   8               ;    /* 15:8 */
        unsigned int fitp_coef2_1_i                                   :   8               ;    /* 23:16 */
        unsigned int fitp_coef2_1_q                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB10;

typedef union {
    struct {
        unsigned int fitp_coef3_0_i                                   :   8               ;    /* 7:0 */
        unsigned int fitp_coef3_0_q                                   :   8               ;    /* 15:8 */
        unsigned int fitp_coef3_1_i                                   :   8               ;    /* 23:16 */
        unsigned int fitp_coef3_1_q                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB11;

typedef union {
    struct {
        unsigned int noisebias_rx0                                    :   10              ;    /* 9:0 */
        unsigned int reserved_0                                       :   6               ;    /* 15:10 */
        unsigned int noisebias_rx1                                    :   10              ;    /* 25:16 */
        unsigned int reserved_1                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB14;

typedef union {
    struct {
        unsigned int noisebias_rx2                                    :   10              ;    /* 9:0 */
        unsigned int reserved_0                                       :   6               ;    /* 15:10 */
        unsigned int noisebias_rx3                                    :   10              ;    /* 25:16 */
        unsigned int reserved_1                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB15;

typedef union {
    struct {
        unsigned int pdc_cce_bitmap4                                  :   8               ;    /* 7:0 */
        unsigned int pdc_cce_num                                      :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB20;

typedef union {
    struct {
        unsigned int pdc_dmrs_x1_0                                    :   31              ;    /* 30:0 */
        unsigned int reserved_0                                       :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB21;

typedef union {
    struct {
        unsigned int pdc_dmrs_x2_0                                    :   31              ;    /* 30:0 */
        unsigned int reserved_0                                       :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB22;

typedef union {
    struct {
        unsigned int pdc_dmrs_x1_1                                    :   31              ;    /* 30:0 */
        unsigned int reserved_0                                       :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB23;

typedef union {
    struct {
        unsigned int pdc_dmrs_x2_1                                    :   31              ;    /* 30:0 */
        unsigned int reserved_0                                       :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB24;

typedef union {
    struct {
        unsigned int pdc_dmrs_x1_2                                    :   31              ;    /* 30:0 */
        unsigned int reserved_0                                       :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB25;

typedef union {
    struct {
        unsigned int pdc_dmrs_x2_2                                    :   31              ;    /* 30:0 */
        unsigned int reserved_0                                       :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB26;

typedef union {
    struct {
        unsigned int ls_shift_rx0                                     :   4               ;    /* 3:0 */
        unsigned int ls_shift_rx1                                     :   4               ;    /* 7:4 */
        unsigned int ls_shift_rx2                                     :   4               ;    /* 11:8 */
        unsigned int ls_shift_rx3                                     :   4               ;    /* 15:12 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB27;

typedef union {
    struct {
        unsigned int rb_conf_bit_map0_8                               :   18              ;    /* 17:0 */
        unsigned int reserved_0                                       :   14              ;    /* 31:18 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_PARA_SUB36;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB0                                    om_data0;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB1                                    om_data1;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB2                                    om_data2;
    unsigned int                                                      pdc_crst_6rb_map0;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB4                                    om_data4;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB5                                    om_data5;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB6                                    om_data6;
    unsigned int                                                      reserved_0;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB8                                    om_data8;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB9                                    om_data9;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB10                                   om_data10;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB11                                   om_data11;
    unsigned int                                                      reserved_1;
    unsigned int                                                      reserved_2;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB14                                   om_data14;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB15                                   om_data15;
    unsigned int                                                      pdc_cce_bitmap0;
    unsigned int                                                      pdc_cce_bitmap1;
    unsigned int                                                      pdc_cce_bitmap2;
    unsigned int                                                      pdc_cce_bitmap3;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB20                                   om_data20;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB21                                   om_data21;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB22                                   om_data22;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB23                                   om_data23;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB24                                   om_data24;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB25                                   om_data25;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB26                                   om_data26;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB27                                   om_data27;
    unsigned int                                                      rb_conf_bit_map0_0;
    unsigned int                                                      rb_conf_bit_map0_1;
    unsigned int                                                      rb_conf_bit_map0_2;
    unsigned int                                                      rb_conf_bit_map0_3;
    unsigned int                                                      rb_conf_bit_map0_4;
    unsigned int                                                      rb_conf_bit_map0_5;
    unsigned int                                                      rb_conf_bit_map0_6;
    unsigned int                                                      rb_conf_bit_map0_7;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB36                                   om_data36;
    unsigned int                                                      reserved_3;
} BCL_SID_BCL_NPDC_DEM_PARA;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB0                                    om_data0;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB1                                    om_data1;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB2                                    om_data2;
    unsigned int                                                      pdc_crst_6rb_map0;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB4                                    om_data4;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB5                                    om_data5;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB6                                    om_data6;
    unsigned int                                                      reserved_0;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB8                                    om_data8;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB9                                    om_data9;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB10                                   om_data10;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB11                                   om_data11;
    unsigned int                                                      reserved_1;
    unsigned int                                                      reserved_2;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB14                                   om_data14;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB15                                   om_data15;
    unsigned int                                                      pdc_cce_bitmap0;
    unsigned int                                                      pdc_cce_bitmap1;
    unsigned int                                                      pdc_cce_bitmap2;
    unsigned int                                                      pdc_cce_bitmap3;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB20                                   om_data20;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB21                                   om_data21;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB22                                   om_data22;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB23                                   om_data23;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB24                                   om_data24;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB25                                   om_data25;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB26                                   om_data26;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB27                                   om_data27;
    unsigned int                                                      rb_conf_bit_map0_0;
    unsigned int                                                      rb_conf_bit_map0_1;
    unsigned int                                                      rb_conf_bit_map0_2;
    unsigned int                                                      rb_conf_bit_map0_3;
    unsigned int                                                      rb_conf_bit_map0_4;
    unsigned int                                                      rb_conf_bit_map0_5;
    unsigned int                                                      rb_conf_bit_map0_6;
    unsigned int                                                      rb_conf_bit_map0_7;
    BCL_SID_BCL_NPDC_DEM_PARA_SUB36                                   om_data36;
    unsigned int                                                      reserved_3;
} BCL_SID_BCL_NPDC_DEM_PARA_BBP_MC;

typedef union {
    struct {
        unsigned int nrch_idx                                         :   4               ;    /* 3:0 */
        unsigned int rpt_pde_idx                                      :   1               ;    /* 4 */
        unsigned int rpt_pde_cfg_idx                                  :   3               ;    /* 7:5 */
        unsigned int coreset_idx                                      :   3               ;    /* 10:8 */
        unsigned int start_symbol                                     :   4               ;    /* 14:11 */
        unsigned int dci_rpt_en                                       :   1               ;    /* 15 */
        unsigned int slot_pq_flag                                     :   1               ;    /* 16 */
        unsigned int ant_preempt_ind                                  :   4               ;    /* 20:17 */
        unsigned int cmd_invld                                        :   1               ;    /* 21 */
        unsigned int span_flag                                        :   1               ;    /* 22 */
        unsigned int llr_rx24_mode                                    :   1               ;    /* 23 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_H_CMD_SUB0;

typedef union {
    struct {
        unsigned int h_iniaddr                                        :   14              ;    /* 13:0 */
        unsigned int cmd_rb_num                                       :   9               ;    /* 22:14 */
        unsigned int cmd_crst_dura                                    :   2               ;    /* 24:23 */
        unsigned int cmd_rx_num                                       :   3               ;    /* 27:25 */
        unsigned int cmd_ruu_mode                                     :   1               ;    /* 28 */
        unsigned int reserved_0                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_H_CMD_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NPDC_DEM_H_CMD_SUB0                                   om_data0;
    BCL_SID_BCL_NPDC_DEM_H_CMD_SUB1                                   om_data1;
} BCL_SID_BCL_NPDC_DEM_H_CMD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NPDC_DEM_H_CMD_SUB0                                   om_data0;
    BCL_SID_BCL_NPDC_DEM_H_CMD_SUB1                                   om_data1;
} BCL_SID_BCL_NPDC_DEM_H_CMD_BBP_MC;

typedef union {
    struct {
        unsigned int p_iniaddr                                        :   14              ;    /* 13:0 */
        unsigned int reserved_0                                       :   18              ;    /* 31:14 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_P_CMD_SUB0;

typedef union {
    struct {
        unsigned int slot_first_rpt                                   :   1               ;    /* 0 */
        unsigned int slot_end_rpt                                     :   1               ;    /* 1 */
        unsigned int span_first_rpt                                   :   1               ;    /* 2 */
        unsigned int area0_last_rpt                                   :   1               ;    /* 3 */
        unsigned int cfg_rf_off                                       :   1               ;    /* 4 */
        unsigned int cs0_no_dci                                       :   1               ;    /* 5 */
        unsigned int cs1_no_dci                                       :   1               ;    /* 6 */
        unsigned int cs2_no_dci                                       :   1               ;    /* 7 */
        unsigned int int_symb_idx                                     :   4               ;    /* 11:8 */
        unsigned int reserved_0                                       :   15              ;    /* 26:12 */
        unsigned int pde_idx                                          :   1               ;    /* 27 */
        unsigned int curr_cfg_idx                                     :   3               ;    /* 30:28 */
        unsigned int scheduled_flag                                   :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_DEM_P_CMD_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NPDC_DEM_P_CMD_SUB0                                   om_data0;
    BCL_SID_BCL_NPDC_DEM_P_CMD_SUB1                                   om_data1;
} BCL_SID_BCL_NPDC_DEM_P_CMD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NPDC_DEM_P_CMD_SUB0                                   om_data0;
    BCL_SID_BCL_NPDC_DEM_P_CMD_SUB1                                   om_data1;
} BCL_SID_BCL_NPDC_DEM_P_CMD_BBP_MC;

typedef union {
    struct {
        unsigned int end_sym_num                                      :   8               ;    /* 7:0 */
        unsigned int cfg_idx_mst                                      :   8               ;    /* 15:8 */
        unsigned int end_sym_idx                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_CHE_SUB0;

typedef union {
    struct {
        unsigned int cs_bitmap                                        :   3               ;    /* 2:0 */
        unsigned int reserved_0                                       :   29              ;    /* 31:3 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_CHE_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NPDC_CHE_SUB0                                         om_data0;
    BCL_SID_BCL_NPDC_CHE_SUB1                                         om_data1;
} BCL_SID_BCL_NPDC_CHE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NPDC_CHE_SUB0                                         om_data0;
    BCL_SID_BCL_NPDC_CHE_SUB1                                         om_data1;
} BCL_SID_BCL_NPDC_CHE_BBP_MC;

typedef union {
    struct {
        unsigned int ovb_clr_dif_ch0                                  :   4               ;    /* 3:0 */
        unsigned int ovb_clr_dif_ch1                                  :   4               ;    /* 7:4 */
        unsigned int ovb_clr_dif_ch2                                  :   4               ;    /* 11:8 */
        unsigned int ovb_clr_dif_ch3                                  :   4               ;    /* 15:12 */
        unsigned int ovb_clr_dif_ch4                                  :   4               ;    /* 19:16 */
        unsigned int ovb_clr_sel                                      :   5               ;    /* 24:20 */
        unsigned int reserved_0                                       :   7               ;    /* 31:25 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NPDC_CLR_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    BCL_SID_BCL_NPDC_CLR_SUB1                                         om_data1;
} BCL_SID_BCL_NPDC_CLR;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    BCL_SID_BCL_NPDC_CLR_SUB1                                         om_data1;
} BCL_SID_BCL_NPDC_CLR_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      npdc_dif_dbg0;
    unsigned int                                                      npdc_dif_dbg1;
    unsigned int                                                      npdc_dif_dbg2;
    unsigned int                                                      npdc_dif_dbg3;
    unsigned int                                                      npdc_dif_dbg4;
    unsigned int                                                      npdc_dif_dbg5;
} BCL_SID_FBCL_NPDC_DIF_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      npdc_dif_dbg0;
    unsigned int                                                      npdc_dif_dbg1;
    unsigned int                                                      npdc_dif_dbg2;
    unsigned int                                                      npdc_dif_dbg3;
    unsigned int                                                      npdc_dif_dbg4;
    unsigned int                                                      npdc_dif_dbg5;
} BCL_SID_FBCL_NPDC_DIF_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cmd_submodule_idx;
    unsigned int                                                      npb_task_cnt;
} BCL_SID_BCL_NRC_NPB_DIF_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cmd_submodule_idx;
    unsigned int                                                      npb_task_cnt;
} BCL_SID_BCL_NRC_NPB_DIF_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      dae_node_addr;
    unsigned int                                                      ssb_data_pos;
} BCL_SID_BCL_NRC_NPB_DIF_DAE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      dae_node_addr;
    unsigned int                                                      ssb_data_pos;
} BCL_SID_BCL_NRC_NPB_DIF_DAE_BBP_MC;

typedef union {
    struct {
        unsigned int init_npb_idx                                     :   1               ;    /* 0 */
        unsigned int npb_reset_flag                                   :   1               ;    /* 1 */
        unsigned int npb_search_fo_en                                 :   1               ;    /* 2 */
        unsigned int npb_search_fo_shift                              :   1               ;    /* 3 */
        unsigned int npb_search_fo                                    :   18              ;    /* 21:4 */
        unsigned int reserved_0                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_SSS_IC_PARA_SUB0;

typedef union {
    struct {
        unsigned int npb_ssb_index                                    :   8               ;    /* 7:0 */
        unsigned int npb_cmd_type                                     :   8               ;    /* 15:8 */
        unsigned int npb_ssb_idx                                      :   8               ;    /* 23:16 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_SSS_IC_PARA_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NRC_NPB_SSS_IC_PARA_SUB0                              om_data0;
    BCL_SID_BCL_NRC_NPB_SSS_IC_PARA_SUB1                              om_data1;
} BCL_SID_BCL_NRC_NPB_SSS_IC_PARA;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NRC_NPB_SSS_IC_PARA_SUB0                              om_data0;
    BCL_SID_BCL_NRC_NPB_SSS_IC_PARA_SUB1                              om_data1;
} BCL_SID_BCL_NRC_NPB_SSS_IC_PARA_BBP_MC;

typedef union {
    struct {
        unsigned int npb_snr_rx0                                      :   16              ;    /* 15:0 */
        unsigned int npb_snr_rx1                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_DMRS_BD_SNR_SUB0;

typedef union {
    struct {
        unsigned int npb_snr_rx2                                      :   16              ;    /* 15:0 */
        unsigned int npb_snr_rx3                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_DMRS_BD_SNR_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NRC_NPB_DMRS_BD_SNR_SUB0                              om_data0;
    BCL_SID_BCL_NRC_NPB_DMRS_BD_SNR_SUB1                              om_data1;
} BCL_SID_BCL_NRC_NPB_DMRS_BD_SNR;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NRC_NPB_DMRS_BD_SNR_SUB0                              om_data0;
    BCL_SID_BCL_NRC_NPB_DMRS_BD_SNR_SUB1                              om_data1;
} BCL_SID_BCL_NRC_NPB_DMRS_BD_SNR_BBP_MC;

typedef union {
    struct {
        unsigned int dmrs_idx_0                                       :   8               ;    /* 7:0 */
        unsigned int dmrs_idx_0_rst                                   :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_DMRS_BD_PARA_SUB0;

typedef union {
    struct {
        unsigned int dmrs_idx_1                                       :   8               ;    /* 7:0 */
        unsigned int dmrs_idx_1_rst                                   :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_DMRS_BD_PARA_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NRC_NPB_DMRS_BD_PARA_SUB0                             om_data0;
    BCL_SID_BCL_NRC_NPB_DMRS_BD_PARA_SUB1                             om_data1;
} BCL_SID_BCL_NRC_NPB_DMRS_BD_PARA;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NRC_NPB_DMRS_BD_PARA_SUB0                             om_data0;
    BCL_SID_BCL_NRC_NPB_DMRS_BD_PARA_SUB1                             om_data1;
} BCL_SID_BCL_NRC_NPB_DMRS_BD_PARA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      issb;
    unsigned int                                                      npb_fo_est;
} BCL_SID_BCL_NRC_NPB_LS_EST_PARA;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      issb;
    unsigned int                                                      npb_fo_est;
} BCL_SID_BCL_NRC_NPB_LS_EST_PARA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      fo_est_para0;
    unsigned int                                                      fo_est_para1;
    unsigned int                                                      fo_est_para2;
    unsigned int                                                      fo_est_para3;
    unsigned int                                                      fo_est_para4;
    unsigned int                                                      fo_est_para5;
    unsigned int                                                      fo_est_para6;
    unsigned int                                                      fo_est_para7;
    unsigned int                                                      fo_est_para8;
    unsigned int                                                      fo_est_para9;
    unsigned int                                                      fo_est_para10;
    unsigned int                                                      fo_est_para11;
    unsigned int                                                      fo_est_para12;
    unsigned int                                                      fo_est_para13;
    unsigned int                                                      fo_est_para14;
    unsigned int                                                      fo_est_para15;
    unsigned int                                                      fo_est_para16;
    unsigned int                                                      fo_est_para17;
    unsigned int                                                      fo_est_para18;
    unsigned int                                                      fo_est_para19;
    unsigned int                                                      fo_est_para20;
    unsigned int                                                      fo_est_para21;
    unsigned int                                                      fo_est_para22;
    unsigned int                                                      fo_est_para23;
    unsigned int                                                      fo_est_para24;
    unsigned int                                                      fo_est_para25;
    unsigned int                                                      fo_est_para26;
    unsigned int                                                      fo_est_para27;
    unsigned int                                                      fo_est_para28;
    unsigned int                                                      fo_est_para29;
    unsigned int                                                      fo_est_para30;
    unsigned int                                                      fo_est_para31;
} BCL_SID_BCL_NRC_NPB_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      fo_est_para0;
    unsigned int                                                      fo_est_para1;
    unsigned int                                                      fo_est_para2;
    unsigned int                                                      fo_est_para3;
    unsigned int                                                      fo_est_para4;
    unsigned int                                                      fo_est_para5;
    unsigned int                                                      fo_est_para6;
    unsigned int                                                      fo_est_para7;
    unsigned int                                                      fo_est_para8;
    unsigned int                                                      fo_est_para9;
    unsigned int                                                      fo_est_para10;
    unsigned int                                                      fo_est_para11;
    unsigned int                                                      fo_est_para12;
    unsigned int                                                      fo_est_para13;
    unsigned int                                                      fo_est_para14;
    unsigned int                                                      fo_est_para15;
    unsigned int                                                      fo_est_para16;
    unsigned int                                                      fo_est_para17;
    unsigned int                                                      fo_est_para18;
    unsigned int                                                      fo_est_para19;
    unsigned int                                                      fo_est_para20;
    unsigned int                                                      fo_est_para21;
    unsigned int                                                      fo_est_para22;
    unsigned int                                                      fo_est_para23;
    unsigned int                                                      fo_est_para24;
    unsigned int                                                      fo_est_para25;
    unsigned int                                                      fo_est_para26;
    unsigned int                                                      fo_est_para27;
    unsigned int                                                      fo_est_para28;
    unsigned int                                                      fo_est_para29;
    unsigned int                                                      fo_est_para30;
    unsigned int                                                      fo_est_para31;
} BCL_SID_BCL_NRC_NPB_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      npb_dft_pdp_idx;
    unsigned int                                                      npb_dft_pdp_filter_init;
} BCL_SID_BCL_NRC_NPB_DFT_PARA;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      npb_dft_pdp_idx;
    unsigned int                                                      npb_dft_pdp_filter_init;
} BCL_SID_BCL_NRC_NPB_DFT_PARA_BBP_MC;

typedef union {
    struct {
        unsigned int npb_new_cmd_0                                    :   1               ;    /* 0 */
        unsigned int tti_flag_0                                       :   1               ;    /* 1 */
        unsigned int mrg_idx_0                                        :   2               ;    /* 3:2 */
        unsigned int half_frame_0                                     :   1               ;    /* 4 */
        unsigned int sfn_num_0                                        :   10              ;    /* 14:5 */
        unsigned int dmrs_idx_0                                       :   3               ;    /* 17:15 */
        unsigned int reserved_0                                       :   10              ;    /* 27:18 */
        unsigned int npb_no_merge_0                                   :   1               ;    /* 28 */
        unsigned int tti_cnt_idx_0                                    :   1               ;    /* 29 */
        unsigned int lmax_idx_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_CMD_SUB0;

typedef union {
    struct {
        unsigned int card_flag_0                                      :   1               ;    /* 0 */
        unsigned int cmd_type_0                                       :   1               ;    /* 1 */
        unsigned int reserved_0                                       :   30              ;    /* 31:2 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_CMD_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NRC_NPB_CMD_SUB0                                      om_data0;
    BCL_SID_BCL_NRC_NPB_CMD_SUB1                                      om_data1;
} BCL_SID_BCL_NRC_NPB_CMD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NRC_NPB_CMD_SUB0                                      om_data0;
    BCL_SID_BCL_NRC_NPB_CMD_SUB1                                      om_data1;
} BCL_SID_BCL_NRC_NPB_CMD_BBP_MC;

typedef union {
    struct {
        unsigned int pb_dftgain_r0_dmrs                               :   16              ;    /* 15:0 */
        unsigned int pb_dftgain_r1_dmrs                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB28;

typedef union {
    struct {
        unsigned int pb_dftgain_r2_dmrs                               :   16              ;    /* 15:0 */
        unsigned int pb_dftgain_r3_dmrs                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB29;

typedef union {
    struct {
        unsigned int pb_dftgain_r0_sss                                :   16              ;    /* 15:0 */
        unsigned int pb_dftgain_r1_sss                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB30;

typedef union {
    struct {
        unsigned int pb_dftgain_r2_sss                                :   16              ;    /* 15:0 */
        unsigned int pb_dftgain_r3_sss                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB31;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      npb_rpt_ls_power_sym0_r0;
    unsigned int                                                      npb_rpt_ls_power_sym0_r1;
    unsigned int                                                      npb_rpt_ls_power_sym0_r2;
    unsigned int                                                      npb_rpt_ls_power_sym0_r3;
    unsigned int                                                      npb_rpt_ls_power_sym1_r0;
    unsigned int                                                      npb_rpt_ls_power_sym1_r1;
    unsigned int                                                      npb_rpt_ls_power_sym1_r2;
    unsigned int                                                      npb_rpt_ls_power_sym1_r3;
    unsigned int                                                      npb_rpt_ls_power_sym2_r0;
    unsigned int                                                      npb_rpt_ls_power_sym2_r1;
    unsigned int                                                      npb_rpt_ls_power_sym2_r2;
    unsigned int                                                      npb_rpt_ls_power_sym2_r3;
    unsigned int                                                      pb_noise_pow0_r0;
    unsigned int                                                      pb_noise_pow0_r1;
    unsigned int                                                      pb_noise_pow0_r2;
    unsigned int                                                      pb_noise_pow0_r3;
    unsigned int                                                      pb_noise_pow1_r0;
    unsigned int                                                      pb_noise_pow1_r1;
    unsigned int                                                      pb_noise_pow1_r2;
    unsigned int                                                      pb_noise_pow1_r3;
    unsigned int                                                      pb_rsrp0_r0;
    unsigned int                                                      pb_rsrp0_r1;
    unsigned int                                                      pb_rsrp0_r2;
    unsigned int                                                      pb_rsrp0_r3;
    unsigned int                                                      pb_rsrp1_r0;
    unsigned int                                                      pb_rsrp1_r1;
    unsigned int                                                      pb_rsrp1_r2;
    unsigned int                                                      pb_rsrp1_r3;
    BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB28                             om_data28;
    BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB29                             om_data29;
    BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB30                             om_data30;
    BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB31                             om_data31;
} BCL_SID_BCL_NRC_NPB_DFT_EST_RPT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      npb_rpt_ls_power_sym0_r0;
    unsigned int                                                      npb_rpt_ls_power_sym0_r1;
    unsigned int                                                      npb_rpt_ls_power_sym0_r2;
    unsigned int                                                      npb_rpt_ls_power_sym0_r3;
    unsigned int                                                      npb_rpt_ls_power_sym1_r0;
    unsigned int                                                      npb_rpt_ls_power_sym1_r1;
    unsigned int                                                      npb_rpt_ls_power_sym1_r2;
    unsigned int                                                      npb_rpt_ls_power_sym1_r3;
    unsigned int                                                      npb_rpt_ls_power_sym2_r0;
    unsigned int                                                      npb_rpt_ls_power_sym2_r1;
    unsigned int                                                      npb_rpt_ls_power_sym2_r2;
    unsigned int                                                      npb_rpt_ls_power_sym2_r3;
    unsigned int                                                      pb_noise_pow0_r0;
    unsigned int                                                      pb_noise_pow0_r1;
    unsigned int                                                      pb_noise_pow0_r2;
    unsigned int                                                      pb_noise_pow0_r3;
    unsigned int                                                      pb_noise_pow1_r0;
    unsigned int                                                      pb_noise_pow1_r1;
    unsigned int                                                      pb_noise_pow1_r2;
    unsigned int                                                      pb_noise_pow1_r3;
    unsigned int                                                      pb_rsrp0_r0;
    unsigned int                                                      pb_rsrp0_r1;
    unsigned int                                                      pb_rsrp0_r2;
    unsigned int                                                      pb_rsrp0_r3;
    unsigned int                                                      pb_rsrp1_r0;
    unsigned int                                                      pb_rsrp1_r1;
    unsigned int                                                      pb_rsrp1_r2;
    unsigned int                                                      pb_rsrp1_r3;
    BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB28                             om_data28;
    BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB29                             om_data29;
    BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB30                             om_data30;
    BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_SUB31                             om_data31;
} BCL_SID_BCL_NRC_NPB_DFT_EST_RPT_BBP_MC;

typedef union {
    struct {
        unsigned int reserved_0                                       :   1               ;    /* 0 */
        unsigned int npb_crc                                          :   1               ;    /* 1 */
        unsigned int npb_dmrs_idx                                     :   3               ;    /* 4:2 */
        unsigned int npb_dec_num                                      :   2               ;    /* 6:5 */
        unsigned int reserved_1                                       :   25              ;    /* 31:7 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_MIB_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NRC_NPB_MIB_SUB0                                      om_data0;
    unsigned int                                                      npb_rpt_mib;
} BCL_SID_BCL_NRC_NPB_MIB;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NRC_NPB_MIB_SUB0                                      om_data0;
    unsigned int                                                      npb_rpt_mib;
} BCL_SID_BCL_NRC_NPB_MIB_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      npb_rpt_flag;
    unsigned int                                                      npb_task_cnt;
} BCL_SID_BCL_NRC_NPB_RPT_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      npb_rpt_flag;
    unsigned int                                                      npb_task_cnt;
} BCL_SID_BCL_NRC_NPB_RPT_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int pb_corr_ruu                                      :   19              ;    /* 18:0 */
        unsigned int pb_ruu_whiteflag_cnt                             :   9               ;    /* 27:19 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_NRC_NPB_RPT_IRC_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_NRC_NPB_RPT_IRC_SUB0                                  om_data0;
    unsigned int                                                      reserved_0;
} BCL_SID_BCL_NRC_NPB_RPT_IRC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_NRC_NPB_RPT_IRC_SUB0                                  om_data0;
    unsigned int                                                      reserved_0;
} BCL_SID_BCL_NRC_NPB_RPT_IRC_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   8               ;    /* 7:0 */
        unsigned int subframe_num                                     :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_DEM_EN_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_PDC_DEM_EN_SUB0                                       om_data0;
    unsigned int                                                      pdc_en;
} BCL_SID_BCL_PDC_DEM_EN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_PDC_DEM_EN_SUB0                                       om_data0;
    unsigned int                                                      pdc_en;
} BCL_SID_BCL_PDC_DEM_EN_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   8               ;    /* 7:0 */
        unsigned int subframe_num                                     :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_SS_SUB0;

typedef union {
    struct {
        unsigned int pdc_en                                           :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   2               ;    /* 2:1 */
        unsigned int lte_cp_mode                                      :   1               ;    /* 3 */
        unsigned int lte_tx_num                                       :   4               ;    /* 7:4 */
        unsigned int lte_rx_num                                       :   4               ;    /* 11:8 */
        unsigned int lte_rb_num                                       :   8               ;    /* 19:12 */
        unsigned int reserved_1                                       :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_SS_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_PDC_SS_SUB0                                           om_data0;
    BCL_SID_BCL_PDC_SS_SUB1                                           om_data1;
} BCL_SID_BCL_PDC_SS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_PDC_SS_SUB0                                           om_data0;
    BCL_SID_BCL_PDC_SS_SUB1                                           om_data1;
} BCL_SID_BCL_PDC_SS_BBP_MC;

typedef union {
    struct {
        unsigned int tx01_dims                                        :   8               ;    /* 7:0 */
        unsigned int tx23_dims                                        :   8               ;    /* 15:8 */
        unsigned int tx01_pattern                                     :   8               ;    /* 23:16 */
        unsigned int tx23_pattern                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CRS_INIT_SUB0;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   8               ;    /* 7:0 */
        unsigned int subframe_num                                     :   8               ;    /* 15:8 */
        unsigned int crs_fitp_target_n                                :   8               ;    /* 23:16 */
        unsigned int reserved_0                                       :   7               ;    /* 30:24 */
        unsigned int pdc_en                                           :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CRS_INIT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_PDC_CRS_INIT_SUB0                                     om_data0;
    BCL_SID_BCL_PDC_CRS_INIT_SUB1                                     om_data1;
} BCL_SID_BCL_PDC_CRS_INIT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_PDC_CRS_INIT_SUB0                                     om_data0;
    BCL_SID_BCL_PDC_CRS_INIT_SUB1                                     om_data1;
} BCL_SID_BCL_PDC_CRS_INIT_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   8               ;    /* 7:0 */
        unsigned int subframe_num                                     :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_SYM0_SUB0;

typedef union {
    struct {
        unsigned int pdc_en                                           :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   3               ;    /* 3:1 */
        unsigned int phi_en                                           :   1               ;    /* 4 */
        unsigned int reserved_1                                       :   3               ;    /* 7:5 */
        unsigned int pdc_vdl_rpt_ch                                   :   3               ;    /* 10:8 */
        unsigned int reserved_2                                       :   17              ;    /* 27:11 */
        unsigned int che_ic_mode                                      :   1               ;    /* 28 */
        unsigned int pdc_ic_ruu_sel                                   :   2               ;    /* 30:29 */
        unsigned int pdc_ic_irc_en                                    :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_SYM0_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_PDC_SYM0_SUB0                                         om_data0;
    BCL_SID_BCL_PDC_SYM0_SUB1                                         om_data1;
} BCL_SID_BCL_PDC_SYM0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_PDC_SYM0_SUB0                                         om_data0;
    BCL_SID_BCL_PDC_SYM0_SUB1                                         om_data1;
} BCL_SID_BCL_PDC_SYM0_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   8               ;    /* 7:0 */
        unsigned int subframe_num                                     :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_SYM1_SUB0;

typedef union {
    struct {
        unsigned int pdc_en                                           :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   3               ;    /* 3:1 */
        unsigned int cfi_val                                          :   4               ;    /* 7:4 */
        unsigned int reserved_1                                       :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_SYM1_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_PDC_SYM1_SUB0                                         om_data0;
    BCL_SID_BCL_PDC_SYM1_SUB1                                         om_data1;
} BCL_SID_BCL_PDC_SYM1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_PDC_SYM1_SUB0                                         om_data0;
    BCL_SID_BCL_PDC_SYM1_SUB1                                         om_data1;
} BCL_SID_BCL_PDC_SYM1_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   8               ;    /* 7:0 */
        unsigned int subframe_num                                     :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_SYM2_SUB0;

typedef union {
    struct {
        unsigned int pdc_en                                           :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   3               ;    /* 3:1 */
        unsigned int cfi_val                                          :   4               ;    /* 7:4 */
        unsigned int reserved_1                                       :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_SYM2_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_PDC_SYM2_SUB0                                         om_data0;
    BCL_SID_BCL_PDC_SYM2_SUB1                                         om_data1;
} BCL_SID_BCL_PDC_SYM2;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_PDC_SYM2_SUB0                                         om_data0;
    BCL_SID_BCL_PDC_SYM2_SUB1                                         om_data1;
} BCL_SID_BCL_PDC_SYM2_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   8               ;    /* 7:0 */
        unsigned int subframe_num                                     :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_DEM_SUB0;

typedef union {
    struct {
        unsigned int pdc_phi_bd                                       :   1               ;    /* 0 */
        unsigned int pdc_cfi_mod                                      :   2               ;    /* 2:1 */
        unsigned int pdc_cfi_val                                      :   2               ;    /* 4:3 */
        unsigned int reserved_0                                       :   8               ;    /* 12:5 */
        unsigned int pdc_phi_dura                                     :   2               ;    /* 14:13 */
        unsigned int pdc_phi_gps                                      :   6               ;    /* 20:15 */
        unsigned int pdc_egr_rx_prefer0                               :   2               ;    /* 22:21 */
        unsigned int pdc_egr_rx_prefer1                               :   2               ;    /* 24:23 */
        unsigned int pdc_egr_rx_prefer2                               :   2               ;    /* 26:25 */
        unsigned int pdc_egr_rx_prefer3                               :   2               ;    /* 28:27 */
        unsigned int reserved_1                                       :   2               ;    /* 30:29 */
        unsigned int pdc_res_protect_en                               :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_DEM_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_PDC_DEM_SUB0                                          om_data0;
    BCL_SID_BCL_PDC_DEM_SUB1                                          om_data1;
} BCL_SID_BCL_PDC_DEM;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_PDC_DEM_SUB0                                          om_data0;
    BCL_SID_BCL_PDC_DEM_SUB1                                          om_data1;
} BCL_SID_BCL_PDC_DEM_BBP_MC;

typedef union {
    struct {
        unsigned int pdc_cmd_v                                        :   1               ;    /* 0 */
        unsigned int pdc_phi_bd                                       :   1               ;    /* 1 */
        unsigned int pdc_pde_ind                                      :   1               ;    /* 2 */
        unsigned int reserved_0                                       :   4               ;    /* 6:3 */
        unsigned int pdc_int_en                                       :   1               ;    /* 7 */
        unsigned int cce_num                                          :   8               ;    /* 15:8 */
        unsigned int re_num                                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CMD_SENT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pdc_vdl_rpt_ch;
    BCL_SID_BCL_PDC_CMD_SENT_SUB1                                     om_data1;
} BCL_SID_BCL_PDC_CMD_SENT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pdc_vdl_rpt_ch;
    BCL_SID_BCL_PDC_CMD_SENT_SUB1                                     om_data1;
} BCL_SID_BCL_PDC_CMD_SENT_BBP_MC;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re0                                 :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB0;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re1                                 :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im1                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB1;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re2                                 :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im2                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB2;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re3                                 :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im3                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB3;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re4                                 :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im4                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB4;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re5                                 :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im5                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB5;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re6                                 :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im6                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB6;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re7                                 :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im7                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB7;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re8                                 :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im8                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB8;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re9                                 :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im9                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB9;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re10                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im10                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB10;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re11                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im11                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB11;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re12                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im12                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB12;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re13                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im13                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB13;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re14                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im14                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB14;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re15                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im15                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB15;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re16                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im16                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB16;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re17                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im17                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB17;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re18                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im18                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB18;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re19                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im19                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB19;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re20                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im20                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB20;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re21                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im21                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB21;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re22                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im22                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB22;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re23                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im23                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB23;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re24                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im24                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB24;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re25                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im25                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB25;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re26                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im26                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB26;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re27                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im27                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB27;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re28                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im28                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB28;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re29                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im29                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB29;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re30                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im30                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB30;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re31                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im31                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB31;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re32                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im32                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB32;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re33                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im33                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB33;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re34                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im34                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB34;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re35                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im35                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB35;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re36                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im36                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB36;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re37                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im37                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB37;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re38                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im38                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB38;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re39                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im39                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB39;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re40                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im40                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB40;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re41                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im41                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB41;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re42                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im42                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB42;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re43                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im43                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB43;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re44                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im44                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB44;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re45                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im45                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB45;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re46                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im46                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB46;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re47                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im47                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB47;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re48                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im48                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB48;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re49                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im49                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB49;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re50                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im50                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB50;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re51                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im51                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB51;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re52                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im52                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB52;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re53                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im53                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB53;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re54                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im54                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB54;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re55                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im55                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB55;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re56                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im56                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB56;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re57                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im57                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB57;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re58                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im58                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB58;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re59                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im59                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB59;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re60                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im60                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB60;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re61                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im61                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB61;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re62                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im62                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB62;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re63                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im63                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB63;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re64                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im64                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB64;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re65                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im65                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB65;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re66                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im66                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB66;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re67                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im67                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB67;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re68                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im68                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB68;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re69                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im69                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB69;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re70                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im70                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB70;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re71                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im71                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB71;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re72                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im72                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB72;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re73                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im73                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB73;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re74                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im74                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB74;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re75                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im75                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB75;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re76                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im76                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB76;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re77                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im77                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB77;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re78                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im78                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB78;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re79                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im79                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB79;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re80                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im80                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB80;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re81                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im81                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB81;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re82                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im82                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB82;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re83                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im83                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB83;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re84                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im84                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB84;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re85                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im85                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB85;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re86                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im86                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB86;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re87                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im87                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB87;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re88                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im88                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB88;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re89                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im89                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB89;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re90                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im90                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB90;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re91                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im91                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB91;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re92                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im92                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB92;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re93                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im93                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB93;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re94                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im94                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB94;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re95                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im95                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB95;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re96                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im96                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB96;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re97                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im97                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB97;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re98                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im98                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB98;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re99                                :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im99                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB99;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re100                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im100                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB100;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re101                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im101                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB101;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re102                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im102                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB102;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re103                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im103                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB103;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re104                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im104                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB104;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re105                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im105                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB105;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re106                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im106                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB106;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re107                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im107                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB107;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re108                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im108                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB108;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re109                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im109                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB109;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re110                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im110                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB110;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re111                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im111                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB111;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re112                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im112                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB112;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re113                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im113                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB113;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re114                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im114                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB114;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re115                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im115                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB115;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re116                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im116                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB116;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re117                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im117                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB117;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re118                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im118                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB118;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re119                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im119                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB119;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re120                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im120                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB120;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re121                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im121                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB121;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re122                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im122                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB122;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re123                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im123                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB123;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re124                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im124                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB124;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re125                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im125                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB125;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re126                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im126                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB126;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re127                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im127                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB127;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re128                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im128                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB128;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re129                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im129                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB129;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re130                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im130                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB130;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re131                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im131                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB131;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re132                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im132                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB132;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re133                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im133                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB133;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re134                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im134                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB134;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re135                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im135                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB135;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re136                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im136                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB136;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re137                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im137                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB137;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re138                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im138                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB138;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re139                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im139                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB139;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re140                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im140                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB140;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re141                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im141                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB141;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re142                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im142                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB142;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re143                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im143                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB143;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re144                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im144                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB144;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re145                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im145                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB145;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re146                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im146                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB146;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re147                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im147                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB147;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re148                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im148                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB148;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re149                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im149                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB149;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re150                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im150                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB150;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re151                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im151                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB151;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re152                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im152                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB152;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re153                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im153                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB153;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re154                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im154                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB154;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re155                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im155                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB155;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re156                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im156                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB156;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re157                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im157                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB157;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re158                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im158                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB158;

typedef union {
    struct {
        unsigned int pdc_cfc_coef_re159                               :   16              ;    /* 15:0 */
        unsigned int pdc_cfc_coef_im159                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB159;

typedef union {
    struct {
        unsigned int tx01_shift_rx0_sym0                              :   8               ;    /* 7:0 */
        unsigned int tx01_shift_rx0_sym1                              :   8               ;    /* 15:8 */
        unsigned int tx01_shift_rx0_sym2                              :   8               ;    /* 23:16 */
        unsigned int tx01_shift_rx0_sym3                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB160;

typedef union {
    struct {
        unsigned int tx01_shift_rx1_sym0                              :   8               ;    /* 7:0 */
        unsigned int tx01_shift_rx1_sym1                              :   8               ;    /* 15:8 */
        unsigned int tx01_shift_rx1_sym2                              :   8               ;    /* 23:16 */
        unsigned int tx01_shift_rx1_sym3                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB161;

typedef union {
    struct {
        unsigned int tx01_shift_rx2_sym0                              :   8               ;    /* 7:0 */
        unsigned int tx01_shift_rx2_sym1                              :   8               ;    /* 15:8 */
        unsigned int tx01_shift_rx2_sym2                              :   8               ;    /* 23:16 */
        unsigned int tx01_shift_rx2_sym3                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB162;

typedef union {
    struct {
        unsigned int tx01_shift_rx3_sym0                              :   8               ;    /* 7:0 */
        unsigned int tx01_shift_rx3_sym1                              :   8               ;    /* 15:8 */
        unsigned int tx01_shift_rx3_sym2                              :   8               ;    /* 23:16 */
        unsigned int tx01_shift_rx3_sym3                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB163;

typedef union {
    struct {
        unsigned int tx23_shift_rx0_sym0                              :   8               ;    /* 7:0 */
        unsigned int tx23_shift_rx0_sym1                              :   8               ;    /* 15:8 */
        unsigned int tx23_shift_rx0_sym2                              :   8               ;    /* 23:16 */
        unsigned int tx23_shift_rx0_sym3                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB164;

typedef union {
    struct {
        unsigned int tx23_shift_rx1_sym0                              :   8               ;    /* 7:0 */
        unsigned int tx23_shift_rx1_sym1                              :   8               ;    /* 15:8 */
        unsigned int tx23_shift_rx1_sym2                              :   8               ;    /* 23:16 */
        unsigned int tx23_shift_rx1_sym3                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB165;

typedef union {
    struct {
        unsigned int tx23_shift_rx2_sym0                              :   8               ;    /* 7:0 */
        unsigned int tx23_shift_rx2_sym1                              :   8               ;    /* 15:8 */
        unsigned int tx23_shift_rx2_sym2                              :   8               ;    /* 23:16 */
        unsigned int tx23_shift_rx2_sym3                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB166;

typedef union {
    struct {
        unsigned int tx23_shift_rx3_sym0                              :   8               ;    /* 7:0 */
        unsigned int tx23_shift_rx3_sym1                              :   8               ;    /* 15:8 */
        unsigned int tx23_shift_rx3_sym2                              :   8               ;    /* 23:16 */
        unsigned int tx23_shift_rx3_sym3                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_PDC_CFC_INFO_SUB167;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_PDC_CFC_INFO_SUB0                                     om_data0;
    BCL_SID_BCL_PDC_CFC_INFO_SUB1                                     om_data1;
    BCL_SID_BCL_PDC_CFC_INFO_SUB2                                     om_data2;
    BCL_SID_BCL_PDC_CFC_INFO_SUB3                                     om_data3;
    BCL_SID_BCL_PDC_CFC_INFO_SUB4                                     om_data4;
    BCL_SID_BCL_PDC_CFC_INFO_SUB5                                     om_data5;
    BCL_SID_BCL_PDC_CFC_INFO_SUB6                                     om_data6;
    BCL_SID_BCL_PDC_CFC_INFO_SUB7                                     om_data7;
    BCL_SID_BCL_PDC_CFC_INFO_SUB8                                     om_data8;
    BCL_SID_BCL_PDC_CFC_INFO_SUB9                                     om_data9;
    BCL_SID_BCL_PDC_CFC_INFO_SUB10                                    om_data10;
    BCL_SID_BCL_PDC_CFC_INFO_SUB11                                    om_data11;
    BCL_SID_BCL_PDC_CFC_INFO_SUB12                                    om_data12;
    BCL_SID_BCL_PDC_CFC_INFO_SUB13                                    om_data13;
    BCL_SID_BCL_PDC_CFC_INFO_SUB14                                    om_data14;
    BCL_SID_BCL_PDC_CFC_INFO_SUB15                                    om_data15;
    BCL_SID_BCL_PDC_CFC_INFO_SUB16                                    om_data16;
    BCL_SID_BCL_PDC_CFC_INFO_SUB17                                    om_data17;
    BCL_SID_BCL_PDC_CFC_INFO_SUB18                                    om_data18;
    BCL_SID_BCL_PDC_CFC_INFO_SUB19                                    om_data19;
    BCL_SID_BCL_PDC_CFC_INFO_SUB20                                    om_data20;
    BCL_SID_BCL_PDC_CFC_INFO_SUB21                                    om_data21;
    BCL_SID_BCL_PDC_CFC_INFO_SUB22                                    om_data22;
    BCL_SID_BCL_PDC_CFC_INFO_SUB23                                    om_data23;
    BCL_SID_BCL_PDC_CFC_INFO_SUB24                                    om_data24;
    BCL_SID_BCL_PDC_CFC_INFO_SUB25                                    om_data25;
    BCL_SID_BCL_PDC_CFC_INFO_SUB26                                    om_data26;
    BCL_SID_BCL_PDC_CFC_INFO_SUB27                                    om_data27;
    BCL_SID_BCL_PDC_CFC_INFO_SUB28                                    om_data28;
    BCL_SID_BCL_PDC_CFC_INFO_SUB29                                    om_data29;
    BCL_SID_BCL_PDC_CFC_INFO_SUB30                                    om_data30;
    BCL_SID_BCL_PDC_CFC_INFO_SUB31                                    om_data31;
    BCL_SID_BCL_PDC_CFC_INFO_SUB32                                    om_data32;
    BCL_SID_BCL_PDC_CFC_INFO_SUB33                                    om_data33;
    BCL_SID_BCL_PDC_CFC_INFO_SUB34                                    om_data34;
    BCL_SID_BCL_PDC_CFC_INFO_SUB35                                    om_data35;
    BCL_SID_BCL_PDC_CFC_INFO_SUB36                                    om_data36;
    BCL_SID_BCL_PDC_CFC_INFO_SUB37                                    om_data37;
    BCL_SID_BCL_PDC_CFC_INFO_SUB38                                    om_data38;
    BCL_SID_BCL_PDC_CFC_INFO_SUB39                                    om_data39;
    BCL_SID_BCL_PDC_CFC_INFO_SUB40                                    om_data40;
    BCL_SID_BCL_PDC_CFC_INFO_SUB41                                    om_data41;
    BCL_SID_BCL_PDC_CFC_INFO_SUB42                                    om_data42;
    BCL_SID_BCL_PDC_CFC_INFO_SUB43                                    om_data43;
    BCL_SID_BCL_PDC_CFC_INFO_SUB44                                    om_data44;
    BCL_SID_BCL_PDC_CFC_INFO_SUB45                                    om_data45;
    BCL_SID_BCL_PDC_CFC_INFO_SUB46                                    om_data46;
    BCL_SID_BCL_PDC_CFC_INFO_SUB47                                    om_data47;
    BCL_SID_BCL_PDC_CFC_INFO_SUB48                                    om_data48;
    BCL_SID_BCL_PDC_CFC_INFO_SUB49                                    om_data49;
    BCL_SID_BCL_PDC_CFC_INFO_SUB50                                    om_data50;
    BCL_SID_BCL_PDC_CFC_INFO_SUB51                                    om_data51;
    BCL_SID_BCL_PDC_CFC_INFO_SUB52                                    om_data52;
    BCL_SID_BCL_PDC_CFC_INFO_SUB53                                    om_data53;
    BCL_SID_BCL_PDC_CFC_INFO_SUB54                                    om_data54;
    BCL_SID_BCL_PDC_CFC_INFO_SUB55                                    om_data55;
    BCL_SID_BCL_PDC_CFC_INFO_SUB56                                    om_data56;
    BCL_SID_BCL_PDC_CFC_INFO_SUB57                                    om_data57;
    BCL_SID_BCL_PDC_CFC_INFO_SUB58                                    om_data58;
    BCL_SID_BCL_PDC_CFC_INFO_SUB59                                    om_data59;
    BCL_SID_BCL_PDC_CFC_INFO_SUB60                                    om_data60;
    BCL_SID_BCL_PDC_CFC_INFO_SUB61                                    om_data61;
    BCL_SID_BCL_PDC_CFC_INFO_SUB62                                    om_data62;
    BCL_SID_BCL_PDC_CFC_INFO_SUB63                                    om_data63;
    BCL_SID_BCL_PDC_CFC_INFO_SUB64                                    om_data64;
    BCL_SID_BCL_PDC_CFC_INFO_SUB65                                    om_data65;
    BCL_SID_BCL_PDC_CFC_INFO_SUB66                                    om_data66;
    BCL_SID_BCL_PDC_CFC_INFO_SUB67                                    om_data67;
    BCL_SID_BCL_PDC_CFC_INFO_SUB68                                    om_data68;
    BCL_SID_BCL_PDC_CFC_INFO_SUB69                                    om_data69;
    BCL_SID_BCL_PDC_CFC_INFO_SUB70                                    om_data70;
    BCL_SID_BCL_PDC_CFC_INFO_SUB71                                    om_data71;
    BCL_SID_BCL_PDC_CFC_INFO_SUB72                                    om_data72;
    BCL_SID_BCL_PDC_CFC_INFO_SUB73                                    om_data73;
    BCL_SID_BCL_PDC_CFC_INFO_SUB74                                    om_data74;
    BCL_SID_BCL_PDC_CFC_INFO_SUB75                                    om_data75;
    BCL_SID_BCL_PDC_CFC_INFO_SUB76                                    om_data76;
    BCL_SID_BCL_PDC_CFC_INFO_SUB77                                    om_data77;
    BCL_SID_BCL_PDC_CFC_INFO_SUB78                                    om_data78;
    BCL_SID_BCL_PDC_CFC_INFO_SUB79                                    om_data79;
    BCL_SID_BCL_PDC_CFC_INFO_SUB80                                    om_data80;
    BCL_SID_BCL_PDC_CFC_INFO_SUB81                                    om_data81;
    BCL_SID_BCL_PDC_CFC_INFO_SUB82                                    om_data82;
    BCL_SID_BCL_PDC_CFC_INFO_SUB83                                    om_data83;
    BCL_SID_BCL_PDC_CFC_INFO_SUB84                                    om_data84;
    BCL_SID_BCL_PDC_CFC_INFO_SUB85                                    om_data85;
    BCL_SID_BCL_PDC_CFC_INFO_SUB86                                    om_data86;
    BCL_SID_BCL_PDC_CFC_INFO_SUB87                                    om_data87;
    BCL_SID_BCL_PDC_CFC_INFO_SUB88                                    om_data88;
    BCL_SID_BCL_PDC_CFC_INFO_SUB89                                    om_data89;
    BCL_SID_BCL_PDC_CFC_INFO_SUB90                                    om_data90;
    BCL_SID_BCL_PDC_CFC_INFO_SUB91                                    om_data91;
    BCL_SID_BCL_PDC_CFC_INFO_SUB92                                    om_data92;
    BCL_SID_BCL_PDC_CFC_INFO_SUB93                                    om_data93;
    BCL_SID_BCL_PDC_CFC_INFO_SUB94                                    om_data94;
    BCL_SID_BCL_PDC_CFC_INFO_SUB95                                    om_data95;
    BCL_SID_BCL_PDC_CFC_INFO_SUB96                                    om_data96;
    BCL_SID_BCL_PDC_CFC_INFO_SUB97                                    om_data97;
    BCL_SID_BCL_PDC_CFC_INFO_SUB98                                    om_data98;
    BCL_SID_BCL_PDC_CFC_INFO_SUB99                                    om_data99;
    BCL_SID_BCL_PDC_CFC_INFO_SUB100                                   om_data100;
    BCL_SID_BCL_PDC_CFC_INFO_SUB101                                   om_data101;
    BCL_SID_BCL_PDC_CFC_INFO_SUB102                                   om_data102;
    BCL_SID_BCL_PDC_CFC_INFO_SUB103                                   om_data103;
    BCL_SID_BCL_PDC_CFC_INFO_SUB104                                   om_data104;
    BCL_SID_BCL_PDC_CFC_INFO_SUB105                                   om_data105;
    BCL_SID_BCL_PDC_CFC_INFO_SUB106                                   om_data106;
    BCL_SID_BCL_PDC_CFC_INFO_SUB107                                   om_data107;
    BCL_SID_BCL_PDC_CFC_INFO_SUB108                                   om_data108;
    BCL_SID_BCL_PDC_CFC_INFO_SUB109                                   om_data109;
    BCL_SID_BCL_PDC_CFC_INFO_SUB110                                   om_data110;
    BCL_SID_BCL_PDC_CFC_INFO_SUB111                                   om_data111;
    BCL_SID_BCL_PDC_CFC_INFO_SUB112                                   om_data112;
    BCL_SID_BCL_PDC_CFC_INFO_SUB113                                   om_data113;
    BCL_SID_BCL_PDC_CFC_INFO_SUB114                                   om_data114;
    BCL_SID_BCL_PDC_CFC_INFO_SUB115                                   om_data115;
    BCL_SID_BCL_PDC_CFC_INFO_SUB116                                   om_data116;
    BCL_SID_BCL_PDC_CFC_INFO_SUB117                                   om_data117;
    BCL_SID_BCL_PDC_CFC_INFO_SUB118                                   om_data118;
    BCL_SID_BCL_PDC_CFC_INFO_SUB119                                   om_data119;
    BCL_SID_BCL_PDC_CFC_INFO_SUB120                                   om_data120;
    BCL_SID_BCL_PDC_CFC_INFO_SUB121                                   om_data121;
    BCL_SID_BCL_PDC_CFC_INFO_SUB122                                   om_data122;
    BCL_SID_BCL_PDC_CFC_INFO_SUB123                                   om_data123;
    BCL_SID_BCL_PDC_CFC_INFO_SUB124                                   om_data124;
    BCL_SID_BCL_PDC_CFC_INFO_SUB125                                   om_data125;
    BCL_SID_BCL_PDC_CFC_INFO_SUB126                                   om_data126;
    BCL_SID_BCL_PDC_CFC_INFO_SUB127                                   om_data127;
    BCL_SID_BCL_PDC_CFC_INFO_SUB128                                   om_data128;
    BCL_SID_BCL_PDC_CFC_INFO_SUB129                                   om_data129;
    BCL_SID_BCL_PDC_CFC_INFO_SUB130                                   om_data130;
    BCL_SID_BCL_PDC_CFC_INFO_SUB131                                   om_data131;
    BCL_SID_BCL_PDC_CFC_INFO_SUB132                                   om_data132;
    BCL_SID_BCL_PDC_CFC_INFO_SUB133                                   om_data133;
    BCL_SID_BCL_PDC_CFC_INFO_SUB134                                   om_data134;
    BCL_SID_BCL_PDC_CFC_INFO_SUB135                                   om_data135;
    BCL_SID_BCL_PDC_CFC_INFO_SUB136                                   om_data136;
    BCL_SID_BCL_PDC_CFC_INFO_SUB137                                   om_data137;
    BCL_SID_BCL_PDC_CFC_INFO_SUB138                                   om_data138;
    BCL_SID_BCL_PDC_CFC_INFO_SUB139                                   om_data139;
    BCL_SID_BCL_PDC_CFC_INFO_SUB140                                   om_data140;
    BCL_SID_BCL_PDC_CFC_INFO_SUB141                                   om_data141;
    BCL_SID_BCL_PDC_CFC_INFO_SUB142                                   om_data142;
    BCL_SID_BCL_PDC_CFC_INFO_SUB143                                   om_data143;
    BCL_SID_BCL_PDC_CFC_INFO_SUB144                                   om_data144;
    BCL_SID_BCL_PDC_CFC_INFO_SUB145                                   om_data145;
    BCL_SID_BCL_PDC_CFC_INFO_SUB146                                   om_data146;
    BCL_SID_BCL_PDC_CFC_INFO_SUB147                                   om_data147;
    BCL_SID_BCL_PDC_CFC_INFO_SUB148                                   om_data148;
    BCL_SID_BCL_PDC_CFC_INFO_SUB149                                   om_data149;
    BCL_SID_BCL_PDC_CFC_INFO_SUB150                                   om_data150;
    BCL_SID_BCL_PDC_CFC_INFO_SUB151                                   om_data151;
    BCL_SID_BCL_PDC_CFC_INFO_SUB152                                   om_data152;
    BCL_SID_BCL_PDC_CFC_INFO_SUB153                                   om_data153;
    BCL_SID_BCL_PDC_CFC_INFO_SUB154                                   om_data154;
    BCL_SID_BCL_PDC_CFC_INFO_SUB155                                   om_data155;
    BCL_SID_BCL_PDC_CFC_INFO_SUB156                                   om_data156;
    BCL_SID_BCL_PDC_CFC_INFO_SUB157                                   om_data157;
    BCL_SID_BCL_PDC_CFC_INFO_SUB158                                   om_data158;
    BCL_SID_BCL_PDC_CFC_INFO_SUB159                                   om_data159;
    BCL_SID_BCL_PDC_CFC_INFO_SUB160                                   om_data160;
    BCL_SID_BCL_PDC_CFC_INFO_SUB161                                   om_data161;
    BCL_SID_BCL_PDC_CFC_INFO_SUB162                                   om_data162;
    BCL_SID_BCL_PDC_CFC_INFO_SUB163                                   om_data163;
    BCL_SID_BCL_PDC_CFC_INFO_SUB164                                   om_data164;
    BCL_SID_BCL_PDC_CFC_INFO_SUB165                                   om_data165;
    BCL_SID_BCL_PDC_CFC_INFO_SUB166                                   om_data166;
    BCL_SID_BCL_PDC_CFC_INFO_SUB167                                   om_data167;
} BCL_SID_BCL_PDC_CFC_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_PDC_CFC_INFO_SUB0                                     om_data0;
    BCL_SID_BCL_PDC_CFC_INFO_SUB1                                     om_data1;
    BCL_SID_BCL_PDC_CFC_INFO_SUB2                                     om_data2;
    BCL_SID_BCL_PDC_CFC_INFO_SUB3                                     om_data3;
    BCL_SID_BCL_PDC_CFC_INFO_SUB4                                     om_data4;
    BCL_SID_BCL_PDC_CFC_INFO_SUB5                                     om_data5;
    BCL_SID_BCL_PDC_CFC_INFO_SUB6                                     om_data6;
    BCL_SID_BCL_PDC_CFC_INFO_SUB7                                     om_data7;
    BCL_SID_BCL_PDC_CFC_INFO_SUB8                                     om_data8;
    BCL_SID_BCL_PDC_CFC_INFO_SUB9                                     om_data9;
    BCL_SID_BCL_PDC_CFC_INFO_SUB10                                    om_data10;
    BCL_SID_BCL_PDC_CFC_INFO_SUB11                                    om_data11;
    BCL_SID_BCL_PDC_CFC_INFO_SUB12                                    om_data12;
    BCL_SID_BCL_PDC_CFC_INFO_SUB13                                    om_data13;
    BCL_SID_BCL_PDC_CFC_INFO_SUB14                                    om_data14;
    BCL_SID_BCL_PDC_CFC_INFO_SUB15                                    om_data15;
    BCL_SID_BCL_PDC_CFC_INFO_SUB16                                    om_data16;
    BCL_SID_BCL_PDC_CFC_INFO_SUB17                                    om_data17;
    BCL_SID_BCL_PDC_CFC_INFO_SUB18                                    om_data18;
    BCL_SID_BCL_PDC_CFC_INFO_SUB19                                    om_data19;
    BCL_SID_BCL_PDC_CFC_INFO_SUB20                                    om_data20;
    BCL_SID_BCL_PDC_CFC_INFO_SUB21                                    om_data21;
    BCL_SID_BCL_PDC_CFC_INFO_SUB22                                    om_data22;
    BCL_SID_BCL_PDC_CFC_INFO_SUB23                                    om_data23;
    BCL_SID_BCL_PDC_CFC_INFO_SUB24                                    om_data24;
    BCL_SID_BCL_PDC_CFC_INFO_SUB25                                    om_data25;
    BCL_SID_BCL_PDC_CFC_INFO_SUB26                                    om_data26;
    BCL_SID_BCL_PDC_CFC_INFO_SUB27                                    om_data27;
    BCL_SID_BCL_PDC_CFC_INFO_SUB28                                    om_data28;
    BCL_SID_BCL_PDC_CFC_INFO_SUB29                                    om_data29;
    BCL_SID_BCL_PDC_CFC_INFO_SUB30                                    om_data30;
    BCL_SID_BCL_PDC_CFC_INFO_SUB31                                    om_data31;
    BCL_SID_BCL_PDC_CFC_INFO_SUB32                                    om_data32;
    BCL_SID_BCL_PDC_CFC_INFO_SUB33                                    om_data33;
    BCL_SID_BCL_PDC_CFC_INFO_SUB34                                    om_data34;
    BCL_SID_BCL_PDC_CFC_INFO_SUB35                                    om_data35;
    BCL_SID_BCL_PDC_CFC_INFO_SUB36                                    om_data36;
    BCL_SID_BCL_PDC_CFC_INFO_SUB37                                    om_data37;
    BCL_SID_BCL_PDC_CFC_INFO_SUB38                                    om_data38;
    BCL_SID_BCL_PDC_CFC_INFO_SUB39                                    om_data39;
    BCL_SID_BCL_PDC_CFC_INFO_SUB40                                    om_data40;
    BCL_SID_BCL_PDC_CFC_INFO_SUB41                                    om_data41;
    BCL_SID_BCL_PDC_CFC_INFO_SUB42                                    om_data42;
    BCL_SID_BCL_PDC_CFC_INFO_SUB43                                    om_data43;
    BCL_SID_BCL_PDC_CFC_INFO_SUB44                                    om_data44;
    BCL_SID_BCL_PDC_CFC_INFO_SUB45                                    om_data45;
    BCL_SID_BCL_PDC_CFC_INFO_SUB46                                    om_data46;
    BCL_SID_BCL_PDC_CFC_INFO_SUB47                                    om_data47;
    BCL_SID_BCL_PDC_CFC_INFO_SUB48                                    om_data48;
    BCL_SID_BCL_PDC_CFC_INFO_SUB49                                    om_data49;
    BCL_SID_BCL_PDC_CFC_INFO_SUB50                                    om_data50;
    BCL_SID_BCL_PDC_CFC_INFO_SUB51                                    om_data51;
    BCL_SID_BCL_PDC_CFC_INFO_SUB52                                    om_data52;
    BCL_SID_BCL_PDC_CFC_INFO_SUB53                                    om_data53;
    BCL_SID_BCL_PDC_CFC_INFO_SUB54                                    om_data54;
    BCL_SID_BCL_PDC_CFC_INFO_SUB55                                    om_data55;
    BCL_SID_BCL_PDC_CFC_INFO_SUB56                                    om_data56;
    BCL_SID_BCL_PDC_CFC_INFO_SUB57                                    om_data57;
    BCL_SID_BCL_PDC_CFC_INFO_SUB58                                    om_data58;
    BCL_SID_BCL_PDC_CFC_INFO_SUB59                                    om_data59;
    BCL_SID_BCL_PDC_CFC_INFO_SUB60                                    om_data60;
    BCL_SID_BCL_PDC_CFC_INFO_SUB61                                    om_data61;
    BCL_SID_BCL_PDC_CFC_INFO_SUB62                                    om_data62;
    BCL_SID_BCL_PDC_CFC_INFO_SUB63                                    om_data63;
    BCL_SID_BCL_PDC_CFC_INFO_SUB64                                    om_data64;
    BCL_SID_BCL_PDC_CFC_INFO_SUB65                                    om_data65;
    BCL_SID_BCL_PDC_CFC_INFO_SUB66                                    om_data66;
    BCL_SID_BCL_PDC_CFC_INFO_SUB67                                    om_data67;
    BCL_SID_BCL_PDC_CFC_INFO_SUB68                                    om_data68;
    BCL_SID_BCL_PDC_CFC_INFO_SUB69                                    om_data69;
    BCL_SID_BCL_PDC_CFC_INFO_SUB70                                    om_data70;
    BCL_SID_BCL_PDC_CFC_INFO_SUB71                                    om_data71;
    BCL_SID_BCL_PDC_CFC_INFO_SUB72                                    om_data72;
    BCL_SID_BCL_PDC_CFC_INFO_SUB73                                    om_data73;
    BCL_SID_BCL_PDC_CFC_INFO_SUB74                                    om_data74;
    BCL_SID_BCL_PDC_CFC_INFO_SUB75                                    om_data75;
    BCL_SID_BCL_PDC_CFC_INFO_SUB76                                    om_data76;
    BCL_SID_BCL_PDC_CFC_INFO_SUB77                                    om_data77;
    BCL_SID_BCL_PDC_CFC_INFO_SUB78                                    om_data78;
    BCL_SID_BCL_PDC_CFC_INFO_SUB79                                    om_data79;
    BCL_SID_BCL_PDC_CFC_INFO_SUB80                                    om_data80;
    BCL_SID_BCL_PDC_CFC_INFO_SUB81                                    om_data81;
    BCL_SID_BCL_PDC_CFC_INFO_SUB82                                    om_data82;
    BCL_SID_BCL_PDC_CFC_INFO_SUB83                                    om_data83;
    BCL_SID_BCL_PDC_CFC_INFO_SUB84                                    om_data84;
    BCL_SID_BCL_PDC_CFC_INFO_SUB85                                    om_data85;
    BCL_SID_BCL_PDC_CFC_INFO_SUB86                                    om_data86;
    BCL_SID_BCL_PDC_CFC_INFO_SUB87                                    om_data87;
    BCL_SID_BCL_PDC_CFC_INFO_SUB88                                    om_data88;
    BCL_SID_BCL_PDC_CFC_INFO_SUB89                                    om_data89;
    BCL_SID_BCL_PDC_CFC_INFO_SUB90                                    om_data90;
    BCL_SID_BCL_PDC_CFC_INFO_SUB91                                    om_data91;
    BCL_SID_BCL_PDC_CFC_INFO_SUB92                                    om_data92;
    BCL_SID_BCL_PDC_CFC_INFO_SUB93                                    om_data93;
    BCL_SID_BCL_PDC_CFC_INFO_SUB94                                    om_data94;
    BCL_SID_BCL_PDC_CFC_INFO_SUB95                                    om_data95;
    BCL_SID_BCL_PDC_CFC_INFO_SUB96                                    om_data96;
    BCL_SID_BCL_PDC_CFC_INFO_SUB97                                    om_data97;
    BCL_SID_BCL_PDC_CFC_INFO_SUB98                                    om_data98;
    BCL_SID_BCL_PDC_CFC_INFO_SUB99                                    om_data99;
    BCL_SID_BCL_PDC_CFC_INFO_SUB100                                   om_data100;
    BCL_SID_BCL_PDC_CFC_INFO_SUB101                                   om_data101;
    BCL_SID_BCL_PDC_CFC_INFO_SUB102                                   om_data102;
    BCL_SID_BCL_PDC_CFC_INFO_SUB103                                   om_data103;
    BCL_SID_BCL_PDC_CFC_INFO_SUB104                                   om_data104;
    BCL_SID_BCL_PDC_CFC_INFO_SUB105                                   om_data105;
    BCL_SID_BCL_PDC_CFC_INFO_SUB106                                   om_data106;
    BCL_SID_BCL_PDC_CFC_INFO_SUB107                                   om_data107;
    BCL_SID_BCL_PDC_CFC_INFO_SUB108                                   om_data108;
    BCL_SID_BCL_PDC_CFC_INFO_SUB109                                   om_data109;
    BCL_SID_BCL_PDC_CFC_INFO_SUB110                                   om_data110;
    BCL_SID_BCL_PDC_CFC_INFO_SUB111                                   om_data111;
    BCL_SID_BCL_PDC_CFC_INFO_SUB112                                   om_data112;
    BCL_SID_BCL_PDC_CFC_INFO_SUB113                                   om_data113;
    BCL_SID_BCL_PDC_CFC_INFO_SUB114                                   om_data114;
    BCL_SID_BCL_PDC_CFC_INFO_SUB115                                   om_data115;
    BCL_SID_BCL_PDC_CFC_INFO_SUB116                                   om_data116;
    BCL_SID_BCL_PDC_CFC_INFO_SUB117                                   om_data117;
    BCL_SID_BCL_PDC_CFC_INFO_SUB118                                   om_data118;
    BCL_SID_BCL_PDC_CFC_INFO_SUB119                                   om_data119;
    BCL_SID_BCL_PDC_CFC_INFO_SUB120                                   om_data120;
    BCL_SID_BCL_PDC_CFC_INFO_SUB121                                   om_data121;
    BCL_SID_BCL_PDC_CFC_INFO_SUB122                                   om_data122;
    BCL_SID_BCL_PDC_CFC_INFO_SUB123                                   om_data123;
    BCL_SID_BCL_PDC_CFC_INFO_SUB124                                   om_data124;
    BCL_SID_BCL_PDC_CFC_INFO_SUB125                                   om_data125;
    BCL_SID_BCL_PDC_CFC_INFO_SUB126                                   om_data126;
    BCL_SID_BCL_PDC_CFC_INFO_SUB127                                   om_data127;
    BCL_SID_BCL_PDC_CFC_INFO_SUB128                                   om_data128;
    BCL_SID_BCL_PDC_CFC_INFO_SUB129                                   om_data129;
    BCL_SID_BCL_PDC_CFC_INFO_SUB130                                   om_data130;
    BCL_SID_BCL_PDC_CFC_INFO_SUB131                                   om_data131;
    BCL_SID_BCL_PDC_CFC_INFO_SUB132                                   om_data132;
    BCL_SID_BCL_PDC_CFC_INFO_SUB133                                   om_data133;
    BCL_SID_BCL_PDC_CFC_INFO_SUB134                                   om_data134;
    BCL_SID_BCL_PDC_CFC_INFO_SUB135                                   om_data135;
    BCL_SID_BCL_PDC_CFC_INFO_SUB136                                   om_data136;
    BCL_SID_BCL_PDC_CFC_INFO_SUB137                                   om_data137;
    BCL_SID_BCL_PDC_CFC_INFO_SUB138                                   om_data138;
    BCL_SID_BCL_PDC_CFC_INFO_SUB139                                   om_data139;
    BCL_SID_BCL_PDC_CFC_INFO_SUB140                                   om_data140;
    BCL_SID_BCL_PDC_CFC_INFO_SUB141                                   om_data141;
    BCL_SID_BCL_PDC_CFC_INFO_SUB142                                   om_data142;
    BCL_SID_BCL_PDC_CFC_INFO_SUB143                                   om_data143;
    BCL_SID_BCL_PDC_CFC_INFO_SUB144                                   om_data144;
    BCL_SID_BCL_PDC_CFC_INFO_SUB145                                   om_data145;
    BCL_SID_BCL_PDC_CFC_INFO_SUB146                                   om_data146;
    BCL_SID_BCL_PDC_CFC_INFO_SUB147                                   om_data147;
    BCL_SID_BCL_PDC_CFC_INFO_SUB148                                   om_data148;
    BCL_SID_BCL_PDC_CFC_INFO_SUB149                                   om_data149;
    BCL_SID_BCL_PDC_CFC_INFO_SUB150                                   om_data150;
    BCL_SID_BCL_PDC_CFC_INFO_SUB151                                   om_data151;
    BCL_SID_BCL_PDC_CFC_INFO_SUB152                                   om_data152;
    BCL_SID_BCL_PDC_CFC_INFO_SUB153                                   om_data153;
    BCL_SID_BCL_PDC_CFC_INFO_SUB154                                   om_data154;
    BCL_SID_BCL_PDC_CFC_INFO_SUB155                                   om_data155;
    BCL_SID_BCL_PDC_CFC_INFO_SUB156                                   om_data156;
    BCL_SID_BCL_PDC_CFC_INFO_SUB157                                   om_data157;
    BCL_SID_BCL_PDC_CFC_INFO_SUB158                                   om_data158;
    BCL_SID_BCL_PDC_CFC_INFO_SUB159                                   om_data159;
    BCL_SID_BCL_PDC_CFC_INFO_SUB160                                   om_data160;
    BCL_SID_BCL_PDC_CFC_INFO_SUB161                                   om_data161;
    BCL_SID_BCL_PDC_CFC_INFO_SUB162                                   om_data162;
    BCL_SID_BCL_PDC_CFC_INFO_SUB163                                   om_data163;
    BCL_SID_BCL_PDC_CFC_INFO_SUB164                                   om_data164;
    BCL_SID_BCL_PDC_CFC_INFO_SUB165                                   om_data165;
    BCL_SID_BCL_PDC_CFC_INFO_SUB166                                   om_data166;
    BCL_SID_BCL_PDC_CFC_INFO_SUB167                                   om_data167;
} BCL_SID_BCL_PDC_CFC_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      reserved_0;
} BCL_SID_BCL_PDC_EN_CLR;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      reserved_0;
} BCL_SID_BCL_PDC_EN_CLR_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      phi0_z1_lo;
    unsigned int                                                      phi0_z1_hi;
    unsigned int                                                      phi1_z1_lo;
    unsigned int                                                      phi1_z1_hi;
    unsigned int                                                      phi2_z1_lo;
    unsigned int                                                      phi2_z1_hi;
    unsigned int                                                      phi3_z1_lo;
    unsigned int                                                      phi3_z1_hi;
    unsigned int                                                      phi0_z2_lo;
    unsigned int                                                      phi0_z2_hi;
    unsigned int                                                      phi1_z2_lo;
    unsigned int                                                      phi1_z2_hi;
    unsigned int                                                      phi2_z2_lo;
    unsigned int                                                      phi2_z2_hi;
    unsigned int                                                      phi3_z2_lo;
    unsigned int                                                      phi3_z2_hi;
} BCL_SID_BCL_PHI_Z;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      phi0_z1_lo;
    unsigned int                                                      phi0_z1_hi;
    unsigned int                                                      phi1_z1_lo;
    unsigned int                                                      phi1_z1_hi;
    unsigned int                                                      phi2_z1_lo;
    unsigned int                                                      phi2_z1_hi;
    unsigned int                                                      phi3_z1_lo;
    unsigned int                                                      phi3_z1_hi;
    unsigned int                                                      phi0_z2_lo;
    unsigned int                                                      phi0_z2_hi;
    unsigned int                                                      phi1_z2_lo;
    unsigned int                                                      phi1_z2_hi;
    unsigned int                                                      phi2_z2_lo;
    unsigned int                                                      phi2_z2_hi;
    unsigned int                                                      phi3_z2_lo;
    unsigned int                                                      phi3_z2_hi;
} BCL_SID_BCL_PHI_Z_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      vdl_pdc_info0;
    unsigned int                                                      vdl_pdc_info1;
    unsigned int                                                      vdl_pdc_info2;
    unsigned int                                                      vdl_pdc_info3;
    unsigned int                                                      vdl_pdc_info4;
    unsigned int                                                      vdl_pdc_info5;
    unsigned int                                                      vdl_pdc_info6;
    unsigned int                                                      vdl_pdc_info7;
    unsigned int                                                      vdl_pdc_info8;
    unsigned int                                                      vdl_pdc_info9;
    unsigned int                                                      vdl_pdc_info10;
    unsigned int                                                      vdl_pdc_info11;
    unsigned int                                                      vdl_pdc_info12;
    unsigned int                                                      vdl_pdc_info13;
    unsigned int                                                      vdl_pdc_info14;
    unsigned int                                                      vdl_pdc_info15;
    unsigned int                                                      vdl_pdc_info16;
    unsigned int                                                      vdl_pdc_info17;
} BCL_SID_BCL_VDL_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      vdl_pdc_info0;
    unsigned int                                                      vdl_pdc_info1;
    unsigned int                                                      vdl_pdc_info2;
    unsigned int                                                      vdl_pdc_info3;
    unsigned int                                                      vdl_pdc_info4;
    unsigned int                                                      vdl_pdc_info5;
    unsigned int                                                      vdl_pdc_info6;
    unsigned int                                                      vdl_pdc_info7;
    unsigned int                                                      vdl_pdc_info8;
    unsigned int                                                      vdl_pdc_info9;
    unsigned int                                                      vdl_pdc_info10;
    unsigned int                                                      vdl_pdc_info11;
    unsigned int                                                      vdl_pdc_info12;
    unsigned int                                                      vdl_pdc_info13;
    unsigned int                                                      vdl_pdc_info14;
    unsigned int                                                      vdl_pdc_info15;
    unsigned int                                                      vdl_pdc_info16;
    unsigned int                                                      vdl_pdc_info17;
} BCL_SID_BCL_VDL_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int pb_pdma_id                                       :   10              ;    /* 9:0 */
        unsigned int pdc_egy_pdma_id                                  :   10              ;    /* 19:10 */
        unsigned int pdc_data_pdma_id                                 :   10              ;    /* 29:20 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_LTE_PB_INIT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_LTE_PB_INIT_SUB0                                      om_data0;
    unsigned int                                                      pb_llr_addr;
} BCL_SID_BCL_LTE_PB_INIT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_LTE_PB_INIT_SUB0                                      om_data0;
    unsigned int                                                      pb_llr_addr;
} BCL_SID_BCL_LTE_PB_INIT_BBP_MC;

typedef union {
    struct {
        unsigned int pb_cfg_en                                        :   1               ;    /* 0 */
        unsigned int pb_cfg_pos                                       :   1               ;    /* 1 */
        unsigned int reserved_0                                       :   30              ;    /* 31:2 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_LTE_PB_IN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pevent;
    BCL_SID_BCL_LTE_PB_IN_SUB1                                        om_data1;
} BCL_SID_BCL_LTE_PB_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pevent;
    BCL_SID_BCL_LTE_PB_IN_SUB1                                        om_data1;
} BCL_SID_BCL_LTE_PB_IN_BBP_MC;

typedef union {
    struct {
        unsigned int reserved_0                                       :   1               ;    /* 0 */
        unsigned int pb_ic_mode                                       :   1               ;    /* 1 */
        unsigned int pb_type_flag                                     :   1               ;    /* 2 */
        unsigned int reserved_1                                       :   2               ;    /* 4:3 */
        unsigned int pb_rx_flag                                       :   2               ;    /* 6:5 */
        unsigned int pb_crs_port                                      :   2               ;    /* 8:7 */
        unsigned int pb_rb_num                                        :   3               ;    /* 11:9 */
        unsigned int pb_subfrm_num                                    :   4               ;    /* 15:12 */
        unsigned int pb_cp_mode                                       :   1               ;    /* 16 */
        unsigned int reserved_2                                       :   3               ;    /* 19:17 */
        unsigned int reserved_3                                       :   9               ;    /* 28:20 */
        unsigned int pb_vshift                                        :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_LTE_PB_CFG_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_LTE_PB_CFG_SUB0                                       om_data0;
    unsigned int                                                      reserved_0;
} BCL_SID_BCL_LTE_PB_CFG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_LTE_PB_CFG_SUB0                                       om_data0;
    unsigned int                                                      reserved_0;
} BCL_SID_BCL_LTE_PB_CFG_BBP_MC;

typedef union {
    struct {
        unsigned int length                                           :   16              ;    /* 15:0 */
        unsigned int step                                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_LTE_PB_CMD_SUB0;

typedef union {
    struct {
        unsigned int pb_cmd_v                                         :   1               ;    /* 0 */
        unsigned int pb_res_ind                                       :   2               ;    /* 2:1 */
        unsigned int cp_type_cur                                      :   1               ;    /* 3 */
        unsigned int pb_tskid                                         :   4               ;    /* 7:4 */
        unsigned int pb_ante                                          :   2               ;    /* 9:8 */
        unsigned int reserved_0                                       :   9               ;    /* 18:10 */
        unsigned int reserved_1                                       :   5               ;    /* 23:19 */
        unsigned int pb_new                                           :   1               ;    /* 24 */
        unsigned int pb_data_checker_en                               :   1               ;    /* 25 */
        unsigned int pb_bd_sel                                        :   1               ;    /* 26 */
        unsigned int reserved_2                                       :   1               ;    /* 27 */
        unsigned int pb_tti                                           :   2               ;    /* 29:28 */
        unsigned int pb_scen_cur                                      :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_LTE_PB_CMD_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_LTE_PB_CMD_SUB0                                       om_data0;
    BCL_SID_BCL_LTE_PB_CMD_SUB1                                       om_data1;
} BCL_SID_BCL_LTE_PB_CMD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_LTE_PB_CMD_SUB0                                       om_data0;
    BCL_SID_BCL_LTE_PB_CMD_SUB1                                       om_data1;
} BCL_SID_BCL_LTE_PB_CMD_BBP_MC;

typedef union {
    struct {
        unsigned int pb_ic_cfg_idx                                    :   4               ;    /* 3:0 */
        unsigned int pb_ic_idx                                        :   4               ;    /* 7:4 */
        unsigned int reserved_0                                       :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_LTE_PB_IC_IN_SUB0;

typedef union {
    struct {
        unsigned int pb_ic_en                                         :   1               ;    /* 0 */
        unsigned int pb_ic_en_p                                       :   1               ;    /* 1 */
        unsigned int pb_ic_en_s                                       :   1               ;    /* 2 */
        unsigned int reserved_0                                       :   29              ;    /* 31:3 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_LTE_PB_IC_IN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_LTE_PB_IC_IN_SUB0                                     om_data0;
    BCL_SID_BCL_LTE_PB_IC_IN_SUB1                                     om_data1;
} BCL_SID_BCL_LTE_PB_IC_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_LTE_PB_IC_IN_SUB0                                     om_data0;
    BCL_SID_BCL_LTE_PB_IC_IN_SUB1                                     om_data1;
} BCL_SID_BCL_LTE_PB_IC_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pb_ic_rpt_param_word0;
    unsigned int                                                      pb_ic_rpt_param_word3;
} BCL_SID_BCL_LTE_PB_IC_DONE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pb_ic_rpt_param_word0;
    unsigned int                                                      pb_ic_rpt_param_word3;
} BCL_SID_BCL_LTE_PB_IC_DONE_BBP_MC;

typedef union {
    struct {
        unsigned int ovb2pdl_bd_num                                   :   8               ;    /* 7:0 */
        unsigned int ovb_span_bd_num                                  :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_OVB_SSS_INFO_SUB0;

typedef union {
    struct {
        unsigned int ovb_ss_active_cnt                                :   8               ;    /* 7:0 */
        unsigned int ovb_ovflw_flag                                   :   1               ;    /* 8 */
        unsigned int reserved_0                                       :   23              ;    /* 31:9 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_OVB_SSS_INFO_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_OVB_SSS_INFO_SUB0                                     om_data0;
    BCL_SID_BCL_OVB_SSS_INFO_SUB1                                     om_data1;
} BCL_SID_BCL_OVB_SSS_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_OVB_SSS_INFO_SUB0                                     om_data0;
    BCL_SID_BCL_OVB_SSS_INFO_SUB1                                     om_data1;
} BCL_SID_BCL_OVB_SSS_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int ovb2che_sym_bmp_cst0                             :   16              ;    /* 15:0 */
        unsigned int ovb2che_sym_bmp_cst1                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_OVB_SYMB_INFO_SUB0;

typedef union {
    struct {
        unsigned int ovb2che_sym_bmp_cst2                             :   16              ;    /* 15:0 */
        unsigned int ovb2che_curr_cfg_idx                             :   4               ;    /* 19:16 */
        unsigned int ovb2che_scheduling_cfg_idx                       :   4               ;    /* 23:20 */
        unsigned int ovb2che_ctrl_cfg_idx                             :   4               ;    /* 27:24 */
        unsigned int ovb2che_pingpang_flag                            :   1               ;    /* 28 */
        unsigned int ovb2che_bd_vld                                   :   1               ;    /* 29 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_OVB_SYMB_INFO_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_OVB_SYMB_INFO_SUB0                                    om_data0;
    BCL_SID_BCL_OVB_SYMB_INFO_SUB1                                    om_data1;
} BCL_SID_BCL_OVB_SYMB_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_OVB_SYMB_INFO_SUB0                                    om_data0;
    BCL_SID_BCL_OVB_SYMB_INFO_SUB1                                    om_data1;
} BCL_SID_BCL_OVB_SYMB_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ovb2pdl_info0;
    unsigned int                                                      ovb2pdl_info1;
    unsigned int                                                      ovb2pdl_info2;
    unsigned int                                                      ovb2pdl_info3;
    unsigned int                                                      ovb2pdl_info4;
    unsigned int                                                      ovb2pdl_info5;
    unsigned int                                                      ovb2pdl_info6;
    unsigned int                                                      ovb2pdl_info7;
    unsigned int                                                      ovb2pdl_info8;
    unsigned int                                                      ovb2pdl_info9;
    unsigned int                                                      ovb2pdl_info10;
    unsigned int                                                      ovb2pdl_info11;
    unsigned int                                                      ovb2pdl_info12;
    unsigned int                                                      ovb2pdl_info13;
    unsigned int                                                      ovb2pdl_info14;
    unsigned int                                                      ovb2pdl_info15;
    unsigned int                                                      ovb2pdl_info16;
    unsigned int                                                      ovb2pdl_info17;
    unsigned int                                                      ovb2pdl_info18;
    unsigned int                                                      ovb2pdl_info19;
    unsigned int                                                      ovb2pdl_info20;
    unsigned int                                                      ovb2pdl_info21;
    unsigned int                                                      ovb2pdl_info22;
    unsigned int                                                      ovb2pdl_info23;
    unsigned int                                                      ovb2pdl_info24;
    unsigned int                                                      ovb2pdl_info25;
    unsigned int                                                      ovb2pdl_info26;
    unsigned int                                                      ovb2pdl_info27;
    unsigned int                                                      ovb2pdl_info28;
    unsigned int                                                      ovb2pdl_info29;
    unsigned int                                                      ovb2pdl_info30;
    unsigned int                                                      ovb2pdl_info31;
} BCL_SID_BCL_OVB_PDL_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ovb2pdl_info0;
    unsigned int                                                      ovb2pdl_info1;
    unsigned int                                                      ovb2pdl_info2;
    unsigned int                                                      ovb2pdl_info3;
    unsigned int                                                      ovb2pdl_info4;
    unsigned int                                                      ovb2pdl_info5;
    unsigned int                                                      ovb2pdl_info6;
    unsigned int                                                      ovb2pdl_info7;
    unsigned int                                                      ovb2pdl_info8;
    unsigned int                                                      ovb2pdl_info9;
    unsigned int                                                      ovb2pdl_info10;
    unsigned int                                                      ovb2pdl_info11;
    unsigned int                                                      ovb2pdl_info12;
    unsigned int                                                      ovb2pdl_info13;
    unsigned int                                                      ovb2pdl_info14;
    unsigned int                                                      ovb2pdl_info15;
    unsigned int                                                      ovb2pdl_info16;
    unsigned int                                                      ovb2pdl_info17;
    unsigned int                                                      ovb2pdl_info18;
    unsigned int                                                      ovb2pdl_info19;
    unsigned int                                                      ovb2pdl_info20;
    unsigned int                                                      ovb2pdl_info21;
    unsigned int                                                      ovb2pdl_info22;
    unsigned int                                                      ovb2pdl_info23;
    unsigned int                                                      ovb2pdl_info24;
    unsigned int                                                      ovb2pdl_info25;
    unsigned int                                                      ovb2pdl_info26;
    unsigned int                                                      ovb2pdl_info27;
    unsigned int                                                      ovb2pdl_info28;
    unsigned int                                                      ovb2pdl_info29;
    unsigned int                                                      ovb2pdl_info30;
    unsigned int                                                      ovb2pdl_info31;
} BCL_SID_BCL_OVB_PDL_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int ovb2pdl_nrch_idx                                 :   4               ;    /* 3:0 */
        unsigned int ovb2che_pde_idx                                  :   1               ;    /* 4 */
        unsigned int ovb2dcicp_rpt_cfg_idx                            :   3               ;    /* 7:5 */
        unsigned int ovb2dcicp_p_ofst                                 :   4               ;    /* 11:8 */
        unsigned int reserved_0                                       :   3               ;    /* 14:12 */
        unsigned int ovb2dcicp_scheduled_flag                         :   1               ;    /* 15 */
        unsigned int ovb2che_span_type                                :   3               ;    /* 18:16 */
        unsigned int ovb2pdl_span_flag                                :   1               ;    /* 19 */
        unsigned int ovb2dcicp_pdc_slot_num                           :   9               ;    /* 28:20 */
        unsigned int reserved_1                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_OVB_DCICP_INFO_SUB0;

typedef union {
    struct {
        unsigned int ovb2dcicp_endsym_map                             :   14              ;    /* 13:0 */
        unsigned int reserved_0                                       :   18              ;    /* 31:14 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_OVB_DCICP_INFO_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_OVB_DCICP_INFO_SUB0                                   om_data0;
    BCL_SID_BCL_OVB_DCICP_INFO_SUB1                                   om_data1;
} BCL_SID_BCL_OVB_DCICP_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_OVB_DCICP_INFO_SUB0                                   om_data0;
    BCL_SID_BCL_OVB_DCICP_INFO_SUB1                                   om_data1;
} BCL_SID_BCL_OVB_DCICP_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tops2ovb_cfg_idx                                 :   3               ;    /* 2:0 */
        unsigned int tops2ovb_pp_flag                                 :   1               ;    /* 3 */
        unsigned int tops2ovb_rrc_bitmap                              :   5               ;    /* 8:4 */
        unsigned int tops2ovb_cfg_idx_s                               :   3               ;    /* 11:9 */
        unsigned int tops2ovb_pp_flag_s                               :   1               ;    /* 12 */
        unsigned int reserved_0                                       :   1               ;    /* 13 */
        unsigned int tops2ovb_ovb_flag                                :   1               ;    /* 14 */
        unsigned int tops2ovb_ovb_mode                                :   1               ;    /* 15 */
        unsigned int reserved_1                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_OVB_TOPS_INFO_SUB0;

typedef union {
    struct {
        unsigned int ovb2tops_cfg_idx                                 :   3               ;    /* 2:0 */
        unsigned int ovb2tops_pp_flag                                 :   1               ;    /* 3 */
        unsigned int ovb2tops_rrc_bitmap                              :   5               ;    /* 8:4 */
        unsigned int ovb2tops_cfg_idx_s                               :   3               ;    /* 11:9 */
        unsigned int ovb2tops_pp_flag_s                               :   1               ;    /* 12 */
        unsigned int ovb2tops_dcicp_symb0_flag                        :   1               ;    /* 13 */
        unsigned int ovb2tops_ovb_flag                                :   1               ;    /* 14 */
        unsigned int ovb2tops_ovb_mode                                :   1               ;    /* 15 */
        unsigned int ovb2tops_cfc_flag                                :   1               ;    /* 16 */
        unsigned int ovb2tops_cfc_info                                :   7               ;    /* 23:17 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} BCL_SID_BCL_OVB_TOPS_INFO_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    BCL_SID_BCL_OVB_TOPS_INFO_SUB0                                    om_data0;
    BCL_SID_BCL_OVB_TOPS_INFO_SUB1                                    om_data1;
} BCL_SID_BCL_OVB_TOPS_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    BCL_SID_BCL_OVB_TOPS_INFO_SUB0                                    om_data0;
    BCL_SID_BCL_OVB_TOPS_INFO_SUB1                                    om_data1;
} BCL_SID_BCL_OVB_TOPS_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} BCL_SID_BCL_OVB_PROTECT_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} BCL_SID_BCL_OVB_PROTECT_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ovb_glb_protect_cfg0;
    unsigned int                                                      ovb_glb_protect_cfg1;
    unsigned int                                                      ovb_glb_protect_cfg2;
    unsigned int                                                      ovb_glb_protect_cfg3;
    unsigned int                                                      ovb_glb_protect_cfg4;
    unsigned int                                                      ovb_glb_clr_gch0;
    unsigned int                                                      ovb_glb_clr_gch1;
    unsigned int                                                      ovb_glb_clr_gch2;
    unsigned int                                                      ovb_glb_clr_gch3;
    unsigned int                                                      ovb_glb_clr_gch4;
} BCL_SID_BCL_OVB_GLB_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ovb_glb_protect_cfg0;
    unsigned int                                                      ovb_glb_protect_cfg1;
    unsigned int                                                      ovb_glb_protect_cfg2;
    unsigned int                                                      ovb_glb_protect_cfg3;
    unsigned int                                                      ovb_glb_protect_cfg4;
    unsigned int                                                      ovb_glb_clr_gch0;
    unsigned int                                                      ovb_glb_clr_gch1;
    unsigned int                                                      ovb_glb_clr_gch2;
    unsigned int                                                      ovb_glb_clr_gch3;
    unsigned int                                                      ovb_glb_clr_gch4;
} BCL_SID_BCL_OVB_GLB_INFO_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
