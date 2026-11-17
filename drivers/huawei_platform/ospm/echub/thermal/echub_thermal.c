/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 * thermal driver for echub
 */

#include <securec.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/thermal.h>
#include <linux/log2.h>
#include "ospm_printf.h"
#include "echub_i2c.h"

#define SENSOR_NAME_STR_MAX_LEN		(30)
#define SENSOR_NUMBER_MAX_LEN		(20)
#define ODVP_RETURN_MAX_LEN		    (13)
#define LCP_RETURN_MAX_LEN		    (3)
#define ECHUB_I2C_NTC_DTAT_MAXLEN	(5)
#define ECHUB_I2C_FAN_SPEED_MAXLEN	(5)
#define ECHUB_I2C_TTL_POWER_MAXLEN	(4)
#define NTC_TEMP_INVALID			(-23)
#define ECHUB_NTC_REG				(0x0261)
#define ECHUB_FAN_SPEED				(0x027c)
#define ECHUB_TOTAL_POWER           (0x025b)
#define ECHUB_ODVP                  (0x02e7)
#define ECHUB_LCP_ICSTATUS          (0x0484)

#define SENSOR_INIT_SUCCESS			(1)
#define SENSOR_INIT_FAILED			(0)

#define ECHUB_LCP_CHIP_INVALID      	(0)
#define ECHUB_LCP_CHIP_VALID        	(1)
#define ECHUB_LCP_STATUS_IDLE       	(0)
#define ECHUB_LCP_STATUS_CALIBRATION    (1)
#define ECHUB_LCP_STATUS_RUN       		(2)
#define ECHUB_LCP_STATUS_ERROR       	(3)
#define ECHUB_LCP_CALIBRATION_RETURN    (-8)
#define ECHUB_LCP_ERROR_RETURN    		(-90)
#define ECHUB_LCP_GEAR1_RUN_RETURN      (1)
#define ECHUB_LCP_GEAR2_RUN_RETURN      (2)
#define ECHUB_LCP_GEAR3_RUN_RETURN      (3)
#define ECHUB_LCP_GEAR4_RUN_RETURN      (4)
#define ECHUB_LCP_GEAR5_RUN_RETURN      (5)
// sensor type---process function---reg---regoffset---outputbufLen
typedef int (*thermal_data_process_function)(int regoffset, char regdata, int *temp);

struct echub_channel_sensor_info {
	thermal_data_process_function process;
	unsigned int regoffset;
	int regdata;
	int bytes;
	int lastTemp;
	char sensor_type[SENSOR_NAME_STR_MAX_LEN];
	bool init_success;
};

struct echub_ntc_sensor {
	char sensor_type[SENSOR_NAME_STR_MAX_LEN];
	unsigned int sensor_id;
	struct thermal_zone_device *tz_dev;
};

struct echub_thermal_priv {
	struct device *dev;
	struct echub_ntc_sensor sensor[SENSOR_NUMBER_MAX_LEN];
	struct echub_i2c_dev *echub_dev;
	unsigned int sensor_num;
};

static struct echub_thermal_priv *g_echub_tz_info = NULL;

static struct echub_channel_sensor_info *g_echub_sensor_info = NULL;

static int get_fan_speed_from_ec(int regoffset, char regdata, int *temp)
{
	char value[ECHUB_I2C_FAN_SPEED_MAXLEN] = {0};

	int ret = g_echub_tz_info->echub_dev->read_func(g_echub_tz_info->echub_dev, regoffset, regdata, value, sizeof(value));
	if (ret) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}
	*temp = (value[NUM_3] << NUM_8) + value[NUM_2];

	return 0;
}

static int get_ntc_data_from_ec(int regoffset, char regdata, int *temp)
{
	char value[ECHUB_I2C_NTC_DTAT_MAXLEN] = {0};

	int ret = g_echub_tz_info->echub_dev->read_func(g_echub_tz_info->echub_dev, regoffset, regdata, value, sizeof(value));
	if (ret != 0) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}
	*temp = ((value[NUM_3] << NUM_8) + value[NUM_2]) * NUM_100;

	return 0;
}

