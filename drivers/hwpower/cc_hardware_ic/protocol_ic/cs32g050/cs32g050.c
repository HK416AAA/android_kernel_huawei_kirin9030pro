// SPDX-License-Identifier: GPL-2.0
/*
 * cs32g050.c
 *
 * cs32g050 driver
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

#include "cs32g050.h"
#include "cs32g050_i2c.h"
#include "cs32g050_scp.h"
#include "cs32g050_ufcs.h"
#include "cs32g050_fw.h"
#include "cs32g050_rscp.h"
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_gpio.h>
#include <chipset_common/hwpower/common_module/power_pinctrl.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include <linux/proc_fs.h>

#define HWLOG_TAG cs32g050
HWLOG_REGIST();

static u32 g_fw_ver;

void cs32g050_hard_reset(struct cs32g050_device_info *di)
{
	/* reset pin pull low */
	gpio_set_value(di->gpio_rst, 1);
	power_usleep(DT_USLEEP_10MS);
	/* reset pin pull high */
	gpio_set_value(di->gpio_rst, 0);

	/* wait for reset complete */
	power_msleep(DT_MSLEEP_400MS, 0, NULL);
	hwlog_info("cs32g050 hard reset done.\n");
}

int cs32g050_ic_reset(void *dev_data)
{
	int ret;
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_IC_RESET_SUB_CMD,
		CS32G050_PORT_DEFAULT};
	u8 ping_ret_len = 0;

	if (!di)
		return -ENODEV;

	/* mcu not response iic when reboot, return directly */
	if (!di->usb_connect && di->ready_for_reboot)
		return 0;

	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_NORMAL_CMD_LEN,
		&ping_ret_len, 2);
	if (ret)
		hwlog_err("ic_reset fail\n");

	return ret;
}

int cs32g050_driver_set_usb_protocol_mux(void *dev_data, u8 mux_status)
{
	int ret;
	struct cs32g050_device_info *di = dev_data;
	u8 mux_ctrl_cmds[5] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT + 1,
		CS32G050_SET_USB_PROTOCOL_MUX_SUB_CMD, CS32G050_PORT_DEFAULT, mux_status};
	u8 ping_ret_len = 0;

	if (!di)
		return -ENODEV;

	/* mcu not response iic when reboot, return directly */
	if (!di->usb_connect && di->ready_for_reboot)
		return 0;

	ret = cs32g050_write_cmd_with_ping(di, mux_ctrl_cmds, 5, &ping_ret_len, DT_MSLEEP_1MS);
	if (ret) {
		hwlog_err("%s: wirte cmd fail\n", __func__);
		return -EPERM;
	}

	return 0;
}

int cs32g050_driver_set_mux_ctrl(void *dev_data, u8 mux_status)
{
	int ret;
	struct cs32g050_device_info *di = dev_data;
	u8 mux_ctrl_cmds[5] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT + 1,
		CS32G050_SET_MUX_CTRL_SUB_CMD, CS32G050_PORT_DEFAULT, mux_status};
	u8 ping_ret_len = 0;

	ret = cs32g050_write_cmd_with_ping(di, mux_ctrl_cmds, 5, &ping_ret_len, DT_MSLEEP_1MS);
	if (ret) {
		hwlog_err("%s: wirte cmd fail\n", __func__);
		return -EPERM;
	}

	return 0;
}

int cs32g050_read_irq_reg(void *dev_data, u8 *data, u8 len)
{
	int ret;
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = { CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_GET_IRQ_STATUS_SUB_CMD, CS32G050_PORT_DEFAULT };

	if (!di)
		return -ENODEV;

	if (!data || (len != CS32G050_IRQ_REG_NUM)) {
		hwlog_err("Invalid input parameters\n");
		return -EINVAL;
	}

	ret = cs32g050_cmd_read_data(di, cmds, CS32G050_NORMAL_CMD_LEN, data, len);
	if (ret) {
		hwlog_err("get_irq_status cmd_read fail\n");
		return ret;
	}

	hwlog_info("[irq_flags]:0x%x, 0x%x, 0x%x\n", data[0], data[1], data[2]);
	return 0;
}

