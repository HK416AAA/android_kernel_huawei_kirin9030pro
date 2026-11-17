/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * Description:
 */
#include "ffts_bbit_debug.h"

#include <linux/fs.h>
#include <linux/debugfs.h>

#include "ffts_bbit_abnormal.h"
#include "ffts_log.h"
#include "ffts_common.h"

#define DEBUGFS_ROOT_DIR NULL

struct ffts_bbit_debugfs_fops {
	struct file_operations fops;
	const char *file_name;
};

static struct dentry *g_ffts_bbit_debugfs_dir;

static int ffts_bbit_debugfs_show(struct seq_file *s, void *data)
{
	unused(data);

	if (s == NULL)
		return -1;

	seq_printf(s, "open bbit debugfs\n");
	return 0;
}

static int ffts_bbit_debugfs_open(struct inode *inode, struct file *file)
{
	if ((inode == NULL) || (file == NULL)) {
		ffts_drv_err("invalid para\n");
		return -1;
	}
	return single_open(file, ffts_bbit_debugfs_show, inode->i_private);
}

static const struct ffts_bbit_debugfs_fops g_ffts_bbit_debugfs[] = {
	{
		{
			.owner   = THIS_MODULE,
			.open	= ffts_bbit_debugfs_open,
			.read	= ffts_bbit_abnormal_read,
			.write   = ffts_bbit_abnormal_write,
			.llseek  = seq_lseek,
			.release = single_release,
		},
		.file_name	   = "abnormal",
	},
};


int ffts_bbit_debug_init(void)
{
	unsigned int i;
	struct dentry *bbit_dir = g_ffts_bbit_debugfs_dir;

	ffts_drv_warn("init ffts bbit debugfs\n");
	if (bbit_dir != NULL) {
		ffts_drv_err("invalid bbit dir\n");
		return -EINVAL;
	}

	bbit_dir = debugfs_create_dir("ffts_bbit_debugfs", DEBUGFS_ROOT_DIR);
	if (IS_ERR_OR_NULL(bbit_dir)) {
		ffts_drv_err("create ffts_bbit_debug fail\n");
		return -EINVAL;
	}

	for (i = 0; i < sizeof(g_ffts_bbit_debugfs) / sizeof(g_ffts_bbit_debugfs[0]);
		i++)
		debugfs_create_file(g_ffts_bbit_debugfs[i].file_name, 00660,
			bbit_dir, NULL, &(g_ffts_bbit_debugfs[i].fops));

	return 0;	
}
