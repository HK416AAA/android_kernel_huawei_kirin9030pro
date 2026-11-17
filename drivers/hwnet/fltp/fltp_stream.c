/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "fltp_tool.h"
#include "fltp_stream.h"
#include "fltp_coord.h"
#include "fltp_utils.h"

struct fltp_stream_handle* fltp_stream_create(const struct fltp_stream_attr_params* attr_params) {
    struct fltp_stream_handle* streamHandle = kmalloc(sizeof(struct fltp_stream_handle), GFP_KERNEL);
    if (!streamHandle) {
        htp_err("Failed to allocate memory for streamHandle.\n");
        return NULL;
    }

    streamHandle->nack_queue = retransmission_queue_init();
    if (!streamHandle->nack_queue) {
        htp_err("Failed to initialize retransmission queue.\n");
        kfree(streamHandle);
        return NULL;
    }
    streamHandle->recv_buffer = receive_queue_init();
    if (!streamHandle->recv_buffer) {
        htp_err("Failed to initialize receive buffer.\n");
        retransmission_queue_destroy(streamHandle->nack_queue);
        kfree(streamHandle);
        return NULL;
    }
    streamHandle->state = sack_state_init();
    if (!streamHandle->state) {
        htp_err("Failed to initialize sack state.\n");
        retransmission_queue_destroy(streamHandle->nack_queue);
        receive_queue_destroy(streamHandle->recv_buffer);
        kfree(streamHandle);
        return NULL;
    }
#ifndef LOOPBACK_DEV
    fltp_trans_setvsp_callback();
#endif
    return streamHandle;
}

int fltp_stream_destroy(struct fltp_stream_handle* streamHandle) {
    if (!streamHandle) {
        htp_info( "Stream handle is NULL.\n");
        return FLTP_SUCCESS;
    }

    retransmission_queue_destroy(streamHandle->nack_queue);
    receive_queue_destroy(streamHandle->recv_buffer);
    sack_state_destroy(streamHandle->state);

    kfree(streamHandle);
    return FLTP_SUCCESS;
}

static void fltp_retransmit_timeout_callback(struct timer_list * data)
{
    struct sock *sk = (struct sock *)container_of((struct timer_list *)data, struct htp_sock, rtx_timer.timer); // 遗留
    bh_lock_sock(sk);
    struct fltp_stream_handle* stream_handle = fltp_get_stream_by_sock(sk);
    if (!stream_handle) {
        bh_unlock_sock(sk);
        return;
    }
    struct fltp_htp_sock fsk = fltp_htp_sk(sk);
    if (stream_handle->nack_queue) {
        if (stream_handle->nack_queue->total_length != 0 && !stream_handle->nack_queue->isfirst) {
            htp_info("retransmit_timeout_callback retransmit_packet %u \n", stream_handle->nack_queue->expected_sn);
            retransmit_packet(stream_handle->nack_queue, stream_handle->nack_queue->expected_sn);
            fltp_coord_trigger_send();
            uint64_t delay = msecs_to_jiffies(500);
            sk_reset_timer(sk, fsk.rt_timer, jiffies + delay);
        }
    }
	bh_unlock_sock(sk);
	sock_put(sk);
}

void fltp_init_send_timer(struct sock *sk)
{
    struct fltp_htp_sock fsk = fltp_htp_sk(sk);
    fltp_htp_setup_timer(fsk.rt_timer, fltp_retransmit_timeout_callback);
}

void fltp_destroy_send_timer(struct sock *sk)
{
    struct fltp_htp_sock fsk = fltp_htp_sk(sk);
    sk_stop_timer(sk, fsk.rt_timer);
}

const struct timer_handler_ops htp_retrans_timer_ops = {
	.init		= fltp_init_send_timer,
	.destroy	= fltp_destroy_send_timer,
};

