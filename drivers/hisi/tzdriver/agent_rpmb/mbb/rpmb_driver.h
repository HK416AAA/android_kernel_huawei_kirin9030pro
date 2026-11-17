/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: function declarment for rpmb
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __RPMB_DRIVER_H
#define __RPMB_DRIVER_H

#include <bsp_rpmb.h>

static inline void rpmb_driver_counter_lock(void)
{
	bsp_rpmb_driver_counter_lock();
}

static inline void rpmb_driver_counter_unlock(void)
{
	bsp_rpmb_driver_counter_unlock();
}

int rpmb_ioctl_cmd(enum rpmb_func_id id, enum rpmb_op_type operation,
	struct storage_blk_ioc_rpmb_data *storage_data);

#endif