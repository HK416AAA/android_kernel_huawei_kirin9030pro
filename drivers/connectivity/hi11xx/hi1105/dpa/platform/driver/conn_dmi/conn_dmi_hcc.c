/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: dmi消息驱动适配
 * Author: dpa drivers
 */

#include "osl_thread.h"
#include "bsp_timer.h"
#include "oal_util.h"
#include "oal_mm.h"
#include "oam_logger.h"
#include "hcc_comm.h"
#include "hcc_base.h"
#include "hcc_slave.h"
#include "conn_dmi_msg.h"
#include "conn_dmi_flowctrl.h"
#include "conn_dmi_hal.h"
#include "conn_dmi_hcc.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_CONN_DMI_HCC_C

#define DMI_HCC_INTER_STRU_SIZE          92
#define HCC_TX_NETBUF_COUNT              16
#define HCC_TX_FAIL_TIMEOUT              500000   /* 500ms */

#pragma pack(1)
// hcc_trans 结构体: 用于AP<->DPA之间HCC数据交互
struct dmi_hcc_inter_data_stru {
    uint64_t payload_addr;          // 保存MAA首地址(不受offset影响, MAA地址块128字节位置)
    uint16_t payload_len;           // 保存MAA数据长度(申请长度 + offset偏移)
    uint8_t hcc_qtype;
    uint8_t resv;
    uint64_t head_addr;             // 保存headroom的地址(MAA地址块0字节位置)
    uint64_t head_len;              // 保存headroom的长度(128字节预留长度 + offset偏移)
    uint8_t hcc_hdr[HCC_HDR_TOTAL_LEN];
};
#pragma pack()

typedef struct {
    uint32_t state;
    uint64_t hcc_rx_count;
    uint64_t hcc_tx_count;
    void *hcc_process_node;
    timer_handle time_handle;
} hcc_dmi_mng_str;

static hcc_bus_t g_hcc_dmi_bus;
static hcc_dmi_mng_str g_hcc_dmi_mng;
static uint32_t g_dmi_rx_alloc_fail_cnt;

/*
 * 函 数 名  : conn_dmi_hcc_send
 * 功能描述  : dmi发送hcc消息接口
 */
static int32_t conn_dmi_hcc_send(oal_netbuf_stru *sbuf, uint8_t qtype)
{
    int32_t ret;
    struct dmi_hcc_inter_data_stru *hcc_data = NULL;

    if (sbuf == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "conn_dmi_hcc_send param check fail");
        return -OAL_FAIL;
    }

    hcc_data = (struct dmi_hcc_inter_data_stru *)conn_dmi_hal_alloc_buf(sizeof(struct dmi_hcc_inter_data_stru));
    if (hcc_data == NULL) {
        return -OAL_ENOMEM;
    }

    // 获取MAA头部headroom信息
    hcc_data->head_addr = oal_netbuf_hcc_header(sbuf);
    hcc_data->head_len = HCC_HDR_TOTAL_LEN;
    // 获取sbuf len(MAA申请长度 + offset)
    hcc_data->payload_addr = oal_netbuf_data(sbuf);
    hcc_data->payload_len = (uint16_t)oal_netbuf_len(sbuf);

    ret = conn_dmi_hal_send(DMI_HAL_TYPE_HCC, (uint8_t *)hcc_data, sizeof(struct dmi_hcc_inter_data_stru));
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "dmi hcc send fail, ret = %d", ret);
        conn_dmi_hal_free_buf((uint8_t *)hcc_data);
        return ret;
    }

    conn_dmi_hal_free_buf((uint8_t *)hcc_data);
    return OAL_SUCC;
}

static inline void conn_hcc_dmi_rx_fail(const struct dmi_hcc_inter_data_stru *hcc_data)
{
    hcc_header_t *hcc_hdr = (hcc_header_t *)hcc_data->hcc_hdr;
    oam_error_log1(0, OAM_SF_DPA, "hcc dmi rx para check fail, payload_len = %d", hcc_data->payload_len);
    oam_error_log3(0, OAM_SF_DPA, "invaild hcc rx head, main_type[%d] sub_type[%d] pay_len[%d]", \
                   hcc_hdr->main_type, hcc_hdr->sub_type, hcc_hdr->pay_len);
}

