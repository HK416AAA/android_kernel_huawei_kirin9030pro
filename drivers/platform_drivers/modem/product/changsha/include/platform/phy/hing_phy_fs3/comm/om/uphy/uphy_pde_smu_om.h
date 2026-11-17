

#ifndef __UPHY_PDE_SMU_OM_H__
#define __UPHY_PDE_SMU_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef union {
    struct {
        unsigned int node0_word2_data_len                             :   19              ;    /* 18:0 */
        unsigned int node0_word2_rx_ofst                              :   13              ;    /* 31:19 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_DIF_DAE_CFG_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      node0_word0_saddr;
    SMU_SID_SMU_DIF_DAE_CFG_SUB1                                      om_data1;
} SMU_SID_SMU_DIF_DAE_CFG;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      node0_word0_saddr;
    SMU_SID_SMU_DIF_DAE_CFG_SUB1                                      om_data1;
} SMU_SID_SMU_DIF_DAE_CFG_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      smu_inner_task_type;
    unsigned int                                                      g_crs_cell_cnt;
} SMU_SID_SMU_TOP_CRS_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      smu_inner_task_type;
    unsigned int                                                      g_crs_cell_cnt;
} SMU_SID_SMU_TOP_CRS_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      smu_inner_task_type;
    unsigned int                                                      ssb_task_type;
} SMU_SID_SMU_TOP_SSB_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      smu_inner_task_type;
    unsigned int                                                      ssb_task_type;
} SMU_SID_SMU_TOP_SSB_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      smu_inner_task_type;
    unsigned int                                                      csi_bm_rsv_0;
} SMU_SID_SMU_TOP_CSI_BM_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      smu_inner_task_type;
    unsigned int                                                      csi_bm_rsv_0;
} SMU_SID_SMU_TOP_CSI_BM_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      return_dat;
    unsigned int                                                      g_crs_cell_cnt;
} SMU_SID_SMU_TOP_CRS_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      return_dat;
    unsigned int                                                      g_crs_cell_cnt;
} SMU_SID_SMU_TOP_CRS_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      return_dat;
    unsigned int                                                      proc_rsc_num;
} SMU_SID_SMU_TOP_SSB_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      return_dat;
    unsigned int                                                      proc_rsc_num;
} SMU_SID_SMU_TOP_SSB_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int csi_bm_rsc_num                                   :   16              ;    /* 15:0 */
        unsigned int rsrpy_rsc_num                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_TOP_CSI_BM_OUT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      return_dat;
    SMU_SID_SMU_TOP_CSI_BM_OUT_SUB1                                   om_data1;
} SMU_SID_SMU_TOP_CSI_BM_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      return_dat;
    SMU_SID_SMU_TOP_CSI_BM_OUT_SUB1                                   om_data1;
} SMU_SID_SMU_TOP_CSI_BM_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int smu_cell_start_flag                              :   8               ;    /* 7:0 */
        unsigned int smu_cell_end_flag                                :   8               ;    /* 15:8 */
        unsigned int smu_sfm_idx                                      :   8               ;    /* 23:16 */
        unsigned int smu_crs_sym_vld                                  :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB0;