static void cs32g050_interrupt_work(struct work_struct *work)
{
	struct cs32g050_device_info *di = NULL;
	u8 reg_val[CS32G050_IRQ_REG_NUM] = { 0 };

	di = container_of(work, struct cs32g050_device_info, irq_work);
	if (!di) {
		hwlog_err("di is null\n");
		return;
	}

	if (cs32g050_read_irq_reg(di, reg_val, CS32G050_IRQ_REG_NUM)) {
		hwlog_err("read irq reg fail\n");
		enable_irq(di->irq_int);
		return;
	}

	cs32g050_ufcs_int_cb(di, reg_val[0], reg_val[1]);
	cs32g050_rscp_int_cb(reg_val[2]);
	enable_irq(di->irq_int);
}

static irqreturn_t cs32g050_interrupt(int irq, void *_di)
{
	struct cs32g050_device_info *di = _di;

	if (!di)
		return IRQ_HANDLED;

	hwlog_info("int happened\n");
	disable_irq_nosync(di->irq_int);
	(void)queue_work(system_highpri_unbound_wq, &di->irq_work);
	return IRQ_HANDLED;
}

static void cs32g050_power_on_work(struct work_struct *work)
{
	struct cs32g050_device_info *di = NULL;

	if (!work)
		return;

	di = container_of(work, struct cs32g050_device_info, pwr_ctrl.pwr_on_work);
	if (!di) {
		hwlog_err("%s: di is invalid parameter\n", __func__);
		return;
	}

	mutex_lock(&di->pwr_ctrl_lock);
	cancel_delayed_work(&di->pwr_ctrl.pwr_down_work);

	gpio_set_value(di->gpio_en, 1);
	di->pwr_ctrl.is_power_on = true;

	power_msleep(DT_MSLEEP_400MS, 0, NULL);
	di->pwr_ctrl.is_slave_iic_ready = true;
	mutex_unlock(&di->pwr_ctrl_lock);

	hwlog_info("power on, slave iic ready.\n");
}

static void cs32g050_power_down_execute(struct cs32g050_device_info *di)
{
	if (di->usb_connect || di->fw_update || di->ready_for_reboot)
		return;

	mutex_lock(&di->pwr_ctrl_lock);
	gpio_set_value(di->gpio_en, 0);
	di->pwr_ctrl.is_power_on = false;
	di->pwr_ctrl.is_slave_iic_ready = false;
	mutex_unlock(&di->pwr_ctrl_lock);

	hwlog_info("port unattach, power down.\n");
}

static void cs32g050_power_down_work(struct work_struct *work)
{
	struct cs32g050_device_info *di = NULL;

	if (!work)
		return;

	di = container_of(work, struct cs32g050_device_info, pwr_ctrl.pwr_down_work.work);
	if (!di) {
		hwlog_err("%s: di is invalid parameter\n", __func__);
		return;
	}

	cs32g050_power_down_execute(di);
}

static int cs32g050_gpio_init(struct cs32g050_device_info *di,
	struct device_node *np)
{
	int ret;

	/* cs32g050 hard_reset pin */
	ret = power_gpio_config_output(np,
		"gpio_rst", "cs32g050_gpio_rst", &di->gpio_rst, 0);
	if (ret)
		return ret;

	/* set gpio to disable/enable cs32g050 */
	ret = power_gpio_config_output(np,
		"gpio_en", "cs32g050_gpio_en", &di->gpio_en, 1);
	if (ret) {
		gpio_free(di->gpio_rst);
		return ret;
	}

	INIT_WORK(&di->pwr_ctrl.pwr_on_work, cs32g050_power_on_work);
	INIT_DELAYED_WORK(&di->pwr_ctrl.pwr_down_work, cs32g050_power_down_work);

