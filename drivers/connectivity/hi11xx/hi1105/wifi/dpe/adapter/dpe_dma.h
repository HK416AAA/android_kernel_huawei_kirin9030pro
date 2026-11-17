/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : EICC dma搬运接口
 * 作    者 : xianglei
 * 创建日期 : 2025年3月26日
 */
#ifndef DPE_DMA_H
#define DPE_DMA_H

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "mdrv_sem.h"
#include "bsp_dma.h"
#include "bsp_memory.h"
#include "oal_util.h"
#include "oal_net.h"

#define MAX_DMA_CPY_LIST 256

typedef enum {
    DPE_RX_ADD_BUFF_DMA, /* 异步DMA: 接收补内存 */
    DPE_RX_COMP_DMA,     /* 异步DMA: 接收数据帧 */
    DPE_HCC_RX_EVT,      /* 同步信道量DMA：plat hcc收到的事件 */
    DPE_FRW_EVENT_DMA,   /* 同步信道量DMA：wifi dpe发送的事件 */
    DPE_TX_COMP_DMA,     /* 同步等待DMA：udelay,功能测试接口 */
    DPE_WLAN_XMIT_DMA,   /* 同步等待DMA：udelay,功能测试接口 */

    DPE_DMA_BUTT
} dpe_dma_cpy_type;

typedef enum {
    RX_GET_ADD_BUFF_NUM_EVENT,
    RX_ADD_BUFF_DMA_START_EVENT,
    RX_ADD_BUFF_DMA_DONE_EVENT,

    RX_ADD_BUFF_EVENT_BUTT
} rx_add_buff_event_enum;

typedef void (*wifi_serv_dma_comp_cb)(void *dma_comp);

typedef struct {
    uint8_t dpe_dma_type;
    uint8_t is_dma_busy;
    uint16_t need_dma_num;

    /* 同步DMA */
    mdrv_sem_id sem_id;
    peerlist single_peer;
    /* 异步DMA */
    peerlist *peer_list;
    uint32_t peers_num;
    completed_handler dma_hdl;
    void *wifi_serv_dma;

    /* 专属dma通道 */
    dma_chn dpe_dma_chn;
} dpe_dma_stru;

typedef struct {
    oal_netbuf_head_stru dma_list;
    wifi_serv_dma_comp_cb dma_done_cb;
    oal_netbuf_head_stru dma_todo_list;
    uint8_t hal_dev_id;
    uint16_t need_dma_num;
    uint16_t dma_next_state;
} dpe_dma_rx_add_buff_cbk_stru;

/* 实测16性能最高,CPU负载最低;粒度降低可以增加dma/cpu的并发度 */
#define DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME 16

#define DPE_RX_DATA_COMP_DMA_START 0
#define DPE_RX_DATA_COMP_DMA_CONTINUE 1
#define DPE_RX_DATA_COMP_RX_REORDER 2

#ifdef _PRE_MULTI_CORE_DPE_DMA_ASYNC
typedef struct {
    oal_netbuf_head_stru mpdu_list; /* 每个mpdu包含N个msdu的skb链 */
    uint32_t sub_msdu_num;          /* mpdu包含的N个sub msdu, 包含首帧 */
    uint16_t crc_fail;
    uint16_t sub_msdu_flag;
} dma_mpdu_node;

typedef struct {
    /* dma业务公共结构, 定义名称保持一致 */
    oal_netbuf_head_stru dma_list;
    uint64_t dma_array[DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME]; /* 子帧host_iova地址数组,源地址 */
    uint64_t rx_info_array[DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME]; /* 子帧目的地址，暂存rx msdu info + eth/ip header */
    uint8_t dma_list_num;
    wifi_serv_dma_comp_cb dma_done_cb;

    /* dma业务各私有结构, 定义按需配置 */
    uint32_t hal_dev_id;
    uint32_t dma_transfer_level; /* continue最大深度统计 */
    uint32_t dma_cur_state; /* 当前DMA状态机的状态 */
    uint32_t dma_next_state; /* 当前DMA状态机的状态 */
    dma_mpdu_node dma_mpdu_array[DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME]; /* dma矩阵链表 */
} dma_rx_comp_stru;  // 两个实例, 并行加速
#endif

#define DPE_RX_ADD_BUFF_DMA_LEN 64
#define DPE_SC_MODE_OFFSET 36
/* 60:64 - 4字节地址长度，rx msdu dscr长度不能超过60，超过需要调整结构体 */
#define WIFI_DPE_RX_DMA_DSCR_MAX_LEN 60
typedef struct {
    uint32_t sbuf_addr;
    uint8_t msdu_info[WIFI_DPE_RX_DMA_DSCR_MAX_LEN];
} dpe_rx_msdu_init_stru; /* 64字节 */

#define WIFI_DPE_XMIT_DSCR_LEN 64
#define WIFI_DPE_XMIT_DMA_CLR_LEN  256
extern uint8_t g_tx_msdu_dscr_init_dma[WIFI_DPE_XMIT_DMA_CLR_LEN];
extern uint8_t g_rx_msdu_dscr_init_dma[WIFI_DPE_XMIT_DMA_CLR_LEN];
extern dpe_rx_msdu_init_stru g_rx_msdu_dma_init[DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME];
dpe_dma_stru *dpe_get_dma_hdl(uint32_t service_type);
uint32_t dpe_dma_cpy_sync(uint64_t src_addr, uint64_t dst_addr, uint32_t len, uint8_t dpe_dma_type);
uint32_t dpe_dma_sem_init(void);
void dpe_dma_sem_deinit(void);
dma_rx_comp_stru *dpe_get_rx_comp_hdl(void);
#endif
#endif