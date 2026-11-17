/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * lt9611uxd_fw.c
 *
 * lt9611uxd firmware update
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, pmicstributed, and mopmicfied under those terms.
 *
 * This program is pmicstributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "lt9611uxd_fw.h"
#include <huawei_platform/log/hw_log.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/irq.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/platform_device.h>
#include <linux/time.h>
#include <linux/types.h>
#include <linux/workqueue.h>
#include <securec.h>
#include <stdbool.h>
#include <uapi/asm-generic/fcntl.h>

#define hwlog_info(fmt, args...) pr_info("[lt9611uxd_fw]" fmt, ##args)
#define hwlog_err(fmt, args...) pr_err("[lt9611uxd_fw]" fmt, ##args)

#define READ_ONE_TIME 32
#define WRITE_SRAM_ONE_TIME 256

#define LT9611UXD_I2C_MAX_LEN 300

#define LT9611UXD_FIRMWARE_VERSION_DEFAULT 0
#define LT9611UXD_PATH "/chip_prod/etc/firmware/Monet_LT9611UXD_V1.4-h0.pc.mnt.r1/LT9611UXD_0104_20260128v1.bin"
#define LT9611UXD_BYTE_LENGTH 8

#define READ_FW_DELAY_MS 5
#define READ_FW_DELAY_CNT 75

#define RESET_AFTER_DELAY 300
#define UPDATE_TRY_TIMES 3
#define UPDATE_TRY_DLY_MS 100
#define GET_IC_VER_TRY_TIMES 3
#define GET_IC_VER_TRY_DLY_MS 200
#define OPEN_FILE_DLY_MS 500
#define FW_READ_WAIT_TIMES 200
#define SEND_BYTES_NUM 2
#define BLOCK_ERASE_DLY_MS1 100
#define BLOCK_ERASE_DLY_MS2 50
#define BLOCK_ERASE_TRY_TIMES 50
#define GET_IC_VER_WAIT_ACK_TIMES 100
#define GET_IC_VER_DATA_SIZE 6
#define IC_VER_LOCATION1 4
#define IC_VER_LOCATION2 5
#define SHIFT_16_BITS 16
#define SHIFT_8_BITS 8
#define KEY_ADDR_REGISTER2 2
#define RETURN_DATA_REG 0x85

struct update_para {
    uint8_t *bin_file1;
    int bin_file1_size;
    int firmware_version;
};

int lt9611uxd_write_block(struct i2c_client *client, unsigned char reg, unsigned char *value, unsigned short num_bytes)
{
    struct i2c_msg msg[1];
    int ret;
    uint8_t buf[LT9611UXD_I2C_MAX_LEN] = { 0 };

    if (!client || !value) {
        hwlog_err("null ptr err\n");
        return -1;
    }

    buf[0] = reg;
    ret = memcpy_s(&buf[1], sizeof(buf) - 1, value, num_bytes);
    if (ret != 0) {
        hwlog_err("[%s] memcpy_s fail\n", __func__);
        return -1;
    }
    msg[0].addr = client->addr;
    msg[0].flags = 0;
    msg[0].buf = buf;
    msg[0].len = num_bytes + 1;

    ret = i2c_transfer(client->adapter, msg, 1);
    if (ret != 1) {
        hwlog_err("i2c_write failed to transfer all messages\n");
        hwlog_err("lt9611uxd_write regoffset = %d value=%d ret = %d \n", client->addr, value, ret);
        return -1;
    }
    return 0;
}

int lt9611uxd_read_block(struct i2c_client *client, unsigned char reg, unsigned char *value, unsigned short num_bytes)
{
    struct i2c_msg msg[2];
    int ret;

    if (!client || !value) {
        hwlog_err("null ptr err\n");
        return -1;
    }

    msg[0].addr = client->addr;
    msg[0].flags = 0;
    msg[0].buf = &reg;
    msg[0].len = 1;

    msg[1].addr = client->addr;
    msg[1].flags = I2C_M_RD;
    msg[1].buf = value;
    msg[1].len = num_bytes;

    ret = i2c_transfer(client->adapter, msg, SEND_BYTES_NUM);
    if (ret != SEND_BYTES_NUM) {
        hwlog_err("i2c_read failed to transfer all messages\n");
        hwlog_err("lt9611uxd_read regoffset = %d value=%d ret = %d \n", client->addr, value[0], ret);
        return -1;
    }
    return 0;
}

