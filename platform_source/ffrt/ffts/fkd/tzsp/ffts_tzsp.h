/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: for ffts drv atf interface
 */
#ifndef _FFTS_TZSP_H_
#define _FFTS_TZSP_H_

#include <linux/types.h>
#include <ffa_plat_drv.h>

int tzsp_service_ffts_smc(u64 _service_id, u64 _cmd, u64 _arg1, u64 _arg2);

#endif