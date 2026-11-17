/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : dpe_wlan_stat.c
 * 作    者 :
 * 创建日期 : 2024年11月22日
 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "hmac_rx.h"
#include "dpe_sbuf.h"
#include "dpe_netdev.h"
#include "dpe_filter_reg.h"
#include "dpe_dpa_intf.h"
#include "dpe_wlan_resource.h"
#include "dpe_wlan_stat.h"
#include "host_hal_ext_if.h"
#include "dpe_tx_data.h"
#include "mac_data.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_WLAN_RX_C

OAL_STATIC OAL_INLINE void hmac_rx_get_input_netbuf_from_waitlist(dpe_wlan_vap_stru *dpe_vap,
    oal_netbuf_head_stru *netbuf_list)
{
    oal_uint lock_flag;
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
    /* 如果wait list非空，先把sbuf链表挂在后面 */
    if (oal_unlikely(!oal_netbuf_list_empty(&dpe_vap->rx_rpt_wait_list))) {
        oal_spin_lock_irq_save(dpe_get_vap_wait_list_lock(dpe_vap->wait_list_lock_idx), &lock_flag);

        rx_stats->rx_rpt_wait_list_cnt += oal_netbuf_list_len(netbuf_list);
        oal_netbuf_queue_splice_tail_init(netbuf_list, &dpe_vap->rx_rpt_wait_list);
        rx_stats->rx_rpt_wait_list_cnt -= oal_netbuf_list_len(&dpe_vap->rx_rpt_wait_list);
        oal_netbuf_queue_splice_tail_init(&dpe_vap->rx_rpt_wait_list, netbuf_list);

        oal_spin_unlock_irq_restore(dpe_get_vap_wait_list_lock(dpe_vap->wait_list_lock_idx), &lock_flag);
    }
}

OAL_STATIC OAL_INLINE void dpe_rx_save_netbuf_to_waitlist(dpe_wlan_vap_stru *dpe_vap, oal_netbuf_stru *ret_netbuf)
{
    oal_uint lock_flag;
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
    /* 将剩余sbuf挂回wait list，如果已满则丢弃一部分 */
    oal_spin_lock_irq_save(dpe_get_vap_wait_list_lock(dpe_vap->wait_list_lock_idx), &lock_flag);
    rx_stats->rx_rpt_wait_list_cnt += hmac_rx_netbuf_join_to_list(ret_netbuf, &dpe_vap->rx_rpt_wait_list);
    oam_warning_log1(dpe_vap->uc_vap_id, OAM_SF_DPA, "dpe_rx_save_netbuf_to_waitlist:: add2wait[%d]",
        oal_netbuf_list_len(&dpe_vap->rx_rpt_wait_list));

    if (oal_netbuf_list_len(&dpe_vap->rx_rpt_wait_list) > HMAC_RX_RPT_WAIT_LIST_MAX_NUM) {
        uint32_t free_num = oal_netbuf_list_len(&dpe_vap->rx_rpt_wait_list) - HMAC_RX_RPT_WAIT_LIST_MAX_NUM;
        dpe_netbuf_free_list_all(&dpe_vap->rx_rpt_wait_list, free_num);
        rx_stats->rx_rpt_wait_list_cnt -= free_num;
        oam_error_log2(dpe_vap->uc_vap_id, OAM_SF_DPA, "dpe_rx_save_netbuf_to_waitlist::free num[%d] all num[%d]",
            free_num, free_num + HMAC_RX_RPT_WAIT_LIST_MAX_NUM);
    }
    oal_spin_unlock_irq_restore(dpe_get_vap_wait_list_lock(dpe_vap->wait_list_lock_idx), &lock_flag);
    return;
}

