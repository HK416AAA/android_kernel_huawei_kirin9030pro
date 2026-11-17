/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : dpe_wlan_user.c
 * 作    者 :
 * 创建日期 : 2024年11月15日
 */

/* 1 头文件包含 */
#include "dpe_wlan_tid.h"
#include "dpe_wlan_resource.h"
#include "oam_ext_if.h"
#include "hmac_rx_reorder.h"
#include "hmac_tid_sche.h"
#include "hmac_tx_ring_alloc.h"
#include "hmac_tid_update.h"
#include "hmac_tid_ring_switch.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_WLAN_TID_C

hmac_tid_stru g_hmac_tid_res[WLAN_ASSOC_USER_MAX_NUM];
OAL_PL1_DATA uint32_t g_hmac_tid_res_bitmap = 0;

uint32_t *hmac_tid_get_res_bitmap(void)
{
    return &g_hmac_tid_res_bitmap;
}

void hmac_tid_res_init(void)
{
    memset_s(g_hmac_tid_res, sizeof(hmac_tid_stru) * WLAN_ASSOC_USER_MAX_NUM,
        0, sizeof(hmac_tid_stru) * WLAN_ASSOC_USER_MAX_NUM);
}

OAL_STATIC hmac_tid_stru *hmac_ml_user_alloc_tid_res(uint16_t user_idx)
{
#ifdef _PRE_WLAN_FEATURE_ML
    dpe_wlan_user_stru *dpe_user = NULL;
    dpe_wlan_user_stru *dpe_master_user = NULL;

    dpe_user = dpe_wlan_user_get(user_idx);
    if (dpe_user == NULL) {
        return NULL;
    }

    /* 非mld下ml_user_id为非法值0xFF，同hmac侧ml_user_manger == NULL */
    if (dpe_user->ml_user_id >= WLAN_USER_MAX_USER_LIMIT) {
        return NULL;
    }

    dpe_master_user = dpe_wlan_user_get(dpe_user->ml_user_id);
    if (dpe_master_user != NULL && dpe_master_user->tid_res != NULL) {
        return dpe_master_user->tid_res;
    }
#endif
    return NULL;
}

OAL_STATIC hmac_tid_stru *hmac_alloc_tid_res(uint16_t user_idx)
{
    uint8_t tid_res_id;
    uint8_t loop;
    hmac_tid_stru *tid_res = NULL;
    uint32_t *bitmap = hmac_tid_get_res_bitmap();

    tid_res = hmac_ml_user_alloc_tid_res(user_idx);
    if (tid_res != NULL) {
        oam_warning_log3(0, OAM_SF_DPA, "hmac_user_tid_init::res_id %d user_id %d bitmap 0x%x",
            tid_res->tid_res_id, user_idx, *bitmap);
        return tid_res;
    }

    tid_res_id = oal_bit_find_first_zero_four_byte(*bitmap);
    if (tid_res_id >= WLAN_ASSOC_USER_MAX_NUM) {
        oam_error_log1(0, OAM_SF_DPA, "hmac_alloc_tid_res:: tid_info_res_id[%d] error", tid_res_id);
        return NULL;
    }

    tid_res = &g_hmac_tid_res[tid_res_id];
    if (tid_res->work_flag != 0) {
        oam_error_log2(0, OAM_SF_DPA,
            "hmac_alloc_tid_res:: res_id[%d] work_flag[%d] error", tid_res_id, tid_res->work_flag);
    }

    for (loop = 0; loop < WLAN_TID_MAX_NUM; loop++) {
        if (tid_res->tid_ba[loop].st_ba_timer.en_is_registerd == OAL_TRUE) {
            frw_timer_immediate_destroy_timer_m(&(tid_res->tid_ba[loop].st_ba_timer));
        }
    }
    memset_s(tid_res, sizeof(hmac_tid_stru), 0, sizeof(hmac_tid_stru));
    oal_bit_set_bit_four_byte(bitmap, (oal_bitops)tid_res_id);
    tid_res->tid_res_id = tid_res_id;

    oam_warning_log3(0, OAM_SF_DPA, "hmac_user_tid_init::res_id %d user_id %d bitmap 0x%x",
        tid_res_id, user_idx, *bitmap);
    return tid_res;
}

