/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: hcc_base.c
 * Author: dpa drivers
 */

/* 头文件包含 */
#include <string.h>
#include "bsp_memory.h"
#include "mdrv_mem.h"
#include "mdrv_cache.h"
#include "oal_util.h"
#include "osl_thread.h"
#include "conn_dmi_flowctrl.h"
#include "dpa_exception_rst.h"
#include "hcc_adapter.h"
#include "hcc_comm.h"
#include "oam_logger.h"
#include "hcc_base.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_HCC_BASE_C

#undef THIS_SUB_MODU
#define THIS_SUB_MODU smod_hcc

static hcc_process_handler g_hcc_process_ops = NULL;
static hcc_info_t g_hcc_thread_info;

static hcc_netbuf_queue_type_t g_hcc_queue_to_netbuf_qmap[HCC_QUEUE_COUNT] = {
    [CTRL_QUEUE] = HCC_NETBUF_HIGH_QUEUE,
    [DATA_HI_QUEUE] = HCC_NETBUF_HIGH_QUEUE,
    [DATA_LO_QUEUE] = HCC_NETBUF_NORMAL_QUEUE,
};

hcc_netbuf_queue_type_t hcc_queue_map_to_netbuf_queue(hcc_queue_type_t qtype)
{
    if (qtype >= HCC_QUEUE_COUNT) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_queue_map_to_netbuf_queue qtype is illegal!");
        sys_abort(0);
    }
    return g_hcc_queue_to_netbuf_qmap[qtype];
}

hcc_bus_t *hcc_bus_get_cur_bus(hcc_handler_t *hcc_handler)
{
    hcc_bus_res_t *bus_res = container_of(hcc_handler, hcc_bus_res_t, hcc_handler);
    return bus_res->bus[bus_res->cur_type];
}

hcc_trans_queue *hcc_bus_get_rx_queue(hcc_handler_t *hcc_handler, uint32_t queue_id)
{
    if (hcc_handler == NULL) {
        return NULL;
    }

    return &hcc_handler->hcc_queues[HCC_RX].queues[queue_id];
}

hcc_trans_queue *hcc_bus_get_tx_queue(hcc_handler_t *hcc_handler, uint32_t queue_id)
{
    if (hcc_handler == NULL) {
        return NULL;
    }
    return &hcc_handler->hcc_queues[HCC_TX].queues[queue_id];
}

int32_t hcc_lock_init(hcc_handler_t *hcc)
{
    int32_t ret;
    if (hcc == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_lock_init hcc is null!");
        return -OAL_FAIL;
    }

    ret = oal_mutex_init(&hcc->rx_transfer_lock);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "rx_transfer_lock init fail! 0x%x", ret);
        return -OAL_FAIL;
    }

    ret = oal_mutex_init(&hcc->tx_transfer_lock);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "tx_transfer_lock init fail! 0x%x", ret);
        oal_mutex_free(&hcc->rx_transfer_lock);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

void hcc_lock_deinit(hcc_handler_t *hcc)
{
    if (hcc == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_lock_deinit hcc is null!");
        return;
    }

    oal_mutex_free(&hcc->tx_transfer_lock);
    oal_mutex_free(&hcc->rx_transfer_lock);
}

void hcc_hdr_param_init(hcc_transfer_param_t *param, uint32_t main_type, uint32_t sub_type,
                        uint32_t extend_len, uint32_t fc_flag, uint32_t queue_id)
{
    if (param == NULL) {
        sys_abort(0);
        return;
    }
    param->main_type = main_type;
    param->sub_type = sub_type;
    param->extend_len = extend_len;
    param->fc_flag = fc_flag;
    param->queue_id = queue_id;
}

void hcc_build_header(hcc_handler_t *hcc_handler, oal_netbuf_stru *netbuf,
                      uint16_t pay_load_len, hcc_transfer_param_t *param)
{
    hcc_header_t *hcc_hdr;

    /* build hcc header */
    hcc_hdr = (hcc_header_t *)oal_sbuf_cb(netbuf);
    hcc_hdr->main_type   = (uint8_t)param->main_type;
    hcc_hdr->sub_type    = (uint8_t)param->sub_type;
    hcc_hdr->pay_len     = pay_load_len;
    hcc_hdr->seq         = (uint8_t)hcc_handler->pkt_index++;

    /* Device alloc netbuf's payload all 4B aligned! */
    hcc_hdr->pad_payload = 0;

    if (pay_load_len > HCC_LONG_PACKAGE_SIZE) {
        sys_abort(0); // hcc有效荷载长度大于封装大小，进行异常恢复
    }

    oal_bug_on(param->extend_len > HCC_HDR_RESERVED_MAX_LEN);
    hcc_hdr->pad_hdr = (uint8_t)(HCC_HDR_RESERVED_MAX_LEN - param->extend_len);
}

/*
 * 函 数 名  : hcc_netbuf_alloc
 * 功能描述  : 申请netbuf以及 maa内存空间
 * 输入参数  : maa空间大小, dpa上约束最大位1536Byte
 *            由于长度不满足，需要使用tailrom 后段24字节空间
 */
