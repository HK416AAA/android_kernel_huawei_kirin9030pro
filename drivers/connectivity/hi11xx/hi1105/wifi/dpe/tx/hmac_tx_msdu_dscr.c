/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : TX MSDU 描述符管理功能
 * 作者       : wifi
 * 创建日期   : 2020年02月12日
 */

/* 1 其他头文件包含 */
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "pcie_linux.h"
#include "hmac_config.h"
#include "hmac_tx_data.h"
#else
#include "pcie_host.h"
#endif
#include "plat_pm_wlan.h"
#include "hmac_tx_msdu_dscr.h"
#ifdef _PRE_WLAN_FEATURE_MINTP
#include "hmac_mintp_log.h"
#endif
#include "dpe_sbuf.h"
#include "dpe_tx_data.h"
#include "hmac_tid_sche.h"
#include "hmac_tx_switch.h"
#include "hmac_tx_sche_switch_fsm.h"
#include "dpe_tx_data.h"
#include "host_hal_dma.h"
#include "dpe_wlan_resource.h"
#include "dpe_wlan_config.h"
#include "dpe_wlan_stat.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DRIVER_HMAC_TX_MSDU_DSCR_C

#define oal_make_word64(lsw, msw) ((((uint64_t)(msw) << 32) & 0xFFFFFFFF00000000) | (lsw))

/* 4 函数实现 */
/*
 * 功能描述 : 更新ring的发送指针
 * 1.日    期 : 2020年2月12日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 * 2.日    期 : 2020年4月22日
 *   作    者 : wifi
 *   修改内容 : 重构函数
 */
void hmac_tx_msdu_ring_inc_write_ptr(hmac_msdu_info_ring_stru *tx_ring)
{
    un_rw_ptr write_ptr = { .rw_ptr = tx_ring->base_ring_info.write_index };

    hmac_tx_rw_ptr_inc(&write_ptr, hal_host_tx_tid_ring_depth_get(tx_ring->base_ring_info.size));

    tx_ring->base_ring_info.write_index = write_ptr.rw_ptr;
}

/*
 * 功能描述 : 常发拆大函数, hostva映射成devva, 供mac访问host ring内容
 * 1.日    期 : 2020年4月22日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
uint32_t hmac_altx_hostva_to_devva(oal_netbuf_stru *netbuf, uint32_t alloc_size, uint64_t *devva)
{
    uint8_t msdu_dscr_len = hal_host_tx_get_msdu_dscr_len();
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    uint64_t pcie_dma_addr = (uint64_t)oal_netbuf_data_iova(netbuf) - msdu_dscr_len;
    hal_host_tx_netbuf_init_msdu_dscr(netbuf, OAL_TRUE);
#else
    uint64_t pcie_dma_addr;
    uint8_t *msdu_dscr_addr = (uint8_t *)((uint8_t *)oal_netbuf_data(netbuf) - msdu_dscr_len);
    hal_host_tx_netbuf_init_msdu_dscr(netbuf, OAL_TRUE);
    if (hal_host_tx_dma_map_phyaddr(msdu_dscr_addr, alloc_size, &pcie_dma_addr) !=
        OAL_SUCC) {
        return OAL_FAIL;
    }
#endif

    if (pcie_if_hostca_to_devva(HCC_EP_WIFI_DEV, pcie_dma_addr, devva) != OAL_SUCC) {
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
        hal_host_tx_dma_unmap_addr(pcie_dma_addr, alloc_size);
#endif
        return OAL_FAIL;
    }

    return OAL_SUCC;
}

/*
 * 功能描述   : 同步ring更新信息设置
 * 1.日    期   : 2020年4月22日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
OAL_STATIC uint32_t hmac_tx_ring_set_update_info(
    hmac_tid_info_stru *tx_tid_info, tid_update_stru *tid_update_info, tid_cmd_enum_uint8 cmd)
{
    uint8_t msdu_ring_size = sizeof(msdu_info_ring_stru);
    hmac_msdu_info_ring_stru *tx_ring = &tx_tid_info->tx_ring;

    tid_update_info->cmd = cmd;
    tid_update_info->user_id = tx_tid_info->user_index; /* 并行问题？ */
    tid_update_info->tid_no = tx_tid_info->tid_no;
    tid_update_info->update_wptr = !dpe_host_update_wptr_enabled();
    memcpy_s(&tid_update_info->msdu_ring, msdu_ring_size, &tx_ring->base_ring_info, msdu_ring_size);

    return OAL_SUCC;
}

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
OAL_STATIC uint32_t host_tx_sync_h2d_scedule_event(uint8_t vap_idx, wlan_cfgid_enum_uint16 cfg_id, uint16_t us_len,
    uint8_t *payload)
{
    mac_vap_stru *mac_vap = (mac_vap_stru *)mac_res_get_mac_vap(vap_idx);
    if (mac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    return hmac_config_send_event(mac_vap, cfg_id, us_len, payload);
}
#else
uint32_t dpe_tx_sync_h2d_scedule_event(uint8_t vap_idx, wlan_cfgid_enum_uint16 cfg_id, uint16_t us_len,
    uint8_t *payload)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_idx);

    if ((dpe_vap == NULL) || (payload == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_tx_sync_h2d_scedule_event::get dpe_vap fail!");
        return OAL_FAIL;
    }
    return dpe_config_sync_device_send_event(dpe_vap, cfg_id, payload, us_len);
}
#endif

