/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "fltp_tool.h"
#include "fltp_recvbuffer.h"
#include "fltp_stream.h"
#include "fltp_utils.h"

struct sack_state* sack_state_init(void) {
    struct sack_state* state = kmalloc(sizeof(struct sack_state), GFP_KERNEL);
    if (!state) {
        return NULL;
    }

    state->blocks = kvmalloc_array(MAX_ACK_LEN, sizeof(struct ack_range), GFP_KERNEL);
    size_t block_size = MAX_ACK_LEN * sizeof(struct ack_range);
    (void)memset_s(state->blocks, block_size, 0, block_size);
    if (!state->blocks) {
        kfree(state);
        return NULL;
    }

    state->capacity = MAX_ACK_LEN;
    state->block_count = 0;
    state->sack_seq = 0;
    state->last_time = 0;
    return state;
}

void sack_state_destroy(struct sack_state* state) {
    if (state) {
        if (state->blocks) {
            kvfree(state->blocks);
            state->blocks = NULL;
        }
        kfree(state);
        state = NULL;
    }
}

void try_send_sack(struct sock* sk) {
    struct fltp_stream_handle* stream_handle = fltp_get_stream_by_sock(sk);
    if (!stream_handle)
        return;

    // 获取 SACK 状态并检查
    struct sack_state* state = stream_handle->state;
    if (!state)
        return;
    struct sk_buff* skb = fltp_hsk_walloc_skb(sk, 0, sk->sk_allocation);

    if (!skb)
        return;

    uint16_t range_nums = state->block_count > MAX_SEND_ACK_BLOCKS ? MAX_SEND_ACK_BLOCKS : state->block_count;
    // 将dcb里边的sacked 长度填上
    struct fltp_htp_sock fsk;
    struct fltp_htp_skb_cb dcb;
    dcb.sacked = range_nums * sizeof(struct ack_range);
    fsk.sack.block_count = 0;
    // hsk 里面的信息填好
    uint16_t i;
    for (i = 0; i < range_nums; ++i) {
        fsk.sack.blocks[i].start = state->blocks[i].start;
        fsk.sack.blocks[i].end = state->blocks[i].end;
        fsk.sack.block_count++;
    }
    dcb.ack_seq = state->sack_seq;
    fltp_set_sack(fsk, dcb, skb, sk);
    fltp_htp_set_htph_for_transmit(skb, sk);
    fltp_htp_set_mach_for_transmit(skb, sk);
    fltp_stream_input_data(sk, skb);
}

static int merge_with_existing_blocks(struct sack_state *state, struct ack_range new_block) {
    int merged = 0;
    for (int i = state->block_count - 1; i >= 0; --i) {
        if (new_block.start == state->blocks[i].end + 1) {
            state->blocks[i].end = new_block.end;
            merged = 1;
            break;
        }
        if (new_block.end + 1 == state->blocks[i].start) {
            state->blocks[i].start = new_block.start;
            merged = 1;
            break;
        }
        uint32_t start = state->blocks[i].start, end = state->blocks[i].end;
        if (is_seq_greater_or_equal(new_block.start, start) && is_seq_less_or_equal(new_block.start, end)) {
            merged = 1;
            break;
        }
    }
    return merged;
}

static void merge_adjacent_blocks(struct sack_state *state) {
    for (int i = 0; i < state->block_count - 1;) {
        struct ack_range *curr = &state->blocks[i];
        struct ack_range *next = &state->blocks[i + 1];
        if (is_seq_less_or_equal(next->start, curr->end + 1)) {
            next->start = curr->start;
            size_t len = (state->block_count - i - 1) * sizeof(struct ack_range);
            if (memmove_s(curr, len, next, len) != 0) {
                htp_err("memmove_s error \n");
            }
            state->block_count--;
        } else {
            i++;
        }
    }
}

void recv_update_sack(struct sack_state* state, uint32_t pkt_num) {
    if (!state) {
        return;
    }
    struct ack_range new_block = {pkt_num, pkt_num};
    int merged = merge_with_existing_blocks(state, new_block);
    size_t length = sizeof(struct ack_range);
    if (!merged) {  // 如果有新增的block，执行处理
        if (state->block_count >= MAX_ACK_LEN) {
            htp_err("state->block_count exceed : %d, too much loss \n", MAX_ACK_LEN);
        } else {
            int insert_pos = 0;
            while (is_seq_less(insert_pos, state->block_count) &&
                is_seq_greater(new_block.start, state->blocks[insert_pos].start)) {
                insert_pos++;
            }
            if (memmove_s(&state->blocks[insert_pos + 1], (state->block_count - insert_pos) * length,
                        &state->blocks[insert_pos], (state->block_count - insert_pos) * length) != EOK) {
                htp_err("memmove_s error,  insert_pos:%d, block_count:%d\n", insert_pos, state->block_count);
            }
            state->blocks[insert_pos].start = new_block.start;
            state->blocks[insert_pos].end = new_block.end;
            state->block_count++;
        }
    }
    merge_adjacent_blocks(state);
}

