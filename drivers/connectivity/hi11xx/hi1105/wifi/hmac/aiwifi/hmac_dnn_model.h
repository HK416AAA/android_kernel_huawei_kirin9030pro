/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_dnn_model.h文件
 * 创建日期 : 2025年05月15日
 */
#ifndef HMAC_DNN_MODEL_H
#define HMAC_DNN_MODEL_H
#ifdef _PRE_WLAN_FEATURE_AI_WIFI
#include "oal_util.h"
#include "oam_ext_if.h"
#define HMAC_DNN_MODEL_SHIFT 1024
typedef void (*hmac_dnn_model_activate_func)(int64_t *input, uint8_t input_size, int64_t *output, uint8_t *output_size);
typedef struct {
    int32_t quant_offest;
    int32_t quant_scale;
    int32_t dequant_scale;
} hmac_dnn_quant_param_stru;
typedef struct {
    uint8_t is_quant_flag;
    uint8_t input_size;
    uint8_t output_size;
    int8_t* weight_param;
    int32_t* bias_param;
    hmac_dnn_model_activate_func activate_func;
} hmac_dnn_model_param_stru;
typedef struct {
    hmac_dnn_model_param_stru *model_param;
    hmac_dnn_quant_param_stru *quant_param;
    int32_t *input;
    int32_t *output;
    size_t layer_size;
    size_t input_size;
    size_t batch_size;
} hmac_dnn_model_inference_param_stru;
uint32_t hmac_dnn_model_process(hmac_dnn_model_inference_param_stru *inference);
void hmac_dnn_model_relu_activate_func(int64_t *input, uint8_t input_size, int64_t *output, uint8_t *output_size);
void hmac_dnn_model_softmax_activate_func(int64_t *input, uint8_t input_size, int64_t *output, uint8_t *output_size);
#endif
#endif