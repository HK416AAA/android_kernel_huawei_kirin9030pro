/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : 事件管理对外接口(对IPC接口、对业务接口)实现
 * 作者       :
 * 创建日期   : 2012年10月12日
 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD

/* 头文件包含 */
#include "securec.h"
#include "dpe_frw.h"
#include "dpe_hcc_if.h"
#include "dpe_dma_cpy.h"
#include "dpe_frw_if.h"
#include "dpe_task.h"
#include "dpe_sbuf.h"
#include "dpe_wlan_debug.h"
#include "dpe_wlan_resource.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_FRW_EVENT_C

/* 事件表全局变量 */
frw_event_table_item_stru g_ast_event_table[FRW_EVENT_TABLE_MAX_ITEMS];

dpe_frw_stru g_frw_thread;  // OAL_PL1_BSS
/*
 * 功能描述  : 注册相应事件对应的事件处理函数
 */
void frw_event_table_register(uint8_t en_type, frw_event_pipeline_enum en_pipeline,
    frw_event_sub_table_item_stru *sub_table)
{
    uint8_t uc_index = (uint8_t)((en_type << 1) | ((uint8_t)en_pipeline & 0x01));

    if (oal_unlikely(sub_table == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "{frw_event_table_register_etc: sub_table is null ptr!}");
        return;
    }

    if (oal_unlikely(uc_index >= FRW_EVENT_TABLE_MAX_ITEMS)) {
        oam_error_log1(0, OAM_SF_DPA, "{frw_event_table_register_etc, array overflow! %d}", uc_index);
        return;
    }

    g_ast_event_table[uc_index].pst_sub_table = sub_table;
}

/* 事件过滤黑名单, 黑名单中的事件流转的SKB为MAA内存, 只记录数据帧事件 */
uint8_t g_event_blacklist[][2] = {
    {FRW_EVENT_TYPE_WLAN_DRX, DMAC_WLAN_DRX_EVENT_SUB_TYPE_WOW_RX_DATA}, /* HMAC->DPA/DMAC->DPA的数据帧事件保持MAA内存 */
    {255, 255}, // invalid event
};
oal_bool_enum_uint8 dpe_frw_event_filter(uint8_t main_type, uint8_t sub_type)
{
    uint16_t list_idx = 0;
    uint16_t list_size = oal_array_size(g_event_blacklist);
    for (list_idx = 0; list_idx < list_size; list_idx++) {
        if (main_type == g_event_blacklist[list_idx][0] &&
            sub_type == g_event_blacklist[list_idx][1]) {
            return OAL_TRUE;
        }
    }
    return OAL_FALSE;
}
void frw_event_skb_free(oal_netbuf_stru *netbuf)
{
    dpe_cb_stru *dpe_cb = NULL;
    netbuf_data_addr addr;

    if (netbuf == NULL) {
        return;
    }
    /* MAA内存都是数据帧，由DPE路径负责释放 */
    dpe_cb = oal_netbuf_dpe_cb(netbuf);
    if (dpe_cb->not_maa_sbuf == 0) {
        return;
    }
    /* 事件内存都是本地内存，统一由FRW负责释放 */
    addr = oal_netbuf_destory(netbuf);
    oal_dma_free_nocache((void *)addr);
}
/* 此接口申请的skb为noncache skb，CPU可访问 */
oal_netbuf_stru *frw_event_skb_generate(oal_netbuf_stru *netbuf, uint8_t main_type, uint8_t sub_type)
{
    oal_netbuf_stru *new_skb = NULL;
    dpe_cb_stru *dpe_cb = NULL;
    uint32_t event_len = oal_netbuf_len(netbuf);
    uint64_t event_src_addr = oal_netbuf_data(netbuf);
    uint64_t event_addr = 0;

    if (dpe_frw_event_filter(main_type, sub_type) == OAL_TRUE) {
        return netbuf;
    }

    event_addr = (uint64_t)oal_dma_alloc_nocache(event_len);
    if (event_addr == (uint64_t)NULL) {
        oam_error_log1(0, OAM_SF_DPA, "frw_event_skb_generate:: event_addr null,len = %d", event_len);
        return NULL;
    }
    /* 构建非MAA内存, 允许CPU访问 */
    new_skb = oal_netbuf_build(event_addr, event_len);
    if (new_skb == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "frw_event_skb_generate:: new_skb null, len = %d", event_len);
        return NULL;
    }
    /* 拷贝256字节CB */
    memcpy_s(oal_sbuf_cb(new_skb), sizeof(dpe_frw_event_stru), oal_sbuf_cb(netbuf), sizeof(dpe_frw_event_stru));

    dpe_cb = oal_netbuf_dpe_cb(new_skb);
    dpe_cb->not_maa_sbuf = 1;

    /* dpe访问payload内容必须通过EICC dma搬运 */
    if (dpe_dma_cpy_noncache(event_src_addr, oal_netbuf_data(new_skb), event_len, DPE_HCC_RX_EVT) != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "frw_event_skb_generate:: dma cpy fail,len = %d", event_len);
        frw_event_skb_free(new_skb);
        return NULL;
    }

    return new_skb;
}

