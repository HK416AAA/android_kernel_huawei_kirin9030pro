/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: dmi消息驱动适配
 * Author: dpa drivers
 */

#include "osl_list.h"
#include "osl_thread.h"
#include "mdrv_kevent.h"
#include "oal_util.h"
#include "oal_mm.h"
#include "oal_types.h"
#include "board_pm.h"
#include "conn_dmi_hal.h"
#include "conn_dmi_msg.h"

#define CONN_DMI_MSG_PRIV_DATA_LEN 16
#define DMI_MSG_RECV_THREAD_SIZE     0x1000
#define DMI_MSG_RECV_EVENT_MODE      (OS_EVENT_ANY)

typedef union {
    struct {
        uint16_t local_req_ack : 1;    // 本端请求对端发送ack事件
        uint16_t remote_resp_ack : 1;  // 远端响应ack事件
    } bits;
    uint16_t as_word;
} conn_dmi_cap;

// 双端通信固定的结构体
struct conn_dmi_msg_inter_stru {
    uint8_t type;
    conn_dmi_cap cap;
    uint16_t data_len;
    uint8_t data[CONN_DMI_MSG_DATA_LEN];
};

// 双端内部私有结构体
struct conn_dmi_msg_priv_stru {
    msg_resp_cb resp;
    void *priv;
};

// 该结构体大小要与对端A核保持一致，需同步修改
struct conn_dmi_msg_stru {
    struct conn_dmi_msg_inter_stru inter;
    // 如下位内部数据
    uint8_t priv_data[CONN_DMI_MSG_PRIV_DATA_LEN];
};

// 消息下半部结构体
struct conn_dmi_msg_thread_stru {
    struct osl_list node;
    struct conn_dmi_msg_stru data;
};

typedef struct dmi_msg_recv_info {
    mdrv_task_id task_id;
    uint32_t event_type;
    bool running_flag;
    void *stack_addr;
} dmi_msg_recv_info_t;

// 链表初始化
OSL_LIST_DEF(g_msg_thread_proc_queue);
oal_spin_lock_stru g_dmi_msg_thread_spinlock;

static dmi_msg_recv_info_t g_dmi_msg_recv_thread_info;
static con_dmi_msg_proc g_dmi_msg_proc[CONN_DMI_MSG_BUF];
static con_dmi_msg_thread_proc g_dmi_msg_thread_proc[CONN_DMI_MSG_BUF];

static void dmi_msg_recv_sched_transfer(void);

int32_t conn_dmi_msg_regiser(enum conn_dmi_msg_type msg_type, con_dmi_msg_proc cb,
                             con_dmi_msg_thread_proc cb_thread)
{
    if (msg_type >= CONN_DMI_MSG_BUF) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_msg_regiser msg type %u invalid", msg_type);
        return -OAL_FAIL;
    }

    g_dmi_msg_proc[msg_type] = cb;
    g_dmi_msg_thread_proc[msg_type] = cb_thread;
    return OAL_SUCC;
}

/*
 * 函 数 名  : conn_dmi_msg_send
 * 功能描述  : 通过dmi接口发送消息
 * 输入参数  : send_msg 待发消息
 */
int32_t conn_dmi_msg_send(uint8_t msg_type, const uint8_t *buf, uint8_t buf_len, msg_resp_cb cb, void *priv)
{
    int32_t ret;
    struct conn_dmi_msg_stru *dmi_msg = NULL;
    struct conn_dmi_msg_priv_stru *dmi_msg_priv = NULL;

    if (buf_len > CONN_DMI_MSG_DATA_LEN) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg send param invalid, len = %u", buf_len);
        return -OAL_FAIL;
    }

    if (msg_type >= CONN_DMI_MSG_BUF) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg send msg_type %u invalid", msg_type);
        return -OAL_FAIL;
    }

    dmi_msg = (struct conn_dmi_msg_stru *)conn_dmi_hal_alloc_buf(sizeof(struct conn_dmi_msg_stru));
    if (dmi_msg == NULL) {
        return -OAL_ENOMEM;
    }

    dmi_msg_priv = (struct conn_dmi_msg_priv_stru *)dmi_msg->priv_data;
    memset_s(dmi_msg, sizeof(struct conn_dmi_msg_stru), 0, sizeof(struct conn_dmi_msg_stru));
    dmi_msg->inter.type = msg_type;
    if (buf != NULL && buf_len != 0) {
        ret = memcpy_s(dmi_msg->inter.data, CONN_DMI_MSG_DATA_LEN, buf, buf_len);
        if (ret != EOK) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg send buf len %u invalid", buf_len);
            conn_dmi_hal_free_buf((uint8_t *)dmi_msg);
            return -OAL_FAIL;
        }
    }

    dmi_msg->inter.data_len = buf_len;
    if (cb != NULL) {
        dmi_msg->inter.cap.bits.local_req_ack = OAL_TRUE;
        dmi_msg_priv->resp = cb;
        dmi_msg_priv->priv = priv;
    }

    ret = conn_dmi_hal_send(DMI_HAL_TYPE_MSG, (uint8_t *)dmi_msg, sizeof(struct conn_dmi_msg_stru));
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg send fail, ret = %d", ret);
        conn_dmi_hal_free_buf((uint8_t *)dmi_msg);
        return ret;
    }

    conn_dmi_hal_free_buf((uint8_t *)dmi_msg);
    return OAL_SUCC;
}

