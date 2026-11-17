/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : CHBA 信道序列文件
 * 作    者 :
 * 创建日期 : 2022年3月24日
 */

#ifdef _PRE_WLAN_CHBA_MGMT
#include "oal_ext_if.h"
#include "oam_ext_if.h"

#include "hmac_chba_function.h"
#include "hmac_chba_frame.h"
#include "hmac_chba_sync.h"
#include "hmac_chba_chan_switch.h"
#include "hmac_config.h"
#include "hmac_chba_coex.h"
#include "hmac_chba_channel_sequence.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_CHBA_CHANNEL_SEQUENCE_C

static uint32_t chba_channel_seq_level_to_bitmap(uint32_t level)
{
    uint32_t chba_channel_seq_level_to_bitmap_table[CHBA_CHANNEL_SEQ_LEVEL_BUTT] = {
        CHBA_CHANNEL_SEQ_BITMAP_25_PERCENT,
        CHBA_CHANNEL_SEQ_BITMAP_50_PERCENT,
        CHBA_CHANNEL_SEQ_BITMAP_75_PERCENT
    };

    if (level >= CHBA_CHANNEL_SEQ_LEVEL_BUTT) {
        return CHBA_CHANNEL_SEQ_BITMAP_100_PERCENT;
    }
    return chba_channel_seq_level_to_bitmap_table[level];
}

/* 配置 信道序列 bitmap */
void hmac_chba_set_channel_seq_bitmap(hmac_chba_vap_stru *chba_vap_info, uint32_t channel_seq_bitmap)
{
    chba_vap_info->channel_sequence_bitmap = channel_seq_bitmap;
}

/* 配置CHBA第一工作信道 */
static void hmac_chba_set_first_work_channel(hmac_chba_vap_stru *chba_vap_info, mac_channel_stru *first_work_channel)
{
    chba_vap_info->work_channel = *first_work_channel;
}

/* 配置CHBA第二工作信道 */
static void hmac_chba_set_sec_work_channel(hmac_chba_vap_stru *chba_vap_info, mac_channel_stru *sec_work_channel)
{
    chba_vap_info->second_work_channel = *sec_work_channel;
}


/* 判断是否是单CHBA VAP工作 */
static oal_bool_enum_uint8 mac_device_is_single_chba_up(mac_device_stru *mac_device)
{
    uint8_t vap_idx;

    for (vap_idx = 0; vap_idx < mac_device->uc_vap_num; vap_idx++) {
        mac_vap_stru *mac_vap = NULL;
        mac_vap = mac_res_get_mac_vap(mac_device->auc_vap_id[vap_idx]);
        if (oal_unlikely(mac_vap == NULL)) {
            oam_error_log1(0, OAM_SF_ANY, "vap is null! vap id is %d",
                mac_device->auc_vap_id[vap_idx]);
            continue;
        }
        if (!mac_is_chba_mode(mac_vap) && mac_vap_is_up(mac_vap)) {
            return OAL_FALSE;
        }
    }
    return OAL_TRUE;
}


/*
 * 函数名:hmac_chba_set_channel_seq_params
 * 功能:设置CHBA 信道序列参数
 */
