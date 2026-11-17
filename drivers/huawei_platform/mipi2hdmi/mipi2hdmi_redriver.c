/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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

#include <linux/delay.h>
#include <securec.h>
#include "dkmd_log.h"
#include "mipi2hdmi_connector.h"
#include "mipi2hdmi_utils.h"

#define REDRIVER_XG_ADDR 0x5E
#define REDRIVER_TI_ADDR 0x5C
#define MAX_RETRY_COUNT 3
#define REDRIVER_PARAM_COUNT 2
#define REDRIVER_REG_COUNT 9

struct redriver_private {
    struct device *dev;
    struct i2c_client *client;
    uint32_t redriver_id;
    struct mipi2hdmi_redriver redriver_info;
};

struct redriver_reg_value {
    uint8_t reg_addr;
    uint8_t reg_value;
};

static struct redriver_reg_value xg_reg_values[REDRIVER_PARAM_COUNT][REDRIVER_REG_COUNT] = {
    {
        { 0x09, 0x12 },
        { 0x0A, 0x43 },
        { 0x0B, 0xD0 },
        { 0x0C, 0x01 },
        { 0x0D, 0x06 },
        { 0x31, 0x60 },
        { 0x32, 0x60 },
        { 0x33, 0x60 },
        { 0x34, 0x60 }
    },
    {
        { 0x09, 0x12 },
        { 0x0A, 0x43 },
        { 0x0B, 0xD0 },
        { 0x0C, 0x60 },
        { 0x0D, 0x06 },
        { 0x31, 0x60 },
        { 0x32, 0x60 },
        { 0x33, 0x60 },
        { 0x34, 0x60 }
    }
};

static struct redriver_reg_value ti_reg_values[REDRIVER_PARAM_COUNT][REDRIVER_REG_COUNT] = {
    {
        { 0x09, 0x12 },
        { 0x0A, 0x43 },
        { 0x0B, 0xC0 },
        { 0x0C, 0xD8 },
        { 0x0D, 0x00 },
        { 0x31, 0x60 },
        { 0x32, 0x60 },
        { 0x33, 0x60 },
        { 0x34, 0x60 }
    },
    {
        { 0x09, 0x12 },
        { 0x0A, 0x43 },
        { 0x0B, 0xDA },
        { 0x0C, 0x40 },
        { 0x0D, 0x00 },
        { 0x31, 0x60 },
        { 0x32, 0x60 },
        { 0x33, 0x60 },
        { 0x34, 0x60 }
    }
};

static inline struct redriver_private *to_redriver_private(struct mipi2hdmi_redriver *redriver)
{
    return container_of(redriver, struct redriver_private, redriver_info);
}

static int32_t redriver_do_configure_device(struct i2c_client *client,
    struct redriver_reg_value *reg_values, int32_t count)
{
    int32_t ret = 0;
    int32_t i = 0;
    int32_t retry_cnt = 0;
    int32_t index = 0;

    dpu_pr_info("[MIPI2HDMI] +");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!reg_values, -EINVAL, err, "[MIPI2HDMI] reg_values is null\n");

    if (count <= 0 || count > REDRIVER_REG_COUNT) {
        dpu_pr_err("[MIPI2HDMI] count is invalid\n");
        return -EINVAL;
    }

    do {
        for (i = index; i < count; i++) {
            ret = mipi2hdmi_i2c_send_byte(client, reg_values[i].reg_addr, reg_values[i].reg_value);
            if (ret != 0) {
                dpu_pr_err("[MIPI2HDMI] failed to write to %#x register, ret=%d\n", reg_values[i].reg_addr, ret);
                index = i;
                break;
            }
        }
        dpu_pr_info("[MIPI2HDMI] retry_cnt=%d\n", retry_cnt);
    } while (ret != 0 && ++retry_cnt < MAX_RETRY_COUNT);

    dpu_pr_info("[MIPI2HDMI] -");

    return ret;
}

static int32_t redriver_configure_device(struct mipi2hdmi_redriver *redriver, MIPI2HDMI_PROTO_VERSION proto_ver)
{
    int32_t ret = 0;
    struct redriver_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +");

    dpu_check_and_return(!redriver, -EINVAL, err, "[MIPI2HDMI] redriver is null\n");
    priv = to_redriver_private(redriver);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->client, -EINVAL, err, "[MIPI2HDMI] priv->client is null\n");

    if (proto_ver < HDMI_PROTO_VERSION_1DOT4 || proto_ver > HDMI_PROTO_VERSION_2DOT0) {
        dpu_pr_err("[MIPI2HDMI] proto_ver is invalid, proto_ver=%d\n", proto_ver);
        return -EINVAL;
    }

    switch (priv->client->addr) {
        case REDRIVER_TI_ADDR:
            ret = redriver_do_configure_device(priv->client, &ti_reg_values[proto_ver][0], REDRIVER_REG_COUNT);
            if (ret != 0) {
                dpu_pr_err("[MIPI2HDMI] ti failed to configure registers, ret=%d\n", ret);
                return ret;
            }
            break;
        case REDRIVER_XG_ADDR:
            ret = redriver_do_configure_device(priv->client, &xg_reg_values[proto_ver][0], REDRIVER_REG_COUNT);
            if (ret != 0) {
                dpu_pr_err("[MIPI2HDMI] xg failed to configure registers, ret=%d\n", ret);
                return ret;
            }
            break;
        default:
            dpu_pr_warn("[MIPI2HDMI] chip addr mismatch, chip addr=%#x\n", priv->client->addr);
            ret = -ENODEV;
            break;
    }

    dpu_pr_info("[MIPI2HDMI] -");

    return ret;
}

