/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description:ete_host.c
 * Author: dpa drivers
 */

#define MPXX_LOG_MODULE_NAME "[PCIE_ETE]"
#define HISI_LOG_TAG           "[PCIE]"

#include "hcc_master.h"
#include "conn_dmi_msg.h"
#include "conn_dmi_flowctrl.h"
#include "dpa_exception_rst.h"
#include "pcie_host.h"
#include "pcie_chip.h"
#include "osl_thread.h"
#include "mdrv_cache.h"
#include "securec.h"
#include "pm_wlan.h"
#include "mp17c/pcie_ctrl_rb_regs.h"
#include "mp17c/host_ctrl_rb_regs.h"
#include "oam_logger.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_ETE_HOST_C

/* netbuf头体是否分离,需要和device同开关 */
uint32_t g_ete_trans_buf_split = 1;

OAL_STATIC pcie_callback_stru g_pcie_ete_intx_callback[PCIE_HOST_CTL_INTR_BUTT];

/* ete intx statistic */
OAL_STATIC uint32_t g_pcie_ete_host_intx_count[PCIE_HOST_CTL_INTR_BUTT] = {0};
OAL_STATIC uint32_t g_pcie_ete_dre_tx_intx_count[ETE_TX_CHANN_MAX_NUMS] = {0};
OAL_STATIC uint32_t g_pcie_ete_dre_rx_intx_count[ETE_RX_CHANN_MAX_NUMS] = {0};
OAL_STATIC uint32_t g_pcie_ete_trans_tx_done_intx_count[ETE_TX_CHANN_MAX_NUMS] = {0};
OAL_STATIC uint32_t g_pcie_ete_trans_tx_err_intx_count[ETE_TX_CHANN_MAX_NUMS] = {0};
OAL_STATIC uint32_t g_pcie_ete_trans_rx_done_intx_count[ETE_RX_CHANN_MAX_NUMS] = {0};
OAL_STATIC uint32_t g_pcie_ete_trans_rx_err_intx_count[ETE_RX_CHANN_MAX_NUMS] = {0};
#ifndef _PRE_LINUX_TEST
extern void hal_host_2g_mac_intr_default_handle(void *para);
extern void hal_host_5g_mac_intr_default_handle(void *para);
#endif

#define ETE_RX_EVENT_RUN        BIT(0)
#define ETE_RX_EVENT_OPEN       BIT(1)
#define ETE_RX_EVENT_CLOSE      BIT(2)
#define ETE_RX_EVENT_DFR        BIT(3)

#define ETE_RX_EVENT (ETE_RX_EVENT_RUN | ETE_RX_EVENT_OPEN | ETE_RX_EVENT_CLOSE | ETE_RX_EVENT_DFR)

typedef struct ete_rx_thread_info {
    mdrv_task_id task_id;
    void *stack_addr;
    uint32_t event_type;
    uint32_t excep_id;
    uint32_t open_flag;
    mdrv_sem_id rx_thread_sem;
} ete_rx_thread_info_t;

static ete_rx_thread_info_t g_ete_rx_thread_info;

// 该数组需与A核及dev保持一致
#define PCIE_ETE_TRANS_MAX_FRAME_LEN        1560
#define ETE_H2D_MAX_BUFF_LEN (HCC_HDR_TOTAL_LEN + PCIE_ETE_TRANS_MAX_FRAME_LEN)
/* ete tx config info */
OAL_STATIC pcie_ete_chan_h2d_res g_pcie_h2d_res_cfg[ETE_TX_CHANN_MAX_NUMS] = {
    /* high queue */
    [ETE_TX_CHANN_0] = {
        .ring_max_num = PCIE_ETE_TX_CHAN0_ENTRY_NUM,
        .enabled = 1,
    },
    /* tae message */
    [ETE_TX_CHANN_1] = {
        .ring_max_num = PCIE_ETE_TX_CHAN1_ENTRY_NUM,
        .enabled = 0,
    },
    /* low queue */
    [ETE_TX_CHANN_2] = {
        .ring_max_num = PCIE_ETE_TX_CHAN2_ENTRY_NUM,
        .enabled = 1,
    },
    /* reserved */
    [ETE_TX_CHANN_3] = {
        .ring_max_num = 0,
        .enabled = 0,
    },
};

#define ETE_D2H_MAX_BUFF_LEN (HCC_HDR_TOTAL_LEN + PCIE_ETE_TRANS_MAX_FRAME_LEN)
/* ete rx config info */
OAL_STATIC pcie_ete_chan_d2h_res g_pcie_d2h_res_config[ETE_RX_CHANN_MAX_NUMS] = {
    /* normal queue */
    [ETE_RX_CHANN_0] = {
        .ring_max_num = PCIE_ETE_RX_CHAN0_ENTRY_NUM,
        .max_len = ETE_D2H_MAX_BUFF_LEN,
        .enabled = 1,
    },
    /* tae message */
    [ETE_RX_CHANN_1] = {
        .ring_max_num = PCIE_ETE_RX_CHAN1_ENTRY_NUM,
        .max_len = ETE_D2H_MAX_BUFF_LEN,
        .enabled = 0,
    },
    /* reserved */
    [ETE_RX_CHANN_2] = {
        .ring_max_num = 0,
        .max_len = ETE_D2H_MAX_BUFF_LEN,
        .enabled = 0,
    },
    /* reserved */
    [ETE_RX_CHANN_3] = {
        .ring_max_num = 0,
        .max_len = ETE_D2H_MAX_BUFF_LEN,
        .enabled = 0,
    },
    /* reserved */
    [ETE_RX_CHANN_4] = {
        .ring_max_num = 0,
        .max_len = ETE_D2H_MAX_BUFF_LEN,
        .enabled = 0,
    },
};

OAL_STATIC OAL_INLINE uint32_t oal_ete_get_netbuf_step(void)
{
    /* 2 is split buff, 1 is not */
    return g_ete_trans_buf_split ? 2 : 1;
}

void oal_ete_sched_hcc_thread(void)
{
    // 触发大循环调度, 执行master_tx事件
    hcc_master_tx_sched_transfer();
}

OAL_STATIC OAL_INLINE int32_t oal_pcie_process_ete_host_intr(pcie_res *pst_pci_res, unsigned int status)
{
    unsigned int bit;
    if (status == 0) {
        return OAL_SUCC;
    }

    /* 从bit0遍历 */
    for (bit = 0; bit < sizeof(status) * 8; bit++) { /* 8 is bits of bytes */
        unsigned int mask = 1 << bit;
        if (status & mask) {
            if (oal_likely((bit < PCIE_HOST_CTL_INTR_BUTT) && (g_pcie_ete_intx_callback[bit].pf_func != NULL))) {
                g_pcie_ete_intx_callback[bit].pf_func(g_pcie_ete_intx_callback[bit].para);
                g_pcie_ete_host_intx_count[bit]++;
            } else {
                oam_warning_log1(0, OAM_SF_DPA, "unregister host intr:%u", bit);
            }
            status &= ~mask;
        }

        if (!status) { /* all done */
            break;
        }
    }

    return OAL_SUCC;
}

OAL_STATIC OAL_INLINE int32_t oal_pcie_process_ete_trans_tx(pcie_res *pst_pci_res,
                                                            unsigned int done, unsigned int err)
{
    unsigned int chan_idx;
    if (!(done | err)) {
        return OAL_SUCC;
    }

    for (chan_idx = 0; chan_idx < ETE_TX_CHANN_MAX_NUMS; chan_idx++) {
        /* process chan tx id */
        unsigned int mask = 1 << chan_idx;
        if (done & mask) {
            oam_info_log4(0, OAM_SF_DPA, "tx chan %u done, trans count:0x%x sr_headptr:0x%x, sr_tailptr:0x%x",
                               chan_idx,
                               pcie_ete_get_tx_done_total_cnt((uintptr_t)pst_pci_res->pst_ete_base, chan_idx),
                               pcie_ete_get_tx_sr_head_ptr((uintptr_t)pst_pci_res->pst_ete_base, chan_idx),
                               pcie_ete_get_tx_sr_tail_ptr((uintptr_t)pst_pci_res->pst_ete_base, chan_idx));
            g_pcie_ete_trans_tx_done_intx_count[chan_idx]++;
            done &= ~mask;

            /* sched tx queue 调用大循环, 复用hcc释放发送完成的netbuf */
            oal_atomic_set(&pst_pci_res->ete_info.h2d_res[chan_idx].tx_sync_cond, 1);
            oal_ete_sched_hcc_thread();
        }
        if (err & mask) {
            oam_error_log1(0, OAM_SF_DPA, "tx chan %u err", chan_idx);
            g_pcie_ete_trans_tx_err_intx_count[chan_idx]++;
            err &= ~mask;
        }
        if (!(done | err)) {
            break;
        }
    }

    return OAL_SUCC;
}

OAL_STATIC OAL_INLINE int32_t oal_pcie_process_ete_trans_rx(pcie_res *pst_pci_res,
                                                            unsigned int done, unsigned int err)
{
    unsigned int chan_idx;
    if (!(done | err)) {
        return OAL_SUCC;
    }

    for (chan_idx = 0; chan_idx < ETE_RX_CHANN_MAX_NUMS; chan_idx++) {
        /* process chan tx id */
        unsigned int mask = 1 << chan_idx;
        if (done & mask) {
            oam_info_log4(0, OAM_SF_DPA, "rx chan %u done, trans count:0x%x dr_headptr:0x%x, dr_tailptr:0x%x",
                               chan_idx,
                               pcie_ete_get_rx_done_total_cnt((uintptr_t)pst_pci_res->pst_ete_base, chan_idx),
                               pcie_ete_get_rx_dr_head_ptr((uintptr_t)pst_pci_res->pst_ete_base, chan_idx),
                               pcie_ete_get_rx_dr_tail_ptr((uintptr_t)pst_pci_res->pst_ete_base, chan_idx));
            g_pcie_ete_trans_rx_done_intx_count[chan_idx]++;
            // 触发大循环调度, 执行ete rx事件
            pcie_ete_rx_sched_transfer(ETE_RX_EVENT_RUN);
            done &= ~mask;
        }
        if (err & mask) {
            oam_error_log1(0, OAM_SF_DPA, "rx chan %u err", chan_idx);
            g_pcie_ete_trans_rx_err_intx_count[chan_idx]++;
            err &= ~mask;
        }
        if (!(done | err)) {
            break;
        }
    }

    return OAL_SUCC;
}

OAL_STATIC OAL_INLINE int32_t oal_pcie_process_ete_trans_intr(pcie_res *pst_pci_res, unsigned int status)
{
    hreg_pcie_ctl_ete_intr_sts pcie_ctl_ete_intr_sts;
    pcie_ctl_ete_intr_sts.as_dword = status;

    oal_pcie_process_ete_trans_tx(pst_pci_res, pcie_ctl_ete_intr_sts.bits.host_tx_done_intr_status,
                                  pcie_ctl_ete_intr_sts.bits.host_tx_err_intr_status);

    oal_pcie_process_ete_trans_rx(pst_pci_res, pcie_ctl_ete_intr_sts.bits.host_rx_done_intr_status,
                                  pcie_ctl_ete_intr_sts.bits.host_rx_err_intr_status);

    return OAL_SUCC;
}

