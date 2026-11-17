/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
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
#ifndef DPU_COMPOSER_INTERFACE_H
#define DPU_COMPOSER_INTERFACE_H
#include <linux/notifier.h>

enum {
	ON_PRESENT_NOTIFY = BIT(0),
	/* TODO: other notify status bits */
};

int composer_register_notify(struct notifier_block *nb);
#endif