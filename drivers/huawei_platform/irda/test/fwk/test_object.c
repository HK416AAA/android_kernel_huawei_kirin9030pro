/*
 * test_object.c
 *
 * test object
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

#include "test_object.h"
#include <linux/mutex.h>
#include <linux/slab.h>
#include <securec.h>
#include "test_system.h"

#define TEST_OBJ_NAME_LEN 128

struct test_object {
	char name[TEST_OBJ_NAME_LEN];
	test_object_setup_t setup;
	test_object_teardown_t teardown;
	struct mutex flock;
	struct rb_node rb;
	struct rb_root funcs;
	struct dentry *dir;
};

static int test_insert_object(struct rb_root *root, struct test_object *obj)
{
	int result;
	struct rb_node **iter_node = &root->rb_node;
	struct test_object *iter_obj = NULL;
	struct rb_node *parent = NULL;

	while (*iter_node) {
		iter_obj = container_of(*iter_node, struct test_object, rb);
		result = strcmp(obj->name, iter_obj->name);
		parent = *iter_node;
		if (result < 0)
			iter_node = &(*iter_node)->rb_left;
		else if (result > 0)
			iter_node = &(*iter_node)->rb_right;
		else
			return -1;
	}

	rb_link_node(&obj->rb, parent, iter_node);
	rb_insert_color(&obj->rb, root);
	return 0;
}

static struct dentry *test_create_obj_dir(const char *obj_name)
{
	struct test_system *sys = test_get_system();

	if (!sys || !sys->root_dir)
		return NULL;

	return debugfs_create_dir(obj_name, sys->root_dir);
}

void test_register_object(struct rb_root *root, const char *obj_name,
	test_object_setup_t setup, test_object_teardown_t teardown)
{
	struct test_object *new_obj = NULL;

	if (!root || !obj_name)
		return;
	
	new_obj = kzalloc(sizeof(*new_obj), GFP_KERNEL);
	if (!new_obj)
		return;

	strncpy_s(new_obj->name, TEST_OBJ_NAME_LEN, obj_name,
		strlen(obj_name));
	new_obj->name[TEST_OBJ_NAME_LEN - 1] = '\0';
	mutex_init(&new_obj->flock);
	new_obj->funcs = RB_ROOT;
	new_obj->dir = test_create_obj_dir(new_obj->name);
	new_obj->setup = setup;
	new_obj->teardown = teardown;

	if (test_insert_object(root, new_obj) != 0) {
		pr_err("%s insert object %s fail\n", __func__, new_obj->name);
		kfree(new_obj);
	} else {
		pr_info("%s register object %s\n", __func__, new_obj->name);
	}
}

struct test_object *test_search_object(struct rb_root *root, const char *name)
{
	int result;
	struct rb_node *iter_node = NULL;
	struct test_object *obj  = NULL;

	if (!root || !name)
		return NULL;

	iter_node = root->rb_node;

	while (iter_node) {
		obj = container_of(iter_node, struct test_object, rb);
		result = strcmp(name, obj->name);
		if (result < 0)
			iter_node = iter_node->rb_left;
		else if (result > 0)
			iter_node = iter_node->rb_right;
		else
			return obj;
	}
	pr_err("%s find object %s fail\n", __func__, name);
	return NULL;
}

void *test_setup_object(struct test_object *obj, struct dentry *dir)
{
	if (!obj || !obj->setup)
		return NULL;

	return obj->setup(dir);
}

void test_teardown_object(struct test_object *obj, void *sub_context)
{
	if (!obj || !obj->teardown)
		return;

	obj->teardown(sub_context);
}

const char *test_get_obj_name(struct test_object *obj)
{
	if (!obj)
		return NULL;
	return obj->name;
}

struct dentry *test_get_obj_dir(struct test_object *obj)
{
	if (!obj)
		return NULL;
	return obj->dir;
}

struct rb_root *test_get_obj_funcs(struct test_object *obj)
{
	if (!obj)
		return NULL;
	return &obj->funcs;
}