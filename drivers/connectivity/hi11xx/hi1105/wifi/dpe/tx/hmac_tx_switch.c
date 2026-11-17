/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : host/device ring tx切换模块
 * 作    者 : wifi
 * 创建日期 : 2020年11月25日
 */

#include "hmac_tx_switch.h"
#include "hmac_tx_switch_fsm.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "hmac_config.h"
#include "chr_errno.h"
#endif
#include "hmac_tx_msdu_dscr.h"
#include "dpe_tx_data.h"
#include "plat_pm_wlan.h"
#include "hmac_host_ring_tx.h"
#include "host_hal_ext_if.h"
#include "hmac_tid_ring_switch.h"
#include "hmac_tid_sche.h"
#include "dpe_wlan_config.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_TX_SWITCH_C

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
OAL_STATIC uint32_t dpe_tx_switch_send_event(uint8_t vap_idx, hmac_tid_info_stru *tid_info, uint8_t mode,
    tx_state_switch_stru *payload)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_idx);
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_tx_switch_send_event::get dpe_vap fail!");
        return OAL_FAIL;
    }
    return dpe_config_sync_device_send_event(dpe_vap, WLAN_CFGID_TX_SWITCH_START, (uint8_t *)payload,
        sizeof(tx_state_switch_stru));
}
#else
OAL_STATIC uint32_t host_tx_switch_send_event(uint8_t vap_idx, hmac_tid_info_stru *tid_info, uint8_t mode,
    tx_state_switch_stru *param)
{
    uint32_t ret = OAL_SUCC;
    ret = hmac_config_send_event_adapt_dpe(vap_idx, WLAN_CFGID_TX_SWITCH_START,
        sizeof(tx_state_switch_stru), (uint8_t *)param);
    if (ret != OAL_SUCC) {
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_WIFI, CHR_LAYER_DRV,
                             CHR_WIFI_DRV_EVENT_RING_TX, CHR_WIFI_DRV_ERROR_TX_RING_SWITCH);
        oam_warning_log3(0, OAM_SF_DPA, "{host_tx_switch_send_event::user[%d] tid[%d] switch to [%d] failed}",
            tid_info->user_index, tid_info->tid_no, mode);
    }
    return ret;
}
#endif

OAL_STATIC uint32_t hmac_tx_switch_send_event(uint8_t vap_idx, hmac_tid_info_stru *tid_info, uint8_t mode)
{
    uint32_t ret = OAL_SUCC;
    tx_state_switch_stru param = {
        .user_id = tid_info->user_index,
        .tid_no = tid_info->tid_no,
        .cmd = mode,
    };
    param.tid_num = g_tid_switch_list.tid_list_count;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    ret = dpe_tx_switch_send_event(vap_idx, tid_info, mode, &param);
#else
    ret = host_tx_switch_send_event(vap_idx, tid_info, mode, &param);
#endif
    return ret;
}

static uint32_t hmac_tx_mode_d2h_switch_nolock(hmac_tid_info_stru *tid_info)
{
    if (oal_atomic_read(&tid_info->ring_tx_mode) != DEVICE_RING_TX_MODE) {
        return OAL_SUCC;
    }

    oal_atomic_set(&tid_info->ring_tx_mode, D2H_SWITCHING_MODE);

    if (hmac_tx_switch_send_event(0, tid_info, HOST_RING_TX_MODE) != OAL_SUCC) {
        oal_atomic_set(&tid_info->ring_tx_mode, DEVICE_RING_TX_MODE);
        return OAL_FAIL;
    }

    oam_warning_log4(0, OAM_SF_DPA, "{hmac_tx_mode_d2h_switch::user[%d] tid[%d] low_th[%d] high_th[%d] switching...}",
        tid_info->user_index, tid_info->tid_no, HMAC_PSM_TX_SWITCH_LOW_PPS, HMAC_PSM_TX_SWITCH_HIGH_PPS);

    return OAL_SUCC;
}