void dpe_wlan_rx_filter_user_data_set(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctrl)
{
    dpe_wlan_rx_filter_priv_data_stru *usr_data = (dpe_wlan_rx_filter_priv_data_stru *)oal_sbuf_cb(netbuf);
    oal_net_device_stru *net_dev = dpe_vap_get_net_device(rx_ctrl->uc_mac_vap_id);

    usr_data->vap_id            = rx_ctrl->uc_mac_vap_id;
    usr_data->data_type         = rx_ctrl->bit_data_type;
    usr_data->transfer_from_dpa = rx_ctrl->bit_transfer_from_dpa;
    usr_data->cipher_type       = rx_ctrl->bit_cipher_type;
    usr_data->rx_user_id        = rx_ctrl->bit_rx_user_id;

    if (usr_data->vap_id == 0) {
        oam_error_log4(0, OAM_SF_DPA, "{dpe_wlan_rx_sms_filter_input::usr_data 0x%x error type %d dpa %d type %d.}",
            *(uint32_t*)usr_data, usr_data->data_type, usr_data->transfer_from_dpa, usr_data->cipher_type);
    }
    if (usr_data->data_type <= MAC_DATA_ARP_REQ) {
        oam_warning_log2(usr_data->vap_id, OAM_SF_DPA, "{dpe filter input::user[%d] rx vip type %d}",
            rx_ctrl->bit_rx_user_id, usr_data->data_type);
    }
#ifdef _PRE_WLAN_DPE_DEBUG
    if ((((uint64_t)oal_netbuf_data(netbuf)) & ((uint64_t)1 << DPE_SC_MODE_OFFSET)) == 0) {
        sys_abort(1);
    }
#endif

    dpe_wifi_netbuf_out_inc(EN_FILTER_INPUT, 1);
    if (net_dev == NULL) {
        oam_error_log4(0, OAM_SF_DPA, "{rx_filter_user_data_set::dev err usr_data 0x%x type %d dpa %d type %d.}",
            *(uint32_t*)usr_data, usr_data->data_type, usr_data->transfer_from_dpa, usr_data->cipher_type);
        return;
    }
    oal_set_netbuf_ifindex(netbuf, dev_get_id(net_dev));
}

/* DPA已支持持锁并发传输, 功耗/性能模式下均可引用该接口 */
oal_netbuf_stru *dpe_wlan_filter_input_single(oal_netbuf_stru *netbuf)
{
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
    oal_netbuf_stru *next_netbuf = NULL;
    int32_t ret = 0;

    while (netbuf != NULL) {
        next_netbuf = oal_netbuf_next(netbuf);
        oal_set_netbuf_next(netbuf, NULL);
        oal_set_netbuf_prev(netbuf, NULL);
        ret = dpa_sms_filter_input(DPA_SMS_NIC_WLAN, netbuf);
        if (ret == OAL_SUCC) {
            rx_stats->rx_filter_input_cnt++;
            netbuf = next_netbuf;
            continue;
        }
        rx_stats->rx_filter_input_fail_cnt++;
        oam_warning_log1(0, OAM_SF_DPA, "{dpa_sms_filter_input returns fail %x}", ret);
        return netbuf;
    }
    return NULL;
}

uint32_t g_dpa_filter_input_switch = 0;
/* DPA无持锁传输, 高性能接口, 功耗(task)/性能(fiber)模式下,需主动申明任务上下文 */
oal_netbuf_stru *dpe_wlan_filter_input_list(oal_netbuf_stru *netbuf, uint32_t cnt)
{
    oal_netbuf_stru *ret_netbuf = netbuf;
    mac_rx_ctl_stru *rx_cb = NULL;
    int32_t ret = 0;
    int is_task = 0;
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();

    /* 返回值负数：异常失败，全部释放 / 0：成功 / 正数：部分成功，返回成功的个数 */
    /* 部分成功，会将指针指向失败起始的netbuf，外部全部释放即可 */
    if (g_dpa_filter_input_switch == 0) {
        rx_cb = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        /* 是否hcc task传递的帧 */
        if (rx_cb->bit_transfer_from_task != 0) {
            is_task = 1;
        }
        /* 支持fiber/task上下文送帧,需明确上下文来帧,hcc是task、gso/reorder/rxring是fiber */
        ret = dpa_sms_filter_input_push(DPA_SMS_NIC_WLAN, &ret_netbuf, is_task);
    } else {
        /* fiber上下文无锁化设计接口,不支持task送帧 */
        ret = dpa_sms_filter_input_list(DPA_SMS_NIC_WLAN, &ret_netbuf);
    }
    if (ret == OAL_SUCC) {
        rx_stats->rx_filter_input_cnt += cnt;
        rx_stats->rx_filter_conti_fail_cnt = 0;
        return NULL;
    } else if (ret > 0) {
        rx_stats->rx_filter_input_fail_cnt += cnt - (uint32_t)ret;
        rx_stats->rx_filter_input_cnt += (uint32_t)ret;
        rx_stats->rx_filter_conti_fail_cnt += cnt - (uint32_t)ret;
        oam_warning_log2(0, 0, "rx filter input cnt %d fail cnt %d \n", cnt, cnt - (uint32_t)ret);
    } else {
        oam_warning_log2(0, OAM_SF_DPA, "{dpa_sms_filter_input_list returns fail %x, cnt is %u.}", ret, cnt);
        rx_stats->rx_filter_input_fail_cnt += cnt;
        rx_stats->rx_filter_conti_fail_cnt += cnt;
    }
    if (rx_stats->rx_filter_conti_fail_cnt > 100) { // 100:连续失败说明有异常，需要分析
        oam_warning_log1(0, OAM_SF_DPA, "{dpa_sms_filter_input_list contiuous fail %d}",
            rx_stats->rx_filter_conti_fail_cnt);
        rx_stats->rx_filter_conti_fail_cnt = 0;
    }
    return ret_netbuf;
}