static void read_i2c_byte(struct i2c_client *client, uint8_t reg, uint8_t *readData)
{
    (void)lt9611uxd_read_block(client, reg, readData, 1);
}

static uint8_t read_i2c_n_byte(struct i2c_client *client, uint8_t reg, uint8_t *readData, uint8_t len)
{
    return lt9611uxd_read_block(client, reg, readData, len);
}

static void write_i2c_byte(struct i2c_client *client, uint8_t reg, uint8_t data)
{
    (void)lt9611uxd_write_block(client, reg, &data, 1);
}

static void write_i2c_n_bytes(struct i2c_client *client, uint8_t reg, uint8_t *data, uint32_t ulLength)
{
    (void)lt9611uxd_write_block(client, reg, data, ulLength);
}

static uint8_t flash_read_flash_status_reg(struct i2c_client *client)
{
    uint8_t ucFlashStatusReg = 0;

    write_i2c_byte(client, 0xFF, 0xE1);
    write_i2c_byte(client, 0x03, 0x3F);
    write_i2c_byte(client, 0x03, 0xFF);

    write_i2c_byte(client, 0xFF, 0xE0);
    write_i2c_byte(client, 0x5E, 0x40);
    write_i2c_byte(client, 0x56, 0x05);
    write_i2c_byte(client, 0x55, 0x25);
    write_i2c_byte(client, 0x55, 0x01);
    write_i2c_byte(client, 0x58, 0x21);

    (void)read_i2c_byte(client, 0x5f, &ucFlashStatusReg);

    return ucFlashStatusReg;
}

static void flash_configure_parameters(struct i2c_client *client)
{
    write_i2c_byte(client, 0xFF, 0xE0);
    write_i2c_byte(client, 0xEE, 0x01);
    write_i2c_byte(client, 0x5E, 0xC1);
    write_i2c_byte(client, 0x58, 0x00);
    write_i2c_byte(client, 0x59, 0x50);
    write_i2c_byte(client, 0x5A, 0x10);
    write_i2c_byte(client, 0x5A, 0x00);
    write_i2c_byte(client, 0x58, 0x21);
}

static void flash_block_erase(struct i2c_client *client)
{
    uint32_t i = 0;
    uint8_t ucFlashStatuss = 0;
    write_i2c_byte(client, 0xFF, 0xE0);
    write_i2c_byte(client, 0xEE, 0x01);
    write_i2c_byte(client, 0x5A, 0x04);
    write_i2c_byte(client, 0x5A, 0x00);
    write_i2c_byte(client, 0x5B, 0x00);
    write_i2c_byte(client, 0x5C, 0x00);
    write_i2c_byte(client, 0x5D, 0x00);
    write_i2c_byte(client, 0x5A, 0x01);
    write_i2c_byte(client, 0x5A, 0x00);
    msleep(BLOCK_ERASE_DLY_MS1);

    i = 0;
    while (1) {
        ucFlashStatuss = flash_read_flash_status_reg(client);
        if ((ucFlashStatuss & 0x01) == 0) {
            break;
        }

        if (i > BLOCK_ERASE_TRY_TIMES) {
            break;
        }
        i++;
        msleep(BLOCK_ERASE_DLY_MS2);
    }

    write_i2c_byte(client, 0xFF, 0xE0);
    write_i2c_byte(client, 0xEE, 0x01);
    write_i2c_byte(client, 0x5A, 0x04);
    write_i2c_byte(client, 0x5A, 0x00);
    write_i2c_byte(client, 0x5B, 0x00);
    write_i2c_byte(client, 0x5C, 0x80);
    write_i2c_byte(client, 0x5D, 0x00);
    write_i2c_byte(client, 0x5A, 0x01);
    write_i2c_byte(client, 0x5A, 0x00);
    msleep(BLOCK_ERASE_DLY_MS1);

    i = 0;
    while (1) {
        ucFlashStatuss = flash_read_flash_status_reg(client);
        if ((ucFlashStatuss & 0x01) == 0) {
            break;
        }

        if (i > BLOCK_ERASE_TRY_TIMES) {
            break;
        }
        i++;
        msleep(BLOCK_ERASE_DLY_MS2);
    }
}

