/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : HMAC模块HCC层适配
 * 作    者 :
 * 创建日期 : 2014年10月8日
 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD

#include "dpe_hcc.h"
#include "dpe_sbuf.h"
#include "dpe_frw_if.h"
#include "oal_hcc_host_if.h"
#include "frw_event_main.h"
#include "host_hal_device.h"
#include "host_hal_ext_if.h"
#include "securec.h"
#include "securectype.h"
#include "oam_event_wifi.h"
#include "dpe_wlan_stat.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_HCC_SLAVE_C

int32_t hcc_slave_rx_wifi_post_action_function(uint8_t stype, oal_netbuf_stru *netbuf, uint8_t *context)
{
    struct hcc_header *hcc_hdr = (struct hcc_header *)oal_sbuf_cb(netbuf);
    struct frw_hcc_extend_hdr *frw_hdr = (struct frw_hcc_extend_hdr *)hcc_get_frw_hdr(netbuf);
    dpe_wlan_event_dispatch_stat_stru *event_trx_stat = dpe_wlan_event_trx_stat_get();
    dpe_wifi_netbuf_in_inc(EN_HCC_RX);
    /* 事件信息维护在sbuf cb(128 bytes) */
    if (frw_hdr->en_nest_type >= FRW_EVENT_TYPE_BUTT) {
        oam_warning_log1(0, OAM_SF_DPA,
            "hcc_slave_rx_wifi_post_action_function::type[%d] butt invalid", frw_hdr->en_nest_type);
        oal_print_hex_dump((uint8_t *)oal_sbuf_cb(netbuf),
            (int32_t)sizeof(dpe_frw_event_stru), 32, "invaild frw extend hdr: "); // 32代表长度
        dpe_netbuf_free(netbuf);
        return 0;
    }
    event_trx_stat->dpe_slave_hcc_rx_event_cnt++;
    /* ACPU->DPA、ACPU->DPA->WCPU依赖FRW继续转发WCPU */
    frw_event_param_stru param = {
        .type = frw_hdr->en_nest_type,
        .subtype = frw_hdr->uc_nest_sub_type,
        .hal_device_id = frw_hdr->device_id,
        .vap_id = frw_hdr->vap_id,
        .pipeline = FRW_EVENT_PIPELINE_STAGE_1,
        .transfer_event_to = FRW_EVENT_TO_WCORE, /* slave hcc接收的去往WCPU方向 */
        .hcc_extend = hcc_hdr->pad_hdr,
        .payload_size = oal_netbuf_len(netbuf), /* 偏移64字节hcc头部后的长度 */
        .payload = NULL,
        .netbuf = netbuf,
    };
    if (frw_post_event(&param) != OAL_SUCC) {
        oal_print_hex_dump((uint8_t *)oal_sbuf_cb(netbuf),
            (int32_t)sizeof(dpe_frw_event_stru), 32, "invaild frw extend hdr: "); // 32代表长度
        dpe_netbuf_free(netbuf);
    }
    return 0;
}
static int32_t hcc_slave_rx_custom_post_action_function(uint8_t stype, oal_netbuf_stru *netbuf, uint8_t *pst_context)
{
    struct hcc_transfer_param param = { 0 };

    hcc_hdr_param_init(&param, HCC_ACTION_TYPE_CUSTOMIZE, stype, 0, HCC_FC_WAIT, DATA_HI_QUEUE);
    return hcc_master_tx(netbuf, oal_netbuf_len(netbuf), &param);
}
void acpu_rx_register_hcc_action(void)
{
    hcc_slave_rx_register(HCC_ACTION_TYPE_WIFI, hcc_slave_rx_wifi_post_action_function, NULL);
    hcc_slave_rx_register(HCC_ACTION_TYPE_CUSTOMIZE, hcc_slave_rx_custom_post_action_function, NULL);
}
#endif
