/*
 * test_case.h
 *
 * test case manager
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

#ifndef _TEST_CASE_H_
#define _TEST_CASE_H_

#include <linux/workqueue.h>
#include <linux/debugfs.h>
#include <linux/dcache.h>
#include "test_context.h"

enum test_case_state {
	TCASE_WAIT = 0,
	TCASE_RUN,
	TCASE_FIN,
	TCASE_DEL,
	TCASE_MAX,
};

#define TCASE_MIN_ID 0
#define TCASE_MAX_ID INT_MAX

struct test_case_s;
struct test_object;
struct test_func;
struct test_result;

struct test_case {
	int id;
	struct dentry *dir;
	struct mutex lock;
	enum test_case_state state;
	struct test_result *result;
	struct test_context context;
};

struct test_case_pool *test_create_case_pool(void);
int test_alloc_case(struct test_case_pool *pool, int id, struct test_func *func);
struct test_case *test_find_case(struct test_case_pool *pool, int id);
void test_free_case(struct test_case_pool *pool, struct test_case *tcase);
int test_move_case(struct test_case_pool *old, struct test_case_pool *new, struct test_case *tcase);
void test_del_unuse_case(struct test_case_pool *pool);
void test_destroy_case_pool(struct test_case_pool *pool);

#endif /* _TEST_CASE_H_ */