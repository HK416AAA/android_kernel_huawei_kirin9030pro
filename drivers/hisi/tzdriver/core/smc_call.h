/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: declarations of unified API for tzdriver
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef SMC_CALL_H
#define SMC_CALL_H

#include <linux/types.h>
#include "smc_ins.h"

#ifdef CONFIG_REE_KERNEL_32BIT_TEE_64BIT
struct smc_map_params {
	unsigned long r0;
	unsigned long r1;
	unsigned long r2;
	unsigned long r3;
	unsigned long r4;
	unsigned long r5;
	unsigned long r6;
	unsigned long r7;
};
 
struct smc_in_params {
	unsigned long long x0;
	unsigned long long x1;
	unsigned long long x2;
	unsigned long long x3;
	unsigned long long x4;
};
 
struct smc_out_params {
	unsigned long long ret;
	unsigned long long exit_reason;
	unsigned long long ta;
	unsigned long long target;
};
#else
struct smc_in_params {
	unsigned long x0;
	unsigned long x1;
	unsigned long x2;
	unsigned long x3;
	unsigned long x4;
	unsigned long x5;
	unsigned long x6;
	unsigned long x7;
};

struct smc_out_params {
	unsigned long ret;
	unsigned long exit_reason;
	unsigned long ta;
	unsigned long target;
};
#endif

void smc_req(struct smc_in_params *in, struct smc_out_params *out, uint8_t wait);

#endif