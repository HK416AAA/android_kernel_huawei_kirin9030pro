/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include "hvgr_platform_api.h"

void __attribute__((weak)) hvgr_platform_enable_ecc(struct hvgr_device *gdev)
{
	return;
}

int __attribute__((weak)) hvgr_platform_tbu_init(struct hvgr_device *gdev)
{
	return 0;
}
