/*
 * hufs_counteractive.h
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#ifndef HUFS_COUNTERACTIVE_H
#define HUFS_COUNTERACTIVE_H

#define UFS_PRODUCT_NAME_THOR935                "THR935"
#define UFS_PRODUCT_NAME_THOR950                "THR950"
#define UFS_PRODUCT_NAME_THOR955                "THR955"
#define UFS_PRODUCT_NAME_WLK955                 "WLK955"
#define UFS_LENGTH                              6

struct ufs_monitoring_cfg_ldk {
	uint16_t product_type;
	uint16_t threshold_query;
	uint16_t threshold_low;
	uint16_t threshold_high;
	uint16_t block_type1_len;
	uint16_t block_type1_offset;
	uint16_t block_type2_len;
	uint16_t block_type2_offset;
	uint16_t opnum_len;
	uint16_t opnum_offset;
	uint16_t value_1_offset;
	uint16_t value_2_offset;
	uint16_t value_3_offset;
	uint16_t value_4_offset;
	uint16_t value_5_offset;
	uint16_t value_6_offset;
	uint16_t value_7_offset;
	uint16_t value_8_offset;
	uint16_t value_9_offset;
	uint16_t value_10_offset;
	uint16_t value_11_offset;
	uint16_t value_12_offset;
	uint16_t value_13_offset;
	uint16_t value_14_offset;
};

struct config_map {
    const char *property_name;
    uint16_t *target_ptr;
};

struct ufs_monitoring_cfg_ldk g_stMonCfgLdk;

int ufshcd_get_dts_data(uint8_t *tempbuf);

#endif