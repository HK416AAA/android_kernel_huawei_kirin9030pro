/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: dubai udk driver stats
 */

#ifndef DUBAI_DRIVER_STATS_H
#define DUBAI_DRIVER_STATS_H
#include <linux/types.h>

long dubai_ioctl_driver(unsigned int cmd, void __user *argp);
void dubai_driver_stats_init(void);

#endif