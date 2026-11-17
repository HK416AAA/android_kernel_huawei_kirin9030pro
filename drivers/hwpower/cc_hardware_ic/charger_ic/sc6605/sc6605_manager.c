// SPDX-License-Identifier: GPL-2.0+
/*
 * sc6605_manager.c
 *
 * sc6605 manager driver
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

#include "sc6605_manager.h"
#include <huawei_platform/log/hw_log.h>
#include <chipset_common/hwpower/common_module/power_gpio.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>

#define HWLOG_TAG sc6605_manager
HWLOG_REGIST();

static int sc6605_i2c_write_bytes(struct i2c_client *i2c, uint8_t reg, uint8_t len, uint8_t *val)
{
	u8 *buff = NULL;
	int ret;

	if (!i2c || !val) {
		hwlog_err("[%s] i2c or val is null\n", __func__);
		return -ENOMEM;
	}

	buff = kzalloc(len + REG_COUNT1, GFP_KERNEL);
	if (!buff)
		return -ENOMEM;

	buff[0] = reg;
	memcpy_s(&buff[1], len, val, len);
	ret = power_i2c_write_block(i2c, buff, len + REG_COUNT1);
	if (ret)
		hwlog_err("[%s] block write failed\n", __func__);

	kfree(buff);
	return ret;
}

static int sc6605_i2c_read_bytes(struct i2c_client *i2c, uint8_t reg, uint8_t len, uint8_t *val)
{
	int ret;

	if (!i2c || !val) {
		hwlog_err("[%s] i2c or val is null\n", __func__);
		return -ENOMEM;
	}

	ret = power_i2c_read_block(i2c, &reg, REG_COUNT1, val, len);
	if (ret)
		hwlog_err("[%s] read write failed\n", __func__);

	return ret;
}

static int sc6605_regmap_write_bytes(void *context, const void *data, size_t count)
{
	struct sc6605_device *di = context;
	struct i2c_client *i2c;
	const u8 *wrt_data = data;
	int ret;

	if (!di || !data) {
		hwlog_err("[%s] di or data is null\n", __func__);
		return -ENOMEM;
	}

	if (count < REG_COUNT2)
		return -EINVAL;

	if (atomic_read(&di->in_sleep)) {
		hwlog_info("[%s] in sleep\n", __func__);
		return -EHOSTDOWN;
	}

	i2c = di->i2c[wrt_data[0]];
	ret = sc6605_i2c_write_bytes(i2c, wrt_data[1], count - REG_COUNT2, (uint8_t *)wrt_data + REG_COUNT2);
	if (ret)
		hwlog_err("[%s] wrt_data0 = 0x%x  wrt_data1 = 0x%x write fail\n", __func__, wrt_data[0], wrt_data[1]);

	return ret;
}

static int sc6605_regmap_read_bytes(void *context, const void *reg_buf, size_t reg_size,
	void *val_buf, size_t val_size)
{
	int ret;
	struct sc6605_device *di = context;
	struct i2c_client *i2c;
	const u8 *read_reg_buf = reg_buf;

	if (!di || !read_reg_buf || !val_buf) {
		hwlog_err("[%s] di or reg_buf or val_buf is null\n", __func__);
		return -ENOMEM;
	}

	if (atomic_read(&di->in_sleep)) {
		hwlog_info("[%s] in sleep\n", __func__);
		return -EHOSTDOWN;
	}

	i2c = di->i2c[read_reg_buf[0]];

	ret = sc6605_i2c_read_bytes(i2c, read_reg_buf[1], val_size, val_buf);
	if (ret)
		hwlog_err("[%s] read_reg_buf = 0x%x 0x%x read fail\n", __func__, read_reg_buf[0], read_reg_buf[1]);

	return ret;
}

static const struct regmap_bus sc6605_regmap_bus = {
	.write = sc6605_regmap_write_bytes,
	.read = sc6605_regmap_read_bytes,
};

static const struct regmap_config sc6605_regmap_config = {
	.reg_bits = SC6605_REG_SHIFT16,
	.val_bits = SC6605_REG_SHIFT8,
	.reg_format_endian = REGMAP_ENDIAN_BIG,
};

static void sc6605_irq_lock(struct irq_data *data)
{
	struct sc6605_device *di = irq_data_get_irq_chip_data(data);

	hwlog_info("[%s] \n", __func__);
	mutex_lock(&di->irq_lock);
}

static void sc6605_irq_sync_unlock(struct irq_data *data)
{
	struct sc6605_device *di = irq_data_get_irq_chip_data(data);

	hwlog_info("[%s] \n", __func__);
	regmap_bulk_write(di->rmap, SC6605_REG_HK_GEN_MASK, &di->irq_mask, REG_COUNT1);
	mutex_unlock(&di->irq_lock);
}

static void sc6605_irq_enable(struct irq_data *data)
{
	struct sc6605_device *di = irq_data_get_irq_chip_data(data);

	di->irq_mask &= ~BIT(data->hwirq);
}

static void sc6605_irq_disable(struct irq_data *data)
{
	struct sc6605_device *di = irq_data_get_irq_chip_data(data);

	di->irq_mask |= BIT(data->hwirq);
}

static int sc6605_irq_map(struct irq_domain *irq_domain_ptr, unsigned int virq, irq_hw_number_t hwirq)
{
	struct sc6605_device *di = irq_domain_ptr->host_data;
	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	irq_set_chip_data(virq, di);
	irq_set_chip(virq, &di->irq_chip);
	irq_set_nested_thread(virq, true);
	irq_set_parent(virq, di->irqn);
	irq_set_noprobe(virq);
	return 0;
}

static const struct irq_domain_ops sc6605_domain_ops = {
	.map = sc6605_irq_map,
	.xlate = irq_domain_xlate_onetwocell,
};

static irqreturn_t sc6605_manager_interrupt_handler(int irq, void *data)
{
	struct sc6605_device *di = data;
	uint8_t reg_val;
	uint16_t irq_state = 0;
	bool is_handled = false;
	unsigned int irq_map_num;
	int i, ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return IRQ_HANDLED;
	}

	pm_stay_awake(di->dev);
	
	ret = regmap_bulk_read(di->rmap, SC6605_REG_HK_GEN_FLG, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] failed to read irq event err:%d\n", __func__, ret);
		return IRQ_NONE;
	}
	irq_state = reg_val;
	
	irq_state |= BIT(SC6605_IRQ_HK);
	irq_state &= ~(di->irq_mask);

	hwlog_info("[%s] irq map -> 0x%x, mask -> 0x%x\n", __func__, irq_state, di->irq_mask);
	
	for (i = 0; i < SC6605_IRQ_MAX; i++) {
		irq_map_num = irq_find_mapping(di->domain, i);
		if (irq_map_num == 0)
			continue;
		if(irq_state & BIT(i)) {
			handle_nested_irq(irq_map_num);
			is_handled = true;
		}
	}

	pm_relax(di->dev);
	return is_handled ? IRQ_HANDLED : IRQ_NONE;
}

static int sc6605_add_irq_chip(struct sc6605_device *di)
{
	int ret;
	di->irq_mask = IQR_MASK;

	ret = regmap_bulk_read(di->rmap, SC6605_REG_HK_GEN_MASK, &di->irq_mask, REG_COUNT1);

	di->irq_chip.name = dev_name(di->dev);
	di->irq_chip.irq_disable = sc6605_irq_disable;
	di->irq_chip.irq_enable = sc6605_irq_enable;
	di->irq_chip.irq_bus_lock = sc6605_irq_lock;
	di->irq_chip.irq_bus_sync_unlock = sc6605_irq_sync_unlock;

	di->domain = irq_domain_add_linear(di->dev->of_node, SC6605_IRQ_MAX, &sc6605_domain_ops, di);
	if (!di->domain) {
		hwlog_err("[%s] failed to create irq domain\n", __func__);
		return -ENOMEM;
	}

	ret = devm_request_threaded_irq(di->dev, di->irqn, NULL, sc6605_manager_interrupt_handler,
			IRQF_TRIGGER_RISING | IRQF_ONESHOT, dev_name(di->dev), di);
	if (ret) {
		hwlog_err("[%s] failed to request irq %d for %s\n", __func__ , di->irqn,
			dev_name(di->dev));

		irq_domain_remove(di->domain);
		return ret;
	}

	hwlog_info("[%s] sc6605 irq = %d\n", __func__ , di->irqn);

	return 0;
}

static void sc6605_del_irq_chip(struct sc6605_device *di)
{
	unsigned int virq;
	int hwirq;

	if (!di || !di->domain) {
		hwlog_err("[%s] di or domain is null\n", __func__);
		return;
	}

	for (hwirq = 0; hwirq < SC6605_IRQ_MAX; hwirq++) {
		virq = irq_find_mapping(di->domain, hwirq);
		if (virq)
			irq_dispose_mapping(virq);
	}

	irq_domain_remove(di->domain);
}

static int sc6605_check_chip(struct sc6605_device *di)
{
	int ret;
	u8 did;

	ret = regmap_bulk_read(di->rmap, SC6605_REG_DEVICE_ID, &did, REG_COUNT1);
	if (ret || (did != SC6605_DEVICE_ID)) {
		hwlog_err("[%s] DEVICE_ID failed\n", __func__);
		return -ENODEV;
	}

	return ret;
}

static int sc6605_init_device_operation(struct sc6605_device *di)
{
	int ret;
	u8 evt;

	di->rmap = devm_regmap_init(di->dev, &sc6605_regmap_bus, di, &sc6605_regmap_config);
	if (IS_ERR(di->rmap)) {
		hwlog_err("[%s] failed to init regmap\n", __func__);
		ret = PTR_ERR(di->rmap);
		return ret;
	}

	ret = sc6605_check_chip(di);
	if (ret) {
		hwlog_err("[%s] failed to check device id\n", __func__);
		return ret;
	}

	/* clear flag */
	ret = regmap_bulk_read(di->rmap, SC6605_REG_HK_GEN_FLG, &evt, REG_COUNT1);
	/* add irq */
	ret |= sc6605_add_irq_chip(di);
	if (ret)
		hwlog_err("[%s] failed to add irq chip\n", __func__);

	return ret;
}

