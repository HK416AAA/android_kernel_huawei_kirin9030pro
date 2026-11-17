

#ifndef DPE_FRW_IF_H
#define DPE_FRW_IF_H
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
/* 其他头文件包含 */
#include "oal_ext_if.h"
#include "dpe_thread.h"

typedef enum {
    FRW_EVENT_TYPE_HIGH_PRIO = 0,    /* 高优先级事件队列 */
    FRW_EVENT_TYPE_HOST_CRX,         /* 接收Host侧发来的配置事件 */
    FRW_EVENT_TYPE_HOST_DRX,         /* 接收Host侧发来的数据事件 */
    FRW_EVENT_TYPE_HOST_CTX,         /* 发向HOST侧的配置事件 */
    FRW_EVENT_TYPE_HOST_SDT_REG = 4, /* SDT读取寄存器，wifi驱动侧上报SDT */
    FRW_EVENT_TYPE_WLAN_CRX,         /* 接收Wlan侧发来的管理/控制帧事件 */
    FRW_EVENT_TYPE_WLAN_DRX,         /* 接收Wlan侧发来的数据帧事件 */
    FRW_EVENT_TYPE_WLAN_CTX,         /* 管理/控制帧发送至Wlan侧事件 */
    FRW_EVENT_TYPE_WLAN_DTX,         /* 数据帧发送至Wlan侧事件 */
    FRW_EVENT_TYPE_WLAN_TX_COMP = 9, /* 发送完成事件 */
    FRW_EVENT_TYPE_TBTT,             /* TBTT中断事件 */
    FRW_EVENT_TYPE_TIMEOUT,          /* FRW普通超时事件 */
    FRW_EVENT_TYPE_DMAC_MISC = 13,   /* DMAC杂散事件 */

    /* 添加新的事件类型 */
    FRW_EVENT_TYPE_BUTT
} frw_event_type_enum;

typedef enum {
    FRW_EVENT_PIPELINE_STAGE_0 = 0,
    FRW_EVENT_PIPELINE_STAGE_1,
    FRW_EVENT_PIPELINE_STAGE_BUTT
} frw_event_pipeline_enum;

typedef enum {
    FRW_EVENT_TO_WCORE = 0,
    FRW_EVENT_TO_ACORE = 1,
} frw_event_dir;
typedef enum {
    HAL_EVENT_TBTT_SUB_TYPE,

    HAL_EVENT_TBTT_SUB_TYPE_BUTT
} hal_event_tbtt_sub_type_enum;

/*
 * 结构名  : frw_event_sub_table_item_stru
 * 结构说明: 事件子表结构体
 */
typedef struct {
    uint32_t (*p_func)(oal_netbuf_stru *); /* (type, subtype, pipeline)类型的事件对应的处理函数 */
    uint32_t (*p_tx_adapt_func)(oal_netbuf_stru *);
    uint32_t (*p_rx_adapt_func)(oal_netbuf_stru *);
} frw_event_sub_table_item_stru;

/*
 * 结构名  : frw_event_table_item_stru
 * 结构说明: 事件表结构体
 */
typedef struct {
    frw_event_sub_table_item_stru *pst_sub_table; /* 指向子表的指针 */
} frw_event_table_item_stru;

#pragma pack(push, 1)
struct frw_hcc_extend_hdr {
    uint8_t en_nest_type;
    uint8_t uc_nest_sub_type;
    uint8_t chip_id : 2;
    uint8_t device_id : 2;
    uint8_t vap_id : 4;
};

struct hcc_frw_wifi_hdr {
    struct hcc_header         hcc_hdr;
    uint8_t                   padding;
    struct frw_hcc_extend_hdr frw_hdr;
    uint8_t                   wifi_cb[19]; // 19B
    uint8_t                   wifi_80211[36]; // 36B
};

/*
 * 结构名  : frw_event_hdr_stru
 * 结构说明: 事件头结构体,
 * 备注    : uc_length的值为(payload长度 + 事件头长度 - 2)
 */
typedef struct {
    uint8_t en_type;         /* 事件类型 */
    uint8_t uc_sub_type;     /* 事件子类型 */
    uint16_t us_length;      /* 事件总体长度 */
    uint8_t en_pipeline       : 1;     /* 事件分段号 */
    uint8_t transfer_event_to : 1;     /* DPA上的事件流转方向 */
    uint8_t resv : 6;
    uint8_t uc_device_id;    /* 设备ID */
    uint8_t uc_vap_id;       /* VAP ID */
    uint8_t hcc_extend;   /* 64字节HCC HDR中WIFI占用字节数 */
} frw_event_hdr_stru;

typedef struct {
    uint8_t txed_count;
    uint8_t not_maa_sbuf : 1;
    uint8_t resv : 7;
    uint8_t rsv0[6];
} dpe_cb_stru;

typedef struct {
    struct hcc_frw_wifi_hdr hcc_hdr; /* cb_head1 64B */
    uint8_t skb_cb[48];              /* cb_head2 48B, 由oal_netbuf_cb指向  */
    uint8_t dpe_cb[8];               /* cb_head2 8B, 由oal_dpe_cb指向  */
    frw_event_hdr_stru st_event_hdr; /* cb_head2 8B  */
    uint8_t rsv[128];
} dpe_frw_event_stru;
#pragma pack(pop)

typedef struct {
    frw_event_type_enum type;
    uint8_t subtype;
    uint8_t vap_id;
    uint8_t hal_device_id;
    uint8_t pipeline;
    uint8_t transfer_event_to; /* 事件去往HCC还是WIFI */
    uint8_t hcc_extend;   /* 64字节HCC HDR中WIFI占用字节数 */
    uint16_t payload_size;
    uint8_t *payload;
    oal_netbuf_stru *netbuf;
} frw_event_param_stru;

typedef struct {
    oal_dlist_head_stru entry;
    oal_netbuf_stru *netbuf;
    frw_event_param_stru param;
} dpe_frw_mem_stru;

typedef struct {
    dpe_thread_info thread_info;
    oal_dlist_head_stru frw_list;
} dpe_frw_stru;

extern dpe_frw_stru g_frw_thread;
int32_t dpe_frw_thread(void *p_data);
uint32_t frw_post_event(frw_event_param_stru *param);
void dpe_frw_list_free(void);
void frw_event_table_register(uint8_t en_type, frw_event_pipeline_enum en_pipeline,
    frw_event_sub_table_item_stru *sub_table);
void event_fsm_table_register(void);
void frw_event_hdr_init(dpe_frw_event_stru *frw_event, frw_event_param_stru *param);
uint32_t frw_event_dispatch_event(frw_event_param_stru *event);
#endif /* _PRE_MULTI_CORE_DPE_OFFLOAD */
#endif
