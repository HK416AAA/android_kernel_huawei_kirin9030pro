/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/*
 *
 * FocalTech TouchScreen driver.
 *
 * Copyright (c) 2012-2020, FocalTech Systems, Ltd., all rights reserved.
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
* File Name: focal_hid_upgrade.c
*
*    Author: Focaltech Driver Team
*
*   Created: 2024-12-05
*
*  Abstract: HID upgrade function
*
*   Version: v1.0
*
*****************************************************************************/

/*****************************************************************************
* Included header files
*****************************************************************************/


#include "focal_hid_core.h"
#include "../touchpad_func.h"

#define FTS_FW_BIN_FILEPATH                     "/data/"
#define FTS_UPGRADE_ONE_PACKET_LEN              56

#define FTS_FW_REQUEST_SUPPORT                  1
#define FTS_AUTO_UPGRADE_EN                     1
#define FT_FIRMWARE_NAME                       "ft3438.bin"
#define FTS_UPGRADE_FIRST_PKG                  0x0
#define FTS_UPGRADE_NORMAL_PKG                 0x1
#define FTS_UPGRADE_LAST_PKG                   0x2

// 0x40
static int fts_enter_into_upgrade_mode(void)
{
    u8 cmd = CMD_ENTER_UPGRADE_MODE;
    int ret = 0;

    ret = fts_hid_write_data(&cmd, 1);
    if (ret < 0) {
        FTS_ERROR("fts_hid_write_data fail\n");
        return -EINVAL;
    }

    ret = fts_hid_read_data(&cmd, 1);
    if (ret < 0) {
        FTS_ERROR("fts_hid_read_data fail\n");
        return -EINVAL;
    }

    if (cmd != 0xF0) {
        FTS_ERROR("wait enter into upgrade_mode %x\n", cmd);
        return -EINVAL;
    } else {
        FTS_INFO("fts_enter_into_upgrade_mode success\n");
    }

    return 0;
}


// 0x41
static int fts_check_current_state(void)
{
    u8 cmd = CMD_CHECK_CURRENT_STATE;
    u8 read_buf[FTS_DATA_LEN_2] = {0};
    int ret = 0;

    ret = fts_hid_write_data(&cmd, 1);
    if (ret < 0) {
        FTS_ERROR("fts_hid_write_data fail\n");
        return -EINVAL;
    }

    ret = fts_hid_read_data(read_buf, FTS_DATA_LEN_2);
    if (ret < 0) {
        FTS_ERROR("fts_hid_read_data fail\n");
        return -EINVAL;
    }

    if ((read_buf[0] != 0x41) || (read_buf[1] != 0x01)) {
        FTS_ERROR("cmd %x, not in upgrade mode %x fail\n", read_buf[0], read_buf[1]);
        return -EINVAL;
    } else {
        FTS_INFO("enter into upgrade mode success\n");
    }

    return 0;
}


// 0x42
static int fts_check_is_ready_for_upgrade(void)
{
    u8 cmd = CMD_READY_FOR_UPGRADE;
    u8 read_buf[FTS_DATA_LEN_2] = {0};
    int ret = 0;

    ret = fts_hid_write_data(&cmd, 1);
    if (ret < 0) {
        FTS_ERROR("fts_hid_write_data fail\n");
        return -EINVAL;
    }

    ret = fts_hid_read_data(read_buf, FTS_DATA_LEN_2);
    if (ret < 0) {
        FTS_ERROR("fts_hid_read_data fail\n");
        return -EINVAL;
    }

    if ((read_buf[0] != 0x42) || (read_buf[1] != 0x02)) {
        FTS_ERROR("wait status(%x) ready\n", read_buf[1]);
        return -EINVAL;
    }

    return 0;
}

