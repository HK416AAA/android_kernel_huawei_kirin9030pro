/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2021. All rights reserved.
 * Description: Contexthub fs adapter.
 * Create: 2025-05-15
 */
#ifndef _IOMCU_FS_ADAPTER_H_
#define _IOMCU_FS_ADAPTER_H_
 
#include <linux/fs.h>
#include <linux/slab.h>
#include "securec.h"
#include <linux/dma-buf.h>
 
#include <platform_include/smart/linux/base/ap/30/tag.h>
#include <platform_include/smart/linux/base/ap/30/cmd.h>
#include <platform_include/smart/linux/iomcu_ipc.h>
#include <platform_include/smart/linux/iomcu_dump_info_restore.h>
 
void iomcu_sh_file_set_cma_addr(int fb, unsigned long buf_addr, unsigned int size);
void iomcu_sh_file_free_cma_addr(void);
 
#endif