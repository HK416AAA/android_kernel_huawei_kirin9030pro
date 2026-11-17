/*
 * test_context.h
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

#ifndef _TEST_CONTEXT_H_
#define _TEST_CONTEXT_H_

#include <linux/debugfs.h>
#include <linux/dcache.h>

struct test_func;

struct test_context {
	struct dentry *dir;
	struct test_func *func;
	int run_loops;
	int forbid_preempt;
	int sched_type;
	int sched_priority;
	int sched_cpu;
	void *args;
	void *sub_context;
};

int test_init_context(struct test_context *ctx, struct test_func *func,
	struct dentry *parent);
int test_setup_context(struct test_context *ctx);
void test_teardown_context(struct test_context *ctx);
void test_deinit_context(struct test_context *ctx);

#endif /* _TEST_CONTEXT_H_ */