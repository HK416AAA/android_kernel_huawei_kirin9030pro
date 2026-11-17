/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */

#ifndef DMM_RWLOCK_H
#define DMM_RWLOCK_H

#include <linux/rwlock_types.h>
#include <linux/rwlock.h>
#include "stack_types.h"

typedef struct {
    rwlock_t lock;
} dmm_rwlock_t;

static inline void dmm_rwlock_init(dmm_rwlock_t *rwlock)
{
    rwlock_init(&rwlock->lock);
}

static inline void dmm_read_lock(dmm_rwlock_t *rwlock)
{
    read_lock_bh(&rwlock->lock);
}

static inline s32 dmm_read_trylock(dmm_rwlock_t *rwlock)
{
    return (s32)read_trylock(&rwlock->lock);
}

static inline void dmm_read_unlock(dmm_rwlock_t *rwlock)
{
    read_unlock_bh(&rwlock->lock);
}

static inline void dmm_read_lock_bh(dmm_rwlock_t *rwlock)
{
    read_lock_bh(&rwlock->lock);
}

static inline void dmm_read_unlock_bh(dmm_rwlock_t *rwlock)
{
    read_unlock_bh(&rwlock->lock);
}

static inline void dmm_read_lock_irqsave(dmm_rwlock_t *rwlock, unsigned long *irq_flags)
{
    unsigned long tmp_flag;
    read_lock_irqsave(&rwlock->lock, tmp_flag);
    *(irq_flags) = tmp_flag;
}

static inline void dmm_read_unlock_irqrestore(dmm_rwlock_t *rwlock, unsigned long irq_flags)
{
    read_unlock_irqrestore(&rwlock->lock, irq_flags);
}

static inline void dmm_write_lock(dmm_rwlock_t *rwlock)
{
    write_lock_bh(&rwlock->lock);
}

static inline s32 dmm_write_trylock(dmm_rwlock_t *rwlock)
{
    return (s32)write_trylock(&rwlock->lock);
}

static inline void dmm_write_unlock(dmm_rwlock_t *rwlock)
{
    write_unlock_bh(&rwlock->lock);
}

static inline void dmm_write_lock_bh(dmm_rwlock_t *rwlock)
{
    write_lock_bh(&rwlock->lock);
}

static inline void dmm_write_unlock_bh(dmm_rwlock_t *rwlock)
{
    write_unlock_bh(&rwlock->lock);
}
#endif /* #ifndef DMM_RWLOCK_H */
