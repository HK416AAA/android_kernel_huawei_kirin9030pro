

#ifndef __UPHY_PDE_XWIS_OM_H__
#define __UPHY_PDE_XWIS_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef union {
    struct {
        unsigned int burst_len                                        :   16              ;    /* 15:0 */
        unsigned int mode                                             :   4               ;    /* 19:16 */
        unsigned int cc_num                                           :   1               ;    /* 20 */
        unsigned int reserved_0                                       :   6               ;    /* 26:21 */
        unsigned int pingpang_idx                                     :   1               ;    /* 27 */
        unsigned int reserved_1                                       :   1               ;    /* 28 */
        unsigned int r                                                :   2               ;    /* 30:29 */
        unsigned int d                                                :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DATA_HUB_DIF_INFO_SUB0;

typedef union {
    struct {
        unsigned int pkg_cnt                                          :   16              ;    /* 15:0 */
        unsigned int data_len                                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DATA_HUB_DIF_INFO_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DATA_HUB_DIF_INFO_SUB0                              om_data0;
    XWIS_SID_XWIS_DATA_HUB_DIF_INFO_SUB1                              om_data1;
} XWIS_SID_XWIS_DATA_HUB_DIF_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DATA_HUB_DIF_INFO_SUB0                              om_data0;
    XWIS_SID_XWIS_DATA_HUB_DIF_INFO_SUB1                              om_data1;
} XWIS_SID_XWIS_DATA_HUB_DIF_INFO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DATA_HUB_DIF_INFO_SUB0                              om_data0;
    XWIS_SID_XWIS_DATA_HUB_DIF_INFO_SUB1                              om_data1;
} XWIS_SID_XWIS_DATA_HUB_DIF_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int lpf_filter_flag                                  :   1               ;    /* 0 */
        unsigned int rrc_filter_flag                                  :   1               ;    /* 1 */
        unsigned int rssi_calc_mode                                   :   1               ;    /* 2 */
        unsigned int lpf_coeff_sel                                    :   2               ;    /* 4:3 */
        unsigned int reserved_0                                       :   11              ;    /* 15:5 */
        unsigned int rx_num                                           :   4               ;    /* 19:16 */
        unsigned int data_less_en                                     :   1               ;    /* 20 */
        unsigned int rssi_sel_mode                                    :   1               ;    /* 21 */
        unsigned int reserved_1                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DATA_HUB_MSG_SUB0;

typedef union {
    struct {
        unsigned int dagc_en                                          :   1               ;    /* 0 */
        unsigned int dagc_fix_en                                      :   1               ;    /* 1 */
        unsigned int dagc_fix_qear                                    :   7               ;    /* 8:2 */
        unsigned int dagc_gain_bias                                   :   7               ;    /* 15:9 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DATA_HUB_MSG_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DATA_HUB_MSG_SUB0                                   om_data0;
    XWIS_SID_XWIS_DATA_HUB_MSG_SUB1                                   om_data1;
} XWIS_SID_XWIS_DATA_HUB_MSG;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DATA_HUB_MSG_SUB0                                   om_data0;
    XWIS_SID_XWIS_DATA_HUB_MSG_SUB1                                   om_data1;
} XWIS_SID_XWIS_DATA_HUB_MSG_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DATA_HUB_MSG_SUB0                                   om_data0;
    XWIS_SID_XWIS_DATA_HUB_MSG_SUB1                                   om_data1;
} XWIS_SID_XWIS_DATA_HUB_MSG_BBP_MC;

typedef union {
    struct {
        unsigned int pkg_cnt                                          :   16              ;    /* 15:0 */
        unsigned int curr_is_rx23                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DATA_HUB_FDAE_CH_BUSY_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DATA_HUB_FDAE_CH_BUSY_SUB0                          om_data0;
    unsigned int                                                      ch_id_debug_in;
} XWIS_SID_XWIS_DATA_HUB_FDAE_CH_BUSY;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DATA_HUB_FDAE_CH_BUSY_SUB0                          om_data0;
    unsigned int                                                      ch_id_debug_in;
} XWIS_SID_XWIS_DATA_HUB_FDAE_CH_BUSY_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DATA_HUB_FDAE_CH_BUSY_SUB0                          om_data0;
    unsigned int                                                      ch_id_debug_in;
} XWIS_SID_XWIS_DATA_HUB_FDAE_CH_BUSY_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      p_event;
    unsigned int                                                      rough_task_cnt;
} XWIS_SID_XWIS_SRCH_ROUGH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      p_event;
    unsigned int                                                      rough_task_cnt;
} XWIS_SID_XWIS_SRCH_ROUGH_IN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      rough_task_cnt;
} XWIS_SID_XWIS_SRCH_ROUGH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int srch_mode                                        :   16              ;    /* 15:0 */
        unsigned int rough_proc_end                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_SRCH_ROUGH_OUT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_SRCH_ROUGH_OUT_SUB0                                 om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_SRCH_ROUGH_OUT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_SRCH_ROUGH_OUT_SUB0                                 om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_SRCH_ROUGH_OUT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_SRCH_ROUGH_OUT_SUB0                                 om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_SRCH_ROUGH_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int rough_pos_ddr_idx                                :   8               ;    /* 7:0 */
        unsigned int rough_pos_num                                    :   8               ;    /* 15:8 */
        unsigned int cc_idx                                           :   8               ;    /* 23:16 */
        unsigned int rough_window_cnt                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_SRCH_FINE_DIF_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      srch_ddr_addr;
    XWIS_SID_XWIS_SRCH_FINE_DIF_SUB1                                  om_data1;
} XWIS_SID_XWIS_SRCH_FINE_DIF;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      srch_ddr_addr;
    XWIS_SID_XWIS_SRCH_FINE_DIF_SUB1                                  om_data1;
} XWIS_SID_XWIS_SRCH_FINE_DIF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      srch_ddr_addr;
    XWIS_SID_XWIS_SRCH_FINE_DIF_SUB1                                  om_data1;
} XWIS_SID_XWIS_SRCH_FINE_DIF_BBP_MC;