	INIT_WORK(&di->irq_work, cs32g050_interrupt_work);
	ret = power_gpio_config_interrupt(np,
		"gpio_int", "cs32g050_gpio_int", &di->gpio_int, &di->irq_int);
	if (ret) {
		gpio_free(di->gpio_en);
		gpio_free(di->gpio_rst);
		return ret;
	}

	ret = request_irq(di->irq_int, cs32g050_interrupt,
		IRQF_TRIGGER_FALLING, "cs32g050_int_irq", di);
	if (ret) {
		hwlog_err("gpio irq request fail\n");
		di->irq_int = -1;
		gpio_free(di->gpio_en);
		gpio_free(di->gpio_int);
		gpio_free(di->gpio_rst);
		return ret;
	}

	enable_irq_wake(di->irq_int);
	return 0;
}

static void cs32g050_ops_register(struct cs32g050_device_info *di)
{
	int ret = 0;

	if (di->param_dts.scp_support)
		ret = cs32g050_hwscp_register(di);
	if (di->param_dts.fcp_support)
		ret += cs32g050_hwfcp_register(di);
	if (di->param_dts.rscp_support)
		ret += cs32g050_hwrscp_register(di);
	if (di->param_dts.rufcs_support)
		ret += cs32g050_hwrufcs_register(di);
	if (ret)
		hwlog_err("scp or fcp ops register fail\n");

	if (di->param_dts.ufcs_support) {
		ret = cs32g050_hwufcs_register(di);
		if (ret)
			hwlog_err("ufcs ops register fail\n");
	}
}

static void cs32g050_parse_fw_para(struct device_node *np, struct cs32g050_device_info *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "firmware_update_mode",
		(u32 *)&di->fw_param.fw_update_mode, 1);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "firmware_version",
		(u32 *)&di->fw_param.fw_version, CS32G050_FIRMWARE_VERSION_DEFAULT);
}

static void cs32g050_parse_dts(struct device_node *np, struct cs32g050_device_info *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "support_scp",
		(u32 *)&(di->param_dts.scp_support), 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "support_fcp",
		(u32 *)&(di->param_dts.fcp_support), 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "support_ufcs",
		(u32 *)&(di->param_dts.ufcs_support), 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "support_rscp",
		(u32 *)&(di->param_dts.rscp_support), 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "support_rufcs",
		(u32 *)&(di->param_dts.rufcs_support), 0);

	cs32g050_parse_fw_para(np, di);
}

static void cs32g050_fw_reboot_work(struct work_struct *work)
{
	struct cs32g050_device_info *di = NULL;

	if (!work)
		return;

	di = container_of(work, struct cs32g050_device_info, fw_reboot_work);
	if (!di)
		return;

	cancel_delayed_work(&di->pwr_ctrl.pwr_down_work);
	cs32g050_fw_reboot_unattach(di);
	schedule_delayed_work(&di->pwr_ctrl.pwr_down_work,
		msecs_to_jiffies(CS32G050_PWR_DOWN_DELAY));
}

static void cs32g050_fw_update_work(struct work_struct *work)
{
	struct cs32g050_device_info *di = NULL;
	static int cnt = 0;
	int soc = 0;

	if (!work)
		return;

	di = container_of(work, struct cs32g050_device_info, fw_work.work);
	if (!di) {
		hwlog_err("%s: di is invalid parameter\n", __func__);
		return;
	}

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_CAPACITY, &soc, POWER_SUPPLY_DEFAULT_CAPACITY, 1);
	if (soc <= CS32G050_FW_SOC_MIN) {
		hwlog_info("%s: capacity is out of range\n", __func__);
		di->fw_update = false;
		return;
	}

	if (cs32g050_fw_param_init(di) == 0) {
		hwlog_info("%s: retry %d times\n", __func__, cnt);
		cs32g050_fw_update(di);

		schedule_delayed_work(&di->pwr_ctrl.pwr_down_work,
			msecs_to_jiffies(CS32G050_PWR_DOWN_DELAY));
		return;
	}

	if (cnt < CS32G050_FW_UPDATE_RETRY_COUNT) {
		cnt++;
		schedule_delayed_work(&di->fw_work,
			msecs_to_jiffies(CS32G050_FIRMWARE_UPDATE_DELAY));
		return;
	}

	di->fw_update = false;
	hwlog_err("%s: get firmware timeout\n", __func__);
}

