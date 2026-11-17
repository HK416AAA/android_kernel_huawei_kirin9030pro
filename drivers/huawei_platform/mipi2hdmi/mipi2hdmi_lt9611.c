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
#ifdef CONFIG_SYS_PM_ULSR
#include <platform_include/cee/linux/ulsr.h>
#endif
#include <securec.h>
#include "dkmd_log.h"
#include "mipi2hdmi_connector.h"
#include "mipi2hdmi_utils.h"
#include "mipi2hdmi_lt9611.h"

#define LT9611_CHIP_MODEL "lt9611"
#define LT9611_UXC_DEV_ADDR 0x2B
#define LT9611_UXD_DEV_ADDR 0x41
#define LT9611_LDO_3V3 3300000
#define LT9611_LDO_1V2 1200000
#define LT9611_UXC_EDID_INT_MASK 0x01
#define LT9611_UXC_EDID_BLOCK_NUM_MASK 0x0F
#define LT9611_UXC_EDID_READY_MASK 0x10
#define LT9611_UXC_EDID_WAIT_TIME 5
#define LT9611_UXC_EDID_WAIT_COUNT 10
#define LT9611_UXC_EDID_BLOCK_CAPACITY 2
#define LT9611_UXC_TIMING_REG_COUNT 15
#define LT9611_UXD_EDID_INT_MASK 0x04
#define LT9611_UXD_INT_CLEAR_INTERVAL 10
#define LT9611_UXD_CHECK_READY_INTERVAL 1
#define LT9611_UXD_CHECK_READY_COUNT 200
#define LT9611_UXD_COMM_F_ACK 0x41
#define LT9611_UXD_COMM_M_HDMI 0x48
#define LT9611_UXD_COMM_M_MIPI 0x4D
#define LT9611_UXD_COMM_DELIMITER 0x3A
#define LT9611_UXD_CMD_BUF_LEN 5
#define LT9611_UXD_EDID_SIZE_BUF_LEN 6
#define LT9611_UXD_EDID_DATA_BUF_LEN 37
#define LT9611_UXD_TIMING_REQ_LEN 26
#define LT9611_UXD_TIMING_ACK_LEN 3
#define LT9611_UXD_EDID_PACKET_SIZE 32
#define LT9611_UXD_REQ_PACKET_MIN_SIZE 5
#define LT9611_UXD_REQ_PACKET_MAX_SIZE 26
#define LT9611_UXD_ACK_PACKET_MIN_SIZE 3
#define LT9611_UXD_ACK_PACKET_MAX_SIZE 37
#define LT9611_FW_UPDATE_TIMEOUT 60000
#define SHIFT_EIGHT_BITS 8
#define LDO_3V3_DELAY_TIME_MS 2
#define LDO_1V2_DELAY_TIME_MS 2
#define RDV_OE_DELAY_TIME_MS 2
#define RST_DELAY_TIME_MS 20
#define I2S_DELAY_TIME_MS 2
#ifndef MIN
#define MIN(x, y)  ((x) < (y) ? (x) : (y))
#endif

enum lt9611_error_codes {
    EFW_UPDATE_ONGOING = 0x10101,
    EINT_NOT_EDID_READY,
    EREAD_EDID_FAILED,
    EINVALID_BLOCK_NUM,
    EUXC_EDID_READ_TIMEOUT,
    EUXD_CHECK_READY_TIMEOUT,
    EUXD_ACK_HEADER_WRONG,
    EINVALID_DATA_SIZE
};

struct lt9611_private {
    struct device *dev;
    struct i2c_client *client;
    uint32_t bridge_id;
    struct regulator *ldo_3v3;
    uint32_t delay_3v3;
    struct regulator *ldo_1v2;
    uint32_t delay_1v2;
    uint32_t rst_gpio;
    uint32_t delay_rst;
    uint32_t rdv_oe_gpio;
    uint32_t delay_rdv_oe;
    uint32_t chip_id_gpio;
    uint32_t i2s_gpio;
    uint32_t delay_i2s;
    struct mipi2hdmi_bridge bridge_info;
    atomic_t fw_update_ongoing_atom;
    struct delayed_work fw_update_timeout_work;
};

static struct lt9611_fw_updater *g_lt9611_fw_updater = NULL;

int32_t lt9611_register_fw_updater(struct lt9611_fw_updater *updater)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!updater, -EINVAL, err, "[MIPI2HDMI] updater is null\n");

    if (strcmp(updater->chip_model, LT9611_CHIP_MODEL) != 0) {
        dpu_pr_err("[MIPI2HDMI] register fw updater, chip model mismatch\n");
        return -EINVAL;
    }
    if (!updater->update_firmware) {
        dpu_pr_err("[MIPI2HDMI] update_firmware is null\n");
        return -EINVAL;
    }
    g_lt9611_fw_updater = updater;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

int32_t lt9611_unregister_fw_updater(struct lt9611_fw_updater *updater)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!updater, -EINVAL, err, "[MIPI2HDMI] updater is null\n");

    if (strcmp(updater->chip_model, LT9611_CHIP_MODEL) != 0) {
        dpu_pr_err("[MIPI2HDMI] unregister fw upater, chip model mismatch\n");
        return -EINVAL;
    }
    g_lt9611_fw_updater = NULL;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static inline struct lt9611_private *to_lt9611_private(struct mipi2hdmi_bridge *bridge)
{
    return container_of(bridge, struct lt9611_private, bridge_info);
}

