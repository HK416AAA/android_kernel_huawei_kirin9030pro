/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
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

#include <securec.h>
#include <linux/miscdevice.h>
#include <linux/i2c.h>
#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/delay.h>
#include <linux/firmware.h>
#include <linux/workqueue.h>
#include <linux/syscalls.h>
#include "edp_log.h"
#include "tcon_i2c_upgrade.h"
#include "tcon_i2c.h"
#include "edp_drv/edp_panel_drv.h"

#define LEN_WR_MSG     1
#define LEN_RD_MSG     2
#define READ_REG_LOOP  10
#define TCON_UPDATE_DELAY_MS 10000
#define WAIT_CHIP_PROD_MS 60000
#define WAIT_FIRMWARE 2000
#define CHECK_VENDOR_ENABLE     true
#define WRITE_DATA_LEN 10
#define WRITE_DATA_HEAD 0x5
#define WRITE_DATA_TAIL 0x1
#define READ_CMD_LEN 6
#define READ_VALUE_LEN 5
#define READ_CMD_HEAD 0x06
#define ADDR_IND 1
#define VAL_IND 5
#define HEX_BIT_LEN 8
#define HEX_THREE_BIT_LEN 24
#define GET_SN_CODE 0xF1010130

#ifdef EDP_FACTORY_MODE
#define EDP_IOC_MAGIC  'E'
#define I2C_DATA_MAX 300

struct edp_ioctl_data_t {
    unsigned char *send_buf;
    unsigned int send_size;
    unsigned char *recv_buf;
	unsigned int recv_size;
};

#define EDP_IOCWRITEDATA  _IOW(EDP_IOC_MAGIC,  1, struct edp_ioctl_data_t)
#define EDP_IOCREADDATA   _IOR(EDP_IOC_MAGIC,  2, struct edp_ioctl_data_t)
#endif

static struct i2c_client *g_tcon_i2c_client = NULL;
static struct delayed_work g_work;
static struct fw_name_list g_fw_name;
struct mutex tcon_i2c_mutex = { 0 };
static bool g_enter_recovery = false;

struct fw_name_list get_fw_name_list(void)
{
	return g_fw_name;
}

static int __init early_parse_recovery_cmdline(char *p)
{
	if (p) {
		g_enter_recovery = (strncmp(p, "1", 1) == 0) ? true : false; // strlen"1" is 1
		edp_info("enter_mode = %s\n", g_enter_recovery ? "recovery" : "normal");
	}

	return 0;
}
early_param("enter_recovery", early_parse_recovery_cmdline);

static int tcon_i2c_write_block_without_cmd(struct i2c_client *client, u8 *buf, u32 buf_len)
{
    struct i2c_msg msg[LEN_WR_MSG];

    if (!client || !buf) {
		edp_err("client or buf is null\n");
		return -EINVAL;
	}
	/* flags: 0 is write data, from master to slave */
	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].buf = buf;
	msg[0].len = buf_len;

	/* i2c_transfer return number of messages transferred */
	if (i2c_transfer(client->adapter, msg, LEN_WR_MSG) != LEN_WR_MSG) {
		edp_err("addr=%x write fail\n", client->addr);
		return -EIO;
	}
	return 0;
}

static int tcon_i2c_read_block_without_cmd(struct i2c_client *client,
	u8 *buf, u32 buf_len)
{
	struct i2c_msg msg;

	if (!client || !buf) {
		edp_err("client or buf is null\n");
		return -EINVAL;
	}

	/* flags: I2C_M_RD is read data, from slave to master */
	msg.addr = client->addr;
	msg.flags = I2C_M_RD;
	msg.buf = buf;
	msg.len = buf_len;

	if (i2c_transfer(client->adapter, &msg, 1) != 1) {
		edp_err("addr=%x read fail\n", client->addr);
		return -EIO;
	}

	return 0;
}

int tcon_i2c_write_block(u8 *value, u32 len)
{
    int ret = 0;

    if (!value) {
        edp_err("value is null\n");
        return -EINVAL;
    }
    ret = tcon_i2c_write_block_without_cmd(g_tcon_i2c_client, value, len);
    if (ret != 0)
        edp_err("edp i2c write fail\n");

    return ret;
}

int tcon_i2c_read_block(u8 *value, u32 value_len)
{
    int ret = 0;

    if (!value) {
        edp_err("value is null\n");
        return -EINVAL;
    }
    ret = tcon_i2c_read_block_without_cmd(g_tcon_i2c_client, value, value_len);
    if (ret != 0)
        edp_err("edp i2c read fail\n");

    return ret;
}

