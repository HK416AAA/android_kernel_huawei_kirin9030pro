/*
 * ffts_atf.c
 *
 * ffts atf
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
#include "ffts_tzsp.h"
#include "ffts_log.h"
#include <linux/arm-smccc.h>

noinline int tzsp_service_ffts_smc(u64 _service_id, u64 _cmd, u64 _arg1,
	u64 _arg2)
{
	int ret;
	struct ffa_send_direct_data args = {
		.data0 = (unsigned long)_service_id,
		.data1 = (unsigned long)_cmd,
		.data2 = (unsigned long)_arg1,
		.data3 = (unsigned long)_arg2,
		.data4 = 0
	};

	ret = ffa_platdrv_send_msg(&args);
	if (ret != 0 || args.data4 != 0) {
		ffts_drv_err("ffa platdrv send msg error, service_id = 0x%llx, ret = %d, data4 = 0x%llx\n",
			_service_id, ret, args.data4);
		return (int)args.data4;
	}
	return ret;
}