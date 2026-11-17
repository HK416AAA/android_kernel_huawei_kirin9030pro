/*
 *  Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 *  Description: the partition table.
 */

#ifndef _ANTLIA_CDC_PLAT_PARTITION_H_
#define _ANTLIA_CDC_PLAT_PARTITION_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static struct partition partition_table_ufs[] = {
    {PART_XLOADER_A,                        0,      2 * 1024,      UFS_PART_0},
    {PART_XLOADER_B,                        0,      2 * 1024,      UFS_PART_1},
    {PART_PTABLE,                           0,           512,      UFS_PART_2}, /* ptable             512K    p0 */
    {PART_VRL_A,                      512,          512, UFS_PART_2}, /* vrl_a              512KB p1 */
    {PART_VRL_BACKUP_A,              1024,          512, UFS_PART_2}, /* vrl_backup_a       512KB p2 */
    {PART_RESERVED1_lu2,             1536,          512, UFS_PART_2}, /* reserved1_lu2      512KB p3 */
    {PART_NPU_A,                 2 * 1024,     8 * 1024, UFS_PART_2}, /* npu_a                8MB p4 */
    {PART_HIEPS_A,              10 * 1024,     2 * 1024, UFS_PART_2}, /* hieps_a              2MB p5 */
    {PART_IVP_A,                12 * 1024,     2 * 1024, UFS_PART_2}, /* ivp_a                2MB p6 */
    {PART_HISEE_IMG_A,          14 * 1024,     4 * 1024, UFS_PART_2}, /* hisee_img_a          4MB p7 */
    {PART_HHEE_A,               18 * 1024,     4 * 1024, UFS_PART_2}, /* hhee_a               4MB p8 */
    {PART_FASTBOOT_A,           22 * 1024,    12 * 1024, UFS_PART_2}, /* fastboot_a          12MB p9 */
    {PART_LOWPOWER_PARA_A,      34 * 1024,     1 * 1024, UFS_PART_2}, /* lowpower_para_a   1024KB p10 */
    {PART_BL2_A,                35 * 1024,     4 * 1024, UFS_PART_2}, /* bl2_a                4MB p11 */
    {PART_TEEOS_A,              39 * 1024,     8 * 1024, UFS_PART_2}, /* teeos_a              8MB p12 */
    {PART_FW_LPM3_A,            47 * 1024,          512, UFS_PART_2}, /* fw_lpm3_a          512KB p13 */
    {PART_FW_CPU_LPCTRL_A,  (47 * 1024 + 512),      256, UFS_PART_2}, /* fw_cpu_lpctrl_a     256K p14 */
    {PART_FW_GPU_LPCTRL_A,  (47 * 1024 + 768),      128, UFS_PART_2}, /* fw_gpu_lpctrl_a     128K p15 */
    {PART_FW_DDR_LPCTRL_A,  (47 * 1024 + 896),      128, UFS_PART_2}, /* fw_ddr_lpctrl_a     128K p16 */
    {PART_FW_UFSDEV_A,          48 * 1024,     4 * 1024, UFS_PART_2}, /* fw_ufsdev_a          4MB p17 */
    {PART_RESERVED2_lu2,        52 * 1024,     4 * 1024, UFS_PART_2}, /* reserved2_lu2        4MB p18 */
    {PART_VECTOR_A,             56 * 1024,     4 * 1024, UFS_PART_2}, /* vector_a             4MB p19 */
    {PART_ISP_BOOT_A,           60 * 1024,     2 * 1024, UFS_PART_2}, /* isp_boot_a           2MB p20 */
    {PART_ISP_FIRMWARE_A,       62 * 1024,    14 * 1024, UFS_PART_2}, /* isp_firmware_a      14MB p21 */
    {PART_FW_HIFI_A,            76 * 1024,    12 * 1024, UFS_PART_2}, /* fw_hifi_a           12MB p22 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_BOOT_A,               88 * 1024,   100 * 1024, UFS_PART_2}, /* boot_a             100MB p23 */
    {PART_UPDATER_BOOT_A,          188 * 1024,    85 * 1024, UFS_PART_2}, /* updater_boot_a          85MB p24 */
    {PART_UPDATER_RAMDISK_A,   273 * 1024,    32 * 1024, UFS_PART_2}, /* updater_ramdisk_a  32MB p25 */
    {PART_UPDATER_VENDOR_A,   305 * 1024,    34 * 1024, UFS_PART_2}, /* updater_vendor_a   34MB p26 */
    {PART_UPDATER_BOOT_BAK_A,         339 * 1024,    12 * 1024, UFS_PART_2}, /* updater_boot_bak_a         12MB p27 */
    {PART_UPDATER_RAMDISK_BAK_A,   351 * 1024,    12 * 1024, UFS_PART_2}, /* updater_ramdisk_bak_a  12MB p28 */
    {PART_UPDATER_VENDOR_BAK_A,   363 * 1024,     8 * 1024, UFS_PART_2}, /* updater_vendor_bak_a   8MB p29 */
    {PART_RESERVED3_lu2,       371 * 1024,    38 * 1024, UFS_PART_2}, /* reserved3_lu2       38MB p30 */
