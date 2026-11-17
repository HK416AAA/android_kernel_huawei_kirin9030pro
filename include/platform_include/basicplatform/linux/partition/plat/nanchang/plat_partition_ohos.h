#ifndef _NANCHANG_PLAT_PARTITION_OHOS_H_
#define _NANCHANG_PLAT_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                0,              4 * 1024,    UFS_PART_0},
    {PART_RESERVED0,              0,              2 * 1024,    UFS_PART_1},
    {PART_PTABLE,                 0,                   512,    UFS_PART_2}, /* ptable           512K    p0 */
    {PART_FRP,                         512,          512, UFS_PART_2}, /* frp                512KB p1 */
    {PART_PERSIST,                    1024,     6 * 1024, UFS_PART_2}, /* persist              6MB p2 */
    {PART_RESERVED1,              7 * 1024,         1024, UFS_PART_2}, /* reserved1         1024KB p3 */
    {PART_PTABLE_LU3,             0,                   512,    UFS_PART_3}, /* ptable_lu3       512K    p0 */
    {PART_VRL,                         512,          512, UFS_PART_3}, /* vrl                512KB p1 */
    {PART_VRL_BACKUP,                 1024,          512, UFS_PART_3}, /* vrl_backup         512KB p2 */
    {PART_MODEM_SECURE,               1536,         8704, UFS_PART_3}, /* modem_secure      8704KB p3 */
    {PART_NVME,                  10 * 1024,     4 * 1024, UFS_PART_3}, /* nvme                 4MB p4 */
    {PART_CONN_CALIDATA,         14 * 1024,         1024, UFS_PART_3}, /* conn_calidata     1024KB p5 */
    {PART_CTF,                   15 * 1024,     1 * 1024, UFS_PART_3}, /* ctf               1024KB p6 */
    {PART_OEMINFO,               16 * 1024,    96 * 1024, UFS_PART_3}, /* oeminfo             96MB p7 */
    {PART_SECURE_STORAGE,       112 * 1024,    32 * 1024, UFS_PART_3}, /* secure_storage      32MB p8 */
    {PART_MODEMNVM_FACTORY,     144 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_factory    16MB p9 */
    {PART_MODEMNVM_BACKUP,      160 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_backup     16MB p10 */
    {PART_MODEMNVM_IMG,         176 * 1024,    46 * 1024, UFS_PART_3}, /* modemnvm_img        46MB p11 */
    {PART_HISEE_ENCOS,          222 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_encos          4MB p12 */
    {PART_VERITYKEY,            226 * 1024,     1 * 1024, UFS_PART_3}, /* veritykey         1024KB p13 */
    {PART_DDR_PARA,             227 * 1024,     1 * 1024, UFS_PART_3}, /* ddr_para          1024KB p14 */
    {PART_LOWPOWER_PARA,        228 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para     1024KB p15 */
    {PART_BATT_TP_PARA,         229 * 1024,     1 * 1024, UFS_PART_3}, /* batt_tp_para      1024KB p16 */
    {PART_PANEL_CALIBRATION,    230 * 1024,   100 * 1024, UFS_PART_3}, /* panel_calibration  100MB p17 */
    {PART_RESERVED2,            330 * 1024,    21 * 1024, UFS_PART_3}, /* reserved2           21MB p18 */
    {PART_LOG,                  351 * 1024,    80 * 1024, UFS_PART_3}, /* log                 80MB p19 */
    {PART_BOOTFAIL_INFO,        431 * 1024,     2 * 1024, UFS_PART_3}, /* bootfail_info        2MB p20 */
    {PART_MISC,                 433 * 1024,     2 * 1024, UFS_PART_3}, /* misc                 2MB p21 */
    {PART_DFX,                  435 * 1024,    16 * 1024, UFS_PART_3}, /* dfx                 16MB p22 */
    {PART_RRECORD,              451 * 1024,    16 * 1024, UFS_PART_3}, /* rrecord             16MB p23 */
    {PART_CACHE,                467 * 1024,   104 * 1024, UFS_PART_3}, /* cache              104MB p24 */
    {PART_METADATA,             571 * 1024,    16 * 1024, UFS_PART_3}, /* metadata            16MB p25 */
    {PART_SEPLAT,               587 * 1024,     4 * 1024, UFS_PART_3}, /* seplat               4MB p26 */
    {PART_TOC,                  591 * 1024,     1 * 1024, UFS_PART_3}, /* toc               1024KB p27 */
    {PART_BL2,                  592 * 1024,     4 * 1024, UFS_PART_3}, /* bl2                  4MB p28 */
    {PART_FW_LPM3,              596 * 1024,          512, UFS_PART_3}, /* fw_lpm3            512KB p29 */
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
    {PART_RESERVED3,           (600 * 1024 + 416),  4 * 1024 + 608, UFS_PART_3}, /* reserved3   5984KB p40 */
    {PART_NPU,                  605 * 1024,     8 * 1024, UFS_PART_3}, /* npu                  8MB p41 */
    {PART_IVP,                  613 * 1024,     2 * 1024, UFS_PART_3}, /* ivp                  2MB p42 */
    {PART_DACC,                 615 * 1024,          256, UFS_PART_3}, /* dacc               256KB p43 */
    {PART_DACC_AAE,            (615 * 1024 + 256),   256, UFS_PART_3}, /* dacc_aae           256KB p44 */
    {PART_VENC,                (615 * 1024 + 512),   512, UFS_PART_3}, /* venc               512KB p45 */
    {PART_HISEE_IMG,            616 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p46 */
    {PART_HHEE,                 620 * 1024,     4 * 1024, UFS_PART_3}, /* hhee                 4MB p47 */
    {PART_HISEE_FS,             624 * 1024,     8 * 1024, UFS_PART_3}, /* hisee_fs             8MB p48 */
    {PART_FASTBOOT,             632 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p49 */
    {PART_VECTOR,               644 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p50 */
    {PART_ISP_BOOT,             648 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot             2MB p51 */
    {PART_ISP_FIRMWARE,         650 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware        14MB p52 */
    {PART_FW_HIFI,              664 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi             12MB p53 */
    {PART_TEEOS,                676 * 1024,     8 * 1024, UFS_PART_3}, /* teeos                8MB p54 */
    {PART_SENSORHUB,            684 * 1024,    13 * 1024, UFS_PART_3}, /* sensorhub           13MB p55 */
    {PART_SENSORHUB_LOG_DIC,    697 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p56 */
    {PART_HKRR,                 700 * 1024,    16 * 1024, UFS_PART_3}, /* hkrr                16MB p57 */
    {PART_FW_UFSDEV,            716 * 1024,     4 * 1024, UFS_PART_3}, /* fw_ufsdev            4MB p58 */
    {PART_FW_DFA,               720 * 1024,     1 * 1024, UFS_PART_3}, /* fw_dfa            1024KB p59 */
    {PART_RESERVED4,            721 * 1024,    15 * 1024, UFS_PART_3}, /* reserved4           15MB p60 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_UPDATER_RAMDISK,      736 * 1024,    64 * 1024, UFS_PART_3}, /* updater_ramdisk     64MB p61 */
    {PART_UPDATER_VENDOR,       800 * 1024,    28 * 1024, UFS_PART_3}, /* updater_vendor      28MB p62 */
    {PART_BOOT,                 828 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p63 */
    {PART_UPDATER_BOOT,         874 * 1024,    64 * 1024, UFS_PART_3}, /* updater_boot        64MB p64 */
    {PART_UPDATER_BOOT_BAK,     938 * 1024,    64 * 1024, UFS_PART_3}, /* updater_boot_bak    64MB p65 */
    {PART_MODULE_UPDATE,       1002 * 1024,          512, UFS_PART_3}, /* module_update      512KB p66 */
    {PART_EXT_RVT,      (1002 * 1024 + 512),    2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p67 */
    {PART_RESERVED,     (1004 * 1024 + 512),   (14 * 1024 + 512), UFS_PART_3}, /* reserved  14.5MB p68 */
    {PART_THEE,                1019 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p69 */
    {PART_TZSP,                1023 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p70 */
    {PART_UPDATER_RAMDISK_BAK,  1035 * 1024,    64 * 1024, UFS_PART_3}, /* updater_ramdisk_bak  64MB p71 */
    {PART_UPDATER_VENDOR_BAK,  1099 * 1024,    28 * 1024, UFS_PART_3}, /* updater_vendor_bak  28MB p72 */
    {PART_ENG_SYSTEM,          1127 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p73 */
    {PART_ENG_CHIPSET,         1139 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset         20MB p74 */
    {PART_FW_DTB,              1159 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb               8MB p75 */
    {PART_DTBO,                1167 * 1024,    20 * 1024, UFS_PART_3}, /* dtbo                20MB p76 */
    {PART_TRUSTFIRMWARE,       1187 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p77 */
    {PART_MODEM_FW,            1189 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p78 */
    {PART_MODEM_VENDOR,        1313 * 1024,    30 * 1024, UFS_PART_3}, /* modem_vendor        30MB p79 */
    {PART_MODEM_PATCH_NV,      1343 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p80 */
    {PART_MODEM_DRIVER,        1347 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p81 */
    {PART_MODEMNVM_UPDATE,     1367 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p82 */
    {PART_MODEMCONFIG_CUST,    1383 * 1024,    16 * 1024, UFS_PART_3}, /* modemconfig_cust    16MB p83 */
    {PART_RAMDISK,             1399 * 1024,     5 * 1024, UFS_PART_3}, /* ramdisk              5MB p84 */
    {PART_RVT_SYSTEM,          1404 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system        1024KB p85 */
    {PART_RVT_VENDOR,          1405 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor        1024KB p86 */
    {PART_RVT_CHIP_PROD,       1406 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod     1024KB p87 */
    {PART_RVT_CUST,            1407 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust          1024KB p88 */
    {PART_RVT_SYS_PROD,        1408 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod      1024KB p89 */
    {PART_UPDATER_RVT,         1409 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt          2MB p90 */
    {PART_UPDATER_BAK_RVT,     1411 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt      2MB p91 */
    {PART_RVT,                 1413 * 1024,     4 * 1024, UFS_PART_3}, /* rvt                  4MB p92 */
    {PART_KPATCH,              1417 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p93 */
    {PART_PATCH,               1421 * 1024,    32 * 1024, UFS_PART_3}, /* patch               32MB p94 */
    {PART_CUST,                1453 * 1024,    88 * 1024, UFS_PART_3}, /* cust                88MB p95 */
    {PART_CHIP_PROD,           1541 * 1024,  3018 * 1024, UFS_PART_3}, /* chip_prod         3018MB p96 */
    {PART_VENDOR,              4559 * 1024,  3284 * 1024, UFS_PART_3}, /* vendor            3284MB p97 */
    {PART_SYS_PROD,            7843 * 1024,  8812 * 1024, UFS_PART_3}, /* sys_prod          8812MB p98 */
    {PART_SYSTEM,             16655 * 1024,  7168 * 1024, UFS_PART_3}, /* system            7168MB p99 */
    {PART_HYPERHOLD,          23823 * 1024,     4 * 1024, UFS_PART_3}, /* hyperhold            4MB p100 */
    {PART_RESERVED5,          23827 * 1024,   143 * 1024, UFS_PART_3}, /* reserved5          143MB p101 */
    {PART_VERSION,            23970 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p102 */
    {PART_PRELOAD,            24546 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p103 */
    {PART_USERDATA,           25946 * 1024,(14UL) * 1024 * 1024, UFS_PART_3}, /* userdata       4G p104 */
#else
    {PART_UPDATER_RAMDISK,      736 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk     32MB p61 */
    {PART_UPDATER_VENDOR,       768 * 1024,    28 * 1024, UFS_PART_3}, /* updater_vendor      28MB p62 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_BOOT,                 796 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p63 */
    {PART_UPDATER_BOOT,         842 * 1024,    64 * 1024, UFS_PART_3}, /* updater_boot        64MB p64 */
    {PART_UPDATER_BOOT_BAK,     906 * 1024,    64 * 1024, UFS_PART_3}, /* updater_boot_bak    64MB p65 */
    {PART_MODULE_UPDATE,        970 * 1024,          512, UFS_PART_3}, /* module_update      512KB p66 */
    {PART_EXT_RVT,       (970 * 1024 + 512),    2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p67 */
    {PART_RESERVED,      (972 * 1024 + 512),   (31 * 1024 + 512), UFS_PART_3}, /* reserved    31.5MB p68 */
#else
    {PART_BOOT,                 796 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p63 */
    {PART_UPDATER_BOOT,         842 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot        54MB p64 */
    {PART_UPDATER_BOOT_BAK,     896 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot_bak    54MB p65 */
    {PART_MODULE_UPDATE,        950 * 1024,          512, UFS_PART_3}, /* module_update      512KB p66 */
    {PART_EXT_RVT,       (950 * 1024 + 512),    2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p67 */
    {PART_RESERVED,      (952 * 1024 + 512),   (51 * 1024 + 512), UFS_PART_3}, /* reserved  51.5MB p68 */
#endif
    {PART_THEE,                1004 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p69 */
    {PART_TZSP,                1008 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p70 */
    {PART_UPDATER_RAMDISK_BAK,  1020 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak  32MB p71 */
    {PART_UPDATER_VENDOR_BAK,  1052 * 1024,    28 * 1024, UFS_PART_3}, /* updater_vendor_bak  28MB p72 */
    {PART_ENG_SYSTEM,          1080 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p73 */
    {PART_ENG_CHIPSET,         1092 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset         20MB p74 */
    {PART_FW_DTB,              1112 * 1024,    20 * 1024, UFS_PART_3}, /* fw_dtb              20MB p75 */
    {PART_DTBO,                1132 * 1024,    20 * 1024, UFS_PART_3}, /* dtbo                20MB p76 */
    {PART_TRUSTFIRMWARE,       1152 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p77 */
    {PART_MODEM_FW,            1154 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p78 */
    {PART_MODEM_VENDOR,        1278 * 1024,    10 * 1024, UFS_PART_3}, /* modem_vendor        10MB p79 */
    {PART_MODEM_PATCH_NV,      1288 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p80 */
    {PART_MODEM_DRIVER,        1292 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p81 */
    {PART_MODEMNVM_UPDATE,     1312 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p82 */
    {PART_MODEMCONFIG_CUST,    1328 * 1024,    16 * 1024, UFS_PART_3}, /* modemconfig_cust    16MB p83 */
    {PART_RAMDISK,             1344 * 1024,     4 * 1024, UFS_PART_3}, /* ramdisk              4MB p84 */
    {PART_RVT_SYSTEM,          1348 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system        1024KB p85 */
    {PART_RVT_VENDOR,          1349 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor        1024KB p86 */
    {PART_RVT_CHIP_PROD,       1350 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod     1024KB p87 */
    {PART_RVT_CUST,            1351 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust          1024KB p88 */
    {PART_RVT_SYS_PROD,        1352 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod      1024KB p89 */
    {PART_UPDATER_RVT,         1353 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt          2MB p90 */
    {PART_UPDATER_BAK_RVT,     1355 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt      2MB p91 */
    {PART_RVT,                 1357 * 1024,     4 * 1024, UFS_PART_3}, /* rvt                  4MB p92 */
    {PART_KPATCH,              1361 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p93 */
    {PART_PATCH,               1365 * 1024,   128 * 1024, UFS_PART_3}, /* patch              128MB p94 */
    {PART_CUST,                1493 * 1024,   128 * 1024, UFS_PART_3}, /* cust               128MB p95 */
    {PART_CHIP_PROD,           1621 * 1024,  3018 * 1024, UFS_PART_3}, /* chip_prod         3018MB p96 */
    {PART_VENDOR,              4639 * 1024,  1132 * 1024, UFS_PART_3}, /* vendor            1132MB p97 */
    {PART_SYS_PROD,            5771 * 1024,  8812 * 1024, UFS_PART_3}, /* sys_prod          8812MB p98 */
    {PART_SYSTEM,             14583 * 1024,  4948 * 1024, UFS_PART_3}, /* system            4948MB p99 */
    {PART_HYPERHOLD,          19531 * 1024,     4 * 1024, UFS_PART_3}, /* hyperhold            4MB p100 */
    {PART_RESERVED5,          19535 * 1024,   137 * 1024, UFS_PART_3}, /* reserved5          137MB p101 */
    {PART_VERSION,            19672 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p102 */
    {PART_PRELOAD,            20248 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p103 */
#if defined(CONFIG_FACTORY_MODE)
    {PART_HIBENCH_IMG,        21648 * 1024,    12 * 1024, UFS_PART_3}, /* hibench_img         12MB p104 */
    {PART_HIBENCH_LOG,        21660 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p105 */
    {PART_HIBENCH_DATA,       21692 * 1024,  1024 * 1024, UFS_PART_3}, /* hibench_data      1024 * 1024KB p106 */
    {PART_XLOADER_HITEST,     22716 * 1024,     2 * 1024, UFS_PART_3}, /* xloader_hitest       2MB p107 */
    {PART_FLASH_AGEING,       22718 * 1024,   512 * 1024, UFS_PART_3}, /* flash_ageing       512MB p108 */
    {PART_RESERVED6,          23230 * 1024, 12372 * 1024, UFS_PART_3}, /* reserved6         12372MB p109 */
    {PART_USERDATA,           35602 * 1024,(16UL) * 1024 * 1024, UFS_PART_3}, /* userdata       6G p110 */
#elif defined(CONFIG_PARTITION_ENG)
    {PART_FTTEST,             21648 * 1024,    12 * 1024, UFS_PART_3}, /* fttest              12MB p104 */
    {PART_XLOADER_HITEST,     21660 * 1024,     2 * 1024, UFS_PART_3}, /* xloader_hitest       2MB p105 */
    {PART_HITEST_DATA,        21662 * 1024,  2228 * 1024, UFS_PART_3}, /* hitest_data       2228MB p106 */
    {PART_MODEM_IMG_TEST,     23890 * 1024,   230 * 1024, UFS_PART_3}, /* modem_img_test     230MB p107 */
    {PART_DISP_PANEL_INFO,    24120 * 1024,    20 * 1024, UFS_PART_3}, /* disp_panel_info    20MB p108 */
    {PART_USERDATA,           24140 * 1024,(16UL) * 1024 * 1024, UFS_PART_3}, /* userdata       6G p109 */
#else // system in ccm is 5716,but now less 768
    {PART_RESERVED9,          21648 * 1024,  1816 * 1024, UFS_PART_3}, /* reserved9         1816MB p104 */
    {PART_USERDATA,           23464 * 1024,(16UL) * 1024 * 1024, UFS_PART_3}, /* userdata       6G p105 */
#endif
#endif
    {"0", 0, 0, 0},
};

#endif
