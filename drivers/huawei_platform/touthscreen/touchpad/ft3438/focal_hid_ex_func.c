/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2025. All rights reserved.
 */

/*
 *
 * FocalTech TouchScreen driver.
 *
 * Copyright (c) 2012-2020, Focaltech Ltd. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

/*****************************************************************************
*
* File Name: focal_hid_ex_fun.c
*
* Author: Focaltech Driver Team
*
* Created: 2016-08-08
*
* Abstract:
*
* Reference:
*
*****************************************************************************/

/*****************************************************************************
* 1.Included header files
*****************************************************************************/
#include "focal_hid_core.h"

/*****************************************************************************
* Private constant and macro definitions using #define
*****************************************************************************/
#define PROC_UPGRADE                            0
#define PROC_READ_REGISTER                      1
#define PROC_WRITE_REGISTER                     2
#define PROC_AUTOCLB                            4
#define PROC_UPGRADE_INFO                       5
#define PROC_WRITE_DATA                         6
#define PROC_READ_DATA                          7
#define PROC_SET_TEST_FLAG                      8
#define PROC_SET_SLAVE_ADDR                     10
#define PROC_HW_RESET                           11
#define PROC_READ_STATUS                        12
#define PROC_SET_BOOT_MODE                      13
#define PROC_ENTER_TEST_ENVIRONMENT             14
#define PROC_WRITE_DATA_DIRECT                  16
#define PROC_READ_DATA_DIRECT                   17
#define PROC_CONFIGURE                          18
#define PROC_CONFIGURE_INTR                     20
#define PROC_GET_DRIVER_INFO                    21
#define PROC_NAME                               "ftxxxx-debug"
#define PROC_BUF_SIZE                           256

#define FTS_DRIVER_NAME_LEN                     12
#define FTS_USER_OPT                            0777
#define FTS_FILE_NAME_LEN_MAX                   32
#define FTS_DEC_CODE                            10
#define FTS_HEX_CODE                            16

/*****************************************************************************
* Private enumerations, structures and unions using typedef
*****************************************************************************/


/*****************************************************************************
* Global variable or extern global variabls/functions
*****************************************************************************/

/*****************************************************************************
* Static function prototypes
*****************************************************************************/
int fts_debug_open(struct inode *inode, struct file *filp)
{
    FTS_INFO("fts_debug_open.......");
    focal_esdcheck_switch(fts_hid_data, DISABLE);
    focal_irq_disable();
    focal_hid2std();

    return 0;
}

int fts_debug_close(struct inode *inode, struct file *filp)
{
    FTS_INFO("fts_debug_close.......");
    fts_reset(FTS_DELAY_MS_200);
    focal_irq_enable();
    focal_esdcheck_switch(fts_hid_data, ENABLE);
    return 0;
}

static int debug_write_case_7(struct fts_hid_data *ts_data, u8 *writebuf, int buflen)
{
    int writelen = 0;
    int ret = 0;
    struct ftxxxx_proc *proc = &ts_data->proc;
    
    writelen = buflen - 1;
    if (writelen >= FTS_MAX_COMMMAND_LENGTH) {
        FTS_ERROR("cmd(PROC_READ_DATA) length(%d) fail", writelen);
        return ret;
    }
    memcpy_s(proc->cmd, FTS_MAX_COMMMAND_LENGTH, writebuf + 1, writelen);
    proc->cmd_len = writelen;
    ret = fts_i2c_write(writebuf + 1, writelen);
    if (ret < 0) {
        FTS_ERROR("PROC_READ_DATA write error");
        return ret;
    }
    return 0;
}

static int debug_write_case_6(struct fts_hid_data *ts_data, u8 *writebuf, int buflen)
{
    int writelen = 0;
    int ret = 0;
    
    writelen = buflen - 1;
    ret = fts_i2c_write(writebuf + 1, writelen);
    if (ret < 0) {
        FTS_ERROR("PROC_WRITE_DATA write error");
        return ret;
    }
    return 0;
}

