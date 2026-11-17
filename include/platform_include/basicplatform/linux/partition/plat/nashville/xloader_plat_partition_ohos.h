#ifndef _PISCES_XLOADER_PLAT_PARTITION_OHOS_H_
#define _PISCES_XLOADER_PLAT_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"


#define XLOADER3_VRL_INDEX_A    22
#define BL2_VRL_INDEX           34
#define FASTBOOT_VRL_INDEX_A    51
#define VECTOR_VRL_INDEX_A      52

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                      0,      4 * 1024, UFS_PART_0},
    {PART_RESERVED1,             7 * 1024,          1024, UFS_PART_2}, /* reserved1         1024KB p3 */
    {PART_VRL,                        512,           512, UFS_PART_3}, /* vrl                512KB p1 */
    {PART_VRL_BACKUP,                1024,           512, UFS_PART_3}, /* vrl backup         512KB p2 */
    {PART_NVME,                 10 * 1024,      4 * 1024, UFS_PART_3}, /* nvme                 4MB p4 */
    {PART_DDR_PARA,             227 * 1024,     1 * 1024, UFS_PART_3}, /* ddr_para             1MB p14 */
    {PART_LOWPOWER_PARA,        228 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para        1MB p15 */
    {PART_DFX,                  435 * 1024,    16 * 1024, UFS_PART_3}, /* dfx                 16MB p22 */
    {PART_BL2,                  592 * 1024,     4 * 1024, UFS_PART_3}, /* bl2                  4MB p28 */
    {PART_FW_CPU_LPCTRL, (596 * 1024 + 512),         256, UFS_PART_3}, /* fw_cpu_lpctrl      256KB p30 */
    {PART_FW_GPU_LPCTRL, (596 * 1024 + 768),         128, UFS_PART_3}, /* fw_gpu_lpctrl      128KB p31 */
    {PART_FW_DDR_LPCTRL, (596 * 1024 + 896),         256, UFS_PART_3}, /* fw_ddr_lpctrl      256KB p32 */
    {PART_DDR_XPU_BOOT0, (597 * 1024 + 128),         256, UFS_PART_3}, /* ddr_xpu_boot0      256KB p33 */
    {PART_DDR_XPU_BOOT1, (597 * 1024 + 384),         256, UFS_PART_3}, /* ddr_xpu_boot1      256KB p34 */
    {PART_DDR_XPU_BOOT2, (597 * 1024 + 640),         256, UFS_PART_3}, /* ddr_xpu_boot2      256KB p35 */
    {PART_UCE,           (597 * 1024 + 896),         160, UFS_PART_3}, /* uce                160KB p36 */
    {PART_DACC,                615 * 1024,          512,  UFS_PART_3}, /* dacc               512KB p40 */
    {PART_HISEE_IMG,            616 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p42 */
    {PART_HISEE_FS,             624 * 1024,     8 * 1024, UFS_PART_3}, /* hisee_fs             8MB p44 */
    {PART_FASTBOOT,             632 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p45 */
    {PART_VECTOR,               644 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p46 */
#ifdef FACTORY_VERSION
    {PART_HIBENCH_IMG,         1630 * 1024,   128 * 1024, UFS_PART_3}, /* hibench_img        128MB p92 */
    {PART_HIBENCH_LOG,         1758 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p93 */
    {PART_HIBENCH_DATA,        1790 * 1024,  1000 * 1024, UFS_PART_3}, /* hibench_data      1000MB p94 */
    {PART_FLASH_AGEING,        2790 * 1024,   512 * 1024, UFS_PART_3}, /* flash_ageing       512MB p95 */
    {PART_HIBENCH_LPM3,        3302 * 1024,     2 * 1024, UFS_PART_3}, /* hibench_lpm3         2MB p96 */
    {PART_XLOADER_HITEST,      3304 * 1024,     2 * 1024, UFS_PART_3}, /* xloader_hitest       2MB p97 */
#elif defined(CONFIG_PARTITION_ENG)
    {PART_FTTEST,             23581 * 1024,   192 * 1024, UFS_PART_3}, /* fttest             192MB p99 */
    {PART_DDRTEST,            23773 * 1024,    48 * 1024, UFS_PART_3}, /* ddrtest             48MB p100 */
    {PART_XLOADER_HITEST,     25847 * 1024,     2 * 1024, UFS_PART_3}, /* xloader_hitest       2MB p125 */
#endif
    {"0", 0, 0, 0},
};

#endif
