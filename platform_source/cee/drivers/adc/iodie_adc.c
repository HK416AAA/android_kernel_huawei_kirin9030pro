/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: for the iodie hkadc driver.
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
#include <platform_include/cee/linux/adc.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/err.h>
#include <linux/delay.h>
#include <linux/debugfs.h>
#include <securec.h>

#ifdef CONFIG_PM_DEL_PLATFORM_ADDR
#include <lpm_kernel_map.h>
#else
#include <soc_acpu_baseaddr_interface.h>
#endif

#include <platform_include/smart/drivers/io_die/iodie_hiphyio_hal.h>
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_def.h>
#include "iodie_adc.h"

/* HKADC register value */
#define HKADC_DATA_EN				(1)
#define HKADC_CHANNEL_MAX			(8)

#define HKADC_PARA0_ADDR			0x500
#define HKADC_PARA1_ADDR			0x504

#define ADC_RESULT_ERR				(-EINVAL)
#define HKADC_VREF				1500
#define HKADC_ACCURACY				0xFFF
#define ACTRL_SIZE				0xFFF
#define HKADC_PARA_K_SIZE			0x3FFFF
#define HKADC_PARA_K_SHIFT			6
#define HKADC_PARA_B1_SIZE			0x7F80
#define HKADC_PARA_B1_SHIFT			17
#define HKADC_PARA_B2_SIZE			0x7F

#define IODIE_HKADC_DATA_GRADE0 0
#define IODIE_HKADC_DATA_GRADE1 100
#define IODIE_HKADC_DATA_GRADE2 300
#define IODIE_HKADC_DATA_GRADE3 500
#define IODIE_HKADC_DATA_GRADE4 700
#define IODIE_HKADC_DATA_GRADE5 900
#define IODIE_HKADC_DATA_GRADE6 1100
#define IODIE_HKADC_DATA_GRADE7 1300
#define IODIE_HKADC_DATA_GRADE8 1500
#define IODIE_HKADC_DATA_GRADE9 1700
#define IODIE_HKADC_DATA_GRADE10 1800
#define IODIE_BOARDID_VALUE0 0x0
#define IODIE_BOARDID_VALUE1 0x1
#define IODIE_BOARDID_VALUE2 0x2
#define IODIE_BOARDID_VALUE3 0x3
#define IODIE_BOARDID_VALUE4 0x4
#define IODIE_BOARDID_VALUE5 0x5
#define IODIE_BOARDID_VALUE6 0x6
#define IODIE_BOARDID_VALUE7 0x7
#define IODIE_BOARDID_VALUE8 0x8
#define IODIE_BOARDID_VALUE9 0x9
#define IODIE_BOARDID_UNKNOWN 0xF
static struct {
	int start;
	int end;
	int val;
} hkadc_maps[] = {
	{IODIE_HKADC_DATA_GRADE0, IODIE_HKADC_DATA_GRADE1, IODIE_BOARDID_VALUE0},
	{IODIE_HKADC_DATA_GRADE1 + 1, IODIE_HKADC_DATA_GRADE2, IODIE_BOARDID_VALUE1},
	{IODIE_HKADC_DATA_GRADE2 + 1, IODIE_HKADC_DATA_GRADE3, IODIE_BOARDID_VALUE2},
	{IODIE_HKADC_DATA_GRADE3 + 1, IODIE_HKADC_DATA_GRADE4, IODIE_BOARDID_VALUE3},
	{IODIE_HKADC_DATA_GRADE4 + 1, IODIE_HKADC_DATA_GRADE5, IODIE_BOARDID_VALUE4},
	{IODIE_HKADC_DATA_GRADE5 + 1, IODIE_HKADC_DATA_GRADE6, IODIE_BOARDID_VALUE5},
	{IODIE_HKADC_DATA_GRADE6 + 1, IODIE_HKADC_DATA_GRADE7, IODIE_BOARDID_VALUE6},
	{IODIE_HKADC_DATA_GRADE7 + 1, IODIE_HKADC_DATA_GRADE8, IODIE_BOARDID_VALUE7},
	{IODIE_HKADC_DATA_GRADE8 + 1, IODIE_HKADC_DATA_GRADE9, IODIE_BOARDID_VALUE8},
	{IODIE_HKADC_DATA_GRADE9 + 1, IODIE_HKADC_DATA_GRADE10, IODIE_BOARDID_VALUE9},
};

#ifdef CONFIG_IODIE_HKADC_DEBUG
#define MODULE_NAME		"iodie_adc"
#define IODIE_HKADC_ABORT_MASK	3

static struct dentry *g_iodie_debugfs_root;
static int g_iodie_buff[3];
static u32 g_iodie_abort_threshold;
#endif

