/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

#include "hvgr_platform_api.h"

bool __attribute__((weak)) hvgr_platform_need_clock_gating(void)
{
	return false;
}

void __attribute__((weak)) hvgr_platform_cbit_constraint_config(struct hvgr_device *gdev)
{
	return;
}

bool __attribute__((weak)) hvgr_platform_support_ebit(void)
{
	return false;
}

bool __attribute__((weak)) hvgr_platform_need_poweroff_bl(void)
{
	return true;
}
