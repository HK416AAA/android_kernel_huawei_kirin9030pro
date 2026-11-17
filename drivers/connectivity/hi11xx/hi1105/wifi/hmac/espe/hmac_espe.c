/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 * 功能说明 : Hertz平台硬转适配源文件
 */
#ifdef _PRE_WLAN_FEATURE_ESPE
#include "hmac_vap.h"
#include "hmac_espe.h"
#include "hmac_tx_data.h"
#include "hmac_ext_if.h"
#include "hmac_mintp.h"
#ifdef CONFIG_ATP_SERVICE_CLASSIFY
#include "atp_skb_mark.h"
#endif
#ifdef _PRE_WLAN_FEATURE_CLAT
#include "hmac_clat.h"
#endif
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_ESPE_C

/* PFA接口 */
int bsp_wifi_hac_alloc(struct wifi_hac_attr *attr);
int bsp_wifi_hac_free(int port_num);
int bsp_wifi_hac_is_hac_own(struct sk_buff *skb);
int32_t bsp_wifi_hac_recv_skb(int32_t portnum, oal_netbuf_stru *netbuf);
struct sk_buff *bsp_wifi_hac_alloc_skb(unsigned int size, unsigned int resv);
int bsp_wifi_hac_set_macaddr(int vir_port, const struct net_device *ndev);
void bsp_wifi_hac_free_skb(struct sk_buff *skb);

/* 根据net_dev获取vap */
OAL_STATIC hmac_vap_stru *hmac_espe_get_hmac_vap(oal_net_device_stru *net_dev)
{
    mac_vap_stru *mac_vap = NULL;

    if (oal_unlikely(net_dev == NULL)) {
        return NULL;
    }
    mac_vap = (mac_vap_stru *)oal_net_dev_priv(net_dev);
    if (oal_unlikely(mac_vap == NULL)) {
        return NULL;
    }
    return mac_res_get_hmac_vap(mac_vap->uc_vap_id);
}

/* 检查espe端口和状态是否正常 */
OAL_STATIC oal_bool_enum_uint8 hmac_espe_check_port_valid(oal_net_device_stru *net_dev, int32_t port_num)
{
    hmac_vap_stru *hmac_vap = hmac_espe_get_hmac_vap(net_dev);
    if (oal_unlikely(hmac_vap == NULL)) {
        return OAL_FALSE;
    }

    if (oal_unlikely((hmac_vap->espe_info.state != ESPE_STATE_ENABLED) || (hmac_vap->espe_info.port_num != port_num))) {
        return OAL_FALSE;
    }

    return OAL_TRUE;
}

/* wifi发送钩子，注册给硬转模块 */
int32_t hmac_espe_xmit(int32_t port_num, oal_netbuf_stru *netbuf)
{
    oal_net_device_stru *net_dev = NULL;

    if (oal_unlikely((netbuf == NULL) || (netbuf->dev == NULL) || (port_num <= 0) || (port_num > ESPE_PORT_NUM_MAX))) {
        return -OAL_FAIL;
    }
    if (oal_unlikely(bsp_wifi_hac_is_hac_own(netbuf) == OAL_FALSE)) {
        return -OAL_FAIL;
    }
    net_dev = netbuf->dev;
    if (oal_unlikely(hmac_espe_check_port_valid(net_dev, port_num) != OAL_TRUE)) {
        return -OAL_FAIL;
    }

    host_start_record_performance(TX_XMIT_PROC);
    /*
     * NON-MINTP(main scene): hmac_bridge_vap_xmit
     * MINTP: ring tx --> hmac_bridge_vap_xmit_mintp; non-ring tx --> hmac_bridge_vap_xmit
     */
#ifdef CONFIG_ATP_SERVICE_CLASSIFY
    if (atp_common_skb_proc_hook(netbuf, 1) != OAL_SUCC) {
        return OAL_NETDEV_TX_OK;  /* 返回失败，产品内部进行内存释放 */
    }
#endif
    if (oal_likely(netbuf->protocol != htons(ETH_P_D2D)) || !hmac_ring_tx_enabled()) {
        return hmac_bridge_vap_xmit(netbuf, net_dev);
    } else {
        return hmac_bridge_vap_xmit_mintp(netbuf, net_dev);
    }
}

/* wifi接收上报espe */
void hmac_espe_recv(oal_netbuf_stru *netbuf)
{
    int32_t ret;
    hmac_vap_stru *hmac_vap = NULL;

    if (oal_unlikely((netbuf == NULL) || (netbuf->dev == NULL) || (netbuf->data == NULL))) {
        return;
    }
    hmac_vap = hmac_espe_get_hmac_vap(netbuf->dev);
    if (oal_unlikely(hmac_vap == NULL)) {
        return;
    }
    /* espe没创建，或者内存不是maa的，上报协议栈 */
    if (hmac_vap->espe_info.state != ESPE_STATE_ENABLED) {
        oal_netif_rx_ni(netbuf);
        return;
    }
    /* 硬转需要push一个以太网头 */
    oal_netbuf_push(netbuf, ETHER_HDR_LEN);
#ifdef _PRE_WLAN_FEATURE_CLAT
    if (hmac_clat_proc(hmac_vap->pst_net_device, netbuf, IPV4_TO_IPV6) != OAL_SUCC) {
        oam_warning_log0(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_RX, "Clat change ip V4-> ip V6 failed");
    }
#endif
    ret = bsp_wifi_hac_recv_skb(hmac_vap->espe_info.port_num, netbuf);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_RX, "hmac_espe_recv:skb_upload_failed[%d]", ret);
    }
}