#elif defined CONFIG_HWSANITIZER_ENABLE
    {PART_BOOT_A,               88 * 1024,    46 * 1024, UFS_PART_2}, /* boot_a              46MB p23 */
    {PART_UPDATER_BOOT_A,          134 * 1024,    45 * 1024, UFS_PART_2}, /* updater_boot_a          45MB p24 */
    {PART_UPDATER_RAMDISK_A,   179 * 1024,    40 * 1024, UFS_PART_2}, /* updater_ramdisk_a  40MB p25 */
    {PART_UPDATER_VENDOR_A,   219 * 1024,    24 * 1024, UFS_PART_2}, /* updater_vendor_a   24MB p26 */
    {PART_UPDATER_BOOT_BAK_A,         243 * 1024,    45 * 1024, UFS_PART_2}, /* updater_boot_bak_a         45MB p27 */
    {PART_UPDATER_RAMDISK_BAK_A,   288 * 1024,    40 * 1024, UFS_PART_2}, /* updater_ramdisk_bak_a  40MB p28 */
    {PART_UPDATER_VENDOR_BAK_A,   328 * 1024,    24 * 1024, UFS_PART_2}, /* updater_vendor_bak_a  24MB p29 */
    {PART_RESERVED3_lu2,       352 * 1024,    57 * 1024, UFS_PART_2}, /* reserved3_lu2       57MB p30 */
#else
    {PART_BOOT_A,               88 * 1024,    46 * 1024, UFS_PART_2}, /* boot_a              46MB p23 */
    {PART_UPDATER_BOOT_A,          134 * 1024,    45 * 1024, UFS_PART_2}, /* updater_boot_a          45MB p24 */
    {PART_UPDATER_RAMDISK_A,   179 * 1024,    32 * 1024, UFS_PART_2}, /* updater_ramdisk_a  32MB p25 */
    {PART_UPDATER_VENDOR_A,   211 * 1024,    24 * 1024, UFS_PART_2}, /* updater_vendor_a   24MB p26 */
    {PART_UPDATER_BOOT_BAK_A,         235 * 1024,    45 * 1024, UFS_PART_2}, /* updater_boot_bak_a         45MB p27 */
    {PART_UPDATER_RAMDISK_BAK_A,   280 * 1024,    32 * 1024, UFS_PART_2}, /* updater_ramdisk_bak_a  32MB p28 */
    {PART_UPDATER_VENDOR_BAK_A,   312 * 1024,    24 * 1024, UFS_PART_2}, /* updater_vendor_bak_a  24MB p29 */
    {PART_RESERVED3_lu2,       336 * 1024,    73 * 1024, UFS_PART_2}, /* reserved3_lu2       73MB p30 */
