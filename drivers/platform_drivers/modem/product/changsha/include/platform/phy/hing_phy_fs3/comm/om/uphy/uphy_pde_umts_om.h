

#ifndef __UPHY_PDE_UMTS_OM_H__
#define __UPHY_PDE_UMTS_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef union {
    struct {
        unsigned int sfn_timing                                       :   3               ;    /* 2:0 */
        unsigned int cpich_slot_timing                                :   4               ;    /* 6:3 */
        unsigned int rach_state_timing                                :   5               ;    /* 11:7 */
        unsigned int preamble_num_timing                              :   8               ;    /* 19:12 */
        unsigned int reserved_0                                       :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_RACH_TIMING_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int mc_cnt_timing                                    :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_RACH_TIMING_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_XCTRL_RACH_TIMING_IN_UMTS_SUB0                           om_data0;
    UMTS_SID_XCTRL_RACH_TIMING_IN_UMTS_SUB1                           om_data1;
} UMTS_SID_XCTRL_RACH_TIMING_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_XCTRL_RACH_TIMING_IN_UMTS_SUB0                           om_data0;
    UMTS_SID_XCTRL_RACH_TIMING_IN_UMTS_SUB1                           om_data1;
} UMTS_SID_XCTRL_RACH_TIMING_IN_BBP_MC;

typedef union {
    struct {
        unsigned int sfn_ai                                           :   3               ;    /* 2:0 */
        unsigned int cpich_slot_ai                                    :   4               ;    /* 6:3 */
        unsigned int rach_state_ai                                    :   5               ;    /* 11:7 */
        unsigned int preamble_num_ai                                  :   8               ;    /* 19:12 */
        unsigned int ai_flag                                          :   2               ;    /* 21:20 */
        unsigned int reserved_0                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_RACH_AI_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int mc_cnt_ai                                        :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_RACH_AI_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_XCTRL_RACH_AI_IN_UMTS_SUB0                               om_data0;
    UMTS_SID_XCTRL_RACH_AI_IN_UMTS_SUB1                               om_data1;
} UMTS_SID_XCTRL_RACH_AI_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_XCTRL_RACH_AI_IN_UMTS_SUB0                               om_data0;
    UMTS_SID_XCTRL_RACH_AI_IN_UMTS_SUB1                               om_data1;
} UMTS_SID_XCTRL_RACH_AI_IN_BBP_MC;

typedef union {
    struct {
        unsigned int cfn                                              :   8               ;    /* 7:0 */
        unsigned int sys_slot                                         :   4               ;    /* 11:8 */
        unsigned int hsscch_slot                                      :   4               ;    /* 15:12 */
        unsigned int hsdpcch_slot                                     :   4               ;    /* 19:16 */
        unsigned int ul_dch_estb                                      :   1               ;    /* 20 */
        unsigned int ul_edch_estb                                     :   1               ;    /* 21 */
        unsigned int ul_dpa_en                                        :   1               ;    /* 22 */
        unsigned int dch_gap_en                                       :   1               ;    /* 23 */
        unsigned int hsscch_gap_en                                    :   1               ;    /* 24 */
        unsigned int hspdsch_gap_en                                   :   1               ;    /* 25 */
        unsigned int hsdpcch_harq_gap_en                              :   1               ;    /* 26 */
        unsigned int hsdpcch_cqi_gap_en                               :   1               ;    /* 27 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_TIMING_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int mc_cnt_trace                                     :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_TIMING_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_XCTRL_DCH_TIMING_IN_UMTS_SUB0                            om_data0;
    UMTS_SID_XCTRL_DCH_TIMING_IN_UMTS_SUB1                            om_data1;
} UMTS_SID_XCTRL_DCH_TIMING_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_XCTRL_DCH_TIMING_IN_UMTS_SUB0                            om_data0;
    UMTS_SID_XCTRL_DCH_TIMING_IN_UMTS_SUB1                            om_data1;
} UMTS_SID_XCTRL_DCH_TIMING_IN_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      umts_cs_stepa_task_id;
    unsigned int                                                      umts_cs_stepa_statu;
} UMTS_SID_CS_STEPA_TRACE_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      umts_cs_stepa_task_id;
    unsigned int                                                      umts_cs_stepa_statu;
} UMTS_SID_CS_STEPA_TRACE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int umts_cs_stepa_rpt_en                             :   16              ;    /* 15:0 */
        unsigned int umts_cs_stepa_a_en                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_TRACE_OUT_UMTS_SUB0;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sort_post_statu                    :   16              ;    /* 15:0 */
        unsigned int umts_cs_stepa_sort_pre_statu                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_TRACE_OUT_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_CS_STEPA_TRACE_OUT_UMTS_SUB0                             om_data0;
    UMTS_SID_CS_STEPA_TRACE_OUT_UMTS_SUB1                             om_data1;
} UMTS_SID_CS_STEPA_TRACE_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_CS_STEPA_TRACE_OUT_UMTS_SUB0                             om_data0;
    UMTS_SID_CS_STEPA_TRACE_OUT_UMTS_SUB1                             om_data1;
} UMTS_SID_CS_STEPA_TRACE_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      umts_cs_stepb_ring_buffer_addr;
    unsigned int                                                      umts_cs_stepb_trans_rsv0_0;
} UMTS_SID_CS_STEPB_TRANS_TRACE_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      umts_cs_stepb_ring_buffer_addr;
    unsigned int                                                      umts_cs_stepb_trans_rsv0_0;
} UMTS_SID_CS_STEPB_TRANS_TRACE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int umts_cs_stepb_proc_num                           :   16              ;    /* 15:0 */
        unsigned int umts_cs_stepb_sym_cnt                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPB_TRANS_TRACE_OUT_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_CS_STEPB_TRANS_TRACE_OUT_UMTS_SUB0                       om_data0;
    unsigned int                                                      umts_cs_stepb_slot_start_addr;
} UMTS_SID_CS_STEPB_TRANS_TRACE_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_CS_STEPB_TRANS_TRACE_OUT_UMTS_SUB0                       om_data0;
    unsigned int                                                      umts_cs_stepb_slot_start_addr;
} UMTS_SID_CS_STEPB_TRANS_TRACE_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int umts_cs_stepb_init_flag                          :   1               ;    /* 0 */
        unsigned int umts_cs_stepb_type                               :   1               ;    /* 1 */
        unsigned int umts_cs_stepb_intra_inter_flag                   :   1               ;    /* 2 */
        unsigned int umts_cs_stepb_afc_lock                           :   1               ;    /* 3 */
        unsigned int umts_cs_stepb_proc_rsv0_0                        :   12              ;    /* 15:4 */
        unsigned int umts_cs_stepb_scram_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPB_PROC_TRACE_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int umts_cs_stepb_cell_scram_num0                    :   16              ;    /* 15:0 */
        unsigned int umts_cs_stepb_cell_scram_num1                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPB_PROC_TRACE_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_CS_STEPB_PROC_TRACE_IN_UMTS_SUB0                         om_data0;
    UMTS_SID_CS_STEPB_PROC_TRACE_IN_UMTS_SUB1                         om_data1;
} UMTS_SID_CS_STEPB_PROC_TRACE_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_CS_STEPB_PROC_TRACE_IN_UMTS_SUB0                         om_data0;
    UMTS_SID_CS_STEPB_PROC_TRACE_IN_UMTS_SUB1                         om_data1;
} UMTS_SID_CS_STEPB_PROC_TRACE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int umts_cs_stepb_cell_pn_num_addr                   :   16              ;    /* 15:0 */
        unsigned int umts_cs_stepb_cell_pn_num                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPB_PROC_TRACE_OUT_UMTS_SUB0;

typedef union {
    struct {
        unsigned int umts_cs_stepb_rpt_en                             :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepb_alg_en                             :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepb_slot_num                           :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepb_2sym_cnt                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPB_PROC_TRACE_OUT_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_CS_STEPB_PROC_TRACE_OUT_UMTS_SUB0                        om_data0;
    UMTS_SID_CS_STEPB_PROC_TRACE_OUT_UMTS_SUB1                        om_data1;
} UMTS_SID_CS_STEPB_PROC_TRACE_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_CS_STEPB_PROC_TRACE_OUT_UMTS_SUB0                        om_data0;
    UMTS_SID_CS_STEPB_PROC_TRACE_OUT_UMTS_SUB1                        om_data1;
} UMTS_SID_CS_STEPB_PROC_TRACE_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int mps_msg_group_vldflag                            :   8               ;    /* 7:0 */
        unsigned int mps_en_vldflag                                   :   11              ;    /* 18:8 */
        unsigned int reserved_0                                       :   13              ;    /* 31:19 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_MSG_PROC_IN_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_MPS_MSG_PROC_IN_UMTS_SUB0                                om_data0;
    unsigned int                                                      mps_msg_id;
} UMTS_SID_MPS_MSG_PROC_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_MPS_MSG_PROC_IN_UMTS_SUB0                                om_data0;
    unsigned int                                                      mps_msg_id;
} UMTS_SID_MPS_MSG_PROC_IN_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      mps_msg_group_vldflag;
    unsigned int                                                      mps_msg_en_vldflag;
} UMTS_SID_MPS_MSG_PROC_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      mps_msg_group_vldflag;
    unsigned int                                                      mps_msg_en_vldflag;
} UMTS_SID_MPS_MSG_PROC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int task_id                                          :   2               ;    /* 1:0 */
        unsigned int mps_unit_busy_flag                               :   11              ;    /* 12:2 */
        unsigned int mps_unit_rpt_flag_c_in                           :   11              ;    /* 23:13 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_C_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int mps_mask                                         :   1               ;    /* 0 */
        unsigned int mps_msg_group_vldflag                            :   8               ;    /* 8:1 */
        unsigned int reserved_0                                       :   23              ;    /* 31:9 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_C_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_MPS_C_IN_UMTS_SUB0                                       om_data0;
    UMTS_SID_MPS_C_IN_UMTS_SUB1                                       om_data1;
} UMTS_SID_MPS_C_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_MPS_C_IN_UMTS_SUB0                                       om_data0;
    UMTS_SID_MPS_C_IN_UMTS_SUB1                                       om_data1;
} UMTS_SID_MPS_C_IN_BBP_MC;

typedef union {
    struct {
        unsigned int mps_a_en_main                                    :   1               ;    /* 0 */
        unsigned int mps_a_en_div                                     :   1               ;    /* 1 */
        unsigned int finger_select_en                                 :   11              ;    /* 12:2 */
        unsigned int mps_unit_rpt_flag                                :   11              ;    /* 23:13 */
        unsigned int mps_total_unit_num                               :   4               ;    /* 27:24 */
        unsigned int mps_total_pn_num                                 :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_ALG_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int data_mv_addr_main                                :   13              ;    /* 12:0 */
        unsigned int data_mv_addr_div                                 :   13              ;    /* 25:13 */
        unsigned int mps_a_en                                         :   1               ;    /* 26 */
        unsigned int mps_corr_num_1_a                                 :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_ALG_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_MPS_ALG_IN_UMTS_SUB0                                     om_data0;
    UMTS_SID_MPS_ALG_IN_UMTS_SUB1                                     om_data1;
} UMTS_SID_MPS_ALG_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_MPS_ALG_IN_UMTS_SUB0                                     om_data0;
    UMTS_SID_MPS_ALG_IN_UMTS_SUB1                                     om_data1;
} UMTS_SID_MPS_ALG_IN_BBP_MC;

