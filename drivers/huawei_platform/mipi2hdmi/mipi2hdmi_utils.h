/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __MIPI2HDMI_UTILS_H__
#define __MIPI2HDMI_UTILS_H__

#include <linux/device.h>
#include <linux/i2c.h>
#include <linux/gpio.h>
#include <linux/regulator/consumer.h>
#include <linux/regulator/driver.h>
#include <linux/regulator/machine.h>

#define MAX_EDID_BLOCK_NUM 8
#define EDID_BLOCK_LENGTH 128
#define MAX_RETRY_TIMES 3
#define EDID_READ_RETRY_INTERVAL 10
#define EDID_HEADER_LEN 8

typedef enum gpio_direction {
    GPIO_DIRECTION_INPUT = 0,
    GPIO_DIRECTION_OUTPUT
} GPIO_DIRECTION;

int32_t mipi2hdmi_regulator_init(struct device *dev, const char *id, uint32_t mvolt, struct regulator **ldo);
int32_t mipi2hdmi_gpio_init(struct device *dev, const char *id, GPIO_DIRECTION dir,
    int32_t out_init_val, uint32_t *gpio);
int32_t mipi2hdmi_i2c_send_byte(struct i2c_client *client, uint8_t regoffset, uint8_t value);
int32_t mipi2hdmi_i2c_recv_byte(struct i2c_client *client, uint8_t regoffset, uint8_t *value);
int32_t mipi2hdmi_i2c_recv_nbytes(struct i2c_client *client, uint8_t regoffset, uint8_t *data_array, uint8_t len);
int32_t mipi2hdmi_check_edid(uint8_t *edid, uint32_t edid_len);

#endif