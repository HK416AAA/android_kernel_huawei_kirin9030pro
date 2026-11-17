#ifndef __DDR_DATA_STRUCT_H__
#define __DDR_DATA_STRUCT_H__ 
#include <ddr_define.h>
#ifndef DDR_UEFI_VERSION
#include <types.h>
#else
#include <Ddr/DdrUefiTypes.h>
#endif
#include <stdint.h>
#include "ddr_reg_ops/ddr_reg_op_qice_extend.h"
#include "soc_ddr_pack_interface.h"
#include "soc_ddr_phy_interface.h"
#include <ddr/ddr_capacity_adaption.h>
#include "soc_efuse_interface.h"
#define DDR_PARA_VERSION 0x36D0003B
typedef struct {
 unsigned int matrix_bg_0 : 6;
 unsigned int matrix_bg_1 : 6;
 unsigned int matrix_ba_0 : 6;
 unsigned int matrix_ba_1 : 6;
 unsigned int matrix_ba_2 : 6;
} matrix_ohot_0_str;
typedef struct {
 unsigned int matrix_ra_0 : 6;
 unsigned int matrix_ch_0 : 6;
 unsigned int matrix_lr_0 : 6;
 unsigned int matrix_col_0 : 6;
 unsigned int matrix_col_1 : 6;
} matrix_ohot_1_str;
typedef struct {
 unsigned int matrix_col_2 : 6;
 unsigned int matrix_col_3 : 6;
 unsigned int matrix_col_4 : 6;
 unsigned int matrix_col_5 : 6;
 unsigned int matrix_col_6 : 6;
} matrix_ohot_2_str;
typedef struct {
 unsigned int matrix_col_7 : 6;
 unsigned int matrix_col_8 : 6;
 unsigned int matrix_col_9 : 6;
 unsigned int matrix_col_10 : 6;
 unsigned int matrix_row_0 : 6;
} matrix_ohot_3_str;
typedef struct {
 unsigned int matrix_row_1 : 6;
 unsigned int matrix_row_2 : 6;
 unsigned int matrix_row_3 : 6;
 unsigned int matrix_row_4 : 6;
 unsigned int matrix_row_5 : 6;
} matrix_ohot_4_str;
typedef struct {
 unsigned int matrix_row_6 : 6;
 unsigned int matrix_row_7 : 6;
 unsigned int matrix_row_8 : 6;
 unsigned int matrix_row_9 : 6;
 unsigned int matrix_row_10 : 6;
} matrix_ohot_5_str;
typedef struct {
 unsigned int matrix_row_11 : 6;
 unsigned int matrix_row_12 : 6;
 unsigned int matrix_row_13 : 6;
 unsigned int matrix_row_14 : 6;
 unsigned int matrix_row_15 : 6;
} matrix_ohot_6_str;
typedef struct {
 unsigned int matrix_row_16 : 6;
 unsigned int matrix_row_17 : 6;
} matrix_ohot_7_str;
typedef struct {
 matrix_ohot_0_str matrix_ohot_0;
 matrix_ohot_1_str matrix_ohot_1;
 matrix_ohot_2_str matrix_ohot_2;
 matrix_ohot_3_str matrix_ohot_3;
 matrix_ohot_4_str matrix_ohot_4;
 matrix_ohot_5_str matrix_ohot_5;
 matrix_ohot_6_str matrix_ohot_6;
 matrix_ohot_7_str matrix_ohot_7;
} matrix_ohot_member_str;
typedef struct {
 unsigned int matrix_0;
 unsigned int matrix_1;
 unsigned int matrix_2;
 unsigned int matrix_3;
 unsigned int matrix_4;
 unsigned int matrix_5;
 unsigned int matrix_6;
 unsigned int matrix_7;
 unsigned int matrix_bg_xor_0;
 unsigned int matrix_bg_xor_1;
 unsigned int matrix_ba_xor_0;
 unsigned int matrix_ba_xor_1;
 unsigned int matrix_ba_xor_2;
 unsigned int matrix_ra_xor_low;
 unsigned int matrix_ra_xor_high;
 unsigned int matrix_ch_xor_0;
 unsigned int matrix_lr_xor_0;
 unsigned int matrix_col_xor_0;
 unsigned int matrix_col_xor_1;
} matrix_val_str;
typedef union {
 matrix_ohot_member_str matrix_member;
 matrix_val_str matrix_val;
} matrix_ohot_val_uni;
typedef struct {
 unsigned int density;
 unsigned int size_mbyte;
 unsigned int range_mbyte;
 unsigned int bank;
 unsigned int row;
 unsigned int col;
 unsigned int io_width;
} ddr_density_rbc_str;
typedef struct {
 unsigned int physical_seg_num;
 unsigned int physical_segs[PHYSICAL_SEG_MAX_NUM];
 unsigned int total_size_mbyte;
 unsigned int total_range_mbyte;
 unsigned int rank_num;
 unsigned int manufactory_id;
 unsigned int revision_id1;
 unsigned int revision_id2;
 unsigned int dram_mr0;
 ddr_density_rbc_str density_rbc[RANK_MAX_NUM];
} ddr_channel_info_str;
typedef struct {
 unsigned int ddr_type;
 unsigned int ddr_sub_type;
 unsigned int total_size_mbyte;
 unsigned int channel_num;
 unsigned int channel_mask;
 ddr_channel_info_str ch_info[CHANNEL_MAX_NUM];
 unsigned int trefi_coef;
} ddr_target_info_str;
typedef struct {
 unsigned char dram_ac_vref_rank_num[CHANNEL_MAX_NUM];
 unsigned char dram_dq_vref_rank_num[CHANNEL_MAX_NUM];
 unsigned char host_dq_vref_rank_num[CHANNEL_MAX_NUM];
 unsigned char dram_ac_vref_bytelane_num[CHANNEL_MAX_NUM];
 unsigned char dram_dq_vref_bytelane_num[CHANNEL_MAX_NUM];
 unsigned char host_dq_vref_bytelane_num[CHANNEL_MAX_NUM];
} ddr_vref_num_info_str;
typedef struct {
 unsigned int addr0_bdl: 10;
 unsigned int addr1_bdl: 10;
 unsigned int addr2_bdl: 10;
 unsigned int addr3_bdl: 10;
 unsigned int addr4_bdl: 10;
 unsigned int addr5_bdl: 10;
 unsigned int addr6_bdl: 10;
 unsigned int addrph_a: 8;
 unsigned int ck_bdl: 10;
 unsigned int rxck_bdl: 10;
 unsigned int rxcs0_bdl: 10;
 unsigned int cmd1tph: 8;
 unsigned int cs0_bdl: 10;
 unsigned int cke0_bdl: 10;
 unsigned int cs1_bdl: 10;
 unsigned int cke1_bdl: 10;
 unsigned int ca_90degree_delay_dq_en_0_5: 8;
 unsigned int ca_90degree_delay_dq_en_6_7: 4;
 unsigned int ca_90degree_delay_dq_en_8_9: 4;
 unsigned int ca_90degree_inverse_dq: 10;
 unsigned int ca_90degree_inverse_dqs: 10;
 unsigned int reserved1: 32;
} ddr_train_result_str;
typedef struct {
 unsigned int dxctl_wck_rank_offset: 4;
 unsigned int rst_g_len: 4;
 unsigned int dxctl_rx_ie_extend: 4;
 unsigned int rdqsbdl: 10;
 unsigned int rdqscyc: 10;
 unsigned int dx_odtctrl1: 32;
 unsigned int dxctl_bypass: 32;
 unsigned int dx_rx_set: 32;
 unsigned int dx_pectrl1: 32;
 unsigned int dx_iorefctrl0: 32;
 unsigned int dx_iorefctrl1: 32;
 unsigned int dx_iorefctrl2: 32;
 unsigned int dx_gate_err: 32;
 unsigned int dx_xrank_ctrl_0: 32;
 unsigned int dx_xrank_ctrl_1: 32;
 unsigned int DX_IO_PUPDMODE_DQS: 2;
 unsigned int wdq_90degree_delay_dq_en_0_7: 10;
 unsigned int wdq_90degree_delay_dq_en_8: 2;
 unsigned int wdq_90degree_inverse_dq: 10;
 unsigned int wdq_90degree_inverse_dqs: 10;
 unsigned int wdq_90degree_inverse_wck: 10;
 unsigned int dx_dqsdm_ctlesstl_cal;
 unsigned int dx_dq01_ctlesstl_cal;
 unsigned int dx_dq23_ctlesstl_cal;
 unsigned int dx_dq45_ctlesstl_cal;
 unsigned int dx_dq67_ctlesstl_cal;
 unsigned int reserved1: 32;
} ddr_train_result_n_str;
typedef struct {
 unsigned int wdq0bdl: 10;
 unsigned int wdq1bdl: 10;
 unsigned int wdq2bdl: 10;
 unsigned int wdq3bdl: 10;
 unsigned int wdq4bdl: 10;
 unsigned int wdq5bdl: 10;
 unsigned int wdq6bdl: 10;
 unsigned int wdq7bdl: 10;
 unsigned int wdmbdl: 10;
 unsigned int oen_bdl: 10;
 unsigned int wdqsoe_bdl: 10;
 unsigned int rdqsbdl30: 10;
 unsigned int bdl_mondly: 10;
 unsigned int wdqsbdl: 8;
 unsigned int wdqsphase: 6;
 unsigned int wdqsbdl_msb: 2;
 unsigned int wdqphase: 8;
 unsigned int wlsl: 2;
 unsigned int gds: 4;
 unsigned int org_rdqsgph: 10;
 unsigned int rdqsgbdl: 8;
 unsigned int rdqsgphase: 10;
 unsigned int rdqsgbdl_msb: 2;
 unsigned int rdqsgtxbdl_msb: 2;
 unsigned int rdqsgtxbdl: 8;
 unsigned int hvreft_status: 8;
 unsigned int advref_status: 8;
 unsigned int dvreft_status: 8;
 unsigned int dx_txdcc_pdn_ctrl1: 32;
 unsigned int dx_txdcc_ndn_ctrl3: 32;
 unsigned int dx_txdcc_pup_ctrl1: 32;
 unsigned int dx_txdcc_nup_ctrl3: 32;
 unsigned int dx_rxdcc_pdn_ctrl0: 32;
 unsigned int dx_rxdcc_pdn_ctrl1;
 unsigned int dx_rxdcc_ndn_ctrl2;
 unsigned int dx_rxdcc_ndn_ctrl3;
 unsigned int dx_rxdcc_pup_ctrl0;
 unsigned int dx_rxdcc_pup_ctrl1;
 unsigned int dx_rxdcc_nup_ctrl2;
 unsigned int dx_rxdcc_nup_ctrl3;
 unsigned int reserved1: 32;
 unsigned int reserved2: 32;
} ddr_train_result_m_n_str;
typedef struct {
 unsigned int rdq0bdl: 10;
 unsigned int rdq1bdl: 10;
 unsigned int rdq2bdl: 10;
 unsigned int rdq3bdl: 10;
 unsigned int rdq4bdl: 10;
 unsigned int rdq5bdl: 10;
 unsigned int rdq6bdl: 10;
 unsigned int rdq7bdl: 10;
 unsigned int rdmbdl: 10;
} ddr_train_result_l_m_n_str;
typedef struct {
 ddr_train_result_str train_result;
 ddr_train_result_n_str train_result_n[BYTELANE_MAX_NUM];
 ddr_train_result_m_n_str train_result_m_n[RANK_MAX_NUM][BYTELANE_MAX_NUM];
 ddr_train_result_l_m_n_str train_result_l_m_n[EDGETYPE_MAX_NUM][RANK_MAX_NUM][BYTELANE_MAX_NUM];
 u32 avs_rtc_time;
 u32 avs_volt;
 u32 dram_vdd2_volt;
 u8 avs_temp_recoup[DDR_AVS_TEMP_RECOUP_NUM];
 u32 section_impstatus[DDR_SECTION_MAX_NUM];
 u16 section_rdqscyc[BYTELANE_MAX_NUM][DDR_SECTION_MAX_NUM];
 u32 section_rdqscyc_actual_num;
 u32 dx_oebdl_ctl0[BYTELANE_MAX_NUM];
 u8 dca_code[RANK_MAX_NUM];
 u8 rdca_code[RANK_MAX_NUM];
 u32 ck_phydcc_status;
 u32 wdqs_phydcc_status[RANK_MAX_NR][BYTELANE_MAX_NUM];
 u32 impstatus;
 u32 section_dfs_factor[BYTELANE_MAX_NUM];
 u32 osc_count[RANK_MAX_NR];
 u32 rdqscyc;
 int linear_fit_ca_ck_diff;
 int vdd2h_volt_delta;
 u32 rdq_input_mode : 3;
 u32 reserved0 : 29;
 u32 reserved1;
} ddr_train_param;
typedef struct {
 u32 hash256_code[CRC_SHA256_OUTLEN];
} ddr_restore_para_head;
#define DIEID_GROUP_SIZE ((EFUSE_DIEID_VALUE_SIZE) / (DDR_NORMAL_REG_BITNUM))
struct ddr_restore_common_info {
 u32 version;
 u32 error_id;
 u32 rtc_time;
 u32 number_of_freq;
 u32 dieid[DIEID_GROUP_SIZE];
 u32 avs_rtc_time;
 u32 avs_volt[LPMCU_FREQ_NUM_MAX];
 u32 dram_vdd2_volt;
 u8 avs_temp_recoup[DDR_AVS_TEMP_RECOUP_NUM];
 u32 vddcore_volt[LPMCU_FREQ_NUM_MAX];
 u32 reserved[22];
};
#define LPRX_SSTL_FLAG_SIZE 2U
#define LPRX_SSTL_FLAG_418 0U
#define LPRX_SSTL_FLAG_749 1U
struct ddr_aging_info {
 unsigned int eye_area_count_rdq[RANK_MAX_NUM][CHANNEL_MAX_NUM][BYTELANE_MAX_NUM];
 unsigned int rdqscyc[RANK_MAX_NUM][CHANNEL_MAX_NUM][BYTELANE_MAX_NUM];
 unsigned int lprx_sstl_flag[LPRX_SSTL_FLAG_SIZE];
 unsigned int init_temp;
 unsigned int worst_dieid;
 unsigned int eye_area_ratio;
 unsigned int norm_min_eye_area_rdq[RANK_MAX_NUM];
 unsigned int rdca_code;
 unsigned int dcc_exce;
 unsigned int rdqs_dcc_code;
 unsigned int wck_dca_code;
 unsigned int reserved[5];
};
struct ddr_store_data {
 ddr_restore_para_head restore_head;
 struct ddr_restore_common_info common_info;
 struct ddr_aging_info aging_info;
 ddr_train_param train_param[CHANNEL_MAX_NUM][DDR_TRAIN_PARAM_NUM_MAX];
 struct ddr_aging_info mntn_aging_info;
};
typedef struct {
 u8 dcc_p_up;
 u8 dcc_n_up;
 u8 dcc_p_dn;
 u8 dcc_n_dn;
} ddr_dcc_cfg_str;
#define RETRAIN_DISABLE 0
#define RETRAIN_NORMAL 1
#define RETRAIN_SOFTWARE 2
#define RETRAIN_TRFC 3
typedef struct {
 u32 dmc_lp_asref : 1;
 u32 dmc_lp_pd : 1;
 u32 dmc_lp : 1;
 u32 ddr_dfs : 1;
 u32 l1bus_dfs : 1;
 u32 dmc_tmon_monitor : 1;
 u32 dmc_tmon_record : 1;
 u32 dmc_tmon_reboot : 1;
 u32 dmc_tmon_shake_noreboot : 1;
 u32 tmon_for_x8 : 1;
 u32 use_tuf : 1;
 u32 ddr_sref_abort : 1;
 u32 brstlen : 2;
 u32 rd_otf_en : 1;
 u32 wr_otf_en : 1;
 u32 bl32atonthefly : 1;
 u32 dmc_cfg_aref_opt : 1;
 u32 dmc_ram_pd : 1;
 u32 pll_lock_err_en : 1;
 u32 pack_zcalrt : 1;
 u32 cpu_fast_wakeup_rank_en : 1;
 u32 cpu_fast_wakeup_ch_en : 1;
 u32 uce_init : 1;
 u32 uce_retrain : 1;
 u32 uce_dfs : 1;
 u32 dmc_int_autogt_en : 1;
 u32 dmc_ext_autogt_en : 1;
 u32 dmss_ext_autogt_en : 1;
 u32 ddr_singlend_en : 1;
 u32 dmss_dyn_ckg : 1;
 u32 wl_enhancement_en : 1;
 u32 per_bit_track_en : 1;
 u32 reg_dlyline_gate_bypass : 1;
 u32 ddr_12_phase_en : 1;
 u32 rd_wr_fasttrain_opt : 1;
 u32 cat_eyet_rb_opt : 1;
 u32 dfi_sel_err_en : 1;
 u32 dvalid_err_int_en : 1;
 u32 dfs_one_step : 1;
 u32 dfs_vote_l1bus_en: 1;
 u32 dfs_ddr_l1bus_linkage_en : 1;
 u32 l1bus_flux_monitor_en : 1;
 u32 dfs_time_debug: 1;
 u32 dfs_backpress_time_debug: 1;
 u32 ddr_stat_lp_en: 1;
 u32 ddr_stat_freq_vote_en: 1;
 u32 ddr_stat_freq_time_en: 1;
 u32 ddr_stat_bandwidth_mntn_en: 1;
 u32 ddr_stat_bandwidth_trans_en: 1;
 u32 ddr_stat_latency_mntn_en : 1;
 u32 ddr_latency_monitor_en : 1;
 u32 pbr_en : 1;
 u32 exmbist_wrap_clken : 1;
 u32 exmbist_apb_clken : 1;
 u32 ddr_force_3200mhz : 1;
 u32 pll_lock_lp_err_en : 1;
 u32 oscillator_en : 1;
 u32 restore_en : 2;
 u32 ddr_lowtemp_en : 1;
 u32 ddr_avs_en : 1;
 u32 ddr_flow_control_en : 1;
 u32 ddr_avs_temp_recoup : 1;
 u32 ddr_avs_pasensor_en : 1;
 u32 single_rank_en : 1;
 u32 efr_volt_comp : 1;
 u32 ddr_lowbattery_en : 1;
 u32 gate_err_int_en : 1;
 u32 dvs_swift_tracking_en : 1;
 u32 dlm_swift_track_en : 1;
 u32 rdet_swift_track_en : 1;
 u32 gt_swift_track_en : 1;
 u32 swift_dfx_en : 1;
 u32 swfit_sref_backpress_en : 1;
 u32 swfit_track_threshold_auto_en : 1;
 u32 writex1_en : 1;
 u32 dfi_access_gt_bypass : 1;
 u32 ddr_lp_feature_en : 1;
 u32 ca_wr_en : 1;
 u32 cas_bc_en : 1;
 u32 writex_en : 1;
 u32 wck_on : 1;
 u32 always_on_mode : 1;
 u32 fn_sc_ppll1_sel : 1;
 u32 osc_small_en : 1;
 u32 dum_small_en : 1;
 u32 tmon_small_en : 1;
 u32 page_timeout_en : 1;
 u32 page_adpt_en : 1;
 u32 wrconverge_en : 1;
 u32 byp_rd_en : 1;
 u32 byp_act_en : 1;
 u32 wr_intlv_en : 1;
 u32 rd_intlv_en : 1;
 u32 ddrc_buf_gt : 1;
 u32 perf_en : 1;
 u32 perf_clk_en : 1;
 u32 pdx_byp_uni : 1;
 u32 pd_exit_opt : 1;
 u32 grp_break_rhit : 1;
 u32 grp_rw_en : 1;
 u32 dsm_en : 1;
 u32 init_lowtemp_fake : 1;
 u32 ddr_wakeup_en : 1;
 u32 priadpt_en : 1;
 u32 addr_push_en : 1;
 u32 mid_push_en : 1;
 u32 sbr_idle_en : 1;
 u32 init_lowbattery_fake : 1;
 u32 grp_flat_en : 1;
 u32 rhit_break_en : 1;
 u32 gbuf_en : 1;
 u32 iecc_en : 1;
 u32 rasc_en : 1;
 u32 wdata_intv_en : 1;
 u32 fast_pdx_en : 1;
 u32 pdx_opt_en : 1;
 u32 bhs_en : 1;
 u32 ch24_intlv_en : 1;
 u32 vdd2_avs_enable : 1;
 u32 trefi_adjust_en : 1;
 u32 bhs_req_neg_chken : 1;
 u32 bhs_efuse_en : 1;
 u32 plldis_en : 1;
 u32 dcc_bypass_en : 1;
 u32 das_enable : 1;
 u32 halt_escape : 1;
 u32 da_antiaging_en : 1;
 u32 sc_workaround_en : 1;
 u32 ppr_by_remap_en : 1;
 u32 apre_en : 1;
 u32 ddr_static_pasr_en : 1;
 u32 fake_penglai_en : 1;
 u32 global_clkon_en : 1;
 u32 qtpem_en : 1;
 u32 vco_freq_rise : 1;
 u32 ddr_dpm_en : 1;
 u32 is_ull_lit_cpu : 1;
 u32 is_ull_mid_cpu : 1;
 u32 is_ull_big_cpu : 1;
 u32 lprx_sstl_switch_en : 1;
 u32 ull_mpam_enable : 1;
} ddr_feature;
typedef struct {
 u32 l1bus_dfs : 1;
 u32 cpu_fast_wakeup_rank_en : 1;
 u32 cpu_fast_wakeup_ch_en : 1;
 u32 dmss_dyn_ckg : 1;
} l1bus_feature;
#ifdef FREQ_VOLT_RANGE
#if FREQ_VOLT_RANGE != 8
#error "FREQ_VOLT_RANGE must be number of core_base_vol[]!!!"
#endif
#endif
typedef struct {
 u16 core_base_vol[8];
 u16 vddqh_base_vol;
 u16 vddql_base_vol;
 u16 vdd2_base_vol;
 u16 vdd2h_base_vol;
 u16 vdd2l_base_vol;
 u16 vdd1_base_vol;
 u16 pll_base_vol;
 u16 mem_base_vol;
 u16 soc_phypll_base_vol;
 u32 current_core_idx;
} ddr_vol_base_cfg_str;
typedef struct {
 u32 target_freq : 4;
 u32 min_freq : 4;
 u32 max_freq : 4;
 u32 sleep_freq : 4;
 u32 lowtemp_min_freq : 4;
 u32 lowtemp_max_freq : 4;
 u32 lowbattery_freq : 4;
 u32 init_mode : 2;
 u32 training_mode : 1;
 u32 read_mode : 1;
 u32 ddr_wakeup_prd : 9;
 u32 bl_data : 4;
 u32 pd_prd : 15;
 u32 openpage_time : 14;
 u32 force_lowtemp : 1;
 u32 ddr_avs_trim_period : 8;
 u32 tphy_wrdata : 1;
 u32 tphy_wrdata_ext : 2;
 u32 dqsgsl_mrgn : 8;
 u32 trdlat : 4;
 u32 aref_rate : 4;
 u32 phyif_tim_wden : 8;
 u32 phyif_tim_wdda : 8;
 u32 phyif_tim_oven : 8;
 u32 phyif_tim_rden : 8;
 u32 phyif_tim_wck : 8;
 u32 asref_prd : 16;
 u8 tmon_period;
 u32 wrcmd_converge_lvl : 8;
 u32 wr_pre : 2;
 u32 wr_pst_en : 1;
 u32 dram_wr_pst : 2;
 u32 dram_rpst_mode : 1;
 u32 dram_rpst : 2;
 u32 dram_rdqs_pre : 2;
 u32 reg_DA_PREAM_TM_DQS : 2;
 u32 reg_DX_DQS_RG_PRESET_DQS : 2;
 u32 page_win_size : 8;
 u32 rhit_break_level : 7;
 u32 trefi_coef : 11;
 u32 ddr_latency_up_threhold : 8;
 u32 ddr_latency_down_threhold : 8;
 u32 latency_monitor_times : 4;
 u32 is_ohot_matrix : 2;
 matrix_ohot_val_uni matrix_ohot_val;
 matrix_ohot_val_uni matrix_ohot_val_bd;
 ddr_vol_base_cfg_str vol_base_cfg;
} ddr_init_info;
typedef struct {
 u32 target_freq : 4;
 u32 min_freq : 4;
 u32 max_freq : 4;
 u32 sleep_freq : 4;
 u32 intlv_mode : 2;
 u32 lowtemp_min_freq : 4;
 u32 lowtemp_max_freq : 4;
 u32 lowbattery_freq : 4;
 u32 scramb_en : 2;
 u32 ddr_channel_mode : 2;
 u32 dcache_mode : 2;
 u32 qice_flux_interval_min : 8;
 u32 qice_flux_interval_max : 8;
 u32 qice_flux_timer_interval : 8;
} l1bus_init_info;
typedef struct {
 u32 wck_ron : 3;
 u32 wck_pre : 1;
 u32 wck_pre_1 : 1;
 u32 wck_pe_c : 3;
 u32 wck_soc_txrx_weak_pull_down : 1;
 u32 wck_dram_odt_1rank : 3;
 u32 wck_dram_odt_rank0 : 3;
 u32 wck_dram_odt_rank1 : 3;
 u32 wck_soc_output_mode : 2;
 u32 wck_dram_output_mode : 2;
 u32 wck_soc_vref_en : 1;
 u32 dqs_pupd_mode : 1;
} wck_io_cfg_str;
typedef struct {
 u32 wdq_ron : 3;
 u32 wdq_pre : 1;
 u32 wdq_pre_1 : 1;
 u32 wdq_pe_c : 3;
 u32 wdq_soc_txrx_weak_pull_down : 1;
 u32 wdq_dram_odt_1rank : 3;
 u32 wdq_dram_odt : 3;
 u32 wdq_dram_nt_odt : 3;
 u32 wdq_dram_nt_odt_en : 1;
 u32 wdq_vref : 7;
 u32 wdq_pu_cal : 3;
 u32 wdq_dbi : 2;
 u32 dram_dfe : 3;
} wdq_io_cfg_str;
typedef struct {
 u32 dram_dq_emphasis : 8;
 u32 rdqs_puds : 3;
 u32 rdqs_puds_enh : 3;
 u32 rdqs_pdds : 3;
 u32 rdqs_pdds_enh : 3;
 u32 rdqs_soc_odt_1rank : 3;
 u32 rdqs_soc_odt : 3;
 u32 rdqs_soc_odt_en : 1;
 u32 rdqs_rg_eq_c : 5;
 u32 rdqs_rg_eq_rp : 6;
 u32 rdqs_rg_sq_di : 3;
 u32 rdqs_soc_input_mode : 3;
 u32 rdqs_dram_input_mode : 2;
 u32 rdqs_soc_vref_en : 1;
 u32 rdqs_ctle_d2s_current_boost : 1;
} rdqs_io_cfg_str;
typedef struct {
 u32 rdq_soc_odt_1rank : 3;
 u32 rdq_soc_odt : 3;
 u32 rdq_soc_odt_en : 1;
 u32 rdq_soc_dummy_odt_en : 1;
 u32 rdq_input_mode : 3;
 u32 rdq_dummy_input_mode : 2;
 u32 rdq_bias_en : 12;
 u32 rdq_dummy_bias_en : 12;
 u32 rdq_eq_c : 8;
 u32 rdq_eq_rp : 8;
 u32 rdq_soc_offset : 5;
 u32 rdq_vref : 6;
 u32 rdq_vref_enh : 6;
 u32 rdq_soc_vref_en : 1;
 u32 rdq_dbi : 2;
 u32 sio_refsel : 1;
 u32 dio_refsel : 2;
 u32 rdq_ctle_d2s_current_boost : 3;
} rdq_io_cfg_str;
typedef struct {
 u32 ck_ron : 3;
 u32 ck_pre : 2;
 u32 ck_pe_c : 3;
 u32 ck_soc_txrx_weak_pull_down : 1;
 u32 ck_dram_odt_dis : 1;
 u32 ca_dram_odt : 3;
 u32 ck_soc_output_mode : 2;
 u32 ck_dram_output_mode : 1;
 u32 ck_soc_vref_en : 1;
} ck_io_cfg_str;
typedef struct {
 u32 ca_ron : 3;
 u32 ca_pre : 2;
 u32 ca_pe_c : 3;
 u32 ca_soc_txrx_weak_pull_down : 1;
 u32 ca_dram_odt_dis : 1;
 u32 ca_vref : 7;
 u32 ca_soc_vref_en : 1;
} ca_io_cfg_str;
typedef struct {
 u32 sfio_ron : 3;
 u32 sfio_pg_en : 6;
 u32 sfio_ng_enb : 6;
 u32 reset_ron : 9;
} sfio_cfg_str;
typedef struct {
 wck_io_cfg_str wck_io_cfg;
 wdq_io_cfg_str wdq_io_cfg;
 rdqs_io_cfg_str rdqs_io_cfg;
 rdq_io_cfg_str rdq_io_cfg;
 ck_io_cfg_str ck_io_cfg;
 ca_io_cfg_str ca_io_cfg;
 sfio_cfg_str sfio_cfg;
} ddr_io_profile;
#ifdef DDR_SCENE_ID_MAX
#if DDR_SCENE_ID_MAX != 5
#error "DDR_SCENE_ID_MAX must be number of core_vol_value[]!!!"
#endif
#endif
typedef struct {
 u8 l1bus_vol_bitmap[2];
 u8 l1bus_mem_vol_bitmap[2];
} l1bus_vol_cfg_str;
typedef struct {
 u8 core_vol_traning_bitmap;
 u8 core_vol_bitmap_for_second;
 u8 core_vol_bitmap[2];
 u16 core_vol_value[5];
 u16 core_vol_base_value[5];
 u16 core_vol_support_max;
 u16 vdd2_vol_value[2];
 u16 vddq_vol_value;
 u16 vddhv_vol_value;
 u8 core_mem_vol_bitmap[2];
} ddr_vol_cfg_str;
typedef struct {
 u16 pasensor_volt;
 u16 volt_uplimit;
} avs_cfg_ddr_str;
typedef struct {
 u32 cbt_en : 1;
 u32 cs_prefix_en : 2;
 u32 reserved : 2;
 u32 sw_hw_vreft_en : 2;
 u32 sw_hw_cst_en : 2;
 u32 cat_90degree : 1;
 u32 cat_ph_step : 8;
 u32 cat_open_bdl_jstep : 8;
 u32 cat_samp_num_bdl1 : 6;
 u32 vreft_no_dec : 1;
 u32 vreft_dborg : 1;
 u32 cat_lb_backtap : 8;
 u32 cat_re_deskew_en : 1;
 u32 cat_rb2nd_fine_en : 1;
 u32 dvreft_hckpts : 6;
 u32 cat_deskew_step : 8;
 u32 cat_ct_scan_step : 8;
 u32 cat_samp_num_bdl2 : 6;
 u32 cat_ds_en : 1;
 u32 cat_ct_en : 1;
 u32 cat_bdl_step : 6;
 u32 cs_course_step : 6;
} cat_step_cfg_str;
typedef struct {
 u32 rdet_vref_offset_en : 1;
 u32 dram_vref_thres : 4;
 u32 host_vref_thres : 4;
 u32 host_dq_train_en : 2;
 u32 dram_dq_train_en : 2;
 u32 host_dq_2ndtrain_en : 1;
 u32 wck_dcc_en : 1;
 u32 wck_dca_en : 1;
 u32 wl_single_rank : 1;
 u32 rdqs_dcc_en : 1;
 u32 rdqs_dca_en : 1;
 u32 rdqs_dca_by_rdq_similar_area_en : 1;
 u32 rdqn_dcc_en : 1;
 u32 rdqn_dcc_from_rdqs_en : 1;
 u32 wck_dca_by_rdq_en : 1;
 u32 rdqs_dcc_by_rdq_en : 1;
 u32 rdq_dcc_second_en : 1;
 u32 rdet_freq_compensate_index : 3;
 u32 gt_ph_step : 4;
 u32 gt_bdl_step : 4;
 u32 gt_90bdl_step_en : 1;
 u32 gt_bpt_step_en : 1;
 u32 gds_margin_sel : 3;
 u32 gds_single_rank : 1;
 u32 gt_ph_fine_step : 3;
 u32 rbound_sfal_en : 1;
 u32 wl_fine_bdl_step : 4;
 u32 rdqs_ori_ratio : 8;
 u32 perbit_rdqs_ori_ratio : 8;
 u32 rdet_rb_backtap : 9;
 u32 rdet_ct_dqs_en : 1;
 u32 row_react_period_offset : 2;
 u32 rdet_dq_scan_step : 4;
 u32 rdet_lb_backtap : 6;
 u32 rdet_lb_ctdone_stop : 1;
 u32 evenodd_en : 1;
 u32 rdet_bdl_step : 2;
 u32 rdet_samp_num : 8;
 u32 rdet_trysamp_num : 8;
 u32 rdet_ph_step : 6;
 u32 rdet_fine_step : 6;
 u32 wdet_ph_step : 8;
 u32 wdet_dq_scan_step : 5;
 u32 wdet_ph_fine_step : 8;
 u32 wdet_samp_num : 8;
 u32 wdet_trysamp_num : 2;
 u32 wdet_lb_backtap : 5;
 u32 wdet_bdl_step : 2;
 u32 wdet_lb_ctdone_stop : 1;
 u32 wdet_rb_backtap : 5;
 u32 perbit_full_vref_scan : 1;
 u32 wdet_ct_dqs_en : 1;
 u32 wdet_ds_en : 1;
 u32 wdet_open_bdl_jstep : 5;
 u32 half_ph_bdl_en : 1;
 u32 wdet_rb2nd_fine_en : 1;
 u32 reserved5 : 2;
 u32 rdqdcc_coar_step : 8;
 u32 rdqdcc_back_step : 8;
 u32 rdqdcc_fine_step : 6;
 u32 wl_en : 2;
 u32 wl_origin_ck_ratio : 8;
 u32 wl_bdl_backtap : 8;
 u32 bdlcarry_done : 1;
 u32 wdet_90degree : 1;
 u32 wl_falledge_bdl_jstep_r : 10;
 u32 reserved7 : 3;
 u32 wl_coarse_bdl_step : 4;
 u32 wdet_mpc_cnt : 4;
 u32 rpat_cnt_num_open : 6;
 u32 rpat_cnt_num : 6;
 u32 gt_en : 1;
 u32 gdst_en : 1;
 u32 rdet_nocrosstalk_en : 1;
 u32 rdet_clear_in_rightscan : 1;
 u32 wdet_crosstalk_pat_enh_en : 1;
 u32 rdet_open_bdl_jstep : 8;
 u32 dcc_use_last_freq : 1;
} dqt_cfg_str;
typedef struct {
 u8 one_phase_code : 6;
 u8 wdert_check_step : 4;
 u8 wdert_shift_step : 4;
 u8 wdert_bdl_check_step : 4;
 u8 wdert_bdl_shift_step : 6;
 u8 rdert_step : 4;
 u8 wdert_mpc_cnt : 4;
 u8 wdert_bdl_mode : 1;
} retrain_cfg_str;
typedef struct {
 u32 valid : 1;
 u32 byp_mode : 1;
 u32 plldis_en : 1;
 u32 ocldo_mode : 2;
 u32 pd_en : 1;
 u32 lp_prd : 15;
 u32 wck_on : 1;
 u32 bg_mode : 1;
 u32 dvfsc_mode : 2;
 u32 dvfsq_mode : 1;
 u32 wck_freq_mode : 1;
 u32 fast_wdet_en : 1;
 u32 fast_rdet_en : 1;
 u32 fast_gt_en : 1;
 u32 fast_gds_en : 1;
 u32 fast_train_method : 1;
 u32 rd_retrain : 2;
 u32 wr_retrain : 2;
 u32 dynamic_perbit_en_r : 1;
 u32 dynamic_dqsgen : 1;
 u32 gtrt : 1;
 u32 dummy_rd_en : 1;
 u32 zcalrt_en : 1;
 u32 rd_preamble : 1;
 u32 dmc_ext_gt : 2;
 u32 sys_clk_gt : 1;
 u32 dmc_cfg_aref_intlv : 1;
 u32 zq_intlv_en : 1;
 u32 dyn_dfi_wakeup : 1;
 u32 dummy_t_extend : 3;
 u32 dummy_wen_t_extend : 3;
 u32 ac_rev_reg_0_add_di_ui;
 u32 ac_rev_reg_1_pll_clk_inv: 1;
 u32 pll_8x_sync_sel: 1;
 u32 dqs_oe_extend : 3;
 u32 dq_oe_extend : 3;
 u32 ac_dq_offset : 3;
 u32 tzcomp_upddly : 6;
 u32 zcomp_rsp_dly : 6;
 u32 cfg_tzcomp_prep : 6;
 u32 plltimer;
 u32 zcal_errstopup : 1;
 u32 aggressive_mode : 1;
 u32 rf_rate_ctrl : 16;
 u32 t_lpwakeup_fg : 5;
 u32 ac_phy_gate_en : 1;
 u32 wdata_phy_gate_en : 1;
 u32 retrain_post_sref_en : 1;
 u32 retrain_time_th : 20;
 u32 rx_offset_k_en : 1;
 u32 reg_ofst_k_ofst_sel : 8;
 u32 rx_offset_k_dio_en : 1;
 u32 txgated_phy_hw_en : 1;
 u32 rxgated_phy_hw_en : 1;
 u32 xgated_dig_hw_en : 1;
 u32 wckgated_phy_hw_en : 1;
 u32 wckgated_dig_hw_en : 1;
 u32 dficlk_wck_dphy_free : 1;
 u32 phyclk_gate_en : 1;
 u32 cfg_tx_gcken : 1;
 u32 reg_8x_gcken : 1;
 u32 reg_ac_rx_gcken : 1;
 u32 reg_ac_txck_gcken : 1;
 u32 reg_ac_txcs_gcken : 1;
 u32 reg_dx_txwck_gcken : 1;
 u32 wlpulsecnt_exd : 3;
 u32 wlpulsecnt : 2;
 u32 pd_prd : 12;
 u32 trefi : 15;
 u32 reg_freq_det_th_mrg;
 u32 reg_freq_det_th;
 u32 bhs_delay_mode : 1;
 u32 bhs_en : 1;
 u32 bhs_req_pos_dly : 8;
 u32 bhs_txrx_en_neg_dly : 8;
 u32 dfi_bhs_dis_ack_pos_dly : 8;
 u32 bhs_req_neg_en : 1;
 u32 bhs_iso_neg_en : 1;
 u32 bhs_iso_neg_dly_base : 8;
 u32 bhs_iso_neg_dly : 8;
 u32 bhs_tx_rx_neg_en : 1;
 u32 bhs_txrx_en_pos_dly_base : 8;
 u32 bhs_txrx_en_pos_dly : 8;
 u32 bhs_8x_ckgn_neg_en: 1;
 u32 bhs_8x_ckgn_pos_dly_base : 8;
 u32 bhs_8x_ckgn_pos_dly : 8;
 u32 dfi_bhs_dis_ack_neg_dly_base : 8;
 u32 dfi_bhs_dis_ack_neg_dly : 8;
 u32 tbhs_end : 8;
 u32 tbhs_wakeup : 8;
 u32 tbhs_req_n_dly_base : 8;
 u32 tbhs_req_n_dly : 8;
 u32 tbhs_req_dly : 8;
 u32 tbhs_timeout : 10;
 u32 dqsgsl_mrgn : 8;
 u32 dram_rdqs_pre : 2;
 u32 reg_DA_PREAM_TM_DQS : 2;
 u32 reg_DX_DQS_RG_PRESET_DQS : 2;
 u32 read_link_ecc_en : 1;
 u32 modem_maping_type : 2;
 u32 tlp_waitcc : 8;
 u32 clk4x_en : 1;
 u32 ac_bypass_ff : 1;
 u32 ac_phy_gate_pre_en : 1;
 u32 ac_da_antiaging_en : 1;
 u32 dx_da_antiaging_en : 1;
 u32 ssdr : 1;
 u32 ua_500ns_time;
 u32 dlm_result_threshold;
 u32 swift_last_upate_en : 1;
 u32 swift_status : 4;
} freq_info;
typedef struct {
 u32 valid : 1;
 u32 sc_fastwakeup_en : 1;
 u32 qice_flux_max;
 u32 qice_flux_up;
 u32 qice_flux_down;
} l1bus_freq_info;
typedef struct {
 u32 ddrc_pllctrl0;
 u32 ddrc_pllctrl1;
 u32 ppll_cfg0;
 u32 ppll_cfg1;
 u32 ppll_cfg2;
 u32 ppll_cfg3;
 u32 sel_ddrcpll : 4;
 u32 div_clk_ddrcfg : 2;
 u32 div_clk_ddrsys : 2;
 u32 div_ddrc_pll : 5;
 u32 div_clk_dcdrbus : 2;
} l1bus_clk_cfg_str;
typedef struct {
 u32 clk_ratio : 2;
 u32 lp5_ofreq_en : 2;
 u32 xdr : 2;
 u32 ac_rg_ptx : 2;
 u32 dx_rg_ptx : 2;
 u32 ie_extend : 4;
 u32 dxctl_rx_ie_extend : 4;
 u32 dx_se_clkd : 4;
 u32 dx_se_clkd_4_7 : 4;
 u32 se_clkd_dqs : 4;
 u32 se_clkd_wck : 4;
 u32 ac_se_clkd : 4;
 u32 ac_se_clkd_4_7 : 4;
 u32 rg_pll_pll_posdiv : 9;
 u32 rg_pll_dll_posdiv : 9;
 u32 rg_pll_prediv : 3;
 u32 rg_pll_lpf_r : 2;
 u32 rg_ssc_r_frac_en : 1;
 u32 rg_ssc_r_sdmtype : 1;
 u32 rg_ssc_r_ups_en : 1;
 u32 rg_ssc_r_triangular_sel : 1;
 u32 rg_ssc_r_div_frac : 8;
 u32 rg_ssc_r_spreadmax : 8;
 u32 rg_ssc_r_sscdivnum : 4;
 u32 rg_ssc_r_sscdiv_en : 1;
 u32 rg_ssc_r_triinc : 8;
 u32 rg_ssc_r_div_int : 11;
 u32 rg_iband_cur_ctrl : 2;
 u32 rg_gcnt_div : 2;
 u32 rg_kband_rst_cycle : 2;
 u32 rg_ssc_r_spread_en : 1;
 u32 rg_ssc_r_fracssc_en : 1;
 u32 rg_fll_prediv_ctrl_0 : 1;
 u32 rg_fll_fbdiv : 2;
 u32 rg_kband_search_range_1_0 : 2;
 u32 base_step : 4;
 u32 base_code : 16;
 u32 rg_kband_search_range : 1;
 u32 rg_kband_fine_prec : 3;
 u32 rg_targ_cnt : 9;
 u32 rg_kband_fbk_cnt : 9;
 u32 rg_targ_cnt_fll_en : 9;
 u32 rg_kband_fbk_cnt_fll_en : 9;
 u32 rg_kband_search_range_fll_en : 1;
 u32 rg_gcnt_div_fll_en : 2;
 u32 pll_8x_sync_sel_0 : 1;
 u32 pll_8x_sync_sel_1 : 1;
 u32 dlm_div : 4;
} ddr_clk_cfg_str;
typedef struct {
 u32 ddrc_cfg_timing0;
 u32 ddrc_cfg_timing1;
 u32 ddrc_cfg_timing2;
 u32 ddrc_cfg_timing3;
 u32 ddrc_cfg_timing4;
 u32 ddrc_cfg_timing5;
 u32 ddrc_cfg_timing6;
 u32 ddrc_cfg_timing7;
 u32 ddrc_cfg_timing8;
 u32 ddrc_cfg_timing9;
 u32 ddrc_cfg_timing10;
 u32 ddrc_cfg_timing11;
 u32 ddrc_cfg_timing12;
 u32 ddrc_cfg_timing13;
 u32 ddrc_cfg_timing14;
 u32 ddrc_cfg_timing15;
 u32 ddrc_cfg_timing16;
 u32 ddrc_cfg_timing17;
 u32 ddrc_cfg_timing18;
 u32 ddrc_cfg_timing19;
 u32 ddrc_cfg_timing20;
 u32 ddrc_cfg_timing21;
 u32 ddrc_cfg_timing22;
 u32 ddrc_cfg_timing23;
 u32 ddrc_cfg_timing24;
 u32 ddrc_cfg_timing25;
 u32 ddrc_cfg_timing26;
 u32 ddrc_cfg_timing27;
 u32 ddrc_cfg_timing28;
 u32 ddrc_cfg_tim_bhs;
 u32 ddrc_cfg_tim_bak0;
 u32 ddrc_cfg_tim_bak1;
 u32 ddrc_cfg_tim_bak2;
 u32 ddrc_cfg_tim_bak7;
 u32 ddrc_cfg_tim_bak8;
 u32 ddrc_cfg_tim_bak9;
 u32 ddrc_cfg_tim_bak10;
 u32 ddrc_cfg_tim_bak11;
 u32 ddrc_cfg_derating_timing0;
 u32 ddrc_cfg_derating_timing1;
 u32 ddrc_cfg_derating_timing2;
 u32 ddrc_cfg_dfi_lat0;
 u32 ddrc_cfg_dfi_lat5;
 u32 ddrc_cfg_dfi_lat6;
 u32 ddrc_cfg_tim_osc0;
 u32 ddrc_cfg_tim_osc1;
 u32 ddrc_cfg_ram_pd;
 u32 t7p5ns_8ck;
} dmc_timing_str;
typedef struct {
 u32 ddrc_cfg_sfc_tim;
} sfc_timing_str;
typedef struct {
 u32 dramtimer0;
 u32 dramtimer1;
 u32 dramtimer2;
 u32 dramtimer3;
 u32 dramtimer4;
 u32 dramtimer5;
 u32 dramtimer6;
 u32 dramtimer7;
 u32 cattimer0;
 u32 cattimer1;
 u8 cfg_rl;
 u8 cfg_wl;
 u32 wckctrl0;
 u32 wckctrl1;
 u8 cfg_rl_rdm;
 u8 t_rl_rdm;
 u8 twckenl_rd_rdm;
} pack_timing_str;
typedef struct {
 u32 modereg01;
 u32 modereg23;
 u32 modereg67;
} dram_timing_str;
typedef struct {
 u16 freq;
 u16 dmc_freq;
 u16 l1bus_freq;
 u16 l1bus_freq_linkage;
 ddr_clk_cfg_str ddr_clk_cfg;
 sfc_timing_str sfc_timing;
 dmc_timing_str dmc_timing;
 pack_timing_str pack_timing;
 dram_timing_str dram_timing;
 freq_info freq_info;
 retrain_cfg_str retrain_cfg;
 ddr_vol_cfg_str ddr_vol_cfg;
 avs_cfg_ddr_str avs_cfg_ddr;
} ddr_profile;
typedef struct {
 u16 l1bus_freq;
 l1bus_clk_cfg_str l1bus_clk_cfg;
 l1bus_freq_info l1bus_freq_info;
 l1bus_vol_cfg_str l1bus_vol_cfg;
} l1bus_profile_str;
typedef struct {
 u32 slt_case_bitmap;
} ddr_slt;
typedef struct {
 u32 ate_init_test : 1;
 u32 ate_init_pass : 7;
 u32 ate_init_fail : 7;
 u32 ate_bist_pass : 7;
 u32 ate_bist_fail : 7;
 u32 ate_bist_bitmap;
} ddr_ate;
#ifdef DDR_HPM_SENSOR_NUM
#if DDR_HPM_SENSOR_NUM != 11
#error "DDR_HPM_SENSOR_NUM must be number of target_hpm[] & hpm_para[]!!"
#endif
#endif
#ifdef DDR_HPMX_SENSOR_NUM
#if DDR_HPMX_SENSOR_NUM != 9
#error "DDR_HPMX_SENSOR_NUM must be number of target_hpm[] & hpmx_para[]!!!"
#endif
#endif
#ifdef DDR_AVS_TEMP_RECOUP_NUM
#if DDR_AVS_TEMP_RECOUP_NUM != 4
#error "DDR_AVS_TEMP_RECOUP_NUM must be number of temp_recoup[]!!!"
#endif
#endif
typedef struct {
 u32 hpm_const_para;
 u32 hpm_para[11];
 u32 hpmx_para[9];
 u8 temp_recoup[4];
 u32 volt_dnlimit;
 u16 drl_volt;
 u8 exp_volt_margin;
 u16 ultimate_volt;
 u16 ultimate_volt_margin;
 u16 adapt_mode1;
 u32 const_volt;
 u16 adapt_mode2;
 u16 adapt_mode3;
} ddr_avs;
typedef struct {
 u32 target_hpm[11];
 u32 target_hpmx[9];
} avs_ctrl_str;
typedef struct {
 ddr_slt ddr_slt;
 ddr_ate ddr_ate;
 ddr_avs ddr_avs;
} ddr_init_profile;
typedef struct {
 cat_step_cfg_str cat_step_cfg;
 dqt_cfg_str dqt_cfg;
} ddr_init_training_cfg;
typedef struct {
 unsigned int offset_addr;
 unsigned int reg_val[QICE_SEC_PORT_MAX];
} qice_port_cfg_str;
typedef struct {
 unsigned int offset_addr;
 unsigned int value;
} common_cfg_str;
struct qice_ibqe_port_cfg_str {
 unsigned int offset_addr;
 unsigned int reg_val[QICE_IBQE_PORT_NUM];
};
struct qice_tbed_port_cfg_str {
 unsigned int offset_addr;
 unsigned int reg_val[QICE_TBED_PORT_NUM];
};
struct qice_fc_port_cfg_str {
 unsigned int offset_addr;
 unsigned int reg_val[QICE_FC_PORT_NUM];
};
struct qice_2to1_port_cfg_str {
 unsigned int offset_addr;
 unsigned int reg_val[QICE_2TO1_PORT_NUM];
};
struct qice_qdb_port_cfg_str {
 unsigned int offset_addr;
 unsigned int reg_val[QICE_QDB_PORT_NUM];
};
struct qice_cfg_str {
 unsigned int qice_ibqecfg_num;
 unsigned int qice_tbedcfg_num;
 unsigned int qice_fccfg_num;
 unsigned int qice_qdbcfg_num;
 struct qice_ibqe_port_cfg_str *qice_ibqe;
 struct qice_tbed_port_cfg_str *qice_tbed;
 struct qice_fc_port_cfg_str *qice_fc;
 struct qice_qdb_port_cfg_str *qice_qdb;
};
typedef struct {
 unsigned int DX_IO_PUPDMODE_DQS : 2;
 unsigned int reg_DX_DQS_DA_SIG_SW : 1;
 unsigned int DX_RG_TEST9_HSB_0 : 1;
} ddr_dqs_swap_cfg;
typedef struct {
 unsigned int DX_IO_PUPDMODE_WCK : 2;
 unsigned int reg_DX_WCK_DA_SIG_SW : 1;
 unsigned int DX_RG_TEST11_HSB_0 : 1;
} ddr_wck_swap_cfg;
typedef struct {
 unsigned int reg_AC_DA_SIG_SW : 1;
 unsigned int AC_RG_TEST8_HSB_0 : 1;
} ddr_ck_swap_cfg;
typedef struct {
 SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_UNION addr_swap_reg;
 SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_UNION addr_swap_oen_reg;
 unsigned int AC_RG_TX_EN : 9;
} ddr_ca_swap_cfg;
typedef struct {
 SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_UNION data_swap_soft0_reg;
 SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_UNION data_swap_soft1_reg;
 SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_UNION data_deswap_soft0_reg;
 SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_UNION data_deswap_soft1_reg;
 SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_UNION data_swap_dm_reg;
} ddr_dq_swap_cfg;
typedef struct {
 u32 ddr_id;
 u8 ddr_ca_swap[CHANNEL_MAX_NUM];
 u8 ddr_dq_swap[CHANNEL_MAX_NUM];
 u8 ddr_dqs_swap[CHANNEL_MAX_NUM][BYTELANE_MAX_NUM];
 u8 ddr_wck_swap[CHANNEL_MAX_NUM][BYTELANE_MAX_NUM];
 u8 ddr_ck_swap[CHANNEL_MAX_NUM];
 u8 dram_master_channel[CHANNEL_MAX_NUM];
 u8 zq_seq[CHANNEL_MAX_NUM];
} swap_table;
typedef struct {
 ddr_ca_swap_cfg *ddr_ca_channel[CHANNEL_MAX_NUM];
 ddr_dq_swap_cfg *ddr_dq_channel[CHANNEL_MAX_NUM];
 ddr_dqs_swap_cfg *ddr_dqs_channel[CHANNEL_MAX_NUM][BYTELANE_MAX_NUM];
 ddr_wck_swap_cfg *ddr_wck_channel[CHANNEL_MAX_NUM][BYTELANE_MAX_NUM];
 ddr_ck_swap_cfg *ddr_ck_channel[CHANNEL_MAX_NUM];
} swap_info;
enum {
 SEGNUM_DDR_INIT = 0,
 SEGNUM_DMSS_INIT,
 SEGNUM_DDR_DDR_PROFILE,
 SEGNUM_DDR_DMSS_PROFILE,
 SEGNUM_DDR_IO_PROFILE,
 SEGNUM_DDR_INIT_PROFILE,
 SEGNUM_DDR_TRAINING_PARA,
 SEGNUM_DMSS_GLOBAL,
 SEGNUM_DMSS_AXI,
 SEGNUM_DMSS_SEC,
 SEGNUM_QOS_CFG,
 SEGNUM_DDR_FEATURE,
 SEGNUM_DMSS_FEATURE,
 SEGNUM_ADJUST_TACTIC,
 SEGNUM_UCE_CTRL,
 SEGNUM_X8_TIMING,
 SEGNUM_AVS_CTRL,
 SEGNUM_DDR_TIMING_ABOVE_12GB,
 SEGNUM_DDR_MAX = 20
};
typedef struct {
 u32 number_of_seg;
 u32 reserved;
 u32 offset_seg[SEGNUM_DDR_MAX][2];
} segment_info;
typedef struct {
 u32 magic_num;
 u32 reserved;
 u32 para_version;
 u32 valid_seg;
 segment_info segment_info;
} ddr_para_head_str;
struct seg_info_desc {
 char *name;
 int para_pointer_offset;
 int para_number_offset;
 int para_size;
};
typedef struct {
 u32 uce_id : 3;
 u32 wdt_en : 1;
 u32 reserved1 : 1;
 u32 uart_dis : 1;
 u32 info_pack_en : 1;
 u32 ddr_train_track_dis : 1;
 u32 print_level : 4;
 u32 zcode_cal : 1;
 u32 reserved : 19;
} uce_ctrl_str;
typedef struct {
 u32 cmd_load_prd;
 u32 cmd_load_max;
 u32 cmd_load_hold_max;
 u32 cmd_load_trigger_max;
 u32 dat_load_prd;
 u32 full_bandwidth;
 u32 dat_load_max;
 u32 dat_load_hold_max;
 u32 dat_load_trigger_max;
 u32 flux_prd;
 u32 flux_min;
 u32 flux_trigger_max;
 u32 flux_stat_prd;
 u32 flux_stat_max;
 u32 flux_stat_min;
 u32 flux_stat_hold_max;
 u32 lit_lat_min;
 u32 mid_lat_min;
 u32 big_lat_min;
} ddr_tactic;
typedef struct {
 u32 avs_chip_type_is_save;
 u32 magic_num;
 u32 avs_chip_type;
} ddr_avs_chip_type;
typedef struct {
 u32 bk_offset;
} ddr_restore_head;
typedef struct {
 u32 is_not_save : 4;
 u32 is_first_restore : 4;
 u32 reserved : 4;
 u32 error_id : 20;
} ddr_restore_status;
typedef struct {
 dmc_timing_str dmc_timing;
 pack_timing_str pack_timing;
 dram_timing_str dram_timing;
} ddr_timing;
typedef struct {
 u32 ddrc_cfg_timing1;
 u32 ddrc_cfg_timing10;
 u32 dramtimer1;
} ddr_timing_density;
#define DDR_DFS_TRACK_SIZE 1024
#define DDR_DFS_TRACK_EXT_SIZE 32
struct ddrdfs_tracking_lpbuf {
 unsigned int wp;
 unsigned int timespec_l;
 unsigned int timespec_h;
 unsigned char buf[DDR_DFS_TRACK_SIZE + DDR_DFS_TRACK_EXT_SIZE];
};
#define LATSTAT_CLK_FPGA 20
#define LATSTAT_CLK_ASIC 20
#define LATSTAT_PORT_IVP 0x2
#define LATSTAT_PORT_CPU 0x1E0
#define LATSTAT_PORT_GPU 0x18
#define LATSTAT_PORT_HIFI 0x1
#define LATSTAT_PORT_NUM 15
#define LATSTAT_DATA_SIZE 0x4
#define LATSTAT_PTQE_DATA_SIZE 0x8
typedef struct {
 u64 cycle_num;
 u64 sample_interval;
 u64 sample_num;
 u64 port_select;
} LATSTAT_FRAME_HEADER;
typedef struct {
 u64 cycle_num;
 u64 pdrst_timeout;
 u64 clkgt_timeout;
 u64 port_select;
} LATSTAT_SAMPLE_HEADER;
#pragma pack(push)
#pragma pack(1)
union latstat_ptqe {
 u64 data[LATSTAT_PTQE_DATA_SIZE];
 struct {
  u32 dataless_osd_num;
  u32 snoop_ostd_num;
  u32 others_osd_num;
  u32 r_beat_num;
  u32 w_beat_num;
  u32 rsp_num;
  u32 srsp_num;
  u32 sreq_num;
  u32 clk_cnt_num;
  u32 read_cmd_num : 24;
  u32 write_cmd_num : 24;
  u32 dataless_cmd_num : 24;
  u32 snp_cmd_num : 24;
  u32 others_cmd_num : 24;
  u8 read_max_osd;
  u8 write_max_osd;
  u8 dataless_max_osd;
  u8 snoop_max_ostd;
  u8 others_max_osd;
  u8 read_osd_num;
  u8 write_osd_num;
 } reg;
};
typedef union {
 u64 data[LATSTAT_DATA_SIZE];
 struct {
  u32 clk_cnt_num;
  u32 r_beat_num;
  u32 w_beat_num;
  u32 r_trans_num;
  u32 w_trans_num;
  u64 r_osd_num : 40;
  u64 w_osd_num : 40;
  u8 r_max_osd;
  u8 w_max_osd;
 } reg;
} LATSTAT_UNION;
#pragma pack(pop)
typedef struct {
 ddr_target_info_str *ddr_target_info;
 ddr_feature *feature;
 l1bus_feature *l1bus_feature;
 ddr_init_info *ddr_init_info;
 l1bus_init_info *l1bus_init_info;
 u32 number_of_ddr_profile;
 ddr_profile *ddr_profile;
 u32 number_of_l1bus_profile;
 l1bus_profile_str *l1bus_profile;
 ddr_io_profile *ddr_io_profile;
 ddr_init_profile *ddr_init_profile;
 uce_ctrl_str *uce_ctrl_cfg;
 avs_ctrl_str *avs_ctrl_cfg;
 u32 number_of_init_training_cfg;
 ddr_init_training_cfg *init_training_cfg;
 ddr_train_param *ddr_train_param[CHANNEL_MAX_NUM];
 u32 number_of_ddr_train;
 ddr_tactic *ddr_adjust_tactic;
 ddr_tactic *ddr_adjust_tactic_lt;
 struct qice_cfg_str *qice_cfg;
 u32 *uce_firmware_addr;
 u32 uce_firmware_size;
 u8 *trainig_result_idx_map_addr;
 u32 trainig_result_idx_map_size;
 ddr_restore_status restore_status;
 ddr_timing *ddr_timing_x8;
 ddr_timing_density *ddr_timing_above_12Gb;
 ddr_phy_addr_info_str *ddr_phy_addr_info_str;
 ddr_avs_chip_type *ddr_avs_chip_type;
} ddr_para_entry_str;
typedef struct {
 ddr_dqs_swap_cfg *ddr_dqs_swap_cfg;
 ddr_wck_swap_cfg *ddr_wck_swap_cfg;
 ddr_ck_swap_cfg *ddr_ck_swap_cfg;
 ddr_ca_swap_cfg *ddr_ca_swap_cfg;
 ddr_dq_swap_cfg *ddr_dq_swap_cfg;
 swap_table *swap_table;
 unsigned int number_of_swap_table;
} ddr_swap_table_str;
typedef struct {
 u32 ddr_target_info;
 u32 feature;
 u32 l1bus_feature;
 u32 ddr_init_info;
 u32 l1bus_init_info;
 u32 number_of_ddr_profile;
 u32 ddr_profile;
 u32 number_of_l1bus_profile;
 u32 l1bus_profile;
 u32 ddr_io_profile;
 u32 ddr_init_profile;
 u32 uce_ctrl_cfg;
 u32 avs_ctrl_cfg;
 u32 number_of_init_training_cfg;
 u32 init_training_cfg;
 u32 ddr_train_param[CHANNEL_MAX_NUM];
 u32 number_of_ddr_train;
 u32 ddr_adjust_tactic;
 u32 ddr_adjust_tactic_lt;
 u32 qice_cfg;
 u32 uce_firmware_addr;
 u32 uce_firmware_size;
 u32 trainig_result_idx_map_addr;
 u32 trainig_result_idx_map_size;
 ddr_restore_status restore_status;
 u32 ddr_timing_x8;
 u32 ddr_timing_above_12Gb;
 u32 ddr_phy_addr_info_str;
 u32 ddr_avs_chip_type;
} fastboot_ddr_para_entry_str;
typedef struct {
 unsigned int ops_id;
} pmu_vol_step_str;
typedef struct {
 u64 start_addr;
 u32 size;
 u32 granularity_size;
} CMA_INFO;
typedef struct {
 int npu_sec_flag;
 u32 npu_sec_size;
 int ap_sec_read_flag;
 int nv_modem_flag;
 int modem_sec_alloc_flag;
 u32 modem_sec_alloc_size;
 int modem_socp_sec_flag;
 int sec_camera_sec_flag;
 int single_ap_flag;
 CMA_INFO tiny_cma;
 CMA_INFO mm_cma;
 CMA_INFO iris_cma;
 CMA_INFO smemheap_cma;
} seccfg_info;
struct seccfg_cma_info {
 CMA_INFO tiny_cma;
 CMA_INFO mm_cma;
 CMA_INFO iris_cma;
 CMA_INFO smemheap_cma;
};
typedef struct {
 u32 dmc_rint_flag;
 u32 dmc_rint0[CHANNEL_MAX_NUM];
} dmc_rint_info;
struct nums_of_para {
 unsigned int num_of_train_param;
 unsigned int num_of_ddr_profile;
 unsigned int reserved;
 unsigned int num_of_l1bus_cfg;
 unsigned int num_of_dbc_cfg;
 unsigned int train_param_map_size;
 unsigned int num_of_l1bus_profile;
};
struct ddr_share_para {
    u32 ddr_target_info_addr;
    u32 ddr_train_param_addr;
    u32 ddr_vref_train_data_addr;
};
struct ddr_margin_node {
 unsigned int lb:16;
 unsigned int rb:16;
 unsigned int window:16;
 unsigned int result:16;
 unsigned int enable:16;
 unsigned int vref:16;
 struct ddr_margin_node *key;
};
struct ddr_mntn_storage {
 unsigned int rtc_time;
};
#define DDR_SEG_MAGIC 0xA55A7F3DU
#endif
