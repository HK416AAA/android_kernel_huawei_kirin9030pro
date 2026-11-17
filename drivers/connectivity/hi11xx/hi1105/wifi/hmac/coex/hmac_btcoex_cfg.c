/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2025. All rights reserved.
 * 功能说明 : 共存天线配置转发到dmac
 * 作    者 : y30060419
 * 创建日期 : 2025年4月15日
 */
#include "oam_wdk.h"
#include "mac_vap.h"
#include "frw_ext_if.h"
#include "hmac_config.h"
#include "hmac_cali_mgmt.h"
#include "hmac_vap.h"
#include "hd_btcoex_cfg.h"
#include "hmac_btcoex_cfg.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_BTCOEX_CFG_C

OAL_STATIC void hmac_btcoex_config_ant_mp12(ant_cfg_stru (*ant_cfg)[2])
{
    /* 配置Wi-Fi RF0和BT RF0的参数。BT没有RF1，但因为device侧结构体已经ROM化，数组大小不能改变，所以不填写BT RF1的配置 */
    ant_cfg[0][0].pta_strategy = HAL_BTCOEX_PTA_TIME_DIVISION;
    ant_cfg[0][0].is_shared_pll = OAL_FALSE;
    ant_cfg[0][0].affect_bitmap = 0xF;
    /* 配置Wi-Fi RF1和BT RF0的参数 */
    ant_cfg[1][0].pta_strategy = HAL_BTCOEX_PTA_NO_AFFECTED;
    ant_cfg[1][0].is_shared_pll = OAL_FALSE;
    ant_cfg[1][0].affect_bitmap = 0xF;
}

OAL_STATIC void hmac_fill_btcoex_ant_cfg_netbuf(oal_netbuf_stru *netbuf)
{
    uint8_t *data = NULL;

    data = oal_netbuf_data(netbuf);
    if (data == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_fill_btcoex_ant_cfg_netbuf:data null}");
        return;
    }
    hmac_btcoex_config_ant_mp12((ant_cfg_stru (*)[2])data);
    oam_warning_log0(0, OAM_SF_ANY, "{hmac_fill_btcoex_ant_cfg_netbuf:fill_btcoex_ant_cfg_netbuf succ.}");
    return;
}

#define BT_RF_STREAM_NUMS_MP12 2
/*
 * 函 数 名  : hmac_set_btcoex_ant_cfg_mp12
 * 功能描述  : 天线干扰状态的配置接口
 * 1.日    期  : 2025年4月15日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_set_btcoex_ant_cfg_mp12(mac_vap_stru *mac_vap)
{
    uint32_t ret;
    dmac_tx_event_stru *dtx_event = NULL;
    frw_event_mem_stru *event_mem = NULL;
    oal_netbuf_stru *netbuf = NULL;
    frw_event_stru *event = NULL;
    uint8_t rf_num = hmac_get_rf_num();
    size_t ant_cfg_num_mp12 = rf_num * BT_RF_STREAM_NUMS_MP12;
    size_t netbuf_len = sizeof(ant_cfg_stru) * ant_cfg_num_mp12;

    netbuf = oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF, netbuf_len, OAL_NETBUF_PRIORITY_MID);
    if (netbuf == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_fill_btcoex_ant_cfg_netbuf:netbuf alloc null}");
        return;
    }
    hmac_fill_btcoex_ant_cfg_netbuf(netbuf);
    oal_netbuf_put(netbuf, netbuf_len);

    /***************************************************************************
        抛事件到DMAC层, 同步DMAC数据
    ***************************************************************************/
    event_mem = frw_event_alloc_m(sizeof(dmac_tx_event_stru));
    if (event_mem == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_CFG, "{hmac_set_btcoex_ant_cfg::event_mem null.}");
        oal_netbuf_free(netbuf);
        return;
    }

    event = (frw_event_stru *)event_mem->puc_data;
    frw_event_hdr_init(&(event->st_event_hdr),
        FRW_EVENT_TYPE_WLAN_CTX, DMAC_WLAN_CTX_EVENT_SUB_TYPE_BTCOEX_ANT_CFG,
        sizeof(dmac_tx_event_stru), FRW_EVENT_PIPELINE_STAGE_1,
        mac_vap->uc_chip_id, mac_vap->uc_device_id, mac_vap->uc_vap_id);

    dtx_event = (dmac_tx_event_stru *)(event->auc_event_data);
    dtx_event->pst_netbuf = netbuf;
    dtx_event->us_frame_len = oal_netbuf_len(netbuf);

    ret = frw_event_dispatch_event(event_mem);
    if (ret != OAL_SUCC) {
        oam_error_log1(mac_vap->uc_vap_id, OAM_SF_CFG,
            "{hmac_set_btcoex_ant_cfg::frw_event_dispatch_event failed[%d].}", ret);
    }
    oal_netbuf_free(netbuf);
    frw_event_free_m(event_mem);
    return;
}