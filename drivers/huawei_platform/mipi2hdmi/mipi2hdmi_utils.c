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

#include "mipi2hdmi_utils.h"
#include "dkmd_log.h"

#define I2C_TRANSFER_LEN 2
#define XFER_ONE 1
#define XFER_TWO 2
#define MAX_I2C_TRANSFER_RETRIES 3

static const uint8_t g_edid_v1_header[EDID_HEADER_LEN] = { 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00 };

int32_t mipi2hdmi_regulator_init(struct device *dev, const char *id, uint32_t mvolt, struct regulator **ldo)
{
    int32_t ret = -EFAULT;

    dpu_check_and_return(!dev, -EINVAL, err, "[MIPI2HDMI] dev is null\n");
    dpu_check_and_return(!id, -EINVAL, err, "[MIPI2HDMI] id is null\n");
    dpu_check_and_return(!ldo, -EINVAL, err, "[MIPI2HDMI] ldo is null\n");

    *ldo = devm_regulator_get(dev, id);
    if (IS_ERR(*ldo)) {
        *ldo = NULL;
        dpu_pr_err("[MIPI2HDMI] devm_regulator_get %s failed\n", id);
        return ret;
    }
    ret = regulator_set_mode(*ldo, REGULATOR_MODE_NORMAL);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] regulator_set_mode %s failed, ret=%d\n", id, ret);
        goto err_out;
    }
    ret = regulator_set_voltage(*ldo, mvolt, mvolt);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] regulator_set_voltage %s failed, ret=%d\n", id, ret);
        goto err_out;
    }

    return 0;

err_out:
    if (*ldo != NULL) {
        (void)devm_regulator_put(*ldo);
        *ldo = NULL;
    }
    return ret;
}

int32_t mipi2hdmi_gpio_init(struct device *dev, const char *id, GPIO_DIRECTION dir,
    int32_t out_init_val, uint32_t *gpio)
{
    int32_t ret = -EFAULT;
    struct device_node *np = NULL;

    dpu_check_and_return(!dev, -EINVAL, err, "[MIPI2HDMI] dev is null\n");
    dpu_check_and_return(!id, -EINVAL, err, "[MIPI2HDMI] id is null\n");
    dpu_check_and_return(!gpio, -EINVAL, err, "[MIPI2HDMI] gpio is null\n");

    np = dev->of_node;
    dpu_check_and_return(!np, -EINVAL, err, "[MIPI2HDMI] np is null\n");

    ret = of_property_read_u32(np, id, gpio);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] get %s failed, ret=%d\n", id, ret);
        return ret;
    }
    dpu_pr_info("[MIPI2HDMI] %s=%u\n", id, *gpio);

    if (!gpio_is_valid(*gpio)) {
        dpu_pr_err("[MIPI2HDMI] %s is not valid, %s=%u\n", id, id, *gpio);
        ret = -EFAULT;
        return ret;
    }

    ret = devm_gpio_request(dev, *gpio, id);
    if (ret < 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to request %s: %u, ret=%d\n", id, *gpio, ret);
        return ret;
    }

    if (dir == GPIO_DIRECTION_INPUT) {
        ret = gpio_direction_input(*gpio);
    } else {
        ret = gpio_direction_output(*gpio, out_init_val);
    }
    if (ret < 0) {
        devm_gpio_free(dev, *gpio);
        dpu_pr_err("[MIPI2HDMI] Failed to set %s direction, ret=%d\n", id, ret);
        return ret;
    }

    return 0;
}

int32_t mipi2hdmi_i2c_send_byte(struct i2c_client *client, uint8_t regoffset, uint8_t value)
{
    int32_t ret = 0;
    uint8_t data[I2C_TRANSFER_LEN] = {0};
    struct i2c_msg msg = {0};
    int32_t retries = 0;
    int32_t xfers = XFER_ONE;

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!client->adapter, -EINVAL, err, "[MIPI2HDMI] client->adapter is null\n");

    msg.addr = client->addr;
    msg.flags = 0;
    msg.len = I2C_TRANSFER_LEN;
    msg.buf = data;
    data[0] = regoffset;
    data[1] = value;

    do {
        ret = i2c_transfer(client->adapter, &msg, xfers);
        if (ret != xfers) {
            dpu_pr_err("[MIPI2HDMI] ret=%d\n", ret);
        }
    } while (ret != xfers && ++retries < MAX_I2C_TRANSFER_RETRIES);
    dpu_pr_info("[MIPI2HDMI] client->addr=%#x regoffset=%#x value=%#x ret=%d retries=%d\n",
        client->addr, regoffset, value, ret, retries);

    return (ret == xfers) ? 0 : ret;
}

