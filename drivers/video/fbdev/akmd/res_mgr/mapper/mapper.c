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

#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/iommu/mm_iommu.h>
#include "mapper.h"
#include "aae_res_mgr.h"
#include "akmd_log.h"

static struct platform_device *g_rm_device;

static void *mapper_init(struct aae_res_data *rm_data)
{
	struct aae_res_mgr *rm = NULL;
	struct aae_mapper *mapper = kzalloc(sizeof(struct aae_mapper), GFP_KERNEL);
	if (!mapper)
		return NULL;

	rm = container_of(rm_data, struct aae_res_mgr, data);

	g_rm_device = rm->pdev;

	if (dma_set_mask_and_coherent(&rm->pdev->dev, DMA_BIT_MASK(64)) != 0)
		aae_pr_err("dma set mask and coherent failed");

	return mapper;
}

static void mapper_deinit(void *data)
{
	struct aae_mapper *mapper = NULL;

	if (!data)
		return;

	mapper = (struct aae_mapper *)data;
	kfree(mapper);
}

static struct dma_buf *mapper_map_dmabuf_by_sharefd(
	uint64_t *iova, int32_t fd, uint32_t size, uint32_t is_protect_layer)
{
	unsigned long buf_size = 0;
	struct dma_buf *buf = dma_buf_get(fd);

	if (IS_ERR_OR_NULL(buf)) {
		aae_pr_err("get dma buf fail, ret = %ld sharefd = %d", PTR_ERR(buf), fd);
		return NULL;
	}

	*iova = kernel_iommu_map_dmabuf(aae_res_get_device(), buf, 0, &buf_size);
	if ((*iova == 0) || (buf_size < size)) {
		aae_pr_err("get iova_size(0x%llx) smaller than size(0x%x)", buf_size, size);
		if (*iova != 0) {
			(void)kernel_iommu_unmap_dmabuf(aae_res_get_device(), buf, *iova);
			*iova = 0;
		}
		dma_buf_put(buf);
		return NULL;
	}
	dma_buf_put(buf);
	return buf;
}

static int32_t mapper_map_iova_buffer(void *data, void __user *argp)
{
	struct aae_dma_buf buf_data = {0};
	struct dma_buf *dmabuf;

	if (!argp) {
		aae_pr_err("argp is nullptr");
		return -1;
	}

	if (copy_from_user(&buf_data, argp, sizeof(buf_data))) {
		aae_pr_err("iova_info copy_from_user fail");
		return -EINVAL;
	}

	if (unlikely(buf_data.size == 0)) {
		aae_pr_err("size is 0!");
		return -EINVAL;
	}

	dmabuf =
		mapper_map_dmabuf_by_sharefd(&buf_data.iova, buf_data.share_fd, (uint32_t)buf_data.size, 0);
	if (!dmabuf) {
		aae_pr_err("dma buf map share_fd(%d) failed", buf_data.share_fd);
		return -EFAULT;
	}

	if (copy_to_user(argp, &buf_data, sizeof(buf_data)) != 0) {
		aae_pr_err("copy_to_user failed");
		(void)kernel_iommu_unmap_dmabuf(aae_res_get_device(), dmabuf, buf_data.iova);
		return -EFAULT;
	}

	aae_pr_debug("share_fd = %d map size = %llu", buf_data.share_fd, buf_data.size);
	return 0;
}

static int32_t mapper_unmap_iova_buffer(void *data, const void __user *argp)
{
	void_unused(data);
	void_unused(argp);

	// unmap will be called on buf release.
	return 0;
}

static long mapper_ioctl(struct aae_res_resouce_node *res_node, uint32_t cmd, void __user *argp)
{
	if (!res_node || !res_node->data || !argp) {
		aae_pr_err("res_node or node data or argp is NULL");
		return -EINVAL;
	}

	aae_pr_info("cmd %#x", cmd);

	switch (cmd) {
	case RES_MAP_IOVA:
		return mapper_map_iova_buffer(res_node->data, argp);
	case RES_UNMAP_IOVA:
		return mapper_unmap_iova_buffer(res_node->data, argp);
	default:
		aae_pr_debug("mem mgr unsupport cmd, need processed by other module");
		return 1;
	}

	return 0;
}

void aae_res_register_mapper(struct list_head *resource_head)
{
	struct aae_res_resouce_node *mapper_node = NULL;
	if (!resource_head)
		return;

	mapper_node = kzalloc(sizeof(struct aae_res_resouce_node), GFP_KERNEL);
	if (!mapper_node)
		return;

	mapper_node->res_type = RES_MAPPER;

	mapper_node->init = mapper_init;
	mapper_node->deinit = mapper_deinit;
	mapper_node->ioctl = mapper_ioctl;

	list_add_tail(&mapper_node->list_node, resource_head);
	aae_pr_debug("aae_res_register_mapper success!");
}
