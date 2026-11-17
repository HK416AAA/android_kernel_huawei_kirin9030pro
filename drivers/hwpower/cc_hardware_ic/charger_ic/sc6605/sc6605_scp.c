// SPDX-License-Identifier: GPL-2.0+
/*
 * sc6605_scp.c
 *
 * sc6605 scp driver
 *
 * Copyright (c) 2024-2025 Huawei Technologies Co., Ltd.
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

#include "sc6605_scp.h"
#include <huawei_platform/log/hw_log.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_scp.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_fcp.h>
#include <chipset_common/hwpower/common_module/power_delay.h>

#define HWLOG_TAG sc6605_scp
HWLOG_REGIST();

static int sc6605_scp_field_read(struct sc6605_scp_dev *di, enum sc6605_scp_fields field_id)
{
	int ret;
	uint8_t reg_val = 0;
	uint8_t mask = GENMASK(sc6605_scp_reg_fields[field_id].msb, sc6605_scp_reg_fields[field_id].lsb);

	ret = regmap_bulk_read(di->rmap, sc6605_scp_reg_fields[field_id].reg, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] sc6605 scp read failed %d fail: %d\n", __func__, field_id, ret);
		return ret;
	}

	reg_val &= mask;
	reg_val >>= sc6605_scp_reg_fields[field_id].lsb;

	return reg_val;
}

static int sc6605_scp_field_write(struct sc6605_scp_dev *di, enum sc6605_scp_fields field_id,
	uint8_t val)
{
	int ret;
	uint8_t reg_val = 0, tmp = 0;
	uint8_t mask = GENMASK(sc6605_scp_reg_fields[field_id].msb, sc6605_scp_reg_fields[field_id].lsb);

	ret = regmap_bulk_read(di->rmap, sc6605_scp_reg_fields[field_id].reg, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] read field %d fail: %d\n", __func__, field_id, ret);
		return ret;
	}

	tmp = reg_val & ~mask;
	val <<= sc6605_scp_reg_fields[field_id].lsb;
	tmp |= val  & mask;

	if (tmp != reg_val) {
		ret = regmap_bulk_write(di->rmap, sc6605_scp_reg_fields[field_id].reg, &tmp, REG_COUNT1);
		if (ret) {
			hwlog_err("[%s] write field %d fail: %d\n", __func__, field_id, ret);
			return ret;
		}
	}

	return 0;
}

static int sc6605_scp_trans(struct sc6605_scp_dev *di, uint8_t *val, uint8_t len)
{
	int ret;
	int reg_val;
	int i;
	uint8_t reg;

	/* clear INT flag */
	ret = regmap_bulk_read(di->rmap, SC6605_REG_SCP_FLAG_MASK, &reg, REG_COUNT1);
	/* clear tx fifo */
	ret |= sc6605_scp_field_write(di, F_CLR_TX_FIFO, REG_COUNT1);
	ret |= sc6605_scp_field_write(di, F_CLR_RX_FIFO, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] clear INT and fifo failed\n", __func__);
		return ret;
	}

	for (i = 0; i < len; i++) {
		ret = regmap_bulk_write(di->rmap, SC6605_REG_SCP_WDATA, &val[i], REG_COUNT1);
		if (ret) {
			hwlog_err("[%s] write tx fifo failed %d\n", __func__, i);
			return ret;
		}
	}
	/* read cnt */
	reg_val = sc6605_scp_field_read(di, F_TX_FIFO_CNT);
	if (reg_val != len) {
		hwlog_err("[%s] read tx fifo failed\n", __func__);
		return -EINVAL;
	}
	reinit_completion(&di->complete);
	/* send cmd */
	ret = sc6605_scp_field_write(di, F_SND_TRANS, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] send cmd failed\n", __func__);
		return ret;
	}

	ret = wait_for_completion_timeout(&di->complete, msecs_to_jiffies(WAIT_SCP_TIMEOUT));
	if (ret < 0) {
		hwlog_err("[%s] read data timeout\n", __func__);
		return -EINVAL;
	}

	return 0;
}

