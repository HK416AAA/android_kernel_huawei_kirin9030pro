/*
 * ffts_platform_pm.c
 *
 * ffts platform pm
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
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
#include "ffts_platform_pm.h"

#include <linux/kernel.h>
#include "platform_include/see/ffa/ffa_msg_id.h"

#include "tzsp/ffts_tzsp.h"
#include "dfx/ffts_log.h"

static int g_ffts_powerstage = 0;

#define FFTS_POWERSTAGE_DOWN 0
#define FFTS_POWERSTAGE_UP 1

int ffts_plat_pm_powerup(uint32_t mode)
{
	int ret = 0;

	if (g_ffts_powerstage == FFTS_POWERSTAGE_UP)
	{
		ffts_drv_warn("ffts has power up\n");
		return 0;
	}
	ffts_drv_info("befor ffts powerup");
	ret = tzsp_service_ffts_smc(FFTS_POWER_UP, mode, 0, 0);
	if (ret != 0) {
		ffts_drv_err("ffts powerup fail, ret = 0x%x\n", ret);
		return ret;
	}
	ffts_drv_info("after ffts powerup");
	g_ffts_powerstage = FFTS_POWERSTAGE_UP;
	ffts_drv_info("power up succeed\n");
	return ret;
}

int ffts_plat_pm_powerdown(void)
{
	int ret = 0;
	if (g_ffts_powerstage == FFTS_POWERSTAGE_DOWN) {
		ffts_drv_warn("ffts has power down\n");
		return 0;
	}

	ret = tzsp_service_ffts_smc(FFTS_POWER_DOWN, 0, 0, 0);
	if (ret != 0) {
		ffts_drv_err("ffts powerdown fail, ret = 0x%x\n", ret);
		return ret;
	}
	g_ffts_powerstage = FFTS_POWERSTAGE_DOWN;
	ffts_drv_info("power down succeed\n");
	return ret;
}