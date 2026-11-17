/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "fltp_tool.h"
#include "fltp_sendbuffer.h"
#include "fltp_def.h"
#include "fltp_coord.h"
#include "fltp_utils.h"

// 初始化链表
struct batch_list *batch_list_create(void) {
    struct batch_list *list = kmalloc(sizeof(*list), GFP_ATOMIC);
    if (!list)
        return NULL;

    spin_lock_init(&list->lock);
    list->head = NULL;
    htp_info("batch_list_create success list address: %x\n", list);
    return list;
}

// 销毁链表（自动释放内存）
void batch_list_destroy(struct batch_list **list) {
    if (!list || !*list)
        return;
    htp_info("batch_list_destroy enter list address: %x\n", list);
    struct batch_list *l = *list;
    spin_lock(&l->lock);
    struct batch_node *currnode = l->head;
    while (currnode) {
        struct batch_node *temp = currnode;
        currnode = currnode->next;
        kfree(temp->data); // 释放batch_info结构体
        kfree(temp);
    }
    spin_unlock(&l->lock);
    kfree(l);
    *list = NULL;
}

// 插入节点（头插法）
int batch_insert(struct batch_list *list, struct batch_info *batch) {
    if (!list || !batch)
        return FLTP_INVAL_PARAM;

    struct batch_node *new_node = kmalloc(sizeof(*new_node), GFP_ATOMIC);
    if (!new_node)
        return FLTP_NO_MEMORY;

    new_node->data = batch;
    new_node->next = NULL;

    spin_lock(&list->lock);
    new_node->next = list->head;
    list->head = new_node;
    spin_unlock(&list->lock);

    return FLTP_SUCCESS;
}


struct batch_node *batch_find(struct batch_list *list, uint32_t target_id) {
    if (!list)
        return NULL;

    spin_lock(&list->lock);
    struct batch_node *curr = list->head;
    while (curr) {
        if (curr->data->batch_id == target_id) {
            break;
        }
        curr = curr->next;
    }
    spin_unlock(&list->lock);
    return curr;
}

