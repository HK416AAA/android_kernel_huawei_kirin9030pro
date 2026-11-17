/*
 * ec_state_sync.h
 *
 * ec_state_sync driver for suspend/resume
 *
 * Copyright (c) 2018-2019 Huawei Technologies Co., Ltd.
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

#ifndef _ARMPC_EC_STATE_SYNC
#define _ARMPC_EC_STATE_SYNC

#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
extern int get_sleep_count(void);
#else
static inline int get_sleep_count(void) { return 0; }
#endif

#ifdef CONFIG_HIPCIE_OCT
extern int pcie_notify_pwr_register(unsigned int cdx, unsigned int pdx, int (*poweron)(void *data),
				int (*poweroff)(void *data), void *data);
#endif

enum echub_bigdata_wakeup_type {
	AWAKE_TYPE_S3 = 1,
	AWAKE_TYPE_ULSR,
	AWAKE_TYPE_S4,
	AWAKE_TYPE_S5,
};

#endif
