#ifndef _PISCES_PLAT_PARTITION_OHOS_H_
#define _PISCES_PLAT_PARTITION_OHOS_H_

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
    {PART_FRP,                        512,          512, UFS_PART_2}, /* frp                512KB p1 */
    {PART_PERSIST,                   1024,     6 * 1024, UFS_PART_2}, /* persist              6MB p2 */
    {PART_RESERVED1,             7 * 1024,         1024, UFS_PART_2}, /* reserved1         1024KB p3 */
    {PART_PTABLE_LU3,             0,                   512,    UFS_PART_3}, /* ptable_lu3       512K    p0 */
    {PART_VRL,                        512,          512, UFS_PART_3}, /* vrl                512KB p1 */
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
    {PART_RESERVED2,           230 * 1024,    21 * 1024, UFS_PART_3}, /* reserved2           21MB p17 */
    {PART_LOG,                 251 * 1024,    80 * 1024, UFS_PART_3}, /* log                 80MB p18 */
    {PART_BOOTFAIL_INFO,       331 * 1024,     2 * 1024, UFS_PART_3}, /* bootfail_info        2MB p19 */
    {PART_MISC,                333 * 1024,     2 * 1024, UFS_PART_3}, /* misc                 2MB p20 */
    {PART_DFX,                 335 * 1024,    16 * 1024, UFS_PART_3}, /* dfx                 16MB p21 */
    {PART_RRECORD,             351 * 1024,    16 * 1024, UFS_PART_3}, /* rrecord             16MB p22 */
    {PART_CACHE,               367 * 1024,   104 * 1024, UFS_PART_3}, /* cache              104MB p23 */
    {PART_METADATA,            471 * 1024,    16 * 1024, UFS_PART_3}, /* metadata            16MB p24 */
    {PART_SEPLAT,              487 * 1024,     4 * 1024, UFS_PART_3}, /* seplat               4MB p25 */
    {PART_TOC,                 491 * 1024,     1 * 1024, UFS_PART_3}, /* toc               1024KB p26 */
    {PART_BL2,                 492 * 1024,     4 * 1024, UFS_PART_3}, /* bl2                  4MB p27 */
    {PART_FW_LPM3,             496 * 1024,          512, UFS_PART_3}, /* fw_lpm3            512KB p28 */
    {PART_FW_CPU_LPCTRL,       (496 * 1024 + 512),          256, UFS_PART_3}, /* fw_cpu_lpctrl            256K    p29 */
    {PART_FW_GPU_LPCTRL,       (496 * 1024 + 768),          128, UFS_PART_3}, /* fw_gpu_lpctrl            128K    p30 */
    {PART_FW_DDR_LPCTRL,       (496 * 1024 + 896),          128, UFS_PART_3}, /* fw_ddr_lpctrl            128K    p31 */
    {PART_NPU,                 497 * 1024,     8 * 1024, UFS_PART_3}, /* npu                  8MB p32 */
    {PART_IVP,                 505 * 1024,     2 * 1024, UFS_PART_3}, /* ivp                  2MB p33 */
    {PART_DACC,                507 * 1024,          512, UFS_PART_3}, /* dacc               512KB p34 */
    {PART_VENC,                (507 * 1024 + 512),  512, UFS_PART_3}, /* venc               512KB p35 */
    {PART_HISEE_IMG,           508 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p36 */
    {PART_HHEE,                512 * 1024,     4 * 1024, UFS_PART_3}, /* hhee                 4MB p37 */
    {PART_HISEE_FS,            516 * 1024,     8 * 1024, UFS_PART_3}, /* hisee_fs             8MB p38 */
    {PART_FASTBOOT,            524 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p39 */
    {PART_VECTOR,              536 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p40 */
    {PART_ISP_BOOT,            540 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot             2MB p41 */
    {PART_ISP_FIRMWARE,        542 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware        14MB p42 */
    {PART_FW_HIFI,             556 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi             12MB p43 */
    {PART_TEEOS,               568 * 1024,     8 * 1024, UFS_PART_3}, /* teeos                8MB p44 */
    {PART_SENSORHUB,           576 * 1024,    13 * 1024, UFS_PART_3}, /* sensorhub           13MB p45 */
    {PART_SENSORHUB_LOG_DIC,   589 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p46 */
    {PART_HKRR,                592 * 1024,    16 * 1024, UFS_PART_3}, /* hkrr                16MB p47 */
    {PART_FW_UFSDEV,           608 * 1024,     4 * 1024, UFS_PART_3}, /* fw_ufsdev            4MB p48 */
    {PART_RESERVED4,           612 * 1024,    20 * 1024, UFS_PART_3}, /* reserved4           20MB p49 */
    {PART_UPDATER_RAMDISK,     632 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk     32MB p50 */
    {PART_UPDATER_VENDOR,      664 * 1024,    28 * 1024, UFS_PART_3}, /* updater_vendor      28MB p51 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_BOOT,                692 * 1024,    48 * 1024, UFS_PART_3}, /* boot                48MB p52 */
    {PART_UPDATER_BOOT,        740 * 1024,    55 * 1024, UFS_PART_3}, /* updater_boot        55MB p53 */
    {PART_UPDATER_BOOT_BAK,    795 * 1024,    55 * 1024, UFS_PART_3}, /* updater_boot_bak    55MB p54 */
    {PART_MODULE_UPDATE,       850 * 1024,          512, UFS_PART_3}, /* module_update      512KB p55 */
    {PART_EXT_RVT,     (850 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p56 */
    {PART_RESERVED,    (852 * 1024 + 512), (40 * 1024 + 512), UFS_PART_3}, /* reserved     40.5MB p57 */
    {PART_THEE,                893 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p58 */
    {PART_TZSP,                897 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p59 */
    {PART_UPDATER_RAMDISK_BAK,   909 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak  32MB p60 */
    {PART_UPDATER_VENDOR_BAK,   941 * 1024,    28 * 1024, UFS_PART_3}, /* updater_vendor_bak  28MB p61 */
    {PART_ENG_SYSTEM,           969 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p62 */
    {PART_ENG_CHIPSET,          981 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset          20MB p63 */
    {PART_FW_DTB,              1001 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb               8MB p64 */
    {PART_DTBO,                1009 * 1024,    14 * 1024, UFS_PART_3}, /* dtbo                14MB p65 */
    {PART_TRUSTFIRMWARE,       1023 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p66 */
    {PART_MODEM_FW,           1025 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p67 */
    {PART_MODEM_VENDOR,       1149 * 1024,    32 * 1024, UFS_PART_3}, /* modem_vendor        32MB p68 */
    {PART_MODEM_PATCH_NV,     1181 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p69 */
    {PART_MODEM_DRIVER,       1185 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p70 */
    {PART_MODEMNVM_UPDATE,    1205 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p71 */
    {PART_MODEMNVM_CUST,      1221 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust       16MB p72 */
    {PART_RAMDISK,            1237 * 1024,     3 * 1024, UFS_PART_3}, /* ramdisk              3MB p73 */
    {PART_RVT_SYSTEM,         1240 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system        1024KB p74 */
    {PART_RVT_VENDOR,         1241 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor        1024KB p75 */
    {PART_RVT_CHIP_PROD,      1242 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod     1024KB p76 */
    {PART_RVT_CUST,           1243 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust          1024KB p77 */
    {PART_RVT_SYS_PROD,       1244 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod      1024KB p78 */
    {PART_UPDATER_RVT,        1245 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt          2MB p79 */
    {PART_UPDATER_BAK_RVT,    1247 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt      2MB p80 */
    {PART_RVT,                1249 * 1024,     4 * 1024, UFS_PART_3}, /* rvt                  4MB p81 */
    {PART_KPATCH,             1253 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p82 */
    {PART_PATCH,              1257 * 1024,    64 * 1024, UFS_PART_3}, /* patch               64MB p83 */
    {PART_CUST,               1321 * 1024,    56 * 1024, UFS_PART_3}, /* cust                56MB p84 */
    {PART_CHIP_PROD,          1377 * 1024,   942 * 1024, UFS_PART_3}, /* chip_prod          942MB p85 */
    {PART_VENDOR,             2319 * 1024,  3072 * 1024, UFS_PART_3}, /* vendor             3072MB p86 */
    {PART_SYS_PROD,           5391 * 1024,  1746 * 1024, UFS_PART_3}, /* sys_prod          1746MB p87 */
    {PART_SYSTEM,             7137 * 1024,  7968 * 1024, UFS_PART_3}, /* system            7968MB p88 */
    {PART_HYPERHOLD,          15105 * 1024,    4 * 1024, UFS_PART_3}, /* hyperhold            4MB p89 */
    {PART_RESERVED5,          15109 * 1024,    629 * 1024, UFS_PART_3}, /* reserved5          629MB p90 */
    {PART_VERSION,            15738 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p91 */
    {PART_PRELOAD,            16314 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p92 */
    {PART_USERDATA,           17714 * 1024,(15UL) * 1024 * 1024, UFS_PART_3}, /* userdata       6G p93 */
#else
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_BOOT,                692 * 1024,    48 * 1024, UFS_PART_3}, /* boot                48MB p52 */
    {PART_UPDATER_BOOT,        740 * 1024,    57 * 1024, UFS_PART_3}, /* updater_boot        57MB p53 */
    {PART_UPDATER_BOOT_BAK,    797 * 1024,    57 * 1024, UFS_PART_3}, /* updater_boot_bak    57MB p54 */
    {PART_RESERVED,            854 * 1024,    17 * 1024, UFS_PART_3}, /* reserved            17MB p55 */
#else
    {PART_BOOT,                692 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p52 */
    {PART_UPDATER_BOOT,        738 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot        54MB p53 */
    {PART_UPDATER_BOOT_BAK,    792 * 1024,    54 * 1024, UFS_PART_3}, /* updater_boot_bak    54MB p54 */
    {PART_RESERVED,            846 * 1024,    25 * 1024, UFS_PART_3}, /* reserved            25MB p55 */
#endif
    {PART_ENG_SYSTEM,          871 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p56 */
    {PART_THEE,                883 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p57 */
    {PART_TZSP,                887 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p58 */
    {PART_UPDATER_RAMDISK_BAK, 899 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak  32MB p59 */
    {PART_UPDATER_VENDOR_BAK,  931 * 1024,    28 * 1024, UFS_PART_3}, /* updater_vendor_bak  28MB p60 */
    {PART_MODULE_UPDATE,       959 * 1024,          512, UFS_PART_3}, /* module_update      512KB p61 */
    {PART_EXT_RVT,     (959 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p62 */
    {PART_RAMDISK,     (961 * 1024 + 512),     4 * 1024, UFS_PART_3}, /* ramdisk              4MB p63 */
    {PART_RESERVED7,    (965 * 1024 + 512),   1.5 * 1024, UFS_PART_3}, /* reserved7            1.5MB p64 */
    {PART_ENG_CHIPSET,         967 * 1024,    20 * 1024, UFS_PART_3}, /* eng_chipset          20MB p65 */
    {PART_FW_DTB,              987 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb               8MB p66 */
    {PART_DTBO,                995 * 1024,    14 * 1024, UFS_PART_3}, /* dtbo                14MB p67 */
    {PART_TRUSTFIRMWARE,      1009 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p68 */
    {PART_MODEM_FW,           1011 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p69 */
    {PART_MODEM_VENDOR,       1135 * 1024,    10 * 1024, UFS_PART_3}, /* modem_vendor        10MB p70 */
    {PART_MODEM_PATCH_NV,     1145 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p71 */
    {PART_MODEM_DRIVER,       1149 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p72 */
    {PART_MODEMNVM_UPDATE,    1169 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p73 */
    {PART_MODEMNVM_CUST,      1185 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust       16MB p74 */
    {PART_RESERVED8,          1201 * 1024,     3 * 1024, UFS_PART_3}, /* reserved8            3MB p75 */
    {PART_RVT_SYSTEM,         1204 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system        1024KB p76 */
    {PART_RVT_VENDOR,         1205 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor        1024KB p77 */
    {PART_RVT_CHIP_PROD,      1206 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod     1024KB p78 */
    {PART_RVT_CUST,           1207 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust          1024KB p79 */
    {PART_RVT_SYS_PROD,       1208 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod      1024KB p80 */
    {PART_UPDATER_RVT,        1209 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt          2MB p81 */
    {PART_UPDATER_BAK_RVT,    1211 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt      2MB p82 */
    {PART_RVT,                1213 * 1024,     4 * 1024, UFS_PART_3}, /* rvt                  4MB p83 */
    {PART_KPATCH,             1217 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p84 */
    {PART_PATCH,              1221 * 1024,    64 * 1024, UFS_PART_3}, /* patch               64MB p85 */
    {PART_CUST,               1285 * 1024,    56 * 1024, UFS_PART_3}, /* cust                56MB p86 */
    {PART_CHIP_PROD,          1341 * 1024,   942 * 1024, UFS_PART_3}, /* chip_prod          942MB p87 */
    {PART_VENDOR,             2283 * 1024,   920 * 1024, UFS_PART_3}, /* vendor             920MB p88 */
    {PART_SYS_PROD,           3203 * 1024,  1746 * 1024, UFS_PART_3}, /* sys_prod          1746MB p89 */
    {PART_SYSTEM,             4949 * 1024,  4948 * 1024, UFS_PART_3}, /* system            4948MB p90 */
    {PART_HYPERHOLD,          9897 * 1024,     4 * 1024, UFS_PART_3}, /* hyperhold            4MB p91 */
    {PART_RESERVED5,          9901 * 1024,     5 * 1024, UFS_PART_3}, /* reserved5            5MB p92 */
    {PART_VERSION,             9906 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p93 */
    {PART_PRELOAD,            10482 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p94 */
#if defined(CONFIG_FACTORY_MODE)
    {PART_HIBENCH_IMG,        11882 * 1024,   128 * 1024, UFS_PART_3}, /* hibench_img        128MB p95 */
    {PART_HIBENCH_LOG,        12010 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p96 */
    {PART_HIBENCH_DATA,       12042 * 1024,   512 * 1024, UFS_PART_3}, /* hibench_data       512MB p97 */
    {PART_FLASH_AGEING,       12554 * 1024,   512 * 1024, UFS_PART_3}, /* flash_ageing       512MB p98 */
    {PART_HIBENCH_LPM3,       13066 * 1024,     2 * 1024, UFS_PART_3}, /* hibench_lpm3         2MB p99 */
    {PART_RESERVED6,          13068 * 1024,  1706 * 1024, UFS_PART_3}, /* reserved6         1706MB p100 */
    {PART_USERDATA,           14774 * 1024,(16UL) * 1024 * 1024, UFS_PART_3}, /* userdata       6G p101 */
#else
    {PART_USERDATA,           11882 * 1024,(16UL) * 1024 * 1024, UFS_PART_3}, /* userdata       6G p95 */
#endif
#endif
    {"0", 0, 0, 0},
};

#endif