OAL_STATIC uint32_t frw_hcc_event_process(frw_event_table_item_stru *frw_event_table, uint8_t main_type,
    uint8_t sub_type, oal_netbuf_stru *netbuf)
{
    oal_netbuf_stru *netbuf_dpa = NULL;

    /* HCC 收到的event除了DPA处理，还可能转发，需要优先本核处理后转发 */
    /* For hcc post event adapt，hcc与wifi适配层，hcc rx post do */
    if (frw_event_table->pst_sub_table[sub_type].p_rx_adapt_func != NULL) {
        /* rx adapt first */
        if (frw_event_table->pst_sub_table[sub_type].p_rx_adapt_func(netbuf) != OAL_SUCC) {
            oam_error_log2(0, OAM_SF_DPA,
                "{frw_hcc_event_process::tx adapt process failed! type[0x%x][0x%x]}", main_type, sub_type);
        }

        /* call action frame, DPA是否要处理该事件，不处理则不注册 */
        if (frw_event_table->pst_sub_table[sub_type].p_func != NULL) {
            /*  DPA需要处理的事件，需新申请skb转发DPA,DPE负责释放该skb */
            netbuf_dpa = frw_event_skb_generate(netbuf, main_type, sub_type);
            if (netbuf_dpa == netbuf) {
                /* 数据帧, 走业务流程处理, 不释放 */
                frw_event_table->pst_sub_table[sub_type].p_func(netbuf_dpa);
            } else if (netbuf_dpa != NULL) {
                /* DPA处理的事件，原事件不释放 */
                frw_event_table->pst_sub_table[sub_type].p_func(netbuf_dpa);
                frw_event_skb_free(netbuf_dpa);
            } else {
                /* 处理异常，原事件不释放 */
                oam_error_log2(0, OAM_SF_DPA,
                    "{frw_dpe_event_process::pfunc failed! type[0x%x][0x%x]}", main_type, sub_type);
            }
        }
    }

    /* For wifi post event adapt，wifi与hcc适配层，去向hcc tx接口 */
    if (frw_event_table->pst_sub_table[sub_type].p_tx_adapt_func != NULL) {
        if (frw_event_table->pst_sub_table[sub_type].p_tx_adapt_func(netbuf) != OAL_SUCC) {
            oam_error_log2(0, OAM_SF_DPA,
                "{frw_hcc_event_process::tx adapt process failed! type[0x%x][0x%x]}", main_type, sub_type);
            return OAL_FAIL;
        }
        return OAL_SUCC;
    }

    /* 已处理完毕，释放MAA内存 */
    dpe_netbuf_free(netbuf);
    return OAL_SUCC;
}

OAL_STATIC uint32_t frw_dpe_event_process(frw_event_table_item_stru *frw_event_table, uint8_t main_type,
    uint8_t sub_type, oal_netbuf_stru *netbuf)
{
    oal_netbuf_stru *netbuf_dpa = NULL;

    /* WIFI 一般只会单向传输，除了异步事件WIFI抛出并WIFI执行,由pfunc直接执行不需要注册trx adapt接口 */
    /* 场景1：For dpe post event adapt，wifi与hcc适配层，去向hcc tx接口 */
    if (frw_event_table->pst_sub_table[sub_type].p_tx_adapt_func != NULL) {
        if (frw_event_table->pst_sub_table[sub_type].p_tx_adapt_func(netbuf) != OAL_SUCC) {
            oam_error_log2(0, OAM_SF_DPA,
                "{frw_dpe_event_process::tx adapt process failed! type[0x%x][0x%x]}", main_type, sub_type);
            return OAL_FAIL;
        }
        return OAL_SUCC;
    }

    /* 场景2：For dpe receive event adapt，wifi与hcc适配层，去向hcc tx接口 */
    if (frw_event_table->pst_sub_table[sub_type].p_rx_adapt_func != NULL) {
        /* rx adapt first */
        if (frw_event_table->pst_sub_table[sub_type].p_rx_adapt_func(netbuf) != OAL_SUCC) {
            oam_error_log2(0, OAM_SF_DPA,
                "{frw_dpe_event_process::tx adapt process failed! type[0x%x][0x%x]}", main_type, sub_type);
            return OAL_FAIL;
        }
        /* call action frame, DPA是否要处理该事件，不处理则不注册 */
        if (frw_event_table->pst_sub_table[sub_type].p_func == NULL) {
            oam_error_log2(0, OAM_SF_DPA,
                "{frw_dpe_event_process::pfunc null! type[0x%x][0x%x]}", main_type, sub_type);
            return OAL_FAIL;
        }
        /* MAA内存转换为本地内存 */
        netbuf_dpa = frw_event_skb_generate(netbuf, main_type, sub_type);
        if (netbuf_dpa == netbuf) {
            /* 数据帧, 走业务流程处理, 不释放 */
            frw_event_table->pst_sub_table[sub_type].p_func(netbuf_dpa);
        } else if (netbuf_dpa != NULL) {
            /* 已处理完毕，释放MAA内存 */
            dpe_netbuf_free(netbuf);
            frw_event_table->pst_sub_table[sub_type].p_func(netbuf_dpa);
            frw_event_skb_free(netbuf_dpa);
        } else {
            /* 处理异常，释放MAA内存 */
            dpe_netbuf_free(netbuf);
            oam_error_log2(0, OAM_SF_DPA,
                "{frw_dpe_event_process::pfunc failed! type[0x%x][0x%x]}", main_type, sub_type);
        }
    }
    return OAL_SUCC;
}