static int sc6605_scp_recv(struct sc6605_scp_dev *di, uint8_t *ack, uint8_t *val)
{
	int ret, i;
	int len;
	uint8_t reg_val;

	/* read cnt */
	reg_val = sc6605_scp_field_read(di, F_RX_FIFO_CNT);

	len = reg_val;

	ret = regmap_bulk_read(di->rmap, SC6605_REG_SCP_RDATA, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] read scp rdata failed\n", __func__);
		return ret;
	}
	*ack = (uint8_t)reg_val;

	for (i = 0; i < len - REG_COUNT2; i++) {
		ret = regmap_bulk_read(di->rmap, SC6605_REG_SCP_RDATA, &reg_val, REG_COUNT1);
		if (ret) {
			hwlog_err("[%s] read scp rdata1 failed\n", __func__);
			return ret;
		}
		*(val + i) = reg_val;
	}

	return 0;
}

static int sc6605_scp_reset(struct sc6605_scp_dev *di)
{
	int ret;
	uint8_t reg_val = 0;

	/* send reset */
	ret = sc6605_scp_field_write(di, F_SND_RST_TRANS, 1);
	if (ret) {
		hwlog_err("[%s] send reset failed\n", __func__);
		return ret;
	}

	power_msleep(DT_MSLEEP_200MS, 0, NULL);
	/* close f_scp_en */
	ret = sc6605_scp_field_write(di, F_SCP_EN, false);
	ret |= sc6605_scp_field_write(di, F_DM_DRIVE, DPDM_HIZ);
	ret |= sc6605_scp_field_write(di, F_DP_DRIVE, DPDM_HIZ);
	ret |= sc6605_scp_field_write(di, F_DPDM_EN, false);
	ret |= regmap_bulk_read(di->rmap, SC6605_REG_DPDM_INT_MASK, &reg_val, REG_COUNT1);
	reg_val |= SC6605_DPDM_INT1;
	ret |= regmap_write(di->rmap, SC6605_REG_DPDM_INT_MASK, reg_val);
	if (ret)
		hwlog_err("[%s] scp reset failed\n", __func__);

	return ret;
}

static int sc6605_scp_send_data(struct sc6605_scp_dev *di, uint8_t *data, uint8_t len,
	uint8_t *recv_data)
{
	uint8_t ack;
	int ret, retry_cn;

	if (len > SCP_FIFO_NUM) {
		hwlog_err("[%s] fail, len more than %d\n", __func__, SCP_FIFO_NUM);
		return -EINVAL;
	}

	for (retry_cn = 0; retry_cn < SC6605_SCP_SEND_RETRY_MAX; retry_cn++) {
		ret = sc6605_scp_trans(di, data, len);
		if (ret) {
			hwlog_err("[%s] scp trans failed\n", __func__);
			continue;
		}

		if (!recv_data) {
			hwlog_err("[%s] write ops, not need recv\n", __func__);
			break;
		}

		ret = sc6605_scp_recv(di, &ack, recv_data);
		if (ret) {
			hwlog_err("[%s] scp recv data err %d\n", __func__, ack);
			continue;
		}
		if (ack != SCP_SEND_DATA_ACK)
			hwlog_err("[%s] times %d, scp trans done, but data err %d\n", __func__, retry_cn, ack);
		else
			break;
	}
	if (retry_cn >= SC6605_SCP_SEND_RETRY_MAX)
		return -EINVAL;

	return 0;
}

static int sc6605_scp_read_byte(struct sc6605_scp_dev *di, uint8_t reg, uint8_t *data)
{
	int ret;
	uint8_t val[2] = { 0 };

	val[0] = SCP_READ_REG1;
	val[1] = reg;
	ret = sc6605_scp_send_data(di, val, ARRAY_SIZE(val), data);
	if (ret) {
		hwlog_err("[%s] send data failed\n", __func__);
		return ret;
	}

	return 0;
}

