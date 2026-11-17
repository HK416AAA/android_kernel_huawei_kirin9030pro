/*
 *  Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 *  Description: the partition table.
 */

#ifndef _ANTLIA_CDC_ACE_PLAT_PARTITION_OHOS_H_
#define _ANTLIA_CDC_ACE_PLAT_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                       0,     2 * 1024, UFS_PART_0},
    {PART_XLOADER_B,                     0,     2 * 1024, UFS_PART_1},
    {PART_PTABLE_LU2,                        0,          512, UFS_PART_2}, /* ptable           512K    p0 */
    {PART_RESERVED2,                   512,          512, UFS_PART_2}, /* reserved2_a        512KB p1 */
    {PART_NPU_A,                      1024,     8 * 1024, UFS_PART_2}, /* npu_a                8MB p2 */
    {PART_IVP,                    9 * 1024,     2 * 1024, UFS_PART_2}, /* ivp_a                2MB p3 */
    {PART_HISEE_IMG,             11 * 1024,     4 * 1024, UFS_PART_2}, /* hisee_img_a          4MB p4 */
    {PART_HHEE,                  15 * 1024,     4 * 1024, UFS_PART_2}, /* hhee_a               4MB p5 */
    {PART_FASTBOOT,              19 * 1024,    12 * 1024, UFS_PART_2}, /* fastboot_a          12MB p6 */
    {PART_LOWPOWER_PARA,         31 * 1024,     1 * 1024, UFS_PART_2}, /* lowpower_para_a   1024KB p7 */
    {PART_BL2,                   32 * 1024,     4 * 1024, UFS_PART_2}, /* bl2_a                4MB p8 */
    {PART_TEEOS,                 36 * 1024,     8 * 1024, UFS_PART_2}, /* teeos_a              8MB p9 */
    {PART_FW_LPM3,               44 * 1024,          512, UFS_PART_2}, /* fw_lpm3_a          512KB p10 */
    {PART_FW_CPU_LPCTRL,  (44 * 1024 + 512),          256, UFS_PART_2}, /* fw_cpu_lpctrl_a    256KB p11 */
    {PART_FW_GPU_LPCTRL,  (44 * 1024 + 768),          128, UFS_PART_2}, /* fw_gpu_lpctrl_a    128KB p12 */
    {PART_FW_DDR_LPCTRL,  (44 * 1024 + 896),          128, UFS_PART_2}, /* fw_ddr_lpctrl_a    128KB p13 */
    {PART_FW_UFSDEV,             45 * 1024,     8 * 1024, UFS_PART_2}, /* fw_ufsdev_a          8MB p14 */
    {PART_VECTOR,                53 * 1024,     4 * 1024, UFS_PART_2}, /* vector_a             4MB p15 */
    {PART_ISP_BOOT_A,            57 * 1024,     2 * 1024, UFS_PART_2}, /* isp_boot_a           2MB p16 */
    {PART_ISP_FIRMWARE_A,        59 * 1024,    14 * 1024, UFS_PART_2}, /* isp_firmware_a      14MB p17 */
    {PART_FW_HIFI_A,             73 * 1024,    12 * 1024, UFS_PART_2}, /* fw_hifi_a           12MB p18 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_BOOT,                  85 * 1024,   100 * 1024, UFS_PART_2},        /* boot_a             100MB p19 */
    {PART_UPDATER_BOOT,         185 * 1024,    85 * 1024, UFS_PART_2},    /* updater_boot_a      85MB p20 */
    {PART_UPDATER_RAMDISK,      270 * 1024,    32 * 1024, UFS_PART_2},        /* updater_ramdisk_a   32MB p21 */
    {PART_UPDATER_VENDOR,       302 * 1024,    24 * 1024, UFS_PART_2},         /* updater_vendor_a    24MB p22 */
    {PART_UPDATER_BOOT_BAK,     326 * 1024,    12 * 1024, UFS_PART_2}, /* updater_boot_bak_a  12MB p23 */
    {PART_UPDATER_RAMDISK_BAK,     338 * 1024,    12 * 1024, UFS_PART_2},    /* updater_ramdisk_bak_a  12MB p24 */
    {PART_UPDATER_VENDOR_BAK,     350 * 1024,     8 * 1024, UFS_PART_2},     /* updater_vendor_bak_a   8MB p25 */
    {PART_RESERVED3_lu2,        358 * 1024,    50 * 1024, UFS_PART_2},        /* reserved3_lu2       50MB p26 */
