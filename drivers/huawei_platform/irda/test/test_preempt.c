/*
 * test_preempt.c
 *
 * test preempt
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

#include <linux/slab.h>
#include <linux/preempt.h>
#include <linux/irqflags.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include "test_system.h"

#define TEST_PREEMPT_OBJ_NAME "preempt"

struct test_preempt_context {
	u32 count;
};

static void *test_preempt_setup(struct dentry *dir)
{
	return kzalloc(sizeof(struct test_preempt_context), GFP_KERNEL);
}

static void test_preempt_teardown(void *sub_context)
{
	kfree(sub_context);
}

static int test_preempt_enable(void *context, void *args)
{
	struct test_preempt_context *ctx = context;

	if (!ctx)
		return -EINVAL;
	
	preempt_disable();
	ctx->count++;
	preempt_enable();
	return 0;
}

static int test_local_irq_enable(void *context, void *args)
{
	struct test_preempt_context *ctx = context;

	if (!ctx)
		return -EINVAL;
	
	local_irq_disable();
	ctx->count++;
	local_irq_enable();
	return 0;
}

static int __init test_preempt_init(void)
{
	test_object(TEST_PREEMPT_OBJ_NAME, test_preempt_setup,
		test_preempt_teardown);
	test_f(TEST_PREEMPT_OBJ_NAME, "preempt_enable",
		test_preempt_enable);
	test_f(TEST_PREEMPT_OBJ_NAME, "local_irq_enable",
		test_local_irq_enable);
	return 0;
}

static void __exit test_preempt_deinit(void)
{
}

module_init(test_preempt_init);
module_exit(test_preempt_deinit);