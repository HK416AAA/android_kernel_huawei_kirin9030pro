/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : AMPDU聚合、BA处理接口定义源文件
 * 作    者 :
 * 创建日期 : 2014年11月25日
 */

/* 1 头文件包含 */
#include "hmac_rx_reorder.h"
#include "dpe_wlan_rx_reorder.h"
#include "wlan_spec.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "hmac_auto_adjust_freq.h"
#endif
#include "dpe_wlan_rx_reorder.h"
#include "dpe_wlan_vap.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_RX_REORDER_C

OAL_STATIC uint8_t hmac_ba_timeout_param_is_valid(hmac_ba_alarm_stru *alarm_data, dpe_wlan_vap_stru *dpe_vap,
    dpe_wlan_user_stru *dpe_user, uint8_t rx_tid)
{
    if (rx_tid >= WLAN_TID_MAX_NUM) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_ba_timeout_fn::tid %d overflow.}", rx_tid);
        return OAL_FALSE;
    }

    if (dpe_vap == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_ba_timeout_fn::vap[%d] NULL}", alarm_data->uc_vap_id);
        return OAL_FALSE;
    }

    if (dpe_user == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_ba_timeout_fn::user[%d] NULL}", alarm_data->us_mac_user_idx);
        return OAL_FALSE;
    }

    return OAL_TRUE;
}

/*
 * 函 数 名  : hmac_ba_flush_reorder_q
 * 功能描述  : 冲刷重排序队列
 * 1.日    期  : 2013年4月15日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_ba_flush_reorder_q(hmac_ba_rx_stru *pst_rx_ba)
{
    hmac_rx_buf_stru *pst_rx_buf = NULL;
    uint16_t us_index;
    oal_uint lock_flag;

    dpe_rx_reorder_lock_irq_save(&pst_rx_ba->st_ba_lock, &lock_flag);
    for (us_index = 0; us_index < WLAN_AMPDU_RX_HE_BUFFER_SIZE; us_index++) {
        pst_rx_buf = hmac_get_ba_rx_dhl(pst_rx_ba, us_index);
        if (pst_rx_buf->in_use == OAL_TRUE) {
            hmac_rx_free_netbuf_list(&pst_rx_buf->st_netbuf_head, pst_rx_buf->uc_num_buf);
            pst_rx_buf->in_use = OAL_FALSE;
            pst_rx_buf->uc_num_buf = 0;
            pst_rx_ba->uc_mpdu_cnt--;
        }
    }
    dpe_rx_reorder_unlock_irq_restore(&pst_rx_ba->st_ba_lock, &lock_flag);
    if (pst_rx_ba->uc_mpdu_cnt != 0) {
        oam_warning_log1(0, OAM_SF_DPA, "{hmac_ba_flush_reorder_q:: %d mpdu cnt left.}", pst_rx_ba->uc_mpdu_cnt);
    }
}

/*
 * 功能描述  : ba会话超时处理
 * 1.日    期  : 2013年4月12日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
int hmac_ba_timeout_fn(int p_arg)
#else
uint32_t hmac_ba_timeout_fn(void *p_arg)
#endif
{
    hmac_ba_rx_stru *pst_rx_ba = NULL;
    dpe_wlan_user_stru *dpe_user = NULL;
    dpe_wlan_vap_stru *dpe_vap = NULL;
    hmac_ba_alarm_stru *alarm_data = (hmac_ba_alarm_stru *)p_arg;
    mac_delba_initiator_enum_uint8 en_direction = alarm_data->en_direction;
    uint8_t rx_tid = alarm_data->uc_tid;
    uint32_t timeout = HMAC_BA_RX_DEFAULT_TIMEOUT;
    hmac_tid_ba_stru *hmac_tid = NULL;

    dpe_user = dpe_wlan_user_get(alarm_data->us_mac_user_idx);
    dpe_vap = dpe_wlan_vap_get(alarm_data->uc_vap_id);
    if (hmac_ba_timeout_param_is_valid(alarm_data, dpe_vap, dpe_user, rx_tid) != OAL_TRUE) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    hmac_tid = dpe_get_tid_ba_info(dpe_user->us_assoc_id, rx_tid);
    if (oal_any_null_ptr1(hmac_tid)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (en_direction == MAC_RECIPIENT_DELBA) {
        pst_rx_ba = (hmac_ba_rx_stru *)hmac_tid->pst_ba_rx_info;
        if (pst_rx_ba == NULL) {
            oam_error_log0(0, OAM_SF_DPA, "{hmac_ba_timeout_fn::pst_rx_ba is null.}");
            return OAL_ERR_CODE_PTR_NULL;
        }
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
        /* 接收业务量较少时只能靠超时定时器冲刷重排序队列,为改善游戏帧延时,需要将超时时间设小 */
        if (hmac_wifi_rx_is_busy() == OAL_FALSE) {
            timeout = dpe_vap->us_rx_timeout_min[WLAN_WME_TID_TO_AC(rx_tid)];
        } else {
            timeout = dpe_vap->us_rx_timeout[WLAN_WME_TID_TO_AC(rx_tid)];
        }
