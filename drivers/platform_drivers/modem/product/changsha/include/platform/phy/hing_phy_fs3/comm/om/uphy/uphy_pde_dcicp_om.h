

#ifndef __UPHY_PDE_DCICP_OM_H__
#define __UPHY_PDE_DCICP_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rpt_dci_num;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_DCI_OVERLOAD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rpt_dci_num;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_DCI_OVERLOAD_BBP_MC;

typedef union {
    struct {
        unsigned int dl_dci_flag                                      :   16              ;    /* 15:0 */
        unsigned int ul_dci_flag                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_ULDL_SEPERATE_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_ULDL_SEPERATE_SUB0                    om_data0;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_ULDL_SEPERATE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_ULDL_SEPERATE_SUB0                    om_data0;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_ULDL_SEPERATE_BBP_MC;

typedef union {
    struct {
        unsigned int pdc_int_exit                                     :   1               ;    /* 0:0 */
        unsigned int rsv_0                                            :   31              ;    /* 31:1 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_INT_CFG_NORDY_SUB0;

typedef union {
    struct {
        unsigned int rrc_info_update                                  :   1               ;    /* 0:0 */
        unsigned int slot_cfg_done                                    :   1               ;    /* 1:1 */
        unsigned int rsv_0                                            :   30              ;    /* 31:2 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_INT_CFG_NORDY_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_INT_CFG_NORDY_SUB0                om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_INT_CFG_NORDY_SUB1                om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_INT_CFG_NORDY;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_INT_CFG_NORDY_SUB0                om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_INT_CFG_NORDY_SUB1                om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_INT_CFG_NORDY_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pdcch_slot_num;
    unsigned int                                                      pdsch_slot_num;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_INT_IND_ABN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pdcch_slot_num;
    unsigned int                                                      pdsch_slot_num;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_INT_IND_ABN_BBP_MC;

typedef union {
    struct {
        unsigned int dci_status                                       :   16              ;    /* 15:0 */
        unsigned int dl_rpt_buf_idx                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_DCI_PARSE_INFO_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      dci_parse_warn_bmp;
    DCICP_SID_DCICP_OM_TRACE_NR_DCI_PARSE_INFO_SUB1                   om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_DCI_PARSE_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      dci_parse_warn_bmp;
    DCICP_SID_DCICP_OM_TRACE_NR_DCI_PARSE_INFO_SUB1                   om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_DCI_PARSE_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rsv_0;
    unsigned int                                                      rsv_1;
} DCICP_SID_DCICP_OM_TRACE_NR_DL_DCI_OVERLOAD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rsv_0;
    unsigned int                                                      rsv_1;
} DCICP_SID_DCICP_OM_TRACE_NR_DL_DCI_OVERLOAD_BBP_MC;

typedef union {
    struct {
        unsigned int dch_dci_flag                                     :   16              ;    /* 15:0 */
        unsigned int pch_dci_flag                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PDSCH_CONFIG_SUB0;

typedef union {
    struct {
        unsigned int bch_dci_flag                                     :   16              ;    /* 15:0 */
        unsigned int rsv_0                                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PDSCH_CONFIG_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_PDSCH_CONFIG_SUB0                     om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PDSCH_CONFIG_SUB1                     om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PDSCH_CONFIG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_PDSCH_CONFIG_SUB0                     om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PDSCH_CONFIG_SUB1                     om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PDSCH_CONFIG_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   4               ;    /* 3:0 */
        unsigned int dsch_cnt                                         :   4               ;    /* 7:4 */
        unsigned int dif_ch_odd_even                                  :   1               ;    /* 8 */
        unsigned int sym_bitmap_sfi_err                               :   1               ;    /* 9 */
        unsigned int aggr_in_array                                    :   1               ;    /* 10 */
        unsigned int aggr_start_flag                                  :   1               ;    /* 11 */
        unsigned int aggr_cnt                                         :   4               ;    /* 15:12 */
        unsigned int aggr_num                                         :   4               ;    /* 19:16 */
        unsigned int dci_array_idx                                    :   4               ;    /* 23:20 */
        unsigned int reserved_0                                       :   1               ;    /* 24 */
        unsigned int sfi_err_aggr_ing_flag                            :   1               ;    /* 25 */
        unsigned int crc_ok_retrans                                   :   1               ;    /* 26 */
        unsigned int reserved_1                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_DSCH_CONFIG_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_DSCH_CONFIG_SUB0                      om_data0;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_DSCH_CONFIG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_DSCH_CONFIG_SUB0                      om_data0;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_DSCH_CONFIG_BBP_MC;

typedef union {
    struct {
        unsigned int dsch_cnt                                         :   4               ;    /* 3:0 */
        unsigned int bch_cnt                                          :   4               ;    /* 7:4 */
        unsigned int pch_cnt                                          :   4               ;    /* 11:8 */
        unsigned int dci_array_idx                                    :   4               ;    /* 15:12 */
        unsigned int reserved_0                                       :   4               ;    /* 19:16 */
        unsigned int reserved_1                                       :   1               ;    /* 20 */
        unsigned int dagc_err                                         :   1               ;    /* 21 */
        unsigned int pds_dem_en                                       :   1               ;    /* 22 */
        unsigned int dif_ch_odd_even                                  :   1               ;    /* 23 */
        unsigned int pdf_ch_idx                                       :   4               ;    /* 27:24 */
        unsigned int reserved_2                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_BCH_CONFIG_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_BCH_CONFIG_SUB0                       om_data0;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_BCH_CONFIG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_BCH_CONFIG_SUB0                       om_data0;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_BCH_CONFIG_BBP_MC;

typedef union {
    struct {
        unsigned int dsch_cnt                                         :   4               ;    /* 3:0 */
        unsigned int bch_cnt                                          :   4               ;    /* 7:4 */
        unsigned int pch_cnt                                          :   4               ;    /* 11:8 */
        unsigned int dci_array_idx                                    :   4               ;    /* 15:12 */
        unsigned int reserved_0                                       :   4               ;    /* 19:16 */
        unsigned int reserved_1                                       :   1               ;    /* 20 */
        unsigned int dagc_err                                         :   1               ;    /* 21 */
        unsigned int pds_dem_en                                       :   1               ;    /* 22 */
        unsigned int dif_ch_odd_even                                  :   1               ;    /* 23 */
        unsigned int pdf_ch_idx                                       :   4               ;    /* 27:24 */
        unsigned int reserved_2                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PCH_CONFIG_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_PCH_CONFIG_SUB0                       om_data0;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_PCH_CONFIG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_PCH_CONFIG_SUB0                       om_data0;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_PCH_CONFIG_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_RRC_CFG_NORDY;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_RRC_CFG_NORDY_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      slot_odd_even;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_SLOT_CFG_NORDY;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      slot_odd_even;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_SLOT_CFG_NORDY_BBP_MC;

typedef union {
    struct {
        unsigned int cur_schedu_pos                                   :   1               ;    /* 0 */
        unsigned int rsv_0                                            :   2               ;    /* 2:1 */
        unsigned int cfg_idx                                          :   3               ;    /* 5:3 */
        unsigned int src_cfg_idx                                      :   3               ;    /* 8:6 */
        unsigned int sdci_src_cfg_flag                                :   2               ;    /* 10:9 */
        unsigned int rrr_updata_en                                    :   1               ;    /* 11 */
        unsigned int rrr_info_updata                                  :   1               ;    /* 12 */
        unsigned int mcdci_cfg_flag                                   :   1               ;    /* 13 */
        unsigned int mcdci_scheduling_cfg_flag                        :   1               ;    /* 14 */
        unsigned int mdci_mtrp_en                                     :   1               ;    /* 15 */
        unsigned int ovb_rdy0                                         :   2               ;    /* 17:16 */
        unsigned int s0_rdy0                                          :   1               ;    /* 18 */
        unsigned int ovb_rdy1                                         :   2               ;    /* 20:19 */
        unsigned int s0_rdy1                                          :   1               ;    /* 21 */
        unsigned int reserved_1                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_INFO_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_SYM0_INFO_SUB0                        om_data0;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_SYM0_INFO_SUB0                        om_data0;
    unsigned int                                                      rsv_0;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_INFO_BBP_MC;

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
        unsigned int dci_num                                          :   5               ;    /* 16:12 */
        unsigned int corset_pool_idx                                  :   1               ;    /* 17 */
        unsigned int pdc_slot_num                                     :   7               ;    /* 24:18 */
        unsigned int pei_flag                                         :   1               ;    /* 25 */
        unsigned int reserved_0                                       :   1               ;    /* 26 */
        unsigned int src_pde_idx                                      :   1               ;    /* 27 */
        unsigned int src_cfg_idx                                      :   3               ;    /* 30:28 */
        unsigned int ccs_flag                                         :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_PROC_INFO_SUB0;

typedef union {
    struct {
        unsigned int mem_idx                                          :   5               ;    /* 4:0 */
        unsigned int tail_rpt_en                                      :   1               ;    /* 5 */
        unsigned int last_rpt_for_sym0                                :   1               ;    /* 6 */
        unsigned int mdci_mtrp_flag                                   :   1               ;    /* 7 */
        unsigned int mcdci_cfg_flag                                   :   1               ;    /* 8 */
        unsigned int scheduled_cell_list_num                          :   3               ;    /* 11:9 */
        unsigned int mcdci_c_set_idx                                  :   1               ;    /* 12 */
        unsigned int scheduling_cfg_idx                               :   3               ;    /* 15:13 */
        unsigned int ref_cfg_idx                                      :   3               ;    /* 18:16 */
        unsigned int reserved_0                                       :   8               ;    /* 26:19 */
        unsigned int mtrp_union_judge_en                              :   1               ;    /* 27 */
        unsigned int cfg_idx                                          :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_PROC_INFO_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_PROC_INFO_SUB0                    om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_PROC_INFO_SUB1                    om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_PROC_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_PROC_INFO_SUB0                    om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_PROC_INFO_SUB1                    om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_PROC_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int dci0_fake_idx                                    :   8               ;    /* 7:0 */
        unsigned int dci1_fake_idx                                    :   8               ;    /* 15:8 */
        unsigned int dci2_fake_idx                                    :   8               ;    /* 23:16 */
        unsigned int dci3_fake_idx                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE0_SUB0;

typedef union {
    struct {
        unsigned int dci4_fake_idx                                    :   8               ;    /* 7:0 */
        unsigned int dci5_fake_idx                                    :   8               ;    /* 15:8 */
        unsigned int dci6_fake_idx                                    :   8               ;    /* 23:16 */
        unsigned int dci7_fake_idx                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE0_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE0_SUB0                        om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE0_SUB1                        om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE0_SUB0                        om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE0_SUB1                        om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE0_BBP_MC;

typedef union {
    struct {
        unsigned int dci8_fake_idx                                    :   8               ;    /* 7:0 */
        unsigned int dci9_fake_idx                                    :   8               ;    /* 15:8 */
        unsigned int dci10_fake_idx                                   :   8               ;    /* 23:16 */
        unsigned int dci11_fake_idx                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE1_SUB0;

typedef union {
    struct {
        unsigned int dci12_fake_idx                                   :   8               ;    /* 7:0 */
        unsigned int dci13_fake_idx                                   :   8               ;    /* 15:8 */
        unsigned int dci14_fake_idx                                   :   8               ;    /* 23:16 */
        unsigned int dci15_fake_idx                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE1_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE1_SUB0                        om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE1_SUB1                        om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE1_SUB0                        om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE1_SUB1                        om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PRE_FAKE1_BBP_MC;

typedef union {
    struct {
        unsigned int pdf_sch_nordy                                    :   1               ;    /* 0 */
        unsigned int pds_no_work                                      :   1               ;    /* 1 */
        unsigned int tx_gt_rx                                         :   1               ;    /* 2 */
        unsigned int dagc_err                                         :   1               ;    /* 3 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_DSCH_NO_CONFIG_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_DSCH_NO_CONFIG_SUB0                   om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_DSCH_NO_CONFIG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_DSCH_NO_CONFIG_SUB0                   om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_DSCH_NO_CONFIG_BBP_MC;

typedef union {
    struct {
        unsigned int nr_schtb_r_type_rpt_pde                          :   6               ;    /* 5:0 */
        unsigned int nr_sch_tb_crc_pde                                :   1               ;    /* 6 */
        unsigned int nr_tti_harq_no_rpt_pde                           :   4               ;    /* 10:7 */
        unsigned int nr_tti_tb_ind_rpt_pde                            :   1               ;    /* 11 */
        unsigned int nr_total_warn_rpt_pde                            :   1               ;    /* 12 */
        unsigned int nr_mctrl_warn_rpt_pde                            :   1               ;    /* 13 */
        unsigned int nr_dec_warn_rpt_pde                              :   1               ;    /* 14 */
        unsigned int nr_didr_warn_rpt_pde                             :   1               ;    /* 15 */
        unsigned int nr_harq_warn_rpt_pde                             :   1               ;    /* 16 */
        unsigned int nr_cfg_abn_rpt_pde                               :   1               ;    /* 17 */
        unsigned int nr_cfg_overtime_rpt_pde                          :   1               ;    /* 18 */
        unsigned int nr_dec_overtime_rpt_pde                          :   1               ;    /* 19 */
        unsigned int nr_tb_done_abn_rpt_pde                           :   1               ;    /* 20 */
        unsigned int nr_allcbok_tberr_rpt_pde                         :   1               ;    /* 21 */
        unsigned int nr_harq_load_fail_rpt_pde                        :   1               ;    /* 22 */
        unsigned int nr_bypcb_rd_disc_rpt_pde                         :   1               ;    /* 23 */
        unsigned int nr_bypass_rpt_pde                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_SUB0;

typedef union {
    struct {
        unsigned int nr_sch_cbg_crc_rpt_pde                           :   16              ;    /* 15:0 */
        unsigned int nr_tb_ok_recfg_rpt_pde                           :   1               ;    /* 16 */
        unsigned int nr_cb_all0_ind_rpt_pde                           :   1               ;    /* 17 */
        unsigned int nr_cb_idx_abn_rpt_pde                            :   1               ;    /* 18 */
        unsigned int nr_cb_ind_abn_rpt_pde                            :   1               ;    /* 19 */
        unsigned int nr_tb_cancel_rpt_pde                             :   1               ;    /* 20 */
        unsigned int nr_cb_overflow_l2_rpt_pde                        :   1               ;    /* 21 */
        unsigned int nr_cb_overflow_harq_rpt_pde                      :   1               ;    /* 22 */
        unsigned int nr_harq_no_err_rpt_pde                           :   1               ;    /* 23 */
        unsigned int nr_tb_ind_err_rpt_pde                            :   1               ;    /* 24 */
        unsigned int nr_fddl_esc_ind_rpt_pde                          :   1               ;    /* 25 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_SUB0                          om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_SUB1                          om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_SUB0                          om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_SUB1                          om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_BBP_MC;

typedef union {
    struct {
        unsigned int mdci_mtrp_en                                     :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   2               ;    /* 2:1 */
        unsigned int cfg_idx                                          :   3               ;    /* 5:3 */
        unsigned int link_cfg_idx                                     :   3               ;    /* 8:6 */
        unsigned int tb2_cfg_idx                                      :   3               ;    /* 11:9 */
        unsigned int dsp_cfg_ddr_num                                  :   8               ;    /* 19:12 */
        unsigned int slot_odd_even                                    :   1               ;    /* 20 */
        unsigned int local_ddr_num                                    :   8               ;    /* 28:21 */
        unsigned int reserved_1                                       :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_PARA_UPD_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_SYM0_PARA_UPD_SUB0                    om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_PARA_UPD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_SYM0_PARA_UPD_SUB0                    om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_PARA_UPD_BBP_MC;

typedef union {
    struct {
        unsigned int dsp_cfg_addr_num                                 :   8               ;    /* 7:0 */
        unsigned int total_ddr_used_num                               :   8               ;    /* 15:8 */
        unsigned int odd_even_flag                                    :   1               ;    /* 16 */
        unsigned int cfg_idx                                          :   3               ;    /* 19:17 */
        unsigned int harq_rpt_num                                     :   8               ;    /* 27:20 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_HARQ_RPT_SUB0;

typedef union {
    struct {
        unsigned int dsp_cfg_addr_num1                                :   8               ;    /* 7:0 */
        unsigned int total_ddr_used_num1                              :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   1               ;    /* 16 */
        unsigned int tb2_cfg_idx                                      :   3               ;    /* 19:17 */
        unsigned int harq_rpt_num1                                    :   8               ;    /* 27:20 */
        unsigned int reserved_1                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_HARQ_RPT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_SYM0_HARQ_RPT_SUB0                    om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_SYM0_HARQ_RPT_SUB1                    om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_HARQ_RPT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_SYM0_HARQ_RPT_SUB0                    om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_SYM0_HARQ_RPT_SUB1                    om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_SYM0_HARQ_RPT_BBP_MC;

typedef union {
    struct {
        unsigned int harq_ddr_num                                     :   8               ;    /* 7:0 */
        unsigned int harq_cfg_idx                                     :   4               ;    /* 11:8 */
        unsigned int cfg_idx                                          :   4               ;    /* 15:12 */
        unsigned int ddl_int_flag                                     :   1               ;    /* 16 */
        unsigned int harq_ddr_rpt_buf_idx                             :   4               ;    /* 20:17 */
        unsigned int reserved_0                                       :   11              ;    /* 31:21 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_CFG_HARQ_RPT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_CFG_HARQ_RPT_SUB0                     om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_CFG_HARQ_RPT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_CFG_HARQ_RPT_SUB0                     om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_CFG_HARQ_RPT_BBP_MC;

typedef union {
    struct {
        unsigned int clr_cnt                                          :   2               ;    /* 1:0 */
        unsigned int cfg_idx                                          :   3               ;    /* 4:2 */
        unsigned int tb2_cfg_idx                                      :   3               ;    /* 7:5 */
        unsigned int rrc_en_clr                                       :   1               ;    /* 8 */
        unsigned int k0eq1_clr                                        :   1               ;    /* 9 */
        unsigned int reserved_0                                       :   22              ;    /* 31:10 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_CLR_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_CLR_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_CLR;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_CLR_SUB0                              om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_CLR_BBP_MC;

typedef union {
    struct {
        unsigned int pdc_end_sym_p0                                   :   16              ;    /* 15:0 */
        unsigned int pdc_end_sym_p1                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_OVB_RESULT_SUB0;

typedef union {
    struct {
        unsigned int pdc_end_sym_p2                                   :   14              ;    /* 13:0 */
        unsigned int pdc_int_exist                                    :   1               ;    /* 14 */
        unsigned int pdc_sym3_int_en                                  :   1               ;    /* 15 */
        unsigned int reserved_0                                       :   3               ;    /* 18:16 */
        unsigned int mcdci_cfg_flag                                   :   1               ;    /* 19 */
        unsigned int scheduling_cell_flag                             :   1               ;    /* 20 */
        unsigned int pdc_work_en                                      :   1               ;    /* 21 */
        unsigned int pdc_ovb_status_pool1                             :   1               ;    /* 22 */
        unsigned int mdci_mtrp_flag                                   :   1               ;    /* 23 */
        unsigned int cfg_idx                                          :   3               ;    /* 26:24 */
        unsigned int scheduling_cfg_idx                               :   3               ;    /* 29:27 */
        unsigned int reserved_1                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_OVB_RESULT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_OVB_RESULT_SUB0                   om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_OVB_RESULT_SUB1                   om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_OVB_RESULT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_OVB_RESULT_SUB0                   om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_PDC_OVB_RESULT_SUB1                   om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_OVB_RESULT_BBP_MC;

typedef union {
    struct {
        unsigned int bwp_sw_k0eq0                                     :   1               ;    /* 0 */
        unsigned int cfg_vld                                          :   1               ;    /* 1 */
        unsigned int k0eq0_crst_nodci                                 :   1               ;    /* 2 */
        unsigned int r16_intra_tdm_flag                               :   1               ;    /* 3 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_IN_ARRAY_INFO_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_IN_ARRAY_INFO_SUB0                    om_data0;
    unsigned int                                                      array_fake_type;
} DCICP_SID_DCICP_OM_TRACE_NR_IN_ARRAY_INFO;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_IN_ARRAY_INFO_SUB0                    om_data0;
    unsigned int                                                      array_fake_type;
} DCICP_SID_DCICP_OM_TRACE_NR_IN_ARRAY_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      old_tbsize;
    unsigned int                                                      new_tbsize;
} DCICP_SID_DCICP_OM_TRACE_NR_RETRANS_TBSIZE_NEQ;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      old_tbsize;
    unsigned int                                                      new_tbsize;
} DCICP_SID_DCICP_OM_TRACE_NR_RETRANS_TBSIZE_NEQ_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_SDCI_RRC_NOT_ALLVLD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_SDCI_RRC_NOT_ALLVLD_BBP_MC;

typedef union {
    struct {
        unsigned int array_fake_type                                  :   8               ;    /* 7:0 */
        unsigned int rsv_0                                            :   8               ;    /* 15:8 */
        unsigned int dci_status                                       :   8               ;    /* 23:16 */
        unsigned int single_dci_warn                                  :   1               ;    /* 24 */
        unsigned int r16_intra_tdm_flag                               :   1               ;    /* 25 */
        unsigned int reserved_1                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_PRE_SCHE_DCI_FAKE_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      dci_parse_warn_bmp;
    DCICP_SID_DCICP_OM_TRACE_NR_PRE_SCHE_DCI_FAKE_SUB1                om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PRE_SCHE_DCI_FAKE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      dci_parse_warn_bmp;
    DCICP_SID_DCICP_OM_TRACE_NR_PRE_SCHE_DCI_FAKE_SUB1                om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_PRE_SCHE_DCI_FAKE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      bba_wr_addr;
    unsigned int                                                      bba_bypass_reg;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_ONLY_CLOSE_RF;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      bba_wr_addr;
    unsigned int                                                      bba_bypass_reg;
} DCICP_SID_DCICP_OM_TRACE_NR_PDC_ONLY_CLOSE_RF_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pdc_profile;
    unsigned int                                                      task_pos;
} DCICP_SID_DCICP_OM_TRACE_NR_DVFS_PROFILE_PDC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pdc_profile;
    unsigned int                                                      task_pos;
} DCICP_SID_DCICP_OM_TRACE_NR_DVFS_PROFILE_PDC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pds_profile;
    unsigned int                                                      task_pos;
} DCICP_SID_DCICP_OM_TRACE_NR_DVFS_PROFILE_PDS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pds_profile;
    unsigned int                                                      task_pos;
} DCICP_SID_DCICP_OM_TRACE_NR_DVFS_PROFILE_PDS_BBP_MC;

typedef union {
    struct {
        unsigned int bpch_llr_comp_mode_ind_rpt_pde                   :   1               ;    /* 0 */
        unsigned int bpch_wch_discard_rpt_pde                         :   1               ;    /* 1 */
        unsigned int bpch_sib_type_rpt_pde                            :   2               ;    /* 3:2 */
        unsigned int bpch_cfg_abn_rpt_pde                             :   1               ;    /* 4 */
        unsigned int bpch_cfg_overtime_rpt_pde                        :   1               ;    /* 5 */
        unsigned int bpch_total_warn_rpt_pde                          :   1               ;    /* 6 */
        unsigned int bpch_fddl_esc_ind_pde                            :   1               ;    /* 7 */
        unsigned int bpch_cap_data_len_rpt_pde                        :   15              ;    /* 22:8 */
        unsigned int bpch_tb_crc_rpt_pde                              :   1               ;    /* 23 */
        unsigned int bpch_bypass_rpt_pde                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_BPCH_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_BPCH_SUB0                     om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_BPCH;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_BPCH_SUB0                     om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_DDL_RPT_BPCH_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      delete_array_idx;
    unsigned int                                                      delete_aggr_array_idx;
} DCICP_SID_DCICP_OM_TRACE_NR_NO_SLOT_DONE_DEL_ARR;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      delete_array_idx;
    unsigned int                                                      delete_aggr_array_idx;
} DCICP_SID_DCICP_OM_TRACE_NR_NO_SLOT_DONE_DEL_ARR_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   4               ;    /* 3:0 */
        unsigned int slot_odd_even                                    :   4               ;    /* 7:4 */
        unsigned int dci_array_idx                                    :   4               ;    /* 11:8 */
        unsigned int union_dem_flag                                   :   4               ;    /* 15:12 */
        unsigned int k1_value_cfg_num                                 :   8               ;    /* 23:16 */
        unsigned int pds_harq_fbk_time_indi                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_K1_WARN_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_K1_WARN_SUB0                          om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_K1_WARN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_K1_WARN_SUB0                          om_data0;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_TRACE_NR_K1_WARN_BBP_MC;

typedef union {
    struct {
        unsigned int schedu_cfg_idx                                   :   16              ;    /* 15:0 */
        unsigned int array_idx                                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_FULL_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_FULL_SUB0                       om_data0;
    unsigned int                                                      dci_store_cnt;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_FULL;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_FULL_SUB0                       om_data0;
    unsigned int                                                      dci_store_cnt;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_FULL_BBP_MC;

typedef union {
    struct {
        unsigned int array_idx                                        :   4               ;    /* 3:0 */
        unsigned int dci_store_idx                                    :   4               ;    /* 7:4 */
        unsigned int dci_store_cnt                                    :   4               ;    /* 11:8 */
        unsigned int reserved_0                                       :   20              ;    /* 31:12 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_STORE_SUB0;

typedef union {
    struct {
        unsigned int schedu_cfg_idx                                   :   4               ;    /* 3:0 */
        unsigned int pds_sfn                                          :   10              ;    /* 13:4 */
        unsigned int pds_slot                                         :   7               ;    /* 20:14 */
        unsigned int r_type                                           :   5               ;    /* 25:21 */
        unsigned int k0                                               :   1               ;    /* 26 */
        unsigned int schedu_int_pos                                   :   4               ;    /* 30:27 */
        unsigned int reserved_0                                       :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_STORE_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_STORE_SUB0                      om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_STORE_SUB1                      om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_STORE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_STORE_SUB0                      om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_STORE_SUB1                      om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_STORE_BBP_MC;

typedef union {
    struct {
        unsigned int array_idx                                        :   4               ;    /* 3:0 */
        unsigned int reserved_0                                       :   1               ;    /* 4 */
        unsigned int del_aggr_flag                                    :   1               ;    /* 5 */
        unsigned int aggr_cnt                                         :   6               ;    /* 11:6 */
        unsigned int aggr_num                                         :   6               ;    /* 17:12 */
        unsigned int aggr_in_array                                    :   1               ;    /* 18 */
        unsigned int aggr_array_idx                                   :   4               ;    /* 22:19 */
        unsigned int aggr_start_flag                                  :   1               ;    /* 23 */
        unsigned int reserved_1                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DEL_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DEL_SUB0                        om_data0;
    unsigned int                                                      delete_idx;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DEL;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DEL_SUB0                        om_data0;
    unsigned int                                                      delete_idx;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DEL_BBP_MC;

typedef union {
    struct {
        unsigned int k0_flag                                          :   16              ;    /* 15:0 */
        unsigned int cur_schedu_flag                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DCI_SEL_SUB0;

typedef union {
    struct {
        unsigned int cfg_idx_flag                                     :   16              ;    /* 15:0 */
        unsigned int not_delay_flag                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DCI_SEL_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DCI_SEL_SUB0                    om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DCI_SEL_SUB1                    om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DCI_SEL;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DCI_SEL_SUB0                    om_data0;
    DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DCI_SEL_SUB1                    om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_ARRAY_DCI_SEL_BBP_MC;

typedef union {
    struct {
        unsigned int single_dci_work_en                               :   16              ;    /* 15:0 */
        unsigned int scheduled_slot_cfg_done                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_TRACE_NR_SDCI_INACTIVE_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rpt_dl_dci_idx;
    DCICP_SID_DCICP_OM_TRACE_NR_SDCI_INACTIVE_SUB1                    om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_SDCI_INACTIVE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rpt_dl_dci_idx;
    DCICP_SID_DCICP_OM_TRACE_NR_SDCI_INACTIVE_SUB1                    om_data1;
} DCICP_SID_DCICP_OM_TRACE_NR_SDCI_INACTIVE_BBP_MC;

typedef union {
    struct {
        unsigned int nr_sch_llr_comp_tbl0                             :   30              ;    /* 29:0 */
        unsigned int nr_sch_llr_comp_mod0                             :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB6;

typedef union {
    struct {
        unsigned int nr_sch_llr_comp_tbl1                             :   30              ;    /* 29:0 */
        unsigned int nr_sch_llr_comp_mod1                             :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB8;

typedef union {
    struct {
        unsigned int nr_sch_llr_6to5_scale                            :   6               ;    /* 5:0 */
        unsigned int nr_sch_llr_5to6_scale                            :   6               ;    /* 11:6 */
        unsigned int nr_sch_harq_shift_factor                         :   3               ;    /* 14:12 */
        unsigned int reserved_0                                       :   1               ;    /* 15:15 */
        unsigned int nr_sch_cb_chk_rslt_force_val6                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB10;

typedef union {
    struct {
        unsigned int nr_sch_ldpc_lft_sz                               :   9               ;    /* 8:0 */
        unsigned int nr_sch_ldpc_crc_ena                              :   1               ;    /* 9 */
        unsigned int nr_sch_ldpc_bg_type                              :   1               ;    /* 10 */
        unsigned int nr_sch_ldpc_succ_itr_tms                         :   4               ;    /* 14:11 */
        unsigned int nr_sch_ldpc_max_itr_flag                         :   1               ;    /* 15:15 */
        unsigned int reserved_0                                       :   6               ;    /* 21:16 */
        unsigned int nr_sch_harq_ind_inv1                             :   5               ;    /* 26:22 */
        unsigned int nr_sch_harq_ind_inv2                             :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB11;

typedef union {
    struct {
        unsigned int nr_sch_cb_trans_ind6                             :   16              ;    /* 15:0 */
        unsigned int nr_sch_cb_set0_ind6                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB18;

typedef union {
    struct {
        unsigned int nr_sch_byp_token                                 :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB25;

typedef union {
    struct {
        unsigned int nr_sch_cbg_en                                    :   1               ;    /* 0:0 */
        unsigned int nr_sch_cbg_num                                   :   5               ;    /* 5:1 */
        unsigned int nr_sch_cbg_m1                                    :   5               ;    /* 10:6 */
        unsigned int nr_sch_cbg_k1                                    :   8               ;    /* 18:11 */
        unsigned int nr_sch_cbg_k2                                    :   8               ;    /* 26:19 */
        unsigned int nr_local_mem_flag                                :   1               ;    /* 27 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB26;

typedef union {
    struct {
        unsigned int nr_sch_k                                         :   15              ;    /* 14:0 */
        unsigned int reserved_0                                       :   12              ;    /* 26:15 */
        unsigned int nr_sch_qm                                        :   3               ;    /* 29:27 */
        unsigned int nr_sch_nl                                        :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB27;

typedef union {
    struct {
        unsigned int reserved_0                                       :   1               ;    /* 0:0 */
        unsigned int nr_sch_all_cb_num                                :   8               ;    /* 8:1 */
        unsigned int nr_sch_cblen                                     :   14              ;    /* 22:9 */
        unsigned int nr_sch_bearer_type                               :   3               ;    /* 25:23 */
        unsigned int reserved_1                                       :   4               ;    /* 29:26 */
        unsigned int nr_sch_harq_mode                                 :   1               ;    /* 30 */
        unsigned int nr_sch_wch_mode                                  :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB28;

typedef union {
    struct {
        unsigned int nr_sch_ncb                                       :   15              ;    /* 14:0 */
        unsigned int reserved_0                                       :   1               ;    /* 15:15 */
        unsigned int nr_sch_nsb                                       :   15              ;    /* 30:16 */
        unsigned int reserved_1                                       :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB29;

typedef union {
    struct {
        unsigned int nr_mt_type                                       :   2               ;    /* 1:0 */
        unsigned int nr_sch_tb_new_flag                               :   1               ;    /* 2:2 */
        unsigned int nr_sch_no_harq_flag                              :   1               ;    /* 3:3 */
        unsigned int nr_tti_symbol_no                                 :   4               ;    /* 7:4 */
        unsigned int nr_tti_harq_no                                   :   4               ;    /* 11:8 */
        unsigned int nr_sch_tb_ind                                    :   1               ;    /* 12:12 */
        unsigned int nr_tti_slot_no                                   :   5               ;    /* 17:13 */
        unsigned int nr_tti_subfrm_no                                 :   4               ;    /* 21:18 */
        unsigned int nr_tti_sysfrm_no                                 :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB30;

typedef union {
    struct {
        unsigned int nr_sch_l2_cc_idx                                 :   4               ;    /* 3:0 */
        unsigned int nr_sch_modem_id                                  :   2               ;    /* 5:4 */
        unsigned int nr_sch_cg_id                                     :   2               ;    /* 7:6 */
        unsigned int nr_sch_c_id                                      :   5               ;    /* 12:8 */
        unsigned int reserved_0                                       :   3               ;    /* 15:13 */
        unsigned int nr_sch_tb_pmch_idx                               :   8               ;    /* 23:16 */
        unsigned int nr_sch_tb_mch_area_id                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB31;

typedef union {
    struct {
        unsigned int nr_sch_k1_idx                                    :   4               ;    /* 3:0 */
        unsigned int nr_sch_scs_idx                                   :   4               ;    /* 7:4 */
        unsigned int nr_sch_tb_rsv1_tbd_0                             :   8               ;    /* 15:8 */
        unsigned int nr_sch_tb_rsv2_tbd_1                             :   4               ;    /* 19:16 */
        unsigned int nr_sch_tb_dataerrind                             :   1               ;    /* 20:20 */
        unsigned int reserved_2                                       :   1               ;    /* 21:21 */
        unsigned int nr_sch_tb_r_type                                 :   6               ;    /* 27:22 */
        unsigned int reserved_3                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB32;

typedef union {
    struct {
        unsigned int nr_sch_tb_size                                   :   24              ;    /* 23:0 */
        unsigned int nr_preload_need_num                              :   7               ;    /* 30:24 */
        unsigned int reserved_0                                       :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB33;

typedef union {
    struct {
        unsigned int nr_harq_cb_addr_ind0                             :   10              ;    /* 9:0 */
        unsigned int nr_harq_cb_addr_ind1                             :   10              ;    /* 19:10 */
        unsigned int nr_harq_cb_addr_ind2                             :   10              ;    /* 29:20 */
        unsigned int nr_harq_trans_no                                 :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB34;

typedef union {
    struct {
        unsigned int nr_harq_cb_addr_ind3                             :   10              ;    /* 9:0 */
        unsigned int nr_harq_cb_addr_ind4                             :   10              ;    /* 19:10 */
        unsigned int nr_harq_cb_addr_ind5                             :   10              ;    /* 29:20 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB35;

typedef union {
    struct {
        unsigned int nr_harq_cb_addr_ind6                             :   10              ;    /* 9:0 */
        unsigned int nr_harq_cb_addr_ind7                             :   10              ;    /* 19:10 */
        unsigned int nr_harq_cb_addr_ind8                             :   10              ;    /* 29:20 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB36;

typedef union {
    struct {
        unsigned int nr_harq_cb_addr_ind9                             :   10              ;    /* 9:0 */
        unsigned int nr_harq_cb_addr_ind10                            :   10              ;    /* 19:10 */
        unsigned int nr_harq_cb_addr_ind11                            :   10              ;    /* 29:20 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB37;

typedef union {
    struct {
        unsigned int nr_harq_cb_addr_ind12                            :   10              ;    /* 9:0 */
        unsigned int nr_harq_cb_addr_ind13                            :   10              ;    /* 19:10 */
        unsigned int nr_harq_cb_addr_ind14                            :   10              ;    /* 29:20 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB38;

typedef union {
    struct {
        unsigned int nr_harq_cb_addr_ind15                            :   10              ;    /* 9:0 */
        unsigned int nr_harq_cb_addr_ind16                            :   10              ;    /* 19:10 */
        unsigned int nr_harq_cb_addr_ind17                            :   10              ;    /* 29:20 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB39;

typedef union {
    struct {
        unsigned int nr_harq_cb_addr_ind18                            :   10              ;    /* 9:0 */
        unsigned int nr_harq_cb_addr_ind19                            :   10              ;    /* 19:10 */
        unsigned int nr_harq_cb_addr_ind20                            :   10              ;    /* 29:20 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB40;

typedef union {
    struct {
        unsigned int nr_harq_cb_addr_ind21                            :   10              ;    /* 9:0 */
        unsigned int nr_harq_cb_addr_ind22                            :   10              ;    /* 19:10 */
        unsigned int nr_harq_cb_addr_ind23                            :   10              ;    /* 29:20 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB41;

typedef union {
    struct {
        unsigned int nr_sch_crc_rpt_en                                :   1               ;    /* 0:0 */
        unsigned int nr_sch_dsp_int_en                                :   1               ;    /* 1:1 */
        unsigned int nr_sch_dsp_reg_rpt_en                            :   1               ;    /* 2:2 */
        unsigned int nr_sch_dsp_int_reg                               :   5               ;    /* 7:3 */
        unsigned int nr_sch_dsp_int_addr_h                            :   8               ;    /* 15:8 */
        unsigned int nr_sch_dsp_reg_rpt_addr_h                        :   8               ;    /* 23:16 */
        unsigned int nr_sch_crc_rpt_addr_h                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB50;

typedef union {
    struct {
        unsigned int nr_sch_crc_clr_en                                :   1               ;    /* 0:0 */
        unsigned int nr_sch_pde_int_en                                :   1               ;    /* 1:1 */
        unsigned int nr_sch_pde_reg_rpt_en                            :   1               ;    /* 2:2 */
        unsigned int nr_sch_pde_int_reg                               :   5               ;    /* 7:3 */
        unsigned int nr_sch_pde_int_addr_h                            :   8               ;    /* 15:8 */
        unsigned int nr_sch_pde_reg_rpt_addr_h                        :   8               ;    /* 23:16 */
        unsigned int nr_sch_hidis_reg_rpt_addr_h                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB51;

typedef union {
    struct {
        unsigned int nr_sch_cfg_en                                    :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   7               ;    /* 7:1 */
        unsigned int nr_sch_tb_work_overtime_cfg                      :   16              ;    /* 23:8 */
        unsigned int nr_sch_slot_idx                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB53;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val0;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val1;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val2;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val3;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val4;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val5;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB6                       om_data6;
    unsigned int                                                      nr_sch_llr_decomp_tbl0;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB8                       om_data8;
    unsigned int                                                      nr_sch_llr_decomp_tbl1;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB10                      om_data10;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB11                      om_data11;
    unsigned int                                                      nr_sch_cb_trans_ind0;
    unsigned int                                                      nr_sch_cb_trans_ind1;
    unsigned int                                                      nr_sch_cb_trans_ind2;
    unsigned int                                                      nr_sch_cb_trans_ind3;
    unsigned int                                                      nr_sch_cb_trans_ind4;
    unsigned int                                                      nr_sch_cb_trans_ind5;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB18                      om_data18;
    unsigned int                                                      nr_sch_cb_set0_ind0;
    unsigned int                                                      nr_sch_cb_set0_ind1;
    unsigned int                                                      nr_sch_cb_set0_ind2;
    unsigned int                                                      nr_sch_cb_set0_ind3;
    unsigned int                                                      nr_sch_cb_set0_ind4;
    unsigned int                                                      nr_sch_cb_set0_ind5;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB25                      om_data25;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB26                      om_data26;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB27                      om_data27;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB28                      om_data28;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB29                      om_data29;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB30                      om_data30;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB31                      om_data31;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB32                      om_data32;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB33                      om_data33;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB34                      om_data34;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB35                      om_data35;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB36                      om_data36;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB37                      om_data37;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB38                      om_data38;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB39                      om_data39;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB40                      om_data40;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB41                      om_data41;
    unsigned int                                                      nr_sch_tb_bypass_val0;
    unsigned int                                                      nr_sch_tb_bypass_val1;
    unsigned int                                                      nr_sch_dsp_reg_rpt_addr_l;
    unsigned int                                                      nr_sch_dsp_int_addr_l;
    unsigned int                                                      nr_sch_pde_reg_rpt_addr_l;
    unsigned int                                                      nr_sch_pde_int_addr_l;
    unsigned int                                                      nr_sch_hidis_reg_rpt_addr_l;
    unsigned int                                                      nr_sch_crc_rpt_addr_l;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB50                      om_data50;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB51                      om_data51;
    unsigned int                                                      nr_sch_cc_for_rpt0;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB53                      om_data53;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val0;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val1;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val2;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val3;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val4;
    unsigned int                                                      nr_sch_cb_chk_rslt_force_val5;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB6                       om_data6;
    unsigned int                                                      nr_sch_llr_decomp_tbl0;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB8                       om_data8;
    unsigned int                                                      nr_sch_llr_decomp_tbl1;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB10                      om_data10;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB11                      om_data11;
    unsigned int                                                      nr_sch_cb_trans_ind0;
    unsigned int                                                      nr_sch_cb_trans_ind1;
    unsigned int                                                      nr_sch_cb_trans_ind2;
    unsigned int                                                      nr_sch_cb_trans_ind3;
    unsigned int                                                      nr_sch_cb_trans_ind4;
    unsigned int                                                      nr_sch_cb_trans_ind5;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB18                      om_data18;
    unsigned int                                                      nr_sch_cb_set0_ind0;
    unsigned int                                                      nr_sch_cb_set0_ind1;
    unsigned int                                                      nr_sch_cb_set0_ind2;
    unsigned int                                                      nr_sch_cb_set0_ind3;
    unsigned int                                                      nr_sch_cb_set0_ind4;
    unsigned int                                                      nr_sch_cb_set0_ind5;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB25                      om_data25;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB26                      om_data26;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB27                      om_data27;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB28                      om_data28;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB29                      om_data29;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB30                      om_data30;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB31                      om_data31;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB32                      om_data32;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB33                      om_data33;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB34                      om_data34;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB35                      om_data35;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB36                      om_data36;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB37                      om_data37;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB38                      om_data38;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB39                      om_data39;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB40                      om_data40;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB41                      om_data41;
    unsigned int                                                      nr_sch_tb_bypass_val0;
    unsigned int                                                      nr_sch_tb_bypass_val1;
    unsigned int                                                      nr_sch_dsp_reg_rpt_addr_l;
    unsigned int                                                      nr_sch_dsp_int_addr_l;
    unsigned int                                                      nr_sch_pde_reg_rpt_addr_l;
    unsigned int                                                      nr_sch_pde_int_addr_l;
    unsigned int                                                      nr_sch_hidis_reg_rpt_addr_l;
    unsigned int                                                      nr_sch_crc_rpt_addr_l;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB50                      om_data50;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB51                      om_data51;
    unsigned int                                                      nr_sch_cc_for_rpt0;
    DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_SUB53                      om_data53;
} DCICP_SID_DCICP_OM_INFO_DDL_SCH_CONFIG_BBP_MC;

typedef union {
    struct {
        unsigned int last_bpch_llr_comp_mode_ind                      :   1               ;    /* 0:0 */
        unsigned int last_bpch_wch_set0_ind                           :   1               ;    /* 1:1 */
        unsigned int reserved_0                                       :   6               ;    /* 7:2 */
        unsigned int last_bpch_cap_data_len                           :   15              ;    /* 22:8 */
        unsigned int reserved_1                                       :   9               ;    /* 31:23 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB0;

typedef union {
    struct {
        unsigned int bpch_llr_comp_tbl0                               :   30              ;    /* 29:0 */
        unsigned int bpch_llr_comp_mod0                               :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB1;

typedef union {
    struct {
        unsigned int bpch_llr_6to5_scale                              :   6               ;    /* 5:0 */
        unsigned int bpch_llr_5to6_scale                              :   6               ;    /* 11:6 */
        unsigned int bpch_harq_shift_factor                           :   3               ;    /* 14:12 */
        unsigned int reserved_0                                       :   17              ;    /* 31:15 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB3;

typedef union {
    struct {
        unsigned int bpch_ldpc_lft_sz                                 :   9               ;    /* 8:0 */
        unsigned int bpch_ldpc_crc_ena                                :   1               ;    /* 9 */
        unsigned int bpch_ldpc_bg_type                                :   1               ;    /* 10 */
        unsigned int bpch_ldpc_succ_itr_tms                           :   4               ;    /* 14:11 */
        unsigned int bpch_ldpc_max_itr_flag                           :   1               ;    /* 15:15 */
        unsigned int reserved_0                                       :   6               ;    /* 21:16 */
        unsigned int bpch_harq_ind_inv1                               :   5               ;    /* 26:22 */
        unsigned int bpch_harq_ind_inv2                               :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB4;

typedef union {
    struct {
        unsigned int bpch_cb_addr_ind                                 :   10              ;    /* 9:0 */
        unsigned int reserved_0                                       :   3               ;    /* 12:10 */
        unsigned int bpch_kup_f1                                      :   9               ;    /* 21:13 */
        unsigned int bpch_kup_f2                                      :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB5;

typedef union {
    struct {
        unsigned int bpch_k                                           :   15              ;    /* 14:0 */
        unsigned int bpch_fill_len                                    :   6               ;    /* 20:15 */
        unsigned int bpch_col_post                                    :   7               ;    /* 27:21 */
        unsigned int bpch_qm                                          :   2               ;    /* 29:28 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB6;

typedef union {
    struct {
        unsigned int reserved_0                                       :   1               ;    /* 0:0 */
        unsigned int bpch_tb_all_cb_num                               :   8               ;    /* 8:1 */
        unsigned int bpch_tb_cblen                                    :   14              ;    /* 22:9 */
        unsigned int reserved_1                                       :   7               ;    /* 29:23 */
        unsigned int bpch_harq_mode                                   :   1               ;    /* 30 */
        unsigned int bpch_wch_mode                                    :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB7;

typedef union {
    struct {
        unsigned int bpch_tb_ncb                                      :   15              ;    /* 14:0 */
        unsigned int reserved_0                                       :   1               ;    /* 15 */
        unsigned int bpch_tb_nsb                                      :   15              ;    /* 30:16 */
        unsigned int reserved_1                                       :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB8;

typedef union {
    struct {
        unsigned int bpch_l2_cc_idx                                   :   4               ;    /* 3:0 */
        unsigned int bpch_modem_id                                    :   2               ;    /* 5:4 */
        unsigned int bpch_cgid                                        :   2               ;    /* 7:6 */
        unsigned int bpch_c_id                                        :   5               ;    /* 12:8 */
        unsigned int reserved_0                                       :   3               ;    /* 15:13 */
        unsigned int bpch_tb_size                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB9;

typedef union {
    struct {
        unsigned int bpch_k1_idx                                      :   4               ;    /* 3:0 */
        unsigned int bpch_scs_idx                                     :   4               ;    /* 7:4 */
        unsigned int bpch_tb_rsv1_tbd_0                               :   8               ;    /* 15:8 */
        unsigned int bpch_tb_rsv2_tbd_1                               :   4               ;    /* 19:16 */
        unsigned int reserved_2                                       :   2               ;    /* 21:20 */
        unsigned int bpch_r_type                                      :   6               ;    /* 27:22 */
        unsigned int reserved_3                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB10;

typedef union {
    struct {
        unsigned int bpch_mt_type                                     :   2               ;    /* 1:0 */
        unsigned int bpch_tb_new_flag                                 :   1               ;    /* 2:2 */
        unsigned int bpch_no_harq_flag                                :   1               ;    /* 3:3 */
        unsigned int reserved_0                                       :   1               ;    /* 4:4 */
        unsigned int bpch_tti_symbol_no                               :   4               ;    /* 8:5 */
        unsigned int bpch_sib1_flag                                   :   2               ;    /* 10:9 */
        unsigned int reserved_1                                       :   2               ;    /* 12:11 */
        unsigned int bpch_tti_slot_no                                 :   5               ;    /* 17:13 */
        unsigned int bpch_tti_subfrm_no                               :   4               ;    /* 21:18 */
        unsigned int bpch_tti_sysfrm_no                               :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB11;

typedef union {
    struct {
        unsigned int bpch_ddr_tcm_sel                                 :   1               ;    /* 0:0 */
        unsigned int bpch_dsp_int_en                                  :   1               ;    /* 1:1 */
        unsigned int bpch_dsp_reg_rpt_en                              :   1               ;    /* 2:2 */
        unsigned int bpch_dsp_int_reg                                 :   5               ;    /* 7:3 */
        unsigned int bpch_dsp_int_addr_h                              :   8               ;    /* 15:8 */
        unsigned int bpch_dsp_reg_rpt_addr_h                          :   8               ;    /* 23:16 */
        unsigned int bpch_rpt_addr_h                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB20;

typedef union {
    struct {
        unsigned int reserved_0                                       :   1               ;    /* 0:0 */
        unsigned int bpch_pde_int_en                                  :   1               ;    /* 1:1 */
        unsigned int bpch_pde_reg_rpt_en                              :   1               ;    /* 2:2 */
        unsigned int bpch_pde_int_reg                                 :   5               ;    /* 7:3 */
        unsigned int bpch_pde_int_addr_h                              :   8               ;    /* 15:8 */
        unsigned int bpch_pde_reg_rpt_addr_h                          :   8               ;    /* 23:16 */
        unsigned int bpch_hidis_reg_rpt_addr_h                        :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB21;

typedef union {
    struct {
        unsigned int bpch_cc_for_rpt0                                 :   24              ;    /* 23:0 */
        unsigned int bpch_cb_chk_rslt_force_val0                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB22;

typedef union {
    struct {
        unsigned int bpch_cfg_en                                      :   1               ;    /* 0 */
        unsigned int reserved_0                                       :   7               ;    /* 7:1 */
        unsigned int bpch_work_overtime_cfg                           :   16              ;    /* 23:8 */
        unsigned int bpch_slot_idx                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB23;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB0                      om_data0;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB1                      om_data1;
    unsigned int                                                      bpch_llr_decomp_tbl0;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB3                      om_data3;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB4                      om_data4;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB5                      om_data5;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB6                      om_data6;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB7                      om_data7;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB8                      om_data8;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB9                      om_data9;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB10                     om_data10;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB11                     om_data11;
    unsigned int                                                      bpch_bypass_val0;
    unsigned int                                                      bpch_bypass_val1;
    unsigned int                                                      bpch_dsp_reg_rpt_addr_l;
    unsigned int                                                      bpch_dsp_int_addr_l;
    unsigned int                                                      bpch_pde_reg_rpt_addr_l;
    unsigned int                                                      bpch_pde_int_addr_l;
    unsigned int                                                      bpch_hidis_reg_rpt_addr_l;
    unsigned int                                                      bpch_rpt_addr_l;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB20                     om_data20;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB21                     om_data21;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB22                     om_data22;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB23                     om_data23;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB0                      om_data0;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB1                      om_data1;
    unsigned int                                                      bpch_llr_decomp_tbl0;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB3                      om_data3;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB4                      om_data4;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB5                      om_data5;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB6                      om_data6;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB7                      om_data7;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB8                      om_data8;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB9                      om_data9;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB10                     om_data10;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB11                     om_data11;
    unsigned int                                                      bpch_bypass_val0;
    unsigned int                                                      bpch_bypass_val1;
    unsigned int                                                      bpch_dsp_reg_rpt_addr_l;
    unsigned int                                                      bpch_dsp_int_addr_l;
    unsigned int                                                      bpch_pde_reg_rpt_addr_l;
    unsigned int                                                      bpch_pde_int_addr_l;
    unsigned int                                                      bpch_hidis_reg_rpt_addr_l;
    unsigned int                                                      bpch_rpt_addr_l;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB20                     om_data20;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB21                     om_data21;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB22                     om_data22;
    DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_SUB23                     om_data23;
} DCICP_SID_DCICP_OM_INFO_DDL_PBCH_CONFIG_BBP_MC;

typedef union {
    struct {
        unsigned int che_ch_sel                                       :   8               ;    /* 7:0 */
        unsigned int che_nr_proc_type                                 :   8               ;    /* 15:8 */
        unsigned int boudle_start_flag                                :   8               ;    /* 23:16 */
        unsigned int che_dmrs_sym_num                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB0;

typedef union {
    struct {
        unsigned int che_dmrs_sym_idx0                                :   8               ;    /* 7:0 */
        unsigned int che_dmrs_sym_idx1                                :   8               ;    /* 15:8 */
        unsigned int che_dmrs_sym_idx2                                :   8               ;    /* 23:16 */
        unsigned int che_dmrs_sym_idx3                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB1;

typedef union {
    struct {
        unsigned int che_dmrs_port_mode                               :   8               ;    /* 7:0 */
        unsigned int che_dmrs_port_num                                :   8               ;    /* 15:8 */
        unsigned int che_bund_size                                    :   8               ;    /* 23:16 */
        unsigned int che_pattern_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB2;

typedef union {
    struct {
        unsigned int che_dmrs_port_tab                                :   16              ;    /* 15:0 */
        unsigned int che_dl_rb_num                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB3;

typedef union {
    struct {
        unsigned int bwp_offset                                       :   16              ;    /* 15:0 */
        unsigned int rmsi_offset                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB4;

typedef union {
    struct {
        unsigned int qcl_pg0_ind                                      :   8               ;    /* 7:0 */
        unsigned int qcl_pg1_ind                                      :   8               ;    /* 15:8 */
        unsigned int qcl_pg2_ind                                      :   8               ;    /* 23:16 */
        unsigned int dcicp_slot_idx                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB5;

typedef union {
    struct {
        unsigned int che_max_qrmport_num                              :   8               ;    /* 7:0 */
        unsigned int che_mu_qrm_flag                                  :   8               ;    /* 15:8 */
        unsigned int che_y_symb_idx_mu                                :   8               ;    /* 23:16 */
        unsigned int che_dmrs_power_offset                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB6;

typedef union {
    struct {
        unsigned int che_mu_en                                        :   8               ;    /* 7:0 */
        unsigned int che_h_symb_idx_mu                                :   8               ;    /* 15:8 */
        unsigned int che_dmrs_muport_tab                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB7;

typedef union {
    struct {
        unsigned int nche_en                                          :   8               ;    /* 7:0 */
        unsigned int che_bpch_dsp_idx                                 :   8               ;    /* 15:8 */
        unsigned int reserved1_0                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB8;

typedef union {
    struct {
        unsigned int fpds_ptrs_rb_start                               :   8               ;    /* 7:0 */
        unsigned int fpds_ptrs_epre_ratio                             :   8               ;    /* 15:8 */
        unsigned int fpds_ptrs0_ch_sym_en                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB9;

typedef union {
    struct {
        unsigned int fpds_ptrs_re_en                                  :   8               ;    /* 7:0 */
        unsigned int fpds_ptrs_rb_gap                                 :   8               ;    /* 15:8 */
        unsigned int fpds_ptrs_en                                     :   8               ;    /* 23:16 */
        unsigned int ptrs_punc_flag                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB10;

typedef union {
    struct {
        unsigned int fddl_preload_mt_type                             :   2               ;    /* 1:0 */
        unsigned int fddl_preload_ch_type                             :   2               ;    /* 3:2 */
        unsigned int reserved_0                                       :   4               ;    /* 7:4 */
        unsigned int fddl_preload_tb1_en                              :   1               ;    /* 8 */
        unsigned int fddl_preload_tb1_odd_even                        :   1               ;    /* 9 */
        unsigned int fddl_preload_tb1_cfg_idx                         :   5               ;    /* 14:10 */
        unsigned int reserved_1                                       :   1               ;    /* 15 */
        unsigned int fddl_preload_tb2_en                              :   1               ;    /* 16 */
        unsigned int fddl_preload_tb2_odd_even                        :   1               ;    /* 17 */
        unsigned int fddl_preload_tb2_cfg_idx                         :   5               ;    /* 22:18 */
        unsigned int fddl_tb_swap_flag                                :   1               ;    /* 23 */
        unsigned int reserved_2                                       :   7               ;    /* 30:24 */
        unsigned int fddl_preload_cc_vld                              :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB11;

typedef union {
    struct {
        unsigned int reserved2_0                                      :   8               ;    /* 7:0 */
        unsigned int n_sc_g0                                          :   8               ;    /* 15:8 */
        unsigned int n_sc_g1                                          :   8               ;    /* 23:16 */
        unsigned int n_sc_g2                                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB12;

typedef union {
    struct {
        unsigned int che_mu_follow_su_ind                             :   8               ;    /* 7:0 */
        unsigned int x_seq_portgroup_diff_en                          :   8               ;    /* 15:8 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB13;

typedef union {
    struct {
        unsigned int reserved_0                                       :   16              ;    /* 15:0 */
        unsigned int reserved_1                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB14;

typedef union {
    struct {
        unsigned int wiener_noise_en                                  :   8               ;    /* 7:0 */
        unsigned int xsub_noise_en                                    :   8               ;    /* 15:8 */
        unsigned int che_sat_net_flag                                 :   8               ;    /* 23:16 */
        unsigned int reserved4_0                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB15;

typedef union {
    struct {
        unsigned int qcl0_snr_time_th0                                :   8               ;    /* 7:0 */
        unsigned int qcl0_snr_time_th1                                :   8               ;    /* 15:8 */
        unsigned int qcl0_snr_time_th2                                :   8               ;    /* 23:16 */
        unsigned int qcl0_freq_wiener_coef_snr_sel                    :   1               ;    /* 24 */
        unsigned int qcl0_time_wiener_coef_snr_sel                    :   1               ;    /* 25 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB16;

typedef union {
    struct {
        unsigned int qcl0_r0_g0_freq_snr_idx                          :   2               ;    /* 1:0 */
        unsigned int qcl0_r0_g1_freq_snr_idx                          :   2               ;    /* 3:2 */
        unsigned int qcl0_r0_g2_freq_snr_idx                          :   2               ;    /* 5:4 */
        unsigned int qcl0_r1_g0_freq_snr_idx                          :   2               ;    /* 7:6 */
        unsigned int qcl0_r1_g1_freq_snr_idx                          :   2               ;    /* 9:8 */
        unsigned int qcl0_r1_g2_freq_snr_idx                          :   2               ;    /* 11:10 */
        unsigned int qcl0_r2_g0_freq_snr_idx                          :   2               ;    /* 13:12 */
        unsigned int qcl0_r2_g1_freq_snr_idx                          :   2               ;    /* 15:14 */
        unsigned int qcl0_r2_g2_freq_snr_idx                          :   2               ;    /* 17:16 */
        unsigned int qcl0_r3_g0_freq_snr_idx                          :   2               ;    /* 19:18 */
        unsigned int qcl0_r3_g1_freq_snr_idx                          :   2               ;    /* 21:20 */
        unsigned int qcl0_r3_g2_freq_snr_idx                          :   2               ;    /* 23:22 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB17;

typedef union {
    struct {
        unsigned int qcl0_r0_g0_time_snr_idx                          :   2               ;    /* 1:0 */
        unsigned int qcl0_r0_g1_time_snr_idx                          :   2               ;    /* 3:2 */
        unsigned int qcl0_r0_g2_time_snr_idx                          :   2               ;    /* 5:4 */
        unsigned int qcl0_r1_g0_time_snr_idx                          :   2               ;    /* 7:6 */
        unsigned int qcl0_r1_g1_time_snr_idx                          :   2               ;    /* 9:8 */
        unsigned int qcl0_r1_g2_time_snr_idx                          :   2               ;    /* 11:10 */
        unsigned int qcl0_r2_g0_time_snr_idx                          :   2               ;    /* 13:12 */
        unsigned int qcl0_r2_g1_time_snr_idx                          :   2               ;    /* 15:14 */
        unsigned int qcl0_r2_g2_time_snr_idx                          :   2               ;    /* 17:16 */
        unsigned int qcl0_r3_g0_time_snr_idx                          :   2               ;    /* 19:18 */
        unsigned int qcl0_r3_g1_time_snr_idx                          :   2               ;    /* 21:20 */
        unsigned int qcl0_r3_g2_time_snr_idx                          :   2               ;    /* 23:22 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB18;

typedef union {
    struct {
        unsigned int qcl0_nr_dft_win_set0_start_idx                   :   5               ;    /* 4:0 */
        unsigned int qcl0_nr_dft_noise_start_idx                      :   5               ;    /* 9:5 */
        unsigned int qcl0_dft_port_zero_idx                           :   8               ;    /* 17:10 */
        unsigned int qcl0_dft_pdp_fltr_snr_flag                       :   4               ;    /* 21:18 */
        unsigned int reserved_0                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB19;

typedef union {
    struct {
        unsigned int qcl0_dft_r0pg0_vdmrs_snr0                        :   4               ;    /* 3:0 */
        unsigned int qcl0_dft_r0pg1_vdmrs_snr0                        :   4               ;    /* 7:4 */
        unsigned int qcl0_dft_r0pg2_vdmrs_snr0                        :   4               ;    /* 11:8 */
        unsigned int qcl0_dft_r1pg0_vdmrs_snr0                        :   4               ;    /* 15:12 */
        unsigned int qcl0_dft_r1pg1_vdmrs_snr0                        :   4               ;    /* 19:16 */
        unsigned int qcl0_dft_r1pg2_vdmrs_snr0                        :   4               ;    /* 23:20 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB20;

typedef union {
    struct {
        unsigned int qcl0_dft_r2pg0_vdmrs_snr0                        :   4               ;    /* 3:0 */
        unsigned int qcl0_dft_r2pg1_vdmrs_snr0                        :   4               ;    /* 7:4 */
        unsigned int qcl0_dft_r2pg2_vdmrs_snr0                        :   4               ;    /* 11:8 */
        unsigned int qcl0_dft_r3pg0_vdmrs_snr0                        :   4               ;    /* 15:12 */
        unsigned int qcl0_dft_r3pg1_vdmrs_snr0                        :   4               ;    /* 19:16 */
        unsigned int qcl0_dft_r3pg2_vdmrs_snr0                        :   4               ;    /* 23:20 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB21;

typedef union {
    struct {
        unsigned int qcl0_fcorr_power                                 :   12              ;    /* 11:0 */
        unsigned int qcl0_fcoef_winner_sel                            :   1               ;    /* 12 */
        unsigned int qcl0_fcoef_corr_sel                              :   1               ;    /* 13 */
        unsigned int qcl0_fcoef_pingpang_idx                          :   1               ;    /* 14 */
        unsigned int qcl0_fcoef_pre_corr_idx                          :   3               ;    /* 17:15 */
        unsigned int qcl0_fcoef_trms                                  :   2               ;    /* 19:18 */
        unsigned int qcl0_freq_dc_proc_flag                           :   1               ;    /* 20 */
        unsigned int reserved_0                                       :   11              ;    /* 31:21 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB22;

typedef union {
    struct {
        unsigned int qcl0_che_nr_to                                   :   16              ;    /* 15:0 */
        unsigned int qcl0_che_nr_fo                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB23;

typedef union {
    struct {
        unsigned int qcl1_snr_time_th0                                :   8               ;    /* 7:0 */
        unsigned int qcl1_snr_time_th1                                :   8               ;    /* 15:8 */
        unsigned int qcl1_snr_time_th2                                :   8               ;    /* 23:16 */
        unsigned int qcl1_freq_wiener_coef_snr_sel                    :   1               ;    /* 24 */
        unsigned int qcl1_time_wiener_coef_snr_sel                    :   1               ;    /* 25 */
        unsigned int reserved_0                                       :   6               ;    /* 31:26 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB24;

typedef union {
    struct {
        unsigned int qcl1_r0_g0_freq_snr_idx                          :   2               ;    /* 1:0 */
        unsigned int qcl1_r0_g1_freq_snr_idx                          :   2               ;    /* 3:2 */
        unsigned int qcl1_r0_g2_freq_snr_idx                          :   2               ;    /* 5:4 */
        unsigned int qcl1_r1_g0_freq_snr_idx                          :   2               ;    /* 7:6 */
        unsigned int qcl1_r1_g1_freq_snr_idx                          :   2               ;    /* 9:8 */
        unsigned int qcl1_r1_g2_freq_snr_idx                          :   2               ;    /* 11:10 */
        unsigned int qcl1_r2_g0_freq_snr_idx                          :   2               ;    /* 13:12 */
        unsigned int qcl1_r2_g1_freq_snr_idx                          :   2               ;    /* 15:14 */
        unsigned int qcl1_r2_g2_freq_snr_idx                          :   2               ;    /* 17:16 */
        unsigned int qcl1_r3_g0_freq_snr_idx                          :   2               ;    /* 19:18 */
        unsigned int qcl1_r3_g1_freq_snr_idx                          :   2               ;    /* 21:20 */
        unsigned int qcl1_r3_g2_freq_snr_idx                          :   2               ;    /* 23:22 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB25;

typedef union {
    struct {
        unsigned int qcl1_r0_g0_time_snr_idx                          :   2               ;    /* 1:0 */
        unsigned int qcl1_r0_g1_time_snr_idx                          :   2               ;    /* 3:2 */
        unsigned int qcl1_r0_g2_time_snr_idx                          :   2               ;    /* 5:4 */
        unsigned int qcl1_r1_g0_time_snr_idx                          :   2               ;    /* 7:6 */
        unsigned int qcl1_r1_g1_time_snr_idx                          :   2               ;    /* 9:8 */
        unsigned int qcl1_r1_g2_time_snr_idx                          :   2               ;    /* 11:10 */
        unsigned int qcl1_r2_g0_time_snr_idx                          :   2               ;    /* 13:12 */
        unsigned int qcl1_r2_g1_time_snr_idx                          :   2               ;    /* 15:14 */
        unsigned int qcl1_r2_g2_time_snr_idx                          :   2               ;    /* 17:16 */
        unsigned int qcl1_r3_g0_time_snr_idx                          :   2               ;    /* 19:18 */
        unsigned int qcl1_r3_g1_time_snr_idx                          :   2               ;    /* 21:20 */
        unsigned int qcl1_r3_g2_time_snr_idx                          :   2               ;    /* 23:22 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB26;

typedef union {
    struct {
        unsigned int qcl1_nr_dft_win_set0_start_idx                   :   5               ;    /* 4:0 */
        unsigned int qcl1_nr_dft_noise_start_idx                      :   5               ;    /* 9:5 */
        unsigned int qcl1_dft_port_zero_idx                           :   8               ;    /* 17:10 */
        unsigned int qcl1_dft_pdp_fltr_snr_flag                       :   4               ;    /* 21:18 */
        unsigned int reserved_0                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB27;

typedef union {
    struct {
        unsigned int qcl1_dft_r0pg0_vdmrs_snr0                        :   4               ;    /* 3:0 */
        unsigned int qcl1_dft_r0pg1_vdmrs_snr0                        :   4               ;    /* 7:4 */
        unsigned int qcl1_dft_r0pg2_vdmrs_snr0                        :   4               ;    /* 11:8 */
        unsigned int qcl1_dft_r1pg0_vdmrs_snr0                        :   4               ;    /* 15:12 */
        unsigned int qcl1_dft_r1pg1_vdmrs_snr0                        :   4               ;    /* 19:16 */
        unsigned int qcl1_dft_r1pg2_vdmrs_snr0                        :   4               ;    /* 23:20 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB28;

typedef union {
    struct {
        unsigned int qcl1_dft_r2pg0_vdmrs_snr0                        :   4               ;    /* 3:0 */
        unsigned int qcl1_dft_r2pg1_vdmrs_snr0                        :   4               ;    /* 7:4 */
        unsigned int qcl1_dft_r2pg2_vdmrs_snr0                        :   4               ;    /* 11:8 */
        unsigned int qcl1_dft_r3pg0_vdmrs_snr0                        :   4               ;    /* 15:12 */
        unsigned int qcl1_dft_r3pg1_vdmrs_snr0                        :   4               ;    /* 19:16 */
        unsigned int qcl1_dft_r3pg2_vdmrs_snr0                        :   4               ;    /* 23:20 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB29;

typedef union {
    struct {
        unsigned int qcl1_fcorr_power                                 :   12              ;    /* 11:0 */
        unsigned int qcl1_fcoef_winner_sel                            :   1               ;    /* 12 */
        unsigned int qcl1_fcoef_corr_sel                              :   1               ;    /* 13 */
        unsigned int qcl1_fcoef_pingpang_idx                          :   1               ;    /* 14 */
        unsigned int qcl1_fcoef_pre_corr_idx                          :   3               ;    /* 17:15 */
        unsigned int qcl1_fcoef_trms                                  :   2               ;    /* 19:18 */
        unsigned int qcl1_freq_dc_proc_flag                           :   1               ;    /* 20 */
        unsigned int reserved_0                                       :   11              ;    /* 31:21 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB30;

typedef union {
    struct {
        unsigned int qcl1_che_nr_to                                   :   16              ;    /* 15:0 */
        unsigned int qcl1_che_nr_fo                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB31;

typedef union {
    struct {
        unsigned int cfc_calc_en                                      :   8               ;    /* 7:0 */
        unsigned int cfc_inst_isr_sel                                 :   8               ;    /* 15:8 */
        unsigned int cfc_mtrp_2qcl_flag                               :   8               ;    /* 23:16 */
        unsigned int mdci_mtrp_flag                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB32;

typedef union {
    struct {
        unsigned int fcorr0_sel_idx                                   :   8               ;    /* 7:0 */
        unsigned int fcorr1_sel_idx                                   :   8               ;    /* 15:8 */
        unsigned int tcorr0_sel_idx                                   :   8               ;    /* 23:16 */
        unsigned int tcorr1_sel_idx                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB33;

typedef union {
    struct {
        unsigned int cfc_fcorr_merge_flag                             :   8               ;    /* 7:0 */
        unsigned int cfc_tcorr_merge_flag                             :   8               ;    /* 15:8 */
        unsigned int dcicp_cmd_ind_rpt                                :   8               ;    /* 23:16 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB34;

typedef union {
    struct {
        unsigned int dft_pdp_flt_buffer_id                            :   8               ;    /* 7:0 */
        unsigned int dft_pdp_fltr_init0                               :   8               ;    /* 15:8 */
        unsigned int dft_pdp_fltr_init1                               :   8               ;    /* 23:16 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB35;

typedef union {
    struct {
        unsigned int nr_irc_ruu_mode                                  :   1               ;    /* 0 */
        unsigned int nr_irc_ruu_sel                                   :   2               ;    /* 2:1 */
        unsigned int nr_irc_n1                                        :   3               ;    /* 5:3 */
        unsigned int nr_irc_n2                                        :   3               ;    /* 8:6 */
        unsigned int reserved_0                                       :   1               ;    /* 9 */
        unsigned int nr_irc_fallback_flag                             :   1               ;    /* 10 */
        unsigned int nr_irc_zp_nzp_flag                               :   2               ;    /* 12:11 */
        unsigned int nr_irc_zp_sel                                    :   3               ;    /* 15:13 */
        unsigned int nr_irc_th1                                       :   10              ;    /* 25:16 */
        unsigned int nr_irc_th1_flag                                  :   1               ;    /* 26 */
        unsigned int reserved_zero0_1                                 :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB36;

typedef union {
    struct {
        unsigned int r4_g0_freq_snr_idx                               :   2               ;    /* 1:0 */
        unsigned int r4_g1_freq_snr_idx                               :   2               ;    /* 3:2 */
        unsigned int r4_g2_freq_snr_idx                               :   2               ;    /* 5:4 */
        unsigned int r5_g0_freq_snr_idx                               :   2               ;    /* 7:6 */
        unsigned int r5_g1_freq_snr_idx                               :   2               ;    /* 9:8 */
        unsigned int r5_g2_freq_snr_idx                               :   2               ;    /* 11:10 */
        unsigned int r6_g0_freq_snr_idx                               :   2               ;    /* 13:12 */
        unsigned int r6_g1_freq_snr_idx                               :   2               ;    /* 15:14 */
        unsigned int r6_g2_freq_snr_idx                               :   2               ;    /* 17:16 */
        unsigned int r7_g0_freq_snr_idx                               :   2               ;    /* 19:18 */
        unsigned int r7_g1_freq_snr_idx                               :   2               ;    /* 21:20 */
        unsigned int r7_g2_freq_snr_idx                               :   2               ;    /* 23:22 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB37;

typedef union {
    struct {
        unsigned int r4_g0_time_snr_idx                               :   2               ;    /* 1:0 */
        unsigned int r4_g1_time_snr_idx                               :   2               ;    /* 3:2 */
        unsigned int r4_g2_time_snr_idx                               :   2               ;    /* 5:4 */
        unsigned int r5_g0_time_snr_idx                               :   2               ;    /* 7:6 */
        unsigned int r5_g1_time_snr_idx                               :   2               ;    /* 9:8 */
        unsigned int r5_g2_time_snr_idx                               :   2               ;    /* 11:10 */
        unsigned int r6_g0_time_snr_idx                               :   2               ;    /* 13:12 */
        unsigned int r6_g1_time_snr_idx                               :   2               ;    /* 15:14 */
        unsigned int r6_g2_time_snr_idx                               :   2               ;    /* 17:16 */
        unsigned int r7_g0_time_snr_idx                               :   2               ;    /* 19:18 */
        unsigned int r7_g1_time_snr_idx                               :   2               ;    /* 21:20 */
        unsigned int r7_g2_time_snr_idx                               :   2               ;    /* 23:22 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB38;

typedef union {
    struct {
        unsigned int che_etype_flag                                   :   8               ;    /* 7:0 */
        unsigned int reserved_0                                       :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB39;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB0                        om_data0;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB1                        om_data1;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB2                        om_data2;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB3                        om_data3;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB4                        om_data4;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB5                        om_data5;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB6                        om_data6;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB7                        om_data7;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB8                        om_data8;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB9                        om_data9;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB10                       om_data10;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB11                       om_data11;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB12                       om_data12;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB13                       om_data13;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB14                       om_data14;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB15                       om_data15;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB16                       om_data16;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB17                       om_data17;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB18                       om_data18;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB19                       om_data19;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB20                       om_data20;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB21                       om_data21;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB22                       om_data22;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB23                       om_data23;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB24                       om_data24;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB25                       om_data25;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB26                       om_data26;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB27                       om_data27;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB28                       om_data28;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB29                       om_data29;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB30                       om_data30;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB31                       om_data31;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB32                       om_data32;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB33                       om_data33;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB34                       om_data34;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB35                       om_data35;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB36                       om_data36;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB37                       om_data37;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB38                       om_data38;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB39                       om_data39;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB0                        om_data0;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB1                        om_data1;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB2                        om_data2;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB3                        om_data3;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB4                        om_data4;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB5                        om_data5;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB6                        om_data6;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB7                        om_data7;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB8                        om_data8;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB9                        om_data9;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB10                       om_data10;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB11                       om_data11;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB12                       om_data12;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB13                       om_data13;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB14                       om_data14;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB15                       om_data15;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB16                       om_data16;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB17                       om_data17;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB18                       om_data18;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB19                       om_data19;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB20                       om_data20;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB21                       om_data21;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB22                       om_data22;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB23                       om_data23;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB24                       om_data24;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB25                       om_data25;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB26                       om_data26;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB27                       om_data27;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB28                       om_data28;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB29                       om_data29;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB30                       om_data30;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB31                       om_data31;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB32                       om_data32;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB33                       om_data33;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB34                       om_data34;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB35                       om_data35;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB36                       om_data36;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB37                       om_data37;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB38                       om_data38;
    DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_SUB39                       om_data39;
    unsigned int                                                      reserved_0;
    unsigned int                                                      reserved_1;
} DCICP_SID_DCICP_OM_INFO_CHE_DM_CONFIG_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      prb_bitmap0;
    unsigned int                                                      prb_bitmap1;
    unsigned int                                                      prb_bitmap2;
    unsigned int                                                      prb_bitmap3;
    unsigned int                                                      prb_bitmap4;
    unsigned int                                                      prb_bitmap5;
    unsigned int                                                      prb_bitmap6;
    unsigned int                                                      prb_bitmap7;
    unsigned int                                                      prb_bitmap8;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_INFO_CHE_VM_CONFIG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      prb_bitmap0;
    unsigned int                                                      prb_bitmap1;
    unsigned int                                                      prb_bitmap2;
    unsigned int                                                      prb_bitmap3;
    unsigned int                                                      prb_bitmap4;
    unsigned int                                                      prb_bitmap5;
    unsigned int                                                      prb_bitmap6;
    unsigned int                                                      prb_bitmap7;
    unsigned int                                                      prb_bitmap8;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_INFO_CHE_VM_CONFIG_BBP_MC;

typedef union {
    struct {
        unsigned int fpds_zp_csi_pat_num                              :   8               ;    /* 7:0 */
        unsigned int fpds_scs_flag                                    :   8               ;    /* 15:8 */
        unsigned int fpds_ch_bmp_idx                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB0;

typedef union {
    struct {
        unsigned int dmrs_sym_bitmap                                  :   16              ;    /* 15:0 */
        unsigned int bwp_bandwidth                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB1;

typedef union {
    struct {
        unsigned int fpds_ch_dem_r                                    :   16              ;    /* 15:0 */
        unsigned int fpds_sym_en                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB2;

typedef union {
    struct {
        unsigned int fpds_bmp_start_l                                 :   16              ;    /* 15:0 */
        unsigned int fpds_bmp_start_h                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB3;

typedef union {
    struct {
        unsigned int fpds_bmp_len_l                                   :   16              ;    /* 15:0 */
        unsigned int fpds_bmp_len_h                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB4;

typedef union {
    struct {
        unsigned int fpds_bf_rb_offset                                :   8               ;    /* 7:0 */
        unsigned int last_bd_flag                                     :   8               ;    /* 15:8 */
        unsigned int last_bd_start                                    :   8               ;    /* 23:16 */
        unsigned int first_flag                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB5;

typedef union {
    struct {
        unsigned int vrb_start                                        :   16              ;    /* 15:0 */
        unsigned int vrb_prb_bund                                     :   8               ;    /* 23:16 */
        unsigned int rx_flag                                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB6;

typedef union {
    struct {
        unsigned int time_qcl_pg0_ind                                 :   8               ;    /* 7:0 */
        unsigned int time_qcl_pg1_ind                                 :   8               ;    /* 15:8 */
        unsigned int time_qcl_pg2_ind                                 :   8               ;    /* 23:16 */
        unsigned int fpds_cdm_group_num                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB7;

typedef union {
    struct {
        unsigned int fpds_tcorr_sel_qcl0                              :   8               ;    /* 7:0 */
        unsigned int fpds_tcorr_doppler0_qcl0                         :   8               ;    /* 15:8 */
        unsigned int fpds_ch_w_fo0                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB8;

typedef union {
    struct {
        unsigned int fpds_tcorr_sel_qcl1                              :   8               ;    /* 7:0 */
        unsigned int fpds_tcorr_doppler0_qcl1                         :   8               ;    /* 15:8 */
        unsigned int fpds_ch_w_fo1                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB9;

typedef union {
    struct {
        unsigned int fpds_tcorr_sel_qcl_2dims0                        :   8               ;    /* 7:0 */
        unsigned int fpds_tcorr_doppler0_qcl_2dims0                   :   8               ;    /* 15:8 */
        unsigned int fpds_ch_w_fo_2dims0                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB10;

typedef union {
    struct {
        unsigned int fpds_tcorr_sel_qcl_2dims1                        :   8               ;    /* 7:0 */
        unsigned int fpds_tcorr_doppler0_qcl_2dims1                   :   8               ;    /* 15:8 */
        unsigned int fpds_ch_w_fo_2dims1                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB11;

typedef union {
    struct {
        unsigned int fpds_ch_typ                                      :   8               ;    /* 7:0 */
        unsigned int harq_cfg_idx                                     :   8               ;    /* 15:8 */
        unsigned int reseved0                                         :   8               ;    /* 23:16 */
        unsigned int fpds_cfg4_ch_flag                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB12;

typedef union {
    struct {
        unsigned int fpds_ch_dem_r1                                   :   16              ;    /* 15:0 */
        unsigned int fpds_bmp_offset                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB13;

typedef union {
    struct {
        unsigned int fpds_modu_level_select                           :   8               ;    /* 7:0 */
        unsigned int fpds_modu_level_avg                              :   8               ;    /* 15:8 */
        unsigned int interleave_en                                    :   8               ;    /* 23:16 */
        unsigned int fpds_fcross_tx_sel                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB14;

typedef union {
    struct {
        unsigned int fddl_llr0_mean_scale_cr_a1                       :   16              ;    /* 15:0 */
        unsigned int fddl_llr0_mean_scale_cr_a2                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB16;

typedef union {
    struct {
        unsigned int fpds_ncb_ch0_cw0                                 :   16              ;    /* 15:0 */
        unsigned int fpds_zc_ch0_cw0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB17;

typedef union {
    struct {
        unsigned int fpds_nfill_bit_ch0_cw0                           :   16              ;    /* 15:0 */
        unsigned int fpds_k_plus_ch0_cw0                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB18;

typedef union {
    struct {
        unsigned int fpds_k0_ch0_cw0                                  :   16              ;    /* 15:0 */
        unsigned int fpds_harq_retrans_num_cw0                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB19;

typedef union {
    struct {
        unsigned int fpds_harq_refresh_ch0_cw0                        :   8               ;    /* 7:0 */
        unsigned int fpds_c_sch_ch0_cw0                               :   8               ;    /* 15:8 */
        unsigned int fpds_c_real_ch0_cw0                              :   8               ;    /* 23:16 */
        unsigned int fdl_tb0_prc_idx                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB20;

typedef union {
    struct {
        unsigned int fpds_rv_ch0_cw0                                  :   8               ;    /* 7:0 */
        unsigned int fpds_bg_type_ch0_cw0                             :   8               ;    /* 15:8 */
        unsigned int fpds_kb_ch0_cw0                                  :   8               ;    /* 23:16 */
        unsigned int reseved1                                         :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB21;

typedef union {
    struct {
        unsigned int fddl_llr1_mean_scale_cr_a1                       :   16              ;    /* 15:0 */
        unsigned int fddl_llr1_mean_scale_cr_a2                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB23;

typedef union {
    struct {
        unsigned int fpds_ncb_ch0_cw1                                 :   16              ;    /* 15:0 */
        unsigned int fpds_zc_ch0_cw1                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB24;

typedef union {
    struct {
        unsigned int fpds_nfill_bit_ch0_cw1                           :   16              ;    /* 15:0 */
        unsigned int fpds_k_plus_ch0_cw1                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB25;

typedef union {
    struct {
        unsigned int fpds_k0_ch0_cw1                                  :   16              ;    /* 15:0 */
        unsigned int fpds_harq_retrans_num_cw1                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB26;

typedef union {
    struct {
        unsigned int fpds_harq_refresh_ch0_cw1                        :   8               ;    /* 7:0 */
        unsigned int fpds_c_sch_ch0_cw1                               :   8               ;    /* 15:8 */
        unsigned int fpds_c_real_ch0_cw1                              :   8               ;    /* 23:16 */
        unsigned int fdl_tb1_prc_idx                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB27;

typedef union {
    struct {
        unsigned int fpds_rv_ch0_cw1                                  :   8               ;    /* 7:0 */
        unsigned int fpds_bg_type_ch0_cw1                             :   8               ;    /* 15:8 */
        unsigned int fpds_kb_ch0_cw1                                  :   8               ;    /* 23:16 */
        unsigned int reseved2                                         :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB28;

typedef union {
    struct {
        unsigned int reseved3                                         :   16              ;    /* 15:0 */
        unsigned int fpds_pow_flag                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB29;

typedef union {
    struct {
        unsigned int fpds_pow_rowa                                    :   16              ;    /* 15:0 */
        unsigned int fpds_pow_rowb                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB30;

typedef union {
    struct {
        unsigned int fpds_ch0_cw_num                                  :   8               ;    /* 7:0 */
        unsigned int fpds_ch0_mode                                    :   8               ;    /* 15:8 */
        unsigned int fpds_ch1_mode                                    :   8               ;    /* 23:16 */
        unsigned int fpds_ch2_mode                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB31;

typedef union {
    struct {
        unsigned int fpds_ch0_cw0_mode                                :   8               ;    /* 7:0 */
        unsigned int fpds_ch0_cw1_mode                                :   8               ;    /* 15:8 */
        unsigned int fpds_ch1_cw_mode                                 :   8               ;    /* 23:16 */
        unsigned int fpds_ch2_cw_mode                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB32;

typedef union {
    struct {
        unsigned int fpds_ch0_cw0_mimo_layer                          :   8               ;    /* 7:0 */
        unsigned int fpds_ch0_cw1_mimo_layer                          :   8               ;    /* 15:8 */
        unsigned int mdci_mtrp_match_cfg                              :   8               ;    /* 23:16 */
        unsigned int dci_type                                         :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB33;

typedef union {
    struct {
        unsigned int fpds_llr_shift_ch0_table0                        :   4               ;    /* 3:0 */
        unsigned int fpds_llr_shift_ch0_table1                        :   4               ;    /* 7:4 */
        unsigned int fpds_llr_shift_ch0_table2                        :   4               ;    /* 11:8 */
        unsigned int fpds_llr_shift_ch0_table3                        :   4               ;    /* 15:12 */
        unsigned int fpds_llr_shift_ch0_table4                        :   4               ;    /* 19:16 */
        unsigned int fpds_llr_shift_ch0_table5                        :   4               ;    /* 23:20 */
        unsigned int fpds_llr_shift_ch0_table6                        :   4               ;    /* 27:24 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB34;

typedef union {
    struct {
        unsigned int fpds_llr_shift_th0                               :   5               ;    /* 4:0 */
        unsigned int fpds_llr_shift_th1                               :   5               ;    /* 9:5 */
        unsigned int fpds_llr_shift_th2                               :   5               ;    /* 14:10 */
        unsigned int fpds_llr_shift_th3                               :   5               ;    /* 19:15 */
        unsigned int fpds_llr_shift_th4                               :   5               ;    /* 24:20 */
        unsigned int fpds_llr_shift_th5                               :   5               ;    /* 29:25 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB35;

typedef union {
    struct {
        unsigned int fpds_llr_shift_table0_ch1                        :   4               ;    /* 3:0 */
        unsigned int fpds_llr_shift_table1_ch1                        :   4               ;    /* 7:4 */
        unsigned int fpds_llr_shift_table0_ch2                        :   4               ;    /* 11:8 */
        unsigned int fpds_llr_shift_table1_ch2                        :   4               ;    /* 15:12 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB36;

typedef union {
    struct {
        unsigned int fpds_llr_shift1_ch0_table0                       :   4               ;    /* 3:0 */
        unsigned int fpds_llr_shift1_ch0_table1                       :   4               ;    /* 7:4 */
        unsigned int fpds_llr_shift1_ch0_table2                       :   4               ;    /* 11:8 */
        unsigned int fpds_llr_shift1_ch0_table3                       :   4               ;    /* 15:12 */
        unsigned int fpds_llr_shift1_ch0_table4                       :   4               ;    /* 19:16 */
        unsigned int fpds_llr_shift1_ch0_table5                       :   4               ;    /* 23:20 */
        unsigned int fpds_llr_shift1_ch0_table6                       :   4               ;    /* 27:24 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB37;

typedef union {
    struct {
        unsigned int tcorr_power1                                     :   12              ;    /* 11:0 */
        unsigned int tcoef_pingpang_idx1                              :   1               ;    /* 12 */
        unsigned int dmrs_titp_snr_db_qp_sel1                         :   2               ;    /* 14:13 */
        unsigned int titp_unit_flag1                                  :   1               ;    /* 15 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB38;

typedef union {
    struct {
        unsigned int tcorr_power0                                     :   12              ;    /* 11:0 */
        unsigned int tcoef_pingpang_idx0                              :   1               ;    /* 12 */
        unsigned int dmrs_titp_snr_db_qp_sel0                         :   2               ;    /* 14:13 */
        unsigned int titp_unit_flag0                                  :   1               ;    /* 15 */
        unsigned int reserved_0                                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB39;

typedef union {
    struct {
        unsigned int fpds_nr_n_id0                                    :   16              ;    /* 15:0 */
        unsigned int fpds_nr_n_id1                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB40;

typedef union {
    struct {
        unsigned int ptrs_t_destiny                                   :   2               ;    /* 1:0 */
        unsigned int reserved_0                                       :   30              ;    /* 31:2 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB41;

typedef union {
    struct {
        unsigned int fpds_llr_shift_ch0_table0_cw1                    :   4               ;    /* 3:0 */
        unsigned int fpds_llr_shift_ch0_table1_cw1                    :   4               ;    /* 7:4 */
        unsigned int fpds_llr_shift_ch0_table2_cw1                    :   4               ;    /* 11:8 */
        unsigned int fpds_llr_shift_ch0_table3_cw1                    :   4               ;    /* 15:12 */
        unsigned int fpds_llr_shift_ch0_table4_cw1                    :   4               ;    /* 19:16 */
        unsigned int fpds_llr_shift_ch0_table5_cw1                    :   4               ;    /* 23:20 */
        unsigned int fpds_llr_shift_ch0_table6_cw1                    :   4               ;    /* 27:24 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB42;

typedef union {
    struct {
        unsigned int fpds_llr_shift_th0_cw1                           :   5               ;    /* 4:0 */
        unsigned int fpds_llr_shift_th1_cw1                           :   5               ;    /* 9:5 */
        unsigned int fpds_llr_shift_th2_cw1                           :   5               ;    /* 14:10 */
        unsigned int fpds_llr_shift_th3_cw1                           :   5               ;    /* 19:15 */
        unsigned int fpds_llr_shift_th4_cw1                           :   5               ;    /* 24:20 */
        unsigned int fpds_llr_shift_th5_cw1                           :   5               ;    /* 29:25 */
        unsigned int reserved_0                                       :   2               ;    /* 31:30 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB43;

typedef union {
    struct {
        unsigned int fpds_llr_shift1_ch0_table0_cw1                   :   4               ;    /* 3:0 */
        unsigned int fpds_llr_shift1_ch0_table1_cw1                   :   4               ;    /* 7:4 */
        unsigned int fpds_llr_shift1_ch0_table2_cw1                   :   4               ;    /* 11:8 */
        unsigned int fpds_llr_shift1_ch0_table3_cw1                   :   4               ;    /* 15:12 */
        unsigned int fpds_llr_shift1_ch0_table4_cw1                   :   4               ;    /* 19:16 */
        unsigned int fpds_llr_shift1_ch0_table5_cw1                   :   4               ;    /* 23:20 */
        unsigned int fpds_llr_shift1_ch0_table6_cw1                   :   4               ;    /* 27:24 */
        unsigned int reserved_0                                       :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB44;

typedef union {
    struct {
        unsigned int fpds_cfg_done                                    :   8               ;    /* 7:0 */
        unsigned int sat_net_flag                                     :   1               ;    /* 8 */
        unsigned int reserved_0                                       :   23              ;    /* 31:9 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB45;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB0                        om_data0;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB1                        om_data1;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB2                        om_data2;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB3                        om_data3;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB4                        om_data4;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB5                        om_data5;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB6                        om_data6;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB7                        om_data7;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB8                        om_data8;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB9                        om_data9;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB10                       om_data10;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB11                       om_data11;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB12                       om_data12;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB13                       om_data13;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB14                       om_data14;
    unsigned int                                                      fpds_b_crc_ch0_cw0;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB16                       om_data16;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB17                       om_data17;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB18                       om_data18;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB19                       om_data19;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB20                       om_data20;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB21                       om_data21;
    unsigned int                                                      fpds_b_crc_ch0_cw1;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB23                       om_data23;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB24                       om_data24;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB25                       om_data25;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB26                       om_data26;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB27                       om_data27;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB28                       om_data28;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB29                       om_data29;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB30                       om_data30;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB31                       om_data31;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB32                       om_data32;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB33                       om_data33;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB34                       om_data34;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB35                       om_data35;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB36                       om_data36;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB37                       om_data37;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB38                       om_data38;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB39                       om_data39;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB40                       om_data40;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB41                       om_data41;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB42                       om_data42;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB43                       om_data43;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB44                       om_data44;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB45                       om_data45;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB0                        om_data0;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB1                        om_data1;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB2                        om_data2;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB3                        om_data3;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB4                        om_data4;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB5                        om_data5;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB6                        om_data6;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB7                        om_data7;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB8                        om_data8;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB9                        om_data9;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB10                       om_data10;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB11                       om_data11;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB12                       om_data12;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB13                       om_data13;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB14                       om_data14;
    unsigned int                                                      fpds_b_crc_ch0_cw0;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB16                       om_data16;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB17                       om_data17;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB18                       om_data18;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB19                       om_data19;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB20                       om_data20;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB21                       om_data21;
    unsigned int                                                      fpds_b_crc_ch0_cw1;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB23                       om_data23;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB24                       om_data24;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB25                       om_data25;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB26                       om_data26;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB27                       om_data27;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB28                       om_data28;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB29                       om_data29;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB30                       om_data30;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB31                       om_data31;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB32                       om_data32;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB33                       om_data33;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB34                       om_data34;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB35                       om_data35;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB36                       om_data36;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB37                       om_data37;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB38                       om_data38;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB39                       om_data39;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB40                       om_data40;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB41                       om_data41;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB42                       om_data42;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB43                       om_data43;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB44                       om_data44;
    DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_SUB45                       om_data45;
} DCICP_SID_DCICP_OM_INFO_PDS_DM_CONFIG_BBP_MC;

typedef union {
    struct {
        unsigned int fpds_corset_ch_sym_en                            :   16              ;    /* 15:0 */
        unsigned int fpds_pdc_dmrs_ch_sym_en                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB0;

typedef union {
    struct {
        unsigned int fpds_zpcsi_sym_en_rs0                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_sym_en_rs1                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB1;

typedef union {
    struct {
        unsigned int fpds_zpcsi_sym_en_rs2                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_sym_en_rs3                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB2;

typedef union {
    struct {
        unsigned int fpds_zpcsi_sym_en_rs4                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_sym_en_rs5                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB3;

typedef union {
    struct {
        unsigned int fpds_zpcsi_sym_en_rs6                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_sym_en_rs7                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB4;

typedef union {
    struct {
        unsigned int fpds_zpcsi_sym_en_rs8                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_sym_en_rs9                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB5;

typedef union {
    struct {
        unsigned int fpds_zpcsi_sym_en_rs10                           :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_sym_en_rs11                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB6;

typedef union {
    struct {
        unsigned int fpds_zpcsi_sym_en_rs12                           :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_sym_en_rs13                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB7;

typedef union {
    struct {
        unsigned int fpds_zpcsi_sym_en_rs14                           :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_sym_en_rs15                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB8;

typedef union {
    struct {
        unsigned int fpds_corset_ch_re_en                             :   16              ;    /* 15:0 */
        unsigned int fpds_pdc_dmrs_ch_re_en                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB9;

typedef union {
    struct {
        unsigned int fpds_zpcsi_re_en_rs0                             :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_re_en_rs1                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB10;

typedef union {
    struct {
        unsigned int fpds_zpcsi_re_en_rs2                             :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_re_en_rs3                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB11;

typedef union {
    struct {
        unsigned int fpds_zpcsi_re_en_rs4                             :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_re_en_rs5                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB12;

typedef union {
    struct {
        unsigned int fpds_zpcsi_re_en_rs6                             :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_re_en_rs7                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB13;

typedef union {
    struct {
        unsigned int fpds_zpcsi_re_en_rs8                             :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_re_en_rs9                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB14;

typedef union {
    struct {
        unsigned int fpds_zpcsi_re_en_rs10                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_re_en_rs11                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB15;

typedef union {
    struct {
        unsigned int fpds_zpcsi_re_en_rs12                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_re_en_rs13                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB16;

typedef union {
    struct {
        unsigned int fpds_zpcsi_re_en_rs14                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_re_en_rs15                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB17;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_start_rs0                          :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_start_rs1                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB18;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_start_rs2                          :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_start_rs3                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB19;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_start_rs4                          :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_start_rs5                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB20;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_start_rs6                          :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_start_rs7                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB21;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_start_rs8                          :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_start_rs9                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB22;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_start_rs10                         :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_start_rs11                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB23;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_start_rs12                         :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_start_rs13                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB24;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_start_rs14                         :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_start_rs15                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB25;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_len_rs0                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_len_rs1                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB26;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_len_rs2                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_len_rs3                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB27;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_len_rs4                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_len_rs5                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB28;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_len_rs6                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_len_rs7                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB29;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_len_rs8                            :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_len_rs9                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB30;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_len_rs10                           :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_len_rs11                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB31;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_len_rs12                           :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_len_rs13                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB32;

typedef union {
    struct {
        unsigned int fpds_zpcsi_rb_len_rs14                           :   16              ;    /* 15:0 */
        unsigned int fpds_zpcsi_rb_len_rs15                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB33;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB0                        om_data0;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB1                        om_data1;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB2                        om_data2;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB3                        om_data3;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB4                        om_data4;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB5                        om_data5;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB6                        om_data6;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB7                        om_data7;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB8                        om_data8;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB9                        om_data9;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB10                       om_data10;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB11                       om_data11;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB12                       om_data12;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB13                       om_data13;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB14                       om_data14;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB15                       om_data15;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB16                       om_data16;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB17                       om_data17;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB18                       om_data18;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB19                       om_data19;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB20                       om_data20;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB21                       om_data21;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB22                       om_data22;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB23                       om_data23;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB24                       om_data24;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB25                       om_data25;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB26                       om_data26;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB27                       om_data27;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB28                       om_data28;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB29                       om_data29;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB30                       om_data30;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB31                       om_data31;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB32                       om_data32;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB33                       om_data33;
    unsigned int                                                      fpds_corset_ch_rb_en0;
    unsigned int                                                      fpds_corset_ch_rb_en1;
    unsigned int                                                      fpds_corset_ch_rb_en2;
    unsigned int                                                      fpds_corset_ch_rb_en3;
    unsigned int                                                      fpds_corset_ch_rb_en4;
    unsigned int                                                      fpds_corset_ch_rb_en5;
    unsigned int                                                      fpds_corset_ch_rb_en6;
    unsigned int                                                      fpds_corset_ch_rb_en7;
    unsigned int                                                      fpds_corset_ch_rb_en8;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en0;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en1;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en2;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en3;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en4;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en5;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en6;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en7;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en8;
    unsigned int                                                      fpds_zpcsi_rb_gap;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB0                        om_data0;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB1                        om_data1;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB2                        om_data2;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB3                        om_data3;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB4                        om_data4;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB5                        om_data5;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB6                        om_data6;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB7                        om_data7;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB8                        om_data8;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB9                        om_data9;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB10                       om_data10;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB11                       om_data11;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB12                       om_data12;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB13                       om_data13;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB14                       om_data14;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB15                       om_data15;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB16                       om_data16;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB17                       om_data17;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB18                       om_data18;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB19                       om_data19;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB20                       om_data20;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB21                       om_data21;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB22                       om_data22;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB23                       om_data23;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB24                       om_data24;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB25                       om_data25;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB26                       om_data26;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB27                       om_data27;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB28                       om_data28;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB29                       om_data29;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB30                       om_data30;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB31                       om_data31;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB32                       om_data32;
    DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_SUB33                       om_data33;
    unsigned int                                                      fpds_corset_ch_rb_en0;
    unsigned int                                                      fpds_corset_ch_rb_en1;
    unsigned int                                                      fpds_corset_ch_rb_en2;
    unsigned int                                                      fpds_corset_ch_rb_en3;
    unsigned int                                                      fpds_corset_ch_rb_en4;
    unsigned int                                                      fpds_corset_ch_rb_en5;
    unsigned int                                                      fpds_corset_ch_rb_en6;
    unsigned int                                                      fpds_corset_ch_rb_en7;
    unsigned int                                                      fpds_corset_ch_rb_en8;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en0;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en1;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en2;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en3;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en4;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en5;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en6;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en7;
    unsigned int                                                      fpds_pdc_dmrs_ch_rb_en8;
    unsigned int                                                      fpds_zpcsi_rb_gap;
    unsigned int                                                      reserved_0;
} DCICP_SID_DCICP_OM_INFO_PDS_VM_CONFIG_BBP_MC;

typedef union {
    struct {
        unsigned int arr0_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr0_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr0_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr0_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB0;

typedef union {
    struct {
        unsigned int arr0_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr0_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr0_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr0_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB1;

typedef union {
    struct {
        unsigned int arr0_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr0_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr0_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr0_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB3;

typedef union {
    struct {
        unsigned int arr0_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr0_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr0_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr0_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB4;

typedef union {
    struct {
        unsigned int arr0_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr0_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr0_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr0_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB5;

typedef union {
    struct {
        unsigned int arr0_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr0_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr0_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr0_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB6;

typedef union {
    struct {
        unsigned int arr0_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr0_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr0_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr0_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB7;

typedef union {
    struct {
        unsigned int arr0_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr0_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr0_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr0_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB8;

typedef union {
    struct {
        unsigned int arr0_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr0_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr0_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr0_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB9;

typedef union {
    struct {
        unsigned int arr0_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr0_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr0_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr0_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB10;

typedef union {
    struct {
        unsigned int arr0_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr0_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr0_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr0_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB11;

typedef union {
    struct {
        unsigned int arr0_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr0_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr0_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr0_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB12;

typedef union {
    struct {
        unsigned int arr0_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr0_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr0_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr0_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB13;

typedef union {
    struct {
        unsigned int arr0_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr0_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr0_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr0_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr0_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB14;

typedef union {
    struct {
        unsigned int arr0_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr0_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr0_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr0_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB15;

typedef union {
    struct {
        unsigned int arr0_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr0_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr0_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr0_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB16;

typedef union {
    struct {
        unsigned int arr0_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr0_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr0_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr0_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB17;

typedef union {
    struct {
        unsigned int arr0_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr0_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr0_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB18;

typedef union {
    struct {
        unsigned int arr0_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr0_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr0_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB19;

typedef union {
    struct {
        unsigned int arr0_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr0_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr0_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB20;

typedef union {
    struct {
        unsigned int arr0_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr0_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr0_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB21;

typedef union {
    struct {
        unsigned int arr0_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr0_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB22;

typedef union {
    struct {
        unsigned int arr0_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr0_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr0_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr0_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB23;

typedef union {
    struct {
        unsigned int arr0_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr0_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr0_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB24;

typedef union {
    struct {
        unsigned int arr0_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr0_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr0_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB25;

typedef union {
    struct {
        unsigned int arr0_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr0_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr0_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB27;

typedef union {
    struct {
        unsigned int arr0_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr0_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr0_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB28;

typedef union {
    struct {
        unsigned int arr0_celset_id                                   :   2               ;    /* 1:0 */
        unsigned int arr0_comb_idx                                    :   4               ;    /* 5:2 */
        unsigned int arr0_scheduled_cfg_idx                           :   5               ;    /* 10:6 */
        unsigned int arr0_reserved_0                                  :   6               ;    /* 16:11 */
        unsigned int arr0_scheduling_cfg_bwp_idx                      :   3               ;    /* 19:17 */
        unsigned int arr0_cfg_bwp_idx0                                :   3               ;    /* 22:20 */
        unsigned int arr0_cfg_bwp_idx1                                :   3               ;    /* 25:23 */
        unsigned int arr0_cfg_bwp_idx2                                :   3               ;    /* 28:26 */
        unsigned int arr0_cfg_bwp_idx3                                :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB30;

typedef union {
    struct {
        unsigned int arr0_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr0_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr0_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB31;

typedef union {
    struct {
        unsigned int arr1_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr1_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr1_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr1_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB38;

typedef union {
    struct {
        unsigned int arr1_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr1_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr1_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr1_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB39;

typedef union {
    struct {
        unsigned int arr1_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr1_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr1_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr1_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB41;

typedef union {
    struct {
        unsigned int arr1_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr1_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr1_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr1_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB42;

typedef union {
    struct {
        unsigned int arr1_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr1_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr1_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr1_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB43;

typedef union {
    struct {
        unsigned int arr1_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr1_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr1_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr1_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB44;

typedef union {
    struct {
        unsigned int arr1_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr1_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr1_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr1_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB45;

typedef union {
    struct {
        unsigned int arr1_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr1_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr1_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr1_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB46;

typedef union {
    struct {
        unsigned int arr1_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr1_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr1_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr1_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB47;

typedef union {
    struct {
        unsigned int arr1_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr1_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr1_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr1_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB48;

typedef union {
    struct {
        unsigned int arr1_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr1_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr1_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr1_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB49;

typedef union {
    struct {
        unsigned int arr1_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr1_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr1_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr1_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB50;

typedef union {
    struct {
        unsigned int arr1_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr1_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr1_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr1_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB51;

typedef union {
    struct {
        unsigned int arr1_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr1_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr1_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr1_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr1_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB52;

typedef union {
    struct {
        unsigned int arr1_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr1_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr1_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr1_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB53;

typedef union {
    struct {
        unsigned int arr1_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr1_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr1_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr1_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB54;

typedef union {
    struct {
        unsigned int arr1_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr1_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr1_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr1_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB55;

typedef union {
    struct {
        unsigned int arr1_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr1_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr1_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB56;

typedef union {
    struct {
        unsigned int arr1_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr1_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr1_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB57;

typedef union {
    struct {
        unsigned int arr1_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr1_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr1_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB58;

typedef union {
    struct {
        unsigned int arr1_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr1_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr1_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB59;

typedef union {
    struct {
        unsigned int arr1_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr1_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB60;

typedef union {
    struct {
        unsigned int arr1_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr1_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr1_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr1_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB61;

typedef union {
    struct {
        unsigned int arr1_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr1_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr1_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB62;

typedef union {
    struct {
        unsigned int arr1_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr1_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr1_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB63;

typedef union {
    struct {
        unsigned int arr1_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr1_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr1_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB65;

typedef union {
    struct {
        unsigned int arr1_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr1_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr1_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB66;

typedef union {
    struct {
        unsigned int arr1_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr1_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr1_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB69;

typedef union {
    struct {
        unsigned int arr2_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr2_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr2_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr2_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB76;

typedef union {
    struct {
        unsigned int arr2_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr2_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr2_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr2_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB77;

typedef union {
    struct {
        unsigned int arr2_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr2_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr2_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr2_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB79;

typedef union {
    struct {
        unsigned int arr2_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr2_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr2_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr2_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB80;

typedef union {
    struct {
        unsigned int arr2_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr2_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr2_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr2_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB81;

typedef union {
    struct {
        unsigned int arr2_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr2_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr2_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr2_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB82;

typedef union {
    struct {
        unsigned int arr2_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr2_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr2_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr2_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB83;

typedef union {
    struct {
        unsigned int arr2_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr2_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr2_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr2_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB84;

typedef union {
    struct {
        unsigned int arr2_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr2_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr2_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr2_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB85;

typedef union {
    struct {
        unsigned int arr2_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr2_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr2_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr2_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB86;

typedef union {
    struct {
        unsigned int arr2_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr2_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr2_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr2_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB87;

typedef union {
    struct {
        unsigned int arr2_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr2_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr2_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr2_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB88;

typedef union {
    struct {
        unsigned int arr2_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr2_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr2_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr2_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB89;

typedef union {
    struct {
        unsigned int arr2_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr2_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr2_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr2_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr2_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB90;

typedef union {
    struct {
        unsigned int arr2_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr2_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr2_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr2_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB91;

typedef union {
    struct {
        unsigned int arr2_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr2_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr2_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr2_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB92;

typedef union {
    struct {
        unsigned int arr2_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr2_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr2_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr2_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB93;

typedef union {
    struct {
        unsigned int arr2_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr2_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr2_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB94;

typedef union {
    struct {
        unsigned int arr2_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr2_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr2_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB95;

typedef union {
    struct {
        unsigned int arr2_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr2_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr2_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB96;

typedef union {
    struct {
        unsigned int arr2_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr2_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr2_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB97;

typedef union {
    struct {
        unsigned int arr2_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr2_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB98;

typedef union {
    struct {
        unsigned int arr2_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr2_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr2_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr2_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB99;

typedef union {
    struct {
        unsigned int arr2_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr2_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr2_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB100;

typedef union {
    struct {
        unsigned int arr2_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr2_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr2_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB101;

typedef union {
    struct {
        unsigned int arr2_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr2_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr2_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB103;

typedef union {
    struct {
        unsigned int arr2_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr2_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr2_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB104;

typedef union {
    struct {
        unsigned int arr2_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr2_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr2_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB107;

typedef union {
    struct {
        unsigned int arr3_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr3_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr3_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr3_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB114;

typedef union {
    struct {
        unsigned int arr3_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr3_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr3_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr3_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB115;

typedef union {
    struct {
        unsigned int arr3_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr3_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr3_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr3_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB117;

typedef union {
    struct {
        unsigned int arr3_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr3_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr3_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr3_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB118;

typedef union {
    struct {
        unsigned int arr3_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr3_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr3_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr3_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB119;

typedef union {
    struct {
        unsigned int arr3_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr3_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr3_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr3_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB120;

typedef union {
    struct {
        unsigned int arr3_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr3_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr3_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr3_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB121;

typedef union {
    struct {
        unsigned int arr3_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr3_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr3_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr3_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB122;

typedef union {
    struct {
        unsigned int arr3_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr3_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr3_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr3_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB123;

typedef union {
    struct {
        unsigned int arr3_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr3_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr3_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr3_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB124;

typedef union {
    struct {
        unsigned int arr3_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr3_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr3_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr3_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB125;

typedef union {
    struct {
        unsigned int arr3_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr3_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr3_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr3_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB126;

typedef union {
    struct {
        unsigned int arr3_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr3_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr3_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr3_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB127;

typedef union {
    struct {
        unsigned int arr3_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr3_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr3_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr3_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr3_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB128;

typedef union {
    struct {
        unsigned int arr3_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr3_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr3_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr3_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB129;

typedef union {
    struct {
        unsigned int arr3_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr3_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr3_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr3_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB130;

typedef union {
    struct {
        unsigned int arr3_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr3_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr3_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr3_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB131;

typedef union {
    struct {
        unsigned int arr3_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr3_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr3_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB132;

typedef union {
    struct {
        unsigned int arr3_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr3_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr3_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB133;

typedef union {
    struct {
        unsigned int arr3_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr3_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr3_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB134;

typedef union {
    struct {
        unsigned int arr3_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr3_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr3_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB135;

typedef union {
    struct {
        unsigned int arr3_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr3_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB136;

typedef union {
    struct {
        unsigned int arr3_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr3_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr3_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr3_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB137;

typedef union {
    struct {
        unsigned int arr3_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr3_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr3_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB138;

typedef union {
    struct {
        unsigned int arr3_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr3_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr3_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB139;

typedef union {
    struct {
        unsigned int arr3_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr3_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr3_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB141;

typedef union {
    struct {
        unsigned int arr3_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr3_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr3_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB142;

typedef union {
    struct {
        unsigned int arr3_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr3_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr3_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB145;

typedef union {
    struct {
        unsigned int arr4_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr4_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr4_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr4_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB152;

typedef union {
    struct {
        unsigned int arr4_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr4_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr4_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr4_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB153;

typedef union {
    struct {
        unsigned int arr4_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr4_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr4_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr4_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB155;

typedef union {
    struct {
        unsigned int arr4_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr4_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr4_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr4_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB156;

typedef union {
    struct {
        unsigned int arr4_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr4_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr4_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr4_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB157;

typedef union {
    struct {
        unsigned int arr4_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr4_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr4_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr4_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB158;

typedef union {
    struct {
        unsigned int arr4_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr4_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr4_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr4_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB159;

typedef union {
    struct {
        unsigned int arr4_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr4_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr4_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr4_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB160;

typedef union {
    struct {
        unsigned int arr4_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr4_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr4_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr4_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB161;

typedef union {
    struct {
        unsigned int arr4_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr4_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr4_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr4_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB162;

typedef union {
    struct {
        unsigned int arr4_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr4_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr4_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr4_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB163;

typedef union {
    struct {
        unsigned int arr4_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr4_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr4_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr4_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB164;

typedef union {
    struct {
        unsigned int arr4_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr4_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr4_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr4_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB165;

typedef union {
    struct {
        unsigned int arr4_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr4_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr4_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr4_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr4_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB166;

typedef union {
    struct {
        unsigned int arr4_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr4_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr4_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr4_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB167;

typedef union {
    struct {
        unsigned int arr4_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr4_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr4_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr4_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB168;

typedef union {
    struct {
        unsigned int arr4_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr4_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr4_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr4_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB169;

typedef union {
    struct {
        unsigned int arr4_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr4_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr4_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB170;

typedef union {
    struct {
        unsigned int arr4_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr4_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr4_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB171;

typedef union {
    struct {
        unsigned int arr4_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr4_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr4_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB172;

typedef union {
    struct {
        unsigned int arr4_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr4_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr4_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB173;

typedef union {
    struct {
        unsigned int arr4_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr4_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB174;

typedef union {
    struct {
        unsigned int arr4_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr4_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr4_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr4_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB175;

typedef union {
    struct {
        unsigned int arr4_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr4_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr4_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB176;

typedef union {
    struct {
        unsigned int arr4_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr4_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr4_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB177;

typedef union {
    struct {
        unsigned int arr4_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr4_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr4_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB179;

typedef union {
    struct {
        unsigned int arr4_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr4_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr4_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB180;

typedef union {
    struct {
        unsigned int arr4_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr4_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr4_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB183;

typedef union {
    struct {
        unsigned int arr5_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr5_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr5_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr5_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB190;

typedef union {
    struct {
        unsigned int arr5_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr5_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr5_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr5_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB191;

typedef union {
    struct {
        unsigned int arr5_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr5_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr5_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr5_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB193;

typedef union {
    struct {
        unsigned int arr5_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr5_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr5_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr5_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB194;

typedef union {
    struct {
        unsigned int arr5_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr5_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr5_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr5_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB195;

typedef union {
    struct {
        unsigned int arr5_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr5_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr5_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr5_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB196;

typedef union {
    struct {
        unsigned int arr5_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr5_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr5_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr5_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB197;

typedef union {
    struct {
        unsigned int arr5_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr5_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr5_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr5_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB198;

typedef union {
    struct {
        unsigned int arr5_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr5_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr5_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr5_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB199;

typedef union {
    struct {
        unsigned int arr5_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr5_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr5_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr5_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB200;

typedef union {
    struct {
        unsigned int arr5_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr5_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr5_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr5_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB201;

typedef union {
    struct {
        unsigned int arr5_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr5_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr5_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr5_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB202;

typedef union {
    struct {
        unsigned int arr5_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr5_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr5_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr5_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB203;

typedef union {
    struct {
        unsigned int arr5_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr5_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr5_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr5_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr5_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB204;

typedef union {
    struct {
        unsigned int arr5_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr5_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr5_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr5_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB205;

typedef union {
    struct {
        unsigned int arr5_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr5_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr5_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr5_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB206;

typedef union {
    struct {
        unsigned int arr5_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr5_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr5_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr5_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB207;

typedef union {
    struct {
        unsigned int arr5_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr5_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr5_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB208;

typedef union {
    struct {
        unsigned int arr5_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr5_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr5_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB209;

typedef union {
    struct {
        unsigned int arr5_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr5_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr5_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB210;

typedef union {
    struct {
        unsigned int arr5_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr5_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr5_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB211;

typedef union {
    struct {
        unsigned int arr5_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr5_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB212;

typedef union {
    struct {
        unsigned int arr5_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr5_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr5_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr5_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB213;

typedef union {
    struct {
        unsigned int arr5_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr5_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr5_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB214;

typedef union {
    struct {
        unsigned int arr5_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr5_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr5_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB215;

typedef union {
    struct {
        unsigned int arr5_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr5_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr5_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB217;

typedef union {
    struct {
        unsigned int arr5_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr5_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr5_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB218;

typedef union {
    struct {
        unsigned int arr5_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr5_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr5_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB221;

typedef union {
    struct {
        unsigned int arr6_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr6_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr6_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr6_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB228;

typedef union {
    struct {
        unsigned int arr6_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr6_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr6_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr6_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB229;

typedef union {
    struct {
        unsigned int arr6_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr6_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr6_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr6_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB231;

typedef union {
    struct {
        unsigned int arr6_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr6_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr6_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr6_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB232;

typedef union {
    struct {
        unsigned int arr6_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr6_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr6_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr6_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB233;

typedef union {
    struct {
        unsigned int arr6_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr6_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr6_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr6_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB234;

typedef union {
    struct {
        unsigned int arr6_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr6_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr6_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr6_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB235;

typedef union {
    struct {
        unsigned int arr6_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr6_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr6_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr6_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB236;

typedef union {
    struct {
        unsigned int arr6_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr6_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr6_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr6_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB237;

typedef union {
    struct {
        unsigned int arr6_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr6_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr6_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr6_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB238;

typedef union {
    struct {
        unsigned int arr6_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr6_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr6_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr6_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB239;

typedef union {
    struct {
        unsigned int arr6_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr6_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr6_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr6_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB240;

typedef union {
    struct {
        unsigned int arr6_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr6_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr6_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr6_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB241;

typedef union {
    struct {
        unsigned int arr6_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr6_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr6_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr6_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr6_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB242;

typedef union {
    struct {
        unsigned int arr6_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr6_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr6_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr6_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB243;

typedef union {
    struct {
        unsigned int arr6_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr6_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr6_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr6_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB244;

typedef union {
    struct {
        unsigned int arr6_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr6_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr6_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr6_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB245;

typedef union {
    struct {
        unsigned int arr6_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr6_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr6_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB246;

typedef union {
    struct {
        unsigned int arr6_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr6_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr6_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB247;

typedef union {
    struct {
        unsigned int arr6_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr6_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr6_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB248;

typedef union {
    struct {
        unsigned int arr6_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr6_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr6_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB249;

typedef union {
    struct {
        unsigned int arr6_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr6_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB250;

typedef union {
    struct {
        unsigned int arr6_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr6_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr6_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr6_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB251;

typedef union {
    struct {
        unsigned int arr6_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr6_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr6_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB252;

typedef union {
    struct {
        unsigned int arr6_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr6_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr6_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB253;

typedef union {
    struct {
        unsigned int arr6_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr6_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr6_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB255;

typedef union {
    struct {
        unsigned int arr6_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr6_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr6_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB256;

typedef union {
    struct {
        unsigned int arr6_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr6_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr6_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB259;

typedef union {
    struct {
        unsigned int arr7_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr7_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr7_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr7_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB266;

typedef union {
    struct {
        unsigned int arr7_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr7_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr7_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr7_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB267;

typedef union {
    struct {
        unsigned int arr7_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr7_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr7_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr7_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB269;

typedef union {
    struct {
        unsigned int arr7_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr7_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr7_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr7_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB270;

typedef union {
    struct {
        unsigned int arr7_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr7_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr7_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr7_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB271;

typedef union {
    struct {
        unsigned int arr7_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr7_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr7_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr7_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB272;

typedef union {
    struct {
        unsigned int arr7_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr7_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr7_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr7_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB273;

typedef union {
    struct {
        unsigned int arr7_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr7_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr7_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr7_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB274;

typedef union {
    struct {
        unsigned int arr7_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr7_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr7_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr7_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB275;

typedef union {
    struct {
        unsigned int arr7_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr7_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr7_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr7_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB276;

typedef union {
    struct {
        unsigned int arr7_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr7_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr7_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr7_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB277;

typedef union {
    struct {
        unsigned int arr7_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr7_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr7_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr7_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB278;

typedef union {
    struct {
        unsigned int arr7_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr7_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr7_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr7_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB279;

typedef union {
    struct {
        unsigned int arr7_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr7_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr7_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr7_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr7_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB280;

typedef union {
    struct {
        unsigned int arr7_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr7_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr7_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr7_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB281;

typedef union {
    struct {
        unsigned int arr7_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr7_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr7_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr7_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB282;

typedef union {
    struct {
        unsigned int arr7_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr7_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr7_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr7_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB283;

typedef union {
    struct {
        unsigned int arr7_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr7_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr7_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB284;

typedef union {
    struct {
        unsigned int arr7_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr7_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr7_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB285;

typedef union {
    struct {
        unsigned int arr7_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr7_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr7_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB286;

typedef union {
    struct {
        unsigned int arr7_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr7_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr7_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB287;

typedef union {
    struct {
        unsigned int arr7_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr7_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB288;

typedef union {
    struct {
        unsigned int arr7_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr7_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr7_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr7_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB289;

typedef union {
    struct {
        unsigned int arr7_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr7_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr7_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB290;

typedef union {
    struct {
        unsigned int arr7_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr7_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr7_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB291;

typedef union {
    struct {
        unsigned int arr7_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr7_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr7_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB293;

typedef union {
    struct {
        unsigned int arr7_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr7_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr7_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB294;

typedef union {
    struct {
        unsigned int arr7_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr7_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr7_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB297;

typedef union {
    struct {
        unsigned int arr8_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr8_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr8_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr8_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB304;

typedef union {
    struct {
        unsigned int arr8_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr8_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr8_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr8_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB305;

typedef union {
    struct {
        unsigned int arr8_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr8_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr8_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr8_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB307;

typedef union {
    struct {
        unsigned int arr8_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr8_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr8_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr8_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB308;

typedef union {
    struct {
        unsigned int arr8_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr8_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr8_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr8_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB309;

typedef union {
    struct {
        unsigned int arr8_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr8_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr8_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr8_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB310;

typedef union {
    struct {
        unsigned int arr8_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr8_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr8_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr8_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB311;

typedef union {
    struct {
        unsigned int arr8_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr8_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr8_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr8_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB312;

typedef union {
    struct {
        unsigned int arr8_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr8_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr8_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr8_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB313;

typedef union {
    struct {
        unsigned int arr8_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr8_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr8_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr8_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB314;

typedef union {
    struct {
        unsigned int arr8_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr8_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr8_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr8_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB315;

typedef union {
    struct {
        unsigned int arr8_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr8_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr8_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr8_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB316;

typedef union {
    struct {
        unsigned int arr8_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr8_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr8_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr8_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB317;

typedef union {
    struct {
        unsigned int arr8_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr8_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr8_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr8_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr8_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB318;

typedef union {
    struct {
        unsigned int arr8_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr8_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr8_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr8_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB319;

typedef union {
    struct {
        unsigned int arr8_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr8_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr8_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr8_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB320;

typedef union {
    struct {
        unsigned int arr8_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr8_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr8_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr8_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB321;

typedef union {
    struct {
        unsigned int arr8_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr8_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr8_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB322;

typedef union {
    struct {
        unsigned int arr8_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr8_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr8_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB323;

typedef union {
    struct {
        unsigned int arr8_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr8_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr8_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB324;

typedef union {
    struct {
        unsigned int arr8_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr8_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr8_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB325;

typedef union {
    struct {
        unsigned int arr8_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr8_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB326;

typedef union {
    struct {
        unsigned int arr8_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr8_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr8_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr8_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB327;

typedef union {
    struct {
        unsigned int arr8_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr8_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr8_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB328;

typedef union {
    struct {
        unsigned int arr8_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr8_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr8_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB329;

typedef union {
    struct {
        unsigned int arr8_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr8_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr8_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB331;

typedef union {
    struct {
        unsigned int arr8_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr8_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr8_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB332;

typedef union {
    struct {
        unsigned int arr8_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr8_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr8_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB335;

typedef union {
    struct {
        unsigned int arr9_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr9_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr9_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr9_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB342;

typedef union {
    struct {
        unsigned int arr9_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr9_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr9_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr9_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB343;

typedef union {
    struct {
        unsigned int arr9_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr9_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr9_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr9_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB345;

typedef union {
    struct {
        unsigned int arr9_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr9_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr9_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr9_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB346;

typedef union {
    struct {
        unsigned int arr9_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr9_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr9_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr9_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB347;

typedef union {
    struct {
        unsigned int arr9_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr9_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr9_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr9_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB348;

typedef union {
    struct {
        unsigned int arr9_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr9_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr9_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr9_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB349;

typedef union {
    struct {
        unsigned int arr9_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr9_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr9_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr9_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB350;

typedef union {
    struct {
        unsigned int arr9_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr9_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr9_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr9_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB351;

typedef union {
    struct {
        unsigned int arr9_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr9_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr9_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr9_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB352;

typedef union {
    struct {
        unsigned int arr9_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr9_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr9_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr9_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB353;

typedef union {
    struct {
        unsigned int arr9_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr9_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr9_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr9_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB354;

typedef union {
    struct {
        unsigned int arr9_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr9_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr9_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr9_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB355;

typedef union {
    struct {
        unsigned int arr9_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr9_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr9_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr9_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr9_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB356;

typedef union {
    struct {
        unsigned int arr9_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr9_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr9_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr9_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB357;

typedef union {
    struct {
        unsigned int arr9_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr9_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr9_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr9_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB358;

typedef union {
    struct {
        unsigned int arr9_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr9_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr9_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr9_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB359;

typedef union {
    struct {
        unsigned int arr9_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr9_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr9_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB360;

typedef union {
    struct {
        unsigned int arr9_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr9_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr9_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB361;

typedef union {
    struct {
        unsigned int arr9_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr9_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr9_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB362;

typedef union {
    struct {
        unsigned int arr9_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr9_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr9_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB363;

typedef union {
    struct {
        unsigned int arr9_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr9_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB364;

typedef union {
    struct {
        unsigned int arr9_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr9_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr9_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr9_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB365;

typedef union {
    struct {
        unsigned int arr9_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr9_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr9_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB366;

typedef union {
    struct {
        unsigned int arr9_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr9_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr9_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB367;

typedef union {
    struct {
        unsigned int arr9_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr9_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr9_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB369;

typedef union {
    struct {
        unsigned int arr9_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr9_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr9_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB370;

typedef union {
    struct {
        unsigned int arr9_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr9_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr9_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB373;

typedef union {
    struct {
        unsigned int arr10_dci_type                                   :   8               ;    /* 7:0 */
        unsigned int arr10_r_idx                                      :   8               ;    /* 15:8 */
        unsigned int arr10_chnl_type                                  :   8               ;    /* 23:16 */
        unsigned int arr10_bwp_sw_flag                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB380;

typedef union {
    struct {
        unsigned int arr10_tb_valid0                                  :   8               ;    /* 7:0 */
        unsigned int arr10_tb_valid1                                  :   8               ;    /* 15:8 */
        unsigned int arr10_cif                                        :   8               ;    /* 23:16 */
        unsigned int arr10_bwp_ind                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB381;

typedef union {
    struct {
        unsigned int arr10_time_idx                                   :   8               ;    /* 7:0 */
        unsigned int arr10_vrb2prb_map                                :   8               ;    /* 15:8 */
        unsigned int arr10_prb_bundl_size_indi                        :   8               ;    /* 23:16 */
        unsigned int arr10_rate_match_indi                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB383;

typedef union {
    struct {
        unsigned int arr10_zpcsi_rs_trigger                           :   8               ;    /* 7:0 */
        unsigned int arr10_tb0_mcs                                    :   8               ;    /* 15:8 */
        unsigned int arr10_tb0_ndi                                    :   8               ;    /* 23:16 */
        unsigned int arr10_tb0_rv                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB384;

typedef union {
    struct {
        unsigned int arr10_tb1_mcs                                    :   8               ;    /* 7:0 */
        unsigned int arr10_tb1_ndi                                    :   8               ;    /* 15:8 */
        unsigned int arr10_tb1_rv                                     :   8               ;    /* 23:16 */
        unsigned int arr10_harq_num                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB385;

typedef union {
    struct {
        unsigned int arr10_dai                                        :   8               ;    /* 7:0 */
        unsigned int arr10_pucch_tpc                                  :   8               ;    /* 15:8 */
        unsigned int arr10_pucch_sec_tpc                              :   8               ;    /* 23:16 */
        unsigned int arr10_pucch_indi                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB386;

typedef union {
    struct {
        unsigned int arr10_pds_harq_fbk_time_indi                     :   8               ;    /* 7:0 */
        unsigned int arr10_oneshot_harq_ack                           :   8               ;    /* 15:8 */
        unsigned int arr10_enh_type3                                  :   8               ;    /* 23:16 */
        unsigned int arr10_pdsch_group_ind                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB387;

typedef union {
    struct {
        unsigned int arr10_new_fbk                                    :   8               ;    /* 7:0 */
        unsigned int arr10_nrof_pdsch_group                           :   8               ;    /* 15:8 */
        unsigned int arr10_harq_ack_retx                              :   8               ;    /* 23:16 */
        unsigned int arr10_ant_port                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB388;

typedef union {
    struct {
        unsigned int arr10_reserved_0                                 :   8               ;    /* 7:0 */
        unsigned int arr10_tci                                        :   8               ;    /* 15:8 */
        unsigned int arr10_srs_req                                    :   8               ;    /* 23:16 */
        unsigned int arr10_srs_ofset                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB389;

typedef union {
    struct {
        unsigned int arr10_cbgti                                      :   8               ;    /* 7:0 */
        unsigned int arr10_cbgfi                                      :   8               ;    /* 15:8 */
        unsigned int arr10_dmrs_seq_init                              :   8               ;    /* 23:16 */
        unsigned int arr10_priority_ind                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB390;

typedef union {
    struct {
        unsigned int arr10_min_k0k2_ind                               :   8               ;    /* 7:0 */
        unsigned int arr10_dormancy_ind                               :   8               ;    /* 15:8 */
        unsigned int arr10_pdc_monitor_adaption                       :   8               ;    /* 23:16 */
        unsigned int arr10_pucch_cell_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB391;

typedef union {
    struct {
        unsigned int arr10_dci42_harq_ack_en                          :   8               ;    /* 7:0 */
        unsigned int arr10_mcch_chg_notify                            :   8               ;    /* 15:8 */
        unsigned int arr10_sps_active_flag                            :   8               ;    /* 23:16 */
        unsigned int arr10_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB392;

typedef union {
    struct {
        unsigned int arr10_trs_availability                           :   8               ;    /* 7:0 */
        unsigned int arr10_short_msg_indi                             :   8               ;    /* 15:8 */
        unsigned int arr10_short_msg                                  :   8               ;    /* 23:16 */
        unsigned int arr10_lsbs_of_sfn                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB393;

typedef union {
    struct {
        unsigned int arr10_prach_idx                                  :   4               ;    /* 3:0 */
        unsigned int arr10_ssb_idx                                    :   6               ;    /* 9:4 */
        unsigned int arr10_sul_ind                                    :   1               ;    /* 10 */
        unsigned int arr10_ra_prmb_idx                                :   6               ;    /* 16:11 */
        unsigned int arr10_reserved_0                                 :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB394;

typedef union {
    struct {
        unsigned int arr10_sys_info_indi                              :   8               ;    /* 7:0 */
        unsigned int arr10_tb_scaling                                 :   8               ;    /* 15:8 */
        unsigned int arr10_k1                                         :   8               ;    /* 23:16 */
        unsigned int arr10_res_alloc_type                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB395;

typedef union {
    struct {
        unsigned int arr10_pds_map_type                               :   8               ;    /* 7:0 */
        unsigned int arr10_k0                                         :   8               ;    /* 15:8 */
        unsigned int arr10_max_k0                                     :   8               ;    /* 23:16 */
        unsigned int arr10_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB396;

typedef union {
    struct {
        unsigned int arr10_sliv                                       :   8               ;    /* 7:0 */
        unsigned int arr10_prb_bundle_size                            :   8               ;    /* 15:8 */
        unsigned int arr10_reserved_0                                 :   8               ;    /* 23:16 */
        unsigned int arr10_dedi_pds_para_vld                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB397;

typedef union {
    struct {
        unsigned int arr10_sym_start                                  :   8               ;    /* 7:0 */
        unsigned int arr10_sym_len                                    :   8               ;    /* 15:8 */
        unsigned int arr10_rb_start                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB398;

typedef union {
    struct {
        unsigned int arr10_rbg_size                                   :   8               ;    /* 7:0 */
        unsigned int arr10_reserved_0                                 :   8               ;    /* 15:8 */
        unsigned int arr10_rb_num                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB399;

typedef union {
    struct {
        unsigned int arr10_cfg_type                                   :   8               ;    /* 7:0 */
        unsigned int arr10_bundle_size                                :   8               ;    /* 15:8 */
        unsigned int arr10_bwp_rb_num                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB400;

typedef union {
    struct {
        unsigned int arr10_additional_pos                             :   8               ;    /* 7:0 */
        unsigned int arr10_max_len                                    :   8               ;    /* 15:8 */
        unsigned int arr10_dmrs_sym_bitmap                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB401;

typedef union {
    struct {
        unsigned int arr10_dmrs_re_bitmap                             :   16              ;    /* 15:0 */
        unsigned int arr10_port_bitmap                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB402;

typedef union {
    struct {
        unsigned int arr10_rbg_num                                    :   8               ;    /* 7:0 */
        unsigned int arr10_cdm_ind                                    :   8               ;    /* 15:8 */
        unsigned int arr10_dmrs_sym_len                               :   8               ;    /* 23:16 */
        unsigned int arr10_dmrs_num_per_pb                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB403;

typedef union {
    struct {
        unsigned int arr10_tb1_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr10_tb1_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr10_tb1_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB404;

typedef union {
    struct {
        unsigned int arr10_tb1_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr10_tb1_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr10_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB405;

typedef union {
    struct {
        unsigned int arr10_tb2_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr10_tb2_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr10_tb2_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB407;

typedef union {
    struct {
        unsigned int arr10_tb2_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr10_tb2_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr10_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB408;

typedef union {
    struct {
        unsigned int arr10_pds_scs                                    :   8               ;    /* 7:0 */
        unsigned int arr10_pds_schedu_slot_num                        :   8               ;    /* 15:8 */
        unsigned int arr10_pds_schedu_sfm_num                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB411;

typedef union {
    struct {
        unsigned int arr11_dci_type                                   :   8               ;    /* 7:0 */
        unsigned int arr11_r_idx                                      :   8               ;    /* 15:8 */
        unsigned int arr11_chnl_type                                  :   8               ;    /* 23:16 */
        unsigned int arr11_bwp_sw_flag                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB418;

typedef union {
    struct {
        unsigned int arr11_tb_valid0                                  :   8               ;    /* 7:0 */
        unsigned int arr11_tb_valid1                                  :   8               ;    /* 15:8 */
        unsigned int arr11_cif                                        :   8               ;    /* 23:16 */
        unsigned int arr11_bwp_ind                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB419;

typedef union {
    struct {
        unsigned int arr11_time_idx                                   :   8               ;    /* 7:0 */
        unsigned int arr11_vrb2prb_map                                :   8               ;    /* 15:8 */
        unsigned int arr11_prb_bundl_size_indi                        :   8               ;    /* 23:16 */
        unsigned int arr11_rate_match_indi                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB421;

typedef union {
    struct {
        unsigned int arr11_zpcsi_rs_trigger                           :   8               ;    /* 7:0 */
        unsigned int arr11_tb0_mcs                                    :   8               ;    /* 15:8 */
        unsigned int arr11_tb0_ndi                                    :   8               ;    /* 23:16 */
        unsigned int arr11_tb0_rv                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB422;

typedef union {
    struct {
        unsigned int arr11_tb1_mcs                                    :   8               ;    /* 7:0 */
        unsigned int arr11_tb1_ndi                                    :   8               ;    /* 15:8 */
        unsigned int arr11_tb1_rv                                     :   8               ;    /* 23:16 */
        unsigned int arr11_harq_num                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB423;

typedef union {
    struct {
        unsigned int arr11_dai                                        :   8               ;    /* 7:0 */
        unsigned int arr11_pucch_tpc                                  :   8               ;    /* 15:8 */
        unsigned int arr11_pucch_sec_tpc                              :   8               ;    /* 23:16 */
        unsigned int arr11_pucch_indi                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB424;

typedef union {
    struct {
        unsigned int arr11_pds_harq_fbk_time_indi                     :   8               ;    /* 7:0 */
        unsigned int arr11_oneshot_harq_ack                           :   8               ;    /* 15:8 */
        unsigned int arr11_enh_type3                                  :   8               ;    /* 23:16 */
        unsigned int arr11_pdsch_group_ind                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB425;

typedef union {
    struct {
        unsigned int arr11_new_fbk                                    :   8               ;    /* 7:0 */
        unsigned int arr11_nrof_pdsch_group                           :   8               ;    /* 15:8 */
        unsigned int arr11_harq_ack_retx                              :   8               ;    /* 23:16 */
        unsigned int arr11_ant_port                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB426;

typedef union {
    struct {
        unsigned int arr11_reserved_0                                 :   8               ;    /* 7:0 */
        unsigned int arr11_tci                                        :   8               ;    /* 15:8 */
        unsigned int arr11_srs_req                                    :   8               ;    /* 23:16 */
        unsigned int arr11_srs_ofset                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB427;

typedef union {
    struct {
        unsigned int arr11_cbgti                                      :   8               ;    /* 7:0 */
        unsigned int arr11_cbgfi                                      :   8               ;    /* 15:8 */
        unsigned int arr11_dmrs_seq_init                              :   8               ;    /* 23:16 */
        unsigned int arr11_priority_ind                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB428;

typedef union {
    struct {
        unsigned int arr11_min_k0k2_ind                               :   8               ;    /* 7:0 */
        unsigned int arr11_dormancy_ind                               :   8               ;    /* 15:8 */
        unsigned int arr11_pdc_monitor_adaption                       :   8               ;    /* 23:16 */
        unsigned int arr11_pucch_cell_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB429;

typedef union {
    struct {
        unsigned int arr11_dci42_harq_ack_en                          :   8               ;    /* 7:0 */
        unsigned int arr11_mcch_chg_notify                            :   8               ;    /* 15:8 */
        unsigned int arr11_sps_active_flag                            :   8               ;    /* 23:16 */
        unsigned int arr11_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB430;

typedef union {
    struct {
        unsigned int arr11_trs_availability                           :   8               ;    /* 7:0 */
        unsigned int arr11_short_msg_indi                             :   8               ;    /* 15:8 */
        unsigned int arr11_short_msg                                  :   8               ;    /* 23:16 */
        unsigned int arr11_lsbs_of_sfn                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB431;

typedef union {
    struct {
        unsigned int arr11_prach_idx                                  :   4               ;    /* 3:0 */
        unsigned int arr11_ssb_idx                                    :   6               ;    /* 9:4 */
        unsigned int arr11_sul_ind                                    :   1               ;    /* 10 */
        unsigned int arr11_ra_prmb_idx                                :   6               ;    /* 16:11 */
        unsigned int arr11_reserved_0                                 :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB432;

typedef union {
    struct {
        unsigned int arr11_sys_info_indi                              :   8               ;    /* 7:0 */
        unsigned int arr11_tb_scaling                                 :   8               ;    /* 15:8 */
        unsigned int arr11_k1                                         :   8               ;    /* 23:16 */
        unsigned int arr11_res_alloc_type                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB433;

typedef union {
    struct {
        unsigned int arr11_pds_map_type                               :   8               ;    /* 7:0 */
        unsigned int arr11_k0                                         :   8               ;    /* 15:8 */
        unsigned int arr11_max_k0                                     :   8               ;    /* 23:16 */
        unsigned int arr11_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB434;

typedef union {
    struct {
        unsigned int arr11_sliv                                       :   8               ;    /* 7:0 */
        unsigned int arr11_prb_bundle_size                            :   8               ;    /* 15:8 */
        unsigned int arr11_reserved_0                                 :   8               ;    /* 23:16 */
        unsigned int arr11_dedi_pds_para_vld                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB435;

typedef union {
    struct {
        unsigned int arr11_sym_start                                  :   8               ;    /* 7:0 */
        unsigned int arr11_sym_len                                    :   8               ;    /* 15:8 */
        unsigned int arr11_rb_start                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB436;

typedef union {
    struct {
        unsigned int arr11_rbg_size                                   :   8               ;    /* 7:0 */
        unsigned int arr11_reserved_0                                 :   8               ;    /* 15:8 */
        unsigned int arr11_rb_num                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB437;

typedef union {
    struct {
        unsigned int arr11_cfg_type                                   :   8               ;    /* 7:0 */
        unsigned int arr11_bundle_size                                :   8               ;    /* 15:8 */
        unsigned int arr11_bwp_rb_num                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB438;

typedef union {
    struct {
        unsigned int arr11_additional_pos                             :   8               ;    /* 7:0 */
        unsigned int arr11_max_len                                    :   8               ;    /* 15:8 */
        unsigned int arr11_dmrs_sym_bitmap                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB439;

typedef union {
    struct {
        unsigned int arr11_dmrs_re_bitmap                             :   16              ;    /* 15:0 */
        unsigned int arr11_port_bitmap                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB440;

typedef union {
    struct {
        unsigned int arr11_rbg_num                                    :   8               ;    /* 7:0 */
        unsigned int arr11_cdm_ind                                    :   8               ;    /* 15:8 */
        unsigned int arr11_dmrs_sym_len                               :   8               ;    /* 23:16 */
        unsigned int arr11_dmrs_num_per_pb                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB441;

typedef union {
    struct {
        unsigned int arr11_tb1_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr11_tb1_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr11_tb1_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB442;

typedef union {
    struct {
        unsigned int arr11_tb1_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr11_tb1_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr11_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB443;

typedef union {
    struct {
        unsigned int arr11_tb2_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr11_tb2_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr11_tb2_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB445;

typedef union {
    struct {
        unsigned int arr11_tb2_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr11_tb2_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr11_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB446;

typedef union {
    struct {
        unsigned int arr11_pds_scs                                    :   8               ;    /* 7:0 */
        unsigned int arr11_pds_schedu_slot_num                        :   8               ;    /* 15:8 */
        unsigned int arr11_pds_schedu_sfm_num                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB449;

typedef union {
    struct {
        unsigned int arr12_dci_type                                   :   8               ;    /* 7:0 */
        unsigned int arr12_r_idx                                      :   8               ;    /* 15:8 */
        unsigned int arr12_chnl_type                                  :   8               ;    /* 23:16 */
        unsigned int arr12_bwp_sw_flag                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB456;

typedef union {
    struct {
        unsigned int arr12_tb_valid0                                  :   8               ;    /* 7:0 */
        unsigned int arr12_tb_valid1                                  :   8               ;    /* 15:8 */
        unsigned int arr12_cif                                        :   8               ;    /* 23:16 */
        unsigned int arr12_bwp_ind                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB457;

typedef union {
    struct {
        unsigned int arr12_time_idx                                   :   8               ;    /* 7:0 */
        unsigned int arr12_vrb2prb_map                                :   8               ;    /* 15:8 */
        unsigned int arr12_prb_bundl_size_indi                        :   8               ;    /* 23:16 */
        unsigned int arr12_rate_match_indi                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB459;

typedef union {
    struct {
        unsigned int arr12_zpcsi_rs_trigger                           :   8               ;    /* 7:0 */
        unsigned int arr12_tb0_mcs                                    :   8               ;    /* 15:8 */
        unsigned int arr12_tb0_ndi                                    :   8               ;    /* 23:16 */
        unsigned int arr12_tb0_rv                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB460;

typedef union {
    struct {
        unsigned int arr12_tb1_mcs                                    :   8               ;    /* 7:0 */
        unsigned int arr12_tb1_ndi                                    :   8               ;    /* 15:8 */
        unsigned int arr12_tb1_rv                                     :   8               ;    /* 23:16 */
        unsigned int arr12_harq_num                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB461;

typedef union {
    struct {
        unsigned int arr12_dai                                        :   8               ;    /* 7:0 */
        unsigned int arr12_pucch_tpc                                  :   8               ;    /* 15:8 */
        unsigned int arr12_pucch_sec_tpc                              :   8               ;    /* 23:16 */
        unsigned int arr12_pucch_indi                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB462;

typedef union {
    struct {
        unsigned int arr12_pds_harq_fbk_time_indi                     :   8               ;    /* 7:0 */
        unsigned int arr12_oneshot_harq_ack                           :   8               ;    /* 15:8 */
        unsigned int arr12_enh_type3                                  :   8               ;    /* 23:16 */
        unsigned int arr12_pdsch_group_ind                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB463;

typedef union {
    struct {
        unsigned int arr12_new_fbk                                    :   8               ;    /* 7:0 */
        unsigned int arr12_nrof_pdsch_group                           :   8               ;    /* 15:8 */
        unsigned int arr12_harq_ack_retx                              :   8               ;    /* 23:16 */
        unsigned int arr12_ant_port                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB464;

typedef union {
    struct {
        unsigned int arr12_reserved_0                                 :   8               ;    /* 7:0 */
        unsigned int arr12_tci                                        :   8               ;    /* 15:8 */
        unsigned int arr12_srs_req                                    :   8               ;    /* 23:16 */
        unsigned int arr12_srs_ofset                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB465;

typedef union {
    struct {
        unsigned int arr12_cbgti                                      :   8               ;    /* 7:0 */
        unsigned int arr12_cbgfi                                      :   8               ;    /* 15:8 */
        unsigned int arr12_dmrs_seq_init                              :   8               ;    /* 23:16 */
        unsigned int arr12_priority_ind                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB466;

typedef union {
    struct {
        unsigned int arr12_min_k0k2_ind                               :   8               ;    /* 7:0 */
        unsigned int arr12_dormancy_ind                               :   8               ;    /* 15:8 */
        unsigned int arr12_pdc_monitor_adaption                       :   8               ;    /* 23:16 */
        unsigned int arr12_pucch_cell_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB467;

typedef union {
    struct {
        unsigned int arr12_dci42_harq_ack_en                          :   8               ;    /* 7:0 */
        unsigned int arr12_mcch_chg_notify                            :   8               ;    /* 15:8 */
        unsigned int arr12_sps_active_flag                            :   8               ;    /* 23:16 */
        unsigned int arr12_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB468;

typedef union {
    struct {
        unsigned int arr12_trs_availability                           :   8               ;    /* 7:0 */
        unsigned int arr12_short_msg_indi                             :   8               ;    /* 15:8 */
        unsigned int arr12_short_msg                                  :   8               ;    /* 23:16 */
        unsigned int arr12_lsbs_of_sfn                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB469;

typedef union {
    struct {
        unsigned int arr12_prach_idx                                  :   4               ;    /* 3:0 */
        unsigned int arr12_ssb_idx                                    :   6               ;    /* 9:4 */
        unsigned int arr12_sul_ind                                    :   1               ;    /* 10 */
        unsigned int arr12_ra_prmb_idx                                :   6               ;    /* 16:11 */
        unsigned int arr12_reserved_0                                 :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB470;

typedef union {
    struct {
        unsigned int arr12_sys_info_indi                              :   8               ;    /* 7:0 */
        unsigned int arr12_tb_scaling                                 :   8               ;    /* 15:8 */
        unsigned int arr12_k1                                         :   8               ;    /* 23:16 */
        unsigned int arr12_res_alloc_type                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB471;

typedef union {
    struct {
        unsigned int arr12_pds_map_type                               :   8               ;    /* 7:0 */
        unsigned int arr12_k0                                         :   8               ;    /* 15:8 */
        unsigned int arr12_max_k0                                     :   8               ;    /* 23:16 */
        unsigned int arr12_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB472;

typedef union {
    struct {
        unsigned int arr12_sliv                                       :   8               ;    /* 7:0 */
        unsigned int arr12_prb_bundle_size                            :   8               ;    /* 15:8 */
        unsigned int arr12_reserved_0                                 :   8               ;    /* 23:16 */
        unsigned int arr12_dedi_pds_para_vld                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB473;

typedef union {
    struct {
        unsigned int arr12_sym_start                                  :   8               ;    /* 7:0 */
        unsigned int arr12_sym_len                                    :   8               ;    /* 15:8 */
        unsigned int arr12_rb_start                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB474;

typedef union {
    struct {
        unsigned int arr12_rbg_size                                   :   8               ;    /* 7:0 */
        unsigned int arr12_reserved_0                                 :   8               ;    /* 15:8 */
        unsigned int arr12_rb_num                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB475;

typedef union {
    struct {
        unsigned int arr12_cfg_type                                   :   8               ;    /* 7:0 */
        unsigned int arr12_bundle_size                                :   8               ;    /* 15:8 */
        unsigned int arr12_bwp_rb_num                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB476;

typedef union {
    struct {
        unsigned int arr12_additional_pos                             :   8               ;    /* 7:0 */
        unsigned int arr12_max_len                                    :   8               ;    /* 15:8 */
        unsigned int arr12_dmrs_sym_bitmap                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB477;

typedef union {
    struct {
        unsigned int arr12_dmrs_re_bitmap                             :   16              ;    /* 15:0 */
        unsigned int arr12_port_bitmap                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB478;

typedef union {
    struct {
        unsigned int arr12_rbg_num                                    :   8               ;    /* 7:0 */
        unsigned int arr12_cdm_ind                                    :   8               ;    /* 15:8 */
        unsigned int arr12_dmrs_sym_len                               :   8               ;    /* 23:16 */
        unsigned int arr12_dmrs_num_per_pb                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB479;

typedef union {
    struct {
        unsigned int arr12_tb1_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr12_tb1_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr12_tb1_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB480;

typedef union {
    struct {
        unsigned int arr12_tb1_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr12_tb1_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr12_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB481;

typedef union {
    struct {
        unsigned int arr12_tb2_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr12_tb2_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr12_tb2_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB483;

typedef union {
    struct {
        unsigned int arr12_tb2_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr12_tb2_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr12_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB484;

typedef union {
    struct {
        unsigned int arr12_pds_scs                                    :   8               ;    /* 7:0 */
        unsigned int arr12_pds_schedu_slot_num                        :   8               ;    /* 15:8 */
        unsigned int arr12_pds_schedu_sfm_num                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB487;

typedef union {
    struct {
        unsigned int arr13_dci_type                                   :   8               ;    /* 7:0 */
        unsigned int arr13_r_idx                                      :   8               ;    /* 15:8 */
        unsigned int arr13_chnl_type                                  :   8               ;    /* 23:16 */
        unsigned int arr13_bwp_sw_flag                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB494;

typedef union {
    struct {
        unsigned int arr13_tb_valid0                                  :   8               ;    /* 7:0 */
        unsigned int arr13_tb_valid1                                  :   8               ;    /* 15:8 */
        unsigned int arr13_cif                                        :   8               ;    /* 23:16 */
        unsigned int arr13_bwp_ind                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB495;

typedef union {
    struct {
        unsigned int arr13_time_idx                                   :   8               ;    /* 7:0 */
        unsigned int arr13_vrb2prb_map                                :   8               ;    /* 15:8 */
        unsigned int arr13_prb_bundl_size_indi                        :   8               ;    /* 23:16 */
        unsigned int arr13_rate_match_indi                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB497;

typedef union {
    struct {
        unsigned int arr13_zpcsi_rs_trigger                           :   8               ;    /* 7:0 */
        unsigned int arr13_tb0_mcs                                    :   8               ;    /* 15:8 */
        unsigned int arr13_tb0_ndi                                    :   8               ;    /* 23:16 */
        unsigned int arr13_tb0_rv                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB498;

typedef union {
    struct {
        unsigned int arr13_tb1_mcs                                    :   8               ;    /* 7:0 */
        unsigned int arr13_tb1_ndi                                    :   8               ;    /* 15:8 */
        unsigned int arr13_tb1_rv                                     :   8               ;    /* 23:16 */
        unsigned int arr13_harq_num                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB499;

typedef union {
    struct {
        unsigned int arr13_dai                                        :   8               ;    /* 7:0 */
        unsigned int arr13_pucch_tpc                                  :   8               ;    /* 15:8 */
        unsigned int arr13_pucch_sec_tpc                              :   8               ;    /* 23:16 */
        unsigned int arr13_pucch_indi                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB500;

typedef union {
    struct {
        unsigned int arr13_pds_harq_fbk_time_indi                     :   8               ;    /* 7:0 */
        unsigned int arr13_oneshot_harq_ack                           :   8               ;    /* 15:8 */
        unsigned int arr13_enh_type3                                  :   8               ;    /* 23:16 */
        unsigned int arr13_pdsch_group_ind                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB501;

typedef union {
    struct {
        unsigned int arr13_new_fbk                                    :   8               ;    /* 7:0 */
        unsigned int arr13_nrof_pdsch_group                           :   8               ;    /* 15:8 */
        unsigned int arr13_harq_ack_retx                              :   8               ;    /* 23:16 */
        unsigned int arr13_ant_port                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB502;

typedef union {
    struct {
        unsigned int arr13_reserved_0                                 :   8               ;    /* 7:0 */
        unsigned int arr13_tci                                        :   8               ;    /* 15:8 */
        unsigned int arr13_srs_req                                    :   8               ;    /* 23:16 */
        unsigned int arr13_srs_ofset                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB503;

typedef union {
    struct {
        unsigned int arr13_cbgti                                      :   8               ;    /* 7:0 */
        unsigned int arr13_cbgfi                                      :   8               ;    /* 15:8 */
        unsigned int arr13_dmrs_seq_init                              :   8               ;    /* 23:16 */
        unsigned int arr13_priority_ind                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB504;

typedef union {
    struct {
        unsigned int arr13_min_k0k2_ind                               :   8               ;    /* 7:0 */
        unsigned int arr13_dormancy_ind                               :   8               ;    /* 15:8 */
        unsigned int arr13_pdc_monitor_adaption                       :   8               ;    /* 23:16 */
        unsigned int arr13_pucch_cell_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB505;

typedef union {
    struct {
        unsigned int arr13_dci42_harq_ack_en                          :   8               ;    /* 7:0 */
        unsigned int arr13_mcch_chg_notify                            :   8               ;    /* 15:8 */
        unsigned int arr13_sps_active_flag                            :   8               ;    /* 23:16 */
        unsigned int arr13_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB506;

typedef union {
    struct {
        unsigned int arr13_trs_availability                           :   8               ;    /* 7:0 */
        unsigned int arr13_short_msg_indi                             :   8               ;    /* 15:8 */
        unsigned int arr13_short_msg                                  :   8               ;    /* 23:16 */
        unsigned int arr13_lsbs_of_sfn                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB507;

typedef union {
    struct {
        unsigned int arr13_prach_idx                                  :   4               ;    /* 3:0 */
        unsigned int arr13_ssb_idx                                    :   6               ;    /* 9:4 */
        unsigned int arr13_sul_ind                                    :   1               ;    /* 10 */
        unsigned int arr13_ra_prmb_idx                                :   6               ;    /* 16:11 */
        unsigned int arr13_reserved_0                                 :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB508;

typedef union {
    struct {
        unsigned int arr13_sys_info_indi                              :   8               ;    /* 7:0 */
        unsigned int arr13_tb_scaling                                 :   8               ;    /* 15:8 */
        unsigned int arr13_k1                                         :   8               ;    /* 23:16 */
        unsigned int arr13_res_alloc_type                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB509;

typedef union {
    struct {
        unsigned int arr13_pds_map_type                               :   8               ;    /* 7:0 */
        unsigned int arr13_k0                                         :   8               ;    /* 15:8 */
        unsigned int arr13_max_k0                                     :   8               ;    /* 23:16 */
        unsigned int arr13_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB510;

typedef union {
    struct {
        unsigned int arr13_sliv                                       :   8               ;    /* 7:0 */
        unsigned int arr13_prb_bundle_size                            :   8               ;    /* 15:8 */
        unsigned int arr13_reserved_0                                 :   8               ;    /* 23:16 */
        unsigned int arr13_dedi_pds_para_vld                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB511;

typedef union {
    struct {
        unsigned int arr13_sym_start                                  :   8               ;    /* 7:0 */
        unsigned int arr13_sym_len                                    :   8               ;    /* 15:8 */
        unsigned int arr13_rb_start                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB512;

typedef union {
    struct {
        unsigned int arr13_rbg_size                                   :   8               ;    /* 7:0 */
        unsigned int arr13_reserved_0                                 :   8               ;    /* 15:8 */
        unsigned int arr13_rb_num                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB513;

typedef union {
    struct {
        unsigned int arr13_cfg_type                                   :   8               ;    /* 7:0 */
        unsigned int arr13_bundle_size                                :   8               ;    /* 15:8 */
        unsigned int arr13_bwp_rb_num                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB514;

typedef union {
    struct {
        unsigned int arr13_additional_pos                             :   8               ;    /* 7:0 */
        unsigned int arr13_max_len                                    :   8               ;    /* 15:8 */
        unsigned int arr13_dmrs_sym_bitmap                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB515;

typedef union {
    struct {
        unsigned int arr13_dmrs_re_bitmap                             :   16              ;    /* 15:0 */
        unsigned int arr13_port_bitmap                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB516;

typedef union {
    struct {
        unsigned int arr13_rbg_num                                    :   8               ;    /* 7:0 */
        unsigned int arr13_cdm_ind                                    :   8               ;    /* 15:8 */
        unsigned int arr13_dmrs_sym_len                               :   8               ;    /* 23:16 */
        unsigned int arr13_dmrs_num_per_pb                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB517;

typedef union {
    struct {
        unsigned int arr13_tb1_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr13_tb1_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr13_tb1_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB518;

typedef union {
    struct {
        unsigned int arr13_tb1_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr13_tb1_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr13_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB519;

typedef union {
    struct {
        unsigned int arr13_tb2_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr13_tb2_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr13_tb2_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB521;

typedef union {
    struct {
        unsigned int arr13_tb2_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr13_tb2_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr13_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB522;

typedef union {
    struct {
        unsigned int arr13_pds_scs                                    :   8               ;    /* 7:0 */
        unsigned int arr13_pds_schedu_slot_num                        :   8               ;    /* 15:8 */
        unsigned int arr13_pds_schedu_sfm_num                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB525;

typedef union {
    struct {
        unsigned int arr14_dci_type                                   :   8               ;    /* 7:0 */
        unsigned int arr14_r_idx                                      :   8               ;    /* 15:8 */
        unsigned int arr14_chnl_type                                  :   8               ;    /* 23:16 */
        unsigned int arr14_bwp_sw_flag                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB532;

typedef union {
    struct {
        unsigned int arr14_tb_valid0                                  :   8               ;    /* 7:0 */
        unsigned int arr14_tb_valid1                                  :   8               ;    /* 15:8 */
        unsigned int arr14_cif                                        :   8               ;    /* 23:16 */
        unsigned int arr14_bwp_ind                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB533;

typedef union {
    struct {
        unsigned int arr14_time_idx                                   :   8               ;    /* 7:0 */
        unsigned int arr14_vrb2prb_map                                :   8               ;    /* 15:8 */
        unsigned int arr14_prb_bundl_size_indi                        :   8               ;    /* 23:16 */
        unsigned int arr14_rate_match_indi                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB535;

typedef union {
    struct {
        unsigned int arr14_zpcsi_rs_trigger                           :   8               ;    /* 7:0 */
        unsigned int arr14_tb0_mcs                                    :   8               ;    /* 15:8 */
        unsigned int arr14_tb0_ndi                                    :   8               ;    /* 23:16 */
        unsigned int arr14_tb0_rv                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB536;

typedef union {
    struct {
        unsigned int arr14_tb1_mcs                                    :   8               ;    /* 7:0 */
        unsigned int arr14_tb1_ndi                                    :   8               ;    /* 15:8 */
        unsigned int arr14_tb1_rv                                     :   8               ;    /* 23:16 */
        unsigned int arr14_harq_num                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB537;

typedef union {
    struct {
        unsigned int arr14_dai                                        :   8               ;    /* 7:0 */
        unsigned int arr14_pucch_tpc                                  :   8               ;    /* 15:8 */
        unsigned int arr14_pucch_sec_tpc                              :   8               ;    /* 23:16 */
        unsigned int arr14_pucch_indi                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB538;

typedef union {
    struct {
        unsigned int arr14_pds_harq_fbk_time_indi                     :   8               ;    /* 7:0 */
        unsigned int arr14_oneshot_harq_ack                           :   8               ;    /* 15:8 */
        unsigned int arr14_enh_type3                                  :   8               ;    /* 23:16 */
        unsigned int arr14_pdsch_group_ind                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB539;

typedef union {
    struct {
        unsigned int arr14_new_fbk                                    :   8               ;    /* 7:0 */
        unsigned int arr14_nrof_pdsch_group                           :   8               ;    /* 15:8 */
        unsigned int arr14_harq_ack_retx                              :   8               ;    /* 23:16 */
        unsigned int arr14_ant_port                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB540;

typedef union {
    struct {
        unsigned int arr14_reserved_0                                 :   8               ;    /* 7:0 */
        unsigned int arr14_tci                                        :   8               ;    /* 15:8 */
        unsigned int arr14_srs_req                                    :   8               ;    /* 23:16 */
        unsigned int arr14_srs_ofset                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB541;

typedef union {
    struct {
        unsigned int arr14_cbgti                                      :   8               ;    /* 7:0 */
        unsigned int arr14_cbgfi                                      :   8               ;    /* 15:8 */
        unsigned int arr14_dmrs_seq_init                              :   8               ;    /* 23:16 */
        unsigned int arr14_priority_ind                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB542;

typedef union {
    struct {
        unsigned int arr14_min_k0k2_ind                               :   8               ;    /* 7:0 */
        unsigned int arr14_dormancy_ind                               :   8               ;    /* 15:8 */
        unsigned int arr14_pdc_monitor_adaption                       :   8               ;    /* 23:16 */
        unsigned int arr14_pucch_cell_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB543;

typedef union {
    struct {
        unsigned int arr14_dci42_harq_ack_en                          :   8               ;    /* 7:0 */
        unsigned int arr14_mcch_chg_notify                            :   8               ;    /* 15:8 */
        unsigned int arr14_sps_active_flag                            :   8               ;    /* 23:16 */
        unsigned int arr14_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB544;

typedef union {
    struct {
        unsigned int arr14_trs_availability                           :   8               ;    /* 7:0 */
        unsigned int arr14_short_msg_indi                             :   8               ;    /* 15:8 */
        unsigned int arr14_short_msg                                  :   8               ;    /* 23:16 */
        unsigned int arr14_lsbs_of_sfn                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB545;

typedef union {
    struct {
        unsigned int arr14_prach_idx                                  :   4               ;    /* 3:0 */
        unsigned int arr14_ssb_idx                                    :   6               ;    /* 9:4 */
        unsigned int arr14_sul_ind                                    :   1               ;    /* 10 */
        unsigned int arr14_ra_prmb_idx                                :   6               ;    /* 16:11 */
        unsigned int arr14_reserved_0                                 :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB546;

typedef union {
    struct {
        unsigned int arr14_sys_info_indi                              :   8               ;    /* 7:0 */
        unsigned int arr14_tb_scaling                                 :   8               ;    /* 15:8 */
        unsigned int arr14_k1                                         :   8               ;    /* 23:16 */
        unsigned int arr14_res_alloc_type                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB547;

typedef union {
    struct {
        unsigned int arr14_pds_map_type                               :   8               ;    /* 7:0 */
        unsigned int arr14_k0                                         :   8               ;    /* 15:8 */
        unsigned int arr14_max_k0                                     :   8               ;    /* 23:16 */
        unsigned int arr14_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB548;

typedef union {
    struct {
        unsigned int arr14_sliv                                       :   8               ;    /* 7:0 */
        unsigned int arr14_prb_bundle_size                            :   8               ;    /* 15:8 */
        unsigned int arr14_reserved_0                                 :   8               ;    /* 23:16 */
        unsigned int arr14_dedi_pds_para_vld                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB549;

typedef union {
    struct {
        unsigned int arr14_sym_start                                  :   8               ;    /* 7:0 */
        unsigned int arr14_sym_len                                    :   8               ;    /* 15:8 */
        unsigned int arr14_rb_start                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB550;

typedef union {
    struct {
        unsigned int arr14_rbg_size                                   :   8               ;    /* 7:0 */
        unsigned int arr14_reserved_0                                 :   8               ;    /* 15:8 */
        unsigned int arr14_rb_num                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB551;

typedef union {
    struct {
        unsigned int arr14_cfg_type                                   :   8               ;    /* 7:0 */
        unsigned int arr14_bundle_size                                :   8               ;    /* 15:8 */
        unsigned int arr14_bwp_rb_num                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB552;

typedef union {
    struct {
        unsigned int arr14_additional_pos                             :   8               ;    /* 7:0 */
        unsigned int arr14_max_len                                    :   8               ;    /* 15:8 */
        unsigned int arr14_dmrs_sym_bitmap                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB553;

typedef union {
    struct {
        unsigned int arr14_dmrs_re_bitmap                             :   16              ;    /* 15:0 */
        unsigned int arr14_port_bitmap                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB554;

typedef union {
    struct {
        unsigned int arr14_rbg_num                                    :   8               ;    /* 7:0 */
        unsigned int arr14_cdm_ind                                    :   8               ;    /* 15:8 */
        unsigned int arr14_dmrs_sym_len                               :   8               ;    /* 23:16 */
        unsigned int arr14_dmrs_num_per_pb                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB555;

typedef union {
    struct {
        unsigned int arr14_tb1_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr14_tb1_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr14_tb1_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB556;

typedef union {
    struct {
        unsigned int arr14_tb1_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr14_tb1_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr14_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB557;

typedef union {
    struct {
        unsigned int arr14_tb2_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr14_tb2_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr14_tb2_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB559;

typedef union {
    struct {
        unsigned int arr14_tb2_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr14_tb2_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr14_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB560;

typedef union {
    struct {
        unsigned int arr14_pds_scs                                    :   8               ;    /* 7:0 */
        unsigned int arr14_pds_schedu_slot_num                        :   8               ;    /* 15:8 */
        unsigned int arr14_pds_schedu_sfm_num                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB563;

typedef union {
    struct {
        unsigned int arr15_dci_type                                   :   8               ;    /* 7:0 */
        unsigned int arr15_r_idx                                      :   8               ;    /* 15:8 */
        unsigned int arr15_chnl_type                                  :   8               ;    /* 23:16 */
        unsigned int arr15_bwp_sw_flag                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB570;

typedef union {
    struct {
        unsigned int arr15_tb_valid0                                  :   8               ;    /* 7:0 */
        unsigned int arr15_tb_valid1                                  :   8               ;    /* 15:8 */
        unsigned int arr15_cif                                        :   8               ;    /* 23:16 */
        unsigned int arr15_bwp_ind                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB571;

typedef union {
    struct {
        unsigned int arr15_time_idx                                   :   8               ;    /* 7:0 */
        unsigned int arr15_vrb2prb_map                                :   8               ;    /* 15:8 */
        unsigned int arr15_prb_bundl_size_indi                        :   8               ;    /* 23:16 */
        unsigned int arr15_rate_match_indi                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB573;

typedef union {
    struct {
        unsigned int arr15_zpcsi_rs_trigger                           :   8               ;    /* 7:0 */
        unsigned int arr15_tb0_mcs                                    :   8               ;    /* 15:8 */
        unsigned int arr15_tb0_ndi                                    :   8               ;    /* 23:16 */
        unsigned int arr15_tb0_rv                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB574;

typedef union {
    struct {
        unsigned int arr15_tb1_mcs                                    :   8               ;    /* 7:0 */
        unsigned int arr15_tb1_ndi                                    :   8               ;    /* 15:8 */
        unsigned int arr15_tb1_rv                                     :   8               ;    /* 23:16 */
        unsigned int arr15_harq_num                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB575;

typedef union {
    struct {
        unsigned int arr15_dai                                        :   8               ;    /* 7:0 */
        unsigned int arr15_pucch_tpc                                  :   8               ;    /* 15:8 */
        unsigned int arr15_pucch_sec_tpc                              :   8               ;    /* 23:16 */
        unsigned int arr15_pucch_indi                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB576;

typedef union {
    struct {
        unsigned int arr15_pds_harq_fbk_time_indi                     :   8               ;    /* 7:0 */
        unsigned int arr15_oneshot_harq_ack                           :   8               ;    /* 15:8 */
        unsigned int arr15_enh_type3                                  :   8               ;    /* 23:16 */
        unsigned int arr15_pdsch_group_ind                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB577;

typedef union {
    struct {
        unsigned int arr15_new_fbk                                    :   8               ;    /* 7:0 */
        unsigned int arr15_nrof_pdsch_group                           :   8               ;    /* 15:8 */
        unsigned int arr15_harq_ack_retx                              :   8               ;    /* 23:16 */
        unsigned int arr15_ant_port                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB578;

typedef union {
    struct {
        unsigned int arr15_reserved_0                                 :   8               ;    /* 7:0 */
        unsigned int arr15_tci                                        :   8               ;    /* 15:8 */
        unsigned int arr15_srs_req                                    :   8               ;    /* 23:16 */
        unsigned int arr15_srs_ofset                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB579;

typedef union {
    struct {
        unsigned int arr15_cbgti                                      :   8               ;    /* 7:0 */
        unsigned int arr15_cbgfi                                      :   8               ;    /* 15:8 */
        unsigned int arr15_dmrs_seq_init                              :   8               ;    /* 23:16 */
        unsigned int arr15_priority_ind                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB580;

typedef union {
    struct {
        unsigned int arr15_min_k0k2_ind                               :   8               ;    /* 7:0 */
        unsigned int arr15_dormancy_ind                               :   8               ;    /* 15:8 */
        unsigned int arr15_pdc_monitor_adaption                       :   8               ;    /* 23:16 */
        unsigned int arr15_pucch_cell_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB581;

typedef union {
    struct {
        unsigned int arr15_dci42_harq_ack_en                          :   8               ;    /* 7:0 */
        unsigned int arr15_mcch_chg_notify                            :   8               ;    /* 15:8 */
        unsigned int arr15_sps_active_flag                            :   8               ;    /* 23:16 */
        unsigned int arr15_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB582;

typedef union {
    struct {
        unsigned int arr15_trs_availability                           :   8               ;    /* 7:0 */
        unsigned int arr15_short_msg_indi                             :   8               ;    /* 15:8 */
        unsigned int arr15_short_msg                                  :   8               ;    /* 23:16 */
        unsigned int arr15_lsbs_of_sfn                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB583;

typedef union {
    struct {
        unsigned int arr15_prach_idx                                  :   4               ;    /* 3:0 */
        unsigned int arr15_ssb_idx                                    :   6               ;    /* 9:4 */
        unsigned int arr15_sul_ind                                    :   1               ;    /* 10 */
        unsigned int arr15_ra_prmb_idx                                :   6               ;    /* 16:11 */
        unsigned int arr15_reserved_0                                 :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB584;

typedef union {
    struct {
        unsigned int arr15_sys_info_indi                              :   8               ;    /* 7:0 */
        unsigned int arr15_tb_scaling                                 :   8               ;    /* 15:8 */
        unsigned int arr15_k1                                         :   8               ;    /* 23:16 */
        unsigned int arr15_res_alloc_type                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB585;

typedef union {
    struct {
        unsigned int arr15_pds_map_type                               :   8               ;    /* 7:0 */
        unsigned int arr15_k0                                         :   8               ;    /* 15:8 */
        unsigned int arr15_max_k0                                     :   8               ;    /* 23:16 */
        unsigned int arr15_reserved_0                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB586;

typedef union {
    struct {
        unsigned int arr15_sliv                                       :   8               ;    /* 7:0 */
        unsigned int arr15_prb_bundle_size                            :   8               ;    /* 15:8 */
        unsigned int arr15_reserved_0                                 :   8               ;    /* 23:16 */
        unsigned int arr15_dedi_pds_para_vld                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB587;

typedef union {
    struct {
        unsigned int arr15_sym_start                                  :   8               ;    /* 7:0 */
        unsigned int arr15_sym_len                                    :   8               ;    /* 15:8 */
        unsigned int arr15_rb_start                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB588;

typedef union {
    struct {
        unsigned int arr15_rbg_size                                   :   8               ;    /* 7:0 */
        unsigned int arr15_reserved_0                                 :   8               ;    /* 15:8 */
        unsigned int arr15_rb_num                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB589;

typedef union {
    struct {
        unsigned int arr15_cfg_type                                   :   8               ;    /* 7:0 */
        unsigned int arr15_bundle_size                                :   8               ;    /* 15:8 */
        unsigned int arr15_bwp_rb_num                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB590;

typedef union {
    struct {
        unsigned int arr15_additional_pos                             :   8               ;    /* 7:0 */
        unsigned int arr15_max_len                                    :   8               ;    /* 15:8 */
        unsigned int arr15_dmrs_sym_bitmap                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB591;

typedef union {
    struct {
        unsigned int arr15_dmrs_re_bitmap                             :   16              ;    /* 15:0 */
        unsigned int arr15_port_bitmap                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB592;

typedef union {
    struct {
        unsigned int arr15_rbg_num                                    :   8               ;    /* 7:0 */
        unsigned int arr15_cdm_ind                                    :   8               ;    /* 15:8 */
        unsigned int arr15_dmrs_sym_len                               :   8               ;    /* 23:16 */
        unsigned int arr15_dmrs_num_per_pb                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB593;

typedef union {
    struct {
        unsigned int arr15_tb1_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr15_tb1_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr15_tb1_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB594;

typedef union {
    struct {
        unsigned int arr15_tb1_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr15_tb1_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr15_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB595;

typedef union {
    struct {
        unsigned int arr15_tb2_layer                                  :   8               ;    /* 7:0 */
        unsigned int arr15_tb2_qm                                     :   8               ;    /* 15:8 */
        unsigned int arr15_tb2_rmcs                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB597;

typedef union {
    struct {
        unsigned int arr15_tb2_new_trans_flag                         :   8               ;    /* 7:0 */
        unsigned int arr15_tb2_crc_ok_retrans_flag                    :   8               ;    /* 15:8 */
        unsigned int arr15_reserved_0                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB598;

typedef union {
    struct {
        unsigned int arr15_pds_scs                                    :   8               ;    /* 7:0 */
        unsigned int arr15_pds_schedu_slot_num                        :   8               ;    /* 15:8 */
        unsigned int arr15_pds_schedu_sfm_num                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB601;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB0                            om_data0;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB1                            om_data1;
    unsigned int                                                      arr0_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB3                            om_data3;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB4                            om_data4;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB5                            om_data5;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB6                            om_data6;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB7                            om_data7;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB8                            om_data8;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB9                            om_data9;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB10                           om_data10;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB11                           om_data11;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB12                           om_data12;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB13                           om_data13;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB14                           om_data14;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB15                           om_data15;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB16                           om_data16;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB17                           om_data17;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB18                           om_data18;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB19                           om_data19;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB20                           om_data20;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB21                           om_data21;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB22                           om_data22;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB23                           om_data23;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB24                           om_data24;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB25                           om_data25;
    unsigned int                                                      arr0_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB27                           om_data27;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB28                           om_data28;
    unsigned int                                                      arr0_tb2_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB30                           om_data30;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB31                           om_data31;
    unsigned int                                                      arr0_array_para0;
    unsigned int                                                      arr0_array_para1;
    unsigned int                                                      arr0_array_para2;
    unsigned int                                                      arr0_array_para3;
    unsigned int                                                      arr0_array_para4;
    unsigned int                                                      arr0_reserved_0;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB38                           om_data38;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB39                           om_data39;
    unsigned int                                                      arr1_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB41                           om_data41;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB42                           om_data42;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB43                           om_data43;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB44                           om_data44;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB45                           om_data45;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB46                           om_data46;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB47                           om_data47;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB48                           om_data48;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB49                           om_data49;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB50                           om_data50;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB51                           om_data51;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB52                           om_data52;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB53                           om_data53;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB54                           om_data54;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB55                           om_data55;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB56                           om_data56;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB57                           om_data57;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB58                           om_data58;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB59                           om_data59;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB60                           om_data60;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB61                           om_data61;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB62                           om_data62;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB63                           om_data63;
    unsigned int                                                      arr1_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB65                           om_data65;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB66                           om_data66;
    unsigned int                                                      arr1_tb2_size;
    unsigned int                                                      arr1_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB69                           om_data69;
    unsigned int                                                      arr1_array_para0;
    unsigned int                                                      arr1_array_para1;
    unsigned int                                                      arr1_array_para2;
    unsigned int                                                      arr1_array_para3;
    unsigned int                                                      arr1_array_para4;
    unsigned int                                                      arr1_reserved_1;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB76                           om_data76;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB77                           om_data77;
    unsigned int                                                      arr2_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB79                           om_data79;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB80                           om_data80;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB81                           om_data81;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB82                           om_data82;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB83                           om_data83;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB84                           om_data84;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB85                           om_data85;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB86                           om_data86;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB87                           om_data87;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB88                           om_data88;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB89                           om_data89;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB90                           om_data90;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB91                           om_data91;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB92                           om_data92;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB93                           om_data93;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB94                           om_data94;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB95                           om_data95;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB96                           om_data96;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB97                           om_data97;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB98                           om_data98;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB99                           om_data99;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB100                          om_data100;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB101                          om_data101;
    unsigned int                                                      arr2_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB103                          om_data103;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB104                          om_data104;
    unsigned int                                                      arr2_tb2_size;
    unsigned int                                                      arr2_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB107                          om_data107;
    unsigned int                                                      arr2_array_para0;
    unsigned int                                                      arr2_array_para1;
    unsigned int                                                      arr2_array_para2;
    unsigned int                                                      arr2_array_para3;
    unsigned int                                                      arr2_array_para4;
    unsigned int                                                      arr2_reserved_2;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB114                          om_data114;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB115                          om_data115;
    unsigned int                                                      arr3_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB117                          om_data117;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB118                          om_data118;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB119                          om_data119;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB120                          om_data120;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB121                          om_data121;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB122                          om_data122;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB123                          om_data123;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB124                          om_data124;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB125                          om_data125;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB126                          om_data126;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB127                          om_data127;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB128                          om_data128;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB129                          om_data129;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB130                          om_data130;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB131                          om_data131;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB132                          om_data132;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB133                          om_data133;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB134                          om_data134;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB135                          om_data135;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB136                          om_data136;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB137                          om_data137;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB138                          om_data138;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB139                          om_data139;
    unsigned int                                                      arr3_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB141                          om_data141;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB142                          om_data142;
    unsigned int                                                      arr3_tb2_size;
    unsigned int                                                      arr3_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB145                          om_data145;
    unsigned int                                                      arr3_array_para0;
    unsigned int                                                      arr3_array_para1;
    unsigned int                                                      arr3_array_para2;
    unsigned int                                                      arr3_array_para3;
    unsigned int                                                      arr3_array_para4;
    unsigned int                                                      arr3_reserved_3;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB152                          om_data152;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB153                          om_data153;
    unsigned int                                                      arr4_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB155                          om_data155;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB156                          om_data156;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB157                          om_data157;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB158                          om_data158;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB159                          om_data159;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB160                          om_data160;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB161                          om_data161;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB162                          om_data162;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB163                          om_data163;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB164                          om_data164;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB165                          om_data165;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB166                          om_data166;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB167                          om_data167;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB168                          om_data168;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB169                          om_data169;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB170                          om_data170;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB171                          om_data171;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB172                          om_data172;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB173                          om_data173;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB174                          om_data174;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB175                          om_data175;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB176                          om_data176;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB177                          om_data177;
    unsigned int                                                      arr4_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB179                          om_data179;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB180                          om_data180;
    unsigned int                                                      arr4_tb2_size;
    unsigned int                                                      arr4_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB183                          om_data183;
    unsigned int                                                      arr4_array_para0;
    unsigned int                                                      arr4_array_para1;
    unsigned int                                                      arr4_array_para2;
    unsigned int                                                      arr4_array_para3;
    unsigned int                                                      arr4_array_para4;
    unsigned int                                                      arr4_reserved_4;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB190                          om_data190;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB191                          om_data191;
    unsigned int                                                      arr5_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB193                          om_data193;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB194                          om_data194;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB195                          om_data195;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB196                          om_data196;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB197                          om_data197;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB198                          om_data198;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB199                          om_data199;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB200                          om_data200;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB201                          om_data201;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB202                          om_data202;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB203                          om_data203;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB204                          om_data204;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB205                          om_data205;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB206                          om_data206;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB207                          om_data207;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB208                          om_data208;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB209                          om_data209;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB210                          om_data210;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB211                          om_data211;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB212                          om_data212;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB213                          om_data213;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB214                          om_data214;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB215                          om_data215;
    unsigned int                                                      arr5_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB217                          om_data217;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB218                          om_data218;
    unsigned int                                                      arr5_tb2_size;
    unsigned int                                                      arr5_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB221                          om_data221;
    unsigned int                                                      arr5_array_para0;
    unsigned int                                                      arr5_array_para1;
    unsigned int                                                      arr5_array_para2;
    unsigned int                                                      arr5_array_para3;
    unsigned int                                                      arr5_array_para4;
    unsigned int                                                      arr5_reserved_5;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB228                          om_data228;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB229                          om_data229;
    unsigned int                                                      arr6_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB231                          om_data231;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB232                          om_data232;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB233                          om_data233;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB234                          om_data234;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB235                          om_data235;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB236                          om_data236;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB237                          om_data237;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB238                          om_data238;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB239                          om_data239;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB240                          om_data240;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB241                          om_data241;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB242                          om_data242;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB243                          om_data243;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB244                          om_data244;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB245                          om_data245;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB246                          om_data246;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB247                          om_data247;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB248                          om_data248;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB249                          om_data249;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB250                          om_data250;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB251                          om_data251;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB252                          om_data252;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB253                          om_data253;
    unsigned int                                                      arr6_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB255                          om_data255;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB256                          om_data256;
    unsigned int                                                      arr6_tb2_size;
    unsigned int                                                      arr6_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB259                          om_data259;
    unsigned int                                                      arr6_array_para0;
    unsigned int                                                      arr6_array_para1;
    unsigned int                                                      arr6_array_para2;
    unsigned int                                                      arr6_array_para3;
    unsigned int                                                      arr6_array_para4;
    unsigned int                                                      arr6_reserved_6;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB266                          om_data266;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB267                          om_data267;
    unsigned int                                                      arr7_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB269                          om_data269;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB270                          om_data270;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB271                          om_data271;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB272                          om_data272;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB273                          om_data273;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB274                          om_data274;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB275                          om_data275;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB276                          om_data276;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB277                          om_data277;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB278                          om_data278;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB279                          om_data279;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB280                          om_data280;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB281                          om_data281;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB282                          om_data282;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB283                          om_data283;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB284                          om_data284;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB285                          om_data285;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB286                          om_data286;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB287                          om_data287;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB288                          om_data288;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB289                          om_data289;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB290                          om_data290;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB291                          om_data291;
    unsigned int                                                      arr7_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB293                          om_data293;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB294                          om_data294;
    unsigned int                                                      arr7_tb2_size;
    unsigned int                                                      arr7_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB297                          om_data297;
    unsigned int                                                      arr7_array_para0;
    unsigned int                                                      arr7_array_para1;
    unsigned int                                                      arr7_array_para2;
    unsigned int                                                      arr7_array_para3;
    unsigned int                                                      arr7_array_para4;
    unsigned int                                                      arr7_reserved_7;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB304                          om_data304;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB305                          om_data305;
    unsigned int                                                      arr8_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB307                          om_data307;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB308                          om_data308;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB309                          om_data309;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB310                          om_data310;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB311                          om_data311;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB312                          om_data312;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB313                          om_data313;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB314                          om_data314;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB315                          om_data315;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB316                          om_data316;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB317                          om_data317;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB318                          om_data318;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB319                          om_data319;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB320                          om_data320;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB321                          om_data321;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB322                          om_data322;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB323                          om_data323;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB324                          om_data324;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB325                          om_data325;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB326                          om_data326;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB327                          om_data327;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB328                          om_data328;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB329                          om_data329;
    unsigned int                                                      arr8_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB331                          om_data331;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB332                          om_data332;
    unsigned int                                                      arr8_tb2_size;
    unsigned int                                                      arr8_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB335                          om_data335;
    unsigned int                                                      arr8_array_para0;
    unsigned int                                                      arr8_array_para1;
    unsigned int                                                      arr8_array_para2;
    unsigned int                                                      arr8_array_para3;
    unsigned int                                                      arr8_array_para4;
    unsigned int                                                      arr8_reserved_8;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB342                          om_data342;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB343                          om_data343;
    unsigned int                                                      arr9_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB345                          om_data345;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB346                          om_data346;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB347                          om_data347;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB348                          om_data348;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB349                          om_data349;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB350                          om_data350;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB351                          om_data351;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB352                          om_data352;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB353                          om_data353;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB354                          om_data354;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB355                          om_data355;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB356                          om_data356;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB357                          om_data357;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB358                          om_data358;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB359                          om_data359;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB360                          om_data360;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB361                          om_data361;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB362                          om_data362;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB363                          om_data363;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB364                          om_data364;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB365                          om_data365;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB366                          om_data366;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB367                          om_data367;
    unsigned int                                                      arr9_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB369                          om_data369;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB370                          om_data370;
    unsigned int                                                      arr9_tb2_size;
    unsigned int                                                      arr9_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB373                          om_data373;
    unsigned int                                                      arr9_array_para0;
    unsigned int                                                      arr9_array_para1;
    unsigned int                                                      arr9_array_para2;
    unsigned int                                                      arr9_array_para3;
    unsigned int                                                      arr9_array_para4;
    unsigned int                                                      arr9_reserved_9;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB380                          om_data380;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB381                          om_data381;
    unsigned int                                                      arr10_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB383                          om_data383;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB384                          om_data384;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB385                          om_data385;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB386                          om_data386;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB387                          om_data387;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB388                          om_data388;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB389                          om_data389;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB390                          om_data390;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB391                          om_data391;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB392                          om_data392;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB393                          om_data393;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB394                          om_data394;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB395                          om_data395;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB396                          om_data396;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB397                          om_data397;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB398                          om_data398;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB399                          om_data399;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB400                          om_data400;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB401                          om_data401;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB402                          om_data402;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB403                          om_data403;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB404                          om_data404;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB405                          om_data405;
    unsigned int                                                      arr10_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB407                          om_data407;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB408                          om_data408;
    unsigned int                                                      arr10_tb2_size;
    unsigned int                                                      arr10_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB411                          om_data411;
    unsigned int                                                      arr10_array_para0;
    unsigned int                                                      arr10_array_para1;
    unsigned int                                                      arr10_array_para2;
    unsigned int                                                      arr10_array_para3;
    unsigned int                                                      arr10_array_para4;
    unsigned int                                                      arr10_reserved_10;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB418                          om_data418;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB419                          om_data419;
    unsigned int                                                      arr11_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB421                          om_data421;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB422                          om_data422;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB423                          om_data423;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB424                          om_data424;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB425                          om_data425;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB426                          om_data426;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB427                          om_data427;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB428                          om_data428;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB429                          om_data429;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB430                          om_data430;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB431                          om_data431;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB432                          om_data432;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB433                          om_data433;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB434                          om_data434;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB435                          om_data435;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB436                          om_data436;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB437                          om_data437;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB438                          om_data438;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB439                          om_data439;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB440                          om_data440;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB441                          om_data441;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB442                          om_data442;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB443                          om_data443;
    unsigned int                                                      arr11_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB445                          om_data445;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB446                          om_data446;
    unsigned int                                                      arr11_tb2_size;
    unsigned int                                                      arr11_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB449                          om_data449;
    unsigned int                                                      arr11_array_para0;
    unsigned int                                                      arr11_array_para1;
    unsigned int                                                      arr11_array_para2;
    unsigned int                                                      arr11_array_para3;
    unsigned int                                                      arr11_array_para4;
    unsigned int                                                      arr11_reserved_11;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB456                          om_data456;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB457                          om_data457;
    unsigned int                                                      arr12_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB459                          om_data459;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB460                          om_data460;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB461                          om_data461;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB462                          om_data462;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB463                          om_data463;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB464                          om_data464;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB465                          om_data465;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB466                          om_data466;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB467                          om_data467;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB468                          om_data468;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB469                          om_data469;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB470                          om_data470;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB471                          om_data471;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB472                          om_data472;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB473                          om_data473;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB474                          om_data474;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB475                          om_data475;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB476                          om_data476;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB477                          om_data477;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB478                          om_data478;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB479                          om_data479;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB480                          om_data480;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB481                          om_data481;
    unsigned int                                                      arr12_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB483                          om_data483;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB484                          om_data484;
    unsigned int                                                      arr12_tb2_size;
    unsigned int                                                      arr12_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB487                          om_data487;
    unsigned int                                                      arr12_array_para0;
    unsigned int                                                      arr12_array_para1;
    unsigned int                                                      arr12_array_para2;
    unsigned int                                                      arr12_array_para3;
    unsigned int                                                      arr12_array_para4;
    unsigned int                                                      arr12_reserved_12;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB494                          om_data494;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB495                          om_data495;
    unsigned int                                                      arr13_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB497                          om_data497;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB498                          om_data498;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB499                          om_data499;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB500                          om_data500;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB501                          om_data501;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB502                          om_data502;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB503                          om_data503;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB504                          om_data504;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB505                          om_data505;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB506                          om_data506;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB507                          om_data507;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB508                          om_data508;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB509                          om_data509;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB510                          om_data510;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB511                          om_data511;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB512                          om_data512;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB513                          om_data513;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB514                          om_data514;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB515                          om_data515;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB516                          om_data516;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB517                          om_data517;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB518                          om_data518;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB519                          om_data519;
    unsigned int                                                      arr13_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB521                          om_data521;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB522                          om_data522;
    unsigned int                                                      arr13_tb2_size;
    unsigned int                                                      arr13_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB525                          om_data525;
    unsigned int                                                      arr13_array_para0;
    unsigned int                                                      arr13_array_para1;
    unsigned int                                                      arr13_array_para2;
    unsigned int                                                      arr13_array_para3;
    unsigned int                                                      arr13_array_para4;
    unsigned int                                                      arr13_reserved_13;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB532                          om_data532;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB533                          om_data533;
    unsigned int                                                      arr14_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB535                          om_data535;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB536                          om_data536;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB537                          om_data537;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB538                          om_data538;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB539                          om_data539;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB540                          om_data540;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB541                          om_data541;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB542                          om_data542;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB543                          om_data543;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB544                          om_data544;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB545                          om_data545;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB546                          om_data546;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB547                          om_data547;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB548                          om_data548;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB549                          om_data549;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB550                          om_data550;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB551                          om_data551;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB552                          om_data552;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB553                          om_data553;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB554                          om_data554;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB555                          om_data555;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB556                          om_data556;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB557                          om_data557;
    unsigned int                                                      arr14_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB559                          om_data559;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB560                          om_data560;
    unsigned int                                                      arr14_tb2_size;
    unsigned int                                                      arr14_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB563                          om_data563;
    unsigned int                                                      arr14_array_para0;
    unsigned int                                                      arr14_array_para1;
    unsigned int                                                      arr14_array_para2;
    unsigned int                                                      arr14_array_para3;
    unsigned int                                                      arr14_array_para4;
    unsigned int                                                      arr14_reserved_14;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB570                          om_data570;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB571                          om_data571;
    unsigned int                                                      arr15_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB573                          om_data573;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB574                          om_data574;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB575                          om_data575;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB576                          om_data576;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB577                          om_data577;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB578                          om_data578;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB579                          om_data579;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB580                          om_data580;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB581                          om_data581;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB582                          om_data582;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB583                          om_data583;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB584                          om_data584;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB585                          om_data585;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB586                          om_data586;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB587                          om_data587;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB588                          om_data588;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB589                          om_data589;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB590                          om_data590;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB591                          om_data591;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB592                          om_data592;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB593                          om_data593;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB594                          om_data594;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB595                          om_data595;
    unsigned int                                                      arr15_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB597                          om_data597;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB598                          om_data598;
    unsigned int                                                      arr15_tb2_size;
    unsigned int                                                      arr15_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB601                          om_data601;
    unsigned int                                                      arr15_array_para0;
    unsigned int                                                      arr15_array_para1;
    unsigned int                                                      arr15_array_para2;
    unsigned int                                                      arr15_array_para3;
    unsigned int                                                      arr15_array_para4;
    unsigned int                                                      arr15_reserved_15;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB0                            om_data0;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB1                            om_data1;
    unsigned int                                                      arr0_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB3                            om_data3;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB4                            om_data4;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB5                            om_data5;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB6                            om_data6;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB7                            om_data7;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB8                            om_data8;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB9                            om_data9;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB10                           om_data10;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB11                           om_data11;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB12                           om_data12;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB13                           om_data13;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB14                           om_data14;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB15                           om_data15;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB16                           om_data16;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB17                           om_data17;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB18                           om_data18;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB19                           om_data19;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB20                           om_data20;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB21                           om_data21;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB22                           om_data22;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB23                           om_data23;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB24                           om_data24;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB25                           om_data25;
    unsigned int                                                      arr0_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB27                           om_data27;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB28                           om_data28;
    unsigned int                                                      arr0_tb2_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB30                           om_data30;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB31                           om_data31;
    unsigned int                                                      arr0_array_para0;
    unsigned int                                                      arr0_array_para1;
    unsigned int                                                      arr0_array_para2;
    unsigned int                                                      arr0_array_para3;
    unsigned int                                                      arr0_array_para4;
    unsigned int                                                      arr0_reserved_0;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB38                           om_data38;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB39                           om_data39;
    unsigned int                                                      arr1_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB41                           om_data41;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB42                           om_data42;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB43                           om_data43;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB44                           om_data44;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB45                           om_data45;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB46                           om_data46;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB47                           om_data47;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB48                           om_data48;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB49                           om_data49;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB50                           om_data50;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB51                           om_data51;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB52                           om_data52;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB53                           om_data53;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB54                           om_data54;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB55                           om_data55;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB56                           om_data56;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB57                           om_data57;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB58                           om_data58;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB59                           om_data59;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB60                           om_data60;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB61                           om_data61;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB62                           om_data62;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB63                           om_data63;
    unsigned int                                                      arr1_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB65                           om_data65;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB66                           om_data66;
    unsigned int                                                      arr1_tb2_size;
    unsigned int                                                      arr1_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB69                           om_data69;
    unsigned int                                                      arr1_array_para0;
    unsigned int                                                      arr1_array_para1;
    unsigned int                                                      arr1_array_para2;
    unsigned int                                                      arr1_array_para3;
    unsigned int                                                      arr1_array_para4;
    unsigned int                                                      arr1_reserved_1;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB76                           om_data76;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB77                           om_data77;
    unsigned int                                                      arr2_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB79                           om_data79;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB80                           om_data80;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB81                           om_data81;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB82                           om_data82;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB83                           om_data83;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB84                           om_data84;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB85                           om_data85;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB86                           om_data86;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB87                           om_data87;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB88                           om_data88;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB89                           om_data89;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB90                           om_data90;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB91                           om_data91;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB92                           om_data92;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB93                           om_data93;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB94                           om_data94;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB95                           om_data95;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB96                           om_data96;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB97                           om_data97;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB98                           om_data98;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB99                           om_data99;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB100                          om_data100;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB101                          om_data101;
    unsigned int                                                      arr2_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB103                          om_data103;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB104                          om_data104;
    unsigned int                                                      arr2_tb2_size;
    unsigned int                                                      arr2_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB107                          om_data107;
    unsigned int                                                      arr2_array_para0;
    unsigned int                                                      arr2_array_para1;
    unsigned int                                                      arr2_array_para2;
    unsigned int                                                      arr2_array_para3;
    unsigned int                                                      arr2_array_para4;
    unsigned int                                                      arr2_reserved_2;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB114                          om_data114;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB115                          om_data115;
    unsigned int                                                      arr3_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB117                          om_data117;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB118                          om_data118;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB119                          om_data119;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB120                          om_data120;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB121                          om_data121;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB122                          om_data122;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB123                          om_data123;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB124                          om_data124;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB125                          om_data125;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB126                          om_data126;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB127                          om_data127;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB128                          om_data128;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB129                          om_data129;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB130                          om_data130;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB131                          om_data131;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB132                          om_data132;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB133                          om_data133;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB134                          om_data134;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB135                          om_data135;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB136                          om_data136;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB137                          om_data137;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB138                          om_data138;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB139                          om_data139;
    unsigned int                                                      arr3_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB141                          om_data141;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB142                          om_data142;
    unsigned int                                                      arr3_tb2_size;
    unsigned int                                                      arr3_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB145                          om_data145;
    unsigned int                                                      arr3_array_para0;
    unsigned int                                                      arr3_array_para1;
    unsigned int                                                      arr3_array_para2;
    unsigned int                                                      arr3_array_para3;
    unsigned int                                                      arr3_array_para4;
    unsigned int                                                      arr3_reserved_3;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB152                          om_data152;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB153                          om_data153;
    unsigned int                                                      arr4_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB155                          om_data155;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB156                          om_data156;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB157                          om_data157;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB158                          om_data158;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB159                          om_data159;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB160                          om_data160;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB161                          om_data161;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB162                          om_data162;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB163                          om_data163;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB164                          om_data164;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB165                          om_data165;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB166                          om_data166;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB167                          om_data167;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB168                          om_data168;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB169                          om_data169;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB170                          om_data170;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB171                          om_data171;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB172                          om_data172;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB173                          om_data173;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB174                          om_data174;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB175                          om_data175;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB176                          om_data176;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB177                          om_data177;
    unsigned int                                                      arr4_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB179                          om_data179;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB180                          om_data180;
    unsigned int                                                      arr4_tb2_size;
    unsigned int                                                      arr4_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB183                          om_data183;
    unsigned int                                                      arr4_array_para0;
    unsigned int                                                      arr4_array_para1;
    unsigned int                                                      arr4_array_para2;
    unsigned int                                                      arr4_array_para3;
    unsigned int                                                      arr4_array_para4;
    unsigned int                                                      arr4_reserved_4;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB190                          om_data190;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB191                          om_data191;
    unsigned int                                                      arr5_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB193                          om_data193;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB194                          om_data194;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB195                          om_data195;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB196                          om_data196;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB197                          om_data197;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB198                          om_data198;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB199                          om_data199;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB200                          om_data200;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB201                          om_data201;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB202                          om_data202;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB203                          om_data203;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB204                          om_data204;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB205                          om_data205;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB206                          om_data206;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB207                          om_data207;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB208                          om_data208;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB209                          om_data209;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB210                          om_data210;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB211                          om_data211;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB212                          om_data212;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB213                          om_data213;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB214                          om_data214;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB215                          om_data215;
    unsigned int                                                      arr5_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB217                          om_data217;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB218                          om_data218;
    unsigned int                                                      arr5_tb2_size;
    unsigned int                                                      arr5_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB221                          om_data221;
    unsigned int                                                      arr5_array_para0;
    unsigned int                                                      arr5_array_para1;
    unsigned int                                                      arr5_array_para2;
    unsigned int                                                      arr5_array_para3;
    unsigned int                                                      arr5_array_para4;
    unsigned int                                                      arr5_reserved_5;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB228                          om_data228;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB229                          om_data229;
    unsigned int                                                      arr6_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB231                          om_data231;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB232                          om_data232;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB233                          om_data233;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB234                          om_data234;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB235                          om_data235;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB236                          om_data236;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB237                          om_data237;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB238                          om_data238;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB239                          om_data239;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB240                          om_data240;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB241                          om_data241;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB242                          om_data242;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB243                          om_data243;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB244                          om_data244;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB245                          om_data245;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB246                          om_data246;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB247                          om_data247;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB248                          om_data248;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB249                          om_data249;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB250                          om_data250;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB251                          om_data251;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB252                          om_data252;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB253                          om_data253;
    unsigned int                                                      arr6_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB255                          om_data255;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB256                          om_data256;
    unsigned int                                                      arr6_tb2_size;
    unsigned int                                                      arr6_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB259                          om_data259;
    unsigned int                                                      arr6_array_para0;
    unsigned int                                                      arr6_array_para1;
    unsigned int                                                      arr6_array_para2;
    unsigned int                                                      arr6_array_para3;
    unsigned int                                                      arr6_array_para4;
    unsigned int                                                      arr6_reserved_6;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB266                          om_data266;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB267                          om_data267;
    unsigned int                                                      arr7_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB269                          om_data269;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB270                          om_data270;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB271                          om_data271;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB272                          om_data272;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB273                          om_data273;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB274                          om_data274;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB275                          om_data275;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB276                          om_data276;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB277                          om_data277;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB278                          om_data278;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB279                          om_data279;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB280                          om_data280;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB281                          om_data281;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB282                          om_data282;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB283                          om_data283;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB284                          om_data284;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB285                          om_data285;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB286                          om_data286;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB287                          om_data287;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB288                          om_data288;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB289                          om_data289;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB290                          om_data290;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB291                          om_data291;
    unsigned int                                                      arr7_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB293                          om_data293;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB294                          om_data294;
    unsigned int                                                      arr7_tb2_size;
    unsigned int                                                      arr7_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB297                          om_data297;
    unsigned int                                                      arr7_array_para0;
    unsigned int                                                      arr7_array_para1;
    unsigned int                                                      arr7_array_para2;
    unsigned int                                                      arr7_array_para3;
    unsigned int                                                      arr7_array_para4;
    unsigned int                                                      arr7_reserved_7;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB304                          om_data304;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB305                          om_data305;
    unsigned int                                                      arr8_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB307                          om_data307;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB308                          om_data308;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB309                          om_data309;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB310                          om_data310;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB311                          om_data311;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB312                          om_data312;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB313                          om_data313;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB314                          om_data314;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB315                          om_data315;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB316                          om_data316;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB317                          om_data317;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB318                          om_data318;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB319                          om_data319;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB320                          om_data320;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB321                          om_data321;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB322                          om_data322;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB323                          om_data323;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB324                          om_data324;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB325                          om_data325;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB326                          om_data326;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB327                          om_data327;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB328                          om_data328;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB329                          om_data329;
    unsigned int                                                      arr8_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB331                          om_data331;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB332                          om_data332;
    unsigned int                                                      arr8_tb2_size;
    unsigned int                                                      arr8_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB335                          om_data335;
    unsigned int                                                      arr8_array_para0;
    unsigned int                                                      arr8_array_para1;
    unsigned int                                                      arr8_array_para2;
    unsigned int                                                      arr8_array_para3;
    unsigned int                                                      arr8_array_para4;
    unsigned int                                                      arr8_reserved_8;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB342                          om_data342;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB343                          om_data343;
    unsigned int                                                      arr9_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB345                          om_data345;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB346                          om_data346;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB347                          om_data347;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB348                          om_data348;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB349                          om_data349;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB350                          om_data350;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB351                          om_data351;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB352                          om_data352;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB353                          om_data353;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB354                          om_data354;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB355                          om_data355;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB356                          om_data356;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB357                          om_data357;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB358                          om_data358;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB359                          om_data359;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB360                          om_data360;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB361                          om_data361;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB362                          om_data362;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB363                          om_data363;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB364                          om_data364;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB365                          om_data365;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB366                          om_data366;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB367                          om_data367;
    unsigned int                                                      arr9_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB369                          om_data369;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB370                          om_data370;
    unsigned int                                                      arr9_tb2_size;
    unsigned int                                                      arr9_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB373                          om_data373;
    unsigned int                                                      arr9_array_para0;
    unsigned int                                                      arr9_array_para1;
    unsigned int                                                      arr9_array_para2;
    unsigned int                                                      arr9_array_para3;
    unsigned int                                                      arr9_array_para4;
    unsigned int                                                      arr9_reserved_9;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB380                          om_data380;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB381                          om_data381;
    unsigned int                                                      arr10_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB383                          om_data383;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB384                          om_data384;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB385                          om_data385;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB386                          om_data386;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB387                          om_data387;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB388                          om_data388;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB389                          om_data389;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB390                          om_data390;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB391                          om_data391;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB392                          om_data392;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB393                          om_data393;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB394                          om_data394;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB395                          om_data395;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB396                          om_data396;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB397                          om_data397;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB398                          om_data398;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB399                          om_data399;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB400                          om_data400;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB401                          om_data401;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB402                          om_data402;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB403                          om_data403;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB404                          om_data404;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB405                          om_data405;
    unsigned int                                                      arr10_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB407                          om_data407;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB408                          om_data408;
    unsigned int                                                      arr10_tb2_size;
    unsigned int                                                      arr10_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB411                          om_data411;
    unsigned int                                                      arr10_array_para0;
    unsigned int                                                      arr10_array_para1;
    unsigned int                                                      arr10_array_para2;
    unsigned int                                                      arr10_array_para3;
    unsigned int                                                      arr10_array_para4;
    unsigned int                                                      arr10_reserved_10;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB418                          om_data418;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB419                          om_data419;
    unsigned int                                                      arr11_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB421                          om_data421;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB422                          om_data422;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB423                          om_data423;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB424                          om_data424;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB425                          om_data425;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB426                          om_data426;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB427                          om_data427;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB428                          om_data428;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB429                          om_data429;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB430                          om_data430;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB431                          om_data431;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB432                          om_data432;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB433                          om_data433;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB434                          om_data434;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB435                          om_data435;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB436                          om_data436;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB437                          om_data437;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB438                          om_data438;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB439                          om_data439;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB440                          om_data440;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB441                          om_data441;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB442                          om_data442;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB443                          om_data443;
    unsigned int                                                      arr11_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB445                          om_data445;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB446                          om_data446;
    unsigned int                                                      arr11_tb2_size;
    unsigned int                                                      arr11_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB449                          om_data449;
    unsigned int                                                      arr11_array_para0;
    unsigned int                                                      arr11_array_para1;
    unsigned int                                                      arr11_array_para2;
    unsigned int                                                      arr11_array_para3;
    unsigned int                                                      arr11_array_para4;
    unsigned int                                                      arr11_reserved_11;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB456                          om_data456;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB457                          om_data457;
    unsigned int                                                      arr12_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB459                          om_data459;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB460                          om_data460;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB461                          om_data461;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB462                          om_data462;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB463                          om_data463;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB464                          om_data464;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB465                          om_data465;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB466                          om_data466;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB467                          om_data467;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB468                          om_data468;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB469                          om_data469;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB470                          om_data470;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB471                          om_data471;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB472                          om_data472;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB473                          om_data473;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB474                          om_data474;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB475                          om_data475;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB476                          om_data476;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB477                          om_data477;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB478                          om_data478;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB479                          om_data479;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB480                          om_data480;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB481                          om_data481;
    unsigned int                                                      arr12_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB483                          om_data483;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB484                          om_data484;
    unsigned int                                                      arr12_tb2_size;
    unsigned int                                                      arr12_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB487                          om_data487;
    unsigned int                                                      arr12_array_para0;
    unsigned int                                                      arr12_array_para1;
    unsigned int                                                      arr12_array_para2;
    unsigned int                                                      arr12_array_para3;
    unsigned int                                                      arr12_array_para4;
    unsigned int                                                      arr12_reserved_12;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB494                          om_data494;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB495                          om_data495;
    unsigned int                                                      arr13_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB497                          om_data497;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB498                          om_data498;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB499                          om_data499;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB500                          om_data500;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB501                          om_data501;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB502                          om_data502;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB503                          om_data503;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB504                          om_data504;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB505                          om_data505;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB506                          om_data506;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB507                          om_data507;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB508                          om_data508;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB509                          om_data509;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB510                          om_data510;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB511                          om_data511;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB512                          om_data512;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB513                          om_data513;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB514                          om_data514;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB515                          om_data515;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB516                          om_data516;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB517                          om_data517;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB518                          om_data518;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB519                          om_data519;
    unsigned int                                                      arr13_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB521                          om_data521;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB522                          om_data522;
    unsigned int                                                      arr13_tb2_size;
    unsigned int                                                      arr13_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB525                          om_data525;
    unsigned int                                                      arr13_array_para0;
    unsigned int                                                      arr13_array_para1;
    unsigned int                                                      arr13_array_para2;
    unsigned int                                                      arr13_array_para3;
    unsigned int                                                      arr13_array_para4;
    unsigned int                                                      arr13_reserved_13;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB532                          om_data532;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB533                          om_data533;
    unsigned int                                                      arr14_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB535                          om_data535;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB536                          om_data536;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB537                          om_data537;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB538                          om_data538;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB539                          om_data539;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB540                          om_data540;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB541                          om_data541;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB542                          om_data542;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB543                          om_data543;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB544                          om_data544;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB545                          om_data545;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB546                          om_data546;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB547                          om_data547;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB548                          om_data548;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB549                          om_data549;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB550                          om_data550;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB551                          om_data551;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB552                          om_data552;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB553                          om_data553;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB554                          om_data554;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB555                          om_data555;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB556                          om_data556;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB557                          om_data557;
    unsigned int                                                      arr14_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB559                          om_data559;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB560                          om_data560;
    unsigned int                                                      arr14_tb2_size;
    unsigned int                                                      arr14_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB563                          om_data563;
    unsigned int                                                      arr14_array_para0;
    unsigned int                                                      arr14_array_para1;
    unsigned int                                                      arr14_array_para2;
    unsigned int                                                      arr14_array_para3;
    unsigned int                                                      arr14_array_para4;
    unsigned int                                                      arr14_reserved_14;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB570                          om_data570;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB571                          om_data571;
    unsigned int                                                      arr15_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB573                          om_data573;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB574                          om_data574;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB575                          om_data575;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB576                          om_data576;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB577                          om_data577;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB578                          om_data578;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB579                          om_data579;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB580                          om_data580;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB581                          om_data581;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB582                          om_data582;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB583                          om_data583;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB584                          om_data584;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB585                          om_data585;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB586                          om_data586;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB587                          om_data587;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB588                          om_data588;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB589                          om_data589;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB590                          om_data590;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB591                          om_data591;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB592                          om_data592;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB593                          om_data593;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB594                          om_data594;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB595                          om_data595;
    unsigned int                                                      arr15_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB597                          om_data597;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB598                          om_data598;
    unsigned int                                                      arr15_tb2_size;
    unsigned int                                                      arr15_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_SUB601                          om_data601;
    unsigned int                                                      arr15_array_para0;
    unsigned int                                                      arr15_array_para1;
    unsigned int                                                      arr15_array_para2;
    unsigned int                                                      arr15_array_para3;
    unsigned int                                                      arr15_array_para4;
    unsigned int                                                      arr15_reserved_15;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY0_BBP_MC;

typedef union {
    struct {
        unsigned int arr0_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr0_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr0_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr0_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB0;

typedef union {
    struct {
        unsigned int arr0_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr0_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr0_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr0_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB1;

typedef union {
    struct {
        unsigned int arr0_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr0_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr0_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr0_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB3;

typedef union {
    struct {
        unsigned int arr0_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr0_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr0_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr0_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB4;

typedef union {
    struct {
        unsigned int arr0_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr0_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr0_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr0_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB5;

typedef union {
    struct {
        unsigned int arr0_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr0_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr0_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr0_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB6;

typedef union {
    struct {
        unsigned int arr0_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr0_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr0_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr0_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB7;

typedef union {
    struct {
        unsigned int arr0_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr0_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr0_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr0_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB8;

typedef union {
    struct {
        unsigned int arr0_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr0_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr0_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr0_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB9;

typedef union {
    struct {
        unsigned int arr0_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr0_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr0_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr0_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB10;

typedef union {
    struct {
        unsigned int arr0_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr0_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr0_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr0_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB11;

typedef union {
    struct {
        unsigned int arr0_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr0_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr0_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr0_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB12;

typedef union {
    struct {
        unsigned int arr0_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr0_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr0_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr0_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB13;

typedef union {
    struct {
        unsigned int arr0_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr0_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr0_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr0_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr0_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB14;

typedef union {
    struct {
        unsigned int arr0_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr0_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr0_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr0_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB15;

typedef union {
    struct {
        unsigned int arr0_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr0_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr0_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr0_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB16;

typedef union {
    struct {
        unsigned int arr0_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr0_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr0_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr0_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB17;

typedef union {
    struct {
        unsigned int arr0_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr0_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr0_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB18;

typedef union {
    struct {
        unsigned int arr0_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr0_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr0_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB19;

typedef union {
    struct {
        unsigned int arr0_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr0_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr0_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB20;

typedef union {
    struct {
        unsigned int arr0_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr0_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr0_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB21;

typedef union {
    struct {
        unsigned int arr0_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr0_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB22;

typedef union {
    struct {
        unsigned int arr0_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr0_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr0_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr0_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB23;

typedef union {
    struct {
        unsigned int arr0_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr0_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr0_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB24;

typedef union {
    struct {
        unsigned int arr0_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr0_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr0_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB25;

typedef union {
    struct {
        unsigned int arr0_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr0_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr0_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB27;

typedef union {
    struct {
        unsigned int arr0_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr0_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr0_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB28;

typedef union {
    struct {
        unsigned int arr0_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr0_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr0_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB31;

typedef union {
    struct {
        unsigned int arr1_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr1_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr1_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr1_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB38;

typedef union {
    struct {
        unsigned int arr1_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr1_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr1_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr1_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB39;

typedef union {
    struct {
        unsigned int arr1_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr1_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr1_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr1_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB41;

typedef union {
    struct {
        unsigned int arr1_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr1_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr1_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr1_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB42;

typedef union {
    struct {
        unsigned int arr1_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr1_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr1_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr1_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB43;

typedef union {
    struct {
        unsigned int arr1_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr1_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr1_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr1_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB44;

typedef union {
    struct {
        unsigned int arr1_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr1_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr1_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr1_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB45;

typedef union {
    struct {
        unsigned int arr1_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr1_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr1_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr1_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB46;

typedef union {
    struct {
        unsigned int arr1_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr1_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr1_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr1_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB47;

typedef union {
    struct {
        unsigned int arr1_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr1_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr1_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr1_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB48;

typedef union {
    struct {
        unsigned int arr1_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr1_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr1_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr1_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB49;

typedef union {
    struct {
        unsigned int arr1_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr1_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr1_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr1_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB50;

typedef union {
    struct {
        unsigned int arr1_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr1_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr1_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr1_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB51;

typedef union {
    struct {
        unsigned int arr1_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr1_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr1_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr1_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr1_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB52;

typedef union {
    struct {
        unsigned int arr1_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr1_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr1_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr1_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB53;

typedef union {
    struct {
        unsigned int arr1_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr1_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr1_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr1_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB54;

typedef union {
    struct {
        unsigned int arr1_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr1_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr1_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr1_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB55;

typedef union {
    struct {
        unsigned int arr1_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr1_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr1_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB56;

typedef union {
    struct {
        unsigned int arr1_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr1_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr1_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB57;

typedef union {
    struct {
        unsigned int arr1_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr1_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr1_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB58;

typedef union {
    struct {
        unsigned int arr1_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr1_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr1_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB59;

typedef union {
    struct {
        unsigned int arr1_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr1_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB60;

typedef union {
    struct {
        unsigned int arr1_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr1_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr1_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr1_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB61;

typedef union {
    struct {
        unsigned int arr1_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr1_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr1_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB62;

typedef union {
    struct {
        unsigned int arr1_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr1_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr1_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB63;

typedef union {
    struct {
        unsigned int arr1_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr1_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr1_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB65;

typedef union {
    struct {
        unsigned int arr1_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr1_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr1_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB66;

typedef union {
    struct {
        unsigned int arr1_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr1_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr1_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB69;

typedef union {
    struct {
        unsigned int arr2_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr2_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr2_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr2_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB76;

typedef union {
    struct {
        unsigned int arr2_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr2_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr2_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr2_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB77;

typedef union {
    struct {
        unsigned int arr2_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr2_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr2_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr2_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB79;

typedef union {
    struct {
        unsigned int arr2_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr2_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr2_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr2_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB80;

typedef union {
    struct {
        unsigned int arr2_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr2_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr2_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr2_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB81;

typedef union {
    struct {
        unsigned int arr2_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr2_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr2_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr2_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB82;

typedef union {
    struct {
        unsigned int arr2_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr2_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr2_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr2_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB83;

typedef union {
    struct {
        unsigned int arr2_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr2_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr2_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr2_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB84;

typedef union {
    struct {
        unsigned int arr2_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr2_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr2_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr2_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB85;

typedef union {
    struct {
        unsigned int arr2_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr2_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr2_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr2_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB86;

typedef union {
    struct {
        unsigned int arr2_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr2_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr2_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr2_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB87;

typedef union {
    struct {
        unsigned int arr2_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr2_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr2_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr2_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB88;

typedef union {
    struct {
        unsigned int arr2_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr2_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr2_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr2_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB89;

typedef union {
    struct {
        unsigned int arr2_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr2_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr2_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr2_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr2_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB90;

typedef union {
    struct {
        unsigned int arr2_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr2_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr2_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr2_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB91;

typedef union {
    struct {
        unsigned int arr2_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr2_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr2_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr2_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB92;

typedef union {
    struct {
        unsigned int arr2_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr2_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr2_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr2_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB93;

typedef union {
    struct {
        unsigned int arr2_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr2_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr2_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB94;

typedef union {
    struct {
        unsigned int arr2_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr2_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr2_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB95;

typedef union {
    struct {
        unsigned int arr2_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr2_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr2_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB96;

typedef union {
    struct {
        unsigned int arr2_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr2_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr2_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB97;

typedef union {
    struct {
        unsigned int arr2_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr2_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB98;

typedef union {
    struct {
        unsigned int arr2_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr2_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr2_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr2_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB99;

typedef union {
    struct {
        unsigned int arr2_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr2_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr2_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB100;

typedef union {
    struct {
        unsigned int arr2_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr2_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr2_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB101;

typedef union {
    struct {
        unsigned int arr2_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr2_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr2_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB103;

typedef union {
    struct {
        unsigned int arr2_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr2_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr2_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB104;

typedef union {
    struct {
        unsigned int arr2_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr2_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr2_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB107;

typedef union {
    struct {
        unsigned int arr3_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr3_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr3_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr3_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB114;

typedef union {
    struct {
        unsigned int arr3_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr3_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr3_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr3_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB115;

typedef union {
    struct {
        unsigned int arr3_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr3_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr3_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr3_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB117;

typedef union {
    struct {
        unsigned int arr3_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr3_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr3_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr3_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB118;

typedef union {
    struct {
        unsigned int arr3_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr3_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr3_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr3_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB119;

typedef union {
    struct {
        unsigned int arr3_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr3_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr3_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr3_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB120;

typedef union {
    struct {
        unsigned int arr3_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr3_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr3_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr3_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB121;

typedef union {
    struct {
        unsigned int arr3_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr3_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr3_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr3_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB122;

typedef union {
    struct {
        unsigned int arr3_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr3_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr3_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr3_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB123;

typedef union {
    struct {
        unsigned int arr3_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr3_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr3_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr3_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB124;

typedef union {
    struct {
        unsigned int arr3_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr3_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr3_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr3_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB125;

typedef union {
    struct {
        unsigned int arr3_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr3_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr3_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr3_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB126;

typedef union {
    struct {
        unsigned int arr3_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr3_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr3_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr3_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB127;

typedef union {
    struct {
        unsigned int arr3_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr3_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr3_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr3_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr3_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB128;

typedef union {
    struct {
        unsigned int arr3_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr3_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr3_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr3_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB129;

typedef union {
    struct {
        unsigned int arr3_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr3_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr3_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr3_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB130;

typedef union {
    struct {
        unsigned int arr3_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr3_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr3_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr3_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB131;

typedef union {
    struct {
        unsigned int arr3_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr3_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr3_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB132;

typedef union {
    struct {
        unsigned int arr3_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr3_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr3_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB133;

typedef union {
    struct {
        unsigned int arr3_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr3_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr3_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB134;

typedef union {
    struct {
        unsigned int arr3_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr3_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr3_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB135;

typedef union {
    struct {
        unsigned int arr3_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr3_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB136;

typedef union {
    struct {
        unsigned int arr3_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr3_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr3_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr3_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB137;

typedef union {
    struct {
        unsigned int arr3_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr3_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr3_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB138;

typedef union {
    struct {
        unsigned int arr3_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr3_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr3_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB139;

typedef union {
    struct {
        unsigned int arr3_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr3_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr3_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB141;

typedef union {
    struct {
        unsigned int arr3_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr3_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr3_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB142;

typedef union {
    struct {
        unsigned int arr3_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr3_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr3_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB145;

typedef union {
    struct {
        unsigned int arr4_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr4_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr4_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr4_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB152;

typedef union {
    struct {
        unsigned int arr4_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr4_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr4_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr4_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB153;

typedef union {
    struct {
        unsigned int arr4_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr4_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr4_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr4_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB155;

typedef union {
    struct {
        unsigned int arr4_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr4_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr4_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr4_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB156;

typedef union {
    struct {
        unsigned int arr4_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr4_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr4_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr4_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB157;

typedef union {
    struct {
        unsigned int arr4_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr4_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr4_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr4_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB158;

typedef union {
    struct {
        unsigned int arr4_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr4_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr4_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr4_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB159;

typedef union {
    struct {
        unsigned int arr4_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr4_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr4_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr4_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB160;

typedef union {
    struct {
        unsigned int arr4_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr4_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr4_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr4_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB161;

typedef union {
    struct {
        unsigned int arr4_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr4_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr4_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr4_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB162;

typedef union {
    struct {
        unsigned int arr4_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr4_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr4_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr4_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB163;

typedef union {
    struct {
        unsigned int arr4_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr4_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr4_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr4_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB164;

typedef union {
    struct {
        unsigned int arr4_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr4_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr4_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr4_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB165;

typedef union {
    struct {
        unsigned int arr4_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr4_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr4_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr4_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr4_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB166;

typedef union {
    struct {
        unsigned int arr4_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr4_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr4_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr4_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB167;

typedef union {
    struct {
        unsigned int arr4_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr4_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr4_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr4_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB168;

typedef union {
    struct {
        unsigned int arr4_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr4_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr4_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr4_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB169;

typedef union {
    struct {
        unsigned int arr4_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr4_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr4_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB170;

typedef union {
    struct {
        unsigned int arr4_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr4_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr4_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB171;

typedef union {
    struct {
        unsigned int arr4_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr4_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr4_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB172;

typedef union {
    struct {
        unsigned int arr4_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr4_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr4_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB173;

typedef union {
    struct {
        unsigned int arr4_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr4_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB174;

typedef union {
    struct {
        unsigned int arr4_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr4_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr4_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr4_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB175;

typedef union {
    struct {
        unsigned int arr4_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr4_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr4_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB176;

typedef union {
    struct {
        unsigned int arr4_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr4_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr4_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB177;

typedef union {
    struct {
        unsigned int arr4_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr4_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr4_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB179;

typedef union {
    struct {
        unsigned int arr4_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr4_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr4_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB180;

typedef union {
    struct {
        unsigned int arr4_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr4_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr4_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB183;

typedef union {
    struct {
        unsigned int arr5_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr5_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr5_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr5_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB190;

typedef union {
    struct {
        unsigned int arr5_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr5_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr5_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr5_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB191;

typedef union {
    struct {
        unsigned int arr5_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr5_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr5_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr5_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB193;

typedef union {
    struct {
        unsigned int arr5_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr5_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr5_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr5_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB194;

typedef union {
    struct {
        unsigned int arr5_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr5_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr5_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr5_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB195;

typedef union {
    struct {
        unsigned int arr5_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr5_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr5_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr5_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB196;

typedef union {
    struct {
        unsigned int arr5_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr5_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr5_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr5_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB197;

typedef union {
    struct {
        unsigned int arr5_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr5_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr5_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr5_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB198;

typedef union {
    struct {
        unsigned int arr5_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr5_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr5_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr5_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB199;

typedef union {
    struct {
        unsigned int arr5_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr5_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr5_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr5_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB200;

typedef union {
    struct {
        unsigned int arr5_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr5_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr5_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr5_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB201;

typedef union {
    struct {
        unsigned int arr5_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr5_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr5_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr5_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB202;

typedef union {
    struct {
        unsigned int arr5_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr5_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr5_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr5_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB203;

typedef union {
    struct {
        unsigned int arr5_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr5_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr5_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr5_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr5_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB204;

typedef union {
    struct {
        unsigned int arr5_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr5_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr5_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr5_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB205;

typedef union {
    struct {
        unsigned int arr5_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr5_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr5_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr5_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB206;

typedef union {
    struct {
        unsigned int arr5_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr5_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr5_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr5_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB207;

typedef union {
    struct {
        unsigned int arr5_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr5_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr5_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB208;

typedef union {
    struct {
        unsigned int arr5_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr5_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr5_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB209;

typedef union {
    struct {
        unsigned int arr5_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr5_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr5_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB210;

typedef union {
    struct {
        unsigned int arr5_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr5_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr5_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB211;

typedef union {
    struct {
        unsigned int arr5_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr5_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB212;

typedef union {
    struct {
        unsigned int arr5_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr5_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr5_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr5_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB213;

typedef union {
    struct {
        unsigned int arr5_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr5_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr5_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB214;

typedef union {
    struct {
        unsigned int arr5_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr5_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr5_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB215;

typedef union {
    struct {
        unsigned int arr5_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr5_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr5_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB217;

typedef union {
    struct {
        unsigned int arr5_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr5_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr5_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB218;

typedef union {
    struct {
        unsigned int arr5_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr5_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr5_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB221;

typedef union {
    struct {
        unsigned int arr6_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr6_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr6_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr6_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB228;

typedef union {
    struct {
        unsigned int arr6_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr6_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr6_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr6_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB229;

typedef union {
    struct {
        unsigned int arr6_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr6_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr6_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr6_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB231;

typedef union {
    struct {
        unsigned int arr6_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr6_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr6_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr6_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB232;

typedef union {
    struct {
        unsigned int arr6_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr6_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr6_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr6_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB233;

typedef union {
    struct {
        unsigned int arr6_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr6_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr6_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr6_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB234;

typedef union {
    struct {
        unsigned int arr6_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr6_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr6_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr6_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB235;

typedef union {
    struct {
        unsigned int arr6_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr6_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr6_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr6_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB236;

typedef union {
    struct {
        unsigned int arr6_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr6_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr6_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr6_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB237;

typedef union {
    struct {
        unsigned int arr6_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr6_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr6_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr6_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB238;

typedef union {
    struct {
        unsigned int arr6_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr6_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr6_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr6_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB239;

typedef union {
    struct {
        unsigned int arr6_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr6_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr6_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr6_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB240;

typedef union {
    struct {
        unsigned int arr6_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr6_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr6_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr6_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB241;

typedef union {
    struct {
        unsigned int arr6_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr6_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr6_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr6_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr6_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB242;

typedef union {
    struct {
        unsigned int arr6_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr6_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr6_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr6_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB243;

typedef union {
    struct {
        unsigned int arr6_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr6_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr6_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr6_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB244;

typedef union {
    struct {
        unsigned int arr6_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr6_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr6_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr6_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB245;

typedef union {
    struct {
        unsigned int arr6_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr6_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr6_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB246;

typedef union {
    struct {
        unsigned int arr6_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr6_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr6_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB247;

typedef union {
    struct {
        unsigned int arr6_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr6_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr6_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB248;

typedef union {
    struct {
        unsigned int arr6_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr6_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr6_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB249;

typedef union {
    struct {
        unsigned int arr6_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr6_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB250;

typedef union {
    struct {
        unsigned int arr6_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr6_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr6_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr6_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB251;

typedef union {
    struct {
        unsigned int arr6_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr6_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr6_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB252;

typedef union {
    struct {
        unsigned int arr6_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr6_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr6_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB253;

typedef union {
    struct {
        unsigned int arr6_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr6_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr6_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB255;

typedef union {
    struct {
        unsigned int arr6_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr6_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr6_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB256;

typedef union {
    struct {
        unsigned int arr6_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr6_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr6_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB259;

typedef union {
    struct {
        unsigned int arr7_dci_type                                    :   8               ;    /* 7:0 */
        unsigned int arr7_r_idx                                       :   8               ;    /* 15:8 */
        unsigned int arr7_chnl_type                                   :   8               ;    /* 23:16 */
        unsigned int arr7_bwp_sw_flag                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB266;

typedef union {
    struct {
        unsigned int arr7_tb_valid0                                   :   8               ;    /* 7:0 */
        unsigned int arr7_tb_valid1                                   :   8               ;    /* 15:8 */
        unsigned int arr7_cif                                         :   8               ;    /* 23:16 */
        unsigned int arr7_bwp_ind                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB267;

typedef union {
    struct {
        unsigned int arr7_time_idx                                    :   8               ;    /* 7:0 */
        unsigned int arr7_vrb2prb_map                                 :   8               ;    /* 15:8 */
        unsigned int arr7_prb_bundl_size_indi                         :   8               ;    /* 23:16 */
        unsigned int arr7_rate_match_indi                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB269;

typedef union {
    struct {
        unsigned int arr7_zpcsi_rs_trigger                            :   8               ;    /* 7:0 */
        unsigned int arr7_tb0_mcs                                     :   8               ;    /* 15:8 */
        unsigned int arr7_tb0_ndi                                     :   8               ;    /* 23:16 */
        unsigned int arr7_tb0_rv                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB270;

typedef union {
    struct {
        unsigned int arr7_tb1_mcs                                     :   8               ;    /* 7:0 */
        unsigned int arr7_tb1_ndi                                     :   8               ;    /* 15:8 */
        unsigned int arr7_tb1_rv                                      :   8               ;    /* 23:16 */
        unsigned int arr7_harq_num                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB271;

typedef union {
    struct {
        unsigned int arr7_dai                                         :   8               ;    /* 7:0 */
        unsigned int arr7_pucch_tpc                                   :   8               ;    /* 15:8 */
        unsigned int arr7_pucch_sec_tpc                               :   8               ;    /* 23:16 */
        unsigned int arr7_pucch_indi                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB272;

typedef union {
    struct {
        unsigned int arr7_pds_harq_fbk_time_indi                      :   8               ;    /* 7:0 */
        unsigned int arr7_oneshot_harq_ack                            :   8               ;    /* 15:8 */
        unsigned int arr7_enh_type3                                   :   8               ;    /* 23:16 */
        unsigned int arr7_pdsch_group_ind                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB273;

typedef union {
    struct {
        unsigned int arr7_new_fbk                                     :   8               ;    /* 7:0 */
        unsigned int arr7_nrof_pdsch_group                            :   8               ;    /* 15:8 */
        unsigned int arr7_harq_ack_retx                               :   8               ;    /* 23:16 */
        unsigned int arr7_ant_port                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB274;

typedef union {
    struct {
        unsigned int arr7_reserved_0                                  :   8               ;    /* 7:0 */
        unsigned int arr7_tci                                         :   8               ;    /* 15:8 */
        unsigned int arr7_srs_req                                     :   8               ;    /* 23:16 */
        unsigned int arr7_srs_ofset                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB275;

typedef union {
    struct {
        unsigned int arr7_cbgti                                       :   8               ;    /* 7:0 */
        unsigned int arr7_cbgfi                                       :   8               ;    /* 15:8 */
        unsigned int arr7_dmrs_seq_init                               :   8               ;    /* 23:16 */
        unsigned int arr7_priority_ind                                :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB276;

typedef union {
    struct {
        unsigned int arr7_min_k0k2_ind                                :   8               ;    /* 7:0 */
        unsigned int arr7_dormancy_ind                                :   8               ;    /* 15:8 */
        unsigned int arr7_pdc_monitor_adaption                        :   8               ;    /* 23:16 */
        unsigned int arr7_pucch_cell_ind                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB277;

typedef union {
    struct {
        unsigned int arr7_dci42_harq_ack_en                           :   8               ;    /* 7:0 */
        unsigned int arr7_mcch_chg_notify                             :   8               ;    /* 15:8 */
        unsigned int arr7_sps_active_flag                             :   8               ;    /* 23:16 */
        unsigned int arr7_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB278;

typedef union {
    struct {
        unsigned int arr7_trs_availability                            :   8               ;    /* 7:0 */
        unsigned int arr7_short_msg_indi                              :   8               ;    /* 15:8 */
        unsigned int arr7_short_msg                                   :   8               ;    /* 23:16 */
        unsigned int arr7_lsbs_of_sfn                                 :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB279;

typedef union {
    struct {
        unsigned int arr7_prach_idx                                   :   4               ;    /* 3:0 */
        unsigned int arr7_ssb_idx                                     :   6               ;    /* 9:4 */
        unsigned int arr7_sul_ind                                     :   1               ;    /* 10 */
        unsigned int arr7_ra_prmb_idx                                 :   6               ;    /* 16:11 */
        unsigned int arr7_reserved_0                                  :   15              ;    /* 31:17 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB280;

typedef union {
    struct {
        unsigned int arr7_sys_info_indi                               :   8               ;    /* 7:0 */
        unsigned int arr7_tb_scaling                                  :   8               ;    /* 15:8 */
        unsigned int arr7_k1                                          :   8               ;    /* 23:16 */
        unsigned int arr7_res_alloc_type                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB281;

typedef union {
    struct {
        unsigned int arr7_pds_map_type                                :   8               ;    /* 7:0 */
        unsigned int arr7_k0                                          :   8               ;    /* 15:8 */
        unsigned int arr7_max_k0                                      :   8               ;    /* 23:16 */
        unsigned int arr7_reserved_0                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB282;

typedef union {
    struct {
        unsigned int arr7_sliv                                        :   8               ;    /* 7:0 */
        unsigned int arr7_prb_bundle_size                             :   8               ;    /* 15:8 */
        unsigned int arr7_reserved_0                                  :   8               ;    /* 23:16 */
        unsigned int arr7_dedi_pds_para_vld                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB283;

typedef union {
    struct {
        unsigned int arr7_sym_start                                   :   8               ;    /* 7:0 */
        unsigned int arr7_sym_len                                     :   8               ;    /* 15:8 */
        unsigned int arr7_rb_start                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB284;

typedef union {
    struct {
        unsigned int arr7_rbg_size                                    :   8               ;    /* 7:0 */
        unsigned int arr7_reserved_0                                  :   8               ;    /* 15:8 */
        unsigned int arr7_rb_num                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB285;

typedef union {
    struct {
        unsigned int arr7_cfg_type                                    :   8               ;    /* 7:0 */
        unsigned int arr7_bundle_size                                 :   8               ;    /* 15:8 */
        unsigned int arr7_bwp_rb_num                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB286;

typedef union {
    struct {
        unsigned int arr7_additional_pos                              :   8               ;    /* 7:0 */
        unsigned int arr7_max_len                                     :   8               ;    /* 15:8 */
        unsigned int arr7_dmrs_sym_bitmap                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB287;

typedef union {
    struct {
        unsigned int arr7_dmrs_re_bitmap                              :   16              ;    /* 15:0 */
        unsigned int arr7_port_bitmap                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB288;

typedef union {
    struct {
        unsigned int arr7_rbg_num                                     :   8               ;    /* 7:0 */
        unsigned int arr7_cdm_ind                                     :   8               ;    /* 15:8 */
        unsigned int arr7_dmrs_sym_len                                :   8               ;    /* 23:16 */
        unsigned int arr7_dmrs_num_per_pb                             :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB289;

typedef union {
    struct {
        unsigned int arr7_tb1_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr7_tb1_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr7_tb1_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB290;

typedef union {
    struct {
        unsigned int arr7_tb1_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr7_tb1_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr7_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB291;

typedef union {
    struct {
        unsigned int arr7_tb2_layer                                   :   8               ;    /* 7:0 */
        unsigned int arr7_tb2_qm                                      :   8               ;    /* 15:8 */
        unsigned int arr7_tb2_rmcs                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB293;

typedef union {
    struct {
        unsigned int arr7_tb2_new_trans_flag                          :   8               ;    /* 7:0 */
        unsigned int arr7_tb2_crc_ok_retrans_flag                     :   8               ;    /* 15:8 */
        unsigned int arr7_reserved_0                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB294;

typedef union {
    struct {
        unsigned int arr7_pds_scs                                     :   8               ;    /* 7:0 */
        unsigned int arr7_pds_schedu_slot_num                         :   8               ;    /* 15:8 */
        unsigned int arr7_pds_schedu_sfm_num                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB297;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB0                            om_data0;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB1                            om_data1;
    unsigned int                                                      arr0_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB3                            om_data3;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB4                            om_data4;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB5                            om_data5;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB6                            om_data6;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB7                            om_data7;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB8                            om_data8;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB9                            om_data9;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB10                           om_data10;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB11                           om_data11;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB12                           om_data12;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB13                           om_data13;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB14                           om_data14;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB15                           om_data15;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB16                           om_data16;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB17                           om_data17;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB18                           om_data18;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB19                           om_data19;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB20                           om_data20;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB21                           om_data21;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB22                           om_data22;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB23                           om_data23;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB24                           om_data24;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB25                           om_data25;
    unsigned int                                                      arr0_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB27                           om_data27;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB28                           om_data28;
    unsigned int                                                      arr0_tb2_size;
    unsigned int                                                      arr0_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB31                           om_data31;
    unsigned int                                                      arr0_array_para0;
    unsigned int                                                      arr0_array_para1;
    unsigned int                                                      arr0_array_para2;
    unsigned int                                                      arr0_array_para3;
    unsigned int                                                      arr0_array_para4;
    unsigned int                                                      arr0_reserved_0;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB38                           om_data38;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB39                           om_data39;
    unsigned int                                                      arr1_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB41                           om_data41;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB42                           om_data42;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB43                           om_data43;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB44                           om_data44;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB45                           om_data45;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB46                           om_data46;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB47                           om_data47;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB48                           om_data48;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB49                           om_data49;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB50                           om_data50;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB51                           om_data51;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB52                           om_data52;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB53                           om_data53;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB54                           om_data54;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB55                           om_data55;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB56                           om_data56;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB57                           om_data57;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB58                           om_data58;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB59                           om_data59;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB60                           om_data60;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB61                           om_data61;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB62                           om_data62;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB63                           om_data63;
    unsigned int                                                      arr1_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB65                           om_data65;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB66                           om_data66;
    unsigned int                                                      arr1_tb2_size;
    unsigned int                                                      arr1_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB69                           om_data69;
    unsigned int                                                      arr1_array_para0;
    unsigned int                                                      arr1_array_para1;
    unsigned int                                                      arr1_array_para2;
    unsigned int                                                      arr1_array_para3;
    unsigned int                                                      arr1_array_para4;
    unsigned int                                                      arr1_reserved_1;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB76                           om_data76;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB77                           om_data77;
    unsigned int                                                      arr2_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB79                           om_data79;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB80                           om_data80;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB81                           om_data81;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB82                           om_data82;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB83                           om_data83;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB84                           om_data84;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB85                           om_data85;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB86                           om_data86;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB87                           om_data87;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB88                           om_data88;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB89                           om_data89;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB90                           om_data90;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB91                           om_data91;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB92                           om_data92;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB93                           om_data93;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB94                           om_data94;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB95                           om_data95;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB96                           om_data96;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB97                           om_data97;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB98                           om_data98;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB99                           om_data99;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB100                          om_data100;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB101                          om_data101;
    unsigned int                                                      arr2_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB103                          om_data103;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB104                          om_data104;
    unsigned int                                                      arr2_tb2_size;
    unsigned int                                                      arr2_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB107                          om_data107;
    unsigned int                                                      arr2_array_para0;
    unsigned int                                                      arr2_array_para1;
    unsigned int                                                      arr2_array_para2;
    unsigned int                                                      arr2_array_para3;
    unsigned int                                                      arr2_array_para4;
    unsigned int                                                      arr2_reserved_2;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB114                          om_data114;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB115                          om_data115;
    unsigned int                                                      arr3_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB117                          om_data117;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB118                          om_data118;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB119                          om_data119;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB120                          om_data120;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB121                          om_data121;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB122                          om_data122;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB123                          om_data123;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB124                          om_data124;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB125                          om_data125;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB126                          om_data126;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB127                          om_data127;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB128                          om_data128;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB129                          om_data129;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB130                          om_data130;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB131                          om_data131;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB132                          om_data132;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB133                          om_data133;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB134                          om_data134;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB135                          om_data135;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB136                          om_data136;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB137                          om_data137;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB138                          om_data138;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB139                          om_data139;
    unsigned int                                                      arr3_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB141                          om_data141;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB142                          om_data142;
    unsigned int                                                      arr3_tb2_size;
    unsigned int                                                      arr3_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB145                          om_data145;
    unsigned int                                                      arr3_array_para0;
    unsigned int                                                      arr3_array_para1;
    unsigned int                                                      arr3_array_para2;
    unsigned int                                                      arr3_array_para3;
    unsigned int                                                      arr3_array_para4;
    unsigned int                                                      arr3_reserved_3;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB152                          om_data152;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB153                          om_data153;
    unsigned int                                                      arr4_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB155                          om_data155;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB156                          om_data156;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB157                          om_data157;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB158                          om_data158;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB159                          om_data159;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB160                          om_data160;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB161                          om_data161;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB162                          om_data162;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB163                          om_data163;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB164                          om_data164;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB165                          om_data165;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB166                          om_data166;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB167                          om_data167;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB168                          om_data168;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB169                          om_data169;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB170                          om_data170;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB171                          om_data171;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB172                          om_data172;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB173                          om_data173;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB174                          om_data174;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB175                          om_data175;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB176                          om_data176;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB177                          om_data177;
    unsigned int                                                      arr4_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB179                          om_data179;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB180                          om_data180;
    unsigned int                                                      arr4_tb2_size;
    unsigned int                                                      arr4_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB183                          om_data183;
    unsigned int                                                      arr4_array_para0;
    unsigned int                                                      arr4_array_para1;
    unsigned int                                                      arr4_array_para2;
    unsigned int                                                      arr4_array_para3;
    unsigned int                                                      arr4_array_para4;
    unsigned int                                                      arr4_reserved_4;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB190                          om_data190;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB191                          om_data191;
    unsigned int                                                      arr5_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB193                          om_data193;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB194                          om_data194;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB195                          om_data195;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB196                          om_data196;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB197                          om_data197;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB198                          om_data198;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB199                          om_data199;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB200                          om_data200;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB201                          om_data201;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB202                          om_data202;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB203                          om_data203;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB204                          om_data204;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB205                          om_data205;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB206                          om_data206;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB207                          om_data207;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB208                          om_data208;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB209                          om_data209;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB210                          om_data210;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB211                          om_data211;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB212                          om_data212;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB213                          om_data213;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB214                          om_data214;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB215                          om_data215;
    unsigned int                                                      arr5_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB217                          om_data217;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB218                          om_data218;
    unsigned int                                                      arr5_tb2_size;
    unsigned int                                                      arr5_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB221                          om_data221;
    unsigned int                                                      arr5_array_para0;
    unsigned int                                                      arr5_array_para1;
    unsigned int                                                      arr5_array_para2;
    unsigned int                                                      arr5_array_para3;
    unsigned int                                                      arr5_array_para4;
    unsigned int                                                      arr5_reserved_5;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB228                          om_data228;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB229                          om_data229;
    unsigned int                                                      arr6_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB231                          om_data231;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB232                          om_data232;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB233                          om_data233;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB234                          om_data234;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB235                          om_data235;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB236                          om_data236;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB237                          om_data237;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB238                          om_data238;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB239                          om_data239;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB240                          om_data240;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB241                          om_data241;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB242                          om_data242;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB243                          om_data243;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB244                          om_data244;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB245                          om_data245;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB246                          om_data246;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB247                          om_data247;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB248                          om_data248;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB249                          om_data249;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB250                          om_data250;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB251                          om_data251;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB252                          om_data252;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB253                          om_data253;
    unsigned int                                                      arr6_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB255                          om_data255;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB256                          om_data256;
    unsigned int                                                      arr6_tb2_size;
    unsigned int                                                      arr6_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB259                          om_data259;
    unsigned int                                                      arr6_array_para0;
    unsigned int                                                      arr6_array_para1;
    unsigned int                                                      arr6_array_para2;
    unsigned int                                                      arr6_array_para3;
    unsigned int                                                      arr6_array_para4;
    unsigned int                                                      arr6_reserved_6;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB266                          om_data266;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB267                          om_data267;
    unsigned int                                                      arr7_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB269                          om_data269;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB270                          om_data270;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB271                          om_data271;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB272                          om_data272;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB273                          om_data273;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB274                          om_data274;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB275                          om_data275;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB276                          om_data276;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB277                          om_data277;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB278                          om_data278;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB279                          om_data279;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB280                          om_data280;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB281                          om_data281;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB282                          om_data282;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB283                          om_data283;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB284                          om_data284;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB285                          om_data285;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB286                          om_data286;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB287                          om_data287;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB288                          om_data288;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB289                          om_data289;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB290                          om_data290;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB291                          om_data291;
    unsigned int                                                      arr7_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB293                          om_data293;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB294                          om_data294;
    unsigned int                                                      arr7_tb2_size;
    unsigned int                                                      arr7_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB297                          om_data297;
    unsigned int                                                      arr7_array_para0;
    unsigned int                                                      arr7_array_para1;
    unsigned int                                                      arr7_array_para2;
    unsigned int                                                      arr7_array_para3;
    unsigned int                                                      arr7_array_para4;
    unsigned int                                                      arr7_reserved_7;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB0                            om_data0;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB1                            om_data1;
    unsigned int                                                      arr0_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB3                            om_data3;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB4                            om_data4;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB5                            om_data5;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB6                            om_data6;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB7                            om_data7;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB8                            om_data8;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB9                            om_data9;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB10                           om_data10;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB11                           om_data11;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB12                           om_data12;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB13                           om_data13;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB14                           om_data14;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB15                           om_data15;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB16                           om_data16;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB17                           om_data17;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB18                           om_data18;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB19                           om_data19;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB20                           om_data20;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB21                           om_data21;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB22                           om_data22;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB23                           om_data23;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB24                           om_data24;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB25                           om_data25;
    unsigned int                                                      arr0_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB27                           om_data27;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB28                           om_data28;
    unsigned int                                                      arr0_tb2_size;
    unsigned int                                                      arr0_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB31                           om_data31;
    unsigned int                                                      arr0_array_para0;
    unsigned int                                                      arr0_array_para1;
    unsigned int                                                      arr0_array_para2;
    unsigned int                                                      arr0_array_para3;
    unsigned int                                                      arr0_array_para4;
    unsigned int                                                      arr0_reserved_0;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB38                           om_data38;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB39                           om_data39;
    unsigned int                                                      arr1_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB41                           om_data41;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB42                           om_data42;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB43                           om_data43;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB44                           om_data44;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB45                           om_data45;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB46                           om_data46;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB47                           om_data47;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB48                           om_data48;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB49                           om_data49;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB50                           om_data50;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB51                           om_data51;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB52                           om_data52;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB53                           om_data53;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB54                           om_data54;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB55                           om_data55;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB56                           om_data56;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB57                           om_data57;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB58                           om_data58;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB59                           om_data59;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB60                           om_data60;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB61                           om_data61;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB62                           om_data62;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB63                           om_data63;
    unsigned int                                                      arr1_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB65                           om_data65;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB66                           om_data66;
    unsigned int                                                      arr1_tb2_size;
    unsigned int                                                      arr1_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB69                           om_data69;
    unsigned int                                                      arr1_array_para0;
    unsigned int                                                      arr1_array_para1;
    unsigned int                                                      arr1_array_para2;
    unsigned int                                                      arr1_array_para3;
    unsigned int                                                      arr1_array_para4;
    unsigned int                                                      arr1_reserved_1;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB76                           om_data76;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB77                           om_data77;
    unsigned int                                                      arr2_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB79                           om_data79;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB80                           om_data80;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB81                           om_data81;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB82                           om_data82;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB83                           om_data83;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB84                           om_data84;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB85                           om_data85;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB86                           om_data86;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB87                           om_data87;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB88                           om_data88;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB89                           om_data89;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB90                           om_data90;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB91                           om_data91;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB92                           om_data92;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB93                           om_data93;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB94                           om_data94;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB95                           om_data95;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB96                           om_data96;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB97                           om_data97;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB98                           om_data98;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB99                           om_data99;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB100                          om_data100;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB101                          om_data101;
    unsigned int                                                      arr2_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB103                          om_data103;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB104                          om_data104;
    unsigned int                                                      arr2_tb2_size;
    unsigned int                                                      arr2_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB107                          om_data107;
    unsigned int                                                      arr2_array_para0;
    unsigned int                                                      arr2_array_para1;
    unsigned int                                                      arr2_array_para2;
    unsigned int                                                      arr2_array_para3;
    unsigned int                                                      arr2_array_para4;
    unsigned int                                                      arr2_reserved_2;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB114                          om_data114;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB115                          om_data115;
    unsigned int                                                      arr3_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB117                          om_data117;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB118                          om_data118;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB119                          om_data119;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB120                          om_data120;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB121                          om_data121;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB122                          om_data122;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB123                          om_data123;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB124                          om_data124;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB125                          om_data125;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB126                          om_data126;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB127                          om_data127;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB128                          om_data128;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB129                          om_data129;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB130                          om_data130;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB131                          om_data131;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB132                          om_data132;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB133                          om_data133;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB134                          om_data134;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB135                          om_data135;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB136                          om_data136;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB137                          om_data137;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB138                          om_data138;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB139                          om_data139;
    unsigned int                                                      arr3_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB141                          om_data141;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB142                          om_data142;
    unsigned int                                                      arr3_tb2_size;
    unsigned int                                                      arr3_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB145                          om_data145;
    unsigned int                                                      arr3_array_para0;
    unsigned int                                                      arr3_array_para1;
    unsigned int                                                      arr3_array_para2;
    unsigned int                                                      arr3_array_para3;
    unsigned int                                                      arr3_array_para4;
    unsigned int                                                      arr3_reserved_3;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB152                          om_data152;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB153                          om_data153;
    unsigned int                                                      arr4_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB155                          om_data155;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB156                          om_data156;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB157                          om_data157;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB158                          om_data158;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB159                          om_data159;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB160                          om_data160;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB161                          om_data161;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB162                          om_data162;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB163                          om_data163;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB164                          om_data164;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB165                          om_data165;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB166                          om_data166;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB167                          om_data167;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB168                          om_data168;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB169                          om_data169;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB170                          om_data170;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB171                          om_data171;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB172                          om_data172;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB173                          om_data173;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB174                          om_data174;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB175                          om_data175;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB176                          om_data176;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB177                          om_data177;
    unsigned int                                                      arr4_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB179                          om_data179;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB180                          om_data180;
    unsigned int                                                      arr4_tb2_size;
    unsigned int                                                      arr4_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB183                          om_data183;
    unsigned int                                                      arr4_array_para0;
    unsigned int                                                      arr4_array_para1;
    unsigned int                                                      arr4_array_para2;
    unsigned int                                                      arr4_array_para3;
    unsigned int                                                      arr4_array_para4;
    unsigned int                                                      arr4_reserved_4;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB190                          om_data190;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB191                          om_data191;
    unsigned int                                                      arr5_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB193                          om_data193;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB194                          om_data194;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB195                          om_data195;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB196                          om_data196;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB197                          om_data197;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB198                          om_data198;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB199                          om_data199;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB200                          om_data200;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB201                          om_data201;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB202                          om_data202;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB203                          om_data203;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB204                          om_data204;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB205                          om_data205;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB206                          om_data206;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB207                          om_data207;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB208                          om_data208;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB209                          om_data209;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB210                          om_data210;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB211                          om_data211;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB212                          om_data212;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB213                          om_data213;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB214                          om_data214;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB215                          om_data215;
    unsigned int                                                      arr5_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB217                          om_data217;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB218                          om_data218;
    unsigned int                                                      arr5_tb2_size;
    unsigned int                                                      arr5_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB221                          om_data221;
    unsigned int                                                      arr5_array_para0;
    unsigned int                                                      arr5_array_para1;
    unsigned int                                                      arr5_array_para2;
    unsigned int                                                      arr5_array_para3;
    unsigned int                                                      arr5_array_para4;
    unsigned int                                                      arr5_reserved_5;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB228                          om_data228;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB229                          om_data229;
    unsigned int                                                      arr6_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB231                          om_data231;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB232                          om_data232;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB233                          om_data233;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB234                          om_data234;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB235                          om_data235;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB236                          om_data236;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB237                          om_data237;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB238                          om_data238;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB239                          om_data239;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB240                          om_data240;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB241                          om_data241;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB242                          om_data242;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB243                          om_data243;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB244                          om_data244;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB245                          om_data245;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB246                          om_data246;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB247                          om_data247;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB248                          om_data248;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB249                          om_data249;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB250                          om_data250;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB251                          om_data251;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB252                          om_data252;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB253                          om_data253;
    unsigned int                                                      arr6_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB255                          om_data255;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB256                          om_data256;
    unsigned int                                                      arr6_tb2_size;
    unsigned int                                                      arr6_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB259                          om_data259;
    unsigned int                                                      arr6_array_para0;
    unsigned int                                                      arr6_array_para1;
    unsigned int                                                      arr6_array_para2;
    unsigned int                                                      arr6_array_para3;
    unsigned int                                                      arr6_array_para4;
    unsigned int                                                      arr6_reserved_6;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB266                          om_data266;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB267                          om_data267;
    unsigned int                                                      arr7_freq_res_assign;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB269                          om_data269;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB270                          om_data270;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB271                          om_data271;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB272                          om_data272;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB273                          om_data273;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB274                          om_data274;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB275                          om_data275;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB276                          om_data276;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB277                          om_data277;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB278                          om_data278;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB279                          om_data279;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB280                          om_data280;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB281                          om_data281;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB282                          om_data282;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB283                          om_data283;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB284                          om_data284;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB285                          om_data285;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB286                          om_data286;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB287                          om_data287;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB288                          om_data288;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB289                          om_data289;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB290                          om_data290;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB291                          om_data291;
    unsigned int                                                      arr7_tb1_size;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB293                          om_data293;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB294                          om_data294;
    unsigned int                                                      arr7_tb2_size;
    unsigned int                                                      arr7_single_dci_para;
    DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_SUB297                          om_data297;
    unsigned int                                                      arr7_array_para0;
    unsigned int                                                      arr7_array_para1;
    unsigned int                                                      arr7_array_para2;
    unsigned int                                                      arr7_array_para3;
    unsigned int                                                      arr7_array_para4;
    unsigned int                                                      arr7_reserved_7;
} DCICP_SID_DCICP_OM_INFO_NR_ARRAY1_BBP_MC;

typedef union {
    struct {
        unsigned int dci_num                                          :   5               ;    /* 4:0 */
        unsigned int coreset_bitmap                                   :   3               ;    /* 7:5 */
        unsigned int dec_rpt_cst_poolidx                              :   1               ;    /* 8 */
        unsigned int cfg_idx                                          :   4               ;    /* 12:9 */
        unsigned int overlap_flag                                     :   3               ;    /* 15:13 */
        unsigned int ssset_rbconf_flag                                :   1               ;    /* 16 */
        unsigned int coreset0_start_symbol                            :   4               ;    /* 20:17 */
        unsigned int coreset1_start_symbol                            :   4               ;    /* 24:21 */
        unsigned int coreset2_start_symbol                            :   4               ;    /* 28:25 */
        unsigned int coreset_vld_bitmap                               :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB6;

typedef union {
    struct {
        unsigned int dec_rpt_dci_idx0                                 :   3               ;    /* 2:0 */
        unsigned int dec_rpt_r_idx0                                   :   5               ;    /* 7:3 */
        unsigned int dec_rpt_dci_idx1                                 :   3               ;    /* 10:8 */
        unsigned int dec_rpt_r_idx1                                   :   5               ;    /* 15:11 */
        unsigned int dec_rpt_dci_idx2                                 :   3               ;    /* 18:16 */
        unsigned int dec_rpt_r_idx2                                   :   5               ;    /* 23:19 */
        unsigned int dec_rpt_dci_idx3                                 :   3               ;    /* 26:24 */
        unsigned int dec_rpt_r_idx3                                   :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB7;

typedef union {
    struct {
        unsigned int dec_rpt_dci_idx4                                 :   3               ;    /* 2:0 */
        unsigned int dec_rpt_r_idx4                                   :   5               ;    /* 7:3 */
        unsigned int dec_rpt_dci_idx5                                 :   3               ;    /* 10:8 */
        unsigned int dec_rpt_r_idx5                                   :   5               ;    /* 15:11 */
        unsigned int dec_rpt_dci_idx6                                 :   3               ;    /* 18:16 */
        unsigned int dec_rpt_r_idx6                                   :   5               ;    /* 23:19 */
        unsigned int dec_rpt_dci_idx7                                 :   3               ;    /* 26:24 */
        unsigned int dec_rpt_r_idx7                                   :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB8;

typedef union {
    struct {
        unsigned int dec_rpt_dci_idx8                                 :   3               ;    /* 2:0 */
        unsigned int dec_rpt_r_idx8                                   :   5               ;    /* 7:3 */
        unsigned int dec_rpt_dci_idx9                                 :   3               ;    /* 10:8 */
        unsigned int dec_rpt_r_idx9                                   :   5               ;    /* 15:11 */
        unsigned int dec_rpt_dci_idx10                                :   3               ;    /* 18:16 */
        unsigned int dec_rpt_r_idx10                                  :   5               ;    /* 23:19 */
        unsigned int dec_rpt_dci_idx11                                :   3               ;    /* 26:24 */
        unsigned int dec_rpt_r_idx11                                  :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB9;

typedef union {
    struct {
        unsigned int dec_rpt_dci_idx12                                :   3               ;    /* 2:0 */
        unsigned int dec_rpt_r_idx12                                  :   5               ;    /* 7:3 */
        unsigned int dec_rpt_dci_idx13                                :   3               ;    /* 10:8 */
        unsigned int dec_rpt_r_idx13                                  :   5               ;    /* 15:11 */
        unsigned int dec_rpt_dci_idx14                                :   3               ;    /* 18:16 */
        unsigned int dec_rpt_r_idx14                                  :   5               ;    /* 23:19 */
        unsigned int dec_rpt_dci_idx15                                :   3               ;    /* 26:24 */
        unsigned int dec_rpt_r_idx15                                  :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB10;

typedef union {
    struct {
        unsigned int dec_rpt_dci_idx16                                :   3               ;    /* 2:0 */
        unsigned int dec_rpt_r_idx16                                  :   5               ;    /* 7:3 */
        unsigned int dec_rpt_dci_idx17                                :   3               ;    /* 10:8 */
        unsigned int dec_rpt_r_idx17                                  :   5               ;    /* 15:11 */
        unsigned int dec_rpt_dci_idx18                                :   3               ;    /* 18:16 */
        unsigned int dec_rpt_r_idx18                                  :   5               ;    /* 23:19 */
        unsigned int dec_rpt_dci_idx19                                :   3               ;    /* 26:24 */
        unsigned int dec_rpt_r_idx19                                  :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB11;

typedef union {
    struct {
        unsigned int dec_rpt_dci_idx20                                :   3               ;    /* 2:0 */
        unsigned int dec_rpt_r_idx20                                  :   5               ;    /* 7:3 */
        unsigned int dec_rpt_dci_idx21                                :   3               ;    /* 10:8 */
        unsigned int dec_rpt_r_idx21                                  :   5               ;    /* 15:11 */
        unsigned int dec_rpt_dci_idx22                                :   3               ;    /* 18:16 */
        unsigned int dec_rpt_r_idx22                                  :   5               ;    /* 23:19 */
        unsigned int dec_rpt_dci_idx23                                :   3               ;    /* 26:24 */
        unsigned int dec_rpt_r_idx23                                  :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB12;

typedef union {
    struct {
        unsigned int coreset0_ls_shift_rx0                            :   4               ;    /* 3:0 */
        unsigned int coreset0_ls_shift_rx1                            :   4               ;    /* 7:4 */
        unsigned int coreset0_ls_shift_rx2                            :   4               ;    /* 11:8 */
        unsigned int coreset0_ls_shift_rx3                            :   4               ;    /* 15:12 */
        unsigned int coreset0_cce_idx_map                             :   8               ;    /* 23:16 */
        unsigned int coreset0_cst_antpreempt_ind                      :   4               ;    /* 27:24 */
        unsigned int coreset0_reserved_0                              :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB13;

typedef union {
    struct {
        unsigned int coreset0_ls_power_sum_rx0                        :   16              ;    /* 15:0 */
        unsigned int coreset0_ls_power_sum_rx1                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB14;

typedef union {
    struct {
        unsigned int coreset0_ls_power_sum_rx2                        :   16              ;    /* 15:0 */
        unsigned int coreset0_ls_power_sum_rx3                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB15;

typedef union {
    struct {
        unsigned int coreset0_noise_sum_rx0                           :   16              ;    /* 15:0 */
        unsigned int coreset0_noise_sum_rx1                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB16;

typedef union {
    struct {
        unsigned int coreset0_noise_sum_rx2                           :   16              ;    /* 15:0 */
        unsigned int coreset0_noise_sum_rx3                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB17;

typedef union {
    struct {
        unsigned int coreset1_ls_shift_rx0                            :   4               ;    /* 3:0 */
        unsigned int coreset1_ls_shift_rx1                            :   4               ;    /* 7:4 */
        unsigned int coreset1_ls_shift_rx2                            :   4               ;    /* 11:8 */
        unsigned int coreset1_ls_shift_rx3                            :   4               ;    /* 15:12 */
        unsigned int coreset1_cce_idx_map                             :   8               ;    /* 23:16 */
        unsigned int coreset1_cst_antpreempt_ind                      :   4               ;    /* 27:24 */
        unsigned int coreset1_reserved_0                              :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB18;

typedef union {
    struct {
        unsigned int coreset1_ls_power_sum_rx0                        :   16              ;    /* 15:0 */
        unsigned int coreset1_ls_power_sum_rx1                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB19;

typedef union {
    struct {
        unsigned int coreset1_ls_power_sum_rx2                        :   16              ;    /* 15:0 */
        unsigned int coreset1_ls_power_sum_rx3                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB20;

typedef union {
    struct {
        unsigned int coreset1_noise_sum_rx0                           :   16              ;    /* 15:0 */
        unsigned int coreset1_noise_sum_rx1                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB21;

typedef union {
    struct {
        unsigned int coreset1_noise_sum_rx2                           :   16              ;    /* 15:0 */
        unsigned int coreset1_noise_sum_rx3                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB22;

typedef union {
    struct {
        unsigned int coreset2_ls_shift_rx0                            :   4               ;    /* 3:0 */
        unsigned int coreset2_ls_shift_rx1                            :   4               ;    /* 7:4 */
        unsigned int coreset2_ls_shift_rx2                            :   4               ;    /* 11:8 */
        unsigned int coreset2_ls_shift_rx3                            :   4               ;    /* 15:12 */
        unsigned int coreset2_cce_idx_map                             :   8               ;    /* 23:16 */
        unsigned int coreset2_cst_antpreempt_ind                      :   4               ;    /* 27:24 */
        unsigned int coreset2_reserved_0                              :   4               ;    /* 31:28 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB23;

typedef union {
    struct {
        unsigned int coreset2_ls_power_sum_rx0                        :   16              ;    /* 15:0 */
        unsigned int coreset2_ls_power_sum_rx1                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB24;

typedef union {
    struct {
        unsigned int coreset2_ls_power_sum_rx2                        :   16              ;    /* 15:0 */
        unsigned int coreset2_ls_power_sum_rx3                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB25;

typedef union {
    struct {
        unsigned int coreset2_noise_sum_rx0                           :   16              ;    /* 15:0 */
        unsigned int coreset2_noise_sum_rx1                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB26;

typedef union {
    struct {
        unsigned int coreset2_noise_sum_rx2                           :   16              ;    /* 15:0 */
        unsigned int coreset2_noise_sum_rx3                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB27;

typedef union {
    struct {
        unsigned int coreset0_al1_et_rpt                              :   3               ;    /* 2:0 */
        unsigned int coreset0_al2_et_rpt                              :   3               ;    /* 5:3 */
        unsigned int coreset0_al4_et_rpt                              :   3               ;    /* 8:6 */
        unsigned int coreset0_al8_et_rpt                              :   3               ;    /* 11:9 */
        unsigned int coreset0_al16_et_rpt                             :   3               ;    /* 14:12 */
        unsigned int coreset0_cce_polar_etflag_rpt                    :   2               ;    /* 16:15 */
        unsigned int coreset0_llr_candi_max                           :   12              ;    /* 28:17 */
        unsigned int coreset0_reserved_0                              :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB29;

typedef union {
    struct {
        unsigned int coreset1_al1_et_rpt                              :   3               ;    /* 2:0 */
        unsigned int coreset1_al2_et_rpt                              :   3               ;    /* 5:3 */
        unsigned int coreset1_al4_et_rpt                              :   3               ;    /* 8:6 */
        unsigned int coreset1_al8_et_rpt                              :   3               ;    /* 11:9 */
        unsigned int coreset1_al16_et_rpt                             :   3               ;    /* 14:12 */
        unsigned int coreset1_cce_polar_etflag_rpt                    :   2               ;    /* 16:15 */
        unsigned int coreset1_llr_candi_max                           :   12              ;    /* 28:17 */
        unsigned int coreset1_reserved_0                              :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB30;

typedef union {
    struct {
        unsigned int coreset2_al1_et_rpt                              :   3               ;    /* 2:0 */
        unsigned int coreset2_al2_et_rpt                              :   3               ;    /* 5:3 */
        unsigned int coreset2_al4_et_rpt                              :   3               ;    /* 8:6 */
        unsigned int coreset2_al8_et_rpt                              :   3               ;    /* 11:9 */
        unsigned int coreset2_al16_et_rpt                             :   3               ;    /* 14:12 */
        unsigned int coreset2_cce_polar_etflag_rpt                    :   2               ;    /* 16:15 */
        unsigned int coreset2_llr_candi_max                           :   12              ;    /* 28:17 */
        unsigned int coreset2_reserved_0                              :   3               ;    /* 31:29 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB31;

typedef union {
    struct {
        unsigned int fake29_match_v                                   :   22              ;    /* 21:0 */
        unsigned int reserved_0                                       :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB32;

typedef union {
    struct {
        unsigned int dec_rpt_pwrfake                                  :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB33;

typedef union {
    struct {
        unsigned int dec_rpt_r2_alarm                                 :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB34;

typedef union {
    struct {
        unsigned int dec_rpt_r1_alarm                                 :   24              ;    /* 23:0 */
        unsigned int reserved_0                                       :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB35;

typedef union {
    struct {
        unsigned int ovb_bypass0                                      :   16              ;    /* 15:0 */
        unsigned int ovb_bypass1                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB36;

typedef union {
    struct {
        unsigned int ovb_bypass2                                      :   16              ;    /* 15:0 */
        unsigned int ovb_bypass3                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB37;

typedef union {
    struct {
        unsigned int ovb_bypass4                                      :   16              ;    /* 15:0 */
        unsigned int ovb_bypass5                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB38;

typedef union {
    struct {
        unsigned int ovb_bypass6                                      :   16              ;    /* 15:0 */
        unsigned int ovb_bypass7                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB39;

typedef union {
    struct {
        unsigned int ovb_bypass8                                      :   16              ;    /* 15:0 */
        unsigned int ovb_bypass9                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB40;

typedef union {
    struct {
        unsigned int ovb_bypass10                                     :   16              ;    /* 15:0 */
        unsigned int ovb_bypass11                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB41;

typedef union {
    struct {
        unsigned int ovb_bypass12                                     :   16              ;    /* 15:0 */
        unsigned int ovb_bypass13                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB42;

typedef union {
    struct {
        unsigned int ovb_bypass14                                     :   16              ;    /* 15:0 */
        unsigned int ovb_bypass15                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB43;

typedef union {
    struct {
        unsigned int ovb_bypass16                                     :   16              ;    /* 15:0 */
        unsigned int ovb_bypass17                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB44;

typedef union {
    struct {
        unsigned int ovb_bypass18                                     :   16              ;    /* 15:0 */
        unsigned int ovb_bypass19                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB45;

typedef union {
    struct {
        unsigned int ovb_bypass20                                     :   16              ;    /* 15:0 */
        unsigned int ovb_bypass21                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB46;

typedef union {
    struct {
        unsigned int ovb_bypass22                                     :   16              ;    /* 15:0 */
        unsigned int ovb_bypass23                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB47;

typedef union {
    struct {
        unsigned int dec_rpt_hedsum0                                  :   9               ;    /* 8:0 */
        unsigned int dec_rpt_hedsum1                                  :   9               ;    /* 17:9 */
        unsigned int dec_rpt_hedsum2                                  :   9               ;    /* 26:18 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB48;

typedef union {
    struct {
        unsigned int dec_rpt_hedsum3                                  :   9               ;    /* 8:0 */
        unsigned int dec_rpt_hedsum4                                  :   9               ;    /* 17:9 */
        unsigned int dec_rpt_hedsum5                                  :   9               ;    /* 26:18 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB49;

typedef union {
    struct {
        unsigned int dec_rpt_hedsum6                                  :   9               ;    /* 8:0 */
        unsigned int dec_rpt_hedsum7                                  :   9               ;    /* 17:9 */
        unsigned int dec_rpt_hedsum8                                  :   9               ;    /* 26:18 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB50;

typedef union {
    struct {
        unsigned int dec_rpt_hedsum9                                  :   9               ;    /* 8:0 */
        unsigned int dec_rpt_hedsum10                                 :   9               ;    /* 17:9 */
        unsigned int dec_rpt_hedsum11                                 :   9               ;    /* 26:18 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB51;

typedef union {
    struct {
        unsigned int dec_rpt_hedsum12                                 :   9               ;    /* 8:0 */
        unsigned int dec_rpt_hedsum13                                 :   9               ;    /* 17:9 */
        unsigned int dec_rpt_hedsum14                                 :   9               ;    /* 26:18 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB52;

typedef union {
    struct {
        unsigned int dec_rpt_hedsum15                                 :   9               ;    /* 8:0 */
        unsigned int dec_rpt_hedsum16                                 :   9               ;    /* 17:9 */
        unsigned int dec_rpt_hedsum17                                 :   9               ;    /* 26:18 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB53;

typedef union {
    struct {
        unsigned int dec_rpt_hedsum18                                 :   9               ;    /* 8:0 */
        unsigned int dec_rpt_hedsum19                                 :   9               ;    /* 17:9 */
        unsigned int dec_rpt_hedsum20                                 :   9               ;    /* 26:18 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB54;

typedef union {
    struct {
        unsigned int dec_rpt_hedsum21                                 :   9               ;    /* 8:0 */
        unsigned int dec_rpt_hedsum22                                 :   9               ;    /* 17:9 */
        unsigned int dec_rpt_hedsum23                                 :   9               ;    /* 26:18 */
        unsigned int reserved_0                                       :   5               ;    /* 31:27 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB55;

typedef union {
    struct {
        unsigned int dec_rpt_pm0                                      :   8               ;    /* 7:0 */
        unsigned int dec_rpt_pm1                                      :   8               ;    /* 15:8 */
        unsigned int dec_rpt_pm2                                      :   8               ;    /* 23:16 */
        unsigned int dec_rpt_pm3                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB56;

typedef union {
    struct {
        unsigned int dec_rpt_pm4                                      :   8               ;    /* 7:0 */
        unsigned int dec_rpt_pm5                                      :   8               ;    /* 15:8 */
        unsigned int dec_rpt_pm6                                      :   8               ;    /* 23:16 */
        unsigned int dec_rpt_pm7                                      :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB57;

typedef union {
    struct {
        unsigned int dec_rpt_pm8                                      :   8               ;    /* 7:0 */
        unsigned int dec_rpt_pm9                                      :   8               ;    /* 15:8 */
        unsigned int dec_rpt_pm10                                     :   8               ;    /* 23:16 */
        unsigned int dec_rpt_pm11                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB58;

typedef union {
    struct {
        unsigned int dec_rpt_pm12                                     :   8               ;    /* 7:0 */
        unsigned int dec_rpt_pm13                                     :   8               ;    /* 15:8 */
        unsigned int dec_rpt_pm14                                     :   8               ;    /* 23:16 */
        unsigned int dec_rpt_pm15                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB59;

typedef union {
    struct {
        unsigned int dec_rpt_pm16                                     :   8               ;    /* 7:0 */
        unsigned int dec_rpt_pm17                                     :   8               ;    /* 15:8 */
        unsigned int dec_rpt_pm18                                     :   8               ;    /* 23:16 */
        unsigned int dec_rpt_pm19                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB60;

typedef union {
    struct {
        unsigned int dec_rpt_pm20                                     :   8               ;    /* 7:0 */
        unsigned int dec_rpt_pm21                                     :   8               ;    /* 15:8 */
        unsigned int dec_rpt_pm22                                     :   8               ;    /* 23:16 */
        unsigned int dec_rpt_pm23                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB61;

typedef union {
    struct {
        unsigned int dci0_dec_rpt_sss_coreset_id                      :   3               ;    /* 2:0 */
        unsigned int dci0_dec_rpt_start_symb                          :   4               ;    /* 6:3 */
        unsigned int dci0_dec_rpt_start_cce                           :   8               ;    /* 14:7 */
        unsigned int dci0_dec_rpt_al                                  :   3               ;    /* 17:15 */
        unsigned int dci0_dec_rpt_llr                                 :   12              ;    /* 29:18 */
        unsigned int dci0_dec_al16_flag                               :   1               ;    /* 30 */
        unsigned int dci0_dec_rpt_comm_flag                           :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB64;

typedef union {
    struct {
        unsigned int dci0_dec_rpt_data4                               :   12              ;    /* 11:0 */
        unsigned int dci0_dec_rb_conflict0                            :   1               ;    /* 12 */
        unsigned int dci0_reserved_0                                  :   1               ;    /* 13 */
        unsigned int dci0_reserved_1                                  :   1               ;    /* 14 */
        unsigned int dci0_fake29_al8_al16_idx                         :   5               ;    /* 19:15 */
        unsigned int dci0_dec_rpt_power                               :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB69;

typedef union {
    struct {
        unsigned int dci1_dec_rpt_sss_coreset_id                      :   3               ;    /* 2:0 */
        unsigned int dci1_dec_rpt_start_symb                          :   4               ;    /* 6:3 */
        unsigned int dci1_dec_rpt_start_cce                           :   8               ;    /* 14:7 */
        unsigned int dci1_dec_rpt_al                                  :   3               ;    /* 17:15 */
        unsigned int dci1_dec_rpt_llr                                 :   12              ;    /* 29:18 */
        unsigned int dci1_dec_al16_flag                               :   1               ;    /* 30 */
        unsigned int dci1_dec_rpt_comm_flag                           :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB70;

typedef union {
    struct {
        unsigned int dci1_dec_rpt_data4                               :   12              ;    /* 11:0 */
        unsigned int dci1_dec_rb_conflict0                            :   1               ;    /* 12 */
        unsigned int dci1_reserved_0                                  :   1               ;    /* 13 */
        unsigned int dci1_reserved_1                                  :   1               ;    /* 14 */
        unsigned int dci1_fake29_al8_al16_idx                         :   5               ;    /* 19:15 */
        unsigned int dci1_dec_rpt_power                               :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB75;

typedef union {
    struct {
        unsigned int dci2_dec_rpt_sss_coreset_id                      :   3               ;    /* 2:0 */
        unsigned int dci2_dec_rpt_start_symb                          :   4               ;    /* 6:3 */
        unsigned int dci2_dec_rpt_start_cce                           :   8               ;    /* 14:7 */
        unsigned int dci2_dec_rpt_al                                  :   3               ;    /* 17:15 */
        unsigned int dci2_dec_rpt_llr                                 :   12              ;    /* 29:18 */
        unsigned int dci2_dec_al16_flag                               :   1               ;    /* 30 */
        unsigned int dci2_dec_rpt_comm_flag                           :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB76;

typedef union {
    struct {
        unsigned int dci2_dec_rpt_data4                               :   12              ;    /* 11:0 */
        unsigned int dci2_dec_rb_conflict0                            :   1               ;    /* 12 */
        unsigned int dci2_reserved_0                                  :   1               ;    /* 13 */
        unsigned int dci2_reserved_1                                  :   1               ;    /* 14 */
        unsigned int dci2_fake29_al8_al16_idx                         :   5               ;    /* 19:15 */
        unsigned int dci2_dec_rpt_power                               :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB81;

typedef union {
    struct {
        unsigned int dci3_dec_rpt_sss_coreset_id                      :   3               ;    /* 2:0 */
        unsigned int dci3_dec_rpt_start_symb                          :   4               ;    /* 6:3 */
        unsigned int dci3_dec_rpt_start_cce                           :   8               ;    /* 14:7 */
        unsigned int dci3_dec_rpt_al                                  :   3               ;    /* 17:15 */
        unsigned int dci3_dec_rpt_llr                                 :   12              ;    /* 29:18 */
        unsigned int dci3_dec_al16_flag                               :   1               ;    /* 30 */
        unsigned int dci3_dec_rpt_comm_flag                           :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB82;

typedef union {
    struct {
        unsigned int dci3_dec_rpt_data4                               :   12              ;    /* 11:0 */
        unsigned int dci3_dec_rb_conflict0                            :   1               ;    /* 12 */
        unsigned int dci3_reserved_0                                  :   1               ;    /* 13 */
        unsigned int dci3_reserved_1                                  :   1               ;    /* 14 */
        unsigned int dci3_fake29_al8_al16_idx                         :   5               ;    /* 19:15 */
        unsigned int dci3_dec_rpt_power                               :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB87;

typedef union {
    struct {
        unsigned int dci4_dec_rpt_sss_coreset_id                      :   3               ;    /* 2:0 */
        unsigned int dci4_dec_rpt_start_symb                          :   4               ;    /* 6:3 */
        unsigned int dci4_dec_rpt_start_cce                           :   8               ;    /* 14:7 */
        unsigned int dci4_dec_rpt_al                                  :   3               ;    /* 17:15 */
        unsigned int dci4_dec_rpt_llr                                 :   12              ;    /* 29:18 */
        unsigned int dci4_dec_al16_flag                               :   1               ;    /* 30 */
        unsigned int dci4_dec_rpt_comm_flag                           :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB88;

typedef union {
    struct {
        unsigned int dci4_dec_rpt_data4                               :   12              ;    /* 11:0 */
        unsigned int dci4_dec_rb_conflict0                            :   1               ;    /* 12 */
        unsigned int dci4_reserved_0                                  :   1               ;    /* 13 */
        unsigned int dci4_reserved_1                                  :   1               ;    /* 14 */
        unsigned int dci4_fake29_al8_al16_idx                         :   5               ;    /* 19:15 */
        unsigned int dci4_dec_rpt_power                               :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB93;

typedef union {
    struct {
        unsigned int dci5_dec_rpt_sss_coreset_id                      :   3               ;    /* 2:0 */
        unsigned int dci5_dec_rpt_start_symb                          :   4               ;    /* 6:3 */
        unsigned int dci5_dec_rpt_start_cce                           :   8               ;    /* 14:7 */
        unsigned int dci5_dec_rpt_al                                  :   3               ;    /* 17:15 */
        unsigned int dci5_dec_rpt_llr                                 :   12              ;    /* 29:18 */
        unsigned int dci5_dec_al16_flag                               :   1               ;    /* 30 */
        unsigned int dci5_dec_rpt_comm_flag                           :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB94;

typedef union {
    struct {
        unsigned int dci5_dec_rpt_data4                               :   12              ;    /* 11:0 */
        unsigned int dci5_dec_rb_conflict0                            :   1               ;    /* 12 */
        unsigned int dci5_reserved_0                                  :   1               ;    /* 13 */
        unsigned int dci5_reserved_1                                  :   1               ;    /* 14 */
        unsigned int dci5_fake29_al8_al16_idx                         :   5               ;    /* 19:15 */
        unsigned int dci5_dec_rpt_power                               :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB99;

typedef union {
    struct {
        unsigned int dci6_dec_rpt_sss_coreset_id                      :   3               ;    /* 2:0 */
        unsigned int dci6_dec_rpt_start_symb                          :   4               ;    /* 6:3 */
        unsigned int dci6_dec_rpt_start_cce                           :   8               ;    /* 14:7 */
        unsigned int dci6_dec_rpt_al                                  :   3               ;    /* 17:15 */
        unsigned int dci6_dec_rpt_llr                                 :   12              ;    /* 29:18 */
        unsigned int dci6_dec_al16_flag                               :   1               ;    /* 30 */
        unsigned int dci6_dec_rpt_comm_flag                           :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB100;

typedef union {
    struct {
        unsigned int dci6_dec_rpt_data4                               :   12              ;    /* 11:0 */
        unsigned int dci6_dec_rb_conflict0                            :   1               ;    /* 12 */
        unsigned int dci6_reserved_0                                  :   1               ;    /* 13 */
        unsigned int dci6_reserved_1                                  :   1               ;    /* 14 */
        unsigned int dci6_fake29_al8_al16_idx                         :   5               ;    /* 19:15 */
        unsigned int dci6_dec_rpt_power                               :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB105;

typedef union {
    struct {
        unsigned int dci7_dec_rpt_sss_coreset_id                      :   3               ;    /* 2:0 */
        unsigned int dci7_dec_rpt_start_symb                          :   4               ;    /* 6:3 */
        unsigned int dci7_dec_rpt_start_cce                           :   8               ;    /* 14:7 */
        unsigned int dci7_dec_rpt_al                                  :   3               ;    /* 17:15 */
        unsigned int dci7_dec_rpt_llr                                 :   12              ;    /* 29:18 */
        unsigned int dci7_dec_al16_flag                               :   1               ;    /* 30 */
        unsigned int dci7_dec_rpt_comm_flag                           :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB106;

typedef union {
    struct {
        unsigned int dci7_dec_rpt_data4                               :   12              ;    /* 11:0 */
        unsigned int dci7_dec_rb_conflict0                            :   1               ;    /* 12 */
        unsigned int dci7_reserved_0                                  :   1               ;    /* 13 */
        unsigned int dci7_reserved_1                                  :   1               ;    /* 14 */
        unsigned int dci7_fake29_al8_al16_idx                         :   5               ;    /* 19:15 */
        unsigned int dci7_dec_rpt_power                               :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB111;

typedef union {
    struct {
        unsigned int dci8_dec_rpt_sss_coreset_id                      :   3               ;    /* 2:0 */
        unsigned int dci8_dec_rpt_start_symb                          :   4               ;    /* 6:3 */
        unsigned int dci8_dec_rpt_start_cce                           :   8               ;    /* 14:7 */
        unsigned int dci8_dec_rpt_al                                  :   3               ;    /* 17:15 */
        unsigned int dci8_dec_rpt_llr                                 :   12              ;    /* 29:18 */
        unsigned int dci8_dec_al16_flag                               :   1               ;    /* 30 */
        unsigned int dci8_dec_rpt_comm_flag                           :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB112;

typedef union {
    struct {
        unsigned int dci8_dec_rpt_data4                               :   12              ;    /* 11:0 */
        unsigned int dci8_dec_rb_conflict0                            :   1               ;    /* 12 */
        unsigned int dci8_reserved_0                                  :   1               ;    /* 13 */
        unsigned int dci8_reserved_1                                  :   1               ;    /* 14 */
        unsigned int dci8_fake29_al8_al16_idx                         :   5               ;    /* 19:15 */
        unsigned int dci8_dec_rpt_power                               :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB117;

typedef union {
    struct {
        unsigned int dci9_dec_rpt_sss_coreset_id                      :   3               ;    /* 2:0 */
        unsigned int dci9_dec_rpt_start_symb                          :   4               ;    /* 6:3 */
        unsigned int dci9_dec_rpt_start_cce                           :   8               ;    /* 14:7 */
        unsigned int dci9_dec_rpt_al                                  :   3               ;    /* 17:15 */
        unsigned int dci9_dec_rpt_llr                                 :   12              ;    /* 29:18 */
        unsigned int dci9_dec_al16_flag                               :   1               ;    /* 30 */
        unsigned int dci9_dec_rpt_comm_flag                           :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB118;

typedef union {
    struct {
        unsigned int dci9_dec_rpt_data4                               :   12              ;    /* 11:0 */
        unsigned int dci9_dec_rb_conflict0                            :   1               ;    /* 12 */
        unsigned int dci9_reserved_0                                  :   1               ;    /* 13 */
        unsigned int dci9_reserved_1                                  :   1               ;    /* 14 */
        unsigned int dci9_fake29_al8_al16_idx                         :   5               ;    /* 19:15 */
        unsigned int dci9_dec_rpt_power                               :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB123;

typedef union {
    struct {
        unsigned int dci10_dec_rpt_sss_coreset_id                     :   3               ;    /* 2:0 */
        unsigned int dci10_dec_rpt_start_symb                         :   4               ;    /* 6:3 */
        unsigned int dci10_dec_rpt_start_cce                          :   8               ;    /* 14:7 */
        unsigned int dci10_dec_rpt_al                                 :   3               ;    /* 17:15 */
        unsigned int dci10_dec_rpt_llr                                :   12              ;    /* 29:18 */
        unsigned int dci10_dec_al16_flag                              :   1               ;    /* 30 */
        unsigned int dci10_dec_rpt_comm_flag                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB124;

typedef union {
    struct {
        unsigned int dci10_dec_rpt_data4                              :   12              ;    /* 11:0 */
        unsigned int dci10_dec_rb_conflict0                           :   1               ;    /* 12 */
        unsigned int dci10_reserved_0                                 :   1               ;    /* 13 */
        unsigned int dci10_reserved_1                                 :   1               ;    /* 14 */
        unsigned int dci10_fake29_al8_al16_idx                        :   5               ;    /* 19:15 */
        unsigned int dci10_dec_rpt_power                              :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB129;

typedef union {
    struct {
        unsigned int dci11_dec_rpt_sss_coreset_id                     :   3               ;    /* 2:0 */
        unsigned int dci11_dec_rpt_start_symb                         :   4               ;    /* 6:3 */
        unsigned int dci11_dec_rpt_start_cce                          :   8               ;    /* 14:7 */
        unsigned int dci11_dec_rpt_al                                 :   3               ;    /* 17:15 */
        unsigned int dci11_dec_rpt_llr                                :   12              ;    /* 29:18 */
        unsigned int dci11_dec_al16_flag                              :   1               ;    /* 30 */
        unsigned int dci11_dec_rpt_comm_flag                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB130;

typedef union {
    struct {
        unsigned int dci11_dec_rpt_data4                              :   12              ;    /* 11:0 */
        unsigned int dci11_dec_rb_conflict0                           :   1               ;    /* 12 */
        unsigned int dci11_reserved_0                                 :   1               ;    /* 13 */
        unsigned int dci11_reserved_1                                 :   1               ;    /* 14 */
        unsigned int dci11_fake29_al8_al16_idx                        :   5               ;    /* 19:15 */
        unsigned int dci11_dec_rpt_power                              :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB135;

typedef union {
    struct {
        unsigned int dci12_dec_rpt_sss_coreset_id                     :   3               ;    /* 2:0 */
        unsigned int dci12_dec_rpt_start_symb                         :   4               ;    /* 6:3 */
        unsigned int dci12_dec_rpt_start_cce                          :   8               ;    /* 14:7 */
        unsigned int dci12_dec_rpt_al                                 :   3               ;    /* 17:15 */
        unsigned int dci12_dec_rpt_llr                                :   12              ;    /* 29:18 */
        unsigned int dci12_dec_al16_flag                              :   1               ;    /* 30 */
        unsigned int dci12_dec_rpt_comm_flag                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB136;

typedef union {
    struct {
        unsigned int dci12_dec_rpt_data4                              :   12              ;    /* 11:0 */
        unsigned int dci12_dec_rb_conflict0                           :   1               ;    /* 12 */
        unsigned int dci12_reserved_0                                 :   1               ;    /* 13 */
        unsigned int dci12_reserved_1                                 :   1               ;    /* 14 */
        unsigned int dci12_fake29_al8_al16_idx                        :   5               ;    /* 19:15 */
        unsigned int dci12_dec_rpt_power                              :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB141;

typedef union {
    struct {
        unsigned int dci13_dec_rpt_sss_coreset_id                     :   3               ;    /* 2:0 */
        unsigned int dci13_dec_rpt_start_symb                         :   4               ;    /* 6:3 */
        unsigned int dci13_dec_rpt_start_cce                          :   8               ;    /* 14:7 */
        unsigned int dci13_dec_rpt_al                                 :   3               ;    /* 17:15 */
        unsigned int dci13_dec_rpt_llr                                :   12              ;    /* 29:18 */
        unsigned int dci13_dec_al16_flag                              :   1               ;    /* 30 */
        unsigned int dci13_dec_rpt_comm_flag                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB142;

typedef union {
    struct {
        unsigned int dci13_dec_rpt_data4                              :   12              ;    /* 11:0 */
        unsigned int dci13_dec_rb_conflict0                           :   1               ;    /* 12 */
        unsigned int dci13_reserved_0                                 :   1               ;    /* 13 */
        unsigned int dci13_reserved_1                                 :   1               ;    /* 14 */
        unsigned int dci13_fake29_al8_al16_idx                        :   5               ;    /* 19:15 */
        unsigned int dci13_dec_rpt_power                              :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB147;

typedef union {
    struct {
        unsigned int dci14_dec_rpt_sss_coreset_id                     :   3               ;    /* 2:0 */
        unsigned int dci14_dec_rpt_start_symb                         :   4               ;    /* 6:3 */
        unsigned int dci14_dec_rpt_start_cce                          :   8               ;    /* 14:7 */
        unsigned int dci14_dec_rpt_al                                 :   3               ;    /* 17:15 */
        unsigned int dci14_dec_rpt_llr                                :   12              ;    /* 29:18 */
        unsigned int dci14_dec_al16_flag                              :   1               ;    /* 30 */
        unsigned int dci14_dec_rpt_comm_flag                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB148;

typedef union {
    struct {
        unsigned int dci14_dec_rpt_data4                              :   12              ;    /* 11:0 */
        unsigned int dci14_dec_rb_conflict0                           :   1               ;    /* 12 */
        unsigned int dci14_reserved_0                                 :   1               ;    /* 13 */
        unsigned int dci14_reserved_1                                 :   1               ;    /* 14 */
        unsigned int dci14_fake29_al8_al16_idx                        :   5               ;    /* 19:15 */
        unsigned int dci14_dec_rpt_power                              :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB153;

typedef union {
    struct {
        unsigned int dci15_dec_rpt_sss_coreset_id                     :   3               ;    /* 2:0 */
        unsigned int dci15_dec_rpt_start_symb                         :   4               ;    /* 6:3 */
        unsigned int dci15_dec_rpt_start_cce                          :   8               ;    /* 14:7 */
        unsigned int dci15_dec_rpt_al                                 :   3               ;    /* 17:15 */
        unsigned int dci15_dec_rpt_llr                                :   12              ;    /* 29:18 */
        unsigned int dci15_dec_al16_flag                              :   1               ;    /* 30 */
        unsigned int dci15_dec_rpt_comm_flag                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB154;

typedef union {
    struct {
        unsigned int dci15_dec_rpt_data4                              :   12              ;    /* 11:0 */
        unsigned int dci15_dec_rb_conflict0                           :   1               ;    /* 12 */
        unsigned int dci15_reserved_0                                 :   1               ;    /* 13 */
        unsigned int dci15_reserved_1                                 :   1               ;    /* 14 */
        unsigned int dci15_fake29_al8_al16_idx                        :   5               ;    /* 19:15 */
        unsigned int dci15_dec_rpt_power                              :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB159;

typedef union {
    struct {
        unsigned int dci16_dec_rpt_sss_coreset_id                     :   3               ;    /* 2:0 */
        unsigned int dci16_dec_rpt_start_symb                         :   4               ;    /* 6:3 */
        unsigned int dci16_dec_rpt_start_cce                          :   8               ;    /* 14:7 */
        unsigned int dci16_dec_rpt_al                                 :   3               ;    /* 17:15 */
        unsigned int dci16_dec_rpt_llr                                :   12              ;    /* 29:18 */
        unsigned int dci16_dec_al16_flag                              :   1               ;    /* 30 */
        unsigned int dci16_dec_rpt_comm_flag                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB160;

typedef union {
    struct {
        unsigned int dci16_dec_rpt_data4                              :   12              ;    /* 11:0 */
        unsigned int dci16_dec_rb_conflict0                           :   1               ;    /* 12 */
        unsigned int dci16_reserved_0                                 :   1               ;    /* 13 */
        unsigned int dci16_reserved_1                                 :   1               ;    /* 14 */
        unsigned int dci16_fake29_al8_al16_idx                        :   5               ;    /* 19:15 */
        unsigned int dci16_dec_rpt_power                              :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB165;

typedef union {
    struct {
        unsigned int dci17_dec_rpt_sss_coreset_id                     :   3               ;    /* 2:0 */
        unsigned int dci17_dec_rpt_start_symb                         :   4               ;    /* 6:3 */
        unsigned int dci17_dec_rpt_start_cce                          :   8               ;    /* 14:7 */
        unsigned int dci17_dec_rpt_al                                 :   3               ;    /* 17:15 */
        unsigned int dci17_dec_rpt_llr                                :   12              ;    /* 29:18 */
        unsigned int dci17_dec_al16_flag                              :   1               ;    /* 30 */
        unsigned int dci17_dec_rpt_comm_flag                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB166;

typedef union {
    struct {
        unsigned int dci17_dec_rpt_data4                              :   12              ;    /* 11:0 */
        unsigned int dci17_dec_rb_conflict0                           :   1               ;    /* 12 */
        unsigned int dci17_reserved_0                                 :   1               ;    /* 13 */
        unsigned int dci17_reserved_1                                 :   1               ;    /* 14 */
        unsigned int dci17_fake29_al8_al16_idx                        :   5               ;    /* 19:15 */
        unsigned int dci17_dec_rpt_power                              :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB171;

typedef union {
    struct {
        unsigned int dci18_dec_rpt_sss_coreset_id                     :   3               ;    /* 2:0 */
        unsigned int dci18_dec_rpt_start_symb                         :   4               ;    /* 6:3 */
        unsigned int dci18_dec_rpt_start_cce                          :   8               ;    /* 14:7 */
        unsigned int dci18_dec_rpt_al                                 :   3               ;    /* 17:15 */
        unsigned int dci18_dec_rpt_llr                                :   12              ;    /* 29:18 */
        unsigned int dci18_dec_al16_flag                              :   1               ;    /* 30 */
        unsigned int dci18_dec_rpt_comm_flag                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB172;

typedef union {
    struct {
        unsigned int dci18_dec_rpt_data4                              :   12              ;    /* 11:0 */
        unsigned int dci18_dec_rb_conflict0                           :   1               ;    /* 12 */
        unsigned int dci18_reserved_0                                 :   1               ;    /* 13 */
        unsigned int dci18_reserved_1                                 :   1               ;    /* 14 */
        unsigned int dci18_fake29_al8_al16_idx                        :   5               ;    /* 19:15 */
        unsigned int dci18_dec_rpt_power                              :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB177;

typedef union {
    struct {
        unsigned int dci19_dec_rpt_sss_coreset_id                     :   3               ;    /* 2:0 */
        unsigned int dci19_dec_rpt_start_symb                         :   4               ;    /* 6:3 */
        unsigned int dci19_dec_rpt_start_cce                          :   8               ;    /* 14:7 */
        unsigned int dci19_dec_rpt_al                                 :   3               ;    /* 17:15 */
        unsigned int dci19_dec_rpt_llr                                :   12              ;    /* 29:18 */
        unsigned int dci19_dec_al16_flag                              :   1               ;    /* 30 */
        unsigned int dci19_dec_rpt_comm_flag                          :   1               ;    /* 31 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB178;

typedef union {
    struct {
        unsigned int dci19_dec_rpt_data4                              :   12              ;    /* 11:0 */
        unsigned int dci19_dec_rb_conflict0                           :   1               ;    /* 12 */
        unsigned int dci19_reserved_0                                 :   1               ;    /* 13 */
        unsigned int dci19_reserved_1                                 :   1               ;    /* 14 */
        unsigned int dci19_fake29_al8_al16_idx                        :   5               ;    /* 19:15 */
        unsigned int dci19_dec_rpt_power                              :   12              ;    /* 31:20 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB183;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      dsp_reserved0_0;
    unsigned int                                                      dsp_reserved1_1;
    unsigned int                                                      dsp_reserved2_2;
    unsigned int                                                      dsp_reserved3_3;
    unsigned int                                                      dsp_reserved4_4;
    unsigned int                                                      dsp_reserved5_5;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB6                              om_data6;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB7                              om_data7;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB8                              om_data8;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB9                              om_data9;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB10                             om_data10;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB11                             om_data11;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB12                             om_data12;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB13                             om_data13;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB14                             om_data14;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB15                             om_data15;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB16                             om_data16;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB17                             om_data17;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB18                             om_data18;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB19                             om_data19;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB20                             om_data20;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB21                             om_data21;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB22                             om_data22;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB23                             om_data23;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB24                             om_data24;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB25                             om_data25;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB26                             om_data26;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB27                             om_data27;
    unsigned int                                                      pde_bypass;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB29                             om_data29;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB30                             om_data30;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB31                             om_data31;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB32                             om_data32;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB33                             om_data33;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB34                             om_data34;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB35                             om_data35;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB36                             om_data36;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB37                             om_data37;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB38                             om_data38;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB39                             om_data39;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB40                             om_data40;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB41                             om_data41;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB42                             om_data42;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB43                             om_data43;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB44                             om_data44;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB45                             om_data45;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB46                             om_data46;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB47                             om_data47;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB48                             om_data48;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB49                             om_data49;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB50                             om_data50;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB51                             om_data51;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB52                             om_data52;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB53                             om_data53;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB54                             om_data54;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB55                             om_data55;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB56                             om_data56;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB57                             om_data57;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB58                             om_data58;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB59                             om_data59;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB60                             om_data60;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB61                             om_data61;
    unsigned int                                                      reserved_6;
    unsigned int                                                      reserved_7;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB64                             om_data64;
    unsigned int                                                      dci0_dec_rpt_data0;
    unsigned int                                                      dci0_dec_rpt_data1;
    unsigned int                                                      dci0_dec_rpt_data2;
    unsigned int                                                      dci0_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB69                             om_data69;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB70                             om_data70;
    unsigned int                                                      dci1_dec_rpt_data0;
    unsigned int                                                      dci1_dec_rpt_data1;
    unsigned int                                                      dci1_dec_rpt_data2;
    unsigned int                                                      dci1_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB75                             om_data75;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB76                             om_data76;
    unsigned int                                                      dci2_dec_rpt_data0;
    unsigned int                                                      dci2_dec_rpt_data1;
    unsigned int                                                      dci2_dec_rpt_data2;
    unsigned int                                                      dci2_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB81                             om_data81;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB82                             om_data82;
    unsigned int                                                      dci3_dec_rpt_data0;
    unsigned int                                                      dci3_dec_rpt_data1;
    unsigned int                                                      dci3_dec_rpt_data2;
    unsigned int                                                      dci3_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB87                             om_data87;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB88                             om_data88;
    unsigned int                                                      dci4_dec_rpt_data0;
    unsigned int                                                      dci4_dec_rpt_data1;
    unsigned int                                                      dci4_dec_rpt_data2;
    unsigned int                                                      dci4_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB93                             om_data93;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB94                             om_data94;
    unsigned int                                                      dci5_dec_rpt_data0;
    unsigned int                                                      dci5_dec_rpt_data1;
    unsigned int                                                      dci5_dec_rpt_data2;
    unsigned int                                                      dci5_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB99                             om_data99;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB100                            om_data100;
    unsigned int                                                      dci6_dec_rpt_data0;
    unsigned int                                                      dci6_dec_rpt_data1;
    unsigned int                                                      dci6_dec_rpt_data2;
    unsigned int                                                      dci6_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB105                            om_data105;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB106                            om_data106;
    unsigned int                                                      dci7_dec_rpt_data0;
    unsigned int                                                      dci7_dec_rpt_data1;
    unsigned int                                                      dci7_dec_rpt_data2;
    unsigned int                                                      dci7_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB111                            om_data111;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB112                            om_data112;
    unsigned int                                                      dci8_dec_rpt_data0;
    unsigned int                                                      dci8_dec_rpt_data1;
    unsigned int                                                      dci8_dec_rpt_data2;
    unsigned int                                                      dci8_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB117                            om_data117;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB118                            om_data118;
    unsigned int                                                      dci9_dec_rpt_data0;
    unsigned int                                                      dci9_dec_rpt_data1;
    unsigned int                                                      dci9_dec_rpt_data2;
    unsigned int                                                      dci9_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB123                            om_data123;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB124                            om_data124;
    unsigned int                                                      dci10_dec_rpt_data0;
    unsigned int                                                      dci10_dec_rpt_data1;
    unsigned int                                                      dci10_dec_rpt_data2;
    unsigned int                                                      dci10_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB129                            om_data129;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB130                            om_data130;
    unsigned int                                                      dci11_dec_rpt_data0;
    unsigned int                                                      dci11_dec_rpt_data1;
    unsigned int                                                      dci11_dec_rpt_data2;
    unsigned int                                                      dci11_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB135                            om_data135;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB136                            om_data136;
    unsigned int                                                      dci12_dec_rpt_data0;
    unsigned int                                                      dci12_dec_rpt_data1;
    unsigned int                                                      dci12_dec_rpt_data2;
    unsigned int                                                      dci12_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB141                            om_data141;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB142                            om_data142;
    unsigned int                                                      dci13_dec_rpt_data0;
    unsigned int                                                      dci13_dec_rpt_data1;
    unsigned int                                                      dci13_dec_rpt_data2;
    unsigned int                                                      dci13_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB147                            om_data147;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB148                            om_data148;
    unsigned int                                                      dci14_dec_rpt_data0;
    unsigned int                                                      dci14_dec_rpt_data1;
    unsigned int                                                      dci14_dec_rpt_data2;
    unsigned int                                                      dci14_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB153                            om_data153;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB154                            om_data154;
    unsigned int                                                      dci15_dec_rpt_data0;
    unsigned int                                                      dci15_dec_rpt_data1;
    unsigned int                                                      dci15_dec_rpt_data2;
    unsigned int                                                      dci15_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB159                            om_data159;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB160                            om_data160;
    unsigned int                                                      dci16_dec_rpt_data0;
    unsigned int                                                      dci16_dec_rpt_data1;
    unsigned int                                                      dci16_dec_rpt_data2;
    unsigned int                                                      dci16_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB165                            om_data165;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB166                            om_data166;
    unsigned int                                                      dci17_dec_rpt_data0;
    unsigned int                                                      dci17_dec_rpt_data1;
    unsigned int                                                      dci17_dec_rpt_data2;
    unsigned int                                                      dci17_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB171                            om_data171;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB172                            om_data172;
    unsigned int                                                      dci18_dec_rpt_data0;
    unsigned int                                                      dci18_dec_rpt_data1;
    unsigned int                                                      dci18_dec_rpt_data2;
    unsigned int                                                      dci18_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB177                            om_data177;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB178                            om_data178;
    unsigned int                                                      dci19_dec_rpt_data0;
    unsigned int                                                      dci19_dec_rpt_data1;
    unsigned int                                                      dci19_dec_rpt_data2;
    unsigned int                                                      dci19_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB183                            om_data183;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      dsp_reserved0_0;
    unsigned int                                                      dsp_reserved1_1;
    unsigned int                                                      dsp_reserved2_2;
    unsigned int                                                      dsp_reserved3_3;
    unsigned int                                                      dsp_reserved4_4;
    unsigned int                                                      dsp_reserved5_5;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB6                              om_data6;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB7                              om_data7;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB8                              om_data8;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB9                              om_data9;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB10                             om_data10;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB11                             om_data11;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB12                             om_data12;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB13                             om_data13;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB14                             om_data14;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB15                             om_data15;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB16                             om_data16;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB17                             om_data17;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB18                             om_data18;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB19                             om_data19;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB20                             om_data20;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB21                             om_data21;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB22                             om_data22;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB23                             om_data23;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB24                             om_data24;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB25                             om_data25;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB26                             om_data26;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB27                             om_data27;
    unsigned int                                                      pde_bypass;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB29                             om_data29;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB30                             om_data30;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB31                             om_data31;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB32                             om_data32;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB33                             om_data33;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB34                             om_data34;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB35                             om_data35;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB36                             om_data36;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB37                             om_data37;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB38                             om_data38;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB39                             om_data39;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB40                             om_data40;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB41                             om_data41;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB42                             om_data42;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB43                             om_data43;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB44                             om_data44;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB45                             om_data45;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB46                             om_data46;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB47                             om_data47;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB48                             om_data48;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB49                             om_data49;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB50                             om_data50;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB51                             om_data51;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB52                             om_data52;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB53                             om_data53;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB54                             om_data54;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB55                             om_data55;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB56                             om_data56;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB57                             om_data57;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB58                             om_data58;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB59                             om_data59;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB60                             om_data60;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB61                             om_data61;
    unsigned int                                                      reserved_6;
    unsigned int                                                      reserved_7;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB64                             om_data64;
    unsigned int                                                      dci0_dec_rpt_data0;
    unsigned int                                                      dci0_dec_rpt_data1;
    unsigned int                                                      dci0_dec_rpt_data2;
    unsigned int                                                      dci0_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB69                             om_data69;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB70                             om_data70;
    unsigned int                                                      dci1_dec_rpt_data0;
    unsigned int                                                      dci1_dec_rpt_data1;
    unsigned int                                                      dci1_dec_rpt_data2;
    unsigned int                                                      dci1_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB75                             om_data75;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB76                             om_data76;
    unsigned int                                                      dci2_dec_rpt_data0;
    unsigned int                                                      dci2_dec_rpt_data1;
    unsigned int                                                      dci2_dec_rpt_data2;
    unsigned int                                                      dci2_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB81                             om_data81;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB82                             om_data82;
    unsigned int                                                      dci3_dec_rpt_data0;
    unsigned int                                                      dci3_dec_rpt_data1;
    unsigned int                                                      dci3_dec_rpt_data2;
    unsigned int                                                      dci3_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB87                             om_data87;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB88                             om_data88;
    unsigned int                                                      dci4_dec_rpt_data0;
    unsigned int                                                      dci4_dec_rpt_data1;
    unsigned int                                                      dci4_dec_rpt_data2;
    unsigned int                                                      dci4_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB93                             om_data93;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB94                             om_data94;
    unsigned int                                                      dci5_dec_rpt_data0;
    unsigned int                                                      dci5_dec_rpt_data1;
    unsigned int                                                      dci5_dec_rpt_data2;
    unsigned int                                                      dci5_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB99                             om_data99;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB100                            om_data100;
    unsigned int                                                      dci6_dec_rpt_data0;
    unsigned int                                                      dci6_dec_rpt_data1;
    unsigned int                                                      dci6_dec_rpt_data2;
    unsigned int                                                      dci6_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB105                            om_data105;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB106                            om_data106;
    unsigned int                                                      dci7_dec_rpt_data0;
    unsigned int                                                      dci7_dec_rpt_data1;
    unsigned int                                                      dci7_dec_rpt_data2;
    unsigned int                                                      dci7_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB111                            om_data111;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB112                            om_data112;
    unsigned int                                                      dci8_dec_rpt_data0;
    unsigned int                                                      dci8_dec_rpt_data1;
    unsigned int                                                      dci8_dec_rpt_data2;
    unsigned int                                                      dci8_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB117                            om_data117;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB118                            om_data118;
    unsigned int                                                      dci9_dec_rpt_data0;
    unsigned int                                                      dci9_dec_rpt_data1;
    unsigned int                                                      dci9_dec_rpt_data2;
    unsigned int                                                      dci9_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB123                            om_data123;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB124                            om_data124;
    unsigned int                                                      dci10_dec_rpt_data0;
    unsigned int                                                      dci10_dec_rpt_data1;
    unsigned int                                                      dci10_dec_rpt_data2;
    unsigned int                                                      dci10_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB129                            om_data129;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB130                            om_data130;
    unsigned int                                                      dci11_dec_rpt_data0;
    unsigned int                                                      dci11_dec_rpt_data1;
    unsigned int                                                      dci11_dec_rpt_data2;
    unsigned int                                                      dci11_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB135                            om_data135;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB136                            om_data136;
    unsigned int                                                      dci12_dec_rpt_data0;
    unsigned int                                                      dci12_dec_rpt_data1;
    unsigned int                                                      dci12_dec_rpt_data2;
    unsigned int                                                      dci12_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB141                            om_data141;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB142                            om_data142;
    unsigned int                                                      dci13_dec_rpt_data0;
    unsigned int                                                      dci13_dec_rpt_data1;
    unsigned int                                                      dci13_dec_rpt_data2;
    unsigned int                                                      dci13_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB147                            om_data147;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB148                            om_data148;
    unsigned int                                                      dci14_dec_rpt_data0;
    unsigned int                                                      dci14_dec_rpt_data1;
    unsigned int                                                      dci14_dec_rpt_data2;
    unsigned int                                                      dci14_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB153                            om_data153;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB154                            om_data154;
    unsigned int                                                      dci15_dec_rpt_data0;
    unsigned int                                                      dci15_dec_rpt_data1;
    unsigned int                                                      dci15_dec_rpt_data2;
    unsigned int                                                      dci15_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB159                            om_data159;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB160                            om_data160;
    unsigned int                                                      dci16_dec_rpt_data0;
    unsigned int                                                      dci16_dec_rpt_data1;
    unsigned int                                                      dci16_dec_rpt_data2;
    unsigned int                                                      dci16_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB165                            om_data165;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB166                            om_data166;
    unsigned int                                                      dci17_dec_rpt_data0;
    unsigned int                                                      dci17_dec_rpt_data1;
    unsigned int                                                      dci17_dec_rpt_data2;
    unsigned int                                                      dci17_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB171                            om_data171;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB172                            om_data172;
    unsigned int                                                      dci18_dec_rpt_data0;
    unsigned int                                                      dci18_dec_rpt_data1;
    unsigned int                                                      dci18_dec_rpt_data2;
    unsigned int                                                      dci18_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB177                            om_data177;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB178                            om_data178;
    unsigned int                                                      dci19_dec_rpt_data0;
    unsigned int                                                      dci19_dec_rpt_data1;
    unsigned int                                                      dci19_dec_rpt_data2;
    unsigned int                                                      dci19_dec_rpt_data3;
    DCICP_SID_DCICP_OM_INFO_PDC_RPT_SUB183                            om_data183;
} DCICP_SID_DCICP_OM_INFO_PDC_RPT_BBP_MC;

typedef union {
    struct {
        unsigned int arr0_old_cfg_idx0                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_cfg_idx1                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB0;

typedef union {
    struct {
        unsigned int arr0_old_cfg_idx2                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_cfg_idx3                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB1;

typedef union {
    struct {
        unsigned int arr0_old_cfg_idx4                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_cfg_idx5                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB2;

typedef union {
    struct {
        unsigned int arr0_old_cfg_idx6                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_cfg_idx7                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB3;

typedef union {
    struct {
        unsigned int arr0_old_cfg_idx8                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_cfg_idx9                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB4;

typedef union {
    struct {
        unsigned int arr0_old_cfg_idx10                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_cfg_idx11                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB5;

typedef union {
    struct {
        unsigned int arr0_old_cfg_idx12                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_cfg_idx13                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB6;

typedef union {
    struct {
        unsigned int arr0_old_cfg_idx14                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_cfg_idx15                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB7;

typedef union {
    struct {
        unsigned int arr0_old_dci_llr0                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_llr1                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB8;

typedef union {
    struct {
        unsigned int arr0_old_dci_llr2                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_llr3                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB9;

typedef union {
    struct {
        unsigned int arr0_old_dci_llr4                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_llr5                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB10;

typedef union {
    struct {
        unsigned int arr0_old_dci_llr6                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_llr7                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB11;

typedef union {
    struct {
        unsigned int arr0_old_dci_llr8                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_llr9                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB12;

typedef union {
    struct {
        unsigned int arr0_old_dci_llr10                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_llr11                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB13;

typedef union {
    struct {
        unsigned int arr0_old_dci_llr12                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_llr13                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB14;

typedef union {
    struct {
        unsigned int arr0_old_dci_llr14                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_llr15                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB15;

typedef union {
    struct {
        unsigned int arr0_old_hed0                                    :   16              ;    /* 15:0 */
        unsigned int arr0_old_hed1                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB16;

typedef union {
    struct {
        unsigned int arr0_old_hed2                                    :   16              ;    /* 15:0 */
        unsigned int arr0_old_hed3                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB17;

typedef union {
    struct {
        unsigned int arr0_old_hed4                                    :   16              ;    /* 15:0 */
        unsigned int arr0_old_hed5                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB18;

typedef union {
    struct {
        unsigned int arr0_old_hed6                                    :   16              ;    /* 15:0 */
        unsigned int arr0_old_hed7                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB19;

typedef union {
    struct {
        unsigned int arr0_old_hed8                                    :   16              ;    /* 15:0 */
        unsigned int arr0_old_hed9                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB20;

typedef union {
    struct {
        unsigned int arr0_old_hed10                                   :   16              ;    /* 15:0 */
        unsigned int arr0_old_hed11                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB21;

typedef union {
    struct {
        unsigned int arr0_old_hed12                                   :   16              ;    /* 15:0 */
        unsigned int arr0_old_hed13                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB22;

typedef union {
    struct {
        unsigned int arr0_old_hed14                                   :   16              ;    /* 15:0 */
        unsigned int arr0_old_hed15                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB23;

typedef union {
    struct {
        unsigned int arr0_old_pds_sfm0                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_sfm1                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB24;

typedef union {
    struct {
        unsigned int arr0_old_pds_sfm2                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_sfm3                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB25;

typedef union {
    struct {
        unsigned int arr0_old_pds_sfm4                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_sfm5                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB26;

typedef union {
    struct {
        unsigned int arr0_old_pds_sfm6                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_sfm7                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB27;

typedef union {
    struct {
        unsigned int arr0_old_pds_sfm8                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_sfm9                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB28;

typedef union {
    struct {
        unsigned int arr0_old_pds_sfm10                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_sfm11                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB29;

typedef union {
    struct {
        unsigned int arr0_old_pds_sfm12                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_sfm13                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB30;

typedef union {
    struct {
        unsigned int arr0_old_pds_sfm14                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_sfm15                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB31;

typedef union {
    struct {
        unsigned int arr0_old_pds_slot0                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_slot1                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB32;

typedef union {
    struct {
        unsigned int arr0_old_pds_slot2                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_slot3                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB33;

typedef union {
    struct {
        unsigned int arr0_old_pds_slot4                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_slot5                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB34;

typedef union {
    struct {
        unsigned int arr0_old_pds_slot6                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_slot7                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB35;

typedef union {
    struct {
        unsigned int arr0_old_pds_slot8                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_slot9                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB36;

typedef union {
    struct {
        unsigned int arr0_old_pds_slot10                              :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_slot11                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB37;

typedef union {
    struct {
        unsigned int arr0_old_pds_slot12                              :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_slot13                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB38;

typedef union {
    struct {
        unsigned int arr0_old_pds_slot14                              :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_slot15                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB39;

typedef union {
    struct {
        unsigned int arr0_old_pdc_sfm0                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_sfm1                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB40;

typedef union {
    struct {
        unsigned int arr0_old_pdc_sfm2                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_sfm3                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB41;

typedef union {
    struct {
        unsigned int arr0_old_pdc_sfm4                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_sfm5                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB42;

typedef union {
    struct {
        unsigned int arr0_old_pdc_sfm6                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_sfm7                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB43;

typedef union {
    struct {
        unsigned int arr0_old_pdc_sfm8                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_sfm9                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB44;

typedef union {
    struct {
        unsigned int arr0_old_pdc_sfm10                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_sfm11                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB45;

typedef union {
    struct {
        unsigned int arr0_old_pdc_sfm12                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_sfm13                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB46;

typedef union {
    struct {
        unsigned int arr0_old_pdc_sfm14                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_sfm15                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB47;

typedef union {
    struct {
        unsigned int arr0_old_pdc_slot0                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_slot1                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB48;

typedef union {
    struct {
        unsigned int arr0_old_pdc_slot2                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_slot3                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB49;

typedef union {
    struct {
        unsigned int arr0_old_pdc_slot4                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_slot5                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB50;

typedef union {
    struct {
        unsigned int arr0_old_pdc_slot6                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_slot7                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB51;

typedef union {
    struct {
        unsigned int arr0_old_pdc_slot8                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_slot9                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB52;

typedef union {
    struct {
        unsigned int arr0_old_pdc_slot10                              :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_slot11                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB53;

typedef union {
    struct {
        unsigned int arr0_old_pdc_slot12                              :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_slot13                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB54;

typedef union {
    struct {
        unsigned int arr0_old_pdc_slot14                              :   16              ;    /* 15:0 */
        unsigned int arr0_old_pdc_slot15                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB55;

typedef union {
    struct {
        unsigned int arr0_old_ch_type0                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_ch_type1                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB56;

typedef union {
    struct {
        unsigned int arr0_old_ch_type2                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_ch_type3                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB57;

typedef union {
    struct {
        unsigned int arr0_old_ch_type4                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_ch_type5                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB58;

typedef union {
    struct {
        unsigned int arr0_old_ch_type6                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_ch_type7                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB59;

typedef union {
    struct {
        unsigned int arr0_old_ch_type8                                :   16              ;    /* 15:0 */
        unsigned int arr0_old_ch_type9                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB60;

typedef union {
    struct {
        unsigned int arr0_old_ch_type10                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_ch_type11                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB61;

typedef union {
    struct {
        unsigned int arr0_old_ch_type12                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_ch_type13                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB62;

typedef union {
    struct {
        unsigned int arr0_old_ch_type14                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_ch_type15                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB63;

typedef union {
    struct {
        unsigned int arr0_r_idx0                                      :   16              ;    /* 15:0 */
        unsigned int arr0_r_idx1                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB64;

typedef union {
    struct {
        unsigned int arr0_r_idx2                                      :   16              ;    /* 15:0 */
        unsigned int arr0_r_idx3                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB65;

typedef union {
    struct {
        unsigned int arr0_r_idx4                                      :   16              ;    /* 15:0 */
        unsigned int arr0_r_idx5                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB66;

typedef union {
    struct {
        unsigned int arr0_r_idx6                                      :   16              ;    /* 15:0 */
        unsigned int arr0_r_idx7                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB67;

typedef union {
    struct {
        unsigned int arr0_r_idx8                                      :   16              ;    /* 15:0 */
        unsigned int arr0_r_idx9                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB68;

typedef union {
    struct {
        unsigned int arr0_r_idx10                                     :   16              ;    /* 15:0 */
        unsigned int arr0_r_idx11                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB69;

typedef union {
    struct {
        unsigned int arr0_r_idx12                                     :   16              ;    /* 15:0 */
        unsigned int arr0_r_idx13                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB70;

typedef union {
    struct {
        unsigned int arr0_r_idx14                                     :   16              ;    /* 15:0 */
        unsigned int arr0_r_idx15                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB71;

typedef union {
    struct {
        unsigned int arr0_bwp_id0                                     :   16              ;    /* 15:0 */
        unsigned int arr0_bwp_id1                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB72;

typedef union {
    struct {
        unsigned int arr0_bwp_id2                                     :   16              ;    /* 15:0 */
        unsigned int arr0_bwp_id3                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB73;

typedef union {
    struct {
        unsigned int arr0_bwp_id4                                     :   16              ;    /* 15:0 */
        unsigned int arr0_bwp_id5                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB74;

typedef union {
    struct {
        unsigned int arr0_bwp_id6                                     :   16              ;    /* 15:0 */
        unsigned int arr0_bwp_id7                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB75;

typedef union {
    struct {
        unsigned int arr0_bwp_id8                                     :   16              ;    /* 15:0 */
        unsigned int arr0_bwp_id9                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB76;

typedef union {
    struct {
        unsigned int arr0_bwp_id10                                    :   16              ;    /* 15:0 */
        unsigned int arr0_bwp_id11                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB77;

typedef union {
    struct {
        unsigned int arr0_bwp_id12                                    :   16              ;    /* 15:0 */
        unsigned int arr0_bwp_id13                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB78;

typedef union {
    struct {
        unsigned int arr0_bwp_id14                                    :   16              ;    /* 15:0 */
        unsigned int arr0_bwp_id15                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB79;

typedef union {
    struct {
        unsigned int arr0_store_dl_dci_idx0                           :   16              ;    /* 15:0 */
        unsigned int arr0_store_dl_dci_idx1                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB80;

typedef union {
    struct {
        unsigned int arr0_store_dl_dci_idx2                           :   16              ;    /* 15:0 */
        unsigned int arr0_store_dl_dci_idx3                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB81;

typedef union {
    struct {
        unsigned int arr0_store_dl_dci_idx4                           :   16              ;    /* 15:0 */
        unsigned int arr0_store_dl_dci_idx5                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB82;

typedef union {
    struct {
        unsigned int arr0_store_dl_dci_idx6                           :   16              ;    /* 15:0 */
        unsigned int arr0_store_dl_dci_idx7                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB83;

typedef union {
    struct {
        unsigned int arr0_store_dl_dci_idx8                           :   16              ;    /* 15:0 */
        unsigned int arr0_store_dl_dci_idx9                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB84;

typedef union {
    struct {
        unsigned int arr0_store_dl_dci_idx10                          :   16              ;    /* 15:0 */
        unsigned int arr0_store_dl_dci_idx11                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB85;

typedef union {
    struct {
        unsigned int arr0_store_dl_dci_idx12                          :   16              ;    /* 15:0 */
        unsigned int arr0_store_dl_dci_idx13                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB86;

typedef union {
    struct {
        unsigned int arr0_store_dl_dci_idx14                          :   16              ;    /* 15:0 */
        unsigned int arr0_store_dl_dci_idx15                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB87;

typedef union {
    struct {
        unsigned int arr0_k0_value0                                   :   16              ;    /* 15:0 */
        unsigned int arr0_k0_value1                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB88;

typedef union {
    struct {
        unsigned int arr0_k0_value2                                   :   16              ;    /* 15:0 */
        unsigned int arr0_k0_value3                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB89;

typedef union {
    struct {
        unsigned int arr0_k0_value4                                   :   16              ;    /* 15:0 */
        unsigned int arr0_k0_value5                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB90;

typedef union {
    struct {
        unsigned int arr0_k0_value6                                   :   16              ;    /* 15:0 */
        unsigned int arr0_k0_value7                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB91;

typedef union {
    struct {
        unsigned int arr0_k0_value8                                   :   16              ;    /* 15:0 */
        unsigned int arr0_k0_value9                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB92;

typedef union {
    struct {
        unsigned int arr0_k0_value10                                  :   16              ;    /* 15:0 */
        unsigned int arr0_k0_value11                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB93;

typedef union {
    struct {
        unsigned int arr0_k0_value12                                  :   16              ;    /* 15:0 */
        unsigned int arr0_k0_value13                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB94;

typedef union {
    struct {
        unsigned int arr0_k0_value14                                  :   16              ;    /* 15:0 */
        unsigned int arr0_k0_value15                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB95;

typedef union {
    struct {
        unsigned int arr0_repet_num0                                  :   16              ;    /* 15:0 */
        unsigned int arr0_repet_num1                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB96;

typedef union {
    struct {
        unsigned int arr0_repet_num2                                  :   16              ;    /* 15:0 */
        unsigned int arr0_repet_num3                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB97;

typedef union {
    struct {
        unsigned int arr0_repet_num4                                  :   16              ;    /* 15:0 */
        unsigned int arr0_repet_num5                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB98;

typedef union {
    struct {
        unsigned int arr0_repet_num6                                  :   16              ;    /* 15:0 */
        unsigned int arr0_repet_num7                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB99;

typedef union {
    struct {
        unsigned int arr0_repet_num8                                  :   16              ;    /* 15:0 */
        unsigned int arr0_repet_num9                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB100;

typedef union {
    struct {
        unsigned int arr0_repet_num10                                 :   16              ;    /* 15:0 */
        unsigned int arr0_repet_num11                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB101;

typedef union {
    struct {
        unsigned int arr0_repet_num12                                 :   16              ;    /* 15:0 */
        unsigned int arr0_repet_num13                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB102;

typedef union {
    struct {
        unsigned int arr0_repet_num14                                 :   16              ;    /* 15:0 */
        unsigned int arr0_repet_num15                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB103;

typedef union {
    struct {
        unsigned int arr0_schedu_pool_idx0                            :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_pool_idx1                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB104;

typedef union {
    struct {
        unsigned int arr0_schedu_pool_idx2                            :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_pool_idx3                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB105;

typedef union {
    struct {
        unsigned int arr0_schedu_pool_idx4                            :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_pool_idx5                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB106;

typedef union {
    struct {
        unsigned int arr0_schedu_pool_idx6                            :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_pool_idx7                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB107;

typedef union {
    struct {
        unsigned int arr0_schedu_pool_idx8                            :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_pool_idx9                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB108;

typedef union {
    struct {
        unsigned int arr0_schedu_pool_idx10                           :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_pool_idx11                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB109;

typedef union {
    struct {
        unsigned int arr0_schedu_pool_idx12                           :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_pool_idx13                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB110;

typedef union {
    struct {
        unsigned int arr0_schedu_pool_idx14                           :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_pool_idx15                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB111;

typedef union {
    struct {
        unsigned int arr0_schedu_int_pos0                             :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_int_pos1                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB112;

typedef union {
    struct {
        unsigned int arr0_schedu_int_pos2                             :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_int_pos3                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB113;

typedef union {
    struct {
        unsigned int arr0_schedu_int_pos4                             :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_int_pos5                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB114;

typedef union {
    struct {
        unsigned int arr0_schedu_int_pos6                             :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_int_pos7                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB115;

typedef union {
    struct {
        unsigned int arr0_schedu_int_pos8                             :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_int_pos9                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB116;

typedef union {
    struct {
        unsigned int arr0_schedu_int_pos10                            :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_int_pos11                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB117;

typedef union {
    struct {
        unsigned int arr0_schedu_int_pos12                            :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_int_pos13                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB118;

typedef union {
    struct {
        unsigned int arr0_schedu_int_pos14                            :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_int_pos15                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB119;

typedef union {
    struct {
        unsigned int arr0_schedu_cfg_idx0                             :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_cfg_idx1                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB120;

typedef union {
    struct {
        unsigned int arr0_schedu_cfg_idx2                             :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_cfg_idx3                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB121;

typedef union {
    struct {
        unsigned int arr0_schedu_cfg_idx4                             :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_cfg_idx5                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB122;

typedef union {
    struct {
        unsigned int arr0_schedu_cfg_idx6                             :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_cfg_idx7                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB123;

typedef union {
    struct {
        unsigned int arr0_schedu_cfg_idx8                             :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_cfg_idx9                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB124;

typedef union {
    struct {
        unsigned int arr0_schedu_cfg_idx10                            :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_cfg_idx11                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB125;

typedef union {
    struct {
        unsigned int arr0_schedu_cfg_idx12                            :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_cfg_idx13                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB126;

typedef union {
    struct {
        unsigned int arr0_schedu_cfg_idx14                            :   16              ;    /* 15:0 */
        unsigned int arr0_schedu_cfg_idx15                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB127;

typedef union {
    struct {
        unsigned int arr0_old_dci_type0                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_type1                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB128;

typedef union {
    struct {
        unsigned int arr0_old_dci_type2                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_type3                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB129;

typedef union {
    struct {
        unsigned int arr0_old_dci_type4                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_type5                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB130;

typedef union {
    struct {
        unsigned int arr0_old_dci_type6                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_type7                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB131;

typedef union {
    struct {
        unsigned int arr0_old_dci_type8                               :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_type9                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB132;

typedef union {
    struct {
        unsigned int arr0_old_dci_type10                              :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_type11                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB133;

typedef union {
    struct {
        unsigned int arr0_old_dci_type12                              :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_type13                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB134;

typedef union {
    struct {
        unsigned int arr0_old_dci_type14                              :   16              ;    /* 15:0 */
        unsigned int arr0_old_dci_type15                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB135;

typedef union {
    struct {
        unsigned int arr0_union_dem_array_idx0                        :   16              ;    /* 15:0 */
        unsigned int arr0_union_dem_array_idx1                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB136;

typedef union {
    struct {
        unsigned int arr0_union_dem_array_idx2                        :   16              ;    /* 15:0 */
        unsigned int arr0_union_dem_array_idx3                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB137;

typedef union {
    struct {
        unsigned int arr0_union_dem_array_idx4                        :   16              ;    /* 15:0 */
        unsigned int arr0_union_dem_array_idx5                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB138;

typedef union {
    struct {
        unsigned int arr0_union_dem_array_idx6                        :   16              ;    /* 15:0 */
        unsigned int arr0_union_dem_array_idx7                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB139;

typedef union {
    struct {
        unsigned int arr0_union_dem_array_idx8                        :   16              ;    /* 15:0 */
        unsigned int arr0_union_dem_array_idx9                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB140;

typedef union {
    struct {
        unsigned int arr0_union_dem_array_idx10                       :   16              ;    /* 15:0 */
        unsigned int arr0_union_dem_array_idx11                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB141;

typedef union {
    struct {
        unsigned int arr0_union_dem_array_idx12                       :   16              ;    /* 15:0 */
        unsigned int arr0_union_dem_array_idx13                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB142;

typedef union {
    struct {
        unsigned int arr0_union_dem_array_idx14                       :   16              ;    /* 15:0 */
        unsigned int arr0_union_dem_array_idx15                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB143;

typedef union {
    struct {
        unsigned int arr0_dci_harq_num0                               :   16              ;    /* 15:0 */
        unsigned int arr0_dci_harq_num1                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB144;

typedef union {
    struct {
        unsigned int arr0_dci_harq_num2                               :   16              ;    /* 15:0 */
        unsigned int arr0_dci_harq_num3                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB145;

typedef union {
    struct {
        unsigned int arr0_dci_harq_num4                               :   16              ;    /* 15:0 */
        unsigned int arr0_dci_harq_num5                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB146;

typedef union {
    struct {
        unsigned int arr0_dci_harq_num6                               :   16              ;    /* 15:0 */
        unsigned int arr0_dci_harq_num7                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB147;

typedef union {
    struct {
        unsigned int arr0_dci_harq_num8                               :   16              ;    /* 15:0 */
        unsigned int arr0_dci_harq_num9                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB148;

typedef union {
    struct {
        unsigned int arr0_dci_harq_num10                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_harq_num11                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB149;

typedef union {
    struct {
        unsigned int arr0_dci_harq_num12                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_harq_num13                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB150;

typedef union {
    struct {
        unsigned int arr0_dci_harq_num14                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_harq_num15                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB151;

typedef union {
    struct {
        unsigned int arr0_harq_cfg_idx0                               :   16              ;    /* 15:0 */
        unsigned int arr0_harq_cfg_idx1                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB152;

typedef union {
    struct {
        unsigned int arr0_harq_cfg_idx2                               :   16              ;    /* 15:0 */
        unsigned int arr0_harq_cfg_idx3                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB153;

typedef union {
    struct {
        unsigned int arr0_harq_cfg_idx4                               :   16              ;    /* 15:0 */
        unsigned int arr0_harq_cfg_idx5                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB154;

typedef union {
    struct {
        unsigned int arr0_harq_cfg_idx6                               :   16              ;    /* 15:0 */
        unsigned int arr0_harq_cfg_idx7                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB155;

typedef union {
    struct {
        unsigned int arr0_harq_cfg_idx8                               :   16              ;    /* 15:0 */
        unsigned int arr0_harq_cfg_idx9                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB156;

typedef union {
    struct {
        unsigned int arr0_harq_cfg_idx10                              :   16              ;    /* 15:0 */
        unsigned int arr0_harq_cfg_idx11                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB157;

typedef union {
    struct {
        unsigned int arr0_harq_cfg_idx12                              :   16              ;    /* 15:0 */
        unsigned int arr0_harq_cfg_idx13                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB158;

typedef union {
    struct {
        unsigned int arr0_harq_cfg_idx14                              :   16              ;    /* 15:0 */
        unsigned int arr0_harq_cfg_idx15                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB159;

typedef union {
    struct {
        unsigned int arr0_ddl_delay_cnt0                              :   16              ;    /* 15:0 */
        unsigned int arr0_ddl_delay_cnt1                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB160;

typedef union {
    struct {
        unsigned int arr0_ddl_delay_cnt2                              :   16              ;    /* 15:0 */
        unsigned int arr0_ddl_delay_cnt3                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB161;

typedef union {
    struct {
        unsigned int arr0_ddl_delay_cnt4                              :   16              ;    /* 15:0 */
        unsigned int arr0_ddl_delay_cnt5                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB162;

typedef union {
    struct {
        unsigned int arr0_ddl_delay_cnt6                              :   16              ;    /* 15:0 */
        unsigned int arr0_ddl_delay_cnt7                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB163;

typedef union {
    struct {
        unsigned int arr0_ddl_delay_cnt8                              :   16              ;    /* 15:0 */
        unsigned int arr0_ddl_delay_cnt9                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB164;

typedef union {
    struct {
        unsigned int arr0_ddl_delay_cnt10                             :   16              ;    /* 15:0 */
        unsigned int arr0_ddl_delay_cnt11                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB165;

typedef union {
    struct {
        unsigned int arr0_ddl_delay_cnt12                             :   16              ;    /* 15:0 */
        unsigned int arr0_ddl_delay_cnt13                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB166;

typedef union {
    struct {
        unsigned int arr0_ddl_delay_cnt14                             :   16              ;    /* 15:0 */
        unsigned int arr0_ddl_delay_cnt15                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB167;

typedef union {
    struct {
        unsigned int arr0_old_pds_bitmap0                             :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_bitmap1                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB200;

typedef union {
    struct {
        unsigned int arr0_old_pds_bitmap2                             :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_bitmap3                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB201;

typedef union {
    struct {
        unsigned int arr0_old_pds_bitmap4                             :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_bitmap5                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB202;

typedef union {
    struct {
        unsigned int arr0_old_pds_bitmap6                             :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_bitmap7                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB203;

typedef union {
    struct {
        unsigned int arr0_old_pds_bitmap8                             :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_bitmap9                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB204;

typedef union {
    struct {
        unsigned int arr0_old_pds_bitmap10                            :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_bitmap11                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB205;

typedef union {
    struct {
        unsigned int arr0_old_pds_bitmap12                            :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_bitmap13                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB206;

typedef union {
    struct {
        unsigned int arr0_old_pds_bitmap14                            :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_bitmap15                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB207;

typedef union {
    struct {
        unsigned int arr0_old_pds_symb_start0                         :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_symb_start1                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB208;

typedef union {
    struct {
        unsigned int arr0_old_pds_symb_start2                         :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_symb_start3                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB209;

typedef union {
    struct {
        unsigned int arr0_old_pds_symb_start4                         :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_symb_start5                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB210;

typedef union {
    struct {
        unsigned int arr0_old_pds_symb_start6                         :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_symb_start7                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB211;

typedef union {
    struct {
        unsigned int arr0_old_pds_symb_start8                         :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_symb_start9                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB212;

typedef union {
    struct {
        unsigned int arr0_old_pds_symb_start10                        :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_symb_start11                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB213;

typedef union {
    struct {
        unsigned int arr0_old_pds_symb_start12                        :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_symb_start13                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB214;

typedef union {
    struct {
        unsigned int arr0_old_pds_symb_start14                        :   16              ;    /* 15:0 */
        unsigned int arr0_old_pds_symb_start15                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB215;

typedef union {
    struct {
        unsigned int arr0_pds_symb_start0                             :   16              ;    /* 15:0 */
        unsigned int arr0_pds_symb_start1                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB216;

typedef union {
    struct {
        unsigned int arr0_pds_symb_start2                             :   16              ;    /* 15:0 */
        unsigned int arr0_pds_symb_start3                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB217;

typedef union {
    struct {
        unsigned int arr0_pds_symb_start4                             :   16              ;    /* 15:0 */
        unsigned int arr0_pds_symb_start5                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB218;

typedef union {
    struct {
        unsigned int arr0_pds_symb_start6                             :   16              ;    /* 15:0 */
        unsigned int arr0_pds_symb_start7                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB219;

typedef union {
    struct {
        unsigned int arr0_pds_symb_start8                             :   16              ;    /* 15:0 */
        unsigned int arr0_pds_symb_start9                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB220;

typedef union {
    struct {
        unsigned int arr0_pds_symb_start10                            :   16              ;    /* 15:0 */
        unsigned int arr0_pds_symb_start11                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB221;

typedef union {
    struct {
        unsigned int arr0_pds_symb_start12                            :   16              ;    /* 15:0 */
        unsigned int arr0_pds_symb_start13                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB222;

typedef union {
    struct {
        unsigned int arr0_pds_symb_start14                            :   16              ;    /* 15:0 */
        unsigned int arr0_pds_symb_start15                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB223;

typedef union {
    struct {
        unsigned int arr0_dci_store_idx0                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_store_idx1                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB224;

typedef union {
    struct {
        unsigned int arr0_dci_store_idx2                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_store_idx3                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB225;

typedef union {
    struct {
        unsigned int arr0_dci_store_idx4                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_store_idx5                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB226;

typedef union {
    struct {
        unsigned int arr0_dci_store_idx6                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_store_idx7                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB227;

typedef union {
    struct {
        unsigned int arr0_dci_store_idx8                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_store_idx9                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB228;

typedef union {
    struct {
        unsigned int arr0_dci_store_idx10                             :   16              ;    /* 15:0 */
        unsigned int arr0_dci_store_idx11                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB229;

typedef union {
    struct {
        unsigned int arr0_dci_store_idx12                             :   16              ;    /* 15:0 */
        unsigned int arr0_dci_store_idx13                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB230;

typedef union {
    struct {
        unsigned int arr0_dci_store_idx14                             :   16              ;    /* 15:0 */
        unsigned int arr0_dci_store_idx15                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB231;

typedef union {
    struct {
        unsigned int arr0_dci_prior_idx0                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_prior_idx1                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB232;

typedef union {
    struct {
        unsigned int arr0_dci_prior_idx2                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_prior_idx3                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB233;

typedef union {
    struct {
        unsigned int arr0_dci_prior_idx4                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_prior_idx5                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB234;

typedef union {
    struct {
        unsigned int arr0_dci_prior_idx6                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_prior_idx7                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB235;

typedef union {
    struct {
        unsigned int arr0_dci_prior_idx8                              :   16              ;    /* 15:0 */
        unsigned int arr0_dci_prior_idx9                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB236;

typedef union {
    struct {
        unsigned int arr0_dci_prior_idx10                             :   16              ;    /* 15:0 */
        unsigned int arr0_dci_prior_idx11                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB237;

typedef union {
    struct {
        unsigned int arr0_dci_prior_idx12                             :   16              ;    /* 15:0 */
        unsigned int arr0_dci_prior_idx13                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB238;

typedef union {
    struct {
        unsigned int arr0_dci_prior_idx14                             :   16              ;    /* 15:0 */
        unsigned int arr0_dci_prior_idx15                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB239;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB0                       om_data0;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB1                       om_data1;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB2                       om_data2;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB3                       om_data3;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB4                       om_data4;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB5                       om_data5;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB6                       om_data6;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB7                       om_data7;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB8                       om_data8;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB9                       om_data9;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB10                      om_data10;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB11                      om_data11;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB12                      om_data12;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB13                      om_data13;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB14                      om_data14;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB15                      om_data15;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB16                      om_data16;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB17                      om_data17;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB18                      om_data18;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB19                      om_data19;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB20                      om_data20;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB21                      om_data21;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB22                      om_data22;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB23                      om_data23;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB24                      om_data24;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB25                      om_data25;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB26                      om_data26;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB27                      om_data27;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB28                      om_data28;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB29                      om_data29;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB30                      om_data30;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB31                      om_data31;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB32                      om_data32;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB33                      om_data33;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB34                      om_data34;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB35                      om_data35;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB36                      om_data36;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB37                      om_data37;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB38                      om_data38;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB39                      om_data39;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB40                      om_data40;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB41                      om_data41;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB42                      om_data42;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB43                      om_data43;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB44                      om_data44;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB45                      om_data45;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB46                      om_data46;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB47                      om_data47;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB48                      om_data48;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB49                      om_data49;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB50                      om_data50;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB51                      om_data51;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB52                      om_data52;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB53                      om_data53;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB54                      om_data54;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB55                      om_data55;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB56                      om_data56;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB57                      om_data57;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB58                      om_data58;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB59                      om_data59;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB60                      om_data60;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB61                      om_data61;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB62                      om_data62;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB63                      om_data63;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB64                      om_data64;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB65                      om_data65;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB66                      om_data66;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB67                      om_data67;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB68                      om_data68;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB69                      om_data69;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB70                      om_data70;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB71                      om_data71;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB72                      om_data72;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB73                      om_data73;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB74                      om_data74;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB75                      om_data75;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB76                      om_data76;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB77                      om_data77;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB78                      om_data78;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB79                      om_data79;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB80                      om_data80;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB81                      om_data81;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB82                      om_data82;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB83                      om_data83;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB84                      om_data84;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB85                      om_data85;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB86                      om_data86;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB87                      om_data87;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB88                      om_data88;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB89                      om_data89;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB90                      om_data90;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB91                      om_data91;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB92                      om_data92;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB93                      om_data93;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB94                      om_data94;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB95                      om_data95;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB96                      om_data96;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB97                      om_data97;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB98                      om_data98;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB99                      om_data99;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB100                     om_data100;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB101                     om_data101;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB102                     om_data102;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB103                     om_data103;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB104                     om_data104;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB105                     om_data105;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB106                     om_data106;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB107                     om_data107;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB108                     om_data108;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB109                     om_data109;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB110                     om_data110;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB111                     om_data111;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB112                     om_data112;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB113                     om_data113;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB114                     om_data114;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB115                     om_data115;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB116                     om_data116;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB117                     om_data117;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB118                     om_data118;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB119                     om_data119;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB120                     om_data120;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB121                     om_data121;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB122                     om_data122;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB123                     om_data123;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB124                     om_data124;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB125                     om_data125;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB126                     om_data126;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB127                     om_data127;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB128                     om_data128;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB129                     om_data129;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB130                     om_data130;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB131                     om_data131;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB132                     om_data132;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB133                     om_data133;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB134                     om_data134;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB135                     om_data135;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB136                     om_data136;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB137                     om_data137;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB138                     om_data138;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB139                     om_data139;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB140                     om_data140;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB141                     om_data141;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB142                     om_data142;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB143                     om_data143;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB144                     om_data144;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB145                     om_data145;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB146                     om_data146;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB147                     om_data147;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB148                     om_data148;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB149                     om_data149;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB150                     om_data150;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB151                     om_data151;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB152                     om_data152;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB153                     om_data153;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB154                     om_data154;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB155                     om_data155;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB156                     om_data156;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB157                     om_data157;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB158                     om_data158;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB159                     om_data159;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB160                     om_data160;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB161                     om_data161;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB162                     om_data162;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB163                     om_data163;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB164                     om_data164;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB165                     om_data165;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB166                     om_data166;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB167                     om_data167;
    unsigned int                                                      arr0_old_dci_data0_0;
    unsigned int                                                      arr0_old_dci_data0_1;
    unsigned int                                                      arr0_old_dci_data0_2;
    unsigned int                                                      arr0_old_dci_data0_3;
    unsigned int                                                      arr0_old_dci_data0_4;
    unsigned int                                                      arr0_old_dci_data0_5;
    unsigned int                                                      arr0_old_dci_data0_6;
    unsigned int                                                      arr0_old_dci_data0_7;
    unsigned int                                                      arr0_old_dci_data0_8;
    unsigned int                                                      arr0_old_dci_data0_9;
    unsigned int                                                      arr0_old_dci_data0_10;
    unsigned int                                                      arr0_old_dci_data0_11;
    unsigned int                                                      arr0_old_dci_data0_12;
    unsigned int                                                      arr0_old_dci_data0_13;
    unsigned int                                                      arr0_old_dci_data0_14;
    unsigned int                                                      arr0_old_dci_data0_15;
    unsigned int                                                      arr0_old_dci_data1_0;
    unsigned int                                                      arr0_old_dci_data1_1;
    unsigned int                                                      arr0_old_dci_data1_2;
    unsigned int                                                      arr0_old_dci_data1_3;
    unsigned int                                                      arr0_old_dci_data1_4;
    unsigned int                                                      arr0_old_dci_data1_5;
    unsigned int                                                      arr0_old_dci_data1_6;
    unsigned int                                                      arr0_old_dci_data1_7;
    unsigned int                                                      arr0_old_dci_data1_8;
    unsigned int                                                      arr0_old_dci_data1_9;
    unsigned int                                                      arr0_old_dci_data1_10;
    unsigned int                                                      arr0_old_dci_data1_11;
    unsigned int                                                      arr0_old_dci_data1_12;
    unsigned int                                                      arr0_old_dci_data1_13;
    unsigned int                                                      arr0_old_dci_data1_14;
    unsigned int                                                      arr0_old_dci_data1_15;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB200                     om_data200;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB201                     om_data201;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB202                     om_data202;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB203                     om_data203;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB204                     om_data204;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB205                     om_data205;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB206                     om_data206;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB207                     om_data207;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB208                     om_data208;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB209                     om_data209;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB210                     om_data210;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB211                     om_data211;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB212                     om_data212;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB213                     om_data213;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB214                     om_data214;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB215                     om_data215;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB216                     om_data216;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB217                     om_data217;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB218                     om_data218;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB219                     om_data219;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB220                     om_data220;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB221                     om_data221;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB222                     om_data222;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB223                     om_data223;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB224                     om_data224;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB225                     om_data225;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB226                     om_data226;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB227                     om_data227;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB228                     om_data228;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB229                     om_data229;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB230                     om_data230;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB231                     om_data231;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB232                     om_data232;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB233                     om_data233;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB234                     om_data234;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB235                     om_data235;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB236                     om_data236;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB237                     om_data237;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB238                     om_data238;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB239                     om_data239;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB0                       om_data0;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB1                       om_data1;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB2                       om_data2;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB3                       om_data3;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB4                       om_data4;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB5                       om_data5;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB6                       om_data6;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB7                       om_data7;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB8                       om_data8;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB9                       om_data9;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB10                      om_data10;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB11                      om_data11;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB12                      om_data12;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB13                      om_data13;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB14                      om_data14;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB15                      om_data15;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB16                      om_data16;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB17                      om_data17;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB18                      om_data18;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB19                      om_data19;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB20                      om_data20;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB21                      om_data21;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB22                      om_data22;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB23                      om_data23;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB24                      om_data24;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB25                      om_data25;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB26                      om_data26;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB27                      om_data27;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB28                      om_data28;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB29                      om_data29;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB30                      om_data30;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB31                      om_data31;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB32                      om_data32;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB33                      om_data33;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB34                      om_data34;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB35                      om_data35;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB36                      om_data36;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB37                      om_data37;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB38                      om_data38;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB39                      om_data39;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB40                      om_data40;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB41                      om_data41;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB42                      om_data42;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB43                      om_data43;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB44                      om_data44;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB45                      om_data45;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB46                      om_data46;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB47                      om_data47;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB48                      om_data48;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB49                      om_data49;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB50                      om_data50;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB51                      om_data51;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB52                      om_data52;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB53                      om_data53;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB54                      om_data54;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB55                      om_data55;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB56                      om_data56;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB57                      om_data57;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB58                      om_data58;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB59                      om_data59;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB60                      om_data60;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB61                      om_data61;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB62                      om_data62;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB63                      om_data63;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB64                      om_data64;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB65                      om_data65;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB66                      om_data66;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB67                      om_data67;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB68                      om_data68;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB69                      om_data69;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB70                      om_data70;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB71                      om_data71;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB72                      om_data72;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB73                      om_data73;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB74                      om_data74;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB75                      om_data75;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB76                      om_data76;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB77                      om_data77;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB78                      om_data78;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB79                      om_data79;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB80                      om_data80;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB81                      om_data81;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB82                      om_data82;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB83                      om_data83;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB84                      om_data84;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB85                      om_data85;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB86                      om_data86;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB87                      om_data87;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB88                      om_data88;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB89                      om_data89;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB90                      om_data90;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB91                      om_data91;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB92                      om_data92;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB93                      om_data93;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB94                      om_data94;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB95                      om_data95;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB96                      om_data96;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB97                      om_data97;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB98                      om_data98;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB99                      om_data99;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB100                     om_data100;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB101                     om_data101;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB102                     om_data102;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB103                     om_data103;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB104                     om_data104;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB105                     om_data105;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB106                     om_data106;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB107                     om_data107;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB108                     om_data108;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB109                     om_data109;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB110                     om_data110;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB111                     om_data111;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB112                     om_data112;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB113                     om_data113;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB114                     om_data114;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB115                     om_data115;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB116                     om_data116;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB117                     om_data117;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB118                     om_data118;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB119                     om_data119;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB120                     om_data120;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB121                     om_data121;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB122                     om_data122;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB123                     om_data123;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB124                     om_data124;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB125                     om_data125;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB126                     om_data126;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB127                     om_data127;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB128                     om_data128;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB129                     om_data129;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB130                     om_data130;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB131                     om_data131;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB132                     om_data132;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB133                     om_data133;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB134                     om_data134;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB135                     om_data135;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB136                     om_data136;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB137                     om_data137;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB138                     om_data138;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB139                     om_data139;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB140                     om_data140;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB141                     om_data141;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB142                     om_data142;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB143                     om_data143;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB144                     om_data144;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB145                     om_data145;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB146                     om_data146;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB147                     om_data147;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB148                     om_data148;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB149                     om_data149;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB150                     om_data150;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB151                     om_data151;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB152                     om_data152;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB153                     om_data153;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB154                     om_data154;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB155                     om_data155;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB156                     om_data156;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB157                     om_data157;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB158                     om_data158;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB159                     om_data159;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB160                     om_data160;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB161                     om_data161;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB162                     om_data162;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB163                     om_data163;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB164                     om_data164;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB165                     om_data165;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB166                     om_data166;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB167                     om_data167;
    unsigned int                                                      arr0_old_dci_data0_0;
    unsigned int                                                      arr0_old_dci_data0_1;
    unsigned int                                                      arr0_old_dci_data0_2;
    unsigned int                                                      arr0_old_dci_data0_3;
    unsigned int                                                      arr0_old_dci_data0_4;
    unsigned int                                                      arr0_old_dci_data0_5;
    unsigned int                                                      arr0_old_dci_data0_6;
    unsigned int                                                      arr0_old_dci_data0_7;
    unsigned int                                                      arr0_old_dci_data0_8;
    unsigned int                                                      arr0_old_dci_data0_9;
    unsigned int                                                      arr0_old_dci_data0_10;
    unsigned int                                                      arr0_old_dci_data0_11;
    unsigned int                                                      arr0_old_dci_data0_12;
    unsigned int                                                      arr0_old_dci_data0_13;
    unsigned int                                                      arr0_old_dci_data0_14;
    unsigned int                                                      arr0_old_dci_data0_15;
    unsigned int                                                      arr0_old_dci_data1_0;
    unsigned int                                                      arr0_old_dci_data1_1;
    unsigned int                                                      arr0_old_dci_data1_2;
    unsigned int                                                      arr0_old_dci_data1_3;
    unsigned int                                                      arr0_old_dci_data1_4;
    unsigned int                                                      arr0_old_dci_data1_5;
    unsigned int                                                      arr0_old_dci_data1_6;
    unsigned int                                                      arr0_old_dci_data1_7;
    unsigned int                                                      arr0_old_dci_data1_8;
    unsigned int                                                      arr0_old_dci_data1_9;
    unsigned int                                                      arr0_old_dci_data1_10;
    unsigned int                                                      arr0_old_dci_data1_11;
    unsigned int                                                      arr0_old_dci_data1_12;
    unsigned int                                                      arr0_old_dci_data1_13;
    unsigned int                                                      arr0_old_dci_data1_14;
    unsigned int                                                      arr0_old_dci_data1_15;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB200                     om_data200;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB201                     om_data201;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB202                     om_data202;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB203                     om_data203;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB204                     om_data204;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB205                     om_data205;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB206                     om_data206;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB207                     om_data207;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB208                     om_data208;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB209                     om_data209;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB210                     om_data210;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB211                     om_data211;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB212                     om_data212;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB213                     om_data213;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB214                     om_data214;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB215                     om_data215;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB216                     om_data216;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB217                     om_data217;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB218                     om_data218;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB219                     om_data219;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB220                     om_data220;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB221                     om_data221;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB222                     om_data222;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB223                     om_data223;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB224                     om_data224;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB225                     om_data225;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB226                     om_data226;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB227                     om_data227;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB228                     om_data228;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB229                     om_data229;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB230                     om_data230;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB231                     om_data231;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB232                     om_data232;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB233                     om_data233;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB234                     om_data234;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB235                     om_data235;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB236                     om_data236;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB237                     om_data237;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB238                     om_data238;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_SUB239                     om_data239;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY0_BBP_MC;

typedef union {
    struct {
        unsigned int arr1_old_cfg_idx0                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_cfg_idx1                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB0;

typedef union {
    struct {
        unsigned int arr1_old_cfg_idx2                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_cfg_idx3                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB1;

typedef union {
    struct {
        unsigned int arr1_old_cfg_idx4                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_cfg_idx5                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB2;

typedef union {
    struct {
        unsigned int arr1_old_cfg_idx6                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_cfg_idx7                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB3;

typedef union {
    struct {
        unsigned int arr1_old_cfg_idx8                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_cfg_idx9                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB4;

typedef union {
    struct {
        unsigned int arr1_old_cfg_idx10                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_cfg_idx11                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB5;

typedef union {
    struct {
        unsigned int arr1_old_cfg_idx12                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_cfg_idx13                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB6;

typedef union {
    struct {
        unsigned int arr1_old_cfg_idx14                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_cfg_idx15                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB7;

typedef union {
    struct {
        unsigned int arr1_old_dci_llr0                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_llr1                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB8;

typedef union {
    struct {
        unsigned int arr1_old_dci_llr2                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_llr3                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB9;

typedef union {
    struct {
        unsigned int arr1_old_dci_llr4                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_llr5                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB10;

typedef union {
    struct {
        unsigned int arr1_old_dci_llr6                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_llr7                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB11;

typedef union {
    struct {
        unsigned int arr1_old_dci_llr8                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_llr9                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB12;

typedef union {
    struct {
        unsigned int arr1_old_dci_llr10                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_llr11                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB13;

typedef union {
    struct {
        unsigned int arr1_old_dci_llr12                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_llr13                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB14;

typedef union {
    struct {
        unsigned int arr1_old_dci_llr14                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_llr15                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB15;

typedef union {
    struct {
        unsigned int arr1_old_hed0                                    :   16              ;    /* 15:0 */
        unsigned int arr1_old_hed1                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB16;

typedef union {
    struct {
        unsigned int arr1_old_hed2                                    :   16              ;    /* 15:0 */
        unsigned int arr1_old_hed3                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB17;

typedef union {
    struct {
        unsigned int arr1_old_hed4                                    :   16              ;    /* 15:0 */
        unsigned int arr1_old_hed5                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB18;

typedef union {
    struct {
        unsigned int arr1_old_hed6                                    :   16              ;    /* 15:0 */
        unsigned int arr1_old_hed7                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB19;

typedef union {
    struct {
        unsigned int arr1_old_hed8                                    :   16              ;    /* 15:0 */
        unsigned int arr1_old_hed9                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB20;

typedef union {
    struct {
        unsigned int arr1_old_hed10                                   :   16              ;    /* 15:0 */
        unsigned int arr1_old_hed11                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB21;

typedef union {
    struct {
        unsigned int arr1_old_hed12                                   :   16              ;    /* 15:0 */
        unsigned int arr1_old_hed13                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB22;

typedef union {
    struct {
        unsigned int arr1_old_hed14                                   :   16              ;    /* 15:0 */
        unsigned int arr1_old_hed15                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB23;

typedef union {
    struct {
        unsigned int arr1_old_pds_sfm0                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_sfm1                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB24;

typedef union {
    struct {
        unsigned int arr1_old_pds_sfm2                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_sfm3                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB25;

typedef union {
    struct {
        unsigned int arr1_old_pds_sfm4                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_sfm5                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB26;

typedef union {
    struct {
        unsigned int arr1_old_pds_sfm6                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_sfm7                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB27;

typedef union {
    struct {
        unsigned int arr1_old_pds_sfm8                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_sfm9                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB28;

typedef union {
    struct {
        unsigned int arr1_old_pds_sfm10                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_sfm11                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB29;

typedef union {
    struct {
        unsigned int arr1_old_pds_sfm12                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_sfm13                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB30;

typedef union {
    struct {
        unsigned int arr1_old_pds_sfm14                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_sfm15                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB31;

typedef union {
    struct {
        unsigned int arr1_old_pds_slot0                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_slot1                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB32;

typedef union {
    struct {
        unsigned int arr1_old_pds_slot2                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_slot3                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB33;

typedef union {
    struct {
        unsigned int arr1_old_pds_slot4                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_slot5                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB34;

typedef union {
    struct {
        unsigned int arr1_old_pds_slot6                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_slot7                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB35;

typedef union {
    struct {
        unsigned int arr1_old_pds_slot8                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_slot9                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB36;

typedef union {
    struct {
        unsigned int arr1_old_pds_slot10                              :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_slot11                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB37;

typedef union {
    struct {
        unsigned int arr1_old_pds_slot12                              :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_slot13                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB38;

typedef union {
    struct {
        unsigned int arr1_old_pds_slot14                              :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_slot15                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB39;

typedef union {
    struct {
        unsigned int arr1_old_pdc_sfm0                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_sfm1                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB40;

typedef union {
    struct {
        unsigned int arr1_old_pdc_sfm2                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_sfm3                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB41;

typedef union {
    struct {
        unsigned int arr1_old_pdc_sfm4                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_sfm5                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB42;

typedef union {
    struct {
        unsigned int arr1_old_pdc_sfm6                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_sfm7                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB43;

typedef union {
    struct {
        unsigned int arr1_old_pdc_sfm8                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_sfm9                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB44;

typedef union {
    struct {
        unsigned int arr1_old_pdc_sfm10                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_sfm11                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB45;

typedef union {
    struct {
        unsigned int arr1_old_pdc_sfm12                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_sfm13                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB46;

typedef union {
    struct {
        unsigned int arr1_old_pdc_sfm14                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_sfm15                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB47;

typedef union {
    struct {
        unsigned int arr1_old_pdc_slot0                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_slot1                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB48;

typedef union {
    struct {
        unsigned int arr1_old_pdc_slot2                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_slot3                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB49;

typedef union {
    struct {
        unsigned int arr1_old_pdc_slot4                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_slot5                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB50;

typedef union {
    struct {
        unsigned int arr1_old_pdc_slot6                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_slot7                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB51;

typedef union {
    struct {
        unsigned int arr1_old_pdc_slot8                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_slot9                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB52;

typedef union {
    struct {
        unsigned int arr1_old_pdc_slot10                              :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_slot11                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB53;

typedef union {
    struct {
        unsigned int arr1_old_pdc_slot12                              :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_slot13                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB54;

typedef union {
    struct {
        unsigned int arr1_old_pdc_slot14                              :   16              ;    /* 15:0 */
        unsigned int arr1_old_pdc_slot15                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB55;

typedef union {
    struct {
        unsigned int arr1_old_ch_type0                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_ch_type1                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB56;

typedef union {
    struct {
        unsigned int arr1_old_ch_type2                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_ch_type3                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB57;

typedef union {
    struct {
        unsigned int arr1_old_ch_type4                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_ch_type5                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB58;

typedef union {
    struct {
        unsigned int arr1_old_ch_type6                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_ch_type7                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB59;

typedef union {
    struct {
        unsigned int arr1_old_ch_type8                                :   16              ;    /* 15:0 */
        unsigned int arr1_old_ch_type9                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB60;

typedef union {
    struct {
        unsigned int arr1_old_ch_type10                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_ch_type11                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB61;

typedef union {
    struct {
        unsigned int arr1_old_ch_type12                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_ch_type13                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB62;

typedef union {
    struct {
        unsigned int arr1_old_ch_type14                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_ch_type15                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB63;

typedef union {
    struct {
        unsigned int arr1_r_idx0                                      :   16              ;    /* 15:0 */
        unsigned int arr1_r_idx1                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB64;

typedef union {
    struct {
        unsigned int arr1_r_idx2                                      :   16              ;    /* 15:0 */
        unsigned int arr1_r_idx3                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB65;

typedef union {
    struct {
        unsigned int arr1_r_idx4                                      :   16              ;    /* 15:0 */
        unsigned int arr1_r_idx5                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB66;

typedef union {
    struct {
        unsigned int arr1_r_idx6                                      :   16              ;    /* 15:0 */
        unsigned int arr1_r_idx7                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB67;

typedef union {
    struct {
        unsigned int arr1_r_idx8                                      :   16              ;    /* 15:0 */
        unsigned int arr1_r_idx9                                      :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB68;

typedef union {
    struct {
        unsigned int arr1_r_idx10                                     :   16              ;    /* 15:0 */
        unsigned int arr1_r_idx11                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB69;

typedef union {
    struct {
        unsigned int arr1_r_idx12                                     :   16              ;    /* 15:0 */
        unsigned int arr1_r_idx13                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB70;

typedef union {
    struct {
        unsigned int arr1_r_idx14                                     :   16              ;    /* 15:0 */
        unsigned int arr1_r_idx15                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB71;

typedef union {
    struct {
        unsigned int arr1_bwp_id0                                     :   16              ;    /* 15:0 */
        unsigned int arr1_bwp_id1                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB72;

typedef union {
    struct {
        unsigned int arr1_bwp_id2                                     :   16              ;    /* 15:0 */
        unsigned int arr1_bwp_id3                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB73;

typedef union {
    struct {
        unsigned int arr1_bwp_id4                                     :   16              ;    /* 15:0 */
        unsigned int arr1_bwp_id5                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB74;

typedef union {
    struct {
        unsigned int arr1_bwp_id6                                     :   16              ;    /* 15:0 */
        unsigned int arr1_bwp_id7                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB75;

typedef union {
    struct {
        unsigned int arr1_bwp_id8                                     :   16              ;    /* 15:0 */
        unsigned int arr1_bwp_id9                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB76;

typedef union {
    struct {
        unsigned int arr1_bwp_id10                                    :   16              ;    /* 15:0 */
        unsigned int arr1_bwp_id11                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB77;

typedef union {
    struct {
        unsigned int arr1_bwp_id12                                    :   16              ;    /* 15:0 */
        unsigned int arr1_bwp_id13                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB78;

typedef union {
    struct {
        unsigned int arr1_bwp_id14                                    :   16              ;    /* 15:0 */
        unsigned int arr1_bwp_id15                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB79;

typedef union {
    struct {
        unsigned int arr1_store_dl_dci_idx0                           :   16              ;    /* 15:0 */
        unsigned int arr1_store_dl_dci_idx1                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB80;

typedef union {
    struct {
        unsigned int arr1_store_dl_dci_idx2                           :   16              ;    /* 15:0 */
        unsigned int arr1_store_dl_dci_idx3                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB81;

typedef union {
    struct {
        unsigned int arr1_store_dl_dci_idx4                           :   16              ;    /* 15:0 */
        unsigned int arr1_store_dl_dci_idx5                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB82;

typedef union {
    struct {
        unsigned int arr1_store_dl_dci_idx6                           :   16              ;    /* 15:0 */
        unsigned int arr1_store_dl_dci_idx7                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB83;

typedef union {
    struct {
        unsigned int arr1_store_dl_dci_idx8                           :   16              ;    /* 15:0 */
        unsigned int arr1_store_dl_dci_idx9                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB84;

typedef union {
    struct {
        unsigned int arr1_store_dl_dci_idx10                          :   16              ;    /* 15:0 */
        unsigned int arr1_store_dl_dci_idx11                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB85;

typedef union {
    struct {
        unsigned int arr1_store_dl_dci_idx12                          :   16              ;    /* 15:0 */
        unsigned int arr1_store_dl_dci_idx13                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB86;

typedef union {
    struct {
        unsigned int arr1_store_dl_dci_idx14                          :   16              ;    /* 15:0 */
        unsigned int arr1_store_dl_dci_idx15                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB87;

typedef union {
    struct {
        unsigned int arr1_k0_value0                                   :   16              ;    /* 15:0 */
        unsigned int arr1_k0_value1                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB88;

typedef union {
    struct {
        unsigned int arr1_k0_value2                                   :   16              ;    /* 15:0 */
        unsigned int arr1_k0_value3                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB89;

typedef union {
    struct {
        unsigned int arr1_k0_value4                                   :   16              ;    /* 15:0 */
        unsigned int arr1_k0_value5                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB90;

typedef union {
    struct {
        unsigned int arr1_k0_value6                                   :   16              ;    /* 15:0 */
        unsigned int arr1_k0_value7                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB91;

typedef union {
    struct {
        unsigned int arr1_k0_value8                                   :   16              ;    /* 15:0 */
        unsigned int arr1_k0_value9                                   :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB92;

typedef union {
    struct {
        unsigned int arr1_k0_value10                                  :   16              ;    /* 15:0 */
        unsigned int arr1_k0_value11                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB93;

typedef union {
    struct {
        unsigned int arr1_k0_value12                                  :   16              ;    /* 15:0 */
        unsigned int arr1_k0_value13                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB94;

typedef union {
    struct {
        unsigned int arr1_k0_value14                                  :   16              ;    /* 15:0 */
        unsigned int arr1_k0_value15                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB95;

typedef union {
    struct {
        unsigned int arr1_repet_num0                                  :   16              ;    /* 15:0 */
        unsigned int arr1_repet_num1                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB96;

typedef union {
    struct {
        unsigned int arr1_repet_num2                                  :   16              ;    /* 15:0 */
        unsigned int arr1_repet_num3                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB97;

typedef union {
    struct {
        unsigned int arr1_repet_num4                                  :   16              ;    /* 15:0 */
        unsigned int arr1_repet_num5                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB98;

typedef union {
    struct {
        unsigned int arr1_repet_num6                                  :   16              ;    /* 15:0 */
        unsigned int arr1_repet_num7                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB99;

typedef union {
    struct {
        unsigned int arr1_repet_num8                                  :   16              ;    /* 15:0 */
        unsigned int arr1_repet_num9                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB100;

typedef union {
    struct {
        unsigned int arr1_repet_num10                                 :   16              ;    /* 15:0 */
        unsigned int arr1_repet_num11                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB101;

typedef union {
    struct {
        unsigned int arr1_repet_num12                                 :   16              ;    /* 15:0 */
        unsigned int arr1_repet_num13                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB102;

typedef union {
    struct {
        unsigned int arr1_repet_num14                                 :   16              ;    /* 15:0 */
        unsigned int arr1_repet_num15                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB103;

typedef union {
    struct {
        unsigned int arr1_schedu_pool_idx0                            :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_pool_idx1                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB104;

typedef union {
    struct {
        unsigned int arr1_schedu_pool_idx2                            :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_pool_idx3                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB105;

typedef union {
    struct {
        unsigned int arr1_schedu_pool_idx4                            :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_pool_idx5                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB106;

typedef union {
    struct {
        unsigned int arr1_schedu_pool_idx6                            :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_pool_idx7                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB107;

typedef union {
    struct {
        unsigned int arr1_schedu_pool_idx8                            :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_pool_idx9                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB108;

typedef union {
    struct {
        unsigned int arr1_schedu_pool_idx10                           :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_pool_idx11                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB109;

typedef union {
    struct {
        unsigned int arr1_schedu_pool_idx12                           :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_pool_idx13                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB110;

typedef union {
    struct {
        unsigned int arr1_schedu_pool_idx14                           :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_pool_idx15                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB111;

typedef union {
    struct {
        unsigned int arr1_schedu_int_pos0                             :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_int_pos1                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB112;

typedef union {
    struct {
        unsigned int arr1_schedu_int_pos2                             :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_int_pos3                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB113;

typedef union {
    struct {
        unsigned int arr1_schedu_int_pos4                             :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_int_pos5                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB114;

typedef union {
    struct {
        unsigned int arr1_schedu_int_pos6                             :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_int_pos7                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB115;

typedef union {
    struct {
        unsigned int arr1_schedu_int_pos8                             :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_int_pos9                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB116;

typedef union {
    struct {
        unsigned int arr1_schedu_int_pos10                            :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_int_pos11                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB117;

typedef union {
    struct {
        unsigned int arr1_schedu_int_pos12                            :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_int_pos13                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB118;

typedef union {
    struct {
        unsigned int arr1_schedu_int_pos14                            :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_int_pos15                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB119;

typedef union {
    struct {
        unsigned int arr1_schedu_cfg_idx0                             :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_cfg_idx1                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB120;

typedef union {
    struct {
        unsigned int arr1_schedu_cfg_idx2                             :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_cfg_idx3                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB121;

typedef union {
    struct {
        unsigned int arr1_schedu_cfg_idx4                             :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_cfg_idx5                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB122;

typedef union {
    struct {
        unsigned int arr1_schedu_cfg_idx6                             :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_cfg_idx7                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB123;

typedef union {
    struct {
        unsigned int arr1_schedu_cfg_idx8                             :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_cfg_idx9                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB124;

typedef union {
    struct {
        unsigned int arr1_schedu_cfg_idx10                            :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_cfg_idx11                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB125;

typedef union {
    struct {
        unsigned int arr1_schedu_cfg_idx12                            :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_cfg_idx13                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB126;

typedef union {
    struct {
        unsigned int arr1_schedu_cfg_idx14                            :   16              ;    /* 15:0 */
        unsigned int arr1_schedu_cfg_idx15                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB127;

typedef union {
    struct {
        unsigned int arr1_old_dci_type0                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_type1                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB128;

typedef union {
    struct {
        unsigned int arr1_old_dci_type2                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_type3                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB129;

typedef union {
    struct {
        unsigned int arr1_old_dci_type4                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_type5                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB130;

typedef union {
    struct {
        unsigned int arr1_old_dci_type6                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_type7                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB131;

typedef union {
    struct {
        unsigned int arr1_old_dci_type8                               :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_type9                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB132;

typedef union {
    struct {
        unsigned int arr1_old_dci_type10                              :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_type11                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB133;

typedef union {
    struct {
        unsigned int arr1_old_dci_type12                              :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_type13                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB134;

typedef union {
    struct {
        unsigned int arr1_old_dci_type14                              :   16              ;    /* 15:0 */
        unsigned int arr1_old_dci_type15                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB135;

typedef union {
    struct {
        unsigned int arr1_union_dem_array_idx0                        :   16              ;    /* 15:0 */
        unsigned int arr1_union_dem_array_idx1                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB136;

typedef union {
    struct {
        unsigned int arr1_union_dem_array_idx2                        :   16              ;    /* 15:0 */
        unsigned int arr1_union_dem_array_idx3                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB137;

typedef union {
    struct {
        unsigned int arr1_union_dem_array_idx4                        :   16              ;    /* 15:0 */
        unsigned int arr1_union_dem_array_idx5                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB138;

typedef union {
    struct {
        unsigned int arr1_union_dem_array_idx6                        :   16              ;    /* 15:0 */
        unsigned int arr1_union_dem_array_idx7                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB139;

typedef union {
    struct {
        unsigned int arr1_union_dem_array_idx8                        :   16              ;    /* 15:0 */
        unsigned int arr1_union_dem_array_idx9                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB140;

typedef union {
    struct {
        unsigned int arr1_union_dem_array_idx10                       :   16              ;    /* 15:0 */
        unsigned int arr1_union_dem_array_idx11                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB141;

typedef union {
    struct {
        unsigned int arr1_union_dem_array_idx12                       :   16              ;    /* 15:0 */
        unsigned int arr1_union_dem_array_idx13                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB142;

typedef union {
    struct {
        unsigned int arr1_union_dem_array_idx14                       :   16              ;    /* 15:0 */
        unsigned int arr1_union_dem_array_idx15                       :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB143;

typedef union {
    struct {
        unsigned int arr1_dci_harq_num0                               :   16              ;    /* 15:0 */
        unsigned int arr1_dci_harq_num1                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB144;

typedef union {
    struct {
        unsigned int arr1_dci_harq_num2                               :   16              ;    /* 15:0 */
        unsigned int arr1_dci_harq_num3                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB145;

typedef union {
    struct {
        unsigned int arr1_dci_harq_num4                               :   16              ;    /* 15:0 */
        unsigned int arr1_dci_harq_num5                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB146;

typedef union {
    struct {
        unsigned int arr1_dci_harq_num6                               :   16              ;    /* 15:0 */
        unsigned int arr1_dci_harq_num7                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB147;

typedef union {
    struct {
        unsigned int arr1_dci_harq_num8                               :   16              ;    /* 15:0 */
        unsigned int arr1_dci_harq_num9                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB148;

typedef union {
    struct {
        unsigned int arr1_dci_harq_num10                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_harq_num11                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB149;

typedef union {
    struct {
        unsigned int arr1_dci_harq_num12                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_harq_num13                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB150;

typedef union {
    struct {
        unsigned int arr1_dci_harq_num14                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_harq_num15                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB151;

typedef union {
    struct {
        unsigned int arr1_harq_cfg_idx0                               :   16              ;    /* 15:0 */
        unsigned int arr1_harq_cfg_idx1                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB152;

typedef union {
    struct {
        unsigned int arr1_harq_cfg_idx2                               :   16              ;    /* 15:0 */
        unsigned int arr1_harq_cfg_idx3                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB153;

typedef union {
    struct {
        unsigned int arr1_harq_cfg_idx4                               :   16              ;    /* 15:0 */
        unsigned int arr1_harq_cfg_idx5                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB154;

typedef union {
    struct {
        unsigned int arr1_harq_cfg_idx6                               :   16              ;    /* 15:0 */
        unsigned int arr1_harq_cfg_idx7                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB155;

typedef union {
    struct {
        unsigned int arr1_harq_cfg_idx8                               :   16              ;    /* 15:0 */
        unsigned int arr1_harq_cfg_idx9                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB156;

typedef union {
    struct {
        unsigned int arr1_harq_cfg_idx10                              :   16              ;    /* 15:0 */
        unsigned int arr1_harq_cfg_idx11                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB157;

typedef union {
    struct {
        unsigned int arr1_harq_cfg_idx12                              :   16              ;    /* 15:0 */
        unsigned int arr1_harq_cfg_idx13                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB158;

typedef union {
    struct {
        unsigned int arr1_harq_cfg_idx14                              :   16              ;    /* 15:0 */
        unsigned int arr1_harq_cfg_idx15                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB159;

typedef union {
    struct {
        unsigned int arr1_ddl_delay_cnt0                              :   16              ;    /* 15:0 */
        unsigned int arr1_ddl_delay_cnt1                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB160;

typedef union {
    struct {
        unsigned int arr1_ddl_delay_cnt2                              :   16              ;    /* 15:0 */
        unsigned int arr1_ddl_delay_cnt3                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB161;

typedef union {
    struct {
        unsigned int arr1_ddl_delay_cnt4                              :   16              ;    /* 15:0 */
        unsigned int arr1_ddl_delay_cnt5                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB162;

typedef union {
    struct {
        unsigned int arr1_ddl_delay_cnt6                              :   16              ;    /* 15:0 */
        unsigned int arr1_ddl_delay_cnt7                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB163;

typedef union {
    struct {
        unsigned int arr1_ddl_delay_cnt8                              :   16              ;    /* 15:0 */
        unsigned int arr1_ddl_delay_cnt9                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB164;

typedef union {
    struct {
        unsigned int arr1_ddl_delay_cnt10                             :   16              ;    /* 15:0 */
        unsigned int arr1_ddl_delay_cnt11                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB165;

typedef union {
    struct {
        unsigned int arr1_ddl_delay_cnt12                             :   16              ;    /* 15:0 */
        unsigned int arr1_ddl_delay_cnt13                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB166;

typedef union {
    struct {
        unsigned int arr1_ddl_delay_cnt14                             :   16              ;    /* 15:0 */
        unsigned int arr1_ddl_delay_cnt15                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB167;

typedef union {
    struct {
        unsigned int arr1_old_pds_bitmap0                             :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_bitmap1                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB200;

typedef union {
    struct {
        unsigned int arr1_old_pds_bitmap2                             :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_bitmap3                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB201;

typedef union {
    struct {
        unsigned int arr1_old_pds_bitmap4                             :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_bitmap5                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB202;

typedef union {
    struct {
        unsigned int arr1_old_pds_bitmap6                             :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_bitmap7                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB203;

typedef union {
    struct {
        unsigned int arr1_old_pds_bitmap8                             :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_bitmap9                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB204;

typedef union {
    struct {
        unsigned int arr1_old_pds_bitmap10                            :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_bitmap11                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB205;

typedef union {
    struct {
        unsigned int arr1_old_pds_bitmap12                            :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_bitmap13                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB206;

typedef union {
    struct {
        unsigned int arr1_old_pds_bitmap14                            :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_bitmap15                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB207;

typedef union {
    struct {
        unsigned int arr1_old_pds_symb_start0                         :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_symb_start1                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB208;

typedef union {
    struct {
        unsigned int arr1_old_pds_symb_start2                         :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_symb_start3                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB209;

typedef union {
    struct {
        unsigned int arr1_old_pds_symb_start4                         :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_symb_start5                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB210;

typedef union {
    struct {
        unsigned int arr1_old_pds_symb_start6                         :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_symb_start7                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB211;

typedef union {
    struct {
        unsigned int arr1_old_pds_symb_start8                         :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_symb_start9                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB212;

typedef union {
    struct {
        unsigned int arr1_old_pds_symb_start10                        :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_symb_start11                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB213;

typedef union {
    struct {
        unsigned int arr1_old_pds_symb_start12                        :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_symb_start13                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB214;

typedef union {
    struct {
        unsigned int arr1_old_pds_symb_start14                        :   16              ;    /* 15:0 */
        unsigned int arr1_old_pds_symb_start15                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB215;

typedef union {
    struct {
        unsigned int arr1_pds_symb_start0                             :   16              ;    /* 15:0 */
        unsigned int arr1_pds_symb_start1                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB216;

typedef union {
    struct {
        unsigned int arr1_pds_symb_start2                             :   16              ;    /* 15:0 */
        unsigned int arr1_pds_symb_start3                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB217;

typedef union {
    struct {
        unsigned int arr1_pds_symb_start4                             :   16              ;    /* 15:0 */
        unsigned int arr1_pds_symb_start5                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB218;

typedef union {
    struct {
        unsigned int arr1_pds_symb_start6                             :   16              ;    /* 15:0 */
        unsigned int arr1_pds_symb_start7                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB219;

typedef union {
    struct {
        unsigned int arr1_pds_symb_start8                             :   16              ;    /* 15:0 */
        unsigned int arr1_pds_symb_start9                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB220;

typedef union {
    struct {
        unsigned int arr1_pds_symb_start10                            :   16              ;    /* 15:0 */
        unsigned int arr1_pds_symb_start11                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB221;

typedef union {
    struct {
        unsigned int arr1_pds_symb_start12                            :   16              ;    /* 15:0 */
        unsigned int arr1_pds_symb_start13                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB222;

typedef union {
    struct {
        unsigned int arr1_pds_symb_start14                            :   16              ;    /* 15:0 */
        unsigned int arr1_pds_symb_start15                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB223;

typedef union {
    struct {
        unsigned int arr1_dci_store_idx0                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_store_idx1                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB224;

typedef union {
    struct {
        unsigned int arr1_dci_store_idx2                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_store_idx3                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB225;

typedef union {
    struct {
        unsigned int arr1_dci_store_idx4                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_store_idx5                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB226;

typedef union {
    struct {
        unsigned int arr1_dci_store_idx6                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_store_idx7                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB227;

typedef union {
    struct {
        unsigned int arr1_dci_store_idx8                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_store_idx9                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB228;

typedef union {
    struct {
        unsigned int arr1_dci_store_idx10                             :   16              ;    /* 15:0 */
        unsigned int arr1_dci_store_idx11                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB229;

typedef union {
    struct {
        unsigned int arr1_dci_store_idx12                             :   16              ;    /* 15:0 */
        unsigned int arr1_dci_store_idx13                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB230;

typedef union {
    struct {
        unsigned int arr1_dci_store_idx14                             :   16              ;    /* 15:0 */
        unsigned int arr1_dci_store_idx15                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB231;

typedef union {
    struct {
        unsigned int arr1_dci_prior_idx0                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_prior_idx1                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB232;

typedef union {
    struct {
        unsigned int arr1_dci_prior_idx2                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_prior_idx3                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB233;

typedef union {
    struct {
        unsigned int arr1_dci_prior_idx4                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_prior_idx5                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB234;

typedef union {
    struct {
        unsigned int arr1_dci_prior_idx6                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_prior_idx7                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB235;

typedef union {
    struct {
        unsigned int arr1_dci_prior_idx8                              :   16              ;    /* 15:0 */
        unsigned int arr1_dci_prior_idx9                              :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB236;

typedef union {
    struct {
        unsigned int arr1_dci_prior_idx10                             :   16              ;    /* 15:0 */
        unsigned int arr1_dci_prior_idx11                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB237;

typedef union {
    struct {
        unsigned int arr1_dci_prior_idx12                             :   16              ;    /* 15:0 */
        unsigned int arr1_dci_prior_idx13                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB238;

typedef union {
    struct {
        unsigned int arr1_dci_prior_idx14                             :   16              ;    /* 15:0 */
        unsigned int arr1_dci_prior_idx15                             :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB239;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB0                       om_data0;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB1                       om_data1;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB2                       om_data2;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB3                       om_data3;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB4                       om_data4;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB5                       om_data5;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB6                       om_data6;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB7                       om_data7;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB8                       om_data8;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB9                       om_data9;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB10                      om_data10;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB11                      om_data11;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB12                      om_data12;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB13                      om_data13;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB14                      om_data14;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB15                      om_data15;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB16                      om_data16;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB17                      om_data17;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB18                      om_data18;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB19                      om_data19;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB20                      om_data20;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB21                      om_data21;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB22                      om_data22;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB23                      om_data23;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB24                      om_data24;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB25                      om_data25;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB26                      om_data26;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB27                      om_data27;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB28                      om_data28;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB29                      om_data29;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB30                      om_data30;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB31                      om_data31;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB32                      om_data32;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB33                      om_data33;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB34                      om_data34;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB35                      om_data35;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB36                      om_data36;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB37                      om_data37;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB38                      om_data38;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB39                      om_data39;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB40                      om_data40;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB41                      om_data41;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB42                      om_data42;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB43                      om_data43;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB44                      om_data44;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB45                      om_data45;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB46                      om_data46;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB47                      om_data47;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB48                      om_data48;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB49                      om_data49;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB50                      om_data50;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB51                      om_data51;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB52                      om_data52;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB53                      om_data53;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB54                      om_data54;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB55                      om_data55;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB56                      om_data56;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB57                      om_data57;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB58                      om_data58;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB59                      om_data59;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB60                      om_data60;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB61                      om_data61;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB62                      om_data62;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB63                      om_data63;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB64                      om_data64;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB65                      om_data65;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB66                      om_data66;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB67                      om_data67;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB68                      om_data68;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB69                      om_data69;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB70                      om_data70;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB71                      om_data71;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB72                      om_data72;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB73                      om_data73;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB74                      om_data74;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB75                      om_data75;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB76                      om_data76;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB77                      om_data77;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB78                      om_data78;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB79                      om_data79;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB80                      om_data80;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB81                      om_data81;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB82                      om_data82;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB83                      om_data83;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB84                      om_data84;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB85                      om_data85;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB86                      om_data86;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB87                      om_data87;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB88                      om_data88;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB89                      om_data89;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB90                      om_data90;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB91                      om_data91;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB92                      om_data92;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB93                      om_data93;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB94                      om_data94;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB95                      om_data95;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB96                      om_data96;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB97                      om_data97;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB98                      om_data98;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB99                      om_data99;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB100                     om_data100;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB101                     om_data101;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB102                     om_data102;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB103                     om_data103;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB104                     om_data104;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB105                     om_data105;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB106                     om_data106;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB107                     om_data107;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB108                     om_data108;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB109                     om_data109;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB110                     om_data110;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB111                     om_data111;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB112                     om_data112;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB113                     om_data113;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB114                     om_data114;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB115                     om_data115;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB116                     om_data116;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB117                     om_data117;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB118                     om_data118;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB119                     om_data119;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB120                     om_data120;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB121                     om_data121;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB122                     om_data122;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB123                     om_data123;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB124                     om_data124;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB125                     om_data125;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB126                     om_data126;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB127                     om_data127;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB128                     om_data128;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB129                     om_data129;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB130                     om_data130;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB131                     om_data131;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB132                     om_data132;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB133                     om_data133;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB134                     om_data134;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB135                     om_data135;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB136                     om_data136;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB137                     om_data137;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB138                     om_data138;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB139                     om_data139;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB140                     om_data140;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB141                     om_data141;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB142                     om_data142;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB143                     om_data143;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB144                     om_data144;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB145                     om_data145;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB146                     om_data146;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB147                     om_data147;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB148                     om_data148;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB149                     om_data149;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB150                     om_data150;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB151                     om_data151;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB152                     om_data152;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB153                     om_data153;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB154                     om_data154;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB155                     om_data155;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB156                     om_data156;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB157                     om_data157;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB158                     om_data158;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB159                     om_data159;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB160                     om_data160;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB161                     om_data161;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB162                     om_data162;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB163                     om_data163;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB164                     om_data164;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB165                     om_data165;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB166                     om_data166;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB167                     om_data167;
    unsigned int                                                      arr1_old_dci_data0_0;
    unsigned int                                                      arr1_old_dci_data0_1;
    unsigned int                                                      arr1_old_dci_data0_2;
    unsigned int                                                      arr1_old_dci_data0_3;
    unsigned int                                                      arr1_old_dci_data0_4;
    unsigned int                                                      arr1_old_dci_data0_5;
    unsigned int                                                      arr1_old_dci_data0_6;
    unsigned int                                                      arr1_old_dci_data0_7;
    unsigned int                                                      arr1_old_dci_data0_8;
    unsigned int                                                      arr1_old_dci_data0_9;
    unsigned int                                                      arr1_old_dci_data0_10;
    unsigned int                                                      arr1_old_dci_data0_11;
    unsigned int                                                      arr1_old_dci_data0_12;
    unsigned int                                                      arr1_old_dci_data0_13;
    unsigned int                                                      arr1_old_dci_data0_14;
    unsigned int                                                      arr1_old_dci_data0_15;
    unsigned int                                                      arr1_old_dci_data1_0;
    unsigned int                                                      arr1_old_dci_data1_1;
    unsigned int                                                      arr1_old_dci_data1_2;
    unsigned int                                                      arr1_old_dci_data1_3;
    unsigned int                                                      arr1_old_dci_data1_4;
    unsigned int                                                      arr1_old_dci_data1_5;
    unsigned int                                                      arr1_old_dci_data1_6;
    unsigned int                                                      arr1_old_dci_data1_7;
    unsigned int                                                      arr1_old_dci_data1_8;
    unsigned int                                                      arr1_old_dci_data1_9;
    unsigned int                                                      arr1_old_dci_data1_10;
    unsigned int                                                      arr1_old_dci_data1_11;
    unsigned int                                                      arr1_old_dci_data1_12;
    unsigned int                                                      arr1_old_dci_data1_13;
    unsigned int                                                      arr1_old_dci_data1_14;
    unsigned int                                                      arr1_old_dci_data1_15;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB200                     om_data200;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB201                     om_data201;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB202                     om_data202;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB203                     om_data203;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB204                     om_data204;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB205                     om_data205;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB206                     om_data206;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB207                     om_data207;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB208                     om_data208;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB209                     om_data209;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB210                     om_data210;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB211                     om_data211;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB212                     om_data212;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB213                     om_data213;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB214                     om_data214;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB215                     om_data215;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB216                     om_data216;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB217                     om_data217;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB218                     om_data218;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB219                     om_data219;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB220                     om_data220;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB221                     om_data221;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB222                     om_data222;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB223                     om_data223;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB224                     om_data224;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB225                     om_data225;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB226                     om_data226;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB227                     om_data227;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB228                     om_data228;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB229                     om_data229;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB230                     om_data230;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB231                     om_data231;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB232                     om_data232;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB233                     om_data233;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB234                     om_data234;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB235                     om_data235;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB236                     om_data236;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB237                     om_data237;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB238                     om_data238;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB239                     om_data239;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB0                       om_data0;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB1                       om_data1;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB2                       om_data2;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB3                       om_data3;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB4                       om_data4;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB5                       om_data5;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB6                       om_data6;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB7                       om_data7;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB8                       om_data8;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB9                       om_data9;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB10                      om_data10;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB11                      om_data11;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB12                      om_data12;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB13                      om_data13;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB14                      om_data14;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB15                      om_data15;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB16                      om_data16;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB17                      om_data17;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB18                      om_data18;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB19                      om_data19;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB20                      om_data20;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB21                      om_data21;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB22                      om_data22;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB23                      om_data23;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB24                      om_data24;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB25                      om_data25;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB26                      om_data26;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB27                      om_data27;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB28                      om_data28;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB29                      om_data29;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB30                      om_data30;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB31                      om_data31;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB32                      om_data32;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB33                      om_data33;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB34                      om_data34;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB35                      om_data35;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB36                      om_data36;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB37                      om_data37;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB38                      om_data38;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB39                      om_data39;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB40                      om_data40;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB41                      om_data41;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB42                      om_data42;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB43                      om_data43;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB44                      om_data44;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB45                      om_data45;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB46                      om_data46;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB47                      om_data47;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB48                      om_data48;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB49                      om_data49;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB50                      om_data50;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB51                      om_data51;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB52                      om_data52;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB53                      om_data53;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB54                      om_data54;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB55                      om_data55;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB56                      om_data56;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB57                      om_data57;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB58                      om_data58;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB59                      om_data59;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB60                      om_data60;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB61                      om_data61;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB62                      om_data62;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB63                      om_data63;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB64                      om_data64;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB65                      om_data65;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB66                      om_data66;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB67                      om_data67;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB68                      om_data68;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB69                      om_data69;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB70                      om_data70;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB71                      om_data71;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB72                      om_data72;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB73                      om_data73;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB74                      om_data74;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB75                      om_data75;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB76                      om_data76;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB77                      om_data77;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB78                      om_data78;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB79                      om_data79;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB80                      om_data80;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB81                      om_data81;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB82                      om_data82;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB83                      om_data83;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB84                      om_data84;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB85                      om_data85;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB86                      om_data86;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB87                      om_data87;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB88                      om_data88;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB89                      om_data89;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB90                      om_data90;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB91                      om_data91;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB92                      om_data92;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB93                      om_data93;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB94                      om_data94;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB95                      om_data95;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB96                      om_data96;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB97                      om_data97;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB98                      om_data98;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB99                      om_data99;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB100                     om_data100;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB101                     om_data101;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB102                     om_data102;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB103                     om_data103;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB104                     om_data104;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB105                     om_data105;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB106                     om_data106;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB107                     om_data107;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB108                     om_data108;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB109                     om_data109;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB110                     om_data110;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB111                     om_data111;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB112                     om_data112;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB113                     om_data113;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB114                     om_data114;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB115                     om_data115;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB116                     om_data116;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB117                     om_data117;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB118                     om_data118;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB119                     om_data119;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB120                     om_data120;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB121                     om_data121;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB122                     om_data122;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB123                     om_data123;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB124                     om_data124;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB125                     om_data125;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB126                     om_data126;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB127                     om_data127;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB128                     om_data128;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB129                     om_data129;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB130                     om_data130;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB131                     om_data131;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB132                     om_data132;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB133                     om_data133;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB134                     om_data134;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB135                     om_data135;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB136                     om_data136;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB137                     om_data137;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB138                     om_data138;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB139                     om_data139;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB140                     om_data140;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB141                     om_data141;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB142                     om_data142;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB143                     om_data143;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB144                     om_data144;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB145                     om_data145;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB146                     om_data146;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB147                     om_data147;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB148                     om_data148;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB149                     om_data149;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB150                     om_data150;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB151                     om_data151;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB152                     om_data152;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB153                     om_data153;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB154                     om_data154;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB155                     om_data155;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB156                     om_data156;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB157                     om_data157;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB158                     om_data158;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB159                     om_data159;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB160                     om_data160;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB161                     om_data161;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB162                     om_data162;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB163                     om_data163;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB164                     om_data164;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB165                     om_data165;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB166                     om_data166;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB167                     om_data167;
    unsigned int                                                      arr1_old_dci_data0_0;
    unsigned int                                                      arr1_old_dci_data0_1;
    unsigned int                                                      arr1_old_dci_data0_2;
    unsigned int                                                      arr1_old_dci_data0_3;
    unsigned int                                                      arr1_old_dci_data0_4;
    unsigned int                                                      arr1_old_dci_data0_5;
    unsigned int                                                      arr1_old_dci_data0_6;
    unsigned int                                                      arr1_old_dci_data0_7;
    unsigned int                                                      arr1_old_dci_data0_8;
    unsigned int                                                      arr1_old_dci_data0_9;
    unsigned int                                                      arr1_old_dci_data0_10;
    unsigned int                                                      arr1_old_dci_data0_11;
    unsigned int                                                      arr1_old_dci_data0_12;
    unsigned int                                                      arr1_old_dci_data0_13;
    unsigned int                                                      arr1_old_dci_data0_14;
    unsigned int                                                      arr1_old_dci_data0_15;
    unsigned int                                                      arr1_old_dci_data1_0;
    unsigned int                                                      arr1_old_dci_data1_1;
    unsigned int                                                      arr1_old_dci_data1_2;
    unsigned int                                                      arr1_old_dci_data1_3;
    unsigned int                                                      arr1_old_dci_data1_4;
    unsigned int                                                      arr1_old_dci_data1_5;
    unsigned int                                                      arr1_old_dci_data1_6;
    unsigned int                                                      arr1_old_dci_data1_7;
    unsigned int                                                      arr1_old_dci_data1_8;
    unsigned int                                                      arr1_old_dci_data1_9;
    unsigned int                                                      arr1_old_dci_data1_10;
    unsigned int                                                      arr1_old_dci_data1_11;
    unsigned int                                                      arr1_old_dci_data1_12;
    unsigned int                                                      arr1_old_dci_data1_13;
    unsigned int                                                      arr1_old_dci_data1_14;
    unsigned int                                                      arr1_old_dci_data1_15;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB200                     om_data200;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB201                     om_data201;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB202                     om_data202;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB203                     om_data203;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB204                     om_data204;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB205                     om_data205;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB206                     om_data206;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB207                     om_data207;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB208                     om_data208;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB209                     om_data209;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB210                     om_data210;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB211                     om_data211;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB212                     om_data212;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB213                     om_data213;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB214                     om_data214;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB215                     om_data215;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB216                     om_data216;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB217                     om_data217;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB218                     om_data218;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB219                     om_data219;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB220                     om_data220;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB221                     om_data221;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB222                     om_data222;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB223                     om_data223;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB224                     om_data224;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB225                     om_data225;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB226                     om_data226;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB227                     om_data227;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB228                     om_data228;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB229                     om_data229;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB230                     om_data230;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB231                     om_data231;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB232                     om_data232;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB233                     om_data233;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB234                     om_data234;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB235                     om_data235;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB236                     om_data236;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB237                     om_data237;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB238                     om_data238;
    DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_SUB239                     om_data239;
} DCICP_SID_DCICP_OM_INFO_NR_CTRL_ARRAY1_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
