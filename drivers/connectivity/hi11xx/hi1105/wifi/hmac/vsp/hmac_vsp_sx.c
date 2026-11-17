/*
 * Copyright (c) @CompanyNameMagicTag 2021-2025. All rights reserved.
 * 功能说明   : vsp sx发送流程
 * 作者       : wifi
 * 创建日期   : 2020年12月24日
 */
#include "hmac_vsp_source.h"
#include "hmac_vsp_buf.h"
#include "hmac_vsp_flow_ctrl.h"
#include "hmac_tx_data.h"
#include "hmac_tx_ring_alloc.h"
#include "hmac_host_ring_tx.h"
#include "hmac_tx_data.h"
#include "hmac_vsp_if.h"
#include "hmac_vsp_sx.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_VSP_SX_C

#ifdef _PRE_WLAN_FEATURE_VSP
uint32_t hmac_vsp_source_thread_init(hmac_vsp_source_stru *source);
bool hmac_vsp_set_evt_flag(hmac_vsp_source_stru *source, enum vsp_source_event evt);
void hmac_vsp_set_netbuf_cb(oal_netbuf_stru *netbuf, hmac_vsp_info_stru *vsp_info, uint8_t tidno);
uint32_t hmac_vsp_set_txop_limit(mac_vap_stru *mac_vap, uint32_t switch_value);

static void hmac_vsp_sx_queue_init(hmac_vsp_source_stru *source)
{
    hmac_vsp_slice_queue_init(&source->sx_free_queue);
    hmac_vsp_slice_queue_init(&source->sx_comp_queue);
}
OAL_STATIC uint32_t hmac_vsp_sx_init(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user)
{
    hmac_vsp_source_stru *source = hmac_vsp_get_vsp_source();

    hmac_vsp_sx_queue_init(source);

    return hmac_vsp_source_thread_init(source);
}

uint32_t hmac_vsp_sx_cfg(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, vsp_param *param)
{
    hmac_vsp_info_stru *vsp_info = hmac_vsp_get_common_info();
    hmac_vsp_source_stru *source = hmac_vsp_get_vsp_source();

    if (oal_any_null_ptr4(hmac_vap, hmac_user, param, vsp_info)) {
        return OAL_FAIL;
    }

    if (!hmac_host_ring_tx_enabled()) {
        return OAL_FAIL;
    }

    if (hmac_vsp_init(vsp_info, hmac_vap, hmac_user, param, VSP_MODE_SX) != OAL_SUCC) {
        return OAL_FAIL;
    }
    if (hmac_vsp_mode_init(vsp_info, hmac_vap, hmac_user, param, VSP_MODE_SX) != OAL_SUCC) {
        return OAL_FAIL;
    }
    source->vsp_base = vsp_info;

    if (hmac_vsp_sx_init(hmac_vap, hmac_user) != OAL_SUCC) {
        hmac_vsp_deinit(source->vsp_base, VSP_MODE_SX);
        return OAL_FAIL;
    }

    if (hmac_vsp_context_init(source->vsp_base, hmac_vap, hmac_user, VSP_MODE_SX) != OAL_SUCC) {
        hmac_vsp_deinit(source->vsp_base, VSP_MODE_SX);
        oam_error_log0(0, 0, "hmac_vsp_source_cfg:hmac_vsp_context_init FAIL!");
        return OAL_FAIL;
    }
    hmac_vsp_set_current_handle(source->vsp_base);

    return OAL_SUCC;
}

uint32_t hmac_vsp_sx_batch_init(hmac_vsp_source_stru *source, tx_layer_ctrl *layer)
{
    hmac_vsp_tx_sx_batch_stru *batch = oal_memalloc(sizeof(hmac_vsp_tx_sx_batch_stru));
    uint32_t cur_tsf = hmac_vsp_get_timestamp(source->vsp_base);

    if (batch == NULL) {
        oam_error_log0(0, 0, "hmac_vsp_source_prepare_slice::alloc batch queue entry failed");
        return OAL_FAIL;
    }

    batch->head = layer;
    batch->arrive_ts = cur_tsf;
    memset_s(&batch->tx_result, sizeof(send_result), 0, sizeof(send_result));
    batch->tx_result.layer_list = layer;
    hmac_vsp_batch_enqueue(&source->sx_free_queue, batch);

    hmac_vsp_set_evt_flag(source, VSP_SRC_EVT_NEW_BATCH);

    return OAL_SUCC;
}

