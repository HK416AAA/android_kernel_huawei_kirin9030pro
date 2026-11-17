/*
 * test_result.c
 *
 * test result manager
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

#include "test_result.h"
#include <linux/slab.h>
#include "test_case.h"
#include "test_func.h"

struct test_func;

struct test_result {
	int ret;
	int total_count;
	uint64_t total_ticks;
	uint64_t total_abs_ticks;
	int normal_count;
	uint64_t normal_toatl_ticks;
	uint64_t normal_max_ticks;
	uint64_t normal_min_ticks;
	int abr_count;
	uint64_t abr_toatl_ticks;
	uint64_t abr_max_ticks;
	uint64_t abr_min_ticks;
};

#define test_seq_printf_result_int(param) \
	seq_printf(s, "%s=%d\n", #param, tcase->result->param)

#define test_seq_printf_result_u64(param) \
	seq_printf(s, "%s=%llu\n", #param, tcase->result->param)

static void test_case_common_result(struct test_case *tcase,
	struct seq_file *s)
{
	test_seq_printf_result_int(ret);
	test_seq_printf_result_int(total_count);
	test_seq_printf_result_u64(total_ticks);
	test_seq_printf_result_u64(total_abs_ticks);
	test_seq_printf_result_int(normal_count);
	test_seq_printf_result_u64(normal_toatl_ticks);
	test_seq_printf_result_u64(normal_max_ticks);
	test_seq_printf_result_u64(normal_min_ticks);
	test_seq_printf_result_int(abr_count);
	test_seq_printf_result_u64(abr_toatl_ticks);
	test_seq_printf_result_u64(abr_max_ticks);
	test_seq_printf_result_u64(abr_min_ticks);
}

static int test_case_result_show(struct seq_file *s, void *what)
{
	struct test_case *tcase = s->private;
	int ret;

	mutex_lock(&tcase->lock);
	if (tcase->state == TCASE_DEL)
		goto ulock_case;

	ret = test_print_func_result(tcase->context.func, s);
	if (ret == -EINVAL)
		test_case_common_result(tcase, s);

ulock_case:
	mutex_unlock(&tcase->lock);
	return 0;
}
DEFINE_SHOW_ATTRIBUTE(test_case_result);

struct test_result *test_alloc_result(struct test_case *tcase)
{
	struct test_result *res = NULL;

	if (!tcase || !tcase->dir)
		return NULL;

	res = kzalloc(sizeof(*res), GFP_KERNEL);
	if (!res)
		return NULL;

	res->normal_min_ticks = INT_MAX;
	res->abr_min_ticks = INT_MAX;
	debugfs_create_file("result", 0400,
		tcase->dir, tcase, &test_case_result_fops);
	return res;
}

static void test_stat_normal_result(struct test_result *result, int ticks)
{
	result->normal_count++;
	result->normal_toatl_ticks += ticks;
	if (result->normal_max_ticks < ticks)
		result->normal_max_ticks = ticks;

	if (result->normal_min_ticks > ticks)
		result->normal_min_ticks = ticks;
}

static void test_stat_abr_result(struct test_result *result, int ticks)
{
	result->abr_count++;
	result->abr_toatl_ticks += ticks;
	if (result->abr_max_ticks < ticks)
		result->abr_max_ticks = ticks;

	if (result->abr_min_ticks > ticks)
		result->abr_min_ticks = ticks;
}

void test_report_once_result(struct test_result *result, int ret, uint64_t ticks)
{
	if (!result)
		return;

	if (ret == 0)
		test_stat_normal_result(result, ticks);
	else
		test_stat_abr_result(result, ticks);

	result->total_ticks += ticks;
	result->total_count++;
	result->ret = ret;
}

void test_report_final_result(struct test_result *result, uint64_t totals)
{
	if (!result)
		return;

	result->total_abs_ticks += totals;
	if (result->abr_count > 0 && result->ret == 0)
		result->ret = -1;
}

void test_free_result(struct test_result *result)
{
	kfree(result);
}