/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Header file of hcc_base.c
 * Author: dpa drivers
 */

#ifndef HCC_BASE_H
#define HCC_BASE_H

#include <stdint.h>
#include "oal_net.h"
#include "oal_util.h"
#include "oal_types.h"
#include "oal_mutex.h"
#include "mdrv_kevent.h"
#include "hcc_comm.h"
#include "mdrv_sem.h"
#include "bsp_dma.h"

#define HCC_EVENT_MODE      (OS_EVENT_ANY)
#define HCC_THREAD_SIZE     0x1000
#define HCC_MAX_PEERS_NUM   16

#define HCC_QUEUE_FC_HIGH_WATER_DROP_LINE 100
#define HCC_TX_LOW_WATERLINE  512
#define HCC_TX_HIGH_WATERLINE 1024

typedef struct hcc_info {
    mdrv_task_id task_id;
    uint32_t event_type;
    uint32_t running_flag;
    uint32_t excep_id;
    uint32_t open_event;
    uint32_t close_event;
    uint32_t dfr_event;
    mdrv_sem_id run_sem;
    void* stack_addr;
} hcc_info_t;

typedef enum hcc_bus_type {
    HCC_BUS_SDIO = 0,
    HCC_BUS_PCIE,
    HCC_BUS_DMI, /* For future */
    HCC_BUS_BUTT
} hcc_bus_type_t;

typedef enum hcc_netbuf_queue_type {
    HCC_NETBUF_NORMAL_QUEUE = 0, /* netbuf is shared with others */
    HCC_NETBUF_HIGH_QUEUE = 1,   /* netbuf is special for high pri */
    HCC_NETBUF_QUEUE_BUTT
} hcc_netbuf_queue_type_t;

typedef enum _hcc_queue_type_ {
    CTRL_QUEUE = 0,
    DATA_HI_QUEUE = 1,
    DATA_LO_QUEUE = 2,
    HCC_QUEUE_COUNT
} hcc_queue_type_t;

typedef enum hcc_chan_type {
    HCC_TX = 0x0,
    HCC_RX = 0x1,
    HCC_DIR_COUNT
} hcc_chan_type;

typedef enum hcc_state {
    HCC_OFF = 0x0,
    HCC_ON = 0x1,
    HCC_EXCEPTION = 0x2,
} hcc_state_t;

/* Power Action */
typedef enum _hcc_bus_power_action_type_ {
    HCC_BUS_POWER_DOWN,               /* The action when wlan power down */
    HCC_BUS_POWER_UP,                 /* The action when wlan power up */
    HCC_BUS_POWER_PATCH_LOAD_PREPARE, /* The action before patch downlaod */
    HCC_BUS_POWER_PATCH_LAUCH,        /* The action after patch download before channel enabled */
    HCC_BUS_SW_POWER_DOWN,            /* switch power down */
    HCC_BUS_SW_POWER_UP,              /* switch power down */
    HCC_BUS_SW_POWER_PATCH_LAUCH,     /* swtich power patch lauch */
    HCC_BUS_SW_POWER_PATCH_LOAD_PREPARE,
    HCC_BUS_POWER_SLEEP,              /* The action when wlan sleep */
    HCC_BUS_POWER_BUTT
} hcc_bus_power_action_type;

typedef struct hcc_transfer_param {
    uint32_t main_type;
    uint32_t sub_type;
    uint32_t extend_len;
    uint32_t fc_flag;
    uint32_t queue_id; /* 期望进入的队列号, */
} hcc_transfer_param_t;

typedef int32_t (*hcc_rx_pre_do)(uint8_t stype, oal_netbuf_stru *netbuf, uint8_t **pre_do_context);
typedef int32_t (*hcc_rx_post_do)(uint8_t stype, oal_netbuf_stru *netbuf, uint8_t *pre_do_context);

typedef int32_t (*hcc_process_handler)(uint32_t event);

typedef struct hcc_rx_action {
    hcc_rx_pre_do pre_do;
    hcc_rx_post_do post_do;
    void *context; /* the callback argument */
} hcc_rx_action;

typedef struct hcc_flow_ctrl {
    uint8_t enable;
    uint16_t is_stopped;
    uint16_t low_waterline;
    uint16_t high_waterline;
} hcc_flow_ctrl_t;

