/* Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * All rights reserved.
 * Description: Interface between the matting algo module and ALSC module for calculating noise
 * Author: yangxiaopeng@huawei.com
 * Create: 2024-4-26
 */

#ifndef MATTING_ALGO_HISI_ALSC_INTERFACE_H
#define MATTING_ALGO_HISI_ALSC_INTERFACE_H

#include "als_matting_algo_info.h"

void matting_algo_als_alsc_expand_status_config(void);
void matting_algo_send_alsc_bl_param(uint32_t brightness);
void matting_algo_clear_bl_param_old(void);
void matting_algo_clear_als_noise_old(void);
#endif