static int32_t redriver_register_device(struct redriver_private *priv)
{
    int32_t ret = 0;
    struct device_node *np = NULL;

    dpu_pr_info("[MIPI2HDMI] +");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->dev, -EINVAL, err, "[MIPI2HDMI] priv->dev is null\n");
    np = priv->dev->of_node;
    dpu_check_and_return(!np, -EINVAL, err, "[MIPI2HDMI] np is null\n");

    ret = of_property_read_u32(np, "redriver_id", &priv->redriver_id);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to read redriver_id from dts, ret=%d\n", ret);
        return ret;
    }

    priv->redriver_info.redriver_id = priv->redriver_id;
    priv->redriver_info.configure_func = redriver_configure_device;
    ret = mipi2hdmi_register_redriver(&priv->redriver_info);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] failed to register redriver, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -");

    return 0;
}

static void redriver_unregister_device(struct redriver_private *priv)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");

    (void)mipi2hdmi_unregister_redriver(&priv->redriver_info);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static void redriver_free_mem(struct redriver_private *priv)
{
    struct i2c_client *client = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");
    client = priv->client;
    dpu_check_and_no_retval(!client, err, "[MIPI2HDMI] client is null\n");

    i2c_set_clientdata(client, NULL);
    devm_kfree(&client->dev, priv);
    priv = NULL;

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static int32_t redriver_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    int32_t ret = 0;
    struct i2c_adapter *adapter = NULL;
    struct redriver_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    adapter = client->adapter;
    dpu_check_and_return(!adapter, -EINVAL, err, "[MIPI2HDMI] adapter is null\n");

    if (!i2c_check_functionality(adapter, I2C_FUNC_I2C)) {
        dpu_pr_err("[MIPI2HDMI] failed to i2c_check_functionality!\n");
        return -EOPNOTSUPP;
    }
    ret = i2c_smbus_read_byte(client);
    if (ret < 0) {
        dpu_pr_warn("[MIPI2HDMI] nothing at this address: %#x\n", client->addr);
        return -ENXIO;
    }

    priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
    dpu_check_and_return(!priv, -ENOMEM, err, "[MIPI2HDMI] alloc redriver driver private data failed!\n");

    priv->dev = &client->dev;
    priv->client = client;
    i2c_set_clientdata(client, priv);

    if (redriver_register_device(priv)) {
        dpu_pr_err("[MIPI2HDMI] failed to register device!\n");
        goto err_out;
    }

    dpu_pr_info("[MIPI2HDMI] chip addr=%#x\n", client->addr);

    dpu_pr_info("[MIPI2HDMI] -");

    return 0;

err_out:
    redriver_free_mem(priv);
    return -EPROBE_DEFER;
}

static int32_t redriver_i2c_remove(struct i2c_client *client)
{
    int32_t ret = 0;
    struct redriver_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    priv = i2c_get_clientdata(client);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    redriver_unregister_device(priv);
    redriver_free_mem(priv);

    dpu_pr_info("[MIPI2HDMI] -");

    return 0;
}

static const struct i2c_device_id redriver_i2c_ids[] = {
    { "ti,tdp158", 0 },
    { "xg,xg8610", 0 },
    {}
};

static const struct of_device_id redriver_i2c_of_ids[] = {
    {.compatible = "ti,tdp158"},
    {.compatible = "xg,xg8610"},
    {}
};

static struct i2c_driver redriver_i2c_driver = {
    .driver = {
        .name = "redriver",
        .of_match_table = redriver_i2c_of_ids,
    },
    .id_table = redriver_i2c_ids,
    .probe = redriver_i2c_probe,
    .remove = redriver_i2c_remove,
};

static int32_t __init redriver_init(void)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    ret = i2c_add_driver(&redriver_i2c_driver);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] failed to i2c_add_driver, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static void __exit redriver_exit(void)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    i2c_del_driver(&redriver_i2c_driver);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

module_init(redriver_init);
module_exit(redriver_exit);

MODULE_AUTHOR("Graphics Display");
MODULE_DESCRIPTION("Huawei redriver driver");
MODULE_LICENSE("GPL");
