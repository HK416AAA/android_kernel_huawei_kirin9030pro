/*
 * Copyright (c) 2019-2019, Hisilicon Tech. Co., Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "mdfx_utils.h"
#include <linux/platform_device.h>
#include <linux/of_device.h>
#include <linux/ktime.h>
#include "mdfx_priv.h"

// level manager
int32_t g_mdfx_log_level = -1;
uint32_t g_mdfx_caps = 0;

#ifdef CONFIG_MDFX_KMD_ENG_MODE
module_param_named(mdfx_log_level, g_mdfx_log_level, int, 0640);
MODULE_PARM_DESC(mdfx_log_level, "mdfx log level, -1:disable log, 0~4 print level, see mdfx_kmsg_level");

module_param_named(mdfx_caps, g_mdfx_caps, uint, 0640);
MODULE_PARM_DESC(mdfx_caps, "mdfx capability, bit0:logger, bit1:dumper, bit2:saver, bit3:tracing, bit4:event");
#endif

void mdfx_get_rtc_time(struct mdfx_time *dt)
{
	if (IS_ERR_OR_NULL(dt))
		return;

	ktime_get_real_ts64(&dt->tv);
	dt->tv.tv_sec -= (long)sys_tz.tz_minuteswest * 60;
	rtc_time64_to_tm(dt->tv.tv_sec, &dt->tm_rtc);
}

static void mdfx_get_file_specify(struct device_node *np, struct mdfx_pri_data *priv_data)
{
	uint32_t file_size = 0;
	uint32_t file_nums = 0;
	int ret;

#ifdef CONFIG_MDFX_KMD_ENG_MODE
	ret = of_property_read_u32(np, "file_max_size", &file_size);
	log_and_return_if(ret, "failed to get file_max_size resource\n");

	ret = of_property_read_u32(np, "file_max_num", &file_nums);
	log_and_return_if(ret, "failed to get file_max_num resource\n");
#else
	ret = of_property_read_u32(np, "user_file_max_size", &file_size);
	log_and_return_if(ret, "failed to get user_file_max_size resource\n");

	ret = of_property_read_u32(np, "user_file_max_num", &file_nums);
	log_and_return_if(ret, "failed to get user_file_max_num resource\n");
#endif
	mdfx_pr_info("file_max_size=%u\n", file_size);
	mdfx_pr_info("file_max_num=%u\n", file_nums);

	priv_data->file_spec.file_max_size = file_size;
	priv_data->file_spec.file_max_num = file_nums;
	priv_data->var_log_file_count = file_nums;
}

int mdfx_read_dtsi(struct mdfx_pri_data *priv_data)
{
	struct device_node *np = NULL;
	int ret;

	g_mdfx_caps = 0;
	g_mdfx_log_level = -1;

	// get file spec from dtsi
	np = of_find_compatible_node(NULL, NULL, DTS_COMP_DFX_NAME);
	if (IS_ERR_OR_NULL(np)) {
		mdfx_pr_warn("NOT FOUND device node %s!\n", DTS_COMP_DFX_NAME);
		return -ENXIO;
	}

	mdfx_get_file_specify(np, priv_data);

	// read mdfx capability from dtsi
	ret = of_property_read_u32(np, "mdfx_caps", &priv_data->mdfx_caps);
	if (ret != 0) {
		mdfx_pr_warn("failed to get mdfx_caps resource\n");
		return ret;
	}

	mdfx_pr_info("dtsi mdfx_caps=0x%x", priv_data->mdfx_caps);

#ifdef CONFIG_MDFX_KMD_ENG_MODE
	g_mdfx_caps = priv_data->mdfx_caps;
	if (MDFX_HAS_CAPABILITY(g_mdfx_caps, MDFX_CAP_LOGGER))
		g_mdfx_log_level = MDFX_LOG_LEVEL_NOTICE;
#endif

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_CMDLIST_NAME);
	if (IS_ERR_OR_NULL(np)) {
		mdfx_pr_warn("NOT FOUND device node %s!\n", DTS_COMP_CMDLIST_NAME);
		return -ENXIO;
	}

	ret = of_property_read_u32(np, "use_kernel_mode", &priv_data->cmdlist_kernel_mode);
	if (ret != 0) {
		mdfx_pr_warn("failed to get cmdlist_kernel_mode\n");
		return ret;
	}

	mdfx_pr_info("dtsi cmdlist_kernel_mode=%u", priv_data->cmdlist_kernel_mode);
	return 0;
}

void mdfx_sysfs_init(struct mdfx_pri_data *mdfx_data)
{
	uint32_t i;

	mdfx_data->attrs_count = 0;
	for (i = 0; i < MDFX_MAX_ATTRS_NUM; i++)
		mdfx_data->sysfs_attrs[i] = NULL;

	mdfx_data->attr_group.attrs = mdfx_data->sysfs_attrs;
}

void mdfx_sysfs_append_attrs(struct mdfx_pri_data *mdfx_data, struct attribute *attr)
{
	if (mdfx_data->attrs_count >= MDFX_MAX_ATTRS_NUM) {
		mdfx_pr_err("attrs_count is over %d", MDFX_MAX_ATTRS_NUM);
		return;
	}

	mdfx_data->sysfs_attrs[mdfx_data->attrs_count] = attr;
	mdfx_data->attrs_count++;
}

void mdfx_sysfs_create_attrs(struct platform_device *pdev)
{
	struct mdfx_device_data *device_data = NULL;
	int ret;

	device_data = platform_get_drvdata(pdev);
	if (IS_ERR_OR_NULL(device_data))
		return;

	ret = sysfs_create_group(&device_data->dfx_cdevice->kobj, &(device_data->data.attr_group));
	if (ret) {
		mdfx_pr_err("create sysfs attrs fail");
		return;
	}

	mdfx_pr_info("create attrs succes");
}

void mdfx_sysfs_remove_attrs(struct platform_device *pdev)
{
	struct mdfx_device_data *device_data = NULL;

	device_data = platform_get_drvdata(pdev);
	if (IS_ERR_OR_NULL(device_data))
		return;

	sysfs_remove_group(&device_data->dfx_cdevice->kobj, &(device_data->data.attr_group));
	mdfx_sysfs_init(&device_data->data);
}

uint32_t mdfx_get_bits(uint64_t value)
{
	uint32_t count = 0;

	for (count = 0; value > 0; count++)
		value &= value - 1;

	return count;
}

int mdfx_get_msg_header(char *buf, uint32_t buf_max_len)
{
	struct mdfx_time dt = {0};
	uint64_t ts;
	unsigned long ts_nsec;

	mdfx_get_rtc_time(&dt);

#ifdef CONFIG_DFX_TIME
	ts = dfx_getcurtime();
#else
	ts = local_clock();
#endif
	ts_nsec = do_div(ts, NSEC_PER_SEC);

	return scnprintf(buf, buf_max_len, "%.2d-%.2d %.2d:%.2d:%.2d.%03lu [%5lu.%06lu][pid:%d,cpu%d,%s]",
					dt.tm_rtc.tm_mon + 1, dt.tm_rtc.tm_mday, dt.tm_rtc.tm_hour,
					dt.tm_rtc.tm_min, dt.tm_rtc.tm_sec, dt.tv.tv_nsec / 1000000, (unsigned long)ts, ts_nsec / 1000, 
					current->pid, smp_processor_id(), in_irq() ? "in_irq" : current->comm);
}

int mdfx_get_file_name_timestamp(char *buf, uint32_t buf_max_len)
{
	struct mdfx_time dt = {0};

	mdfx_get_rtc_time(&dt);
	return scnprintf(buf, buf_max_len, "%.4d%.2d%.2d_%.2d%.2d%.2d.%03ld", 
					dt.tm_rtc.tm_year + 1900, dt.tm_rtc.tm_mon + 1, dt.tm_rtc.tm_mday, dt.tm_rtc.tm_hour,
					dt.tm_rtc.tm_min, dt.tm_rtc.tm_sec, dt.tv.tv_nsec / 1000000);
}