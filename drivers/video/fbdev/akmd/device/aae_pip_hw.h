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

#ifndef AKMD_AAE_PIP_HW_H
#define AKMD_AAE_PIP_HW_H

#include "akmd_pip.h"

struct aae_pipeline {
	// Notice: pip_sw must be first element for static cast from struct aae_pipeline_sw to struct aae_pipeline type
	// Otherwise we need use container_of to transfer type
	struct aae_pipeline_sw pip_sw;

	/* ------------------------- hardware struct or interface -------------------------*/
	int32_t pip_irq;
	struct ukmd_isr isr_ctrl;
	/* link initialize cmdlist id */
	uint32_t init_cmdlist_id;
};

int32_t aae_pip_hw_init(struct aae_pipeline_sw **pip_sw);
void aae_pip_hw_deinit(struct aae_pipeline_sw **pip_sw);
void aae_pip_hw_close(struct aae_pipeline_sw *pip_sw);
int32_t aae_pip_hw_parse_dt(struct aae_pipeline_sw *pip_sw, struct device_node *np);
void aae_pip_isr_setup(struct aae_pipeline_sw *pip_sw);
void aae_pip_isr_release(struct aae_pipeline_sw *pip_sw);
void aae_pip_hw_setup(struct aae_pipeline_sw *pip_sw);
void aae_pip_isr_enable(struct aae_pipeline_sw *pip_sw);
void aae_pip_isr_disable(struct aae_pipeline_sw *pip_sw);
#endif /* AKMD_AAE_PIP_HW_H */
