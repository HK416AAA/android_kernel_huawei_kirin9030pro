/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : HOST HAL DSCR FUNCTION
 * 作    者 :
 * 创建日期 : 2021年2月23日
 */

#include "host_hal_dscr.h"
#include "host_hal_ext_if.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "pcie_linux.h"
#else
#include "pcie_host.h"
#include "dpe_dma.h"
#endif
#include "host_hal_ring.h"
#include "pcie_host.h"
#include "dpe_wlan_stat.h"
#ifdef _PRE_WLAN_FEATURE_ESPE
#include "hmac_espe.h"
#endif
#include "oam_event_wifi.h"
#include "host_hal_dma.h"
#include "dpe_sbuf.h"
#include "dpe_mem.h"
#include "dpe_dma_cpy.h"
#include "dpe_tx_data.h"
#include "dpe_wlan_debug.h"
#include "dpe_wlan_resource.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HOST_HAL_DSCR_C

#ifdef _PRE_WLAN_FEATURE_VSP
static inline oal_netbuf_stru *hal_vsp_alloc_rx_netbuf(hal_host_device_stru *hal_device, uint32_t size)
{
    if (oal_netbuf_list_empty(&hal_device->vsp_netbuf_recycle_list) ||
        size != LARGE_NETBUF_SIZE + hal_host_get_rx_msdu_dscr_len()) {
        return NULL;
    }

    return oal_netbuf_delist(&hal_device->vsp_netbuf_recycle_list);
}
#endif

oal_netbuf_stru *hal_host_rx_alloc_netbuf(hal_host_device_stru *hal_device, uint32_t size)
{
#ifdef _PRE_WLAN_FEATURE_VSP
    oal_netbuf_stru *netbuf = hal_vsp_alloc_rx_netbuf(hal_device, size);
    if (netbuf) {
        return netbuf;
    }
#endif

#ifdef _PRE_WLAN_FEATURE_ESPE
    return hmac_espe_alloc_skb(size);
#else
    return dpe_netbuf_alloc(size, EN_RX_ALLOC);
#endif
}

void hal_host_rx_add_buff_clear_msdu_info(oal_netbuf_stru *netbuf, size_t mpdu_desc_size)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    if (dpe_is_support_rx_sbuf_by_addr()) {
        /* ring切换同步DMA,每次只拷贝一个 */
        g_rx_msdu_dma_init[0].sbuf_addr = (uint32_t)netbuf;
#ifndef _DMA_USE_TCM
        dpe_dma_cpy_cache((void *)&g_rx_msdu_dma_init[0], (uint64_t)&g_rx_msdu_dma_init[0],
            (uint64_t)oal_netbuf_data(netbuf) + mpdu_desc_size - DPE_RX_ADD_BUFF_DMA_LEN, /* headroom 64字节地址 */
            DPE_RX_ADD_BUFF_DMA_LEN, DPE_RX_ADD_BUFF_DMA);
#else
        dpe_dma_cpy_noncache((uint64_t)GLOBAL_L1DTCM_ADDR(&g_rx_msdu_dma_init[0]),
            (uint64_t)oal_netbuf_data(netbuf) + mpdu_desc_size - DPE_RX_ADD_BUFF_DMA_LEN, /* headroom 128地址 */
            DPE_RX_ADD_BUFF_DMA_LEN, DPE_RX_ADD_BUFF_DMA);
#endif
    } else {
        /* 清空headroom 128字节,burst单位操作效率更高 */
        dpe_dma_cpy_noncache((uint64_t)g_rx_msdu_dscr_init_dma,
            (uint64_t)oal_netbuf_data(netbuf) + mpdu_desc_size - SBUF_DATA_HEADROOM_MAX_LEN, /* headroom 128地址 */
            SBUF_DATA_HEADROOM_MAX_LEN, DPE_RX_ADD_BUFF_DMA);
    }
#else
    memset_s((uint8_t *)oal_netbuf_data(netbuf), mpdu_desc_size, 0, mpdu_desc_size);
#endif
}

void hal_host_rx_add_buff_alloc_before_dma(hal_host_device_stru *hal_device,
    oal_netbuf_head_stru *before_dma, uint32_t buff_size, uint16_t need_add)
{
    uint16_t loop, headroom;
    oal_netbuf_stru *netbuf = NULL;
    size_t mpdu_desc_size = hal_host_get_rx_msdu_dscr_len();
    dpe_wlan_rx_async_stat_stru  *rx_stats = dpe_wlan_rx_async_stat_get();

    for (loop = 0; loop < need_add; loop++) {
        netbuf = hal_host_rx_alloc_netbuf(hal_device, buff_size);
        if (netbuf == NULL) {
            oam_warning_log0(0, OAM_SF_DPA, "hal_host_rx_add_buff_alloc_before_dma::skb alloc fail");
            rx_stats->rx_alloc_fail_cnt++;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
            dpe_rx_async_debug_show();
            dpe_tx_debug_show();
#endif
            break;
        }
        oal_netbuf_set_len(netbuf, buff_size);

        headroom = oal_netbuf_headroom(netbuf);
        if (headroom < mpdu_desc_size) {
            oam_error_log2(0, OAM_SF_DPA, "hal_host_rx_add_buff::headroom not enough %d<%d", headroom, mpdu_desc_size);
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
            dpe_netbuf_free(netbuf);
#else
            if (oal_netbuf_expand_head(netbuf, mpdu_desc_size - headroom, 0, GFP_ATOMIC) != OAL_SUCC) {
                oam_error_log0(0, OAM_SF_DPA, "{hmac_hcc_tx_data:: alloc head room failed.}");
                dpe_netbuf_free(netbuf);
            }
#endif
            continue;
        }

        if (g_wlan_spec_cfg->rx_ring_8_bytes_align_check == OAL_TRUE) {
            /* 确保帧体位置是8字节对齐 */
            if (((uintptr_t)oal_netbuf_data(netbuf) % HAL_RX_NETBUF_ADDR_ALIGN) != 0) {
                oal_netbuf_pull(netbuf, HAL_RX_NETBUF_ADDR_OFFSET);
            }
        }

        /* headroom空间用于放rx msdu描述符 */
        oal_netbuf_push(netbuf, mpdu_desc_size);

        /* 不支持自主清零并且不支持异步清零 */
        if ((g_wlan_spec_cfg->rx_ring_reduce_load_is_open != OAL_TRUE) &&
            (dpe_is_support_rx_dma_async() != OAL_TRUE || hal_device->rx_alloc_list_inited == OAL_FALSE)) {
            hal_host_rx_add_buff_clear_msdu_info(netbuf, mpdu_desc_size);
        }

        oal_netbuf_list_tail_nolock(before_dma, netbuf);
    }

    rx_stats->rx_add_buff_cnt += oal_netbuf_list_len(before_dma);
}

