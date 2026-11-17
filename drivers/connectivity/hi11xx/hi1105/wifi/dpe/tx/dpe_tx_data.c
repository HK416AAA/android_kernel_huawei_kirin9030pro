/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpe_tx_data.c
 * 创建日期 : 2025年1月4日
 */

#include "dpe_tx_data.h"
#include "mac_data.h"
#include "hmac_tx_msdu_dscr.h"
#include "hmac_host_ring_tx.h"
#include "hmac_tx_ring_alloc.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "hmac_tcp_ack_buf.h"
#include "hmac_tx_data.h"
#endif
#include "hmac_tid_sche.h"
#include "hmac_tid_update.h"
#include "hmac_tid_ring_switch.h"
#include "hmac_host_performance.h"
#include "dpe_wlan_vap.h"
#include "dpe_wlan_stat.h"
#include "dpe_schedule.h"
#include "hd_trx_data.h"
#include "host_hal_dma.h"
#include "dpe_sbuf.h"
#include "dpe_dpa_intf.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_TX_DATA_C

#define oal_high_half_byte(a) (((a) & 0xF0) >> 4)
#define oal_low_half_byte(a)  ((a) & 0x0F)

void dpe_trx_switch_sync(wlan_trx_switch_stru *trx_switch)
{
    int32_t ret;
    ret = memcpy_s(&g_dpe_trx_switch, sizeof(wlan_trx_switch_stru), trx_switch, sizeof(wlan_trx_switch_stru));
    if (ret != EOK) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_trx_switch_sync::memcpy fail}");
    }
}

/*
 * host ring tx流控水线, ring中sk_buff数量:
 * 达到上水线(suspend)时, 停止mac_vap对应的netdev下发数据帧
 * 降低至下水线(resume)时, 恢复mac_vap对应的netdev下发数据帧
 */
static inline uint32_t hmac_ring_tx_suspend_th(hmac_tid_info_stru *tid_info)
{
    return (hal_host_tx_tid_ring_depth_get(tid_info->tx_ring.base_ring_info.size) * 7 / 8); // 7/8: 流控上水线(87.5%)
}

static inline uint32_t hmac_ring_tx_resume_th(hmac_tid_info_stru *tid_info)
{
    return (hal_host_tx_tid_ring_depth_get(tid_info->tx_ring.base_ring_info.size) * 1 / 2); // 1/2: 流控上水线(50%)
}

OAL_STATIC void hmac_host_ring_tx_suspend(dpe_wlan_vap_stru *dpe_vap, dpe_wlan_user_stru *dpe_user,
    hmac_tid_info_stru *tid_info)
{
    oal_net_device_stru *netdev = NULL;
    if (dpe_vap == NULL || dpe_user == NULL) {
        return;
    }

    netdev = dpe_vap_get_net_device(dpe_vap->uc_vap_id);
    if (netdev == NULL) {
        return;
    }

    /* AP模式不能关net_dev队列，否则会导致其他用户无法发包 */
    if (dpe_vap->en_vap_mode == WLAN_VAP_MODE_BSS_AP) {
        return;
    }

    if ((uint32_t)oal_atomic_read(&tid_info->tx_ring.msdu_cnt) < hmac_ring_tx_suspend_th(tid_info) ||
        oal_atomic_read(&dpe_user->atomic_val->netdev_tx_suspend)) {
        return;
    }

    if (oal_atomic_read(&dpe_vap->atomic_val->tx_suspend_user_cnt) == 0) {
        oal_net_tx_stop_all_queues(netdev);
    }

    oal_atomic_inc(&dpe_vap->atomic_val->tx_suspend_user_cnt);
    oal_atomic_set(&dpe_user->atomic_val->netdev_tx_suspend, OAL_TRUE);
}

