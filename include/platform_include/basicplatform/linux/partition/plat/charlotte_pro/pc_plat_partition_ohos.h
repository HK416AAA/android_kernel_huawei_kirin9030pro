#ifndef _ANTLIA_PLAT_PARTITION_OHOS_H_
#define _ANTLIA_PLAT_PARTITION_OHOS_H_
 
#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"
 
static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};
 
static const struct partition partition_table_ufs[] = {
    {PART_PTABLE,                      0,           136, SPI_NOR_PART}, /* ptable            136K    p0  */
    {PART_BOOT_CTRL,                  136,            4, SPI_NOR_PART}, /* boot_ctrl            4KB p1 */
    {PART_BL2_A,                      140,          900, SPI_NOR_PART}, /* bl2_a                900KB p2 */
    {PART_FW_CPU_LPCTRL_A,           1040,          256, SPI_NOR_PART}, /* fw_cpu_lpctrl_a      256KB p3 */
    {PART_FW_GPU_LPCTRL_A,           1296,          128, SPI_NOR_PART}, /* fw_gpu_lpctrl_a      128KB p4 */
    {PART_FW_DDR_LPCTRL_A,           1424,          128, SPI_NOR_PART}, /* fw_ddr_lpctrl_a      128KB p5 */
    {PART_DDR_XPU_BOOT0_A,           1552,          136, SPI_NOR_PART}, /* ddr_xpu_boot0_a      136KB p6 */
    {PART_DDR_XPU_BOOT1_A,           1688,          136, SPI_NOR_PART}, /* ddr_xpu_boot1_a      136KB p7 */
    {PART_FW_DTB_A,                  1824,          516, SPI_NOR_PART}, /* fw_dtb_a             516KB p8 */
    {PART_DACC_A,                    2340,          128, SPI_NOR_PART}, /* dacc_a               128KB p9 */
    {PART_TRUSTFIRMWARE_A,           2468,          512, SPI_NOR_PART}, /* trustfirmware_a      512KB p10 */
    {PART_MSPC_DATA,                 2980,           96, SPI_NOR_PART}, /* mspc_data           96KB p11 */
    {PART_HHEE_A,                    3076,          200, SPI_NOR_PART}, /* hhee_a               200KB p12 */
    {PART_DFX_XLOADER,               3276,           16, SPI_NOR_PART}, /* dfx_xloader         16KB p13 */
    {PART_RESERVED1,                 3292,           88, SPI_NOR_PART}, /* reserved1          104KB p14 */
    /* !!!Attention!!! cannot modify xloader_a offset */
    {PART_XLOADER_A,                 3380,         1024, SPI_NOR_PART}, /* xloader_a         1024KB p15 */
    {PART_NVME,                      4404,         1024, SPI_NOR_PART}, /* nvme              1024KB p16 */
#ifdef CONFIG_FACTORY_MODE
    {PART_FASTBOOT_A,                5428,         5120, SPI_NOR_PART}, /* fastboot             5MB p14 */
    {PART_HIBENCH_IMG,              10548,         4608, SPI_NOR_PART}, /* hibench_img       4608KB p15 */
    {PART_HIBENCH_LOG,              15156,          512, SPI_NOR_PART}, /* hibench_log        512KB p16 */
#else
    {PART_FASTBOOT_A,                5428,         6144, SPI_NOR_PART}, /* fastboot_a             6MB p17 */
    {PART_BL2_B,                    11572,          900, SPI_NOR_PART}, /* bl2_b                900KB p18 */
    {PART_FW_CPU_LPCTRL_B,          12472,          256, SPI_NOR_PART}, /* fw_cpu_lpctrl_b      256KB p19 */
    {PART_FW_GPU_LPCTRL_B,          12728,          128, SPI_NOR_PART}, /* fw_gpu_lpctrl_b      128KB p20 */
    {PART_DDR_XPU_BOOT0_B,          12856,          136, SPI_NOR_PART}, /* ddr_xpu_boot0_b      136KB p21 */
    {PART_DDR_XPU_BOOT1_B,          12992,          136, SPI_NOR_PART}, /* ddr_xpu_boot1_b      136KB p22 */
    {PART_LOWPOWER_PARA_B,          13128,          512, SPI_NOR_PART}, /* lowpower_para_b     512KB p26 */
    {PART_RESERVED2,                13640,         2028, SPI_NOR_PART}, /* reserved2           2540KB p23 */
#endif
    {PART_DDR_PARA,                 15668,          256, SPI_NOR_PART}, /* ddr_para           256KB p24 */
    {PART_UEFI_LOGO,                15924,          768, SPI_NOR_PART}, /* uefi_logo          768KB p25 */
    {PART_LOWPOWER_PARA_A,          16692,          512, SPI_NOR_PART}, /* lowpower_para_a    512KB p26 */
    {PART_FW_LPM3_A,                17204,          512, SPI_NOR_PART}, /* fw_lpm3_a          512KB p27 */
    {PART_TOC,                      17716,           32, SPI_NOR_PART}, /* toc                 32KB p28 */
    {PART_RESERVED3,                17748,          316, SPI_NOR_PART}, /* reserved3          316KB p29 */
    {PART_XLOADER_B,                18064,         1024, SPI_NOR_PART}, /* xloader_b         1024KB p30 */
    {PART_UEFI_VB,                  19088,          256, SPI_NOR_PART}, /* uefi_vb            256KB p31 */
    {PART_HDMI_A,                   19344,           80, SPI_NOR_PART}, /* hdmi_a              80KB p32 */
    {PART_THEE_A,                   19424,         2048, SPI_NOR_PART}, /* thee_a               2MB p33 */
    {PART_TZSP_A,                   21472,         2048, SPI_NOR_PART}, /* tzsp_a               2MB p34 */
    {PART_TEEOS_A,                  23520,         5120, SPI_NOR_PART}, /* teeos_a              5MB p35 */
    {PART_OEMINFO_NOR,              28640,         3072, SPI_NOR_PART}, /* oeminfo_nor          3MB p36 */
    {PART_RPM_MAC,                  31712,            4, SPI_NOR_PART}, /* rpm_mac              4KB p37 */
    {PART_UAPP,                     31716,            4, SPI_NOR_PART}, /* uapp                 4KB p38 */
    {PART_VERIFI_BOOT,              31720,            4, SPI_NOR_PART}, /* verifi_boot          4KB p39 */
    {PART_MSPC_CODE_A,              31724,          216, SPI_NOR_PART}, /* mspc_code_a        216KB p40 */
    {PART_MSPC_IMG_A,               31940,          256, SPI_NOR_PART}, /* mspc_img_a         256KB p41 */
    {PART_VECTOR,                   32196,          512, SPI_NOR_PART}, /* vector             512KB p42 */
    {PART_CTF,                      32708,           16, SPI_NOR_PART}, /* ctf                 16KB p43 */
    {PART_RESERVED4,                32724,           24, SPI_NOR_PART}, /* reserved4           24KB p44 */
    {PART_PTABLE_SSD,                   0,                 512, SSD_PART}, /* ptable_ssd          512K p45 */
    {PART_PERSIST,                    512,            6 * 1024, SSD_PART}, /* persist              6MB p46 */
    {PART_CONN_CALIDATA,      (6 * 1024 + 512),           1024, SSD_PART}, /* conn_calidata     1024KB p47 */
    {PART_OEMINFO,            (7 * 1024 + 512),      96 * 1024, SSD_PART}, /* oeminfo             96MB p48 */
    {PART_SECURE_STORAGE,     (103 * 1024 + 512),    32 * 1024, SSD_PART}, /* secure_storage      32MB p49 */
    {PART_SECURE_TEE,         (135 * 1024 + 512),    13 * 1024, SSD_PART}, /* secure_tee          13MB p50 */
    {PART_HISEE_ENCOS,        (148 * 1024 + 512),     4 * 1024, SSD_PART}, /* hisee_encos          4MB p51 */
    {PART_NVME_BAK,           (152 * 1024 + 512),     1 * 1024, SSD_PART}, /* nvme_bak             1MB p52 */
    {PART_RESERVED5,          (153 * 1024 + 512),    19 * 1024, SSD_PART}, /* reserved5           19MB p53 */
    {PART_LOG,                (172 * 1024 + 512),    80 * 1024, SSD_PART}, /* log                 80MB p54 */
    {PART_BOOTFAIL_INFO,      (252 * 1024 + 512),     2 * 1024, SSD_PART}, /* bootfail_info        2MB p55 */
    {PART_MISC,               (254 * 1024 + 512),     2 * 1024, SSD_PART}, /* misc                 2MB p56 */
    {PART_DFX,                (256 * 1024 + 512),    16 * 1024, SSD_PART}, /* dfx                 16MB p57 */
    {PART_RRECORD,            (272 * 1024 + 512),    16 * 1024, SSD_PART}, /* rrecord             16MB p58 */
    {PART_CACHE,              (288 * 1024 + 512),   104 * 1024, SSD_PART}, /* cache              104MB p59 */
    {PART_METADATA,           (392 * 1024 + 512),    16 * 1024, SSD_PART}, /* metadata            16MB p60 */
    {PART_RESERVED6,          (408 * 1024 + 512),     4 * 1024, SSD_PART}, /* reserved6            4MB p61 */
    {PART_NPU,                (412 * 1024 + 512),     8 * 1024, SSD_PART}, /* npu                  8MB p62 */
    {PART_IVP,                (420 * 1024 + 512),     2 * 1024, SSD_PART}, /* ivp                  2MB p63 */
    {PART_VENC,               (422 * 1024 + 512),          512, SSD_PART}, /* venc               512KB p64 */
    {PART_HISEE_IMG,           423 * 1024,     4 * 1024, SSD_PART}, /* hisee_img            4MB p65 */
    {PART_HISEE_FS,            427 * 1024,     8 * 1024, SSD_PART}, /* hisee_fs             8MB p66 */
    {PART_ISP_BOOT,            435 * 1024,     2 * 1024, SSD_PART}, /* isp_boot             2MB p67 */
    {PART_ISP_FIRMWARE,        437 * 1024,    14 * 1024, SSD_PART}, /* isp_firmware        14MB p68 */
    {PART_FW_HIFI,             451 * 1024,    12 * 1024, SSD_PART}, /* fw_hifi             12MB p69 */
    {PART_SENSORHUB,           463 * 1024,    13 * 1024, SSD_PART}, /* sensorhub           13MB p70 */
    {PART_SENSORHUB_LOG_DIC,   476 * 1024,     3 * 1024, SSD_PART}, /* sensorhub_log_dic     3MB p71 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_RESERVED7,           479 * 1024,    24 * 1024, SSD_PART}, /* reserved7           24MB p27 */
    {PART_ESP,                 503 * 1024,   200 * 1024, SSD_PART}, /* esp                200MB p28 */
    {PART_UPDATER_RAMDISK,     703 * 1024,    32 * 1024, SSD_PART}, /* updater_ramdisk     32MB p29 */
    {PART_UPDATER_VENDOR,      735 * 1024,    24 * 1024, SSD_PART}, /* updater_vendor      24MB p30 */
    {PART_BOOT,                759 * 1024,    65 * 1024, SSD_PART}, /* boot                65MB p31 */
    {PART_UPDATER_BOOT,        824 * 1024,    54 * 1024, SSD_PART}, /* updater_boot        54MB p32 */
    {PART_UPDATER_BOOT_BAK,    878 * 1024,    54 * 1024, SSD_PART}, /* updater_boot_bak    54MB p33 */
    {PART_UPDATER_RAMDISK_BAK,   932 * 1024,    32 * 1024, SSD_PART}, /* updater_ramdisk_bak  32MB p34 */
    {PART_UPDATER_VENDOR_BAK,   964 * 1024,    24 * 1024, SSD_PART}, /* updater_vendor_bak  24MB p35 */
    {PART_ENG_SYSTEM,          988 * 1024,    12 * 1024, SSD_PART}, /* eng_system          12MB p36 */
    {PART_ENG_CHIPSET,        1000 * 1024,    20 * 1024, SSD_PART}, /* eng_chipset         20MB p37 */
    {PART_DTBO,               1020 * 1024,    14 * 1024, SSD_PART}, /* dtbo                14MB p38 */
    {PART_RAMDISK,            1034 * 1024,     3 * 1024, SSD_PART}, /* ramdisk              3MB p39 */
    {PART_RVT_SYSTEM,         1037 * 1024,     1 * 1024, SSD_PART}, /* rvt_system        1024KB p40 */
    {PART_RVT_VENDOR,         1038 * 1024,     1 * 1024, SSD_PART}, /* rvt_vendor        1024KB p41 */
    {PART_RVT_CHIP_PROD,      1039 * 1024,     1 * 1024, SSD_PART}, /* rvt_chip_prod     1024KB p42 */
    {PART_RVT_CUST,           1040 * 1024,     1 * 1024, SSD_PART}, /* rvt_cust          1024KB p43 */
    {PART_RVT_SYS_PROD,       1041 * 1024,     1 * 1024, SSD_PART}, /* rvt_sys_prod      1024KB p44 */
    {PART_UPDATER_RVT,        1042 * 1024,     2 * 1024, SSD_PART}, /* updater_rvt          2MB p45 */
    {PART_UPDATER_BAK_RVT,    1044 * 1024,     2 * 1024, SSD_PART}, /* updater_bak_rvt      2MB p46 */
    {PART_RVT,                1046 * 1024,     4 * 1024, SSD_PART}, /* rvt                  4MB p47 */
    {PART_SEPLAT,             1050 * 1024,     4 * 1024, SSD_PART}, /* seplat               4MB p48 */
    {PART_KPATCH,             1054 * 1024,     4 * 1024, SSD_PART}, /* kpatch               4MB p49 */
    {PART_PATCH,              1058 * 1024,    32 * 1024, SSD_PART}, /* patch               32MB p50 */
    {PART_CUST,               1090 * 1024,    88 * 1024, SSD_PART}, /* cust                88MB p51 */
    {PART_CHIP_PROD,          1178 * 1024,   616 * 1024, SSD_PART}, /* chip_prod          616MB p52 */
    {PART_VENDOR,             1794 * 1024,   920 * 1024, SSD_PART}, /* vendor             920MB p53 */
    {PART_SYS_PROD,           2714 * 1024,  9766 * 1024, SSD_PART}, /* sys_prod          9766MB p54 */
    {PART_SYSTEM,            12480 * 1024,  6860 * 1024, SSD_PART}, /* system            6860MB p55 */
    {PART_HYPERHOLD,         19340 * 1024,     4 * 1024, SSD_PART}, /* hyperhold            4MB p56 */
    {PART_MODULE_UPDATE,     19344 * 1024,          512, SSD_PART}, /* module_update      512KB p57 */
    {PART_EXT_RVT,          (19344 * 1024 + 512), 2 * 1024, SSD_PART}, /* ext_rvt              2MB p58 */
    {PART_RESERVED8,        (19346 * 1024 + 512),  (1003 * 1024+512), SSD_PART}, /* reserved8         1006 * 1024KB p59 */
#elif defined CONFIG_ASAN_SUPPORT_ENABLE
    {PART_RESERVED7,           479 * 1024,    23 * 1024, SSD_PART}, /* reserved7           24MB p27 */
    {PART_ESP,                 502 * 1024,   200 * 1024, SSD_PART}, /* esp                200MB p28 */
    {PART_UPDATER_RAMDISK,     702 * 1024,    32 * 1024, SSD_PART}, /* updater_ramdisk     32MB p29 */
    {PART_UPDATER_VENDOR,      734 * 1024,    25 * 1024, SSD_PART}, /* updater_vendor      25MB p30 */
    {PART_BOOT,                759 * 1024,    51 * 1024, SSD_PART}, /* boot                65MB p31 */
    {PART_UPDATER_BOOT,        810 * 1024,    52 * 1024, SSD_PART}, /* updater_boot        45MB p32 */
    {PART_UPDATER_BOOT_BAK,    862 * 1024,    52 * 1024, SSD_PART}, /* updater_boot_bak    45MB p33 */
    {PART_UPDATER_RAMDISK_BAK,   914 * 1024,    32 * 1024, SSD_PART}, /* updater_ramdisk_bak  32MB p34 */
    {PART_UPDATER_VENDOR_BAK,   946 * 1024,    25 * 1024, SSD_PART}, /* updater_vendor_bak  25MB p35 */
    {PART_ENG_SYSTEM,          971 * 1024,    12 * 1024, SSD_PART}, /* eng_system          12MB p36 */
    {PART_ENG_CHIPSET,         983 * 1024,    20 * 1024, SSD_PART}, /* eng_chipset         20MB p37 */
    {PART_DTBO,               1003 * 1024,    14 * 1024, SSD_PART}, /* dtbo                14MB p38 */
    {PART_RAMDISK,            1017 * 1024,     3 * 1024, SSD_PART}, /* ramdisk              3MB p39 */
    {PART_RVT_SYSTEM,         1020 * 1024,     1 * 1024, SSD_PART}, /* rvt_system        1024KB p40 */
    {PART_RVT_VENDOR,         1021 * 1024,     1 * 1024, SSD_PART}, /* rvt_vendor        1024KB p41 */
    {PART_RVT_CHIP_PROD,      1022 * 1024,     1 * 1024, SSD_PART}, /* rvt_chip_prod     1024KB p42 */
    {PART_RVT_CUST,           1023 * 1024,     1 * 1024, SSD_PART}, /* rvt_cust          1024KB p43 */
    {PART_RVT_SYS_PROD,       1024 * 1024,     1 * 1024, SSD_PART}, /* rvt_sys_prod      1024KB p44 */
    {PART_UPDATER_RVT,        1025 * 1024,     2 * 1024, SSD_PART}, /* updater_rvt          2MB p45 */
    {PART_UPDATER_BAK_RVT,    1027 * 1024,     2 * 1024, SSD_PART}, /* updater_bak_rvt      2MB p46 */
    {PART_RVT,                1029 * 1024,     4 * 1024, SSD_PART}, /* rvt                  4MB p47 */
    {PART_SEPLAT,             1033 * 1024,     4 * 1024, SSD_PART}, /* seplat               4MB p48 */
    {PART_KPATCH,             1037 * 1024,     4 * 1024, SSD_PART}, /* kpatch               4MB p49 */
    {PART_PATCH,              1041 * 1024,    32 * 1024, SSD_PART}, /* patch               32MB p50 */
    {PART_CUST,               1073 * 1024,    88 * 1024, SSD_PART}, /* cust                88MB p51 */
    {PART_CHIP_PROD,          1161 * 1024,   616 * 1024, SSD_PART}, /* chip_prod          616MB p52 */
    {PART_VENDOR,             1777 * 1024,   1900 * 1024, SSD_PART}, /* vendor             1900MB p53 */
    {PART_SYS_PROD,           3677 * 1024,  9766 * 1024, SSD_PART}, /* sys_prod          9766MB p54 */
    {PART_SYSTEM,            13443 * 1024,  6862 * 1024, SSD_PART}, /* system            6862MB p55 */
    {PART_HYPERHOLD,         20305 * 1024,     4 * 1024, SSD_PART}, /* hyperhold            4MB p56 */
    {PART_MODULE_UPDATE,     20309 * 1024,          512, SSD_PART}, /* module_update      512KB p57 */
    {PART_EXT_RVT,          (20309 * 1024 + 512), 2 * 1024, SSD_PART}, /* ext_rvt              2MB p58 */
    {PART_RESERVED8,        (20311 * 1024 + 512),  (38 * 1024+512), SSD_PART}, /* reserved8         43 * 1024KB p59 */
#else
    {PART_RESERVED7,           479 * 1024,    23 * 1024, SSD_PART}, /* reserved7           23MB p27 */
    {PART_ESP,                 502 * 1024,   200 * 1024, SSD_PART}, /* esp                200MB p28 */
    {PART_UPDATER_RAMDISK_A,   702 * 1024,    32 * 1024, SSD_PART}, /* updater_ramdisk_a   32MB p29 */
    {PART_UPDATER_VENDOR_A,    734 * 1024,    24 * 1024, SSD_PART}, /* updater_vendor_a    24MB p30 */
    {PART_BOOT,                758 * 1024,    51 * 1024, SSD_PART}, /* boot                51MB p31 */
    {PART_UPDATER_BOOT_A,      809 * 1024,    52 * 1024, SSD_PART}, /* updater_boot_a        52MB p32 */
    {PART_UPDATER_BOOT_BAK_A,  861 * 1024,    52 * 1024, SSD_PART}, /* updater_boot_bak_a    52MB p33 */
    {PART_UPDATER_RAMDISK_BAK_A, 913 * 1024,  32 * 1024, SSD_PART}, /* updater_ramdisk_bak_a 32MB p34 */
    {PART_UPDATER_VENDOR_BAK_A,  945 * 1024,  24 * 1024, SSD_PART}, /* updater_vendor_bak_a  24MB p35 */
    {PART_ENG_SYSTEM,          969 * 1024,    20 * 1024, SSD_PART}, /* eng_system          20MB p36 */
    {PART_ENG_CHIPSET,         989 * 1024,    20 * 1024, SSD_PART}, /* eng_chipset         20MB p37 */
    {PART_DTBO,               1009 * 1024,    14 * 1024, SSD_PART}, /* dtbo                14MB p38 */
    {PART_RAMDISK,            1023 * 1024,     4 * 1024, SSD_PART}, /* ramdisk              4MB p39 */
    {PART_RVT_SYSTEM,         1027 * 1024,     1 * 1024, SSD_PART}, /* rvt_system        1024KB p40 */
    {PART_RVT_VENDOR,         1028 * 1024,     1 * 1024, SSD_PART}, /* rvt_vendor        1024KB p41 */
    {PART_RVT_CHIP_PROD,      1029 * 1024,     1 * 1024, SSD_PART}, /* rvt_chip_prod     1024KB p42 */
    {PART_RVT_CUST,           1030 * 1024,     1 * 1024, SSD_PART}, /* rvt_cust          1024KB p43 */
    {PART_RVT_SYS_PROD,       1031 * 1024,     1 * 1024, SSD_PART}, /* rvt_sys_prod      1024KB p44 */
    {PART_UPDATER_RVT_A,      1032 * 1024,     2 * 1024, SSD_PART}, /* updater_rvt_a        2MB p45 */
    {PART_UPDATER_BAK_RVT_A,  1034 * 1024,     2 * 1024, SSD_PART}, /* updater_bak_rvt_a    2MB p46 */
    {PART_RVT,                1036 * 1024,     4 * 1024, SSD_PART}, /* rvt                  4MB p47 */
    {PART_SEPLAT,             1040 * 1024,     4 * 1024, SSD_PART}, /* seplat               4MB p48 */
    {PART_KPATCH,             1044 * 1024,     4 * 1024, SSD_PART}, /* kpatch               4MB p49 */
    {PART_PATCH,              1048 * 1024,    32 * 1024, SSD_PART}, /* patch               32MB p50 */
    {PART_MODULE_UPDATE,      1080 * 1024,          512, SSD_PART}, /* module_update      512KB p57 */
    {PART_EXT_RVT,           (1080 * 1024 + 512),   2 * 1024, SSD_PART}, /* ext_rvt         2MB p58 */
    {PART_FW_DDR_LPCTRL_B,   (1082 * 1024 + 512),  128, SSD_PART}, /* fw_ddr_lpctrl_b     128KB p33 */
    {PART_FW_DTB_B,          (1082 * 1024 + 640),  516, SSD_PART}, /* fw_dtb_b            516KB p34 */
    {PART_DACC_B,            (1083 * 1024 + 132),  128, SSD_PART}, /* dacc_b              128KB p35 */
    {PART_TRUSTFIRMWARE_B,   (1083 * 1024 + 260),  512, SSD_PART}, /* trustfirmware_b     512KB p36 */
    {PART_HHEE_B,            (1083 * 1024 + 772),  200, SSD_PART}, /* hhee_b              200KB p37 */
    {PART_RESERVED1_B,       (1083 * 1024 + 972),  104, SSD_PART}, /* reserved1_b         104KB p38 */
    {PART_FASTBOOT_B,        (1084 * 1024 + 52),   6 * 1024, SSD_PART}, /* fastboot_b       6MB p39 */
    {PART_FW_LPM3_B,         (1090 * 1024 + 52),  512, SSD_PART}, /* fw_lpm3_b           512KB p41 */
    {PART_RESERVED3_B,       (1090 * 1024 + 564),   828, SSD_PART}, /* reserved3_b         316KB p42 */
    {PART_HDMI_B,            (1091 * 1024 + 368),   80, SSD_PART}, /* hdmi_b               80KB p43 */
    {PART_THEE_B,            (1091 * 1024 + 448),  2 * 1024, SSD_PART}, /* thee_b           2MB p44 */
    {PART_TZSP_B,            (1093 * 1024 + 448),  2 * 1024, SSD_PART}, /* tzsp_b           2MB p45 */
    {PART_TEEOS_B,           (1095 * 1024 + 448),  5 * 1024, SSD_PART}, /* teeos_b          5MB p46 */
    {PART_MSPC_CODE_B,       (1100 * 1024 + 448),   216, SSD_PART}, /* mspc_code_b        216KB p47 */
    {PART_MSPC_IMG_B,        (1100 * 1024 + 664),   256, SSD_PART}, /* mspc_img_b         256KB p48 */
    {PART_RESERVED4_B,       (1100 * 1024 + 920),  (20 * 1024 + 616), SSD_PART}, /* reserved4_b 20 * 1024 + 616KB p49 */
    {PART_CONN_CALIDATA_B_BACK, (1121 * 1024 + 512),    1 * 1024, SSD_PART}, /* conn_calidata_b_back      1024KB p50 */
    {PART_RESERVED5_B,       (1122 * 1024 + 512),   19 * 1024, SSD_PART}, /* reserved5_b              19MB p57 */
    {PART_METADATA_B_BACK,   (1141 * 1024 + 512),   16 * 1024, SSD_PART}, /* metadata_b_back          16MB p58 */
    {PART_RESERVED6_B,       (1157 * 1024 + 512),    4 * 1024, SSD_PART}, /* reserved6_b               4MB p33 */
    {PART_NPU_B_BACK,        (1161 * 1024 + 512),    8 * 1024, SSD_PART}, /* npu_b_back                8MB p34 */
    {PART_IVP_B_BACK,        (1169 * 1024 + 512),    2 * 1024, SSD_PART}, /* ivp_b_back                2MB p35 */
    {PART_VENC_B_BACK,       (1171 * 1024 + 512),   512, SSD_PART}, /* venc_b_back                   512KB p36 */
    {PART_HISEE_IMG_B_BACK,          1172 * 1024,    4 * 1024, SSD_PART}, /* hisee_img_b_back          4MB p37 */
    {PART_ISP_BOOT_B_BACK,           1176 * 1024,    2 * 1024, SSD_PART}, /* isp_boot_b_back           2MB p38 */
    {PART_ISP_FIRMWARE_B_BACK,       1178 * 1024,   14 * 1024, SSD_PART}, /* isp_firmware_b_back      14MB p39 */
    {PART_FW_HIFI_B_BACK,            1192 * 1024,   12 * 1024, SSD_PART}, /* fw_hifi_b_back           12MB p40 */
    {PART_SENSORHUB_B_BACK,          1204 * 1024,   13 * 1024, SSD_PART}, /* sensorhub_b_back         13MB p41 */
    {PART_SENSORHUB_LOG_DIC_B_BACK,  1217 * 1024,    3 * 1024, SSD_PART}, /* sensorhub_log_dic_b_back  3MB p42 */
    {PART_RESERVED7_B,               1220 * 1024,   23 * 1024, SSD_PART}, /* reserved7_b              23MB p43 */
    {PART_UPDATER_RAMDISK_B,         1243 * 1024,   32 * 1024, SSD_PART}, /* updater_ramdisk_b        32MB p44 */
    {PART_UPDATER_VENDOR_B,          1275 * 1024,   24 * 1024, SSD_PART}, /* updater_vendor_b         24MB p45 */
    {PART_BOOT_B_BACK,               1299 * 1024,   51 * 1024, SSD_PART}, /* boot_b_back              51MB p46 */
    {PART_UPDATER_BOOT_B,            1350 * 1024,   52 * 1024, SSD_PART}, /* updater_boot_b           52MB p47 */
    {PART_UPDATER_BOOT_BAK_B,        1402 * 1024,   52 * 1024, SSD_PART}, /* updater_boot_bak_b       52MB p48 */
    {PART_UPDATER_RAMDISK_BAK_B,     1454 * 1024,   32 * 1024, SSD_PART}, /* updater_ramdisk_bak_b    32MB p49 */
    {PART_UPDATER_VENDOR_BAK_B,      1486 * 1024,   24 * 1024, SSD_PART}, /* updater_vendor_bak_b     24MB p50 */
    {PART_ENG_SYSTEM_B_BACK,         1510 * 1024,   20 * 1024, SSD_PART}, /* eng_system_b_back        20MB p57 */
    {PART_ENG_CHIPSET_B_BACK,        1530 * 1024,   20 * 1024, SSD_PART}, /* eng_chipset_b_back       20MB p58 */
    {PART_DTBO_B_BACK,               1550 * 1024,   14 * 1024, SSD_PART}, /* dtbo_b_back              14MB p42 */
    {PART_RAMDISK_B_BACK,            1564 * 1024,    4 * 1024, SSD_PART}, /* ramdisk_b_back            4MB p43 */
    {PART_RVT_SYSTEM_B_BACK,         1568 * 1024,    1 * 1024, SSD_PART}, /* rvt_system_b_back      1024KB p44 */
    {PART_RVT_VENDOR_B_BACK,         1569 * 1024,    1 * 1024, SSD_PART}, /* rvt_vendor_b_back      1024KB p45 */
    {PART_RVT_CHIP_PROD_B_BACK,      1570 * 1024,    1 * 1024, SSD_PART}, /* rvt_chip_prod_b_back   1024KB p46 */
    {PART_RVT_CUST_B_BACK,           1571 * 1024,    1 * 1024, SSD_PART}, /* rvt_cust_b_back        1024KB p47 */
    {PART_RVT_SYS_PROD_B_BACK,       1572 * 1024,    1 * 1024, SSD_PART}, /* rvt_sys_prod_b_back    1024KB p48 */
    {PART_UPDATER_RVT_B,             1573 * 1024,    2 * 1024, SSD_PART}, /* updater_rvt_b             2MB p49 */
    {PART_UPDATER_BAK_RVT_B,         1575 * 1024,    2 * 1024, SSD_PART}, /* updater_bak_rvt_b         2MB p50 */
    {PART_RVT_B_BACK,                1577 * 1024,    4 * 1024, SSD_PART}, /* rvt_b_back                4MB p50 */
    {PART_SEPLAT_B_BACK,             1581 * 1024,    4 * 1024, SSD_PART}, /* seplat_b_back             4MB p57 */
    {PART_KPATCH_B_BACK,             1585 * 1024,    4 * 1024, SSD_PART}, /* kpatch_b_back             4MB p58 */
    {PART_PATCH_B_BACK,              1589 * 1024,   32 * 1024, SSD_PART}, /* patch_b_back             32MB p50 */
    {PART_EXT_RVT_B_BACK,            1621 * 1024,    2 * 1024, SSD_PART}, /* ext_rvt_b_back            2MB p57 */
    {PART_RESERVED8,                 1623 * 1024,  173 * 1024, SSD_PART}, /* reserved8               173MB p58 */
    {PART_CUST,                      1796 * 1024,   88 * 1024, SSD_PART}, /* cust                     88MB p59 */
    {PART_CHIP_PROD,                 1884 * 1024,  616 * 1024, SSD_PART}, /* chip_prod               616MB p60 */
    {PART_VENDOR,                    2500 * 1024,  920 * 1024, SSD_PART}, /* vendor                  920MB p61 */
    {PART_SYS_PROD,                  3420 * 1024, 9766 * 1024, SSD_PART}, /* sys_prod               9766MB p62 */
    {PART_SYSTEM,                   13186 * 1024, 6860 * 1024, SSD_PART}, /* system                 6860MB p63 */
    {PART_HYPERHOLD,                20046 * 1024,    4 * 1024, SSD_PART}, /* hyperhold                 4MB p64 */
    {PART_RESERVED9,                20050 * 1024,  300 * 1024, SSD_PART}, /* reserved9               300MB p65 */
#endif
    {PART_VERSION,           20350 * 1024,   576 * 1024, SSD_PART}, /* version            576MB p61 */
    {PART_PRELOAD,           20926 * 1024,  1400 * 1024, SSD_PART}, /* preload           1400MB p62 */
    {PART_AI_MODELS,         22326 * 1024,     4 * 1024, SSD_PART}, /* ai_models            4MB p63 */
#if defined(CONFIG_FACTORY_MODE)
    {PART_HIBENCH1_LOG,      22330 * 1024,    20 * 1024, SSD_PART}, /* hibench1_log        20MB p61 */
    {PART_HIBENCH_DATA,      22350 * 1024,   512 * 1024, SSD_PART}, /* hibench_data       512MB p62 */
    {PART_HIBENCH_LPM3,      22862 * 1024,     2 * 1024, SSD_PART}, /* hibench_lpm3         2MB p63 */
    {PART_FLASH_AGEING,      22864 * 1024,   1024 * 1024, SSD_PART}, /* flash_ageing       1024MB p64 */
    {PART_RESERVED10,         23888 * 1024,   33562 * 1024, SSD_PART}, /* reserved10       33562MB p65 */
    {PART_USERDATA,          57450 * 1024,(16UL) * 1024 * 1024, SSD_PART}, /* userdata        6G p66 */
#else
    {PART_USERDATA,          22330 * 1024,(16UL) * 1024 * 1024, SSD_PART}, /* userdata        6G p64 */
#endif
    {"0", 0, 0, 0},
};
 
#endif