static int sc6605_manager_probe(struct i2c_client *client)
{
	int ret;
	int irq_gpio;
	struct sc6605_device *di = NULL;
	struct device_node *np = NULL;

	if (!client || !client->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&client->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;
	di->dev = &client->dev;
	np = di->dev->of_node;
	i2c_set_clientdata(client, di);
	mutex_init(&di->irq_lock);
	atomic_set(&di->in_sleep, 0);
	ret = power_gpio_config_interrupt(np, "intr_gpio_num", "charger_int", &irq_gpio, &di->irqn);
	if (ret) {
		hwlog_err("[%s] gpio config failed!\n", __func__);
		goto sc6605_fail_0;
	}

	di->i2c[SC6605_SLAVE_CHG] = client;
	di->i2c[SC6605_SLAVE_UFCS] = i2c_new_dummy_device(client->adapter, sc6605_slave_addr[SC6605_SLAVE_UFCS]);
	if (IS_ERR(di->i2c[SC6605_SLAVE_UFCS])) {
		hwlog_err("[%s] failed to create new i2c[0x%02x] dev\n", __func__, sc6605_slave_addr[SC6605_SLAVE_UFCS]);
		ret = PTR_ERR(di->i2c[SC6605_SLAVE_UFCS]);
		goto sc6605_fail_0;
	}

	ret = sc6605_init_device_operation(di);
	if (ret) {
		hwlog_err("[%s] failed to add irq chip\n", __func__);
		goto sc6605_fail_1;
	}
	enable_irq_wake(di->irqn);
	device_init_wakeup(di->dev, true);
	ret = devm_of_platform_populate(di->dev);
	if (ret) {
		hwlog_err("%s populate fail ret %d\n", __func__, ret);
		goto sc6605_fail_1;
	}
	hwlog_info("[%s] success\n", __func__);
	return ret;

sc6605_fail_1:
	sc6605_del_irq_chip(di);
	i2c_unregister_device(di->i2c[SC6605_SLAVE_UFCS]);
sc6605_fail_0:
	mutex_destroy(&di->irq_lock);
	hwlog_info("[%s] failed\n", __func__);
	return ret;
}

static int sc6605_manager_remove(struct i2c_client *client)
{
	struct sc6605_device *di = i2c_get_clientdata(client);

	if (!di)
		return -ENODEV;

	sc6605_del_irq_chip(di);
	mutex_destroy(&di->irq_lock);
	return 0;
}

#ifdef CONFIG_PM
static int sc6605_suspend(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	struct sc6605_device *di = i2c_get_clientdata(i2c);

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	if (device_may_wakeup(dev))
		enable_irq_wake(di->irqn);

	disable_irq(di->irqn);

	return 0;
}

static int sc6605_resume(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	struct sc6605_device *di = i2c_get_clientdata(i2c);

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	enable_irq(di->irqn);
	if (device_may_wakeup(dev))
		disable_irq_wake(di->irqn);

	return 0;
}

static int sc6605_suspend_noirq(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	struct sc6605_device *di = i2c_get_clientdata(i2c);

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	atomic_set(&di->in_sleep, 1);
	return 0;
}

static int sc6605_resume_noirq(struct device *dev)
{
	struct i2c_client *i2c = to_i2c_client(dev);
	struct sc6605_device *di = i2c_get_clientdata(i2c);

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	atomic_set(&di->in_sleep, 0);
	return 0;
}

static const struct dev_pm_ops sc6605_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(sc6605_suspend, sc6605_resume)
	SET_NOIRQ_SYSTEM_SLEEP_PM_OPS(sc6605_suspend_noirq, sc6605_resume_noirq)
};

#define SC6605_PM_OPS (&sc6605_pm_ops)
#else
#define SC6605_PM_OPS (NULL)
#endif /* CONFIG_PM */

static const struct of_device_id sc6605_of_match[] = {
	{
		.compatible = "huawei,sc6605_manager",
		.data = NULL,
	},
	{},
};

static struct i2c_driver sc6605_driver = {
	.probe_new = sc6605_manager_probe,
	.remove = sc6605_manager_remove,
	.driver = {
		.name = "sc6605_manager",
		.pm = SC6605_PM_OPS,
		.of_match_table = of_match_ptr(sc6605_of_match),
	},
};
module_i2c_driver(sc6605_driver);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("sc6605 manager module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");