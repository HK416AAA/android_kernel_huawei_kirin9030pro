/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */

#ifndef OAL_ATOMIC_H
#define OAL_ATOMIC_H

#include <stdint.h>
#include "osal.h"

typedef int32_t oal_atomic_t;

#define oal_atomic_init(v)  (v)

static inline int32_t oal_atomic_read(oal_atomic_t *v)
{
    return *v;
}

static inline void oal_atomic_set(oal_atomic_t *v, int32_t val)
{
    uint32_t int_flag = osa_int_lock();
    *v = val;
    osa_int_restore(int_flag);
}

static inline int32_t oal_atomic_add(oal_atomic_t *v, int32_t val)
{
    int32_t res;
    uint32_t int_flag = osa_int_lock();
    *v += val;
    res = *v;
    osa_int_restore(int_flag);

    return res;
}

static inline int32_t oal_atomic_sub(oal_atomic_t *v, int32_t val)
{
    int32_t res;
    uint32_t int_flag = osa_int_lock();
    *v -= val;
    res = *v;
    osa_int_restore(int_flag);

    return res;
}

static inline int32_t oal_atomic_dec(oal_atomic_t *v)
{
    return oal_atomic_sub(v, 1);
}

static inline int32_t oal_atomic_inc(oal_atomic_t *v)
{
    return oal_atomic_add(v, 1);
}

static inline bool oal_in_atomic()
{
    return false;
}

#endif