typedef union {
    struct {
        unsigned int mps_alg_out_flag                                 :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   31              ;    /* 31:1 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_ALG_OUT_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reserved_0;
    UMTS_SID_MPS_ALG_OUT_UMTS_SUB1                                    om_data1;
} UMTS_SID_MPS_ALG_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    UMTS_SID_MPS_ALG_OUT_UMTS_SUB1                                    om_data1;
} UMTS_SID_MPS_ALG_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int mps_rpt_group_id                                 :   4               ;    /* 3:0 */
        unsigned int mps_rpt_bitmap                                   :   11              ;    /* 14:4 */
        unsigned int reserved_0                                       :   17              ;    /* 31:15 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_RPT_OUT_UMTS_SUB0;

typedef union {
    struct {
        unsigned int mps_status_rx_main                               :   1               ;    /* 0 */
        unsigned int mps_status_rx_div                                :   1               ;    /* 1 */
        unsigned int mps_msg_group_vldflag                            :   8               ;    /* 9:2 */
        unsigned int mps_unit_busy_flag                               :   11              ;    /* 20:10 */
        unsigned int mps_unit_rpt_flag                                :   11              ;    /* 31:21 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_RPT_OUT_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_MPS_RPT_OUT_UMTS_SUB0                                    om_data0;
    UMTS_SID_MPS_RPT_OUT_UMTS_SUB1                                    om_data1;
} UMTS_SID_MPS_RPT_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_MPS_RPT_OUT_UMTS_SUB0                                    om_data0;
    UMTS_SID_MPS_RPT_OUT_UMTS_SUB1                                    om_data1;
} UMTS_SID_MPS_RPT_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int fg_ud_acute_ind                                  :   16              ;    /* 15:0 */
        unsigned int fg_en                                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_CPICH_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int scram_num                                        :   13              ;    /* 12:0 */
        unsigned int nbhd_flag                                        :   1               ;    /* 13 */
        unsigned int pri_rl_no                                        :   3               ;    /* 16:14 */
        unsigned int tx_diversity_mode                                :   2               ;    /* 18:17 */
        unsigned int ovsf                                             :   8               ;    /* 26:19 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_CPICH_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_CPICH_IN_UMTS_SUB0                                  om_data0;
    UMTS_SID_RAKE_CPICH_IN_UMTS_SUB1                                  om_data1;
} UMTS_SID_RAKE_CPICH_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_CPICH_IN_UMTS_SUB0                                  om_data0;
    UMTS_SID_RAKE_CPICH_IN_UMTS_SUB1                                  om_data1;
} UMTS_SID_RAKE_CPICH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int div_fg_sl                                        :   16              ;    /* 15:0 */
        unsigned int div_fg_sttd                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_PC_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int slotformat_index_pc                              :   7               ;    /* 6:0 */
        unsigned int algorithm_dltpc                                  :   1               ;    /* 7 */
        unsigned int algorithm_ultpc                                  :   1               ;    /* 8 */
        unsigned int cld_en                                           :   1               ;    /* 9 */
        unsigned int div_fg_cld                                       :   16              ;    /* 25:10 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_PC_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_PC_IN_UMTS_SUB0                                     om_data0;
    UMTS_SID_RAKE_PC_IN_UMTS_SUB1                                     om_data1;
} UMTS_SID_RAKE_PC_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_PC_IN_UMTS_SUB0                                     om_data0;
    UMTS_SID_RAKE_PC_IN_UMTS_SUB1                                     om_data1;
} UMTS_SID_RAKE_PC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int cpu_piai_div_mode                                :   2               ;    /* 1:0 */
        unsigned int cpu_ai_threshold                                 :   10              ;    /* 11:2 */
        unsigned int cpu_ai_pi_ovsf                                   :   9               ;    /* 20:12 */
        unsigned int ai_rl_no                                         :   4               ;    /* 24:21 */
        unsigned int reserved_0                                       :   7               ;    /* 31:25 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_AICH_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int ai_scram_num                                     :   6               ;    /* 5:0 */
        unsigned int reserved_0                                       :   26              ;    /* 31:6 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_AICH_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_AICH_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_RAKE_AICH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_AICH_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_AICH_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_RAKE_AICH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_AICH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int cpu_piai_div_mode                                :   2               ;    /* 1:0 */
        unsigned int cpu_pi_cpst                                      :   8               ;    /* 9:2 */
        unsigned int cpu_ai_pi_ovsf                                   :   10              ;    /* 19:10 */
        unsigned int pi_rl_no                                         :   4               ;    /* 23:20 */
        unsigned int pi_scram_num                                     :   6               ;    /* 29:24 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_PICH_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int pi_user_no                                       :   10              ;    /* 9:0 */
        unsigned int pi_grp_no                                        :   11              ;    /* 20:10 */
        unsigned int reserved_0                                       :   11              ;    /* 31:21 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_PICH_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_PICH_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_RAKE_PICH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_PICH_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_PICH_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_RAKE_PICH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_PICH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int pccp_div_mode                                    :   2               ;    /* 1:0 */
        unsigned int pccp_scram_num                                   :   6               ;    /* 7:2 */
        unsigned int pccp_first_flag                                  :   1               ;    /* 8 */
        unsigned int pccp_not_frm_end                                 :   1               ;    /* 9 */
        unsigned int reserved_0                                       :   22              ;    /* 31:10 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_PCCPCH_IN_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_PCCPCH_IN_UMTS_SUB0                                 om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_RAKE_PCCPCH_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_PCCPCH_IN_UMTS_SUB0                                 om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_RAKE_PCCPCH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int sch_ovsf                                         :   10              ;    /* 9:0 */
        unsigned int sch_div_mode                                     :   2               ;    /* 11:10 */
        unsigned int sch_rl_no                                        :   4               ;    /* 15:12 */
        unsigned int sch_scram_num                                    :   6               ;    /* 21:16 */
        unsigned int reserved_0                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_SCH_IN_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_SCH_IN_UMTS_SUB0                                    om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_RAKE_SCH_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_SCH_IN_UMTS_SUB0                                    om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_RAKE_SCH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int pri_ovsf_sccp                                    :   8               ;    /* 7:0 */
        unsigned int fg_div_mode_sccp                                 :   16              ;    /* 23:8 */
        unsigned int cm_mode_sccp                                     :   2               ;    /* 25:24 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_SCCPCH_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int slotformat_index_sccp                            :   7               ;    /* 6:0 */
        unsigned int sf_sccp                                          :   9               ;    /* 15:7 */
        unsigned int pri_scram_num_sccp                               :   15              ;    /* 30:16 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_SCCPCH_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_SCCPCH_IN_UMTS_SUB0                                 om_data0;
    UMTS_SID_RAKE_SCCPCH_IN_UMTS_SUB1                                 om_data1;
} UMTS_SID_RAKE_SCCPCH_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_SCCPCH_IN_UMTS_SUB0                                 om_data0;
    UMTS_SID_RAKE_SCCPCH_IN_UMTS_SUB1                                 om_data1;
} UMTS_SID_RAKE_SCCPCH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int pri_ovsf_dp                                      :   8               ;    /* 7:0 */
        unsigned int fg_div_mode_dp                                   :   16              ;    /* 23:8 */
        unsigned int cm_mode_dp                                       :   2               ;    /* 25:24 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_DPCH_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int slotformat_index_dp                              :   7               ;    /* 6:0 */
        unsigned int sf_dp                                            :   9               ;    /* 15:7 */
        unsigned int pri_scram_num_dp                                 :   15              ;    /* 30:16 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_DPCH_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_DPCH_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_RAKE_DPCH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_DPCH_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_DPCH_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_RAKE_DPCH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_DPCH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int pri_ovsf_fdp                                     :   8               ;    /* 7:0 */
        unsigned int fg_div_mode_fdp                                  :   16              ;    /* 23:8 */
        unsigned int cm_mode_fdp                                      :   2               ;    /* 25:24 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_FDPCH_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int pri_scram_num_fdp                                :   15              ;    /* 14:0 */
        unsigned int reserved_0                                       :   17              ;    /* 31:15 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_FDPCH_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_FDPCH_IN_UMTS_SUB0                                  om_data0;
    UMTS_SID_RAKE_FDPCH_IN_UMTS_SUB1                                  om_data1;
} UMTS_SID_RAKE_FDPCH_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_FDPCH_IN_UMTS_SUB0                                  om_data0;
    UMTS_SID_RAKE_FDPCH_IN_UMTS_SUB1                                  om_data1;
} UMTS_SID_RAKE_FDPCH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int eagch_comb_mode                                  :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   31              ;    /* 31:1 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_AGCH_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reserved_0;
    UMTS_SID_RAKE_AGCH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_AGCH_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    UMTS_SID_RAKE_AGCH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_AGCH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int rg_rl5_comb_rl                                   :   6               ;    /* 5:0 */
        unsigned int reserved_0                                       :   26              ;    /* 31:6 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_RGCH_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int rg_rl0_comb_rl                                   :   6               ;    /* 5:0 */
        unsigned int rg_rl1_comb_rl                                   :   6               ;    /* 11:6 */
        unsigned int rg_rl2_comb_rl                                   :   6               ;    /* 17:12 */
        unsigned int rg_rl3_comb_rl                                   :   6               ;    /* 23:18 */
        unsigned int rg_rl4_comb_rl                                   :   6               ;    /* 29:24 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_RGCH_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_RGCH_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_RAKE_RGCH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_RGCH_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_RGCH_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_RAKE_RGCH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_RGCH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int hi_rls5_comb_rl                                  :   6               ;    /* 5:0 */
        unsigned int reserved_0                                       :   26              ;    /* 31:6 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_HICH_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int hi_rls0_comb_rl                                  :   6               ;    /* 5:0 */
        unsigned int hi_rls1_comb_rl                                  :   6               ;    /* 11:6 */
        unsigned int hi_rls2_comb_rl                                  :   6               ;    /* 17:12 */
        unsigned int hi_rls3_comb_rl                                  :   6               ;    /* 23:18 */
        unsigned int hi_rls4_comb_rl                                  :   6               ;    /* 29:24 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_HICH_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_HICH_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_RAKE_HICH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_HICH_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_HICH_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_RAKE_HICH_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_RAKE_HICH_IN_BBP_MC;

typedef union {
    struct {
        unsigned int freqoff_disc_mrc_q                               :   30              ;    /* 29:0 */
        unsigned int afc_judge_valid                                  :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_AFC_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int freqoff_disc_mrc_i                               :   30              ;    /* 29:0 */
        unsigned int afc_coarse_lock_state                            :   1               ;    /* 30 */
        unsigned int freqoff_disc_valid                               :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_AFC_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_AFC_IN_UMTS_SUB0                                    om_data0;
    UMTS_SID_RAKE_AFC_IN_UMTS_SUB1                                    om_data1;
} UMTS_SID_RAKE_AFC_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_AFC_IN_UMTS_SUB0                                    om_data0;
    UMTS_SID_RAKE_AFC_IN_UMTS_SUB1                                    om_data1;
} UMTS_SID_RAKE_AFC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int rake_state                                       :   2               ;    /* 1:0 */
        unsigned int modem_id                                         :   1               ;    /* 2 */
        unsigned int reserved_0                                       :   29              ;    /* 31:3 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_C_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int cpu_ch_cpi_en                                    :   1               ;    /* 0 */
        unsigned int pc_en                                            :   1               ;    /* 1 */
        unsigned int cld_en                                           :   1               ;    /* 2 */
        unsigned int reserved_0                                       :   29              ;    /* 31:3 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_C_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_C_IN_UMTS_SUB0                                      om_data0;
    UMTS_SID_RAKE_C_IN_UMTS_SUB1                                      om_data1;
} UMTS_SID_RAKE_C_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_C_IN_UMTS_SUB0                                      om_data0;
    UMTS_SID_RAKE_C_IN_UMTS_SUB1                                      om_data1;
} UMTS_SID_RAKE_C_IN_BBP_MC;

typedef union {
    struct {
        unsigned int tpc_cmd                                          :   2               ;    /* 1:0 */
        unsigned int slot_num_dp                                      :   4               ;    /* 5:2 */
        unsigned int reserved_0                                       :   26              ;    /* 31:6 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_PC_TPC_OUT_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      tpc_mc_cnt;
    UMTS_SID_RAKE_PC_TPC_OUT_UMTS_SUB1                                om_data1;
} UMTS_SID_RAKE_PC_TPC_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tpc_mc_cnt;
    UMTS_SID_RAKE_PC_TPC_OUT_UMTS_SUB1                                om_data1;
} UMTS_SID_RAKE_PC_TPC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int s_time                                           :   16              ;    /* 15:0 */
        unsigned int s_addr                                           :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_AGC_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int e_time                                           :   16              ;    /* 15:0 */
        unsigned int e_addr                                           :   12              ;    /* 27:16 */
        unsigned int c                                                :   1               ;    /* 28 */
        unsigned int d                                                :   1               ;    /* 29 */
        unsigned int b                                                :   1               ;    /* 30 */
        unsigned int s                                                :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_AGC_INFO_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_AGC_INFO_UMTS_SUB0                                  om_data0;
    UMTS_SID_RAKE_AGC_INFO_UMTS_SUB1                                  om_data1;
} UMTS_SID_RAKE_AGC_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_AGC_INFO_UMTS_SUB0                                  om_data0;
    UMTS_SID_RAKE_AGC_INFO_UMTS_SUB1                                  om_data1;
} UMTS_SID_RAKE_AGC_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int pri_r0_fg0_pst_samp                              :   2               ;    /* 1:0 */
        unsigned int pri_r0_fg0_pst_chip                              :   5               ;    /* 6:2 */
        unsigned int pri_r1_fg0_pst_samp                              :   2               ;    /* 8:7 */
        unsigned int pri_r1_fg0_pst_chip                              :   5               ;    /* 13:9 */
        unsigned int pri_cpu_win_pst_slot                             :   4               ;    /* 17:14 */
        unsigned int pri_cpu_win_pst_chip                             :   12              ;    /* 29:18 */
        unsigned int cpu_dem_rx_mode                                  :   1               ;    /* 30 */
        unsigned int cpu_dem_tx_mode                                  :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int cpu_equalizer_en                                 :   1               ;    /* 0 */
        unsigned int cpu_scr_no                                       :   9               ;    /* 9:1 */
        unsigned int cpu_equalizer_clr                                :   1               ;    /* 10 */
        unsigned int cpu_dc_en                                        :   1               ;    /* 11 */
        unsigned int cpu_ic0_en                                       :   1               ;    /* 12 */
        unsigned int cpu_ic1_en                                       :   1               ;    /* 13 */
        unsigned int cpu_ic0_scr_no                                   :   9               ;    /* 22:14 */
        unsigned int cpu_ic1_scr_no                                   :   9               ;    /* 31:23 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_LMMSE_WDC_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_LMMSE_WDC_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_LMMSE_WDC_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_LMMSE_WDC_IN_UMTS_SUB0                                   om_data0;
    UMTS_SID_LMMSE_WDC_IN_UMTS_SUB1                                   om_data1;
} UMTS_SID_LMMSE_WDC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int fg_en_flag_rx0                                   :   6               ;    /* 5:0 */
        unsigned int fg_en_flag_rx1                                   :   6               ;    /* 11:6 */
        unsigned int fg_renew                                         :   1               ;    /* 12 */
        unsigned int sec_cell_ind                                     :   1               ;    /* 13 */
        unsigned int reserved_0                                       :   18              ;    /* 31:14 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_LSRC_OUT_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_LMMSE_WDC_LSRC_OUT_UMTS_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_LMMSE_WDC_LSRC_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_LMMSE_WDC_LSRC_OUT_UMTS_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_LMMSE_WDC_LSRC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int subfrm_ind_count                                 :   4               ;    /* 3:0 */
        unsigned int slot_num                                         :   4               ;    /* 7:4 */
        unsigned int max_finge_ind                                    :   2               ;    /* 9:8 */
        unsigned int sec_finger_ind                                   :   2               ;    /* 11:10 */
        unsigned int first_flag                                       :   1               ;    /* 12 */
        unsigned int tti_flag                                         :   1               ;    /* 13 */
        unsigned int sec_cell_ind                                     :   1               ;    /* 14 */
        unsigned int reserved_0                                       :   17              ;    /* 31:15 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_IOREC_OUT_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_LMMSE_WDC_IOREC_OUT_UMTS_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_LMMSE_WDC_IOREC_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_LMMSE_WDC_IOREC_OUT_UMTS_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_LMMSE_WDC_IOREC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int cpich_slot_no                                    :   4               ;    /* 3:0 */
        unsigned int cpich_symb_no                                    :   4               ;    /* 7:4 */
        unsigned int rx_mode                                          :   1               ;    /* 8 */
        unsigned int init_flag                                        :   1               ;    /* 9 */
        unsigned int sec_cell_ind                                     :   1               ;    /* 10 */
        unsigned int reserved_0                                       :   21              ;    /* 31:11 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_WPROC_OUT_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_LMMSE_WDC_WPROC_OUT_UMTS_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_LMMSE_WDC_WPROC_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_LMMSE_WDC_WPROC_OUT_UMTS_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_LMMSE_WDC_WPROC_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int time_shift_pc                                    :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_DIF_DRIVER_OUT_UMTS_SUB0;

typedef union {
    struct {
        unsigned int time_shift_sc                                    :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_DIF_DRIVER_OUT_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_LMMSE_WDC_DIF_DRIVER_OUT_UMTS_SUB0                       om_data0;
    UMTS_SID_LMMSE_WDC_DIF_DRIVER_OUT_UMTS_SUB1                       om_data1;
} UMTS_SID_LMMSE_WDC_DIF_DRIVER_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_LMMSE_WDC_DIF_DRIVER_OUT_UMTS_SUB0                       om_data0;
    UMTS_SID_LMMSE_WDC_DIF_DRIVER_OUT_UMTS_SUB1                       om_data1;
} UMTS_SID_LMMSE_WDC_DIF_DRIVER_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_EQU_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_EQU_IN_BBP_MC;

typedef union {
    struct {
        unsigned int scch_detect_ch_no                                :   8               ;    /* 7:0 */
        unsigned int scch_detect_flag                                 :   8               ;    /* 15:8 */
        unsigned int cpich_slot_cnt                                   :   8               ;    /* 23:16 */
        unsigned int cpich_sym_cnt                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_SCCH_PROC_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int scch_gap_index0                                  :   1               ;    /* 0 */
        unsigned int scch_gap_index1                                  :   1               ;    /* 1 */
        unsigned int scch_gap_index2                                  :   1               ;    /* 2 */
        unsigned int scch_gap_index3                                  :   1               ;    /* 3 */
        unsigned int scch_gap_index4                                  :   1               ;    /* 4 */
        unsigned int reserved_0                                       :   3               ;    /* 7:5 */
        unsigned int carrier_ind                                      :   1               ;    /* 8 */
        unsigned int reserved_1                                       :   23              ;    /* 31:9 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_SCCH_PROC_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_LMMSE_SCCH_PROC_IN_UMTS_SUB0                             om_data0;
    UMTS_SID_LMMSE_SCCH_PROC_IN_UMTS_SUB1                             om_data1;
} UMTS_SID_LMMSE_SCCH_PROC_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_LMMSE_SCCH_PROC_IN_UMTS_SUB0                             om_data0;
    UMTS_SID_LMMSE_SCCH_PROC_IN_UMTS_SUB1                             om_data1;
} UMTS_SID_LMMSE_SCCH_PROC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int carrier_ind                                      :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   4               ;    /* 4:1 */
        unsigned int scch_detect_flag_delay                           :   1               ;    /* 5 */
        unsigned int reserved_1                                       :   2               ;    /* 7:6 */
        unsigned int scch_detect_ms_delay                             :   8               ;    /* 15:8 */
        unsigned int scch_detect_p_delay                              :   8               ;    /* 23:16 */
        unsigned int scch_detect_o_delay                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_PDSCH_PROC_IN_UMTS_SUB0;

