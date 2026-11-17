/*
 * clock_mntn.c
 *
 * record clock_mntn into filesystem when booting kernel
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

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/stat.h>
#include <linux/io.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>   /* For copy_to_user */
#include <linux/vmalloc.h>   /* For vmalloc */
#include <linux/module.h>
#ifndef CONFIG_CLK_DEBUG
#include <linux/slab.h>
#include <media_xpu/media_xpu_ddr_mntn_map.h>
#include <platform_include/basicplatform/linux/rdr_pub.h> /* For mach_call_usermoduleshell */
#endif
#include <platform_include/basicplatform/linux/util.h> /* For mach_call_usermoduleshell */
#include <mntn_public_interface.h>
#include <securec.h>

#define CLOCK_MNTN_LOG_ADDR SUB_RESERVED_MEDIA_CLOCK_BASE
#define CLOCK_MNTN_LOG_SIZE SUB_RESERVED_MEDIA_CLOCK_SIZE

static char *g_clock_mntn_buff = NULL;
static char *s_clock_mntn_buff = NULL;

#ifndef CONFIG_CLK_DEBUG
#define CLOCK_MNTN_LOG_FILE	"clock_mntn.txt"
static u64 g_current_core_id = RDR_CLK;

typedef int (*cleartext_func_t)(const char *dir_path,
				struct file *fp,
				unsigned long long log_addr,
				unsigned int log_len);

struct clock_log_cleartext {
	char *name;
	unsigned int offset;
	unsigned int len;
	cleartext_func_t cleartext_func;
};

static int clear_log_parse(const char *dir_path __maybe_unused, struct file *fp,
			  u64 log_addr, u32 log_len)
{
	char *log_buff = NULL;
	u32 log_size = log_len + 1;
	s32 ret = 0;

	if (IS_ERR_OR_NULL(fp)) {
		pr_err("%s error:fp 0x%pK\n", __func__, fp);
		return -EINVAL;
	}

	log_buff = (char *)kzalloc(log_size, GFP_KERNEL);
	if (log_buff == NULL) {
		pr_err("kzalloc fail for clock_mntn_buff\n");
		return -EINVAL;
	}

	if (memcpy_s((void *)log_buff, log_size,
		     (void *)(uintptr_t)log_addr, log_len) != EOK) {
		pr_err("memcpy fail for clock_mntn_log\n");
		ret = -EINVAL;
		goto out;
	}

	ret = vfs_write(fp, log_buff, (size_t)log_len, &fp->f_pos);
	if ((u32)ret != log_len) {
		pr_err("%s write file exception with ret %d\n",
			     __func__, ret);
		ret = -EINVAL;
		goto out;
	}
out:
	kfree(log_buff);

	return ret;
}

#define IRQ_RECORED_SIZE 16
static int irq_trace_parse(const char *dir_path __maybe_unused, struct file *fp,
	u64 log_addr, u32 log_len)
{
	u32 i;
	bool error = false;
	u64 print_addr;

	if (IS_ERR_OR_NULL(fp)) {
		pr_err("%s error:fp 0x%pK\n", __func__, fp);
		return -EINVAL;
	}

	rdr_cleartext_print(fp, &error, "num  irq_in        time  irq_out        time\n");
	for (i = 0; i < log_len / IRQ_RECORED_SIZE; i++) {
		print_addr = log_addr + i * IRQ_RECORED_SIZE;
		rdr_cleartext_print(fp, &error, "%02u:     %03u",
				    i + 1, *((u8 volatile *)(uintptr_t)print_addr));
		rdr_cleartext_print(fp, &error, "  0x%08X",
				    *((u32 volatile *)(uintptr_t)(print_addr + 4)));
		rdr_cleartext_print(fp, &error, "      %03u",
				    *((u8 volatile *)(uintptr_t)(print_addr + 8)));
		rdr_cleartext_print(fp, &error, "  0x%08X\n",
				    *((u32 volatile *)(uintptr_t)(print_addr + 12)));
	}
	if (error)
		return -EINVAL;

	return 0;
}