static int32_t lt9611_power_on_sequence(struct i2c_client *client)
{
    int32_t ret = 0;
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    priv = i2c_get_clientdata(client);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->ldo_3v3, -EINVAL, err, "[MIPI2HDMI] priv->ldo_3v3 is null\n");
    dpu_check_and_return(!priv->ldo_1v2, -EINVAL, err, "[MIPI2HDMI] priv->ldo_1v2 is null\n");

    if (atomic_read(&priv->fw_update_ongoing_atom) == FW_UPDATE_STATUS_ONGOING ||
        atomic_read(&priv->fw_update_ongoing_atom) == FW_UPDATE_STATUS_ONGOING_POWER_OFF) {
        dpu_pr_err("[MIPI2HDMI] fw update ongoing, power on is not allowed\n");
        return -EBUSY;
    }

    dpu_pr_info("[MIPI2HDMI] enable ldo_3v3\n");
    ret = regulator_enable(priv->ldo_3v3);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] regulator_enable ldo_3v3 failed, ret=%d\n", ret);
        return ret;
    }
    mdelay(priv->delay_3v3);

    dpu_pr_info("[MIPI2HDMI] enable ldo_1v2\n");
    ret = regulator_enable(priv->ldo_1v2);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] regulator_enable ldo_1v2 failed, ret=%d\n", ret);
        (void)regulator_disable(priv->ldo_3v3);
        return ret;
    }
    mdelay(priv->delay_1v2);

    if (!gpio_is_valid(priv->rst_gpio)) {
        dpu_pr_err("[MIPI2HDMI] rst_gpio is invalid, rst_gpio=%u\n", priv->rst_gpio);
        return -EINVAL;
    }
    gpio_set_value(priv->rst_gpio, GPIO_HIGH_VOLTAGE);

    if (!gpio_is_valid(priv->rdv_oe_gpio)) {
        dpu_pr_err("[MIPI2HDMI] rdv_oe_gpio is invalid, rdv_oe_gpio=%u\n", priv->rdv_oe_gpio);
        return -EINVAL;
    }
    gpio_set_value(priv->rdv_oe_gpio, GPIO_HIGH_VOLTAGE);
    mdelay(priv->delay_rdv_oe);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_deassert_reset(struct mipi2hdmi_bridge *bridge)
{
    int32_t ret = 0;
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");
    priv = to_lt9611_private(bridge);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    mdelay(priv->delay_rst);
    if (!gpio_is_valid(priv->rst_gpio)) {
        dpu_pr_err("[MIPI2HDMI] rst_gpio is invalid, rst_gpio=%u\n", priv->rst_gpio);
        return -EINVAL;
    }
    gpio_set_value(priv->rst_gpio, GPIO_LOW_VOLTAGE);

    dpu_pr_info("[MIPI2HDMI] deassert reset done\n");

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_power_on(struct mipi2hdmi_bridge *bridge)
{
    int32_t ret = 0;
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");
    priv = to_lt9611_private(bridge);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->client, -EINVAL, err, "[MIPI2HDMI] priv->client is null\n");

    ret = lt9611_power_on_sequence(priv->client);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] power on sequence failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] power on done\n");

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_power_off_sequence(struct i2c_client *client)
{
    int32_t ret = 0;
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    priv = i2c_get_clientdata(client);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->ldo_1v2, -EINVAL, err, "[MIPI2HDMI] priv->ldo_1v2 is null\n");
    dpu_check_and_return(!priv->ldo_3v3, -EINVAL, err, "[MIPI2HDMI] priv->ldo_3v3 is null\n");

    if (atomic_read(&priv->fw_update_ongoing_atom) == FW_UPDATE_STATUS_ONGOING) {
        dpu_pr_err("[MIPI2HDMI] fw update ongoing, power off is not allowed\n");
        return -EBUSY;
    }

    if (!gpio_is_valid(priv->i2s_gpio)) {
        dpu_pr_err("[MIPI2HDMI] i2s_gpio is invalid, i2s_gpio=%u\n", priv->i2s_gpio);
        return -EINVAL;
    }
    gpio_set_value(priv->i2s_gpio, GPIO_LOW_VOLTAGE);
    mdelay(priv->delay_i2s);
    if (!gpio_is_valid(priv->rst_gpio)) {
        dpu_pr_err("[MIPI2HDMI] rst_gpio is invalid, rst_gpio=%u\n", priv->rst_gpio);
        return -EINVAL;
    }
    gpio_set_value(priv->rst_gpio, GPIO_HIGH_VOLTAGE);
    mdelay(priv->delay_rst);
    if (!gpio_is_valid(priv->rdv_oe_gpio)) {
        dpu_pr_err("[MIPI2HDMI] rdv_oe_gpio is invalid, rdv_oe_gpio=%u\n", priv->rdv_oe_gpio);
        return -EINVAL;
    }
    gpio_set_value(priv->rdv_oe_gpio, GPIO_LOW_VOLTAGE);
    mdelay(priv->delay_rdv_oe);

    dpu_pr_info("[MIPI2HDMI] disable ldo_1v2\n");
    ret = regulator_disable(priv->ldo_1v2);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] regulator_disable ldo_1v2 failed, ret=%d\n", ret);
        return ret;
    }
    mdelay(priv->delay_1v2);

    dpu_pr_info("[MIPI2HDMI] disable ldo_3v3\n");
    ret = regulator_disable(priv->ldo_3v3);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] regulator_disable ldo_3v3 failed, ret=%d\n", ret);
        return ret;
    }
    mdelay(priv->delay_3v3);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_power_off(struct mipi2hdmi_bridge *bridge)
{
    int32_t ret = 0;
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");
    priv = to_lt9611_private(bridge);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->client, -EINVAL, err, "[MIPI2HDMI] priv->client is null\n");

    ret = lt9611_power_off_sequence(priv->client);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] power off sequence failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] power off done\n");

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_set_update_status(struct i2c_client *client, FW_UPDATE_STATUS status)
{
    int32_t ret = 0;
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    priv = i2c_get_clientdata(client);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    dpu_pr_info("[MIPI2HDMI] status=%d\n", status);
    atomic_set(&priv->fw_update_ongoing_atom, status);
    if (status == FW_UPDATE_STATUS_ONGOING) {
        dpu_pr_info("[MIPI2HDMI] fw update started\n");
        schedule_delayed_work(&priv->fw_update_timeout_work, msecs_to_jiffies(LT9611_FW_UPDATE_TIMEOUT));
    } else if (status == FW_UPDATE_STATUS_DONE) {
        dpu_pr_info("[MIPI2HDMI] fw update done\n");
        cancel_delayed_work(&priv->fw_update_timeout_work);
        ret = mipi2hdmi_check_online(&priv->bridge_info);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] check online failed, ret=%d\n", ret);
        }
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_reset_chip(struct i2c_client *client, int32_t delay)
{
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    priv = i2c_get_clientdata(client);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    dpu_pr_info("[MIPI2HDMI] delay=%d\n", delay);

    if (!gpio_is_valid(priv->rst_gpio)) {
        dpu_pr_err("[MIPI2HDMI] rst_gpio is invalid, rst_gpio=%u\n", priv->rst_gpio);
        return -EINVAL;
    }
    gpio_set_value(priv->rst_gpio, GPIO_HIGH_VOLTAGE);
    mdelay(delay);
    gpio_set_value(priv->rst_gpio, GPIO_LOW_VOLTAGE);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxc_control_enable(struct i2c_client *client)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");

    /* switch to bank address 0x80 */
    ret = mipi2hdmi_i2c_send_byte(client, 0xFF, 0x80);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] switch to bank address 0x80 failed, ret=%d\n", ret);
        return ret;
    }
    /* write 0x01 to address 0x80ee(stop firmware in OCM) */
    ret = mipi2hdmi_i2c_send_byte(client, 0xEE, 0x01);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] write 0x01 to address 0x80ee failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxc_control_disable(struct i2c_client *client)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");

    /* switch to bank address 0x80 */
    ret = mipi2hdmi_i2c_send_byte(client, 0xFF, 0x80);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] switch to bank address 0x80 failed, ret=%d\n", ret);
        return ret;
    }
    /* write 0x00 to address 0x80ee(start firmware in OCM) */
    ret = mipi2hdmi_i2c_send_byte(client, 0xEE, 0x00);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] write 0x00 to address 0x80EE failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxc_edid_read_enable(struct i2c_client *client)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");

    /* switch to bank address 0xB0 */
    ret = mipi2hdmi_i2c_send_byte(client, 0xFF, 0xB0);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] switch to bank address 0xB0 failed, ret=%d\n", ret);
        return ret;
    }
    /* write 0x10 to 0xB00B */
    ret = mipi2hdmi_i2c_send_byte(client, 0x0B, 0x10);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] write 0x10 to address 0xB00B failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxc_check_int(struct i2c_client *client)
{
    int32_t ret = 0;
    uint8_t value = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");

    /* switch to bank address 0xB0 */
    ret = mipi2hdmi_i2c_send_byte(client, 0xFF, 0xB0);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] switch to bank address 0xB0 failed, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_i2c_recv_byte(client, 0x22, &value);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] read interrupt register failed, ret=%d\n", ret);
        return ret;
    }
    dpu_pr_info("[MIPI2HDMI] interrupt flag=%#x\n", value);

    if (value & LT9611_UXC_EDID_INT_MASK) {
        dpu_pr_info("[MIPI2HDMI] edid interrupt detected\n");
    } else {
        dpu_pr_err("[MIPI2HDMI] edid interrupt not detected, value=%#x\n", value);
        return -EINT_NOT_EDID_READY;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxc_clear_int(struct i2c_client *client)
{
    int32_t ret = 0;
    uint8_t value = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");

    /* switch to bank address 0xB0 */
    ret = mipi2hdmi_i2c_send_byte(client, 0xFF, 0xB0);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] switch to bank address 0xB0 failed, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_i2c_recv_byte(client, 0x22, &value);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] read interrupt register failed, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_i2c_send_byte(client, 0x22, value & (~LT9611_UXC_EDID_INT_MASK));
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] clear interrupt flag failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return ret;
}