void hal_host_rx_add_buff_alloc_after_dma(hal_host_device_stru *hal_device,
    oal_netbuf_head_stru *after_dma, hal_host_ring_ctl_stru *ring_ctl, hal_host_rx_alloc_list_stru *alloc_list)
{
    unsigned long lock_flag;
    uint16_t succ_add_num = 0;
    oal_netbuf_stru *netbuf = NULL;
    uint64_t pci_dma_addr;
    uint64_t  devva = 0;
    pcie_cb_dma_res *cb_res = NULL;

    while ((netbuf = oal_netbuf_delist_nolock(after_dma)) != NULL) {
        /* 异步流程在此处赋值dma地址 */
        cb_res = (pcie_cb_dma_res *)oal_netbuf_cb(netbuf);
#ifdef _PRE_MULTI_CORE_DPE_DMA_ASYNC
        cb_res->paddr.addr = (uint64_t)oal_netbuf_data_iova(netbuf);
        cb_res->len = oal_netbuf_len(netbuf);
#endif
        pci_dma_addr = cb_res->paddr.addr;

#ifdef _USE_CACHE_PRELOAD
        prefetch_cached_ddr(oal_netbuf_peek(after_dma));
#endif
        if (pcie_if_hostca_to_devva(HCC_EP_WIFI_DEV, pci_dma_addr, &devva) != OAL_SUCC) {
            oam_error_log0(0, OAM_SF_DPA, "hal_host_rx_add_buff_alloc_after_dma::hostca_to_devva fail");
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
            dpe_dma_unmap_single(pci_dma_addr, cb_res->len, DPE_DMA_FROM_DEVICE);
#endif
            dpe_netbuf_free(netbuf);
            continue;
        }
        oal_spin_lock_irq_save(dpe_get_dev_rx_alloc_list_lock(alloc_list->rx_alloc_list_lock_idx), &lock_flag);
        oal_netbuf_list_tail_nolock(&alloc_list->rx_alloc_list, netbuf);
        oal_spin_unlock_irq_restore(dpe_get_dev_rx_alloc_list_lock(alloc_list->rx_alloc_list_lock_idx), &lock_flag);
        hal_ring_set_entries(ring_ctl, devva);
        succ_add_num++;
    }
    if (succ_add_num > 0) {
        hal_ring_set_sw2hw(ring_ctl);
    }
}

void hal_host_rx_add_buff_alloc_dma_proc(hal_host_device_stru *hal_device,
    hal_host_ring_ctl_stru *ring_ctl, uint32_t buff_size, hal_host_rx_alloc_list_stru *alloc_list, uint16_t need_add)
{
    oal_netbuf_head_stru before;
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_netbuf_head_stru after;
#endif

    /* step0：初始化链表 */
    oal_netbuf_list_head_init_nolock(&before);

    /* step1：申请netbuf并串链到before */
    hal_host_rx_add_buff_alloc_before_dma(hal_device, &before, buff_size, need_add);

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* step2: 遍历before,逐包写ring */
    hal_host_rx_add_buff_alloc_after_dma(hal_device, &before, ring_ctl, alloc_list);
#else
    /* step2: before进行dma地址转换，转换后返回after */
    oal_netbuf_list_head_init_nolock(&after);
    hal_host_rx_dma_map_proc(&before, &after);
    /* step3: 遍历after,逐包写ring */
    hal_host_rx_add_buff_alloc_after_dma(hal_device, &after, ring_ctl, alloc_list);
#endif
}

OAL_STATIC void hal_host_rx_add_buff_proc(hal_host_device_stru *hal_device,
    hal_host_ring_ctl_stru *ring_ctl, uint32_t buff_size, hal_host_rx_alloc_list_stru *alloc_list, uint16_t total_add)
{
    uint16_t once_proc_num = DMA_MAP_ONCE_PROC_NUM_DEFAULT;
    uint16_t need_add = total_add;

    while (need_add > once_proc_num) {
        hal_host_rx_add_buff_alloc_dma_proc(hal_device, ring_ctl, buff_size, alloc_list, once_proc_num);
        need_add -= once_proc_num;
    }
    hal_host_rx_add_buff_alloc_dma_proc(hal_device, ring_ctl, buff_size, alloc_list, need_add);
}

/*
 * 功能描述   : 为防止描述符越来越少，至少要补齐spec
 * 1.日    期   : 2015年1月21日
 *   作    者   : wifi
 */
void hal_host_rx_add_buff(hal_host_device_stru *hal_device, uint8_t q_num)
{
    uint32_t                     buff_size;
    uint16_t                     need_add = 0;
    hal_host_ring_ctl_stru      *ring_ctl = NULL;
    hal_host_rx_alloc_list_stru *alloc_list = NULL;

    if (!oal_pcie_link_state_up(HCC_EP_WIFI_DEV)) {
        oam_warning_log0(0, OAM_SF_DPA, "{host_rx_add_buff::pcie link down!}");
        return;
    }

    if (q_num == HAL_RX_DSCR_NORMAL_PRI_QUEUE) {
        ring_ctl = &hal_device->st_host_rx_normal_free_ring;
        buff_size = (hal_device->st_alrx.en_al_rx_flag != 0) ? ALRX_NETBUF_SIZE : LARGE_NETBUF_SIZE;
        alloc_list = &hal_device->host_rx_normal_alloc_list;  // 申请补充内存
    } else {
        oam_error_log1(0, OAM_SF_DPA, "invalid queue num[%d] in rx irq", q_num);
        return;
    }

    if (hal_ring_get_entry_count(hal_device, ring_ctl, &need_add) != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_DPA, "{host_rx_add_buff_alloc::return code.}");
        return;
    }
    if (need_add == 0) {
        return;
    }
    /* DPE初始化需进行dma同步搬移，所以只申请128个，其余由rx中断补充，降低负载 */
    if (hal_device->rx_alloc_list_inited == OAL_FALSE) {
        need_add = need_add < HAL_RX_MSDU_RING_NUM_INIT ? need_add : HAL_RX_MSDU_RING_NUM_INIT;
    }
    hal_host_rx_add_buff_proc(hal_device, ring_ctl, buff_size, alloc_list, need_add);
}
#ifdef _PRE_MULTI_CORE_DPE_DMA_ASYNC
void hal_host_get_rx_add_buff_num(hal_host_device_stru *hal_device, uint8_t q_num,
    dpe_dma_rx_add_buff_cbk_stru *dma_comp)
{
    uint32_t                     buff_size = 0;
    uint16_t                     need_add = 0;
    hal_host_ring_ctl_stru      *ring_ctl = NULL;
    oal_netbuf_head_stru add_buf_list;

    if (!oal_pcie_link_state_up(HCC_EP_WIFI_DEV)) {
        oam_warning_log0(0, OAM_SF_DPA, "{host_rx_add_buff::pcie link down!}");
        return;
    }

    if (q_num == HAL_RX_DSCR_NORMAL_PRI_QUEUE) {
        ring_ctl = &hal_device->st_host_rx_normal_free_ring;
        buff_size = (hal_device->st_alrx.en_al_rx_flag != 0) ? ALRX_NETBUF_SIZE : LARGE_NETBUF_SIZE;
    } else {
        oam_error_log1(0, OAM_SF_DPA, "invalid queue num[%d] in rx irq", q_num);
        return;
    }

    if (hal_ring_get_entry_count(hal_device, ring_ctl, &need_add) != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_DPA, "{host_rx_add_buff_alloc::return code.}");
        return;
    }
    if (need_add == 0) {
        return;
    }

    oal_netbuf_list_head_init_nolock(&add_buf_list);
    hal_host_rx_add_buff_alloc_before_dma(hal_device, &add_buf_list, buff_size, need_add);

    oal_netbuf_queue_splice_tail_init(&add_buf_list, &dma_comp->dma_todo_list);
    dma_comp->need_dma_num = oal_netbuf_list_len(&dma_comp->dma_todo_list);
}
#endif
/*
 * 功能描述   : 从alloc list中删除指定地址的netbuf,锁操作由外部保证
 * 1.日    期   : 2020.6.15
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
oal_netbuf_stru *hal_alloc_list_delete_netbuf(hal_host_device_stru *hal_dev,
    hal_host_rx_alloc_list_stru *alloc_list, uint64_t host_iova, uint32_t *pre_num)
{
    oal_netbuf_stru             *next_skb       = NULL;
    oal_netbuf_stru             *skb            = NULL;
    pcie_cb_dma_res             *cb_res         = NULL;
    oal_netbuf_head_stru        *list           = &alloc_list->rx_alloc_list;

    oal_netbuf_search_for_each_safe(skb, next_skb, list) {
#ifdef _USE_CACHE_PRELOAD
        if (next_skb) {
            prefetch_cached_ddr(next_skb);
        }
        cb_res = (pcie_cb_dma_res *)oal_netbuf_cb(skb);
        if (next_skb) {
            prefetch_cached_ddr(oal_netbuf_cb(next_skb));
        }
#else
        cb_res = (pcie_cb_dma_res *)oal_netbuf_cb(skb);
#endif
        if (cb_res == NULL) {
            return NULL;
        }
        /* 复用cb字段 */
        if (cb_res->paddr.addr == host_iova) {
            /* 此处仅从链表中取出，先不进行unmap操作 */
            oal_netbuf_delete_nolock(skb, list);
            return skb;
        }
        /* pre_num计数到达一定门限后，添加自愈机制，TO BE DONE */
        (*pre_num)++;
    }
    return NULL;
}

