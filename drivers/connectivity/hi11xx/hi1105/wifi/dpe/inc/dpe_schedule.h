/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpe schedule，兼容各平台线程、锁相关接口
 */

#ifndef DPE_SCHEDULE_H
#define DPE_SCHEDULE_H

/* 1 其他头文件包含 */
#include "oal_types.h"
#include "oal_schedule.h"
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "oal_schedule_wifi.h"
#endif

/* ---------------netbuflist 操作------------------- */
OAL_STATIC OAL_INLINE void dpe_netbuf_list_head_init(oal_netbuf_head_stru *netbuf_head)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    // DPA spinlock资源锁增加后替换oal_netbuf_list_head_init
    sbuf_queue_head_init(&netbuf_head->hdr);
#else
    oal_netbuf_list_head_init(netbuf_head);
#endif
}

/* ---------------spinlock锁------------------- */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#define OAL_SPIN_LOCK_EXIT(lock) oal_spin_lock_exit(lock)
#else
#define OAL_SPIN_LOCK_EXIT(lock)
#endif
/* ---------------mutex锁------------------- */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
/* DPA软件资源, 全部mutex正常初始化及使用 */
#define OAL_MUTEX_INIT(mutex) oal_mutex_init(mutex)
#define OAL_MUTEX_FREE(mutex) oal_mutex_free(mutex)
#else
#ifndef WIN32
#define OAL_MUTEX_INIT(mutex) mutex_init(mutex)
#else
#define OAL_MUTEX_INIT(mutex)
#endif
#define OAL_MUTEX_FREE(mutex)
#endif

/* ---------------vap lock 锁------------------- */
OAL_STATIC OAL_INLINE void dpe_cache_user_lock_irq_save(oal_spin_lock_stru *pst_lock, oal_uint *pui_flags)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_spin_lock_irq_save(pst_lock, pui_flags);
#else
    oal_spin_lock_bh(pst_lock);
#endif
}
OAL_STATIC OAL_INLINE void dpe_cache_user_unlock_irq_restore(oal_spin_lock_stru *pst_lock, oal_uint *pui_flags)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_spin_unlock_irq_restore(pst_lock, pui_flags);
#else
    oal_spin_unlock_bh(pst_lock);
#endif
}

/* ---------------timer lock锁------------------- */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#define dpe_timer_lock_init(_lock)                 /* dpa自带统一硬件锁 */
#define dpe_timer_lock_exit(_lock)
#define dpe_timer_spin_lock(_lock)
#define dpe_timer_spin_unlock(_lock)
#else
#define dpe_timer_lock_init(_lock)                  oal_spin_lock_init(_lock)
#define dpe_timer_lock_exit(_lock)
#define dpe_timer_spin_lock(_lock)                  oal_spin_lock(_lock)
#define dpe_timer_spin_unlock(_lock)                oal_spin_unlock(_lock)
#endif

/* ---------------tid_list锁------------------- */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#define dpe_tid_list_lock_init(_lock)                  oal_spin_lock_init(_lock)
#define dpe_tid_list_lock_exit(_lock)                  oal_spin_lock_exit(_lock)
#define dpe_tid_list_lock_irq_save(_lock, flags)       oal_spin_lock_irq_save(_lock, flags)
#define dpe_tid_list_unlock_irq_restore(_lock, flags)  oal_spin_unlock_irq_restore(_lock, flags)
#else
#define dpe_tid_list_lock_init(_lock)                  OAL_MUTEX_INIT(_lock)
#define dpe_tid_list_lock_exit(_lock)
#define dpe_tid_list_lock_irq_save(_lock, flags)       oal_mutex_lock(_lock)
#define dpe_tid_list_unlock_irq_restore(_lock, flags)  oal_mutex_unlock(_lock)
#endif

/* ---------------tid_info tid_queue_lock------------------- */
#define dpe_tid_queue_lock_init(_lock)                  oal_spin_lock_init(_lock)
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#define dpe_tid_queue_lock_exit(_lock)                  oal_spin_lock_exit(_lock)
#else
#define dpe_tid_queue_lock_exit(_lock)
#endif
OAL_STATIC OAL_INLINE void dpe_tid_queue_lock_irq_save(oal_spin_lock_stru *_lock, oal_uint *pui_flags)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
   oal_spin_lock_irq_save(_lock, pui_flags);
