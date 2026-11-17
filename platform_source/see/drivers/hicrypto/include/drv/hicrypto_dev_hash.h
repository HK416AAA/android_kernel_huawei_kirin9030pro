/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine dev data struct
 * Create: 2024/04/16
 */
#ifndef __HICRYPTO_DEV_HASH_H__
#define __HICRYPTO_DEV_HASH_H__
#include "hicrypto_driver.h"
#include "hicrypto_dev_data.h"
#include "hicrypto_ctx_def.h"

int hisi_dev_hash_run_cmd(struct hicrypto_device *hdev, struct hi_hash_req_ctx_inner *ctx,
                          struct hisi_dev_symm_data_proc *proc, struct hisi_drv_symm_sg_list_info *plist_sg_info);
#endif