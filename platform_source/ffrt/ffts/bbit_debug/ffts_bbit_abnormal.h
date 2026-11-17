/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: for ffts drv bbit abnm
 */
#ifndef __FFTS_BBIT_ABNORMAL_H
#define __FFTS_BBIT_ABNORMAL_H

#include <linux/types.h>
#include <linux/fs.h>

ssize_t ffts_bbit_abnormal_read(struct file *filp, char __user *buf,
	size_t count, loff_t *ppos);
ssize_t ffts_bbit_abnormal_write(struct file *filp, const char __user *buf,
	size_t count, loff_t *ppos);

#endif /* __FFTS_BBIT_ABNORMAL_H */
