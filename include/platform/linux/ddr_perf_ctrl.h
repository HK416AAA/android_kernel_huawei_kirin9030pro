/*
 * Copyright (c) 2020-2020 Huawei Device Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __DDR_PERF_CTRL_H
#define __DDR_PERF_CTRL_H

struct ddr_flux {
	unsigned long long rd_flux;
	unsigned long long wr_flux;
};

#ifdef CONFIG_HUAWEI_DDR_PERF_CTRL
int perf_ctrl_get_ddr_flux(void __user *uarg);
int perf_ctrl_get_ddr_other_vote(void __user *uarg);
#else
static inline int perf_ctrl_get_ddr_flux(void __user *uarg)
{
	return -EFAULT;
}

static inline int perf_ctrl_get_ddr_other_vote(void __user *uarg)
{
	return -EFAULT;
}
#endif

#endif
