/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */
#ifndef NSTACK_THREAD_H
#define NSTACK_THREAD_H

#include <linux/types.h>
#include <linux/bottom_half.h>

s32 stack_create_thread(s32 (*threadfn)(void *), void *data, const char *name, void **thread);
bool stack_thread_should_stop(const void *thread);

static inline void stack_local_bh_disable(void)
{
    local_bh_disable();
}

static inline void stack_local_bh_enable(void)
{
    local_bh_enable();
}

#endif