// 0x43
static int fts_send_pkg(u8 *write_buf, int packet_len)
{
    int ret = 0;
    u8 read_buf = 0;
    int j = 0;

    ret = fts_hid_write_data(write_buf, packet_len + FTS_DATA_LEN_2);
    if (ret < 0) {
        FTS_ERROR("fts_hid_write_data fail\n");
        return -EINVAL;
    }

    ret = fts_hid_read_data(&read_buf, 1);
    if (ret < 0) {
        FTS_ERROR("fts_hid_read_data fail\n");
        return -EINVAL;
    }

    for (j = 0; j < FTS_RETRY_NUM_100; j++) {
        ret = fts_check_is_ready_for_upgrade();
        if (ret < 0) {
            FTS_INFO("wait for write flash %d", j);
            msleep(1);
            continue;
        }
        break;
    }
    if (j >= FTS_RETRY_NUM_100) {
        FTS_ERROR("wait for write flash fail\n");
        return -EINVAL;
    }

    return 0;
}

static int fts_send_data(u8 * data, int len)
{
    u8 write_buf[72] = {0};
    int packet_number = 0;
    int remainder = 0;
    int packet_len = 0;
    int i = 0;
    int offset = 0;
    int ret = 0;

    packet_number = len / FTS_UPGRADE_ONE_PACKET_LEN;
    remainder = len % FTS_UPGRADE_ONE_PACKET_LEN;
    if (remainder > 0) {
        packet_number++;
    }
    packet_len = FTS_UPGRADE_ONE_PACKET_LEN;
    FTS_INFO("write data, num:%d remainder:%d", packet_number, remainder);

    for (i = 0; i < packet_number; i++) {
        offset = i * FTS_UPGRADE_ONE_PACKET_LEN;
        if ((i == (packet_number - 1)) && remainder) {
            packet_len = remainder;
        }
        if (i == 0) {
            write_buf[0] = CMD_SEND_DATA;
            write_buf[1] = FTS_UPGRADE_FIRST_PKG;
            memcpy_s(write_buf + FTS_DATA_LEN_2, sizeof(write_buf) - FTS_DATA_LEN_2, data + offset, packet_len);
        } else if (i == (packet_number - 1)) {
            write_buf[0] = CMD_SEND_DATA;
            write_buf[1] = FTS_UPGRADE_LAST_PKG;
            memcpy_s(write_buf + FTS_DATA_LEN_2, sizeof(write_buf) - FTS_DATA_LEN_2, data + offset, packet_len);
        } else {
            write_buf[0] = CMD_SEND_DATA;
            write_buf[1] = FTS_UPGRADE_NORMAL_PKG;
            memcpy_s(write_buf + FTS_DATA_LEN_2, sizeof(write_buf) - FTS_DATA_LEN_2, data + offset, packet_len);
        }

        ret = fts_send_pkg(write_buf, packet_len);
        if (ret < 0) {
            FTS_INFO("fts_send_pkg fail %d", i);
            return -EINVAL;
        }
    }

    return 0;
}

// 0x44
static int fts_checksum_upgrade(int* checksum)
{
    u8 cmd = CMD_UPGRADE_CHECKSUM;
    u8 data[5] = {0};
    int ret = 0;

    ret = fts_hid_write_data(&cmd, 1);
    if (ret < 0) {
        FTS_ERROR("fts_hid_write_data fail\n");
        return -EINVAL;
    }

    msleep(FTS_DELAY_MS_100);

    ret = fts_hid_read_data(data, FTS_DATA_LEN_5);
    if (ret < 0) {
        FTS_ERROR("fts_hid_read_data fail\n");
        return -EINVAL;
    }

    if (data[0] == CMD_UPGRADE_CHECKSUM) {
        *checksum = (data[FTS_DATA_LEN_4] << FTS_BYTE_OFF_24) +  (data[FTS_DATA_LEN_3] << FTS_BYTE_OFF_16) +
                    (data[FTS_DATA_LEN_2] << FTS_BYTE_OFF_8) + data[1];
        FTS_INFO("read checksum success %x\n", checksum);
    } else {
        FTS_ERROR("read checksum fail\n");
        return -EINVAL;
    }

    return 0;
}

