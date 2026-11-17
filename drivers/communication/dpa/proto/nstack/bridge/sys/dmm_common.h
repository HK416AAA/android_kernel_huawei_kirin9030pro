/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */


#ifndef DMM_COMMON_H
#define DMM_COMMON_H

#include <stddef.h>
#include <linux/compiler.h>

#define dmm_packed __attribute__((__packed__))
#define dmm_aligned(a) __attribute__((__aligned__(a)))
#define dmm_cache_aligned dmm_aligned(DMM_CACHE_LINE_SIZE)

#define dmm_align(x, a)                                      \
    ({                                                       \
        __typeof__(x) _a = (a);                              \
        ((x) + (_a - 1)) / _a *_a;                           \
    })

#ifndef offsetof
#define offsetof(type, member) ((size_t)((type *)0)->member)
#endif

static inline u32 align32pow2(u32 px)
{
    unsigned int x = px;

    x--;
    x |= x >> 1U;
    x |= x >> 2U;
    x |= x >> 4U;
    x |= x >> 8U;
    x |= x >> 16U;

    return x + 1U;
}

#define NSFW_THREAD

#endif