int cs32g050_ic_pwr_switch(void *dev_data, bool is_pwr_on)
{
	struct cs32g050_device_info *di = dev_data;

	if (!di)
        return -ENODEV;
    if (is_pwr_on)
        (void)queue_work(system_highpri_unbound_wq, &di->pwr_ctrl.pwr_on_work);
	else
        schedule_delayed_work(&di->pwr_ctrl.pwr_down_work,
			msecs_to_jiffies(CS32G050_PWR_DOWN_DELAY));

    return 0;
}

static int cs32g050_usb_notifier_call(struct notifier_block *event_nb,
	unsigned long event, void *data)
{
	struct cs32g050_device_info *di = container_of(event_nb,
		struct cs32g050_device_info, event_nb);

	if (!di)
		return NOTIFY_OK;

	switch (event) {
	case POWER_NE_OTG_INSERT:
		di->otg_connect = true;
		break;
	case POWER_NE_USB_CONNECT:
		di->usb_connect = true;
		(void)queue_work(system_highpri_unbound_wq, &di->pwr_ctrl.pwr_on_work);
		break;
	case POWER_NE_USB_DISCONNECT:
		di->usb_connect = false;
		if (!di->ready_for_reboot)
            schedule_delayed_work(&di->pwr_ctrl.pwr_down_work,
                msecs_to_jiffies(CS32G050_PWR_DOWN_DELAY));
    case POWER_NE_OTG_REMOVE:
		di->otg_connect = false;
		di->ufcs_irq[0] = 0;
		di->ufcs_irq[1] = 0;
        cs32g050_driver_set_usb_protocol_mux((void*)di, CS32G050_MUX_CTRL_USB);
        di->scp_handshake_flag = false;
        di->is_in_rufcs_mode = false;
		if (di->ready_for_reboot)
                schedule_work(&di->fw_reboot_work);
		break;
	default:
		return NOTIFY_OK;
	}

	return NOTIFY_OK;
}

static void cs32g050_firmware_check(struct cs32g050_device_info *di)
{
	INIT_WORK(&di->fw_reboot_work, cs32g050_fw_reboot_work);

	if (di->ic_info.info.app_version >= di->fw_param.fw_version) {
		hwlog_err("no need update firmware\n");
		return;
	}

	hwlog_info("firmware_check, ic_version=0x%x, firmware_version=0x%x\n",
		di->ic_info.info.app_version, di->fw_param.fw_version);
	di->fw_update = true;
	di->wakelock = power_wakeup_source_register(di->dev, "cs32g050_wakelock");
	INIT_DELAYED_WORK(&di->fw_work, cs32g050_fw_update_work);
	schedule_delayed_work(&di->fw_work, msecs_to_jiffies(CS32G050_FIRMWARE_UPDATE_DELAY));
}

int cs32g050_get_ic_status(struct cs32g050_device_info *di)
{
	u8 buf[CS32G050_GET_IC_STATUS_BUF_LEN] = { CS32G050_GET_IC_STATUS, CS32G050_IC_STATUS_LEN };
	int ret;

	if (!di)
		return -ENODEV;

	ret = cs32g050_cmd_read_data(di, buf, sizeof(buf),
		di->ic_info.status, sizeof(di->ic_info.status));
	if (ret) {
		hwlog_err("get status fail\n");
		return ret;
	}

	hwlog_info("get status chip_id=%x, run_bank=%x, bootversion=%x, app_version=%x,\
		fail_times=%x\n", di->ic_info.info.chip_id, di->ic_info.info.run_bank,
		di->ic_info.info.boot_version, di->ic_info.info.app_version, di->ic_info.info.fail_time);

	g_fw_ver = di->ic_info.info.app_version >> 8;
	return 0;
}