int32_t mipi2hdmi_i2c_recv_byte(struct i2c_client *client, uint8_t regoffset, uint8_t *value)
{
    int32_t ret = 0;
    struct i2c_msg msg[XFER_TWO] = {0};
    int32_t retries = 0;
    int32_t xfers = XFER_TWO;

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!client->adapter, -EINVAL, err, "[MIPI2HDMI] client->adapter is null\n");
    dpu_check_and_return(!value, -EINVAL, err, "[MIPI2HDMI] value is null\n");

    msg[0].addr = client->addr;
    msg[0].flags = 0;
    msg[0].len = 1;
    msg[0].buf = (uint8_t *)&regoffset;

    msg[1].addr = client->addr;
    msg[1].flags = I2C_M_RD;
    msg[1].len = 1;
    msg[1].buf = value;

    do {
        ret = i2c_transfer(client->adapter, msg, xfers);
        if (ret != xfers) {
            dpu_pr_err("[MIPI2HDMI] ret=%d\n", ret);
        }
    } while (ret != xfers && ++retries < MAX_I2C_TRANSFER_RETRIES);
    dpu_pr_info("[MIPI2HDMI] client->addr=%#x regoffset=%#x value=%#x ret=%d retries=%d\n",
        client->addr, regoffset, *value, ret, retries);

    return (ret == xfers) ? 0 : ret;
}

int32_t mipi2hdmi_i2c_recv_nbytes(struct i2c_client *client, uint8_t regoffset, uint8_t *data_array, uint8_t len)
{
    int32_t ret = 0;
    struct i2c_msg msg[XFER_TWO] = {0};
    int32_t retries = 0;
    int32_t xfers = XFER_TWO;

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!client->adapter, -EINVAL, err, "[MIPI2HDMI] client->adapter is null\n");
    dpu_check_and_return(!data_array, -EINVAL, err, "[MIPI2HDMI] data_array is null\n");

    if (len == 0 || len > EDID_BLOCK_LENGTH) {
        dpu_pr_err("[MIPI2HDMI] len is invalid\n");
        return -EINVAL;
    }

    msg[0].addr = client->addr;
    msg[0].flags = 0;
    msg[0].len = 1;
    msg[0].buf = (uint8_t *)&regoffset;

    msg[1].addr = client->addr;
    msg[1].flags = I2C_M_RD;
    msg[1].len = len;
    msg[1].buf = data_array;

    do {
        ret = i2c_transfer(client->adapter, msg, xfers);
        if (ret != xfers) {
            dpu_pr_err("[MIPI2HDMI] ret=%d\n", ret);
        }
    } while (ret != xfers && ++retries < MAX_I2C_TRANSFER_RETRIES);
    dpu_pr_info("[MIPI2HDMI] client->addr=%#x len=%d ret=%d retries=%d\n", client->addr, len, ret, retries);

    return (ret == xfers) ? 0 : ret;
}

int32_t mipi2hdmi_check_edid(uint8_t *edid, uint32_t edid_len)
{
    uint32_t checksum = 0;
    int32_t i = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!edid, -EINVAL, err, "[MIPI2HDMI] edid is NULL!\n");

    if (((edid_len / EDID_BLOCK_LENGTH) > MAX_EDID_BLOCK_NUM) ||
        ((edid_len % EDID_BLOCK_LENGTH) != 0) || (edid_len < EDID_BLOCK_LENGTH)) {
        dpu_pr_err("[MIPI2HDMI] Raw Data length is invalid(not the size of (128 x N , N = [1-8]) uint8_t!\n");
        return -EINVAL;
    }
    for (i = 0; i < EDID_BLOCK_LENGTH; i++) {
        checksum += edid[i];
    }
    if (checksum & 0xFF) {
        dpu_pr_err("[MIPI2HDMI] EDID checksum failed\n");
        return -EINVAL;
    }
    for (i = 0; i < EDID_HEADER_LEN; i++) {
        if (edid[i] != g_edid_v1_header[i]) {
            dpu_pr_err("[MIPI2HDMI] first uint8_ts don't match EDID version 1 header\n");
            return -EINVAL;
        }
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}
