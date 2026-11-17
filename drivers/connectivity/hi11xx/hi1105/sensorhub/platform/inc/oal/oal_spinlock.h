/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */

#ifndef OAL_SPINLOCK_H
#define OAL_SPINLOCK_H

#include "los_spinlock.h"


typedef uint32_t (*oal_irqlocked_func)(void *);
typedef struct Spinlock spinlock_t;

typedef struct {
    spinlock_t lock;
} oal_spin_lock_stru;


OAL_STATIC OAL_INLINE void oal_spin_lock_init(oal_spin_lock_stru *pst_lock)
{
    LOS_SpinInit(&pst_lock->lock);
}

OAL_STATIC OAL_INLINE void oal_spin_lock(oal_spin_lock_stru *pst_lock)
{
    LOS_SpinLock(&pst_lock->lock);
}

OAL_STATIC OAL_INLINE void oal_spin_unlock(oal_spin_lock_stru *pst_lock)
{
    LOS_SpinUnlock(&pst_lock->lock);
}

OAL_STATIC OAL_INLINE void oal_spin_lock_bh(oal_spin_lock_stru *pst_lock)
{
    (void)(pst_lock);
}

OAL_STATIC OAL_INLINE void oal_spin_unlock_bh(oal_spin_lock_stru *pst_lock)
{
    (void)(pst_lock);
}

OAL_STATIC OAL_INLINE void oal_spin_lock_irq_save(oal_spin_lock_stru *pst_lock, oal_uint *pui_flags)
{
    LOS_SpinLockSave(&pst_lock->lock, (UINT32 *)pui_flags);
}

OAL_STATIC OAL_INLINE void oal_spin_unlock_irq_restore(oal_spin_lock_stru *pst_lock, oal_uint *pui_flags)
{
    LOS_SpinUnlockRestore(&pst_lock->lock, (UINT32)*pui_flags);
}

OAL_STATIC OAL_INLINE uint32_t oal_spin_lock_irq_exec(oal_spin_lock_stru *pst_lock, oal_irqlocked_func func,
                                                      void *p_arg, oal_uint *pui_flags)
{
    uint32_t ul_rslt;

    LOS_SpinLockSave(&pst_lock->lock, (UINT32 *)pui_flags);
    ul_rslt = func(p_arg);
    LOS_SpinUnlockRestore(&pst_lock->lock, *pui_flags);
    return ul_rslt;
}


#endif
