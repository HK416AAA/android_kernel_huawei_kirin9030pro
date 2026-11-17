/*
 * npu_extend_param.c
 *
 * about npu extend param
 *
 * Copyright (c) 2012-2020 Huawei Technologies Co., Ltd.
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
#ifdef CONFIG_SUPPORT_AI_IN_FLASH
#include "npu_extend_param.h"
#include "npu_iova.h"
#include "npu_pool.h"
#include "npu_shm.h"
#include "npu_id_allocator.h"
#include <securec.h>

struct npu_id_entity *npu_alloc_extend_param_id(u8 dev_ctx_id)
{
	struct npu_dev_ctx *cur_dev_ctx = NULL;
	struct npu_id_allocator *id_allocator = NULL;

	cond_return_error(dev_ctx_id >= NPU_DEV_NUM, NULL,
		"invalid dev_ctx_id\n");
	cur_dev_ctx = get_dev_ctx_by_id(dev_ctx_id);
	cond_return_error(cur_dev_ctx == NULL, NULL, "cur_dev_ctx %u is null\n",
		dev_ctx_id);
	id_allocator = &(cur_dev_ctx->id_allocator[NPU_ID_TYPE_EXTEND_PARAM]);

	return npu_id_allocator_alloc(id_allocator);
}

int npu_free_extend_param_id(u8 dev_ctx_id, u32 exparam_id)
{
	struct npu_dev_ctx *cur_dev_ctx = NULL;
	struct npu_id_allocator *id_allocator = NULL;

	cond_return_error(dev_ctx_id >= NPU_DEV_NUM, -EINVAL,
		"invalid dev_ctx_id\n");
	cur_dev_ctx = get_dev_ctx_by_id(dev_ctx_id);
	cond_return_error(cur_dev_ctx == NULL, -ENODATA,
		"cur_dev_ctx %u is null\n", dev_ctx_id);
	id_allocator = &(cur_dev_ctx->id_allocator[NPU_ID_TYPE_EXTEND_PARAM]);

	return npu_id_allocator_free(id_allocator, exparam_id);
}

static int npu_set_inout_addr_param(npu_exparam_t* ex_param)
{
	int i;
	int ret = -1;
	int prot = IOMMU_READ | IOMMU_WRITE;
	int fd;
	uint16_t offset;
	npu_exparam_t exparam_temp = {0};
	uint64_t vaddr = 0;
	uint64_t iova_size = 0;

	cond_return_error(ex_param->param_cnt > MAX_IOVA_ADDR_NUM, -1,
		"invalid ioAddr param_cnt(%d)\n", ex_param->param_cnt);

	exparam_temp.exparam_type = NPU_EXPARAM_IOVA_ADDR;
	exparam_temp.param_cnt = 1;

	fd = ex_param->param_value.ioAddr.fd[0];
	offset = ex_param->param_value.ioAddr.offset[0];

	/* map iova memory */
	ret = npu_iova_map_ion_aif(fd, prot, (unsigned long *)&vaddr, (unsigned long *)&iova_size);
	cond_return_error(ret != 0, -1, "npu iova map ion fail, ret = %d\n", ret);
	cond_return_error(offset > iova_size, -1, "offset greater than iova_size");

	exparam_temp.param_value.iovaAddr.iova_addr = vaddr + offset;
	exparam_temp.param_value.iovaAddr.iova_size = iova_size - offset;
	exparam_temp.param_value.iovaAddr.fd = fd;

	ret = memcpy_s(ex_param, sizeof(npu_exparam_t), &exparam_temp, sizeof(npu_exparam_t));
	cond_return_error(ret != EOK, -1, "memcpy_s failed. ret=%d\n", ret);

	return 0;
}

int npu_set_extend_param(u8 devid, npu_exparam_list_t *extend_param_info)
{	
	int i;
	int ret;
	cond_return_error(extend_param_info == NULL, -1, "extend_param_info is null.");

	npu_exparam_list_t *extend_param_list =
		npu_calc_extend_param_desc_info(devid, extend_param_info->exparam_list_id);
	cond_return_error(extend_param_list == NULL, -1, "extend_param_list is null.");

	ret = memset_s(extend_param_list, sizeof(npu_exparam_list_t),
		0, sizeof(npu_exparam_list_t));
	cond_return_error(ret != EOK, -1, "memset_s failed. ret=%d\n", ret);

	ret = memcpy_s(extend_param_list, sizeof(npu_exparam_list_t),
		extend_param_info, sizeof(npu_exparam_list_t));
	cond_return_error(ret != EOK, -1, "memcpy_s failed. ret=%d\n", ret);

	npu_drv_warn("extend_param_list, model_id: %u, exparam_list_id: %u, extend_param_cnt: %u",
        extend_param_list->model_id, extend_param_list->exparam_list_id, extend_param_list->extend_param_cnt);

	for (i = 0; i < extend_param_list->extend_param_cnt && i < MAX_EXTEND_PARAM_NUM; i++) {
		if (extend_param_list->extend_param[i].exparam_type == NPU_EXPARAM_INPUT_OUTPUT_ADDR) {
			if(extend_param_list->type == NPU_EXPARAM_LIST_PREFILL_END){
				npu_drv_warn("NPU_EXPARAM_LIST_PREFILL_END");
			}
			ret = npu_set_inout_addr_param(extend_param_list->extend_param + i);
			cond_return_error(ret != EOK, -1, "memcpy_s failed. ret=%d\n", ret);
		}
	}
	return 0;
}

int npu_bind_extend_param(u8 devid, u32 exparam_id, u32 model_id)
{
	npu_model_desc_info_t *model_desc_info = NULL;

	model_desc_info = npu_calc_model_desc_info(devid, model_id);
	cond_return_error(model_desc_info == NULL, -1,
		"model_desc_info is NULL\n");

	cond_return_error(model_desc_info->extend_param_id < NPU_MAX_EXTEND_PARAM_ID, -1,
		"model already bind param(%u)\n", model_desc_info->extend_param_id);

	model_desc_info->extend_param_id = exparam_id;
	return 0;
}
#endif