#elif defined CONFIG_HWSANITIZER_ENABLE
    {PART_BOOT,                  85 * 1024,    46 * 1024, UFS_PART_2},        /* boot_a              46MB p19 */
    {PART_UPDATER_BOOT,         131 * 1024,    45 * 1024, UFS_PART_2},    /* updater_boot_a      45MB p20 */
    {PART_UPDATER_RAMDISK,      176 * 1024,    40 * 1024, UFS_PART_2},        /* updater_ramdisk_a   40MB p21 */
    {PART_UPDATER_VENDOR,       216 * 1024,    24 * 1024, UFS_PART_2},         /* updater_vendor_a    24MB p22 */
    {PART_UPDATER_BOOT_BAK,     240 * 1024,    45 * 1024, UFS_PART_2}, /* updater_boot_bak_a  45MB p23 */
    {PART_UPDATER_RAMDISK_BAK,     285 * 1024,    40 * 1024, UFS_PART_2},    /* updater_ramdisk_bak_a  40MB p24 */
    {PART_UPDATER_VENDOR_BAK,     325 * 1024,    24 * 1024, UFS_PART_2},     /* updater_vendor_bak_a  24MB p25 */
    {PART_RESERVED3_lu2,        349 * 1024,    59 * 1024, UFS_PART_2},        /* reserved3_lu2       59MB p26 */
#else
    {PART_BOOT,                  85 * 1024,    46 * 1024, UFS_PART_2}, /* boot_a              46MB p19 */
    {PART_UPDATER_RAMDISK,      131 * 1024,    32 * 1024, UFS_PART_2}, /* updater_ramdisk_a   32MB p20 */
    {PART_UPDATER_VENDOR,       163 * 1024,    24 * 1024, UFS_PART_2}, /* updater_vendor_a    24MB p21 */
    {PART_UPDATER_BOOT,         187 * 1024,    55 * 1024, UFS_PART_2}, /* updater_boot_a      55MB p22 */
    {PART_UPDATER_RAMDISK_BAK,     242 * 1024,    32 * 1024, UFS_PART_2}, /* updater_ramdisk_bak_a  32MB p23 */
    {PART_UPDATER_VENDOR_BAK,     274 * 1024,    24 * 1024, UFS_PART_2}, /* updater_vendor_bak_a  24MB p24 */
    {PART_UPDATER_BOOT_BAK,     298 * 1024,    55 * 1024, UFS_PART_2}, /* updater_boot_bak_a  55MB p25 */
    {PART_RESERVED1,            353 * 1024,    55 * 1024, UFS_PART_2}, /* reserved1_a         75MB p26 */
