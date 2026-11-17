/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Data transmission API header file
 * Author: mpxx drivers
 */

#ifndef MPXX_DEV_H
#define MPXX_DEV_H

typedef void (*bfgn_read_data_callback_t)(const char *, uint16_t);

/**
 * @brief 写入数据到蓝牙模块
 *
 * @param data 需要写入的数据
 * @param data_len 数据长度
 *
 * @return int32_t 返回写入的字节数，若失败返回负值
 */
int32_t hw_bt_write(const char *data, int32_t data_len);

/**
 * @brief 写入数据到 SLE 模块
 *
 * @param data 需要写入的数据
 * @param data_len 数据长度
 *
 * @return int32_t 返回写入的字节数，若失败返回负值
 */
int32_t hw_sle_write(const char *data, int32_t data_len);

/**
 * @brief 注册蓝牙模块的读取回调函数
 *
 * @param callback 回调函数，用于处理读取到的数据
 *
 * @return void 无返回值
 */
void hw_bt_register_read_callback(bfgn_read_data_callback_t callback);

/**
 * @brief 注册 SLE 模块的读取回调函数
 *
 * @param callback 回调函数，用于处理读取到的数据
 *
 * @return void 无返回值
 */
void hw_sle_register_read_callback(bfgn_read_data_callback_t callback);

/**
 * @brief 获取蓝牙模块的状态
 *
 * @return int32_t 返回蓝牙模块的状态码, 0表示当前为关闭状态
 */
int32_t hw_get_bt_state(void);

/**
 * @brief 获取 SLE 模块的状态
 *
 * @return int32_t 返回 SLE 模块的状态码, 0表示当前为关闭状态
 */
int32_t hw_get_sle_state(void);

#endif /* MPXX_DEV_H */