oal_netbuf_stru *hcc_netbuf_alloc(uint32_t size)
{
    oal_netbuf_stru *netbuf = NULL;
    uint32_t alloc_size = size > OAL_SBUF_DATA_MAX_LEN ? OAL_SBUF_DATA_MAX_LEN : size;
    netbuf = oal_netbuf_alloc(alloc_size);
    if (netbuf == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc sbuf alloc fail!");
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
        dpe_rx_async_debug_show(); // 内存申请失败的维测，问题定位后删除
        dpe_tx_debug_show();
#endif
        return NULL;
    }

    // cb字段初始化为随机值，此处先清零，避免残留数据对包头有影响
    memset_s(oal_sbuf_cb(netbuf), OAL_SBUF_CB_MAX_LEN, 0, OAL_SBUF_CB_MAX_LEN);
    mdrv_cache_flush(MDRV_DATA_CACHE, (void *)oal_sbuf_cb(netbuf), HCC_HDR_TOTAL_LEN);

    // 使用sbuf 末尾内存补充payload大小
    oal_netbuf_put(netbuf, size - alloc_size);

    if (oal_netbuf_len(netbuf) != size) {
        oam_error_log0(0, OAM_SF_DPA, "hcc sbuf large data len fail!");
        oal_netbuf_free(netbuf);
        return NULL;
    }

    return netbuf;
}

/*
 * 函 数 名  : hcc_netbuf_build
 * 功能描述  : 根据maa地址，生成sbuf结构体
 * 输入参数  : maa空间大小, dpa上约束最大位1536Byte
 *            由于长度不满足，需要使用tailrom 后段24字节空间
 */
oal_netbuf_stru *hcc_netbuf_build(netbuf_data_addr payload_addr, uint32_t payload_len)
{
    oal_netbuf_stru *netbuf = NULL;
    uint32_t payload_build_len;
    uint32_t tail_len = 0;

    if (payload_addr == 0 || payload_len == 0 || payload_len > HCC_LONG_PACKAGE_SIZE) {
        oam_error_log2(0, OAM_SF_DPA, "param invalid addr %u, len %u!", (uint32_t)payload_addr, payload_len);
        return NULL;
    }

    if (payload_len > OAL_SBUF_DATA_MAX_LEN) {
        payload_build_len = OAL_SBUF_DATA_MAX_LEN;
        tail_len = (payload_len - OAL_SBUF_DATA_MAX_LEN);
    } else {
        payload_build_len = payload_len;
    }

    // 先按照最大长度申请
    netbuf = oal_netbuf_build(payload_addr, payload_build_len);
    if (netbuf == NULL) {
        oam_warning_log0(0, OAM_SF_DPA, "netbuf build fail");
        return NULL;
    }

    // cb字段初始化为随机值，此处先清零，避免残留数据对包头有影响
    memset_s(oal_sbuf_cb(netbuf), OAL_SBUF_CB_MAX_LEN, 0, OAL_SBUF_CB_MAX_LEN);
    mdrv_cache_flush(MDRV_DATA_CACHE, (void *)oal_sbuf_cb(netbuf), HCC_HDR_TOTAL_LEN);

    // 如果长度不足，从包尾分配
    if (tail_len > 0) {
        oal_netbuf_put(netbuf, tail_len);
    }

    return netbuf;
}

void hcc_netbuf_free(oal_netbuf_stru *netbuf)
{
    if (netbuf == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_netbuf_free nutbuf is null");
        return;
    }
#ifdef _PRE_WLAN_DPE_DEBUG
    if (get_sbuf_next(netbuf) != NULL) {
        sys_abort(1);
    }
#endif
    oal_netbuf_free(netbuf);
}

void hcc_rx(hcc_handler_t *hcc_handler, oal_netbuf_stru *netbuf, uint32_t queue_id)
{
    hcc_trans_queue *hcc_queues = NULL;
    if (hcc_handler == NULL || netbuf == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_handler or netbuf is null!");
        return;
    }

    hcc_queues = hcc_bus_get_rx_queue(hcc_handler, queue_id);
    hcc_netbuf_addlist_tail_with_flowctrl(&hcc_queues->data_queue, netbuf);
}

void hcc_change_state(hcc_handler_t *hcc_handler, int32_t state)
{
    int32_t old_state, new_state;
    if (hcc_handler == NULL) {
        return;
    }

    old_state = hcc_handler->state;
    hcc_handler->state = state;
    new_state = hcc_handler->state;
    if (old_state != new_state) {
        oam_warning_log2(0, OAM_SF_DPA, "hcc state [%d]=>[%d]", old_state, new_state);
    }
}

static int32_t hcc_tx_para_check(const hcc_handler_t *hcc_handler, const oal_netbuf_stru *netbuf,
                                 const hcc_transfer_param_t *param)
{
    if (hcc_handler == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_handler is null!");
        return -OAL_EINVAL;
    }

    if (netbuf == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "netbuf is null!");
        return -OAL_EINVAL;
    }

    if (param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "param is null!");
        return -OAL_EINVAL;
    }

    return OAL_SUCC;
}

