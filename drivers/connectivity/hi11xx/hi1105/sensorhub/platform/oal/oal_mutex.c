/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for mutex
 * Author: plat drivers
 */

#include "oal_mutex.h"
#include "oal_types.h"
#include <los_mux.h>
#include <los_mux_pri.h>


int32_t oal_mutex_init(oal_mutex_t *mutex)
{
    if (mutex == NULL) {
        return -OAL_EFAIL;
    }

    if (GET_MUX_INDEX((unsigned int)(UINTPTR)mutex->mutex) >= (unsigned int)KERNEL_MUX_LIMIT) {
        return -OAL_EFAIL;
    }

    LosMuxCB *mutex_handle = GET_MUX((unsigned int)(UINTPTR)mutex->mutex);
    if (mutex_handle->muxStat == LOS_USED && ((unsigned int)(UINTPTR)mutex->mutex != 0)) {
        return -OAL_EFAIL;
    }

    unsigned int ret = LOS_MuxCreate((unsigned int *)&(mutex->mutex));
    if (ret != LOS_OK) {
        return -OAL_EFAIL;
    }

    return OAL_SUCC;
}

void oal_mutex_destroy(oal_mutex_t *mutex)
{
    if (mutex == NULL) {
        return;
    }

    LOS_MuxDelete((unsigned int)(UINTPTR)mutex->mutex);
    mutex->mutex = NULL;
}

int32_t oal_mutex_lock(oal_mutex_t *mutex)
{
    if (mutex == NULL) {
        return -OAL_EFAIL;
    }

    unsigned int ret = LOS_MuxPend((unsigned int)(UINTPTR)mutex->mutex, LOS_WAIT_FOREVER);
    if (ret != LOS_OK) {
        return -OAL_EFAIL;
    }

    return OAL_SUCC;
}

void oal_mutex_unlock(oal_mutex_t *mutex)
{
    if (mutex == NULL) {
        return;
    }

    LOS_MuxPost((unsigned int)(UINTPTR)mutex->mutex);
}