/*
 * 功能描述  : 触发Host to Device调度事件
 * 1.日    期  : 2020年9月11日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_tx_sync_h2d_scedule_event(uint8_t vap_idx, wlan_cfgid_enum_uint16 cfg_id, uint16_t us_len,
    uint8_t *payload)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* DPE流程 */
    return dpe_tx_sync_h2d_scedule_event(vap_idx, cfg_id, us_len, payload);
#else
    /* HMAC流程 */
    return host_tx_sync_h2d_scedule_event(vap_idx, cfg_id, us_len, payload);
#endif
}
#define HMAC_TX_SYNC_RING_INFO_MIN_TIME 1000
/*
 * 功能描述 : 同步ring信息至device
 * 1.日    期 : 2020年4月22日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
uint32_t hmac_tx_sync_ring_info(hmac_tid_info_stru *tx_tid_info, tid_cmd_enum_uint8 cmd)
{
    tid_update_stru tid_update_info = { 0 };
    uint32_t cur_time = (uint32_t)oal_time_get_stamp_ms();
    uint32_t ret;

    if (hmac_tx_ring_set_update_info(tx_tid_info, &tid_update_info, cmd) != OAL_SUCC) {
        return OAL_FAIL;
    }
    if (oal_time_get_runtime(tx_tid_info->last_sync_succ_timestamp, cur_time) < HMAC_TX_SYNC_RING_INFO_MIN_TIME) {
        return OAL_FAIL;
    }

    ret = hmac_tx_sync_h2d_scedule_event(0, WLAN_CFGID_TX_TID_UPDATE,
        sizeof(tid_update_stru), (uint8_t *)&tid_update_info);
    if (ret == OAL_SUCC) {
        tx_tid_info->last_sync_succ_timestamp = cur_time;
    }
    return ret;
}

/*
 * 功能描述 : 释放msdu占用的dma内存地址
 * 1.日    期 : 2020年4月22日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
uint32_t hmac_tx_unmap_msdu_dma_addr(
    hmac_msdu_info_ring_stru *tx_ring, msdu_info_stru *msdu_info, uint32_t netbuf_len)
{
    uint64_t netbuf_iova = 0;
    int32_t ret;

    ret = (int32_t)pcie_if_devva_to_hostca(HCC_EP_WIFI_DEV,
        oal_make_word64(msdu_info->msdu_addr_lsb, msdu_info->msdu_addr_msb), &netbuf_iova);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_tx_unmap_msdu_dma_addr::hostca to devva fail[%d]", ret);
        return (uint32_t)ret;
    }

    return hal_host_tx_dma_unmap_addr(netbuf_iova, netbuf_len + hal_host_tx_get_msdu_dscr_len());
}

void hmac_tx_ring_unmap_netbuf(hmac_msdu_info_ring_stru *tx_ring, oal_netbuf_stru *netbuf, uint16_t release_index)
{
    msdu_info_stru msdu_info = { 0 };

    if (hal_host_tx_get_msdu_ring(&tx_ring->ring_buf, &msdu_info, release_index) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "{hmac_tx_ring_unmap_netbuf::unmap failed!}");
        return;
    }

    hmac_tx_unmap_msdu_dma_addr(tx_ring, &msdu_info, oal_netbuf_len(netbuf));
}

/*
 * 功能描述 : 获取host tid、ring和host rx状态
 * 1.日    期 : 2022.1.17
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
uint32_t hmac_get_host_ring_state(frw_event_mem_stru *event_mem)
{
    return dpe_get_host_ring_state();
}
#endif

oal_netbuf_stru *hmac_tx_ring_get_netbuf(hmac_msdu_info_ring_stru *tx_ring, un_rw_ptr netbuf_ptr)
{
    oal_netbuf_stru *cur_netbuf = NULL;
    uint16_t netbuf_index = netbuf_ptr.st_rw_ptr.bit_rw_ptr;
#ifdef _USE_CACHE_PRELOAD
    uint16_t host_ring_size = hal_host_tx_tid_ring_depth_get(tx_ring->base_ring_info.size);
#endif
    if (tx_ring->netbuf_list == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{hmac_tx_ring_get_netbuf::netbuf list is NULL!}");
        return NULL;
    }

    if (tx_ring->netbuf_list[netbuf_index] == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_tx_ring_get_netbuf::netbuf[%d] is NULL!}", netbuf_index);
    }
#ifdef _USE_CACHE_PRELOAD
    if (netbuf_index + 1 < host_ring_size) {
        prefetch_cached_ddr(tx_ring->netbuf_list[netbuf_index + 1]);
    }
#endif
    cur_netbuf = tx_ring->netbuf_list[netbuf_index];
    tx_ring->netbuf_list[netbuf_index] = NULL;
    oal_smp_mb();
    return cur_netbuf;
}

/*
 * 功能描述 : 设置msdu info信息
 * 1.日    期 : 2020年4月22日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC void hmac_tx_set_msdu_info_from_netbuf(dpe_wlan_vap_stru *dpe_vap, msdu_info_stru *msdu_info,
    oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctl, uint64_t devva)
{
    if (tx_ctl == NULL) {
        return;
    }
    msdu_info->msdu_addr_lsb = get_low_32_bits(devva);
    msdu_info->msdu_addr_msb = get_high_32_bits(devva);
    msdu_info->msdu_len = oal_netbuf_len(netbuf);
    msdu_info->data_type = mac_get_cb_data_type(tx_ctl);

    dpe_tx_renew_ip_checksum(msdu_info, netbuf, tx_ctl);

    if (mac_get_cb_data_type(tx_ctl) == DATA_TYPE_80211) {
        msdu_info->more_frag = tx_ctl->st_expand_cb.bit_more_frag;
        msdu_info->frag_num = tx_ctl->st_expand_cb.bit_frag_num;
    }

    if (dpe_vap->en_vap_mode == WLAN_VAP_MODE_BSS_AP && !mac_get_cb_is_4address(tx_ctl)) {
        msdu_info->from_ds = 1;
        msdu_info->to_ds = 0;
    } else if (dpe_vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA && !mac_get_cb_is_4address(tx_ctl)) {
        msdu_info->from_ds = 0;
        msdu_info->to_ds = 1;
    } else {
        msdu_info->from_ds = 1;
        msdu_info->to_ds = 1;
    }
    /* 对于CHBA相关的管理帧不走状态机接口 */
    if (dpe_vap->bit_is_start_chba_vap == OAL_TRUE) {
        msdu_info->from_ds = 0;
        msdu_info->to_ds = 0;
    }
}

