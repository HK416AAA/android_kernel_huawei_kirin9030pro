/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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

#include <linux/types.h>
#include <linux/string.h>
#include <linux/cpufreq.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/io.h>
#include <linux/of_device.h>
#include <linux/i2c.h>
#include <linux/device.h>
#include <platform_include/display/dkmd/dkmd_nonmcu_blpwm.h>
#include "dkmd_log.h"

static char __iomem *get_base_io_addr(unsigned int base_addr)
{
	unsigned int i = 0;
	char __iomem *base_io_addr = NULL;
	if (blpwm_ioremap_info.current_size > (unsigned int)IOREMAP_LIST_SIZE) {
		dpu_pr_err("inval size: %d", blpwm_ioremap_info.current_size);
		return NULL;
	}
	for (i = 0; i < blpwm_ioremap_info.current_size; i++) {
		if (base_addr == blpwm_ioremap_info.ioremap_list[i].base_addr) {
			return blpwm_ioremap_info.ioremap_list[i].base_io_addr;
		}
	}
	base_io_addr = ioremap(base_addr, BLPWM_ADDR_SIZE);
	if (base_io_addr == NULL) {
		dpu_pr_err("ioremap failed");
		return NULL;
	}
	if (blpwm_ioremap_info.ioremap_list[blpwm_ioremap_info.next_index].base_io_addr != NULL) {
		dpu_pr_info("iounmap index: %d", blpwm_ioremap_info.next_index);
		iounmap(blpwm_ioremap_info.ioremap_list[blpwm_ioremap_info.next_index].base_io_addr);
	}
	blpwm_ioremap_info.ioremap_list[blpwm_ioremap_info.next_index].base_addr = base_addr;
	blpwm_ioremap_info.ioremap_list[blpwm_ioremap_info.next_index].base_io_addr = base_io_addr;
	blpwm_ioremap_info.current_size++;
	if (blpwm_ioremap_info.current_size > (unsigned int)IOREMAP_LIST_SIZE)
		blpwm_ioremap_info.current_size = (unsigned int)IOREMAP_LIST_SIZE;
	dpu_pr_info("add ioremap_list index: %d, size: %d", blpwm_ioremap_info.next_index, blpwm_ioremap_info.current_size);
	blpwm_ioremap_info.next_index++;
	blpwm_ioremap_info.next_index = blpwm_ioremap_info.next_index % (unsigned int)IOREMAP_LIST_SIZE;
	return base_io_addr;
}

static int blpwm_write_u32(blpwm_reg_val_t *blpwm_reg_val, unsigned int data)
{
	char __iomem *base_io_addr = NULL;
	if (blpwm_reg_val == NULL) {
		dpu_pr_info("NULL parameter, data:%u", data);
		return -EINVAL;
	}
	base_io_addr = get_base_io_addr(blpwm_reg_val->base_addr);
	if (base_io_addr == NULL) {
		dpu_pr_err("ioremap addr %#x get failed", blpwm_reg_val->base_addr);
		return -EINVAL;
	}
	writel(data, base_io_addr + blpwm_reg_val->offset_addr);
	dpu_pr_info("writel offset_addr: %#x, data: %#x", blpwm_reg_val->offset_addr, data);
	return 0;
}

static int blpwm_read_u32(blpwm_reg_val_t *blpwm_reg_val, unsigned int *data)
{
	char __iomem *base_io_addr = NULL;
	if (blpwm_reg_val == NULL || data == NULL) {
		dpu_pr_info("NULL parameter");
		return -EINVAL;
	}
	base_io_addr = get_base_io_addr(blpwm_reg_val->base_addr);
	if (base_io_addr == NULL) {
		dpu_pr_err("ioremap addr %#x get failed", blpwm_reg_val->base_addr);
		return -EINVAL;
	}
	*data = readl(base_io_addr + blpwm_reg_val->offset_addr);
	dpu_pr_info("readl offset_addr: %#x, data: %#x", blpwm_reg_val->offset_addr, *data);
	return 0;
}