static u32 g_adc_para_k;
static u32 g_adc_para_b;
static void __iomem *g_actrl_base;

static DEFINE_MUTEX(hiphyio_mutex);

static int iodie_hkadc_get_value(int channel)
{
	u32 data;
	u32 val;

	if (channel >= HKADC_CHANNEL_MAX) {
		pr_err("iodie Adc channel Er:%d\n", channel);
		return HKADC_ERROR;
	}

	val = iodie_readl(IODIE_IP_ADC, HKADC_RESET);
	val |= BIT(0);
	iodie_writel(IODIE_IP_ADC, HKADC_RESET, val);

	udelay(5);

	val = iodie_readl(IODIE_IP_ADC, HKADC_CHANNEL_SEL);
	val &= ~0xF;
	val |= channel;
	iodie_writel(IODIE_IP_ADC, HKADC_CHANNEL_SEL, channel);

	val = iodie_readl(IODIE_IP_ADC, HKADC_RESET);
	val &= ~BIT(0);
	iodie_writel(IODIE_IP_ADC, HKADC_RESET, val);

	udelay(100);

	data = iodie_readl(IODIE_IP_ADC, HKADC_DATA);
	data &= 0x1fff;
	if (data & HKADC_DATA_EN) {
		if (g_adc_para_k) {
			return ((data >> HKADC_DATA_EN) * g_adc_para_k + g_adc_para_b);
		} else {
			return (data >> HKADC_DATA_EN);
		}
	}

	pr_err("iodie Adc data error:%d, \n", data);
	return HKADC_ERROR;
}

static void iodie_hkadc_disable(void)
{
	u32 val;

	// clk disable, reset enable
	val = iodie_readl(IODIE_IP_AO_CRG, HKADC_CLK_EN);
	val &= ~BIT(24);
	iodie_writel(IODIE_IP_AO_CRG, HKADC_CLK_EN, val);

	val = iodie_readl(IODIE_IP_AO_CRG, HKADC_RESET_DIS);
	val &= ~BIT(11);
	iodie_writel(IODIE_IP_AO_CRG, HKADC_RESET_DIS, val);

	val = iodie_readl(IODIE_IP_ADC, HKADC_EN);
	val &= ~BIT(0);
	iodie_writel(IODIE_IP_ADC, HKADC_EN, val);
}

static void iodie_hkadc_enable(void)
{
	u32 para_0;
	u32 para_1;
	u32 val;

	// clk enable, reset disable
	val = iodie_readl(IODIE_IP_AO_CRG, HKADC_CLK_EN);
	val |= BIT(24);
	iodie_writel(IODIE_IP_AO_CRG, HKADC_CLK_EN, val);

	val = iodie_readl(IODIE_IP_AO_CRG, HKADC_RESET_DIS);
	val |= BIT(11);
	iodie_writel(IODIE_IP_AO_CRG, HKADC_RESET_DIS, val);

	// vsensor init
	val = iodie_readl(IODIE_IP_ADC, HKADC_CHANNEL_EN);
	val |= BIT(0);
	iodie_writel(IODIE_IP_ADC, HKADC_CHANNEL_EN, val);

	val = iodie_readl(IODIE_IP_ADC, HKADC_CHANNEL_SEL);
	val &= ~0xF;
	iodie_writel(IODIE_IP_ADC, HKADC_CHANNEL_SEL, val);

	val = iodie_readl(IODIE_IP_ADC, HKADC_BGR_TOP_EN);
	val |= BIT(0);
	iodie_writel(IODIE_IP_ADC, HKADC_BGR_TOP_EN, val);

	val = iodie_readl(IODIE_IP_ADC, HKADC_EN);
	val |= BIT(0);
	iodie_writel(IODIE_IP_ADC, HKADC_EN, val);

	udelay(100);

	val = iodie_readl(IODIE_IP_ADC, HKADC_RESET);
	val &= ~BIT(0);
	iodie_writel(IODIE_IP_ADC, HKADC_RESET, val);

	g_actrl_base = ioremap(SOC_ACPU_ACTRL_BASE_ADDR, ACTRL_SIZE);
	if (!g_actrl_base) {
		pr_err("iodie_adc ioremap failed\n");
		return;
	}
	para_0 = readl(g_actrl_base + HKADC_PARA0_ADDR);
	para_1 = readl(g_actrl_base + HKADC_PARA1_ADDR);
	g_adc_para_k = (para_0 >> HKADC_PARA_K_SHIFT) & HKADC_PARA_K_SIZE;
	g_adc_para_b = ((para_0 >> HKADC_PARA_B1_SHIFT) & HKADC_PARA_B1_SIZE) | (para_1 & HKADC_PARA_B2_SIZE);

	iounmap(g_actrl_base);
	pr_info("iodie Adc para_0:%d, para_1:%d,para_k :%d, para_b : %d\n", para_0, para_1, g_adc_para_k, g_adc_para_b);
}

