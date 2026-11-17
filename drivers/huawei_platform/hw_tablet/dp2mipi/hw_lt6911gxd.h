/*
 * hw_lt6911gxd.h
 *
 * lt6911gxd driver
 *
 * Copyright (c) 2023 Huawei Technologies Co., Ltd.
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
#ifndef _HW_DP_IN_H_
#define _HW_DP_IN_H_

#include <linux/types.h>
#ifdef CONFIG_HW_LT6911GXD_DRIVER

typedef void (*event_notify_t)(int event_type, int event_data);

typedef enum {
	PD_EVENT = 1,
} lt6911gxd_register_module;
#define DP_IN_ENABLE 1
#define DP_IN_DISABLE 0
typedef enum {
	DP_IN_SET_MODE,
	DP_IN_GET_MODE,
	//PD ACTION
	DP_IN_SEND_ATTENTION,
	//PD MODE
} lt6911gxd_dp_in_status;

void lt6911gxd_register_event(lt6911gxd_register_module type,
			      event_notify_t notify);

int lt6911gxd_get_fw_ver(unsigned int *ver);
void lt6911gxd_change_audio_mux(bool audio_cmd);
#endif

#endif
