

#ifndef __UPHY_PDE_PDS_OM_H__
#define __UPHY_PDE_PDS_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      p_crs_drs_flag;
    unsigned int                                                      reserved_0;
} PDS_SID_PDS_LTE_P_MOVE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_crs_drs_flag;
    unsigned int                                                      reserved_0;
} PDS_SID_PDS_LTE_P_MOVE_BBP_MC;

typedef union {
    struct {
        unsigned int pds_config_done                                  :   1               ;    /* 0:0 */
        unsigned int reserved0_0                                      :   15              ;    /* 15:1 */
        unsigned int demap_sym_en                                     :   14              ;    /* 29:16 */
        unsigned int reserved1_1                                      :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_LTE_CFG_DEMAP_SUB0;

typedef union {
    struct {
        unsigned int fpds_ch0_cw_num                                  :   1               ;    /* 0 */
        unsigned int fpds_ch0_cw1_shift                               :   5               ;    /* 5:1 */
        unsigned int reserved_0                                       :   2               ;    /* 7:6 */
        unsigned int fpds_ch0_mode                                    :   1               ;    /* 8 */
        unsigned int fpds_ch0_sfbc_flag                               :   1               ;    /* 9 */
        unsigned int fpds_ch0_cw0_shift                               :   5               ;    /* 14:10 */
        unsigned int reserved_1                                       :   1               ;    /* 15 */
        unsigned int fpds_ch1_mode                                    :   1               ;    /* 16 */
        unsigned int fpds_ch1_sfbc_flag                               :   1               ;    /* 17 */
        unsigned int fpds_ch1_shift                                   :   5               ;    /* 22:18 */
        unsigned int reserved_2                                       :   1               ;    /* 23 */
        unsigned int fpds_ch2_mode                                    :   1               ;    /* 24 */
        unsigned int fpds_ch2_sfbc_flag                               :   1               ;    /* 25 */
        unsigned int fpds_ch2_shift                                   :   5               ;    /* 30:26 */
        unsigned int reserved_3                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_LTE_CFG_DEMAP_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_LTE_CFG_DEMAP_SUB0                                    om_data0;
    PDS_SID_PDS_LTE_CFG_DEMAP_SUB1                                    om_data1;
} PDS_SID_PDS_LTE_CFG_DEMAP;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_LTE_CFG_DEMAP_SUB0                                    om_data0;
    PDS_SID_PDS_LTE_CFG_DEMAP_SUB1                                    om_data1;
} PDS_SID_PDS_LTE_CFG_DEMAP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rs_type;
    unsigned int                                                      ode_even_flag;
} PDS_SID_PDS_LTE_CFC_CALC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rs_type;
    unsigned int                                                      ode_even_flag;
} PDS_SID_PDS_LTE_CFC_CALC_BBP_MC;

