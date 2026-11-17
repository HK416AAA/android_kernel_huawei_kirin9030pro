/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * Description: the partition table.
 */

#ifndef _PISCES_XLOADER_PLAT_PARTITION_H_
#define _PISCES_XLOADER_PLAT_PARTITION_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"


#define XLOADER3_VRL_INDEX_A    12
#define XLOADER3_VRL_INDEX_B    13
#define BL2_VRL_INDEX           15
#define BL2_VRL_INDEX_B         16
#define FASTBOOT_VRL_INDEX_A    37
#define FASTBOOT_VRL_INDEX_B    38
#define VECTOR_VRL_INDEX_A      39
#define VECTOR_VRL_INDEX_B      40

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER_A,                               0,      4 * 1024, UFS_PART_0},
    {PART_XLOADER_B,                               0,      4 * 1024, UFS_PART_1},
    {PART_BOOT_CTRL,                             512,           512, UFS_PART_2}, /* boot_ctrl   512KB p1 */
    {PART_NVME,                                 1024,      4 * 1024, UFS_PART_2}, /* nvme                 4MB p2 */
    {PART_DDR_PARA,                       101 * 1024,      1 * 1024, UFS_PART_2}, /* ddr_para          1024KB p4 */
    {PART_LOWPOWER_PARA_A,           (1 * 1024 + 512),     1 * 1024, UFS_PART_3}, /* lowpower_para_a   1024KB p3 */
    {PART_BL2_A,                     (2 * 1024 + 512),     4 * 1024, UFS_PART_3}, /* bl2_a                4MB p4 */
    {PART_FW_CPU_LPCTRL_A,                   7 * 1024,          256, UFS_PART_3}, /* fw_cpu_lpctrl_a    256KB p6 */
    {PART_FW_GPU_LPCTRL_A,           (7 * 1024 + 256),          128, UFS_PART_3}, /* fw_gpu_lpctrl_a    128KB p7 */
    {PART_FW_DDR_LPCTRL_A,           (7 * 1024 + 384),          256, UFS_PART_3}, /* fw_ddr_lpctrl_a    256KB p8 */
    {PART_DDR_XPU_BOOT0_A,           (7 * 1024 + 640),          256, UFS_PART_3}, /* ddr_xpu_boot0_a    256KB p9 */
    {PART_DDR_XPU_BOOT1_A,           (7 * 1024 + 896),          256, UFS_PART_3}, /* ddr_xpu_boot1_a    256KB p10 */
    {PART_DDR_XPU_BOOT2_A,           (8 * 1024 + 128),          256, UFS_PART_3}, /* ddr_xpu_boot2_a    256KB p11 */
    {PART_DACC_A,                    (8 * 1024 + 384),          512, UFS_PART_3}, /* dacc_a             512KB p12 */
    {PART_UCE_A,                     (8 * 1024 + 896),          160, UFS_PART_3}, /* uce_a              160KB p13 */
    {PART_VENC_A,                     (9 * 1024 + 32),          512, UFS_PART_3}, /* venc_a             512KB p14 */
    {PART_FASTBOOT_A,                (9 * 1024 + 544),    12 * 1024, UFS_PART_3}, /* fastboot_a          12MB p15 */
    {PART_VECTOR_A,                 (21 * 1024 + 544),     4 * 1024, UFS_PART_3}, /* vector_a             4MB p16 */
    {PART_LOWPOWER_PARA_B,           (1 * 1024 + 512),     1 * 1024, UFS_PART_4}, /* lowpower_para_b   1024KB p3 */
    {PART_BL2_B,                     (2 * 1024 + 512),     4 * 1024, UFS_PART_4}, /* bl2_b                4MB p4 */
    {PART_FW_CPU_LPCTRL_B,                   7 * 1024,          256, UFS_PART_4}, /* fw_cpu_lpctrl_b    256KB p6 */
    {PART_FW_GPU_LPCTRL_B,           (7 * 1024 + 256),          128, UFS_PART_4}, /* fw_gpu_lpctrl_b    128KB p7 */
    {PART_FW_DDR_LPCTRL_B,           (7 * 1024 + 384),          256, UFS_PART_4}, /* fw_ddr_lpctrl_b    256KB p8 */
    {PART_DDR_XPU_BOOT0_B,           (7 * 1024 + 640),          256, UFS_PART_4}, /* ddr_xpu_boot0_b    256KB p9 */
    {PART_DDR_XPU_BOOT1_B,           (7 * 1024 + 896),          256, UFS_PART_4}, /* ddr_xpu_boot1_b    256KB p10 */
    {PART_DDR_XPU_BOOT2_B,           (8 * 1024 + 128),          256, UFS_PART_4}, /* ddr_xpu_boot2_b    256KB p11 */
    {PART_DACC_B,                    (8 * 1024 + 384),          512, UFS_PART_4}, /* dacc_b             512KB p12 */
    {PART_UCE_B,                     (8 * 1024 + 896),          160, UFS_PART_4}, /* uce_b              160KB p13 */
    {PART_VENC_B,                     (9 * 1024 + 32),          512, UFS_PART_4}, /* venc_b             512KB p14 */
    {PART_FASTBOOT_B,                (9 * 1024 + 544),    12 * 1024, UFS_PART_4}, /* fastboot_b          12MB p15 */
    {PART_VECTOR_B,                 (21 * 1024 + 544),     4 * 1024, UFS_PART_4}, /* vector_b             4MB p16 */
#ifdef FACTORY_VERSION
    {PART_HIBENCH_IMG,       123906 * 1024,   128 * 1024, UFS_PART_5}, /* hibench_img        128MB p4 */
    {PART_FLASH_AGEING,      124546 * 1024,   512 * 1024, UFS_PART_5}, /* flash_ageing       512MB p6 */
    {PART_HIBENCH_LOG,       125058 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p7 */
    {PART_XLOADER_HITEST,    125092 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p124 */
    {PART_HISEE_IMG,         125094 * 1024,     4 * 1024, UFS_PART_5}, /* hisee_img            4M    p36 */
    {PART_HISEE_FS,          125098 * 1024,     8 * 1024, UFS_PART_5}, /* hisee_fs             8M    p38 */
#endif
    {"0", 0, 0, 0},
};

#endif
