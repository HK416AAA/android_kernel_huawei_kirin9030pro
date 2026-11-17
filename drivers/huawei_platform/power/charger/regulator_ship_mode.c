#include <securec.h>
#include <linux/delay.h>
#include <chipset_common/hwpower/common_module/power_debug.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/hardware_monitor/ship_mode.h>
#include <chipset_common/log/hw_log.h>
#include <linux/regulator/consumer.h>
 
#define HWLOG_TAG regulator_ship_mode
HWLOG_REGIST();
 
#define REGULATOR_DEFAULT_NAME            "pmu0_vcon"
#define REGULATOR_DEFAULT_VOLTAGE_VALUE    2500000
#define REGULATOR_DEFAULT_MAX_RETRIES      3

struct regulator_ship_mode_device_info {
 	struct device *dev;
 	const char *regulator_name;
 	unsigned int voltage_value;
	struct regulator *regulator_dev;
 };
static struct regulator_ship_mode_device_info *g_di;
 
static inline void regulator_ship_mode_parse_dts(struct regulator_ship_mode_device_info *di,
	struct device_node *np)
{
	int ret;
	ret = of_property_read_string(np, "regulator_name", &di->regulator_name);
	if (ret) {
		hwlog_err("get regulator_name fail\n");
		di->regulator_name = REGULATOR_DEFAULT_NAME;
	}
 
	ret = of_property_read_u32(np, "voltage_value", &di->voltage_value);
	if (ret) {
		hwlog_err("get voltage_value fail\n");
		di->voltage_value = REGULATOR_DEFAULT_VOLTAGE_VALUE;
	}
}
 
static void regulator_ship_mode_set_entry_time(unsigned int time, void *dev_data)
{
	hwlog_err("set_entry_time: value=%u\n", time);
}
 
static void regulator_ship_mode_set_work_mode(unsigned int mode, void *dev_data)
{
	int ret, retry;
	if (!g_di)
		return;
 
	if ((mode != SHIP_MODE_IN_SHIP) && (mode != SHIP_MODE_IN_SHUTDOWN_SHIP))
		return;
 
	for (retry = 0; retry < REGULATOR_DEFAULT_MAX_RETRIES; retry++) {
		ret = regulator_set_voltage(g_di->regulator_dev, g_di->voltage_value, g_di->voltage_value);
		if (ret == 0)
			break;
		hwlog_err("regulator set voltage failed, retry %d, rc = %d\n", retry + 1, ret);
		msleep(500);
	}
	if (ret) {
		hwlog_err("regulator set voltage failed after %d retries, rc = %d\n", REGULATOR_DEFAULT_MAX_RETRIES, ret);
		return;
	}

	for (retry = 0; retry < REGULATOR_DEFAULT_MAX_RETRIES; retry++) {
		ret = regulator_enable(g_di->regulator_dev);
		if (ret == 0)
			break;
		hwlog_err("regulator enable failed, retry %d, rc = %d\n", retry + 1, ret);
		msleep(500);
	}
	if (ret) {
		hwlog_err("regulator enable failed after %d retries, rc = %d\n", REGULATOR_DEFAULT_MAX_RETRIES, ret);
		return;
	}
	hwlog_err("[%s] mode to ship success!\n", __func__);
}
 
static struct ship_mode_ops huawei_regulator_ship_mode_ops = {
	.ops_name = "huawei_regulator_ship_mode",
	.set_entry_time =regulator_ship_mode_set_entry_time,
	.set_work_mode = regulator_ship_mode_set_work_mode,
};
 
static int regulator_ship_mode_probe(struct platform_device *pdev)
{
	g_di = kzalloc(sizeof(*g_di), GFP_KERNEL);
	if (!g_di)
		return -ENOMEM;
 
	g_di->dev = &pdev->dev;
	regulator_ship_mode_parse_dts(g_di, g_di->dev->of_node);
	g_di->regulator_dev = devm_regulator_get(g_di->dev, g_di->regulator_name);
	if (IS_ERR(g_di->regulator_dev) || !g_di->regulator_dev) {
		hwlog_err("regulator get failed regulator rc = %d\n", PTR_ERR(g_di->regulator_dev));
		kfree(g_di);
		g_di = NULL;
		return -ENODEV;
	}
	
	ship_mode_ops_register(&huawei_regulator_ship_mode_ops, SHIP_MODE_IC_TYPE_PLATFORM);
	hwlog_err("regulator ship mode probe ok\n");
	return 0;
}
 
static int regulator_ship_mode_remove(struct platform_device *pdev)
{
	if (!g_di)
		return -ENODEV;
 
    kfree(g_di);
	g_di = NULL;
	hwlog_err("regulator ship mode remove ok\n");
	return 0;
}
 
static struct of_device_id regulator_ship_mode_match_table[] = {
	{
		.compatible = "huawei,regulator_ship_mode",
		.data = NULL,
	},
	{},
};
 
static struct platform_driver regulator_ship_mode_driver = {
	.probe = regulator_ship_mode_probe,
	.remove = regulator_ship_mode_remove,
	.driver = {
		.name = "huawei,regulator_ship_mode",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(regulator_ship_mode_match_table),
	},
};
 
static int __init regulator_ship_mode_init(void)
{
	return platform_driver_register(&regulator_ship_mode_driver);
}
 
static void __exit regulator_ship_mode_exit(void)
{
	platform_driver_unregister(&regulator_ship_mode_driver);
}
 
module_init(regulator_ship_mode_init);
module_exit(regulator_ship_mode_exit);
 
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("regulator ship mode module driver");
MODULE_AUTHOR("HUAWEI Inc");