OAL_STATIC OAL_INLINE int32_t oal_pcie_process_ete_dre_tx(pcie_res *pst_pci_res,
                                                          unsigned int tx_dr_empty_sts)
{
    unsigned int chan_idx;
    if (!tx_dr_empty_sts) {
        return OAL_SUCC;
    }

    for (chan_idx = 0; chan_idx < ETE_TX_CHANN_MAX_NUMS; chan_idx++) {
        /* process chan tx id */
        unsigned int mask = 1 << chan_idx;
        if (tx_dr_empty_sts & mask) {
            oam_warning_log1(0, OAM_SF_DPA, "tx dr empty sts %u done", chan_idx);
            g_pcie_ete_dre_tx_intx_count[chan_idx]++;
            /* tx dr empty should done in wcpu */
            tx_dr_empty_sts &= ~mask;
        }

        if (!tx_dr_empty_sts) {
            break;
        }
    }

    return OAL_SUCC;
}

OAL_STATIC OAL_INLINE int32_t oal_pcie_process_ete_dre_rx(pcie_res *pst_pci_res,
                                                          unsigned int rx_dr_empty_sts)
{
    unsigned int chan_idx;

    if (!rx_dr_empty_sts) {
        return OAL_SUCC;
    }

    for (chan_idx = 0; chan_idx < ETE_RX_CHANN_MAX_NUMS; chan_idx++) {
        /* process chan tx id */
        unsigned int mask = 1 << chan_idx;
        if (rx_dr_empty_sts & mask) {
            oam_info_log1(0, OAM_SF_DPA, "rx dr empty sts %u done", chan_idx);
            g_pcie_ete_dre_rx_intx_count[chan_idx]++;
            // 补充内存，触发大循环调度, 执行ete rx事件
            pcie_ete_rx_sched_transfer(ETE_RX_EVENT_RUN);
            rx_dr_empty_sts &= ~mask;
        }

        if (!rx_dr_empty_sts) {
            break;
        }
    }

    return OAL_SUCC;
}

/* ete dr empty intr */
OAL_STATIC OAL_INLINE int32_t oal_pcie_process_ete_dre_intr(pcie_res *pst_pci_res, unsigned int status)
{
    hreg_pcie_ctrl_ete_ch_dr_empty_intr_sts dr_empty_sts;
    dr_empty_sts.as_dword = status;

    oal_pcie_process_ete_dre_tx(pst_pci_res, dr_empty_sts.bits.host_tx_ch_dr_empty_intr_status);
    oal_pcie_process_ete_dre_rx(pst_pci_res, dr_empty_sts.bits.host_rx_ch_dr_empty_intr_status);
    return OAL_SUCC;
}

int32_t oal_pcie_transfer_ete_done(pcie_res *pst_pci_res)
{
    int32_t ret;

    hreg_host_intr_status intr_status;
    hreg_pcie_ctl_ete_intr_sts pcie_ctl_ete_intr_sts;
    hreg_pcie_ctrl_ete_ch_dr_empty_intr_sts dr_empty_sts;

    if (oal_unlikely(pst_pci_res->link_state < PCI_WLAN_LINK_MEM_UP)) {
        oam_error_log1(0, OAM_SF_DPA, "ete int link invaild, link_state:%d",
                       pst_pci_res->link_state);
        pst_pci_res->stat.done_err_cnt++;
        return -OAL_EBUSY;
    }

    if (oal_unlikely(pst_pci_res->pst_pci_ctrl_base == NULL)) {
        return -OAL_ENODEV;
    }

    hreg_get_val(intr_status, pst_pci_res->ete_info.reg.host_intr_sts_addr);
    hreg_get_val(pcie_ctl_ete_intr_sts, pst_pci_res->ete_info.reg.ete_intr_sts_addr);
    hreg_get_val(dr_empty_sts, pst_pci_res->ete_info.reg.ete_dr_empty_sts_addr);

    /* 先清中断 */
    /* host2device_tx_intr host不会单独上报host，其他中断响应时不清楚，等待device响应 */
    intr_status.as_dword = intr_status.as_dword & (~(pst_pci_res->ete_info.int_event_ignore_mask));

    if (intr_status.as_dword != 0) {
        hreg_set_val(intr_status, pst_pci_res->ete_info.reg.host_intr_clr_addr);
    }
    if (pcie_ctl_ete_intr_sts.as_dword != 0) {
        hreg_set_val(pcie_ctl_ete_intr_sts, pst_pci_res->ete_info.reg.ete_intr_clr_addr);
    }
    if (dr_empty_sts.as_dword != 0) {
        hreg_set_val(dr_empty_sts, pst_pci_res->ete_info.reg.ete_dr_empty_clr_addr);
    }

    oam_info_log3(0, OAM_SF_DPA, "intr_status=0x%x, ete_intr_sts=0x%x dr_empty_sts=0x%x",
                       intr_status.as_dword, pcie_ctl_ete_intr_sts.as_dword, dr_empty_sts.as_dword);

    if (oal_unlikely((intr_status.as_dword | pcie_ctl_ete_intr_sts.as_dword | dr_empty_sts.as_dword) == 0)) {
        return 0;
    }

    // 判断最后一个PCIE MEM读操作
    if (oal_unlikely(dr_empty_sts.as_dword == 0xFFFFFFFF) && (oal_pcie_check_link_state(pst_pci_res) == OAL_FALSE)) {
        return -OAL_ENODEV;
    }

    ret = oal_pcie_process_ete_host_intr(pst_pci_res, intr_status.as_dword);
    if (oal_unlikely(ret)) {
        return ret;
    }

    ret = oal_pcie_process_ete_trans_intr(pst_pci_res, pcie_ctl_ete_intr_sts.as_dword);
    if (oal_unlikely(ret)) {
        return ret;
    }

    ret = oal_pcie_process_ete_dre_intr(pst_pci_res, dr_empty_sts.as_dword);
    if (oal_unlikely(ret)) {
        return ret;
    }

    return 0;
}

/* refer to g_pcie_h2d_res_cfg */
OAL_STATIC ete_tx_chann_type g_pcie_hcc2ete_qmap[HCC_NETBUF_QUEUE_BUTT] = {
    [HCC_NETBUF_NORMAL_QUEUE] = ETE_TX_CHANN_2,
    [HCC_NETBUF_HIGH_QUEUE] = ETE_TX_CHANN_0,
};
OAL_STATIC OAL_INLINE ete_tx_chann_type oal_pcie_hcc_qtype_to_ete_qtype(hcc_netbuf_queue_type_t qtype)
{
    return g_pcie_hcc2ete_qmap[qtype];
}

OAL_STATIC OAL_INLINE int32_t ete_send_check_param(pcie_res *pst_pci_res, oal_netbuf_head_stru *pst_head)
{
    if (oal_unlikely(pst_pci_res == NULL || pst_head == NULL)) {
        oam_error_log2(0, OAM_SF_DPA, "invalid input pst_pci_res is 0x%x, pst_head %x",
                       (uint32_t)(uintptr_t)pst_pci_res, (uint32_t)(uintptr_t)pst_head);
        return -OAL_EINVAL;
    }

    /* pcie is link */
    if (oal_unlikely(pst_pci_res->link_state <= PCI_WLAN_LINK_DOWN)) {
        oam_warning_log1(0, OAM_SF_DPA, "linkdown hold the pkt, link_state:%d", pst_pci_res->link_state);
        return 0;
    }

    if (oal_unlikely(oal_netbuf_list_empty(pst_head))) {
        return 0;
    }

    return 1;
}

static int32_t oal_ete_shced_rx_all_chan_thread(pcie_res *pst_pci_res)
{
    uint32_t chan_idx;
    pcie_ete_chan_d2h_res *pst_d2h_res = NULL;

    for (chan_idx = 0; chan_idx < ETE_RX_CHANN_MAX_NUMS; chan_idx++) {
        pst_d2h_res = &pst_pci_res->ete_info.d2h_res[chan_idx];
        if (pst_d2h_res->enabled == 0) {
            continue;
        }
        g_pcie_ete_trans_rx_done_intx_count[chan_idx]++;
        pcie_ete_rx_sched_transfer(ETE_RX_EVENT_RUN);
    }

    return OAL_SUCC;
}

int32_t oal_ete_host_pending_signal_check(pcie_res *pci_res)
{
    int32_t i;
    pcie_ete_chan_h2d_res *pst_h2d_res = NULL;
    /* ETE use bit ops */
    for (i = 0; i < ETE_TX_CHANN_MAX_NUMS; i++) {
        pst_h2d_res = &pci_res->ete_info.h2d_res[i];
        if (pst_h2d_res->enabled == 0) {
            continue;
        }

        if (oal_atomic_read(&pst_h2d_res->tx_sync_cond)) {
            return OAL_TRUE;
        }
    }
    return OAL_FALSE;
}

/* 释放RX通路的资源 */
void oal_ete_rx_res_clean(pcie_res *pst_pci_res)
{
    int32_t i;
    pcie_ete_chan_d2h_res *pst_d2h_res = NULL;
    for (i = 0; i < ETE_RX_CHANN_MAX_NUMS; i++) {
        pst_d2h_res = &pst_pci_res->ete_info.d2h_res[i];
        if (pst_d2h_res->enabled == 0) {
            continue;
        }

        /* 释放RX补充队列 */
        oam_info_log2(0, OAM_SF_DPA, "prepare free rxq[%d] len=%u",
                      i, oal_netbuf_list_len(&pst_d2h_res->rxq));
        hcc_netbuf_clear_list_with_flowctrl(&pst_d2h_res->rxq);

        /* 释放RX预申请队列 */
        oam_info_log2(0, OAM_SF_DPA, "prepare free pre_rxq[%d] len=%u",
                      i, oal_netbuf_list_len(&pst_d2h_res->pre_rxq));
        hcc_netbuf_clear_list_with_flowctrl(&pst_d2h_res->pre_rxq);
        /* 释放RX接收完成队列 */
        oam_info_log2(0, OAM_SF_DPA, "prepare free rx_doneq[%d] len=%u",
                      i, oal_netbuf_list_len(&pst_d2h_res->rx_doneq));
        hcc_netbuf_clear_list_with_flowctrl(&pst_d2h_res->rx_doneq);
        /* reset ringbuf */
        (void)pcie_ete_ringbuf_reset(&pst_d2h_res->ring);
    }
}

