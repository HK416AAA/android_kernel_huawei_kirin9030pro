/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpe模块的初始化与卸载
 */

/* 1 头文件包含 */
#include "conn_dmi_msg.h"
#include "dpe_hcc_if.h"
#include "oam_ext_if.h"
#include "dpe_thread.h"
#include "dpe_wlan_resource.h"
#include "dpe_dma_cpy.h"
#include "dpe_filter_reg.h"
#include "dpe_tx_data.h"
#include "plat_pm_wlan.h"
#include "hmac_tx_complete.h"
#include "hmac_rx_complete.h"
#include "hmac_tid_update.h"
#include "hmac_tid_sche.h"
#include "hmac_tid_ring_switch.h"
#include "hmac_tx_switch.h"
#include "dpe_wlan_debug.h"
#include "dpe_main.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_MAIN_C

/* WIFI DPE低功耗投票接口 */
uint8_t dpe_is_trx_busy(void)
{
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
#else
    wlan_pm_ring_stat *wlan_pm_info = wlan_pm_get_ring_stat();
#endif
    if (oal_warn_on(wlan_pm_info == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_is_trx_busy: wlan_pm is null ");
        return OAL_FALSE;
    }

    if (dpe_ring_tx_enabled() != OAL_TRUE) {
        return OAL_FALSE;
    }

    if (hmac_is_tid_empty() == OAL_FALSE) {
        wlan_pm_info->tid_not_empty_cnt++;
        return OAL_TRUE;
    }

    if (oal_atomic_read(&g_tid_sche_ring_mpdu_num) != 0) {
        wlan_pm_info->ring_has_mpdu_cnt++;
        return OAL_TRUE;
    }

    /* Host DDR接收不允许平台睡眠,低流量切device接收 */
    if (hal_master_is_in_ddr_rx() == OAL_TRUE) {
        wlan_pm_info->master_ddr_rx_cnt++;
        return OAL_TRUE;
    }
    if (hal_slave_is_in_ddr_rx() == OAL_TRUE) {
        wlan_pm_info->slave_ddr_rx_cnt++;
        return OAL_TRUE;
    }

    if (hmac_is_tid_device_ring() == OAL_FALSE) {
        wlan_pm_info->tid_ring_host_cnt++;
        return OAL_TRUE;
    }

    if (hal_is_host_forbid_sleep() == OAL_TRUE) {
        wlan_pm_info->host_forbid_sleep_cnt++;
        return OAL_TRUE;
    }
    /* 常发常收不允许平台睡眠 */
    if (hal_device_is_al_trx() == OAL_TRUE) {
        return OAL_TRUE;
    }
    return OAL_FALSE;
}

/* WIFI上电处理接口 */
int32_t dpe_wifi_on_init(uint8_t *buf, uint16_t buf_len)
{
    uint8_t dev_num = mac_chip_get_hal_dev_num();
    uint8_t dev_id;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_resource_dump();
#else
    hmac_tid_sche_list_dump(HMAC_TID_SCHE_LIST_WIFI_STATE_NOTIFY);
#endif
    hal_host_approve_access_device();
    for (dev_id = 0; dev_id < dev_num; dev_id++) {
        if (dpe_host_ring_tx_enabled() == OAL_TRUE || dpe_rx_ring_switch_enabled() == OAL_TRUE) {
            hal_host_intr_regs_init(dev_id);
        }
#ifdef _PRE_WLAN_FEATURE_FTM
        hal_host_ftm_reg_init(dev_id);
#endif
    }

    if (dpe_host_ring_tx_enabled() == OAL_TRUE) {
        hal_host_ring_tx_init(HAL_DEVICE_ID_MASTER);
    }

    dpe_wlan_device_init_dyn_pcie(0);
    hmac_tid_update_timer_init();
    return OAL_SUCC;
}
/* WIFI下电处理接口 */
int32_t dpe_wifi_off_deinit(uint8_t *buf, uint16_t buf_len)
{
    uint8_t dev_num = mac_chip_get_hal_dev_num();
    uint8_t dev_id;

#ifndef _PRE_LINUX_TEST
    /* wifi 下电过程和dfr过程中释放rx ring相关资源 */
    hal_device_reset_rx_res();
#endif

    hal_pm_try_wakeup_reset_forbid_sleep();

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_wifi_clear_wlan_res(); /* 下电清理全部vap/user资源 */
    dpe_clean_wlan_pm_ring_stat(); // 关wifi时清理统计量
    dpe_frw_list_free(); // 清理事件
#else
    hmac_tid_sche_list_dump(HMAC_TID_SCHE_LIST_WIFI_STATE_NOTIFY);
#endif
    hmac_tid_update_timer_deinit();

    hal_host_forbid_access_device();
    for (dev_id = 0; dev_id < dev_num; dev_id++) {
        hal_host_device_exit(dev_id);
    }
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_resource_dump();
#endif
    return OAL_SUCC;
}

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
static int32_t dpe_wifi_update_trx_stat(uint8_t *buf, uint16_t buf_len)
{
    const uint32_t cache_align = 0xFFFFFF00;
    uint32_t stat_info_len = (uint32_t)(sizeof(dpe_wlan_stat_res_stru) & cache_align);

    /* dpe统计信息只有保存在共享内存内, 才可刷新后供host使用 */
    if ((g_dpe_wlan_stat_res_ptr == NULL) || (g_dpe_wlan_stat_res_ptr == &g_dpe_wlan_stat_res)) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wifi_update_trx_stat:stat_info is not shared!}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    if (dpe_cache_flush(g_dpe_wlan_stat_res_ptr, stat_info_len) != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "mdrv_cache_flush failed! g_dpe_wlan_stat_res_ptr is not NUL and \
            stat_info_len is %u.", stat_info_len);
    }
    return OAL_SUCC;
}
#endif

