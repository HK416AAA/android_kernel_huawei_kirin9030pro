/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: nbw 8GHz channel measurement
 * Author: wifi
 * Create: 2025-03-29
 */
#include "hmac_nbw_channnel_measure.h"
#include "hmac_nbw_sync.h"
#include "oal_schedule.h"
#include "hmac_nbw_master_election.h"
#include "hmac_config.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_CHANNEL_MEASURE_C

#ifdef _PRE_WLAN_FEATURE_NBW
/* 信道测量管理全局变量 */
const uint8_t channel_num_array[NBW_MAX_CHANNLE_NUM] = {8, 9, 10};
hmac_nbw_chan_measure_mgmt_stru g_nbw_chan_meas_mgmt;

/* 信道测量结束的处理函数表 */
typedef uint32_t (*nbw_channel_measure_func)(hmac_vap_stru *hmac_vap);
static nbw_channel_measure_func g_nbw_channel_measure[MAC_NBW_TRIGGER_CHAN_MEASURE_EVENT_BUTT];

/*
 * 功能描述  : 基于当前nbw工作信道，获取信道测量参数
 */
uint8_t hmac_nbw_get_measure_param_by_current_work_channel(hmac_vap_stru *hmac_vap)
{
    uint8_t channel_list = 0x01;
    uint8_t index;
    mac_channel_stru work_channel = hmac_vap->hmac_chba_vap_info->work_channel;
    if (work_channel.uc_chan_number <= 0) {
        return 0;
    }
    for (index = 0; index < NBW_MAX_CHANNLE_NUM; index++) {
        if (channel_num_array[index] == work_channel.uc_chan_number) {
            channel_list <<= index;
            break;
        }
    }
    return channel_list;
}

/*
 * 功能描述  : 获取信道测量管理信息
 */
hmac_nbw_chan_measure_mgmt_stru* hmac_nbw_get_channel_measure_info(void)
{
    return &g_nbw_chan_meas_mgmt;
}

/*
 * 功能描述  : 获取信道测量结果
 */
hmac_nbw_chan_measure_res_stru *hmac_nbw_get_channel_measure_res(void)
{
    return g_nbw_chan_meas_mgmt.measure_res;
}

/*
 * 功能描述  : NBW信道测量默认处理函数
 */
static uint32_t hmac_nbw_channel_measure_process_fn(hmac_vap_stru *hmac_vap)
{
    /* 什么都不做 */
    oam_warning_log0(0, OAM_SF_CHBA, "{hmac_nbw_channel_measure_process_fn::null function}");

    return OAL_SUCC;
}

/*
 * 功能描述  : NBW连接触发的信道测量处理函数
 */
static uint32_t hmac_nbw_conn_trigger_chan_meas_process(hmac_vap_stru *hmac_vap)
{
    return 0;
}

/*
 * 功能描述  : NBW master丢失出发的信道测量处理函数
 */
static uint32_t hmac_nbw_master_lost_trigger_chan_meas_process(hmac_vap_stru *hmac_vap)
{
    hmac_nbw_master_loss_trigger_chan_meas_process(hmac_vap);
    return OAL_SUCC;
}

/*
 * 功能描述  : 初始化NBW信道测量处理函数
 */
void hmac_nbw_channel_measure_process_init(void)
{
    uint32_t event_num;

    /* 初始化为空函数 */
    for (event_num = 0; event_num < MAC_NBW_TRIGGER_CHAN_MEASURE_EVENT_BUTT; event_num++) {
        g_nbw_channel_measure[event_num] = hmac_nbw_channel_measure_process_fn;
    }

    /* 建链触发信道测量的处理函数 */
    g_nbw_channel_measure[MAC_NBW_CONN_TRIGGER_CHAN_MEASURE] = hmac_nbw_conn_trigger_chan_meas_process;
    /* master丢失触发信道测量的处理函数 */
    g_nbw_channel_measure[MAC_NBW_MASTER_LOST_TRIGGER_CHAN_MEASURE] = hmac_nbw_master_lost_trigger_chan_meas_process;
    g_nbw_channel_measure[MAC_NBW_POOR_QOS_TRIGGER_CHAN_MEASURE] = hmac_nbw_interface_trigger_chan_meas_process;
}

