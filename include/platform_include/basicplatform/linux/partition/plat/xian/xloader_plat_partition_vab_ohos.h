/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * Description: the partition table.
 */

#ifndef _PISCES_XLOADER_PLAT_PARTITION_H_
#define _PISCES_XLOADER_PLAT_PARTITION_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"


#define XLOADER3_VRL_INDEX_A    21
#define BL2_VRL_INDEX           34
#define FASTBOOT_VRL_INDEX_A    51
#define VECTOR_VRL_INDEX_A      52

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER_A,                      0,     2 * 1024, UFS_PART_0},
    {PART_XLOADER_B,                    0,     2 * 1024, UFS_PART_1},
    {PART_VRL,               (1 * 1024 + 512),          512, UFS_PART_5}, /* vrl                512KB p2 */
    {PART_VRL_BACKUP,             2 * 1024,          512, UFS_PART_5}, /* vrl_backup         512KB p3 */
    {PART_NVME,                  11 * 1024,     4 * 1024, UFS_PART_5}, /* nvme                 4MB p5 */
    {PART_DDR_PARA,             228 * 1024,     1 * 1024, UFS_PART_5}, /* ddr_para          1024KB p15 */
    {PART_DFX,                  435 * 1024,    16 * 1024, UFS_PART_5}, /* dfx                 16MB p22 */
    {PART_HISEE_FS,             588 * 1024,     8 * 1024, UFS_PART_5}, /* hisee_fs             8MB p27 */
    {PART_LOWPOWER_PARA_A,             512,     1 * 1024, UFS_PART_3}, /* lowpower_para_a   1024KB p1 */
    {PART_BL2_A,             (1 * 1024 + 512),     4 * 1024, UFS_PART_3}, /* bl2_a                4MB p2 */
    {PART_FW_CPU_LPCTRL_A,       10 * 1024,          256, UFS_PART_3}, /* fw_cpu_lpctrl_a    256KB p5 */
    {PART_FW_GPU_LPCTRL_A,   (10 * 1024 + 256),          128, UFS_PART_3}, /* fw_gpu_lpctrl_a    128KB p6 */
    {PART_FW_DDR_LPCTRL_A,   (10 * 1024 + 384),          256, UFS_PART_3}, /* fw_ddr_lpctrl_a    256KB p7 */
    {PART_DDR_XPU_BOOT0_A,   (10 * 1024 + 640),          256, UFS_PART_3}, /* ddr_xpu_boot0_a    256KB p8 */
    {PART_DDR_XPU_BOOT1_A,   (10 * 1024 + 896),          256, UFS_PART_3}, /* ddr_xpu_boot1_a    256KB p9 */
    {PART_DDR_XPU_BOOT2_A,   (11 * 1024 + 128),          256, UFS_PART_3}, /* ddr_xpu_boot2_a    256KB p10 */
    {PART_UCE_A,             (11 * 1024 + 384),          160, UFS_PART_3}, /* uce_a              160KB p11 */
    {PART_DACC_A,                27 * 1024,          512, UFS_PART_3}, /* dacc_a             512KB p16 */
    {PART_HISEE_IMG_A,           28 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img_a          4MB p18 */
    {PART_HHEE_A,                32 * 1024,     4 * 1024, UFS_PART_3}, /* hhee_a               4MB p19 */
    {PART_FASTBOOT_A,            36 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot_a          12MB p20 */
    {PART_VECTOR_A,              48 * 1024,     4 * 1024, UFS_PART_3}, /* vector_a             4MB p21 */
    {PART_LOWPOWER_PARA_B,             512,     1 * 1024, UFS_PART_4}, /* lowpower_para_b   1024KB p1 */
    {PART_BL2_B,             (1 * 1024 + 512),     4 * 1024, UFS_PART_4}, /* bl2_b                4MB p2 */
    {PART_FW_CPU_LPCTRL_B,       10 * 1024,          256, UFS_PART_4}, /* fw_cpu_lpctrl_b    256KB p5 */
    {PART_FW_GPU_LPCTRL_B,   (10 * 1024 + 256),          128, UFS_PART_4}, /* fw_gpu_lpctrl_b    128KB p6 */
    {PART_FW_DDR_LPCTRL_B,   (10 * 1024 + 384),          256, UFS_PART_4}, /* fw_ddr_lpctrl_b    256KB p7 */
    {PART_DDR_XPU_BOOT0_B,   (10 * 1024 + 640),          256, UFS_PART_4}, /* ddr_xpu_boot0_b    256KB p8 */
    {PART_DDR_XPU_BOOT1_B,   (10 * 1024 + 896),          256, UFS_PART_4}, /* ddr_xpu_boot1_b    256KB p9 */
    {PART_DDR_XPU_BOOT2_B,   (11 * 1024 + 128),          256, UFS_PART_4}, /* ddr_xpu_boot2_b    256KB p10 */
    {PART_UCE_B,             (11 * 1024 + 384),          160, UFS_PART_4}, /* uce_b              160KB p11 */
    {PART_DACC_B,                27 * 1024,          512, UFS_PART_4}, /* dacc_b             512KB p16 */
    {PART_HISEE_IMG_B,           28 * 1024,     4 * 1024, UFS_PART_4}, /* hisee_img_b          4MB p18 */
    {PART_HHEE_B,                32 * 1024,     4 * 1024, UFS_PART_4}, /* hhee_b               4MB p19 */
    {PART_FASTBOOT_B,            36 * 1024,    12 * 1024, UFS_PART_4}, /* fastboot_b          12MB p20 */
    {PART_VECTOR_B,              48 * 1024,     4 * 1024, UFS_PART_4}, /* vector_b             4MB p21 */
    {PART_BOOT_CTRL,                   512,     1 * 1024, UFS_PART_5}, /* boot_ctrl         1024KB p1 */
#ifdef FACTORY_VERSION
    {PART_HIBENCH_IMG,          745 * 1024,   128 * 1024, UFS_PART_5}, /* hibench_img        128MB p31 */
    {PART_FLASH_AGEING,        1605 * 1024,   512 * 1024, UFS_PART_5}, /* flash_ageing       512MB p34 */
    {PART_HIBENCH_LOG,          873 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p32 */
    {PART_XLOADER_HITEST,      2119 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p36 */
#elif defined(CONFIG_PARTITION_ENG)
    {PART_FTTEST,             20937 * 1024,   192 * 1024, UFS_PART_5}, /* fttest             192MB p40 */
    {PART_XLOADER_HITEST,     23163 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p66 */
    {PART_DDRTEST,            21129 * 1024,    48 * 1024, UFS_PART_5}, /* ddrtest             48MB p41 */
#endif
    {"0", 0, 0, 0},
};

#endif
