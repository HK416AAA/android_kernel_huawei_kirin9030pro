/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2022. All rights reserved.
 * Description: function implementation for tee livepatch
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

#include "livepatch_cmd.h"
#include <linux/sysfs.h>
#include <linux/platform_device.h>
#include <linux/string.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <securec.h>
#include "teek_client_constants.h"
#include "teek_ns_client.h"
#include "mailbox_mempool.h"
#include "smc_smp.h"
#include "livepatch_errno.h"
#include "session_manager.h"
#include "tc_ns_log.h"
#include "tc_current_info.h"

#define MAX_SENDSTR_LEN 50

enum cmd_type {
	LIVEPATCH_LOAD = 0,
	LIVEPATCH_UNLOAD,
	LIVEPATCH_ENABLE,
	LIVEPATCH_DISABLE,
	LIVEPATCH_QUERY,
	LIVEPATCH_CMDMAX
};

struct livepatch_dispatch {
	enum cmd_type cmd_type;
	enum global_service_cmd_id cmd_id;
};

struct livepatch_send_datas {
	uint32_t data_len; /* data_len is str actual len without \0 */
	int type;
	struct load_secfile_ioctl_struct load_arg;
	char trans_data[MAX_SENDSTR_LEN];
};


static const struct livepatch_dispatch g_cmd_dispatch[] = {
	{LIVEPATCH_ENABLE, GLOBAL_CMD_ID_LIVEPATCH_ENABLE},
	{LIVEPATCH_DISABLE, GLOBAL_CMD_ID_LIVEPATCH_DISABLE},
	{LIVEPATCH_UNLOAD, GLOBAL_CMD_ID_LIVEPATCH_UNLOAD},
	{LIVEPATCH_QUERY, GLOBAL_CMD_ID_LIVEPATCH_QUERY}
};

DECLARE_RWSEM(g_livepatch_rwsem);

void livepatch_down_read_sem(void)
{
	down_read(&g_livepatch_rwsem);
	tlogd("down read semaphore\n");
}

static bool livepatch_down_write_sem(void)
{
	uint32_t count = 3000000;
	while (count--) {
		if (down_write_trylock(&g_livepatch_rwsem) == 1) {
			tlogd("down write semaphore\n");
			return true;
		}
		udelay(1);
	}
	return false;
}

void livepatch_up_read_sem(void)
{
	up_read(&g_livepatch_rwsem);
	tlogd("up read semaphore\n");
}

static void livepatch_up_write_sem(void)
{
	up_write(&g_livepatch_rwsem);
	tlogd("up write semaphore\n");
}

static bool check_module_name_valid(const char *module_name, uint32_t len)
{
	uint32_t i = 0;
	if (module_name == NULL) {
		tloge("module name empty\n");
		return false;
	}

	if (len == 0 || len >= MAX_SENDSTR_LEN || strnlen(module_name, len + 1) != len) {
		tloge("module name length is invalid! len is %u\n", len);
		return false;
	}

	/* module name can only contain '0'~'9', 'a'~'z', 'A'~'Z', '_', '.' */
	while (i < len) {
		if ((module_name[i] < '0' || module_name[i] > '9') &&
			(module_name[i] < 'a' || module_name[i] > 'z') &&
			(module_name[i] < 'A' || module_name[i] > 'Z') &&
			module_name[i] != '_' && module_name[i] != '.') {
			tloge("module name contains invalid character: '%c'\n", module_name[i]);
			return false;
		}
		i++;
	}

	return true;
}

static int livepatch_tc_ns_smc(struct tc_ns_smc_cmd *smc_cmd, enum global_service_cmd_id cmd_id)
{
	int ret = 0;

	if (cmd_id == GLOBAL_CMD_ID_LIVEPATCH_ENABLE ||
		cmd_id == GLOBAL_CMD_ID_LIVEPATCH_DISABLE) {
		if (!livepatch_down_write_sem()) {
			tloge("down write rwsem timeout\n");
			return LIVEPATCH_CMD_TIME_OUT | LIVEPATCH_ORIGIN_COMMS;
		}
	} else {
		livepatch_down_read_sem();
	}

	ret = tc_ns_smc(smc_cmd);

	if (cmd_id == GLOBAL_CMD_ID_LIVEPATCH_ENABLE ||
		cmd_id == GLOBAL_CMD_ID_LIVEPATCH_DISABLE)
		livepatch_up_write_sem();
	else
		livepatch_up_read_sem();

	return ret;
}

