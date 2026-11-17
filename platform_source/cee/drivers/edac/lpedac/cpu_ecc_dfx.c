/*
 * cpu_ecc_dfx.c
 *
 * CPU ECC DFX API
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include <linux/string.h>
#include "ras_common.h"
#include "cpu_ecc_dfx.h"

unsigned int g_cpu_pll_source[FREQ_DOMAIN_MAX] = {0};

bool is_l3_ecc(char* str)
{
	char* l3_instance_name = "share_l3";
	return (strstr(str, l3_instance_name) == NULL) ? false : true;
}

static void cpu_ecc_dfx_info_parse(unsigned int cluster, int **dfx_info)
{
	int type;
	struct dfx_info_shift_mask {
		unsigned int shift;
		unsigned int mask;
	} dfx_shift_mask[] = {
		{CPU_FREQ_SHIFT, CPU_FREQ_MASK},
		{CPU_VDDP_SHIFT, CPU_VDDP_MASK},
		{CPU_VDDC_SHIFT, CPU_VDDC_MASK},
		{CPU_TEMP_SHIFT, CPU_TEMP_MASK},
	};
	u64 _cpu_ecc_dfx_info     = _read_cpu_ecc_dfx_info(cluster);
	unsigned int temp_flag    = (_cpu_ecc_dfx_info >> CPU_TEMP_SYMBOL_SHIFT) & CPU_TEMP_SYMBOL_MASK;

	g_cpu_pll_source[cluster] = (unsigned int)((_cpu_ecc_dfx_info >> CPU_PLL_SOURCE_SHIFT) & CPU_PLL_SOURCE_MASK);

	if (IS_ERR_OR_NULL(dfx_info)) {
		pr_err("[%s %d] dfx_info is NULL\n", __func__, __LINE__);
		return;
	}

	for (type = RAS_CPU_DFX_FREQ; type < RAS_CPU_DFX_INFO_TYPE_CNT; type++) {
		*dfx_info[type] = (int)((_cpu_ecc_dfx_info >> dfx_shift_mask[type].shift) & dfx_shift_mask[type].mask);
		if ((type == RAS_CPU_DFX_TEMPERATURE) && (temp_flag == LOW_TEMP))
			*dfx_info[type] = 0 - *dfx_info[type];
	}
}

void read_cpu_ecc_dfx_info(struct cpu_ecc_dfx_info *info, unsigned int cpuid, char *instance_name)
{
	int *dfx_info[RAS_CPU_DFX_INFO_TYPE_CNT] = {
		&(info->freq_mhz), &(info->logic_volt), &(info->mem_volt), &(info->temp)};

	if (IS_ERR_OR_NULL(info) || IS_ERR_OR_NULL(instance_name)) {
		pr_err("[%s %d] info or instance_name is NULL\n", __func__, __LINE__);
		return;
	}

	info->cluster = is_l3_ecc(instance_name) ? (FREQ_DOMAIN_MAX - 1) : topology_physical_package_id(cpuid);
	cpu_ecc_dfx_info_parse(info->cluster, dfx_info);
}
