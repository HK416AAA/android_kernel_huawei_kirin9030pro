/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */


#ifndef NSTACK_TYPES_H
#define NSTACK_TYPES_H

#include <linux/types.h>
#include <linux/uio.h>

/* CONFIG_ARCH_HISI is defined on OH config file */
#ifndef CONFIG_ARCH_HISI
struct timespec {
    s64 tv_sec;  /* seconds */
    long tv_nsec; /* nanoseconds */
};

struct timeval {
    s64 tv_sec;  /* seconds */
    s64 tv_usec; /* microseconds */
};
#endif

#if !defined(socklen_t)
typedef u32 socklen_t;
#endif

#ifndef NONBLOCK_MODE_FOR_ALG
#define NONBLOCK_MODE_FOR_ALG 2 /* it is possible to get fail */
#endif

#ifndef BLOCK_MODE_FOR_ALG
#define BLOCK_MODE_FOR_ALG 1 /* will block till success */
#endif

#ifndef NONBLOCK_MODE_NOT_FOR_ALG
#define NONBLOCK_MODE_NOT_FOR_ALG 0
#endif

#ifndef NSTACK_MAX_U32_NUM
#define NSTACK_MAX_U32_NUM ((u32)0xffffffffU)
#endif

#ifndef NSTACK_MAX_S32_NUM
#define NSTACK_MAX_S32_NUM ((s32)0x7fffffff)
#endif

#ifndef NSTACK_MAX_U64_NUM
#define NSTACK_MAX_U64_NUM ((u64)0xffffffffffffffffULL)
#endif

#ifndef NSTACK_MAX_S64_NUM
#define NSTACK_MAX_S64_NUM ((s64)0x7fffffffffffffff)
#endif

#ifndef SPL_MAX_S16_NUM
#define SPL_MAX_S16_NUM ((s16)0x7fff)
#endif

#ifndef SPL_MAX_U16_NUM
#define SPL_MAX_U16_NUM ((u16)0xFfff)
#endif

#ifndef SPL_MAX_U32_NUM
#define SPL_MAX_U32_NUM ((u32)0xffffffffU)
#endif

#ifndef SPL_MAX_S32_NUM
#define SPL_MAX_S32_NUM ((s32)0x7fffffff)
#endif

#ifndef SPL_MAX_U64_NUM
#define SPL_MAX_U64_NUM ((u64)0xffffffffffffffffULL)
#endif

typedef uintptr_t mem_ptr_t;

typedef s32 err_t;
#endif /* NSTACK_TYPES_H */