void hmac_host_ring_tx_resume(dpe_wlan_vap_stru *dpe_vap, dpe_wlan_user_stru *dpe_user, hmac_tid_info_stru *tid_info)
{
    oal_net_device_stru *netdev = NULL;
    if (dpe_vap == NULL || dpe_user == NULL) {
        return;
    }

    netdev = dpe_vap_get_net_device(dpe_vap->uc_vap_id);
    if (netdev == NULL) {
        return;
    }

    if ((uint32_t)oal_atomic_read(&tid_info->tx_ring.msdu_cnt) > hmac_ring_tx_resume_th(tid_info) ||
        !oal_atomic_read(&dpe_user->atomic_val->netdev_tx_suspend)) {
        return;
    }

    oal_atomic_dec(&dpe_vap->atomic_val->tx_suspend_user_cnt);
    if (oal_atomic_read(&dpe_vap->atomic_val->tx_suspend_user_cnt) == 0) {
        oal_net_tx_wake_all_queues(netdev);
    }

    oal_atomic_set(&dpe_user->atomic_val->netdev_tx_suspend, OAL_FALSE);
}

/*
 * 函 数 名  : oal_free_netbuf_list
 * 功能描述  : 释放一个netbuf链，此链中的skb或者都来自lan，或者都来自wlan
 * 1.日    期  : 2012年11月14日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_free_netbuf_list(oal_netbuf_stru *netbuf)
{
    oal_netbuf_stru *next = NULL;

    if (oal_unlikely(!netbuf)) {
        oam_error_log0(0, OAM_SF_DPA, "{hmac_free_netbuf_list::netbuf is null}");
        return;
    }

    while (netbuf) {
        next = oal_netbuf_next(netbuf);
        dpe_netbuf_free(netbuf);
        netbuf = next;
    }
}

#define MAC_DATA_DOUBLE_VLAN_MIN_LEN           22   /* 双vlan最小报文长度 */
#define MAC_DATA_DOUBLE_VLAN_ETHER_TYPE_OFFSET (ETHER_ADDR_LEN * 2 + sizeof(mac_vlan_tag_stru) * 2)
/*
 * 功能描述 : 设置VLAN以太帧的data type、snap cb字段
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_ether_with_double_vlan_tag(oal_netbuf_stru *netbuf, uint16_t ether_type)
{
    return (oal_netbuf_len(netbuf) >= MAC_DATA_DOUBLE_VLAN_MIN_LEN &&
           (ether_type == oal_host2net_short(ETHER_TYPE_VLAN_88A8) ||
           ether_type == oal_host2net_short(ETHER_TYPE_VLAN_9100) ||
           ether_type == oal_host2net_short(ETHER_TYPE_VLAN))) ? OAL_TRUE : OAL_FALSE;
}

/*
 * 功能描述 : 双vlan以太网报文的情况下, 返回第二个vlan的ether type
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE uint16_t hmac_ether_get_second_vlan_type(uint8_t *vlan_ether_hdr)
{
    return *(uint16_t *)(vlan_ether_hdr + MAC_DATA_DOUBLE_VLAN_ETHER_TYPE_OFFSET);
}

/*
 * 功能描述 : 设置VLAN以太帧的data type、snap cb字段
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC void hmac_ether_set_vlan_data_type(mac_tx_ctl_stru *tx_ctl, oal_netbuf_stru *netbuf)
{
    uint16_t ether_type = 0;
    oal_vlan_ethhdr_stru *vlan_ether_hdr = (oal_vlan_ethhdr_stru *)dpe_tx_get_eth_hdr_info(netbuf);
    if (vlan_ether_hdr == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hmac_ether_set_vlan_data_type:vlan_ether_hdr null");
        return;
    }
    ether_type = vlan_ether_hdr->h_vlan_encapsulated_proto;

    /* 单vlan以太网类型报文 */
    mac_get_cb_data_type(tx_ctl) = DATA_TYPE_1_VLAN_ETH;

    if (hmac_ether_with_double_vlan_tag(netbuf, ether_type) == OAL_TRUE) {
        /* 双vlan以太网报文 */
        mac_get_cb_data_type(tx_ctl) = DATA_TYPE_2_VLAN_ETH;

        /* 取第2个vlan后面的2字节用于802.3报文判断, DA|SA|VLAN|VLAN|TYPE(LEN)|DATA */
        ether_type = hmac_ether_get_second_vlan_type((uint8_t *)vlan_ether_hdr);
    }

    /* 判断是否是802.3报文 */
    mac_get_cb_is_802_3_snap(tx_ctl) = oal_net2host_short(ether_type) <= MAC_DATA_TYPE_INVALID_MIN_VALUE;
}

