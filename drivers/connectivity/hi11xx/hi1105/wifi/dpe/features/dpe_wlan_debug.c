
/*
 * Copyright (c) @CompanyNameMagicTag 2025-2025. All rights reserved.
 * 功能说明 : deshell 命令
 * 作    者 : xianglei
 * 创建日期 : 2025年7月1日
 */

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "dpe_wlan_debug.h"
#include "bsp_console.h"
#include "dpe_sbuf.h"
#include "dpe_wlan_stat.h"
#include "dpe_wlan_resource.h"
#include "dpe_tx_data.h"
#include "host_hal_ring.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_WLAN_DEBUG_C

static void trx_busy(void)
{
    wlan_pm_ring_stat *wlan_pm_info = wlan_pm_get_ring_stat();
    bsp_print("trx_busy::tid_not_empty_cnt[%d], ring_has_mpdu_cnt[%d], master_ddr_rx_cnt[%d], slave_ddr_rx_cnt[%d]\n",
        wlan_pm_info->tid_not_empty_cnt, wlan_pm_info->ring_has_mpdu_cnt, wlan_pm_info->master_ddr_rx_cnt,
        wlan_pm_info->slave_ddr_rx_cnt);
    bsp_print("trx_busy::tid_ring_host_cnt[%d], host_forbid_sleep_cnt[%d]\n",
        wlan_pm_info->tid_ring_host_cnt, wlan_pm_info->host_forbid_sleep_cnt);
}

uint32_t g_add_timer_cnt = 0;
uint32_t g_del_timer_cnt = 0;
uint32_t g_del_timer_smt_cnt = 0; // 跨核删除timer个数统计
uint32_t g_netbuf_in_cnt[EN_NETBUF_IN_BUTT] = { 0 };
uint32_t g_netbuf_out_cnt[EN_NTBUF_OUT_BUTT] = { 0 };

uint32_t dpe_get_netbuf_cnt_total(uint32_t *record, uint32_t max_len)
{
    uint32_t total_cnt = 0;
    uint32_t idx = 0;
    for (idx = 0; idx < max_len; idx++) {
        total_cnt += record[idx];
    }
    return total_cnt;
}

void dpe_netbuf_dump(void)
{
    uint32_t netbuf_in_total = dpe_get_netbuf_cnt_total(g_netbuf_in_cnt, EN_NETBUF_IN_BUTT);
    uint32_t netbuf_out_total = dpe_get_netbuf_cnt_total(g_netbuf_out_cnt, EN_NTBUF_OUT_BUTT);

    oam_warning_log3(0, OAM_SF_DPA, "wifi dpe own sbuf numbers:own total[%d], send total[%d], diff[%d]",
        netbuf_in_total, netbuf_out_total, netbuf_in_total - netbuf_out_total);
    oam_warning_log2(0, OAM_SF_DPA, "netbuf alloc cnt:rx_alloc[%d], frw_alloc[%d]",
        g_netbuf_in_cnt[EN_RX_ALLOC], g_netbuf_in_cnt[EN_FRW_ALLOC]);
    oam_warning_log4(0, OAM_SF_DPA, "netbuf in cnt: hcc_rx[%d] acpu_rx[%d] modem_rx[%d], dpa_stack_rx[%d]",
        g_netbuf_in_cnt[EN_HCC_RX], g_netbuf_in_cnt[EN_XMIT_GSO],
        g_netbuf_in_cnt[EN_XMIT_MODEM], g_netbuf_in_cnt[EN_XMIT_TPCIP]);
    oam_warning_log4(0, OAM_SF_DPA, "netbuf out cnt:wifi_free[%d], filter_input[%d], hcc_tx_wcpu[%d], hcc_tx_acpu[%d]",
        g_netbuf_out_cnt[EN_FREE_NETBUF], g_netbuf_out_cnt[EN_FILTER_INPUT],
        g_netbuf_out_cnt[EN_HCC_TX_WCPU], g_netbuf_out_cnt[EN_HCC_TX_ACPU]);
}
// 打开/关闭wifi时打印资源类计数维测，可识别内存泄漏类问题
void dpe_resource_dump(void)
{
    oam_warning_log3(0, OAM_SF_DPA, "dpe_resource_dump::spin lock:alloc succ:%d, free cnt:%d, delta:%d",
        g_spin_lock_alloc_succ_cnt, g_spin_lock_free_cnt, g_spin_lock_alloc_succ_cnt - g_spin_lock_free_cnt);
    oam_warning_log4(0, OAM_SF_DPA, "dpe_resource_dump::timer :add timer:%d, del timer:%d, delta:%d, smt_del_timer[%d]",
        g_add_timer_cnt, g_del_timer_cnt, g_add_timer_cnt - g_del_timer_cnt, g_del_timer_smt_cnt);
    dpe_netbuf_dump();
}