static int32_t hcc_tx_cond_check(const hcc_handler_t *hcc_handler)
{
    if (hcc_handler->state != HCC_ON) {
        if (hcc_handler->state == HCC_OFF) {
            return -OAL_EBUSY;
        } else if (hcc_handler->state == HCC_EXCEPTION) {
            return -OAL_EIO;
        } else {
            oam_error_log1(0, OAM_SF_DPA, "invaild hcc state:%d", hcc_handler->state);
            return -OAL_EINVAL;
        }
    }
    return OAL_SUCC;
}

static int32_t hcc_tx_flowctrl_process(hcc_handler_t *hcc_handler, hcc_trans_queue *hcc_queue,
                                       oal_netbuf_stru *netbuf, hcc_transfer_param_t *param)
{
    /* flowctrl: 1. sched thread fc pause 2.interrupt  3. drop package */
    if ((param->fc_flag & HCC_FC_WAIT) == HCC_FC_WAIT && (mdrv_is_int_context() == 1)) {
        /* when in interrupt,can't sched! */
        param->fc_flag &= ~HCC_FC_WAIT;
    }

    if (param->fc_flag != HCC_FC_NONE) {
        /* Block if fc */
        if ((HCC_FC_WAIT & param->fc_flag) == HCC_FC_WAIT) {
            // TODO 超过水线信号量等待
        }

        /* control net layer if fc */
        if ((HCC_FC_NET & param->fc_flag) == HCC_FC_NET) {
            // TODO 网络层流控
        }

        /* control net layer if fc */
        if ((HCC_FC_DROP & param->fc_flag) == HCC_FC_DROP) {
            if (oal_netbuf_list_len(&hcc_queue->data_queue) >
                hcc_queue->flow_ctrl.high_waterline + HCC_QUEUE_FC_HIGH_WATER_DROP_LINE) {
                hcc_queue->loss_pkts++;
                /* drop the netbuf */
                return -OAL_EBUSY;
            }
        }
    }

    return OAL_SUCC;
}

/* 清除netbuf的prev和next指针 */
static inline void hcc_netbuf_unlink(oal_netbuf_stru *netbuf)
{
    set_sbuf_next(netbuf, NULL);
    set_sbuf_prev(netbuf, NULL);
}

int32_t hcc_tx(hcc_handler_t *hcc_handler, oal_netbuf_stru *netbuf,
               uint16_t pay_load_len, hcc_transfer_param_t *param)
{
    int32_t ret;
    hcc_trans_queue *hcc_queues = NULL;
    if (hcc_tx_para_check(hcc_handler, netbuf, param) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    if (hcc_tx_cond_check(hcc_handler) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    hcc_queues = hcc_bus_get_tx_queue(hcc_handler, param->queue_id);
    ret = hcc_tx_flowctrl_process(hcc_handler, hcc_queues, netbuf, param);
    if (ret != OAL_SUCC) {
        if (ret == -OAL_EBUSY) {
            hcc_netbuf_unlink(netbuf);
            oal_netbuf_free(netbuf);
            return OAL_SUCC;
        } else {
            // TODO 此处UT未覆盖, hcc_tx_flowctrl_process流控适配后补充UT
            return ret;
        }
    }

    hcc_build_header(hcc_handler, netbuf, pay_load_len, param);
    hcc_netbuf_addlist_tail_with_flowctrl(&hcc_queues->data_queue, netbuf);
    return OAL_SUCC;
}

int32_t hcc_rx_register(hcc_handler_t *hcc_handler, uint8_t mtype, hcc_rx_post_do post_do, hcc_rx_pre_do pre_do)
{
    hcc_rx_action *rx_action = NULL;
    if (hcc_handler == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "Invalid params hcc_handler null");
        return -OAL_FAIL;
    }

    if (mtype >= HCC_ACTION_TYPE_BUTT) {
        oam_error_log1(0, OAM_SF_DPA, "Invalid params:main type = %u", mtype);
        return -OAL_FAIL;
    }

    rx_action = &hcc_handler->rx_action[mtype];

    rx_action->post_do = post_do;
    rx_action->pre_do = pre_do;

    return OAL_SUCC;
}

int32_t hcc_rx_unregister(hcc_handler_t *hcc_handler, uint8_t mtype)
{
    hcc_rx_action *rx_action = NULL;
    if (hcc_handler == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "Invalid params hcc_handler null");
        return -OAL_FAIL;
    }

    if (mtype >= HCC_ACTION_TYPE_BUTT) {
        oam_error_log1(0, OAM_SF_DPA, "Invalid params:main type = %u", mtype);
        return -OAL_FAIL;
    }

    rx_action = &(hcc_handler->rx_action[mtype]);
    memset_s((void *)rx_action, sizeof(hcc_rx_action), 0, sizeof(hcc_rx_action));
    return OAL_SUCC;
}

