/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : vsp低时延丢包流程
 * 作者       : wifi
 * 创建日期   : 2020年12月24日
 */

#include "hmac_vsp.h"
#include "hmac_vsp_buf.h"
#include "hmac_tx_data.h"
#include "hmac_tx_msdu_dscr.h"
#include "hmac_tx_data.h"
#include "hmac_tx_ring_alloc.h"
#include "hmac_config.h"
#include "hmac_scan.h"
#include "hmac_tid_ring_switch.h"
#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_chba_ps.h"
#endif
#include "hmac_sync_dpe.h"
#include "dpe_vsp_source.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_VSP_C

#ifdef _PRE_WLAN_FEATURE_VSP
static hmac_vsp_vcodec_vdec_ops g_default_vdec_ops = {
    .alloc_slice_mgmt = NULL,
    .rx_slice_done = NULL,
};

static hmac_vsp_vcodec_venc_ops g_default_venc_ops = {
    .wifi_tx_pkg_done = NULL,
    .wifi_tx_send_done = NULL,
    .wifi_rx_msdu = NULL,
};

static hmac_vsp_sx_ops g_default_sx_ops = {
    .wifi_tx_send_done = NULL,
    .wifi_rx_msdu = NULL,
};

hmac_vsp_vcodec_vdec_ops *g_vsp_vcodec_vdec_ops = &g_default_vdec_ops;
hmac_vsp_vcodec_venc_ops *g_vsp_vcodec_venc_ops = &g_default_venc_ops;
hmac_vsp_sx_ops *g_vsp_sx_ops = &g_default_sx_ops;
hmac_vsp_info_stru g_vsp_common_info = {0};
hmac_vsp_info_stru *g_vsp_common_info_ptr = &g_vsp_common_info;
hmac_vsp_info_stru *g_vsp_info = NULL;

/* vdec call wifi to set callback */
void vdec_set_callback(struct vcodec_vdec_callback *callback)
{
    (void)memcpy_s(g_vsp_vcodec_vdec_ops, sizeof(struct vcodec_vdec_callback),
        callback, sizeof(struct vcodec_vdec_callback));
}

/* venc call wifi to set callback */
void venc_set_callback(struct vcodec_venc_callback *callback)
{
    (void)memcpy_s(g_vsp_vcodec_venc_ops, sizeof(struct vcodec_venc_callback),
        callback, sizeof(struct vcodec_venc_callback));
}

/* sx call wifi to set callback */
void sx_set_callback(struct vcodec_sx_callback *callback)
{
    (void)memcpy_s(g_vsp_sx_ops, sizeof(struct vcodec_sx_callback),
        callback, sizeof(struct vcodec_sx_callback));
}

void hmac_vsp_set_current_handle(hmac_vsp_info_stru *vsp_info)
{
    g_vsp_info = vsp_info;
}

hmac_vsp_info_stru *hmac_vsp_get_current_handle(void)
{
    return g_vsp_info;
}

hmac_vsp_info_stru *hmac_vsp_get_common_info(void)
{
    return g_vsp_common_info_ptr;
}

static uint32_t hmac_vsp_set_status(mac_vap_stru *mac_vap, uint8_t mode, uint16_t user_index)
{
    mac_vsp_cfg_stru vsp_cfg = {
        .user_index = user_index,
        .mode = mode,
    };

    return hmac_config_send_event(mac_vap, WLAN_CFGID_VSP_STATUS_CHANGE, sizeof(mac_vsp_cfg_stru), (uint8_t *)&vsp_cfg);
}

static uint32_t hmac_vsp_init_common_timer(hmac_vsp_info_stru *vsp_info)
{
    hal_mac_common_timer *timer = &vsp_info->timer;

    timer->timer_en = OAL_TRUE;
    timer->timer_mask_en = OAL_TRUE;
    timer->timer_unit = HAL_COMMON_TIMER_UNIT_1US;
    timer->timer_mode = HAL_COMMON_TIMER_MODE_ONE_SHOT;
    timer->func = NULL;
    timer->timer_id = g_wlan_spec_cfg->vsp_timer_id;
    hal_pm_try_wakeup_forbid_sleep(HAL_PM_FORBIDE_SLEEP_VSP_INIT_COMMON_TIMER);
    if (hal_pm_try_wakeup_dev_lock() != OAL_SUCC) {
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_INIT_COMMON_TIMER);
        return OAL_FAIL;
    }
    if (hal_host_init_common_timer(timer) != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_TX, "hmac_vsp_tx_info_init :: init common timer[%d] fail", timer->timer_id);
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_INIT_COMMON_TIMER);
        return OAL_FAIL;
    }
    hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_INIT_COMMON_TIMER);
    return OAL_SUCC;
}