/*
 * 功能描述 : 设置msdu info信息
 * 1.日    期 : 2020年2月12日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 * 2.日    期 : 2020年4月22日
 *   作    者 : wifi
 *   修改内容 : 重构函数
 */
OAL_STATIC void hmac_tx_set_msdu_info(dpe_wlan_vap_stru *dpe_vap, hmac_msdu_info_ring_stru *tx_ring,
    oal_netbuf_stru *netbuf, uint64_t devva)
{
    mac_tx_ctl_stru *tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    un_rw_ptr write_ptr = { .rw_ptr = tx_ring->base_ring_info.write_index };
    msdu_info_stru msdu_info = { 0 };

    hmac_tx_set_msdu_info_from_netbuf(dpe_vap, &msdu_info, netbuf, tx_ctl, devva);
    if ((g_wlan_spec_cfg->support_ring_burst_access == OAL_TRUE) &&
        (dpe_is_tx_ring_set_single() != OAL_TRUE)) {
        hal_host_tx_set_ddr_ring(&tx_ring->ring_buf, &msdu_info, write_ptr.st_rw_ptr.bit_rw_ptr,
            tx_ring->base_ring_info.size);
    } else {
        hal_host_tx_set_msdu_ring(&tx_ring->ring_buf, &msdu_info, write_ptr.st_rw_ptr.bit_rw_ptr);
    }
}

/*
 * 功能描述 : 记录入ring的netbuf地址, 用于后续释放
 * 1.日    期 : 2020年4月13日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE void hmac_record_netbuf_addr(hmac_msdu_info_ring_stru *tx_msdu_ring, oal_netbuf_stru *netbuf)
{
    un_rw_ptr write_ptr = { .rw_ptr = tx_msdu_ring->base_ring_info.write_index };

    tx_msdu_ring->netbuf_list[write_ptr.st_rw_ptr.bit_rw_ptr] = netbuf;
}

/*
 * 功能描述 : 将msdu info设置到ring的对应位置上
 * 1.日    期 : 2020年2月12日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 * 2.日    期 : 2020年4月22日
 *   作    者 : wifi
 *   修改内容 : 重构函数
 */