static int set_livepatch_err_code(int smc_origin, const int *livepatch_err)
{
	if (smc_origin == TEEC_ORIGIN_TEE)
		return *livepatch_err | LIVEPATCH_ORIGIN_TEE;
	else
		return *livepatch_err | LIVEPATCH_ORIGIN_COMMS;
}

static int livepatch_send_cmd(const char *module_name, enum global_service_cmd_id cmd_id)
{
	struct tc_ns_smc_cmd smc_cmd;
	struct mb_cmd_pack *mb_pack = NULL;
	char *lpmodule_name = NULL;
	int ret = 0;
	int smc_ret;
	uint32_t lpmodule_len = strlen(module_name) + 1;

	(void)memset_s(&smc_cmd, sizeof(smc_cmd), 0, sizeof(smc_cmd));
	mb_pack = mailbox_alloc_cmd_pack();
	lpmodule_name = mailbox_alloc(lpmodule_len, MB_FLAG_ZERO);
	if (!mb_pack || !lpmodule_name) {
		ret = LIVEPATCH_OUT_OF_MEM | LIVEPATCH_ORIGIN_COMMS;
		goto clean;
	}
	ret = strncpy_s(lpmodule_name, lpmodule_len, module_name, lpmodule_len - 1);
	if (ret != 0) {
		tloge("strcpy module_name failed\n");
		ret = LIVEPATCH_GENERIC_ERR | LIVEPATCH_ORIGIN_COMMS;
		goto clean;
	}

	mb_pack->operation.paramtypes = teec_param_types(TEEC_MEMREF_TEMP_INPUT,
		TEEC_VALUE_OUTPUT, TEEC_NONE, TEEC_NONE);
	mb_pack->operation.params[0].memref.buffer =
		mailbox_virt_to_phys((uintptr_t)lpmodule_name);
	mb_pack->operation.buffer_h_addr[0] =
		(uint64_t)mailbox_virt_to_phys((uintptr_t)lpmodule_name) >> ADDR_TRANS_NUM;
	mb_pack->operation.params[0].memref.size = lpmodule_len;
	mb_pack->operation.params[1].value.a = LIVEPATCH_GENERIC_ERR;

	smc_cmd.cmd_id = cmd_id;
	smc_cmd.cmd_type = CMD_TYPE_GLOBAL;
	smc_cmd.operation_phys = mailbox_virt_to_phys((uintptr_t)&mb_pack->operation);
	smc_cmd.operation_h_phys =
		(uint64_t)mailbox_virt_to_phys((uintptr_t)&mb_pack->operation) >> ADDR_TRANS_NUM;

	smc_ret = livepatch_tc_ns_smc(&smc_cmd, cmd_id);
	if (smc_ret != 0) {
		if (cmd_id != GLOBAL_CMD_ID_LIVEPATCH_QUERY)
			tloge("livepatch cmd failed(0x%x)\n", smc_ret);
		if (smc_ret == (LIVEPATCH_CMD_TIME_OUT | LIVEPATCH_ORIGIN_COMMS)) {
			ret = smc_ret;
			goto clean;
		}
		ret = set_livepatch_err_code(smc_cmd.err_origin, &mb_pack->operation.params[1].value.a);
	}

clean:
	mailbox_free(mb_pack);
	mailbox_free(lpmodule_name);

	return ret;
}

static bool is_valid_file_size(unsigned int file_size)
{
	if (file_size == 0) {
		tloge("invalid load livepatch size\n");
		return false;
	}

	if (file_size > SZ_8M) {
		tloge("not support livepatch larger than 8M. real size=%u\n", file_size);
		return false;
	}

	return true;
}

