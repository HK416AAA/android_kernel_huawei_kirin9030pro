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

#define POWER_BIN_LOW_MASK           BIT(0)
#define POWER_BIN_MID_MASK           (BIT(0) | BIT(1))
#define POWER_BIN_HIGH_MASK          (BIT(0) | BIT(1) | BIT(2))

#define BIN_1_POWER_START_BIT      18
#define BIN_1_POWER_BIT_CNT        3
#define BIN_1_POWER_GROUP          EFUSE_KERNEL_PARTIALGOOD_FLAG1

#define BIN_13_POWER_START_BIT     50
#define BIN_13_POWER_BIT_CNT       1
#define BIN_13_POWER_GROUP         EFUSE_KERNEL_PARTIALGOOD_FLAG8

#define BIN_7_POWER_START_BIT      812
#define BIN_7_POWER_BIT_CNT        3
#define BIN_7_POWER_GROUP          EFUSE_KERNEL_PARTIALGOOD_FLAG8

#define IS_BIN13_CHIP_START_BIT    137
#define IS_BIN13_CHIP_BIT_CNT      1
#define IS_BIN13_CHIP_GROUP        EFUSE_KERNEL_PARTIALGOOD_FLAG1

enum {
	EFUSE_BIN1_POWER = 0,
	EFUSE_BIN13_POWER,
	EFUSE_BIN7_POWER,
	EFUSE_IS_BIN13_CHIP,

	EFUSE_MAX_NR,
};

unsigned int efuse_item[EFUSE_MAX_NR][3] = {
	{ BIN_1_POWER_START_BIT,  BIN_1_POWER_BIT_CNT,  BIN_1_POWER_GROUP },
	{ BIN_13_POWER_START_BIT, BIN_13_POWER_BIT_CNT, BIN_13_POWER_GROUP },
	{ BIN_7_POWER_START_BIT,  BIN_7_POWER_BIT_CNT,  BIN_7_POWER_GROUP },
	{ IS_BIN13_CHIP_START_BIT,  IS_BIN13_CHIP_BIT_CNT,  IS_BIN13_CHIP_GROUP },
};

enum {
	POWER_UNDEFINED = 0,
	POWER_LEVEL_1,
	POWER_LEVEL_2,
	POWER_LEVEL_3,

	POWER_LEVEL_NR,
};

enum {
	CHIP_TYPE = 0,
	CPUB_CORE,
	CPUM_CORE,
	CPUL_CORE,
	CPUB_FREQ,
	GPU_CORE,

	SOC_PG_TYPE_NR,
};

int soc_pg_type_index[SOC_PG_TYPE_NR] = {
	SOC_COMPONENT_CHIP_TYPE_INFO,
	SOC_COMPONENT_CPUB_CORE_INFO,
	SOC_COMPONENT_CPUM_CORE_INFO,
	SOC_COMPONENT_CPUL_CORE_INFO,
	SOC_COMPONENT_CPUB_FREQ_INFO,
	SOC_COMPONENT_GPU_CORE_INFO,
};

