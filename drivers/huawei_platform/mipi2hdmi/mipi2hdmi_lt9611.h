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

#ifndef __MIPI2HDMI_LT9611_H__
#define __MIPI2HDMI_LT9611_H__

typedef enum fw_update_status {
    FW_UPDATE_STATUS_NOT_STARTED = 0,
    FW_UPDATE_STATUS_ONGOING,
    FW_UPDATE_STATUS_ONGOING_POWER_OFF,
    FW_UPDATE_STATUS_DONE
} FW_UPDATE_STATUS;

struct lt9611_fw_updater_data {
    int32_t (*set_update_status)(struct i2c_client *client, FW_UPDATE_STATUS status);
    int32_t (*power_on_sequence)(struct i2c_client *client);
    int32_t (*power_off_sequence)(struct i2c_client *client);
    int32_t (*reset_chip)(struct i2c_client *client, int32_t delay);
};

struct lt9611_fw_updater {
    char *chip_model;
    void (*update_firmware)(struct i2c_client *client, struct lt9611_fw_updater_data *pdata);
};

int32_t lt9611_register_fw_updater(struct lt9611_fw_updater *updater);
int32_t lt9611_unregister_fw_updater(struct lt9611_fw_updater *updater);

#endif