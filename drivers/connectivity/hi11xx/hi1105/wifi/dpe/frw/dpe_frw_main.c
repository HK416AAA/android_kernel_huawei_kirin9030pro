/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : FRW模块初始化与卸载
 * 作者       : 康国昌
 * 创建日期   : 2012年9月18日
 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
/* 头文件包含 */
#include "dpe_frw.h"
#include "dpe_hcc.h"
#include "mac_common.h"
#include "dpe_sbuf.h"
#include "dpe_dma_cpy.h"
#include "dpe_wlan_resource.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_FRW_MAIN_C

/* part1 HMAC --> DMAC模块，HOST_DRX事件处理函数注册结构定义 */
frw_event_sub_table_item_stru g_ast_hmac_to_dpe_tx_host_drx[DMAC_TX_HOST_DRX_BUTT] = {
    [DMAC_TX_HOST_DTX] = { .p_tx_adapt_func = frw_hcc_tx_event_to_netbuf }, // device ring TX
    [DMAC_TX_HOST_TO_DPA] = {
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event,
        .p_func = dpe_wlan_xmit_from_wlan },
};

/* HOST CRX子表 */
frw_event_sub_table_item_stru g_ast_hmac_to_dpe_host_crx_table[HMAC_TO_DMAC_SYN_BUTT] = {
    [HMAC_TO_DMAC_SYN_CFG] = { .p_func = dpe_frw_event_config_syn, // hmac_to_dmac_cfg_msg_stru核间通信事件通用接口
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event,
        .p_tx_adapt_func = frw_hcc_tx_event_to_netbuf},
    [DPA_TO_DMAC_SYN_CFG] = { .p_func = NULL,
        .p_tx_adapt_func = frw_hcc_tx_event_to_netbuf},
    [HMAC_TO_DMAC_SYN_CREATE_CFG_VAP] = { .p_func = NULL, // 创建配置vap
        .p_rx_adapt_func = NULL},
    [HMAC_SYN_DPA] = { .p_func = dpe_frw_event_syn_dpa, // hmac同步dpa事件通用接口
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event},
};

/* DMAC模块，WLAN_DTX事件处理函数注册结构定义 */
frw_event_sub_table_item_stru g_ast_hmac_to_dpe_tx_wlan_dtx[DMAC_TX_WLAN_DTX_BUTT] = {
    [DMAC_TX_WLAN_DTX] = { .p_func = NULL } // 已废弃
};

frw_event_sub_table_item_stru g_ast_hmac_to_dpe_wlan_ctx_event_sub_table[DMAC_WLAN_CTX_EVENT_SUB_TYPE_BUTT] = {
    /* 注册DMAC模块WLAN_CTX事件处理函数表 */
    [DMAC_WLAN_CTX_EVENT_SUB_TYPE_ADD_USER] = {
        .p_func = dpe_frw_wlan_user_add, // DPA具体的业务处理函数
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event,  // DPA接收事件适配层
        .p_tx_adapt_func = frw_hcc_tx_event_to_netbuf },  // DPA发送事件适配层
    [DMAC_WLAN_CTX_EVENT_SUB_TYPE_DEL_USER] = {
        .p_func = dpe_frw_wlan_user_del,
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event,
        .p_tx_adapt_func = frw_hcc_tx_event_to_netbuf },
    [DMAC_WLAN_CTX_EVENT_SUB_TYPE_BA_SYNC] = {
        .p_func = dpe_frw_wlan_tid_ba_sync,
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event,
        .p_tx_adapt_func = frw_hcc_tx_event_to_netbuf },
    [DMAC_WLAN_CTX_EVENT_SUB_TYPE_MGMT] = { .p_func = NULL,  // 管理帧发送统一接口
        .p_rx_adapt_func = NULL },
};

