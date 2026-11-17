

#ifndef __UPHY_PDE_CHE_OM_H__
#define __UPHY_PDE_CHE_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef union {
    struct {
        unsigned int init_flag_cur                                    :   1               ;    /* 0 */
        unsigned int last_flag_pre                                    :   1               ;    /* 1 */
        unsigned int crs_en_cur                                       :   1               ;    /* 2 */
        unsigned int crs_en_pre                                       :   1               ;    /* 3 */
        unsigned int turnoff_en_pre                                   :   1               ;    /* 4 */
        unsigned int ic_mode_pre                                      :   1               ;    /* 5 */
        unsigned int ic_s1_pdma_en                                    :   1               ;    /* 6 */
        unsigned int ic_s4_pdma_en                                    :   1               ;    /* 7 */
        unsigned int crs_tx01_num_cur                                 :   3               ;    /* 10:8 */
        unsigned int crs_tx23_num_cur                                 :   3               ;    /* 13:11 */
        unsigned int crs_tx01_num_pre                                 :   3               ;    /* 16:14 */
        unsigned int crs_tx23_num_pre                                 :   3               ;    /* 19:17 */
        unsigned int crs_task_num0                                    :   3               ;    /* 22:20 */
        unsigned int crs_task_num1                                    :   2               ;    /* 24:23 */
        unsigned int pds_func_addr                                    :   4               ;    /* 28:25 */
        unsigned int pdc_func_addr                                    :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} CHE_SID_CHE_LTE_PDS_INIT_S_OUT_SUB0;

typedef union {
    struct {
        unsigned int cc_idx                                           :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   1               ;    /* 4 */
        unsigned int modem_id                                         :   1               ;    /* 5 */
        unsigned int reserved_1                                       :   3               ;    /* 8:6 */
        unsigned int turnoff_en_final                                 :   1               ;    /* 9 */
        unsigned int reserved_2                                       :   1               ;    /* 10 */
        unsigned int dmrs_en_pre                                      :   1               ;    /* 11 */
        unsigned int pb_en_pre                                        :   1               ;    /* 12 */
        unsigned int tfe_crs_en_pre                                   :   1               ;    /* 13 */
        unsigned int tfe_sss_en_pre                                   :   1               ;    /* 14 */
        unsigned int reserved_3                                       :   3               ;    /* 17:15 */
        unsigned int pds_crs_pdma_en                                  :   1               ;    /* 18 */
        unsigned int tfe_crs_pattern                                  :   2               ;    /* 20:19 */
        unsigned int reserved_4                                       :   1               ;    /* 21 */
        unsigned int pb1_en_pre                                       :   1               ;    /* 22 */
        unsigned int tfe_crs_only_pre                                 :   1               ;    /* 23 */
        unsigned int ic_mode_cur                                      :   1               ;    /* 24 */
        unsigned int reserved_5                                       :   7               ;    /* 31:25 */
    } bits;
    unsigned int u32;
} CHE_SID_CHE_LTE_PDS_INIT_S_OUT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CHE_SID_CHE_LTE_PDS_INIT_S_OUT_SUB0                               om_data0;
    CHE_SID_CHE_LTE_PDS_INIT_S_OUT_SUB1                               om_data1;
} CHE_SID_CHE_LTE_PDS_INIT_S_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CHE_SID_CHE_LTE_PDS_INIT_S_OUT_SUB0                               om_data0;
    CHE_SID_CHE_LTE_PDS_INIT_S_OUT_SUB1                               om_data1;
} CHE_SID_CHE_LTE_PDS_INIT_S_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_NR_INIT_S_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_NR_INIT_S_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_PDS_INIT_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_PDS_INIT_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int che_lte_pb_dif_en                                :   1               ;    /* 0 */
        unsigned int tfe_sss_dif_en                                   :   1               ;    /* 1 */
        unsigned int che_lte_dmrs_dif_en                              :   1               ;    /* 2 */
        unsigned int reserved_0                                       :   1               ;    /* 3 */
        unsigned int reserved_1                                       :   1               ;    /* 4 */
        unsigned int che_lte_pds_crs_dif_en                           :   1               ;    /* 5 */
        unsigned int tfe_crs_dif_en                                   :   1               ;    /* 6 */
        unsigned int crsic_ryy_dif_en                                 :   1               ;    /* 7 */
        unsigned int reserved_2                                       :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} CHE_SID_CHE_LTE_IC_DIF_S1_OUT_SUB0;

typedef union {
    struct {
        unsigned int crs_no_pds_flag                                  :   1               ;    /* 0 */
        unsigned int tx_num_pre                                       :   3               ;    /* 3:1 */
        unsigned int crs_tx01_num_pre                                 :   3               ;    /* 6:4 */
        unsigned int pds_crs_dif_sym_ind                              :   4               ;    /* 10:7 */
        unsigned int cur_slot_idx                                     :   4               ;    /* 14:11 */
        unsigned int pb_slot_num                                      :   4               ;    /* 18:15 */
        unsigned int dmrs_slot_num_pre                                :   4               ;    /* 22:19 */
        unsigned int reserved_0                                       :   9               ;    /* 31:23 */
    } bits;
    unsigned int u32;
} CHE_SID_CHE_LTE_IC_DIF_S1_OUT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CHE_SID_CHE_LTE_IC_DIF_S1_OUT_SUB0                                om_data0;
    CHE_SID_CHE_LTE_IC_DIF_S1_OUT_SUB1                                om_data1;
} CHE_SID_CHE_LTE_IC_DIF_S1_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CHE_SID_CHE_LTE_IC_DIF_S1_OUT_SUB0                                om_data0;
    CHE_SID_CHE_LTE_IC_DIF_S1_OUT_SUB1                                om_data1;
} CHE_SID_CHE_LTE_IC_DIF_S1_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int che_lte_pdc_crs_dif_en                           :   1               ;    /* 0 */
        unsigned int che_lte_pdc_data_symb0123_flag                   :   1               ;    /* 1 */
        unsigned int che_lte_pdc_crs_int_flag                         :   1               ;    /* 2 */
        unsigned int che_lte_pdc_crs_ind                              :   3               ;    /* 5:3 */
        unsigned int che_lte_pdc_slot_num                             :   4               ;    /* 9:6 */
        unsigned int che_lte_pdc_symb_int_bitmap                      :   4               ;    /* 13:10 */
        unsigned int reserved_0                                       :   18              ;    /* 31:14 */
    } bits;
    unsigned int u32;
} CHE_SID_CHE_LTE_IC_DIF_S4_OUT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CHE_SID_CHE_LTE_IC_DIF_S4_OUT_SUB0                                om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_IC_DIF_S4_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CHE_SID_CHE_LTE_IC_DIF_S4_OUT_SUB0                                om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_IC_DIF_S4_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_SYMB_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_SYMB_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_PDS_IRC_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_PDS_IRC_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_PDC_INIT_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_PDC_INIT_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_PDC_IRC_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_PDC_IRC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int ic_s11_status                                    :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   31              ;    /* 31:1 */
    } bits;
    unsigned int u32;
} CHE_SID_CHE_LTE_IC_S11_PROC_OUT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CHE_SID_CHE_LTE_IC_S11_PROC_OUT_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_IC_S11_PROC_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CHE_SID_CHE_LTE_IC_S11_PROC_OUT_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_IC_S11_PROC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int ic_s1_status                                     :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   31              ;    /* 31:1 */
    } bits;
    unsigned int u32;
} CHE_SID_CHE_LTE_IC_S1_PROC_OUT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CHE_SID_CHE_LTE_IC_S1_PROC_OUT_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_IC_S1_PROC_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CHE_SID_CHE_LTE_IC_S1_PROC_OUT_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_IC_S1_PROC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int ic_s4_status                                     :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   31              ;    /* 31:1 */
    } bits;
    unsigned int u32;
} CHE_SID_CHE_LTE_IC_S4_PROC_OUT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CHE_SID_CHE_LTE_IC_S4_PROC_OUT_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_IC_S4_PROC_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CHE_SID_CHE_LTE_IC_S4_PROC_OUT_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_IC_S4_PROC_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_NR_INIT_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_NR_INIT_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_NR_SYMB_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_NR_SYMB_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      nr_irc_mdcoef;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_NR_IRC_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      nr_irc_mdcoef;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_NR_IRC_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_PB_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_PB_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_TFE_ONLY_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_TFE_ONLY_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_DMRS_PARAM_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_DMRS_PARAM_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_DMRS_WN_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_DMRS_WN_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_DMRS_IRC_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_LTE_DMRS_IRC_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_PDS_TRANS_TIMEOUT_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} CHE_SID_CHE_PDS_TRANS_TIMEOUT_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int lte_fifo_cnt                                     :   8               ;    /* 7:0 */
        unsigned int mem_pool_fifo_cnt                                :   16              ;    /* 23:8 */
        unsigned int mem_pool_cst                                     :   4               ;    /* 27:24 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB0;

typedef union {
    struct {
        unsigned int nr_mem_ctrl_info                                 :   16              ;    /* 15:0 */
        unsigned int cr_cc_memu_num                                   :   8               ;    /* 23:16 */
        unsigned int cr_cc_info                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB1;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap0_rx0                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb0_rx0                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb0_rx0                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot0_rx0                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot0_rx0                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot0_rx0                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB2;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap0_rx1                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb0_rx1                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb0_rx1                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot0_rx1                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot0_rx1                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot0_rx1                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB3;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap0_rx2                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb0_rx2                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb0_rx2                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot0_rx2                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot0_rx2                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot0_rx2                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB4;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap0_rx3                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb0_rx3                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb0_rx3                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot0_rx3                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot0_rx3                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot0_rx3                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB5;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap0_rx4                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb0_rx4                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb0_rx4                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot0_rx4                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot0_rx4                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot0_rx4                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB6;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap0_rx5                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb0_rx5                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb0_rx5                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot0_rx5                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot0_rx5                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot0_rx5                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB7;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap0_rx6                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb0_rx6                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb0_rx6                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot0_rx6                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot0_rx6                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot0_rx6                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB8;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap0_rx7                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb0_rx7                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb0_rx7                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot0_rx7                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot0_rx7                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot0_rx7                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB9;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap1_rx0                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb1_rx0                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb1_rx0                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot1_rx0                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot1_rx0                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot1_rx0                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB10;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap1_rx1                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb1_rx1                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb1_rx1                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot1_rx1                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot1_rx1                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot1_rx1                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB11;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap1_rx2                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb1_rx2                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb1_rx2                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot1_rx2                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot1_rx2                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot1_rx2                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB12;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap1_rx3                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb1_rx3                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb1_rx3                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot1_rx3                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot1_rx3                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot1_rx3                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB13;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap1_rx4                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb1_rx4                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb1_rx4                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot1_rx4                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot1_rx4                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot1_rx4                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB14;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap1_rx5                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb1_rx5                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb1_rx5                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot1_rx5                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot1_rx5                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot1_rx5                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB15;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap1_rx6                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb1_rx6                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb1_rx6                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot1_rx6                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot1_rx6                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot1_rx6                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB16;

