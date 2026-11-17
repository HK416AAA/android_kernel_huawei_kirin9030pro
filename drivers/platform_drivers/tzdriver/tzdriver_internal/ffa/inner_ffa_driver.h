/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: header file inner ffa module
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef INNER_FFA_DRIVER_H
#define INNER_FFA_DRIVER_H

#include <linux/device.h>
#include <linux/types.h>
#include "tc_linux_def.h"

#define FFA_MSG_SEND_DIRECT_REQ_SMC32           0x8400006f
#define FFA_MSG_SEND_DIRECT_REQ_SMC64           0xC400006f
#define FFA_MSG_SEND_DIRECT_RESP_SMC32          0x84000070
#define FFA_MSG_SEND_DIRECT_RESP_SMC64          0xC4000070
#define FFA_INTERRUPT                           0x84000062
#define FFA_ERROR                               0x84000060
#define FFA_SUCCESS_SMC32                       0x84000061
#define FFA_SUCCESS_SMC64                       0xC4000061

/* FFA Bus/Device/Driver related */
struct ffa_device {
	int vm_id;
	bool mode_32bit;
	uuid_t uuid;
	struct device dev;
	const struct ffa_ops *ops;
};

struct ffa_device_id {
	uuid_t uuid;
};

struct ffa_driver {
	const char *name;
	int (*probe)(struct ffa_device *sdev);
	void (*remove)(struct ffa_device *sdev);
	const struct ffa_device_id *id_table;

	struct device_driver driver;
};

struct ffa_send_direct_data {
	unsigned long data0; /* w3/x3 */
	unsigned long data1; /* w4/x4 */
	unsigned long data2; /* w5/x5 */
	unsigned long data3; /* w6/x6 */
	unsigned long data4; /* w7/x7 */
};

struct ffa_ops {
	void (*mode_32bit_set)(struct ffa_device *dev);
	int (*sync_send_receive)(struct ffa_device *dev, struct ffa_send_direct_data *data);
};

int ffa_register(struct ffa_driver *driver);
int ffa_unregister(struct ffa_driver *driver);

#endif
