/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: provide aae dacc start function interfaces.
 */

#ifndef __AAE_DACC_CTRL_H__
#define __AAE_DACC_CTRL_H__

#include <linux/types.h>

int32_t start_dacc(char __iomem *aae_base); /* riscv start */
#endif