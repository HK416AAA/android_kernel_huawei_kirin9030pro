/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025. All rights reserved.
 * 功能说明 : dmac/host共存模块共用结构体
 * 作    者 : y30060419
 * 创建日期 : 2025年4月16日
 */
#ifndef HD_BTCOEX_CFG_H
#define HD_BTCOEX_CFG_H

typedef enum {
    HAL_BTCOEX_PTA_UNSET = 0,                   /* wifi和BT仲裁策略未设置 */
    HAL_BTCOEX_PTA_TRX_SAME_TIME = 1,           /* wifi和BT收发同时 */
    HAL_BTCOEX_PTA_WIFI_RX_BT_TX_AFFECTED = 2,  /* wifi的接收和BT的发送不同时 */
    HAL_BTCOEX_PTA_WIFI_TX_BT_RX_AFFECTED = 3,  /* wifi的发送和BT的接收不同时 */
    HAL_BTCOEX_PTA_TIME_DIVISION = 4,           /* wifi和BT完全时分 */
    HAL_BTCOEX_PTA_RX_SAME_TIME = 5,            /* wifi和BT接收同时 */
    HAL_BTCOEX_PTA_NO_AFFECTED = 6,             /* wifi和BT完全空分 */

    HAL_BTCOEX_PTA_STRATEGY_BUTT
} hal_btcoex_ant_pta_strategy_enum;

typedef struct {
    uint8_t pta_strategy    :   4,
            is_shared_pll   :   4;
    uint8_t affect_bitmap;             /* W2G&B2G:bit0, W5G&B2G:bit1, W2G&B5G:bit2, W5G&B5G:bit3 */
} ant_cfg_stru;

#endif