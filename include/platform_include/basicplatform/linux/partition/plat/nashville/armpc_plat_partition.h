#ifndef _PISCES_PLAT_PARTITION_H_
#define _PISCES_PLAT_PARTITION_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER_A,                               0,      4 * 1024, UFS_PART_0},
    {PART_XLOADER_B,                               0,      4 * 1024, UFS_PART_1},
    {PART_PTABLE,                                  0,           512, UFS_PART_2}, /* ptable 512KB             p0 */
    {PART_BOOT_CTRL,                             512,           512, UFS_PART_2}, /* boot_ctrl          512KB p1 */
    {PART_NVME,                                 1024,      4 * 1024, UFS_PART_2}, /* nvme                 4MB p2 */
    {PART_OEMINFO,                          5 * 1024,     96 * 1024, UFS_PART_2}, /* oeminfo             96MB p3 */
    {PART_DDR_PARA,                       101 * 1024,      1 * 1024, UFS_PART_2}, /* ddr_para          1024KB p4 */
    {PART_FW_VERSION,                     102 * 1024,      1 * 1024, UFS_PART_2}, /* fw_version        1024KB p5 */
    {PART_MCU,                            103 * 1024,      1 * 1024, UFS_PART_2}, /* mcu               1024KB p6 */
    {PART_MISC,                           104 * 1024,      2 * 1024, UFS_PART_2}, /* misc                 2MB p7 */
    {PART_DFX,                             106 * 1024,    16 * 1024, UFS_PART_2}, /* dfx                 16MB p8 */
    {PART_PTABLE_LU3,                               0,          512, UFS_PART_3}, /* ptable              512K p0 */
    {PART_VRL_A,                                  512,          512, UFS_PART_3}, /* vrl_a              512KB p1 */
    {PART_VRL_BACKUP_A,                          1024,          512, UFS_PART_3}, /* vrl_backup_a       512KB p2 */
    {PART_LOWPOWER_PARA_A,           (1 * 1024 + 512),     1 * 1024, UFS_PART_3}, /* lowpower_para_a   1024KB p3 */
    {PART_BL2_A,                     (2 * 1024 + 512),     4 * 1024, UFS_PART_3}, /* bl2_a                4MB p4 */
    {PART_FW_LPM3_A,                 (6 * 1024 + 512),          512, UFS_PART_3}, /* fw_lpm3_a          512KB p5 */
    {PART_FW_CPU_LPCTRL_A,                   7 * 1024,          256, UFS_PART_3}, /* fw_cpu_lpctrl_a    256KB p6 */
    {PART_FW_GPU_LPCTRL_A,           (7 * 1024 + 256),          128, UFS_PART_3}, /* fw_gpu_lpctrl_a    128KB p7 */
    {PART_FW_DDR_LPCTRL_A,           (7 * 1024 + 384),          256, UFS_PART_3}, /* fw_ddr_lpctrl_a    256KB p8 */
    {PART_DDR_XPU_BOOT0_A,           (7 * 1024 + 640),          256, UFS_PART_3}, /* ddr_xpu_boot0_a    256KB p9 */
    {PART_DDR_XPU_BOOT1_A,           (7 * 1024 + 896),          256, UFS_PART_3}, /* ddr_xpu_boot1_a    256KB p10 */
    {PART_DDR_XPU_BOOT2_A,           (8 * 1024 + 128),          256, UFS_PART_3}, /* ddr_xpu_boot2_a    256KB p11 */
    {PART_DACC_A,                    (8 * 1024 + 384),          512, UFS_PART_3}, /* dacc_a             512KB p12 */
    {PART_UCE_A,                     (8 * 1024 + 896),          160, UFS_PART_3}, /* uce_a              160KB p13 */
    {PART_VENC_A,                     (9 * 1024 + 32),          512, UFS_PART_3}, /* venc_a             512KB p14 */
    {PART_FASTBOOT_A,                (9 * 1024 + 544),    12 * 1024, UFS_PART_3}, /* fastboot_a          12MB p15 */
    {PART_VECTOR_A,                 (21 * 1024 + 544),     4 * 1024, UFS_PART_3}, /* vector_a             4MB p16 */
    {PART_TEEOS_A,                  (25 * 1024 + 544),    10 * 1024, UFS_PART_3}, /* teeos_a             10MB p17 */
    {PART_FW_DFA_A,                 (35 * 1024 + 544),     1 * 1024, UFS_PART_3}, /* fw_dfa_a          1024KB p18 */
    {PART_FW_DTB_A,                 (36 * 1024 + 544),    20 * 1024, UFS_PART_3}, /* fw_dtb_a            20MB p19 */
    {PART_DTBO_A,                   (56 * 1024 + 544),    20 * 1024, UFS_PART_3}, /* dtbo_a              20MB p20 */
    {PART_TRUSTFIRMWARE_A,          (76 * 1024 + 544),     2 * 1024, UFS_PART_3}, /* trustfirmware_a      2MB p21 */
    {PART_THEE_A,                   (78 * 1024 + 544),     4 * 1024, UFS_PART_3}, /* thee_a               4MB p22 */
    {PART_TZSP_A,                   (82 * 1024 + 544),    12 * 1024, UFS_PART_3}, /* tzsp_a              12MB p23 */
    {PART_UPDATER_BOOT_A,           (94 * 1024 + 544),    45 * 1024, UFS_PART_3}, /* updater_boot        45MB p24 */
    {PART_UPDATER_BOOT_BAK_A,      (139 * 1024 + 544),    45 * 1024, UFS_PART_3}, /* updater_boot_bak    45MB p25 */
    {PART_UPDATER_RAMDISK_A,       (184 * 1024 + 544),    32 * 1024, UFS_PART_3}, /* updater_ramdisk     32MB p26 */
    {PART_UPDATER_RAMDISK_BAK_A,   (216 * 1024 + 544),    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak 32MB p27 */
    {PART_UPDATER_VENDOR_A,        (248 * 1024 + 544),    24 * 1024, UFS_PART_3}, /* updater_vendor      24MB p28 */
    {PART_UPDATER_VENDOR_BAK_A,    (272 * 1024 + 544),    24 * 1024, UFS_PART_3}, /* updater_vendor_bak  24MB p29 */
    {PART_UPDATER_RVT_A,           (296 * 1024 + 544),     2 * 1024, UFS_PART_3}, /* updater_rvt          2MB p30 */
    {PART_UPDATER_BAK_RVT_A,       (298 * 1024 + 544),     2 * 1024, UFS_PART_3}, /* updater_bak_rvt      2MB p31 */
    {PART_PTABLE_LU4,                               0,          512, UFS_PART_4}, /* ptable              512K p0 */
    {PART_VRL_B,                                  512,          512, UFS_PART_4}, /* vrl_b              512KB p1 */
    {PART_VRL_BACKUP_B,                          1024,          512, UFS_PART_4}, /* vrl_backup_b       512KB p2 */
    {PART_LOWPOWER_PARA_B,           (1 * 1024 + 512),     1 * 1024, UFS_PART_4}, /* lowpower_para_b   1024KB p3 */
    {PART_BL2_B,                     (2 * 1024 + 512),     4 * 1024, UFS_PART_4}, /* bl2_b                4MB p4 */
    {PART_FW_LPM3_B,                 (6 * 1024 + 512),          512, UFS_PART_4}, /* fw_lpm3_b          512KB p5 */
    {PART_FW_CPU_LPCTRL_B,                   7 * 1024,          256, UFS_PART_4}, /* fw_cpu_lpctrl_b    256KB p6 */
    {PART_FW_GPU_LPCTRL_B,           (7 * 1024 + 256),          128, UFS_PART_4}, /* fw_gpu_lpctrl_b    128KB p7 */
    {PART_FW_DDR_LPCTRL_B,           (7 * 1024 + 384),          256, UFS_PART_4}, /* fw_ddr_lpctrl_b    256KB p8 */
    {PART_DDR_XPU_BOOT0_B,           (7 * 1024 + 640),          256, UFS_PART_4}, /* ddr_xpu_boot0_b    256KB p9 */
    {PART_DDR_XPU_BOOT1_B,           (7 * 1024 + 896),          256, UFS_PART_4}, /* ddr_xpu_boot1_b    256KB p10 */
    {PART_DDR_XPU_BOOT2_B,           (8 * 1024 + 128),          256, UFS_PART_4}, /* ddr_xpu_boot2_b    256KB p11 */
    {PART_DACC_B,                    (8 * 1024 + 384),          512, UFS_PART_4}, /* dacc_b             512KB p12 */
    {PART_UCE_B,                     (8 * 1024 + 896),          160, UFS_PART_4}, /* uce_b              160KB p13 */
    {PART_VENC_B,                     (9 * 1024 + 32),          512, UFS_PART_4}, /* venc_b             512KB p14 */
    {PART_FASTBOOT_B,                (9 * 1024 + 544),    12 * 1024, UFS_PART_4}, /* fastboot_b          12MB p15 */
    {PART_VECTOR_B,                 (21 * 1024 + 544),     4 * 1024, UFS_PART_4}, /* vector_b             4MB p16 */
    {PART_TEEOS_B,                  (25 * 1024 + 544),    10 * 1024, UFS_PART_4}, /* teeos_b             10MB p17 */
    {PART_FW_DFA_B,                 (35 * 1024 + 544),     1 * 1024, UFS_PART_4}, /* fw_dfa_b          1024KB p18 */
    {PART_FW_DTB_B,                 (36 * 1024 + 544),    20 * 1024, UFS_PART_4}, /* fw_dtb_b            20MB p19 */
    {PART_DTBO_B,                   (56 * 1024 + 544),    20 * 1024, UFS_PART_4}, /* dtbo_b              20MB p20 */
    {PART_TRUSTFIRMWARE_B,          (76 * 1024 + 544),     2 * 1024, UFS_PART_4}, /* trustfirmware_b      2MB p21 */
    {PART_THEE_B,                   (78 * 1024 + 544),     4 * 1024, UFS_PART_4}, /* thee_b               4MB p22 */
    {PART_TZSP_B,                   (82 * 1024 + 544),    12 * 1024, UFS_PART_4}, /* tzsp_b              12MB p23 */
    {PART_UPDATER_BOOT_B,           (94 * 1024 + 544),    45 * 1024, UFS_PART_4}, /* updater_boot        45MB p24 */
    {PART_UPDATER_BOOT_BAK_B,      (139 * 1024 + 544),    45 * 1024, UFS_PART_4}, /* updater_boot_bak    45MB p25 */
    {PART_UPDATER_RAMDISK_B,       (184 * 1024 + 544),    32 * 1024, UFS_PART_4}, /* updater_ramdisk     32MB p26 */
    {PART_UPDATER_RAMDISK_BAK_B,   (216 * 1024 + 544),    32 * 1024, UFS_PART_4}, /* updater_ramdisk_bak 32MB p27 */
    {PART_UPDATER_VENDOR_B,        (248 * 1024 + 544),    24 * 1024, UFS_PART_4}, /* updater_vendor      24MB p28 */
    {PART_UPDATER_VENDOR_BAK_B,    (272 * 1024 + 544),    24 * 1024, UFS_PART_4}, /* updater_vendor_bak  24MB p29 */
    {PART_UPDATER_RVT_B,           (296 * 1024 + 544),     2 * 1024, UFS_PART_4}, /* updater_rvt          2MB p30 */
    {PART_UPDATER_BAK_RVT_B,       (298 * 1024 + 544),     2 * 1024, UFS_PART_4}, /* updater_bak_rvt      2MB p31 */
    {PART_PTABLE_LU5,                               0,          512, UFS_PART_5}, /* ptable_lu3          512K p0 */
    {PART_RESERVED2,                              512,      3 * 512, UFS_PART_5}, /* reserved2         1536KB p1 */
    {PART_ROOT,                     2 * 1024, (120UL) * 1024 * 1024, UFS_PART_5}, /* root            122880MB p2 */
    {PART_EFI,                   122882 * 1024, (1UL) * 1024 * 1024, UFS_PART_5}, /* efi        1024 * 1024KB p3 */
#ifdef CONFIG_FACTORY_MODE
    {PART_HIBENCH_IMG,       123906 * 1024,   128 * 1024, UFS_PART_5}, /* hibench_img        128MB p4 */
    {PART_HIBENCH_DATA,      124034 * 1024,   512 * 1024, UFS_PART_5}, /* hibench_data       512MB p5 */
    {PART_FLASH_AGEING,      124546 * 1024,   512 * 1024, UFS_PART_5}, /* flash_ageing       512MB p6 */
    {PART_HIBENCH_LOG,       125058 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p7 */
    {PART_HIBENCH_LPM3,      125090 * 1024,     2 * 1024, UFS_PART_5}, /* hibench_lpm3         2MB p8 */
    {PART_XLOADER_HITEST,    125092 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p124 */
    {PART_KERNEL,            125094 * 1024,(8UL) * 1024 * 1024, UFS_PART_5}, /* kernel            8192MB p9 */
    {PART_HISEE_IMG,         133286 * 1024,       4 * 1024, UFS_PART_5}, /* hisee_img          4M    p10 */
    {PART_HISEE_FS,          133290 * 1024,       8 * 1024, UFS_PART_5}, /* hisee_fs           8M    p11 */
    {PART_HOME,              133298 * 1024,(64UL) * 1024 * 1024, UFS_PART_5}, /* home              65536MB p12 */
#else
#ifdef CONFIG_PRODUCT_ARMPC_USER
    {PART_HOME,                 123906 * 1024, (64UL) * 1024 * 1024, UFS_PART_5}, /* home             65536MB p4 */
#else
    {PART_KERNEL,                123906 * 1024, (8UL) * 1024 * 1024, UFS_PART_5}, /* kernel            8192MB p4 */
    {PART_HOME,                 132098 * 1024, (64UL) * 1024 * 1024, UFS_PART_5}, /* home             65536MB p5 */
#endif
#endif
    {"0", 0, 0, 0},
};

#endif
