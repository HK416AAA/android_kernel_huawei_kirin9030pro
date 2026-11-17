/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Platform OAM Log Registration Header File
 * Author: plat drivers
 */

#ifndef MPXX_OAM_H
#define MPXX_OAM_H

#include <stdint.h>

typedef uint32_t (*plat_oam_save_handle)(uint32_t msg_type, uint8_t *buffer, uint32_t buf_len);

/**
 * @brief 注册一个日志保存处理函数
 *
 * @param handle 回调函数，用于处理保存操作
 *
 * @return void 无返回值
 */
void plat_oam_register_save_handle(plat_oam_save_handle handle);

#endif