static int32_t hcc_check_header_vaild(const hcc_header_t *hdr)
{
    if (unlikely(hdr->main_type >= HCC_ACTION_TYPE_BUTT) ||
        (HCC_HDR_LEN + hdr->pad_hdr + hdr->pad_payload > HCC_HDR_TOTAL_LEN)) {
        return -OAL_FAIL;
    }
    return OAL_SUCC;
}

static void hcc_netbuf_restore(oal_netbuf_head_stru *data_head, oal_netbuf_head_stru *ready_head, uint32_t netbuf_num)
{
    uint32_t i = 0;
    oal_netbuf_stru *netbuf = NULL;
    for (i = 0; i < netbuf_num; i++) {
        netbuf = hcc_netbuf_delist_tail_with_flowctrl(ready_head);
        hcc_netbuf_addlist_head_with_flowctrl(data_head, netbuf);
    }
}

static int hcc_dma_cbk(dma_chn chn, void *arg)
{
    hcc_trans_queue *hcc_queue = NULL;
    if (arg == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "arg NULL");
        return -OAL_FAIL;
    }
    hcc_queue = (hcc_trans_queue *)arg;
    // 若搬运失败，ready队列尾部出队，加到data队列头部
    if (mdrv_sem_up(hcc_queue->queue_sem) != OAL_SUCC) {
        return -OAL_FAIL;
    }
    return OAL_SUCC;
}

int32_t hcc_dma_memcpy_submit_sync(completed_handler *dma_hdl, peerlist *peers, mdrv_sem_id sem_id, uint32_t trans_cnt)
{
    int32_t ret;

    ret = bsp_dma_memcpy_submit_async(peers, trans_cnt, dma_hdl);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "bsp_dma_memcpy_submit_async failed: 0x%x!", ret);
        return -OAL_FAIL;
    }

    ret = (int32_t)mdrv_sem_down(sem_id, OS_WAIT_FOREVER);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "mdrv_sem_down failed: 0x%x!", ret);
        return -OAL_FAIL;
    }
    return OAL_SUCC;
}

static inline void hcc_peerlist_build(peerlist *peers, uint64_t src, uint64_t dst, uint32_t len)
{
    memset_s(peers, sizeof(peerlist), 0, sizeof(peerlist));
    peers->src = src;
    peers->dst = dst;
    peers->len = len;
}

void hcc_tx_get_netbuf_header(hcc_handler_t *hcc_handler, uint32_t queue_id)
{
    int32_t ret;
    uint32_t loop;
    oal_netbuf_head_stru *data_head = NULL;
    oal_netbuf_head_stru *ready_head = NULL;
    hcc_trans_queue *hcc_queue = NULL;
    oal_netbuf_stru *netbuf = NULL;
    completed_handler dma_hdl;
    peerlist *peers = NULL;
    uint8_t *header_temp = NULL;

    if (hcc_handler == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_tx_get_netbuf_header hcc_handler is null");
        return;
    }
    hcc_queue = hcc_bus_get_tx_queue(hcc_handler, queue_id);
    data_head = &hcc_queue->data_queue;
    ready_head = &hcc_queue->ready_queue;
    if (oal_netbuf_list_len(data_head) == 0) {
        return;
    }

    dma_hdl.args = (void *)hcc_queue;
    dma_hdl.dma_cbk = hcc_dma_cbk;
    peers = hcc_handler->hcc_queues[HCC_TX].peers;
    header_temp = (uint8_t *)mdrv_mem_alloc(HCC_HDR_TOTAL_LEN, MEM_UNCACHE | MDRV_MEM_ALIGN_004);
    if (header_temp == NULL) {
        return;
    }

    for (loop = 0; loop < hcc_handler->hcc_queues[HCC_TX].peers_num; loop++) { // 限制最大循环次数，防止其他流程饿死
        if (oal_netbuf_list_len(data_head) == 0) {
            break;
        }

        netbuf = hcc_netbuf_delist_head_with_flowctrl(data_head);
        if (netbuf == NULL) {
            oam_error_log0(0, OAM_SF_DPA, "rx netbuf underflow");
            break;
        }
        memcpy_s(header_temp, HCC_HDR_TOTAL_LEN, oal_sbuf_cb(netbuf), HCC_HDR_TOTAL_LEN);
        hcc_peerlist_build(peers, (uint64_t)(uintptr_t)header_temp, oal_netbuf_hcc_header(netbuf), HCC_HDR_TOTAL_LEN);
        hcc_netbuf_addlist_tail_with_flowctrl(ready_head, netbuf);

        ret = hcc_dma_memcpy_submit_sync(&dma_hdl, peers, hcc_queue->queue_sem, 1);
        if (ret != OAL_SUCC) {
            oam_error_log1(0, OAM_SF_DPA, "hcc_dma_memcpy_submit_sync failed: 0x%x!", ret);
            hcc_netbuf_restore(data_head, ready_head, 1);
            break;
        }
    }
    mdrv_free(header_temp);
}