static void hmac_vsp_deinit_common_timer(hmac_vsp_info_stru *vsp_info)
{
    hal_mac_common_timer *timer = &vsp_info->timer;

    timer->timer_en = OAL_FALSE;
    hal_host_set_mac_common_timer(timer);
}

OAL_STATIC void hmac_vsp_clear_tx_ring(hmac_vsp_info_stru *vsp_info, hmac_tid_info_stru *tid_info)
{
    hmac_msdu_info_ring_stru *tx_ring = &tid_info->tx_ring;
    unsigned long flags = 0;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_uint lock_flag, lock_flag_tx_comp;
#endif

    if (vsp_info == NULL || tx_ring == NULL) {
        oam_error_log0(0, 0, "hmac_vsp_clear_tx_ring:vsp_info/tx_ring null");
        return;
    }

    dpe_tid_tx_lock_irq_save(&tx_ring->tx_lock, &lock_flag);
    dpe_tid_tx_comp_lock_irq_save(&tx_ring->tx_comp_lock, &lock_flag_tx_comp);

    hmac_wait_tx_ring_empty(tid_info);
    oal_spin_lock_irq_save(&vsp_info->vsp_lock, &flags);
    hmac_tx_ring_release_all_netbuf(tx_ring);
    oal_spin_unlock_irq_restore(&vsp_info->vsp_lock, &flags);

    dpe_tid_tx_unlock_irq_restore(&tx_ring->tx_lock, &lock_flag);
    dpe_tid_tx_comp_unlock_irq_restore(&tx_ring->tx_comp_lock, &lock_flag_tx_comp);
}

typedef struct {
    hmac_scan_state_enum scan_state;
    mac_cfg_ps_open_stru pm_state;
} hmac_vsp_config_stru;

static void hmac_vsp_config_sta(mac_vap_stru *mac_vap, hmac_vsp_config_stru *param)
{
    if (!is_legacy_sta(mac_vap)) {
        return;
    }

    hmac_config_set_sta_pm_on(mac_vap, 0, (uint8_t *)&param->pm_state);
    hmac_bgscan_enable(mac_vap, 0, (uint8_t *)&param->scan_state);
}

static void hmac_vsp_stop_config_sta(hmac_vsp_info_stru *vsp_info)
{
    hmac_vsp_config_stru param = {
        .scan_state = HMAC_BGSCAN_ENABLE,
        .pm_state = {
            .uc_pm_ctrl_type = MAC_STA_PM_CTRL_TYPE_CMD,
            .uc_pm_enable = MAC_STA_PM_SWITCH_ON,
        }
    };

    hmac_vsp_config_sta(&vsp_info->hmac_vap->st_vap_base_info, &param);
}

/* 现阶段为保证投屏时延与稳定性, 需要关闭背景扫描与协议低功耗 */
static void hmac_vsp_start_config_sta(hmac_vsp_info_stru *vsp_info)
{
    hmac_vsp_config_stru param = {
        .scan_state = HMAC_BGSCAN_DISABLE,
        .pm_state = {
            .uc_pm_ctrl_type = MAC_STA_PM_CTRL_TYPE_CMD,
            .uc_pm_enable = MAC_STA_PM_SWITCH_OFF,
        }
    };

    hmac_vsp_config_sta(&vsp_info->hmac_vap->st_vap_base_info, &param);
}