// 0x45
static int fts_exit_upgrade_mode(void)
{
    u8 cmd = CMD_EXIT_UPRADE_MODE;
    int ret = 0;

    ret = fts_hid_write_data(&cmd, 1);
    if (ret < 0) {
        FTS_ERROR("fts_hid_write_data fail\n");
        return -EINVAL;
    }

    FTS_INFO("exit upgrade mode\n");

    return 0;
}

// 0x46
static int fts_i2c_read_upgrade_id(void)
{
    u8 cmd = CMD_USB_READ_UPGRADE_ID;
    u8 read_buf[3] = {0};
    int ret = 0;

    ret = fts_hid_write_data(&cmd, 1);
    if (ret < 0) {
        FTS_ERROR("fts_hid_write_data fail\n");
        return -EINVAL;
    }

    ret = fts_hid_read_data(read_buf, FTS_DATA_LEN_3);
    if (ret < 0) {
        FTS_ERROR("fts_hid_read_data fail\n");
        return -EINVAL;
    }

    if ((read_buf[0] != CMD_USB_READ_UPGRADE_ID) ||
        (read_buf[1] != FTS_BOOT_ID_H) ||
        (read_buf[FTS_DATA_LEN_2] != FTS_BOOT_ID_L)) {
        FTS_ERROR("cmd %x, read id 0x%x%x fail\n", read_buf[0], read_buf[1], read_buf[FTS_DATA_LEN_2]);
        return -EINVAL;
    } else {
        FTS_INFO("success read id 0x%x%x", read_buf[1], read_buf[FTS_DATA_LEN_2]);
    }

    return 0;
}


// 0x47
static int fts_erase_flash(void)
{
    u8 cmd = CMD_USB_ERASE_FLASH;
    int ret = 0;
    int i = 0;

    FTS_INFO("**********erase now**********");
    ret = fts_hid_write_data(&cmd, 1);
    if (ret < 0) {
        FTS_ERROR("fts_hid_write_data fail\n");
        return -EINVAL;
    }

    ret = fts_hid_read_data(&cmd, 1);
    if (ret < 0) {
        FTS_ERROR("fts_hid_read_data fail\n");
        return -EINVAL;
    }

    for (i = 0; i < FTS_RETRY_NUM_20; i++) {
        ret = fts_check_is_ready_for_upgrade();
        if (ret < 0) {
            FTS_INFO("wait for flash erase %d\n", i);
            msleep(FTS_DELAY_MS_500);
            continue;
        }
        break;
    }

    if (i >= FTS_RETRY_NUM_20) {
        FTS_INFO("wait for flash erase fail\n");
        return -EINVAL;
    }

    return 0;
}


/*****************************************************************************
*  Name: fts_wait_tp_to_valid
*  Brief: Read chip id until TP FW become valid(Timeout: TIMEOUT_READ_REG),
*         need call when reset/power on/resume...
*  Input: NA
*  Output:NA
*  Return: return 0 if tp valid, otherwise return error code
*****************************************************************************/
int focal_wait_tp_to_valid(void)
{
    int ret = 0;
    int cnt = 0;
    u8 idh = 0;

    do {
        ret = fts_hid_read_reg(FTS_REG_CHIP_ID_H, &idh);
        if (idh == FTS_CHIP_ID_H) {
            FTS_INFO("TP Ready,Device ID:0x%02x", idh);
            return 0;
        } else {
            FTS_DEBUG("TP Not Ready,ReadData:0x%02x,ret:%d", idh, ret);
        }

        cnt++;
        msleep(FTS_DELAY_MS_200);
    } while ((cnt * FTS_DELAY_MS_200) < FTS_DELAY_MAX);

    return -EIO;
}