static void flash_write_disable(struct i2c_client *client)
{
    if (!client) {
        return;
    }
    write_i2c_byte(client, 0xFF, 0xE0);
    write_i2c_byte(client, 0x5A, 0x08);
    write_i2c_byte(client, 0x5A, 0x00);
}

static void flash_to_sram(struct i2c_client *client)
{
    if (!client) {
        return;
    }
    write_i2c_byte(client, 0xFF, 0xE1);
    write_i2c_byte(client, 0x03, 0x2F);
    write_i2c_byte(client, 0x03, 0xEF);

    write_i2c_byte(client, 0xFF, 0xE0);
    write_i2c_byte(client, 0xFF, 0xE0);
    write_i2c_byte(client, 0xEE, 0x01);

    write_i2c_byte(client, 0x52, 0x00);
    write_i2c_byte(client, 0x53, 0x00);
    write_i2c_byte(client, 0x55, 0xC0);

    write_i2c_byte(client, 0x5A, 0x04);
    write_i2c_byte(client, 0x5A, 0x00);
}

static void flash_write_flash_with_sram(struct i2c_client *client, uint8_t *ucData, uint32_t ulOffset,
    uint32_t ulLength)
{
    uint8_t sramBuffer[WRITE_SRAM_ONE_TIME];
    int ret;
    if (!client || !ucData) {
        hwlog_err("[%s:] ptr null\n", __func__);
        return;
    }

    if (memset_s(sramBuffer, sizeof(sramBuffer), 0xFF, sizeof(sramBuffer))) {
        hwlog_err("[%s:] memset_s err\n", __func__);
        return;
    }
    ret = memcpy_s(sramBuffer, sizeof(sramBuffer), &ucData[ulOffset], ulLength);
    if (ret != 0) {
        hwlog_err("[%s:] memcpy_s err\n", __func__);
        return;
    }

    write_i2c_byte(client, 0xFF, 0xE0); // Wren.

    write_i2c_byte(client, 0x51, 0xFF);

    write_i2c_byte(client, 0x55, 0x80); // I2c to sram
    write_i2c_byte(client, 0x5E, 0xc0);
    write_i2c_byte(client, 0x58, 0x21);

    // Write regsister 0xe059 with 256 bytes.
    write_i2c_n_bytes(client, 0x59, sramBuffer, sizeof(sramBuffer));

    write_i2c_byte(client, 0x5B, ulOffset >> 16); // set flash address[23:16]
    write_i2c_byte(client, 0x5C, ulOffset >> 8);  // set flash address[15:8]
    write_i2c_byte(client, 0x5D, ulOffset);       // set flash address[7:0]

    write_i2c_byte(client, 0x5A, 0x04);
    write_i2c_byte(client, 0x5A, 0x00); // spi write WREN cmd.

    write_i2c_byte(client, 0x5A, 0x30);
    write_i2c_byte(client, 0x5A, 0x00); // spi write 256 bytes
}

static void flash_write_sram_end(struct i2c_client *client)
{
    write_i2c_byte(client, 0xff, 0xe0);
    write_i2c_byte(client, 0x55, 0x00);
}

static int lt9611uxd_update_param_init(struct device_node *node, struct update_para *update_param)
{
    int ret;
    if (!node || !update_param) {
        hwlog_err("[%s:] update param input params null\n", __func__);
        return UPDATE_ECODE_NULL_PTR;
    }

    update_param->firmware_version = LT9611UXD_FIRMWARE_VERSION_DEFAULT;
    ret = of_property_read_u32(node, "firmware_version_uxd", &update_param->firmware_version);
    if (ret != 0) {
        hwlog_err("[%s:] read fw_version from dts err. ret = %d\n", __func__, ret);
        return UPDATE_ECODE_READ_DTS;
    }

    return UPDATE_ECODE_OK;
}