static int sc6605_scp_write_byte(struct sc6605_scp_dev *di, uint8_t reg, uint8_t data)
{
	int ret;
	uint8_t val[3] = { 0 };

	val[0] = SCP_WRITE_REG1;
	val[1] = reg;
	val[2] = data;

	ret = sc6605_scp_send_data(di, val, ARRAY_SIZE(val), NULL);
	if (ret) {
		hwlog_err("[%s] send data failed\n", __func__);
		return ret;
	}

	return 0;
}

static int sc6605_scp_reg_multi_read(struct sc6605_scp_dev *di, uint8_t reg,
	uint8_t *data, uint8_t len)
{
	int ret;
	uint8_t val[3] = { 0 };

	val[0] = REG_MUITI_READ;
	val[1] = reg;
	val[2] = len;

	ret = sc6605_scp_send_data(di, val, ARRAY_SIZE(val), data);
	if (ret) {
		hwlog_err("[%s] send data failed\n", __func__);
		return ret;
	}

	return 0;
}

static int sc6605_scp_multi_reg_read_block(u8 reg, u8 *val, u8 num, void *dev_data)
{
	struct sc6605_scp_dev *di = dev_data;
	u8 *val_cpy = val;
	u8 data_len = (num < SCP_MULTI_REG) ? num : SCP_MULTI_REG;
	int ret = 0;

	if (!di || !val)
		return -ENODEV;

	ret = sc6605_scp_reg_multi_read(di, reg, val_cpy, data_len);
	if (ret) {
		hwlog_err("[%s] multi read 0x%x faild\n", __func__, reg);
		return ret;
	}

	num -= data_len;
	if (num) {
		val_cpy += data_len;
		reg += data_len;
		ret = sc6605_scp_reg_multi_read(di, reg, val_cpy, data_len);
		if (ret) {
			hwlog_err("[%s] multi read 0x%x faild\n", __func__, reg);
			return ret;
		}
	}

	return 0;
}

static int sc6605_fcp_reg_read_block(int reg, int *val, int num, void *dev_data)
{
	int i, ret;
	uint8_t data;
	struct sc6605_scp_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	for (i = 0; i < num; i++) {
		ret = sc6605_scp_read_byte(di, reg + i, &data);
		if (ret) {
			hwlog_err("[%s] scp read failed\n", __func__);
			return ret;
		}
		hwlog_info("[%s] read 0x%x = 0x%x, i = %d, ret = %d\n", __func__, reg + i, data, i, ret);
		val[i] = data;
	}

	return 0;
}

static int sc6605_fcp_reg_write_block(int reg, const int *val, int num, void *dev_data)
{
	int i, ret;
	struct sc6605_scp_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	for (i = 0; i < num; i++) {
		ret = sc6605_scp_write_byte(di, reg + i, val[i]);
		if (ret) {
			hwlog_err("[%s] scp write 0x%x failed\n", __func__, reg + i);
			return ret;
		}
		hwlog_info("[%s] write 0x%x = 0x%x, i = %d, ret = %d\n", __func__,
			reg + i, val[i], i, ret);
	}

	return 0;
}

static int sc6605_fcp_adapter_detct_dpdm_stat(struct sc6605_scp_dev *di)
{
	uint8_t dpdm_stat[2];
	int cnt, ret;
	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -EINVAL;
	}

	for (cnt = 0; cnt < SC6605_SCP_DETECT_MAX_CNT; cnt++) {
		ret = regmap_bulk_read(di->rmap, SC6605_REG_DP_STAT, dpdm_stat, REG_COUNT2);
		if (ret) {
			hwlog_err("[%s] read dpdm_stat_reg fail\n", __func__);
			continue;
		}
		hwlog_info("[%s]scp_dpdm_stat:0x%x 0x%x\n", __func__, dpdm_stat[0], dpdm_stat[1]);

		/* 0.325v < DP voltage < 1V, DM voltage < 0.325v */
		if (((dpdm_stat[0] & SCP_DPDM_IN_MASK) == SC6605_VDP_RD_325_1000) &&
			((dpdm_stat[1] & SCP_DPDM_IN_MASK) == SC6605_VDM_RD_0_325))
			break;
		(void)power_msleep(DT_MSLEEP_100MS, 0, NULL);
	}
	if (cnt == SC6605_SCP_DETECT_MAX_CNT) {
		hwlog_err("CHG_SCP_ADAPTER_DETECT_OTHER\n");
		return -EINVAL;
	}
	return 0;
}

