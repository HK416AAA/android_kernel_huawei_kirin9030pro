/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: Encapsulate malloc to reduce number of macros
 */

#ifndef NSTACK_SCHED_YIELD_H
#define NSTACK_SCHED_YIELD_H

#include <linux/sched.h>
static inline void stack_sched_yield(void)
{
    schedule();
}

#endif
