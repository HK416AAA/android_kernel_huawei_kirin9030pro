/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef UKMD_DACC_LOG_FUNCS_H
#define UKMD_DACC_LOG_FUNCS_H

#include <linux/types.h>
#include <linux/io.h>

#define DACC_LOG_ADDR_REG			(0x15C30)
#define DACC_LOG_SIZE_REG			(0x15C34)
#define LOG_PATH_LEN      			128

struct ukmd_dacc_log_dump_infos {
	uint32_t log_addr; // dacc log mem addr
	uint32_t log_total_size; // dacc log mem total size
	uint32_t log_info_num; // dacc log info num: 3
	uint32_t log_max_size; // dacc log size: log_total_size - log_info_num
	uint32_t log_head_addr; // dacc log info start addr:  (log_addr + (log_max_size << 2))
	uint32_t log_head_offset; // DACC_OFFSET + log_head_addr
	uint32_t log_head_rptr_offset; // dacc log rptr addr: log_head_offset
	uint32_t log_head_wptr_offset; // dacc log wptr addr: log_head_offset + 4
	uint32_t log_head_flag_offset; // dacc log flag addr: log_head_offset + 8
	uint32_t log_data_offset; // dacc log data addr: DACC_OFFSET + log_addr
	uint32_t read_cnt_add; // log read cnt by now
	uint32_t total_read_cnt; // record total read cnt 
	int32_t file_num; // log file num currently
	uint32_t file_flag; // file write mode
	uint8_t log_type; // DSS_LOG or AAE_LOG
	char __iomem *dpu_base;
	uint8_t log_file_path[LOG_PATH_LEN];
	bool dir_is_ok;
	uint32_t *log_buf;
};

enum DACC_LOG_TYPE {
    DPU_DACC_LOG = 0,
    AAE_DACC_LOG,
    DUMP_LOG_TYPE_NUM,
};

int32_t ukmd_dacc_log_read_init(char __iomem *dpu_base, uint32_t dacc_offset, 
						    	uint8_t type, struct ukmd_dacc_log_dump_infos *dacc_log_info);
void ukmd_dacc_log_read_deinit(struct ukmd_dacc_log_dump_infos *dacc_log_info);
uint32_t ukmd_read_dacc_log_to_file(struct ukmd_dacc_log_dump_infos *dacc_log_info);
uint32_t ukmd_dacc_dump_reserved_log(struct ukmd_dacc_log_dump_infos *dacc_log_info);
uint32_t ukmd_exception_dacc_log_dump(struct ukmd_dacc_log_dump_infos *dacc_log_info);

#endif