void dpe_rx_async_debug_show(void)
{
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
    host_rx_comp_buff_pool_stru *rx_buff = hal_host_get_rx_buff_pool();
    dma_rx_comp_stru *rx_dma = dpe_get_rx_comp_hdl();
    hal_host_device_stru *hal_dev = hal_get_host_device(0);
    oam_warning_log4(0, OAM_SF_DPA, "add buff cnt: %d isr rpt cnt: %d rx dma done cnt: %d dma fail cnt: %d",
        rx_stats->rx_add_buff_cnt, rx_stats->rx_isr_rpt_cnt, rx_stats->rx_dma_done_cnt, rx_stats->rx_dma_fail_cnt);
    if (rx_stats->rx_data_msdu_cnt != 0) {
        oam_warning_log4(0, OAM_SF_DPA, "rx data mpdu cnt: %d msdu cnt: %d drop cnt: %d crc err percnt %d",
            rx_stats->rx_data_mpdu_cnt, rx_stats->rx_data_msdu_cnt, rx_stats->rx_drop_cnt,
            rx_stats->rx_drop_cnt * 100 / rx_stats->rx_data_msdu_cnt); // 100:百分比
    }
    oam_warning_log4(0, OAM_SF_DPA, "filter input succ: %d filter input fail: %d alloc fail: %d qemtpy cnt: %d",
        rx_stats->rx_filter_input_cnt, rx_stats->rx_filter_input_fail_cnt, rx_stats->rx_alloc_fail_cnt,
        rx_stats->rx_host_ring_empty_cnt);
    if (rx_stats->rx_data_mpdu_cnt != 0) {
        oam_warning_log4(0, OAM_SF_DPA, "filter input waitlist %d ping-pong %d rx buff pool %d amsdu level %d",
            rx_stats->rx_rpt_wait_list_cnt, rx_stats->rx_add_buff_cnt - rx_stats->rx_dma_done_cnt,
            rx_buff->sbuf_num, rx_stats->rx_data_msdu_cnt / rx_stats->rx_data_mpdu_cnt);
    }
    dpe_netbuf_dump();
    oam_warning_log3(0, OAM_SF_DPA, "rx buff pool overrun: fiber proc %d enqueue %d event 0x%x",
        g_rx_comp_mgmt.rx_data_thread_info.proc_msg_cnt,
        g_rx_comp_mgmt.rx_data_thread_info.enqueue_msg_cnt[0] +
        g_rx_comp_mgmt.rx_data_thread_info.enqueue_msg_cnt[1],
        g_rx_comp_mgmt.rx_data_thread_info.fiber_event_type[0] |
        g_rx_comp_mgmt.rx_data_thread_info.fiber_event_type[1]);
    oam_warning_log3(0, OAM_SF_DPA, "rx buff pool overrun: dma cur state %d next state %d num %d",
        rx_dma->dma_cur_state, rx_dma->dma_next_state, rx_dma->dma_list_num);
    oam_warning_log2(0, OAM_SF_DPA, "rx alloc list free: %d remain cnt: %d", rx_stats->rx_alloc_list_free,
        oal_netbuf_list_len(&hal_dev->host_rx_normal_alloc_list.rx_alloc_list));
}