static int32_t lt9611_uxc_get_block_num(struct i2c_client *client, uint8_t *block_num)
{
    int32_t ret = 0;
    uint8_t value = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!block_num, -EINVAL, err, "[MIPI2HDMI] block_num is null\n");

    *block_num = 0;
    ret = mipi2hdmi_i2c_recv_byte(client, 0x2A, &value);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] read edid register failed, ret=%d\n", ret);
        return ret;
    }
    *block_num = value & LT9611_UXC_EDID_BLOCK_NUM_MASK;
    if (*block_num == 0 || *block_num > MAX_EDID_BLOCK_NUM) {
        dpu_pr_err("[MIPI2HDMI] block num is invalid, block_num=%hhu\n", *block_num);
        return -EINVALID_BLOCK_NUM;
    }

    dpu_pr_info("[MIPI2HDMI] block_num=%hhu\n", *block_num);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxc_get_ready_flag(struct i2c_client *client, uint8_t *flag)
{
    int32_t ret = 0;
    uint8_t value = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!flag, -EINVAL, err, "[MIPI2HDMI] flag is null\n");

    ret = mipi2hdmi_i2c_recv_byte(client, 0x2A, &value);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] read edid register failed, ret=%d\n", ret);
        return ret;
    }
    *flag = value;

    dpu_pr_info("[MIPI2HDMI] ready flag=%#x\n", *flag);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxc_clear_ready_flag(struct i2c_client *client, uint8_t value)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");

    ret = mipi2hdmi_i2c_send_byte(client, 0x2A, value);
    if (ret != 0) {
        dpu_pr_warn("[MIPI2HDMI] clear edid ready flag failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxc_read_edid_data(struct i2c_client *client, uint8_t cur_num,
    uint8_t *edid, size_t edid_buf_len)
{
    int32_t ret = 0;

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!edid, -EINVAL, err, "[MIPI2HDMI] edid is null\n");

    if ((size_t)cur_num >= edid_buf_len / EDID_BLOCK_LENGTH) {
        dpu_pr_err("[MIPI2HDMI] cur_num is invalid\n");
        return -EINVAL;
    }

    ret = mipi2hdmi_i2c_send_byte(client, 0x0A,
        (cur_num % LT9611_UXC_EDID_BLOCK_CAPACITY) * EDID_BLOCK_LENGTH);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] write register address failed, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_i2c_recv_nbytes(client, 0xB0,
        &edid[cur_num * EDID_BLOCK_LENGTH], EDID_BLOCK_LENGTH);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] read edid data failed, ret=%d\n", ret);
        return ret;
    }

    return 0;
}

static int32_t lt9611_uxc_do_read_edid(struct i2c_client *client, uint8_t block_num,
    uint8_t *edid, size_t edid_buf_len, uint32_t *edid_len)
{
    int32_t ret = 0;
    int32_t wait_cnt = 0;
    uint8_t cur_num = 0;
    uint8_t min_num = 0;
    uint8_t count = 0;
    uint8_t ready_flag = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!edid, -EINVAL, err, "[MIPI2HDMI] edid is null\n");
    dpu_check_and_return(!edid_len, -EINVAL, err, "[MIPI2HDMI] edid_len is null\n");

    do {
        ret = lt9611_uxc_get_ready_flag(client, &ready_flag);
        if (ret || !(ready_flag & LT9611_UXC_EDID_READY_MASK)) {
            mdelay(LT9611_UXC_EDID_WAIT_TIME);
            dpu_pr_warn("[MIPI2HDMI] edid not ready, wait for %dms, ret=%d, ready_flag=%hhu, wait_cnt=%d\n",
                LT9611_UXC_EDID_WAIT_TIME, ret, ready_flag, wait_cnt);
            continue;
        }
        min_num = MIN(LT9611_UXC_EDID_BLOCK_CAPACITY, block_num - cur_num);
        for (count = 0; count < min_num; count++) {
            ret = lt9611_uxc_read_edid_data(client, cur_num, edid, edid_buf_len);
            if (ret != 0) {
                dpu_pr_err("[MIPI2HDMI] read edid data failed failed, ret=%d\n", ret);
                return ret;
            }
            cur_num++;
        }
        if (block_num > LT9611_UXC_EDID_BLOCK_CAPACITY && (cur_num % LT9611_UXC_EDID_BLOCK_CAPACITY) == 0) {
            ret = lt9611_uxc_clear_ready_flag(client, ready_flag & (~LT9611_UXC_EDID_READY_MASK));
            if (ret != 0) {
                dpu_pr_err("[MIPI2HDMI] clear edid ready flag failed, ret=%d\n", ret);
                return ret;
            }
        }
    } while (cur_num < block_num && ++wait_cnt < LT9611_UXC_EDID_WAIT_COUNT);

    if (wait_cnt >= LT9611_UXC_EDID_WAIT_COUNT) {
        dpu_pr_warn("[MIPI2HDMI] wait for edid ready flag timeout\n");
        return -EUXC_EDID_READ_TIMEOUT;
    }

    *edid_len = cur_num * EDID_BLOCK_LENGTH;

    dpu_pr_info("[MIPI2HDMI] cur_num=%hhu edid_len=%u\n", cur_num, *edid_len);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxc_check_prepare(struct i2c_client *client, uint8_t *block_num)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!block_num, -EINVAL, err, "[MIPI2HDMI] block_num is null\n");

    ret = lt9611_uxc_check_int(client);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] interrupt is not for edid ready, ret=%d\n", ret);
        return ret;
    }
    ret = lt9611_uxc_get_block_num(client, block_num);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] read block num failed, ret=%d\n", ret);
        return ret;
    }
    ret = lt9611_uxc_edid_read_enable(client);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] enable edid read failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxc_read_edid(struct i2c_client *client, uint8_t *edid, size_t edid_buf_len, uint32_t *edid_len)
{
    int32_t ret = 0;
    uint8_t retry_cnt = 0;
    uint8_t block_num = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!edid, -EINVAL, err, "[MIPI2HDMI] edid is null\n");
    dpu_check_and_return(!edid_len, -EINVAL, err, "[MIPI2HDMI] edid_len is null\n");

    ret = lt9611_uxc_control_enable(client);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] enable uxc control failed, ret=%d\n", ret);
        return ret;
    }
    ret = lt9611_uxc_check_prepare(client, &block_num);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] check and prepare failed, ret=%d\n", ret);
        goto err_out;
    }

    do {
        ret = lt9611_uxc_do_read_edid(client, block_num, edid, edid_buf_len, edid_len);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] read edid data failed, ret=%d\n", ret);
            continue;
        }
        ret = mipi2hdmi_check_edid(edid, *edid_len);
        if (ret != 0) {
            dpu_pr_warn("[MIPI2HDMI] Edid verification failed, ret=%d, retry_cnt=%hhu\n", ret, retry_cnt);
            continue;
        }
        dpu_pr_info("[MIPI2HDMI] Edid verification succeeded, retry_cnt: %hhu\n", retry_cnt);
    } while (ret != 0 && ++retry_cnt < MAX_RETRY_TIMES);

    ret = lt9611_uxc_clear_int(client);
    if (ret != 0) {
        dpu_pr_warn("[MIPI2HDMI] Failed to clear interrupt flag, ret=%d, retry_cnt=%hhu\n", ret, retry_cnt);
    }

    if (retry_cnt >= MAX_RETRY_TIMES) {
        dpu_pr_err("[MIPI2HDMI] retry count exceeds max times\n");
        ret = -EREAD_EDID_FAILED;
    }

err_out:
    (void)lt9611_uxc_control_disable(client);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return ret;
}

