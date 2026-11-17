/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2022. All rights reserved.
 * Description: api for crl update
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
#include "tz_update_crl.h"
#include <linux/fs.h>
#include <linux/vmalloc.h>
#include <linux/uaccess.h>
#include <securec.h>
#include "tc_ns_log.h"
#include "tc_current_info.h"
#include "mailbox_mempool.h"
#include "smc_smp.h"


static DEFINE_MUTEX(g_cms_crl_update_lock);

int send_crl_to_tee(const char *crl_buffer, uint32_t crl_len, const struct tc_ns_dev_file *dev_file)
{
	int ret;
	struct tc_ns_smc_cmd smc_cmd;
	struct mb_cmd_pack *mb_pack = NULL;
	char *mb_param = NULL;

	(void)memset_s(&smc_cmd, sizeof(smc_cmd), 0, sizeof(smc_cmd));
	/* dev_file not need check null */
	if (crl_buffer == NULL || crl_len == 0 || crl_len > DEVICE_CRL_MAX) {
		tloge("invalid params\n");
		return -EINVAL;
	}

	mb_pack = mailbox_alloc_cmd_pack();
	if (!mb_pack) {
		tloge("alloc mb pack failed\n");
		return -ENOMEM;
	}
	mb_param = mailbox_copy_alloc(crl_buffer, crl_len);
	if (!mb_param) {
		tloge("alloc mb param failed\n");
		ret = -ENOMEM;
		goto clean;
	}
	mb_pack->operation.paramtypes = TEEC_MEMREF_TEMP_INPUT;
	mb_pack->operation.params[0].memref.buffer = (unsigned int)mailbox_virt_to_phys((uintptr_t)mb_param);
	mb_pack->operation.buffer_h_addr[0] =
		(unsigned int)((uint64_t)mailbox_virt_to_phys((uintptr_t)mb_param) >> ADDR_TRANS_NUM);
	mb_pack->operation.params[0].memref.size = crl_len;
	smc_cmd.cmd_id = GLOBAL_CMD_ID_UPDATE_TA_CRL;
	smc_cmd.cmd_type = CMD_TYPE_GLOBAL;
	if (dev_file != NULL)
		smc_cmd.dev_file_id = dev_file->dev_file_id;
	smc_cmd.context_id = 0;
	smc_cmd.operation_phys = (unsigned int)mailbox_virt_to_phys((uintptr_t)&mb_pack->operation);
	smc_cmd.operation_h_phys =
		(unsigned int)((uint64_t)mailbox_virt_to_phys((uintptr_t)&mb_pack->operation) >> ADDR_TRANS_NUM);

	mutex_lock(&g_cms_crl_update_lock);
	ret = tc_ns_smc(&smc_cmd);
	mutex_unlock(&g_cms_crl_update_lock);
	if (ret != 0)
		tloge("smc call returns error ret 0x%x\n", ret);
clean:
	mailbox_free(mb_pack);
	mb_pack = NULL;
	if (mb_param)
		mailbox_free(mb_param);

	return ret;
}

int tc_ns_update_ta_crl(const struct tc_ns_dev_file *dev_file, void __user *argp)
{
	int ret = -1;
	struct tc_ns_client_crl context = {0};
	void *buffer_addr = NULL;
	uint8_t *crl_buffer = NULL;

	if (!dev_file || !argp) {
		tloge("invalid params\n");
		return -EINVAL;
	}

	if (copy_from_user(&context, argp, sizeof(context)) != 0) {
		tloge("copy from user failed\n");
		return -ENOMEM;
	}

	if (context.size > DEVICE_CRL_MAX) {
		tloge("crl size is too long\n");
		return -ENOMEM;
	}

	crl_buffer = kmalloc(context.size, GFP_KERNEL);
	if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)(crl_buffer))) {
		tloge("failed to allocate crl buffer\n");
		return -ENOMEM;
	}

	buffer_addr = (void *)(uintptr_t)(context.memref.buffer_addr |
		(((uint64_t)context.memref.buffer_h_addr) << ADDR_TRANS_NUM));
	if (copy_from_user(crl_buffer, buffer_addr, context.size) != 0) {
		tloge("copy from user failed\n");
		goto clean;
	}

	ret = send_crl_to_tee((void *)crl_buffer, context.size, dev_file);
	if (ret != 0) {
		tloge("send crl to tee failed\n");
		goto clean;
	}

clean:
	kfree(crl_buffer);
	return ret;
}