void oal_ete_tx_res_clean(pcie_res *pst_pci_res, uint32_t force_clean)
{
    int32_t i;
    pcie_ete_chan_h2d_res *pst_h2d_res = NULL;
    for (i = 0; i < ETE_TX_CHANN_MAX_NUMS; i++) {
        pst_h2d_res = &pst_pci_res->ete_info.h2d_res[i];
        if (pst_h2d_res->enabled == 0) {
            continue;
        }
        /* 释放TX补充队列 */
        oam_warning_log2(0, OAM_SF_DPA, "prepare free txq[%d] len=%u",
                         i, oal_netbuf_list_len(&pst_h2d_res->txq));
        if (force_clean == OAL_FALSE) {
            /* If force clean false, txq had pkts, it's fatal err.
             * If txq not empty, shouldn't allow sleep! */
            if (oal_netbuf_list_len(&pst_h2d_res->txq) != 0) {
                oam_error_log0(0, OAM_SF_DPA, "txq_not_empty_under_lowerpower");
            }
        }
        hcc_netbuf_clear_list_with_flowctrl(&pst_h2d_res->txq);

        oal_atomic_set(&pst_h2d_res->tx_sync_cond, 0);
        (void)pcie_ete_ringbuf_reset(&pst_h2d_res->ring);
    }
}

static int32_t oal_ete_thread_sched(uint8_t* buf, uint16_t buf_len)
{
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }

    oal_ete_shced_rx_all_chan_thread(pst_pci_lres->pst_pci_res);
    return OAL_SUCC;
}

static int32_t oal_ete_transfer_deepwkup_restore(uint8_t* buf, uint16_t buf_len)
{
    int32_t ret;
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }

    // 修改pcie链路状态为MEM_UP
    oal_pcie_change_link_state(pst_pci_lres->pst_pci_res, PCI_WLAN_LINK_MEM_UP);

    ret = oal_ete_ip_init(pst_pci_lres->pst_pci_res);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "oal_ete_ip_init fail %d", ret);
        return -OAL_FAIL;
    }

    // 修改pcie链路状态为WORKUP
    oal_pcie_change_link_state(pst_pci_lres->pst_pci_res, PCI_WLAN_LINK_WORK_UP);

    pm_wlan_set_wkup_sleep_stage(STATE_WAKEUP, WAKEUP_ETE_OPEN);
    return OAL_SUCC;
}

static int32_t oal_ete_transfer_deepsleep_clean(uint8_t* buf, uint16_t buf_len)
{
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }

    // 关闭intx中断
    oal_disable_pcie_irq(pst_pci_lres);

    // 修改pcie链路状态为DEEPSLEEP
    oal_mutex_lock(&pst_pci_lres->pst_pci_res->st_rx_mem_lock);
    oal_pcie_change_link_state(pst_pci_lres->pst_pci_res, PCI_WLAN_LINK_DEEPSLEEP);
    oal_mutex_unlock(&pst_pci_lres->pst_pci_res->st_rx_mem_lock);

    // 清空ete队列
    oal_ete_rx_res_clean(pst_pci_lres->pst_pci_res);
    oal_ete_tx_res_clean(pst_pci_lres->pst_pci_res, OAL_FALSE);

    pm_wlan_set_wkup_sleep_stage(STATE_SLEEP, SLEEP_ETE_CLOSE);
    return OAL_SUCC;
}

static int32_t oal_ete_transfer_rx_supply(uint8_t* buf, uint16_t buf_len)
{
    int32_t ret;
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }

    // ete ringbuf初始化
    ret = oal_ete_rx_ringbuf_build(pst_pci_lres->pst_pci_res);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "oal_ete_rx_ringbuf_init fail %d", ret);
        return -OAL_FAIL;
    }

    // 打开intx中断
    ret = oal_enable_pcie_irq(pst_pci_lres);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "oal_ete_rx_ringbuf_init fail %d", ret);
        oal_ete_rx_res_clean(pst_pci_lres->pst_pci_res);
        return -OAL_FAIL;
    }
    oam_info_log0(0, OAM_SF_DPA, "oal_ete_transfer_rx_supply");
    return OAL_SUCC;
}

int32_t oal_ete_tx_transfer_process(pcie_res *pst_pci_res, uint32_t chan_idx)
{
    uint32_t trans_cnt, trans_cnt_t, netbuf_cnt;
    uint32_t netbuf_trans_cnt = 0;
    oal_netbuf_stru *pst_netbuf = NULL;
    pcie_ete_chan_h2d_res *pst_h2d_res = NULL;
    uint32_t step = oal_ete_get_netbuf_step();
    pst_h2d_res = &pst_pci_res->ete_info.h2d_res[chan_idx];

    trans_cnt = pcie_ete_update_ring_tx_donecnt(&pst_h2d_res->ring, (uintptr_t)pst_pci_res->pst_ete_base, chan_idx);
    if (oal_likely(trans_cnt != PCIE_ETE_INVALID_RD_VALUE)) {
        trans_cnt_t = trans_cnt;
        netbuf_cnt = oal_netbuf_list_len(&pst_h2d_res->txq);
        oam_info_log3(0, OAM_SF_DPA, "txq trans_cnt=%u, txq len=%u done_cnt=%u",
                      trans_cnt, netbuf_cnt, pst_h2d_res->ring.done_cnt);
        if (trans_cnt) {
            pst_h2d_res->ring.done_cnt += trans_cnt;
        }
        /* release trans_cnt netbufs */
        forever_loop() {
            if (pst_h2d_res->ring.done_cnt < step) {
                break;
            }

            pst_netbuf = hcc_netbuf_delist_head_with_flowctrl(&pst_h2d_res->txq);
            if (oal_unlikely(pst_netbuf == NULL)) {
                oam_error_log4(0, OAM_SF_DPA, "ete_tx_underflow[%u] trans_cnt=%u, trans_cnt_t=%u, netbuf_cnt=%u",
                               chan_idx, trans_cnt + 1, trans_cnt_t, netbuf_cnt);
                oal_pcie_trigger_dfr();
                return -OAL_EFAIL; /* DFR Here */
            }
            oal_pcie_tx_netbuf_free(pst_pci_res, pst_netbuf);
            netbuf_trans_cnt++;
            pst_h2d_res->ring.done_cnt -= step;
        }
        if (netbuf_trans_cnt != 0) {
            hcc_tx_assem_count(hcc_get_master_handler(), netbuf_trans_cnt);
        }
    }

    return OAL_SUCC;
}

int32_t oal_ete_host_pending_signal_process(pcie_res *pci_res)
{
    int32_t i;
    int32_t total_cnt = 0;
    pcie_ete_chan_h2d_res *pst_h2d_res = NULL;

    for (i = 0; i < ETE_TX_CHANN_MAX_NUMS; i++) {
        pst_h2d_res = &pci_res->ete_info.h2d_res[i];
        if (oal_atomic_read(&pst_h2d_res->tx_sync_cond)) {
            oal_atomic_set(&pst_h2d_res->tx_sync_cond, 0);
            if (oal_ete_tx_transfer_process(pci_res, i) == OAL_SUCC) {
                total_cnt++;
            }
        }
    }

    return total_cnt;
}

OAL_STATIC OAL_INLINE void oal_ete_init_h2d_sr_descr(h2d_sr_descr *tx_sr, uint64_t dst_addr, uint32_t len)
{
    tx_sr->reserved = 0x4321; /* 0x4321 is flag */
    tx_sr->ctrl.dword = 0;
    tx_sr->addr = dst_addr; /* devva */
    tx_sr->ctrl.bits.nbytes = len;
}

OAL_STATIC OAL_INLINE void oal_ete_dump_send_netbuf(oal_netbuf_stru *pst_netbuf)
{
}

// host smmu/iommu addr to ep ip slave access address(+offset 0x80000000)
OAL_STATIC OAL_INLINE int32_t oal_ete_get_send_ep_slave_addr(pcie_res *pst_pci_res, uint64_t *dst_addr,
                                                             uint64_t pci_dma_addr)
{
    int32_t ret = oal_pcie_host_slave_address_switch(pst_pci_res, pci_dma_addr, dst_addr, OAL_TRUE);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_error_log3(0, OAM_SF_DPA, "slave address switch failed ret=%d iova high:0x%x, low:0x%x",
                           ret, ADDR_HIGH(pci_dma_addr), ADDR_LOW(pci_dma_addr));
    }
    return ret;
}

OAL_STATIC OAL_INLINE void oal_ete_send_netbuf_h2d_enqueue(pcie_ete_chan_h2d_res *pst_h2d_res,
                                                           oal_netbuf_stru *pst_netbuf)
{
    /* netbuf入队 */
    hcc_netbuf_addlist_tail_with_flowctrl(&pst_h2d_res->txq, pst_netbuf);
}

OAL_STATIC OAL_INLINE uint32_t oal_ete_write_ringbuf_by_sendbuf(pcie_ete_chan_h2d_res *pst_h2d_res, h2d_sr_descr *tx_sr,
                                                                oal_netbuf_stru *pst_netbuf, uint32_t len)
{
    uint32_t wr_len;
    /* 硬件需要更新head_ptr才启动传输,可以先写ringbuf */
    wr_len = pcie_ete_ringbuf_write(&pst_h2d_res->ring, (uint8_t *)tx_sr);
    if (oal_unlikely(wr_len == 0)) {
        oam_error_log0(0, OAM_SF_DPA, "ete tx ring write failed");
        hcc_netbuf_free(pst_netbuf);
    }
    return wr_len;
}