OAL_STATIC uint32_t frw_pipe_1_event_process(oal_netbuf_stru *netbuf,
    frw_event_table_item_stru *frw_event_table, uint8_t main_type, uint8_t sub_type)
{
    /* 场景1：如果该事件DPE不关心, HCC直接流转 */
    if ((frw_event_table->pst_sub_table[sub_type].p_tx_adapt_func == NULL) &&
        (frw_event_table->pst_sub_table[sub_type].p_rx_adapt_func == NULL)) {
        /* 透传流转, 不动HCC HDR */
        return frw_hcc_tx_netbuf(netbuf);
    }

    /* 场景2：如果该事件需要多核流转，需要拷贝到新的skb实现流转设计 */
    if ((frw_event_table->pst_sub_table[sub_type].p_tx_adapt_func != NULL) &&
        (frw_event_table->pst_sub_table[sub_type].p_rx_adapt_func != NULL)) {
        /* HCC收到的事件才会多核流转 */
        return frw_hcc_event_process(frw_event_table, main_type, sub_type, netbuf);
    }
    /* 场景3：WIFI DPE上抛出的事件或者目的地是DPE的事件 */
    return frw_dpe_event_process(frw_event_table, main_type, sub_type, netbuf);
}
/*
 * 功能描述  : 根据事件类型，子类型以及分段号，找到相应事件处理函数
 */
