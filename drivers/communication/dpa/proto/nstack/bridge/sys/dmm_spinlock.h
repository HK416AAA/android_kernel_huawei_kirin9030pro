/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */


#ifndef DMM_SPINLOCK_H
#define DMM_SPINLOCK_H

#include <linux/spinlock.h>

typedef struct {
    spinlock_t lock;
} dmm_spinlock_t;

static inline void dmm_spin_init(dmm_spinlock_t *spinlock)
{
    spin_lock_init(&spinlock->lock);
}

static inline void dmm_spin_lock(dmm_spinlock_t *spinlock)
{
    spin_lock_bh(&spinlock->lock);
}

static inline void dmm_spin_unlock(dmm_spinlock_t *spinlock)
{
    spin_unlock_bh(&spinlock->lock);
}

static inline s32 dmm_spin_trylock(dmm_spinlock_t *spinlock)
{
    return spin_trylock(&spinlock->lock);
}

static inline bool dmm_spinlock_trylock(dmm_spinlock_t *spinlock)
{
    return dmm_spin_trylock(spinlock);
}

static inline void dmm_spin_lock_with(dmm_spinlock_t *spinlock, s32 value)
{
    (void)value;
    dmm_spin_lock(spinlock);
}

static inline void dmm_spin_lock_bh(dmm_spinlock_t *spinlock)
{
    spin_lock_bh(&spinlock->lock);
}

static inline void dmm_spin_unlock_bh(dmm_spinlock_t *spinlock)
{
    spin_unlock_bh(&spinlock->lock);
}

static inline void dmm_spin_lock_irqsave(dmm_spinlock_t *spinlock, unsigned long *flag)
{
    unsigned long tmp_flag;
    spin_lock_irqsave(&spinlock->lock, tmp_flag);
    *(flag) = tmp_flag;
}

static inline void dmm_spin_unlock_irqrestore(dmm_spinlock_t *spinlock, unsigned long flag)
{
    spin_unlock_irqrestore(&spinlock->lock, flag);
}

#endif /* #ifndef DMM_SPINLOCK_H */
