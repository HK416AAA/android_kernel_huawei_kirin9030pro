/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : Free/Complete ring基本操作
 * 作者       : wifi
 * 创建日期   : 2018年4月26日
 */

#ifndef HOST_HAL_RING_H
#define HOST_HAL_RING_H

#include "oal_types.h"
#include "host_hal_device.h"

#define HAL_MULTILINK_TX_BITMAP_LINK0 1
#define HAL_MULTILINK_TX_BITMAP_LINK1 2
#define HAL_MULTILINK_TX_BITMAP_ALL_LINK 3

typedef enum {
    HAL_HOST_TX_UPDATE_MSDU_INFO_RING_LSB,
    HAL_HOST_TX_UPDATE_MSDU_INFO_RING_MSB,
    HAL_HOST_TX_UPDATE_MSDU_ADDR_RING_LSB,
    HAL_HOST_TX_UPDATE_MSDU_ADDR_RING_MSB,
    HAL_HOST_TX_UPDATE_WPTR,
    HAL_HOST_TX_UPDATE_RPTR, /* 非multilink rptr 或 multilink ml0 rptr */
    HAL_HOST_TX_UPDATE_ML1_RPTR,
    HAL_HOST_TX_UPDATE_RING_DEPTH,
    HAL_HOST_TX_UPDATE_MAX_AGGR_AMSDU_NUM,
    HAL_HOST_TX_UPDATE_SW_WPTR,
    HAL_HOST_TX_UPDATE_SW_RPTR,
    HAL_HOST_TX_UPDATE_SW_ML1_RPTR,
    HAL_HOST_TX_UPDATE_ML_MODE,
    HAL_HOST_TX_UPDATE_ML0_DUP_EN,
    HAL_HOST_TX_UPDATE_ML1_DUP_EN,
    HAL_HOST_TX_UPDATE_ML_BITMAP,

    HAL_HOST_TX_UPDATE_OPS_BUTT,
} hal_host_tx_ring_update_ops_enum;

typedef enum {
    HAL_HOST_TX_GET_HW_RPTR, /* 非multilink rptr 或 multilink ml0 rptr */
    HAL_HOST_TX_GET_HW_ML1_RPTR,
    HAL_HOST_TX_GET_SW_WPTR,
    HAL_HOST_TX_GET_HW_WPTR,
    HAL_HOST_TX_GET_HW_SEQ_NUM,
    HAL_HOST_TX_GET_HW_ML1_SEQ_NUM,
    HAL_HOST_TX_GET_HW_ML_BITMAP,

    HAL_HOST_TX_GET_OPS_BUTT,
} hal_host_tx_ring_get_ops_enum;

typedef struct {
    uint64_t tx_ring_table_addr;
    uint32_t val;
    uint8_t lut_idx;
    uint8_t tid;
} hal_host_tx_ring_ops_param_stru;

typedef struct {
    uint8_t *ring_buf;
    uint8_t *ddr_ring_buf;
    uint64_t bus_addr;
    uint64_t devva;
    uint32_t mem_size; /* 整个Ring内存总大小, 而非Ring数组长度 */
} hal_host_tx_ring_buf_stru;

typedef struct {
    hal_host_tx_ring_buf_stru msdu_info_ring;
    hal_host_tx_ring_buf_stru msdu_addr_ring;
} hal_host_tx_msdu_ring_stru;

typedef struct {
    uint64_t info_devva;
    uint64_t addr_devva;
} hal_tx_ring_table_addr_stru;

typedef struct {
    uint64_t addr_val;
} hal_tx_ring_table_addr_val_stru;

/*-------------------tx msdu批量入ring相关定义------------------*/
/* 批量写tx ring时所使用临时msdu数组的最大数量 */
#define PUSH_NETBUF_TO_RING_PER_TIME 64
#define TX_RING_MSDU_MAX_NUM (PUSH_NETBUF_TO_RING_PER_TIME * 2)
 
/* 新增addr ring结构和info ring结构，方便批量memcpy到tx ring */
typedef struct {
    uint32_t msdu_addr_lsb;
    uint32_t msdu_addr_msb;
} host_tx_msdu_addr_stru;
 
typedef struct {
    uint32_t msdu_len      : 12;
    uint32_t data_type     : 4;
    uint32_t frag_num      : 4;
    uint32_t to_ds         : 1;
    uint32_t from_ds       : 1;
    uint32_t more_frag     : 1;
    uint32_t reserved      : 1;
    uint32_t aggr_msdu_num : 4;
    uint32_t first_msdu    : 1;
    uint32_t csum_type     : 3;
} host_tx_msdu_info_stru;
 
