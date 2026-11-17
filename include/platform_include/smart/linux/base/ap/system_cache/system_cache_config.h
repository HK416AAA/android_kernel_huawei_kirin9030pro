/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: system cache ipc information
 * Create: 2024-03-4
 */
#ifndef __SYSTEM_CACHE_CONFIG_H__
#define __SYSTEM_CACHE_CONFIG_H__

typedef enum {
	CMD_CACHE_ENABLE = 0x01,
	CMD_CACHE_BYPASS,
	CMD_ALLOC_SYNC_BUFFER,
	CMD_FREE_SYNC_BUFFER,
} sc_cmd_t;

struct lb_ctrl_t {
	union lb_ctrl_e {
		struct cache_ctrl {
			unsigned int quota;
			unsigned char type;
			unsigned char prio;
		} cc;
		struct buff_ctrl {
			unsigned int size;
		} bc;
	} para;
	unsigned char pid;
};

#endif