void hcc_rx_get_netbuf_header(hcc_handler_t *hcc_handler, uint32_t queue_id)
{
    int ret;
    uint32_t loop;
    oal_netbuf_head_stru *data_head = NULL;
    oal_netbuf_head_stru *ready_head = NULL;
    hcc_trans_queue *hcc_queue = NULL;
    oal_netbuf_stru *netbuf = NULL;
    completed_handler dma_hdl;
    peerlist *peers = NULL;
    uint8_t *header_temp = NULL;

    if (hcc_handler == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_rx_get_netbuf_header hcc_handler is null");
        return;
    }
    hcc_queue = hcc_bus_get_rx_queue(hcc_handler, queue_id);
    data_head = &hcc_queue->data_queue;
    ready_head = &hcc_queue->ready_queue;
    if (oal_netbuf_list_len(data_head) == 0) {
        return;
    }

    dma_hdl.args = (void *)hcc_queue;
    dma_hdl.dma_cbk = hcc_dma_cbk;
    peers = hcc_handler->hcc_queues[HCC_RX].peers;
    header_temp = (uint8_t *)mdrv_mem_alloc(HCC_HDR_TOTAL_LEN, MEM_UNCACHE | MDRV_MEM_ALIGN_004);
    if (header_temp == NULL) {
        return;
    }

    for (loop = 0; loop < hcc_handler->hcc_queues[HCC_RX].peers_num; loop++) { // 限制最大循环次数，防止其他流程饿死
        if (oal_netbuf_list_len(data_head) == 0) {
            break;
        }

        memset_s(peers, sizeof(peerlist), 0, sizeof(peerlist));
        netbuf = hcc_netbuf_delist_head_with_flowctrl(data_head);
        if (netbuf == NULL) {
            oam_error_log0(0, OAM_SF_DPA, "rx netbuf underflow");
            break;
        }
        hcc_peerlist_build(peers, oal_netbuf_hcc_header(netbuf), (uint64_t)(uintptr_t)header_temp, HCC_HDR_TOTAL_LEN);
        hcc_netbuf_addlist_tail_with_flowctrl(ready_head, netbuf);

        ret = hcc_dma_memcpy_submit_sync(&dma_hdl, peers, hcc_queue->queue_sem, 1);
        if (ret != OAL_SUCC) {
            oam_error_log1(0, OAM_SF_DPA, "hcc_dma_memcpy_submit_sync failed: 0x%x!", ret);
            hcc_netbuf_restore(data_head, ready_head, 1);
            break;
        }

        memcpy_s(oal_sbuf_cb(netbuf), HCC_HDR_TOTAL_LEN, header_temp, HCC_HDR_TOTAL_LEN);
    }
    mdrv_free(header_temp);
}

static void hcc_rx_netbuf_trim(oal_netbuf_stru *netbuf, uint32_t pay_len)
{
    uint32_t buf_len = oal_netbuf_len(netbuf);
    if (pay_len > buf_len) {
        oam_error_log2(0, OAM_SF_DPA, "hcc rx pay len %u, buf len %u, invalid", pay_len, buf_len);
        sys_abort(0);
    }

    oal_netbuf_trim(netbuf, pay_len);
}

static int32_t hcc_bus_rx_sched_pre_post_do(hcc_handler_t *hcc_handler, oal_netbuf_head_stru *rx_head)
{
    int32_t ret = OAL_SUCC;
    uint8_t *pre_context = NULL;
    hcc_rx_action *rx_action = NULL;
    oal_netbuf_stru *netbuf = NULL;
    hcc_header_t *hcc_head = NULL;
    netbuf = hcc_netbuf_delist_head_with_flowctrl(rx_head);
    if (netbuf == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "netbuf is null, list cnt %d", oal_netbuf_list_len(rx_head));
        return -OAL_FAIL;
    }

    hcc_head = (hcc_header_t *)oal_sbuf_cb(netbuf);
    if (unlikely(hcc_check_header_vaild(hcc_head) != OAL_SUCC)) { // 包头非法本包丢弃, 继续执行
        oam_error_log0(0, OAM_SF_DPA, "hcc_check_header_vaild ");
        oal_netbuf_free(netbuf);
        return OAL_SUCC;
    }

    hcc_rx_netbuf_trim(netbuf, hcc_head->pay_len);
    rx_action = &(hcc_handler->rx_action[hcc_head->main_type]);
    if (rx_action->pre_do != NULL) {
        ret = rx_action->pre_do(hcc_head->sub_type, netbuf, &pre_context);
    }

    if (ret != OAL_SUCC) {
        hcc_netbuf_addlist_head_with_flowctrl(rx_head, netbuf); // pre_do 失败，netbuf重新加至队列头
        oam_error_log1(0, OAM_SF_DPA, "pre_do failed: 0x%x!", ret);
        return ret;
    }

    if (rx_action->post_do != NULL) {
        if (rx_action->post_do(hcc_head->sub_type, netbuf, pre_context) != OAL_SUCC) {
            oam_error_log0(0, OAM_SF_DPA, "post_do fail");
        }
    } else {
        oam_error_log2(0, OAM_SF_DPA, "mtype:%d cb is null len:%d", hcc_head->main_type, hcc_head->pay_len);
        oal_netbuf_free(netbuf);
    }
    return OAL_SUCC;
}

