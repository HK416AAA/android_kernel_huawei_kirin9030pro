/*
 * echub_thermal.h
 *
 * thermal driver for echub
 *
 * Copyright (c) 2023-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef _LINUX_ECHUB_THERMAL_H
#define _LINUX_ECHUB_THERMAL_H

#define TEMP_WORK_SCHEDULE_PERIOD			1000
#define DECIMAL_MAGNIFICATION				1000
#define INVALID_VALUE					    0xFFFF

#define MFG_MODE_REG						0x0489
#define MFG_TEST_GET_REG					0x0488
#define MFG_TEST_SET_REG					0x0408
#define CONTINUOUS_TRIGGER_TIME				10

#define FAN_WORK_SCHEDULE_PERIOD			1000
#define FAN_SPEED_ACCURACY					100
#define FAN0_SPEED_REG						0x06A1
#define FAN1_SPEED_REG						0x06A2
#define TEMP_FILTER_COEFFICIENT				85

#define MAX_TEMP_SIZE						8

enum fan_temp_id {
	CPU_DTS_ID = 0,
	SOC_NTC_ID,
	AMB_NTC_ID,
	MAX_TEMP_ID,
};

enum adc_channel_id {
	HKADC_CH0 = 0,
	HKADC_CH1,
	HKADC_CH2,
	HKADC_CH3,
	HKADC_CH4,
	HKADC_CH5,
	HKADC_CH6,
	HKADC_CH7,
	MAX_HKADC_CHANNEL,
};

enum echub_fan_id {
	FAN_0 = 0,
	FAN_1,
	MAX_FAN_ID,
};

struct key_value_pair {
	int key;
	int value;
};

enum echub_pair_para_index {
	KEY_IDX = 0,
	VALUE_IDX,
	PAIR_PARA_IDX_SIZE,
};

struct temp_trigger_fallback {
	u8 temp_id;
	int temp_trigger;
	int temp_fallback;
};

enum echub_temp_para_index {
	TEMPID_IDX = 0,
	TRIGGER_IDX,
	FALLBACK_IDX,
	TEMP_PARA_IDX_SIZE,
};

int get_adc_channel_temp(int adc_channel);

u8 mfg_test_mode_get(void);
u8 temp_virtual_test_mode_get(void);
int temp_virtual_test_mode_set(u8 mode);
int temp_virtual_celsius_get(u8 temp_id);
int temp_virtual_celsius_set(u8 temp_id, int temp_value);

u8 fan_test_mode_get(void);
int fan_test_mode_set(u8 mode);
int fan_test_speed_get(u8 fan_id);
int fan_test_speed_set(u8 fan_id, int set_speed);

#endif