oal_netbuf_head_stru g_skb_list_temp = { 0 }; // 将局部变量转换全局变量，维测使用。
/*
 * 功能描述   : 释放alloc list中所有元素
 * 1.日    期   : 2020.6.15
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
void hal_rx_alloc_list_free(hal_host_device_stru *hal_dev, hal_host_rx_alloc_list_stru *alloc_list)
{
    oal_netbuf_head_stru *list = &alloc_list->rx_alloc_list;
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
    unsigned long flags = 0;
    oal_netbuf_stru *skb = NULL;
    oal_netbuf_stru *next_skb = NULL;
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    pcie_cb_dma_res *cb_res = NULL;
#endif

    hal_dev->rx_alloc_list_inited = OAL_FALSE;
    if (!hal_dev->rx_q_inited) {
        oam_warning_log0(hal_dev->device_id, OAM_SF_DPA, "hal_rx_alloc_list_free:rx res not inited");
        return;
    }
    /* 清零中转缓存区 */
    if (hal_dev->device_id == HAL_DEVICE_ID_MASTER) {
        dpe_rx_mpdu_list_lock_irq_save(&hal_dev->st_rx_mpdu.st_spin_lock, &flags);
        hal_host_rx_ring_init();
        dpe_rx_mpdu_list_unlock_irq_restore(&hal_dev->st_rx_mpdu.st_spin_lock, &flags);
    }

    oal_netbuf_list_head_init_nolock(&g_skb_list_temp);
    oal_spin_lock_irq_save(dpe_get_dev_rx_alloc_list_lock(alloc_list->rx_alloc_list_lock_idx), &flags);
    if (oal_netbuf_peek(list) != NULL) {
        oal_netbuf_queue_splice_tail_init(list, &g_skb_list_temp);
    }
    oal_spin_unlock_irq_restore(dpe_get_dev_rx_alloc_list_lock(alloc_list->rx_alloc_list_lock_idx), &flags);
    rx_stats->rx_alloc_list_free += oal_netbuf_list_len(&g_skb_list_temp);
    oal_netbuf_search_for_each_safe(skb, next_skb, &g_skb_list_temp) {
        if (skb == NULL) {
            oam_error_log0(hal_dev->device_id, OAM_SF_DPA, "hal_rx_alloc_list_free:skb list is broken");
            return;
        }
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
        cb_res = (pcie_cb_dma_res *)oal_netbuf_cb(skb);
        dpe_dma_unmap_single(cb_res->paddr.addr, oal_netbuf_len(skb), DPE_DMA_FROM_DEVICE); // rx receive
#endif
        oal_netbuf_delete_nolock(skb, &g_skb_list_temp);
        dpe_netbuf_free(skb);
    }
}

/*
 * 功能描述   : 初始化alloc list
 * 1.日    期   : 2020.6.15
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
void hal_init_alloc_list(hal_host_device_stru *hal_dev, uint8_t rx_dscr_queue_id)
{
    oal_netbuf_head_stru    *list;
    hal_host_rx_alloc_list_stru *alloc_list = NULL;
    uint32_t                 len;
    unsigned long            flags = 0;
    if (rx_dscr_queue_id == HAL_RX_DSCR_NORMAL_PRI_QUEUE) {
        alloc_list = &(hal_dev->host_rx_normal_alloc_list); // dma by list
    } else if (rx_dscr_queue_id == HAL_RX_DSCR_SMALL_QUEUE) {
        alloc_list = &(hal_dev->host_rx_small_alloc_list);
    } else {
        oam_error_log1(0, OAM_SF_DPA, "{hal_init_alloc_list:: wrong rx_dscr_queue_id[%d]}", rx_dscr_queue_id);
        return;
    }
    list = &alloc_list->rx_alloc_list;
    len = oal_netbuf_list_len(list);
    if ((oal_netbuf_peek(list) != NULL) || (len != 0)) {
        oam_error_log1(hal_dev->device_id, OAM_SF_DPA, "init_alloc_list:list len[%d] not empty", len);
        hal_rx_alloc_list_free(hal_dev, alloc_list);
    }
    alloc_list->rx_alloc_list_lock_idx = rx_dscr_queue_id * (hal_dev->device_id + 1);
    /* 初始化锁 */
    oal_spin_lock_init(dpe_get_dev_rx_alloc_list_lock(alloc_list->rx_alloc_list_lock_idx));
    oal_netbuf_list_head_init_nolock(list);

    /* 清零中转缓存区 */
    if (hal_dev->device_id == HAL_DEVICE_ID_MASTER) {
        dpe_rx_mpdu_list_lock_irq_save(&hal_dev->st_rx_mpdu.st_spin_lock, &flags);
        hal_host_rx_ring_init();
        dpe_rx_mpdu_list_unlock_irq_restore(&hal_dev->st_rx_mpdu.st_spin_lock, &flags);
    }
}
/*
 * 功能描述   : 固件侧reset_smac, host处理总入口
 * 1.日    期   : 2020.6.15
 *   作    者   : wifi
 */
uint32_t hal_host_rx_reset_smac_handler(hal_host_device_stru *hal_dev)
{
    hal_rx_alloc_list_free(hal_dev, &hal_dev->host_rx_normal_alloc_list); // ring 切换
    oam_warning_log1(0, OAM_SF_DPA, "{host_rx_reset_smac_handler::succ device[%d]}", hal_dev->device_id);
    return OAL_SUCC;
}

