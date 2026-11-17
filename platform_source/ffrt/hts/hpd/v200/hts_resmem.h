/*
 * hts_resmem.h
 *
 * about hts resmem
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

#ifndef _HTS_RESMEM_H_
#define _HTS_RESMEM_H_

#include <linux/types.h>
#include "hts_platform.h"

typedef union {
	uint32_t value;
	struct {
		uint32_t valid              :1;   // bit 0
		uint32_t rsv                :3;   // bit 1~3  reserved
		uint32_t src_id             :6;   // bit 4~9
		uint32_t dst_id             :6;   // bit 10~15
		uint32_t uid                :12;  // bit 16~27  reserved
		uint32_t rsv1               :4;
	} data;
} hts_check_table;

void hts_plat_get_resmem_info(struct hts_platform_info *plat_info);
int hts_set_auth_table(u32 event, hts_check_table* check_table);
int hts_get_auth_table(u32 event, hts_check_table* check_table);

#endif