static int lt9611uxd_read_fw_file(struct device_node *node, struct update_para *update_param)
{
    char *bin_file1;
    struct file *f_bin1 = NULL;
    mm_segment_t fs;
    loff_t pos_a = 0;
    int ret;

    if (!node || !update_param) {
        hwlog_err("[%s:] update param input params null\n", __func__);
        return UPDATE_ECODE_NULL_PTR;
    }

    for (int i = 0; i < FW_READ_WAIT_TIMES; i++) {
        f_bin1 = filp_open(LT9611UXD_PATH, O_RDONLY, 0);
        if (f_bin1 == NULL || IS_ERR(f_bin1) || f_bin1->f_inode == NULL) {
            hwlog_err("[%s:] file %s open fail , times: %d\n", __func__, LT9611UXD_PATH, i);
            msleep(OPEN_FILE_DLY_MS);
        } else {
            hwlog_err("[%s:] file %s open success , times: %d\n", __func__, LT9611UXD_PATH, i);
            break;
        }
    }
    if (f_bin1 == NULL || IS_ERR(f_bin1) || f_bin1->f_inode == NULL) {
        hwlog_err("[%s:] file %s open fail,PTR_ERR = %d\n", __func__, LT9611UXD_PATH, PTR_ERR(f_bin1));
        return UPDATE_ECODE_F_OPEN;
    }

    update_param->bin_file1_size = f_bin1->f_inode->i_size;

    bin_file1 = kzalloc(update_param->bin_file1_size, GFP_KERNEL);
    if (bin_file1 == NULL) {
        hwlog_err("[%s:] kzalloc err\n", __func__);
        filp_close(f_bin1, NULL);
        return UPDATE_ECODE_KZALLOC;
    }

    fs = get_fs();
    set_fs(KERNEL_DS);
    hwlog_info("[%s:] file read begin\n", __func__);
    if (vfs_read(f_bin1, bin_file1, update_param->bin_file1_size, &pos_a) != update_param->bin_file1_size) {
        set_fs(fs);
        filp_close(f_bin1, NULL);
        kfree(bin_file1);
        hwlog_info("[%s:] file read fail\n", __func__);
        return UPDATE_ECODE_VFS_READ;
    }
    hwlog_info("[%s:] file read end\n", __func__);
    update_param->bin_file1 = bin_file1;

    set_fs(fs);
    filp_close(f_bin1, NULL);

    return UPDATE_ECODE_OK;
}

void lt9611uxd_write_with_sram(struct i2c_client *client, uint8_t *ucData, uint32_t ulFwSize)
{
    uint32_t ulLength;
    uint32_t i;
    uint32_t ulFlashAddr = 0;
    uint8_t ucLastDateLangth;
    hwlog_info("[%s:] begin\n", __func__);

    if (!client || !ucData) {
        hwlog_err("[%s:] input params null\n", __func__);
        return;
    }

    ulLength = ulFwSize;
    // write 256 bytes every time in sram mode.
    ulLength = (ulLength + (WRITE_SRAM_ONE_TIME - 1)) / WRITE_SRAM_ONE_TIME;
    hwlog_info("[%s:] ucData's page around:%d\n", __func__, ulLength);

    ucLastDateLangth = ulFwSize % WRITE_SRAM_ONE_TIME;

    flash_configure_parameters(client);
    flash_block_erase(client);

    flash_to_sram(client);

    for (i = 0; i < ulLength; i++) {
        // the last 256 bytes
        if ((ucLastDateLangth != 0) && (i == (ulLength - 1))) {
            flash_write_flash_with_sram(client, ucData, ulFlashAddr, ucLastDateLangth);
        } else {
            flash_write_flash_with_sram(client, ucData, ulFlashAddr, WRITE_SRAM_ONE_TIME);
        }
        ulFlashAddr += WRITE_SRAM_ONE_TIME;
    }

    flash_write_disable(client);
    flash_write_sram_end(client);
    hwlog_info("[%s:] end\n", __func__);
}

