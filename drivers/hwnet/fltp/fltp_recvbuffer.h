/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef FLTP_RECVBUFFER_H
#define FLTP_RECVBUFFER_H

#include <net/inet_sock.h>

#define DEFAULT_QUEUE_CAPACITY 2048  // 接收队列大小
#define MAX_QUEUE_CAPACITY 4096  // 接收队列最大大小
#define MERGE_THRESHOLD 1            // 合并敏感度阈值
#define MAX_SEND_ACK_BLOCKS 4
#define MAX_ACK_LEN 500
#define ACK_SEND_TIME 20

struct ack_range {
    uint32_t start;
    uint32_t end;
};

struct sack_state {
    uint16_t sack_seq;       // SACK帧序号（2字节）
    uint16_t block_count;        // 当前块数量 （2字节）
    struct ack_range *blocks;  // 块数组 （8字节/块）
    size_t capacity;              // 块数组容量
    uint64_t last_time;             // 上次发送时间
};

struct receive_queue_entry {
    struct sk_buff *skb;
    uint32_t seq;          // 数据包指针
};

struct receive_queue {
    struct receive_queue_entry* entries;        // 一维数组
    size_t capacity;              // 数组容量
    spinlock_t lock;              // 自旋锁
    size_t total_nums;            // 当前队列中包的数量
    bool isfirst;                 // 是否是第一个数据包
    uint32_t out_skb_id;        // 上一帧已出包的包序号
};

struct sack_state* sack_state_init(void);
void sack_state_destroy(struct sack_state* state);
void recv_update_sack(struct sack_state* state, uint32_t pkt_num);

struct receive_queue* receive_queue_init(void);
void receive_queue_destroy(struct receive_queue* queue);

int receive_queue_insert_skb(struct receive_queue* queue, struct sk_buff* skb, uint32_t seq);

void output_packet(struct sock* sk, struct receive_queue* queue, uint32_t seq);

int recv_skb_data(struct sock* sk, struct sk_buff* skb, struct sack_state* state, struct receive_queue* queue);

void try_send_sack(struct sock* sk);

#endif // RECV_BUFFER_H