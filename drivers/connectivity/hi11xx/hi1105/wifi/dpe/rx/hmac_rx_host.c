/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_rx_host.c文件
 * 创建日期 : 2020年09月22日
 */

/* 1 头文件包含 */
#include "hmac_rx_host.h"
#include "hmac_rx.h"
#include "mac_data.h"
#include "mac_frame_if.h"
#include "hmac_rx_reorder.h"
#include "host_hal_ext_if.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "hmac_ota_report.h"
#include "oam_event_wifi.h"
#endif
#include "hmac_host_performance.h"
#include "dpe_wlan_stat.h"
#include "dpe_wlan_resource.h"
#include "dpe_tx_data.h"
#ifdef _PRE_WLAN_FEATURE_SNIFFER
#include "hmac_sniffer.h"
#endif
#ifdef _PRE_WLAN_FEATURE_VSP
#include "hmac_vsp_if.h"
#endif
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "pcie_linux.h"
#else
#include "pcie_host.h"
#endif
#include "host_hal_dma.h"
#include "dpe_wlan_debug.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_RX_HOST_C

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
void hal_host_rx_proc_msdu_dscr(oal_netbuf_stru *netbuf)
{
    if (oam_ota_get_switch(OAM_OTA_SWITCH_RX_MSDU_DSCR) == OAL_SWITCH_OFF) {
        return;
    }
    while (netbuf != NULL) {
        oam_report_dscr(BROADCAST_MACADDR, (uint8_t *)dpe_get_rx_netbuf_hdr_addr(netbuf),
            hal_host_get_rx_msdu_dscr_len(), OAM_OTA_TYPE_RX_MSDU_DSCR);
        netbuf = oal_netbuf_next(netbuf);
    }
}
void hmac_rx_netbuf_update_rxctl_data_type(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl)
{
    mac_data_type_enum_uint8 datatype = MAC_DATA_NUM;
    uint16_t frame_format = rx_ctl->bit_frame_format;
    uint32_t frame_len = rx_ctl->us_frame_len;
    uint8_t eth_type = MAC_NETBUFF_PAYLOAD_BUTT;

    if (frame_format == MAC_FRAME_TYPE_80211) {
        datatype = mac_get_data_type_from_80211(netbuf, mac_get_rx_cb_mac_header_len(rx_ctl),
            mac_get_rx_cb_frame_len(rx_ctl) - mac_get_rx_cb_mac_header_len(rx_ctl));
    } else if (frame_format == MAC_FRAME_TYPE_8023) {
        /* 跳过DA/SA/length 14字节 */
        datatype = mac_get_data_type_from_8023(netbuf, (uint8_t *)(dpe_get_rx_netbuf_hdr_addr(netbuf) + ETHER_HDR_LEN),
            MAC_FRAME_TYPE_8023, frame_len - ETHER_HDR_LEN, OAM_OTA_FRAME_DIRECTION_TYPE_RX);
    } else if (frame_format == MAC_FRAME_TYPE_RTH) {
        eth_type = mac_get_eth_data_subtype(netbuf, frame_len);
        if (eth_type == MAC_FRAME_TYPE_8023) { // MAC_NETBUFF_PAYLOAD_SNAP is equal MAC_FRAME_TYPE_8023
            /* 跳过DA/SA/length 14字节 */
            datatype = mac_get_data_type_from_8023(netbuf,
                (uint8_t *)(dpe_get_rx_netbuf_hdr_addr(netbuf) + ETHER_HDR_LEN),
                MAC_FRAME_TYPE_8023, frame_len - ETHER_HDR_LEN, OAM_OTA_FRAME_DIRECTION_TYPE_RX);
        } else {
            datatype = mac_get_data_type_from_8023(netbuf,
                (uint8_t *)dpe_get_rx_netbuf_hdr_addr(netbuf), MAC_FRAME_TYPE_RTH,
                frame_len, OAM_OTA_FRAME_DIRECTION_TYPE_RX);
        }
    } else {
        oam_warning_log1(0, OAM_SF_DPA, "hmac_rx_netbuf_update_rxctl_data_type:frame format[%d]", frame_format);
    }

    rx_ctl->bit_data_type  = datatype;
}
#endif

/* 功能描述 : 检查上报帧的vap是否有效 */
OAL_STATIC uint32_t hmac_is_hal_vap_valid(hal_host_device_stru *hal_device, mac_rx_ctl_stru *rx_ctl)
{
    uint8_t   hal_vap_id;

    if (mac_rxcb_is_amsdu_sub_msdu(rx_ctl)) {
        return OAL_SUCC;
    }

    hal_vap_id = mac_get_rx_cb_hal_vap_id(rx_ctl);
    if (oal_unlikely(hal_vap_id >= dpe_mac_chip_get_hal_max_vap_num()) &&
        (hal_vap_id != g_wlan_spec_cfg->other_bss_id)) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_is_hal_vap_valid::invalid hal vap id[%d].}", hal_vap_id);
        return OAL_FAIL;
    }

    if ((hal_vap_id < dpe_mac_chip_get_hal_max_vap_num()) &&
        (!hal_device->hal_vap_sts_info[hal_vap_id].hal_vap_valid)) {
        oam_warning_log2(0, OAM_SF_DPA, "{hmac_is_hal_vap_valid::haldev[%d] invalid hal vap[%d]. }",
            hal_device->device_id, hal_vap_id);
        return OAL_FAIL;
    }

    return OAL_SUCC;
}
/* 功能描述 : 检查上报帧的tid是否有效 */
OAL_STATIC uint32_t hmac_is_tid_valid(hal_host_device_stru *hal_device, mac_rx_ctl_stru *rx_ctl)
{
    uint8_t frame_type;

    if (mac_rxcb_is_amsdu_sub_msdu(rx_ctl)) {
        return OAL_SUCC;
    }

    /* 判断该帧是不是qos帧 */
    frame_type = mac_get_frame_type_and_subtype((uint8_t *)&rx_ctl->us_frame_control);
    if (frame_type != (WLAN_FC0_SUBTYPE_QOS | WLAN_FC0_TYPE_DATA)) {
        return OAL_SUCC;
    }

    if (!mac_tid_is_valid(mac_get_rx_cb_tid(rx_ctl))) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_is_tid_valid::invalid tid[%d].}", mac_get_rx_cb_tid(rx_ctl));
        return OAL_FAIL;
    }
    return OAL_SUCC;
}
OAL_STATIC void hmac_alrx_process(hal_host_device_stru *hal_device, mac_rx_ctl_stru *rx_ctl)
{
    if (rx_ctl == NULL || hal_device == NULL) {
        return;
    } else if (rx_ctl->rx_status != HAL_RX_SUCCESS) {
        hal_device->st_alrx.rx_ppdu_fail_num++;
    } else if (rx_ctl->bit_is_ampdu == OAL_TRUE) {
        hal_device->st_alrx.rx_ampdu_succ_num++;
    } else {
        hal_device->st_alrx.rx_normal_mdpu_succ_num++;
    }
    return;
}

