

#ifndef __UPHY_PDE_TTS_OM_H__
#define __UPHY_PDE_TTS_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef union {
    struct {
        unsigned int aagc_gain_rx0                                    :   16              ;    /* 15:0 */
        unsigned int aagc_gain_rx1                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_ALG_BBPS_TTS_SUB0;

typedef union {
    struct {
        unsigned int freq_shift_num                                   :   4               ;    /* 3:0 */
        unsigned int freq_shift_en                                    :   4               ;    /* 7:4 */
        unsigned int lpf_filter_flag                                  :   2               ;    /* 9:8 */
        unsigned int rrc_filter_flag                                  :   2               ;    /* 11:10 */
        unsigned int lpf_coeff_sel                                    :   2               ;    /* 13:12 */
        unsigned int rssi_calc_mode                                   :   2               ;    /* 15:14 */
        unsigned int dagc_en                                          :   2               ;    /* 17:16 */
        unsigned int dagc_fix_en                                      :   2               ;    /* 19:18 */
        unsigned int ping_pang_flag                                   :   2               ;    /* 21:20 */
        unsigned int first_slot_flag                                  :   1               ;    /* 22 */
        unsigned int last_slot_flag                                   :   1               ;    /* 23 */
        unsigned int dagc_fix_year                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_ALG_BBPS_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_ALG_BBPS_TTS_SUB0                                  om_data0;
    TTS_SID_TTS_OM_ALG_BBPS_TTS_SUB1                                  om_data1;
} TTS_SID_TTS_OM_ALG_BBPS_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_ALG_BBPS_TTS_SUB0                                  om_data0;
    TTS_SID_TTS_OM_ALG_BBPS_TTS_SUB1                                  om_data1;
} TTS_SID_TTS_OM_ALG_BBPS_BBP_MC;

typedef union {
    struct {
        unsigned int burst_len                                        :   16              ;    /* 15:0 */
        unsigned int current_total_num                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_ALG_TOP_TTS_SUB0;

typedef union {
    struct {
        unsigned int dump_info_mode                                   :   4               ;    /* 3:0 */
        unsigned int ping_pang_flag                                   :   4               ;    /* 7:4 */
        unsigned int task_num                                         :   4               ;    /* 11:8 */
        unsigned int return_value                                     :   8               ;    /* 19:12 */
        unsigned int dif_ping_pang_ind                                :   4               ;    /* 23:20 */
        unsigned int rx_num                                           :   4               ;    /* 27:24 */
        unsigned int curr_is_rx23                                     :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_ALG_TOP_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_ALG_TOP_TTS_SUB0                                   om_data0;
    TTS_SID_TTS_OM_ALG_TOP_TTS_SUB1                                   om_data1;
} TTS_SID_TTS_OM_ALG_TOP_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_ALG_TOP_TTS_SUB0                                   om_data0;
    TTS_SID_TTS_OM_ALG_TOP_TTS_SUB1                                   om_data1;
} TTS_SID_TTS_OM_ALG_TOP_BBP_MC;

typedef union {
    struct {
        unsigned int comfort_noise_rst                                :   1               ;    /* 0 */
        unsigned int power_control_rst                                :   1               ;    /* 1 */
        unsigned int reserved_0                                       :   2               ;    /* 3:2 */
        unsigned int sacch_rst                                        :   1               ;    /* 4 */
        unsigned int llr_shift                                        :   4               ;    /* 8:5 */
        unsigned int dkab_llr_shift                                   :   4               ;    /* 12:9 */
        unsigned int reserved_1                                       :   19              ;    /* 31:13 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_TOP_IN_TTS_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_TOP_IN_TTS_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_TOP_IN_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_TOP_IN_TTS_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_TOP_IN_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      dummypow;
    unsigned int                                                      signalpow;
} TTS_SID_TTS_OM_DEM_DEC_BD_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      dummypow;
    unsigned int                                                      signalpow;
} TTS_SID_TTS_OM_DEM_DEC_BD_BBP_MC;

typedef union {
    struct {
        unsigned int bitbias                                          :   9               ;    /* 8:0 */
        unsigned int reserved_0                                       :   23              ;    /* 31:9 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_BD_BITBIAS_TTS_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_BD_BITBIAS_TTS_SUB0                        om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_BD_BITBIAS_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_BD_BITBIAS_TTS_SUB0                        om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_BD_BITBIAS_BBP_MC;

typedef union {
    struct {
        unsigned int llr0                                             :   8               ;    /* 7:0 */
        unsigned int llr1                                             :   8               ;    /* 15:8 */
        unsigned int llr2                                             :   8               ;    /* 23:16 */
        unsigned int llr3                                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR0_TTS_SUB0;

typedef union {
    struct {
        unsigned int llr4                                             :   8               ;    /* 7:0 */
        unsigned int llr5                                             :   8               ;    /* 15:8 */
        unsigned int llr6                                             :   8               ;    /* 23:16 */
        unsigned int llr7                                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR0_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR0_TTS_SUB0                         om_data0;
    TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR0_TTS_SUB1                         om_data1;
} TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR0_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR0_TTS_SUB0                         om_data0;
    TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR0_TTS_SUB1                         om_data1;
} TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR0_BBP_MC;

typedef union {
    struct {
        unsigned int llr8                                             :   8               ;    /* 7:0 */
        unsigned int llr9                                             :   8               ;    /* 15:8 */
        unsigned int llr10                                            :   8               ;    /* 23:16 */
        unsigned int llr11                                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR1_TTS_SUB0;

typedef union {
    struct {
        unsigned int llr12                                            :   8               ;    /* 7:0 */
        unsigned int llr13                                            :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR1_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR1_TTS_SUB0                         om_data0;
    TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR1_TTS_SUB1                         om_data1;
} TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR1_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR1_TTS_SUB0                         om_data0;
    TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR1_TTS_SUB1                         om_data1;
} TTS_SID_TTS_OM_DEM_DEC_DKAB_LLR1_BBP_MC;

typedef union {
    struct {
        unsigned int reserved_0                                       :   3               ;    /* 2:0 */
        unsigned int vtb_list_order_flag                              :   1               ;    /* 3 */
        unsigned int final_crc_flag                                   :   4               ;    /* 7:4 */
        unsigned int vtb_true_trace_back_num                          :   4               ;    /* 11:8 */
        unsigned int invalid_cw_flag                                  :   4               ;    /* 15:12 */
        unsigned int vtb_dec_zero_llr_flag                            :   4               ;    /* 19:16 */
        unsigned int vtb_max_trace_back_num                           :   4               ;    /* 23:20 */
        unsigned int reserved_1                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_TBCC_TTS_SUB0;

typedef union {
    struct {
        unsigned int vtb_channel_type                                 :   8               ;    /* 7:0 */
        unsigned int reserved_0                                       :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_TBCC_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_TBCC_TTS_SUB0                              om_data0;
    TTS_SID_TTS_OM_DEM_DEC_TBCC_TTS_SUB1                              om_data1;
} TTS_SID_TTS_OM_DEM_DEC_TBCC_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_TBCC_TTS_SUB0                              om_data0;
    TTS_SID_TTS_OM_DEM_DEC_TBCC_TTS_SUB1                              om_data1;
} TTS_SID_TTS_OM_DEM_DEC_TBCC_BBP_MC;

typedef union {
    struct {
        unsigned int rs_diff_tmsi_num                                 :   4               ;    /* 3:0 */
        unsigned int rs_dec_flag                                      :   4               ;    /* 7:4 */
        unsigned int rs_zero_llr_flag                                 :   4               ;    /* 11:8 */
        unsigned int rs_flip_sym_num                                  :   4               ;    /* 15:12 */
        unsigned int rs_zero_llr_num_th                               :   4               ;    /* 19:16 */
        unsigned int reserved_0                                       :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_RS_TTS_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_RS_TTS_SUB0                                om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_RS_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_RS_TTS_SUB0                                om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_RS_BBP_MC;

typedef union {
    struct {
        unsigned int rs_rxsymb0                                       :   8               ;    /* 7:0 */
        unsigned int rs_rxsymb1                                       :   8               ;    /* 15:8 */
        unsigned int rs_rxsymb2                                       :   8               ;    /* 23:16 */
        unsigned int rs_rxsymb3                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_0_TTS_SUB0;

typedef union {
    struct {
        unsigned int rs_rxsymb4                                       :   8               ;    /* 7:0 */
        unsigned int rs_rxsymb5                                       :   8               ;    /* 15:8 */
        unsigned int rs_rxsymb6                                       :   8               ;    /* 23:16 */
        unsigned int rs_rxsymb7                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_0_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_0_TTS_SUB0                        om_data0;
    TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_0_TTS_SUB1                        om_data1;
} TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_0_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_0_TTS_SUB0                        om_data0;
    TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_0_TTS_SUB1                        om_data1;
} TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_0_BBP_MC;

typedef union {
    struct {
        unsigned int rs_rxsymb8                                       :   8               ;    /* 7:0 */
        unsigned int rs_rxsymb9                                       :   8               ;    /* 15:8 */
        unsigned int rs_rxsymb10                                      :   8               ;    /* 23:16 */
        unsigned int rs_rxsymb11                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_1_TTS_SUB0;

typedef union {
    struct {
        unsigned int rs_rxsymb12                                      :   8               ;    /* 7:0 */
        unsigned int rs_rxsymb13                                      :   8               ;    /* 15:8 */
        unsigned int rs_rxsymb14                                      :   8               ;    /* 23:16 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_1_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_1_TTS_SUB0                        om_data0;
    TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_1_TTS_SUB1                        om_data1;
} TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_1_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_1_TTS_SUB0                        om_data0;
    TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_1_TTS_SUB1                        om_data1;
} TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_1_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rs_rxsymb_llr0;
    unsigned int                                                      rs_rxsymb_llr1;
} TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_LLR_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rs_rxsymb_llr0;
    unsigned int                                                      rs_rxsymb_llr1;
} TTS_SID_TTS_OM_DEM_DEC_RS_RXSYM_LLR_BBP_MC;

typedef union {
    struct {
        unsigned int reserved_0                                       :   4               ;    /* 3:0 */
        unsigned int turbo_actual_itr_num                             :   8               ;    /* 11:4 */
        unsigned int turbo_early_stop_succ_num                        :   4               ;    /* 15:12 */
        unsigned int turbo_early_stop_start_iter                      :   8               ;    /* 23:16 */
        unsigned int turbo_max_itr_tms                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_TRB_TTS_SUB0;

typedef union {
    struct {
        unsigned int turbo_channel_type                               :   8               ;    /* 7:0 */
        unsigned int turbo_early_stop_flag                            :   1               ;    /* 8 */
        unsigned int reserved_0                                       :   23              ;    /* 31:9 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_TRB_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_TRB_TTS_SUB0                               om_data0;
    TTS_SID_TTS_OM_DEM_DEC_TRB_TTS_SUB1                               om_data1;
} TTS_SID_TTS_OM_DEM_DEC_TRB_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_TRB_TTS_SUB0                               om_data0;
    TTS_SID_TTS_OM_DEM_DEC_TRB_TTS_SUB1                               om_data1;
} TTS_SID_TTS_OM_DEM_DEC_TRB_BBP_MC;

typedef union {
    struct {
        unsigned int golay_zero_llr_check_flag                        :   4               ;    /* 3:0 */
        unsigned int golay_corr_check_flag                            :   4               ;    /* 7:4 */
        unsigned int golay_zero_llr_num_th                            :   8               ;    /* 15:8 */
        unsigned int golay_threshold                                  :   8               ;    /* 23:16 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_GLY_TTS_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_GLY_TTS_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_GLY_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_GLY_TTS_SUB0                               om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_GLY_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      da_corr;
    unsigned int                                                      dt_corr;
} TTS_SID_TTS_OM_DEM_DEC_DTDA_CORR_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      da_corr;
    unsigned int                                                      dt_corr;
} TTS_SID_TTS_OM_DEM_DEC_DTDA_CORR_BBP_MC;

typedef union {
    struct {
        unsigned int dem_rho                                          :   16              ;    /* 15:0 */
        unsigned int seg_num_iter2                                    :   4               ;    /* 19:16 */
        unsigned int seg_num_iter3                                    :   4               ;    /* 23:20 */
        unsigned int seg_num_iter4                                    :   4               ;    /* 27:24 */
        unsigned int seg_num_iter5                                    :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_DEMRHO_SEGNUM_UWNUM_TTS_SUB0;

typedef union {
    struct {
        unsigned int uw_num_iter2                                     :   8               ;    /* 7:0 */
        unsigned int uw_num_iter3                                     :   8               ;    /* 15:8 */
        unsigned int uw_num_iter4                                     :   8               ;    /* 23:16 */
        unsigned int uw_num_iter5                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_DEMRHO_SEGNUM_UWNUM_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_DEMRHO_SEGNUM_UWNUM_TTS_SUB0               om_data0;
    TTS_SID_TTS_OM_DEM_DEC_DEMRHO_SEGNUM_UWNUM_TTS_SUB1               om_data1;
} TTS_SID_TTS_OM_DEM_DEC_DEMRHO_SEGNUM_UWNUM_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_DEMRHO_SEGNUM_UWNUM_TTS_SUB0               om_data0;
    TTS_SID_TTS_OM_DEM_DEC_DEMRHO_SEGNUM_UWNUM_TTS_SUB1               om_data1;
} TTS_SID_TTS_OM_DEM_DEC_DEMRHO_SEGNUM_UWNUM_BBP_MC;

typedef union {
    struct {
        unsigned int uw_vld_sym65_68_iter2                            :   4               ;    /* 3:0 */
        unsigned int uw_vld_sym65_68_iter3                            :   4               ;    /* 7:4 */
        unsigned int uw_vld_sym65_68_iter4                            :   4               ;    /* 11:8 */
        unsigned int uw_vld_sym65_68_iter5                            :   4               ;    /* 15:12 */
        unsigned int che_type_bitmap                                  :   5               ;    /* 20:16 */
        unsigned int iter_mode_bitmap                                 :   5               ;    /* 25:21 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DEM_DEC_UWVLD_TTS_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_UWVLD_TTS_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_UWVLD_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_DEM_DEC_UWVLD_TTS_SUB0                             om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_UWVLD_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      function_in;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_BACH_DEM_FUNC_IN_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      function_in;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_BACH_DEM_FUNC_IN_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      function_out;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_BACH_DEM_FUNC_OUT_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      function_out;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_BACH_DEM_FUNC_OUT_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      corr_max_val;
    unsigned int                                                      corr_min_val;
} TTS_SID_TTS_OM_BACH_DEM_CORR_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      corr_max_val;
    unsigned int                                                      corr_min_val;
} TTS_SID_TTS_OM_BACH_DEM_CORR_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} TTS_SID_TTS_OM_DEM_DEC_TOP_OUT_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} TTS_SID_TTS_OM_DEM_DEC_TOP_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int bach_start_burst_idx                             :   4               ;    /* 3:0 */
        unsigned int bach_noise_sel_flag                              :   1               ;    /* 4 */
        unsigned int bach_to_set_num                                  :   4               ;    /* 8:5 */
        unsigned int bach_fo_set_num                                  :   4               ;    /* 12:9 */
        unsigned int bach_corr_mean_method                            :   1               ;    /* 13 */
        unsigned int bach_joint_burst_num                             :   3               ;    /* 16:14 */
        unsigned int reserved_0                                       :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_BACH_DEM_PARAMETERS_TTS_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_BACH_DEM_PARAMETERS_TTS_SUB0                       om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_BACH_DEM_PARAMETERS_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_BACH_DEM_PARAMETERS_TTS_SUB0                       om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_BACH_DEM_PARAMETERS_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ekab_corr;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_DTDA_CORR_EKAB_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ekab_corr;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_DEM_DEC_DTDA_CORR_EKAB_BBP_MC;

typedef union {
    struct {
        unsigned int tts_srch_ping_pang_flag                          :   1               ;    /* 0 */
        unsigned int tts_srch_init_flag                               :   1               ;    /* 1 */
        unsigned int tts_srch_rough_pnr_valid                         :   1               ;    /* 2 */
        unsigned int tts_srch_state                                   :   4               ;    /* 6:3 */
        unsigned int tts_srch_rough_slot_num                          :   9               ;    /* 15:7 */
        unsigned int tts_srch_rough_loop_cnt                          :   10              ;    /* 25:16 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_ROUGH_TRACE_IN_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_srch_fine_bgn_pad_num                        :   4               ;    /* 3:0 */
        unsigned int tts_srch_fine_end_pad_num                        :   4               ;    /* 7:4 */
        unsigned int tts_srch_rough_est_start                         :   5               ;    /* 12:8 */
        unsigned int tts_srch_fine_win_len                            :   4               ;    /* 16:13 */
        unsigned int tts_srch_fine_loop_cnt                           :   6               ;    /* 22:17 */
        unsigned int reserved_0                                       :   9               ;    /* 31:23 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_ROUGH_TRACE_IN_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_ROUGH_TRACE_IN_TTS_SUB0                          om_data0;
    TTS_SID_TTS_SRCH_ROUGH_TRACE_IN_TTS_SUB1                          om_data1;
} TTS_SID_TTS_SRCH_ROUGH_TRACE_IN_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_ROUGH_TRACE_IN_TTS_SUB0                          om_data0;
    TTS_SID_TTS_SRCH_ROUGH_TRACE_IN_TTS_SUB1                          om_data1;
} TTS_SID_TTS_SRCH_ROUGH_TRACE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int tts_srch_ping_pang_flag                          :   1               ;    /* 0 */
        unsigned int tts_srch_init_flag                               :   1               ;    /* 1 */
        unsigned int tts_srch_rough_pnr_valid                         :   1               ;    /* 2 */
        unsigned int tts_srch_state                                   :   4               ;    /* 6:3 */
        unsigned int tts_srch_rough_slot_num                          :   9               ;    /* 15:7 */
        unsigned int tts_srch_rough_loop_cnt                          :   10              ;    /* 25:16 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_ROUGH_TRACE_OUT_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_srch_fine_bgn_pad_num                        :   4               ;    /* 3:0 */
        unsigned int tts_srch_fine_end_pad_num                        :   4               ;    /* 7:4 */
        unsigned int tts_srch_rough_est_start                         :   5               ;    /* 12:8 */
        unsigned int tts_srch_fine_win_len                            :   4               ;    /* 16:13 */
        unsigned int tts_srch_fine_loop_cnt                           :   6               ;    /* 22:17 */
        unsigned int reserved_0                                       :   9               ;    /* 31:23 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_ROUGH_TRACE_OUT_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_ROUGH_TRACE_OUT_TTS_SUB0                         om_data0;
    TTS_SID_TTS_SRCH_ROUGH_TRACE_OUT_TTS_SUB1                         om_data1;
} TTS_SID_TTS_SRCH_ROUGH_TRACE_OUT_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_ROUGH_TRACE_OUT_TTS_SUB0                         om_data0;
    TTS_SID_TTS_SRCH_ROUGH_TRACE_OUT_TTS_SUB1                         om_data1;
} TTS_SID_TTS_SRCH_ROUGH_TRACE_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int tts_srch_ping_pang_flag                          :   1               ;    /* 0 */
        unsigned int tts_srch_init_flag                               :   1               ;    /* 1 */
        unsigned int tts_srch_rough_pnr_valid                         :   1               ;    /* 2 */
        unsigned int tts_srch_state                                   :   4               ;    /* 6:3 */
        unsigned int tts_srch_rough_slot_num                          :   9               ;    /* 15:7 */
        unsigned int tts_srch_rough_loop_cnt                          :   10              ;    /* 25:16 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_TRACE_IN_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_srch_fine_bgn_pad_num                        :   4               ;    /* 3:0 */
        unsigned int tts_srch_fine_end_pad_num                        :   4               ;    /* 7:4 */
        unsigned int tts_srch_rough_est_start                         :   5               ;    /* 12:8 */
        unsigned int tts_srch_fine_win_len                            :   4               ;    /* 16:13 */
        unsigned int tts_srch_fine_loop_cnt                           :   6               ;    /* 22:17 */
        unsigned int reserved_0                                       :   9               ;    /* 31:23 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_TRACE_IN_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_FINE_TRACE_IN_TTS_SUB0                           om_data0;
    TTS_SID_TTS_SRCH_FINE_TRACE_IN_TTS_SUB1                           om_data1;
} TTS_SID_TTS_SRCH_FINE_TRACE_IN_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_FINE_TRACE_IN_TTS_SUB0                           om_data0;
    TTS_SID_TTS_SRCH_FINE_TRACE_IN_TTS_SUB1                           om_data1;
} TTS_SID_TTS_SRCH_FINE_TRACE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int tts_srch_ping_pang_flag                          :   1               ;    /* 0 */
        unsigned int tts_srch_init_flag                               :   1               ;    /* 1 */
        unsigned int tts_srch_rough_pnr_valid                         :   1               ;    /* 2 */
        unsigned int tts_srch_state                                   :   4               ;    /* 6:3 */
        unsigned int tts_srch_rough_slot_num                          :   9               ;    /* 15:7 */
        unsigned int tts_srch_rough_loop_cnt                          :   10              ;    /* 25:16 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_TRACE_OUT_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_srch_fine_bgn_pad_num                        :   4               ;    /* 3:0 */
        unsigned int tts_srch_fine_end_pad_num                        :   4               ;    /* 7:4 */
        unsigned int tts_srch_rough_est_start                         :   5               ;    /* 12:8 */
        unsigned int tts_srch_fine_win_len                            :   4               ;    /* 16:13 */
        unsigned int tts_srch_fine_loop_cnt                           :   6               ;    /* 22:17 */
        unsigned int reserved_0                                       :   9               ;    /* 31:23 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_TRACE_OUT_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_FINE_TRACE_OUT_TTS_SUB0                          om_data0;
    TTS_SID_TTS_SRCH_FINE_TRACE_OUT_TTS_SUB1                          om_data1;
} TTS_SID_TTS_SRCH_FINE_TRACE_OUT_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_FINE_TRACE_OUT_TTS_SUB0                          om_data0;
    TTS_SID_TTS_SRCH_FINE_TRACE_OUT_TTS_SUB1                          om_data1;
} TTS_SID_TTS_SRCH_FINE_TRACE_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int tfs_burst_dkab_flag                              :   1               ;    /* 0 */
        unsigned int tfs_cfg_pingpang_flag                            :   1               ;    /* 1 */
        unsigned int reserved_0                                       :   30              ;    /* 31:2 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_TRACE_IN_TTS_SUB0;

typedef union {
    struct {
        unsigned int burst_type                                       :   16              ;    /* 15:0 */
        unsigned int tfs_dkab_p                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_TRACE_IN_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_T_EST_TRACE_IN_TTS_SUB0                           om_data0;
    TTS_SID_TTS_TFS_T_EST_TRACE_IN_TTS_SUB1                           om_data1;
} TTS_SID_TTS_TFS_T_EST_TRACE_IN_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_T_EST_TRACE_IN_TTS_SUB0                           om_data0;
    TTS_SID_TTS_TFS_T_EST_TRACE_IN_TTS_SUB1                           om_data1;
} TTS_SID_TTS_TFS_T_EST_TRACE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int tfs_t_est                                        :   16              ;    /* 15:0 */
        unsigned int tfs_t_est_filter                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_TRACE_OUT_TTS_SUB0;

typedef union {
    struct {
        unsigned int tfs_dkab_t_burst_cnt                             :   8               ;    /* 7:0 */
        unsigned int tfs_t_hold_flag                                  :   8               ;    /* 15:8 */
        unsigned int tfs_t_ka_hold_value                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_TRACE_OUT_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_T_EST_TRACE_OUT_TTS_SUB0                          om_data0;
    TTS_SID_TTS_TFS_T_EST_TRACE_OUT_TTS_SUB1                          om_data1;
} TTS_SID_TTS_TFS_T_EST_TRACE_OUT_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_T_EST_TRACE_OUT_TTS_SUB0                          om_data0;
    TTS_SID_TTS_TFS_T_EST_TRACE_OUT_TTS_SUB1                          om_data1;
} TTS_SID_TTS_TFS_T_EST_TRACE_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int tfs_f_init_flag                                  :   1               ;    /* 0 */
        unsigned int tts_tfs_dkab_f_burst_cnt                         :   8               ;    /* 8:1 */
        unsigned int dkab_flag                                        :   1               ;    /* 9 */
        unsigned int tts_tfs_burst_f_est_type                         :   8               ;    /* 17:10 */
        unsigned int reserved_0                                       :   14              ;    /* 31:18 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_TRACE_IN_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_tfs_f_gain_r0                                :   12              ;    /* 11:0 */
        unsigned int tts_tfs_f_gain_r1                                :   12              ;    /* 23:12 */
        unsigned int dacch_or_dtch_flag                               :   1               ;    /* 24 */
        unsigned int f_est_fst_loop_num                               :   3               ;    /* 27:25 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_TRACE_IN_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_F_EST_TRACE_IN_TTS_SUB0                           om_data0;
    TTS_SID_TTS_TFS_F_EST_TRACE_IN_TTS_SUB1                           om_data1;
} TTS_SID_TTS_TFS_F_EST_TRACE_IN_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_F_EST_TRACE_IN_TTS_SUB0                           om_data0;
    TTS_SID_TTS_TFS_F_EST_TRACE_IN_TTS_SUB1                           om_data1;
} TTS_SID_TTS_TFS_F_EST_TRACE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int tfs_f_nps                                        :   16              ;    /* 15:0 */
        unsigned int tfs_f_est                                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_TRACE_OUT_TTS_SUB0;

typedef union {
    struct {
        unsigned int tfs_f_est_filter                                 :   16              ;    /* 15:0 */
        unsigned int tfs_f_dkab_burst_comb_current_num                :   3               ;    /* 18:16 */
        unsigned int tfs_f_dkab_burst_comb_total_num                  :   3               ;    /* 21:19 */
        unsigned int tfs_t_dkab_burst_comb_current_num                :   3               ;    /* 24:22 */
        unsigned int tfs_t_dkab_burst_comb_total_num                  :   3               ;    /* 27:25 */
        unsigned int tfs_dkab_flag                                    :   1               ;    /* 28 */
        unsigned int reserved_0                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_TRACE_OUT_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_F_EST_TRACE_OUT_TTS_SUB0                          om_data0;
    TTS_SID_TTS_TFS_F_EST_TRACE_OUT_TTS_SUB1                          om_data1;
} TTS_SID_TTS_TFS_F_EST_TRACE_OUT_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_F_EST_TRACE_OUT_TTS_SUB0                          om_data0;
    TTS_SID_TTS_TFS_F_EST_TRACE_OUT_TTS_SUB1                          om_data1;
} TTS_SID_TTS_TFS_F_EST_TRACE_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_ping_pang_flag                     :   4               ;    /* 3:0 */
        unsigned int tts_fcch_cich_init_flag                          :   4               ;    /* 7:4 */
        unsigned int tts_fcch_cich_pnr_valid                          :   4               ;    /* 11:8 */
        unsigned int tts_fcch_cich_delta_flag                         :   4               ;    /* 15:12 */
        unsigned int tts_fcch_cich_state                              :   4               ;    /* 19:16 */
        unsigned int tts_fcch_cich_burst_comb_current_num             :   4               ;    /* 23:20 */
        unsigned int tts_fcch_cich_burst_comb_total_num               :   4               ;    /* 27:24 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_TRACE_IN_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_tsync                              :   24              ;    /* 23:0 */
        unsigned int tts_fcch_cich_fine_win_len                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_TRACE_IN_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_TRACE_IN_TTS_SUB0                           om_data0;
    TTS_SID_TTS_FCCH_CICH_TRACE_IN_TTS_SUB1                           om_data1;
} TTS_SID_TTS_FCCH_CICH_TRACE_IN_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_TRACE_IN_TTS_SUB0                           om_data0;
    TTS_SID_TTS_FCCH_CICH_TRACE_IN_TTS_SUB1                           om_data1;
} TTS_SID_TTS_FCCH_CICH_TRACE_IN_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_ping_pang_flag                     :   4               ;    /* 3:0 */
        unsigned int tts_fcch_cich_init_flag                          :   4               ;    /* 7:4 */
        unsigned int tts_fcch_cich_pnr_valid                          :   4               ;    /* 11:8 */
        unsigned int tts_fcch_cich_delta_flag                         :   4               ;    /* 15:12 */
        unsigned int tts_fcch_cich_state                              :   4               ;    /* 19:16 */
        unsigned int tts_fcch_cich_burst_comb_current_num             :   4               ;    /* 23:20 */
        unsigned int tts_fcch_cich_burst_comb_total_num               :   4               ;    /* 27:24 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_TRACE_OUT_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_tsync                              :   24              ;    /* 23:0 */
        unsigned int tts_fcch_cich_fine_win_len                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_TRACE_OUT_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_TRACE_OUT_TTS_SUB0                          om_data0;
    TTS_SID_TTS_FCCH_CICH_TRACE_OUT_TTS_SUB1                          om_data1;
} TTS_SID_TTS_FCCH_CICH_TRACE_OUT_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_TRACE_OUT_TTS_SUB0                          om_data0;
    TTS_SID_TTS_FCCH_CICH_TRACE_OUT_TTS_SUB1                          om_data1;
} TTS_SID_TTS_FCCH_CICH_TRACE_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int tts_enc_num                                      :   4               ;    /* 3:0 */
        unsigned int tts_enc_type_0                                   :   4               ;    /* 7:4 */
        unsigned int tts_enc_type_1                                   :   4               ;    /* 11:8 */
        unsigned int tts_enc_type_2                                   :   4               ;    /* 15:12 */
        unsigned int tts_enc_type_3                                   :   4               ;    /* 19:16 */
        unsigned int tts_mux_type                                     :   4               ;    /* 23:20 */
        unsigned int tts_burst_type                                   :   4               ;    /* 27:24 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_IN_TTS_SUB0;

typedef union {
    struct {
        unsigned int block_idx_n                                      :   6               ;    /* 5:0 */
        unsigned int block_idx_p                                      :   2               ;    /* 7:6 */
        unsigned int block_idx_sac                                    :   5               ;    /* 12:8 */
        unsigned int block_idx_dac                                    :   1               ;    /* 13:13 */
        unsigned int flag_noise_en                                    :   1               ;    /* 14:14 */
        unsigned int flag_pow_en                                      :   1               ;    /* 15:15 */
        unsigned int flag_sacch_en                                    :   1               ;    /* 16:16 */
        unsigned int flag_dacch_en                                    :   1               ;    /* 17:17 */
        unsigned int flag_dtch_en                                     :   1               ;    /* 18:18 */
        unsigned int flag_dacch_in_dtx                                :   1               ;    /* 19:19 */
        unsigned int burst_type                                       :   3               ;    /* 22:20 */
        unsigned int rate_type                                        :   2               ;    /* 24:23 */
        unsigned int reserved_0                                       :   7               ;    /* 31:25 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_IN_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_IN_TTS_SUB0                                 om_data0;
    TTS_SID_TTS_OM_UL_ENC_IN_TTS_SUB1                                 om_data1;
} TTS_SID_TTS_OM_UL_ENC_IN_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_IN_TTS_SUB0                                 om_data0;
    TTS_SID_TTS_OM_UL_ENC_IN_TTS_SUB1                                 om_data1;
} TTS_SID_TTS_OM_UL_ENC_IN_BBP_MC;

typedef union {
    struct {
        unsigned int rms_factor                                       :   13              ;    /* 12:0 */
        unsigned int reserved_0                                       :   3               ;    /* 15:13 */
        unsigned int burst_type_mod                                   :   3               ;    /* 18:16 */
        unsigned int reserved_1                                       :   1               ;    /* 19:19 */
        unsigned int slot_index                                       :   4               ;    /* 23:20 */
        unsigned int ping_pong_flag                                   :   1               ;    /* 24:24 */
        unsigned int reserved_2                                       :   3               ;    /* 27:25 */
        unsigned int ping_pong_en                                     :   1               ;    /* 28:28 */
        unsigned int reserved_3                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_MOD_IN_TTS_SUB0;

typedef union {
    struct {
        unsigned int rrc_del_head                                     :   7               ;    /* 6:0 */
        unsigned int reserved_0                                       :   1               ;    /* 7:7 */
        unsigned int cfr_thres                                        :   13              ;    /* 20:8 */
        unsigned int reserved_1                                       :   2               ;    /* 22:21 */
        unsigned int cfr_bypass                                       :   1               ;    /* 23:23 */
        unsigned int win_len                                          :   6               ;    /* 29:24 */
        unsigned int reserved_2                                       :   1               ;    /* 30:30 */
        unsigned int win_en                                           :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_MOD_IN_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_MOD_IN_TTS_SUB0                                 om_data0;
    TTS_SID_TTS_OM_UL_MOD_IN_TTS_SUB1                                 om_data1;
} TTS_SID_TTS_OM_UL_MOD_IN_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_MOD_IN_TTS_SUB0                                 om_data0;
    TTS_SID_TTS_OM_UL_MOD_IN_TTS_SUB1                                 om_data1;
} TTS_SID_TTS_OM_UL_MOD_IN_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      bbp_slot_data_wr_addr;
    unsigned int                                                      fpdf_slot_data_rd_addr;
} TTS_SID_TTS_OM_UL_MOD_OUT_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      bbp_slot_data_wr_addr;
    unsigned int                                                      fpdf_slot_data_rd_addr;
} TTS_SID_TTS_OM_UL_MOD_OUT_BBP_MC;


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
} TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_0_TTS;


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
} TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_0_BBP_MC;

typedef union {
    struct {
        unsigned int burst_len                                        :   16              ;    /* 15:0 */
        unsigned int mode                                             :   4               ;    /* 19:16 */
        unsigned int rsv1_0                                           :   7               ;    /* 26:20 */
        unsigned int p                                                :   1               ;    /* 27 */
        unsigned int rsv0_1                                           :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB24;

typedef union {
    struct {
        unsigned int base_cnt_subsym                                  :   9               ;    /* 8:0 */
        unsigned int base_cnt_sym                                     :   6               ;    /* 14:9 */
        unsigned int rsv4_0                                           :   1               ;    /* 15 */
        unsigned int base_cnt_slot                                    :   6               ;    /* 21:16 */
        unsigned int rsv3_1                                           :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB25;

typedef union {
    struct {
        unsigned int sys_cnt_subsym                                   :   9               ;    /* 8:0 */
        unsigned int sys_cnt_sym                                      :   6               ;    /* 14:9 */
        unsigned int rsv6_0                                           :   1               ;    /* 15 */
        unsigned int sys_cnt_slot                                     :   6               ;    /* 21:16 */
        unsigned int rsv5_1                                           :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB26;

typedef union {
    struct {
        unsigned int sys_cnt_frm                                      :   19              ;    /* 18:0 */
        unsigned int rsv7_0                                           :   13              ;    /* 31:19 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB27;

typedef union {
    struct {
        unsigned int pkg_cnt                                          :   16              ;    /* 15:0 */
        unsigned int data_len                                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB28;

typedef union {
    struct {
        unsigned int start_base_cnt_subsym                            :   9               ;    /* 8:0 */
        unsigned int start_base_cnt_sym                               :   6               ;    /* 14:9 */
        unsigned int rsv9_0                                           :   1               ;    /* 15 */
        unsigned int start_base_cnt_slot                              :   6               ;    /* 21:16 */
        unsigned int rsv8_1                                           :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB29;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data744;
    unsigned int                                                      data745;
    unsigned int                                                      data746;
    unsigned int                                                      data747;
    unsigned int                                                      data748;
    unsigned int                                                      data749;
    unsigned int                                                      data750;
    unsigned int                                                      data751;
    unsigned int                                                      data752;
    unsigned int                                                      data753;
    unsigned int                                                      data754;
    unsigned int                                                      data755;
    unsigned int                                                      data756;
    unsigned int                                                      data757;
    unsigned int                                                      data758;
    unsigned int                                                      data759;
    unsigned int                                                      data760;
    unsigned int                                                      data761;
    unsigned int                                                      data762;
    unsigned int                                                      data763;
    unsigned int                                                      data764;
    unsigned int                                                      data765;
    unsigned int                                                      data766;
    unsigned int                                                      data767;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB24                       om_data24;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB25                       om_data25;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB26                       om_data26;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB27                       om_data27;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB28                       om_data28;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB29                       om_data29;
    unsigned int                                                      rsv10_0;
    unsigned int                                                      rsv11_1;
} TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data744;
    unsigned int                                                      data745;
    unsigned int                                                      data746;
    unsigned int                                                      data747;
    unsigned int                                                      data748;
    unsigned int                                                      data749;
    unsigned int                                                      data750;
    unsigned int                                                      data751;
    unsigned int                                                      data752;
    unsigned int                                                      data753;
    unsigned int                                                      data754;
    unsigned int                                                      data755;
    unsigned int                                                      data756;
    unsigned int                                                      data757;
    unsigned int                                                      data758;
    unsigned int                                                      data759;
    unsigned int                                                      data760;
    unsigned int                                                      data761;
    unsigned int                                                      data762;
    unsigned int                                                      data763;
    unsigned int                                                      data764;
    unsigned int                                                      data765;
    unsigned int                                                      data766;
    unsigned int                                                      data767;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB24                       om_data24;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB25                       om_data25;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB26                       om_data26;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB27                       om_data27;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB28                       om_data28;
    TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_TTS_SUB29                       om_data29;
    unsigned int                                                      rsv10_0;
    unsigned int                                                      rsv11_1;
} TTS_SID_TTS_OM_DAGC_IN_RX0_INFO_1_BBP_MC;


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
} TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_0_TTS;


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
} TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_0_BBP_MC;

typedef union {
    struct {
        unsigned int burst_len                                        :   16              ;    /* 15:0 */
        unsigned int mode                                             :   4               ;    /* 19:16 */
        unsigned int rsv1_0                                           :   7               ;    /* 26:20 */
        unsigned int p                                                :   1               ;    /* 27 */
        unsigned int rsv0_1                                           :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB24;

typedef union {
    struct {
        unsigned int base_cnt_subsym                                  :   9               ;    /* 8:0 */
        unsigned int base_cnt_sym                                     :   6               ;    /* 14:9 */
        unsigned int rsv4_0                                           :   1               ;    /* 15 */
        unsigned int base_cnt_slot                                    :   6               ;    /* 21:16 */
        unsigned int rsv3_1                                           :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB25;

typedef union {
    struct {
        unsigned int sys_cnt_subsym                                   :   9               ;    /* 8:0 */
        unsigned int sys_cnt_sym                                      :   6               ;    /* 14:9 */
        unsigned int rsv6_0                                           :   1               ;    /* 15 */
        unsigned int sys_cnt_slot                                     :   6               ;    /* 21:16 */
        unsigned int rsv5_1                                           :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB26;

typedef union {
    struct {
        unsigned int sys_cnt_frm                                      :   19              ;    /* 18:0 */
        unsigned int rsv7_0                                           :   13              ;    /* 31:19 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB27;

typedef union {
    struct {
        unsigned int pkg_cnt                                          :   16              ;    /* 15:0 */
        unsigned int data_len                                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB28;

typedef union {
    struct {
        unsigned int start_base_cnt_subsym                            :   9               ;    /* 8:0 */
        unsigned int start_base_cnt_sym                               :   6               ;    /* 14:9 */
        unsigned int rsv9_0                                           :   1               ;    /* 15 */
        unsigned int start_base_cnt_slot                              :   6               ;    /* 21:16 */
        unsigned int rsv8_1                                           :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB29;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data744;
    unsigned int                                                      data745;
    unsigned int                                                      data746;
    unsigned int                                                      data747;
    unsigned int                                                      data748;
    unsigned int                                                      data749;
    unsigned int                                                      data750;
    unsigned int                                                      data751;
    unsigned int                                                      data752;
    unsigned int                                                      data753;
    unsigned int                                                      data754;
    unsigned int                                                      data755;
    unsigned int                                                      data756;
    unsigned int                                                      data757;
    unsigned int                                                      data758;
    unsigned int                                                      data759;
    unsigned int                                                      data760;
    unsigned int                                                      data761;
    unsigned int                                                      data762;
    unsigned int                                                      data763;
    unsigned int                                                      data764;
    unsigned int                                                      data765;
    unsigned int                                                      data766;
    unsigned int                                                      data767;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB24                       om_data24;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB25                       om_data25;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB26                       om_data26;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB27                       om_data27;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB28                       om_data28;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB29                       om_data29;
    unsigned int                                                      rsv10_0;
    unsigned int                                                      rsv11_1;
} TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data744;
    unsigned int                                                      data745;
    unsigned int                                                      data746;
    unsigned int                                                      data747;
    unsigned int                                                      data748;
    unsigned int                                                      data749;
    unsigned int                                                      data750;
    unsigned int                                                      data751;
    unsigned int                                                      data752;
    unsigned int                                                      data753;
    unsigned int                                                      data754;
    unsigned int                                                      data755;
    unsigned int                                                      data756;
    unsigned int                                                      data757;
    unsigned int                                                      data758;
    unsigned int                                                      data759;
    unsigned int                                                      data760;
    unsigned int                                                      data761;
    unsigned int                                                      data762;
    unsigned int                                                      data763;
    unsigned int                                                      data764;
    unsigned int                                                      data765;
    unsigned int                                                      data766;
    unsigned int                                                      data767;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB24                       om_data24;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB25                       om_data25;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB26                       om_data26;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB27                       om_data27;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB28                       om_data28;
    TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_TTS_SUB29                       om_data29;
    unsigned int                                                      rsv10_0;
    unsigned int                                                      rsv11_1;
} TTS_SID_TTS_OM_DAGC_IN_RX1_INFO_1_BBP_MC;


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
} TTS_SID_TTS_OM_DAGC_OUT_RX0_INFO_0_TTS;


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
} TTS_SID_TTS_OM_DAGC_OUT_RX0_INFO_0_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data932;
    unsigned int                                                      data933;
    unsigned int                                                      data934;
    unsigned int                                                      data935;
    unsigned int                                                      data936;
    unsigned int                                                      data937;
    unsigned int                                                      data938;
    unsigned int                                                      data939;
    unsigned int                                                      data940;
    unsigned int                                                      data941;
    unsigned int                                                      data942;
    unsigned int                                                      data943;
    unsigned int                                                      data944;
    unsigned int                                                      data945;
    unsigned int                                                      data946;
    unsigned int                                                      data947;
    unsigned int                                                      data948;
    unsigned int                                                      data949;
    unsigned int                                                      data950;
    unsigned int                                                      data951;
    unsigned int                                                      data952;
    unsigned int                                                      data953;
    unsigned int                                                      data954;
    unsigned int                                                      data955;
    unsigned int                                                      data956;
    unsigned int                                                      data957;
    unsigned int                                                      data958;
    unsigned int                                                      data959;
    unsigned int                                                      data960;
    unsigned int                                                      data961;
    unsigned int                                                      data962;
    unsigned int                                                      data963;
} TTS_SID_TTS_OM_DAGC_OUT_RX0_INFO_1_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data932;
    unsigned int                                                      data933;
    unsigned int                                                      data934;
    unsigned int                                                      data935;
    unsigned int                                                      data936;
    unsigned int                                                      data937;
    unsigned int                                                      data938;
    unsigned int                                                      data939;
    unsigned int                                                      data940;
    unsigned int                                                      data941;
    unsigned int                                                      data942;
    unsigned int                                                      data943;
    unsigned int                                                      data944;
    unsigned int                                                      data945;
    unsigned int                                                      data946;
    unsigned int                                                      data947;
    unsigned int                                                      data948;
    unsigned int                                                      data949;
    unsigned int                                                      data950;
    unsigned int                                                      data951;
    unsigned int                                                      data952;
    unsigned int                                                      data953;
    unsigned int                                                      data954;
    unsigned int                                                      data955;
    unsigned int                                                      data956;
    unsigned int                                                      data957;
    unsigned int                                                      data958;
    unsigned int                                                      data959;
    unsigned int                                                      data960;
    unsigned int                                                      data961;
    unsigned int                                                      data962;
    unsigned int                                                      data963;
} TTS_SID_TTS_OM_DAGC_OUT_RX0_INFO_1_BBP_MC;


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
} TTS_SID_TTS_OM_DAGC_OUT_RX1_INFO_0_TTS;


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
} TTS_SID_TTS_OM_DAGC_OUT_RX1_INFO_0_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data932;
    unsigned int                                                      data933;
    unsigned int                                                      data934;
    unsigned int                                                      data935;
    unsigned int                                                      data936;
    unsigned int                                                      data937;
    unsigned int                                                      data938;
    unsigned int                                                      data939;
    unsigned int                                                      data940;
    unsigned int                                                      data941;
    unsigned int                                                      data942;
    unsigned int                                                      data943;
    unsigned int                                                      data944;
    unsigned int                                                      data945;
    unsigned int                                                      data946;
    unsigned int                                                      data947;
    unsigned int                                                      data948;
    unsigned int                                                      data949;
    unsigned int                                                      data950;
    unsigned int                                                      data951;
    unsigned int                                                      data952;
    unsigned int                                                      data953;
    unsigned int                                                      data954;
    unsigned int                                                      data955;
    unsigned int                                                      data956;
    unsigned int                                                      data957;
    unsigned int                                                      data958;
    unsigned int                                                      data959;
    unsigned int                                                      data960;
    unsigned int                                                      data961;
    unsigned int                                                      data962;
    unsigned int                                                      data963;
} TTS_SID_TTS_OM_DAGC_OUT_RX1_INFO_1_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data932;
    unsigned int                                                      data933;
    unsigned int                                                      data934;
    unsigned int                                                      data935;
    unsigned int                                                      data936;
    unsigned int                                                      data937;
    unsigned int                                                      data938;
    unsigned int                                                      data939;
    unsigned int                                                      data940;
    unsigned int                                                      data941;
    unsigned int                                                      data942;
    unsigned int                                                      data943;
    unsigned int                                                      data944;
    unsigned int                                                      data945;
    unsigned int                                                      data946;
    unsigned int                                                      data947;
    unsigned int                                                      data948;
    unsigned int                                                      data949;
    unsigned int                                                      data950;
    unsigned int                                                      data951;
    unsigned int                                                      data952;
    unsigned int                                                      data953;
    unsigned int                                                      data954;
    unsigned int                                                      data955;
    unsigned int                                                      data956;
    unsigned int                                                      data957;
    unsigned int                                                      data958;
    unsigned int                                                      data959;
    unsigned int                                                      data960;
    unsigned int                                                      data961;
    unsigned int                                                      data962;
    unsigned int                                                      data963;
} TTS_SID_TTS_OM_DAGC_OUT_RX1_INFO_1_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_srch_fpdf2ddr_fpdf_r0_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_fpdf_r1_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_fpdf_r0_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_fpdf_r1_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_ddr_r0_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_ddr_r1_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_ddr_r0_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_ddr_r1_addr;
    unsigned int                                                      tts_srch_cfg_addr;
    unsigned int                                                      tts_srch_common_buf_addr;
    unsigned int                                                      tts_srch_glb_addr;
    unsigned int                                                      srch_max_idx_up_c_1;
    unsigned int                                                      srch_max_val_up_c_1;
    unsigned int                                                      srch_max_val_up_l_1;
    unsigned int                                                      srch_max_val_up_r_1;
    unsigned int                                                      srch_max_idx_dn_c_1;
    unsigned int                                                      srch_max_val_dn_c_1;
    unsigned int                                                      srch_max_val_dn_l_1;
    unsigned int                                                      srch_max_val_dn_r_1;
    unsigned int                                                      srch_max_idx_up_c_2;
    unsigned int                                                      srch_max_val_up_c_2;
    unsigned int                                                      srch_max_val_up_l_2;
    unsigned int                                                      srch_max_val_up_r_2;
    unsigned int                                                      srch_max_idx_dn_c_2;
    unsigned int                                                      srch_max_val_dn_c_2;
    unsigned int                                                      srch_max_val_dn_l_2;
    unsigned int                                                      srch_max_val_dn_r_2;
    unsigned int                                                      srch_max_idx_up_c_3;
    unsigned int                                                      srch_max_val_up_c_3;
    unsigned int                                                      srch_max_val_up_l_3;
    unsigned int                                                      srch_max_val_up_r_3;
    unsigned int                                                      srch_max_idx_dn_c_3;
    unsigned int                                                      srch_max_val_dn_c_3;
    unsigned int                                                      srch_max_val_dn_l_3;
    unsigned int                                                      srch_max_val_dn_r_3;
    unsigned int                                                      srch_max_idx_up_c_4;
    unsigned int                                                      srch_max_val_up_c_4;
    unsigned int                                                      srch_max_val_up_l_4;
    unsigned int                                                      srch_max_val_up_r_4;
    unsigned int                                                      srch_max_idx_dn_c_4;
    unsigned int                                                      srch_max_val_dn_c_4;
    unsigned int                                                      srch_max_val_dn_l_4;
    unsigned int                                                      srch_max_val_dn_r_4;
    unsigned int                                                      reserve0_0;
} TTS_SID_TTS_SRCH_ROUGH_VM_ID0_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_srch_fpdf2ddr_fpdf_r0_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_fpdf_r1_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_fpdf_r0_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_fpdf_r1_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_ddr_r0_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_ddr_r1_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_ddr_r0_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_ddr_r1_addr;
    unsigned int                                                      tts_srch_cfg_addr;
    unsigned int                                                      tts_srch_common_buf_addr;
    unsigned int                                                      tts_srch_glb_addr;
    unsigned int                                                      srch_max_idx_up_c_1;
    unsigned int                                                      srch_max_val_up_c_1;
    unsigned int                                                      srch_max_val_up_l_1;
    unsigned int                                                      srch_max_val_up_r_1;
    unsigned int                                                      srch_max_idx_dn_c_1;
    unsigned int                                                      srch_max_val_dn_c_1;
    unsigned int                                                      srch_max_val_dn_l_1;
    unsigned int                                                      srch_max_val_dn_r_1;
    unsigned int                                                      srch_max_idx_up_c_2;
    unsigned int                                                      srch_max_val_up_c_2;
    unsigned int                                                      srch_max_val_up_l_2;
    unsigned int                                                      srch_max_val_up_r_2;
    unsigned int                                                      srch_max_idx_dn_c_2;
    unsigned int                                                      srch_max_val_dn_c_2;
    unsigned int                                                      srch_max_val_dn_l_2;
    unsigned int                                                      srch_max_val_dn_r_2;
    unsigned int                                                      srch_max_idx_up_c_3;
    unsigned int                                                      srch_max_val_up_c_3;
    unsigned int                                                      srch_max_val_up_l_3;
    unsigned int                                                      srch_max_val_up_r_3;
    unsigned int                                                      srch_max_idx_dn_c_3;
    unsigned int                                                      srch_max_val_dn_c_3;
    unsigned int                                                      srch_max_val_dn_l_3;
    unsigned int                                                      srch_max_val_dn_r_3;
    unsigned int                                                      srch_max_idx_up_c_4;
    unsigned int                                                      srch_max_val_up_c_4;
    unsigned int                                                      srch_max_val_up_l_4;
    unsigned int                                                      srch_max_val_up_r_4;
    unsigned int                                                      srch_max_idx_dn_c_4;
    unsigned int                                                      srch_max_val_dn_c_4;
    unsigned int                                                      srch_max_val_dn_l_4;
    unsigned int                                                      srch_max_val_dn_r_4;
    unsigned int                                                      reserve0_0;
} TTS_SID_TTS_SRCH_ROUGH_VM_ID0_INFO_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_srch_glb_pnr_0;
    unsigned int                                                      tts_srch_glb_pnr_1;
    unsigned int                                                      tts_srch_glb_pnr_2;
    unsigned int                                                      tts_srch_glb_pnr_3;
    unsigned int                                                      tts_srch_glb_tsync_0;
    unsigned int                                                      tts_srch_glb_tsync_1;
    unsigned int                                                      tts_srch_glb_tsync_2;
    unsigned int                                                      tts_srch_glb_tsync_3;
    unsigned int                                                      tts_srch_glb_fd_0;
    unsigned int                                                      tts_srch_glb_fd_1;
    unsigned int                                                      tts_srch_glb_fd_2;
    unsigned int                                                      tts_srch_glb_fd_3;
    unsigned int                                                      tts_srch_rough_pnr_1;
    unsigned int                                                      tts_srch_rough_tsync_1;
    unsigned int                                                      tts_srch_rough_fd_1;
    unsigned int                                                      tts_srch_rough_pnr_2;
    unsigned int                                                      tts_srch_rough_tsync_2;
    unsigned int                                                      tts_srch_rough_fd_2;
    unsigned int                                                      tts_srch_rough_pnr_3;
    unsigned int                                                      tts_srch_rough_tsync_3;
    unsigned int                                                      tts_srch_rough_fd_3;
    unsigned int                                                      tts_srch_rough_pnr_4;
    unsigned int                                                      tts_srch_rough_tsync_4;
    unsigned int                                                      tts_srch_rough_fd_4;
} TTS_SID_TTS_SRCH_ROUGH_VM_ID1_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_srch_glb_pnr_0;
    unsigned int                                                      tts_srch_glb_pnr_1;
    unsigned int                                                      tts_srch_glb_pnr_2;
    unsigned int                                                      tts_srch_glb_pnr_3;
    unsigned int                                                      tts_srch_glb_tsync_0;
    unsigned int                                                      tts_srch_glb_tsync_1;
    unsigned int                                                      tts_srch_glb_tsync_2;
    unsigned int                                                      tts_srch_glb_tsync_3;
    unsigned int                                                      tts_srch_glb_fd_0;
    unsigned int                                                      tts_srch_glb_fd_1;
    unsigned int                                                      tts_srch_glb_fd_2;
    unsigned int                                                      tts_srch_glb_fd_3;
    unsigned int                                                      tts_srch_rough_pnr_1;
    unsigned int                                                      tts_srch_rough_tsync_1;
    unsigned int                                                      tts_srch_rough_fd_1;
    unsigned int                                                      tts_srch_rough_pnr_2;
    unsigned int                                                      tts_srch_rough_tsync_2;
    unsigned int                                                      tts_srch_rough_fd_2;
    unsigned int                                                      tts_srch_rough_pnr_3;
    unsigned int                                                      tts_srch_rough_tsync_3;
    unsigned int                                                      tts_srch_rough_fd_3;
    unsigned int                                                      tts_srch_rough_pnr_4;
    unsigned int                                                      tts_srch_rough_tsync_4;
    unsigned int                                                      tts_srch_rough_fd_4;
} TTS_SID_TTS_SRCH_ROUGH_VM_ID1_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_0_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_0_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_1_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_1_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_2_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_2_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_3_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_3_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_4_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_4_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_5_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_5_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_6_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_6_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_7_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_7_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_8_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_8_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_9_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_9_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_10_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_10_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_11_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_11_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_12_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_12_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_13_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_13_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_14_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_14_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_15_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_15_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_16_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_16_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_17_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_17_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_18_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_18_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_19_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_19_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_20_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_20_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_21_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_21_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_22_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_22_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_23_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_23_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_24_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_24_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_25_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_25_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_26_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_26_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_27_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_27_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_28_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_28_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_29_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_29_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_30_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_30_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_31_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_31_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_32_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_32_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_33_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_33_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_34_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_34_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_35_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_35_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_36_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_36_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_37_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_37_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_38_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_38_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_39_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_39_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_40_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_40_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_41_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_41_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_42_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_42_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_43_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_43_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_44_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_44_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_45_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_45_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_46_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_46_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_47_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_47_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_48_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_48_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_49_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_49_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_50_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_50_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_51_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_51_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_52_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_52_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_53_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_53_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_54_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_54_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_55_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_55_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_56_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_56_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_57_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_57_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_58_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_58_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_59_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_59_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_60_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_60_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_61_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_61_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_62_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_62_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_63_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_63_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R0_ID0_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_64_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_64_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_65_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_65_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_66_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_66_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_67_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_67_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_68_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_68_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_69_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_69_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_70_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_70_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_71_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_71_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_72_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_72_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_73_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_73_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_74_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_74_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_75_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_75_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_76_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_76_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_77_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_77_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_78_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_78_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_79_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_79_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_80_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_80_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_81_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_81_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_82_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_82_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_83_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_83_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_84_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_84_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_85_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_85_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_86_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_86_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_87_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_87_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_88_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_88_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_89_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_89_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_90_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_90_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_91_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_91_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_92_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_92_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_93_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_93_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_94_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_94_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_95_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_95_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_96_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_96_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_97_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_97_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_98_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_98_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_99_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_99_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_100_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_100_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_101_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_101_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_102_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_102_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_103_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_103_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_104_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_104_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_105_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_105_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_106_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_106_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_107_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_107_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_108_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_108_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_109_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_109_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_110_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_110_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_111_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_111_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_112_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_112_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_113_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_113_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_114_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_114_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_115_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_115_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_116_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_116_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_117_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_117_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_118_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_118_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_119_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_119_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_120_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_120_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_121_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_121_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_122_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_122_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_123_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_123_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_124_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_124_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_125_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_125_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_126_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_126_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_127_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_127_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R0_ID1_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_128_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_128_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_129_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_129_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_130_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_130_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_131_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_131_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_132_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_132_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_133_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_133_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_134_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_134_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_135_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_135_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_136_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_136_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_137_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_137_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_138_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_138_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_139_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_139_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_140_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_140_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_141_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_141_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_142_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_142_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_143_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_143_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_144_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_144_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_145_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_145_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_146_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_146_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_147_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_147_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_148_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_148_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_149_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_149_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_150_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_150_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_151_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_151_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_152_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_152_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_153_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_153_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_154_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_154_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_155_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_155_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_156_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_156_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_157_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_157_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_158_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_158_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_159_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_159_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_160_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_160_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_161_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_161_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_162_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_162_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_163_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_163_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_164_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_164_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_165_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_165_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_166_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_166_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_167_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_167_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_168_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_168_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_169_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_169_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_170_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_170_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_171_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_171_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_172_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_172_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_173_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_173_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_174_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_174_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_175_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_175_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_176_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_176_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_177_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_177_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_178_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_178_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_179_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_179_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_180_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_180_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_181_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_181_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_182_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_182_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_183_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_183_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_184_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_184_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_185_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_185_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_186_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_186_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_187_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_187_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_188_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_188_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_189_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_189_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_190_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_190_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r0_191_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r0_191_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R0_ID2_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_0_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_0_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_1_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_1_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_2_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_2_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_3_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_3_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_4_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_4_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_5_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_5_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_6_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_6_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_7_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_7_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_8_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_8_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_9_re                      :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_9_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_10_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_10_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_11_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_11_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_12_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_12_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_13_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_13_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_14_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_14_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_15_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_15_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_16_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_16_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_17_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_17_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_18_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_18_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_19_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_19_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_20_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_20_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_21_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_21_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_22_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_22_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_23_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_23_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_24_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_24_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_25_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_25_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_26_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_26_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_27_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_27_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_28_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_28_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_29_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_29_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_30_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_30_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_31_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_31_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_32_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_32_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_33_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_33_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_34_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_34_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_35_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_35_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_36_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_36_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_37_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_37_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_38_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_38_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_39_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_39_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_40_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_40_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_41_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_41_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_42_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_42_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_43_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_43_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_44_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_44_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_45_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_45_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_46_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_46_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_47_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_47_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_48_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_48_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_49_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_49_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_50_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_50_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_51_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_51_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_52_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_52_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_53_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_53_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_54_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_54_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_55_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_55_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_56_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_56_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_57_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_57_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_58_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_58_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_59_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_59_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_60_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_60_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_61_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_61_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_62_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_62_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_63_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_63_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R1_ID0_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_64_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_64_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_65_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_65_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_66_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_66_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_67_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_67_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_68_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_68_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_69_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_69_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_70_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_70_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_71_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_71_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_72_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_72_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_73_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_73_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_74_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_74_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_75_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_75_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_76_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_76_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_77_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_77_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_78_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_78_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_79_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_79_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_80_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_80_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_81_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_81_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_82_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_82_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_83_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_83_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_84_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_84_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_85_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_85_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_86_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_86_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_87_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_87_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_88_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_88_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_89_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_89_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_90_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_90_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_91_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_91_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_92_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_92_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_93_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_93_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_94_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_94_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_95_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_95_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_96_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_96_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_97_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_97_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_98_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_98_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_99_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_99_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_100_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_100_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_101_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_101_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_102_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_102_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_103_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_103_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_104_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_104_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_105_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_105_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_106_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_106_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_107_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_107_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_108_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_108_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_109_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_109_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_110_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_110_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_111_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_111_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_112_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_112_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_113_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_113_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_114_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_114_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_115_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_115_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_116_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_116_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_117_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_117_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_118_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_118_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_119_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_119_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_120_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_120_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_121_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_121_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_122_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_122_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_123_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_123_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_124_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_124_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_125_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_125_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_126_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_126_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_127_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_127_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R1_ID1_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_128_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_128_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_129_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_129_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_130_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_130_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_131_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_131_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_132_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_132_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_133_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_133_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_134_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_134_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_135_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_135_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_136_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_136_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_137_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_137_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_138_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_138_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_139_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_139_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_140_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_140_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_141_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_141_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_142_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_142_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_143_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_143_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_144_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_144_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_145_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_145_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_146_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_146_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_147_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_147_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_148_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_148_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_149_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_149_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_150_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_150_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_151_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_151_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_152_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_152_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_153_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_153_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_154_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_154_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_155_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_155_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_156_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_156_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_157_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_157_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_158_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_158_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_159_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_159_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_160_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_160_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_161_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_161_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_162_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_162_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_163_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_163_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_164_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_164_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_165_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_165_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_166_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_166_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_167_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_167_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_168_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_168_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_169_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_169_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_170_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_170_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_171_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_171_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_172_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_172_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_173_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_173_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_174_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_174_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_175_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_175_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_176_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_176_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_177_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_177_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_178_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_178_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_179_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_179_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_180_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_180_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_181_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_181_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_182_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_182_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_183_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_183_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_184_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_184_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_185_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_185_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_186_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_186_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_187_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_187_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_188_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_188_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_189_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_189_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_190_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_190_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_srch_rough_data_r1_191_re                    :   16              ;    /* 15:0 */
        unsigned int tts_srch_rough_data_r1_191_img                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB0                        om_data0;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB1                        om_data1;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB2                        om_data2;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB3                        om_data3;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB4                        om_data4;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB5                        om_data5;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB6                        om_data6;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB7                        om_data7;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB8                        om_data8;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB9                        om_data9;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB10                       om_data10;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB11                       om_data11;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB12                       om_data12;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB13                       om_data13;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB14                       om_data14;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB15                       om_data15;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB16                       om_data16;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB17                       om_data17;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB18                       om_data18;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB19                       om_data19;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB20                       om_data20;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB21                       om_data21;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB22                       om_data22;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB23                       om_data23;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB24                       om_data24;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB25                       om_data25;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB26                       om_data26;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB27                       om_data27;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB28                       om_data28;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB29                       om_data29;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB30                       om_data30;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB31                       om_data31;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB32                       om_data32;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB33                       om_data33;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB34                       om_data34;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB35                       om_data35;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB36                       om_data36;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB37                       om_data37;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB38                       om_data38;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB39                       om_data39;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB40                       om_data40;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB41                       om_data41;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB42                       om_data42;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB43                       om_data43;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB44                       om_data44;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB45                       om_data45;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB46                       om_data46;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB47                       om_data47;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB48                       om_data48;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB49                       om_data49;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB50                       om_data50;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB51                       om_data51;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB52                       om_data52;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB53                       om_data53;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB54                       om_data54;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB55                       om_data55;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB56                       om_data56;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB57                       om_data57;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB58                       om_data58;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB59                       om_data59;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB60                       om_data60;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB61                       om_data61;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB62                       om_data62;
    TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_TTS_SUB63                       om_data63;
} TTS_SID_TTS_SRCH_DATA_R1_ID2_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_0_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_0_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_1_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_1_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_2_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_2_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_3_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_3_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_4_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_4_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_5_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_5_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_6_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_6_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_7_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_7_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_504_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_504_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_505_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_505_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_506_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_506_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_507_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_507_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_508_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_508_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_509_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_509_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_510_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_510_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r0_511_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r0_511_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_0_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_0_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_1_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_1_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_2_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_2_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_3_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_3_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_4_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_4_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_5_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_5_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_6_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_6_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_7_re                       :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_7_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_504_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_504_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_505_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_505_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_506_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_506_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_507_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_507_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_508_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_508_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_509_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_509_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_510_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_510_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_srch_fine_data_r1_511_re                     :   16              ;    /* 15:0 */
        unsigned int tts_srch_fine_data_r1_511_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB31;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB0                            om_data0;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB1                            om_data1;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB2                            om_data2;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB3                            om_data3;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB4                            om_data4;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB5                            om_data5;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB6                            om_data6;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB7                            om_data7;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB8                            om_data8;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB9                            om_data9;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB10                           om_data10;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB11                           om_data11;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB12                           om_data12;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB13                           om_data13;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB14                           om_data14;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB15                           om_data15;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB16                           om_data16;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB17                           om_data17;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB18                           om_data18;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB19                           om_data19;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB20                           om_data20;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB21                           om_data21;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB22                           om_data22;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB23                           om_data23;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB24                           om_data24;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB25                           om_data25;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB26                           om_data26;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB27                           om_data27;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB28                           om_data28;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB29                           om_data29;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB30                           om_data30;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB31                           om_data31;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB0                            om_data0;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB1                            om_data1;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB2                            om_data2;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB3                            om_data3;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB4                            om_data4;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB5                            om_data5;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB6                            om_data6;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB7                            om_data7;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB8                            om_data8;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB9                            om_data9;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB10                           om_data10;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB11                           om_data11;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB12                           om_data12;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB13                           om_data13;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB14                           om_data14;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB15                           om_data15;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB16                           om_data16;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB17                           om_data17;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB18                           om_data18;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB19                           om_data19;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB20                           om_data20;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB21                           om_data21;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB22                           om_data22;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB23                           om_data23;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB24                           om_data24;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB25                           om_data25;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB26                           om_data26;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB27                           om_data27;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB28                           om_data28;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB29                           om_data29;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB30                           om_data30;
    TTS_SID_TTS_SRCH_FINE_VM_INFO_TTS_SUB31                           om_data31;
} TTS_SID_TTS_SRCH_FINE_VM_INFO_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_srch_fpdf2ddr_fpdf_r0_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_fpdf_r1_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_fpdf_r0_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_fpdf_r1_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_ddr_r0_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_ddr_r1_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_ddr_r0_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_ddr_r1_addr;
    unsigned int                                                      tts_srch_cfg_addr;
    unsigned int                                                      tts_srch_common_buf_addr;
    unsigned int                                                      tts_srch_glb_addr;
    unsigned int                                                      srch_max_idx_up_c_1;
    unsigned int                                                      srch_max_val_up_c_1;
    unsigned int                                                      srch_max_val_up_l_1;
    unsigned int                                                      srch_max_val_up_r_1;
    unsigned int                                                      srch_max_idx_dn_c_1;
    unsigned int                                                      srch_max_val_dn_c_1;
    unsigned int                                                      srch_max_val_dn_l_1;
    unsigned int                                                      srch_max_val_dn_r_1;
    unsigned int                                                      srch_max_idx_up_c_2;
    unsigned int                                                      srch_max_val_up_c_2;
    unsigned int                                                      srch_max_val_up_l_2;
    unsigned int                                                      srch_max_val_up_r_2;
    unsigned int                                                      srch_max_idx_dn_c_2;
    unsigned int                                                      srch_max_val_dn_c_2;
    unsigned int                                                      srch_max_val_dn_l_2;
    unsigned int                                                      srch_max_val_dn_r_2;
    unsigned int                                                      srch_max_idx_up_c_3;
    unsigned int                                                      srch_max_val_up_c_3;
    unsigned int                                                      srch_max_val_up_l_3;
    unsigned int                                                      srch_max_val_up_r_3;
    unsigned int                                                      srch_max_idx_dn_c_3;
    unsigned int                                                      srch_max_val_dn_c_3;
    unsigned int                                                      srch_max_val_dn_l_3;
    unsigned int                                                      srch_max_val_dn_r_3;
    unsigned int                                                      srch_max_idx_up_c_4;
    unsigned int                                                      srch_max_val_up_c_4;
    unsigned int                                                      srch_max_val_up_l_4;
    unsigned int                                                      srch_max_val_up_r_4;
    unsigned int                                                      srch_max_idx_dn_c_4;
    unsigned int                                                      srch_max_val_dn_c_4;
    unsigned int                                                      srch_max_val_dn_l_4;
    unsigned int                                                      srch_max_val_dn_r_4;
    unsigned int                                                      srch_max_idx_up_c_5;
    unsigned int                                                      srch_max_val_up_c_5;
    unsigned int                                                      srch_max_val_up_l_5;
    unsigned int                                                      srch_max_val_up_r_5;
    unsigned int                                                      srch_max_idx_dn_c_5;
    unsigned int                                                      srch_max_val_dn_c_5;
    unsigned int                                                      srch_max_val_dn_l_5;
    unsigned int                                                      srch_max_val_dn_r_5;
    unsigned int                                                      reserve0_0;
} TTS_SID_TTS_SRCH_FINE_VM_ID0_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_srch_fpdf2ddr_fpdf_r0_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_fpdf_r1_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_fpdf_r0_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_fpdf_r1_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_ddr_r0_addr;
    unsigned int                                                      tts_srch_fpdf2ddr_ddr_r1_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_ddr_r0_addr;
    unsigned int                                                      tts_srch_ddr2fpdf_ddr_r1_addr;
    unsigned int                                                      tts_srch_cfg_addr;
    unsigned int                                                      tts_srch_common_buf_addr;
    unsigned int                                                      tts_srch_glb_addr;
    unsigned int                                                      srch_max_idx_up_c_1;
    unsigned int                                                      srch_max_val_up_c_1;
    unsigned int                                                      srch_max_val_up_l_1;
    unsigned int                                                      srch_max_val_up_r_1;
    unsigned int                                                      srch_max_idx_dn_c_1;
    unsigned int                                                      srch_max_val_dn_c_1;
    unsigned int                                                      srch_max_val_dn_l_1;
    unsigned int                                                      srch_max_val_dn_r_1;
    unsigned int                                                      srch_max_idx_up_c_2;
    unsigned int                                                      srch_max_val_up_c_2;
    unsigned int                                                      srch_max_val_up_l_2;
    unsigned int                                                      srch_max_val_up_r_2;
    unsigned int                                                      srch_max_idx_dn_c_2;
    unsigned int                                                      srch_max_val_dn_c_2;
    unsigned int                                                      srch_max_val_dn_l_2;
    unsigned int                                                      srch_max_val_dn_r_2;
    unsigned int                                                      srch_max_idx_up_c_3;
    unsigned int                                                      srch_max_val_up_c_3;
    unsigned int                                                      srch_max_val_up_l_3;
    unsigned int                                                      srch_max_val_up_r_3;
    unsigned int                                                      srch_max_idx_dn_c_3;
    unsigned int                                                      srch_max_val_dn_c_3;
    unsigned int                                                      srch_max_val_dn_l_3;
    unsigned int                                                      srch_max_val_dn_r_3;
    unsigned int                                                      srch_max_idx_up_c_4;
    unsigned int                                                      srch_max_val_up_c_4;
    unsigned int                                                      srch_max_val_up_l_4;
    unsigned int                                                      srch_max_val_up_r_4;
    unsigned int                                                      srch_max_idx_dn_c_4;
    unsigned int                                                      srch_max_val_dn_c_4;
    unsigned int                                                      srch_max_val_dn_l_4;
    unsigned int                                                      srch_max_val_dn_r_4;
    unsigned int                                                      srch_max_idx_up_c_5;
    unsigned int                                                      srch_max_val_up_c_5;
    unsigned int                                                      srch_max_val_up_l_5;
    unsigned int                                                      srch_max_val_up_r_5;
    unsigned int                                                      srch_max_idx_dn_c_5;
    unsigned int                                                      srch_max_val_dn_c_5;
    unsigned int                                                      srch_max_val_dn_l_5;
    unsigned int                                                      srch_max_val_dn_r_5;
    unsigned int                                                      reserve0_0;
} TTS_SID_TTS_SRCH_FINE_VM_ID0_INFO_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_srch_glb_pnr_0;
    unsigned int                                                      tts_srch_glb_pnr_1;
    unsigned int                                                      tts_srch_glb_pnr_2;
    unsigned int                                                      tts_srch_glb_pnr_3;
    unsigned int                                                      tts_srch_glb_tsync_0;
    unsigned int                                                      tts_srch_glb_tsync_1;
    unsigned int                                                      tts_srch_glb_tsync_2;
    unsigned int                                                      tts_srch_glb_tsync_3;
    unsigned int                                                      tts_srch_glb_fd_0;
    unsigned int                                                      tts_srch_glb_fd_1;
    unsigned int                                                      tts_srch_glb_fd_2;
    unsigned int                                                      tts_srch_glb_fd_3;
    unsigned int                                                      tts_srch_fine_pnr_1;
    unsigned int                                                      tts_srch_fine_tsync_1;
    unsigned int                                                      tts_srch_fine_fd_1;
    unsigned int                                                      tts_srch_fine_pnr_2;
    unsigned int                                                      tts_srch_fine_tsync_2;
    unsigned int                                                      tts_srch_fine_fd_2;
    unsigned int                                                      tts_srch_fine_pnr_3;
    unsigned int                                                      tts_srch_fine_tsync_3;
    unsigned int                                                      tts_srch_fine_fd_3;
    unsigned int                                                      tts_srch_fine_pnr_4;
    unsigned int                                                      tts_srch_fine_tsync_4;
    unsigned int                                                      tts_srch_fine_fd_4;
    unsigned int                                                      tts_srch_fine_pnr_5;
    unsigned int                                                      tts_srch_fine_tsync_5;
    unsigned int                                                      tts_srch_fine_fd_5;
    unsigned int                                                      rough_chan_est_hls_r0_0;
    unsigned int                                                      rough_chan_est_hls_r0_1;
    unsigned int                                                      rough_chan_est_hls_r0_2;
    unsigned int                                                      rough_chan_est_hls_r0_3;
    unsigned int                                                      rough_chan_est_hls_r0_4;
    unsigned int                                                      rough_chan_est_hls_r1_0;
    unsigned int                                                      rough_chan_est_hls_r1_1;
    unsigned int                                                      rough_chan_est_hls_r1_2;
    unsigned int                                                      rough_chan_est_hls_r1_3;
    unsigned int                                                      rough_chan_est_hls_r1_4;
    unsigned int                                                      fine_chan_est_hls_r0_0;
    unsigned int                                                      fine_chan_est_hls_r0_1;
    unsigned int                                                      fine_chan_est_hls_r0_2;
    unsigned int                                                      fine_chan_est_hls_r0_3;
    unsigned int                                                      fine_chan_est_hls_r0_4;
    unsigned int                                                      fine_chan_est_hls_r1_0;
    unsigned int                                                      fine_chan_est_hls_r1_1;
    unsigned int                                                      fine_chan_est_hls_r1_2;
    unsigned int                                                      fine_chan_est_hls_r1_3;
    unsigned int                                                      fine_chan_est_hls_r1_4;
    unsigned int                                                      reserve0_0;
} TTS_SID_TTS_SRCH_FINE_VM_ID1_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_srch_glb_pnr_0;
    unsigned int                                                      tts_srch_glb_pnr_1;
    unsigned int                                                      tts_srch_glb_pnr_2;
    unsigned int                                                      tts_srch_glb_pnr_3;
    unsigned int                                                      tts_srch_glb_tsync_0;
    unsigned int                                                      tts_srch_glb_tsync_1;
    unsigned int                                                      tts_srch_glb_tsync_2;
    unsigned int                                                      tts_srch_glb_tsync_3;
    unsigned int                                                      tts_srch_glb_fd_0;
    unsigned int                                                      tts_srch_glb_fd_1;
    unsigned int                                                      tts_srch_glb_fd_2;
    unsigned int                                                      tts_srch_glb_fd_3;
    unsigned int                                                      tts_srch_fine_pnr_1;
    unsigned int                                                      tts_srch_fine_tsync_1;
    unsigned int                                                      tts_srch_fine_fd_1;
    unsigned int                                                      tts_srch_fine_pnr_2;
    unsigned int                                                      tts_srch_fine_tsync_2;
    unsigned int                                                      tts_srch_fine_fd_2;
    unsigned int                                                      tts_srch_fine_pnr_3;
    unsigned int                                                      tts_srch_fine_tsync_3;
    unsigned int                                                      tts_srch_fine_fd_3;
    unsigned int                                                      tts_srch_fine_pnr_4;
    unsigned int                                                      tts_srch_fine_tsync_4;
    unsigned int                                                      tts_srch_fine_fd_4;
    unsigned int                                                      tts_srch_fine_pnr_5;
    unsigned int                                                      tts_srch_fine_tsync_5;
    unsigned int                                                      tts_srch_fine_fd_5;
    unsigned int                                                      rough_chan_est_hls_r0_0;
    unsigned int                                                      rough_chan_est_hls_r0_1;
    unsigned int                                                      rough_chan_est_hls_r0_2;
    unsigned int                                                      rough_chan_est_hls_r0_3;
    unsigned int                                                      rough_chan_est_hls_r0_4;
    unsigned int                                                      rough_chan_est_hls_r1_0;
    unsigned int                                                      rough_chan_est_hls_r1_1;
    unsigned int                                                      rough_chan_est_hls_r1_2;
    unsigned int                                                      rough_chan_est_hls_r1_3;
    unsigned int                                                      rough_chan_est_hls_r1_4;
    unsigned int                                                      fine_chan_est_hls_r0_0;
    unsigned int                                                      fine_chan_est_hls_r0_1;
    unsigned int                                                      fine_chan_est_hls_r0_2;
    unsigned int                                                      fine_chan_est_hls_r0_3;
    unsigned int                                                      fine_chan_est_hls_r0_4;
    unsigned int                                                      fine_chan_est_hls_r1_0;
    unsigned int                                                      fine_chan_est_hls_r1_1;
    unsigned int                                                      fine_chan_est_hls_r1_2;
    unsigned int                                                      fine_chan_est_hls_r1_3;
    unsigned int                                                      fine_chan_est_hls_r1_4;
    unsigned int                                                      reserve0_0;
} TTS_SID_TTS_SRCH_FINE_VM_ID1_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r0_data_elem0_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r0_data_elem0_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r0_data_elem1_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r0_data_elem1_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r0_data_elem2_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r0_data_elem2_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r0_data_elem3_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r0_data_elem3_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r0_data_elem4_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r0_data_elem4_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r0_data_elem5_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r0_data_elem5_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r0_data_elem6_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r0_data_elem6_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r0_data_elem7_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r0_data_elem7_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r1_data_elem0_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r1_data_elem0_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r1_data_elem1_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r1_data_elem1_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r1_data_elem2_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r1_data_elem2_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r1_data_elem3_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r1_data_elem3_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r1_data_elem4_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r1_data_elem4_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r1_data_elem5_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r1_data_elem5_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r1_data_elem6_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r1_data_elem6_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_tfs_t_est_r1_data_elem7_real                 :   16              ;    /* 15:0 */
        unsigned int tts_tfs_t_est_r1_data_elem7_imag                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB15;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB0                            om_data0;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB1                            om_data1;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB2                            om_data2;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB3                            om_data3;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB4                            om_data4;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB5                            om_data5;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB6                            om_data6;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB7                            om_data7;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB8                            om_data8;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB9                            om_data9;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB10                           om_data10;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB11                           om_data11;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB12                           om_data12;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB13                           om_data13;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB14                           om_data14;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB15                           om_data15;
    unsigned int                                                      tts_tfs_r0_data_sum_elem0_l;
    unsigned int                                                      tts_tfs_r0_data_sum_elem0_h;
    unsigned int                                                      tts_tfs_r0_data_sum_elem1_l;
    unsigned int                                                      tts_tfs_r0_data_sum_elem1_h;
    unsigned int                                                      tts_tfs_r0_data_sum_elem2_l;
    unsigned int                                                      tts_tfs_r0_data_sum_elem2_h;
    unsigned int                                                      tts_tfs_r0_data_sum_elem3_l;
    unsigned int                                                      tts_tfs_r0_data_sum_elem3_h;
    unsigned int                                                      tts_tfs_agc_agin_r0;
    unsigned int                                                      tts_tfs_r1_data_sum_elem0_l;
    unsigned int                                                      tts_tfs_r1_data_sum_elem0_h;
    unsigned int                                                      tts_tfs_r1_data_sum_elem1_l;
    unsigned int                                                      tts_tfs_r1_data_sum_elem1_h;
    unsigned int                                                      tts_tfs_r1_data_sum_elem2_l;
    unsigned int                                                      tts_tfs_r1_data_sum_elem2_h;
    unsigned int                                                      tts_tfs_r1_data_sum_elem3_l;
    unsigned int                                                      tts_tfs_r1_data_sum_elem3_h;
    unsigned int                                                      tts_tfs_agc_agin_r1;
    unsigned int                                                      tts_tfs_r0_shift_elem0;
    unsigned int                                                      tts_tfs_r0_shift_elem1;
    unsigned int                                                      tts_tfs_r0_shift_elem2;
    unsigned int                                                      tts_tfs_r0_shift_elem3;
    unsigned int                                                      data_shift_num_r0;
    unsigned int                                                      agc_gain_r0_tmp;
    unsigned int                                                      tts_tfs_r1_shift_elem0;
    unsigned int                                                      tts_tfs_r1_shift_elem1;
    unsigned int                                                      tts_tfs_r1_shift_elem2;
    unsigned int                                                      tts_tfs_r1_shift_elem3;
    unsigned int                                                      data_shift_num_r1;
    unsigned int                                                      agc_gain_r1_tmp;
    unsigned int                                                      tts_tfs_sum_pow_elem0;
    unsigned int                                                      tts_tfs_sum_pow_elem1;
    unsigned int                                                      tts_tfs_sum_pow_elem2;
    unsigned int                                                      tts_tfs_sum_pow_elem3;
    unsigned int                                                      gain_bit_out;
    unsigned int                                                      tts_tfs_sum_pow_tmp_elem0;
    unsigned int                                                      tts_tfs_sum_pow_tmp_elem1;
    unsigned int                                                      tts_tfs_sum_pow_tmp_elem2;
    unsigned int                                                      tts_tfs_sum_pow_tmp_elem3;
    unsigned int                                                      gain_out_burst_comb;
    unsigned int                                                      tts_tfs_sum_fft4_elem0_real;
    unsigned int                                                      tts_tfs_sum_fft4_elem0_imag;
    unsigned int                                                      tts_tfs_sum_fft4_elem1_real;
    unsigned int                                                      tts_tfs_sum_fft4_elem1_imag;
    unsigned int                                                      tts_tfs_sum_fft4_elem2_real;
    unsigned int                                                      tts_tfs_sum_fft4_elem2_imag;
    unsigned int                                                      tts_tfs_sum_fft4_elem3_real;
    unsigned int                                                      tts_tfs_sum_fft4_elem3_imag;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB0                            om_data0;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB1                            om_data1;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB2                            om_data2;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB3                            om_data3;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB4                            om_data4;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB5                            om_data5;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB6                            om_data6;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB7                            om_data7;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB8                            om_data8;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB9                            om_data9;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB10                           om_data10;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB11                           om_data11;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB12                           om_data12;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB13                           om_data13;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB14                           om_data14;
    TTS_SID_TTS_TFS_T_EST_VM_INFO_TTS_SUB15                           om_data15;
    unsigned int                                                      tts_tfs_r0_data_sum_elem0_l;
    unsigned int                                                      tts_tfs_r0_data_sum_elem0_h;
    unsigned int                                                      tts_tfs_r0_data_sum_elem1_l;
    unsigned int                                                      tts_tfs_r0_data_sum_elem1_h;
    unsigned int                                                      tts_tfs_r0_data_sum_elem2_l;
    unsigned int                                                      tts_tfs_r0_data_sum_elem2_h;
    unsigned int                                                      tts_tfs_r0_data_sum_elem3_l;
    unsigned int                                                      tts_tfs_r0_data_sum_elem3_h;
    unsigned int                                                      tts_tfs_agc_agin_r0;
    unsigned int                                                      tts_tfs_r1_data_sum_elem0_l;
    unsigned int                                                      tts_tfs_r1_data_sum_elem0_h;
    unsigned int                                                      tts_tfs_r1_data_sum_elem1_l;
    unsigned int                                                      tts_tfs_r1_data_sum_elem1_h;
    unsigned int                                                      tts_tfs_r1_data_sum_elem2_l;
    unsigned int                                                      tts_tfs_r1_data_sum_elem2_h;
    unsigned int                                                      tts_tfs_r1_data_sum_elem3_l;
    unsigned int                                                      tts_tfs_r1_data_sum_elem3_h;
    unsigned int                                                      tts_tfs_agc_agin_r1;
    unsigned int                                                      tts_tfs_r0_shift_elem0;
    unsigned int                                                      tts_tfs_r0_shift_elem1;
    unsigned int                                                      tts_tfs_r0_shift_elem2;
    unsigned int                                                      tts_tfs_r0_shift_elem3;
    unsigned int                                                      data_shift_num_r0;
    unsigned int                                                      agc_gain_r0_tmp;
    unsigned int                                                      tts_tfs_r1_shift_elem0;
    unsigned int                                                      tts_tfs_r1_shift_elem1;
    unsigned int                                                      tts_tfs_r1_shift_elem2;
    unsigned int                                                      tts_tfs_r1_shift_elem3;
    unsigned int                                                      data_shift_num_r1;
    unsigned int                                                      agc_gain_r1_tmp;
    unsigned int                                                      tts_tfs_sum_pow_elem0;
    unsigned int                                                      tts_tfs_sum_pow_elem1;
    unsigned int                                                      tts_tfs_sum_pow_elem2;
    unsigned int                                                      tts_tfs_sum_pow_elem3;
    unsigned int                                                      gain_bit_out;
    unsigned int                                                      tts_tfs_sum_pow_tmp_elem0;
    unsigned int                                                      tts_tfs_sum_pow_tmp_elem1;
    unsigned int                                                      tts_tfs_sum_pow_tmp_elem2;
    unsigned int                                                      tts_tfs_sum_pow_tmp_elem3;
    unsigned int                                                      gain_out_burst_comb;
    unsigned int                                                      tts_tfs_sum_fft4_elem0_real;
    unsigned int                                                      tts_tfs_sum_fft4_elem0_imag;
    unsigned int                                                      tts_tfs_sum_fft4_elem1_real;
    unsigned int                                                      tts_tfs_sum_fft4_elem1_imag;
    unsigned int                                                      tts_tfs_sum_fft4_elem2_real;
    unsigned int                                                      tts_tfs_sum_fft4_elem2_imag;
    unsigned int                                                      tts_tfs_sum_fft4_elem3_real;
    unsigned int                                                      tts_tfs_sum_fft4_elem3_imag;
} TTS_SID_TTS_TFS_T_EST_VM_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r0_elem0_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r0_elem0_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r0_elem1_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r0_elem1_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r0_elem2_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r0_elem2_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r0_elem3_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r0_elem3_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r0_elem4_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r0_elem4_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r0_elem5_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r0_elem5_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r0_elem6_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r0_elem6_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r0_elem7_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r0_elem7_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r0_elem0_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r0_elem0_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r0_elem1_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r0_elem1_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r0_elem2_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r0_elem2_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r0_elem3_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r0_elem3_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r0_elem4_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r0_elem4_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r0_elem5_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r0_elem5_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r0_elem6_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r0_elem6_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r0_elem7_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r0_elem7_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r0_elem0_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r0_elem0_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r0_elem1_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r0_elem1_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r0_elem2_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r0_elem2_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r0_elem3_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r0_elem3_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r0_elem4_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r0_elem4_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r0_elem5_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r0_elem5_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r0_elem6_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r0_elem6_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r0_elem7_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r0_elem7_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r1_elem0_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r1_elem0_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r1_elem1_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r1_elem1_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r1_elem2_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r1_elem2_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r1_elem3_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r1_elem3_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r1_elem4_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r1_elem4_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r1_elem5_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r1_elem5_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r1_elem6_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r1_elem6_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_tfs_uw0_data_r1_elem7_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw0_data_r1_elem7_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r1_elem0_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r1_elem0_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r1_elem1_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r1_elem1_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r1_elem2_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r1_elem2_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r1_elem3_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r1_elem3_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r1_elem4_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r1_elem4_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r1_elem5_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r1_elem5_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r1_elem6_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r1_elem6_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_tfs_uw1_data_r1_elem7_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw1_data_r1_elem7_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r1_elem0_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r1_elem0_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r1_elem1_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r1_elem1_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r1_elem2_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r1_elem2_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r1_elem3_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r1_elem3_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r1_elem4_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r1_elem4_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r1_elem5_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r1_elem5_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r1_elem6_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r1_elem6_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_tfs_uw2_data_r1_elem7_real                   :   16              ;    /* 15:0 */
        unsigned int tts_tfs_uw2_data_r1_elem7_imag                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_tfs_sum_data5_r0_real                        :   16              ;    /* 15:0 */
        unsigned int tts_tfs_sum_data5_r0_imag                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_tfs_sum_data5_r1_real                        :   16              ;    /* 15:0 */
        unsigned int tts_tfs_sum_data5_r1_imag                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_tfs_data_comb_real                           :   16              ;    /* 15:0 */
        unsigned int tts_tfs_data_comb_imag                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB52;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB0                            om_data0;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB1                            om_data1;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB2                            om_data2;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB3                            om_data3;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB4                            om_data4;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB5                            om_data5;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB6                            om_data6;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB7                            om_data7;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB8                            om_data8;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB9                            om_data9;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB10                           om_data10;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB11                           om_data11;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB12                           om_data12;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB13                           om_data13;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB14                           om_data14;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB15                           om_data15;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB16                           om_data16;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB17                           om_data17;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB18                           om_data18;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB19                           om_data19;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB20                           om_data20;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB21                           om_data21;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB22                           om_data22;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB23                           om_data23;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB24                           om_data24;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB25                           om_data25;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB26                           om_data26;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB27                           om_data27;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB28                           om_data28;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB29                           om_data29;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB30                           om_data30;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB31                           om_data31;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB32                           om_data32;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB33                           om_data33;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB34                           om_data34;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB35                           om_data35;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB36                           om_data36;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB37                           om_data37;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB38                           om_data38;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB39                           om_data39;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB40                           om_data40;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB41                           om_data41;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB42                           om_data42;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB43                           om_data43;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB44                           om_data44;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB45                           om_data45;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB46                           om_data46;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB47                           om_data47;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB48                           om_data48;
    unsigned int                                                      tts_tfs_gain_r0_out;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB50                           om_data50;
    unsigned int                                                      tts_tfs_gain_r1_out;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB52                           om_data52;
    unsigned int                                                      gain_bit_out;
    unsigned int                                                      tts_tfs_f_phase_arc_out;
    unsigned int                                                      reserve0_0;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB0                            om_data0;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB1                            om_data1;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB2                            om_data2;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB3                            om_data3;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB4                            om_data4;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB5                            om_data5;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB6                            om_data6;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB7                            om_data7;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB8                            om_data8;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB9                            om_data9;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB10                           om_data10;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB11                           om_data11;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB12                           om_data12;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB13                           om_data13;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB14                           om_data14;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB15                           om_data15;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB16                           om_data16;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB17                           om_data17;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB18                           om_data18;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB19                           om_data19;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB20                           om_data20;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB21                           om_data21;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB22                           om_data22;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB23                           om_data23;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB24                           om_data24;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB25                           om_data25;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB26                           om_data26;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB27                           om_data27;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB28                           om_data28;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB29                           om_data29;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB30                           om_data30;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB31                           om_data31;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB32                           om_data32;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB33                           om_data33;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB34                           om_data34;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB35                           om_data35;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB36                           om_data36;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB37                           om_data37;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB38                           om_data38;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB39                           om_data39;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB40                           om_data40;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB41                           om_data41;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB42                           om_data42;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB43                           om_data43;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB44                           om_data44;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB45                           om_data45;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB46                           om_data46;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB47                           om_data47;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB48                           om_data48;
    unsigned int                                                      tts_tfs_gain_r0_out;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB50                           om_data50;
    unsigned int                                                      tts_tfs_gain_r1_out;
    TTS_SID_TTS_TFS_F_EST_VM_INFO_TTS_SUB52                           om_data52;
    unsigned int                                                      gain_bit_out;
    unsigned int                                                      tts_tfs_f_phase_arc_out;
    unsigned int                                                      reserve0_0;
} TTS_SID_TTS_TFS_F_EST_VM_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int dkab_data0_r0_elem0_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r0_elem0_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int dkab_data0_r0_elem1_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r0_elem1_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int dkab_data0_r0_elem2_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r0_elem2_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int dkab_data0_r0_elem3_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r0_elem3_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int dkab_data0_r0_elem4_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r0_elem4_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int dkab_data0_r0_elem5_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r0_elem5_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int dkab_data0_r0_elem6_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r0_elem6_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int dkab_data0_r0_elem7_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r0_elem7_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int dkab_data1_r0_elem0_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r0_elem0_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int dkab_data1_r0_elem1_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r0_elem1_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int dkab_data1_r0_elem2_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r0_elem2_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int dkab_data1_r0_elem3_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r0_elem3_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int dkab_data1_r0_elem4_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r0_elem4_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int dkab_data1_r0_elem5_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r0_elem5_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int dkab_data1_r0_elem6_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r0_elem6_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int dkab_data1_r0_elem7_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r0_elem7_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int dkab_data0_r1_elem0_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r1_elem0_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int dkab_data0_r1_elem1_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r1_elem1_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int dkab_data0_r1_elem2_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r1_elem2_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int dkab_data0_r1_elem3_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r1_elem3_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int dkab_data0_r1_elem4_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r1_elem4_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int dkab_data0_r1_elem5_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r1_elem5_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int dkab_data0_r1_elem6_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r1_elem6_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int dkab_data0_r1_elem7_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data0_r1_elem7_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int dkab_data1_r1_elem0_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r1_elem0_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int dkab_data1_r1_elem1_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r1_elem1_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int dkab_data1_r1_elem2_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r1_elem2_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int dkab_data1_r1_elem3_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r1_elem3_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int dkab_data1_r1_elem4_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r1_elem4_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int dkab_data1_r1_elem5_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r1_elem5_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int dkab_data1_r1_elem6_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r1_elem6_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int dkab_data1_r1_elem7_real                         :   16              ;    /* 15:0 */
        unsigned int dkab_data1_r1_elem7_imag                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int dkab_norm_sum_r_comb_elem0_real                  :   16              ;    /* 15:0 */
        unsigned int dkab_norm_sum_r_comb_elem0_imag                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_tfs_dkab_data_comb_c16_elem0_real            :   16              ;    /* 15:0 */
        unsigned int tts_tfs_dkab_data_comb_c16_elem0_imag            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_tfs_dkab_data_comb_c16_elem1_real            :   16              ;    /* 15:0 */
        unsigned int tts_tfs_dkab_data_comb_c16_elem1_imag            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_tfs_dkab_data_comb_c16_elem2_real            :   16              ;    /* 15:0 */
        unsigned int tts_tfs_dkab_data_comb_c16_elem2_imag            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_tfs_dkab_data_comb_c16_elem3_real            :   16              ;    /* 15:0 */
        unsigned int tts_tfs_dkab_data_comb_c16_elem3_imag            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_tfs_dkab_data_comb_c16_elem4_real            :   16              ;    /* 15:0 */
        unsigned int tts_tfs_dkab_data_comb_c16_elem4_imag            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_tfs_dkab_data_comb_c16_elem5_real            :   16              ;    /* 15:0 */
        unsigned int tts_tfs_dkab_data_comb_c16_elem5_imag            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_tfs_dkab_data_comb_c16_elem6_real            :   16              ;    /* 15:0 */
        unsigned int tts_tfs_dkab_data_comb_c16_elem6_imag            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_tfs_dkab_data_comb_c16_elem7_real            :   16              ;    /* 15:0 */
        unsigned int tts_tfs_dkab_data_comb_c16_elem7_imag            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_tfs_burst_comb_last_elem0_real               :   16              ;    /* 15:0 */
        unsigned int tts_tfs_burst_comb_last_elem0_imag               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int dkab_norm_sum_burst_comb_last_elem0_real         :   16              ;    /* 15:0 */
        unsigned int dkab_norm_sum_burst_comb_last_elem0_imag         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB47;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB0                       om_data0;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB1                       om_data1;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB2                       om_data2;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB3                       om_data3;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB4                       om_data4;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB5                       om_data5;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB6                       om_data6;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB7                       om_data7;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB8                       om_data8;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB9                       om_data9;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB10                      om_data10;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB11                      om_data11;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB12                      om_data12;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB13                      om_data13;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB14                      om_data14;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB15                      om_data15;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB16                      om_data16;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB17                      om_data17;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB18                      om_data18;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB19                      om_data19;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB20                      om_data20;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB21                      om_data21;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB22                      om_data22;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB23                      om_data23;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB24                      om_data24;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB25                      om_data25;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB26                      om_data26;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB27                      om_data27;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB28                      om_data28;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB29                      om_data29;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB30                      om_data30;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB31                      om_data31;
    unsigned int                                                      tts_tfs_r0_weight;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB33                      om_data33;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB34                      om_data34;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB35                      om_data35;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB36                      om_data36;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB37                      om_data37;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB38                      om_data38;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB39                      om_data39;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB40                      om_data40;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB41                      om_data41;
    unsigned int                                                      current_dkab_burst_cnt;
    unsigned int                                                      tts_tfs_burst_comb_num;
    unsigned int                                                      tts_tfs_burst_gain_last;
    unsigned int                                                      dkab_norm_sum_gain_last;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB46                      om_data46;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB47                      om_data47;
    unsigned int                                                      tts_tfs_f_phase;
    unsigned int                                                      reserve_0;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB0                       om_data0;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB1                       om_data1;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB2                       om_data2;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB3                       om_data3;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB4                       om_data4;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB5                       om_data5;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB6                       om_data6;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB7                       om_data7;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB8                       om_data8;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB9                       om_data9;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB10                      om_data10;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB11                      om_data11;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB12                      om_data12;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB13                      om_data13;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB14                      om_data14;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB15                      om_data15;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB16                      om_data16;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB17                      om_data17;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB18                      om_data18;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB19                      om_data19;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB20                      om_data20;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB21                      om_data21;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB22                      om_data22;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB23                      om_data23;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB24                      om_data24;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB25                      om_data25;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB26                      om_data26;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB27                      om_data27;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB28                      om_data28;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB29                      om_data29;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB30                      om_data30;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB31                      om_data31;
    unsigned int                                                      tts_tfs_r0_weight;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB33                      om_data33;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB34                      om_data34;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB35                      om_data35;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB36                      om_data36;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB37                      om_data37;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB38                      om_data38;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB39                      om_data39;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB40                      om_data40;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB41                      om_data41;
    unsigned int                                                      current_dkab_burst_cnt;
    unsigned int                                                      tts_tfs_burst_comb_num;
    unsigned int                                                      tts_tfs_burst_gain_last;
    unsigned int                                                      dkab_norm_sum_gain_last;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB46                      om_data46;
    TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_TTS_SUB47                      om_data47;
    unsigned int                                                      tts_tfs_f_phase;
    unsigned int                                                      reserve_0;
} TTS_SID_TTS_TFS_F_EST_DKAB_VM_INFO_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_fcch_tfs_private_vm_p;
    unsigned int                                                      tts_fcch_tfs_backup_memory;
    unsigned int                                                      tts_srch_cfg_addr;
    unsigned int                                                      tts_srch_common_buf_addr;
    unsigned int                                                      tts_srch_glb_addr;
    unsigned int                                                      srch_max_idx_up_c_1;
    unsigned int                                                      srch_max_val_up_c_1;
    unsigned int                                                      srch_max_val_up_l_1;
    unsigned int                                                      srch_max_val_up_r_1;
    unsigned int                                                      srch_max_idx_dn_c_1;
    unsigned int                                                      srch_max_val_dn_c_1;
    unsigned int                                                      srch_max_val_dn_l_1;
    unsigned int                                                      srch_max_val_dn_r_1;
    unsigned int                                                      srch_fine_snr_thd;
    unsigned int                                                      srch_fine_pnr_thd;
    unsigned int                                                      srch_fine_max_freq_range;
    unsigned int                                                      srch_fine_pnr_noise_flag;
    unsigned int                                                      srch_fine_rx_combine_flag;
    unsigned int                                                      srch_fine_che_type;
    unsigned int                                                      srch_fine_pnr_max_num;
    unsigned int                                                      srch_fine_t_deltamax;
    unsigned int                                                      srch_fine_f_deltamax;
} TTS_SID_TTS_FCCH_CICH_VM_ID0_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_fcch_tfs_private_vm_p;
    unsigned int                                                      tts_fcch_tfs_backup_memory;
    unsigned int                                                      tts_srch_cfg_addr;
    unsigned int                                                      tts_srch_common_buf_addr;
    unsigned int                                                      tts_srch_glb_addr;
    unsigned int                                                      srch_max_idx_up_c_1;
    unsigned int                                                      srch_max_val_up_c_1;
    unsigned int                                                      srch_max_val_up_l_1;
    unsigned int                                                      srch_max_val_up_r_1;
    unsigned int                                                      srch_max_idx_dn_c_1;
    unsigned int                                                      srch_max_val_dn_c_1;
    unsigned int                                                      srch_max_val_dn_l_1;
    unsigned int                                                      srch_max_val_dn_r_1;
    unsigned int                                                      srch_fine_snr_thd;
    unsigned int                                                      srch_fine_pnr_thd;
    unsigned int                                                      srch_fine_max_freq_range;
    unsigned int                                                      srch_fine_pnr_noise_flag;
    unsigned int                                                      srch_fine_rx_combine_flag;
    unsigned int                                                      srch_fine_che_type;
    unsigned int                                                      srch_fine_pnr_max_num;
    unsigned int                                                      srch_fine_t_deltamax;
    unsigned int                                                      srch_fine_f_deltamax;
} TTS_SID_TTS_FCCH_CICH_VM_ID0_INFO_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_srch_fine_pnr_1;
    unsigned int                                                      tts_srch_fine_tsync_1;
    unsigned int                                                      tts_srch_fine_fd_1;
    unsigned int                                                      tts_srch_fine_pnr_2;
    unsigned int                                                      tts_srch_fine_tsync_2;
    unsigned int                                                      tts_srch_fine_fd_2;
    unsigned int                                                      tts_srch_fine_pnr_3;
    unsigned int                                                      tts_srch_fine_tsync_3;
    unsigned int                                                      tts_srch_fine_fd_3;
    unsigned int                                                      tts_srch_fine_pnr_4;
    unsigned int                                                      tts_srch_fine_tsync_4;
    unsigned int                                                      tts_srch_fine_fd_4;
    unsigned int                                                      tts_srch_fine_pnr_5;
    unsigned int                                                      tts_srch_fine_tsync_5;
    unsigned int                                                      tts_srch_fine_fd_5;
    unsigned int                                                      fine_chan_est_hls_r0_0;
    unsigned int                                                      fine_chan_est_hls_r0_1;
    unsigned int                                                      fine_chan_est_hls_r0_2;
    unsigned int                                                      fine_chan_est_hls_r0_3;
    unsigned int                                                      fine_chan_est_hls_r0_4;
    unsigned int                                                      fine_chan_est_hls_r1_0;
    unsigned int                                                      fine_chan_est_hls_r1_1;
    unsigned int                                                      fine_chan_est_hls_r1_2;
    unsigned int                                                      fine_chan_est_hls_r1_3;
    unsigned int                                                      fine_chan_est_hls_r1_4;
    unsigned int                                                      reserve0_0;
} TTS_SID_TTS_FCCH_CICH_VM_ID1_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      tts_srch_fine_pnr_1;
    unsigned int                                                      tts_srch_fine_tsync_1;
    unsigned int                                                      tts_srch_fine_fd_1;
    unsigned int                                                      tts_srch_fine_pnr_2;
    unsigned int                                                      tts_srch_fine_tsync_2;
    unsigned int                                                      tts_srch_fine_fd_2;
    unsigned int                                                      tts_srch_fine_pnr_3;
    unsigned int                                                      tts_srch_fine_tsync_3;
    unsigned int                                                      tts_srch_fine_fd_3;
    unsigned int                                                      tts_srch_fine_pnr_4;
    unsigned int                                                      tts_srch_fine_tsync_4;
    unsigned int                                                      tts_srch_fine_fd_4;
    unsigned int                                                      tts_srch_fine_pnr_5;
    unsigned int                                                      tts_srch_fine_tsync_5;
    unsigned int                                                      tts_srch_fine_fd_5;
    unsigned int                                                      fine_chan_est_hls_r0_0;
    unsigned int                                                      fine_chan_est_hls_r0_1;
    unsigned int                                                      fine_chan_est_hls_r0_2;
    unsigned int                                                      fine_chan_est_hls_r0_3;
    unsigned int                                                      fine_chan_est_hls_r0_4;
    unsigned int                                                      fine_chan_est_hls_r1_0;
    unsigned int                                                      fine_chan_est_hls_r1_1;
    unsigned int                                                      fine_chan_est_hls_r1_2;
    unsigned int                                                      fine_chan_est_hls_r1_3;
    unsigned int                                                      fine_chan_est_hls_r1_4;
    unsigned int                                                      reserve0_0;
} TTS_SID_TTS_FCCH_CICH_VM_ID1_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_0_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_0_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_1_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_1_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_2_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_2_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_3_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_3_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_4_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_4_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_5_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_5_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_6_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_6_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_7_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_7_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_8_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_8_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_9_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_9_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_10_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_10_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_11_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_11_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_12_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_12_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_13_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_13_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_14_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_14_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_15_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_15_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_16_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_16_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_17_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_17_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_18_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_18_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_19_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_19_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_20_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_20_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_21_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_21_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_22_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_22_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_23_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_23_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_24_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_24_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_25_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_25_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_26_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_26_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_27_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_27_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_28_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_28_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_29_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_29_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_30_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_30_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_31_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_31_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_32_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_32_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_33_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_33_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_34_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_34_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_35_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_35_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_36_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_36_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_37_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_37_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_38_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_38_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_39_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_39_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_40_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_40_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_41_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_41_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_42_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_42_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_43_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_43_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_44_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_44_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_45_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_45_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_46_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_46_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_47_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_47_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_48_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_48_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_49_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_49_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_50_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_50_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_51_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_51_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_52_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_52_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_53_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_53_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_54_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_54_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_55_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_55_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_56_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_56_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_57_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_57_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_58_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_58_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_59_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_59_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_60_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_60_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_61_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_61_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_62_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_62_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_63_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_63_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID0_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_64_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_64_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_65_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_65_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_66_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_66_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_67_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_67_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_68_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_68_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_69_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_69_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_70_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_70_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_71_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_71_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_72_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_72_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_73_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_73_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_74_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_74_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_75_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_75_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_76_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_76_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_77_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_77_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_78_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_78_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_79_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_79_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_80_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_80_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_81_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_81_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_82_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_82_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_83_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_83_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_84_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_84_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_85_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_85_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_86_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_86_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_87_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_87_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_88_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_88_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_89_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_89_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_90_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_90_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_91_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_91_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_92_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_92_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_93_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_93_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_94_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_94_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_95_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_95_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_96_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_96_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_97_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_97_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_98_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_98_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_99_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_99_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_100_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_100_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_101_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_101_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_102_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_102_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_103_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_103_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_104_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_104_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_105_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_105_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_106_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_106_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_107_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_107_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_108_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_108_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_109_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_109_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_110_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_110_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_111_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_111_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_112_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_112_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_113_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_113_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_114_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_114_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_115_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_115_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_116_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_116_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_117_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_117_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_118_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_118_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_119_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_119_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_120_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_120_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_121_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_121_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_122_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_122_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_123_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_123_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_124_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_124_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_125_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_125_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_126_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_126_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_127_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_127_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID1_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_128_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_128_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_129_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_129_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_130_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_130_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_131_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_131_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_132_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_132_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_133_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_133_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_134_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_134_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_135_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_135_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_136_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_136_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_137_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_137_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_138_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_138_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_139_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_139_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_140_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_140_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_141_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_141_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_142_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_142_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_143_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_143_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_144_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_144_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_145_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_145_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_146_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_146_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_147_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_147_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_148_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_148_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_149_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_149_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_150_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_150_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_151_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_151_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_152_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_152_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_153_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_153_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_154_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_154_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_155_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_155_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_156_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_156_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_157_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_157_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_158_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_158_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_159_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_159_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_160_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_160_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_161_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_161_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_162_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_162_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_163_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_163_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_164_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_164_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_165_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_165_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_166_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_166_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_167_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_167_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_168_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_168_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_169_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_169_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_170_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_170_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_171_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_171_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_172_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_172_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_173_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_173_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_174_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_174_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_175_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_175_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_176_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_176_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_177_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_177_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_178_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_178_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_179_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_179_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_180_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_180_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_181_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_181_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_182_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_182_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_183_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_183_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_184_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_184_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_185_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_185_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_186_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_186_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_187_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_187_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_188_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_188_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_189_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_189_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_190_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_190_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_191_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_191_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID2_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_192_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_192_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_193_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_193_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_194_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_194_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_195_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_195_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_196_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_196_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_197_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_197_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_198_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_198_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_199_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_199_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_200_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_200_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_201_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_201_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_202_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_202_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_203_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_203_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_204_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_204_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_205_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_205_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_206_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_206_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_207_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_207_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_208_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_208_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_209_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_209_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_210_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_210_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_211_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_211_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_212_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_212_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_213_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_213_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_214_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_214_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_215_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_215_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_216_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_216_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_217_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_217_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_218_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_218_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_219_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_219_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_220_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_220_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_221_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_221_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_222_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_222_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_223_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_223_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_224_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_224_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_225_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_225_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_226_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_226_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_227_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_227_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_228_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_228_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_229_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_229_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_230_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_230_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_231_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_231_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_232_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_232_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_233_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_233_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_234_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_234_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_235_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_235_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_236_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_236_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_237_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_237_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_238_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_238_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_239_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_239_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_240_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_240_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_241_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_241_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_242_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_242_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_243_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_243_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_244_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_244_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_245_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_245_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_246_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_246_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_247_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_247_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_248_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_248_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_249_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_249_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_250_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_250_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_251_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_251_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_252_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_252_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_253_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_253_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_254_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_254_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_255_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_255_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID3_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_256_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_256_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_257_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_257_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_258_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_258_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_259_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_259_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_260_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_260_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_261_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_261_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_262_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_262_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_263_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_263_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_264_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_264_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_265_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_265_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_266_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_266_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_267_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_267_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_268_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_268_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_269_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_269_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_270_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_270_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_271_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_271_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_272_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_272_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_273_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_273_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_274_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_274_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_275_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_275_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_276_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_276_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_277_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_277_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_278_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_278_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_279_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_279_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_280_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_280_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_281_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_281_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_282_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_282_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_283_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_283_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_284_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_284_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_285_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_285_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_286_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_286_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_287_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_287_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_288_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_288_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_289_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_289_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_290_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_290_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_291_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_291_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_292_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_292_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_293_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_293_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_294_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_294_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_295_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_295_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_296_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_296_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_297_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_297_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_298_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_298_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_299_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_299_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_300_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_300_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_301_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_301_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_302_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_302_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_303_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_303_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_304_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_304_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_305_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_305_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_306_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_306_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_307_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_307_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_308_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_308_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_309_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_309_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_310_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_310_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_311_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_311_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_312_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_312_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_313_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_313_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_314_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_314_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_315_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_315_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_316_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_316_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_317_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_317_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_318_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_318_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_319_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_319_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID4_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_320_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_320_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_321_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_321_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_322_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_322_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_323_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_323_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_324_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_324_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_325_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_325_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_326_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_326_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_327_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_327_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_328_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_328_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_329_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_329_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_330_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_330_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_331_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_331_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_332_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_332_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_333_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_333_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_334_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_334_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_335_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_335_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_336_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_336_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_337_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_337_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_338_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_338_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_339_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_339_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_340_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_340_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_341_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_341_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_342_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_342_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_343_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_343_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_344_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_344_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_345_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_345_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_346_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_346_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_347_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_347_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_348_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_348_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_349_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_349_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_350_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_350_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_351_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_351_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_352_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_352_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_353_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_353_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_354_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_354_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_355_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_355_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_356_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_356_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_357_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_357_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_358_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_358_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_359_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_359_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_360_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_360_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_361_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_361_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_362_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_362_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_363_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_363_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_364_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_364_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_365_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_365_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_366_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_366_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_367_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_367_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_368_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_368_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_369_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_369_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_370_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_370_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_371_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_371_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_372_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_372_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_373_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_373_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_374_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_374_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_375_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_375_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_376_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_376_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_377_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_377_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_378_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_378_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_379_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_379_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_380_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_380_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_381_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_381_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_382_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_382_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_383_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_383_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID5_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_384_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_384_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_385_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_385_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_386_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_386_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_387_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_387_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_388_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_388_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_389_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_389_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_390_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_390_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_391_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_391_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_392_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_392_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_393_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_393_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_394_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_394_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_395_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_395_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_396_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_396_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_397_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_397_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_398_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_398_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_399_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_399_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_400_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_400_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_401_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_401_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_402_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_402_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_403_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_403_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_404_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_404_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_405_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_405_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_406_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_406_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_407_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_407_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_408_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_408_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_409_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_409_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_410_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_410_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_411_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_411_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_412_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_412_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_413_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_413_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_414_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_414_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_415_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_415_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_416_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_416_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_417_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_417_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_418_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_418_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_419_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_419_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_420_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_420_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_421_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_421_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_422_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_422_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_423_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_423_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_424_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_424_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_425_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_425_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_426_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_426_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_427_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_427_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_428_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_428_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_429_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_429_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_430_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_430_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_431_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_431_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_432_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_432_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_433_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_433_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_434_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_434_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_435_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_435_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_436_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_436_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_437_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_437_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_438_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_438_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_439_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_439_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_440_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_440_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_441_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_441_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_442_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_442_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_443_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_443_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_444_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_444_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_445_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_445_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_446_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_446_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_447_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_447_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID6_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_448_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_448_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_449_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_449_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_450_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_450_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_451_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_451_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_452_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_452_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_453_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_453_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_454_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_454_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_455_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_455_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_456_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_456_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_457_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_457_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_458_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_458_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_459_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_459_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_460_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_460_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_461_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_461_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_462_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_462_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_463_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_463_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_464_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_464_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_465_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_465_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_466_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_466_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_467_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_467_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_468_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_468_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_469_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_469_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_470_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_470_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_471_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_471_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_472_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_472_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_473_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_473_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_474_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_474_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_475_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_475_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_476_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_476_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_477_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_477_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_478_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_478_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r0_479_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r0_479_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB31;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB31                  om_data31;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_TTS_SUB31                  om_data31;
} TTS_SID_TTS_FCCH_CICH_DATA_R0_ID7_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_0_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_0_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_1_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_1_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_2_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_2_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_3_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_3_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_4_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_4_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_5_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_5_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_6_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_6_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_7_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_7_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_8_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_8_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_9_re                       :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_9_img                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_10_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_10_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_11_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_11_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_12_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_12_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_13_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_13_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_14_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_14_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_15_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_15_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_16_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_16_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_17_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_17_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_18_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_18_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_19_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_19_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_20_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_20_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_21_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_21_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_22_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_22_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_23_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_23_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_24_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_24_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_25_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_25_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_26_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_26_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_27_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_27_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_28_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_28_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_29_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_29_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_30_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_30_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_31_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_31_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_32_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_32_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_33_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_33_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_34_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_34_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_35_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_35_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_36_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_36_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_37_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_37_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_38_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_38_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_39_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_39_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_40_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_40_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_41_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_41_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_42_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_42_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_43_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_43_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_44_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_44_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_45_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_45_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_46_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_46_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_47_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_47_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_48_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_48_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_49_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_49_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_50_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_50_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_51_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_51_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_52_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_52_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_53_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_53_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_54_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_54_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_55_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_55_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_56_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_56_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_57_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_57_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_58_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_58_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_59_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_59_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_60_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_60_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_61_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_61_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_62_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_62_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_63_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_63_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID0_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_64_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_64_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_65_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_65_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_66_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_66_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_67_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_67_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_68_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_68_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_69_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_69_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_70_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_70_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_71_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_71_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_72_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_72_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_73_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_73_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_74_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_74_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_75_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_75_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_76_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_76_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_77_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_77_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_78_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_78_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_79_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_79_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_80_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_80_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_81_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_81_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_82_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_82_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_83_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_83_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_84_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_84_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_85_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_85_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_86_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_86_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_87_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_87_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_88_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_88_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_89_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_89_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_90_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_90_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_91_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_91_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_92_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_92_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_93_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_93_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_94_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_94_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_95_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_95_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_96_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_96_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_97_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_97_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_98_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_98_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_99_re                      :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_99_img                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_100_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_100_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_101_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_101_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_102_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_102_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_103_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_103_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_104_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_104_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_105_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_105_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_106_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_106_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_107_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_107_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_108_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_108_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_109_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_109_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_110_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_110_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_111_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_111_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_112_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_112_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_113_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_113_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_114_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_114_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_115_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_115_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_116_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_116_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_117_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_117_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_118_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_118_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_119_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_119_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_120_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_120_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_121_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_121_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_122_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_122_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_123_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_123_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_124_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_124_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_125_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_125_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_126_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_126_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_127_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_127_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID1_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_128_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_128_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_129_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_129_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_130_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_130_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_131_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_131_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_132_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_132_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_133_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_133_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_134_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_134_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_135_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_135_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_136_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_136_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_137_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_137_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_138_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_138_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_139_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_139_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_140_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_140_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_141_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_141_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_142_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_142_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_143_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_143_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_144_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_144_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_145_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_145_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_146_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_146_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_147_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_147_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_148_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_148_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_149_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_149_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_150_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_150_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_151_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_151_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_152_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_152_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_153_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_153_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_154_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_154_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_155_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_155_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_156_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_156_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_157_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_157_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_158_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_158_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_159_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_159_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_160_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_160_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_161_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_161_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_162_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_162_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_163_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_163_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_164_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_164_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_165_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_165_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_166_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_166_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_167_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_167_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_168_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_168_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_169_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_169_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_170_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_170_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_171_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_171_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_172_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_172_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_173_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_173_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_174_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_174_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_175_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_175_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_176_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_176_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_177_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_177_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_178_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_178_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_179_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_179_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_180_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_180_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_181_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_181_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_182_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_182_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_183_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_183_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_184_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_184_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_185_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_185_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_186_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_186_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_187_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_187_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_188_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_188_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_189_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_189_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_190_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_190_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_191_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_191_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID2_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_192_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_192_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_193_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_193_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_194_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_194_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_195_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_195_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_196_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_196_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_197_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_197_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_198_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_198_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_199_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_199_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_200_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_200_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_201_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_201_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_202_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_202_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_203_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_203_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_204_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_204_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_205_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_205_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_206_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_206_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_207_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_207_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_208_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_208_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_209_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_209_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_210_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_210_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_211_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_211_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_212_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_212_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_213_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_213_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_214_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_214_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_215_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_215_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_216_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_216_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_217_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_217_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_218_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_218_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_219_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_219_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_220_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_220_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_221_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_221_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_222_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_222_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_223_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_223_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_224_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_224_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_225_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_225_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_226_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_226_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_227_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_227_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_228_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_228_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_229_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_229_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_230_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_230_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_231_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_231_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_232_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_232_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_233_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_233_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_234_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_234_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_235_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_235_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_236_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_236_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_237_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_237_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_238_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_238_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_239_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_239_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_240_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_240_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_241_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_241_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_242_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_242_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_243_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_243_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_244_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_244_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_245_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_245_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_246_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_246_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_247_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_247_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_248_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_248_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_249_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_249_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_250_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_250_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_251_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_251_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_252_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_252_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_253_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_253_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_254_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_254_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_255_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_255_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID3_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_256_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_256_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_257_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_257_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_258_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_258_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_259_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_259_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_260_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_260_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_261_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_261_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_262_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_262_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_263_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_263_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_264_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_264_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_265_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_265_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_266_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_266_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_267_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_267_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_268_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_268_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_269_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_269_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_270_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_270_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_271_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_271_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_272_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_272_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_273_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_273_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_274_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_274_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_275_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_275_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_276_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_276_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_277_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_277_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_278_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_278_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_279_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_279_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_280_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_280_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_281_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_281_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_282_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_282_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_283_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_283_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_284_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_284_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_285_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_285_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_286_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_286_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_287_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_287_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_288_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_288_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_289_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_289_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_290_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_290_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_291_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_291_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_292_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_292_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_293_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_293_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_294_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_294_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_295_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_295_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_296_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_296_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_297_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_297_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_298_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_298_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_299_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_299_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_300_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_300_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_301_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_301_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_302_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_302_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_303_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_303_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_304_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_304_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_305_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_305_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_306_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_306_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_307_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_307_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_308_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_308_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_309_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_309_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_310_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_310_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_311_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_311_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_312_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_312_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_313_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_313_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_314_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_314_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_315_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_315_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_316_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_316_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_317_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_317_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_318_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_318_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_319_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_319_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID4_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_320_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_320_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_321_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_321_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_322_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_322_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_323_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_323_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_324_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_324_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_325_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_325_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_326_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_326_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_327_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_327_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_328_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_328_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_329_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_329_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_330_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_330_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_331_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_331_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_332_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_332_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_333_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_333_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_334_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_334_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_335_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_335_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_336_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_336_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_337_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_337_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_338_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_338_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_339_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_339_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_340_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_340_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_341_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_341_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_342_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_342_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_343_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_343_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_344_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_344_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_345_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_345_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_346_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_346_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_347_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_347_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_348_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_348_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_349_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_349_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_350_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_350_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_351_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_351_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_352_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_352_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_353_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_353_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_354_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_354_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_355_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_355_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_356_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_356_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_357_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_357_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_358_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_358_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_359_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_359_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_360_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_360_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_361_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_361_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_362_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_362_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_363_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_363_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_364_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_364_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_365_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_365_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_366_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_366_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_367_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_367_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_368_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_368_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_369_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_369_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_370_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_370_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_371_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_371_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_372_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_372_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_373_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_373_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_374_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_374_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_375_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_375_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_376_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_376_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_377_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_377_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_378_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_378_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_379_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_379_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_380_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_380_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_381_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_381_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_382_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_382_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_383_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_383_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID5_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_384_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_384_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_385_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_385_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_386_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_386_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_387_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_387_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_388_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_388_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_389_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_389_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_390_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_390_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_391_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_391_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_392_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_392_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_393_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_393_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_394_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_394_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_395_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_395_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_396_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_396_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_397_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_397_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_398_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_398_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_399_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_399_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_400_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_400_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_401_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_401_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_402_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_402_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_403_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_403_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_404_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_404_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_405_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_405_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_406_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_406_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_407_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_407_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_408_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_408_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_409_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_409_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_410_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_410_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_411_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_411_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_412_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_412_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_413_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_413_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_414_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_414_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_415_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_415_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB31;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_416_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_416_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB32;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_417_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_417_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB33;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_418_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_418_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB34;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_419_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_419_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB35;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_420_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_420_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB36;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_421_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_421_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB37;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_422_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_422_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB38;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_423_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_423_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB39;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_424_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_424_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB40;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_425_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_425_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB41;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_426_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_426_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB42;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_427_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_427_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB43;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_428_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_428_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB44;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_429_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_429_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB45;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_430_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_430_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB46;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_431_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_431_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB47;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_432_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_432_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB48;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_433_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_433_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB49;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_434_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_434_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB50;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_435_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_435_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB51;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_436_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_436_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB52;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_437_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_437_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB53;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_438_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_438_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB54;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_439_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_439_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB55;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_440_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_440_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB56;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_441_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_441_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB57;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_442_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_442_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB58;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_443_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_443_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB59;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_444_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_444_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB60;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_445_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_445_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB61;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_446_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_446_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB62;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_447_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_447_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB63;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB31                  om_data31;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB32                  om_data32;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB33                  om_data33;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB34                  om_data34;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB35                  om_data35;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB36                  om_data36;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB37                  om_data37;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB38                  om_data38;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB39                  om_data39;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB40                  om_data40;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB41                  om_data41;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB42                  om_data42;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB43                  om_data43;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB44                  om_data44;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB45                  om_data45;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB46                  om_data46;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB47                  om_data47;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB48                  om_data48;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB49                  om_data49;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB50                  om_data50;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB51                  om_data51;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB52                  om_data52;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB53                  om_data53;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB54                  om_data54;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB55                  om_data55;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB56                  om_data56;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB57                  om_data57;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB58                  om_data58;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB59                  om_data59;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB60                  om_data60;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB61                  om_data61;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB62                  om_data62;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_TTS_SUB63                  om_data63;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID6_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_448_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_448_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_449_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_449_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_450_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_450_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_451_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_451_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_452_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_452_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_453_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_453_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_454_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_454_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_455_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_455_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_456_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_456_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_457_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_457_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_458_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_458_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_459_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_459_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_460_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_460_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_461_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_461_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_462_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_462_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_463_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_463_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB15;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_464_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_464_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB16;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_465_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_465_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB17;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_466_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_466_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB18;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_467_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_467_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB19;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_468_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_468_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB20;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_469_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_469_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB21;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_470_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_470_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB22;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_471_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_471_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB23;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_472_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_472_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB24;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_473_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_473_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB25;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_474_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_474_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB26;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_475_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_475_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB27;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_476_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_476_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB28;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_477_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_477_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB29;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_478_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_478_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB30;

typedef union {
    struct {
        unsigned int tts_fcch_cich_data_r1_479_re                     :   16              ;    /* 15:0 */
        unsigned int tts_fcch_cich_data_r1_479_img                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB31;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB31                  om_data31;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB0                   om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB1                   om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB2                   om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB3                   om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB4                   om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB5                   om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB6                   om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB7                   om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB8                   om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB9                   om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB10                  om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB11                  om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB12                  om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB13                  om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB14                  om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB15                  om_data15;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB16                  om_data16;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB17                  om_data17;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB18                  om_data18;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB19                  om_data19;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB20                  om_data20;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB21                  om_data21;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB22                  om_data22;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB23                  om_data23;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB24                  om_data24;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB25                  om_data25;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB26                  om_data26;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB27                  om_data27;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB28                  om_data28;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB29                  om_data29;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB30                  om_data30;
    TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_TTS_SUB31                  om_data31;
} TTS_SID_TTS_FCCH_CICH_DATA_R1_ID7_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r0_0_re                   :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r0_0_img                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r0_1_re                   :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r0_1_img                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB1;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r0_2_re                   :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r0_2_img                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB2;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r0_3_re                   :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r0_3_img                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB3;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r0_476_re                 :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r0_476_img                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB4;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r0_477_re                 :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r0_477_img                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB5;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r0_478_re                 :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r0_478_img                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB6;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r0_479_re                 :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r0_479_img                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB7;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r1_0_re                   :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r1_0_img                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB8;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r1_1_re                   :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r1_1_img                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB9;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r1_2_re                   :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r1_2_img                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB10;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r1_3_re                   :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r1_3_img                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r1_476_re                 :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r1_476_img                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB12;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r1_477_re                 :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r1_477_img                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB13;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r1_478_re                 :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r1_478_img                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB14;

typedef union {
    struct {
        unsigned int tts_fcch_tfs_cich_data_r1_479_re                 :   16              ;    /* 15:0 */
        unsigned int tts_fcch_tfs_cich_data_r1_479_img                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB15;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB0              om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB1              om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB2              om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB3              om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB4              om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB5              om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB6              om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB7              om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB8              om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB9              om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB10             om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB11             om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB12             om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB13             om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB14             om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB15             om_data15;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB0              om_data0;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB1              om_data1;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB2              om_data2;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB3              om_data3;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB4              om_data4;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB5              om_data5;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB6              om_data6;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB7              om_data7;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB8              om_data8;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB9              om_data9;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB10             om_data10;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB11             om_data11;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB12             om_data12;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB13             om_data13;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB14             om_data14;
    TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_TTS_SUB15             om_data15;
} TTS_SID_TTS_FCCH_CICH_DATA_MEASURE_ID0_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_ul_enc_type                                  :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int tts_ul_enc_crc_len                               :   8               ;    /* 15:8 */
        unsigned int tts_ul_enc_crc                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_DATA_INTLV_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_ul_enc_intlv_in10                            :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   12              ;    /* 15:4 */
        unsigned int tts_ul_enc_intlv_in_len                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_DATA_INTLV_INFO_TTS_SUB11;

typedef union {
    struct {
        unsigned int tts_ul_enc_intlv_out10                           :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   12              ;    /* 15:4 */
        unsigned int tts_ul_enc_intlv_out_len                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_DATA_INTLV_INFO_TTS_SUB22;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_DATA_INTLV_INFO_TTS_SUB0                    om_data0;
    unsigned int                                                      tts_ul_enc_intlv_in0;
    unsigned int                                                      tts_ul_enc_intlv_in1;
    unsigned int                                                      tts_ul_enc_intlv_in2;
    unsigned int                                                      tts_ul_enc_intlv_in3;
    unsigned int                                                      tts_ul_enc_intlv_in4;
    unsigned int                                                      tts_ul_enc_intlv_in5;
    unsigned int                                                      tts_ul_enc_intlv_in6;
    unsigned int                                                      tts_ul_enc_intlv_in7;
    unsigned int                                                      tts_ul_enc_intlv_in8;
    unsigned int                                                      tts_ul_enc_intlv_in9;
    TTS_SID_TTS_OM_UL_ENC_DATA_INTLV_INFO_TTS_SUB11                   om_data11;
    unsigned int                                                      tts_ul_enc_intlv_out0;
    unsigned int                                                      tts_ul_enc_intlv_out1;
    unsigned int                                                      tts_ul_enc_intlv_out2;
    unsigned int                                                      tts_ul_enc_intlv_out3;
    unsigned int                                                      tts_ul_enc_intlv_out4;
    unsigned int                                                      tts_ul_enc_intlv_out5;
    unsigned int                                                      tts_ul_enc_intlv_out6;
    unsigned int                                                      tts_ul_enc_intlv_out7;
    unsigned int                                                      tts_ul_enc_intlv_out8;
    unsigned int                                                      tts_ul_enc_intlv_out9;
    TTS_SID_TTS_OM_UL_ENC_DATA_INTLV_INFO_TTS_SUB22                   om_data22;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_UL_ENC_DATA_INTLV_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_DATA_INTLV_INFO_TTS_SUB0                    om_data0;
    unsigned int                                                      tts_ul_enc_intlv_in0;
    unsigned int                                                      tts_ul_enc_intlv_in1;
    unsigned int                                                      tts_ul_enc_intlv_in2;
    unsigned int                                                      tts_ul_enc_intlv_in3;
    unsigned int                                                      tts_ul_enc_intlv_in4;
    unsigned int                                                      tts_ul_enc_intlv_in5;
    unsigned int                                                      tts_ul_enc_intlv_in6;
    unsigned int                                                      tts_ul_enc_intlv_in7;
    unsigned int                                                      tts_ul_enc_intlv_in8;
    unsigned int                                                      tts_ul_enc_intlv_in9;
    TTS_SID_TTS_OM_UL_ENC_DATA_INTLV_INFO_TTS_SUB11                   om_data11;
    unsigned int                                                      tts_ul_enc_intlv_out0;
    unsigned int                                                      tts_ul_enc_intlv_out1;
    unsigned int                                                      tts_ul_enc_intlv_out2;
    unsigned int                                                      tts_ul_enc_intlv_out3;
    unsigned int                                                      tts_ul_enc_intlv_out4;
    unsigned int                                                      tts_ul_enc_intlv_out5;
    unsigned int                                                      tts_ul_enc_intlv_out6;
    unsigned int                                                      tts_ul_enc_intlv_out7;
    unsigned int                                                      tts_ul_enc_intlv_out8;
    unsigned int                                                      tts_ul_enc_intlv_out9;
    TTS_SID_TTS_OM_UL_ENC_DATA_INTLV_INFO_TTS_SUB22                   om_data22;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_UL_ENC_DATA_INTLV_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_ul_enc_powctrl_intlv_in                      :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_POWCTRL_INTLV_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_ul_enc_powctrl_intlv_out                     :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_POWCTRL_INTLV_INFO_TTS_SUB1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_POWCTRL_INTLV_INFO_TTS_SUB0                 om_data0;
    TTS_SID_TTS_OM_UL_ENC_POWCTRL_INTLV_INFO_TTS_SUB1                 om_data1;
} TTS_SID_TTS_OM_UL_ENC_POWCTRL_INTLV_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_POWCTRL_INTLV_INFO_TTS_SUB0                 om_data0;
    TTS_SID_TTS_OM_UL_ENC_POWCTRL_INTLV_INFO_TTS_SUB1                 om_data1;
} TTS_SID_TTS_OM_UL_ENC_POWCTRL_INTLV_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_ul_enc_type                                  :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   12              ;    /* 15:4 */
        unsigned int tts_ul_enc_scram_len                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_DATA_SCRAM_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_ul_enc_scram_out10                           :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_DATA_SCRAM_INFO_TTS_SUB11;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_DATA_SCRAM_INFO_TTS_SUB0                    om_data0;
    unsigned int                                                      tts_ul_enc_scram_out0;
    unsigned int                                                      tts_ul_enc_scram_out1;
    unsigned int                                                      tts_ul_enc_scram_out2;
    unsigned int                                                      tts_ul_enc_scram_out3;
    unsigned int                                                      tts_ul_enc_scram_out4;
    unsigned int                                                      tts_ul_enc_scram_out5;
    unsigned int                                                      tts_ul_enc_scram_out6;
    unsigned int                                                      tts_ul_enc_scram_out7;
    unsigned int                                                      tts_ul_enc_scram_out8;
    unsigned int                                                      tts_ul_enc_scram_out9;
    TTS_SID_TTS_OM_UL_ENC_DATA_SCRAM_INFO_TTS_SUB11                   om_data11;
} TTS_SID_TTS_OM_UL_ENC_DATA_SCRAM_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_DATA_SCRAM_INFO_TTS_SUB0                    om_data0;
    unsigned int                                                      tts_ul_enc_scram_out0;
    unsigned int                                                      tts_ul_enc_scram_out1;
    unsigned int                                                      tts_ul_enc_scram_out2;
    unsigned int                                                      tts_ul_enc_scram_out3;
    unsigned int                                                      tts_ul_enc_scram_out4;
    unsigned int                                                      tts_ul_enc_scram_out5;
    unsigned int                                                      tts_ul_enc_scram_out6;
    unsigned int                                                      tts_ul_enc_scram_out7;
    unsigned int                                                      tts_ul_enc_scram_out8;
    unsigned int                                                      tts_ul_enc_scram_out9;
    TTS_SID_TTS_OM_UL_ENC_DATA_SCRAM_INFO_TTS_SUB11                   om_data11;
} TTS_SID_TTS_OM_UL_ENC_DATA_SCRAM_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_ul_enc_powctrl_scram_out                     :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_POWCTRL_SCRAM_INFO_TTS_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_POWCTRL_SCRAM_INFO_TTS_SUB0                 om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_UL_ENC_POWCTRL_SCRAM_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_POWCTRL_SCRAM_INFO_TTS_SUB0                 om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_UL_ENC_POWCTRL_SCRAM_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int tts_ul_burst_type                                :   3               ;    /* 2:0 */
        unsigned int reserved_0                                       :   13              ;    /* 15:3 */
        unsigned int tts_ul_map_len                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_MAP_INFO_TTS_SUB0;

typedef union {
    struct {
        unsigned int tts_ul_enc_scram_out12                           :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_UL_ENC_MAP_INFO_TTS_SUB13;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_MAP_INFO_TTS_SUB0                           om_data0;
    unsigned int                                                      tts_ul_enc_scram_out0;
    unsigned int                                                      tts_ul_enc_scram_out1;
    unsigned int                                                      tts_ul_enc_scram_out2;
    unsigned int                                                      tts_ul_enc_scram_out3;
    unsigned int                                                      tts_ul_enc_scram_out4;
    unsigned int                                                      tts_ul_enc_scram_out5;
    unsigned int                                                      tts_ul_enc_scram_out6;
    unsigned int                                                      tts_ul_enc_scram_out7;
    unsigned int                                                      tts_ul_enc_scram_out8;
    unsigned int                                                      tts_ul_enc_scram_out9;
    unsigned int                                                      tts_ul_enc_scram_out10;
    unsigned int                                                      tts_ul_enc_scram_out11;
    TTS_SID_TTS_OM_UL_ENC_MAP_INFO_TTS_SUB13                          om_data13;
} TTS_SID_TTS_OM_UL_ENC_MAP_INFO_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_UL_ENC_MAP_INFO_TTS_SUB0                           om_data0;
    unsigned int                                                      tts_ul_enc_scram_out0;
    unsigned int                                                      tts_ul_enc_scram_out1;
    unsigned int                                                      tts_ul_enc_scram_out2;
    unsigned int                                                      tts_ul_enc_scram_out3;
    unsigned int                                                      tts_ul_enc_scram_out4;
    unsigned int                                                      tts_ul_enc_scram_out5;
    unsigned int                                                      tts_ul_enc_scram_out6;
    unsigned int                                                      tts_ul_enc_scram_out7;
    unsigned int                                                      tts_ul_enc_scram_out8;
    unsigned int                                                      tts_ul_enc_scram_out9;
    unsigned int                                                      tts_ul_enc_scram_out10;
    unsigned int                                                      tts_ul_enc_scram_out11;
    TTS_SID_TTS_OM_UL_ENC_MAP_INFO_TTS_SUB13                          om_data13;
} TTS_SID_TTS_OM_UL_ENC_MAP_INFO_BBP_MC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      iter_idx;
    unsigned int                                                      noise_inst_rx0;
    unsigned int                                                      noise_inst_rx1;
    unsigned int                                                      noise_inst_rx2;
    unsigned int                                                      noise_inst_rx3;
    unsigned int                                                      iter_snr_rx0;
    unsigned int                                                      iter_snr_rx1;
    unsigned int                                                      iter_snr_rx2;
    unsigned int                                                      iter_snr_rx3;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_DEM_PARA_EST_NOISE_ITER_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      iter_idx;
    unsigned int                                                      noise_inst_rx0;
    unsigned int                                                      noise_inst_rx1;
    unsigned int                                                      noise_inst_rx2;
    unsigned int                                                      noise_inst_rx3;
    unsigned int                                                      iter_snr_rx0;
    unsigned int                                                      iter_snr_rx1;
    unsigned int                                                      iter_snr_rx2;
    unsigned int                                                      iter_snr_rx3;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_DEM_PARA_EST_NOISE_ITER_BBP_MC;

typedef union {
    struct {
        unsigned int slot_num                                         :   16              ;    /* 15:0 */
        unsigned int cc_idx                                           :   4               ;    /* 19:16 */
        unsigned int curr_is_rx23                                     :   4               ;    /* 23:20 */
        unsigned int ddr_cnt                                          :   4               ;    /* 27:24 */
        unsigned int debug_no                                         :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} TTS_SID_TTS_OM_BBPS_FADE_WARN_TTS_SUB0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_BBPS_FADE_WARN_TTS_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_BBPS_FADE_WARN_TTS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TTS_SID_TTS_OM_BBPS_FADE_WARN_TTS_SUB0                            om_data0;
    unsigned int                                                      reserved_0;
} TTS_SID_TTS_OM_BBPS_FADE_WARN_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
