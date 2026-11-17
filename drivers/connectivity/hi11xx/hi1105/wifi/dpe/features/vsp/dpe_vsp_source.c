/*
 * Copyright (c) @CompanyNameMagicTag 2021-2024. All rights reserved.
 * 功能说明 : dpe_vsp_source.c
 * 作    者 : Wi-Fi
 * 创建日期 : 2025年06月27日
 */

#include "hd_event.h"
#include "hd_command.h"
#include "oam_ext_if.h"
#include "host_hal_device.h"
#include "dpe_wlan_config.h"
#include "dpe_wlan_resource.h"
#include "pcie_host.h"
#include "dpe_tx_data.h"
#include "hmac_tid_ring_switch.h"
#include "hmac_tx_ring_alloc.h"
#include "hmac_host_ring_tx.h"
#include "hmac_tx_msdu_dscr.h"
#include "host_hal_device.h"
#include "dpe_vsp_source.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_VSP_SOURCE_C

static dpe_vsp_source_stru g_dpe_vsp_source;

static uint32_t hmac_vsp_tx_set_msdu_info(msdu_info_stru *msdu_info, uintptr_t iova, uint16_t msdu_len)
{
    uint32_t ret;
    uint64_t devva = 0;

    ret = (uint32_t)pcie_if_hostca_to_devva(HCC_EP_WIFI_DEV, (uint64_t)iova, &devva);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_vsp_tx_set_msdu_info::hostca to devva failed[%d]}", ret);
        return ret;
    }

    msdu_info->msdu_addr_lsb = get_low_32_bits(devva);
    msdu_info->msdu_addr_msb = get_high_32_bits(devva);
    msdu_info->msdu_len = msdu_len;
    msdu_info->data_type = DATA_TYPE_ETH;
#ifdef _PRE_WLAN_CHBA_MGMT
    if (dpe_is_chba_mode(dpe_get_vsp_info()->vap) == OAL_TRUE) {
        // chba模式下to_ds 和 from_ds都是0
        msdu_info->from_ds = 0;
        msdu_info->to_ds = 0;
    } else
#endif
    {
        msdu_info->to_ds = dpe_get_vsp_info()->vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA;
        msdu_info->from_ds = !msdu_info->to_ds;
    }
    return OAL_SUCC;
}

static uint32_t hmac_vsp_tx_ring_push_msdu(hmac_tid_info_stru *tid_info, uintptr_t va, uintptr_t iova, uint16_t len)
{
    hmac_msdu_info_ring_stru *tx_ring = &tid_info->tx_ring;
    un_rw_ptr write_ptr = { .rw_ptr = tx_ring->base_ring_info.write_index };
    msdu_info_stru msdu_info = { 0 };
    uint8_t msdu_dscr_len = hal_host_tx_get_msdu_dscr_len();

    if (oal_unlikely(hmac_tid_ring_full(tx_ring))) {
        oam_warning_log0(0, OAM_SF_DPA, "hmac_vsp_tx_ring_push_msdu: tx ring push fail");
        return OAL_FAIL;
    }
    memset_s((uint8_t *)(uintptr_t)va, msdu_dscr_len, 0, msdu_dscr_len);
    if (hmac_vsp_tx_set_msdu_info(&msdu_info, iova, len) != OAL_SUCC) {
        return OAL_FAIL;
    }
    hal_host_tx_set_msdu_ring(&tx_ring->ring_buf, &msdu_info, write_ptr.st_rw_ptr.bit_rw_ptr);
    hmac_tx_msdu_ring_inc_write_ptr(tx_ring);
    hmac_tx_reg_write_ring_info(tid_info, TID_CMDID_ENQUE, OAL_FALSE);

    return OAL_SUCC;
}

