#ifndef _PISCES_XLOADER_PLAT_PARTITION_OHOS_TV_H_
#define _PISCES_XLOADER_PLAT_PARTITION_OHOS_TV_H_
 
#include "partition_macro.h"
#include "partition_macro_plus.h"
 
 
#define XLOADER3_VRL_INDEX_A    10
#define XLOADER3_VRL_INDEX_B    48
#define BL2_VRL_INDEX           12
#define BL2_VRL_INDEX_B         50
#define FASTBOOT_VRL_INDEX_A    18
#define FASTBOOT_VRL_INDEX_B    56
#define VECTOR_VRL_INDEX_A      19
#define VECTOR_VRL_INDEX_B      57
 
static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};
 
static const struct partition partition_table_ufs[] = {
    {PART_XLOADER_A,                               0,     4 * 1024, UFS_PART_0},
    {PART_XLOADER_B,                             0,     4 * 1024, UFS_PART_1},
    {PART_FW_CPU_LPCTRL_A,             512,          256, UFS_PART_2}, /* fw_cpu_lpctrl_a    256KB p1 */
    {PART_FW_GPU_LPCTRL_A,             768,          128, UFS_PART_2}, /* fw_gpu_lpctrl_a    128KB p2 */
    {PART_FW_DDR_LPCTRL_A,             896,          256, UFS_PART_2}, /* fw_ddr_lpctrl_a    256KB p3 */
    {PART_DDR_XPU_BOOT0_A,   (1 * 1024 + 128),          256, UFS_PART_2}, /* ddr_xpu_boot0_a    256KB p4 */
    {PART_DDR_XPU_BOOT1_A,   (1 * 1024 + 384),          256, UFS_PART_2}, /* ddr_xpu_boot1_a    256KB p5 */
    {PART_UCE_A,             (1 * 1024 + 640),          160, UFS_PART_2}, /* uce_a              160KB p6 */
    {PART_LOWPOWER_PARA_A,        4 * 1024,        1 * 1024, UFS_PART_2}, /* lowpower_para_a   1024KB p8 */
    {PART_BL2_A,                  9 * 1024,        4 * 1024, UFS_PART_2}, /* bl2_a                4MB p10 */
    {PART_DACC_A,            (13 * 1024 + 512),          512, UFS_PART_2}, /* dacc_a             512KB p12 */
    {PART_HISEE_IMG_A,           22 * 1024,     4 * 1024, UFS_PART_2}, /* hisee_img_a          4MB p14 */
    {PART_FASTBOOT_A,            30 * 1024,    12 * 1024, UFS_PART_2}, /* fastboot_a          12MB p16 */
    {PART_FW_CPU_LPCTRL_B,             512,          256, UFS_PART_3}, /* fw_cpu_lpctrl_b    256KB p1 */
    {PART_FW_GPU_LPCTRL_B,             768,          128, UFS_PART_3}, /* fw_gpu_lpctrl_b    128KB p2 */
    {PART_FW_DDR_LPCTRL_B,             896,          256, UFS_PART_3}, /* fw_ddr_lpctrl_b    256KB p3 */
    {PART_DDR_XPU_BOOT0_B,   (1 * 1024 + 128),          256, UFS_PART_3}, /* ddr_xpu_boot0_b    256KB p4 */
    {PART_DDR_XPU_BOOT1_B,   (1 * 1024 + 384),          256, UFS_PART_3}, /* ddr_xpu_boot1_b    256KB p5 */
    {PART_UCE_B,             (1 * 1024 + 640),          160, UFS_PART_3}, /* uce_b              160KB p6 */
	{PART_LOWPOWER_PARA_B,        4 * 1024,        1 * 1024, UFS_PART_3}, /* lowpower_para_b   1024KB p8 */
    {PART_BL2_B,                  9 * 1024,        4 * 1024, UFS_PART_3}, /* bl2_b                4MB p10 */
    {PART_DACC_B,            (13 * 1024 + 512),          512, UFS_PART_3}, /* dacc_b             512KB p12 */
    {PART_HISEE_IMG_B,           22 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img_b          4MB p14 */
    {PART_FASTBOOT_B,            30 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot_b          12MB p16 */
	{PART_VRL,                    8 * 1024,          512, UFS_PART_4}, /* vrl                512KB p4 */
    {PART_VRL_BACKUP,        (8 * 1024 + 512),          512, UFS_PART_4}, /* vrl_backup         512KB p5 */
	{PART_BOOT_CTRL,             18 * 1024,     1 * 1024, UFS_PART_4}, /* boot_ctrl         1024KB p7 */
    {PART_NVME,                  19 * 1024,     4 * 1024, UFS_PART_4}, /* nvme                 4MB p8 */
    {PART_DDR_PARA,             240 * 1024,     1 * 1024, UFS_PART_4}, /* ddr_para          1024KB p19 */
    {PART_DFX,                  447 * 1024,    16 * 1024, UFS_PART_4}, /* dfx                 16MB p26 */
    {PART_DDR_XPU_BOOT2,        600 * 1024,          256, UFS_PART_4}, /* ddr_xpu_boot2      256KB p31 */
    {PART_HISEE_FS,          (609 * 1024 + 512),     8 * 1024, UFS_PART_4}, /* hisee_fs             8MB p35 */
    {PART_VECTOR,            (617 * 1024 + 512),     4 * 1024, UFS_PART_4}, /* vector               4MB p36 */
    {"0", 0, 0, 0},
};
 
#endif