/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oal_pm.h
 * Author: dpa pm
 */

#ifndef OAL_PM_H
#define OAL_PM_H

#include "bsp_pm.h"

#define WIFI_WAKE_PM    WIFI_PM
#define HCC_WAKE_PM     HCC_PM

/*
 * 函 数 名  : oal_wake_lock
 * 功能描述  : 唤醒持锁
 * 输入参数  : lock_id: 睡眠锁id
 */
OAL_STATIC OAL_INLINE void oal_wake_lock(wake_lock_id_e lock_id)
{
    int32_t ret = bsp_wake_lock(lock_id);
    if (ret != OAL_SUCC) {
        // 失败后返回系统err
        sys_abort(1);
    }
}

/*
 * 函 数 名  : oal_wake_unlock
 * 功能描述  : 睡眠释放锁
 * 输入参数  : lock_id: 睡眠锁id
 */
OAL_STATIC OAL_INLINE void oal_wake_unlock(wake_lock_id_e lock_id)
{
    int32_t ret = bsp_wake_unlock(lock_id);
    if (ret != OAL_SUCC) {
        // 失败后返回系统err
        sys_abort(1);
    }
}
#endif