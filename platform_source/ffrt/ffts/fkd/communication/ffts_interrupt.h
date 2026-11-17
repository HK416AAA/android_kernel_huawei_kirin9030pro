/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: for ffts interrupt
 */
#ifndef _FFTS_INTERRUPT_H_
#define _FFTS_INTERRUPT_H_

#include "ffts_platform.h"
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"

#define FFTS_ACPU_INTRQ_NUM 4096
#define FFTS_DFX_INFO_MAX  20

struct ffts_dfx_info {
	uint32_t org_status;
	uint32_t mask_status;
	uint32_t type;
	uint32_t info;
};

struct ffts_intr_info {
	struct workqueue_struct *normal_intr_wq;
	struct work_struct normal_intr_work[FFTS_INTR_NORMAL_MAX];
	uint32_t normal_intr_count[FFTS_INTR_NORMAL_MAX];
	struct workqueue_struct *abnormal_intr_wq;
	struct work_struct abnormal_intr_work[FFTS_INTR_ABNORMAL_MAX];
	uint32_t abnormal_intr_count[FFTS_INTRQ_ABNORMAL_MAX];
	struct ffts_dfx_info abnormal_dfx_info[FFTS_DFX_INFO_MAX];
	uint8_t abnormal_dfx_info_read;
	uint8_t abnormal_dfx_info_write;
	uint16_t abnormal_dfx_info_lose_count;
	uint16_t abnormal_dfx_info_count;
};

int ffts_register_irq(struct ffts_platform_info *platform_info);
void ffts_unregister_irq(struct ffts_platform_info *platform_info);

uint32_t ffts_get_abnormal_count(ffts_intrq_abnormal_type_e type);
uint32_t ffts_get_dfx_count(void);
uint32_t ffts_get_debug_info_hwrtb(void);
uint32_t ffts_get_debug_info_submit(void);
uint32_t ffts_get_debug_info_task_done(void);

struct ffts_intr_info* ffts_get_intr_info_ptr(void);
void ffts_get_intr_abnormal_ptr(struct ffts_platform_info *plat_info, uint16_t *read, uint16_t *write);

#endif