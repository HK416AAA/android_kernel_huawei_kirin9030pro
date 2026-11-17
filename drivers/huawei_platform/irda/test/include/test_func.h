/*
 * test_func.h
 *
 * test function
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

#ifndef _TEST_FUNC_H_
#define _TEST_FUNC_H_

#include <linux/rbtree.h>
#include <linux/debugfs.h>
#include <linux/dcache.h>

struct test_func;
struct test_object;

typedef void *(*test_func_alloc_args_t)(struct dentry *dir);
typedef void (*test_func_free_args_t)(void *args);
typedef int (*test_func_run_t)(void *context, void *args);
typedef int (*test_func_print_result)(struct seq_file *s);

struct test_func_register {
	const char *obj_name;
	const char *name;
	test_func_alloc_args_t alloc_args;
	test_func_free_args_t free_args;
	test_func_run_t run;
	test_func_print_result print_result;
};

void test_register_func(struct rb_root *root, struct test_func_register *func_r);
struct test_func *test_search_func(struct rb_root *root, const char *obj_name, const char *name);
const char *test_get_func_name(struct test_func *func);
struct dentry *test_get_func_dir(struct test_func *func);
struct test_object *test_get_func_obj(struct test_func *func);
void *test_alloc_func_args(struct test_func *func, struct dentry *dir);
void test_free_func_args(struct test_func *func, void *args);
int test_run_func(struct test_func *func, void *sub_context, void *args);
int test_print_func_result(struct test_func *func, struct seq_file *s);

#endif /* _TEST_FUNC_H_ */