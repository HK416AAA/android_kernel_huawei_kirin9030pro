#ifndef __DDR_PARA_TRANSFER_STR_H__
#define __DDR_PARA_TRANSFER_STR_H__ 
#ifndef DDR_UEFI_VERSION
#include <types.h>
#else
#include <Ddr/DdrUefiTypes.h>
#endif
#define DDR_ADDR_ALIGN(addr,align) (((uintptr_t)(addr) + (align) - 1) / (align) * (align))
#define ATF_ALIGN_LENGTH 8
#define FASTBOOT_SEC_DATA_ADDR ATF_BL2_DDR_SHMEM_ADDR
#define FASTBOOT_SEC_DATA_SIZE 0x100
#define FASTBOOT_INFO_DATA_ADDR (FASTBOOT_SEC_DATA_ADDR + FASTBOOT_SEC_DATA_SIZE)
#define FASTBOOT_INFO_DATA_SIZE (ATF_BL2_DDR_SHMEM_SIZE - (FASTBOOT_INFO_DATA_ADDR - FASTBOOT_SEC_DATA_ADDR))
#define DDR_ADDR_PARA_MAX 8
#define DDR_NUM_PARA_MAX 7
enum {
    DDR_IDX_TARGET_INFO = 0,
    DDR_IDX_FEATURE = 1,
    DDR_IDX_L1BUS_FEATURE = 2,
    DDR_IDX_INIT_INFO = 3,
    DDR_IDX_L1BUS_INIT_INFO = 4,
    DDR_IDX_PROFILE = 5,
    DDR_IDX_L1BUS_PROFILE = 6,
    DDR_IDX_IO_PROFILE = 7,
    DDR_IDX_UCE_CTRL_CFG = 8,
    DDR_IDX_AVS_CTRL_CFG = 9,
    DDR_IDX_TRAIN_PARAM = 10,
    DDR_IDX_TRAIN_PARAM_FOR_UCE = 11,
    DDR_IDX_ADJUST_TACTIC = 12,
    DDR_IDX_ADJUST_TACTIC_LT = 13,
    DDR_IDX_L1BUS_CFG = 14,
    DDR_IDX_SEC_BYPASS_CFG = 15,
    DDR_IDX_DBC_CFG = 16,
    DDR_IDX_UCE_FIRMWARE_ADDR = 17,
    DDR_IDX_TRAINIG_RESULT_IDX_MAP_ADDR = 18,
    DDR_IDX_PHY_ADDR_INFO = 19,
    DDR_IDX_RESTORE_STATUS = 20,
    DDR_IDX_AVS_CHIP_TYPE = 21,
    DDR_IDX_RUNTIME_VALUE = 22,
    DDR_IDX_NUMS_STRUCT = 23,
    DDR_IDX_TRANSFER_DATA_MAX = 24,
};
enum {
    TARGET_LPMCU = 0,
    TARGET_FASTBOOT,
    TARGET_XPU,
    TARGET_CPU_MAX,
};
struct transfer_data_str {
    u64 target_cpu;
    u64 data_idx;
    u64 source_addr;
    u64 source_size;
    u64 source_item_num;
    u64 target_addr;
    u64 target_size;
};
typedef struct fastboot_ddr_para {
    u64 ddr_target_info;
    u64 ddr_init_info;
    u64 ddr_train_param;
    u64 ddr_train_param_for_uce;
    u64 ddr_phy_addr_info_str;
    u64 restore_status;
    u64 ddr_avs_chip_type;
} UEFI_DDR_PARA_T;
struct lpm3_ddr_para {
    u64 ddr_target_info;
    u64 feature;
    u64 l1bus_feature;
    u64 ddr_init_info;
    u64 l1bus_init_info;
    u64 ddr_profile;
    u64 l1bus_profile;
    u64 ddr_io_profile;
    u64 uce_ctrl_cfg;
    u64 ddr_train_param;
    u64 ddr_train_param_for_uce;
    u64 sec_bypass_cfg;
    u64 dmss_axi_cfg;
    u64 l1bus_fc_cfg;
    u64 dbc_cfg;
    u64 trainig_result_idx_map_addr;
    u64 runtime_info_cfg;
    u64 runtime_num_cfg;
};
struct xpu_ddr_para {
    u64 ddr_target_info;
    u64 feature;
    u64 l1bus_feature;
    u64 ddr_init_info;
    u64 l1bus_init_info;
    u64 ddr_profile;
    u64 l1bus_profile;
    u64 ddr_io_profile;
    u64 uce_ctrl_cfg;
    u64 ddr_train_param;
    u64 ddr_adjust_tactic;
    u64 ddr_adjust_tactic_lt;
    u64 trainig_result_idx_map_addr;
    u64 runtime_num_cfg;
};
struct xpu_ddr_boot_para {
    u32 ddr_init_info;
    u32 feature;
    u32 ddr_profile;
    u32 init_training_cfg;
    u32 ddr_io_profile;
    u32 uce_ctrl_cfg;
    u32 ddr_timing_x8;
    u32 boot_num_cfg;
    u32 ddr_share_para;
};
#endif
