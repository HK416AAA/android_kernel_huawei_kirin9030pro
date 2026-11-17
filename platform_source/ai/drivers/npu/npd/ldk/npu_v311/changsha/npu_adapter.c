/*
 * npu_adapter.c
 *
 * about npu adapter
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include "npu_adapter.h"

#include <asm/barrier.h>
#include <securec.h>
#ifndef CONFIG_SELF_HEALING_PV_DIS
#include <platform_include/see/efuse_driver.h>
#endif

#include "npd_interface.h"
#include "npu_log.h"
#include "npu_platform_pm_spec.h"
#include "npu_pm_internal.h"
#include "npu_pm_framework.h"

u32 npu_get_feature_bits(void)
{
	return NPU_FEATUE_GLOBAL_EXCEPTION_REG;
}

int npu_plat_res_mailbox_send(void *mailbox, unsigned long mailbox_len,
	const void *message, unsigned long message_len)
{
	int ret;

	cond_return_error(message_len > mailbox_len, -1,
		"message len =%d, too long", message_len);

	ret = memset_s(mailbox, mailbox_len, 0, mailbox_len);
	cond_return_error(ret != 0, ret, "memset failed. ret=%d\n", ret);

	ret = memcpy_s(mailbox, mailbox_len, message, message_len);
	cond_return_error(ret != 0, ret, "memcpy failed. ret=%d\n", ret);

	mb();
	return ret;
}

int npu_send_ipc_with_power_check(u32 cmd_type, enum ipc_msg_sync_type msg_sync_type,
	const u8 *send_msg, u32 send_len, enum ipc_send_ack_type ack_type)
{
	int ret = 0;
	struct npu_dev_ctx *dev_ctx = get_dev_ctx_by_id(0);
	cond_return_error(dev_ctx == NULL, -1, "invalid dev ctx\n");

	npu_pm_safe_call_with_return(dev_ctx, NPU_IP_TSCPU,
		send_ipc_msg_to_ts(cmd_type, msg_sync_type, send_msg, send_len, ack_type), ret);
	return ret;
}

#ifndef CONFIG_SELF_HEALING_PV_DIS
int npu_set_self_healing_voltage(u32 *self_healing_value, u32 size)
{
	u32 index = 0;
	struct efuse_desc desc = { 0 };
	u32 binx_voltage_flag = 1;
	desc.buf = &binx_voltage_flag;
	desc.buf_size = 1;
	/* binx voltage up flag */
	desc.start_bit = 137;
	desc.bit_cnt = 1;
	desc.item_vid = EFUSE_KERNEL_PARTIALGOOD_FLAG1;
	if ((efuse_read_value_t(&desc) == EFUSE_OK) && (binx_voltage_flag == 0)) {
		for (index = 0; index < size; index++) {
			self_healing_value[index] = binx_self_healing_voltage[index];
		}
	}
	return 0;
}
#endif