oal_netbuf_stru *hal_rx_get_sub_msdu(hal_host_device_stru *hal_device, uint64_t next_dscr_addr)
{
    uint64_t                     host_iova = 0;
    hal_host_rx_alloc_list_stru *alloc_list = &hal_device->host_rx_normal_alloc_list; // dma by list
    unsigned long                flags = 0;
    uint32_t                     pre_num = 0;
    oal_netbuf_stru             *sub_msdu = NULL;

    if (pcie_if_devva_to_hostca(HCC_EP_WIFI_DEV, next_dscr_addr, (uint64_t *)&host_iova) != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_DPA, "{hal_rx_get_sub_msdu:get next msdu fail.}");
        return NULL;
    }
    oal_spin_lock_irq_save(dpe_get_dev_rx_alloc_list_lock(alloc_list->rx_alloc_list_lock_idx), &flags);
    sub_msdu = hal_alloc_list_delete_netbuf(hal_device, alloc_list, host_iova, &pre_num);
    oal_spin_unlock_irq_restore(dpe_get_dev_rx_alloc_list_lock(alloc_list->rx_alloc_list_lock_idx), &flags);
    if (pre_num != 0 && g_wlan_spec_cfg->need_check_netbuf_pre_num == OAL_TRUE) {
        oam_warning_log1(hal_device->device_id, OAM_SF_DPA, "hal_rx_get_sub_msdu:pre num[%d]", pre_num);
    }
    if (sub_msdu == NULL) {
        oam_error_log0(hal_device->device_id, OAM_SF_DPA, "hal_rx_get_sub_msdu:sub msdu not found");
    }
    return sub_msdu;
}
/*
* 函 数 名   : mp16_host_rx_get_mac_header_len
* 功能描述   : 计算RX数据帧的帧头长度
* 1.日    期   : 2021年2月26日
*   作    者   : wifi
*   修改内容   : 计算mac header len
*/
uint8_t hal_host_rx_get_mac_header_len(mac_rx_ctl_stru *rx_ctl)
{
    uint8_t mac_hdr_len = MAC_80211_FRAME_LEN;
    mac_header_frame_control_stru *fc_ctl_hdr = NULL;

    fc_ctl_hdr = (mac_header_frame_control_stru *)&rx_ctl->us_frame_control;
    if (rx_ctl->bit_frame_format == MAC_FRAME_TYPE_80211) {
        if ((fc_ctl_hdr->bit_type == WLAN_DATA_BASICTYPE) || (fc_ctl_hdr->bit_type == WLAN_MANAGEMENT)) {
            /* 4-Address Header */
            if ((fc_ctl_hdr->bit_to_ds == 1) && (fc_ctl_hdr->bit_from_ds == 1)) {
                mac_hdr_len += OAL_MAC_ADDR_LEN;
            }

            /* HTC+ Header */
            mac_hdr_len += (fc_ctl_hdr->bit_order == 1) ? sizeof(uint32_t) : 0;
            /* QoS Header */
            if ((fc_ctl_hdr->bit_type) == WLAN_DATA_BASICTYPE &&
                ((fc_ctl_hdr->bit_sub_type & WLAN_QOS_DATA) == WLAN_QOS_DATA)) {
                mac_hdr_len += sizeof(uint16_t);
            }
        } else {
            /* ctrl frame */
            mac_hdr_len = MAC_80211_CTL_HEADER_LEN;
            /* 适配monitor ack rts cts等 */
            if (rx_ctl->us_frame_len < mac_hdr_len) {
                mac_hdr_len = (uint8_t)(rx_ctl->us_frame_len);
            }
        }
    } else {
        /* 以太网帧头长度 */
        mac_hdr_len = ETHER_HDR_LEN;
    }

    return mac_hdr_len;
}

void hal_rx_set_ring_regs(hal_host_ring_ctl_stru *rx_ring_ctl)
{
    if (rx_ring_ctl->devva == 0) {
        oam_error_log2(0, OAM_SF_DPA, "rx_set_ring_regs::ring_type %d, subtype %d!",
            rx_ring_ctl->ring_type, rx_ring_ctl->ring_subtype);
        return;
    }

    hal_host_writel(get_low_32bits(rx_ring_ctl->devva), rx_ring_ctl->base_lsb);
    hal_host_writel(get_high_32bits(rx_ring_ctl->devva), rx_ring_ctl->base_msb);
    hal_host_writel(rx_ring_ctl->entries, rx_ring_ctl->ring_size_reg);

    /* hw与sw保持一致 */
    rx_ring_ctl->un_read_ptr.read_ptr = 0;
    rx_ring_ctl->un_write_ptr.write_ptr = 0;

    if (rx_ring_ctl->write_ptr_reg != 0) {
        hal_host_writel(0, rx_ring_ctl->write_ptr_reg);
    }
    if (rx_ring_ctl->cfg_read_ptr_reg != 0) {
        hal_host_writel(0, rx_ring_ctl->cfg_read_ptr_reg);
    }
    if (rx_ring_ctl->read_ptr_reg != 0) {
        hal_host_writel(0, rx_ring_ctl->read_ptr_reg);
    }
    if (rx_ring_ctl->cfg_write_ptr_reg != 0) {
        hal_host_writel(0, rx_ring_ctl->cfg_write_ptr_reg);
    }
}

static uint64_t hal_rx_ring_regs_addr_transfer(uint8_t device_id, uint32_t reg_addr)
{
    uint64_t host_va = 0;
    uint32_t mac_reg_offset = hal_get_mac_reg_offset(device_id, reg_addr);
    uint8_t dev_num = mac_chip_get_hal_dev_num();
    if (device_id >= dev_num) {
        oam_error_log2(0, OAM_SF_DPA, "{ring_ctl_regs_addr_transfer::device_id[%d],addr[%x], check device_id fail}",
            device_id, reg_addr);
        return 0;
    }
    if (oal_pcie_devca_to_hostva(HCC_EP_WIFI_DEV, reg_addr + mac_reg_offset, &host_va) == OAL_SUCC) {
        return host_va;
    } else {
        oam_error_log2(0, OAM_SF_DPA, "{ring_ctl_regs_addr_transfer::device_id[%d],addr[%x] transfer fail}",
            device_id, reg_addr);
        return 0;
    }
}