typedef struct hcc_trans_queue {
    oal_netbuf_head_stru data_queue;
    oal_netbuf_head_stru ready_queue;
    mdrv_sem_id queue_sem;
    hcc_flow_ctrl_t flow_ctrl;
    uint32_t total_pkts;
    uint32_t loss_pkts;
} hcc_trans_queue;

typedef struct _hcc_trans_queues_ {
    hcc_trans_queue queues[HCC_QUEUE_COUNT];
    peerlist *peers;
    uint32_t peers_num;
} hcc_trans_queues;

// 暂定32, +1用于存异常值，ete仅需16，后续看eicc最大聚合度修改
#define HCC_TRANS_ASSEM_INFO_MAX_NUM    (32 + 1)
typedef struct _hcc_tx_assem_info_ {
    /* The +1 for the single pkt */
    uint32_t info[HCC_TRANS_ASSEM_INFO_MAX_NUM];
    uint64_t pkt_cnt; /* pps count for switch */
} hcc_trans_info;

typedef struct _hcc_handler_ {
    hcc_trans_queues hcc_queues[HCC_DIR_COUNT];
    hcc_rx_action rx_action[HCC_ACTION_TYPE_BUTT];
    oal_mutex_stru tx_transfer_lock;
    oal_mutex_stru rx_transfer_lock;
    uint32_t pkt_index;
    int32_t state;

    hcc_trans_info tx_assem_info;
    hcc_trans_info rx_assem_info;
} hcc_handler_t;

typedef struct _hcc_bus_ hcc_bus_t;
typedef struct hcc_bus_ops {
    int32_t (*rx_queue_sched)(hcc_bus_t *pst_bus, oal_netbuf_head_stru *pst_head);
    int32_t (*tx_queue_sched)(hcc_bus_t *pst_bus, oal_netbuf_head_stru *pst_head, hcc_netbuf_queue_type_t qtype);

    int32_t (*tx_condition)(hcc_bus_t *pst_bus, hcc_netbuf_queue_type_t qtype); /* ip idle ?, 1 is idle, 0 is busy */
    int32_t (*pending_signal_process)(hcc_bus_t *pst_bus); /* process中要清掉调度标记，否者会死循环 */
    int32_t (*sleep_request_host)(hcc_bus_t *pst_bus); /* 检查Host是否满足睡眠条件 */
    /* do something before power on/off */
    int32_t (*power_action)(hcc_bus_t *pst_bus, hcc_bus_power_action_type action);

    /* device cpu address<->device pcie address
     * <->host io address<-> host cpu virtual address
     * is_host_va ,
     *   if ture ,src_addr means  host cpu virtual address, return device cpu address
     *   if false ,src_addr means device cpu address, return host virtual address
     */
    int32_t (*master_address_switch)(hcc_bus_t *pst_bus, uint64_t src_addr, uint64_t* dst_addr, int32_t is_host_va);

    /* host ddr iommu/smmu address <-> pcie slave address
     * is_host_iova ,
     *   if ture ,src_addr means smmu io virtual address or kernel dma address
     *   if false ,src_addr means pcie ep slave address(start with 0x80000000)
     */
    int32_t (*slave_address_switch)(hcc_bus_t *pst_bus, uint64_t src_addr, uint64_t* dst_addr, int32_t is_host_iova);
} hcc_bus_ops_t;

struct _hcc_bus_ {
    hcc_bus_type_t type;
    int32_t tx_sched_count; /* 每次发送调度的包个数 */
    hcc_bus_ops_t *ops;
};

typedef struct _hcc_bus_res_ {
    hcc_bus_type_t cur_type;
    hcc_bus_t *bus[HCC_BUS_BUTT];
    hcc_handler_t hcc_handler;
} hcc_bus_res_t;

/*
 * 函 数 名  : oal_netbuf_hcc_header
 * 功能描述  : 获取sbuf hcc header 地址
 * 输入参数  : netbuf: 报文结构体指针
 */
static inline netbuf_data_addr oal_netbuf_hcc_header(oal_netbuf_stru *netbuf)
{
    return (netbuf_data_addr)oal_netbuf_data(netbuf) - HCC_HDR_TOTAL_LEN;
}

/*
 * 函 数 名  : oal_netbuf_hcc_header_iova
 * 功能描述  : 获取sbuf hcc header io地址
 * 输入参数  : netbuf: 报文结构体指针
 */
