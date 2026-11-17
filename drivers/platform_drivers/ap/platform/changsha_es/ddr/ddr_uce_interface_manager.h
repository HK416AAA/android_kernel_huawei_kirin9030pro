#ifndef __DDR_UCE_INTERFACE_NMANAGER_H__
#define __DDR_UCE_INTERFACE_NMANAGER_H__ 
#define SOC_UCEOUTPUT_RESULT_ADDR(base) ((base) + 0x000UL)
#define SOC_UCEINPUT_FEATURE_ADDR(base) ((base) + 0x000UL)
#define SOC_UCEINPUT_DDR_TARGET_INFO_ADDR(base) ((base) + 0x004UL)
#define SOC_UCEINPUT_DDR_PROFILE_ADDR(base) ((base) + 0x008UL)
#define SOC_UCEINPUT_UCE_CTRL_ADDR(base) ((base) + 0x00CUL)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_ADDR(base) ((base) + 0x010UL)
#define SOC_UCEINPUT_RECORD_TRAIN_PARAM_INDEX_ADDR(base) ((base) + 0x014UL)
#define SOC_UCEINPUT_DQ_SWAP_ADDR(base,bytelane) ((base) + 0x024UL + 0x4 * (bytelane))
#define SOC_UCEINPUT_EYESUM_ADDR(base,rank,bytelane) ((base) + 0x02CUL + 0x4 * (rank) + 0x8 * (bytelane))
#define SOC_UCEINPUT_AREA_EVEN_ADDR(base,bytelane) ((base) + 0x02CUL + 0x4 * (bytelane))
#define SOC_UCEINPUT_AREA_ODD_ADDR(base,bytelane) ((base) + 0x034UL + 0x4 * (bytelane))
#define SOC_UCEINPUT_OSC_COUNT_RANK0_ADDR(base) ((base) + 0x02CUL)
#define SOC_UCEINPUT_OSC_COUNT_RANK1_ADDR(base) ((base) + 0x030UL)
#define SOC_UCEINPUT_OSC_VALID_ADDR(base) ((base) + 0x034UL)
#define SOC_UCEINPUT_WDQ_DELTA_RANK0_ADDR(base) ((base) + 0x038UL)
#define SOC_UCEINPUT_WDQ_DELTA_RANK1_ADDR(base) ((base) + 0x03CUL)
#define SOC_UCEINPUT_BACKPRESS_TIME_ADDR(base) ((base) + 0x040UL)
#define SOC_UCEINPUT_CA_VREF_ADDR(base,vref_num) ((base) + 0x050UL + 0x4 * (vref_num))
#define SOC_UCEINPUT_DRAM_DQ_VREF_ADDR(base,vref_num) ((base) + 0x0A0UL + 0x4 * (vref_num))
#define SOC_UCEINPUT_HOST_DQ_VREF_ADDR(base,vref_num) ((base) + 0x0F0UL + 0x4 * (vref_num))
#define SOC_UCEINPUT_WCK_DCC_EN_ADDR(base) ((base) + 0x140UL)
#define SOC_UCEINPUT_RDQS_DCC_EN_ADDR(base) ((base) + 0x144UL)
#define SOC_UCEINPUT_BDL_DLM_RDQSCYC_ADDR(base) ((base) + 0x148UL)
#define SOC_UCEINPUT_DFS_TRACE_POINT_ADDR(base) ((base) + 0x14CUL)
#define SOC_UCEINPUT_VREF_BIAS_ADDR(base,freq_id,train_type) ((base) + 0x150UL + 0x4 * (freq_id) + 0x28 * (train_type))
#define SOC_UCEINPUT_AC_RG_TX_EN_ADDR(base) ((base) + 0x1D0UL)
#define SOC_UCEINPUT_DRAM_MENUFACTORY_ADDR(base) ((base) + 0x1D4UL)
#define SOC_UCEINPUT_SWAP_DX_RG_TEST9_HSB_0_ADDR(base,bytelane) ((base) + 0x1D8UL + 0x4 * (bytelane))
#define SOC_UCEINPUT_DFS_STOP_RETRAIN_ADDR(base) ((base) + 0x1E4UL)
#define SOC_UCEINPUT_DFS_SWIFT_TRK_STATUS_ADDR(base) ((base) + 0x1E8UL)
#define SOC_UCEINPUT_DFS_SWIFT_TRK_UPD_DONE_ADDR(base) ((base) + 0x1ECUL)
#define SOC_UCEINPUT_DFS_CTRL_ADDR(base) ((base) + 0x1F0UL)
typedef union {
 unsigned int value;
 struct {
  unsigned int wl_enhancement_en : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_UCEINPUT_FEATURE_UNION;
#define SOC_UCEINPUT_FEATURE_wl_enhancement_en_START (0)
#define SOC_UCEINPUT_FEATURE_wl_enhancement_en_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int ddr_type : 4;
  unsigned int rank_num : 8;
  unsigned int io_width_rank0 : 1;
  unsigned int io_width_rank1 : 1;
  unsigned int manufactory_id : 8;
  unsigned int reserved : 10;
 } reg;
} SOC_UCEINPUT_DDR_TARGET_INFO_UNION;
#define SOC_UCEINPUT_DDR_TARGET_INFO_ddr_type_START (0)
#define SOC_UCEINPUT_DDR_TARGET_INFO_ddr_type_END (3)
#define SOC_UCEINPUT_DDR_TARGET_INFO_rank_num_START (4)
#define SOC_UCEINPUT_DDR_TARGET_INFO_rank_num_END (11)
#define SOC_UCEINPUT_DDR_TARGET_INFO_io_width_rank0_START (12)
#define SOC_UCEINPUT_DDR_TARGET_INFO_io_width_rank0_END (12)
#define SOC_UCEINPUT_DDR_TARGET_INFO_io_width_rank1_START (13)
#define SOC_UCEINPUT_DDR_TARGET_INFO_io_width_rank1_END (13)
#define SOC_UCEINPUT_DDR_TARGET_INFO_io_width_rank1_START (13)
#define SOC_UCEINPUT_DDR_TARGET_INFO_io_width_rank1_END (13)
#define SOC_UCEINPUT_DDR_TARGET_INFO_manufactory_id_START (14)
#define SOC_UCEINPUT_DDR_TARGET_INFO_manufactory_id_END (21)
typedef union {
 unsigned int value;
 struct {
  unsigned int freq : 16;
  unsigned int wck_on : 1;
  unsigned int dvfsq_mode : 1;
  unsigned int rd_retrain : 2;
  unsigned int wr_retrain : 2;
  unsigned int reserved : 10;
 } reg;
} SOC_UCEINPUT_DDR_PROFILE_UNION;
#define SOC_UCEINPUT_DDR_PROFILE_freq_START (0)
#define SOC_UCEINPUT_DDR_PROFILE_freq_END (15)
#define SOC_UCEINPUT_DDR_PROFILE_wck_on_START (16)
#define SOC_UCEINPUT_DDR_PROFILE_wck_on_END (16)
#define SOC_UCEINPUT_DDR_PROFILE_dvfsq_mode_START (17)
#define SOC_UCEINPUT_DDR_PROFILE_dvfsq_mode_END (17)
#define SOC_UCEINPUT_DDR_PROFILE_rd_retrain_START (18)
#define SOC_UCEINPUT_DDR_PROFILE_rd_retrain_END (19)
#define SOC_UCEINPUT_DDR_PROFILE_wr_retrain_START (20)
#define SOC_UCEINPUT_DDR_PROFILE_wr_retrain_END (21)
typedef union {
 unsigned int value;
 struct {
  unsigned int uce_id : 3;
  unsigned int wdt_en : 1;
  unsigned int uart_dis : 1;
  unsigned int info_pack_en : 1;
  unsigned int ddr_train_track_dis : 1;
  unsigned int print_level : 4;
  unsigned int zcode_cal : 1;
  unsigned int uce_idle : 1;
  unsigned int bdl_cfg_ack : 1;
  unsigned int sr_train_param_id : 4;
  unsigned int reserved : 14;
 } reg;
} SOC_UCEINPUT_UCE_CTRL_UNION;
#define SOC_UCEINPUT_UCE_CTRL_uce_id_START (0)
#define SOC_UCEINPUT_UCE_CTRL_uce_id_END (2)
#define SOC_UCEINPUT_UCE_CTRL_wdt_en_START (3)
#define SOC_UCEINPUT_UCE_CTRL_wdt_en_END (3)
#define SOC_UCEINPUT_UCE_CTRL_uart_dis_START (4)
#define SOC_UCEINPUT_UCE_CTRL_uart_dis_END (4)
#define SOC_UCEINPUT_UCE_CTRL_info_pack_en_START (5)
#define SOC_UCEINPUT_UCE_CTRL_info_pack_en_END (5)
#define SOC_UCEINPUT_UCE_CTRL_ddr_train_track_dis_START (6)
#define SOC_UCEINPUT_UCE_CTRL_ddr_train_track_dis_END (6)
#define SOC_UCEINPUT_UCE_CTRL_print_level_START (7)
#define SOC_UCEINPUT_UCE_CTRL_print_level_END (10)
#define SOC_UCEINPUT_UCE_CTRL_zcode_cal_START (11)
#define SOC_UCEINPUT_UCE_CTRL_zcode_cal_END (11)
#define SOC_UCEINPUT_UCE_CTRL_uce_idle_START (12)
#define SOC_UCEINPUT_UCE_CTRL_uce_idle_END (12)
#define SOC_UCEINPUT_UCE_CTRL_bdl_cfg_ack_START (13)
#define SOC_UCEINPUT_UCE_CTRL_bdl_cfg_ack_END (13)
#define SOC_UCEINPUT_UCE_CTRL_sr_train_param_id_START (14)
#define SOC_UCEINPUT_UCE_CTRL_sr_train_param_id_END (17)
typedef union {
 unsigned int value;
 struct {
  unsigned int target_freq_idx : 4;
  unsigned int is_samsung_bytemode : 1;
  unsigned int is_restore : 1;
  unsigned int scene_id : 5;
  unsigned int result_idx : 8;
  unsigned int rdet_type : 3;
  unsigned int reserved0 : 1;
  unsigned int sw_should_swap : 1;
  unsigned int bytelane : 1;
  unsigned int rank_id : 1;
  unsigned int is_lpddr5 : 1;
  unsigned int dqx_swap : 1;
  unsigned int rdet_scan_err_en : 1;
  unsigned int reserved : 3;
 } reg;
} SOC_UCEINPUT_INIT_TRAIN_INFO_UNION;
#define SOC_UCEINPUT_INIT_TRAIN_INFO_target_freq_idx_START (0)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_target_freq_idx_END (3)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_is_samsung_bytemode_START (4)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_is_samsung_bytemode_END (4)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_is_restore_START (5)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_is_restore_END (5)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_scene_id_START (6)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_scene_id_END (10)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_result_idx_START (11)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_result_idx_END (18)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_rdet_type_START (19)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_rdet_type_END (21)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_sw_should_swap_START (23)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_sw_should_swap_END (23)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_bytelane_START (24)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_bytelane_END (24)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_rank_id_START (25)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_rank_id_END (25)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_is_lpddr5_START (26)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_is_lpddr5_END (26)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_dqx_swap_START (27)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_dqx_swap_END (27)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_rdet_scan_err_en_START (28)
#define SOC_UCEINPUT_INIT_TRAIN_INFO_rdet_scan_err_en_END (28)
typedef union {
 unsigned int value;
 struct {
  unsigned int swap_8dq : 32;
 } reg;
} SOC_UCEINPUT_DQ_SWAP_UNION;
typedef union {
 unsigned int value;
 struct {
  unsigned int vref_2rank_2byte : 32;
 } reg;
} SOC_UCEINPUT_CA_VREF_UNION;
typedef union {
 unsigned int value;
 struct {
  unsigned int vref_2rank_2byte : 32;
 } reg;
} SOC_UCEINPUT_DRAM_DQ_VREF_UNION;
typedef union {
 unsigned int value;
 struct {
  unsigned int vref_2rank_2byte : 32;
 } reg;
} SOC_UCEINPUT_HOST_DQ_VREF_UNION;
typedef union {
 unsigned int value;
 struct {
  unsigned int cfg_value;
 } reg;
} SOC_UCEINPUT_WCK_DCC_EN_UNION;
#define SOC_UCEINPUT_WCK_DCC_EN_cfg_value_START (0)
#define SOC_UCEINPUT_WCK_DCC_EN_cfg_value_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int cfg_value;
 } reg;
} SOC_UCEINPUT_RDQS_DCC_EN_UNION;
#define SOC_UCEINPUT_RDQS_DCC_EN_cfg_value_START (0)
#define SOC_UCEINPUT_RDQS_DCC_EN_cfg_value_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int rdqscyc : 32;
 } reg;
} SOC_UCEINPUT_BDL_DLM_RDQSCYC_UNION;
#define SOC_UCEINPUT_BDL_DLM_RDQSCYC_rdqscyc_START (0)
#define SOC_UCEINPUT_BDL_DLM_RDQSCYC_rdqscyc_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int cnt;
 } reg;
} SOC_UCEINPUT_DFS_TRACE_POINT_UNION;
#define SOC_UCEINPUT_DFS_TRACE_POINT_cnt_START (0)
#define SOC_UCEINPUT_DFS_TRACE_POINT_cnt_END (31)
#define SOC_DDR_DUMREG_DUM_REG_RSV0_uce_shadow_cfg_finished_START (0)
#define SOC_DDR_DUMREG_DUM_REG_RSV0_uce_shadow_cfg_finished_END (0)
#define SOC_DDR_DUMREG_DUM_REG_RSV0_xpu_switch_packphy_wr_sel_START (1)
#define SOC_DDR_DUMREG_DUM_REG_RSV0_xpu_switch_packphy_wr_sel_END (1)
typedef union {
 unsigned int value;
 struct {
  unsigned int cfg_value;
 } reg;
} SOC_UCEINPUT_AC_RG_TX_EN_UNION;
#define SOC_UCEINPUT_AC_RG_TX_EN_cfg_value_START (0)
#define SOC_UCEINPUT_AC_RG_TX_EN_cfg_value_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int manufactory_id;
 } reg;
} SOC_UCEINPUT_DRAM_MENUFACTORY_UNION;
#define SOC_UCEINPUT_DRAM_MENUFACTORY_manufactory_id_START (0)
#define SOC_UCEINPUT_DRAM_MENUFACTORY_manufactory_id_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int cfg_value : 32;
 } reg;
} SOC_UCEINPUT_SWAP_DX_RG_TEST9_HSB_0_UNION;
#define SOC_UCEINPUT_SWAP_DX_RG_TEST9_HSB_0_cfg_value_START (0)
#define SOC_UCEINPUT_SWAP_DX_RG_TEST9_HSB_0_cfg_value_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int value;
 } reg;
} SOC_UCEINPUT_DFS_STOP_RETRAIN_UNION;
#define SOC_UCEINPUT_DFS_STOP_RETRAIN_value_START (0)
#define SOC_UCEINPUT_DFS_STOP_RETRAIN_value_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int swift_status : 4;
  unsigned int swift_trk_done : 4;
  unsigned int is_swift_fall : 1;
  unsigned int reserved : 23;
 } reg;
} SOC_UCEINPUT_DFS_SWIFT_TRK_STATUS_UNION;
#define SOC_UCEINPUT_DFS_SWIFT_TRK_STATUS_swift_status_START (0)
#define SOC_UCEINPUT_DFS_SWIFT_TRK_STATUS_swift_status_END (3)
#define SOC_UCEINPUT_DFS_SWIFT_TRK_STATUS_swift_trk_done_START (4)
#define SOC_UCEINPUT_DFS_SWIFT_TRK_STATUS_swift_trk_done_END (7)
#define SOC_UCEINPUT_DFS_SWIFT_TRK_STATUS_is_swift_fall_START (8)
#define SOC_UCEINPUT_DFS_SWIFT_TRK_STATUS_is_swift_fall_END (8)
#define SOC_UCEINPUT_DFS_SWIFT_TRK_STATUS_reserved_START (9)
#define SOC_UCEINPUT_DFS_SWIFT_TRK_STATUS_reserved_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int dfs : 8;
  unsigned int retrain : 8;
  unsigned int reserved : 16;
 } reg;
} SOC_UCEINPUT_BACKPRESS_TIME_UNION;
#define SOC_UCEINPUT_BACKPRESS_TIME_dfs_START (0)
#define SOC_UCEINPUT_BACKPRESS_TIME_dfs_END (7)
#define SOC_UCEINPUT_BACKPRESS_TIME_retrain_START (8)
#define SOC_UCEINPUT_BACKPRESS_TIME_retrain_END (15)
#define SOC_UCEINPUT_BACKPRESS_TIME_reserved_START (16)
#define SOC_UCEINPUT_BACKPRESS_TIME_reserved_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int upd_done : 32;
 } reg;
} SOC_UCEINPUT_DFS_SWIFT_TRK_UPD_DONE_UNION;
#define SOC_UCEINPUT_DFS_SWIFT_TRK_UPD_DONE_upd_done_START (0)
#define SOC_UCEINPUT_DFS_SWIFT_TRK_UPD_DONE_upd_done_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int pll_retry_en : 1;
  unsigned int pll_retry_times : 8;
  unsigned int reserved : 23;
 } reg;
} SOC_UCEINPUT_DFS_CTRL_UNION;
#define SOC_UCEINPUT_DFS_CTRL_pll_retry_en_START (0)
#define SOC_UCEINPUT_DFS_CTRL_pll_retry_en_END (0)
#define SOC_UCEINPUT_DFS_CTRL_pll_retry_times_START (1)
#define SOC_UCEINPUT_DFS_CTRL_pll_retry_times_END (8)
#define SOC_UCEINPUT_DFS_CTRL_reserved_START (9)
#define SOC_UCEINPUT_DFS_CTRL_reserved_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int osc_count : 32;
 } reg;
} SOC_UCEINPUT_OSC_COUNT_RANK0_UNION;
#define SOC_UCEINPUT_OSC_COUNT_RANK0_osc_count_START (0)
#define SOC_UCEINPUT_OSC_COUNT_RANK0_osc_count_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int osc_count : 32;
 } reg;
} SOC_UCEINPUT_OSC_COUNT_RANK1_UNION;
#define SOC_UCEINPUT_OSC_COUNT_RANK1_osc_count_START (0)
#define SOC_UCEINPUT_OSC_COUNT_RANK1_osc_count_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int osc_valid : 32;
 } reg;
} SOC_UCEINPUT_OSC_VALID_UNION;
#define SOC_UCEINPUT_OSC_VALID_osc_valid_START (0)
#define SOC_UCEINPUT_OSC_VALID_osc_valid_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int wdq_delta : 32;
 } reg;
} SOC_UCEINPUT_WDQ_DELTA_RANK0_UNION;
#define SOC_UCEINPUT_WDQ_DELTA_RANK0_wdq_delta_START (0)
#define SOC_UCEINPUT_WDQ_DELTA_RANK0_wdq_delta_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int wdq_delta : 32;
 } reg;
} SOC_UCEINPUT_WDQ_DELTA_RANK1_UNION;
#define SOC_UCEINPUT_WDQ_DELTA_RANK1_wdq_delta_START (0)
#define SOC_UCEINPUT_WDQ_DELTA_RANK1_wdq_delta_END (31)
#endif
