// SPDX-License-Identifier: GPL-2.0
/*
 * sched_chip_info.c
 *
 * Copyright (c) 2025-2026 Huawei Technologies Co., Ltd.
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

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/kernel.h>
#include <platform_include/basicplatform/linux/soc_spec.h>

#include "sched_chip_info.h"

unsigned int soc_power_type;
unsigned int soc_pg_type_nr;
unsigned int soc_pg_type[PG_TYPE_MAX_NR];

static int soc_energy_type_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%u\n", soc_power_type);
	return 0;
}

static int soc_energy_type_open(struct inode *inode, struct file *file)
{
	return single_open(file, soc_energy_type_show, inode->i_private);
}

static const struct proc_ops energy_type_proc_fops = {
	.proc_open = soc_energy_type_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};

static int soc_pg_type_show(struct seq_file *m, void *v)
{
	unsigned int i;

	for (i = 0; i < soc_pg_type_nr; i++) {
		seq_printf(m, "%u ", soc_pg_type[i]);
	}
	seq_printf(m, "\n");

	return 0;
}

static int soc_pg_type_open(struct inode *inode, struct file *file)
{
	return single_open(file, soc_pg_type_show, inode->i_private);
}

static const struct proc_ops pg_type_proc_fops = {
	.proc_open = soc_pg_type_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};

static int soc_eer_show(struct seq_file *m, void *v)
{
	unsigned int chip_type = soc_pg_type[SOC_COMPONENT_CHIP_TYPE_INFO];

	seq_printf(m, "%u\n", get_soc_energy_level(chip_type, soc_power_type));

	return 0;
}

static int soc_eer_open(struct inode *inode, struct file *file)
{
	return single_open(file, soc_eer_show, inode->i_private);
}

static const struct proc_ops soc_eer_proc_fops = {
	.proc_open = soc_eer_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};

static int __init sched_chip_info_init(void)
{
	struct proc_dir_entry *base = proc_mkdir("sched_device_info", NULL);
	if (base == NULL) {
		pr_err("%s proc create chip_info failed\n", __func__);
		return -EINVAL;
	}

	get_soc_power_type(&soc_power_type);
	proc_create("energy_type", S_IRUSR | S_IRGRP, base, &energy_type_proc_fops);

	get_soc_pg_type(&soc_pg_type[0], &soc_pg_type_nr);
	proc_create("pg_type", S_IRUSR | S_IRGRP, base, &pg_type_proc_fops);

	proc_create("soc_info", S_IRUSR | S_IRGRP, NULL, &soc_eer_proc_fops);

	return 0;
}

fs_initcall(sched_chip_info_init);

