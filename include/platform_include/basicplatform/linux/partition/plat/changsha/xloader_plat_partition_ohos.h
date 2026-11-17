#ifndef _CHANGSHA_XLOADER_PLAT_PARTITION_OHOS_H_
#define _CHANGSHA_XLOADER_PLAT_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"


#define XLOADER3_VRL_INDEX_A    22
#define BL2_VRL_INDEX           34
#define FASTBOOT_VRL_INDEX_A    51
#define VECTOR_VRL_INDEX_A      52
#define BL2_VRL_INDEX_B         35

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER_A,              0,                 4 * 1024,    UFS_PART_0},
    {PART_XLOADER_B,              0,                 4 * 1024,    UFS_PART_1},
    {PART_RESERVED1,              7 * 1024,              1024,    UFS_PART_2}, /* reserved1         1024KB p3 */
    {PART_VRL,                  512 + 1024,               512,    UFS_PART_5}, /* vrl                512KB p2 */
    {PART_VRL_BACKUP,             2 * 1024,               512,    UFS_PART_5}, /* vrl_backup         512KB p3 */
    {PART_BOOT_CTRL,              512,               1 * 1024,    UFS_PART_5}, /* boot_ctrl         1024KB p1 */
    {PART_NVME,                  11 * 1024,          4 * 1024,    UFS_PART_5}, /* nvme                 4MB p5 */
    {PART_DDR_PARA,             228 * 1024,          1 * 1024,    UFS_PART_5}, /* ddr_para          1024KB p15 */
    {PART_LOWPOWER_PARA_A,             512,          1 * 1024,    UFS_PART_3}, /* lowpower_para_a    1024KB p1 */
    {PART_LOWPOWER_PARA_B,             512,          1 * 1024,    UFS_PART_4}, /* lowpower_para_b    1024KB p1 */
    {PART_MISC,                 553 * 1024,          2 * 1024,    UFS_PART_5}, /* misc                 2MB p21 */
    {PART_DFX,                  555 * 1024,         16 * 1024,    UFS_PART_5}, /* dfx                 16MB p22 */
    {PART_BL2_A,                512 + 1024,          4 * 1024,    UFS_PART_3}, /* bl2_a                 4MB p2 */
    {PART_BL2_B,                512 + 1024,          4 * 1024,    UFS_PART_4}, /* bl2_b                 4MB p2 */
    {PART_FW_CPU_LPCTRL_A,       10 * 1024,               256,    UFS_PART_3}, /* fw_cpu_lpctrl_a      256K p5 */
    {PART_FW_CPU_LPCTRL_B,       10 * 1024,               256,    UFS_PART_4}, /* fw_cpu_lpctrl_b      256K  p5 */
    {PART_FW_GPU_LPCTRL_A,  (10 * 1024) + 256,            128,    UFS_PART_3}, /* fw_gpu_lpctrl_a     128K  p6 */
    {PART_FW_GPU_LPCTRL_B,  (10 * 1024) + 256,            128,    UFS_PART_4}, /* fw_gpu_lpctrl_b      128K  p6 */
    {PART_FW_DDR_LPCTRL_A,  (10 * 1024) + 384,            320,    UFS_PART_3}, /* fw_ddr_lpctrl_a     320K  p7 */
    {PART_FW_DDR_LPCTRL_B,  (10 * 1024) + 384,            320,    UFS_PART_4}, /* fw_ddr_lpctrl_b      320K  p7 */
    {PART_DDR_XPU_BOOT0_A,  (10 * 1024) + 704,            320,    UFS_PART_3}, /* ddr_xpu_boot0_a     320KB p8 */
    {PART_DDR_XPU_BOOT0_B,  (10 * 1024) + 704,            320,    UFS_PART_4}, /* ddr_xpu_boot0_b      320KB p8 */
    {PART_DDR_XPU_BOOT1_A,       11 * 1024,               320,    UFS_PART_3}, /* ddr_xpu_boot1_a     320KB p9 */
    {PART_DDR_XPU_BOOT1_B,       11 * 1024,               320,    UFS_PART_4}, /* ddr_xpu_boot1_b      320KB p9 */
    {PART_DDR_XPU_BOOT2_A,  (11 * 1024) + 320,            320,    UFS_PART_3}, /* ddr_xpu_boot2_a    320KB p10 */
    {PART_DDR_XPU_BOOT2_B,  (11 * 1024) + 320,            320,    UFS_PART_4}, /* ddr_xpu_boot2_b      320KB p10 */
    {PART_UCE_A,         (11 * 1024) + 640,               160,    UFS_PART_3}, /* uce_a              160KB p11 */
    {PART_UCE_B,         (11 * 1024) + 640,               160,    UFS_PART_4}, /* uce_b                160KB  p11 */
    {PART_FW_MEDIA_LPCTRL_A,  (11 * 1024) + 800,          128,    UFS_PART_3}, /* fw_media_lpctrl_a  128KB p12 */
    {PART_FW_MEDIA_LPCTRL_B,  (11 * 1024) + 800,          128,    UFS_PART_4}, /* fw_media_lpctrl_b    128KB  p12 */
    {PART_DDR_FAC_INFO,         708 * 1024,          1 * 1024,    UFS_PART_5}, /* ddr_fac_info     1024KB p27 */
    {PART_DVFS,                 709 * 1024,          1 * 1024,    UFS_PART_5}, /* dvfs             1024KB p28 */
    {PART_DACC_A,        (21 * 1024) + 928,               256,    UFS_PART_3}, /* dacc_a             256KB p15 */
    {PART_DACC_B,        (21 * 1024) + 928,               256,    UFS_PART_4}, /* dacc_b               256KB p15 */
    {PART_DACC_AAE_A,    (22 * 1024) + 160,               256,    UFS_PART_3}, /* dacc_aae_a         256KB p16 */
    {PART_DACC_AAE_B,    (22 * 1024) + 160,               256,    UFS_PART_4}, /* dacc_aae_b           256KB p16 */
    {PART_HISEE_IMG_A,   (22 * 1024) + 928,          4 * 1024,    UFS_PART_3}, /* hisee_img_a          4MB p18 */
    {PART_HISEE_IMG_B,   (22 * 1024) + 928,          4 * 1024,    UFS_PART_4}, /* hisee_img_b            4MB p18 */
    {PART_HISEE_FS,             710 * 1024,          8 * 1024,    UFS_PART_5}, /* hisee_fs             8MB p29 */
    {PART_FASTBOOT_A,    (30 * 1024) + 928,         12 * 1024,    UFS_PART_3}, /* fastboot_a          12MB p20 */
    {PART_FASTBOOT_B,    (30 * 1024) + 928,         12 * 1024,    UFS_PART_4}, /* fastboot_b           12MB  p20 */
    {PART_VECTOR_A,      (42 * 1024) + 928,          4 * 1024,    UFS_PART_3}, /* vector_a             4MB p21 */
    {PART_VECTOR_B,      (42 * 1024) + 928,          4 * 1024,    UFS_PART_4}, /* vector_b               4MB p21 */
#ifdef FACTORY_VERSION
    {PART_HIBENCH_IMG,          733 * 1024,    12 * 1024, UFS_PART_5}, /* hibench_img         12MB p32 */
    {PART_HIBENCH_LOG,          745 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p33 */
    {PART_HIBENCH_DATA,         777 * 1024,  2048 * 1024, UFS_PART_5}, /* hibench_data      2048MB p34 */
    {PART_XLOADER_HITEST,      3337 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p36 */
    {PART_FLASH_AGEING,        2825 * 1024,   512 * 1024, UFS_PART_5}, /* flash_ageing       512MB p35 */
#elif defined(CONFIG_PARTITION_ENG)
    {PART_FTTEST,             24559 * 1024,    12 * 1024, UFS_PART_5}, /* fttest              12MB p40 */
    {PART_DDRTEST,            24571 * 1024,    48 * 1024, UFS_PART_5}, /* ddrtest             48MB p41 */
    {PART_XLOADER_HITEST,     24619 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p42 */
#endif
    {"0", 0, 0, 0},
};
#endif