int tcon_i2c_write_addr(unsigned int addr, unsigned int value)
{
    unsigned char data[WRITE_DATA_LEN] = {0};
	int ret = 0;

	/* set data head&tail */
    data[0] = WRITE_DATA_HEAD;
	data[WRITE_DATA_LEN - 1] = WRITE_DATA_TAIL;
    *(unsigned int *)&data[ADDR_IND] = addr;
    *(unsigned int *)&data[VAL_IND] = value;
    ret = tcon_i2c_write_block(data, WRITE_DATA_LEN);
	if (ret != 0)
        edp_err("edp i2c write fail\n");
    udelay(200);
    return ret;
}

unsigned int tcon_i2c_read_addr(unsigned int addr)
{
	unsigned char cmd[READ_CMD_LEN] = { 0x0 };
	unsigned char value[READ_VALUE_LEN] = { 0x0 };
	int i;
	int ret = 0;

	cmd[0] = READ_CMD_HEAD;
	*((unsigned int *)&cmd[ADDR_IND]) = addr;
	cmd[READ_CMD_LEN - 1] = (unsigned char)(cmd[0] + cmd[1] + cmd[2] + cmd[3] + cmd[4]);
	for (i = 0; i < READ_REG_LOOP; i++) {
		ret = tcon_i2c_write_block(cmd, READ_CMD_LEN);
		if (ret < 0) {
			edp_warn("write block failed, try again!\n");
			continue;
		}
		mdelay(5);
		ret = tcon_i2c_read_block(value, READ_VALUE_LEN);
		if (ret < 0) {
			edp_warn("read block failed, try again!\n");
			continue;
		}
		if (value[READ_VALUE_LEN - 1] == (unsigned char)(value[0] + value[1] + value[2] + value[3] + cmd[0]))
			return *(unsigned int *)value;
		mdelay(1);
	}
	edp_err("get failed read %x!\n", addr);
	return 0xBADBEEF;
}

static unsigned int swap_endian_order(unsigned int value)
{
    unsigned int temp = 0;

    temp = ((value & 0x000000FF) << HEX_THREE_BIT_LEN) +
        ((value & 0x0000FF00) << HEX_BIT_LEN) +
        ((value & 0x00FF0000) >> HEX_BIT_LEN) +
        ((value & 0xFF000000) >> HEX_THREE_BIT_LEN);

    return temp;
}

void parse_edp_tcon_info(void)
{
    int ret = 0;
    uint32_t temp = 0;
    struct edp_drv_info *tcon_info = NULL;

    tcon_info = get_edp_drv_info();
    if (!tcon_info) {
        edp_err("tcon_info is null\n");
        return;
    }
    ret = get_tconic_vendor(&tcon_info->vendor, &tcon_info->version);
    if (ret) {
        edp_err("get tconic vendor fail %d\n", ret);
        tcon_info->vendor = 0;
    }
    temp = tcon_i2c_read_addr(GET_SN_CODE);
    if (temp == 0xBADBEEF) { // if read fail will return 0xBADBEEF
        edp_err("sncode read fail!\n");
        tcon_info->sn_code = 0;
    } else {
        tcon_info->sn_code = swap_endian_order(temp);
    }
    edp_info("vendor %04x version %04x", tcon_info->vendor, tcon_info->version);
}

static void wait_chip_prod_mount(int timeout)
{
	int wait_time;
	unsigned long old_fs;
	const int schedule_time = 1000;
	const char *chip_prod_partition = "/chip_prod/etc/firmware";

	old_fs = get_fs();

	for (wait_time = 0; wait_time < timeout; wait_time += schedule_time) {
		if (!ksys_access(chip_prod_partition, 0))
			break;

		msleep(schedule_time);
	}

	set_fs(old_fs);
}

