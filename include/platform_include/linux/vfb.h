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

#ifndef _VFB_H_
#define _VFB_H_

#include <linux/types.h>
#include <platform_include/display/dkmd/dkmd_dpu.h>
#include <platform_include/display/dkmd/dkmd_vfb.h>

#define VIRTIO_FB_PRESENT_LAYER_NUM	1
#define SCENE_SPLIT_MAX 4
#define COLOR_MODE_COUNT_MAX 5

// use for display's driver and device feature
struct virtio_fb_layer_info {
	uint32_t format;
	uint32_t stride;
	uint64_t buf_key;
	uint64_t iova;
};

struct virtio_fb_present_data {
	uint32_t frame_no;
	uint32_t magic_num;
	uint32_t layer_nums;
	struct virtio_fb_layer_info layer_infos[VIRTIO_FB_PRESENT_LAYER_NUM];
};

typedef void (*release_func_t)(void *vq, int head, int len);

#ifdef CONFIG_VFB_BE
int vfb_get_product_config(void *data, int len);
int vfb_present(void *data, int len, release_func_t func, void *vq, int head);
struct virtio_fb_present_data *vfb_acquire_present_data(void);
void vfb_flush(void);
void vfb_start_distribute_present_data(void);
void vfb_stop_distribute_present_data(void);
int vfb_init(void);
void vfb_deinit(void);
void vfb_virtio_trigger_except(void);
#else

static inline int vfb_get_product_config(void *data, int len)
{
	return -EINVAL;
}

static inline int vfb_present(void *data, int len, release_func_t func, void *vq, int head)
{
	return -EINVAL;
}

static inline struct virtio_fb_present_data *vfb_acquire_present_data(void)
{
	return NULL;
}

static void vfb_flush(void)
{
	return;
}

static inline void vfb_start_distribute_present_data(void)
{
	return;
}

static inline void vfb_stop_distribute_present_data(void)
{
	return;
}

static inline int vfb_init(void)
{
	return -EINVAL;
}

static inline void vfb_deinit(void)
{
	return;
}
static void vfb_virtio_trigger_except(void)
{
	return;
}
#endif
#endif
