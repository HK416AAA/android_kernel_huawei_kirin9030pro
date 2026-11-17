/* SPDX-License-Identifier: GPL-2.0 */
/*
 * serial_gauge.h
 *
 * serial gauge function interface
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#ifndef _SERIAL_GAUGE_H_
#define _SERIAL_GAUGE_H_

#include "serial_gauge_base.h"

#define SERIAL_GAUGE_BATTERY_INVALID   0
#define SERIAL_GAUGE_SELF_DEV_DEVICE_ID 3
#define SERIAL_GAUGE_SOC_LOG_MAX_LEN   1000

void serial_gauge_probe(struct i2c_client *i2c, struct mutex *rw_lock,
	struct device_node *np, int device_id);
void serial_gauge_shutdown(void);
void serial_gauge_remove(void);

int serial_gauge_log_data(char *buf, int size);
int serial_gauge_log_head(char *buf, int size);

int judge_upgrade_can_i2c(void);

int serial_gauge_set_vterm_dec(unsigned int nondc_volt_dec);

int serial_gauge_battery_cycle_clear(void);

#endif /* _SERIAL_GAUGE_H_ */