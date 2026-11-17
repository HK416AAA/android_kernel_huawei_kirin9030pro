/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oal_dpa_net_queue.h
 * Author: dpa drivers
 */

#ifndef OAL_DPA_NET_QUEUE_H
#define OAL_DPA_NET_QUEUE_H

#include "oal_util.h"
#include "oal_net.h"
#include "sbuf_api.h"

typedef struct {
    struct sbuf_header hdr;
    mdrv_spin_lock_t lock;
} oal_netbuf_head_stru;

extern uint32_t g_spin_lock_alloc_succ_cnt;

OAL_STATIC OAL_INLINE oal_netbuf_stru *oal_netbuff_next(oal_netbuf_stru *pst_buf);

/* 遍历双向链表使用时请在其后加大括号 */
#define hcc_netbuf_search_for_each(_dlist_pos, _dilst_head) \
        for ((_dlist_pos) = (oal_netbuf_stru *)((_dilst_head)->hdr).next; \
            (_dlist_pos) != (oal_netbuf_stru *)(&(_dilst_head)->hdr); \
            (_dlist_pos) = oal_netbuff_next(_dlist_pos))

/* 遍列netbuf链表，并可安全删除某个节点 */
#define hcc_netbuf_search_for_each_safe(_dlist_pos, n, _dilst_head) \
        for ((_dlist_pos) = (oal_netbuf_stru *)((_dilst_head)->hdr).next, (n) = oal_netbuff_next(_dlist_pos); \
            (_dlist_pos) != (oal_netbuf_stru *)(&(_dilst_head)->hdr); \
            (_dlist_pos) = (n), (n) = oal_netbuff_next(_dlist_pos))

OAL_STATIC OAL_INLINE oal_netbuf_stru *oal_netbuff_next(oal_netbuf_stru *pst_buf)
{
    return ((pst_buf != NULL) ? get_sbuf_next(pst_buf) : NULL);
}
/*
 * 函 数 名  : oal_netbuf_list_head_init
 * 功能描述  : 初始化sbuf队列头
 */
static inline void oal_netbuf_list_head_init(oal_netbuf_head_stru *head)
{
    sbuf_queue_head_init(&head->hdr);
    if (mdrv_spin_lock_zalloc(&head->lock)) {
        bsp_print("spinlock init fail!\n");
        // 异常时需要触发整机异常
        sys_abort(1);
        return;
    }
    g_spin_lock_alloc_succ_cnt++;
}

/*
 * 函 数 名  : oal_netbuf_list_head_deinit
 * 功能描述  : 初始化sbuf队列头
 */
static inline void oal_netbuf_list_head_deinit(oal_netbuf_head_stru *head)
{
    mdrv_spin_lock_free(&head->lock);
}

/*
 * 函 数 名  : oal_netbuf_list_len
 * 功能描述  : 获取sbuf list 链表长度
 */
static inline uint32_t oal_netbuf_list_len(oal_netbuf_head_stru *head)
{
    return (uint32_t)sbuf_queue_len(&head->hdr);
}

/*
 * 函 数 名  : oal_netbuf_list_empty
 * 功能描述  : 判断链表是否为空
 */
static inline int32_t oal_netbuf_list_empty(oal_netbuf_head_stru *head)
{
    return sbuf_queue_empty(&head->hdr);
}

/*
 * 函 数 名  : oal_netbuf_addlist_tail
 * 功能描述  : 添加到链表队列的尾部(持锁)
 */
static inline void oal_netbuf_addlist_tail(oal_netbuf_head_stru *head, oal_netbuf_stru *buf)
{
    unsigned long irq_sts;

    irq_sts =  mdrv_spin_lock_irqsave(&head->lock);
    sbuf_enqueue_tail(&head->hdr, buf);
    mdrv_spin_unlock_irqrestore(&head->lock, irq_sts);
}

/*
 * 函 数 名  : oal_netbuf_addlist_tail_nolock
 * 功能描述  : 添加到链表队列的尾部
 */
static inline void oal_netbuf_addlist_tail_nolock(oal_netbuf_head_stru *head, oal_netbuf_stru *buf)
{
    return sbuf_enqueue_tail(&head->hdr, buf);
}

/*
 * 函 数 名  : oal_netbuf_addlist_head
 * 功能描述  : 添加到链表队列的头部(持锁)
 */
static inline void oal_netbuf_addlist_head(oal_netbuf_head_stru *head, oal_netbuf_stru *buf)
{
    unsigned long irq_sts;

    irq_sts =  mdrv_spin_lock_irqsave(&head->lock);
    sbuf_enqueue_head(&head->hdr, buf);
    mdrv_spin_unlock_irqrestore(&head->lock, irq_sts);
}

/*
 * 函 数 名  : oal_netbuf_addlist_head_nolock
 * 功能描述  : 添加到链表队列的头部
 */
static inline void oal_netbuf_addlist_head_nolock(oal_netbuf_head_stru *head, oal_netbuf_stru *buf)
{
    return sbuf_enqueue_head(&head->hdr, buf);
}

