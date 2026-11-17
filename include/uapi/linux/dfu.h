/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2020. All rights reserved.
 * Description: head file for dfu
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

#ifndef _UAPI_DFU_H
#define _UAPI_DFU_H

#include <linux/types.h>

struct dfu_status {
	__u8  bStatus;
	__u8  bwPollTimeout0;
	__u8  bwPollTimeout1;
	__u8  bwPollTimeout2;
	__u8  bState;
	__u8  iString;
} __attribute__ ((packed));

#define DFU_MAX_WRITE_SIZE	0x100000
#define DFU_MAX_READ_SIZE	0x100000

/* ioctrl interface */
#define DFUIOCDETACH			_IO('D', 0x1)
#define DFUIOCDOWNLOAD(len)		_IOC(_IOC_WRITE|_IOC_READ, 'D', 0x2, len)
#define DFUIOCGETSTATUS			_IOR('D', 0x3, struct dfu_status)
#define DFUIOCABORT			_IO('D', 0x4)
#define DFUIOCFINISHDNLOAD		_IO('D', 0x5)

#endif /* _UAPI_DFU_H */
