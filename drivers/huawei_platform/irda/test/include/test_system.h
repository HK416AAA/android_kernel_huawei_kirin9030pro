/*
 * test_system.h
 *
 * test system
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

#ifndef _TEST_SYSTEM_H_
#define _TEST_SYSTEM_H_

#include <linux/rbtree.h>
#include <linux/mutex.h>
#include <linux/list.h>
#include <linux/debugfs.h>
#include <linux/dcache.h>
#include "test_func.h"
#include "test_object.h"

struct test_case_pool;

struct test_system {
	struct rb_root objects;
	struct mutex olock;
	int enable_log;
	int max_case_id;
	struct dentry *root_dir;
	struct test_case_pool *active_cases;
	struct test_case_pool *inactive_cases;
	struct delayed_work del_work;
	struct mutex dlock;
};

struct test_system *test_get_system(void);
void test_try_reclaim_case(void);

#define test_object(obj_name, setup, teardown) \
do { \
	struct test_system *sys = test_get_system(); \
	if (sys) { \
		mutex_lock(&sys->olock); \
		test_register_object(&sys->objects, obj_name, setup, teardown); \
		mutex_unlock(&sys->olock); \
	} \
} while (0)

#define test_f(_obj_name, _func_name, _run) \
do { \
	struct test_system *sys = test_get_system(); \
	if (sys) { \
		struct test_func_register func = { \
			.obj_name = (_obj_name), \
			.name = (_func_name), \
			.alloc_args = NULL, \
			.free_args = NULL, \
			.run = (_run), \
			.print_result = NULL, \
		}; \
		mutex_lock(&sys->olock); \
		test_register_func(&sys->objects, &func); \
		mutex_unlock(&sys->olock); \
	} \
} while (0)

#define test_f_r(_obj_name, _func_name, _run, _print) \
do { \
	struct test_system *sys = test_get_system(); \
	if (sys) { \
		struct test_func_register func = { \
			.obj_name = (_obj_name), \
			.name = (_func_name), \
			.alloc_args = NULL, \
			.free_args = NULL, \
			.run = (_run), \
			.print_result = (_print), \
		}; \
		mutex_lock(&sys->olock); \
		test_register_func(&sys->objects, &func); \
		mutex_unlock(&sys->olock); \
	} \
} while (0)

#define test_f_arg(_obj_name, _func_name, _run, \
	_alloc_args, _free_args) \
do { \
	struct test_system *sys = test_get_system(); \
	if (sys) { \
		struct test_func_register func = { \
			.obj_name = (_obj_name), \
			.name = (_func_name), \
			.alloc_args = (_alloc_args), \
			.free_args = (_free_args), \
			.run = (_run), \
			.print_result = NULL, \
		}; \
		mutex_lock(&sys->olock); \
		test_register_func(&sys->objects, &func); \
		mutex_unlock(&sys->olock); \
	} \
} while (0)

#define test_f_r_arg(_obj_name, _func_name, _run, \
	_alloc_args, _free_args, _print) \
do { \
	struct test_system *sys = test_get_system(); \
	if (sys) { \
		struct test_func_register func = { \
			.obj_name = (_obj_name), \
			.name = (_func_name), \
			.alloc_args = (_alloc_args), \
			.free_args = (_free_args), \
			.run = (_run), \
			.print_result = (_print), \
		}; \
		mutex_lock(&sys->olock); \
		test_register_func(&sys->objects, &func); \
		mutex_unlock(&sys->olock); \
	} \
} while (0)

#endif /* _TEST_SYSTEM_H_ */