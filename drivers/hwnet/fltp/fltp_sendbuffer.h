/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef FLTP_SENDBUFFER_H
#define FLTP_SENDBUFFER_H

#include <net/inet_sock.h>
#define BATCH_SIZE (64)

#define RETRANSMIT_QUEUE_SIZE 4096
#define RETRY_ONE_TIME 20
#define RETRY_MORE_TIME 40

struct batch_info {
    uint32_t batch_id;
    size_t packet_count; // 批次中的数据包数量
    struct {
        uint8_t dstport;
        uint8_t srcport;
        uint16_t payload_sequence;
    } packets[BATCH_SIZE];
};
struct batch_node {
    struct batch_info *data;
    struct batch_node *next;
};

struct batch_list {
    struct batch_node *head;
    spinlock_t lock;
};

struct batch_list *batch_list_create(void);
void batch_list_destroy(struct batch_list **list);
int batch_insert(struct batch_list *list, struct batch_info *batch);
struct batch_node * batch_find(struct batch_list *list, uint32_t target_id);
void batch_delete(struct batch_list *list, uint32_t target_id);

struct retransmission_entry {
    struct sk_buff *skb;
    uint32_t seq;
    uint64_t last_transmit_time;
    uint8_t retransmit_count;
};

struct retransmission_queue {
    struct retransmission_entry **entries;
    uint32_t expected_sn;      // 期望的包序号
    bool isfirst;  // 是否是第一个包
    uint32_t max_sn;
    size_t total_length;
    bool throttle_enabled;
    spinlock_t lock;
};

struct retransmission_queue *retransmission_queue_init(void);
int retransmission_queue_insert(struct retransmission_queue *queue, struct sk_buff *skb, uint32_t seq);
void retransmission_queue_destroy(struct retransmission_queue *queue);
struct retransmission_entry *retransmission_queue_find(struct retransmission_queue *queue, uint32_t seq);
int retransmission_queue_clean_up(struct retransmission_queue *queue, uint32_t seq);
int retransmit_packet(struct retransmission_queue *queue, uint32_t seq);

#endif // SEND_BUFFER_H