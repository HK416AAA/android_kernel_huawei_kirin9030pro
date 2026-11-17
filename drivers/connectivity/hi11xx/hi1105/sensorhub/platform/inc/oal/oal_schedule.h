/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */

#ifndef OAL_SCHEDULE_H
#define OAL_SCHEDULE_H

#include "oal_types.h"
#include "oal_list.h"
#include "oal_spinlock.h"
#include "los_driverbase.h"


#define oal_debug_module_param(_symbol, _type, _name)
#define oal_debug_module_param_string(arg1, arg2, arg3, arg4)
#define oal_debug_module_parm_desc(arg1, arg2)


typedef struct {
    uint32_t  lock_count;       /* 持有wakelock锁的次数 */
    uintptr_t locked_addr;      /* the locked address */
    uint32_t  debug;            /* debug flag */
} oal_wakelock_stru;

typedef struct oal_event {
    uint32_t uwEventID;             /**< Event mask in the event control block,
                                        indicating the event that has been logically processed. */
    oal_list_head_stru stEventList; /**< Event control block linked list */
} OAL_EVENT_CB_S, *OAL_PEVENT_CB_S;

typedef struct oal_wait_queue_head {
    OAL_EVENT_CB_S      event;
    spinlock_t          lock;
    oal_list_head_stru  poll_queue;
} oal_wait_queue_head_t, oal_wait_queue_head_stru;


typedef enum {
    OAL_DFT_TRACE_OTHER = 0x0,
    OAL_DFT_TRACE_SUCC,
    OAL_DFT_TRACE_FAIL,
    OAL_DFT_TRACE_EXCEP,
    OAL_DFT_TRACE_BUTT
} oal_dft_type;

#define declare_dft_trace_key_info(dname, dtype)


OAL_STATIC OAL_INLINE void oal_wake_lock_init(oal_wakelock_stru *pst_wakelock, char *name)
{
}

OAL_STATIC OAL_INLINE void oal_wake_lock_exit(oal_wakelock_stru *pst_wakelock)
{
}

OAL_STATIC OAL_INLINE void oal_wake_lock(oal_wakelock_stru *pst_wakelock)
{
}

OAL_STATIC OAL_INLINE void oal_wake_unlock(oal_wakelock_stru *pst_wakelock)
{
}

OAL_STATIC OAL_INLINE int32_t oal_wakelock_active(oal_wakelock_stru *pst_wakelock)
{
    return 0;
}

OAL_STATIC OAL_INLINE void oal_wake_lock_timeout(oal_wakelock_stru *pst_wakelock, int32_t msec)
{
}

OAL_STATIC OAL_INLINE void oal_wake_unlock_force(oal_wakelock_stru *pst_wakelock)
{
}


void init_waitqueue_head(oal_wait_queue_head_t *wait);
void wake_up_interruptible(oal_wait_queue_head_t *wait);

#define oal_wait_queue_init_head(x)             init_waitqueue_head(x)
#define oal_wait_queue_wake_up_interrupt(x)     wake_up_interruptible(x)

#define oal_in_interrupt()                      (0)

uint32_t msecs_to_jiffies(const uint32_t m);
static inline uint32_t oal_msecs_to_jiffies(const uint32_t m)
{
    return msecs_to_jiffies(m);
}

static inline uint32_t oal_time_after(unsigned long ul_time_a, unsigned long ul_time_b)
{
    return ((long)(ul_time_b - ul_time_a) < 0) ? 1 : 0;
}

static inline uint32_t oal_time_after32(uint32_t ul_time_a, uint32_t ul_time_b)
{
    return ((int32_t)((ul_time_b) - (ul_time_a)) < 0) ? 1 : 0;
}


typedef struct pm_message {
    int event;
} dev_pm_message_t, oal_pm_message_t;

struct dev_pm_info {
    dev_pm_message_t power_state;
    oal_list_head_stru entry;
};

struct platform_device {
    struct LosDevice dev;
    const CHAR *name;
    VOID *driver_data;
    VOID *platform_data;            /**< Platform specific data, device core doesn't touch it */
    struct dev_pm_info power;
};

static inline void *dev_get_drvdata(const struct LosDevice *dev)
{
    return dev->data;
}


#endif /* OAL_SCHEDULE_H */