static int lt9611uxd_version_check(const struct update_para *update_param, uint16_t ic_ver)
{
    if (!update_param) {
        hwlog_err("[%s:] version check input params null\n", __func__);
        return UPDATE_ECODE_NULL_PTR;
    }

    if (ic_ver == update_param->firmware_version) {
        hwlog_err("[%s:] no new version. ic_ver = %02x, target = %02x\n", __func__, ic_ver,
            update_param->firmware_version);
        return UPDATE_ECODE_NO_NEW;
    }

    if (ic_ver > update_param->firmware_version) {
        hwlog_err("[%s:] Prohibit upgrading from high version to low version. ic_ver = %02x, target = %02x\n", __func__,
            ic_ver, update_param->firmware_version);
        return UPDATE_ECODE_NO_ROLLBACK;
    }

    hwlog_info("[%s:] ready to upgrade lt9611uxd from ver %02x to %02x\n", __func__, ic_ver,
        update_param->firmware_version);
    return UPDATE_ECODE_OK;
}

static int lt9611uxd_get_ic_version(struct i2c_client *client, uint16_t *ver)
{
    if (!client) {
        hwlog_err("[%s:] get ic_version params null\n", __func__);
        return UPDATE_ECODE_NULL_PTR;
    }
    uint8_t ic_ver1 = 0;
    uint8_t ic_ver2 = 0;
    unsigned char temp = 0;
    unsigned char count = 0;
    unsigned char rxbuff[GET_IC_VER_DATA_SIZE] = { 0 };

    // Write Start
    write_i2c_byte(client, 0xFF, 0xE0);
    write_i2c_byte(client, 0xDE, 0x01);

    // Read Ack 01
    count = 0;
    do {
        read_i2c_byte(client, 0xAE, &temp);
        msleep(1);
        count++;
    } while ((count < GET_IC_VER_WAIT_ACK_TIMES) && (temp != 0x01));
    if (count >= GET_IC_VER_WAIT_ACK_TIMES) {
        return UPDATE_ECODE_GET_IC_VER;
    }

    // Write Cmd Content
    write_i2c_byte(client, 0xB0, 0x52);
    write_i2c_byte(client, 0xB1, 0x43);
    write_i2c_byte(client, 0xB2, 0x31);
    write_i2c_byte(client, 0xB3, 0x3A);
    write_i2c_byte(client, 0xB4, 0x00);

    // Write End
    write_i2c_byte(client, 0xFF, 0xE0);
    write_i2c_byte(client, 0xDE, 0x02);

    // Read Ack 02
    count = 0;
    do {
        read_i2c_byte(client, 0xAE, &temp);
        msleep(1);
        count++;
    } while ((count < GET_IC_VER_WAIT_ACK_TIMES) && (temp != 0x02));
    if (count >= GET_IC_VER_WAIT_ACK_TIMES) {
        return UPDATE_ECODE_GET_IC_VER;
    }

    // Read Return Data
    for (count = 0; count < GET_IC_VER_DATA_SIZE; count++) {
        read_i2c_byte(client, RETURN_DATA_REG + count, &rxbuff[count]);
    }

    ic_ver1 = rxbuff[IC_VER_LOCATION1];
    ic_ver2 = rxbuff[IC_VER_LOCATION2];
    hwlog_info("[%s:] get ic_version success. verion = V%x.%x\n", __func__, ic_ver1, ic_ver2);
    *ver = (ic_ver1 << LT9611UXD_BYTE_LENGTH) | (ic_ver2);

    return UPDATE_ECODE_OK;
}