int32_t hcc_bus_rx_queue_sched(hcc_handler_t *hcc_handler, oal_netbuf_head_stru *rx_head, uint32_t queue_id)
{
    int32_t count = 0;
    int32_t ret;
    hcc_trans_queue *hcc_queue = hcc_bus_get_rx_queue(hcc_handler, queue_id);
    if (hcc_handler == NULL || rx_head == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_handler or rx_head is empty ");
        return 0;
    }

    if (oal_netbuf_list_len(rx_head) == 0) {
        return 0;
    }

    for (;;) {
        if (count >= FRW_EVENT_HCC_BURST_COUNT) {
            break;
        }

        if (oal_netbuf_list_len(rx_head) == 0) {
            break;
        }

        ret = hcc_bus_rx_sched_pre_post_do(hcc_handler, rx_head);
        if (ret != OAL_SUCC) {
            break;
        }
        count++;
        hcc_queue->total_pkts++;
    }
    hcc_handler->rx_assem_info.pkt_cnt += (uint64_t)count;
    return count;
}

int32_t hcc_bus_tx_queue_sched(hcc_handler_t *hcc_handler, oal_netbuf_head_stru *tx_head, uint32_t queue_id)
{
    int32_t count;
    uint32_t qtype = hcc_queue_map_to_netbuf_queue(queue_id);
    hcc_trans_queue *hcc_queue = NULL;
    hcc_bus_t *bus = NULL;
    if (hcc_handler == NULL || tx_head == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_handler or tx_head is empty ");
        return 0;
    }

    if (oal_netbuf_list_len(tx_head) == 0) {
        return 0;
    }

    bus = hcc_bus_get_cur_bus(hcc_handler);
    if (unlikely(bus == NULL)) {
        return 0;
    }

    if (bus->ops != NULL && bus->ops->tx_queue_sched != NULL) {
        count = bus->ops->tx_queue_sched(bus, tx_head, qtype);
        if (count < 0) {
            oam_error_log0(0, OAM_SF_DPA, "tx_queue_sched fail ");
            return 0;
        } else {
            hcc_queue = hcc_bus_get_tx_queue(hcc_handler, queue_id);
            hcc_queue->total_pkts += (uint32_t)count;
            hcc_handler->tx_assem_info.pkt_cnt += (uint64_t)count;
            return count;
        }
    }
    return 0;
}

int32_t hcc_bus_sleep_request_host(hcc_handler_t *hcc_handler)
{
    hcc_bus_t *bus = NULL;
    if (hcc_handler == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_handler is empty ");
        return -OAL_FAIL;
    }

    bus = hcc_bus_get_cur_bus(hcc_handler);
    if (unlikely(bus == NULL)) {
        return -OAL_FAIL;
    }

    if (bus->ops == NULL || bus->ops->sleep_request_host == NULL) {
        return -OAL_FAIL;
    }

    return bus->ops->sleep_request_host(bus);
}

int32_t hcc_bus_power_action(hcc_handler_t *hcc_handler, hcc_bus_power_action_type action)
{
    hcc_bus_t *bus = NULL;
    if (hcc_handler == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_handler is empty ");
        return -OAL_FAIL;
    }

    bus = hcc_bus_get_cur_bus(hcc_handler);
    if (unlikely(bus == NULL)) {
        return -OAL_FAIL;
    }

    if (bus->ops == NULL || bus->ops->power_action == NULL) {
        return -OAL_FAIL;
    }

    return bus->ops->power_action(bus, action);
}

void hcc_set_thread_func(hcc_process_handler func)
{
    g_hcc_process_ops = func;
}

uint32_t hcc_thread_should_stop(void)
{
    return g_hcc_thread_info.running_flag;
}

void hcc_thread_stop(void)
{
    g_hcc_thread_info.running_flag = 1;
}

static int32_t hcc_thread_process(void *param)
{
    uint32_t recv_event;
    uint32_t current_thread_flag = OAL_FALSE;
    int32_t ret = 0;
    oam_warning_log0(0, OAM_SF_DPA, "hcc_thread_process enter ");
    while (hcc_thread_should_stop() == 0) {
        recv_event = 0;
        mdrv_kevent_recv(~(g_hcc_thread_info.event_type), HCC_EVENT_MODE, OS_EVENT_WAIT_FOREVER, &recv_event);
        if ((current_thread_flag == OAL_FALSE) && ((recv_event & ~g_hcc_thread_info.open_event) != 0)) {
            oam_warning_log1(0, OAM_SF_DPA, "thread close recv_event 0x%x", recv_event);
        }

        if ((recv_event & g_hcc_thread_info.open_event) == g_hcc_thread_info.open_event) {
            current_thread_flag = OAL_TRUE;
            mdrv_sem_up(g_hcc_thread_info.run_sem);
        } else if ((recv_event & g_hcc_thread_info.close_event) == g_hcc_thread_info.close_event) {
            current_thread_flag = OAL_FALSE;
            mdrv_sem_up(g_hcc_thread_info.run_sem);
        }

        if ((recv_event & g_hcc_thread_info.dfr_event) == g_hcc_thread_info.dfr_event) {
            hcc_exception(); // 修改状态, 清理资源
            dpa_exception_handler(g_hcc_thread_info.excep_id);
        }

        if ((current_thread_flag == OAL_TRUE) && (g_hcc_process_ops != NULL)) {
            ret = g_hcc_process_ops(recv_event);
            if (ret == 0) {
                oam_info_log0(0, OAM_SF_DPA, "thread loop no data");
            }
        }
    }

    return OAL_SUCC;
}