/*
 * 功能描述 : 设置其他以太帧的data type、snap cb字段
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE void hmac_ether_set_other_data_type(mac_tx_ctl_stru *tx_ctl, oal_netbuf_stru *netbuf)
{
    uint16_t ether_type = mac_get_cb_ether_type(tx_ctl);

    mac_get_cb_is_802_3_snap(tx_ctl) = oal_net2host_short(ether_type) <= MAC_DATA_TYPE_INVALID_MIN_VALUE;
}

/*
 * 功能描述 : vlan、其他报文类型检查与设置
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
void hmac_ether_set_data_type(mac_tx_ctl_stru *tx_ctl, oal_netbuf_stru *netbuf)
{
    /* 默认设置 */
    mac_get_cb_data_type(tx_ctl) = DATA_TYPE_ETH;

    switch (mac_get_cb_frame_subtype(tx_ctl)) {
        case MAC_DATA_VLAN:
            hmac_ether_set_vlan_data_type(tx_ctl, netbuf);
            break;
        case MAC_DATA_BUTT:
            hmac_ether_set_other_data_type(tx_ctl, netbuf);
            break;
        default:
            break;
    }

    /* 802.3格式 */
    if (mac_get_cb_is_802_3_snap(tx_ctl)) {
        mac_get_cb_data_type(tx_ctl) |= DATA_TYPE_802_3_SNAP;
    }
}
/*
 * 函 数 名  : oal_netbuf_is_tcp_ack
 * 功能描述  : 判断ipv4 tcp报文是否为tcp 关键帧，包括TCP ACK\TCP SYN帧等
 */
oal_bool_enum_uint8 oal_netbuf_is_tcp_ack(oal_ip_header_stru *ip_hdr)
{
    oal_tcp_header_stru *tcp_hdr = NULL;
    uint32_t ip_pkt_len;
    uint32_t ip_hdr_len;
    uint32_t tcp_hdr_len;

    if (oal_unlikely(ip_hdr == NULL)) {
        oal_warn_on(1);
        return OAL_FALSE;
    }

    tcp_hdr     = (oal_tcp_header_stru *)(ip_hdr + 1);
    ip_pkt_len  = oal_net2host_short(ip_hdr->us_tot_len);
    ip_hdr_len  = (oal_low_half_byte(ip_hdr->us_ihl)) << 2; /* 2 协议规范 */
    tcp_hdr_len = (oal_high_half_byte(tcp_hdr->uc_offset)) << 2; /* 2 协议规范 */
    if (tcp_hdr_len + ip_hdr_len == ip_pkt_len) {
        return OAL_TRUE;
    }

    return OAL_FALSE;
}
static void hmac_set_cb_is_ipv4_tcp(mac_ether_header_stru *ether_hdr, mac_tx_ctl_stru *tx_ctl)
{
    oal_ip_header_stru *ip_hdr = (oal_ip_header_stru *)(ether_hdr + 1);
    oal_tcp_header_stru *tcp_hdr = (oal_tcp_header_stru *)(ip_hdr + 1);

    if (ip_hdr->uc_protocol != MAC_TCP_PROTOCAL) {
        return;
    }

    if (oal_netbuf_is_tcp_ack(ip_hdr)) {
        mac_get_cb_is_tcp_ack(tx_ctl) = OAL_TRUE;

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
        if (hmac_device_tcp_buf_duplicate_ack_proc(ip_hdr)) {
            mac_get_cb_urgent_tcp_ack(tx_ctl) = OAL_TRUE;
        }
#endif
    } else {
        mac_get_cb_is_tcp_data(tx_ctl) = OAL_TRUE;
    }

    if (tcp_hdr->uc_flags & FILTER_FLAG_MASK) {
        mac_get_cb_urgent_tcp_ack(tx_ctl) = OAL_TRUE;
    }
}
/*
 * 功能描述  : 判断ipv6 tcp报文是否为tcp ack
 */
