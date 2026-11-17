#ifndef __DDR_XPU_OPEN_PRODUCT_SRAM_MAP_H__
#define __DDR_XPU_OPEN_PRODUCT_SRAM_MAP_H__ 
#include "ddr/ddr_remap_interface.h"
#include "soc_efuse_interface.h"
#include "ddr/ddrtest_global_sram_map.h"
#include "ddr_xpu_sram_map.h"
#include "ddr/ddr_screen_data_stuct.h"
#include "ddr/ddr_restore_map.h"
#define EFUSE_ITEM_MAX_SIZE 5
#define STORAGE_ITEM_MAX_SIZE 5
#define NVE_ITEM_MAX_SIZE 5
#define PTABLE_NAME_MAX 15
#define MAX_PPR_NV_LEN 104
#define EFUSE_DIEID_GROUP_WIDTH (5)
#define SYS_EFUSE1 0
#define PPR_NV_BASE (DDR_XPU_PRODUCT_STATE_BASE)
#define PPR_NV_SIZE (MAX_PPR_NV_LEN)
#define DIED_ID_BASE (PPR_NV_BASE + PPR_NV_SIZE)
#define DIED_ID_SIZE (EFUSE_DIEID_GROUP_WIDTH * sizeof(unsigned int))
#define SCREEN_EXMBIST_CTRL_BASE (DIED_ID_BASE + DIED_ID_SIZE)
#define SCREEN_EXMBIST_CTRL_SIZE (sizeof(struct ddr_screen_exmbist_ctrl))
#define DDRTEST_FSM_PROCESS_BASE (SCREEN_EXMBIST_CTRL_BASE + SCREEN_EXMBIST_CTRL_SIZE)
#define DDRTEST_FSM_PROCESS_SIZE (sizeof(struct ddrtest_process_record))
#define DDRAVS_VOLTAGE_CTRL_BASE (DDRTEST_FSM_PROCESS_BASE + DDRTEST_FSM_PROCESS_SIZE)
#define DDRAVS_VOLTAGE_CTRL_SIZE (sizeof(struct dram_voltage_ctrl) * FREQ_NUM_MAX)
#define DDRAVS_TREFI_CTRL_BASE (DDRAVS_VOLTAGE_CTRL_BASE + DDRAVS_VOLTAGE_CTRL_SIZE)
#define DDRAVS_TREFI_CTRL_SIZE (sizeof(struct dram_trefi_ctrl))
#define DDRAVS_VOLTAGE_RESULT_BASE (DDRAVS_TREFI_CTRL_BASE + DDRAVS_TREFI_CTRL_SIZE)
#define DDRAVS_VOLTAGE_RESULT_SIZE (sizeof(struct dram_voltage_result))
#define DDRAVS_TREFI_RESULT_BASE (DDRAVS_VOLTAGE_RESULT_BASE + DDRAVS_VOLTAGE_RESULT_SIZE)
#define DDRAVS_TREFI_RESULT_SIZE (sizeof(struct dram_trefi_result))
#define PRODUCT_STATE_BASE (DDRAVS_TREFI_RESULT_BASE + DDRAVS_TREFI_RESULT_SIZE)
#define PRODUCT_STATE_SIZE 0x20
        #define BOARDID_BASE (PRODUCT_STATE_BASE)
#define DDR_PENGLAI_BASE (PRODUCT_STATE_BASE + PRODUCT_STATE_SIZE)
#define DDR_PENGLAI_SIZE 0x10
#define DDR_XPU_PRODUCT_STATE_END (DDR_PENGLAI_BASE + DDR_PENGLAI_SIZE)
#endif
