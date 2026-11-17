/*
 *  Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 *  Description: the partition table.
 */

#ifndef _ANTLIA_CDC_ACE_CSV3_XLOADER_PLAT_PARTITION_H_
#define _ANTLIA_CDC_ACE_CSV3_XLOADER_PLAT_PARTITION_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

#define XLOADER3_VRL_INDEX_A    10
#define BL2_VRL_INDEX           11
#define FASTBOOT_VRL_INDEX_A    9
#define VECTOR_VRL_INDEX_A      19
#define XLOADER3_VRL_INDEX_B    72
#define BL2_VRL_INDEX_B         73
#define FASTBOOT_VRL_INDEX_B    71
#define VECTOR_VRL_INDEX_B      81

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER_A,                0,              2 * 1024,    UFS_PART_0},
    {PART_XLOADER_B,                0,              2 * 1024,    UFS_PART_1},
    {PART_RESERVED1,                  1536,          512, UFS_PART_2}, /* reserved1          512KB p3 */
    {PART_VRL_A,                       512,          512, UFS_PART_2}, /* vrl_a              512KB p1 */
    {PART_VRL_B,                       512,          512, UFS_PART_3}, /* vrl_b              512KB p1 */
    {PART_VRL_BACKUP_A,               1024,          512, UFS_PART_2}, /* vrl_backup_a       512KB p2 */
    {PART_VRL_BACKUP_B,               1024,          512, UFS_PART_3}, /* vrl_backup_b       512KB p2 */
    {PART_BOOT_CTRL,              7 * 1024,     1 * 1024, UFS_PART_5}, /* boot_ctrl         1024KB p3 */
    {PART_NVME,                   8 * 1024,     5 * 1024, UFS_PART_5}, /* nvme                 5MB p4 */
    {PART_BOARD_ID,             110 * 1024,           64, UFS_PART_5}, /* board_id            64KB p7 */
    {PART_DDR_PARA,             149 * 1024,     1 * 1024, UFS_PART_5}, /* ddr_para          1024KB p12 */
    {PART_LOWPOWER_PARA_A,       34 * 1024,     1 * 1024, UFS_PART_2}, /* lowpower_para_a   1024KB p10 */
    {PART_LOWPOWER_PARA_B,       34 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para_b   1024KB p10 */
    {PART_BL2_A,                 35 * 1024,     4 * 1024, UFS_PART_2}, /* bl2_a                4MB p11 */
    {PART_BL2_B,                 35 * 1024,     4 * 1024, UFS_PART_3}, /* bl2_b                4MB p11 */
    {PART_DFX,                  236 * 1024,    16 * 1024, UFS_PART_5}, /* dfx                 16MB p18 */
    {PART_FW_CPU_LPCTRL_A,(47 * 1024 + 512),          256, UFS_PART_2}, /* fw_cpu_lpctrl_a    256KB p14 */
    {PART_FW_GPU_LPCTRL_A,(47 * 1024 + 768),          128, UFS_PART_2}, /* fw_gpu_lpctrl_a    128KB p15 */
    {PART_FW_DDR_LPCTRL_A,(47 * 1024 + 896),          128, UFS_PART_2}, /* fw_ddr_lpctrl_a    128KB p16 */
    {PART_FW_CPU_LPCTRL_B, (47 * 1024 + 512),        256, UFS_PART_3}, /* fw_cpu_lpctrl_b    256KB p14 */
    {PART_FW_GPU_LPCTRL_B, (47 * 1024 + 768),        128, UFS_PART_3}, /* fw_gpu_lpctrl_b    128KB p15 */
    {PART_FW_DDR_LPCTRL_B, (47 * 1024 + 896),          128, UFS_PART_3}, /* fw_ddr_lpctrl_b    128KB p16 */
    {PART_HISEE_IMG_A,           14 * 1024,     4 * 1024, UFS_PART_2}, /* hisee_img_a          4MB p7 */
    {PART_HISEE_IMG_B,           14 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img_b          4MB p7 */
    {PART_FASTBOOT_A,            22 * 1024,    12 * 1024, UFS_PART_2}, /* fastboot_a          12MB p9 */
    {PART_FASTBOOT_B,            22 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot_b          12MB p9 */
    {PART_VECTOR_A,              56 * 1024,     4 * 1024, UFS_PART_2}, /* vector_a             4MB p19 */
    {PART_VECTOR_B,              56 * 1024,     4 * 1024, UFS_PART_3}, /* vector_b             4MB p19 */
    {PART_SAFETY_ISLAND_A,      766 * 1024,     4 * 1024, UFS_PART_2}, /* safety_island_a      4MB p51 */ 
    {PART_SAFETY_ISLAND_B,      766 * 1024,     4 * 1024, UFS_PART_3}, /* safety_island_b      4MB p50 */
    {PART_DACC_A,               787 * 1024,          256, UFS_PART_2}, /* dacc_a             256KB p55 */
    {PART_DACC_LITE_A,  (787 * 1024 + 256),          256, UFS_PART_2}, /* dacc_lite_a        256KB p56 */
    {PART_DACC_B,               787 * 1024,          256, UFS_PART_3}, /* dacc_b             256KB p54 */
    {PART_DACC_LITE_B,   (787 * 1024 + 256),         256, UFS_PART_3}, /* dacc_lite_b        256KB p54 */
    {PART_DDR_XPU_BOOT0_A,      788 * 1024,          136, UFS_PART_2}, /* ddr_xpu_boot0_a    136KB p58 */
    {PART_DDR_XPU_BOOT1_A,(788 * 1024 + 136),        136, UFS_PART_2},  /* ddr_xpu_boot1_a    136KB p59 */
    {PART_DDR_XPU_BOOT0_B,      788 * 1024,          136, UFS_PART_3}, /* ddr_xpu_boot0_b    136KB p56 */
    {PART_DDR_XPU_BOOT1_B,(788 * 1024 + 136),        136, UFS_PART_3},  /* ddr_xpu_boot1_b    136KB p57 */
    {PART_HISEE_FS,             388 * 1024,     8 * 1024, UFS_PART_5}, /* hisee_fs             8MB p22 */
#ifdef FACTORY_VERSION
    {PART_HIBENCH_IMG,        36794 * 1024,   128 * 1024, UFS_PART_5}, /* hibench_img        128MB p35 */
    {PART_HIBENCH_LOG,        37946 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p38 */
    {PART_SECFLASH_AGEING,    38010 * 1024,    32 * 1024, UFS_PART_5}, /* secflash_ageing     32MB p40 */
#endif
#ifdef CONFIG_PARTITION_ENG
#ifdef CONFIG_HISI_DEBUG_FS
    {PART_FTTEST,             36794 * 1024,   192 * 1024, UFS_PART_5}, /* fttest             192MB p35 */
#endif
#ifdef XLOADER_DDR_TEST
    {PART_DDRTEST,            36986 * 1024,    48 * 1024, UFS_PART_5}, /* ddrtest             48MB p36 */
#endif
#endif
    {"0", 0, 0, 0},
};

#endif
