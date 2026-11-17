/*
 * smmu_fault.h
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
#ifndef _SMMU_FAULT_H
#define _SMMU_FAULT_H

#include <linux/mm_types.h>
#include <linux/iommu.h>
#ifdef CONFIG_HM_SMMU_V3
#include "hm_smmu_v3.h"
#else
#include "platform_smmu_v3.h"
#endif

#ifdef CONFIG_MM_IOMMU_FAULT
extern struct list_head smmu_dev_list;

int arm_smmu_do_translation_fault_batch(void *priv);

int arm_smmu_handle_evt(struct arm_smmu_device *smmu, u64 *evt);
#else
static inline int arm_smmu_do_translation_fault(struct iommu_domain *domain,
				void *priv, unsigned long iova,
				unsigned long offset, int prot)
{
	return -EINVAL;
}

static inline int arm_smmu_handle_evt(struct arm_smmu_device *smmu, u64 *evt)
{
	return -EINVAL;
}
#endif /* CONFIG_MM_IOMMU_FAULT */
#endif