/*
 * 功能描述  : 配置信道测量事件
 */
static void hmac_nbw_config_channel_measure_event(uint16_t event)
{
    g_nbw_chan_meas_mgmt.measure_event |= BIT(event);
}

/*
 * 功能描述  : 信道列表bitmap中计算配置的测量信道数
 */
static uint8_t hmac_nbw_channel_cnt_calculate(uint8_t channel_list)
{
    uint8_t index;
    uint8_t channel_cnt = 0;
    for (index = 0; index < NBW_MAX_CHANNLE_NUM; index++) {
        if (channel_list & BIT0) {
            channel_cnt++;
        }
        channel_list >>= 1;
    }

    return channel_cnt;
}

/*
 * 功能描述  : 获取信道测量结果存储位置
 */
hmac_nbw_chan_measure_res_stru *hmac_nbw_get_measure_res_pos(uint8_t channel_num)
{
    uint8_t channel_num_index = NBW_MAX_CHANNLE_NUM;
    switch (channel_num) {
        case NBW_CHANNEL_8:
            channel_num_index = NBW_CHANNEL_RES_0;
            break;
        case NBW_CHANNEL_9:
            channel_num_index = NBW_CHANNEL_RES_1;
            break;
        case NBW_CHANNEL_10:
            channel_num_index = NBW_CHANNEL_RES_2;
            break;
        default:
            channel_num_index = NBW_MAX_CHANNLE_NUM;
    }
    if (channel_num_index >= NBW_MAX_CHANNLE_NUM) {
        oam_error_log1(0, 0, "NBW: {hmac_nbw_get_measure_res_pos: channel_num is wrong, channel num: %u}", channel_num);
        return NULL;
    }

    return &g_nbw_chan_meas_mgmt.measure_res[channel_num_index];
}


/*
 * 功能描述  : 释放一个信道测量结果中域节点的内存
 */
static void hmac_nbw_domain_list_node_free(struct hi_node *node)
{
    hmac_nbw_domain_list_node_stru *n = NULL;
    if (node == NULL) {
        return;
    }
    n = hi_node_entry(node, hmac_nbw_domain_list_node_stru, node);
    oal_free(n);
}

/*
 * 功能描述  : 清除过期的单个信道测量结果,入参为全局变量中对应信道在数组的中的下标
 */
static void hmac_nbw_clean_single_channel_res(uint8_t channel_index)
{
    hmac_nbw_chan_measure_res_stru *measure_res = NULL;
    if (channel_index >= NBW_MAX_CHANNLE_NUM) {
        oam_error_log0(0, 0, "NBW: {hmac_nbw_clean_single_channel_res: channle_index is wrong}");
        return;
    }
    measure_res = &g_nbw_chan_meas_mgmt.measure_res[channel_index];
    /* 清空域信息链表 */
    if (measure_res->domain_cnt > 0) {
        /* 释放域信息节点 */
        hi_list_deinit(&measure_res->domain_list, hmac_nbw_domain_list_node_free);
        /* 初始化信息链表 */
        hi_list_init(&measure_res->domain_list);
        measure_res->domain_cnt = 0;
    }

    /* 清空信道信息 */
    hi_list_init(&measure_res->domain_list);
    measure_res->domain_cnt = 0;
    measure_res->measure_end_time = 0;
    measure_res->channel_num = 0;
    measure_res->channel_load = 0;
}

/*
 * 功能描述  : 清除指定的过期的信道测量结果
 */
void hmac_nbw_clean_expire_res(uint8_t channel_list)
{
    uint8_t index;
    for (index = 0; index < NBW_MAX_CHANNLE_NUM; index++) {
        if (channel_list & BIT0) {
            hmac_nbw_clean_single_channel_res(index);
        }
        channel_list >>= 1;
    }
}

