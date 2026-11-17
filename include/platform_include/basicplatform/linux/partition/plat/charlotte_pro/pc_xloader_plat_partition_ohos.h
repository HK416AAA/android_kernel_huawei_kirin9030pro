#ifndef _ANTLIA_XLOADER_PLAT_PARTITION_OHOS_H_
#define _ANTLIA_XLOADER_PLAT_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"

#ifdef CONFIG_SPI_NOR_STORAGE
#define XLOADER3_VRL_INDEX_A    21
#define BL2_VRL_INDEX            7
#define FASTBOOT_VRL_INDEX_A    18
#define XLOADER3_VRL_INDEX_B    39
#define BL2_VRL_INDEX_B         25
#define FASTBOOT_VRL_INDEX_B    36
#else
#define XLOADER3_VRL_INDEX_A    15
#define BL2_VRL_INDEX           31
#define FASTBOOT_VRL_INDEX_A    47
#define VECTOR_VRL_INDEX_A      48
#endif

static const struct partition partition_table_emmc[] = {
    {PART_PTABLE,                      0,           136, SPI_NOR_PART}, /* ptable            136K    p0  */
    {PART_BOOT_CTRL,                  136,            4, SPI_NOR_PART}, /* boot_ctrl            4KB p1 */
    {PART_BL2_A,                      140,          900, SPI_NOR_PART}, /* bl2_a                900KB p2 */
    {PART_FW_CPU_LPCTRL_A,           1040,          256, SPI_NOR_PART}, /* fw_cpu_lpctrl_a      256KB p3 */
    {PART_FW_GPU_LPCTRL_A,           1296,          128, SPI_NOR_PART}, /* fw_gpu_lpctrl_a      128KB p4 */
    {PART_FW_DDR_LPCTRL_A,           1424,          128, SPI_NOR_PART}, /* fw_ddr_lpctrl_a      128KB p5 */
    {PART_DDR_XPU_BOOT0_A,           1552,          136, SPI_NOR_PART}, /* ddr_xpu_boot0_a      136KB p6 */
    {PART_DDR_XPU_BOOT1_A,           1688,          136, SPI_NOR_PART}, /* ddr_xpu_boot1_a      136KB p7 */
    {PART_DFX_XLOADER,               3276,           16, SPI_NOR_PART}, /* dfx_xloader         16KB p13 */
    /* !!!Attention!!! cannot modify xloader_a offset */
    {PART_XLOADER_A,                 3380,         1024, SPI_NOR_PART}, /* xloader_a          1024KB p9 */
    {PART_NVME,                      4404,         1024, SPI_NOR_PART}, /* nvme              1024KB p13 */
#ifdef FACTORY_VERSION
    {PART_FASTBOOT_A,                5428,         5120, SPI_NOR_PART}, /* fastboot             5MB p14 */
    {PART_HIBENCH_IMG,              10548,         4608, SPI_NOR_PART}, /* hibench_img       4608KB p15 */
    {PART_HIBENCH_LOG,              15156,          512, SPI_NOR_PART}, /* hibench_log        512KB p16 */
#else
    {PART_FASTBOOT_A,                5428,        6144, SPI_NOR_PART}, /* fastboot_a            6MB p14 */
    {PART_BL2_B,                    11572,         900, SPI_NOR_PART}, /* bl2_b               900KB p15 */
    {PART_FW_CPU_LPCTRL_B,          12472,         256, SPI_NOR_PART}, /* fw_cpu_lpctrl_b     256KB p16 */
    {PART_FW_GPU_LPCTRL_B,          12728,         128, SPI_NOR_PART}, /* fw_gpu_lpctrl_b     128KB p17 */
    {PART_DDR_XPU_BOOT0_B,          12856,         136, SPI_NOR_PART}, /* ddr_xpu_boot0_b     136KB p18 */
    {PART_DDR_XPU_BOOT1_B,          12992,         136, SPI_NOR_PART}, /* ddr_xpu_boot1_b     136KB p19 */
    {PART_LOWPOWER_PARA_B,          13128,         512, SPI_NOR_PART}, /* lowpower_para_b      512KB p20 */
    {PART_RESERVED2,                13640,        2028, SPI_NOR_PART}, /* reserved2          2540KB p20 */
#endif
    {PART_DDR_PARA,                 15668,          256, SPI_NOR_PART}, /* ddr_para           256KB p18 */
    {PART_UEFI_LOGO,                15924,          768, SPI_NOR_PART}, /* uefi_logo          768KB p19 */
    {PART_LOWPOWER_PARA_A,          16692,          512, SPI_NOR_PART}, /* lowpower_para      512KB p20 */
    {PART_FW_LPM3,                  17204,          512, SPI_NOR_PART}, /* fw_lpm3            512KB p21 */
    {PART_XLOADER_B,                18064,         1024, SPI_NOR_PART}, /* xloader_b         1024KB p25 */
    {PART_UEFI_VB,                  19088,          256, SPI_NOR_PART}, /* uefi_vb            256KB p24 */
    {PART_VECTOR,                   32196,          512, SPI_NOR_PART}, /* vector             512KB p35 */
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {"0", 0, 0, 0},
};
#endif
