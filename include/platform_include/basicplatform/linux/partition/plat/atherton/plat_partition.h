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
    {PART_VRL,                        8704,          512, EMMC_USER_PART}, /* vrl                512KB p4 */
    {PART_VRL_BACKUP,             9 * 1024,          512, EMMC_USER_PART}, /* vrl_backup         512KB p5 */
    {PART_MODEM_SECURE,               9728,         8704, EMMC_USER_PART}, /* modem_secure      8704KB p6 */
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
    {PART_RESERVED2,    (238 * 1024 + 512), (20 * 1024 + 512), EMMC_USER_PART}, /* reserved2      21MB p20 */
    {PART_SPLASH2,              259 * 1024,    80 * 1024, EMMC_USER_PART}, /* splash2             80MB p21 */
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
    {PART_FW_CPU_LPCTRL,       (504 * 1024 + 512),   256, EMMC_USER_PART}, /* fw_cpu_lpctrl      256KB p32 */
    {PART_FW_GPU_LPCTRL,       (504 * 1024 + 768),   128, EMMC_USER_PART}, /* fw_gpu_lpctrl      128KB p33 */
    {PART_FW_DDR_LPCTRL,       (504 * 1024 + 896),   128, EMMC_USER_PART}, /* fw_ddr_lpctrl      128KB p34 */
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
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK,    584 * 1024,    32 * 1024, EMMC_USER_PART}, /* erecovery_ramdisk   32MB p47 */
    {PART_ERECOVERY_VENDOR,     616 * 1024,    24 * 1024, EMMC_USER_PART}, /* erecovery_vendor    24MB p48 */
    {PART_BOOT,                 640 * 1024,    48 * 1024, EMMC_USER_PART}, /* boot                48MB p49 */
    {PART_RECOVERY,             688 * 1024,    54 * 1024, EMMC_USER_PART}, /* recovery            54MB p50 */
    {PART_ERECOVERY,            742 * 1024,    54 * 1024, EMMC_USER_PART}, /* erecovery           54MB p51 */
    {PART_MODULE_UPDATE,        796 * 1024,          512, EMMC_USER_PART}, /* module_update      512KB p62 */
    {PART_EXT_RVT,      (796 * 1024 + 512),     2 * 1024, EMMC_USER_PART}, /* ext_rvt              2MB p63 */
    {PART_RESERVED,    (798 * 1024 + 512),    (50 * 1024+512), EMMC_USER_PART}, /* reserved3           53MB p52 */
#else
    {PART_ERECOVERY_RAMDISK,    584 * 1024,    32 * 1024, EMMC_USER_PART}, /* erecovery_ramdisk   32MB p47 */
    {PART_ERECOVERY_VENDOR,     616 * 1024,    24 * 1024, EMMC_USER_PART}, /* erecovery_vendor    24MB p48 */
    {PART_BOOT,                 640 * 1024,    46 * 1024, EMMC_USER_PART}, /* boot                46MB p49 */
    {PART_RECOVERY,             686 * 1024,    54 * 1024, EMMC_USER_PART}, /* recovery            54MB p50 */
    {PART_ERECOVERY,            740 * 1024,    54 * 1024, EMMC_USER_PART}, /* erecovery           54MB p51 */
    {PART_MODULE_UPDATE,        794 * 1024,          512, EMMC_USER_PART}, /* module_update      512KB p62 */
    {PART_EXT_RVT,      (794 * 1024 + 512),     2 * 1024, EMMC_USER_PART}, /* ext_rvt              2MB p63 */
    {PART_RESERVED,    (796 * 1024 + 512),    (52 * 1024+512), EMMC_USER_PART}, /* reserved3           53MB p52 */
