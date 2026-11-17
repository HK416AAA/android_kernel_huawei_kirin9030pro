/*
 * test_percpu.c
 *
 * test percpu
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
#include <linux/percpu.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include "test_system.h"

#define TEST_PERCPU_OBJ_NAME "percpu"

struct test_percpu_data {
	int cpu;
	int count;
};

struct test_percpu_context {
	struct test_percpu_data __percpu *tda;
};

static DEFINE_PER_CPU(struct test_percpu_data, test_data);

static void *test_percpu_setup(struct dentry *dir)
{
	struct test_percpu_context *ctx = NULL;
	struct test_percpu_data *pda = NULL;
	int cpu;

	ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return NULL;

	ctx->tda = alloc_percpu(struct test_percpu_data);
	if (!ctx->tda) {
		kfree(ctx);
		return NULL;
	}
	for_each_possible_cpu(cpu) {
		pda = per_cpu_ptr(ctx->tda, cpu);
		pda->cpu = cpu;
	}
	for_each_possible_cpu(cpu) {
		pda = per_cpu_ptr(&test_data, cpu);
		pda->cpu = cpu;
	}
	return ctx;
}

static void test_percpu_teardown(void *sub_context)
{
	struct test_percpu_context *ctx = sub_context;
	int ctx_tda_count = 0;

	if (!ctx)
		return;

	if (ctx->tda) {
		ctx_tda_count = this_cpu_read(ctx->tda->count);
		free_percpu(ctx->tda);
		ctx->tda = NULL;
	}
	pr_info("%s dynamic this percu value=%d\n", __func__,
		ctx_tda_count);
	pr_info("%s static this percu value=%d\n", __func__,
		this_cpu_read(test_data.count));
	kfree(ctx);
}

static int test_dynamic_percpu_foreach(void *context, void *args)
{
	struct test_percpu_context *ctx = context;
	struct test_percpu_data *pda = NULL;
	int cpu;

	if (!ctx)
		return -EINVAL;

	for_each_possible_cpu(cpu) {
		pda = per_cpu_ptr(ctx->tda, cpu);
		pda->count += pda->cpu;
	}
	return 0;
}

static int test_dynamic_percpu_this(void *context, void *args)
{
	struct test_percpu_context *ctx = context;
	struct test_percpu_data *pda = NULL;
	int tcpu;

	if (!ctx)
		return -EINVAL;

	tcpu = this_cpu_read(ctx->tda->cpu);
	pda = raw_cpu_ptr(ctx->tda);
	pda->count += tcpu;
	return 0;
}

static int test_static_percpu_foreach(void *context, void *args)
{
	struct test_percpu_data *pda = NULL;
	int cpu;

	for_each_possible_cpu(cpu) {
		pda = per_cpu_ptr(&test_data, cpu);
		pda->count += pda->cpu;
	}
	return 0;
}

static int test_static_percpu_this(void *context, void *args)
{
	struct test_percpu_data *pda = NULL;
	int tcpu;

	tcpu = this_cpu_read(test_data.cpu);
	pda = raw_cpu_ptr(&test_data);
	pda->count += tcpu;
	return 0;
}

static int __init test_percpu_init(void)
{
	test_object(TEST_PERCPU_OBJ_NAME, test_percpu_setup,
		test_percpu_teardown);
	test_f(TEST_PERCPU_OBJ_NAME, "dynamic_percpu_foreach",
		test_dynamic_percpu_foreach);
	test_f(TEST_PERCPU_OBJ_NAME, "dynamic_percpu_this",
		test_dynamic_percpu_this);
	test_f(TEST_PERCPU_OBJ_NAME, "static_percpu_foreach",
		test_static_percpu_foreach);
	test_f(TEST_PERCPU_OBJ_NAME, "static_percpu_this",
		test_static_percpu_this);
	return 0;
}

static void __exit test_percpu_deinit(void)
{
}

module_init(test_percpu_init);
module_exit(test_percpu_deinit);