/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: functions for legacy tzdriver smc transport
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
#include "smc_abi.h"
#include "smc_call.h"
#include "smc_smp.h"
#include "teek_ns_client.h"
 
#ifdef CONFIG_REE_KERNEL_32BIT_TEE_64BIT
#define SHIFT_32 32
#define MASK_32 0xFFFFFFFFU
 
static void register_map_for_smc_in(struct smc_map_params *map_in, struct smc_in_params *in)
{
	map_in->r0 = in->x0;
	map_in->r1 = in->x1;
	map_in->r2 = in->x2 & MASK_32;
	map_in->r3 = in->x2 >> SHIFT_32;
	map_in->r4 = in->x3 & MASK_32;
	map_in->r5 = in->x3 >> SHIFT_32;
	map_in->r6 = in->x4 & MASK_32;
	map_in->r7 = in->x4 >> SHIFT_32;
}
 
static void register_map_for_smc_out(struct smc_map_params *map_out, struct smc_out_params *out)
{
	out->ret = map_out->r0;
	out->exit_reason = map_out->r1 | ((uint64_t)map_out->r2 << SHIFT_32);
	out->ta = map_out->r3 | ((uint64_t)map_out->r4 << SHIFT_32);
	out->target = map_out->r5 | ((uint64_t)map_out->r6 << SHIFT_32);
}
 
void do_smc_transport(struct smc_in_params *in, struct smc_out_params *out, uint8_t wait)
{
	struct smc_map_params map_in = {0};
	struct smc_map_params map_out = {0};
 
	register_map_for_smc_in(&map_in, in);
 
	isb();
	wmb();
	do {
		asm volatile(
			"ldr r0, %[fid]\n"
			"ldr r1, %[a1]\n"
			"ldr r2, %[a2]\n"
			"ldr r3, %[a3]\n"
			"ldr r4, %[a4]\n"
			"ldr r5, %[a5]\n"
			"ldr r6, %[a6]\n"
			"ldr r7, %[a7]\n"
			".arch_extension sec\n"
			SMCCC_SMC_INST"\n"
			"str r0, %[re0]\n"
			"str r1, %[re1]\n"
			"str r2, %[re2]\n"
			"str r3, %[re3]\n"
			"str r4, %[re4]\n"
			"str r5, %[re5]\n"
			"str r6, %[re6]\n" :
			[re0] "=m"(map_out.r0),
			[re1] "=m"(map_out.r1),
			[re2] "=m"(map_out.r2),
			[re3] "=m"(map_out.r3),
			[re4] "=m"(map_out.r4),
			[re5] "=m"(map_out.r5),
			[re6] "=m"(map_out.r6):
			[fid] "m"(map_in.r0),
			[a1] "m"(map_in.r1),
			[a2] "m"(map_in.r2),
			[a3] "m"(map_in.r3),
			[a4] "m"(map_in.r4),
			[a5] "m"(map_in.r5),
			[a6] "m"(map_in.r6),
			[a7] "m"(map_in.r7) :
			"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7");
	} while (out->ret == TSP_REQUEST && wait != 0);
	isb();
	wmb();
 
	register_map_for_smc_out(&map_out, out);
}
#endif