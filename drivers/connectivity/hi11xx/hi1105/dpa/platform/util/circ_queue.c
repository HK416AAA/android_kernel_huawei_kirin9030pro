/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: implementation of universal circular queue
 * Author: dpa drivers
 */

#include "oal_util.h"
#include "securec.h"
#include "oam_logger.h"
#include "circ_queue.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_CIRC_QUEUE_C

/*
 * 功能描述: 队列总大小mask
 */
static inline uint16_t circ_queue_mask(const circ_queue_t *queue)
{
    return (queue->size - 1);
}

/*
 * 功能描述: 获取节点地址
 */
static inline uintptr_t circ_queue_node(const circ_queue_t *queue, uint16_t idx)
{
    return (queue->mem_addr + ((idx & circ_queue_mask(queue)) * queue->node_bytes));
}

/*
 * 功能描述: 队列剩余空间
 */
static inline uint16_t circ_queue_space(circ_queue_t *queue)
{
    return (uint16_t)(queue->tail - (queue->head + 1)) & circ_queue_mask(queue);
}

/*
 * 功能描述: 队列初始化
 * size ：队列大小，深度, 最多只能放size - 1个节点, size必须为2的次方
 * node_bytes ：队列每个单元节点的字节长度
 * mem_addr ：队列内存的起始地址， 长度应该等于size * node_bytes
 */
int32_t circ_queue_init(circ_queue_t *queue, uint16_t size, uint16_t node_bytes, uintptr_t mem_addr)
{
    if ((queue == NULL) || (size == 0) || (node_bytes == 0) || (mem_addr == 0)) {
        oam_error_log0(0, OAM_SF_DPA, "circ_queue_init failed");
        return -OAL_EINVAL;
    }

    if ((size & (size - 1)) != 0) {
        oam_error_log1(0, OAM_SF_DPA, "circ_queue_init failed, size = %d should be power of 2", size);
        return -OAL_EINVAL;
    }

    if (mdrv_spin_lock_zalloc(&queue->spinlock)) {
        return -OAL_EINVAL;
    }

    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    queue->node_bytes = node_bytes;
    queue->mem_addr = mem_addr;
    queue->cur_cnt = 0;

    return OAL_SUCC;
}

/*
 * 功能描述: 队列去初始化
 */
void circ_queue_deinit(circ_queue_t *queue)
{
    if (queue == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "circ_queue_deinit param check fail");
        return;
    }
    mdrv_spin_lock_free(&queue->spinlock);
    memset_s(queue, sizeof(circ_queue_t), 0, sizeof(circ_queue_t));
}

/*
 * 功能描述: 入队列一个节点
 */
int32_t circ_queue_enqueue(circ_queue_t *queue, uintptr_t src_node)
{
    uintptr_t dis_node;
    unsigned long irq_sts;
    if (queue == NULL || src_node == 0) {
        oam_error_log0(0, OAM_SF_DPA, "circ queue enqueue param check fail");
        return -OAL_FAIL;
    }

    irq_sts = mdrv_spin_lock_irqsave(&queue->spinlock);

    // 检查队列是否已满
    if (circ_queue_space(queue) == 0) {
        mdrv_spin_unlock_irqrestore(&queue->spinlock, irq_sts);
        oam_error_log1(0, OAM_SF_DPA, "circuit queue is full, cur len = %d", queue->cur_cnt);
        return -OAL_FAIL;
    }

    // 保存节点内容
    dis_node = circ_queue_node(queue, queue->head);
    if (memcpy_s((void *)dis_node, queue->node_bytes, (void *)src_node, queue->node_bytes) != EOK) {
        mdrv_spin_unlock_irqrestore(&queue->spinlock, irq_sts);
        oam_error_log0(0, OAM_SF_DPA, "node copy failed");
        return -OAL_FAIL;
    }

    // 索引更新到下一位置
    queue->head = (queue->head + 1) & circ_queue_mask(queue);
    queue->cur_cnt++;

    mdrv_spin_unlock_irqrestore(&queue->spinlock, irq_sts);
    return OAL_SUCC;
}

/*
 * 功能描述: 从循环队列中，取出最早入队列的节点并将其从队列中删除
 */
uintptr_t circ_queue_dequeue(circ_queue_t *queue)
{
    uintptr_t node;
    unsigned long irq_sts;
    if (queue == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "circ queue dequeue param check fail");
        return 0;
    }

    irq_sts = mdrv_spin_lock_irqsave(&queue->spinlock);

    // 检查是否为空
    if (queue->head == queue->tail) {
        mdrv_spin_unlock_irqrestore(&queue->spinlock, irq_sts);
        return 0;
    }

    node = circ_queue_node(queue, queue->tail);

    // 索引更新到下一位置
    queue->tail = (queue->tail + 1) & circ_queue_mask(queue);
    queue->cur_cnt--;

    mdrv_spin_unlock_irqrestore(&queue->spinlock, irq_sts);
    return node;
}

/*
 * 功能描述: 从循环队列中，取出最早入队列的节点并不删除队列中节点
 */
uintptr_t circ_queue_head(circ_queue_t *queue)
{
    uintptr_t node;
    unsigned long irq_sts;
    if (queue == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "circ queue head param check fail");
        return 0;
    }

    irq_sts = mdrv_spin_lock_irqsave(&queue->spinlock);

    // 检查是否为空
    if (queue->head == queue->tail) {
        mdrv_spin_unlock_irqrestore(&queue->spinlock, irq_sts);
        return 0;
    }

    node = circ_queue_node(queue, queue->tail);

    mdrv_spin_unlock_irqrestore(&queue->spinlock, irq_sts);
    return node;
}

/*
 * 功能描述: 获取当前队列已存在节点个数
 */
uint16_t circ_queue_size(circ_queue_t *queue)
{
    uint16_t ret;
    unsigned long irq_sts;
    if (queue == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "circ queue size param check fail");
        return 0;
    }

    irq_sts = mdrv_spin_lock_irqsave(&queue->spinlock);
    ret = queue->cur_cnt;
    mdrv_spin_unlock_irqrestore(&queue->spinlock, irq_sts);
    return ret;
}
