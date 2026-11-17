/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : Host发送(Ring模式)模块
 * 作    者 : wifi
 * 创建日期 : 2020年4月23日
 */

#include "hmac_host_tx_data.h"
#include "hmac_tx_msdu_dscr.h"
#include "hmac_host_ring_tx.h"
#include "hmac_tx_ring_alloc.h"
#include "hmac_tid_sche.h"
#include "hmac_tid_update.h"
#include "hmac_tx_data.h"
#include "hmac_tx_switch.h"
#include "hmac_sync_dpe.h"
#include "mac_data.h"
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
#include "hmac_tcp_ack_buf.h"
#endif
#include "hmac_stat.h"
#include "hmac_wapi.h"
#include "hmac_tid_ring_switch.h"
#include "host_hal_ext_if.h"
#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_chba_ps.h"
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
#include "hmac_pwl.h"
#endif
#include "host_hal_dma.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_HOST_TX_DATA_C

/*
 * 功能描述 : host发送MPDU报文,netbuf内容调整
 * 1.日    期 : 2020.5.16
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC void hmac_host_tx_mpdu_netbuf_move(oal_netbuf_stru *netbuf)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    mac_ieee80211_frame_stru *mac_header = NULL;
    uint32_t mac_hdr_len;
    int32_t ret;

    while (netbuf != NULL) {
        tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
        mac_hdr_len = mac_get_cb_frame_header_length(tx_ctl);
        /* MAC header和snap头部分存在空洞，需要调整mac header内容位置 */
        ret = memmove_s(oal_netbuf_data(netbuf) - mac_hdr_len, mac_hdr_len,
            (uint8_t *)(uintptr_t)mac_get_cb_frame_header_addr(tx_ctl), mac_hdr_len);
        if (oal_unlikely(ret != EOK)) {
            oam_error_log0(0, 0, "hmac_host_tx_mpdu_netbuf_adjust:memmove fail");
        }
        oal_netbuf_push(netbuf, mac_hdr_len);
        /* 记录新的MAC头的位置 */
        mac_get_cb_frame_header_addr(tx_ctl) = (uint64_t)(uintptr_t)oal_netbuf_data(netbuf);
        if (mac_get_cb_data_type(tx_ctl) == DATA_TYPE_80211) {
            mac_header = (mac_ieee80211_frame_stru *)oal_netbuf_data(netbuf);
            tx_ctl->st_expand_cb.bit_more_frag = mac_header->st_frame_control.bit_more_frag;
            tx_ctl->st_expand_cb.bit_frag_num = mac_header->bit_frag_num;
        }
        /* 分片场景存在多个netbuf */
        netbuf = oal_netbuf_next(netbuf);
    }
}

OAL_STATIC oal_bool_enum_uint8 hmac_host_tx_need_transfer_to_80211(hmac_vap_stru *hmac_vap,
    hmac_user_stru *hmac_user, oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctl)
{
    /* host_tx需要封装为802.11格式条件：
     * 1. 分片报文
     * 2. 芯片不支持WAPI硬件加解密 && WAPI关联场景
     * host tx模式下分片/WAPI 时需要软件封装802.11帧头, 其余情况硬件会进行封装
     * 也可通过设置msdu info中的data type = 3进行软件封装, 详见Host描述符文档
     */
    if (hmac_tx_need_frag(hmac_vap, hmac_user, netbuf, tx_ctl) != 0) {
        return OAL_TRUE;
    }
#ifdef _PRE_WLAN_FEATURE_WAPI
    if ((wlan_chip_is_support_hw_wapi() == OAL_FALSE) && (wapi_port_flag(&hmac_user->st_wapi) == OAL_TRUE)) {
        return OAL_TRUE;
    }
#endif
    return OAL_FALSE;
}