static int soc_reg_parse(const char *dir_path __maybe_unused, struct file *fp,
	u64 log_addr, u32 log_len)
{
	u32 i;
	bool error = false;

	if (IS_ERR_OR_NULL(fp)) {
		pr_err("%s error:fp 0x%pK\n", __func__, fp);
		return -EINVAL;
	}

	rdr_cleartext_print(fp, &error, "offset      val\n");

	for (i = 0; i < log_len; i = i + 4)
		rdr_cleartext_print(fp, &error, "0x%03x       0x%08x\n", i,
				    *((u32 volatile *)(uintptr_t)(log_addr + i)));
	if (error)
		return -EINVAL;

	return 0;
}

static struct clock_log_cleartext g_clock_mntn_cleartext[] = {
	{
		"MXPU_LOG",
		MEDIA_XPU_LOG_OFFSET,
		MEDIA_XPU_LOG_DDR_SIZE,
		clear_log_parse,
	},
	{
		"MXPU_IRQ_TRACE",
		MEDIA_XPU_IRQ_TRACE_OFFSET,
		MEDIA_XPU_IRQ_TRACE_DDR_SIZE,
		irq_trace_parse
	},
	{
		"MEDIA_PMC",
		MEDIA_PMC_REG_OFFSET,
		MEDIA_XPU_PMC_DDR_SIZE,
		soc_reg_parse
	},
	{
		"MEDIA1_CRG",
		MEDIA1_CRG_REG_OFFSET,
		MEDIA1_CRG_DUMP_DDR_SIZE,
		soc_reg_parse
	},
#ifdef MEDIA2_CRG_REG1_OFFSET
	{
		"MEDIA2_CRG1",
		MEDIA2_CRG_REG1_OFFSET,
		MEDIA2_CRG_REG1_SIZE,
		soc_reg_parse
	},
#endif
#ifdef MEDIA2_CRG_REG2_OFFSET
	{
		"MEDIA2_CRG2",
		MEDIA2_CRG_REG2_OFFSET,
		MEDIA2_CRG_REG2_SIZE,
		soc_reg_parse
	},
#endif
};

static int clock_mntn_cleartext_print(const char *dir_path,
	u64 log_addr, u32 log_len)
{
	bool error = false;
	u32 idx;
	u64 log_addr_parse;
	u32 log_len_parse;
	s32 ret = 0;
	struct file *fp = NULL;

	fp = bbox_cleartext_get_filep(dir_path, CLOCK_MNTN_LOG_FILE);
	if (IS_ERR_OR_NULL(fp)) {
		pr_err("%s error:fp 0x%pK.\n", __func__, fp);
		return -EINVAL;
	}

	if (IS_ERR_OR_NULL(dir_path) || IS_ERR_OR_NULL((void *)(uintptr_t)log_addr)) {
		pr_err("%s error:dir_path 0x%pK log_addr 0x%llx.\n",
			__func__, dir_path, log_addr);
		ret = -EINVAL;
		goto out;
	}

	if (log_len < RDR_CLK_MEM_MAP_SIZE) {
		pr_err("log_len error:0x%x.\n", log_len);
		ret = -EINVAL;
		goto out;
	}

	for (idx = 0; idx < ARRAY_SIZE(g_clock_mntn_cleartext); idx++) {
		log_addr_parse = log_addr +	g_clock_mntn_cleartext[idx].offset;
		log_len_parse = g_clock_mntn_cleartext[idx].len;
		rdr_cleartext_print(fp, &error, "=================%s START================\n",
			g_clock_mntn_cleartext[idx].name);
		ret = g_clock_mntn_cleartext[idx].cleartext_func(dir_path, fp, log_addr_parse, log_len_parse);
		rdr_cleartext_print(fp, &error, "=================%s END================\n\n",
			g_clock_mntn_cleartext[idx].name);
	}

out:
	bbox_cleartext_end_filep(fp, dir_path, CLOCK_MNTN_LOG_FILE);
	return ret;
}
#endif

