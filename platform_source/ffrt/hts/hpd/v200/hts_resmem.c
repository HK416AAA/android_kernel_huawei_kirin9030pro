/*
 * hts_resmem.c
 *
 * hts resmem
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
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
#include "hts_resmem.h"
#include <linux/types.h>
#include <asm/io.h>
#include <securec.h>
#include "ffts_ddr_map.h"
#include "hts_kernel_log.h"

static void hts_plat_set_resmem_info(struct hts_resmem_info *resmem_info, phys_addr_t base, size_t len)
{
	if (resmem_info != NULL) {
		resmem_info->phy_addr = base;
		resmem_info->size = len;
	}
}

void hts_plat_get_resmem_info(struct hts_platform_info *plat_info)
{
	hts_plat_set_resmem_info(&plat_info->resmem_desc[HTS_RESMEM_AUTH_TABLE],
		FFTS_HTS_AUTH_TABLE_BASE_DDR, FFTS_HTS_AUTH_TABLE_DDR_LEN);
}

int hts_get_auth_table(u32 event, hts_check_table *check_table)
{
	uint64_t virt_addr;
	struct hts_platform_info *plat_info = hts_plat_get_info();
	if (plat_info == NULL) {
		hts_drv_err("get platform info error\n");
		return -1;
	}

	if (event > HTS_MAX_EVENT_NUM) {
		hts_drv_err("invalid event num:%u\n", event);
		return -1;
	}
	virt_addr = plat_info->resmem_desc[HTS_RESMEM_AUTH_TABLE].virt_addr;
	check_table->value = readl(virt_addr + sizeof(hts_check_table) * event);
	return 0;
}

int hts_set_auth_table(u32 event, hts_check_table *check_table)
{
	uint64_t virt_addr;
	struct hts_platform_info *plat_info = hts_plat_get_info();
	if (plat_info == NULL) {
		hts_drv_err("get platform info error\n");
		return -1;
	}

	if (event > HTS_MAX_EVENT_NUM) {
		hts_drv_err("invalid event num:%u\n", event);
		return -1;
	}

	virt_addr = plat_info->resmem_desc[HTS_RESMEM_AUTH_TABLE].virt_addr;
	writel(check_table->value, virt_addr + sizeof(hts_check_table) * event);
	__asm__ __volatile__ ("dmb sy;");
	return 0;
}