/* 批量写tx ring时的参数 */
typedef struct {
    host_tx_msdu_addr_stru msdu_addr_ring[TX_RING_MSDU_MAX_NUM];
    host_tx_msdu_info_stru msdu_info_ring[TX_RING_MSDU_MAX_NUM];
    uint16_t ring_depth;        /* tx ring深度，用于判断批量写ring时是否出现翻转 */
    uint16_t batch_num;         /* 有效数 */
    uint16_t pre_write_ptr;     /* 批量写ring时的起始位置 */
    uint16_t read_ptr;
} host_tx_msdu_ring_batch_stru;
/* ------------------------------------------------------- */

/* 判断ring是否为满，如果满，返回TRUE;反之，返回FALSE */
static inline bool hal_ring_is_full(hal_host_ring_ctl_stru *ring_ctl)
{
    return (((ring_ctl)->un_write_ptr.st_write_ptr.bit_write_ptr == \
        (ring_ctl)->un_read_ptr.st_read_ptr.bit_read_ptr) && \
        ((ring_ctl)->un_write_ptr.st_write_ptr.bit_wrap_flag != (ring_ctl)->un_read_ptr.st_read_ptr.bit_wrap_flag));
}

/* 判断ring是否为空，如果空，返回TRUE;反之，返回FALSE */
static inline bool hal_ring_is_empty(hal_host_ring_ctl_stru *ring_ctl)
{
    return ((ring_ctl)->un_write_ptr.write_ptr == (ring_ctl)->un_read_ptr.read_ptr);
}

/* 判断ring是否翻转，如果翻转，返回TRUE;反之，返回FALSE */
static inline bool hal_ring_wrap_around(hal_host_ring_ctl_stru *ring_ctl)
{
    return ((ring_ctl)->un_read_ptr.st_read_ptr.bit_wrap_flag != (ring_ctl)->un_write_ptr.st_write_ptr.bit_wrap_flag);
}

typedef enum {
    HAL_RING_TYPE_INVALID,
    /* Free ring: 软件操作write ptr, HW操作read ptr */
    HAL_RING_TYPE_FREE_RING,
    /* Complete ring: 软件操作read ptr, HW操作write ptr */
    HAL_RING_TYPE_COMPLETE_RING,

    HAL_RING_TYPE_BUTT
} hal_ring_type_enum;

/* 读出rx comp ring与处理接收skb流程之间的数据中转站, 用于缓存wifi物理层接收与wifi媒体层的数据缓存池,替换ping-pong队列 */
#define HAL_RX_COMPLETE_BUFF_POOL_SIZE  (4096 * 8)
typedef struct {
    uint64_t rx_comp_data_buff_pool[HAL_RX_COMPLETE_BUFF_POOL_SIZE];
    uint32_t buff_pool_depth;      // 最大缓存3.2w帧
    uint32_t write_ptr;           /* 中断写指针 */
    uint32_t read_ptr;            /* 软件读指针 */
    uint32_t sbuf_num;            /* 统计维测 */
    uint32_t overloop;
} host_rx_comp_buff_pool_stru;

void hal_host_ring_init(void);
void hal_host_rx_ring_init(void);
host_tx_msdu_ring_batch_stru *hal_host_get_tx_ring_batch(void);
host_rx_comp_buff_pool_stru *hal_host_get_rx_buff_pool(void);
uint8_t hal_rx_buff_pool_is_empty(hal_host_device_stru *hal_dev);
uint64_t hal_host_rx_get_from_buff_pool(void);
void hal_ring_get_hw2sw(hal_host_ring_ctl_stru *ring_ctl);
uint32_t hal_ring_set_sw2hw(hal_host_ring_ctl_stru *ring_ctl);
uint32_t hal_ring_get_entry_count(hal_host_device_stru *hal_dev, hal_host_ring_ctl_stru *ring_ctl, uint16_t *p_count);
uint32_t hal_ring_get_entries(hal_host_ring_ctl_stru *ring_ctl, uint8_t *entries, uint16_t count);
uint32_t hal_ring_reset_entries(hal_host_ring_ctl_stru *ring_ctl, uint16_t read_idx, uint16_t count);
uint32_t hal_ring_set_entries(hal_host_ring_ctl_stru *ring_ctl, uint64_t entry);
void hmac_update_free_ring_wptr(hal_host_ring_ctl_stru *ring_ctl, uint16_t count);
void hal_host_ring_tx_deinit(hal_host_device_stru *hal_device);
uint32_t hal_host_tx_dma_alloc_ring_buf(hal_host_tx_ring_buf_stru *ring_buf, uint32_t mem_size, uint8_t mirror);
uint32_t hal_host_tx_dma_release_ring_buf(hal_host_tx_ring_buf_stru *ring_buf);
uint32_t hal_host_rx_ring_entry_get(hal_host_device_stru *hal_dev,
    hal_host_ring_ctl_stru *ring_ctl, oal_netbuf_head_stru *netbuf_head);
uint16_t hal_host_tx_rw_smaller_ptr(uint16_t rptr_val1, uint16_t rptr_val2, uint16_t wptr_val);
#endif /* HAL_RING_H */
