#ifndef __DDRTEST_GLOBAL_SRAM_MAP_H_
#define __DDRTEST_GLOBAL_SRAM_MAP_H_ 
#include <soc_lpmcu_baseaddr_interface.h>
#include <soc_acpu_baseaddr_interface.h>
#include <ddr_define.h>
#ifndef DDR_BASE_ADDR_LPMCU
#define DDRTEST_RAM_BASE SOC_ACPU_IOMCU_ITCM_BASE_ADDR
#else
#define DDRTEST_RAM_BASE SOC_LPMCU_IOMCU_ITCM_BASE_ADDR
#endif
#define DDRTEST_EX_SPINLOCK_BASE DDRTEST_RAM_BASE
#define DDRTEST_EX_SPINLOCK_SIZE 0x100UL
#define DDRTEST_UART_SPINLOCK DDRTEST_EX_SPINLOCK_BASE
#define DDRTEST_LOG_SPINLOCK (DDRTEST_UART_SPINLOCK + 0x8UL)
#define DDRTEST_STORAGE_SPINLOCK (DDRTEST_LOG_SPINLOCK + 0x8UL)
#define DDRTEST_LOG_BUFFER_SPINLOCK (DDRTEST_STORAGE_SPINLOCK + 0x8UL)
#define DDRTEST_ACPU_LOG_BASE (DDRTEST_EX_SPINLOCK_BASE + DDRTEST_EX_SPINLOCK_SIZE)
#define DDRTEST_ACPU_LOG_SIZE 0x16800UL
#define DDRTEST_LPMCU_LOG_BASE (DDRTEST_ACPU_LOG_BASE + DDRTEST_ACPU_LOG_SIZE)
#define DDRTEST_LPMCU_LOG_SIZE 0x16800UL
#define DDRTEST_LOG_END (DDRTEST_LPMCU_LOG_BASE + DDRTEST_LPMCU_LOG_SIZE)
#define DDRTEST_RECORD_BASE (DDRTEST_LOG_END + 0x800UL)
#define DDRTEST_RECORD_NR 100
#define DDRTEST_RECORD_SIZE ((32 * DDRTEST_RECORD_NR) + 16)
#define DDRTEST_ACPU_RECORD_BASE DDRTEST_RECORD_BASE
#define DDRTEST_LPMCU_RECORD_BASE (DDRTEST_ACPU_RECORD_BASE + DDRTEST_RECORD_SIZE)
#define DDRTEST_RECORD_END (DDRTEST_LPMCU_RECORD_BASE + DDRTEST_RECORD_SIZE)
#define DDRTEST_REG_INFO_BASE DDRTEST_RECORD_END
#define DDRTEST_REG_INFO_SIZE 0x1000UL
#define DDRTEST_REG_TRAIN_BASE (DDRTEST_REG_INFO_BASE + DDRTEST_REG_INFO_SIZE)
#define DDRTEST_REG_TRAIN_SIZE 0x2800UL
#ifndef DDR_BASE_ADDR_LPMCU
#define DDRTEST_ERROR_AP_FLAG SOC_SCTRL_SCDDRADDR_ADDR(SOC_ACPU_SCTRL_BASE_ADDR)
#define DDRTEST_ERROR_LPM3_FLAG SOC_SCTRL_SCDDRDATA_ADDR(SOC_ACPU_SCTRL_BASE_ADDR)
#else
#define DDRTEST_ERROR_AP_FLAG SOC_SCTRL_SCDDRADDR_ADDR(SOC_LPMCU_SCTRL_BASE_ADDR)
#define DDRTEST_ERROR_LPM3_FLAG SOC_SCTRL_SCDDRDATA_ADDR(SOC_LPMCU_SCTRL_BASE_ADDR)
#endif
#if defined(CONFIG_FACTORY_MODE) || defined(FACTORY_VERSION)
#define PART_DDR_TEST PART_HIBENCH_LOG
#define STORAGE_FSM_LOG_OFFSET 0
#else
#define PART_DDR_TEST PART_DDRTEST
#define STORAGE_FSM_LOG_OFFSET 0
#endif
#define STORAGE_FSM_CFG_OFFSET (STORAGE_FSM_LOG_OFFSET + 0x8000UL)
#define STORAGE_ACPU_LOG_OFFSET (STORAGE_FSM_LOG_OFFSET + 0x100000UL)
#define STORAGE_LPM3_LOG_OFFSET (STORAGE_ACPU_LOG_OFFSET + DDRTEST_ACPU_LOG_SIZE)
#define STORAGE_ACPU_RECORD_OFFSET (STORAGE_FSM_LOG_OFFSET + 0x200000UL)
#define STORAGE_LPM3_RECORD_OFFSET (STORAGE_ACPU_RECORD_OFFSET + DDRTEST_RECORD_SIZE)
#define STORAGE_TRAIN_INIT_OFFSET (STORAGE_FSM_LOG_OFFSET + 0x300000UL)
#define STORAGE_TRAIN_CUR_OFFSET (STORAGE_TRAIN_INIT_OFFSET + DDRTEST_REG_TRAIN_SIZE)
#define STORAGE_TRAIN_REINIT_OFFSET (STORAGE_TRAIN_CUR_OFFSET + DDRTEST_REG_TRAIN_SIZE)
#define STORAGE_REG_DUMP_OFFSET (STORAGE_TRAIN_REINIT_OFFSET + DDRTEST_REG_TRAIN_SIZE)
#define STORAGE_AVS_VMIN_CFG_OFFSET (STORAGE_REG_DUMP_OFFSET + DDRTEST_REG_TRAIN_SIZE)
#define DDRTEST_ACPU_RECORD_MAGIC ("AP")
#define DDRTEST_LPM3_RECORD_MAGIC ("M3")
#define PART_DDR_TEST_LOG PART_DDR_TEST
#define PART_DDR_TEST_LOG_OFFSET (STORAGE_FSM_LOG_OFFSET + 0)
#define PART_DDR_TEST_IMAGE PART_DDR_TEST
#define PART_DDR_TEST_IMAGE_OFFSET (STORAGE_FSM_LOG_OFFSET + 0x400000UL)
#define PART_DDR_PARA_TEST PART_DDR_TEST
#define PART_DDR_PARA_TEST_OFFSET (STORAGE_FSM_LOG_OFFSET + 0xC00000UL)
#define PART_DDR_TEST_LPM3 PART_DDR_TEST
#define PART_DDR_TEST_LPM3_OFFSET (STORAGE_FSM_LOG_OFFSET + 0xf00000UL)
#define PART_LOW_TEMP_MAGIC_OFFSET (PART_DDR_TEST_LPM3_OFFSET + 0x80000UL)
#define DDR_LOW_TEMP_SIMU_MAGIC 0xAECDBCEAU
struct ddrtest_error_header {
    char magic_number[4];
    unsigned int error_counter;
    unsigned int wr_index;
    unsigned int overflow : 1;
    unsigned int freq_prod : 3;
    unsigned int reserved : 4;
};
struct ddrtest_error_data {
    unsigned int addr_h;
    unsigned int addr_l;
    unsigned int expect_data;
    unsigned int actual_data;
    unsigned int algo_id;
    unsigned int reserved[3];
};
struct ddrtest_error_info {
    struct ddrtest_error_header header;
    struct ddrtest_error_data data[DDRTEST_RECORD_NR];
};
enum {
     VDD2_MAKEUP_TEMP = 0,
     VDD2_MAKEUP_AGING,
     VDD2_MAKEUP_HARD,
     VDD2_MAKEUP_INHERENT,
     VDD2_MAKEUP_NUM,
 };