uint32_t hmac_tx_mode_d2h_switch(hmac_tid_info_stru *tid_info)
{
    uint32_t ret;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_uint lock_flag, lock_flag_tx_comp;
#endif

    dpe_tid_tx_lock_irq_save(&tid_info->tx_ring.tx_lock, &lock_flag);
    dpe_tid_tx_comp_lock_irq_save(&tid_info->tx_ring.tx_comp_lock, &lock_flag_tx_comp);

    ret = hmac_tx_mode_d2h_switch_nolock(tid_info);

    dpe_tid_tx_comp_unlock_irq_restore(&tid_info->tx_ring.tx_comp_lock, &lock_flag_tx_comp);
    dpe_tid_tx_unlock_irq_restore(&tid_info->tx_ring.tx_lock, &lock_flag);

    return ret;
}

static inline uint8_t hmac_tx_mode_h2d_switch_allowed(hmac_msdu_info_ring_stru *tx_ring)
{
    un_rw_ptr release_ptr = { .rw_ptr = tx_ring->release_index};
    un_rw_ptr write_ptr = { .rw_ptr = tx_ring->base_ring_info.write_index };

    return !oal_atomic_read(&tx_ring->msdu_cnt) && hal_tx_rw_ptr_compare(write_ptr, release_ptr) == RING_PTR_EQUAL;
}

void hmac_tx_mode_h2d_switch_process(hmac_tid_info_stru *tid_info)
{
    hmac_msdu_info_ring_stru *tx_ring = &tid_info->tx_ring;
    if (oal_atomic_read(&tid_info->ring_tx_mode) != H2D_SWITCHING_MODE) {
        return;
    }

    if (!hmac_tx_mode_h2d_switch_allowed(&tid_info->tx_ring)) {
        return;
    }

    if (hmac_tx_switch_send_event(0, tid_info, DEVICE_RING_TX_MODE) != OAL_SUCC) {
        oal_atomic_set(&tid_info->ring_tx_mode, HOST_RING_TX_MODE);
        return;
    }
    if (tid_info->is_write_tx_ring_table == OAL_FALSE) {
        hmac_tx_reg_write_ring_info(tid_info, TID_CMDID_CREATE, OAL_FALSE);
    }

    oal_atomic_set(&tid_info->ring_tx_mode, H2D_SWITCHING_MODE_STAGE2);

    oam_warning_log4(0, OAM_SF_DPA, "{hmac_tx_mode_h2d_switch_process::tid[%d] release[%d] rptr[%d], wptr[%d]}",
        tid_info->tid_no, tx_ring->release_index, tx_ring->base_ring_info.read_index,
        tx_ring->base_ring_info.write_index);
}

static void hmac_tx_mode_h2d_switch_nolock(hmac_tid_info_stru *tid_info)
{
    if (oal_atomic_read(&tid_info->ring_tx_mode) != HOST_RING_TX_MODE) {
        return;
    }

    oal_atomic_set(&tid_info->ring_tx_mode, H2D_SWITCHING_MODE);
    hmac_tx_mode_h2d_switch_process(tid_info);
}

uint32_t hmac_tx_mode_h2d_switch(hmac_tid_info_stru *tid_info)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_uint lock_flag, lock_flag_tx_comp;
#endif

    dpe_tid_tx_lock_irq_save(&tid_info->tx_ring.tx_lock, &lock_flag);
    dpe_tid_tx_comp_lock_irq_save(&tid_info->tx_ring.tx_comp_lock, &lock_flag_tx_comp);

    hmac_tx_mode_h2d_switch_nolock(tid_info);

    dpe_tid_tx_comp_unlock_irq_restore(&tid_info->tx_ring.tx_comp_lock, &lock_flag_tx_comp);
    dpe_tid_tx_unlock_irq_restore(&tid_info->tx_ring.tx_lock, &lock_flag);

    return OAL_SUCC;
}

