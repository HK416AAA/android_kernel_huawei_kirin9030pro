#ifndef _GUANGZHOU_XLOADER_PLAT_PARTITION_OHOS_H_
#define _GUANGZHOU_XLOADER_PLAT_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"


#define XLOADER3_VRL_INDEX_A    22
#define BL2_VRL_INDEX           34
#define FASTBOOT_VRL_INDEX_A    51
#define VECTOR_VRL_INDEX_A      52

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                0,                 4 * 1024,    UFS_PART_0},
    {PART_RESERVED1,              7 * 1024,              1024,    UFS_PART_2}, /* reserved1       1024K    p3 */
    {PART_VRL,                    512,                    512,    UFS_PART_3}, /* vrl              512K    p1 */
    {PART_VRL_BACKUP,             1024,                   512,    UFS_PART_3}, /* vrl backup       512K    p2 */
    {PART_NVME,                   10 * 1024,           4 * 1024,    UFS_PART_3}, /* nvme               4M    p4 */
    {PART_DDR_PARA,               227 * 1024,          1 * 1024,    UFS_PART_3}, /* ddr_para           1M    p14 */
    {PART_LOWPOWER_PARA,          228 * 1024,          1 * 1024,    UFS_PART_3}, /* lowpower_para      1M    p15 */
    {PART_DFX,                  435 * 1024,    16 * 1024, UFS_PART_3}, /* dfx                 16MB p22 */
    {PART_BL2,                  592 * 1024,     4 * 1024, UFS_PART_3}, /* bl2                  4MB p28 */
    {PART_FW_CPU_LPCTRL,       (596 * 1024 + 512),  256, UFS_PART_3}, /* fw_cpu_lpctrl      256K    p30 */
    {PART_FW_GPU_LPCTRL,       (596 * 1024 + 768),  128, UFS_PART_3}, /* fw_gpu_lpctrl      128K    p31 */
    {PART_FW_DDR_LPCTRL,       (596 * 1024 + 896),  320, UFS_PART_3}, /* fw_ddr_lpctrl      320K    p32 */
    {PART_DDR_XPU_BOOT0,       (597 * 1024 + 192),  320, UFS_PART_3}, /* ddr_xpu_boot0      320KB p33 */
    {PART_DDR_XPU_BOOT1,       (597 * 1024 + 512),  320, UFS_PART_3}, /* ddr_xpu_boot1      320KB  p34 */
    {PART_DDR_XPU_BOOT2,       (597 * 1024 + 832),  320, UFS_PART_3}, /* ddr_xpu_boot2      320KB  p35 */
    {PART_UCE,                 (598 * 1024 + 128),  160, UFS_PART_3}, /* uce                160KB  p36 */
    {PART_FW_MEDIA_LPCTRL,     (598 * 1024 + 288),  128, UFS_PART_3}, /* fw_media_lpctrl    128KB  p37 */
    {PART_DDR_FAC_INFO,        (598 * 1024 + 416),  1 * 1024, UFS_PART_3}, /* ddr_fac_info        1024KB p38 */
    {PART_DVFS,                (599 * 1024 + 416),  1 * 1024, UFS_PART_3}, /* dvfs   1024KB p39 */
    {PART_DACC,                 615 * 1024,          256, UFS_PART_3}, /* dacc               256KB p42 */
    {PART_DACC_AAE,            (615 * 1024 + 256),   256, UFS_PART_3}, /* dacc_aae           256KB p42 */
    {PART_HISEE_IMG,            616 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p44 */
    {PART_HISEE_FS,             624 * 1024,     8 * 1024, UFS_PART_3}, /* hisee_fs             8MB p46 */
    {PART_FASTBOOT,             632 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p47 */
    {PART_VECTOR,               644 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p48 */
#ifdef FACTORY_VERSION
    {PART_HIBENCH_IMG,        21648 * 1024,    12 * 1024, UFS_PART_3}, /* hibench_img         12MB p101 */
    {PART_HIBENCH_LOG,        21660 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p102 */
    {PART_HIBENCH_DATA,       21692 * 1024,  1024 * 1024, UFS_PART_3}, /* hibench_data      1024MB p103 */
    {PART_XLOADER_HITEST,     22716 * 1024,     2 * 1024, UFS_PART_3}, /* xloader_hitest       2MB p107 */
    {PART_FLASH_AGEING,       22718 * 1024,   512 * 1024, UFS_PART_3}, /* flash_ageing       512MB p108 */
#elif defined(CONFIG_PARTITION_ENG)
    {PART_FTTEST,             21648 * 1024,    12 * 1024, UFS_PART_3}, /* fttest              12MB p104 */
    {PART_XLOADER_HITEST,     21660 * 1024,     2 * 1024, UFS_PART_3}, /* xloader_hitest       2MB p105 */
#endif
    {"0", 0, 0, 0},
};
#endif