#else
    oal_spin_lock_bh(_lock); // 保持原host不变;
#endif
}
OAL_STATIC OAL_INLINE void dpe_tid_queue_unlock_irq_restore(oal_spin_lock_stru *_lock, oal_uint *pui_flags)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_spin_unlock_irq_restore(_lock, pui_flags);
#else
    oal_spin_unlock_bh(_lock);
#endif
}

/* ---------------tid_info tx_lock锁------------------- */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#define dpe_tid_tx_lock_init(_lock)                  oal_spin_lock_init(_lock)
#define dpe_tid_tx_lock_exit(_lock)                  oal_spin_lock_exit(_lock)
#define dpe_tid_tx_lock_irq_save(_lock, flags)       oal_spin_lock_irq_save(_lock, flags)
#define dpe_tid_tx_unlock_irq_restore(_lock, flags)  oal_spin_unlock_irq_restore(_lock, flags)
#else
#define dpe_tid_tx_lock_init(_lock)                  OAL_MUTEX_INIT(_lock)
#define dpe_tid_tx_lock_exit(_lock)
#define dpe_tid_tx_lock_irq_save(_lock, flags)       oal_mutex_lock(_lock)
#define dpe_tid_tx_unlock_irq_restore(_lock, flags)  oal_mutex_unlock(_lock)
#endif

/* ---------------tid_info tx_comp_lock锁------------------- */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#define dpe_tid_tx_comp_lock_init(_lock)                  oal_spin_lock_init(_lock)
#define dpe_tid_tx_comp_lock_exit(_lock)                  oal_spin_lock_exit(_lock)
#define dpe_tid_tx_comp_lock_irq_save(_lock, flags)       oal_spin_lock_irq_save(_lock, flags)
#define dpe_tid_tx_comp_unlock_irq_restore(_lock, flags)  oal_spin_unlock_irq_restore(_lock, flags)
#else
#define dpe_tid_tx_comp_lock_init(_lock)                  OAL_MUTEX_INIT(_lock)
#define dpe_tid_tx_comp_lock_exit(_lock)
#define dpe_tid_tx_comp_lock_irq_save(_lock, flags)       oal_mutex_lock(_lock)
#define dpe_tid_tx_comp_unlock_irq_restore(_lock, flags)  oal_mutex_unlock(_lock)
#endif

/* ---------------rx ba reorder lock------------------- */
#define dpe_rx_reorder_lock_init(_lock)                  oal_spin_lock_init(_lock)
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#define dpe_rx_reorder_lock_exit(_lock)                  oal_spin_lock_exit(_lock)
#else
#define dpe_rx_reorder_lock_exit(_lock)
#endif
OAL_STATIC OAL_INLINE void dpe_rx_reorder_lock_irq_save(oal_spin_lock_stru *_lock, oal_uint *pui_flags)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_spin_lock_irq_save(_lock, pui_flags);
#else
    oal_spin_lock(_lock); // 保持原host不变;
#endif
}
OAL_STATIC OAL_INLINE void dpe_rx_reorder_unlock_irq_restore(oal_spin_lock_stru *_lock, oal_uint *pui_flags)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_spin_unlock_irq_restore(_lock, pui_flags);
#else
    oal_spin_unlock(_lock);
#endif
}

/* ---------------rx mpdu list lock------------------- */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#define dpe_rx_mpdu_list_spin_lock_init(_lock)
#else
#define dpe_rx_mpdu_list_spin_lock_init(_lock)                  oal_spin_lock_init(_lock)
#endif
OAL_STATIC OAL_INLINE void dpe_rx_mpdu_list_lock_irq_save(oal_spin_lock_stru *_lock, oal_uint *pui_flags)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_mdrv_int_lock(pui_flags);  // DPA禁用中断, rxdata和pcie isr都在core0
#else
    oal_spin_lock_irq_save(_lock, pui_flags); // 保持原host不变;
#endif
}
OAL_STATIC OAL_INLINE void dpe_rx_mpdu_list_unlock_irq_restore(oal_spin_lock_stru *_lock, oal_uint *pui_flags)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_mdrv_int_unlock(pui_flags);
#else
    oal_spin_unlock_irq_restore(_lock, pui_flags);
#endif
}
#endif /* end of dpe schedule */
