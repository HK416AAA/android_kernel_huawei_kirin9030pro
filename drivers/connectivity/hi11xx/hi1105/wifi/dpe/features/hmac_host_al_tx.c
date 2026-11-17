/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : host常发管理功能
 * 作者       : wifi
 * 创建日期   : 2020年05月15日
 */

/* 1 头文件包含 */

#include "hd_command.h"
#include "hmac_tx_msdu_dscr.h"
#include "hmac_tx_ring_alloc.h"
#include "host_hal_ext_if.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "hmac_config.h"
#endif
#include "host_hal_dma.h"
#include "dpe_wlan_config.h"
#include "dpe_tx_data.h"
#include "dpe_wlan_stat.h"
#include "dpe_sbuf.h"
#include "hmac_host_al_tx.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_AL_TX_C

#define AL_TX_MSDU_NETBUF_MAX_NUM (4 * MAX_MAC_AGGR_MPDU_NUM)

/* DPA模式下host常发定时器超时时间 */
#define DPE_ALTX_NETBUF_TIMEOUT 50
/* hal_device级别常发资源 */
dpe_wlan_altx_stru g_dpe_wlan_altx_res[WLAN_DEVICE_MAX_NUM_PER_CHIP];

/* 常发资源初始化 */
void dpe_wlan_altx_res_init(void)
{
    uint8_t hal_dev_id;

    memset_s(g_dpe_wlan_altx_res, sizeof(g_dpe_wlan_altx_res), 0, sizeof(g_dpe_wlan_altx_res));
    /* 初始化常发netbuf链表 */
    for (hal_dev_id = 0; hal_dev_id < WLAN_DEVICE_MAX_NUM_PER_CHIP; hal_dev_id++) {
        oal_netbuf_list_head_init_nolock(&g_dpe_wlan_altx_res[hal_dev_id].netbuf_list);
    }
}

