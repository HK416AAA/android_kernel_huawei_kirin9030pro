

#ifndef __UPHY_PDE_CSI_OM_H__
#define __UPHY_PDE_CSI_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef union {
    struct {
        unsigned int real_coef_up_en                                  :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   31              ;    /* 31:1 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_NR_INIT_SUB0;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   8               ;    /* 7:0 */
        unsigned int dsp_init_idx                                     :   9               ;    /* 16:8 */
        unsigned int reserved_0                                       :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_NR_INIT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_NR_INIT_SUB0                                          om_data0;
    CSI_SID_CSI_NR_INIT_SUB1                                          om_data1;
} CSI_SID_CSI_NR_INIT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_NR_INIT_SUB0                                          om_data0;
    CSI_SID_CSI_NR_INIT_SUB1                                          om_data1;
} CSI_SID_CSI_NR_INIT_BBP_MC;

typedef union {
    struct {
        unsigned int cc_idx                                           :   8               ;    /* 7:0 */
        unsigned int res_idx                                          :   5               ;    /* 12:8 */
        unsigned int reserved_0                                       :   2               ;    /* 14:13 */
        unsigned int csi_rs_type                                      :   1               ;    /* 15 */
        unsigned int reserved_1                                       :   1               ;    /* 16 */
        unsigned int csi_rs_mode                                      :   2               ;    /* 18:17 */
        unsigned int buf_idx                                          :   2               ;    /* 20:19 */
        unsigned int rx_flag                                          :   3               ;    /* 23:21 */
        unsigned int reserved_2                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_NR_CHE_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_NR_CHE_SUB0                                           om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_CHE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_NR_CHE_SUB0                                           om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_CHE_BBP_MC;

typedef union {
    struct {
        unsigned int sb_size                                          :   7               ;    /* 6:0 */
        unsigned int reserved_0                                       :   1               ;    /* 7 */
        unsigned int csi_start_rb                                     :   9               ;    /* 16:8 */
        unsigned int reserved_1                                       :   3               ;    /* 19:17 */
        unsigned int csi_rb_num                                       :   9               ;    /* 28:20 */
        unsigned int reserved_2                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_NR_COVH_CAND_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_NR_COVH_CAND_SUB0                                     om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_COVH_CAND;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_NR_COVH_CAND_SUB0                                     om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_COVH_CAND_BBP_MC;

typedef union {
    struct {
        unsigned int pmi1set_mode                                     :   2               ;    /* 1:0 */
        unsigned int pmi2set_mode                                     :   1               ;    /* 2 */
        unsigned int pmi2_bypass                                      :   1               ;    /* 3 */
        unsigned int si1_bypass                                       :   1               ;    /* 4 */
        unsigned int reserved_0                                       :   2               ;    /* 6:5 */
        unsigned int csi_pmi1_sampfactor                              :   1               ;    /* 7 */
        unsigned int reserved_1                                       :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_NR_PMI1_SI1_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_NR_PMI1_SI1_SUB0                                      om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_PMI1_SI1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_NR_PMI1_SI1_SUB0                                      om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_PMI1_SI1_BBP_MC;

typedef union {
    struct {
        unsigned int rank1_si2_w_num                                  :   8               ;    /* 7:0 */
        unsigned int rank2_si2_w_num                                  :   8               ;    /* 15:8 */
        unsigned int rank3_si2_w_num                                  :   8               ;    /* 23:16 */
        unsigned int rank4_si2_w_num                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_NR_PMI1_SI2_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_NR_PMI1_SI2_SUB0                                      om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_PMI1_SI2;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_NR_PMI1_SI2_SUB0                                      om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_PMI1_SI2_BBP_MC;

typedef union {
    struct {
        unsigned int ri_sel                                           :   3               ;    /* 2:0 */
        unsigned int reserved_0                                       :   29              ;    /* 31:3 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_NR_PMI2_SI2_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_NR_PMI2_SI2_SUB0                                      om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_PMI2_SI2;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_NR_PMI2_SI2_SUB0                                      om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_PMI2_SI2_BBP_MC;

typedef union {
    struct {
        unsigned int rpt_id                                           :   8               ;    /* 7:0 */
        unsigned int attri                                            :   4               ;    /* 11:8 */
        unsigned int ap_fast                                          :   1               ;    /* 12 */
        unsigned int reserved_0                                       :   3               ;    /* 15:13 */
        unsigned int pmi_rpt_sel                                      :   2               ;    /* 17:16 */
        unsigned int cqi_rpt_sel                                      :   2               ;    /* 19:18 */
        unsigned int bwp_to_dbuf_0rb_offset                           :   9               ;    /* 28:20 */
        unsigned int reserved_1                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_NR_RI_CQI_RPT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_NR_RI_CQI_RPT_SUB0                                    om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_RI_CQI_RPT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_NR_RI_CQI_RPT_SUB0                                    om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_RI_CQI_RPT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      chose_beam_group_num;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_TYPEII_WB_BEAM_GEND;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      chose_beam_group_num;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_TYPEII_WB_BEAM_GEND_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      size;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_TYPEII_GEN_EVD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      size;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_TYPEII_GEN_EVD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      typeii_r16_r17_flag;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_TYPEII_GEN_WB_W;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      typeii_r16_r17_flag;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_TYPEII_GEN_WB_W_BBP_MC;

typedef union {
    struct {
        unsigned int r16_n_first_extra                                :   3               ;    /* 2:0 */
        unsigned int r16_n_last_extra                                 :   3               ;    /* 5:3 */
        unsigned int reserved_0                                       :   2               ;    /* 7:6 */
        unsigned int r16_n3                                           :   6               ;    /* 13:8 */
        unsigned int reserved_1                                       :   2               ;    /* 15:14 */
        unsigned int r16_m_rank12                                     :   4               ;    /* 19:16 */
        unsigned int r16_m_rank34                                     :   3               ;    /* 22:20 */
        unsigned int reserved_2                                       :   3               ;    /* 25:23 */
        unsigned int r16_k0                                           :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_NR_TYPEII_SB_D_MATRIX_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_NR_TYPEII_SB_D_MATRIX_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_TYPEII_SB_D_MATRIX;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_NR_TYPEII_SB_D_MATRIX_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_TYPEII_SB_D_MATRIX_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pmi_rpt_sel;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_TYPEII_GEN_SB_W;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pmi_rpt_sel;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_TYPEII_GEN_SB_W_BBP_MC;

typedef union {
    struct {
        unsigned int lte_tx_num                                       :   3               ;    /* 2:0 */
        unsigned int lte_rx_num                                       :   4               ;    /* 6:3 */
        unsigned int lte_cp                                           :   1               ;    /* 7 */
        unsigned int lte_bw                                           :   3               ;    /* 10:8 */
        unsigned int reserved_0                                       :   21              ;    /* 31:11 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_LTE_RLM_SUB0;

typedef union {
    struct {
        unsigned int cc_rs_mode                                       :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   31              ;    /* 31:1 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_LTE_RLM_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_LTE_RLM_SUB0                                          om_data0;
    CSI_SID_CSI_LTE_RLM_SUB1                                          om_data1;
} CSI_SID_CSI_LTE_RLM;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_LTE_RLM_SUB0                                          om_data0;
    CSI_SID_CSI_LTE_RLM_SUB1                                          om_data1;
} CSI_SID_CSI_LTE_RLM_BBP_MC;

typedef union {
    struct {
        unsigned int csi_port_num                                     :   4               ;    /* 3:0 */
        unsigned int csi_rs_config                                    :   5               ;    /* 8:4 */
        unsigned int reserved_0                                       :   17              ;    /* 25:9 */
        unsigned int frm_type3_flag                                   :   1               ;    /* 26 */
        unsigned int reserved_1                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_LTE_CHE_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_LTE_CHE_SUB0                                          om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_CHE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_LTE_CHE_SUB0                                          om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_CHE_BBP_MC;

typedef union {
    struct {
        unsigned int filter_init                                      :   1               ;    /* 0 */
        unsigned int lte_ap_cqi_en                                    :   1               ;    /* 1 */
        unsigned int lte_cqi_en                                       :   1               ;    /* 2 */
        unsigned int bp_idx                                           :   2               ;    /* 4:3 */
        unsigned int reserved_0                                       :   7               ;    /* 11:5 */
        unsigned int rpt_frame_id                                     :   12              ;    /* 23:12 */
        unsigned int rpt_sbfn_id                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_LTE_COVH_CAND_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_LTE_COVH_CAND_SUB0                                    om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_COVH_CAND;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_LTE_COVH_CAND_SUB0                                    om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_COVH_CAND_BBP_MC;

typedef union {
    struct {
        unsigned int pmi1set_mode                                     :   2               ;    /* 1:0 */
        unsigned int pmi2set_mode                                     :   2               ;    /* 3:2 */
        unsigned int pmi2_bypass                                      :   1               ;    /* 4 */
        unsigned int si1_bypass                                       :   1               ;    /* 5 */
        unsigned int reserved_0                                       :   26              ;    /* 31:6 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_LTE_PMI1_SI1_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_LTE_PMI1_SI1_SUB0                                     om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_PMI1_SI1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_LTE_PMI1_SI1_SUB0                                     om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_PMI1_SI1_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ri_bitmap;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_PMI1_SI2;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ri_bitmap;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_PMI1_SI2_BBP_MC;

typedef union {
    struct {
        unsigned int trans_mode                                       :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int ri_bitmap                                        :   4               ;    /* 11:8 */
        unsigned int cqi_table                                        :   2               ;    /* 13:12 */
        unsigned int reserved_1                                       :   2               ;    /* 15:14 */
        unsigned int attri                                            :   2               ;    /* 17:16 */
        unsigned int ap_attri                                         :   4               ;    /* 21:18 */
        unsigned int pc_pa                                            :   5               ;    /* 26:22 */
        unsigned int pmi_ri_rpt_sel                                   :   1               ;    /* 27 */
        unsigned int sub_sample_mode                                  :   1               ;    /* 28 */
        unsigned int reserved_2                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_LTE_PMI2_SI2_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_LTE_PMI2_SI2_SUB0                                     om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_PMI2_SI2;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_LTE_PMI2_SI2_SUB0                                     om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_PMI2_SI2_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cbk_type;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_RI_CQI_RPT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cbk_type;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_RI_CQI_RPT_BBP_MC;

typedef union {
    struct {
        unsigned int lte_csi_calc_en_cc                               :   1               ;    /* 0 */
        unsigned int lte_qp_cqi_en                                    :   1               ;    /* 1 */
        unsigned int lte_cqi_en                                       :   1               ;    /* 2 */
        unsigned int reserved_0                                       :   29              ;    /* 31:3 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_LTE_DEBUG_INFO_LTE_CFG_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_LTE_DEBUG_INFO_LTE_CFG_SUB0                           om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_DEBUG_INFO_LTE_CFG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_LTE_DEBUG_INFO_LTE_CFG_SUB0                           om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_LTE_DEBUG_INFO_LTE_CFG_BBP_MC;

typedef union {
    struct {
        unsigned int res_idx                                          :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} CSI_SID_CSI_NR_DEBUG_INFO_CHE_H_MEM_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSI_SID_CSI_NR_DEBUG_INFO_CHE_H_MEM_SUB0                          om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_DEBUG_INFO_CHE_H_MEM;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSI_SID_CSI_NR_DEBUG_INFO_CHE_H_MEM_SUB0                          om_data0;
    unsigned int                                                      reserved_0;
} CSI_SID_CSI_NR_DEBUG_INFO_CHE_H_MEM_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      irc_rpt_slot_power0;
    unsigned int                                                      irc_rpt_slot_power1;
    unsigned int                                                      irc_rpt_slot_power2;
    unsigned int                                                      irc_rpt_slot_power3;
    unsigned int                                                      res_auto_lower_complexity;
    unsigned int                                                      res_idx;
} CSI_SID_CSI_NR_DEBUG_INFO_P_NOISE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      irc_rpt_slot_power0;
    unsigned int                                                      irc_rpt_slot_power1;
    unsigned int                                                      irc_rpt_slot_power2;
    unsigned int                                                      irc_rpt_slot_power3;
    unsigned int                                                      res_auto_lower_complexity;
    unsigned int                                                      res_idx;
} CSI_SID_CSI_NR_DEBUG_INFO_P_NOISE_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