uint8_t hal_rx_ring_reg_init(hal_host_device_stru *hal_dev, hal_host_ring_ctl_stru *rctl, uint8_t ring_id)
{
    hal_ring_mac_regs_info* ring_reg_tbl = hal_get_ring_mac_regs_tbl();
    if ((hal_dev == NULL) || (rctl == NULL) || (ring_id >= HAL_RING_ID_BUTT) || (ring_reg_tbl == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_rx_ring_reg_init::null input}");
        return OAL_FALSE;
    }

    rctl->base_lsb      = hal_rx_ring_regs_addr_transfer(hal_dev->device_id, ring_reg_tbl[ring_id].base_lsb);
    rctl->base_msb      = hal_rx_ring_regs_addr_transfer(hal_dev->device_id, ring_reg_tbl[ring_id].base_msb);
    rctl->ring_size_reg = hal_rx_ring_regs_addr_transfer(hal_dev->device_id, ring_reg_tbl[ring_id].size);
    rctl->write_ptr_reg = hal_rx_ring_regs_addr_transfer(hal_dev->device_id, ring_reg_tbl[ring_id].wptr_reg);
    rctl->read_ptr_reg  = hal_rx_ring_regs_addr_transfer(hal_dev->device_id, ring_reg_tbl[ring_id].rptr_reg);
    rctl->rx_ring_reset = hal_rx_ring_regs_addr_transfer(hal_dev->device_id, ring_reg_tbl[ring_id].rx_ring_reset);
    if (!((rctl->base_lsb) && (rctl->base_msb) && (rctl->ring_size_reg) &&
        (rctl->write_ptr_reg) && (rctl->read_ptr_reg))) {
        oam_error_log4(0, OAM_SF_DPA, "{rx_ring_reg_init::base_lsb[0x%x%x],base_msb[0x%x%x]}",
            (uint32_t)(rctl->base_lsb >> NUM_32_BYTES), (uint32_t)(rctl->base_lsb),
            (uint32_t)(rctl->base_msb >> NUM_32_BYTES), (uint32_t)(rctl->base_msb));
        oam_error_log4(0, OAM_SF_DPA, "{rx_ring_reg_init::wptr_reg[0x%x%x] rptr_reg[0x%x%x]}",
            (uint32_t)(rctl->write_ptr_reg >> NUM_32_BYTES), (uint32_t)(rctl->write_ptr_reg),
            (uint32_t)(rctl->read_ptr_reg >> NUM_32_BYTES), (uint32_t)(rctl->read_ptr_reg));
        oam_error_log2(0, OAM_SF_DPA, "{rx_ring_reg_init::ring_size_reg[0x%x%x]}",
            (uint32_t)(rctl->ring_size_reg >> NUM_32_BYTES), (uint32_t)(rctl->ring_size_reg));
        return OAL_FALSE;
    }
    if (ring_id < HAL_RING_TYPE_COMP) {
        rctl->cfg_read_ptr_reg =
            hal_rx_ring_regs_addr_transfer(hal_dev->device_id, ring_reg_tbl[ring_id].cfg_rptr_reg);
        return !!(rctl->cfg_read_ptr_reg);
    } else {
        if (ring_reg_tbl[ring_id].len) {
            rctl->len_reg  = hal_rx_ring_regs_addr_transfer(hal_dev->device_id, ring_reg_tbl[ring_id].len);
            rctl->cfg_write_ptr_reg =
                hal_rx_ring_regs_addr_transfer(hal_dev->device_id, ring_reg_tbl[ring_id].cfg_wptr_reg);
            return ((rctl->len_reg) && (rctl->cfg_write_ptr_reg));
        } else {
            rctl->cfg_write_ptr_reg =
                hal_rx_ring_regs_addr_transfer(hal_dev->device_id, ring_reg_tbl[ring_id].cfg_wptr_reg);
            return OAL_TRUE;
        }
    }
}

void hal_rx_init_ring_ptr_host_addr(hal_host_device_stru *hal_dev)
{
    void *rbase_vaddr = NULL;
    uint64_t rbase_dma_addr = 0;
    hal_host_chip_stru *hal_chip = hal_get_host_chip();

    // 申请MAC上报Host侧指针的内存
    dpe_dma_buff_alloc(sizeof(hal_rx_ring_mac_ptr_info) * HAL_MAC_PTR_RPT_HOST_BUTT,
        &rbase_vaddr, &rbase_dma_addr, DPE_GFP_KERNEL);
    if (rbase_vaddr == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hal_rx_init_ring_ptr_host_addr::alloc ptr rpt host mem fail.");
        return;
    }
    memset_s(rbase_vaddr, sizeof(hal_rx_ring_mac_ptr_info) * HAL_MAC_PTR_RPT_HOST_BUTT, 0,
        sizeof(hal_rx_ring_mac_ptr_info) * HAL_MAC_PTR_RPT_HOST_BUTT);
    hal_chip->rx_ring_mac_ptr_info = (hal_rx_ring_mac_ptr_info *)rbase_vaddr;
    hal_chip->rx_ring_mac_ptr_addr.rbase_bus_addr = rbase_dma_addr;
    oam_warning_log0(0, OAM_SF_DPA, "hal_rx_init_ring_ptr_host_addr::init rpt host addr succ!");
}

void hal_rx_set_ring_ptr_host_addr(hal_host_device_stru *hal_dev)
{
    uint64_t devva = 0;
    uint64_t host_va_lsb;
    uint64_t host_va_msb;
    uint64_t ring_ptr_rpt_mode;
    hal_host_chip_stru *hal_chip = hal_get_host_chip();

    if (hal_chip->rx_ring_mac_ptr_info == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_rx_set_ring_ptr_host_addr::get rx ring mac ptr fail.}");
        return;
    }

    memset_s(hal_chip->rx_ring_mac_ptr_info, sizeof(hal_rx_ring_mac_ptr_info) * HAL_MAC_PTR_RPT_HOST_BUTT, 0,
        sizeof(hal_rx_ring_mac_ptr_info) * HAL_MAC_PTR_RPT_HOST_BUTT);

    if (pcie_if_hostca_to_devva(HCC_EP_WIFI_DEV, (uint64_t)hal_chip->rx_ring_mac_ptr_addr.rbase_bus_addr,
        &devva) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hal_rx_set_ring_ptr_host_addr::set ring ptr host addr fail.");
        return;
    }

    host_va_lsb = hal_rx_ring_regs_addr_transfer(hal_dev->device_id,
        hal_chip->rx_ring_mac_ptr_addr.mac_ptr_rpt_host_addr_lsb);
    host_va_msb = hal_rx_ring_regs_addr_transfer(hal_dev->device_id,
        hal_chip->rx_ring_mac_ptr_addr.mac_ptr_rpt_host_addr_msb);
    hal_host_writel(get_low_32bits(devva), host_va_lsb);
    hal_host_writel(get_high_32bits(devva), host_va_msb);

    /* 配置上报模式寄存器 */
    ring_ptr_rpt_mode = hal_rx_ring_regs_addr_transfer(hal_dev->device_id,
        hal_chip->rx_ring_mac_ptr_addr.ring_ptr_rpt_mode);
    hal_host_set_mac_ptr_rpt_regs(ring_ptr_rpt_mode);

    oam_warning_log0(0, OAM_SF_DPA, "hal_rx_set_ring_ptr_host_addr::set rpt host addr succ!");
}