static void lt9611uxd_read_fw(struct i2c_client *client, uint8_t *fw_data, uint32_t fw_size)
{
    hwlog_info("[%s:] begin. fw_size = %u\n", __func__, fw_size);
    if (!client || !fw_data) {
        hwlog_err("[%s:] params null\n", __func__);
        return;
    }

    flash_configure_parameters(client);

    uint8_t key_addr[3] = { 0, 0, 0 };
    uint32_t start_addr = 0;
    uint16_t loop = 0;
    loop = (fw_size % READ_ONE_TIME != 0) ? ((fw_size / READ_ONE_TIME) + 1) : (fw_size / READ_ONE_TIME);

    for (int i = 0; i < loop; i++) {
        // flash to fifo
        write_i2c_byte(client, 0x5E, 0x5f);
        write_i2c_byte(client, 0x5A, 0x20);
        write_i2c_byte(client, 0x5A, 0x00);

        // set reading address
        write_i2c_byte(client, 0x5B, key_addr[0]);
        write_i2c_byte(client, 0x5C, key_addr[1]);
        write_i2c_byte(client, 0x5D, key_addr[KEY_ADDR_REGISTER2]);

        write_i2c_byte(client, 0x5A, 0x10);
        write_i2c_byte(client, 0x5A, 0x00);

        write_i2c_byte(client, 0x58, 0x21);
        // read 32 bytes of data from SPI FIFO
        (void)read_i2c_n_byte(client, 0x5F, &(fw_data[i * READ_ONE_TIME]), 0x20);

        start_addr += READ_ONE_TIME;
        key_addr[0] = (start_addr & 0xFF0000) >> SHIFT_16_BITS;
        key_addr[1] = (start_addr & 0xFF00) >> SHIFT_8_BITS;
        key_addr[KEY_ADDR_REGISTER2] = (start_addr & 0xFF);
        if ((i % READ_FW_DELAY_CNT) == 0) {
            msleep(READ_FW_DELAY_MS);
        }
    }
    flash_write_disable(client);

    hwlog_info("[%s:] end\n", __func__);
}

static int lt9611uxd_flash_validate(struct i2c_client *client, const struct update_para *para)
{
    uint8_t *fw = NULL;
    hwlog_info("[%s:] begin\n", __func__);

    if (!client || !para) {
        hwlog_err("[%s:] input params null\n", __func__);
        return UPDATE_ECODE_NULL_PTR;
    }

    if (para->bin_file1_size == 0 || para->bin_file1 == NULL) {
        hwlog_err("[%s:] bin_file1 err\n", __func__);
        return UPDATE_ECODE_PARA;
    }

    fw = kzalloc(para->bin_file1_size, GFP_KERNEL);
    if (fw == NULL) {
        hwlog_err("[%s:] kzalloc err\n", __func__);
        return UPDATE_ECODE_KZALLOC;
    }
    lt9611uxd_read_fw(client, fw, para->bin_file1_size);
    if (memcmp(fw, para->bin_file1, para->bin_file1_size)) {
        hwlog_err("[%s:] firmware read memcmp err\n", __func__);
        kfree(fw);
        fw = NULL;
        return UPDATE_ECODE_FW_MEM_COMP;
    }
    kfree(fw);
    fw = NULL;

    hwlog_info("[%s:] success\n", __func__);
    return UPDATE_ECODE_OK;
}

static int lt9611uxd_send_fw(struct i2c_client *client, struct update_para *update_param)
{
    struct device_node *node = NULL;
    uint8_t *fw_file = NULL;
    int fw_size = 0;
    int ret;

    hwlog_info("[%s:] begin\n", __func__);
    if (!client || !update_param) {
        hwlog_err("[%s:] send firmware input params null\n", __func__);
        return UPDATE_ECODE_NULL_PTR;
    }

    node = client->dev.of_node;
    ret = lt9611uxd_read_fw_file(node, update_param);
    if (ret != UPDATE_ECODE_OK) {
        hwlog_err("[%s:] read firmware file fail!!!\n", __func__);
        return ret;
    }

    fw_file = update_param->bin_file1;
    fw_size = update_param->bin_file1_size;

    lt9611uxd_write_with_sram(client, fw_file, fw_size);

    hwlog_info("[%s:] success\n", __func__);
    return UPDATE_ECODE_OK;
}

static void lt9611uxd_reset(hard_reset_func_t reset_func)
{
    hwlog_info("[%s:] begin\n", __func__);
    if (!reset_func) {
        hwlog_err("[%s:] invalid parameter\n", __func__);
        return;
    }
    reset_func();
    msleep(RESET_AFTER_DELAY);
    hwlog_info("[%s:] success\n", __func__);
}