void dpe_wlan_rx_filter_input_is_from_dpa(oal_net_device_stru *netdev,
    oal_netbuf_head_stru *netbuf_list, mac_rx_ctl_stru *rx_ctrl)
{
    oal_netbuf_stru *netbuf = NULL;
    oal_netbuf_stru *next_netbuf = NULL;
    if (oal_unlikely(oal_netbuf_list_len(netbuf_list) != 1)) {
        oam_error_log0(0, 0, "rx filter input transfer from dpa netbuf cnt != 1");
    }
    oal_netbuf_search_for_each_safe(netbuf, next_netbuf, netbuf_list) {
        oal_netbuf_delete_nolock(netbuf, netbuf_list);
        rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        dpe_wlan_rx_filter_user_data_set(netbuf, rx_ctrl);
        /* 软转透传帧, 32字节空间 */
        memcpy_s((uint8_t *)oal_sbuf_cb(netbuf) + RX_FILTER_USER_DATA_MAX_LEN, RX_FILTER_SOFT_USER_DATA_MAX_LEN,
            rx_ctrl, RX_FILTER_SOFT_USER_DATA_MAX_LEN);
        oal_set_netbuf_cb_len(netbuf, RX_FILTER_USER_DATA_MAX_LEN + RX_FILTER_SOFT_USER_DATA_MAX_LEN);
        oal_set_netbuf_deliv_flag(netbuf, OAL_TRUE);
        if (oal_netbuf_len(netbuf) > WLAN_MAX_NETBUF_SIZE) {
            oam_error_log1(0, OAM_SF_DPA, "dpe_wlan_rx_filter_input_is_from_dpa:: from dpa netbuf len %d > 1536",
                oal_netbuf_len(netbuf));
        }
        /* 透传帧都是单个传递 */
        dpe_wlan_filter_input_single(netbuf);
    }
}

void dpe_wlan_to_filter(oal_net_device_stru *net_dev, uint8_t vap_id, oal_netbuf_head_stru *netbuf_list)
{
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_id);
    mac_rx_ctl_stru *rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb(oal_netbuf_peek(netbuf_list));
    oal_netbuf_stru *ret_netbuf = NULL;

    /* DPE在DPA上转发 */
    /* 透传帧不会返回失败，直接传给filter，无需反压 */
    if (rx_ctrl->bit_transfer_from_dpa == 1) {
        dpe_wlan_rx_filter_input_is_from_dpa(net_dev, netbuf_list, rx_ctrl);
        return;
    }

    hmac_rx_get_input_netbuf_from_waitlist(dpe_vap, netbuf_list);
    oal_set_netbuf_next((oal_netbuf_tail(netbuf_list)), NULL);
    if (dpe_is_support_rx_filter_list() == OAL_TRUE) {
        ret_netbuf = dpe_wlan_filter_input_list(oal_netbuf_peek(netbuf_list), oal_netbuf_list_len(netbuf_list));
    } else {
        ret_netbuf = dpe_wlan_filter_input_single(oal_netbuf_peek(netbuf_list));
    }

    if (ret_netbuf != NULL) {
        mac_rx_ctl_stru *cb = (mac_rx_ctl_stru *)oal_netbuf_cb(ret_netbuf);
        oam_warning_log4(vap_id, OAM_SF_DPA, "dpe_wlan_to_filter::seq[%d] frm_ctl[%d] data_type[%d] link_id[%d]",
            cb->us_seq_num, cb->us_frame_control, cb->bit_data_type, cb->link_id);
        oam_warning_log2(vap_id, OAM_SF_DPA, "dpe_wlan_to_filter:: filter[%d] fail[%d]",
            rx_stats->rx_filter_input_cnt, rx_stats->rx_filter_input_fail_cnt);
        dpe_rx_save_netbuf_to_waitlist(dpe_vap, ret_netbuf);
        return;
    }
}
#endif
