/*
 * haptic_regmap.c
 *
 * vibrator reg operation.
 *
 * Copyright (c) 2023 Huawei Technologies Co., Ltd.
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

#include <linux/regmap.h>

#include "vib_log.h"

int __maybe_unused haptic_regmap_read(struct regmap *regmap, unsigned int reg,
				      char *buf)
{
	unsigned int val = 0;
	int ret;

	if (!regmap || !buf) {
		vib_err("invalid regmap para");
		return -EINVAL;
	}

	ret = regmap_read(regmap, reg, &val);
	if (ret == 0)
		*buf = (char)val;
	else
		vib_err("regmap_read fail:%d", ret);

	return ret;
}

int __maybe_unused haptic_regmap_write(struct regmap *regmap, unsigned int reg,
				       char value)
{
	int ret;

	if (!regmap) {
		vib_err("invalid regmap para");
		return -EINVAL;
	}

	ret = regmap_write(regmap, reg, value);
	if (ret)
		vib_err("regmap_write fail:%d", ret);
	return ret;
}

int __maybe_unused haptic_regmap_reads(struct regmap *regmap,
				       unsigned int start_reg,
				       unsigned int reg_num, char *buf)
{
	int ret;

	if (!regmap || !buf) {
		vib_err("invalid regmap para");
		return -EINVAL;
	}

	ret = regmap_raw_read(regmap, start_reg, buf, reg_num);
	if (ret)
		vib_err("regmap_raw_read fail:%d", ret);
	return ret;
}

int __maybe_unused haptic_regmap_writes(struct regmap *regmap,
					unsigned int start_reg,
					unsigned int reg_num, const char *buf)
{
	int ret;

	if (!regmap || !buf) {
		vib_err("invalid regmap para");
		return -EINVAL;
	}

	ret = regmap_raw_write(regmap, start_reg, buf, reg_num);
	if (ret)
		vib_err("regmap_raw_write fail:%d", ret);
	return ret;
}

int haptic_regmap_bulk_write(struct regmap *regmap, unsigned int start_reg,
			     unsigned int reg_num, const char *buf)
{
	int ret;

	if (!regmap || !buf) {
		vib_err("invalid regmap para");
		return -EINVAL;
	}

	ret = regmap_bulk_write(regmap, start_reg, buf, reg_num);
	if (ret)
		vib_err("regmap_bulk_write fail:%d", ret);
	return ret;
}

int haptic_regmap_bulk_read(struct regmap *regmap, unsigned int start_reg,
			    unsigned int reg_num, char *buf)
{
	int ret;

	if (!regmap || !buf) {
		vib_err("invalid regmap para");
		return -EINVAL;
	}

	ret = regmap_bulk_read(regmap, start_reg, buf, reg_num);
	if (ret)
		vib_err("regmap_bulk_read fail:%d", ret);
	return ret;
}

int haptic_regmap_update_bits(struct regmap *regmap, unsigned int reg,
			      unsigned int mask, unsigned int val)
{
	int ret;

	if (!regmap) {
		vib_err("invalid regmap para");
		return -EINVAL;
	}

	// TODO revert mask
	ret = regmap_update_bits(regmap, reg, ~mask, val);
	if (ret)
		vib_err("regmap_update_bits fail:%d", ret);
	return ret;
}

struct regmap *haptic_regmap_init(struct i2c_client *client,
				  const struct regmap_config *config)
{
	if (!client || !config) {
		vib_err("invalid client or config");
		return NULL;
	}

	return devm_regmap_init_i2c(client, config);
}

void haptic_regmap_remove(struct regmap *regmap)
{
	if (!IS_ERR(regmap))
		regmap_exit(regmap);
}