oal_bool_enum_uint8 oal_netbuf_is_tcp_ack6(oal_ipv6hdr_stru *ipv6hdr)
{
    oal_tcp_header_stru *tcp_hdr = NULL;
    uint32_t ip_pkt_len;
    uint32_t tcp_hdr_len;

    if (oal_unlikely(ipv6hdr == NULL)) {
        oal_warn_on(1);
        return OAL_FALSE;
    }

    tcp_hdr = (oal_tcp_header_stru *)(ipv6hdr + 1);
    /* ipv6 净载荷, ipv6报文头部固定为40字节 */
    ip_pkt_len = oal_net2host_short(ipv6hdr->payload_len);
    tcp_hdr_len = (oal_high_half_byte(tcp_hdr->uc_offset)) << 2; /* 2 协议规范 */
    if (tcp_hdr_len == ip_pkt_len) {
        return OAL_TRUE;
    }

    return OAL_FALSE;
}

static void hmac_set_cb_is_ipv6_tcp(mac_ether_header_stru *ether_hdr, mac_tx_ctl_stru *tx_ctl)
{
    oal_ipv6hdr_stru *ipv6_hdr = (oal_ipv6hdr_stru *)(ether_hdr + 1);

    if (ipv6_hdr->nexthdr != TCP_PROTOCAL) {
        return;
    }

    if (oal_netbuf_is_tcp_ack6(ipv6_hdr)) {
        mac_get_cb_ipv6_tcp_ack(tx_ctl) = OAL_TRUE;
    } else {
        mac_get_cb_is_tcp_data(tx_ctl) = OAL_TRUE;
    }
}

/*
 * 功能描述  :  初始化netbuf中CB字段中的is_tcp_ack和urgent_tcp_ack
 */
void hmac_set_cb_is_tcp(mac_tx_ctl_stru *tx_ctl, mac_ether_header_stru *ether_hdr, uint16_t ether_type)
{
    switch (ether_type) {
        case oal_host2net_short(ETHER_TYPE_IP):
            hmac_set_cb_is_ipv4_tcp(ether_hdr, tx_ctl);
            break;
        case oal_host2net_short(ETHER_TYPE_IPV6):
            hmac_set_cb_is_ipv6_tcp(ether_hdr, tx_ctl);
            break;
        default:
            break;
    }
}
/*
 * 功能描述  : 判断ipv4 是否为icmp报文
 * 输入参数  : pst_ip_hdr: IP报文头部
 */
oal_bool_enum_uint8 oal_netbuf_is_icmp(oal_ip_header_stru *ip_hdr)
{
    if (oal_unlikely(ip_hdr == NULL)) {
        oal_warn_on(1);
        return OAL_FALSE;
    }

    /* ICMP报文检查 */
    if (ip_hdr->uc_protocol == ICMP_PROTOCAL) {
        return OAL_TRUE;
    }

    return OAL_FALSE;
}
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU_DEBUG
uint8_t g_netbuf_alg_pkt_no = 0;
#endif
void hmac_tx_cb_field_init(mac_tx_ctl_stru *tx_ctl, uint8_t uc_vap_id, uint8_t en_vap_mode,
    uint16_t user_idx, mac_ether_header_stru *ether_hdr)
{
    uint16_t ether_type;

    if (tx_ctl == NULL || ether_hdr == NULL) {
        return;
    }
    ether_type = ether_hdr->us_ether_type;
    if (en_vap_mode == WLAN_VAP_MODE_BSS_AP) {
        mac_get_cb_is_mcast(tx_ctl) = ether_is_multicast(ether_hdr->auc_ether_dhost);
    }

    if (ether_type == oal_host2net_short(ETHER_TYPE_IP)) {
        mac_get_cb_is_icmp(tx_ctl) = oal_netbuf_is_icmp((oal_ip_header_stru *)(ether_hdr + 1));
    }

    hmac_set_cb_is_tcp(tx_ctl, ether_hdr, ether_type);
    mac_get_cb_ether_type(tx_ctl) = ether_type;
    mac_get_cb_mpdu_num(tx_ctl) = 1;
    mac_get_cb_netbuf_num(tx_ctl) = 1;
    mac_get_cb_ack_policy(tx_ctl) = WLAN_TX_NORMAL_ACK;
    mac_get_cb_tx_vap_index(tx_ctl) = uc_vap_id;
    mac_get_cb_tx_user_idx(tx_ctl) = user_idx;
    /*  初始队列，非qos帧入VO队列 */
    mac_get_cb_wme_ac_type(tx_ctl) = WLAN_WME_AC_VO;
    mac_get_cb_wme_tid_type(tx_ctl) = WLAN_TIDNO_VOICE;
    mac_get_cb_frame_type(tx_ctl) = WLAN_CB_FRAME_TYPE_DATA;
    mac_get_cb_frame_subtype(tx_ctl) = MAC_DATA_NUM; /* 后续识别模块刷新 */
    mac_get_cb_data_type(tx_ctl) = DATA_TYPE_80211;
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU_DEBUG
    if (mac_get_cb_is_mcast(tx_ctl) == OAL_TRUE) {
        mac_get_cb_alg_pktno(tx_ctl) = g_netbuf_alg_pkt_no++;
        oam_warning_log1(uc_vap_id, OAM_SF_DPA, "MCAST_AMPDU::hmac_tx_cb_field_init num[%u]",
            mac_get_cb_alg_pktno(tx_ctl));
    }
#endif
    mac_get_cb_frame_subtype(tx_ctl) = MAC_DATA_NUM;
}