int32_t fltp_stream_input_data(struct sock* sk, struct sk_buff *skb) {
    struct fltp_stream_handle* streamHandle = fltp_get_stream_by_sock(sk);
    if (!sk || !streamHandle || !skb || skb->len <= 0 || skb->len > FLTP_MTU){
        return FLTP_INVAL_PARAM;
    }
    struct fltp_htp_sock fsk = fltp_htp_sk(sk);
    struct fltphdr fdr = fltp_htp_hdr(skb);  // 获取HTP头部
    struct fltp_htp_skb_cb dcb = fltp_htp_skb_cb(skb);
    bool flag = (streamHandle->nack_queue->isfirst) && (fdr.packtype == FLTP_HTPHDR_TYPE_DEFAULT);
    if (flag && !dcb.sacked && !(dcb.flags & FLTP_HTPHDR_PROBE)) {
        fltp_htp_init_timer(sk, FLTP_HTP_RETRANS_TIMER);
        // expected_sn is the sequence number that the sender expects to receive next
        streamHandle->nack_queue->expected_sn = fsk.send_seq;
        htp_info("fsk.send_seq : %u\n", fsk.send_seq);
        streamHandle->nack_queue->isfirst = false;
    }
 
    htp_info("skb seq : %u sack : %u\n", fdr.seq, dcb.sacked);
    if (!dcb.sacked && !(dcb.flags & FLTP_HTPHDR_PROBE) && fdr.packtype == FLTP_HTPHDR_TYPE_DEFAULT) {
        int iRet = retransmission_queue_insert(streamHandle->nack_queue, skb, fdr.seq);
        if (iRet != 0) {
            htp_err("queue_insert failed retransmit_packet %u \n", streamHandle->nack_queue->expected_sn);
            retransmit_packet(streamHandle->nack_queue, streamHandle->nack_queue->expected_sn);
            fltp_coord_trigger_send();
            return iRet;
        }
    }
    if (fdr.packtype == FLTP_HTPHDR_TYPE_DEFAULT && !dcb.sacked && !(dcb.flags & FLTP_HTPHDR_PROBE)) {
        uint64_t delay = msecs_to_jiffies(500);
        sk_reset_timer(sk, fsk.rt_timer, jiffies + delay);
    }

    fltp_coord_add_packet(skb);
    fltp_coord_trigger_send();

    return FLTP_SUCCESS;
}

int32_t fltp_stream_recv_skb_data(struct sock* sk, struct fltp_stream_handle* stream_handle, struct sk_buff *skb) {
    if (!stream_handle) {
        return FLTP_INVAL_PARAM;
    }
    return recv_skb_data(sk, skb, stream_handle->state, stream_handle->recv_buffer);
}

int32_t fltp_stream_process_sack(struct sock* sk, struct fltp_stream_handle* stream_handle, struct sk_buff* skb) {
    if (!stream_handle || !skb)
        return FLTP_INVAL_PARAM;
    // 获取range信息
    struct fltp_htp_sock fsk = fltp_htp_sk(sk);
    
    uint32_t clean_sn = stream_handle->nack_queue->expected_sn;
    uint32_t first_sn = stream_handle->nack_queue->expected_sn;
 
    int range_count = fsk.sack.block_count > MAX_SEND_ACK_BLOCKS ? MAX_SEND_ACK_BLOCKS : fsk.sack.block_count;
    // 遍历block信息并处理
    uint32_t i = 0;
    for (i = 0; i < range_count; ++i) {
        uint32_t start = fsk.sack.blocks[i].start;
        uint32_t end = fsk.sack.blocks[i].end;
        htp_info("expected_sn %u start %u end %u \n", stream_handle->nack_queue->expected_sn, start, end);
        if (is_seq_greater(start, first_sn)) {
            uint32_t seq = first_sn;
            for (seq = first_sn; is_seq_less(seq, start); ++seq) {
                retransmit_packet(stream_handle->nack_queue, seq);
                fltp_coord_trigger_send();
            }
        }
        first_sn = end + 1;
        if (is_seq_less_or_equal(start, stream_handle->nack_queue->expected_sn) &&
            is_seq_greater_or_equal(end, stream_handle->nack_queue->expected_sn)) {
            clean_sn = end + 1;
        }
    }
 
    uint32_t seq = stream_handle->nack_queue->expected_sn;
    for (seq = stream_handle->nack_queue->expected_sn; is_seq_less(seq, clean_sn); ++seq) {
        int iRet = retransmission_queue_clean_up(stream_handle->nack_queue, seq);
        if (iRet != 0) {
            clean_sn = seq;
            break;
        }
    } 
    stream_handle->nack_queue->expected_sn = clean_sn;
    return FLTP_SUCCESS;
}

int32_t fltp_stream_get_nackqueue_flag(struct sock* sk, bool *flag)
{
    struct fltp_stream_handle* stream_handle = fltp_get_stream_by_sock(sk);
    if (!flag || !stream_handle || !stream_handle->nack_queue) {
        return FLTP_INVAL_PARAM;
    }
    *flag = stream_handle->nack_queue->throttle_enabled;
    return FLTP_SUCCESS;
}