OAL_STATIC uint32_t hmac_vsp_tid_ring_switch(hmac_vsp_info_stru *vsp_info, hmac_tid_info_stru *tid_info)
{
    uint8_t cnt = 5; // 最多重试5次

    while (oal_atomic_read(&tid_info->ring_tx_mode) != HOST_RING_TX_MODE &&
        oal_atomic_read(&tid_info->ring_tx_mode) != D2H_SWITCHING_MODE && cnt != 0) {
        hmac_tid_ring_switch(vsp_info->hmac_user->st_user_base_info.us_assoc_id, tid_info, HOST_RING_TX_MODE);
        oal_msleep(2); // 间隔2ms
        cnt--;
    }

    if (oal_atomic_read(&tid_info->ring_tx_mode) == HOST_RING_TX_MODE ||
        oal_atomic_read(&tid_info->ring_tx_mode) == D2H_SWITCHING_MODE) {
        return OAL_SUCC;
    } else {
        oam_error_log2(0, 0, "hmac_vsp_tid_ring_switch:FAIL! ring_tx_mode[%d]cnt[%d]",
            oal_atomic_read(&tid_info->ring_tx_mode), cnt);
        return OAL_FAIL;
    }
}

static uint32_t hmac_vsp_context_init_ring_sync(uint8_t vsp_type)
{
    hmac_dpe_wifi_msg_stru resp = { 0 };
    hmac_dpe_wifi_msg_stru msg = {
        .msg_type = HMAC2DPE_VSP_RING_INIT_MSG,
        .param0 = vsp_type,
    };
 
    /* sync vsp ring init event & wait for result */
    if (hmac_sync_dpa_event_wait_response(&msg, &resp) != OAL_SUCC) {
        return OAL_FAIL;
    }
 
    return resp.param0;
}

static uint32_t hmac_vsp_context_init_ring(hmac_vsp_info_stru *vsp_info, uint8_t vsp_type)
{
    if (dpe_is_support_dpe_offload() == OAL_TRUE) {
        return hmac_vsp_context_init_ring_sync(vsp_type);
    } else {
        return dpe_vsp_context_init_ring(vsp_type);
    }
}

uint32_t hmac_vsp_context_init(hmac_vsp_info_stru *vsp_info, hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    uint8_t mode)
{
    uint8_t vsp_type = hmac_vsp_get_type_by_mode(mode);
    hmac_tid_info_stru *tid_info = vsp_info->tid_info[vsp_type];
    uint8_t tid = WLAN_TIDNO_VSP;

    if (tid_info == NULL) {
        return OAL_FAIL;
    }

    hmac_vsp_start_config_sta(vsp_info);
    hmac_tid_info_queue_release(tid_info);
    hmac_vsp_clear_tx_ring(vsp_info, tid_info);
    if (hmac_vsp_tid_ring_switch(vsp_info, tid_info) != OAL_SUCC) {
        return OAL_FAIL;
    }

    if (hmac_vsp_context_init_ring(vsp_info, vsp_type) != OAL_SUCC) {
        return OAL_FAIL;
    }

    if (vsp_type == VSP_TYPE_VIDEO) {
        tid = WLAN_TIDNO_VSP;
    } else if (vsp_type == VSP_TYPE_SX) {
        tid = WLAN_TIDNO_VIDEO;
    }
    if (hmac_tid_need_ba_session(hmac_vap, hmac_user, tid) == OAL_TRUE) {
        hmac_tx_ba_setup(hmac_vap, hmac_user, tid);
    }
    hmac_user->vsp_hdl = vsp_info;
    return OAL_SUCC;
}

void hmac_vsp_context_deinit(hmac_vsp_info_stru *vsp_info, uint8_t mode)
{
    uint8_t vsp_type = hmac_vsp_get_type_by_mode(mode);
    hmac_tid_info_stru *tid_info;

    if (vsp_info == NULL) {
        oam_error_log0(0, 0, "hmac_vsp_context_deinit:vsp_info null");
        return;
    }
    tid_info = vsp_info->tid_info[vsp_type];
    if (tid_info != NULL) {
        hmac_vsp_clear_tx_ring(vsp_info, tid_info);
    }
    hmac_vsp_stop_config_sta(vsp_info);
}

