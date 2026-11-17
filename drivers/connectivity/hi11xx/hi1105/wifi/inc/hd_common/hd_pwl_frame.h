/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : pwl host/dev 共用帧体
 */
#ifndef HD_PWL_FRAME_H
#define HD_PWL_FRAME_H
#ifdef _PRE_WLAN_FEATURE_PWL

#define PWL_PN_LEN 16
#pragma pack(1)
typedef struct {
    uint16_t pc;
    uint8_t pn[PWL_PN_LEN];
} pwl_head_stru;
#pragma pack()

#endif
#endif