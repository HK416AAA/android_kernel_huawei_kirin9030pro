/*
 *  Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 *  Description: the partition table.
 */

#ifndef _ANTLIA_CDC_ACE_XLOADER_PLAT_PARTITION_OHOS_H_
#define _ANTLIA_CDC_ACE_XLOADER_PLAT_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

#define XLOADER3_VRL_INDEX_A    9
#define BL2_VRL_INDEX           10
#define FASTBOOT_VRL_INDEX_A    8
#define VECTOR_VRL_INDEX_A      17
#define XLOADER3_VRL_INDEX_B    69
#define BL2_VRL_INDEX_B         70
#define FASTBOOT_VRL_INDEX_B    68
#define VECTOR_VRL_INDEX_B      77

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                  0,              2 * 1024,    UFS_PART_0},
    {PART_XLOADER_B,                0,              2 * 1024,    UFS_PART_1},
    {PART_HISEE_IMG,             11 * 1024,     4 * 1024, UFS_PART_2}, /* hisee_img_a          4MB p4 */
    {PART_FASTBOOT,              19 * 1024,    12 * 1024, UFS_PART_2}, /* fastboot_a          12MB p9 */
    {PART_LOWPOWER_PARA,         31 * 1024,     1 * 1024, UFS_PART_2}, /* lowpower_para_a   1024KB p7 */
    {PART_BL2,                   32 * 1024,     4 * 1024, UFS_PART_2}, /* bl2_a                4MB p8 */
    {PART_FW_CPU_LPCTRL,  (44 * 1024 + 512),          256, UFS_PART_2}, /* fw_cpu_lpctrl_a    256KB p11 */
    {PART_FW_GPU_LPCTRL,  (44 * 1024 + 768),          128, UFS_PART_2}, /* fw_gpu_lpctrl_a    128KB p12 */
    {PART_FW_DDR_LPCTRL,  (44 * 1024 + 896),          128, UFS_PART_2}, /* fw_ddr_lpctrl_a    128KB p13 */
    {PART_VECTOR,                53 * 1024,     4 * 1024, UFS_PART_2}, /* vector_a             4MB p19 */
    {PART_DACC,                 540 * 1024,          256, UFS_PART_2}, /* dacc_a             256KB p55 */
    {PART_DACC_LITE,    (540 * 1024 + 256),          256, UFS_PART_2}, /* dacc_lite_a        256KB p47 */
    {PART_DDR_XPU_BOOT0,        541 * 1024,          136, UFS_PART_2}, /* ddr_xpu_boot0_a    136KB p49 */
    {PART_DDR_XPU_BOOT1,  (541 * 1024 + 136),        136, UFS_PART_2},  /* ddr_xpu_boot1_a    136KB p59 */
    {PART_SAFETY_ISLAND,  (1064 * 1024 + 272),  4 * 1024, UFS_PART_2}, /* safety_island_a      4MB p58 */
    {PART_HISEE_IMG_B,           11 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img_b          4MB p7 */
    {PART_FASTBOOT_B,            19 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot_b          12MB p9 */
    {PART_LOWPOWER_PARA_B,       31 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para_b   1024KB p7 */
    {PART_BL2_B,                 32 * 1024,     4 * 1024, UFS_PART_3}, /* bl2_b                4MB p11 */
    {PART_FW_CPU_LPCTRL_B,(44 * 1024 + 512),          256, UFS_PART_3}, /* fw_cpu_lpctrl_b    256KB p11 */
    {PART_FW_GPU_LPCTRL_B,(44 * 1024 + 768),          128, UFS_PART_3}, /* fw_gpu_lpctrl_b    128KB p12 */
    {PART_FW_DDR_LPCTRL_B,(44 * 1024 + 896),          128, UFS_PART_3}, /* fw_ddr_lpctrl_b    128KB p13 */
    {PART_VECTOR_B,              53 * 1024,     4 * 1024, UFS_PART_3}, /* vector_b             4MB p19 */
    {PART_DACC_B,               540 * 1024,          256, UFS_PART_3}, /* dacc_b             256KB p54 */
    {PART_DACC_LITE_B,   (540 * 1024 + 256),         256, UFS_PART_3}, /* dacc_lite_b        256KB p54 */
    {PART_DDR_XPU_BOOT0_B,      541 * 1024,          136, UFS_PART_3}, /* ddr_xpu_boot0_b    136KB p56 */
    {PART_DDR_XPU_BOOT1_B,(541 * 1024 + 136),        136, UFS_PART_3},  /* ddr_xpu_boot1_b    136KB p57 */
    {PART_SAFETY_ISLAND_B,(1064 * 1024 + 272),  4 * 1024, UFS_PART_3}, /* safety_island_b      4MB p50 */
    {PART_BOOT_CTRL,              7 * 1024,     1 * 1024, UFS_PART_5}, /* boot_ctrl         1024KB p3 */
    {PART_NVME,                   8 * 1024,     5 * 1024, UFS_PART_5}, /* nvme                 5MB p4 */
    {PART_BOARD_ID,             110 * 1024,           64, UFS_PART_5}, /* board_id            64KB p7 */
    {PART_DDR_PARA,             149 * 1024,     1 * 1024, UFS_PART_5}, /* ddr_para          1024KB p12 */
    {PART_DFX,                  236 * 1024,    16 * 1024, UFS_PART_5}, /* dfx                 16MB p18 */
    {PART_HISEE_FS,             388 * 1024,     8 * 1024, UFS_PART_5}, /* hisee_fs             8MB p22 */
#ifdef FACTORY_VERSION
    {PART_HIBENCH_IMG,        33594 * 1024,   128 * 1024, UFS_PART_5}, /* hibench_img        128MB p47 */
    {PART_HIBENCH_LOG,        34746 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p50 */
    {PART_SECFLASH_AGEING,    34810 * 1024,    32 * 1024, UFS_PART_5}, /* secflash_ageing     32MB p52 */
#endif
#ifdef CONFIG_PARTITION_ENG
#ifdef CONFIG_HISI_DEBUG_FS
    {PART_FTTEST,             33594 * 1024,   192 * 1024, UFS_PART_5}, /* fttest             192MB p47 */
#endif
#ifdef XLOADER_DDR_TEST
    {PART_DDRTEST,            33786 * 1024,    48 * 1024, UFS_PART_5}, /* ddrtest             48MB p48 */
#endif
#endif
    {"0", 0, 0, 0},
};

#endif