oal_netbuf_stru *hmac_espe_alloc_skb(uint32_t size)
{
    oal_netbuf_stru *buf = NULL;
    uint32_t offset;
    uint32_t align_size;

    /* 保证data部分的size不会再字节对齐后小于预先想分配的大小 */
    align_size = size + (WLAN_MEM_NETBUF_ALIGN - 1);

    if (align_size > ESPE_MAX_NETBUF_LEN) {
        /* 如果长度大于硬转支持的长度，转为从内核申请 */
        return oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF, size, OAL_NETBUF_PRIORITY_HIGH);
    }

    buf = bsp_wifi_hac_alloc_skb(align_size, ESPE_NETBUF_RESERVE);
    if (oal_unlikely(buf == NULL)) {
        return NULL;
    }

    skb_reserve(buf, ESPE_NETBUF_RESERVE);

    offset = ((uintptr_t)buf->data) % WLAN_MEM_NETBUF_ALIGN;
    if (offset != 0) {
        skb_reserve(buf, WLAN_MEM_NETBUF_ALIGN - offset);
    }
    return buf;
}

static uint32_t hmac_espe_set_mac_addr(oal_net_device_stru *net_dev, hmac_vap_stru *hmac_vap)
{
    int32_t res = OAL_SUCC;

    res = bsp_wifi_hac_set_macaddr(hmac_vap->espe_info.port_num, net_dev);
    if (res != OAL_SUCC) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, 0, "hmac_espe_set_mac_addr:set_failed[%d]",
            hmac_vap->espe_info.port_num);
        return OAL_FAIL;
    }
    oam_warning_log0(0, 0, "hmac_espe_set_mac_addr:set_mac_addr_succ");
    return OAL_SUCC;
}

/* 初始化espe */
void hmac_espe_init(hmac_vap_stru *hmac_vap)
{
    wifi_hac_attr_stru espe_attr = { 0 };
    oal_net_device_stru *net_device = NULL;
    int32_t espe_port;

    if (oal_unlikely(hmac_vap == NULL)) {
        return;
    }

    net_device = hmac_vap->pst_net_device;
    if (oal_unlikely(net_device == NULL)) {
        return;
    }

    if ((oal_strncmp(net_device->name, "wlan0", OAL_IF_NAME_SIZE) != 0) &&
        (oal_strncmp(net_device->name, "wlan1", OAL_IF_NAME_SIZE) != 0) &&
        (oal_strncmp(net_device->name, "wlan2", OAL_IF_NAME_SIZE) != 0) &&
        (oal_strncmp(net_device->name, "wlan3", OAL_IF_NAME_SIZE) != 0)) {
        oam_warning_log0(hmac_vap->st_vap_base_info.uc_vap_id, 0, "hmac_espe_init:netdev_not_support");
        return;
    }

    if (oal_unlikely(hmac_vap->espe_info.state != ESPE_STATE_DISABLED)) {
        oam_warning_log0(hmac_vap->st_vap_base_info.uc_vap_id, 0, "hmac_espe_init:espe_has_been_inited");
        return;
    }

    espe_attr.net_device = net_device;
    espe_attr.level = ESPE_DEFAULT_LEVEL;
    espe_attr.xmit_cb = hmac_espe_xmit;
    espe_attr.rx_done_cb = NULL;
    espe_attr.add_entry_cb = NULL;
    espe_port = bsp_wifi_hac_alloc(&espe_attr);
    if ((espe_port <= 0) || (espe_port > ESPE_PORT_NUM_MAX)) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, 0, "hmac_espe_init:espe_init_failed[%d]", espe_port);
        return;
    }

    /* 保存端口并配置espe状态 */
    hmac_vap->espe_info.port_num = espe_port;
    hmac_vap->espe_info.state = ESPE_STATE_ENABLED;
    /* 给对应端口配置mac */
    hmac_espe_set_mac_addr(net_device, hmac_vap);
    oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, 0, "hmac_espe_init:espe_init_succ, port[%d]", espe_port);
}

/* 销毁espe */
void hmac_espe_deinit(hmac_vap_stru *hmac_vap)
{
    int32_t free_res;

    if (oal_unlikely(hmac_vap == NULL)) {
        return;
    }

    if (oal_unlikely(hmac_vap->espe_info.state != ESPE_STATE_ENABLED)) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, 0, "hmac_espe_deinit:espe_state_invalid[%d]",
            hmac_vap->espe_info.state);
        hmac_vap->espe_info.state = ESPE_STATE_DISABLED;
        return;
    }

    free_res = bsp_wifi_hac_free(hmac_vap->espe_info.port_num);
    if (oal_unlikely(free_res != OAL_SUCC)) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, 0,
            "hmac_espe_deinit::bsp_wifi_hac_free return %d.", free_res);
    }
    /* 最终都改为disable，用于后续重复注册 */
    hmac_vap->espe_info.state = ESPE_STATE_DISABLED;
    oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, 0, "hmac_espe_deinit:espe_deinit_succ, port[%d]",
        hmac_vap->espe_info.port_num);
}

#endif