int32_t hal_rx_host_init_small_free_ring(hal_host_device_stru *pst_device)
{
    uint16_t entries;
    hal_host_ring_ctl_stru *rx_ring_ctl = NULL;
    uint32_t alloc_size;
    uint64_t rbase_dma_addr = 0;
    void *rbase_vaddr = NULL;
    uint64_t devva = 0;
    int32_t ret;

    rx_ring_ctl = &(pst_device->st_host_rx_small_free_ring);
    memset_s(rx_ring_ctl, sizeof(hal_host_ring_ctl_stru), 0, sizeof(hal_host_ring_ctl_stru));

    entries = (pst_device->device_id == 0) ? HAL_RX_MSDU_SMALL_RING_NUM0 : HAL_RX_MSDU_SMALL_RING_NUM0;
    alloc_size = (entries * HAL_RX_ENTRY_SIZE);
    dpe_dma_buff_alloc(alloc_size, &rbase_vaddr, &rbase_dma_addr, DPE_GFP_KERNEL);
    if (rbase_vaddr == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "normal_free:dma_alloc fail, size[%d]", alloc_size);
        return OAL_FAIL;
    }

    ret = pcie_if_hostca_to_devva(HCC_EP_WIFI_DEV, (uint64_t)rbase_dma_addr, &devva);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "rx_host_init_small_free_ring alloc pcie_if_hostca_to_devva fail.");
        dpe_dma_buff_free(alloc_size, rbase_vaddr, rbase_dma_addr);
        return OAL_FAIL;
    }

    rx_ring_ctl->entries = entries;
    rx_ring_ctl->p_entries = (uint64_t *)rbase_vaddr;
    rx_ring_ctl->entry_size = HAL_RX_ENTRY_SIZE;
    rx_ring_ctl->ring_type = HAL_RING_TYPE_FREE_RING;
    rx_ring_ctl->ring_subtype = HAL_RING_TYPE_S_F;
    rx_ring_ctl->devva = devva;

    if (hal_rx_ring_reg_init(pst_device, rx_ring_ctl, HAL_RING_TYPE_S_F) == OAL_FALSE) {
        oam_error_log0(0, OAM_SF_DPA, "rx_host_init_small_free_ring alloc pcie_if_hostca_to_devva fail.");
        dpe_dma_buff_free(alloc_size, rbase_vaddr, rbase_dma_addr);
        rx_ring_ctl->p_entries = NULL;
        return OAL_FAIL;
    }
    hal_init_alloc_list(pst_device, HAL_RX_DSCR_SMALL_QUEUE);
    return OAL_SUCC;
}

int32_t hal_rx_host_init_normal_free_ring(hal_host_device_stru *pst_device)
{
    uint16_t entries;
    hal_host_ring_ctl_stru *rx_ring_ctl = NULL;
    uint32_t alloc_size;
    void *rbase_vaddr = NULL;
    uint64_t devva = 0;
    uint64_t rbase_dma_addr = 0;

    rx_ring_ctl = &(pst_device->st_host_rx_normal_free_ring);
    memset_s(rx_ring_ctl, sizeof(hal_host_ring_ctl_stru), 0, sizeof(hal_host_ring_ctl_stru));

    entries = (pst_device->device_id == 0) ? HAL_RX_MSDU_NORMAL_RING_NUM : HAL_RX_MSDU_NORMAL_RING_NUM;
    alloc_size = (entries * HAL_RX_ENTRY_SIZE);

    dpe_dma_buff_alloc(alloc_size, &rbase_vaddr, &rbase_dma_addr, DPE_GFP_KERNEL);
    if (rbase_vaddr == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hal_rx_host_init_normal_free_ring alloc pcie_dev  null.");
        return OAL_FAIL;
    }

    if (pcie_if_hostca_to_devva(HCC_EP_WIFI_DEV, (uint64_t)rbase_dma_addr, &devva) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hal_rx_host_init_normal_free_ring alloc pcie_if_hostca_to_devva fail.");
        dpe_dma_buff_free(alloc_size, rbase_vaddr, rbase_dma_addr);
        return OAL_FAIL;
    }

    rx_ring_ctl->entries    = entries;
    rx_ring_ctl->p_entries  = (uint64_t *)rbase_vaddr;
    rx_ring_ctl->entry_size = HAL_RX_ENTRY_SIZE;
    rx_ring_ctl->ring_type  = HAL_RING_TYPE_FREE_RING;
    rx_ring_ctl->ring_subtype = HAL_RING_TYPE_L_F;
    rx_ring_ctl->devva = devva;

    if (hal_rx_ring_reg_init(pst_device, rx_ring_ctl, HAL_RING_TYPE_L_F) == OAL_FALSE) {
        oam_error_log0(0, OAM_SF_DPA, "hal_rx_host_init_normal_free_ring alloc pcie_if_hostca_to_devva fail.");
        dpe_dma_buff_free(alloc_size, rbase_vaddr, rbase_dma_addr);
        rx_ring_ctl->p_entries = NULL;
        return OAL_FAIL;
    }
    hal_init_alloc_list(pst_device, HAL_RX_DSCR_NORMAL_PRI_QUEUE);
    oam_warning_log3(0, OAM_SF_DPA, "hal_rx_host_init_normal_free_ring :base[0x%x%x].size[%d]",
        get_high_32bits(devva), get_low_32bits(devva), entries);
    return OAL_SUCC;
}

int32_t hal_rx_host_init_complete_ring(hal_host_device_stru *pst_device)
{
    uint16_t entries;
    hal_host_ring_ctl_stru *rx_ring_ctl = NULL;
    uint32_t alloc_size;
    uint64_t rbase_dma_addr = 0;
    void *rbase_vaddr = NULL;
    uint64_t devva = 0;

    rx_ring_ctl = &(pst_device->st_host_rx_complete_ring);
    memset_s(rx_ring_ctl, sizeof(hal_host_ring_ctl_stru), 0, sizeof(hal_host_ring_ctl_stru));

    entries = HAL_RX_COMPLETE_RING_MAX;
    alloc_size = (entries * HAL_RX_ENTRY_SIZE);
    dpe_dma_buff_alloc(alloc_size, &rbase_vaddr, &rbase_dma_addr, DPE_GFP_KERNEL);
    if (rbase_vaddr == NULL) {
        return OAL_FAIL;
    }

    if (pcie_if_hostca_to_devva(HCC_EP_WIFI_DEV, (uint64_t)rbase_dma_addr, &devva) != OAL_SUCC) {
        dpe_dma_buff_free(alloc_size, rbase_vaddr, rbase_dma_addr);
        return OAL_FAIL;
    }

    rx_ring_ctl->entries = entries;
    rx_ring_ctl->p_entries = (uint64_t *)rbase_vaddr;
    rx_ring_ctl->entry_size = HAL_RX_ENTRY_SIZE;
    rx_ring_ctl->ring_type = HAL_RING_TYPE_COMPLETE_RING;
    rx_ring_ctl->ring_subtype = HAL_RING_TYPE_COMP;
    rx_ring_ctl->devva = devva;

    if (hal_rx_ring_reg_init(pst_device, rx_ring_ctl, HAL_RING_TYPE_COMP) == OAL_FALSE) {
        oam_error_log0(0, OAM_SF_DPA, "hal_rx_host_init_complete_ring alloc pcie_if_hostca_to_devva  fail.");
        dpe_dma_buff_free(alloc_size, rbase_vaddr, rbase_dma_addr);
        rx_ring_ctl->p_entries = NULL;
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

int32_t hal_rx_host_init_dscr_queue(uint8_t hal_dev_id)
{
    hal_host_device_stru *hal_device = hal_get_host_device(hal_dev_id);

    if ((hal_device == NULL) || (hal_dev_id >= mac_chip_get_hal_dev_num())) {
        oam_error_log1(0, OAM_SF_DPA, "hal_rx_host_init_dscr_queue::hal dev null. id[%d].", hal_dev_id);
        return OAL_FAIL;
    }

    if (hal_device->rx_q_inited) {
        oam_warning_log0(0, OAM_SF_DPA, "hal_rx_host_init_dscr_queue::already inited.");
        return OAL_SUCC;
    }

    /* host访问device寄存器的地址映射操作 */
    hal_host_regs_addr_init(hal_device);

    /* 初始化接收硬件队列 */
    if (hal_rx_host_init_normal_free_ring(hal_device) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hal_rx_host_init_dscr_queue::init_normal_free_ring fail.");
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_WIFI, CHR_LAYER_DEV,
                             CHR_WIFI_DEV_EVENT_RING_RX, CHR_WIFI_DEV_ERROR_RX_RING_INIT);
        return OAL_FAIL;
    }

    if (hal_rx_host_init_small_free_ring(hal_device) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hal_rx_host_init_dscr_queue::init_small_free_ring fail.");
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_WIFI, CHR_LAYER_DEV,
                             CHR_WIFI_DEV_EVENT_RING_RX, CHR_WIFI_DEV_ERROR_RX_RING_INIT);
        return OAL_FAIL;
    }

    if (hal_rx_host_init_complete_ring(hal_device) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hal_rx_host_init_dscr_queue::init_complete_ring fail.");
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_WIFI, CHR_LAYER_DEV,
                             CHR_WIFI_DEV_EVENT_RING_RX, CHR_WIFI_DEV_ERROR_RX_RING_INIT);
        return OAL_FAIL;
    }

    /* rx方向负载优化，初始化ring指针上报host侧地址 */
    if (g_wlan_spec_cfg->rx_ring_reduce_load_is_open == OAL_TRUE) {
        hal_rx_init_ring_ptr_host_addr(hal_device);
    }

    hal_device->rx_q_inited = OAL_TRUE;
    oam_warning_log0(0, OAM_SF_DPA, "hal_rx_host_init_dscr_queue::inited succ.");

    return OAL_SUCC;
}

