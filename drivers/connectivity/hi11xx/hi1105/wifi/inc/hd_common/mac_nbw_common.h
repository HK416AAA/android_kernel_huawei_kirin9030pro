/*
* Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
* 功能说明   : Hmac与Dmac公用的NBW变量
* 作者       : wifi
* 创建日期   : 2025年1月7日
*/
#ifndef MAC_NBW_COMMON_H
#define MAC_NBW_COMMON_H
/* 1 其他头文件包含 */
#include "oal_types.h"
#include "wlan_types.h"
#include "wlan_spec.h"
#include "mac_device_common.h"
#include "mac_user_common.h"
#include "mac_chba_common.h"

#ifdef _PRE_WLAN_FEATURE_NBW
#define MAC_NBW_ACTION_OUI_TYPE_LEN 4
#define MAC_NBW_ACTION_TYPE_LEN 5
#define MAC_NBW_ACTION_HDR_LEN 6
#define MAC_NBW_ATTR_ID_LEN 1
#define MAC_NBW_ATTR_HDR_LEN 2
#define MIN_TIMESLOT_BODY_LEN 4

#define TIMESLOT_REQ_BODY_LEN 17
#define TIMESLOT_REQ_SLAVEMAC_POS 2
#define TIMESLOT_REQ_SLAVEAP_RP_POS 8
#define TIMESLOT_REQ_SLOT_LEVEL 13
#define TIMESLOT_REQ_TIMEINTERVAL_POS 14

#define TIMESLOT_RSP_MIN_BODY_LEN 9
#define TIMESLOT_RSP_BODY_LEN 15
#define TIMESLOT_RSP_STATUS_POS 2
#define TIMESLOT_RSP_SLAVEMAC_POS 3
#define TIMESLOT_RSP_SLOT_LEVEL_POS 11
#define TIMESLOT_RSP_START_IDX_POS 12
#define TIMESLOT_RSP_END_IDX_POS 13
#define TIMESLOT_RSP_WORK_USLOT_IDX_POS 14

#define TIMESLOT_INDICATE_BODY_LEN_MIN 3
#define TIMESLOT_INDICATE_BODY_LEN 14
#define TIMESLOT_INDICATE_SLOT_LEVEL_POS 10
#define TIMESLOT_INDICATE_START_IDX_POS 11
#define TIMESLOT_INDICATE_END_IDX_POS 12
#define TIMESLOT_INDICATE_WORK_USLOT_POS 13
#define TIMESLOT_INDICATE_STATUS_POS 2
#define TIMESLOT_INDICATE_MASTERMAC_POS 3

#define TIMESLOT_REQ_AND_SYNC_LEN_MIN 8
#define TIMESLOT_REQ_AND_SYNC_TOTAL_USLOT_NUM_POS 6
#define TIMESLOT_REQ_AND_SYNC_TOTAL_LINK_CNT_POS 7
#define TIMESLOT_REQ_AND_SYNC_BASIC_TIMESLOT_LEN 9
#define TIMESLOT_REQ_AND_SYNC_USLOT_SHARED_POS 6
#define TIMESLOT_REQ_AND_SYNC_SLOT_PERIOD_POS 7
#define TIMESLOT_REQ_AND_SYNC_TIME_IBNTERVAL_POS 8

#define TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_BODY_LEN 13
#define TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_SLAVEMAC_POS 2
#define TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_SLOT_LEVEL 10
#define TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_START_IDX_POS 11
#define TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_END_IDX_POS 12
#define TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_FLAG_POS 8

#define TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_MIN_BODY_LEN 3
#define TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_BODY_LEN 14
#define TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_SLOT_LEVEL_POS 10
#define TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_START_IDX_POS 11
#define TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_END_IDX_POS 12
#define TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_WORK_USLOT_POS 13
#define TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_STATUS_POS 2

#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_BODY_LEN 7
#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_SLOT_LEVEL_POS 3
#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_START_IDX_POS 4
#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_END_IDX_POS 5
#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_WORK_USLOT_IDX_POS 6

#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_MIN_BODY_LEN 3
#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_BODY_LEN 8
#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_STATUS_POS 2
#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_SLOT_LEVEL_POS 4
#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_START_IDX_POS 5
#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_END_IDX_POS 6
#define TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_WORL_USLOT_POS 7

#define DOMAIN_MERGE_ACTION_MIN_LEN 1

#define TIMESLOT_ADJUST_INFORM_BORROW_REQ_BODY_LEN 11
#define TIMESLOT_ADJUST_INFORM_BORROW_REQ_SLAVEMAC_POS 2
#define TIMESLOT_ADJUST_INFORM_BORROW_REQ_WORK_USLOT_POS 8
#define TIMESLOT_ADJUST_INFORM_BORROW_REQ_OLD_WORK_USLOT_POS 9
#define TIMESLOT_ADJUST_INFORM_BORROW_REQ_DOMAIN_USLOT_POS 10
 
