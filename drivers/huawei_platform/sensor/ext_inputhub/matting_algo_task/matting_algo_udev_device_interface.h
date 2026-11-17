/* Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * All rights reserved.
 * Description: Creating File Nodes and Interfaces in udev
 * Author: yangxiaopeng@huawei.com
 * Create: 2024-9-9
 */
#ifndef MATTING_ALGO_UDEV_DEVICE_INTERFACE_H
#define MATTING_ALGO_UDEV_DEVICE_INTERFACE_H

#include <linux/types.h>
#include <linux/fs.h>

void matting_algo_udev_device_init(void);
ssize_t matting_algo_als_param_read(struct file *file, char __user *buf, size_t count, loff_t *pos);
ssize_t matting_algo_als_param_write(struct file *file, const char __user *data, size_t len, loff_t *ppos);
void matting_algo_set_lux_value(uint32_t lux_value);
ssize_t matting_algo_lux_value_read(struct file *file, char __user *buf, size_t count, loff_t *pos);
ssize_t matting_algo_lux_value_write(struct file *file, const char __user *data, size_t len, loff_t *ppos);
ssize_t matting_algo_log_check_control_read(struct file *file, char __user *buf, size_t count, loff_t *pos);
ssize_t matting_algo_log_check_control_write(struct file *file, const char __user *data, size_t len, loff_t *ppos);
ssize_t matting_algo_crop_check_control_read(struct file *file, char __user *buf, size_t count, loff_t *pos);
ssize_t matting_algo_crop_check_control_write(struct file *file, const char __user *data, size_t len, loff_t *ppos);
#endif