uint32_t hal_rx_d2h_init_dscr_queue(uint8_t hal_dev_id)
{
    hal_host_device_stru *hal_device  = hal_get_host_device(hal_dev_id);
    uint32_t mpdu_desc_size = hal_host_get_rx_msdu_dscr_len();
    if (hal_device == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{rx_host_start_dscr_queue::hal_device null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (hal_device->rx_alloc_list_inited) {
        return OAL_SUCC;
    }

    /* 队列的初始化可以放到hal device init函数内做一次 */
    if (hal_rx_host_init_dscr_queue(hal_dev_id) != OAL_SUCC) {
        return OAL_FAIL;
    }
    /* host data ring复位 */
    if (hal_device->st_host_rx_normal_free_ring.rx_ring_reset != 0) {
        hal_host_h2d_rx_ring_reset(hal_device);
    }
    /* LEN REG keep default */
    hal_rx_set_ring_regs(&(hal_device->st_host_rx_normal_free_ring));
    hal_rx_set_ring_regs(&(hal_device->st_host_rx_small_free_ring));
    hal_rx_set_ring_regs(&(hal_device->st_host_rx_complete_ring));

    /* rx方向负载优化，设置ring指针上报host侧地址及上报模式寄存器 */
    if (g_wlan_spec_cfg->rx_ring_reduce_load_is_open == OAL_TRUE) {
        hal_rx_set_ring_ptr_host_addr(hal_device);
    }

    if (hal_device->st_alrx.en_al_rx_flag != 0) {
        if (!hal_device->st_host_rx_complete_ring.len_reg) {
            oam_error_log0(0, OAM_SF_DPA, "rx_host_start_dscr_queue::len_reg not inited!");
            return OAL_FAIL;
        }
        hal_host_writel(((ALRX_NETBUF_SIZE + mpdu_desc_size) | (mpdu_desc_size << NUM_16_BITS)),
            hal_device->st_host_rx_complete_ring.len_reg);
    }
    /* host data ring解复位 */
    if (hal_device->st_host_rx_normal_free_ring.rx_ring_reset != 0) {
        hal_host_writel(0x0, hal_device->st_host_rx_normal_free_ring.rx_ring_reset);
    }
    /* 向数据帧normal free ring添加内存 */
    hal_host_rx_add_buff(hal_device, HAL_RX_DSCR_NORMAL_PRI_QUEUE);
    hal_device->rx_alloc_list_inited = OAL_TRUE;
    hal_device->dscr_prev = 0;
    oam_warning_log1(0, OAM_SF_DPA, "rx_host_start_dscr_queue::dev[%d]succ!", hal_dev_id);
    return OAL_SUCC;
}

OAL_STATIC void hal_rx_host_destory_free_ring(hal_host_ring_ctl_stru *rx_ring_ctl)
{
}

OAL_STATIC void hal_rx_host_destory_comp_ring(hal_host_ring_ctl_stru *rx_ring_ctl)
{
}

int32_t hal_rx_host_stop_dscr_queue(uint8_t hal_dev_id)
{
    hal_host_device_stru   *hal_device  = hal_get_host_device(hal_dev_id);

    if (hal_device == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 不用host去reset ring cfg regs，避免处理不必要的同步问题 */
    hal_rx_host_destory_free_ring(&hal_device->st_host_rx_small_free_ring);
    hal_rx_host_destory_free_ring(&hal_device->st_host_rx_normal_free_ring);
    hal_rx_host_destory_comp_ring(&hal_device->st_host_rx_complete_ring);

    return OAL_SUCC;
}

void hal_host_intr_regs_init(uint8_t hal_dev_id)
{
    hal_host_device_stru *hal_device = hal_get_host_device(hal_dev_id);

    if (hal_device == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{host_ring_tx_init::haldev null!}");
        return;
    }

    oam_warning_log2(0, OAM_SF_DPA, "host_intr_regs_init::dev_id[%d], initr_inited state[%d]!",
                     hal_device->device_id, hal_device->intr_inited);
    if (hal_device->intr_inited) {
        return;
    }

    if (hal_host_regs_addr_init(hal_device) != OAL_SUCC) {
        return;
    }
    hal_device->intr_inited = OAL_TRUE;
}

hal_host_device_stru *hal_rx_get_mpdu_link(oal_netbuf_stru *mpdu)
{
    mac_rx_ctl_stru *rx_cb = (mac_rx_ctl_stru *)oal_netbuf_cb(mpdu);
    uint8_t link_id;
    uint8_t dev_num = mac_chip_get_hal_dev_num();

    if (rx_cb == NULL) {
        return NULL;
    }
    link_id = rx_cb->link_id;

    return link_id < dev_num ? hal_get_host_device(link_id) : NULL;
}

uint8_t hal_rx_is_frag_frm(mac_rx_ctl_stru *rx_ctl)
{
    mac_header_frame_control_stru *fc_ctl_hdr = (mac_header_frame_control_stru *)&rx_ctl->us_frame_control;

    return (uint8_t)((rx_ctl->bit_frame_format == MAC_FRAME_TYPE_80211) &&
        (fc_ctl_hdr->bit_more_frag || rx_ctl->bit_fragment_num));
}

/*
 * 功能描述  : cb中长度计算，并调整netbuf数据部分头尾指针
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hal_rx_adjust_netbuf_len(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl)
{
    uint32_t rx_msdu_len;
    pcie_cb_dma_res *cb_res = (pcie_cb_dma_res *)oal_netbuf_cb(netbuf);
    if (cb_res == NULL) {
        return OAL_FAIL;
    }

    rx_msdu_len = hal_host_get_rx_msdu_dscr_len();
    oal_netbuf_pull(netbuf, rx_msdu_len);
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* 1.fcs错误，后续字段信息不需要查看，本身不可信  2.fcs错误的amsdu非首帧信息本身不回填，字段不可信 */
    if ((rx_ctl->rx_status == HAL_RX_SUCCESS) &&
        (rx_ctl->us_frame_len == 0 || (rx_ctl->us_frame_len > (cb_res->len - rx_msdu_len)))) {
        oam_error_log3(0, OAM_SF_DPA, "host_rx_adjust_netbuf_len:pkt len:%d, pcie cb len:%d msdu len %d",
            rx_ctl->us_frame_len, cb_res->len, rx_msdu_len);
        return OAL_FAIL;
    }
#endif
    oal_netbuf_trim(netbuf, rx_ctl->us_frame_len);
    return OAL_SUCC;
}

oal_bool_enum_uint8 hal_rx_ip_checksum_is_pass(oal_netbuf_stru *netbuf)
{
    mac_rx_ctl_stru *rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (rx_ctrl == NULL) {
        return OAL_FALSE;
    }
    if  (rx_ctrl->bit_ipv4cs_valid && (rx_ctrl->bit_ipv4cs_pass == 0)) {
        return OAL_FALSE;
    } else {
        return OAL_TRUE;
    }
}

void hal_rx_tcp_udp_checksum(oal_netbuf_stru *netbuf)
{
    oal_netbuf_stru *cur_netbuf = netbuf;
    oal_netbuf_stru *next_netbuf = NULL;
    mac_rx_ctl_stru *rx_ctrl = NULL;
    while (cur_netbuf != NULL) {
        next_netbuf = oal_netbuf_next(cur_netbuf);
        rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb(cur_netbuf);
        if (rx_ctrl->bit_ptlcs_valid && rx_ctrl->bit_ptlcs_pass) {
            dpe_rx_set_netbuf_checksum(cur_netbuf, OAL_TRUE);
        }
        dpe_device_rx_checksum_stat(rx_ctrl);
        cur_netbuf = next_netbuf;
    }
}

#ifdef _PRE_WLAN_FEATURE_VSP
#define MAX_BUFFER_IN_RECYCLE_LIST 20
uint32_t hal_vsp_rx_buff_recycle(hal_host_device_stru *hal_device, oal_netbuf_head_stru *netbuf_head)
{
    oal_netbuf_stru *netbuf = NULL;
    uint32_t netbuf_total_len, headroom, rx_msdu_len;
    uint32_t recycle_cnt = 0;

    if (hal_device == NULL) {
        while ((netbuf = oal_netbuf_delist_nolock(netbuf_head)) != NULL) {
            dpe_netbuf_free(netbuf);
        }
        return 0; // 若vsp已经stop(hal_device=null),直接释放netbuf
    }

    if (oal_netbuf_list_len(&hal_device->vsp_netbuf_recycle_list) > MAX_BUFFER_IN_RECYCLE_LIST) {
        oal_netbuf_list_purge(netbuf_head);
        return 0;
    }
    rx_msdu_len = hal_host_get_rx_msdu_dscr_len();
    while ((netbuf = oal_netbuf_delist_nolock(netbuf_head)) != NULL) {
        headroom = oal_netbuf_headroom(netbuf);
        netbuf_total_len = headroom + oal_netbuf_len(netbuf) + oal_netbuf_tailroom(netbuf);
        if (netbuf_total_len < LARGE_NETBUF_SIZE + rx_msdu_len) {
            oam_warning_log1(0, OAM_SF_DPA, "{host_rx_buff_recycle::buffer room[%d] not sufficent}", netbuf_total_len);
            dpe_netbuf_free(netbuf);
            continue;
        }
        oal_netbuf_push(netbuf, headroom);
        oal_netbuf_set_len(netbuf, LARGE_NETBUF_SIZE + rx_msdu_len);
        oal_netbuf_add_to_list_tail(netbuf, &hal_device->vsp_netbuf_recycle_list);
        recycle_cnt++;
    }

    return recycle_cnt;
}
#endif

uint32_t hal_host_rx_amsdu_list_build(hal_host_device_stru *hal_device, oal_netbuf_stru *netbuf)
{
    oal_netbuf_stru *next_netbuf = NULL;
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    pcie_cb_dma_res *cb_res = NULL;
#endif
    while (netbuf != NULL) {
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
        if (dpe_host_rx_netbuf_payload_cpy_to_sbuf_cb(netbuf) != OAL_SUCC) {
            return OAL_FAIL;
        }
#endif
        next_netbuf = hal_rx_get_next_sub_msdu(hal_device, netbuf);
        oal_set_netbuf_next(netbuf, next_netbuf);
        netbuf = next_netbuf;
        rx_stats->rx_data_msdu_cnt++;
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
        if (netbuf != NULL) {
            cb_res = (pcie_cb_dma_res *)oal_netbuf_cb(netbuf);
            if (oal_likely(cb_res != NULL)) {
                dpe_dma_unmap_single(cb_res->paddr.addr, oal_netbuf_len(netbuf), DPE_DMA_FROM_DEVICE);
            }
        }
#endif
    }
    return OAL_SUCC;
}

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
// 将netbuf的cb通过dma拷贝到全局变量里做检查是否已清0
uint8_t g_tx_msdu_info_temp[WIFI_DPE_XMIT_DMA_CLR_LEN] OSL_CACHELINE_ALIGNED = { 0 };
uint8_t g_tx_msdu_info_clear_check = 0;
#endif
void dpe_tx_msdu_info_clear_check(oal_netbuf_stru *netbuf)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    uint8_t idx = 0;
    uint32_t sum = 0; /* headroom 64字节内容总和 */
    uint32_t *addr = NULL;
    if (g_tx_msdu_info_clear_check == 0) {
        return;
    }
    memset_s(g_tx_msdu_info_temp, WIFI_DPE_XMIT_DMA_CLR_LEN, 0, WIFI_DPE_XMIT_DMA_CLR_LEN);
    // 这里无需对g_tx_msdu_info_temp刷cache，dpe_dma_cpy_cache接口内已封装
    /* dpe访问payload内容必须通过EICC dma搬运，拷贝tx count开始的4字节 */
    if (dpe_dma_cpy_cache((void *)g_tx_msdu_info_temp, (uint64_t)(oal_netbuf_data(netbuf) - WIFI_DPE_XMIT_DSCR_LEN),
        (uint64_t)g_tx_msdu_info_temp, WIFI_DPE_XMIT_DSCR_LEN, DPE_TX_COMP_DMA) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_tx_msdu_info_clear_check:: dma cpy fail");
        return;
    }
    if (unlikely(dpe_cache_invalid((void *)g_tx_msdu_info_temp, WIFI_DPE_XMIT_DMA_CLR_LEN) != OAL_SUCC)) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_tx_msdu_info_clear_check:dpe_cache_invalid returns fail}");
    }
    addr = (uint32_t *)g_tx_msdu_info_temp;
    for (; idx < (WIFI_DPE_XMIT_DSCR_LEN / sizeof(uint32_t)); idx++) {
        sum += addr[idx];
    }
    if (sum != 0) {
        oam_error_log1(0, OAM_SF_DPA, "dpe tx gso sbuf headroom sum %d != 0", sum);
    }
#endif
}