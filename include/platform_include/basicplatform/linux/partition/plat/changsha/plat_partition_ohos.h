#ifndef _CHANGSHA_PLAT_PARTITION_OHOS_H_
#define _CHANGSHA_PLAT_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER_A,              0,              4 * 1024,    UFS_PART_0},
    {PART_XLOADER_B,              0,              4 * 1024,    UFS_PART_1},
    {PART_PTABLE,                 0,                   512,    UFS_PART_2}, /* ptable           512K    p0 */
    {PART_FRP,                         512,          512, UFS_PART_2}, /* frp                512KB p1 */
    {PART_PERSIST,                    1024,     6 * 1024, UFS_PART_2}, /* persist              6MB p2 */
    {PART_RESERVED1,              7 * 1024,         1024, UFS_PART_2}, /* reserved1         1024KB p3 */
    {PART_PTABLE_LU3,                              0,          512,  UFS_PART_3}, /* ptable_lu3          512KB p0 */
    {PART_LOWPOWER_PARA_A,                       512,     1 * 1024,  UFS_PART_3}, /* lowpower_para_a    1024KB p1 */
    {PART_BL2_A,                          512 + 1024,     4 * 1024,  UFS_PART_3}, /* bl2_a                 4MB p2 */
    {PART_FW_LPM3_A,                512 + (5 * 1024),          512,  UFS_PART_3}, /* fw_lpm3_a           512KB p3 */
    {PART_SEPLAT_A,                         6 * 1024,     4 * 1024,  UFS_PART_3}, /* seplat_a              4MB p4 */
    {PART_FW_CPU_LPCTRL_A,                 10 * 1024,          256,  UFS_PART_3}, /* fw_cpu_lpctrl_a      256K p5 */
    {PART_FW_GPU_LPCTRL_A,         (10 * 1024) + 256,          128,  UFS_PART_3}, /* fw_gpu_lpctrl_a     128K  p6 */
    {PART_FW_DDR_LPCTRL_A,         (10 * 1024) + 384,          320,  UFS_PART_3}, /* fw_ddr_lpctrl_a     320K  p7 */
    {PART_DDR_XPU_BOOT0_A,         (10 * 1024) + 704,          320,  UFS_PART_3}, /* ddr_xpu_boot0_a     320KB p8 */
    {PART_DDR_XPU_BOOT1_A,                 11 * 1024,          320,  UFS_PART_3}, /* ddr_xpu_boot1_a     320KB p9 */
    {PART_DDR_XPU_BOOT2_A,         (11 * 1024) + 320,          320,  UFS_PART_3}, /* ddr_xpu_boot2_a    320KB p10 */
    {PART_UCE_A,                   (11 * 1024) + 640,          160,  UFS_PART_3}, /* uce_a              160KB p11 */
    {PART_FW_MEDIA_LPCTRL_A,       (11 * 1024) + 800,          128,  UFS_PART_3}, /* fw_media_lpctrl_a  128KB p12 */
    {PART_NPU_A,                   (11 * 1024) + 928,     8 * 1024,  UFS_PART_3}, /* npu_a                8MB p13 */
    {PART_IVP_A,                   (19 * 1024) + 928,     2 * 1024,  UFS_PART_3}, /* ivp_a                2MB p14 */
    {PART_DACC_A,                  (21 * 1024) + 928,          256,  UFS_PART_3}, /* dacc_a             256KB p15 */
    {PART_DACC_AAE_A,              (22 * 1024) + 160,          256,  UFS_PART_3}, /* dacc_aae_a         256KB p16 */
    {PART_VENC_A,                  (22 * 1024) + 416,          512,  UFS_PART_3}, /* venc_a             512KB p17 */
    {PART_HISEE_IMG_A,             (22 * 1024) + 928,     4 * 1024,  UFS_PART_3}, /* hisee_img_a          4MB p18 */
    {PART_HHEE_A,                  (26 * 1024) + 928,     4 * 1024,  UFS_PART_3}, /* hhee_a               4MB p19 */
    {PART_FASTBOOT_A,              (30 * 1024) + 928,    12 * 1024,  UFS_PART_3}, /* fastboot_a          12MB p20 */
    {PART_VECTOR_A,                (42 * 1024) + 928,     4 * 1024,  UFS_PART_3}, /* vector_a             4MB p21 */
    {PART_ISP_BOOT_A,              (46 * 1024) + 928,     2 * 1024,  UFS_PART_3}, /* isp_boot_a           2MB p22 */
    {PART_ISP_FIRMWARE_A,          (48 * 1024) + 928,    14 * 1024,  UFS_PART_3}, /* isp_firmware_a      14MB p23 */
    {PART_FW_HIFI_A,               (62 * 1024) + 928,    12 * 1024,  UFS_PART_3}, /* fw_hifi_a           12MB p24 */
    {PART_TEEOS_A,                 (74 * 1024) + 928,     8 * 1024,  UFS_PART_3}, /* teeos_a              8MB p25 */
    {PART_SENSORHUB_A,             (82 * 1024) + 928,    13 * 1024,  UFS_PART_3}, /* sensorhub_a         13MB p26 */
    {PART_SENSORHUB_LOG_DIC_A,     (95 * 1024) + 928,     3 * 1024,  UFS_PART_3}, /* sensorhub_log_dic_a  3MB p27 */
    {PART_HKRR_A,                  (98 * 1024) + 928,    16 * 1024,  UFS_PART_3}, /* hkrr_a              16MB p28 */
    {PART_FW_UFSDEV_A,            (114 * 1024) + 928,     4 * 1024,  UFS_PART_3}, /* fw_ufsdev_a          4MB p29 */
    {PART_FW_DFA_A,               (118 * 1024) + 928,     1 * 1024,  UFS_PART_3}, /* fw_dfa_a          1024KB p30 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_UPDATER_RAMDISK_A,      (119 * 1024) + 928,    64 * 1024,  UFS_PART_3}, /* updater_ramdisk_a   64MB p31 */
    {PART_UPDATER_VENDOR_A,       (183 * 1024) + 928,    33 * 1024,  UFS_PART_3}, /* updater_vendor_a    32MB p32 */
    {PART_BOOT_A,                 (216 * 1024) + 928,    46 * 1024,  UFS_PART_3}, /* boot_a              46MB p33 */
    {PART_UPDATER_BOOT_A,         (262 * 1024) + 928,    70 * 1024,  UFS_PART_3}, /* updater_boot_a      70MB p34 */
    {PART_UPDATER_BOOT_BAK_A,     (332 * 1024) + 928,    70 * 1024,  UFS_PART_3}, /* updater_boot_bak_a  70MB p35 */
    {PART_EXT_RVT_A,              (402 * 1024) + 928,     2 * 1024,  UFS_PART_3}, /* ext_rvt_a           2MB  p36 */
    {PART_THEE_A,                 (404 * 1024) + 928,     4 * 1024,  UFS_PART_3}, /* thee_a              4MB  p37 */
    {PART_TZSP_A,                 (408 * 1024) + 928,    12 * 1024,  UFS_PART_3}, /* tzsp_a             12MB  p38 */
    {PART_UPDATER_RAMDISK_BAK_A,  (420 * 1024) + 928,    64 * 1024,  UFS_PART_3}, /* updater_ramdisk_bak_a 64MB p39 */
    {PART_UPDATER_VENDOR_BAK_A,   (484 * 1024) + 928,    33 * 1024,  UFS_PART_3}, /* updater_vendor_bak_a  32MB p40 */
    {PART_ENG_SYSTEM_A,           (517 * 1024) + 928,    12 * 1024,  UFS_PART_3}, /* eng_system_a          12MB p41 */
    {PART_ENG_CHIPSET_A,          (529 * 1024) + 928,    20 * 1024,  UFS_PART_3}, /* eng_chipset_a         20MB p42 */
    {PART_FW_DTB_A,               (549 * 1024) + 928,    20 * 1024, UFS_PART_3}, /* fw_dtb_a            20MB p43 */
    {PART_DTBO_A,                 (569 * 1024) + 928,    20 * 1024, UFS_PART_3}, /* dtbo_a              20MB p44 */
    {PART_TRUSTFIRMWARE_A,        (589 * 1024) + 928,     2 * 1024, UFS_PART_3}, /* trustfirmware_a      2MB p45 */
    {PART_DPA_VENDOR_A,           (591 * 1024) + 928,    32 * 1024, UFS_PART_3}, /* dpa_vendor_a        32MB p46 */
    {PART_MODEM_FW_A,             (623 * 1024) + 928,   124 * 1024, UFS_PART_3}, /* modem_fw_a         124MB p47 */
    {PART_MODEM_VENDOR_A,         (747 * 1024) + 928,    40 * 1024, UFS_PART_3}, /* modem_vendor_a      30MB p48 */
    {PART_MODEM_PATCH_NV_A,       (787 * 1024) + 928,     4 * 1024, UFS_PART_3}, /* modem_patch_nv_a     4MB p49 */
    {PART_MODEM_DRIVER_A,         (791 * 1024) + 928,    20 * 1024, UFS_PART_3}, /* modem_driver_a      20MB p50 */
    {PART_MODEMNVM_UPDATE_A,      (811 * 1024) + 928,    16 * 1024, UFS_PART_3}, /* modemnvm_update_a   16MB p51 */
    {PART_MODEMCONFIG_CUST_A,     (827 * 1024) + 928,    16 * 1024, UFS_PART_3}, /* modemconfig_cust_a  16MB p52 */
    {PART_RAMDISK_A,              (843 * 1024) + 928,     4 * 1024, UFS_PART_3}, /* ramdisk_a            4MB p53 */
    {PART_RVT_SYSTEM_A,           (847 * 1024) + 928,     1 * 1024, UFS_PART_3}, /* rvt_system_a      1024KB p54 */
    {PART_RVT_VENDOR_A,           (848 * 1024) + 928,     1 * 1024, UFS_PART_3}, /* rvt_vendor_a      1024KB p55 */
    {PART_RVT_CHIP_PROD_A,        (849 * 1024) + 928,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod_a   1024KB p56 */
    {PART_RVT_CUST_A,             (850 * 1024) + 928,     1 * 1024, UFS_PART_3}, /* rvt_cust_a        1024KB p57 */
    {PART_RVT_SYS_PROD_A,         (851 * 1024) + 928,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod_a    1024KB p58 */
    {PART_UPDATER_RVT_A,          (852 * 1024) + 928,     2 * 1024, UFS_PART_3}, /* updater_rvt_a        2MB p59 */
    {PART_UPDATER_BAK_RVT_A,      (854 * 1024) + 928,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt_a    2MB p60 */
    {PART_RVT_A,                  (856 * 1024) + 928,     4 * 1024, UFS_PART_3}, /* rvt_a                4MB p61 */
    {PART_KPATCH_A,               (860 * 1024) + 928,     4 * 1024, UFS_PART_3}, /* kpatch_a             4MB p62 */
    {PART_PATCH_A,                (864 * 1024) + 928,    32 * 1024, UFS_PART_3}, /* patch_a             32MB p63 */
    {PART_RVT_VERSION_A,          (896 * 1024) + 928,     1 * 1024, UFS_PART_3}, /* rvt_version_a     1024KB p64 */
    {PART_RVT_PRELOAD_A,          (897 * 1024) + 928,     1 * 1024, UFS_PART_3}, /* rvt_preload_a     1024KB p65 */
    {PART_RVT_AI_MODEL_A,         (898 * 1024) + 928,     1 * 1024, UFS_PART_3}, /* rvt_ai_model_a   1024KB p66 */
    {PART_RESERVED_lu3,           (899 * 1024) + 928,138 * 1024+96, UFS_PART_3}, /* reserved_lu3      140M p67 */
#else
    {PART_UPDATER_RAMDISK_A,      (119 * 1024) + 928,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_a   32MB p31 */
    {PART_UPDATER_VENDOR_A,       (151 * 1024) + 928,    32 * 1024, UFS_PART_3}, /* updater_vendor_a    32MB p32 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_BOOT_A,                 (183 * 1024) + 928,    46 * 1024, UFS_PART_3}, /* boot_a              46MB p33 */
    {PART_UPDATER_BOOT_A,         (229 * 1024) + 928,    70 * 1024, UFS_PART_3}, /* updater_boot_a      70MB p34 */
    {PART_UPDATER_BOOT_BAK_A,     (299 * 1024) + 928,    70 * 1024, UFS_PART_3}, /* updater_boot_bak_a  70MB p35 */
    {PART_EXT_RVT_A,              (369 * 1024) + 928,     2 * 1024, UFS_PART_3}, /* ext_rvt_a            2MB p36 */
    {PART_RESERVED1_lu3,          (371 * 1024) + 928, 56 * 1024+96, UFS_PART_3}, /* reserved1_lu3     57440KB p37 */
#else
    {PART_BOOT_A,                 (183 * 1024) + 928,    46 * 1024, UFS_PART_3}, /* boot_a              46MB p33 */
    {PART_UPDATER_BOOT_A,         (229 * 1024) + 928,    66 * 1024, UFS_PART_3}, /* updater_boot_a      66MB p34 */
    {PART_UPDATER_BOOT_BAK_A,     (295 * 1024) + 928,    66 * 1024, UFS_PART_3}, /* updater_boot_bak_a  66MB p35 */
    {PART_EXT_RVT_A,              (361 * 1024) + 928,     2 * 1024, UFS_PART_3}, /* ext_rvt_a            2MB p36 */
    {PART_RESERVED1_lu3,          (363 * 1024) + 928, 64 * 1024+96, UFS_PART_3}, /* reserved1_lu3     65632KB p37 */
#endif
    {PART_THEE_A,               428 * 1024,     4 * 1024, UFS_PART_3}, /* thee_a               4MB p38 */
    {PART_TZSP_A,               432 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp_a              12MB p39 */
    {PART_UPDATER_RAMDISK_BAK_A,444 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak_a  32MB p40 */
    {PART_UPDATER_VENDOR_BAK_A, 476 * 1024,    32 * 1024, UFS_PART_3}, /* updater_vendor_bak_a  32MB p41 */
    {PART_ENG_SYSTEM_A,         508 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system_a        12MB p42 */
    {PART_ENG_CHIPSET_A,        520 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset_a       20MB p43 */
    {PART_FW_DTB_A,             540 * 1024,    20 * 1024, UFS_PART_3}, /* fw_dtb_a            20MB p44 */
    {PART_DTBO_A,               560 * 1024,    20 * 1024, UFS_PART_3}, /* dtbo_a              20MB p45 */
    {PART_TRUSTFIRMWARE_A,      580 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware_a      2MB p46 */
    {PART_DPA_VENDOR_A,         582 * 1024,    32 * 1024, UFS_PART_3}, /* dpa_vendor_a        32MB p47 */
    {PART_MODEM_FW_A,           614 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw_a         124MB p48 */
    {PART_MODEM_VENDOR_A,       738 * 1024,    10 * 1024, UFS_PART_3}, /* modem_vendor_a      10MB p49 */
    {PART_MODEM_PATCH_NV_A,     748 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv_a     4MB p50 */
    {PART_MODEM_DRIVER_A,       752 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver_a      20MB p51 */
    {PART_MODEMNVM_UPDATE_A,    772 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update_a   16MB p52 */
    {PART_MODEMCONFIG_CUST_A,   788 * 1024,    16 * 1024, UFS_PART_3}, /* modemconfig_cust_a  16MB p53 */
    {PART_RAMDISK_A,            804 * 1024,     4 * 1024, UFS_PART_3}, /* ramdisk_a            4MB p54 */
    {PART_RVT_SYSTEM_A,         808 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system_a      1024KB p55 */
    {PART_RVT_VENDOR_A,         809 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor_a      1024KB p56 */
    {PART_RVT_CHIP_PROD_A,      810 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod_a   1024KB p57 */
    {PART_RVT_CUST_A,           811 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust_a        1024KB p58 */
    {PART_RVT_SYS_PROD_A,       812 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod_a    1024KB p59 */
    {PART_UPDATER_RVT_A,        813 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt_a        2MB p60 */
    {PART_UPDATER_BAK_RVT_A,    815 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt_a    2MB p61 */
    {PART_RVT_A,                817 * 1024,     4 * 1024, UFS_PART_3}, /* rvt_a                4MB p62 */
    {PART_KPATCH_A,             821 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch_a             4MB p63 */
    {PART_PATCH_A,              825 * 1024,   128 * 1024, UFS_PART_3}, /* patch_a            128MB p64 */
    {PART_RVT_VERSION_A,        953 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_version_a     1024KB p65 */
    {PART_RVT_PRELOAD_A,        954 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_preload_a     1024KB p66 */
    {PART_RVT_AI_MODEL_A,       955 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_ai_model_a    1024KB p67 */
    {PART_RESERVED_lu3,         956 * 1024,    95 * 1024, UFS_PART_3}, /* reserved_lu3        95MB p68 */
#endif
    {PART_PTABLE_LU4,                              0,          512, UFS_PART_4}, /* ptable_lu4          512KB p0 */
    {PART_LOWPOWER_PARA_B,                       512,     1 * 1024, UFS_PART_4}, /* lowpower_para_b    1024KB p1 */
    {PART_BL2_B,                          512 + 1024,     4 * 1024, UFS_PART_4}, /* bl2_b                 4MB p2 */
    {PART_FW_LPM3_B,                512 + (5 * 1024),          512, UFS_PART_4}, /* fw_lpm3_b           512KB p3 */
    {PART_SEPLAT_B,                         6 * 1024,     4 * 1024, UFS_PART_4}, /* seplat_b             4MB p4 */
    {PART_FW_CPU_LPCTRL_B,                 10 * 1024,          256, UFS_PART_4}, /* fw_cpu_lpctrl_b      256K  p5 */
    {PART_FW_GPU_LPCTRL_B,         (10 * 1024) + 256,          128, UFS_PART_4}, /* fw_gpu_lpctrl_b      128K  p6 */
    {PART_FW_DDR_LPCTRL_B,         (10 * 1024) + 384,          320, UFS_PART_4}, /* fw_ddr_lpctrl_b      320K  p7 */
    {PART_DDR_XPU_BOOT0_B,         (10 * 1024) + 704,          320, UFS_PART_4}, /* ddr_xpu_boot0_b      320KB p8 */
    {PART_DDR_XPU_BOOT1_B,                 11 * 1024,          320, UFS_PART_4}, /* ddr_xpu_boot1_b      320KB  p9 */
    {PART_DDR_XPU_BOOT2_B,         (11 * 1024) + 320,          320, UFS_PART_4}, /* ddr_xpu_boot2_b      320KB  p10 */
    {PART_UCE_B,                   (11 * 1024) + 640,          160, UFS_PART_4}, /* uce_b                160KB  p11 */
    {PART_FW_MEDIA_LPCTRL_B,       (11 * 1024) + 800,          128, UFS_PART_4}, /* fw_media_lpctrl_b    128KB  p12 */
    {PART_NPU_B,                   (11 * 1024) + 928,     8 * 1024, UFS_PART_4}, /* npu_b                 8MB  p13 */
    {PART_IVP_B,                   (19 * 1024) + 928,     2 * 1024, UFS_PART_4}, /* ivp_b                2MB p14 */
    {PART_DACC_B,                  (21 * 1024) + 928,          256, UFS_PART_4}, /* dacc_b               256KB p15 */
    {PART_DACC_AAE_B,              (22 * 1024) + 160,          256, UFS_PART_4}, /* dacc_aae_b           256KB p16 */
    {PART_VENC_B,                  (22 * 1024) + 416,          512, UFS_PART_4}, /* venc_b               512KB p17 */
    {PART_HISEE_IMG_B,             (22 * 1024) + 928,     4 * 1024, UFS_PART_4}, /* hisee_img_b            4MB p18 */
    {PART_HHEE_B,                  (26 * 1024) + 928,     4 * 1024, UFS_PART_4}, /* hhee_b                4MB  p19 */
    {PART_FASTBOOT_B,              (30 * 1024) + 928,    12 * 1024, UFS_PART_4}, /* fastboot_b           12MB  p20 */
    {PART_VECTOR_B,                (42 * 1024) + 928,     4 * 1024, UFS_PART_4}, /* vector_b               4MB p21 */
    {PART_ISP_BOOT_B,              (46 * 1024) + 928,     2 * 1024, UFS_PART_4}, /* isp_boot_b             2MB p22 */
    {PART_ISP_FIRMWARE_B,          (48 * 1024) + 928,    14 * 1024, UFS_PART_4}, /* isp_firmware_b       14MB  p23 */
    {PART_FW_HIFI_B,               (62 * 1024) + 928,    12 * 1024, UFS_PART_4}, /* fw_hifi_b            12MB  p24 */
    {PART_TEEOS_B,                 (74 * 1024) + 928,     8 * 1024, UFS_PART_4}, /* teeos_b               8MB  p25 */
    {PART_SENSORHUB_B,             (82 * 1024) + 928,    13 * 1024, UFS_PART_4}, /* sensorhub_b          13MB  p26 */
    {PART_SENSORHUB_LOG_DIC_B,     (95 * 1024) + 928,     3 * 1024, UFS_PART_4}, /* sensorhub_log_dic_b  3MB   p27 */
    {PART_HKRR_B,                  (98 * 1024) + 928,    16 * 1024, UFS_PART_4}, /* hkrr_b                16MB p28 */
    {PART_FW_UFSDEV_B,            (114 * 1024) + 928,     4 * 1024, UFS_PART_4}, /* fw_ufsdev_b          4MB   p29 */
    {PART_FW_DFA_B,               (118 * 1024) + 928,     1 * 1024, UFS_PART_4}, /* fw_dfa_b            1024KB p30 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_UPDATER_RAMDISK_B,      (119 * 1024) + 928,    64 * 1024, UFS_PART_4}, /* updater_ramdisk_b     64MB p31 */
    {PART_UPDATER_VENDOR_B,       (183 * 1024) + 928,    33 * 1024, UFS_PART_4}, /* updater_vendor_b      32MB p32 */
    {PART_BOOT_B,                 (216 * 1024) + 928,    46 * 1024, UFS_PART_4}, /* boot_b                46MB p33 */
    {PART_UPDATER_BOOT_B,         (262 * 1024) + 928,    70 * 1024, UFS_PART_4}, /* updater_boot_b      70MB p34 */
    {PART_UPDATER_BOOT_BAK_B,     (332 * 1024) + 928,    70 * 1024, UFS_PART_4}, /* updater_boot_bak_b  70MB p35 */
    {PART_EXT_RVT_B,              (402 * 1024) + 928,     2 * 1024, UFS_PART_4}, /* ext_rvt_b              2MB p36 */
    {PART_THEE_B,                 (404 * 1024) + 928,     4 * 1024, UFS_PART_4}, /* thee_b              4MB p37 */
    {PART_TZSP_B,                 (408 * 1024) + 928,    12 * 1024, UFS_PART_4}, /* tzsp_b             12MB p38 */
    {PART_UPDATER_RAMDISK_BAK_B,  (420 * 1024) + 928,    64 * 1024, UFS_PART_4}, /* updater_ramdisk_bak_b 64MB p39 */
    {PART_UPDATER_VENDOR_BAK_B,   (484 * 1024) + 928,    33 * 1024, UFS_PART_4}, /* updater_vendor_bak_b  32MB p40 */
    {PART_ENG_SYSTEM_B,           (517 * 1024) + 928,    12 * 1024, UFS_PART_4}, /* eng_system_b          12MB p41 */
    {PART_ENG_CHIPSET_B,          (529 * 1024) + 928,    20 * 1024, UFS_PART_4}, /* eng_chipset_b         20MB p42 */
    {PART_FW_DTB_B,               (549 * 1024) + 928,    20 * 1024, UFS_PART_4}, /* fw_dtb_b            20MB p43 */
    {PART_DTBO_B,                 (569 * 1024) + 928,    20 * 1024, UFS_PART_4}, /* dtbo_b              20MB p44 */
    {PART_TRUSTFIRMWARE_B,        (589 * 1024) + 928,     2 * 1024, UFS_PART_4}, /* trustfirmware_b      2MB p45 */
    {PART_DPA_VENDOR_B,           (591 * 1024) + 928,    32 * 1024, UFS_PART_4}, /* dpa_vendor_b        32MB p46 */
    {PART_MODEM_FW_B,             (623 * 1024) + 928,   124 * 1024, UFS_PART_4}, /* modem_fw_b         124MB p47 */
    {PART_MODEM_VENDOR_B,         (747 * 1024) + 928,    40 * 1024, UFS_PART_4}, /* modem_vendor_b      30MB p48 */
    {PART_MODEM_PATCH_NV_B,       (787 * 1024) + 928,     4 * 1024, UFS_PART_4}, /* modem_patch_nv_b     4MB p49 */
    {PART_MODEM_DRIVER_B,         (791 * 1024) + 928,    20 * 1024, UFS_PART_4}, /* modem_driver_b      20MB p50 */
    {PART_MODEMNVM_UPDATE_B,      (811 * 1024) + 928,    16 * 1024, UFS_PART_4}, /* modemnvm_update_b   16MB p51 */
    {PART_MODEMCONFIG_CUST_B,     (827 * 1024) + 928,    16 * 1024, UFS_PART_4}, /* modemconfig_cust_b  16MB p52 */
    {PART_RAMDISK_B,              (843 * 1024) + 928,     4 * 1024, UFS_PART_4}, /* ramdisk_b            4MB p53 */
    {PART_RVT_SYSTEM_B,           (847 * 1024) + 928,     1 * 1024, UFS_PART_4}, /* rvt_system_b      1024KB p54 */
    {PART_RVT_VENDOR_B,           (848 * 1024) + 928,     1 * 1024, UFS_PART_4}, /* rvt_vendor_b      1024KB p55 */
    {PART_RVT_CHIP_PROD_B,        (849 * 1024) + 928,     1 * 1024, UFS_PART_4}, /* rvt_chip_prod_b   1024KB p56 */
    {PART_RVT_CUST_B,             (850 * 1024) + 928,     1 * 1024, UFS_PART_4}, /* rvt_cust_b        1024KB p57 */
    {PART_RVT_SYS_PROD_B,         (851 * 1024) + 928,     1 * 1024, UFS_PART_4}, /* rvt_sys_prod_b    1024KB p58 */
    {PART_UPDATER_RVT_B,          (852 * 1024) + 928,     2 * 1024, UFS_PART_4}, /* updater_rvt_b        2MB p59 */
    {PART_UPDATER_BAK_RVT_B,      (854 * 1024) + 928,     2 * 1024, UFS_PART_4}, /* updater_bak_rvt_b    2MB p60 */
    {PART_RVT_B,                  (856 * 1024) + 928,     4 * 1024, UFS_PART_4}, /* rvt_b                4MB p61 */
    {PART_KPATCH_B,               (860 * 1024) + 928,     4 * 1024, UFS_PART_4}, /* kpatch_b             4MB p62 */
    {PART_PATCH_B,                (864 * 1024) + 928,    32 * 1024, UFS_PART_4}, /* patch_b             32MB p63 */
    {PART_RVT_VERSION_B,          (896 * 1024) + 928,     1 * 1024, UFS_PART_4}, /* rvt_version_b     1024KB p64 */
    {PART_RVT_PRELOAD_B,          (897 * 1024) + 928,     1 * 1024, UFS_PART_4}, /* rvt_preload_b     1024KB p65 */
    {PART_RVT_AI_MODEL_B,         (898 * 1024) + 928,     1 * 1024, UFS_PART_4}, /* rvt_ai_model_b   1024KB p66 */
    {PART_RESERVED_lu4,           (899 * 1024)+ 928,140 * 1024+96, UFS_PART_4}, /* reserved_lu4      142M p67 */
#else
    {PART_UPDATER_RAMDISK_B,      (119 * 1024) + 928,    32 * 1024, UFS_PART_4}, /* updater_ramdisk_b   32MB p31 */
    {PART_UPDATER_VENDOR_B,       (151 * 1024) + 928,    32 * 1024, UFS_PART_4}, /* updater_vendor_b    32MB p32 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_BOOT_B,                 (183 * 1024) + 928,    46 * 1024, UFS_PART_4}, /* boot_b              46MB p33 */
    {PART_UPDATER_BOOT_B,         (229 * 1024) + 928,    70 * 1024, UFS_PART_4}, /* updater_boot_b      70MB p34 */
    {PART_UPDATER_BOOT_BAK_B,     (299 * 1024) + 928,    70 * 1024, UFS_PART_4}, /* updater_boot_bak_b  70MB p35 */
    {PART_EXT_RVT_B,              (369 * 1024) + 928,     2 * 1024, UFS_PART_4}, /* ext_rvt_b            2MB p36 */
    {PART_RESERVED1_lu4,          (371 * 1024) + 928, 56 * 1024+96, UFS_PART_4}, /* reserved1_lu4     57440KB p37 */
#else
    {PART_BOOT_B,                 (183 * 1024) + 928,    46 * 1024, UFS_PART_4}, /* boot_b              46MB p33 */
    {PART_UPDATER_BOOT_B,         (229 * 1024) + 928,    66 * 1024, UFS_PART_4}, /* updater_boot_b      66MB p34 */
    {PART_UPDATER_BOOT_BAK_B,     (295 * 1024) + 928,    66 * 1024, UFS_PART_4}, /* updater_boot_bak_b  66MB p35 */
    {PART_EXT_RVT_B,              (361 * 1024) + 928,     2 * 1024, UFS_PART_4}, /* ext_rvt_b            2MB p36 */
    {PART_RESERVED1_lu4,          (363 * 1024) + 928, 64 * 1024+96, UFS_PART_4}, /* reserved1_lu4     65632KB p37 */
#endif
    {PART_THEE_B,               428 * 1024,     4 * 1024, UFS_PART_4}, /* thee_b               4MB p38 */
    {PART_TZSP_B,               432 * 1024,    12 * 1024, UFS_PART_4}, /* tzsp_b              12MB p39 */
    {PART_UPDATER_RAMDISK_BAK_B,444 * 1024,    32 * 1024, UFS_PART_4}, /* updater_ramdisk_bak_b  32MB p40 */
    {PART_UPDATER_VENDOR_BAK_B, 476 * 1024,    32 * 1024, UFS_PART_4}, /* updater_vendor_bak_b  28MB p41 */
    {PART_ENG_SYSTEM_B,         508 * 1024,    12 * 1024, UFS_PART_4}, /* eng_system_b        12MB p42 */
    {PART_ENG_CHIPSET_B,        520 * 1024,    20 * 1024, UFS_PART_4}, /* eng_chipset_b       20MB p43 */
    {PART_FW_DTB_B,             540 * 1024,    20 * 1024, UFS_PART_4}, /* fw_dtb_b            20MB p44 */
    {PART_DTBO_B,               560 * 1024,    20 * 1024, UFS_PART_4}, /* dtbo_b              20MB p45 */
    {PART_TRUSTFIRMWARE_B,      580 * 1024,     2 * 1024, UFS_PART_4}, /* trustfirmware_b      2MB p46 */
    {PART_DPA_VENDOR_B,         582 * 1024,    32 * 1024, UFS_PART_4}, /* dpa_vendor_b        32MB p47 */
    {PART_MODEM_FW_B,           614 * 1024,   124 * 1024, UFS_PART_4}, /* modem_fw_b         124MB p48 */
    {PART_MODEM_VENDOR_B,       738 * 1024,    10 * 1024, UFS_PART_4}, /* modem_vendor_b      10MB p49 */
    {PART_MODEM_PATCH_NV_B,     748 * 1024,     4 * 1024, UFS_PART_4}, /* modem_patch_nv_b     4MB p50 */
    {PART_MODEM_DRIVER_B,       752 * 1024,    20 * 1024, UFS_PART_4}, /* modem_driver_b      20MB p51 */
    {PART_MODEMNVM_UPDATE_B,    772 * 1024,    16 * 1024, UFS_PART_4}, /* modemnvm_update_b   16MB p52 */
    {PART_MODEMCONFIG_CUST_B,   788 * 1024,    16 * 1024, UFS_PART_4}, /* modemconfig_cust_b  16MB p53 */
    {PART_RAMDISK_B,            804 * 1024,     4 * 1024, UFS_PART_4}, /* ramdisk_b            4MB p54 */
    {PART_RVT_SYSTEM_B,         808 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_system_b      1024KB p55 */
    {PART_RVT_VENDOR_B,         809 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_vendor_b      1024KB p56 */
    {PART_RVT_CHIP_PROD_B,      810 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_chip_prod_b   1024KB p57 */
    {PART_RVT_CUST_B,           811 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_cust_b        1024KB p58 */
    {PART_RVT_SYS_PROD_B,       812 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_sys_prod_b    1024KB p59 */
    {PART_UPDATER_RVT_B,        813 * 1024,     2 * 1024, UFS_PART_4}, /* updater_rvt_b        2MB p60 */
    {PART_UPDATER_BAK_RVT_B,    815 * 1024,     2 * 1024, UFS_PART_4}, /* updater_bak_rvt_b    2MB p61 */
    {PART_RVT_B,                817 * 1024,     4 * 1024, UFS_PART_4}, /* rvt_b                4MB p62 */
    {PART_KPATCH_B,             821 * 1024,     4 * 1024, UFS_PART_4}, /* kpatch_b             4MB p63 */
    {PART_PATCH_B,              825 * 1024,   128 * 1024, UFS_PART_4}, /* patch_b            128MB p64 */
    {PART_RVT_VERSION_B,        953 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_version_b     1024KB p65 */
    {PART_RVT_PRELOAD_B,        954 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_preload_b     1024KB p66 */
    {PART_RVT_AI_MODEL_B,       955 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_ai_model_b    1024KB p67 */
    {PART_RESERVED_lu4,         956 * 1024,    95 * 1024, UFS_PART_4}, /* reserved_lu4        95MB p68 */
#endif
    {PART_PTABLE_LU5,             0,             512,     UFS_PART_5}, /* ptable_lu5          512KB p0 */
    {PART_BOOT_CTRL,              512,          1 * 1024, UFS_PART_5}, /* boot_ctrl         1024KB p1 */
    {PART_VRL,                    512 + 1024,        512, UFS_PART_5}, /* vrl                512KB p2 */
    {PART_VRL_BACKUP,             2 * 1024,          512, UFS_PART_5}, /* vrl_backup         512KB p3 */
    {PART_MODEM_SECURE,           2 * 1024 + 512,   8704, UFS_PART_5}, /* modem_secure         9MB p4 */
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
    {PART_LOG,                  351 * 1024,    200 * 1024, UFS_PART_5}, /* log                 200MB p19 */
    {PART_BOOTFAIL_INFO,        551 * 1024,     2 * 1024, UFS_PART_5}, /* bootfail_info        2MB p20 */
    {PART_MISC,                 553 * 1024,     2 * 1024, UFS_PART_5}, /* misc                 2MB p21 */
    {PART_DFX,                  555 * 1024,    16 * 1024, UFS_PART_5}, /* dfx                 16MB p22 */
    {PART_RRECORD,              571 * 1024,    16 * 1024, UFS_PART_5}, /* rrecord             16MB p23 */
    {PART_CACHE,                587 * 1024,   104 * 1024, UFS_PART_5}, /* cache              104MB p24 */
    {PART_METADATA,             691 * 1024,    16 * 1024, UFS_PART_5}, /* metadata            16MB p25 */
    {PART_TOC,                  707 * 1024,     1 * 1024, UFS_PART_5}, /* toc               1024KB p26 */
    {PART_DDR_FAC_INFO,         708 * 1024,     1 * 1024, UFS_PART_5}, /* ddr_fac_info   1024KB p27 */
    {PART_DVFS,                 709 * 1024,     1 * 1024, UFS_PART_5}, /* dvfs   1024KB p28 */
    {PART_HISEE_FS,             710 * 1024,     8 * 1024, UFS_PART_5}, /* hisee_fs             8MB p29 */
    {PART_MODULE_UPDATE,        718 * 1024,          512, UFS_PART_5}, /* module_update      512KB p30 */
    {PART_RESERVED,             718 * 1024 + 512,   (14 * 1024 + 512), UFS_PART_5}, /* reserved  14.5MB p31 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_HYPERHOLD,            733 * 1024,     4 * 1024, UFS_PART_5}, /* hyperhold            4MB p32 */
    {PART_CUST,                 737 * 1024,    88 * 1024, UFS_PART_5}, /* cust                88MB p33 */
    {PART_CHIP_PROD,            825 * 1024,  8192 * 1024, UFS_PART_5}, /* chip_prod         8192MB p34 */
    {PART_VENDOR,              9017 * 1024,  3284 * 1024, UFS_PART_5}, /* vendor            3284MB p35 */
    {PART_SYS_PROD,           12301 * 1024,  8812 * 1024, UFS_PART_5}, /* sys_prod          8812MB p36 */
    {PART_SYSTEM,             21113 * 1024,  8500 * 1024, UFS_PART_5}, /* system            8500MB p37 */
    {PART_VERSION,            29613 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p38 */
    {PART_PRELOAD,            30189 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p39 */
    {PART_RESERVED1_lu5,      31589 * 1024,   169 * 1024, UFS_PART_5}, /* reserved1_lu5       169MB p40 */
    {PART_USERDATA,           31758 * 1024,(14UL) * 1024 * 1024, UFS_PART_5}, /* userdata       14G p41 */
#elif defined(CONFIG_FACTORY_MODE)
    {PART_HIBENCH_IMG,          733 * 1024,    12 * 1024, UFS_PART_5}, /* hibench_img         12MB p32 */
    {PART_HIBENCH_LOG,          745 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p33 */
    {PART_HIBENCH_DATA,         777 * 1024,  2048 * 1024, UFS_PART_5}, /* hibench_data      2048MB p34 */
    {PART_FLASH_AGEING,        2825 * 1024,   512 * 1024, UFS_PART_5}, /* flash_ageing       512MB p35 */
    {PART_XLOADER_HITEST,      3337 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p36 */
    {PART_HYPERHOLD,           3339 * 1024,     4 * 1024, UFS_PART_5}, /* hyperhold            4MB p37 */
    {PART_CUST,                3343 * 1024,   128 * 1024, UFS_PART_5}, /* cust               128MB p38 */
    {PART_VENDOR,              3471 * 1024,  1282 * 1024, UFS_PART_5}, /* vendor            1282MB p39 */
    {PART_CHIP_PROD,           4753 * 1024,  3218 * 1024, UFS_PART_5}, /* chip_prod         3218MB p40 */
    {PART_SYS_PROD,            7971 * 1024,  8812 * 1024, UFS_PART_5}, /* sys_prod          8812MB p41 */
    {PART_SYSTEM,             16783 * 1024,  4948 * 1024, UFS_PART_5}, /* system            4948MB p42 */
    {PART_RESERVED6,          21731 * 1024, 29123 * 1024, UFS_PART_5}, /* reserved6         29123MB p43 */
    {PART_PRELOAD,            50854 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p44 */
    {PART_USERDATA,           52254 * 1024,(16UL) * 1024 * 1024, UFS_PART_5}, /* userdata       16G p45 */
    {PART_VERSION,            68638 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p46 */
#else
    {PART_HYPERHOLD,            733 * 1024,     4 * 1024, UFS_PART_5}, /* hyperhold            4MB p32 */
    {PART_CUST,                 737 * 1024,   128 * 1024, UFS_PART_5}, /* cust               128MB p33 */
    {PART_VENDOR,               865 * 1024,  1800 * 1024, UFS_PART_5}, /* vendor            1800MB p34 */
    {PART_AI_MODEL,            2665 * 1024,     2 * 1024, UFS_PART_5}, /* ai_model             2MB p35 */
    {PART_CHIP_PROD,           2667 * 1024,  6212 * 1024, UFS_PART_5}, /* chip_prod         6212MB p36 */
    {PART_SYS_PROD,            8879 * 1024,  9796 * 1024, UFS_PART_5}, /* sys_prod          9796MB p37 */
    {PART_SYSTEM,             18675 * 1024,  5716 * 1024, UFS_PART_5}, /* system            5716MB p38 */
    {PART_RESERVED1_lu5,      24391 * 1024,   168 * 1024, UFS_PART_5}, /* reserved1_lu5      168MB p39 */
#if defined(CONFIG_PARTITION_ENG)
    {PART_FTTEST,             24559 * 1024,    12 * 1024, UFS_PART_5}, /* fttest              12MB p40 */
    {PART_DDRTEST,            24571 * 1024,    48 * 1024, UFS_PART_5}, /* ddrtest             48MB p41 */
    {PART_XLOADER_HITEST,     24619 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p42 */
    {PART_HITEST_DATA,        24621 * 1024,  2229 * 1024, UFS_PART_5}, /* hitest_data       2229MB p43 */
    {PART_MODEM_IMG_TEST,     26850 * 1024,   230 * 1024, UFS_PART_5}, /* modem_img_test     230MB p44 */
    {PART_DISP_PANEL_INFO,    27080 * 1024,    20 * 1024, UFS_PART_5}, /* disp_panel_info     20MB p45 */
    {PART_PRELOAD,            27100 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p46 */
    {PART_USERDATA,           28500 * 1024,(16UL) * 1024 * 1024, UFS_PART_5}, /* userdata      16G p47 */
    {PART_VERSION,            44884 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p48 */
#else // system in ccm is 5716,but now less 768
    {PART_RESERVED9,          24559 * 1024,  1817 * 1024, UFS_PART_5}, /* reserved9         1817MB p40 */
    {PART_PRELOAD,            26376 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p41 */
    {PART_USERDATA,           27776 * 1024,(16UL) * 1024 * 1024, UFS_PART_5}, /* userdata      16G p42 */
    {PART_VERSION,            44160 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p43 */
#endif
#endif
    {"0", 0, 0, 0},
};
#endif
