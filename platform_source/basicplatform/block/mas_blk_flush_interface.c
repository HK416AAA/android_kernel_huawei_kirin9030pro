/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description:  mas block flush reduce interface
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "mas_blk_flush_interface.h"

static void __cfi_mas_blk_flush_work_fn(struct work_struct *work)
{
	mas_blk_flush_work_fn(work);
}

void __cfi_mas_blk_flush_delayed_work_init(struct blk_queue_cust *mas_queue)
{
	INIT_DELAYED_WORK(&mas_queue->flush_work,
		__cfi_mas_blk_flush_work_fn);
}

int __cfi_mas_blk_poweroff_flush_notifier_call(
	struct notifier_block *powerkey_nb, unsigned long event, void *data)
{
	return mas_blk_poweroff_flush_notifier_call(powerkey_nb, event, data);
}

int __init __cfi_mas_blk_flush_init(void)
{
	return mas_blk_flush_init();
}

module_init(__cfi_mas_blk_flush_init);

struct notifier_block mas_blk_poweroff_flush_nb = {
	.notifier_call = __cfi_mas_blk_poweroff_flush_notifier_call,
	.priority = 0,
};