static int sc6605_fcp_adapter_detect_enable(struct sc6605_scp_dev *di)
{
	int ret;
	uint8_t reg_dp_val = 0;
	uint8_t reg_dm_val = 0;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -EINVAL;
	}

	reg_dp_val = sc6605_scp_field_read(di, F_DP_STAT);
	reg_dm_val = sc6605_scp_field_read(di, F_DM_STAT);
	hwlog_info("[%s] dp = %d, dm = %d\n", __func__, reg_dp_val, reg_dm_val);

	if (reg_dp_val > SC6605_DPDM_VOL && reg_dm_val > SC6605_DPDM_VOL) {
		ret |= sc6605_scp_field_write(di, F_DPDM_EN, true);
		ret |= sc6605_scp_field_write(di, F_DP_DRIVE, DPDM_20K_DOWN);
		usleep_range(10000, 11000);
		ret |= sc6605_scp_field_write(di, F_DP_DRIVE, DPDM_HIZ);
	}

	return ret;
}

static int sc6605_fcp_detect_adapter(void *dev_data)
{
	int ret;
	uint8_t reg_val;
	struct sc6605_scp_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return ADAPTER_DETECT_OTHER;
	}

	ret =sc6605_fcp_adapter_detect_enable(di);
	ret |= regmap_bulk_read(di->rmap, SC6605_REG_DPDM_INT_MASK, &reg_val, REG_COUNT1);

	reg_val &= ~SC6605_DPDM_INT2;
	ret |= regmap_write(di->rmap, SC6605_REG_DPDM_INT_MASK, reg_val);
	ret |= sc6605_scp_field_write(di, F_DPDM_EN, true);
	/* open DP 0.6V */
	ret |= sc6605_scp_field_write(di, F_DP_DRIVE, DPDM_V0_6);
	if (ret) {
		hwlog_err("[%s] open DP failed\n", __func__);
		return ADAPTER_DETECT_OTHER;
	}

	power_msleep(DT_MSLEEP_1S + DT_MSLEEP_300MS, 0, NULL);

	/* write DM voltage */
	ret = regmap_write(di->rmap, SC6605_REG_DPDM_INTERNAL, DPDM_INTERNAL_VAL);
	if (ret) {
		hwlog_err("[%s] write 0x%x byte failed\n", __func__, SC6605_REG_DPDM_INTERNAL);
		return ADAPTER_DETECT_OTHER;
	}

	power_usleep(DT_USLEEP_1MS);

	ret = sc6605_fcp_adapter_detct_dpdm_stat(di);
	if (ret) {
		(void)sc6605_scp_reset(di);
		hwlog_err("[%s] handshake failed\n", __func__);
		return ADAPTER_DETECT_OTHER;
	}

	ret |= sc6605_scp_field_write(di, F_DM_DRIVE, DPDM_V3_3);
	ret |= sc6605_scp_field_write(di, F_SCP_EN, true);
	if (ret) {
		hwlog_err("[%s] field write failed\n", __func__);
		return ADAPTER_DETECT_OTHER;
	}
	hwlog_info("[%s] handshake success\n", __func__);
	return ADAPTER_DETECT_SUCC;
}

static int sc6605_fcp_master_reset(void *dev_data)
{
	int ret;
	struct sc6605_scp_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);;
		return -ENODEV;
	}

	ret = sc6605_scp_field_write(di, F_SCP_SOFT_RST, true);
	if (ret) {
		hwlog_err("[%s] fcp_master_reset failed\n", __func__);
		return ret;
	}

	return 0;
}