#ifdef _PRE_WLAN_CHBA_MGMT
void hmac_vsp_init_fix_chba_bitmap(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user)
{
    // vsp+chba场景：固定全醒
    hmac_chba_update_fix_user_bitmap_cfg(hmac_vap, hmac_user,
        CHBA_VSP_FIX_USER_BITMAP_TYPE, CHBA_BITMAP_ALL_AWAKE_LEVEL, OAL_TRUE);
}

void hmac_vsp_deinit_set_chba_bitmap(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user)
{
    // vsp+chba场景：退出时恢复自动调整
    hmac_chba_update_fix_user_bitmap_cfg(hmac_vap, hmac_user,
        CHBA_VSP_FIX_USER_BITMAP_TYPE, CHBA_BITMAP_ALL_AWAKE_LEVEL, OAL_FALSE);
}
#endif

uint32_t hmac_vsp_init_user_vap_check(hmac_vsp_info_stru *vsp_info, hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    hal_host_device_stru *hal_device)
{
    if (vsp_info->hmac_user == hmac_user && vsp_info->hmac_vap == hmac_vap && vsp_info->host_hal_device == hal_device) {
        return OAL_SUCC;
    }
    oam_error_log3(0, 0, "{hmac_vsp_init_user_vap_check::fail! vap idx[%d], user idx[%d] device_id[%d]}",
        hmac_vap->st_vap_base_info.uc_vap_id, hmac_user->st_user_base_info.us_assoc_id, hal_device->device_id);
    return OAL_FAIL;
}

static uint32_t hmac_vsp_init_sync(uint16_t user_id, uint16_t vap_id, uint8_t device_id)
{
    hmac_dpe_wifi_msg_stru resp = { 0 };
    hmac_dpe_wifi_msg_stru msg = {
        .msg_type = HMAC2DPE_VSP_INIT_MSG,
        .param0 = user_id,
        .param1 = vap_id,
        .param2 = device_id,
    };
 
    /* sync vsp init event to dpe & wait for result */
    if (hmac_sync_dpa_event_wait_response(&msg, &resp) != OAL_SUCC) {
        return OAL_FAIL;
    }
 
    return resp.param0;
}
 
static uint32_t hmac_vsp_init_proc(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user)
{
    if (dpe_is_support_dpe_offload() == OAL_TRUE) {
        return hmac_vsp_init_sync(hmac_user->st_user_base_info.us_assoc_id, mac_vap->uc_vap_id, mac_vap->uc_device_id);
    } else {
        return dpe_vsp_init(hmac_user->st_user_base_info.us_assoc_id, mac_vap->uc_vap_id, mac_vap->uc_device_id);
    }
}

uint32_t hmac_vsp_init(
    hmac_vsp_info_stru *vsp_info, hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, vsp_param *param, uint8_t mode)
{
    mac_vap_stru *mac_vap = &hmac_vap->st_vap_base_info;
    hal_host_device_stru *hal_device = hal_get_host_device(mac_vap->uc_device_id);
    if (!hal_device) {
        oam_error_log0(0, OAM_SF_TX, "{hmac_vsp_init::hal_device NULL}");
        return OAL_FAIL;
    }
    if (vsp_info->enable != 0) {
        return hmac_vsp_init_user_vap_check(vsp_info, hmac_vap, hmac_user, hal_device);
    }

    vsp_info->hmac_user = hmac_user;
    vsp_info->hmac_vap = hmac_vap;
    vsp_info->tid_info[VSP_TYPE_VIDEO] = dpe_get_tx_tid_info(hmac_user->st_user_base_info.us_assoc_id, WLAN_TIDNO_VSP);
    if (vsp_info->tid_info[VSP_TYPE_VIDEO] == NULL) {
        return OAL_FAIL;
    }
    vsp_info->tid_info[VSP_TYPE_SX] = dpe_get_tx_tid_info(hmac_user->st_user_base_info.us_assoc_id, WLAN_TIDNO_VIDEO);
    if (vsp_info->tid_info[VSP_TYPE_SX] == NULL) {
        return OAL_FAIL;
    }
    vsp_info->host_hal_device = hal_device;

    oal_spin_lock_init(&vsp_info->vsp_lock);
    if (hmac_vsp_init_common_timer(vsp_info) != OAL_SUCC) {
        return OAL_FAIL;
    }

    vsp_info->timer_running = OAL_FALSE;
    hmac_vsp_set_vcodec_vdec_ops(&g_default_vdec_ops);
    hmac_vsp_set_vcodec_venc_ops(&g_default_venc_ops);

    if (hmac_vsp_init_proc(mac_vap, hmac_user) != OAL_SUCC) {
        oam_error_log3(0, 0, "{hmac_vsp_init::VSP[%d] init FAILED, vap idx[%d], user idx[%d]!}",
            mode, mac_vap->uc_vap_id, hmac_user->st_user_base_info.us_assoc_id);
        return OAL_FAIL;
    }

    oam_warning_log3(0, 0, "{hmac_vsp_init::VSP[%d] init SUCC, vap idx[%d], user idx[%d]!}",
        mode, mac_vap->uc_vap_id, hmac_user->st_user_base_info.us_assoc_id);
#ifdef _PRE_WLAN_CHBA_MGMT
    hmac_vsp_init_fix_chba_bitmap(hmac_vap, hmac_user);
#endif

    return OAL_SUCC;
}

