#ifndef _CHENGDU_PLAT_PARTITION_H_
#define _CHENGDU_PLAT_PARTITION_H_

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
    {PART_FRP,                 512,          512, UFS_PART_2}, /* frp                512KB p1 */
    {PART_PERSIST,                1 * 1024,       6 * 1024,    UFS_PART_2}, /* persist         6144K    p2 */
    {PART_RESERVED1,             7 * 1024,         1024, UFS_PART_2}, /* reserved1         1024KB p3 */
    {PART_PTABLE_LU3,             0,                   512,    UFS_PART_3}, /* ptable_lu3       512K    p0 */
    {PART_VRL,                 512,          512, UFS_PART_3}, /* vrl                512KB p1 */
    {PART_VRL_BACKUP,                1024,          512, UFS_PART_3}, /* vrl_backup         512KB p2 */
    {PART_MODEM_SECURE,              1536,         8704, UFS_PART_3}, /* modem_secure      8704KB p3 */
    {PART_NVME,                 10 * 1024,     4 * 1024, UFS_PART_3}, /* nvme                 4MB p4 */
    {PART_CONN_CALIDATA,        14 * 1024,         1024, UFS_PART_3}, /* conn_calidata     1024KB p5 */
    {PART_CTF,                  15 * 1024,     1 * 1024, UFS_PART_3}, /* ctf               1024KB p6 */
    {PART_OEMINFO,              16 * 1024,    96 * 1024, UFS_PART_3}, /* oeminfo             96MB p7 */
    {PART_SECURE_STORAGE,      112 * 1024,    32 * 1024, UFS_PART_3}, /* secure_storage      32MB p8 */
    {PART_MODEMNVM_FACTORY,    144 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_factory    16MB p9 */
    {PART_MODEMNVM_BACKUP,     160 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_backup     16MB p10 */
    {PART_MODEMNVM_IMG,        176 * 1024,    46 * 1024, UFS_PART_3}, /* modemnvm_img        46MB p11 */
    {PART_HISEE_ENCOS,         222 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_encos          4MB p12 */
    {PART_VERITYKEY,           226 * 1024,     1 * 1024, UFS_PART_3}, /* veritykey         1024KB p13 */
    {PART_DDR_PARA,            227 * 1024,     1 * 1024, UFS_PART_3}, /* ddr_para          1024KB p14 */
    {PART_LOWPOWER_PARA,       228 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para     1024KB p15 */
    {PART_BATT_TP_PARA,        229 * 1024,     1 * 1024, UFS_PART_3}, /* batt_tp_para      1024KB p16 */
    {PART_PANEL_CALIBRATION,   230 * 1024,   100 * 1024, UFS_PART_3}, /* panel_calibration  100MB p17 */
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
    {PART_FW_CPU_LPCTRL,       (596 * 1024 + 512),  256, UFS_PART_3}, /* fw_cpu_lpctrl      256K    p30 */
    {PART_FW_GPU_LPCTRL,       (596 * 1024 + 768),  128, UFS_PART_3}, /* fw_gpu_lpctrl      128K    p31 */
    {PART_FW_DDR_LPCTRL,       (596 * 1024 + 896),  320, UFS_PART_3}, /* fw_ddr_lpctrl      320K    p32 */
    {PART_DDR_XPU_BOOT0,       (597 * 1024 + 192),  320, UFS_PART_3}, /* ddr_xpu_boot0      320KB p33 */
    {PART_DDR_XPU_BOOT1,       (597 * 1024 + 512),  320, UFS_PART_3}, /* ddr_xpu_boot1      320KB  p34 */
    {PART_DDR_XPU_BOOT2,       (597 * 1024 + 832),  320, UFS_PART_3}, /* ddr_xpu_boot2      320KB  p35 */
    {PART_UCE,                 (598 * 1024 + 128),  160, UFS_PART_3}, /* uce                160KB  p36 */
    {PART_FW_MEDIA_LPCTRL,     (598 * 1024 + 288),  128, UFS_PART_3}, /* fw_media_lpctrl    128KB  p37 */
    {PART_DDR_FAC_INFO,        (598 * 1024 + 416),  1 * 1024, UFS_PART_3}, /* ddr_fac_info        1024KB p38 */
    {PART_DVFS,                (599 * 1024 + 416),  1 * 1024, UFS_PART_3}, /* dvfs          1024KB p39 */
    {PART_RESERVED4,           (600 * 1024 + 416),  4 * 1024 + 608, UFS_PART_3}, /* reserved4   5984KB p40 */
    {PART_NPU,                  605 * 1024,     8 * 1024, UFS_PART_3}, /* npu                  8MB p41 */
    {PART_IVP,                  613 * 1024,     2 * 1024, UFS_PART_3}, /* ivp                  2MB p42 */
    {PART_DACC,                 615 * 1024,          256, UFS_PART_3}, /* dacc               512KB p43 */
    {PART_DACC_AAE,            (615 * 1024 + 256),   256, UFS_PART_3}, /* dacc_aae           512KB p43 */
    {PART_VENC,                (615 * 1024 + 512),   512, UFS_PART_3}, /* venc               512KB p44 */
    {PART_HISEE_IMG,            616 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p45 */
    {PART_HHEE,                 620 * 1024,     4 * 1024, UFS_PART_3}, /* hhee                 4MB p46 */
    {PART_HISEE_FS,             624 * 1024,     8 * 1024, UFS_PART_3}, /* hisee_fs             8MB p47 */
    {PART_FASTBOOT,             632 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p48 */
    {PART_VECTOR,               644 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p49 */
    {PART_ISP_BOOT,             648 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot             2MB p50 */
    {PART_ISP_FIRMWARE,         650 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware        14MB p51 */
    {PART_FW_HIFI,              664 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi             12MB p52 */
    {PART_TEEOS,                676 * 1024,     8 * 1024, UFS_PART_3}, /* teeos                8MB p53 */
    {PART_SENSORHUB,            684 * 1024,    13 * 1024, UFS_PART_3}, /* sensorhub           13MB p54 */
    {PART_SENSORHUB_LOG_DIC,    697 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p55 */
    {PART_HKRR,                 700 * 1024,    16 * 1024, UFS_PART_3}, /* hkrr                16MB p56 */
    {PART_FW_UFSDEV,            716 * 1024,     4 * 1024, UFS_PART_3}, /* fw_ufsdev            4MB p57 */
    {PART_FW_DFA,               720 * 1024,     1 * 1024, UFS_PART_3}, /* fw_dfa            1024KB p58 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK,    721 * 1024,    12 * 1024, UFS_PART_3}, /* erecovery_ramdisk   12MB p59 */
    {PART_ERECOVERY_VENDOR,     733 * 1024,     8 * 1024, UFS_PART_3}, /* erecovery_vendor     8MB p60 */
    {PART_BOOT,                 741 * 1024,    81 * 1024, UFS_PART_3}, /* boot                81MB p61 */
    {PART_RECOVERY,             822 * 1024,    85 * 1024, UFS_PART_3}, /* recovery            85MB p62 */
    {PART_ERECOVERY,            907 * 1024,    12 * 1024, UFS_PART_3}, /* erecovery           12MB p63 */
    {PART_MODULE_UPDATE,        919 * 1024,          512, UFS_PART_3}, /* module_update      512KB p64 */
    {PART_EXT_RVT,      (919 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p65 */
    {PART_RESERVED,     (921 * 1024 + 512),   (69 * 1024 + 512), UFS_PART_3}, /* reserved   69.5MB p66 */
    {PART_THEE,                 991 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p67 */
    {PART_TZSP,                 995 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p68 */
    {PART_RECOVERY_RAMDISK,    1007 * 1024,    32 * 1024, UFS_PART_3}, /* recovery_ramdisk    32MB p69 */
    {PART_RECOVERY_VENDOR,     1039 * 1024,    24 * 1024, UFS_PART_3}, /* recovery_vendor     24MB p70 */
#elif defined CONFIG_HWSANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK,    721 * 1024,    40 * 1024, UFS_PART_3}, /* erecovery_ramdisk   40MB p59 */
    {PART_ERECOVERY_VENDOR,     761 * 1024,    24 * 1024, UFS_PART_3}, /* erecovery_vendor    24MB p60 */
    {PART_BOOT,                 785 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p61 */
    {PART_RECOVERY,             831 * 1024,    45 * 1024, UFS_PART_3}, /* recovery            45MB p62 */
    {PART_ERECOVERY,            876 * 1024,    45 * 1024, UFS_PART_3}, /* erecovery           45MB p63 */
    {PART_MODULE_UPDATE,        921 * 1024,          512, UFS_PART_3}, /* module_update      512KB p64 */
    {PART_EXT_RVT,      (921 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p65 */
    {PART_RESERVED,     (923 * 1024 + 512),    (59 * 1024 + 512), UFS_PART_3}, /* reserved  59.5MB p66 */
    {PART_THEE,                 983 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p67 */
    {PART_TZSP,                 987 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p68 */
    {PART_RECOVERY_RAMDISK,     999 * 1024,    40 * 1024, UFS_PART_3}, /* recovery_ramdisk    40MB p69 */
    {PART_RECOVERY_VENDOR,     1039 * 1024,    24 * 1024, UFS_PART_3}, /* recovery_vendor     24MB p70 */
#else
    {PART_ERECOVERY_RAMDISK,    721 * 1024,    32 * 1024, UFS_PART_3}, /* erecovery_ramdisk   32MB p59 */
    {PART_ERECOVERY_VENDOR,     753 * 1024,    24 * 1024, UFS_PART_3}, /* erecovery_vendor    24MB p60 */
    {PART_BOOT,                 777 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p61 */
    {PART_RECOVERY,             823 * 1024,    45 * 1024, UFS_PART_3}, /* recovery            45MB p62 */
    {PART_ERECOVERY,            868 * 1024,    45 * 1024, UFS_PART_3}, /* erecovery           45MB p63 */
    {PART_MODULE_UPDATE,        913 * 1024,          512, UFS_PART_3}, /* module_update      512KB p64 */
    {PART_EXT_RVT,      (913 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p65 */
    {PART_RESERVED,     (915 * 1024 + 512),    (75 * 1024 + 512), UFS_PART_3}, /* reserved  75.5MB p66 */
    {PART_THEE,                 991 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p67 */
    {PART_TZSP,                 995 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p68 */
    {PART_RECOVERY_RAMDISK,    1007 * 1024,    32 * 1024, UFS_PART_3}, /* recovery_ramdisk    32MB p69 */
    {PART_RECOVERY_VENDOR,     1039 * 1024,    24 * 1024, UFS_PART_3}, /* recovery_vendor     24MB p70 */
#endif
    {PART_ENG_SYSTEM,          1063 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p71 */
    {PART_ENG_VENDOR,          1075 * 1024,    20 * 1024, UFS_PART_3}, /* eng_vendor          20MB p72 */
    {PART_FW_DTB,              1095 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb               8MB p73 */
    {PART_DTBO,                1103 * 1024,    14 * 1024, UFS_PART_3}, /* dtbo                14MB p74 */
    {PART_TRUSTFIRMWARE,       1117 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p75 */
    {PART_DPA_VENDOR,          1119 * 1024,    32 * 1024, UFS_PART_3}, /* dpa_vendor          32MB p76 */
    {PART_MODEM_FW,            1151 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p77 */
    {PART_MODEM_VENDOR,        1275 * 1024,    10 * 1024, UFS_PART_3}, /* modem_vendor        10MB p78 */
    {PART_MODEM_PATCH_NV,      1285 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p79 */
    {PART_MODEM_DRIVER,        1289 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p80 */
    {PART_MODEMNVM_UPDATE,     1309 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p81 */
    {PART_MODEMCONFIG_CUST,    1325 * 1024,    16 * 1024, UFS_PART_3}, /* modemconfig_cust    16MB p82 */
    {PART_RAMDISK,             1341 * 1024,     2 * 1024, UFS_PART_3}, /* ramdisk              2MB p83 */
    {PART_VBMETA_SYSTEM,       1343 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_system     1024KB p84 */
    {PART_VBMETA_VENDOR,       1344 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_vendor     1024KB p85 */
    {PART_VBMETA_ODM,          1345 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_odm        1024KB p86 */
    {PART_VBMETA_CUST,         1346 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_cust       1024KB p87 */
    {PART_VBMETA_HW_PRODUCT,   1347 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_hw_product 1024KB p88 */
    {PART_RECOVERY_VBMETA,     1348 * 1024,     2 * 1024, UFS_PART_3}, /* recovery_vbmeta      2MB p89 */
    {PART_ERECOVERY_VBMETA,    1350 * 1024,     2 * 1024, UFS_PART_3}, /* erecovery_vbmeta     2MB p90 */
    {PART_VBMETA,              1352 * 1024,     4 * 1024, UFS_PART_3}, /* vbmeta               4MB p91 */
    {PART_KPATCH,              1356 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p92 */
    {PART_PATCH,               1360 * 1024,    32 * 1024, UFS_PART_3}, /* patch               32MB p93 */
#ifdef CONFIG_FACTORY_MODE
    {PART_PREAS,               1392 * 1024,   368 * 1024, UFS_PART_3}, /* preas              368MB p94 */
    {PART_PREAVS,              1760 * 1024,    32 * 1024, UFS_PART_3}, /* preavs              32MB p95 */
    {PART_SUPER,               1792 * 1024,  9656 * 1024, UFS_PART_3}, /* super             9656MB p96 */
    {PART_VERSION,            11448 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p97 */
    {PART_PRELOAD,            12024 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p98 */
    {PART_HIBENCH_IMG,        13424 * 1024,    12 * 1024, UFS_PART_3}, /* hibench_img         12MB p99 */
    {PART_HIBENCH_DATA,       13436 * 1024,  2048 * 1024, UFS_PART_3}, /* hibench_data      2048 * 1024KB p100 */
    {PART_HIBENCH_LOG,        15484 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p101 */
    {PART_XLOADER_HITEST,     15516 * 1024,     2 * 1024, UFS_PART_3}, /* xloader_hitest       2MB p102 */
    {PART_FLASH_AGEING,       15518 * 1024,   512 * 1024, UFS_PART_3}, /* flash_ageing       512MB p103 */
    {PART_USERDATA,           16030 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p104 */
#elif defined CONFIG_MARKET_INTERNAL
#ifdef CONFIG_USE_EROFS
    {PART_PREAS,               1392 * 1024,   296 * 1024, UFS_PART_3}, /* preas              296MB p94 */
    {PART_PREAVS,              1688 * 1024,    32 * 1024, UFS_PART_3}, /* preavs              32MB p95 */
    {PART_SUPER,               1720 * 1024,  8322 * 1024, UFS_PART_3}, /* super             8322MB p96 */
    {PART_VERSION,            10042 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p97 */
    {PART_PRELOAD,            10618 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p98 */
    {PART_USERDATA,           12018 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p99 */
#else
    {PART_PREAS,               1392 * 1024,   368 * 1024, UFS_PART_3}, /* preas              368MB p94 */
    {PART_PREAVS,              1760 * 1024,    32 * 1024, UFS_PART_3}, /* preavs              32MB p95 */
    {PART_SUPER,               1792 * 1024, 10208 * 1024, UFS_PART_3}, /* super             10208MB p96 */
    {PART_VERSION,            12000 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p97 */
    {PART_PRELOAD,            12576 * 1024,  1144 * 1024, UFS_PART_3}, /* preload           1144MB p98 */
    {PART_USERDATA,           13720 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p99 */
#endif
#elif defined CONFIG_MARKET_OVERSEA
#ifdef CONFIG_USE_EROFS
    {PART_PREAS,               1392 * 1024,  1024 * 1024, UFS_PART_3}, /* preas             1024 * 1024KB p94 */
    {PART_PREAVS,              2416 * 1024,    32 * 1024, UFS_PART_3}, /* preavs              32MB p95 */
    {PART_SUPER,               2448 * 1024,  8282 * 1024, UFS_PART_3}, /* super             8282MB p96 */
    {PART_VERSION,            10730 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p97 */
    {PART_PRELOAD,            11306 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p98 */
    {PART_USERDATA,           12706 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p99 */
#else /* end erofs */
    {PART_PREAS,               1392 * 1024,  1280 * 1024, UFS_PART_3}, /* preas             1280MB p94 */
    {PART_PREAVS,              2672 * 1024,    32 * 1024, UFS_PART_3}, /* preavs              32MB p95 */
    {PART_SUPER,               2704 * 1024, 10688 * 1024, UFS_PART_3}, /* super             10688MB p96 */
    {PART_VERSION,            13392 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p97 */
    {PART_PRELOAD,            13968 * 1024,  1144 * 1024, UFS_PART_3}, /* preload           1144MB p98 */
    {PART_USERDATA,           15112 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p99 */
#endif
#elif defined CONFIG_GCOV_PARTITION_SUPPORT_ENABLE
    {PART_PREAS,               1392 * 1024,    32 * 1024, UFS_PART_3}, /* preas               32MB p94 */
    {PART_PREAVS,              1424 * 1024,    32 * 1024, UFS_PART_3}, /* preavs              32MB p95 */
    {PART_SUPER,               1456 * 1024, 10688 * 1024, UFS_PART_3}, /* super             10688MB p96 */
    {PART_VERSION,            12144 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p97 */
    {PART_PRELOAD,            12720 * 1024,  1144 * 1024, UFS_PART_3}, /* preload           1144MB p98 */
    {PART_USERDATA,           13864 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p99 */
#else
    {PART_PREAS,               1392 * 1024,  1280 * 1024, UFS_PART_3}, /* preas             1280MB p94 */
    {PART_PREAVS,              2672 * 1024,    32 * 1024, UFS_PART_3}, /* preavs              32MB p95 */
    {PART_SUPER,               2704 * 1024, 10688 * 1024, UFS_PART_3}, /* super             10688MB p96 */
    {PART_VERSION,            13392 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p97 */
    {PART_PRELOAD,            13968 * 1024,  1144 * 1024, UFS_PART_3}, /* preload           1144MB p98 */
#if defined(CONFIG_PARTITION_ENG)
    {PART_FTTEST,             15112 * 1024,    12 * 1024, UFS_PART_3}, /* fttest              12MB p99 */
    {PART_XLOADER_HITEST,     15124 * 1024,     2 * 1024, UFS_PART_3}, /* xloader_hitest       2MB p100 */
    {PART_DDRTEST,            15126 * 1024,    48 * 1024, UFS_PART_3}, /* ddrtest             48MB p101 */
    {PART_HITEST_GPU,         15174 * 1024,   512 * 1024, UFS_PART_3}, /* hitest_gpu         512MB p102 */
    {PART_HITEST_CPU,         15686 * 1024,    50 * 1024, UFS_PART_3}, /* hitest_cpu          50MB p103 */
    {PART_VCODE_DATA,         15736 * 1024,   180 * 1024, UFS_PART_3}, /* vcode_data         180MB p104 */
    {PART_VCODE_MAX_DATA,     15916 * 1024,   160 * 1024, UFS_PART_3}, /* vcode_max_data     160MB p105 */
    {PART_JPEG_DEC_TEST_SRC,  16076 * 1024,    20 * 1024, UFS_PART_3}, /* jpeg_dec_test_src   20MB p106 */
    {PART_JPEG_DEC_TEST_DEST, 16096 * 1024,    80 * 1024, UFS_PART_3}, /* jpeg_dec_test_dest  80MB p107 */
    {PART_HITEST_ISP,         16176 * 1024,    25 * 1024, UFS_PART_3}, /* hitest_isp          25MB p108 */
    {PART_HITEST_ISP_AVS,     16201 * 1024,    65 * 1024, UFS_PART_3}, /* hitest_isp_avs      65MB p109 */
    {PART_HITEST_HIPP,        16266 * 1024,   100 * 1024, UFS_PART_3}, /* hitest_hipp        100MB p110 */
    {PART_HITEST_OISP,        16366 * 1024,    10 * 1024, UFS_PART_3}, /* hitest_oisp         10MB p111 */
    {PART_DSS_DISP_BUF,       16376 * 1024,   128 * 1024, UFS_PART_3}, /* dss_disp_buf       128MB p112 */
    {PART_HITEST_ASP_DHRYSTONE, 16504 * 1024,    20 * 1024, UFS_PART_3}, /* hitest_asp_dhrystone  20MB p113 */
    {PART_HITEST_ASP_TEST,    16524 * 1024,   300 * 1024, UFS_PART_3}, /* hitest_asp_test    300MB p114 */
    {PART_HITEST_SENSORHUB,   16824 * 1024,     6 * 1024, UFS_PART_3}, /* hitest_sensorhub     6MB p115 */
    {PART_HITEST_NPU,         16830 * 1024,    20 * 1024, UFS_PART_3}, /* hitest_npu          20MB p116 */
    {PART_MODEM_IMG_TEST,      16850 * 1024,    230 * 1024, UFS_PART_3}, /* modem_img_test      230MB p117 */
    {PART_HITEST_JPEGENC,      17080 * 1024,   260 * 1024, UFS_PART_3}, /* hitest_jpegenc          260MB p118 */
    {PART_HITEST_DATA,         17340 * 1024,   2228 * 1024, UFS_PART_3}, /* hitest_data          2228MB p119 */
    {PART_DISP_PANEL_INFO,     19568 * 1024,    20 * 1024, UFS_PART_3}, /* disp_panel_info         20MB p120 */
#ifdef CONFIG_BOOT_METALBOX
    {PART_METALBOX,           19588 * 1024,     4 * 1024, UFS_PART_3}, /* metalbox             4MB p121 */
    {PART_SLICES,             19592 * 1024,(32UL) * 1024 * 1024, UFS_PART_3},/* slices            32768MB p122 */
    {PART_USERDATA,           52360 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p123 */
#else
    {PART_USERDATA,           19588 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p120 */
#endif // CONFIG_BOOT_METALBOX
#else
    {PART_USERDATA,           15112 * 1024, (8UL) * 1024 * 1024, UFS_PART_3}, /* userdata       8G p99 */
#endif
#endif
    {"0", 0, 0, 0},
};

#endif
