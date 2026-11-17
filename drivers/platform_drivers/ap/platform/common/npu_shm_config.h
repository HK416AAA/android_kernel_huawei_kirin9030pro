#ifndef __NPU_SHM_CONFIG_H__
#define __NPU_SHM_CONFIG_H__ 
#include <npu_ddr_map.h>
#define NPU_LOAD_TSFW_CONFIG_SIZE 0x1000
#define NPU_AUTOBOOT_DATA_SIZE 0x2000
struct npu_error_info {
 unsigned int type;
 unsigned int value;
};
enum npu_error_info_type {
    NPU_NOSEC_ERROR = 1,
    NPU_SEC_ERROR,
    NPU_TINY_ERROR,
};
enum npu_error_info_value {
    BUS_ERROR = 1,
    POOL_CONFLICT,
    SQE_ERROR,
    TASK_ERROR,
    NPU_POWER_TIMEOUT_ERR,
    NPU_TASK_TIMEOUT_ERR,
    NPU_PDC_DISABLE,
 FFRT_ERROR,
 NPU_NO_POWERDOWN,
};
struct npu_chip_cfg {
 unsigned int valid_magic;
 unsigned int aicore_disable_bitmap;
 unsigned int platform_specification;
};
typedef union {
 struct {
  struct npu_chip_cfg chip_cfg;
 } cfg;
 unsigned char reserved[NPU_S_NPU_CONFIG_SIZE];
} npu_shm_cfg;
#pragma pack(push)
#pragma pack(4)
typedef union
{
 struct {
  unsigned char load_random;
  unsigned int canary;
  volatile unsigned int boot_status;
  volatile unsigned int ts_pd_stage;
 } cfg;
 unsigned char reserved[NPU_LOAD_TSFW_CONFIG_SIZE];
} npu_load_tsfw_cfg;
#pragma pack(pop)
#define NPU_AUTOBOOT_BASE_ADDR (RESERVED_NPU_AI_TS_FW_PHYMEM_BASE + RESERVED_NPU_AI_TS_FW_PHYMEM_SIZE -\
 NPU_LOAD_TSFW_CONFIG_SIZE - NPU_AUTOBOOT_DATA_SIZE)
#endif
