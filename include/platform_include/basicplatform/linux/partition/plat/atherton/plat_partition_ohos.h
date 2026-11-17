/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * Description: the partition table.
 */

#ifndef _SCORPIO_PARTITION_H_
#define _SCORPIO_PARTITION_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {PART_XLOADER,                0,             2 * 1024,    EMMC_BOOT_MAJOR_PART},
    {PART_RESERVED0,              0,             2 * 1024,    EMMC_BOOT_BACKUP_PART},
    {PART_PTABLE,                 0,                  512,    EMMC_USER_PART}, /* ptable           512K    p0 */
    {PART_FRP,                                512,   512, EMMC_USER_PART}, /* frp                512KB p1 */
    {PART_PERSIST,                    1024,     6 * 1024, EMMC_USER_PART}, /* persist              6MB p2 */
    {PART_RESERVED1,              7 * 1024,         1536, EMMC_USER_PART}, /* reserved1         1536KB p3 */
    {PART_VRL,               (8 * 1024 + 512),          512, EMMC_USER_PART}, /* vrl                512KB p4 */
    {PART_VRL_BACKUP,             9 * 1024,          512, EMMC_USER_PART}, /* vrl_backup         512KB p5 */
    {PART_MODEM_SECURE,      (9 * 1024 + 512),         8704, EMMC_USER_PART}, /* modem_secure      8704KB p6 */
    {PART_NVME,                  18 * 1024,     5 * 1024, EMMC_USER_PART}, /* nvme                 5MB p7 */
    {PART_CTF,                   23 * 1024,     1 * 1024, EMMC_USER_PART}, /* ctf               1024KB p8 */
    {PART_OEMINFO,               24 * 1024,    96 * 1024, EMMC_USER_PART}, /* oeminfo             96MB p9 */
    {PART_SECURE_STORAGE,       120 * 1024,    32 * 1024, EMMC_USER_PART}, /* secure_storage      32MB p10 */
    {PART_MODEMNVM_FACTORY,     152 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_factory    16MB p11 */
    {PART_MODEMNVM_BACKUP,      168 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_backup     16MB p12 */
    {PART_MODEMNVM_IMG,         184 * 1024,    46 * 1024, EMMC_USER_PART}, /* modemnvm_img        46MB p13 */
    {PART_HISEE_ENCOS,          230 * 1024,     4 * 1024, EMMC_USER_PART}, /* hisee_encos          4MB p14 */
    {PART_VERITYKEY,            234 * 1024,     1 * 1024, EMMC_USER_PART}, /* veritykey         1024KB p15 */
    {PART_DDR_PARA,             235 * 1024,     1 * 1024, EMMC_USER_PART}, /* ddr_para          1024KB p16 */
    {PART_LOWPOWER_PARA,        236 * 1024,     1 * 1024, EMMC_USER_PART}, /* lowpower_para     1024KB p17 */
    {PART_BATT_TP_PARA,         237 * 1024,     1 * 1024, EMMC_USER_PART}, /* batt_tp_para      1024KB p18 */
    {PART_DACC,                 238 * 1024,          512, EMMC_USER_PART}, /* dacc               512KB p19 */
    {PART_RESERVED2,         (238 * 1024 + 512),(20 * 1024+512), EMMC_USER_PART}, /* reserved2         20992KB p20 */
    {PART_LOG,                  259 * 1024,    80 * 1024, EMMC_USER_PART}, /* log                 80MB p21 */
    {PART_BOOTFAIL_INFO,        339 * 1024,     2 * 1024, EMMC_USER_PART}, /* bootfail_info        2MB p22 */
    {PART_MISC,                 341 * 1024,     2 * 1024, EMMC_USER_PART}, /* misc                 2MB p23 */
    {PART_DFX,                  343 * 1024,    16 * 1024, EMMC_USER_PART}, /* dfx                 16MB p24 */
    {PART_RRECORD,              359 * 1024,    16 * 1024, EMMC_USER_PART}, /* rrecord             16MB p25 */
    {PART_CACHE,                375 * 1024,   104 * 1024, EMMC_USER_PART}, /* cache              104MB p26 */
    {PART_METADATA,             479 * 1024,    16 * 1024, EMMC_USER_PART}, /* metadata            16MB p27 */
    {PART_FW_EMMCDEV,           495 * 1024,     4 * 1024, EMMC_USER_PART}, /* fw_emmcdev           4MB p28 */
    {PART_TOC,                  499 * 1024,     1 * 1024, EMMC_USER_PART}, /* toc               1024KB p29 */
    {PART_BL2,                  500 * 1024,     4 * 1024, EMMC_USER_PART}, /* bl2                  4MB p30 */
    {PART_FW_LPM3,              504 * 1024,          512, EMMC_USER_PART}, /* fw_lpm3            512KB p31 */
    {PART_FW_CPU_LPCTRL,     (504 * 1024 + 512),          256, EMMC_USER_PART}, /* fw_cpu_lpctrl      256KB p32 */
    {PART_FW_GPU_LPCTRL,     (504 * 1024 + 768),          128, EMMC_USER_PART}, /* fw_gpu_lpctrl      128KB p33 */
    {PART_FW_DDR_LPCTRL,     (504 * 1024 + 896),          128, EMMC_USER_PART}, /* fw_ddr_lpctrl      128KB p34 */
    {PART_NPU,                  505 * 1024,     8 * 1024, EMMC_USER_PART}, /* npu                  8MB p35 */
    {PART_IVP,                  513 * 1024,     2 * 1024, EMMC_USER_PART}, /* ivp                  2MB p36 */
    {PART_HDCP,                 515 * 1024,     1 * 1024, EMMC_USER_PART}, /* hdcp              1024KB p37 */
    {PART_HISEE_IMG,            516 * 1024,     4 * 1024, EMMC_USER_PART}, /* hisee_img            4MB p38 */
    {PART_HHEE,                 520 * 1024,     4 * 1024, EMMC_USER_PART}, /* hhee                 4MB p39 */
    {PART_HISEE_FS,             524 * 1024,     8 * 1024, EMMC_USER_PART}, /* hisee_fs             8MB p40 */
    {PART_FASTBOOT,             532 * 1024,    12 * 1024, EMMC_USER_PART}, /* fastboot            12MB p41 */
    {PART_VECTOR,               544 * 1024,     4 * 1024, EMMC_USER_PART}, /* vector               4MB p42 */
    {PART_ISP_BOOT,             548 * 1024,     2 * 1024, EMMC_USER_PART}, /* isp_boot             2MB p43 */
    {PART_ISP_FIRMWARE,         550 * 1024,    14 * 1024, EMMC_USER_PART}, /* isp_firmware        14MB p44 */
    {PART_FW_HIFI,              564 * 1024,    12 * 1024, EMMC_USER_PART}, /* fw_hifi             12MB p45 */
    {PART_TEEOS,                576 * 1024,     8 * 1024, EMMC_USER_PART}, /* teeos                8MB p46 */

#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, EMMC_USER_PART}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    28 * 1024, EMMC_USER_PART}, /* updater_vendor_bak  28MB p48 */
    {PART_BOOT,                 644 * 1024,    48 * 1024, EMMC_USER_PART}, /* boot                48MB p49 */
    {PART_UPDATER_BOOT,         692 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     746 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        800 * 1024,          512, EMMC_USER_PART}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (800 * 1024 + 512),     2 * 1024, EMMC_USER_PART}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (802 * 1024 + 512),(50 * 1024+512), EMMC_USER_PART}, /* reserved3         51712KB p54 */
    {PART_THEE,                 853 * 1024,     4 * 1024, EMMC_USER_PART}, /* thee                 4MB p55 */
    {PART_TZSP,                 857 * 1024,    12 * 1024, EMMC_USER_PART}, /* tzsp                12MB p56 */
    {PART_UPDATER_RAMDISK,      869 * 1024,    32 * 1024, EMMC_USER_PART}, /* updater_ramdisk     32MB p57 */
    {PART_UPDATER_VENDOR,       901 * 1024,    28 * 1024, EMMC_USER_PART}, /* updater_vendor      28MB p58 */
    {PART_ENG_SYSTEM,           929 * 1024,    12 * 1024, EMMC_USER_PART}, /* eng_system          12MB p59 */
    {PART_ENG_CHIPSET,          941 * 1024,    20 * 1024, EMMC_USER_PART}, /* eng_chipset         20MB p60 */
    {PART_FW_DTB,               961 * 1024,     8 * 1024, EMMC_USER_PART}, /* fw_dtb               8MB p61 */
    {PART_DTBO,                 969 * 1024,    14 * 1024, EMMC_USER_PART}, /* dtbo                14MB p62 */
    {PART_TRUSTFIRMWARE,        983 * 1024,     2 * 1024, EMMC_USER_PART}, /* trustfirmware        2MB p63 */
    {PART_MODEM_FW,             985 * 1024,   124 * 1024, EMMC_USER_PART}, /* modem_fw           124MB p64 */
    {PART_MODEM_VENDOR,        1109 * 1024,    30 * 1024, EMMC_USER_PART}, /* modem_vendor        30MB p65 */
    {PART_MODEM_PATCH_NV,      1139 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_patch_nv       4MB p66 */
    {PART_MODEM_DRIVER,        1143 * 1024,    20 * 1024, EMMC_USER_PART}, /* modem_driver        20MB p67 */
    {PART_MODEMNVM_UPDATE,     1163 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_update     16MB p68 */
    {PART_MODEMNVM_CUST,       1179 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_cust       16MB p69 */
    {PART_RAMDISK,             1195 * 1024,     4 * 1024, EMMC_USER_PART}, /* ramdisk              4MB p70 */
    {PART_RVT_SYSTEM,          1199 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_system        1024KB p71 */
    {PART_RVT_VENDOR,          1200 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_vendor        1024KB p72 */
    {PART_RVT_CHIP_PROD,       1201 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_chip_prod     1024KB p73 */
    {PART_RVT_CUST,            1202 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_cust          1024KB p74 */
    {PART_RVT_SYS_PROD,        1203 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_sys_prod      1024KB p75 */
    {PART_UPDATER_RVT,         1204 * 1024,     2 * 1024, EMMC_USER_PART}, /* updater_rvt          2MB p76 */
    {PART_UPDATER_BAK_RVT,     1206 * 1024,     2 * 1024, EMMC_USER_PART}, /* updater_bak_rvt      2MB p77 */
    {PART_RVT,                 1208 * 1024,     4 * 1024, EMMC_USER_PART}, /* rvt                  4MB p78 */
    {PART_KPATCH,              1212 * 1024,     4 * 1024, EMMC_USER_PART}, /* kpatch               4MB p79 */
    {PART_PATCH,               1216 * 1024,    32 * 1024, EMMC_USER_PART}, /* patch               32MB p80 */
    {PART_RESERVED5,           1248 * 1024,     2 * 1024, EMMC_USER_PART}, /* reserved5            2MB p81 */

    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, EMMC_USER_PART}, /* sensorhub          597MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, EMMC_USER_PART}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1850 * 1024,   600 * 1024, EMMC_USER_PART}, /* chip_prod          600MB p84 */
    {PART_VENDOR,              2450 * 1024,  1024 * 1024, EMMC_USER_PART}, /* vendor            1024 * 1024KB p85 */
    {PART_SYS_PROD,            3474 * 1024,   600 * 1024, EMMC_USER_PART}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              4074 * 1024,  3666 * 1024, EMMC_USER_PART}, /* system            3666MB p87 */
    {PART_CUST,                7740 * 1024,    88 * 1024, EMMC_USER_PART}, /* cust                88MB p88 */
    {PART_VERSION,             7828 * 1024,   200 * 1024, EMMC_USER_PART}, /* version            200MB p89 */
    {PART_PRELOAD,             8028 * 1024,   520 * 1024, EMMC_USER_PART}, /* preload            520MB p90 */
    {PART_SENSORHUB_SYSTEM,    8548 * 1024,  1536 * 1024, EMMC_USER_PART}, /* sensorhub_system  1536MB p91 */
    {PART_SENSORHUB_DATA,     10084 * 1024,  6656 * 1024, EMMC_USER_PART}, /* sensorhub_data    6656MB p92 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      16740 * 1024,     2 * 1024, EMMC_USER_PART}, /* conn_calidata        2MB p93 */
    {PART_USERDATA,           16742 * 1024,       (3668 * 1024), EMMC_USER_PART}, /* userdata       4G p94 */
#else
    {PART_USERDATA,           16740 * 1024,       (3668 * 1024), EMMC_USER_PART}, /* userdata       4G p93 */
#endif
#else
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, EMMC_USER_PART}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    24 * 1024, EMMC_USER_PART}, /* updater_vendor_bak  24MB p48 */
    {PART_BOOT,                 640 * 1024,    48 * 1024, EMMC_USER_PART}, /* boot                48MB p49 */
    {PART_UPDATER_BOOT,         688 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     742 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        796 * 1024,          512, EMMC_USER_PART}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (796 * 1024 + 512),     2 * 1024, EMMC_USER_PART}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (798 * 1024 + 512),(49 * 1024+512), EMMC_USER_PART}, /* reserved3         50688KB p54 */
#else
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, EMMC_USER_PART}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    24 * 1024, EMMC_USER_PART}, /* updater_vendor_bak  24MB p48 */
    {PART_BOOT,                 640 * 1024,    46 * 1024, EMMC_USER_PART}, /* boot                46MB p49 */
    {PART_UPDATER_BOOT,         686 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     740 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        794 * 1024,          512, EMMC_USER_PART}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (794 * 1024 + 512),     2 * 1024, EMMC_USER_PART}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (796 * 1024 + 512),(51 * 1024+512), EMMC_USER_PART}, /* reserved3         52736KB p54 */
