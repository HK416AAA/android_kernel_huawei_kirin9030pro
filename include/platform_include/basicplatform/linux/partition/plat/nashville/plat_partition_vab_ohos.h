#ifndef _PISCES_PLAT_PARTITION_OHOS_H_
#define _PISCES_PLAT_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER_A,                      0,     4 * 1024, UFS_PART_0},
    {PART_XLOADER_B,                    0,     4 * 1024, UFS_PART_1},
    {PART_PTABLE,                 0,                   512,    UFS_PART_2}, /* ptable           512K    p0 */
    {PART_FRP,                         512,          512, UFS_PART_2}, /* frp                512KB p1 */
    {PART_PERSIST,                    1024,     6 * 1024, UFS_PART_2}, /* persist              6MB p2 */
    {PART_RESERVED1,              7 * 1024,         1024, UFS_PART_2}, /* reserved1         1024KB p3 */
    {PART_PTABLE_LU3,                              0,          512,  UFS_PART_3}, /* ptable_lu3          512KB p0 */
    {PART_LOWPOWER_PARA_A,             512,     1 * 1024, UFS_PART_3}, /* lowpower_para_a   1024KB p1 */
    {PART_BL2_A,             (1 * 1024 + 512),     4 * 1024, UFS_PART_3}, /* bl2_a                4MB p2 */
    {PART_FW_LPM3_A,         (5 * 1024 + 512),          512, UFS_PART_3}, /* fw_lpm3_a          512KB p3 */
    {PART_SEPLAT_A,               6 * 1024,     4 * 1024, UFS_PART_3}, /* seplat_a             4MB p4 */
    {PART_FW_CPU_LPCTRL_A,       10 * 1024,          256, UFS_PART_3}, /* fw_cpu_lpctrl_a    256KB p5 */
    {PART_FW_GPU_LPCTRL_A,   (10 * 1024 + 256),          128, UFS_PART_3}, /* fw_gpu_lpctrl_a    128KB p6 */
    {PART_FW_DDR_LPCTRL_A,   (10 * 1024 + 384),          256, UFS_PART_3}, /* fw_ddr_lpctrl_a    256KB p7 */
    {PART_DDR_XPU_BOOT0_A,   (10 * 1024 + 640),          256, UFS_PART_3}, /* ddr_xpu_boot0_a    256KB p8 */
    {PART_DDR_XPU_BOOT1_A,   (10 * 1024 + 896),          256, UFS_PART_3}, /* ddr_xpu_boot1_a    256KB p9 */
    {PART_DDR_XPU_BOOT2_A,   (11 * 1024 + 128),          256, UFS_PART_3}, /* ddr_xpu_boot2_a    256KB p10 */
    {PART_UCE_A,             (11 * 1024 + 384),          160, UFS_PART_3}, /* uce_a              160KB p11 */
    {PART_RESERVED3,         (11 * 1024 + 544), 5 * 1024+480, UFS_PART_3}, /* reserved3         5600KB p12 */
    {PART_NPU_A,                 17 * 1024,     8 * 1024, UFS_PART_3}, /* npu_a                8MB p13 */
    {PART_IVP_A,                 25 * 1024,     2 * 1024, UFS_PART_3}, /* ivp_a                2MB p14 */
    {PART_DACC_A,                27 * 1024,          512, UFS_PART_3}, /* dacc_a             512KB p15 */
    {PART_VENC_A,            (27 * 1024 + 512),          512, UFS_PART_3}, /* venc_a             512KB p16 */
    {PART_HISEE_IMG_A,           28 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img_a          4MB p17 */
    {PART_HHEE_A,                32 * 1024,     4 * 1024, UFS_PART_3}, /* hhee_a               4MB p18 */
    {PART_FASTBOOT_A,            36 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot_a          12MB p19 */
    {PART_VECTOR_A,              48 * 1024,     4 * 1024, UFS_PART_3}, /* vector_a             4MB p20 */
    {PART_ISP_BOOT_A,            52 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot_a           2MB p21 */
    {PART_ISP_FIRMWARE_A,        54 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware_a      14MB p22 */
    {PART_FW_HIFI_A,             68 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi_a           12MB p23 */
    {PART_TEEOS_A,               80 * 1024,     8 * 1024, UFS_PART_3}, /* teeos_a              8MB p24 */
    {PART_SENSORHUB_A,           88 * 1024,    13 * 1024, UFS_PART_3}, /* sensorhub_a         13MB p25 */
    {PART_SENSORHUB_LOG_DIC_A,   101 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic_a   3MB p26 */
    {PART_HKRR_A,               104 * 1024,    16 * 1024, UFS_PART_3}, /* hkrr_a              16MB p27 */
    {PART_FW_UFSDEV_A,          120 * 1024,     4 * 1024, UFS_PART_3}, /* fw_ufsdev_a          4MB p28 */
    {PART_FW_DFA_A,             124 * 1024,     1 * 1024, UFS_PART_3}, /* fw_dfa_a          1024KB p29 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_UPDATER_RAMDISK_A,    125 * 1024,    64 * 1024, UFS_PART_3}, /* updater_ramdisk_a   64MB p30 */
    {PART_UPDATER_VENDOR_A,     189 * 1024,    35 * 1024, UFS_PART_3}, /* updater_vendor_a    35MB p31 */
    {PART_BOOT_A,               224 * 1024,    46 * 1024, UFS_PART_3}, /* boot_a              46MB p32 */
    {PART_UPDATER_BOOT_A,       270 * 1024,    66 * 1024, UFS_PART_3}, /* updater_boot_a      66MB p33 */
    {PART_UPDATER_BOOT_BAK_A,   336 * 1024,    66 * 1024, UFS_PART_3}, /* updater_boot_bak_a  66MB p34 */
    {PART_EXT_RVT_A,            402 * 1024,     2 * 1024, UFS_PART_3}, /* ext_rvt_a            2MB p35 */
    {PART_THEE_A,               404 * 1024,     4 * 1024, UFS_PART_3}, /* thee_a               4MB p36 */
    {PART_TZSP_A,               408 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp_a              12MB p37 */
    {PART_UPDATER_RAMDISK_BAK_A,   420 * 1024,    64 * 1024, UFS_PART_3}, /* updater_ramdisk_bak_a  64MB p38 */
    {PART_UPDATER_VENDOR_BAK_A,   484 * 1024,    35 * 1024, UFS_PART_3}, /* updater_vendor_bak_a  35MB p39 */
    {PART_ENG_SYSTEM_A,         519 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system_a        12MB p40 */
    {PART_ENG_CHIPSET_A,        531 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset_a       20MB p41 */
    {PART_FW_DTB_A,             551 * 1024,    20 * 1024, UFS_PART_3}, /* fw_dtb_a            20MB p42 */
    {PART_DTBO_A,               571 * 1024,    20 * 1024, UFS_PART_3}, /* dtbo_a              20MB p43 */
    {PART_TRUSTFIRMWARE_A,      591 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware_a      2MB p44 */
    {PART_MODEM_FW_A,           593 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw_a         124MB p45 */
    {PART_MODEM_VENDOR_A,       717 * 1024,    30 * 1024, UFS_PART_3}, /* modem_vendor_a      30MB p46 */
    {PART_MODEM_PATCH_NV_A,     747 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv_a     4MB p47 */
    {PART_MODEM_DRIVER_A,       751 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver_a      20MB p48 */
    {PART_MODEMNVM_UPDATE_A,    771 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update_a   16MB p49 */
    {PART_MODEMNVM_CUST_A,      787 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust_a     16MB p50 */
    {PART_RAMDISK_A,            803 * 1024,     4 * 1024, UFS_PART_3}, /* ramdisk_a            4MB p51 */
    {PART_RVT_SYSTEM_A,         807 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system_a      1024KB p52 */
    {PART_RVT_VENDOR_A,         808 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor_a      1024KB p53 */
    {PART_RVT_CHIP_PROD_A,      809 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod_a   1024KB p54 */
    {PART_RVT_CUST_A,           810 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust_a        1024KB p55 */
    {PART_RVT_SYS_PROD_A,       811 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod_a    1024KB p56 */
    {PART_UPDATER_RVT_A,        812 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt_a        2MB p57 */
    {PART_UPDATER_BAK_RVT_A,    814 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt_a    2MB p58 */
    {PART_RVT_A,                816 * 1024,     4 * 1024, UFS_PART_3}, /* rvt_a                4MB p59 */
    {PART_KPATCH_A,             820 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch_a             4MB p60 */
    {PART_PATCH_A,              824 * 1024,    32 * 1024, UFS_PART_3}, /* patch_a             32MB p61 */
    {PART_RESERVED_lu3,         856 * 1024,   165 * 1024, UFS_PART_3}, /* reserved_lu3       166MB p62 */
    {PART_RVT_VERSION_A,        1021 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_version_a     1024KB p64 */
    {PART_RVT_PRELOAD_A,        1022 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_preload_a     1024KB p65 */
    {PART_RVT_AI_MODEL_A,       1023 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_ai_model_a   1024KB p66 */
#else
    {PART_UPDATER_RAMDISK_A,    125 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_a   32MB p30 */
    {PART_UPDATER_VENDOR_A,     157 * 1024,    28 * 1024, UFS_PART_3}, /* updater_vendor_a    28MB p31 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_BOOT_A,               185 * 1024,    46 * 1024, UFS_PART_3}, /* boot_a              46MB p32 */
    {PART_UPDATER_BOOT_A,       231 * 1024,    64 * 1024, UFS_PART_3}, /* updater_boot_a      64MB p33 */
    {PART_UPDATER_BOOT_BAK_A,   295 * 1024,    64 * 1024, UFS_PART_3}, /* updater_boot_bak_a  64MB p34 */
    {PART_EXT_RVT_A,            359 * 1024,     2 * 1024, UFS_PART_3}, /* ext_rvt_a            2MB p35 */
    {PART_RESERVED1_lu3,        361 * 1024,    68 * 1024, UFS_PART_3}, /* reserved1_lu3       68MB p36 */
#else
    {PART_BOOT_A,               185 * 1024,    46 * 1024, UFS_PART_3}, /* boot_a              46MB p32 */
    {PART_UPDATER_BOOT_A,       231 * 1024,    66 * 1024, UFS_PART_3}, /* updater_boot_a      66MB p33 */
    {PART_UPDATER_BOOT_BAK_A,   297 * 1024,    66 * 1024, UFS_PART_3}, /* updater_boot_bak_a  66MB p34 */
    {PART_EXT_RVT_A,            363 * 1024,     2 * 1024, UFS_PART_3}, /* ext_rvt_a            2MB p35 */
    {PART_RESERVED1_lu3,        365 * 1024,    64 * 1024, UFS_PART_3}, /* reserved1_lu3       64MB p36 */
#endif
    {PART_THEE_A,               429 * 1024,     4 * 1024, UFS_PART_3}, /* thee_a               4MB p37 */
    {PART_TZSP_A,               433 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp_a              12MB p38 */
    {PART_UPDATER_RAMDISK_BAK_A,   445 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak_a  32MB p39 */
    {PART_UPDATER_VENDOR_BAK_A,   477 * 1024,    28 * 1024, UFS_PART_3}, /* updater_vendor_bak_a  28MB p40 */
    {PART_ENG_SYSTEM_A,         505 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system_a        12MB p41 */
    {PART_ENG_CHIPSET_A,        517 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset_a       20MB p42 */
    {PART_FW_DTB_A,             537 * 1024,    20 * 1024, UFS_PART_3}, /* fw_dtb_a            20MB p43 */
    {PART_DTBO_A,               557 * 1024,    20 * 1024, UFS_PART_3}, /* dtbo_a              20MB p44 */
    {PART_TRUSTFIRMWARE_A,      577 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware_a      2MB p45 */
    {PART_MODEM_FW_A,           579 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw_a         124MB p46 */
    {PART_MODEM_VENDOR_A,       703 * 1024,    10 * 1024, UFS_PART_3}, /* modem_vendor_a      10MB p47 */
    {PART_MODEM_PATCH_NV_A,     713 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv_a     4MB p48 */
    {PART_MODEM_DRIVER_A,       717 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver_a      20MB p49 */
    {PART_MODEMNVM_UPDATE_A,    737 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update_a   16MB p50 */
    {PART_MODEMNVM_CUST_A,      753 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust_a     16MB p51 */
    {PART_RAMDISK_A,            769 * 1024,     4 * 1024, UFS_PART_3}, /* ramdisk_a            4MB p52 */
    {PART_RVT_SYSTEM_A,         773 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system_a      1024KB p53 */
    {PART_RVT_VENDOR_A,         774 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor_a      1024KB p54 */
    {PART_RVT_CHIP_PROD_A,      775 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod_a   1024KB p55 */
    {PART_RVT_CUST_A,           776 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust_a        1024KB p56 */
    {PART_RVT_SYS_PROD_A,       777 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod_a    1024KB p57 */
    {PART_UPDATER_RVT_A,        778 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt_a        2MB p58 */
    {PART_UPDATER_BAK_RVT_A,    780 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt_a    2MB p59 */
    {PART_RVT_A,                782 * 1024,     4 * 1024, UFS_PART_3}, /* rvt_a                4MB p60 */
    {PART_KPATCH_A,             786 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch_a             4MB p61 */
    {PART_PATCH_A,              790 * 1024,   128 * 1024, UFS_PART_3}, /* patch_a            128MB p62 */
    {PART_RESERVED_lu3,         918 * 1024,   103 * 1024, UFS_PART_3}, /* reserved_lu3       104MB p63 */
    {PART_RVT_VERSION_A,        1021 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_version_a     1024KB p64 */
    {PART_RVT_PRELOAD_A,        1022 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_preload_a     1024KB p65 */
    {PART_RVT_AI_MODEL_A,       1023 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_ai_model_a   1024KB p66 */
#endif
    {PART_PTABLE_LU4,                              0,          512, UFS_PART_4}, /* ptable_lu4          512KB p0 */
    {PART_LOWPOWER_PARA_B,             512,     1 * 1024, UFS_PART_4}, /* lowpower_para_b   1024KB p1 */
    {PART_BL2_B,             (1 * 1024 + 512),     4 * 1024, UFS_PART_4}, /* bl2_b                4MB p2 */
    {PART_FW_LPM3_B,         (5 * 1024 + 512),          512, UFS_PART_4}, /* fw_lpm3_b          512KB p3 */
    {PART_SEPLAT_B,               6 * 1024,     4 * 1024, UFS_PART_4}, /* seplat_b             4MB p4 */
    {PART_FW_CPU_LPCTRL_B,       10 * 1024,          256, UFS_PART_4}, /* fw_cpu_lpctrl_b    256KB p5 */
    {PART_FW_GPU_LPCTRL_B,   (10 * 1024 + 256),          128, UFS_PART_4}, /* fw_gpu_lpctrl_b    128KB p6 */
    {PART_FW_DDR_LPCTRL_B,   (10 * 1024 + 384),          256, UFS_PART_4}, /* fw_ddr_lpctrl_b    256KB p7 */
    {PART_DDR_XPU_BOOT0_B,   (10 * 1024 + 640),          256, UFS_PART_4}, /* ddr_xpu_boot0_b    256KB p8 */
    {PART_DDR_XPU_BOOT1_B,   (10 * 1024 + 896),          256, UFS_PART_4}, /* ddr_xpu_boot1_b    256KB p9 */
    {PART_DDR_XPU_BOOT2_B,   (11 * 1024 + 128),          256, UFS_PART_4}, /* ddr_xpu_boot2_b    256KB p10 */
    {PART_UCE_B,             (11 * 1024 + 384),          160, UFS_PART_4}, /* uce_b              160KB p11 */
    {PART_RESERVED4,         (11 * 1024 + 544), 5 * 1024+480, UFS_PART_4}, /* reserved4         5600KB p12 */
    {PART_NPU_B,                 17 * 1024,     8 * 1024, UFS_PART_4}, /* npu_b                8MB p13 */
    {PART_IVP_B,                 25 * 1024,     2 * 1024, UFS_PART_4}, /* ivp_b                2MB p14 */
    {PART_DACC_B,                27 * 1024,          512, UFS_PART_4}, /* dacc_b             512KB p15 */
    {PART_VENC_B,            (27 * 1024 + 512),          512, UFS_PART_4}, /* venc_b             512KB p16 */
    {PART_HISEE_IMG_B,           28 * 1024,     4 * 1024, UFS_PART_4}, /* hisee_img_b          4MB p17 */
    {PART_HHEE_B,                32 * 1024,     4 * 1024, UFS_PART_4}, /* hhee_b               4MB p18 */
    {PART_FASTBOOT_B,            36 * 1024,    12 * 1024, UFS_PART_4}, /* fastboot_b          12MB p19 */
    {PART_VECTOR_B,              48 * 1024,     4 * 1024, UFS_PART_4}, /* vector_b             4MB p20 */
    {PART_ISP_BOOT_B,            52 * 1024,     2 * 1024, UFS_PART_4}, /* isp_boot_b           2MB p21 */
    {PART_ISP_FIRMWARE_B,        54 * 1024,    14 * 1024, UFS_PART_4}, /* isp_firmware_b      14MB p22 */
    {PART_FW_HIFI_B,             68 * 1024,    12 * 1024, UFS_PART_4}, /* fw_hifi_b           12MB p23 */
    {PART_TEEOS_B,               80 * 1024,     8 * 1024, UFS_PART_4}, /* teeos_b              8MB p24 */
    {PART_SENSORHUB_B,           88 * 1024,    13 * 1024, UFS_PART_4}, /* sensorhub_b         13MB p25 */
    {PART_SENSORHUB_LOG_DIC_B,   101 * 1024,     3 * 1024, UFS_PART_4}, /* sensorhub_log_dic_b   3MB p26 */
    {PART_HKRR_B,               104 * 1024,    16 * 1024, UFS_PART_4}, /* hkrr_b              16MB p27 */
    {PART_FW_UFSDEV_B,          120 * 1024,     4 * 1024, UFS_PART_4}, /* fw_ufsdev_b          4MB p28 */
    {PART_FW_DFA_B,             124 * 1024,     1 * 1024, UFS_PART_4}, /* fw_dfa_b          1024KB p29 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_UPDATER_RAMDISK_B,    125 * 1024,    64 * 1024, UFS_PART_4}, /* updater_ramdisk_b   64MB p30 */
    {PART_UPDATER_VENDOR_B,     189 * 1024,    35 * 1024, UFS_PART_4}, /* updater_vendor_b    35MB p31 */
    {PART_BOOT_B,               224 * 1024,    46 * 1024, UFS_PART_4}, /* boot_b              46MB p32 */
    {PART_UPDATER_BOOT_B,       270 * 1024,    66 * 1024, UFS_PART_4}, /* updater_boot_b      66MB p33 */
    {PART_UPDATER_BOOT_BAK_B,   336 * 1024,    66 * 1024, UFS_PART_4}, /* updater_boot_bak_b  66MB p34 */
    {PART_EXT_RVT_B,            402 * 1024,     2 * 1024, UFS_PART_4}, /* ext_rvt_b            2MB p35 */
    {PART_THEE_B,               404 * 1024,     4 * 1024, UFS_PART_4}, /* thee_b               4MB p36 */
    {PART_TZSP_B,               408 * 1024,    12 * 1024, UFS_PART_4}, /* tzsp_b              12MB p37 */
    {PART_UPDATER_RAMDISK_BAK_B,   420 * 1024,    64 * 1024, UFS_PART_4}, /* updater_ramdisk_bak_b  64MB p38 */
    {PART_UPDATER_VENDOR_BAK_B,   484 * 1024,    35 * 1024, UFS_PART_4}, /* updater_vendor_bak_b  35MB p39 */
    {PART_ENG_SYSTEM_B,         519 * 1024,    12 * 1024, UFS_PART_4}, /* eng_system_b        12MB p40 */
    {PART_ENG_CHIPSET_B,        531 * 1024,    20 * 1024, UFS_PART_4}, /* eng_chipset_b       20MB p41 */
    {PART_FW_DTB_B,             551 * 1024,    20 * 1024, UFS_PART_4}, /* fw_dtb_b            20MB p42 */
    {PART_DTBO_B,               571 * 1024,    20 * 1024, UFS_PART_4}, /* dtbo_b              20MB p43 */
    {PART_TRUSTFIRMWARE_B,      591 * 1024,     2 * 1024, UFS_PART_4}, /* trustfirmware_b      2MB p44 */
    {PART_MODEM_FW_B,           593 * 1024,   124 * 1024, UFS_PART_4}, /* modem_fw_b         124MB p45 */
    {PART_MODEM_VENDOR_B,       717 * 1024,    30 * 1024, UFS_PART_4}, /* modem_vendor_b      30MB p46 */
    {PART_MODEM_PATCH_NV_B,     747 * 1024,     4 * 1024, UFS_PART_4}, /* modem_patch_nv_b     4MB p47 */
    {PART_MODEM_DRIVER_B,       751 * 1024,    20 * 1024, UFS_PART_4}, /* modem_driver_b      20MB p48 */
    {PART_MODEMNVM_UPDATE_B,    771 * 1024,    16 * 1024, UFS_PART_4}, /* modemnvm_update_b   16MB p49 */
    {PART_MODEMNVM_CUST_B,      787 * 1024,    16 * 1024, UFS_PART_4}, /* modemnvm_cust_b     16MB p50 */
    {PART_RAMDISK_B,            803 * 1024,     4 * 1024, UFS_PART_4}, /* ramdisk_b            4MB p51 */
    {PART_RVT_SYSTEM_B,         807 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_system_b      1024KB p52 */
    {PART_RVT_VENDOR_B,         808 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_vendor_b      1024KB p53 */
    {PART_RVT_CHIP_PROD_B,      809 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_chip_prod_b   1024KB p54 */
    {PART_RVT_CUST_B,           810 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_cust_b        1024KB p55 */
    {PART_RVT_SYS_PROD_B,       811 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_sys_prod_b    1024KB p56 */
    {PART_UPDATER_RVT_B,        812 * 1024,     2 * 1024, UFS_PART_4}, /* updater_rvt_b        2MB p57 */
    {PART_UPDATER_BAK_RVT_B,    814 * 1024,     2 * 1024, UFS_PART_4}, /* updater_bak_rvt_b    2MB p58 */
    {PART_RVT_B,                816 * 1024,     4 * 1024, UFS_PART_4}, /* rvt_b                4MB p59 */
    {PART_KPATCH_B,             820 * 1024,     4 * 1024, UFS_PART_4}, /* kpatch_b             4MB p60 */
    {PART_PATCH_B,              824 * 1024,    32 * 1024, UFS_PART_4}, /* patch_b             32MB p61 */
    {PART_RESERVED_lu4,         856 * 1024,   165 * 1024, UFS_PART_4}, /* reserved_lu4       166MB p62 */
    {PART_RVT_VERSION_B,        1021 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_version_b     1024KB p64 */
    {PART_RVT_PRELOAD_B,        1022 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_preload_b     1024KB p65 */
    {PART_RVT_AI_MODEL_B,       1023 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_ai_model_b   1024KB p66 */
#else
    {PART_UPDATER_RAMDISK_B,    125 * 1024,    32 * 1024, UFS_PART_4}, /* updater_ramdisk_b   32MB p30 */
    {PART_UPDATER_VENDOR_B,     157 * 1024,    28 * 1024, UFS_PART_4}, /* updater_vendor_b    28MB p31 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_BOOT_B,               185 * 1024,    46 * 1024, UFS_PART_4}, /* boot_b              46MB p32 */
    {PART_UPDATER_BOOT_B,       231 * 1024,    64 * 1024, UFS_PART_4}, /* updater_boot_b      64MB p33 */
    {PART_UPDATER_BOOT_BAK_B,   295 * 1024,    64 * 1024, UFS_PART_4}, /* updater_boot_bak_b  64MB p34 */
    {PART_EXT_RVT_B,            359 * 1024,     2 * 1024, UFS_PART_4}, /* ext_rvt_b            2MB p35 */
    {PART_RESERVED1_lu4,        361 * 1024,    68 * 1024, UFS_PART_4}, /* reserved1_lu4       68MB p36 */
#else
    {PART_BOOT_B,               185 * 1024,    46 * 1024, UFS_PART_4}, /* boot_b              46MB p32 */
    {PART_UPDATER_BOOT_B,       231 * 1024,    66 * 1024, UFS_PART_4}, /* updater_boot_b      66MB p33 */
    {PART_UPDATER_BOOT_BAK_B,   297 * 1024,    66 * 1024, UFS_PART_4}, /* updater_boot_bak_b  66MB p34 */
    {PART_EXT_RVT_B,            363 * 1024,     2 * 1024, UFS_PART_4}, /* ext_rvt_b            2MB p35 */
    {PART_RESERVED1_lu4,        365 * 1024,    64 * 1024, UFS_PART_4}, /* reserved1_lu4       64MB p36 */
#endif
    {PART_THEE_B,               429 * 1024,     4 * 1024, UFS_PART_4}, /* thee_b               4MB p37 */
    {PART_TZSP_B,               433 * 1024,    12 * 1024, UFS_PART_4}, /* tzsp_b              12MB p38 */
    {PART_UPDATER_RAMDISK_BAK_B,   445 * 1024,    32 * 1024, UFS_PART_4}, /* updater_ramdisk_bak_b  32MB p39 */
    {PART_UPDATER_VENDOR_BAK_B,   477 * 1024,    28 * 1024, UFS_PART_4}, /* updater_vendor_bak_b  28MB p40 */
    {PART_ENG_SYSTEM_B,         505 * 1024,    12 * 1024, UFS_PART_4}, /* eng_system_b        12MB p41 */
    {PART_ENG_CHIPSET_B,        517 * 1024,    20 * 1024, UFS_PART_4}, /* eng_chipset_b       20MB p42 */
    {PART_FW_DTB_B,             537 * 1024,    20 * 1024, UFS_PART_4}, /* fw_dtb_b            20MB p43 */
    {PART_DTBO_B,               557 * 1024,    20 * 1024, UFS_PART_4}, /* dtbo_b              20MB p44 */
    {PART_TRUSTFIRMWARE_B,      577 * 1024,     2 * 1024, UFS_PART_4}, /* trustfirmware_b      2MB p45 */
    {PART_MODEM_FW_B,           579 * 1024,   124 * 1024, UFS_PART_4}, /* modem_fw_b         124MB p46 */
    {PART_MODEM_VENDOR_B,       703 * 1024,    10 * 1024, UFS_PART_4}, /* modem_vendor_b      10MB p47 */
    {PART_MODEM_PATCH_NV_B,     713 * 1024,     4 * 1024, UFS_PART_4}, /* modem_patch_nv_b     4MB p48 */
    {PART_MODEM_DRIVER_B,       717 * 1024,    20 * 1024, UFS_PART_4}, /* modem_driver_b      20MB p49 */
    {PART_MODEMNVM_UPDATE_B,    737 * 1024,    16 * 1024, UFS_PART_4}, /* modemnvm_update_b   16MB p50 */
    {PART_MODEMNVM_CUST_B,      753 * 1024,    16 * 1024, UFS_PART_4}, /* modemnvm_cust_b     16MB p51 */
    {PART_RAMDISK_B,            769 * 1024,     4 * 1024, UFS_PART_4}, /* ramdisk_b            4MB p52 */
    {PART_RVT_SYSTEM_B,         773 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_system_b      1024KB p53 */
    {PART_RVT_VENDOR_B,         774 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_vendor_b      1024KB p54 */
    {PART_RVT_CHIP_PROD_B,      775 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_chip_prod_b   1024KB p55 */
    {PART_RVT_CUST_B,           776 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_cust_b        1024KB p56 */
    {PART_RVT_SYS_PROD_B,       777 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_sys_prod_b    1024KB p57 */
    {PART_UPDATER_RVT_B,        778 * 1024,     2 * 1024, UFS_PART_4}, /* updater_rvt_b        2MB p58 */
    {PART_UPDATER_BAK_RVT_B,    780 * 1024,     2 * 1024, UFS_PART_4}, /* updater_bak_rvt_b    2MB p59 */
    {PART_RVT_B,                782 * 1024,     4 * 1024, UFS_PART_4}, /* rvt_b                4MB p60 */
    {PART_KPATCH_B,             786 * 1024,     4 * 1024, UFS_PART_4}, /* kpatch_b             4MB p61 */
    {PART_PATCH_B,              790 * 1024,   128 * 1024, UFS_PART_4}, /* patch_b            128MB p62 */
    {PART_RESERVED_lu4,         918 * 1024,   103 * 1024, UFS_PART_4}, /* reserved_lu4       104MB p63 */
    {PART_RVT_VERSION_B,        1021 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_version_b     1024KB p64 */
    {PART_RVT_PRELOAD_B,        1022 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_preload_b     1024KB p65 */
    {PART_RVT_AI_MODEL_B,       1023 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_ai_model_b   1024KB p66 */
#endif
    {PART_PTABLE_LU5,             0,             512,     UFS_PART_5}, /* ptable_lu5          512KB p0 */
    {PART_BOOT_CTRL,                   512,     1 * 1024, UFS_PART_5}, /* boot_ctrl         1024KB p1 */
    {PART_VRL,               (1 * 1024 + 512),          512, UFS_PART_5}, /* vrl                512KB p2 */
    {PART_VRL_BACKUP,             2 * 1024,          512, UFS_PART_5}, /* vrl_backup         512KB p3 */
    {PART_MODEM_SECURE,      (2 * 1024 + 512),         8704, UFS_PART_5}, /* modem_secure      8704KB p4 */
    {PART_NVME,                  11 * 1024,     4 * 1024, UFS_PART_5}, /* nvme                 4MB p5 */
    {PART_CONN_CALIDATA,         15 * 1024,         1024, UFS_PART_5}, /* conn_calidata     1024KB p6 */
    {PART_CTF,                   16 * 1024,     1 * 1024, UFS_PART_5}, /* ctf               1024KB p7 */
    {PART_OEMINFO,               17 * 1024,    96 * 1024, UFS_PART_5}, /* oeminfo             96MB p8 */
    {PART_SECURE_STORAGE,       113 * 1024,    32 * 1024, UFS_PART_5}, /* secure_storage      32MB p9 */
    {PART_MODEMNVM_FACTORY,     145 * 1024,    16 * 1024, UFS_PART_5}, /* modemnvm_factory    16MB p10 */
    {PART_MODEMNVM_BACKUP,      161 * 1024,    16 * 1024, UFS_PART_5}, /* modemnvm_backup     16MB p11 */
    {PART_MODEMNVM_IMG,         177 * 1024,    46 * 1024, UFS_PART_5}, /* modemnvm_img        46MB p12 */
    {PART_HISEE_ENCOS,          223 * 1024,     4 * 1024, UFS_PART_5}, /* hisee_encos          4MB p13 */
    {PART_VERITYKEY,            227 * 1024,     1 * 1024, UFS_PART_5}, /* veritykey         1024KB p14 */
    {PART_DDR_PARA,             228 * 1024,     1 * 1024, UFS_PART_5}, /* ddr_para          1024KB p15 */
    {PART_BATT_TP_PARA,         229 * 1024,     1 * 1024, UFS_PART_5}, /* batt_tp_para      1024KB p16 */
    {PART_PANEL_CALIBRATION,    230 * 1024,   100 * 1024, UFS_PART_5}, /* panel_calibration  100MB p17 */
    {PART_RESERVED2,            330 * 1024,    21 * 1024, UFS_PART_5}, /* reserved2           21MB p18 */
    {PART_LOG,                  351 * 1024,    80 * 1024, UFS_PART_5}, /* log                 80MB p19 */
    {PART_BOOTFAIL_INFO,        431 * 1024,     2 * 1024, UFS_PART_5}, /* bootfail_info        2MB p20 */
    {PART_MISC,                 433 * 1024,     2 * 1024, UFS_PART_5}, /* misc                 2MB p21 */
    {PART_DFX,                  435 * 1024,    16 * 1024, UFS_PART_5}, /* dfx                 16MB p22 */
    {PART_RRECORD,              451 * 1024,    16 * 1024, UFS_PART_5}, /* rrecord             16MB p23 */
    {PART_CACHE,                467 * 1024,   104 * 1024, UFS_PART_5}, /* cache              104MB p24 */
    {PART_METADATA,             571 * 1024,    16 * 1024, UFS_PART_5}, /* metadata            16MB p25 */
    {PART_TOC,                  587 * 1024,     1 * 1024, UFS_PART_5}, /* toc               1024KB p26 */
    {PART_HISEE_FS,             588 * 1024,     8 * 1024, UFS_PART_5}, /* hisee_fs             8MB p27 */
    {PART_RESERVED,             596 * 1024,    14 * 1024, UFS_PART_5}, /* reserved            14MB p28 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_CUST,                 610 * 1024,    88 * 1024, UFS_PART_5}, /* cust                88MB p29 */
    {PART_CHIP_PROD,            698 * 1024,  3018 * 1024, UFS_PART_5}, /* chip_prod         3018MB p30 */
    {PART_VENDOR,              3716 * 1024,  3284 * 1024, UFS_PART_5}, /* vendor            3284MB p31 */
    {PART_SYS_PROD,            7000 * 1024,  8812 * 1024, UFS_PART_5}, /* sys_prod          8812MB p32 */
    {PART_SYSTEM,             15812 * 1024,  7968 * 1024, UFS_PART_5}, /* system            7968MB p33 */
    {PART_HYPERHOLD,          23780 * 1024,     4 * 1024, UFS_PART_5}, /* hyperhold            4MB p34 */
    {PART_VERSION,            23784 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p35 */
    {PART_PRELOAD,            24360 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p36 */
    {PART_RESERVED1_lu5,      25760 * 1024,   168 * 1024, UFS_PART_5}, /* reserved1_lu5      168MB p37 */
    {PART_USERDATA,           25928 * 1024,(14UL) * 1024 * 1024, UFS_PART_5}, /* userdata       4G p38 */
#elif defined(CONFIG_FACTORY_MODE)
    {PART_RESERVED5,            610 * 1024,(134 * 1024+512), UFS_PART_5}, /* reserved5         137728KB p29 */
    {PART_MODULE_UPDATE,     (744 * 1024 + 512),          512, UFS_PART_5}, /* module_update      512KB p30 */
    {PART_HIBENCH_IMG,          745 * 1024,   128 * 1024, UFS_PART_5}, /* hibench_img        128MB p31 */
    {PART_HIBENCH_LOG,          873 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p32 */
    {PART_HIBENCH_DATA,         905 * 1024,  1000 * 1024, UFS_PART_5}, /* hibench_data      1000MB p33 */
    {PART_FLASH_AGEING,        1905 * 1024,   512 * 1024, UFS_PART_5}, /* flash_ageing       512MB p34 */
    {PART_HIBENCH_LPM3,        2417 * 1024,     2 * 1024, UFS_PART_5}, /* hibench_lpm3         2MB p35 */
    {PART_XLOADER_HITEST,      2419 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p36 */
    {PART_CUST,                2421 * 1024,   128 * 1024, UFS_PART_5}, /* cust               128MB p37 */
    {PART_CHIP_PROD,           2549 * 1024,  3018 * 1024, UFS_PART_5}, /* chip_prod         3018MB p38 */
    {PART_VENDOR,              5567 * 1024,  1132 * 1024, UFS_PART_5}, /* vendor            1132MB p39 */
    {PART_SYS_PROD,            6699 * 1024,  8812 * 1024, UFS_PART_5}, /* sys_prod          8812MB p40 */
    {PART_SYSTEM,             15511 * 1024,  4948 * 1024, UFS_PART_5}, /* system            4948MB p41 */
    {PART_HYPERHOLD,          20459 * 1024,     4 * 1024, UFS_PART_5}, /* hyperhold            4MB p42 */
    {PART_RESERVED6,          20463 * 1024, 29505 * 1024, UFS_PART_5}, /* reserved6         29505MB p43 */
    {PART_USERDATA,           49968 * 1024,(16UL) * 1024 * 1024, UFS_PART_5}, /* userdata       6G p44 */
    {PART_VERSION,              66352 * 1024, 40960 * 1024, UFS_PART_5},/* version           40960MB p29 */
    {PART_PRELOAD,            107312 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p30 */
#else
    {PART_HYPERHOLD,            610 * 1024,     4 * 1024, UFS_PART_5}, /* hyperhold            4MB p29 */
    {PART_CUST,                 614 * 1024,   128 * 1024, UFS_PART_5}, /* cust               128MB p30 */
    {PART_CHIP_PROD,            742 * 1024,  3018 * 1024, UFS_PART_5}, /* chip_prod         3018MB p31 */
    {PART_VENDOR,              3760 * 1024,  1132 * 1024, UFS_PART_5}, /* vendor            1132MB p32 */
    {PART_SYS_PROD,            4892 * 1024,  8812 * 1024, UFS_PART_5}, /* sys_prod          8812MB p33 */
    {PART_SYSTEM,             13704 * 1024,  4948 * 1024, UFS_PART_5}, /* system            4948MB p34 */
    {PART_RESERVED1_lu5,      18652 * 1024,   168 * 1024, UFS_PART_5}, /* reserved1_lu5      168MB p35 */
#if defined(CONFIG_PARTITION_ENG)
    {PART_HYPERHOLD,          18820 * 1024,     4 * 1024, UFS_PART_5}, /* hyperhold            4MB p36 */
    {PART_RESERVED5,          18824 * 1024,   137 * 1024, UFS_PART_5}, /* reserved5          137MB p37 */
    {PART_VERSION,            18961 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p38 */
    {PART_PRELOAD,            19537 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p39 */
    {PART_FTTEST,             20937 * 1024,   192 * 1024, UFS_PART_5}, /* fttest             192MB p40 */
    {PART_DDRTEST,            21129 * 1024,    48 * 1024, UFS_PART_5}, /* ddrtest             48MB p41 */
    {PART_HITEST_GPU,         21177 * 1024,   512 * 1024, UFS_PART_5}, /* hitest_gpu         512MB p42 */
    {PART_HITEST_ASP_DHRYSTONE, 21689 * 1024,    20 * 1024, UFS_PART_5}, /* hitest_asp_dhrystone  20MB p43 */
    {PART_HITEST_ASP_TEST,    21709 * 1024,   300 * 1024, UFS_PART_5}, /* hitest_asp_test    300MB p44 */
    {PART_HITEST_SENSORHUB,   22009 * 1024,     6 * 1024, UFS_PART_5}, /* hitest_sensorhub     6MB p45 */
    {PART_HITEST_ISP,         22015 * 1024,    25 * 1024, UFS_PART_5}, /* hitest_isp          25MB p46 */
    {PART_HITEST_ISP_AVS,     22040 * 1024,    65 * 1024, UFS_PART_5}, /* hitest_isp_avs      65MB p47 */
    {PART_HITEST_NPU,         22105 * 1024,    80 * 1024, UFS_PART_5}, /* hitest_npu          80MB p48 */
    {PART_HITEST_DSS,         22185 * 1024,    18 * 1024, UFS_PART_5}, /* hitest_dss          18MB p49 */
    {PART_DSS_DISP_BUF,       22203 * 1024,   128 * 1024, UFS_PART_5}, /* dss_disp_buf       128MB p50 */
    {PART_HITEST_JPEGENC,     22331 * 1024,   200 * 1024, UFS_PART_5}, /* hitest_jpegenc     200MB p51 */
    {PART_HITEST_HIPP,        22531 * 1024,   100 * 1024, UFS_PART_5}, /* hitest_hipp        100MB p52 */
    {PART_HIBENCH_LPM3,       22631 * 1024,     2 * 1024, UFS_PART_5}, /* hibench_lpm3         2MB p53 */
    {PART_JPEG_DEC_TEST_SRC,  22633 * 1024,    20 * 1024, UFS_PART_5}, /* jpeg_dec_test_src   20MB p54 */
    {PART_JPEG_DEC_TEST_DEST, 22653 * 1024,    80 * 1024, UFS_PART_5}, /* jpeg_dec_test_dest  80MB p55 */
    {PART_VCODE_DATA,         22733 * 1024,   140 * 1024, UFS_PART_5}, /* vcode_data         140MB p56 */
    {PART_HITEST_FFRT,        22873 * 1024,    20 * 1024, UFS_PART_5}, /* hitest_ffrt         20MB p57 */
    {PART_VCODE_MAX_DATA,     22893 * 1024,   140 * 1024, UFS_PART_5}, /* vcode_max_data     140MB p58 */
    {PART_MODEM_TSP_TEST,     23033 * 1024,    36 * 1024, UFS_PART_5}, /* modem_tsp_test      36MB p59 */
    {PART_MODEM_VECTOR_CONFIG, 23069 * 1024,     4 * 1024, UFS_PART_5}, /* modem_vector_config   4MB p60 */
    {PART_MODEM_TSP_DT,       23073 * 1024,     1 * 1024, UFS_PART_5}, /* modem_tsp_dt      1024KB p61 */
    {PART_MODEM_L2DLE,        23074 * 1024,     4 * 1024, UFS_PART_5}, /* modem_l2dle          4MB p62 */
    {PART_MODEM_BBP_TEST,     23078 * 1024,   100 * 1024, UFS_PART_5}, /* modem_bbp_test     100MB p63 */
    {PART_MODEM_PSA_TEST,     23178 * 1024,    20 * 1024, UFS_PART_5}, /* modem_psa_test      20MB p64 */
    {PART_MODEM_PDE_TEST,     23198 * 1024,     5 * 1024, UFS_PART_5}, /* modem_pde_test       5MB p65 */
    {PART_XLOADER_HITEST,     23203 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p66 */
    {PART_HITEST_OISP,        23205 * 1024,    25 * 1024, UFS_PART_5}, /* hitest_oisp         25MB p67 */
    {PART_RESERVED8,          23230 * 1024,     2 * 1024, UFS_PART_5}, /* reserved8            2MB p68 */
    {PART_USERDATA,           23232 * 1024,(16UL) * 1024 * 1024, UFS_PART_5}, /* userdata       6G p69 */
#else // system in ccm is 5716,but now less 768
    {PART_AI_MODEL,           18820 * 1024,     2 * 1024, UFS_PART_5}, /* ai_model             2MB p36 */
    {PART_HYPERHOLD,          18822 * 1024,     2 * 1024, UFS_PART_5}, /* hyperhold            2MB p37 */
    {PART_RESERVED5,          18824 * 1024,(134 * 1024+512), UFS_PART_5}, /* reserved5         137728KB p38 */
    {PART_MODULE_UPDATE,     (18958 * 1024 + 512),          512, UFS_PART_5}, /* module_update      512KB p39 */
    {PART_EXT_RVT,            18959 * 1024,     2 * 1024, UFS_PART_5}, /* ext_rvt              2MB p40 */
    {PART_VERSION,            18961 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p41 */
    {PART_PRELOAD,            19537 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p42 */
    {PART_RESERVED9,          20937 * 1024,  1815 * 1024, UFS_PART_5}, /* reserved9         1815MB p43 */
    {PART_USERDATA,           22752 * 1024,(16UL) * 1024 * 1024, UFS_PART_5}, /* userdata       6G p44 */
#endif
#endif
    {"0", 0, 0, 0},
};
#endif