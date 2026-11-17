/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
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
#ifndef __EDP_PANEL_DRV_H__
#define __EDP_PANEL_DRV_H__

#include "display_engine/display_engine_interface.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(array)	((sizeof(array)) / (sizeof(array[0])))
#endif
 
#define EDP_CMD_NAME_MAX 100
#define EARLY_POWER_ON_FILGER_MAX 3

#define GPIO_CHECK_TIMES 3
#define ESD_RECOVERY_MAX_COUNT 10
#define ESD_CHECK_MAX_COUNT 3
#define FPS_LEVEL_MAX 20

struct edp_ctl {
	uint32_t gpio_num;
	uint32_t value;
	uint32_t delayms;
};
 
struct edp_seq {
	int8_t num;
	struct edp_ctl *ctls;
};

struct edp_esd {
	uint8_t enable;
	uint32_t gpio_detect_num;
	uint32_t gpio_normal_value;
};

struct fps_list_info {
	uint32_t fps_list_num;
	uint32_t fps_list[FPS_LEVEL_MAX];
};

struct s4_power_off_info {
	bool support;
	uint32_t gpio_bkl;
	uint32_t gpio_vdd;
};

struct edp_drv_info {
    uint32_t power_status;
    uint32_t port_id;
    uint32_t bl_max;
    uint32_t bl_min;
    uint32_t maxluminance;
    uint32_t minluminance;
    uint32_t afr_support;
	uint32_t jank_last_bl_level;
	uint8_t is_part_update_support;
	uint16_t vendor;
    uint16_t version;
    uint32_t sn_code;
	struct edp_esd esd;
    struct edp_seq *power_on;
	struct edp_seq *bkl_on;
	struct edp_seq *power_off;
	struct edp_seq *bkl_off;
	bool early_power_on_support;
	uint32_t early_power_on_gpio_filter[EARLY_POWER_ON_FILGER_MAX];
	uint32_t oled_type;
	uint32_t current_fps;
	uint32_t default_fps;
	struct fps_list_info fps_list;
	struct s4_power_off_info s4_power_off_list;
};

/* power sequece */
enum edp_power_sequece {
	EDP_POWER_NONE,
	EDP_POWER_ON_SEQ,
	EDP_BKL_ON_SEQ,
	EDP_POWER_ON,
	EDP_BKL_OFF_SEQ,
	EDP_POWER_OFF_SEQ,
	EDP_POWER_OFF,
};

struct edp_array_data {
	uint32_t *buf;
	int cnt;
};

enum oled_type {
	LTPS,
	LTPO,
};
 
enum ltpo_version {
	LTPO_V1,
	LTPO_V2,
};

enum {
	DIMMING_SEQ_120HZ_INDEX = 0,
	DIMMING_SEQ_90HZ_INDEX = 1,
	DIMMING_SEQ_60HZ_INDEX = 2,
};

bool edp_get_panel_on_state(void);
uint32_t get_edp_port_id(void);
struct edp_drv_info* get_edp_drv_info(void);
uint32_t get_edp_afr_support_mode(void);
int32_t get_edp_tp_support_mode(struct edp_tp_safe *tp_safe);
#endif /* EDP_PANEL_DRV_H */