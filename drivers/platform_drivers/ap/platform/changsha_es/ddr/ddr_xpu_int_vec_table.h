#ifndef __DDR_XPU_INT_VEC_TABLE_H__
#define __DDR_XPU_INT_VEC_TABLE_H__ 
#include <ddr_define.h>
#include <soc_xpu_lp_ctrl_cfg_interface.h>
#define INTR_COMBINED_UCE_TO_DDRXPU_CH_MAX 4
#define DDRXPU_TO_LPMCU_INTR_BIT_OFFSET SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_intr_xpu_lp_ctrl_to_lpmcu_mask_START
enum ddr_xpu_intr_no {
 INTR_WATCHDOG = 0,
 INTR_FREQ_VOTE_TO_DDR_LP_CTRL = 3,
 INTR_FAST_CFG0 = 6,
 INTR_FAST_CFG1 = 7,
 INTR_FAST_CFG2 = 8,
 INTR_FAST_CFG3 = 9,
 INTR_FAST_CFG4 = 10,
 INTR_FAST_CFG5 = 11,
 INTR_FAST_CFG6 = 12,
 INTR_FAST_CFG7 = 13,
 INTR_TIMER0 = 14,
 INTR_TIMER1 = 15,
 INTR_UART = 16,
 INTR_IPC_NS_TO_DDR_LP_CTRL = 17,
 INTR_IPC_S_TO_DDR_LP_CTRL = 18,
 INTR_RTOS_IPC_NS_TO_DDR_LP_CTRL = 19,
 INTR_COMBINED_UCE_TO_DDRXPU_A_CFG0 = 32,
 INTR_COMBINED_UCE_TO_DDRXPU_A_CFG1 = 33,
 INTR_COMBINED_UCE_TO_DDRXPU_A_DDRC = 34,
 INTR_COMBINED_UCE_TO_DDRXPU_A_UCE = 35,
 INTR_COMBINED_UCE_TO_DDRXPU_B_CFG0 = 36,
 INTR_COMBINED_UCE_TO_DDRXPU_B_CFG1 = 37,
 INTR_COMBINED_UCE_TO_DDRXPU_B_DDRC = 38,
 INTR_COMBINED_UCE_TO_DDRXPU_B_UCE = 39,
 INTR_COMBINED_UCE_TO_DDRXPU_C_CFG0 = 40,
 INTR_COMBINED_UCE_TO_DDRXPU_C_CFG1 = 41,
 INTR_COMBINED_UCE_TO_DDRXPU_C_DDRC = 42,
 INTR_COMBINED_UCE_TO_DDRXPU_C_UCE = 43,
 INTR_COMBINED_UCE_TO_DDRXPU_D_CFG0 = 44,
 INTR_COMBINED_UCE_TO_DDRXPU_D_CFG1 = 45,
 INTR_COMBINED_UCE_TO_DDRXPU_D_DDRC = 46,
 INTR_COMBINED_UCE_TO_DDRXPU_D_UCE = 47,
 INTR_HBUS_TIMEOUT = 48,
 INTR_COMBINED_UCE_TO_DDRXPU_E_CFG0 = 49,
 INTR_COMBINED_UCE_TO_DDRXPU_E_CFG1 = 50,
 INTR_COMBINED_UCE_TO_DDRXPU_E_DDRC = 51,
 INTR_COMBINED_UCE_TO_DDRXPU_E_UCE = 52,
 INTR_COMBINED_UCE_TO_DDRXPU_F_CFG0 = 53,
 INTR_COMBINED_UCE_TO_DDRXPU_F_CFG1 = 54,
 INTR_COMBINED_UCE_TO_DDRXPU_F_DDRC = 55,
 INTR_COMBINED_UCE_TO_DDRXPU_F_UCE = 56,
 INTR_COMBINED_UCE_TO_DDRXPU_G_CFG0 = 57,
 INTR_COMBINED_UCE_TO_DDRXPU_G_CFG1 = 58,
 INTR_COMBINED_UCE_TO_DDRXPU_G_DDRC = 59,
 INTR_COMBINED_UCE_TO_DDRXPU_G_UCE = 60,
 INTR_COMBINED_UCE_TO_DDRXPU_H_CFG0 = 61,
 INTR_COMBINED_UCE_TO_DDRXPU_H_CFG1 = 62,
 INTR_COMBINED_UCE_TO_DDRXPU_H_DDRC = 63,
 INTR_COMBINED_UCE_TO_DDRXPU_H_UCE = 64,
 INTR_MAX = 65,
};
enum ddr_xpu_to_lpmcu_intr_no {
 INTR_DDR_XPU_TO_LPMCU_RESERVED0 = 0,
 INTR_DDR_XPU_TO_LPMCU_RESERVED1 = 1,
 INTR_DDR_XPU_TO_LPMCU_WATCHDOG = 2,
 INTR_DDR_XPU_TO_LPMCU_CFG0 = 3,
 INTR_DDR_XPU_TO_LPMCU_CFG1 = 4,
 INTR_DDR_XPU_TO_LPMCU_MAX = 5,
};
enum fast_cfg_intr_def {
 FAST_CFG_GENERAL,
 FAST_CFG_DDR_SFC_MRR_CMD,
 FAST_CFG_RESERVED2,
 FAST_CFG_RESERVED3,
 FAST_CFG_RESERVED4,
 FAST_CFG_RESERVED5,
 FAST_CFG_RESERVED6,
 FAST_CFG_RESERVED7,
 FAST_CFG_INTR_MAX,
};
enum ddr_xpu_to_lpmcu_data_id {
 DDR_XPU_TO_LPMCU_DATA_VOTE,
 DDR_XPU_TO_LPMCU_DATA_FREQ,
 DDR_XPU_TO_LPMCU_DATA_TMON,
 DDR_XPU_TO_LPMCU_DATA_XPU_WDG,
 DDR_XPU_TO_LPMCU_DATA_MAX,
};
enum ddr_dfs_on_off_ctrl_cmd {
 DDR_DFS_CLOSE,
 DDR_DFS_OPEN,
 DDR_DFS_RECOVER,
 DDR_DFS_ON_OFF_CTRL_CMD_MAX,
};
union xpu_fast_cfg_dfs_on_off_str {
 unsigned int value;
 struct {
  unsigned int ctrl_cmd : 4;
  unsigned int ack : 4;
  unsigned int reserved : 24;
 } reg;
};
union xpu_fast_cfg_dfs_directly_str {
 unsigned int value;
 struct {
  unsigned int freq_id : 8;
  unsigned int ack : 4;
  unsigned int reserved : 20;
 } reg;
};
union xpu_fast_cfg_dfs_lowtemp_str {
 unsigned int value;
 struct {
  unsigned int is_lowtemp;
 } reg;
};
union xpu_to_lpmcu_vote_data {
 unsigned int value;
 struct {
  unsigned int valid : 1;
  unsigned int reserved : 31;
 } reg;
};
union xpu_to_lpmcu_freq_data {
 unsigned int value;
 struct {
  unsigned int valid : 1;
  unsigned int reserved : 31;
 } reg;
};
union xpu_to_lpmcu_tmon_data {
 unsigned int value;
 unsigned char tmon_upd_intsts[CHANNEL_MAX_NUM];
};
union xpu_fast_cfg_boot_init_str {
 unsigned int value;
 struct {
  unsigned int is_restore: 1;
  unsigned int low_temp: 3;
  unsigned int init_mode: 3;
  unsigned int target_freq: 4;
  unsigned int para_modify_flag: 1;
  unsigned int ack: 1;
 } reg;
};
#endif