#define CHIP_TYPE_NR  4
static unsigned int soc_energy_level[CHIP_TYPE_NR][POWER_LEVEL_NR] = {
	{ENERGY_LV_N, ENERGY_LV_N, ENERGY_LV_N, ENERGY_LV_N},
	{ENERGY_LV_N, ENERGY_LV_1, ENERGY_LV_2, ENERGY_LV_3},
	{ENERGY_LV_N, ENERGY_LV_2, ENERGY_LV_2, ENERGY_LV_4},
	{ENERGY_LV_N, ENERGY_LV_1, ENERGY_LV_2, ENERGY_LV_3},
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

static bool check_is_bin13_chip(void)
{
	u32 efuse = 0;
	int ret;
	bool is_bin13_chip = false;

	ret = get_efuse_by_item(&efuse, EFUSE_IS_BIN13_CHIP);
	if (ret) {
		pr_err("%s:get efuse failed\n", __func__);
		return false;
	}

	return efuse ? false : true;
}

static int get_soc_pg_type_by_index(int id)
{
	struct soc_component_pg_info info = {0};

	get_soc_pg_info_by_index(id, &info);

	if (id == SOC_COMPONENT_CHIP_TYPE_INFO) {
		if (info.tailor_strategy == SOC_SPEC_LEVEL1 && check_is_bin13_chip()) {
			return SOC_SPEC_LEVEL1_VOLT_INCR;
		}
	}	

	return info.tailor_strategy;
}

static unsigned int get_bin1_chip_power_type(void)
{
	u32 efuse;
	int ret;
	unsigned int power_type;

	ret = get_efuse_by_item(&efuse, EFUSE_BIN1_POWER);
	if (ret) {
		pr_err("%s:get efuse failed\n", __func__);
		power_type = POWER_UNDEFINED;
		return power_type;
	}

	if (efuse == POWER_BIN_HIGH_MASK)
		power_type = POWER_LEVEL_1;
	else if (efuse == POWER_BIN_MID_MASK)
		power_type = POWER_LEVEL_2;
	else if (efuse == POWER_BIN_LOW_MASK)
		power_type = POWER_LEVEL_3;
	else
		power_type = POWER_UNDEFINED;

	return power_type;
}

static unsigned int get_bin13_chip_power_type(void)
{
	u32 efuse;
	int ret;
	unsigned int power_type;

	ret = get_efuse_by_item(&efuse, EFUSE_BIN13_POWER);
	if (ret) {
		pr_err("%s:get efuse failed\n", __func__);
		power_type = POWER_UNDEFINED;
		return power_type;
	}

	if (efuse)
		power_type = POWER_LEVEL_3;
	else
		power_type = POWER_LEVEL_1;

	return power_type;
}

static unsigned int get_bin7_chip_power_type(void)
{
	u32 efuse;
	int ret;
	unsigned int power_type;

	ret = get_efuse_by_item(&efuse, EFUSE_BIN7_POWER);
	if (ret) {
		pr_err("%s:get efuse failed\n", __func__);
		power_type = POWER_UNDEFINED;
		return power_type;
	}

	if (efuse == POWER_BIN_HIGH_MASK)
		power_type = POWER_LEVEL_1;
	else if (efuse == POWER_BIN_MID_MASK)
		power_type = POWER_LEVEL_2;
	else if (efuse == POWER_BIN_LOW_MASK)
		power_type = POWER_LEVEL_3;
	else
		power_type = POWER_UNDEFINED;

	return power_type;
}

void get_soc_power_type(unsigned int *power_type)
{
	unsigned int chip_type;

	if (!power_type) {
		pr_err("%s: power type addr is NULL\n", __func__);
		return;
	}

	chip_type = get_soc_pg_type_by_index(SOC_COMPONENT_CHIP_TYPE_INFO);
	if (chip_type == SOC_SPEC_LEVEL1)
		*power_type = get_bin1_chip_power_type();
	else if (chip_type == SOC_SPEC_LEVEL1_VOLT_INCR)
		*power_type = get_bin13_chip_power_type();
	else if (chip_type == SOC_SPEC_PHONE)
		*power_type = get_bin7_chip_power_type();
	else
		*power_type = POWER_UNDEFINED;
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
	int i;

	if (chip_type >= CHIP_TYPE_NR || power_type >= POWER_LEVEL_NR) {
		pr_err("%s:input is invliad\n", __func__);
		return ENERGY_LV_N;
	}

	return soc_energy_level[chip_type][power_type];
}

bool get_soc_is_bottom_power(void)
{
	unsigned int chip_type = soc_pg_type[SOC_COMPONENT_CHIP_TYPE_INFO];

	if (((soc_power_type == POWER_LEVEL_2 || soc_power_type == POWER_LEVEL_3) &&
	     (chip_type == SOC_SPEC_LEVEL1 || chip_type == SOC_SPEC_PHONE)) ||
	      chip_type == SOC_SPEC_LEVEL1_VOLT_INCR) {
		return true;
	}

	return false;
}