/* part2 DMAC --> HMAC模块, WLAN_DRX事件处理函数注册结构定义 */
frw_event_sub_table_item_stru g_ast_dpe_to_hmac_wlan_drx_event_sub_table[DMAC_WLAN_DRX_EVENT_SUB_TYPE_BUTT] = {
    [DMAC_WLAN_DRX_EVENT_SUB_TYPE_WOW_RX_DATA]= {
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event,
        .p_func = hmac_dev_rx_process_data},
    [DMAC_WLAN_DRX_EVENT_SUB_TYPE_RX_DATA_DPA]= {
        .p_tx_adapt_func = frw_hcc_tx_event_to_netbuf },
};

/* HMAC模块 WLAN_CRX事件处理函数注册结构定义 */
frw_event_sub_table_item_stru g_dpe_to_hmac_wlan_crx_event_sub_table[DMAC_WLAN_CRX_EVENT_SUB_TYPE_BUTT] = {
    [DMAC_WLAN_CRX_EVENT_SUB_TYPE_INIT] = { .p_tx_adapt_func = NULL },
    [DMAC_WLAN_CRX_EVENT_SUB_TYPE_RX] = { .p_tx_adapt_func = NULL },
    [DMAC_WLAN_CRX_EVENT_SUB_TYPE_RX_WOW] = { .p_tx_adapt_func = NULL },
    [DMAC_WLAN_CRX_EVENT_SUB_TYPE_DELBA] = { .p_tx_adapt_func = NULL },
    [DMAC_WLAN_CRX_EVENT_SUB_TYPE_DISASSOC] = { .p_tx_adapt_func = NULL },
    [DMAC_WLAN_CRX_EVENT_SUB_TYPE_TX_RING_ADDR] = {
        .p_func = dpe_frw_set_tx_ring_device_base_addr,
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event },
    [DMAC_WLAN_CRX_EVENT_SUB_TYPE_VSP_INFO_ADDR] = { .p_tx_adapt_func = NULL },
    [DMAC_WLAN_CRX_EVENT_SUB_TYPR_DBAC] = {
        .p_func = dpe_frw_dbac_status_notify,
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event,
        .p_tx_adapt_func = frw_hcc_tx_event_to_netbuf },
};

/* HMAC模块 MISC杂散事件处理函数注册结构定义 */
frw_event_sub_table_item_stru g_dpe_to_hmac_wlan_misc_event_sub_table[DMAC_MISC_SUB_TYPE_BUTT] = {
    [DMAC_MISC_SUB_TYPE_DISASOC] = { .p_tx_adapt_func = NULL },
    [DMAC_MISC_SUB_TYPE_TX_SWITCH_STATE] = {
        .p_func = dpe_frw_tx_mode_switch_process,
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event }, /* DPE */
    [DMAC_MISC_PSM_GET_HOST_RING_STATE] = {
        .p_func = dpe_frw_get_host_ring_state,
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event  }, /* DPE */
};
/* HMAC模块 发向HOST侧的配置事件处理函数注册结构定义 */
frw_event_sub_table_item_stru g_dpe_to_hmac_wlan_ctx_event_sub_table[DMAC_TO_HMAC_SYN_BUTT] = {
    [DPA_TO_HMAC_SYN_CFG] = { .p_tx_adapt_func = frw_hcc_tx_event_to_netbuf },
    [DMAC_TO_HMAC_SYN_CFG] = {
        .p_func = dpe_frw_event_config_dmac_d2h_syn,
        .p_rx_adapt_func = frw_hcc_rx_convert_to_event,
        .p_tx_adapt_func = frw_hcc_tx_event_to_netbuf },
};

