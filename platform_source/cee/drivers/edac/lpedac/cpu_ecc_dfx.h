/*
 * cpu_ecc_dfx.h
 *
 * CPU ECC DFX HEAD
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
#ifndef __CPU_ECC_DFX_H__
#define __CPU_ECC_DFX_H__

#include <cpu_cluster_def.h>

#ifndef unused
#define unused(x) ((void)(x))
#endif

#define CPU_FREQ_SHIFT 0
#define CPU_VDDP_SHIFT 16
#define CPU_VDDC_SHIFT 28
#define CPU_TEMP_SHIFT 40
#define CPU_TEMP_SYMBOL_SHIFT 48
#define CPU_PLL_SOURCE_SHIFT  49

#define CPU_FREQ_MASK 0xffff
#define CPU_VDDP_MASK 0xfff
#define CPU_VDDC_MASK 0xfff
#define CPU_TEMP_MASK 0xff
#define CPU_TEMP_SYMBOL_MASK 0x1
#define CPU_PLL_SOURCE_MASK  0x1

#define LOW_TEMP 1

enum ras_cpu_dfx_info_type {
	RAS_CPU_DFX_FREQ = 0,
	RAS_CPU_DFX_LOGIC_VOLT,
	RAS_CPU_DFX_MEM_VOLT,
	RAS_CPU_DFX_TEMPERATURE,
	RAS_CPU_DFX_INFO_TYPE_CNT,
};

struct cpu_ecc_dfx_info {
	int cluster;
	int freq_mhz;
	int logic_volt;
	int mem_volt;
	int temp;
};

extern unsigned int g_cpu_pll_source[FREQ_DOMAIN_MAX];

bool is_l3_ecc(char* str);

#ifdef CONFIG_RAS_EDAC_BL31
u64 _read_cpu_ecc_dfx_info(u64 cluster);
#else
static inline u64 _read_cpu_ecc_dfx_info(u64 cluster)
{
	u64 ret = 0;

	unused(cluster);

	return ret;
}
#endif
void read_cpu_ecc_dfx_info(struct cpu_ecc_dfx_info *info, unsigned int cpuid, char *instance_name);
#endif /* __CPU_ECC_DFX_H__ */
