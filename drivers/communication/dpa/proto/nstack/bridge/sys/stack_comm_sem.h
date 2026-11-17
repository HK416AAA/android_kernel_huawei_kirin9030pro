/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 * Description: Russell Lab
 */
#ifndef NSTACK_COMM_SEM_H
#define NSTACK_COMM_SEM_H

#include <linux/sched.h>
#include <linux/semaphore.h>
#include <linux/errno.h>
#include <linux/wait.h>
#include <linux/completion.h>
#include <linux/jiffies.h>
#include "stack_time_unit.h"
#include "stack_types.h"
#include "spl_err.h"
typedef struct completion stack_sem_t;

struct stack_wait_queue {
    wait_queue_head_t wait;
};

static inline void stack_wait_queue_init(struct stack_wait_queue *wait_queue)
{
    init_waitqueue_head(&wait_queue->wait);
    return;
}

static inline void stack_wakeup_interruptible(struct stack_wait_queue *wait_queue)
{
    wake_up_interruptible(&wait_queue->wait);
    return;
}

#define stack_wait_cond(wait, condition) \
    wait_event_interruptible((wait), (condition))

#define stack_wait_cond_timeout(wait, condition, time) \
    wait_event_interruptible_timeout((wait), (condition), (time))

static inline int stack_sem_init(stack_sem_t *sem, int pshared, unsigned int value)
{
    (void)pshared;
    (void)value;
    init_completion(sem);
    return 0;
}

static inline int stack_sem_trywait(stack_sem_t *sem)
{
    return try_wait_for_completion(sem) ? 0 : -1;
}

static inline s64 convert_retval(s64 ret)
{
    if (ret == 0) {
        return -SPL_ETIMEDOUT;
    } else if (ret == -SPL_ERESTARTSYS) {
        /* convert errno for compatibility */
        return -SPL_EINTR;
    } else if (ret > 0) {
        return 1;
    } else {
        return ret;
    }
}

static inline int stack_sem_timedwait_comm(stack_sem_t *sem, const struct timespec *ts)
{
    long ms = (ts->tv_sec * (long)SPL_MS_PER_S) + (ts->tv_nsec / (long)SPL_NS_PER_MS);
    u64 tmp_jiffies = msecs_to_jiffies((unsigned int)ms);
    /* unit 10ms */
    /* returns -SPL_ERESTARTSYS is interrupt, 0 is timeout, > 0 is wake up */
    s64 ret = wait_for_completion_interruptible_timeout(sem, tmp_jiffies);
    ret = convert_retval(ret);
    return (s32)ret;
}

static inline int stack_sem_wait_interruptible(stack_sem_t *sem)
{
    return wait_for_completion_interruptible(sem);
}

static inline int stack_sem_wait(stack_sem_t *sem)
{
    wait_for_completion(sem);
    return 0;
}

static inline int stack_sem_post(stack_sem_t *sem)
{
    complete(sem);
    return 0;
}

static inline int stack_sem_destroy(const stack_sem_t *sem)
{
    (void)sem;
    return -1;
}

#endif /* !NSTACK_COMM_SEM_H */
