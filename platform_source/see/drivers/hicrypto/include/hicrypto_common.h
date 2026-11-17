/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine common soft process
 * Create: 2024/03/01
 */
#ifndef __HICRYPTO_COMMON_H__
#define __HICRYPTO_COMMON_H__
#include "hicrypto_driver.h"
#include "hicrypto_dev_data.h"

/* hicrypto interface */
int hisi_dev_symm_build_hwaddr(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *proc,
	struct hisi_drv_symm_sg_list_info *plist_sg_info);

int hisi_dev_symm_tx_out_process(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *proc,
	struct hisi_drv_symm_sg_list_info *plist_sg_info);

int hisi_dev_symm_clean_workspace(struct hisi_dev_symm_data_proc *proc,
	struct hisi_drv_symm_sg_list_info *plist_sg_info);

unsigned int hisi_dev_symm_cal_timeoutus(unsigned int dinlen);
#endif