static int blpwm_operate_u32(blpwm_reg_val_t *blpwm_reg_val, bool set_reg, unsigned int reg_value)
{
	int ret = 0;
	if (blpwm_reg_val == NULL) {
		dpu_pr_err("blpwm_reg_val is NULL");
		return -EINVAL;
	}
	if (blpwm_reg_val->operation == BLPWM_READ) {
		ret = blpwm_read_u32(blpwm_reg_val, &blpwm_reg_val->data);
	} else if (blpwm_reg_val->operation == BLPWM_WRITE) {
		if (set_reg == true)
			blpwm_reg_val->data = reg_value;
		ret = blpwm_write_u32(blpwm_reg_val, blpwm_reg_val->data);
	} else {
		dpu_pr_err("invalid operation: %d", blpwm_reg_val->operation);
		return -EINVAL;
	}

	return ret;
}

static int blpwm_operate_list(blpwm_reg_val_t *reg_val_list, unsigned long list_size,
	bool set_reg, unsigned int reg_value)
{
	int ret = 0;
	unsigned int i = 0;
	if (reg_val_list == NULL) {
		dpu_pr_err("reg_val_list is NULL");
		return -EINVAL;
	}
	for (i = 0; i < (unsigned int)list_size; i++) {
		ret = blpwm_operate_u32(&reg_val_list[i], set_reg, reg_value);
		if (ret != 0) {
			dpu_pr_err("blpwm_operate_u32 addr: %#x failed, list_size %d",
				reg_val_list[i].base_addr, (unsigned int)list_size);
			return ret;
		}
	}

	return ret;
}

blpwm_operate_config_t* dkmd_get_blpwm_config(int blpwm_type)
{
	unsigned int i = 0;
	unsigned long list_size = 0;
	static blpwm_operate_config_t *config_list = NULL;
	list_size = ARRAY_SIZE(blpwm_operate_config_list);
	config_list = blpwm_operate_config_list;
	if (config_list == NULL) {
		dpu_pr_err("config_list is NULL");
		return NULL;
	}
	for (i = 0; i < (unsigned int)list_size; i++) {
		if (config_list[i].blpwm_type == blpwm_type)
			return &config_list[i];
	}

	return NULL;
}

int dkmd_blpwm_init(blpwm_operate_config_t* blpwm_operate_config)
{
	int ret = 0;
	if ((blpwm_operate_config == NULL) || (blpwm_operate_config->blpwm_init_config == NULL)) {
		dpu_pr_err("NULL parameter");
		return -EINVAL;
	}
	ret = blpwm_operate_list(blpwm_operate_config->blpwm_init_config,
		blpwm_operate_config->blpwm_init_config_size, false, 0);
	if (ret != 0) {
		dpu_pr_err("dkmd_blpwm_init failed");
		return ret;
	}

	return ret;
}

int dkmd_blpwm_enable(blpwm_operate_config_t* blpwm_operate_config)
{
	int ret = 0;
	if ((blpwm_operate_config == NULL) || (blpwm_operate_config->blpwm_enable_config == NULL)) {
		dpu_pr_err("NULL parameter");
		return -EINVAL;
	}
	ret = blpwm_operate_list(blpwm_operate_config->blpwm_enable_config,
		blpwm_operate_config->blpwm_enable_config_size, false, 0);
	if (ret != 0) {
		dpu_pr_err("dkmd_blpwm_enable failed");
		return ret;
	}

	return ret;
}

int dkmd_blpwm_disable(blpwm_operate_config_t* blpwm_operate_config)
{
	int ret = 0;
	if ((blpwm_operate_config == NULL) || (blpwm_operate_config->blpwm_disable_config == NULL)) {
		dpu_pr_err("NULL parameter");
		return -EINVAL;
	}
	ret = blpwm_operate_list(blpwm_operate_config->blpwm_disable_config,
		blpwm_operate_config->blpwm_disable_config_size, false, 0);
	if (ret != 0) {
		dpu_pr_err("dkmd_blpwm_disable failed");
		return ret;
	}

	return ret;
}

static int blpwm_frequency(blpwm_operate_config_t* blpwm_operate_config, unsigned int reg_data)
{
	int ret = 0;
	if ((blpwm_operate_config == NULL) || (blpwm_operate_config->blpwm_frequency_config == NULL)) {
		dpu_pr_err("NULL parameter");
		return -EINVAL;
	}
	ret = blpwm_operate_list(blpwm_operate_config->blpwm_frequency_config,
		blpwm_operate_config->blpwm_frequency_config_size, true, reg_data);
	if (ret != 0) {
		dpu_pr_err("blpwm_frequency failed");
		return ret;
	}

	return ret;
}