/* Rxcb中amsdu非首帧的信息填充 */
OAL_STATIC void hmac_rx_update_submsdu_rxctl(mac_rx_ctl_stru *dst_rxcb,
    mac_rx_ctl_stru *src_rxcb, oal_netbuf_stru *netbuf)
{
    mac_get_rx_cb_tid(dst_rxcb) = mac_get_rx_cb_tid(src_rxcb);
    mac_get_rx_cb_hal_vap_id(dst_rxcb) = mac_get_rx_cb_hal_vap_id(src_rxcb);
    mac_rxcb_is_amsdu(dst_rxcb) = mac_rxcb_is_amsdu(src_rxcb);
    mac_get_rx_cb_is_first_sub_msdu(dst_rxcb) = OAL_FALSE;
    mac_get_rx_cb_ta_user_id(dst_rxcb) = mac_get_rx_cb_ta_user_id(src_rxcb);
    dst_rxcb->bit_rx_user_id = src_rxcb->bit_rx_user_id;

    mac_get_rx_cb_mac_vap_id(dst_rxcb) = mac_get_rx_cb_mac_vap_id(src_rxcb);
    mac_get_rx_cb_seq_num(dst_rxcb) = mac_get_rx_cb_seq_num(src_rxcb);
    dst_rxcb->us_frame_control = src_rxcb->us_frame_control;
    dst_rxcb->us_rx_msb_pn = src_rxcb->us_rx_msb_pn;
    dst_rxcb->rx_lsb_pn = src_rxcb->rx_lsb_pn;

    /* frame len刷新 当芯片上报802.11格式的AMSDU帧时，且非首个msdu不包含802.11头 */
    if (dst_rxcb->bit_frame_format == MAC_FRAME_TYPE_80211 && mac_rxcb_is_amsdu_sub_msdu(dst_rxcb)) {
        dst_rxcb->us_frame_len += dst_rxcb->uc_mac_header_len;
    }
    dst_rxcb->last_msdu_in_amsdu = (oal_netbuf_next(netbuf) == NULL);
}
OAL_STATIC uint32_t hmac_rx_netbuf_check_status(mac_rx_ctl_stru *cb, oal_netbuf_stru *netbuf)
{
    uint8_t  rx_status = cb->rx_status;
    if (rx_status == HAL_RX_SUCCESS) {
        return OAL_SUCC;
    }

    if (rx_status == HAL_RX_NEW) {
        oam_error_log1(0, OAM_SF_DPA, "hmac_rx_netbuf_check_status::rx_status:[%d]", rx_status);
#ifdef _PRE_WLAN_DFT_DUMP_FRAME
        oam_report_dscr(BROADCAST_MACADDR, (uint8_t *)dpe_get_rx_msdu_dscr_addr(netbuf),
            hal_host_get_rx_msdu_dscr_len(), OAM_OTA_TYPE_RX_MSDU_DSCR);
#endif
    }
    return OAL_FAIL;
}

OAL_STATIC OAL_INLINE void hmac_rx_exception_free_stat(hal_host_device_stru *hal_dev)
{
    hal_dev->rx_statics.rx_exception_free_cnt++;
}
#ifdef _PRE_WLAN_DFT_DUMP_FRAME
/* 功能描述: rx流程强制打印ota */
void hmac_rx_netbuf_force_ota_report(oal_netbuf_stru *netbuf)
{
    mac_rx_ctl_stru *rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (rx_ctl == NULL) {
        return;
    }
    oam_report_netbuf_cb(BROADCAST_MACADDR,
                         (uint8_t *)oal_netbuf_cb(netbuf),
                         sizeof(mac_rx_ctl_stru),
                         OAM_OTA_FRAME_DIRECTION_TYPE_RX);
    if (rx_ctl->bit_frame_format == MAC_FRAME_TYPE_RTH) {
        oam_report_eth_frame(BROADCAST_MACADDR,
                             (uint8_t *)dpe_get_rx_netbuf_hdr_addr(netbuf),
                             rx_ctl->us_frame_len,
                             OAM_OTA_FRAME_DIRECTION_TYPE_RX);
    } else if (rx_ctl->bit_frame_format == MAC_FRAME_TYPE_80211) {
        oam_report_80211_frame(BROADCAST_MACADDR,
                               (uint8_t *)dpe_get_rx_netbuf_hdr_addr(netbuf),
                               rx_ctl->uc_mac_header_len,
                               (uint8_t *)dpe_get_rx_netbuf_hdr_addr(netbuf) + rx_ctl->uc_mac_header_len,
                               rx_ctl->us_frame_len,
                               OAM_OTA_FRAME_DIRECTION_TYPE_RX);
    }
}
#endif

/*
 * 功能描述  : MPDU级别(msdu或者amsdu)的netbuf成链并生成cb
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_host_rx_mpdu_build_cb(hal_host_device_stru *hal_dev, oal_netbuf_stru *netbuf)
{
    dpe_wlan_device_stat_stru *device_stats = dpe_wlan_device_stat_get();
    mac_rx_ctl_stru *rxctl = NULL;
    uint8_t          first_msdu = OAL_TRUE;
    mac_rx_ctl_stru  first_rx_ctl = { 0 };
    oal_netbuf_stru *next = NULL;
    uint32_t rx_packets = 0;

    while (netbuf != NULL) {
        next = oal_netbuf_next(netbuf);
        rxctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);

        rx_packets++;

        /* 更新软件cb信息 */
        if (first_msdu == OAL_TRUE) {
            /*  fcs错误帧提前过滤, 防止帧长错误时候取报文类型读越界 */
            if (hmac_rx_netbuf_check_status(rxctl, netbuf) != OAL_SUCC) {
                hmac_rx_exception_free_stat(hal_dev);
                device_stats->host_ring_rx_packets += rx_packets;
                return OAL_FAIL;
            }
            if (rxctl->bit_vap_id < HAL_MAX_VAP_NUM) {
                rxctl->uc_mac_vap_id = hal_dev->hal_vap_sts_info[rxctl->bit_vap_id].mac_vap_id;
            }
        }

        /* AMSDU专有处理流程 */
        if (mac_rxcb_is_first_msdu(rxctl) == OAL_TRUE) {
            memcpy_s(&first_rx_ctl, sizeof(mac_rx_ctl_stru), rxctl, sizeof(mac_rx_ctl_stru));
            first_msdu = OAL_FALSE;
        } else if (first_msdu == OAL_FALSE) {
            hmac_rx_update_submsdu_rxctl(rxctl, &first_rx_ctl, netbuf);
        }
        /* 标记数据帧来源,host有特殊处理 */
        rxctl->bit_transfer_from_dpa = 0;
        rxctl->bit_transfer_from_task = 0;
        rxctl->bit_tsf_valid = 0;
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
        hmac_rx_netbuf_update_rxctl_data_type(netbuf, rxctl);
#endif
        netbuf = next;
    }
    device_stats->host_ring_rx_packets += rx_packets;
    return OAL_SUCC;
}


/* 过滤A-MSDU首帧DA为AA-AA-03-00-00-00 的异常A-MSDU 帧 */
OAL_STATIC hmac_rx_frame_ctrl_enum hmac_host_rx_filter_abnormal_amsdu(oal_netbuf_stru *netbuf,
    mac_rx_ctl_stru *rx_cb_ctrl)
{
    uint8_t *dst_addr = NULL;
    uint8_t frame_format;
    uint8_t mac_addr_snap_header[WLAN_MAC_ADDR_LEN] = {0xAA, 0xAA, 0x03, 0x00, 0x00, 0x00};

    if (!rx_cb_ctrl->bit_amsdu_enable || !rx_cb_ctrl->bit_is_first_buffer) {
        return HMAC_RX_FRAME_CTRL_GOON;
    }
    frame_format = rx_cb_ctrl->bit_frame_format;
    if (frame_format == MAC_FRAME_TYPE_80211) {
        uint8_t *ieee80211_hdr = (uint8_t *)dpe_get_rx_netbuf_hdr_addr(netbuf);
        /* 80211 格式A-MSDU DA在80211 帧头后 */
        dst_addr = (ieee80211_hdr + rx_cb_ctrl->uc_mac_header_len + MAC_SUBMSDU_DA_OFFSET);
    } else if (frame_format == MAC_FRAME_TYPE_RTH || frame_format == MAC_FRAME_TYPE_8023) {
        mac_ether_header_stru *eth_hdr = (mac_ether_header_stru *)dpe_get_rx_netbuf_hdr_addr(netbuf);
        if (eth_hdr == NULL) {
            return HMAC_RX_FRAME_CTRL_DROP;
        }
        dst_addr = eth_hdr->auc_ether_dhost;
    } else {
        return HMAC_RX_FRAME_CTRL_GOON;
    }

    if (oal_memcmp(dst_addr, mac_addr_snap_header, WLAN_MAC_ADDR_LEN) == 0) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    return HMAC_RX_FRAME_CTRL_GOON;
}