void hcc_thread_open(void)
{
    int32_t ret;
    hcc_sched_transfer(g_hcc_thread_info.open_event);
    ret = (int32_t)mdrv_sem_down(g_hcc_thread_info.run_sem, OS_WAIT_FOREVER);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "hcc_thread_open mdrv_sem_down failed: 0x%x!", ret);
    }
}

void hcc_thread_close(void)
{
    int32_t ret;
    hcc_sched_transfer(g_hcc_thread_info.close_event);
    ret = (int32_t)mdrv_sem_down(g_hcc_thread_info.run_sem, OS_WAIT_FOREVER);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "hcc_thread_close mdrv_sem_down failed: 0x%x!", ret);
    }
}

void hcc_thread_event_relasese(uint32_t event)
{
    g_hcc_thread_info.event_type |= event; // 使用过的event bit置1
}

int32_t hcc_thread_event_acquire(uint32_t *event)
{
    uint8_t event_bit = 0;
    if (g_hcc_thread_info.event_type == 0) {
        return -OAL_FAIL;
    }

    event_bit = oal_bit_find_first_bit_four_byte(g_hcc_thread_info.event_type);
    g_hcc_thread_info.event_type &= ~BIT(event_bit); // 获取的event bit置0

    *event = BIT(event_bit);
    return OAL_SUCC;
}

void hcc_sched_transfer(uint32_t event)
{
    mdrv_kevent_send(g_hcc_thread_info.task_id, event);
}

static int32_t hcc_thread_create(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    int32_t ret;

    g_hcc_thread_info.stack_addr = mdrv_mem_alloc(HCC_THREAD_SIZE, MEM_CACHE | MDRV_MEM_ALIGN_016);
    if (g_hcc_thread_info.stack_addr == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_thread_create stack mem alloc fail");
        return -OAL_FAIL;
    }

    task_attr.type = THRD_TASK;
    task_attr.prio = OS_TSK_PRIORITY_00;
    task_attr.stackSize = HCC_THREAD_SIZE;
    task_attr.stackAddr = (uintptr_t)g_hcc_thread_info.stack_addr;
    task_attr.queNum = 1;
    task_attr.args[0] = 0;
    task_attr.entryFunc = hcc_thread_process,
    ret = (int32_t)osl_task_create("hisi_hcc", &task_attr, 1, &g_hcc_thread_info.task_id);
    if (ret != OAL_SUCC) {
        mdrv_free(g_hcc_thread_info.stack_addr);
        oam_error_log1(0, OAM_SF_DPA, "osl_task_create hisi_hcc fail, ret = 0x%x", ret);
        return -OAL_FAIL;
    }
    ret = mdrv_task_core_bind(g_hcc_thread_info.task_id, 0x2);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "mdrv_task_core_bind hisi_hcc, ret = 0x%x", ret);
    }

    dpa_exception_register((uint8_t *)&g_hcc_thread_info.excep_id, g_hcc_thread_info.task_id,
                           g_hcc_thread_info.dfr_event);
    g_hcc_thread_info.running_flag = 0;
    return OAL_SUCC;
}

void hcc_thread_destory(void)
{
    uint32_t ret;

    ret = mdrv_task_delete(g_hcc_thread_info.task_id);
    if (ret) {
        oam_error_log1(0, OAM_SF_DPA, "mdrv_task_delete hisi_oam fail, ret = 0x%x", ret);
    }
    mdrv_free(g_hcc_thread_info.stack_addr);
}