void hmac_vsp_set_batch_pktnum(oal_netbuf_stru *netbuf, uint16_t batch_id, uint8_t pkt_num)
{
    mac_tx_ctl_stru *tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (tx_ctl == NULL) {
        return;
    }

    tx_ctl->uc_hid2d_tx_delay_time = pkt_num;
    tx_ctl->st_expand_cb.us_seqnum = batch_id;
}
uint8_t hmac_vsp_sx_netbuf_get_batch_pktnum(oal_netbuf_stru *netbuf)
{
    mac_tx_ctl_stru *tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (tx_ctl == NULL) {
        return 0;
    }

    return tx_ctl->uc_hid2d_tx_delay_time;
}
uint16_t hmac_vsp_sx_netbuf_get_batch_id(oal_netbuf_stru *netbuf)
{
    mac_tx_ctl_stru *tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (tx_ctl == NULL) {
        return 0;
    }

    return tx_ctl->st_expand_cb.us_seqnum;
}

#define MAX_BATCH_NUM (64)
uint32_t hmac_vsp_tx_batch(hmac_vsp_info_stru *vsp_info, hmac_vsp_tx_sx_batch_stru *batch)
{
    oal_netbuf_stru *current_msdu;
    oal_netbuf_stru *next_msdu = NULL;
    uint8_t pkt_num = 0;
    uint32_t ret;

    current_msdu = (oal_netbuf_stru *)batch->head->netbuf;
    if (oal_unlikely(current_msdu == NULL)) {
        oam_error_log0(0, 0, "{hmac_vsp_tx_batch::tx_layer_ctrl netbuf=null!");
        return OAL_FAIL;
    }

    while (current_msdu) {
        next_msdu = oal_netbuf_next(current_msdu);
        oal_netbuf_next(current_msdu) = NULL;
        oal_netbuf_prev(current_msdu) = NULL;
        if (pkt_num >= MAX_BATCH_NUM) {
            oam_error_log1(0, 0, "{hmac_vsp_tx_batch::batch[%d] pkt>64!", batch->head->batch_id);
            oal_netbuf_free(current_msdu);
            hmac_free_netbuf_list(next_msdu);
            return OAL_SUCC;
        }
        if (vsp_info->hmac_vap == NULL || vsp_info->hmac_user == NULL) {
            oam_error_log0(0, 0, "{hmac_vsp_tx_batch::vap or user is null!}");
            oal_netbuf_free(current_msdu);
            hmac_free_netbuf_list(next_msdu);
            return OAL_FAIL;
        }
        hmac_vsp_set_netbuf_cb(current_msdu, vsp_info, WLAN_TIDNO_VIDEO);
        hmac_vsp_set_batch_pktnum(current_msdu, batch->head->batch_id, pkt_num);
        pkt_num++;
        ret = hmac_tx_lan_to_wlan_no_tcp_opt(hmac_vsp_info_get_mac_vap(vsp_info), &current_msdu);
        if (ret != OAL_SUCC) {
            oam_error_log3(0, 0, "{hmac_vsp_tx_batch::batch[%d]pkt[%d]tx fail ret[%d]}",
                batch->head->batch_id, pkt_num, ret);
            oal_netbuf_free(current_msdu);
        }
        current_msdu = next_msdu;
    }
    batch->head->netbuf = NULL;
    batch->pkt_num = pkt_num;
    hmac_vsp_log((uint8_t *)batch, VSP_LOG_BITMAP_SLICE_INFO, VSP_LOG_DATATYPE_BATCH, VSP_LOG_TYPE_NEW_BATCH);

    return OAL_SUCC;
}

void hmac_vsp_new_batch_handler(hmac_vsp_source_stru *source)
{
    hmac_vsp_tx_sx_batch_stru *batch = NULL;
    unsigned long flags = 0;

    oal_spin_lock_irq_save(&source->vsp_base->vsp_lock, &flags);
    while (!hmac_vsp_slice_queue_empty(&source->sx_free_queue)) {
        batch = hmac_vsp_batch_dequeue(&source->sx_free_queue);
        if (hmac_vsp_tx_batch(source->vsp_base, batch) != OAL_SUCC) {
            oam_error_log1(0, 0, "{hmac_vsp_new_batch_handler, batch[%d] TX FAIL}", batch->head->batch_id);
            vsp_sx_tx_send_done(&batch->tx_result);
            oal_free(batch);
            continue;
        }

        hmac_vsp_batch_enqueue(&source->sx_comp_queue, batch);
    }
    oal_spin_unlock_irq_restore(&source->vsp_base->vsp_lock, &flags);
}