OAL_STATIC void hmac_tid_ba_info_init(uint16_t user_idx, uint8_t tid)
{
    hmac_tid_ba_stru *tid_ba = NULL;

    tid_ba = dpe_get_tid_ba_info(user_idx, tid);
    if (tid_ba == NULL) {
        return;
    }
    tid_ba->uc_tid_no = tid;
    tid_ba->tx_ba_status = DMAC_BA_INIT;
    /* 初始化ba rx操作句柄 */
    tid_ba->pst_ba_rx_info = NULL;

    /* 初始化上一帧的seq num, 防止当前帧seq num为0时被误过滤 */
    tid_ba->qos_last_seq_frag_num = 0xffff;

    dpe_timer_lock_init(&(tid_ba->st_ba_timer_lock));
}
void hmac_tid_ba_info_deinit(uint16_t user_idx, uint8_t tid)
{
    hmac_tid_ba_stru *tid_ba = NULL;
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);
    if (dpe_user == NULL || dpe_user->en_is_multi_user == OAL_TRUE) {
        return;
    }
    tid_ba = dpe_get_tid_ba_info(user_idx, tid);
    if (tid_ba == NULL) {
        return;
    }
    dpe_timer_lock_exit(&(tid_ba->st_ba_timer_lock));
}
/*
 * 功能描述 : 初始化hmac user各tid
 * 1.日    期 : 2020年4月26日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
void dpe_wlan_user_tid_init(uint16_t user_idx)
{
    uint8_t tid;
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    hmac_tid_switch_list_dump(HMAC_TID_SWITCH_LIST_BEFORE_ADD_USER);
    hmac_tid_update_list_dump(HMAC_TID_UPDATE_LIST_BEFORE_ADD_USER);
    hmac_tid_sche_list_dump(HMAC_TID_SCHE_LIST_BEFORE_ADD_USER);
#endif
    if (dpe_user == NULL) {
        return;
    }
    dpe_user->tid_res = hmac_alloc_tid_res(dpe_user->us_assoc_id);
    if (oal_unlikely(dpe_user->tid_res == NULL)) {
        oam_error_log1(0, OAM_SF_DPA, "hmac_user_tid_init::user[%d] tid res null", dpe_user->us_assoc_id);
        return;
    }

    if (dpe_user->tid_res->work_flag != 0) { // 说明已初始化
        dpe_user->tid_res->work_flag++;
        return;
    }
    dpe_user->tid_res->work_flag++;

    for (tid = 0; tid < WLAN_TID_MAX_NUM; tid++) {
        if (dpe_user->en_is_multi_user == OAL_FALSE) {
            hmac_tid_ba_info_init(dpe_user->us_assoc_id, tid);
        }
        hmac_ring_tx_init(dpe_user->us_assoc_id, tid);
    }
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    hmac_tid_sche_list_dump(HMAC_TID_SCHE_LIST_AFTER_ADD_USER);
#endif
}

void dpe_user_tid_res_deinit(uint16_t user_idx)
{
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);
    hmac_tid_stru *tid_res = NULL;
    uint32_t *bitmap = hmac_tid_get_res_bitmap();

    if (dpe_user == NULL || dpe_user->tid_res == NULL) {
        return;
    }
    tid_res = dpe_user->tid_res;
    if (tid_res->work_flag == 0) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_user_tid_res_deinit:: work flag[%d] error!", tid_res->work_flag);
        return;
    }
    tid_res->work_flag--;
    /* 所有user都已释放该资源，对应bitmap可置为0 */
    if (tid_res->work_flag == 0) {
        hmac_clear_tid_queue(user_idx);
        oal_bit_clear_bit_four_byte(bitmap, (oal_bitops)tid_res->tid_res_id);
    }
}

void dpe_change_tid_ba_info(uint16_t cur_work_user_idx, uint16_t next_work_user_idx)
{
    uint8_t tid;
    hmac_tid_ba_stru *tid_ba = NULL;
    hmac_tid_info_stru *tid_info = NULL;
    dpe_wlan_user_stru *dpe_next_user = NULL;

    dpe_next_user = dpe_wlan_user_get(next_work_user_idx);
    if (dpe_next_user == NULL) {
        return;
    }

    /* 切换user下的tid信息 */
    for (tid = 0; tid < WLAN_TID_MAX_NUM; tid++) {
        tid_ba = dpe_get_tid_ba_info(cur_work_user_idx, tid);
        tid_info = dpe_get_tx_tid_info(cur_work_user_idx, tid);
        if (tid_info == NULL || tid_ba == NULL) {
            continue;
        }
        tid_info->user_index = next_work_user_idx;

        tid_ba->st_alarm_data.us_mac_user_idx = next_work_user_idx;
        tid_ba->st_alarm_data.uc_vap_id = dpe_next_user->uc_vap_id;
    }
}

