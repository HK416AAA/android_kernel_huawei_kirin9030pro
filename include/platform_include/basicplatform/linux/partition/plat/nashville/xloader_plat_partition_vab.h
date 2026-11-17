/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * Description: the partition table.
 */

#ifndef _PISCES_XLOADER_PLAT_PARTITION_H_
#define _PISCES_XLOADER_PLAT_PARTITION_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"


#define XLOADER3_VRL_INDEX_A    22
#define BL2_VRL_INDEX           33
#define FASTBOOT_VRL_INDEX_A    51
#define VECTOR_VRL_INDEX_A      52

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                0,              4 * 1024,    UFS_PART_0},
    {PART_RESERVED1,              7 * 1024,           1024,    UFS_PART_2}, /* reserved1       1024K    p3 */
    {PART_LOWPOWER_PARA,          512,                  1 * 1024,      UFS_PART_3}, /* lowpower_para     1024KB p1 */
    {PART_BL2,               (1 * 1024 + 512),     4 * 1024, UFS_PART_3}, /* bl2                  4MB p2 */
    {PART_FW_CPU_LPCTRL,         10 * 1024,          256, UFS_PART_3}, /* fw_cpu_lpctrl      256KB p5 */
    {PART_FW_GPU_LPCTRL,     (10 * 1024 + 256),          128, UFS_PART_3}, /* fw_gpu_lpctrl      128KB p6 */
    {PART_FW_DDR_LPCTRL,     (10 * 1024 + 384),          256, UFS_PART_3}, /* fw_ddr_lpctrl      256KB p7 */
    {PART_DDR_XPU_BOOT0,     (10 * 1024 + 640),          256, UFS_PART_3}, /* ddr_xpu_boot0      256KB p8 */
    {PART_DDR_XPU_BOOT1,     (10 * 1024 + 896),          256, UFS_PART_3}, /* ddr_xpu_boot1      256KB p9 */
    {PART_DDR_XPU_BOOT2,     (11 * 1024 + 128),          256, UFS_PART_3}, /* ddr_xpu_boot2      256KB p10 */
    {PART_UCE,               (11 * 1024 + 384),          160, UFS_PART_3}, /* uce                160KB p11 */
    {PART_DACC,                  27 * 1024,          512, UFS_PART_3}, /* dacc               512KB p16 */
    {PART_HISEE_IMG,             28 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p18 */
    {PART_FASTBOOT,              36 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p20 */
    {PART_VECTOR,                48 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p21 */
    {PART_VRL,               (1 * 1024 + 512),          512, UFS_PART_5}, /* vrl                512KB p2 */
    {PART_VRL_BACKUP,             2 * 1024,          512, UFS_PART_5}, /* vrl_backup         512KB p3 */
    {PART_NVME,                  11 * 1024,     4 * 1024, UFS_PART_5}, /* nvme                 4MB p5 */
    {PART_DDR_PARA,             228 * 1024,     1 * 1024, UFS_PART_5}, /* ddr_para          1024KB p15 */
    {PART_DFX,                  435 * 1024,    16 * 1024, UFS_PART_5}, /* dfx                 16MB p22 */
    {PART_MISC,                 433 * 1024,     2 * 1024, UFS_PART_5}, /* misc                 2MB p21 */
    {PART_HISEE_FS,             588 * 1024,     8 * 1024, UFS_PART_5}, /* hisee_fs             8MB p27 */
#ifdef FACTORY_VERSION
    {PART_HIBENCH_IMG,        13329 * 1024,   128 * 1024, UFS_PART_5}, /* hibench_img        128MB p34 */
    {PART_FLASH_AGEING,       14457 * 1024,   512 * 1024, UFS_PART_5}, /* flash_ageing       512MB p36 */
    {PART_HIBENCH_LOG,        14969 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p37 */
    {PART_XLOADER_HITEST,     15001 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p38 */
#endif
#ifdef XLOADER_LOAD_AND_BOOT_POSTSI
    {PART_SUPER,                625 * 1024,  8723 * 1024, UFS_PART_5}, /* super             8723MB p31 */
#endif
#ifdef CONFIG_PARTITION_ENG
#ifdef CONFIG_HISI_DEBUG_FS
    {PART_FTTEST,             22752 * 1024,   192 * 1024, UFS_PART_5}, /* fttest             192MB p34 */
    {PART_XLOADER_HITEST,     25018 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p62 */
#endif
#ifdef XLOADER_DDR_TEST
    {PART_DDRTEST,            22944 * 1024,    48 * 1024, UFS_PART_5}, /* ddrtest             48MB p35 */
#endif
#endif
    {"0", 0, 0, 0},
};

#endif