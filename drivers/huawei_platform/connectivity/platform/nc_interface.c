/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: This module is to support near communication interface for kernel.
 * Create: 2025-07-14
 */

#include <huawei_platform/connectivity/nc_interface.h>
#include <linux/interrupt.h>

void nc_do_softirq(void)
{
	do_softirq();
}
EXPORT_SYMBOL(nc_do_softirq);
