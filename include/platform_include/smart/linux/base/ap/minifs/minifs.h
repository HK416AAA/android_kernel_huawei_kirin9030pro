/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: minifs header file
 * Create: 2025/03/27
 */
#ifndef __MINIFS_H__
#define __MINIFS_H__

enum fs_cmd {
	FS_CMD_INIT_FILE_LIST_CMA = 0x30,
	FS_CMD_BEFORE_RELEASE_CMA = 0x31,
};

#define FILE_MAX 10
#define PATH_MAX 1024

struct file_info {
	char file_name[PATH_MAX];
	unsigned int file_index;
};

struct sh_minifs_msg {
	unsigned int fs_cmd;
	unsigned int cma_addr;
	unsigned int cma_size;
	unsigned int user_data_addr;
	unsigned int file_num;
	struct file_info file_info[FILE_MAX];
};

void init_cma_only(unsigned int cma_addr, unsigned int cma_size, int shared_fd);
void release_cma_only(unsigned int cma_addr, unsigned int cma_size);

int init_all_file_map_info(char **file_name_list, unsigned int file_num);
int release_file_list_in_cma(void);
#endif