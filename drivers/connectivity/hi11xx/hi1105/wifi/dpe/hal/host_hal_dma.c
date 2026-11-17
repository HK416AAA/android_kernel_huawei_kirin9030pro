/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2025. All rights reserved.
 * 功能说明   : MAP UNMAP基本操作
 * 作者       : wifi
 * 创建日期   : 2025年1月4日
 */
#include "securec.h"
#include "oal_util.h"
#include "oal_ext_if.h"
#include "oam_ext_if.h"
#include "host_hal_ext_if.h"
#include "host_hal_device.h"
#include "pcie_host.h"
#include "dpe_dma_cpy.h"
#include "host_hal_ring.h"
#include "host_hal_dma.h"
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "dpe_dma.h"
#include "pcie_host.h"
#else
#include "pcie_linux.h"
#include "dpe_wlan_stat.h"
#endif
#include "dpe_sbuf.h"
#include "dpe_mem.h"
#include "dpe_tx_data.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID     OAM_FILE_ID_HOST_HAL_DMA

/*
 * 功能描述 : 清零netbuf headroom中的MSDU描述符内存空间, 并返回其地址
 * 1.日    期 : 2020年4月22日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
void hal_host_tx_netbuf_init_msdu_dscr(oal_netbuf_stru *netbuf, uint8_t is_force_dma)
{
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    uint8_t msdu_dscr_len = hal_host_tx_get_msdu_dscr_len();
    uint8_t *msdu_dscr_addr = (uint8_t *)((uint8_t *)oal_netbuf_data(netbuf) - msdu_dscr_len);

    memset_s(msdu_dscr_addr, msdu_dscr_len, 0, msdu_dscr_len);
#else
    uint8_t msdu_dscr_len = WIFI_DPE_XMIT_DSCR_LEN;
    uint64_t msdu_dscr_addr;

    /* dpa栈/modem/aput二层转发均已支持tx msdu info清零 */
    if ((is_force_dma == OAL_FALSE) && (dpe_is_support_tx_no_dma() == OAL_TRUE)) {
        return;
    }
    msdu_dscr_addr = (uint64_t)((uint64_t)oal_netbuf_data(netbuf) - msdu_dscr_len);
    dpe_dma_cpy_noncache((uint64_t)g_tx_msdu_dscr_init_dma, msdu_dscr_addr,
        (uint32_t)msdu_dscr_len, DPE_WLAN_XMIT_DMA);
#endif
}

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
void hal_host_rx_dma_map_proc(oal_netbuf_head_stru *before, oal_netbuf_head_stru *after)
{
    uint64_t pci_dma_addr;
    oal_netbuf_stru *netbuf = NULL;
    pcie_cb_dma_res *cb_res = NULL;

#ifdef _PRE_WLAN_FEATURE_DMA_MAP_BATCH
    hal_host_dma_proc(before, after, DMA_BATCH_HOST_RX_MAP);
#else

    while ((netbuf = oal_netbuf_delist_nolock(before)) != NULL) {
        pci_dma_addr = dpe_dma_map_single(oal_netbuf_data(netbuf),
            oal_netbuf_len(netbuf), DPE_DMA_FROM_DEVICE);
        if (dpe_dma_mapping_error(pci_dma_addr) != 0) {
            oam_error_log0(0, OAM_SF_DPA, "{hal_host_rx_dma_map_proc::addr map failed}");
            dpe_netbuf_free(netbuf);
            continue;
        }
        cb_res = (pcie_cb_dma_res *)oal_netbuf_cb(netbuf);
        if (oal_likely(cb_res != NULL)) {
            cb_res->paddr.addr = pci_dma_addr;
            cb_res->len = oal_netbuf_len(netbuf);
        }
        oal_netbuf_list_tail_nolock(after, netbuf);
    }
#endif
}

uint32_t hal_host_tx_dma_map_phyaddr(uint8_t *host_addr, uint32_t len, uint64_t *physaddr)
{
#ifdef WIN32
    *physaddr = (uint64_t)host_addr;
    return OAL_SUCC;
#endif

    if (oal_unlikely(host_addr == NULL || physaddr == NULL)) {
        return OAL_FAIL;
    }

    *physaddr = dpe_dma_map_single(host_addr, len, DPE_DMA_TO_DEVICE);
    if (dpe_dma_mapping_error(*physaddr) != 0) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_host_tx_dma_map_phyaddr::addr map failed}");
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