static int cs32g050_device_check(struct cs32g050_device_info *di)
{
	int ret;
	int i;

	for (i = 0; i < CS32G050_DEV_CHECK_RETRY_CNT; i++) {
		ret = cs32g050_get_ic_status(di);
		if (ret == 0)
			break;
		hwlog_info("get ic status retry %d times\n", i + 1);
		power_usleep(DT_USLEEP_10MS);
	}

	if (i >= CS32G050_DEV_CHECK_RETRY_CNT) {
		hwlog_err("get ic status fail\n");
		return -EINVAL;
	}

	if (di->ic_info.info.chip_id != CS32G050_CHIP_ID) {
		hwlog_err("chip id(0x%x) error\n", di->ic_info.info.chip_id);
		return -EINVAL;
	}

	return 0;
}

static ssize_t cs32g050_fw_ver_read(struct file *filp, char __user *ubuf,
	size_t cnt, loff_t *ppos)
{
	(void) filp;
	int len = 0;
	char buf[CS32G050_FW_VERSION_LEN];
	char ver_buf[CS32G050_FW_VERSION_LEN];
	int ver = 0;

	len = sprintf_s(ver_buf, sizeof(ver_buf), "%x\n", g_fw_ver);
	if (len <= 0) {
		hwlog_info("%s: ver_buf sprintf failed\n", __func__);
		return 0;
	}

	if (kstrtoint(ver_buf, POWER_BASE_DEC, &ver)) {
		hwlog_info("%s: kstrtoint failed\n", __func__);
		return 0;
	}

	len = sprintf_s(buf, sizeof(buf), "XH %x\n", ver);
	if (len <= 0) {
		hwlog_info("%s: buf sprintf failed\n", __func__);
		return 0;
	}
	return simple_read_from_buffer(ubuf, cnt, ppos, buf, len);
}

static void cs32g050_mutex_init(struct cs32g050_device_info *di)
{
	mutex_init(&di->cmd_write_lock);
	mutex_init(&di->accp_adapter_reg_lock);
	mutex_init(&di->ufcs_detect_lock);
	mutex_init(&di->pwr_ctrl_lock);
}

static void cs32g050_mutex_destroy(struct cs32g050_device_info *di)
{
	mutex_destroy(&di->cmd_write_lock);
	mutex_destroy(&di->accp_adapter_reg_lock);
	mutex_destroy(&di->ufcs_detect_lock);
	mutex_destroy(&di->pwr_ctrl_lock);
}

static const struct proc_ops cs32g050_ver_info_fops = {
	.proc_read = cs32g050_fw_ver_read,
};

static void cs32g050_power_status_disable(struct cs32g050_device_info *di)
{
	di->chip_already_init = 0;
	di->pwr_ctrl.is_power_on = false;
	di->pwr_ctrl.is_slave_iic_ready = false;

	free_irq(di->irq_int, di);
	di->irq_int = -1;
	gpio_free(di->gpio_int);
	gpio_free(di->gpio_en);
	gpio_free(di->gpio_rst);
}

static int cs32g050_power_status_init(struct cs32g050_device_info *di,
	struct device_node *np)
{
	int ret;

	ret = cs32g050_gpio_init(di, np);
	if (ret)
		return -EPERM;

	di->chip_already_init = 1;
	di->pwr_ctrl.is_power_on = true;
	di->pwr_ctrl.is_slave_iic_ready = true;

	return 0;
}

