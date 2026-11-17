/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: circ_queue.c header file
 * Author: dpa drivers
 */
#ifndef CIRC_QUEUE_H
#define CIRC_QUEUE_H
#include "oal_types.h"
#include "oal_schedule.h"

typedef struct {
    uint16_t head; // 队列头索引，入队索引
    uint16_t tail; // 队列尾索引，出队索引
    uint16_t size; // 队列总大小,深度，2^n
    uint16_t node_bytes; // 每个节点的长度
    uintptr_t mem_addr; // 队列管理的内存空间（size * node_bytes）起始地址
    uint16_t cur_cnt;
    mdrv_spin_lock_t spinlock;
} circ_queue_t;

/*
 * 功能描述: 队列是否为空
 */
static inline int32_t circ_queue_empty(circ_queue_t *queue)
{
    int32_t ret;
    unsigned long irq_sts;
    irq_sts = mdrv_spin_lock_irqsave(&queue->spinlock);
    ret = (queue->head == queue->tail);
    mdrv_spin_unlock_irqrestore(&queue->spinlock, irq_sts);
    return ret;
}

static inline void circ_queue_clear(circ_queue_t *queue)
{
    unsigned long irq_sts;
    irq_sts = mdrv_spin_lock_irqsave(&queue->spinlock);
    queue->head = 0;
    queue->tail = 0;
    mdrv_spin_unlock_irqrestore(&queue->spinlock, irq_sts);
}

int32_t circ_queue_init(circ_queue_t *queue, uint16_t size, uint16_t node_bytes, uintptr_t mem_addr);
void circ_queue_deinit(circ_queue_t *queue);
int32_t circ_queue_enqueue(circ_queue_t *queue, uintptr_t src_node);
uintptr_t circ_queue_dequeue(circ_queue_t *queue);
uintptr_t circ_queue_head(circ_queue_t *queue);
uint16_t circ_queue_size(circ_queue_t *queue);

#endif // CIRC_QUEUE_H

