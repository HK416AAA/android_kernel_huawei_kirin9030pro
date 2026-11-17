/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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
#ifndef DPU_DRM_FUSA_DATA_H
#define DPU_DRM_FUSA_DATA_H
#include <linux/types.h>
#include <linux/notifier.h>

#define FFD_ROI_CNT_MAX 32
#define FFD_ROI_AREA_MAX 2048

enum ffd_mode_type {
	DPU_DRM_FFD_FRAME = 0,
	DPU_DRM_FFD_ROI0,
	DPU_DRM_FFD_ROI1,
	DPU_DRM_FFD_MODE_CNT,
};

enum dpu_drm_action {
	DPU_DRM_FFD_ENABLE = 0,
	DPU_DRM_FFD_DISABLE,
	DPU_DRM_ISR_RESULT,
	DPU_DRM_FFD_RESULT,
};

struct dpu_drm_roi_rect {
	int32_t x;
	int32_t y;
	uint32_t w;
	uint32_t h;
};

struct dpu_drm_ffd_roi_cfg {
	struct dpu_drm_roi_rect roi_area;
	bool roi_en;
	uint8_t roi_index;
};
struct dpu_drm_ffd_cfg {
	bool ffd_en;
	enum ffd_mode_type ffd_mode;
	uint32_t mode0_roi_cfg_bytes; // ROI0 mode
	struct dpu_drm_ffd_roi_cfg roi_cfg[FFD_ROI_CNT_MAX]; // ROI1 mode
};

struct dpu_drm_ffd_info {
	struct dpu_drm_ffd_cfg ffd_cfg;
	uint32_t ffd_result;
};

int fusa_register_client(struct notifier_block *nb);

int fusa_unregister_client(struct notifier_block *nb);

int fusa_notifier_call_chain(unsigned long val, void *v);
#endif