typedef union {
    struct {
        unsigned int dfu_cc_symb_bitmap1_rx7                          :   14              ;    /* 13:0 */
        unsigned int dfu_cc_timer_symb1_rx7                           :   4               ;    /* 17:14 */
        unsigned int dfu_cc_dfu_symb1_rx7                             :   4               ;    /* 21:18 */
        unsigned int dfu_cc_dfu_slot1_rx7                             :   4               ;    /* 25:22 */
        unsigned int dfu_cc_timer_slot1_rx7                           :   4               ;    /* 29:26 */
        unsigned int dfu_cc_slot1_rx7                                 :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DFU_INFO_SUB17;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CHE_SID_FDBUF_DFU_INFO_SUB0                                       om_data0;
    CHE_SID_FDBUF_DFU_INFO_SUB1                                       om_data1;
    CHE_SID_FDBUF_DFU_INFO_SUB2                                       om_data2;
    CHE_SID_FDBUF_DFU_INFO_SUB3                                       om_data3;
    CHE_SID_FDBUF_DFU_INFO_SUB4                                       om_data4;
    CHE_SID_FDBUF_DFU_INFO_SUB5                                       om_data5;
    CHE_SID_FDBUF_DFU_INFO_SUB6                                       om_data6;
    CHE_SID_FDBUF_DFU_INFO_SUB7                                       om_data7;
    CHE_SID_FDBUF_DFU_INFO_SUB8                                       om_data8;
    CHE_SID_FDBUF_DFU_INFO_SUB9                                       om_data9;
    CHE_SID_FDBUF_DFU_INFO_SUB10                                      om_data10;
    CHE_SID_FDBUF_DFU_INFO_SUB11                                      om_data11;
    CHE_SID_FDBUF_DFU_INFO_SUB12                                      om_data12;
    CHE_SID_FDBUF_DFU_INFO_SUB13                                      om_data13;
    CHE_SID_FDBUF_DFU_INFO_SUB14                                      om_data14;
    CHE_SID_FDBUF_DFU_INFO_SUB15                                      om_data15;
    CHE_SID_FDBUF_DFU_INFO_SUB16                                      om_data16;
    CHE_SID_FDBUF_DFU_INFO_SUB17                                      om_data17;
} CHE_SID_FDBUF_DFU_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CHE_SID_FDBUF_DFU_INFO_SUB0                                       om_data0;
    CHE_SID_FDBUF_DFU_INFO_SUB1                                       om_data1;
    CHE_SID_FDBUF_DFU_INFO_SUB2                                       om_data2;
    CHE_SID_FDBUF_DFU_INFO_SUB3                                       om_data3;
    CHE_SID_FDBUF_DFU_INFO_SUB4                                       om_data4;
    CHE_SID_FDBUF_DFU_INFO_SUB5                                       om_data5;
    CHE_SID_FDBUF_DFU_INFO_SUB6                                       om_data6;
    CHE_SID_FDBUF_DFU_INFO_SUB7                                       om_data7;
    CHE_SID_FDBUF_DFU_INFO_SUB8                                       om_data8;
    CHE_SID_FDBUF_DFU_INFO_SUB9                                       om_data9;
    CHE_SID_FDBUF_DFU_INFO_SUB10                                      om_data10;
    CHE_SID_FDBUF_DFU_INFO_SUB11                                      om_data11;
    CHE_SID_FDBUF_DFU_INFO_SUB12                                      om_data12;
    CHE_SID_FDBUF_DFU_INFO_SUB13                                      om_data13;
    CHE_SID_FDBUF_DFU_INFO_SUB14                                      om_data14;
    CHE_SID_FDBUF_DFU_INFO_SUB15                                      om_data15;
    CHE_SID_FDBUF_DFU_INFO_SUB16                                      om_data16;
    CHE_SID_FDBUF_DFU_INFO_SUB17                                      om_data17;
} CHE_SID_FDBUF_DFU_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int rb0_shift_p                                      :   8               ;    /* 7:0 */
        unsigned int rb1_shift_p                                      :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} CHE_SID_CHE_LTE_DMRS_P_SHIFT_RPT_DOT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CHE_SID_CHE_LTE_DMRS_P_SHIFT_RPT_DOT_SUB0                         om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_DMRS_P_SHIFT_RPT_DOT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CHE_SID_CHE_LTE_DMRS_P_SHIFT_RPT_DOT_SUB0                         om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_DMRS_P_SHIFT_RPT_DOT_BBP_MC;

