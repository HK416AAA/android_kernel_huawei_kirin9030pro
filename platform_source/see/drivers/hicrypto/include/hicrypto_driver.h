/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: hardware crypto engine driver
 * Create: 2023/03/07
 */

#ifndef __HICRYPTO_DRIVER_H__
#define __HICRYPTO_DRIVER_H__
#include <linux/scatterlist.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/device.h>

/* device info */
struct hicrypto_device {
	struct list_head list;
	struct device *dev;

	void __iomem *io_base;
	void __iomem *cfg_base;
	void __iomem *sce_base;
	void __iomem *km_base;

	/* reserved memory */
	void __iomem *reserved_vir_basei;
	void __iomem *reserved_vir_baseo;
	unsigned long  reserved_phy_base;
	unsigned int   reserved_size;

	bool polled;

	/* Interrupt wait queue */
	bool en_intr;
	unsigned int int_rcvd;
	wait_queue_head_t int_queue;

	int          major;
	struct class *dev_class;

	/* km valid flag */
	int km_valid_flag;
};


struct hicrypto_device *hicrypto_find_dev(struct hicrypto_device **dev);
#endif /* __HICRYPTO_DRIVER_H__ */