#endif
    {PART_THEE,                 849 * 1024,     4 * 1024, EMMC_USER_PART}, /* thee                 4MB p53 */
    {PART_TZSP,                 853 * 1024,    12 * 1024, EMMC_USER_PART}, /* tzsp                12MB p54 */
    {PART_RECOVERY_RAMDISK,     865 * 1024,    32 * 1024, EMMC_USER_PART}, /* recovery_ramdisk    32MB p55 */
    {PART_RECOVERY_VENDOR,      897 * 1024,    24 * 1024, EMMC_USER_PART}, /* recovery_vendor     24MB p56 */
    {PART_ENG_SYSTEM,           921 * 1024,    12 * 1024, EMMC_USER_PART}, /* eng_system          12MB p57 */
    {PART_ENG_VENDOR,           933 * 1024,    20 * 1024, EMMC_USER_PART}, /* eng_vendor          20MB p58 */
    {PART_FW_DTB,               953 * 1024,     8 * 1024, EMMC_USER_PART}, /* fw_dtb               8MB p59 */
    {PART_DTBO,                 961 * 1024,    14 * 1024, EMMC_USER_PART}, /* dtbo                14MB p60 */
    {PART_TRUSTFIRMWARE,        975 * 1024,     2 * 1024, EMMC_USER_PART}, /* trustfirmware        2MB p61 */
    {PART_MODEM_FW,             977 * 1024,   124 * 1024, EMMC_USER_PART}, /* modem_fw           124MB p62 */
    {PART_MODEM_VENDOR,        1101 * 1024,    10 * 1024, EMMC_USER_PART}, /* modem_vendor        10MB p63 */
    {PART_MODEM_PATCH_NV,      1111 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_patch_nv       4MB p64 */
    {PART_MODEM_DRIVER,        1115 * 1024,    20 * 1024, EMMC_USER_PART}, /* modem_driver        20MB p65 */
    {PART_MODEMNVM_UPDATE,     1135 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_update     16MB p66 */
    {PART_MODEMNVM_CUST,       1151 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_cust       16MB p67 */
    {PART_RAMDISK,             1167 * 1024,     4 * 1024, EMMC_USER_PART}, /* ramdisk              4MB p68 */
    {PART_VBMETA_SYSTEM,       1171 * 1024,     1 * 1024, EMMC_USER_PART}, /* vbmeta_system     1024KB p69 */
    {PART_VBMETA_VENDOR,       1172 * 1024,     1 * 1024, EMMC_USER_PART}, /* vbmeta_vendor     1024KB p70 */
    {PART_VBMETA_ODM,          1173 * 1024,     1 * 1024, EMMC_USER_PART}, /* vbmeta_odm        1024KB p71 */
    {PART_VBMETA_CUST,         1174 * 1024,     1 * 1024, EMMC_USER_PART}, /* vbmeta_cust       1024KB p72 */
    {PART_VBMETA_HW_PRODUCT,   1175 * 1024,     1 * 1024, EMMC_USER_PART}, /* vbmeta_hw_product 1024KB p73 */
    {PART_RECOVERY_VBMETA,     1176 * 1024,     2 * 1024, EMMC_USER_PART}, /* recovery_vbmeta      2MB p74 */
    {PART_ERECOVERY_VBMETA,    1178 * 1024,     2 * 1024, EMMC_USER_PART}, /* erecovery_vbmeta     2MB p75 */
    {PART_VBMETA,              1180 * 1024,     4 * 1024, EMMC_USER_PART}, /* vbmeta               4MB p76 */
    {PART_KPATCH,              1184 * 1024,     4 * 1024, EMMC_USER_PART}, /* kpatch               4MB p77 */
    {PART_PATCH,               1188 * 1024,    32 * 1024, EMMC_USER_PART}, /* patch               32MB p78 */
    {PART_RESERVED5,           1220 * 1024,    30 * 1024, EMMC_USER_PART}, /* reserved5           30MB p79 */
    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, EMMC_USER_PART}, /* sensorhub          597MB p80 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, EMMC_USER_PART}, /* sensorhub_log_dic    3MB p80 */
#ifdef CONFIG_FACTORY_MODE
    {PART_PREAS,               1850 * 1024,    32 * 1024, EMMC_USER_PART}, /* preas               32MB p81 */
    {PART_PREAVS,              1882 * 1024,    32 * 1024, EMMC_USER_PART}, /* preavs              32MB p82 */
    {PART_SUPER,               1914 * 1024,  7656 * 1024, EMMC_USER_PART}, /* super             7656MB p83 */
    {PART_VERSION,             9570 * 1024,    32 * 1024, EMMC_USER_PART}, /* version             32MB p84 */
    {PART_PRELOAD,             9602 * 1024,    32 * 1024, EMMC_USER_PART}, /* preload             32MB p85 */
    {PART_HIBENCH_IMG,         9634 * 1024,    40 * 1024, EMMC_USER_PART}, /* hibench_img         40MB p86 */
    {PART_HIBENCH_DATA,        9674 * 1024,   600 * 1024, EMMC_USER_PART}, /* hibench_data       600MB p87 */
    {PART_FLASH_AGEING,       10274 * 1024,   512 * 1024, EMMC_USER_PART}, /* flash_ageing       512MB p88 */
    {PART_HIBENCH_LOG,        10786 * 1024,    32 * 1024, EMMC_USER_PART}, /* hibench_log         32MB p89 */
    {PART_SENSORHUB_SYSTEM,   10818 * 1024,  1536 * 1024, EMMC_USER_PART}, /* sensorhub_system  1536MB p90 */
    {PART_SENSORHUB_DATA,     12354 * 1024,  6656 * 1024, EMMC_USER_PART}, /* sensorhub_data  6656MB p90-1 */
    {PART_USERDATA,           19010 * 1024, (4UL) * 1024 * 1024, EMMC_USER_PART}, /* userdata       4G p91 */
#else
    {PART_PREAS,               1850 * 1024,    32 * 1024, EMMC_USER_PART}, /* preas               32MB p81 */
    {PART_PREAVS,              1882 * 1024,    32 * 1024, EMMC_USER_PART}, /* preavs              32MB p82 */
    {PART_SUPER,               1914 * 1024,  7656 * 1024, EMMC_USER_PART}, /* super             7656MB p83 */
    {PART_VERSION,             9570 * 1024,    32 * 1024, EMMC_USER_PART}, /* version             32MB p84 */
    {PART_PRELOAD,             9602 * 1024,    32 * 1024, EMMC_USER_PART}, /* preload             32MB p85 */
    {PART_SENSORHUB_SYSTEM,    9634 * 1024,  1536 * 1024, EMMC_USER_PART}, /* sensorhub_system   1536MB 86 */
    {PART_SENSORHUB_DATA,     11170 * 1024,  6656 * 1024, EMMC_USER_PART}, /* sensorhub_data  6656MB p86-1 */
#ifdef CONFIG_PARTITION_ENG
    {PART_FTTEST,             17826 * 1024,   192 * 1024, EMMC_USER_PART}, /* fttest             192MB p87 */
    {PART_DDRTEST,            18018 * 1024,    48 * 1024, EMMC_USER_PART}, /* ddrtest             48MB p88 */
    {PART_HIBENCH_LPM3,       18066 * 1024,     2 * 1024, EMMC_USER_PART}, /* hibench_lpm3         2MB p89 */
    {PART_HITEST_ASP_DHRYSTONE, 18068 * 1024,     2 * 1024, EMMC_USER_PART}, /* hitest_asp_dhrystone   2MB p90 */
    {PART_HITEST_ASP_TEST,    18070 * 1024,    30 * 1024, EMMC_USER_PART}, /* hitest_asp_test     30MB p91 */
    {PART_HITEST_GPU,         18100 * 1024,   100 * 1024, EMMC_USER_PART}, /* hitest_gpu         100MB p92 */
    {PART_HITEST_GPU_1,       18200 * 1024,   256 * 1024, EMMC_USER_PART}, /* hitest_gpu_1       256MB p93 */
    {PART_HITEST_NPU,         18456 * 1024,    64 * 1024, EMMC_USER_PART}, /* hitest_npu          64MB p94 */
    {PART_HITEST_JPEGENC,     18520 * 1024,   200 * 1024, EMMC_USER_PART}, /* hitest_jpegenc     200MB p95 */
    {PART_HITEST_SENSORHUB,   18720 * 1024,     6 * 1024, EMMC_USER_PART}, /* hitest_sensorhub     6MB p96 */
    {PART_VCODE_DATA,         18726 * 1024,   140 * 1024, EMMC_USER_PART}, /* vcode_data         140MB p97 */
    {PART_VCODE_MAX_DATA,     18866 * 1024,   140 * 1024, EMMC_USER_PART}, /* vcode_max_data     140MB p98 */
    {PART_DSS_DISP_BUF,       19006 * 1024,    64 * 1024, EMMC_USER_PART}, /* dss_disp_buf        64MB p99 */
    {PART_MODEM_TSP_TEST,     19070 * 1024,    10 * 1024, EMMC_USER_PART}, /* modem_tsp_test      10MB p100 */
    {PART_MODEM_TSP_DT,       19080 * 1024,     2 * 1024, EMMC_USER_PART}, /* modem_tsp_dt         2MB p101 */
    {PART_MODEM_TSP_AVS,      19082 * 1024,    80 * 1024, EMMC_USER_PART}, /* modem_tsp_avs       80MB p102 */
    {PART_MODEM_PDE_TEST,     19162 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_pde_test       4MB p103 */
    {PART_MODEM_L2DLE,        19166 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_l2dle          4MB p104 */
    {PART_MODEM_VECTOR_CONFIG, 19170 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_vector_config   4MB p105 */
    {PART_USERDATA,           19174 * 1024, (4UL) * 1024 * 1024, EMMC_USER_PART}, /* userdata       4G p106 */
#else
    {PART_USERDATA,           17826 * 1024, (4UL) * 1024 * 1024, EMMC_USER_PART}, /* userdata       4G p87 */
#endif
#endif
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                0,             2 * 1024,    UFS_PART_0},
    {PART_RESERVED0,              0,             2 * 1024,    UFS_PART_1},
    {PART_PTABLE,                 0,                  512,    UFS_PART_2}, /* ptable           512K    p0 */
    {PART_PTABLE,                 0,                  512,    UFS_PART_3}, /* ptable           512K    p0 */
    {PART_FRP,                                512,   512, UFS_PART_3}, /* frp                512KB p1 */
    {PART_PERSIST,                    1024,     6 * 1024, UFS_PART_3}, /* persist              6MB p2 */
    {PART_RESERVED1,              7 * 1024,         1536, UFS_PART_3}, /* reserved1         1536KB p3 */
    {PART_VRL,                        8704,          512, UFS_PART_3}, /* vrl                512KB p4 */
    {PART_VRL_BACKUP,             9 * 1024,          512, UFS_PART_3}, /* vrl_backup         512KB p5 */
    {PART_MODEM_SECURE,               9728,         8704, UFS_PART_3}, /* modem_secure      8704KB p6 */
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
    {PART_RESERVED2,    (238 * 1024 + 512), (20 * 1024 + 512), UFS_PART_3}, /* reserved2      21MB p20 */
    {PART_SPLASH2,              259 * 1024,    80 * 1024, UFS_PART_3}, /* splash2             80MB p21 */
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
    {PART_FW_CPU_LPCTRL,       (504 * 1024 + 512),   256, UFS_PART_3}, /* fw_cpu_lpctrl      256KB p32 */
    {PART_FW_GPU_LPCTRL,       (504 * 1024 + 768),   128, UFS_PART_3}, /* fw_gpu_lpctrl      128KB p33 */
    {PART_FW_DDR_LPCTRL,       (504 * 1024 + 896),   128, UFS_PART_3}, /* fw_ddr_lpctrl      128KB p34 */
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
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK,    584 * 1024,    32 * 1024, UFS_PART_3}, /* erecovery_ramdisk   32MB p47 */
    {PART_ERECOVERY_VENDOR,     616 * 1024,    24 * 1024, UFS_PART_3}, /* erecovery_vendor    24MB p48 */
    {PART_BOOT,                 640 * 1024,    48 * 1024, UFS_PART_3}, /* boot                48MB p49 */
    {PART_RECOVERY,             688 * 1024,    54 * 1024, UFS_PART_3}, /* recovery            54MB p50 */
    {PART_ERECOVERY,            742 * 1024,    54 * 1024, UFS_PART_3}, /* erecovery           54MB p51 */
    {PART_MODULE_UPDATE,        796 * 1024,          512, UFS_PART_3}, /* module_update      512KB p62 */
    {PART_EXT_RVT,      (796 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p63 */
    {PART_RESERVED,    (798 * 1024 + 512),    (50 * 1024+512), UFS_PART_3}, /* reserved3           53MB p52 */
#else
    {PART_ERECOVERY_RAMDISK,    584 * 1024,    32 * 1024, UFS_PART_3}, /* erecovery_ramdisk   32MB p47 */
    {PART_ERECOVERY_VENDOR,     616 * 1024,    24 * 1024, UFS_PART_3}, /* erecovery_vendor    24MB p48 */
    {PART_BOOT,                 640 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p49 */
    {PART_RECOVERY,             686 * 1024,    54 * 1024, UFS_PART_3}, /* recovery            54MB p50 */
    {PART_ERECOVERY,            740 * 1024,    54 * 1024, UFS_PART_3}, /* erecovery           54MB p51 */
    {PART_MODULE_UPDATE,        794 * 1024,          512, UFS_PART_3}, /* module_update      512KB p62 */
    {PART_EXT_RVT,      (794 * 1024 + 512),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p63 */
    {PART_RESERVED,    (796 * 1024 + 512),    (52 * 1024+512), UFS_PART_3}, /* reserved3           53MB p52 */
#endif
    {PART_THEE,                 849 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p53 */
    {PART_TZSP,                 853 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p54 */
    {PART_RECOVERY_RAMDISK,     865 * 1024,    32 * 1024, UFS_PART_3}, /* recovery_ramdisk    32MB p55 */
    {PART_RECOVERY_VENDOR,      897 * 1024,    24 * 1024, UFS_PART_3}, /* recovery_vendor     24MB p56 */
    {PART_ENG_SYSTEM,           921 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p57 */
    {PART_ENG_VENDOR,           933 * 1024,    20 * 1024, UFS_PART_3}, /* eng_vendor          20MB p58 */
    {PART_FW_DTB,               953 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb               8MB p59 */
    {PART_DTBO,                 961 * 1024,    14 * 1024, UFS_PART_3}, /* dtbo                14MB p60 */
    {PART_TRUSTFIRMWARE,        975 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p61 */
    {PART_MODEM_FW,             977 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p62 */
    {PART_MODEM_VENDOR,        1101 * 1024,    10 * 1024, UFS_PART_3}, /* modem_vendor        10MB p63 */
    {PART_MODEM_PATCH_NV,      1111 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p64 */
    {PART_MODEM_DRIVER,        1115 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p65 */
    {PART_MODEMNVM_UPDATE,     1135 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p66 */
    {PART_MODEMNVM_CUST,       1151 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust       16MB p67 */
    {PART_RAMDISK,             1167 * 1024,     4 * 1024, UFS_PART_3}, /* ramdisk              4MB p68 */
    {PART_VBMETA_SYSTEM,       1171 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_system     1024KB p69 */
    {PART_VBMETA_VENDOR,       1172 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_vendor     1024KB p70 */
    {PART_VBMETA_ODM,          1173 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_odm        1024KB p71 */
    {PART_VBMETA_CUST,         1174 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_cust       1024KB p72 */
    {PART_VBMETA_HW_PRODUCT,   1175 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_hw_product 1024KB p73 */
    {PART_RECOVERY_VBMETA,     1176 * 1024,     2 * 1024, UFS_PART_3}, /* recovery_vbmeta      2MB p74 */
    {PART_ERECOVERY_VBMETA,    1178 * 1024,     2 * 1024, UFS_PART_3}, /* erecovery_vbmeta     2MB p75 */
    {PART_VBMETA,              1180 * 1024,     4 * 1024, UFS_PART_3}, /* vbmeta               4MB p76 */
    {PART_KPATCH,              1184 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p77 */
    {PART_PATCH,               1188 * 1024,    32 * 1024, UFS_PART_3}, /* patch               32MB p78 */
    {PART_RESERVED5,           1220 * 1024,    30 * 1024, UFS_PART_3}, /* reserved5           30MB p79 */
    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, UFS_PART_3}, /* sensorhub          597MB p80 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p80 */
#ifdef CONFIG_FACTORY_MODE
    {PART_PREAS,               1850 * 1024,    32 * 1024, UFS_PART_3}, /* preas               32MB p81 */
    {PART_PREAVS,              1882 * 1024,    32 * 1024, UFS_PART_3}, /* preavs              32MB p82 */
    {PART_SUPER,               1914 * 1024,  7656 * 1024, UFS_PART_3}, /* super             7656MB p83 */
    {PART_VERSION,             9570 * 1024,    32 * 1024, UFS_PART_3}, /* version             32MB p84 */
    {PART_PRELOAD,             9602 * 1024,    32 * 1024, UFS_PART_3}, /* preload             32MB p85 */
    {PART_HIBENCH_IMG,         9634 * 1024,    40 * 1024, UFS_PART_3}, /* hibench_img         40MB p86 */
    {PART_HIBENCH_DATA,        9674 * 1024,   600 * 1024, UFS_PART_3}, /* hibench_data       600MB p87 */
    {PART_FLASH_AGEING,       10274 * 1024,   512 * 1024, UFS_PART_3}, /* flash_ageing       512MB p88 */
    {PART_HIBENCH_LOG,        10786 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p89 */
    {PART_SENSORHUB_SYSTEM,   10818 * 1024,  1536 * 1024, UFS_PART_3}, /* sensorhub_system  1536MB p90 */
    {PART_SENSORHUB_DATA,     12354 * 1024,  6656 * 1024, UFS_PART_3}, /* sensorhub_data  6656MB p90-1 */
    {PART_USERDATA,           19010 * 1024, (4UL) * 1024 * 1024, UFS_PART_3}, /* userdata       4G p91 */
#else
    {PART_PREAS,               1850 * 1024,    32 * 1024, UFS_PART_3}, /* preas               32MB p81 */
    {PART_PREAVS,              1882 * 1024,    32 * 1024, UFS_PART_3}, /* preavs              32MB p82 */
    {PART_SUPER,               1914 * 1024,  7656 * 1024, UFS_PART_3}, /* super             7656MB p83 */
    {PART_VERSION,             9570 * 1024,    32 * 1024, UFS_PART_3}, /* version             32MB p84 */
    {PART_PRELOAD,             9602 * 1024,    32 * 1024, UFS_PART_3}, /* preload             32MB p85 */
    {PART_SENSORHUB_SYSTEM,    9634 * 1024,  1536 * 1024, UFS_PART_3}, /* sensorhub_system   1536MB 86 */
    {PART_SENSORHUB_DATA,     11170 * 1024,  6656 * 1024, UFS_PART_3}, /* sensorhub_data  6656MB p86-1 */
#ifdef CONFIG_PARTITION_ENG
    {PART_FTTEST,             17826 * 1024,   192 * 1024, UFS_PART_3}, /* fttest             192MB p87 */
    {PART_DDRTEST,            18018 * 1024,    48 * 1024, UFS_PART_3}, /* ddrtest             48MB p88 */
    {PART_HIBENCH_LPM3,       18066 * 1024,     2 * 1024, UFS_PART_3}, /* hibench_lpm3         2MB p89 */
    {PART_HITEST_ASP_DHRYSTONE, 18068 * 1024,     2 * 1024, UFS_PART_3}, /* hitest_asp_dhrystone   2MB p90 */
    {PART_HITEST_ASP_TEST,    18070 * 1024,    30 * 1024, UFS_PART_3}, /* hitest_asp_test     30MB p91 */
    {PART_HITEST_GPU,         18100 * 1024,   100 * 1024, UFS_PART_3}, /* hitest_gpu         100MB p92 */
    {PART_HITEST_GPU_1,       18200 * 1024,   256 * 1024, UFS_PART_3}, /* hitest_gpu_1       256MB p93 */
    {PART_HITEST_NPU,         18456 * 1024,    64 * 1024, UFS_PART_3}, /* hitest_npu          64MB p94 */
    {PART_HITEST_JPEGENC,     18520 * 1024,   200 * 1024, UFS_PART_3}, /* hitest_jpegenc     200MB p95 */
    {PART_HITEST_SENSORHUB,   18720 * 1024,     6 * 1024, UFS_PART_3}, /* hitest_sensorhub     6MB p96 */
    {PART_VCODE_DATA,         18726 * 1024,   140 * 1024, UFS_PART_3}, /* vcode_data         140MB p97 */
    {PART_VCODE_MAX_DATA,     18866 * 1024,   140 * 1024, UFS_PART_3}, /* vcode_max_data     140MB p98 */
    {PART_DSS_DISP_BUF,       19006 * 1024,    64 * 1024, UFS_PART_3}, /* dss_disp_buf        64MB p99 */
    {PART_MODEM_TSP_TEST,     19070 * 1024,    10 * 1024, UFS_PART_3}, /* modem_tsp_test      10MB p100 */
    {PART_MODEM_TSP_DT,       19080 * 1024,     2 * 1024, UFS_PART_3}, /* modem_tsp_dt         2MB p101 */
    {PART_MODEM_TSP_AVS,      19082 * 1024,    80 * 1024, UFS_PART_3}, /* modem_tsp_avs       80MB p102 */
    {PART_MODEM_PDE_TEST,     19162 * 1024,     4 * 1024, UFS_PART_3}, /* modem_pde_test       4MB p103 */
    {PART_MODEM_L2DLE,        19166 * 1024,     4 * 1024, UFS_PART_3}, /* modem_l2dle          4MB p104 */
    {PART_MODEM_VECTOR_CONFIG, 19170 * 1024,     4 * 1024, UFS_PART_3}, /* modem_vector_config   4MB p105 */
    {PART_USERDATA,           19174 * 1024, (4UL) * 1024 * 1024, UFS_PART_3}, /* userdata       4G p106 */
#else
    {PART_USERDATA,           17826 * 1024, (4UL) * 1024 * 1024, UFS_PART_3}, /* userdata       4G p87 */
#endif
#endif
    {"0", 0, 0, 0},
};
#endif
