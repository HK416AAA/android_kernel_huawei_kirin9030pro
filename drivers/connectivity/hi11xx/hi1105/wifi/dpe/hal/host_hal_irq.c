/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : HOST HAL MAIN
 * 作    者 :
 * 创建日期 : 2020年06月14日
 */

#include "oal_util.h"
#include "oal_net.h"
#include "oal_ext_if.h"
#include "oam_ext_if.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "pcie_linux.h"
#else
#include "pcie_host.h"
#endif
#include "pcie_host.h"
#include "host_hal_ext_if.h"
#include "host_hal_ops.h"
#include "host_hal_ring.h"
#include "host_hal_dscr.h"
#include "dpe_wlan_device.h"
#include "hmac_host_performance.h"
#include "hmac_rx_complete.h"
#include "hmac_tx_complete.h"
#include "hd_trx_data.h"
#include "dpe_wlan_stat.h"
#include "host_hal_irq.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HOST_HAL_IRQ_C

OAL_PL1_DATA uint32_t g_int_state_reg_val = 0;
OAL_PL1_DATA uint32_t g_int_mask_reg_val = 0;

#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
uint8_t hmac_tx_comp_need_scheduled(mdrv_order_msg *msg, uint32_t event)
{
    uint8_t id = 0;
    uint32_t begin = 0;
    uint32_t end   = 0;
    uint32_t pend_num = 0;
    uint8_t core_id = mdrv_get_core_id();
    if (unlikely(core_id >= CORE_NUM)) {
        return OAL_FALSE;
    }

    begin = g_tx_comp_mgmt.thread_info.proc_msg_cnt;
    for (; id < CORE_NUM; id++) {
        end += g_tx_comp_mgmt.thread_info.enqueue_msg_cnt[id];
    }
    pend_num = word_delta(begin, end);

    /* 标记事件类型, 与task的event保持一样处理 */
    g_tx_comp_mgmt.thread_info.fiber_event_type[core_id] |= event;

    if (pend_num >= FIBER_QUEUE_SIZE) { // 缓存MAX
        g_tx_comp_mgmt.thread_info.overflow_cnt[core_id]++;
        return OAL_FALSE;
    }

    /* 传递数据 */
    msg->load[0] = 0;
    msg->load[1] = 0;
    g_tx_comp_mgmt.thread_info.enqueue_msg_cnt[core_id]++;
    return OAL_TRUE;
}

uint8_t hmac_rx_comp_need_scheduled(mdrv_order_msg *msg, uint32_t event, uint8_t is_irq)
{
    uint8_t thres = (is_irq == OAL_TRUE) ? FIBER_QUEUE_IRQ_SIZE : FIBER_QUEUE_SIZE;
    uint8_t id = 0;
    uint32_t begin = 0;
    uint32_t end   = 0;
    uint32_t pend_num = 0;
    oal_uint lock_flag;
    uint8_t core_id = mdrv_get_core_id();
    if (unlikely(core_id >= CORE_NUM)) {
        return OAL_FALSE;
    }

    oal_mdrv_int_lock(&lock_flag);
    begin = g_rx_comp_mgmt.thread_info.proc_msg_cnt;
    /* 所有core的计数相加 */
    for (; id < CORE_NUM; id++) {
        end += g_rx_comp_mgmt.thread_info.enqueue_msg_cnt[id];
    }
    pend_num = word_delta(begin, end);

    /* 标记事件类型, 与task的event保持一样处理 */
    g_rx_comp_mgmt.thread_info.fiber_event_type[core_id] |= event;

    /* 为add buff fiber中抛的DMA_START事件固定预留5个计数，防止中断太多，丢失关键事件 */
    if (pend_num >= thres) { // 缓存MAX
        g_rx_comp_mgmt.thread_info.overflow_cnt[core_id]++;
        oal_mdrv_int_unlock(&lock_flag);
        return OAL_FALSE;
    }

    /* 传递数据 */
    msg->load[0] = 0;
    msg->load[1] = 0;
    g_rx_comp_mgmt.thread_info.enqueue_msg_cnt[core_id]++;
    oal_mdrv_int_unlock(&lock_flag);
    return OAL_TRUE;
}

