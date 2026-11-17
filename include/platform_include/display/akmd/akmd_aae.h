/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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

#ifndef AKMD_AAE_H
#define AKMD_AAE_H

#include "akmd_res_mgr.h"

#define AAE_IOCTL_MAGIC 'A'

#define AAE_COMMIT _IOW(AAE_IOCTL_MAGIC, AAE_IOCTL_COMMIT, struct aae_commit)

enum {
	AAE_IOCTL_COMMIT = 0x10,
};

enum color_mode {
	COLOR_MODE_NATIVE = 0,
	COLOR_MODE_STANDARD_BT601_625 = 1,
	COLOR_MODE_STANDARD_BT601_625_UNADJUSTED = 2,
	COLOR_MODE_STANDARD_BT601_525 = 3,
	COLOR_MODE_STANDARD_BT601_525_UNADJUSTED = 4,
	COLOR_MODE_STANDARD_BT709 = 5,
	COLOR_MODE_DCI_P3 = 6,
	COLOR_MODE_SRGB = 7,
	COLOR_MODE_ADOBE_RGB = 8,
	COLOR_MODE_DISPLAY_P3 = 9,
	COLOR_MODE_BT2020 = 10,
	COLOR_MODE_BT2100_PQ = 11,
	COLOR_MODE_BT2100_HLG = 12,
};

#define COLOR_MODE_COUNT_MAX 5

#define AAE_HW_TYPE_FPGA 0
#define AAE_HW_TYPE_ASIC 1
#define AAE_SOC_TYPE_ES  0
#define AAE_SOC_TYPE_CS  1

enum aae_version_code {
	AAE_ACCEL_V100 = 0x8000,
	AAE_ACCEL_V200 = 0x8001,
};

union aae_version {
	uint64_t value;
	struct {
		uint64_t version   : 32;     /* serial number */
		uint64_t reserved1 : 16;
		uint64_t hw_type   : 1;      /* fpga or asic */
		uint64_t soc_type  : 1;     /* es or cs */
		uint64_t reserved2 : 14;
	} info;
};

struct aae_layer {
	int32_t share_fd;
	int32_t acquired_fence;
	uint32_t format;
	uint32_t stride;
	bool is_protected_mode;
};

#define AAE_LAYER_MAX_COUNT 6
struct aae_commit {
	uint32_t scene_id;
	uint64_t cmdlist_id;
	uint32_t layer_count;
	int32_t protected_wch_id;  // add for drm layers config
	struct aae_layer layer[AAE_LAYER_MAX_COUNT];
	uint32_t commit_index;
	uint32_t perf_level;
};

#endif