uint32_t hal_host_tx_dma_unmap_addr(uint64_t dma_addr, uint32_t len)
{
    if (oal_unlikely(dma_addr == 0)) {
        return OAL_FAIL;
    }
    dpe_dma_unmap_single(dma_addr, len, DPE_DMA_TO_DEVICE);
    return OAL_SUCC;
}

void hal_host_rx_dma_unmap_proc(oal_netbuf_head_stru *before, oal_netbuf_head_stru *after)
{
#ifdef _PRE_WLAN_FEATURE_DMA_MAP_BATCH
    hal_host_dma_proc(before, after, DMA_BATCH_HOST_RX_UNMAP);
#else
    oal_netbuf_stru *netbuf = NULL;
    pcie_cb_dma_res *cb_res = NULL;

    while ((netbuf = oal_netbuf_delist_nolock(before)) != NULL) {
        cb_res = (pcie_cb_dma_res *)oal_netbuf_cb(netbuf);
        if (oal_likely(cb_res != NULL)) {
            dpe_dma_unmap_single(cb_res->paddr.addr, oal_netbuf_len(netbuf), DPE_DMA_FROM_DEVICE);
        }
        dpe_wlan_rx_delay_notify(netbuf, 0, RX_BUFF_POOL_END);
        oal_netbuf_list_tail_nolock(after, netbuf);
    }
#endif
}

void hal_host_tx_dma_map_proc(oal_netbuf_head_stru *before, oal_netbuf_head_stru *after)
{
#ifdef _PRE_WLAN_FEATURE_DMA_MAP_BATCH
    hal_host_dma_proc(before, after, DMA_BATCH_HOST_TX_MAP);
#else
    oal_netbuf_stru *netbuf = NULL;
    uint32_t ret;
    uint64_t addr;
    mac_tx_ctl_stru *tx_ctl = NULL;

    while ((netbuf = oal_netbuf_delist_nolock(before)) != NULL) {
        ret = hal_host_tx_dma_map_phyaddr(oal_netbuf_data(netbuf) - hal_host_tx_get_msdu_dscr_len(),
            oal_netbuf_len(netbuf) + hal_host_tx_get_msdu_dscr_len(), &addr);
        if (oal_unlikely(ret != OAL_SUCC)) {
            oam_error_log0(0, OAM_SF_DPA, "hal_host_tx_dma_map_phyaddr fail");
            dpe_netbuf_free(netbuf);
            continue;
        }
        tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
        if (oal_likely(tx_ctl != NULL && ret == OAL_SUCC)) {
            tx_ctl->st_expand_cb.pcie_dma_addr = addr;
            tx_ctl->st_expand_cb.pcie_dma_len = oal_netbuf_len(netbuf) + hal_host_tx_get_msdu_dscr_len();
            tx_ctl->st_expand_cb.dma_mapped = OAL_TRUE;
        }
        oal_netbuf_list_tail_nolock(after, netbuf);
    }
#endif
}

void hal_host_tx_dma_unmap_step_proc(oal_netbuf_head_stru *before, oal_netbuf_head_stru *after)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    oal_netbuf_stru *netbuf = NULL;
    if (oal_unlikely(before == NULL || after == NULL)) {
        return;
    }

    while ((netbuf = oal_netbuf_delist_nolock(before)) != NULL) {
        tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
        if (oal_likely(tx_ctl != NULL && tx_ctl->st_expand_cb.dma_mapped == OAL_TRUE)) {
            hal_host_tx_dma_unmap_addr(tx_ctl->st_expand_cb.pcie_dma_addr, tx_ctl->st_expand_cb.pcie_dma_len);
            tx_ctl->st_expand_cb.dma_mapped = OAL_FALSE;
        } else {
            oam_error_log0(0, OAM_SF_DPA, "hal_host_tx_dma_unmap_proc dma not mapped");
        }
        oal_netbuf_list_tail_nolock(after, netbuf);
    }
}

