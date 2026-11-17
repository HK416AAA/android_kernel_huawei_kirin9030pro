/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include "hvgr_platform_api.h"

int __attribute__((weak)) hvgr_platform_map_reg_addr(struct platform_device *pdev, struct hvgr_device *gdev)
{
	return 0;
}

void __attribute__((weak)) hvgr_platform_set_ffap1_drain_th(struct hvgr_device *gdev)
{
	return;
}