typedef union {
    struct {
        unsigned int fine_task_cnt                                    :   16              ;    /* 15:0 */
        unsigned int rough_freq_ofst                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_SRCH_FINE_IN_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_SRCH_FINE_IN_SUB0                                   om_data0;
    unsigned int                                                      rough_max_corr;
} XWIS_SID_XWIS_SRCH_FINE_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_SRCH_FINE_IN_SUB0                                   om_data0;
    unsigned int                                                      rough_max_corr;
} XWIS_SID_XWIS_SRCH_FINE_IN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_SRCH_FINE_IN_SUB0                                   om_data0;
    unsigned int                                                      rough_max_corr;
} XWIS_SID_XWIS_SRCH_FINE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int srch_mode                                        :   16              ;    /* 15:0 */
        unsigned int fine_proc_end                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_SRCH_FINE_OUT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_SRCH_FINE_OUT_SUB0                                  om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_SRCH_FINE_OUT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_SRCH_FINE_OUT_SUB0                                  om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_SRCH_FINE_OUT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_SRCH_FINE_OUT_SUB0                                  om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_SRCH_FINE_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      fft_grp_num;
    unsigned int                                                      rough_sub_cnt;
} XWIS_SID_XWIS_SRCH_ROUGH_PAC_TIME_OUT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      fft_grp_num;
    unsigned int                                                      rough_sub_cnt;
} XWIS_SID_XWIS_SRCH_ROUGH_PAC_TIME_OUT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      fft_grp_num;
    unsigned int                                                      rough_sub_cnt;
} XWIS_SID_XWIS_SRCH_ROUGH_PAC_TIME_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int pkt_cnt                                          :   8               ;    /* 7:0 */
        unsigned int update_data_flag                                 :   8               ;    /* 15:8 */
        unsigned int pkt_end_flag                                     :   8               ;    /* 23:16 */
        unsigned int task_end_flag                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_FCCH_IN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      in_para;
    XWIS_SID_XWIS_FCCH_IN_SUB1                                        om_data1;
} XWIS_SID_XWIS_FCCH_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      in_para;
    XWIS_SID_XWIS_FCCH_IN_SUB1                                        om_data1;
} XWIS_SID_XWIS_FCCH_IN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      in_para;
    XWIS_SID_XWIS_FCCH_IN_SUB1                                        om_data1;
} XWIS_SID_XWIS_FCCH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int max_freq_idx                                     :   8               ;    /* 7:0 */
        unsigned int max_pkt_idx                                      :   8               ;    /* 15:8 */
        unsigned int fcch_state0                                      :   8               ;    /* 23:16 */
        unsigned int fcch_state1                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_FCCH_OUT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      t_ofst;
    XWIS_SID_XWIS_FCCH_OUT_SUB1                                       om_data1;
} XWIS_SID_XWIS_FCCH_OUT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      t_ofst;
    XWIS_SID_XWIS_FCCH_OUT_SUB1                                       om_data1;
} XWIS_SID_XWIS_FCCH_OUT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      t_ofst;
    XWIS_SID_XWIS_FCCH_OUT_SUB1                                       om_data1;
} XWIS_SID_XWIS_FCCH_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int step_num                                         :   8               ;    /* 7:0 */
        unsigned int step_interval                                    :   8               ;    /* 15:8 */
        unsigned int step_cnt                                         :   8               ;    /* 23:16 */
        unsigned int freq_idx                                         :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_FCCH_PAC_TIME_OUT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pac_grp_num;
    XWIS_SID_XWIS_FCCH_PAC_TIME_OUT_SUB1                              om_data1;
} XWIS_SID_XWIS_FCCH_PAC_TIME_OUT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pac_grp_num;
    XWIS_SID_XWIS_FCCH_PAC_TIME_OUT_SUB1                              om_data1;
} XWIS_SID_XWIS_FCCH_PAC_TIME_OUT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pac_grp_num;
    XWIS_SID_XWIS_FCCH_PAC_TIME_OUT_SUB1                              om_data1;
} XWIS_SID_XWIS_FCCH_PAC_TIME_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      task_idx;
    unsigned int                                                      bursttype_rxnum_pingpang_ccidx;
} XWIS_SID_XWIS_TFE_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      task_idx;
    unsigned int                                                      bursttype_rxnum_pingpang_ccidx;
} XWIS_SID_XWIS_TFE_IN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      task_idx;
    unsigned int                                                      bursttype_rxnum_pingpang_ccidx;
} XWIS_SID_XWIS_TFE_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      to_val;
    unsigned int                                                      fo_val;
} XWIS_SID_XWIS_TFE_OUT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      to_val;
    unsigned int                                                      fo_val;
} XWIS_SID_XWIS_TFE_OUT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      to_val;
    unsigned int                                                      fo_val;
} XWIS_SID_XWIS_TFE_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pmbch_vm_addr_rx0;
    unsigned int                                                      pmbch_ddr_addr_rx0;
} XWIS_SID_XWIS_DEM_DEC_TOP_MIB_DAE;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pmbch_vm_addr_rx0;
    unsigned int                                                      pmbch_ddr_addr_rx0;
} XWIS_SID_XWIS_DEM_DEC_TOP_MIB_DAE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pmbch_vm_addr_rx0;
    unsigned int                                                      pmbch_ddr_addr_rx0;
} XWIS_SID_XWIS_DEM_DEC_TOP_MIB_DAE_BBP_MC;