#endif
    {PART_KPATCH_A,            409 * 1024,     4 * 1024, UFS_PART_2}, /* kpatch_a             4MB p31 */
    {PART_ENG_SYSTEM_A,        413 * 1024,    12 * 1024, UFS_PART_2}, /* eng_system_a        12MB p32 */
    {PART_RAMDISK_A,           425 * 1024,     4 * 1024, UFS_PART_2}, /* ramdisk_a            4MB p33 */
    {PART_RVT_SYSTEM_A,     429 * 1024,     1 * 1024, UFS_PART_2}, /* rvt_system_a   1024KB p34 */
    {PART_RVT_VENDOR_A,     430 * 1024,     1 * 1024, UFS_PART_2}, /* rvt_vendor_a   1024KB p35 */
    {PART_RVT_CHIP_PROD_A,        431 * 1024,     1 * 1024, UFS_PART_2}, /* rvt_chip_prod_a      1024KB p36 */
    {PART_RVT_CUST_A,       432 * 1024,     1 * 1024, UFS_PART_2}, /* rvt_cust_a     1024KB p37 */
    {PART_RVT_SYS_PROD_A,   433 * 1024,     1 * 1024, UFS_PART_2}, /* rvt_sys_prod_a 1024KB p38 */
    {PART_DTBO_A,              434 * 1024,    20 * 1024, UFS_PART_2}, /* dtbo_a              20MB p39 */
    {PART_ENG_CHIPSET_A,        454 * 1024,    20 * 1024, UFS_PART_2}, /* eng_chipset_a        20MB p40 */
    {PART_FW_DTB_A,            474 * 1024,     8 * 1024, UFS_PART_2}, /* fw_dtb_a             8MB p41 */
    {PART_TRUSTFIRMWARE_A,     482 * 1024,     2 * 1024, UFS_PART_2}, /* trustfirmware_a      2MB p42 */
    {PART_UPDATER_RVT_A,   484 * 1024,     2 * 1024, UFS_PART_2}, /* update_rvt_a    2MB p43 */
    {PART_UPDATER_BAK_RVT_A,   486 * 1024,     2 * 1024, UFS_PART_2}, /* update_bak_rvt_a   2MB p44 */
    {PART_RVT_A,            488 * 1024,     4 * 1024, UFS_PART_2}, /* rvt_a             4MB p45 */
    {PART_PATCH_A,             492 * 1024,    32 * 1024, UFS_PART_2}, /* patch_a             32MB p46 */
    {PART_PREAS_A,             524 * 1024,    12 * 1024, UFS_PART_2}, /* preas_a             12MB p47 */
    {PART_PREAVS_A,            536 * 1024,    12 * 1024, UFS_PART_2}, /* preavs_a            12MB p48 */
    {PART_SAFETY_ISLAND_A,     548 * 1024,     4 * 1024, UFS_PART_2}, /* safety_island_a      4MB p49 */
    {PART_THEE_A,              552 * 1024,     4 * 1024, UFS_PART_2}, /* thee_a               4MB p50 */
    {PART_TZSP_A,              556 * 1024,    12 * 1024, UFS_PART_2}, /* tzsp_a              12MB p51 */
    {PART_DICE_A,              568 * 1024,     1 * 1024, UFS_PART_2}, /* dice_a            1024KB p52 */
    {PART_DACC_A,              569 * 1024,          256, UFS_PART_2}, /* dacc_a             256KB p53 */
    {PART_DACC_LITE_A, (569 * 1024 + 256),          256, UFS_PART_2}, /* dacc_lite_a           256K  p52 */
    {PART_VENC_A,      (569 * 1024 + 512),          512, UFS_PART_2}, /* venc_a                512K  p53 */
    {PART_DDR_XPU_BOOT0_A,     570 * 1024,          136, UFS_PART_2}, /* ddr_xpu_boot0_a    136KB p56 */
    {PART_DDR_XPU_BOOT1_A, (570 * 1024 + 136),          136, UFS_PART_2}, /* ddr_xpu_boot1_a    136KB p57 */
    {PART_PTABLE_LU3,                       0,           512,      UFS_PART_3}, /* ptable             512K    p0 */
    {PART_VRL_B,                      512,          512, UFS_PART_3}, /* vrl_b              512KB p1 */
    {PART_VRL_BACKUP_B,              1024,          512, UFS_PART_3}, /* vrl_backup_b       512KB p2 */
    {PART_RESERVED1_lu3,             1536,          512, UFS_PART_3}, /* reserved1_lu3      512KB p3 */
    {PART_NPU_B,                 2 * 1024,     8 * 1024, UFS_PART_3}, /* npu_b                8MB p4 */
    {PART_HIEPS_B,              10 * 1024,     2 * 1024, UFS_PART_3}, /* hieps_b              2MB p5 */
    {PART_IVP_B,                12 * 1024,     2 * 1024, UFS_PART_3}, /* ivp_b                2MB p6 */
    {PART_HISEE_IMG_B,          14 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img_b          4MB p7 */
    {PART_HHEE_B,               18 * 1024,     4 * 1024, UFS_PART_3}, /* hhee_b               4MB p8 */
    {PART_FASTBOOT_B,           22 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot_b          12MB p9 */
    {PART_LOWPOWER_PARA_B,      34 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para_b   1024KB p10 */
    {PART_BL2_B,                35 * 1024,     4 * 1024, UFS_PART_3}, /* bl2_b                4MB p11 */
    {PART_TEEOS_B,              39 * 1024,     8 * 1024, UFS_PART_3}, /* teeos_b              8MB p12 */
    {PART_FW_LPM3_B,            47 * 1024,          512, UFS_PART_3}, /* fw_lpm3_b          512KB p13 */
    {PART_FW_CPU_LPCTRL_B,  (47 * 1024 + 512),      256, UFS_PART_3}, /* fw_cpu_lpctrl      256K  p14 */
    {PART_FW_GPU_LPCTRL_B,  (47 * 1024 + 768),      128, UFS_PART_3}, /* fw_gpu_lpctrl      128K  p15 */
    {PART_FW_DDR_LPCTRL_B,  (47 * 1024 + 896),      128, UFS_PART_3}, /* fw_ddr_lpctrl      128K  p16 */
    {PART_FW_UFSDEV_B,          48 * 1024,     4 * 1024, UFS_PART_3}, /* fw_ufsdev_b          4MB p17 */
    {PART_RESERVED2_lu3,        52 * 1024,     4 * 1024, UFS_PART_3}, /* reserved2_lu3        4MB p18 */
    {PART_VECTOR_B,             56 * 1024,     4 * 1024, UFS_PART_3}, /* vector_b             4MB p19 */
    {PART_ISP_BOOT_B,           60 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot_b           2MB p20 */
    {PART_ISP_FIRMWARE_B,       62 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware_b      14MB p21 */
    {PART_FW_HIFI_B,            76 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi_b           12MB p22 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_BOOT_B,               88 * 1024,   100 * 1024, UFS_PART_3}, /* boot_b             100MB p23 */
    {PART_UPDATER_BOOT_B,          188 * 1024,    85 * 1024, UFS_PART_3}, /* updater_boot_b          85MB p24 */
    {PART_UPDATER_RAMDISK_B,   273 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_b  32MB p25 */
    {PART_UPDATER_VENDOR_B,   305 * 1024,    34 * 1024, UFS_PART_3}, /* updater_vendor_b   34MB p26 */
    {PART_UPDATER_BOOT_BAK_B,         339 * 1024,    12 * 1024, UFS_PART_3}, /* updater_boot_bak_b         12MB p27 */
    {PART_UPDATER_RAMDISK_BAK_B,   351 * 1024,    12 * 1024, UFS_PART_3}, /* updater_ramdisk_bak_b  12MB p28 */
    {PART_UPDATER_VENDOR_BAK_B,   363 * 1024,     8 * 1024, UFS_PART_3}, /* updater_vendor_bak_b   8MB p29 */
    {PART_RESERVED3_lu3,       371 * 1024,    38 * 1024, UFS_PART_3}, /* reserved3_lu3       38MB p30 */
#elif defined CONFIG_HWSANITIZER_ENABLE
    {PART_BOOT_B,               88 * 1024,    46 * 1024, UFS_PART_3}, /* boot_b              46MB p23 */
    {PART_UPDATER_BOOT_B,          134 * 1024,    45 * 1024, UFS_PART_3}, /* updater_boot_b          45MB p24 */
    {PART_UPDATER_RAMDISK_B,   179 * 1024,    40 * 1024, UFS_PART_3}, /* updater_ramdisk_b  40MB p25 */
    {PART_UPDATER_VENDOR_B,   219 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_b   24MB p26 */
    {PART_UPDATER_BOOT_BAK_B,         243 * 1024,    45 * 1024, UFS_PART_3}, /* updater_boot_bak_b         45MB p27 */
    {PART_UPDATER_RAMDISK_BAK_B,   288 * 1024,    40 * 1024, UFS_PART_3}, /* updater_ramdisk_bak_b  40MB p28 */
    {PART_UPDATER_VENDOR_BAK_B,   328 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_bak_b  24MB p29 */
    {PART_RESERVED3_lu3,       352 * 1024,    57 * 1024, UFS_PART_3}, /* reserved3_lu3       57MB p30 */
#else
    {PART_BOOT_B,               88 * 1024,    46 * 1024, UFS_PART_3}, /* boot_b              46MB p23 */
    {PART_UPDATER_BOOT_B,          134 * 1024,    45 * 1024, UFS_PART_3}, /* updater_boot_b          45MB p24 */
    {PART_UPDATER_RAMDISK_B,   179 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_b  32MB p25 */
    {PART_UPDATER_VENDOR_B,   211 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_b   24MB p26 */
    {PART_UPDATER_BOOT_BAK_B,         235 * 1024,    45 * 1024, UFS_PART_3}, /* updater_boot_bak_b         45MB p27 */
    {PART_UPDATER_RAMDISK_BAK_B,   280 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak_b  32MB p28 */
    {PART_UPDATER_VENDOR_BAK_B,   312 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_bak_b  24MB p29 */
    {PART_RESERVED3_lu3,       336 * 1024,    73 * 1024, UFS_PART_3}, /* reserved3_lu3       73MB p30 */
#endif
    {PART_KPATCH_B,            409 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch_b             4MB p31 */
    {PART_ENG_SYSTEM_B,        413 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system_b        12MB p32 */
    {PART_RAMDISK_B,           425 * 1024,     4 * 1024, UFS_PART_3}, /* ramdisk_b            4MB p33 */
    {PART_RVT_SYSTEM_B,     429 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system_b   1024KB p34 */
    {PART_RVT_VENDOR_B,     430 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor_b   1024KB p35 */
    {PART_RVT_CHIP_PROD_B,        431 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod_b      1024KB p36 */
    {PART_RVT_CUST_B,       432 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust_b     1024KB p37 */
    {PART_RVT_SYS_PROD_B,   433 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod_b 1024KB p38 */
    {PART_DTBO_B,              434 * 1024,    20 * 1024, UFS_PART_3}, /* dtbo_b              20MB p39 */
    {PART_ENG_CHIPSET_B,        454 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset_b        20MB p40 */
    {PART_FW_DTB_B,            474 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb_b             8MB p41 */
    {PART_TRUSTFIRMWARE_B,     482 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware_b      2MB p42 */
    {PART_UPDATER_RVT_B,   484 * 1024,     2 * 1024, UFS_PART_3}, /* update_rvt_b    2MB p43 */
    {PART_UPDATER_BAK_RVT_B,   486 * 1024,     2 * 1024, UFS_PART_3}, /* update_bak_rvt_b   2MB p44 */
    {PART_RVT_B,            488 * 1024,     4 * 1024, UFS_PART_3}, /* rvt_b             4MB p45 */
    {PART_PATCH_B,             492 * 1024,    32 * 1024, UFS_PART_3}, /* patch_b             32MB p46 */
    {PART_PREAS_B,             524 * 1024,    12 * 1024, UFS_PART_3}, /* preas_b             12MB p47 */
    {PART_PREAVS_B,            536 * 1024,    12 * 1024, UFS_PART_3}, /* preavs_b            12MB p48 */
    {PART_SAFETY_ISLAND_B,     548 * 1024,     4 * 1024, UFS_PART_3}, /* safety_island_b      4MB p49 */
    {PART_THEE_B,              552 * 1024,     4 * 1024, UFS_PART_3}, /* thee_b               4MB p50 */
    {PART_TZSP_B,              556 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp_b              12MB p51 */
    {PART_DICE_B,              568 * 1024,     1 * 1024, UFS_PART_3}, /* dice_b            1024KB p52 */
    {PART_DACC_B,              569 * 1024,          256, UFS_PART_3}, /* dacc_b             256KB p53 */
    {PART_DACC_LITE_B,    (569 * 1024 + 256),       256, UFS_PART_3}, /* dacc_lite_b        256K  p54 */
    {PART_VENC_B,         (569 * 1024 + 512),       512, UFS_PART_3}, /* venc_b             512K  p55 */
    {PART_DDR_XPU_BOOT0_B,     570 * 1024,          136, UFS_PART_3}, /* ddr_xpu_boot0_b    136KB p56 */
    {PART_DDR_XPU_BOOT1_B, (570 * 1024 + 136),      136, UFS_PART_3}, /* ddr_xpu_boot1_b    136K  p57 */
    {PART_PTABLE_LU4,                       0,           512,      UFS_PART_4}, /* ptable_lu4         512K    p0 */
    {PART_FRP,                        512,          512, UFS_PART_4}, /* frp                512KB p1 */
    {PART_PERSIST,                   1024,     6 * 1024, UFS_PART_4}, /* persist              6MB p2 */
    {PART_BOOT_CTRL,             7 * 1024,     1 * 1024, UFS_PART_4}, /* boot_ctrl         1024KB p3 */
    {PART_NVME,                  8 * 1024,     5 * 1024, UFS_PART_4}, /* nvme                 5MB p4 */
    {PART_CTF,                  13 * 1024,     1 * 1024, UFS_PART_4}, /* ctf               1024KB p5 */
    {PART_OEMINFO,              14 * 1024,    96 * 1024, UFS_PART_4}, /* oeminfo             96MB p6 */
    {PART_BOARD_ID,            110 * 1024,           64, UFS_PART_4}, /* board_id            64KB p7 */
    {PART_RESERVED1_lu4,    (110 * 1024 + 64),   (960 + 1024), UFS_PART_4}, /* reserved1_lu4       1984KB   p8 */
    {PART_SECURE_STORAGE,      112 * 1024,    32 * 1024, UFS_PART_4}, /* secure_storage      32MB p9 */
    {PART_HISEE_ENCOS,         144 * 1024,     4 * 1024, UFS_PART_4}, /* hisee_encos          4MB p10 */
    {PART_VERITYKEY,           148 * 1024,     1 * 1024, UFS_PART_4}, /* veritykey         1024KB p11 */
    {PART_DDR_PARA,            149 * 1024,     1 * 1024, UFS_PART_4}, /* ddr_para          1024KB p12 */
    {PART_BATT_TP_PARA,        150 * 1024,     1 * 1024, UFS_PART_4}, /* batt_tp_para      1024KB p13 */
    {PART_TOC,                 151 * 1024,     1 * 1024, UFS_PART_4}, /* toc               1024KB p14 */
    {PART_LOG,                 152 * 1024,    80 * 1024, UFS_PART_4}, /* log                 80MB p15 */
    {PART_BOOTFAIL_INFO,       232 * 1024,     2 * 1024, UFS_PART_4}, /* bootfail_info        2MB p16 */
    {PART_MISC,                234 * 1024,     2 * 1024, UFS_PART_4}, /* misc                 2MB p17 */
    {PART_DFX,                 236 * 1024,    16 * 1024, UFS_PART_4}, /* dfx                 16MB p18 */
    {PART_RRECORD,             252 * 1024,    16 * 1024, UFS_PART_4}, /* rrecord             16MB p19 */
    {PART_CACHE,               268 * 1024,   104 * 1024, UFS_PART_4}, /* cache              104MB p20 */
    {PART_METADATA,            372 * 1024,    16 * 1024, UFS_PART_4}, /* metadata            16MB p21 */
    {PART_HISEE_FS,            388 * 1024,     8 * 1024, UFS_PART_4}, /* hisee_fs             8MB p22 */
    {PART_CDC_DATA,            396 * 1024,     8 * 1024, UFS_PART_4}, /* cdc_data             8MB p23 */
    {PART_RESERVED2_lu4,       404 * 1024,    80 * 1024, UFS_PART_4}, /* reserved2_lu4       80MB p24 */
    {PART_HYPERHOLD,           484 * 1024,     4 * 1024, UFS_PART_4}, /* hyperhold            4MB p24 */
    /* {PART_SUPER,               488 * 1024, 23318 * 1024, UFS_PART_4}, *//* super             23318MB p25 */
    {PART_CUST_A,              488 * 1024,    89 * 1024, UFS_PART_4}, /* cust_a                89MB p26 */
    {PART_CUST_B,              577 * 1024,    89 * 1024, UFS_PART_4}, /* cust_b                89MB p27 */
    {PART_CHIP_PROD_A,         666 * 1024,   760 * 1024, UFS_PART_4}, /* chip_prod_a          760MB p28 */
    {PART_CHIP_PROD_B,        1426 * 1024,   760 * 1024, UFS_PART_4}, /* chip_prod_b          760MB p29 */
    {PART_VENDOR_A,           2186 * 1024,   800 * 1024, UFS_PART_4}, /* vendor_a             800MB p30 */
    {PART_VENDOR_B,           2986 * 1024,   800 * 1024, UFS_PART_4}, /* vendor_b             800MB p31 */
    {PART_SYSTEM_A,           3786 * 1024,  4210 * 1024, UFS_PART_4}, /* system_a            4210MB p32 */
    {PART_SYSTEM_B,           7996 * 1024,  4210 * 1024, UFS_PART_4}, /* system_b            4210MB p33 */
    {PART_SYS_PROD_A,        12206 * 1024,  5800 * 1024, UFS_PART_4}, /* sys_prod_a         5800MB p34 */
    {PART_SYS_PROD_B,        18006 * 1024,  5800 * 1024, UFS_PART_4}, /* sys_prod_b         5800MB p35 */
    // {PART_CHIP_PROD,         666 * 1024,   1520 * 1024, UFS_PART_4}, /* chip_prod_a          1520MB p28 */
    // {PART_VENDOR,           2186 * 1024,   1600 * 1024, UFS_PART_4}, /* vendor_a             1600MB p30 */
    // {PART_SYSTEM,           3786 * 1024,  8420 * 1024, UFS_PART_4}, /* system            8420MB p32 */
    // {PART_SYS_PROD,        12206 * 1024,  11600 * 1024, UFS_PART_4}, /* sys_prod_a         11600MB p34 */
    {PART_VERSION_A,         23806 * 1024,  2000 * 1024, UFS_PART_4}, /* version_a         2000MB p36 */
    {PART_PRELOAD_A,         25806 * 1024,  1144 * 1024, UFS_PART_4}, /* preload_a         1144MB p37 */
    {PART_VERSION_B,         26950 * 1024,  2000 * 1024, UFS_PART_4}, /* version_b         2000MB p38 */
    {PART_PRELOAD_B,         28950 * 1024,  1144 * 1024, UFS_PART_4}, /* preload_b         1144MB p39 */
#ifdef CONFIG_FACTORY_MODE
    {PART_HIBENCH_IMG,       30094 * 1024,   128 * 1024, UFS_PART_4}, /* hibench_img        128MB p40 */
    {PART_HIBENCH_DATA,      30222 * 1024,   512 * 1024, UFS_PART_4}, /* hibench_data       512MB p41 */
    {PART_FLASH_AGEING,      30734 * 1024,   512 * 1024, UFS_PART_4}, /* flash_ageing       512MB p42 */
    {PART_HIBENCH_LOG,       31246 * 1024,    32 * 1024, UFS_PART_4}, /* hibench_log         32MB p43 */
    {PART_HIBENCH_LPM3,      31278 * 1024,    32 * 1024, UFS_PART_4}, /* hibench_lpm3        32MB p44 */
    {PART_SECFLASH_AGEING,   31310 * 1024,    32 * 1024, UFS_PART_4}, /* secflash_ageing     32MB p45 */
    {PART_USERDATA,          31342 * 1024,(4UL) * 1024 * 1024, UFS_PART_4}, /* userdata        4G p46 */
#elif defined CONFIG_PARTITION_ENG
    {PART_FTTEST,            30094 * 1024,   192 * 1024, UFS_PART_4}, /* fttest             192MB p30 */
    {PART_DDRTEST,           30286 * 1024,    48 * 1024, UFS_PART_4}, /* ddrtest             48MB p31 */
    {PART_HITEST_GPU,        30334 * 1024,   512 * 1024, UFS_PART_4}, /* hitest_gpu         512MB p32 */
    {PART_HITEST_ASP_DHRYSTONE, 30846 * 1024,    20 * 1024, UFS_PART_4}, /* hitest_asp_dhrystone  20MB p33 */
    {PART_HITEST_ASP_TEST,   30866 * 1024,   300 * 1024, UFS_PART_4}, /* hitest_asp_test    300MB p34 */
    {PART_HITEST_SENSORHUB,  31166 * 1024,     6 * 1024, UFS_PART_4}, /* hitest_sensorhub     6MB p35 */
    {PART_HITEST_ISP,        31172 * 1024,    25 * 1024, UFS_PART_4}, /* hitest_isp          25MB p36 */
    {PART_HITEST_ISP_AVS,    31197 * 1024,    25 * 1024, UFS_PART_4}, /* hitest_isp_avs      25MB p37 */
    {PART_HITEST_NPU,        31222 * 1024,    80 * 1024, UFS_PART_4}, /* hitest_npu          80MB p38 */
    {PART_HITEST_DSS,        31302 * 1024,    18 * 1024, UFS_PART_4}, /* hitest_dss          18MB p39 */
    {PART_DSS_DISP_BUF,      31320 * 1024,    64 * 1024, UFS_PART_4}, /* dss_disp_buf        64MB p40 */
    {PART_HITEST_JPEGENC,    31384 * 1024,   200 * 1024, UFS_PART_4}, /* hitest_jpegenc     200MB p41 */
    {PART_HITEST_HIPP,       31584 * 1024,   100 * 1024, UFS_PART_4}, /* hitest_hipp        100MB p42 */
    {PART_HIBENCH_LPM3,      31684 * 1024,     2 * 1024, UFS_PART_4}, /* hibench_lpm3         2MB p43 */
    {PART_JPEG_DEC_TEST_SRC, 31686 * 1024,    20 * 1024, UFS_PART_4}, /* jpeg_dec_test_src   20MB p44 */
    {PART_JPEG_DEC_TEST_DEST, 31706 * 1024,    80 * 1024, UFS_PART_4}, /* jpeg_dec_test_dest  80MB p45 */
    {PART_VCODE_DATA,        31786 * 1024,   160 * 1024, UFS_PART_4}, /* vcode_data         160MB p46 */
    {PART_VCODE_MAX_DATA,    31946 * 1024,   180 * 1024, UFS_PART_4}, /* vcode_max_data     180MB p47 */
    {PART_HITEST_SAFETY_ISLAND, 32126 * 1024,     4 * 1024, UFS_PART_4}, /* hitest_safety_island   4MB p48 */
    {PART_USERDATA,          32130 * 1024,(4UL) * 1024 * 1024, UFS_PART_4}, /* userdata        4G p49 */
#else
    {PART_USERDATA,          30094 * 1024,(4UL) * 1024 * 1024, UFS_PART_4}, /* userdata        4G p30 */
#endif
    {"0", 0, 0, 0},
};

#endif