enum {
    DISABLE_REASON_ZERO = 0,
    DISABLE_REASON_ESCAPE,
    DISABLE_REASON_HALT,
};
struct dram_voltage_ctrl {
    unsigned int magic_head;
    unsigned int vmin_get;
    unsigned int vmin_set;
    unsigned int vmin_save;
    unsigned int normalvol_boot;
    unsigned int vmin_algo;
    unsigned int voltage_triggered;
    unsigned int voltage_min;
    unsigned int voltage_max;
    unsigned int voltage_makeup[VDD2_MAKEUP_NUM];
    unsigned int magic_tail;
};
#define VDD2_RESULT_VERSION 0x90100002
struct dram_voltage_result {
    unsigned int escape_time;
    unsigned int clean_reason;
    unsigned int halt_type;
    unsigned int result_version;
    unsigned int magic_head[FREQ_NUM_MAX];
    unsigned int normalvol_boot[FREQ_NUM_MAX];
    unsigned int voltage_triggered[FREQ_NUM_MAX];
    unsigned int voltage_final[FREQ_NUM_MAX];
    unsigned int err_num[FREQ_NUM_MAX];
    unsigned int self_test_result[FREQ_NUM_MAX];
    int linear_fit_ca_ck_diff[FREQ_NUM_MAX][4];
    unsigned int magic_tail[FREQ_NUM_MAX];
};
struct exm_vmin_result
{
    unsigned int vmin_result;
    unsigned int err_num;
    int fit_result[4];
};
#define MID_MEM_AVS_MAX 100
#define DRAM_AVS_RESULT_MAGIC 0xBAADF00D
#define TREFI_SCAN_GEAR_MAX 20
struct mid_mem_avs_volt {
    unsigned int count;
    unsigned int data[MID_MEM_AVS_MAX];
};
typedef struct dram_voltage_result DRAM_VOLTAGE_RESULT;
typedef struct mid_mem_avs_volt MID_MEM_AVS_VOLT;
typedef struct dram_trefi_result DRAM_TREFI_RESULT;
struct dram_trefi_ctrl {
    unsigned int magic_head;
    unsigned int trefi_times;
    unsigned int trefi_freq;
    unsigned int trefi_algo;
    unsigned int trefi_waittime;
    unsigned int trefi_gaptime;
    unsigned int trefi_use;
    unsigned int scan_total_time;
    unsigned int trefi_scan_gear[TREFI_SCAN_GEAR_MAX];
    unsigned int trefi_base_gaptime;
    unsigned int magic_tail;
};
struct dram_trefi_result {
    unsigned int magic_head;
    unsigned int trefi_res;
    unsigned int trefi_whole;
    unsigned int trefi_use;
    unsigned int magic_tail;
};
struct core_avs_voltage_result {
    unsigned int magic_head[FREQ_NUM_MAX];
    unsigned int final_volt[FREQ_NUM_MAX];
    unsigned int magic_tail[FREQ_NUM_MAX];
};
#define DDR_SCREEN_EXMBIST_MAGIC 0xA01DBEEF
#define DDR_SCREEN_EXMBIST_TESTED_MAGIC 0xBEEFF00D
#define DDR_SCREEN_EXMBIST_TEST_PART "flash_ageing"
#define DDR_SCREEN_EXMBIST_CTRL_OFFSET 0x10000
#define DDR_SCREEN_EXMBIST_CTRL_SIZE 0x10000
#define DDR_EXMBIST_LOG_OFFSET (DDR_SCREEN_EXMBIST_CTRL_OFFSET + DDR_SCREEN_EXMBIST_CTRL_SIZE)
#define DDR_EXMBIST_LOG_SIZE 0x1FFE0000UL
#if defined(CONFIG_FACTORY_MODE) || defined(FACTORY_VERSION)
#define PART_DDRTESTLOG DDR_SCREEN_EXMBIST_TEST_PART
#define DDRTESTLOG_OFFSET DDR_EXMBIST_LOG_OFFSET
#define DDRTESTLOG_SIZE DDR_EXMBIST_LOG_SIZE
#else
#define PART_DDRTESTLOG NULL
#define DDRTESTLOG_OFFSET 0
#define DDRTESTLOG_SIZE 0
#endif
#define DDR_SCREEN_MBIST_NORMAL_VOL_SEL 0x0
#define DDR_SCREEN_MBIST_LOW_VOL_SEL 0x1
#define DDR_SCREEN_MBIST_HIGH_VOL_SEL 0x2
struct ddr_screen_exmbist_ctrl {
    unsigned int magic_head;
    unsigned int vol_sel;
    unsigned int freq_sel;
    unsigned int algo_bitmap;
    unsigned int test_time;
    unsigned int magic_tail;
};
#endif
