/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * either version 2 of that License or (at your option) any later version.
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef VSMMU_H
#define VSMMU_H

#define MAX_ENTRY			512

enum smmu_option_type {
	SMMU_MAP,
	SMMU_UNMAP
};

struct map_info_entry {
	void *base;
	int len;
};

struct iommu_map_info {
	struct map_info_entry mi_entry[MAX_ENTRY];
	int entry;
};

struct iommu_head_info {
	uint64_t vfb_buf_key;
	int ops_code;
	int sg_nents;
	uint64_t map_size;
	int err_code;
	unsigned long out_size;
};
 #endif