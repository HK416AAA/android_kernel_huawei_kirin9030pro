/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: Encapsulate malloc to reduce number of macros
 */

#ifndef NSTACK_DELAY_H
#define NSTACK_DELAY_H

#include <uapi/linux/time.h>
#include <linux/delay.h>
#include "stack_types.h"

#define DEF_DELAY   50UL
static inline s32 stack_nanosleep(const struct timespec *rqtp, const struct timespec *rmtp)
{
    (void)rmtp;
    unsigned long usecs = (unsigned long)((rqtp->tv_sec * 1000000) + (rqtp->tv_nsec / 1000));
    usleep_range(usecs, DEF_DELAY);
    return 0;
}

#endif