static int get_total_power_data_from_ec(int regoffset, char regdata, int *temp)
{
	char value[ECHUB_I2C_TTL_POWER_MAXLEN] = {0};

	int ret = g_echub_tz_info->echub_dev->read_func(g_echub_tz_info->echub_dev, regoffset, regdata, value, sizeof(value));
	if (ret != 0) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}
	*temp = value[NUM_2];

	return 0;
}

static int get_odvp_data_from_ec(int regoffset, char regdata, int *temp)
{
	char value[ODVP_RETURN_MAX_LEN] = {0};

	int ret = g_echub_tz_info->echub_dev->transfer_func(g_echub_tz_info->echub_dev, regoffset, NULL, 0,
														value, sizeof(value));
	if (ret != 0) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}

	*temp = value[regdata % ODVP_RETURN_MAX_LEN];

	return 0;
}

static int get_return_value(char isvalid, char icstatus, char errlist)
{
	int ret = 0xff; /* 0xff means error code */

	if (isvalid == ECHUB_LCP_CHIP_INVALID)
		ret = -1;
	if (icstatus == ECHUB_LCP_STATUS_IDLE)
		ret = 0;
	else if (icstatus == ECHUB_LCP_STATUS_CALIBRATION)
		ret = ECHUB_LCP_CALIBRATION_RETURN;
	else if (icstatus == ECHUB_LCP_STATUS_RUN)
		ret = ECHUB_LCP_GEAR1_RUN_RETURN;
	else if (icstatus == ECHUB_LCP_STATUS_ERROR)
		ret = ECHUB_LCP_ERROR_RETURN - ilog2(errlist);

	return ret;
}

static int get_lcp_icstatus_from_ec(int regoffset, char regdata, int *temp)
{
	char value[LCP_RETURN_MAX_LEN] = {0};

	int ret = g_echub_tz_info->echub_dev->transfer_func(g_echub_tz_info->echub_dev, regoffset, NULL, 0,
														value, sizeof(value));
	if (ret != 0) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}

	*temp = get_return_value(value[0], value[1], value[2]); /* 2 means read 2 bytes */

	return 0;
}

/* get process func */
static thermal_data_process_function get_process_func(unsigned int regoffset)
{
	static struct echub_channel_sensor_info {
		int regoffset;
		thermal_data_process_function process;
	} process_tbl[] = {
		{ ECHUB_NTC_REG,      get_ntc_data_from_ec         },
		{ ECHUB_FAN_SPEED,    get_fan_speed_from_ec        },
		{ ECHUB_TOTAL_POWER,  get_total_power_data_from_ec },
		{ ECHUB_ODVP,         get_odvp_data_from_ec        },
		{ ECHUB_LCP_ICSTATUS, get_lcp_icstatus_from_ec     }
	};
	int i;
	int tbl_size = sizeof(process_tbl) / sizeof(process_tbl[0]);

    for (i = 0; i < tbl_size; i++) {
        if (process_tbl[i].regoffset == regoffset) {
            return process_tbl[i].process;
        }
    }

	return NULL;
}

static void get_thermal_data_from_ec(struct thermal_zone_device *thermal, int *temp)
{
	int i, ret;
	int raw_temp = NTC_TEMP_INVALID;

	for (i = 0; i < g_echub_tz_info->sensor_num; i++) {
		if (!g_echub_sensor_info[i].init_success) {
			echub_err("%s failed %d ret = %d\n", __func__, __LINE__, i);
			return;
		}
		if (strncmp(g_echub_sensor_info[i].sensor_type, thermal->type, strlen(thermal->type)) == 0) {
			if (g_echub_sensor_info[i].process == NULL) {
				echub_err("%s failed %d sensor:%s\n", __func__, __LINE__, thermal->type);
				return;
			}
			ret = g_echub_sensor_info[i].process(g_echub_sensor_info[i].regoffset, g_echub_sensor_info[i].regdata, &raw_temp);
			if (ret != 0) {
				echub_err("%s failed %d ret = %d sensor:%s\n", __func__, __LINE__, ret, thermal->type);
				*temp = g_echub_sensor_info[i].lastTemp;
				return;
			}
			g_echub_sensor_info[i].lastTemp = raw_temp;
			break;
		}
	}
	*temp = raw_temp;

	return;
}