static int fts_ready_for_upgrade(u8 *buf, u32 buf_len, u8 mode)
{
    int ret = 0;
    int i = 0;

    for (i = 0; i < FTS_RETRY_NUM_15; i++) {
        ret = fts_enter_into_upgrade_mode();
        if (ret < 0) {
            msleep(1);
            continue;
        }
        break;
    }
    if (i >= FTS_RETRY_NUM_15) {
        FTS_INFO("enter upgrade mode fail");
        return ret;
    }

    ret = fts_check_current_state();
    if (ret < 0) {
        FTS_INFO("fts_check_current_state fail");
        return ret;
    }

    ret = fts_check_is_ready_for_upgrade();
    if (ret < 0) {
        FTS_INFO("fts_check_is_ready_for_upgrade fail");
        return ret;
    }

    ret = fts_i2c_read_upgrade_id();
    if (ret < 0) {
        FTS_INFO("read upgrade id fail");
        return ret;
    }

    return 0;
}

static int fts_upgrade_firmware(u8 *buf, u32 buf_len, u8 mode)
{
    int ret = 0;
    int i = 0;
    int checksum = 0, dvalue = 0, tp_checksum = 0;

    for (i = 0; i < buf_len ; i += FTS_DATA_LEN_4) {
        dvalue = (buf[i + FTS_DATA_LEN_3] << FTS_BYTE_OFF_24) + (buf[i + FTS_DATA_LEN_2] << FTS_BYTE_OFF_16) +
                 (buf[i + 1] << FTS_BYTE_OFF_8) + buf[i];
        checksum ^= dvalue;
    }
    checksum += 1;

    ret = fts_ready_for_upgrade(buf, buf_len, mode);
    if (ret < 0) {
        FTS_INFO("fts_erase_flash fail");
        goto out;
    }

    ret = fts_erase_flash();
    if (ret < 0) {
        FTS_INFO("fts_erase_flash fail");
        goto out;
    }

    ret = fts_send_data(buf, buf_len);
    if (ret < 0) {
        FTS_INFO("fts_send_data fail");
        goto out;
    }

    fts_checksum_upgrade(&tp_checksum);
    FTS_INFO("tp_checksum = %x, checksum = %x\n", tp_checksum, checksum);
    if (tp_checksum != checksum) {
        FTS_INFO("tp_checksum != checksum, upgrade fail\n");
        ret = -EINVAL;
        goto out;
    }

    ret = 0;
    out:
    fts_exit_upgrade_mode();
    msleep(FTS_DELAY_MS_100);
    return ret;
}

static int fts_i2c_read_file_default(char *file_name, u8 **file_buf)
{
    int ret = 0;
    char file_path[FILE_NAME_LENGTH] = { 0 };
    struct file *filp = NULL;
    struct inode *inode;
    mm_segment_t old_fs;
    loff_t pos;
    loff_t file_len = 0;
    int count;

    if ((NULL == file_name) || (NULL == file_buf)) {
        FTS_ERROR("filename/filebuf is NULL");
        return -EINVAL;
    }

    count = snprintf_s(file_path, FILE_NAME_LENGTH, FILE_NAME_LENGTH, "%s%s", FTS_FW_BIN_FILEPATH, file_name);
    if (count == -1) {
        FTS_ERROR("snprintf_s fail");
    }
    filp = filp_open(file_path, O_RDONLY, 0);
    if (IS_ERR(filp)) {
        FTS_ERROR("open %s file fail", file_path);
        return -ENOENT;
    }

#if 1
    inode = filp->f_inode;
#else
    /* reserved for linux earlier verion */
    inode = filp->f_dentry->d_inode;
#endif

    file_len = inode->i_size;
    *file_buf = (u8 *)vmalloc(file_len);
    if (NULL == *file_buf) {
        FTS_ERROR("file buf malloc fail");
        filp_close(filp, NULL);
        return -ENOMEM;
    }
    old_fs = get_fs();
    set_fs(KERNEL_DS);
    pos = 0;
    ret = vfs_read(filp, *file_buf, file_len, &pos);
    if (ret < 0) {
        FTS_ERROR("read file fail");
    }
        
    FTS_INFO("file len:%d read len:%d pos:%d", (u32)file_len, ret, (u32)pos);
    filp_close(filp, NULL);
    set_fs(old_fs);

    return ret;
}

