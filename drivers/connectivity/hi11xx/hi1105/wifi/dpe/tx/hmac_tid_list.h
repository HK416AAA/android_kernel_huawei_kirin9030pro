/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : Hmac tid队列操作模块
 * 作    者 : wifi
 * 创建日期 : 2021年5月18日
 */

#ifndef HMAC_TID_LIST_H
#define HMAC_TID_LIST_H

#include "dpe_wlan_tid.h"
#include "dpe_task.h"
#include "dpe_wlan_resource.h"

/* hmac_tid_list涉及加锁操作的接口, 如hmac_tid_list_for_each, 不允许在原子上下文(irq/softirq/spinlock...)中使用 */
typedef struct {
    oal_dlist_head_stru list;
    uint8_t tid_list_lock_idx;
    const hmac_tid_list_ops *ops;
} hmac_tid_list_stru;

static inline void hmac_tid_list_init(hmac_tid_list_stru *tid_list, const hmac_tid_list_ops *ops,  uint8_t tx_list_idx)
{
    oal_dlist_init_head(&tid_list->list);
    tid_list->tid_list_lock_idx = tx_list_idx;
    dpe_tid_list_lock_init(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx));
    tid_list->ops = ops;
}

static inline uint8_t hmac_tid_list_for_each_nolock(hmac_tid_list_stru *tid_list, hmac_tid_list_func func, void *param)
{
    oal_dlist_head_stru *entry, *entry_tmp;

    if (oal_unlikely(!tid_list->ops->tid_info_getter)) {
        return OAL_FALSE;
    }

    oal_dlist_search_for_each_safe(entry, entry_tmp, &tid_list->list) {
        if (func(tid_list->ops->tid_info_getter(entry), param) == OAL_RETURN) {
            return OAL_TRUE;
        }
    }

    return OAL_FALSE;
}

static inline uint8_t hmac_tid_list_for_each(hmac_tid_list_stru *tid_list, hmac_tid_list_func func, void *param)
{
    uint8_t ret;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_uint lock_flag;
#endif
    dpe_tid_list_lock_irq_save(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
    ret = hmac_tid_list_for_each_nolock(tid_list, func, param);
    dpe_tid_list_unlock_irq_restore(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
    return ret;
}

static inline uint8_t hmac_tid_list_entry_count(hmac_tid_list_stru *tid_list)
{
    uint8_t count = 0;
    oal_dlist_head_stru *entry = NULL;
    oal_dlist_head_stru *entry_tmp = NULL;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_uint lock_flag;
#endif
    dpe_tid_list_lock_irq_save(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
    oal_dlist_search_for_each_safe(entry, entry_tmp, &tid_list->list) {
        count++;
    }
    dpe_tid_list_unlock_irq_restore(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
    return count;
}

static inline uint8_t hmac_tid_entry_equal(hmac_tid_info_stru *tid_info_entry, void *tid_info)
{
    if (tid_info_entry->user_index == ((hmac_tid_info_stru *)tid_info)->user_index &&
        tid_info_entry->tid_no == ((hmac_tid_info_stru *)tid_info)->tid_no) {
        return OAL_RETURN;
    }

    return OAL_CONTINUE;
}

static inline uint8_t hmac_tid_entry_exists_nolock(hmac_tid_list_stru *tid_list, hmac_tid_info_stru *tid_info)
{
    return hmac_tid_list_for_each_nolock(tid_list, hmac_tid_entry_equal, (void *)tid_info);
}

static inline hmac_tid_info_stru *hmac_tid_list_dequeue_nolock(hmac_tid_list_stru *tid_list)
{
    if (oal_dlist_is_empty(&tid_list->list) || oal_unlikely(!tid_list->ops->tid_info_getter)) {
        return NULL;
    }

    return tid_list->ops->tid_info_getter(oal_dlist_delete_head(&tid_list->list));
}

static inline uint32_t hmac_tid_list_enqueue_nolock(hmac_tid_list_stru *tid_list, hmac_tid_info_stru *tid_info)
{
    if (hmac_tid_entry_exists_nolock(tid_list, tid_info) || oal_unlikely(!tid_list->ops->entry_getter)) {
        return OAL_FAIL;
    }

    oal_dlist_add_tail(tid_list->ops->entry_getter(tid_info), &tid_list->list);
    return OAL_SUCC;
}

static inline uint32_t hmac_tid_list_enqueue(hmac_tid_list_stru *tid_list, hmac_tid_info_stru *tid_info)
{
    uint32_t ret;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_uint lock_flag;
#endif
    dpe_tid_list_lock_irq_save(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
    ret = hmac_tid_list_enqueue_nolock(tid_list, tid_info);
    dpe_tid_list_unlock_irq_restore(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
    return ret;
}

static inline void hmac_tid_list_delete_nolock(hmac_tid_list_stru *tid_list, hmac_tid_info_stru *tid_info)
{
    if (oal_unlikely(!tid_list->ops->entry_getter)) {
        return;
    }

    oal_dlist_delete_entry(tid_list->ops->entry_getter(tid_info));
}

/*
功能: 删除list特定节点
*/
static inline void hmac_tid_list_delete(hmac_tid_list_stru *tid_list, hmac_tid_info_stru *tid_info)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_uint lock_flag;
#endif
    dpe_tid_list_lock_irq_save(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
    hmac_tid_list_delete_nolock(tid_list, tid_info);
    dpe_tid_list_unlock_irq_restore(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
}

/*
功能: 查找list并且删除
*/
static inline void hmac_tid_list_search_delete(hmac_tid_list_stru *tid_list, hmac_tid_info_stru *tid_info)
{
    oal_dlist_head_stru *entry = NULL;
    oal_dlist_head_stru *entry_tmp = NULL;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_uint lock_flag;
#endif
    if (oal_unlikely(!tid_list->ops->tid_info_getter)) {
        return;
    }

    dpe_tid_list_lock_irq_save(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
    oal_dlist_search_for_each_safe(entry, entry_tmp, &tid_list->list) {
        if (tid_list->ops->tid_info_getter(entry) == tid_info) {
            hmac_tid_list_delete_nolock(tid_list, tid_info);
            break;
        }
    }
    dpe_tid_list_unlock_irq_restore(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
}

static inline void hmac_tid_list_clear_nolock(hmac_tid_list_stru *tid_list)
{
    while (!oal_dlist_is_empty(&tid_list->list)) {
        oal_dlist_delete_head(&tid_list->list);
    }
}

static inline void hmac_tid_list_clear(hmac_tid_list_stru *tid_list)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_uint lock_flag;
#endif
    dpe_tid_list_lock_irq_save(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
    hmac_tid_list_clear_nolock(tid_list);
    dpe_tid_list_unlock_irq_restore(dpe_get_tid_list_lock(tid_list->tid_list_lock_idx), &lock_flag);
}
#endif