/*
 * 功能描述  : 初始化ring
 * 1.日    期  : 2020年4月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_always_tx_init_tx_ring(hmac_msdu_info_ring_stru *tx_ring)
{
    memset_s(tx_ring, sizeof(hmac_msdu_info_ring_stru), 0, sizeof(hmac_msdu_info_ring_stru));
    tx_ring->base_ring_info.size = hal_host_tx_tid_ring_size_get(HAL_TX_RING_SIZE_GRADE_DEFAULT, WLAN_TIDNO_BCAST);
    tx_ring->host_tx_flag = HOST_AL_TX_FLAG;
    oal_atomic_set(&tx_ring->inited, OAL_TRUE);
    if (hmac_alloc_tx_ring_by_tid(tx_ring, WLAN_TIDNO_BCAST) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "{hmac_always_tx_init_tx_ring::hmac_alloc_tx_ring_by_tid failed}");
        return OAL_FAIL;
    }
    return OAL_SUCC;
}
/*
 * 功能描述  : 配置msdu ring info
 * 1.日    期  : 2020年4月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC void hmac_always_tx_set_msdu_info(msdu_info_stru *msdu_info, oal_netbuf_stru *netbuf, uint64_t devva)
{
    memset_s(msdu_info, sizeof(msdu_info_stru), 0, sizeof(msdu_info_stru));
    msdu_info->msdu_addr_lsb = get_low_32_bits(devva);
    msdu_info->msdu_addr_msb = get_high_32_bits(devva);
    msdu_info->msdu_len = oal_netbuf_len(netbuf);
    msdu_info->data_type = DATA_TYPE_ETH;
    msdu_info->from_ds = 0;
    msdu_info->to_ds = 1;
}
/*
 * 功能描述  : 修改ringbuffer
 * 1.日    期  : 2020年4月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC void hmac_al_tx_set_ring_info(hmac_msdu_info_ring_stru *tx_ring, oal_netbuf_stru *netbuf, uint32_t index,
    uint64_t info_devva)
{
    msdu_info_stru msdu_info = { 0 };
    hmac_always_tx_set_msdu_info(&msdu_info, netbuf, info_devva);
    hal_host_tx_set_msdu_ring(&tx_ring->ring_buf, &msdu_info, index);
    tx_ring->netbuf_list[index] = netbuf;
    oal_atomic_inc(&tx_ring->msdu_cnt);
    tx_ring->base_ring_info.write_index++;
}
/*
 * 功能描述  : 更新抛事件内容
 * 1.日    期  : 2020年4月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC void hmac_always_tx_set_update_info(mac_cfg_tx_comp_stru *event_set_al_tx,
    hmac_msdu_info_ring_stru *tx_ring, uint32_t net_buff_num, uint64_t devva)
{
    event_set_al_tx->base_addr_lsb = get_low_32_bits(devva);
    event_set_al_tx->base_addr_msb = get_high_32_bits(devva);
    event_set_al_tx->en_protocol_mode = tx_ring->base_ring_info.size;
    event_set_al_tx->en_ack_policy = net_buff_num / MAX_MAC_AGGR_MPDU_NUM;
    event_set_al_tx->write_index = net_buff_num;
    event_set_al_tx->uc_param = HAL_ALWAYS_TX_DEVICE_TX;
}

/*
 * 功能描述  : host长发根据帧长获取netbuf个数
 * 1.日    期  : 2020年12月14日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_always_tx_get_netbuf_num(uint32_t payload_len)
{
    uint32_t net_buff_num;

    if (payload_len % AL_TX_MSDU_NETBUF_MAX_LEN == 0) {
        net_buff_num = payload_len / AL_TX_MSDU_NETBUF_MAX_LEN;
    } else {
        net_buff_num = payload_len / AL_TX_MSDU_NETBUF_MAX_LEN + 1;
    }
    net_buff_num = oal_min(net_buff_num, AL_TX_MSDU_NETBUF_MAX_NUM);
    return net_buff_num;
}
OAL_STATIC void hmac_always_tx_spin_lock_init(hmac_msdu_info_ring_stru *tx_ring)
{
    dpe_tid_tx_lock_init(&tx_ring->tx_lock);
    dpe_tid_tx_comp_lock_init(&tx_ring->tx_comp_lock);
}

void hmac_al_tx_ring_release(hmac_msdu_info_ring_stru *tx_ring)
{
    oal_atomic_set(&tx_ring->inited, OAL_FALSE);
    hmac_tx_host_ring_release(tx_ring);
}
/*
 * 功能描述  : host常发 同步 msdu info信息 需要在常发启动前同步
 * 1.日    期  : 2025年6月20日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC void hmac_always_tx_set_msdu_info_msg(hal_tx_ring_table_addr_stru *tx_ring_addr,
    uint32_t net_buff_num, uint8_t *param)
{
    mac_cfg_altx_msdu_info_stru *event_set_al_tx = (mac_cfg_altx_msdu_info_stru *)param;
    event_set_al_tx->msdu_info_addr_lsb = get_low_32_bits(tx_ring_addr->info_devva);
    event_set_al_tx->msdu_info_addr_msb = get_high_32_bits(tx_ring_addr->info_devva);
    event_set_al_tx->msdu_addr_addr_lsb = get_low_32_bits(tx_ring_addr->addr_devva);
    event_set_al_tx->msdu_addr_addr_msb = get_high_32_bits(tx_ring_addr->addr_devva);
    event_set_al_tx->al_tx_netbuf_num = net_buff_num;
    event_set_al_tx->al_tx_flag = HAL_ALWAYS_TX_DEVICE_TX;
}

void hmac_always_tx_send_msdu_info_msg(dpe_wlan_vap_stru *dpe_vap, uint16_t len, uint8_t *param)
{
    uint32_t ret;

    if (dpe_vap == NULL) {
        oam_warning_log0(0, OAM_SF_DPA, "{hmac_always_tx_send_msdu_info_msg::dpe_vap is null.}");
        return;
    }
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    ret = hmac_config_send_event((mac_vap_stru *)mac_res_get_mac_vap(dpe_vap->uc_vap_id),
        WLAN_CFGID_SET_ALWAYS_TX_RING_INFO, len, param);
#else
    ret = dpe_config_sync_device_send_event(dpe_vap, WLAN_CFGID_SET_ALWAYS_TX_RING_INFO, param, len);
#endif
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(dpe_vap->uc_vap_id, OAM_SF_DPA,
            "{hmac_always_tx_send_msdu_info_msg::hmac_config_send_event failed[%d].}", ret);
    }
}

/*
 * 功能描述  : host常发主流程
 * 1.日    期  : 2020年4月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_always_tx_proc(dpe_wlan_vap_stru *dpe_vap, uint16_t len, uint8_t *param, uint8_t hal_dev_id)
{
    mac_cfg_tx_comp_stru *event_set_al_tx = (mac_cfg_tx_comp_stru *)param;
    uint32_t ret;
    uint32_t index;
    uint32_t net_buff_num;
    hal_tx_ring_table_addr_stru tx_ring_addr = {0};
    hmac_msdu_info_ring_stru *tx_ring = &g_dpe_wlan_altx_res[hal_dev_id].tx_ring;
    oal_netbuf_stru  *netbuf = NULL;
    uint8_t payload_flag = event_set_al_tx->en_payload_flag;
    uint32_t payload_len = event_set_al_tx->payload_len;

    if (hmac_always_tx_init_tx_ring(tx_ring) != OAL_SUCC) {
        return OAL_FAIL;
    }
    hmac_always_tx_spin_lock_init(tx_ring);
    net_buff_num = hmac_always_tx_get_netbuf_num(payload_len);
    for (index = 0; index < net_buff_num; index++) {
        /* 从常发队列中取出netbuf */
        if (oal_netbuf_list_empty(&g_dpe_wlan_altx_res[hal_dev_id].netbuf_list) == OAL_TRUE) {
            oam_warning_log0(0, OAM_SF_DPA, "{hmac_always_tx_proc::al_tx_netbuf_list empty!");
            break;
        }
        netbuf = oal_netbuf_delist_nolock(&g_dpe_wlan_altx_res[hal_dev_id].netbuf_list);
        if (oal_unlikely(netbuf == NULL)) {
            hmac_al_tx_ring_release(tx_ring);
            oam_error_log0(0, OAM_SF_DPA, "{hmac_always_tx_proc::netbuf is NULL}");
            return OAL_ERR_CODE_PTR_NULL;
        }

        ret = hmac_altx_hostva_to_devva(netbuf,
            oal_netbuf_len(netbuf) + hal_host_tx_get_msdu_dscr_len(), &tx_ring_addr.info_devva);
        if (ret != OAL_SUCC) {
            oam_error_log1(0, OAM_SF_DPA, "{hmac_always_tx_proc::hostva to info_devva failed[%d]}", ret);
            hmac_al_tx_ring_release(tx_ring);
            dpe_netbuf_free(netbuf);
            return ret;
        }
        hmac_al_tx_set_ring_info(tx_ring, netbuf, index, tx_ring_addr.info_devva);
    }
    if (hal_host_tx_get_msdu_info_devva(&tx_ring->ring_buf, &tx_ring_addr) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "{hmac_always_tx_proc::hostva to devva failed");
        hmac_al_tx_ring_release(tx_ring);
        return OAL_ERR_CODE_ALLOC_MEM_FAIL;
    }
    hmac_always_tx_set_msdu_info_msg(&tx_ring_addr, net_buff_num, param);
    hmac_always_tx_send_msdu_info_msg(dpe_vap, len, param);
    event_set_al_tx->en_payload_flag = payload_flag;
    event_set_al_tx->payload_len = payload_len;
    hmac_always_tx_set_update_info(event_set_al_tx, tx_ring, net_buff_num, tx_ring_addr.info_devva);
    return ret;
}

