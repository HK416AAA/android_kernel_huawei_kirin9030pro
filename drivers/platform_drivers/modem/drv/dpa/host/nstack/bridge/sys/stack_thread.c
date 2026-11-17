/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include <linux/kthread.h>
#include "stack_log.h"
#include "stack_thread.h"

s32 stack_create_thread(s32 (*threadfn)(void *), void *data, const char *name, void **thread)
{
    struct task_struct *task = kthread_run(threadfn, data, "%s", name);
    if (IS_ERR_OR_NULL(task)) {
        NS_ERR("kthread_run failed");
        return (s32)PTR_ERR(task);
    }

    *thread = task;
    return 0;
}

bool stack_thread_should_stop(const void *thread)
{
    (void)thread;
    bool stop = kthread_should_stop();
    if (stop) {
        NS_ERR("task %s stop bit set", current->comm);
    }
    return stop;
}