/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for semaphore
 * Author: plat drivers
 */

#include "oal_semaphore.h"
#include "los_sem.h"


#define SEM_COUNT_MAX   1
#define UNINIT_VALUE    0xFFFFFFFF

int32_t oal_sema_init(oal_semaphore_t *sem, uint32_t value)
{
    if (sem == NULL) {
        return -1;
    }

    if (value > SEM_COUNT_MAX) {
        sem->sem = UNINIT_VALUE;
        return -1;
    }

    uint32_t ret = LOS_SemCreate((uint16_t)value, &(sem->sem));
    if (ret != LOS_OK) {
        sem->sem = UNINIT_VALUE;
        return -1;
    }

    return 0;
}

int32_t oal_sema_destory(oal_semaphore_t *sem)
{
    if ((sem == NULL) || (sem->sem == UNINIT_VALUE)) {
        return -1;
    }

    return (LOS_SemDelete(sem->sem) == LOS_OK) ? 0 : -1;
}

int32_t oal_sema_lock(oal_semaphore_t *sem, uint32_t timeout_ms)
{
    if (sem == NULL) {
        return -1;
    }

    if (sem->sem == UNINIT_VALUE) {
        if (oal_sema_init(sem, sem->count) != 0) {
            return -1;
        }
    }

    return (LOS_SemPend(sem->sem, LOS_MS2Tick(timeout_ms)) == LOS_OK) ? 0 : -1;
}

int32_t oal_sema_trylock(oal_semaphore_t *sem)
{
    if (sem == NULL) {
        return -1;
    }

    if (sem->sem == UNINIT_VALUE) {
        if (oal_sema_init(sem, sem->count) != 0) {
            return -1;
        }
    }

    return (LOS_SemPend(sem->sem, LOS_NO_WAIT) == LOS_OK) ? 0 : -1;
}

int32_t oal_sema_unlock(oal_semaphore_t *sem)
{
    if (sem == NULL) {
        return -1;
    }

    if (sem->sem == UNINIT_VALUE) {
        if (oal_sema_init(sem, sem->count) != 0) {
            return -1;
        }
    }

    return (LOS_SemPost(sem->sem) == LOS_OK) ? 0 : -1;
}
