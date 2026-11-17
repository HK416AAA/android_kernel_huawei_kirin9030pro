#ifndef __DDR_XPU_INTERFACE_NMANAGER_H__
#define __DDR_XPU_INTERFACE_NMANAGER_H__ 
#define SOC_XPUINPUT_SHOULD_AWAKED_ADDR(base) ((base) + 0x000UL)
#define SOC_XPUINPUT_DDRTEST_LOOP_MAX_ADDR(base) ((base) + 0x004UL)
#define SOC_XPUINPUT_DDRENV_INFO_ADDR(base) ((base) + 0x008UL)
#define SOC_XPUINPUT_UCE_IMGADDR_ADDR(base) ((base) + 0x00CUL)
#define SOC_XPUINPUT_UCE_IMGSIZE_ADDR(base) ((base) + 0x010UL)
#define SOC_XPUINPUT_DDRSR_STAT_ADDR(base) ((base) + 0x014UL)
#define SOC_XPUINPUT_EXMBIST_TEST_CFG_ADDR(base) ((base) + 0x018UL)
#define SOC_XPUINPUT_DDRTEST_INTERVAL_MS_ADDR(base) ((base) + 0x01CUL)
#define SOC_XPUINPUT_BPG_TEST_CFG_ADDR(base) ((base) + 0x020UL)
#define SOC_XPUINPUT_XLOADER_MODE_ADDR(base) ((base) + 0x024UL)
#define SOC_XPUINPUT_DDR_TEST_CFG_ADDR(base) ((base) + 0x028UL)
#define SOC_XPUINPUT_DVFS_ADDR(base) ((base) + 0x02CUL)
#define SOC_XPUINPUT_DVFS_FREQ_INFO_ADDR(base) ((base) + 0x030UL)
#define SOC_XPUINPUT_RTC_TIME_ADDR(base) ((base) + 0x034UL)
#define SOC_XPUINPUT_DDRRESTORE_STAT_ADDR(base) ((base) + 0x038UL)
#define SOC_XPUINPUT_QICE_ADDR(base) ((base) + 0x03CUL)
#define SOC_XPUINPUT_QICE_FREQ_INFO_ADDR(base) ((base) + 0x040UL)
#define SOC_XPUINPUT_DDR_LPNV_INFO_ADDR(base) ((base) + 0x044UL)
#define SOC_XPUINPUT_DDRAVS_INFO_ADDR(base) ((base) + 0x048UL)
#define SOC_XPUINPUT_UCE_INFO_ADDR(base) ((base) + 0x04CUL)
#define SOC_XPUINPUT_UCE_MNTN_ADDR(base) ((base) + 0x050UL)
#define SOC_XPUINPUT_QICE_VOTE_TOP_FREQ_ADDR(base) ((base) + 0x054UL)
#define SOC_XPUINPUT_EXCE_TYPE_ADDR(base) ((base) + 0x058UL)
#define SOC_XPUINPUT_APP_SCENE_ADDR(base) ((base) + 0x05CUL)
#define SOC_XPUINPUT_BHSACK0_ADDR(base) ((base) + 0x060UL)
#define SOC_XPUINPUT_BHSACK1_ADDR(base) ((base) + 0x064UL)
#define SOC_XPUINPUT_BHSACK2_ADDR(base) ((base) + 0x068UL)
#define SOC_XPUINPUT_NPU_BW_LIMIT_PERCENT_ADDR(base) ((base) + 0x06CUL)
#define SOC_XPUINPUT_DIEID_GROUP_ADDR(base,grp_id) ((base) + 0x070UL + 0x4 * (grp_id))
#define SOC_XPUINPUT_PG_INFO_ADDR(base) ((base) + 0x088UL)
#define SOC_XPUINPUT_DDR_VMIN_ADDR(base) ((base) + 0x08CUL)
#define SOC_XPUINPUT_DDR_VMIN_FREQ_ADDR(base) ((base) + 0x090UL)
#define SOC_XPUINPUT_CKSWAP_ADDR(base) ((base) + 0x094UL)
#define SOC_XPUINPUT_WCKSWAP_ADDR(base) ((base) + 0x098UL)
#define SOC_XPUINPUT_DQSSWAP_ADDR(base) ((base) + 0x09CUL)
#define SOC_XPUINPUT_EFR_DDRBIAS_STATE_ADDR(base) ((base) + 0x0A0UL)
#define SOC_XPUINPUT_EFR_DDRBIAS_VDDCORE_ADDR(base) ((base) + 0x0A4UL)
#define SOC_XPUINPUT_EFR_DDRBIAS_VDDHV_ADDR(base) ((base) + 0x0C4UL)
#define SOC_XPUINPUT_EFR_DDRBIAS_VDDQ_ADDR(base) ((base) + 0x0E4UL)
#define SOC_XPUINPUT_BHSVOFST_ADDR(base) ((base) + 0x0E8UL)
#define SOC_XPUINPUT_DDRINIT_ESCAPE_INFO_ADDR(base) ((base) + 0x0ECUL)
#define SOC_XPUINPUT_BOARD_RUNTIME_ADDR(base) ((base) + 0x0F0UL)
#define SOC_XPUINPUT_EFR_VOLT_COMPENSATE_INFO_ADDR(base) ((base) + 0x0F4UL)
#define SOC_XPUINPUT_BINX_INFO_ADDR(base) ((base) + 0x0F8UL)
#define SOC_XPUINPUT_DDR_DPM_STATUS_ADDR(base) ((base) + 0x0FCUL)
#define SOC_XPUINPUT_DDR_SCHEDULE_SCENE_ADDR(base) ((base) + 0x100UL)
#define SOC_XPUINPUT_ULL_SCENE_ADDR(base) ((base) + 0x104UL)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_ADDR(base) ((base) + 0x108UL)
typedef union {
 unsigned int value;
 struct {
  unsigned int ckswap_ch : 4;
  unsigned int reserved : 28;
 } reg;
} SOC_XPUINPUT_CKSWAP_UNION;
#define SOC_XPUINPUT_CKSWAP_ckswap_ch_START (0)
#define SOC_XPUINPUT_CKSWAP_ckswap_ch_END (3)
typedef union {
 unsigned int value;
 struct {
  unsigned int wckswap_ch : 8;
  unsigned int reserved : 24;
 } reg;
} SOC_XPUINPUT_WCKSWAP_UNION;
#define SOC_XPUINPUT_WCKSWAP_wckswap_ch_START (0)
#define SOC_XPUINPUT_WCKSWAP_wckswap_ch_END (7)
typedef union {
 unsigned int value;
 struct {
  unsigned int dqsswap_ch : 8;
  unsigned int reserved : 24;
 } reg;
} SOC_XPUINPUT_DQSSWAP_UNION;
#define SOC_XPUINPUT_DQSSWAP_dqsswap_ch_START (0)
#define SOC_XPUINPUT_DQSSWAP_dqsswap_ch_END (7)
typedef union {
 unsigned int value;
 struct {
  unsigned int awake : 1;
  unsigned int prepare_suspend : 1;
  unsigned int should_state_retention : 1;
  unsigned int should_bss_retention : 1;
  unsigned int reserved : 28;
 } reg;
} SOC_XPUINPUT_SHOULD_AWAKED_UNION;
#define SOC_XPUINPUT_SHOULD_AWAKED_awake_START (0)
#define SOC_XPUINPUT_SHOULD_AWAKED_awake_END (0)
#define SOC_XPUINPUT_SHOULD_AWAKED_prepare_suspend_START (1)
#define SOC_XPUINPUT_SHOULD_AWAKED_prepare_suspend_END (1)
#define SOC_XPUINPUT_SHOULD_AWAKED_should_state_retention_START (2)
#define SOC_XPUINPUT_SHOULD_AWAKED_should_state_retention_END (2)
#define SOC_XPUINPUT_SHOULD_AWAKED_should_bss_retention_START (3)
#define SOC_XPUINPUT_SHOULD_AWAKED_should_bss_retention_END (3)
typedef union {
 unsigned int value;
 struct {
  unsigned int fpga : 1;
  unsigned int emu : 1;
  unsigned int emupxp : 1;
  unsigned int emulpddr5 : 1;
  unsigned int boot_mode : 1;
  unsigned int board_type : 2;
  unsigned int emu_media1_on : 1;
  unsigned int emu_npu_on : 1;
  unsigned int lowbattery : 1;
  unsigned int tsensor_lowtemp : 1;
  unsigned int ddr_type : 1;
  unsigned int hardware_ddr_id : 4;
  unsigned int init_force_minfreq_en : 1;
  unsigned int close_lp_flag : 1;
  unsigned int bhsack_avail : 1;
  unsigned int bhsvofst_avail : 1;
  unsigned int dieid_avail : 1;
  unsigned int is_ohos : 1;
  unsigned int ate_aging_flag : 2;
  unsigned int lprx_upg_sstl_avail : 1;
  unsigned int is_aging_rtb : 1;
  unsigned int reserved : 6;
 } reg;
} SOC_XPUINPUT_DDRENV_INFO_UNION;
#define SOC_XPUINPUT_DDRENV_INFO_fpga_START (0)
#define SOC_XPUINPUT_DDRENV_INFO_fpga_END (0)
#define SOC_XPUINPUT_DDRENV_INFO_emu_START (1)
#define SOC_XPUINPUT_DDRENV_INFO_emu_END (1)
#define SOC_XPUINPUT_DDRENV_INFO_emupxp_START (2)
#define SOC_XPUINPUT_DDRENV_INFO_emupxp_END (2)
#define SOC_XPUINPUT_DDRENV_INFO_emulpddr5_START (3)
#define SOC_XPUINPUT_DDRENV_INFO_emulpddr5_END (3)
#define SOC_XPUINPUT_DDRENV_INFO_boot_mode_START (4)
#define SOC_XPUINPUT_DDRENV_INFO_boot_mode_END (4)
#define SOC_XPUINPUT_DDRENV_INFO_board_type_START (5)
#define SOC_XPUINPUT_DDRENV_INFO_board_type_END (6)
#define SOC_XPUINPUT_DDRENV_INFO_emu_media1_on_START (7)
#define SOC_XPUINPUT_DDRENV_INFO_emu_media1_on_END (7)
#define SOC_XPUINPUT_DDRENV_INFO_emu_npu_on_START (8)
#define SOC_XPUINPUT_DDRENV_INFO_emu_npu_on_END (8)
#define SOC_XPUINPUT_DDRENV_INFO_lowbattery_START (9)
#define SOC_XPUINPUT_DDRENV_INFO_lowbattery_END (9)
#define SOC_XPUINPUT_DDRENV_INFO_tsensor_lowtemp_START (10)
#define SOC_XPUINPUT_DDRENV_INFO_tsensor_lowtemp_END (10)
#define SOC_XPUINPUT_DDRENV_INFO_ddr_type_START (11)
#define SOC_XPUINPUT_DDRENV_INFO_ddr_type_END (11)
#define SOC_XPUINPUT_DDRENV_INFO_hardware_ddr_id_START (12)
#define SOC_XPUINPUT_DDRENV_INFO_hardware_ddr_id_END (15)
#define SOC_XPUINPUT_DDRENV_INFO_init_force_minfreq_en_START (16)
#define SOC_XPUINPUT_DDRENV_INFO_init_force_minfreq_en_END (16)
#define SOC_XPUINPUT_DDRENV_INFO_close_lp_flag_START (17)
#define SOC_XPUINPUT_DDRENV_INFO_close_lp_flag_END (17)
#define SOC_XPUINPUT_DDRENV_INFO_bhsack_avail_START (18)
#define SOC_XPUINPUT_DDRENV_INFO_bhsack_avail_END (18)
#define SOC_XPUINPUT_DDRENV_INFO_bhsvofst_avail_START (19)
#define SOC_XPUINPUT_DDRENV_INFO_bhsvofst_avail_END (19)
#define SOC_XPUINPUT_DDRENV_INFO_dieid_avail_START (20)
#define SOC_XPUINPUT_DDRENV_INFO_dieid_avail_END (20)
#define SOC_XPUINPUT_DDRENV_INFO_is_ohos_START (21)
#define SOC_XPUINPUT_DDRENV_INFO_is_ohos_END (21)
#define SOC_XPUINPUT_DDRENV_INFO_ate_aging_flag_START (22)
#define SOC_XPUINPUT_DDRENV_INFO_ate_aging_flag_END (23)
#define SOC_XPUINPUT_DDRENV_INFO_lprx_upg_sstl_avail_START (24)
#define SOC_XPUINPUT_DDRENV_INFO_lprx_upg_sstl_avail_END (24)
#define SOC_XPUINPUT_DDRENV_INFO_is_aging_rtb_START (25)
#define SOC_XPUINPUT_DDRENV_INFO_is_aging_rtb_END (25)
typedef union {
 unsigned int value;
 struct {
  unsigned int sr_type : 2;
  unsigned int sr_mode : 3;
  unsigned int can_ddr_sleep : 1;
  unsigned int can_l1bus_sleep : 1;
  unsigned int can_light_sleep : 1;
  unsigned int sr_timepoint : 5;
  unsigned int sr_drv_id : 3;
  unsigned int reserved : 16;
 } reg;
} SOC_XPUINPUT_DDRSR_STAT_UNION;
#define SOC_XPUINPUT_DDRSR_STAT_sr_type_START (0)
#define SOC_XPUINPUT_DDRSR_STAT_sr_type_END (1)
#define SOC_XPUINPUT_DDRSR_STAT_sr_mode_START (2)
#define SOC_XPUINPUT_DDRSR_STAT_sr_mode_END (4)
#define SOC_XPUINPUT_DDRSR_STAT_can_ddr_sleep_START (5)
#define SOC_XPUINPUT_DDRSR_STAT_can_ddr_sleep_END (5)
#define SOC_XPUINPUT_DDRSR_STAT_can_l1bus_sleep_START (6)
#define SOC_XPUINPUT_DDRSR_STAT_can_l1bus_sleep_END (6)
#define SOC_XPUINPUT_DDRSR_STAT_can_light_sleep_START (7)
#define SOC_XPUINPUT_DDRSR_STAT_can_light_sleep_END (7)
#define SOC_XPUINPUT_DDRSR_STAT_sr_timepoint_START (8)
#define SOC_XPUINPUT_DDRSR_STAT_sr_timepoint_END (12)
#define SOC_XPUINPUT_DDRSR_STAT_sr_drv_id_START (13)
#define SOC_XPUINPUT_DDRSR_STAT_sr_drv_id_END (15)
typedef union {
 unsigned int value;
 struct {
  unsigned int loop_infinite : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUINPUT_EXMBIST_TEST_CFG_UNION;
#define SOC_XPUINPUT_EXMBIST_TEST_CFG_loop_infinite_START (0)
#define SOC_XPUINPUT_EXMBIST_TEST_CFG_loop_infinite_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int bpg_start : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUINPUT_BPG_TEST_CFG_UNION;
#define SOC_XPUINPUT_BPG_TEST_CFG_bpg_start_START (0)
#define SOC_XPUINPUT_BPG_TEST_CFG_bpg_start_END (0)
enum xloader_startup_mode {
 LPMCU_STARTUP_MODE = 0,
 ACPU_STARTUP_MODE = 1,
 STARTUP_MODE_MAX,
};
typedef union {
 unsigned int value;
 struct {
  unsigned int startup_mode : 1;
  unsigned int is_qice_init_pre : 1;
  unsigned int reserved : 30;
 } reg;
} SOC_XPUINPUT_XLOADER_MODE_UNION;
#define SOC_XPUINPUT_XLOADER_MODE_startup_mode_START (0)
#define SOC_XPUINPUT_XLOADER_MODE_startup_mode_END (0)
#define SOC_XPUINPUT_XLOADER_MODE_is_qice_init_pre_START (1)
#define SOC_XPUINPUT_XLOADER_MODE_is_qice_init_pre_END (1)
typedef union {
 unsigned int value;
 struct {
  unsigned int ddr_test_type : 4;
  unsigned int exm_sync_en : 1;
  unsigned int exm_cfg_chan_type : 1;
  unsigned int exm_readback : 1;
  unsigned int reserved : 25;
 } reg;
} SOC_XPUINPUT_DDR_TEST_CFG_UNION;
#define SOC_XPUINPUT_DDR_TEST_CFG_ddr_test_type_START (0)
#define SOC_XPUINPUT_DDR_TEST_CFG_ddr_test_type_END (3)
#define SOC_XPUINPUT_DDR_TEST_CFG_exm_sync_en_START (4)
#define SOC_XPUINPUT_DDR_TEST_CFG_exm_sync_en_END (4)
#define SOC_XPUINPUT_DDR_TEST_CFG_exm_cfg_chan_type_START (5)
#define SOC_XPUINPUT_DDR_TEST_CFG_exm_cfg_chan_type_END (5)
#define SOC_XPUINPUT_DDR_TEST_CFG_exm_readback_START (6)
#define SOC_XPUINPUT_DDR_TEST_CFG_exm_readback_END (6)
typedef union {
 unsigned int value;
 struct {
  unsigned int dvfs_enable : 1;
  unsigned int need_artribute : 1;
  unsigned int is_in_sr : 1;
  unsigned int is_in_lowtemp : 1;
  unsigned int reserved : 28;
 } reg;
} SOC_XPUINPUT_DVFS_UNION;
#define SOC_XPUINPUT_DVFS_dvfs_enable_START (0)
#define SOC_XPUINPUT_DVFS_dvfs_enable_END (0)
#define SOC_XPUINPUT_DVFS_need_artribute_START (1)
#define SOC_XPUINPUT_DVFS_need_artribute_END (1)
#define SOC_XPUINPUT_DVFS_is_in_sr_START (2)
#define SOC_XPUINPUT_DVFS_is_in_sr_END (2)
#define SOC_XPUINPUT_DVFS_is_in_lowtemp_START (3)
#define SOC_XPUINPUT_DVFS_is_in_lowtemp_END (3)
typedef union {
 unsigned int value;
 struct {
  unsigned int ddr_min : 4;
  unsigned int ddr_max : 4;
  unsigned int ddr_cur : 4;
  unsigned int ddr_tar : 4;
  unsigned int ddr_last : 4;
  unsigned int reserved : 12;
 } reg;
} SOC_XPUINPUT_DVFS_FREQ_INFO_UNION;
#define SOC_XPUINPUT_DVFS_FREQ_INFO_ddr_min_START (0)
#define SOC_XPUINPUT_DVFS_FREQ_INFO_ddr_min_END (3)
#define SOC_XPUINPUT_DVFS_FREQ_INFO_ddr_max_START (4)
#define SOC_XPUINPUT_DVFS_FREQ_INFO_ddr_max_END (7)
#define SOC_XPUINPUT_DVFS_FREQ_INFO_ddr_cur_START (8)
#define SOC_XPUINPUT_DVFS_FREQ_INFO_ddr_cur_END (11)
#define SOC_XPUINPUT_DVFS_FREQ_INFO_ddr_tar_START (12)
#define SOC_XPUINPUT_DVFS_FREQ_INFO_ddr_tar_END (15)
#define SOC_XPUINPUT_DVFS_FREQ_INFO_ddr_last_START (16)
#define SOC_XPUINPUT_DVFS_FREQ_INFO_ddr_last_END (19)
typedef union {
 unsigned int value;
 struct {
  unsigned int rtc_time : 32;
 } reg;
} SOC_XPUINPUT_RTC_TIME_UNION;
#define SOC_XPUINPUT_RTC_TIME_rtc_time_START (0)
#define SOC_XPUINPUT_RTC_TIME_rtc_time_END (31)
enum ddrrestore_load_status {
 RESTORE_DATA_LOAD_SUCC = 0,
 RESTORE_DATA_LOAD_FAIL,
};
typedef union {
 unsigned int value;
 struct {
  unsigned int load_stat : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUINPUT_DDRRESTORE_STAT_UNION;
#define SOC_XPUINPUT_DDRRESTORE_STAT_load_stat_START (0)
#define SOC_XPUINPUT_DDRRESTORE_STAT_load_stat_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int qice_dvfs_enable : 1;
  unsigned int qice_need_artribute : 1;
  unsigned int reserved : 30;
 } reg;
} SOC_XPUINPUT_QICE_UNION;
#define SOC_XPUINPUT_QICE_qice_dvfs_enable_START (0)
#define SOC_XPUINPUT_QICE_qice_dvfs_enable_END (0)
#define SOC_XPUINPUT_QICE_qice_need_artribute_START (1)
#define SOC_XPUINPUT_QICE_qice_need_artribute_END (1)
typedef union {
 unsigned int value;
 struct {
  unsigned int qice_min : 4;
  unsigned int qice_max : 4;
  unsigned int qice_cur : 4;
  unsigned int qice_tar : 4;
  unsigned int qice_last : 4;
  unsigned int qice_sleep : 4;
  unsigned int reserved : 8;
 } reg;
} SOC_XPUINPUT_QICE_FREQ_INFO_UNION;
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_min_START (0)
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_min_END (3)
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_max_START (4)
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_max_END (7)
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_cur_START (8)
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_cur_END (11)
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_tar_START (12)
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_tar_END (15)
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_last_START (16)
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_last_END (19)
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_sleep_START (20)
#define SOC_XPUINPUT_QICE_FREQ_INFO_qice_sleep_END (23)
typedef union {
 unsigned int value;
 struct {
  unsigned int dmc_int_autogt : 1;
  unsigned int dmc_ext_autogt : 1;
  unsigned int qice_ext_autogt : 1;
  unsigned int ddr_tmp : 1;
  unsigned int ddr_tmp_rec : 1;
  unsigned int ddr_tmp_rst : 1;
  unsigned int ddr_tmp_sharst : 1;
  unsigned int ddr_dfs : 1;
  unsigned int qice_dfs : 1;
  unsigned int vdd2h_cfg : 1;
  unsigned int trefi_cfg : 1;
  unsigned int reserved : 21;
 } reg;
} SOC_XPUINPUT_DDR_LPNV_INFO_UNION;
#define SOC_XPUINPUT_DDR_LPNV_INFO_dmc_int_autogt_START (0)
#define SOC_XPUINPUT_DDR_LPNV_INFO_dmc_int_autogt_END (0)
#define SOC_XPUINPUT_DDR_LPNV_INFO_dmc_ext_autogt_START (1)
#define SOC_XPUINPUT_DDR_LPNV_INFO_dmc_ext_autogt_END (1)
#define SOC_XPUINPUT_DDR_LPNV_INFO_qice_ext_autogt_START (2)
#define SOC_XPUINPUT_DDR_LPNV_INFO_qice_ext_autogt_END (2)
#define SOC_XPUINPUT_DDR_LPNV_INFO_ddr_tmp_START (3)
#define SOC_XPUINPUT_DDR_LPNV_INFO_ddr_tmp_END (3)
#define SOC_XPUINPUT_DDR_LPNV_INFO_ddr_tmp_rec_START (4)
#define SOC_XPUINPUT_DDR_LPNV_INFO_ddr_tmp_rec_END (4)
#define SOC_XPUINPUT_DDR_LPNV_INFO_ddr_tmp_rst_START (5)
#define SOC_XPUINPUT_DDR_LPNV_INFO_ddr_tmp_rst_END (5)
#define SOC_XPUINPUT_DDR_LPNV_INFO_ddr_tmp_sharst_START (6)
#define SOC_XPUINPUT_DDR_LPNV_INFO_ddr_tmp_sharst_END (6)
#define SOC_XPUINPUT_DDR_LPNV_INFO_ddr_dfs_START (7)
#define SOC_XPUINPUT_DDR_LPNV_INFO_ddr_dfs_END (7)
#define SOC_XPUINPUT_DDR_LPNV_INFO_qice_dfs_START (8)
#define SOC_XPUINPUT_DDR_LPNV_INFO_qice_dfs_END (8)
#define SOC_XPUINPUT_DDR_LPNV_INFO_vdd2h_cfg_START (9)
#define SOC_XPUINPUT_DDR_LPNV_INFO_vdd2h_cfg_END (9)
#define SOC_XPUINPUT_DDR_LPNV_INFO_trefi_cfg_START (10)
#define SOC_XPUINPUT_DDR_LPNV_INFO_trefi_cfg_END (10)
typedef union {
 unsigned int value;
 struct {
  unsigned int exce_type : 32;
 } reg;
} SOC_XPUINPUT_EXCE_TYPE_UNION;
#define SOC_XPUINPUT_EXCE_TYPE_exce_type_START (0)
#define SOC_XPUINPUT_EXCE_TYPE_exce_type_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int avs_en : 1;
  unsigned int avs_exceplog : 1;
  unsigned int age_en : 1;
  unsigned int ultimate_flag : 1;
  unsigned int ultimate_ddr_flag : 1;
  unsigned int level_flag : 1;
  unsigned int pg_bin1_flag : 1;
  unsigned int bit136_flag : 1;
  unsigned int adapt_mode1_flag : 1;
  unsigned int adapt_mode2_flag : 1;
  unsigned int adapt_mode3_flag : 1;
  unsigned int adapt_mode1_ddr_flag: 1;
  unsigned int adapt_mode2_ddr_flag: 1;
  unsigned int adapt_mode3_ddr_flag: 1;
  unsigned int drl_dmc_flag : 1;
  unsigned int drl_flag : 1;
  unsigned int reserved : 16;
 } reg;
} SOC_XPUINPUT_DDRAVS_INFO_UNION;
#define SOC_XPUINPUT_DDRAVS_INFO_avs_en_START (0)
#define SOC_XPUINPUT_DDRAVS_INFO_avs_en_END (0)
#define SOC_XPUINPUT_DDRAVS_INFO_avs_exceplog_START (1)
#define SOC_XPUINPUT_DDRAVS_INFO_avs_exceplog_END (1)
#define SOC_XPUINPUT_DDRAVS_INFO_age_en_START (2)
#define SOC_XPUINPUT_DDRAVS_INFO_age_en_END (2)
#define SOC_XPUINPUT_DDRAVS_INFO_ultimate_flag_START (3)
#define SOC_XPUINPUT_DDRAVS_INFO_ultimate_flag_END (3)
#define SOC_XPUINPUT_DDRAVS_INFO_ultimate_ddr_flag_START (4)
#define SOC_XPUINPUT_DDRAVS_INFO_ultimate_ddr_flag_END (4)
#define SOC_XPUINPUT_DDRAVS_INFO_level_flag_START (5)
#define SOC_XPUINPUT_DDRAVS_INFO_level_flag_END (5)
#define SOC_XPUINPUT_DDRAVS_INFO_pg_bin1_flag_START (6)
#define SOC_XPUINPUT_DDRAVS_INFO_pg_bin1_flag_END (6)
#define SOC_XPUINPUT_DDRAVS_INFO_bit136_flag_START (7)
#define SOC_XPUINPUT_DDRAVS_INFO_bit136_flag_END (7)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode1_flag_START (8)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode1_flag_END (8)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode2_flag_START (9)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode2_flag_END (9)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode3_flag_START (10)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode3_flag_END (10)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode1_ddr_flag_START (11)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode1_ddr_flag_END (11)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode2_ddr_flag_START (12)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode2_ddr_flag_END (12)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode3_ddr_flag_START (13)
#define SOC_XPUINPUT_DDRAVS_INFO_adapt_mode3_ddr_flag_END (13)
#define SOC_XPUINPUT_DDRAVS_INFO_drl_dmc_flag_START (14)
#define SOC_XPUINPUT_DDRAVS_INFO_drl_dmc_flag_END (14)
#define SOC_XPUINPUT_DDRAVS_INFO_drl_flag_START (15)
#define SOC_XPUINPUT_DDRAVS_INFO_drl_flag_END (15)
typedef union {
 unsigned int value;
 struct {
  unsigned int uce_mode : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUINPUT_UCE_INFO_UNION;
#define SOC_XPUINPUT_UCE_INFO_uce_mode_START (0)
#define SOC_XPUINPUT_UCE_INFO_uce_mode_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int freq_418_sdr_clk4x : 5;
  unsigned int freq_418_sdr_clk8x : 5;
  unsigned int freq_418_ssdr : 5;
  unsigned int freq_749_clk4x : 5;
  unsigned int freq_749_clk8x : 5;
  unsigned int freq_1066 : 5;
  unsigned int reserved : 2;
 } reg;
} SOC_XPUINPUT_BHSACK0_UNION;
#define SOC_XPUINPUT_BHSACK0_freq_418_sdr_clk4x_START (0)
#define SOC_XPUINPUT_BHSACK0_freq_418_sdr_clk4x_END (4)
#define SOC_XPUINPUT_BHSACK0_freq_418_sdr_clk8x_START (5)
#define SOC_XPUINPUT_BHSACK0_freq_418_sdr_clk8x_END (9)
#define SOC_XPUINPUT_BHSACK0_freq_418_ssdr_START (10)
#define SOC_XPUINPUT_BHSACK0_freq_418_ssdr_END (14)
#define SOC_XPUINPUT_BHSACK0_freq_749_clk4x_START (15)
#define SOC_XPUINPUT_BHSACK0_freq_749_clk4x_END (19)
#define SOC_XPUINPUT_BHSACK0_freq_749_clk8x_START (20)
#define SOC_XPUINPUT_BHSACK0_freq_749_clk8x_END (24)
#define SOC_XPUINPUT_BHSACK0_freq_1066_START (25)
#define SOC_XPUINPUT_BHSACK0_freq_1066_END (29)
typedef union {
 unsigned int value;
 struct {
  unsigned int freq_1536 : 5;
  unsigned int freq_2102 : 5;
  unsigned int freq_2745 : 5;
  unsigned int freq_3187 : 5;
  unsigned int freq_3744 : 5;
  unsigned int freq_4253 : 5;
  unsigned int reserved : 2;
 } reg;
} SOC_XPUINPUT_BHSACK1_UNION;
#define SOC_XPUINPUT_BHSACK1_freq_1536_START (0)
#define SOC_XPUINPUT_BHSACK1_freq_1536_END (4)
#define SOC_XPUINPUT_BHSACK1_freq_2102_START (5)
#define SOC_XPUINPUT_BHSACK1_freq_2102_END (9)
#define SOC_XPUINPUT_BHSACK1_freq_2745_START (10)
#define SOC_XPUINPUT_BHSACK1_freq_2745_END (14)
#define SOC_XPUINPUT_BHSACK1_freq_3187_START (15)
#define SOC_XPUINPUT_BHSACK1_freq_3187_END (19)
#define SOC_XPUINPUT_BHSACK1_freq_3744_START (20)
#define SOC_XPUINPUT_BHSACK1_freq_3744_END (24)
#define SOC_XPUINPUT_BHSACK1_freq_4253_START (25)
#define SOC_XPUINPUT_BHSACK1_freq_4253_END (29)
typedef union {
 unsigned int value;
 struct {
  unsigned int freq_4800 : 5;
  unsigned int freq_418_hdr_clk4x : 5;
  unsigned int reserved : 22;
 } reg;
} SOC_XPUINPUT_BHSACK2_UNION;
#define SOC_XPUINPUT_BHSACK2_freq_4800_START (0)
#define SOC_XPUINPUT_BHSACK2_freq_4800_END (4)
#define SOC_XPUINPUT_BHSACK2_freq_418_hdr_clk4x_START (5)
#define SOC_XPUINPUT_BHSACK2_freq_418_hdr_clk4x_END (9)
typedef union {
 unsigned int value;
 struct {
  unsigned int is_valid : 1;
  unsigned int tailor_strategy : 15;
  unsigned int efuse_value : 16;
 } reg;
} SOC_XPUINPUT_PG_INFO_UNION;
#define SOC_XPUINPUT_PG_INFO_is_valid_START (0)
#define SOC_XPUINPUT_PG_INFO_is_valid_END (0)
#define SOC_XPUINPUT_PG_INFO_tailor_strategy_START (1)
#define SOC_XPUINPUT_PG_INFO_tailor_strategy_END (15)
#define SOC_XPUINPUT_PG_INFO_efuse_value_START (16)
#define SOC_XPUINPUT_PG_INFO_efuse_value_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int tailor_strategy : 8;
  unsigned int reserved : 24;
 } reg;
} SOC_XPUINPUT_BINX_INFO_UNION;
#define SOC_XPUINPUT_BINX_INFO_tailor_strategy_START (0)
#define SOC_XPUINPUT_BINX_INFO_tailor_strategy_END (7)
typedef union {
 unsigned int value;
 struct {
  unsigned int vmin_enable : 1;
  unsigned int init_enable : 1;
  unsigned int marchc_ssh_enable : 1;
  unsigned int reserved : 29;
 } reg;
} SOC_XPUINPUT_DDR_VMIN_UNION;
#define SOC_XPUINPUT_DDR_VMIN_vmin_enable_START (0)
#define SOC_XPUINPUT_DDR_VMIN_vmin_enable_END (0)
#define SOC_XPUINPUT_DDR_VMIN_init_enable_START (1)
#define SOC_XPUINPUT_DDR_VMIN_init_enable_END (1)
#define SOC_XPUINPUT_DDR_VMIN_marchc_ssh_enable_START (2)
#define SOC_XPUINPUT_DDR_VMIN_marchc_ssh_enable_END (2)
typedef union {
 unsigned int value;
 struct {
  unsigned int freq_val : 32;
 } reg;
} SOC_XPUINPUT_DDR_VMIN_FREQ_UNION;
#define SOC_XPUINPUT_DDR_VMIN_FREQ_freq_val_START (0)
#define SOC_XPUINPUT_DDR_VMIN_FREQ_freq_val_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int efr_vddcore_en : 1;
  unsigned int efr_vddhv_en : 1;
  unsigned int efr_vddq_en : 1;
  unsigned int reserved : 29;
 } reg;
} SOC_XPUINPUT_EFR_DDRBIAS_STATE_UNION;
#define SOC_XPUINPUT_EFR_DDRBIAS_STATE_efr_vddcore_en_START (0)
#define SOC_XPUINPUT_EFR_DDRBIAS_STATE_efr_vddcore_en_END (0)
#define SOC_XPUINPUT_EFR_DDRBIAS_STATE_efr_vddhv_en_START (1)
#define SOC_XPUINPUT_EFR_DDRBIAS_STATE_efr_vddhv_en_END (1)
#define SOC_XPUINPUT_EFR_DDRBIAS_STATE_efr_vddq_en_START (2)
#define SOC_XPUINPUT_EFR_DDRBIAS_STATE_efr_vddq_en_END (2)
typedef union {
 unsigned int value;
 struct {
  unsigned int freq_418_hdr_clk4x : 2;
  unsigned int freq_418_sdr_clk4x : 2;
  unsigned int freq_418_sdr_clk8x : 2;
  unsigned int freq_749_clk4x : 2;
  unsigned int freq_749_clk8x : 2;
  unsigned int freq_1066 : 2;
  unsigned int freq_1536 : 2;
  unsigned int freq_2102 : 2;
  unsigned int freq_2745 : 2;
  unsigned int freq_3187 : 2;
  unsigned int reserved : 12;
 } reg;
} SOC_XPUINPUT_BHSVOFST_UNION;
#define SOC_XPUINPUT_BHSVOFST_freq_418_hdr_clk4x_START (0)
#define SOC_XPUINPUT_BHSVOFST_freq_418_hdr_clk4x_END (1)
#define SOC_XPUINPUT_BHSVOFST_freq_418_sdr_clk4x_START (2)
#define SOC_XPUINPUT_BHSVOFST_freq_418_sdr_clk4x_END (3)
#define SOC_XPUINPUT_BHSVOFST_freq_418_sdr_clk8x_START (4)
#define SOC_XPUINPUT_BHSVOFST_freq_418_sdr_clk8x_END (5)
#define SOC_XPUINPUT_BHSVOFST_freq_749_clk4x_START (6)
#define SOC_XPUINPUT_BHSVOFST_freq_749_clk4x_END (7)
#define SOC_XPUINPUT_BHSVOFST_freq_749_clk8x_START (8)
#define SOC_XPUINPUT_BHSVOFST_freq_749_clk8x_END (9)
#define SOC_XPUINPUT_BHSVOFST_freq_1066_START (10)
#define SOC_XPUINPUT_BHSVOFST_freq_1066_END (11)
#define SOC_XPUINPUT_BHSVOFST_freq_1536_START (12)
#define SOC_XPUINPUT_BHSVOFST_freq_1536_END (13)
#define SOC_XPUINPUT_BHSVOFST_freq_2102_START (14)
#define SOC_XPUINPUT_BHSVOFST_freq_2102_END (15)
#define SOC_XPUINPUT_BHSVOFST_freq_2745_START (16)
#define SOC_XPUINPUT_BHSVOFST_freq_2745_END (17)
#define SOC_XPUINPUT_BHSVOFST_freq_3187_START (18)
#define SOC_XPUINPUT_BHSVOFST_freq_3187_END (19)
typedef union {
 unsigned int value;
 struct {
  unsigned int ate_sstl_efuse_freq_418 : 1;
  unsigned int ate_sstl_efuse_freq_749 : 1;
  unsigned int ate_efuse_written_flag : 1;
  unsigned int sstl_en_freq_418 : 1;
  unsigned int sstl_en_freq_749 : 1;
  unsigned int efuse_written : 1;
  unsigned int reserved : 26;
 } reg;
} SOC_XPUINPUT_LPRX_UPG_SSTL_UNION;
#define SOC_XPUINPUT_LPRX_UPG_SSTL_ate_sstl_efuse_freq_418_START (0)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_ate_sstl_efuse_freq_418_END (0)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_ate_sstl_efuse_freq_749_START (1)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_ate_sstl_efuse_freq_749_END (1)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_ate_efuse_written_flag_START (2)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_ate_efuse_written_flag_END (2)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_sstl_en_freq_418_START (3)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_sstl_en_freq_418_END (3)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_sstl_en_freq_749_START (4)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_sstl_en_freq_749_END (4)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_efuse_written_START (5)
#define SOC_XPUINPUT_LPRX_UPG_SSTL_efuse_written_END (5)
typedef union {
 unsigned int value;
 struct {
  unsigned int need_escape : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUINPUT_DDRINIT_ESCAPE_INFO_UNION;
#define SOC_XPUINPUT_DDRINIT_ESCAPE_INFO_need_escape_START (0)
#define SOC_XPUINPUT_DDRINIT_ESCAPE_INFO_need_escape_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int flag_avail : 1;
  unsigned int aging_corner_flag : 2;
  unsigned int reserved : 29;
 } reg;
} SOC_XPUINPUT_EFR_VOLT_COMPENSATE_INFO_UNION;
#define SOC_XPUINPUT_EFR_VOLT_COMPENSATE_INFO_flag_avail_START (0)
#define SOC_XPUINPUT_EFR_VOLT_COMPENSATE_INFO_flag_avail_END (0)
#define SOC_XPUINPUT_EFR_VOLT_COMPENSATE_INFO_aging_corner_flag_START (1)
#define SOC_XPUINPUT_EFR_VOLT_COMPENSATE_INFO_aging_corner_flag_END (2)
typedef union {
 unsigned int value;
 struct {
  unsigned int status : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUINPUT_DDR_DPM_STATUS_UNION;
#define SOC_XPUINPUT_DDR_DPM_STATUS_status_START (0)
#define SOC_XPUINPUT_DDR_DPM_STATUS_status_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int heca_stat : 1;
  unsigned int ai_game_stat : 1;
  unsigned int ai_game_max_cluster : 4;
  unsigned int npu_vote_qice_max_freq_stat : 1;
  unsigned int reserved : 25;
 } reg;
} SOC_XPUINPUT_DDR_SCHEDULE_SCENE_UNION;
#define SOC_XPUINPUT_DDR_SCHEDULE_SCENE_heca_stat_START (0)
#define SOC_XPUINPUT_DDR_SCHEDULE_SCENE_heca_stat_END (0)
#define SOC_XPUINPUT_DDR_SCHEDULE_SCENE_ai_game_stat_START (1)
#define SOC_XPUINPUT_DDR_SCHEDULE_SCENE_ai_game_stat_END (1)
#define SOC_XPUINPUT_DDR_SCHEDULE_SCENE_ai_game_max_cluster_START (2)
#define SOC_XPUINPUT_DDR_SCHEDULE_SCENE_ai_game_max_cluster_END (5)
#define SOC_XPUINPUT_DDR_SCHEDULE_SCENE_npu_vote_qice_max_freq_stat_START (6)
#define SOC_XPUINPUT_DDR_SCHEDULE_SCENE_npu_vote_qice_max_freq_stat_END (6)
typedef union {
 unsigned int value;
 struct {
  unsigned int input_scene : 4;
  unsigned int reserved : 28;
 } reg;
} SOC_XPUINPUT_ULL_SCENE_UNION;
#define SOC_XPUINPUT_ULL_SCENE_input_scene_START (0)
#define SOC_XPUINPUT_ULL_SCENE_input_scene_END (3)
#define SOC_XPUOUTPUT_IS_AWAKED_ADDR(base) ((base) + 0x000UL)
#define SOC_XPUOUTPUT_DDRSR_STAT_ADDR(base) ((base) + 0x014UL)
#define SOC_XPUOUTPUT_DDRTEST_LOOP_CUR_ADDR(base) ((base) + 0x018UL)
#define SOC_XPUOUTPUT_DDRPARA_ENTRY_ADDR_ADDR(base) ((base) + 0x01CUL)
#define SOC_XPUOUTPUT_DDRATGT_STAT_ADDR(base) ((base) + 0x020UL)
#define SOC_XPUOUTPUT_DDRRESTORE_INFO_ADDR(base) ((base) + 0x024UL)
#define SOC_XPUOUTPUT_DDRTMON_INFO_ADDR(base) ((base) + 0x028UL)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_ADDR(base) ((base) + 0x02CUL)
#define SOC_XPUOUTPUT_DDR_DFS_STAT_ADDR(base) ((base) + 0x030UL)
#define SOC_XPUOUTPUT_DDRMNTN_INFO_ADDR(base) ((base) + 0x034UL)
#define SOC_XPUOUTPUT_DDRDAS_ADDR(base) ((base) + 0x038UL)
#define SOC_XPUOUTPUT_LOG_P_ADDR(base) ((base) + 0x03CUL)
#define SOC_XPUOUTPUT_VDD2H_AVS_ADDR(base) ((base) + 0x040UL)
#define SOC_XPUOUTPUT_DDRXPU_LOG_TRANSFER_ADDR(base) ((base) + 0x04CUL)
#define SOC_XPUOUTPUT_PRODUCT_REBOOT_ADDR(base) ((base) + 0x050UL)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_ADDR(base) ((base) + 0x054UL)
#define SOC_XPUOUTPUT_DDRBIAS_EXMBIST_DQ_BITMAP_ADDR(base) ((base) + 0x058UL)
#define SOC_XPUOUTPUT_PPR_REMAP_FLAG_ADDR(base) ((base) + 0x05CUL)
#define SOC_XPUOUTPUT_DDR_VMIN_ADDR(base) ((base) + 0x060UL)
#define SOC_XPUOUTPUT_DDR_VMIN_FREQ_ADDR(base) ((base) + 0x064UL)
#define SOC_XPUOUTPUT_DDR_VMIN_TIMER_ADDR(base) ((base) + 0x068UL)
#define SOC_XPUOUTPUT_DDR_BHS_ADDR(base) ((base) + 0x06CUL)
#define SOC_XPUOUTPUT_DDRINIT_ESCAPE_INFO_ADDR(base) ((base) + 0x070UL)
#define SOC_XPUOUTPUT_DCC_EXCEP_ADDR(base) ((base) + 0x074UL)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_EXT_ADDR(base) ((base) + 0x078UL)
#define SOC_XPUOUTPUT_DDRPOWER_SUM_DRAM_ADDR(base,s_id) ((base) + 0x07CUL + 0x4 * (s_id))
#define SOC_XPUOUTPUT_DDRPOWER_SUM_SOC_ADDR(base,s_id) ((base) + 0x090UL + 0x4 * (s_id))
#define SOC_XPUOUTPUT_DDRPOWER_SUM_QICE_ADDR(base,s_id) ((base) + 0x0A4UL + 0x4 * (s_id))
#define SOC_XPUOUTPUT_CBT_RANK1_REORDER_ADDR(base) ((base) + 0x0B8UL)
typedef union {
 unsigned int value;
 struct {
  unsigned int awake : 1;
  unsigned int core_ready : 1;
  unsigned int reserved : 30;
 } reg;
} SOC_XPUOUTPUT_IS_AWAKED_UNION;
#define SOC_XPUOUTPUT_IS_AWAKED_awake_START (0)
#define SOC_XPUOUTPUT_IS_AWAKED_awake_END (0)
#define SOC_XPUOUTPUT_IS_AWAKED_core_ready_START (1)
#define SOC_XPUOUTPUT_IS_AWAKED_core_ready_END (1)
typedef union {
 unsigned int value;
 struct {
  unsigned int sr_type : 2;
  unsigned int sr_mode : 3;
  unsigned int is_ddr_sleep : 1;
  unsigned int is_l1bus_sleep : 1;
  unsigned int is_light_sleep : 1;
  unsigned int sr_timepoint : 5;
  unsigned int sr_timetick : 1;
  unsigned int sc_workaround_en : 1;
  unsigned int reserved : 17;
 } reg;
} SOC_XPUOUTPUT_DDRSR_STAT_UNION;
#define SOC_XPUOUTPUT_DDRSR_STAT_sr_type_START (0)
#define SOC_XPUOUTPUT_DDRSR_STAT_sr_type_END (1)
#define SOC_XPUOUTPUT_DDRSR_STAT_sr_mode_START (2)
#define SOC_XPUOUTPUT_DDRSR_STAT_sr_mode_END (4)
#define SOC_XPUOUTPUT_DDRSR_STAT_is_ddr_sleep_START (5)
#define SOC_XPUOUTPUT_DDRSR_STAT_is_ddr_sleep_END (5)
#define SOC_XPUOUTPUT_DDRSR_STAT_is_l1bus_sleep_START (6)
#define SOC_XPUOUTPUT_DDRSR_STAT_is_l1bus_sleep_END (6)
#define SOC_XPUOUTPUT_DDRSR_STAT_is_light_sleep_START (7)
#define SOC_XPUOUTPUT_DDRSR_STAT_is_light_sleep_END (7)
#define SOC_XPUOUTPUT_DDRSR_STAT_sr_timepoint_START (8)
#define SOC_XPUOUTPUT_DDRSR_STAT_sr_timepoint_END (12)
#define SOC_XPUOUTPUT_DDRSR_STAT_sr_timetick_START (13)
#define SOC_XPUOUTPUT_DDRSR_STAT_sr_timetick_END (13)
#define SOC_XPUOUTPUT_DDRSR_STAT_sc_workaround_en_START (14)
#define SOC_XPUOUTPUT_DDRSR_STAT_sc_workaround_en_END (14)
typedef union {
 unsigned int value;
 struct {
  unsigned int atgt_init_done : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUOUTPUT_DDRATGT_STAT_UNION;
#define SOC_XPUOUTPUT_DDRATGT_STAT_atgt_init_done_START (0)
#define SOC_XPUOUTPUT_DDRATGT_STAT_atgt_init_done_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int restore_mode : 2;
  unsigned int param_avail : 1;
  unsigned int use_param : 1;
  unsigned int save_param : 1;
  unsigned int reserved : 27;
 } reg;
} SOC_XPUOUTPUT_DDRRESTORE_INFO_UNION;
#define SOC_XPUOUTPUT_DDRRESTORE_INFO_restore_mode_START (0)
#define SOC_XPUOUTPUT_DDRRESTORE_INFO_restore_mode_END (1)
#define SOC_XPUOUTPUT_DDRRESTORE_INFO_param_avail_START (2)
#define SOC_XPUOUTPUT_DDRRESTORE_INFO_param_avail_END (2)
#define SOC_XPUOUTPUT_DDRRESTORE_INFO_use_param_START (3)
#define SOC_XPUOUTPUT_DDRRESTORE_INFO_use_param_END (3)
#define SOC_XPUOUTPUT_DDRRESTORE_INFO_save_param_START (4)
#define SOC_XPUOUTPUT_DDRRESTORE_INFO_save_param_END (4)
typedef union {
 unsigned int value;
 struct {
  unsigned int is_ddr_temp_overlimit : 1;
  unsigned int need_sys_temp_control : 1;
  unsigned int reserved : 30;
 } reg;
} SOC_XPUOUTPUT_DDRTMON_INFO_UNION;
#define SOC_XPUOUTPUT_DDRTMON_INFO_is_ddr_temp_overlimit_START (0)
#define SOC_XPUOUTPUT_DDRTMON_INFO_is_ddr_temp_overlimit_END (0)
#define SOC_XPUOUTPUT_DDRTMON_INFO_need_sys_temp_control_START (1)
#define SOC_XPUOUTPUT_DDRTMON_INFO_need_sys_temp_control_END (1)
typedef union {
 unsigned int value;
 struct {
  unsigned int reboot_reason : 32;
 } reg;
} SOC_XPUOUTPUT_DDRMNTN_INFO_UNION;
#define SOC_XPUOUTPUT_DDRMNTN_INFO_reboot_reason_START (0)
#define SOC_XPUOUTPUT_DDRMNTN_INFO_reboot_reason_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int init_mode : 2;
  unsigned int target_freqid : 4;
  unsigned int max_freqid : 4;
  unsigned int min_freqid : 4;
  unsigned int init_lowtemp : 1;
  unsigned int init_lowbattery : 1;
  unsigned int reserved : 16;
 } reg;
} SOC_XPUOUTPUT_DDRINIT_STRATEGY_UNION;
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_init_mode_START (0)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_init_mode_END (1)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_target_freqid_START (2)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_target_freqid_END (5)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_max_freqid_START (6)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_max_freqid_END (9)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_min_freqid_START (10)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_min_freqid_END (13)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_init_lowtemp_START (14)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_init_lowtemp_END (14)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_init_lowbattery_START (15)
#define SOC_XPUOUTPUT_DDRINIT_STRATEGY_init_lowbattery_END (15)
typedef union {
 unsigned int value;
 struct {
  unsigned int reserved : 32;
 } reg;
} SOC_XPUOUTPUT_DDR_DFS_STAT_UNION;
typedef union {
 unsigned int value;
 struct {
  unsigned int module_status : 8;
  unsigned int das_scene : 8;
  unsigned int reserved : 16;
 } reg;
} SOC_XPUOUTPUT_DDRDAS_UNION;
#define SOC_XPUOUTPUT_DDRDAS_module_status_START (0)
#define SOC_XPUOUTPUT_DDRDAS_module_status_END (7)
#define SOC_XPUOUTPUT_DDRDAS_das_scene_START (8)
#define SOC_XPUOUTPUT_DDRDAS_das_scene_END (15)
typedef union {
 unsigned int value;
 struct {
  unsigned int log_transfer_to_storage : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUOUTPUT_DDRXPU_LOG_TRANSFER_UNION;
#define SOC_XPUOUTPUT_DDRXPU_LOG_TRANSFER_log_transfer_to_storage_START (0)
#define SOC_XPUOUTPUT_DDRXPU_LOG_TRANSFER_log_transfer_to_storage_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int sram_flush : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUOUTPUT_VDD2H_AVS_UNION;
#define SOC_XPUOUTPUT_VDD2H_AVS_sram_flush_START (0)
#define SOC_XPUOUTPUT_VDD2H_AVS_sram_flush_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int reboot_flag : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUOUTPUT_PRODUCT_REBOOT_UNION;
#define SOC_XPUOUTPUT_PRODUCT_REBOOT_reboot_flag_START (0)
#define SOC_XPUOUTPUT_PRODUCT_REBOOT_reboot_flag_END (0)
enum {
 APP_SCENE_DEFAULT = 0,
 APP_SCENE_YUANSHEN,
 APP_SCENE_XINQIONG,
 APP_SCENE_MAX,
};
typedef union {
 unsigned int value;
 struct {
  unsigned int qice_dlock_intr : 1;
  unsigned int qice_ns_intr : 1;
  unsigned int ddr_freq : 4;
  unsigned int last_freq : 4;
  unsigned int core_volt : 10;
  unsigned int last_core_volt : 10;
  unsigned int reserved : 2;
 } reg;
} SOC_XPUOUTPUT_DDRMNTN_RECORD_UNION;
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_qice_dlock_intr_START (0)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_qice_dlock_intr_END (0)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_qice_ns_intr_START (1)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_qice_ns_intr_END (1)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_ddr_freq_START (2)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_ddr_freq_END (5)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_last_freq_START (6)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_last_freq_END (9)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_core_volt_START (10)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_core_volt_END (19)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_last_core_volt_START (20)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_last_core_volt_END (29)
typedef union {
 unsigned int value;
 struct {
  unsigned int exmbist_dq_bitmap : 32;
 } reg;
} SOC_XPUOUTPUT_DDRBIAS_EXMBIST_DQ_BITMAP_UNION;
#define SOC_XPUOUTPUT_DDRBIAS_exmbist_dq_bitmap_START (0)
#define SOC_XPUOUTPUT_DDRBIAS_exmbist_dq_bitmap_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int ppr_remap_flag : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUOUTPUT_PPR_REMAP_FLAG_UNION;
#define SOC_XPUOUTPUT_PPR_REMAP_FLAG_ppr_remap_flag_START (0)
#define SOC_XPUOUTPUT_PPR_REMAP_FLAG_ppr_remap_flag_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int min_norm_eye_area : 12;
  unsigned int reserved : 20;
 } reg;
} SOC_XPUOUTPUT_DDRMNTN_RECORD_EXT_UNION;
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_EXT_min_norm_eye_area_START (0)
#define SOC_XPUOUTPUT_DDRMNTN_RECORD_EXT_min_norm_eye_area_END (11)
typedef union {
 unsigned int value;
 struct {
  unsigned int vmin_enable : 1;
  unsigned int init_enable : 1;
  unsigned int marchc_ssh_enable : 1;
 } reg;
} SOC_XPUOUTPUT_DDR_VMIN_UNION;
#define SOC_XPUOUTPUT_DDR_VMIN_vmin_enable_START (0)
#define SOC_XPUOUTPUT_DDR_VMIN_vmin_enable_END (0)
#define SOC_XPUOUTPUT_DDR_VMIN_init_enable_START (1)
#define SOC_XPUOUTPUT_DDR_VMIN_init_enable_END (1)
#define SOC_XPUOUTPUT_DDR_VMIN_marchc_ssh_enable_START (2)
#define SOC_XPUOUTPUT_DDR_VMIN_marchc_ssh_enable_END (2)
typedef union {
 unsigned int value;
 struct {
  unsigned int freq_val : 32;
 } reg;
} SOC_XPUOUTPUT_DDR_VMIN_FREQ_UNION;
#define SOC_XPUOUTPUT_DDR_VMIN_FREQ_freq_val_START (0)
#define SOC_XPUOUTPUT_DDR_VMIN_FREQ_freq_val_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int vmin_timer_flag : 32;
 } reg;
} SOC_XPUOUTPUT_DDR_VMIN_TIMER_UNION;
#define SOC_XPUOUTPUT_DDR_VMIN_TIMER_vmin_timer_flag_START (0)
#define SOC_XPUOUTPUT_DDR_VMIN_TIMER_vmin_timer_flag_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int vofst_threshold : 2;
  unsigned int reserved : 30;
 } reg;
} SOC_XPUOUTPUT_DDR_BHS_UNION;
#define SOC_XPUOUTPUT_DDR_BHS_vofst_threshold_START (0)
#define SOC_XPUOUTPUT_DDR_BHS_vofst_threshold_END (1)
typedef union {
 unsigned int value;
 struct {
  unsigned int need_escape : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUOUTPUT_DDRINIT_ESCAPE_INFO_UNION;
#define SOC_XPUOUTPUT_DDRINIT_ESCAPE_INFO_need_escape_START (0)
#define SOC_XPUOUTPUT_DDRINIT_ESCAPE_INFO_need_escape_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int dcc_limit_exceed : 32;
 } reg;
} SOC_XPUOUTPUT_DCC_EXCEP_UNION;
#define SOC_XPUOUTPUT_DCC_EXCEP_dcc_limit_exceed_START (0)
#define SOC_XPUOUTPUT_DCC_EXCEP_dcc_limit_exceed_END (31)
typedef union {
 unsigned int value;
 struct {
  unsigned int reorder_en : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUOUTPUT_CBT_RANK1_REORDER_UNION;
#define SOC_XPUOUTPUT_CBT_RANK1_REORDER_reorder_en_START (0)
#define SOC_XPUOUTPUT_CBT_RANK1_REORDER_reorder_en_END (0)
#define SOC_XPUREQUEST_CMD_ADDR(base,cmd_len) ((base) + 0x000UL * (cmd_len) * 0x1)
#define SOC_XPUREQUEST_ARG0_ADDR(base) ((base) + 0x40)
#define SOC_XPUREQUEST_ARG1_ADDR(base) ((base) + 0x44)
#define SOC_XPUREQUEST_ARG2_ADDR(base) ((base) + 0x48)
#define SOC_XPUREQUEST_ARG3_ADDR(base) ((base) + 0x4C)
#define SOC_XPUREQUEST_ARG4_ADDR(base) ((base) + 0x50)
#define SOC_XPUREQUEST_ARG5_ADDR(base) ((base) + 0x54)
#define SOC_XPUREQUEST_RESULT0_ADDR(base) ((base) + 0x58)
#define SOC_XPUREQUEST_RESULT1_ADDR(base) ((base) + 0x5C)
#define SOC_XPUREQUEST_RESULT2_ADDR(base) ((base) + 0x60)
#define SOC_XPUREQUEST_RESULT3_ADDR(base) ((base) + 0x64)
#define SOC_XPUREQUEST_RESULT4_ADDR(base) ((base) + 0x68)
#define SOC_XPUREQUEST_RESULT5_ADDR(base) ((base) + 0x6C)
#define SOC_XPUREQUEST_RESULT6_ADDR(base) ((base) + 0x70)
#define SOC_XPUREQUEST_DDR_CMD_REQUEST_ADDR(base) ((base) + 0x74)
#define SOC_XPUREQUEST_DUBAI_VOTE_DATA_ADDR(base) ((base) + 0x78)
#define SOC_XPUREQUEST_DUBAI_FREQ_DATA_ADDR(base) ((base) + 0x7C)
#define SOC_XPUREQUEST_MAGICWORD_ADDR(base) ((base) + 0x80)
#define SOC_XPUREQUEST_SR_REQUEST_ADDR(base) ((base) + 0x84)
#define SOC_XPUREQUEST_PRODUCT_BOOT_ADDR(base) ((base) + 0x88)
#define SOC_XPUREQUEST_FSTWSC0_ADDR(base) ((base) + 0x8C)
#define SOC_XPUREQUEST_FSTWSC1_ADDR(base) ((base) + 0x90)
#define SOC_XPUREQUEST_FSTWSC2_ADDR(base) ((base) + 0x94)
#define SOC_XPUREQUEST_FSTWSC3_ADDR(base) ((base) + 0x98)
#define SOC_XPUREQUEST_FSTWSC4_ADDR(base) ((base) + 0x9C)
#define SOC_XPUREQUEST_INITESCAPE_ADDR(base) ((base) + 0xA0)
#define SOC_XPUREQUEST_ULL_CPU_DATA_ADDR(base) ((base) + 0xA4)
#define SOC_XPUREQUEST_MNTN_REQUEST_ADDR(base) ((base) + 0xA8)
typedef union {
 unsigned int value;
 struct {
  unsigned int init_req : 1;
  unsigned int test_req : 1;
  unsigned int img_destroy_req : 1;
  unsigned int reserved : 29;
 } reg;
} SOC_XPUREQUEST_DDR_CMD_REQUEST_UNION;
#define SOC_XPUREQUEST_DDR_CMD_REQUEST_init_req_START (0)
#define SOC_XPUREQUEST_DDR_CMD_REQUEST_init_req_END (0)
#define SOC_XPUREQUEST_DDR_CMD_REQUEST_test_req_START (1)
#define SOC_XPUREQUEST_DDR_CMD_REQUEST_test_req_END (1)
#define SOC_XPUREQUEST_DDR_CMD_REQUEST_img_destroy_req_START (2)
#define SOC_XPUREQUEST_DDR_CMD_REQUEST_img_destroy_req_END (2)
typedef union {
 unsigned int value;
 struct {
  unsigned int valid : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUREQUEST_DUBAI_VOTE_DATA_UNION;
#define SOC_XPUREQUEST_DUBAI_VOTE_DATA_valid_START (0)
#define SOC_XPUREQUEST_DUBAI_VOTE_DATA_valid_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int valid : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUREQUEST_DUBAI_FREQ_DATA_UNION;
#define SOC_XPUREQUEST_DUBAI_FREQ_DATA_valid_START (0)
#define SOC_XPUREQUEST_DUBAI_FREQ_DATA_valid_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int prepare_sr_req : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUREQUEST_SR_REQUEST_UNION;
#define SOC_XPUREQUEST_SR_REQUEST_prepare_sr_req_START (0)
#define SOC_XPUREQUEST_SR_REQUEST_prepare_sr_req_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int product_boot_req : 1;
  unsigned int dram_repower_req : 1;
  unsigned int reserved : 30;
 } reg;
} SOC_XPUREQUEST_PRODUCT_BOOT_UNION;
#define SOC_XPUREQUEST_PRODUCT_BOOT_product_boot_req_START (0)
#define SOC_XPUREQUEST_PRODUCT_BOOT_product_boot_req_END (0)
#define SOC_XPUREQUEST_PRODUCT_BOOT_dram_repower_req_START (1)
#define SOC_XPUREQUEST_PRODUCT_BOOT_dram_repower_req_END (1)
typedef union {
 unsigned int value;
 struct {
  unsigned int ull_cpu_en : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUREQUEST_ULL_CPU_DATA_UNION;
#define SOC_XPUREQUEST_ULL_CPU_DATA_ull_cpu_en_START (0)
#define SOC_XPUREQUEST_ULL_CPU_DATA_ull_cpu_en_END (0)
typedef union {
 unsigned int value;
 struct {
  unsigned int prepare_mntn_req : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_XPUREQUEST_MNTN_REQUEST_UNION;
#define SOC_XPUREQUEST_MNTN_REQUEST_prepare_mntn_req_START (0)
#define SOC_XPUREQUEST_MNTN_REQUEST_prepare_mntn_req_END (0)
#endif
