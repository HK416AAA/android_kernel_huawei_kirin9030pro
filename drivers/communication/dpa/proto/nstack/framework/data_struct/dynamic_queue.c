/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

#include "securec.h"
#include "stack_log.h"
#include "stack_mem.h"
#include "dynamic_queue.h"

#define QUEUE_RESIZE_RATIO 2

// 创建队列
dynamic_fifo_queue *create_dynamic_fifo_queue(size_t initial_capacity)
{
    dynamic_fifo_queue *queue = stack_malloc(sizeof(dynamic_fifo_queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->capacity = initial_capacity;
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
    queue->data = stack_malloc(initial_capacity * sizeof(void *));
    if (queue->data == NULL) {
        stack_free(queue);
        return NULL;
    }
    return queue;
}

// 销毁队列
void destroy_dynamic_fifo_queue(dynamic_fifo_queue *queue)
{
    if (queue) {
        stack_free(queue->data);
        stack_free(queue);
    }
}

// 扩展队列容量
static bool resize_dynamic_fifo_queue(dynamic_fifo_queue *queue)
{
    size_t new_capacity = queue->capacity * QUEUE_RESIZE_RATIO;
    void **new_data = stack_malloc(new_capacity * sizeof(void *));
    if (new_data == NULL)  {
        NS_ERR("dynamic_fifo resize alloc new queue failed");
        return false;
    }
    // 复制元素到新数组
    if (queue->head < queue->tail) {
        // 连续存储的情况
        if (memcpy_s(new_data, new_capacity, queue->data + queue->head, queue->size * sizeof(void *)) != EOK) {
            stack_free(new_data);
            NS_ERR("dynamic_fifo resize copy new 1 failed");
            return false;
        }
    } else {
        // 队列环绕的情况
        size_t part1_size = queue->capacity - queue->head;
        if (memcpy_s(new_data, new_capacity, queue->data + queue->head, part1_size * sizeof(void *)) != EOK) {
            stack_free(new_data);
            NS_ERR("dynamic_fifo resize copy new 2 failed");
            return false;
        }
        if (memcpy_s(new_data + part1_size, new_capacity - part1_size,
            queue->data, queue->tail * sizeof(void *)) != EOK) {
            stack_free(new_data);
            NS_ERR("dynamic_fifo resize copy new 3 failed");
            return false;
        }
    }
    stack_free(queue->data);
    queue->data = new_data;
    queue->capacity = new_capacity;
    queue->head = 0;
    queue->tail = queue->size;
    return true;
}

// 入队操作
bool dynamic_fifo_enqueue(dynamic_fifo_queue *queue, void *item)
{
    if (queue->size == queue->capacity) {
        if (!resize_dynamic_fifo_queue(queue)) {
            return false; // 扩展失败
        }
    }
    queue->data[queue->tail] = item;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;
    return true;
}

// 出队操作
void *dynamic_fifo_dequeue(dynamic_fifo_queue *queue)
{
    if (queue->size == 0) {
        return NULL; // 队列为空
    }
    void *item = queue->data[queue->head];
    queue->data[queue->head] = NULL;
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;
    return item;
}

// 检查队列是否为空
bool is_dynamic_fifo_queue_empty(const dynamic_fifo_queue *queue)
{
    return queue->size == 0;
}

// 获取队列当前大小
size_t dynamic_fifo_queue_size(const dynamic_fifo_queue *queue)
{
    return queue->size;
}

// 获取队列当前总容量
size_t dynamic_fifo_queue_capacity_size(const dynamic_fifo_queue *queue)
{
    return queue->capacity;
}

// 获取队列头部
void *dynamic_fifo_queue_first(dynamic_fifo_queue *queue)
{
    if (queue->size == 0) {
        return NULL; // 队列为空
    }
    void *item = queue->data[queue->head];
    return item;
}