static int fts_i2c_read_file_request_firmware(char *file_name, u8 **file_buf)
{
    int ret = 0;
    const struct firmware *fw = NULL;
    char fwname[FILE_NAME_LENGTH] = { 0 };
    int count;

#if !FTS_FW_REQUEST_SUPPORT
    return -EINVAL;
#endif

    count = snprintf_s(fwname, FILE_NAME_LENGTH, FILE_NAME_LENGTH, "%s", file_name);
    if (count == -1) {
        FTS_ERROR("snprintf_s fail");
    }
    ret = request_firmware(&fw, fwname, fts_hid_data->dev);
    if (ret == 0) {
        FTS_INFO("firmware(%s) request successfully", fwname);
        *file_buf = vmalloc(fw->size);
        if (NULL == *file_buf) {
            FTS_ERROR("fw buffer vmalloc fail");
            ret = -ENOMEM;
        } else {
            memcpy_s(*file_buf, fw->size, fw->data, fw->size);
            ret = fw->size;
        }
    } else {
        FTS_INFO("firmware(%s) request fail,ret=%d", fwname, ret);
        ret = -EIO;
    }

    if (fw != NULL) {
        release_firmware(fw);
        fw = NULL;
    }

    return ret;
}

static int fts_i2c_read_file(char *file_name, u8 **file_buf)
{
    int ret = 0;

    ret = fts_i2c_read_file_request_firmware(file_name, file_buf);
    if (ret < 0) {
        ret = fts_i2c_read_file_default(file_name, file_buf);
        if (ret < 0) {
            FTS_ERROR("get fw file(default) fail");
            return ret;
        }
    }

    return ret;
}

static int fts_do_upgrade(u32 fw_file_len, u8 *fw_file_buf)
{
    int ret = 0;
    int j = 0;
    int i = 0;
    u8 value = 0;

    ret = fts_upgrade_firmware(fw_file_buf, fw_file_len, 0x0B);
    if (ret < 0) {
        FTS_INFO("upgrade fw bin fail\n");
    } else {
        for (j = 0; j < FTS_RETRY_NUM_50; j++) {
            ret = fts_hid_read_reg(FTS_REG_FW_VERSION, &value);
            if (ret < 0) {
                FTS_INFO("read A6 %d time\n", j);
                msleep(FTS_RETRY_NUM_50);
                continue;
            }
            FTS_INFO("success upgrade to version %d\n", value);
            ret = 0;
            break;
        }
    }
    return ret;
}

#ifdef TOUCHPAD_FACTORY_ENABLE
int focal_hid_upgrade_bin(char *fw_name)
{
    int ret = 0;
    u32 fw_file_len = 0;
    u8 *fw_file_buf = NULL;
	u8 value = 0;
	int i = 0;
	int j = 0;

    ret = fts_i2c_read_file(fw_name, &fw_file_buf);
    if ((ret < 0) || (ret < 0x120)) {
        FTS_ERROR("read fw bin file(%s) fail, len:%d", fw_name, ret);
        goto err_bin;
    }

    fw_file_len = ret;
    FTS_INFO("fw bin file len:%d", fw_file_len);
	
	fts_hid_data->fw_loading = true;
	device_wakeup_enable(fts_hid_data->dev);
	focal_esdcheck_switch(fts_hid_data, DISABLE);

    do {
        ret = fts_do_upgrade(fw_file_len, fw_file_buf);
        if (ret < 0) {
            FTS_INFO("fts_do_upgrade fail");
        }
		i++;
	}while(ret && (i < FTS_RETRY_NUM_3));
	
err_bin:
	fts_hid_data->fw_loading = false;
	device_wakeup_disable(fts_hid_data->dev);
	focal_esdcheck_switch(fts_hid_data, ENABLE);
    if (fw_file_buf) {
        vfree(fw_file_buf);
        fw_file_buf = NULL;
    }
	
    return ret;
}
#endif

static bool fts_fwupg_check_fw_valid(void)
{
    int ret = 0;

    ret = focal_wait_tp_to_valid();
    if (ret < 0) {
        FTS_INFO("tp fw invaild");
        return false;
    }

    FTS_INFO("tp fw vaild");
    return true;
}


