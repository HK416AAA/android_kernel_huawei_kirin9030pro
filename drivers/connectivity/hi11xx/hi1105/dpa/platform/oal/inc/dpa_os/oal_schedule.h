/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oal_dpa_schedule.h
 * Author: dpa drivers
 */

#ifndef OAL_DPA_SCHEDULE_H
#define OAL_DPA_SCHEDULE_H

/* 其他头文件包含 */
#include <mdrv_sys.h>
#include "atomic.h"
#include "oal_net.h"
#include "sbuf_api.h"
#include "mdrv_cpu.h"
#include "oal_net_queue.h"

typedef dpa_atomic_t oal_atomic;

typedef unsigned int oal_spin_lock_stru;
extern uint32_t g_spin_lock_alloc_succ_cnt;
extern uint32_t g_spin_lock_free_cnt;
/*
 * 函 数 名  : oal_spin_lock_init
 * 功能描述  : 自旋锁初始化
 * 输入参数  : pst_lock: 锁的地址
 */
OAL_STATIC OAL_INLINE void oal_spin_lock_init(oal_spin_lock_stru *pst_lock)
{
    *(unsigned int*)pst_lock = 0;
}

/*
 * 函 数 名  : oal_spin_lock_exit
 * 功能描述  : 自旋锁释放
 * 输入参数  : pst_lock: 锁的地址
 */
OAL_STATIC OAL_INLINE void oal_spin_lock_exit(oal_spin_lock_stru *pst_lock)
{
}

/*
 * 函 数 名  : oal_spin_lock_irq_save
 * 功能描述  : 获得自旋锁的同时获得保存标志寄存器的值，并且失效本地中断。
 * 输入参数  : pst_lock:自旋锁地址
 *            pui_flags:标志寄存器
 */
OAL_STATIC OAL_INLINE void oal_spin_lock_irq_save(oal_spin_lock_stru *pst_lock, oal_uint *pui_flags)
{
    *pui_flags = mdrv_spin_lock_irqsave((mdrv_spin_lock_t*)&pst_lock);
}

/*
 * 函 数 名  : oal_spin_unlock_irq_restore
 * 功能描述  : 释放自旋锁的同时，恢复标志寄存器的值，恢复本地中断。它与oal_spin_lock_irq配对使用
 * 输入参数  : pst_lock:自旋锁地址
 *            pui_flags:标志寄存器
 */
OAL_STATIC OAL_INLINE void oal_spin_unlock_irq_restore(oal_spin_lock_stru *pst_lock, oal_uint *pui_flags)
{
    mdrv_spin_unlock_irqrestore((mdrv_spin_lock_t*)&pst_lock, *pui_flags);
}

/*
 * 函 数 名  : oal_mdrv_int_lock
 * 功能描述  : 关闭全局可屏蔽中断
 * 输入参数  : pui_flags:关闭全局中断前的中断状态值
 */
OAL_STATIC OAL_INLINE void oal_mdrv_int_lock(oal_uint *pui_flags)
{
    *pui_flags = mdrv_int_lock();
}
/*
 * 函 数 名  : oal_mdrv_int_unlock
 * 功能描述  : 开启全局可屏蔽中断
 * 输入参数  : pui_flags:中断状态值
 */
OAL_STATIC OAL_INLINE void oal_mdrv_int_unlock(oal_uint *pui_flags)
{
    mdrv_int_unlock(*pui_flags);
}

#define ATOMIC_INIT(x) { (x) }

/*
 * 函 数 名  : oal_atomic_set
 * 功能描述  : 原子地设置原子变量p_vector值为val
 * 输入参数  : vector: 需要进行原子操作的原子变量地址
 *            val  : 需要被设置成的值
 */
OAL_STATIC OAL_INLINE void oal_atomic_set(oal_atomic *vector, int32_t val)
{
    dpa_atomic_set(vector, val);
}

/*
 * 函 数 名  : oal_atomic_read
 * 功能描述  : 读取原子变量的值
 * 输入参数  : *vector: 需要进行原子操作的原子变量地址
 */
OAL_STATIC OAL_INLINE int32_t oal_atomic_read(oal_atomic *vector)
{
    return dpa_atomic_read(vector);
}

/*
 * 函 数 名  : oal_atomic_dec
 * 功能描述  : 原子的给入参减1，
 * 输入参数  : *vector: 需要进行原子操作的原子变量地址
 */
OAL_STATIC OAL_INLINE oal_void oal_atomic_dec(oal_atomic *vector)
{
    dpa_atomic_dec(vector);
}

/*
 * 函 数 名  : oal_atomic_inc
 * 功能描述  : 原子的给入参加一
 * 输入参数  : *vector: 需要进行原子操作的原子变量地址
 */
OAL_STATIC OAL_INLINE oal_void oal_atomic_inc(oal_atomic *vector)
{
    dpa_atomic_inc(vector);
}

/*
 * 函 数 名  : oal_atomic_add
 * 功能描述  : 原子地设置原子变量p_vector值加上val
 * 输入参数  : vector: 需要进行原子操作的原子变量地址
 *            val  : 需要加上的值
 */
OAL_STATIC OAL_INLINE oal_void oal_atomic_add(oal_atomic *vector, int32_t val)
{
    dpa_atomic_add(vector, val);
}

/*
 * 函 数 名  : oal_atomic_sub
 * 功能描述  : 原子地设置原子变量vector值减去val
 * 输入参数  : p_vector: 需要进行原子操作的原子变量地址
 *            val  : 需要加上的值
 */
OAL_STATIC OAL_INLINE oal_void oal_atomic_sub(oal_atomic *vector, int32_t val)
{
    dpa_atomic_sub(vector, val);
}
#endif