/* build tx netbuf, dma map & tx descr build */
OAL_STATIC OAL_INLINE int32_t oal_ete_send_netbuf_list_build(pcie_res *pst_pci_res,
                                                             oal_netbuf_head_stru *pst_head,
                                                             pcie_ete_chan_h2d_res *pst_h2d_res)
{
    int32_t ret;
    int32_t i;
    uint32_t len;
    uint32_t free_cnt, send_cnt;
    uint64_t src_addr;
    uint64_t dst_addr = 0;
    int32_t total_cnt = 0;
    h2d_sr_descr st_tx_sr_item;
    oal_netbuf_stru *pst_netbuf = NULL;

    uint32_t step = oal_ete_get_netbuf_step();

    free_cnt = pcie_ete_ringbuf_freecount(&pst_h2d_res->ring);

    send_cnt = oal_netbuf_list_len(pst_head);
    send_cnt = oal_min((free_cnt / step), send_cnt);

    /* freecount & netbuf_cnt 只增不减 */
    for (i = 0; i < (int32_t)send_cnt; i++) {
        free_cnt = pcie_ete_ringbuf_freecount(&pst_h2d_res->ring);
        if (free_cnt < step) {
            oam_error_log0(0, OAM_SF_DPA, "unexpect ete tx ringbuf empty");
            break;
        }

        /* 取netbuf */
        pst_netbuf = hcc_netbuf_delist_head_with_flowctrl(pst_head);
        if (oal_unlikely(pst_netbuf == NULL)) {
            oam_error_log0(0, OAM_SF_DPA, "unexpect ete txq empty");
            break;
        }

        /* Debug */
        if (oal_unlikely(pst_pci_res->link_state < PCI_WLAN_LINK_WORK_UP)) {
            oam_error_log1(0, OAM_SF_DPA, "oal_pcie_send_netbuf_list loop invaild, link_state:%d",
                           pst_pci_res->link_state);
            hcc_netbuf_free(pst_netbuf);
            return total_cnt;
        }

        oal_ete_dump_send_netbuf(pst_netbuf);
        oam_info_log2(0, OAM_SF_DPA, "ete tx[%u] netbuf 0x%x", pst_h2d_res->chan_idx,
                      (uint32_t)(uintptr_t)pst_netbuf);

        src_addr = (uint64_t)oal_netbuf_hcc_header_iova(pst_netbuf);
        len = HCC_HDR_TOTAL_LEN;
        ret = oal_ete_get_send_ep_slave_addr(pst_pci_res, &dst_addr, src_addr);
        if (oal_unlikely(ret != OAL_SUCC)) {
            hcc_netbuf_free(pst_netbuf);
            return total_cnt;
        }

        oam_info_log3(0, OAM_SF_DPA, "ete_tx_header iova high:0x%x, low:0x%x, len=%u",
                      ADDR_HIGH(src_addr), ADDR_LOW(src_addr), len);
        oam_info_log2(0, OAM_SF_DPA, "ete_tx_header slave addr high:0x%x, low:0x%x",
                      ADDR_HIGH(dst_addr), ADDR_LOW(dst_addr));
        if (g_ete_trans_buf_split) {
            oal_ete_init_h2d_sr_descr(&st_tx_sr_item, dst_addr, HCC_HDR_TOTAL_LEN);
            if (oal_unlikely(oal_ete_write_ringbuf_by_sendbuf(pst_h2d_res, &st_tx_sr_item, pst_netbuf, len) == 0)) {
                continue;
            }
        }

        src_addr = (uint64_t)oal_netbuf_data_iova(pst_netbuf);
        len = oal_netbuf_len(pst_netbuf);
        if (oal_unlikely(len == 0)) {
            oam_error_log0(0, OAM_SF_DPA, "ete len must more than four bytes");
            len = 4; /* ete 传输0长度的描述符会导致挂死,最少4个字节! */
        }

        ret = oal_ete_get_send_ep_slave_addr(pst_pci_res, &dst_addr, src_addr);
        if (oal_unlikely(ret != OAL_SUCC)) {
            hcc_netbuf_free(pst_netbuf);
            return total_cnt;
        }

        oal_ete_init_h2d_sr_descr(&st_tx_sr_item, dst_addr, len);

        st_tx_sr_item.ctrl.bits.src_intr = 1;
        st_tx_sr_item.ctrl.bits.dst_intr = 1;

        oam_info_log4(0, OAM_SF_DPA, "ete_tx_data iova high:0x%x, low:0x%x, len=%u, ctrl=0x%x",
                      ADDR_HIGH(src_addr), ADDR_LOW(src_addr), len, st_tx_sr_item.ctrl.dword);
        oam_info_log2(0, OAM_SF_DPA, "ete_tx_data ep slave addr high:0x%x, low:0x%x",
                      ADDR_HIGH(dst_addr), ADDR_LOW(dst_addr));
        /* 硬件需要更新head_ptr才启动传输,可以先写ringbuf */
        if (oal_unlikely(oal_ete_write_ringbuf_by_sendbuf(pst_h2d_res, &st_tx_sr_item, pst_netbuf, len) == 0)) {
            continue;
        }

        oal_ete_send_netbuf_h2d_enqueue(pst_h2d_res, pst_netbuf);

        total_cnt++;
    }

    if (total_cnt) {
        oam_info_log1(0, OAM_SF_DPA, "h2d tx assem count=%d", total_cnt);
        /* 更新最后一个描述符 */
        pcie_ete_ring_update_tx_sr_hptr(&pst_h2d_res->ring,
                                        (uintptr_t)pst_pci_res->pst_ete_base, pst_h2d_res->chan_idx);
    }

    return total_cnt;
}

int32_t oal_ete_send_netbuf_list(pcie_res *pst_pci_res, oal_netbuf_head_stru *pst_head,
                                 hcc_netbuf_queue_type_t qtype)
{
    int32_t ret;
    uint32_t free_cnt, queue_cnt;
    ete_tx_chann_type tx_chan_num;

    uint32_t step = oal_ete_get_netbuf_step();

    pcie_ete_chan_h2d_res *pst_h2d_res = NULL;

    ret = ete_send_check_param(pst_pci_res, pst_head);
    if (ret <= 0) {
        return ret;
    }

    /* 发送唤醒 */
    ret = pm_wlan_wakeup_dpa_handler(WAKEUP_SOURCE_DPA);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "dpa_wakeup_acpu fail!");
        return ret;
    }

    tx_chan_num = oal_pcie_hcc_qtype_to_ete_qtype(qtype);
    pst_h2d_res = &pst_pci_res->ete_info.h2d_res[tx_chan_num];

    queue_cnt = oal_netbuf_list_len(pst_head);
    free_cnt = pcie_ete_ringbuf_freecount(&pst_h2d_res->ring);
    if (queue_cnt > (free_cnt / step)) {
        /* ringbuf 空间不够, 刷新rd指针，重新判断
         * 刷新rd属于耗时操作，峰值性能应该考虑独立线程，否者会影响hcc rx */
        ret = oal_ete_tx_transfer_process(pst_pci_res, tx_chan_num);
        if (oal_likely(ret == OAL_SUCC)) {
            free_cnt = pcie_ete_ringbuf_freecount(&pst_h2d_res->ring);
        }
    }

    if (free_cnt < step) {
        /* ringbuf 为满，挂起发送线程 */
        return 0;
    }

    oam_info_log3(0, OAM_SF_DPA, "[txq:%d]h2d_ringbuf freecount:%u, qlen:%u",
                  (int32_t)tx_chan_num, free_cnt, queue_cnt);

    return oal_ete_send_netbuf_list_build(pst_pci_res, pst_head, pst_h2d_res);
}

int32_t oal_pcie_ete_tx_is_idle(pcie_res *pst_pci_res, hcc_netbuf_queue_type_t qtype)
{
    uint32_t free_cnt;
    uint32_t step = oal_ete_get_netbuf_step();

    if (oal_warn_on(pst_pci_res == NULL)) {
        oam_warning_log0(0, OAM_SF_DPA, "pci res is null");
        return OAL_FALSE;
    }

    /* pcie is link */
    if (oal_unlikely(pst_pci_res->link_state <= PCI_WLAN_LINK_DOWN)) {
        return OAL_FALSE;
    }

    free_cnt = pcie_ete_ringbuf_freecount(&pst_pci_res->ete_info.h2d_res[g_pcie_hcc2ete_qmap[qtype]].ring);
    oam_info_log1(0, OAM_SF_DPA, "tx is idle free_cnt=%u", free_cnt);
    return ((free_cnt >= step) ? OAL_TRUE : OAL_FALSE);
}

/* check ete tx queue */
int32_t oal_ete_sleep_request_host_check(pcie_res *pci_res)
{
    uint32_t chan_idx;
    uint32_t total_cnt = 0;
    pcie_ete_chan_h2d_res *pst_h2d_res = NULL;
    for (chan_idx = 0; chan_idx < ETE_TX_CHANN_MAX_NUMS; chan_idx++) {
        pst_h2d_res = &pci_res->ete_info.h2d_res[chan_idx];
        if (pst_h2d_res->enabled == 0) {
            continue;
        }
        total_cnt += oal_netbuf_list_len(&pst_h2d_res->txq);
        oam_info_log2(0, OAM_SF_DPA, "chan_idx[%u], total_cnt=%u", chan_idx, total_cnt);
    }
    return (total_cnt != 0) ? -OAL_EBUSY : OAL_SUCC;
}

static int ete_rx_hdr_proc_cbk(dma_chn chn, void *arg)
{
    pcie_ete_chan_d2h_res *pst_d2h_res = NULL;

    if (arg == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "ete_rx_hdr_proc_cbk arg NULL");
        return -OAL_EFAIL;
    }

    pst_d2h_res = (pcie_ete_chan_d2h_res *)arg;

    if (mdrv_sem_up(pst_d2h_res->rx_sem) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "rx_hdr_proc_cbk sem up fail");
        return -OAL_EFAIL;
    }
    return OAL_SUCC;
}

static int32_t oal_pcie_rx_netbuf_pre_malloc(pcie_ete_chan_d2h_res *pst_d2h_res)
{
    int32_t ret = OAL_SUCC;
    uint32_t i;
    int32_t max_len = pst_d2h_res->max_len;
    uint32_t trans_cnt = 0;
    uint32_t qlen = oal_netbuf_list_len(&pst_d2h_res->pre_rxq);
    oal_netbuf_stru *pst_netbuf = NULL;
    peerlist peers[HCC_MAX_PEERS_NUM] = { 0 };
    completed_handler dma_hdl;

    if (oal_unlikely(max_len <= 0)) {
        oam_error_log1(0, OAM_SF_DPA, "invalid max_len =%d ", max_len);
        return -OAL_EINVAL;
    }

    for (i = 0; i < (HCC_MAX_PEERS_NUM - qlen); i++) {
        pst_netbuf = oal_pcie_rx_netbuf_alloc(max_len);
        if (pst_netbuf == NULL) {
            ret = -OAL_ENOMEM;
            goto rxq_pre_malloc_fail;
        }
        peers[i].dst = oal_netbuf_hcc_header(pst_netbuf);
        peers[i].src = (uint64_t)(uintptr_t)(&pst_d2h_res->hdr_flag);
        peers[i].len = sizeof(pst_d2h_res->hdr_flag);
        /* netbuf入队 */
        hcc_netbuf_addlist_tail_with_flowctrl(&pst_d2h_res->pre_rxq, pst_netbuf);
        trans_cnt++;
    }

    if (trans_cnt != 0) {
        dma_hdl.args = pst_d2h_res;
        dma_hdl.dma_cbk = ete_rx_hdr_proc_cbk;

        ret = hcc_dma_memcpy_submit_sync(&dma_hdl, peers, pst_d2h_res->rx_sem, trans_cnt);
        if (ret) {
            oam_error_log0(0, OAM_SF_DPA, "rx buf hdr init failed!");
            goto rxq_pre_malloc_fail;
        }
        oam_info_log1(0, OAM_SF_DPA, "ete rx pre malloc trans_cnt:%u", trans_cnt);
    }
    return ret;

rxq_pre_malloc_fail:
    hcc_netbuf_clear_list_with_flowctrl(&pst_d2h_res->pre_rxq);
    oam_error_log1(0, OAM_SF_DPA, "pcie rxq pre malloc failed, ret:%d", ret);
    return ret;
}