// 使用预查找到的节点进行删除
void batch_delete(struct batch_list *list, uint32_t target_id) {
    if (!list)
        return;

    spin_lock(&list->lock);
    struct batch_node *curr = list->head;
    struct batch_node *prev = NULL;

    // 遍历链表，找到目标节点
    while (curr) {
        if (curr->data->batch_id == target_id) {
            // 如果是头节点
            if (curr == list->head) {
                list->head = curr->next;
            } else {
                prev->next = curr->next;
            }
            // 释放内存
            kfree(curr->data);
            kfree(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    spin_unlock(&list->lock);
}


// 重传队列初始化
struct retransmission_queue *retransmission_queue_init(void) {
    struct retransmission_queue *queue = kmalloc(sizeof(*queue), GFP_KERNEL);
    if (!queue)
        return NULL;
    size_t length = sizeof(struct retransmission_entry *);
    queue->entries = kvmalloc_array(RETRANSMIT_QUEUE_SIZE, length, GFP_KERNEL);
    if (!queue->entries) {
        kfree(queue);
        return NULL;
    }
    (void)memset_s(queue->entries, RETRANSMIT_QUEUE_SIZE * length, 0, RETRANSMIT_QUEUE_SIZE * length);
    spin_lock_init(&queue->lock);
    queue->total_length = 0;
    queue->expected_sn = 1;
    queue->throttle_enabled = false;
    queue->isfirst = true; // 初始设置为true，表示需要获取expected_sn
    htp_info("retransmission_queue_init success queue address: %x\n", queue);
    return queue;
}

// 删除重传队列
void retransmission_queue_destroy(struct retransmission_queue *queue) {
    if (!queue)
        return;
    htp_info("retransmission_queue_destroy enter queue address: %x\n", queue);
    spin_lock(&queue->lock);
    if (!queue->entries) {
        spin_unlock(&queue->lock);
        kfree(queue);
        queue = NULL;
        return;
    }
    size_t i = 0;
    for (i = 0; i < RETRANSMIT_QUEUE_SIZE; i++) {
        if (queue->entries[i]) {
            if (queue->entries[i]->skb) {
                kfree_skb(queue->entries[i]->skb);
            }
            kfree(queue->entries[i]);
            queue->entries[i] = NULL;
        }
    }
    kvfree(queue->entries);
    queue->entries = NULL;
    spin_unlock(&queue->lock);
    kfree(queue);
    queue = NULL;
    htp_info("retransmission_queue_destroy success\n");
}

// 重传队列插入数据包
int retransmission_queue_insert(struct retransmission_queue *queue, struct sk_buff *skb, uint32_t seq) {
    if (!queue || !skb)
        return FLTP_INVAL_PARAM;

    spin_lock(&queue->lock);
    size_t index = seq % RETRANSMIT_QUEUE_SIZE;
    size_t start_index = queue->expected_sn % RETRANSMIT_QUEUE_SIZE;
    size_t end_index = (seq - 1) % RETRANSMIT_QUEUE_SIZE; // 假定输入的sn是连续且累积的 

    if (queue->entries[index]) {
        spin_unlock(&queue->lock);
        return FLTP_NO_SPACE;
    }

    struct retransmission_entry *entry = kmalloc(sizeof(*entry), GFP_ATOMIC);
    if (!entry) {
        spin_unlock(&queue->lock);
        return FLTP_NO_MEMORY;
    }
    skb_get(skb); // 增加引用计数
    entry->skb = skb;
    entry->seq = seq;
    entry->last_transmit_time = 0;
    entry->retransmit_count = 0;
    queue->entries[index] = entry;
    queue->total_length++;
    if (queue->total_length >= RETRANSMIT_QUEUE_SIZE) {
        queue->throttle_enabled = true;
    }
    spin_unlock(&queue->lock);

    return FLTP_SUCCESS;
}

// 查找重传队列中的数据包
struct retransmission_entry *retransmission_queue_find(struct retransmission_queue *queue, uint32_t seq) {
    if (!queue)
        return NULL;

    size_t index = seq % RETRANSMIT_QUEUE_SIZE;
    struct retransmission_entry *entry = queue->entries[index];
    if (entry && entry->skb && entry->seq == seq) {
        return entry;
    }
    return NULL;
}

// 清理已确认的包
int retransmission_queue_clean_up(struct retransmission_queue *queue, uint32_t seq) {
    if (!queue)
        return FLTP_INVAL_PARAM;

    spin_lock(&queue->lock);
    size_t index = seq % RETRANSMIT_QUEUE_SIZE;
    struct retransmission_entry *entry = queue->entries[index];

    if (entry && entry->skb && entry->seq == seq) {
        kfree_skb(entry->skb);
        kfree(entry);
        queue->entries[index] = NULL;
        queue->total_length--;
        htp_debug("clean seq : %u, totoal_length : %u\n", seq, queue->total_length);
        if (queue->throttle_enabled && queue->total_length < RETRANSMIT_QUEUE_SIZE) {
            queue->throttle_enabled = false;
        }
    }
    spin_unlock(&queue->lock);

    return FLTP_SUCCESS;
}

bool skb_in_queue(struct sk_buff *skb) {
    return skb->next != NULL || skb->prev != NULL;
}

int retransmit_packet(struct retransmission_queue *queue, uint32_t seq) {
    if (!queue)
        return FLTP_INVAL_PARAM;

    spin_lock(&queue->lock);
    struct retransmission_entry *entry = retransmission_queue_find(queue, seq);
    if (!entry) {
        htp_err("Retransmission queue: seq %u not found\n", seq);
        spin_unlock(&queue->lock);
        return FLTP_INVAL_SEQ; // 没找到包，直接返回
    } else {
        if (skb_in_queue(entry->skb)) {
            htp_err("Retransmission queue: seq %u in send queue\n",seq);
            spin_unlock(&queue->lock);
            return FLTP_SUCCESS;
        }
        struct timespec64 now;
        ktime_get_real_ts64(&now);
        uint8_t cnt = entry->retransmit_count;
        uint64_t last = entry->last_transmit_time;
        if (cnt > 0 && (now.tv_sec * S_TO_MS + now.tv_nsec / NS_TO_MS) - last < RETRY_ONE_TIME) {
            htp_debug("Retransmission queue: seq %u retransmitted too frequently\n", seq);
        } else if (cnt > 1 && (now.tv_sec * S_TO_MS + now.tv_nsec / NS_TO_MS) - last < RETRY_MORE_TIME) {
            htp_debug("Retransmission queue: seq %u retransmitted too frequently\n", seq);
        } else {
            htp_info("Retransmission queue: seq %u success\n", seq);
            fltp_coord_add_packet_first(entry->skb);
            skb_get(entry->skb); // 增加引用计数，因为skb被重新插入到发送队列中
            entry->last_transmit_time = now.tv_sec * S_TO_MS + now.tv_nsec / NS_TO_MS;
            entry->retransmit_count++;
        }
    }
    spin_unlock(&queue->lock);
    return FLTP_SUCCESS;
}