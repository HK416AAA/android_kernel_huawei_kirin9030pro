/*
 * test_file.c
 *
 * test file
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

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#ifdef CONFIG_NVE_AP_KERNEL
#include <linux/mtd/nve_ap_kernel_interface.h>
#endif /* CONFIG_NVE_AP_KERNEL */
#include <securec.h>
#include "test_system.h"

#define TEST_FILE_OBJ_NAME "file"
#define TEST_FILE_PATH "/data/log/hilog/kapi_test.dat"

static int test_file_flip(void *context, void *args)
{
	struct file *fp = NULL;
	mm_segment_t old_fs;
	int data = 0x12345678; /* 0x12345678：test value */
	int rd_data = 0;
	loff_t pos = 0;
	int ret;

	old_fs = get_fs();
	set_fs(get_ds());
	set_fs(KERNEL_DS);

	fp = filp_open(TEST_FILE_PATH, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (IS_ERR_OR_NULL(fp))
		return (int)PTR_ERR(fp);

	ret = vfs_write(fp, (char *)&data, sizeof(int), &pos);
	if (ret != sizeof(int))
		goto vfs_test_done;
	vfs_fsync(fp, 0);

	pos = 0;
	ret = vfs_read(fp, (char *)&rd_data, sizeof(int), &pos);
	if (ret != sizeof(int))
		goto vfs_test_done;
	
	if (rd_data != data)
		ret = -EFAULT;

vfs_test_done:
	filp_close(fp, NULL);
	set_fs(old_fs);
	return ret;
}

#ifdef CONFIG_NVE_AP_KERNEL
struct test_file_nv_args {
	u32 nv_number;
	u32 valid_size;
};

void *test_file_nv_alloc_args(struct dentry *dir)
{
	struct test_file_nv_args *args = NULL;

	if (!dir)
		return NULL;

	args = kzalloc(sizeof(*args), GFP_KERNEL);
	if (!args)
		return NULL;

	args->nv_number = 0;
	args->valid_size = 0;
	debugfs_create_x32("nv_number", 0600, dir,
		&args->nv_number);
	debugfs_create_x32("valid_size", 0600, dir,
		&args->valid_size);
	return args;
}

void test_file_nv_free_args(void *args)
{
	kfree(args);
}

static int test_file_nv_read(void *context, void *args)
{
	struct test_file_nv_args *targ = args;
	struct opt_nve_info_user nv_info;

	if (!targ || targ->valid_size == 0)
		return -EINVAL;

	memset_s(&nv_info, sizeof(nv_info), 0,
		sizeof(nv_info));
	nv_info.nv_operation = NV_READ;
	nv_info.nv_number = targ->nv_number;
	nv_info.valid_size = targ->valid_size;
	return nve_direct_access_interface(&nv_info);
}
#endif /* CONFIG_NVE_AP_KERNEL */

static int __init test_file_init(void)
{
	test_f(TEST_FILE_OBJ_NAME, "flip", test_file_flip);
#ifdef CONFIG_NVE_AP_KERNEL
	test_f_arg(TEST_FILE_OBJ_NAME, "nv_read",
		test_file_nv_read, test_file_nv_alloc_args,
		test_file_nv_free_args);
#endif /* CONFIG_NVE_AP_KERNEL */
	return 0;
}

static void __exit test_file_deinit(void)
{
}

module_init(test_file_init);
module_exit(test_file_deinit);