/* 向Hcc层提交收到的netbuf */
static int32_t oal_pcie_rx_netbuf_submit(pcie_ete_chan_d2h_res *pst_d2h_res, oal_netbuf_head_stru *netbuf_rx_header)
{
    int32_t ret;
    uint32_t i = 0;
    uint32_t hdr_value;
    uint32_t trans_cnt = oal_netbuf_list_len(&pst_d2h_res->rx_doneq);
    oal_netbuf_stru *pst_netbuf = NULL;
    oal_netbuf_stru *next_netbuf = NULL;
    completed_handler dma_hdl;
    peerlist peers[HCC_MAX_PEERS_NUM] = { 0 };

    dma_hdl.args = (void *)pst_d2h_res;
    dma_hdl.dma_cbk = ete_rx_hdr_proc_cbk;

    hcc_netbuf_search_for_each(pst_netbuf, &pst_d2h_res->rx_doneq) {
        peers[i].src = oal_netbuf_hcc_header(pst_netbuf);
        peers[i].dst = (uint64_t)(uintptr_t)oal_sbuf_cb(pst_netbuf);
        peers[i++].len = HCC_HDR_TOTAL_LEN;
    }

    /* 包头内容拷贝至CB段，后续HCC或业务使用 */
    ret = hcc_dma_memcpy_submit_sync(&dma_hdl, peers, pst_d2h_res->rx_sem, trans_cnt);
    if (ret) {
        oam_error_log0(0, OAM_SF_DPA, "rx buf hdr check fail");
        goto rx_hdr_check_fail;
    }

    hcc_netbuf_search_for_each_safe(pst_netbuf, next_netbuf, &pst_d2h_res->rx_doneq) {
        pst_netbuf = hcc_netbuf_delist_head_with_flowctrl(&pst_d2h_res->rx_doneq);
        /* CHS平台已解决反压问题，考虑后续同类问题定位困难，此处还是增加包头flag校验 */
        mdrv_cache_invalid(MDRV_DATA_CACHE, (void *)oal_sbuf_cb(pst_netbuf), HCC_HDR_TOTAL_LEN);
        hdr_value = *(uint32_t *)oal_sbuf_cb(pst_netbuf);
        if (hdr_value == PCIE_RX_TRANS_FLAG) {
            oam_error_log3(0, OAM_SF_DPA, "buf_cnt:%d, trans_cnt:%d, err_val:0x%x", i, trans_cnt, hdr_value);
            goto rx_hdr_check_fail;
        }
        hcc_master_rx(pst_netbuf);
    }
    return OAL_SUCC;

rx_hdr_check_fail:
    hcc_netbuf_clear_list_with_flowctrl(&pst_d2h_res->rx_doneq);
    oam_error_log0(0, OAM_SF_DPA, "pcie rx netbuf check failed");
    return -OAL_EFAIL;
}

int32_t oal_ete_rx_transfer_process(pcie_res *pst_pci_res, uint32_t chan_idx)
{
    uint32_t trans_cnt, netbuf_cnt;
    uint32_t netbuf_trans_cnt = 0;
    uint32_t step = oal_ete_get_netbuf_step();
    oal_netbuf_stru *pst_netbuf = NULL;
    pcie_ete_chan_d2h_res *pst_d2h_res = NULL;

    pst_d2h_res = &pst_pci_res->ete_info.d2h_res[chan_idx];

    trans_cnt = pcie_ete_update_ring_rx_donecnt(&pst_d2h_res->ring, (uintptr_t)pst_pci_res->pst_ete_base, chan_idx);
    if (oal_likely(trans_cnt != PCIE_ETE_INVALID_RD_VALUE)) {
        netbuf_cnt = oal_netbuf_list_len(&pst_d2h_res->rxq);
        oam_info_log3(0, OAM_SF_DPA, "rxq trans_cnt=%u, rxq len=%u, done_cnt=%u",
                      trans_cnt, netbuf_cnt, pst_d2h_res->ring.done_cnt);

        if (trans_cnt) {
            pst_d2h_res->ring.done_cnt += trans_cnt;
        }

        /* release trans_cnt netbufs */
        forever_loop() {
            if (pst_d2h_res->ring.done_cnt < step) {
                break;
            }

            pst_netbuf = hcc_netbuf_delist_head_with_flowctrl(&pst_d2h_res->rxq);
            if (oal_unlikely(pst_netbuf == NULL)) {
                oam_error_log3(0, OAM_SF_DPA, "ete_rx_netbuf_underflow[%u] trans_cnt=%u, netbuf_cnt=%u",
                               chan_idx, trans_cnt + 1, netbuf_cnt);
                hcc_netbuf_clear_list_with_flowctrl(&pst_d2h_res->rx_doneq);
                oal_pcie_trigger_dfr();
                return -OAL_EFAIL; /* DFR Here */
            }

            oam_info_log1(0, OAM_SF_DPA, "ete rx netbuf remain=%u", pst_d2h_res->ring.done_cnt);
            hcc_netbuf_addlist_tail_with_flowctrl(&pst_d2h_res->rx_doneq, pst_netbuf);
            netbuf_trans_cnt++;
            pst_d2h_res->ring.done_cnt -= step;
        }
    }
    if (netbuf_trans_cnt != 0) {
        oal_pcie_rx_netbuf_submit(pst_d2h_res, &pst_d2h_res->rx_doneq);

        hcc_rx_assem_count(hcc_get_master_handler(), netbuf_trans_cnt);
        /* 通知线程，补充RX内存 */
        pcie_ete_rx_sched_transfer(ETE_RX_EVENT_RUN);
    }

    return OAL_SUCC;
}

int32_t oal_ete_rx_ringbuf_supply(pcie_res *pst_pci_res,
                                  uint32_t chan_idx,
                                  int32_t is_sync,
                                  int32_t is_up_headptr,
                                  uint32_t request_cnt,
                                  int32_t gflag,
                                  int32_t *ret)
{
    uint32_t i;
    uint32_t cnt = 0;
    uint64_t src_addr;
    uint64_t dst_addr;
    oal_netbuf_stru *pst_netbuf = NULL;
    d2h_dr_descr st_rx_dr_item;
    pcie_ete_chan_d2h_res *pst_d2h_res = NULL;
    uint32_t step = oal_ete_get_netbuf_step();

    *ret = OAL_SUCC;
    pst_d2h_res = &pst_pci_res->ete_info.d2h_res[chan_idx];
    if (pst_d2h_res->enabled == 0) { /* 0 is disable */
        return cnt;
    }

    *ret = oal_pcie_rx_netbuf_pre_malloc(pst_d2h_res);
    if (*ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "ete rx[%d] netbuf_pre_malloc fail", chan_idx);
        return cnt;
    }

    if (is_sync == OAL_TRUE) {
        /* 更新rd指针,处理已经接受完成的报文 */
        oal_ete_rx_transfer_process(pst_pci_res, chan_idx);
    }

    for (i = 0; i < request_cnt; i++) {
        if (pcie_ete_ringbuf_freecount(&pst_d2h_res->ring) < step) {
            /* rx ring full */
            oam_info_log1(0, OAM_SF_DPA, "rx ring chan %u is full", chan_idx);
            break;
        }

        pst_netbuf = hcc_netbuf_delist_head_with_flowctrl(&pst_d2h_res->pre_rxq);

        // 处理hcc 头地址
        src_addr = oal_netbuf_hcc_header_iova(pst_netbuf);
        *ret = oal_ete_get_send_ep_slave_addr(pst_pci_res, &dst_addr, src_addr);
        if (oal_unlikely(*ret != OAL_SUCC)) {
            hcc_netbuf_free(pst_netbuf);
            break;
        }

        /* 头体分离 */
        if (g_ete_trans_buf_split != 0) {
            st_rx_dr_item.addr = dst_addr;
            if (oal_unlikely(pcie_ete_ringbuf_write(&pst_d2h_res->ring,
                (uint8_t *)&st_rx_dr_item) == 0)) {
                oam_error_log0(0, OAM_SF_DPA, "pcie_ete_ringbuf_write failed, fatal error");
                hcc_netbuf_free(pst_netbuf);
                // never should happened
                break;
            }
        }
        oam_info_log2(0, OAM_SF_DPA, "ete_rx_header iova high:0x%x, low:0x%x",
                      ADDR_HIGH(src_addr), ADDR_LOW(src_addr));
        oam_info_log2(0, OAM_SF_DPA, "ete_rx_header slave addr high:0x%x, low:0x%x",
                      ADDR_HIGH(dst_addr), ADDR_LOW(dst_addr));

        // 处理hcc 数据
        src_addr = oal_netbuf_data_iova(pst_netbuf);
        *ret = oal_ete_get_send_ep_slave_addr(pst_pci_res, &dst_addr, src_addr);
        if (oal_unlikely(*ret != OAL_SUCC)) {
            hcc_netbuf_free(pst_netbuf);
            break;
        }

        /* dma_addr 转换成pcie slave地址 */
        st_rx_dr_item.addr = dst_addr;
        if (oal_unlikely(pcie_ete_ringbuf_write(&pst_d2h_res->ring,
            (uint8_t *)&st_rx_dr_item) == 0)) {
            oam_error_log0(0, OAM_SF_DPA, "pcie_ete_ringbuf_write failed, fatal error");
            hcc_netbuf_free(pst_netbuf);
            // never should happened
            break;
        }

        oam_info_log2(0, OAM_SF_DPA, "ete_rx_data iova high:0x%x, low:0x%x",
                      ADDR_HIGH(src_addr), ADDR_LOW(src_addr));
        oam_info_log2(0, OAM_SF_DPA, "ete_rx_data slave addr high:0x%x, low:0x%x",
                      ADDR_HIGH(dst_addr), ADDR_LOW(dst_addr));
        /* 入队 */
        hcc_netbuf_addlist_tail_with_flowctrl(&pst_d2h_res->rxq, pst_netbuf);

        cnt++;
    }

    /* 这里需要考虑HOST/DEVICE的初始化顺序 */
    if (cnt && (is_up_headptr == OAL_TRUE)) {
        pcie_ete_ring_update_rx_dr_hptr(&pst_d2h_res->ring, (uintptr_t)pst_pci_res->pst_ete_base, chan_idx);
    }

    return cnt;
}

/* 预先分配rx的接收buf */
int32_t oal_ete_rx_ringbuf_build(pcie_res *pst_pci_res)
{
    /* 走到这里要确保DEVICE ZI区已经初始化完成， 中断已经注册和使能 */
    int32_t ret;
    int32_t i;
    int32_t supply_num;

    for (i = 0; i < ETE_RX_CHANN_MAX_NUMS; i++) {
        if (pst_pci_res->ete_info.d2h_res[i].enabled != OAL_TRUE) {
            continue;
        }
        supply_num = oal_ete_rx_ringbuf_supply(pst_pci_res, i, OAL_TRUE, OAL_TRUE,
                                               PCIE_RX_RINGBUF_SUPPLY_ALL, 1, &ret);
        if (supply_num == 0) {
            oam_warning_log1(0, OAM_SF_DPA, "oal_pcie_rx_ringbuf_build chan %d can't get any netbufs!", i);
            return -OAL_ENOMEM;
        } else {
            oam_warning_log2(0, OAM_SF_DPA, "oal_pcie_rx_ringbuf_build chan %d got %d netbufs!", i, supply_num);
        }
    }
    pcie_ete_rx_sched_transfer(ETE_RX_EVENT_RUN);
    return OAL_SUCC;
}


