/*
 * npu_svm.h
 *
 * about npu svm
 *
 * Copyright (c) 2012-2020 Huawei Technologies Co., Ltd.
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
#ifndef __NPU_SVM_H
#define __NPU_SVM_H
#include "npu_common.h"
#include "npu_svm_common.h"

int npu_svm_bind(struct npu_dev_ctx *cur_dev_ctx, pid_t manager_pid, pid_t svm_pid, uint16_t *uid);
int npu_get_ssid_bypid(u8 devid, pid_t manager_pid, pid_t svm_pid, uint16_t *ssid, uint64_t *ttbr, uint64_t *tcr);
int npu_get_ttbr(u64 *ttbr, u64 *tcr, pid_t process_id);
int npu_manager_svm_bind(struct npu_dev_ctx *cur_dev_ctx);
int npu_svm_flushcache_bypid(struct npu_dev_ctx *cur_dev_ctx, pid_t svm_pid);
pid_t npu_svm_get_root_pid(u8 devid, pid_t manager_pid, pid_t ori_pid);
#endif
