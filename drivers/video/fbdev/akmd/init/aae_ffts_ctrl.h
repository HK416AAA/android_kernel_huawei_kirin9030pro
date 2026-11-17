/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: provide ffap1 handle function interfaces.
 */

#ifndef __AAE_FFTS_CTRL_H__
#define __AAE_FFTS_CTRL_H__

#include <linux/types.h>

int32_t aae_ffts_connect(char __iomem *aae_base);
int32_t config_ffap_exp_handle(char __iomem *aae_base);
int32_t wait_ffap_pt_link(char __iomem *aae_base);
#endif