static int load_livepatch(struct livepatch_send_datas *send_datas)
{
	int ret;
	void *file_addr = NULL;
	struct load_secfile_ioctl_struct *arg = NULL;
	struct tc_ns_dev_file dev_file = {0};
	struct load_img_params params = {0};

	arg = &(send_datas->load_arg);
	file_addr = (void *)(uintptr_t)(arg->memref.file_addr |
		(((uint64_t)arg->memref.file_h_addr) << ADDR_TRANS_NUM));
	params.dev_file = &dev_file;
	params.file_buffer = file_addr;

	params.file_size = arg->sec_file_info.file_size;
	if (!is_valid_file_size(params.file_size))
		return LIVEPATCH_FILE_SIZE_ERR;
	load_image_lock();
	ret = load_image(&params, &arg->sec_file_info, NULL, false);
	load_image_unlock();
	if (ret != 0)
		return arg->sec_file_info.sec_load_err;

	return 0;
}

static ssize_t set_livepatch_state(struct kobject *kobj,
	struct kobj_attribute *attr, const char *buf, size_t count)
{
	int ret = LIVEPATCH_ORIGIN_COMMS;
	char module_name[MAX_SENDSTR_LEN] = {0};
	struct livepatch_send_datas send_datas = {0};
	int cmd_type;
	uint32_t i;

	(void)kobj;
	(void)attr;

	if (count > sizeof(send_datas)) {
		tloge("input count over max len\n");
		return ret | LIVEPATCH_PARAM_INVALID;
	}

	if (memcpy_s(&send_datas, sizeof(send_datas), buf, count) != 0) {
		tloge("memcpy_s send data fail!\n");
		return ret | LIVEPATCH_GENERIC_ERR;
	}

	if (send_datas.type == LIVEPATCH_LOAD)
		return load_livepatch(&send_datas);

	if (!check_module_name_valid(send_datas.trans_data, send_datas.data_len))
		return ret | LIVEPATCH_PARAM_INVALID;

	if (memcpy_s(module_name, MAX_SENDSTR_LEN, send_datas.trans_data, send_datas.data_len) != 0) {
		tloge("memcpy module name fail!\n");
		return ret | LIVEPATCH_GENERIC_ERR;
	}

	cmd_type = send_datas.type;
	for (i = 0; i < ARRAY_SIZE(g_cmd_dispatch); ++i) {
		if (cmd_type == (int)g_cmd_dispatch[i].cmd_type) {
			ret = livepatch_send_cmd(module_name, g_cmd_dispatch[i].cmd_id);
			break;
		}
	}

	if (i == ARRAY_SIZE(g_cmd_dispatch)) {
		ret |= LIVEPATCH_PARAM_INVALID;
		tloge("param is incorrect!\n");
	}

	if (ret != LIVEPATCH_SUCCESS)
		return ret;

	return (ssize_t)count;
}

static ssize_t show_livepatch_state(struct kobject *kobj,
	struct kobj_attribute *attr, char *buf)
{
	int ret = LIVEPATCH_SUCCESS;

#ifdef CONFIG_LIVEPATCH_DEBUG
	const char *default_module_name = "1_1_all";

	ret = livepatch_send_cmd(default_module_name, GLOBAL_CMD_ID_LIVEPATCH_QUERY);
#endif

	(void)kobj;
	(void)attr;
	(void)buf;
	return (ssize_t)ret;
}

static struct kobj_attribute livepatch_stat_attr =
	__ATTR(state, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP,
	show_livepatch_state, set_livepatch_state);

static struct kobject *g_lp_kobj = NULL;

int livepatch_init(const struct device *dev)
{
	if (dev == NULL) {
		tloge("device ptr is NULL\n");
		return -EINVAL;
	}

	g_lp_kobj = kobject_create_and_add("livepatch", (struct kobject *)&dev->kobj);
	if (!g_lp_kobj)
		return -EINVAL;

	return sysfs_create_file(g_lp_kobj, &livepatch_stat_attr.attr);
}

void free_livepatch(void)
{
	if (!g_lp_kobj)
		return;
	sysfs_remove_file(g_lp_kobj, &livepatch_stat_attr.attr);
	kobject_del(g_lp_kobj);
	g_lp_kobj = NULL;
}
