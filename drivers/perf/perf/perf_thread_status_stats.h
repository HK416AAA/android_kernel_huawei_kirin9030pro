/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */
#ifndef PERF_CPU_STATE_STATS_H
#define PERF_CPU_STATE_STATS_H

#include <linux/sched.h>

long perf_ioctl_thread_status(unsigned int cmd, void __user *argp);

#endif