static inline oal_bool_enum_uint8 hmac_host_tx_need_ba_session(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    mac_tx_ctl_stru *tx_ctl, oal_netbuf_stru *netbuf)
{
    /* 组播转单播不触发建BA会话 */
    if ((tx_ctl->bit_is_m2u_data == OAL_FALSE) &&
        (hmac_tid_need_ba_session(hmac_vap, hmac_user, mac_get_cb_wme_tid_type(tx_ctl)) == OAL_TRUE)) {
        return OAL_TRUE;
    }
    return OAL_FALSE;
}

/*
 * 功能描述 : host tx预处理, 包括帧过滤、业务识别、BA会话建立、分片报文802.11头封装等
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC uint32_t hmac_host_tx_preprocess(
    hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, oal_netbuf_stru **origin_netbuf)
{
    oal_netbuf_stru *netbuf = *origin_netbuf;
    mac_tx_ctl_stru *tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);

    if (hmac_tx_filter_security(hmac_vap, netbuf, hmac_user) != OAL_SUCC) {
        return HMAC_TX_DROP_SECURITY_FILTER;
    }

    hmac_ring_tx_update_tid(tx_ctl);

    if (hmac_host_tx_need_ba_session(hmac_vap, hmac_user, tx_ctl, netbuf) == OAL_TRUE) {
        hmac_tx_ba_setup(hmac_vap, hmac_user, mac_get_cb_wme_tid_type(tx_ctl));
    }

#ifdef _PRE_WLAN_CHBA_MGMT
    hmac_chba_sync_user_bitmap_level_by_data_type(hmac_vap, hmac_user, tx_ctl);
#endif

    if (hmac_host_tx_need_transfer_to_80211(hmac_vap, hmac_user, netbuf, tx_ctl) == OAL_FALSE) {
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
        if (hmac_tx_tcp_ack_buf_process(hmac_vap, hmac_user, netbuf) == HMAC_TX_BUFF) {
            return HMAC_TX_BUFF;
        }
#endif
        return HMAC_TX_PASS;
    }

#ifndef _PRE_WINDOWS_SUPPORT
    /* csum硬化仅802.3帧，ring发送802.11场景由驱动计算CSUM值 */
    dpe_tx_set_netbuf_checksum(netbuf);
#endif

    /* 分片报文由软件组MAC头 */
    if (hmac_tx_encap_ieee80211_header(hmac_vap, hmac_user, netbuf) != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_TX, "{hmac_host_tx_preprocess_sta::hmac_tx_encap_ieee80211_header failed}");
        return HMAC_TX_DROP_80211_ENCAP_FAIL;
    }

    hmac_host_tx_mpdu_netbuf_move(netbuf);

    /* WAPI host_tx 加密处理 */
#ifdef _PRE_WLAN_FEATURE_WAPI
    *origin_netbuf = hmac_wapi_netbuf_tx_encrypt_mp16(hmac_vap, hmac_user, netbuf);
    if (*origin_netbuf == NULL) {
        /* WAPI加密失败，netbuf在此处释放并返回TX_DONE, 不需要外部释放 */
        hmac_free_netbuf_list(netbuf);
        oam_warning_log0(0, 0, "{hmac_host_tx_preprocess_sta::hmac_wapi_netbuff_tx_handle_sta failed}");
        return HMAC_TX_DONE;
    }

    /* 如果*origin_netbuf和netbuf指针不相同则说明做过加密, 释放掉旧的netbuf */
    if (*origin_netbuf != netbuf) {
        hmac_free_netbuf_list(netbuf);
    }
#endif /* _PRE_WLAN_FEATURE_WAPI */

    return HMAC_TX_PASS;
}

