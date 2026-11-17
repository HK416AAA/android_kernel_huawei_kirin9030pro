/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 * Description: Russell Lab
 */
#ifndef NSTACK_COMM_THREAD_H
#define NSTACK_COMM_THREAD_H

#include "stack_types.h"
#include <linux/mutex.h>


#ifdef DT_NSTACK
#include <pthread.h>
typedef pthread_mutex_t stack_thread_mutex_t;
#else
typedef struct mutex stack_thread_mutex_t;
#endif
typedef s32 stack_thread_mutexattr_t;


static inline s32 stack_thread_mutex_lock(stack_thread_mutex_t *mutex)
{
    mutex_lock(mutex);
    return 0;
}

static inline s32 stack_thread_mutex_unlock(stack_thread_mutex_t *mutex)
{
    mutex_unlock(mutex);
    return 0;
}

static inline s32 stack_thread_mutex_trylock(stack_thread_mutex_t *mutex)
{
    return mutex_trylock(mutex);
}

static inline s32 stack_thread_mutex_init(stack_thread_mutex_t *mutex, const stack_thread_mutexattr_t *attr)
{
    (void)attr;
    mutex_init(mutex);
    return 0;
}


#endif /* _NSTACK_COMM_THREAD_H_ */