typedef union {
    struct {
        unsigned int rb0_shift_p                                      :   8               ;    /* 7:0 */
        unsigned int rb1_shift_p                                      :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} CHE_SID_CHE_LTE_PDS_CRS_P_SHIFT_RPT_DOT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CHE_SID_CHE_LTE_PDS_CRS_P_SHIFT_RPT_DOT_SUB0                      om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_PDS_CRS_P_SHIFT_RPT_DOT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CHE_SID_CHE_LTE_PDS_CRS_P_SHIFT_RPT_DOT_SUB0                      om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_LTE_PDS_CRS_P_SHIFT_RPT_DOT_BBP_MC;

typedef union {
    struct {
        unsigned int rb0_shift_p                                      :   8               ;    /* 7:0 */
        unsigned int rb1_shift_p                                      :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} CHE_SID_CHE_NR_P_SHIFT_RPT_DOT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CHE_SID_CHE_NR_P_SHIFT_RPT_DOT_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_NR_P_SHIFT_RPT_DOT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CHE_SID_CHE_NR_P_SHIFT_RPT_DOT_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} CHE_SID_CHE_NR_P_SHIFT_RPT_DOT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rb0_p00_p11;
    unsigned int                                                      rb0_p10;
    unsigned int                                                      rb0_p20;
    unsigned int                                                      rb0_p21;
    unsigned int                                                      rb0_p22_p33;
    unsigned int                                                      rb0_p30;
    unsigned int                                                      rb0_p31;
    unsigned int                                                      rb0_p32;
    unsigned int                                                      rb0_p44_p55;
    unsigned int                                                      rb0_p54;
    unsigned int                                                      rb0_p64;
    unsigned int                                                      rb0_p65;
    unsigned int                                                      rb0_p66_p77;
    unsigned int                                                      rb0_p74;
    unsigned int                                                      rb0_p75;
    unsigned int                                                      rb0_p76;
    unsigned int                                                      rb0_p40;
    unsigned int                                                      rb0_p41;
    unsigned int                                                      rb0_p42;
    unsigned int                                                      rb0_p43;
    unsigned int                                                      rb0_p50;
    unsigned int                                                      rb0_p51;
    unsigned int                                                      rb0_p52;
    unsigned int                                                      rb0_p53;
    unsigned int                                                      rb0_p60;
    unsigned int                                                      rb0_p61;
    unsigned int                                                      rb0_p62;
    unsigned int                                                      rb0_p63;
    unsigned int                                                      rb0_p70;
    unsigned int                                                      rb0_p71;
    unsigned int                                                      rb0_p72;
    unsigned int                                                      rb0_p73;
    unsigned int                                                      rb1_p00_p11;
    unsigned int                                                      rb1_p10;
    unsigned int                                                      rb1_p20;
    unsigned int                                                      rb1_p21;
    unsigned int                                                      rb1_p22_p33;
    unsigned int                                                      rb1_p30;
    unsigned int                                                      rb1_p31;
    unsigned int                                                      rb1_p32;
    unsigned int                                                      rb1_p44_p55;
    unsigned int                                                      rb1_p54;
    unsigned int                                                      rb1_p64;
    unsigned int                                                      rb1_p65;
    unsigned int                                                      rb1_p66_p77;
    unsigned int                                                      rb1_p74;
    unsigned int                                                      rb1_p75;
    unsigned int                                                      rb1_p76;
    unsigned int                                                      rb1_p40;
    unsigned int                                                      rb1_p41;
    unsigned int                                                      rb1_p42;
    unsigned int                                                      rb1_p43;
    unsigned int                                                      rb1_p50;
    unsigned int                                                      rb1_p51;
    unsigned int                                                      rb1_p52;
    unsigned int                                                      rb1_p53;
    unsigned int                                                      rb1_p60;
    unsigned int                                                      rb1_p61;
    unsigned int                                                      rb1_p62;
    unsigned int                                                      rb1_p63;
    unsigned int                                                      rb1_p70;
    unsigned int                                                      rb1_p71;
    unsigned int                                                      rb1_p72;
    unsigned int                                                      rb1_p73;
} CHE_SID_CHE_NR_P_RPT_DOT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rb0_p00_p11;
    unsigned int                                                      rb0_p10;
    unsigned int                                                      rb0_p20;
    unsigned int                                                      rb0_p21;
    unsigned int                                                      rb0_p22_p33;
    unsigned int                                                      rb0_p30;
    unsigned int                                                      rb0_p31;
    unsigned int                                                      rb0_p32;
    unsigned int                                                      rb0_p44_p55;
    unsigned int                                                      rb0_p54;
    unsigned int                                                      rb0_p64;
    unsigned int                                                      rb0_p65;
    unsigned int                                                      rb0_p66_p77;
    unsigned int                                                      rb0_p74;
    unsigned int                                                      rb0_p75;
    unsigned int                                                      rb0_p76;
    unsigned int                                                      rb0_p40;
    unsigned int                                                      rb0_p41;
    unsigned int                                                      rb0_p42;
    unsigned int                                                      rb0_p43;
    unsigned int                                                      rb0_p50;
    unsigned int                                                      rb0_p51;
    unsigned int                                                      rb0_p52;
    unsigned int                                                      rb0_p53;
    unsigned int                                                      rb0_p60;
    unsigned int                                                      rb0_p61;
    unsigned int                                                      rb0_p62;
    unsigned int                                                      rb0_p63;
    unsigned int                                                      rb0_p70;
    unsigned int                                                      rb0_p71;
    unsigned int                                                      rb0_p72;
    unsigned int                                                      rb0_p73;
    unsigned int                                                      rb1_p00_p11;
    unsigned int                                                      rb1_p10;
    unsigned int                                                      rb1_p20;
    unsigned int                                                      rb1_p21;
    unsigned int                                                      rb1_p22_p33;
    unsigned int                                                      rb1_p30;
    unsigned int                                                      rb1_p31;
    unsigned int                                                      rb1_p32;
    unsigned int                                                      rb1_p44_p55;
    unsigned int                                                      rb1_p54;
    unsigned int                                                      rb1_p64;
    unsigned int                                                      rb1_p65;
    unsigned int                                                      rb1_p66_p77;
    unsigned int                                                      rb1_p74;
    unsigned int                                                      rb1_p75;
    unsigned int                                                      rb1_p76;
    unsigned int                                                      rb1_p40;
    unsigned int                                                      rb1_p41;
    unsigned int                                                      rb1_p42;
    unsigned int                                                      rb1_p43;
    unsigned int                                                      rb1_p50;
    unsigned int                                                      rb1_p51;
    unsigned int                                                      rb1_p52;
    unsigned int                                                      rb1_p53;
    unsigned int                                                      rb1_p60;
    unsigned int                                                      rb1_p61;
    unsigned int                                                      rb1_p62;
    unsigned int                                                      rb1_p63;
    unsigned int                                                      rb1_p70;
    unsigned int                                                      rb1_p71;
    unsigned int                                                      rb1_p72;
    unsigned int                                                      rb1_p73;
} CHE_SID_CHE_NR_P_RPT_DOT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rb0_p00_p11;
    unsigned int                                                      rb0_p10;
    unsigned int                                                      rb0_p20;
    unsigned int                                                      rb0_p21;
    unsigned int                                                      rb0_p22_p33;
    unsigned int                                                      rb0_p30;
    unsigned int                                                      rb0_p31;
    unsigned int                                                      rb0_p32;
    unsigned int                                                      rb1_p00_p11;
    unsigned int                                                      rb1_p10;
    unsigned int                                                      rb1_p20;
    unsigned int                                                      rb1_p21;
    unsigned int                                                      rb1_p22_p33;
    unsigned int                                                      rb1_p30;
    unsigned int                                                      rb1_p31;
    unsigned int                                                      rb1_p32;
} CHE_SID_CHE_LTE_DMRS_P_RPT_DOT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rb0_p00_p11;
    unsigned int                                                      rb0_p10;
    unsigned int                                                      rb0_p20;
    unsigned int                                                      rb0_p21;
    unsigned int                                                      rb0_p22_p33;
    unsigned int                                                      rb0_p30;
    unsigned int                                                      rb0_p31;
    unsigned int                                                      rb0_p32;
    unsigned int                                                      rb1_p00_p11;
    unsigned int                                                      rb1_p10;
    unsigned int                                                      rb1_p20;
    unsigned int                                                      rb1_p21;
    unsigned int                                                      rb1_p22_p33;
    unsigned int                                                      rb1_p30;
    unsigned int                                                      rb1_p31;
    unsigned int                                                      rb1_p32;
} CHE_SID_CHE_LTE_DMRS_P_RPT_DOT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rb0_p00_p11;
    unsigned int                                                      rb0_p10;
    unsigned int                                                      rb0_p20;
    unsigned int                                                      rb0_p21;
    unsigned int                                                      rb0_p22_p33;
    unsigned int                                                      rb0_p30;
    unsigned int                                                      rb0_p31;
    unsigned int                                                      rb0_p32;
    unsigned int                                                      rb1_p00_p11;
    unsigned int                                                      rb1_p10;
    unsigned int                                                      rb1_p20;
    unsigned int                                                      rb1_p21;
    unsigned int                                                      rb1_p22_p33;
    unsigned int                                                      rb1_p30;
    unsigned int                                                      rb1_p31;
    unsigned int                                                      rb1_p32;
} CHE_SID_CHE_LTE_PDS_CRS_P_RPT_DOT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rb0_p00_p11;
    unsigned int                                                      rb0_p10;
    unsigned int                                                      rb0_p20;
    unsigned int                                                      rb0_p21;
    unsigned int                                                      rb0_p22_p33;
    unsigned int                                                      rb0_p30;
    unsigned int                                                      rb0_p31;
    unsigned int                                                      rb0_p32;
    unsigned int                                                      rb1_p00_p11;
    unsigned int                                                      rb1_p10;
    unsigned int                                                      rb1_p20;
    unsigned int                                                      rb1_p21;
    unsigned int                                                      rb1_p22_p33;
    unsigned int                                                      rb1_p30;
    unsigned int                                                      rb1_p31;
    unsigned int                                                      rb1_p32;
} CHE_SID_CHE_LTE_PDS_CRS_P_RPT_DOT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      port0_rx0_rx3;
    unsigned int                                                      port1_rx0_rx3;
    unsigned int                                                      port2_rx0_rx3;
    unsigned int                                                      port3_rx0_rx3;
    unsigned int                                                      port4_rx0_rx3;
    unsigned int                                                      port5_rx0_rx3;
    unsigned int                                                      port6_rx0_rx3;
    unsigned int                                                      port7_rx0_rx3;
    unsigned int                                                      port8_rx0_rx3;
    unsigned int                                                      port9_rx0_rx3;
    unsigned int                                                      port10_rx0_rx3;
    unsigned int                                                      port11_rx0_rx3;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
    unsigned int                                                      reserved_2;
    unsigned int                                                      reserved_3;
    unsigned int                                                      port0_rx4_rx7;
    unsigned int                                                      port1_rx4_rx7;
    unsigned int                                                      port2_rx4_rx7;
    unsigned int                                                      port3_rx4_rx7;
    unsigned int                                                      port4_rx4_rx7;
    unsigned int                                                      port5_rx4_rx7;
    unsigned int                                                      port6_rx4_rx7;
    unsigned int                                                      port7_rx4_rx7;
    unsigned int                                                      port8_rx4_rx7;
    unsigned int                                                      port9_rx4_rx7;
    unsigned int                                                      port10_rx4_rx7;
    unsigned int                                                      port11_rx4_rx7;
    unsigned int                                                      reserved_4;
    unsigned int                                                      reserved_5;
    unsigned int                                                      reserved_6;
    unsigned int                                                      reserved_7;
} CHE_SID_CHE_NR_SNR_DB_DOT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      port0_rx0_rx3;
    unsigned int                                                      port1_rx0_rx3;
    unsigned int                                                      port2_rx0_rx3;
    unsigned int                                                      port3_rx0_rx3;
    unsigned int                                                      port4_rx0_rx3;
    unsigned int                                                      port5_rx0_rx3;
    unsigned int                                                      port6_rx0_rx3;
    unsigned int                                                      port7_rx0_rx3;
    unsigned int                                                      port8_rx0_rx3;
    unsigned int                                                      port9_rx0_rx3;
    unsigned int                                                      port10_rx0_rx3;
    unsigned int                                                      port11_rx0_rx3;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
    unsigned int                                                      reserved_2;
    unsigned int                                                      reserved_3;
    unsigned int                                                      port0_rx4_rx7;
    unsigned int                                                      port1_rx4_rx7;
    unsigned int                                                      port2_rx4_rx7;
    unsigned int                                                      port3_rx4_rx7;
    unsigned int                                                      port4_rx4_rx7;
    unsigned int                                                      port5_rx4_rx7;
    unsigned int                                                      port6_rx4_rx7;
    unsigned int                                                      port7_rx4_rx7;
    unsigned int                                                      port8_rx4_rx7;
    unsigned int                                                      port9_rx4_rx7;
    unsigned int                                                      port10_rx4_rx7;
    unsigned int                                                      port11_rx4_rx7;
    unsigned int                                                      reserved_4;
    unsigned int                                                      reserved_5;
    unsigned int                                                      reserved_6;
    unsigned int                                                      reserved_7;
} CHE_SID_CHE_NR_SNR_DB_DOT_BBP_MC;