void hal_host_tx_dma_unmap_proc(oal_netbuf_head_stru *before, oal_netbuf_head_stru *after)
{
#ifdef _PRE_WLAN_FEATURE_DMA_MAP_BATCH
    hal_host_dma_proc(before, after, DMA_BATCH_HOST_TX_UNMAP);
#else
    hal_host_tx_dma_unmap_step_proc(before, after);
#endif
}

void hal_host_tx_unmap_single_netbuf(oal_netbuf_stru *netbuf)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    if (oal_unlikely(netbuf == NULL)) {
        return;
    }
    tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (oal_unlikely(tx_ctl == NULL)) {
        return;
    }
    if (tx_ctl->st_expand_cb.dma_mapped == OAL_TRUE) {
        hal_host_tx_dma_unmap_addr(tx_ctl->st_expand_cb.pcie_dma_addr, tx_ctl->st_expand_cb.pcie_dma_len);
        tx_ctl->st_expand_cb.dma_mapped = OAL_FALSE;
    } else {
        oam_error_log0(0, OAM_SF_DPA, "hal_host_tx_unmap_single_netbuf dma not mapped");
    }
}

void hal_host_tx_unmap_netbuf_list(oal_netbuf_stru *netbuf)
{
    oal_netbuf_stru *next = NULL;
    if (oal_unlikely(!netbuf)) {
        return;
    }

    while (netbuf != NULL) {
        next = oal_netbuf_next(netbuf);
        hal_host_tx_unmap_single_netbuf(netbuf);
        netbuf = next;
    }
}
/*
 * 功能描述 : 单个tx netbuf map接口
 */
uint32_t hal_host_ring_tx_single_map(oal_netbuf_stru *netbuf)
{
    uint32_t ret;
    uint64_t addr;
    mac_tx_ctl_stru *tx_ctl = NULL;
    if (oal_unlikely(netbuf == NULL)) {
        return OAL_FAIL;
    }
    tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (oal_unlikely(tx_ctl == NULL)) {
        return OAL_FAIL;
    }
    ret = hal_host_tx_dma_map_phyaddr(oal_netbuf_data(netbuf) - hal_host_tx_get_msdu_dscr_len(),
        oal_netbuf_len(netbuf) + hal_host_tx_get_msdu_dscr_len(), &addr);
    if (oal_likely(tx_ctl != NULL && ret == OAL_SUCC)) {
        tx_ctl->st_expand_cb.pcie_dma_addr = addr;
        tx_ctl->st_expand_cb.pcie_dma_len = oal_netbuf_len(netbuf) + hal_host_tx_get_msdu_dscr_len();
        tx_ctl->st_expand_cb.dma_mapped = OAL_TRUE;
    }
    return ret;
}
#endif

/*
 * 功能描述 : hostva映射成devva, 供mac访问host ring内容
 * dma_map_batch处理场景，走到此函数是已经map好了，此处仅需要从cb中取出dma地址进行转换
 */
uint32_t hal_host_tx_get_devva(oal_netbuf_stru *netbuf, uint64_t *devva)
{
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    uint64_t pcie_dma_addr;
    mac_tx_ctl_stru *tx_ctl = NULL;
    if (oal_unlikely(netbuf == NULL || devva == NULL)) {
        return OAL_FAIL;
    }
    tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (oal_unlikely(tx_ctl == NULL)) {
        return OAL_FAIL;
    }
    if (oal_unlikely(tx_ctl->st_expand_cb.dma_mapped == OAL_FALSE)) {
        oam_error_log0(0, OAM_SF_DPA, "hal_host_tx_get_devva dma not mapped");
        return OAL_FAIL;
    }

    pcie_dma_addr = tx_ctl->st_expand_cb.pcie_dma_addr;

    if (pcie_if_hostca_to_devva(HCC_EP_WIFI_DEV, pcie_dma_addr, devva) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hal_host_tx_get_devva hostca_to_devva fail");
        return OAL_FAIL;
    }
#else
    /* DPA模式下直接通过oal_netbuf_data_iova获取host地址，进行地址映射 */
    if (pcie_if_hostca_to_devva(HCC_EP_WIFI_DEV,
        oal_netbuf_data_iova(netbuf) - hal_host_tx_get_msdu_dscr_len(), devva) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hal_host_tx_get_devva hostca_to_devva fail");
        return OAL_FAIL;
    }
#endif
    return OAL_SUCC;
}
