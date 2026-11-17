// SPDX-License-Identifier: GPL-2.0
/*
 * sched_chip_info.h
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

#ifndef __SCHED_CHIP_INFO_H
#define __SCHED_CHIP_INFO_H

enum {
	ENERGY_LV_N = 0,
	ENERGY_LV_1,
	ENERGY_LV_2,
	ENERGY_LV_3,
	ENERGY_LV_4,
};

#define PG_TYPE_MAX_NR 10

extern unsigned int soc_power_type;
extern unsigned int soc_pg_type[PG_TYPE_MAX_NR];

void get_soc_power_type(unsigned int *power_type);
void get_soc_pg_type(unsigned int pg_type[], unsigned int *pg_nr);
unsigned int get_soc_energy_level(unsigned int chip_type, unsigned int power_type);
#endif