hmac_tid_info_stru *dpe_get_tx_tid_info(uint16_t user_idx, uint8_t tid)
{
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);
    if (dpe_user == NULL || dpe_user->tid_res == NULL) {
        oam_warning_log1(0, OAM_SF_DPA, "dpe_get_tx_tid_info::tid res null user[%d]", user_idx);
        return NULL;
    }

    /* 不支持组播聚合的组播用户 没有ring和ba */
    if (dpe_wlan_is_multi_user_not_support_ampdu(dpe_user) == OAL_TRUE) {
        return NULL;
    }

    return &dpe_user->tid_res->tid_info[tid];
}

hmac_tid_ba_stru *dpe_get_tid_ba_info(uint16_t user_idx, uint8_t tid)
{
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);
    if (dpe_user == NULL || dpe_user->tid_res == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_get_tid_ba_info::tid res null user[%d]", user_idx);
        return NULL;
    }

    /* 不支持组播聚合的组播用户 没有ring和ba */
    if (dpe_wlan_is_multi_user_not_support_ampdu(dpe_user) == OAL_TRUE) {
        return NULL;
    }

    return &dpe_user->tid_res->tid_ba[tid];
}

/* hw reorder window init */
void hmac_ba_rx_win_init(hmac_tid_ba_stru *hmac_tid, hmac_ba_rx_stru *ba_rx_win,
    uint8_t vap_id, uint16_t assoc_id, uint8_t rx_tid)
{
    hmac_rx_buf_stru *pst_rx_buff = NULL;
    uint16_t index;

    for (index = 0; index < WLAN_AMPDU_RX_HE_BUFFER_SIZE; index++) {
        pst_rx_buff = hmac_get_ba_rx_dhl(ba_rx_win, index);
        pst_rx_buff->in_use = 0;
        pst_rx_buff->us_seq_num = 0;
        pst_rx_buff->uc_num_buf = 0;
        dpe_netbuf_list_head_init(&(pst_rx_buff->st_netbuf_head));
    }

    /* 初始化定时器资源 */
    hmac_tid->st_alarm_data.us_mac_user_idx = assoc_id;
    hmac_tid->st_alarm_data.uc_vap_id = vap_id;
    hmac_tid->st_alarm_data.uc_tid = rx_tid;
    hmac_tid->st_alarm_data.us_timeout_times = 0;
    hmac_tid->st_alarm_data.en_direction = MAC_RECIPIENT_DELBA;

    /* 1.1 BA接收窗口参数(SSN与窗口大小)由管理面收到BA请求帧后获取并同步到数据面 */
    ba_rx_win->us_last_relseq = mac_ba_seqno_sub(ba_rx_win->us_baw_start, 1);
    /* 1.2 其它窗口参数通过计算获取 */
    ba_rx_win->us_baw_end = mac_ba_seqno_add(ba_rx_win->us_baw_start, (ba_rx_win->us_baw_size - 1));
    ba_rx_win->us_baw_tail = mac_ba_seqno_sub(ba_rx_win->us_baw_start, 1);
    ba_rx_win->us_baw_head = mac_ba_seqno_sub(ba_rx_win->us_baw_start, HMAC_BA_BMP_SIZE);

    ba_rx_win->en_timer_triggered = OAL_FALSE;
    ba_rx_win->uc_mpdu_cnt = 0;
    ba_rx_win->en_is_ba = OAL_TRUE;  // Ba session is processing
    ba_rx_win->uc_mpdu_cnt = 0;

    memset_s(ba_rx_win->aul_rx_buf_bitmap, sizeof(ba_rx_win->aul_rx_buf_bitmap),
        0, sizeof(ba_rx_win->aul_rx_buf_bitmap));
    dpe_rx_reorder_lock_init(&ba_rx_win->st_ba_lock);
}