static inline netbuf_data_addr oal_netbuf_hcc_header_iova(oal_netbuf_stru *netbuf)
{
    return (netbuf_data_addr)oal_netbuf_data_iova(netbuf) - HCC_HDR_TOTAL_LEN;
}

// hcc lock
int32_t hcc_lock_init(hcc_handler_t *hcc);
void hcc_lock_deinit(hcc_handler_t *hcc);
static inline int32_t hcc_rx_transfer_lock(hcc_handler_t *hcc)
{
    return oal_mutex_lock(&hcc->rx_transfer_lock);
}

static inline int32_t hcc_rx_transfer_unlock(hcc_handler_t *hcc)
{
    return oal_mutex_unlock(&hcc->rx_transfer_lock);
}

static inline int32_t hcc_tx_transfer_lock(hcc_handler_t *hcc)
{
    return oal_mutex_lock(&hcc->tx_transfer_lock);
}

static inline int32_t hcc_tx_transfer_unlock(hcc_handler_t *hcc)
{
    return oal_mutex_unlock(&hcc->tx_transfer_lock);
}

OAL_STATIC OAL_INLINE int32_t hcc_bus_check_tx_condition(hcc_bus_t *hi_bus, hcc_netbuf_queue_type_t qtype)
{
    if (oal_unlikely(hi_bus == NULL)) {
        return OAL_TRUE;
    }

    if (oal_unlikely(hi_bus->ops->tx_condition == NULL)) {
        /* 没有回调说明 发送不受限制 直接返回1 */
        return OAL_TRUE;
    }

    return hi_bus->ops->tx_condition(hi_bus, qtype);
}

OAL_STATIC OAL_INLINE int32_t hcc_bus_pending_signal_process(hcc_bus_t *hi_bus)
{
    if (oal_unlikely(hi_bus == NULL)) {
        return 0;
    }

    if (oal_unlikely(hi_bus->ops->pending_signal_process == NULL)) {
        return 0;
    }

    return hi_bus->ops->pending_signal_process(hi_bus);
}

#define MASTER_VA_TO_WCPUADDR   OAL_TRUE
#define MASTER_WCPUADDR_TO_VA   OAL_FALSE
OAL_STATIC OAL_INLINE int32_t hcc_bus_master_address_switch(hcc_bus_t *hi_bus, uint64_t src_addr,
                                                            uint64_t *dst_addr, int32_t is_host_va)
{
    if (oal_unlikely(hi_bus == NULL)) {
        return -OAL_ENODEV;
    }

    if (oal_unlikely(hi_bus->ops == NULL)) {
        return -OAL_ENODEV;
    }

    if (oal_unlikely(hi_bus->ops->master_address_switch == NULL)) {
        return -OAL_ENODEV;
    }

    return hi_bus->ops->master_address_switch(hi_bus, src_addr, dst_addr, is_host_va);
}

#define SLAVE_IOVA_TO_PCI_SLV   OAL_TRUE
#define SLAVE_PCI_SLV_TO_IOVA   OAL_FALSE
OAL_STATIC OAL_INLINE int32_t hcc_bus_slave_address_switch(hcc_bus_t *hi_bus, uint64_t src_addr,
                                                           uint64_t *dst_addr, int32_t is_host_iova)
{
    if (oal_unlikely(hi_bus == NULL)) {
        return -OAL_ENODEV;
    }

    if (oal_unlikely(hi_bus->ops == NULL)) {
        return -OAL_ENODEV;
    }

    if (oal_unlikely(hi_bus->ops->slave_address_switch == NULL)) {
        return -OAL_ENODEV;
    }

    return hi_bus->ops->slave_address_switch(hi_bus, src_addr, dst_addr, is_host_iova);
}

/* 统计一次传输的最大报文个数，每次传输报文个数越多，调度消耗占比越低
 * info[0]表示聚合个数超过了最大统计大小 */
OAL_STATIC OAL_INLINE void hcc_tx_assem_count(hcc_handler_t *hcc, uint32_t assem_count)
{
    if (oal_unlikely(hcc == NULL)) {
        oal_io_print("%s,hcc is null", __FUNCTION__);
        return;
    }
    if (oal_unlikely(assem_count == 0)) {
        return;
    }
    if (oal_likely(assem_count < sizeof(hcc->rx_assem_info.info) / sizeof(hcc->rx_assem_info.info)[0])) {
        hcc->tx_assem_info.info[assem_count]++;
    } else {
        hcc->tx_assem_info.info[0]++;
    }
}