static int lt9611uxd_flash_proc(struct i2c_client *client, struct update_para *update_param,
    hard_reset_func_t reset_func)
{
    uint16_t ic_ver = 0;
    int ret;

    if (!client || !update_param || !reset_func) {
        hwlog_err("[%s:] flash proc input params null\n", __func__);
        return UPDATE_ECODE_NULL_PTR;
    }

    lt9611uxd_reset(reset_func);

    unsigned char reg = 0xE0;
    ret = lt9611uxd_write_block(client, 0xFF, &reg, 1);
    if (ret != 0) {
        hwlog_info("[%s:] I2C communication failure\n", __func__);
        return ret;
    }

    ret = lt9611uxd_get_ic_version(client, &ic_ver);
    if (ret != UPDATE_ECODE_OK) {
        hwlog_err("[%s:] get_ic_version failed at begin. ret = %d\n", __func__, ret);
    } else {
        ret = lt9611uxd_version_check(update_param, ic_ver);
        if (ret == UPDATE_ECODE_NO_NEW) {
            return UPDATE_ECODE_OK;
        }
        if (ret != UPDATE_ECODE_OK) {
            hwlog_err("[%s:] lt9611uxd_version_check err\n", __func__);
            return ret;
        }
    }

    ret = lt9611uxd_send_fw(client, update_param);
    if (ret != UPDATE_ECODE_OK) {
        hwlog_err("[%s:] read and send firmware file fail!!!\n", __func__);
        return ret;
    }

    ret = lt9611uxd_flash_validate(client, update_param);
    if (ret != UPDATE_ECODE_OK) {
        hwlog_err("[%s:] flash validate fail. ret = %d\n", __func__, ret);
        return ret;
    }

    lt9611uxd_reset(reset_func);

    ic_ver = 0;
    ret = lt9611uxd_get_ic_version(client, &ic_ver);
    if (ret != UPDATE_ECODE_OK) {
        hwlog_err("[%s:] get_ic_version failed at end. ret = %d\n", __func__, ret);
        return ret;
    }

    if (ic_ver != update_param->firmware_version) {
        hwlog_err("[%s:] ver check after update err. ic_ver = %02x, tar_ver = %02x\n", __func__, ic_ver,
            update_param->firmware_version);
    }

    return UPDATE_ECODE_OK;
}

int lt9611uxd_update(struct i2c_client *client, struct device_node *node, hard_reset_func_t reset_func)
{
    int ret;
    struct update_para update_param = { 0, 0, 0 };
    hwlog_info("[%s:] begin\n", __func__);

    if (!client || !node || !reset_func) {
        hwlog_err("[%s:] update firmware input params fail\n", __func__);
        return UPDATE_ECODE_NULL_PTR;
    }

    hwlog_info("[%s:] client's addr is %x\n", __func__, client->addr);

    ret = lt9611uxd_update_param_init(node, &update_param);
    if (ret != UPDATE_ECODE_OK) {
        hwlog_err("[%s:] update param init fail!!!\n", __func__);
        reset_func();
        msleep(RESET_AFTER_DELAY);
        return ret;
    }

    for (int i = 0; i < UPDATE_TRY_TIMES; ++i) {
        ret = lt9611uxd_flash_proc(client, &update_param, reset_func);
        if (ret == UPDATE_ECODE_OK) {
            break;
        } else if (ret == UPDATE_ECODE_NO_ROLLBACK) {
            hwlog_err("[%s:] Prohibit upgrading from high version to low version\n", __func__);
            break;
        }
        msleep(UPDATE_TRY_DLY_MS);
    }

    if (update_param.bin_file1_size != 0) {
        kfree(update_param.bin_file1);
        update_param.bin_file1 = NULL;
        update_param.bin_file1_size = 0;
    }

    if (ret != UPDATE_ECODE_OK) {
        hwlog_err("[%s:] lt9611uxd_flash_proc fail\n", __func__);
        return ret;
    }
    hwlog_info("[%s:] success\n", __func__);
    return ret;
}