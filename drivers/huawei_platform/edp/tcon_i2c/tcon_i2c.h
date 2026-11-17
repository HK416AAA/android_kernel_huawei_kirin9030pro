/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef _TCON_I2C_H_
#define _TCON_I2C_H_

#include <linux/mutex.h>
#define WRITE_CMD_HEAD 0x90
struct fw_name_list;
struct firmware;
extern struct mutex tcon_i2c_mutex;

int tcon_i2c_write_block(u8 *value, u32 len);
int tcon_i2c_read_block(u8 *value, u32 value_len);
int tcon_i2c_write_addr(unsigned int addr, unsigned int value);
unsigned int tcon_i2c_read_addr(unsigned int addr);
struct fw_name_list get_fw_name_list(void);
int check_tcon_firmware(const struct firmware **fw, uint16_t *vendor, uint16_t *version,
                        bool check_vendor, unsigned char partition);
void parse_edp_tcon_info(void);
#endif /* _TCON_I2C_H_ */
