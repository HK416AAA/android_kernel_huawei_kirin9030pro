#ifndef _PISCES_PLAT_PARTITION_H_
#define _PISCES_PLAT_PARTITION_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                0,              2 * 1024,    UFS_PART_0},
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
    {PART_SPLASH2,              351 * 1024,    80 * 1024, UFS_PART_3}, /* splash2             80MB p19 */
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
    {PART_FW_CPU_LPCTRL,       (596 * 1024 + 512),  256, UFS_PART_3}, /* fw_cpu_lpctrl      256K    p29 */
    {PART_FW_GPU_LPCTRL,       (596 * 1024 + 768),  128, UFS_PART_3}, /* fw_gpu_lpctrl      128K    p30 */
    {PART_FW_DDR_LPCTRL,       (596 * 1024 + 896),  256, UFS_PART_3}, /* fw_ddr_lpctrl      256K    p31 */
    {PART_DDR_XPU_BOOT0,       (597 * 1024 + 128),    256, UFS_PART_3}, /* ddr_xpu_boot0      256KB p32 */
    {PART_DDR_XPU_BOOT1,       (597 * 1024 + 384),  256, UFS_PART_3}, /* ddr_xpu_boot1      256KB  p33 */
    {PART_DDR_XPU_BOOT2,       (597 * 1024 + 640),  256, UFS_PART_3}, /* ddr_xpu_boot2      256KB  p34 */
    {PART_UCE,                 (597 * 1024 + 896),  160, UFS_PART_3}, /* uce                160KB  p35 */
    {PART_RESERVED4,           (598 * 1024 + 32),  5 * 1024 + 2016, UFS_PART_3}, /* reserved4   7136KB p36 */
    {PART_NPU,                  605 * 1024,     8 * 1024, UFS_PART_3}, /* npu                  8MB p38 */
    {PART_IVP,                  613 * 1024,     2 * 1024, UFS_PART_3}, /* ivp                  2MB p39 */
    {PART_DACC,                 615 * 1024,          512, UFS_PART_3}, /* dacc               512KB p40 */
    {PART_VENC,                (615 * 1024 + 512),   512, UFS_PART_3}, /* venc               512KB p35 */
    {PART_HISEE_IMG,            616 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p42 */
    {PART_HHEE,                 620 * 1024,     4 * 1024, UFS_PART_3}, /* hhee                 4MB p43 */
    {PART_HISEE_FS,             624 * 1024,     8 * 1024, UFS_PART_3}, /* hisee_fs             8MB p44 */
    {PART_FASTBOOT,             632 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p45 */
    {PART_VECTOR,               644 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p46 */
    {PART_ISP_BOOT,             648 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot             2MB p47 */
    {PART_ISP_FIRMWARE,         650 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware        14MB p48 */
    {PART_FW_HIFI,              664 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi             12MB p49 */
    {PART_TEEOS,                676 * 1024,     8 * 1024, UFS_PART_3}, /* teeos                8MB p50 */
    {PART_SENSORHUB,            684 * 1024,    13 * 1024, UFS_PART_3}, /* sensorhub           13MB p51 */
    {PART_SENSORHUB_LOG_DIC,    697 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p52 */
    {PART_HKRR,                 700 * 1024,    16 * 1024, UFS_PART_3}, /* hkrr                16MB p53 */
    {PART_FW_UFSDEV,            716 * 1024,     4 * 1024, UFS_PART_3}, /* fw_ufsdev            4MB p54 */
    {PART_FW_DFA,               720 * 1024,     1 * 1024, UFS_PART_3}, /* fw_dfa            1024KB p55 */
    {PART_RESERVED5,            721 * 1024,    23 * 1024, UFS_PART_3}, /* reserved5           23MB p56 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK,    744 * 1024,    12 * 1024, UFS_PART_3}, /* erecovery_ramdisk   12MB p57 */
    {PART_ERECOVERY_VENDOR,     756 * 1024,    12 * 1024, UFS_PART_3}, /* erecovery_vendor    12MB p58 */
    {PART_BOOT,                 768 * 1024,    81 * 1024, UFS_PART_3}, /* boot                81MB p59 */
    {PART_RECOVERY,             849 * 1024,    94 * 1024, UFS_PART_3}, /* recovery            94MB p60 */
    {PART_ERECOVERY,            943 * 1024,    21 * 1024, UFS_PART_3}, /* erecovery           21MB p61 */
    {PART_MODULE_UPDATE,        964 * 1024,          512, UFS_PART_3}, /* module_update      512KB p62 */
    {PART_EXT_RVT,      (964 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p63 */
    {PART_RESERVED, (966 * 1024 + 512),(46 * 1024 + 512), UFS_PART_3}, /* reserved          46.5MB p64 */
    {PART_THEE,                1013 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p65 */
    {PART_TZSP,                1017 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p66 */
    {PART_RECOVERY_RAMDISK,    1029 * 1024,    32 * 1024, UFS_PART_3}, /* recovery_ramdisk    32MB p67 */
    {PART_RECOVERY_VENDOR,     1061 * 1024,    28 * 1024, UFS_PART_3}, /* recovery_vendor     28MB p68 */
#elif defined CONFIG_HWSANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK,    744 * 1024,    40 * 1024, UFS_PART_3}, /* erecovery_ramdisk   40MB p57 */
    {PART_ERECOVERY_VENDOR,     784 * 1024,    28 * 1024, UFS_PART_3}, /* erecovery_vendor    28MB p58 */
    {PART_BOOT,                 812 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p59 */
    {PART_RECOVERY,             858 * 1024,    54 * 1024, UFS_PART_3}, /* recovery            54MB p60 */
    {PART_ERECOVERY,            912 * 1024,    54 * 1024, UFS_PART_3}, /* erecovery           54MB p61 */
    {PART_MODULE_UPDATE,       966 * 1024,          512, UFS_PART_3}, /* module_update       512KB p62 */
    {PART_EXT_RVT,     (966 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt               2MB p63 */
    {PART_RESERVED, (968 * 1024 + 512),(36 * 1024 + 512), UFS_PART_3}, /* reserved          36.5MB p64 */
    {PART_THEE,                1005 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p65 */
    {PART_TZSP,                1009 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p66 */
    {PART_RECOVERY_RAMDISK,    1021 * 1024,    40 * 1024, UFS_PART_3}, /* recovery_ramdisk    40MB p67 */
    {PART_RECOVERY_VENDOR,     1061 * 1024,    28 * 1024, UFS_PART_3}, /* recovery_vendor     28MB p68 */
#else
    {PART_ERECOVERY_RAMDISK,    744 * 1024,    32 * 1024, UFS_PART_3}, /* erecovery_ramdisk   32MB p57 */
    {PART_ERECOVERY_VENDOR,     776 * 1024,    28 * 1024, UFS_PART_3}, /* erecovery_vendor    28MB p58 */
    {PART_BOOT,                 804 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p59 */
    {PART_RECOVERY,             850 * 1024,    54 * 1024, UFS_PART_3}, /* recovery            54MB p60 */
    {PART_ERECOVERY,            904 * 1024,    54 * 1024, UFS_PART_3}, /* erecovery           54MB p61 */
    {PART_MODULE_UPDATE,        958 * 1024,          512, UFS_PART_3}, /* module_update      512KB p62 */
    {PART_EXT_RVT,      (958 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p63 */
    {PART_RESERVED, (960 * 1024 + 512),(52 * 1024 + 512), UFS_PART_3}, /* reserved          52.5MB p64 */
    {PART_THEE,                1013 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p65 */
    {PART_TZSP,                1017 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p66 */
    {PART_RECOVERY_RAMDISK,    1029 * 1024,    32 * 1024, UFS_PART_3}, /* recovery_ramdisk    32MB p67 */
    {PART_RECOVERY_VENDOR,     1061 * 1024,    28 * 1024, UFS_PART_3}, /* recovery_vendor     28MB p68 */
#endif
    {PART_ENG_SYSTEM,          1089 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p69 */
    {PART_ENG_VENDOR,          1101 * 1024,    20 * 1024, UFS_PART_3}, /* eng_vendor          20MB p70 */
    {PART_FW_DTB,              1121 * 1024,    16 * 1024, UFS_PART_3}, /* fw_dtb              16MB p71 */
    {PART_DTBO,                1137 * 1024,    16 * 1024, UFS_PART_3}, /* dtbo                16MB p72 */
    {PART_TRUSTFIRMWARE,       1153 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p73 */
    {PART_MODEM_FW,            1155 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p74 */
    {PART_MODEM_VENDOR,        1279 * 1024,    10 * 1024, UFS_PART_3}, /* modem_vendor        10MB p75 */
    {PART_MODEM_PATCH_NV,      1289 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p76 */
    {PART_MODEM_DRIVER,        1293 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p77 */
    {PART_MODEMNVM_UPDATE,     1313 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p78 */
    {PART_MODEMNVM_CUST,       1329 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust       16MB p79 */
    {PART_RAMDISK,             1345 * 1024,     2 * 1024, UFS_PART_3}, /* ramdisk              2MB p80 */
    {PART_VBMETA_SYSTEM,       1347 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_system     1024KB p81 */
    {PART_VBMETA_VENDOR,       1348 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_vendor     1024KB p82 */
    {PART_VBMETA_ODM,          1349 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_odm        1024KB p83 */
    {PART_VBMETA_CUST,         1350 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_cust       1024KB p84 */
    {PART_VBMETA_HW_PRODUCT,   1351 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_hw_product 1024KB p85 */
    {PART_RECOVERY_VBMETA,     1352 * 1024,     2 * 1024, UFS_PART_3}, /* recovery_vbmeta      2MB p86 */
    {PART_ERECOVERY_VBMETA,    1354 * 1024,     2 * 1024, UFS_PART_3}, /* erecovery_vbmeta     2MB p87 */
    {PART_VBMETA,              1356 * 1024,     4 * 1024, UFS_PART_3}, /* vbmeta               4MB p88 */
    {PART_KPATCH,              1360 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p89 */
    {PART_PATCH,               1364 * 1024,    32 * 1024, UFS_PART_3}, /* patch               32MB p90 */
#ifdef CONFIG_FACTORY_MODE
    {PART_PREAS,               1396 * 1024,    12 * 1024, UFS_PART_3}, /* preas               12MB p91 */
    {PART_PREAVS,              1408 * 1024,    12 * 1024, UFS_PART_3}, /* preavs              12MB p92 */
    {PART_SUPER,               1420 * 1024, 10728 * 1024, UFS_PART_3}, /* super            10728MB p93 */
    {PART_VERSION,            12148 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p94 */
    {PART_PRELOAD,            12724 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p95 */
    {PART_HIBENCH_IMG,        14124 * 1024,   128 * 1024, UFS_PART_3}, /* hibench_img        128MB p96 */
    {PART_HIBENCH_DATA,       14252 * 1024,   700 * 1024, UFS_PART_3}, /* hibench_data       700MB p97 */
    {PART_FLASH_AGEING,       14952 * 1024,   512 * 1024, UFS_PART_3}, /* flash_ageing       512MB p98 */
    {PART_HIBENCH_LOG,        15464 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p99 */
    {PART_XLOADER_HITEST,     15496 * 1024,     2 * 1024, UFS_PART_3}, /* xloader_hitest      2MB p100 */
    {PART_USERDATA,           15498 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata      8G p101 */
#elif defined CONFIG_MARKET_INTERNAL
#ifdef CONFIG_USE_EROFS
    {PART_PREAS,               1396 * 1024,    12 * 1024, UFS_PART_3}, /* preas               12MB p91 */
    {PART_PREAVS,              1408 * 1024,    12 * 1024, UFS_PART_3}, /* preavs              12MB p92 */
    {PART_SUPER,               1420 * 1024, 20226 * 1024, UFS_PART_3}, /* super            20226MB p93 */
    {PART_VERSION,            21646 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p94 */
    {PART_PRELOAD,            22222 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p95 */
    {PART_RESERVED6,          23622 * 1024,   506 * 1024, UFS_PART_3}, /* reserved6          506MB p96 */
    {PART_USERDATA,           24128 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p97 */
#else
    {PART_PREAS,               1396 * 1024,    12 * 1024, UFS_PART_3}, /* preas               12MB p91 */
    {PART_PREAVS,              1408 * 1024,    12 * 1024, UFS_PART_3}, /* preavs              12MB p92 */
    {PART_SUPER,               1420 * 1024, 21808 * 1024, UFS_PART_3}, /* super            21808MB p93 */
    {PART_VERSION,            23228 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p94 */
    {PART_PRELOAD,            23804 * 1024,  1144 * 1024, UFS_PART_3}, /* preload           1144MB p95 */
    {PART_USERDATA,           24948 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p96 */
#endif
#elif defined CONFIG_MARKET_OVERSEA
#ifdef CONFIG_USE_EROFS
    {PART_PREAS,               1396 * 1024,    12 * 1024, UFS_PART_3}, /* preas               12MB p91 */
    {PART_PREAVS,              1408 * 1024,    12 * 1024, UFS_PART_3}, /* preavs              12MB p92 */
    {PART_SUPER,               1420 * 1024, 19834 * 1024, UFS_PART_3}, /* super            19834MB p93 */
    {PART_VERSION,            21254 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p94 */
    {PART_PRELOAD,            21830 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p95 */
    {PART_USERDATA,           23230 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p96 */
#else /* end erofs */
    {PART_PREAS,               1396 * 1024,    12 * 1024, UFS_PART_3}, /* preas               12MB p91 */
    {PART_PREAVS,              1408 * 1024,    12 * 1024, UFS_PART_3}, /* preavs              12MB p92 */
    {PART_SUPER,               1420 * 1024, 22112 * 1024, UFS_PART_3}, /* super            22112MB p93 */
    {PART_VERSION,            23532 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p94 */
    {PART_PRELOAD,            24108 * 1024,  1144 * 1024, UFS_PART_3}, /* preload           1144MB p95 */
    {PART_USERDATA,           25252 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p96 */
#endif
#elif defined CONFIG_GCOV_PARTITION_SUPPORT_ENABLE
    {PART_PREAS,               1396 * 1024,    12 * 1024, UFS_PART_3}, /* preas               12MB p91 */
    {PART_PREAVS,              1408 * 1024,    12 * 1024, UFS_PART_3}, /* preavs              12MB p92 */
    {PART_SUPER,               1420 * 1024, 22412 * 1024, UFS_PART_3}, /* super            22412MB p93 */
    {PART_VERSION,            23832 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p94 */
    {PART_PRELOAD,            24408 * 1024,  1144 * 1024, UFS_PART_3}, /* preload           1144MB p95 */
    {PART_USERDATA,           25552 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p96 */
#else
    {PART_PREAS,               1396 * 1024,    12 * 1024, UFS_PART_3}, /* preas               12MB p91 */
    {PART_PREAVS,              1408 * 1024,    12 * 1024, UFS_PART_3}, /* preavs              12MB p92 */
    {PART_SUPER,               1420 * 1024, 22412 * 1024, UFS_PART_3}, /* super            22412MB p93 */
    {PART_VERSION,            23832 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p94 */
    {PART_PRELOAD,            24408 * 1024,  1144 * 1024, UFS_PART_3}, /* preload           1144MB p95 */
#if defined(CONFIG_PARTITION_ENG)
    {PART_FTTEST,             25552 * 1024,   192 * 1024, UFS_PART_3}, /* fttest             192MB p96 */
    {PART_DDRTEST,            25744 * 1024,    48 * 1024, UFS_PART_3}, /* ddrtest             48MB p97 */
    {PART_HITEST_GPU,         25792 * 1024,   512 * 1024, UFS_PART_3}, /* hitest_gpu         512MB p98 */
    {PART_HITEST_ASP_DHRYSTONE, 26304 * 1024,    20 * 1024, UFS_PART_3}, /* hitest_asp_dhrystone  20MB p99 */
    {PART_HITEST_ASP_TEST,    26324 * 1024,   300 * 1024, UFS_PART_3}, /* hitest_asp_test    300MB p100 */
    {PART_HITEST_SENSORHUB,   26624 * 1024,     6 * 1024, UFS_PART_3}, /* hitest_sensorhub     6MB p101 */
    {PART_HITEST_ISP,         26630 * 1024,    25 * 1024, UFS_PART_3}, /* hitest_isp          25MB p102 */
    {PART_HITEST_ISP_AVS,     26655 * 1024,    25 * 1024, UFS_PART_3}, /* hitest_isp_avs      25MB p103 */
    {PART_HITEST_NPU,         26680 * 1024,    80 * 1024, UFS_PART_3}, /* hitest_npu          80MB p104 */
    {PART_HITEST_DSS,         26760 * 1024,    18 * 1024, UFS_PART_3}, /* hitest_dss          18MB p105 */
    {PART_DSS_DISP_BUF,       26778 * 1024,    64 * 1024, UFS_PART_3}, /* dss_disp_buf        64MB p106 */
    {PART_HITEST_JPEGENC,     26842 * 1024,   200 * 1024, UFS_PART_3}, /* hitest_jpegenc     200MB p107 */
    {PART_HITEST_HIPP,        27042 * 1024,   100 * 1024, UFS_PART_3}, /* hitest_hipp        100MB p108 */
    {PART_HIBENCH_LPM3,       27142 * 1024,     2 * 1024, UFS_PART_3}, /* hibench_lpm3         2MB p109 */
    {PART_JPEG_DEC_TEST_SRC,  27144 * 1024,    20 * 1024, UFS_PART_3}, /* jpeg_dec_test_src   20MB p110 */
    {PART_JPEG_DEC_TEST_DEST, 27164 * 1024,    80 * 1024, UFS_PART_3}, /* jpeg_dec_test_dest  80MB p111 */
    {PART_VCODE_DATA,         27244 * 1024,   140 * 1024, UFS_PART_3}, /* vcode_data         140MB p112 */
    {PART_HITEST_FFRT,        27384 * 1024,    20 * 1024, UFS_PART_3}, /* hitest_ffrt         20MB p113 */
    {PART_VCODE_MAX_DATA,     27404 * 1024,   140 * 1024, UFS_PART_3}, /* vcode_max_data     140MB p114 */
    {PART_MODEM_TSP_TEST,     27544 * 1024,    32 * 1024, UFS_PART_3}, /* modem_tsp_test      32MB p115 */
    {PART_MODEM_MTEE,         27576 * 1024,     4 * 1024, UFS_PART_3}, /* modem_mtee           4MB p116 */
    {PART_MODEM_VECTOR_CONFIG, 27580 * 1024,     4 * 1024, UFS_PART_3}, /* modem_vector_config   4MB p117 */
    {PART_MODEM_TSP_DT,       27584 * 1024,     1 * 1024, UFS_PART_3}, /* modem_tsp_dt      1024KB p118 */
    {PART_MODEM_L2DLE,        27585 * 1024,     2 * 1024, UFS_PART_3}, /* modem_l2dle          2MB p119 */
    {PART_MODEM_L2DLE_TEST,   27587 * 1024,     2 * 1024, UFS_PART_3}, /* modem_l2dle_test     2MB p120 */
    {PART_MODEM_BBP_TEST,     27589 * 1024,   100 * 1024, UFS_PART_3}, /* modem_bbp_test     100MB p121 */
    {PART_MODEM_PSA_TEST,     27689 * 1024,    20 * 1024, UFS_PART_3}, /* modem_psa_test      20MB p122 */
    {PART_MODEM_PDE_TEST,     27709 * 1024,     5 * 1024, UFS_PART_3}, /* modem_pde_test       5MB p123 */
    {PART_XLOADER_HITEST,     27714 * 1024,     2 * 1024, UFS_PART_3}, /* xloader_hitest       2MB p124 */
    {PART_HITEST_OISP,        27716 * 1024,    26 * 1024, UFS_PART_3}, /* hitest_oisp         26MB p125 */
#ifdef CONFIG_BOOT_METALBOX
    {PART_METALBOX,           27742 * 1024,     4 * 1024, UFS_PART_3}, /* metalbox             4MB p126 */
    {PART_SLICES,             27746 * 1024,(32UL) * 1024 * 1024, UFS_PART_3}, /* slices    32768MB p127 */
    {PART_USERDATA,           60514 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p128 */
#else
    {PART_USERDATA,           27742 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p126 */
#endif // CONFIG_BOOT_METALBOX
#else
    {PART_USERDATA,           25552 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p96 */
#endif
#endif
    {"0", 0, 0, 0},
};

#endif
