/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2021.
 * All rights reserved.
 *
 * Description: This file is for the gpu smc process.
 * Author:
 * Create: 2021-02-03
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include "hvgr_platform_ffa.h"

#include <linux/delay.h>
#include <linux/hwspinlock.h>
#include "hvgr_platform_api.h"
#include "hvgr_ffa.h"

uint64_t hvgr_platform_crg_reset(struct hvgr_device *gdev)
{
	uint64_t ret;
	bool get_lock = false;

	ret = (uint64_t)hwspin_lock_timeout(gdev->read_cnt_hwlock, 10);
	if (ret != 0)
		dev_err(gdev->dev, "[HVGR_ERROR] e2ec0000 get hwlock failed!");
	else
		get_lock = true;

	ret = hvgr_ffa_call(gdev, HVGR_FFA_CRG_RESET, 0, 0);
	if (ret != 0)
		dev_err(gdev->dev, "[HVGR_ERROR] crg reset failed!");

	if (get_lock)
		hwspin_unlock(gdev->read_cnt_hwlock);
	return ret;
}