static uint8_t hmac_tid_ring_tx_allowed(mac_tx_ctl_stru *tx_ctl)
{
    uint8_t tid = 0;
    hmac_tid_info_stru *tid_info = NULL;
    dpe_wlan_user_stru *dpe_user = NULL;
    if (tx_ctl == NULL) {
        oam_warning_log0(0, OAM_SF_DPA, "{hmac_tid_ring_tx_allowed::tx_ctl NULL}");
        return OAL_FALSE;
    }
    tid = mac_get_cb_wme_tid_type(tx_ctl);
    dpe_user = dpe_wlan_user_get(mac_get_cb_tx_user_idx(tx_ctl));
    if (oal_unlikely(dpe_user == NULL)) {
        oam_warning_log0(0, OAM_SF_DPA, "{hmac_tid_ring_tx_allowed::dpe_user NULL}");
        return OAL_FALSE;
    }

    /* 不支持组播聚合的组播用户预期没有ring，直接返回 */
    if (dpe_wlan_is_multi_user_not_support_ampdu(dpe_user) == OAL_TRUE) {
        return OAL_FALSE;
    }

    tid_info = dpe_get_tx_tid_info(dpe_user->us_assoc_id, tid);
    if (tid_info == NULL) {
        return OAL_FALSE;
    }

    return hmac_tid_info_inited(tid_info);
}