uint32_t dpe_always_tx_netbuf_enqueue(uint8_t hal_dev_id, oal_netbuf_stru *netbuf)
{
    dpe_wlan_tx_stat_stru *dpe_tx_stat = dpe_wlan_tx_stat_get();
    dpe_tx_stat->tx_gso_output_altx++;
    oal_netbuf_list_tail_nolock(&g_dpe_wlan_altx_res[hal_dev_id].netbuf_list, netbuf);
    return OAL_SUCC;
}

/* 功能：常发trx ring定制化开关check */
void hmac_altx_trx_switch_check(hal_device_always_tx_enum_uint8 al_tx_flag)
{
    if ((al_tx_flag == HAL_ALWAYS_TX_HOST_RING_TX && dpe_host_ring_tx_enabled() != OAL_TRUE) ||
        ((al_tx_flag == HAL_ALWAYS_TX_DEVICE_TX || al_tx_flag == HAL_ALWAYS_TX_DEVICE_RING_TX) &&
        dpe_device_ring_tx_enabled() != OAL_TRUE)) {
        oam_error_log3(0, OAM_SF_DPA, "{hmac_altx_trx_switch_check::al_tx[%d] host ring[%d] dev ring[%d]}",
            al_tx_flag, dpe_host_ring_tx_enabled(), dpe_device_ring_tx_enabled());
    }
}
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
int dpe_altx_check_netbuf_list_timeout(int arg)
#else
uint32_t dpe_altx_check_netbuf_list_timeout(void *arg)
#endif
{
    uint8_t vap_id;
    uint8_t hal_dev_id;
    dpe_wlan_vap_stru *dpe_vap = NULL;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    if (arg == 0) {
#else
    if (arg == NULL) {
#endif
        oam_error_log0(0, OAM_SF_DPA, "{dpe_altx_check_netbuf_list_timeout::arg is null!}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    vap_id = *((uint8_t *)arg);
    dpe_vap = dpe_wlan_vap_get(vap_id);
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_altx_check_netbuf_list_timeout::get dpe_vap failed!}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    hal_dev_id = dpe_vap->hal_dev_id;

    if (oal_netbuf_list_len(&g_dpe_wlan_altx_res[hal_dev_id].netbuf_list) <
        g_dpe_wlan_altx_res[hal_dev_id].netbuf_num) {
        /* 若netbuf仍未传输完成则继续起定时器等待 */
        frw_timer_create_timer_m(&g_dpe_wlan_altx_res[hal_dev_id].netbuf_timer,
            dpe_altx_check_netbuf_list_timeout, DPE_ALTX_NETBUF_TIMEOUT, &dpe_vap->uc_vap_id,
            OAL_FALSE, 0, dpe_vap->core_id);
        return OAL_SUCC;
    } else {
        /* netbuf传输完成继续常发流程处理 */
        return dpe_config_always_tx(dpe_vap, dpe_vap->hal_dev_id, g_dpe_wlan_altx_res[hal_dev_id].param_len,
            g_dpe_wlan_altx_res[hal_dev_id].param);
    }
}

uint32_t dpe_config_always_tx(dpe_wlan_vap_stru *dpe_vap, uint8_t dev_id, uint8_t len, uint8_t *param)
{
    uint32_t ret = OAL_SUCC;
    mac_cfg_tx_comp_stru *al_tx_param = (mac_cfg_tx_comp_stru *)param;
    hal_device_always_tx_enum_uint8 al_tx_flag;

    if (dpe_vap == NULL || param == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    al_tx_flag = al_tx_param->uc_param;
#ifndef _PRE_LINUX_TEST
    /* 设置host常发状态 */
    hal_set_altx_status(dev_id, (al_tx_flag == HAL_ALWAYS_TX_DISABLE) ? OAL_FALSE : OAL_TRUE);
    dpe_wlan_device_al_trx_flag_sync((al_tx_flag == HAL_ALWAYS_TX_DISABLE) ? OAL_FALSE : OAL_TRUE);
#endif
    hmac_altx_trx_switch_check(al_tx_flag);
    /* 常发host ring tx处理，未使能host ring不处理 */
    if ((dpe_ring_tx_enabled() == OAL_TRUE) && al_tx_flag == HAL_ALWAYS_TX_HOST_RING_TX) {
        ret = hmac_always_tx_proc(dpe_vap, len, param, dev_id);
        if (ret != OAL_SUCC) {
            oam_warning_log1(dpe_vap->uc_vap_id, OAM_SF_DPA,
                "{dpe_config_always_tx::hmac_always_tx_proc failed[%d].}", ret);
            return ret;
        }
    }
    /* 去使能且有包，执行释放动作 */
    if ((dpe_ring_tx_enabled() == OAL_TRUE) && (al_tx_flag == HAL_ALWAYS_TX_DISABLE)) {
        /* 清理ring中的netbuf */
        if (oal_atomic_read(&(g_dpe_wlan_altx_res[dev_id].tx_ring.msdu_cnt)) != 0) {
            oam_warning_log2(dpe_vap->uc_vap_id, OAM_SF_DPA,
                "{dpe_config_always_tx::al tx ring release before, msdu_cnt[%d] al tx mode[%d].}",
                oal_atomic_read(&(g_dpe_wlan_altx_res[dev_id].tx_ring.msdu_cnt)), al_tx_flag);
            hmac_al_tx_ring_release(&g_dpe_wlan_altx_res[dev_id].tx_ring);
        }
        /* 清理未出队的netbuf */
        if (oal_netbuf_list_empty(&g_dpe_wlan_altx_res[dev_id].netbuf_list) == OAL_FALSE) {
            dpe_netbuf_clear_list(&g_dpe_wlan_altx_res[dev_id].netbuf_list);
        }
        /* 清理已创建的定时器 */
        if (g_dpe_wlan_altx_res[dev_id].netbuf_timer.en_is_registerd == OAL_TRUE) {
            frw_timer_immediate_destroy_timer_m(&g_dpe_wlan_altx_res[dev_id].netbuf_timer);
        }
    }

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* DPA模式下执行完常发初始化后抛事件到dmac启动常发 */
    ret = dpe_config_sync_device_send_event(dpe_vap, WLAN_CFGID_SET_ALWAYS_TX, param, len);
#endif

    return ret;
}

/*
 * 功能描述  : DPA模式下，host ring常发判断(若netbuf未传完，起定时器等待)
 * 日    期  : 2025年5月20日
 * 作    者  : Wi-Fi
 * 修改内容  : 新生成函数
 */
uint32_t dpe_always_tx_host_ring_check(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param)
{
    uint32_t net_buff_num;
    uint32_t payload_len;
    hal_device_always_tx_enum_uint8 al_tx_flag;
    mac_cfg_tx_comp_stru *al_tx_param = (mac_cfg_tx_comp_stru *)param;

    if (dpe_vap == NULL || param == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    al_tx_flag = al_tx_param->uc_param;
    payload_len = al_tx_param->payload_len;
    /* host ring常发时才需要判断netbuf是否已全部从hmac传至dpa */
    if ((dpe_ring_tx_enabled() == OAL_TRUE) && al_tx_flag == HAL_ALWAYS_TX_HOST_RING_TX) {
        /* 存储常发参数 */
        net_buff_num = hmac_always_tx_get_netbuf_num(payload_len);
        g_dpe_wlan_altx_res[dpe_vap->hal_dev_id].netbuf_num = net_buff_num;
        g_dpe_wlan_altx_res[dpe_vap->hal_dev_id].param_len = len;
        if (memcpy_s(g_dpe_wlan_altx_res[dpe_vap->hal_dev_id].param, WLAN_MAX_NETBUF_SIZE, param, len) != EOK) {
            oam_error_log0(dpe_vap->uc_vap_id, OAM_SF_DPA, "dpe_always_tx_host_ring_check:copy param failed!");
            return OAL_FAIL;
        }
        /* 若netbuf未全部传输到DPA，则起定时器等待 */
        if (oal_netbuf_list_len(&g_dpe_wlan_altx_res[dpe_vap->hal_dev_id].netbuf_list) < net_buff_num) {
            frw_timer_create_timer_m(&g_dpe_wlan_altx_res[dpe_vap->hal_dev_id].netbuf_timer,
                dpe_altx_check_netbuf_list_timeout, DPE_ALTX_NETBUF_TIMEOUT, &dpe_vap->uc_vap_id,
                OAL_FALSE, 0, dpe_vap->core_id);
            return OAL_SUCC;
        }
    }
    return dpe_config_always_tx(dpe_vap, dpe_vap->hal_dev_id, len, param);
}