static ssize_t clock_mntn_dump_file_read(struct file *file __maybe_unused,
					char __user *userbuf, size_t bytes,
					loff_t *off)
{
	ssize_t copy;

	if (off == NULL)
		return 0;

	if (*off > (loff_t)CLOCK_MNTN_LOG_SIZE) {
		pr_err("%s: read offset error\n", __func__);
		return 0;
	}

	if (*off == (loff_t)CLOCK_MNTN_LOG_SIZE) {
		/* end of file */
		return 0;
	}

	if (userbuf == NULL) {
		/* end of file */
		return 0;
	}

	copy = (ssize_t)(uintptr_t) min(bytes, (size_t) (CLOCK_MNTN_LOG_SIZE - *off));

	if (copy_to_user(userbuf, s_clock_mntn_buff + *off, copy)) {
		pr_err("%s: copy to user error\n", __func__);
		copy = -EFAULT;
		return copy;
	}

	*off += copy;

	return copy;
}

static const struct proc_ops clock_mntn_dump_file_fops = {
	.proc_read = clock_mntn_dump_file_read,
};

static void init_save_log(void)
{
	int ret;

	s_clock_mntn_buff = vmalloc(CLOCK_MNTN_LOG_SIZE);
	if (s_clock_mntn_buff == NULL) {
		pr_err(
			"%s: fail to vmalloc %#x bytes s_clock_mntn_log_buff\n",
			__func__, CLOCK_MNTN_LOG_SIZE);
		return;
	}

	ret = memcpy_s(s_clock_mntn_buff, CLOCK_MNTN_LOG_SIZE, g_clock_mntn_buff, CLOCK_MNTN_LOG_SIZE);
	if (ret != EOK) {
		pr_err("%s():%d:memcpy_s fail!\n", __func__, __LINE__);
		vfree(s_clock_mntn_buff);
		s_clock_mntn_buff = NULL;
		return;
	}

	return;
}

static int __init clock_mntn_init(void)
{
	int use_ioremap = 0;
	int ret = 0;

	if (!check_mntn_switch(MNTN_GOBAL_RESETLOG))
		return ret;

	if (pfn_valid(__phys_to_pfn(CLOCK_MNTN_LOG_ADDR))) {
		g_clock_mntn_buff = phys_to_virt(CLOCK_MNTN_LOG_ADDR);
	} else {
		use_ioremap = 1;
		g_clock_mntn_buff =
		    ioremap_wc(CLOCK_MNTN_LOG_ADDR, CLOCK_MNTN_LOG_SIZE);
	}
	if (g_clock_mntn_buff == NULL) {
		pr_err("%s: fail to get the virtual address of clock_mntn\n", __func__);
		return -1;
	}

	init_save_log();

	if (use_ioremap && g_clock_mntn_buff != NULL)
		iounmap(g_clock_mntn_buff);

	if (s_clock_mntn_buff != NULL)
		dfx_create_log_proc_entry("clock_mntn_log", S_IRUSR | S_IRGRP,
					     &clock_mntn_dump_file_fops, NULL);

#ifndef CONFIG_CLK_DEBUG
	ret = rdr_register_cleartext_ops(g_current_core_id,
		clock_mntn_cleartext_print);
#endif

	return ret;
}

module_init(clock_mntn_init);

static void __exit clock_mntn_exit(void)
{
	dfx_remove_log_proc_entry("clock_mntn_log");

	if (g_clock_mntn_buff != NULL) {
		iounmap(g_clock_mntn_buff);
		g_clock_mntn_buff = NULL;
	}

	if (s_clock_mntn_buff != NULL) {
		vfree(s_clock_mntn_buff);
		s_clock_mntn_buff = NULL;
	}
}

module_exit(clock_mntn_exit);