static int32_t lt9611_uxd_check_int(struct i2c_client *client)
{
    int32_t ret = 0;
    uint8_t value = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");

    /* switch to bank address 0xE0 */
    ret = mipi2hdmi_i2c_send_byte(client, 0xFF, 0xE0);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd switch to bank address 0xE0 failed, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_i2c_recv_byte(client, 0x84, &value);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd read interrupt register failed, ret=%d\n", ret);
        return ret;
    }
    dpu_pr_info("[MIPI2HDMI] uxd interrupt flag=%#x\n", value);

    if (value & LT9611_UXD_EDID_INT_MASK) {
        dpu_pr_info("[MIPI2HDMI] uxd edid interrupt detected\n");
    } else {
        dpu_pr_err("[MIPI2HDMI] uxd edid interrupt not detected, value=%#x\n", value);
        return -EINT_NOT_EDID_READY;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxd_clear_int(struct i2c_client *client)
{
    int32_t ret = 0;
    uint8_t value = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");

    /* switch to bank address 0xE0 */
    ret = mipi2hdmi_i2c_send_byte(client, 0xFF, 0xE0);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd switch to bank address 0xE0 failed, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_i2c_recv_byte(client, 0x84, &value);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd read interrupt register failed, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_i2c_send_byte(client, 0xDF, LT9611_UXD_EDID_INT_MASK);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd write 1 to clear interrupt flag failed, ret=%d\n", ret);
        return ret;
    }
    mdelay(LT9611_UXD_INT_CLEAR_INTERVAL);
    ret = mipi2hdmi_i2c_send_byte(client, 0xDF, value & (~LT9611_UXD_EDID_INT_MASK));
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd write 0 to clear interrupt flag failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxd_transaction_request(struct i2c_client *client, uint8_t *in_buffer, int32_t in_len)
{
    int32_t ret = 0;
    uint8_t value = 0;
    int32_t wait_cnt = 0;
    int32_t i = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!in_buffer, -EINVAL, err, "[MIPI2HDMI] in_buffer is null\n");

    if (in_len < LT9611_UXD_REQ_PACKET_MIN_SIZE || in_len > LT9611_UXD_REQ_PACKET_MAX_SIZE) {
        dpu_pr_err("[MIPI2HDMI] in_len is invalid\n");
        return -EINVAL;
    }

    /* enable host to write bridge chip */
    ret = mipi2hdmi_i2c_send_byte(client, 0xDE, 0x01);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd enable external write failed, ret=%d\n", ret);
        return ret;
    }

    do {
        ret = mipi2hdmi_i2c_recv_byte(client, 0xAE, &value);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] uxd check i2c ready failed, ret=%d\n", ret);
            return ret;
        }
        mdelay(LT9611_UXD_CHECK_READY_INTERVAL);
    } while (value != 0x01 && ++wait_cnt < LT9611_UXD_CHECK_READY_COUNT);

    dpu_pr_info("[MIPI2HDMI] wait_cnt=%d\n", wait_cnt);

    if (wait_cnt >= LT9611_UXD_CHECK_READY_COUNT) {
        dpu_pr_err("[MIPI2HDMI] uxd i2c is not ready\n");
        return -EUXD_CHECK_READY_TIMEOUT;
    }

    for (i = 0; i < in_len; i++) {
        ret = mipi2hdmi_i2c_send_byte(client, 0xB0 + i, in_buffer[i]);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] uxd write cmd data failed, ret=%d\n", ret);
            return ret;
        }
    }

    /* host write cmd data end */
    ret = mipi2hdmi_i2c_send_byte(client, 0xDE, 0x02);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd write cmd data end failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxd_transaction_ack(struct i2c_client *client, uint8_t *out_buffer, int32_t out_len)
{
    int32_t ret = 0;
    uint8_t value = 0;
    int32_t wait_cnt = 0;
    int32_t i = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!out_buffer, -EINVAL, err, "[MIPI2HDMI] out_buffer is null\n");

    if (out_len < LT9611_UXD_ACK_PACKET_MIN_SIZE || out_len > LT9611_UXD_ACK_PACKET_MAX_SIZE) {
        dpu_pr_err("[MIPI2HDMI] out_len is invalid\n");
        return -EINVAL;
    }

    do {
        ret = mipi2hdmi_i2c_recv_byte(client, 0xAE, &value);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] uxd check ack ready failed, ret=%d\n", ret);
            return ret;
        }
        mdelay(LT9611_UXD_CHECK_READY_INTERVAL);
    } while (value != 0x02 && ++wait_cnt < LT9611_UXD_CHECK_READY_COUNT);

    if (wait_cnt >= LT9611_UXD_CHECK_READY_COUNT) {
        dpu_pr_err("[MIPI2HDMI] uxd bridge chip does not ack\n");
        return -EUXD_CHECK_READY_TIMEOUT;
    }

    ret = mipi2hdmi_i2c_recv_nbytes(client, 0x85, out_buffer, out_len);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd read data failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxd_transaction(struct i2c_client *client, uint8_t *in_buffer, int32_t in_len,
    uint8_t *out_buffer, int32_t out_len)
{
    int32_t ret = 0;
    uint8_t value = 0;
    int32_t wait_cnt = 0;
    int32_t i = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!in_buffer, -EINVAL, err, "[MIPI2HDMI] in_buffer is null\n");
    dpu_check_and_return(!out_buffer, -EINVAL, err, "[MIPI2HDMI] out_buffer is null\n");

    if (in_len < LT9611_UXD_REQ_PACKET_MIN_SIZE || in_len > LT9611_UXD_REQ_PACKET_MAX_SIZE) {
        dpu_pr_err("[MIPI2HDMI] in_len is invalid\n");
        return -EINVAL;
    }

    if (out_len < LT9611_UXD_ACK_PACKET_MIN_SIZE || out_len > LT9611_UXD_ACK_PACKET_MAX_SIZE) {
        dpu_pr_err("[MIPI2HDMI] out_len is invalid\n");
        return -EINVAL;
    }

    /* switch to bank address 0xE0 */
    ret = mipi2hdmi_i2c_send_byte(client, 0xFF, 0xE0);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd switch to bank address 0xE0 failed, ret=%d\n", ret);
        return ret;
    }

    ret = lt9611_uxd_transaction_request(client, in_buffer, in_len);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd transaction request failed, ret=%d\n", ret);
        return ret;
    }

    ret = lt9611_uxd_transaction_ack(client, out_buffer, out_len);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd transaction ack failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxd_check_ack_header(uint8_t *cmd_buf, int32_t cmd_buf_len,
    uint8_t *data_buf, int32_t data_buf_len)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!cmd_buf, -EINVAL, err, "[MIPI2HDMI] cmd_buf is null\n");
    dpu_check_and_return(!data_buf, -EINVAL, err, "[MIPI2HDMI] data_buf is null\n");

    if (cmd_buf_len < ARRAY_INDEX_2 + 1) {
        dpu_pr_err("[MIPI2HDMI] cmd_buf_len is invalid\n");
        return -EINVAL;
    }
    if (data_buf_len < ARRAY_INDEX_2 + 1) {
        dpu_pr_err("[MIPI2HDMI] data_buf_len is invalid\n");
        return -EINVAL;
    }

    if (data_buf[ARRAY_INDEX_0] != LT9611_UXD_COMM_F_ACK || data_buf[ARRAY_INDEX_1] != cmd_buf[ARRAY_INDEX_1] ||
        data_buf[ARRAY_INDEX_2] != cmd_buf[ARRAY_INDEX_2]) {
        dpu_pr_err("[MIPI2HDMI] uxd ack header is wrong\n");
        return -EUXD_ACK_HEADER_WRONG;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxd_get_edid_size(struct i2c_client *client, uint16_t *edid_data_size)
{
    int32_t ret = 0;
    uint8_t cmd_buf[LT9611_UXD_CMD_BUF_LEN] = {0x52, 0x48, 0x32, 0x3A, 0x00};
    int32_t cmd_buf_len = sizeof(cmd_buf);
    uint8_t data_buf[LT9611_UXD_EDID_SIZE_BUF_LEN] = {0};
    int32_t data_buf_len = sizeof(data_buf);

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!edid_data_size, -EINVAL, err, "[MIPI2HDMI] edid_data_size is null\n");

    *edid_data_size = 0;
    ret = lt9611_uxd_transaction(client, cmd_buf, cmd_buf_len, data_buf, data_buf_len);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd read edid size failed, ret=%d\n", ret);
        return ret;
    }
    ret = lt9611_uxd_check_ack_header(cmd_buf, cmd_buf_len, data_buf, data_buf_len);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd check ack header failed, ret=%d\n", ret);
        return ret;
    }
    *edid_data_size = (((uint16_t)data_buf[ARRAY_INDEX_4]) << SHIFT_EIGHT_BITS) | data_buf[ARRAY_INDEX_5];
    if (*edid_data_size < EDID_BLOCK_LENGTH || *edid_data_size > MAX_EDID_DATA_SIZE) {
        dpu_pr_err("[MIPI2HDMI] uxd edid data size is invalid, edid_data_size=%hu\n", *edid_data_size);
        return -EINVALID_DATA_SIZE;
    }

    dpu_pr_info("[MIPI2HDMI] uxd edid_data_size=%hu\n", *edid_data_size);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxd_do_read_edid(struct i2c_client *client, uint16_t edid_data_size,
    uint8_t *edid, size_t edid_buf_len, uint32_t *edid_len)
{
    int32_t ret = 0;
    uint8_t cmd_buf[LT9611_UXD_CMD_BUF_LEN] = {0x52, 0x48, 0x33, 0x3A, 0x00};
    int32_t cmd_buf_len = sizeof(cmd_buf);
    uint8_t data_buf[LT9611_UXD_EDID_DATA_BUF_LEN] = {0};
    int32_t data_buf_len = sizeof(data_buf);
    uint16_t i = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!edid, -EINVAL, err, "[MIPI2HDMI] edid is null\n");
    dpu_check_and_return(!edid_len, -EINVAL, err, "[MIPI2HDMI] edid_len is null\n");

    if ((size_t)edid_data_size > edid_buf_len) {
        dpu_pr_err("[MIPI2HDMI] edid_data_size is invalid\n");
        return -EINVAL;
    }

    for (i = 0; i < edid_data_size / LT9611_UXD_EDID_PACKET_SIZE; i++) {
        cmd_buf[ARRAY_INDEX_4] = i;
        ret = lt9611_uxd_transaction(client, cmd_buf, cmd_buf_len, data_buf, data_buf_len);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] uxd read edid len failed, ret=%d\n", ret);
            return ret;
        }
        ret = lt9611_uxd_check_ack_header(cmd_buf, cmd_buf_len, data_buf, data_buf_len);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] uxd check ack header failed, ret=%d\n", ret);
            return ret;
        }
        if (data_buf[ARRAY_INDEX_4] != cmd_buf[ARRAY_INDEX_4]) {
            dpu_pr_err("[MIPI2HDMI] uxd ack packet sequence number mismatch\n");
            return ret;
        }
        ret = memcpy_s(&edid[i * LT9611_UXD_EDID_PACKET_SIZE], LT9611_UXD_EDID_PACKET_SIZE,
            &data_buf[ARRAY_INDEX_5], LT9611_UXD_EDID_PACKET_SIZE);
        if (ret != EOK) {
            dpu_pr_err("[MIPI2HDMI] uxd copy data_buf to edid[%hu] failed, ret=%d\n",
                i * LT9611_UXD_EDID_PACKET_SIZE, ret);
            return ret;
        }

        *edid_len += LT9611_UXD_EDID_PACKET_SIZE;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxd_read_edid(struct i2c_client *client, uint8_t *edid, size_t edid_buf_len, uint32_t *edid_len)
{
    int32_t ret = 0;
    int32_t retry_cnt = 0;
    uint16_t edid_data_size = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!edid, -EINVAL, err, "[MIPI2HDMI] edid is null\n");
    dpu_check_and_return(!edid_len, -EINVAL, err, "[MIPI2HDMI] edid_len is null\n");

    ret = lt9611_uxd_check_int(client);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd interrupt is not for edid ready, ret=%d\n", ret);
        return ret;
    }
    ret = lt9611_uxd_get_edid_size(client, &edid_data_size);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd read edid size failed, ret=%d\n", ret);
        return ret;
    }

    do {
        ret = lt9611_uxd_do_read_edid(client, edid_data_size, edid, edid_buf_len, edid_len);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] uxd read edid data failed, ret=%d\n", ret);
            continue;
        }
        ret = mipi2hdmi_check_edid(edid, *edid_len);
        if (ret != 0) {
            dpu_pr_warn("[MIPI2HDMI] uxd edid verification failed, ret=%d, retry_cnt=%d\n", ret, retry_cnt);
            continue;
        }
        dpu_pr_info("[MIPI2HDMI] uxd edid verification succeeded, retry_cnt: %d\n", retry_cnt);
    } while (ret != 0 && ++retry_cnt < MAX_RETRY_TIMES);

    ret = lt9611_uxd_clear_int(client);
    if (ret != 0) {
        dpu_pr_warn("[MIPI2HDMI] uxd failed to clear interrupt flag, ret=%d, retry_cnt=%d\n", ret, retry_cnt);
    }

    if (retry_cnt >= MAX_RETRY_TIMES) {
        dpu_pr_err("[MIPI2HDMI] uxd retry count exceeds max times\n");
        return -EREAD_EDID_FAILED;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_read_edid(struct mipi2hdmi_bridge *bridge, uint8_t *edid,
    size_t edid_buf_len, uint32_t *edid_len)
{
    int32_t ret = 0;
    struct lt9611_private *priv = NULL;
    struct i2c_client *client = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");
    dpu_check_and_return(!edid, -EINVAL, err, "[MIPI2HDMI] edid is null\n");
    dpu_check_and_return(!edid_len, -EINVAL, err, "[MIPI2HDMI] edid_len is null\n");

    priv = to_lt9611_private(bridge);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    client = priv->client;
    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");

    if (client->addr == LT9611_UXC_DEV_ADDR) {
        ret = lt9611_uxc_read_edid(client, edid, edid_buf_len, edid_len);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] uxc read edid data failed, ret=%d\n", ret);
            return ret;
        }
    } else {
        ret = lt9611_uxd_read_edid(client, edid, edid_buf_len, edid_len);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] uxd read edid data failed, ret=%d\n", ret);
            return ret;
        }
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return ret;
}