static int debug_write_case_10(struct fts_hid_data *ts_data, u8 *writebuf, int buflen)
{
    FTS_INFO("Original i2c addr 0x%x", ts_data->client->addr << 1);
    if (writebuf[1] != ts_data->client->addr) {
        ts_data->client->addr = writebuf[1];
        FTS_INFO("Change i2c addr 0x%x to 0x%x",
                 ts_data->client->addr << 1, writebuf[1] << 1);
    }

    return 0;
}

static int debug_write_case_11(struct fts_hid_data *ts_data, u8 *writebuf, int buflen)
{
    char tmp[PROC_BUF_SIZE];
    int count;
    
    if (buflen < PROC_BUF_SIZE) {
        count = snprintf_s(tmp, PROC_BUF_SIZE, PROC_BUF_SIZE, "%s", writebuf + 1);
        if (count == -1) {
            FTS_ERROR("snprintf_s fail");
        }
        tmp[buflen - 1] = '\0';
        if (strncmp(tmp, "focal_driver", FTS_DRIVER_NAME_LEN) == 0) {
            FTS_INFO("APK execute HW Reset");
            fts_hw_reset(0);
        }
    }

    return 0;
}


static int fts_debug_write_switch(struct fts_hid_data *ts_data, u8 *writebuf, int buflen)
{
    struct ftxxxx_proc *proc = &ts_data->proc;
    int ret = 0;
    
    switch (proc->opmode) {
    case PROC_READ_REGISTER:
        proc->cmd[0] = writebuf[1];
        break;

    case PROC_WRITE_REGISTER:
        ret = fts_i2c_write_reg(writebuf[1], writebuf[FTS_DATA_LEN_2]);
        if (ret < 0) {
            FTS_ERROR("PROC_WRITE_REGISTER write error");
            return ret;
        }
        break;

    case PROC_READ_DATA:
        debug_write_case_7(ts_data, writebuf, buflen);
        break;

    case PROC_WRITE_DATA:
        debug_write_case_6(ts_data, writebuf, buflen);
        break;

    case PROC_SET_SLAVE_ADDR:
        debug_write_case_10(ts_data, writebuf, buflen);
        break;

    case PROC_HW_RESET:
        debug_write_case_11(ts_data, writebuf, buflen);
        break;
    case PROC_CONFIGURE_INTR:
        if (writebuf[1] == 0) {
            focal_irq_disable();
        } else {
            focal_irq_enable();
        }
        break;

    default:
        break;
    }

    return ret;
}

static ssize_t fts_debug_write(
    struct file *filp, const char __user *buff, size_t count, loff_t *ppos)
{
    u8 *writebuf = NULL;
    u8 tmpbuf[PROC_BUF_SIZE] = { 0 };
    int buflen = count;
    int ret = 0;
    struct fts_hid_data *ts_data = PDE_DATA(file_inode(filp));
    struct ftxxxx_proc *proc = &ts_data->proc;

    if (buflen < 1) {
        FTS_ERROR("apk proc count(%d) fail", buflen);
        return -EINVAL;
    }

    if (buflen > PROC_BUF_SIZE) {
        writebuf = (u8 *)kzalloc(buflen * sizeof(u8), GFP_KERNEL);
        if (NULL == writebuf) {
            FTS_ERROR("apk proc wirte buf zalloc fail");
            return -ENOMEM;
        }
    } else {
        writebuf = tmpbuf;
    }

    if (copy_from_user(writebuf, buff, buflen)) {
        FTS_ERROR("[APK]: copy from user error!!");
        ret = -EFAULT;
        goto proc_write_err;
    }

    proc->opmode = writebuf[0];
    if (buflen == 1) {
        ret = buflen;
        goto proc_write_err;
    }

    fts_debug_write_switch(ts_data, writebuf, buflen);

    ret = buflen;
proc_write_err:
    if ((buflen > PROC_BUF_SIZE) && writebuf) {
        kfree(writebuf);
        writebuf = NULL;
    }
    return ret;
}

static int fts_debug_read_out(char __user *buff, u8 *readbuf, int num_read_chars, int buflen)
{
    int ret = num_read_chars;
    if ((num_read_chars > 0) && copy_to_user(buff, readbuf, num_read_chars)) {
        FTS_ERROR("copy to user error");
        ret = -EFAULT;
    }

    if ((buflen > PROC_BUF_SIZE) && readbuf) {
        kfree(readbuf);
        readbuf = NULL;
    }
    return ret;
}

