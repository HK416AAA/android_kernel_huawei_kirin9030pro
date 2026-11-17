/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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

#ifndef __EDP_TS_KIT_H__
#define __EDP_TS_KIT_H__

/* edp tp safe rate ops, provide to lcd kit module register */
struct edp_tp_safe_rate_ops {
	void (*send_de_event)(int val, int panel_id);
};

/* TS sync */
#define NO_SYNC 0
#define SHORT_SYNC 5

enum lcd_kit_type {
    TS_GESTURE_FUNCTION,
};

/* TS Event */
enum lcd_kit_ts_pm_type {
    TS_BEFORE_SUSPEND = 0,
    TS_SUSPEND_DEVICE,
    TS_RESUME_DEVICE,
    TS_AFTER_RESUME,
    TS_EARLY_SUSPEND,
    TS_IC_SHUT_DOWN,
    TS_2ND_POWER_OFF,
    TS_BLOCK_TPRST,
    TS_UNBLOCK_TPRST
};

/* edp kit ops, provide to ts kit module register */
struct edp_ts_kit_ops {
    int (*edp_ts_power_notify)(enum lcd_kit_ts_pm_type type, int sync);
};

int edp_ts_kit_ops_register(struct edp_ts_kit_ops *ops);
int edp_ts_kit_ops_unregister(struct edp_ts_kit_ops *ops);
struct edp_ts_kit_ops *edp_ts_kit_get_ops(void);
int edp_tp_safe_rate_ops_register(struct edp_tp_safe_rate_ops *ops);
int edp_tp_safe_rate_ops_unregister(struct edp_tp_safe_rate_ops *ops);
struct edp_tp_safe_rate_ops *edp_tp_safe_rate_get_ops(void);
#endif