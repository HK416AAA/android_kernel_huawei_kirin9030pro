/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2024. All rights reserved.
 */
#ifndef _LINUX_ECHUB_TURBO_CHARGE_H
#define _LINUX_ECHUB_TURBO_CHARGE_H

#include <linux/platform_device.h>

#define TURBO_CHG_ADAPTER_POWER               (90000)
#define QUICK_CHG_ADAPTER_POWER               (65000)

void echub_turbo_charge_sysfs_create_group(struct device *dev);
void echub_turbo_charge_remove_group(struct device *dev);
void echub_turbo_charge_reset_status(void);
#endif