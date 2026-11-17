/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_dnn_model.c文件
 * 创建日期 : 2025年05月15日
 */
#ifdef _PRE_WLAN_FEATURE_AI_WIFI
#include "hmac_dnn_model.h"
#include "oal_mm.h"
void hmac_dnn_model_relu_activate_func(int64_t *input, uint8_t input_size, int64_t *output, uint8_t *output_size)
{
    uint8_t index;
    for (index = 0; index < input_size; index++) {
        output[index] = (input[index] < 0) ? 0 : input[index];
    }
    *output_size = input_size;
    return;
}
void hmac_dnn_model_softmax_activate_func(int64_t *input, uint8_t input_size, int64_t *output, uint8_t *output_size)
{
    uint8_t index;
    uint8_t max_index = 0;
    int64_t max_input = input[0];
    for (index = 1; index < input_size; index++) {
        if (input[index] > max_input) {
            max_index = index;
            max_input = input[index];
        }
    }
    *output = max_index;
    *output_size = 1;
    return;
}
OAL_STATIC uint8_t hmac_dnn_find_max_dimension_size(hmac_dnn_model_param_stru *model_param, uint8_t layer_size)
{
    uint8_t layer_index;
    uint8_t max_dimension_size = 0;
    for (layer_index = 0; layer_index < layer_size; layer_index++) {
        if (max_dimension_size < model_param[layer_index].input_size) {
            max_dimension_size = model_param[layer_index].input_size;
        }
        if (max_dimension_size < model_param[layer_index].output_size) {
            max_dimension_size = model_param[layer_index].output_size;
        }
    }
    return max_dimension_size;
}
OAL_STATIC void hmac_dnn_switch_input_output_ptr(int64_t **input, int64_t **output)
{
    int64_t *temp = *input;
    *output = *input;
    *input = temp;
}
OAL_STATIC void hmac_dnn_quant_input(int64_t *input, int64_t* output, uint8_t size,
    hmac_dnn_quant_param_stru *quant_param)
{
    uint8_t index;
    int8_t offest = quant_param->quant_offest;
    int64_t scale = quant_param->quant_scale;
    for (index = 0; index < size; index++) {
        output[index] = input[index] * scale + offest;
    }
    return;
}
OAL_STATIC void hmac_dnn_dequant_input(int64_t *input, int64_t* output, uint8_t size,
    hmac_dnn_quant_param_stru *quant_param)
{
    uint8_t index;
    int64_t scale = quant_param->dequant_scale;
    for (index = 0; index < size; index++) {
        output[index] = input[index] * scale;
    }
    return;
}
OAL_STATIC void hmac_dnn_model_input_transform(int32_t *ori_input, int64_t *input, uint8_t size)
{
    uint8_t index;
    for (index = 0; index < size; index++) {
        input[index] = (int64_t)ori_input[index];
    }
    return;
}
OAL_STATIC uint32_t hmac_dnn_model_prepare_input(hmac_dnn_model_inference_param_stru *inference,
    int64_t **input, int64_t **output)
{
    uint8_t max_dimension_size;
    max_dimension_size = hmac_dnn_find_max_dimension_size(inference->model_param, inference->layer_size);
    if (max_dimension_size == 0) {
        return OAL_FAIL;
    }
    *input = oal_memalloc(sizeof(int64_t) * max_dimension_size);
    if (*input == NULL) {
        return OAL_FAIL;
    }
    *output = oal_memalloc(sizeof(int64_t) * max_dimension_size);
    if (*output == NULL) {
        oal_free(*input);
        return OAL_FAIL;
    }
    (void)memset_s(*input, sizeof(int64_t) * max_dimension_size, 0, sizeof(int64_t) * max_dimension_size);
    (void)memset_s(*output, sizeof(int64_t) * max_dimension_size, 0, sizeof(int64_t) * max_dimension_size);
    return OAL_SUCC;
}
OAL_STATIC void hmac_dnn_model_matrix_mul(hmac_dnn_model_param_stru *model_param, int64_t *input, int64_t *output)
{
    uint8_t row, col;
    int64_t temp_val;
    int32_t *bias = model_param->bias_param;
    uint8_t output_size = model_param->output_size;
    int32_t *weight = NULL;
    int8_t *weight_quant = NULL;
    for (row = 0; row < output_size; row++) {
        temp_val = 0;
        for (col = 0; col < model_param->input_size; col++) {
            if (model_param->is_quant_flag != OAL_TRUE) {
                weight = (int32_t *)model_param->weight_param;
                temp_val += input[col] * weight[col * output_size + row]; // 后续优化矩阵乘法
            } else {
                weight_quant = model_param->weight_param;
                temp_val += input[col] * weight_quant[col * output_size + row];
            }
        }
        if (model_param->is_quant_flag != OAL_TRUE) {
            temp_val /= HMAC_DNN_MODEL_SHIFT; // 输入做了左移10位处理，这里移回去
        }
        temp_val += bias[row];
        output[row] = temp_val;
    }
    return;
}

uint32_t hmac_dnn_model_process(hmac_dnn_model_inference_param_stru *inference)
{
    uint8_t batch_index, layer_index;
    int64_t *input = NULL;
    int64_t *output = NULL;
    hmac_dnn_model_param_stru *model_param = NULL;
    uint8_t tmp_dim_size;
    int32_t *model_output = NULL;
    if (inference == NULL || inference->model_param == NULL || inference->quant_param == NULL ||
        inference->input == NULL || inference->output == NULL) {
        return OAL_FAIL;
    }
    if (hmac_dnn_model_prepare_input(inference, &input, &output) != OAL_SUCC) {
        return OAL_FAIL;
    }
    model_output = inference->output;
    for (batch_index = 0; batch_index < inference->batch_size; batch_index++) {
        tmp_dim_size = inference->input_size;
        hmac_dnn_model_input_transform(&(inference->input[batch_index * tmp_dim_size]), input, tmp_dim_size);
        for (layer_index = 0; layer_index < inference->layer_size; layer_index++) {
            model_param = &(inference->model_param[layer_index]);
            if (tmp_dim_size != model_param->input_size) {
                oal_free(input);
                oal_free(output);
                return OAL_FAIL;
            }
            // 量化
            if (model_param->is_quant_flag == OAL_TRUE) {
                hmac_dnn_quant_input(input, output, model_param->input_size, &(inference->quant_param[layer_index]));
                hmac_dnn_switch_input_output_ptr(&input, &output);
            }
            // 矩阵乘
            hmac_dnn_model_matrix_mul(model_param, input, output);
            // 反量化
            if (model_param->is_quant_flag == OAL_TRUE) {
                hmac_dnn_dequant_input(output, input, model_param->output_size, &(inference->quant_param[layer_index]));
                hmac_dnn_switch_input_output_ptr(&input, &output);
            }
            // 激活函数
            model_param->activate_func(output, model_param->output_size, input, &tmp_dim_size);
        }
        if (tmp_dim_size == 1) {
            model_output[batch_index] = (int32_t)(input[0]);
        }
    }
    oal_free(input);
    oal_free(output);
    return OAL_SUCC;
}
#endif