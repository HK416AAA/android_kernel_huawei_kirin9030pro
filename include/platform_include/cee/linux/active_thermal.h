/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: ac_thermal_noise.h
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __ACTIVE_THERMAL_H_
#define __ACTIVE_THERMAL_H_
#include <linux/types.h>

enum NoiseLevel {
	NOISE_LEVEL_MILD = 0,
	NOISE_LEVEL_MODERATE,
	NOISE_LEVEL_SEVERE,
	NOISE_LEVEL_MAX,
};

enum NoiseType {
	NOISE_TYPE_NORMAL = 0,
	NOISE_TYPE_EXCESSIVE_MOTOR,
	NOISE_TYPE_EXCESSIVE_WIND,
	NOISE_TYPE_SCRATCHNOISE,
	NOISE_TYPE_SHAKE_NOISE,
	NOISE_TYPE_MAX,
};

enum NoiseHandleStrategy {
	NOISE_STRATEGY_STOP = 0,
	NOISE_STRATEGY_DECELERATE,
	NOISE_STRATEGY_MAX,
};

typedef struct {
	uint16_t type;   // Type of abnormal noise
	uint16_t level;  // Level of abnormal noise
	uint16_t strategy; // Strategy for fan control.
} AbnormalNoiseInfo;

enum ContextType {
	FAN_CONTEXT_NULL = 0,
	FAN_CONTEXT_FLIP,
	FAN_CONTEXT_SHAKE,
	FAN_CONTEXT_FALL,
	FAN_CONTEXT_MAX,
};

struct FanContext {
	enum ContextType type;
	long time; // fan context change time
};

int set_fan_context_type(enum ContextType type);
int set_ac_thermal_noise(AbnormalNoiseInfo *fan_noise_info);
#endif /* __ACTIVE_THERMAL_H_ */