uint8_t hal_rx_data_need_scheduled(mdrv_order_msg *msg, uint32_t event, uint8_t is_irq)
{
    uint8_t thres = (is_irq == OAL_TRUE) ? FIBER_QUEUE_IRQ_SIZE : FIBER_QUEUE_SIZE;
    uint8_t id = 0;
    uint32_t begin = 0;
    uint32_t end   = 0;
    uint32_t pend_num = 0;
    oal_uint lock_flag;
    uint8_t core_id = mdrv_get_core_id();
    if (unlikely(core_id >= CORE_NUM)) {
        return OAL_FALSE;
    }
    oal_mdrv_int_lock(&lock_flag);
    begin = g_rx_comp_mgmt.rx_data_thread_info.proc_msg_cnt;

    for (; id < CORE_NUM; id++) {
        end += g_rx_comp_mgmt.rx_data_thread_info.enqueue_msg_cnt[id];
    }
    pend_num = word_delta(begin, end);

    /* 标记事件类型, 与task的event保持一样处理 */
    g_rx_comp_mgmt.rx_data_thread_info.fiber_event_type[core_id] |= event;

    if (pend_num >= thres) { // 缓存MAX
        g_rx_comp_mgmt.rx_data_thread_info.overflow_cnt[core_id]++;
        oal_mdrv_int_unlock(&lock_flag);
        return OAL_FALSE;
    }

    /* 传递数据 */
    msg->load[0] = 0;
    msg->load[1] = 0;
    g_rx_comp_mgmt.rx_data_thread_info.enqueue_msg_cnt[core_id]++;
    oal_mdrv_int_unlock(&lock_flag);
    return OAL_TRUE;
}
#endif

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
void hal_clear_host_mac_irq_mask(void)
{
    uint32_t mask = 0xffffffff;
    hal_host_device_stru *hal_dev = hal_pcie_down_get_hal_dev(0);
    dpe_wlan_device_stru *dpe_device = dpe_wlan_device_get(0);

    if (hal_dev == NULL || dpe_device == NULL) {
        return;
    }

    hal_get_host_mac_int_mask(hal_dev, &mask);
    dpe_device->pre_host_mac_irq_mask = mask;
    hal_set_host_mac_int_mask(hal_dev, 0xffffffff);
    oam_warning_log1(0, OAM_SF_DPA, "{clear_host_mac_irq_mask: pcie_switch irq mask[0x%x].}", mask);
}

void hal_recover_host_mac_irq_mask(void)
{
    hal_host_device_stru *hal_dev = NULL;
    dpe_wlan_device_stru *dpe_device = dpe_wlan_device_get(0);

    if (dpe_device == NULL) {
        return;
    }
    hal_dev = hal_pcie_down_get_hal_dev(0);
    if (hal_dev == NULL) {
        return;
    }
    hal_set_host_mac_int_mask(hal_dev, dpe_device->pre_host_mac_irq_mask);
    oam_warning_log1(0, OAM_SF_DPA, "{recover_host_mac_irq_mask: pcie_switch irq mask[0x%x].}",
        dpe_device->pre_host_mac_irq_mask);
}

