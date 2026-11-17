/*
 * isp rpmsg client driver
 *
 * Copyright (c) 2025- ISP Technologies CO., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/scatterlist.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/jiffies.h>
#include <linux/mutex.h>
#include <linux/wait.h>
#include <linux/skbuff.h>
#include <linux/sched.h>
#include <linux/rpmsg.h>
#include <linux/completion.h>
#include <linux/dma-buf.h>
#ifdef CONFIG_ION
#include <linux/ion.h>
#include <linux/ion/mm_ion.h>
#elif defined CONFIG_DMABUF_HEAPS
#include <linux/dma-heap.h>
#include <linux/dmabuf/mm_dma_heap.h>
#endif
#include <linux/iommu/mm_iommu.h>
#include <linux/iommu.h>
#include <linux/version.h>
#include <linux/miscdevice.h>
#include <uapi/linux/isp.h>
#include <platform_include/isp/linux/hisp_remoteproc.h>
#include <platform_include/isp/linux/hisp_mempool.h>
#include <securec.h>
#include <hisp_internel.h>
#include "hisp_rpmsg.h"

struct hisp_rpmsg_device {
	struct mutex sendlock;
	struct rpmsg_device *rpdev;
	struct rpmsg_endpoint *ept;
	struct completion isp_comp;
	hisp_rpmsg_cb callback[MAX_OP];
};

static struct hisp_rpmsg_device hisp_rpmsg_dev = {0};

#define TIMEOUT_IS_FPGA_BOARD 500000
#define TIMEOUT_IS_NOT_FPGA_BOARD 15000

int hisp_rpmsg_wait_handshake(void)
{
	int rc = 0;
	int ret = 0;
	uint32_t timeout = hw_is_fpga_board() ?
		TIMEOUT_IS_FPGA_BOARD : TIMEOUT_IS_NOT_FPGA_BOARD;

	rc = (int)wait_for_completion_timeout(&hisp_rpmsg_dev.isp_comp,
		msecs_to_jiffies(timeout));
	if (rc == 0) {
		pr_err("%s:wait isp_fw rpmsg handshake failed", __func__);
		ret = -1;
	}

	reinit_completion(&hisp_rpmsg_dev.isp_comp);

	return ret;
}

void hisp_rpmsg_handshake_init(void)
{
	reinit_completion(&hisp_rpmsg_dev.isp_comp);
}

void hisp_rpmsg_handshake_complete(void)
{
	complete(&hisp_rpmsg_dev.isp_comp);
}

void hisp_rpmsg_register_callback(unsigned int master, hisp_rpmsg_cb callback)
{
	if (master >= MAX_OP) {
		pr_err("%s:master %u too big", __func__, master);
		return;
	}
	hisp_rpmsg_dev.callback[master] = callback;
}

int hisp_rpmsg_send(enum hisp_op_master_e master, void *data, int len)
{
	int rc = 0;
	struct isp_msg_content *msg_data = NULL;

	if ((data == NULL) || (len <= 0) || (len > (int)sizeof(struct isp_msg_content))) {
		pr_err("%s: itf or imsg NULL, or len:%d", __func__, len);
		return -EINVAL;
	}

	msg_data = (struct isp_msg_content *)data;

	pr_debug("%s: master:%d, api_name:%#x, message_id:%#x", __func__,
		master, msg_data->info.api_name, msg_data->info.message_id);

	hisp_sendin(&msg_data);
	mutex_lock(&hisp_rpmsg_dev.sendlock); // protect against async remove
	if (hisp_rpmsg_dev.ept)
		rc = rpmsg_send(hisp_rpmsg_dev.ept, (void *)msg_data, len);
	else
		rc = -ENODEV;
	mutex_unlock(&hisp_rpmsg_dev.sendlock);
	if (rc)
		pr_err("%s: rpmsg_send ret is %d", __func__, rc);
	return rc;
}

void hisp_rpmsg_receive(enum hisp_op_master_e master, void *data, int len)
{
	if (master >= MAX_OP) {
		pr_err("func %s: master:%d out of range", __func__, master);
		return;
	}

	if (hisp_rpmsg_dev.callback[master] != NULL) {
		hisp_rpmsg_dev.callback[master](data, len);
	} else {
		pr_err("func %s: receive rpmsg while callback function not registered", __func__);
		return;
	}
}

void hisp_rpmsg_set_ept(struct rpmsg_endpoint *ept)
{
	pr_info("[%s]+\n", __func__);
	hisp_rpmsg_dev.ept = ept;
	if (ept != NULL) {
		if (ept->rpdev != NULL) {
			pr_info("[%s] name %s\n", __func__, ept->rpdev->id.name);
		}
	}
	pr_info("[%s]-\n", __func__);
}

static int hisp_rpmsg_ept_cb(struct rpmsg_device *rpdev,
	void *data, int len, void *priv, u32 src)
{
	struct isp_msg_content *msg_data = NULL;
	unsigned int dst_master = MAX_OP;

	(void)src;
	(void)rpdev;
	(void)priv;

	if (!data || len <= 0) {
		pr_err("func %s: data NULL or len:%d", __func__, len);
		return -EINVAL;
	}

	msg_data = (struct isp_msg_content *)data;

	if ((msg_data->info.api_name >= RPMSG_CAMERA_START) && (msg_data->info.api_name <= RPMSG_CAMERA_END)) {
		dst_master = CAMERA_OP;
	} else if ((msg_data->info.api_name >= RPMSG_CANN_START) && (msg_data->info.api_name <= RPMSG_CANN_END)) {
		dst_master = CANN_OP;
	}

	if (dst_master >= MAX_OP) {
		pr_err("func %s: msg api_name:%u out of range", __func__, msg_data->info.api_name);
		return -EINVAL;
	}

	if (hisp_rpmsg_dev.callback[dst_master] != NULL) {
		hisp_rpmsg_dev.callback[dst_master](data, len);
	} else {
		pr_err("func %s: receive rpmsg while callback function not registered", __func__);
		return -EINVAL;
	}

	return 0;
}

static int32_t hisp_rpmsg_probe(struct rpmsg_device *rpdev)
{
	pr_info("%s enter", __func__);

	if (hisp_rpmsg_dev.rpdev) {
		pr_warn("%s rpdev is already up", __func__);
		return -EBUSY;
	}

	if (!rpdev || !rpdev->ept) {
		pr_err("%s: rpdev NULL or rpdev->ept not created!", __func__);
		return -ENOENT;
	}

	hisp_rpmsg_dev.rpdev = rpdev;
	dev_set_drvdata(&rpdev->dev, &hisp_rpmsg_dev);

	pr_info("new KERNEL connection srv channel: %u -> %u",
		rpdev->src, rpdev->dst);
	return 0;
}

static void hisp_rpmsg_remove(struct rpmsg_device *rpdev)
{
	pr_info("%s enter ... ", __func__);
	mutex_lock(&hisp_rpmsg_dev.sendlock);
	if (rpdev != hisp_rpmsg_dev.rpdev)
		pr_warn("%s: removing rpdev not same as probed", __func__);
	hisp_rpmsg_dev.rpdev = NULL;
	mutex_unlock(&hisp_rpmsg_dev.sendlock);
	pr_info("%s: rpmsg kernel driver is removed", __func__);
}

static struct rpmsg_device_id rpmsg_hisp_id_table[] = {
	{.name = "rpmsg-isp-cann"},
	{},
};

MODULE_DEVICE_TABLE(platform, rpmsg_hisp_id_table);

/* lint -save -e485 */
static struct rpmsg_driver hisp_rpmsg_driver = {
	.drv.name = KBUILD_MODNAME,
	.drv.owner = THIS_MODULE,
	.id_table = rpmsg_hisp_id_table,
	.probe = hisp_rpmsg_probe,
	.callback = hisp_rpmsg_ept_cb,
	.remove = hisp_rpmsg_remove,
};
/* lint -restore */

static int __init hisp_rpmsg_init(void)
{
	int ret = 0;

	pr_info("Enter ...\n");

	hisp_rpmsg_dev.rpdev = NULL;
	hisp_rpmsg_dev.callback[CAMERA_OP] = NULL;
	hisp_rpmsg_dev.callback[CANN_OP] = NULL;

	mutex_init(&hisp_rpmsg_dev.sendlock);
	init_completion(&hisp_rpmsg_dev.isp_comp);

	ret = register_rpmsg_driver(&hisp_rpmsg_driver);
	if (ret != 0) {
		pr_err("[%s] register_rpmsg_driver error ret %d", __func__, ret);
	}

	pr_info("Exit ...\n");

	return ret;
}

static void __exit hisp_rpmsg_exit(void)
{
	pr_info("Enter ...\n");

	unregister_rpmsg_driver(&hisp_rpmsg_driver);

	pr_info("Exit ...\n");
}

module_init(hisp_rpmsg_init);
module_exit(hisp_rpmsg_exit);

MODULE_DESCRIPTION("ISP rpmsg driver");
MODULE_LICENSE("GPL v2");
