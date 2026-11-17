/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:ete_host.h
 * Author: dpa drivers
 */

#ifndef OAL_ETE_HOST_H
#define OAL_ETE_HOST_H
#include "ete_comm.h"
#include "oal_schedule.h"
#include "oal_net.h"
#include "mdrv_sem.h"
#include "oam_logger.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_ETE_HOST_H

typedef struct _pcie_ete_chan_h2d_res__ {
    pcie_ete_ringbuf ring;
    uint32_t chan_idx;
    int32_t ring_max_num;    /* max num descrs */
    int32_t enabled;
    oal_netbuf_head_stru txq;           /* 正在发送中的netbuf队列 */
    oal_atomic tx_sync_cond;
} pcie_ete_chan_h2d_res;

typedef struct _pcie_ete_chan_d2h_res__ {
    pcie_ete_ringbuf ring;
    uint32_t chan_idx;
    int32_t max_len;
    int32_t ring_max_num;    /* max num descrs */
    int32_t enabled;
    int32_t hdr_flag;
    oal_netbuf_head_stru pre_rxq;       /* 预申请并填写包头的netbuf队列 */
    oal_netbuf_head_stru rxq;           /* 正在接收中的netbuf队列 */
    oal_netbuf_head_stru rx_doneq;      /* 用于rx接收完成后，dma拷贝包头向hcc提交 */
    mdrv_sem_id rx_sem;
} pcie_ete_chan_d2h_res;

typedef struct _pcie_ete_reg__ {
    void* host_intr_sts_addr;
    void* host_intr_clr_addr;
    void* host_intr_mask_addr;
    void* ete_intr_sts_addr;
    void* ete_intr_clr_addr;
    void* ete_intr_mask_addr;
    void* ete_dr_empty_sts_addr;
    void* ete_dr_empty_clr_addr;
    void* h2d_intr_addr;
} pcie_ete_reg;

typedef struct _pcie_ete_res__ {
    pcie_ete_chan_h2d_res h2d_res[ETE_TX_CHANN_MAX_NUMS];
    pcie_ete_chan_d2h_res d2h_res[ETE_RX_CHANN_MAX_NUMS];
    unsigned int host_intr_mask;            // 屏蔽中断，不上报host
    unsigned int pcie_ctl_ete_intr_mask;
    unsigned int ete_ch_dr_empty_intr_mask;
    unsigned int int_event_ignore_mask;     // 检测到中断事件，但是host侧不处理
    pcie_ete_reg reg;
} pcie_ete_res;

OAL_STATIC OAL_INLINE void oal_ete_print_ringbuf_info(pcie_ete_ringbuf *pst_ringbuf)
{
    // ete ring均在dpa申请，故必然为32位，因ete硬件约束故采用64位结构，此处直接用32位打印
    oam_info_log4(0, OAM_SF_DPA, "[%x]item_len:%u, cpu_addr:0x%x, io_addr:0x%x",
                  (uint32_t)(uintptr_t)pst_ringbuf, pst_ringbuf->item_len,
                  (uint32_t)pst_ringbuf->cpu_addr, (uint32_t)pst_ringbuf->io_addr);
    oam_info_log4(0, OAM_SF_DPA, "wr:%u, rd:%u, size:%u, items:%u",
                  pst_ringbuf->wr, pst_ringbuf->rd, pst_ringbuf->size, pst_ringbuf->items);
    oam_info_log2(0, OAM_SF_DPA, "wflag:%u  rflag:%u",
                  pst_ringbuf->wflag, pst_ringbuf->rflag);
}

int32_t oal_ete_rx_ringbuf_init(void);
#endif