static int sc6605_fcp_adapter_reset(void *dev_data)
{
	int ret;
	struct sc6605_scp_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	ret = sc6605_scp_field_write(di, F_SCP_SOFT_RST, true);
	if (ret) {
		hwlog_err("[%s] fcp_adapter_reset failed\n", __func__);
		return ret;
	}

	return 0;
}

static int sc6605_fcp_read_switch_status(void *dev_data)
{
	return 0;
}

static int sc6605_fcp_stop_charge_config(void *dev_data)
{
	int ret;
	struct sc6605_scp_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	ret = sc6605_fcp_master_reset(di);
	ret |= sc6605_scp_reset(di);
	if (ret) {
		hwlog_err("[%s] stop_charge_config failed\n", __func__);
		return ret;
	}

	return 0;
}

static int sc6605_is_fcp_charger_type(void *dev_data)
{
	return 0;
}

static int sc6605_scp_reg_read_block(int reg, int *val, int num, void *dev_data)
{
	int ret;
	struct sc6605_scp_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	ret = sc6605_fcp_reg_read_block(reg, val, num, di);
	if (ret) {
		hwlog_err("[%s] scp read failed\n", __func__);
		return ret;
	}

	return 0;
}

static int sc6605_scp_reg_write_block(int reg, const int *val, int num, void *dev_data)
{
	int ret;
	struct sc6605_scp_dev *di = dev_data;

	if (!di || !val) {
		hwlog_err("[%s] di or val is null\n", __func__);
		return -ENODEV;
	}

	ret = sc6605_fcp_reg_write_block(reg, val, num, di);
	if (ret) {
		hwlog_err("[%s] scp write failed\n", __func__);
		return ret;
	}

	return 0;
}

static int sc6605_scp_detect_adapter(void *dev_data)
{
	struct sc6605_scp_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	return sc6605_fcp_detect_adapter(di);
}

static int sc6605_scp_chip_reset(void *dev_data)
{
	int ret;
	struct sc6605_scp_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	ret = sc6605_fcp_master_reset(di);
	if (ret) {
		hwlog_err("[%s] chip reset failed\n", __func__);
		return ret;
	}

	return 0;
}

static int sc6605_scp_adapter_reset(void *dev_data)
{
	int ret;
	struct sc6605_scp_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	ret = sc6605_fcp_adapter_reset(di);
	if (ret) {
		hwlog_err("[%s] adapter reset failed\n", __func__);
		return ret;
	}

	return 0;
}

static int sc6605_pre_init(void *dev_data)
{
	hwlog_err("sc6605_pre_init\n");
	return 0;
}

static struct hwfcp_ops sc6605_hwfcp_ops = {
	.chip_name = "sc6605",
	.reg_read = sc6605_fcp_reg_read_block,
	.reg_write = sc6605_fcp_reg_write_block,
	.detect_adapter = sc6605_fcp_detect_adapter,
	.soft_reset_master = sc6605_fcp_master_reset,
	.soft_reset_slave = sc6605_fcp_adapter_reset,
	.get_master_status = sc6605_fcp_read_switch_status,
	.stop_charging_config = sc6605_fcp_stop_charge_config,
	.is_accp_charger_type = sc6605_is_fcp_charger_type,
};

static struct hwscp_ops sc6605_hwscp_ops = {
	.chip_name = "sc6605",
	.reg_read = sc6605_scp_reg_read_block,
	.reg_write = sc6605_scp_reg_write_block,
	.reg_multi_read = sc6605_scp_multi_reg_read_block,
	.detect_adapter = sc6605_scp_detect_adapter,
	.soft_reset_master = sc6605_scp_chip_reset,
	.soft_reset_slave = sc6605_scp_adapter_reset,
	.pre_init = sc6605_pre_init,
};