/*
 * 函 数 名  : oal_netbuf_delist_head
 * 功能描述  : 从队列头部删除(持锁)
 */
static inline oal_netbuf_stru *oal_netbuf_delist_head(oal_netbuf_head_stru *head)
{
    unsigned long irq_sts;
    oal_netbuf_stru *netbuf = NULL;

    irq_sts =  mdrv_spin_lock_irqsave(&head->lock);
    netbuf = sbuf_dequeue(&head->hdr);
    mdrv_spin_unlock_irqrestore(&head->lock, irq_sts);

    return netbuf;
}

/*
 * 函 数 名  : oal_netbuf_delist_head_nolock
 * 功能描述  : 从队列头部删除
 */
static inline oal_netbuf_stru *oal_netbuf_delist_head_nolock(oal_netbuf_head_stru *head)
{
    return sbuf_dequeue(&head->hdr);
}

/*
 * 函 数 名  : oal_netbuf_delist_tail
 * 功能描述  :  从队列尾部删除，因为单向链表缘故，实现需要遍历，效率低
 *             建议选择从尾部加，从头部删除的方式(持锁)
 */
static inline oal_netbuf_stru *oal_netbuf_delist_tail(oal_netbuf_head_stru *head)
{
    unsigned long irq_sts;
    oal_netbuf_stru *netbuf = NULL;

    irq_sts =  mdrv_spin_lock_irqsave(&head->lock);
    netbuf = sbuf_dequeue_tail(&head->hdr);
    mdrv_spin_unlock_irqrestore(&head->lock, irq_sts);

    return netbuf;
}

/*
 * 函 数 名  : oal_netbuf_delist_tail_nolock
 * 功能描述  :  从队列尾部删除，因为单向链表缘故，实现需要遍历，效率低
 *             建议选择从尾部加，从头部删除的方式
 */
static inline oal_netbuf_stru *oal_netbuf_delist_tail_nolock(oal_netbuf_head_stru *head)
{
    return sbuf_dequeue_tail(&head->hdr);
}

/*
 * 函 数 名  : oal_netbuf_head_next
 * 功能描述  :  获取队列头的第一个netbuf
 */
static inline oal_netbuf_stru *oal_netbuf_head_next(oal_netbuf_head_stru *head)
{
    return sbuf_peek(&head->hdr);
}

/*
 * 函 数 名  : oal_netbuf_tail_next
 * 功能描述  :  获取队列尾的第一个netbuf
 */
static inline oal_netbuf_stru *oal_netbuf_tail_next(oal_netbuf_head_stru *head)
{
    return sbuf_peek_tail(&head->hdr);
}

/*
 * 函 数 名  : oal_netbuf_clear_list
 * 功能描述  :  清除链表，并将其中的内存释放掉（dpa 新增），返回处理掉的netbuf个数(持锁)
 */
static inline uint32_t oal_netbuf_clear_list(oal_netbuf_head_stru *head)
{
    uint32_t ret;
    unsigned long irq_sts;

    irq_sts =  mdrv_spin_lock_irqsave(&head->lock);
    ret = (uint32_t)sbuf_queue_clear(&head->hdr);
    mdrv_spin_unlock_irqrestore(&head->lock, irq_sts);

    return ret;
}

/*
 * 函 数 名  : oal_netbuf_clear_list_nolock
 * 功能描述  :  清除链表，并将其中的内存释放掉（dpa 新增），返回处理掉的netbuf个数
 */
static inline uint32_t oal_netbuf_clear_list_nolock(oal_netbuf_head_stru *head)
{
    return (uint32_t)sbuf_queue_clear(&head->hdr);
}

/*
 * 函 数 名  : oal_netbuf_queue_splice_tail_init
 * 功能描述  : 链表合并，将链表list合并到head中，无需锁
 */
static inline void oal_netbuf_queue_splice_tail_init(oal_netbuf_head_stru *list, oal_netbuf_head_stru *head)
{
    sbuf_queue_splice_tail_init(&list->hdr, &head->hdr);
}

/*
 * 函 数 名  : oal_netbuf_delete
 * 功能描述  : 删除链表中的某个netbuf，持锁
 */
static inline void oal_netbuf_delete(oal_netbuf_stru *netbuf, oal_netbuf_head_stru *head)
{
    unsigned long irq_sts;

    irq_sts =  mdrv_spin_lock_irqsave(&head->lock);
    sbuf_unlink(netbuf, &head->hdr);
    mdrv_spin_unlock_irqrestore(&head->lock, irq_sts);
}

/*
 * 函 数 名  : oal_netbuf_delete_nolock
 * 功能描述  : 删除链表中的某个netbuf，无锁
 */
static inline void oal_netbuf_delete_nolock(oal_netbuf_stru *netbuf, oal_netbuf_head_stru *head)
{
    sbuf_unlink(netbuf, &head->hdr);
}

#endif // OAL_DPA_NET_QUEUE_H