static int echub_thermal_get_temp(struct thermal_zone_device *thermal, int *temp)
{
	if (!thermal || !temp) {
		echub_err("[%s:%dL] input params NULL\n", __func__, __LINE__);
		return -EINVAL;
	}

	get_thermal_data_from_ec(thermal, temp);

	return 0;
}

static struct thermal_zone_device_ops echub_thermal_ops = {
	.get_temp = echub_thermal_get_temp,
};

static void echub_fill_sensor_info_from_dts(struct device_node *echub_sensor_np, struct echub_thermal_priv *info)
{
	int i;
	int ret;
	char node_name[SENSOR_NAME_STR_MAX_LEN] = { 0 };
	unsigned int sensor_id;
	unsigned int sensor_reg;
	const char *sensor_type = NULL;
	struct device_node *echub_sensor_regnp = NULL;

	for (i = 0; i < info->sensor_num; i++) {
		g_echub_sensor_info[i].lastTemp = NTC_TEMP_INVALID;

		(void)sprintf_s(node_name, sizeof(node_name), "sensor%d", i);
		echub_sensor_regnp = of_get_child_by_name(echub_sensor_np, node_name);

		ret = of_property_read_string(echub_sensor_regnp, "sensor_name", &sensor_type);
		if (ret < 0) {
			echub_err("%s failed %d\n", __func__, __LINE__);
			continue;
		}
		ret = strcpy_s(info->sensor[i].sensor_type, sizeof(info->sensor[i].sensor_type), sensor_type);
		ret |= strcpy_s(g_echub_sensor_info[i].sensor_type, sizeof(g_echub_sensor_info[i].sensor_type), sensor_type);
		if (ret != 0) {
			echub_err("%s failed %d\n", __func__, __LINE__);
			continue;
		}

		ret = of_property_read_u32(echub_sensor_regnp, "sensor_id", &sensor_id);
		if (ret < 0) {
			echub_err("%s failed %d\n", __func__, __LINE__);
			continue;
		}
		info->sensor[i].sensor_id = sensor_id;
		g_echub_sensor_info[i].regdata = sensor_id;

		ret = of_property_read_u32(echub_sensor_regnp, "sensor_reg", &sensor_reg);
		if (ret < 0) {
			echub_err("%s failed %d\n", __func__, __LINE__);
			continue;
		}
		g_echub_sensor_info[i].regoffset = sensor_reg;
		g_echub_sensor_info[i].process = get_process_func(sensor_reg);
		g_echub_sensor_info[i].init_success = SENSOR_INIT_SUCCESS;
		echub_info("i = [%d] sensor_type %s, sensor_id %d sensor_reg %d\n", i, g_echub_sensor_info[i].sensor_type,
			g_echub_sensor_info[i].regdata, g_echub_sensor_info[i].regoffset);
	}

	of_node_put(echub_sensor_regnp);

	return;
}