static ssize_t fts_debug_read(
    struct file *filp, char __user *buff, size_t count, loff_t *ppos)
{
    int ret = 0;
    int num_read_chars = 0;
    int buflen = count;
    u8 *readbuf = NULL;
    u8 tmpbuf[PROC_BUF_SIZE] = { 0 };
    struct fts_hid_data *ts_data = PDE_DATA(file_inode(filp));
    struct ftxxxx_proc *proc = &ts_data->proc;

    if (buflen <= 0) {
        FTS_ERROR("apk proc read count(%d) fail", buflen);
        return -EINVAL;
    }

    if (buflen > PROC_BUF_SIZE) {
        readbuf = (u8 *)kzalloc(buflen * sizeof(u8), GFP_KERNEL);
        if (NULL == readbuf) {
            FTS_ERROR("apk proc buf zalloc fail");
            return -ENOMEM;
        }
    } else {
        readbuf = tmpbuf;
    }

    switch (proc->opmode) {
        case PROC_READ_REGISTER:
            num_read_chars = 1;
            ret = fts_i2c_read_reg(proc->cmd[0], &readbuf[0]);
            if (ret < 0) {
                FTS_ERROR("PROC_READ_REGISTER read error");
                goto proc_read_err;
            }
            break;

        case PROC_READ_DATA:
            num_read_chars = buflen;
            ret = fts_i2c_read(NULL, 0, readbuf, num_read_chars);
            if (ret < 0) {
                FTS_ERROR("PROC_READ_DATA read error");
                goto proc_read_err;
            }
            break;

        default:
            break;
    }

    ret = num_read_chars;
proc_read_err:
    return fts_debug_read_out(buff, readbuf, num_read_chars, buflen);
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
static const struct proc_ops fts_proc_fops = {
    .proc_open = fts_debug_open,
    .proc_release = fts_debug_close,
    .proc_read = fts_debug_read,
    .proc_write = fts_debug_write,
};
#else
static const struct file_operations fts_proc_fops = {
    .owner   = THIS_MODULE,
    .open    = fts_debug_open,
    .release = fts_debug_close,
    .read    = fts_debug_read,
    .write   = fts_debug_write,
};
#endif


int focal_create_apk_debug_channel(struct fts_hid_data *ts_data)
{
    struct ftxxxx_proc *proc = &ts_data->proc;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 10, 0))
    proc->proc_entry = proc_create_data(PROC_NAME, FTS_USER_OPT, NULL, &fts_proc_fops, ts_data);
    if (NULL == proc->proc_entry) {
        FTS_ERROR("create proc entry fail");
        return -ENOMEM;
    }
#else
    proc->proc_entry = create_proc_entry(PROC_NAME, FTS_USER_OPT, NULL);
    if (NULL == proc->proc_entry) {
        FTS_ERROR("create proc entry fail");
        return -ENOMEM;
    }
    proc->proc_entry->write_proc = fts_debug_write;
    proc->proc_entry->read_proc = fts_debug_read;
#endif

    FTS_INFO("Create proc entry success!");
    return 0;
}

void focal_release_apk_debug_channel(struct fts_hid_data *ts_data)
{
    struct ftxxxx_proc *proc = &ts_data->proc;

    if (proc->proc_entry) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 10, 0))
        proc_remove(proc->proc_entry);
#else
        remove_proc_entry(PROC_NAME, NULL);
#endif
    }
}


static ssize_t fts_hw_reset_show(
    struct device *dev, struct device_attribute *attr, char *buf)
{
    ssize_t count = 0;

    fts_hw_reset(0);
    count = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE, "hw reset executed\n");

    return count;
}

static ssize_t fts_version_show(
    struct device *dev, struct device_attribute *attr, char *buf)
{
    ssize_t count = 0;
    u8 value = 0;
    int ret = 0;

    FTS_FUNC_ENTER();
    ret = fts_hid_read_reg(0xA6, &value);
    if (ret) {
        count = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE, "read version fail\n");
    } else {
        count = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE, "%02x\n", value);
    }

    return count;
}