typedef union {
    struct {
        unsigned int llr_tau_scale                                    :   7               ;    /* 6:0 */
        unsigned int llr_llrt_scale                                   :   5               ;    /* 11:7 */
        unsigned int llr_mean_scale                                   :   10              ;    /* 21:12 */
        unsigned int dec_d                                            :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_LTE_DDL_PARA_SUB0;

typedef union {
    struct {
        unsigned int itr_max_tms                                      :   9               ;    /* 8:0 */
        unsigned int itr_avr_tms                                      :   9               ;    /* 17:9 */
        unsigned int reserved_0                                       :   14              ;    /* 31:18 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_LTE_DDL_PARA_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_LTE_DDL_PARA_SUB0                                     om_data0;
    PDS_SID_PDS_LTE_DDL_PARA_SUB1                                     om_data1;
} PDS_SID_PDS_LTE_DDL_PARA;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_LTE_DDL_PARA_SUB0                                     om_data0;
    PDS_SID_PDS_LTE_DDL_PARA_SUB1                                     om_data1;
} PDS_SID_PDS_LTE_DDL_PARA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      h_calc_cmd0_lo;
    unsigned int                                                      h_calc_cmd0_hi;
    unsigned int                                                      h_calc_cmd1_lo;
    unsigned int                                                      h_calc_cmd1_hi;
    unsigned int                                                      h_calc_cmd2_lo;
    unsigned int                                                      h_calc_cmd2_hi;
    unsigned int                                                      h_calc_cmd3_lo;
    unsigned int                                                      h_calc_cmd3_hi;
    unsigned int                                                      h_calc_cmd4_lo;
    unsigned int                                                      h_calc_cmd4_hi;
    unsigned int                                                      h_calc_cmd5_lo;
    unsigned int                                                      h_calc_cmd5_hi;
    unsigned int                                                      h_calc_cmd6_lo;
    unsigned int                                                      h_calc_cmd6_hi;
    unsigned int                                                      h_calc_cmd7_lo;
    unsigned int                                                      h_calc_cmd7_hi;
    unsigned int                                                      h_calc_cmd8_lo;
    unsigned int                                                      h_calc_cmd8_hi;
    unsigned int                                                      h_calc_cmd9_lo;
    unsigned int                                                      h_calc_cmd9_hi;
    unsigned int                                                      h_calc_cmd10_lo;
    unsigned int                                                      h_calc_cmd10_hi;
    unsigned int                                                      h_calc_cmd11_lo;
    unsigned int                                                      h_calc_cmd11_hi;
    unsigned int                                                      h_calc_cmd12_lo;
    unsigned int                                                      h_calc_cmd12_hi;
    unsigned int                                                      h_calc_cmd13_lo;
    unsigned int                                                      h_calc_cmd13_hi;
    unsigned int                                                      h_calc_cmd14_lo;
    unsigned int                                                      h_calc_cmd14_hi;
    unsigned int                                                      h_calc_cmd15_lo;
    unsigned int                                                      h_calc_cmd15_hi;
} PDS_SID_PDS_LTE_HCALC_DBG_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      h_calc_cmd0_lo;
    unsigned int                                                      h_calc_cmd0_hi;
    unsigned int                                                      h_calc_cmd1_lo;
    unsigned int                                                      h_calc_cmd1_hi;
    unsigned int                                                      h_calc_cmd2_lo;
    unsigned int                                                      h_calc_cmd2_hi;
    unsigned int                                                      h_calc_cmd3_lo;
    unsigned int                                                      h_calc_cmd3_hi;
    unsigned int                                                      h_calc_cmd4_lo;
    unsigned int                                                      h_calc_cmd4_hi;
    unsigned int                                                      h_calc_cmd5_lo;
    unsigned int                                                      h_calc_cmd5_hi;
    unsigned int                                                      h_calc_cmd6_lo;
    unsigned int                                                      h_calc_cmd6_hi;
    unsigned int                                                      h_calc_cmd7_lo;
    unsigned int                                                      h_calc_cmd7_hi;
    unsigned int                                                      h_calc_cmd8_lo;
    unsigned int                                                      h_calc_cmd8_hi;
    unsigned int                                                      h_calc_cmd9_lo;
    unsigned int                                                      h_calc_cmd9_hi;
    unsigned int                                                      h_calc_cmd10_lo;
    unsigned int                                                      h_calc_cmd10_hi;
    unsigned int                                                      h_calc_cmd11_lo;
    unsigned int                                                      h_calc_cmd11_hi;
    unsigned int                                                      h_calc_cmd12_lo;
    unsigned int                                                      h_calc_cmd12_hi;
    unsigned int                                                      h_calc_cmd13_lo;
    unsigned int                                                      h_calc_cmd13_hi;
    unsigned int                                                      h_calc_cmd14_lo;
    unsigned int                                                      h_calc_cmd14_hi;
    unsigned int                                                      h_calc_cmd15_lo;
    unsigned int                                                      h_calc_cmd15_hi;
} PDS_SID_PDS_LTE_HCALC_DBG_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      task_num;
    unsigned int                                                      cmd_rb_num;
} PDS_SID_PDS_LTE_CALC_CMD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      task_num;
    unsigned int                                                      cmd_rb_num;
} PDS_SID_PDS_LTE_CALC_CMD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      odd_even_flag;
    unsigned int                                                      lte_cfg_idx;
} PDS_SID_PDC_LTE_TASK1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      odd_even_flag;
    unsigned int                                                      lte_cfg_idx;
} PDS_SID_PDC_LTE_TASK1_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      odd_even_flag;
    unsigned int                                                      reserved_0;
} PDS_SID_PDC_LTE_CFC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      odd_even_flag;
    unsigned int                                                      reserved_0;
} PDS_SID_PDC_LTE_CFC_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   4               ;    /* 3:0 */
        unsigned int odd_even_flag                                    :   4               ;    /* 7:4 */
        unsigned int cfg_idx_tmp                                      :   4               ;    /* 11:8 */
        unsigned int pch_core_sel                                     :   4               ;    /* 15:12 */
        unsigned int pds_ch_typ                                       :   4               ;    /* 19:16 */
        unsigned int slot_idx                                         :   4               ;    /* 23:20 */
        unsigned int cfg_idx_uesd                                     :   4               ;    /* 27:24 */
        unsigned int fpds_card_flag                                   :   2               ;    /* 29:28 */
        unsigned int null_frm_flag                                    :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_DEMAP_TASK_SUB0;

typedef union {
    struct {
        unsigned int fpds_ch0_cw_num                                  :   1               ;    /* 0 */
        unsigned int fpds_ch0_cw1_shift                               :   5               ;    /* 5:1 */
        unsigned int reserved_0                                       :   2               ;    /* 7:6 */
        unsigned int fpds_ch0_mode                                    :   1               ;    /* 8 */
        unsigned int fpds_ch0_sfbc_flag                               :   1               ;    /* 9 */
        unsigned int fpds_ch0_cw0_shift                               :   5               ;    /* 14:10 */
        unsigned int reserved_1                                       :   1               ;    /* 15 */
        unsigned int fpds_ch1_mode                                    :   1               ;    /* 16 */
        unsigned int fpds_ch1_sfbc_flag                               :   1               ;    /* 17 */
        unsigned int fpds_ch1_shift                                   :   5               ;    /* 22:18 */
        unsigned int reserved_2                                       :   1               ;    /* 23 */
        unsigned int fpds_ch2_mode                                    :   1               ;    /* 24 */
        unsigned int fpds_ch2_sfbc_flag                               :   1               ;    /* 25 */
        unsigned int fpds_ch2_shift                                   :   5               ;    /* 30:26 */
        unsigned int reserved_3                                       :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_DEMAP_TASK_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_DEMAP_TASK_SUB0                                    om_data0;
    PDS_SID_PDS_NR_DEMAP_TASK_SUB1                                    om_data1;
} PDS_SID_PDS_NR_DEMAP_TASK;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_DEMAP_TASK_SUB0                                    om_data0;
    PDS_SID_PDS_NR_DEMAP_TASK_SUB1                                    om_data1;
} PDS_SID_PDS_NR_DEMAP_TASK_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   4               ;    /* 3:0 */
        unsigned int odd_even_flag                                    :   1               ;    /* 4 */
        unsigned int null_frm_flag                                    :   1               ;    /* 5 */
        unsigned int mu_tsme_en                                       :   1               ;    /* 6 */
        unsigned int rx_flag                                          :   2               ;    /* 8:7 */
        unsigned int che_dl_rb_num                                    :   9               ;    /* 17:9 */
        unsigned int fpds_fcross_en                                   :   1               ;    /* 18 */
        unsigned int noise_sel_flag                                   :   1               ;    /* 19 */
        unsigned int noise_rx_sel                                     :   8               ;    /* 27:20 */
        unsigned int fpds_inter_sel                                   :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_PCFGCMD_MV_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_PCFGCMD_MV_SUB0                                    om_data0;
    unsigned int                                                      fpds_slot_num;
} PDS_SID_PDS_NR_PCFGCMD_MV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_PCFGCMD_MV_SUB0                                    om_data0;
    unsigned int                                                      fpds_slot_num;
} PDS_SID_PDS_NR_PCFGCMD_MV_BBP_MC;

typedef union {
    struct {
        unsigned int ch_idx                                           :   4               ;    /* 3:0 */
        unsigned int mu_tsme_en                                       :   1               ;    /* 4 */
        unsigned int che_mu_qrm_flag                                  :   1               ;    /* 5 */
        unsigned int fpds_modu_level_sel                              :   1               ;    /* 6 */
        unsigned int fpds_mu_en                                       :   1               ;    /* 7 */
        unsigned int pds_config_done                                  :   1               ;    /* 8 */
        unsigned int reserved_0                                       :   7               ;    /* 15:9 */
        unsigned int demap_sym_en                                     :   14              ;    /* 29:16 */
        unsigned int dem_dcfc_pp_flag                                 :   1               ;    /* 30:30 */
        unsigned int demap_pp_flag                                    :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_DEMAP_CMD_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_DEMAP_CMD_SUB0                                     om_data0;
    unsigned int                                                      reserved_0;
} PDS_SID_PDS_NR_DEMAP_CMD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_DEMAP_CMD_SUB0                                     om_data0;
    unsigned int                                                      reserved_0;
} PDS_SID_PDS_NR_DEMAP_CMD_BBP_MC;

typedef union {
    struct {
        unsigned int ch_idx                                           :   4               ;    /* 3:0 */
        unsigned int odd_even_flag                                    :   1               ;    /* 4 */
        unsigned int dem_dcfc_pp_flag                                 :   1               ;    /* 5 */
        unsigned int coef_pp_flag                                     :   1               ;    /* 6 */
        unsigned int drs_cfc_inverse                                  :   1               ;    /* 7 */
        unsigned int cfg_idx                                          :   4               ;    /* 11:8 */
        unsigned int mdci_mtrp_match_cfg                              :   4               ;    /* 15:12 */
        unsigned int mdci_mtrp_flag                                   :   1               ;    /* 16 */
        unsigned int reserved_0                                       :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_CFC_CMD_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_CFC_CMD_SUB0                                       om_data0;
    unsigned int                                                      reserved_0;
} PDS_SID_PDS_NR_CFC_CMD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_CFC_CMD_SUB0                                       om_data0;
    unsigned int                                                      reserved_0;
} PDS_SID_PDS_NR_CFC_CMD_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   4               ;    /* 3:0 */
        unsigned int scs_val                                          :   4               ;    /* 7:4 */
        unsigned int sym_num                                          :   4               ;    /* 11:8 */
        unsigned int task_sym_num                                     :   4               ;    /* 15:12 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_CALC_CMD_SUB0;

typedef union {
    struct {
        unsigned int arq_info                                         :   16              ;    /* 15:0 */
        unsigned int task_num                                         :   4               ;    /* 19:16 */
        unsigned int cmd_rb_num                                       :   4               ;    /* 23:20 */
        unsigned int cmd_pp_flag                                      :   1               ;    /* 24:24 */
        unsigned int lst_send_int                                     :   1               ;    /* 25:25 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_CALC_CMD_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_CALC_CMD_SUB0                                      om_data0;
    PDS_SID_PDS_NR_CALC_CMD_SUB1                                      om_data1;
} PDS_SID_PDS_NR_CALC_CMD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_CALC_CMD_SUB0                                      om_data0;
    PDS_SID_PDS_NR_CALC_CMD_SUB1                                      om_data1;
} PDS_SID_PDS_NR_CALC_CMD_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   4               ;    /* 3:0 */
        unsigned int odd_even_flag                                    :   1               ;    /* 4 */
        unsigned int null_frm_flag                                    :   1               ;    /* 5 */
        unsigned int mu_tsme_en                                       :   1               ;    /* 6 */
        unsigned int cmd_pp_flag                                      :   1               ;    /* 7 */
        unsigned int dma_wr_int_flag                                  :   1               ;    /* 8 */
        unsigned int reserved_0                                       :   23              ;    /* 31:9 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_NULL_FRM_CMD_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_NULL_FRM_CMD_SUB0                                  om_data0;
    unsigned int                                                      arq_info;
} PDS_SID_PDS_NR_NULL_FRM_CMD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_NULL_FRM_CMD_SUB0                                  om_data0;
    unsigned int                                                      arq_info;
} PDS_SID_PDS_NR_NULL_FRM_CMD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      h_calc_cmd0_lo;
    unsigned int                                                      h_calc_cmd0_hi;
    unsigned int                                                      h_calc_cmd1_lo;
    unsigned int                                                      h_calc_cmd1_hi;
    unsigned int                                                      h_calc_cmd2_lo;
    unsigned int                                                      h_calc_cmd2_hi;
    unsigned int                                                      h_calc_cmd3_lo;
    unsigned int                                                      h_calc_cmd3_hi;
    unsigned int                                                      h_calc_cmd4_lo;
    unsigned int                                                      h_calc_cmd4_hi;
    unsigned int                                                      h_calc_cmd5_lo;
    unsigned int                                                      h_calc_cmd5_hi;
    unsigned int                                                      h_calc_cmd6_lo;
    unsigned int                                                      h_calc_cmd6_hi;
    unsigned int                                                      h_calc_cmd7_lo;
    unsigned int                                                      h_calc_cmd7_hi;
    unsigned int                                                      h_calc_cmd8_lo;
    unsigned int                                                      h_calc_cmd8_hi;
    unsigned int                                                      h_calc_cmd9_lo;
    unsigned int                                                      h_calc_cmd9_hi;
    unsigned int                                                      h_calc_cmd10_lo;
    unsigned int                                                      h_calc_cmd10_hi;
    unsigned int                                                      h_calc_cmd11_lo;
    unsigned int                                                      h_calc_cmd11_hi;
    unsigned int                                                      h_calc_cmd12_lo;
    unsigned int                                                      h_calc_cmd12_hi;
    unsigned int                                                      h_calc_cmd13_lo;
    unsigned int                                                      h_calc_cmd13_hi;
    unsigned int                                                      h_calc_cmd14_lo;
    unsigned int                                                      h_calc_cmd14_hi;
    unsigned int                                                      h_calc_cmd15_lo;
    unsigned int                                                      h_calc_cmd15_hi;
} PDS_SID_PDS_NR_HCALC_DBG_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      h_calc_cmd0_lo;
    unsigned int                                                      h_calc_cmd0_hi;
    unsigned int                                                      h_calc_cmd1_lo;
    unsigned int                                                      h_calc_cmd1_hi;
    unsigned int                                                      h_calc_cmd2_lo;
    unsigned int                                                      h_calc_cmd2_hi;
    unsigned int                                                      h_calc_cmd3_lo;
    unsigned int                                                      h_calc_cmd3_hi;
    unsigned int                                                      h_calc_cmd4_lo;
    unsigned int                                                      h_calc_cmd4_hi;
    unsigned int                                                      h_calc_cmd5_lo;
    unsigned int                                                      h_calc_cmd5_hi;
    unsigned int                                                      h_calc_cmd6_lo;
    unsigned int                                                      h_calc_cmd6_hi;
    unsigned int                                                      h_calc_cmd7_lo;
    unsigned int                                                      h_calc_cmd7_hi;
    unsigned int                                                      h_calc_cmd8_lo;
    unsigned int                                                      h_calc_cmd8_hi;
    unsigned int                                                      h_calc_cmd9_lo;
    unsigned int                                                      h_calc_cmd9_hi;
    unsigned int                                                      h_calc_cmd10_lo;
    unsigned int                                                      h_calc_cmd10_hi;
    unsigned int                                                      h_calc_cmd11_lo;
    unsigned int                                                      h_calc_cmd11_hi;
    unsigned int                                                      h_calc_cmd12_lo;
    unsigned int                                                      h_calc_cmd12_hi;
    unsigned int                                                      h_calc_cmd13_lo;
    unsigned int                                                      h_calc_cmd13_hi;
    unsigned int                                                      h_calc_cmd14_lo;
    unsigned int                                                      h_calc_cmd14_hi;
    unsigned int                                                      h_calc_cmd15_lo;
    unsigned int                                                      h_calc_cmd15_hi;
} PDS_SID_PDS_NR_HCALC_DBG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int llr_tau_scale                                    :   7               ;    /* 6:0 */
        unsigned int llr_llrt_scale                                   :   5               ;    /* 11:7 */
        unsigned int llr_mean_scale                                   :   10              ;    /* 21:12 */
        unsigned int dec_d                                            :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_DDL_PARA_SUB0;

typedef union {
    struct {
        unsigned int itr_max_tms                                      :   9               ;    /* 8:0 */
        unsigned int itr_avr_tms                                      :   9               ;    /* 17:9 */
        unsigned int ldpc_cor_matri_thres                             :   6               ;    /* 23:18 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_DDL_PARA_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_DDL_PARA_SUB0                                      om_data0;
    PDS_SID_PDS_NR_DDL_PARA_SUB1                                      om_data1;
} PDS_SID_PDS_NR_DDL_PARA;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_DDL_PARA_SUB0                                      om_data0;
    PDS_SID_PDS_NR_DDL_PARA_SUB1                                      om_data1;
} PDS_SID_PDS_NR_DDL_PARA_BBP_MC;

typedef union {
    struct {
        unsigned int rx_sw_release_flag                               :   1               ;    /* 0 */
        unsigned int bw_sw_release_flag                               :   1               ;    /* 1 */
        unsigned int cfg_change_flag                                  :   1               ;    /* 2 */
        unsigned int dims_sw_reles_flag                               :   1               ;    /* 3 */
        unsigned int bw_sw_alloc_flag                                 :   1               ;    /* 4 */
        unsigned int dims_sw_alloc_flag                               :   1               ;    /* 5 */
        unsigned int rx_sw_alloc_flag                                 :   1               ;    /* 6 */
        unsigned int rsv_bit0_0                                       :   1               ;    /* 7 */
        unsigned int cfg_idx                                          :   4               ;    /* 11:8 */
        unsigned int nr_cc_num                                        :   4               ;    /* 15:12 */
        unsigned int rx_num                                           :   4               ;    /* 19:16 */
        unsigned int work_cfg_flag                                    :   5               ;    /* 24:20 */
        unsigned int work_cfg_flag_old                                :   5               ;    /* 29:25 */
        unsigned int rsv_bit1_1                                       :   1               ;    /* 30 */
        unsigned int nr_flag                                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_HBUF_STATUS_SUB0;

typedef union {
    struct {
        unsigned int hubf_rd_ptr                                      :   16              ;    /* 15:0 */
        unsigned int hubf_wr_ptr                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_HBUF_STATUS_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_HBUF_STATUS_SUB0                                   om_data0;
    PDS_SID_PDS_NR_HBUF_STATUS_SUB1                                   om_data1;
} PDS_SID_PDS_NR_HBUF_STATUS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_HBUF_STATUS_SUB0                                   om_data0;
    PDS_SID_PDS_NR_HBUF_STATUS_SUB1                                   om_data1;
} PDS_SID_PDS_NR_HBUF_STATUS_BBP_MC;

typedef union {
    struct {
        unsigned int lte_init_flag                                    :   1               ;    /* 0 */
        unsigned int lte_comm_release_flag                            :   1               ;    /* 1 */
        unsigned int lte_cfg_release_flag                             :   1               ;    /* 2 */
        unsigned int area1_release_flag                               :   1               ;    /* 3 */
        unsigned int area1_alloc_flag                                 :   1               ;    /* 4 */
        unsigned int area0_cp_area1_flag                              :   1               ;    /* 5 */
        unsigned int rsv_bit0_0                                       :   1               ;    /* 6 */
        unsigned int rsv_bit1_1                                       :   1               ;    /* 7 */
        unsigned int cfg_idx                                          :   4               ;    /* 11:8 */
        unsigned int lte_cc_num                                       :   4               ;    /* 15:12 */
        unsigned int lte_old_cc_num                                   :   4               ;    /* 19:16 */
        unsigned int lte_cfg_en                                       :   5               ;    /* 24:20 */
        unsigned int lte_cfg_area_idx                                 :   5               ;    /* 29:25 */
        unsigned int lte_rx_4_flag                                    :   1               ;    /* 30 */
        unsigned int cfg_change_flag                                  :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_LTE_HBUF_STATUS_SUB0;

typedef union {
    struct {
        unsigned int hubf_rd_ptr                                      :   16              ;    /* 15:0 */
        unsigned int hubf_wr_ptr                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_LTE_HBUF_STATUS_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_LTE_HBUF_STATUS_SUB0                                  om_data0;
    PDS_SID_PDS_LTE_HBUF_STATUS_SUB1                                  om_data1;
} PDS_SID_PDS_LTE_HBUF_STATUS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_LTE_HBUF_STATUS_SUB0                                  om_data0;
    PDS_SID_PDS_LTE_HBUF_STATUS_SUB1                                  om_data1;
} PDS_SID_PDS_LTE_HBUF_STATUS_BBP_MC;

typedef union {
    struct {
        unsigned int ch_idx                                           :   4               ;    /* 3:0 */
        unsigned int cfg_blk_updata_en                                :   1               ;    /* 4 */
        unsigned int dims_sw_alloc_flag                               :   1               ;    /* 5 */
        unsigned int cfg_ping_alloc_rdy                               :   1               ;    /* 6 */
        unsigned int cfg_pang_alloc_rdy                               :   1               ;    /* 7 */
        unsigned int cfg_ping_reles_rdy                               :   1               ;    /* 8 */
        unsigned int cfg_pang_relse_rdy                               :   1               ;    /* 9 */
        unsigned int rx_num                                           :   2               ;    /* 11:10 */
        unsigned int cfg_blk_num_idx                                  :   4               ;    /* 15:12 */
        unsigned int cfg_blk_tot_num                                  :   8               ;    /* 23:16 */
        unsigned int nr_cc_num                                        :   3               ;    /* 26:24 */
        unsigned int work_cfg_flag                                    :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_H_MV_CMD_STATUS_SUB0;

typedef union {
    struct {
        unsigned int hubf_rd_ptr                                      :   16              ;    /* 15:0 */
        unsigned int hubf_wr_ptr                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_H_MV_CMD_STATUS_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_H_MV_CMD_STATUS_SUB0                               om_data0;
    PDS_SID_PDS_NR_H_MV_CMD_STATUS_SUB1                               om_data1;
} PDS_SID_PDS_NR_H_MV_CMD_STATUS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_H_MV_CMD_STATUS_SUB0                               om_data0;
    PDS_SID_PDS_NR_H_MV_CMD_STATUS_SUB1                               om_data1;
} PDS_SID_PDS_NR_H_MV_CMD_STATUS_BBP_MC;

typedef union {
    struct {
        unsigned int lte_cfg_idx                                      :   4               ;    /* 3:0 */
        unsigned int cfg_updata_en                                    :   1               ;    /* 4 */
        unsigned int blk_release_rdy                                  :   1               ;    /* 5 */
        unsigned int blk_alloc_rdy                                    :   1               ;    /* 6 */
        unsigned int lte_hpp_flag                                     :   1               ;    /* 7 */
        unsigned int lte_rx_flag                                      :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_LTE_H_MV_CMD_STATUS_SUB0;

typedef union {
    struct {
        unsigned int hubf_rd_ptr                                      :   16              ;    /* 15:0 */
        unsigned int hubf_wr_ptr                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_LTE_H_MV_CMD_STATUS_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_LTE_H_MV_CMD_STATUS_SUB0                              om_data0;
    PDS_SID_PDS_LTE_H_MV_CMD_STATUS_SUB1                              om_data1;
} PDS_SID_PDS_LTE_H_MV_CMD_STATUS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_LTE_H_MV_CMD_STATUS_SUB0                              om_data0;
    PDS_SID_PDS_LTE_H_MV_CMD_STATUS_SUB1                              om_data1;
} PDS_SID_PDS_LTE_H_MV_CMD_STATUS_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   4               ;    /* 3:0 */
        unsigned int old_blk_num_idx                                  :   4               ;    /* 7:4 */
        unsigned int old_blk_tot_num                                  :   8               ;    /* 15:8 */
        unsigned int nr_hpp_flag                                      :   1               ;    /* 16 */
        unsigned int first_release_rdy                                :   1               ;    /* 17 */
        unsigned int first_alloc_rdy                                  :   1               ;    /* 18 */
        unsigned int secnd_release_rdy                                :   1               ;    /* 19 */
        unsigned int secnd_alloc_rdy                                  :   1               ;    /* 20 */
        unsigned int cfg_release_en                                   :   1               ;    /* 21 */
        unsigned int cfg_ping_relse_rdy                               :   1               ;    /* 22 */
        unsigned int cfg_pang_relse_rdy                               :   1               ;    /* 23 */
        unsigned int cfg_ping_alloc_rdy                               :   1               ;    /* 24 */
        unsigned int cfg_pang_alloc_rdy                               :   1               ;    /* 25 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_CFG_RELEASE_STATUS_SUB0;

typedef union {
    struct {
        unsigned int hubf_rd_ptr                                      :   16              ;    /* 15:0 */
        unsigned int hubf_wr_ptr                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_CFG_RELEASE_STATUS_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_CFG_RELEASE_STATUS_SUB0                            om_data0;
    PDS_SID_PDS_NR_CFG_RELEASE_STATUS_SUB1                            om_data1;
} PDS_SID_PDS_NR_CFG_RELEASE_STATUS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_CFG_RELEASE_STATUS_SUB0                            om_data0;
    PDS_SID_PDS_NR_CFG_RELEASE_STATUS_SUB1                            om_data1;
} PDS_SID_PDS_NR_CFG_RELEASE_STATUS_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   4               ;    /* 3:0 */
        unsigned int old_blk_num_idx                                  :   4               ;    /* 7:4 */
        unsigned int old_blk_tot_num                                  :   8               ;    /* 15:8 */
        unsigned int cfg_rx_num                                       :   4               ;    /* 19:16 */
        unsigned int new_tot_num                                      :   8               ;    /* 27:20 */
        unsigned int cfg_ping_relse_rdy                               :   1               ;    /* 28 */
        unsigned int cfg_pang_relse_rdy                               :   1               ;    /* 29 */
        unsigned int cfg_ping_alloc_rdy                               :   1               ;    /* 30 */
        unsigned int cfg_pang_alloc_rdy                               :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_PARTIAL_RELEASE_STATUS_SUB0;

typedef union {
    struct {
        unsigned int hubf_rd_ptr                                      :   16              ;    /* 15:0 */
        unsigned int hubf_wr_ptr                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_PARTIAL_RELEASE_STATUS_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_PARTIAL_RELEASE_STATUS_SUB0                        om_data0;
    PDS_SID_PDS_NR_PARTIAL_RELEASE_STATUS_SUB1                        om_data1;
} PDS_SID_PDS_NR_PARTIAL_RELEASE_STATUS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_PARTIAL_RELEASE_STATUS_SUB0                        om_data0;
    PDS_SID_PDS_NR_PARTIAL_RELEASE_STATUS_SUB1                        om_data1;
} PDS_SID_PDS_NR_PARTIAL_RELEASE_STATUS_BBP_MC;

typedef union {
    struct {
        unsigned int ltev_cfg_alloc_en                                :   1               ;    /* 0 */
        unsigned int ltev_cfg_relse_flag                              :   1               ;    /* 1 */
        unsigned int ltev_cfg_alloc_rdy                               :   1               ;    /* 2 */
        unsigned int ltev_cfg_relese_rdy                              :   1               ;    /* 3 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_LTEV_CFG_RELEASE_STAUTS_SUB0;

typedef union {
    struct {
        unsigned int hubf_rd_ptr                                      :   16              ;    /* 15:0 */
        unsigned int hubf_wr_ptr                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_LTEV_CFG_RELEASE_STAUTS_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_LTEV_CFG_RELEASE_STAUTS_SUB0                          om_data0;
    PDS_SID_PDS_LTEV_CFG_RELEASE_STAUTS_SUB1                          om_data1;
} PDS_SID_PDS_LTEV_CFG_RELEASE_STAUTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_LTEV_CFG_RELEASE_STAUTS_SUB0                          om_data0;
    PDS_SID_PDS_LTEV_CFG_RELEASE_STAUTS_SUB1                          om_data1;
} PDS_SID_PDS_LTEV_CFG_RELEASE_STAUTS_BBP_MC;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx0                             :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx1                             :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx2                             :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx3                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB0;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx4                             :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx5                             :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx6                             :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx7                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB1;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx8                             :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx9                             :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx10                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx11                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB2;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx12                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx13                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx14                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx15                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB3;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx16                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx17                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx18                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx19                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB4;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx20                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx21                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx22                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx23                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB5;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx24                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx25                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx26                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx27                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB6;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx28                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx29                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx30                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx31                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB7;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx32                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx33                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx34                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx35                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB8;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx36                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx37                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx38                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx39                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB9;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx40                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx41                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx42                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx43                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB10;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx44                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx45                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx46                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx47                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB11;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx48                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx49                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx50                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx51                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB12;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx52                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx53                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx54                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx55                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB13;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx56                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx57                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx58                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx59                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB14;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx60                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx61                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx62                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx63                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB15;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx64                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx65                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx66                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx67                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB16;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx68                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx69                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx70                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx71                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB17;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx72                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx73                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx74                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx75                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB18;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx76                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx77                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx78                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx79                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB19;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx80                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx81                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx82                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx83                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB20;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx84                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx85                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx86                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx87                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB21;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx88                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx89                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx90                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx91                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB22;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx92                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx93                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx94                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx95                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB23;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx96                            :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx97                            :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx98                            :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx99                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB24;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx100                           :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx101                           :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx102                           :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx103                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB25;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx104                           :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx105                           :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx106                           :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx107                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB26;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx108                           :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx109                           :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx110                           :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx111                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB27;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx112                           :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx113                           :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx114                           :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx115                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB28;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx116                           :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx117                           :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx118                           :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx119                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB29;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx120                           :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx121                           :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx122                           :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx123                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB30;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx124                           :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx125                           :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx126                           :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx127                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB31;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx128                           :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx129                           :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx130                           :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx131                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB32;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx132                           :   8               ;    /* 7:0 */
        unsigned int fpds_mdm_lvl_rb_idx133                           :   8               ;    /* 15:8 */
        unsigned int fpds_mdm_lvl_rb_idx134                           :   8               ;    /* 23:16 */
        unsigned int fpds_mdm_lvl_rb_idx135                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB33;

typedef union {
    struct {
        unsigned int fpds_mdm_lvl_rb_idx136                           :   8               ;    /* 7:0 */
        unsigned int reserved_0                                       :   8               ;    /* 15:8 */
        unsigned int reserved_1                                       :   8               ;    /* 23:16 */
        unsigned int reserved_2                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} PDS_SID_PDS_NR_MU_INFO_SUB34;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    PDS_SID_PDS_NR_MU_INFO_SUB0                                       om_data0;
    PDS_SID_PDS_NR_MU_INFO_SUB1                                       om_data1;
    PDS_SID_PDS_NR_MU_INFO_SUB2                                       om_data2;
    PDS_SID_PDS_NR_MU_INFO_SUB3                                       om_data3;
    PDS_SID_PDS_NR_MU_INFO_SUB4                                       om_data4;
    PDS_SID_PDS_NR_MU_INFO_SUB5                                       om_data5;
    PDS_SID_PDS_NR_MU_INFO_SUB6                                       om_data6;
    PDS_SID_PDS_NR_MU_INFO_SUB7                                       om_data7;
    PDS_SID_PDS_NR_MU_INFO_SUB8                                       om_data8;
    PDS_SID_PDS_NR_MU_INFO_SUB9                                       om_data9;
    PDS_SID_PDS_NR_MU_INFO_SUB10                                      om_data10;
    PDS_SID_PDS_NR_MU_INFO_SUB11                                      om_data11;
    PDS_SID_PDS_NR_MU_INFO_SUB12                                      om_data12;
    PDS_SID_PDS_NR_MU_INFO_SUB13                                      om_data13;
    PDS_SID_PDS_NR_MU_INFO_SUB14                                      om_data14;
    PDS_SID_PDS_NR_MU_INFO_SUB15                                      om_data15;
    PDS_SID_PDS_NR_MU_INFO_SUB16                                      om_data16;
    PDS_SID_PDS_NR_MU_INFO_SUB17                                      om_data17;
    PDS_SID_PDS_NR_MU_INFO_SUB18                                      om_data18;
    PDS_SID_PDS_NR_MU_INFO_SUB19                                      om_data19;
    PDS_SID_PDS_NR_MU_INFO_SUB20                                      om_data20;
    PDS_SID_PDS_NR_MU_INFO_SUB21                                      om_data21;
    PDS_SID_PDS_NR_MU_INFO_SUB22                                      om_data22;
    PDS_SID_PDS_NR_MU_INFO_SUB23                                      om_data23;
    PDS_SID_PDS_NR_MU_INFO_SUB24                                      om_data24;
    PDS_SID_PDS_NR_MU_INFO_SUB25                                      om_data25;
    PDS_SID_PDS_NR_MU_INFO_SUB26                                      om_data26;
    PDS_SID_PDS_NR_MU_INFO_SUB27                                      om_data27;
    PDS_SID_PDS_NR_MU_INFO_SUB28                                      om_data28;
    PDS_SID_PDS_NR_MU_INFO_SUB29                                      om_data29;
    PDS_SID_PDS_NR_MU_INFO_SUB30                                      om_data30;
    PDS_SID_PDS_NR_MU_INFO_SUB31                                      om_data31;
    PDS_SID_PDS_NR_MU_INFO_SUB32                                      om_data32;
    PDS_SID_PDS_NR_MU_INFO_SUB33                                      om_data33;
    PDS_SID_PDS_NR_MU_INFO_SUB34                                      om_data34;
    unsigned int                                                      reserved_0;
} PDS_SID_PDS_NR_MU_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    PDS_SID_PDS_NR_MU_INFO_SUB0                                       om_data0;
    PDS_SID_PDS_NR_MU_INFO_SUB1                                       om_data1;
    PDS_SID_PDS_NR_MU_INFO_SUB2                                       om_data2;
    PDS_SID_PDS_NR_MU_INFO_SUB3                                       om_data3;
    PDS_SID_PDS_NR_MU_INFO_SUB4                                       om_data4;
    PDS_SID_PDS_NR_MU_INFO_SUB5                                       om_data5;
    PDS_SID_PDS_NR_MU_INFO_SUB6                                       om_data6;
    PDS_SID_PDS_NR_MU_INFO_SUB7                                       om_data7;
    PDS_SID_PDS_NR_MU_INFO_SUB8                                       om_data8;
    PDS_SID_PDS_NR_MU_INFO_SUB9                                       om_data9;
    PDS_SID_PDS_NR_MU_INFO_SUB10                                      om_data10;
    PDS_SID_PDS_NR_MU_INFO_SUB11                                      om_data11;
    PDS_SID_PDS_NR_MU_INFO_SUB12                                      om_data12;
    PDS_SID_PDS_NR_MU_INFO_SUB13                                      om_data13;
    PDS_SID_PDS_NR_MU_INFO_SUB14                                      om_data14;
    PDS_SID_PDS_NR_MU_INFO_SUB15                                      om_data15;
    PDS_SID_PDS_NR_MU_INFO_SUB16                                      om_data16;
    PDS_SID_PDS_NR_MU_INFO_SUB17                                      om_data17;
    PDS_SID_PDS_NR_MU_INFO_SUB18                                      om_data18;
    PDS_SID_PDS_NR_MU_INFO_SUB19                                      om_data19;
    PDS_SID_PDS_NR_MU_INFO_SUB20                                      om_data20;
    PDS_SID_PDS_NR_MU_INFO_SUB21                                      om_data21;
    PDS_SID_PDS_NR_MU_INFO_SUB22                                      om_data22;
    PDS_SID_PDS_NR_MU_INFO_SUB23                                      om_data23;
    PDS_SID_PDS_NR_MU_INFO_SUB24                                      om_data24;
    PDS_SID_PDS_NR_MU_INFO_SUB25                                      om_data25;
    PDS_SID_PDS_NR_MU_INFO_SUB26                                      om_data26;
    PDS_SID_PDS_NR_MU_INFO_SUB27                                      om_data27;
    PDS_SID_PDS_NR_MU_INFO_SUB28                                      om_data28;
    PDS_SID_PDS_NR_MU_INFO_SUB29                                      om_data29;
    PDS_SID_PDS_NR_MU_INFO_SUB30                                      om_data30;
    PDS_SID_PDS_NR_MU_INFO_SUB31                                      om_data31;
    PDS_SID_PDS_NR_MU_INFO_SUB32                                      om_data32;
    PDS_SID_PDS_NR_MU_INFO_SUB33                                      om_data33;
    PDS_SID_PDS_NR_MU_INFO_SUB34                                      om_data34;
    unsigned int                                                      reserved_0;
} PDS_SID_PDS_NR_MU_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ch_idx;
    unsigned int                                                      re_num;
} PDS_SID_PDS_LTE_DDL_CH_RE_NUM_ZERO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ch_idx;
    unsigned int                                                      re_num;
} PDS_SID_PDS_LTE_DDL_CH_RE_NUM_ZERO_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
