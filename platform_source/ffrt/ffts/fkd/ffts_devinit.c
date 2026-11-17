/*
 * ffts_devinit.c
 *
 * ffts device driver
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
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

#include "ffts_devinit.h"

#include <linux/slab.h>

#include "ffts_ioctl_services.h"
#include "ffts_log.h"
#include "ffts_map.h"
#include "ffts_proc_ctx.h"
#include "inc/ffts_common.h"

static dev_t g_ffts_devno;
static struct class *g_ffts_dev_class = NULL;

static int ffts_open(struct inode *inode, struct file *filep)
{
	int ret;
	struct ffts_dev_ctx *dev_ctx = NULL;
	ffts_drv_warn("ffts open start\n");

	dev_ctx = ffts_get_dev_ctx();
	cond_return_error(dev_ctx == NULL, -ENODEV, "get dev_ctx failed\n");

	ret = ffts_create_proc_ctx(dev_ctx, filep);
	cond_return_error(ret != 0, ret,
		"ffts_create_proc_ctx fail ret = %d.\n", ret);

	ffts_drv_warn("ffts open success\n");
	return ret;
}

static int ffts_release(struct inode *inode, struct file *filep)
{
	int ret;
	struct ffts_dev_ctx *dev_ctx = NULL;
	ffts_drv_warn("ffts close start\n");

	dev_ctx = ffts_get_dev_ctx();
	cond_return_error(dev_ctx == NULL, -ENODEV, "get dev_ctx failed\n");

	ret = ffts_release_proc_ctx(dev_ctx, filep);
	cond_return_error(ret != 0, ret,
		"ffts_release_proc_ctx fail ret = %d.\n", ret);

	ffts_drv_warn("ffts close end\n");
	return ret;
}

static const struct file_operations ffts_dev_fops = {
	.owner = THIS_MODULE,
	.open = ffts_open,
	.release = ffts_release,
	.unlocked_ioctl = ffts_ioctl,
	.compat_ioctl = ffts_ioctl,
	.mmap = ffts_map,
};

static char *ffts_dev_node(struct device *dev, umode_t *mode)
{
	unused(dev);
	if (mode != NULL)
		*mode = 666;
	return NULL;
}

static void ffts_dev_ctx_init(struct ffts_dev_ctx *dev_ctx)
{
	int hw_type = 0;
	INIT_LIST_HEAD(&dev_ctx->proc_ctx_list_head);
	mutex_init(&dev_ctx->proc_ctx_lock);
	atomic_set(&dev_ctx->excp_status_manager, FFTS_EXCP_POWER_UP);
	for (; hw_type < FFTS_MAX_HW_NUM; hw_type++)
		dev_ctx->proc_block_hw_reg.registered_hw[hw_type] = 0;
	atomic_set(&dev_ctx->proc_block_hw_reg.target_cnt, 0);
	atomic_set(&dev_ctx->proc_block_hw_reg.ready_cnt, 0);
	mutex_init(&dev_ctx->ffts_cmo_lock);
	mutex_init(&dev_ctx->ffts_hw_operation_lock);
	init_waitqueue_head(&dev_ctx->proc_block_wait);
	mutex_init(&dev_ctx->ffts_excp_lock);
}

static void ffts_dev_ctx_deinit(struct ffts_dev_ctx *dev_ctx)
{
	mutex_destroy(&dev_ctx->ffts_hw_operation_lock);
	mutex_destroy(&dev_ctx->ffts_cmo_lock);
	atomic_set(&dev_ctx->excp_status_manager, FFTS_EXCP_POWER_DOWN);
	mutex_destroy(&dev_ctx->proc_ctx_lock);
	mutex_destroy(&dev_ctx->ffts_excp_lock);
}

int ffts_dev_register(void)
{
	struct ffts_dev_ctx *dev_ctx = NULL;
	struct device *i_device = NULL;
	int ret;
	ffts_drv_info("ffts dev is registering\n");

	// 1. create dev_ctx
	dev_ctx = kzalloc(sizeof(struct ffts_dev_ctx), GFP_KERNEL);
	cond_return_error(dev_ctx == NULL, -ENOMEM, "kmalloc dev_ctx failed\n");

	ret = alloc_chrdev_region(&g_ffts_devno, 0, FFTS_DEV_NUM, "ffts-cdev");
	cond_goto_error(ret != 0, alloc_chrdev_fail, ret, -EINVAL,
		"ffts alloc chrdev region error\n");

	g_ffts_dev_class = class_create(THIS_MODULE, "ffts");
	cond_goto_error(IS_ERR(g_ffts_dev_class), class_fail, ret, -EINVAL,
		"ffts_class create error\n");
	g_ffts_dev_class->devnode = ffts_dev_node;

	dev_ctx->ffts_cdev.owner = THIS_MODULE;
	cdev_init(&dev_ctx->ffts_cdev, &ffts_dev_fops);
	ret = cdev_add(&dev_ctx->ffts_cdev, g_ffts_devno, FFTS_DEV_NUM);
	cond_goto_error(ret != 0, cdev_add_fail, ret, ret, "ffts cdev_add error\n");

	i_device = device_create(g_ffts_dev_class, NULL, g_ffts_devno, NULL, "ffts");
	cond_goto_error(i_device == NULL, device_create_fail, ret, -ENOMEM,
		"ffts device_create error\n");
	dev_ctx->ffts_dev = i_device;

	ffts_dev_ctx_init(dev_ctx);

	ffts_set_dev_ctx(dev_ctx);

	return 0;
device_create_fail:
	cdev_del(&dev_ctx->ffts_cdev);
cdev_add_fail:
	class_destroy(g_ffts_dev_class);
class_fail:
	unregister_chrdev_region(g_ffts_devno, FFTS_DEV_NUM);
alloc_chrdev_fail:
	kfree(dev_ctx);
	return ret;
}

void ffts_dev_unregister(void)
{
	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();
	cond_return_void(dev_ctx == NULL, "dev_ctx is null\n");

	ffts_set_dev_ctx(NULL);

	ffts_dev_ctx_deinit(dev_ctx);

	cond_return_void(g_ffts_dev_class == NULL, "dev_class is null\n");
	device_destroy(g_ffts_dev_class, g_ffts_devno);
	cdev_del(&dev_ctx->ffts_cdev);
	class_destroy(g_ffts_dev_class);
	g_ffts_dev_class = NULL;
	unregister_chrdev_region(g_ffts_devno, FFTS_DEV_NUM);
	kfree(dev_ctx);
	dev_ctx = NULL;
}