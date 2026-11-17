#ifndef _PISCES_PLAT_PARTITION_OHOS_TV_H_
#define _PISCES_PLAT_PARTITION_OHOS_TV_H_
 
#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"
 
static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};
 
static const struct partition partition_table_ufs[] = {
    {PART_XLOADER_A,                       0,     4 * 1024, UFS_PART_0},
    {PART_XLOADER_B,                       0,     4 * 1024, UFS_PART_1},
	{PART_PTABLE_LU2,                      0,          512, UFS_PART_2}, /* ptable_lu2         512KB p0 */
    {PART_FW_CPU_LPCTRL_A,             512,          256, UFS_PART_2}, /* fw_cpu_lpctrl_a    256KB p1 */
    {PART_FW_GPU_LPCTRL_A,             768,          128, UFS_PART_2}, /* fw_gpu_lpctrl_a    128KB p2 */
    {PART_FW_DDR_LPCTRL_A,             896,          256, UFS_PART_2}, /* fw_ddr_lpctrl_a    256KB p3 */
    {PART_DDR_XPU_BOOT0_A,   (1 * 1024 + 128),          256, UFS_PART_2}, /* ddr_xpu_boot0_a    256KB p4 */
    {PART_DDR_XPU_BOOT1_A,   (1 * 1024 + 384),          256, UFS_PART_2}, /* ddr_xpu_boot1_a    256KB p5 */
    {PART_UCE_A,             (1 * 1024 + 640),          160, UFS_PART_2}, /* uce_a              160KB p6 */
    {PART_RESERVED0,         (1 * 1024 + 800),(2 * 1024+224), UFS_PART_2}, /* reserved0         2272KB p7 */
    {PART_LOWPOWER_PARA_A,        4 * 1024,     1 * 1024, UFS_PART_2}, /* lowpower_para_a   1024KB p8 */
    {PART_SEPLAT_A,               5 * 1024,     4 * 1024, UFS_PART_2}, /* seplat_a             4MB p9 */
    {PART_BL2_A,                  9 * 1024,     4 * 1024, UFS_PART_2}, /* bl2_a                4MB p10 */
    {PART_FW_LPM3_A,             13 * 1024,          512, UFS_PART_2}, /* fw_lpm3_a          512KB p11 */
    {PART_DACC_A,            (13 * 1024 + 512),          512, UFS_PART_2}, /* dacc_a             512KB p12 */
    {PART_NPU_A,                 14 * 1024,     8 * 1024, UFS_PART_2}, /* npu_a                8MB p13 */
    {PART_HISEE_IMG_A,           22 * 1024,     4 * 1024, UFS_PART_2}, /* hisee_img_a          4MB p14 */
    {PART_HHEE_A,                26 * 1024,     4 * 1024, UFS_PART_2}, /* hhee_a               4MB p15 */
    {PART_FASTBOOT_A,            30 * 1024,    12 * 1024, UFS_PART_2}, /* fastboot_a          12MB p16 */
    {PART_ISP_FIRMWARE_A,        42 * 1024,    14 * 1024, UFS_PART_2}, /* isp_firmware_a      14MB p17 */
    {PART_FW_HIFI_A,             56 * 1024,    12 * 1024, UFS_PART_2}, /* fw_hifi_a           12MB p18 */
    {PART_TEEOS_A,               68 * 1024,     8 * 1024, UFS_PART_2}, /* teeos_a              8MB p19 */
    {PART_SENSORHUB_A,           76 * 1024,    13 * 1024, UFS_PART_2}, /* sensorhub_a         13MB p20 */
    {PART_SENSORHUB_LOG_DIC_A,    89 * 1024,     3 * 1024, UFS_PART_2}, /* sensorhub_log_dic_a   3MB p21 */
    {PART_FW_UFSDEV_A,           92 * 1024,     4 * 1024, UFS_PART_2}, /* fw_ufsdev_a          4MB p22 */
    {PART_FW_DFA_A,              96 * 1024,     1 * 1024, UFS_PART_2}, /* fw_dfa_a          1024KB p23 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_UPDATER_RAMDISK_A,     97 * 1024,    64 * 1024, UFS_PART_2}, /* updater_ramdisk_a   64MB p24 */
    {PART_UPDATER_VENDOR_A,     161 * 1024,    35 * 1024, UFS_PART_2}, /* updater_vendor_a    35MB p25 */
    {PART_UPDATER_BOOT_A,       196 * 1024,    66 * 1024, UFS_PART_2}, /* updater_boot_a      66MB p26 */
    {PART_UPDATER_BOOT_BAK_A,   262 * 1024,    66 * 1024, UFS_PART_2}, /* updater_boot_bak_a  66MB p27 */	
    {PART_RESERVED,             328 * 1024,     9 * 1024, UFS_PART_2}, /* reserved             9MB p28 */
    {PART_THEE_A,               337 * 1024,     4 * 1024, UFS_PART_2}, /* thee_a               4MB p29 */
    {PART_TZSP_A,               341 * 1024,    12 * 1024, UFS_PART_2}, /* tzsp_a              12MB p30 */
	{PART_UPDATER_RAMDISK_BAK_A,   353 * 1024,    64 * 1024, UFS_PART_2}, /* updater_ramdisk_bak_a  64MB p31 */
    {PART_UPDATER_VENDOR_BAK_A,   417 * 1024,    35 * 1024, UFS_PART_2}, /* updater_vendor_bak_a  35MB p32 */
    {PART_FW_DTB_A,             452 * 1024,    20 * 1024, UFS_PART_2}, /* fw_dtb_a            20MB p33 */
    {PART_DTBO_A,               472 * 1024,    20 * 1024, UFS_PART_2}, /* dtbo_a              20MB p34 */
    {PART_TRUSTFIRMWARE_A,      492 * 1024,     2 * 1024, UFS_PART_2}, /* trustfirmware_a      2MB p35 */
	{PART_UPDATER_RVT_A,        494 * 1024,     2 * 1024, UFS_PART_2}, /* updater_rvt_a        2MB p36 */
    {PART_UPDATER_BAK_RVT_A,    496 * 1024,     2 * 1024, UFS_PART_2}, /* updater_bak_rvt_a    2MB p37 */
#else
    {PART_UPDATER_RAMDISK_A,     97 * 1024,    32 * 1024, UFS_PART_2}, /* updater_ramdisk_a   32MB p24 */
    {PART_UPDATER_VENDOR_A,     129 * 1024,    28 * 1024, UFS_PART_2}, /* updater_vendor_a    28MB p25 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_UPDATER_BOOT_A,       157 * 1024,    64 * 1024, UFS_PART_2}, /* updater_boot_a      64MB p26 */
    {PART_UPDATER_BOOT_BAK_A,   221 * 1024,    64 * 1024, UFS_PART_2}, /* updater_boot_bak_a  64MB p27 */
    {PART_RESERVED,             285 * 1024,    35 * 1024, UFS_PART_2}, /* reserved            35MB p28 */
#else
    {PART_UPDATER_BOOT_A,       157 * 1024,    66 * 1024, UFS_PART_2}, /* updater_boot_a      66MB p26 */
    {PART_UPDATER_BOOT_BAK_A,   223 * 1024,    66 * 1024, UFS_PART_2}, /* updater_boot_bak_a  66MB p27 */
    {PART_RESERVED,             289 * 1024,    31 * 1024, UFS_PART_2}, /* reserved            31MB p28 */ 
#endif
    {PART_THEE_A,               320 * 1024,     4 * 1024, UFS_PART_2}, /* thee_a               4MB p29 */
    {PART_TZSP_A,               324 * 1024,    12 * 1024, UFS_PART_2}, /* tzsp_a              12MB p30 */
    {PART_UPDATER_RAMDISK_BAK_A,   336 * 1024,    32 * 1024, UFS_PART_2}, /* updater_ramdisk_bak_a  32MB p31 */
    {PART_UPDATER_VENDOR_BAK_A,   368 * 1024,    28 * 1024, UFS_PART_2}, /* updater_vendor_bak_a  28MB p32 */
    {PART_FW_DTB_A,             396 * 1024,    20 * 1024, UFS_PART_2}, /* fw_dtb_a            20MB p33 */
    {PART_DTBO_A,               416 * 1024,    20 * 1024, UFS_PART_2}, /* dtbo_a              20MB p34 */
    {PART_TRUSTFIRMWARE_A,      436 * 1024,     2 * 1024, UFS_PART_2}, /* trustfirmware_a      2MB p35 */
    {PART_UPDATER_RVT_A,        438 * 1024,     2 * 1024, UFS_PART_2}, /* updater_rvt_a        2MB p36 */
    {PART_UPDATER_BAK_RVT_A,    440 * 1024,     2 * 1024, UFS_PART_2}, /* updater_bak_rvt_a    2MB p37 */
#endif
	{PART_PTABLE_LU3,                      0,          512, UFS_PART_3}, /* ptable_lu3            512KB p0 */
    {PART_FW_CPU_LPCTRL_B,             512,          256, UFS_PART_3}, /* fw_cpu_lpctrl_b    256KB p1 */
    {PART_FW_GPU_LPCTRL_B,             768,          128, UFS_PART_3}, /* fw_gpu_lpctrl_b    128KB p2 */
    {PART_FW_DDR_LPCTRL_B,             896,          256, UFS_PART_3}, /* fw_ddr_lpctrl_b    256KB p3 */
    {PART_DDR_XPU_BOOT0_B,   (1 * 1024 + 128),          256, UFS_PART_3}, /* ddr_xpu_boot0_b    256KB p4 */
    {PART_DDR_XPU_BOOT1_B,   (1 * 1024 + 384),          256, UFS_PART_3}, /* ddr_xpu_boot1_b    256KB p5 */
    {PART_UCE_B,             (1 * 1024 + 640),          160, UFS_PART_3}, /* uce_b              160KB p6 */
    {PART_RESERVED,          (1 * 1024 + 800),(2 * 1024+224), UFS_PART_3}, /* reserved          2272KB p7 */
	{PART_LOWPOWER_PARA_B,        4 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para_b   1024KB p8 */
    {PART_SEPLAT_B,               5 * 1024,     4 * 1024, UFS_PART_3}, /* seplat_b             4MB p9 */
    {PART_BL2_B,                  9 * 1024,     4 * 1024, UFS_PART_3}, /* bl2_b                4MB p10 */
    {PART_FW_LPM3_B,             13 * 1024,          512, UFS_PART_3}, /* fw_lpm3_b          512KB p11 */
    {PART_DACC_B,            (13 * 1024 + 512),          512, UFS_PART_3}, /* dacc_b             512KB p12 */
    {PART_NPU_B,                 14 * 1024,     8 * 1024, UFS_PART_3}, /* npu_b                8MB p13 */
    {PART_HISEE_IMG_B,           22 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img_b          4MB p14 */
    {PART_HHEE_B,                26 * 1024,     4 * 1024, UFS_PART_3}, /* hhee_b               4MB p15 */
    {PART_FASTBOOT_B,            30 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot_b          12MB p16 */
    {PART_ISP_FIRMWARE_B,        42 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware_b      14MB p17 */
    {PART_FW_HIFI_B,             56 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi_b           12MB p18 */
    {PART_TEEOS_B,               68 * 1024,     8 * 1024, UFS_PART_3}, /* teeos_b              8MB p19 */
    {PART_SENSORHUB_B,           76 * 1024,    13 * 1024, UFS_PART_3}, /* sensorhub_b         13MB p20 */
    {PART_SENSORHUB_LOG_DIC_B,    89 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic_b   3MB p21 */
    {PART_FW_UFSDEV_B,           92 * 1024,     4 * 1024, UFS_PART_3}, /* fw_ufsdev_b          4MB p22 */
    {PART_FW_DFA_B,              96 * 1024,     1 * 1024, UFS_PART_3}, /* fw_dfa_b          1024KB p23 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_UPDATER_RAMDISK_B,     97 * 1024,    64 * 1024, UFS_PART_3}, /* updater_ramdisk_b   64MB p24 */
    {PART_UPDATER_VENDOR_B,     161 * 1024,    35 * 1024, UFS_PART_3}, /* updater_vendor_b    35MB p25 */
    {PART_UPDATER_BOOT_B,       196 * 1024,    66 * 1024, UFS_PART_3}, /* updater_boot_b      66MB p26 */
    {PART_UPDATER_BOOT_BAK_B,   262 * 1024,    66 * 1024, UFS_PART_3}, /* updater_boot_bak_b  66MB p27 */	
    {PART_RESERVED,             328 * 1024,     9 * 1024, UFS_PART_3}, /* reserved             9MB p28 */
    {PART_THEE_B,               337 * 1024,     4 * 1024, UFS_PART_3}, /* thee_b               4MB p29 */
    {PART_TZSP_B,               341 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp_b              12MB p30 */
	{PART_UPDATER_RAMDISK_BAK_B,   353 * 1024,    64 * 1024, UFS_PART_3}, /* updater_ramdisk_bak_b  64MB p31 */
    {PART_UPDATER_VENDOR_BAK_B,   417 * 1024,    35 * 1024, UFS_PART_3}, /* updater_vendor_bak_b  35MB p32 */
    {PART_FW_DTB_B,             452 * 1024,    20 * 1024, UFS_PART_3}, /* fw_dtb_b            20MB p33 */
    {PART_DTBO_B,               472 * 1024,    20 * 1024, UFS_PART_3}, /* dtbo_b              20MB p34 */
    {PART_TRUSTFIRMWARE_B,      492 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware_b      2MB p35 */
	{PART_UPDATER_RVT_B,        494 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt_b        2MB p36 */
    {PART_UPDATER_BAK_RVT_B,    496 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt_b    2MB p37 */
#else
    {PART_UPDATER_RAMDISK_B,     97 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_b   32MB p24 */
    {PART_UPDATER_VENDOR_B,     129 * 1024,    28 * 1024, UFS_PART_3}, /* updater_vendor_b    28MB p25 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_UPDATER_BOOT_B,       157 * 1024,    64 * 1024, UFS_PART_3}, /* updater_boot_b      64MB p26 */
    {PART_UPDATER_BOOT_BAK_B,   221 * 1024,    64 * 1024, UFS_PART_3}, /* updater_boot_bak_b  64MB p27 */
    {PART_RESERVED,             285 * 1024,    35 * 1024, UFS_PART_3}, /* reserved            35MB p28 */
#else
    {PART_UPDATER_BOOT_B,       157 * 1024,    66 * 1024, UFS_PART_3}, /* updater_boot_b      66MB p26 */
    {PART_UPDATER_BOOT_BAK_B,   223 * 1024,    66 * 1024, UFS_PART_3}, /* updater_boot_bak_b  66MB p27 */
    {PART_RESERVED,             289 * 1024,    31 * 1024, UFS_PART_3}, /* reserved            31MB p28 */ 
#endif
    {PART_THEE_B,               320 * 1024,     4 * 1024, UFS_PART_3}, /* thee_b               4MB p29 */
    {PART_TZSP_B,               324 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp_b              12MB p30 */
    {PART_UPDATER_RAMDISK_BAK_B,   336 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak_b  32MB p31 */
    {PART_UPDATER_VENDOR_BAK_B,   368 * 1024,    28 * 1024, UFS_PART_3}, /* updater_vendor_bak_b  28MB p32 */
    {PART_FW_DTB_B,             396 * 1024,    20 * 1024, UFS_PART_3}, /* fw_dtb_b            20MB p33 */
    {PART_DTBO_B,               416 * 1024,    20 * 1024, UFS_PART_3}, /* dtbo_b              20MB p34 */
    {PART_TRUSTFIRMWARE_B,      436 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware_b      2MB p35 */
    {PART_UPDATER_RVT_B,        438 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt_b        2MB p36 */
    {PART_UPDATER_BAK_RVT_B,    440 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt_b    2MB p37 */
#endif
	{PART_PTABLE_LU4,                    0,          512, UFS_PART_4}, /* ptable_lu4            512KB p0 */
    {PART_FRP,                          512,         512, UFS_PART_4}, /* frp                512KB p1 */
    {PART_PERSIST,                    1024,     6 * 1024, UFS_PART_4}, /* persist              6MB p2 */
    {PART_RESERVED1,              7 * 1024,         1024, UFS_PART_4}, /* reserved1         1024KB p3 */  
	{PART_VRL,                    8 * 1024,          512, UFS_PART_4}, /* vrl                512KB p4 */
    {PART_VRL_BACKUP,        (8 * 1024 + 512),          512, UFS_PART_4}, /* vrl_backup         512KB p5 */
    {PART_MODEM_SECURE,            9 * 1024,    9 * 1024, UFS_PART_4}, /* modem_secure         9MB p6 */
    {PART_BOOT_CTRL,             18 * 1024,     1 * 1024, UFS_PART_4}, /* boot_ctrl         1024KB p7 */
    {PART_NVME,                  19 * 1024,     4 * 1024, UFS_PART_4}, /* nvme                 4MB p8 */
    {PART_CONN_CALIDATA,         23 * 1024,     1 * 1024, UFS_PART_4}, /* conn_calidata     1024KB p9 */
    {PART_CTF,                   24 * 1024,     1 * 1024, UFS_PART_4}, /* ctf               1024KB p10 */
    {PART_OEMINFO,               25 * 1024,    96 * 1024, UFS_PART_4}, /* oeminfo             96MB p11 */
    {PART_SECURE_STORAGE,       121 * 1024,    32 * 1024, UFS_PART_4}, /* secure_storage      32MB p12 */
    {PART_REMOTECTRONL_DATA,    153 * 1024,     4 * 1024, UFS_PART_4}, /* remotectronl_data    4MB p13 */
    {PART_MODEMNVM_FACTORY,     157 * 1024,    16 * 1024, UFS_PART_4}, /* modemnvm_factory    16MB p14 */
    {PART_MODEMNVM_BACKUP,      173 * 1024,    16 * 1024, UFS_PART_4}, /* modemnvm_backup     16MB p15 */
    {PART_MODEMNVM_IMG,         189 * 1024,    46 * 1024, UFS_PART_4}, /* modemnvm_img        46MB p16 */
    {PART_HISEE_ENCOS,          235 * 1024,     4 * 1024, UFS_PART_4}, /* hisee_encos          4MB p17 */
    {PART_VERITYKEY,            239 * 1024,     1 * 1024, UFS_PART_4}, /* veritykey         1024KB p18 */
    {PART_DDR_PARA,             240 * 1024,     1 * 1024, UFS_PART_4}, /* ddr_para          1024KB p19 */
    {PART_BATT_TP_PARA,         241 * 1024,     1 * 1024, UFS_PART_4}, /* batt_tp_para      1024KB p20 */
    {PART_PANEL_CALIBRATION,    242 * 1024,   100 * 1024, UFS_PART_4}, /* panel_calibration  100MB p21 */
    {PART_RESERVED2,            342 * 1024,    21 * 1024, UFS_PART_4}, /* reserved2           21MB p22 */
    {PART_LOG,                  363 * 1024,    80 * 1024, UFS_PART_4}, /* log                 80MB p23 */
    {PART_BOOTFAIL_INFO,        443 * 1024,     2 * 1024, UFS_PART_4}, /* bootfail_info        2MB p24 */
    {PART_MISC,                 445 * 1024,     2 * 1024, UFS_PART_4}, /* misc                 2MB p25 */
    {PART_DFX,                  447 * 1024,    16 * 1024, UFS_PART_4}, /* dfx                 16MB p26 */
    {PART_RRECORD,              463 * 1024,    16 * 1024, UFS_PART_4}, /* rrecord             16MB p27 */
    {PART_CACHE,                479 * 1024,   104 * 1024, UFS_PART_4}, /* cache              104MB p28 */
    {PART_METADATA,             583 * 1024,    16 * 1024, UFS_PART_4}, /* metadata            16MB p29 */
    {PART_TOC,                  599 * 1024,     1 * 1024, UFS_PART_4}, /* toc               1024KB p30 */
    {PART_DDR_XPU_BOOT2,        600 * 1024,          256, UFS_PART_4}, /* ddr_xpu_boot2      256KB p31 */
    {PART_RESERVED3,         (600 * 1024 + 256),(6 * 1024+768), UFS_PART_4}, /* reserved3         6912KB p32 */
    {PART_IVP,                  607 * 1024,     2 * 1024, UFS_PART_4}, /* ivp                  2MB p33 */
    {PART_VENC,                 609 * 1024,          512, UFS_PART_4}, /* venc               512KB p34 */
	{PART_HISEE_FS,          (609 * 1024 + 512),     8 * 1024, UFS_PART_4}, /* hisee_fs             8MB p35 */
	{PART_VECTOR,            (617 * 1024 + 512),     4 * 1024, UFS_PART_4}, /* vector               4MB p36 */
    {PART_ISP_BOOT,          (621 * 1024 + 512),     2 * 1024, UFS_PART_4}, /* isp_boot             2MB p37 */
    {PART_HKRR,              (623 * 1024 + 512),    16 * 1024, UFS_PART_4}, /* hkrr                16MB p38 */
    {PART_RESERVED4,         (639 * 1024 + 512),14 * 1024+512, UFS_PART_4}, /* reserved4         14848KB p39 */
#ifdef CONFIG_ASAN_SUPPORT_ENABLE
    {PART_BOOT,                 654 * 1024,    46 * 1024, UFS_PART_4}, /* boot                46MB p40 */
    {PART_RESERVED,             700 * 1024,     9 * 1024, UFS_PART_4}, /* reserved             9MB p41 */
    {PART_ENG_SYSTEM,           709 * 1024,    12 * 1024, UFS_PART_4}, /* eng_system          12MB p42 */
    {PART_ENG_CHIPSET,          721 * 1024,    20 * 1024, UFS_PART_4}, /* eng_chipset         20MB p43 */
    {PART_MODEM_FW,             741 * 1024,   124 * 1024, UFS_PART_4}, /* modem_fw           124MB p44 */
    {PART_MODEM_VENDOR,         865 * 1024,    30 * 1024, UFS_PART_4}, /* modem_vendor        30MB p45 */
    {PART_MODEM_PATCH_NV,       895 * 1024,     4 * 1024, UFS_PART_4}, /* modem_patch_nv       4MB p46 */
    {PART_MODEM_DRIVER,         899 * 1024,    20 * 1024, UFS_PART_4}, /* modem_driver        20MB p47 */
    {PART_MODEMNVM_UPDATE,      919 * 1024,    16 * 1024, UFS_PART_4}, /* modemnvm_update     16MB p48 */
    {PART_MODEMNVM_CUST,        935 * 1024,    16 * 1024, UFS_PART_4}, /* modemnvm_cust       16MB p49 */
    {PART_RAMDISK,              951 * 1024,     5 * 1024, UFS_PART_4}, /* ramdisk              5MB p50 */
    {PART_RVT_SYSTEM,           956 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_system        1024KB p51 */
    {PART_RVT_VENDOR,           957 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_vendor        1024KB p52 */
    {PART_RVT_CHIP_PROD,        958 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_chip_prod     1024KB p53 */
    {PART_RVT_CUST,             959 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_cust          1024KB p54 */
    {PART_RVT_SYS_PROD,         960 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_sys_prod      1024KB p55 */
    {PART_RVT,                  961 * 1024,     4 * 1024, UFS_PART_4}, /* rvt                  4MB p56 */
    {PART_KPATCH,               965 * 1024,     4 * 1024, UFS_PART_4}, /* kpatch               4MB p57 */
    {PART_PATCH,                969 * 1024,    32 * 1024, UFS_PART_4}, /* patch               32MB p58 */
    {PART_CUST,                1001 * 1024,    88 * 1024, UFS_PART_4}, /* cust                88MB p59 */
    {PART_CHIP_PROD,           1089 * 1024,  3018 * 1024, UFS_PART_4}, /* chip_prod         3018MB p60 */
    {PART_VENDOR,              4107 * 1024,  3284 * 1024, UFS_PART_4}, /* vendor            3284MB p61 */
    {PART_SYS_PROD,            7391 * 1024,  8812 * 1024, UFS_PART_4}, /* sys_prod          8812MB p62 */
    {PART_SYSTEM,             16203 * 1024,  7168 * 1024, UFS_PART_4}, /* system            7168MB p63 */
    {PART_HYPERHOLD,          23371 * 1024,     4 * 1024, UFS_PART_4}, /* hyperhold            4MB p64 */
    {PART_RESERVED5,          23375 * 1024,   745 * 1024, UFS_PART_4}, /* reserved5          745MB p65 */
    {PART_VERSION,            24120 * 1024,   576 * 1024, UFS_PART_4}, /* version            576MB p66 */
    {PART_PRELOAD,            24696 * 1024,  1400 * 1024, UFS_PART_4}, /* preload           1400MB p67 */
    {PART_RESERVED9,          26096 * 1024,   824 * 1024, UFS_PART_4}, /* reserved9          824MB p68 */  
    {PART_USERDATA,           26920 * 1024,(12UL) * 1024 * 1024, UFS_PART_4}, /* userdata       2G p69 */
#else
    {PART_BOOT,                 654 * 1024,    46 * 1024, UFS_PART_4}, /* boot                46MB p40 */
    {PART_RESERVED,             700 * 1024,    34 * 1024, UFS_PART_4}, /* reserved            34MB p41 */    
    {PART_ENG_SYSTEM,           734 * 1024,    12 * 1024, UFS_PART_4}, /* eng_system          12MB p42 */
    {PART_ENG_CHIPSET,          746 * 1024,    20 * 1024, UFS_PART_4}, /* eng_chipset         20MB p43 */
    {PART_MODEM_FW,             766 * 1024,   124 * 1024, UFS_PART_4}, /* modem_fw           124MB p44 */
    {PART_MODEM_VENDOR,         890 * 1024,    10 * 1024, UFS_PART_4}, /* modem_vendor        10MB p45 */
    {PART_MODEM_PATCH_NV,       900 * 1024,     4 * 1024, UFS_PART_4}, /* modem_patch_nv       4MB p46 */
    {PART_MODEM_DRIVER,         904 * 1024,    20 * 1024, UFS_PART_4}, /* modem_driver        20MB p47 */
    {PART_MODEMNVM_UPDATE,      924 * 1024,    16 * 1024, UFS_PART_4}, /* modemnvm_update     16MB p48 */
    {PART_MODEMNVM_CUST,        940 * 1024,    16 * 1024, UFS_PART_4}, /* modemnvm_cust       16MB p49 */
    {PART_RAMDISK,              956 * 1024,     4 * 1024, UFS_PART_4}, /* ramdisk              4MB p50 */
    {PART_RVT_SYSTEM,           960 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_system        1024KB p51 */
    {PART_RVT_VENDOR,           961 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_vendor        1024KB p52 */
    {PART_RVT_CHIP_PROD,        962 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_chip_prod     1024KB p53 */
    {PART_RVT_CUST,             963 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_cust          1024KB p54 */
    {PART_RVT_SYS_PROD,         964 * 1024,     1 * 1024, UFS_PART_4}, /* rvt_sys_prod      1024KB p55 */
    {PART_RVT,                  965 * 1024,     4 * 1024, UFS_PART_4}, /* rvt                  4MB p56 */
    {PART_KPATCH,               969 * 1024,     4 * 1024, UFS_PART_4}, /* kpatch               4MB p57 */
    {PART_PATCH,                973 * 1024,   128 * 1024, UFS_PART_4}, /* patch              128MB p58 */
#if defined(CONFIG_FACTORY_MODE)
    {PART_RESERVED5,           1101 * 1024,(139 * 1024+512), UFS_PART_4}, /* reserved5         138752KB p59 */
    {PART_MODULE_UPDATE,     (1240 * 1024 + 512),          512, UFS_PART_4}, /* module_update      512KB p60 */
    {PART_EXT_RVT,             1241 * 1024,     2 * 1024, UFS_PART_4}, /* ext_rvt              2MB p61 */
    {PART_HIBENCH_IMG,         1243 * 1024,   128 * 1024, UFS_PART_4}, /* hibench_img        128MB p62 */
    {PART_HIBENCH_LOG,         1371 * 1024,    32 * 1024, UFS_PART_4}, /* hibench_log         32MB p63 */
    {PART_HIBENCH_DATA,        1403 * 1024,  1000 * 1024, UFS_PART_4}, /* hibench_data      1000MB p64 */
    {PART_FLASH_AGEING,        2403 * 1024,   512 * 1024, UFS_PART_4}, /* flash_ageing       512MB p65 */
    {PART_HIBENCH_LPM3,        2915 * 1024,     2 * 1024, UFS_PART_4}, /* hibench_lpm3         2MB p66 */
    {PART_XLOADER_HITEST,      2917 * 1024,     2 * 1024, UFS_PART_4}, /* xloader_hitest       2MB p67 */
    {PART_CUST,                2919 * 1024,   128 * 1024, UFS_PART_4}, /* cust               128MB p68 */
    {PART_CHIP_PROD,           3047 * 1024,  3018 * 1024, UFS_PART_4}, /* chip_prod         3018MB p69 */
    {PART_VENDOR,              6065 * 1024,  1132 * 1024, UFS_PART_4}, /* vendor            1132MB p70 */
    {PART_SYS_PROD,            7197 * 1024,  8812 * 1024, UFS_PART_4}, /* sys_prod          8812MB p71 */
    {PART_SYSTEM,             16009 * 1024,  4948 * 1024, UFS_PART_4}, /* system            4948MB p72 */
    {PART_HYPERHOLD,          20957 * 1024,     4 * 1024, UFS_PART_4}, /* hyperhold            4MB p73 */
    {PART_VERSION,            20961 * 1024,   576 * 1024, UFS_PART_4}, /* version            576MB p74 */
    {PART_PRELOAD,            21537 * 1024,  1400 * 1024, UFS_PART_4}, /* preload           1400MB p75 */
    {PART_RESERVED6,          22937 * 1024, 27529 * 1024, UFS_PART_4}, /* reserved6         27529MB p76 */
    {PART_USERDATA,           50466 * 1024,(16UL) * 1024 * 1024, UFS_PART_4}, /* userdata       6G p77 */
#else
    {PART_CUST,                1101 * 1024,   128 * 1024, UFS_PART_4}, /* cust               128MB p59 */
    {PART_CHIP_PROD,           1229 * 1024,  3018 * 1024, UFS_PART_4}, /* chip_prod         3018MB p60 */
    {PART_VENDOR,              4247 * 1024,  1132 * 1024, UFS_PART_4}, /* vendor            1132MB p61 */
    {PART_SYS_PROD,            5379 * 1024,  8812 * 1024, UFS_PART_4}, /* sys_prod          8812MB p62 */
    {PART_SYSTEM,             14191 * 1024,  4948 * 1024, UFS_PART_4}, /* system            4948MB p63 */
#if defined(CONFIG_PARTITION_ENG)
    {PART_HYPERHOLD,          19139 * 1024,     4 * 1024, UFS_PART_4}, /* hyperhold            4MB p64 */
    {PART_RESERVED5,          19143 * 1024,   140 * 1024, UFS_PART_4}, /* reserved5          136MB p65 */
    {PART_VERSION,            19283 * 1024,   576 * 1024, UFS_PART_4}, /* version            576MB p66 */
    {PART_PRELOAD,            19859 * 1024,  1400 * 1024, UFS_PART_4}, /* preload           1400MB p67 */
    {PART_FTTEST,             21259 * 1024,   192 * 1024, UFS_PART_4}, /* fttest             192MB p68 */
    {PART_DDRTEST,            21451 * 1024,    48 * 1024, UFS_PART_4}, /* ddrtest             48MB p69 */
    {PART_HITEST_GPU,         21499 * 1024,   512 * 1024, UFS_PART_4}, /* hitest_gpu         512MB p70 */
    {PART_HITEST_ASP_DHRYSTONE, 22011 * 1024,    20 * 1024, UFS_PART_4}, /* hitest_asp_dhrystone  20MB p71 */
    {PART_HITEST_ASP_TEST,    22031 * 1024,   300 * 1024, UFS_PART_4}, /* hitest_asp_test    300MB p72 */
    {PART_HITEST_SENSORHUB,   22331 * 1024,     6 * 1024, UFS_PART_4}, /* hitest_sensorhub     6MB p73 */
    {PART_HITEST_ISP,         22337 * 1024,    25 * 1024, UFS_PART_4}, /* hitest_isp          25MB p74 */
    {PART_HITEST_ISP_AVS,     22362 * 1024,    65 * 1024, UFS_PART_4}, /* hitest_isp_avs      65MB p75 */
    {PART_HITEST_NPU,         22427 * 1024,    80 * 1024, UFS_PART_4}, /* hitest_npu          80MB p76 */
    {PART_HITEST_DSS,         22507 * 1024,    18 * 1024, UFS_PART_4}, /* hitest_dss          18MB p77 */
    {PART_DSS_DISP_BUF,       22525 * 1024,   128 * 1024, UFS_PART_4}, /* dss_disp_buf       128MB p78 */
    {PART_HITEST_JPEGENC,     22653 * 1024,   200 * 1024, UFS_PART_4}, /* hitest_jpegenc     200MB p79 */
    {PART_HITEST_HIPP,        22853 * 1024,   100 * 1024, UFS_PART_4}, /* hitest_hipp        100MB p80 */
    {PART_HIBENCH_LPM3,       22953 * 1024,     2 * 1024, UFS_PART_4}, /* hibench_lpm3         2MB p81 */
    {PART_JPEG_DEC_TEST_SRC,  22955 * 1024,    20 * 1024, UFS_PART_4}, /* jpeg_dec_test_src   20MB p82 */
    {PART_JPEG_DEC_TEST_DEST, 22975 * 1024,    80 * 1024, UFS_PART_4}, /* jpeg_dec_test_dest  80MB p83 */
    {PART_VCODE_DATA,         23055 * 1024,   140 * 1024, UFS_PART_4}, /* vcode_data         140MB p84 */
    {PART_HITEST_FFRT,        23195 * 1024,    20 * 1024, UFS_PART_4}, /* hitest_ffrt         20MB p85 */
    {PART_VCODE_MAX_DATA,     23215 * 1024,   140 * 1024, UFS_PART_4}, /* vcode_max_data     140MB p86 */
    {PART_MODEM_TSP_TEST,     23355 * 1024,    36 * 1024, UFS_PART_4}, /* modem_tsp_test      36MB p87 */
    {PART_MODEM_VECTOR_CONFIG, 23391 * 1024,     4 * 1024, UFS_PART_4}, /* modem_vector_config   4MB p88 */
    {PART_MODEM_TSP_DT,       23395 * 1024,     1 * 1024, UFS_PART_4}, /* modem_tsp_dt      1024KB p89 */
    {PART_MODEM_L2DLE,        23396 * 1024,     4 * 1024, UFS_PART_4}, /* modem_l2dle          4MB p90 */
    {PART_MODEM_BBP_TEST,     23400 * 1024,   100 * 1024, UFS_PART_4}, /* modem_bbp_test     100MB p91 */
    {PART_MODEM_PSA_TEST,     23500 * 1024,    20 * 1024, UFS_PART_4}, /* modem_psa_test      20MB p92 */
    {PART_MODEM_PDE_TEST,     23520 * 1024,     5 * 1024, UFS_PART_4}, /* modem_pde_test       5MB p93 */
    {PART_XLOADER_HITEST,     23525 * 1024,     2 * 1024, UFS_PART_4}, /* xloader_hitest       2MB p94 */
    {PART_HITEST_OISP,        23527 * 1024,    25 * 1024, UFS_PART_4}, /* hitest_oisp         25MB p95 */
    {PART_RESERVED8,          23552 * 1024,     2 * 1024, UFS_PART_4}, /* reserved8            2MB p96 */       
    {PART_USERDATA,           23554 * 1024,(16UL) * 1024 * 1024, UFS_PART_4}, /* userdata       6G p97 */
#else // system in ccm is 5716,but now less 768
    {PART_AI_MODEL,           19139 * 1024,     2 * 1024, UFS_PART_4}, /* ai_model             2MB p64 */
    {PART_HYPERHOLD,          19141 * 1024,     2 * 1024, UFS_PART_4}, /* hyperhold            2MB p65 */
    {PART_RESERVED5,          19143 * 1024,   138 * 1024, UFS_PART_4}, /* reserved5          134MB p66 */	
	{PART_MODULE_UPDATE,      19281 * 1024,          512, UFS_PART_4}, /* module_update      512KB p67 */
    {PART_EXT_RVT,           (19281 * 1024 + 512),     2 * 1024, UFS_PART_4}, /* ext_rvt              2MB p68 */
    {PART_VERSION,           (19283 * 1024 + 512),   576 * 1024, UFS_PART_4}, /* version            576MB p69 */
    {PART_PRELOAD,           (19859 * 1024 + 512),  1400 * 1024, UFS_PART_4}, /* preload           1400MB p70 */
    {PART_SUB_PACKAGE_BAK,  (21259 * 1024 + 512),1816 * 1024+512, UFS_PART_4}, /* sub_package_bak 1860096KB p71 */
    {PART_USERDATA,           23076 * 1024,(16UL) * 1024 * 1024, UFS_PART_4}, /* userdata       6G p72 */
#endif
#endif
#endif
    {"0", 0, 0, 0},
};
#endif