#endif
        if (pst_rx_ba->uc_mpdu_cnt > 0) {
            if (g_wlan_spec_cfg->rx_support_hw_reorder == OAL_TRUE) {
                hmac_ba_send_ring_reorder_timeout(pst_rx_ba, dpe_vap, alarm_data, &timeout);
            } else {
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
                hmac_ba_send_reorder_timeout(pst_rx_ba, dpe_vap, alarm_data, &timeout);
#endif
            }
        }

        /* 若重排序队列刷新后,依然有缓存帧则需要重启定时器;
           若重排序队列无帧则为了节省功耗不启动定时器,在有帧入队时重启 */
        if (pst_rx_ba->uc_mpdu_cnt > 0) {
            dpe_timer_spin_lock(&(hmac_tid->st_ba_timer_lock));
            /* 此处不需要判断定时器是否已经启动,如果未启动则启动定时器;
               如果此定时器已经启动 */
            frw_timer_create_timer_m(&(hmac_tid->st_ba_timer),
                hmac_ba_timeout_fn, timeout, alarm_data, OAL_FALSE, 2, dpe_vap->core_id); // 2 是reorder timer
            dpe_timer_spin_unlock(&(hmac_tid->st_ba_timer_lock));
        }
    } else {
        /* tx ba没有定时器 */
        oam_error_log1(0, OAM_SF_DPA, "{hmac_ba_timeout_fn::en_direction is %d.}", en_direction);
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_ba_reset_rx_handle
 * 功能描述  : 重置rx ba结构体
 * 1.日    期  : 2014年12月5日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_ba_reset_rx_handle(uint16_t user_idx, uint8_t uc_tid, oal_bool_enum_uint8 en_is_aging)
{
    hmac_ba_rx_stru *pst_ba_rx_info = NULL;
    hmac_tid_ba_stru *hmac_tid = NULL;

    if (uc_tid >= WLAN_TID_MAX_NUM) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_ba_reset_rx_handle::tid %d overflow.}", uc_tid);
        return OAL_ERR_CODE_ARRAY_OVERFLOW;
    }
    hmac_tid = dpe_get_tid_ba_info(user_idx, uc_tid);
    if (hmac_tid == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_ba_rx_info = hmac_tid->pst_ba_rx_info;
    if (oal_unlikely((pst_ba_rx_info == NULL) || (pst_ba_rx_info->en_is_ba != OAL_TRUE))) {
        oam_warning_log0(0, OAM_SF_DPA, "{hmac_ba_reset_rx_handle::rx ba not set yet.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* Step1: disable the flag of ba session */
    pst_ba_rx_info->en_is_ba = OAL_FALSE;

    /* Step2: flush reorder q */
    hmac_ba_flush_reorder_q(pst_ba_rx_info);
    /* step 3~4 goto hmac_rx_ba_reset_pre_handle */
    dpe_timer_spin_lock(&(hmac_tid->st_ba_timer_lock));
    /* Step5: Del Timer */
    if (hmac_tid->st_ba_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&(hmac_tid->st_ba_timer));
    }
    dpe_timer_spin_unlock(&(hmac_tid->st_ba_timer_lock));
    dpe_rx_reorder_lock_exit(&pst_ba_rx_info->st_ba_lock);
    /* Step6: Free rx handle */
    oal_mem_free_m(pst_ba_rx_info, OAL_TRUE);

    hmac_tid->pst_ba_rx_info = NULL;

    return OAL_SUCC;
}