OAL_STATIC OAL_INLINE void hcc_rx_assem_count(hcc_handler_t *hcc, uint32_t assem_count)
{
    if (oal_unlikely(hcc == NULL)) {
        oal_io_print("%s,hcc is null", __FUNCTION__);
        return;
    }
    if (oal_unlikely(assem_count == 0)) {
        return;
    }
    if (oal_likely(assem_count < sizeof(hcc->rx_assem_info.info) / sizeof(hcc->rx_assem_info.info)[0])) {
        hcc->rx_assem_info.info[assem_count]++;
    } else {
        hcc->rx_assem_info.info[0]++;
    }
}

// hcc queue
hcc_netbuf_queue_type_t hcc_queue_map_to_netbuf_queue(hcc_queue_type_t qtype);
hcc_bus_t *hcc_bus_get_cur_bus(hcc_handler_t *hcc_handler);
hcc_trans_queue *hcc_bus_get_rx_queue(hcc_handler_t *hcc_handler, uint32_t queue_id);
hcc_trans_queue *hcc_bus_get_tx_queue(hcc_handler_t *hcc_handler, uint32_t queue_id);
int32_t hcc_bus_tx_queue_sched(hcc_handler_t *hcc_handler, oal_netbuf_head_stru *tx_head, uint32_t queue_id);
int32_t hcc_bus_rx_queue_sched(hcc_handler_t *hcc_handler, oal_netbuf_head_stru *rx_head, uint32_t queue_id);
int32_t hcc_dma_memcpy_submit_sync(completed_handler *dma_hdl, peerlist *peers,
                                   mdrv_sem_id sem_id, uint32_t trans_cnt);
void hcc_tx_get_netbuf_header(hcc_handler_t *hcc_handler, uint32_t queue_id);
void hcc_rx_get_netbuf_header(hcc_handler_t *hcc_handler, uint32_t queue_id);
// hcc buffer
void hcc_hdr_param_init(hcc_transfer_param_t *param, uint32_t main_type, uint32_t sub_type,
                        uint32_t extend_len, uint32_t fc_flag, uint32_t queue_id);
void hcc_build_header(hcc_handler_t *hcc_handler, oal_netbuf_stru *netbuf,
                      uint16_t pay_load_len, hcc_transfer_param_t *param);
oal_netbuf_stru *hcc_netbuf_alloc(uint32_t size);
oal_netbuf_stru *hcc_netbuf_build(netbuf_data_addr payload_addr, uint32_t payload_len);
void hcc_netbuf_free(oal_netbuf_stru *netbuf);

// hcc process
int32_t hcc_tx(hcc_handler_t *hcc_handler, oal_netbuf_stru *netbuf,
               uint16_t pay_load_len, hcc_transfer_param_t *param);
void hcc_rx(hcc_handler_t *hcc_handler, oal_netbuf_stru *netbuf, uint32_t queue_id);
void hcc_set_thread_func(hcc_process_handler func);
void hcc_thread_open(void);
void hcc_thread_close(void);
int32_t hcc_thread_event_acquire(uint32_t *event);
void hcc_thread_event_relasese(uint32_t event);
void hcc_thread_stop(void);
uint32_t hcc_thread_should_stop(void);
int32_t hcc_rx_register(hcc_handler_t *hcc_handler, uint8_t mtype, hcc_rx_post_do post_do, hcc_rx_pre_do pre_do);
int32_t hcc_rx_unregister(hcc_handler_t *hcc_handler, uint8_t mtype);
void hcc_sched_transfer(uint32_t event);

int32_t hcc_bus_sleep_request_host(hcc_handler_t *hcc_handler);
int32_t hcc_bus_power_action(hcc_handler_t *hcc_handler, hcc_bus_power_action_type action);
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
void dpe_rx_async_debug_show(void); // 内存申请失败的维测，问题定位后删除
void dpe_tx_debug_show(void);
#endif
// hcc init
int32_t hcc_module_init(void);
void hcc_module_exit(void);
int32_t hcc_handler_queues_init(hcc_handler_t *hcc_handler);
void hcc_handler_queues_deinit(hcc_handler_t *hcc_handler);
void hcc_handler_queues_clear(hcc_handler_t *hcc_handler);
void hcc_change_state(hcc_handler_t *hcc_handler, int32_t state);
#endif /* end of Hcc.h */
