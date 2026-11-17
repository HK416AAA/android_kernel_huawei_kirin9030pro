// SPDX-License-Identifier: GPL-2.0
/*
 * sched_chip_info_plat.c
 *
 * Copyright (c) 2025-2026 Huawei Technologies Co., Ltd.
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

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/fs.h>
#include <linux/kernel.h>

#include <platform_include/see/efuse_driver.h>
#include <platform_include/basicplatform/linux/soc_spec.h>
#include <platform_include/basicplatform/linux/dfx_cmdline_parse.h>

#include "sched_chip_info.h"

#define POWER_BIN_LOW_MASK        BIT(0)
#define POWER_BIN_MID_MASK        (BIT(0) | BIT(1))
#define POWER_BIN_HIGH_MASK       (BIT(0) | BIT(1) | BIT(2))

#define IS_FG_CHIP_START_BIT      2
#define IS_FG_CHIP_BIT_CNT        1
#define IS_FG_CHIP_GROUP          EFUSE_KERNEL_PARTIALGOOD_FLAG1

#define IS_TURBO_CHIP_START_BIT   127
#define IS_TURBO_CHIP_BIT_CNT     1
#define IS_TURBO_CHIP_GROUP       EFUSE_KERNEL_PARTIALGOOD_FLAG1

#define TURBO_POWER_START_BIT     91
#define TURBO_POWER_BIT_CNT       3
#define TURBO_POWER_GROUP         EFUSE_KERNEL_PARTIALGOOD_FLAG1

#define NO_TURBO_POWER_START_BIT  126
#define NO_TURBO_POWER_BIT_CNT    1
#define NO_TURBO_POWER_GROUP      EFUSE_KERNEL_PARTIALGOOD_FLAG8

enum {
	EFUSE_IS_FG_CHIP = 0,
	EFUSE_IS_TURBO_CHIP,
	EFUSE_TURBO_POWER,
	EFUSE_NO_TURBO_POWER,

	EFUSE_MAX_NR,
};

unsigned int efuse_item[EFUSE_MAX_NR][3] = {
	{ IS_FG_CHIP_START_BIT,     IS_FG_CHIP_BIT_CNT,     IS_FG_CHIP_GROUP },
	{ IS_TURBO_CHIP_START_BIT,  IS_TURBO_CHIP_BIT_CNT,  IS_TURBO_CHIP_GROUP },
	{ TURBO_POWER_START_BIT,    TURBO_POWER_BIT_CNT,    TURBO_POWER_GROUP },
	{ NO_TURBO_POWER_START_BIT, NO_TURBO_POWER_BIT_CNT, NO_TURBO_POWER_GROUP },
};

enum {
	POWER_UNDEFINED = 0,
	POWER_TURBO_GOOD,
	POWER_TURBO_MID,
	POWER_TURBO_BAD,
	POWER_NO_TURBO_GOOD,
	POWER_NO_TURBO_BAD,
};

enum {
	CHIP_TYPE = 0,
	CPUB_CORE,
	CPUM_CORE,
	CPUL_CORE,
	CPUB_FREQ,
	CPUM_FREQ,
	CPUL_FREQ,
	GPU_CORE,

	SOC_PG_TYPE_NR,
};

int soc_pg_type_index[SOC_PG_TYPE_NR] = {
	SOC_COMPONENT_CHIP_TYPE_INFO,
	SOC_COMPONENT_CPUB_CORE_INFO,
	SOC_COMPONENT_CPUM_CORE_INFO,
	SOC_COMPONENT_CPUL_CORE_INFO,
	SOC_COMPONENT_CPUB_FREQ_INFO,
	SOC_COMPONENT_CPUM_FREQ_INFO,
	SOC_COMPONENT_CPUL_FREQ_INFO,
	SOC_COMPONENT_GPU_CORE_INFO,
};

static int get_efuse_by_item(u32 *efuse, unsigned int idx)
{
	struct efuse_desc desc;

	*efuse = 0;
	desc.buf = efuse;
	desc.buf_size = 1;
	desc.start_bit = efuse_item[idx][0];
	desc.bit_cnt = efuse_item[idx][1];
	desc.item_vid = efuse_item[idx][2];

	if (efuse_read_value_t(&desc) != EFUSE_OK)
		return -EINVAL;

	pr_info("%s:idx is %u, efuse is %u\n", __func__, idx, *efuse);
	return 0;
}

static unsigned int get_turbo_chip_power_type(void)
{
	u32 efuse;
	int ret;
	unsigned int power_type;

	ret = get_efuse_by_item(&efuse, EFUSE_TURBO_POWER);
	if (ret) {
		pr_err("%s:get efuse failed\n", __func__);
		power_type = POWER_TURBO_GOOD;
		return power_type;
	}

	if (efuse == POWER_BIN_HIGH_MASK)
		power_type = POWER_TURBO_GOOD;
	else if (efuse == POWER_BIN_MID_MASK)
		power_type = POWER_TURBO_MID;
	else if (efuse == POWER_BIN_LOW_MASK)
		power_type = POWER_TURBO_BAD;
	else
		power_type = POWER_TURBO_GOOD;

	return power_type;
}

static unsigned int get_no_turbo_chip_power_type(void)
{
	u32 efuse;
	int ret;
	unsigned int power_type;

	ret = get_efuse_by_item(&efuse, EFUSE_NO_TURBO_POWER);
	if (ret) {
		pr_err("%s:get efuse failed\n", __func__);
		power_type = POWER_NO_TURBO_GOOD;
		return power_type;
	}

	if (!efuse)
		power_type = POWER_NO_TURBO_GOOD;
	else 
		power_type = POWER_NO_TURBO_BAD;

	return power_type;
}

void get_soc_power_type(unsigned int *power_type)
{
	u32 efuse;
	int ret;

	if (!power_type)
		return;

	/*
	 * Step1, check chip is FG chip:
	 * if chip is not FG chip, power type is undefined.
	 */
	ret = get_efuse_by_item(&efuse, EFUSE_IS_FG_CHIP);
	if (ret) {
		pr_err("%s:get fg efuse failed\n", __func__);
		*power_type = POWER_UNDEFINED;
		return;
	}

	if (efuse == 0) {
		*power_type = POWER_UNDEFINED;
		return;
	}

	/*
	 * Step2, check chip whether TURBO chip, then get power type:
	 * if efuse = 1 means FG TURBO chip;
	 * if efuse = 0 means FG NO_TURBO chip;
	 */
	ret = get_efuse_by_item(&efuse, EFUSE_IS_TURBO_CHIP);
	if (ret) {
		pr_err("%s:get turbo efuse failed\n", __func__);
		*power_type = POWER_UNDEFINED;
		return;
	}

	if (efuse) {
		*power_type = get_turbo_chip_power_type();
	} else {
		*power_type = get_no_turbo_chip_power_type();
	}
}