static uint32_t dpe_vsp_tx_packet_nolock(
    hmac_tid_info_stru *tid_info, uintptr_t va, uintptr_t iova, uint16_t msdu_len)
{
    /* lock */
    if (!dpe_get_vsp_info()->vap) {
        oam_warning_log0(0, OAM_SF_DPA, "{dpe_vsp_tx_packet::vap NULL}");
        return OAL_FAIL;
    }

    if (!hmac_tx_ring_alloced(&tid_info->tx_ring) &&
        hmac_alloc_tx_ring_after_inited(tid_info, &tid_info->tx_ring) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_vsp_tx_packet::ring NULL}");
        return OAL_FAIL;
    }

    if (hmac_vsp_tx_ring_push_msdu(tid_info, va, iova, msdu_len) != OAL_SUCC) {
        return OAL_FAIL;
    }

    hmac_tx_sched_trigger(dpe_get_vsp_info()->vap->uc_vap_id, tid_info);
    /* unlock */

    return OAL_SUCC;
}

uint32_t dpe_vsp_tx_packet(uintptr_t va, uintptr_t iova, uint16_t msdu_len)
{
    hmac_tid_info_stru *tid_info = dpe_get_vsp_info()->tid_info[DPE_VSP_TYPE_VIDEO];
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    unsigned long flags1 = 0;
    unsigned long flags2 = 0;
#endif
    uint32_t ret;

    if (!tid_info) {
        return OAL_FAIL;
    }

    dpe_tid_tx_lock_irq_save(&tid_info->tx_ring.tx_lock, &flags1);
    dpe_tid_tx_lock_irq_save(&dpe_get_vsp_info()->vsp_lock, &flags2);
    ret = dpe_vsp_tx_packet_nolock(tid_info, va, iova, msdu_len);
    dpe_tid_tx_unlock_irq_restore(&dpe_get_vsp_info()->vsp_lock, &flags2);
    dpe_tid_tx_unlock_irq_restore(&tid_info->tx_ring.tx_lock, &flags1);

    return ret;
}

void dpe_vsp_tx_packet_proc(hmac_dpe_wifi_msg_stru *msg)
{
    msg->param0 = dpe_vsp_tx_packet(msg->param0, msg->param1, msg->param2);
}

uint32_t dpe_set_vsp_info_addr(uint8_t *data)
{
    uint32_t ret;
    mac_d2h_device_vspinfo_addr *addr = (mac_d2h_device_vspinfo_addr *)data;

    ret = (uint32_t)oal_pcie_devca_to_hostva(HCC_EP_WIFI_DEV, addr->device_vspinfo_addr, &g_dpe_vsp_source.sync_addr);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "{hmac_set_vsp_info_addr::vsp addr sync failed!}");
    }

    return ret;
}

/* 清ring需要host/device同步进行, 通过读写sync_addr对应的device内存, 来共享双方的状态 */
static void dpe_vsp_clear_tx_ring_sync(void)
{
    uint32_t ret;
    uint32_t check_cnt = 1001;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    unsigned long flags = 0;
#endif

    dpe_tid_tx_lock_irq_save(&dpe_get_vsp_info()->vsp_lock, &flags);
    hal_host_writel_irq(VSP_TX_SYNC_LOCK_ACQUIRE, g_dpe_vsp_source.sync_addr);
    do {
        oal_udelay(1);
        check_cnt--;
    } while ((ret = hal_host_readl_irq(g_dpe_vsp_source.sync_addr)) == VSP_TX_SYNC_LOCK_ACQUIRE && check_cnt);
    hal_host_writel_irq(VSP_TX_SYNC_LOCK_RELEASE, g_dpe_vsp_source.sync_addr);
    dpe_tid_tx_unlock_irq_restore(&dpe_get_vsp_info()->vsp_lock, &flags);

    oam_warning_log2(0, OAM_SF_DPA, "{dpe_vsp_clear_tx_ring_sync::sync res %d, check %d}", ret, check_cnt);
}

static void dpe_vsp_source_timer_intr_callback_sync(void)
{
    /* sync timeout event to hmac */
}