/*
 * 功能描述  : 信道测量参数检查
 */
static oal_bool_enum_uint8 hmac_nbw_channel_measure_para_check(uint8_t channel_cnt, uint8_t channel_list,
    uint16_t event, uint32_t measure_time)
{
    /* 触发事件和测量时间检查 */
    if (event >= MAC_NBW_TRIGGER_CHAN_MEASURE_EVENT_BUTT || measure_time == 0) {
        oam_error_log0(0, 0, "NBW: {hmac_nbw_channel_measure_para_check: event or measure_time is wrong}");
        return OAL_FALSE;
    }

    /* 信道参数检查 */
    if (channel_cnt == 0 || channel_cnt > NBW_MAX_CHANNLE_NUM || channel_list > NBW_CHANNEL_BITMAP_MAX_VALUE ||
        hmac_nbw_channel_cnt_calculate(channel_list) != channel_cnt) {
        oam_error_log0(0, 0, "NBW: {hmac_nbw_channel_measure_para_check: channel para wrong}");
        return OAL_FALSE;
    }
    
    return OAL_TRUE;
}

/*
 * 功能描述  : 执行挂接的处理函数
 */
static void hmac_nbw_channel_measure_res_process(hmac_vap_stru *hmac_vap)
{
    uint32_t event_index;

    /* 信道触发事件为空 */
    if (g_nbw_chan_meas_mgmt.measure_event == 0) {
        oam_warning_log0(0, 0, "NBW: {hmac_nbw_channel_measure_process: measure event is null}");
        return;
    }

    /* 调用对应的处理函数 */
    for (event_index = 0; event_index < MAC_NBW_TRIGGER_CHAN_MEASURE_EVENT_BUTT; event_index++) {
        if (g_nbw_chan_meas_mgmt.measure_event & BIT0) {
            g_nbw_channel_measure[event_index](hmac_vap);
        }
        g_nbw_chan_meas_mgmt.measure_event >>= 1;
    }
}

/*
 * 功能描述  : 信道测量前的状态检查，返回false表示已有的信道测量结果有效，无需再进行信道测量
 */
static uint8_t hmac_nbw_channel_measure_status_check(hmac_vap_stru *hmac_vap, uint8_t channel_cnt,
    uint8_t channel_list, uint16_t event)
{
    uint8_t index;
    uint8_t valid_cnt = 0;
    uint32_t curr_time_stamp;
    hmac_nbw_chan_measure_res_stru *measure_res = NULL;

    /* 如果当前正在进行信道测量则返回 */
    if (g_nbw_chan_meas_mgmt.measure_status == MAC_NBW_CHANNEL_MEASURE_START) {
        if (channel_list != g_nbw_chan_meas_mgmt.measure_channel_list) {
            oam_warning_log0(0, 0, "NBW: {hmac_nbw_channel_measure_status_check: channel measure busy!}");
            return MAC_NBW_CHANNEL_MEASURE_BUSY;
        }
        /* 配置信道测量事件 */
        hmac_nbw_config_channel_measure_event(event);
        oam_warning_log0(0, 0, "NBW: {hmac_nbw_channel_measure_status_check: has start channel measure!}");
        return OAL_FALSE;
    }

    /* 检查当前存储的信道测量结果是否有效 */
    for (index = 0; index < NBW_MAX_CHANNLE_NUM; index++) {
        if (channel_list & BIT0) {
            measure_res = &g_nbw_chan_meas_mgmt.measure_res[index];
            if (measure_res->domain_cnt == 0) {
                continue;
            }
            curr_time_stamp = (uint32_t)oal_time_get_stamp_ms();
            if (oal_time_after32(curr_time_stamp, (measure_res->measure_end_time + NBW_CHANNEL_RES_EXPIREE_TIME) ==
                FALSE)) {
                valid_cnt++;
            }
        }
        channel_list >>= 1;
    }

    /* 已有的信道测量结果都在有效期内,则直接使用已有的测量结果 */
    if (valid_cnt == channel_cnt) {
        oam_warning_log0(0, 0, "NBW: {hmac_nbw_channel_measure_status_check: channel measure res is still valid!}");
        /* 配置信道测量事件 */
        hmac_nbw_config_channel_measure_event(event);
        hmac_nbw_channel_measure_res_process(hmac_vap);
        return OAL_FALSE;
    }

    return OAL_TRUE;
}

