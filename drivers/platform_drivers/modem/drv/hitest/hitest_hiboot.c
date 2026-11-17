/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2020. All rights reserved.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <securec.h>
#include <bsp_partition.h>
#include <bsp_blk.h>
#include "hitest_cov.h"

int hitest_get_hiboot_cov(void)
{
    int ret;
    struct cov_data_hdr hdr = {0};
    loff_t part_size = 0;
    struct cov_data_hdr *cov_data = NULL;

    ret = bsp_blk_get_part_size(PTABLE_HIBOOT, &part_size);
    if (ret) {
        hitest_err("get part size err\n");
        return -1;
    }

    ret = bsp_blk_read(PTABLE_HIBOOT, part_size - sizeof(hdr), &hdr, sizeof(hdr));
    if (ret) {
        hitest_err("get cov hdr err\n");
        return -1;
    }

    cov_data = kzalloc(sizeof(struct cov_data_hdr) + hdr.data_len, GFP_KERNEL);
    if (cov_data == NULL) {
        hitest_err("alloc hiboot cov_data memory error!\n");
        return -1;
    }

    (void)memcpy_s(cov_data, sizeof(struct cov_data_hdr), &hdr, sizeof(hdr));

    ret = bsp_blk_read(PTABLE_HIBOOT, part_size - sizeof(hdr) - hdr.data_len, cov_data->data, cov_data->data_len);
    if (ret) {
        hitest_err("get hiboot cov data fail\n");
        kfree(cov_data);
        return -1;
    }

    creat_cov_file(cov_data);

    kfree(cov_data);

    return 0;
}

EXPORT_SYMBOL(hitest_get_hiboot_cov);
