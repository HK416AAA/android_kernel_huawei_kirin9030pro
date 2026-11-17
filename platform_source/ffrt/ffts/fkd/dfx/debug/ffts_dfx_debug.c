/*
 * ffts_dfx_debug.c
 *
 * about ffts dfx debug
 *
 * Copyright (c) 2012-2020 Huawei Technologies Co., Ltd.
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
#include "ffts_dfx_debug.h"

#include <securec.h>
#include <linux/io.h>

#include "ffts_platform.h"
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"
#include "ffts_log.h"

#define FFTS_DEBUG_INFO_MAX 4

static uint32_t g_debug_info[FFTS_DEBUG_INFO_MAX];
static struct mutex g_debug_info_lock;

void ffts_debug_info_init(void)
{
	mutex_init(&g_debug_info_lock);
}

void ffts_debug_info_deinit(void)
{
	mutex_destroy(&g_debug_info_lock);
}

static void ffts_set_debug_addr(vir_addr_t ffts_reg_base, u16 debug_cfg_addr)
{
	SOC_FFTS_DEBUG_ADDR_UNION debug_addr_val = {0};
	SOC_FFTS_DEBUG_RD_EN_UNION debug_rd_en = {0};

	debug_addr_val.reg.dbg_cfg_addr = debug_cfg_addr;
	writel(debug_addr_val.value, (volatile void *)(uintptr_t)SOC_FFTS_DEBUG_ADDR_ADDR(ffts_reg_base));

	debug_rd_en.reg.dbg_cfg_rd = 1;
	writel(debug_rd_en.value, (volatile void *)(uintptr_t)SOC_FFTS_DEBUG_RD_EN_ADDR(ffts_reg_base));
}

static int ffts_print_debug_info(u16 debug_cfg_addr)
{
	vir_addr_t ffts_reg_base;
	int read_wait_times = 1000;
	uint32_t debug_st = 0;

	ffts_reg_base = ffts_get_reg_base();
	cond_return_error(ffts_reg_base == 0, -EINVAL, "get reg base failed\n");

	mutex_lock(&g_debug_info_lock);
	ffts_set_debug_addr(ffts_reg_base, debug_cfg_addr);

	while(read_wait_times-- > 0) {
		// read debug st
		debug_st = readl((const volatile void *)(uintptr_t)SOC_FFTS_DEBUG_ST_ADDR(ffts_reg_base));
		if (debug_st == 1) {
			ffts_drv_warn("ffts read dbg data vld");
			break;
		}
	}

	cond_goto_error(debug_st == 0, error, debug_st, debug_st,
		"ffts read dbg data invalid\n");

	g_debug_info[0] = readl((const volatile void *)(uintptr_t)SOC_FFTS_DEBUG_INFO0_ADDR(ffts_reg_base));
	g_debug_info[1] = readl((const volatile void *)(uintptr_t)SOC_FFTS_DEBUG_INFO1_ADDR(ffts_reg_base));
	g_debug_info[2] = readl((const volatile void *)(uintptr_t)SOC_FFTS_DEBUG_INFO2_ADDR(ffts_reg_base));
	g_debug_info[3] = readl((const volatile void *)(uintptr_t)SOC_FFTS_DEBUG_INFO3_ADDR(ffts_reg_base));

	ffts_drv_info("ffts debug addr %u, debug_info %u %u %u %u",
		debug_cfg_addr, g_debug_info[0], g_debug_info[1], g_debug_info[2], g_debug_info[3]);

	mutex_unlock(&g_debug_info_lock);
	return 0;
error:
	mutex_unlock(&g_debug_info_lock);
	return -EINVAL;
}

uint32_t ffts_get_debug_info(u16 debug_cfg_addr, u16 debug_info_index)
{
	if (debug_info_index >= FFTS_DEBUG_INFO_MAX) {
		ffts_drv_err("debug info index is invalid, val[%u]", debug_info_index);
		return 0;
	}
	ffts_print_debug_info(debug_cfg_addr);
	return g_debug_info[debug_info_index];
}

void ffts_get_whole_debug_info(u16 debug_cfg_addr, u32 *debug_info)
{
	int i;
	ffts_print_debug_info(debug_cfg_addr);
	for (i = 0; i < FFTS_DEBUG_INFO_MAX; i++)
		debug_info[i] = g_debug_info[i];
}