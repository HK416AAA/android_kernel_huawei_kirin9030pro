/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#ifndef DPA_OM_TCPDUMP_H
#define DPA_OM_TCPDUMP_H

#include <linux/semaphore.h>
#include "linux/mm.h"
#include <linux/kthread.h>
#include <linux/kernel.h>
#include <linux/skbuff.h>
#include <linux/netdevice.h>
#include <linux/refcount.h>
#include <linux/timer.h>
#include "bsp_sms.h"

enum {
    DPA_TCPDUMP_STATE_IDLE = 0,
    DPA_TCPDUMP_STATE_START,
    DPA_TCPDUMP_STATE_RUNNING,
    DPA_TCPDUMP_STATE_STOP,

    DAP_TCPDUMP_STATE_MAX
};

struct dpa_tcpdump_ctx {
    struct semaphore sem_tcpdump_task;
    struct task_struct *task;
    struct sk_buff_head list;                    /* sk_buff list */

    unsigned int state;                          /* 状态机 */
    unsigned int refcnt;                         /* 服务启用计数 */
    unsigned int ctrl_msg_send_fail_num;         /* 控制消息发送失败次数 */

    unsigned int no_service_enqueue_fail_num;    /* 无服务时入队失败次数 */
    unsigned int skb_build_fail_num;             /* skb构建失败次数 */
    unsigned int skb_link_type_err_num;          /* skb链路类型错误次数 */
    unsigned int enqueue_skb_num;                /* 累计入队skb个数 */
    unsigned int deliver_times;                  /* 累计批量递交次数 */
    unsigned int enqueue_uplink_skb_num;
    unsigned int enqueue_uplink_pkts;
    unsigned int enqueue_downlink_skb_num;
    unsigned int enqueue_downlink_pkts;
    unsigned int deliver_uplink_skb_num;
    unsigned int deliver_downlink_skb_num;
    unsigned int no_dev_free_skb_num;
    unsigned int normal_free_skb_num;
    unsigned int no_dev_skb_iif;
};

extern struct list_head ptype_all;

int dpa_tcpdump_service_init(void);
int dpa_tcpdump_proc_cb(unsigned char *data, unsigned int size);
void start_dpa_tcpdump_service(void);
void exit_dpa_tcpdump_service(void);

#endif