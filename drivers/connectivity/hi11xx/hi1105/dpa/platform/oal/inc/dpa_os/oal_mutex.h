/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oal_dpa_mutex.h
 * Author: dpa drivers
 */

#ifndef OAL_DPA_MUTEX_H
#define OAL_DPA_MUTEX_H

/* 其他头文件包含 */
#include "oal_util.h"

#ifndef _PRE_LINUX_TEST
#include "pthread.h"
typedef pthread_mutex_t oal_mutex_stru;

/*
 * 函 数 名  : oal_mutex_init
 * 功能描述  : 初始化互斥锁
 * 输入参数  : lock 互斥锁结构体地址
 */
OAL_STATIC OAL_INLINE int32_t oal_mutex_init(oal_mutex_stru *lock)
{
    int32_t ret;
    ret = pthread_mutex_init(lock, NULL);
    return ret;
}

/*
 * 函 数 名  : oal_mutex_free
 * 功能描述  : 释放互斥锁
 * 输入参数  : lock 互斥锁结构体地址
 */
OAL_STATIC OAL_INLINE int32_t oal_mutex_free(oal_mutex_stru *lock)
{
    int32_t ret;
    ret = pthread_mutex_destroy(lock);
    return ret;
}

/*
 * 函 数 名  : oal_mutex_lock
 * 功能描述  : 获取互斥锁，在进程上下文使用, 如果获取不到会让出cpu
 * 输入参数  : lock 互斥锁结构体地址
 */
OAL_STATIC OAL_INLINE int32_t oal_mutex_lock(oal_mutex_stru *lock)
{
    int32_t ret;
    ret = pthread_mutex_lock(lock);
    if (ret != OAL_SUCC) {
        oal_dump_callstack();
    }
    return ret;
}

/*
 * 函 数 名  : oal_mutex_lock
 * 功能描述  : 释放互斥锁，在进程上下文使用
 * 输入参数  : lock 互斥锁结构体地址
 */
OAL_STATIC OAL_INLINE int32_t oal_mutex_unlock(oal_mutex_stru *lock)
{
    int32_t ret;
    ret = pthread_mutex_unlock(lock);
    if (ret != OAL_SUCC) {
        oal_dump_callstack();
    }
    return ret;
}
#else
typedef struct oal_mutex_stru {
    int32_t lock;
} oal_mutex_stru;

int32_t oal_mutex_init(oal_mutex_stru *lock);
int32_t oal_mutex_free(oal_mutex_stru *lock);
int32_t oal_mutex_lock(oal_mutex_stru *lock);
int32_t oal_mutex_unlock(oal_mutex_stru *lock);
#endif
#endif