/*
 * 函 数 名  : conn_dmi_msg_rx_ack_process
 * 功能描述  : 本核发过去的消息，对端已传回，调用发送时带的cb函数
 */
static int32_t conn_dmi_msg_rx_ack_process(uint8_t msg_type, uint8_t *buf, uint16_t buf_len)
{
    struct conn_dmi_msg_stru *msg = NULL;
    struct conn_dmi_msg_priv_stru *msg_priv = NULL;

    // 发送回来的数据应该与发过去的长度一致
    if (buf_len != (uint16_t)sizeof(struct conn_dmi_msg_stru)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi ack msg len %u invaid", buf_len);
        return -OAL_FAIL;
    }

    msg = (struct conn_dmi_msg_stru *)buf;
    msg_priv = (struct conn_dmi_msg_priv_stru *)msg->priv_data;
    if (msg_priv->resp == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi ack callback is NULL");
        return -OAL_FAIL;
    }

    return ((msg_resp_cb)msg_priv->resp)(msg_type, (void *)msg_priv->priv);
}

/*
 * 函 数 名  : conn_dmi_msg_rx_ack_send_back
 * 功能描述  : 接收到对端核消息, 直接调用返回
 */
static int32_t conn_dmi_msg_rx_ack_send_back(uint8_t msg_type, uint8_t *buf, uint16_t buf_len)
{
    int32_t ret;
    uint8_t *send_buf = NULL;
    struct conn_dmi_msg_stru *msg = NULL;
    struct conn_dmi_msg_inter_stru *msg_inter = NULL;
    conn_dmi_cap cap;
    if (buf == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg rx ack param invalid");
        return -OAL_FAIL;
    }

    msg = (struct conn_dmi_msg_stru *)buf;
    msg_inter = &msg->inter;
    cap.as_word = msg_inter->cap.as_word;

    // 不需要将消息回传，直接返回
    if (cap.bits.local_req_ack == OAL_FALSE) {
        return OAL_SUCC;
    }

    // 这里需要把标记位改掉，对端才知道时回传消息
    cap.bits.remote_resp_ack = OAL_TRUE;
    msg_inter->cap.as_word = cap.as_word;

    send_buf = conn_dmi_hal_alloc_buf(buf_len);
    if (send_buf == NULL) {
        return -OAL_ENOMEM;
    }

    ret = memcpy_s(send_buf, buf_len, buf, buf_len);
    if (ret != EOK) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg rx ack memcpy_s fail");
        conn_dmi_hal_free_buf(send_buf);
        return ret;
    }

    ret = conn_dmi_hal_send(DMI_HAL_TYPE_MSG, send_buf, buf_len);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg rx ack send fail, ret = %d", ret);
        conn_dmi_hal_free_buf(send_buf);
        return ret;
    }

    conn_dmi_hal_free_buf(send_buf);
    return OAL_SUCC;
}

/*
 * 函 数 名  : conn_dmi_msg_rx_process
 * 功能描述  : 消息处理函数
 */