static struct rwreg_operation_t {
    int type;   /*	0: read, 1: write */
    int reg;    /*	register */
    int len;    /*	read/write length */
    int val;    /*	length = 1; read: return value, write: op return */
    int res;    /*	0: success, otherwise: fail */
    char *opbuf;    /*	length >= 1, read return value, write: op return */
} rw_op;

enum {
    RWREG_OP_READ = 0,
    RWREG_OP_WRITE = 1,
};

/* fts_rw_reg */
static int tprwreg_print_data(int count, char *buf)
{
    int i = 0;
    for (i = 0; i < rw_op.len; i++) {
        count += snprintf_s(buf + count, PAGE_SIZE - count, PAGE_SIZE - count, "%02X ", rw_op.opbuf[i]);
    }
    return count;
}

static int tprwreg_long_opt(char *buf)
{
    int count = 0;
    int i = 0;

    if (rw_op.type == RWREG_OP_READ) {
        count = snprintf_s(buf, PAGE_SIZE, "Read Reg: [%02X]-[%02X]\n", rw_op.reg, rw_op.reg + rw_op.len);
        count += snprintf_s(buf + count, PAGE_SIZE - count, PAGE_SIZE - count, "Result: ");
        if (rw_op.res) {
            count += snprintf_s(buf + count, PAGE_SIZE - count, PAGE_SIZE - count, "failed, ret: %d\n", rw_op.res);
        } else {
            if (rw_op.opbuf) {
                count += tprwreg_print_data(count, buf);
                count += snprintf_s(buf + count, PAGE_SIZE - count, PAGE_SIZE - count, "\n");
            }
        }
    } else {
        count = snprintf_s(buf, PAGE_SIZE, "Write Reg: [%02X]-[%02X]\n", rw_op.reg, rw_op.reg + rw_op.len - 1);
        count += snprintf_s(buf + count, PAGE_SIZE - count, PAGE_SIZE - count, "Write Data: ");
        if (rw_op.opbuf) {
            for (i = 1; i < rw_op.len; i++) {
                count += snprintf_s(buf + count, PAGE_SIZE - count, PAGE_SIZE - count, "%02X ", rw_op.opbuf[i]);
            }
            count += snprintf_s(buf + count, PAGE_SIZE - count, PAGE_SIZE - count, "\n");
        }
        if (rw_op.res) {
            count += snprintf_s(buf + count, PAGE_SIZE - count, PAGE_SIZE - count,
                                "Result: failed, ret: %d\n", rw_op.res);
        } else {
            count += snprintf_s(buf + count, PAGE_SIZE - count, PAGE_SIZE - count, "Result: success\n");
        }
    }

    return count;
}
static ssize_t fts_tprwreg_show(
    struct device *dev, struct device_attribute *attr, char *buf)
{
    int count = 0;
    struct fts_hid_data *ts_data = fts_hid_data;

    mutex_lock(&ts_data->debug_lock);

    if (rw_op.len < 0) {
        count = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE, "Invalid cmd line\n");
    } else if (rw_op.len == 1) {
        if (rw_op.type == RWREG_OP_READ) {
            if (rw_op.res == 0) {
                count = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE,
                                   "Read %02X: %02X\n", rw_op.reg, rw_op.val);
            } else {
                count = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE,
                                   "Read %02X failed, ret: %d\n", rw_op.reg,	rw_op.res);
            }
        } else {
            if (rw_op.res == 0) {
                count = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE,
                                   "Write %02X, %02X success\n", rw_op.reg,  rw_op.val);
            } else {
                count = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE,
                                   "Write %02X failed, ret: %d\n", rw_op.reg,  rw_op.res);
            }
        }
    } else {
        tprwreg_long_opt(buf);
    }
    mutex_unlock(&ts_data->debug_lock);

    return count;
}

