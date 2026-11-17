/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2024. All rights reserved.
 */
#ifndef _LINUX_ECHUB_FLOAT_CHARGE_H
#define _LINUX_ECHUB_FLOAT_CHARGE_H

#include <linux/platform_device.h>

void echub_float_charge_init(struct device *dev);
void echub_float_charge_exit(void);
#endif