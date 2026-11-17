/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: dynamic fifoqueue
 * Create: 2025-7-21
 */

#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include "stack_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct {
    void **data;        // 存储元素的指针数组
    size_t capacity;    // 队列总容量
    size_t size;        // 当前元素数量
    size_t head;        // 队列头索引
    size_t tail;        // 队列尾索引（下一个入队位置）
} dynamic_fifo_queue;

dynamic_fifo_queue *create_dynamic_fifo_queue(size_t initial_capacity);

void destroy_dynamic_fifo_queue(dynamic_fifo_queue *queue);

bool dynamic_fifo_enqueue(dynamic_fifo_queue *queue, void *item);

void *dynamic_fifo_dequeue(dynamic_fifo_queue *queue);

bool is_dynamic_fifo_queue_empty(const dynamic_fifo_queue *queue);

size_t dynamic_fifo_queue_size(const dynamic_fifo_queue *queue);

size_t dynamic_fifo_queue_capacity_size(const dynamic_fifo_queue *queue);

void *dynamic_fifo_queue_first(dynamic_fifo_queue *queue);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DYNAMIC_QUEUE_H */