#endif
    {PART_KPATCH,               408 * 1024,     4 * 1024, UFS_PART_2}, /* kpatch_a             4MB p27 */
    {PART_PATCH,                412 * 1024,    32 * 1024, UFS_PART_2}, /* patch_a             32MB p28 */
    {PART_ENG_SYSTEM,           444 * 1024,    12 * 1024, UFS_PART_2}, /* eng_system_a        12MB p29 */
    {PART_ENG_CHIPSET,          456 * 1024,    20 * 1024, UFS_PART_2}, /* eng_chipset_a       20MB p30 */
    {PART_RVT_SYSTEM,           476 * 1024,     1 * 1024, UFS_PART_2}, /* rvt_system_a      1024KB p31 */
    {PART_RVT_VENDOR,           477 * 1024,     1 * 1024, UFS_PART_2}, /* rvt_vendor_a      1024KB p32 */
    {PART_RVT_CHIP_PROD,        478 * 1024,     1 * 1024, UFS_PART_2}, /* rvt_chip_prod_a   1024KB p33 */
    {PART_RVT_CUST,             479 * 1024,     1 * 1024, UFS_PART_2}, /* rvt_cust_a        1024KB p34 */
    {PART_RVT_SYS_PROD,         480 * 1024,     1 * 1024, UFS_PART_2}, /* rvt_sys_prod_a    1024KB p35 */
    {PART_UPDATER_RVT,          481 * 1024,     2 * 1024, UFS_PART_2}, /* updater_rvt_a        2MB p36 */
    {PART_UPDATER_BAK_RVT,      483 * 1024,     2 * 1024, UFS_PART_2}, /* updater_bak_rvt_a    2MB p37 */
    {PART_RVT,                  485 * 1024,     4 * 1024, UFS_PART_2}, /* rvt_a                4MB p38 */
    {PART_RAMDISK,              489 * 1024,     4 * 1024, UFS_PART_2}, /* ramdisk_a            4MB p39 */
    {PART_DTBO,                 493 * 1024,    20 * 1024, UFS_PART_2}, /* dtbo_a              20MB p40 */
    {PART_FW_DTB,               513 * 1024,     8 * 1024, UFS_PART_2}, /* fw_dtb_a             8MB p41 */
    {PART_TRUSTFIRMWARE,        521 * 1024,     2 * 1024, UFS_PART_2}, /* trustfirmware_a      2MB p42 */
    {PART_THEE,                 523 * 1024,     4 * 1024, UFS_PART_2}, /* thee_a               4MB p43 */
    {PART_TZSP,                 527 * 1024,    12 * 1024, UFS_PART_2}, /* tzsp_a              12MB p44 */
    {PART_DICE,                 539 * 1024,         1024, UFS_PART_2}, /* dice_a            1024KB p45 */
    {PART_DACC,                 540 * 1024,          256, UFS_PART_2}, /* dacc_a             256KB p46 */
    {PART_DACC_LITE,    (540 * 1024 + 256),          256, UFS_PART_2}, /* dacc_lite_a        256KB p47 */
    {PART_VENC,         (540 * 1024 + 512),          512, UFS_PART_2}, /* venc_a             512KB p48 */
    {PART_DDR_XPU_BOOT0,        541 * 1024,          136, UFS_PART_2}, /* ddr_xpu_boot0_a    136KB p49 */
    {PART_DDR_XPU_BOOT1,  (541 * 1024 + 136),          136, UFS_PART_2},  /* ddr_xpu_boot1_a    136KB p50 */
    {PART_CONN_CALIDATA,  (541 * 1024 + 272),         1024, UFS_PART_2},  /* conn_calidata_a   1024KB p51 */
    {PART_SEPLAT,         (542 * 1024 + 272),     4 * 1024, UFS_PART_2}, /* seplat_a             4MB p52 */
    {PART_RDA_DTB,       (546 * 1024 + 272),     8 * 1024, UFS_PART_2}, /* rda_dtb_a            8MB p53 */
    {PART_MICROVISOR,    (554 * 1024 + 272),   100 * 1024, UFS_PART_2}, /* microvisor_a       100MB p54 */
    {PART_MICROVISOR_RECOVERY,  (654 * 1024 + 272),   110 * 1024, UFS_PART_2}, /* microvisor_recovery_a 110MB p55 */
    {PART_RDA,            (764 * 1024 + 272),   200 * 1024, UFS_PART_2}, /* rda_a              200MB p56 */
    {PART_RDA_VENDOR,     (964 * 1024 + 272),   100 * 1024, UFS_PART_2}, /* rda_vendor_a       100MB p57 */
    {PART_SAFETY_ISLAND,  (1064 * 1024 + 272),     4 * 1024, UFS_PART_2}, /* safety_island_a      4MB p58 */
    {PART_RESERVED2,      (1068 * 1024 + 272),    20 * 1024, UFS_PART_2}, /* reserved2_a         21MB p59 */
    {PART_PTABLE_LU3,                        0,          512, UFS_PART_3}, /* ptable           512K    p0 */
    {PART_RESERVED2_B,                 512,          512, UFS_PART_3}, /* reserved2_b        512KB p1 */
    {PART_NPU_B,                      1024,     8 * 1024, UFS_PART_3}, /* npu_b                8MB p2 */
    {PART_IVP_B,                  9 * 1024,     2 * 1024, UFS_PART_3}, /* ivp_b                2MB p3 */
    {PART_HISEE_IMG_B,           11 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img_b          4MB p4 */
    {PART_HHEE_B,                15 * 1024,     4 * 1024, UFS_PART_3}, /* hhee_b               4MB p5 */
    {PART_FASTBOOT_B,            19 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot_b          12MB p6 */
    {PART_LOWPOWER_PARA_B,       31 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para_b   1024KB p7 */
    {PART_BL2_B,                 32 * 1024,     4 * 1024, UFS_PART_3}, /* bl2_b                4MB p8 */
    {PART_TEEOS_B,               36 * 1024,     8 * 1024, UFS_PART_3}, /* teeos_b              8MB p9 */
    {PART_FW_LPM3_B,             44 * 1024,          512, UFS_PART_3}, /* fw_lpm3_b          512KB p10 */
    {PART_FW_CPU_LPCTRL_B,(44 * 1024 + 512),          256, UFS_PART_3}, /* fw_cpu_lpctrl_b    256KB p11 */
    {PART_FW_GPU_LPCTRL_B,(44 * 1024 + 768),          128, UFS_PART_3}, /* fw_gpu_lpctrl_b    128KB p12 */
    {PART_FW_DDR_LPCTRL_B,(44 * 1024 + 896),          128, UFS_PART_3}, /* fw_ddr_lpctrl_b    128KB p13 */
    {PART_FW_UFSDEV_B,           45 * 1024,     8 * 1024, UFS_PART_3}, /* fw_ufsdev_b          8MB p14 */
    {PART_VECTOR_B,              53 * 1024,     4 * 1024, UFS_PART_3}, /* vector_b             4MB p15 */
    {PART_ISP_BOOT_B,            57 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot_b           2MB p16 */
    {PART_ISP_FIRMWARE_B,        59 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware_b      14MB p17 */
    {PART_FW_HIFI_B,             73 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi_b           12MB p18 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_BOOT_B,                85 * 1024,   100 * 1024, UFS_PART_3}, /* boot_b             100MB p19 */
    {PART_UPDATER_BOOT_B,       185 * 1024,    85 * 1024, UFS_PART_3}, /* updater_boot_b      85MB p20 */
    {PART_UPDATER_RAMDISK_B,    270 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_b   32MB p21 */
    {PART_UPDATER_VENDOR_B,     302 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_b    24MB p22 */
    {PART_UPDATER_BOOT_BAK_B,   326 * 1024,    12 * 1024, UFS_PART_3}, /* updater_boot_bak_b  12MB p23 */
    {PART_UPDATER_RAMDISK_BAK_B,   338 * 1024,    12 * 1024, UFS_PART_3}, /* updater_ramdisk_bak_b  12MB p24 */
    {PART_UPDATER_VENDOR_BAK_B,   350 * 1024,     8 * 1024, UFS_PART_3}, /* updater_vendor_bak_b   8MB p25 */
    {PART_RESERVED3_lu3,        358 * 1024,    50 * 1024, UFS_PART_3}, /* reserved3_lu3       49MB p26 */
#elif defined CONFIG_HWSANITIZER_ENABLE
    {PART_BOOT_B,                85 * 1024,    46 * 1024, UFS_PART_3}, /* boot_b              46MB p19 */
    {PART_UPDATER_BOOT_B,       131 * 1024,    45 * 1024, UFS_PART_3}, /* updater_boot_b      45MB p20 */
    {PART_UPDATER_RAMDISK_B,    176 * 1024,    40 * 1024, UFS_PART_3}, /* updater_ramdisk_b   40MB p21 */
    {PART_UPDATER_VENDOR_B,     216 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_b    24MB p22 */
    {PART_UPDATER_BOOT_BAK_B,   240 * 1024,    45 * 1024, UFS_PART_3}, /* updater_boot_bak_b  45MB p23 */
    {PART_UPDATER_RAMDISK_BAK_B,   285 * 1024,    40 * 1024, UFS_PART_3}, /* updater_ramdisk_bak_b  40MB p24 */
    {PART_UPDATER_VENDOR_BAK_B,   325 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_bak_b  24MB p25 */
    {PART_RESERVED3_lu3,        349 * 1024,    59 * 1024, UFS_PART_3}, /* reserved3_lu3       58MB p26 */
#else
    {PART_BOOT_B,                85 * 1024,    46 * 1024, UFS_PART_3}, /* boot_b              46MB p19 */
    {PART_UPDATER_RAMDISK_B,    131 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_b   32MB p20 */
    {PART_UPDATER_VENDOR_B,     163 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_b    24MB p21 */
    {PART_UPDATER_BOOT_B,       187 * 1024,    55 * 1024, UFS_PART_3}, /* updater_boot_b      55MB p22 */
    {PART_UPDATER_RAMDISK_BAK_B,   242 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak_b  32MB p23 */
    {PART_UPDATER_VENDOR_BAK_B,   274 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_bak_b  24MB p24 */
    {PART_UPDATER_BOOT_BAK_B,   298 * 1024,    55 * 1024, UFS_PART_3}, /* updater_boot_bak_b  55MB p25 */
    {PART_RESERVED1_B,          353 * 1024,    55 * 1024, UFS_PART_3}, /* reserved1_b         75MB p26 */
#endif
    {PART_KPATCH_B,             408 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch_b             4MB p27 */
    {PART_PATCH_B,              412 * 1024,    32 * 1024, UFS_PART_3}, /* patch_b             32MB p28 */
    {PART_ENG_SYSTEM_B,         444 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system_b        12MB p29 */
    {PART_ENG_CHIPSET_B,        456 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset_b       20MB p30 */
    {PART_RVT_SYSTEM_B,         476 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system_b      1024KB p31 */
    {PART_RVT_VENDOR_B,         477 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor_b      1024KB p32 */
    {PART_RVT_CHIP_PROD_B,      478 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod_b   1024KB p33 */
    {PART_RVT_CUST_B,           479 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust_b        1024KB p34 */
    {PART_RVT_SYS_PROD_B,       480 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod_b    1024KB p35 */
    {PART_UPDATER_RVT_B,        481 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt_b        2MB p36 */
    {PART_UPDATER_BAK_RVT_B,    483 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt_b    2MB p37 */
    {PART_RVT_B,                485 * 1024,     4 * 1024, UFS_PART_3}, /* rvt_b                4MB p38 */
    {PART_RAMDISK_B,            489 * 1024,     4 * 1024, UFS_PART_3}, /* ramdisk_b            4MB p39 */
    {PART_DTBO_B,               493 * 1024,    20 * 1024, UFS_PART_3}, /* dtbo_b              20MB p40 */
    {PART_FW_DTB_B,             513 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb_b             8MB p41 */
    {PART_TRUSTFIRMWARE_B,      521 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware_b      2MB p42 */
    {PART_THEE_B,               523 * 1024,     4 * 1024, UFS_PART_3}, /* thee_b               4MB p43 */
    {PART_TZSP_B,               527 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp_b              12MB p44 */
    {PART_DICE_B,               539 * 1024,         1024, UFS_PART_3}, /* dice_b            1024KB p45 */
    {PART_DACC_B,               540 * 1024,          256, UFS_PART_3}, /* dacc_b             256KB p46 */
    {PART_DACC_LITE_B,  (540 * 1024 + 256),          256, UFS_PART_3}, /* dacc_lite_b        256KB p47 */
    {PART_VENC_B,       (540 * 1024 + 512),          512, UFS_PART_3}, /* venc_b             512KB p48 */
    {PART_DDR_XPU_BOOT0_B,      541 * 1024,          136, UFS_PART_3}, /* ddr_xpu_boot0_b    136KB p49 */
    {PART_DDR_XPU_BOOT1_B,(541 * 1024 + 136),          136, UFS_PART_3},  /* ddr_xpu_boot1_b    136KB p50 */
    {PART_CONN_CALIDATA_B,(541 * 1024 + 272),         1024, UFS_PART_3},  /* conn_calidata_b   1024KB p51 */
    {PART_SEPLAT_B,       (542 * 1024 + 272),     4 * 1024, UFS_PART_3}, /* seplat_b             4MB p52 */
    {PART_RDA_DTB_B,      (546 * 1024 + 272),     8 * 1024, UFS_PART_3}, /* rda_dtb_b            8MB p53 */
    {PART_MICROVISOR_B,   (554 * 1024 + 272),   100 * 1024, UFS_PART_3}, /* microvisor_b       100MB p54 */
    {PART_MICROVISOR_RECOVERY_B,(654 * 1024 + 272),   110 * 1024, UFS_PART_3}, /* microvisor_recovery_b 110MB p55 */
    {PART_RDA_B,         (764 * 1024 + 272),   200 * 1024, UFS_PART_3}, /* rda_b              200MB p56 */
    {PART_RDA_VENDOR_B,  (964 * 1024 + 272),   100 * 1024, UFS_PART_3}, /* rda_vendor_b       100MB p57 */
    {PART_SAFETY_ISLAND_B,(1064 * 1024 + 272),     4 * 1024, UFS_PART_3}, /* safety_island_b      4MB p58 */
    {PART_RESERVED2_B,    (1068 * 1024 + 272),    20 * 1024, UFS_PART_3}, /* reserved2_b         21MB p59 */
    {PART_PTABLE_LU4,             0,                 512, UFS_PART_4}, /* ptable_lu4       512K    p0 */
    {PART_RESERVED1_lu4,               512,          512, UFS_PART_4}, /* reserved1_lu4      512KB p1 */
    {PART_RDA_LOG,                    1024,   500 * 1024, UFS_PART_4}, /* rda_log            500MB p2 */
    {PART_RDA_OEMINFO,          501 * 1024,    16 * 1024, UFS_PART_4}, /* rda_oeminfo         16MB p3 */
    {PART_RDA_RECOVERY_DFX,     517 * 1024,     4 * 1024, UFS_PART_4}, /* rda_recovery_dfx     4MB p4 */
    {PART_RESERVED2_lu4,        521 * 1024,   119 * 1024, UFS_PART_4}, /* reserved2_lu4      119MB p5 */
    {PART_PTABLE_LU5,                    0,          512, UFS_PART_5}, /* ptable_lu5       512K    p0 */
    {PART_FRP,                         512,          512, UFS_PART_5}, /* frp                512KB p1 */
    {PART_PERSIST,                    1024,     6 * 1024, UFS_PART_5}, /* persist              6MB p2 */
    {PART_BOOT_CTRL,              7 * 1024,     1 * 1024, UFS_PART_5}, /* boot_ctrl         1024KB p3 */
    {PART_NVME,                   8 * 1024,     5 * 1024, UFS_PART_5}, /* nvme                 5MB p4 */
    {PART_CTF,                   13 * 1024,     1 * 1024, UFS_PART_5}, /* ctf               1024KB p5 */
    {PART_OEMINFO,               14 * 1024,    96 * 1024, UFS_PART_5}, /* oeminfo             96MB p6 */
    {PART_BOARD_ID,             110 * 1024,           64, UFS_PART_5}, /* board_id            64KB p7 */
    {PART_RESERVED1_lu5, (110 * 1024 + 64),   960 + 1024, UFS_PART_5}, /* reserved1_lu5     1984KB p8 */
    {PART_SECURE_STORAGE,       112 * 1024,    32 * 1024, UFS_PART_5}, /* secure_storage      32MB p9 */
    {PART_HISEE_ENCOS,          144 * 1024,     4 * 1024, UFS_PART_5}, /* hisee_encos          4MB p10 */
    {PART_VERITYKEY,            148 * 1024,     1 * 1024, UFS_PART_5}, /* veritykey         1024KB p11 */
    {PART_DDR_PARA,             149 * 1024,     1 * 1024, UFS_PART_5}, /* ddr_para          1024KB p12 */
    {PART_BATT_TP_PARA,         150 * 1024,     1 * 1024, UFS_PART_5}, /* batt_tp_para      1024KB p13 */
    {PART_TOC,                  151 * 1024,     1 * 1024, UFS_PART_5}, /* toc               1024KB p14 */
    {PART_LOG,                  152 * 1024,    80 * 1024, UFS_PART_5}, /* log                 80MB p15 */
    {PART_BOOTFAIL_INFO,        232 * 1024,     2 * 1024, UFS_PART_5}, /* bootfail_info        2MB p16 */
    {PART_MISC,                 234 * 1024,     2 * 1024, UFS_PART_5}, /* misc                 2MB p17 */
    {PART_DFX,                  236 * 1024,    16 * 1024, UFS_PART_5}, /* dfx                 16MB p18 */
    {PART_RRECORD,              252 * 1024,    16 * 1024, UFS_PART_5}, /* rrecord             16MB p19 */
    {PART_CACHE,                268 * 1024,   104 * 1024, UFS_PART_5}, /* cache              104MB p20 */
    {PART_METADATA,             372 * 1024,    16 * 1024, UFS_PART_5}, /* metadata            16MB p21 */
    {PART_HISEE_FS,             388 * 1024,     8 * 1024, UFS_PART_5}, /* hisee_fs             8MB p22 */
    {PART_CDC_DATA,             396 * 1024,     8 * 1024, UFS_PART_5}, /* cdc_data             8MB p23 */
    {PART_FW_HIFI,              404 * 1024,    12 * 1024, UFS_PART_5}, /* fw_hifi_a           12MB p18 */
    {PART_NPU,                  416 * 1024,     8 * 1024, UFS_PART_5}, /* npu_a                8MB p2 */
    {PART_ISP_BOOT,             424 * 1024,     2 * 1024, UFS_PART_5}, /* isp_boot_a           2MB p16 */
    {PART_ISP_FIRMWARE,         426 * 1024,    14 * 1024, UFS_PART_5}, /* isp_firmware_a      14MB p17 */
    {PART_RESERVED2_lu5,        440 * 1024,    40 * 1024, UFS_PART_5}, /* reserved2_lu5       76MB p24 */
    {PART_HYPERHOLD,            480 * 1024,     4 * 1024, UFS_PART_5}, /* hyperhold_a          4MB p25 */
    {PART_HYPERHOLD_B,          484 * 1024,     4 * 1024, UFS_PART_5}, /* hyperhold_b          4MB p26 */
    {PART_RDA_DATA,             488 * 1024,   500 * 1024, UFS_PART_5}, /* rda_data           500MB p27 */
    {PART_RESERVED3_lu5,        988 * 1024,     2 * 1024, UFS_PART_5}, /* reserved3_lu5        2MB p28 */
    {PART_SYSTEM,               990 * 1024,  4210 * 1024, UFS_PART_5}, /* system_a          4210MB p29 */
    {PART_SYS_PROD,            5200 * 1024,  5800 * 1024, UFS_PART_5}, /* sys_prod_a        5800MB p30 */
    {PART_CUST,               11000 * 1024,    88 * 1024, UFS_PART_5}, /* cust_a              88MB p31 */
    {PART_VENDOR,             11088 * 1024,   800 * 1024, UFS_PART_5}, /* vendor_a           800MB p32 */
    {PART_CHIP_PROD,          11888 * 1024,   760 * 1024, UFS_PART_5}, /* chip_prod_a        760MB p33 */
    {PART_SYSTEM_B,           12648 * 1024,  4210 * 1024, UFS_PART_5}, /* system_b          4210MB p34 */
    {PART_SYS_PROD_B,         16858 * 1024,  5800 * 1024, UFS_PART_5}, /* sys_prod_b        5800MB p35 */
    {PART_CUST_B,             22658 * 1024,    88 * 1024, UFS_PART_5}, /* cust_b              88MB p36 */
    {PART_VENDOR_B,           22746 * 1024,   800 * 1024, UFS_PART_5}, /* vendor_b           800MB p37 */
    {PART_CHIP_PROD_B,        23546 * 1024,   760 * 1024, UFS_PART_5}, /* chip_prod_b        760MB p38 */
    {PART_VERSION,            24306 * 1024,  2000 * 1024, UFS_PART_5}, /* version_a         2000MB p39 */
    {PART_PRELOAD,            26306 * 1024,  1144 * 1024, UFS_PART_5}, /* preload_a         1144MB p40 */
    {PART_RDA_PRODUCT,        27450 * 1024,   900 * 1024, UFS_PART_5}, /* rda_product_a      900MB p41 */
    {PART_RDA_VERSION,        28350 * 1024,   600 * 1024, UFS_PART_5}, /* rda_version_a      600MB p42 */
    {PART_VERSION_B,          28950 * 1024,  2000 * 1024, UFS_PART_5}, /* version_b         2000MB p43 */
    {PART_PRELOAD_B,          30950 * 1024,  1144 * 1024, UFS_PART_5}, /* preload_b         1144MB p44 */
    {PART_RDA_PRODUCT_B,      32094 * 1024,   900 * 1024, UFS_PART_5}, /* rda_product_b      900MB p45 */
    {PART_RDA_VERSION_B,      32994 * 1024,   600 * 1024, UFS_PART_5}, /* rda_version_b      600MB p46 */
#ifdef CONFIG_FACTORY_MODE
    {PART_HIBENCH_IMG,        33594 * 1024,   128 * 1024, UFS_PART_5}, /* hibench_img        128MB p47 */
    {PART_HIBENCH_DATA,       33722 * 1024,   512 * 1024, UFS_PART_5}, /* hibench_data       512MB p48 */
    {PART_FLASH_AGEING,       34234 * 1024,   512 * 1024, UFS_PART_5}, /* flash_ageing       512MB p49 */
    {PART_HIBENCH_LOG,        34746 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p50 */
    {PART_HIBENCH_LPM3,       34778 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_lpm3        32MB p51 */
    {PART_SECFLASH_AGEING,    34810 * 1024,    32 * 1024, UFS_PART_5}, /* secflash_ageing     32MB p52 */
    {PART_RESERVED6,          34842 * 1024,  1406 * 1024, UFS_PART_5}, /* reserved6         1406MB p53 */
    {PART_USERDATA,           36248 * 1024, (4UL) * 1024 * 1024, UFS_PART_5}, /* userdata       4G p54 */
#elif defined CONFIG_PARTITION_ENG
    {PART_FTTEST,             33594 * 1024,   192 * 1024, UFS_PART_5}, /* fttest             192MB p47 */
    {PART_DDRTEST,            33786 * 1024,    48 * 1024, UFS_PART_5}, /* ddrtest             48MB p48 */
    {PART_HITEST_GPU,         33834 * 1024,   512 * 1024, UFS_PART_5}, /* hitest_gpu         512MB p49 */
    {PART_HITEST_ASP_DHRYSTONE, 34346 * 1024,    20 * 1024, UFS_PART_5}, /* hitest_asp_dhrystone  20MB p50 */
    {PART_HITEST_ASP_TEST,    34366 * 1024,   300 * 1024, UFS_PART_5}, /* hitest_asp_test    300MB p51 */
    {PART_HITEST_SENSORHUB,   34666 * 1024,     6 * 1024, UFS_PART_5}, /* hitest_sensorhub     6MB p52 */
    {PART_HITEST_ISP,         34672 * 1024,    25 * 1024, UFS_PART_5}, /* hitest_isp          25MB p53 */
    {PART_HITEST_ISP_AVS,     34697 * 1024,    25 * 1024, UFS_PART_5}, /* hitest_isp_avs      25MB p54 */
    {PART_HITEST_NPU,         34722 * 1024,    80 * 1024, UFS_PART_5}, /* hitest_npu          80MB p55 */
    {PART_HITEST_DSS,         34802 * 1024,    18 * 1024, UFS_PART_5}, /* hitest_dss          18MB p56 */
    {PART_DSS_DISP_BUF,       34820 * 1024,    64 * 1024, UFS_PART_5}, /* dss_disp_buf        64MB p57 */
    {PART_HITEST_JPEGENC,     34884 * 1024,   200 * 1024, UFS_PART_5}, /* hitest_jpegenc     200MB p58 */
    {PART_HITEST_HIPP,        35084 * 1024,   100 * 1024, UFS_PART_5}, /* hitest_hipp        100MB p59 */
    {PART_HIBENCH_LPM3,       35184 * 1024,     2 * 1024, UFS_PART_5}, /* hibench_lpm3         2MB p60 */
    {PART_JPEG_DEC_TEST_SRC,  35186 * 1024,    20 * 1024, UFS_PART_5}, /* jpeg_dec_test_src   20MB p61 */
    {PART_JPEG_DEC_TEST_DEST, 35206 * 1024,    80 * 1024, UFS_PART_5}, /* jpeg_dec_test_dest  80MB p62 */
    {PART_VCODE_DATA,         35286 * 1024,   160 * 1024, UFS_PART_5}, /* vcode_data         160MB p63 */
    {PART_VCODE_MAX_DATA,     35446 * 1024,   180 * 1024, UFS_PART_5}, /* vcode_max_data     180MB p64 */
    {PART_HITEST_SAFETY_ISLAND, 35626 * 1024,     4 * 1024, UFS_PART_5}, /* hitest_safety_island   4MB p65 */
    {PART_USERDATA,           35630 * 1024, (4UL) * 1024 * 1024, UFS_PART_5}, /* userdata       4G p66 */
#else
    {PART_USERDATA,           33594 * 1024, (4UL) * 1024 * 1024, UFS_PART_5}, /* userdata       4G p47 */
#endif

    {"0", 0, 0, 0},
};

#endif