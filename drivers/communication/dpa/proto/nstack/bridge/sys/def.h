/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef SPL_DEF_H
#define SPL_DEF_H

#include "opt.h"
#include "stack_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SPL_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define SPL_MIN(x, y) (((x) < (y)) ? (x) : (y))

/* Endianess-optimized shifting of two u8 to create one u16 */
#if __ORDER_BIG_ENDIAN__ == __BYTE_ORDER__
#define SPL_MAKE_U16(a, b) (((b) << 8U) | (a))
#else
#define SPL_MAKE_U16(a, b) (((a) << 8U) | (b))
#endif

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define spl_htons(x) (x)
#define spl_ntohs(x) (x)
#define spl_htonl(x) (x)
#define spl_ntohl(x) (x)
#else /* __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ */
static inline u16 spl_htons(u16 x)
{
    return ((x & 0x00ffU) << 8U) | ((x & 0xff00U) >> 8U);
}
static inline u16 spl_ntohs(u16 x)
{
    return spl_htons(x);
}
static inline u32 spl_htonl(u32 x)
{
    return (u32)(((x & 0x000000ffU) << 24U) |
        ((x & 0x0000ff00U) << 8U) |
        ((x & 0x00ff0000UL) >> 8U) |
        ((x & 0xff000000UL) >> 24U));
}
static inline u32 spl_ntohl(u32 x)
{
    return spl_htonl(x);
}
#endif /* __BYTE_ORDER__  selection */

#ifndef SPL_UNUSED_ARG
#define SPL_UNUSED_ARG(x) (void)(x)
#endif /* SPL_UNUSED_ARG */

#ifndef SPL_UNUSED_VAR
#define SPL_UNUSED_VAR(x) (void)(x)
#endif /* SPL_UNUSED_VAR */

#ifdef __cplusplus
}
#endif

#endif /* SPL_DEF_H */