/*
 * 功能描述  : host rx预先过滤流程，主要涉及device rx部分已经设置的过滤
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC hmac_rx_frame_ctrl_enum hmac_host_rx_pre_abnormal_filter(hmac_host_rx_context_stru *rx_context)
{
    hal_host_device_stru    *hal_dev = rx_context->hal_dev;
    oal_netbuf_stru         *netbuf = rx_context->netbuf;
    mac_rx_ctl_stru         *rx_ctl = rx_context->cb;
    dpe_wlan_vap_stru       *dpe_vap = rx_context->dpe_vap;
    dpe_wlan_user_stru      *dpe_user = rx_context->dpe_user;

    if (dpe_vap == NULL) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }
    if (hal_dev->st_alrx.en_al_rx_flag != 0) {
        hmac_alrx_process(hal_dev, rx_ctl);
        return HMAC_RX_FRAME_CTRL_DROP;
    }
#ifdef _PRE_WLAN_FEATURE_SNIFFER
    if (hmac_host_rx_sniffer_is_on(hal_dev) == OAL_TRUE) {
        hmac_host_rx_sniffer_filter_check(hal_dev, netbuf, rx_ctl);
        return HMAC_RX_FRAME_CTRL_DROP;
    }
#endif
    if ((hmac_is_hal_vap_valid(hal_dev, rx_ctl) != OAL_SUCC) ||
        (hmac_is_tid_valid(hal_dev, rx_ctl)) != OAL_SUCC) {
#ifdef _PRE_WLAN_DFT_DUMP_FRAME
        hmac_rx_netbuf_force_ota_report(netbuf);
#endif
        return HMAC_RX_FRAME_CTRL_DROP;
    }
    /* 加密收到非加密的数据帧需要过滤处理,只处理首帧 */
    if (dpe_user == NULL) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    /* 异常AMSDU 帧过滤 */
    if (hmac_host_rx_filter_abnormal_amsdu(netbuf, rx_ctl) == HMAC_RX_FRAME_CTRL_DROP) {
        oam_warning_log0(dpe_vap->uc_vap_id, OAM_SF_DPA,
            "hmac_host_rx_pre_abnormal_filter::msdu da is snap llc header!");
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    return HMAC_RX_FRAME_CTRL_GOON;
}

OAL_STATIC dpe_wlan_user_stru *dpe_wlan_ap_rx_recheck_user_idx(dpe_wlan_vap_stru *dpe_vap,
    oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl)
{
    mac_ieee80211_frame_stru *frmhdr = NULL;
    uint8_t *transmit_addr = NULL;
    dpe_wlan_user_stru *dpe_user = NULL;
    uint8_t usr_lut = rx_ctl->bit_rx_user_id;
    uint16_t user_idx;

    /* lut为无效值且为80211帧时，才进行查找,此为异常保护流程 */
    if ((usr_lut < g_wlan_spec_cfg->invalid_user_id) || (rx_ctl->bit_frame_format != MAC_FRAME_TYPE_80211)) {
        return NULL;
    }
    frmhdr = (mac_ieee80211_frame_stru *)dpe_get_rx_netbuf_hdr_addr(netbuf);
    if (frmhdr == NULL) {
        return NULL;
    }
    transmit_addr = frmhdr->auc_address2;
    if (dpe_vap_find_user_by_macaddr(dpe_vap->uc_vap_id, transmit_addr, &user_idx) == OAL_SUCC) {
        dpe_user = dpe_wlan_user_get(user_idx);
    }
    return dpe_user;
}

OAL_STATIC OAL_INLINE dpe_wlan_user_stru *dpe_wlan_host_rx_lut_get_user(dpe_wlan_vap_stru *dpe_vap,
    oal_netbuf_stru *netbuf, hal_host_device_stru *hal_dev, mac_rx_ctl_stru *cb)
{
    dpe_wlan_user_stru *dpe_user = NULL;
    uint8_t usr_lut = cb->bit_rx_user_id;
    hal_host_chip_stru *hal_chip = hal_get_host_chip();

    if ((usr_lut < HAL_MAX_LUT) && (hal_chip->user_sts_info[usr_lut].user_valid)) {
        dpe_user = dpe_wlan_user_get(hal_chip->user_sts_info[usr_lut].user_id);
    }
    if (oal_unlikely(dpe_user == NULL) &&
       !mac_rx_dscr_need_drop(cb->rx_status) && (hal_dev->st_alrx.en_al_rx_flag == HAL_ALWAYS_RX_DISABLE)) {
        oam_warning_log1(hal_dev->device_id, OAM_SF_DPA,
            "dpe_wlan_host_rx_lut_get_user:get user fail, lut idx[%d]", usr_lut);
        /* 漫游过程中接收到数据帧信息输出 */
        if (dpe_vap->en_vap_state == MAC_VAP_STATE_ROAMING) {
#ifdef _PRE_WLAN_DFT_DUMP_FRAME
            hmac_rx_report_eth_frame(dpe_vap->uc_vap_id, netbuf);
#endif
        }
    }
    return dpe_user;
}

/*
 * 功能描述  : 将cb中的user id统一更新为mac user id
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE void hmac_host_rx_update_cb_user_idx(dpe_wlan_user_stru *dpe_user, oal_netbuf_stru *netbuf)
{
    mac_rx_ctl_stru *rx_ctl = NULL;
    uint16_t user_idx;

    if (dpe_user == NULL) {
        return;
    }

    user_idx = dpe_user->us_assoc_id;

    for (; netbuf; netbuf = oal_netbuf_next(netbuf)) {
        rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        rx_ctl->bit_rx_user_id = user_idx;
    }
}

/*
 * 功能描述  : 构建host rx上下文
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_host_build_rx_context(hal_host_device_stru *hal_dev, oal_netbuf_stru *netbuf,
    hmac_host_rx_context_stru *rx_context)
{
    mac_rx_ctl_stru *cb = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    dpe_wlan_vap_stru *dpe_vap = NULL;
    dpe_wlan_user_stru *dpe_user = NULL;

    if (cb == NULL) {
        return OAL_FAIL;
    }
    dpe_vap = dpe_wlan_vap_get(cb->uc_mac_vap_id);
    if (dpe_vap == NULL) {
        oam_error_log0(cb->uc_mac_vap_id, OAM_SF_DPA, "hmac_host_build_rx_context:vap null");
        return OAL_FAIL;
    }
    rx_context->hal_dev = hal_dev;
    dpe_user = dpe_wlan_host_rx_lut_get_user(dpe_vap, netbuf, hal_dev, cb);
    if ((dpe_user == NULL) && (dpe_vap->en_vap_mode == WLAN_VAP_MODE_BSS_AP)) {
        dpe_user = dpe_wlan_ap_rx_recheck_user_idx(dpe_vap, netbuf, cb);
    }
    hmac_host_rx_update_cb_user_idx(dpe_user, netbuf);
    rx_context->dpe_vap = dpe_vap;
    rx_context->dpe_user = dpe_user;
    rx_context->netbuf = netbuf;
    rx_context->cb = cb;
    return OAL_SUCC;
}

/*
 * 功能描述  : host rx流程预处理函数，主要包括AMSDU成链，cb生成，device部分过滤操作
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_host_rx_proc_dev_routine(hal_host_device_stru *hal_dev,
    oal_netbuf_stru *netbuf, hmac_host_rx_context_stru *rx_context)
{
    /* 维测 */
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    hal_host_rx_proc_msdu_dscr(netbuf);
#endif
    if (hmac_host_rx_mpdu_build_cb(hal_dev, netbuf) != OAL_SUCC) {
        return OAL_FAIL;
    }
    if (hmac_host_build_rx_context(hal_dev, netbuf, rx_context) != OAL_SUCC) {
        return OAL_FAIL;
    }
    if (hmac_host_rx_pre_abnormal_filter(rx_context) != HMAC_RX_FRAME_CTRL_GOON) {
        hmac_rx_exception_free_stat(hal_dev);
        return OAL_FAIL;
    }

    return OAL_SUCC;
}