/*
 * 功能描述  : 启动信道测量时，更新信道测量状态参数
 */
static void hmac_nbw_update_channel_measure_status(uint32_t status, uint8_t channel_cnt, uint8_t channel_list,
    uint16_t event, uint32_t measure_time)
{
    /* 配置信道测量管理信息 */
    g_nbw_chan_meas_mgmt.measure_status = status;
    g_nbw_chan_meas_mgmt.measure_channel_list = channel_list;
    g_nbw_chan_meas_mgmt.measure_channel_cnt = channel_cnt;
    g_nbw_chan_meas_mgmt.measure_event |= BIT(event);
    g_nbw_chan_meas_mgmt.measure_time = measure_time;
    g_nbw_chan_meas_mgmt.measure_channel_num = 0;
}

/*
 * 功能描述  : 通知device启动或者停止信道测量.flag为true表示开始测量，false表示停止测量
 */
void hmac_nbw_channel_measure_notification(hmac_vap_stru *hmac_vap, uint8_t channel_num, uint8_t flag)
{
    uint32_t ret;
    ret = hmac_config_send_event(&hmac_vap->st_vap_base_info, WLAN_CFGID_NBW_CHANNEL_MEASUREMENT_FLAG,
        sizeof(uint8_t), (uint8_t *)&flag);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_channel_measure_notification:: send event fail");
    }
}

/*
 * 功能描述  : 指示device进行单信道监听测量，并启动定时器
 */
static void hmac_nbw_single_channel_measure(hmac_vap_stru *hmac_vap)
{
    uint8_t index, channel_list, channel_cnt;
    uint8_t channel_num = 0;
    uint32_t measure_time;

    channel_list = g_nbw_chan_meas_mgmt.measure_channel_list;
    channel_cnt = g_nbw_chan_meas_mgmt.measure_channel_cnt;
    /* 查找到需要测量的单个信道号 */
    for (index = 0; index < NBW_MAX_CHANNLE_NUM; index++) {
        if (channel_list & BIT0) {
            channel_num = channel_num_array[index];
            break;
        }
        channel_list >>= 1;
    }

    if (channel_num == 0) {
        oam_error_log0(0, 0, "NBW: {hmac_nbw_single_channel_measure: channel num is 0}");
        return;
    }

    /* 下发信道测量指示给device, 将channel num下发给device */
    hmac_nbw_channel_measure_notification(hmac_vap, channel_num, OAL_TRUE);
    g_nbw_chan_meas_mgmt.measure_channel_num = channel_num;

    /* 启动定时器 */
    measure_time = g_nbw_chan_meas_mgmt.measure_time;
    if (g_nbw_chan_meas_mgmt.measure_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&(g_nbw_chan_meas_mgmt.measure_timer));
    }
    frw_timer_create_timer_m(&(g_nbw_chan_meas_mgmt.measure_timer), hmac_nbw_channel_measure_end_process,
        measure_time, hmac_vap, OAL_FALSE, OAM_MODULE_ID_HMAC, hmac_vap->st_vap_base_info.core_id);
    /* 更新待测量的信道信息 */
    channel_cnt = channel_cnt > 0 ? channel_cnt - 1 : 0; // 放置channel_cnt异常时，再减1
    channel_list >>= 1;
    g_nbw_chan_meas_mgmt.measure_channel_cnt = channel_cnt;
    g_nbw_chan_meas_mgmt.measure_channel_list = channel_list;
}

/*
 * 功能描述  : 信道测量结束的处理函数
 */