static int32_t conn_dmi_msg_rx_process(uint8_t msg_type, uint8_t *buf, uint16_t buf_len)
{
    unsigned long irq_sts;
    struct conn_dmi_msg_thread_stru *msg_buf = NULL;
    struct conn_dmi_msg_inter_stru *msg_inter = NULL;
    struct conn_dmi_msg_stru *msg = NULL;

    msg = (struct conn_dmi_msg_stru *)buf;
    msg_inter = &msg->inter;

    // 处理消息上半部, 处理失败直接返回
    if (g_dmi_msg_proc[msg_type] != NULL) {
        if (g_dmi_msg_proc[msg_type]((uint8_t *)msg_inter->data, (uint16_t)msg_inter->data_len) != OAL_SUCC) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg %u process fail", msg_type);
            return -OAL_FAIL;
        }
    }

    // 处理消息下半部, 消息入队直接返回
    if (g_dmi_msg_thread_proc[msg_type] != NULL) {
        msg_buf = (struct conn_dmi_msg_thread_stru *)oal_memalloc(sizeof(struct conn_dmi_msg_thread_stru));
        if (msg_buf == NULL) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg thread proc mem alloc fail");
            return -OAL_ENOMEM;
        }
        OSL_LIST_INIT(&msg_buf->node);
        if (memcpy_s((void *)&msg_buf->data, sizeof(struct conn_dmi_msg_stru), buf, buf_len) != EOK) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg thread proc memcpy fail");
            oal_free(msg_buf);
            return -OAL_FAIL;
        }
        oal_spin_lock_irq_save(&g_dmi_msg_thread_spinlock, &irq_sts);
        osl_list_insert_tail(&msg_buf->node, &g_msg_thread_proc_queue);
        oal_spin_unlock_irq_restore(&g_dmi_msg_thread_spinlock, &irq_sts);
        dmi_msg_recv_sched_transfer();
        return OAL_SUCC;
    }

    // 上半部处理成功, 无下半部消息处理, 直接返回ACK消息
    return conn_dmi_msg_rx_ack_send_back(msg_type, buf, buf_len);
}

static int32_t conn_dmi_msg_rx_cap_process(uint8_t msg_type, uint8_t *buf, uint16_t buf_len)
{
    struct conn_dmi_msg_inter_stru *msg_inter = NULL;
    struct conn_dmi_msg_stru *msg = NULL;
    conn_dmi_cap cap;

    msg = (struct conn_dmi_msg_stru *)buf;
    msg_inter = &msg->inter;
    cap.as_word = msg_inter->cap.as_word;

    // 接收到本核消息的答应ack, 仅执行内容回调
    if (cap.bits.local_req_ack == OAL_TRUE && cap.bits.remote_resp_ack == OAL_TRUE) {
        return conn_dmi_msg_rx_ack_process(msg_type, buf, buf_len);
    }

    return conn_dmi_msg_rx_process(msg_type, buf, buf_len);
}

static int32_t conn_dmi_msg_rx_func(uint8_t *buf, uint16_t buf_len)
{
    struct conn_dmi_msg_stru *msg = NULL;
    struct conn_dmi_msg_inter_stru *msg_inter = NULL;

    if (buf == NULL || buf_len < (uint16_t)sizeof(struct conn_dmi_msg_stru)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg rx param invalid, len %u", buf_len);
        return -OAL_FAIL;
    }

    msg = (struct conn_dmi_msg_stru *)buf;
    msg_inter = &msg->inter;
    /* 当前消息类型校验 */
    if (msg_inter->type >= CONN_DMI_MSG_BUF) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg type %u invalid", msg_inter->type);
        return -OAL_FAIL;
    }
    /* 回调注册检查 */
    if (g_dmi_msg_proc[msg_inter->type] == NULL && g_dmi_msg_thread_proc[msg_inter->type] == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg %u need to register", msg_inter->type);
        return -OAL_FAIL;
    }

    return conn_dmi_msg_rx_cap_process(msg_inter->type, buf, buf_len);
}

static int32_t conn_dmi_msg_rx_err_func(uint8_t *buf, uint16_t buf_len)
{
    return OAL_SUCC;
}

static void dmi_msg_recv_task_handler(void)
{
    unsigned long irq_sts;
    struct conn_dmi_msg_thread_stru *cur_node = NULL;
    struct conn_dmi_msg_thread_stru *next_node = NULL;
    struct conn_dmi_msg_inter_stru *msg_inter = NULL;
    struct conn_dmi_msg_stru *msg = NULL;

    osl_list_loop_node_safe(cur_node, next_node, &g_msg_thread_proc_queue, node) {
        oal_spin_lock_irq_save(&g_dmi_msg_thread_spinlock, &irq_sts);
        osl_list_remove(&cur_node->node);
        oal_spin_unlock_irq_restore(&g_dmi_msg_thread_spinlock, &irq_sts);
        msg = (struct conn_dmi_msg_stru *)&cur_node->data;
        msg_inter = &msg->inter;
        if (msg_inter->type >= CONN_DMI_MSG_BUF) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg thread proc msg_type %u invalid", msg_inter->type);
            oal_free(cur_node);
            continue;
        }
        if (g_dmi_msg_thread_proc[msg_inter->type] == NULL) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg thread proc func is null, type = %d", msg_inter->type);
            oal_free(cur_node);
            continue;
        }
        if (g_dmi_msg_thread_proc[msg_inter->type](msg_inter->data, msg_inter->data_len) != OAL_SUCC) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg thread proc %u fail", msg_inter->type);
            oal_free(cur_node);
            continue;
        }
        // 下半部消息处理成功, 返回ACK消息
        conn_dmi_msg_rx_ack_send_back(msg_inter->type, (uint8_t *)&cur_node->data, sizeof(struct conn_dmi_msg_stru));
        oal_free(cur_node);
    }
}

