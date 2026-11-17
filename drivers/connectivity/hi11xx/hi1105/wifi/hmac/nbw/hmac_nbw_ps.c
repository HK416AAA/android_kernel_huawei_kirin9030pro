/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: nbw powersave
 * Author: wifi
 * Create: 2024-12-26
 */

#include "hmac_config.h"
#include "hmac_vap.h"
#include "hmac_chba_ps.h"
#include "hmac_chba_function.h"
#include "hmac_nbw_ps.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_PS_C
#ifdef _PRE_WLAN_FEATURE_NBW
uint8_t hmac_nbw_calc_bitmap_by_unuseful_data(hmac_chba_user_throughput_stru *throughput_info,
    hmac_chba_user_stru *chba_user_info, uint8_t cur_bitmap_level)
{
    /* 如果在历史5次采样周期中至少三次出现了大采样周期，说明trx不频繁,
       统计模型不能生效，如果此时bitmap为全f，直接置为33333333 */
    if (cur_bitmap_level == NBW_SLOT_LEVEL_1 &&
        throughput_info->large_tsf_interval_cnt >= TIME_INTERVAL_THRESHOLD) {
        return NBW_SLOT_LEVEL_2;
    }

    /* 休眠期间突然来了大量数据, nbw也立刻退出保活状态， 目前先复用chba实现 */
    if ((cur_bitmap_level == CHBA_BITMAP_KEEP_ALIVE_LEVEL) && hmac_chba_latest_data_is_large_packet(throughput_info)) {
        oam_warning_log2(0, OAM_SF_ANY,
            "{hmac_nbw_calc_bitmap_by_unuseful_data:high throught wakeup nbw!, tx_data[%d], rx_data[%d]}",
            throughput_info->tx_bytes_windows[throughput_info->peer_cnt],
            throughput_info->rx_bytes_windows[throughput_info->peer_cnt]);
        return NBW_SLOT_LEVEL_2;
    }
    return cur_bitmap_level;
}

uint8_t hmac_nbw_calc_bitmap_by_cnt(hmac_chba_user_stru *user_info, uint8_t cur_bitmap_level,
    hmac_chba_ps_throught_thres_stru *chba_thres)
{
    /* bitmap等级2降到等级3的条件:  powerDownCount 大于阈值 */
    if (user_info->power_down_count > chba_thres->downgrade_to_lv_three_thres &&
        cur_bitmap_level == NBW_SLOT_LEVEL_2) {
        return NBW_SLOT_LEVEL_3;
    } else if (user_info->power_down_count > chba_thres->downgrade_to_lv_two_thres &&
        cur_bitmap_level == NBW_SLOT_LEVEL_1) {
        /* bitmap等级1降到等级2的条件: power_save_count大于阈值 */
        return NBW_SLOT_LEVEL_2;
    }

    /* bitmap等级2升到等级1的条件: power_up_count大于阈值 */
    if (user_info->power_up_count > chba_thres->upgrade_to_lv_one_thres &&
        cur_bitmap_level == NBW_SLOT_LEVEL_2) {
        return NBW_SLOT_LEVEL_1;
    }

    /* 如果不满足以上条件，档位不变 */
    return user_info->nbw_user_slot_bitmap_level;
}

/*
 * 功能描述  : 流量模型算法，计算得出更新后的slot bitmap level
 *   日    期  : 2025年6月24日
 *   作    者  : 00500293
 */
