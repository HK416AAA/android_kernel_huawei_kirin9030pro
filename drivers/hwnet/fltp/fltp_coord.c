/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "fltp_tool.h"
#include "fltp_stream.h"
#include "fltp_utils.h"
#include "fltp_coord.h"

static struct coordination_manager g_send_coordinationManager = {
    .coordination = NULL,
    .lock = __SPIN_LOCK_UNLOCKED(g_send_coordinationManager.lock)
};

// 处理wifi反馈回调
void fltp_coord_process_hmac_message(struct send_result_sx* send_result) {
    spin_lock_bh(&g_send_coordinationManager.lock);
    if (!send_result || !send_result->layer_list || g_send_coordinationManager.coordination == NULL) {
        spin_unlock_bh(&g_send_coordinationManager.lock);
        return;
    }
    uint16_t batch_id = send_result->layer_list->batch_id;
    bool send_flag = false;
    struct batch_node* out_curr = batch_find(g_send_coordinationManager.coordination->batch_list, batch_id);
    if (!out_curr || !out_curr->data) {
        htp_debug("out_curr is NULL");
        kfree(send_result->layer_list);
        spin_unlock_bh(&g_send_coordinationManager.lock);
        return;
    }
    size_t byte_index = 0;
    for (byte_index = 0; byte_index < (MAX_BATCH_SIZE / BITS_PER_BYTE); byte_index++) {
        uint8_t byte = send_result->tx_result[byte_index];
        size_t bit_index = 0;
        for (bit_index = 0; bit_index < BITS_PER_BYTE; bit_index++) {
            uint16_t packet_index = byte_index * BITS_PER_BYTE + bit_index;
            if (packet_index >= out_curr->data->packet_count)
                continue;

            uint16_t payload_sequence = out_curr->data->packets[packet_index].payload_sequence;
            // 要找stream
            uint8_t dstport = out_curr->data->packets[packet_index].dstport;
            uint8_t srcport = out_curr->data->packets[packet_index].srcport;
            struct fltp_stream_handle* stream = fltp_htp_get_stream_by_port(dstport, srcport);
            if (stream == NULL) {
                htp_err("fsk can not find dstport : %u srcport : %u", dstport, srcport);
                kfree(send_result->layer_list);
                spin_unlock_bh(&g_send_coordinationManager.lock);
                return;
            }
            if (((byte >> bit_index) & 0x01) == 0) {
                htp_debug("Bit %zu of tx_result[%zu] = %u\n", bit_index, byte_index, ((byte >> bit_index) & 0x01));
                bool ret = retransmit_packet(stream->nack_queue, payload_sequence) == FLTP_SUCCESS;
                send_flag = ret || send_flag;
            }
            g_send_coordinationManager.coordination->send_window_size++;
        }
    }
    batch_delete(g_send_coordinationManager.coordination->batch_list, batch_id);
    kfree(send_result->layer_list);
    spin_unlock_bh(&g_send_coordinationManager.lock);
    if (send_flag)
        fltp_coord_trigger_send();
}

// 创建连接
int32_t fltp_coord_create(void) {
    spin_lock(&g_send_coordinationManager.lock);
    if (g_send_coordinationManager.coordination == NULL) {
        struct fltp_coord_handle* coordination = kmalloc(sizeof(*coordination), GFP_ATOMIC);
        if (!coordination) {
            spin_unlock(&g_send_coordinationManager.lock);
            return FLTP_NO_MEMORY;
        }

        coordination->send_window_size = MAX_SEND_WINDOW_SIZE;
        coordination->batch_list = batch_list_create();
        if (!coordination->batch_list) {
            kfree(coordination);
            spin_unlock(&g_send_coordinationManager.lock);
            return FLTP_NO_MEMORY;
        }
        skb_queue_head_init(&coordination->send_queue);

        g_send_coordinationManager.coordination = coordination;
    }
    spin_unlock(&g_send_coordinationManager.lock);

    return FLTP_SUCCESS;
}

// 删除连接
int32_t fltp_coord_delete(void) {
    spin_lock(&g_send_coordinationManager.lock);
    if (g_send_coordinationManager.coordination == NULL) {
        spin_unlock(&g_send_coordinationManager.lock);
        return FLTP_SUCCESS;
    }
    batch_list_destroy(&g_send_coordinationManager.coordination->batch_list);
    skb_queue_purge(&g_send_coordinationManager.coordination->send_queue);
    kfree(g_send_coordinationManager.coordination);
    g_send_coordinationManager.coordination = NULL;
    spin_unlock(&g_send_coordinationManager.lock);

    return FLTP_SUCCESS;
}