/*
 * 功能描述 : 判断是否允许进行host tx
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE uint32_t hmac_host_tx_netbuf_allowed(mac_vap_stru *mac_vap, hmac_vap_stru *hmac_vap)
{
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (mac_vap->en_vap_mode != WLAN_VAP_MODE_BSS_AP && mac_vap->en_vap_mode != WLAN_VAP_MODE_BSS_STA) {
        return OAL_ERR_CODE_CONFIG_UNSUPPORT;
    }

    if (mac_vap->us_user_nums == 0) {
        return OAL_FAIL;
    }

    return OAL_SUCC;
}


/*
 * 功能描述  : 设置msdu csum硬化信息
 * 1.日    期 : 2020.5.13
 *   作    者 : wifi
 *   修改内容: 新生成函数
 */
void hmac_tx_get_msdu_csum_info(oal_netbuf_stru *netbuf)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    mac_tx_ctl_stru *tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    mac_ether_header_stru *ether_header = (mac_ether_header_stru *)oal_netbuf_data(netbuf);
    uint8_t *ip_dhr = (uint8_t *)(netbuf->head + netbuf->network_header);
    if (tx_ctl == NULL || ether_header == NULL || ip_dhr == NULL) {
        oam_warning_log0(0, OAM_SF_TX, "{hmac_tx_get_msdu_csum_info:: null}");
        return;
    }
    tx_ctl->st_expand_cb.csum_type = 0;

    if (ether_header->us_ether_type == oal_host2net_short(ETHER_TYPE_IP)) {
        struct iphdr *iph = (struct iphdr *)ip_dhr;
        if (iph->protocol == OAL_IPPROTO_TCP) {
            tx_ctl->st_expand_cb.csum_type = CSUM_TYPE_IPV4_TCP;
        } else if (iph->protocol == OAL_IPPROTO_UDP) {
            tx_ctl->st_expand_cb.csum_type = CSUM_TYPE_IPV4_UDP;
        }
    } else if (ether_header->us_ether_type == oal_host2net_short(ETHER_TYPE_IPV6)) {
        struct ipv6hdr *ipv6h = (struct ipv6hdr *)ip_dhr;
        if (ipv6h->nexthdr == OAL_IPPROTO_TCP) {
            tx_ctl->st_expand_cb.csum_type = CSUM_TYPE_IPV6_TCP;
        } else if (ipv6h->nexthdr == OAL_IPPROTO_UDP) {
            tx_ctl->st_expand_cb.csum_type = CSUM_TYPE_IPV6_UDP;
        }
    }
#endif
}

