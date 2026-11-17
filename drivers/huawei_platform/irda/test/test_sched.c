/*
 * test_sched.c
 *
 * test schedule
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
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include "test_system.h"

#define TEST_SCHED_OBJ_NAME "sched"

struct test_sched_context {
	u32 count;
	struct tasklet_struct tsklet;
};

static void test_sched_tasklet_func(struct tasklet_struct *t)
{
	struct test_sched_context *ctx = NULL;

	ctx = container_of(t, struct test_sched_context, tsklet);
	ctx->count++;
}

static void *test_sched_setup(struct dentry *dir)
{
	struct test_sched_context *ctx = NULL;

	ctx = kzalloc(sizeof(struct test_sched_context), GFP_KERNEL);
	if (!ctx)
		return NULL;

	tasklet_setup(&ctx->tsklet, test_sched_tasklet_func);
	return ctx;
}

static void test_sched_teardown(void *sub_context)
{
	struct test_sched_context *ctx = sub_context;

	if (!ctx)
		return;
	
	tasklet_kill(&ctx->tsklet);
	kfree(sub_context);
}

static int test_sched_thread_func(void *arg)
{
	struct test_sched_context *ctx = arg;

	if (ctx)
		ctx->count++;
	return 0;
}

static int test_sched_kthread_run(void *context, void *args)
{
	struct task_struct *k = NULL;

	k = kthread_create(test_sched_thread_func, context,
		"test_kthread");
	if (IS_ERR(k))
		return -ENOMEM;
	kthread_stop(k);
	return 0;
}

static int test_sched_tasklet_schedule(void *context, void *args)
{
	struct test_sched_context *ctx = context;

	if (!ctx)
		return -EINVAL;
	tasklet_schedule(&ctx->tsklet);
	return 0;
}

static int __init test_sched_init(void)
{
	test_object(TEST_SCHED_OBJ_NAME, test_sched_setup,
		test_sched_teardown);
	test_f(TEST_SCHED_OBJ_NAME, "kthread_run",
		test_sched_kthread_run);
	test_f(TEST_SCHED_OBJ_NAME, "tasklet_schedule",
		test_sched_tasklet_schedule);
	return 0;
}

static void __exit test_sched_deinit(void)
{
}

module_init(test_sched_init);
module_exit(test_sched_deinit);