OAL_STATIC uint32_t hmac_host_get_rx_msdu_info(hal_host_device_stru *hal_dev, oal_netbuf_stru *netbuf)
{
    mac_rx_ctl_stru *rxctl = NULL;
    oal_netbuf_stru *next = NULL;
    uint8_t          first_msdu = OAL_TRUE;

    while (netbuf != NULL) {
        next = oal_netbuf_next(netbuf);
        rxctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        /* 统一获取参数接口 */
        if (hal_host_rx_get_msdu_info_dscr(hal_dev, netbuf, rxctl, first_msdu) != OAL_SUCC) {
            return OAL_FAIL;
        }

        /* 首帧标记 */
        if (mac_rxcb_is_first_msdu(rxctl) == OAL_TRUE) {
            first_msdu = OAL_FALSE;
        }
        netbuf = next;
    }
    return OAL_SUCC;
}

OAL_STATIC uint32_t hmac_host_rx_mpdu_proc(
    hal_host_device_stru *origin_dev, oal_netbuf_stru **mpdu, oal_netbuf_head_stru *rpt_list)
{
    hmac_host_rx_context_stru rx_context = { 0 };
    hal_host_device_stru *hal_dev = NULL;
    oal_netbuf_stru *netbuf = *mpdu;

    if (dpe_is_support_rx_dma_async() != OAL_TRUE) {
        /* 1. 外层异常处理基于链表的形式释放netbuf, 此处需要优先建链 */
        if (hal_host_rx_amsdu_list_build(origin_dev, netbuf) != OAL_SUCC) {
            return OAL_FAIL;
        }

        /* 2. rx msdu info归一化处理接口 */
        if (hmac_host_get_rx_msdu_info(origin_dev, netbuf) != OAL_SUCC) {
            return OAL_FAIL;
        }
    }
    /* 3. link选择 */
    hal_dev = hal_host_rx_get_mpdu_link(origin_dev, netbuf);
    if (oal_unlikely(hal_dev == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "{hmac_host_rx_mpdu_proc::get mpdu link failed}");
        return OAL_FAIL;
    }

    /* 4. 构建接收流程上下文 */
    if (hmac_host_rx_proc_dev_routine(hal_dev, netbuf, &rx_context) != OAL_SUCC) {
        return OAL_FAIL;
    }
#ifdef _PRE_WLAN_FEATURE_VSP
    if (hmac_vsp_rx_proc(rx_context.dpe_user->us_assoc_id, netbuf) == VSP_RX_ACCEPT) {
        /* vsp帧不采用上报协议栈方式，单独处理 */
        return OAL_SUCC;
    }
#endif
    /* 5. 业务流程上下文 */
    hmac_rx_route_print(rx_context.hal_dev, HOST_RX_REPORT, rx_context.cb);
    hmac_host_rx_static_proc(&rx_context);
    if (hmac_rx_proc_feature(&rx_context, rpt_list) != OAL_SUCC) {
        /* 部分子帧可能被加入rpt_list */
        *mpdu = rx_context.netbuf;
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

OAL_STATIC void hmac_host_rx_mpdu_list_proc(hal_host_device_stru *origin_dev, oal_netbuf_head_stru *mpdu_list)
{
    oal_netbuf_head_stru rpt_list;
    oal_netbuf_stru *mpdu = oal_netbuf_delist_nolock(mpdu_list);
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
    uint8_t fail_cnt;

    host_cnt_init_record_performance(RX_RING_PROC);
    host_start_record_performance(RX_RING_PROC);

    oal_netbuf_list_head_init_nolock(&rpt_list);
    for (; mpdu; mpdu = oal_netbuf_delist_nolock(mpdu_list)) {
        host_cnt_inc_record_performance(RX_RING_PROC);
        dpe_wlan_rx_delay_notify(mpdu, 0, RX_DMA_START);
        if (hmac_host_rx_mpdu_proc(origin_dev, &mpdu, &rpt_list) != OAL_SUCC) {
            fail_cnt = hmac_rx_netbuf_list_free(mpdu);
            rx_stats->rx_drop_cnt += fail_cnt;
            continue;
        }
        dpe_wlan_rx_delay_notify(mpdu, 0, RX_DMA_END);
    }

    if (oal_netbuf_list_len(&rpt_list)) {
        hmac_rx_rpt_netbuf(&rpt_list);
    }

    host_end_record_performance(host_cnt_get_record_performance(RX_RING_PROC), RX_RING_PROC);
}

#ifdef _PRE_MULTI_CORE_DPE_DMA_ASYNC
/* amsdu首帧或mpdu帧 */
OAL_STATIC OAL_INLINE void dpe_rx_data_dma_process_mpdu_crc_succ(dma_rx_comp_stru *dma_comp, uint32_t dma_array_idx,
    mac_rx_ctl_stru *rxctl)
{
    /* 如果是非amsdu帧返回不更新sum msdu num */
    if (mac_rxcb_is_first_msdu(rxctl) == OAL_FALSE) {
        return;
    }
    /* 如果是first msdu帧，更新num, sub_msdu_num不包含首帧 */
    dma_comp->dma_mpdu_array[dma_array_idx].sub_msdu_num = rxctl->uc_msdu_in_buffer;

    /* amsdu时创建新的dma待搬移数组 */
    if (rxctl->next_msdu_host_iova != 0) {
        /* host iova都是rx msdu起始地址,从comp ring读取 */
        dma_comp->dma_array[dma_comp->dma_list_num] = rxctl->next_msdu_host_iova;
        dma_comp->dma_list_num++;
        dma_comp->dma_mpdu_array[dma_array_idx].sub_msdu_flag = 1;
    }
}
void dpe_rx_data_dma_process_mpdu_crc_fail(dma_rx_comp_stru *dma_comp, uint32_t dma_array_idx,
    oal_netbuf_stru  *netbuf, mac_rx_ctl_stru *rxctl)
{
    /* 如果crc校验错,mac以为是非amsdu帧, 则sub_msdu_num=0并且不填写netx msdu msb/lsb */
    if (mac_rxcb_is_first_msdu(rxctl) == OAL_FALSE) {
        return;
    }

    /* 如果crc校验错,mac误以为是amsdu帧, 也会正确更新sub_msdu_num并且填写netx msdu msb/lsb, sub_msdu_num不包含首帧 */
    dma_comp->dma_mpdu_array[dma_array_idx].sub_msdu_num = rxctl->uc_msdu_in_buffer;
    dma_comp->dma_mpdu_array[dma_array_idx].crc_fail = 1;
    dma_comp->dma_mpdu_array[dma_array_idx].sub_msdu_flag = 0;

    /* amsdu时创建新的dma待搬移数组 */
    if (rxctl->next_msdu_host_iova != 0) {
        /* host iova都是rx msdu起始地址,从comp ring读取 */
        dma_comp->dma_array[dma_comp->dma_list_num] = rxctl->next_msdu_host_iova;
        dma_comp->dma_list_num++;
        dma_comp->dma_mpdu_array[dma_array_idx].sub_msdu_flag = 1;
    }
}

void dpe_rx_data_dma_process(hal_host_device_stru *hal_dev, dma_rx_comp_stru *dma_comp,
    oal_netbuf_stru  *netbuf, uint32_t dma_array_idx, uint32_t *next_array_idx)
{
    uint32_t submsdu_idx, cur_array_idx;
    mac_rx_ctl_stru *rxctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();

    /* amsdu需要通过lsb/msb读取后再释放 */
    /* 待适配amsdu获取流程 */
    /* 第一次处理mpdu首帧 */
    if (dma_comp->dma_cur_state == DPE_RX_DATA_COMP_DMA_START) {
        /* 统一获取参数接口, 已拷贝至sbuf cb */
        hal_host_rx_get_msdu_info_dscr(hal_dev, netbuf, rxctl, OAL_TRUE);

        if (oal_netbuf_list_empty(&dma_comp->dma_mpdu_array[dma_array_idx].mpdu_list) == OAL_FALSE) {
            oam_error_log2(dma_comp->hal_dev_id, OAM_SF_DPA, "dpe_rx_data_dma_process error first %d num %d!",
                mac_rxcb_is_first_msdu(rxctl), rxctl->uc_msdu_in_buffer);
        }
        /* 加入mpdu数组 */
        oal_netbuf_addlist_tail_nolock(&dma_comp->dma_mpdu_array[dma_array_idx].mpdu_list, netbuf);
        dma_comp->dma_mpdu_array[dma_array_idx].sub_msdu_num = 0;
        dma_comp->dma_mpdu_array[dma_array_idx].crc_fail = 0;
        dma_comp->dma_mpdu_array[dma_array_idx].sub_msdu_flag = 0;
        rx_stats->rx_data_mpdu_cnt++;

        /* crc正确与否关系是否有sub msdu num及next sub msdu msb/lsb */
        if (rxctl->rx_status == HAL_RX_SUCCESS) {
            dpe_rx_data_dma_process_mpdu_crc_succ(dma_comp, dma_array_idx, rxctl);
        } else {
            dpe_rx_data_dma_process_mpdu_crc_fail(dma_comp, dma_array_idx, netbuf, rxctl);
        }
        return;
    }

    /* 矩阵子层处理,也是amsdu的非首帧处理 */
    /* 统一获取参数接口, 已拷贝至sbuf cb */
    hal_host_rx_get_msdu_info_dscr(hal_dev, netbuf, rxctl, OAL_FALSE);

#ifdef _PRE_MULTI_CORE_DPE_DMA_DEBUG
    /* 校验DMA搬移是否正确 */
    oam_error_log4(dma_comp->hal_dev_id, OAM_SF_DPA, "dpe_rx_data_dma_process \
        rx status %d, frame %d, mac header len %d pay len %d !",
        rxctl->rx_status, rxctl->bit_frame_format, rxctl->uc_mac_header_len, rxctl->us_frame_len);
#endif
    /* sub msdu加入mpdu数组 */
    cur_array_idx = *next_array_idx;
    for (submsdu_idx = cur_array_idx; submsdu_idx < DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME; submsdu_idx++) {
        if (dma_comp->dma_mpdu_array[submsdu_idx].sub_msdu_flag == 0) {
            /* 该节点没有sub msdu子帧 */
            continue;
        }
        oal_netbuf_addlist_tail_nolock(&dma_comp->dma_mpdu_array[submsdu_idx].mpdu_list, netbuf);
        if (rxctl->next_msdu_host_iova != 0) {
            /* host iova都是rx msdu起始地址,从comp ring读取 */
            dma_comp->dma_array[dma_comp->dma_list_num] = rxctl->next_msdu_host_iova;
            dma_comp->dma_list_num++;
            dma_comp->dma_mpdu_array[submsdu_idx].sub_msdu_flag = 1;
        } else {
            dma_comp->dma_mpdu_array[submsdu_idx].sub_msdu_flag = 0;
        }
        /* 记录当前非零的indx, 可以减少负载 */
        *next_array_idx = submsdu_idx + 1;
        break;
    }
}

void dpe_rx_data_comp_dma_proc_array(hal_host_device_stru *hal_dev, uint32_t dma_array_idx, dma_rx_comp_stru *dma_comp,
    uint8_t dma_list_num_total, uint32_t *next_array_idx)
{
    uint8_t rx_msdu_len = hal_host_get_rx_msdu_dscr_len();
    uint8_t offset = DPE_RX_ADD_BUFF_DMA_LEN - rx_msdu_len;
    uint8_t  rx_alloc_list_lock_idx;
    oal_uint flags;
    hal_host_rx_alloc_list_stru *alloc_list = &hal_dev->host_rx_normal_alloc_list;
    mac_rx_ctl_stru *rxctl = NULL;
    dpe_rx_msdu_init_stru *rx_info = (dpe_rx_msdu_init_stru *)dma_comp->rx_info_array[dma_array_idx];
    oal_netbuf_stru *netbuf = (oal_netbuf_stru *)rx_info->sbuf_addr;  // 目的是这个点
    if (netbuf == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_rx_data_comp_dma_proc_array::netbuf null, idx %d", dma_array_idx);
        return;
    }
#ifdef _USE_CACHE_PRELOAD
    if (((dma_array_idx + 1) < dma_list_num_total) && (dma_comp->rx_info_array[dma_array_idx + 1] != 0)) {
        prefetch_cached_ddr(
            (oal_netbuf_stru *)((dpe_rx_msdu_init_stru *)dma_comp->rx_info_array[dma_array_idx + 1])->sbuf_addr);
    }
#endif
    /* 1. 中断流程不处理sbuf,全部此处摘链; 2. amsdu首帧已在中断里面摘下,dma done流程中只需摘子帧 */
    if ((dpe_is_support_isr_rx_sbuf_by_addr() == OAL_TRUE) || (dma_comp->dma_cur_state != DPE_RX_DATA_COMP_DMA_START)) {
        rx_alloc_list_lock_idx = alloc_list->rx_alloc_list_lock_idx;
        oal_spin_lock_irq_save(dpe_get_dev_rx_alloc_list_lock(rx_alloc_list_lock_idx), &flags);
        /* 关wifi或ring切换时已释放alloc list, 则不处理 */
        if (oal_netbuf_list_empty(&alloc_list->rx_alloc_list) == OAL_TRUE) {
            oal_spin_unlock_irq_restore(dpe_get_dev_rx_alloc_list_lock(rx_alloc_list_lock_idx), &flags);
            oam_warning_log1(0, OAM_SF_DPA, "dpe_rx_data_comp_dma_proc_array::netbuf freed %d", dma_array_idx);
            return;
        }
        oal_netbuf_delete_nolock(netbuf, &alloc_list->rx_alloc_list);
        oal_spin_unlock_irq_restore(dpe_get_dev_rx_alloc_list_lock(rx_alloc_list_lock_idx), &flags);
    }

    /* 将rx msdu和eth/ip头从ddr拷贝到sbuf cb里 */
    memcpy_s(dpe_get_sbuf_cb_wifi_info(netbuf), DPE_NETBUF_CB_WIFI_INFO_LEN - offset, (uint8_t *)rx_info + offset,
        DPE_NETBUF_CB_WIFI_INFO_LEN - offset);

    /* 获取下一个sub msdu的iova */
    rxctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    rxctl->next_msdu_host_iova = hal_host_rx_get_next_msdu_iova(netbuf);

    dpe_rx_data_dma_process(hal_dev, dma_comp, netbuf, dma_array_idx, next_array_idx);
}

void dpe_rx_data_comp_dma_proc_list(hal_host_device_stru *hal_dev, uint32_t dma_array_idx,
    dma_rx_comp_stru *dma_comp, oal_netbuf_stru *netbuf, oal_netbuf_head_stru *msdu_list, uint32_t *next_array_idx)
{
    oal_netbuf_stru  *next_msdu = NULL;
    /* 获取下一个sub msdu */
    next_msdu = hal_rx_get_next_sub_msdu(hal_dev, netbuf);
    /* 创建新的dma待搬移链表 */
    if (next_msdu != NULL) {
        oal_netbuf_addlist_tail_nolock(msdu_list, next_msdu); // 放到临时链表，函数尾部返回前再加入dma list
    }
    /* 遍历当前搬移完毕的DMA链表 */
    dpe_rx_data_dma_process(hal_dev, dma_comp, netbuf, dma_array_idx, next_array_idx);
}
OAL_STATIC OAL_INLINE uint32_t dpe_rx_dma_list_number(dma_rx_comp_stru *dma_comp)
{
    return dpe_is_support_rx_sbuf_by_addr() ?
        dma_comp->dma_list_num : oal_netbuf_list_len(&dma_comp->dma_list);
}

OAL_STATIC OAL_INLINE uint8_t dpe_rx_dma_list_empty(dma_rx_comp_stru *dma_comp)
{
    return dpe_is_support_rx_sbuf_by_addr() ?
        dma_comp->dma_list_num == 0 : oal_netbuf_list_empty(&dma_comp->dma_list);
}

/* DMA callback的fiber和wifi处理线程绑定到一个核，存在共享内存竞争问题 */
void dpe_rx_data_comp_dma_cb(void *dma_cb)
{
    oal_netbuf_stru  *netbuf = NULL;
    dma_rx_comp_stru *dma_comp = (dma_rx_comp_stru *)dma_cb;
    oal_netbuf_head_stru msdu_list;
    uint32_t dma_array_idx, dma_event;
    hal_host_device_stru *hal_dev = hal_get_host_device(dma_comp->hal_dev_id);
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
    uint8_t dma_list_num = dma_comp->dma_list_num;
    uint8_t dma_list_num_total = dma_comp->dma_list_num;
    uint32_t next_array_idx = 0;

    /* 维测 */
    rx_stats->rx_dma_done_cnt += dpe_rx_dma_list_number(dma_comp);

    if (hal_dev == NULL) {
        oam_error_log0(dma_comp->hal_dev_id, OAM_SF_DPA, "dpe_rx_data_comp_dma_cb:hal dev null");
        hal_dev = hal_get_host_device(HAL_DEVICE_ID_MASTER);
    }
    dma_comp->dma_list_num = 0;
    oal_netbuf_list_head_init_nolock(&msdu_list);
    for (dma_array_idx = 0; dma_array_idx < DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME; dma_array_idx++) {
        if (dpe_is_support_rx_sbuf_by_addr()) {
            /* DMA搬移完成链表已取空 */
            if (dma_list_num == 0) {
                break;
            }
            dma_list_num--;
            dpe_rx_data_comp_dma_proc_array(hal_dev, dma_array_idx, dma_comp, dma_list_num_total, &next_array_idx);
        } else {
            /* DMA搬移完成链表已取空 */
            if (oal_netbuf_list_empty(&dma_comp->dma_list) == OAL_TRUE) {
                break;
            }
            /* 选择搬移完毕的msdu子帧 */
            netbuf = oal_netbuf_delist_head_nolock(&dma_comp->dma_list);
            dpe_rx_data_comp_dma_proc_list(hal_dev, dma_array_idx, dma_comp, netbuf, &msdu_list, &next_array_idx);
        }
    }
    if (oal_netbuf_list_empty(&msdu_list) != OAL_TRUE) {
        /* 链式dma */
        oal_netbuf_queue_splice_tail_init(&msdu_list, &dma_comp->dma_list);
    }
    // 消息触发线程调度
    if (dpe_rx_dma_list_empty(dma_comp) != OAL_TRUE) {
        dma_event = (hal_dev->device_id == 0) ? DPE_RX_DATA_DMA_CONTINUE_MASTER : DPE_RX_DATA_DMA_CONTINUE_SLAVE;
    } else {
        dma_event = (hal_dev->device_id == 0) ? DPE_RX_DATA_REORDER_EVENT_MASTER : DPE_RX_DATA_REORDER_EVENT_SLAVE;
    }

#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
    mdrv_order_msg msg; // 可以携带两个参数, 如sk_list及num
    if (hal_rx_data_need_scheduled(&msg, dma_event, OAL_FALSE) != OAL_TRUE) {
        return;
    }
#endif
    /* 入队驱动fiber调度 */
    if (dpe_sema_up(g_rx_comp_mgmt.rx_data_thread_info.task_id, &msg, dma_event) != 0) {
        oam_error_log1(dma_comp->hal_dev_id, OAM_SF_DPA, "dpe_rx_data_comp_dma_cb: post event %d fail", dma_event);
    }
}
void dpe_rx_data_dma_array_init(dma_rx_comp_stru *dma_comp, uint32_t dma_array_idx)
{
    oal_netbuf_list_head_init_nolock(&dma_comp->dma_mpdu_array[dma_array_idx].mpdu_list);
    dma_comp->dma_mpdu_array[dma_array_idx].sub_msdu_num = 0;
    dma_comp->dma_mpdu_array[dma_array_idx].crc_fail = 0;
    dma_comp->dma_mpdu_array[dma_array_idx].sub_msdu_flag = 0;
}
void dpe_rx_data_comp_dma_init(hal_host_device_stru *hal_dev, uint32_t dma_cur_state, uint32_t dma_next_state)
{
    dpe_dma_stru *dma_hdl = dpe_get_dma_hdl(DPE_RX_COMP_DMA);
    dma_rx_comp_stru *dma_comp = (dma_rx_comp_stru*)dma_hdl->wifi_serv_dma;
    uint32_t dma_array_idx;

    dma_comp->hal_dev_id = hal_dev->device_id;
    dma_comp->dma_cur_state = dma_cur_state;
    dma_comp->dma_next_state = dma_next_state;
    dma_comp->dma_transfer_level = 0;
    dma_comp->dma_done_cb = dpe_rx_data_comp_dma_cb;

    /* 初始化ampdu+amsdu矩阵队列 */
    for (dma_array_idx = 0; dma_array_idx < DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME; dma_array_idx++) {
        dpe_rx_data_dma_array_init(dma_comp, dma_array_idx);
    }
}

/*
 * 功能描述  : pingpang队列出队指定数量的帧
 * 1.日    期  : 2020年2月23日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void dpe_rx_mpdu_que_pop_designate_list(hal_host_device_stru *hal_device,
    oal_netbuf_head_stru *netbuf_head, uint32_t number)
{
    hal_rx_mpdu_que  *rx_mpdu = &(hal_device->st_rx_mpdu);
    oal_netbuf_head_stru *list = &rx_mpdu->ast_rx_mpdu_list[HAL_RX_MPDU_PONG]; // ping-pong list,不需要锁
    oal_netbuf_stru  *skb = NULL;
    oal_netbuf_stru  *next_skb = NULL;
    dpe_dma_stru *dma_hdl = dpe_get_dma_hdl(DPE_RX_COMP_DMA);
    uint32_t add_num = 0;
    dma_rx_comp_stru *dma_comp = (dma_rx_comp_stru*)dma_hdl->wifi_serv_dma;
    /* 初始化 */
    dma_comp->dma_list_num = 0;
    oal_netbuf_list_head_init_nolock(netbuf_head);

    if (oal_netbuf_list_empty(list) == OAL_TRUE) {
        /* 切换ping-pong队列 */
        hal_host_rx_mpdu_que_pop(hal_device, list);
    }

    if (oal_netbuf_list_empty(list) == OAL_TRUE) {
        return;
    }

    oal_netbuf_search_for_each_safe(skb, next_skb, list) {
        if (skb == NULL || number == 0) {
            break;
        }
        number--;
        /* 摘除skb */
        skb = oal_netbuf_delist_nolock(list);
        /* 加入skb */
        if (dpe_is_support_rx_sbuf_by_addr()) {
            /* 此处host iova是maa地址, 非rx msdu dscr起始地址 */
            dma_comp->dma_array[add_num] = (uint64_t)oal_netbuf_data_iova(skb);
            add_num++;
        } else {
            oal_netbuf_list_tail_nolock(netbuf_head, skb);
        }
    }
    dma_comp->dma_list_num = add_num;
}
void dpe_rx_pop_buff_pool_to_dma_array(hal_host_device_stru *hal_device, uint32_t number)
{
    dpe_dma_stru *dma_hdl = dpe_get_dma_hdl(DPE_RX_COMP_DMA);
    dma_rx_comp_stru *dma_comp = (dma_rx_comp_stru*)dma_hdl->wifi_serv_dma;
    hal_rx_mpdu_que  *rx_mpdu = &(hal_device->st_rx_mpdu);
    uint64_t hw_dscr_addr;
    unsigned long    lock_flag;
    uint32_t add_num;

    dpe_rx_mpdu_list_lock_irq_save(&rx_mpdu->st_spin_lock, &lock_flag);
    for (add_num = 0; add_num < number; add_num++) {
        /* 此处host iova是maa地址, 非rx msdu dscr起始地址 */
        hw_dscr_addr = hal_host_rx_get_from_buff_pool();
        if (hw_dscr_addr == 0) {
            break;
        }
        dma_comp->dma_array[add_num] = hw_dscr_addr;
        dpe_wlan_rx_delay_notify(NULL, add_num, RX_DMA_START);
    }
    dma_comp->dma_list_num = add_num;
    dpe_rx_mpdu_list_unlock_irq_restore(&rx_mpdu->st_spin_lock, &lock_flag);
}

void dpe_rx_data_dma_to_reorder(hal_host_device_stru *hal_dev, dma_rx_comp_stru *dma_comp, uint8_t dma_transfer_state)
{
    oal_netbuf_head_stru rpt_list;
    oal_netbuf_stru *mpdu_head = NULL;
    oal_netbuf_stru *mpdu_tail = NULL;
    uint32_t dma_array_idx;
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
    uint8_t msdu_cnt = 0;

    // 检查新链表1的1/4/7对应的// 2/3/5/6/7/8队列中是否都已搬移完毕
    // 搬移完毕，先处理callback
    // 新链表1和新链表2 1->2->3, 4->5->6, 7->8->9， mpdu串连，逐个mpdu处理
    oal_netbuf_list_head_init_nolock(&rpt_list);
    for (dma_array_idx = 0; dma_array_idx < DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME; dma_array_idx++) {
        if (oal_netbuf_list_empty(&dma_comp->dma_mpdu_array[dma_array_idx].mpdu_list) == OAL_TRUE) {
            dpe_rx_data_dma_array_init(dma_comp, dma_array_idx);
            continue;
        }

#ifdef _USE_CACHE_PRELOAD
        if (dma_array_idx + 1 < DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME) {
            prefetch_cached_ddr(oal_netbuf_peek(&dma_comp->dma_mpdu_array[dma_array_idx + 1].mpdu_list));
        }
#endif
        msdu_cnt = oal_netbuf_list_len(&dma_comp->dma_mpdu_array[dma_array_idx].mpdu_list);
        mpdu_head = oal_netbuf_peek(&dma_comp->dma_mpdu_array[dma_array_idx].mpdu_list);
        mpdu_tail = oal_netbuf_tail(&dma_comp->dma_mpdu_array[dma_array_idx].mpdu_list);
        /* 从链表断链 */
        oal_set_netbuf_next(mpdu_tail, NULL);

        rx_stats->rx_data_msdu_cnt += msdu_cnt;
        /* 开启amsdu后crc错误率提升明显 */
        if (hmac_host_rx_mpdu_proc(hal_dev, &mpdu_head, &rpt_list) != OAL_SUCC) {
            rx_stats->rx_drop_cnt += msdu_cnt;
            hmac_rx_netbuf_list_free(mpdu_head);
        }

        dpe_wlan_rx_delay_notify(mpdu_head, dma_array_idx, RX_DMA_END);

        /* 处理完初始化 */
        dpe_rx_data_dma_array_init(dma_comp, dma_array_idx);
    }
    /* 提交FILTER */
    if (oal_netbuf_list_len(&rpt_list)) {
        hmac_rx_rpt_netbuf(&rpt_list); // filter input可以做成list链式传递
    }
}
#ifdef _PRE_MULTI_CORE_DPE_DMA_DEBUG
uint32_t g_test = 0;
void dpe_rx_ring_data_abnormal_log(hal_host_device_stru *hal_dev, dpe_dma_stru *dma_hdl, dma_rx_comp_stru *dma_comp)
{
    uint32_t dma_event;
    oam_error_log3(dma_comp->hal_dev_id, OAM_SF_DPA, "dpe_rx_ring_data_abnormal_log: dma busy %d cur state %d \
        delay cnt %d\n", dma_hdl->is_dma_busy, dma_comp->dma_next_state, g_test);
    g_test++;
    if (g_test >= 10) { // 10 代表异常循环10次
        g_test = 0;
        dma_comp->dma_next_state = DPE_RX_DATA_COMP_DMA_START;
    }
    dma_event = (hal_dev->device_id == 0) ? DPE_RX_DATA_IRQ_EVENT_MASTER : DPE_RX_DATA_IRQ_EVENT_SLAVE;

#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
    mdrv_order_msg msg; // 可以携带两个参数, 如sk_list及num
    if (hal_rx_data_need_scheduled(&msg, dma_event, OAL_FALSE) != OAL_TRUE) {
        return;
    }
#endif
    /* 入队驱动fiber调度 */
    if (dpe_sema_up(g_rx_comp_mgmt.rx_data_thread_info.task_id, &msg, dma_event) != 0) {
        oam_error_log1(dma_comp->hal_dev_id, OAM_SF_DPA, "dpe_rx_ring_data_event: %d err", dma_event);
    }
}
#endif

uint32_t dpe_rx_ring_data_event_async(hal_host_device_stru *hal_dev, uint8_t dma_transfer_state)
{
    dpe_dma_stru *dma_hdl = dpe_get_dma_hdl(DPE_RX_COMP_DMA);
    dma_rx_comp_stru *dma_comp = (dma_rx_comp_stru*)dma_hdl->wifi_serv_dma;
    uint8_t dma_array_idx = 0;
    uint32_t dma_event;

    if (oal_unlikely(hal_dev == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    switch (dma_transfer_state) {
        case DPE_RX_DATA_COMP_DMA_START:
            /* DMA已启动 */
            if (dma_hdl->is_dma_busy != 0 || dma_comp->dma_next_state != DPE_RX_DATA_COMP_DMA_START) {
            #ifdef _PRE_MULTI_CORE_DPE_DMA_DEBUG
                dpe_rx_ring_data_abnormal_log(hal_dev, dma_hdl, dma_comp);
            #endif
                return OAL_SUCC;
            }
            for (dma_array_idx = 0; dma_array_idx < DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME; dma_array_idx++) {
                if (oal_netbuf_list_empty(&dma_comp->dma_mpdu_array[dma_array_idx].mpdu_list) == 0) {
                    oam_error_log0(0, OAM_SF_DPA, "dpe_rx_ring_data_event_async:: dma start but array not empty!");
                    return OAL_SUCC;
                }
            }
            if (dpe_rx_dma_list_empty(dma_comp) == OAL_FALSE) {
                oam_error_log0(0, OAM_SF_DPA, "dpe_rx_ring_data_event_async:: dma start but list not empty!");
                return OAL_SUCC;
            }
            if (dpe_is_support_isr_rx_sbuf_by_addr() != OAL_TRUE) {
                // ping pong队列摘取skb, 启动mpdu首帧(不处理amsdu子帧)的dma搬移
                dpe_rx_mpdu_que_pop_designate_list(hal_dev, &dma_comp->dma_list, DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME);
            } else {
                /* 从buff pool的host iova填写dma array, 启动mpdu首帧(不处理amsdu子帧)的dma搬移 */
                dpe_rx_pop_buff_pool_to_dma_array(hal_dev, DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME);
            }

            if (dpe_rx_dma_list_empty(dma_comp) == OAL_TRUE) {
                return OAL_SUCC;
            }
#ifdef _PRE_MULTI_CORE_DPE_DMA_DEBUG
            oam_error_log1(dma_comp->hal_dev_id, OAM_SF_DPA, "enter dma start, move %d skbs\n",
                oal_netbuf_list_len(&dma_comp->dma_list));
#endif

            // 1/4/7, 启动DMA异步搬移, 放到新链表1
            dpe_rx_data_comp_dma_init(hal_dev, dma_transfer_state, DPE_RX_DATA_COMP_DMA_CONTINUE);
            dpe_dma_cpy_list(DPE_RX_COMP_DMA);
            return OAL_SUCC;
        case DPE_RX_DATA_COMP_DMA_CONTINUE:
#ifdef _PRE_MULTI_CORE_DPE_DMA_DEBUG
            oam_error_log1(dma_comp->hal_dev_id, OAM_SF_DPA, "enter dma continue, move %d skbs\n",
                oal_netbuf_list_len(&dma_comp->dma_list));
#endif
            // 2/3/5/6/7/8队列
            dma_comp->dma_cur_state = dma_transfer_state;
            dma_comp->dma_next_state = DPE_RX_DATA_COMP_DMA_CONTINUE;
            dma_comp->dma_transfer_level++;
            // 知道1/4/7分别携带多少个msdu, 从rx list摘msdu，启动dma
            dpe_dma_cpy_list(DPE_RX_COMP_DMA);
            // msdu 链表不空，不切换dma状态机,  老链表取一批， 启动dma， 放到新链表2表示已dma搬完
            return OAL_SUCC;
        case DPE_RX_DATA_COMP_RX_REORDER:
#ifdef _PRE_MULTI_CORE_DPE_DMA_DEBUG
            oam_error_log0(dma_comp->hal_dev_id, OAM_SF_DPA, "enter reorder \n");
#endif
            /* ampdu+amsdu搬移完毕, 进入重排序 */
            dpe_rx_data_dma_to_reorder(hal_dev, dma_comp, dma_transfer_state);

            /* 链表处理完后，再修改状态，防止DMA_START事件重入，导致链表访问冲突 */
            dma_comp->dma_cur_state = dma_transfer_state;
            dma_comp->dma_next_state = DPE_RX_DATA_COMP_DMA_START;
            /* 下一轮DMA搬移 */
            dma_event = (hal_dev->device_id == 0) ? DPE_RX_DATA_IRQ_EVENT_MASTER : DPE_RX_DATA_IRQ_EVENT_SLAVE;
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
            mdrv_order_msg msg; // 可以携带两个参数, 如sk_list及num
            if (hal_rx_data_need_scheduled(&msg, dma_event, OAL_FALSE) != OAL_TRUE) {
                return OAL_SUCC;
            }
#endif
            /* 入队驱动fiber调度 */
            if (dpe_sema_up(g_rx_comp_mgmt.rx_data_thread_info.task_id, &msg, dma_event) != 0) {
                oam_error_log1(dma_comp->hal_dev_id, OAM_SF_DPA, "dpe_rx_ring_data_event: event %d fail", dma_event);
            }
            return OAL_SUCC;
        default:
            break;
    }

    return OAL_SUCC;
}
#endif

OAL_STATIC uint32_t dpe_rx_ring_data_event(hal_host_device_stru *hal_dev, uint8_t dma_transfer_state)
{
    oal_netbuf_head_stru mpdu_list;
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_netbuf_head_stru unmap_list;
#endif

    oal_netbuf_list_head_init_nolock(&mpdu_list);
    hal_host_rx_mpdu_que_pop(hal_dev, &mpdu_list);
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* DPA上无需做unmap操作 */
    hmac_host_rx_mpdu_list_proc(hal_dev, &mpdu_list);
#else
    oal_netbuf_list_head_init_nolock(&unmap_list);
    hal_host_rx_dma_unmap_proc(&mpdu_list, &unmap_list);
    hmac_host_rx_mpdu_list_proc(hal_dev, &unmap_list);
#endif

    return OAL_SUCC;
}

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
uint32_t dpe_dma_rx_ring_data_event(hal_host_device_stru *hal_dev, uint8_t dma_transfer_state)
{
#ifdef _PRE_MULTI_CORE_DPE_DMA_ASYNC
    if (dpe_is_support_rx_dma_async() == OAL_TRUE) {
        return dpe_rx_ring_data_event_async(hal_dev, dma_transfer_state);
    } else {
        return dpe_rx_ring_data_event(hal_dev, dma_transfer_state);
    }
#else
    return dpe_rx_ring_data_event(hal_dev, dma_transfer_state);
#endif
}
#else
/*
 * 功能描述  : host rx ring数据处理接口
 * 1.日    期  : 2020年1月5日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_host_rx_ring_data_event(frw_event_mem_stru *event_mem)
{
    hal_host_rx_event *wlan_rx_event = NULL;
    hal_host_device_stru *hal_dev = NULL;
    if (oal_unlikely(event_mem == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    wlan_rx_event = (hal_host_rx_event *)frw_get_event_stru(event_mem)->auc_event_data;
    if (oal_unlikely(wlan_rx_event->hal_dev == NULL)) {
        return OAL_FAIL;
    }
    hal_dev = wlan_rx_event->hal_dev;
    dpe_rx_ring_data_event(hal_dev, 0);
    return OAL_SUCC;
}
#endif