void dpe_tx_debug_show(void)
{
    dpe_wlan_tx_stat_stru *dpe_tx_stat = dpe_wlan_tx_stat_get();
    oam_warning_log4(0, 0, "tx gso output data: %d output devtx: %d dpa trans: %d altx: %d",
        dpe_tx_stat->tx_gso_output_data, dpe_tx_stat->tx_gso_output_devtx,
        dpe_tx_stat->tx_gso_output_dpa_trans, dpe_tx_stat->tx_gso_output_altx);
    oam_warning_log4(0, 0, "tx tid enq: %d tx host push ring: %d tx device ring: %d tx comp host ring: %d",
        dpe_tx_stat->tx_tid_enq, dpe_tx_stat->tx_host_push_ring_cnt,
        dpe_tx_stat->tx_device_ring_cnt, dpe_tx_stat->tx_host_ring_tx_comp);
    oam_warning_log1(0, 0, "tx_tiq_queue_release: %d", dpe_tx_stat->tx_tiq_queue_release);
}

void dpe_wlan_debug_hipriv_sync(uint8_t *buf)
{
    uint32_t ctrl;
    hmac_to_dpe_hipriv_stru *msg = (hmac_to_dpe_hipriv_stru *)buf;
    if (msg == NULL) {
        return;
    }

    switch (msg->sub_type & 0xFFFF) {
        case DPE_TX_LOG:
            dpe_tx_debug_show();
            break;
        case DPE_RX_LOG:
            dpe_rx_async_debug_show();
            break;
        case DPE_TX_DELAY:
            ctrl = (msg->sub_type >> 16) & 0xFFFF; // 16表示half word
            dpe_wlan_tx_delay_print(ctrl);
            break;
        case DPE_RX_DELAY:
            ctrl = (msg->sub_type >> 16) & 0xFFFF; // 16表示half word
            dpe_wlan_rx_delay_print(ctrl);
            break;
        default:
            break;
    }
}
/* 07C debug使用 */
void dpe_rx_msdu_dscr_parse(oal_netbuf_stru *netbuf)
{
    rx_msdu_dscr_stru *rx_hw_dscr = (rx_msdu_dscr_stru *)dpe_get_rx_msdu_dscr_addr(netbuf);
    bsp_print("ppdu_host_buf_addr_lsb: 0x%x\n", rx_hw_dscr->ppdu_host_buf_addr_lsb  );
    bsp_print("ppdu_host_buf_addr_msb: 0x%x\n", rx_hw_dscr->ppdu_host_buf_addr_msb  );
    bsp_print("next_sub_msdu_addr_lsb: 0x%x\n", rx_hw_dscr->next_sub_msdu_addr_lsb  );
    bsp_print("next_sub_msdu_addr_msb: 0x%x\n", rx_hw_dscr->next_sub_msdu_addr_msb  );
    bsp_print("start_seqnum          : 0x%x\n", rx_hw_dscr->start_seqnum            );
    bsp_print("mcast_bcast           : 0x%x\n", rx_hw_dscr->mcast_bcast             );
    bsp_print("eosp                  : 0x%x\n", rx_hw_dscr->eosp                    );
    bsp_print("is_amsdu              : 0x%x\n", rx_hw_dscr->is_amsdu                );
    bsp_print("first_sub_msdu        : 0x%x\n", rx_hw_dscr->first_sub_msdu          );
    bsp_print("sub_msdu_num          : 0x%x\n", rx_hw_dscr->sub_msdu_num            );
    bsp_print("rx_protocol_mode      : 0x%x\n", rx_hw_dscr->rx_protocol_mode        );
    bsp_print("rx_status             : 0x%x\n", rx_hw_dscr->rx_status               );
    bsp_print("process_flag          : 0x%x\n", rx_hw_dscr->process_flag            );
    bsp_print("release_is_valid      : 0x%x\n", rx_hw_dscr->release_is_valid        );
    bsp_print("release_start_seqnum  : 0x%x\n", rx_hw_dscr->release_start_seqnum    );
    bsp_print("release_end_seqnum    : 0x%x\n", rx_hw_dscr->release_end_seqnum      );
    bsp_print("rx_ppdu_intr_seq      : 0x%x\n", rx_hw_dscr->rx_ppdu_intr_seq        );
    bsp_print("pn_lsb                : 0x%x\n", rx_hw_dscr->pn_lsb                  );
    bsp_print("pn_msb                : 0x%x\n", rx_hw_dscr->pn_msb                  );
    bsp_print("frame_control         : 0x%x\n", rx_hw_dscr->frame_control           );
    bsp_print("user_id               : 0x%x\n", rx_hw_dscr->user_id                 );
    bsp_print("band_id               : 0x%x\n", rx_hw_dscr->band_id                 );
    bsp_print("link_id               : 0x%x\n", rx_hw_dscr->link_id                 );
    bsp_print("vap_id                : 0x%x\n", rx_hw_dscr->vap_id                  );
    bsp_print("is_ampdu              : 0x%x\n", rx_hw_dscr->is_ampdu                );
    bsp_print("ba_session_vld        : 0x%x\n", rx_hw_dscr->ba_session_vld          );
    bsp_print("bar_flag              : 0x%x\n", rx_hw_dscr->bar_flag                );
    bsp_print("tid                   : 0x%x\n", rx_hw_dscr->tid                     );
    bsp_print("cipher_type           : 0x%x\n", rx_hw_dscr->cipher_type             );
    bsp_print("fragment_num          : 0x%x\n", rx_hw_dscr->fragment_num            );
    bsp_print("sequence_num          : 0x%x\n", rx_hw_dscr->sequence_num            );
    bsp_print("packet_len            : 0x%x\n", rx_hw_dscr->packet_len              );
    bsp_print("dst_user_id           : 0x%x\n", rx_hw_dscr->dst_user_id             );
    bsp_print("dst_band_id           : 0x%x\n", rx_hw_dscr->dst_band_id             );
    bsp_print("ptlcs_valid           : 0x%x\n", rx_hw_dscr->ptlcs_valid             );
    bsp_print("ptlcs_pass            : 0x%x\n", rx_hw_dscr->ptlcs_pass              );
    bsp_print("dst_vap_id            : 0x%x\n", rx_hw_dscr->dst_vap_id              );
    bsp_print("rx_data_type          : 0x%x\n", rx_hw_dscr->rx_data_type            );
    bsp_print("frame_format          : 0x%x\n", rx_hw_dscr->frame_format            );
    bsp_print("ipv4cs_valid          : 0x%x\n", rx_hw_dscr->ipv4cs_valid            );
    bsp_print("ipv4cs_pass           : 0x%x\n", rx_hw_dscr->ipv4cs_pass             );
    bsp_print("rsv4                  : 0x%x\n", rx_hw_dscr->rsv4                    );
    bsp_print("dst_is_valid          : 0x%x\n", rx_hw_dscr->dst_is_valid            );
    bsp_print("rpt_rssi_0ch_msb      : 0x%x\n", rx_hw_dscr->rpt_rssi_0ch_msb        );
    bsp_print("rpt_rssi_1ch_msb      : 0x%x\n", rx_hw_dscr->rpt_rssi_1ch_msb        );
    bsp_print("rpt_rssi_2ch_msb      : 0x%x\n", rx_hw_dscr->rpt_rssi_2ch_msb        );
}

