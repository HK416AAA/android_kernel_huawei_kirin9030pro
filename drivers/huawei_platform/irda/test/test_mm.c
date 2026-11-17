/*
 * test_mm.c
 *
 * test memory
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
#include <linux/vmalloc.h>
#include <linux/gfp.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include "test_system.h"

#define TEST_MM_DEFAULT_SIZE 256
#define TEST_MM_DEFAULT_GFP_T GFP_KERNEL

struct test_mm_normal_args {
	u32 alloc_size;
	u32 gfp_flags;
};

static void *test_mm_alloc_normal_args(struct dentry *dir)
{
	struct test_mm_normal_args *args = NULL;

	if (!dir)
		return NULL;

	args = kzalloc(sizeof(*args), GFP_KERNEL);
	if (!args)
		return NULL;

	args->alloc_size = TEST_MM_DEFAULT_SIZE;
	args->gfp_flags = TEST_MM_DEFAULT_GFP_T;
	debugfs_create_x32("alloc_size", 0600, dir,
		&args->alloc_size);
	debugfs_create_x32("gfp_flags", 0600, dir,
		&args->gfp_flags);
	return args;
}

static void test_mm_free_normal_args(void *args)
{
	kfree(args);
}

#define test_mm_normal_f(_func_name, _run) \
	test_f_arg("normal_mm", _func_name, _run, \
	test_mm_alloc_normal_args, test_mm_free_normal_args)

static int test_mm_vmalloc(void *context, void *args)
{
	struct test_mm_normal_args *sargs = args;
	void *tmp = NULL;

	if (!sargs)
		return -EINVAL;

	tmp = vmalloc(sargs->alloc_size);
	if (!tmp)
		return -ENOMEM;
	vfree(tmp);
	return 0;
}

static int test_mm_vzalloc(void *context, void *args)
{
	struct test_mm_normal_args *sargs = args;
	void *tmp = NULL;

	if (!sargs)
		return -EINVAL;

	tmp = vzalloc(sargs->alloc_size);
	if (!tmp)
		return -ENOMEM;
	vfree(tmp);
	return 0;
}

static int test_mm_kmalloc(void *context, void *args)
{
	struct test_mm_normal_args *sargs = args;
	void *tmp = NULL;

	if (!sargs)
		return -EINVAL;

	tmp = kmalloc(sargs->alloc_size, sargs->gfp_flags);
	if (!tmp)
		return -ENOMEM;
	kfree(tmp);
	return 0;
}

static int test_mm_kzalloc(void *context, void *args)
{
	struct test_mm_normal_args *sargs = args;
	void *tmp = NULL;

	if (!sargs)
		return -EINVAL;

	tmp = kzalloc(sargs->alloc_size, sargs->gfp_flags);
	if (!tmp)
		return -ENOMEM;
	kfree(tmp);
	return 0;
}

static int __init test_mm_init(void)
{
	test_mm_normal_f("vmalloc", test_mm_vmalloc);
	test_mm_normal_f("vzalloc", test_mm_vzalloc);
	test_mm_normal_f("kmalloc", test_mm_kmalloc);
	test_mm_normal_f("kzalloc", test_mm_kzalloc);
	return 0;
}

static void __exit test_mm_deinit(void)
{
}

module_init(test_mm_init);
module_exit(test_mm_deinit);