/*
 * 功能描述 : 保证netbuf headroom有足够的空间供硬件填写MSDU描述符
 * 1.日    期 : 2020年4月22日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
static uint32_t hmac_tx_netbuf_expand_headroom(oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctl)
{
    int32_t ret;
    uint8_t mac_hdr[MAX_MAC_HEAD_LEN];
    if (oal_unlikely(netbuf == NULL)) {
        return OAL_FAIL;
    }

    if (oal_netbuf_headroom(netbuf) > hal_host_tx_get_msdu_dscr_len()) {
        return OAL_SUCC;
    }

    oam_warning_log1(0, OAM_SF_TX, "{hmac_tx_netbuf_expand_headroom::headroom %d not enough}",
        oal_netbuf_headroom(netbuf));

    if (memcpy_s(mac_hdr, MAX_MAC_HEAD_LEN, (uint8_t *)oal_netbuf_data(netbuf), MAX_MAC_HEAD_LEN) != EOK) {
        return OAL_FAIL;
    }
    /* skb本身不会释放, 因此还在skb list中,不会断链 */
    ret = oal_netbuf_expand_head(netbuf, hal_host_tx_get_msdu_dscr_len(), 0, GFP_ATOMIC);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_tx_netbuf_expand_headroom::expand headroom failed}");
        return OAL_ERR_CODE_ALLOC_MEM_FAIL;
    }

    if (memcpy_s(oal_netbuf_data(netbuf), MAX_MAC_HEAD_LEN, mac_hdr, MAX_MAC_HEAD_LEN) != EOK) {
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

/* 对netbuf payload的访问提前到hmac */
OAL_STATIC uint32_t hmac_host_tx_data_netbuf_payload_proc(oal_netbuf_stru *netbuf)
{
    mac_tx_ctl_stru *tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (oal_unlikely(tx_ctl == NULL)) {
        return OAL_FAIL;
    }
    if (oal_unlikely(hal_host_tx_clear_msdu_padding(netbuf) != OAL_SUCC)) {
        oam_error_log0(0, OAM_SF_TX, "hal_host_tx_clear_msdu_padding fail");
        return OAL_FAIL;
    }

    if (oal_unlikely(hmac_tx_netbuf_expand_headroom(netbuf, tx_ctl) != OAL_SUCC)) {
        oam_error_log0(0, OAM_SF_TX, "hmac_tx_netbuf_expand_headroom fail");
        return OAL_FAIL;
    }

    /* 通过gso发送的包由gso替wifi清空msdu info */
    if ((hmac_is_support_dpe_offload() == OAL_FALSE)) {
        hal_host_tx_netbuf_init_msdu_dscr(netbuf, OAL_TRUE);
    }
    return OAL_SUCC;
}

uint32_t hmac_host_tx_data_proc(uint8_t vap_idx, uint16_t user_idx, oal_netbuf_stru *netbuf)
{
    oal_netbuf_stru *next_buf = NULL;
    oal_netbuf_stru *temp_buf = netbuf;
    
    while (temp_buf != NULL) {
        next_buf = oal_netbuf_next(temp_buf);
        /* 访问netbuf payload提前：1.非dpa流程防止host dma map后访问 2.防止dpa异步访问 */
        if (oal_unlikely(hmac_host_tx_data_netbuf_payload_proc(temp_buf) != OAL_SUCC)) {
            return OAL_FAIL;
        }
        temp_buf = next_buf;
    }
    
    return hmac_host_tx_data(vap_idx, user_idx, netbuf);
}

/*
 * 功能描述 : host tx主入口
 * 1.日    期 : 2020年4月13日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
uint32_t hmac_ring_tx(hmac_vap_stru *hmac_vap, oal_netbuf_stru **netbuf, mac_tx_ctl_stru *tx_ctl)
{
    hmac_user_stru *hmac_user = NULL;
    mac_vap_stru *mac_vap = &hmac_vap->st_vap_base_info;
    uint32_t ret = hmac_host_tx_netbuf_allowed(mac_vap, hmac_vap);
    if (ret != OAL_SUCC) {
        return ret;
    }

#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU_DEBUG
    if (mac_get_cb_is_mcast(tx_ctl) == OAL_TRUE) {
        oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, 0,
            "MCAST_AMPDU::hmac_ring_tx num[%u]", mac_get_cb_alg_pktno(tx_ctl));
    }
#endif

    /* csum上层填写在skb cb里, 后续流程根据该字段填写 */
    hmac_ether_set_data_type(tx_ctl, *netbuf);
    hmac_tx_get_msdu_csum_info(*netbuf);

    hmac_user = mac_res_get_hmac_user(mac_get_cb_tx_user_idx(tx_ctl));
    if (oal_unlikely(hmac_user == NULL)) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_TX, "{hmac_host_tx::hmac_user is null.}");
        return OAL_FAIL;
    }
    switch (hmac_host_tx_preprocess(hmac_vap, hmac_user, netbuf)) {
        case HMAC_TX_PASS:
            return hmac_host_tx_data_proc(hmac_vap->st_vap_base_info.uc_vap_id,
                hmac_user->st_user_base_info.us_assoc_id, *netbuf);
        case HMAC_TX_BUFF:
        case HMAC_TX_DONE:
            return OAL_SUCC;
        default:
            return OAL_FAIL;
    }
}

uint32_t hmac_tx_mode_switch(mac_vap_stru *mac_vap, uint32_t *params)
{
    return hmac_tx_mode_switch_sync(mac_vap->uc_vap_id, params);
}