void fltp_coord_add_packet(struct sk_buff *skb) {
    spin_lock(&g_send_coordinationManager.lock);
    if (skb == NULL || g_send_coordinationManager.coordination == NULL) {
        spin_unlock(&g_send_coordinationManager.lock);
        return;
    }

    skb_queue_tail(&g_send_coordinationManager.coordination->send_queue, skb);
    spin_unlock(&g_send_coordinationManager.lock);
}

void fltp_coord_add_packet_first(struct sk_buff *skb) {
    spin_lock(&g_send_coordinationManager.lock);
    if (skb == NULL || g_send_coordinationManager.coordination == NULL) {
        spin_unlock(&g_send_coordinationManager.lock);
        return;
    }

    skb_queue_head(&g_send_coordinationManager.coordination->send_queue, skb);
    spin_unlock(&g_send_coordinationManager.lock); 
}

static void fltp_send_control(struct sk_buff **list, struct batch_info *batch) {
    struct sk_buff *curr = NULL;
    struct sk_buff *buffer = NULL;
    while (g_send_coordinationManager.coordination->send_window_size > 0) {
        struct sk_buff *dequeued_skb = skb_dequeue(&g_send_coordinationManager.coordination->send_queue);
        if (dequeued_skb != NULL && batch->packet_count < MAX_BATCH_SIZE) {
        // 分配SKB基础内存
            struct sk_buff *skb = skb_copy(dequeued_skb, GFP_ATOMIC);
            if (!skb) {
                // 如果分配失败，释放之前分配的skb
                while (buffer) {
                    struct sk_buff *next_skb = buffer->next;
                    skb_queue_head(&g_send_coordinationManager.coordination->send_queue, buffer);
                    buffer = next_skb;
                    g_send_coordinationManager.coordination->send_window_size++;
                }
                htp_err("skb_copy fail");
                kfree(batch);
                batch = NULL;
                skb_queue_head(&g_send_coordinationManager.coordination->send_queue, dequeued_skb);
                return;
            }

            // 将skb添加到链表中
            if (!buffer) {
                buffer = skb;
                curr = skb;
                skb->prev = NULL;
                skb->next = NULL;
            } else {
                curr->next = skb;
                skb->prev = curr;
                skb->next = NULL;
                curr = skb;
            }
            struct htphdr *htph = htp_hdr(skb);  // 获取HTP头部
            
            batch->packets[batch->packet_count].dstport = htph->dst;
            batch->packets[batch->packet_count].srcport = htph->src;
            batch->packets[batch->packet_count].payload_sequence = ntohl(htph->seq);
            batch->packet_count++;
            g_send_coordinationManager.coordination->send_window_size--;

            kfree_skb(dequeued_skb);  // 手动释放所有权
        } else {
            break;
        }
    }
    *list = buffer;
}

void fltp_coord_trigger_send(void) {
    spin_lock_bh(&g_send_coordinationManager.lock);
    if (g_send_coordinationManager.coordination == NULL) {
        spin_unlock_bh(&g_send_coordinationManager.lock);
        htp_err("g_send_coordinationManager.coordination is null");
        return;
    }
    struct sk_buff *list = NULL;
    struct batch_info *batch = kmalloc(sizeof(*batch), GFP_ATOMIC);
    if (!batch) {
        spin_unlock_bh(&g_send_coordinationManager.lock);
        htp_err("batch kmalloc failed");
        return;
    }
    batch->packet_count = 0;
    fltp_send_control(&list, batch);
    if (list) {
        g_send_coordinationManager.coordination->batch_id++;
        batch->batch_id = g_send_coordinationManager.coordination->batch_id;
        batch_insert(g_send_coordinationManager.coordination->batch_list, batch);
        int ret = fltp_trans_send_data_to_wifi(list, batch->batch_id);
        if ((ret != FLTP_SUCCESS) && (fltp_trans_send_data_to_wifi(list, batch->batch_id) != FLTP_SUCCESS)) {
            batch_delete(g_send_coordinationManager.coordination->batch_list, batch->batch_id);
            while (list) {
                struct sk_buff *next_skb = list->next;
                kfree_skb(list);  // 头部插入，不自动增加引用计数
                list = next_skb;
                g_send_coordinationManager.coordination->send_window_size++;
            }
        }
    }
    spin_unlock_bh(&g_send_coordinationManager.lock);
}

int fltp_coord_recv_packet(struct sock* sk, struct sk_buff *skb) {
    if (!skb || !sk) { 
        return FLTP_INVAL_PARAM; 
    }
    struct sk_buff *cur_skb = skb;
    struct fltp_htp_skb_cb dcb = fltp_htp_skb_cb(skb);
    struct fltp_stream_handle* stream_handle = fltp_get_stream_by_sock(sk);
    if (!dcb.sacked) {
        return fltp_stream_recv_skb_data(sk, stream_handle, cur_skb);
    } else {
        return fltp_stream_process_sack(sk, stream_handle, cur_skb);
    }
}