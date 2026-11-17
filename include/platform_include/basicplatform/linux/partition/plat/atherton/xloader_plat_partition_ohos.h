/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * Description: the partition table.
 */

#ifndef _SCORPIO_XLOADER_PARTITION_H_
#define _SCORPIO_XLOADER_PARTITION_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"


#define XLOADER3_VRL_INDEX_A    19
#define BL2_VRL_INDEX           31
#define FASTBOOT_VRL_INDEX_A    42
#define VECTOR_VRL_INDEX_A      43

static const struct partition partition_table_emmc[] = {
    {PART_XLOADER,                0,             2 * 1024,    EMMC_BOOT_MAJOR_PART},
    {PART_RESERVED1,              7 * 1024,         1536, EMMC_USER_PART}, /* reserved1         1536KB p3 */
    {PART_VRL,                        8704,          512, EMMC_USER_PART}, /* vrl                512KB p4 */
    {PART_VRL_BACKUP,             9 * 1024,          512, EMMC_USER_PART}, /* vrl_backup         512KB p5 */
    {PART_NVME,                  18 * 1024,     5 * 1024, EMMC_USER_PART}, /* nvme                 5MB p7 */
    {PART_DDR_PARA,             235 * 1024,     1 * 1024, EMMC_USER_PART}, /* ddr_para          1024KB p16 */
    {PART_LOWPOWER_PARA,        236 * 1024,     1 * 1024, EMMC_USER_PART}, /* lowpower_para     1024KB p17 */
    {PART_DACC,                 238 * 1024,          512, EMMC_USER_PART}, /* dacc               512KB p19 */
    {PART_DFX,                  343 * 1024,    16 * 1024, EMMC_USER_PART}, /* dfx                 16MB p24 */
    {PART_BL2,                  500 * 1024,     4 * 1024, EMMC_USER_PART}, /* bl2                  4MB p30 */
    {PART_FW_LPM3,              504 * 1024,          512, EMMC_USER_PART}, /* fw_lpm3            512KB p31 */
    {PART_FW_CPU_LPCTRL,       (504 * 1024 + 512),   256, EMMC_USER_PART}, /* fw_cpu_lpctrl      256KB p32 */
    {PART_FW_GPU_LPCTRL,       (504 * 1024 + 768),   128, EMMC_USER_PART}, /* fw_gpu_lpctrl      128KB p33 */
    {PART_FW_DDR_LPCTRL,       (504 * 1024 + 896),   128, EMMC_USER_PART}, /* fw_ddr_lpctrl      128KB p34 */
    {PART_HISEE_IMG,            516 * 1024,     4 * 1024, EMMC_USER_PART}, /* hisee_img            4MB p38 */
    {PART_HISEE_FS,             524 * 1024,     8 * 1024, EMMC_USER_PART}, /* hisee_fs             8MB p40 */
    {PART_FASTBOOT,             532 * 1024,    12 * 1024, EMMC_USER_PART}, /* fastboot            12MB p41 */
    {PART_VECTOR,               544 * 1024,     4 * 1024, EMMC_USER_PART}, /* vector               4MB p42 */
    {PART_FW_HIFI,              564 * 1024,    12 * 1024, EMMC_USER_PART}, /* fw_hifi             12MB p45 */
#ifdef FACTORY_VERSION
    {PART_SENSORHUB,           1250 * 1024,   125 * 1024, EMMC_USER_PART}, /* sensorhub          125MB p80 */
    {PART_SENSORHUB_LOG_DIC,   1375 * 1024,     3 * 1024, EMMC_USER_PART}, /* sensorhub_log_dic    3MB p80 */
    {PART_HIBENCH_IMG,         5594 * 1024,    40 * 1024, EMMC_USER_PART}, /* hibench_img         40MB p88 */
    {PART_HIBENCH_LOG,         6746 * 1024,    32 * 1024, EMMC_USER_PART}, /* hibench_log         32MB p91 */
#else
    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, EMMC_USER_PART}, /* sensorhub          597MB p80 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, EMMC_USER_PART}, /* sensorhub_log_dic    3MB p80 */