/* ete ip 重新初始化接口 */
int32_t oal_ete_chan_tx_ring_init(pcie_res *pst_pci_res)
{
    int32_t i;
    pcie_ete_chan_h2d_res *pst_h2d_res = NULL;

    for (i = 0; i < ETE_TX_CHANN_MAX_NUMS; i++) {
        pst_h2d_res = &pst_pci_res->ete_info.h2d_res[i];
        if (pst_h2d_res->enabled == 0) {
            continue;
        }

        /* 设置TX SR地址 */
        if (oal_unlikely(pst_pci_res->pst_ete_base != NULL)) {
            pcie_ete_tx_sr_hardinit((uintptr_t)pst_pci_res->pst_ete_base, i, &pst_h2d_res->ring);
        } else {
            oam_error_log0(0, OAM_SF_DPA, "pst_ete_base is null");
            return -OAL_ENODEV;
        }

        // ring为DPA申请的uncache内存，必然为32位
        oam_info_log3(0, OAM_SF_DPA, "ete h2d chan%d hardinit succ, io_addr=0x%x, items=%u",
                      i, (uint32_t)pst_h2d_res->ring.io_addr, pst_h2d_res->ring.items);
    }

    return OAL_SUCC;
}

int32_t oal_ete_chan_rx_ring_init(pcie_res *pst_pci_res)
{
    int32_t i;
    pcie_ete_chan_d2h_res *pst_d2h_res = NULL;

    for (i = 0; i < ETE_TX_CHANN_MAX_NUMS; i++) {
        pst_d2h_res = &pst_pci_res->ete_info.d2h_res[i];
        if (pst_d2h_res->enabled == 0) {
            continue;
        }

        /* 设置TX SR地址 */
        if (oal_unlikely(pst_pci_res->pst_ete_base != NULL)) {
            pcie_ete_rx_dr_hardinit((uintptr_t)pst_pci_res->pst_ete_base, i, &pst_d2h_res->ring);
        } else {
            oam_error_log0(0, OAM_SF_DPA, "pst_ete_base is null");
            return -OAL_ENODEV;
        }

        oal_ete_print_ringbuf_info(&pst_d2h_res->ring);
        // ring为DPA申请的uncache内存，必然为32位
        oam_info_log3(0, OAM_SF_DPA, "ete d2h chan%d hardinit succ, io_addr=0x%x, items=%u",
                      i, (uint32_t)pst_d2h_res->ring.io_addr, pst_d2h_res->ring.items);
    }

    return OAL_SUCC;
}

int32_t oal_ete_chan_ring_init(pcie_res *pst_pci_res)
{
    int32_t ret;
    ret = oal_ete_chan_tx_ring_init(pst_pci_res);
    if (ret != OAL_SUCC) {
        return ret;
    }

    ret = oal_ete_chan_rx_ring_init(pst_pci_res);
    if (ret != OAL_SUCC) {
        return ret;
    }

    return ret;
}

int32_t oal_ete_rx_ringbuf_init(void)
{
    int32_t ret;
    oal_pcie_res *pst_pci_lres;
    pst_pci_lres = get_pcie_res();

    /* ringbuf rebuild, after device ete late init! after ete clk en */
    ret = oal_ete_rx_ringbuf_build(pst_pci_lres->pst_pci_res);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "oal_ete_rx_ringbuf_build failed");
        return ret;
    }

    return OAL_SUCC;
}

int32_t oal_ete_ip_init(pcie_res *pst_pci_res)
{
    int32_t ret = pst_pci_res->chip_info.cb.ete_intr_init(pst_pci_res);
    if (ret != OAL_SUCC) {
        return ret;
    }

    ret = oal_ete_chan_ring_init(pst_pci_res);
    if (ret != OAL_SUCC) {
        return ret;
    }

    pcie_dual_enable((uintptr_t)pst_pci_res->pst_ete_base, OAL_FALSE);

    /* enable ete, 必须要在head ptr配置前使能! */
    ret = pcie_ete_clk_en((uintptr_t)pst_pci_res->pst_ete_base,
                          1); /* 0 means disable */
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "ete clk en enable failed!");
        return ret;
    }

    return OAL_SUCC;
}

void oal_ete_ip_exit(pcie_res *pst_pci_res)
{
    /* enable interrupts */
    if (pst_pci_res->pst_pci_ctrl_base == NULL) {
        oam_warning_log0(0, OAM_SF_DPA, "pst_pci_ctrl_base is null");
        return;
    }

    if (oal_unlikely(pst_pci_res->link_state < PCI_WLAN_LINK_MEM_UP)) {
        oam_error_log1(0, OAM_SF_DPA, "ete int link invaild, link_state:%d",
                       pst_pci_res->link_state);
        return;
    }
    oal_writel(0xffffffff, pst_pci_res->ete_info.reg.host_intr_mask_addr);

    /* ete exit应与init对应，此处原有拉低ete_clk_en
     * 此时已在pcie下电流程，wifi下电或进L3后，pcie、ete模块会直接下电
     * 且此处先关闭时钟再disable中断，易引发异常，故此处删除关闭ete时钟动作 */
}

void oal_ete_transfer_res_exit(pcie_res *pst_pci_res)
{
    uint32_t ret;

    pcie_ete_rx_sched_transfer(ETE_RX_EVENT_CLOSE);
    ret = mdrv_sem_down(g_ete_rx_thread_info.rx_thread_sem, OS_WAIT_FOREVER);
    if (ret != MDRV_OK) {
        oam_error_log1(0, OAM_SF_DPA, "ete_res_exit sem_down failed: 0x%x", ret);
    }

    oal_ete_rx_res_clean(pst_pci_res);
    oal_ete_tx_res_clean(pst_pci_res, OAL_TRUE);
}

/* 芯片上电初始化 */
int32_t oal_ete_transfer_res_init(pcie_res *pst_pci_res)
{
    uint32_t ret;
    oal_ete_rx_res_clean(pst_pci_res);
    oal_ete_tx_res_clean(pst_pci_res, OAL_TRUE);

    oal_mutex_lock(&pst_pci_res->st_rx_mem_lock);
    oal_pcie_change_link_state(pst_pci_res, PCI_WLAN_LINK_RES_UP);
    oal_mutex_unlock(&pst_pci_res->st_rx_mem_lock);

    pcie_ete_rx_sched_transfer(ETE_RX_EVENT_OPEN);
    ret = mdrv_sem_down(g_ete_rx_thread_info.rx_thread_sem, OS_WAIT_FOREVER);
    if (ret != MDRV_OK) {
        oam_error_log1(0, OAM_SF_DPA, "ete_res_init sem_down failed: 0x%x", ret);
        return -OAL_EFAIL;
    }
    return OAL_SUCC;
}

void oal_ete_transfer_exception(void)
{
    oal_pcie_res *pci_dpa_res = NULL;
    pcie_res *pcie_res = NULL;

    pci_dpa_res = get_pcie_res();
    if (pci_dpa_res == NULL) {
        return;
    }

    pcie_res = pci_dpa_res->pst_pci_res;
    if (pcie_res == NULL) {
        return;
    }

    oal_mutex_lock(&pcie_res->st_rx_mem_lock);
    oal_pcie_change_link_state(pcie_res, PCI_WLAN_LINK_DOWN);
    oal_mutex_unlock(&pcie_res->st_rx_mem_lock);
    oal_disable_pcie_irq(pci_dpa_res);
    oal_ete_rx_res_clean(pcie_res);
    oal_ete_tx_res_clean(pcie_res, OAL_TRUE);
}

int32_t pcie_wlan_func_register(pcie_wlan_callback_group_stru *pst_func)
{
    if (pst_func == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "ptr NULL");
        return -OAL_ENODEV;
    }

    g_pcie_ete_intx_callback[MAC_5G_INTR_MASK] = pst_func->pcie_mac_5g_isr_callback;
    g_pcie_ete_intx_callback[MAC_2G_INTR_MASK] = pst_func->pcie_mac_2g_isr_callback;
    g_pcie_ete_intx_callback[PHY_5G_INTR_MASK] = pst_func->pcie_phy_5g_isr_callback;
    g_pcie_ete_intx_callback[PHY_2G_INTR_MASK] = pst_func->pcie_phy_2g_isr_callback;
    g_pcie_ete_intx_callback[MAC_COMMON_INTR_MASK] = pst_func->pcie_mac_common_isr_callback;

    return OAL_SUCC;
}

static int32_t oal_ete_rx_hi_thread(void)
{
    int32_t ret;
    int32_t supply_num;
    oal_pcie_res *pst_pci_lres = NULL;
    pcie_res *pst_pcie_res = NULL;
    pcie_ete_chan_d2h_res *pst_d2h_res = NULL;
    ete_rx_chann_type rx_chan_num = 0;

    pst_pci_lres = get_pcie_res();
    if (oal_warn_on(pst_pci_lres == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "error: pst_pci_lres is null");
        return -OAL_EFAIL;
    }

    pst_pcie_res = pst_pci_lres->pst_pci_res;
    if (oal_warn_on(pst_pcie_res == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "error: pst_pci_lres is null");
        return -OAL_EFAIL;
    }

    oal_mutex_lock(&pst_pcie_res->st_rx_mem_lock);
    if (oal_unlikely(pst_pcie_res->link_state < PCI_WLAN_LINK_WORK_UP) || (pst_pcie_res->regions.inited == 0)) {
        oam_warning_log2(0, OAM_SF_DPA, "hi thread link invaild, stop supply mem, link_state:%d, region:%d",
                         pst_pcie_res->link_state, pst_pcie_res->regions.inited);
        oal_mutex_unlock(&pst_pcie_res->st_rx_mem_lock);
        return -OAL_EFAIL;
    }

    for (rx_chan_num = 0; rx_chan_num < ETE_TX_CHANN_MAX_NUMS; rx_chan_num++) {
        pst_d2h_res = &pst_pcie_res->ete_info.d2h_res[rx_chan_num];
        if (pst_d2h_res->enabled == 0) {
            continue;
        }

        supply_num = oal_ete_rx_ringbuf_supply(pst_pcie_res, pst_d2h_res->chan_idx, OAL_TRUE, OAL_TRUE,
                                               PCIE_RX_RINGBUF_SUPPLY_ALL, 1, &ret);
        oam_info_log1(0, OAM_SF_DPA, "oal_ete_rx_hi_thread supply_num:%d", supply_num);
        if (ret != OAL_SUCC) {
            /* 补充内存失败，成功则忽略，有可能当前不需要补充内存也视为成功 */
            oam_error_log0(0, OAM_SF_DPA, "ete_rx supply_num fail");
        }
    }
    oal_mutex_unlock(&pst_pcie_res->st_rx_mem_lock);
    return 0;
}

#define ETE_RX_EVENT_MODE      (OS_EVENT_ANY)
#define ETE_RX_THREAD_SIZE     0x1000

/*
 * 函 数 名  : ete_rx_transfer
 * 功能描述  : ete_rx 线程调度函数
 */
