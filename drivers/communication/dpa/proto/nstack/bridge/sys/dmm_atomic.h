/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */


#ifndef DMM_ATOMIC_H
#define DMM_ATOMIC_H

#include <linux/atomic.h>
#include "stack_types.h"

/* atomic 32 bit operation */
typedef atomic_t dmm_atomic_t;

inline static void dmm_atomic_set(dmm_atomic_t *a, s32 n)
{
    atomic_set(a, n);
}

inline static s32 dmm_atomic_get(const dmm_atomic_t *a)
{
    return atomic_read(a);
}

inline static s32 dmm_atomic_read(dmm_atomic_t *a)
{
    return atomic_read(a);
}

inline static s32 dmm_atomic_swap(dmm_atomic_t *a, s32 o, s32 n)
{
    return (atomic_cmpxchg(a, o, n) == o) ? 1 : 0;
}

inline static s32 dmm_atomic_xchg(dmm_atomic_t *a, int n)
{
    s32 old = dmm_atomic_get(a);
    while (1) {
        s32 tmp = atomic_cmpxchg(a, old, n);
        if (tmp == old) {
            break;
        }
        old = tmp;
    }
    return old;
}

inline static s32 dmm_atomic_fetch_and_add(dmm_atomic_t *a, s32 n)
{
    return atomic_fetch_add(n, a);
}

inline static void dmm_atomic_add(dmm_atomic_t *a, s32 n)
{
    atomic_add(n, a);
}

inline static void dmm_atomic_inc(dmm_atomic_t *a)
{
    atomic_add(1, a);
}

inline static bool dmm_atomic_swap_u32(volatile u32 *cnt, u32 o, u32 n)
{
    return (dmm_atomic_swap((dmm_atomic_t *)cnt, (s32)o, (s32)n) == 1U);
}

inline static void dmm_atomic_add_u32(volatile u32 *cnt, u32 n)
{
    atomic_add((s32)n, (dmm_atomic_t *)cnt);
}

inline static u32 dmm_atomic_add_return_u32(volatile u32 *cnt, u32 n)
{
    return (u32)atomic_add_return((s32)n, (dmm_atomic_t *)cnt);
}

inline static void dmm_atomic_add_i32(volatile s32 *cnt, s32 n)
{
    atomic_add(n, (dmm_atomic_t *)cnt);
}

inline static void dmm_atomic_sub_i32(volatile s32 *cnt, s32 n)
{
    atomic_sub(n, (dmm_atomic_t *)cnt);
}

inline static u32 dmm_atomic_sub_return_u32(volatile u32 *cnt, u32 n)
{
    return (u32)atomic_sub_return((s32)n, (dmm_atomic_t *)cnt);
}

inline static u32 dmm_atomic_and_u32(volatile u32 *cnt, u32 n)
{
    return (u32)atomic_fetch_and((s32)n, (dmm_atomic_t *)cnt);
}

inline static u32 dmm_atomic_or_u32(volatile u32 *cnt, u32 n)
{
    return (u32)atomic_fetch_or((s32)n, (dmm_atomic_t *)cnt);
}

inline static void dmm_atomic_sub(dmm_atomic_t *a, s32 n)
{
    atomic_sub(n, a);
}

inline static void dmm_atomic_dec(dmm_atomic_t *a)
{
    dmm_atomic_sub(a, 1);
}

inline static s32 dmm_atomic_inc_not_zero(dmm_atomic_t *a)
{
    s32 old;
    do {
        old = dmm_atomic_get(a);
        if (old == 0) {
            break;
        }
    } while (atomic_cmpxchg(a, old, old + 1) != old);

    return old;
}

inline static s32 dmm_atomic_dec_not_zero(dmm_atomic_t *a)
{
    s32 old;
    do {
        old = dmm_atomic_get(a);
        if (old == 0) {
            break;
        }
    } while (atomic_cmpxchg(a, old, old - 1) != old);

    return old;
}

inline static s32 dmm_atomic_sub_return(dmm_atomic_t *a, s32 n)
{
    return atomic_sub_return(n, a);
}

inline static s32 dmm_atomic_dec_return(dmm_atomic_t *a)
{
    return dmm_atomic_sub_return(a, 1);
}

/* atomit 64bit operation */
typedef atomic64_t dmm_atomic64_t;

inline static s64 dmm_atomic64_get(const dmm_atomic64_t *a)
{
    return atomic64_read(a);
}

inline static void dmm_atomic64_set(dmm_atomic64_t *a, s32 n)
{
    atomic64_set(a, (s64)n);
}

inline static void dmm_atomic64_add(dmm_atomic64_t *a, s32 n)
{
    atomic64_add((s64)n, a);
}

inline static void dmm_atomic64_inc(dmm_atomic64_t *a)
{
    dmm_atomic64_add(a, 1);
}

inline static s64 dmm_atomic64_inc_return(dmm_atomic64_t *a)
{
    return atomic64_inc_return(a);
}

inline static void dmm_atomic64_sub(dmm_atomic64_t *a, s32 n)
{
    dmm_atomic64_add(a, -n);
}

inline static void dmm_atomic64_dec(dmm_atomic64_t *a)
{
    dmm_atomic64_sub(a, 1);
}

inline static bool dmm_atomic64_swap(volatile u64 *a, u64 o, u64 n)
{
    return (atomic64_cmpxchg((dmm_atomic64_t *)a, (s64)o, (s64)n) == (s64)o);
}

inline static void dmm_atomic_add_u64(volatile u64 *cnt, u64 n)
{
    atomic64_add((s64)n, (dmm_atomic64_t *)cnt);
}

inline static bool dmm_atomic_swap_uintptr(volatile uintptr_t *cnt, uintptr_t o, uintptr_t n)
{
    return (atomic64_cmpxchg((dmm_atomic64_t *)cnt, (s64)o, (s64)n) == (s64)o);
}

#endif /* #ifndef DMM_ATOMIC_H */
