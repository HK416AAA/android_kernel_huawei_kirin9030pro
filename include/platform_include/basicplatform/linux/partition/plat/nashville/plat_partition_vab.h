#ifndef _PISCES_PLAT_PARTITION_H_
#define _PISCES_PLAT_PARTITION_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                0,              4 * 1024,    UFS_PART_0},
    {PART_RESERVED0,              0,              4 * 1024,    UFS_PART_1},
    {PART_PTABLE,                 0,                   512,    UFS_PART_2}, /* ptable           512K    p0 */
    {PART_FRP,                         512,          512, UFS_PART_2}, /* frp                512KB p1 */
    {PART_PERSIST,                    1024,     6 * 1024, UFS_PART_2}, /* persist              6MB p2 */
    {PART_RESERVED1,              7 * 1024,         1024, UFS_PART_2}, /* reserved1         1024KB p3 */
    {PART_PTABLE_LU3,             0,       512,           UFS_PART_3}, /* ptable_lu3       512K    p0 */    
    {PART_LOWPOWER_PARA,               512,     1 * 1024, UFS_PART_3}, /* lowpower_para     1024KB p1 */
    {PART_BL2,               (1 * 1024 + 512),     4 * 1024, UFS_PART_3}, /* bl2                  4MB p2 */
    {PART_FW_LPM3,           (5 * 1024 + 512),          512, UFS_PART_3}, /* fw_lpm3            512KB p3 */
    {PART_SEPLAT,                 6 * 1024,     4 * 1024, UFS_PART_3}, /* seplat               4MB p4 */
    {PART_FW_CPU_LPCTRL,         10 * 1024,          256, UFS_PART_3}, /* fw_cpu_lpctrl      256KB p5 */
    {PART_FW_GPU_LPCTRL,     (10 * 1024 + 256),          128, UFS_PART_3}, /* fw_gpu_lpctrl      128KB p6 */
    {PART_FW_DDR_LPCTRL,     (10 * 1024 + 384),          256, UFS_PART_3}, /* fw_ddr_lpctrl      256KB p7 */
    {PART_DDR_XPU_BOOT0,     (10 * 1024 + 640),          256, UFS_PART_3}, /* ddr_xpu_boot0      256KB p8 */
    {PART_DDR_XPU_BOOT1,     (10 * 1024 + 896),          256, UFS_PART_3}, /* ddr_xpu_boot1      256KB p9 */
    {PART_DDR_XPU_BOOT2,     (11 * 1024 + 128),          256, UFS_PART_3}, /* ddr_xpu_boot2      256KB p10 */
    {PART_UCE,               (11 * 1024 + 384),          160, UFS_PART_3}, /* uce                160KB p11 */
    {PART_RESERVED4,         (11 * 1024 + 544), 5 * 1024+480, UFS_PART_3}, /* reserved4         5600KB p12 */
	{PART_NPU,                   17 * 1024,     8 * 1024, UFS_PART_3}, /* npu                  8MB p13 */
    {PART_IVP,                   25 * 1024,     2 * 1024, UFS_PART_3}, /* ivp                  2MB p14 */
    {PART_DACC,                  27 * 1024,          512, UFS_PART_3}, /* dacc               512KB p15 */
    {PART_VENC,              (27 * 1024 + 512),          512, UFS_PART_3}, /* venc               512KB p16 */
    {PART_HISEE_IMG,             28 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p17 */
    {PART_HHEE,                  32 * 1024,     4 * 1024, UFS_PART_3}, /* hhee                 4MB p18 */
    {PART_FASTBOOT,              36 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p19 */
    {PART_VECTOR,                48 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p20 */
    {PART_ISP_BOOT,              52 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot             2MB p21 */
    {PART_ISP_FIRMWARE,          54 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware        14MB p22 */
    {PART_FW_HIFI,               68 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi             12MB p23 */
    {PART_TEEOS,                 80 * 1024,     8 * 1024, UFS_PART_3}, /* teeos                8MB p24 */
    {PART_SENSORHUB,             88 * 1024,    13 * 1024, UFS_PART_3}, /* sensorhub           13MB p25 */
    {PART_SENSORHUB_LOG_DIC,    101 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p26 */
    {PART_HKRR,                 104 * 1024,    16 * 1024, UFS_PART_3}, /* hkrr                16MB p27 */
    {PART_FW_UFSDEV,            120 * 1024,     4 * 1024, UFS_PART_3}, /* fw_ufsdev            4MB p28 */
    {PART_FW_DFA,               124 * 1024,     1 * 1024, UFS_PART_3}, /* fw_dfa            1024KB p29 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK,    125 * 1024,    12 * 1024, UFS_PART_3}, /* erecovery_ramdisk   12MB p30 */
    {PART_ERECOVERY_VENDOR,     137 * 1024,    12 * 1024, UFS_PART_3}, /* erecovery_vendor    12MB p31 */
    {PART_BOOT,                 149 * 1024,    81 * 1024, UFS_PART_3}, /* boot                81MB p32 */
    {PART_RECOVERY,             230 * 1024,    94 * 1024, UFS_PART_3}, /* recovery            94MB p33 */
    {PART_ERECOVERY,            324 * 1024,    21 * 1024, UFS_PART_3}, /* erecovery           21MB p34 */
    {PART_RESERVED,             345 * 1024,    49 * 1024, UFS_PART_3}, /* reserved            49MB p35 */
    {PART_THEE,                 394 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p36 */
    {PART_TZSP,                 398 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p37 */
    {PART_RECOVERY_RAMDISK,     410 * 1024,    32 * 1024, UFS_PART_3}, /* recovery_ramdisk    32MB p38 */
    {PART_RECOVERY_VENDOR,      442 * 1024,    28 * 1024, UFS_PART_3}, /* recovery_vendor     28MB p39 */
#elif defined CONFIG_HWSANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK,    125 * 1024,    40 * 1024, UFS_PART_3}, /* erecovery_ramdisk   40MB p30 */
    {PART_ERECOVERY_VENDOR,     165 * 1024,    28 * 1024, UFS_PART_3}, /* erecovery_vendor    28MB p31 */
    {PART_BOOT,                 193 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p32 */
    {PART_RECOVERY,             239 * 1024,    54 * 1024, UFS_PART_3}, /* recovery            54MB p33 */
    {PART_ERECOVERY,            293 * 1024,    54 * 1024, UFS_PART_3}, /* erecovery           54MB p34 */
    {PART_RESERVED,             347 * 1024,    39 * 1024, UFS_PART_3}, /* reserved            39MB p35 */
    {PART_THEE,                 386 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p36 */
    {PART_TZSP,                 390 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p37 */
    {PART_RECOVERY_RAMDISK,     402 * 1024,    40 * 1024, UFS_PART_3}, /* recovery_ramdisk    40MB p38 */
    {PART_RECOVERY_VENDOR,      442 * 1024,    28 * 1024, UFS_PART_3}, /* recovery_vendor     28MB p39 */
#else
    {PART_ERECOVERY_RAMDISK,    125 * 1024,    32 * 1024, UFS_PART_3}, /* erecovery_ramdisk   32MB p30 */
    {PART_ERECOVERY_VENDOR,     157 * 1024,    28 * 1024, UFS_PART_3}, /* erecovery_vendor    28MB p31 */
    {PART_BOOT,                 185 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p32 */
    {PART_RECOVERY,             231 * 1024,    54 * 1024, UFS_PART_3}, /* recovery            54MB p33 */
    {PART_ERECOVERY,            285 * 1024,    54 * 1024, UFS_PART_3}, /* erecovery           54MB p34 */
    {PART_RESERVED,             339 * 1024,    55 * 1024, UFS_PART_3}, /* reserved            55MB p35 */
    {PART_THEE,                 394 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p36 */
    {PART_TZSP,                 398 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p37 */
    {PART_RECOVERY_RAMDISK,     410 * 1024,    32 * 1024, UFS_PART_3}, /* recovery_ramdisk    32MB p38 */
    {PART_RECOVERY_VENDOR,      442 * 1024,    28 * 1024, UFS_PART_3}, /* recovery_vendor     28MB p39 */
#endif
    {PART_ENG_SYSTEM,           470 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p40 */
    {PART_ENG_VENDOR,           482 * 1024,    20 * 1024, UFS_PART_3}, /* eng_vendor          20MB p41 */
    {PART_FW_DTB,               502 * 1024,    20 * 1024, UFS_PART_3}, /* fw_dtb              20MB p42 */
    {PART_DTBO,                 522 * 1024,    20 * 1024, UFS_PART_3}, /* dtbo                20MB p43 */
    {PART_TRUSTFIRMWARE,        542 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p44 */
    {PART_MODEM_FW,             544 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p45 */
    {PART_MODEM_VENDOR,         668 * 1024,    10 * 1024, UFS_PART_3}, /* modem_vendor        10MB p46 */
    {PART_MODEM_PATCH_NV,       678 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p47 */
    {PART_MODEM_DRIVER,         682 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p48 */
    {PART_MODEMNVM_UPDATE,      702 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p49 */
    {PART_MODEMNVM_CUST,        718 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust       16MB p50 */
    {PART_RAMDISK,              734 * 1024,     2 * 1024, UFS_PART_3}, /* ramdisk              2MB p51 */
    {PART_VBMETA_SYSTEM,        736 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_system     1024KB p52 */
    {PART_VBMETA_VENDOR,        737 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_vendor     1024KB p53 */
    {PART_VBMETA_ODM,           738 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_odm        1024KB p54 */
    {PART_VBMETA_CUST,          739 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_cust       1024KB p55 */
    {PART_VBMETA_HW_PRODUCT,    740 * 1024,     1 * 1024, UFS_PART_3}, /* vbmeta_hw_product 1024KB p56 */
    {PART_RECOVERY_VBMETA,      741 * 1024,     2 * 1024, UFS_PART_3}, /* recovery_vbmeta      2MB p57 */
    {PART_ERECOVERY_VBMETA,     743 * 1024,     2 * 1024, UFS_PART_3}, /* erecovery_vbmeta     2MB p58 */
    {PART_VBMETA,               745 * 1024,     4 * 1024, UFS_PART_3}, /* vbmeta               4MB p59 */
    {PART_KPATCH,               749 * 1024,     4 * 1024, UFS_PART_3}, /* kpatch               4MB p60 */
    {PART_PATCH,                753 * 1024,    32 * 1024, UFS_PART_3}, /* patch               32MB p61 */
    {PART_RESERVED1_lu3,        785 * 1024,    78 * 1024, UFS_PART_3}, /* reserved1_lu3       78MB p62 */
	{PART_PTABLE_LU4,             0,              512,    UFS_PART_4}, /* ptable_lu4       512K    p0 */
	{PART_RESERVED4_lu4,               512,885 * 1024+928, UFS_PART_4}, /* reserved4_lu4     907168KB p1 */
    {PART_PTABLE_LU5,             0,              512,    UFS_PART_5}, /* ptable_lu3       512K    p0 */
	{PART_RESERVED1_lu5,               512,     1 * 1024, UFS_PART_5}, /* reserved1_lu5     1024KB p1 */
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
    {PART_SPLASH2,              351 * 1024,    80 * 1024, UFS_PART_5}, /* splash2             80MB p19 */
    {PART_BOOTFAIL_INFO,        431 * 1024,     2 * 1024, UFS_PART_5}, /* bootfail_info        2MB p20 */
    {PART_MISC,                 433 * 1024,     2 * 1024, UFS_PART_5}, /* misc                 2MB p21 */
    {PART_DFX,                  435 * 1024,    16 * 1024, UFS_PART_5}, /* dfx                 16MB p22 */
    {PART_RRECORD,              451 * 1024,    16 * 1024, UFS_PART_5}, /* rrecord             16MB p23 */
    {PART_CACHE,                467 * 1024,   104 * 1024, UFS_PART_5}, /* cache              104MB p24 */
    {PART_METADATA,             571 * 1024,    16 * 1024, UFS_PART_5}, /* metadata            16MB p25 */
    {PART_TOC,                  587 * 1024,     1 * 1024, UFS_PART_5}, /* toc               1024KB p26 */
    {PART_HISEE_FS,             588 * 1024,     8 * 1024, UFS_PART_5}, /* hisee_fs             8MB p27 */
    {PART_RESERVED3,            596 * 1024,   (4 * 1024), UFS_PART_5}, /* reserved3            4MB p28 */
#ifdef CONFIG_FACTORY_MODE
    {PART_PREAS,                600 * 1024,    12 * 1024, UFS_PART_5}, /* preas               12MB p29 */
    {PART_PREAVS,               612 * 1024,    12 * 1024, UFS_PART_5}, /* preavs              12MB p30 */
    {PART_SUPER,                624 * 1024, 10728 * 1024, UFS_PART_5}, /* super             10728MB p31 */
    {PART_VERSION,            11352 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p32 */
    {PART_PRELOAD,            11928 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p33 */
    {PART_HIBENCH_IMG,        13328 * 1024,   128 * 1024, UFS_PART_5}, /* hibench_img        128MB p34 */
    {PART_HIBENCH_DATA,       13456 * 1024,  1000 * 1024, UFS_PART_5}, /* hibench_data      1000MB p35 */
    {PART_FLASH_AGEING,       14456 * 1024,   512 * 1024, UFS_PART_5}, /* flash_ageing       512MB p36 */
    {PART_HIBENCH_LOG,        14968 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p37 */
    {PART_XLOADER_HITEST,     15000 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p38 */
    {PART_RESERVED,           15002 * 1024, 35048 * 1024, UFS_PART_5}, /* reserved          35048MB p39 */
    {PART_USERDATA,           50050 * 1024, (8UL) * 1024 * 1024, UFS_PART_5}, /* userdata      (8G p40 */
#elif defined CONFIG_MARKET_INTERNAL
#ifdef CONFIG_USE_EROFS
    {PART_PREAS,                600 * 1024,    12 * 1024, UFS_PART_5}, /* preas               12MB p29 */
    {PART_PREAVS,               612 * 1024,    12 * 1024, UFS_PART_5}, /* preavs              12MB p30 */
    {PART_SUPER,                624 * 1024, 19550 * 1024, UFS_PART_5}, /* super             19550MB p31 */
    {PART_VERSION,            20174 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p32 */
    {PART_PRELOAD,            20750 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p33 */
    {PART_RESERVED,           22150 * 1024,   602 * 1024, UFS_PART_5}, /* reserved           602MB p34 */   
    {PART_USERDATA,           22752 * 1024, (8UL) * 1024 * 1024, UFS_PART_5}, /* userdata      (8G p35 */
#else
    {PART_PREAS,                600 * 1024,    12 * 1024, UFS_PART_5}, /* preas               12MB p29 */
    {PART_PREAVS,               612 * 1024,    12 * 1024, UFS_PART_5}, /* preavs              12MB p30 */
    {PART_SUPER,                624 * 1024, 20408 * 1024, UFS_PART_5}, /* super             20408MB p31 */
    {PART_VERSION,            21032 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p32 */
    {PART_PRELOAD,            21608 * 1024,  1144 * 1024, UFS_PART_5}, /* preload           1144MB p33 */
    {PART_USERDATA,           22752 * 1024, (8UL) * 1024 * 1024, UFS_PART_5}, /* userdata      (8G p34 */
#endif
#elif defined CONFIG_MARKET_OVERSEA
#ifdef CONFIG_USE_EROFS
    {PART_PREAS,                600 * 1024,    12 * 1024, UFS_PART_5}, /* preas               12MB p29 */
    {PART_PREAVS,               612 * 1024,    12 * 1024, UFS_PART_5}, /* preavs              12MB p30 */
    {PART_SUPER,                624 * 1024, 19834 * 1024, UFS_PART_5}, /* super             19834MB p31 */
    {PART_VERSION,            20458 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p32 */
    {PART_PRELOAD,            21034 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p33 */
    {PART_USERDATA,           22434 * 1024, (8UL) * 1024 * 1024, UFS_PART_5}, /* userdata      (8G p34 */
#else /* end erofs */
    {PART_PREAS,                600 * 1024,    12 * 1024, UFS_PART_5}, /* preas               12MB p29 */
    {PART_PREAVS,               612 * 1024,    12 * 1024, UFS_PART_5}, /* preavs              12MB p30 */
    {PART_SUPER,                624 * 1024, 22112 * 1024, UFS_PART_5}, /* super             22112MB p31 */
    {PART_VERSION,            22736 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p32 */
    {PART_PRELOAD,            23312 * 1024,  1144 * 1024, UFS_PART_5}, /* preload           1144MB p33 */
    {PART_USERDATA,           24456 * 1024, (8UL) * 1024 * 1024, UFS_PART_5}, /* userdata      (8G p34 */
#endif
#elif defined CONFIG_GCOV_PARTITION_SUPPORT_ENABLE
    {PART_PREAS,                600 * 1024,    12 * 1024, UFS_PART_5}, /* preas               12MB p29 */
    {PART_PREAVS,               612 * 1024,    12 * 1024, UFS_PART_5}, /* preavs              12MB p30 */
    {PART_SUPER,                624 * 1024, 22412 * 1024, UFS_PART_5}, /* super             22412MB p31 */
    {PART_VERSION,            23036 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p32 */
    {PART_PRELOAD,            23612 * 1024,  1144 * 1024, UFS_PART_5}, /* preload           1144MB p33 */
    {PART_USERDATA,           24756 * 1024, (8UL) * 1024 * 1024, UFS_PART_5}, /* userdata      (8G p34 */
#else
    {PART_PREAS,                600 * 1024,    12 * 1024, UFS_PART_5}, /* preas               12MB p29 */
    {PART_PREAVS,               612 * 1024,    12 * 1024, UFS_PART_5}, /* preavs              12MB p30 */
    {PART_SUPER,                624 * 1024, 20408 * 1024, UFS_PART_5}, /* super             20408MB p31 */
    {PART_VERSION,            21032 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p32 */
    {PART_PRELOAD,            21608 * 1024,  1144 * 1024, UFS_PART_5}, /* preload           1144MB p33 */
#if defined(CONFIG_PARTITION_ENG)
    {PART_FTTEST,             22752 * 1024,   192 * 1024, UFS_PART_5}, /* fttest             192MB p34 */
    {PART_DDRTEST,            22944 * 1024,    48 * 1024, UFS_PART_5}, /* ddrtest             48MB p35 */
    {PART_HITEST_GPU,         22992 * 1024,   512 * 1024, UFS_PART_5}, /* hitest_gpu         512MB p36 */
    {PART_HITEST_ASP_DHRYSTONE, 23504 * 1024,    20 * 1024, UFS_PART_5}, /* hitest_asp_dhrystone  20MB p37 */
    {PART_HITEST_ASP_TEST,    23524 * 1024,   300 * 1024, UFS_PART_5}, /* hitest_asp_test    300MB p38 */
    {PART_HITEST_SENSORHUB,   23824 * 1024,     6 * 1024, UFS_PART_5}, /* hitest_sensorhub     6MB p39 */
    {PART_HITEST_ISP,         23830 * 1024,    25 * 1024, UFS_PART_5}, /* hitest_isp          25MB p40 */
    {PART_HITEST_ISP_AVS,     23855 * 1024,    65 * 1024, UFS_PART_5}, /* hitest_isp_avs      65MB p41 */
    {PART_HITEST_NPU,         23920 * 1024,    80 * 1024, UFS_PART_5}, /* hitest_npu          80MB p42 */
    {PART_HITEST_DSS,         24000 * 1024,    18 * 1024, UFS_PART_5}, /* hitest_dss          18MB p43 */
    {PART_DSS_DISP_BUF,       24018 * 1024,   128 * 1024, UFS_PART_5}, /* dss_disp_buf       128MB p44 */
    {PART_HITEST_JPEGENC,     24146 * 1024,   200 * 1024, UFS_PART_5}, /* hitest_jpegenc     200MB p45 */
    {PART_HITEST_HIPP,        24346 * 1024,   100 * 1024, UFS_PART_5}, /* hitest_hipp        100MB p46 */
    {PART_HIBENCH_LPM3,       24446 * 1024,     2 * 1024, UFS_PART_5}, /* hibench_lpm3         2MB p47 */
    {PART_JPEG_DEC_TEST_SRC,  24448 * 1024,    20 * 1024, UFS_PART_5}, /* jpeg_dec_test_src   20MB p48 */
    {PART_JPEG_DEC_TEST_DEST, 24468 * 1024,    80 * 1024, UFS_PART_5}, /* jpeg_dec_test_dest  80MB p49 */
    {PART_VCODE_DATA,         24548 * 1024,   140 * 1024, UFS_PART_5}, /* vcode_data         140MB p50 */
    {PART_HITEST_FFRT,        24688 * 1024,    20 * 1024, UFS_PART_5}, /* hitest_ffrt         20MB p51 */
    {PART_VCODE_MAX_DATA,     24708 * 1024,   140 * 1024, UFS_PART_5}, /* vcode_max_data     140MB p52 */
    {PART_MODEM_TSP_TEST,     24848 * 1024,    32 * 1024, UFS_PART_5}, /* modem_tsp_test      32MB p53 */
    {PART_MODEM_MTEE,         24880 * 1024,     4 * 1024, UFS_PART_5}, /* modem_mtee           4MB p54 */
    {PART_MODEM_VECTOR_CONFIG, 24884 * 1024,     4 * 1024, UFS_PART_5}, /* modem_vector_config   4MB p55 */
    {PART_MODEM_TSP_DT,       24888 * 1024,     1 * 1024, UFS_PART_5}, /* modem_tsp_dt      1024KB p56 */
    {PART_MODEM_L2DLE,        24889 * 1024,     2 * 1024, UFS_PART_5}, /* modem_l2dle          2MB p57 */
    {PART_MODEM_L2DLE_TEST,   24891 * 1024,     2 * 1024, UFS_PART_5}, /* modem_l2dle_test     2MB p58 */
    {PART_MODEM_BBP_TEST,     24893 * 1024,   100 * 1024, UFS_PART_5}, /* modem_bbp_test     100MB p59 */
    {PART_MODEM_PSA_TEST,     24993 * 1024,    20 * 1024, UFS_PART_5}, /* modem_psa_test      20MB p60 */
    {PART_MODEM_PDE_TEST,     25013 * 1024,     5 * 1024, UFS_PART_5}, /* modem_pde_test       5MB p61 */
    {PART_XLOADER_HITEST,     25018 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p62 */
    {PART_HITEST_OISP,        25020 * 1024,    26 * 1024, UFS_PART_5}, /* hitest_oisp         26MB p63 */
#ifdef CONFIG_BOOT_METALBOX
    {PART_METALBOX,           25046 * 1024,     4 * 1024, UFS_PART_5}, /* metalbox             4MB p64 */
    {PART_SLICES,             25050 * 1024,(32UL) * 1024 * 1024, UFS_PART_5}, /* slices            32768MB p65 */
    {PART_USERDATA,           57818 * 1024, (8UL) * 1024 * 1024, UFS_PART_5}, /* userdata      (8G p66 */
#else
    {PART_USERDATA,           25046 * 1024, (8UL) * 1024 * 1024, UFS_PART_5}, /* userdata      (8G p64 */
#endif // CONFIG_BOOT_METALBOX
#else
    {PART_USERDATA,           22752 * 1024, (8UL) * 1024 * 1024, UFS_PART_5}, /* userdata      (8G p34 */
#endif
#endif
    {"0", 0, 0, 0},
};

#endif
