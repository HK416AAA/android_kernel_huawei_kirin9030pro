/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Implementation Queue
 * Author: dpa drivers
 */

#ifndef OAM_QUEUE_H
#define OAM_QUEUE_H

#include "oal_types.h"

typedef struct {
    uint8_t           element_cnt;    /* 本队列中已经存放的元素个数 */
    uint8_t           max_elements;   /* 本队列中所能存放的最大元素个数 */
    uint8_t           tail_index;     /* 指向下一个元素入队位置的索引 */
    uint8_t           head_index;     /* 指向当前元素出队位置的索引 */
    oal_uint          *buf;           /* 队列缓存 */
}oam_queue_stru;

/*
 * 函 数 名  : oam_queue_init
 * 功能描述  : 设置队列参数
 *  输入参数  : queue      : 队列指针
 *             buf        : 指向队列缓冲区的指针
 *             max_elements: 最大元素个数
 */
static inline int32_t oam_queue_init(oam_queue_stru *queue, oal_uint *buf, uint8_t max_elements)
{
    if (queue == NULL || buf == NULL) {
        return OAL_FAIL;
    }

    queue->buf          = buf;
    queue->tail_index   = 0;
    queue->head_index   = 0;
    queue->element_cnt  = 0;
    queue->max_elements = max_elements;

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_queue_destroy
 * 功能描述  : 队列销毁
 *  输入参数  : queue      : 队列指针
 *             buf        : 指向队列缓冲区的指针
 *             max_elements: 最大元素个数
 */
static inline void oam_queue_destroy(oam_queue_stru *queue)
{
    if (queue == NULL) {
        return;
    }

    memset_s(queue, sizeof(oam_queue_stru), 0, sizeof(oam_queue_stru));
}

static inline int32_t oam_queue_enqueue(oam_queue_stru *queue, const void *element)
{
    if (!queue || !element || queue->element_cnt >= queue->max_elements) {
        return OAL_FAIL;
    }

    uint8_t tail_index = queue->tail_index;
    queue->buf[tail_index] = (oal_uint)(uintptr_t)element;
    queue->tail_index = (tail_index + 1) % queue->max_elements;
    queue->element_cnt++;
    return OAL_SUCC;
}

static inline void *oam_queue_dequeue(oam_queue_stru *queue)
{
    if (!queue || queue->element_cnt == 0) {
        return NULL;
    }
    
    uint8_t head_index = queue->head_index;
    void *element = (void *)(uintptr_t)queue->buf[head_index];
    queue->head_index = (head_index + 1) % queue->max_elements;
    queue->element_cnt--;
    return element;
}

#endif /* end of oal_queue.h */
