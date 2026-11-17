/*
 * dsp_iodie_drv.c -- codec driver
 *
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 *
 * Description: Initialization registration and exception callback
 * Create: 2025-02-19
 *
 */

#ifndef __DSP_IODIE_DRV_H__
#define __DSP_IODIE_DRV_H__
 
#include <linux/types.h>

struct dsp_iodie_write_output_msg {
	uint32_t msg_id;
	int error_code;
	uint16_t status;
};

int32_t iodie_drv_init(void);
#endif