int check_tcon_firmware(const struct firmware **fw, uint16_t *vendor, uint16_t *version,
                        bool check_vendor, unsigned char partition)
{
    int ret;
	const char *fw_name = NULL;
	int i;

    if (vendor == NULL || version == NULL) {
        edp_err("vendor or version is null\n");
		return -EINVAL;
    }
	ret = get_tconic_vendor(vendor, version);
    if (ret != 0) {
        edp_err("get vendor failed! stop upgrade\n");
		return -EINVAL;
	}

	for (i = 0; i < g_fw_name.count; i++) {
		fw_name = g_fw_name.name_list[i];
		ret = request_firmware(fw, fw_name, &g_tcon_i2c_client->dev);
		if (ret) {
			edp_err("%s request firmware failed, ret: %d\n", fw_name, ret);
			continue;
		}
		ret = check_bin_valid(*fw, *vendor, *version, check_vendor, partition);
		if (ret != TCON_CHECK_SUCCESS) {
			edp_warn("upgrade bin %s is invalid, check next bin, err code %d!\n", fw_name, ret);
            if (*fw) {
                release_firmware(*fw);
                *fw = NULL;
            }
            if (ret == TCON_NOT_NEED_UPGRADE) {
                edp_info("tcon do not need upgrade!\n");
                return TCON_NOT_NEED_UPGRADE;
            }
			continue;
		}
		edp_info("upgrade bin %s is valid, request upgrade!\n", fw_name);
		break;
	}
	if (i >= g_fw_name.count) {
		edp_warn("no vaild bin, can not upgrade\n");
		return -EINVAL;
	}

	return 0;
}

static void edp_tcon_update(struct work_struct *work)
{
	const struct firmware *fw = NULL;
    uint16_t vendor = 0;
    uint16_t version = 0;
	int ret;

	edp_info("enter\n");
	wait_chip_prod_mount(WAIT_CHIP_PROD_MS);
	msleep(WAIT_FIRMWARE);

    ret = check_tcon_firmware(&fw, &vendor, &version, CHECK_VENDOR_ENABLE, MAIN_PARTITION);
	if (ret) {
		edp_err("check dts firmware fail\n");
		return;
	}
	ret = update_tconic_fw_request(fw, vendor, version, MAIN_PARTITION);
	if (ret != 0)
		edp_err("upgrade fail\n");
	else
		edp_info("edp tcon upgarde success!!!\n");
    if (fw)
	    release_firmware(fw);
}

#ifdef EDP_FACTORY_MODE
static int edp_ioctl_write_data(void __user *argp)
{
    struct edp_ioctl_data_t rdata;
    unsigned char *temp = NULL;
    int ret;
    int size = sizeof(struct edp_ioctl_data_t);

    ret = (int)copy_from_user(&rdata, argp, size);
    if (ret) {
        edp_err("first copy_from_user err\n");
        return -EFAULT;
    }
    if (!rdata.send_buf) {
        edp_err("send_buf is nul\n");
        return -EFAULT;
    }
    if (!rdata.send_size || rdata.send_size > I2C_DATA_MAX) {
        edp_err("send_size %d is null\n", rdata.send_size);
        return -EFAULT;
    }
    temp = kmalloc(rdata.send_size, GFP_KERNEL);
    if (temp == NULL) {
        edp_err("malloc copy_from_user temp fail");
        return -ENOMEM;
    }
    if (memset_s(temp, rdata.send_size, 0, rdata.send_size) != EOK) {
        edp_err("memset_s fail\n");
        goto err;
    }
    ret = (int)copy_from_user(temp, rdata.send_buf, rdata.send_size);
    if (ret) {
        edp_err("second copy_from_user err\n");
        goto err;
    }
    ret = tcon_i2c_write_block(temp, rdata.send_size);
    if (ret != 0) {
        edp_err("edp i2c write fail\n");
        goto err;
    }
    if (temp) {
        kfree(temp);
        temp = NULL;
    }
    return 0;

err:
    if (temp) {
        kfree(temp);
        temp = NULL;
    }
    return -EFAULT;
}

static int edp_ioctl_read_data(void __user *argp)
{
    struct edp_ioctl_data_t rdata;
    unsigned char *temp = NULL;
    int ret;
    int size = sizeof(struct edp_ioctl_data_t);

    ret = copy_from_user(&rdata, argp, size);
    if (ret) {
        edp_err("EDP_IOCREADDATA copy_from_user err\n");
        return -EFAULT;
    }
    if (!rdata.recv_buf) {
        edp_err("recv_buf is nul\n");
        return -EFAULT;
    }
    if (!rdata.recv_size || rdata.recv_size > I2C_DATA_MAX) {
        edp_err("recv_size is nul\n");
        return -EFAULT;
    }
    temp = kmalloc(rdata.recv_size, GFP_KERNEL);
    if (temp == NULL) {
        edp_err("malloc copy_from_user temp fail");
        return -ENOMEM;
    }
    if (memset_s(temp, rdata.recv_size, 0, rdata.recv_size) != EOK) {
        edp_err("memset_s fail\n");
        goto err;
    }
    ret = tcon_i2c_read_block(temp, rdata.recv_size);
    if (ret != 0) {
        edp_err("edp i2c read fail\n");
        goto err;
    }
    copy_to_user(rdata.recv_buf, temp, rdata.recv_size);
    if (temp) {
        kfree(temp);
        temp = NULL;
    }
    return 0;
err:
    if (temp) {
        kfree(temp);
        temp = NULL;
    }
    return -EFAULT;
}

