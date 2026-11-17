/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 * 功能说明 : Hertz平台硬转适配头文件
 */
#ifndef HMAC_ESPE_H
#define HMAC_ESPE_H
#ifdef _PRE_WLAN_FEATURE_ESPE

/* 宏定义 */
#define ESPE_DEFAULT_LEVEL 1
#define ESPE_PORT_NUM_MAX 0xFFFF
#define ESPE_MAX_NETBUF_LEN 1536    /* PFA接口限制 */
#define ESPE_NETBUF_RESERVE 0

/* 枚举定义 */
enum {
    ESPE_STATE_DISABLED,
    ESPE_STATE_ENABLED,
    ESPE_STATE_BUTT
};

/* 结构体定义 */
typedef struct {
    uint8_t state;
    uint8_t rsv;
    uint16_t port_num;
} hmac_vap_espe_stru;

typedef struct wifi_usr_attr {
    uint8_t tid;
    uint8_t frame_type;
    uint8_t vap_id;
    uint8_t band_id;

    uint16_t usr_id;
    uint8_t asic_id;
    uint8_t reserve1;

    unsigned char destmac[ETHER_ADDR_LEN];
    uint16_t reserve2;
} wifi_usr_attr_stru;

typedef void (*wifi_hac_rx_done_cb_t)(int32_t handle, oal_netbuf_stru *netbuf);
typedef int32_t (*wifi_hac_xmit_cb_t)(int32_t handle, oal_netbuf_stru *netbuf);
typedef int32_t (*wifi_hac_add_entry_cb_t)(int32_t handle, oal_netbuf_stru *netbuf, wifi_usr_attr_stru *usr);

typedef struct wifi_hac_attr {
    oal_net_device_stru *net_device;
    int32_t level; /* 1~n */
    wifi_hac_rx_done_cb_t rx_done_cb;
    wifi_hac_xmit_cb_t xmit_cb;
    wifi_hac_add_entry_cb_t add_entry_cb;
} wifi_hac_attr_stru;

typedef struct hmac_vap_tag hmac_vap_stru;

/* 接口定义 */
void hmac_espe_init(hmac_vap_stru *hmac_vap);
void hmac_espe_deinit(hmac_vap_stru *hmac_vap);
void hmac_espe_recv(oal_netbuf_stru *netbuf);
oal_netbuf_stru *hmac_espe_alloc_skb(uint32_t size);

#endif
#endif