/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
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
#ifndef __DPM_MANAGE_H__
#define __DPM_MANAGE_H__

#include <linux/pm_qos.h>
#include <linux/errno.h>

#define DPM_POWER_OFF	0
#define DPM_POWER_ON	1

#ifdef CONFIG_DPM_SUPPORT
bool dpm_debug_mode_enable(void);

int dpm_pwr_state_add_request(struct pm_qos_request *req, s32 value);
int dpm_pwr_state_update_request(struct pm_qos_request *req, s32 new_value);
int dpm_pwr_state_remove_request(struct pm_qos_request *req);

#else
static inline bool dpm_debug_mode_enable(void) { return false; }
static inline int dpm_pwr_state_add_request(struct pm_qos_request *req, s32 value) { return -EFAULT; }
static inline int dpm_pwr_state_update_request(struct pm_qos_request *req, s32 new_value) { return -EFAULT; }
static inline int dpm_pwr_state_remove_request(struct pm_qos_request *req) { return -EFAULT; }
#endif

#endif /* __DPM_MANAGE_H__ */
