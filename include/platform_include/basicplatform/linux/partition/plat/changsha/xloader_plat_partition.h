/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * Description: the partition table.
 */

#ifndef _CHANGSHA_XLOADER_PLAT_PARTITION_H_
#define _CHANGSHA_XLOADER_PLAT_PARTITION_H_

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
    {PART_FW_DDR_LPCTRL,     (10 * 1024 + 384),          320, UFS_PART_3}, /* fw_ddr_lpctrl      320KB p7 */
    {PART_DDR_XPU_BOOT0,     (10 * 1024 + 704),          320, UFS_PART_3}, /* ddr_xpu_boot0      320KB p8 */
    {PART_DDR_XPU_BOOT1,         11 * 1024,          320, UFS_PART_3}, /* ddr_xpu_boot1      320KB p9 */
    {PART_DDR_XPU_BOOT2,     (11 * 1024 + 320),          320, UFS_PART_3}, /* ddr_xpu_boot2      320KB p10 */
    {PART_UCE,               (11 * 1024 + 640),          160, UFS_PART_3}, /* uce                160KB p11 */
    {PART_FW_MEDIA_LPCTRL,   (11 * 1024 + 800),          128, UFS_PART_3}, /* fw_media_lpctrl    128KB p12 */
    {PART_DACC,              (21 * 1024 + 928),          256, UFS_PART_3}, /* dacc               256KB p15 */
    {PART_DACC_AAE,          (22 * 1024 + 160),          256, UFS_PART_3}, /* dacc_aae           256KB p16 */
    {PART_HISEE_IMG,         (22 * 1024 + 928),     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p18 */
    {PART_FASTBOOT,          (30 * 1024 + 928),    12 * 1024, UFS_PART_3}, /* fastboot            12MB p20 */
    {PART_VECTOR,            (42 * 1024 + 928),     4 * 1024, UFS_PART_3}, /* vector               4MB p21 */
    {PART_VRL,               (1 * 1024 + 512),          512, UFS_PART_5}, /* vrl                512KB p2 */
    {PART_VRL_BACKUP,             2 * 1024,          512, UFS_PART_5}, /* vrl_backup         512KB p3 */
    {PART_NVME,                  11 * 1024,     4 * 1024, UFS_PART_5}, /* nvme                 4MB p5 */
    {PART_DDR_PARA,             228 * 1024,     1 * 1024, UFS_PART_5}, /* ddr_para          1024KB p15 */
    {PART_DFX,                  555 * 1024,    16 * 1024, UFS_PART_5}, /* dfx                 16MB p22 */
    {PART_MISC,                 553 * 1024,     2 * 1024, UFS_PART_5}, /* misc                 2MB p21 */
    {PART_DDR_FAC_INFO,         708 * 1024,     1 * 1024, UFS_PART_5}, /* ddr_fac_info      1024KB p27 */
    {PART_DVFS,                 709 * 1024,     1 * 1024, UFS_PART_5}, /* dvfs              1024KB p28 */
    {PART_HISEE_FS,             710 * 1024,     8 * 1024, UFS_PART_5}, /* hisee_fs             8MB p29 */
#ifdef FACTORY_VERSION
    {PART_HIBENCH_IMG,        13406 * 1024,    12 * 1024, UFS_PART_5}, /* hibench_img         12MB p37 */
    {PART_HIBENCH_DATA,       13418 * 1024,  2048 * 1024, UFS_PART_5}, /* hibench_data      2048MB p38 */
    {PART_HIBENCH_LOG,        15466 * 1024,    32 * 1024, UFS_PART_5}, /* hibench_log         32MB p39 */
    {PART_XLOADER_HITEST,     15498 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p40 */
    {PART_FLASH_AGEING,       15500 * 1024,   512 * 1024, UFS_PART_5}, /* flash_ageing       512MB p41 */
#endif
#ifdef CONFIG_PARTITION_ENG
    {PART_FTTEST,             16860 * 1024,    12 * 1024, UFS_PART_5}, /* fttest              12MB p37 */
    {PART_XLOADER_HITEST,     16872 * 1024,     2 * 1024, UFS_PART_5}, /* xloader_hitest       2MB p38 */
    {PART_DDRTEST,            16874 * 1024,    48 * 1024, UFS_PART_5}, /* ddrtest             48MB p39 */
#endif
    {"0", 0, 0, 0},
};

#endif