static int iodie_adc_to_volt(int adc)
{
	int volt;

	if (adc < 0)
		return ADC_RESULT_ERR;
	volt = adc * HKADC_VREF / HKADC_ACCURACY;
	return volt;
}

int iodie_adc_get_volt(int adc_channel)
{
	int ret;
	int volt;

	mutex_lock(&hiphyio_mutex);
	iodie_hkadc_enable();

	ret = iodie_hkadc_get_value(adc_channel);
	if (ret < 0) {
		iodie_hkadc_disable();
		mutex_unlock(&hiphyio_mutex);
		return ret;
	}

	iodie_hkadc_disable();
	mutex_unlock(&hiphyio_mutex);

	volt = iodie_adc_to_volt(ret);

	return volt;
}
EXPORT_SYMBOL(iodie_adc_get_volt);

static int iodie_adc_data_remap(int adcin_value)
{
	u32 i;

	for (i = 0; i < ARRAY_SIZE(hkadc_maps); i++) {
		if ((adcin_value >= hkadc_maps[i].start) && (adcin_value <= hkadc_maps[i].end))
			return hkadc_maps[i].val;
	}

	return IODIE_BOARDID_UNKNOWN;
}

int get_iodie_hkadc_boardid(int hk_num, int hk_ios[], int *boarid)
{
	int i;
	int hkadc_boardid = 0;
	int adc_val;
	int id;

	if (hk_num <= 0 || hk_num >= HKADC_CHANNEL_MAX) {
		pr_err("Invalid hkadc num\n");
		return -1;
	}

	for (i = 0; i < hk_num; i++) {
		adc_val = iodie_adc_get_volt(hk_ios[i]);
		id = iodie_adc_data_remap(adc_val);
		if (id == IODIE_BOARDID_UNKNOWN) {
			pr_err("get boardid from hkadc [%d] failed\n", hk_ios[i]);
			return -1;
		}
	hkadc_boardid = hkadc_boardid * 10 + id;
	}

	*boarid = hkadc_boardid;
	return 0;
}
EXPORT_SYMBOL(get_iodie_hkadc_boardid);

/* debugfs for adc */
#ifdef CONFIG_IODIE_HKADC_DEBUG
static int g_intr_flag;
static void iodie_adc_data_abort_handler(void *data)
{
	u32 val;
 
	// close interrupt
	val = iodie_readl(IODIE_IP_ADC, HKADC_DATA_ABORT_INTR);
	val |= BIT(1);
	iodie_writel(IODIE_IP_ADC, HKADC_DATA_ABORT_INTR, val);
 
	// clear interrupt
	val = iodie_readl(IODIE_IP_ADC, HKADC_DATA_ABORT_INTR);
	val |= BIT(2);
	iodie_writel(IODIE_IP_ADC, HKADC_DATA_ABORT_INTR, val);
	
	val = iodie_readl(IODIE_IP_ADC, HKADC_DATA_ABORT_INTR);
	val &= ~BIT(2);
	iodie_writel(IODIE_IP_ADC, HKADC_DATA_ABORT_INTR, val);
 
	pr_err("recv iodie adc data abort intr\n");
}

static void iodie_adc_abort(u32 thershold)
{
	u32 val;

	mutex_lock(&hiphyio_mutex);
	iodie_hkadc_enable();

	iodie_intr_hub_irq_register(INTR_HUB_L2_ID_8, IODIE_HKADC_ABORT_MASK, iodie_adc_data_abort_handler, NULL);

	iodie_writel(IODIE_IP_ADC, HKADC_DATA_THRESHOLD_ADDR, thershold);

	val = iodie_readl(IODIE_IP_ADC, HKADC_DATA_ABORT_INTR);
	val &= ~BIT(1);
	iodie_writel(IODIE_IP_ADC, HKADC_DATA_ABORT_INTR, val);

	iodie_hkadc_get_value(0);

	iodie_hkadc_disable();
	mutex_unlock(&hiphyio_mutex);
}

static int iodie_adc_debugfs_show(struct seq_file *s, void *data __maybe_unused)
{
	seq_printf(s, "ch-%d: iodie_adc = %d, volt = %dmv\n",
		   g_iodie_buff[0], g_iodie_buff[1], g_iodie_buff[2]);
	return 0;
}

static int iodie_adc_debugfs_open(struct inode *inode __maybe_unused, struct file *file)
{
	return single_open(file, iodie_adc_debugfs_show, NULL);
}