typedef union {
    struct {
        unsigned int burst_type                                       :   6               ;    /* 5:0 */
        unsigned int reserved_0                                       :   2               ;    /* 7:6 */
        unsigned int rx_num                                           :   3               ;    /* 10:8 */
        unsigned int fo_sel                                           :   1               ;    /* 11 */
        unsigned int to_sel                                           :   1               ;    /* 12 */
        unsigned int fw_process_en                                    :   1               ;    /* 13 */
        unsigned int reserved_1                                       :   18              ;    /* 31:14 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_TOP_IN_SUB0;

typedef union {
    struct {
        unsigned int reserved_0                                       :   1               ;    /* 0 */
        unsigned int dem_dec_type                                     :   1               ;    /* 1 */
        unsigned int reserved_1                                       :   1               ;    /* 2 */
        unsigned int ping_pang_flag                                   :   1               ;    /* 3 */
        unsigned int cc_idx                                           :   1               ;    /* 4 */
        unsigned int reserved_2                                       :   27              ;    /* 31:5 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_TOP_IN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DEM_DEC_TOP_IN_SUB0                                 om_data0;
    XWIS_SID_XWIS_DEM_DEC_TOP_IN_SUB1                                 om_data1;
} XWIS_SID_XWIS_DEM_DEC_TOP_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DEM_DEC_TOP_IN_SUB0                                 om_data0;
    XWIS_SID_XWIS_DEM_DEC_TOP_IN_SUB1                                 om_data1;
} XWIS_SID_XWIS_DEM_DEC_TOP_IN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DEM_DEC_TOP_IN_SUB0                                 om_data0;
    XWIS_SID_XWIS_DEM_DEC_TOP_IN_SUB1                                 om_data1;
} XWIS_SID_XWIS_DEM_DEC_TOP_IN_BBP_MC;

typedef union {
    struct {
        unsigned int fw_fo_sel                                        :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   31              ;    /* 31:1 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_TOP_FW_SUB0;

typedef union {
    struct {
        unsigned int fo_val_use                                       :   16              ;    /* 15:0 */
        unsigned int fo_val_tfe                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_TOP_FW_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DEM_DEC_TOP_FW_SUB0                                 om_data0;
    XWIS_SID_XWIS_DEM_DEC_TOP_FW_SUB1                                 om_data1;
} XWIS_SID_XWIS_DEM_DEC_TOP_FW;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DEM_DEC_TOP_FW_SUB0                                 om_data0;
    XWIS_SID_XWIS_DEM_DEC_TOP_FW_SUB1                                 om_data1;
} XWIS_SID_XWIS_DEM_DEC_TOP_FW_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DEM_DEC_TOP_FW_SUB0                                 om_data0;
    XWIS_SID_XWIS_DEM_DEC_TOP_FW_SUB1                                 om_data1;
} XWIS_SID_XWIS_DEM_DEC_TOP_FW_BBP_MC;

typedef union {
    struct {
        unsigned int crc_iter                                         :   4               ;    /* 3:0 */
        unsigned int tot_iter_num                                     :   4               ;    /* 7:4 */
        unsigned int iter_idx                                         :   4               ;    /* 11:8 */
        unsigned int fscan_num                                        :   5               ;    /* 16:12 */
        unsigned int fscan_idx                                        :   5               ;    /* 21:17 */
        unsigned int fscan_break_en                                   :   1               ;    /* 22 */
        unsigned int dem_dec_stop                                     :   1               ;    /* 23 */
        unsigned int fscan_crc_his                                    :   1               ;    /* 24 */
        unsigned int iter_crc_his                                     :   1               ;    /* 25 */
        unsigned int psch_dec_en                                      :   1               ;    /* 26 */
        unsigned int dec_en                                           :   1               ;    /* 27 */
        unsigned int early_quit_en                                    :   1               ;    /* 28 */
        unsigned int reserved_0                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_TOP_ITER_SUB0;

typedef union {
    struct {
        unsigned int iter_metric_new                                  :   16              ;    /* 15:0 */
        unsigned int dec_mode_bitmap                                  :   8               ;    /* 23:16 */
        unsigned int llr_rec_bitmap                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_TOP_ITER_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DEM_DEC_TOP_ITER_SUB0                               om_data0;
    XWIS_SID_XWIS_DEM_DEC_TOP_ITER_SUB1                               om_data1;
} XWIS_SID_XWIS_DEM_DEC_TOP_ITER;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DEM_DEC_TOP_ITER_SUB0                               om_data0;
    XWIS_SID_XWIS_DEM_DEC_TOP_ITER_SUB1                               om_data1;
} XWIS_SID_XWIS_DEM_DEC_TOP_ITER_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DEM_DEC_TOP_ITER_SUB0                               om_data0;
    XWIS_SID_XWIS_DEM_DEC_TOP_ITER_SUB1                               om_data1;
} XWIS_SID_XWIS_DEM_DEC_TOP_ITER_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      to_val_use;
    unsigned int                                                      to_val_tfe;
} XWIS_SID_XWIS_DEM_DEC_TOP_TO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      to_val_use;
    unsigned int                                                      to_val_tfe;
} XWIS_SID_XWIS_DEM_DEC_TOP_TO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      to_val_use;
    unsigned int                                                      to_val_tfe;
} XWIS_SID_XWIS_DEM_DEC_TOP_TO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      corr1_pow_rx_merge;
    unsigned int                                                      corr0_pow_rx_merge;
} XWIS_SID_XWIS_DEM_UWDET_CORR0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      corr1_pow_rx_merge;
    unsigned int                                                      corr0_pow_rx_merge;
} XWIS_SID_XWIS_DEM_UWDET_CORR0_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      corr1_pow_rx_merge;
    unsigned int                                                      corr0_pow_rx_merge;
} XWIS_SID_XWIS_DEM_UWDET_CORR0_BBP_MC;