static int32_t lt9611_uxd_set_hdcp_mode(struct i2c_client *client, uint8_t mode)
{
    int32_t ret = 0;
    uint8_t cmd_buf[LT9611_UXD_CMD_BUF_LEN] = {0x57, 0x48, 0x34, 0x3A, 0x01};
    int32_t cmd_buf_len = sizeof(cmd_buf);
    uint8_t data_buf[LT9611_UXD_EDID_SIZE_BUF_LEN] = {0};
    int32_t data_buf_len = sizeof(data_buf);
 
    dpu_pr_info("[MIPI2HDMI] +\n");
 
    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
 
    cmd_buf[LT9611_UXD_CMD_BUF_LEN - 1] = mode;
    ret = lt9611_uxd_transaction(client, cmd_buf, cmd_buf_len, data_buf, data_buf_len);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd set hdcp failed, ret=%d\n", ret);
        return ret;
    }
    ret = lt9611_uxd_check_ack_header(cmd_buf, cmd_buf_len, data_buf, data_buf_len);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd check ack header failed, ret=%d\n", ret);
        return ret;
    }
 
    dpu_pr_info("[MIPI2HDMI] -\n");
 
    return 0;
}

static int32_t lt9611_uxc_convert_timing(struct mipi2hdmi_video_timing *user_timing,
    uint8_t *config_values, int32_t len)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!user_timing, -EINVAL, err, "[MIPI2HDMI] user_timing is null\n");
    dpu_check_and_return(!config_values, -EINVAL, err, "[MIPI2HDMI] config_values is null\n");

    if (len < LT9611_UXC_TIMING_REG_COUNT) {
        dpu_pr_err("[MIPI2HDMI] len is invalid\n");
        return -EINVAL;
    }

    config_values[ARRAY_INDEX_0] = (user_timing->vtotal >> SHIFT_EIGHT_BITS) & 0xFF;
    config_values[ARRAY_INDEX_1] = user_timing->vtotal & 0xFF;
    config_values[ARRAY_INDEX_2] = (user_timing->vactive >> SHIFT_EIGHT_BITS) & 0xFF;
    config_values[ARRAY_INDEX_3] = user_timing->vactive & 0xFF;
    config_values[ARRAY_INDEX_4] = (user_timing->htotal >> SHIFT_EIGHT_BITS) & 0xFF;
    config_values[ARRAY_INDEX_5] = user_timing->htotal & 0xFF;
    config_values[ARRAY_INDEX_6] = (user_timing->hactive >> SHIFT_EIGHT_BITS) & 0xFF;
    config_values[ARRAY_INDEX_7] = user_timing->hactive & 0xFF;
    config_values[ARRAY_INDEX_8] = user_timing->vsa & 0xFF;
    config_values[ARRAY_INDEX_9] = (user_timing->hsa >> SHIFT_EIGHT_BITS) & 0x0F;
    config_values[ARRAY_INDEX_10] = user_timing->hsa & 0xFF;
    config_values[ARRAY_INDEX_11] = (user_timing->vfp >> SHIFT_EIGHT_BITS) & 0x0F;
    config_values[ARRAY_INDEX_12] = user_timing->vfp & 0xFF;
    config_values[ARRAY_INDEX_13] = (user_timing->hfp >> SHIFT_EIGHT_BITS) & 0x0F;
    config_values[ARRAY_INDEX_14] = user_timing->hfp & 0xFF;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxc_do_set_display_timing(struct i2c_client *client, uint8_t *config_values, int32_t len)
{
    int32_t ret = 0;
    int32_t i = 0;
    uint8_t value = 0;
    uint8_t reg_addr = 0;
    uint8_t reg_value = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!config_values, -EINVAL, err, "[MIPI2HDMI] config_values is null\n");

    if (len <= 0 || len > LT9611_UXC_TIMING_REG_COUNT) {
        dpu_pr_err("[MIPI2HDMI] len is invalid\n");
        return -EINVAL;
    }

    for (i = 0; i < len; i++) {
        reg_addr = 0x0D + i;
        if (reg_addr == 0x16 || reg_addr == 0x18 || reg_addr == 0x1A) {
            ret = mipi2hdmi_i2c_recv_byte(client, reg_addr, &value);
            if (ret != 0) {
                dpu_pr_err("[MIPI2HDMI] read from register %#x failed, ret=%d\n", reg_addr, ret);
                break;
            }
            reg_value = config_values[i] | value;
        } else {
            reg_value = config_values[i];
        }
        ret = mipi2hdmi_i2c_send_byte(client, reg_addr, reg_value);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] write to register %#x failed, ret=%d\n", reg_addr, ret);
            break;
        }
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return ret;
}

