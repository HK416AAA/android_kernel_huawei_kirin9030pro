/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: 循环队列
 * Author: platform drivers
 */

#include "oal_util.h"
#include "oal_circ_queue.h"

/*
 * 功能描述: 队列总大小mask
 */
static inline uint16_t oal_circ_queue_mask(const oal_circ_queue_t *queue)
{
    return (queue->size - 1);
}

/*
 * 功能描述: 获取节点地址
 */
static inline uintptr_t oal_circ_queue_node(const oal_circ_queue_t *queue, uint16_t idx)
{
    return (queue->mem_addr + ((idx & oal_circ_queue_mask(queue)) * queue->node_bytes));
}

/*
 * 功能描述: 队列剩余空间
 */
static inline uint16_t oal_circ_queue_space(oal_circ_queue_t *queue)
{
    return (uint16_t)(queue->tail - (queue->head + 1)) & oal_circ_queue_mask(queue);
}

/*
 * 功能描述: 队列初始化
 * size ：队列大小，深度, 最多只能放size - 1个节点, size必须为2的次方
 * node_bytes ：队列每个单元节点的字节长度
 * mem_addr ：队列内存的起始地址， 长度应该等于size * node_bytes
 */
int32_t oal_circ_queue_init(oal_circ_queue_t *queue, uint16_t size, uint16_t node_bytes, uintptr_t mem_addr)
{
    if (unlikely((queue == NULL) || (size == 0) || (node_bytes == 0) || (mem_addr == 0))) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oal_circ_queue_init failed");
        return -OAL_EINVAL;
    }

    if ((size & (size - 1)) != 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oal_circ_queue_init failed, size = %d should be power of 2", size);
        return -OAL_EINVAL;
    }

    oal_spin_lock_init(&queue->spinlock);

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
void oal_circ_queue_deinit(oal_circ_queue_t *queue)
{
    memset_s(queue, sizeof(oal_circ_queue_t), 0, sizeof(oal_circ_queue_t));
}

/*
 * 功能描述: 入队列一个节点
 */
int32_t oal_circ_queue_enqueue(oal_circ_queue_t *queue, uintptr_t src_node)
{
    uintptr_t dis_node;
    unsigned long irq_sts;

    oal_spin_lock_irq_save(&queue->spinlock, &irq_sts);

    // 检查队列是否已满
    if (oal_circ_queue_space(queue) == 0) {
        oal_spin_unlock_irq_restore(&queue->spinlock, &irq_sts);
        oal_print_mpxx_log(MPXX_LOG_ERR, "circuit queue is full");
        return -OAL_FAIL;
    }

    // 保存节点内容
    dis_node = oal_circ_queue_node(queue, queue->head);
    if (memcpy_s((void *)dis_node, queue->node_bytes, (void *)src_node, queue->node_bytes) != EOK) {
        oal_spin_unlock_irq_restore(&queue->spinlock, &irq_sts);
        oal_print_mpxx_log(MPXX_LOG_ERR, "node copy failed");
        return -OAL_FAIL;
    }

    // 索引更新到下一位置
    queue->head = (queue->head + 1) & oal_circ_queue_mask(queue);
    queue->cur_cnt++;

    oal_spin_unlock_irq_restore(&queue->spinlock, &irq_sts);
    return OAL_SUCC;
}

/*
 * 功能描述: 从循环队列中，取出最早入队列的节点并将其从队列中删除
 */
uintptr_t oal_circ_queue_dequeue(oal_circ_queue_t *queue)
{
    uintptr_t node;
    unsigned long irq_sts;

    oal_spin_lock_irq_save(&queue->spinlock, &irq_sts);

    // 检查是否为空
    if (queue->head == queue->tail) {
        oal_spin_unlock_irq_restore(&queue->spinlock, &irq_sts);
        return 0;
    }

    node = oal_circ_queue_node(queue, queue->tail);

    // 索引更新到下一位置
    queue->tail = (queue->tail + 1) & oal_circ_queue_mask(queue);
    queue->cur_cnt--;

    oal_spin_unlock_irq_restore(&queue->spinlock, &irq_sts);
    return node;
}

/*
 * 功能描述: 从循环队列中，取出最早入队列的节点并不删除队列中节点
 */
uintptr_t oal_circ_queue_head(oal_circ_queue_t *queue)
{
    uintptr_t node;
    unsigned long irq_sts;

    oal_spin_lock_irq_save(&queue->spinlock, &irq_sts);

    // 检查是否为空
    if (queue->head == queue->tail) {
        oal_spin_unlock_irq_restore(&queue->spinlock, &irq_sts);
        return 0;
    }

    node = oal_circ_queue_node(queue, queue->tail);

    oal_spin_unlock_irq_restore(&queue->spinlock, &irq_sts);
    return node;
}

/*
 * 功能描述: 获取当前队列已存在节点个数
 */
uint16_t oal_circ_queue_size(oal_circ_queue_t *queue)
{
    uint16_t ret;
    unsigned long irq_sts;
    oal_spin_lock_irq_save(&queue->spinlock, &irq_sts);
    ret = queue->cur_cnt;
    oal_spin_unlock_irq_restore(&queue->spinlock, &irq_sts);
    return ret;
}