static void trx_switch(void)
{
    bsp_print("trx_switch:bit6~bit11, dpe_support[%d,%d,%d,%d,%d,%d]\n",
        g_dpe_trx_switch.is_support_dpe_offload, g_dpe_trx_switch.is_support_80211_rx_filter,
        g_dpe_trx_switch.is_support_device_tx_gso, g_dpe_trx_switch.is_support_host_rx_dma_async,
        g_dpe_trx_switch.is_support_tx_no_dma, g_dpe_trx_switch.is_support_dev_rx_no_dma);
}
console_cmd_regist(trx_switch, 0, 1);

void dpe_wlan_debug_cosole_register(void)
{
    bsp_mo_cmd_regist("tx_debug", (console_cmd_t)dpe_tx_debug_show, 0, 1);
    bsp_mo_cmd_regist("rx_debug", (console_cmd_t)dpe_rx_async_debug_show, 0, 1);
    bsp_mo_cmd_regist("rx_delay", (console_cmd_t)dpe_wlan_rx_delay_print, 1, 1);
    bsp_mo_cmd_regist("tx_delay", (console_cmd_t)dpe_wlan_tx_delay_print, 1, 1);
    bsp_mo_cmd_regist("trx_busy", (console_cmd_t)trx_busy, 0, 1);
    bsp_mo_cmd_regist("dpe_resource_dump", (console_cmd_t)dpe_resource_dump, 0, 1);
}
#endif