static int32_t lt9611_uxc_set_display_timing(struct i2c_client *client, struct mipi2hdmi_video_timing *user_timing)
{
    int32_t ret = 0;
    uint8_t config_values[LT9611_UXC_TIMING_REG_COUNT] = {0};
    int32_t retry_cnt = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!user_timing, -EINVAL, err, "[MIPI2HDMI] user_timing is null\n");

    ret = lt9611_uxc_convert_timing(user_timing, config_values, LT9611_UXC_TIMING_REG_COUNT);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] convert timing failed, ret=%d\n", ret);
        return ret;
    }
    ret = lt9611_uxc_control_enable(client);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] enable uxc control failed, ret=%d\n", ret);
        return ret;
    }
    /* switch to bank address 0xD0 */
    ret = mipi2hdmi_i2c_send_byte(client, 0xFF, 0xD0);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] switch to bank address 0xD0 failed, ret=%d\n", ret);
        goto err_out;
    }
    do {
        ret = lt9611_uxc_do_set_display_timing(client, config_values, LT9611_UXC_TIMING_REG_COUNT);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] set display timing failed, ret=%d\n", ret);
            continue;
        }
        dpu_pr_info("[MIPI2HDMI] write to register, retry_cnt=%d\n", retry_cnt);
    } while (ret != 0 && ++retry_cnt < MAX_RETRY_TIMES);

err_out:
    (void)lt9611_uxc_control_disable(client);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return ret;
}

static int32_t lt9611_uxd_fill_req_buf(struct mipi2hdmi_video_timing *user_timing,
    uint8_t *cmd_buf, int32_t cmd_buf_len)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!user_timing, -EINVAL, err, "[MIPI2HDMI] user_timing is null\n");
    dpu_check_and_return(!cmd_buf, -EINVAL, err, "[MIPI2HDMI] cmd_buf is null\n");

    if (cmd_buf_len < ARRAY_INDEX_25 + 1) {
        dpu_pr_err("[MIPI2HDMI] uxd cmd_buf_len is invalid\n");
        return -EINVAL;
    }

    cmd_buf[ARRAY_INDEX_4] = (user_timing->htotal >> SHIFT_EIGHT_BITS) & 0xFF;
    cmd_buf[ARRAY_INDEX_5] = user_timing->htotal & 0xFF;
    cmd_buf[ARRAY_INDEX_6] = (user_timing->hactive >> SHIFT_EIGHT_BITS) & 0xFF;
    cmd_buf[ARRAY_INDEX_7] = user_timing->hactive & 0xFF;
    cmd_buf[ARRAY_INDEX_8] = (user_timing->hfp >> SHIFT_EIGHT_BITS) & 0xFF;
    cmd_buf[ARRAY_INDEX_9] = user_timing->hfp & 0xFF;
    cmd_buf[ARRAY_INDEX_10] = (user_timing->hsa >> SHIFT_EIGHT_BITS) & 0xFF;
    cmd_buf[ARRAY_INDEX_11] = user_timing->hsa & 0xFF;
    cmd_buf[ARRAY_INDEX_12] = (user_timing->hbp >> SHIFT_EIGHT_BITS) & 0xFF;
    cmd_buf[ARRAY_INDEX_13] = user_timing->hbp & 0xFF;
    cmd_buf[ARRAY_INDEX_14] = (user_timing->vtotal >> SHIFT_EIGHT_BITS) & 0xFF;
    cmd_buf[ARRAY_INDEX_15] = user_timing->vtotal & 0xFF;
    cmd_buf[ARRAY_INDEX_16] = (user_timing->vactive >> SHIFT_EIGHT_BITS) & 0xFF;
    cmd_buf[ARRAY_INDEX_17] = user_timing->vactive & 0xFF;
    cmd_buf[ARRAY_INDEX_18] = (user_timing->vfp >> SHIFT_EIGHT_BITS) & 0xFF;
    cmd_buf[ARRAY_INDEX_19] = user_timing->vfp & 0xFF;
    cmd_buf[ARRAY_INDEX_20] = (user_timing->vsa >> SHIFT_EIGHT_BITS) & 0xFF;
    cmd_buf[ARRAY_INDEX_21] = user_timing->vsa & 0xFF;
    cmd_buf[ARRAY_INDEX_22] = (user_timing->vbp >> SHIFT_EIGHT_BITS) & 0xFF;
    cmd_buf[ARRAY_INDEX_23] = user_timing->vbp & 0xFF;
    cmd_buf[ARRAY_INDEX_24] = user_timing->fps;
    cmd_buf[ARRAY_INDEX_25] = user_timing->vic;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_uxd_set_display_timing(struct i2c_client *client, struct mipi2hdmi_video_timing *user_timing)
{
    int32_t ret = 0;
    uint8_t cmd_buf[LT9611_UXD_TIMING_REQ_LEN] = {0x57, 0x4D, 0x33, 0x3A};
    int32_t cmd_buf_len = sizeof(cmd_buf);
    uint8_t data_buf[LT9611_UXD_TIMING_ACK_LEN] = {0};
    int32_t data_buf_len = sizeof(data_buf);

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    dpu_check_and_return(!user_timing, -EINVAL, err, "[MIPI2HDMI] user_timing is null\n");

    ret = lt9611_uxd_fill_req_buf(user_timing, cmd_buf, cmd_buf_len);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd fill request buffer failed, ret=%d\n", ret);
        return ret;
    }
    ret = lt9611_uxd_transaction(client, cmd_buf, cmd_buf_len, data_buf, data_buf_len);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd read edid len failed, ret=%d\n", ret);
        return ret;
    }
    ret = lt9611_uxd_check_ack_header(cmd_buf, cmd_buf_len, data_buf, data_buf_len);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] uxd check ack header failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_set_display_timing(struct mipi2hdmi_bridge *bridge, struct mipi2hdmi_video_timing *user_timing)
{
    int32_t ret = 0;
    struct lt9611_private *priv = NULL;
    struct i2c_client *client = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");
    dpu_check_and_return(!user_timing, -EINVAL, err, "[MIPI2HDMI] user_timing is null\n");

    priv = to_lt9611_private(bridge);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    client = priv->client;
    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");

    if (client->addr == LT9611_UXC_DEV_ADDR) {
        ret = lt9611_uxc_set_display_timing(client, user_timing);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] uxc set display timing failed, ret=%d\n", ret);
            return ret;
        }
    } else {
        ret = lt9611_uxd_set_display_timing(client, user_timing);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] uxd set display timing failed, ret=%d\n", ret);
            return ret;
        }
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_enable_i2s(struct mipi2hdmi_bridge *bridge)
{
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");

    priv = to_lt9611_private(bridge);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    if (!gpio_is_valid(priv->i2s_gpio)) {
        dpu_pr_err("[MIPI2HDMI] i2s_gpio is invalid, i2s_gpio=%u\n", priv->i2s_gpio);
        return -EINVAL;
    }
    gpio_set_value(priv->i2s_gpio, GPIO_HIGH_VOLTAGE);

    dpu_pr_info("[MIPI2HDMI] enable i2s\n");

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_disable_i2s(struct mipi2hdmi_bridge *bridge)
{
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");

    priv = to_lt9611_private(bridge);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    if (!gpio_is_valid(priv->i2s_gpio)) {
        dpu_pr_err("[MIPI2HDMI] i2s_gpio is invalid, i2s_gpio=%u\n", priv->i2s_gpio);
        return -EINVAL;
    }
    gpio_set_value(priv->i2s_gpio, GPIO_LOW_VOLTAGE);

    dpu_pr_info("[MIPI2HDMI] disable i2s\n");

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_set_hdcp_mode(struct mipi2hdmi_bridge *bridge, uint8_t mode)
{
    int32_t ret = 0;
    struct lt9611_private *priv = NULL;
    struct i2c_client *client = NULL;
 
    dpu_pr_info("[MIPI2HDMI] +\n");
 
    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");
 
    priv = to_lt9611_private(bridge);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
 
    client = priv->client;
    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
 
    if (client->addr == LT9611_UXC_DEV_ADDR) {
        dpu_pr_warn("[MIPI2HDMI] uxc does not support setting hdcp mode\n");
    } else {
        ret = lt9611_uxd_set_hdcp_mode(client, mode);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] uxd set hdcp mode failed, ret=%d\n", ret);
            return ret;
        }
    }
 
    dpu_pr_info("[MIPI2HDMI] -\n");
 
    return 0;
}

