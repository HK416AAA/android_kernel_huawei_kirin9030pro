/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpe netdev
 * 作    者 : xianglei
 * 创建日期 : 2025年5月20日
 */
#ifndef DPE_DPA_INTF_H
#define DPE_DPA_INTF_H

#include "oal_types.h"
#include "dpe_netdev.h"
#include "dpe_wlan_stat.h"
#include "hd_trx_data.h"
#ifdef _PRE_PLAT_FEATURE_DPA
#include <dpa/dpa_sms.h>
#include <dpa/dpa_mem_layout.h>
#endif

/* dpa传递给host的4字节私有信息,不可扩展 */
typedef struct {
    uint32_t vap_id : 4;
    uint32_t data_type : 6;
    uint32_t transfer_from_dpa : 1; /* 标记是否软转代理帧 */
    uint32_t cipher_type : 5;
    uint32_t rx_user_id : 16;
} dpe_wlan_rx_filter_priv_data_stru;

OAL_STATIC OAL_INLINE uint32_t dpe_dpa_sms_get_netdev_feature(void)
{
#ifdef _PRE_PLAT_FEATURE_DPA
    return (uint32_t)dpa_sms_get_netdev_feature_ops();
#else
    return 0;
#endif
}

OAL_STATIC OAL_INLINE int dpe_dpa_sms_filter_add_entry_ops(oal_netbuf_stru *netbuf)
{
#ifdef _PRE_PLAT_FEATURE_DPA
    return dpa_sms_filter_add_entry_ops(DPA_SMS_NIC_WLAN, netbuf);
#else
    return 0;
#endif
}

OAL_STATIC OAL_INLINE int dpe_dpa_sms_sync_netdev_ops(oal_net_device_stru *net_device,
    sync_wlan_priv_info_stru *dpe_netdev_priv_info)
{
#ifdef _PRE_PLAT_FEATURE_DPA
    uint32_t sync_event = NIC_SYNC_EVENT_MAX;

    switch (dpe_netdev_priv_info->sync_event) {
        case DPE_NETDEV_SYNC_ADD_NETDEV:
            sync_event = NIC_SYNC_EVENT_ADD;
            break;
        case DPE_NETDEV_SYNC_DEL_NETDEV:
            sync_event = NIC_SYNC_EVENT_DEL;
            break;
        case DPE_NETDEV_SYNC_ADD_VAP:
        case DPE_NETDEV_SYNC_DEL_VAP:
        case DPE_NETDEV_SYNC_CHANGE_FLAGS:
        case DPE_NETDEV_SYNC_VAP_UPDATE_NETDEV:
            sync_event = NIC_SYNC_EVENT_UPDATE_INFO;
            break;
        default:
            break;
    }
    return dpa_sms_sync_netdev_ops(DPA_SMS_NIC_WLAN, net_device, (uint8_t *)dpe_netdev_priv_info, sync_event);
#else
    return OAL_SUCC;
#endif
}

OAL_STATIC OAL_INLINE int dpe_dpa_sms_rx_callback_register_ops(void *hmac_rx_skb_from_gro_func)
{
#ifdef _PRE_PLAT_FEATURE_DPA
    struct dpa_sms_rx_callback_s cb;

    memset_s(&cb, sizeof(struct dpa_sms_rx_callback_s), 0, sizeof(struct dpa_sms_rx_callback_s));
    cb.rx = hmac_rx_skb_from_gro_func;
    return dpa_sms_rx_callback_register_ops(DPA_SMS_NIC_WLAN, &cb);
#else
    return OAL_SUCC;
#endif
}

OAL_STATIC OAL_INLINE int dpe_dpa_sms_tx_unblock_cb_register(void *hmac_dpa_sms_tx_unblock_state_notify_func)
{
#ifdef _PRE_PLAT_FEATURE_DPA
    return dpa_sms_tx_unblock_cb_register_ops(hmac_dpa_sms_tx_unblock_state_notify_func);
#else
    return OAL_SUCC;
#endif
}

// 入参 dma_handle为申请到的cma的物理地址，dpe使用
// 返回值 void *的地址是申请到的虚拟地址，acpu使用
OAL_STATIC OAL_INLINE void *dpe_dpa_cma_alloc(size_t size, uint64_t *dma_handle)
{
#ifdef _PRE_PLAT_FEATURE_DPA
    return dpa_cma_alloc_ops(ALIGN(size, PAGE_SIZE), dma_handle, GFP_KERNEL);
#else
    return NULL;
#endif
}

OAL_STATIC OAL_INLINE void dpe_print_funcname(void)
{
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_mem_print_funcname(OAL_RET_ADDR);
#else
    oal_dump_callstack();
#endif
}

// 用于hmac获取dpa 32K时间戳，与dpa的bsp_get_slice_value接口一致，时间戳返回值为递增值，一个数值代表30.5us。
OAL_STATIC OAL_INLINE uint32_t host_get_dpa_slice_value(void)
{
#ifdef _PRE_PLAT_FEATURE_DPA
    void *vaddr = ioremap((phys_addr_t)(uintptr_t)0xFDB23000, 0x1000); // 0xFDB23000, 0x1000为地址和偏移量
    u32 slice = readl((void *)((uintptr_t)(vaddr + 0x534))); // 0x534为偏移量
    return slice;
#else
    return 0;
#endif
}
// 将32K时间戳转换为ms
static inline uint32_t host_get_dpa_elapse_ms(void)
{
#ifdef _PRE_PLAT_FEATURE_DPA
    return (uint32_t)((unsigned long long)host_get_dpa_slice_value() * 1000 / 32764); // 1毫秒=1000微秒 32764为频率
#else
    return 0;
#endif
}
#endif /* DPE_DPA_INTF_H end */