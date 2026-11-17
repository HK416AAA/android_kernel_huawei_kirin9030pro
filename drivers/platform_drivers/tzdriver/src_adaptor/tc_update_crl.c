/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include "tz_update_crl.h"
#include <linux/namei.h>
#include <linux/fs.h>
#include <linux/vmalloc.h>
#include <securec.h>
#include "tc_ns_log.h"
#include "tc_current_info.h"

#define D_PATH_LEN 256
static struct file *crl_file_open(const char *file_path)
{
	struct file *fp = NULL;
	int ret;
	char *dpath = NULL;
	char tmp_buf[D_PATH_LEN] = { 0 };
	struct path base_path = {
		.mnt = NULL,
		.dentry = NULL
	};

	ret = kern_path(file_path, LOOKUP_FOLLOW, &base_path);
	if (ret != 0)
		return NULL;

	dpath = d_path(&base_path, tmp_buf, D_PATH_LEN);
	if (!dpath || IS_ERR(dpath))
		goto clean;

	fp = filp_open(dpath, O_RDONLY, 0);

clean:
	path_put(&base_path);
	return fp;
}

int tz_update_crl(const char *file_path, const struct tc_ns_dev_file *dev_file)
{
	struct file *fp = NULL;
	uint32_t crl_len, read_size;
	char *crl_buffer = NULL;
	loff_t pos = 0;
	int ret = 0;

	if (!file_path || !dev_file) {
		tloge("invalid params\n");
		return -EINVAL;
	}

	fp = crl_file_open(file_path);
	if (!fp || IS_ERR(fp)) {
		tloge("open crl file error, ret = %ld\n", PTR_ERR(fp));
		return -ENOENT;
	}

	if (!fp->f_inode) {
		tloge("node is NULL\n");
		ret = -EINVAL;
		goto clean;
	}

	crl_len = (uint32_t)(fp->f_inode->i_size);
	if (crl_len > DEVICE_CRL_MAX) {
		tloge("crl file len is invalid %u\n", crl_len);
		ret = -EINVAL;
		goto clean;
	}

	crl_buffer = vmalloc(crl_len);
	if (!crl_buffer) {
		tloge("alloc crl file buffer(size=%u) failed\n", crl_len);
		ret = -ENOMEM;
		goto clean;
	}

	read_size = (uint32_t)kernel_read(fp, crl_buffer, crl_len, &pos);
	if (read_size != crl_len) {
		tloge("read crl file failed, read size/total size=%u/%u\n", read_size, crl_len);
		ret = -ENOENT;
		goto clean;
	}

	ret = send_crl_to_tee(crl_buffer, crl_len, dev_file);
	if (ret != 0) {
		tloge("send crl to tee failed\n");
		goto clean;
	}

clean:
	filp_close(fp, 0);
	if (crl_buffer)
		vfree(crl_buffer);
	return ret;
}