uint8_t hmac_nbw_calc_bitmap_by_throughput(hmac_chba_vap_stru *vap_info, hmac_user_stru *hmac_user,
    hmac_chba_user_stru *nbw_user_info)
{
    uint8_t need_level_up;
    uint8_t cur_bitmap_level = nbw_user_info->nbw_user_slot_bitmap_level;
    uint8_t goto_awake_direct_flag;
    hmac_chba_user_throughput_stru *tmp_throughput_info = &nbw_user_info->throughput_info;
    hmac_vap_stru *hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(vap_info->mac_vap_id);
    /* 第一版使用和hml一样的thres，后面可改 */
    hmac_chba_ps_throught_thres_stru *chba_thres = hmac_chba_get_ps_throught_thres(hmac_vap);

    if (chba_thres == NULL) {
        return cur_bitmap_level;
    }

    /* 如果在历史5次采样周期中至少三次出现了大采样周期，说明trx不频繁,
       统计模型不能生效，如果此时bitmap为全f，直接置为33333333 */
    if (hmac_chba_latest_data_is_unuseful(tmp_throughput_info, nbw_user_info) == OAL_TRUE) {
        return hmac_nbw_calc_bitmap_by_unuseful_data(tmp_throughput_info, nbw_user_info, cur_bitmap_level);
    }
    oam_warning_log4(0, OAM_SF_CFG,
        "{hmac_nbw_calc_bitmap_by_throughput:user_idx[%d], cur_bitmap_level[%d], up_cnt[%d], down_cnt[%d]}",
        hmac_user->st_user_base_info.us_assoc_id, cur_bitmap_level, nbw_user_info->power_up_count,
        nbw_user_info->power_down_count);
    /* powerUpCount: txrx至少有1个不为0则加1, 清0的条件满足:
       升档或者最近连续5次统计中至少有3次txrx均为0或者收到bitmap req;
       powerDownCount: txrx均为0则加1，清0的条件满足: 降档或者最近连续5次统计中至少2次为大包或收到bitmap req */
    if (!hmac_chba_latest_data_is_zero(tmp_throughput_info)) {
        nbw_user_info->power_up_count++;
        if (hmac_chba_user_is_in_high_throughput(tmp_throughput_info->high_trx_windows_cnt)) {
            nbw_user_info->power_down_count = 0;
        }
        /* 如果该统计周期的流量是极大，则无论当前是什么档位，直接到全醒态 */
        goto_awake_direct_flag = hmac_chba_latest_data_is_huge_packet(tmp_throughput_info);
        if (goto_awake_direct_flag == OAL_TRUE) {
            return NBW_SLOT_LEVEL_1;
        }
        /* 自bitmap等级3升档: 最近的tx rx统计非0，且最近5次中至少3次为小包 或者有1次大包 */
        need_level_up = (cur_bitmap_level == NBW_SLOT_LEVEL_3) &&
            (hmac_chba_user_is_in_trxing(tmp_throughput_info->trx_windows_cnt) ||
            hmac_chba_latest_data_is_large_packet(tmp_throughput_info));
        if (need_level_up == OAL_TRUE && nbw_user_info->power_up_count > chba_thres->upgrade_to_lv_two_thres) {
            return NBW_SLOT_LEVEL_2;
        }
    } else {
        nbw_user_info->power_down_count++;
        if (hmac_chba_user_is_in_zero_throughput(tmp_throughput_info->trx_windows_cnt)) {
            nbw_user_info->power_up_count = 0;
        }
    }
    return hmac_nbw_calc_bitmap_by_cnt(nbw_user_info, cur_bitmap_level, chba_thres);
}

/*
 * 功能描述  : 生成user bitmap同步信息并同步
 *   日    期  : 2025年6月24日
 *   作    者  : 500293
 */
void hmac_nbw_sync_user_slot_bitmap_level_info(mac_vap_stru *mac_vap,
    hmac_user_stru *hmac_user, uint8_t tmp_bitmap_level)
{
    uint32_t ret;
    chba_user_ps_cfg_stru user_ps_cfg = { 0 };

    /* 将user同步信息初始化后, 同步给dmac */
    user_ps_cfg.user_idx = hmac_user->st_user_base_info.us_assoc_id;
    user_ps_cfg.bitmap_level = tmp_bitmap_level;
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_NBW_AUTO_ADJUST_SLOT_BITMAP_LEVEL, sizeof(chba_user_ps_cfg_stru),
        (uint8_t *)&user_ps_cfg);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(0, 0, "hmac_nbw_sync_user_slot_bitmap_level_info::send_event fail[%d]", ret);
    }
}

