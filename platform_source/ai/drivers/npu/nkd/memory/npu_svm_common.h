/*
 * npu_svm_common.h
 *
 * about npu svm
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
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
#ifndef __NPU_SVM_COMMON_H
#define __NPU_SVM_COMMON_H
#include "npu_common.h"

#define NPU_SSID_NUM 32

struct t_svm_pid_info {
	pid_t svm_pid; // the key of the list is svm pid
	pid_t manager_pid;
	pid_t ori_pid; // original pid for anco, is same as svm_pid out of anco
	uint16_t ssid;
	struct mm_svm *npu_svm;
};

#define DRVDEV_APP_MAX_NUM 30
struct t_svm_manager {
	struct mutex lock;
	uint32_t item_num;
	struct t_svm_pid_info svm_pid_info[DRVDEV_APP_MAX_NUM];
#ifdef CONFIG_NPU_ASSIGN_SSID
	DECLARE_BITMAP(npu_ssid_bitmap, NPU_SSID_NUM);
	struct mutex npu_ssid_assign_lock;
#endif
};

#ifndef VA_BITS
#define VA_BITS CONFIG_ARM64_VA_BITS
#endif

int npu_svm_manager_init(u8 devid);
int npu_check_item_bypid(struct t_svm_manager *svm_manager,
	pid_t svm_pid);
int npu_svm_unbind(u8 devid, pid_t svm_pid);
int npu_insert_item_bypid(u8 devid, pid_t manager_pid, pid_t ori_pid, pid_t svm_pid);
int npu_release_item_bypid(u8 devid, pid_t manager_pid, pid_t svm_pid);
int npu_clear_pid_ssid_table(u8 devid, pid_t pid, int flag);
int npu_svm_manager_destroy(u8 devid);
int npu_check_app_pid(struct npu_dev_ctx *cur_dev_ctx, pid_t process_id);
int npu_get_server_pid(struct npu_dev_ctx *cur_dev_ctx, pid_t process_id, pid_t *server_id);

#endif
