/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_smart_roam_dnn_model.h文件
 * 创建日期 : 2025年05月15日
 */
#ifndef HMAC_SMART_ROAM_DNN_MODEL_H
#define HMAC_SMART_ROAM_DNN_MODEL_H
#ifdef _PRE_WLAN_FEATURE_AI_WIFI_ROAM
uint32_t hmac_smart_roam_dnn_process(int32_t *input, uint8_t input_size, uint8_t batch_size, int32_t *output);
#endif
#endif