uint32_t hmac_chba_set_channel_seq_params(mac_vap_stru *mac_vap, uint32_t *params)
{
    uint32_t channel_seq_bitmap;
    oal_bool_enum_uint8 is_single_chba_up;
    hmac_chba_vap_stru *chba_vap_info = NULL;
    mac_device_stru *mac_device = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    struct chba_channel_sequence_params channel_seq_params;

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_CHBA, "{hmac_chba_set_channel_seq_params:fail to get hmac_vap}");
        return OAL_FAIL;
    }
    chba_vap_info = hmac_chba_get_chba_vap_info(hmac_vap);
    if (chba_vap_info == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_CHBA, "{hmac_chba_set_channel_seq_params:not chba vap!}");
        return OAL_FAIL;
    }

    channel_seq_params.data.test_params.channel_seq_level = params[0];  // 0: test cmd 0
    channel_seq_params.data.test_params.first_work_channel = params[1]; // 1: test cmd 1
    channel_seq_params.data.test_params.sec_work_channel = params[2];   // 2: test cmd 2
    /* 根据信道序列等级, 配置channle_sequenc_bitmap */
    channel_seq_bitmap = chba_channel_seq_level_to_bitmap(channel_seq_params.data.test_params.channel_seq_level);
    hmac_chba_set_channel_seq_bitmap(chba_vap_info, channel_seq_bitmap);

    /* 单CHBA vap工作场景，才能配置STA 工作信道 */
    mac_device = mac_res_get_mac_dev();
    is_single_chba_up = mac_device_is_single_chba_up(mac_device);
    if (is_single_chba_up == OAL_TRUE) {
        /* 单CHBA场景，根据命令信道参数构造工作信道结构体 */
        mac_channel_stru tmp_channel = chba_vap_info->work_channel;

        /* 配置social channel 和工作信道 */
        tmp_channel.uc_chan_number = channel_seq_params.data.test_params.first_work_channel;
        if (mac_get_channel_idx_from_num(tmp_channel.en_band, tmp_channel.uc_chan_number,
            tmp_channel.ext6g_band, &tmp_channel.uc_chan_idx) == OAL_SUCC) {
            hmac_config_chba_social_channel(hmac_vap, chba_vap_info, &tmp_channel, CHBA_INVALID_SWITCH_CHAN_SLOT_IDX);
            hmac_chba_set_first_work_channel(chba_vap_info, &tmp_channel);
        }

        /* 配置CHBA第二工作信道 */
        tmp_channel.uc_chan_number = channel_seq_params.data.test_params.sec_work_channel;
        if (mac_get_channel_idx_from_num(tmp_channel.en_band, tmp_channel.uc_chan_number,
            tmp_channel.ext6g_band, &tmp_channel.uc_chan_idx) == OAL_SUCC) {
            hmac_chba_set_sec_work_channel(chba_vap_info, &tmp_channel);
        }
    }

    oam_warning_log4(mac_vap->uc_vap_id, OAM_SF_CHBA,
        "hmac_chba_set_channel_seq_params: level %d, bitmap 0x%08x, first_work_channel %d, sec_work_channel %d",
        channel_seq_params.data.test_params.channel_seq_level,
        chba_vap_info->channel_sequence_bitmap,
        chba_vap_info->work_channel.uc_chan_number,
        chba_vap_info->second_work_channel.uc_chan_number);

    /* 更新信道序列参数后，更新beacon/pnf下发到device */
    hmac_chba_save_update_beacon_pnf(hmac_chba_sync_get_domain_bssid());

    return OAL_SUCC;
}

uint32_t hmac_chba_update_channel_seq_params_proc(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param)
{
    struct chba_channel_sequence_params *channel_seq_params = NULL;
    hmac_chba_vap_stru *chba_vap_info = NULL;
    mac_channel_stru *sec_channel = NULL;
    mac_channel_stru *work_channel = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    uint32_t channel_seq_bitmap;
    chba_chan_seq_cfg_type_enum chba_chan_seq_cfg;
    if (mac_is_chba_mode(mac_vap) == OAL_FALSE) {
        oam_error_log0(0, OAM_SF_CHBA, "{hmac_chba_update_channel_seq_params_proc:not chba mode!}");
        return OAL_FAIL;
    }
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    chba_vap_info = hmac_chba_get_chba_vap_info(hmac_vap);
    if (chba_vap_info == NULL) {
        return OAL_FAIL;
    }

    channel_seq_params = (struct chba_channel_sequence_params *)param;

    channel_seq_bitmap = channel_seq_params->data.sync_info_params.channel_seq_bitmap;
    work_channel = &(channel_seq_params->data.sync_info_params.work_channel);
    sec_channel = &(channel_seq_params->data.sync_info_params.sec_work_channel);
    chba_chan_seq_cfg = channel_seq_params->chba_chan_seq_cfg_type;
    
    hmac_chba_set_channel_seq_bitmap(chba_vap_info, channel_seq_bitmap);
    hmac_chba_set_first_work_channel(chba_vap_info, work_channel);
    hmac_chba_set_sec_work_channel(chba_vap_info, sec_channel);
    oam_warning_log4(mac_vap->uc_vap_id, OAM_SF_CHBA,
        "hmac_chba_update_channel_seq_params_proc: level %d, bitmap:0x%08x, fir_work_channel %d, sec_work_channel %d",
        channel_seq_params->data.test_params.channel_seq_level,
        chba_vap_info->channel_sequence_bitmap,
        chba_vap_info->work_channel.uc_chan_number,
        chba_vap_info->second_work_channel.uc_chan_number);
    /* 更新信道序列参数后，更新beacon/pnf */
    hmac_chba_save_update_beacon_pnf(hmac_chba_sync_get_domain_bssid());
    return OAL_SUCC;
}
#endif /* _PRE_WLAN_CHBA_MGMT */