static int shex_to_int(const char *hex_buf, int size)
{
    int i;
    int base = 1;
    int value = 0;
    char single;

    for (i = size - 1; i >= 0; i--) {
        single = hex_buf[i];

        if ((single >= '0') && (single <= '9')) {
            value += (single - '0') * base;
        } else if ((single >= 'a') && (single <= 'z')) {
            value += (single - 'a' + FTS_DEC_CODE) * base;
        } else if ((single >= 'A') && (single <= 'Z')) {
            value += (single - 'A' + FTS_DEC_CODE) * base;
        } else {
            return -EINVAL;
        }

        base *= FTS_HEX_CODE;
    }

    return value;
}


static u8 shex_to_u8(const char *hex_buf, int size)
{
    return (u8)shex_to_int(hex_buf, size);
}
/*
 * Format buf: 0~6
 * [0]: '0' write, '1' read(reserved)
 * [1-2]: addr, hex
 * [3-4]: length, hex
 * [5-6]...[n-(n+1)]: data, hex
 */
static int fts_parse_buf(const char *buf, size_t cmd_len)
{
    int length;
    int i;
    char *tmpbuf;

    rw_op.reg = shex_to_u8(buf + 1, FTS_DATA_LEN_2);
    length = shex_to_int(buf + FTS_DATA_LEN_3, FTS_DATA_LEN_2);

    if (buf[0] == '1') {
        rw_op.len = length;
        rw_op.type = RWREG_OP_READ;
        FTS_DEBUG("read %02X, %d bytes", rw_op.reg, rw_op.len);
    } else {
        if (cmd_len < (length * FTS_DATA_LEN_2 + FTS_DATA_LEN_5)) {
            pr_err("data invalided!\n");
            return -EINVAL;
        }
        FTS_DEBUG("write %02X, %d bytes", rw_op.reg, length);

        /* first byte is the register addr */
        rw_op.type = RWREG_OP_WRITE;
        rw_op.len = length + 1;
    }

    if (rw_op.len > 0) {
        tmpbuf = (char *)kzalloc(rw_op.len, GFP_KERNEL);
        if (!tmpbuf) {
            FTS_ERROR("allocate memory failed!\n");
            return -ENOMEM;
        }

        if (rw_op.type == RWREG_OP_WRITE) {
            tmpbuf[0] = rw_op.reg & 0xFF;
            FTS_DEBUG("write buffer: ");
            for (i = 1; i < rw_op.len; i++) {
                tmpbuf[i] = shex_to_u8(buf + FTS_DATA_LEN_5 + i * FTS_DATA_LEN_2 - FTS_DATA_LEN_2, FTS_DATA_LEN_2);
                FTS_DEBUG("buf[%d]: %02X", i, tmpbuf[i] & 0xFF);
            }
        }
        rw_op.opbuf = tmpbuf;
    }

    return rw_op.len;
}

static int rw_op_init(const char *buf, ssize_t cmd_length)
{
    if (rw_op.opbuf) {
        kfree(rw_op.opbuf);
        rw_op.opbuf = NULL;
    }

    FTS_DEBUG("cmd len: %d, buf: %s", (int)cmd_length, buf);
    /* compatible old ops */
    if (cmd_length == FTS_DATA_LEN_2) {
        rw_op.type = RWREG_OP_READ;
        rw_op.len = 1;
        rw_op.reg = shex_to_int(buf, FTS_DATA_LEN_2);
    } else if (cmd_length == FTS_DATA_LEN_4) {
        rw_op.type = RWREG_OP_WRITE;
        rw_op.len = 1;
        rw_op.reg = shex_to_int(buf, FTS_DATA_LEN_2);
        rw_op.val = shex_to_int(buf + FTS_DATA_LEN_2, FTS_DATA_LEN_2);
    } else if (cmd_length < FTS_DATA_LEN_5) {
        FTS_ERROR("Invalid cmd buffer");
        return -EINVAL;
    } else {
        rw_op.len = fts_parse_buf(buf, cmd_length);
    }

    return 0;
}
static ssize_t fts_tprwreg_store(
    struct device *dev,
    struct device_attribute *attr, const char *buf, size_t count)
{
    struct fts_hid_data *ts_data = fts_hid_data;
    ssize_t cmd_length = 0;