static int echub_thermal_parse_dts(struct device_node *dev_node, struct echub_thermal_priv *info)
{
	struct device_node *echub_sensor_np = NULL;

	echub_sensor_np = of_get_child_by_name(dev_node, "sensors");
	if (echub_sensor_np == NULL) {
		echub_err("%s failed %d not find sensors sub-node\n", __func__, __LINE__);
		return -EINVAL;
	}
	info->sensor_num = of_get_child_count(echub_sensor_np);
	echub_info("%s huawei,sensor_num %d\n", __func__, info->sensor_num);

	if (info->sensor_num > SENSOR_NUMBER_MAX_LEN) {
		echub_err("%s sensor num [%d] error!\n", __func__, info->sensor_num);
		return -EINVAL;
	}

	int sensor_info_size = sizeof(*g_echub_sensor_info) * info->sensor_num;
	g_echub_sensor_info = kzalloc(sensor_info_size, GFP_KERNEL);
	if (g_echub_sensor_info == NULL) {
		return -ENOMEM;
	}
	(void)memset_s(g_echub_sensor_info, sensor_info_size, 0, sensor_info_size);

	echub_fill_sensor_info_from_dts(echub_sensor_np, info);
	of_node_put(echub_sensor_np);

	return 0;
}

static int echub_thermal_probe(struct platform_device *pdev)
{
	int i, ret, flag = 0;

	if (!pdev || !pdev->dev.parent || !pdev->dev.of_node) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}

	struct echub_i2c_dev *echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (echub_dev == NULL) {
		echub_err("echub_dev is null, get echub_dev form tmp\n");
		echub_dev = get_echub_dev();
		if (echub_dev == NULL) {
			return -ENODEV;
		}
	}

	struct echub_thermal_priv *priv = devm_kzalloc(&pdev->dev, sizeof(struct echub_thermal_priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	g_echub_tz_info = priv;
	priv->dev = &pdev->dev;
	priv->echub_dev = echub_dev;

	ret = echub_thermal_parse_dts(priv->dev->of_node, priv);
	if (ret < 0)
		goto fail_parse_dts;

	for (i = 0; i < priv->sensor_num; i++) {
		priv->sensor[i].tz_dev = thermal_zone_device_register(priv->sensor[i].sensor_type, 0, 0, priv,
															  &echub_thermal_ops, NULL, 0, 0);
		if (IS_ERR(priv->sensor[i].tz_dev)) {
			ret = -ENODEV;
			goto fail_register_tz;
		}
		flag++;
	}
	platform_set_drvdata(pdev, priv);
	return 0;

fail_register_tz:
	for (i = 0; i < flag; i++) {
		thermal_zone_device_unregister(priv->sensor[i].tz_dev);
	}

fail_parse_dts:
	of_node_put(priv->dev->of_node);
	g_echub_tz_info = NULL;
	if (g_echub_sensor_info != NULL)
		kfree(g_echub_sensor_info);
	g_echub_sensor_info = NULL;

	return ret;
}

static int echub_thermal_remove(struct platform_device *pdev)
{
	int i;
	struct echub_thermal_priv *priv = NULL;

	echub_info("%s enter\n", __func__);
	if (!pdev) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	priv = platform_get_drvdata(pdev);
	if (!priv) {
		echub_err("%s failed %d\n", __func__, __LINE__);
		return -ENODEV;
	}

	for (i = 0; i < priv->sensor_num; i++) {
		thermal_zone_device_unregister(priv->sensor[i].tz_dev);
	}
	platform_set_drvdata(pdev, NULL);
	g_echub_tz_info = NULL;
	if (g_echub_sensor_info != NULL) {
		kfree(g_echub_sensor_info);
	}
	g_echub_sensor_info = NULL;

	return 0;
}

static const struct of_device_id echub_thermal_match[] = {
	{
		.compatible = "huawei,echub_thermal",
		.data = NULL,
	},
	{},
};

static struct platform_driver echub_thermal_driver = {
	.probe = echub_thermal_probe,
	.remove = echub_thermal_remove,
	.driver = {
		.name = "huawei,echub_thermal",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(echub_thermal_match),
	},
};

static int __init echub_thermal_init(void)
{
	return platform_driver_register(&echub_thermal_driver);
}

static void __exit echub_thermal_exit(void)
{
	platform_driver_unregister(&echub_thermal_driver);
}

module_init(echub_thermal_init);
module_exit(echub_thermal_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei pc echub thermal driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
