/*
 * test_object.h
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

#ifndef _TEST_OBJECT_H_
#define _TEST_OBJECT_H_

#include <linux/rbtree.h>
#include <linux/debugfs.h>
#include <linux/dcache.h>

struct test_object;

typedef void *(*test_object_setup_t)(struct dentry *dir);
typedef void (*test_object_teardown_t)(void *sub_context);

void test_register_object(struct rb_root *root, const char *obj_name,
	test_object_setup_t setup, test_object_teardown_t teardown);
struct test_object *test_search_object(struct rb_root *root, const char *name);
void *test_setup_object(struct test_object *obj, struct dentry *dir);
void test_teardown_object(struct test_object *obj, void *sub_context);
const char *test_get_obj_name(struct test_object *obj);
struct dentry *test_get_obj_dir(struct test_object *obj);
struct rb_root *test_get_obj_funcs(struct test_object *obj);

#endif /* _TEST_OBJECT_H_ */