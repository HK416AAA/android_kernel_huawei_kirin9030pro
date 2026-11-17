/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: functions for inner ffa module
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
#include "inner_ffa_driver.h"
#include "smc_call.h"
#include "tc_ns_log.h"
#include "tc_current_info.h"

struct ffa_params_all {
	unsigned long x0;
	unsigned long x1;
	unsigned long x2;
	struct ffa_send_direct_data *ffa_data;
};

#define SENDER_ID_MASK           GENMASK(31, 16)
#define RECEIVER_ID_MASK         GENMASK(15, 0)
#define PACK_TARGET_INFO(s, r)   \
	(FIELD_PREP(SENDER_ID_MASK, (s)) | FIELD_PREP(RECEIVER_ID_MASK, (r)))

static u16 vm_id = CURRENT_VM_ID;

static void mode_32bit_set(struct ffa_device *dev)
{
	dev->mode_32bit = true;
}

static void set_smc_results(struct ffa_params_all *result, const struct ffa_params_all *params_out)
{
	result->x0 = params_out->x0;
	result->x1 = params_out->x1;
	result->x2 = params_out->x2;
	result->ffa_data->data0 = params_out->ffa_data->data0;
	result->ffa_data->data1 = params_out->ffa_data->data1;
	result->ffa_data->data2 = params_out->ffa_data->data2;
	result->ffa_data->data3 = params_out->ffa_data->data3;
	result->ffa_data->data4 = params_out->ffa_data->data4;
}

static void send_smc(struct ffa_params_all *params)
{
	struct ffa_params_all params_out;
	struct ffa_send_direct_data data_out;
	params_out.ffa_data = &data_out;
	isb();
	wmb();
	asm volatile(
		"mov x0, %[fid]\n"
		"mov x1, %[a1]\n"
		"mov x2, %[a2]\n"
		"mov x3, %[a3]\n"
		"mov x4, %[a4]\n"
		"mov x5, %[a5]\n"
		"mov x6, %[a6]\n"
		"mov x7, %[a7]\n"
		SMCCC_SMC_INST"\n"
		"str x0, [%[re0]]\n"
		"str x1, [%[re1]]\n"
		"str x2, [%[re2]]\n"
		"str x3, [%[re3]]\n"
		"str x4, [%[re4]]\n"
		"str x5, [%[re5]]\n"
		"str x6, [%[re6]]\n"
		"str x7, [%[re7]]\n" :
		[fid] "+r"(params->x0),
		[a1] "+r"(params->x1),
		[a2] "+r"(params->x2),
		[a3] "+r"(params->ffa_data->data0),
		[a4] "+r"(params->ffa_data->data1),
		[a5] "+r"(params->ffa_data->data2),
		[a6] "+r"(params->ffa_data->data3),
		[a7] "+r"(params->ffa_data->data4):
		[re0] "r"(&params_out.x0),
		[re1] "r"(&params_out.x1),
		[re2] "r"(&params_out.x2),
		[re3] "r"(&params_out.ffa_data->data0),
		[re4] "r"(&params_out.ffa_data->data1),
		[re5] "r"(&params_out.ffa_data->data2),
		[re6] "r"(&params_out.ffa_data->data3),
		[re7] "r"(&params_out.ffa_data->data4) :
		"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
	);
	isb();
	wmb();
	set_smc_results(params, &params_out);
}

static int sync_send_receive(struct ffa_device *dev, struct ffa_send_direct_data *data)
{
	struct ffa_params_all params;
	unsigned long expected_resp = FFA_MSG_SEND_DIRECT_RESP_SMC64;
	if (dev == NULL || data == NULL)
		return -1;

	params.x0 = FFA_MSG_SEND_DIRECT_REQ_SMC64;
	params.x1 = PACK_TARGET_INFO(vm_id, dev->vm_id);
	params.x2 = 0;
	params.ffa_data = data;

	if (dev->mode_32bit) {
		params.x0 = FFA_MSG_SEND_DIRECT_REQ_SMC32;
		expected_resp = FFA_MSG_SEND_DIRECT_RESP_SMC32;
	}

	send_smc(&params);

	if (params.x0 != expected_resp) {
		tloge("ffa call return 0x%llx\n", (unsigned long long)(params.x0));
		return -1;
	}

	return 0;
}

static struct ffa_ops g_ffa_ops = {
	.mode_32bit_set = mode_32bit_set,
	.sync_send_receive = sync_send_receive
};

static struct ffa_device g_ffa_dev = {
	.ops = &g_ffa_ops
};

int ffa_register(struct ffa_driver *driver)
{
	if (driver == NULL)
		return -1;
	if (driver->probe != NULL)
		driver->probe(&g_ffa_dev);
	g_ffa_dev.vm_id = DEFAULT_TEE_SP_ID;
	return 0;
}

int ffa_unregister(struct ffa_driver *driver)
{
	if (driver == NULL)
		return -1;
	if (driver->remove != NULL)
		driver->remove(&g_ffa_dev);
	return 0;
}