void pcie_ete_rx_sched_transfer(uint32_t event)
{
    mdrv_kevent_send(g_ete_rx_thread_info.task_id, event);
}

/*
 * 函 数 名  : ete_rx_thread_process
 * 功能描述  : ete_rx 线程处理函数
 */
static int32_t ete_rx_thread_process(void *param)
{
    uint32_t ret;
    uint32_t recv_event;
    oam_warning_log0(0, OAM_SF_DPA, "ete_rx_thread_process enter");
    while (1) {
        recv_event = 0;
        mdrv_kevent_recv(g_ete_rx_thread_info.event_type, ETE_RX_EVENT_MODE, OS_EVENT_WAIT_FOREVER, &recv_event);

        if (g_ete_rx_thread_info.open_flag != 1 && ((recv_event & ETE_RX_EVENT_OPEN) != ETE_RX_EVENT_OPEN)) {
            oam_error_log1(0, OAM_SF_DPA, "ete_rx_thread excp, event:0x%x", recv_event);
            continue;
        }

        if ((recv_event & ETE_RX_EVENT_RUN) == ETE_RX_EVENT_RUN) {
            oal_ete_rx_hi_thread();
        }

        if ((recv_event & ETE_RX_EVENT_OPEN) == ETE_RX_EVENT_OPEN) {
            g_ete_rx_thread_info.open_flag = 1;
            ret = mdrv_sem_up(g_ete_rx_thread_info.rx_thread_sem);
            if (ret != MDRV_OK) {
                g_ete_rx_thread_info.open_flag = 0;
                oam_error_log1(0, OAM_SF_DPA, "ete_rx_thread open sem up fail, ret:%x", ret);
            }
        }

        if ((recv_event & ETE_RX_EVENT_CLOSE) == ETE_RX_EVENT_CLOSE) {
            oal_ete_rx_hi_thread();
            g_ete_rx_thread_info.open_flag = 0;
            ret = mdrv_sem_up(g_ete_rx_thread_info.rx_thread_sem);
            if (ret != MDRV_OK) {
                oam_error_log1(0, OAM_SF_DPA, "ete_rx_thread close sem up fail, ret:%x", ret);
            }
        }

        if ((recv_event & ETE_RX_EVENT_DFR) == ETE_RX_EVENT_DFR) {
            oal_ete_transfer_exception(); // 清理内存
            dpa_exception_handler(g_ete_rx_thread_info.excep_id);
        }
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : ete_rx_thread_destory
 * 功能描述  : ete_rx 线程销毁函数
 */
void ete_rx_thread_destory(void)
{
    uint32_t ret;
    ret = mdrv_sem_delete(g_ete_rx_thread_info.rx_thread_sem);
    if (ret != MDRV_OK) {
        oam_error_log1(0, OAM_SF_DPA, "ete_rx_thread_sem delete fail, ret:0x%x", ret);
    }

    ret = mdrv_task_delete(g_ete_rx_thread_info.task_id);
    if (ret != MDRV_OK) {
        oam_error_log1(0, OAM_SF_DPA, "ete_rx_thread destroy fail, ret:0x%x", ret);
    }
    oal_free(g_ete_rx_thread_info.stack_addr);
}

/*
 * 函 数 名  : ete_rx_thread_create
 * 功能描述  : ete_rx 线程创建函数
 */
int32_t ete_rx_thread_create(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    uint32_t ret;

    g_ete_rx_thread_info.stack_addr = mdrv_mem_alloc(ETE_RX_THREAD_SIZE, MEM_CACHE | MDRV_MEM_ALIGN_016);
    if (g_ete_rx_thread_info.stack_addr == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "ete_rx_thread_create stack mem alloc fail");
        return -OAL_FAIL;
    }

    task_attr.type = THRD_TASK;
    task_attr.prio = OS_TSK_PRIORITY_01;
    task_attr.stackSize = ETE_RX_THREAD_SIZE;
    task_attr.stackAddr = (uintptr_t)g_ete_rx_thread_info.stack_addr;
    task_attr.queNum = 1;
    task_attr.args[0] = 0;
    task_attr.entryFunc = ete_rx_thread_process,
    ret = osl_task_create("ete_rx", &task_attr, 1, &g_ete_rx_thread_info.task_id);
    if (ret) {
        oal_free(g_ete_rx_thread_info.stack_addr);
        oam_error_log1(0, OAM_SF_DPA, "osl_task_create ete_rx fail, ret:0x%x", ret);
        return -OAL_EFAIL;
    }
    g_ete_rx_thread_info.event_type = ETE_RX_EVENT;
    oam_warning_log0(0, OAM_SF_DPA, "ete_rx thread creat succ");

    dpa_exception_register((uint8_t *)&g_ete_rx_thread_info.excep_id, g_ete_rx_thread_info.task_id, ETE_RX_EVENT_DFR);
    ret = mdrv_bsem_init(OS_SEM_EMPTY, SEM_MODE_PRIOR, &g_ete_rx_thread_info.rx_thread_sem);
    if (ret != MDRV_OK) {
        oam_error_log1(0, OAM_SF_DPA, "ete_rx_thread sem init fail, ret:0x%x", ret);
        ret = mdrv_task_delete(g_ete_rx_thread_info.task_id);
        if (ret != MDRV_OK) {
            oam_error_log1(0, OAM_SF_DPA, "ete_rx_thread delete fail, ret = 0x%x", ret);
        }
        oal_free(g_ete_rx_thread_info.stack_addr);
        return -OAL_EFAIL;
    }

    return OAL_SUCC;
}

void oal_pcie_ete_buff_free(pcie_res *pst_pci_res, size_t buff_size, void *cpu_addr, uint64_t iova)
{
    oal_dma_free_nocache(cpu_addr);
}

int32_t oal_pcie_ete_buff_alloc(pcie_res *pst_pci_res, size_t buff_size,
                                void **cpu_addr, uint64_t *dst_addr, uint64_t *iova)
{
    int32_t ret;
    *cpu_addr = oal_dma_alloc_nocache(buff_size);
    if (*cpu_addr == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "dma alloc buff failed, buff_size=%u", (uint32_t)buff_size);
        return -OAL_ENOMEM;
    }

    oal_addr32_to_addr64((uint32_t)(uintptr_t)(*cpu_addr), iova);

    ret = oal_pcie_host_slave_address_switch(pst_pci_res, *iova, dst_addr, OAL_TRUE);
    if (ret != OAL_SUCC) {
        oam_error_log2(0, OAM_SF_DPA, "slave address switch failed ret=%d iova=%x", ret, (uint32_t)(*iova));
        return ret;
    }
    return OAL_SUCC;
}

void oal_ete_chan_tx_exit(pcie_res *pst_pci_res)
{
    int32_t i;
    int32_t ret;
    uint64_t iova;
    pcie_ete_chan_h2d_res *pst_h2d_res = NULL;

    for (i = 0; i < ETE_TX_CHANN_MAX_NUMS; i++) {
        pst_h2d_res = &pst_pci_res->ete_info.h2d_res[i];
        if (pst_h2d_res->ring.cpu_addr != 0) {
            ret = oal_pcie_host_slave_address_switch(pst_pci_res,
                                                     (uint64_t)pst_h2d_res->ring.io_addr, &iova, OAL_FALSE);
            if (oal_unlikely(ret != OAL_SUCC)) {
                oam_error_log2(0, OAM_SF_DPA, "slave address switch failed ret=%d devca=%x", ret,
                               (uint32_t)pst_h2d_res->ring.io_addr);
            }
            oal_pcie_ete_buff_free(pst_pci_res, pst_h2d_res->ring.size,
                                   (void*)(uintptr_t)pst_h2d_res->ring.cpu_addr,
                                   (uint64_t)(iova));
            pst_h2d_res->ring.cpu_addr = 0;
            pst_h2d_res->ring.io_addr = 0;
        }

        oal_netbuf_list_head_deinit(&pst_h2d_res->txq);
    }
}

void oal_ete_chan_rx_exit(pcie_res *pst_pci_res)
{
    int32_t i;
    int32_t ret;
    uint64_t iova;
    pcie_ete_chan_d2h_res *pst_d2h_res = NULL;

    for (i = 0; i < ETE_RX_CHANN_MAX_NUMS; i++) {
        pst_d2h_res = &pst_pci_res->ete_info.d2h_res[i];
        if (pst_d2h_res->ring.cpu_addr != 0) {
            ret = oal_pcie_host_slave_address_switch(pst_pci_res,
                                                     (uint64_t)pst_d2h_res->ring.io_addr, &iova, OAL_FALSE);
            if (oal_unlikely(ret != OAL_SUCC)) {
                oam_error_log2(0, OAM_SF_DPA, "slave address switch failed ret=%d devca=%x", ret,
                               (uint32_t)pst_d2h_res->ring.io_addr);
            } else {
                oal_pcie_ete_buff_free(pst_pci_res, pst_d2h_res->ring.size,
                                       (void *)(uintptr_t)pst_d2h_res->ring.cpu_addr, (uint64_t)iova);
                pst_d2h_res->ring.cpu_addr = 0;
                pst_d2h_res->ring.io_addr = 0;
            }
        }

        oal_netbuf_list_head_deinit(&pst_d2h_res->rxq);
        oal_netbuf_list_head_deinit(&pst_d2h_res->pre_rxq);
        oal_netbuf_list_head_deinit(&pst_d2h_res->rx_doneq);
        if (mdrv_sem_delete(pst_d2h_res->rx_sem) != OAL_SUCC) {
            oam_error_log0(0, OAM_SF_DPA, "rx_sem delete fail");
        }
    }
}

void oal_ete_chan_exit(pcie_res *pst_pci_res)
{
    oal_ete_chan_tx_exit(pst_pci_res);
    oal_ete_chan_rx_exit(pst_pci_res);
}