uint32_t hmac_vsp_mode_init(
    hmac_vsp_info_stru *vsp_info, hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, vsp_param *param, uint8_t mode)
{
    mac_vap_stru *mac_vap = &hmac_vap->st_vap_base_info;
    uint8_t bitmask = hmac_vsp_get_type_bitmask_by_cmd(mode);
    if ((vsp_info->enable & bitmask) != 0) {
        oam_error_log2(0, 0, "{hmac_vsp_mode_init::fail! enable[0x%x] mode[%d]}", vsp_info->enable, mode);
        return OAL_FAIL;
    }
    if (mode == VSP_MODE_SINK || mode == VSP_MODE_SOURCE) {
        vsp_info->mode = mode;
        if (memcpy_s(&vsp_info->param, sizeof(vsp_param), param, sizeof(vsp_param)) != EOK) {
            return OAL_FAIL;
        }
    }
    oam_warning_log1(0, 0, "{hmac_vsp_mode_init::VSP[%d] init SUCC!}", mode);

    hmac_vsp_set_status(mac_vap, mode, hmac_user->st_user_base_info.us_assoc_id);

    return OAL_SUCC;
}

void hmac_vsp_deinit(hmac_vsp_info_stru *vsp_info, uint8_t mode)
{
    unsigned long flags = 0;
    uint8_t bitmask = hmac_vsp_get_type_bitmask_by_cmd(mode);

    if (oal_any_null_ptr3(vsp_info, vsp_info->hmac_vap, vsp_info->hmac_user)) {
        oam_error_log0(0, 0, "{hmac_vsp_deinit::vsp deinit failed due to null ptr!}");
        return;
    }

    vsp_info->enable &= ~bitmask;
    if (vsp_info->enable != 0) {
        oam_warning_log2(0, 0, "hmac_vsp_deinit::mode[%d] enable[0x%x]", mode, vsp_info->enable);
        return;
    }
    hmac_vsp_deinit_common_timer(vsp_info);
    hmac_vsp_set_status(
        &vsp_info->hmac_vap->st_vap_base_info, VSP_MODE_DISABLED, vsp_info->hmac_user->st_user_base_info.us_assoc_id);
#ifdef _PRE_WLAN_CHBA_MGMT
    hmac_vsp_deinit_set_chba_bitmap(vsp_info->hmac_vap, vsp_info->hmac_user);
#endif
    oal_spin_lock_irq_save(&vsp_info->vsp_lock, &flags);
    vsp_info->hmac_vap = NULL;
    vsp_info->hmac_user = NULL;
    vsp_info->host_hal_device = NULL;
    oal_spin_unlock_irq_restore(&vsp_info->vsp_lock, &flags);
    oam_warning_log0(0, 0, "hmac_vsp_deinit::finish");
}

uint32_t hmac_vsp_get_timestamp(hmac_vsp_info_stru *vsp_info)
{
    uint32_t tsf = 0;

    if (oal_any_null_ptr3(vsp_info, vsp_info->host_hal_device, vsp_info->hmac_vap)) {
        return 0;
    }

    return hal_host_get_tsf_lo(vsp_info->host_hal_device, vsp_info->hmac_vap->hal_vap_id, &tsf) == OAL_SUCC ? tsf : 0;
}