static void hmac_vsp_sx_batch_pkt_update(hmac_vsp_source_stru *source, hmac_vsp_tx_sx_batch_stru *batch,
    uint16_t batch_id, uint8_t pkt_num)
{
    uint8_t byte_idx;
    uint8_t byte_pos;
    if (pkt_num >= MAX_BATCH_NUM) {
        oam_warning_log2(0, 0, "hmac_vsp_sx_batch_pkt_update:batch[%d]pkt[%d] invalid", batch_id, pkt_num);
        return;
    }
    byte_idx = pkt_num / 8; // 8
    byte_pos = pkt_num % 8; // 8
    batch->tx_result.tx_succ_packet_number++;
    batch->tx_result.tx_result[byte_idx] |= BIT(byte_pos);
    oam_warning_log2(0, 0, "hmac_vsp_sx_batch_pkt_update:batch[%d]pkt[%d]", batch_id, pkt_num);
}

static void hmac_vsp_sx_batch_compl_process(hmac_vsp_source_stru *source, hmac_vsp_tx_sx_batch_stru *batch,
    uint32_t cur_tsf)
{
    hmac_vsp_tx_sx_batch_stru *batch_tmp = NULL;

    batch->tx_result.tx_delay = cur_tsf - batch->arrive_ts;

    batch_tmp = hmac_vsp_batch_dequeue(&source->sx_comp_queue);
    if (batch_tmp != batch) {
        oam_error_log2(0, 0, "{hmac_vsp_sx_batch_compl_process::batch mismatch [%llx] [%llx]}",
            (uintptr_t)batch, (uintptr_t)batch_tmp);
    }

    hmac_vsp_log((uint8_t *)batch, VSP_LOG_BITMAP_SLICE_INFO, VSP_LOG_DATATYPE_BATCH_RTT, VSP_LOG_TYPE_BATCH_COMP);

    vsp_sx_tx_send_done(&batch->tx_result);
    oal_free(batch);
}

static void hmac_vsp_sx_tx_complete_netbuf_process(hmac_vsp_source_stru *source, hmac_tid_info_stru *tid_info,
    hmac_msdu_info_ring_stru *tx_ring, un_rw_ptr release_ptr, uint32_t cur_tsf)
{
    hmac_vsp_tx_sx_batch_stru *batch = NULL;
    uint16_t batch_id;
    uint8_t pkt_num;
    mac_tx_ctl_stru *tx_ctl = NULL;
    oal_netbuf_stru *netbuf = hmac_tx_ring_get_netbuf(tx_ring, release_ptr);
    if (oal_unlikely(netbuf == NULL)) {
        oam_error_log3(0, 0, "{hmac_vsp_sx_tx_complete_netbuf_process::user[%d] tid[%d] index[%d] netbuf null}",
            tid_info->user_index, tid_info->tid_no, release_ptr.rw_ptr);
        return;
    }
    tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    batch_id = hmac_vsp_sx_netbuf_get_batch_id(netbuf);
    pkt_num = hmac_vsp_sx_netbuf_get_batch_pktnum(netbuf);

    hmac_tx_ring_unmap_netbuf(tx_ring, netbuf, release_ptr.st_rw_ptr.bit_rw_ptr);
    oal_netbuf_free(netbuf);

    if (hmac_vsp_slice_queue_empty(&source->sx_comp_queue)) {
        oam_error_log0(0, 0, "{hmac_vsp_sx_tx_complete_netbuf_process::comp queue is empty!}");
        return;
    }
    batch = hmac_vsp_batch_queue_peek(&source->sx_comp_queue);
    if (batch == NULL) {
        oam_error_log0(0, 0, "{hmac_vsp_sx_tx_complete_netbuf_process::batch NULL!}");
        return;
    }
    if (batch_id != batch->head->batch_id) {
        oam_error_log3(0, 0, "{hmac_vsp_sx_tx_complete_netbuf_process::batch id[%d] pkt[%d] invalid! curr batch[%d]}",
            batch_id, pkt_num, batch->head->batch_id);
        return;
    }
    hmac_vsp_sx_batch_pkt_update(source, batch, batch_id, pkt_num);

    if (pkt_num < batch->pkt_num - 1) {
        return;
    }
    // 最后一个pkt 代表一个batch发送完成
    hmac_vsp_sx_batch_compl_process(source, batch, cur_tsf);
}