/*
 * 功能描述   : 发消息到中断下半部对收到的MPDU进行处理
 * 1.日    期   : 2020年3月4日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
OAL_STATIC void hal_irq_host_rx_complete_notify(hal_host_device_stru *hal_device)
{
    frw_event_stru           *event = NULL;
    frw_event_mem_stru       *event_mem = NULL;
    hal_host_rx_event        *wlan_rx_event = NULL;

    event_mem = frw_event_alloc_m(sizeof(hal_host_rx_event));
    if (event_mem == NULL) {
        return;
    }

    event = frw_get_event_stru(event_mem);
    frw_event_hdr_init(&(event->st_event_hdr),
                       FRW_EVENT_TYPE_HOST_DDR_DRX,
                       HAL_WLAN_DDR_DRX_EVENT_SUBTYPE,
                       sizeof(hal_host_rx_event),
                       FRW_EVENT_PIPELINE_STAGE_0,
                       0, hal_device->device_id, 0);

    wlan_rx_event = (hal_host_rx_event *)event->auc_event_data;
    wlan_rx_event->hal_dev = hal_device;
    frw_event_dispatch_event(event_mem);
    frw_event_free_m(event_mem);
    return;
}
#endif
/*
 * 功能描述   : free ring 空中断服务例程
 * 1.日    期   : 2019年11月20日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
void hal_irq_host_rx_ring_empty_isr(hal_host_device_stru *hal_device, uint32_t mask)
{
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();

    if (!hal_device->rx_q_inited) {
        oam_error_log1(0, OAM_SF_DPA, "host_rx_ring_empty_isr:: device[%d] not inited", hal_device->device_id);
        oam_warning_log3(0, OAM_SF_DPA, "{host_rx_ring_empty_isr::int status reg[0x%x%x], state val[0x%x]}",
            (uint32_t)(hal_device->mac_regs.irq_status_reg >> NUM_32_BYTES),
            (uint32_t)(hal_device->mac_regs.irq_status_reg), g_int_state_reg_val);
        oam_warning_log3(0, OAM_SF_DPA, "{host_rx_ring_empty_isr::mask reg[0x%x%X], mask val[0x%x]}",
            (uint32_t)(hal_device->mac_regs.irq_status_mask_reg >> NUM_32_BYTES),
            (uint32_t)(hal_device->mac_regs.irq_status_mask_reg), g_int_mask_reg_val);
        return;
    }
    oam_warning_log2(0, OAM_SF_DPA, "{host_rx_ring_empty_isr::int status reg[0x%x], state val[0x%x]}",
        g_int_state_reg_val, g_int_mask_reg_val);

    rx_stats->rx_host_ring_empty_cnt++;
    hmac_rx_comp_trigger_scheduled(hal_device);
}

/*
 * 功能描述   : 将临时netbuf链放入乒乓链表
 * 1.日    期   : 2019年7月4日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
OAL_STATIC void hal_host_rx_mpdu_que_push(hal_rx_mpdu_que *rx_mpdu, oal_netbuf_head_stru *netbuf_head,
    uint32_t *ori_skb_num)
{
    oal_netbuf_head_stru *rx_que = NULL;
    unsigned long         lock_flag;
    dpe_rx_mpdu_list_lock_irq_save(&rx_mpdu->st_spin_lock, &lock_flag);
    rx_que = &(rx_mpdu->ast_rx_mpdu_list[HAL_RX_MPDU_PING]);
    *ori_skb_num = oal_netbuf_list_len(rx_que);
    oal_netbuf_queue_splice_tail_init(netbuf_head, rx_que);
    dpe_rx_mpdu_list_unlock_irq_restore(&rx_mpdu->st_spin_lock, &lock_flag);
}
uint32_t hal_irq_rx_get_ring_data(hal_host_device_stru *hal_device)
{
    oal_netbuf_head_stru         rx_msdu_que;
    uint32_t                     ori_skb_num = 0;

    oal_netbuf_list_head_init_nolock(&rx_msdu_que);
    if (dpe_is_support_isr_rx_sbuf_by_addr() == OAL_TRUE) {
        ori_skb_num = hal_rx_buff_pool_is_empty(hal_device) ? 0 : 1;
    }

    /* 从complete ring上读取元素，并存入临时netbuf上报链表 */
    if (hal_host_rx_ring_entry_get(hal_device, &hal_device->st_host_rx_complete_ring, &rx_msdu_que) != OAL_SUCC) {
        return 1; /* 不需要调度 */
    }
    if (dpe_is_support_isr_rx_sbuf_by_addr() != OAL_TRUE) {
        /* 将临时链表中的元素存入乒乓队列 */
        hal_host_rx_mpdu_que_push(&(hal_device->st_rx_mpdu), &rx_msdu_que, &ori_skb_num);
    }
    
    return ori_skb_num;
}
OAL_STATIC void hal_irq_rx_complete_process(hal_host_device_stru *hal_device)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* dpa上采用线程方式 */
    hal_rx_data_scheduled(hal_device->device_id);
