/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: 循环队列
 * Author: platform drivers
 */

#ifndef OAL_CIRC_QUEUE_H
#define OAL_CIRC_QUEUE_H

#include "oal_schedule.h"

typedef struct {
    uint16_t head; // 队列头索引，入队索引
    uint16_t tail; // 队列尾索引，出队索引
    uint16_t size; // 队列总大小,深度，2^n
    uint16_t node_bytes; // 每个节点的长度
    uintptr_t mem_addr; // 队列管理的内存空间（size * node_bytes）起始地址
    uint16_t cur_cnt;
    oal_spin_lock_stru spinlock;
} oal_circ_queue_t;

/*
 * 功能描述: 队列是否为空
 */
static inline int32_t oal_circ_queue_empty(oal_circ_queue_t *queue)
{
    int32_t ret;
    unsigned long irq_sts;
    oal_spin_lock_irq_save(&queue->spinlock, &irq_sts);
    ret = (queue->head == queue->tail);
    oal_spin_unlock_irq_restore(&queue->spinlock, &irq_sts);
    return ret;
}

static inline void oal_circ_queue_clear(oal_circ_queue_t *queue)
{
    unsigned long irq_sts;
    oal_spin_lock_irq_save(&queue->spinlock, &irq_sts);
    queue->head = 0;
    queue->tail = 0;
    oal_spin_unlock_irq_restore(&queue->spinlock, &irq_sts);
}

int32_t oal_circ_queue_init(oal_circ_queue_t *queue, uint16_t size, uint16_t node_bytes, uintptr_t mem_addr);
void oal_circ_queue_deinit(oal_circ_queue_t *queue);
int32_t oal_circ_queue_enqueue(oal_circ_queue_t *queue, uintptr_t src_node);
uintptr_t oal_circ_queue_dequeue(oal_circ_queue_t *queue);
uintptr_t oal_circ_queue_head(oal_circ_queue_t *queue);
uint16_t oal_circ_queue_size(oal_circ_queue_t *queue);

#endif