int32_t hcc_handler_queues_init(hcc_handler_t *hcc_handler)
{
    int32_t i, j;
    if (hcc_handler == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_handler is null");
        return -OAL_FAIL;
    }

    for (i = 0; i < HCC_DIR_COUNT; i++) {
        for (j = 0; j < HCC_QUEUE_COUNT; j++) {
            oal_netbuf_list_head_init(&hcc_handler->hcc_queues[i].queues[j].data_queue);
            oal_netbuf_list_head_init(&hcc_handler->hcc_queues[i].queues[j].ready_queue);

            if (mdrv_bsem_init(OS_SEM_EMPTY, SEM_MODE_PRIOR, &hcc_handler->hcc_queues[i].queues[j].queue_sem) !=
                OAL_SUCC) {
                oam_error_log0(0, OAM_SF_DPA, "mdrv_bsem_init queue_sem fail");
                return -OAL_FAIL;
            }
        }
        hcc_handler->hcc_queues[i].peers_num = HCC_MAX_PEERS_NUM;
        hcc_handler->hcc_queues[i].peers = (peerlist *)mdrv_mem_alloc(sizeof(peerlist), MDRV_MEM_ALIGN_004);
        if (hcc_handler->hcc_queues[i].peers == NULL) {
            oam_error_log0(0, OAM_SF_DPA, "hcc_handler->peers alloc fail");
            mdrv_sem_delete(hcc_handler->hcc_queues[i].queues[j].queue_sem);
            return -OAL_FAIL;
        }

        if (memset_s(hcc_handler->hcc_queues[i].peers, sizeof(peerlist), 0, sizeof(peerlist)) != OAL_SUCC) {
            oam_error_log0(0, OAM_SF_DPA, "peers memset fail");
            return -OAL_FAIL;
        }
    }
    return OAL_SUCC;
}

void hcc_handler_queues_clear(hcc_handler_t *hcc_handler)
{
    int32_t i, j;
    if (hcc_handler == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_handler is null");
        return;
    }

    for (i = 0; i < HCC_DIR_COUNT; i++) {
        for (j = 0; j < HCC_QUEUE_COUNT; j++) {
            hcc_netbuf_clear_list_with_flowctrl(&hcc_handler->hcc_queues[i].queues[j].data_queue);
            hcc_netbuf_clear_list_with_flowctrl(&hcc_handler->hcc_queues[i].queues[j].ready_queue);
        }
    }
}

void hcc_handler_queues_deinit(hcc_handler_t *hcc_handler)
{
    int32_t i, j;
    if (hcc_handler == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_handler is null");
        return;
    }

    for (i = 0; i < HCC_DIR_COUNT; i++) {
        if (hcc_handler->hcc_queues[i].peers != NULL) {
            if (mdrv_free(hcc_handler->hcc_queues[i].peers) != OAL_SUCC) {
                oam_error_log0(0, OAM_SF_DPA, "mdrv_free hcc peers fail");
            }
        }

        for (j = 0; j < HCC_QUEUE_COUNT; j++) {
            if (mdrv_sem_delete(hcc_handler->hcc_queues[i].queues[j].queue_sem) != OAL_SUCC) {
                oam_error_log0(0, OAM_SF_DPA, "mdrv_bsem_init mdrv_sem_delete fail");
            }
            hcc_netbuf_clear_list_with_flowctrl(&hcc_handler->hcc_queues[i].queues[j].data_queue);
            oal_netbuf_list_head_deinit(&hcc_handler->hcc_queues[i].queues[j].data_queue);
            hcc_netbuf_clear_list_with_flowctrl(&hcc_handler->hcc_queues[i].queues[j].ready_queue);
            oal_netbuf_list_head_deinit(&hcc_handler->hcc_queues[i].queues[j].ready_queue);
        }
    }
}

int32_t hcc_module_init(void)
{
    int32_t ret;

    g_hcc_thread_info.event_type = 0xFFFFFFFF;
    if (hcc_thread_event_acquire(&g_hcc_thread_info.open_event) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "open_event acquire fail");
        return -OAL_FAIL;
    }

    if (hcc_thread_event_acquire(&g_hcc_thread_info.close_event) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "close_event acquire fail");
        ret = -OAL_FAIL;
        goto err_open_event_acquire;
    }

    if (hcc_thread_event_acquire(&g_hcc_thread_info.dfr_event) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "dfr_event acquire fail");
        ret = -OAL_FAIL;
        goto err_close_event_acquire;
    }

    if (mdrv_bsem_init(OS_SEM_EMPTY, SEM_MODE_PRIOR, &g_hcc_thread_info.run_sem) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "mdrv_bsem_init queue_sem fail");
        ret = -OAL_FAIL;
        goto err_dfr_event_acquire;
    }

    ret = hcc_thread_create();
    if (ret < 0) {
        oam_error_log0(0, OAM_SF_DPA, "thread create fail");
        goto err_hcc_run_sem_acquire;
    }
    return OAL_SUCC;

err_hcc_run_sem_acquire:
    mdrv_sem_delete(g_hcc_thread_info.run_sem);
err_dfr_event_acquire:
    hcc_thread_event_relasese(g_hcc_thread_info.dfr_event);
err_close_event_acquire:
    hcc_thread_event_relasese(g_hcc_thread_info.close_event);
err_open_event_acquire:
    hcc_thread_event_relasese(g_hcc_thread_info.open_event);
    return ret;
}

void hcc_module_exit(void)
{
    hcc_thread_destory();
    mdrv_sem_delete(g_hcc_thread_info.run_sem);
    hcc_thread_event_relasese(g_hcc_thread_info.close_event);
    hcc_thread_event_relasese(g_hcc_thread_info.open_event);
    oam_warning_log0(0, OAM_SF_DPA, "thread module exit");
}
