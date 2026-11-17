/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: Contexthub 9030 driver.
 * Create: 2024-10-10
 */

#include <linux/printk.h>
#include <linux/export.h>
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_hal.h>
#include "iodie_dev.h"
#include "iodie_drv.h"

enum iodie_sys_status get_iodie_status(void)
{
	enum iodie_sys_status status;

	status = iodie_drv_get_sys_status();
	if (status == IODIE_ST_ERR)
		pr_err("%s: status err, sys %u, err %u\n", __func__, (unsigned int)status,
			(unsigned int)iodie_drv_get_err_status());

	return status;
}
EXPORT_SYMBOL(get_iodie_status);

enum iodie_runtime_status get_iodie_rt_status(void)
{
	enum iodie_runtime_status status;

	status = (enum iodie_runtime_status)iodie_dev_lp_status();

	return status;
}
EXPORT_SYMBOL(get_iodie_rt_status);

inline void iodie_writel(enum iodie_module module, unsigned int addr, unsigned int val)
{
	iodie_dev_writel(module, addr, val);
}

inline unsigned int iodie_readl(enum iodie_module module, unsigned int addr)
{ 
	return iodie_dev_readl(module, addr);
}

int iodie_normal_request(enum iodie_user user, enum iodie_runtime_status status)
{
	return iodie_drv_normal_request(user, status);
}
EXPORT_SYMBOL(iodie_normal_request);

int iodie_normal_release(enum iodie_user user, enum iodie_runtime_status status)
{
	return iodie_drv_normal_release(user, status);
}
EXPORT_SYMBOL(iodie_normal_release);

int iodie_fnpll_request(enum iodie_user user)
{
	return iodie_drv_fnpll_request(user);
}
EXPORT_SYMBOL(iodie_fnpll_request);

int iodie_fnpll_release(enum iodie_user user)
{
	return iodie_drv_fnpll_release(user);
}
EXPORT_SYMBOL(iodie_fnpll_release);

int iodie_notify_register(enum iodie_user user, iodie_user_func func)
{
	return iodie_drv_notify_register(user, func);
}
EXPORT_SYMBOL(iodie_notify_register);

void iodie_clk_en(enum iodie_module module)
{
	iodie_dev_clk_en(module);
}

void iodie_clk_dis(enum iodie_module module)
{
	iodie_dev_clk_dis(module);
}

int iodie_clk_out_sys(enum iodie_clk_out_op op)
{
	return iodie_drv_clk_out_sys(op, 0);
}

int iodie_clk_out_sys_freq(enum iodie_clk_out_op op, unsigned int freq)
{
	return iodie_drv_clk_out_sys(op, freq);
}