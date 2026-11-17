/*
 * test_context.c
 *
 * test context
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

#include "test_context.h"
#include <linux/cpumask.h>
#include <linux/sched.h>
#include <linux/sched/rt.h>
#include <uapi/linux/sched/types.h>
#include "test_object.h"
#include "test_func.h"

#define TEST_CTX_DFT_LOOPS 1
#define TEST_CTX_DFT_FORBID_PREEMPT 0
#define TEST_CTX_DFT_SCH_TYPE (-1)
#define TEST_CTX_DFT_SCH_PRIORITY (-1)
#define TEST_CTX_DFT_SCH_AFFINITY (-1)

#define test_create_context_u32_attr(ctx, param, default) \
do { \
	debugfs_create_x32(#param, 0600, (ctx)->dir, &(ctx)->param); \
	(ctx)->param = (default); \
} while (0)

int test_init_context(struct test_context *ctx, struct test_func *func,
	struct dentry *parent)
{
	if (!ctx || !parent)
		return -EINVAL;

	ctx->dir = debugfs_create_dir("context", parent);
	if (!ctx->dir) {
		pr_err("%s create context dir fail\n", __func__);
		return -ENOMEM;
	}

	test_create_context_u32_attr(ctx, run_loops, TEST_CTX_DFT_LOOPS);
	test_create_context_u32_attr(ctx, forbid_preempt, TEST_CTX_DFT_FORBID_PREEMPT);
	test_create_context_u32_attr(ctx, sched_type, TEST_CTX_DFT_SCH_TYPE);
	test_create_context_u32_attr(ctx, sched_priority, TEST_CTX_DFT_SCH_PRIORITY);
	test_create_context_u32_attr(ctx, sched_cpu, TEST_CTX_DFT_SCH_AFFINITY);
	ctx->func = func;
	ctx->sub_context = test_setup_object(test_get_func_obj(ctx->func), ctx->dir);
	ctx->args = test_alloc_func_args(ctx->func, ctx->dir);
	return 0;
}

static int test_set_sched_affinity(struct test_context *ctx)
{
	if (ctx->sched_cpu == TEST_CTX_DFT_SCH_AFFINITY)
		return 0;

	if (ctx->sched_cpu >= NR_CPUS)
		return -EINVAL;

	return sched_setaffinity(0, cpumask_of(ctx->sched_cpu));
}

static void test_reset_sched_affinity(struct test_context *ctx)
{
	cpumask_t all;

	cpumask_setall(&all);
	(void)sched_setaffinity(0, &all);
}

static int test_set_sched_priority(struct test_context *ctx)
{
	struct sched_param param = { .sched_priority = MAX_RT_PRIO - 4 };

	if (ctx->sched_priority == TEST_CTX_DFT_SCH_PRIORITY ||
		ctx->sched_type == TEST_CTX_DFT_SCH_TYPE)
		return 0;

	if ((ctx->sched_type != SCHED_FIFO &&
		ctx->sched_type != SCHED_NORMAL))
		return -EINVAL;

	if (ctx->sched_priority > MAX_RT_PRIO)
		ctx->sched_priority = MAX_RT_PRIO;
	param.sched_priority = ctx->sched_priority;

	return sched_setscheduler_nocheck(current, ctx->sched_type, &param);
}

static void test_reset_sched_priority(struct test_context *ctx)
{
	struct sched_param param = { .sched_priority = 0 };

	if (ctx->sched_priority == TEST_CTX_DFT_SCH_PRIORITY ||
		ctx->sched_type == TEST_CTX_DFT_SCH_TYPE)
		return;

	sched_setscheduler_nocheck(current, SCHED_NORMAL, &param);
}

int test_setup_context(struct test_context *ctx)
{
	int ret;

	if (!ctx)
		return -EINVAL;

	ret = test_set_sched_priority(ctx);
	if (ret != 0)
		return ret;
	return test_set_sched_affinity(ctx);
}

void test_teardown_context(struct test_context *ctx)
{
	if (!ctx)
		return;

	test_reset_sched_affinity(ctx);
	test_reset_sched_priority(ctx);
}

void test_deinit_context(struct test_context *ctx)
{
	if (!ctx)
		return;

	debugfs_remove_recursive(ctx->dir);
	test_free_func_args(ctx->func, ctx->args);\
	ctx->args = NULL;
	test_teardown_object(test_get_func_obj(ctx->func), ctx->sub_context);
	ctx->sub_context = NULL;
}
