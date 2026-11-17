/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : HMAC模块HCC层适配
 * 作    者 :
 * 创建日期 : 2014年10月8日
 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD

#include "dpe_hcc.h"
#include "dpe_sbuf.h"
#include "dpe_wlan_resource.h"
#include "dpe_wlan_stat.h"
#include "oal_hcc_host_if.h"
#include "frw_event_main.h"
#include "host_hal_device.h"
#include "host_hal_ext_if.h"
#include "securec.h"
#include "securectype.h"
#include "oam_event_wifi.h"
#include "dpe_pm.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_HCC_MASTER_C

OAL_STATIC void dpe_rx_wifi_pm_wkup(struct frw_hcc_extend_hdr *extend_hdr)
{
    if (wlan_pm_wkup_src_debug_get() != OAL_TRUE) {
        return;
    }

    oal_io_print("wifi_wake_src:event[%d],subtype[%d]!\n", extend_hdr->en_nest_type, extend_hdr->uc_nest_sub_type);
    if (extend_hdr->en_nest_type == FRW_EVENT_TYPE_WLAN_DRX) {
        // 数据帧解析使用单独开关控制，避免在解析之前开关被别的事件关闭
        dpe_pm_wkup_src_parse_set(OAL_TRUE);
        wlan_pm_wkup_src_debug_set(OAL_FALSE);
        return;
    }

    /* 管理帧事件，开关在管理帧处理流程中打印具体的管理帧类型后关闭 */
    if (!((extend_hdr->en_nest_type == FRW_EVENT_TYPE_WLAN_CRX) &&
        (extend_hdr->uc_nest_sub_type == DMAC_WLAN_CRX_EVENT_SUB_TYPE_RX ||
        extend_hdr->uc_nest_sub_type == DMAC_WLAN_CRX_EVENT_SUB_TYPE_RX_WOW))) {
        wlan_pm_wkup_src_debug_set(OAL_FALSE);
    }
}

int32_t hcc_master_rx_wifi_post_action_function(uint8_t stype, oal_netbuf_stru *netbuf, uint8_t *context)
{
    struct hcc_header *hcc_hdr = (struct hcc_header *)oal_sbuf_cb(netbuf);
    struct frw_hcc_extend_hdr *frw_hdr = (struct frw_hcc_extend_hdr *)hcc_get_frw_hdr(netbuf);
    mac_rx_ctl_stru *rx_ctl = (mac_rx_ctl_stru*)oal_netbuf_cb(netbuf);
    dpe_wlan_event_dispatch_stat_stru *event_trx_stat = dpe_wlan_event_trx_stat_get();
    event_trx_stat->dpe_master_hcc_rx_event_cnt++;
    dpe_wifi_netbuf_in_inc(EN_HCC_RX);
    if (frw_hdr->en_nest_type >= FRW_EVENT_TYPE_BUTT) {
        oal_print_hex_dump((uint8_t *)oal_sbuf_cb(netbuf),
            (int32_t)sizeof(dpe_frw_event_stru), 32, "invaild frw extend hdr: "); // 32代表长度
        dpe_netbuf_free(netbuf);
        return 0;
    }

    if (!(rx_ctl->bit_is_beacon)) {
        g_pm_wlan_pkt_statis.d2h_rx_pkt++;
    }
    dpe_rx_wifi_pm_wkup(frw_hdr);

    /* WCPU->DPA、WCPU->DPA->ACPU依赖FRW继续转发ACPU */
    frw_event_param_stru param = {
        .type = frw_hdr->en_nest_type,
        .subtype = frw_hdr->uc_nest_sub_type,
        .hal_device_id = frw_hdr->device_id,
        .vap_id = frw_hdr->vap_id,
        .pipeline = FRW_EVENT_PIPELINE_STAGE_1,
        .transfer_event_to = FRW_EVENT_TO_ACORE,  /* master hcc接收的去往ACPU方向 */
        .hcc_extend = hcc_hdr->pad_hdr,
        .payload_size = oal_netbuf_len(netbuf),
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

void wcpu_rx_register_hcc_action(void)
{
    hcc_master_rx_register(HCC_ACTION_TYPE_WIFI, hcc_master_rx_wifi_post_action_function, NULL);
}

#endif
