/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */

#ifndef OAL_SEMAPHORE_H
#define OAL_SEMAPHORE_H

#include <stdint.h>

#define OAL_WAIT_FOREVER    0xFFFFFFFF

typedef struct oal_semaphore {
    uint32_t sem;
    int32_t  count;
} oal_semaphore_t;

int32_t oal_sema_init(oal_semaphore_t *sem, uint32_t value);
int32_t oal_sema_destory(oal_semaphore_t *sem);
int32_t oal_sema_lock(oal_semaphore_t *sem, uint32_t timeout_ms);
int32_t oal_sema_trylock(oal_semaphore_t *sem);
int32_t oal_sema_unlock(oal_semaphore_t *sem);

static inline int32_t oal_down(oal_semaphore_t *sem)
{
    return oal_sema_lock(sem, OAL_WAIT_FOREVER);
}

static inline int32_t oal_down_interruptible(oal_semaphore_t *sem)
{
    return oal_sema_lock(sem, OAL_WAIT_FOREVER);
}

static inline int32_t oal_down_trylock(oal_semaphore_t *sem)
{
    return (oal_sema_trylock(sem) == 0) ? 0 : 1;
}

static inline int32_t oal_up(oal_semaphore_t *sem)
{
    return oal_sema_unlock(sem);
}

#endif