#endif
#ifdef CONFIG_PARTITION_ENG
    {PART_FTTEST,              7766 * 1024,   192 * 1024, EMMC_USER_PART}, /* fttest             192MB p91 */
    {PART_DDRTEST,             7958 * 1024,    48 * 1024, EMMC_USER_PART}, /* ddrtest             48MB p92 */
    {PART_HIBENCH_LPM3,        8006 * 1024,     2 * 1024, EMMC_USER_PART}, /* hibench_lpm3         2MB p93 */
#endif
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                0,             2 * 1024,    UFS_PART_0},
    {PART_VRL,                        8704,          512, UFS_PART_3}, /* vrl                512KB p4 */
    {PART_VRL_BACKUP,             9 * 1024,          512, UFS_PART_3}, /* vrl_backup         512KB p5 */
    {PART_NVME,                  18 * 1024,     5 * 1024, UFS_PART_3}, /* nvme                 5MB p7 */
    {PART_DDR_PARA,             235 * 1024,     1 * 1024, UFS_PART_3}, /* ddr_para          1024KB p16 */
    {PART_LOWPOWER_PARA,        236 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para     1024KB p17 */
    {PART_DACC,                 238 * 1024,          512, UFS_PART_3}, /* dacc               512KB p19 */
    {PART_DFX,                  343 * 1024,    16 * 1024, UFS_PART_3}, /* dfx                 16MB p24 */
    {PART_BL2,                  500 * 1024,     4 * 1024, UFS_PART_3}, /* bl2                  4MB p30 */
    {PART_FW_LPM3,              504 * 1024,          512, UFS_PART_3}, /* fw_lpm3            512KB p31 */
    {PART_FW_CPU_LPCTRL,       (504 * 1024 + 512),   256, UFS_PART_3}, /* fw_cpu_lpctrl      256KB p32 */
    {PART_FW_GPU_LPCTRL,       (504 * 1024 + 768),   128, UFS_PART_3}, /* fw_gpu_lpctrl      128KB p33 */
    {PART_FW_DDR_LPCTRL,       (504 * 1024 + 896),   128, UFS_PART_3}, /* fw_ddr_lpctrl      128KB p34 */
    {PART_HISEE_IMG,            516 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p38 */
    {PART_HISEE_FS,             524 * 1024,     8 * 1024, UFS_PART_3}, /* hisee_fs             8MB p40 */
    {PART_FASTBOOT,             532 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p41 */
    {PART_VECTOR,               544 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p42 */
    {PART_FW_HIFI,              564 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi             12MB p45 */
#ifdef FACTORY_VERSION
    {PART_SENSORHUB,           1250 * 1024,   125 * 1024, UFS_PART_3}, /* sensorhub          125MB p80 */
    {PART_SENSORHUB_LOG_DIC,   1375 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p80 */
    {PART_HIBENCH_IMG,         5594 * 1024,    40 * 1024, UFS_PART_3}, /* hibench_img         40MB p88 */
    {PART_HIBENCH_LOG,         6746 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p91 */
#else
    {PART_SENSORHUB,           1250 * 1024,   597 * 1024, UFS_PART_3}, /* sensorhub          597MB p80 */
    {PART_SENSORHUB_LOG_DIC,   1847 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p80 */
#endif
#ifdef CONFIG_PARTITION_ENG
    {PART_FTTEST,              7766 * 1024,   192 * 1024, UFS_PART_3}, /* fttest             192MB p91 */
    {PART_DDRTEST,             7958 * 1024,    48 * 1024, UFS_PART_3}, /* ddrtest             48MB p92 */
    {PART_HIBENCH_LPM3,        8006 * 1024,     2 * 1024, UFS_PART_3}, /* hibench_lpm3         2MB p93 */
#endif
    {"0", 0, 0, 0},
};

#endif