#define TIMESLOT_ADJUST_INFORM_BORROW_RESP_BODY_LEN 3
#define TIMESLOT_ADJUST_INFORM_BORROW_RESP_STATUS_POS 2
/* NBW demo 模式切换 */
#define MAC_NBW_MODE_SWITCH_ATTR_LEN 7 /* 包含属性头 */
#define MAC_NBW_MODE_SWITCH_FRAME_TYPE_POS 2 /* 模式切换帧类型位置 */
/* beacon帧相关 */
#define MAC_NBW_BEACON_ELEMENT_OFFSET 12 /* nbw Beacon固定字段长度 */
#define INVALID_TIMESLOT_USLOT_IDX 255
#define MAC_OUI_TYPE_NBW 0x88
#define MAC_NBW_VENDOR_EID 221
#define INVALID_USLOT_BITMAP 0
#define MAC_NBW_DOAMIN_HDR_LEN 4
#define MAC_NBW_ISLAND_HDR_LEN 3
#define MAC_NBW_SLOT_INFO_LEN 11
#define MAC_NBW_ISLAND_FLAG_LEN 1
#define MAC_NBW_ISLAND_RSV_LEN 1
#define MAC_NBW_TOPO_CHANGE_POS 1
#define MAC_NBW_SLOT_BITMAP_ALLOC_POS 2
#define NBW_BEACON_LINK_SLOT_INFO_POS 6
// link info attribute
#define MAC_NBW_LINK_CNT_LEN 1
#define MAC_NBW_LINK_INFO_RSSI_POS 2
#define MAC_NBW_LINK_INFO_SLAVE_LINK_CNT_POS 4 /* LINK INFO字段中slave link cnt偏移 */

#define FULL_USLOT_BITMAP (uint8_t)(0xFF)
#define NBW_USLOT0_1_BITMAP (uint8_t)(0x03)
#define NBW_USLOT2_3_BITMAP (uint8_t)(0x0C)
#define NBW_USLOT4_5_BITMAP (uint8_t)(0x30)
#define NBW_USLOT6_7_BITMAP (uint8_t)(0xC0)
#define NBW_0_1_WORK_BITMAP (uint32_t)(0x03030303)
#define NBW_2_3_WORK_BITMAP (uint32_t)(0x0C0C0C0C)
#define NBW_4_5_WORK_BITMAP (uint32_t)(0x30303030)
#define NBW_6_7_WORK_BITMAP (uint32_t)(0xC0C0C0C0)
#ifdef _PRE_WLAN_NBW_DEMO
#define NBW_SLOT_BITMAP_1_LEVEL (uint32_t)(0x00000FFF)
#define NBW_SLOT_BITMAP_2_LEVEL (uint32_t)(0x00000555)
#define NBW_SLOT_BITMAP_3_LEVEL (uint32_t)(0x00000111)
#else
#define NBW_SLOT_BITMAP_1_LEVEL (uint16_t)(0x0FFF)
#define NBW_SLOT_BITMAP_2_LEVEL (uint16_t)(0x0555)
#define NBW_SLOT_BITMAP_3_LEVEL (uint16_t)(0x0001)
#endif
/* master beacon */
#define MAC_NBW_ATTR_RP_LEN 4
#define NBW_MASTER_BEACON_BASIC_INFO_LEN 4  /* rssi, 拓扑信息改变，已分配bitmap，域内岛数目 */
#define MAC_NBW_ISLAND_INFO_HEAD_LEN 10     /* slaveAp Mac, rp */
#define MAC_NBW_ISLAND_INFO_LEN 13
#define NBW_MASTER_BEACON_HDR_ISLAND_POS (MAC_NBW_DOAMIN_HDR_LEN + MAC_CHBA_ATTR_HDR_LEN)
#define NBW_MASTER_BEACON_ISLAND_NUM_POS 3
#define NBW_MASTER_BEACON_SLOT_NUM_POS 12

/* slaveAp beacon */
#define NBW_SLAVEAP_BEACON_BASIC_INFO_LEN 9 /* rssi, 拓扑信息改变，已分配bitmap，Master bssid */
#define NBW_SLAVEAP_BEACON_MASTER_MAC_POS 3
#define NBW_SLAVEAP_BEACON_ISLAND_FLAG_POS 9
#define NBW_SLAVEAP_BEACON_ISLAND_LINKCNT_POS 10
#define NBW_SLAVEAP_BEACON_ISLAND_SLOTINFO_POS 12
#define NBW_SLAVEAP_BEACON_HDR_SLOTINFO_POS (NBW_SLAVEAP_BEACON_ISLAND_SLOTINFO_POS + MAC_CHBA_ATTR_HDR_LEN)
/* slaveAp PNF */
#define MAC_NBW_LINK_INFO_LINK_CNT_POS 4 /* LINK INFO字段中link cnt偏移 */