static bool fts_fwupg_need_upgrade(u8 *fw_file_buf)
{
    bool fwvalid = false;
    u8 fw_ver_in_host = 0;
    u8 fw_ver_in_tp = 0;

    fwvalid = fts_fwupg_check_fw_valid();
    if (fwvalid) {
        fw_ver_in_host = fw_file_buf[0x10E];

        fts_hid_read_reg(0xA6, &fw_ver_in_tp);

        FTS_INFO("fw version in tp:%x, host:%x", fw_ver_in_tp, fw_ver_in_host);
#ifdef TOUCHPAD_FACTORY_ENABLE
        if (fw_ver_in_tp != fw_ver_in_host) {
#else
        if (fw_ver_in_tp < fw_ver_in_host) {
#endif
            return true;
        }
    } else {
        FTS_INFO("fw invalid, need upgrade fw");
        return true;
    }

    return false;
}

static int fts_upgrade_init(u8 **fw_file_buf)
{
    int ret = 0;
    
#if !FTS_AUTO_UPGRADE_EN
    FTS_INFO("FTS_AUTO_UPGRADE_EN is disabled, not upgrade when power on");
    return -EINVAL;
#endif

    FTS_INFO("fw upgrade work function");

        /* get fw */
    ret = fts_i2c_read_file_request_firmware(FT_FIRMWARE_NAME, fw_file_buf);
    if (ret < 0) {
        FTS_ERROR("get fw file(default) fail");
        return -EINVAL;
    }

    FTS_INFO("fw bin file len:%d", ret);
    if (!fts_fwupg_need_upgrade(*fw_file_buf)) {
        return -EINVAL;
    }

    return ret;
}
/*****************************************************************************
 *  Name: fts_fwupg_work
 *  Brief: 1. get fw image/file
 *         2. ic init if have
 *         3. call upgrade main function(fts_fwupg_auto_upgrade)
 *  Input: NA
 *  Output:NA
 *  Return:NA
 *****************************************************************************/
static void fts_fwupg_work(struct work_struct *work)
{
    int ret = 0;
    u32 fw_file_len = 0;
    u8 *fw_file_buf = NULL;
    int i = 0;

    /* 600000: Wait for chip_prod image mount complete, timeout 60s */
    wait_chip_prod_mount(60000);

    ret = fts_upgrade_init(&fw_file_buf);
    if (ret < 0) {
        goto err_bin;
    }
    
    fw_file_len = ret;

    fts_hid_data->fw_loading = 1;
    __pm_stay_awake(fts_hid_data->ws);
    cancel_work_sync(&fts_hid_data->esd_work);
    focal_esdcheck_switch(fts_hid_data, DISABLE);

    /* run auto upgrade */
    do {
        ret = fts_do_upgrade(fw_file_len, fw_file_buf);
        if (ret < 0) {
            FTS_INFO("fts_do_upgrade fail");
        }
        i++;
    } while (ret && (i < FTS_RETRY_NUM_3));
    fts_hid_data->fw_loading = false;
    __pm_relax(fts_hid_data->ws);
    focal_esdcheck_switch(fts_hid_data, ENABLE);

    err_bin:
    if (fw_file_buf) {
        vfree(fw_file_buf);
        fw_file_buf = NULL;
    }

    return;
}


int focal_fwupg_init(struct fts_hid_data *ts_data)
{
    FTS_INFO("fw upgrade init function");

    INIT_DELAYED_WORK(&ts_data->fwupg_work, fts_fwupg_work);
    queue_delayed_work(ts_data->ts_workqueue, &ts_data->fwupg_work, msecs_to_jiffies(10000)); // 10000: delay 10s

    return 0;
}

int focal_fwupg_exit(struct fts_hid_data *ts_data)
{
    FTS_FUNC_ENTER();
    cancel_delayed_work_sync(&ts_data->fwupg_work);

    FTS_FUNC_EXIT();
    return 0;
}
