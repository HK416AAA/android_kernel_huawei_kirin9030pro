/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include "hvgr_platform_api.h"

void __attribute__((weak)) hvgr_platform_reset(struct hvgr_device *gdev)
{
	return;
}

void __attribute__((weak)) hvgr_platform_enable_icg_clk(struct hvgr_device *gdev)
{
	return;
}