static int sc6605_protocol_ops_register(struct sc6605_scp_dev *di)
{
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}
	sc6605_hwscp_ops.dev_data = (void *)di;
	ret = hwscp_ops_register(&sc6605_hwscp_ops);
	if (ret) {
		hwlog_err("[%s] hwscp_ops_register fail", __func__);
		return ret;
	}

	sc6605_hwfcp_ops.dev_data = (void *)di;
	ret = hwfcp_ops_register(&sc6605_hwfcp_ops);
	if (ret) {
		hwlog_err("[%s] hwfcp_ops_register fail", __func__);
		return ret;
	}

	return 0;
}

static irqreturn_t sc6605_scp_interrupt_handler(int irq, void *data)
{
	struct sc6605_scp_dev *di = data;
	int ret;
	uint8_t reg_val;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return IRQ_NONE;
	}

	ret = regmap_bulk_read(di->rmap, SC6605_REG_SCP_FLAG_MASK, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] read 0x%x fail\n", __func__, SC6605_REG_SCP_FLAG_MASK);
		return IRQ_NONE;
	}

	hwlog_info("[%s] flag = 0x%02x\n", __func__, reg_val);

	if (reg_val & SCP_TX_FIFO_EMPTY)
		hwlog_info("[%s] scp tx fifo empty\n", __func__);

	if (reg_val & SCP_RX_FIFO_FULL)
		hwlog_info("[%s] scp rx fifo full\n", __func__);

	if (reg_val & SCP_TRANS_DONE) {
		hwlog_info("[%s] scp trans done\n", __func__);
		complete(&di->complete);
	}
	return IRQ_HANDLED;
}

static int sc6605_scp_request_irq(struct sc6605_scp_dev *di)
{
	int ret;
	const char *irq_name = "SCP";

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}
	ret = platform_get_irq_byname(to_platform_device(di->dev), irq_name);
	if (ret < 0) {
		hwlog_err("[%s] failed to get irq %s\n", __func__, irq_name);
		return ret;
	}

	di->irq = ret;
	hwlog_info("[%s] %s irq = %d\n", __func__, irq_name, ret);
	ret = devm_request_threaded_irq(di->dev, ret, NULL, sc6605_scp_interrupt_handler,
		IRQF_ONESHOT, dev_name(di->dev), di);
	if (ret < 0) {
		hwlog_err("[%s] failed to request irq %s\n", __func__, irq_name);
		return ret;
	}
	return 0;
}

static int sc6605_scp_probe(struct platform_device *pdev)
{
	int ret;
	struct sc6605_scp_dev *di = NULL;
	struct device *dev = NULL;

	if (!pdev || !pdev->dev.of_node) {
		hwlog_err("[%s] pdev or of_node is null\n", __func__);
		return -ENODEV;
	}

	dev = &pdev->dev;
	di = devm_kzalloc(dev, sizeof(struct sc6605_scp_dev), GFP_KERNEL);
	if (!di) {
		return -ENOMEM;
	}
	di->rmap = dev_get_regmap(dev->parent, NULL);
	if (!di->rmap) {
		hwlog_err("[%s] failed to get regmap\n", __func__);
		return -ENODEV;
	}

	di->dev = dev;
	ret = sc6605_scp_request_irq(di);
	if (ret) {
		hwlog_err("[%s] irq request failed\n", __func__);
		return ret;
	}

	ret = sc6605_protocol_ops_register(di);
	if (ret) {
		hwlog_err("[%s] scp or fcp ops register failed\n", __func__);
		return ret;
	}

	init_completion(&di->complete);

	hwlog_info("[%s]: success\n", __func__);
	return 0;
}

static int sc6605_scp_remove(struct platform_device *pdev)
{
	return 0;
}

static const struct of_device_id sc6605_scp_of_match[] = {
	{
		.compatible = "huawei,sc6605_scp",
		.data = NULL,
	},
	{},
};

static struct platform_driver sc6605_scp_driver = {
	.driver = {
		.name = "sc6605_scp",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(sc6605_scp_of_match),
	},
	.probe = sc6605_scp_probe,
	.remove = sc6605_scp_remove,
};
module_platform_driver(sc6605_scp_driver);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("sc6605 scp module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");