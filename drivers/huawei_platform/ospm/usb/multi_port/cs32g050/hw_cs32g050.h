/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * hw_cs32g050.h
 *
 * cs32g050 multi port driver
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
#ifndef _HW_PC_PD_IN_H_
#define _HW_PC_PD_IN_H_

typedef void (*event_notify_t)(int event_type, int event_data);

typedef enum {
	DPIN_CONFIG,
	DPIN_PLUG_DEVICE_STATUS,
	DPIN_DP_MODE,
	//上面是事件类型宏  下面是事件类型值
	DP_IN_STATUS_POSITIVE,
	DP_IN_STATUS_NEGATIVE,
	//CONFIG
	DP_IN_STATUS_UNSUPPORT,
	DP_IN_STATUS_PLUG_IN,
	DP_IN_STATUS_PLUG_OUT,
} dp_in_status;

typedef enum {
	DPIN_EVENT = 1,
} cs32g050_register_module;

void cs32g050_register_event(cs32g050_register_module type, event_notify_t notify);

#endif