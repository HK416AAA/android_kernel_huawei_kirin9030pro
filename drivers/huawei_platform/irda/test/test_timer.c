/*
 * test_timer.c
 *
 * test timer
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
#include <linux/slab.h>
#include <linux/delay.h>
#include "test_system.h"

#define TEST_TIMER_OBJ_NAME "timer"
#define TEST_TIMER_DELAY_US_MIN 500
#define TEST_TIMER_DELAY_US_MAX 1000
#define TEST_TIMER_DELAY_MS 20

struct test_timer_context {
	u32 count;
};

struct test_timer_args {
	u32 delay_us_min;
	u32 delay_us_max;
	u32 delay_us;
	u32 delay_ms;
};

static void *test_timer_setup(struct dentry *dir)
{
	struct test_timer_context *ctx = NULL;

	ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return NULL;
	return ctx;
}

static void test_timer_teardown(void *sub_context)
{
	if (sub_context)
		kfree(sub_context);
}

#define test_timer_u32_arg(param, default) \
do { \
	debugfs_create_x32(#param, 0600, dir, &args->param); \
	args->param = default; \
} while (0)

void *test_timer_alloc_args(struct dentry *dir)
{
	struct test_timer_args *args = NULL;

	if (!dir)
		return NULL;

	args = kzalloc(sizeof(*args), GFP_KERNEL);
	if (!args)
		return NULL;

	test_timer_u32_arg(delay_us_min, TEST_TIMER_DELAY_US_MIN);
	test_timer_u32_arg(delay_us_max, TEST_TIMER_DELAY_US_MAX);
	test_timer_u32_arg(delay_us, TEST_TIMER_DELAY_US_MIN);
	test_timer_u32_arg(delay_ms, TEST_TIMER_DELAY_MS);
	return args;
}

void test_timer_free_args(void *args)
{
	kfree(args);
}

static int test_timer_udelay(void *context, void *args)
{
	struct test_timer_context *ctx = context;
	struct test_timer_args *targs = args;

	if (!ctx || !targs)
		return -EINVAL;
	
	udelay(targs->delay_us);
	ctx->count++;
	return 0;
}

static int test_timer_usleep_range(void *context, void *args)
{
	struct test_timer_context *ctx = context;
	struct test_timer_args *targs = args;

	if (!ctx || !targs)
		return -EINVAL;
	
	usleep_range(targs->delay_us_min, targs->delay_us_max);
	ctx->count++;
	return 0;
}

static int test_timer_msleep(void *context, void *args)
{
	struct test_timer_context *ctx = context;
	struct test_timer_args *targs = args;

	if (!ctx || !targs)
		return -EINVAL;
	
	msleep(targs->delay_ms);
	ctx->count++;
	return 0;
}

#define test_timer_f(_func_name, _run) \
	test_f_arg(TEST_TIMER_OBJ_NAME, _func_name, _run, \
	test_timer_alloc_args, test_timer_free_args)

static int __init test_timer_init(void)
{
	test_object(TEST_TIMER_OBJ_NAME, test_timer_setup,
		test_timer_teardown);
	test_timer_f("udelay", test_timer_udelay);
	test_timer_f("usleep_range", test_timer_usleep_range);
	test_timer_f("msleep", test_timer_msleep);
	return 0;
}

static void __exit test_timer_deinit(void)
{
}

module_init(test_timer_init);
module_exit(test_timer_deinit);