#endif
    {PART_THEE,                 848 * 1024,     4 * 1024, EMMC_USER_PART}, /* thee                 4MB p55 */
    {PART_TZSP,                 852 * 1024,    12 * 1024, EMMC_USER_PART}, /* tzsp                12MB p56 */
    {PART_UPDATER_RAMDISK,      864 * 1024,    32 * 1024, EMMC_USER_PART}, /* updater_ramdisk     32MB p57 */
    {PART_UPDATER_VENDOR,       896 * 1024,    24 * 1024, EMMC_USER_PART}, /* updater_vendor      24MB p58 */
    {PART_ENG_SYSTEM,           920 * 1024,    12 * 1024, EMMC_USER_PART}, /* eng_system          12MB p59 */
    {PART_ENG_CHIPSET,          932 * 1024,    20 * 1024, EMMC_USER_PART}, /* eng_chipset         20MB p60 */
    {PART_FW_DTB,               952 * 1024,     8 * 1024, EMMC_USER_PART}, /* fw_dtb               8MB p61 */
    {PART_DTBO,                 960 * 1024,    14 * 1024, EMMC_USER_PART}, /* dtbo                14MB p62 */
    {PART_TRUSTFIRMWARE,        974 * 1024,     2 * 1024, EMMC_USER_PART}, /* trustfirmware        2MB p63 */
    {PART_MODEM_FW,             976 * 1024,   124 * 1024, EMMC_USER_PART}, /* modem_fw           124MB p64 */
    {PART_MODEM_VENDOR,        1100 * 1024,    10 * 1024, EMMC_USER_PART}, /* modem_vendor        10MB p65 */
    {PART_MODEM_PATCH_NV,      1110 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_patch_nv       4MB p66 */
    {PART_MODEM_DRIVER,        1114 * 1024,    20 * 1024, EMMC_USER_PART}, /* modem_driver        20MB p67 */
    {PART_MODEMNVM_UPDATE,     1134 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_update     16MB p68 */
    {PART_MODEMNVM_CUST,       1150 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_cust       16MB p69 */
    {PART_RAMDISK,             1166 * 1024,     4 * 1024, EMMC_USER_PART}, /* ramdisk              4MB p70 */
    {PART_RVT_SYSTEM,          1170 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_system        1024KB p71 */
    {PART_RVT_VENDOR,          1171 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_vendor        1024KB p72 */
    {PART_RVT_CHIP_PROD,       1172 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_chip_prod     1024KB p73 */
    {PART_RVT_CUST,            1173 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_cust          1024KB p74 */
    {PART_RVT_SYS_PROD,        1174 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_sys_prod      1024KB p75 */
    {PART_UPDATER_RVT,         1175 * 1024,     2 * 1024, EMMC_USER_PART}, /* updater_rvt          2MB p76 */
    {PART_UPDATER_BAK_RVT,     1177 * 1024,     2 * 1024, EMMC_USER_PART}, /* updater_bak_rvt      2MB p77 */
    {PART_RVT,                 1179 * 1024,     4 * 1024, EMMC_USER_PART}, /* rvt                  4MB p78 */
    {PART_KPATCH,              1183 * 1024,     4 * 1024, EMMC_USER_PART}, /* kpatch               4MB p79 */
    {PART_PATCH,               1187 * 1024,    32 * 1024, EMMC_USER_PART}, /* patch               32MB p80 */
    {PART_RESERVED5,           1219 * 1024,    31 * 1024, EMMC_USER_PART}, /* reserved5           31MB p81 */
#ifdef CONFIG_FACTORY_MODE
    {PART_SENSORHUB,           1250 * 1024,   125 * 1024, EMMC_USER_PART}, /* sensorhub          125MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1375 * 1024,     3 * 1024, EMMC_USER_PART}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1378 * 1024,   128 * 1024, EMMC_USER_PART}, /* chip_prod          128MB p84 */
    {PART_VENDOR,              1506 * 1024,   500 * 1024, EMMC_USER_PART}, /* vendor             500MB p85 */
    {PART_SYS_PROD,            2006 * 1024,   600 * 1024, EMMC_USER_PART}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              2606 * 1024,  2988 * 1024, EMMC_USER_PART}, /* system            2988MB p87 */
    {PART_HIBENCH_IMG,         5594 * 1024,    40 * 1024, EMMC_USER_PART}, /* hibench_img         40MB p88 */
    {PART_HIBENCH_DATA,        5634 * 1024,   600 * 1024, EMMC_USER_PART}, /* hibench_data       600MB p89 */
    {PART_FLASH_AGEING,        6234 * 1024,   512 * 1024, EMMC_USER_PART}, /* flash_ageing       512MB p90 */
    {PART_HIBENCH_LOG,         6746 * 1024,    32 * 1024, EMMC_USER_PART}, /* hibench_log         32MB p91 */
    {PART_HIBENCH_LPM3,        6778 * 1024,     2 * 1024, EMMC_USER_PART}, /* hibench_lpm3         2MB p92 */
    {PART_RESERVED4,           6780 * 1024,   178 * 1024, EMMC_USER_PART}, /* reserved4          178MB p93 */
    {PART_CUST,                6958 * 1024,    88 * 1024, EMMC_USER_PART}, /* cust                88MB p94 */
    {PART_VERSION,             7046 * 1024,   200 * 1024, EMMC_USER_PART}, /* version            200MB p95 */
    {PART_PRELOAD,             7246 * 1024,   520 * 1024, EMMC_USER_PART}, /* preload            520MB p96 */
    {PART_SENSORHUB_SYSTEM,    7766 * 1024,  1536 * 1024, EMMC_USER_PART}, /* sensorhub_system  1536MB p97 */
    {PART_SENSORHUB_DATA,      9302 * 1024,  6656 * 1024, EMMC_USER_PART}, /* sensorhub_data    6656MB p98 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      15958 * 1024,     2 * 1024, EMMC_USER_PART}, /* conn_calidata        2MB p99 */
    {PART_USERDATA,           15960 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p100 */
#else
    {PART_USERDATA,           15958 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p99 */
#endif
#else
    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, EMMC_USER_PART}, /* sensorhub          597MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, EMMC_USER_PART}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1850 * 1024,   600 * 1024, EMMC_USER_PART}, /* chip_prod          600MB p84 */
    {PART_VENDOR,              2450 * 1024,   920 * 1024, EMMC_USER_PART}, /* vendor             920MB p85 */
    {PART_SYS_PROD,            3370 * 1024,   600 * 1024, EMMC_USER_PART}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              3970 * 1024,  2988 * 1024, EMMC_USER_PART}, /* system            2988MB p87 */
    {PART_CUST,                6958 * 1024,    88 * 1024, EMMC_USER_PART}, /* cust                88MB p88 */
    {PART_VERSION,             7046 * 1024,   200 * 1024, EMMC_USER_PART}, /* version            200MB p89 */
    {PART_PRELOAD,             7246 * 1024,   520 * 1024, EMMC_USER_PART}, /* preload            520MB p90 */
#ifdef CONFIG_PARTITION_ENG
    {PART_FTTEST,              7766 * 1024,   192 * 1024, EMMC_USER_PART}, /* fttest             192MB p91 */
    {PART_DDRTEST,             7958 * 1024,    48 * 1024, EMMC_USER_PART}, /* ddrtest             48MB p92 */
    {PART_HIBENCH_LPM3,        8006 * 1024,     2 * 1024, EMMC_USER_PART}, /* hibench_lpm3         2MB p93 */
    {PART_HITEST_ASP_DHRYSTONE,  8008 * 1024,     2 * 1024, EMMC_USER_PART}, /* hitest_asp_dhrystone   2MB p94 */
    {PART_HITEST_ASP_TEST,     8010 * 1024,    30 * 1024, EMMC_USER_PART}, /* hitest_asp_test     30MB p95 */
    {PART_HITEST_GPU,          8040 * 1024,   100 * 1024, EMMC_USER_PART}, /* hitest_gpu         100MB p96 */
    {PART_HITEST_GPU_1,        8140 * 1024,   256 * 1024, EMMC_USER_PART}, /* hitest_gpu_1       256MB p97 */
    {PART_HITEST_NPU,          8396 * 1024,    64 * 1024, EMMC_USER_PART}, /* hitest_npu          64MB p98 */
    {PART_HITEST_JPEGENC,      8460 * 1024,   200 * 1024, EMMC_USER_PART}, /* hitest_jpegenc     200MB p99 */
    {PART_HITEST_SENSORHUB,    8660 * 1024,     6 * 1024, EMMC_USER_PART}, /* hitest_sensorhub     6MB p100 */
    {PART_VCODE_DATA,          8666 * 1024,   140 * 1024, EMMC_USER_PART}, /* vcode_data         140MB p101 */
    {PART_VCODE_MAX_DATA,      8806 * 1024,   140 * 1024, EMMC_USER_PART}, /* vcode_max_data     140MB p102 */
    {PART_DSS_DISP_BUF,        8946 * 1024,    64 * 1024, EMMC_USER_PART}, /* dss_disp_buf        64MB p103 */
    {PART_MODEM_TSP_TEST,      9010 * 1024,    10 * 1024, EMMC_USER_PART}, /* modem_tsp_test      10MB p104 */
    {PART_MODEM_TSP_DT,        9020 * 1024,     2 * 1024, EMMC_USER_PART}, /* modem_tsp_dt         2MB p105 */
    {PART_MODEM_TSP_AVS,       9022 * 1024,    80 * 1024, EMMC_USER_PART}, /* modem_tsp_avs       80MB p106 */
    {PART_MODEM_PDE_TEST,      9102 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_pde_test       4MB p107 */
    {PART_MODEM_L2DLE,         9106 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_l2dle          4MB p108 */
    {PART_MODEM_VECTOR_CONFIG,  9110 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_vector_config   4MB p109 */
    {PART_SENSORHUB_SYSTEM,    9114 * 1024,  1536 * 1024, EMMC_USER_PART}, /* sensorhub_system  1536MB p110 */
    {PART_SENSORHUB_DATA,     10650 * 1024,  6656 * 1024, EMMC_USER_PART}, /* sensorhub_data    6656MB p111 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      17306 * 1024,     2 * 1024, EMMC_USER_PART}, /* conn_calidata        2MB p112 */
    {PART_USERDATA,           17308 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p113 */
#else
    {PART_USERDATA,           17306 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p112 */
#endif
#else
    {PART_SENSORHUB_SYSTEM,    7766 * 1024,  1536 * 1024, EMMC_USER_PART}, /* sensorhub_system  1536MB p91 */
    {PART_SENSORHUB_DATA,      9302 * 1024,  6656 * 1024, EMMC_USER_PART}, /* sensorhub_data    6656MB p92 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      15958 * 1024,     2 * 1024, EMMC_USER_PART},  /* conn_calidata        2MB p93 */
    {PART_USERDATA,           15960 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p94 */
#else
    {PART_USERDATA,           15958 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p93 */
#endif
#endif
#endif
#endif
    {"0", 0, 0, 0},
};
static const struct partition partition_table_emmc_custom[] = {
    {PART_XLOADER,                0,             2 * 1024,    EMMC_BOOT_MAJOR_PART},
    {PART_RESERVED0,              0,             2 * 1024,    EMMC_BOOT_BACKUP_PART},
    {PART_PTABLE,                 0,                  512,    EMMC_USER_PART}, /* ptable           512K    p0 */
    {PART_FRP,                                512,   512, EMMC_USER_PART}, /* frp                512KB p1 */
    {PART_PERSIST,                    1024,     6 * 1024, EMMC_USER_PART}, /* persist              6MB p2 */
    {PART_RESERVED1,              7 * 1024,         1536, EMMC_USER_PART}, /* reserved1         1536KB p3 */
    {PART_VRL,               (8 * 1024 + 512),          512, EMMC_USER_PART}, /* vrl                512KB p4 */
    {PART_VRL_BACKUP,             9 * 1024,          512, EMMC_USER_PART}, /* vrl_backup         512KB p5 */
    {PART_MODEM_SECURE,      (9 * 1024 + 512),         8704, EMMC_USER_PART}, /* modem_secure      8704KB p6 */
    {PART_NVME,                  18 * 1024,     5 * 1024, EMMC_USER_PART}, /* nvme                 5MB p7 */
    {PART_CTF,                   23 * 1024,     1 * 1024, EMMC_USER_PART}, /* ctf               1024KB p8 */
    {PART_OEMINFO,               24 * 1024,    96 * 1024, EMMC_USER_PART}, /* oeminfo             96MB p9 */
    {PART_SECURE_STORAGE,       120 * 1024,    32 * 1024, EMMC_USER_PART}, /* secure_storage      32MB p10 */
    {PART_MODEMNVM_FACTORY,     152 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_factory    16MB p11 */
    {PART_MODEMNVM_BACKUP,      168 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_backup     16MB p12 */
    {PART_MODEMNVM_IMG,         184 * 1024,    46 * 1024, EMMC_USER_PART}, /* modemnvm_img        46MB p13 */
    {PART_HISEE_ENCOS,          230 * 1024,     4 * 1024, EMMC_USER_PART}, /* hisee_encos          4MB p14 */
    {PART_VERITYKEY,            234 * 1024,     1 * 1024, EMMC_USER_PART}, /* veritykey         1024KB p15 */
    {PART_DDR_PARA,             235 * 1024,     1 * 1024, EMMC_USER_PART}, /* ddr_para          1024KB p16 */
    {PART_LOWPOWER_PARA,        236 * 1024,     1 * 1024, EMMC_USER_PART}, /* lowpower_para     1024KB p17 */
    {PART_BATT_TP_PARA,         237 * 1024,     1 * 1024, EMMC_USER_PART}, /* batt_tp_para      1024KB p18 */
    {PART_DACC,                 238 * 1024,          512, EMMC_USER_PART}, /* dacc               512KB p19 */
    {PART_RESERVED2,         (238 * 1024 + 512),(20 * 1024+512), EMMC_USER_PART}, /* reserved2         20992KB p20 */
    {PART_LOG,                  259 * 1024,    80 * 1024, EMMC_USER_PART}, /* log                 80MB p21 */
    {PART_BOOTFAIL_INFO,        339 * 1024,     2 * 1024, EMMC_USER_PART}, /* bootfail_info        2MB p22 */
    {PART_MISC,                 341 * 1024,     2 * 1024, EMMC_USER_PART}, /* misc                 2MB p23 */
    {PART_DFX,                  343 * 1024,    16 * 1024, EMMC_USER_PART}, /* dfx                 16MB p24 */
    {PART_RRECORD,              359 * 1024,    16 * 1024, EMMC_USER_PART}, /* rrecord             16MB p25 */
    {PART_CACHE,                375 * 1024,   104 * 1024, EMMC_USER_PART}, /* cache              104MB p26 */
    {PART_METADATA,             479 * 1024,    16 * 1024, EMMC_USER_PART}, /* metadata            16MB p27 */
    {PART_FW_EMMCDEV,           495 * 1024,     4 * 1024, EMMC_USER_PART}, /* fw_emmcdev           4MB p28 */
    {PART_TOC,                  499 * 1024,     1 * 1024, EMMC_USER_PART}, /* toc               1024KB p29 */
    {PART_BL2,                  500 * 1024,     4 * 1024, EMMC_USER_PART}, /* bl2                  4MB p30 */
    {PART_FW_LPM3,              504 * 1024,          512, EMMC_USER_PART}, /* fw_lpm3            512KB p31 */
    {PART_FW_CPU_LPCTRL,     (504 * 1024 + 512),          256, EMMC_USER_PART}, /* fw_cpu_lpctrl      256KB p32 */
    {PART_FW_GPU_LPCTRL,     (504 * 1024 + 768),          128, EMMC_USER_PART}, /* fw_gpu_lpctrl      128KB p33 */
    {PART_FW_DDR_LPCTRL,     (504 * 1024 + 896),          128, EMMC_USER_PART}, /* fw_ddr_lpctrl      128KB p34 */
    {PART_NPU,                  505 * 1024,     8 * 1024, EMMC_USER_PART}, /* npu                  8MB p35 */
    {PART_IVP,                  513 * 1024,     2 * 1024, EMMC_USER_PART}, /* ivp                  2MB p36 */
    {PART_HDCP,                 515 * 1024,     1 * 1024, EMMC_USER_PART}, /* hdcp              1024KB p37 */
    {PART_HISEE_IMG,            516 * 1024,     4 * 1024, EMMC_USER_PART}, /* hisee_img            4MB p38 */
    {PART_HHEE,                 520 * 1024,     4 * 1024, EMMC_USER_PART}, /* hhee                 4MB p39 */
    {PART_HISEE_FS,             524 * 1024,     8 * 1024, EMMC_USER_PART}, /* hisee_fs             8MB p40 */
    {PART_FASTBOOT,             532 * 1024,    12 * 1024, EMMC_USER_PART}, /* fastboot            12MB p41 */
    {PART_VECTOR,               544 * 1024,     4 * 1024, EMMC_USER_PART}, /* vector               4MB p42 */
    {PART_ISP_BOOT,             548 * 1024,     2 * 1024, EMMC_USER_PART}, /* isp_boot             2MB p43 */
    {PART_ISP_FIRMWARE,         550 * 1024,    14 * 1024, EMMC_USER_PART}, /* isp_firmware        14MB p44 */
    {PART_FW_HIFI,              564 * 1024,    12 * 1024, EMMC_USER_PART}, /* fw_hifi             12MB p45 */
    {PART_TEEOS,                576 * 1024,     8 * 1024, EMMC_USER_PART}, /* teeos                8MB p46 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, EMMC_USER_PART}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    28 * 1024, EMMC_USER_PART}, /* updater_vendor_bak  28MB p48 */
    {PART_BOOT,                 644 * 1024,    48 * 1024, EMMC_USER_PART}, /* boot                48MB p49 */
    {PART_UPDATER_BOOT,         692 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     746 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        800 * 1024,          512, EMMC_USER_PART}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (800 * 1024 + 512),     2 * 1024, EMMC_USER_PART}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (802 * 1024 + 512),(50 * 1024+512), EMMC_USER_PART}, /* reserved3         51712KB p54 */
    {PART_THEE,                 853 * 1024,     4 * 1024, EMMC_USER_PART}, /* thee                 4MB p55 */
    {PART_TZSP,                 857 * 1024,    12 * 1024, EMMC_USER_PART}, /* tzsp                12MB p56 */
    {PART_UPDATER_RAMDISK,      869 * 1024,    32 * 1024, EMMC_USER_PART}, /* updater_ramdisk     32MB p57 */
    {PART_UPDATER_VENDOR,       901 * 1024,    28 * 1024, EMMC_USER_PART}, /* updater_vendor      28MB p58 */
    {PART_ENG_SYSTEM,           929 * 1024,    12 * 1024, EMMC_USER_PART}, /* eng_system          12MB p59 */
    {PART_ENG_CHIPSET,          941 * 1024,    20 * 1024, EMMC_USER_PART}, /* eng_chipset         20MB p60 */
    {PART_FW_DTB,               961 * 1024,     8 * 1024, EMMC_USER_PART}, /* fw_dtb               8MB p61 */
    {PART_DTBO,                 969 * 1024,    14 * 1024, EMMC_USER_PART}, /* dtbo                14MB p62 */
    {PART_TRUSTFIRMWARE,        983 * 1024,     2 * 1024, EMMC_USER_PART}, /* trustfirmware        2MB p63 */
    {PART_MODEM_FW,             985 * 1024,   124 * 1024, EMMC_USER_PART}, /* modem_fw           124MB p64 */
    {PART_MODEM_VENDOR,        1109 * 1024,    30 * 1024, EMMC_USER_PART}, /* modem_vendor        30MB p65 */
    {PART_MODEM_PATCH_NV,      1139 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_patch_nv       4MB p66 */
    {PART_MODEM_DRIVER,        1143 * 1024,    20 * 1024, EMMC_USER_PART}, /* modem_driver        20MB p67 */
    {PART_MODEMNVM_UPDATE,     1163 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_update     16MB p68 */
    {PART_MODEMNVM_CUST,       1179 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_cust       16MB p69 */
    {PART_RAMDISK,             1195 * 1024,     4 * 1024, EMMC_USER_PART}, /* ramdisk              4MB p70 */
    {PART_RVT_SYSTEM,          1199 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_system        1024KB p71 */
    {PART_RVT_VENDOR,          1200 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_vendor        1024KB p72 */
    {PART_RVT_CHIP_PROD,       1201 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_chip_prod     1024KB p73 */
    {PART_RVT_CUST,            1202 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_cust          1024KB p74 */
    {PART_RVT_SYS_PROD,        1203 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_sys_prod      1024KB p75 */
    {PART_UPDATER_RVT,         1204 * 1024,     2 * 1024, EMMC_USER_PART}, /* updater_rvt          2MB p76 */
    {PART_UPDATER_BAK_RVT,     1206 * 1024,     2 * 1024, EMMC_USER_PART}, /* updater_bak_rvt      2MB p77 */
    {PART_RVT,                 1208 * 1024,     4 * 1024, EMMC_USER_PART}, /* rvt                  4MB p78 */
    {PART_KPATCH,              1212 * 1024,     4 * 1024, EMMC_USER_PART}, /* kpatch               4MB p79 */
    {PART_PATCH,               1216 * 1024,    32 * 1024, EMMC_USER_PART}, /* patch               32MB p80 */
    {PART_RESERVED5,           1248 * 1024,     2 * 1024, EMMC_USER_PART}, /* reserved5            2MB p81 */
    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, EMMC_USER_PART}, /* sensorhub          597MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, EMMC_USER_PART}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1850 * 1024,   600 * 1024, EMMC_USER_PART}, /* chip_prod          600MB p84 */
    {PART_VENDOR,              2450 * 1024,  1024 * 1024, EMMC_USER_PART}, /* vendor            1024 * 1024KB p85 */
    {PART_SYS_PROD,            3474 * 1024,   600 * 1024, EMMC_USER_PART}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              4074 * 1024,  3666 * 1024, EMMC_USER_PART}, /* system            3666MB p87 */
    {PART_CUST,                7740 * 1024,    88 * 1024, EMMC_USER_PART}, /* cust                88MB p88 */
    {PART_VERSION,             7828 * 1024,   200 * 1024, EMMC_USER_PART}, /* version            200MB p89 */
    {PART_PRELOAD,             8028 * 1024,   520 * 1024, EMMC_USER_PART}, /* preload            520MB p90 */
    {PART_SENSORHUB_SYSTEM,    8548 * 1024,  1536 * 1024, EMMC_USER_PART}, /* sensorhub_system  1536MB p91 */
    {PART_SENSORHUB_DATA,     10084 * 1024,  6656 * 1024, EMMC_USER_PART}, /* sensorhub_data    6656MB p92 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      16740 * 1024,     2 * 1024, EMMC_USER_PART}, /* conn_calidata        2MB p93 */
    {PART_USERDATA,           16742 * 1024,       (3668 * 1024), EMMC_USER_PART}, /* userdata       4G p94 */
#else
    {PART_USERDATA,           16740 * 1024,       (3668 * 1024), EMMC_USER_PART}, /* userdata       4G p93 */
#endif
#else
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, EMMC_USER_PART}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    24 * 1024, EMMC_USER_PART}, /* updater_vendor_bak  24MB p48 */
    {PART_BOOT,                 640 * 1024,    48 * 1024, EMMC_USER_PART}, /* boot                48MB p49 */
    {PART_UPDATER_BOOT,         688 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     742 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        796 * 1024,          512, EMMC_USER_PART}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (796 * 1024 + 512),     2 * 1024, EMMC_USER_PART}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (798 * 1024 + 512),(49 * 1024+512), EMMC_USER_PART}, /* reserved3         50688KB p54 */
#else
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, EMMC_USER_PART}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    24 * 1024, EMMC_USER_PART}, /* updater_vendor_bak  24MB p48 */
    {PART_BOOT,                 640 * 1024,    46 * 1024, EMMC_USER_PART}, /* boot                46MB p49 */
    {PART_UPDATER_BOOT,         686 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     740 * 1024,    54 * 1024, EMMC_USER_PART}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        794 * 1024,          512, EMMC_USER_PART}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (794 * 1024 + 512),     2 * 1024, EMMC_USER_PART}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (796 * 1024 + 512),(51 * 1024+512), EMMC_USER_PART}, /* reserved3         52736KB p54 */
#endif
    {PART_THEE,                 848 * 1024,     4 * 1024, EMMC_USER_PART}, /* thee                 4MB p55 */
    {PART_TZSP,                 852 * 1024,    12 * 1024, EMMC_USER_PART}, /* tzsp                12MB p56 */
    {PART_UPDATER_RAMDISK,      864 * 1024,    32 * 1024, EMMC_USER_PART}, /* updater_ramdisk     32MB p57 */
    {PART_UPDATER_VENDOR,       896 * 1024,    24 * 1024, EMMC_USER_PART}, /* updater_vendor      24MB p58 */
    {PART_ENG_SYSTEM,           920 * 1024,    12 * 1024, EMMC_USER_PART}, /* eng_system          12MB p59 */
    {PART_ENG_CHIPSET,          932 * 1024,    20 * 1024, EMMC_USER_PART}, /* eng_chipset         20MB p60 */
    {PART_FW_DTB,               952 * 1024,     8 * 1024, EMMC_USER_PART}, /* fw_dtb               8MB p61 */
    {PART_DTBO,                 960 * 1024,    14 * 1024, EMMC_USER_PART}, /* dtbo                14MB p62 */
    {PART_TRUSTFIRMWARE,        974 * 1024,     2 * 1024, EMMC_USER_PART}, /* trustfirmware        2MB p63 */
    {PART_MODEM_FW,             976 * 1024,   124 * 1024, EMMC_USER_PART}, /* modem_fw           124MB p64 */
    {PART_MODEM_VENDOR,        1100 * 1024,    10 * 1024, EMMC_USER_PART}, /* modem_vendor        10MB p65 */
    {PART_MODEM_PATCH_NV,      1110 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_patch_nv       4MB p66 */
    {PART_MODEM_DRIVER,        1114 * 1024,    20 * 1024, EMMC_USER_PART}, /* modem_driver        20MB p67 */
    {PART_MODEMNVM_UPDATE,     1134 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_update     16MB p68 */
    {PART_MODEMNVM_CUST,       1150 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_cust       16MB p69 */
    {PART_RAMDISK,             1166 * 1024,     4 * 1024, EMMC_USER_PART}, /* ramdisk              4MB p70 */
    {PART_RVT_SYSTEM,          1170 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_system        1024KB p71 */
    {PART_RVT_VENDOR,          1171 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_vendor        1024KB p72 */
    {PART_RVT_CHIP_PROD,       1172 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_chip_prod     1024KB p73 */
    {PART_RVT_CUST,            1173 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_cust          1024KB p74 */
    {PART_RVT_SYS_PROD,        1174 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_sys_prod      1024KB p75 */
    {PART_UPDATER_RVT,         1175 * 1024,     2 * 1024, EMMC_USER_PART}, /* updater_rvt          2MB p76 */
    {PART_UPDATER_BAK_RVT,     1177 * 1024,     2 * 1024, EMMC_USER_PART}, /* updater_bak_rvt      2MB p77 */
    {PART_RVT,                 1179 * 1024,     4 * 1024, EMMC_USER_PART}, /* rvt                  4MB p78 */
    {PART_KPATCH,              1183 * 1024,     4 * 1024, EMMC_USER_PART}, /* kpatch               4MB p79 */
    {PART_PATCH,               1187 * 1024,    32 * 1024, EMMC_USER_PART}, /* patch               32MB p80 */
    {PART_RESERVED5,           1219 * 1024,    31 * 1024, EMMC_USER_PART}, /* reserved5           31MB p81 */
#ifdef CONFIG_FACTORY_MODE
    {PART_SENSORHUB,           1250 * 1024,   125 * 1024, EMMC_USER_PART}, /* sensorhub          125MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1375 * 1024,     3 * 1024, EMMC_USER_PART}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1378 * 1024,   128 * 1024, EMMC_USER_PART}, /* chip_prod          128MB p84 */
    {PART_VENDOR,              1506 * 1024,   500 * 1024, EMMC_USER_PART}, /* vendor             500MB p85 */
    {PART_SYS_PROD,            2006 * 1024,   600 * 1024, EMMC_USER_PART}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              2606 * 1024,  2988 * 1024, EMMC_USER_PART}, /* system            2988MB p87 */
    {PART_HIBENCH_IMG,         5594 * 1024,    40 * 1024, EMMC_USER_PART}, /* hibench_img         40MB p88 */
    {PART_HIBENCH_DATA,        5634 * 1024,   600 * 1024, EMMC_USER_PART}, /* hibench_data       600MB p89 */
    {PART_FLASH_AGEING,        6234 * 1024,   512 * 1024, EMMC_USER_PART}, /* flash_ageing       512MB p90 */
    {PART_HIBENCH_LOG,         6746 * 1024,    32 * 1024, EMMC_USER_PART}, /* hibench_log         32MB p91 */
    {PART_HIBENCH_LPM3,        6778 * 1024,     2 * 1024, EMMC_USER_PART}, /* hibench_lpm3         2MB p92 */
    {PART_RESERVED4,           6780 * 1024,   178 * 1024, EMMC_USER_PART}, /* reserved4          178MB p93 */
    {PART_CUST,                6958 * 1024,    88 * 1024, EMMC_USER_PART}, /* cust                88MB p94 */
    {PART_VERSION,             7046 * 1024,   200 * 1024, EMMC_USER_PART}, /* version            200MB p95 */
    {PART_PRELOAD,             7246 * 1024,   520 * 1024, EMMC_USER_PART}, /* preload            520MB p96 */
    {PART_SENSORHUB_SYSTEM,    7766 * 1024,  1536 * 1024, EMMC_USER_PART}, /* sensorhub_system  1536MB p97 */
    {PART_SENSORHUB_DATA,      9302 * 1024,  6656 * 1024, EMMC_USER_PART}, /* sensorhub_data    6656MB p98 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      15958 * 1024,     2 * 1024, EMMC_USER_PART}, /* conn_calidata        2MB p99 */
    {PART_USERDATA,           15960 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p100 */
#else
    {PART_USERDATA,           15958 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p99 */
#endif
#else
    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, EMMC_USER_PART}, /* sensorhub          597MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, EMMC_USER_PART}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1850 * 1024,   600 * 1024, EMMC_USER_PART}, /* chip_prod          600MB p84 */
    {PART_VENDOR,              2450 * 1024,   920 * 1024, EMMC_USER_PART}, /* vendor             920MB p85 */
    {PART_SYS_PROD,            3370 * 1024,   600 * 1024, EMMC_USER_PART}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              3970 * 1024,  2988 * 1024, EMMC_USER_PART}, /* system            2988MB p87 */
    {PART_CUST,                6958 * 1024,    88 * 1024, EMMC_USER_PART}, /* cust                88MB p88 */
    {PART_VERSION,             7046 * 1024,   200 * 1024, EMMC_USER_PART}, /* version            200MB p89 */
    {PART_PRELOAD,             7246 * 1024,   520 * 1024, EMMC_USER_PART}, /* preload            520MB p90 */
#ifdef CONFIG_PARTITION_ENG
    {PART_FTTEST,              7766 * 1024,   192 * 1024, EMMC_USER_PART}, /* fttest             192MB p91 */
    {PART_DDRTEST,             7958 * 1024,    48 * 1024, EMMC_USER_PART}, /* ddrtest             48MB p92 */
    {PART_HIBENCH_LPM3,        8006 * 1024,     2 * 1024, EMMC_USER_PART}, /* hibench_lpm3         2MB p93 */
    {PART_HITEST_ASP_DHRYSTONE,  8008 * 1024,     2 * 1024, EMMC_USER_PART}, /* hitest_asp_dhrystone   2MB p94 */
    {PART_HITEST_ASP_TEST,     8010 * 1024,    30 * 1024, EMMC_USER_PART}, /* hitest_asp_test     30MB p95 */
    {PART_HITEST_GPU,          8040 * 1024,   100 * 1024, EMMC_USER_PART}, /* hitest_gpu         100MB p96 */
    {PART_HITEST_GPU_1,        8140 * 1024,   256 * 1024, EMMC_USER_PART}, /* hitest_gpu_1       256MB p97 */
    {PART_HITEST_NPU,          8396 * 1024,    64 * 1024, EMMC_USER_PART}, /* hitest_npu          64MB p98 */
    {PART_HITEST_JPEGENC,      8460 * 1024,   200 * 1024, EMMC_USER_PART}, /* hitest_jpegenc     200MB p99 */
    {PART_HITEST_SENSORHUB,    8660 * 1024,     6 * 1024, EMMC_USER_PART}, /* hitest_sensorhub     6MB p100 */
    {PART_VCODE_DATA,          8666 * 1024,   140 * 1024, EMMC_USER_PART}, /* vcode_data         140MB p101 */
    {PART_VCODE_MAX_DATA,      8806 * 1024,   140 * 1024, EMMC_USER_PART}, /* vcode_max_data     140MB p102 */
    {PART_DSS_DISP_BUF,        8946 * 1024,    64 * 1024, EMMC_USER_PART}, /* dss_disp_buf        64MB p103 */
    {PART_MODEM_TSP_TEST,      9010 * 1024,    10 * 1024, EMMC_USER_PART}, /* modem_tsp_test      10MB p104 */
    {PART_MODEM_TSP_DT,        9020 * 1024,     2 * 1024, EMMC_USER_PART}, /* modem_tsp_dt         2MB p105 */
    {PART_MODEM_TSP_AVS,       9022 * 1024,    80 * 1024, EMMC_USER_PART}, /* modem_tsp_avs       80MB p106 */
    {PART_MODEM_PDE_TEST,      9102 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_pde_test       4MB p107 */
    {PART_MODEM_L2DLE,         9106 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_l2dle          4MB p108 */
    {PART_MODEM_VECTOR_CONFIG,  9110 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_vector_config   4MB p109 */
    {PART_SENSORHUB_SYSTEM,    9114 * 1024,  1792 * 1024, EMMC_USER_PART}, /* sensorhub_system  1792MB p110 */
    {PART_SENSORHUB_DATA,     10906 * 1024, 18688 * 1024, EMMC_USER_PART}, /* sensorhub_data    18688MB p111 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      29594 * 1024,     2 * 1024, EMMC_USER_PART}, /* conn_calidata        2MB p112 */
    {PART_USERDATA,           29596 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p113 */
#else
    {PART_USERDATA,           29594 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p112 */
#endif
#else
    {PART_SENSORHUB_SYSTEM,    7766 * 1024,  1536 * 1024, EMMC_USER_PART}, /* sensorhub_system  1536MB p91 */
    {PART_SENSORHUB_DATA,      9302 * 1024,  6656 * 1024, EMMC_USER_PART}, /* sensorhub_data    6656MB p92 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      15958 * 1024,     2 * 1024, EMMC_USER_PART},  /* conn_calidata        2MB p93 */
    {PART_USERDATA,           15960 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p94 */
#else
    {PART_USERDATA,           15958 * 1024, (4UL * 1024 * 1024), EMMC_USER_PART}, /* userdata       4G p93 */
#endif
#endif
#endif
#endif
    {"0", 0, 0, 0},
};
static const struct partition partition_table_ufs_custom[] = {
    {PART_XLOADER,                0,             2 * 1024,    UFS_PART_0},
    {PART_RESERVED0,              0,             2 * 1024,    UFS_PART_1},
    {PART_PTABLE,                 0,              512, UFS_PART_2}, /* ptable             512KB p0 */
    {PART_RPMB_RESERVED,        512,       1024 + 512, UFS_PART_2}, /* rpmb_reserved     1536KB p1 */
    {PART_RPMB_SECOS,      2 * 1024,        14 * 1024, UFS_PART_2}, /* rpmb_secos          14MB p2 */
    {PART_PTABLE_LU3,             0,          512, UFS_PART_3}, /* ptable           512K    p0 */
    {PART_FRP,                                512,   512, UFS_PART_3}, /* frp                512KB p1 */
    {PART_PERSIST,                    1024,     6 * 1024, UFS_PART_3}, /* persist              6MB p2 */
    {PART_RESERVED1,              7 * 1024,         1536, UFS_PART_3}, /* reserved1         1536KB p3 */
    {PART_VRL,               (8 * 1024 + 512),          512, UFS_PART_3}, /* vrl                512KB p4 */
    {PART_VRL_BACKUP,             9 * 1024,          512, UFS_PART_3}, /* vrl_backup         512KB p5 */
    {PART_MODEM_SECURE,      (9 * 1024 + 512),         8704, UFS_PART_3}, /* modem_secure      8704KB p6 */
    {PART_NVME,                  18 * 1024,     5 * 1024, UFS_PART_3}, /* nvme                 5MB p7 */
    {PART_CTF,                   23 * 1024,     1 * 1024, UFS_PART_3}, /* ctf               1024KB p8 */
    {PART_OEMINFO,               24 * 1024,    96 * 1024, UFS_PART_3}, /* oeminfo             96MB p9 */
    {PART_SECURE_STORAGE,       120 * 1024,    32 * 1024, UFS_PART_3}, /* secure_storage      32MB p10 */
    {PART_MODEMNVM_FACTORY,     152 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_factory    16MB p11 */
    {PART_MODEMNVM_BACKUP,      168 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_backup     16MB p12 */
    {PART_MODEMNVM_IMG,         184 * 1024,    46 * 1024, UFS_PART_3}, /* modemnvm_img        46MB p13 */
    {PART_HISEE_ENCOS,          230 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_encos          4MB p14 */
    {PART_VERITYKEY,            234 * 1024,     1 * 1024, UFS_PART_3}, /* veritykey         1024KB p15 */
    {PART_DDR_PARA,             235 * 1024,     1 * 1024, UFS_PART_3}, /* ddr_para          1024KB p16 */
    {PART_LOWPOWER_PARA,        236 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para     1024KB p17 */
    {PART_BATT_TP_PARA,         237 * 1024,     1 * 1024, UFS_PART_3}, /* batt_tp_para      1024KB p18 */
    {PART_DACC,                 238 * 1024,          512, UFS_PART_3}, /* dacc               512KB p19 */
    {PART_RESERVED2,         (238 * 1024 + 512),(20 * 1024+512), UFS_PART_3}, /* reserved2         20992KB p20 */
    {PART_LOG,                  259 * 1024,    80 * 1024, UFS_PART_3}, /* log                 80MB p21 */
    {PART_BOOTFAIL_INFO,        339 * 1024,     2 * 1024, UFS_PART_3}, /* bootfail_info        2MB p22 */
    {PART_MISC,                 341 * 1024,     2 * 1024, UFS_PART_3}, /* misc                 2MB p23 */
    {PART_DFX,                  343 * 1024,    16 * 1024, UFS_PART_3}, /* dfx                 16MB p24 */
    {PART_RRECORD,              359 * 1024,    16 * 1024, UFS_PART_3}, /* rrecord             16MB p25 */
    {PART_CACHE,                375 * 1024,   104 * 1024, UFS_PART_3}, /* cache              104MB p26 */
    {PART_METADATA,             479 * 1024,    16 * 1024, UFS_PART_3}, /* metadata            16MB p27 */
    {PART_FW_EMMCDEV,           495 * 1024,     4 * 1024, UFS_PART_3}, /* fw_emmcdev           4MB p28 */
    {PART_TOC,                  499 * 1024,     1 * 1024, UFS_PART_3}, /* toc               1024KB p29 */
    {PART_BL2,                  500 * 1024,     4 * 1024, UFS_PART_3}, /* bl2                  4MB p30 */
    {PART_FW_LPM3,              504 * 1024,          512, UFS_PART_3}, /* fw_lpm3            512KB p31 */
    {PART_FW_CPU_LPCTRL,     (504 * 1024 + 512),          256, UFS_PART_3}, /* fw_cpu_lpctrl      256KB p32 */
    {PART_FW_GPU_LPCTRL,     (504 * 1024 + 768),          128, UFS_PART_3}, /* fw_gpu_lpctrl      128KB p33 */
    {PART_FW_DDR_LPCTRL,     (504 * 1024 + 896),          128, UFS_PART_3}, /* fw_ddr_lpctrl      128KB p34 */
    {PART_NPU,                  505 * 1024,     8 * 1024, UFS_PART_3}, /* npu                  8MB p35 */
    {PART_IVP,                  513 * 1024,     2 * 1024, UFS_PART_3}, /* ivp                  2MB p36 */
    {PART_HDCP,                 515 * 1024,     1 * 1024, UFS_PART_3}, /* hdcp              1024KB p37 */
    {PART_HISEE_IMG,            516 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p38 */
    {PART_HHEE,                 520 * 1024,     4 * 1024, UFS_PART_3}, /* hhee                 4MB p39 */
    {PART_HISEE_FS,             524 * 1024,     8 * 1024, UFS_PART_3}, /* hisee_fs             8MB p40 */
    {PART_FASTBOOT,             532 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p41 */
    {PART_VECTOR,               544 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p42 */
    {PART_ISP_BOOT,             548 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot             2MB p43 */
    {PART_ISP_FIRMWARE,         550 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware        14MB p44 */
    {PART_FW_HIFI,              564 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi             12MB p45 */
    {PART_TEEOS,                576 * 1024,     8 * 1024, UFS_PART_3}, /* teeos                8MB p46 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_bak  24MB p48 */
    {PART_BOOT,                 640 * 1024,    48 * 1024, UFS_PART_3}, /* boot                48MB p49 */
    {PART_UPDATER_BOOT,         688 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     742 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        796 * 1024,          512, UFS_PART_3}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (796 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (798 * 1024 + 512),(50 * 1024+512), UFS_PART_3}, /* reserved3         51712KB p54 */
    {PART_THEE,                 849 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p55 */
    {PART_TZSP,                 853 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p56 */
    {PART_UPDATER_RAMDISK,      865 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk     32MB p57 */
    {PART_UPDATER_VENDOR,       897 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor      24MB p58 */
    {PART_ENG_SYSTEM,           921 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p59 */
    {PART_ENG_CHIPSET,          933 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset         20MB p60 */
    {PART_FW_DTB,               953 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb               8MB p61 */
    {PART_DTBO,                 961 * 1024,    14 * 1024, UFS_PART_3}, /* dtbo                14MB p62 */
    {PART_TRUSTFIRMWARE,        975 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p63 */
    {PART_MODEM_FW,             977 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p64 */
    {PART_MODEM_VENDOR,        1101 * 1024,    30 * 1024, UFS_PART_3}, /* modem_vendor        30MB p65 */
    {PART_MODEM_PATCH_NV,      1131 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p66 */
    {PART_MODEM_DRIVER,        1135 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p67 */
    {PART_MODEMNVM_UPDATE,     1155 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p68 */
    {PART_MODEMNVM_CUST,       1171 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust       16MB p69 */
    {PART_RAMDISK,             1187 * 1024,     4 * 1024, UFS_PART_3}, /* ramdisk              4MB p70 */
    {PART_RVT_SYSTEM,          1191 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system        1024KB p71 */
    {PART_RVT_VENDOR,          1192 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor        1024KB p72 */
    {PART_RVT_CHIP_PROD,       1193 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod     1024KB p73 */
    {PART_RVT_CUST,            1194 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust          1024KB p74 */
    {PART_RVT_SYS_PROD,        1195 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod      1024KB p75 */
    {PART_UPDATER_RVT,         1196 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt          2MB p76 */
    {PART_UPDATER_BAK_RVT,     1198 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt      2MB p77 */
    {PART_RVT,                 1200 * 1024,     4 * 1024, UFS_PART_3}, /* rvt                  4MB p78 */
    {PART_KPATCH,              1204 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p79 */
    {PART_PATCH,               1208 * 1024,    32 * 1024, UFS_PART_3}, /* patch               32MB p80 */
    {PART_RESERVED5,           1240 * 1024,    10 * 1024, UFS_PART_3}, /* reserved5           10MB p81 */
    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, UFS_PART_3}, /* sensorhub          597MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1850 * 1024,   600 * 1024, UFS_PART_3}, /* chip_prod          600MB p84 */
    {PART_VENDOR,              2450 * 1024,  1024 * 1024, UFS_PART_3}, /* vendor            1024 * 1024KB p85 */
    {PART_SYS_PROD,            3474 * 1024,   600 * 1024, UFS_PART_3}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              4074 * 1024,  3666 * 1024, UFS_PART_3}, /* system            3666MB p87 */
    {PART_CUST,                7740 * 1024,    88 * 1024, UFS_PART_3}, /* cust                88MB p88 */
    {PART_VERSION,             7828 * 1024,   200 * 1024, UFS_PART_3}, /* version            200MB p89 */
    {PART_PRELOAD,             8028 * 1024,   520 * 1024, UFS_PART_3}, /* preload            520MB p90 */
    {PART_SENSORHUB_SYSTEM,    8548 * 1024,  1536 * 1024, UFS_PART_3}, /* sensorhub_system  1536MB p91 */
    {PART_SENSORHUB_DATA,     10084 * 1024,  6656 * 1024, UFS_PART_3}, /* sensorhub_data    6656MB p92 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      16740 * 1024,     2 * 1024, UFS_PART_3}, /* conn_calidata        2MB p93 */
    {PART_USERDATA,           16742 * 1024,       (3668 * 1024), UFS_PART_3}, /* userdata       4G p94 */
#else
    {PART_USERDATA,           16740 * 1024, (3668 * 1024), UFS_PART_3}, /* userdata       3668M p89 */
#endif
#else
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_bak  24MB p48 */
    {PART_BOOT,                 640 * 1024,    48 * 1024, UFS_PART_3}, /* boot                48MB p49 */
    {PART_UPDATER_BOOT,         688 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     742 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        796 * 1024,          512, UFS_PART_3}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (796 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (798 * 1024 + 512),(49 * 1024+512), UFS_PART_3}, /* reserved3         50688KB p54 */
#else
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_bak  24MB p48 */
    {PART_BOOT,                 640 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p49 */
    {PART_UPDATER_BOOT,         686 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     740 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        794 * 1024,          512, UFS_PART_3}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (794 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (796 * 1024 + 512),(51 * 1024+512), UFS_PART_3}, /* reserved3         52736KB p54 */
#endif
    {PART_THEE,                 848 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p55 */
    {PART_TZSP,                 852 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p56 */
    {PART_UPDATER_RAMDISK,      864 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk     32MB p57 */
    {PART_UPDATER_VENDOR,       896 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor      24MB p58 */
    {PART_ENG_SYSTEM,           920 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p59 */
    {PART_ENG_CHIPSET,          932 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset         20MB p60 */
    {PART_FW_DTB,               952 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb               8MB p61 */
    {PART_DTBO,                 960 * 1024,    14 * 1024, UFS_PART_3}, /* dtbo                14MB p62 */
    {PART_TRUSTFIRMWARE,        974 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p63 */
    {PART_MODEM_FW,             976 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p64 */
    {PART_MODEM_VENDOR,        1100 * 1024,    10 * 1024, UFS_PART_3}, /* modem_vendor        10MB p65 */
    {PART_MODEM_PATCH_NV,      1110 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p66 */
    {PART_MODEM_DRIVER,        1114 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p67 */
    {PART_MODEMNVM_UPDATE,     1134 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p68 */
    {PART_MODEMNVM_CUST,       1150 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust       16MB p69 */
    {PART_RAMDISK,             1166 * 1024,     4 * 1024, UFS_PART_3}, /* ramdisk              4MB p70 */
    {PART_RVT_SYSTEM,          1170 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system        1024KB p71 */
    {PART_RVT_VENDOR,          1171 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor        1024KB p72 */
    {PART_RVT_CHIP_PROD,       1172 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod     1024KB p73 */
    {PART_RVT_CUST,            1173 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust          1024KB p74 */
    {PART_RVT_SYS_PROD,        1174 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod      1024KB p75 */
    {PART_UPDATER_RVT,         1175 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt          2MB p76 */
    {PART_UPDATER_BAK_RVT,     1177 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt      2MB p77 */
    {PART_RVT,                 1179 * 1024,     4 * 1024, UFS_PART_3}, /* rvt                  4MB p78 */
    {PART_KPATCH,              1183 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p79 */
    {PART_PATCH,               1187 * 1024,    32 * 1024, UFS_PART_3}, /* patch               32MB p80 */
    {PART_RESERVED5,           1219 * 1024,    31 * 1024, UFS_PART_3}, /* reserved5           31MB p81 */
#ifdef CONFIG_FACTORY_MODE
    {PART_SENSORHUB,           1250 * 1024,   125 * 1024, UFS_PART_3}, /* sensorhub          125MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1375 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1378 * 1024,   128 * 1024, UFS_PART_3}, /* chip_prod          128MB p84 */
    {PART_VENDOR,              1506 * 1024,   500 * 1024, UFS_PART_3}, /* vendor             500MB p85 */
    {PART_SYS_PROD,            2006 * 1024,   600 * 1024, UFS_PART_3}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              2606 * 1024,  2988 * 1024, UFS_PART_3}, /* system            2988MB p87 */
    {PART_HIBENCH_IMG,         5594 * 1024,    40 * 1024, UFS_PART_3}, /* hibench_img         40MB p88 */
    {PART_HIBENCH_DATA,        5634 * 1024,   600 * 1024, UFS_PART_3}, /* hibench_data       600MB p89 */
    {PART_FLASH_AGEING,        6234 * 1024,   512 * 1024, UFS_PART_3}, /* flash_ageing       512MB p90 */
    {PART_HIBENCH_LOG,         6746 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p91 */
    {PART_HIBENCH_LPM3,        6778 * 1024,     2 * 1024, UFS_PART_3}, /* hibench_lpm3         2MB p92 */
    {PART_RESERVED4,           6780 * 1024,   178 * 1024, UFS_PART_3}, /* reserved4          178MB p93 */
    {PART_CUST,                6958 * 1024,    88 * 1024, UFS_PART_3}, /* cust                88MB p94 */
    {PART_VERSION,             7046 * 1024,   200 * 1024, UFS_PART_3}, /* version            200MB p95 */
    {PART_PRELOAD,             7246 * 1024,   520 * 1024, UFS_PART_3}, /* preload            520MB p96 */
    {PART_SENSORHUB_SYSTEM,    7766 * 1024,  1536 * 1024, UFS_PART_3}, /* sensorhub_system  1536MB p97 */
    {PART_SENSORHUB_DATA,      9302 * 1024,  6656 * 1024, UFS_PART_3}, /* sensorhub_data    6656MB p98 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      15958 * 1024,     2 * 1024, UFS_PART_3}, /* conn_calidata        2MB p99 */
    {PART_USERDATA,           15960 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p100 */
#else
    {PART_USERDATA,           15958 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p99 */
#endif
#else
    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, UFS_PART_3}, /* sensorhub          597MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1850 * 1024,   600 * 1024, UFS_PART_3}, /* chip_prod          600MB p84 */
    {PART_VENDOR,              2450 * 1024,   920 * 1024, UFS_PART_3}, /* vendor             920MB p85 */
    {PART_SYS_PROD,            3370 * 1024,   600 * 1024, UFS_PART_3}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              3970 * 1024,  2988 * 1024, UFS_PART_3}, /* system            2988MB p87 */
    {PART_CUST,                6958 * 1024,    88 * 1024, UFS_PART_3}, /* cust                88MB p88 */
    {PART_VERSION,             7046 * 1024,   200 * 1024, UFS_PART_3}, /* version            200MB p89 */
    {PART_PRELOAD,             7246 * 1024,   520 * 1024, UFS_PART_3}, /* preload            520MB p90 */
#ifdef CONFIG_PARTITION_ENG
    {PART_FTTEST,              7766 * 1024,   192 * 1024, UFS_PART_3}, /* fttest             192MB p91 */
    {PART_DDRTEST,             7958 * 1024,    48 * 1024, UFS_PART_3}, /* ddrtest             48MB p92 */
    {PART_HIBENCH_LPM3,        8006 * 1024,     2 * 1024, UFS_PART_3}, /* hibench_lpm3         2MB p93 */
    {PART_HITEST_ASP_DHRYSTONE,  8008 * 1024,     2 * 1024, UFS_PART_3}, /* hitest_asp_dhrystone   2MB p94 */
    {PART_HITEST_ASP_TEST,     8010 * 1024,    30 * 1024, UFS_PART_3}, /* hitest_asp_test     30MB p95 */
    {PART_HITEST_GPU,          8040 * 1024,   100 * 1024, UFS_PART_3}, /* hitest_gpu         100MB p96 */
    {PART_HITEST_GPU_1,        8140 * 1024,   256 * 1024, UFS_PART_3}, /* hitest_gpu_1       256MB p97 */
    {PART_HITEST_NPU,          8396 * 1024,    64 * 1024, UFS_PART_3}, /* hitest_npu          64MB p98 */
    {PART_HITEST_JPEGENC,      8460 * 1024,   200 * 1024, UFS_PART_3}, /* hitest_jpegenc     200MB p99 */
    {PART_HITEST_SENSORHUB,    8660 * 1024,     6 * 1024, UFS_PART_3}, /* hitest_sensorhub     6MB p100 */
    {PART_VCODE_DATA,          8666 * 1024,   140 * 1024, UFS_PART_3}, /* vcode_data         140MB p101 */
    {PART_VCODE_MAX_DATA,      8806 * 1024,   140 * 1024, UFS_PART_3}, /* vcode_max_data     140MB p102 */
    {PART_DSS_DISP_BUF,        8946 * 1024,    64 * 1024, UFS_PART_3}, /* dss_disp_buf        64MB p103 */
    {PART_MODEM_TSP_TEST,      9010 * 1024,    10 * 1024, UFS_PART_3}, /* modem_tsp_test      10MB p104 */
    {PART_MODEM_TSP_DT,        9020 * 1024,     2 * 1024, UFS_PART_3}, /* modem_tsp_dt         2MB p105 */
    {PART_MODEM_TSP_AVS,       9022 * 1024,    80 * 1024, UFS_PART_3}, /* modem_tsp_avs       80MB p106 */
    {PART_MODEM_PDE_TEST,      9102 * 1024,     4 * 1024, UFS_PART_3}, /* modem_pde_test       4MB p107 */
    {PART_MODEM_L2DLE,         9106 * 1024,     4 * 1024, UFS_PART_3}, /* modem_l2dle          4MB p108 */
    {PART_MODEM_VECTOR_CONFIG,  9110 * 1024,     4 * 1024, UFS_PART_3}, /* modem_vector_config   4MB p109 */
    {PART_SENSORHUB_SYSTEM,    9114 * 1024,  1792 * 1024, UFS_PART_3}, /* sensorhub_system  1792MB p110 */
    {PART_SENSORHUB_DATA,     10906 * 1024, 18688 * 1024, UFS_PART_3}, /* sensorhub_data    18688MB p111 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      29594 * 1024,     2 * 1024, UFS_PART_3}, /* conn_calidata        2MB p112 */
    {PART_USERDATA,           29596 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p113 */
#else
    {PART_USERDATA,           29594 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p112 */
#endif
#else
    {PART_SENSORHUB_SYSTEM,    7766 * 1024,  1536 * 1024, UFS_PART_3}, /* sensorhub_system  1536MB p91 */
    {PART_SENSORHUB_DATA,      9302 * 1024,  6656 * 1024, UFS_PART_3}, /* sensorhub_data    6656MB p92 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      15958 * 1024,     2 * 1024, UFS_PART_3}, /* conn_calidata        2MB p93 */
    {PART_USERDATA,           15960 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p94 */
#else
    {PART_USERDATA,           15958 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p93 */
#endif
#endif
#endif
#endif
    {"0", 0, 0, 0},
};
static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                0,             2 * 1024,    UFS_PART_0},
    {PART_RESERVED0,              0,             2 * 1024,    UFS_PART_1},
    {PART_PTABLE,                 0,                  512,    UFS_PART_2}, /* ptable           512K    p0 */
    {PART_RPMB_RESERVED,        512,       1024 + 512, UFS_PART_2}, /* rpmb_reserved     1536KB p1 */
    {PART_RPMB_SECOS,      2 * 1024,        14 * 1024, UFS_PART_2}, /* rpmb_secos          14MB p2 */
    {PART_PTABLE_LU3,             0,          512, UFS_PART_3}, /* ptable           512K    p0 */
    {PART_FRP,                                512,   512, UFS_PART_3}, /* frp                512KB p1 */
    {PART_PERSIST,                    1024,     6 * 1024, UFS_PART_3}, /* persist              6MB p2 */
    {PART_RESERVED1,              7 * 1024,         1536, UFS_PART_3}, /* reserved1         1536KB p3 */
    {PART_VRL,               (8 * 1024 + 512),          512, UFS_PART_3}, /* vrl                512KB p4 */
    {PART_VRL_BACKUP,             9 * 1024,          512, UFS_PART_3}, /* vrl_backup         512KB p5 */
    {PART_MODEM_SECURE,      (9 * 1024 + 512),         8704, UFS_PART_3}, /* modem_secure      8704KB p6 */
    {PART_NVME,                  18 * 1024,     5 * 1024, UFS_PART_3}, /* nvme                 5MB p7 */
    {PART_CTF,                   23 * 1024,     1 * 1024, UFS_PART_3}, /* ctf               1024KB p8 */
    {PART_OEMINFO,               24 * 1024,    96 * 1024, UFS_PART_3}, /* oeminfo             96MB p9 */
    {PART_SECURE_STORAGE,       120 * 1024,    32 * 1024, UFS_PART_3}, /* secure_storage      32MB p10 */
    {PART_MODEMNVM_FACTORY,     152 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_factory    16MB p11 */
    {PART_MODEMNVM_BACKUP,      168 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_backup     16MB p12 */
    {PART_MODEMNVM_IMG,         184 * 1024,    46 * 1024, UFS_PART_3}, /* modemnvm_img        46MB p13 */
    {PART_HISEE_ENCOS,          230 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_encos          4MB p14 */
    {PART_VERITYKEY,            234 * 1024,     1 * 1024, UFS_PART_3}, /* veritykey         1024KB p15 */
    {PART_DDR_PARA,             235 * 1024,     1 * 1024, UFS_PART_3}, /* ddr_para          1024KB p16 */
    {PART_LOWPOWER_PARA,        236 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para     1024KB p17 */
    {PART_BATT_TP_PARA,         237 * 1024,     1 * 1024, UFS_PART_3}, /* batt_tp_para      1024KB p18 */
    {PART_DACC,                 238 * 1024,          512, UFS_PART_3}, /* dacc               512KB p19 */
    {PART_RESERVED2,         (238 * 1024 + 512),(20 * 1024+512), UFS_PART_3}, /* reserved2         20992KB p20 */
    {PART_LOG,                  259 * 1024,    80 * 1024, UFS_PART_3}, /* log                 80MB p21 */
    {PART_BOOTFAIL_INFO,        339 * 1024,     2 * 1024, UFS_PART_3}, /* bootfail_info        2MB p22 */
    {PART_MISC,                 341 * 1024,     2 * 1024, UFS_PART_3}, /* misc                 2MB p23 */
    {PART_DFX,                  343 * 1024,    16 * 1024, UFS_PART_3}, /* dfx                 16MB p24 */
    {PART_RRECORD,              359 * 1024,    16 * 1024, UFS_PART_3}, /* rrecord             16MB p25 */
    {PART_CACHE,                375 * 1024,   104 * 1024, UFS_PART_3}, /* cache              104MB p26 */
    {PART_METADATA,             479 * 1024,    16 * 1024, UFS_PART_3}, /* metadata            16MB p27 */
    {PART_FW_EMMCDEV,           495 * 1024,     4 * 1024, UFS_PART_3}, /* fw_emmcdev           4MB p28 */
    {PART_TOC,                  499 * 1024,     1 * 1024, UFS_PART_3}, /* toc               1024KB p29 */
    {PART_BL2,                  500 * 1024,     4 * 1024, UFS_PART_3}, /* bl2                  4MB p30 */
    {PART_FW_LPM3,              504 * 1024,          512, UFS_PART_3}, /* fw_lpm3            512KB p31 */
    {PART_FW_CPU_LPCTRL,     (504 * 1024 + 512),          256, UFS_PART_3}, /* fw_cpu_lpctrl      256KB p32 */
    {PART_FW_GPU_LPCTRL,     (504 * 1024 + 768),          128, UFS_PART_3}, /* fw_gpu_lpctrl      128KB p33 */
    {PART_FW_DDR_LPCTRL,     (504 * 1024 + 896),          128, UFS_PART_3}, /* fw_ddr_lpctrl      128KB p34 */
    {PART_NPU,                  505 * 1024,     8 * 1024, UFS_PART_3}, /* npu                  8MB p35 */
    {PART_IVP,                  513 * 1024,     2 * 1024, UFS_PART_3}, /* ivp                  2MB p36 */
    {PART_HDCP,                 515 * 1024,     1 * 1024, UFS_PART_3}, /* hdcp              1024KB p37 */
    {PART_HISEE_IMG,            516 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p38 */
    {PART_HHEE,                 520 * 1024,     4 * 1024, UFS_PART_3}, /* hhee                 4MB p39 */
    {PART_HISEE_FS,             524 * 1024,     8 * 1024, UFS_PART_3}, /* hisee_fs             8MB p40 */
    {PART_FASTBOOT,             532 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p41 */
    {PART_VECTOR,               544 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p42 */
    {PART_ISP_BOOT,             548 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot             2MB p43 */
    {PART_ISP_FIRMWARE,         550 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware        14MB p44 */
    {PART_FW_HIFI,              564 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi             12MB p45 */
    {PART_TEEOS,                576 * 1024,     8 * 1024, UFS_PART_3}, /* teeos                8MB p46 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_bak  24MB p48 */
    {PART_BOOT,                 640 * 1024,    48 * 1024, UFS_PART_3}, /* boot                48MB p49 */
    {PART_UPDATER_BOOT,         688 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     742 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        796 * 1024,          512, UFS_PART_3}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (796 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (798 * 1024 + 512),(50 * 1024+512), UFS_PART_3}, /* reserved3         51712KB p54 */
    {PART_THEE,                 849 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p55 */
    {PART_TZSP,                 853 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p56 */
    {PART_UPDATER_RAMDISK,      865 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk     32MB p57 */
    {PART_UPDATER_VENDOR,       897 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor      24MB p58 */
    {PART_ENG_SYSTEM,           921 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p59 */
    {PART_ENG_CHIPSET,          933 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset         20MB p60 */
    {PART_FW_DTB,               953 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb               8MB p61 */
    {PART_DTBO,                 961 * 1024,    14 * 1024, UFS_PART_3}, /* dtbo                14MB p62 */
    {PART_TRUSTFIRMWARE,        975 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p63 */
    {PART_MODEM_FW,             977 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p64 */
    {PART_MODEM_VENDOR,        1101 * 1024,    30 * 1024, UFS_PART_3}, /* modem_vendor        30MB p65 */
    {PART_MODEM_PATCH_NV,      1131 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p66 */
    {PART_MODEM_DRIVER,        1135 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p67 */
    {PART_MODEMNVM_UPDATE,     1155 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p68 */
    {PART_MODEMNVM_CUST,       1171 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust       16MB p69 */
    {PART_RAMDISK,             1187 * 1024,     4 * 1024, UFS_PART_3}, /* ramdisk              4MB p70 */
    {PART_RVT_SYSTEM,          1191 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system        1024KB p71 */
    {PART_RVT_VENDOR,          1192 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor        1024KB p72 */
    {PART_RVT_CHIP_PROD,       1193 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod     1024KB p73 */
    {PART_RVT_CUST,            1194 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust          1024KB p74 */
    {PART_RVT_SYS_PROD,        1195 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod      1024KB p75 */
    {PART_UPDATER_RVT,         1196 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt          2MB p76 */
    {PART_UPDATER_BAK_RVT,     1198 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt      2MB p77 */
    {PART_RVT,                 1200 * 1024,     4 * 1024, UFS_PART_3}, /* rvt                  4MB p78 */
    {PART_KPATCH,              1204 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p79 */
    {PART_PATCH,               1208 * 1024,    32 * 1024, UFS_PART_3}, /* patch               32MB p80 */
    {PART_RESERVED5,           1240 * 1024,    10 * 1024, UFS_PART_3}, /* reserved5           10MB p81 */
    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, UFS_PART_3}, /* sensorhub          597MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1850 * 1024,   600 * 1024, UFS_PART_3}, /* chip_prod          600MB p84 */
    {PART_VENDOR,              2450 * 1024,  1024 * 1024, UFS_PART_3}, /* vendor            1024 * 1024KB p85 */
    {PART_SYS_PROD,            3474 * 1024,   600 * 1024, UFS_PART_3}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              4074 * 1024,  3666 * 1024, UFS_PART_3}, /* system            3666MB p87 */
    {PART_CUST,                7740 * 1024,    88 * 1024, UFS_PART_3}, /* cust                88MB p88 */
    {PART_VERSION,             7828 * 1024,   200 * 1024, UFS_PART_3}, /* version            200MB p89 */
    {PART_PRELOAD,             8028 * 1024,   520 * 1024, UFS_PART_3}, /* preload            520MB p90 */
    {PART_SENSORHUB_SYSTEM,    8548 * 1024,  1536 * 1024, UFS_PART_3}, /* sensorhub_system  1536MB p91 */
    {PART_SENSORHUB_DATA,     10084 * 1024,  6656 * 1024, UFS_PART_3}, /* sensorhub_data    6656MB p92 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      16740 * 1024,     2 * 1024, UFS_PART_3}, /* conn_calidata        2MB p93 */
    {PART_USERDATA,           16742 * 1024,       (3668 * 1024), UFS_PART_3}, /* userdata       4G p94 */
#else
    {PART_USERDATA,           16740 * 1024,       (3668 * 1024), UFS_PART_3}, /* userdata       4G p93 */
#endif
#else
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_bak  24MB p48 */
    {PART_BOOT,                 640 * 1024,    48 * 1024, UFS_PART_3}, /* boot                48MB p49 */
    {PART_UPDATER_BOOT,         688 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     742 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        796 * 1024,          512, UFS_PART_3}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (796 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (798 * 1024 + 512),(49 * 1024+512), UFS_PART_3}, /* reserved3         50688KB p54 */
#else
    {PART_UPDATER_RAMDISK_BAK,   584 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak  32MB p47 */
    {PART_UPDATER_VENDOR_BAK,   616 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_bak  24MB p48 */
    {PART_BOOT,                 640 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p49 */
    {PART_UPDATER_BOOT,         686 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot        54MB p50 */
    {PART_UPDATER_BOOT_BAK,     740 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot_bak    54MB p51 */
    {PART_MODULE_UPDATE,        794 * 1024,          512, UFS_PART_3}, /* module_update      512KB p52 */
    {PART_EXT_RVT,           (794 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p53 */
    {PART_RESERVED3,         (796 * 1024 + 512),(51 * 1024+512), UFS_PART_3}, /* reserved3         52736KB p54 */
#endif
    {PART_THEE,                 848 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p55 */
    {PART_TZSP,                 852 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p56 */
    {PART_UPDATER_RAMDISK,      864 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk     32MB p57 */
    {PART_UPDATER_VENDOR,       896 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor      24MB p58 */
    {PART_ENG_SYSTEM,           920 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p59 */
    {PART_ENG_CHIPSET,          932 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset         20MB p60 */
    {PART_FW_DTB,               952 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb               8MB p61 */
    {PART_DTBO,                 960 * 1024,    14 * 1024, UFS_PART_3}, /* dtbo                14MB p62 */
    {PART_TRUSTFIRMWARE,        974 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p63 */
    {PART_MODEM_FW,             976 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p64 */
    {PART_MODEM_VENDOR,        1100 * 1024,    10 * 1024, UFS_PART_3}, /* modem_vendor        10MB p65 */
    {PART_MODEM_PATCH_NV,      1110 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p66 */
    {PART_MODEM_DRIVER,        1114 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p67 */
    {PART_MODEMNVM_UPDATE,     1134 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p68 */
    {PART_MODEMNVM_CUST,       1150 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust       16MB p69 */
    {PART_RAMDISK,             1166 * 1024,     4 * 1024, UFS_PART_3}, /* ramdisk              4MB p70 */
    {PART_RVT_SYSTEM,          1170 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system        1024KB p71 */
    {PART_RVT_VENDOR,          1171 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor        1024KB p72 */
    {PART_RVT_CHIP_PROD,       1172 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod     1024KB p73 */
    {PART_RVT_CUST,            1173 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust          1024KB p74 */
    {PART_RVT_SYS_PROD,        1174 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod      1024KB p75 */
    {PART_UPDATER_RVT,         1175 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt          2MB p76 */
    {PART_UPDATER_BAK_RVT,     1177 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt      2MB p77 */
    {PART_RVT,                 1179 * 1024,     4 * 1024, UFS_PART_3}, /* rvt                  4MB p78 */
    {PART_KPATCH,              1183 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p79 */
    {PART_PATCH,               1187 * 1024,    32 * 1024, UFS_PART_3}, /* patch               32MB p80 */
    {PART_RESERVED5,           1219 * 1024,    31 * 1024, UFS_PART_3}, /* reserved5           31MB p81 */
#ifdef CONFIG_FACTORY_MODE
    {PART_SENSORHUB,           1250 * 1024,   125 * 1024, UFS_PART_3}, /* sensorhub          125MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1375 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1378 * 1024,   128 * 1024, UFS_PART_3}, /* chip_prod          128MB p84 */
    {PART_VENDOR,              1506 * 1024,   500 * 1024, UFS_PART_3}, /* vendor             500MB p85 */
    {PART_SYS_PROD,            2006 * 1024,   600 * 1024, UFS_PART_3}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              2606 * 1024,  2988 * 1024, UFS_PART_3}, /* system            2988MB p87 */
    {PART_HIBENCH_IMG,         5594 * 1024,    40 * 1024, UFS_PART_3}, /* hibench_img         40MB p88 */
    {PART_HIBENCH_DATA,        5634 * 1024,   600 * 1024, UFS_PART_3}, /* hibench_data       600MB p89 */
    {PART_FLASH_AGEING,        6234 * 1024,   512 * 1024, UFS_PART_3}, /* flash_ageing       512MB p90 */
    {PART_HIBENCH_LOG,         6746 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p91 */
    {PART_HIBENCH_LPM3,        6778 * 1024,     2 * 1024, UFS_PART_3}, /* hibench_lpm3         2MB p92 */
    {PART_RESERVED4,           6780 * 1024,   178 * 1024, UFS_PART_3}, /* reserved4          178MB p93 */
    {PART_CUST,                6958 * 1024,    88 * 1024, UFS_PART_3}, /* cust                88MB p94 */
    {PART_VERSION,             7046 * 1024,   200 * 1024, UFS_PART_3}, /* version            200MB p95 */
    {PART_PRELOAD,             7246 * 1024,   520 * 1024, UFS_PART_3}, /* preload            520MB p96 */
    {PART_SENSORHUB_SYSTEM,    7766 * 1024,  1536 * 1024, UFS_PART_3}, /* sensorhub_system  1536MB p97 */
    {PART_SENSORHUB_DATA,      9302 * 1024,  6656 * 1024, UFS_PART_3}, /* sensorhub_data    6656MB p98 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      15958 * 1024,     2 * 1024, UFS_PART_3}, /* conn_calidata        2MB p99 */
    {PART_USERDATA,           15960 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p100 */
#else
    {PART_USERDATA,           15958 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p99 */
#endif
#else
    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, UFS_PART_3}, /* sensorhub          597MB p82 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p83 */
    {PART_CHIP_PROD,           1850 * 1024,   600 * 1024, UFS_PART_3}, /* chip_prod          600MB p84 */
    {PART_VENDOR,              2450 * 1024,   920 * 1024, UFS_PART_3}, /* vendor             920MB p85 */
    {PART_SYS_PROD,            3370 * 1024,   600 * 1024, UFS_PART_3}, /* sys_prod           600MB p86 */
    {PART_SYSTEM,              3970 * 1024,  2988 * 1024, UFS_PART_3}, /* system            2988MB p87 */
    {PART_CUST,                6958 * 1024,    88 * 1024, UFS_PART_3}, /* cust                88MB p88 */
    {PART_VERSION,             7046 * 1024,   200 * 1024, UFS_PART_3}, /* version            200MB p89 */
    {PART_PRELOAD,             7246 * 1024,   520 * 1024, UFS_PART_3}, /* preload            520MB p90 */
#ifdef CONFIG_PARTITION_ENG
    {PART_FTTEST,              7766 * 1024,   192 * 1024, UFS_PART_3}, /* fttest             192MB p91 */
    {PART_DDRTEST,             7958 * 1024,    48 * 1024, UFS_PART_3}, /* ddrtest             48MB p92 */
    {PART_HIBENCH_LPM3,        8006 * 1024,     2 * 1024, UFS_PART_3}, /* hibench_lpm3         2MB p93 */
    {PART_HITEST_ASP_DHRYSTONE,  8008 * 1024,     2 * 1024, UFS_PART_3}, /* hitest_asp_dhrystone   2MB p94 */
    {PART_HITEST_ASP_TEST,     8010 * 1024,    30 * 1024, UFS_PART_3}, /* hitest_asp_test     30MB p95 */
    {PART_HITEST_GPU,          8040 * 1024,   100 * 1024, UFS_PART_3}, /* hitest_gpu         100MB p96 */
    {PART_HITEST_GPU_1,        8140 * 1024,   256 * 1024, UFS_PART_3}, /* hitest_gpu_1       256MB p97 */
    {PART_HITEST_NPU,          8396 * 1024,    64 * 1024, UFS_PART_3}, /* hitest_npu          64MB p98 */
    {PART_HITEST_JPEGENC,      8460 * 1024,   200 * 1024, UFS_PART_3}, /* hitest_jpegenc     200MB p99 */
    {PART_HITEST_SENSORHUB,    8660 * 1024,     6 * 1024, UFS_PART_3}, /* hitest_sensorhub     6MB p100 */
    {PART_VCODE_DATA,          8666 * 1024,   140 * 1024, UFS_PART_3}, /* vcode_data         140MB p101 */
    {PART_VCODE_MAX_DATA,      8806 * 1024,   140 * 1024, UFS_PART_3}, /* vcode_max_data     140MB p102 */
    {PART_DSS_DISP_BUF,        8946 * 1024,    64 * 1024, UFS_PART_3}, /* dss_disp_buf        64MB p103 */
    {PART_MODEM_TSP_TEST,      9010 * 1024,    10 * 1024, UFS_PART_3}, /* modem_tsp_test      10MB p104 */
    {PART_MODEM_TSP_DT,        9020 * 1024,     2 * 1024, UFS_PART_3}, /* modem_tsp_dt         2MB p105 */
    {PART_MODEM_TSP_AVS,       9022 * 1024,    80 * 1024, UFS_PART_3}, /* modem_tsp_avs       80MB p106 */
    {PART_MODEM_PDE_TEST,      9102 * 1024,     4 * 1024, UFS_PART_3}, /* modem_pde_test       4MB p107 */
    {PART_MODEM_L2DLE,         9106 * 1024,     4 * 1024, UFS_PART_3}, /* modem_l2dle          4MB p108 */
    {PART_MODEM_VECTOR_CONFIG,  9110 * 1024,     4 * 1024, UFS_PART_3}, /* modem_vector_config   4MB p109 */
    {PART_SENSORHUB_SYSTEM,    9114 * 1024,  1536 * 1024, UFS_PART_3}, /* sensorhub_system  1536MB p110 */
    {PART_SENSORHUB_DATA,     10650 * 1024,  6656 * 1024, UFS_PART_3}, /* sensorhub_data    6656MB p111 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      17306 * 1024,     2 * 1024, UFS_PART_3}, /* conn_calidata        2MB p112 */
    {PART_USERDATA,           17308 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p113 */
#else
    {PART_USERDATA,           17306 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p112 */
#endif
#else
    {PART_SENSORHUB_SYSTEM,    7766 * 1024,  1536 * 1024, UFS_PART_3}, /* sensorhub_system  1536MB p91 */
    {PART_SENSORHUB_DATA,      9302 * 1024,  6656 * 1024, UFS_PART_3}, /* sensorhub_data    6656MB p92 */
#ifdef CONFIG_CONN_CALIDATA
    {PART_CONN_CALIDATA,      15958 * 1024,     2 * 1024, UFS_PART_3}, /* conn_calidata        2MB p93 */
    {PART_USERDATA,           15960 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p94 */
#else
    {PART_USERDATA,           15958 * 1024, (4UL * 1024 * 1024), UFS_PART_3}, /* userdata       4G p93 */
#endif
#endif
#endif
#endif
    {"0", 0, 0, 0},
};

#endif