struct receive_queue* receive_queue_init(void) {
    struct receive_queue* queue = kmalloc(sizeof(struct receive_queue), GFP_KERNEL);
    if (!queue) {
        return NULL;
    }
    size_t len = sizeof(struct receive_queue_entry);
    queue->entries = kvmalloc_array(DEFAULT_QUEUE_CAPACITY, len, GFP_KERNEL);
    if (!queue->entries) {
        kfree(queue);
        return NULL;
    }
    (void)memset_s(queue->entries, DEFAULT_QUEUE_CAPACITY * len, 0, DEFAULT_QUEUE_CAPACITY * len);
    queue->capacity = DEFAULT_QUEUE_CAPACITY;
    queue->out_skb_id = 0;
    queue->isfirst = true;
    spin_lock_init(&queue->lock);
    queue->total_nums = 0;
    htp_info("receive_queue_init success queue address: %x\n", queue);
    return queue;
}

void receive_queue_destroy(struct receive_queue* queue) {
    if (!queue) {
        return;
    }
    htp_info("receive_queue_destroy enter queue address: %x\n", queue);
    spin_lock(&queue->lock);
    if (!queue->entries) {
        spin_unlock(&queue->lock);
        kfree(queue);
        queue = NULL;
        return;
    }
    
    size_t i = 0;
    for (i = 0; i < queue->capacity; i++) {
        if (queue->entries[i].skb) {
            kfree_skb(queue->entries[i].skb);
            queue->entries[i].skb = NULL;
        }
    }
    kvfree(queue->entries);
    queue->entries = NULL;
    spin_unlock(&queue->lock);
    kfree(queue);
    queue = NULL;
    htp_info("receive_queue_destroy success\n");
}

int receive_queue_insert_skb(struct receive_queue* queue, struct sk_buff* skb, uint32_t seq) {
    if (!queue || !skb) {
        return FLTP_INVAL_PARAM;
    }

    if (is_seq_less(seq, queue->out_skb_id)) {
        kfree_skb(skb);
        htp_err("old seq : %u\n", seq);
        return FLTP_INVAL_SEQ;
    }

    spin_lock(&queue->lock);

    size_t index = seq % queue->capacity;
    if (!queue->entries[index].skb) {
        skb_get(skb);
        queue->entries[index].skb = skb;
        queue->entries[index].seq = seq;
        htp_debug("queue->entries[index].seq : %u skb len : %u\n", queue->entries[index].seq, skb->len);
        spin_unlock(&queue->lock);
        return FLTP_SUCCESS;
    } else if (queue->entries[index].seq == seq) {
        spin_unlock(&queue->lock);
        kfree_skb(skb);
        htp_err("repeat seq : %u\n", seq);
        return FLTP_INVAL_SEQ;
    } else {
        spin_unlock(&queue->lock);
        kfree_skb(skb);
        htp_err("receieve queue is full, drop seq: %u\n", seq);
        return FLTP_NO_SPACE;
    }
    spin_unlock(&queue->lock);
    return FLTP_SUCCESS;
}

void output_packet(struct sock* sk, struct receive_queue* queue, uint32_t seq) {
    if (!queue || !sk) {
        return;
    }
    spin_lock(&queue->lock);
    while (true) {
        uint32_t current_skb_id = queue->out_skb_id;
        
        size_t index = current_skb_id % queue->capacity;

        if (queue->entries && queue->entries[index].seq == current_skb_id && queue->entries[index].skb) {
            htp_info("output_packet seq : %u skb len : %u\n",
                queue->entries[index].seq, queue->entries[index].skb->len);
            skb_queue_tail(&sk->sk_receive_queue, queue->entries[index].skb);
            kfree_skb(queue->entries[index].skb);
            queue->entries[index].skb = NULL;
            queue->out_skb_id = ++current_skb_id;
        } else {
            break;
        }
        if (!sock_flag(sk, SOCK_DEAD))
		    sk->sk_data_ready(sk);
    }
    spin_unlock(&queue->lock);
}

int recv_skb_data(struct sock* sk, struct sk_buff* skb, struct sack_state* state, struct receive_queue* queue)
{
    if (!sk || !skb || !state || !queue)
        return FLTP_INVAL_PARAM;
    struct fltp_htp_sock fsk = fltp_htp_sk(sk);
    struct fltp_htp_skb_cb dcb = fltp_htp_skb_cb(skb);

    struct timespec64 ts;
    ktime_get_real_ts64(&ts);
    if (state->last_time == 0) {
        state->last_time = ts.tv_sec * S_TO_MS + ts.tv_nsec / NS_TO_MS;
    } else if ((ts.tv_sec * S_TO_MS + ts.tv_nsec / NS_TO_MS) - state->last_time > ACK_SEND_TIME) {
        // send packet
        try_send_sack(sk);
        state->last_time = ts.tv_sec * S_TO_MS + ts.tv_nsec / NS_TO_MS;
    }

    if (queue->isfirst) {
        queue->out_skb_id = fsk.copied_seq;
        queue->isfirst = false;
        htp_info( "out_skb_id->seq : %u\n", queue->out_skb_id);
    }

    int ret = receive_queue_insert_skb(queue, skb, dcb.seq);
    if (ret != FLTP_SUCCESS) {
        return ret;
    }
    recv_update_sack(state, dcb.seq);
    htp_info("recv_skb_data seq : %u\n", dcb.seq);
    output_packet(sk, queue, dcb.seq);
    return FLTP_SUCCESS;
}