void dpe_module_init(void)
{
    /* 硬件抽象层初始化 */
    hal_main_init();

    dpe_wlan_res_init();
    hmac_tid_res_init();
    dpe_wlan_lut_index_tbl_init();

    /* 线程资源初始化 */
#ifdef _PRE_HOST_PERFORMANCE
    host_time_init();
#endif
    hmac_tx_comp_init();
    hmac_rx_comp_init();
    hmac_tid_update_init();
    hmac_tid_schedule_init();
    hmac_tid_ring_switch_init();
    hmac_cb_size_protect();
}

/* WIFI开机接口处理 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
/* 低功耗进出 */
OAL_STATIC void dpe_pm_state_notify(oal_bool_enum_uint8 en_wake_up)
{
    if (en_wake_up == OAL_TRUE) {
        hmac_tid_update_timer_init();
    } else {
        hmac_tid_update_timer_deinit();
    }
}
OAL_STATIC void dpe_wifi_pm_register()
{
    struct wifi_srv_callback_handler *pm_hdl = wlan_pm_get_wifi_srv_handler();
    /* WIFI业务投休眠票 */
    pm_hdl->p_wifi_srv_get_pm_pause_func = dpe_is_trx_busy;
    /* 低功耗进出通知WIFI */
    pm_hdl->p_wifi_srv_pm_state_notify = dpe_pm_state_notify;
    /* 获取WIFI当个timer周期内的收发包统计 */
    pm_hdl->p_wifi_srv_get_trx_cnt_func = dpe_pm_get_trx_cnt;
    pm_hdl->p_wifi_srv_data_pm_print_func = dpe_wlan_pm_print_debug_info;
    /* 平台开关WIFI通知WIFI */
    pm_hdl->p_wifi_srv_open_notify = NULL;
}
OAL_STATIC int32_t dpe_dfr_forbid_access(uint8_t *buf, uint16_t buf_len)
{
    hal_host_forbid_access_device();
    return OAL_SUCC;
}