int dkmd_blpwm_set_frequency(blpwm_operate_config_t* blpwm_operate_config, unsigned int reg_data)
{
	int ret = 0;
	if ((blpwm_operate_config == NULL) || (blpwm_operate_config->blpwm_frequency_config == NULL)) {
		dpu_pr_err("NULL parameter");
		return -EINVAL;
	}
	ret = blpwm_write_u32(&blpwm_operate_config->blpwm_frequency_config[BLPWM_SET_INDEX], reg_data);
	if (ret != 0) {
		dpu_pr_err("blpwm_write_u32 failed");
		return ret;
	}

	return ret;
}

int dkmd_blpwm_get_frequency(blpwm_operate_config_t* blpwm_operate_config, unsigned int *reg_data)
{
	int ret = 0;
	if ((blpwm_operate_config == NULL) || (blpwm_operate_config->blpwm_frequency_config == NULL)) {
		dpu_pr_err("NULL parameter");
		return -EINVAL;
	}
	ret = blpwm_read_u32(&blpwm_operate_config->blpwm_frequency_config[BLPWM_GET_INDEX], reg_data);
	if (ret != 0) {
		dpu_pr_err("blpwm_read_u32 failed");
		return ret;
	}

	return ret;
}

static int blpwm_cycle(blpwm_operate_config_t* blpwm_operate_config, unsigned int reg_data)
{
	int ret = 0;
	if ((blpwm_operate_config == NULL) || (blpwm_operate_config->blpwm_cycle_config == NULL)) {
		dpu_pr_err("NULL parameter");
		return -EINVAL;
	}
	ret = blpwm_operate_list(blpwm_operate_config->blpwm_cycle_config,
		blpwm_operate_config->blpwm_cycle_config_size, true, reg_data);
	if (ret != 0) {
		dpu_pr_err("blpwm_cycle failed");
		return ret;
	}

	return ret;
}

int dkmd_blpwm_set_cycle(blpwm_operate_config_t* blpwm_operate_config, unsigned int reg_data)
{
	int ret = 0;
	if ((blpwm_operate_config == NULL) || (blpwm_operate_config->blpwm_cycle_config == NULL)) {
		dpu_pr_err("NULL parameter");
		return -EINVAL;
	}
	ret = blpwm_write_u32(&blpwm_operate_config->blpwm_cycle_config[BLPWM_SET_INDEX], reg_data);
	if (ret != 0) {
		dpu_pr_err("blpwm_write_u32 failed");
		return ret;
	}

	return ret;
}

int dkmd_blpwm_get_cycle(blpwm_operate_config_t* blpwm_operate_config, unsigned int *reg_data)
{
	int ret = 0;
	if ((blpwm_operate_config == NULL) || (blpwm_operate_config->blpwm_cycle_config == NULL)) {
		dpu_pr_err("NULL parameter");
		return -EINVAL;
	}
	ret = blpwm_read_u32(&blpwm_operate_config->blpwm_cycle_config[BLPWM_GET_INDEX], reg_data);
	if (ret != 0) {
		dpu_pr_err("blpwm_read_u32 failed");
		return ret;
	}

	return ret;
}

int dkmd_display_blpwm_custom_settings(int pwm_type, bool pwm_gen, unsigned int frequency_val, unsigned int cycle_val)
{
	int ret = 0;
	blpwm_operate_config_t* blpwm_operate_config = NULL;
	blpwm_operate_config = dkmd_get_blpwm_config(pwm_type);
	if (blpwm_operate_config == NULL) {
		dpu_pr_err("unsupported blpwm_type: %d", pwm_type);
		return -EINVAL;
	}
	ret |= dkmd_blpwm_init(blpwm_operate_config);
	if (ret != 0) {
		dpu_pr_err("dkmd_blpwm_init failed, pwm_type: %d, ret: %d", pwm_type, ret);
		return -EINVAL;
	}
	if (pwm_gen) {
		ret |= dkmd_blpwm_enable(blpwm_operate_config);
		ret |= blpwm_frequency(blpwm_operate_config, frequency_val);
		ret |= blpwm_cycle(blpwm_operate_config, cycle_val);
	} else {
		ret |= dkmd_blpwm_disable(blpwm_operate_config);
	}
	if (ret != 0) {
		dpu_pr_err("set_pwm failed, pwm_type: %d, ret: %d", pwm_type, ret);
		return ret;
	}

	return ret;
}