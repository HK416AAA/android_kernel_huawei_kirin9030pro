#ifndef __DDR_SEC_DATA_STRUCT_H__
#define __DDR_SEC_DATA_STRUCT_H__ 
#include <ddr_define.h>
#include <stdint.h>
struct qice_ib_info {
 uint32_t rgn_num_reserved;
 uint32_t rgn_num_total;
 uint32_t ib_idx;
};
struct qice_ib_info_with_lock {
 uint32_t rgn_num_reserved;
 uint32_t rgn_num_total;
 uint32_t ib_idx;
 uint32_t lock_rgn_num_reserved;
};
struct qice_reserved_rgn {
 uint32_t rgn_num_kernel_protect;
 uint32_t rgn_num_hifi_reboot;
 uint32_t rgn_num_asp_dsp_play;
 uint32_t rgn_num_kernel_prmem;
};
struct sec_rgn_cfg {
 uint32_t rgn_en;
 uint32_t attri;
 uint32_t mid_wr;
 uint32_t mid_rd;
 uint64_t start_addr;
 uint64_t end_addr;
};
enum sec_ib_idx {
 SEC_SC_IDX = 0x3,
 SEC_PUB_IDX = 0x8,
 SEC_QIC_COMMON_MISC_M1_IDX = 0x14,
 SEC_QIC_COMMON_MISC_M2_IDX,
 SEC_QIC_COMMON_MISC_NPU_IDX,
 IBQE_GPU_P0_KPU = 0xb8,
 IBQE_GPU_P1_KPU,
 IBQE_H0_FFTS_KPU,
 IBQE_MDM_DDR_KPU,
 IBQE_MDM_PDEA_KPU,
 IBQE_MEDIA1_P0_KPU,
 IBQE_MEDIA1_P1_KPU,
 IBQE_MEDIA2_P0_KPU,
 IBQE_MEDIA2_P1_KPU,
 IBQE_QDBEM_WRAP_P0_KPU,
 IBQE_QDBEM_WRAP_P1_KPU,
 IBQE_SYS_SDCU_KPU,
 SEC_RGN_MEDIA1_P0_KPU,
 SEC_RGN_MEDIA1_P1_KPU,
 SEC_RGN_MEDIA2_P0_KPU,
 SEC_RGN_MEDIA2_P1_KPU,
 SEC_RGN_NPU_P0_KPU,
 SEC_RGN_NPU_P1_KPU,
 IBQE_GPU_P0_SEC = 0xd0,
 IBQE_GPU_P1_SEC,
 IBQE_H0_FFTS_SEC,
 IBQE_MDM_DDR_SEC,
 IBQE_MDM_PDEA_SEC,
 IBQE_SYS_SDCU_SEC = 0xdb,
 SEC_RGN_MEDIA1_P0_SEC,
 SEC_RGN_MEDIA1_P1_SEC,
 SEC_RGN_MEDIA2_P0_SEC,
 SEC_RGN_MEDIA2_P1_SEC,
 SEC_RGN_NPU_P0_SEC,
 SEC_RGN_NPU_P1_SEC,
 MPUCFG,
 SEC_QICE_IB_IDX_MAX,
};
enum sec_ib_type {
 SEC_SC = 0,
 SEC_IBQE_GPU_P0,
 SEC_IBQE_GPU_P1,
 SEC_IBQE_H0_FFTS,
 SEC_IBQE_MDM,
 SEC_IBQE_MDM_PDEA,
 SEC_IBQE_MEDIA1_P0,
 SEC_IBQE_MEDIA1_P1,
 SEC_IBQE_MEDIA2_P0,
 SEC_IBQE_MEDIA2_P1,
 SEC_IBQE_NPU_P0,
 SEC_IBQE_NPU_P1,
 SEC_IBQE_SYS_SDCU,
 SEC_IB_TYPE_MAX,
};
enum sub_rgn_zone {
 SUB_RGN_1MB_ZONE = 0,
 SUB_RGN_2MB_ZONE,
 SUB_RGN_ZONE_MAX
};
enum {
 RW_FORBID = 0,
 UNSEC_WR = 0x1,
 UNSEC_RD = 0x2,
 SEC_WR = 0x4,
 SEC_RD = 0x8,
};
enum property_status {
 STATUS_DISABLE = 0,
 STATUS_OK
};
enum kpu_ib_type {
    KPU_IBQE_GPU_P0 = 0,
    KPU_IBQE_GPU_P1,
    KPU_IBQE_MDM_DDR,
    KPU_IBQE_MDM_PDEA,
    KPU_IBQE_QDBEM_WRAP_P0,
    KPU_IBQE_QDBEM_WRAP_P1,
    KPU_IBQE_SYS_SDCU,
    KPU_IB_TYPE_MAX,
};
#endif
