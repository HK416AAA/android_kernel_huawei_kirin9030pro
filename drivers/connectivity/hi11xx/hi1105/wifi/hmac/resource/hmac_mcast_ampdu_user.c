/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_mcast_ampdu_user.c
 * 作    者 :
 * 创建日期 : 2025年05月26日
 */

/* 1 头文件包含 */
#include "hmac_tx_data.h"
#include "hmac_host_tx_data.h"
#include "hmac_resource.h"
#include "hmac_tx_ring_alloc.h"
#include "hmac_rx_reorder.h"
#include "oam_stat_wifi.h"
#include "hmac_wapi.h"
#include "hmac_invoke_dpe.h"
#include "hmac_mcast_ampdu.h"
#include "hmac_user.h"
#include "hmac_config.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_MCAST_AMPDU_USER_C


#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
void hmac_mcast_ampdu_user_init(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user,
    uint8_t *lut_idx, uint8_t *ml_lut_idx)
{
    mac_chip_stru *mac_chip = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    if (mac_vap->en_vap_mode != WLAN_VAP_MODE_BSS_AP) {
        return;
    }
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        return;
    }
    if (hmac_ring_tx_enabled() != OAL_TRUE) {
        oam_warning_log0(0, 0, "{hmac_mcast_ampdu_user_init::return due to not support ring tx}");
        return;
    }
    mac_chip = hmac_res_get_mac_chip(mac_vap->uc_chip_id);
    if (mac_chip == NULL) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_mcast_ampdu_user_init::mac_chip null.}");
        return;
    }
    /* 组播用户也申请lut index */
    if (hmac_alloc_user_lut_index(hmac_user, mac_chip, MAC_AP_TYPE_NORMAL) != OAL_SUCC) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_TX, "{hmac_mcast_ampdu_user_init::get multi user lut failed.}");
        return;
    }
    /* 组播用户也申请ml lut index */
    if (hmac_user_alloc_ml_lut(hmac_vap, hmac_user) != OAL_SUCC) {
        hmac_user_del_refresh_lut(mac_chip, hmac_user);
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_TX, "{hmac_mcast_ampdu_user_init::get multi user lut failed.}");
        return;
    }

    /* 配置lut index，同步到device */
    *lut_idx = hmac_user->lut_index;
    *ml_lut_idx = hmac_user->ml_user_lut_idx;
}

void hmac_add_multi_user_mcast_ampdu_user_init(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user,
    mac_cfg_add_vap_param_stru *pst_param)
{
    uint8_t lut_index = WLAN_ASSOC_USER_MAX_NUM;
    uint8_t ml_lut_idx = WLAN_ASSOC_USER_MAX_NUM;
    if (mac_vap == NULL || hmac_user == NULL || pst_param == NULL) {
        return;
    }

    if (mac_vap->bit_support_mcast_ampdu == OAL_FALSE || hmac_user->st_user_base_info.en_is_multi_user == OAL_FALSE) {
        return;
    }
    hmac_mcast_ampdu_user_init(mac_vap, hmac_user, &lut_index, &ml_lut_idx);
    pst_param->multi_user_lut_idx = lut_index;
    pst_param->multi_user_ml_lut_idx = (ml_lut_idx & 0x3f); /* 3f:6个bit */
    hmac_ba_info_init(hmac_user);

    oam_warning_log3(mac_vap->uc_vap_id, 0,
        "{MCAST_AMPDU::hmac_mcast_ampdu_user_init::multi user[%u] lut[%u] ml_lut[%u].}",
        hmac_user->st_user_base_info.us_assoc_id, hmac_user->lut_index, hmac_user->ml_user_lut_idx);
}

void hmac_del_multi_user_mcast_ampdu_user_deinit(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user)
{
    mac_chip_stru *mac_chip = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    if (mac_vap == NULL || hmac_user == NULL) {
        return;
    }
    if (mac_vap->bit_support_mcast_ampdu == OAL_FALSE || hmac_user->st_user_base_info.en_is_multi_user == OAL_FALSE) {
        return;
    }
    mac_chip = hmac_res_get_mac_chip(mac_vap->uc_chip_id);
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (mac_chip == NULL || hmac_vap == NULL) {
        return;
    }
    oam_warning_log3(mac_vap->uc_vap_id, 0,
        "{MCAST_AMPDU::hmac_del_multi_user_mcast_ampdu_user_deinit::multi user[%u] lut[%u] ml_lut[%u].}",
        hmac_user->st_user_base_info.us_assoc_id, hmac_user->lut_index, hmac_user->ml_user_lut_idx);
    hmac_ba_info_deinit(hmac_user);
    hmac_user_del_refresh_lut(mac_chip, hmac_user);
    hmac_user_free_ml_lut(mac_vap, hmac_user, mac_chip, hmac_vap, hmac_user->st_user_base_info.us_assoc_id);
}

/* 如果组播聚合打开，则组播数据需要走tid3, 为了reorder处理，其余be帧走tid0,入参函数调用者保证有效性 */
void hmac_tx_classify_mcast_ampdu_tidno(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    uint8_t *tidno, mac_tx_ctl_stru *tx_ctl)
{
    if (hmac_vap->st_vap_base_info.bit_support_mcast_ampdu == OAL_FALSE) {
        return;
    }
    /* vap组播聚合开启后，该vap下的组播帧改为tid3 */
    if (mac_get_cb_is_mcast(tx_ctl) == OAL_TRUE) {
        *tidno = WLAN_TIDNO_MCAST_AMPDU;
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU_DEBUG
        oam_warning_log3(hmac_vap->st_vap_base_info.uc_vap_id, 0,
            "MCAST_AMPDU::hmac_tx_classify_mcast_ampdu_tidno alg[%u] tid[%u]->[%u]",
            mac_get_cb_alg_pktno(tx_ctl), *tidno, WLAN_TIDNO_MCAST_AMPDU);
#endif
        *tidno = WLAN_TIDNO_MCAST_AMPDU;
        return;
    }
    /* vap组播聚合开启后，该vap下的其他tid3的帧，更换成tid0 */
    if ((*tidno) == WLAN_TIDNO_ANT_TRAINING_LOW_PRIO) {
        *tidno = WLAN_TIDNO_BEST_EFFORT;
    }
}

uint32_t hmac_config_set_mcast_ampdu_tx_param(mac_vap_stru *mac_vap, mcast_ampdu_rate_stru *tx_param)
{
    uint32_t ret;
    if (mac_vap == NULL || tx_param == NULL) {
        return OAL_FAIL;
    }
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_SET_MCAST_AMPDU_TX_PARAM,
        sizeof(mcast_ampdu_rate_stru), (uint8_t *)tx_param);
    oam_warning_log4(mac_vap->uc_vap_id, 0, "hmac_config_set_mcast_ampdu_tx_param mcs[%u] bw[%u] aggr[%u] ret[%u]",
        tx_param->bit_rate_mcs, tx_param->bit_freq_bw, tx_param->aggr_num, ret);
    return ret;
}

#endif