int32_t oal_ete_chan_tx_init(pcie_res *pst_pci_res)
{
    int32_t i;
    int32_t ret;
    size_t buff_size;
    uint64_t iova = 0;
    uint64_t dst_addr;
    void *cpu_addr = NULL;
    pcie_ete_chan_h2d_res *pst_h2d_res = NULL;

    for (i = 0; i < ETE_TX_CHANN_MAX_NUMS; i++) {
        pst_h2d_res = &pst_pci_res->ete_info.h2d_res[i];
        pst_h2d_res->chan_idx = (uint32_t)i;
        if (pst_h2d_res->enabled == 0) {
            continue;
        }
        if (pst_h2d_res->ring_max_num == 0) {
            pst_h2d_res->enabled = 0;
            continue;
        }

        oal_netbuf_list_head_init(&pst_h2d_res->txq);
        oal_atomic_set(&pst_h2d_res->tx_sync_cond, 0);
        buff_size = sizeof(h2d_sr_descr) * (uint32_t)pst_h2d_res->ring_max_num;

        /* (h2d_sr_descr*) */
        ret = oal_pcie_ete_buff_alloc(pst_pci_res, buff_size, &cpu_addr, &dst_addr, &iova);
        if (ret != OAL_SUCC) {
            oam_error_log2(0, OAM_SF_DPA, "ete h2d chan%u ring buff init failed, ring_max_num = %d",
                           pst_h2d_res->chan_idx, pst_h2d_res->ring_max_num);
            return -OAL_FAIL;
        }

        ret = pcie_ete_ringbuf_init(&pst_h2d_res->ring, (uint64_t)(uintptr_t)cpu_addr,
                                    (uint64_t)dst_addr, 0, buff_size, sizeof(h2d_sr_descr));
        if (ret != OAL_SUCC) {
            oal_pcie_ete_buff_free(pst_pci_res, buff_size, cpu_addr, (uint64_t)(iova));
            return ret;
        }

        pst_h2d_res->ring.debug = 0; /* 0 no debug info */

        oam_info_log4(0, OAM_SF_DPA, "ete h2d chan%d iova=%x  devva=%x, io_addr=%x",
                      i, (uint32_t)iova, (uint32_t)dst_addr, (uint32_t)pst_h2d_res->ring.io_addr);

        oam_warning_log3(0, OAM_SF_DPA, "ete h2d chan%d init succ, ring_max_num=%d, buff_size=%u",
                         i, pst_h2d_res->ring_max_num, (uint32_t)buff_size);
        oal_ete_print_ringbuf_info(&pst_h2d_res->ring);
    }

    return OAL_SUCC;
}

int32_t oal_ete_chan_rx_init(pcie_res *pst_pci_res)
{
    int32_t i;
    int32_t ret;
    size_t buff_size;
    uint64_t iova = 0;
    uint64_t dst_addr;
    void *cpu_addr = NULL;
    pcie_ete_chan_d2h_res *pst_d2h_res = NULL;

    for (i = 0; i < ETE_RX_CHANN_MAX_NUMS; i++) {
        pst_d2h_res = &pst_pci_res->ete_info.d2h_res[i];
        pst_d2h_res->chan_idx = (uint32_t)i;
        if (pst_d2h_res->enabled == 0) {
            continue;
        }
        if (pst_d2h_res->ring_max_num == 0) {
            pst_d2h_res->enabled = 0;
            continue;
        }
        pst_d2h_res->hdr_flag = PCIE_RX_TRANS_FLAG;
        oal_netbuf_list_head_init(&pst_d2h_res->pre_rxq);
        oal_netbuf_list_head_init(&pst_d2h_res->rxq);
        oal_netbuf_list_head_init(&pst_d2h_res->rx_doneq);

        if (mdrv_bsem_init(OS_SEM_EMPTY, SEM_MODE_PRIOR, &pst_d2h_res->rx_sem)) {
            oam_error_log1(0, OAM_SF_DPA, "ete h2d chan%u rx_sem init fail", pst_d2h_res->chan_idx);
            return -OAL_FAIL;
        }

        buff_size = sizeof(d2h_dr_descr) * (uint32_t)pst_d2h_res->ring_max_num;

        /* (d2h_sr_descr*) */
        ret = oal_pcie_ete_buff_alloc(pst_pci_res, buff_size, &cpu_addr, &dst_addr, &iova);
        if (ret != OAL_SUCC) {
            oam_error_log2(0, OAM_SF_DPA, "ete h2d chan%u ring buff init failed, ring_max_num = %d",
                           pst_d2h_res->chan_idx, pst_d2h_res->ring_max_num);
            mdrv_sem_delete(pst_d2h_res->rx_sem);
            return -OAL_FAIL;
        }

        ret = pcie_ete_ringbuf_init(&pst_d2h_res->ring, (uint64_t)(uintptr_t)cpu_addr, (uint64_t)dst_addr,
                                    0, buff_size, sizeof(d2h_dr_descr));
        if (ret != OAL_SUCC) {
            oal_pcie_ete_buff_free(pst_pci_res, buff_size, cpu_addr, (uint64_t)(iova));
            mdrv_sem_delete(pst_d2h_res->rx_sem);
            return ret;
        }

        oam_info_log3(0, OAM_SF_DPA, "ete d2h chan%d iova=%x  devva=%x",
                      i, (uint32_t)iova, (uint32_t)dst_addr);

        oam_info_log3(0, OAM_SF_DPA, "ete d2h chan%d init succ, ring_max_num=%d, buff_size=%u",
                      i, pst_d2h_res->ring_max_num, (uint32_t)buff_size);

        oal_ete_print_ringbuf_info(&pst_d2h_res->ring);
    }

    return OAL_SUCC;
}

OAL_STATIC void oal_ete_int_mask_init(pcie_res *pst_pci_res)
{
    hreg_host_intr_mask host_intr_mask;
    hreg_pcie_ctl_ete_intr_mask ete_intr_mask;
    hreg_pcie_ctrl_ete_ch_dr_empty_intr_mask ete_ch_dr_empty_intr_mask;

    host_intr_mask.as_dword = 0x0;
    ete_intr_mask.as_dword = 0x0;

    /* host int mask */
    host_intr_mask.bits.device2host_tx_intr_mask = 1;
    host_intr_mask.bits.device2host_rx_intr_mask = 1;
    host_intr_mask.bits.device2host_intr_mask = 1;
    host_intr_mask.bits.mac_n2_intr_mask = 1;
    host_intr_mask.bits.mac_n1_intr_mask = 1;
    host_intr_mask.bits.phy_n2_intr_mask = 1;
    host_intr_mask.bits.phy_n1_intr_mask = 1;
    /* mp17c新增，其他项目该字段为reserved */
    host_intr_mask.bits.mac_n3_intr_mask = 1;

    pst_pci_res->ete_info.host_intr_mask = host_intr_mask.as_dword;
    oam_info_log1(0, OAM_SF_DPA, "host_intr_mask:0x%x", pst_pci_res->ete_info.host_intr_mask);

    ete_intr_mask.bits.host_tx_err_intr_mask = ((1 << ETE_TX_CHANN_MAX_NUMS) - 1);
    ete_intr_mask.bits.host_tx_done_intr_mask = ((1 << ETE_TX_CHANN_MAX_NUMS) - 1);
    ete_intr_mask.bits.host_rx_err_intr_mask = ((1 << ETE_RX_CHANN_MAX_NUMS) - 1);
    ete_intr_mask.bits.host_rx_done_intr_mask = ((1 << ETE_RX_CHANN_MAX_NUMS) - 1);
    pst_pci_res->ete_info.pcie_ctl_ete_intr_mask = ete_intr_mask.as_dword;
    oam_info_log1(0, OAM_SF_DPA, "pcie_ctl_ete_intr_mask:0x%x", pst_pci_res->ete_info.pcie_ctl_ete_intr_mask);

    ete_ch_dr_empty_intr_mask.bits.host_tx_ch_dr_empty_intr_mask = ((1 << ETE_TX_CHANN_MAX_NUMS) - 1);
    ete_ch_dr_empty_intr_mask.bits.host_rx_ch_dr_empty_intr_mask = ((1 << ETE_RX_CHANN_MAX_NUMS) - 1);
    pst_pci_res->ete_info.ete_ch_dr_empty_intr_mask = ete_ch_dr_empty_intr_mask.as_dword;
    oam_info_log1(0, OAM_SF_DPA, "pcie_ctl_ete_intr_mask:0x%x",
                  pst_pci_res->ete_info.ete_ch_dr_empty_intr_mask);
}

static void oal_ete_intr_register(int bit, void (*fun_callback)(void *para))
{
    g_pcie_ete_intx_callback[bit].pf_func = fun_callback;
}

void oal_ete_host2device_tx_intr_cb(void *fun)
{
    // 仅61产品业务有使用，dpa上可用于intx中断上报验证
    oam_warning_log0(0, OAM_SF_DPA, "host2device intr, ignore by host");
}

int32_t oal_ete_chan_init(pcie_res *pst_pci_res)
{
    int32_t ret;
    errno_t err1, err2;

    err1 = memcpy_s((void *)pst_pci_res->ete_info.h2d_res,
                    sizeof(pst_pci_res->ete_info.h2d_res),
                    (void *)g_pcie_h2d_res_cfg, sizeof(pst_pci_res->ete_info.h2d_res));
    err2 = memcpy_s((void *)pst_pci_res->ete_info.d2h_res,
                    sizeof(pst_pci_res->ete_info.d2h_res),
                    (void *)g_pcie_d2h_res_config, sizeof(pst_pci_res->ete_info.d2h_res));
    if (err1 != EOK || err2 != EOK) {
        oam_error_log2(0, OAM_SF_DPA, "err1=%d, err2=%d", err1, err2);
    }

    (void)memset_s((void *)g_pcie_ete_intx_callback, sizeof(g_pcie_ete_intx_callback),
                   0, sizeof(g_pcie_ete_intx_callback));
    oal_ete_int_mask_init(pst_pci_res);
#ifndef _PRE_LINUX_TEST
    g_pcie_ete_intx_callback[MAC_2G_INTR_MASK].pf_func = hal_host_2g_mac_intr_default_handle;
    g_pcie_ete_intx_callback[MAC_5G_INTR_MASK].pf_func = hal_host_5g_mac_intr_default_handle;
#endif
    oal_ete_intr_register(HOST2DEVICE_TX_INTR_MASK, oal_ete_host2device_tx_intr_cb);

    ret = oal_ete_chan_tx_init(pst_pci_res);
    if (ret != OAL_SUCC) {
        goto fail_tx;
    }

    ret = oal_ete_chan_rx_init(pst_pci_res);
    if (ret != OAL_SUCC) {
        goto fail_rx;
    }
    return OAL_SUCC;
fail_rx:
    oal_ete_chan_tx_exit(pst_pci_res);
fail_tx:
    return ret;
}

int32_t oal_ete_host_init(pcie_res *pst_pci_res)
{
    int32_t ret;
    /* init ringbuf and alloc descr mem */
    ret = oal_ete_chan_init(pst_pci_res);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "oal_ete_chan_init fail");
        return -OAL_FAIL;
    }

    conn_dmi_msg_regiser(CONN_DMI_MSG_ETE_THREAD_SCHED, oal_ete_thread_sched, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_ETE_RX_SUPPLY, NULL, oal_ete_transfer_rx_supply);
    conn_dmi_msg_regiser(CONN_DMI_MSG_ETE_DEEPSLEEP_CLEAN, NULL, oal_ete_transfer_deepsleep_clean);
    conn_dmi_msg_regiser(CONN_DMI_MSG_ETE_DEEPWKUP_RESTORE, oal_ete_transfer_deepwkup_restore, NULL);
    return OAL_SUCC;
}

void oal_ete_host_exit(pcie_res *pst_pci_res)
{
    oam_warning_log0(0, OAM_SF_DPA, "oal_ete_host_exit");

    conn_dmi_msg_regiser(CONN_DMI_MSG_ETE_THREAD_SCHED, NULL, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_ETE_RX_SUPPLY, NULL, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_ETE_DEEPSLEEP_CLEAN, NULL, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_ETE_DEEPWKUP_RESTORE, NULL, NULL);
    oal_ete_chan_exit(pst_pci_res);
}
