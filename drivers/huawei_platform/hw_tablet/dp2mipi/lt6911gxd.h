/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * lt6911gxd.h
 *
 * lt6911gxd dp2mipi driver
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, pmicstributed, and mopmicfied under those terms.
 *
 * This program is pmicstributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#ifndef _LT6911GXD_H_
#define _LT6911GXD_H_

#include <linux/list.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/workqueue.h>
#include <linux/mutex.h>
#include <linux/leds.h>
#include <linux/types.h>

typedef struct led_classdev cdev_t;

#define LT6911GXD_FIRMWARE_UPDATE_DELAY 10000
#define LT6911GXD_FIRMWARE_UPDATE_DEFAULT_MODE 1
#define LT6911GXD_FIRMWARE_UPDATE_FIRST_ADDR 0x50

struct lt6911gxd_device {
	struct i2c_client *client;
	struct device *dev;
	cdev_t c_dev;
	struct mutex lock;
	int irq;

	int gpio_i_irq;
	int gpio_o_cc1;
	int gpio_i_hpd;
	int gpio_o_reset;
	int gpio_o_1v2_power;
	int gpio_o_3v3_power;
	int gpio_o_mux_sel;

	struct delayed_work fw_update_work;
	struct delayed_work get_dpin_hpd_status;

	int first_update_addr;
	int firmware_update_delay;
	int firmware_update_mode;
	int update_finished;

	uint32_t chip_version;
	uint32_t chip_video_int_type;
	uint32_t chip_pixel_clock;
	uint32_t chip_htotal;
	uint32_t chip_vtotal;
	uint32_t chip_hactive;
	uint32_t chip_vactive;
	uint32_t chip_audio_int_type;
	uint32_t chip_auido_fs_value;
	uint32_t chip_byte_clock;
	uint32_t chip_lane_nr;
	uint32_t chip_port_nr;
};

typedef enum {
	DP_IN_CHIP_ECODE_OK = 0,
	DP_IN_CHIP_ECODE_POWER_OFF,
	DP_IN_CHIP_ECODE_UPDAE_ING,
	DP_IN_CHIP_ECODE_PARA_INVALID,
	DP_IN_CHIP_ECODE_I2C_COMM,
} dp_in_chip_ecode;

typedef enum {
	PLUG_STATUS_EVENT,
	DP_MODE_EVENT,
	VIDEO_PARAMS_EVENT,
	ERROR_CODE_EVENT,
	DEVICE_SUPPORT_EVENT
} lt6911gxd_hal_event_type;

typedef enum {
	ERROR_CODE_OK,
	NO_SIGNAL,
	INVALID_STREAM_INFO
} lt6911gxd_hal_error_code;

typedef enum {
	STREAM_OFF,
	STREAM_ON,
	STREAM_INVALID,
	STREAM_VALID
} lt6911gxd_stream_status;

#endif