/* MAC_NBW_ATTR_MASTER_INFO beacon attr id */
#define NBW_BEACON_MASTER_INFO_LEN 16 /* master info的长度，包含header头 */
#define NBW_BEACON_MASTER_INFO_ADDR_POS 2
#define NBW_BEACON_MASTER_INFO_SLOT_BITMAP_LEN 4

typedef enum {
    NBW_SLOT_LEVEL_1 = 0,
    NBW_SLOT_LEVEL_2 = 1,
    NBW_SLOT_LEVEL_3 = 2,

    NBW_SLOT_BITMAP_LEVEL_BUTT = 3
} nbw_slot_bitmap_level_enum; /* nbw slot bitmap档位枚举 */

typedef enum {
    MAC_NBW_BEACON_TYPE_BASIC = 0,
    MAC_NBW_BEACON_TYPE_DOMAIN_TOPO,    /* master发送全域拓扑 */
    MAC_NBW_BEACON_TYPE_ISLAND_TOPO,    /* slaveAp发送本岛拓扑 */
    MAC_NBW_BEACON_TYPE_MASTER_INDICATE,
    MAC_NBW_BEACON_TYPE_SLOT_ALLOC,
    MAC_NBW_BEACON_TYPE_SLOT_SWITCH,
    MAC_NBW_BEACON_TYPE_MASTER_SWITCH,
} hmac_nbw_beacon_type_enum;

#define MAC_NBW_USLOT_NUM (MAC_NBW_SLOT_DURATION / MAC_NBW_USLOT_DURATION)
#define MAC_NBW_SCHED_PERIOD 8
#ifdef _PRE_WLAN_NBW_DEMO
#define MAC_NBW_SLOT_DURATION 16
#define MAC_NBW_USLOT_DURATION 4
#else
#define MAC_NBW_SLOT_DURATION 8
#define MAC_NBW_USLOT_DURATION 1
#endif

#define MAC_NBW_DEFALUT_PERIODS_MS 128 /* NBW默认调度周期时长(ms) */

/* Timeslot neg ACTION帧subtype类型 */
typedef enum {
    MAC_NBW_TIMESLOT_NEG_REQUEST_ACTION = 0,
    MAC_NBW_TIMESLOT_NEG_RESPONSE_ACTION = 1,
    MAC_NBW_TIMESLOT_NEG_INDICATE_ACTION = 2,
    MAC_NBW_TIMESLOT_NEG_AND_SYNC_REQUEST_ACTION = 3,
    MAC_NBW_TIMESLOT_NEG_ACTION_SUBTYPE_BUTT,
} hmac_nbw_timeslot_neg_action_subtype_enum;

typedef enum {
    NBW_BITMAP_USLOT_0_1_LEVEL = 3,
    NBW_BITMAP_USLOT_2_3_LEVEL = 4,
    NBW_BITMAP_USLOT_4_5_LEVEL = 5,
    NBW_BITMAP_USLOT_6_7_LEVEL = 6,
} mac_nbw_bitmap_level_enum;
#ifdef _PRE_WLAN_NBW_DEMO
typedef struct {
    uint16_t user_idx; /* 指定user的user_idx */
    uint32_t bitmap;
} nbw_user_timeslot_bitmap_cfg_stru; /* nbw user级别bitmap配置结构体 */
#else
typedef struct {
    uint8_t uslot_bitmap;
    uint8_t work_uslot_bitmap;
    uint16_t slot_bitmap;
    uint8_t work_uslot_flag;
    uint8_t work_slot_flag;
} nbw_timeslot_bitmap_cfg_stru;

typedef struct {
    uint16_t user_idx;
    nbw_timeslot_bitmap_cfg_stru bitmap_info;
} nbw_user_timeslot_bitmap_cfg_stru;
#endif

/* Ranking Priority信息结构体 */
typedef struct {
    union {
        uint8_t value;
        struct {
            uint8_t hardware_capability : 2; /* 硬件规格，比如单双芯片 */
            uint8_t remain_power : 2; /* 剩余电量 */
            uint8_t device_type : 4; /* 设备类型: 例如PC、Pad等 */
        } dl;
    } device_level;
    uint8_t chba_version; /* 协议版本 */
    uint8_t link_cnt; /* 链路总数 */
    uint8_t ranking_id; /* 岛主根据rp值在域内的排名，由域主计算并宣告，排名从1开始按rp从大到小升序，1为默认值 */
} nbw_ranking_priority;

