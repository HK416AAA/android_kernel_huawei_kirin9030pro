#ifndef _CHANGSHA_PLAT_PARTITION_H_
#define _CHANGSHA_PLAT_PARTITION_H_

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
    {PART_PTABLE_LU3,             0,                         512,           UFS_PART_3}, /* ptable_lu3       512K    p0 */
    {PART_LOWPOWER_PARA,               512,     1 * 1024, UFS_PART_3}, /* lowpower_para     1024KB p1 */
    {PART_BL2,               (1 * 1024 + 512),     4 * 1024, UFS_PART_3}, /* bl2                  4MB p2 */
    {PART_FW_LPM3,           (5 * 1024 + 512),          512, UFS_PART_3}, /* fw_lpm3            512KB p3 */
    {PART_SEPLAT,                 6 * 1024,     4 * 1024, UFS_PART_3}, /* seplat               4MB p4 */
    {PART_FW_CPU_LPCTRL,         10 * 1024,          256, UFS_PART_3}, /* fw_cpu_lpctrl      256KB p5 */
    {PART_FW_GPU_LPCTRL,     (10 * 1024 + 256),          128, UFS_PART_3}, /* fw_gpu_lpctrl      128KB p6 */
    {PART_FW_DDR_LPCTRL,     (10 * 1024 + 384),          320, UFS_PART_3}, /* fw_ddr_lpctrl      320KB p7 */
    {PART_DDR_XPU_BOOT0,     (10 * 1024 + 704),          320, UFS_PART_3}, /* ddr_xpu_boot0      320KB p8 */
    {PART_DDR_XPU_BOOT1,         11 * 1024,          320, UFS_PART_3}, /* ddr_xpu_boot1      320KB p9 */
    {PART_DDR_XPU_BOOT2,     (11 * 1024 + 320),          320, UFS_PART_3}, /* ddr_xpu_boot2      320KB p10 */
    {PART_UCE,               (11 * 1024 + 640),          160, UFS_PART_3}, /* uce                160KB p11 */
    {PART_FW_MEDIA_LPCTRL,   (11 * 1024 + 800),          128, UFS_PART_3}, /* fw_media_lpctrl    128KB p12 */
	{PART_NPU,               (11 * 1024 + 928),     8 * 1024, UFS_PART_3}, /* npu                  8MB p13 */
    {PART_IVP,               (19 * 1024 + 928),     2 * 1024, UFS_PART_3}, /* ivp                  2MB p14 */
    {PART_DACC,              (21 * 1024 + 928),          256, UFS_PART_3}, /* dacc               256KB p15 */
    {PART_DACC_AAE,          (22 * 1024 + 160),          256, UFS_PART_3}, /* dacc_aae           256KB p16 */
    {PART_VENC,              (22 * 1024 + 416),          512, UFS_PART_3}, /* venc               512KB p17 */
    {PART_HISEE_IMG,         (22 * 1024 + 928),     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p18 */
    {PART_HHEE,              (26 * 1024 + 928),     4 * 1024, UFS_PART_3}, /* hhee                 4MB p19 */
    {PART_FASTBOOT,          (30 * 1024 + 928),    12 * 1024, UFS_PART_3}, /* fastboot            12MB p20 */
    {PART_VECTOR,            (42 * 1024 + 928),     4 * 1024, UFS_PART_3}, /* vector               4MB p21 */
    {PART_ISP_BOOT,          (46 * 1024 + 928),     2 * 1024, UFS_PART_3}, /* isp_boot             2MB p22 */
    {PART_ISP_FIRMWARE,      (48 * 1024 + 928),    14 * 1024, UFS_PART_3}, /* isp_firmware        14MB p23 */
    {PART_FW_HIFI,           (62 * 1024 + 928),    12 * 1024, UFS_PART_3}, /* fw_hifi             12MB p24 */
    {PART_TEEOS,             (74 * 1024 + 928),     8 * 1024, UFS_PART_3}, /* teeos                8MB p25 */
    {PART_SENSORHUB,         (82 * 1024 + 928),    13 * 1024, UFS_PART_3}, /* sensorhub           13MB p26 */
    {PART_SENSORHUB_LOG_DIC, (95 * 1024 + 928),     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p27 */
    {PART_HKRR,              (98 * 1024 + 928),    16 * 1024, UFS_PART_3}, /* hkrr                16MB p28 */
    {PART_FW_UFSDEV,         (114 * 1024 + 928),     4 * 1024, UFS_PART_3}, /* fw_ufsdev            4MB p29 */
    {PART_FW_DFA,            (118 * 1024 + 928),     1 * 1024, UFS_PART_3}, /* fw_dfa            1024KB p30 */ 
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK, (119 * 1024 + 928),    12 * 1024, UFS_PART_3}, /* erecovery_ramdisk   12MB p31 */
    {PART_ERECOVERY_VENDOR,  (131 * 1024 + 928),     8 * 1024, UFS_PART_3}, /* erecovery_vendor     8MB p32 */
    {PART_BOOT,              (139 * 1024 + 928),    81 * 1024, UFS_PART_3}, /* boot                81MB p33 */
    {PART_RECOVERY,          (220 * 1024 + 928),    85 * 1024, UFS_PART_3}, /* recovery            85MB p34 */
    {PART_ERECOVERY,         (305 * 1024 + 928),    12 * 1024, UFS_PART_3}, /* erecovery           12MB p35 */
    {PART_EXT_RVT,           (317 * 1024 + 928),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p36 */
    {PART_RESERVED,          (319 * 1024 + 928),(69 * 1024+512), UFS_PART_3}, /* reserved          71168KB p37 */
    {PART_RECOVERY_RAMDISK,  (389 * 1024 + 416),    32 * 1024, UFS_PART_3}, /* recovery_ramdisk    32MB p38 */
    {PART_RECOVERY_VENDOR,   (421 * 1024 + 416),    24 * 1024, UFS_PART_3}, /* recovery_vendor     24MB p39 */
#elif defined CONFIG_HWSANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK, (119 * 1024 + 928),    40 * 1024, UFS_PART_3}, /* erecovery_ramdisk   40MB p31 */
    {PART_ERECOVERY_VENDOR,  (159 * 1024 + 928),    24 * 1024, UFS_PART_3}, /* erecovery_vendor    24MB p32 */
    {PART_BOOT,              (183 * 1024 + 928),    46 * 1024, UFS_PART_3}, /* boot                46MB p33 */
    {PART_RECOVERY,          (229 * 1024 + 928),    66 * 1024, UFS_PART_3}, /* recovery            66MB p34 */
    {PART_ERECOVERY,         (295 * 1024 + 928),    66 * 1024, UFS_PART_3}, /* erecovery           66MB p35 */
    {PART_EXT_RVT,           (361 * 1024 + 928),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p36 */
    {PART_RESERVED,          (363 * 1024 + 928),(17 * 1024+512), UFS_PART_3}, /* reserved          17920KB p37 */
    {PART_RECOVERY_RAMDISK,  (381 * 1024 + 416),    40 * 1024, UFS_PART_3}, /* recovery_ramdisk    40MB p38 */
    {PART_RECOVERY_VENDOR,   (421 * 1024 + 416),    24 * 1024, UFS_PART_3}, /* recovery_vendor     24MB p39 */
#else
    {PART_ERECOVERY_RAMDISK, (119 * 1024 + 928),    32 * 1024, UFS_PART_3}, /* erecovery_ramdisk   32MB p31 */
    {PART_ERECOVERY_VENDOR,  (151 * 1024 + 928),    24 * 1024, UFS_PART_3}, /* erecovery_vendor    24MB p32 */
    {PART_BOOT,              (175 * 1024 + 928),    46 * 1024, UFS_PART_3}, /* boot                46MB p33 */
    {PART_RECOVERY,          (221 * 1024 + 928),    66 * 1024, UFS_PART_3}, /* recovery            66MB p34 */
    {PART_ERECOVERY,         (287 * 1024 + 928),    66 * 1024, UFS_PART_3}, /* erecovery           66MB p35 */
    {PART_EXT_RVT,           (353 * 1024 + 928),     2 * 1024, UFS_PART_3}, /* ext_rvt              2MB p36 */
    {PART_RESERVED,          (355 * 1024 + 928),(33 * 1024+512), UFS_PART_3}, /* reserved          34304KB p37 */
    {PART_RECOVERY_RAMDISK,  (389 * 1024 + 416),    32 * 1024, UFS_PART_3}, /* recovery_ramdisk    32MB p38 */
    {PART_RECOVERY_VENDOR,   (421 * 1024 + 416),    24 * 1024, UFS_PART_3}, /* recovery_vendor     24MB p39 */
#endif
    {PART_THEE,              (445 * 1024 + 416),     4 * 1024, UFS_PART_3}, /* thee                 4MB p40 */
    {PART_TZSP,              (449 * 1024 + 416),    12 * 1024, UFS_PART_3}, /* tzsp                12MB p41 */
    {PART_ENG_SYSTEM,        (461 * 1024 + 416),    12 * 1024, UFS_PART_3}, /* eng_system          12MB p42 */
    {PART_ENG_VENDOR,        (473 * 1024 + 416),    20 * 1024, UFS_PART_3}, /* eng_vendor          20MB p43 */
    {PART_FW_DTB,            (493 * 1024 + 416),    20 * 1024, UFS_PART_3}, /* fw_dtb              20MB p44 */
    {PART_DTBO,              (513 * 1024 + 416),    20 * 1024, UFS_PART_3}, /* dtbo                20MB p45 */
    {PART_TRUSTFIRMWARE,     (533 * 1024 + 416),     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p46 */
    {PART_DPA_VENDOR,        (535 * 1024 + 416),    32 * 1024, UFS_PART_3}, /* dpa_vendor          32MB p47 */
    {PART_MODEM_FW,          (567 * 1024 + 416),   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p48 */
    {PART_MODEM_VENDOR,      (691 * 1024 + 416),    10 * 1024, UFS_PART_3}, /* modem_vendor        10MB p49 */
    {PART_MODEM_PATCH_NV,    (701 * 1024 + 416),     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p50 */
    {PART_MODEM_DRIVER,      (705 * 1024 + 416),    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p51 */
    {PART_MODEMNVM_UPDATE,   (725 * 1024 + 416),    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p52 */
    {PART_MODEMCONFIG_CUST,  (741 * 1024 + 416),    16 * 1024, UFS_PART_3}, /* modemconfig_cust    16MB p53 */
    {PART_RAMDISK,           (757 * 1024 + 416),     2 * 1024, UFS_PART_3}, /* ramdisk              2MB p54 */
    {PART_VBMETA_SYSTEM,     (759 * 1024 + 416),     1 * 1024, UFS_PART_3}, /* vbmeta_system     1024KB p55 */
    {PART_VBMETA_VENDOR,     (760 * 1024 + 416),     1 * 1024, UFS_PART_3}, /* vbmeta_vendor     1024KB p56 */
    {PART_VBMETA_ODM,        (761 * 1024 + 416),     1 * 1024, UFS_PART_3}, /* vbmeta_odm        1024KB p57 */
    {PART_VBMETA_CUST,       (762 * 1024 + 416),     1 * 1024, UFS_PART_3}, /* vbmeta_cust       1024KB p58 */
    {PART_VBMETA_HW_PRODUCT, (763 * 1024 + 416),     1 * 1024, UFS_PART_3}, /* vbmeta_hw_product 1024KB p59 */
    {PART_RECOVERY_VBMETA,   (764 * 1024 + 416),     2 * 1024, UFS_PART_3}, /* recovery_vbmeta      2MB p60 */
    {PART_ERECOVERY_VBMETA,  (766 * 1024 + 416),     2 * 1024, UFS_PART_3}, /* erecovery_vbmeta     2MB p61 */
    {PART_VBMETA,            (768 * 1024 + 416),     4 * 1024, UFS_PART_3}, /* vbmeta               4MB p62 */
    {PART_KPATCH,            (772 * 1024 + 416),     4 * 1024, UFS_PART_3}, /* kpatch               4MB p63 */
    {PART_PATCH,             (776 * 1024 + 416),    32 * 1024, UFS_PART_3}, /* patch               32MB p64 */
    {PART_RESERVED1_lu3,     (808 * 1024 + 416),    78 * 1024, UFS_PART_3}, /* reserved1_lu3       78MB p65 */
	{PART_PTABLE_LU4,             0,                   512,    UFS_PART_4}, /* ptable_lu4       512K    p0 */
	{PART_RESERVED4_lu4,        512,         885 * 1024 + 928, UFS_PART_4}, /* reserved4_lu4     1024KB p1 */
    {PART_PTABLE_LU5,             0,                   512,    UFS_PART_5}, /* ptable_lu3       512K    p0 */
	{PART_RESERVED1_lu5,                   512,     1 * 1024, UFS_PART_5}, /* reserved1_lu5         1024KB p1 */
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
    {PART_SPLASH2,              351 * 1024,   200 * 1024, UFS_PART_5}, /* splash2             80MB p19 */
    {PART_BOOTFAIL_INFO,        551 * 1024,     2 * 1024, UFS_PART_5}, /* bootfail_info        2MB p20 */
    {PART_MISC,                 553 * 1024,     2 * 1024, UFS_PART_5}, /* misc                 2MB p21 */
    {PART_DFX,                  555 * 1024,    16 * 1024, UFS_PART_5}, /* dfx                 16MB p22 */
    {PART_RRECORD,              571 * 1024,    16 * 1024, UFS_PART_5}, /* rrecord             16MB p23 */
    {PART_CACHE,                587 * 1024,   104 * 1024, UFS_PART_5}, /* cache              104MB p24 */
    {PART_METADATA,             691 * 1024,    16 * 1024, UFS_PART_5}, /* metadata            16MB p25 */
    {PART_TOC,                  707 * 1024,     1 * 1024, UFS_PART_5}, /* toc               1024KB p26 */
    {PART_DDR_FAC_INFO,         708 * 1024,     1 * 1024, UFS_PART_5}, /* ddr_fac_info      1024KB p27 */
    {PART_DVFS,                 709 * 1024,     1 * 1024, UFS_PART_5}, /* dvfs              1024KB p28 */
    {PART_HISEE_FS,             710 * 1024,     8 * 1024, UFS_PART_5}, /* hisee_fs             8MB p29 */
    {PART_MODULE_UPDATE,        718 * 1024,          512, UFS_PART_5}, /* module_update      512KB p30 */
    {PART_RESERVED3,         (718 * 1024 + 512),(5 * 1024+512), UFS_PART_5}, /* reserved3         5632KB p31 */
#ifdef CONFIG_FACTORY_MODE
    {PART_PREAS,                724 * 1024,   368 * 1024, UFS_PART_5}, /* preas              368MB p32 */
    {PART_PREAVS,              1092 * 1024,    32 * 1024, UFS_PART_5}, /* preavs              32MB p33 */
    {PART_SUPER,               1124 * 1024, 10306 * 1024, UFS_PART_5}, /* super             10306MB p34 */
    {PART_VERSION,            11430 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p35 */
    {PART_PRELOAD,            12006 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p36 */
    {PART_HIBENCH_IMG,        13406 * 1024,    12 * 1024, UFS_PART_5}, /* hibench_img         12MB p37 */
    {PART_HIBENCH_DATA,       13418 * 1024,  2048 * 1024, UFS_PART_5}, /* hibench_data      2048MB p38 */
    {PART_HIBENCH_LOG,        15466 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p39 */
    {PART_XLOADER_HITEST,     15498 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p40 */
    {PART_FLASH_AGEING,       15500 * 1024,   512 * 1024, UFS_PART_5}, /* flash_ageing       512MB p41 */
    {PART_USERDATA,           16012 * 1024,     8 * 1024 * 1024, UFS_PART_5}, /* userdata       4G p42 */
#elif defined CONFIG_MARKET_INTERNAL
#ifdef CONFIG_USE_EROFS
    {PART_PREAS,                724 * 1024,   296 * 1024, UFS_PART_5}, /* preas              296MB p32 */
    {PART_PREAVS,              1020 * 1024,    32 * 1024, UFS_PART_5}, /* preavs              32MB p33 */
    {PART_SUPER,               1052 * 1024, 28088 * 1024, UFS_PART_5}, /* super             28086MB p34 */
    {PART_VERSION,            29140 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p35 */
    {PART_PRELOAD,            29716 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p36 */
    {PART_USERDATA,           31116 * 1024,     8 * 1024 * 1024, UFS_PART_5}, /* userdata       4G p37 */
#else
    {PART_PREAS,                724 * 1024,   368 * 1024, UFS_PART_5}, /* preas              368MB p32 */
    {PART_PREAVS,              1092 * 1024,    32 * 1024, UFS_PART_5}, /* preavs              32MB p33 */
    {PART_SUPER,               1124 * 1024, 12624 * 1024, UFS_PART_5}, /* super             12624MB p34 */
    {PART_VERSION,            13748 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p35 */
    {PART_PRELOAD,            14324 * 1024,  1144 * 1024, UFS_PART_5}, /* preload           1144MB p36 */
    {PART_USERDATA,           15468 * 1024,     8 * 1024 * 1024, UFS_PART_5}, /* userdata       4G p37 */
#endif
#elif defined CONFIG_MARKET_OVERSEA
#ifdef CONFIG_USE_EROFS
    {PART_PREAS,                724 * 1024,  1024 * 1024, UFS_PART_5}, /* preas             1024 * 1024KB p32 */
    {PART_PREAVS,              1748 * 1024,    32 * 1024, UFS_PART_5}, /* preavs              32MB p33 */
    {PART_SUPER,               1780 * 1024, 10548 * 1024, UFS_PART_5}, /* super             10548MB p34 */
    {PART_VERSION,            12328 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p35 */
    {PART_PRELOAD,            12904 * 1024,  1400 * 1024, UFS_PART_5}, /* preload           1400MB p36 */
    {PART_USERDATA,           14304 * 1024,     8 * 1024 * 1024, UFS_PART_5}, /* userdata       4G p37 */
#else /* end erofs */
    {PART_PREAS,                724 * 1024,  1280 * 1024, UFS_PART_5}, /* preas             1280MB p32 */
    {PART_PREAVS,              2004 * 1024,    32 * 1024, UFS_PART_5}, /* preavs              32MB p33 */
    {PART_SUPER,               2036 * 1024, 13084 * 1024, UFS_PART_5}, /* super             13084MB p34 */
    {PART_VERSION,            15120 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p35 */
    {PART_PRELOAD,            15696 * 1024,  1144 * 1024, UFS_PART_5}, /* preload           1144MB p36 */
    {PART_USERDATA,           16840 * 1024,     8 * 1024 * 1024, UFS_PART_5}, /* userdata       4G p37 */
#endif
#elif defined CONFIG_GCOV_PARTITION_SUPPORT_ENABLE
    {PART_PREAS,                724 * 1024,    32 * 1024, UFS_PART_5}, /* preas               32MB p32 */
    {PART_PREAVS,               756 * 1024,    32 * 1024, UFS_PART_5}, /* preavs              32MB p33 */
    {PART_SUPER,                788 * 1024, 13104 * 1024, UFS_PART_5}, /* super             13104MB p34 */
    {PART_VERSION,            13892 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p35 */
    {PART_PRELOAD,            14468 * 1024,  1144 * 1024, UFS_PART_5}, /* preload           1144MB p36 */
    {PART_USERDATA,           15612 * 1024,     8 * 1024 * 1024, UFS_PART_5}, /* userdata       4G p37 */
#else
    {PART_PREAS,                724 * 1024,  1280 * 1024, UFS_PART_5}, /* preas             1280MB p32 */
    {PART_PREAVS,              2004 * 1024,    32 * 1024, UFS_PART_5}, /* preavs              32MB p33 */
    {PART_SUPER,               2036 * 1024, 13104 * 1024, UFS_PART_5}, /* super             13104MB p34 */
    {PART_VERSION,            15140 * 1024,   576 * 1024, UFS_PART_5}, /* version            576MB p35 */
    {PART_PRELOAD,            15716 * 1024,  1144 * 1024, UFS_PART_5}, /* preload           1144MB p36 */
#if defined(CONFIG_PARTITION_ENG)
    {PART_FTTEST,             16860 * 1024,    12 * 1024, UFS_PART_5}, /* fttest              12MB p37 */
    {PART_XLOADER_HITEST,     16872 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p38 */
    {PART_DDRTEST,            16874 * 1024,    48 * 1024, UFS_PART_5}, /* ddrtest             48MB p39 */
    {PART_HITEST_GPU,         16922 * 1024,   512 * 1024, UFS_PART_5}, /* hitest_gpu         512MB p40 */
    {PART_HITEST_CPU,         17434 * 1024,    50 * 1024, UFS_PART_5}, /* hitest_cpu          50MB p41 */
    {PART_VCODE_DATA,         17484 * 1024,   180 * 1024, UFS_PART_5}, /* vcode_data         180MB p42 */
    {PART_VCODE_MAX_DATA,     17664 * 1024,   160 * 1024, UFS_PART_5}, /* vcode_max_data     160MB p43 */
    {PART_JPEG_DEC_TEST_SRC,  17824 * 1024,    20 * 1024, UFS_PART_5}, /* jpeg_dec_test_src   20MB p44 */
    {PART_JPEG_DEC_TEST_DEST, 17844 * 1024,    80 * 1024, UFS_PART_5}, /* jpeg_dec_test_dest  80MB p45 */
    {PART_HITEST_ISP,         17924 * 1024,    25 * 1024, UFS_PART_5}, /* hitest_isp          25MB p46 */
    {PART_HITEST_ISP_AVS,     17949 * 1024,    65 * 1024, UFS_PART_5}, /* hitest_isp_avs      65MB p47 */
    {PART_HITEST_HIPP,        18014 * 1024,   100 * 1024, UFS_PART_5}, /* hitest_hipp        100MB p48 */
    {PART_HITEST_OISP,        18114 * 1024,    10 * 1024, UFS_PART_5}, /* hitest_oisp         10MB p49 */
    {PART_DSS_DISP_BUF,       18124 * 1024,   128 * 1024, UFS_PART_5}, /* dss_disp_buf       128MB p50 */
    {PART_HITEST_ASP_DHRYSTONE, 18252 * 1024,    20 * 1024, UFS_PART_5}, /* hitest_asp_dhrystone  20MB p51 */
    {PART_HITEST_ASP_TEST,    18272 * 1024,   300 * 1024, UFS_PART_5}, /* hitest_asp_test    300MB p52 */
    {PART_HITEST_SENSORHUB,   18572 * 1024,     6 * 1024, UFS_PART_5}, /* hitest_sensorhub     6MB p53 */
    {PART_HITEST_NPU,         18578 * 1024,    20 * 1024, UFS_PART_5}, /* hitest_npu          20MB p54 */
    {PART_MODEM_BBP_TEST,     18598 * 1024,   150 * 1024, UFS_PART_5}, /* modem_bbp_test     150MB p55 */
    {PART_MODEM_VECTOR_CONFIG, 18748 * 1024,     1 * 1024, UFS_PART_5}, /* modem_vector_config1024KB p56 */
    {PART_MODEM_IMG_TEST,     18749 * 1024,    79 * 1024, UFS_PART_5}, /* modem_img_test      79MB p57 */
    {PART_HITEST_JPEGENC,     18828 * 1024,   260 * 1024, UFS_PART_5}, /* hitest_jpegenc     260MB p58 */
    {PART_HITEST_DATA,        19088 * 1024,  2228 * 1024, UFS_PART_5}, /* hitest_data       2228MB p59 */
    {PART_DISP_PANEL_INFO,    21316 * 1024,    20 * 1024, UFS_PART_5}, /* disp_panel_info    20MB p60 */
#ifdef CONFIG_BOOT_METALBOX
    {PART_METALBOX,           21336 * 1024,     4 * 1024, UFS_PART_5}, /* metalbox             4MB p61 */
    {PART_SLICES,             21340 * 1024,32 * 1024 * 1024, UFS_PART_5},/* slices            32768MB p62 */
    {PART_USERDATA,           54108 * 1024,     8 * 1024 * 1024, UFS_PART_5}, /* userdata       4G p63 */
#else
    {PART_USERDATA,           21336 * 1024,     8 * 1024 * 1024, UFS_PART_5}, /* userdata       4G p61 */
#endif // CONFIG_BOOT_METALBOX
#else
    {PART_USERDATA,           16860 * 1024,     8 * 1024 * 1024, UFS_PART_5}, /* userdata       4G p37 */
#endif
#endif
    {"0", 0, 0, 0},
};

#endif
