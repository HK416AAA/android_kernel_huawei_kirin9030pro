/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: nbw powersave
 * Author: wifi
 * Create: 2024-12-26
 */
#ifndef HMAC_NBW_PS_H
#define HMAC_NBW_PS_H

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_PS_H
#ifdef _PRE_WLAN_FEATURE_NBW
uint8_t hmac_nbw_calc_bitmap_by_unuseful_data(hmac_chba_user_throughput_stru *throughput_info,
    hmac_chba_user_stru *chba_user_info, uint8_t cur_bitmap_level);
uint8_t hmac_nbw_calc_bitmap_by_cnt(hmac_chba_user_stru *user_info, uint8_t cur_bitmap_level,
    hmac_chba_ps_throught_thres_stru *chba_thres);
uint8_t hmac_nbw_calc_bitmap_by_throughput(hmac_chba_vap_stru *vap_info, hmac_user_stru *hmac_user,
    hmac_chba_user_stru *nbw_user_info);
void hmac_nbw_sync_user_slot_bitmap_level_info(mac_vap_stru *mac_vap,
    hmac_user_stru *hmac_user, uint8_t tmp_bitmap_level);
void hmac_nbw_sync_user_slot_bitmap_level(hmac_vap_stru *hmac_vap,
    hmac_user_stru *hmac_user, uint8_t tmp_bitmap_level);
void hmac_nbw_update_throughput_info(hmac_chba_vap_stru *vap_info);
uint32_t hmac_nbw_update_user_slot_bitmap_level(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param);
#endif
#endif