/*
 * 功能描述 : netbuf是否采用ring tx模式
 * 1.日    期 : 2020年4月13日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
oal_bool_enum_uint8 dpe_is_ring_tx(uint8_t vapid, oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctl)
{
    oal_bool_enum_uint8 need_ring_tx = OAL_TRUE;
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vapid);
    if (dpe_vap == NULL) {
        return OAL_FALSE;
    }
    if (dpe_ring_tx_enabled() != OAL_TRUE) {
        return OAL_FALSE;
    }

    if (!hmac_tid_ring_tx_allowed(tx_ctl)) {
        return OAL_FALSE;
    }

    if (dpe_vap->en_vap_mode != WLAN_VAP_MODE_BSS_STA) {
        /* AP模式的单播帧支持ring tx, 组播帧不支持ring tx; STA模式没有组播帧 */
        need_ring_tx = (mac_get_cb_is_mcast(tx_ctl) == OAL_FALSE ||
            dpe_vap->bit_support_mcast_ampdu == OAL_TRUE);
    }

    return (mac_get_cb_wme_tid_type(tx_ctl) != WLAN_TIDNO_BCAST) && need_ring_tx;
}
/*
 * 功能描述 : 入ring成功, 更新tid级别统计信息
 * 1.日    期 : 2020年6月11日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
static inline void hmac_tx_update_statistics(hmac_msdu_info_ring_stru *tx_msdu_ring, uint32_t msdu_cnt)
{
    dpe_wlan_tx_stat_stru *dpe_tx_stat = dpe_wlan_tx_stat_get();
    dpe_tx_stat->tx_host_push_ring_cnt += msdu_cnt;

    oal_atomic_add(&tx_msdu_ring->msdu_cnt, msdu_cnt);
    oal_atomic_add(&g_tid_sche_ring_mpdu_num, msdu_cnt);

    oal_atomic_add(&tx_msdu_ring->last_period_tx_msdu, msdu_cnt);
    tx_msdu_ring->tx_msdu_cnt += msdu_cnt;
}

/*
 * 功能描述 : 通过ring发送数据帧
 * 1.日    期 : 2020年2月17日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
uint32_t hmac_host_ring_tx(dpe_wlan_vap_stru *dpe_vap, dpe_wlan_user_stru *dpe_user, oal_netbuf_stru *netbuf)
{
    oal_netbuf_stru *next_buf = NULL;
    hmac_msdu_info_ring_stru *tx_ring = NULL;
    mac_tx_ctl_stru *tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    hmac_tid_info_stru *tid_info = dpe_get_tx_tid_info(dpe_user->us_assoc_id, mac_get_cb_wme_tid_type(tx_ctl));
    uint32_t msdu_cnt = 0;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_uint lock_flag;
#endif
    if (tid_info == NULL) {
        return OAL_FAIL;
    }

    tx_ring = &tid_info->tx_ring;
    dpe_tid_tx_lock_irq_save(&tx_ring->tx_lock, &lock_flag);

    if (oal_atomic_read(&tid_info->ring_tx_mode) != HOST_RING_TX_MODE) {
        dpe_tid_tx_unlock_irq_restore(&tx_ring->tx_lock, &lock_flag);
        oam_warning_log3(0, OAM_SF_DPA, "{hmac_host_ring_tx::usr[%d] tid[%d] mode[%d]}",
            tid_info->user_index, tid_info->tid_no, oal_atomic_read(&tid_info->ring_tx_mode));
        return OAL_FAIL;
    }

    if (!hmac_tx_ring_alloced(tx_ring) && hmac_alloc_tx_ring_after_inited(tid_info, tx_ring) != OAL_SUCC) {
        dpe_tid_tx_unlock_irq_restore(&tx_ring->tx_lock, &lock_flag);
        return OAL_FAIL;
    }
    /* DPA场景user add申请ring但不配置tx ring table，来包时配置tx ring table
       非DPA场景在来包时申请ring且配置tx ring table */
    if (tid_info->is_write_tx_ring_table == OAL_FALSE) {
        hmac_tx_reg_write_ring_info(tid_info, TID_CMDID_CREATE, OAL_FALSE);
    }

    if (dpe_tx_ring_switch_enabled() == OAL_TRUE) {
        hmac_tid_ring_switch_list_enqueue(tid_info);
    }

    while (netbuf != NULL) {
        next_buf = oal_netbuf_next(netbuf);
        if (hmac_tx_ring_push_msdu(dpe_vap, tx_ring, netbuf) != OAL_SUCC) {
            /*
             * 1. 流量高时一次性处理大量netbuf, 可能会使tx ring table写指针更新不及时, 导致MAC无帧可发但软件ring满的情况
             * 此时需要强制更新一次写指针, 加速MAC消耗ring中数据帧, 提升发送效率, 降低入ring失败带来的无效MIPS开销
             * 2. 此处返回fail一定是netbuf未进行dma map或已unmap的情况, 可直接释放
             *
             */
            hal_host_tx_update_msdu_ring(&tx_ring->ring_buf, tx_ring->base_ring_info.write_index);
            hmac_tx_reg_write_ring_info(tid_info, TID_CMDID_ENQUE, OAL_FALSE);
            oam_error_log0(0, OAM_SF_DPA, "{hmac_host_ring_tx::tx ring push fail}");
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
            hal_host_tx_unmap_netbuf_list(netbuf);
#endif
            hmac_free_netbuf_list(netbuf);
            break;
        }
        msdu_cnt++;
        netbuf = next_buf;
    }
    hmac_tx_update_statistics(tx_ring, msdu_cnt);
    hmac_host_ring_tx_suspend(dpe_vap, dpe_user, tid_info);

    dpe_tid_tx_unlock_irq_restore(&tx_ring->tx_lock, &lock_flag);
    return OAL_SUCC;
}