/*
 * 功能描述  : 将user slot bitmap level同步给驱动
 *   日    期  : 2025年6月24日
 *   作    者  : 500293
 */
void hmac_nbw_sync_user_slot_bitmap_level(hmac_vap_stru *hmac_vap,
    hmac_user_stru *hmac_user, uint8_t tmp_bitmap_level)
{
    hmac_chba_vap_stru *chba_vap_info = NULL;

    chba_vap_info = hmac_chba_get_chba_vap_info(hmac_vap);
    if (chba_vap_info == NULL) {
        return;
    }

    if (hmac_vap_is_connecting(&hmac_vap->st_vap_base_info) == OAL_TRUE) {
        return;
    }

    hmac_nbw_sync_user_slot_bitmap_level_info(&(hmac_vap->st_vap_base_info), hmac_user, tmp_bitmap_level);
    oam_warning_log1(0, 0, "hmac_nbw_sync_user_slot_bitmap_level: %d", tmp_bitmap_level);
}

/*
 * 功能描述  : NBW二级时隙低功耗流量模型算法入口, 后续考虑和chba是否归一，因为是流量模型总入口，目前区分
 *   日    期  : 2025年6月24日
 *   作    者  : 500293
 */
void hmac_nbw_update_throughput_info(hmac_chba_vap_stru *vap_info)
{
    uint8_t tmp_bitmap_level;
    hmac_vap_stru *hmac_vap = NULL;
    hmac_user_stru *hmac_user = NULL;
    hmac_chba_user_stru *nbw_user_info = NULL;
    mac_user_stru *mac_user = NULL;
    oal_dlist_head_stru *entry = NULL;
    oal_dlist_head_stru *dlist_tmp = NULL;

    if (vap_info == NULL) {
        oam_error_log0(0, OAM_SF_CHBA, "{hmac_nbw_update_throughput_info:vap_info is NULL!}");
        return;
    }
    /* 未初始化不处理 */
    if (hmac_chba_get_module_state(NBW_WORK_MODE) == MAC_CHBA_MODULE_STATE_UNINIT) {
        return;
    }

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(vap_info->mac_vap_id);
    if (hmac_vap == NULL) {
        return;
    }
    if (oal_dlist_is_empty(&(hmac_vap->st_vap_base_info.st_mac_user_list_head)) == OAL_TRUE) {
        return;
    }
    /* 对每一条链路的流程模型进行更新 */
    oal_dlist_search_for_each_safe(entry, dlist_tmp, &(hmac_vap->st_vap_base_info.st_mac_user_list_head)) {
        mac_user = oal_dlist_get_entry(entry, mac_user_stru, st_user_dlist);
        hmac_user = mac_res_get_hmac_user(mac_user->us_assoc_id);
        if ((hmac_user == NULL) || (mac_user_get_port(&hmac_user->st_user_base_info) == OAL_FALSE)) {
            continue;
        }
        nbw_user_info = &(hmac_user->chba_user);

        /* 将user吞吐放入算法部分进行计算,   第一版可以复用chba的update实现，后续由参数要修改可以直接在此函数中改 */
        hmac_chba_throughput_windows_update(vap_info, nbw_user_info, hmac_user);
        /* 流量模型建议还是用新的类似的，但是不复用实现，因为状态机算法改动比较频繁 */
        tmp_bitmap_level = hmac_nbw_calc_bitmap_by_throughput(vap_info, hmac_user, nbw_user_info);
        if (tmp_bitmap_level != nbw_user_info->nbw_user_slot_bitmap_level) {
            oam_warning_log3(0, 0,
                "{hmac_nbw_update_throughput_info:user_idx[%d], set user bitmap_level[%d]->[%d]}",
                mac_user->us_assoc_id, nbw_user_info->nbw_user_slot_bitmap_level, tmp_bitmap_level);
            oam_warning_log2(0, 0,
                "{hmac_nbw_update_throughput_info:cur user up_cnt[%d], dwon_cnt[%d]}",
                nbw_user_info->power_up_count, nbw_user_info->power_down_count);
            /* 准备更新bitmap，原统计结果清0, 复用chba的函数，因为统计信息相同 */
            hmac_chba_reset_throught_info_stat_cnt(nbw_user_info);
            /* 将此链路新bitmap消息同步到dmac */
            hmac_nbw_sync_user_slot_bitmap_level(hmac_vap, hmac_user, tmp_bitmap_level);
        }
    }
}

