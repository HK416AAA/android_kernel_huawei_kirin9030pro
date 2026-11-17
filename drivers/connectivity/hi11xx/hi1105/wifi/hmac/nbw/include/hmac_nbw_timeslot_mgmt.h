/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: nbw timeslot mgmt and schedule
 * Author: wifi
 * Create: 2024-12-26
 */
#ifndef HMAC_NBW_TIMESLOT_MGMT_H
#define HMAC_NBW_TIMESLOT_MGMT_H

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_TIMESLOT_MGMT_H
#include "hmac_nbw_common.h"
#ifdef _PRE_WLAN_FEATURE_NBW
#define FOUR_LEVEL 4
#define EIGHT_LEVEL 8

#define NBW_TOTAL_SLOT_NUM 96
/* ACTION帧subtype类型 */
typedef enum {
    MAC_NBW_ACCEPT = 0,
    MAC_NBW_REJECT = 1,

    MAC_NBW_TIMESLOT_STATUS_BUTT,
} hmac_nbw_timeslot_status_enum;

typedef struct {
    uint8_t timeslot_alloced; /* 标识是否已有工作时隙，只有分配了工作时隙，才会置位 */
    uint8_t alloc_uslot_bitmap; /* 当前设备分配的uslot_bitmap，如果是多条链，则是取或 */
#ifdef _PRE_WLAN_NBW_DEMO
    uint32_t used_bitmap; /* 配置给固件的vap bitmap，由工作work_uslot_bitmap转换而来 */
#else
    uint8_t cur_slot_level;
    uint16_t cur_slot_bitmap; /* 当前设备工作的slot bitmap，如果是多条链，取最大的level */
#endif
    uint8_t domain_alloc_bitmap; /* 全域已分配的工作时隙 */
    uint8_t work_uslot_bitmap; /* 当前设备实际工作（借用）的uslot_bitmap，由alloc_uslot_bitmap和domain_alloc_bitmap计算而来 */
} hmac_nbw_timeslot_mgmt_stru;

extern hmac_nbw_timeslot_mgmt_stru g_nbw_timeslot_mgmt_info;
static inline hmac_nbw_timeslot_mgmt_stru *hmac_nbw_get_timeslot_mgmt_info(void)
{
    return &g_nbw_timeslot_mgmt_info;
}

static inline uint8_t hmac_nbw_get_timeslot_alloced(void)
{
    return g_nbw_timeslot_mgmt_info.timeslot_alloced;
}

static inline void hmac_nbw_set_timeslot_alloced(uint8_t val)
{
    g_nbw_timeslot_mgmt_info.timeslot_alloced = val;
}

static inline uint8_t hmac_nbw_get_used_uslot_bitmap(void)
{
    return g_nbw_timeslot_mgmt_info.alloc_uslot_bitmap;
}

static inline void hmac_nbw_resume_used_uslot_bitmap(uint8_t val)
{
    g_nbw_timeslot_mgmt_info.alloc_uslot_bitmap &= ~val;
}

static inline void hmac_nbw_resume_work_uslot_bitmap(uint8_t val)
{
    g_nbw_timeslot_mgmt_info.work_uslot_bitmap &= ~val;
}

static inline uint8_t hmac_nbw_get_work_uslot_bitmap(void)
{
    return g_nbw_timeslot_mgmt_info.work_uslot_bitmap;
}

static inline void hmac_nbw_set_work_uslot_bitmap(uint8_t val)
{
    g_nbw_timeslot_mgmt_info.work_uslot_bitmap = val;
}


static inline uint8_t hmac_nbw_get_available_uslot_bitmap(void)
{
    return g_nbw_timeslot_mgmt_info.domain_alloc_bitmap;
}

static inline void hmac_nbw_resume_uslot_bitmap(uint8_t val)
{
    g_nbw_timeslot_mgmt_info.domain_alloc_bitmap &= ~val;
}

static inline void hmac_nbw_set_alloc_uslot_bitmap(uint8_t val)
{
    g_nbw_timeslot_mgmt_info.domain_alloc_bitmap = val;
}

#ifdef _PRE_WLAN_NBW_DEMO
static inline uint32_t hmac_nbw_get_slot_bitmap(void)
{
    return g_nbw_timeslot_mgmt_info.used_bitmap;
}

static inline void hmac_nbw_set_slot_bitmap(uint32_t val)
{
    g_nbw_timeslot_mgmt_info.used_bitmap = val;
}
#else
static inline uint8_t hmac_nbw_get_slot_level(void)
{
    return g_nbw_timeslot_mgmt_info.cur_slot_level;
}

static inline void hmac_nbw_set_slot_level(uint8_t val)
{
    g_nbw_timeslot_mgmt_info.cur_slot_level = val;
}

static inline uint16_t hmac_nbw_get_cur_slot_bitmap(void)
{
    return g_nbw_timeslot_mgmt_info.cur_slot_bitmap;
}

static inline void hmac_nbw_set_cur_slot_bitmap(uint16_t val)
{
    g_nbw_timeslot_mgmt_info.cur_slot_bitmap = val;
}
#endif
void hmac_nbw_reset_timeslot_info(uint8_t work_mode);
uint8_t hmac_nbw_uslotbitmap_transform_timeinterval(uint8_t uslot_bitmap);
uint8_t hmac_nbw_timeslot_interval_transfrom(uint8_t timeslot_interval);
uint8_t hmac_nbw_convert_idx_to_uslotbitmap_level1(uint8_t start_idx, uint8_t end_idx);
hmac_nbw_uslot_info_stru hmac_nbw_calculate_uslotbitmap(uint8_t timeslot_interval);
void hmac_nbw_update_uslot_bitmap_for_slot_alloced(hmac_vap_stru *hmac_vap, hmac_nbw_slot_info_stru timeslot_info);
void hmac_nbw_set_uslot_bitmap(uint8_t val);
void hmac_nbw_update_uslot_bitmap_for_link_disconnect(uint8_t val);
uint8_t hmac_get_user_uslot_bitmap(hmac_user_stru *hmac_user);
uint32_t hmac_nbw_form_uslot_bitmap(uint8_t slot_level, uint8_t uslot_bitmap);
uint8_t hmac_nbw_get_new_slot_bitmap_level(mac_vap_stru *mac_vap);
void hmac_nbw_resume_timeslot_bitmap(hmac_nbw_uslot_info_stru uslot_info);
uint8_t hmac_nbw_calc_work_uslot(uint8_t link_alloc_uslot, uint8_t domain_alloc_uslot);
uint8_t hmac_nbw_calc_all_links_work_uslot(uint8_t local_alloc_uslot, uint8_t domain_alloc_uslot);
void hmac_nbw_set_available_uslot_bitmap(uint8_t val);
#endif
#endif