void hmac_vsp_start_timer(hmac_vsp_info_stru *vsp_info, uint32_t start_time, uint32_t timeout_us)
{
    if (!vsp_info) {
        oam_error_log0(0, 0, "{hmac_vsp_start_timer::vsp timer start failed!}");
        return;
    }

    oal_warn_on(vsp_info->timer_running);
    vsp_info->timer.start_time = start_time;
    vsp_info->timer.common_timer_val = timeout_us;
    vsp_info->timer.timer_en = OAL_TRUE;
    hal_host_set_mac_common_timer(&vsp_info->timer);
    vsp_info->timer_running = OAL_TRUE;
}

void hmac_vsp_stop_timer(hmac_vsp_info_stru *vsp_info)
{
    if (!vsp_info) {
        oam_error_log0(0, 0, "{hmac_vsp_stop_timer::vsp timer stop failed!}");
        return;
    }

    vsp_info->timer.timer_en = OAL_FALSE;
    hal_host_set_mac_common_timer(&vsp_info->timer);
    vsp_info->timer_running = OAL_FALSE;
}

void hmac_vsp_stop_timer_no_pm_wakeup(hmac_vsp_info_stru *vsp_info)
{
    if (!vsp_info) {
        oam_error_log0(0, 0, "{hmac_vsp_stop_timer_no_pm_wakeup::vsp timer stop failed!}");
        return;
    }

    vsp_info->timer.timer_en = OAL_FALSE;
    hal_host_set_mac_common_timer_no_pm_wakeup(&vsp_info->timer);
    vsp_info->timer_running = OAL_FALSE;
}

static uint32_t hmac_vsp_calc_slice_timeout(hmac_vsp_info_stru *vsp_info, uint8_t slice_id, uint32_t cur,
    uint8_t is_cfg_pkt)
{
    uint32_t consume = hmac_vsp_calc_runtime(vsp_info->timer_ref_vsync, cur); // 当前slice已经run的时间
    uint32_t target = vsp_info->param.tmax; // 以每个slice各自的时间作为超时时间
    uint32_t timeout;

    if (is_cfg_pkt == OAL_TRUE) {
        target = vsp_info->param.tfeedback;
    }

    if (consume < target) {
        timeout = target - consume; // 当前slice的剩余时间作为超时时间
        /* min timeout for a slice 100us */
        if (oal_warn_on(timeout < 100)) {
            timeout = vsp_info->param.tslice;
        }
    } else {
        oam_error_log2(0, 0, "{hmac_vsp_calc_slice_timeout::slice[%d] consume[%d] is lager than target transmit dly}",
            slice_id, consume);
        timeout = vsp_info->param.tslice;
    }

    return timeout;
}

void hmac_vsp_set_slice_timeout(hmac_vsp_info_stru *vsp_info, uint8_t slice_id, uint8_t is_cfg_pkt)
{
    uint32_t cur;

    if (!vsp_info) {
        oam_error_log0(0, 0, "{hmac_vsp_stop_timer::vsp timer stop failed!}");
        return;
    }

    cur = hmac_vsp_get_timestamp(vsp_info);
    hmac_vsp_start_timer(vsp_info, cur, hmac_vsp_calc_slice_timeout(vsp_info, slice_id, cur, is_cfg_pkt));

    hmac_vsp_log((uint8_t *)&vsp_info->timer, VSP_LOG_BITMAP_TIMER, VSP_LOG_DATATYPE_TIMER, VSP_LOG_TYPE_START_TIMER);
}
void hmac_vsp_set_vcodec_vdec_ops(hmac_vsp_vcodec_vdec_ops *ops)
{
    g_vsp_vcodec_vdec_ops = ops;
}

void hmac_vsp_set_vcodec_venc_ops(hmac_vsp_vcodec_venc_ops *ops)
{
    g_vsp_vcodec_venc_ops = ops;
}

void hmac_vsp_set_sx_ops(hmac_vsp_sx_ops *ops)
{
    g_vsp_sx_ops = ops;
}
#endif
