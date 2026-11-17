/*
 * test_driver_model.c
 *
 * test driver model
 *
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
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

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include "test_system.h"

#define TEST_FILE_OBJ_NAME "driver_model"

static int __init test_dmod_init(void)
{
	return 0;
}

static void __exit test_dmod_deinit(void)
{
}

module_init(test_dmod_init);
module_exit(test_dmod_deinit);