#else
    /* hmac走抛事件流程 */
    hal_irq_host_rx_complete_notify(hal_device);
#endif
}

/*
 * 功能描述   : 接收数据完成中断host处理
 * 1.日    期   : 2018年5月13日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
void hal_irq_host_rx_complete_isr(hal_host_device_stru *hal_device, uint32_t mask)
{
    uint32_t                     ori_skb_num = 0;
    host_start_record_performance(RX_ISR_PROC);

    if (!hal_device->rx_q_inited) {
        oam_error_log1(0, OAM_SF_DPA, "irq_host_mac_isr:: device[%d] not inited", hal_device->device_id);
        oam_warning_log3(0, OAM_SF_DPA, "{hal_irq_host_rx_complete_isr::int status reg[0x%x%x], state val[0x%x]}",
            (uint32_t)(hal_device->mac_regs.irq_status_reg >> NUM_32_BYTES),
            (uint32_t)(hal_device->mac_regs.irq_status_reg), g_int_state_reg_val);
        oam_warning_log3(0, OAM_SF_DPA, "{hal_irq_host_rx_complete_isr::mask reg[0x%x%x], mask val[0x%x]}",
            (uint32_t)(hal_device->mac_regs.irq_status_mask_reg >> NUM_32_BYTES),
            (uint32_t)(hal_device->mac_regs.irq_status_mask_reg), g_int_mask_reg_val);
        return;
    }
    hmac_rx_comp_trigger_scheduled(hal_device);

    /* 中断处理负载 */
    ori_skb_num = hal_irq_rx_get_ring_data(hal_device);
    /* 如果乒乓链表没有数据，抛事件到下半部处理 */
    if (!ori_skb_num) {
        hal_irq_rx_complete_process(hal_device);
    }

    host_end_record_performance(ori_skb_num, RX_ISR_PROC);
}

/*
 * 功能描述   : irq_host_tx_complete_isr中断服务例程
 * 1.日    期   : 2020年05月10日
 *   修改内容   : 新生成函数
 */
void hal_irq_host_tx_complete_isr(hal_host_device_stru *hal_dev, uint32_t mask)
{
    host_start_record_performance(TX_ISR_PROC);

    if (!hal_dev->intr_inited) {
        oam_warning_log1(0, OAM_SF_DPA, "irq_host_tx_complete_isr:: device[%d] not inited", hal_dev->device_id);
        oam_warning_log3(0, OAM_SF_DPA, "{hal_irq_host_rx_complete_isr::int status reg[0x%x%x], state val[0x%x]}",
            (uint32_t)(hal_dev->mac_regs.irq_status_reg >> NUM_32_BYTES),
            (uint32_t)(hal_dev->mac_regs.irq_status_reg), g_int_state_reg_val);
        oam_warning_log3(0, OAM_SF_DPA, "{hal_irq_host_rx_complete_isr::mask reg[0x%x%x], mask val[0x%x]}",
            (uint32_t)(hal_dev->mac_regs.irq_status_mask_reg >> NUM_32_BYTES),
            (uint32_t)(hal_dev->mac_regs.irq_status_mask_reg), g_int_mask_reg_val);
    }
    hmac_set_tx_comp_triggered(hal_dev->device_id);
    hmac_tx_comp_scheduled(hal_dev->device_id);

    host_end_record_performance(1, TX_ISR_PROC);
}

