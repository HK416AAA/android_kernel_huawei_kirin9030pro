/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2022. All rights reserved.
 * Description: for pages log cfg api define
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
#include "log_cfg_api.h"
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sysfs.h>
#include <linux/semaphore.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/err.h>
#ifdef CONFIG_TEE_LOG_RDR
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_platform.h>
#endif
#include <securec.h>
#include "tlogger.h"
#include "shared_mem.h"
#include "tc_ns_log.h"
#include "tc_current_info.h"

#ifdef CONFIG_TEE_LOG_RDR
#define TEE_LOG_LEN 0x40000
#define TEE_LOG_LEN_LITE 0x3B000
#endif

void unregister_log_exception(void)
{
}

int register_log_exception(void)
{
	return 0;
}

struct pages_module_result {
	uint64_t log_addr;
	uint32_t log_len;
};

struct pages_module_result g_mem_info = {0};

static int tee_pages_register_core(void)
{
	if (g_mem_info.log_addr != 0 || g_mem_info.log_len != 0) {
		if (memset_s((void *)g_mem_info.log_addr,  g_mem_info.log_len, 0,  g_mem_info.log_len) != 0) {
			tloge("clean log memory failed\n");
			return -EFAULT;
		}
		return 0;
	}

	g_mem_info.log_addr = get_log_mem_vaddr();
	if (IS_ERR_OR_NULL((void *)(uintptr_t)g_mem_info.log_addr)) {
		tloge("get log mem error\n");
		return -1;
	}
	g_mem_info.log_len = PAGES_LOG_MEM_LEN;
	return 0;
}

/* Register log memory */
#ifdef CONFIG_TEE_LOG_RDR
int register_log_mem(uint64_t *addr, uint32_t *len)
{
	int ret;
	uint64_t mem_addr;
	uint32_t mem_len;
	struct device_node *np = NULL;
	struct resource rc;
	void *ptr = NULL;
 
	if (!addr || !len) {
		tloge("addr or len is invalid, addr is %s, len is %s\n", addr == NULL ? "null" : "valid",
			len == NULL ? "null" : "valid");
		return -1;
	}
 
	np = of_find_compatible_node(NULL, NULL, "tee_log");
	if (np == NULL) {
		tlogw("Unable to find 'tee_log' compatible node\n");
		ret = tee_pages_register_core();
		if (ret != 0)
			return ret;
 
		mem_addr = get_log_mem_paddr(g_mem_info.log_addr);
		mem_len = g_mem_info.log_len;
		goto out;
	}
 
	if (of_address_to_resource(np, 0, &rc) != 0) {
		tloge("of_address_to_resource error\n");
		return -ENODEV;
	}
 
	mem_len = (uint32_t)resource_size(&rc);
	if (mem_len != TEE_LOG_LEN && mem_len != TEE_LOG_LEN_LITE) {
		tloge("tee log reserved memory size is wrong\n");
		return -EINVAL;
	}
 
	mem_addr = (uint64_t)rc.start;
 
	ptr = ioremap_cache(mem_addr, mem_len);
	if (ptr == NULL) {
		tloge("io remap for reserved memory failed\n");
		return -ENOMEM;
	}
 
	g_mem_info.log_addr = (uint64_t *)ptr;
	g_mem_info.log_len = mem_len;
out:
	ret = register_mem_to_teeos(mem_addr, mem_len, true);
	if (ret != 0)
		return ret;
 
	*addr = g_mem_info.log_addr;
	*len = g_mem_info.log_len;
	return ret;
}
#else
int register_log_mem(uint64_t *addr, uint32_t *len)
{
	int ret;
	uint64_t mem_addr;
	uint32_t mem_len;

	if (!addr || !len) {
		tloge("addr or len is invalid, addr is %s, len is %s\n", addr == NULL ? "null" : "valid",
			len == NULL ? "null" : "valid");
		return -1;
	}

	ret = tee_pages_register_core();
	if (ret != 0)
		return ret;

	mem_addr = get_log_mem_paddr(g_mem_info.log_addr);
	mem_len = g_mem_info.log_len;

	ret = register_mem_to_teeos(mem_addr, mem_len, true);
	if (ret != 0)
		return ret;

	*addr = g_mem_info.log_addr;
	*len = g_mem_info.log_len;
	return ret;
}
#endif

void report_log_system_error(void)
{
}

void report_log_system_panic(void)
{
/* default support trigger ap reset */
#ifndef NOT_TRIGGER_AP_RESET
	panic("TEEOS panic\n");
#endif
}

void ta_crash_report_log(void)
{
}

int *map_log_mem(uint64_t mem_addr, uint32_t mem_len)
{
	(void)mem_len;
	return (int *)(uintptr_t)mem_addr;
}

void unmap_log_mem(int *log_buffer)
{
	free_log_mem((uint64_t)(uintptr_t)log_buffer);
}

void get_log_chown(uid_t *user, gid_t *group)
{
	if (!user || !group) {
		tloge("user or group buffer is null, user is %s, group is %s\n", user == NULL ? "null" : "valid",
			group == NULL ? "null" : "valid");
		return;
	}

	*user = ROOT_UID;
	*group = FILE_CHOWN_GID;
}