typedef union {
    struct {
        unsigned int uw_val                                           :   2               ;    /* 1:0 */
        unsigned int uw_val_det                                       :   2               ;    /* 3:2 */
        unsigned int uw_detect_force_val                              :   2               ;    /* 5:4 */
        unsigned int uw_detect_force_en                               :   1               ;    /* 6 */
        unsigned int uw_detect_mode                                   :   1               ;    /* 7 */
        unsigned int fw_fo_sel                                        :   1               ;    /* 8 */
        unsigned int fw_process_en                                    :   1               ;    /* 9 */
        unsigned int tfe_uw_val                                       :   2               ;    /* 11:10 */
        unsigned int dem_det_uw_val                                   :   2               ;    /* 13:12 */
        unsigned int reserved_0                                       :   18              ;    /* 31:14 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_UWDET_CORR1_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      corr2_pow_rx_merge;
    XWIS_SID_XWIS_DEM_UWDET_CORR1_SUB1                                om_data1;
} XWIS_SID_XWIS_DEM_UWDET_CORR1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      corr2_pow_rx_merge;
    XWIS_SID_XWIS_DEM_UWDET_CORR1_SUB1                                om_data1;
} XWIS_SID_XWIS_DEM_UWDET_CORR1_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      corr2_pow_rx_merge;
    XWIS_SID_XWIS_DEM_UWDET_CORR1_SUB1                                om_data1;
} XWIS_SID_XWIS_DEM_UWDET_CORR1_BBP_MC;

typedef union {
    struct {
        unsigned int fo                                               :   16              ;    /* 15:0 */
        unsigned int che_type                                         :   1               ;    /* 16 */
        unsigned int che_seg_num                                      :   5               ;    /* 21:17 */
        unsigned int che_uw_num                                       :   8               ;    /* 29:22 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEMRHO_SEGNUM_UWNUM_ITER_SUB0;

typedef union {
    struct {
        unsigned int dem_rho                                          :   16              ;    /* 15:0 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEMRHO_SEGNUM_UWNUM_ITER_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DEM_DEMRHO_SEGNUM_UWNUM_ITER_SUB0                   om_data0;
    XWIS_SID_XWIS_DEM_DEMRHO_SEGNUM_UWNUM_ITER_SUB1                   om_data1;
} XWIS_SID_XWIS_DEM_DEMRHO_SEGNUM_UWNUM_ITER;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DEM_DEMRHO_SEGNUM_UWNUM_ITER_SUB0                   om_data0;
    XWIS_SID_XWIS_DEM_DEMRHO_SEGNUM_UWNUM_ITER_SUB1                   om_data1;
} XWIS_SID_XWIS_DEM_DEMRHO_SEGNUM_UWNUM_ITER_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DEM_DEMRHO_SEGNUM_UWNUM_ITER_SUB0                   om_data0;
    XWIS_SID_XWIS_DEM_DEMRHO_SEGNUM_UWNUM_ITER_SUB1                   om_data1;
} XWIS_SID_XWIS_DEM_DEMRHO_SEGNUM_UWNUM_ITER_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      metric1;
    unsigned int                                                      metric2;
} XWIS_SID_XWIS_DEM_DEC_DEM_METRIC_ITER;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      metric1;
    unsigned int                                                      metric2;
} XWIS_SID_XWIS_DEM_DEC_DEM_METRIC_ITER_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      metric1;
    unsigned int                                                      metric2;
} XWIS_SID_XWIS_DEM_DEC_DEM_METRIC_ITER_BBP_MC;

typedef union {
    struct {
        unsigned int llr_th                                           :   16              ;    /* 15:0 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_RECONSTRUCT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DEM_DEC_RECONSTRUCT_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_DEM_DEC_RECONSTRUCT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DEM_DEC_RECONSTRUCT_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_DEM_DEC_RECONSTRUCT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DEM_DEC_RECONSTRUCT_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_DEM_DEC_RECONSTRUCT_BBP_MC;

typedef union {
    struct {
        unsigned int turbo_early_stop_succ_num                        :   5               ;    /* 4:0 */
        unsigned int turbo_early_stop_start_iter                      :   5               ;    /* 9:5 */
        unsigned int turbo_max_itr_tms                                :   5               ;    /* 14:10 */
        unsigned int crc_mask_en                                      :   1               ;    /* 15 */
        unsigned int crc_mask_revert                                  :   1               ;    /* 16 */
        unsigned int far_reduce_en                                    :   1               ;    /* 17 */
        unsigned int sms_enhance_en                                   :   1               ;    /* 18 */
        unsigned int reserved_0                                       :   1               ;    /* 19 */
        unsigned int iter_dec_last_flag                               :   1               ;    /* 20 */
        unsigned int iter_crc_his                                     :   1               ;    /* 21 */
        unsigned int crc_check                                        :   1               ;    /* 22 */
        unsigned int turbo_early_stop_flag                            :   1               ;    /* 23 */
        unsigned int turbo_actual_itr_num                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_TRB_SUB0;

typedef union {
    struct {
        unsigned int logch_type_prim                                  :   8               ;    /* 7:0 */
        unsigned int fscan_metric_result0                             :   12              ;    /* 19:8 */
        unsigned int reserved_0                                       :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_TRB_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DEM_DEC_TRB_SUB0                                    om_data0;
    XWIS_SID_XWIS_DEM_DEC_TRB_SUB1                                    om_data1;
} XWIS_SID_XWIS_DEM_DEC_TRB;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DEM_DEC_TRB_SUB0                                    om_data0;
    XWIS_SID_XWIS_DEM_DEC_TRB_SUB1                                    om_data1;
} XWIS_SID_XWIS_DEM_DEC_TRB_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DEM_DEC_TRB_SUB0                                    om_data0;
    XWIS_SID_XWIS_DEM_DEC_TRB_SUB1                                    om_data1;
} XWIS_SID_XWIS_DEM_DEC_TRB_BBP_MC;

typedef union {
    struct {
        unsigned int turbo_early_stop_succ_num                        :   5               ;    /* 4:0 */
        unsigned int turbo_early_stop_start_iter                      :   5               ;    /* 9:5 */
        unsigned int turbo_max_itr_tms                                :   5               ;    /* 14:10 */
        unsigned int crc_mask_en                                      :   1               ;    /* 15 */
        unsigned int crc_mask_revert                                  :   1               ;    /* 16 */
        unsigned int far_reduce_en                                    :   1               ;    /* 17 */
        unsigned int sms_enhance_en                                   :   1               ;    /* 18 */
        unsigned int reserved_0                                       :   3               ;    /* 21:19 */
        unsigned int crc_check                                        :   1               ;    /* 22 */
        unsigned int turbo_early_stop_flag                            :   1               ;    /* 23 */
        unsigned int turbo_actual_itr_num                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_SMS_SUB0;

typedef union {
    struct {
        unsigned int logch_type_prim                                  :   8               ;    /* 7:0 */
        unsigned int sms_min_idx                                      :   12              ;    /* 19:8 */
        unsigned int reserved_0                                       :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_SMS_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DEM_DEC_SMS_SUB0                                    om_data0;
    XWIS_SID_XWIS_DEM_DEC_SMS_SUB1                                    om_data1;
} XWIS_SID_XWIS_DEM_DEC_SMS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DEM_DEC_SMS_SUB0                                    om_data0;
    XWIS_SID_XWIS_DEM_DEC_SMS_SUB1                                    om_data1;
} XWIS_SID_XWIS_DEM_DEC_SMS_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DEM_DEC_SMS_SUB0                                    om_data0;
    XWIS_SID_XWIS_DEM_DEC_SMS_SUB1                                    om_data1;
} XWIS_SID_XWIS_DEM_DEC_SMS_BBP_MC;

typedef union {
    struct {
        unsigned int golay_bitinverse_m                               :   3               ;    /* 2:0 */
        unsigned int golay_threshold                                  :   8               ;    /* 10:3 */
        unsigned int golay_zero_llr_num_th                            :   5               ;    /* 15:11 */
        unsigned int reserved_0                                       :   6               ;    /* 21:16 */
        unsigned int s_id_cfg_vld                                     :   1               ;    /* 22 */
        unsigned int mcs_sel                                          :   1               ;    /* 23 */
        unsigned int mcs_cfg_val                                      :   3               ;    /* 26:24 */
        unsigned int mcs_bit_revert_flag                              :   1               ;    /* 27 */
        unsigned int pui_bit_mode                                     :   1               ;    /* 28 */
        unsigned int reserved_1                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_GLY_SUB0;

typedef union {
    struct {
        unsigned int golay_dec_corr_chk_flag                          :   1               ;    /* 0 */
        unsigned int golay_dec_zero_llr_check_flag                    :   1               ;    /* 1 */
        unsigned int pui_dec_flag_step0                               :   1               ;    /* 2 */
        unsigned int mcs_unvalid_flag                                 :   1               ;    /* 3 */
        unsigned int pui_dec_flag_step1                               :   1               ;    /* 4 */
        unsigned int s_id_uni_flag                                    :   1               ;    /* 5 */
        unsigned int pui_dec_flag_step2                               :   1               ;    /* 6 */
        unsigned int psch_dec_en                                      :   1               ;    /* 7 */
        unsigned int mcs_parse_val                                    :   3               ;    /* 10:8 */
        unsigned int mcs_final_val                                    :   3               ;    /* 13:11 */
        unsigned int fscan_idx                                        :   5               ;    /* 18:14 */
        unsigned int pui_bit_parse                                    :   12              ;    /* 30:19 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_GLY_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DEM_DEC_GLY_SUB0                                    om_data0;
    XWIS_SID_XWIS_DEM_DEC_GLY_SUB1                                    om_data1;
} XWIS_SID_XWIS_DEM_DEC_GLY;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DEM_DEC_GLY_SUB0                                    om_data0;
    XWIS_SID_XWIS_DEM_DEC_GLY_SUB1                                    om_data1;
} XWIS_SID_XWIS_DEM_DEC_GLY_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DEM_DEC_GLY_SUB0                                    om_data0;
    XWIS_SID_XWIS_DEM_DEC_GLY_SUB1                                    om_data1;
} XWIS_SID_XWIS_DEM_DEC_GLY_BBP_MC;

typedef union {
    struct {
        unsigned int corr_div_noise_sel_flag                          :   2               ;    /* 1:0 */
        unsigned int reserved_0                                       :   7               ;    /* 8:2 */
        unsigned int corr_interval                                    :   7               ;    /* 15:9 */
        unsigned int reserved_1                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_DEM_DEC_CORR_EST_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_DEM_DEC_CORR_EST_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_DEM_DEC_CORR_EST;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_DEM_DEC_CORR_EST_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_DEM_DEC_CORR_EST_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_DEM_DEC_CORR_EST_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_DEM_DEC_CORR_EST_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      dem_dec_cfg_addr;
    unsigned int                                                      dem_dec_rpt_addr;
} XWIS_SID_XWIS_DEM_DEC_TOP_OUT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      dem_dec_cfg_addr;
    unsigned int                                                      dem_dec_rpt_addr;
} XWIS_SID_XWIS_DEM_DEC_TOP_OUT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      dem_dec_cfg_addr;
    unsigned int                                                      dem_dec_rpt_addr;
} XWIS_SID_XWIS_DEM_DEC_TOP_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int burst_type                                       :   4               ;    /* 3:0 */
        unsigned int rate_type                                        :   2               ;    /* 5:4 */
        unsigned int reserved_0                                       :   2               ;    /* 7:6 */
        unsigned int pdch_type                                        :   3               ;    /* 10:8 */
        unsigned int reserved_1                                       :   1               ;    /* 11 */
        unsigned int msc_index                                        :   2               ;    /* 13:12 */
        unsigned int reserved_2                                       :   2               ;    /* 15:14 */
        unsigned int slot_idx                                         :   3               ;    /* 18:16 */
        unsigned int reserved_3                                       :   13              ;    /* 31:19 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_UL_ENC_IN_SUB0;

typedef union {
    struct {
        unsigned int crc_mask_en                                      :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   3               ;    /* 3:1 */
        unsigned int crc_mask_bit                                     :   16              ;    /* 19:4 */
        unsigned int reserved_1                                       :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_UL_ENC_IN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_UL_ENC_IN_SUB0                                      om_data0;
    XWIS_SID_XWIS_UL_ENC_IN_SUB1                                      om_data1;
} XWIS_SID_XWIS_UL_ENC_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_UL_ENC_IN_SUB0                                      om_data0;
    XWIS_SID_XWIS_UL_ENC_IN_SUB1                                      om_data1;
} XWIS_SID_XWIS_UL_ENC_IN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_UL_ENC_IN_SUB0                                      om_data0;
    XWIS_SID_XWIS_UL_ENC_IN_SUB1                                      om_data1;
} XWIS_SID_XWIS_UL_ENC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int pui                                              :   12              ;    /* 11:0 */
        unsigned int reserved_0                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_UL_ENC_PUI_IN_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_UL_ENC_PUI_IN_SUB0                                  om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_UL_ENC_PUI_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_UL_ENC_PUI_IN_SUB0                                  om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_UL_ENC_PUI_IN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_UL_ENC_PUI_IN_SUB0                                  om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_UL_ENC_PUI_IN_BBP_MC;