    mutex_lock(&ts_data->debug_lock);
    cmd_length = count - 1;
    if (rw_op_init(buf, cmd_length) < 0) {
        mutex_unlock(&ts_data->debug_lock);
        return -EINVAL;
    }
    if (rw_op.len < 0) {
        FTS_ERROR("cmd buffer error!");
    } else {
        if (rw_op.type == RWREG_OP_READ) {
            if (rw_op.len == 1) {
                u8 reg, val;
                reg = rw_op.reg & 0xFF;
                rw_op.res = fts_hid_read_reg(reg, &val);
                rw_op.val = val;
            }

            if (rw_op.res < 0) {
                FTS_ERROR("Could not read 0x%02x", rw_op.reg);
            } else {
                FTS_INFO("read 0x%02x, %d bytes successful", rw_op.reg, rw_op.len);
                rw_op.res = 0;
            }
        } else {
            if (rw_op.len == 1) {
                u8 reg, val;
                reg = rw_op.reg & 0xFF;
                val = rw_op.val & 0xFF;
                rw_op.res = fts_hid_write_reg(reg, val);
            }
            if (rw_op.res < 0) {
                FTS_ERROR("Could not write 0x%02x", rw_op.reg);
            } else {
                FTS_INFO("Write 0x%02x, %d bytes successful", rw_op.val, rw_op.len);
                rw_op.res = 0;
            }
        }
    }

    mutex_unlock(&ts_data->debug_lock);
    return count;
}

#ifdef TOUCHPAD_FACTORY_ENABLE
static ssize_t fts_fwupgradebin_store(
    struct device *dev,
    struct device_attribute *attr, const char *buf, size_t count)
{
    char fwname[FILE_NAME_LENGTH] = { 0 };
    int ret;
	
    if ((count <= 1) || (count >= FILE_NAME_LENGTH - FTS_FILE_NAME_LEN_MAX)) {
        FTS_ERROR("fw bin name's length(%d) fail", (int)count);
        return -EINVAL;
    }
    memset_s(fwname, FILE_NAME_LENGTH, 0, sizeof(fwname));
    ret = snprintf_s(fwname, FILE_NAME_LENGTH, FILE_NAME_LENGTH, "%s", buf);
    fwname[count - 1] = '\0';

    FTS_INFO("upgrade with bin file through sysfs node");
	
    focal_hid_upgrade_bin(fwname);

    return (ssize_t)ret;
}


static ssize_t fts_upgrade_bin_show(
    struct device *dev, struct device_attribute *attr, char *buf)
{
    ssize_t count = 0;

    FTS_FUNC_ENTER();

    return count;
}

static DEVICE_ATTR(fts_upgrade_bin, S_IRUGO | S_IWUSR, fts_upgrade_bin_show, fts_fwupgradebin_store);
#endif

static DEVICE_ATTR(fts_fw_version, S_IRUGO | S_IWUSR, fts_version_show, NULL);
static DEVICE_ATTR(fts_hw_reset, S_IRUGO | S_IWUSR, fts_hw_reset_show, NULL);
static DEVICE_ATTR(fts_rw_reg, S_IRUGO | S_IWUSR, fts_tprwreg_show, fts_tprwreg_store);

static struct attribute *fts_attributes[] = {
#ifdef TOUCHPAD_FACTORY_ENABLE
    &dev_attr_fts_upgrade_bin.attr,
#endif
    &dev_attr_fts_hw_reset.attr,
    &dev_attr_fts_fw_version.attr,
    &dev_attr_fts_rw_reg.attr,
    NULL
};
	
static struct attribute_group fts_attribute_group = {
    .attrs = fts_attributes
};

int fts_create_sysfs(struct fts_hid_data *ts_data)
{
    int ret = 0;

    ret = sysfs_create_group(&ts_data->dev->kobj, &fts_attribute_group);
    if (ret) {
        FTS_ERROR("[EX]: sysfs_create_group() failed!!");
        sysfs_remove_group(&ts_data->dev->kobj, &fts_attribute_group);
        return -ENOMEM;
    } else {
        FTS_INFO("[EX]: sysfs_create_group() succeeded!!");
    }

    return ret;
}

int fts_remove_sysfs(struct fts_hid_data *ts_data)
{
    sysfs_remove_group(&ts_data->dev->kobj, &fts_attribute_group);
    return 0;
}