typedef union {
    struct {
        unsigned int pdsch_slot_mod3                                  :   8               ;    /* 7:0 */
        unsigned int pdsch_subframe_cnt                               :   8               ;    /* 15:8 */
        unsigned int pdsch_gap_index0                                 :   1               ;    /* 16 */
        unsigned int pdsch_gap_index1                                 :   1               ;    /* 17 */
        unsigned int pdsch_gap_index2                                 :   1               ;    /* 18 */
        unsigned int pdsch_gap_index3                                 :   1               ;    /* 19 */
        unsigned int pdsch_gap_index4                                 :   1               ;    /* 20 */
        unsigned int init_flag                                        :   1               ;    /* 21 */
        unsigned int reserved_0                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_PDSCH_PROC_IN_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_LMMSE_PDSCH_PROC_IN_UMTS_SUB0                            om_data0;
    UMTS_SID_LMMSE_PDSCH_PROC_IN_UMTS_SUB1                            om_data1;
} UMTS_SID_LMMSE_PDSCH_PROC_IN_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_LMMSE_PDSCH_PROC_IN_UMTS_SUB0                            om_data0;
    UMTS_SID_LMMSE_PDSCH_PROC_IN_UMTS_SUB1                            om_data1;
} UMTS_SID_LMMSE_PDSCH_PROC_IN_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      snr_thd1;
    unsigned int                                                      snr_thd2;
} UMTS_SID_LMMSE_ALG_HDM_LLR_S_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      snr_thd1;
    unsigned int                                                      snr_thd2;
} UMTS_SID_LMMSE_ALG_HDM_LLR_S_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int snr_for_cqi                                      :   31              ;    /* 30:0 */
        unsigned int cqi_init_flag                                    :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_ALG_HDM_CQI_PRE_S_OUT_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      cqi_delta_21s;
    UMTS_SID_LMMSE_ALG_HDM_CQI_PRE_S_OUT_UMTS_SUB1                    om_data1;
} UMTS_SID_LMMSE_ALG_HDM_CQI_PRE_S_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cqi_delta_21s;
    UMTS_SID_LMMSE_ALG_HDM_CQI_PRE_S_OUT_UMTS_SUB1                    om_data1;
} UMTS_SID_LMMSE_ALG_HDM_CQI_PRE_S_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int snr_out                                          :   31              ;    /* 30:0 */
        unsigned int init_flag_subframe                               :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_ALG_HDM_CQI_S_OUT_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pre_snr;
    UMTS_SID_LMMSE_ALG_HDM_CQI_S_OUT_UMTS_SUB1                        om_data1;
} UMTS_SID_LMMSE_ALG_HDM_CQI_S_OUT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pre_snr;
    UMTS_SID_LMMSE_ALG_HDM_CQI_S_OUT_UMTS_SUB1                        om_data1;
} UMTS_SID_LMMSE_ALG_HDM_CQI_S_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int cctrch_cfn                                       :   12              ;    /* 11:0 */
        unsigned int cctrch_id                                        :   6               ;    /* 17:12 */
        unsigned int min_tti_type                                     :   2               ;    /* 19:18 */
        unsigned int max_tti_type                                     :   2               ;    /* 21:20 */
        unsigned int cctrch_trch_num                                  :   4               ;    /* 25:22 */
        unsigned int blind_detect_flag                                :   1               ;    /* 26 */
        unsigned int btfd_no                                          :   1               ;    /* 27 */
        unsigned int cctrch_fst_frm_flag                              :   1               ;    /* 28 */
        unsigned int task_id                                          :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_DCH_INIT_UMTS_SUB0;