#ifdef CONFIG_SOC_PG_INFO
static int get_soc_pg_type_by_index(int id)
{
	struct soc_component_pg_info info = {0};

	get_soc_pg_info_by_index(id, &info);

	return info.tailor_strategy;
}

void get_soc_pg_type(unsigned int pg_type[], unsigned int *pg_nr)
{
	int i;

	if (!soc_pg_type || !pg_nr)
		return;

	if (SOC_PG_TYPE_NR > PG_TYPE_MAX_NR) {
		pr_err("%s:pg_type num is too large\n", __func__);
		return;
	}

	for (i = 0; i < SOC_PG_TYPE_NR; i++) {
		pg_type[i] = get_soc_pg_type_by_index(soc_pg_type_index[i]);
	}

	*pg_nr = SOC_PG_TYPE_NR;
}

unsigned int get_soc_energy_level(unsigned int chip_type, unsigned int power_type)
{
	return ENERGY_LV_N;
}

bool get_soc_is_bottom_power(void)
{
	unsigned int chip_type = soc_pg_type[SOC_COMPONENT_CHIP_TYPE_INFO];

	if ((soc_power_type == POWER_TURBO_BAD ||
	     soc_power_type == POWER_NO_TURBO_BAD) &&
	    (chip_type == SOC_SPEC_LEVEL1)) {
		return true;
	}
	return false;
}
#endif