void dpe_wlan_rx_ba_init(hmac_ba_rx_para_stru *ba_rx)
{
    hmac_ba_rx_stru  *ba_rx_info = NULL;
    dpe_wlan_vap_stru *dpe_vap = NULL;
    hmac_tid_ba_stru *tid_ba = NULL;

    if (ba_rx == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_rx_ba_init::ba_rx_info is null!}");
        return;
    }

    dpe_vap = dpe_wlan_vap_get(ba_rx->uc_vap_id);
    tid_ba = dpe_get_tid_ba_info(ba_rx->us_assoc_id, ba_rx->uc_tid_no);
    if (tid_ba == NULL || dpe_vap == NULL) {
        return;
    }

    if (tid_ba->pst_ba_rx_info != NULL) {
        oam_warning_log2(0, OAM_SF_DPA,
            "{dpe_wlan_rx_ba_init::addba req received, user [%d] but tid [%d] already set up.}",
            ba_rx->us_assoc_id, ba_rx->uc_tid_no);
        /*  addba rsp发送失败, 再次收到addba req重新建立BA */
        hmac_ba_reset_rx_handle(ba_rx->us_assoc_id, ba_rx->uc_tid_no, OAL_FALSE);
    }
    /* 初始化rx addba聚合信息 */
    ba_rx_info = (hmac_ba_rx_stru *)oal_mem_alloc_m(OAL_MEM_POOL_ID_LOCAL, (uint16_t)sizeof(hmac_ba_rx_stru), OAL_TRUE);
    if (ba_rx_info == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_mgmt_rx_addba_req::alloc fail. tid[%d].}", ba_rx->uc_tid_no);
        return;
    }

    /* Ba会话参数初始化 */
    ba_rx_info->en_ba_status = DMAC_BA_INIT;

    /* 初始化接收窗口 */
    ba_rx_info->us_baw_start = ba_rx->us_baw_start;
    ba_rx_info->us_baw_size = ba_rx->us_baw_size;
    hmac_ba_rx_win_init(tid_ba, ba_rx_info, ba_rx->uc_vap_id, ba_rx->us_assoc_id, ba_rx->uc_tid_no);

    ba_rx_info->uc_lut_index = ba_rx->uc_lut_index;
    /* profiling测试中，接收端不删除ba */
    frw_timer_create_timer_m(&(tid_ba->st_ba_timer), hmac_ba_timeout_fn,
        dpe_vap->us_rx_timeout[WLAN_WME_TID_TO_AC(ba_rx->uc_tid_no)],
        &(tid_ba->st_alarm_data), OAL_FALSE, 2, dpe_vap->uc_chip_id); // 2 是reorder timer

    /* 初始化完成 */
    ba_rx_info->en_ba_status = DMAC_BA_COMPLETE;
    tid_ba->pst_ba_rx_info = ba_rx_info;
}

void hmac_clear_tid_queue(uint16_t us_assoc_id)
{
    uint8_t tidno;
    hmac_tid_ba_stru *tid = NULL;
    dpe_wlan_user_stru *user = (dpe_wlan_user_stru *)dpe_wlan_user_get(us_assoc_id);
    if (user == NULL || user->tid_res == NULL) {
        return;
    }

    dpe_wlan_user_list_free(user);

    for (tidno = 0; tidno < WLAN_TID_MAX_NUM; tidno++) {
        tid = &user->tid_res->tid_ba[tidno];
        tid->uc_tid_no = (uint8_t)tidno;

        /* 清除接收方向会话句柄 */
        if (tid->pst_ba_rx_info != NULL) {
            hmac_ba_reset_rx_handle(us_assoc_id, tidno, OAL_TRUE);
        }
    }
}

void dpe_wlan_tid_ba_sync(uint8_t *tid_data)
{
    dmac_ctx_action_event_stru *ba_info = (dmac_ctx_action_event_stru *)tid_data;
    hmac_tid_ba_stru *tid_ba_info = dpe_get_tid_ba_info(ba_info->us_user_idx, ba_info->uc_tidno);
    if (tid_ba_info == NULL) {
        oam_error_log3(0, OAM_SF_DPA, "{dpe_wlan_tid_ba_sync::user[%d]tid[%d] bawsize[%d] tid ba info null.}",
            ba_info->us_user_idx, ba_info->uc_tidno, ba_info->us_baw_size);
        return;
    }

    if ((ba_info->uc_action == MAC_BA_ACTION_ADDBA_RSP) && (ba_info->uc_status == MAC_SUCCESSFUL_STATUSCODE)) {
        tid_ba_info->tx_ba_status = DMAC_BA_COMPLETE;
        oam_warning_log4(0, OAM_SF_DPA, "{dpe_wlan_tid_ba_sync::user[%d]tid[%d] bawsize[%d] succ %d.}",
            ba_info->us_user_idx, ba_info->uc_tidno, ba_info->us_baw_size, tid_ba_info->tx_ba_status);
        return;
    }

    tid_ba_info->tx_ba_status = DMAC_BA_INIT;
}
