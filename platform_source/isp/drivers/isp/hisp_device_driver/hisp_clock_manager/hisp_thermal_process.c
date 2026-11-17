/*
 * isp_thermal_process.c
 *
 * This is for isp temperature process
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include "platform_include/cee/linux/thermal_interact_lpmcu.h"
#include "hisp_internel.h"

static int hisp_lowtemp_process(unsigned int level)
{
	pr_info("device %s low temperature\n", level ? "into" : "out of");
	hisp_set_low_temp_flag(level);

	return 0;
}

static struct thermal_lpmcu_ops g_isp_thermal_ops = {
	.name = "hisp_lowtemp",
	.lowtemp_thermal_handler = hisp_lowtemp_process,
};

void hisp_thermal_init(void)
{
    if (thermal_lpmcu_ops_register(&g_isp_thermal_ops))
		pr_info("register thermal lpm failed\n");
	pr_info("register isp thermal lpm finish\n");
}

void hisp_thermal_deinit(void)
{
	thermal_lpmcu_ops_unregister(&g_isp_thermal_ops);
	pr_info("unregister isp thermal lpm finish\n");
}