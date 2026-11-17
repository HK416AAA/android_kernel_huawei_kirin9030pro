/*
 * ffts_dfx_black_box.h
 *
 * about ffts dfx black box
 *
 * Copyright (c) 2012-2023 Huawei Technologies Co., Ltd.
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
#ifndef __FFTS_BLACK_BOX_H
#define __FFTS_BLACK_BOX_H

#include <platform_include/basicplatform/linux/rdr_pub.h>
#define FFTS_BUF_LEN_MAX 256

enum rdr_ffts_system_error_type {
	EXC_TYPE_FFTS_NO_ERROR = 0x0,
	/* DFX_BB_MOD_FFTS_START is 0xc0007000 */
	MODID_FFTS_START = DFX_BB_MOD_FFTS_START,

	EXC_TYPE_BLOCK_PROC_EXCEPTION = 0xc0007001,
	EXC_TYPE_BLOCK_GPU_EXCEPTION = 0xc0007002,
	EXC_TYPE_BLOCK_NPU_EXCEPTION = 0xc0007003,
	EXC_TYPE_CMO_EXCEPTION = 0xc0007004,
	EXC_TYPE_RETRY_EXCEPTION = 0xc0007005,
	EXC_TYPE_ABNORMAL_EXCEPTION = 0xc0007006,
};

int ffts_black_box_init(void);

int ffts_black_box_exit(void);

void ffts_rdr_exception_report(uint32_t error_code);

int ffts_mntn_copy_reg_to_bbox(const char *src_addr,
	unsigned int len);

void ffts_dump_to_file(char* file_name, void *addr, size_t size, loff_t pos);

#endif /* __FFTS_BLACK_BOX_H */
