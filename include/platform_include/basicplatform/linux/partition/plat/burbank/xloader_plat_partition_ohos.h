/*
 *  Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 *  Description: the partition table.
 */

#ifndef _SAGITTARIUS_XLOADER_PARTITION_OHOS_H_
#define _SAGITTARIUS_XLOADER_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"


#define XLOADER3_VRL_INDEX_A    19
#define BL2_VRL_INDEX           21
#define FASTBOOT_VRL_INDEX_A    37
#define VECTOR_VRL_INDEX_A      38

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                0,            2 * 1024, UFS_PART_0},
    {PART_RESERVED1,              7 * 1024,         1024, UFS_PART_2}, /* reserved1         1024KB p3 */
    {PART_VRL,                         512,          512, UFS_PART_3}, /* vrl                512KB p1 */
    {PART_VRL_BACKUP,                 1024,          512, UFS_PART_3}, /* vrl_backup         512KB p2 */
    {PART_NVME,                  10 * 1024,     5 * 1024, UFS_PART_3}, /* nvme                 5MB p4 */
    {PART_DDR_PARA,             223 * 1024,     1 * 1024, UFS_PART_3}, /* ddr_para          1024KB p12 */
    {PART_LOWPOWER_PARA,        224 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para     1024KB p13 */
    {PART_DFX,                  339 * 1024,    16 * 1024, UFS_PART_3}, /* dfx                 16MB p20 */
    {PART_BL2,                  226 * 1024,     4 * 1024, UFS_PART_3}, /* bl2                  4MB p15 */
    {PART_FASTBOOT,             512 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p31 */
    {PART_VECTOR,               524 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p32 */
#ifdef FACTORY_VERSION
    {PART_HIBENCH_IMG,        11942 * 1024,   128 * 1024, UFS_PART_3}, /* hibench_img        128MB p81 */
    {PART_HIBENCH_LOG,        12070 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p82 */
    {PART_HIBENCH_LPM3,       13126 * 1024,     2 * 1024, UFS_PART_3}, /* hibench_lpm3         2MB p85 */
#elif defined(CONFIG_PARTITION_ENG)
#ifdef CONFIG_HISI_DEBUG_FS
    {PART_FTTEST,             11942 * 1024,   192 * 1024, UFS_PART_3}, /* fttest             192MB p80 */
#endif
#ifdef XLOADER_DDR_TEST
    {PART_DDRTEST,            12134 * 1024,    48 * 1024, UFS_PART_3}, /* ddrtest             48MB p81 */
#endif
    {PART_XLOADER_HITEST,     14208 * 1024,     2 * 1024, UFS_PART_3}, /* xloader_hitest       2MB p106 */
#endif
    {"0", 0, 0, 0},
};

#endif