static uint32_t hmac_tx_set_msdu_info_to_ring(
    dpe_wlan_vap_stru *dpe_vap, hmac_msdu_info_ring_stru *tx_msdu_ring, oal_netbuf_stru *netbuf)
{
    uint64_t devva = 0;

    if (oal_unlikely(hmac_tid_ring_full(tx_msdu_ring))) {
        oam_error_log2(0, OAM_SF_DPA, "{hmac_tx_set_msdu_info_to_ring::ring full relptr[0x%x]wptr[0x%d]}",
            tx_msdu_ring->release_index, tx_msdu_ring->base_ring_info.write_index);
        return OAL_FAIL;
    }

    if (hal_host_tx_get_devva(netbuf, &devva) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "{hmac_tx_set_msdu_info_to_ring::hostva to devva failed}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_tx_delay_notify(netbuf, TX_DELAY_SCHED);
    hmac_tx_set_msdu_info(dpe_vap, tx_msdu_ring, netbuf, devva);
    hmac_record_netbuf_addr(tx_msdu_ring, netbuf);
    hmac_tx_msdu_ring_inc_write_ptr(tx_msdu_ring);

    return OAL_SUCC;
}

static inline void hmac_tx_ring_push_msdu_post_proc(hmac_msdu_info_ring_stru *tx_ring, oal_netbuf_stru *netbuf)
{
#ifdef _PRE_WLAN_FEATURE_MINTP
    hmac_mintp_log((uint8_t *)netbuf, MINTP_LOG_LVL_2, MINTP_LOG_DATATYPE_SKB, MINTP_LOG_TYPE_PUSH_RING);
#endif
}

/*
 * 功能描述 : 挂msdu到发送RING上
 * 1.日    期 : 2020年2月12日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 * 2.日    期 : 2020年4月13日
 *   作    者 : wifi
 *   修改内容 : 重构函数
 */
uint32_t hmac_tx_ring_push_msdu(dpe_wlan_vap_stru *dpe_vap, hmac_msdu_info_ring_stru *tx_ring, oal_netbuf_stru *netbuf)
{
    if (hmac_tx_set_msdu_info_to_ring(dpe_vap, tx_ring, netbuf) != OAL_SUCC) {
        return OAL_FAIL;
    }

    hmac_tx_ring_push_msdu_post_proc(tx_ring, netbuf);
    return OAL_SUCC;
}

uint32_t dpe_get_host_ring_state(void)
{
    if (!dpe_host_ring_tx_enabled()) {
        return OAL_SUCC;
    }

    hmac_dump_tid_info();
    /*  协助定位长时间无法进入深睡问题 */
    oam_warning_log4(0, OAM_SF_DPA,
        "hmac_get_host_ring_state::tid empty[%d] (1:empty) ring mpdu[%d] m ddr rx[%d] s ddr rx[%d]",
        hmac_is_tid_empty(), oal_atomic_read(&g_tid_sche_ring_mpdu_num),
        hal_master_is_in_ddr_rx(), hal_slave_is_in_ddr_rx());
    oam_warning_log1(0, OAM_SF_DPA, "hmac_get_host_ring_state::host forbid sleep[%d]",
        oal_atomic_read(&g_wifi_forbid_sleep));

    return OAL_SUCC;
}

static uint32_t hmac_tx_trig_device_softirq(dpe_wlan_vap_stru *dpe_vap)
{
    hal_host_device_stru *hal_device = NULL;
    if (dpe_vap == NULL) {
        return OAL_FAIL;
    }

    hal_device = hal_get_host_device(dpe_vap->hal_dev_id);
    if (hal_device == NULL) {
        return OAL_FAIL;
    }

    hal_host_writel(1, hal_device->soc_regs.w_soft_int_set_aon_reg);
    return OAL_SUCC;
}

void hmac_tx_sched_trigger(uint8_t vap_idx, hmac_tid_info_stru *tid_info)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_idx);
    /* WCPU软中断调度 */
    if (dpe_tx_ring_soft_irq_sched_enabled() && hmac_tx_trig_device_softirq(dpe_vap) == OAL_SUCC) {
        return;
    }
    /* 下发事件调度 */
    hmac_tx_sync_ring_info(tid_info, TID_CMDID_ENQUE);
}
