/*
 * test_iomem.c
 *
 * test iomem
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
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include "test_system.h"

#define TEST_IOMEM_OBJ_NAME "iomem"

struct test_iomem_args {
	u32 io_addr;
	u32 io_mm_size;
};

void *test_iomem_alloc_args(struct dentry *dir)
{
	struct test_iomem_args *args = NULL;

	if (!dir)
		return NULL;

	args = kzalloc(sizeof(*args), GFP_KERNEL);
	if (!args)
		return NULL;

	args->io_addr = 0;
	args->io_mm_size = 0;
	debugfs_create_x32("io_addr", 0600, dir,
		&args->io_addr);
	debugfs_create_x32("io_mm_size", 0600, dir,
		&args->io_mm_size);
	return args;
}

void test_iomem_free_args(void *args)
{
	kfree(args);
}

static int test_iomem_remap(void *context, void *args)
{
	struct test_iomem_args *targ = args;
	void __iomem *virt_addr = NULL;
	u32 value;

	if (!targ || targ->io_addr == 0 || targ->io_mm_size < sizeof(u32))
		return -EINVAL;

	virt_addr = ioremap(targ->io_addr, targ->io_mm_size);
	if (!virt_addr)
		return -ENOMEM;

	value = readl(virt_addr);
	writel(value, virt_addr);
	iounmap(virt_addr);
	return 0;
}

#define test_iomem_f(_func_name, _run) \
	test_f_arg(TEST_IOMEM_OBJ_NAME, _func_name, _run, \
	test_iomem_alloc_args, test_iomem_free_args)

static int __init test_iomem_init(void)
{
	test_iomem_f("ioremap", test_iomem_remap);
	return 0;
}

static void __exit test_iomem_deinit(void)
{
}

module_init(test_iomem_init);
module_exit(test_iomem_deinit);