static long tcon_updater_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int ret;
    void __user *argp = (void __user *)(uintptr_t)arg;

    if (!argp) {
        edp_err("argp is nullptr\n");
        return -EINVAL;
    }
    switch (cmd) {
        case EDP_IOCWRITEDATA: /* write data */
            ret = edp_ioctl_write_data(argp);
            break;
        case EDP_IOCREADDATA: /* read data */
            ret = edp_ioctl_read_data(argp);
            break;
        default:
            edp_err("tcon i2c ioctl cmd not find\n");
            return -EFAULT;
    }
    return ret;
}

static const struct file_operations tcon_upater_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = tcon_updater_ioctl,
};

static struct miscdevice tcon_updater_miscdev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "tcon_i2c_updater",
    .fops = &tcon_upater_fops,
};
#endif

static int tcon_i2c_probe(struct i2c_client *i2c, const struct i2c_device_id *id)
{
	int ret;
	unsigned int enable_tcon_update;
	struct device *dev = &i2c->dev;
    g_tcon_i2c_client = i2c;

    mutex_init(&tcon_i2c_mutex);
    parse_edp_tcon_info();
	ret = of_property_read_u32(dev->of_node, "enable-tcon-update", &enable_tcon_update);
	if (ret < 0) {
	    edp_warn("parse enable-tcon-update failed\n");
		enable_tcon_update = 0;
	}

	if (!enable_tcon_update) {
		edp_info("edp tcon update %d not support\n", enable_tcon_update);
		return 0;
	}
	g_fw_name.count = of_property_count_strings(dev->of_node, "firmware_name");
	if (g_fw_name.count <= 0) {
		edp_err("firmware_name not to config, can not upgrade!\n");
		return -EINVAL;
	}
	if (g_fw_name.count > TCON_BIN_MAX) {
		edp_warn("count = %d is oversize\n", g_fw_name.count);
		g_fw_name.count = TCON_BIN_MAX;
	}
	ret = of_property_read_string_array(dev->of_node, "firmware_name",
										g_fw_name.name_list, g_fw_name.count);
	if (ret < 0) {
		edp_err("get firmware_name failed, can not upgrade!\n");
		return -EINVAL;
	}
    if (g_enter_recovery) {
        edp_info("mode is recovery, skip tcon update");
        return 0;
    }
	INIT_DELAYED_WORK(&g_work, edp_tcon_update);
	queue_delayed_work(system_wq, &g_work, msecs_to_jiffies(TCON_UPDATE_DELAY_MS));

    edp_info("edp i2c probe success");

    return 0;
}

static const struct i2c_device_id tcon_i2c_id[] = {
    { "tcon_i2c", 0 },
    {},
};
MODULE_DEVICE_TABLE(i2c, tcon_i2c_id);

static const struct of_device_id tcon_i2c_match[] = {
    { .compatible = "huawei,edp-over-i2c", },
    {},
};

static struct i2c_driver tcon_i2c_driver = {
    .driver = {
        .name           = "edp-over-i2c",
        .owner          = THIS_MODULE,
        .of_match_table = of_match_ptr(tcon_i2c_match),
    },
    .probe  = tcon_i2c_probe,
    .remove = NULL,
    .id_table = tcon_i2c_id,
};

static int __init tcon_i2c_init(void)
{
    int ret;

    ret = i2c_add_driver(&tcon_i2c_driver);
    if (ret != 0) {
        edp_err("[eDP]i2c_driver_register failed, %d\n", ret);
        return ret;
    }

#ifdef EDP_FACTORY_MODE
    ret = misc_register(&tcon_updater_miscdev);
    if (ret != 0)
        edp_err("register miscdev failed, %d\n", ret);
#endif

    return ret;
}

static void __exit tcon_i2c_exit(void)
{
#ifdef EDP_FACTORY_MODE
    misc_deregister(&tcon_updater_miscdev);
#endif
    i2c_del_driver(&tcon_i2c_driver);
}

late_initcall(tcon_i2c_init);
module_exit(tcon_i2c_exit)