void dpe_vsp_source_timeout_update_rptr(void)
{
    hmac_tid_info_stru *tid_info = dpe_get_vsp_info()->tid_info[DPE_VSP_TYPE_VIDEO];
    uint32_t rptr_val;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    unsigned long flags = 0;
#endif

    hal_pm_try_wakeup_forbid_sleep(HAL_PM_FORBIDE_SLEEP_VSP_SOURCE_TIMEOUT);
    if (hal_pm_try_wakeup_dev_lock() != OAL_SUCC) {
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_SOURCE_TIMEOUT);
        return;
    }

    dpe_tid_tx_lock_irq_save(&tid_info->tx_ring.tx_comp_lock, &flags);
    if (hmac_tx_reg_read_rptr(tid_info, &rptr_val) != OAL_SUCC) {
        return;
    }
    tid_info->tx_ring.base_ring_info.read_index = (uint16_t)rptr_val;
    dpe_tid_tx_unlock_irq_restore(&tid_info->tx_ring.tx_comp_lock, &flags);

    hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_SOURCE_TIMEOUT);
}

void dpe_vsp_source_timeout_proc(hmac_dpe_wifi_msg_stru *msg)
{
    dpe_vsp_source_timeout_update_rptr();
}

static void dpe_vsp_source_timer_intr_callback(void *data)
{
    dpe_vsp_clear_tx_ring_sync();
    dpe_vsp_source_timer_intr_callback_sync();
}

void dpe_vsp_source_init_timer(void)
{
    dpe_get_vsp_info()->timer.func = dpe_vsp_source_timer_intr_callback;
}

void dpe_vsp_source_init_timer_proc(hmac_dpe_wifi_msg_stru *msg)
{
    dpe_vsp_source_init_timer();
}

uint32_t dpe_vsp_tx_complete_ring_proc(uint32_t *pkt_num)
{
    hmac_msdu_info_ring_stru *tx_ring = &dpe_get_vsp_info()->tid_info[DPE_VSP_TYPE_VIDEO]->tx_ring;
    un_rw_ptr release_ptr;
    un_rw_ptr target_ptr;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    unsigned long flags1 = 0;
    unsigned long flags2 = 0;
#endif

    /*
     * spin lock锁范围内不允许上下文切换
     * tx complete流程会调用到stop timer写common timer寄存器，前提得唤醒dev
     * 而hal_pm_try_wakeup_dev_lock是允许线程睡眠，所以需要将hal_pm_try_wakeup_dev_lock提前到spin lock前
    */
    hal_pm_try_wakeup_forbid_sleep(HAL_PM_FORBIDE_SLEEP_VSP_TX_COMPLETE);
    if (hal_pm_try_wakeup_dev_lock() != OAL_SUCC) {
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_TX_COMPLETE);
        return OAL_FAIL;
    }
    dpe_tid_tx_lock_irq_save(&tx_ring->tx_lock, &flags1);
    dpe_tid_tx_lock_irq_save(&dpe_get_vsp_info()->vsp_lock, &flags2);
    release_ptr.rw_ptr = tx_ring->release_index;
    target_ptr.rw_ptr = tx_ring->base_ring_info.read_index;
    while (hal_tx_rw_ptr_compare(release_ptr, target_ptr) == RING_PTR_SMALLER) {
        hmac_tx_reset_msdu_info(tx_ring, release_ptr);
        hmac_tx_msdu_ring_inc_release_ptr(tx_ring);
        release_ptr.rw_ptr = tx_ring->release_index;
        (*pkt_num)++;
    }
    dpe_tid_tx_unlock_irq_restore(&dpe_get_vsp_info()->vsp_lock, &flags2);
    dpe_tid_tx_unlock_irq_restore(&tx_ring->tx_lock, &flags1);
    hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_TX_COMPLETE);

    return OAL_SUCC;
}

void dpe_vsp_tx_complete_proc(hmac_dpe_wifi_msg_stru *msg)
{
    msg->param0 = dpe_vsp_tx_complete_ring_proc(&msg->param1);
}