static inline uint8_t mac_nbw_bitmap_to_level(uint32_t bitmap)
{
    return (((bitmap) == NBW_0_1_WORK_BITMAP) ? NBW_BITMAP_USLOT_0_1_LEVEL : \
        ((bitmap) == NBW_2_3_WORK_BITMAP) ? NBW_BITMAP_USLOT_2_3_LEVEL : \
        ((bitmap) == NBW_4_5_WORK_BITMAP) ? NBW_BITMAP_USLOT_4_5_LEVEL : \
        ((bitmap) == NBW_6_7_WORK_BITMAP) ? NBW_BITMAP_USLOT_6_7_LEVEL : NBW_BITMAP_USLOT_0_1_LEVEL);
}

static inline uint32_t mac_nbw_level_to_bitmap(uint8_t level)
{
    return (((level) == NBW_BITMAP_USLOT_0_1_LEVEL) ? NBW_0_1_WORK_BITMAP : \
        ((level) == NBW_BITMAP_USLOT_2_3_LEVEL) ? NBW_2_3_WORK_BITMAP : \
        ((level) == NBW_BITMAP_USLOT_4_5_LEVEL) ? NBW_4_5_WORK_BITMAP : \
        ((level) == NBW_BITMAP_USLOT_6_7_LEVEL) ? NBW_6_7_WORK_BITMAP : 0);
}

static inline uint8_t mac_nbw_uslot_bitmap_to_level(uint8_t uslot_bitmap)
{
    return (((uslot_bitmap) == NBW_USLOT0_1_BITMAP) ? NBW_BITMAP_USLOT_0_1_LEVEL : \
        ((uslot_bitmap) == NBW_USLOT2_3_BITMAP) ? NBW_BITMAP_USLOT_2_3_LEVEL : \
        ((uslot_bitmap) == NBW_USLOT4_5_BITMAP) ? NBW_BITMAP_USLOT_4_5_LEVEL : \
        ((uslot_bitmap) == NBW_USLOT6_7_BITMAP) ? NBW_BITMAP_USLOT_6_7_LEVEL : NBW_BITMAP_USLOT_0_1_LEVEL);
}
#ifdef _PRE_WLAN_NBW_DEMO
static inline uint32_t mac_nbw_level_to_slot_bitmap(uint8_t slot_bitmap_level)
{
    return (((slot_bitmap_level) == NBW_SLOT_LEVEL_1) ? NBW_SLOT_BITMAP_1_LEVEL: \
        ((slot_bitmap_level) == NBW_SLOT_LEVEL_2) ? NBW_SLOT_BITMAP_2_LEVEL: \
        ((slot_bitmap_level) == NBW_SLOT_LEVEL_3) ? NBW_SLOT_BITMAP_3_LEVEL: 0);
}

static inline uint8_t mac_nbw_slot_bitmap_to_level(uint32_t slot_bitmap)
{
    return (((slot_bitmap) == NBW_SLOT_BITMAP_1_LEVEL) ? NBW_SLOT_LEVEL_1: \
        ((slot_bitmap) == NBW_SLOT_BITMAP_2_LEVEL) ? NBW_SLOT_LEVEL_2: \
        ((slot_bitmap) == NBW_SLOT_BITMAP_3_LEVEL) ? NBW_SLOT_LEVEL_3: NBW_SLOT_LEVEL_1);
}
#else
static inline uint16_t mac_nbw_level_to_slot_bitmap(uint8_t slot_bitmap_level)
{
    return (((slot_bitmap_level) == NBW_SLOT_LEVEL_1) ? NBW_SLOT_BITMAP_1_LEVEL: \
        ((slot_bitmap_level) == NBW_SLOT_LEVEL_2) ? NBW_SLOT_BITMAP_2_LEVEL: \
        ((slot_bitmap_level) == NBW_SLOT_LEVEL_3) ? NBW_SLOT_BITMAP_3_LEVEL: 0);
}

static inline uint8_t mac_nbw_slot_bitmap_to_level(uint16_t slot_bitmap)
{
    return (((slot_bitmap) == NBW_SLOT_BITMAP_1_LEVEL) ? NBW_SLOT_LEVEL_1: \
        ((slot_bitmap) == NBW_SLOT_BITMAP_2_LEVEL) ? NBW_SLOT_LEVEL_2: \
        ((slot_bitmap) == NBW_SLOT_BITMAP_3_LEVEL) ? NBW_SLOT_LEVEL_3: NBW_SLOT_LEVEL_1);
}
#endif
/* 先实现repeat的code */
static inline uint32_t mac_nbw_uslot_bitmap_to_bitmap(uint8_t uslot_bitmap)
{
    return uslot_bitmap | (uslot_bitmap << BIT_OFFSET_8) | (uslot_bitmap << BIT_OFFSET_16) |
        (uslot_bitmap << BIT_OFFSET_24);
}
#endif
#endif