void hmac_tx_mode_switch_dump(hmac_tid_info_stru *tid_info)
{
    oam_warning_log4(0, OAM_SF_DPA, "{hmac_tx_mode_switch_dump:: tid[%d] release_ptr[%d] rptr[%d] wptr[%d]}",
        tid_info->tid_no, tid_info->tx_ring.release_index, tid_info->tx_ring.base_ring_info.read_index,
        tid_info->tx_ring.base_ring_info.write_index);

    oam_warning_log4(0, OAM_SF_DPA, "{hmac_tx_mode_switch_dump::tx_mode[%d] sync_th[%d] sync_cnt[%d] sche_th[%d]}",
        oal_atomic_read(&tid_info->ring_tx_mode), oal_atomic_read(&tid_info->tx_ring.ring_sync_th),
        tid_info->tx_ring.ring_sync_cnt, oal_atomic_read(&tid_info->tid_sche_th));

    oam_warning_log3(0, OAM_SF_DPA,
        "{hmac_tx_mode_switch_dump::tid_len[%d] ring_msdu_cnt[%d] last_period_tx_msdu[%d]}",
        oal_netbuf_list_len(&tid_info->tid_queue), oal_atomic_read(&tid_info->tx_ring.msdu_cnt),
        oal_atomic_read(&tid_info->tx_ring.last_period_tx_msdu));
}

void hmac_tx_mode_switch_dump_process(hmac_tid_info_stru *tid_info)
{
    hmac_tx_mode_switch_dump(tid_info);
    hmac_tx_switch_send_event(0, tid_info, TX_MODE_DEBUG_DUMP);
}

static inline oal_bool_enum_uint8 hmac_tx_mode_switch_ring_ptr_abnormal(hmac_tid_info_stru *tid_info)
{
    return ((tid_info->tx_ring.base_ring_info.read_index != tid_info->tx_ring.base_ring_info.write_index) ||
           (tid_info->tx_ring.base_ring_info.read_index != tid_info->tx_ring.release_index)) ? OAL_TRUE : OAL_FALSE;
}

static void hmac_tx_ring_sw_ptr_reset(hmac_tid_info_stru *tid_info)
{
    hal_host_tx_ring_ops_param_stru param = {
        .tx_ring_table_addr = tid_info->tx_ring.tx_ring_table_addr.addr_val,
        .val = 0,
        .lut_idx = tid_info->lut_index,
        .tid = tid_info->tid_no,
    };

    hal_host_tx_ring_update_ops(&param, HAL_HOST_TX_UPDATE_SW_WPTR);
    hal_host_tx_ring_update_ops(&param, HAL_HOST_TX_UPDATE_SW_RPTR);
    hal_host_tx_ring_update_ops(&param, HAL_HOST_TX_UPDATE_SW_ML1_RPTR);
}

static inline void hmac_tx_mode_switch_ring_ptr_reset(hmac_tid_info_stru *tid_info)
{
    tid_info->tx_ring.base_ring_info.read_index = 0;
    tid_info->tx_ring.base_ring_info.write_index = 0;
    tid_info->tx_ring.release_index = 0;
    hmac_tx_ring_sw_ptr_reset(tid_info);
}

void hmac_tx_complete_tid_ring_ptr_reset(hmac_tid_info_stru *tid_info)
{
    hmac_tx_mode_switch_dump(tid_info);
    hmac_tx_mode_switch_ring_ptr_reset(tid_info);
}

OAL_STATIC void hmac_tx_mode_d2h_switch_process(hmac_tid_info_stru *tid_info)
{
    if (!oal_atomic_read(&tid_info->tx_ring.inited)) {
        oam_warning_log2(0, OAM_SF_DPA, "{hmac_tx_mode_d2h_switch_process::user[%d] tid[%d] already deinited}",
            tid_info->user_index, tid_info->tid_no);
        return;
    }

    if (hmac_tx_mode_switch_ring_ptr_abnormal(tid_info) == OAL_TRUE) {
        hmac_tx_mode_switch_dump(tid_info);
        hmac_tx_mode_switch_ring_ptr_reset(tid_info);
    }

    hmac_tx_reg_write_ring_info(tid_info, TID_CMDID_CREATE, OAL_TRUE);
}