typedef union {
    struct {
        unsigned int nr_dch0                                          :   1               ;    /* 0 */
        unsigned int nr_dch1                                          :   1               ;    /* 1 */
        unsigned int nr_dch2                                          :   1               ;    /* 2 */
        unsigned int nr_dch3                                          :   1               ;    /* 3 */
        unsigned int nr_dch4                                          :   1               ;    /* 4 */
        unsigned int nr_bch0                                          :   1               ;    /* 5 */
        unsigned int nr_bch1                                          :   1               ;    /* 6 */
        unsigned int nr_qrm                                           :   1               ;    /* 7 */
        unsigned int lte_dmrs                                         :   1               ;    /* 8 */
        unsigned int lte_pds_crs                                      :   1               ;    /* 9 */
        unsigned int lte_pb_crs                                       :   1               ;    /* 10 */
        unsigned int lte_pdc_crs                                      :   1               ;    /* 11 */
        unsigned int lte_ic_rych0                                     :   1               ;    /* 12 */
        unsigned int lte_ic_rych1                                     :   1               ;    /* 13 */
        unsigned int lte_ic_wych0                                     :   1               ;    /* 14 */
        unsigned int lte_ic_wych1                                     :   1               ;    /* 15 */
        unsigned int lte_ic_wych2                                     :   1               ;    /* 16 */
        unsigned int lte_pb_data                                      :   1               ;    /* 17 */
        unsigned int lte_ryy                                          :   1               ;    /* 18 */
        unsigned int lte_tfe_ic0                                      :   1               ;    /* 19 */
        unsigned int lte_tfe_ic1                                      :   1               ;    /* 20 */
        unsigned int lte_pdc_data                                     :   1               ;    /* 21 */
        unsigned int ltev_data                                        :   1               ;    /* 22 */
        unsigned int ltev_dmrs                                        :   1               ;    /* 23 */
        unsigned int lte_tfe_sym0                                     :   1               ;    /* 24 */
        unsigned int npdc                                             :   1               ;    /* 25 */
        unsigned int gsm                                              :   1               ;    /* 26 */
        unsigned int tts                                              :   1               ;    /* 27 */
        unsigned int umts                                             :   1               ;    /* 28 */
        unsigned int beam                                             :   1               ;    /* 29 */
        unsigned int csi                                              :   1               ;    /* 30 */
        unsigned int proc_timeout                                     :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB6;

typedef union {
    struct {
        unsigned int dch0_cfg_invld_warn                              :   1               ;    /* 0 */
        unsigned int dch0_data_miss_warn                              :   1               ;    /* 1 */
        unsigned int dch0_data_cov_warn                               :   1               ;    /* 2 */
        unsigned int dch0_systimer_slot                               :   2               ;    /* 4:3 */
        unsigned int dch0_crt_st                                      :   3               ;    /* 7:5 */
        unsigned int dch1_cfg_invld_warn                              :   1               ;    /* 8 */
        unsigned int dch1_data_miss_warn                              :   1               ;    /* 9 */
        unsigned int dch1_data_cov_warn                               :   1               ;    /* 10 */
        unsigned int dch1_systimer_slot                               :   2               ;    /* 12:11 */
        unsigned int dch1_crt_st                                      :   3               ;    /* 15:13 */
        unsigned int dch2_cfg_invld_warn                              :   1               ;    /* 16 */
        unsigned int dch2_data_miss_warn                              :   1               ;    /* 17 */
        unsigned int dch2_data_cov_warn                               :   1               ;    /* 18 */
        unsigned int dch2_systimer_slot                               :   2               ;    /* 20:19 */
        unsigned int dch2_crt_st                                      :   3               ;    /* 23:21 */
        unsigned int dch3_cfg_invld_warn                              :   1               ;    /* 24 */
        unsigned int dch3_data_miss_warn                              :   1               ;    /* 25 */
        unsigned int dch3_data_cov_warn                               :   1               ;    /* 26 */
        unsigned int dch3_systimer_slot                               :   2               ;    /* 28:27 */
        unsigned int dch3_crt_st                                      :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB7;

typedef union {
    struct {
        unsigned int dch4_cfg_invld_warn                              :   1               ;    /* 0 */
        unsigned int dch4_data_miss_warn                              :   1               ;    /* 1 */
        unsigned int dch4_data_cov_warn                               :   1               ;    /* 2 */
        unsigned int dch4_systimer_slot                               :   2               ;    /* 4:3 */
        unsigned int dch4_crt_st                                      :   3               ;    /* 7:5 */
        unsigned int bch0_cfg_invld_warn                              :   1               ;    /* 8 */
        unsigned int bch0_data_miss_warn                              :   1               ;    /* 9 */
        unsigned int bch0_data_cov_warn                               :   1               ;    /* 10 */
        unsigned int bch0_systimer_slot                               :   2               ;    /* 12:11 */
        unsigned int bch0_crt_st                                      :   3               ;    /* 15:13 */
        unsigned int bch1_cfg_invld_warn                              :   1               ;    /* 16 */
        unsigned int bch1_data_miss_warn                              :   1               ;    /* 17 */
        unsigned int bch1_data_cov_warn                               :   1               ;    /* 18 */
        unsigned int bch1_systimer_slot                               :   2               ;    /* 20:19 */
        unsigned int bch1_crt_st                                      :   3               ;    /* 23:21 */
        unsigned int qrm_cfg_invld_warn                               :   1               ;    /* 24 */
        unsigned int qrm_data_miss_warn                               :   1               ;    /* 25 */
        unsigned int qrm_data_cov_warn                                :   1               ;    /* 26 */
        unsigned int qrm_systimer_slot                                :   2               ;    /* 28:27 */
        unsigned int qrm_crt_st                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB8;

typedef union {
    struct {
        unsigned int dmrs_cfg_invld_warn                              :   1               ;    /* 0 */
        unsigned int dmrs_data_miss_warn                              :   1               ;    /* 1 */
        unsigned int dmrs_data_cov_warn                               :   1               ;    /* 2 */
        unsigned int dmrs_systimer_slot                               :   2               ;    /* 4:3 */
        unsigned int dmrs_crt_st                                      :   3               ;    /* 7:5 */
        unsigned int pds_crs_cfg_invld_warn                           :   1               ;    /* 8 */
        unsigned int pds_crs_data_miss_warn                           :   1               ;    /* 9 */
        unsigned int pds_crs_data_cov_warn                            :   1               ;    /* 10 */
        unsigned int pds_crs_systimer_slot                            :   2               ;    /* 12:11 */
        unsigned int pds_crs_crt_st                                   :   3               ;    /* 15:13 */
        unsigned int pb_crs_cfg_invld_warn                            :   1               ;    /* 16 */
        unsigned int pb_crs_data_miss_warn                            :   1               ;    /* 17 */
        unsigned int pb_crs_data_cov_warn                             :   1               ;    /* 18 */
        unsigned int pb_crs_systimer_slot                             :   2               ;    /* 20:19 */
        unsigned int pb_crs_crt_st                                    :   3               ;    /* 23:21 */
        unsigned int pdc_crs_cfg_invld_warn                           :   1               ;    /* 24 */
        unsigned int pdc_crs_data_miss_warn                           :   1               ;    /* 25 */
        unsigned int pdc_crs_data_cov_warn                            :   1               ;    /* 26 */
        unsigned int pdc_crs_systimer_slot                            :   2               ;    /* 28:27 */
        unsigned int pdc_crs_crt_st                                   :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB9;

typedef union {
    struct {
        unsigned int ic_rych0_cfg_invld_warn                          :   1               ;    /* 0 */
        unsigned int ic_rych0_data_miss_warn                          :   1               ;    /* 1 */
        unsigned int ic_rych0_data_cov_warn                           :   1               ;    /* 2 */
        unsigned int ic_rych0_systimer_slot                           :   2               ;    /* 4:3 */
        unsigned int ic_rych0_crt_st                                  :   3               ;    /* 7:5 */
        unsigned int ic_rych1_cfg_invld_warn                          :   1               ;    /* 8 */
        unsigned int ic_rych1_data_miss_warn                          :   1               ;    /* 9 */
        unsigned int ic_rych1_data_cov_warn                           :   1               ;    /* 10 */
        unsigned int ic_rych1_systimer_slot                           :   2               ;    /* 12:11 */
        unsigned int ic_rych1_crt_st                                  :   3               ;    /* 15:13 */
        unsigned int ic_wych0_cfg_invld_warn                          :   1               ;    /* 16 */
        unsigned int ic_wych0_data_miss_warn                          :   1               ;    /* 17 */
        unsigned int ic_wych0_systimer_slot                           :   3               ;    /* 20:18 */
        unsigned int ic_wych0_crt_st                                  :   3               ;    /* 23:21 */
        unsigned int ic_wych1_cfg_invld_warn                          :   1               ;    /* 24 */
        unsigned int ic_wych1_data_miss_warn                          :   1               ;    /* 25 */
        unsigned int ic_wych1_systimer_slot                           :   3               ;    /* 28:26 */
        unsigned int ic_wych1_crt_st                                  :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB10;

typedef union {
    struct {
        unsigned int ic_wych2_cfg_invld_warn                          :   1               ;    /* 0 */
        unsigned int ic_wych2_data_miss_warn                          :   1               ;    /* 1 */
        unsigned int ic_wych2_systimer_slot                           :   3               ;    /* 4:2 */
        unsigned int ic_wych2_crt_st                                  :   3               ;    /* 7:5 */
        unsigned int ic_pb_data_cfg_invld_warn                        :   1               ;    /* 8 */
        unsigned int ic_pb_data_data_miss_warn                        :   1               ;    /* 9 */
        unsigned int ic_pb_data_cov_warn                              :   1               ;    /* 10 */
        unsigned int ic_pb_data_systimer_slot                         :   2               ;    /* 12:11 */
        unsigned int ic_pb_data_crt_st                                :   3               ;    /* 15:13 */
        unsigned int ic_ryy_cfg_invld_warn                            :   1               ;    /* 16 */
        unsigned int ic_ryy_data_miss_warn                            :   1               ;    /* 17 */
        unsigned int ic_ryy_data_cov_warn                             :   1               ;    /* 18 */
        unsigned int ic_ryy_systimer_slot                             :   2               ;    /* 20:19 */
        unsigned int ic_ryy_crt_st                                    :   3               ;    /* 23:21 */
        unsigned int ic_tfe_ic0_cfg_invld_warn                        :   1               ;    /* 24 */
        unsigned int ic_tfe_ic0_data_miss_warn                        :   1               ;    /* 25 */
        unsigned int ic_tfe_ic0_data_cov_warn                         :   1               ;    /* 26 */
        unsigned int ic_tfe_ic0_systimer_slot                         :   2               ;    /* 28:27 */
        unsigned int ic_tfe_ic0_crt_st                                :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB11;

typedef union {
    struct {
        unsigned int ic_tfe_ic1_cfg_invld_warn                        :   1               ;    /* 0 */
        unsigned int ic_tfe_ic1_data_miss_warn                        :   1               ;    /* 1 */
        unsigned int ic_tfe_ic1_data_cov_warn                         :   1               ;    /* 2 */
        unsigned int ic_tfe_ic1_systimer_slot                         :   2               ;    /* 4:3 */
        unsigned int ic_tfe_ic1_crt_st                                :   3               ;    /* 7:5 */
        unsigned int pdc_data_cfg_invld_warn                          :   1               ;    /* 8 */
        unsigned int pdc_data_data_miss_warn                          :   1               ;    /* 9 */
        unsigned int pdc_data_cov_warn                                :   1               ;    /* 10 */
        unsigned int pdc_data_systimer_slot                           :   2               ;    /* 12:11 */
        unsigned int pdc_data_crt_st                                  :   3               ;    /* 15:13 */
        unsigned int ltev_data_cfg_invld_warn                         :   1               ;    /* 16 */
        unsigned int ltev_data_data_miss_warn                         :   1               ;    /* 17 */
        unsigned int ltev_data_cov_warn                               :   1               ;    /* 18 */
        unsigned int ltev_data_systimer_slot                          :   2               ;    /* 20:19 */
        unsigned int ltev_data_crt_st                                 :   3               ;    /* 23:21 */
        unsigned int ltev_dmrs_cfg_invld_warn                         :   1               ;    /* 24 */
        unsigned int ltev_dmrs_data_miss_warn                         :   1               ;    /* 25 */
        unsigned int ltev_dmrs_data_cov_warn                          :   1               ;    /* 26 */
        unsigned int ltev_dmrs_systimer_slot                          :   2               ;    /* 28:27 */
        unsigned int ltev_dmrs_crt_st                                 :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB12;

typedef union {
    struct {
        unsigned int tfe_sym0_cfg_invld_warn                          :   1               ;    /* 0 */
        unsigned int tfe_sym0_data_miss_warn                          :   1               ;    /* 1 */
        unsigned int tfe_sym0_data_cov_warn                           :   1               ;    /* 2 */
        unsigned int tfe_sym0_systimer_slot                           :   2               ;    /* 4:3 */
        unsigned int tfe_sym0_crt_st                                  :   3               ;    /* 7:5 */
        unsigned int u_inst0_fifo_warn                                :   1               ;    /* 8 */
        unsigned int u_inst0_sop_eop_warn                             :   1               ;    /* 9 */
        unsigned int u_inst0_int_overlap_warn                         :   1               ;    /* 10 */
        unsigned int u_inst0_guard_overlap_warn                       :   1               ;    /* 11 */
        unsigned int u_inst0_guard_invalid_warn                       :   1               ;    /* 12 */
        unsigned int u_inst0_crt_st                                   :   3               ;    /* 15:13 */
        unsigned int u_inst1_fifo_warn                                :   1               ;    /* 16 */
        unsigned int u_inst1_sop_eop_warn                             :   1               ;    /* 17 */
        unsigned int u_inst1_int_overlap_warn                         :   1               ;    /* 18 */
        unsigned int u_inst1_guard_overlap_warn                       :   1               ;    /* 19 */
        unsigned int u_inst1_guard_invalid_warn                       :   1               ;    /* 20 */
        unsigned int u_inst1_crt_st                                   :   3               ;    /* 23:21 */
        unsigned int u_equ0_cfg_invalid                               :   1               ;    /* 24 */
        unsigned int u_equ0_data_cov                                  :   1               ;    /* 25 */
        unsigned int u_equ1_cfg_invalid                               :   1               ;    /* 26 */
        unsigned int u_equ1_data_cov                                  :   1               ;    /* 27 */
        unsigned int gsm0_warn                                        :   1               ;    /* 28 */
        unsigned int t_warn                                           :   1               ;    /* 29 */
        unsigned int gsm1_warn                                        :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB13;

typedef union {
    struct {
        unsigned int npdc_cfg0_data_miss                              :   1               ;    /* 0 */
        unsigned int npdc_cfg0_vm_timeout                             :   1               ;    /* 1 */
        unsigned int npdc_cfg0_pde_cfg_timeout                        :   1               ;    /* 2 */
        unsigned int npdc_cfg0_gch_cfg_timeout                        :   1               ;    /* 3 */
        unsigned int npdc_cfg0_cfg_invld                              :   1               ;    /* 4 */
        unsigned int npdc_cfg0_cfg_int_overlap                        :   1               ;    /* 5 */
        unsigned int npdc_cfg0_cfg_abn_time                           :   1               ;    /* 6 */
        unsigned int npdc_cfg0_rsv_0                                  :   1               ;    /* 7 */
        unsigned int npdc_cfg0_crt_st                                 :   4               ;    /* 11:8 */
        unsigned int npdc_cfg0_t1_time                                :   8               ;    /* 19:12 */
        unsigned int npdc_cfg0_cfg_time                               :   8               ;    /* 27:20 */
        unsigned int npdc_cfg0_slot_idx                               :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB14;

typedef union {
    struct {
        unsigned int npdc_cfg1_data_miss                              :   1               ;    /* 0 */
        unsigned int npdc_cfg1_vm_timeout                             :   1               ;    /* 1 */
        unsigned int npdc_cfg1_pde_cfg_timeout                        :   1               ;    /* 2 */
        unsigned int npdc_cfg1_gch_cfg_timeout                        :   1               ;    /* 3 */
        unsigned int npdc_cfg1_cfg_invld                              :   1               ;    /* 4 */
        unsigned int npdc_cfg1_cfg_int_overlap                        :   1               ;    /* 5 */
        unsigned int npdc_cfg1_cfg_abn_time                           :   1               ;    /* 6 */
        unsigned int npdc_cfg1_rsv_0                                  :   1               ;    /* 7 */
        unsigned int npdc_cfg1_crt_st                                 :   4               ;    /* 11:8 */
        unsigned int npdc_cfg1_t1_time                                :   8               ;    /* 19:12 */
        unsigned int npdc_cfg1_cfg_time                               :   8               ;    /* 27:20 */
        unsigned int npdc_cfg1_slot_idx                               :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB15;

typedef union {
    struct {
        unsigned int npdc_cfg2_data_miss                              :   1               ;    /* 0 */
        unsigned int npdc_cfg2_vm_timeout                             :   1               ;    /* 1 */
        unsigned int npdc_cfg2_pde_cfg_timeout                        :   1               ;    /* 2 */
        unsigned int npdc_cfg2_gch_cfg_timeout                        :   1               ;    /* 3 */
        unsigned int npdc_cfg2_cfg_invld                              :   1               ;    /* 4 */
        unsigned int npdc_cfg2_cfg_int_overlap                        :   1               ;    /* 5 */
        unsigned int npdc_cfg2_cfg_abn_time                           :   1               ;    /* 6 */
        unsigned int npdc_cfg2_rsv_0                                  :   1               ;    /* 7 */
        unsigned int npdc_cfg2_crt_st                                 :   4               ;    /* 11:8 */
        unsigned int npdc_cfg2_t1_time                                :   8               ;    /* 19:12 */
        unsigned int npdc_cfg2_cfg_time                               :   8               ;    /* 27:20 */
        unsigned int npdc_cfg2_slot_idx                               :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB16;

typedef union {
    struct {
        unsigned int npdc_cfg3_data_miss                              :   1               ;    /* 0 */
        unsigned int npdc_cfg3_vm_timeout                             :   1               ;    /* 1 */
        unsigned int npdc_cfg3_pde_cfg_timeout                        :   1               ;    /* 2 */
        unsigned int npdc_cfg3_gch_cfg_timeout                        :   1               ;    /* 3 */
        unsigned int npdc_cfg3_cfg_invld                              :   1               ;    /* 4 */
        unsigned int npdc_cfg3_cfg_int_overlap                        :   1               ;    /* 5 */
        unsigned int npdc_cfg3_cfg_abn_time                           :   1               ;    /* 6 */
        unsigned int npdc_cfg3_rsv_0                                  :   1               ;    /* 7 */
        unsigned int npdc_cfg3_crt_st                                 :   4               ;    /* 11:8 */
        unsigned int npdc_cfg3_t1_time                                :   8               ;    /* 19:12 */
        unsigned int npdc_cfg3_cfg_time                               :   8               ;    /* 27:20 */
        unsigned int npdc_cfg3_slot_idx                               :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB17;

typedef union {
    struct {
        unsigned int npdc_cfg4_data_miss                              :   1               ;    /* 0 */
        unsigned int npdc_cfg4_vm_timeout                             :   1               ;    /* 1 */
        unsigned int npdc_cfg4_pde_cfg_timeout                        :   1               ;    /* 2 */
        unsigned int npdc_cfg4_gch_cfg_timeout                        :   1               ;    /* 3 */
        unsigned int npdc_cfg4_cfg_invld                              :   1               ;    /* 4 */
        unsigned int npdc_cfg4_cfg_int_overlap                        :   1               ;    /* 5 */
        unsigned int npdc_cfg4_cfg_abn_time                           :   1               ;    /* 6 */
        unsigned int npdc_cfg4_rsv_0                                  :   1               ;    /* 7 */
        unsigned int npdc_cfg4_crt_st                                 :   4               ;    /* 11:8 */
        unsigned int npdc_cfg4_t1_time                                :   8               ;    /* 19:12 */
        unsigned int npdc_cfg4_cfg_time                               :   8               ;    /* 27:20 */
        unsigned int npdc_cfg4_slot_idx                               :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB18;

typedef union {
    struct {
        unsigned int npdc_cfg0_pre_warn                               :   1               ;    /* 0 */
        unsigned int npdc_cfg0_pre_crt_st                             :   3               ;    /* 3:1 */
        unsigned int npdc_cfg1_pre_warn                               :   1               ;    /* 4 */
        unsigned int npdc_cfg1_pre_crt_st                             :   3               ;    /* 7:5 */
        unsigned int npdc_cfg2_pre_warn                               :   1               ;    /* 8 */
        unsigned int npdc_cfg2_pre_crt_st                             :   3               ;    /* 11:9 */
        unsigned int npdc_cfg3_pre_warn                               :   1               ;    /* 12 */
        unsigned int npdc_cfg3_pre_crt_st                             :   3               ;    /* 15:13 */
        unsigned int npdc_cfg4_pre_warn                               :   1               ;    /* 16 */
        unsigned int npdc_cfg4_pre_crt_st                             :   3               ;    /* 19:17 */
        unsigned int npdc_timer_vld                                   :   10              ;    /* 29:20 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB19;

typedef union {
    struct {
        unsigned int s2b_cfifo_cnt                                    :   13              ;    /* 12:0 */
        unsigned int s2b_dfifo_cnt                                    :   13              ;    /* 25:13 */
        unsigned int proc_ch_idx                                      :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB20;

typedef union {
    struct {
        unsigned int s2b_abn_alarm                                    :   8               ;    /* 7:0 */
        unsigned int s2b_dfifo_full                                   :   1               ;    /* 8 */
        unsigned int s2b_dfifo_empty                                  :   1               ;    /* 9 */
        unsigned int s2b_cfifo_full                                   :   1               ;    /* 10 */
        unsigned int s2b_cfifo_empty                                  :   1               ;    /* 11 */
        unsigned int xw_cc0_slot_idx                                  :   5               ;    /* 16:12 */
        unsigned int xw_cc0_data_len                                  :   5               ;    /* 21:17 */
        unsigned int xw_cc1_slot_idx                                  :   5               ;    /* 26:22 */
        unsigned int xw_cc1_data_len                                  :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB21;

typedef union {
    struct {
        unsigned int arb_2345g_crt_st                                 :   4               ;    /* 3:0 */
        unsigned int che_rx_num_err                                   :   1               ;    /* 4 */
        unsigned int che_rx_sel_err                                   :   1               ;    /* 5 */
        unsigned int che_pg_bmp_err                                   :   1               ;    /* 6 */
        unsigned int che_pg0_err                                      :   1               ;    /* 7 */
        unsigned int che_pg1_err                                      :   1               ;    /* 8 */
        unsigned int che_pg2_err                                      :   1               ;    /* 9 */
        unsigned int ptrs_gap_err                                     :   1               ;    /* 10 */
        unsigned int che_rb_num_err                                   :   1               ;    /* 11 */
        unsigned int che_err_rs_type                                  :   4               ;    /* 15:12 */
        unsigned int arb_45g_crt_st                                   :   3               ;    /* 18:16 */
        unsigned int arb_rsv0_0                                       :   1               ;    /* 19 */
        unsigned int mst_id_crt                                       :   4               ;    /* 23:20 */
        unsigned int mst_id_nxt                                       :   4               ;    /* 27:24 */
        unsigned int g_cc0_rs_type                                    :   2               ;    /* 29:28 */
        unsigned int g_cc1_rs_type                                    :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB22;

typedef union {
    struct {
        unsigned int fcsi_nzp_rsc_en                                  :   16              ;    /* 15:0 */
        unsigned int fcsi_rlm_rsc_en                                  :   8               ;    /* 23:16 */
        unsigned int fcsi_lte_rsc_en                                  :   5               ;    /* 28:24 */
        unsigned int fcsi_zp0_rsc_en                                  :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB23;

typedef union {
    struct {
        unsigned int fcsi_zp1_rsc_en                                  :   13              ;    /* 12:0 */
        unsigned int fcsi_rsv_rsc_en_0                                :   19              ;    /* 31:13 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB24;

typedef union {
    struct {
        unsigned int fcsi_arb_crt_st                                  :   4               ;    /* 3:0 */
        unsigned int fcsi_arb_cancel                                  :   4               ;    /* 7:4 */
        unsigned int fcsi_arb_res_idx                                 :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB25;

typedef union {
    struct {
        unsigned int beam_p0_fifo_cnt                                 :   6               ;    /* 5:0 */
        unsigned int beam_p0_fifo_afull                               :   1               ;    /* 6 */
        unsigned int beam_p0_fifo_empty                               :   1               ;    /* 7 */
        unsigned int beam_p1_fifo_cnt                                 :   6               ;    /* 13:8 */
        unsigned int beam_p1_fifo_afull                               :   1               ;    /* 14 */
        unsigned int beam_p1_fifo_empty                               :   1               ;    /* 15 */
        unsigned int beam_arb_res_idx                                 :   6               ;    /* 21:16 */
        unsigned int beam_arb_cancel                                  :   1               ;    /* 22 */
        unsigned int beam_wr_fifo_crt_st                              :   2               ;    /* 24:23 */
        unsigned int beam_rd_fifo_crt_st                              :   3               ;    /* 27:25 */
        unsigned int beam_rsv0_0                                      :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB28;

typedef union {
    struct {
        unsigned int fcsi_proc_crt_st                                 :   3               ;    /* 2:0 */
        unsigned int fcsi_symb_num_cnt_mwc                            :   3               ;    /* 5:3 */
        unsigned int fcsi_symb_num_cnt_mrc                            :   3               ;    /* 8:6 */
        unsigned int fcsi_rsv0_0                                      :   7               ;    /* 15:9 */
        unsigned int fcsi_rs_type                                     :   4               ;    /* 19:16 */
        unsigned int fcsi_symb_idx_err                                :   1               ;    /* 20 */
        unsigned int fcsi_re_bmp_err                                  :   1               ;    /* 21 */
        unsigned int fcsi_rb_num_err                                  :   1               ;    /* 22 */
        unsigned int fcsi_cdm_err                                     :   1               ;    /* 23 */
        unsigned int fcsi_symb_num_err                                :   1               ;    /* 24 */
        unsigned int fcsi_dens_err                                    :   1               ;    /* 25 */
        unsigned int fcsi_rx_num_err                                  :   1               ;    /* 26 */
        unsigned int fcsi_re_num_err                                  :   1               ;    /* 27 */
        unsigned int fcsi_rsv1_1                                      :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} CHE_SID_FPDF_DIF_DEBUG_INFO_SUB29;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      beam_warn_raw_int_status0;
    unsigned int                                                      beam_warn_raw_int_status1;
    unsigned int                                                      csi_warn_raw_int_status0;
    unsigned int                                                      csi_warn_raw_int_status1;
    unsigned int                                                      csi_warn_raw_int_status2;
    unsigned int                                                      csi_warn_raw_int_status3;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB6                                  om_data6;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB7                                  om_data7;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB8                                  om_data8;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB9                                  om_data9;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB10                                 om_data10;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB11                                 om_data11;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB12                                 om_data12;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB13                                 om_data13;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB14                                 om_data14;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB15                                 om_data15;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB16                                 om_data16;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB17                                 om_data17;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB18                                 om_data18;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB19                                 om_data19;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB20                                 om_data20;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB21                                 om_data21;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB22                                 om_data22;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB23                                 om_data23;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB24                                 om_data24;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB25                                 om_data25;
    unsigned int                                                      beam_rsc_en;
    unsigned int                                                      beam_rscv0;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB28                                 om_data28;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB29                                 om_data29;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
    unsigned int                                                      csi_warn_raw_int_status4;
    unsigned int                                                      csi_warn_raw_int_status5;
} CHE_SID_FPDF_DIF_DEBUG_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      beam_warn_raw_int_status0;
    unsigned int                                                      beam_warn_raw_int_status1;
    unsigned int                                                      csi_warn_raw_int_status0;
    unsigned int                                                      csi_warn_raw_int_status1;
    unsigned int                                                      csi_warn_raw_int_status2;
    unsigned int                                                      csi_warn_raw_int_status3;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB6                                  om_data6;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB7                                  om_data7;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB8                                  om_data8;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB9                                  om_data9;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB10                                 om_data10;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB11                                 om_data11;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB12                                 om_data12;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB13                                 om_data13;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB14                                 om_data14;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB15                                 om_data15;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB16                                 om_data16;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB17                                 om_data17;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB18                                 om_data18;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB19                                 om_data19;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB20                                 om_data20;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB21                                 om_data21;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB22                                 om_data22;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB23                                 om_data23;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB24                                 om_data24;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB25                                 om_data25;
    unsigned int                                                      beam_rsc_en;
    unsigned int                                                      beam_rscv0;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB28                                 om_data28;
    CHE_SID_FPDF_DIF_DEBUG_INFO_SUB29                                 om_data29;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
    unsigned int                                                      csi_warn_raw_int_status4;
    unsigned int                                                      csi_warn_raw_int_status5;
} CHE_SID_FPDF_DIF_DEBUG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int dsp_dfu_slot_conflict                            :   1               ;    /* 0 */
        unsigned int dsp_dfu_ofst_warn                                :   1               ;    /* 1 */
        unsigned int dsp_dfu_overlap_warn                             :   1               ;    /* 2 */
        unsigned int dsp_dfu_rx_err_warn                              :   1               ;    /* 3 */
        unsigned int dsp_dfu_gsm_warn                                 :   1               ;    /* 4 */
        unsigned int dsp_dfu_umts_warn                                :   1               ;    /* 5 */
        unsigned int dsp_mem_manager_warn                             :   2               ;    /* 7:6 */
        unsigned int dsp_buf_ctrl_warn                                :   1               ;    /* 8 */
        unsigned int dsp_cfg_err_warn                                 :   1               ;    /* 9 */
        unsigned int dsp_buf_alloc_warn                               :   1               ;    /* 10 */
        unsigned int dsp_fsau_dif_warn                                :   1               ;    /* 11 */
        unsigned int reserved_0                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DEBUG_INFO_SUB0;

typedef union {
    struct {
        unsigned int pde_dfu_slot_conflict                            :   1               ;    /* 0 */
        unsigned int pde_dfu_ofst_warn                                :   1               ;    /* 1 */
        unsigned int pde_dfu_overlap_warn                             :   1               ;    /* 2 */
        unsigned int pde_dfu_rx_err_warn                              :   1               ;    /* 3 */
        unsigned int pde_dfu_gsm_warn                                 :   1               ;    /* 4 */
        unsigned int pde_dfu_umts_warn                                :   1               ;    /* 5 */
        unsigned int pde_mem_manager_warn                             :   2               ;    /* 7:6 */
        unsigned int pde_buf_ctrl_warn                                :   1               ;    /* 8 */
        unsigned int pde_cfg_err_warn                                 :   1               ;    /* 9 */
        unsigned int pde_buf_alloc_warn                               :   1               ;    /* 10 */
        unsigned int pde_fsau_dif_warn                                :   1               ;    /* 11 */
        unsigned int reserved_0                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DEBUG_INFO_SUB1;

typedef union {
    struct {
        unsigned int dfu_slot_raw_conflict                            :   1               ;    /* 0 */
        unsigned int dfu_ofst_raw_warn                                :   1               ;    /* 1 */
        unsigned int dfu_overlap_raw_warn                             :   1               ;    /* 2 */
        unsigned int dfu_rx_err_raw_warn                              :   1               ;    /* 3 */
        unsigned int dfu_gsm_raw_warn                                 :   1               ;    /* 4 */
        unsigned int dfu_umts_raw_warn                                :   1               ;    /* 5 */
        unsigned int mem_manager_raw_warn                             :   2               ;    /* 7:6 */
        unsigned int buf_ctrl_raw_warn                                :   1               ;    /* 8 */
        unsigned int cfg_err_raw_warn                                 :   1               ;    /* 9 */
        unsigned int buf_alloc_raw_warn                               :   1               ;    /* 10 */
        unsigned int fsau_dif_raw_warn                                :   1               ;    /* 11 */
        unsigned int reserved_0                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} CHE_SID_FDBUF_DEBUG_INFO_SUB2;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CHE_SID_FDBUF_DEBUG_INFO_SUB0                                     om_data0;
    CHE_SID_FDBUF_DEBUG_INFO_SUB1                                     om_data1;
    CHE_SID_FDBUF_DEBUG_INFO_SUB2                                     om_data2;
    unsigned int                                                      dfu_dbg_info0_raw;
    unsigned int                                                      dfu_dbg_info1_raw;
    unsigned int                                                      dfu_dbg_info2_raw;
    unsigned int                                                      dfu_dbg_info3_raw;
    unsigned int                                                      umts_dfu_dbg_info0_raw;
    unsigned int                                                      umts_dfu_dbg_info1_raw;
    unsigned int                                                      gsm_dfu_dbg_info0_raw;
    unsigned int                                                      buf_ctrl_lte_dbg_info_raw;
    unsigned int                                                      mem_lut01_dbg_info_raw;
    unsigned int                                                      mem_lut23_dbg_info_raw;
    unsigned int                                                      mem_lut45_dbg_info_raw;
    unsigned int                                                      mem_lut67_dbg_info_raw;
    unsigned int                                                      mem_lut89_dbg_info_raw;
    unsigned int                                                      mem_lut1011_dbg_info_raw;
    unsigned int                                                      u_mem_lut01_dbg_info_raw;
    unsigned int                                                      u_mem_lut23_dbg_info_raw;
    unsigned int                                                      g_mem_lut01_dbg_info_raw;
    unsigned int                                                      mem_pool0_dbg_info_raw;
    unsigned int                                                      cr_cfg_dbg_info0_raw;
    unsigned int                                                      cr_cfg_dbg_info1_raw;
    unsigned int                                                      cr_buf_alloc_dbg_info_raw;
} CHE_SID_FDBUF_DEBUG_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CHE_SID_FDBUF_DEBUG_INFO_SUB0                                     om_data0;
    CHE_SID_FDBUF_DEBUG_INFO_SUB1                                     om_data1;
    CHE_SID_FDBUF_DEBUG_INFO_SUB2                                     om_data2;
    unsigned int                                                      dfu_dbg_info0_raw;
    unsigned int                                                      dfu_dbg_info1_raw;
    unsigned int                                                      dfu_dbg_info2_raw;
    unsigned int                                                      dfu_dbg_info3_raw;
    unsigned int                                                      umts_dfu_dbg_info0_raw;
    unsigned int                                                      umts_dfu_dbg_info1_raw;
    unsigned int                                                      gsm_dfu_dbg_info0_raw;
    unsigned int                                                      buf_ctrl_lte_dbg_info_raw;
    unsigned int                                                      mem_lut01_dbg_info_raw;
    unsigned int                                                      mem_lut23_dbg_info_raw;
    unsigned int                                                      mem_lut45_dbg_info_raw;
    unsigned int                                                      mem_lut67_dbg_info_raw;
    unsigned int                                                      mem_lut89_dbg_info_raw;
    unsigned int                                                      mem_lut1011_dbg_info_raw;
    unsigned int                                                      u_mem_lut01_dbg_info_raw;
    unsigned int                                                      u_mem_lut23_dbg_info_raw;
    unsigned int                                                      g_mem_lut01_dbg_info_raw;
    unsigned int                                                      mem_pool0_dbg_info_raw;
    unsigned int                                                      cr_cfg_dbg_info0_raw;
    unsigned int                                                      cr_cfg_dbg_info1_raw;
    unsigned int                                                      cr_buf_alloc_dbg_info_raw;
} CHE_SID_FDBUF_DEBUG_INFO_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