void hmac_vsp_sx_tx_complete_handler(hmac_vsp_source_stru *source)
{
    hmac_tid_info_stru *tid_info = source->vsp_base->tid_info[VSP_TYPE_SX];
    hmac_msdu_info_ring_stru *tx_ring = &source->vsp_base->tid_info[VSP_TYPE_SX]->tx_ring;
    un_rw_ptr release_ptr, target_ptr;
    unsigned long flags = 0;
    uint32_t cur_tsf = hmac_vsp_get_timestamp(source->vsp_base);
    uint32_t msdu_cnt = 0;
    /*
        spin lock锁范围内不允许上下文切换
        tx complete流程会调用到stop timer写common timer寄存器，前提得唤醒dev
        而hal_pm_try_wakeup_dev_lock是允许线程睡眠，所以需要将hal_pm_try_wakeup_dev_lock提前到spin lock前
    */
    hal_pm_try_wakeup_forbid_sleep(HAL_PM_FORBIDE_SLEEP_VSP_TX_COMPLETE);
    if (hal_pm_try_wakeup_dev_lock() != OAL_SUCC) {
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_TX_COMPLETE);
        return;
    }
    oal_mutex_lock(&tx_ring->tx_lock);
    oal_spin_lock_irq_save(&source->vsp_base->vsp_lock, &flags);
    release_ptr.rw_ptr = tx_ring->release_index;
    target_ptr.rw_ptr = tx_ring->base_ring_info.read_index;
    while (hal_tx_rw_ptr_compare(release_ptr, target_ptr) == RING_PTR_SMALLER) {
        hmac_vsp_sx_tx_complete_netbuf_process(source, tid_info, tx_ring, release_ptr, cur_tsf);
        hmac_tx_reset_msdu_info(tx_ring, release_ptr);
        hmac_tx_msdu_ring_inc_release_ptr(tx_ring);
        release_ptr.rw_ptr = tx_ring->release_index;
        msdu_cnt++;
    }
    hmac_tx_msdu_update_free_cnt(tx_ring, msdu_cnt);
    oal_spin_unlock_irq_restore(&source->vsp_base->vsp_lock, &flags);
    oal_mutex_unlock(&tx_ring->tx_lock);
    hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_TX_COMPLETE);
}

OAL_STATIC void hmac_vsp_sx_queue_deinit(hmac_vsp_source_stru *source)
{
    hmac_vsp_tx_sx_batch_stru *batch = NULL;
    unsigned long flags = 0;

    oal_spin_lock_irq_save(&source->vsp_base->vsp_lock, &flags);
    while (!hmac_vsp_slice_queue_empty(&source->sx_free_queue)) {
        batch = hmac_vsp_batch_dequeue(&source->sx_free_queue);
        if (batch == NULL) {
            continue;
        }
        oal_io_print("[vsp sx]free_queue DEQUEUE batch[%d]", batch->head->batch_id);
        vsp_sx_tx_send_done(&batch->tx_result);
        oal_free(batch);
    }
    while (!hmac_vsp_slice_queue_empty(&source->sx_comp_queue)) {
        batch = hmac_vsp_batch_dequeue(&source->sx_comp_queue);
        if (batch == NULL) {
            continue;
        }
        oal_io_print("[vsp sx]comp_queue DEQUEUE batch[%d]", batch->head->batch_id);
        vsp_sx_tx_send_done(&batch->tx_result);
        oal_free(batch);
    }
    oal_spin_unlock_irq_restore(&source->vsp_base->vsp_lock, &flags);
}

void hmac_vsp_sx_stop(void)
{
    hmac_vsp_source_stru *source = hmac_vsp_get_vsp_source();

    source->vsp_base->enable &= ~(BIT(VSP_TYPE_SX)); // 先置位 stop过程中下发新帧直接返回失败 不处理
    hmac_vsp_sx_queue_deinit(source);

    hmac_vsp_context_deinit(source->vsp_base, VSP_MODE_SX);

    hmac_vsp_deinit(source->vsp_base, VSP_MODE_SX);
}
#endif /* _PRE_WLAN_FEATURE_VSP */