OAL_STATIC void hmac_tx_mode_switch_comp_process(hmac_tid_info_stru *tid_info, tx_state_switch_stru *tx_switch_param)
{
    if (tx_switch_param->cmd == oal_atomic_read(&tid_info->ring_tx_mode)) {
        oam_warning_log3(0, OAM_SF_DPA,
            "{hmac_tx_mode_switch_process::user[%d] tid[%d] target[%d] is the same as current mode",
            tx_switch_param->user_id, tx_switch_param->tid_no, tx_switch_param->cmd);
        return;
    }

    oam_warning_log3(0, OAM_SF_DPA, "{hmac_tx_mode_switch_process::user[%d] tid[%d] mode[%d]}",
        tx_switch_param->user_id, tx_switch_param->tid_no, tx_switch_param->cmd);

    if (tx_switch_param->cmd == HOST_RING_TX_MODE) {
        hmac_tx_mode_d2h_switch_process(tid_info);
    }

    oal_smp_mb();

    oal_atomic_set(&tid_info->ring_tx_mode, tx_switch_param->cmd);
}

uint32_t dpe_tx_mode_switch_process(uint8_t *tx_switch_param_data)
{
    tx_state_switch_stru *tx_switch_param = (tx_state_switch_stru *)tx_switch_param_data;
    hmac_tid_info_stru *tid_info = NULL;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_uint lock_flag, lock_flag_tx_comp;
#endif

    if (tx_switch_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_tx_mode_switch_process::tx_switch_param null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (tx_switch_param->user_id >= WLAN_USER_MAX_USER_LIMIT) {
        oam_warning_log1(0, OAM_SF_DPA, "{dpe_tx_mode_switch_process::user[%d] null.}", tx_switch_param->user_id);
        return OAL_ERR_CODE_PTR_NULL;
    }

    tid_info = dpe_get_tx_tid_info(tx_switch_param->user_id, tx_switch_param->tid_no);
    if (tid_info == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    hal_pm_try_wakeup_forbid_sleep(HAL_PM_FORBIDE_SLEEP_D2H_RX_MODE_SYN);
    if (hal_pm_try_wakeup_dev_lock() != OAL_SUCC) {
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_D2H_RX_MODE_SYN);
        return OAL_FAIL;
    }
    dpe_tid_tx_lock_irq_save(&tid_info->tx_ring.tx_lock, &lock_flag);
    dpe_tid_tx_comp_lock_irq_save(&tid_info->tx_ring.tx_comp_lock, &lock_flag_tx_comp);
    hmac_tx_mode_switch_comp_process(tid_info, tx_switch_param);

    dpe_tid_tx_comp_unlock_irq_restore(&tid_info->tx_ring.tx_comp_lock, &lock_flag_tx_comp);
    dpe_tid_tx_unlock_irq_restore(&tid_info->tx_ring.tx_lock, &lock_flag);
    hmac_tid_schedule();
    hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_D2H_RX_MODE_SYN);
    return OAL_SUCC;
}

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
uint32_t hmac_tx_mode_switch_process(frw_event_mem_stru *event_mem)
{
    uint8_t *tx_switch_param = NULL;

    if (event_mem == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{hmac_tx_mode_switch_process::event_mem null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    tx_switch_param = (uint8_t *)(frw_get_event_stru(event_mem)->auc_event_data);
    return dpe_tx_mode_switch_process(tx_switch_param);
}
#endif

hmac_psm_tx_switch_event_enum hmac_psm_tx_switch_throughput_to_event(uint32_t tx_pps)
{
    if (tx_pps <= HMAC_PSM_TX_SWITCH_LOW_PPS) {
        return PSM_TX_H2D_SWITCH;
    } else if (tx_pps >= HMAC_PSM_TX_SWITCH_HIGH_PPS) {
        return PSM_TX_D2H_SWITCH;
    } else {
        return PSM_TX_SWITCH_BUTT;
    }
}

/*
功能：配置命令切换入口
*/
uint32_t dpe_wlan_tx_mode_switch(uint32_t *params)
{
    uint32_t tx_pps_thre;
    uint8_t mode = (uint8_t)params[0];

    if ((mode == HOST_RING_TX_MODE) || (mode == DEVICE_RING_TX_MODE)) {
        g_tid_switch_list.tid_fix_switch = OAL_TRUE;
    } else {
        g_tid_switch_list.tid_fix_switch = OAL_FALSE;
    }
    oam_warning_log1(0, OAM_SF_DPA, "{dpe_wlan_tx_mode_switch::switch mode[%d][0:H 1:D]}", mode);
    hmac_tx_fsm_quick_switch_to_device();
    tx_pps_thre = (mode == HOST_RING_TX_MODE) ? HMAC_PSM_TX_SWITCH_HIGH_PPS : HMAC_PSM_TX_SWITCH_LOW_PPS;
    hmac_tid_ring_switch_process(tx_pps_thre);
    hmac_tid_ring_switch_process(tx_pps_thre);
    return OAL_SUCC;
}

/*
功能：是否允许H2D切换判决: ring资源足够
*/
oal_bool_enum_uint8 hmac_tx_keep_host_switch(void)
{
    uint8_t tid_entry = hmac_tid_list_entry_count(&g_tid_switch_list.tid_list);
    /* Device ring资源足够，根据pps动态切换；否则全部部署于Host */
    if (tid_entry <= hal_host_get_device_tx_ring_num()) {
        /* 允许根据pps状态机切换 */
        return OAL_FALSE;
    }
    if (g_tid_switch_list.tid_fix_switch == OAL_TRUE) {
        return OAL_TRUE;
    }
    if (hmac_get_tx_switch_fsm_state() == HOST_RING_TX_MODE) {
        return OAL_TRUE;
    }
    /* 保持Host ring state */
    hmac_tid_ring_switch_process(HMAC_PSM_TX_SWITCH_HIGH_PPS);
    return OAL_TRUE;
}

/*
功能：发送流程H2D/D2H PPS门限切换入口
 */
void hmac_tx_pps_switch(uint32_t tx_pps)
{
    /* TX跟随RX切换, PPS不处理 */
    if (!dpe_tx_ring_switch_sync_mode()) {
        return;
    }
    if (g_tid_switch_list.tid_fix_switch == OAL_TRUE) {
        return;
    }
    hmac_tid_ring_switch_process(tx_pps);
}
/*
功能：发送流程H2D/D2H通道统一切换入口
 */
void hmac_tx_switch(uint8_t new_rx_mode)
{
    uint32_t tx_pps_thre;

    /* TRX独立切换, 不处理 */
    if (dpe_tx_ring_switch_sync_mode() == OAL_TRUE) {
        return;
    }
    if (g_tid_switch_list.tid_fix_switch == OAL_TRUE) {
        return;
    }
    /* 根据rx ring模式判定tx ring模型, 两者保持一致: DDR TRX or WRAM TRX */
    tx_pps_thre = (new_rx_mode == HAL_DDR_RX) ? HMAC_PSM_TX_SWITCH_HIGH_PPS : HMAC_PSM_TX_SWITCH_LOW_PPS;
    oam_warning_log1(0, OAM_SF_DPA, "{hmac_tx_switch::tx ring switch by rx mode, pps[%d]!}", tx_pps_thre);
    hmac_tid_ring_switch_process(tx_pps_thre);
    hmac_tid_ring_switch_process(tx_pps_thre);
}