/*
 * 功能描述  : NBW:hmac user slot bitmap档位的更新接口
 *   日    期  : 2025年6月24日
 *   作    者  : 500293
 */
uint32_t hmac_nbw_update_user_slot_bitmap_level(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param)
{
    hmac_user_stru *hmac_user = NULL;
    chba_user_ps_cfg_stru *user_ps_cfg = NULL;
    hmac_chba_user_stru *user_info = NULL;
#ifdef _PRE_WLAN_NBW_DEMO
    hmac_vap_stru *hmac_vap = NULL;
    uint32_t total_bitmap;
#endif

    if (oal_any_null_ptr2(mac_vap, param)) {
        oam_error_log0(0, 0, "{hmac_nbw_update_user_slot_bitmap_level: ptr is NULL!}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    user_ps_cfg = (chba_user_ps_cfg_stru *)param;
    if (user_ps_cfg->bitmap_level >= NBW_SLOT_BITMAP_LEVEL_BUTT) {
        oam_error_log1(mac_vap->uc_vap_id, 0,
            "{hmac_nbw_update_user_slot_bitmap_level:invalid bitmap level[%d]}", user_ps_cfg->bitmap_level);
        return OAL_ERR_CODE_INVALID_CONFIG;
    }

    hmac_user = mac_res_get_hmac_user(user_ps_cfg->user_idx);
    if (hmac_user == NULL) {
        oam_warning_log1(mac_vap->uc_vap_id, 0,
            "{hmac_nbw_update_user_slot_bitmap_level:invalid user_idx[%d]}", user_ps_cfg->user_idx);
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 更新user bitmap */
    user_info = &(hmac_user->chba_user);
    if (user_info->nbw_user_slot_bitmap_level == user_ps_cfg->bitmap_level) {
        return OAL_SUCC;
    }
    user_info->nbw_user_slot_bitmap_level = user_ps_cfg->bitmap_level;
    /* user bitmap更新, chba流量模型重新开始计数 */
    hmac_chba_reset_throught_info_stat_cnt(user_info);
    /* nbw需要07c实现需要在host生成新的vap bitmap和user bitmap，并配置给device, 08更新完就结束了 */
#ifdef _PRE_WLAN_NBW_DEMO
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    /* 07c 上取所有链路中slot level最高的作为slot bitmap level来计算32位bitmap */
    total_bitmap = hmac_nbw_form_uslot_bitmap(hmac_nbw_get_new_slot_bitmap_level(mac_vap),
        hmac_get_user_uslot_bitmap(hmac_user));
    hmac_nbw_sync_user_bitmap(hmac_vap, hmac_user, total_bitmap);
    hmac_nbw_set_slot_bitmap(total_bitmap);
    hmac_nbw_sync_vap_bitmap_info(mac_vap);
    oam_warning_log3(mac_vap->uc_vap_id, 0,
        "{hmac_nbw_update_user_slot_bitmap_level:user_idx[%d], update user_bitmap_level[%d]}, bitmap: %d",
        hmac_user->st_user_base_info.us_assoc_id, user_info->nbw_user_slot_bitmap_level, total_bitmap);
#endif
    return OAL_SUCC;
}

#endif