static int32_t lt9611_parse_delay_params(struct lt9611_private *priv)
{
    int32_t ret = 0;
    struct device_node *np = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->dev, -EINVAL, err, "[MIPI2HDMI] priv->dev is null\n");
    np = priv->dev->of_node;
    dpu_check_and_return(!np, -EINVAL, err, "[MIPI2HDMI] np is null\n");

    ret = of_property_read_u32(np, "delay_3v3", &priv->delay_3v3);
    if (ret != 0) {
        dpu_pr_warn("[MIPI2HDMI] read delay_3v3 from dts failed, ret=%d\n", ret);
        priv->delay_3v3 = LDO_3V3_DELAY_TIME_MS;
    }
    ret = of_property_read_u32(np, "delay_1v2", &priv->delay_1v2);
    if (ret != 0) {
        dpu_pr_warn("[MIPI2HDMI] read delay_1v2 from dts failed, ret=%d\n", ret);
        priv->delay_1v2 = LDO_1V2_DELAY_TIME_MS;
    }
    ret = of_property_read_u32(np, "delay_rdv_oe", &priv->delay_rdv_oe);
    if (ret != 0) {
        dpu_pr_warn("[MIPI2HDMI] read delay_rdv_oe from dts failed, ret=%d\n", ret);
        priv->delay_rdv_oe = RDV_OE_DELAY_TIME_MS;
    }
    ret = of_property_read_u32(np, "delay_rst", &priv->delay_rst);
    if (ret != 0) {
        dpu_pr_warn("[MIPI2HDMI] read delay_rst from dts failed, ret=%d\n", ret);
        priv->delay_rst = RST_DELAY_TIME_MS;
    }
    ret = of_property_read_u32(np, "delay_i2s", &priv->delay_i2s);
    if (ret != 0) {
        dpu_pr_warn("[MIPI2HDMI] read delay_i2s from dts failed, ret=%d\n", ret);
        priv->delay_i2s = I2S_DELAY_TIME_MS;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return ret;
}

static void lt9611_get_dev_addr(struct lt9611_private *priv)
{
    int32_t value = 0;
    struct i2c_client *client = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");

    client = priv->client;
    dpu_check_and_no_retval(!client, err, "[MIPI2HDMI] client is null\n");

    if (!gpio_is_valid(priv->chip_id_gpio)) {
        dpu_pr_err("[MIPI2HDMI] chip_id_gpio is invalid, chip_id_gpio=%u\n", priv->chip_id_gpio);
        return;
    }
    value = gpio_get_value(priv->chip_id_gpio);
    if (value == GPIO_HIGH_VOLTAGE) {
        client->addr = LT9611_UXD_DEV_ADDR;
    } else {
        client->addr = LT9611_UXC_DEV_ADDR;
    }

    dpu_pr_info("[MIPI2HDMI] dev_addr=%#x\n", client->addr);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static void lt9611_free_gpio(struct lt9611_private *priv)
{
    struct device *dev = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");
    dev = priv->dev;
    dpu_check_and_no_retval(!dev, err, "[MIPI2HDMI] dev is null\n");

    devm_gpio_free(dev, priv->rdv_oe_gpio);
    devm_gpio_free(dev, priv->rst_gpio);
    devm_gpio_free(dev, priv->chip_id_gpio);
    devm_gpio_free(dev, priv->i2s_gpio);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static void lt9611_free_mem(struct lt9611_private *priv)
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

static int32_t lt9611_regulator_setup(struct device *dev, struct lt9611_private *priv)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!dev, -EINVAL, err, "[MIPI2HDMI] dev is null\n");
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    ret = mipi2hdmi_regulator_init(dev, "ldo_3v3", LT9611_LDO_3V3, &priv->ldo_3v3);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to initialize ldo_3v3, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_regulator_init(dev, "ldo_1v2", LT9611_LDO_1V2, &priv->ldo_1v2);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to initialize ldo_1v2, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_gpio_setup(struct device *dev, struct lt9611_private *priv)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!dev, -EINVAL, err, "[MIPI2HDMI] dev is null\n");
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    ret = mipi2hdmi_gpio_init(dev, "rdv_oe_gpio", GPIO_DIRECTION_OUTPUT, GPIO_LOW_VOLTAGE, &priv->rdv_oe_gpio);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to initialize rdv_oe_gpio, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_gpio_init(dev, "rst_gpio", GPIO_DIRECTION_OUTPUT, GPIO_HIGH_VOLTAGE, &priv->rst_gpio);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to initialize rst_gpio, ret=%d\n", ret);
        goto rdv_oe_gpio_free;
    }
    ret = mipi2hdmi_gpio_init(dev, "chip_id_gpio", GPIO_DIRECTION_INPUT, GPIO_LOW_VOLTAGE, &priv->chip_id_gpio);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to initialize chip_id_gpio, ret=%d\n", ret);
        goto rst_gpio_free;
    }
    ret = mipi2hdmi_gpio_init(dev, "i2s_gpio", GPIO_DIRECTION_OUTPUT, GPIO_LOW_VOLTAGE, &priv->i2s_gpio);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to initialize i2s_gpio, ret=%d\n", ret);
        goto chip_id_gpio_free;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;

chip_id_gpio_free:
    devm_gpio_free(dev, priv->chip_id_gpio);
rst_gpio_free:
    devm_gpio_free(dev, priv->rst_gpio);
rdv_oe_gpio_free:
    devm_gpio_free(dev, priv->rdv_oe_gpio);

    return ret;
}