OAL_STATIC int32_t dpe_dfr_recovery(uint8_t *buf, uint16_t buf_len)
{
    /* 资源初始化 */
    dpe_wifi_on_init(buf, buf_len);
    return OAL_SUCC;
}
OAL_STATIC int32_t dpe_dfr_excp(uint8_t *buf, uint16_t buf_len)
{
    dpe_wifi_clear_wlan_res(); /* 清理全部wifi资源 */
    dpe_wifi_off_deinit(buf, buf_len); /* 执行下电流程 */
    return OAL_SUCC;
}
OAL_STATIC int32_t dpe_wifi_pps_tx_switch(uint8_t *buf, uint16_t buf_len)
{
    hmac_pps_tx_switch_stru *msg_info = (hmac_pps_tx_switch_stru *)buf;
    if (msg_info == NULL) {
        return OAL_FAIL;
    }

    hmac_tx_pps_switch(msg_info->pps);
    return OAL_SUCC;
}
OAL_STATIC int32_t sme_to_dpe_sync_msg(uint8_t *buf, uint16_t buf_len)
{
    uint32_t msg_type = *(uint32_t*)buf;
    dpe_wlan_event_dispatch_stat_stru *event_trx_stat = dpe_wlan_event_trx_stat_get();

    switch (msg_type) {
        case DMI_WIFI_MSG_PPS_TX_SWITCH:
            event_trx_stat->dpe_rx_dmi_msg_ring_switch++;
            dpe_wifi_pps_tx_switch(buf, buf_len);
            return OAL_SUCC;
        case DMI_WIFI_MSG_TX_ADDBA:
            oam_warning_log2(0, OAM_SF_DPA, "{sme_to_dpe_sync_msg:: msg_type %d len %d sync dpe}", msg_type, buf_len);
            return OAL_SUCC;
        case DMI_WIFI_MSG_HIRPIV:
            dpe_wlan_debug_hipriv_sync(buf);
            return OAL_SUCC;
        default:
            oam_error_log2(0, OAM_SF_DPA, "{sme_to_dpe_sync_msg:: msg_type %d, len %d}", msg_type, buf_len);
            break;
    }
    return OAL_SUCC;
}
OAL_STATIC void dpe_dmi_msg_info_handle(dmi_msg_content_stru *msg_info)
{
    dpe_trx_switch_sync(&msg_info->trx_switch);
    if (msg_info->cma_base != 0) {
        g_dpe_wlan_stat_res_ptr = (dpe_wlan_stat_res_stru *)(uintptr_t)msg_info->cma_base;
    } else {
        oam_error_log0(0, OAM_SF_DPA, "dpe_dmi_msg_info_handle:: wlan_stat cma virt_addr is NULL");
    }
}

OAL_STATIC int32_t dpe_main_init(uint8_t *buf, uint16_t buf_len)
{
    dpe_dmi_msg_info_handle((dmi_msg_content_stru *)buf);
    /* WIFI DPE资源初始化 */
    dpe_module_init();
    /* WIFI DPE核间通信初始化 */
    dpe_hcc_adapt_init();
    /* WIFI DPE事件流转初始化 */
    event_fsm_table_register();
    /* WIFI DPE线程初始化 */
    hmac_hisi_thread_init();
    /* WIFI DPE spec初始化 */
    dpe_chip_feature_init();
    /* WIFI DPE modem->filter->dpe数据流转注册 */
    dpe_wlan_tx_data_src_register();
    /* WIFI DPE DMA信号量初始化 */
    dpe_dma_sem_init();
    /* WIFI DPE netdev同步接口注册 */
    dpe_wlan_net_dev_init();
    /* 低功耗注册 */
    dpe_wifi_pm_register();
    /* console debug命令注册 */
    dpe_wlan_debug_cosole_register();
    return OAL_SUCC;
}

void dpe_main_exit(void)
{
    dpe_dma_sem_deinit();
    hal_host_access_device_exit();
    hmac_hisi_thread_deinit();
}

void dpe_dmi_register(void)
{
    conn_dmi_msg_regiser(CONN_DMI_MSG_WIFI_FORBID_ACCESS, dpe_dfr_forbid_access, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_WIFI_DFR_RECOVER, dpe_dfr_recovery, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_WIFI_INIT, dpe_main_init, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_WIFI_ON, dpe_wifi_on_init, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_WIFI_OFF, dpe_wifi_off_deinit, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_WIFI_DFX_UPDATE, dpe_wifi_update_trx_stat, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_WIFI_MSG, sme_to_dpe_sync_msg, NULL); // SME->DPE msg sync
    conn_dmi_msg_regiser(CONN_DMI_MSG_WIFI_DFR_EXCP, dpe_dfr_excp, NULL);
}
#endif