typedef union {
    struct {
        unsigned int smu_sym_gain_sw_flag                             :   8               ;    /* 7:0 */
        unsigned int smu_sym_gain_sel                                 :   8               ;    /* 15:8 */
        unsigned int smu_sym_gain_ofst                                :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB1;

typedef union {
    struct {
        unsigned int smu_gain_pre_r0                                  :   16              ;    /* 15:0 */
        unsigned int smu_gain_pre_r1                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB2;

typedef union {
    struct {
        unsigned int smu_gain_cur_r0                                  :   16              ;    /* 15:0 */
        unsigned int smu_gain_cur_r1                                  :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB3;

typedef union {
    struct {
        unsigned int smu_sfrm_tab0                                    :   8               ;    /* 7:0 */
        unsigned int smu_sfrm_tab1                                    :   8               ;    /* 15:8 */
        unsigned int smu_sfrm_tab2                                    :   8               ;    /* 23:16 */
        unsigned int smu_sfrm_tab3                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB4;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB0                                 om_data0;
    SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB1                                 om_data1;
    SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB2                                 om_data2;
    SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB3                                 om_data3;
    SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB4                                 om_data4;
    unsigned int                                                      rsv0_0;
    unsigned int                                                      crs_sym_num;
    unsigned int                                                      crs_next_finish_flag;
    unsigned int                                                      g_crs_cell_cnt;
    unsigned int                                                      rsv1_1;
    unsigned int                                                      g_crs_sfrm_idx;
    unsigned int                                                      g_crs_sfrm_num;
} SMU_SID_SMU_INFO_CRS_DIF_GLB;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB0                                 om_data0;
    SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB1                                 om_data1;
    SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB2                                 om_data2;
    SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB3                                 om_data3;
    SMU_SID_SMU_INFO_CRS_DIF_GLB_SUB4                                 om_data4;
    unsigned int                                                      rsv0_0;
    unsigned int                                                      crs_sym_num;
    unsigned int                                                      crs_next_finish_flag;
    unsigned int                                                      g_crs_cell_cnt;
    unsigned int                                                      rsv1_1;
    unsigned int                                                      g_crs_sfrm_idx;
    unsigned int                                                      g_crs_sfrm_num;
} SMU_SID_SMU_INFO_CRS_DIF_GLB_BBP_MC;

typedef union {
    struct {
        unsigned int data0_rs_type                                    :   8               ;    /* 7:0 */
        unsigned int data0_cc_idx                                     :   8               ;    /* 15:8 */
        unsigned int data0_rsc_idx                                    :   8               ;    /* 23:16 */
        unsigned int data0_sym_idx                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB0;

typedef union {
    struct {
        unsigned int data1_slot_idx                                   :   8               ;    /* 7:0 */
        unsigned int data1_port_num                                   :   8               ;    /* 15:8 */
        unsigned int data1_rx_num                                     :   8               ;    /* 23:16 */
        unsigned int data1_cp_type                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB1;

typedef union {
    struct {
        unsigned int data6_pilot_d                                    :   8               ;    /* 7:0 */
        unsigned int data6_sym_num                                    :   8               ;    /* 15:8 */
        unsigned int data6_dat_ind                                    :   8               ;    /* 23:16 */
        unsigned int data6_sent_cnt                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB6;

typedef union {
    struct {
        unsigned int data9_ifft_idx                                   :   16              ;    /* 15:0 */
        unsigned int data9_pdc_only_ind                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB9;

typedef union {
    struct {
        unsigned int data10_rsc0_bm_idx                               :   8               ;    /* 7:0 */
        unsigned int data10_rsc1_bm_idx                               :   8               ;    /* 15:8 */
        unsigned int data10_rsc2_bm_idx                               :   8               ;    /* 23:16 */
        unsigned int data10_rsc3_bm_idx                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB10;

typedef union {
    struct {
        unsigned int data11_rsc4_bm_idx                               :   8               ;    /* 7:0 */
        unsigned int data11_rsc5_bm_idx                               :   8               ;    /* 15:8 */
        unsigned int data11_rsc6_bm_idx                               :   8               ;    /* 23:16 */
        unsigned int data11_rsc7_bm_idx                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB11;

typedef union {
    struct {
        unsigned int data12_rsc0_buf_idx                              :   8               ;    /* 7:0 */
        unsigned int data12_rsc1_buf_idx                              :   8               ;    /* 15:8 */
        unsigned int data12_rsc2_buf_idx                              :   8               ;    /* 23:16 */
        unsigned int data12_rsc3_buf_idx                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB12;

typedef union {
    struct {
        unsigned int data13_rsc4_buf_idx                              :   8               ;    /* 7:0 */
        unsigned int data13_rsc5_buf_idx                              :   8               ;    /* 15:8 */
        unsigned int data13_rsc6_buf_idx                              :   8               ;    /* 23:16 */
        unsigned int data13_rsc7_buf_idx                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB13;

typedef union {
    struct {
        unsigned int data15_tfe_task_cnt                              :   8               ;    /* 7:0 */
        unsigned int data15_tfe_task_mode                             :   8               ;    /* 15:8 */
        unsigned int data15_tfe_task_end                              :   8               ;    /* 23:16 */
        unsigned int data15_tfe_sub_task_type                         :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB15;

typedef union {
    struct {
        unsigned int data17_crs_port_sel_rx0                          :   8               ;    /* 7:0 */
        unsigned int data17_crs_port_sel_rx1                          :   8               ;    /* 15:8 */
        unsigned int data17_crs_port_sel_rx2                          :   8               ;    /* 23:16 */
        unsigned int data17_crs_port_sel_rx3                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB17;

typedef union {
    struct {
        unsigned int data18_dsds_bitmap                               :   16              ;    /* 15:0 */
        unsigned int data18_smu_state_bitmap                          :   8               ;    /* 23:16 */
        unsigned int data18_smu_rpt_info                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB18;

typedef union {
    struct {
        unsigned int data20_start_re_offset                           :   16              ;    /* 15:0 */
        unsigned int data20_start_dat_offset                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB20;

typedef union {
    struct {
        unsigned int data21_tpa_en                                    :   16              ;    /* 15:0 */
        unsigned int data21_lte_bw                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB21;

typedef union {
    struct {
        unsigned int data30_max_path_win_len                          :   8               ;    /* 7:0 */
        unsigned int data30_noise_win_len                             :   8               ;    /* 15:8 */
        unsigned int data30_noise_est_mod                             :   8               ;    /* 23:16 */
        unsigned int data30_noise_win_start                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB30;

typedef union {
    struct {
        unsigned int data31_pkt_pdp_reset_flag                        :   8               ;    /* 7:0 */
        unsigned int data31_tfe_cmu_en                                :   8               ;    /* 15:8 */
        unsigned int data31_tfe_emu_en                                :   8               ;    /* 23:16 */
        unsigned int data31_emu_max_path_type                         :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB31;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB0                                om_data0;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB1                                om_data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB6                                om_data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8_rsc_num;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB9                                om_data9;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB10                               om_data10;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB11                               om_data11;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB12                               om_data12;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB13                               om_data13;
    unsigned int                                                      data14;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB15                               om_data15;
    unsigned int                                                      data16;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB17                               om_data17;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB18                               om_data18;
    unsigned int                                                      data19_cir_ls_buf_addr;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB20                               om_data20;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB21                               om_data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25_data_type;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB30                               om_data30;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB31                               om_data31;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB0                                om_data0;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB1                                om_data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB6                                om_data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8_rsc_num;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB9                                om_data9;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB10                               om_data10;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB11                               om_data11;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB12                               om_data12;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB13                               om_data13;
    unsigned int                                                      data14;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB15                               om_data15;
    unsigned int                                                      data16;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB17                               om_data17;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB18                               om_data18;
    unsigned int                                                      data19_cir_ls_buf_addr;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB20                               om_data20;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB21                               om_data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25_data_type;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB30                               om_data30;
    SMU_SID_SMU_INFO_CRS_PKT_HEAD_SUB31                               om_data31;
} SMU_SID_SMU_INFO_CRS_PKT_HEAD_BBP_MC;


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
} SMU_SID_SMU_INFO_CRS_EMU_PDP;


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
} SMU_SID_SMU_INFO_CRS_EMU_PDP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      sym_vld_flag;
    unsigned int                                                      dsds_flag;
    unsigned int                                                      post_sym_remove_flag;
    unsigned int                                                      rxtx_idx;
} SMU_SID_SMU_INFO_CRS_SYM_PICK;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sym_vld_flag;
    unsigned int                                                      dsds_flag;
    unsigned int                                                      post_sym_remove_flag;
    unsigned int                                                      rxtx_idx;
} SMU_SID_SMU_INFO_CRS_SYM_PICK_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      smu_crs_par0;
    unsigned int                                                      smu_crs_par1;
    unsigned int                                                      smu_crs_par2;
    unsigned int                                                      smu_crs_par3;
    unsigned int                                                      smu_crs_par4;
    unsigned int                                                      smu_crs_par5;
    unsigned int                                                      smu_crs_par6;
    unsigned int                                                      smu_crs_par7;
    unsigned int                                                      smu_crs_par8;
    unsigned int                                                      smu_crs_par9;
    unsigned int                                                      smu_crs_par10;
    unsigned int                                                      smu_crs_par11;
    unsigned int                                                      smu_crs_par12;
    unsigned int                                                      smu_crs_par13;
    unsigned int                                                      smu_crs_par14;
    unsigned int                                                      smu_crs_par15;
    unsigned int                                                      smu_crs_par16;
    unsigned int                                                      smu_crs_par17;
    unsigned int                                                      smu_crs_par18;
    unsigned int                                                      smu_crs_par19;
    unsigned int                                                      smu_crs_par20;
    unsigned int                                                      smu_crs_par21;
    unsigned int                                                      smu_crs_par22;
    unsigned int                                                      smu_crs_par23;
    unsigned int                                                      smu_crs_par24;
    unsigned int                                                      smu_crs_par25;
    unsigned int                                                      smu_crs_par26;
    unsigned int                                                      smu_crs_par27;
    unsigned int                                                      smu_crs_par28;
    unsigned int                                                      smu_crs_par29;
    unsigned int                                                      smu_crs_par30;
    unsigned int                                                      smu_crs_par31;
} SMU_SID_SMU_INFO_CRS_PAR;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      smu_crs_par0;
    unsigned int                                                      smu_crs_par1;
    unsigned int                                                      smu_crs_par2;
    unsigned int                                                      smu_crs_par3;
    unsigned int                                                      smu_crs_par4;
    unsigned int                                                      smu_crs_par5;
    unsigned int                                                      smu_crs_par6;
    unsigned int                                                      smu_crs_par7;
    unsigned int                                                      smu_crs_par8;
    unsigned int                                                      smu_crs_par9;
    unsigned int                                                      smu_crs_par10;
    unsigned int                                                      smu_crs_par11;
    unsigned int                                                      smu_crs_par12;
    unsigned int                                                      smu_crs_par13;
    unsigned int                                                      smu_crs_par14;
    unsigned int                                                      smu_crs_par15;
    unsigned int                                                      smu_crs_par16;
    unsigned int                                                      smu_crs_par17;
    unsigned int                                                      smu_crs_par18;
    unsigned int                                                      smu_crs_par19;
    unsigned int                                                      smu_crs_par20;
    unsigned int                                                      smu_crs_par21;
    unsigned int                                                      smu_crs_par22;
    unsigned int                                                      smu_crs_par23;
    unsigned int                                                      smu_crs_par24;
    unsigned int                                                      smu_crs_par25;
    unsigned int                                                      smu_crs_par26;
    unsigned int                                                      smu_crs_par27;
    unsigned int                                                      smu_crs_par28;
    unsigned int                                                      smu_crs_par29;
    unsigned int                                                      smu_crs_par30;
    unsigned int                                                      smu_crs_par31;
} SMU_SID_SMU_INFO_CRS_PAR_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      g_crs_sym_start_next0;
    unsigned int                                                      g_crs_sym_start_next1;
    unsigned int                                                      g_crs_sym_start_next2;
    unsigned int                                                      g_crs_sym_start_next3;
} SMU_SID_SMU_INFO_CRS_POS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      g_crs_sym_start_next0;
    unsigned int                                                      g_crs_sym_start_next1;
    unsigned int                                                      g_crs_sym_start_next2;
    unsigned int                                                      g_crs_sym_start_next3;
} SMU_SID_SMU_INFO_CRS_POS_BBP_MC;

typedef union {
    struct {
        unsigned int rsv0_0                                           :   8               ;    /* 7:0 */
        unsigned int ssb_idx_pre0                                     :   8               ;    /* 15:8 */
        unsigned int ssb_snr_pre0                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB0;

typedef union {
    struct {
        unsigned int rsv1_0                                           :   8               ;    /* 7:0 */
        unsigned int ssb_idx_cur0                                     :   8               ;    /* 15:8 */
        unsigned int ssb_snr_cur0                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB2;

typedef union {
    struct {
        unsigned int rsv2_0                                           :   8               ;    /* 7:0 */
        unsigned int ssb_idx_pre1                                     :   8               ;    /* 15:8 */
        unsigned int ssb_snr_pre1                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB4;

typedef union {
    struct {
        unsigned int rsv3_0                                           :   8               ;    /* 7:0 */
        unsigned int ssb_idx_cur1                                     :   8               ;    /* 15:8 */
        unsigned int ssb_snr_cur1                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB6;

typedef union {
    struct {
        unsigned int rsv4_0                                           :   8               ;    /* 7:0 */
        unsigned int ssb_idx_pre2                                     :   8               ;    /* 15:8 */
        unsigned int ssb_snr_pre2                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB8;

typedef union {
    struct {
        unsigned int rsv5_0                                           :   8               ;    /* 7:0 */
        unsigned int ssb_idx_cur2                                     :   8               ;    /* 15:8 */
        unsigned int ssb_snr_cur2                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB10;

typedef union {
    struct {
        unsigned int rsv6_0                                           :   8               ;    /* 7:0 */
        unsigned int ssb_idx_pre3                                     :   8               ;    /* 15:8 */
        unsigned int ssb_snr_pre3                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB12;

typedef union {
    struct {
        unsigned int rsv7_0                                           :   8               ;    /* 7:0 */
        unsigned int ssb_idx_cur3                                     :   8               ;    /* 15:8 */
        unsigned int ssb_snr_cur3                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB14;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB0                                 om_data0;
    unsigned int                                                      ssb_data_ofst_pre0;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB2                                 om_data2;
    unsigned int                                                      ssb_data_ofst_cur0;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB4                                 om_data4;
    unsigned int                                                      ssb_data_ofst_pre1;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB6                                 om_data6;
    unsigned int                                                      ssb_data_ofst_cur1;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB8                                 om_data8;
    unsigned int                                                      ssb_data_ofst_pre2;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB10                                om_data10;
    unsigned int                                                      ssb_data_ofst_cur2;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB12                                om_data12;
    unsigned int                                                      ssb_data_ofst_pre3;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB14                                om_data14;
    unsigned int                                                      ssb_data_ofst_cur3;
} SMU_SID_SMU_INFO_SSB_OPTM_BM;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB0                                 om_data0;
    unsigned int                                                      ssb_data_ofst_pre0;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB2                                 om_data2;
    unsigned int                                                      ssb_data_ofst_cur0;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB4                                 om_data4;
    unsigned int                                                      ssb_data_ofst_pre1;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB6                                 om_data6;
    unsigned int                                                      ssb_data_ofst_cur1;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB8                                 om_data8;
    unsigned int                                                      ssb_data_ofst_pre2;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB10                                om_data10;
    unsigned int                                                      ssb_data_ofst_cur2;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB12                                om_data12;
    unsigned int                                                      ssb_data_ofst_pre3;
    SMU_SID_SMU_INFO_SSB_OPTM_BM_SUB14                                om_data14;
    unsigned int                                                      ssb_data_ofst_cur3;
} SMU_SID_SMU_INFO_SSB_OPTM_BM_BBP_MC;

typedef union {
    struct {
        unsigned int data0_rs_type                                    :   8               ;    /* 7:0 */
        unsigned int data0_cc_idx                                     :   8               ;    /* 15:8 */
        unsigned int data0_rsc_idx                                    :   8               ;    /* 23:16 */
        unsigned int data0_sym_idx                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB0;

typedef union {
    struct {
        unsigned int data1_slot_idx                                   :   8               ;    /* 7:0 */
        unsigned int data1_port_num                                   :   8               ;    /* 15:8 */
        unsigned int data1_rx_num                                     :   8               ;    /* 23:16 */
        unsigned int data1_cp_type                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB1;

typedef union {
    struct {
        unsigned int data6_pilot_d                                    :   8               ;    /* 7:0 */
        unsigned int data6_sym_num                                    :   8               ;    /* 15:8 */
        unsigned int data6_dat_ind                                    :   8               ;    /* 23:16 */
        unsigned int data6_sent_cnt                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB6;

typedef union {
    struct {
        unsigned int data9_ifft_idx                                   :   16              ;    /* 15:0 */
        unsigned int data9_pdc_only_ind                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB9;

typedef union {
    struct {
        unsigned int data10_rsc0_bm_idx                               :   8               ;    /* 7:0 */
        unsigned int data10_rsc1_bm_idx                               :   8               ;    /* 15:8 */
        unsigned int data10_rsc2_bm_idx                               :   8               ;    /* 23:16 */
        unsigned int data10_rsc3_bm_idx                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB10;

typedef union {
    struct {
        unsigned int data11_rsc4_bm_idx                               :   8               ;    /* 7:0 */
        unsigned int data11_rsc5_bm_idx                               :   8               ;    /* 15:8 */
        unsigned int data11_rsc6_bm_idx                               :   8               ;    /* 23:16 */
        unsigned int data11_rsc7_bm_idx                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB11;

typedef union {
    struct {
        unsigned int data12_rsc0_buf_idx                              :   8               ;    /* 7:0 */
        unsigned int data12_rsc1_buf_idx                              :   8               ;    /* 15:8 */
        unsigned int data12_rsc2_buf_idx                              :   8               ;    /* 23:16 */
        unsigned int data12_rsc3_buf_idx                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB12;

typedef union {
    struct {
        unsigned int data13_rsc4_buf_idx                              :   8               ;    /* 7:0 */
        unsigned int data13_rsc5_buf_idx                              :   8               ;    /* 15:8 */
        unsigned int data13_rsc6_buf_idx                              :   8               ;    /* 23:16 */
        unsigned int data13_rsc7_buf_idx                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB13;

typedef union {
    struct {
        unsigned int data15_tfe_task_cnt                              :   8               ;    /* 7:0 */
        unsigned int data15_tfe_task_mode                             :   8               ;    /* 15:8 */
        unsigned int data15_tfe_task_end                              :   8               ;    /* 23:16 */
        unsigned int data15_tfe_sub_task_type                         :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB15;

typedef union {
    struct {
        unsigned int data17_crs_port_sel_rx0                          :   8               ;    /* 7:0 */
        unsigned int data17_crs_port_sel_rx1                          :   8               ;    /* 15:8 */
        unsigned int data17_crs_port_sel_rx2                          :   8               ;    /* 23:16 */
        unsigned int data17_crs_port_sel_rx3                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB17;

typedef union {
    struct {
        unsigned int data18_dsds_bitmap                               :   16              ;    /* 15:0 */
        unsigned int data18_smu_state_bitmap                          :   8               ;    /* 23:16 */
        unsigned int data18_smu_rpt_info                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB18;

typedef union {
    struct {
        unsigned int data20_start_re_offset                           :   16              ;    /* 15:0 */
        unsigned int data20_start_dat_offset                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB20;

typedef union {
    struct {
        unsigned int data21_tpa_en                                    :   16              ;    /* 15:0 */
        unsigned int data21_lte_bw                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB21;

typedef union {
    struct {
        unsigned int data30_max_path_win_len                          :   8               ;    /* 7:0 */
        unsigned int data30_noise_win_len                             :   8               ;    /* 15:8 */
        unsigned int data30_noise_est_mod                             :   8               ;    /* 23:16 */
        unsigned int data30_noise_win_start                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB30;

typedef union {
    struct {
        unsigned int data31_pkt_pdp_reset_flag                        :   8               ;    /* 7:0 */
        unsigned int data31_tfe_cmu_en                                :   8               ;    /* 15:8 */
        unsigned int data31_tfe_emu_en                                :   8               ;    /* 23:16 */
        unsigned int data31_emu_max_path_type                         :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB31;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB0                                om_data0;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB1                                om_data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB6                                om_data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8_rsc_num;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB9                                om_data9;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB10                               om_data10;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB11                               om_data11;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB12                               om_data12;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB13                               om_data13;
    unsigned int                                                      data14;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB15                               om_data15;
    unsigned int                                                      data16;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB17                               om_data17;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB18                               om_data18;
    unsigned int                                                      data19_cir_ls_buf_addr;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB20                               om_data20;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB21                               om_data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25_data_type;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB30                               om_data30;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB31                               om_data31;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB0                                om_data0;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB1                                om_data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB6                                om_data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8_rsc_num;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB9                                om_data9;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB10                               om_data10;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB11                               om_data11;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB12                               om_data12;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB13                               om_data13;
    unsigned int                                                      data14;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB15                               om_data15;
    unsigned int                                                      data16;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB17                               om_data17;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB18                               om_data18;
    unsigned int                                                      data19_cir_ls_buf_addr;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB20                               om_data20;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB21                               om_data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25_data_type;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB30                               om_data30;
    SMU_SID_SMU_INFO_SSB_PKT_HEAD_SUB31                               om_data31;
} SMU_SID_SMU_INFO_SSB_PKT_HEAD_BBP_MC;


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
} SMU_SID_SMU_INFO_SSS_EMU_PDP;


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
} SMU_SID_SMU_INFO_SSS_EMU_PDP_BBP_MC;


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
} SMU_SID_SMU_INFO_SSS_LS;


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
} SMU_SID_SMU_INFO_SSS_LS_BBP_MC;


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
} SMU_SID_SMU_INFO_DMRS_EMU_PDP;


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
} SMU_SID_SMU_INFO_DMRS_EMU_PDP_BBP_MC;


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
} SMU_SID_SMU_INFO_DMRS_LS;


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
} SMU_SID_SMU_INFO_DMRS_LS_BBP_MC;

typedef union {
    struct {
        unsigned int data0_rs_type                                    :   8               ;    /* 7:0 */
        unsigned int data0_cc_idx                                     :   8               ;    /* 15:8 */
        unsigned int data0_rsc_idx                                    :   8               ;    /* 23:16 */
        unsigned int data0_sym_idx                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB0;

typedef union {
    struct {
        unsigned int data1_slot_idx                                   :   8               ;    /* 7:0 */
        unsigned int data1_port_num                                   :   8               ;    /* 15:8 */
        unsigned int data1_rx_num                                     :   8               ;    /* 23:16 */
        unsigned int data1_cp_type                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB1;

typedef union {
    struct {
        unsigned int data6_pilot_d                                    :   8               ;    /* 7:0 */
        unsigned int data6_sym_num                                    :   8               ;    /* 15:8 */
        unsigned int data6_dat_ind                                    :   8               ;    /* 23:16 */
        unsigned int data6_sent_cnt                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB6;

typedef union {
    struct {
        unsigned int data9_ifft_idx                                   :   16              ;    /* 15:0 */
        unsigned int data9_pdc_only_ind                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB9;

typedef union {
    struct {
        unsigned int data10_rsc0_bm_idx                               :   8               ;    /* 7:0 */
        unsigned int data10_rsc1_bm_idx                               :   8               ;    /* 15:8 */
        unsigned int data10_rsc2_bm_idx                               :   8               ;    /* 23:16 */
        unsigned int data10_rsc3_bm_idx                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB10;

typedef union {
    struct {
        unsigned int data11_rsc4_bm_idx                               :   8               ;    /* 7:0 */
        unsigned int data11_rsc5_bm_idx                               :   8               ;    /* 15:8 */
        unsigned int data11_rsc6_bm_idx                               :   8               ;    /* 23:16 */
        unsigned int data11_rsc7_bm_idx                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB11;

typedef union {
    struct {
        unsigned int data12_rsc0_buf_idx                              :   8               ;    /* 7:0 */
        unsigned int data12_rsc1_buf_idx                              :   8               ;    /* 15:8 */
        unsigned int data12_rsc2_buf_idx                              :   8               ;    /* 23:16 */
        unsigned int data12_rsc3_buf_idx                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB12;

typedef union {
    struct {
        unsigned int data13_rsc4_buf_idx                              :   8               ;    /* 7:0 */
        unsigned int data13_rsc5_buf_idx                              :   8               ;    /* 15:8 */
        unsigned int data13_rsc6_buf_idx                              :   8               ;    /* 23:16 */
        unsigned int data13_rsc7_buf_idx                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB13;

typedef union {
    struct {
        unsigned int data15_tfe_task_cnt                              :   8               ;    /* 7:0 */
        unsigned int data15_tfe_task_mode                             :   8               ;    /* 15:8 */
        unsigned int data15_tfe_task_end                              :   8               ;    /* 23:16 */
        unsigned int data15_tfe_sub_task_type                         :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB15;

typedef union {
    struct {
        unsigned int data17_crs_port_sel_rx0                          :   8               ;    /* 7:0 */
        unsigned int data17_crs_port_sel_rx1                          :   8               ;    /* 15:8 */
        unsigned int data17_crs_port_sel_rx2                          :   8               ;    /* 23:16 */
        unsigned int data17_crs_port_sel_rx3                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB17;

typedef union {
    struct {
        unsigned int data18_dsds_bitmap                               :   16              ;    /* 15:0 */
        unsigned int data18_smu_state_bitmap                          :   8               ;    /* 23:16 */
        unsigned int data18_smu_rpt_info                              :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB18;

typedef union {
    struct {
        unsigned int data20_start_re_offset                           :   16              ;    /* 15:0 */
        unsigned int data20_start_dat_offset                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB20;

typedef union {
    struct {
        unsigned int data21_tpa_en                                    :   16              ;    /* 15:0 */
        unsigned int data21_lte_bw                                    :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB21;

typedef union {
    struct {
        unsigned int data30_max_path_win_len                          :   8               ;    /* 7:0 */
        unsigned int data30_noise_win_len                             :   8               ;    /* 15:8 */
        unsigned int data30_noise_est_mod                             :   8               ;    /* 23:16 */
        unsigned int data30_noise_win_start                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB30;

typedef union {
    struct {
        unsigned int data31_pkt_pdp_reset_flag                        :   8               ;    /* 7:0 */
        unsigned int data31_tfe_cmu_en                                :   8               ;    /* 15:8 */
        unsigned int data31_tfe_emu_en                                :   8               ;    /* 23:16 */
        unsigned int data31_emu_max_path_type                         :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB31;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB0                             om_data0;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB1                             om_data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB6                             om_data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8_rsc_num;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB9                             om_data9;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB10                            om_data10;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB11                            om_data11;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB12                            om_data12;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB13                            om_data13;
    unsigned int                                                      data14;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB15                            om_data15;
    unsigned int                                                      data16;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB17                            om_data17;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB18                            om_data18;
    unsigned int                                                      data19_cir_ls_buf_addr;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB20                            om_data20;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB21                            om_data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25_data_type;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB30                            om_data30;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB31                            om_data31;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB0                             om_data0;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB1                             om_data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB6                             om_data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8_rsc_num;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB9                             om_data9;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB10                            om_data10;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB11                            om_data11;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB12                            om_data12;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB13                            om_data13;
    unsigned int                                                      data14;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB15                            om_data15;
    unsigned int                                                      data16;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB17                            om_data17;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB18                            om_data18;
    unsigned int                                                      data19_cir_ls_buf_addr;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB20                            om_data20;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB21                            om_data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25_data_type;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB30                            om_data30;
    SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_SUB31                            om_data31;
} SMU_SID_SMU_INFO_CSI_BM_PKT_HEAD_BBP_MC;


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
} SMU_SID_SMU_INFO_CSI_BM_EMU_PDP;


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
} SMU_SID_SMU_INFO_CSI_BM_EMU_PDP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      compress_data0;
    unsigned int                                                      compress_data1;
    unsigned int                                                      compress_data2;
    unsigned int                                                      compress_data3;
    unsigned int                                                      compress_data4;
    unsigned int                                                      compress_data5;
    unsigned int                                                      compress_data6;
    unsigned int                                                      compress_data7;
    unsigned int                                                      compress_data8;
    unsigned int                                                      compress_data9;
    unsigned int                                                      compress_data10;
    unsigned int                                                      compress_data11;
    unsigned int                                                      compress_data12;
    unsigned int                                                      compress_data13;
    unsigned int                                                      compress_data14;
    unsigned int                                                      compress_data15;
    unsigned int                                                      compress_data16;
    unsigned int                                                      compress_data17;
    unsigned int                                                      compress_data18;
    unsigned int                                                      compress_data19;
    unsigned int                                                      compress_data20;
    unsigned int                                                      compress_data21;
    unsigned int                                                      compress_data22;
    unsigned int                                                      compress_data23;
    unsigned int                                                      compress_data24;
    unsigned int                                                      compress_data25;
    unsigned int                                                      compress_data26;
    unsigned int                                                      compress_data27;
    unsigned int                                                      compress_data28;
    unsigned int                                                      compress_data29;
    unsigned int                                                      compress_data30;
    unsigned int                                                      compress_data31;
    unsigned int                                                      compress_data32;
    unsigned int                                                      compress_data33;
    unsigned int                                                      compress_data34;
    unsigned int                                                      compress_data35;
    unsigned int                                                      compress_data36;
    unsigned int                                                      compress_data37;
    unsigned int                                                      compress_data38;
    unsigned int                                                      compress_data39;
    unsigned int                                                      compress_data40;
    unsigned int                                                      compress_data41;
    unsigned int                                                      compress_data42;
    unsigned int                                                      compress_data43;
    unsigned int                                                      compress_data44;
    unsigned int                                                      compress_data45;
    unsigned int                                                      compress_data46;
    unsigned int                                                      compress_data47;
    unsigned int                                                      compress_data48;
    unsigned int                                                      compress_data49;
    unsigned int                                                      compress_data50;
    unsigned int                                                      compress_data51;
    unsigned int                                                      compress_data52;
    unsigned int                                                      compress_data53;
    unsigned int                                                      compress_data54;
    unsigned int                                                      compress_data55;
    unsigned int                                                      compress_data56;
    unsigned int                                                      compress_data57;
    unsigned int                                                      compress_data58;
    unsigned int                                                      compress_data59;
    unsigned int                                                      compress_data60;
    unsigned int                                                      compress_data61;
    unsigned int                                                      compress_data62;
    unsigned int                                                      compress_data63;
    unsigned int                                                      compress_data64;
    unsigned int                                                      compress_data65;
    unsigned int                                                      compress_data66;
    unsigned int                                                      compress_data67;
    unsigned int                                                      compress_data68;
    unsigned int                                                      compress_data69;
    unsigned int                                                      compress_data70;
    unsigned int                                                      compress_data71;
    unsigned int                                                      compress_data72;
    unsigned int                                                      compress_data73;
    unsigned int                                                      compress_data74;
    unsigned int                                                      compress_data75;
    unsigned int                                                      compress_data76;
    unsigned int                                                      compress_data77;
    unsigned int                                                      compress_data78;
    unsigned int                                                      compress_data79;
    unsigned int                                                      compress_data80;
    unsigned int                                                      compress_data81;
    unsigned int                                                      compress_data82;
    unsigned int                                                      compress_data83;
    unsigned int                                                      compress_data84;
    unsigned int                                                      compress_data85;
    unsigned int                                                      compress_data86;
    unsigned int                                                      compress_data87;
    unsigned int                                                      compress_data88;
    unsigned int                                                      compress_data89;
    unsigned int                                                      compress_data90;
    unsigned int                                                      compress_data91;
    unsigned int                                                      compress_data92;
    unsigned int                                                      compress_data93;
    unsigned int                                                      compress_data94;
    unsigned int                                                      compress_data95;
    unsigned int                                                      compress_data96;
    unsigned int                                                      compress_data97;
    unsigned int                                                      compress_data98;
    unsigned int                                                      compress_data99;
    unsigned int                                                      compress_data100;
    unsigned int                                                      compress_data101;
    unsigned int                                                      compress_data102;
    unsigned int                                                      compress_data103;
    unsigned int                                                      compress_data104;
    unsigned int                                                      compress_data105;
    unsigned int                                                      compress_data106;
    unsigned int                                                      compress_data107;
    unsigned int                                                      compress_data108;
    unsigned int                                                      compress_data109;
    unsigned int                                                      compress_data110;
    unsigned int                                                      compress_data111;
    unsigned int                                                      compress_data112;
    unsigned int                                                      compress_data113;
    unsigned int                                                      compress_data114;
    unsigned int                                                      compress_data115;
    unsigned int                                                      compress_data116;
    unsigned int                                                      compress_data117;
    unsigned int                                                      compress_data118;
    unsigned int                                                      compress_data119;
    unsigned int                                                      compress_data120;
    unsigned int                                                      compress_data121;
    unsigned int                                                      compress_data122;
    unsigned int                                                      compress_data123;
    unsigned int                                                      compress_data124;
    unsigned int                                                      compress_data125;
    unsigned int                                                      compress_data126;
    unsigned int                                                      compress_data127;
} SMU_SID_SMU_INFO_CSI_BM_LS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      compress_data0;
    unsigned int                                                      compress_data1;
    unsigned int                                                      compress_data2;
    unsigned int                                                      compress_data3;
    unsigned int                                                      compress_data4;
    unsigned int                                                      compress_data5;
    unsigned int                                                      compress_data6;
    unsigned int                                                      compress_data7;
    unsigned int                                                      compress_data8;
    unsigned int                                                      compress_data9;
    unsigned int                                                      compress_data10;
    unsigned int                                                      compress_data11;
    unsigned int                                                      compress_data12;
    unsigned int                                                      compress_data13;
    unsigned int                                                      compress_data14;
    unsigned int                                                      compress_data15;
    unsigned int                                                      compress_data16;
    unsigned int                                                      compress_data17;
    unsigned int                                                      compress_data18;
    unsigned int                                                      compress_data19;
    unsigned int                                                      compress_data20;
    unsigned int                                                      compress_data21;
    unsigned int                                                      compress_data22;
    unsigned int                                                      compress_data23;
    unsigned int                                                      compress_data24;
    unsigned int                                                      compress_data25;
    unsigned int                                                      compress_data26;
    unsigned int                                                      compress_data27;
    unsigned int                                                      compress_data28;
    unsigned int                                                      compress_data29;
    unsigned int                                                      compress_data30;
    unsigned int                                                      compress_data31;
    unsigned int                                                      compress_data32;
    unsigned int                                                      compress_data33;
    unsigned int                                                      compress_data34;
    unsigned int                                                      compress_data35;
    unsigned int                                                      compress_data36;
    unsigned int                                                      compress_data37;
    unsigned int                                                      compress_data38;
    unsigned int                                                      compress_data39;
    unsigned int                                                      compress_data40;
    unsigned int                                                      compress_data41;
    unsigned int                                                      compress_data42;
    unsigned int                                                      compress_data43;
    unsigned int                                                      compress_data44;
    unsigned int                                                      compress_data45;
    unsigned int                                                      compress_data46;
    unsigned int                                                      compress_data47;
    unsigned int                                                      compress_data48;
    unsigned int                                                      compress_data49;
    unsigned int                                                      compress_data50;
    unsigned int                                                      compress_data51;
    unsigned int                                                      compress_data52;
    unsigned int                                                      compress_data53;
    unsigned int                                                      compress_data54;
    unsigned int                                                      compress_data55;
    unsigned int                                                      compress_data56;
    unsigned int                                                      compress_data57;
    unsigned int                                                      compress_data58;
    unsigned int                                                      compress_data59;
    unsigned int                                                      compress_data60;
    unsigned int                                                      compress_data61;
    unsigned int                                                      compress_data62;
    unsigned int                                                      compress_data63;
    unsigned int                                                      compress_data64;
    unsigned int                                                      compress_data65;
    unsigned int                                                      compress_data66;
    unsigned int                                                      compress_data67;
    unsigned int                                                      compress_data68;
    unsigned int                                                      compress_data69;
    unsigned int                                                      compress_data70;
    unsigned int                                                      compress_data71;
    unsigned int                                                      compress_data72;
    unsigned int                                                      compress_data73;
    unsigned int                                                      compress_data74;
    unsigned int                                                      compress_data75;
    unsigned int                                                      compress_data76;
    unsigned int                                                      compress_data77;
    unsigned int                                                      compress_data78;
    unsigned int                                                      compress_data79;
    unsigned int                                                      compress_data80;
    unsigned int                                                      compress_data81;
    unsigned int                                                      compress_data82;
    unsigned int                                                      compress_data83;
    unsigned int                                                      compress_data84;
    unsigned int                                                      compress_data85;
    unsigned int                                                      compress_data86;
    unsigned int                                                      compress_data87;
    unsigned int                                                      compress_data88;
    unsigned int                                                      compress_data89;
    unsigned int                                                      compress_data90;
    unsigned int                                                      compress_data91;
    unsigned int                                                      compress_data92;
    unsigned int                                                      compress_data93;
    unsigned int                                                      compress_data94;
    unsigned int                                                      compress_data95;
    unsigned int                                                      compress_data96;
    unsigned int                                                      compress_data97;
    unsigned int                                                      compress_data98;
    unsigned int                                                      compress_data99;
    unsigned int                                                      compress_data100;
    unsigned int                                                      compress_data101;
    unsigned int                                                      compress_data102;
    unsigned int                                                      compress_data103;
    unsigned int                                                      compress_data104;
    unsigned int                                                      compress_data105;
    unsigned int                                                      compress_data106;
    unsigned int                                                      compress_data107;
    unsigned int                                                      compress_data108;
    unsigned int                                                      compress_data109;
    unsigned int                                                      compress_data110;
    unsigned int                                                      compress_data111;
    unsigned int                                                      compress_data112;
    unsigned int                                                      compress_data113;
    unsigned int                                                      compress_data114;
    unsigned int                                                      compress_data115;
    unsigned int                                                      compress_data116;
    unsigned int                                                      compress_data117;
    unsigned int                                                      compress_data118;
    unsigned int                                                      compress_data119;
    unsigned int                                                      compress_data120;
    unsigned int                                                      compress_data121;
    unsigned int                                                      compress_data122;
    unsigned int                                                      compress_data123;
    unsigned int                                                      compress_data124;
    unsigned int                                                      compress_data125;
    unsigned int                                                      compress_data126;
    unsigned int                                                      compress_data127;
} SMU_SID_SMU_INFO_CSI_BM_LS_BBP_MC;

typedef union {
    struct {
        unsigned int data_type                                        :   8               ;    /* 7:0 */
        unsigned int rsc_idx                                          :   8               ;    /* 15:8 */
        unsigned int port_num                                         :   8               ;    /* 23:16 */
        unsigned int rx_num                                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB0;

typedef union {
    struct {
        unsigned int rb_num                                           :   16              ;    /* 15:0 */
        unsigned int pilot_d                                          :   8               ;    /* 23:16 */
        unsigned int sym_num                                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB1;

typedef union {
    struct {
        unsigned int cc_idx                                           :   8               ;    /* 7:0 */
        unsigned int slot_idx                                         :   8               ;    /* 15:8 */
        unsigned int sym_idx                                          :   8               ;    /* 23:16 */
        unsigned int rx_bmap                                          :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB2;

typedef union {
    struct {
        unsigned int slot_gain_r0                                     :   16              ;    /* 15:0 */
        unsigned int slot_gain_r1                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB3;

typedef union {
    struct {
        unsigned int rx_valid                                         :   8               ;    /* 7:0 */
        unsigned int rsv0_0                                           :   8               ;    /* 15:8 */
        unsigned int dat_ind                                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB6;

typedef union {
    struct {
        unsigned int data_vld                                         :   8               ;    /* 7:0 */
        unsigned int rsv1_0                                           :   8               ;    /* 15:8 */
        unsigned int ls_len                                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB7;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB0                              om_data0;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB1                              om_data1;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB2                              om_data2;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB3                              om_data3;
    unsigned int                                                      ls_sft_bit_r0;
    unsigned int                                                      ls_sft_bit_r1;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB6                              om_data6;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB7                              om_data7;
} SMU_SID_SMU_INFO_CSI_BM_LS_HEAD;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB0                              om_data0;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB1                              om_data1;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB2                              om_data2;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB3                              om_data3;
    unsigned int                                                      ls_sft_bit_r0;
    unsigned int                                                      ls_sft_bit_r1;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB6                              om_data6;
    SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_SUB7                              om_data7;
} SMU_SID_SMU_INFO_CSI_BM_LS_HEAD_BBP_MC;

typedef union {
    struct {
        unsigned int data0_rs_type                                    :   8               ;    /* 7:0 */
        unsigned int data0_cc_idx                                     :   8               ;    /* 15:8 */
        unsigned int data0_rsc_idx                                    :   8               ;    /* 23:16 */
        unsigned int data0_sym_idx                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_PARA_PROC_SUB0;

typedef union {
    struct {
        unsigned int data1_slot_idx                                   :   8               ;    /* 7:0 */
        unsigned int data1_port_num                                   :   8               ;    /* 15:8 */
        unsigned int data1_rx_num                                     :   8               ;    /* 23:16 */
        unsigned int data1_cp_type                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_PARA_PROC_SUB1;

typedef union {
    struct {
        unsigned int data6_pilot_d                                    :   8               ;    /* 7:0 */
        unsigned int data6_sym_num                                    :   8               ;    /* 15:8 */
        unsigned int data6_dat_ind                                    :   8               ;    /* 23:16 */
        unsigned int data6_sent_cnt                                   :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_PARA_PROC_SUB6;

typedef union {
    struct {
        unsigned int data9_ifft_idx                                   :   16              ;    /* 15:0 */
        unsigned int data9_pdc_only_ind                               :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} SMU_SID_SMU_INFO_PARA_PROC_SUB9;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    SMU_SID_SMU_INFO_PARA_PROC_SUB0                                   om_data0;
    SMU_SID_SMU_INFO_PARA_PROC_SUB1                                   om_data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    SMU_SID_SMU_INFO_PARA_PROC_SUB6                                   om_data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8_rsc_num;
    SMU_SID_SMU_INFO_PARA_PROC_SUB9                                   om_data9;
} SMU_SID_SMU_INFO_PARA_PROC;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    SMU_SID_SMU_INFO_PARA_PROC_SUB0                                   om_data0;
    SMU_SID_SMU_INFO_PARA_PROC_SUB1                                   om_data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    SMU_SID_SMU_INFO_PARA_PROC_SUB6                                   om_data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8_rsc_num;
    SMU_SID_SMU_INFO_PARA_PROC_SUB9                                   om_data9;
} SMU_SID_SMU_INFO_PARA_PROC_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