/*
 * 函 数 名  : dmi_msg_recv_sched_transfer
 * 功能描述  : dmi_msg线程调度函数
 */
static void dmi_msg_recv_sched_transfer(void)
{
    mdrv_kevent_send(g_dmi_msg_recv_thread_info.task_id, 1);
}

bool dmi_msg_thread_is_running(void)
{
    return g_dmi_msg_recv_thread_info.running_flag;
}

void dmi_msg_thread_stop(void)
{
    g_dmi_msg_recv_thread_info.running_flag = false;
}

/*
 * 函 数 名  : dmi_msg_thread_process
 * 功能描述  : dmi_msg线程处理函数
 */
static int32_t dmi_msg_thread_process(void *param)
{
    uint32_t recv_event;
    oal_print_mpxx_log(MPXX_LOG_INFO, "dmi_msg_thread_process enter");
    while (dmi_msg_thread_is_running()) {
        recv_event = 0;
        mdrv_kevent_recv(g_dmi_msg_recv_thread_info.event_type,
                         DMI_MSG_RECV_EVENT_MODE, OS_EVENT_WAIT_FOREVER, &recv_event);
        dmi_msg_recv_task_handler();
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : dmi_msg_thread_create
 * 功能描述  : dmi_msg线程创建函数
 */
static int32_t dmi_msg_thread_create(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    int32_t ret;

    g_dmi_msg_recv_thread_info.stack_addr = mdrv_mem_alloc(DMI_MSG_RECV_THREAD_SIZE, MEM_CACHE | MDRV_MEM_ALIGN_016);
    if (g_dmi_msg_recv_thread_info.stack_addr == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi_msg_thread_create stack mem alloc fail");
        return -OAL_FAIL;
    }

    task_attr.type = THRD_TASK;
    task_attr.prio = OS_TSK_PRIORITY_01;
    task_attr.stackSize = DMI_MSG_RECV_THREAD_SIZE;
    task_attr.stackAddr = (uintptr_t)g_dmi_msg_recv_thread_info.stack_addr;
    task_attr.queNum = 1;
    task_attr.args[0] = 0;
    task_attr.entryFunc = dmi_msg_thread_process,
    ret = (int32_t)osl_task_create("hisi_dmi_msg", &task_attr, 1, &g_dmi_msg_recv_thread_info.task_id);
    if (ret) {
        mdrv_free(g_dmi_msg_recv_thread_info.stack_addr);
        oal_print_mpxx_log(MPXX_LOG_ERR, "osl_task_create hisi_dmi_msg fail, ret = 0x%x", ret);
        return -OAL_FAIL;
    }
    g_dmi_msg_recv_thread_info.event_type = 0xFFFFFFFF;
    g_dmi_msg_recv_thread_info.running_flag = true;
    return OAL_SUCC;
}

void dmi_msg_thread_destory(void)
{
    uint32_t ret;

    ret = mdrv_task_delete(g_dmi_msg_recv_thread_info.task_id);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "mdrv_task_delete hisi_oam fail, ret = 0x%x", ret);
    }
    mdrv_free(g_dmi_msg_recv_thread_info.stack_addr);
}

int32_t conn_dmi_msg_init(void)
{
    int32_t ret;

    oal_build_bug_on((sizeof(struct conn_dmi_msg_priv_stru) > CONN_DMI_MSG_PRIV_DATA_LEN));
    conn_dmi_hal_init();

    /* dmi hcc接收线程初始化 */
    ret = dmi_msg_thread_create();
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi_msg_recv_thread_create fail");
        return -OAL_FAIL;
    }

    oal_spin_lock_init(&g_dmi_msg_thread_spinlock);
    // 注册msg消息到dmi
    conn_dmi_hal_rx_register(DMI_HAL_TYPE_MSG, conn_dmi_msg_rx_func, conn_dmi_msg_rx_err_func);
    return OAL_SUCC;
}

void conn_dmi_msg_deinit(void)
{
    conn_dmi_hal_rx_register(DMI_HAL_TYPE_MSG, NULL, NULL);
    oal_spin_lock_exit(&g_dmi_msg_thread_spinlock);
    dmi_msg_thread_destory();
}