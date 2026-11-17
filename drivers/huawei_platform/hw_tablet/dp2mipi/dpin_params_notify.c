/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * dpin_params_notify.c
 *
 * dpin_params_notify driver
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, pmicstributed, and mopmicfied under those terms.
 *
 * This program is pmicstributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include "dpin_params_notify.h"

#define hwlog_info(fmt, args...) pr_info("[dpin_params_notify]" fmt, ##args)
#define hwlog_err(fmt, args...) pr_err("[dpin_params_notify]" fmt, ##args)

struct video_device *g_vdev = NULL;
static struct class *g_video_class = NULL;

static int video_open(struct inode *inode, struct file *filp)
{
	hwlog_info("%s: Device is open\n", __func__);
	return 0;
}

static int video_release(struct inode *inode, struct file *filp)
{
	hwlog_info("%s: Device is released\n", __func__);
	return 0;
}

static long video_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return -ENOTTY;
	}
	struct dpin_params params;
	int ret = 0;

	switch (cmd) {
	case VIDEO_GET_PARAMS:
		mutex_lock(&g_vdev->lock);
		params = g_vdev->params;
		mutex_unlock(&g_vdev->lock);
		hwlog_info(
			"%s: event_type = %d, plug_status = %d, dp_mode = %d, is_signal_appear = %d, error_code = %d",
			__func__, params.event_type, params.plug_status,
			params.dp_mode, params.is_signal_appear,
			params.error_code);
		hwlog_info(
			"%s: hactive = %d, vactive = %d, frame = %d, is_device_support = %d, version = %d\n",
			__func__, params.hactive, params.vactive, params.frame,
			params.is_device_support, params.version);
		if (copy_to_user((void __user *)arg, &params, sizeof(params))) {
			ret = -EFAULT;
			hwlog_err("%s: user get params fail\n", __func__);
		} else {
			atomic_set(&g_vdev->data_ready, 0);
		}
		break;
	default:
		ret = -ENOTTY;
		hwlog_err("%s: invalid cmd\n", __func__);
	}
	return ret;
}

static unsigned int video_poll(struct file *filp, poll_table *wait)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return -ENOTTY;
	}
	unsigned int mask = 0;
	poll_wait(filp, &g_vdev->waitq, wait);
	if (atomic_read(&g_vdev->data_ready)) {
		mask |= POLLIN | POLLRDNORM;
	}
	return mask;
}

static struct file_operations video_fops = {
	.owner = THIS_MODULE,
	.open = video_open,
	.release = video_release,
	.unlocked_ioctl = video_ioctl,
	.poll = video_poll,
};

static void params_init(void)
{
	mutex_lock(&g_vdev->lock);
	g_vdev->params.plug_status = 0;
	g_vdev->params.is_signal_appear = 0;
	g_vdev->params.is_device_support = 0;
	g_vdev->params.hactive = 0;
	g_vdev->params.vactive = 0;
	g_vdev->params.frame = 0;
	g_vdev->params.error_code = 0;
	g_vdev->params.event_type = -1;
	g_vdev->params.dp_mode = 0;
	g_vdev->params.version = 1;
	mutex_unlock(&g_vdev->lock);
}

static int __init dpin_param_init(void)
{
	int ret;

	g_vdev = kzalloc(sizeof(*g_vdev), GFP_KERNEL);
	if (!g_vdev) {
		hwlog_err("%s: Failed to allocate device memory\n", __func__);
		return -ENOMEM;
	}

	ret = alloc_chrdev_region(&g_vdev->devno, 0, NUM_DEVICES, DEVICE_NAME);
	if (ret < 0) {
		hwlog_err("%s: Failed to allocate device id_number\n",
			  __func__);
		goto fail_alloc;
	}

	g_video_class = class_create(THIS_MODULE, DEVICE_CLASS);
	if (IS_ERR(g_video_class)) {
		hwlog_err("%s: Failed to create class\n", __func__);
		ret = -EBUSY;
		goto fail_class;
	}

	cdev_init(&g_vdev->cdev, &video_fops);
	g_vdev->cdev.owner = THIS_MODULE;
	ret = cdev_add(&g_vdev->cdev, g_vdev->devno, NUM_DEVICES);
	if (ret < 0) {
		hwlog_err("%s: Failed to add cdev\n", __func__);
		goto fail_cdev;
	}

	struct device *devices =
		device_create(g_video_class, NULL,
			      MKDEV(MAJOR(g_vdev->devno), MINOR(g_vdev->devno)),
			      NULL, DEVICE_NAME);
	if (!devices) {
		hwlog_err("%s: Failed to create devices\n", __func__);
		ret = -EBUSY;
		goto fail_device;
	}
	mutex_init(&g_vdev->lock);
	init_waitqueue_head(&g_vdev->waitq);
	atomic_set(&g_vdev->data_ready, 0);
	params_init();
	return 0;
fail_device:
	cdev_del(&g_vdev->cdev);
fail_cdev:
	class_destroy(g_video_class);
fail_class:
	unregister_chrdev_region(g_vdev->devno, NUM_DEVICES);
fail_alloc:
	kfree(g_vdev);
	return ret;
}

static void __exit dpin_param_exit(void)
{
	if (g_vdev) {
		device_destroy(g_video_class, MKDEV(MAJOR(g_vdev->devno),
						    MINOR(g_vdev->devno)));
		cdev_del(&g_vdev->cdev);
		unregister_chrdev_region(g_vdev->devno, NUM_DEVICES);
		kfree(g_vdev);
		g_vdev = NULL;
	}
	if (g_video_class) {
		class_destroy(g_video_class);
		g_video_class = NULL;
	}
}

void hal_trigger_event(void)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	atomic_set(&g_vdev->data_ready, 1);
	wake_up_interruptible(&g_vdev->waitq);
}
EXPORT_SYMBOL(hal_trigger_event);

module_init(dpin_param_init);
module_exit(dpin_param_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
MODULE_DESCRIPTION("Video Parameter Notification Driver");