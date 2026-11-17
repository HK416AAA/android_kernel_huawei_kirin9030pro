/*
 * test_func.c
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

#include "test_func.h"
#include <linux/slab.h>
#include <securec.h>
#include "test_object.h"
#include "test_case.h"
#include "test_system.h"

#define TEST_FUNC_NAME_LEN 128

struct test_func {
	char name[TEST_FUNC_NAME_LEN];
	struct test_object *obj;
	test_func_alloc_args_t alloc_args;
	test_func_free_args_t free_args;
	test_func_run_t run;
	test_func_print_result print_result;
	struct rb_node rb;
};

static int test_insert_func(struct rb_root *root, struct test_func *func)
{
	int result;
	struct rb_node **iter_node = &root->rb_node;
	struct test_func *iter_func = NULL;
	struct rb_node *parent = NULL;

	while (*iter_node) {
		iter_func = container_of(*iter_node, struct test_func, rb);
		result = strcmp(func->name, iter_func->name);
		parent = *iter_node;
		if (result < 0)
			iter_node = &(*iter_node)->rb_left;
		else if (result > 0)
			iter_node = &(*iter_node)->rb_right;
		else
			return -1;
	}

	rb_link_node(&func->rb, parent, iter_node);
	rb_insert_color(&func->rb, root);
	return 0;
}

static int test_create_case(void *data, u64 val)
{
	struct test_func *func = data;
	struct test_system *sys = test_get_system();

	if (!func || !sys)
		return -EINVAL;

	pr_info("%s to create test case %llu\n", __func__, val);
	return test_alloc_case(sys->active_cases, val, func);
}
DEFINE_DEBUGFS_ATTRIBUTE(test_create_case_fops,
	NULL, test_create_case, "%llu\n");

static void test_create_func_file(struct test_func *func)
{
	struct dentry *parent = NULL;

	parent = test_get_obj_dir(func->obj);
	if (!parent)
		return;

	debugfs_create_file(test_get_func_name(func), 0600,
		parent, func, &test_create_case_fops);
}

void test_register_func(struct rb_root *root, struct test_func_register *func_r)
{
	struct test_object *obj = NULL;
	struct test_func *new_func = NULL;

	if (!root || !func_r || !func_r->obj_name ||
		!func_r->name || !func_r->run)
		return;

	obj = test_search_object(root, func_r->obj_name);
	if (!obj) {
		test_register_object(root, func_r->obj_name, NULL, NULL);
		obj = test_search_object(root, func_r->obj_name);
	}
	if (!obj) {
		pr_err("%s find object %s fail\n", __func__, func_r->obj_name);
		return;
	} else {
		pr_err("%s find object %s for func %s\n", __func__,
			func_r->obj_name, func_r->name);
	}

	new_func = kzalloc(sizeof(*new_func), GFP_KERNEL);
	if (!new_func)
		return;

	strncpy_s(new_func->name, TEST_FUNC_NAME_LEN, func_r->name,
		strlen(func_r->name));
	new_func->name[TEST_FUNC_NAME_LEN - 1] = '\0';
	new_func->obj = obj;
	new_func->alloc_args = func_r->alloc_args;
	new_func->free_args = func_r->free_args;
	new_func->run = func_r->run;
	new_func->print_result = func_r->print_result;
	test_create_func_file(new_func);

	if (test_insert_func(test_get_obj_funcs(obj), new_func) != 0) {
		pr_err("%s insert func %s of object %s fail\n", __func__,
			new_func->name, func_r->obj_name);
		kfree(new_func);
	} else {
		pr_info("%s register func %s of object %s\n", __func__,
			new_func->name, func_r->obj_name);
	}
}

struct test_func *test_search_func(struct rb_root *root,
	const char *obj_name, const char *name)
{
	int result;
	struct test_object *obj = NULL;
	struct rb_node *iter_node = NULL;
	struct test_func *func  = NULL;

	obj = test_search_object(root, obj_name);
	if (!obj)
		return NULL;

	iter_node = test_get_obj_funcs(obj)->rb_node;
	while (iter_node) {
		func = container_of(iter_node, struct test_func, rb);
		result = strcmp(name, func->name);
		if (result < 0)
			iter_node = iter_node->rb_left;
		else if (result > 0)
			iter_node = iter_node->rb_right;
		else
			return func;
	}
	pr_err("%s find func %s of object %s fail\n", __func__,
		obj_name, name);
	return NULL;
}

const char *test_get_func_name(struct test_func *func)
{
	if (!func)
		return NULL;
	return func->name;
}

struct dentry *test_get_func_dir(struct test_func *func)
{
	if (!func || !func->obj)
		return NULL;
	return test_get_obj_dir(func->obj);
}

struct test_object *test_get_func_obj(struct test_func *func)
{
	if (!func)
		return NULL;
	return func->obj;
}

void *test_alloc_func_args(struct test_func *func, struct dentry *dir)
{
	if (!func || !func->alloc_args)
		return NULL;
	 
	return func->alloc_args(dir);
}

void test_free_func_args(struct test_func *func, void *args)
{
	if (!func || !func->free_args || !args)
		return;
	
	func->free_args(args);
}

int test_run_func(struct test_func *func, void *sub_context, void *args)
{
	if (!func || !func->run)
		return -EINVAL;

	return func->run(sub_context, args);
}

int test_print_func_result(struct test_func *func, struct seq_file *s)
{
	if (!func || !func->print_result)
		return -EINVAL;

	return func->print_result(s);
}