typedef union {
    struct {
        unsigned int rach_cw_mod_type                                 :   1               ;    /* 0 */
        unsigned int rrc_del_head                                     :   7               ;    /* 7:1 */
        unsigned int cfr_en                                           :   1               ;    /* 8 */
        unsigned int cfr_thres                                        :   13              ;    /* 21:9 */
        unsigned int lpf_en                                           :   1               ;    /* 22 */
        unsigned int win_en                                           :   1               ;    /* 23 */
        unsigned int win_len                                          :   3               ;    /* 26:24 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_UL_MOD_IN_SUB0;

typedef union {
    struct {
        unsigned int call_mode                                        :   1               ;    /* 0 */
        unsigned int split_no                                         :   4               ;    /* 4:1 */
        unsigned int mod_call_end                                     :   1               ;    /* 5 */
        unsigned int len_todo                                         :   5               ;    /* 10:6 */
        unsigned int len_done                                         :   10              ;    /* 20:11 */
        unsigned int reserved_0                                       :   11              ;    /* 31:21 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_UL_MOD_IN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_UL_MOD_IN_SUB0                                      om_data0;
    XWIS_SID_XWIS_UL_MOD_IN_SUB1                                      om_data1;
} XWIS_SID_XWIS_UL_MOD_IN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_UL_MOD_IN_SUB0                                      om_data0;
    XWIS_SID_XWIS_UL_MOD_IN_SUB1                                      om_data1;
} XWIS_SID_XWIS_UL_MOD_IN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_UL_MOD_IN_SUB0                                      om_data0;
    XWIS_SID_XWIS_UL_MOD_IN_SUB1                                      om_data1;
} XWIS_SID_XWIS_UL_MOD_IN_BBP_MC;

typedef union {
    struct {
        unsigned int crc_out                                          :   16              ;    /* 15:0 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_UL_ENC_CRC_OUT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_UL_ENC_CRC_OUT_SUB0                                 om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_UL_ENC_CRC_OUT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_UL_ENC_CRC_OUT_SUB0                                 om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_UL_ENC_CRC_OUT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_UL_ENC_CRC_OUT_SUB0                                 om_data0;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_UL_ENC_CRC_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} XWIS_SID_XWIS_DATA_HUB_XXX;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} XWIS_SID_XWIS_DATA_HUB_XXX_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} XWIS_SID_XWIS_DATA_HUB_XXX_BBP_MC;


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
} XWIS_SID_XWIS_SRCH_ROUGH_ALG_RPT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
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
} XWIS_SID_XWIS_SRCH_ROUGH_ALG_RPT_XWIS;


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
} XWIS_SID_XWIS_SRCH_ROUGH_ALG_RPT_BBP_MC;


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
} XWIS_SID_XWIS_SRCH_FINE_ALG_RPT;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
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
} XWIS_SID_XWIS_SRCH_FINE_ALG_RPT_XWIS;


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
} XWIS_SID_XWIS_SRCH_FINE_ALG_RPT_BBP_MC;


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
} XWIS_SID_XWIS_FCCH_DATA_4X;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
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
} XWIS_SID_XWIS_FCCH_DATA_4X_XWIS;


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
} XWIS_SID_XWIS_FCCH_DATA_4X_BBP_MC;


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
} XWIS_SID_XWIS_FCCH_CFG_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
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
} XWIS_SID_XWIS_FCCH_CFG_INFO_XWIS;


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
} XWIS_SID_XWIS_FCCH_CFG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int gain0                                            :   16              ;    /* 15:0 */
        unsigned int gain1                                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB0;

typedef union {
    struct {
        unsigned int gain2                                            :   16              ;    /* 15:0 */
        unsigned int data3                                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB1;

typedef union {
    struct {
        unsigned int gain4                                            :   16              ;    /* 15:0 */
        unsigned int data5                                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB2;

typedef union {
    struct {
        unsigned int gain6                                            :   16              ;    /* 15:0 */
        unsigned int data7                                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB3;

typedef union {
    struct {
        unsigned int gain8                                            :   16              ;    /* 15:0 */
        unsigned int data9                                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB4;

typedef union {
    struct {
        unsigned int gain10                                           :   16              ;    /* 15:0 */
        unsigned int data11                                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB5;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB0                                  om_data0;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB1                                  om_data1;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB2                                  om_data2;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB3                                  om_data3;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB4                                  om_data4;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB5                                  om_data5;
} XWIS_SID_XWIS_FCCH_AGC_GAIN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB0                                  om_data0;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB1                                  om_data1;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB2                                  om_data2;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB3                                  om_data3;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB4                                  om_data4;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB5                                  om_data5;
} XWIS_SID_XWIS_FCCH_AGC_GAIN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB0                                  om_data0;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB1                                  om_data1;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB2                                  om_data2;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB3                                  om_data3;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB4                                  om_data4;
    XWIS_SID_XWIS_FCCH_AGC_GAIN_SUB5                                  om_data5;
} XWIS_SID_XWIS_FCCH_AGC_GAIN_BBP_MC;


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
} XWIS_SID_XWIS_TFE_DATA_4X;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
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
} XWIS_SID_XWIS_TFE_DATA_4X_XWIS;


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
} XWIS_SID_XWIS_TFE_DATA_4X_BBP_MC;


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
} XWIS_SID_XWIS_TFE_DATA_1X;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
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
} XWIS_SID_XWIS_TFE_DATA_1X_XWIS;


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
} XWIS_SID_XWIS_TFE_DATA_1X_BBP_MC;


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
} XWIS_SID_XWIS_TFE_DATA_LLR;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
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
} XWIS_SID_XWIS_TFE_DATA_LLR_XWIS;


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
} XWIS_SID_XWIS_TFE_DATA_LLR_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
} XWIS_SID_XWIS_TFE_DATA_VLD_FLAG;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
} XWIS_SID_XWIS_TFE_DATA_VLD_FLAG_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
} XWIS_SID_XWIS_TFE_DATA_VLD_FLAG_BBP_MC;


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
} XWIS_SID_XWIS_TFE_INTF_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
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
} XWIS_SID_XWIS_TFE_INTF_INFO_XWIS;


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
} XWIS_SID_XWIS_TFE_INTF_INFO_BBP_MC;


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
} XWIS_SID_XWIS_TFE_RPT_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
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
} XWIS_SID_XWIS_TFE_RPT_INFO_XWIS;


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
} XWIS_SID_XWIS_TFE_RPT_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rssi_last_filter_agc_rx0;
    unsigned int                                                      rssi_last_filter_agc_rx1;
    unsigned int                                                      rssi_last_filter_agc_rx2;
    unsigned int                                                      rssi_last_filter_agc_rx3;
    unsigned int                                                      noise_last_filter_agc_rx0;
    unsigned int                                                      noise_last_filter_agc_rx1;
    unsigned int                                                      noise_last_filter_agc_rx2;
    unsigned int                                                      noise_last_filter_agc_rx3;
    unsigned int                                                      noise_cfg_agc_rx0;
    unsigned int                                                      noise_cfg_agc_rx1;
    unsigned int                                                      noise_cfg_agc_rx2;
    unsigned int                                                      noise_cfg_agc_rx3;
    unsigned int                                                      rssi_inst_rx0;
    unsigned int                                                      rssi_inst_rx1;
    unsigned int                                                      rssi_inst_rx2;
    unsigned int                                                      rssi_inst_rx3;
    unsigned int                                                      noise_inst_rx0;
    unsigned int                                                      noise_inst_rx1;
    unsigned int                                                      noise_inst_rx2;
    unsigned int                                                      noise_inst_rx3;
    unsigned int                                                      rssi_filter_rx0;
    unsigned int                                                      rssi_filter_rx1;
    unsigned int                                                      rssi_filter_rx2;
    unsigned int                                                      rssi_filter_rx3;
    unsigned int                                                      noise_filter_rx0;
    unsigned int                                                      noise_filter_rx1;
    unsigned int                                                      noise_filter_rx2;
    unsigned int                                                      noise_filter_rx3;
    unsigned int                                                      snr_inst_rx0;
    unsigned int                                                      snr_inst_rx1;
    unsigned int                                                      snr_inst_rx2;
    unsigned int                                                      snr_inst_rx3;
    unsigned int                                                      rsrp_inst_rx0;
    unsigned int                                                      rsrp_inst_rx1;
    unsigned int                                                      rsrp_inst_rx2;
    unsigned int                                                      rsrp_inst_rx3;
} XWIS_SID_XWIS_DEM_DEC_TOP_DEM_PARA;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      rssi_last_filter_agc_rx0;
    unsigned int                                                      rssi_last_filter_agc_rx1;
    unsigned int                                                      rssi_last_filter_agc_rx2;
    unsigned int                                                      rssi_last_filter_agc_rx3;
    unsigned int                                                      noise_last_filter_agc_rx0;
    unsigned int                                                      noise_last_filter_agc_rx1;
    unsigned int                                                      noise_last_filter_agc_rx2;
    unsigned int                                                      noise_last_filter_agc_rx3;
    unsigned int                                                      noise_cfg_agc_rx0;
    unsigned int                                                      noise_cfg_agc_rx1;
    unsigned int                                                      noise_cfg_agc_rx2;
    unsigned int                                                      noise_cfg_agc_rx3;
    unsigned int                                                      rssi_inst_rx0;
    unsigned int                                                      rssi_inst_rx1;
    unsigned int                                                      rssi_inst_rx2;
    unsigned int                                                      rssi_inst_rx3;
    unsigned int                                                      noise_inst_rx0;
    unsigned int                                                      noise_inst_rx1;
    unsigned int                                                      noise_inst_rx2;
    unsigned int                                                      noise_inst_rx3;
    unsigned int                                                      rssi_filter_rx0;
    unsigned int                                                      rssi_filter_rx1;
    unsigned int                                                      rssi_filter_rx2;
    unsigned int                                                      rssi_filter_rx3;
    unsigned int                                                      noise_filter_rx0;
    unsigned int                                                      noise_filter_rx1;
    unsigned int                                                      noise_filter_rx2;
    unsigned int                                                      noise_filter_rx3;
    unsigned int                                                      snr_inst_rx0;
    unsigned int                                                      snr_inst_rx1;
    unsigned int                                                      snr_inst_rx2;
    unsigned int                                                      snr_inst_rx3;
    unsigned int                                                      rsrp_inst_rx0;
    unsigned int                                                      rsrp_inst_rx1;
    unsigned int                                                      rsrp_inst_rx2;
    unsigned int                                                      rsrp_inst_rx3;
} XWIS_SID_XWIS_DEM_DEC_TOP_DEM_PARA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rssi_last_filter_agc_rx0;
    unsigned int                                                      rssi_last_filter_agc_rx1;
    unsigned int                                                      rssi_last_filter_agc_rx2;
    unsigned int                                                      rssi_last_filter_agc_rx3;
    unsigned int                                                      noise_last_filter_agc_rx0;
    unsigned int                                                      noise_last_filter_agc_rx1;
    unsigned int                                                      noise_last_filter_agc_rx2;
    unsigned int                                                      noise_last_filter_agc_rx3;
    unsigned int                                                      noise_cfg_agc_rx0;
    unsigned int                                                      noise_cfg_agc_rx1;
    unsigned int                                                      noise_cfg_agc_rx2;
    unsigned int                                                      noise_cfg_agc_rx3;
    unsigned int                                                      rssi_inst_rx0;
    unsigned int                                                      rssi_inst_rx1;
    unsigned int                                                      rssi_inst_rx2;
    unsigned int                                                      rssi_inst_rx3;
    unsigned int                                                      noise_inst_rx0;
    unsigned int                                                      noise_inst_rx1;
    unsigned int                                                      noise_inst_rx2;
    unsigned int                                                      noise_inst_rx3;
    unsigned int                                                      rssi_filter_rx0;
    unsigned int                                                      rssi_filter_rx1;
    unsigned int                                                      rssi_filter_rx2;
    unsigned int                                                      rssi_filter_rx3;
    unsigned int                                                      noise_filter_rx0;
    unsigned int                                                      noise_filter_rx1;
    unsigned int                                                      noise_filter_rx2;
    unsigned int                                                      noise_filter_rx3;
    unsigned int                                                      snr_inst_rx0;
    unsigned int                                                      snr_inst_rx1;
    unsigned int                                                      snr_inst_rx2;
    unsigned int                                                      snr_inst_rx3;
    unsigned int                                                      rsrp_inst_rx0;
    unsigned int                                                      rsrp_inst_rx1;
    unsigned int                                                      rsrp_inst_rx2;
    unsigned int                                                      rsrp_inst_rx3;
} XWIS_SID_XWIS_DEM_DEC_TOP_DEM_PARA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      noise_inst_rx0;
    unsigned int                                                      noise_inst_rx1;
    unsigned int                                                      noise_inst_rx2;
    unsigned int                                                      noise_inst_rx3;
} XWIS_SID_XWIS_DEM_PARA_EST_ITER;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      noise_inst_rx0;
    unsigned int                                                      noise_inst_rx1;
    unsigned int                                                      noise_inst_rx2;
    unsigned int                                                      noise_inst_rx3;
} XWIS_SID_XWIS_DEM_PARA_EST_ITER_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      noise_inst_rx0;
    unsigned int                                                      noise_inst_rx1;
    unsigned int                                                      noise_inst_rx2;
    unsigned int                                                      noise_inst_rx3;
} XWIS_SID_XWIS_DEM_PARA_EST_ITER_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      uw0_inst_noise_rx0;
    unsigned int                                                      uw1_inst_noise_rx0;
    unsigned int                                                      uw2_inst_noise_rx0;
    unsigned int                                                      uw0_inst_noise_rx1;
    unsigned int                                                      uw1_inst_noise_rx1;
    unsigned int                                                      uw2_inst_noise_rx1;
    unsigned int                                                      uw0_inst_noise_rx2;
    unsigned int                                                      uw1_inst_noise_rx2;
    unsigned int                                                      uw2_inst_noise_rx2;
    unsigned int                                                      uw0_inst_noise_rx3;
    unsigned int                                                      uw1_inst_noise_rx3;
    unsigned int                                                      uw2_inst_noise_rx3;
} XWIS_SID_XWIS_DEM_UWDET_INST_NOISE;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      uw0_inst_noise_rx0;
    unsigned int                                                      uw1_inst_noise_rx0;
    unsigned int                                                      uw2_inst_noise_rx0;
    unsigned int                                                      uw0_inst_noise_rx1;
    unsigned int                                                      uw1_inst_noise_rx1;
    unsigned int                                                      uw2_inst_noise_rx1;
    unsigned int                                                      uw0_inst_noise_rx2;
    unsigned int                                                      uw1_inst_noise_rx2;
    unsigned int                                                      uw2_inst_noise_rx2;
    unsigned int                                                      uw0_inst_noise_rx3;
    unsigned int                                                      uw1_inst_noise_rx3;
    unsigned int                                                      uw2_inst_noise_rx3;
} XWIS_SID_XWIS_DEM_UWDET_INST_NOISE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      uw0_inst_noise_rx0;
    unsigned int                                                      uw1_inst_noise_rx0;
    unsigned int                                                      uw2_inst_noise_rx0;
    unsigned int                                                      uw0_inst_noise_rx1;
    unsigned int                                                      uw1_inst_noise_rx1;
    unsigned int                                                      uw2_inst_noise_rx1;
    unsigned int                                                      uw0_inst_noise_rx2;
    unsigned int                                                      uw1_inst_noise_rx2;
    unsigned int                                                      uw2_inst_noise_rx2;
    unsigned int                                                      uw0_inst_noise_rx3;
    unsigned int                                                      uw1_inst_noise_rx3;
    unsigned int                                                      uw2_inst_noise_rx3;
} XWIS_SID_XWIS_DEM_UWDET_INST_NOISE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      enc_out0;
    unsigned int                                                      enc_out1;
    unsigned int                                                      enc_out2;
    unsigned int                                                      enc_out3;
    unsigned int                                                      enc_out4;
    unsigned int                                                      enc_out5;
    unsigned int                                                      enc_out6;
    unsigned int                                                      enc_out7;
    unsigned int                                                      enc_out8;
    unsigned int                                                      enc_out9;
    unsigned int                                                      enc_out10;
    unsigned int                                                      enc_out11;
    unsigned int                                                      enc_out12;
    unsigned int                                                      enc_out13;
    unsigned int                                                      enc_out14;
    unsigned int                                                      enc_out15;
} XWIS_SID_XWIS_UL_ENC_OUT_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      enc_out0;
    unsigned int                                                      enc_out1;
    unsigned int                                                      enc_out2;
    unsigned int                                                      enc_out3;
    unsigned int                                                      enc_out4;
    unsigned int                                                      enc_out5;
    unsigned int                                                      enc_out6;
    unsigned int                                                      enc_out7;
    unsigned int                                                      enc_out8;
    unsigned int                                                      enc_out9;
    unsigned int                                                      enc_out10;
    unsigned int                                                      enc_out11;
    unsigned int                                                      enc_out12;
    unsigned int                                                      enc_out13;
    unsigned int                                                      enc_out14;
    unsigned int                                                      enc_out15;
} XWIS_SID_XWIS_UL_ENC_OUT_INFO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      enc_out0;
    unsigned int                                                      enc_out1;
    unsigned int                                                      enc_out2;
    unsigned int                                                      enc_out3;
    unsigned int                                                      enc_out4;
    unsigned int                                                      enc_out5;
    unsigned int                                                      enc_out6;
    unsigned int                                                      enc_out7;
    unsigned int                                                      enc_out8;
    unsigned int                                                      enc_out9;
    unsigned int                                                      enc_out10;
    unsigned int                                                      enc_out11;
    unsigned int                                                      enc_out12;
    unsigned int                                                      enc_out13;
    unsigned int                                                      enc_out14;
    unsigned int                                                      enc_out15;
} XWIS_SID_XWIS_UL_ENC_OUT_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      bbp_waddr;
    unsigned int                                                      pde_raddr;
    unsigned int                                                      data_len;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_UL_MOD_MAXS_INFO;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      bbp_waddr;
    unsigned int                                                      pde_raddr;
    unsigned int                                                      data_len;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_UL_MOD_MAXS_INFO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      bbp_waddr;
    unsigned int                                                      pde_raddr;
    unsigned int                                                      data_len;
    unsigned int                                                      reserved_0;
} XWIS_SID_XWIS_UL_MOD_MAXS_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int enc_type                                         :   16              ;    /* 15:0 */
        unsigned int burst_type                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_UL_WARN_SUB0;

typedef union {
    struct {
        unsigned int split_no                                         :   16              ;    /* 15:0 */
        unsigned int len_done                                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} XWIS_SID_XWIS_UL_WARN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    XWIS_SID_XWIS_UL_WARN_SUB0                                        om_data0;
    XWIS_SID_XWIS_UL_WARN_SUB1                                        om_data1;
} XWIS_SID_XWIS_UL_WARN;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    XWIS_SID_XWIS_UL_WARN_SUB0                                        om_data0;
    XWIS_SID_XWIS_UL_WARN_SUB1                                        om_data1;
} XWIS_SID_XWIS_UL_WARN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    XWIS_SID_XWIS_UL_WARN_SUB0                                        om_data0;
    XWIS_SID_XWIS_UL_WARN_SUB1                                        om_data1;
} XWIS_SID_XWIS_UL_WARN_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