#ifdef _PRE_WLAN_FEATURE_CSI
/*
 * 功能描述   : mp16c_host_ftm_csi_event FTM/CSI事件上报
 * 1.日    期   : 2020年11月18日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
static void hal_host_ftm_csi_event(hal_host_device_stru *hal_device, hal_host_location_isr_stru *ftm_csi_isr_event)
{
    frw_event_mem_stru *event_mem = NULL;
    frw_event_stru *hmac_ftm_csi_event = NULL;

    /* 抛加入完成事件到WAL */
    event_mem = frw_event_alloc_m(sizeof(hal_host_location_isr_stru));
    if (event_mem == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{host_ftm_csi_event::alloc event_mem failed.}\r\n");
        return;
    }
    ftm_csi_isr_event->chip_id = hal_device->chip_id;
    ftm_csi_isr_event->hal_device_id = hal_device->device_id;
    /* 填写事件 */
    hmac_ftm_csi_event = frw_get_event_stru(event_mem);

    /* 填写事件头 */
    frw_event_hdr_init(&(hmac_ftm_csi_event->st_event_hdr), FRW_EVENT_TYPE_HOST_DDR_DRX,
                       HAL_WLAN_FTM_IRQ_EVENT_SUBTYPE,
                       sizeof(hal_host_location_isr_stru), FRW_EVENT_PIPELINE_STAGE_0,
                       0, hal_device->device_id, 0);

    if (memcpy_s(hmac_ftm_csi_event->auc_event_data, sizeof(hal_host_location_isr_stru), ftm_csi_isr_event,
        sizeof(hal_host_location_isr_stru)) != EOK) {
        oam_error_log0(0, OAM_SF_DPA, "host_ftm_csi_event::memcpy fail!");
        frw_event_free_m(event_mem);
        return;
    }

    /* 分发事件 */
    frw_event_dispatch_event(event_mem);
    frw_event_free_m(event_mem);
}

static uint32_t hal_host_ftm_csi_addr_report(uint32_t info_addr_lsb, uint32_t info_addr_msb, uint64_t *addr)
{
    *addr = oal_make_word64(hal_host_readl_irq(info_addr_lsb), hal_host_readl_irq(info_addr_msb));

    if (*addr == 0) {
        oam_warning_log0(0, OAM_SF_DPA, "{host_ftm_csi_addr_report:get addr fail.}");
        return OAL_FAIL;
    }
    return OAL_SUCC;
}
/*
 * 功能描述   : mp16c_irq_host_ftm_csi_isr中断服务例程
 * 1.日    期   : 2020年11月13日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
void hal_irq_host_ftm_csi_isr(hal_host_device_stru *hal_dev, uint32_t mask)
{
    hal_host_location_isr_stru ftm_csi_isr_event;

    if (!hal_dev->intr_inited) {
        oam_error_log4(0, OAM_SF_DPA, "irq_host_ftm_csi_isr:: device[%d]not inited, csi init[%d], \
            ftm init[%d], mask[0x%x]", hal_dev->device_id, hal_dev->csi_regs.inited, hal_dev->ftm_regs.inited, mask);
        oam_warning_log4(0, OAM_SF_DPA, "{irq_host_ftm_csi_isr::int status reg[0x%x], state val[0x%x], \
            mask reg[0x%x], mask val[0x%x]}", hal_dev->mac_regs.irq_status_reg, g_int_state_reg_val,
            hal_dev->mac_regs.irq_status_mask_reg, g_int_mask_reg_val);
        return;
    }

    ftm_csi_isr_event.ftm_csi_info = hal_get_host_ftm_csi_locationinfo(hal_dev);

    // 考虑ftm、csi全上报的情况，取flag bit0 bit1分别进行判断 bit0:csi、bit1:ftm
    if (!ftm_csi_isr_event.ftm_csi_info) {
        oam_error_log0(0, OAM_SF_DPA, "irq_host_ftm_csi_isr::no ftm csi rpt!");
        return;
    }

    if (ftm_csi_isr_event.ftm_csi_info & BIT0) { // CSI上报
        if (hal_host_ftm_csi_addr_report(hal_dev->csi_regs.csi_info_lsb,
            hal_dev->csi_regs.csi_info_msb, &ftm_csi_isr_event.csi_info_addr) != OAL_SUCC) {
            return;
        }
        hal_host_ftm_csi_event(hal_dev, &ftm_csi_isr_event);
    }

    if (ftm_csi_isr_event.ftm_csi_info & BIT1) { // FTM上报
        if (hal_host_ftm_csi_addr_report(hal_dev->ftm_regs.ftm_info_lsb,
            hal_dev->ftm_regs.ftm_info_msb, &ftm_csi_isr_event.ftm_info_addr) != OAL_SUCC) {
            return;
        }
        hal_host_ftm_csi_event(hal_dev, &ftm_csi_isr_event);
    }
}
#endif