typedef union {
    struct {
        unsigned int cctrch_work_en                                   :   1               ;    /* 0 */
        unsigned int recfg_ind                                        :   1               ;    /* 1 */
        unsigned int cctrch_dec_discard_ind                           :   1               ;    /* 2 */
        unsigned int fst_frame_quit                                   :   1               ;    /* 3 */
        unsigned int phy2dec_cctrch_en                                :   1               ;    /* 4 */
        unsigned int cctrch_llr_num                                   :   14              ;    /* 18:5 */
        unsigned int tfci_llr_num                                     :   8               ;    /* 26:19 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_DCH_INIT_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_DEC_DCH_INIT_UMTS_SUB0                                   om_data0;
    UMTS_SID_DEC_DCH_INIT_UMTS_SUB1                                   om_data1;
} UMTS_SID_DEC_DCH_INIT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_DEC_DCH_INIT_UMTS_SUB0                                   om_data0;
    UMTS_SID_DEC_DCH_INIT_UMTS_SUB1                                   om_data1;
} UMTS_SID_DEC_DCH_INIT_BBP_MC;

typedef union {
    struct {
        unsigned int pccpch_sync_flag                                 :   1               ;    /* 0 */
        unsigned int pccpch_fst_frm_flag                              :   1               ;    /* 1 */
        unsigned int reserved_0                                       :   30              ;    /* 31:2 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_PCCPCH_INIT_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_DEC_PCCPCH_INIT_UMTS_SUB0                                om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_DEC_PCCPCH_INIT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_DEC_PCCPCH_INIT_UMTS_SUB0                                om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_DEC_PCCPCH_INIT_BBP_MC;

typedef union {
    struct {
        unsigned int eagch_cfn                                        :   8               ;    /* 7:0 */
        unsigned int reserved_0                                       :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_EAGCH_INIT_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_DEC_EAGCH_INIT_UMTS_SUB0                                 om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_DEC_EAGCH_INIT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_DEC_EAGCH_INIT_UMTS_SUB0                                 om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_DEC_EAGCH_INIT_BBP_MC;

typedef union {
    struct {
        unsigned int scch_fst_frm_flag                                :   1               ;    /* 0 */
        unsigned int scch_carrier_ind                                 :   1               ;    /* 1 */
        unsigned int scch_modem_id                                    :   1               ;    /* 2 */
        unsigned int scch_dc_ind                                      :   1               ;    /* 3 */
        unsigned int scch_detect_en                                   :   1               ;    /* 4 */
        unsigned int scch_symbol_cnt                                  :   3               ;    /* 7:5 */
        unsigned int scch_tti_no                                      :   3               ;    /* 10:8 */
        unsigned int scch_ch_num                                      :   3               ;    /* 13:11 */
        unsigned int msg_new_flag                                     :   1               ;    /* 14 */
        unsigned int pp_flag                                          :   1               ;    /* 15 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_SCCH_INIT_UMTS_SUB0;

typedef union {
    struct {
        unsigned int hsscch_less_active                               :   1               ;    /* 0 */
        unsigned int dc_hsdpa_status                                  :   1               ;    /* 1 */
        unsigned int dtx_drx_enable                                   :   1               ;    /* 2 */
        unsigned int hsscch_less_status                               :   1               ;    /* 3 */
        unsigned int hs_drx_ind                                       :   1               ;    /* 4 */
        unsigned int hsd_64qam_flag                                   :   1               ;    /* 5 */
        unsigned int hsdpa_estb_ind_0_scch                            :   1               ;    /* 6 */
        unsigned int hsdpa_estb_ind_1_scch                            :   1               ;    /* 7 */
        unsigned int reserved_0                                       :   8               ;    /* 15:8 */
        unsigned int hspda_ue_id                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_SCCH_INIT_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_DEC_SCCH_INIT_UMTS_SUB0                                  om_data0;
    UMTS_SID_DEC_SCCH_INIT_UMTS_SUB1                                  om_data1;
} UMTS_SID_DEC_SCCH_INIT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_DEC_SCCH_INIT_UMTS_SUB0                                  om_data0;
    UMTS_SID_DEC_SCCH_INIT_UMTS_SUB1                                  om_data1;
} UMTS_SID_DEC_SCCH_INIT_BBP_MC;

typedef union {
    struct {
        unsigned int task_no                                          :   2               ;    /* 1:0 */
        unsigned int fst_frm_flag_pc                                  :   1               ;    /* 2 */
        unsigned int fst_frm_flag_sc                                  :   1               ;    /* 3 */
        unsigned int hsd_ir_buffer_reset_pc                           :   1               ;    /* 4 */
        unsigned int hsd_ir_buffer_reset_sc                           :   1               ;    /* 5 */
        unsigned int pdsch_modem_id                                   :   1               ;    /* 6 */
        unsigned int pdsch_work                                       :   1               ;    /* 7 */
        unsigned int order_null_call                                  :   1               ;    /* 8 */
        unsigned int pdsch_tti_no                                     :   3               ;    /* 11:9 */
        unsigned int subframe_head                                    :   1               ;    /* 12 */
        unsigned int pdsch_dc_ind                                     :   1               ;    /* 13 */
        unsigned int pre_task_no                                      :   4               ;    /* 17:14 */
        unsigned int valid_cc_num                                     :   2               ;    /* 19:18 */
        unsigned int hsd_para_ms                                      :   2               ;    /* 21:20 */
        unsigned int hsd_para_p                                       :   4               ;    /* 25:22 */
        unsigned int scch_less_status                                 :   1               ;    /* 26 */
        unsigned int hsd_hap_num                                      :   4               ;    /* 30:27 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_PDSCH_INIT_UMTS_SUB0;

typedef union {
    struct {
        unsigned int pc_done                                          :   1               ;    /* 0 */
        unsigned int dc_excute_2nd_cc                                 :   1               ;    /* 1 */
        unsigned int pdsch_carrier_ind                                :   1               ;    /* 2 */
        unsigned int pdsch_pp_flag                                    :   1               ;    /* 3 */
        unsigned int scch_type_para_cal                               :   4               ;    /* 7:4 */
        unsigned int pre_task_done                                    :   1               ;    /* 8 */
        unsigned int raw_cnt_mod_13                                   :   4               ;    /* 12:9 */
        unsigned int drawer_cnt_mod_14                                :   4               ;    /* 16:13 */
        unsigned int ack_wen                                          :   1               ;    /* 17 */
        unsigned int para_unexpected                                  :   1               ;    /* 18 */
        unsigned int d0less_wr_ddr                                    :   1               ;    /* 19 */
        unsigned int hsd_para_new                                     :   1               ;    /* 20 */
        unsigned int cb_num                                           :   4               ;    /* 24:21 */
        unsigned int last_retrans_no                                  :   2               ;    /* 26:25 */
        unsigned int return_scch_type                                 :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_PDSCH_INIT_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_DEC_PDSCH_INIT_UMTS_SUB0                                 om_data0;
    UMTS_SID_DEC_PDSCH_INIT_UMTS_SUB1                                 om_data1;
} UMTS_SID_DEC_PDSCH_INIT_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_DEC_PDSCH_INIT_UMTS_SUB0                                 om_data0;
    UMTS_SID_DEC_PDSCH_INIT_UMTS_SUB1                                 om_data1;
} UMTS_SID_DEC_PDSCH_INIT_BBP_MC;

typedef union {
    struct {
        unsigned int rach_acc_sfn                                     :   3               ;    /* 2:0 */
        unsigned int rach_acc_slot                                    :   4               ;    /* 6:3 */
        unsigned int rach_acc_sig                                     :   4               ;    /* 10:7 */
        unsigned int rach_pream_no                                    :   7               ;    /* 17:11 */
        unsigned int rach_pwr                                         :   11              ;    /* 28:18 */
        unsigned int pream_flag                                       :   1               ;    /* 29 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int rach_mc_cnt_start                                :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB1;

typedef union {
    struct {
        unsigned int rach_mc_cnt_end                                  :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int rach_gain_factor                                 :   12              ;    /* 11:0 */
        unsigned int reserved_0                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB3;

typedef union {
    struct {
        unsigned int rand_slot                                        :   4               ;    /* 3:0 */
        unsigned int rand_sig                                         :   4               ;    /* 7:4 */
        unsigned int reserved_0                                       :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB4;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB0                                om_data0;
    UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB1                                om_data1;
    UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB2                                om_data2;
    UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB3                                om_data3;
    UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB4                                om_data4;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
    unsigned int                                                      reserved_2;
} UMTS_SID_XCTRL_RACH_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB0                                om_data0;
    UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB1                                om_data1;
    UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB2                                om_data2;
    UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB3                                om_data3;
    UMTS_SID_XCTRL_RACH_INFO_UMTS_SUB4                                om_data4;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
    unsigned int                                                      reserved_2;
} UMTS_SID_XCTRL_RACH_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int mc_cnt_info                                      :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int cfn_info                                         :   8               ;    /* 7:0 */
        unsigned int sys_slot_info                                    :   4               ;    /* 11:8 */
        unsigned int hsscch_slot_info                                 :   4               ;    /* 15:12 */
        unsigned int hspdsch_slot_info                                :   4               ;    /* 19:16 */
        unsigned int hsdpcch_slot_info                                :   4               ;    /* 23:20 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB1;

typedef union {
    struct {
        unsigned int reserved_0                                       :   3               ;    /* 2:0 */
        unsigned int dpch_slot_gap_index                              :   3               ;    /* 5:3 */
        unsigned int hsscch_subfrm_gap_ind                            :   5               ;    /* 10:6 */
        unsigned int hspdsch_subfrm_gap_ind                           :   5               ;    /* 15:11 */
        unsigned int hsdpcch_harq_gap_ind                             :   1               ;    /* 16 */
        unsigned int hsdpcch_cqi_gap_ind                              :   1               ;    /* 17 */
        unsigned int reserved_1                                       :   14              ;    /* 31:18 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int dpcch_tx_en                                      :   1               ;    /* 0 */
        unsigned int dpdch_tx_en                                      :   1               ;    /* 1 */
        unsigned int dpdch_gain                                       :   8               ;    /* 9:2 */
        unsigned int edpcch_tx_en                                     :   1               ;    /* 10 */
        unsigned int edpcch_gain                                      :   8               ;    /* 18:11 */
        unsigned int edpdch_tx_en                                     :   2               ;    /* 20:19 */
        unsigned int edpdch_gain                                      :   9               ;    /* 29:21 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB3;

typedef union {
    struct {
        unsigned int hsdpcch_harq_tx_en                               :   1               ;    /* 0 */
        unsigned int hsdpcch_harq_state                               :   4               ;    /* 4:1 */
        unsigned int hsdpcch_harq                                     :   10              ;    /* 14:5 */
        unsigned int hsdpcch_n_harq                                   :   3               ;    /* 17:15 */
        unsigned int hsdpcch_gain                                     :   6               ;    /* 23:18 */
        unsigned int hsdpcch_cqi_tx_en                                :   2               ;    /* 25:24 */
        unsigned int hsdpcch_n_cqi                                    :   3               ;    /* 28:26 */
        unsigned int reserved_0                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB4;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB0                            om_data0;
    UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB1                            om_data1;
    UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB2                            om_data2;
    UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB3                            om_data3;
    UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB4                            om_data4;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
    unsigned int                                                      reserved_2;
} UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB0                            om_data0;
    UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB1                            om_data1;
    UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB2                            om_data2;
    UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB3                            om_data3;
    UMTS_SID_XCTRL_DCH_CTRL_INFO_UMTS_SUB4                            om_data4;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
    unsigned int                                                      reserved_2;
} UMTS_SID_XCTRL_DCH_CTRL_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int pow_1st_slot                                     :   1               ;    /* 0 */
        unsigned int pca                                              :   1               ;    /* 1 */
        unsigned int pow_dpcch_last                                   :   11              ;    /* 12:2 */
        unsigned int delta_pilot                                      :   7               ;    /* 19:13 */
        unsigned int itp_mode                                         :   1               ;    /* 20 */
        unsigned int rpp_mode                                         :   1               ;    /* 21 */
        unsigned int reserved_0                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int power_curr_slot0                                 :   11              ;    /* 10:0 */
        unsigned int power_curr_slot_low0                             :   11              ;    /* 21:11 */
        unsigned int edpdch_gain0                                     :   9               ;    /* 30:22 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB1;

typedef union {
    struct {
        unsigned int power_curr_slot1                                 :   11              ;    /* 10:0 */
        unsigned int power_curr_slot_low1                             :   11              ;    /* 21:11 */
        unsigned int edpdch_gain1                                     :   9               ;    /* 30:22 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int power_curr_slot2                                 :   11              ;    /* 10:0 */
        unsigned int power_curr_slot_low2                             :   11              ;    /* 21:11 */
        unsigned int edpdch_gain2                                     :   9               ;    /* 30:22 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB3;

typedef union {
    struct {
        unsigned int mpr_index0                                       :   6               ;    /* 5:0 */
        unsigned int mpr_index1                                       :   6               ;    /* 11:6 */
        unsigned int mpr_index2                                       :   6               ;    /* 17:12 */
        unsigned int reserved_0                                       :   14              ;    /* 31:18 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB4;

typedef union {
    struct {
        unsigned int scale_0                                          :   1               ;    /* 0 */
        unsigned int scale_1                                          :   1               ;    /* 1 */
        unsigned int scale_2                                          :   1               ;    /* 2 */
        unsigned int ksc_n                                            :   1               ;    /* 3 */
        unsigned int delta_last                                       :   12              ;    /* 15:4 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB5;

typedef union {
    struct {
        unsigned int pow_offset0                                      :   11              ;    /* 10:0 */
        unsigned int pow_offset1                                      :   11              ;    /* 21:11 */
        unsigned int reserved_0                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB6;

typedef union {
    struct {
        unsigned int pow_offset2                                      :   11              ;    /* 10:0 */
        unsigned int reserved_0                                       :   21              ;    /* 31:11 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB7;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB0                             om_data0;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB1                             om_data1;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB2                             om_data2;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB3                             om_data3;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB4                             om_data4;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB5                             om_data5;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB6                             om_data6;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB7                             om_data7;
} UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB0                             om_data0;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB1                             om_data1;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB2                             om_data2;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB3                             om_data3;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB4                             om_data4;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB5                             om_data5;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB6                             om_data6;
    UMTS_SID_XCTRL_DCH_PWR_INFO_UMTS_SUB7                             om_data7;
} UMTS_SID_XCTRL_DCH_PWR_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x0_pre0_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x0_pre0_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x0_pre1_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x0_pre1_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x0_pre2_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x0_pre2_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x0_pre3_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x0_pre3_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB1;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x0_pre4_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x0_pre4_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x0_pre5_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x0_pre5_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x0_pre6_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x0_pre6_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x0_pre7_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x0_pre7_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB3;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x0_post0_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x0_post0_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x0_post1_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x0_post1_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB4;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x0_post2_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x0_post2_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x0_post3_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x0_post3_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB5;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x0_post4_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x0_post4_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x0_post5_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x0_post5_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB6;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x0_post6_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x0_post6_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x0_post7_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x0_post7_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB7;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x0_pre0_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x0_pre0_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x0_pre1_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x0_pre1_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB8;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x0_pre2_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x0_pre2_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x0_pre3_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x0_pre3_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB9;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x0_pre4_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x0_pre4_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x0_pre5_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x0_pre5_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB10;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x0_pre6_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x0_pre6_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x0_pre7_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x0_pre7_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB11;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x0_post0_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x0_post0_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x0_post1_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x0_post1_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB12;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x0_post2_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x0_post2_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x0_post3_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x0_post3_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB13;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x0_post4_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x0_post4_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x0_post5_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x0_post5_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB14;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x0_post6_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x0_post6_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x0_post7_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x0_post7_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB15;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x0_pre0_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x0_pre0_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x0_pre1_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x0_pre1_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB16;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x0_pre2_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x0_pre2_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x0_pre3_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x0_pre3_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB17;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x0_pre4_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x0_pre4_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x0_pre5_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x0_pre5_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB18;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x0_pre6_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x0_pre6_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x0_pre7_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x0_pre7_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB19;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x0_post0_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x0_post0_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x0_post1_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x0_post1_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB20;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x0_post2_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x0_post2_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x0_post3_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x0_post3_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB21;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x0_post4_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x0_post4_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x0_post5_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x0_post5_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB22;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x0_post6_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x0_post6_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x0_post7_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x0_post7_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB23;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x0_pre0_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x0_pre0_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x0_pre1_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x0_pre1_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB24;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x0_pre2_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x0_pre2_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x0_pre3_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x0_pre3_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB25;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x0_pre4_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x0_pre4_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x0_pre5_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x0_pre5_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB26;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x0_pre6_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x0_pre6_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x0_pre7_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x0_pre7_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB27;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x0_post0_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x0_post0_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x0_post1_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x0_post1_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB28;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x0_post2_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x0_post2_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x0_post3_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x0_post3_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB29;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x0_post4_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x0_post4_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x0_post5_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x0_post5_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB30;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x0_post6_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x0_post6_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x0_post7_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x0_post7_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB31;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x2_pre0_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x2_pre0_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x2_pre1_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x2_pre1_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB32;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x2_pre2_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x2_pre2_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x2_pre3_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x2_pre3_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB33;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x2_pre4_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x2_pre4_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x2_pre5_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x2_pre5_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB34;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x2_pre6_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x2_pre6_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x2_pre7_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x2_pre7_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB35;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x2_post0_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x2_post0_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x2_post1_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x2_post1_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB36;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x2_post2_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x2_post2_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x2_post3_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x2_post3_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB37;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x2_post4_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x2_post4_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x2_post5_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x2_post5_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB38;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym0_x2_post6_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym0_x2_post6_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym0_x2_post7_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym0_x2_post7_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB39;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x2_pre0_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x2_pre0_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x2_pre1_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x2_pre1_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB40;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x2_pre2_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x2_pre2_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x2_pre3_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x2_pre3_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB41;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x2_pre4_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x2_pre4_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x2_pre5_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x2_pre5_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB42;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x2_pre6_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x2_pre6_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x2_pre7_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x2_pre7_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB43;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x2_post0_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x2_post0_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x2_post1_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x2_post1_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB44;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x2_post2_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x2_post2_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x2_post3_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x2_post3_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB45;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x2_post4_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x2_post4_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x2_post5_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x2_post5_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB46;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym1_x2_post6_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym1_x2_post6_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym1_x2_post7_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym1_x2_post7_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB47;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x2_pre0_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x2_pre0_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x2_pre1_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x2_pre1_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB48;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x2_pre2_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x2_pre2_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x2_pre3_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x2_pre3_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB49;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x2_pre4_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x2_pre4_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x2_pre5_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x2_pre5_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB50;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x2_pre6_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x2_pre6_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x2_pre7_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x2_pre7_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB51;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x2_post0_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x2_post0_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x2_post1_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x2_post1_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB52;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x2_post2_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x2_post2_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x2_post3_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x2_post3_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB53;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x2_post4_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x2_post4_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x2_post5_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x2_post5_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB54;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym2_x2_post6_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym2_x2_post6_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym2_x2_post7_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym2_x2_post7_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB55;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x2_pre0_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x2_pre0_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x2_pre1_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x2_pre1_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB56;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x2_pre2_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x2_pre2_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x2_pre3_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x2_pre3_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB57;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x2_pre4_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x2_pre4_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x2_pre5_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x2_pre5_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB58;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x2_pre6_re                    :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x2_pre6_im                    :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x2_pre7_re                    :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x2_pre7_im                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB59;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x2_post0_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x2_post0_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x2_post1_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x2_post1_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB60;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x2_post2_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x2_post2_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x2_post3_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x2_post3_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB61;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x2_post4_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x2_post4_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x2_post5_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x2_post5_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB62;

typedef union {
    struct {
        unsigned int umts_cs_stepa_sym3_x2_post6_re                   :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_sym3_x2_post6_im                   :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_sym3_x2_post7_re                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sym3_x2_post7_im                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB63;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB0                     om_data0;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB1                     om_data1;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB2                     om_data2;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB3                     om_data3;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB4                     om_data4;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB5                     om_data5;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB6                     om_data6;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB7                     om_data7;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB8                     om_data8;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB9                     om_data9;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB10                    om_data10;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB11                    om_data11;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB12                    om_data12;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB13                    om_data13;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB14                    om_data14;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB15                    om_data15;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB16                    om_data16;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB17                    om_data17;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB18                    om_data18;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB19                    om_data19;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB20                    om_data20;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB21                    om_data21;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB22                    om_data22;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB23                    om_data23;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB24                    om_data24;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB25                    om_data25;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB26                    om_data26;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB27                    om_data27;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB28                    om_data28;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB29                    om_data29;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB30                    om_data30;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB31                    om_data31;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB32                    om_data32;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB33                    om_data33;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB34                    om_data34;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB35                    om_data35;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB36                    om_data36;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB37                    om_data37;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB38                    om_data38;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB39                    om_data39;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB40                    om_data40;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB41                    om_data41;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB42                    om_data42;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB43                    om_data43;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB44                    om_data44;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB45                    om_data45;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB46                    om_data46;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB47                    om_data47;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB48                    om_data48;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB49                    om_data49;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB50                    om_data50;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB51                    om_data51;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB52                    om_data52;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB53                    om_data53;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB54                    om_data54;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB55                    om_data55;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB56                    om_data56;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB57                    om_data57;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB58                    om_data58;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB59                    om_data59;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB60                    om_data60;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB61                    om_data61;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB62                    om_data62;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB63                    om_data63;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB0                     om_data0;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB1                     om_data1;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB2                     om_data2;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB3                     om_data3;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB4                     om_data4;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB5                     om_data5;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB6                     om_data6;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB7                     om_data7;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB8                     om_data8;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB9                     om_data9;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB10                    om_data10;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB11                    om_data11;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB12                    om_data12;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB13                    om_data13;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB14                    om_data14;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB15                    om_data15;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB16                    om_data16;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB17                    om_data17;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB18                    om_data18;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB19                    om_data19;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB20                    om_data20;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB21                    om_data21;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB22                    om_data22;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB23                    om_data23;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB24                    om_data24;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB25                    om_data25;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB26                    om_data26;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB27                    om_data27;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB28                    om_data28;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB29                    om_data29;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB30                    om_data30;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB31                    om_data31;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB32                    om_data32;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB33                    om_data33;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB34                    om_data34;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB35                    om_data35;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB36                    om_data36;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB37                    om_data37;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB38                    om_data38;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB39                    om_data39;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB40                    om_data40;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB41                    om_data41;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB42                    om_data42;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB43                    om_data43;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB44                    om_data44;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB45                    om_data45;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB46                    om_data46;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB47                    om_data47;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB48                    om_data48;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB49                    om_data49;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB50                    om_data50;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB51                    om_data51;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB52                    om_data52;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB53                    om_data53;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB54                    om_data54;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB55                    om_data55;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB56                    om_data56;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB57                    om_data57;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB58                    om_data58;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB59                    om_data59;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB60                    om_data60;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB61                    om_data61;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB62                    om_data62;
    UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_UMTS_SUB63                    om_data63;
} UMTS_SID_CS_STEPA_SYM0TO3_DATA_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int umts_cs_stepa_msg_renew                          :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_uen_renew                          :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_int_flag                           :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_init_flag                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int umts_cs_stepa_cfg_rsv2_0                         :   8               ;    /* 7:0 */
        unsigned int umts_cs_stepa_en                                 :   8               ;    /* 15:8 */
        unsigned int umts_cs_stepa_intra_inter_flag                   :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_sort_mode                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB1;

typedef union {
    struct {
        unsigned int umts_cs_stepa_threshold                          :   16              ;    /* 15:0 */
        unsigned int umts_cs_stepa_ncorre_len                         :   8               ;    /* 23:16 */
        unsigned int umts_cs_stepa_cfg_rsv0_0                         :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int umts_agc_ctrl_r0_s_time                          :   16              ;    /* 15:0 */
        unsigned int umts_agc_ctrl_r0_s_addr                          :   13              ;    /* 28:16 */
        unsigned int umts_agc_ctrl_r0_rsv0_0                          :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB3;

typedef union {
    struct {
        unsigned int umts_agc_ctrl_r0_e_time                          :   16              ;    /* 15:0 */
        unsigned int umts_agc_ctrl_r0_e_addr                          :   13              ;    /* 28:16 */
        unsigned int umts_agc_ctrl_r0_d                               :   1               ;    /* 29 */
        unsigned int umts_agc_ctrl_r0_b                               :   1               ;    /* 30 */
        unsigned int umts_agc_ctrl_r0_s                               :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB4;

typedef union {
    struct {
        unsigned int umts_stepa_task_total_num                        :   16              ;    /* 15:0 */
        unsigned int umts_stepa_task_continue_num                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB7;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB0                             om_data0;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB1                             om_data1;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB2                             om_data2;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB3                             om_data3;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB4                             om_data4;
    unsigned int                                                      umts_stepa_live_buffer_addr_last;
    unsigned int                                                      umts_stepa_live_buffer_current_addr;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB7                             om_data7;
    unsigned int                                                      umts_stepa_ncorre_addr_0to255;
    unsigned int                                                      umts_stepa_ncorre_addr_256to511;
    unsigned int                                                      umts_stepa_ncorre_addr_512to767;
    unsigned int                                                      reserved_0;
} UMTS_SID_CS_STEPA_CTRL_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB0                             om_data0;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB1                             om_data1;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB2                             om_data2;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB3                             om_data3;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB4                             om_data4;
    unsigned int                                                      umts_stepa_live_buffer_addr_last;
    unsigned int                                                      umts_stepa_live_buffer_current_addr;
    UMTS_SID_CS_STEPA_CTRL_INFO_UMTS_SUB7                             om_data7;
    unsigned int                                                      umts_stepa_ncorre_addr_0to255;
    unsigned int                                                      umts_stepa_ncorre_addr_256to511;
    unsigned int                                                      umts_stepa_ncorre_addr_512to767;
    unsigned int                                                      reserved_0;
} UMTS_SID_CS_STEPA_CTRL_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      umts_stepb_ncorre_data0;
    unsigned int                                                      umts_stepb_ncorre_data1;
    unsigned int                                                      umts_stepb_ncorre_data2;
    unsigned int                                                      umts_stepb_ncorre_data3;
    unsigned int                                                      umts_stepb_ncorre_data4;
    unsigned int                                                      umts_stepb_ncorre_data5;
    unsigned int                                                      umts_stepb_ncorre_data6;
    unsigned int                                                      umts_stepb_ncorre_data7;
    unsigned int                                                      umts_stepb_ncorre_data8;
    unsigned int                                                      umts_stepb_ncorre_data9;
    unsigned int                                                      umts_stepb_ncorre_data10;
    unsigned int                                                      umts_stepb_ncorre_data11;
    unsigned int                                                      umts_stepb_ncorre_data12;
    unsigned int                                                      umts_stepb_ncorre_data13;
    unsigned int                                                      umts_stepb_ncorre_data14;
    unsigned int                                                      reserved_0;
} UMTS_SID_CS_STEPB_NCORRE_DATA_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      umts_stepb_ncorre_data0;
    unsigned int                                                      umts_stepb_ncorre_data1;
    unsigned int                                                      umts_stepb_ncorre_data2;
    unsigned int                                                      umts_stepb_ncorre_data3;
    unsigned int                                                      umts_stepb_ncorre_data4;
    unsigned int                                                      umts_stepb_ncorre_data5;
    unsigned int                                                      umts_stepb_ncorre_data6;
    unsigned int                                                      umts_stepb_ncorre_data7;
    unsigned int                                                      umts_stepb_ncorre_data8;
    unsigned int                                                      umts_stepb_ncorre_data9;
    unsigned int                                                      umts_stepb_ncorre_data10;
    unsigned int                                                      umts_stepb_ncorre_data11;
    unsigned int                                                      umts_stepb_ncorre_data12;
    unsigned int                                                      umts_stepb_ncorre_data13;
    unsigned int                                                      umts_stepb_ncorre_data14;
    unsigned int                                                      reserved_0;
} UMTS_SID_CS_STEPB_NCORRE_DATA_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int mps_main_stime                                   :   16              ;    /* 15:0 */
        unsigned int mps_main_saddr                                   :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB0;

typedef union {
    struct {
        unsigned int mps_main_etime                                   :   16              ;    /* 15:0 */
        unsigned int mps_main_eaddr                                   :   12              ;    /* 27:16 */
        unsigned int mps_main_c                                       :   1               ;    /* 28 */
        unsigned int mps_main_d                                       :   1               ;    /* 29 */
        unsigned int mps_main_b                                       :   1               ;    /* 30 */
        unsigned int mps_main_s                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB1;

typedef union {
    struct {
        unsigned int mps_div_stime                                    :   16              ;    /* 15:0 */
        unsigned int mps_div_saddr                                    :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB2;

typedef union {
    struct {
        unsigned int mps_div_etime                                    :   16              ;    /* 15:0 */
        unsigned int mps_div_eaddr                                    :   12              ;    /* 27:16 */
        unsigned int mps_div_c                                        :   1               ;    /* 28 */
        unsigned int reserved_0                                       :   1               ;    /* 29 */
        unsigned int mps_div_b                                        :   1               ;    /* 30 */
        unsigned int mps_div_s                                        :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB3;

typedef union {
    struct {
        unsigned int mps_main_dagc                                    :   16              ;    /* 15:0 */
        unsigned int mps_main_aadc                                    :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB4;

typedef union {
    struct {
        unsigned int mps_main_drssi                                   :   11              ;    /* 10:0 */
        unsigned int reserved_0                                       :   5               ;    /* 15:11 */
        unsigned int mps_main_rssi                                    :   11              ;    /* 26:16 */
        unsigned int reserved_1                                       :   3               ;    /* 29:27 */
        unsigned int mps_main_p                                       :   1               ;    /* 30 */
        unsigned int mps_main_i                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB5;

typedef union {
    struct {
        unsigned int mps_div_dagc                                     :   16              ;    /* 15:0 */
        unsigned int mps_div_aadc                                     :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB6;

typedef union {
    struct {
        unsigned int mps_div_drssi                                    :   11              ;    /* 10:0 */
        unsigned int reserved_0                                       :   5               ;    /* 15:11 */
        unsigned int mps_div_rssi                                     :   11              ;    /* 26:16 */
        unsigned int reserved_1                                       :   3               ;    /* 29:27 */
        unsigned int mps_div_p                                        :   1               ;    /* 30 */
        unsigned int mps_div_i                                        :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB7;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB0                       om_data0;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB1                       om_data1;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB2                       om_data2;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB3                       om_data3;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB4                       om_data4;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB5                       om_data5;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB6                       om_data6;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB7                       om_data7;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB0                       om_data0;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB1                       om_data1;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB2                       om_data2;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB3                       om_data3;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB4                       om_data4;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB5                       om_data5;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB6                       om_data6;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_UMTS_SUB7                       om_data7;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC0_BBP_MC;

typedef union {
    struct {
        unsigned int mps_main_stime_cc1                               :   16              ;    /* 15:0 */
        unsigned int mps_main_saddr_cc1                               :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB0;

typedef union {
    struct {
        unsigned int mps_main_etime_cc1                               :   16              ;    /* 15:0 */
        unsigned int mps_main_eaddr_cc1                               :   12              ;    /* 27:16 */
        unsigned int mps_main_c_cc1                                   :   1               ;    /* 28 */
        unsigned int mps_main_d_cc1                                   :   1               ;    /* 29 */
        unsigned int mps_main_b_cc1                                   :   1               ;    /* 30 */
        unsigned int mps_main_s_cc1                                   :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB1;

typedef union {
    struct {
        unsigned int mps_div_stime_cc1                                :   16              ;    /* 15:0 */
        unsigned int mps_div_saddr_cc1                                :   13              ;    /* 28:16 */
        unsigned int reserved_0                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB2;

typedef union {
    struct {
        unsigned int mps_div_etime_cc1                                :   16              ;    /* 15:0 */
        unsigned int mps_div_eaddr_cc1                                :   12              ;    /* 27:16 */
        unsigned int mps_div_c_cc1                                    :   1               ;    /* 28 */
        unsigned int reserved_0                                       :   1               ;    /* 29 */
        unsigned int mps_div_b_cc1                                    :   1               ;    /* 30 */
        unsigned int mps_div_s_cc1                                    :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB3;

typedef union {
    struct {
        unsigned int mps_main_dagc_cc1                                :   16              ;    /* 15:0 */
        unsigned int mps_main_aadc_cc1                                :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB4;

typedef union {
    struct {
        unsigned int mps_main_drssi_cc1                               :   11              ;    /* 10:0 */
        unsigned int reserved_0                                       :   5               ;    /* 15:11 */
        unsigned int mps_main_rssi_cc1                                :   11              ;    /* 26:16 */
        unsigned int reserved_1                                       :   3               ;    /* 29:27 */
        unsigned int mps_main_p_cc1                                   :   1               ;    /* 30 */
        unsigned int mps_main_i_cc1                                   :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB5;

typedef union {
    struct {
        unsigned int mps_div_dagc_cc1                                 :   16              ;    /* 15:0 */
        unsigned int mps_div_aadc_cc1                                 :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB6;

typedef union {
    struct {
        unsigned int mps_div_drssi_cc1                                :   11              ;    /* 10:0 */
        unsigned int reserved_0                                       :   5               ;    /* 15:11 */
        unsigned int mps_div_rssi_cc1                                 :   11              ;    /* 26:16 */
        unsigned int reserved_1                                       :   3               ;    /* 29:27 */
        unsigned int mps_div_p_cc1                                    :   1               ;    /* 30 */
        unsigned int mps_div_i_cc1                                    :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB7;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB0                       om_data0;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB1                       om_data1;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB2                       om_data2;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB3                       om_data3;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB4                       om_data4;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB5                       om_data5;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB6                       om_data6;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB7                       om_data7;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB0                       om_data0;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB1                       om_data1;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB2                       om_data2;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB3                       om_data3;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB4                       om_data4;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB5                       om_data5;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB6                       om_data6;
    UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_UMTS_SUB7                       om_data7;
} UMTS_SID_MPS_LIVE_BUFFER_INFO_CC1_BBP_MC;

typedef union {
    struct {
        unsigned int mps_msg_bitmap                                   :   11              ;    /* 10:0 */
        unsigned int mps_msg_ted                                      :   1               ;    /* 11 */
        unsigned int mps_cfg_func                                     :   4               ;    /* 15:12 */
        unsigned int mps_phy_sat                                      :   4               ;    /* 19:16 */
        unsigned int reserved_0                                       :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_C_A_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int mps_total_unit_num_c_out                         :   16              ;    /* 15:0 */
        unsigned int mps_total_pn_num_c_out                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_C_A_INFO_UMTS_SUB1;

typedef union {
    struct {
        unsigned int mps_a_unit_busy_flag_c_out                       :   16              ;    /* 15:0 */
        unsigned int mps_unit_busy_flag_c_out                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_C_A_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int mps_a_en_c_out                                   :   16              ;    /* 15:0 */
        unsigned int mps_corr_num_1_c_out                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_C_A_INFO_UMTS_SUB3;

typedef union {
    struct {
        unsigned int mps_div_data_basecnt                             :   16              ;    /* 15:0 */
        unsigned int mps_main_data_basecnt                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_C_A_INFO_UMTS_SUB4;

typedef union {
    struct {
        unsigned int mps_live_buf_sym_num_div                         :   16              ;    /* 15:0 */
        unsigned int mps_live_buf_sym_num_main                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_C_A_INFO_UMTS_SUB5;

typedef union {
    struct {
        unsigned int mps_div_data_basecnt_cc1                         :   16              ;    /* 15:0 */
        unsigned int mps_main_data_basecnt_cc1                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_C_A_INFO_UMTS_SUB6;

typedef union {
    struct {
        unsigned int mps_live_buf_sym_num_div_cc1                     :   16              ;    /* 15:0 */
        unsigned int mps_live_buf_sym_num_main_cc1                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_C_A_INFO_UMTS_SUB7;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB0                                   om_data0;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB1                                   om_data1;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB2                                   om_data2;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB3                                   om_data3;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB4                                   om_data4;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB5                                   om_data5;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB6                                   om_data6;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB7                                   om_data7;
    unsigned int                                                      mps_release_ill_occup;
    unsigned int                                                      reserved_0;
} UMTS_SID_MPS_C_A_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB0                                   om_data0;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB1                                   om_data1;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB2                                   om_data2;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB3                                   om_data3;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB4                                   om_data4;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB5                                   om_data5;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB6                                   om_data6;
    UMTS_SID_MPS_C_A_INFO_UMTS_SUB7                                   om_data7;
    unsigned int                                                      mps_release_ill_occup;
    unsigned int                                                      reserved_0;
} UMTS_SID_MPS_C_A_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int dagc_x0_sym_pre_0_re                             :   8               ;    /* 7:0 */
        unsigned int dagc_x0_sym_pre_0_img                            :   8               ;    /* 15:8 */
        unsigned int dagc_x0_sym_pre_1_re                             :   8               ;    /* 23:16 */
        unsigned int dagc_x0_sym_pre_1_img                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int dagc_x0_sym_pre_2_re                             :   8               ;    /* 7:0 */
        unsigned int dagc_x0_sym_pre_2_img                            :   8               ;    /* 15:8 */
        unsigned int dagc_x0_sym_pre_3_re                             :   8               ;    /* 23:16 */
        unsigned int dagc_x0_sym_pre_3_img                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB1;

typedef union {
    struct {
        unsigned int dagc_x0_sym_pre_4_re                             :   8               ;    /* 7:0 */
        unsigned int dagc_x0_sym_pre_4_img                            :   8               ;    /* 15:8 */
        unsigned int dagc_x0_sym_pre_5_re                             :   8               ;    /* 23:16 */
        unsigned int dagc_x0_sym_pre_5_img                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int dagc_x0_sym_pre_6_re                             :   8               ;    /* 7:0 */
        unsigned int dagc_x0_sym_pre_6_img                            :   8               ;    /* 15:8 */
        unsigned int dagc_x0_sym_pre_7_re                             :   8               ;    /* 23:16 */
        unsigned int dagc_x0_sym_pre_7_img                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB3;

typedef union {
    struct {
        unsigned int dagc_x0_sym_post_0_re                            :   8               ;    /* 7:0 */
        unsigned int dagc_x0_sym_post_0_img                           :   8               ;    /* 15:8 */
        unsigned int dagc_x0_sym_post_1_re                            :   8               ;    /* 23:16 */
        unsigned int dagc_x0_sym_post_1_img                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB4;

typedef union {
    struct {
        unsigned int dagc_x0_sym_post_2_re                            :   8               ;    /* 7:0 */
        unsigned int dagc_x0_sym_post_2_img                           :   8               ;    /* 15:8 */
        unsigned int dagc_x0_sym_post_3_re                            :   8               ;    /* 23:16 */
        unsigned int dagc_x0_sym_post_3_img                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB5;

typedef union {
    struct {
        unsigned int dagc_x0_sym_post_4_re                            :   8               ;    /* 7:0 */
        unsigned int dagc_x0_sym_post_4_img                           :   8               ;    /* 15:8 */
        unsigned int dagc_x0_sym_post_5_re                            :   8               ;    /* 23:16 */
        unsigned int dagc_x0_sym_post_5_img                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB6;

typedef union {
    struct {
        unsigned int dagc_x0_sym_post_6_re                            :   8               ;    /* 7:0 */
        unsigned int dagc_x0_sym_post_6_img                           :   8               ;    /* 15:8 */
        unsigned int dagc_x0_sym_post_7_re                            :   8               ;    /* 23:16 */
        unsigned int dagc_x0_sym_post_7_img                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB7;

typedef union {
    struct {
        unsigned int dagc_x2_sym_pre_0_re                             :   8               ;    /* 7:0 */
        unsigned int dagc_x2_sym_pre_0_img                            :   8               ;    /* 15:8 */
        unsigned int dagc_x2_sym_pre_1_re                             :   8               ;    /* 23:16 */
        unsigned int dagc_x2_sym_pre_1_img                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB8;

typedef union {
    struct {
        unsigned int dagc_x2_sym_pre_2_re                             :   8               ;    /* 7:0 */
        unsigned int dagc_x2_sym_pre_2_img                            :   8               ;    /* 15:8 */
        unsigned int dagc_x2_sym_pre_3_re                             :   8               ;    /* 23:16 */
        unsigned int dagc_x2_sym_pre_3_img                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB9;

typedef union {
    struct {
        unsigned int dagc_x2_sym_pre_4_re                             :   8               ;    /* 7:0 */
        unsigned int dagc_x2_sym_pre_4_img                            :   8               ;    /* 15:8 */
        unsigned int dagc_x2_sym_pre_5_re                             :   8               ;    /* 23:16 */
        unsigned int dagc_x2_sym_pre_5_img                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB10;

typedef union {
    struct {
        unsigned int dagc_x2_sym_pre_6_re                             :   8               ;    /* 7:0 */
        unsigned int dagc_x2_sym_pre_6_img                            :   8               ;    /* 15:8 */
        unsigned int dagc_x2_sym_pre_7_re                             :   8               ;    /* 23:16 */
        unsigned int dagc_x2_sym_pre_7_img                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB11;

typedef union {
    struct {
        unsigned int dagc_x2_sym_post_0_re                            :   8               ;    /* 7:0 */
        unsigned int dagc_x2_sym_post_0_img                           :   8               ;    /* 15:8 */
        unsigned int dagc_x2_sym_post_1_re                            :   8               ;    /* 23:16 */
        unsigned int dagc_x2_sym_post_1_img                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB12;

typedef union {
    struct {
        unsigned int dagc_x2_sym_post_2_re                            :   8               ;    /* 7:0 */
        unsigned int dagc_x2_sym_post_2_img                           :   8               ;    /* 15:8 */
        unsigned int dagc_x2_sym_post_3_re                            :   8               ;    /* 23:16 */
        unsigned int dagc_x2_sym_post_3_img                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB13;

typedef union {
    struct {
        unsigned int dagc_x2_sym_post_4_re                            :   8               ;    /* 7:0 */
        unsigned int dagc_x2_sym_post_4_img                           :   8               ;    /* 15:8 */
        unsigned int dagc_x2_sym_post_5_re                            :   8               ;    /* 23:16 */
        unsigned int dagc_x2_sym_post_5_img                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB14;

typedef union {
    struct {
        unsigned int dagc_x2_sym_post_6_re                            :   8               ;    /* 7:0 */
        unsigned int dagc_x2_sym_post_6_img                           :   8               ;    /* 15:8 */
        unsigned int dagc_x2_sym_post_7_re                            :   8               ;    /* 23:16 */
        unsigned int dagc_x2_sym_post_7_img                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DATA_INFO_UMTS_SUB15;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB0                                  om_data0;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB1                                  om_data1;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB2                                  om_data2;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB3                                  om_data3;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB4                                  om_data4;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB5                                  om_data5;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB6                                  om_data6;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB7                                  om_data7;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB8                                  om_data8;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB9                                  om_data9;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB10                                 om_data10;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB11                                 om_data11;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB12                                 om_data12;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB13                                 om_data13;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB14                                 om_data14;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB15                                 om_data15;
} UMTS_SID_MPS_DATA_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB0                                  om_data0;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB1                                  om_data1;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB2                                  om_data2;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB3                                  om_data3;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB4                                  om_data4;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB5                                  om_data5;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB6                                  om_data6;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB7                                  om_data7;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB8                                  om_data8;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB9                                  om_data9;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB10                                 om_data10;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB11                                 om_data11;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB12                                 om_data12;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB13                                 om_data13;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB14                                 om_data14;
    UMTS_SID_MPS_DATA_INFO_UMTS_SUB15                                 om_data15;
} UMTS_SID_MPS_DATA_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int cc0_rx0_s_time                                   :   16              ;    /* 15:0 */
        unsigned int cc0_rx0_s_addr                                   :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int cc0_rx0_e_time                                   :   16              ;    /* 15:0 */
        unsigned int cc0_rx0_e_addr                                   :   12              ;    /* 27:16 */
        unsigned int cc0_rx0_c                                        :   1               ;    /* 28 */
        unsigned int cc0_rx0_d                                        :   1               ;    /* 29 */
        unsigned int cc0_rx0_b                                        :   1               ;    /* 30 */
        unsigned int cc0_rx0_s                                        :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB1;

typedef union {
    struct {
        unsigned int cc0_rx1_s_time                                   :   16              ;    /* 15:0 */
        unsigned int cc0_rx1_s_addr                                   :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int cc0_rx1_e_time                                   :   16              ;    /* 15:0 */
        unsigned int cc0_rx1_e_addr                                   :   12              ;    /* 27:16 */
        unsigned int cc0_rx1_rsv_0                                    :   2               ;    /* 29:28 */
        unsigned int cc0_rx1_b                                        :   1               ;    /* 30 */
        unsigned int cc0_rx1_s                                        :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB3;

typedef union {
    struct {
        unsigned int cc1_rx0_s_time                                   :   16              ;    /* 15:0 */
        unsigned int cc1_rx0_s_addr                                   :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB4;

typedef union {
    struct {
        unsigned int cc1_rx0_e_time                                   :   16              ;    /* 15:0 */
        unsigned int cc1_rx0_e_addr                                   :   12              ;    /* 27:16 */
        unsigned int cc1_rx0_rsv_0                                    :   1               ;    /* 28 */
        unsigned int cc1_rx0_d                                        :   1               ;    /* 29 */
        unsigned int cc1_rx0_b                                        :   1               ;    /* 30 */
        unsigned int cc1_rx0_s                                        :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB5;

typedef union {
    struct {
        unsigned int cc1_rx1_s_time                                   :   16              ;    /* 15:0 */
        unsigned int cc1_rx1_s_addr                                   :   12              ;    /* 27:16 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB6;

typedef union {
    struct {
        unsigned int cc1_rx1_e_time                                   :   16              ;    /* 15:0 */
        unsigned int cc1_rx1_e_addr                                   :   12              ;    /* 27:16 */
        unsigned int cc1_rx1_rsv_0                                    :   2               ;    /* 29:28 */
        unsigned int cc1_rx1_b                                        :   1               ;    /* 30 */
        unsigned int cc1_rx1_s                                        :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB7;

typedef union {
    struct {
        unsigned int wdc_state_pc                                     :   2               ;    /* 1:0 */
        unsigned int wdc_next_state_pc                                :   2               ;    /* 3:2 */
        unsigned int wdc_state_sc                                     :   2               ;    /* 5:4 */
        unsigned int wdc_next_state_sc                                :   2               ;    /* 7:6 */
        unsigned int subframe_head_ind                                :   1               ;    /* 8 */
        unsigned int off_itr_ind                                      :   1               ;    /* 9 */
        unsigned int ping_pang_flag                                   :   1               ;    /* 10 */
        unsigned int real_delay_tap_pc                                :   3               ;    /* 13:11 */
        unsigned int real_delay_tap_sc                                :   3               ;    /* 16:14 */
        unsigned int lmmse_init_flag_pc                               :   1               ;    /* 17 */
        unsigned int lmmse_init_flag_sc                               :   1               ;    /* 18 */
        unsigned int cpich_slot_cnt                                   :   4               ;    /* 22:19 */
        unsigned int cpich_sym_cnt                                    :   4               ;    /* 26:23 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB8;

typedef union {
    struct {
        unsigned int real_sig2dual_rx_ind                             :   1               ;    /* 0 */
        unsigned int real_dual2sig_rx_ind                             :   1               ;    /* 1 */
        unsigned int real_sc2dc_ind                                   :   1               ;    /* 2 */
        unsigned int real_dc2sc_ind                                   :   1               ;    /* 3 */
        unsigned int delay_sig2dual_rx_ind                            :   1               ;    /* 4 */
        unsigned int delay_dual2sig_rx_ind                            :   1               ;    /* 5 */
        unsigned int delay_sc2dc_ind                                  :   1               ;    /* 6 */
        unsigned int delay_dc2sc_ind                                  :   1               ;    /* 7 */
        unsigned int r5_renew_flag_pc                                 :   1               ;    /* 8 */
        unsigned int fg_renew_flag_pc                                 :   1               ;    /* 9 */
        unsigned int wdc_state                                        :   2               ;    /* 11:10 */
        unsigned int inter_frequency                                  :   1               ;    /* 12 */
        unsigned int reserved_0                                       :   19              ;    /* 31:13 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB9;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB0                                 om_data0;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB1                                 om_data1;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB2                                 om_data2;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB3                                 om_data3;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB4                                 om_data4;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB5                                 om_data5;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB6                                 om_data6;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB7                                 om_data7;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB8                                 om_data8;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB9                                 om_data9;
} UMTS_SID_LMMSE_WDC_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB0                                 om_data0;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB1                                 om_data1;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB2                                 om_data2;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB3                                 om_data3;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB4                                 om_data4;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB5                                 om_data5;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB6                                 om_data6;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB7                                 om_data7;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB8                                 om_data8;
    UMTS_SID_LMMSE_WDC_INFO_UMTS_SUB9                                 om_data9;
} UMTS_SID_LMMSE_WDC_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int cell_status                                      :   7               ;    /* 6:0 */
        unsigned int reserved_0                                       :   25              ;    /* 31:7 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_CHE_INFO_UMTS_SUB12;

typedef union {
    struct {
        unsigned int r5_renew                                         :   16              ;    /* 15:0 */
        unsigned int fg_renew                                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_CHE_INFO_UMTS_SUB15;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pri_rx1_fg0pow_rpt;
    unsigned int                                                      pri_rx1_fg1pow_rpt;
    unsigned int                                                      pri_rx1_fg2pow_rpt;
    unsigned int                                                      pri_rx1_fg3pow_rpt;
    unsigned int                                                      pri_rx1_fg4pow_rpt;
    unsigned int                                                      pri_rx1_fg5pow_rpt;
    unsigned int                                                      pri_rx2_fg0pow_rpt;
    unsigned int                                                      pri_rx2_fg1pow_rpt;
    unsigned int                                                      pri_rx2_fg2pow_rpt;
    unsigned int                                                      pri_rx2_fg3pow_rpt;
    unsigned int                                                      pri_rx2_fg4pow_rpt;
    unsigned int                                                      pri_rx2_fg5pow_rpt;
    UMTS_SID_LMMSE_WDC_CHE_INFO_UMTS_SUB12                            om_data12;
    unsigned int                                                      reserved_0;
    unsigned int                                                      ovsf_no;
    UMTS_SID_LMMSE_WDC_CHE_INFO_UMTS_SUB15                            om_data15;
    unsigned int                                                      sec_cell_ind;
    unsigned int                                                      wr_ptr_his;
    unsigned int                                                      fir_history_rd_ptr;
    unsigned int                                                      wr_ptr_backup;
} UMTS_SID_LMMSE_WDC_CHE_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pri_rx1_fg0pow_rpt;
    unsigned int                                                      pri_rx1_fg1pow_rpt;
    unsigned int                                                      pri_rx1_fg2pow_rpt;
    unsigned int                                                      pri_rx1_fg3pow_rpt;
    unsigned int                                                      pri_rx1_fg4pow_rpt;
    unsigned int                                                      pri_rx1_fg5pow_rpt;
    unsigned int                                                      pri_rx2_fg0pow_rpt;
    unsigned int                                                      pri_rx2_fg1pow_rpt;
    unsigned int                                                      pri_rx2_fg2pow_rpt;
    unsigned int                                                      pri_rx2_fg3pow_rpt;
    unsigned int                                                      pri_rx2_fg4pow_rpt;
    unsigned int                                                      pri_rx2_fg5pow_rpt;
    UMTS_SID_LMMSE_WDC_CHE_INFO_UMTS_SUB12                            om_data12;
    unsigned int                                                      reserved_0;
    unsigned int                                                      ovsf_no;
    UMTS_SID_LMMSE_WDC_CHE_INFO_UMTS_SUB15                            om_data15;
    unsigned int                                                      sec_cell_ind;
    unsigned int                                                      wr_ptr_his;
    unsigned int                                                      fir_history_rd_ptr;
    unsigned int                                                      wr_ptr_backup;
} UMTS_SID_LMMSE_WDC_CHE_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pri_rx0_sym0_descramble_fg0_rpt;
    unsigned int                                                      pri_rx0_sym0_descramble_fg1_rpt;
    unsigned int                                                      pri_rx0_sym0_descramble_fg2_rpt;
    unsigned int                                                      pri_rx0_sym0_descramble_fg3_rpt;
    unsigned int                                                      pri_rx0_sym0_descramble_fg4_rpt;
    unsigned int                                                      pri_rx0_sym0_descramble_fg5_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg0_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg1_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg2_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg3_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg4_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg5_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg0_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg1_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg2_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg3_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg4_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg5_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg0_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg1_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg2_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg3_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg4_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg5_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg0_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg1_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg2_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg3_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg4_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg5_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg0_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg1_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg2_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg3_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg4_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg5_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg0_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg1_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg2_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg3_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg4_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg5_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg0_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg1_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg2_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg3_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg4_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg5_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg0_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg1_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg2_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg3_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg4_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg5_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg0_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg1_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg2_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg3_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg4_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg5_rpt;
    unsigned int                                                      ic1_rx0_sym1_descramble_fg0_rpt;
    unsigned int                                                      ic1_rx0_sym1_descramble_fg1_rpt;
    unsigned int                                                      ic1_rx0_sym1_descramble_fg2_rpt;
    unsigned int                                                      ic1_rx0_sym1_descramble_fg3_rpt;
} UMTS_SID_LMMSE_WDC_CHE_DESCRAMBLE_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pri_rx0_sym0_descramble_fg0_rpt;
    unsigned int                                                      pri_rx0_sym0_descramble_fg1_rpt;
    unsigned int                                                      pri_rx0_sym0_descramble_fg2_rpt;
    unsigned int                                                      pri_rx0_sym0_descramble_fg3_rpt;
    unsigned int                                                      pri_rx0_sym0_descramble_fg4_rpt;
    unsigned int                                                      pri_rx0_sym0_descramble_fg5_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg0_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg1_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg2_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg3_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg4_rpt;
    unsigned int                                                      pri_rx1_sym0_descramble_fg5_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg0_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg1_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg2_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg3_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg4_rpt;
    unsigned int                                                      pri_rx0_sym1_descramble_fg5_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg0_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg1_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg2_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg3_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg4_rpt;
    unsigned int                                                      pri_rx1_sym1_descramble_fg5_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg0_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg1_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg2_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg3_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg4_rpt;
    unsigned int                                                      ic0_rx0_sym0_descramble_fg5_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg0_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg1_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg2_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg3_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg4_rpt;
    unsigned int                                                      ic0_rx1_sym0_descramble_fg5_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg0_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg1_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg2_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg3_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg4_rpt;
    unsigned int                                                      ic0_rx0_sym1_descramble_fg5_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg0_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg1_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg2_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg3_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg4_rpt;
    unsigned int                                                      ic0_rx1_sym1_descramble_fg5_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg0_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg1_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg2_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg3_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg4_rpt;
    unsigned int                                                      ic1_rx0_sym0_descramble_fg5_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg0_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg1_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg2_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg3_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg4_rpt;
    unsigned int                                                      ic1_rx1_sym0_descramble_fg5_rpt;
    unsigned int                                                      ic1_rx0_sym1_descramble_fg0_rpt;
    unsigned int                                                      ic1_rx0_sym1_descramble_fg1_rpt;
    unsigned int                                                      ic1_rx0_sym1_descramble_fg2_rpt;
    unsigned int                                                      ic1_rx0_sym1_descramble_fg3_rpt;
} UMTS_SID_LMMSE_WDC_CHE_DESCRAMBLE_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pri_rx0_tx0_filter_fg0_rpt;
    unsigned int                                                      pri_rx0_tx0_filter_fg1_rpt;
    unsigned int                                                      pri_rx0_tx0_filter_fg2_rpt;
    unsigned int                                                      pri_rx0_tx0_filter_fg3_rpt;
    unsigned int                                                      pri_rx0_tx0_filter_fg4_rpt;
    unsigned int                                                      pri_rx0_tx0_filter_fg5_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg0_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg1_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg2_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg3_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg4_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg5_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg0_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg1_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg2_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg3_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg4_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg5_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg0_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg1_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg2_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg3_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg4_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg5_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg0_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg1_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg2_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg3_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg4_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg5_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg0_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg1_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg2_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg3_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg4_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg5_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg0_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg1_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg2_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg3_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg4_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg5_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg0_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg1_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg2_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg3_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg4_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg5_rpt;
} UMTS_SID_LMMSE_WDC_CHE_FILTER_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pri_rx0_tx0_filter_fg0_rpt;
    unsigned int                                                      pri_rx0_tx0_filter_fg1_rpt;
    unsigned int                                                      pri_rx0_tx0_filter_fg2_rpt;
    unsigned int                                                      pri_rx0_tx0_filter_fg3_rpt;
    unsigned int                                                      pri_rx0_tx0_filter_fg4_rpt;
    unsigned int                                                      pri_rx0_tx0_filter_fg5_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg0_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg1_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg2_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg3_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg4_rpt;
    unsigned int                                                      pri_rx0_tx1_filter_fg5_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg0_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg1_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg2_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg3_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg4_rpt;
    unsigned int                                                      pri_rx1_tx0_filter_fg5_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg0_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg1_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg2_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg3_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg4_rpt;
    unsigned int                                                      pri_rx1_tx1_filter_fg5_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg0_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg1_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg2_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg3_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg4_rpt;
    unsigned int                                                      ic0_rx0_tx0_filter_fg5_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg0_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg1_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg2_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg3_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg4_rpt;
    unsigned int                                                      ic0_rx1_tx0_filter_fg5_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg0_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg1_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg2_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg3_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg4_rpt;
    unsigned int                                                      ic1_rx0_tx0_filter_fg5_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg0_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg1_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg2_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg3_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg4_rpt;
    unsigned int                                                      ic1_rx1_tx0_filter_fg5_rpt;
} UMTS_SID_LMMSE_WDC_CHE_FILTER_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      rx0_signal_power_rpt;
    unsigned int                                                      rx1_signal_power_rpt;
    unsigned int                                                      pri_cell_rx0_max_ioc_power_rpt;
    unsigned int                                                      pri_cell_rx0_snd_ioc_power_rpt;
    unsigned int                                                      pri_cell_rx1_max_ioc_power_rpt;
    unsigned int                                                      pri_cell_rx1_snd_ioc_power_rpt;
    unsigned int                                                      ic0_rx0_max_ioc_power_rpt;
    unsigned int                                                      ic0_rx0_snd_ioc_power_rpt;
    unsigned int                                                      ic0_rx1_max_ioc_power_rpt;
    unsigned int                                                      ic0_rx1_snd_ioc_power_rpt;
    unsigned int                                                      ic1_rx0_max_ioc_power_rpt;
    unsigned int                                                      ic1_rx0_snd_ioc_power_rpt;
    unsigned int                                                      ic1_rx1_max_ioc_power_rpt;
    unsigned int                                                      ic1_rx1_snd_ioc_power_rpt;
    unsigned int                                                      pri_cell_rx0_max_cpich_power_rpt;
    unsigned int                                                      pri_cell_rx0_snd_cpich_power_rpt;
    unsigned int                                                      pri_cell_rx1_max_cpich_power_rpt;
    unsigned int                                                      pri_cell_rx1_snd_cpich_power_rpt;
    unsigned int                                                      ic0_rx0_max_cpich_power_rpt;
    unsigned int                                                      ic0_rx0_snd_cpich_power_rpt;
    unsigned int                                                      ic0_rx1_max_cpich_power_rpt;
    unsigned int                                                      ic0_rx1_snd_cpich_power_rpt;
    unsigned int                                                      ic1_rx0_max_cpich_power_rpt;
    unsigned int                                                      ic1_rx0_snd_cpich_power_rpt;
    unsigned int                                                      ic1_rx1_max_cpich_power_rpt;
    unsigned int                                                      ic1_rx1_snd_cpich_power_rpt;
} UMTS_SID_LMMSE_WDC_IOREC_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rx0_signal_power_rpt;
    unsigned int                                                      rx1_signal_power_rpt;
    unsigned int                                                      pri_cell_rx0_max_ioc_power_rpt;
    unsigned int                                                      pri_cell_rx0_snd_ioc_power_rpt;
    unsigned int                                                      pri_cell_rx1_max_ioc_power_rpt;
    unsigned int                                                      pri_cell_rx1_snd_ioc_power_rpt;
    unsigned int                                                      ic0_rx0_max_ioc_power_rpt;
    unsigned int                                                      ic0_rx0_snd_ioc_power_rpt;
    unsigned int                                                      ic0_rx1_max_ioc_power_rpt;
    unsigned int                                                      ic0_rx1_snd_ioc_power_rpt;
    unsigned int                                                      ic1_rx0_max_ioc_power_rpt;
    unsigned int                                                      ic1_rx0_snd_ioc_power_rpt;
    unsigned int                                                      ic1_rx1_max_ioc_power_rpt;
    unsigned int                                                      ic1_rx1_snd_ioc_power_rpt;
    unsigned int                                                      pri_cell_rx0_max_cpich_power_rpt;
    unsigned int                                                      pri_cell_rx0_snd_cpich_power_rpt;
    unsigned int                                                      pri_cell_rx1_max_cpich_power_rpt;
    unsigned int                                                      pri_cell_rx1_snd_cpich_power_rpt;
    unsigned int                                                      ic0_rx0_max_cpich_power_rpt;
    unsigned int                                                      ic0_rx0_snd_cpich_power_rpt;
    unsigned int                                                      ic0_rx1_max_cpich_power_rpt;
    unsigned int                                                      ic0_rx1_snd_cpich_power_rpt;
    unsigned int                                                      ic1_rx0_max_cpich_power_rpt;
    unsigned int                                                      ic1_rx0_snd_cpich_power_rpt;
    unsigned int                                                      ic1_rx1_max_cpich_power_rpt;
    unsigned int                                                      ic1_rx1_snd_cpich_power_rpt;
} UMTS_SID_LMMSE_WDC_IOREC_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int symb_num                                         :   8               ;    /* 7:0 */
        unsigned int slot_num                                         :   7               ;    /* 14:8 */
        unsigned int sec_cell_ind                                     :   1               ;    /* 15 */
        unsigned int ec_ior                                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_NOI_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int snr_no_po                                        :   16              ;    /* 15:0 */
        unsigned int noi_cons                                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_NOI_INFO_UMTS_SUB5;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      rx1_noi_rpt;
    unsigned int                                                      rx2_noi_rpt;
    UMTS_SID_LMMSE_WDC_NOI_INFO_UMTS_SUB2                             om_data2;
    unsigned int                                                      one_path_pwr_rx0;
    unsigned int                                                      one_path_pwr_rx1;
    UMTS_SID_LMMSE_WDC_NOI_INFO_UMTS_SUB5                             om_data5;
    unsigned int                                                      lsrc_hnoise_rx0;
    unsigned int                                                      lsrc_hnoise_rx1;
} UMTS_SID_LMMSE_WDC_NOI_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rx1_noi_rpt;
    unsigned int                                                      rx2_noi_rpt;
    UMTS_SID_LMMSE_WDC_NOI_INFO_UMTS_SUB2                             om_data2;
    unsigned int                                                      one_path_pwr_rx0;
    unsigned int                                                      one_path_pwr_rx1;
    UMTS_SID_LMMSE_WDC_NOI_INFO_UMTS_SUB5                             om_data5;
    unsigned int                                                      lsrc_hnoise_rx0;
    unsigned int                                                      lsrc_hnoise_rx1;
} UMTS_SID_LMMSE_WDC_NOI_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int sample_idx                                       :   8               ;    /* 7:0 */
        unsigned int ofst_sel                                         :   1               ;    /* 8 */
        unsigned int rx_sel                                           :   4               ;    /* 12:9 */
        unsigned int card_ind                                         :   1               ;    /* 13 */
        unsigned int chip_num                                         :   12              ;    /* 25:14 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_DIF_DRIVER_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int slot_start_pc                                    :   4               ;    /* 3:0 */
        unsigned int symb_start_pc                                    :   4               ;    /* 7:4 */
        unsigned int chip_start_pc                                    :   8               ;    /* 15:8 */
        unsigned int slot_start_sc                                    :   4               ;    /* 19:16 */
        unsigned int symb_start_sc                                    :   4               ;    /* 23:20 */
        unsigned int chip_start_sc                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_WDC_DIF_DRIVER_INFO_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_LMMSE_WDC_DIF_DRIVER_INFO_UMTS_SUB0                      om_data0;
    UMTS_SID_LMMSE_WDC_DIF_DRIVER_INFO_UMTS_SUB1                      om_data1;
} UMTS_SID_LMMSE_WDC_DIF_DRIVER_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_LMMSE_WDC_DIF_DRIVER_INFO_UMTS_SUB0                      om_data0;
    UMTS_SID_LMMSE_WDC_DIF_DRIVER_INFO_UMTS_SUB1                      om_data1;
} UMTS_SID_LMMSE_WDC_DIF_DRIVER_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      fir_hw00;
    unsigned int                                                      fir_hw01;
    unsigned int                                                      fir_hw10;
    unsigned int                                                      fir_hw11;
    unsigned int                                                      scch_ch0_sym0;
    unsigned int                                                      scch_ch0_sym1;
    unsigned int                                                      scch_ch0_sym2;
    unsigned int                                                      scch_ch0_sym3;
    unsigned int                                                      scch_ch1_sym0;
    unsigned int                                                      scch_ch1_sym1;
    unsigned int                                                      scch_ch1_sym2;
    unsigned int                                                      scch_ch1_sym3;
    unsigned int                                                      scch_ch2_sym0;
    unsigned int                                                      scch_ch2_sym1;
    unsigned int                                                      scch_ch2_sym2;
    unsigned int                                                      scch_ch2_sym3;
    unsigned int                                                      scch_ch3_sym0;
    unsigned int                                                      scch_ch3_sym1;
    unsigned int                                                      scch_ch3_sym2;
    unsigned int                                                      scch_ch3_sym3;
} UMTS_SID_LMMSE_SCCH_DEM_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      fir_hw00;
    unsigned int                                                      fir_hw01;
    unsigned int                                                      fir_hw10;
    unsigned int                                                      fir_hw11;
    unsigned int                                                      scch_ch0_sym0;
    unsigned int                                                      scch_ch0_sym1;
    unsigned int                                                      scch_ch0_sym2;
    unsigned int                                                      scch_ch0_sym3;
    unsigned int                                                      scch_ch1_sym0;
    unsigned int                                                      scch_ch1_sym1;
    unsigned int                                                      scch_ch1_sym2;
    unsigned int                                                      scch_ch1_sym3;
    unsigned int                                                      scch_ch2_sym0;
    unsigned int                                                      scch_ch2_sym1;
    unsigned int                                                      scch_ch2_sym2;
    unsigned int                                                      scch_ch2_sym3;
    unsigned int                                                      scch_ch3_sym0;
    unsigned int                                                      scch_ch3_sym1;
    unsigned int                                                      scch_ch3_sym2;
    unsigned int                                                      scch_ch3_sym3;
} UMTS_SID_LMMSE_SCCH_DEM_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int fade_fac                                         :   16              ;    /* 15:0 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO0_UMTS_SUB4;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      factor0;
    unsigned int                                                      factor1;
    unsigned int                                                      factor2;
    unsigned int                                                      factor3;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO0_UMTS_SUB4                          om_data4;
    unsigned int                                                      rake_w2;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO0_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      factor0;
    unsigned int                                                      factor1;
    unsigned int                                                      factor2;
    unsigned int                                                      factor3;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO0_UMTS_SUB4                          om_data4;
    unsigned int                                                      rake_w2;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO0_BBP_MC;

typedef union {
    struct {
        unsigned int llr_step1_sch0                                   :   16              ;    /* 15:0 */
        unsigned int llr_step1_sch1                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB9;

typedef union {
    struct {
        unsigned int llr_step1_sch2                                   :   16              ;    /* 15:0 */
        unsigned int llr_step1_sch3                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB10;

typedef union {
    struct {
        unsigned int llr_step1_sch4                                   :   16              ;    /* 15:0 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB11;

typedef union {
    struct {
        unsigned int one_mag_coeff_sch0                               :   16              ;    /* 15:0 */
        unsigned int one_mag_coeff_sch1                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB12;

typedef union {
    struct {
        unsigned int one_mag_coeff_sch2                               :   16              ;    /* 15:0 */
        unsigned int one_mag_coeff_sch3                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB13;

typedef union {
    struct {
        unsigned int one_mag_coeff_sch4                               :   16              ;    /* 15:0 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB14;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      snr_llr;
    unsigned int                                                      power_offset;
    unsigned int                                                      snr_no_po;
    unsigned int                                                      cpich_s_pow;
    unsigned int                                                      delta;
    unsigned int                                                      fgnoi_n00;
    unsigned int                                                      fgnoi_n11;
    unsigned int                                                      fgnoi_n01_re;
    unsigned int                                                      fgnoi_n01_im;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB9                          om_data9;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB10                         om_data10;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB11                         om_data11;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB12                         om_data12;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB13                         om_data13;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB14                         om_data14;
    unsigned int                                                      reserved_0;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      snr_llr;
    unsigned int                                                      power_offset;
    unsigned int                                                      snr_no_po;
    unsigned int                                                      cpich_s_pow;
    unsigned int                                                      delta;
    unsigned int                                                      fgnoi_n00;
    unsigned int                                                      fgnoi_n11;
    unsigned int                                                      fgnoi_n01_re;
    unsigned int                                                      fgnoi_n01_im;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB9                          om_data9;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB10                         om_data10;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB11                         om_data11;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB12                         om_data12;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB13                         om_data13;
    UMTS_SID_LMMSE_PDSCH_DEM_INFO1_UMTS_SUB14                         om_data14;
    unsigned int                                                      reserved_0;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO1_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      cpu_cqi_pre_th;
    unsigned int                                                      cqi_result;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO2_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cpu_cqi_pre_th;
    unsigned int                                                      cqi_result;
} UMTS_SID_LMMSE_PDSCH_DEM_INFO2_BBP_MC;

typedef union {
    struct {
        unsigned int tfci_ber                                         :   8               ;    /* 7:0 */
        unsigned int tfci_value                                       :   10              ;    /* 17:8 */
        unsigned int r99_btfd_guide_error_flag                        :   1               ;    /* 18 */
        unsigned int r99_btfd_guide_error_type                        :   1               ;    /* 19 */
        unsigned int hard_vtb_cmd_v                                   :   1               ;    /* 20 */
        unsigned int hard_turbo_cmd_v                                 :   1               ;    /* 21 */
        unsigned int turbo_rpt_cmd_v                                  :   1               ;    /* 22 */
        unsigned int turbo_derm_num                                   :   3               ;    /* 25:23 */
        unsigned int enter_turbo_derm_num                             :   3               ;    /* 28:26 */
        unsigned int turbo_derm_finish_flag                           :   1               ;    /* 29 */
        unsigned int r99_80ms_ind                                     :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_DCH_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int trch_tfi_0                                       :   6               ;    /* 5:0 */
        unsigned int btfd_guide_error_flag_0                          :   1               ;    /* 6 */
        unsigned int btfd_guide_error_type_0                          :   1               ;    /* 7 */
        unsigned int trch_tfi_1                                       :   6               ;    /* 13:8 */
        unsigned int btfd_guide_error_flag_1                          :   1               ;    /* 14 */
        unsigned int btfd_guide_error_type_1                          :   1               ;    /* 15 */
        unsigned int trch_tfi_2                                       :   6               ;    /* 21:16 */
        unsigned int btfd_guide_error_flag_2                          :   1               ;    /* 22 */
        unsigned int btfd_guide_error_type_2                          :   1               ;    /* 23 */
        unsigned int trch_tfi_3                                       :   6               ;    /* 29:24 */
        unsigned int btfd_guide_error_flag_3                          :   1               ;    /* 30 */
        unsigned int btfd_guide_error_type_3                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_DCH_INFO_UMTS_SUB1;

typedef union {
    struct {
        unsigned int trch_tfi_4                                       :   6               ;    /* 5:0 */
        unsigned int btfd_guide_error_flag_4                          :   1               ;    /* 6 */
        unsigned int btfd_guide_error_type_4                          :   1               ;    /* 7 */
        unsigned int trch_tfi_5                                       :   6               ;    /* 13:8 */
        unsigned int btfd_guide_error_flag_5                          :   1               ;    /* 14 */
        unsigned int btfd_guide_error_type_5                          :   1               ;    /* 15 */
        unsigned int trch_tfi_6                                       :   6               ;    /* 21:16 */
        unsigned int btfd_guide_error_flag_6                          :   1               ;    /* 22 */
        unsigned int btfd_guide_error_type_6                          :   1               ;    /* 23 */
        unsigned int trch_tfi_7                                       :   6               ;    /* 29:24 */
        unsigned int btfd_guide_error_flag_7                          :   1               ;    /* 30 */
        unsigned int btfd_guide_error_type_7                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_DCH_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int hard_vtb_trch_num                                :   4               ;    /* 3:0 */
        unsigned int hard_turbo_trch_num                              :   4               ;    /* 7:4 */
        unsigned int vtb_trch_no_0                                    :   3               ;    /* 10:8 */
        unsigned int vtb_trch_no_1                                    :   3               ;    /* 13:11 */
        unsigned int vtb_trch_no_2                                    :   3               ;    /* 16:14 */
        unsigned int vtb_trch_no_3                                    :   3               ;    /* 19:17 */
        unsigned int vtb_trch_no_4                                    :   3               ;    /* 22:20 */
        unsigned int turbo_trch_no_0                                  :   3               ;    /* 25:23 */
        unsigned int turbo_trch_no_1                                  :   3               ;    /* 28:26 */
        unsigned int turbo_trch_no_2                                  :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_DCH_INFO_UMTS_SUB3;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_DEC_DCH_INFO_UMTS_SUB0                                   om_data0;
    UMTS_SID_DEC_DCH_INFO_UMTS_SUB1                                   om_data1;
    UMTS_SID_DEC_DCH_INFO_UMTS_SUB2                                   om_data2;
    UMTS_SID_DEC_DCH_INFO_UMTS_SUB3                                   om_data3;
} UMTS_SID_DEC_DCH_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_DEC_DCH_INFO_UMTS_SUB0                                   om_data0;
    UMTS_SID_DEC_DCH_INFO_UMTS_SUB1                                   om_data1;
    UMTS_SID_DEC_DCH_INFO_UMTS_SUB2                                   om_data2;
    UMTS_SID_DEC_DCH_INFO_UMTS_SUB3                                   om_data3;
} UMTS_SID_DEC_DCH_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int scch_detect_flag                                 :   1               ;    /* 0 */
        unsigned int scch_detect_ch_no                                :   3               ;    /* 3:1 */
        unsigned int scch_detect_o                                    :   4               ;    /* 7:4 */
        unsigned int scch_detect_p                                    :   4               ;    /* 11:8 */
        unsigned int scch_detect_ms                                   :   2               ;    /* 13:12 */
        unsigned int scch_type_detect                                 :   4               ;    /* 17:14 */
        unsigned int scch_detect_data                                 :   8               ;    /* 25:18 */
        unsigned int hsd_less_frm_detect                              :   1               ;    /* 26 */
        unsigned int ms_o_p_unexpected                                :   1               ;    /* 27 */
        unsigned int scch_detect_flag_dec                             :   1               ;    /* 28 */
        unsigned int hard_vdl_cmd_v                                   :   1               ;    /* 29 */
        unsigned int send_vdl                                         :   1               ;    /* 30 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_SCCH_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int scch_rslt_wait_flag                              :   1               ;    /* 0 */
        unsigned int rpt_vld_pc                                       :   1               ;    /* 1 */
        unsigned int rpt_vld_sc                                       :   1               ;    /* 2 */
        unsigned int valid_cc_num_vdl                                 :   2               ;    /* 4:3 */
        unsigned int last_dc_ind                                      :   1               ;    /* 5 */
        unsigned int reserved_0                                       :   26              ;    /* 31:6 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_SCCH_INFO_UMTS_SUB1;

typedef union {
    struct {
        unsigned int analyze_pc_vld                                   :   1               ;    /* 0 */
        unsigned int condition_1_pc                                   :   1               ;    /* 1 */
        unsigned int condition_3_pc                                   :   1               ;    /* 2 */
        unsigned int scch_type_dec_vdl_pc                             :   6               ;    /* 8:3 */
        unsigned int hsd_order_type_pc                                :   6               ;    /* 14:9 */
        unsigned int rpt_phy_time_pc                                  :   1               ;    /* 15 */
        unsigned int vdl_hsd_para_tbs_pc                              :   6               ;    /* 21:16 */
        unsigned int vdl_hsd_para_hap_pc                              :   3               ;    /* 24:22 */
        unsigned int vdl_hsd_para_rv_pc                               :   3               ;    /* 27:25 */
        unsigned int vdl_hsd_para_nd_pc                               :   1               ;    /* 28 */
        unsigned int vdl_hsd_para_ptr_pc                              :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_SCCH_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int analyze_sc_vld                                   :   1               ;    /* 0 */
        unsigned int condition_1_sc                                   :   1               ;    /* 1 */
        unsigned int condition_3_sc                                   :   1               ;    /* 2 */
        unsigned int scch_type_dec_vdl_sc                             :   6               ;    /* 8:3 */
        unsigned int hsd_order_type_sc                                :   6               ;    /* 14:9 */
        unsigned int rpt_phy_time_sc                                  :   1               ;    /* 15 */
        unsigned int vdl_hsd_para_tbs_sc                              :   6               ;    /* 21:16 */
        unsigned int vdl_hsd_para_hap_sc                              :   3               ;    /* 24:22 */
        unsigned int vdl_hsd_para_rv_sc                               :   3               ;    /* 27:25 */
        unsigned int vdl_hsd_para_nd_sc                               :   1               ;    /* 28 */
        unsigned int vdl_hsd_para_ptr_sc                              :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_SCCH_INFO_UMTS_SUB3;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_DEC_SCCH_INFO_UMTS_SUB0                                  om_data0;
    UMTS_SID_DEC_SCCH_INFO_UMTS_SUB1                                  om_data1;
    UMTS_SID_DEC_SCCH_INFO_UMTS_SUB2                                  om_data2;
    UMTS_SID_DEC_SCCH_INFO_UMTS_SUB3                                  om_data3;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_DEC_SCCH_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_DEC_SCCH_INFO_UMTS_SUB0                                  om_data0;
    UMTS_SID_DEC_SCCH_INFO_UMTS_SUB1                                  om_data1;
    UMTS_SID_DEC_SCCH_INFO_UMTS_SUB2                                  om_data2;
    UMTS_SID_DEC_SCCH_INFO_UMTS_SUB3                                  om_data3;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_DEC_SCCH_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int less_hap0_flag_ld                                :   1               ;    /* 0 */
        unsigned int less_hap1_flag_ld                                :   1               ;    /* 1 */
        unsigned int less_hap2_flag_ld                                :   1               ;    /* 2 */
        unsigned int release_13_tti                                   :   1               ;    /* 3 */
        unsigned int raw_buffer_pointer                               :   4               ;    /* 7:4 */
        unsigned int redundant_frm_flag                               :   1               ;    /* 8 */
        unsigned int hsd_para_less_hap                                :   2               ;    /* 10:9 */
        unsigned int less_hap_full                                    :   1               ;    /* 11 */
        unsigned int occupied_flag                                    :   1               ;    /* 12 */
        unsigned int sat_ack_condition                                :   1               ;    /* 13 */
        unsigned int drawer_pointer                                   :   4               ;    /* 17:14 */
        unsigned int less_abcomb_flag                                 :   1               ;    /* 18 */
        unsigned int cb_derm1_out_len                                 :   13              ;    /* 31:19 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_PDSCH_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int pos_task_no                                      :   4               ;    /* 3:0 */
        unsigned int last_cb_flag                                     :   1               ;    /* 4 */
        unsigned int cb_cnt                                           :   4               ;    /* 8:5 */
        unsigned int hard_wdec_cmd_v                                  :   1               ;    /* 9 */
        unsigned int raw_or_ir_buffer                                 :   1               ;    /* 10 */
        unsigned int fdae_cmd_v                                       :   1               ;    /* 11 */
        unsigned int tb_crc_vld_correct                               :   1               ;    /* 12 */
        unsigned int tb_rpt_drawer_pointer                            :   4               ;    /* 16:13 */
        unsigned int tb_rpt_drawer_cnt_mod_14                         :   4               ;    /* 20:17 */
        unsigned int release_hap_buf                                  :   1               ;    /* 21 */
        unsigned int tb_rpt_hsd_para_less_hap                         :   2               ;    /* 23:22 */
        unsigned int rpt_time_pc                                      :   1               ;    /* 24 */
        unsigned int rpt_time_sc                                      :   1               ;    /* 25 */
        unsigned int norpt2xctrl                                      :   1               ;    /* 26 */
        unsigned int umts_pdsch_end_ind                               :   1               ;    /* 27 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_PDSCH_INFO_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_DEC_PDSCH_INFO_UMTS_SUB0                                 om_data0;
    UMTS_SID_DEC_PDSCH_INFO_UMTS_SUB1                                 om_data1;
} UMTS_SID_DEC_PDSCH_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_DEC_PDSCH_INFO_UMTS_SUB0                                 om_data0;
    UMTS_SID_DEC_PDSCH_INFO_UMTS_SUB1                                 om_data1;
} UMTS_SID_DEC_PDSCH_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_warn                                         :   1               ;    /* 0 */
        unsigned int ai_warn                                          :   1               ;    /* 1 */
        unsigned int reserved_0                                       :   30              ;    /* 31:2 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_RACH_DBG_INFO_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_XCTRL_RACH_DBG_INFO_UMTS_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_XCTRL_RACH_DBG_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_XCTRL_RACH_DBG_INFO_UMTS_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_XCTRL_RACH_DBG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int dpch_para_cfg_warn                               :   1               ;    /* 0 */
        unsigned int edch_para_cfg_warn                               :   1               ;    /* 1 */
        unsigned int dpa_para_cfg_warn                                :   1               ;    /* 2 */
        unsigned int gap_para_cfg_warn                                :   1               ;    /* 3 */
        unsigned int cfg_slot                                         :   4               ;    /* 7:4 */
        unsigned int reserved_0                                       :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_DBG_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int hsscch_hspdsch_unmatch_warn                      :   2               ;    /* 1:0 */
        unsigned int hsdpa_inter_tti_warn                             :   1               ;    /* 2 */
        unsigned int reserved_0                                       :   29              ;    /* 31:3 */
    } bits;
    unsigned int u32;
} UMTS_SID_XCTRL_DCH_DBG_INFO_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_XCTRL_DCH_DBG_INFO_UMTS_SUB0                             om_data0;
    UMTS_SID_XCTRL_DCH_DBG_INFO_UMTS_SUB1                             om_data1;
} UMTS_SID_XCTRL_DCH_DBG_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_XCTRL_DCH_DBG_INFO_UMTS_SUB0                             om_data0;
    UMTS_SID_XCTRL_DCH_DBG_INFO_UMTS_SUB1                             om_data1;
} UMTS_SID_XCTRL_DCH_DBG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int mps_msg_overgroups                               :   1               ;    /* 0 */
        unsigned int mps_msg_id_error                                 :   1               ;    /* 1 */
        unsigned int mps_msg_bitmap_error                             :   1               ;    /* 2 */
        unsigned int mps_group_ill_occup                              :   1               ;    /* 3 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} UMTS_SID_MPS_DBG_INFO_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_MPS_DBG_INFO_UMTS_SUB0                                   om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_MPS_DBG_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_MPS_DBG_INFO_UMTS_SUB0                                   om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_MPS_DBG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int over_buf_len                                     :   16              ;    /* 15:0 */
        unsigned int over_win_end                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_DBG_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int fg_type                                          :   3               ;    /* 2:0 */
        unsigned int reserved_0                                       :   29              ;    /* 31:3 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_DBG_INFO_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_DBG_INFO_UMTS_SUB0                                  om_data0;
    UMTS_SID_RAKE_DBG_INFO_UMTS_SUB1                                  om_data1;
} UMTS_SID_RAKE_DBG_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_DBG_INFO_UMTS_SUB0                                  om_data0;
    UMTS_SID_RAKE_DBG_INFO_UMTS_SUB1                                  om_data1;
} UMTS_SID_RAKE_DBG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int cpi_slot_num_rl0                                 :   16              ;    /* 15:0 */
        unsigned int cpi_slot_num_rl1                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB0;

typedef union {
    struct {
        unsigned int cpi_slot_num_rl2                                 :   16              ;    /* 15:0 */
        unsigned int cpi_slot_num_rl3                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB1;

typedef union {
    struct {
        unsigned int cpi_slot_num_rl4                                 :   16              ;    /* 15:0 */
        unsigned int cpi_slot_num_rl5                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB2;

typedef union {
    struct {
        unsigned int cpi_slot_num_rl6                                 :   16              ;    /* 15:0 */
        unsigned int cpi_sym_num_rl0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB3;

typedef union {
    struct {
        unsigned int cpi_sym_num_rl1                                  :   16              ;    /* 15:0 */
        unsigned int cpi_sym_num_rl2                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB4;

typedef union {
    struct {
        unsigned int cpi_sym_num_rl3                                  :   16              ;    /* 15:0 */
        unsigned int cpi_sym_num_rl4                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB5;

typedef union {
    struct {
        unsigned int cpi_sym_num_rl5                                  :   16              ;    /* 15:0 */
        unsigned int cpi_sym_num_rl6                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB6;

typedef union {
    struct {
        unsigned int todo_sym_num                                     :   8               ;    /* 7:0 */
        unsigned int todo_sym_num_pccp                                :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB7;

typedef union {
    struct {
        unsigned int wintop_chip_pst                                  :   12              ;    /* 11:0 */
        unsigned int wintop_slot_pst                                  :   4               ;    /* 15:12 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB8;

typedef union {
    struct {
        unsigned int winend_chip_pst                                  :   12              ;    /* 11:0 */
        unsigned int winend_slot_pst                                  :   4               ;    /* 15:12 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB9;

typedef union {
    struct {
        unsigned int s_time                                           :   16              ;    /* 15:0 */
        unsigned int s_addr                                           :   13              ;    /* 28:16 */
        unsigned int reserved_0                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB10;

typedef union {
    struct {
        unsigned int e_time                                           :   16              ;    /* 15:0 */
        unsigned int e_addr                                           :   13              ;    /* 28:16 */
        unsigned int d                                                :   1               ;    /* 29 */
        unsigned int b                                                :   1               ;    /* 30 */
        unsigned int s                                                :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB11;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB0                           om_data0;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB1                           om_data1;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB2                           om_data2;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB3                           om_data3;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB4                           om_data4;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB5                           om_data5;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB6                           om_data6;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB7                           om_data7;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB8                           om_data8;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB9                           om_data9;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB10                          om_data10;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB11                          om_data11;
} UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB0                           om_data0;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB1                           om_data1;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB2                           om_data2;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB3                           om_data3;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB4                           om_data4;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB5                           om_data5;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB6                           om_data6;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB7                           om_data7;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB8                           om_data8;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB9                           om_data9;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB10                          om_data10;
    UMTS_SID_RAKE_TIMING_DBG_INFO_UMTS_SUB11                          om_data11;
} UMTS_SID_RAKE_TIMING_DBG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tfci_num                                         :   16              ;    /* 15:0 */
        unsigned int data_num                                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_CCTRCH_DBG_INFO0_UMTS_SUB0;

typedef union {
    struct {
        unsigned int slot_num                                         :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} UMTS_SID_RAKE_CCTRCH_DBG_INFO0_UMTS_SUB1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_RAKE_CCTRCH_DBG_INFO0_UMTS_SUB0                          om_data0;
    UMTS_SID_RAKE_CCTRCH_DBG_INFO0_UMTS_SUB1                          om_data1;
} UMTS_SID_RAKE_CCTRCH_DBG_INFO0_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_RAKE_CCTRCH_DBG_INFO0_UMTS_SUB0                          om_data0;
    UMTS_SID_RAKE_CCTRCH_DBG_INFO0_UMTS_SUB1                          om_data1;
} UMTS_SID_RAKE_CCTRCH_DBG_INFO0_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      data_num;
    unsigned int                                                      reserved_0;
} UMTS_SID_RAKE_CCTRCH_DBG_INFO1_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data_num;
    unsigned int                                                      reserved_0;
} UMTS_SID_RAKE_CCTRCH_DBG_INFO1_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_WDC_CHE_DBG_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_WDC_CHE_DBG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int sch_tx_mode_abn                                  :   1               ;    /* 0 */
        unsigned int sch_a_abn                                        :   1               ;    /* 1 */
        unsigned int reserved_0                                       :   30              ;    /* 31:2 */
    } bits;
    unsigned int u32;
} UMTS_SID_LMMSE_EQU_DBG_INFO_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_LMMSE_EQU_DBG_INFO_UMTS_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_LMMSE_EQU_DBG_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_LMMSE_EQU_DBG_INFO_UMTS_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_LMMSE_EQU_DBG_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_SCCH_DEM_DBG_INFO0_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_SCCH_DEM_DBG_INFO0_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_SCCH_DEM_DBG_INFO1_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_SCCH_DEM_DBG_INFO1_BBP_MC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_PDSCH_DEM_DBG_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} UMTS_SID_LMMSE_PDSCH_DEM_DBG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int r99_btfd_cb2                                     :   1               ;    /* 0 */
        unsigned int r99_btfd_turbo                                   :   1               ;    /* 1 */
        unsigned int r99_max_split_exceed                             :   1               ;    /* 2 */
        unsigned int r99_split_punc_num_exceed                        :   1               ;    /* 3 */
        unsigned int r99_split_rept_num_exceed                        :   1               ;    /* 4 */
        unsigned int r99_pkt_tot_len_exceed                           :   1               ;    /* 5 */
        unsigned int vdl_para_prt_cb_len                              :   1               ;    /* 6 */
        unsigned int vdl_para_prt_cb_num                              :   1               ;    /* 7 */
        unsigned int vdl_para_prt_tb_len                              :   1               ;    /* 8 */
        unsigned int vdl_para_prt_tb_num                              :   1               ;    /* 9 */
        unsigned int dch_derm_len_exceed_range_turbo_rept             :   1               ;    /* 10 */
        unsigned int dch_derm_len_exceed_range_turbo_punc             :   1               ;    /* 11 */
        unsigned int dch_derm_len_exceed_range_vtb_rept               :   1               ;    /* 12 */
        unsigned int dch_derm_len_exceed_range_vtb_punc               :   1               ;    /* 13 */
        unsigned int dch_deintl_len_exceed_range_turbo                :   1               ;    /* 14 */
        unsigned int dch_deintl_len_exceed_range_vtb                  :   1               ;    /* 15 */
        unsigned int deintl_exceeds_6400_total                        :   1               ;    /* 16 */
        unsigned int deintl_exceeds_19200_total                       :   1               ;    /* 17 */
        unsigned int reserved_0                                       :   14              ;    /* 31:18 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_DCH_DBG_INFO_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_DEC_DCH_DBG_INFO_UMTS_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_DEC_DCH_DBG_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_DEC_DCH_DBG_INFO_UMTS_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_DEC_DCH_DBG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int ir_buffer_overflow                               :   1               ;    /* 0 */
        unsigned int hap_overflow                                     :   1               ;    /* 1 */
        unsigned int tb_crc_invld                                     :   1               ;    /* 2 */
        unsigned int turbo_rpt_early                                  :   1               ;    /* 3 */
        unsigned int pdma_cfg_len_exceed                              :   1               ;    /* 4 */
        unsigned int pdsch_derm_len_exceed_range_punc                 :   1               ;    /* 5 */
        unsigned int pdsch_derm_len_exceed_range_rept                 :   1               ;    /* 6 */
        unsigned int reserved_0                                       :   25              ;    /* 31:7 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_PDSCH_DBG_INFO_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_DEC_PDSCH_DBG_INFO_UMTS_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_DEC_PDSCH_DBG_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_DEC_PDSCH_DBG_INFO_UMTS_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_DEC_PDSCH_DBG_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int no_vdl_return_pc                                 :   1               ;    /* 0 */
        unsigned int no_vdl_return_sc                                 :   1               ;    /* 1 */
        unsigned int last_rslt_wait_flag_high                         :   1               ;    /* 2 */
        unsigned int status_active_conflict                           :   1               ;    /* 3 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} UMTS_SID_DEC_SCCH_DBG_INFO_UMTS_SUB0;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    UMTS_SID_DEC_SCCH_DBG_INFO_UMTS_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_DEC_SCCH_DBG_INFO_UMTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    UMTS_SID_DEC_SCCH_DBG_INFO_UMTS_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} UMTS_SID_DEC_SCCH_DBG_INFO_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
