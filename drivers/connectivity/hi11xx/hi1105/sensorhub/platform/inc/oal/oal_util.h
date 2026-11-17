/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */

#ifndef OAL_UTIL_H
#define OAL_UTIL_H

#include "oal_types.h"
#include "los_tick.h"

#if defined(__GNUC__)
#define oal_likely(_expr)       __builtin_expect(!!(_expr), 1)
#define oal_unlikely(_expr)     __builtin_expect(!!(_expr), 0)
#else
#define oal_likely(_expr)       (_expr)
#define oal_unlikely(_expr)     (_expr)
#endif

#ifndef __user
#define __user
#endif

#define OAL_DECLARE_PACKED      __attribute__((__packed__))

#define OAL_RET_ADDR            ((uintptr_t)__builtin_return_address(0))

#define HEX_DUMP_GROUP_SIZE     32

#define declare_time_cost_stru(name) \
    uint64_t trans_us_##name;      \
    ktime_t local_cost_time_start_##name, local_cost_time_end_##name

#define BIT31   ((uint32_t)(1UL << 31))
#ifndef BIT
#define BIT(nr) (1UL << (nr))
#endif

#ifndef min_t
#define min_t(t, x, y) ((t)(x) < (t)(y) ? (t)(x) : (t)(y))
#endif

// dead loop
#define forever_loop()  for (;;)

#define oal_any_null_ptr1(p1)                   (((p1) == NULL))
#define oal_any_null_ptr2(p1, p2)               (((p1) == NULL) || ((p2) == NULL))
#define oal_any_null_ptr3(p1, p2, p3)           (((p1) == NULL) || ((p2) == NULL) || ((p3) == NULL))
#define oal_any_null_ptr4(p1, p2, p3, p4)       (((p1) == NULL) || ((p2) == NULL) || ((p3) == NULL) || ((p4) == NULL))
#define oal_any_null_ptr5(p1, p2, p3, p4, p5)   (((p1) == NULL) || ((p2) == NULL) || ((p3) == NULL) || \
                                                 ((p4) == NULL) || ((p5) == NULL))
#define oal_all_not_null_ptr2(p1, p2)           (((p1) != NULL) && ((p2) != NULL))
#define oal_all_true_value2(v1, v2)             (((v1) == true) && ((v2) == true))
#define oal_all_zero_value2(v1, v2)             (((v1) == 0) && ((v2) == 0))

#define oal_container_of(_member_ptr, _stru_type, _stru_member_name) \
    ((_stru_type *)((uintptr_t)(_member_ptr) - (uintptr_t)(&((_stru_type *)0)->_stru_member_name)))

static inline void oal_set_bits(uint32_t mask, uintptr_t addr)
{
    (*(volatile uintptr_t *) (addr)) |= mask;
}

static inline void oal_set_bit(uint32_t nr, uintptr_t addr)
{
    oal_set_bits(BIT(nr), addr);
}

static inline bool oal_test_bit(uint32_t nr, uintptr_t addr)
{
    if (((*(volatile uintptr_t *) (addr)) & BIT(nr)) == 0) {
        return false;
    }

    return true;
}

static inline void oal_print_hex_dump(uint8_t *addr, int32_t len, int32_t groupsize, char *pre_str)
{
}

extern VOID LOS_Msleep(UINT32 mSecs);
static inline void oal_msleep(uint32_t ul_usecs)
{
    LOS_Msleep(ul_usecs);
}

extern VOID LOS_Mdelay(UINT32 mSecs);
static inline void oal_mdelay(uint32_t msecs)
{
    LOS_Mdelay(msecs);
}

extern VOID LOS_Udelay(UINT32 usecs);
static inline void oal_udelay(uint32_t us)
{
    LOS_Udelay(us);
}
#endif