void event_fsm_table_register(void)
{
    memset_s(g_ast_event_table, sizeof(g_ast_event_table), 0, sizeof(g_ast_event_table));

    /* Part1: 以下是ACPU post向Dmac收的事件 */
    /* 注册DMAC模块HOST_DRX事件处理函数表 */
    frw_event_table_register(FRW_EVENT_TYPE_HOST_DRX, FRW_EVENT_PIPELINE_STAGE_1,
        g_ast_hmac_to_dpe_tx_host_drx);
    /* 注册DMAC模块HOST_CRX事件 */
    frw_event_table_register(FRW_EVENT_TYPE_HOST_CRX, FRW_EVENT_PIPELINE_STAGE_1,
        g_ast_hmac_to_dpe_host_crx_table);
    /* 注册DMAC模块WLAN_DTX事件处理函数表 */
    frw_event_table_register(FRW_EVENT_TYPE_WLAN_DTX, FRW_EVENT_PIPELINE_STAGE_1,
        g_ast_hmac_to_dpe_tx_wlan_dtx);
    /* 注册DMAC模块WLAN_CTX事件处理函数表 */
    frw_event_table_register(FRW_EVENT_TYPE_WLAN_CTX, FRW_EVENT_PIPELINE_STAGE_1,
        g_ast_hmac_to_dpe_wlan_ctx_event_sub_table);

    /* Part2: 以下是WCPU post向Hmac收的事件 */
    /* 注册WLAN_DRX事件子表 */
    frw_event_table_register(FRW_EVENT_TYPE_WLAN_DRX, FRW_EVENT_PIPELINE_STAGE_1,
        g_ast_dpe_to_hmac_wlan_drx_event_sub_table);
    /* 注册WLAN_CRX事件子表 */
    frw_event_table_register(FRW_EVENT_TYPE_WLAN_CRX, FRW_EVENT_PIPELINE_STAGE_1,
        g_dpe_to_hmac_wlan_crx_event_sub_table);
    /* 注册DMAC模块MISC事件字表 */
    frw_event_table_register(FRW_EVENT_TYPE_DMAC_MISC, FRW_EVENT_PIPELINE_STAGE_1,
        g_dpe_to_hmac_wlan_misc_event_sub_table);
    /* 注册统计结果查询事件子表 */
    frw_event_table_register(FRW_EVENT_TYPE_HOST_SDT_REG, FRW_EVENT_PIPELINE_STAGE_1,
        g_dpe_to_hmac_wlan_ctx_event_sub_table);
}

OAL_STATIC void dpe_frw_event_mem_free(dpe_frw_mem_stru *event_mem, uint8_t sbuf_free)
{
    if (sbuf_free == OAL_TRUE) {
        if (event_mem->netbuf) {
            dpe_netbuf_free(event_mem->netbuf);
        } else {
            oam_error_log0(0, OAM_SF_DPA, "{dpe_frw_event_mem_free::netbuf is null!");
        }
    }
    if (event_mem->param.payload != NULL) {
        oal_free(event_mem->param.payload);
    } else {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_frw_event_mem_free::payload is null!");
    }
    event_mem->param.payload = NULL;
    oal_mem_free_m(event_mem, OAL_TRUE);
}
void dpe_frw_list_free(void)
{
    oal_uint lock_flag;
    oal_dlist_head_stru *dlist_entry = NULL;
    oal_dlist_head_stru *dlist_tmp = NULL;
    dpe_frw_mem_stru *event_mem = NULL;

    oal_spin_lock_irq_save(dpe_get_frw_thread_lock(), &lock_flag);
    if (oal_dlist_is_empty(&g_frw_thread.frw_list) == OAL_TRUE) {
        oal_dlist_init_head(&g_frw_thread.frw_list);
        oal_spin_unlock_irq_restore(dpe_get_frw_thread_lock(), &lock_flag);
        return;
    }
    oal_dlist_search_for_each_safe(dlist_entry, dlist_tmp, &g_frw_thread.frw_list) {
        event_mem = (dpe_frw_mem_stru *)oal_dlist_get_entry(dlist_entry, dpe_frw_mem_stru, entry);
        if (event_mem == NULL) {
            oam_error_log0(0, OAM_SF_DPA, "{dpe_frw_event_mem_free::event_mem is null!");
            continue;
        }
        oal_dlist_delete_entry(&event_mem->entry);
        dpe_frw_event_mem_free(event_mem, OAL_TRUE);
    }
    oal_dlist_init_head(&g_frw_thread.frw_list);
    oal_spin_unlock_irq_restore(dpe_get_frw_thread_lock(), &lock_flag);
}

