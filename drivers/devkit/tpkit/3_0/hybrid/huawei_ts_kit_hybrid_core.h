/* SPDX-License-Identifier: GPL-2.0 */
/*
 * huawei_ts_kit_hybrid_core.h
 *
 * head file for hybrid ts core
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

#ifndef __TS_KIT_HYBRID_CORE_H_
#define __TS_KIT_HYBRID_CORE_H_
#include <linux/wait.h>
#include "huawei_ts_kit.h"

/* ts hybrid switch command list */
enum ts_kit_hybrid_cmd {
	TS_KIT_HYBRID_SUSPEND,
	TS_KIT_HYBRID_RESUME,
	TS_KIT_HYBRID_IDLE,

	TS_KIT_HYBRID_NORMAL_TO_MCU,
	TS_KIT_HYBRID_IDLE_TO_MCU,
	TS_KIT_HYBRID_SLEEP_TO_MCU,

	TS_KIT_HYBRID_NORMAL_TO_AP,
	TS_KIT_HYBRID_IDLE_TO_AP,
	TS_KIT_HYBRID_SLEEP_TO_AP,
	TS_KIT_HYBRID_QUCIK_ON,
	/* check ts_kit_hybrid_switch_control when add enum */
	TS_KIT_HYBRID_INVALID_CMD,
};

struct ts_hybrid_chip_ops {
	int (*hybrid_suspend)(void);
	int (*hybrid_resume)(void);
	int (*hybrid_idle)(void);
	void (*hybrid_get_mode)(int mode);
	void (*hybrid_before_suspend)(void);
};

#define MAX_I2C_DEV_NUM 2
struct ts_hybrid_ctrl {
	/* lock for hybrid ts cmd */
	struct mutex ts_lock;
	struct hybrid_sw_ops *input_sw_ops;
	/* lock for enable/disable ts irq */
	struct mutex irq_lock;
	u8 enable_irq_depth;
	u8 power_resp_state;
	/* lock for devices ops */
	struct mutex chip_ops_lock;
	wait_queue_head_t resp_wait;
	struct ts_hybrid_chip_ops *chip_ops[MAX_I2C_DEV_NUM];
};

void ts_kit_hybrid_switch_control_func(struct ts_cmd_node *proc_cmd,
	struct ts_cmd_node *out_cmd, struct ts_cmd_sync *sync);

/*
 * process ts hybrid control command
 * @param proc_cmd the switch command to process
 */
void ts_kit_hybrid_switch_control(struct ts_cmd_node *proc_cmd);

/*
 * initialize the ts hybrid
 */
void ts_kit_hybrid_init(void);

/*
 * release the ts hybrid
 */
void ts_kit_hybrid_release(void);

/*
 * request i2c switch
 * @param value 0 for release i2c, 1 for request i2c.
 * return 0 for success
 */
int hybrid_i2c_request(int value);

/*
 * check if AP hold i2c
 * @return true for i2c at AP, false otherwise.
 */
bool hybrid_i2c_check(void);

/*
 * send a hybrid ts command
 * @param sub_cmd hybrid command to process
 */
void send_hybrid_ts_cmd(enum ts_kit_hybrid_cmd sub_cmd);

/*
 * register hybrid ts chip operations
 * @param ops the operations to register
 */
int ts_hybrid_ops_register(struct ts_hybrid_chip_ops *ops);

/*
 * reset tp
 * @return >= 0 for success, false otherwise.
 */
int ts_hybrid_reset(void);

/*
 * rotary crown power control
 * @return = 0 for success, false otherwise.
 */
int ts_hybrid_crown_power_control(bool power_status);

void enable_ts_irq(void);

void disable_ts_irq(void);

void ts_kit_hybrid_irq_open(void);

void ts_kit_hybrid_irq_close(void);

void ts_kit_hybrid_hw_reset(void);

/*
 * wait tskit poweroff resp state
 */
void ts_kit_set_resp_state(int state);
/*
 * wait tskit poweroff ready
 */
void ts_hybrid_wait_resp(void);

unsigned int get_gesture_switch(void);
#endif
