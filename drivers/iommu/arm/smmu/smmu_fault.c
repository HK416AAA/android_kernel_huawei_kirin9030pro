/*
 * smmu_fault.c
 *
 * Copyright (C) 2024 Hisilicon Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include <linux/bitfield.h>
#include <linux/err.h>
#include <linux/iommu.h>
#include <linux/list.h>
#include <linux/mm_types.h>
#include <linux/kernel.h>
#include <linux/ktime.h>
#include <linux/dmabuf/dmabuf_reclaim.h>
#include <linux/dmabuf/dmabuf_swap.h>

#include "platform_smmu_v3.h"
#include "smmu_fault.h"

static int arm_smmu_page_response(struct device *dev,
				  u32 sid, u32 stag, u32 code)
{
	struct arm_smmu_cmdq_ent cmd = {0};
	struct arm_smmu_master_data *master = dev_iommu_priv_get(dev);

	if (master->stall_enabled) {
		cmd.opcode		= CMDQ_OP_RESUME;
		cmd.resume.sid		= sid;
		cmd.resume.stag		= stag;
		switch (code) {
		case IOMMU_PAGE_RESP_INVALID:
		case IOMMU_PAGE_RESP_FAILURE:
			cmd.resume.resp = 2;
			break;
		case IOMMU_PAGE_RESP_SUCCESS:
			cmd.resume.resp = 1;
			break;
		default:
			return -EINVAL;
		}
	} else {
		return -ENODEV;
	}

	arm_smmu_cmdq_issue_cmd(master->smmu, &cmd);

	return 0;
}

static struct arm_smmu_master_data *
arm_smmu_find_master(struct arm_smmu_device *smmu, u32 sid)
{
	struct rb_node *node;
	struct arm_smmu_stream_data *stream;

	lockdep_assert_held(&smmu->streams_mutex);
	node = smmu->streams.rb_node;
	while (node) {
		stream = rb_entry(node, struct arm_smmu_stream_data, node);
		if (stream->id < sid)
			node = node->rb_right;
		else if (stream->id > sid)
			node = node->rb_left;
		else
			return stream->master;
	}

	return NULL;
}

/* smmu fault: arm_smmu ops->fault */
int arm_smmu_do_translation_fault_batch(void *priv)
{
	return dmabuf_resume((struct dma_buf *)priv, NULL);
}

static int arm_smmu_handle_translation_fault(struct arm_smmu_device *smmu,
							u64 *evt)
{
	int ret, code;
	u32 sid = FIELD_GET(EVTQ_0_SID, evt[0]);
	u32 stag = FIELD_GET(EVTQ_1_STAG, evt[1]);
	unsigned long iova = FIELD_GET(EVTQ_2_ADDR, evt[2]);
	struct arm_smmu_master_data *master = NULL;

	mutex_lock(&smmu->streams_mutex);
	master = arm_smmu_find_master(smmu, sid);
	if (!master || !master->stall_enabled) {
		pr_err("%s, master stall disable\n", __func__);
		ret = -EPERM;
		goto out_unlock;
	}

	ret = mm_iommu_handle_translation_fault(master->dev, iova);
	if (!ret)
		code = IOMMU_PAGE_RESP_SUCCESS;
	else
		code = IOMMU_PAGE_RESP_FAILURE;

	ret = arm_smmu_page_response(master->dev, sid, stag, code);
	if (ret)
		pr_err("%s, arm_smmu_page_response fail\n", __func__);

out_unlock:
	mutex_unlock(&smmu->streams_mutex);
	return ret;
}

/* IRQ and event handlers */
int arm_smmu_handle_evt(struct arm_smmu_device *smmu, u64 *evt)
{
	int ret = 0;

	spin_unlock(&smmu->tcu_lock);
	switch (FIELD_GET(EVTQ_0_ID, evt[0])) {
	case EVTQ_TYPE_TRANSLATION:
		ret = arm_smmu_handle_translation_fault(smmu, evt);
		break;
	case EVTQ_TYPE_ADDR_SIZE:
		/* do not support */
		pr_err("%s, unsupport addr size fault handle\n", __func__);
		break;
	case EVTQ_TYPE_ACCESS:
		/* do not support */
		pr_err("%s, unsupport addr access handle\n", __func__);
		break;
	case EVTQ_TYPE_PERMISSION:
		/* do not support */
		pr_err("%s, unsupport permission fault handle\n", __func__);
		break;
	default:
		pr_err("%s, unsupport fault handle\n", __func__);
	}
	spin_lock(&smmu->tcu_lock);

	return ret;
}