static int cs32g050_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int ret;
	struct cs32g050_device_info *di = NULL;
	struct device_node *np = NULL;

	if (!client || !client->dev.of_node || !id)
		return -ENODEV;

	di = devm_kzalloc(&client->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &client->dev;
	np = di->dev->of_node;
	di->client = client;

	ret = cs32g050_power_status_init(di, np);
	if (ret)
		goto cs32g050_power_init_fail;

	ret = cs32g050_device_check(di);
	if (ret)
		goto cs32g050_fail_0;

	cs32g050_parse_dts(np, di);
	cs32g050_mutex_init(di);
	cs32g050_ops_register(di);

	proc_create("rchg_mcu_ver", 0444, NULL, &cs32g050_ver_info_fops);

	di->event_nb.notifier_call = cs32g050_usb_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_OTG, &di->event_nb);
	if (ret)
		goto cs32g050_fail_1;

	ret = power_event_bnc_register(POWER_BNT_CONNECT, &di->event_nb);
	if (ret)
		goto cs32g050_fail_2;

	cs32g050_firmware_check(di);
	i2c_set_clientdata(client, di);
	hwlog_info("probe ok\n");
	return 0;

cs32g050_fail_2:
	power_event_bnc_unregister(POWER_BNT_OTG, &di->event_nb);
cs32g050_fail_1:
	cs32g050_mutex_destroy(di);
cs32g050_fail_0:
	cs32g050_power_status_disable(di);
cs32g050_power_init_fail:
	devm_kfree(&client->dev, di);
	return -EPERM;
}

static int cs32g050_remove(struct i2c_client *client)
{
	struct cs32g050_device_info *di = i2c_get_clientdata(client);

	if (!di)
		return -ENODEV;

	(void)power_event_bnc_unregister(POWER_BNT_OTG, &di->event_nb);
	(void)power_event_bnc_unregister(POWER_BNT_CONNECT, &di->event_nb);
	cs32g050_mutex_destroy(di);
	power_wakeup_source_unregister(di->wakelock);

	return 0;
}

static void cs32g050_shutdown(struct i2c_client *client)
{
}

#ifdef CONFIG_PM
static int cs32g050_i2c_suspend(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct cs32g050_device_info *di = NULL;

	if (!client)
		return 0;

	di = i2c_get_clientdata(client);

	if (di) {
		cancel_delayed_work(&di->pwr_ctrl.pwr_down_work);
		cs32g050_power_down_execute(di);
	}

	return 0;
}

static int cs32g050_i2c_resume(struct device *dev)
{
	return 0;
}

static void cs32g050_i2c_complete(struct device *dev)
{
}

static const struct dev_pm_ops cs32g050_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(cs32g050_i2c_suspend, cs32g050_i2c_resume)
	.complete = cs32g050_i2c_complete,
};
#define CS32G050_PM_OPS (&cs32g050_pm_ops)
#else
#define CS32G050_PM_OPS (NULL)
#endif /* CONFIG_PM */

MODULE_DEVICE_TABLE(i2c, cs32g050);
static const struct of_device_id cs32g050_of_match[] = {
	{
		.compatible = "cs32g050",
		.data = NULL,
	},
	{},
};

static const struct i2c_device_id cs32g050_i2c_id[] = {
	{ "cs32g050", 0 }, {}
};

static struct i2c_driver cs32g050_driver = {
	.probe = cs32g050_probe,
	.remove = cs32g050_remove,
	.shutdown = cs32g050_shutdown,
	.id_table = cs32g050_i2c_id,
	.driver = {
		.owner = THIS_MODULE,
		.name = "cs32g050",
		.of_match_table = of_match_ptr(cs32g050_of_match),
		.pm = CS32G050_PM_OPS,
	},
};

static int __init cs32g050_init(void)
{
	return i2c_add_driver(&cs32g050_driver);
}

static void __exit cs32g050_exit(void)
{
	i2c_del_driver(&cs32g050_driver);
}

module_init(cs32g050_init);
module_exit(cs32g050_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("cs32g050 module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
