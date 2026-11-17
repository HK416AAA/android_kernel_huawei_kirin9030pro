// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024. All rights reserved.
 * Description:
 * Soc Chip Dfx switch
 */
#include <linux/types.h>
#include <linux/init.h>
#include <linux/printk.h>
#include <linux/errno.h>

#include <securec.h>
#include <platform_include/basicplatform/linux/hw_cmdline_parse.h>

unsigned int soc_dfx_enable = 0;

static int __init early_parse_soc_dfx_switch(char *p)
{
	int ret;
	char clow[HEX_STRING_MAX + 1] = {0};

	if (p == NULL) {
		soc_dfx_enable = 0; /* error parameter, switch logger off */
		pr_err("%s input is NULL\n", __func__);
		return 0;
	}

	if (memcpy_s(clow, HEX_STRING_MAX + 1, p, HEX_STRING_MAX) != EOK) {
		pr_err("%s:%d Err\n", __func__, __LINE__);
		return -EINVAL;
	}

	ret = kstrtoint(clow, TRANSFER_BASE, &soc_dfx_enable);
	if (ret)
		return ret;

	pr_err("soc_dfx switch=%u\n", soc_dfx_enable);

	return 0;
}
early_param("soc_dfx", early_parse_soc_dfx_switch);