void dpe_frw_event_process(uint32_t recv_event)
{
    oal_dlist_head_stru *dlist_entry = NULL;
    oal_dlist_head_stru *dlist_tmp = NULL;
    dpe_frw_mem_stru *event_mem = NULL;
    frw_event_param_stru *param = NULL;
    oal_netbuf_stru *netbuf = NULL;
    dpe_frw_event_stru *frw_event = NULL;
    oal_uint lock_flag;
    oal_dlist_head_stru temp_list;
    oal_dlist_init_head(&temp_list);

    oal_spin_lock_irq_save(dpe_get_frw_thread_lock(), &lock_flag);
    if (oal_dlist_is_empty(&g_frw_thread.frw_list) != OAL_TRUE) {
        oal_dlist_join_tail(&temp_list, &g_frw_thread.frw_list);
        oal_dlist_init_head(&g_frw_thread.frw_list);
    }
    oal_spin_unlock_irq_restore(dpe_get_frw_thread_lock(), &lock_flag);

    oal_dlist_search_for_each_safe(dlist_entry, dlist_tmp, &temp_list) {
        event_mem = (dpe_frw_mem_stru *)oal_dlist_get_entry(dlist_entry, dpe_frw_mem_stru, entry);
        oal_dlist_delete_entry(&event_mem->entry);
        param = &event_mem->param;
        netbuf = event_mem->netbuf;
        /* 参数校验 */
        if (netbuf == NULL) {
            oam_error_log4(0, OAM_SF_DPA, "dpe_frw_event_process:: type %d subtype %d pipe %d, to %d",
                param->type, param->subtype, param->pipeline, param->transfer_event_to);
            dpe_frw_event_mem_free(event_mem, OAL_FALSE);
            continue;
        }
        /* 1. 事件信息维护在sbuf cb(128 bytes) */
        frw_event = (dpe_frw_event_stru*)oal_sbuf_cb(netbuf);
        frw_event_hdr_init(frw_event, param);
        /* 2. 事件体维护在sbuf payload(1536 bytes), 只包含事件长度 */
        /* 传递非skb需要拷贝信息到新申请的skb中, 后续流程交由skb流转, payload对象由业务负责释放或其他处理 */
        /* DMA在task中同步拷贝 */
        if (dpe_dma_cpy_cache((void *)param->payload, (uint64_t)param->payload,
            oal_netbuf_data(netbuf), param->payload_size, DPE_FRW_EVENT_DMA) != OAL_SUCC) {
            oam_error_log3(0, OAM_SF_DPA, "frw_generate_event_netbuf:: dma cpy fail,len = %d type %d subtype %d",
                param->payload_size, param->type, param->subtype);
            dpe_frw_event_mem_free(event_mem, OAL_TRUE);
            continue;
        }
        /* 设置事件内存长度 */
        oal_netbuf_set_len(netbuf, param->payload_size);

        /* 传递消息 */
        param->netbuf = netbuf;
        if (frw_event_dispatch_event(param) != OAL_SUCC) {
            dpe_netbuf_free(netbuf);
            oam_error_log2(param->vap_id, OAM_SF_DPA, "{frw_post_event::post event[%d][%d] failed!}",
                param->type, param->subtype);
        }
        /* 释放事件内存 */
        dpe_frw_event_mem_free(event_mem, OAL_FALSE);
    }
}

int32_t dpe_frw_thread(void *p_data)
{
    uint32_t recv_event;
    unsigned int ret;
    while (1) {
        recv_event = 0;
        /* event不会溢出, fiber的消息会溢出 */
        ret = mdrv_kevent_recv(g_frw_thread.thread_info.task_event_type,
            OS_EVENT_ANY, OS_EVENT_WAIT_FOREVER, &recv_event);
        if (ret != 0) {
            oam_error_log3(0, OAM_SF_DPA, "dpe_rx_data_thread mdrv_kevent_recv event 0x%x. ret[0x%x], event_type[0x%x]",
                recv_event, ret, g_frw_thread.thread_info.task_event_type);
        }
        if (recv_event != 0) {
            dpe_frw_event_process(recv_event);
        }
    }
    return OAL_SUCC;
}
#endif