uint32_t hmac_nbw_channel_measure_end_process(void *arg)
{
    uint8_t channel_num;
    hmac_vap_stru *hmac_vap = NULL;
    hmac_nbw_chan_measure_res_stru *measure_res = NULL;

    hmac_vap = (hmac_vap_stru *)arg;
    if (hmac_vap == NULL) {
        oam_error_log0(0, 0, "NBW: {hmac_nbw_channel_measure_process: arg is null}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 记录信道测量结束时间 */
    channel_num = g_nbw_chan_meas_mgmt.measure_channel_num;
    measure_res = hmac_nbw_get_measure_res_pos(channel_num);
    if (measure_res == NULL) {
        oam_error_log0(0, 0, "NBW: {hmac_nbw_channel_measure_process: not find measure result pos}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    measure_res->measure_end_time = (uint32_t)oal_time_get_stamp_ms();
    measure_res->channel_num = channel_num;

    /* 多信道测量场景,即剩余信道测量数不为0, 不立即执行处理函数，等测量结束后执行 */
    if (g_nbw_chan_meas_mgmt.measure_channel_cnt != 0) {
        oam_warning_log0(0, 0, "NBW: {hmac_nbw_channel_measure_process: need continue measure}");
        hmac_nbw_single_channel_measure(hmac_vap);
        return OAL_SUCC;
    }

    /* 指示device信道测量结束 */
    hmac_nbw_channel_measure_notification(hmac_vap, channel_num, OAL_FALSE);

    /* 执行信道测量触发事件对应的处理函数 */
    hmac_nbw_channel_measure_res_process(hmac_vap);

    /* 本次测量结束，清除信道测量状态参数 */
    hmac_nbw_update_channel_measure_status(MAC_NBW_CHANNEL_MEASURE_END, 0, 0, 0, 0);

    return OAL_SUCC;
}

/*
 * 功能描述  : 信道测量入口函数，正常返回0，异常则返回对应异常码
 */
uint32_t hmac_nbw_channel_measure_request(hmac_vap_stru *hmac_vap, uint8_t channel_cnt, uint8_t channel_list,
    uint16_t event, uint32_t measure_time)
{
    oal_bool_enum_uint8 ret;
    /* 参数校验 */
    if (hmac_nbw_channel_measure_para_check(channel_cnt, channel_list, event, measure_time) == OAL_FALSE) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_channel_measure_request::para check err.");
        return MAC_NBW_CHANNEL_MEASURE_PARA_ERROR;
    }

    /* 信道测量状态检查 */
    ret = hmac_nbw_channel_measure_status_check(hmac_vap, channel_cnt, channel_list, event);
    if (ret != OAL_TRUE) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_channel_measure_request::measure check err.");
        return ret;
    }

    /* 清空对应信道的测量结果 */
    hmac_nbw_clean_expire_res(channel_list);

    /* 启动信道测量，更新信道测量状态参数 */
    hmac_nbw_update_channel_measure_status(MAC_NBW_CHANNEL_MEASURE_START, channel_cnt, channel_list,
        event, measure_time);

    /* 指示device进入测量模式, 并启动定时器，每次仅做单信道监听测量 */
    hmac_nbw_single_channel_measure(hmac_vap);

    return MAC_NBW_CHANNEL_MEASURE_NORMAL;
}

/*
 * 功能描述  : 将域信息节点保存到链表中
 */
static void hmac_nbw_save_domain_info_to_list(hmac_nbw_chan_measure_res_stru *measure_res,
    hmac_nbw_domain_list_node_stru *new_domain_node)
{
    struct hi_node *node = NULL;
    struct hi_node *tmp = NULL;
    hmac_nbw_domain_list_node_stru *domain_node = NULL;
    hmac_nbw_chan_domain_info_stru *domain_data = NULL;

    if (measure_res == NULL || new_domain_node == NULL) {
        return;
    }

    /* 按RSSI降序存储 */
    if (measure_res->domain_cnt == 0) {
        /* 域列表为空，则插入在链表头 */
        hi_list_add_head(&measure_res->domain_list, &new_domain_node->node);
    } else {
        hi_list_for_each_safe(node, tmp, &measure_res->domain_list) {
            domain_node = hi_node_entry(node, hmac_nbw_domain_list_node_stru, node);
            domain_data = &domain_node->data;
            if (domain_data->master_rssi < new_domain_node->data.master_rssi) {
                break;
            }
        }
        if (node == &measure_res->domain_list.base) {
            /* 域列表中所有域RSSI均高于当前域，则插入链表尾 */
            hi_list_add_tail(&measure_res->domain_list, &new_domain_node->node);
        } else {
            /* 域列表中存在域RSSI低于当前域，则插入该域前面 */
            hi_list_insert(&domain_node->node, &new_domain_node->node);
        }
    }
}

/*
 * 功能描述  : 信道测量过程中beacon帧处理，解析beacon帧并存储结果,入参payload为beacon attribute
 */
uint32_t hmac_nbw_channel_measure_beacon_process(uint8_t *payload, uint32_t payload_len, uint8_t *domain_addr)
{
    uint8_t is_master;
    hmac_nbw_chan_measure_res_stru *measure_res = NULL;
    struct hi_node *node = NULL;
    struct hi_node *tmp = NULL;
    hmac_nbw_domain_list_node_stru *domain_node = NULL;
    hmac_nbw_chan_domain_info_stru *domain_data = NULL;
    hmac_nbw_domain_list_node_stru *new_domain_node = NULL;

    /* 不在测量过程中，返回 */
    if (g_nbw_chan_meas_mgmt.measure_status != MAC_NBW_CHANNEL_MEASURE_START) {
        oam_warning_log0(0, 0, "NBW: {hmac_nbw_channel_measure_beacon_process: not start channel measure}");
        return OAL_FAIL;
    }

    /* 非master beacon帧不处理 */
    if (payload_len < NBW_MASTER_BEACON_ATTR_MIN_LEN) {
        oam_warning_log0(0, 0, "NBW: {hmac_nbw_channel_measure_beacon_process: beacon attr len is wrong}");
        return OAL_FAIL;
    }
    is_master = *(payload);
    if (is_master != 0x38) {
        oam_warning_log0(0, 0, "NBW: {hmac_nbw_channel_measure_beacon_process: not master beacon}");
        return OAL_FAIL;
    }

    measure_res = hmac_nbw_get_measure_res_pos(g_nbw_chan_meas_mgmt.measure_channel_num);
    if (measure_res == NULL) {
        oam_info_log0(0, 0, "NBW: {hmac_nbw_channel_measure_beacon_process: measure_res null}");
        return OAL_FAIL;
    }
    /* 遍历已有测量结果，去重 */
    hi_list_for_each_safe(node, tmp, &measure_res->domain_list) {
        domain_node = hi_node_entry(node, hmac_nbw_domain_list_node_stru, node);
        domain_data = &domain_node->data;
        if (oal_memcmp(domain_data->master_addr, domain_addr, OAL_MAC_ADDR_LEN) == 0) {
            domain_data->master_rssi = (int8_t)(*(payload + NBW_MATSER_BEACON_RSSI_OFFSET));
            return OAL_SUCC;
        }
    }
    /* 构造新的域节点 */
    new_domain_node = (hmac_nbw_domain_list_node_stru *)oal_memalloc(sizeof(hmac_nbw_domain_list_node_stru));
    if (new_domain_node == NULL) {
        return OAL_FAIL;
    }
    /* TDO: 设置值 */
    new_domain_node->data.alloc_uslot_bitmap = *(payload + NBW_USED_BITMAP_POS);
    new_domain_node->data.master_rssi = (int8_t)(*(payload + NBW_MATSER_BEACON_RSSI_OFFSET));
    new_domain_node->data.link_cnt = 0;
    oal_set_mac_addr(new_domain_node->data.master_addr, domain_addr);
    /* 保存到链表中 */
    hmac_nbw_save_domain_info_to_list(measure_res, new_domain_node);
    /* 更新域数量 */
    measure_res->domain_cnt += 1;
    return OAL_SUCC;
}
#endif