static int iodie_adc_abort_debugfs_show(struct seq_file *s, void *data __maybe_unused)
{
	seq_printf(s, "threshold:%x\n", g_iodie_abort_threshold);
	return 0;
}

static int iodie_adc_abort_debugfs_open(struct inode *inode __maybe_unused, struct file *file)
{
	return single_open(file, iodie_adc_abort_debugfs_show, NULL);
}

static ssize_t iodie_adc_abort_debugfs_write(struct file *file __maybe_unused,
				 const char __user *user_buf,
				 size_t count,
				 loff_t *ppos __maybe_unused)
{
	char buf[64];
	int ret;
	long val = 0;

	ret = memset_s(buf, sizeof(buf), 0, sizeof(buf));
	if (ret != 0) {
		pr_err("%s:wrong_buf!\n", __func__);
		return -ENODEV;
	}

	if (user_buf == NULL) {
		pr_err("%s:user_buf is NULL!\n", __func__);
		return -EFAULT;
	}
	if (copy_from_user(buf, user_buf,
			   min_t(size_t, sizeof(buf) - 1, count))) {
		pr_err("[%s]copy error!\n", __func__);
		return -EFAULT;
	}

	ret = kstrtol(buf, 16, &val);
	if (ret < 0) {
		pr_err("%s: input error!\n", MODULE_NAME);
		return count;
	}

	g_iodie_abort_threshold = (u32)val;
	iodie_adc_abort(g_iodie_abort_threshold);
	pr_err("adc threshold: %x\n", g_iodie_abort_threshold);
	return count;
}

static ssize_t iodie_adc_debugfs_write(struct file *file __maybe_unused,
				 const char __user *user_buf,
				 size_t count,
				 loff_t *ppos __maybe_unused)
{
	char buf[64];
	int ret;
	long val = 0;

	ret = memset_s(buf, sizeof(buf), 0, sizeof(buf));
	if (ret != 0) {
		pr_err("%s:wrong_buf!\n", __func__);
		return -ENODEV;
	}

	if (user_buf == NULL) {
		pr_err("%s:user_buf is NULL!\n", __func__);
		return -EFAULT;
	}
	if (copy_from_user(buf, user_buf,
			   min_t(size_t, sizeof(buf) - 1, count))) {
		pr_err("[%s]copy error!\n", __func__);
		return -EFAULT;
	}

	ret = kstrtol(buf, 10, &val);
	if (ret < 0) {
		pr_err("%s: input error!\n", MODULE_NAME);
		return count;
	}

	mutex_lock(&hiphyio_mutex);
	iodie_hkadc_enable();

	g_iodie_buff[0] = (int)val;
	g_iodie_buff[1] = iodie_hkadc_get_value(g_iodie_buff[0]);
	g_iodie_buff[2] = iodie_adc_to_volt(g_iodie_buff[1]);

	iodie_hkadc_disable();
	mutex_unlock(&hiphyio_mutex);
	pr_info("%s: channel[%d] adc is %d\n, volt is %dmv\n",
		MODULE_NAME, g_iodie_buff[0], g_iodie_buff[1], g_iodie_buff[2]);
	return count;
}

static const struct file_operations iodie_adc_operations = {
	.open = iodie_adc_debugfs_open,
	.read = seq_read,
	.write = iodie_adc_debugfs_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations iodie_adc_abort_operations = {
	.open = iodie_adc_abort_debugfs_open,
	.read = seq_read,
	.write = iodie_adc_abort_debugfs_write,
	.llseek = seq_lseek,
	.release = single_release,
};

void iodie_adc_remove_device_debugfs(void)
{
	debugfs_remove_recursive(g_iodie_debugfs_root);
}
#else

void iodie_adc_remove_device_debugfs(void)
{
}
#endif

static int __init iodie_hkadc_init(void)
{
#ifdef CONFIG_IODIE_HKADC_DEBUG
	g_iodie_debugfs_root = debugfs_create_dir(MODULE_NAME, NULL);
	if (IS_ERR(g_iodie_debugfs_root) || g_iodie_debugfs_root == NULL) {
		pr_err("%s:failed to create debugfs directory!\n", MODULE_NAME);
		return -1;
	}

	debugfs_create_file("channel", S_IFREG | S_IRUGO,
			    g_iodie_debugfs_root, NULL, &iodie_adc_operations);
	debugfs_create_file("abort_threshold", S_IFREG | S_IRUGO,
			    g_iodie_debugfs_root, NULL, &iodie_adc_abort_operations);
#endif
	return 0;
}

static void __exit iodie_hkadc_exit(void)
{
	iodie_adc_remove_device_debugfs();
}

subsys_initcall(iodie_hkadc_init);
module_exit(iodie_hkadc_exit);