uint32_t hmac_host_tx_tid_enqueue(hmac_tid_info_stru *tid_info, oal_netbuf_stru *netbuf)
{
    oal_netbuf_stru *next_buf = NULL;
    mac_tx_ctl_stru *tx_ctl = NULL;
    oal_netbuf_head_stru netbuf_list;
    oal_uint lock_flag;
    dpe_wlan_tx_stat_stru *dpe_tx_stat = dpe_wlan_tx_stat_get();

    if (!hmac_tid_info_inited(tid_info)) {
        oam_warning_log1(0, OAM_SF_DPA, "{hmac_host_tx_tid_enqueue::tid[%d] not inited}", tid_info->tid_no);
        return OAL_FAIL;
    }

#ifdef _PRE_WLAN_FEATURE_TID_DEPTH_CTRL
    if (hmac_tid_check_queue_overflow() == OAL_TRUE) {
        return OAL_FAIL;
    }
#endif

    /* netbuf建链 */
    oal_netbuf_list_head_init_nolock(&netbuf_list);
    while (netbuf != NULL) {
        next_buf = oal_netbuf_next(netbuf);
        tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
        dpe_wlan_stat_all_tx_netbuf(tx_ctl, netbuf); /* 发包统计 */
        #ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
            dpe_wlan_tx_delay_notify(netbuf, TX_DELAY_GSO);
        #else
            dpe_wlan_tx_delay_notify(netbuf, TX_DELAY_ACPU);
        #endif
        mac_get_cb_retried_num(tx_ctl)++;
        oal_netbuf_list_tail_nolock(&netbuf_list, netbuf);
        netbuf = next_buf;
        dpe_tx_stat->tx_tid_enq++;
    }

#ifdef _PRE_WLAN_FEATURE_TID_DEPTH_CTRL
    hmac_tid_queue_depth_increase(oal_netbuf_list_len(&netbuf_list));
#endif
#ifdef _PRE_WLAN_FEATURE_TX_STAT
    tid_info->tx_stat.enqueue_msdu_cnt += oal_netbuf_list_len(&netbuf_list);
#endif

    /* netbuf链表入队 */
    dpe_tid_queue_lock_irq_save(&tid_info->tid_queue_lock, &lock_flag);
    oal_netbuf_queue_splice_tail_init(&netbuf_list, &tid_info->tid_queue);
    dpe_tid_queue_unlock_irq_restore(&tid_info->tid_queue_lock, &lock_flag);

    if ((hmac_tid_sche_allowed(tid_info) == OAL_TRUE) && oal_likely(!hmac_tx_ring_switching(tid_info))) {
        hmac_tid_schedule();
    }

    return OAL_SUCC;
}

uint32_t hmac_host_tx_without_thread(uint8_t vap_idx, uint16_t user_idx, oal_netbuf_stru *netbuf)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_idx);
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);
    uint32_t ret = OAL_SUCC;
    if (dpe_vap == NULL || dpe_user == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{hmac_host_tx_data::dpe_vap or dpe_user NULL}");
        return OAL_FAIL;
    }

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* 入ring前进行map操作，后续不再进行 */
    if (hal_host_ring_tx_single_map(netbuf) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_host_ring_tx_single_map::fail}");
        return OAL_FAIL;
    }
#endif
    hal_pm_try_wakeup_forbid_sleep(HAL_PM_FORBIDE_SLEEP_HOST_RING_TX);
    if (hal_pm_try_wakeup_dev_lock() != OAL_SUCC) {
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_HOST_RING_TX);
        return OAL_FAIL;
    }
    ret = hmac_host_ring_tx(dpe_vap, dpe_user, netbuf);
    hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_HOST_RING_TX);
    return ret;
}

