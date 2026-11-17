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

#ifndef _TCON_I2C_UPGRADE_H_
#define _TCON_I2C_UPGRADE_H_

#define TCON_BIN_MAX 6
#define PARTITIONS_START_ADDR 0xF1010090
#define CHECK_CHANGE_PARTITIONS_ADDR 0xF10100F8
enum tcon_upgrade_result {
    TCON_CHECK_SUCCESS,
    TCON_NOT_NEED_UPGRADE,
    TCON_UNSUPPORT_LOGO_BIN,
    TCON_MAGIC_NUMBER_ERR,
    TCON_VENDOR_NOT_MATCH,
};

enum ext_update_status {
    UPDATE_WAITING,
    UPDATE_FAIL,
    UPDATE_SUCESS,
    UPDATE_DOING,
};

enum update_partitions {
    EXT_PARTITION,
    MAIN_PARTITION,
};

struct fw_name_list {
    int count;
    const char *name_list[TCON_BIN_MAX];
};

struct bin_vendor_info {
    unsigned short vendor;
    unsigned short version;
};

int get_tconic_vendor(unsigned short *vendor, unsigned short *version);
int check_bin_valid(const struct firmware *fw, unsigned short tcon_vendor,
                    unsigned short tcon_version, bool vendor_check_enable, bool main_flag);
int update_tconic_fw_request(const struct firmware *fw, unsigned short tcon_vendor,
                             unsigned short tcon_version, bool main_flag);
uint8_t get_update_status(void);
int extra_upgrade_switch_boot(unsigned char pos);
struct bin_vendor_info* get_bin_vendor_info(void);
#endif /* _TCON_I2C_UPGRADE_H_ */