static int32_t lt9611_base_setup(struct lt9611_private *priv)
{
    int32_t ret = 0;
    struct device *dev = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dev = priv->dev;
    dpu_check_and_return(!dev, -EINVAL, err, "[MIPI2HDMI] dev is null\n");

    ret = lt9611_regulator_setup(dev, priv);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to setup regulator, ret=%d\n", ret);
        return ret;
    }
    ret = lt9611_gpio_setup(dev, priv);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to setup gpio, ret=%d\n", ret);
        return ret;
    }
    ret = lt9611_parse_delay_params(priv);
    if (ret != 0) {
        dpu_pr_warn("[MIPI2HDMI] Failed to parse delay params, ret=%d\n", ret);
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_register_bridge(struct lt9611_private *priv)
{
    int32_t ret = 0;
    struct device_node *np = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->dev, -EINVAL, err, "[MIPI2HDMI] priv->dev is null\n");
    np = priv->dev->of_node;
    dpu_check_and_return(!np, -EINVAL, err, "[MIPI2HDMI] np is null\n");

    ret = of_property_read_u32(np, "bridge_id", &priv->bridge_id);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to read bridge_id from dts, ret=%d\n", ret);
        return ret;
    }

    priv->bridge_info.bridge_id = priv->bridge_id;
    priv->bridge_info.on_func = lt9611_power_on;
    priv->bridge_info.off_func = lt9611_power_off;
    priv->bridge_info.deassert_reset = lt9611_deassert_reset;
    priv->bridge_info.read_edid = lt9611_read_edid;
    priv->bridge_info.set_display_timing = lt9611_set_display_timing;
    priv->bridge_info.enable_i2s = lt9611_enable_i2s;
    priv->bridge_info.disable_i2s = lt9611_disable_i2s;
    priv->bridge_info.set_hdcp = lt9611_set_hdcp_mode;
    ret = mipi2hdmi_register_bridge(&priv->bridge_info);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to register bridge\n");
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static void lt9611_unregister_bridge(struct lt9611_private *priv)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");

    (void)mipi2hdmi_unregister_bridge(&priv->bridge_info);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static void lt9611_fw_update_timeout_work(struct work_struct *work)
{
    int32_t ret = 0;
    struct lt9611_private *priv = container_of(work, struct lt9611_private, fw_update_timeout_work.work);

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null pointer\n");

    atomic_set(&priv->fw_update_ongoing_atom, FW_UPDATE_STATUS_DONE);
    ret = mipi2hdmi_check_online(&priv->bridge_info);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] check online failed, ret=%d\n", ret);
    }

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static struct lt9611_fw_updater_data g_lt9611_fw_updater_data = {
    .set_update_status = lt9611_set_update_status,
    .power_on_sequence = lt9611_power_on_sequence,
    .power_off_sequence = lt9611_power_off_sequence,
    .reset_chip = lt9611_reset_chip
};

static void lt9611_update_firmware(struct lt9611_private *priv)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");

    if (!g_lt9611_fw_updater) {
        dpu_pr_err("[MIPI2HDMI] g_lt9611_fw_updater is null\n");
        (void)mipi2hdmi_check_online(&priv->bridge_info);
        return;
    }
    if (!g_lt9611_fw_updater->update_firmware) {
        dpu_pr_err("[MIPI2HDMI] g_lt9611_fw_updater->update_firmware is null\n");
        (void)mipi2hdmi_check_online(&priv->bridge_info);
        return;
    }

    INIT_DELAYED_WORK(&(priv->fw_update_timeout_work), lt9611_fw_update_timeout_work);
    atomic_set(&priv->fw_update_ongoing_atom, FW_UPDATE_STATUS_NOT_STARTED);
    g_lt9611_fw_updater->update_firmware(priv->client, &g_lt9611_fw_updater_data);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static int32_t lt9611_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    struct i2c_adapter *adapter = NULL;
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    adapter = client->adapter;
    dpu_check_and_return(!adapter, -EINVAL, err, "[MIPI2HDMI] adapter is null\n");

    if (!i2c_check_functionality(adapter, I2C_FUNC_I2C)) {
        dpu_pr_err("[MIPI2HDMI] failed to i2c_check_functionality!\n");
        return -EOPNOTSUPP;
    }

    priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
    dpu_check_and_return(!priv, -ENOMEM, err, "[MIPI2HDMI] alloc lt9611 driver private data failed!\n");

    priv->dev = &client->dev;
    priv->client = client;
    i2c_set_clientdata(client, priv);

    if (lt9611_base_setup(priv)) {
        dpu_pr_err("[MIPI2HDMI] failed to setup regulator and gpio\n");
        goto mem_free;
    }

    lt9611_get_dev_addr(priv);

    if (lt9611_register_bridge(priv)) {
        dpu_pr_err("[MIPI2HDMI] failed to register bridge\n");
        goto gpio_free;
    }

    lt9611_update_firmware(priv);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;

gpio_free:
    lt9611_free_gpio(priv);
mem_free:
    lt9611_free_mem(priv);
    return -EPROBE_DEFER;
}

static void lt9611_free_regulator(struct lt9611_private *priv)
{
    dpu_pr_info("[MIPI2HDMI] +");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");

    if (priv->ldo_3v3 != NULL) {
        devm_regulator_put(priv->ldo_3v3);
        priv->ldo_3v3 = NULL;
    }
    if (priv->ldo_1v2 != NULL) {
        devm_regulator_put(priv->ldo_1v2);
        priv->ldo_1v2 = NULL;
    }

    dpu_pr_info("[MIPI2HDMI] -");
}

static int32_t lt9611_i2c_remove(struct i2c_client *client)
{
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +");

    dpu_check_and_return(!client, -EINVAL, err, "[MIPI2HDMI] client is null\n");
    priv = i2c_get_clientdata(client);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    lt9611_free_regulator(priv);
    lt9611_unregister_bridge(priv);
    lt9611_free_gpio(priv);
    lt9611_free_mem(priv);

    dpu_pr_info("[MIPI2HDMI] -");

    return 0;
}

static int32_t lt9611_i2c_suspend(struct device *dev)
{
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!dev, -EINVAL, err, "[MIPI2HDMI] dev is null\n");

    priv = (struct lt9611_private *)dev_get_drvdata(dev);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->ldo_1v2, -EINVAL, err, "[MIPI2HDMI] priv->ldo_1v2 is null\n");
    dpu_check_and_return(!priv->ldo_3v3, -EINVAL, err, "[MIPI2HDMI] priv->ldo_3v3 is null\n");

#ifdef CONFIG_SYS_PM_ULSR
    if (is_ulsr()) {
        dpu_pr_info("[MIPI2HDMI] ulsr suspend, ldo_1v2=%d, ldo_3v3=%d\n",
            regulator_get_voltage(priv->ldo_1v2), regulator_get_voltage(priv->ldo_3v3));
    }
#endif

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t lt9611_i2c_resume(struct device *dev)
{
    int32_t ret = 0;
    struct lt9611_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!dev, -EINVAL, err, "[MIPI2HDMI] dev is null\n");

    priv = (struct lt9611_private *)dev_get_drvdata(dev);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->ldo_1v2, -EINVAL, err, "[MIPI2HDMI] priv->ldo_1v2 is null\n");
    dpu_check_and_return(!priv->ldo_3v3, -EINVAL, err, "[MIPI2HDMI] priv->ldo_3v3 is null\n");

#ifdef CONFIG_SYS_PM_ULSR
    if (is_ulsr()) {
        ret = regulator_sync_voltage(priv->ldo_1v2);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] regulator_sync_voltage ldo_1v2 failed, ret=%d\n", ret);
        }
        ret = regulator_sync_voltage(priv->ldo_3v3);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] regulator_sync_voltage ldo_3v3 failed, ret=%d\n", ret);
        }
        dpu_pr_info("[MIPI2HDMI] ulsr resume, regulator sync voltage, ldo_1v2=%d, ldo_3v3=%d\n",
            regulator_get_voltage(priv->ldo_1v2), regulator_get_voltage(priv->ldo_3v3));
    }
#endif

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static const struct dev_pm_ops lt9611_pm_ops = {
    .suspend = lt9611_i2c_suspend,
    .resume = lt9611_i2c_resume,
};

static const struct i2c_device_id lt9611_i2c_ids[] = {
    { "lt,lt9611", 0 },
    {}
};

static const struct of_device_id lt9611_i2c_of_ids[] = {
    {.compatible = "lt,lt9611"},
    {}
};

static struct i2c_driver lt9611_i2c_driver = {
    .driver = {
        .name = "lt9611",
        .of_match_table = lt9611_i2c_of_ids,
        .pm = &lt9611_pm_ops,
    },
    .id_table = lt9611_i2c_ids,
    .probe = lt9611_i2c_probe,
    .remove = lt9611_i2c_remove,
};

static int32_t __init lt9611_init(void)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    ret = i2c_add_driver(&lt9611_i2c_driver);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] failed to i2c_add_driver, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static void __exit lt9611_exit(void)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    i2c_del_driver(&lt9611_i2c_driver);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

module_init(lt9611_init);
module_exit(lt9611_exit);

MODULE_AUTHOR("Graphics Display");
MODULE_DESCRIPTION("Huawei lt9611 bridge driver");
MODULE_LICENSE("GPL");