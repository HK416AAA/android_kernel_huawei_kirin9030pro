/*
 * Copyright (c) @CompanyNameMagicTag 2021-2025. All rights reserved.
 * 功能说明   : hmac_vsp.c 的头文件
 * 作者       :
 */

#ifndef HMAC_VSP_SX_H
#define HMAC_VSP_SX_H

#include "hmac_vsp.h"
#include "oal_dma_buf.h"

#ifdef _PRE_WLAN_FEATURE_VSP

typedef struct {
    oal_dlist_head_stru entry;
    tx_layer_ctrl *head; /* layer链表头 */
    send_result_sx tx_result;
    uint8_t pkt_num;
    uint32_t arrive_ts;
} hmac_vsp_tx_sx_batch_stru;

static inline void hmac_vsp_batch_enqueue_unlock(hmac_vsp_slice_queue_stru *queue, hmac_vsp_tx_sx_batch_stru *batch)
{
    oal_dlist_add_tail(&batch->entry, &queue->head);
}

static inline void hmac_vsp_batch_enqueue(hmac_vsp_slice_queue_stru *queue, hmac_vsp_tx_sx_batch_stru *batch)
{
    oal_spin_lock(&queue->lock);
    hmac_vsp_batch_enqueue_unlock(queue, batch);
    oal_spin_unlock(&queue->lock);
}

static inline hmac_vsp_tx_sx_batch_stru *hmac_vsp_batch_dequeue_unlock(hmac_vsp_slice_queue_stru *queue)
{
    return oal_container_of(oal_dlist_delete_head(&queue->head), hmac_vsp_tx_sx_batch_stru, entry);
}

static inline hmac_vsp_tx_sx_batch_stru *hmac_vsp_batch_dequeue(hmac_vsp_slice_queue_stru *queue)
{
    hmac_vsp_tx_sx_batch_stru *batch = NULL;

    oal_spin_lock(&queue->lock);
    batch = hmac_vsp_batch_dequeue_unlock(queue);
    oal_spin_unlock(&queue->lock);

    return batch;
}

static inline hmac_vsp_tx_sx_batch_stru *hmac_vsp_batch_queue_peek(hmac_vsp_slice_queue_stru *queue)
{
    return oal_container_of(queue->head.pst_next, hmac_vsp_tx_sx_batch_stru, entry);
}

uint32_t hmac_vsp_sx_cfg(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, vsp_param *param);
void hmac_vsp_sx_tx_complete_handler(hmac_vsp_source_stru *source);
void hmac_vsp_new_batch_handler(hmac_vsp_source_stru *source);
uint32_t hmac_vsp_sx_batch_init(hmac_vsp_source_stru *source, tx_layer_ctrl *layer);
void hmac_vsp_sx_stop(void);

#endif /* end of _PRE_WLAN_FEATURE_VSP */
#endif