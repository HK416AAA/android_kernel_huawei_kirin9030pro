/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2024. All rights reserved.
 * Description: PV LED
 * Create: 2024-02-26
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 */

#ifndef __HW_KERNEL_CAM_PV_LED_CFG_H__
#define __HW_KERNEL_CAM_PV_LED_CFG_H__

#define CMD_MAGIC 'A'

#define KERNEL_PVLED_ON _IO(CMD_MAGIC, 0)
#define KERNEL_PVLED_OFF _IO(CMD_MAGIC, 1)

#endif /* __HW_KERNEL_CAM_PV_LED_CFG_H__ */