uint32_t hmac_host_tx_data(uint8_t vap_idx, uint16_t user_idx, oal_netbuf_stru *netbuf)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    hmac_tid_info_stru *tid_info = NULL;
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_net_device_stru *dev = NULL;
    oal_netbuf_stru *next_buf = NULL;
    /* host -> gso, 入参是skb list, 接口不支持链式传输 */
    if (dpe_is_support_dpe_offload() == OAL_TRUE) {
        dev = dpe_vap_get_net_device(vap_idx);
        if (dev == NULL) {
            return OAL_FAIL;
        }
        while (netbuf != NULL) {
            next_buf = oal_netbuf_next(netbuf);
            oal_netbuf_next(netbuf) = NULL;
            oal_netbuf_prev(netbuf) = NULL;
            netbuf->dev = dev;

            tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
            if (mac_get_cb_data_type(tx_ctl) != DATA_TYPE_80211) {
                /* 802.3 offload */
                hmac_dpa_sms_tx_ops(netbuf, tx_ctl, OAL_TRUE, OAL_FALSE);
            } else {
                /* 802.11透传: 802.11帧已做过csum及linearize */
                hmac_dpa_sms_tx_ops(netbuf, tx_ctl, OAL_FALSE, OAL_FALSE);
            }

            netbuf = next_buf;
        }
        return OAL_SUCC;
    }
#endif

    /* gso -> dpe */
    if (oal_likely(HMAC_TX_SCHED_THREAD_ENABLED())) {
        tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
        tid_info = dpe_get_tx_tid_info(user_idx, mac_get_cb_wme_tid_type(tx_ctl));
        if (tid_info == NULL) {
            oam_error_log0(0, OAM_SF_DPA, "{hmac_host_tx_data::tid_info NULL}");
            return OAL_FAIL;
        }
        return hmac_host_tx_tid_enqueue(tid_info, netbuf);
    } else {
        return hmac_host_tx_without_thread(vap_idx, user_idx, netbuf);
    }
}

/*
 * 函 数 名  : dpe_tx_get_user_id
 * 功能描述  : tx方向获取dpe user id
 * 日    期  : 2025年02月14日
 */
uint16_t dpe_tx_get_user_id(dpe_wlan_vap_stru *dpe_vap, mac_ether_header_stru *ether_hdr)
{
    uint16_t user_idx = g_wlan_spec_cfg->invalid_user_id;
    uint8_t *addr = NULL;                     /* 目的地址 */
    uint32_t ret;

    if (dpe_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    if (dpe_vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA) {
        return dpe_vap->us_assoc_vap_id;
    }

    if (dpe_vap->en_vap_mode == WLAN_VAP_MODE_BSS_AP) {
        if (ether_hdr == NULL) {
            oam_error_log0(dpe_vap->uc_vap_id, OAM_SF_DPA, "{dpe_tx_get_user_id::ether_hdr null}");
            return g_wlan_spec_cfg->invalid_user_id;
        }
        /* 判断是组播或单播,对于lan to wlan的单播帧，返回以太网地址 */
        addr = ether_hdr->auc_ether_dhost;
        /* 单播数据帧 */
        if (oal_likely(!ether_is_multicast(addr))) {
            ret = dpe_vap_find_user_by_macaddr(dpe_vap->uc_vap_id, addr, &user_idx);
            if (oal_unlikely(ret != OAL_SUCC)) {
                oam_warning_log3(dpe_vap->uc_vap_id, OAM_SF_DPA, "{dpe_tx_get_user_id::dpe_tx_find_user failed \
                    %02X:XX:XX:XX:%02X:%02X}", addr[MAC_ADDR_0], addr[MAC_ADDR_4], addr[MAC_ADDR_5]);
                return g_wlan_spec_cfg->invalid_user_id;
            }
        } else { /* 组播 or 广播 */
            user_idx = dpe_vap->us_multi_user_idx;
        }
    }

    return user_idx;
}