OAL_STATIC uint32_t frw_event_lookup_process_entry(frw_event_param_stru *event_para)
{
    frw_event_table_item_stru *frw_event_table = NULL;
    uint8_t index_t;
    frw_event_type_enum main_type = event_para->type;
    uint8_t sub_type = event_para->subtype;

    /* 根据事件类型及分段号计算事件表索引 */
    index_t = (uint8_t)((main_type << 1) | (event_para->pipeline & 0x01));
    if (oal_unlikely(index_t >= FRW_EVENT_TABLE_MAX_ITEMS)) {
        oam_error_log3(0, OAM_SF_DPA,
            "{frw_event_lookup_process_entry::array overflow! type[0x%x], sub_type[0x%x], pipeline[0x%x].}",
            main_type, sub_type, event_para->pipeline);
        return OAL_ERR_CODE_ARRAY_OVERFLOW;
    }

    /* 先把全局变量变成局部变量 */
    frw_event_table = &g_ast_event_table[index_t]; /* 与codex检查冲突，屏蔽掉 */
    if (oal_unlikely(frw_event_table->pst_sub_table == NULL)) {
        oam_error_log2(0, OAM_SF_DPA,
            "{frw_event_lookup_process_entry::sub table is NULL! sub_type[0x%x], index[0x%x].}", sub_type, index_t);
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* For pipeline 1 type */
    if (event_para->pipeline != FRW_EVENT_PIPELINE_STAGE_0) {
        return  frw_pipe_1_event_process(event_para->netbuf, frw_event_table, main_type, sub_type);
    }

    /* For pipeline 0 type */
    if (event_para->pipeline == FRW_EVENT_PIPELINE_STAGE_0) {
        if (oal_unlikely(frw_event_table->pst_sub_table[sub_type].p_func == NULL)) {
            oam_error_log2(0, OAM_SF_DPA,
                "{frw_event_lookup_process_entry::sub type is NULL! sub_type[0x%x], index[0x%x].}", sub_type, index_t);
            return OAL_ERR_CODE_PTR_NULL;
        }
        frw_event_table->pst_sub_table[sub_type].p_func(event_para->netbuf);
    }
    return OAL_SUCC;
}
OAL_STATIC uint32_t frw_event_post_event(frw_event_param_stru *event, uint32_t core_id)
{
    oam_error_log2(0, OAM_SF_DPA, "{frw_event_post_event::no pipeline 0 event,sub_type[0x%x], index[0x%x].}",
        event->type, event->subtype);
    return OAL_FAIL;
}
/*
 * 功能描述  : 事件分发接口(分发事件至核间通讯、事件队列、或者查表寻找相应事件处理函数)
 */
uint32_t frw_event_dispatch_event(frw_event_param_stru *event)
{
    /* 如果pipleline为1，根据事件类型，子类型以及分段号，转发相应的事件处理函数 */
    if (event->pipeline == FRW_EVENT_PIPELINE_STAGE_1) {
        return frw_event_lookup_process_entry(event);
    }

    /* 如果pipleline为0，则将事件入队。 */
    return frw_event_post_event(event, 0);
}

void frw_event_hdr_init(dpe_frw_event_stru *frw_event, frw_event_param_stru *param)
{
    frw_event_hdr_stru  *pst_hdr = &frw_event->st_event_hdr;

    pst_hdr->en_type       = param->type;
    pst_hdr->uc_sub_type   = param->subtype;
    pst_hdr->en_pipeline   = param->pipeline;
    pst_hdr->us_length     = param->payload_size;
    pst_hdr->uc_device_id  = param->hal_device_id;
    pst_hdr->uc_vap_id     = param->vap_id;
    pst_hdr->transfer_event_to = param->transfer_event_to;
    pst_hdr->hcc_extend    = param->hcc_extend;
}

OAL_STATIC uint32_t frw_generate_event_netbuf(frw_event_param_stru *param)
{
    dpe_frw_mem_stru *event_mem = NULL;
    oal_netbuf_stru *netbuf = NULL;
    oal_uint lock_flag;

    /* 先申请内存, 申请不到skb则丢弃事件 */
    netbuf = dpe_netbuf_alloc(WLAN_MAX_NETBUF_SIZE, EN_FRW_ALLOC);
    if (netbuf == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "frw_enqueue_event_netbuf:: alloc sbuf failed %d", WLAN_MAX_NETBUF_SIZE);
        dpe_rx_async_debug_show();
        dpe_tx_debug_show();
        return OAL_FAIL;
    }
    /* 申请cache ddr 事件内存 */
    event_mem = oal_mem_alloc_m(OAL_MEM_POOL_ID_LOCAL, sizeof(dpe_frw_mem_stru), OAL_TRUE);
    if (event_mem == NULL) {
        dpe_netbuf_free(netbuf);
        oam_error_log1(0, OAM_SF_DPA,
            "frw_enqueue_event_netbuf:: alloc cache ddr fail,len = %d", sizeof(dpe_frw_mem_stru));
        dpe_rx_async_debug_show();
        return OAL_FAIL;
    }

    memcpy_s(&event_mem->param, sizeof(frw_event_param_stru), param, sizeof(frw_event_param_stru));
    event_mem->netbuf = netbuf;

    oal_spin_lock_irq_save(dpe_get_frw_thread_lock(), &lock_flag);
    oal_dlist_add_tail(&event_mem->entry, &g_frw_thread.frw_list);
    oal_spin_unlock_irq_restore(dpe_get_frw_thread_lock(), &lock_flag);
    /* 抛事件触发线程调度 */
    dpe_sema_up_evt(g_frw_thread.thread_info.task_id, DPE_FRW_THREAD_EVENT);
    return OAL_SUCC;
}

/* WIFI post event总入口 */
uint32_t frw_post_event(frw_event_param_stru *param)
{
    dpe_frw_event_stru *frw_event = NULL;
    if (param == NULL) {
        return OAL_FAIL;
    }
    /* 只支持传递一个事件体 */
    if (param->netbuf != NULL && param->payload != NULL) {
        oam_error_log2(param->vap_id, OAM_SF_DPA, "{frw_post_event::err post evt %d %d!}", param->type, param->subtype);
    }

    /* 需要入队调度frw task进行申请skb并dma拷贝,再给hcc传输 */
    if (param->payload != NULL) {
        return frw_generate_event_netbuf(param);
    }

    if (param->netbuf == NULL) {
        oam_error_log2(param->vap_id, OAM_SF_DPA, "{frw_post_event::err post evt %d %d!}", param->type, param->subtype);
        return OAL_SUCC;
    }
    /* 已有现成的skb则直接交给hcc传输 */
    /* 事件信息维护在sbuf cb(128 bytes) */
    frw_event = (dpe_frw_event_stru*)oal_sbuf_cb(param->netbuf);
    frw_event_hdr_init(frw_event, param);

    if (frw_event_dispatch_event(param) != OAL_SUCC) {
        oam_warning_log2(param->vap_id, OAM_SF_DPA, "{frw_post_event::post event[%d][%d] failed!}",
            param->type, param->subtype);
        return OAL_FAIL;
    }
    return OAL_SUCC;
}
#endif