static inline int32_t conn_hcc_dmi_rx_check(const struct dmi_hcc_inter_data_stru *hcc_data, uint16_t buf_len)
{
    if (buf_len != (uint16_t)(sizeof(struct dmi_hcc_inter_data_stru))) {
        oam_error_log1(0, OAM_SF_DPA, "hcc dmi rx len %u invalid", buf_len);
        return -OAL_FAIL;
    }

    if (hcc_data->payload_addr == 0 || hcc_data->payload_len == 0 ||
        hcc_data->head_addr == 0 || hcc_data->head_len == 0) {
        conn_hcc_dmi_rx_fail(hcc_data);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

static int32_t conn_dmi_hcc_rx(uint8_t *buf, uint16_t buf_len)
{
    struct dmi_hcc_inter_data_stru *hcc_data = NULL;
    oal_netbuf_stru *netbuf = NULL;
    uint8_t *hcc_head = NULL;

    g_hcc_dmi_mng.hcc_rx_count++;
    hcc_data = (struct dmi_hcc_inter_data_stru *)buf;
    if (conn_hcc_dmi_rx_check(hcc_data, buf_len) != OAL_SUCC) {
        oal_netbuf_free_data(hcc_data->payload_addr);
        return -OAL_FAIL;
    }

    netbuf = hcc_netbuf_build(hcc_data->payload_addr, hcc_data->payload_len);
    if (netbuf == NULL) {
        oal_netbuf_free_data(hcc_data->payload_addr);
        g_dmi_rx_alloc_fail_cnt++;
        oam_error_log2(0, OAM_SF_DPA, "build fail cnt %d, build_len = %d",
                       g_dmi_rx_alloc_fail_cnt, hcc_data->payload_len);
        conn_dmi_msg_data_send(CONN_DMI_MSG_SBUF_ALLOC_FAIL, (uint8_t *)&g_dmi_rx_alloc_fail_cnt, sizeof(uint32_t));
        return -OAL_FAIL;
    }

    // 拷贝hcc包头信息
    hcc_head = (uint8_t *)oal_sbuf_cb(netbuf);
    if (memcpy_s(hcc_head, OAL_SBUF_CB_MAX_LEN, hcc_data->hcc_hdr, HCC_HDR_TOTAL_LEN) != EOK) {
        oal_netbuf_destory(netbuf);
        oam_error_log0(0, OAM_SF_DPA, "dmi_hcc_rx_queue_process memcpy hcc hdr fail");
        return -OAL_FAIL;
    }

    hcc_slave_rx(netbuf);
    return OAL_SUCC;
}

static int32_t conn_dmi_hcc_rx_err(uint8_t *buf, uint16_t buf_len)
{
    struct dmi_hcc_inter_data_stru *hcc_data = (struct dmi_hcc_inter_data_stru *)buf;

    if (conn_hcc_dmi_rx_check(hcc_data, buf_len) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    oal_netbuf_free_data(hcc_data->payload_addr);
    return OAL_SUCC;
}

static int32_t dmi_hcc_tx_fail_retry(int arg)
{
    oam_error_log0(0, OAM_SF_DPA, "dmi_hcc_tx_fail_retry enter");
    hcc_slave_tx_sched_transfer();
    return OAL_SUCC;
}

static int32_t conn_dmi_hcc_tx_netbuf(hcc_bus_t *bus, oal_netbuf_head_stru *queue, uint32_t qtype)
{
    oal_netbuf_stru *netbuf = NULL;
    int32_t total = 0;
    uint32_t idx;
    uint32_t queue_len;
    timer_attr_s timerattr = { .name = "hcc_tx" };

    if (bus == NULL || queue == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "conn_dmi_hcc_tx_netbuf param check fail");
        return -OAL_FAIL;
    }

    if (oal_netbuf_list_len(queue) == 0) {
        oam_error_log0(0, OAM_SF_DPA, "conn_dmi_hcc_tx_netbuf netbuf queue is empty");
        return -OAL_FAIL;
    }
    g_hcc_dmi_mng.hcc_tx_count++;

    queue_len = oal_netbuf_list_len(queue);
    queue_len = queue_len > HCC_TX_NETBUF_COUNT ? HCC_TX_NETBUF_COUNT : queue_len;
    for (idx = 0; idx < queue_len; idx++) {
        netbuf = oal_netbuf_head_next(queue);
        if (conn_dmi_hcc_send(netbuf, (uint8_t)qtype) == OAL_SUCC) {
            netbuf = hcc_netbuf_delist_head_with_flowctrl(queue);
            oal_netbuf_destory(netbuf);
            total++;
        } else {
            timerattr.time = HCC_TX_FAIL_TIMEOUT;
            timerattr.flag = TIMER_FLAG_DEFAULT;
            timerattr.callback = dmi_hcc_tx_fail_retry;
            g_hcc_dmi_mng.time_handle = bsp_timer_add(&timerattr);
            if (g_hcc_dmi_mng.time_handle < 0) {
                oam_error_log1(0, OAM_SF_DPA, "conn_dmi_hcc_tx_netbuf timer start failed, %d",
                               g_hcc_dmi_mng.time_handle);
            }
            return total;
        }
    }

    return total;
}

static hcc_bus_ops_t g_dmi_opt_ops = {
    .tx_queue_sched = conn_dmi_hcc_tx_netbuf,
};


static void dmi_hcc_bus_init(void)
{
    hcc_slave_select_bus(HCC_BUS_DMI);
    memset_s(&g_hcc_dmi_bus, sizeof(g_hcc_dmi_bus), 0, sizeof(g_hcc_dmi_bus));
    g_hcc_dmi_bus.type = HCC_BUS_DMI;
    g_hcc_dmi_bus.ops = &g_dmi_opt_ops;
    hcc_slave_add_bus(&g_hcc_dmi_bus);
}

int32_t dmi_hcc_transfer_init(void)
{
    oal_build_bug_on((sizeof(struct dmi_hcc_inter_data_stru) != DMI_HCC_INTER_STRU_SIZE));

    /* dmi hcc接收回调初始化 */
    if (conn_dmi_hal_rx_register(DMI_HAL_TYPE_HCC, conn_dmi_hcc_rx, conn_dmi_hcc_rx_err) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hcc dmi rx register fail");
        return -OAL_FAIL;
    }

    dmi_hcc_bus_init();
    return OAL_SUCC;
}

void dmi_hcc_transfer_deinit(void)
{
    memset_s(&g_hcc_dmi_bus, sizeof(g_hcc_dmi_bus), 0, sizeof(g_hcc_dmi_bus));
    memset_s(&g_hcc_dmi_mng, sizeof(g_hcc_dmi_mng), 0, sizeof(hcc_dmi_mng_str));
}