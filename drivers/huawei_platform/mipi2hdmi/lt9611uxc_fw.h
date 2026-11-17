/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * lt9611uxc_fw.h
 *
 * lt9611uxc firmware update
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
#ifndef _LT9611UXC_FW_H
#define _LT9611UXC_FW_H

#include <linux/i2c.h>
#include <linux/of.h>

typedef void (*hard_reset_func_t)(void);

#define UPDATE_ECODE_OK 0
#define UPDATE_ECODE_NULL_PTR (-1000)
#define UPDATE_ECODE_PARA (-1001)
#define UPDATE_ECODE_READ_DTS (-1002)
#define UPDATE_ECODE_F_OPEN (-1003)
#define UPDATE_ECODE_KZALLOC (-1004)
#define UPDATE_ECODE_VFS_READ (-1005)
#define UPDATE_ECODE_GET_IC_VER (-1006)
#define UPDATE_ECODE_NO_NEW (-1007)
#define UPDATE_ECODE_FW_MEM_COMP (-1008)
#define UPDATE_ECODE_NO_ROLLBACK (-1012)

int lt9611uxc_write_block(struct i2c_client *client, unsigned char reg, unsigned char *value, unsigned short num_bytes);
int lt9611uxc_read_block(struct i2c_client *client, unsigned char reg, unsigned char *value, unsigned short num_bytes);
int lt9611uxc_update(struct i2c_client *client, struct device_node *node, hard_reset_func_t reset_func);

#endif // _LT9611UXC_FW_H