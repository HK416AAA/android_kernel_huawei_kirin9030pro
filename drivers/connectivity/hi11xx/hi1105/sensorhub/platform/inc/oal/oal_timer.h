/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */

#ifndef OAL_TIMER_H
#define OAL_TIMER_H

#include <stddef.h>
#include "oal_util.h"
#include "los_spinlock.h"

extern uint64_t LOS_TickCountGet(void);
#define jiffies     LOS_TickCountGet()

#define TIMER_VALID             0xABCDDCBA
#define TIMER_UNVALID           0xDCBAABCD

typedef struct oal_timer_list {
    uint32_t expires;                           /**< Timing duration of the timer. */
    VOID (*function)(struct oal_timer_list *);  /**< Callback function that handles timer timeout. */
    uint16_t timerid;                           /**< Timer ID. */
    uint32_t flag;                              /**< Indicates whether the timer is valid. */
    bool created;                               /**< Not used. */
    SPIN_LOCK_S lock;                           /**< Private spinlock. */
} oal_timer_list_t;


void oal_timer_setup(oal_timer_list_t *timer, void (*function)(oal_timer_list_t *), uint32_t flags);
int32_t oal_mod_timer(oal_timer_list_t *timer, uint32_t expires);

static inline int32_t oal_del_timer(oal_timer_list_t *timer)
{
    return 0;
}

static inline int oal_timer_pending(const oal_timer_list_t *timer)
{
    return 0;
}

static inline int32_t oal_del_timer_sync(oal_timer_list_t *timer)
{
    return oal_del_timer(timer);
}

#endif
