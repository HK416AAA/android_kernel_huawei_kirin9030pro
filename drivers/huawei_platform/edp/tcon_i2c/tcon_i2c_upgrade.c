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
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/firmware.h>
#include "tcon_i2c.h"
#include "edp_log.h"
#include "tcon_i2c_upgrade.h"

#define WRITE_BUF_LEN 1
#define READ_BUF_LEN 13
#define VENDOR_BIT_POSITION 10
#define VERSION_BIT_POSITION 8
#define WARNING_TRY_CNT 3
#define MAX_GET_RESULT_TRY_CNT 10
#define REPEAT_PACKAGE_TRY_CNT 10
#define REQUEST_TRY_CNT 100
#define CRC_CHECKSUM_1 0x01
#define CRC_CHECKSUM_2 0x8c
#define CRC_MAGIC_1 0x8000
#define CRC_MAGIC_2 0x8005
#define REQUEST_WRITE 0x93
#define UPG_VERSION_MAX_LEN 12
#define UPG_CRC_CHECKSUM_LEN 2
#define UPG_IMAGE_AND_TCON_BIN_MAX_LEN (256 * 1024 * 2)
#define IMAGE_OFFSET_WITH_2_BIN 28 // 4 algen
#define LOGOBIN_MAGIC_NUM 0x1C2C3C4C
#define IMAGE_TCONBIN_MAGIC_NUM1 0x00500301
#define IMAGE_TCONBIN_MAGIC_NUM2 0x00500302
#define PER_PACKT_MAX_SIZE 256
#define REQUEST_LEN 27
#define REQUEST_HEAD 0x91
#define MAIN_UPDATE_REAUEST_CMD 0x91
#define EXTRA_UPDATE_REAUEST_CMD 0x95
#define MAX_EXTRA_UPDATE_TRY_CNT 10

enum ext_upgrage_result {
    UPG_RESULT_DEVICE_BUSY = 0x0, // if devie busy mean no prepare recive new pack or request, need try check again
    UPG_RESULT_READY_TO_REQUST, // init state when not quest upgrade
    UPG_RESULT_REQUEST_FAIL, // request arg check failed, need request again
    UPG_RESULT_REQUEST_SUCCESS, // request ok, can start send package
    UPG_RESULT_DATA_RECIVE_BUSY, // no buf to recive package, need wait and try send package again
    UPG_RESULT_DATA_CHECK_ERROR, // package check error, need try send package again
    UPG_RESULT_DATA_CHECK_SUCESS, // package check success, send next id package or wait all package wait write finish
    UPG_RESULT_WRITE_FINISH, // all package write finish, upgrade finish in this request
    UPG_RESULT_WRITE_ERROR, // flash write failed, this flash may damaged, please stop upgrade
    UPG_RESULT_MAX,
};

static struct ext_result_info {
    uint8_t upgrade_status;
    uint8_t current_bin_type;
    unsigned short current_pack_id;
};

enum ext_bin_type {
    UPG_BIN_TYPE_IMAGE,
    UPG_BIN_TYPE_TCON,
    UPG_BIN_TYPE_RESERVE,
    UPG_BIN_TYPE_MAX,
};

static const unsigned int g_vendor_list[] = { 0x0101, 0x0102, 0x0103, 0x0105, 0x0106, 0x0107,
                                              0x0108, 0x0109, 0x0111, 0x0112, 0x0113, 0x0114,
                                              0x0115, 0x0116, 0x0117, 0x0118, 0x0119, 0x0120,
                                              0x0121, 0x0123, 0x0126, 0x0127, 0x0128, 0x012B,
                                              0x012E, 0x012F, 0x0131, 0x0133, 0x0135, 0x0136,
                                              0x0138 };

static uint8_t g_ext_update_status = UPDATE_WAITING;
static struct bin_vendor_info g_bin_vendor_info = { 0 };

uint8_t get_update_status()
{
    return g_ext_update_status;
}

struct bin_vendor_info* get_bin_vendor_info(void)
{
    return &g_bin_vendor_info;
}

static bool check_vendor_valid(uint32_t vendor)
{
    int vendor_index = 0;
    int vendor_list_len = sizeof(g_vendor_list) / sizeof(g_vendor_list[0]);

    for (vendor_index = 0; vendor_index < vendor_list_len; vendor_index++) {
        if (g_vendor_list[vendor_index] == vendor)
            return true;
    }
    return false;
}

static uint8_t crc_8_checkSum(const uint8_t *buffer, uint32_t len)
{
    uint8_t crc = 0;
    uint8_t i = 0;
    uint8_t u8_len = 8;
    uint32_t crc_index = 0;

    for (crc_index = 0; crc_index < len; crc_index++) {
        crc ^= buffer[crc_index];
        for (i = 0; i < u8_len; i++) {
            if (crc & CRC_CHECKSUM_1)
                crc = (crc >> 1) ^ CRC_CHECKSUM_2;
            else
                crc >>= 1;
        }
    }

    return crc;
}

static unsigned short crc_16_checkSum(const uint8_t *buffer, uint32_t len)
{
    uint32_t i, j;
    unsigned short crc_data = 0;
    unsigned short tmp;
    uint32_t crc_len = 8;

    for (i = 0; i < len; i++) {
        tmp = (unsigned short)(buffer[i] << crc_len);
        crc_data ^= tmp;
        for (j = 0; j < crc_len; j++) {
            if ((crc_data & CRC_MAGIC_1) == CRC_MAGIC_1) {
                crc_data = crc_data << 1;
                crc_data = crc_data ^ CRC_MAGIC_2;
            } else
                crc_data = crc_data << 1;
        }
    }
    return crc_data;
}

int get_tconic_vendor(unsigned short *vendor, unsigned short *version)
{
	unsigned char cmd_write_buff[WRITE_BUF_LEN] = { 0 };
    unsigned char cmd_read_buff[READ_BUF_LEN] = { 0 };
    unsigned int try_cnt = 0;
    int ret = 0;

    if (!vendor || !version)
        return -EINVAL;
    cmd_write_buff[0] = WRITE_CMD_HEAD;
    for (try_cnt = 0; try_cnt < MAX_GET_RESULT_TRY_CNT; try_cnt++) {
        ret = tcon_i2c_write_block(cmd_write_buff, WRITE_BUF_LEN);
        if (ret < 0) {
			edp_warn("write block failed, try again!\n");
			continue;
		}
        mdelay(5); // delay 5ms
        ret = tcon_i2c_read_block(cmd_read_buff, READ_BUF_LEN);
        if (ret < 0) {
			edp_warn("read block failed, try again!\n");
			continue;
		}
        if (cmd_read_buff[READ_BUF_LEN - 1] == crc_8_checkSum(cmd_read_buff, READ_BUF_LEN - 1)) {
            *vendor = *(unsigned short *)&cmd_read_buff[VENDOR_BIT_POSITION];
            *version = *(unsigned short *)&cmd_read_buff[VERSION_BIT_POSITION];
            edp_info("get vendor %x verson %x ok [cnt=%d].\n", *vendor, *version, try_cnt);
            if (check_vendor_valid(*vendor)) {
                edp_info("get valid vendor %x\n", *vendor);
                break;
            } else {
                edp_warn("invalid vendor  %x, need retry!\n", *vendor);
            }
        }
        mdelay(3); // delay 3ms
    }
    if (try_cnt >= MAX_GET_RESULT_TRY_CNT) {
        edp_err("get vendor failed [cnt=%d]. \n", try_cnt);
        return -EFAULT;
    }
    return 0;
}

static void get_result_info(struct ext_result_info *getInfo)
{
	uint8_t result[sizeof(struct ext_result_info) + 1] = { 0 };
    struct ext_result_info *info = (struct ext_result_info *)&result[0];
    unsigned int try_cnt = 0;
    int ret = 0;
    const int request_read_len = 5;
    uint8_t checksum = 0;
    uint8_t request_write_buffer;

    if (getInfo == NULL) {
        edp_err("getInfo is NULL");
        return;
    }
    for (try_cnt = 0; try_cnt < MAX_GET_RESULT_TRY_CNT; try_cnt++) {
        if (info->upgrade_status != UPG_RESULT_DEVICE_BUSY && checksum == result[sizeof(struct ext_result_info)])
            break;
        request_write_buffer = REQUEST_WRITE;
        ret = tcon_i2c_write_block(&request_write_buffer, WRITE_BUF_LEN);
        if (ret < 0) {
			edp_warn("write block failed, try again!\n");
			continue;
		}
        mdelay(2); // delay 2ms
        ret = tcon_i2c_read_block(result, request_read_len);
        if (ret < 0) {
			edp_warn("read block failed, try again!\n");
			continue;
		}
        checksum = crc_8_checkSum(result, sizeof(struct ext_result_info));
        udelay(100); // delay 100us
    }

    if (try_cnt > WARNING_TRY_CNT)
        edp_warn("try_cnt %u\n", try_cnt);
	*getInfo = *info;
    return;
}

static bool send_bin(unsigned char *image_data_bin, unsigned short datasize)
{
    int try_cnt = 0;
    int ret;
    struct ext_result_info send_info = { 0 };

    for (try_cnt = 0; try_cnt < REPEAT_PACKAGE_TRY_CNT; try_cnt++) {
        mutex_lock(&tcon_i2c_mutex);
        ret = tcon_i2c_write_block(image_data_bin, (9 + datasize)); // 9 is head + tail
        if (ret) {
            mutex_unlock(&tcon_i2c_mutex);
            edp_warn("warning:i2c write fail, need repreat!");
            continue;
        }
        mdelay(2); // delay 2ms
        get_result_info(&send_info);
        mutex_unlock(&tcon_i2c_mutex);
        if (send_info.upgrade_status == UPG_RESULT_DATA_CHECK_SUCESS ||
            send_info.upgrade_status == UPG_RESULT_WRITE_FINISH)
            break;
        // if device busy or check error, need repeat send pakage
        edp_warn("warning: status is %x type %x id %u, need repreat!\n",
            send_info.upgrade_status, send_info.current_bin_type, send_info.current_pack_id);
    }
    if (try_cnt >= REPEAT_PACKAGE_TRY_CNT) {
        edp_err("send bin failed!\n");
        return false;
    }
    edp_debug("send bin success!\n");
    return true;
}

static int pack_and_send_bin(const struct firmware *fw, uint32_t binSize, uint8_t binType, unsigned long *pos)
{
    const unsigned int data_bin_len = PER_PACKT_MAX_SIZE + 9;
    unsigned char image_data_bin[data_bin_len] = { 0 };
    const unsigned char data_bin_head = 0x92;
    const uint8_t head_index = 0;
    const uint8_t send_id_index = 1;
    const uint8_t bin_type_index = 3;
    const uint8_t size_index = 5;
    const uint8_t head_len = 7;
    unsigned short send_id = 0;
    int i = 0;
    uint32_t need_send_bin_size = binSize;
    unsigned short datasize;

    if (!fw) {
        edp_err("fw is null");
        return -EINVAL;
    }

    for (need_send_bin_size = binSize; need_send_bin_size > 0; need_send_bin_size -= datasize) {
        datasize = need_send_bin_size >= PER_PACKT_MAX_SIZE ? PER_PACKT_MAX_SIZE : need_send_bin_size;
        for (i = 0; i < datasize && head_len + i < data_bin_len; i++) {
            if (*pos < fw->size) {
                image_data_bin[head_len + i] = fw->data[*pos];
                (*pos)++;
            } else {
                edp_err("error: pos %d out of range\n", *pos);
                break;
            }
        }

        if (head_len + datasize >= data_bin_len) {
            edp_err("datasize %d is error", datasize);
            return -EINVAL;
        }
        image_data_bin[head_index] = data_bin_head;
        *(unsigned short *)&image_data_bin[send_id_index] = send_id;
        image_data_bin[bin_type_index] = binType;
        image_data_bin[4] = 0; // 4 is reserve
        *(unsigned short *)&image_data_bin[size_index] = datasize;
        *(unsigned short *)&image_data_bin[head_len + datasize] =\
            crc_16_checkSum(image_data_bin, (head_len + datasize));
        if (!send_bin(image_data_bin, datasize)) {
            edp_err("send package type %x id %d failed!\n", binType, send_id);
            return -EFAULT;
        }
        if (send_id % 100 == 0) // every 100 cnt print
            edp_info("info: send data type %x id %d ok [every 100 cnt print]\n", binType, send_id);
        send_id++;
    }
    return 0;
}

static int check_upgrade_status(void)
{
    struct ext_result_info end_info = { 0 };
    unsigned int try_cnt = 0;

    for (try_cnt = 0; try_cnt < MAX_GET_RESULT_TRY_CNT; try_cnt++) {
        get_result_info(&end_info);
        if (end_info.upgrade_status == UPG_RESULT_WRITE_FINISH) {
            edp_info("info:TCON FW Update success.[%d]\n", try_cnt);
            break;
        }
        if (end_info.upgrade_status == UPG_RESULT_WRITE_ERROR) {
            edp_err("error:TCON FW Update failed!\n");
            return -EFAULT;
        }
        mdelay(100); // delay 100ms
    }
    if (try_cnt >= MAX_GET_RESULT_TRY_CNT) {
        edp_err("check upgrade status timeout!\n");
        return -ETIMEDOUT;
    }
    return 0;
}

static int check_bin_vendor_match(uint8_t *version_information, unsigned short tcon_vendor,
                                  unsigned short tcon_version, bool main_flag)
{
    const int type_index = 1;
    const int vendor_index = 11;
    const int version_index = 9;
    unsigned short bin_vendor = *(unsigned short *)&version_information[vendor_index];
    unsigned short bin_version = *(unsigned short *)&version_information[version_index];

    edp_info("info: bin vendor %x fwvendor %x [version %x] match ok\n", bin_vendor, tcon_vendor, bin_version);
    if (*(uint32_t *)&version_information[type_index] == LOGOBIN_MAGIC_NUM) {
        edp_warn("update logo bin not support, vendor %x verion %x!\n", tcon_vendor, tcon_version);
        return TCON_UNSUPPORT_LOGO_BIN;
    }
    if ((*(uint32_t *)&version_information[type_index] != IMAGE_TCONBIN_MAGIC_NUM1) &&
        (*(uint32_t *)&version_information[type_index] != IMAGE_TCONBIN_MAGIC_NUM2)) {
        edp_err("error: update bin error magic number %x not support\n", *(uint32_t *)&version_information[type_index]);
        return TCON_MAGIC_NUMBER_ERR;
    }
    if (bin_vendor != tcon_vendor) {
        edp_err("error: bin vendor %x fwvendor %x [version %x] not match\n", bin_vendor, tcon_vendor, bin_version);
        return TCON_VENDOR_NOT_MATCH;
    }
    g_bin_vendor_info.vendor = bin_vendor;
    g_bin_vendor_info.version = bin_version;
    if (main_flag && tcon_version >= bin_version) {
        edp_info("info: bin vendor %x fwvendor %x [bin version %x <= tcon vendor %x] do not need upgrade\n",
            bin_vendor, tcon_vendor, bin_version, tcon_version);
        return TCON_NOT_NEED_UPGRADE;
    }
    return TCON_CHECK_SUCCESS;
}

static bool request_upgrade(uint8_t *version_information)
{
    unsigned int try_cnt = 0;
    int ret = 0;
    struct ext_result_info req_info = { 0 };

    for (try_cnt = 0; try_cnt < REQUEST_TRY_CNT; try_cnt++) {
        ret = tcon_i2c_write_block(version_information, REQUEST_LEN);
        if (ret < 0) {
			edp_warn("write block failed, try again!\n");
			continue;
		}
        get_result_info(&req_info);
        if (req_info.upgrade_status == UPG_RESULT_REQUEST_SUCCESS) {
            edp_info("info:the request upgrade ok [cnt=%d]\n", try_cnt);
            break;
        } else {
            edp_err("err:the request upgrade status error %d\n", req_info.upgrade_status);
        }
        udelay(100); // delay 100us
    }
    if (try_cnt >= REQUEST_TRY_CNT) {
        edp_err("request upgrade failed.\n");
        return false;
    }
    edp_info("request upgrade success.\n");
    return true;
}

int extra_upgrade_switch_boot(unsigned char pos)
{
    unsigned char cmd_write_buff[5] = {0xD1, 0xD2, 0xD3, 0xD4, 0x00};
    int ret;

    cmd_write_buff[4] = pos;
    ret = tcon_i2c_write_block(cmd_write_buff, 5);
    if (ret)
        edp_err("tcon_i2c_write_block fail \n");

    return ret;
}

static bool check_upgrade_bin_crc(const struct firmware *fw)
{
    unsigned char *buffer = (unsigned char *)kmalloc(fw->size, GFP_KERNEL);
    unsigned short *crc_check_sum = NULL;
    unsigned short checkSum;
    uint8_t *bin_num = NULL;
    uint8_t *imgbin_type = NULL;
    uint32_t *imgbin_size = NULL;
    uint8_t *tconbin_type = NULL;
    uint32_t *tconbin_size = NULL;

    if (buffer == NULL)
        return -EINVAL;
    if (memcpy_s(buffer, fw->size, fw->data, fw->size) != EOK) {
        edp_err("memcpy buffer fail \n");
        goto err;
    }
    crc_check_sum = (unsigned short *)&buffer[UPG_VERSION_MAX_LEN];
    bin_num = &buffer[UPG_VERSION_MAX_LEN + UPG_CRC_CHECKSUM_LEN];
    if (*bin_num >= UPG_BIN_TYPE_MAX) {
        edp_err("bin num %d check err\n", *bin_num);
        goto err;
    }
    imgbin_type = bin_num + 1;
    if (*imgbin_type >= UPG_BIN_TYPE_MAX) {
        edp_err("imgbin type %d check err\n", *imgbin_type);
        goto err;
    }
    imgbin_size = (uint32_t *)(imgbin_type + 1);
    tconbin_type = imgbin_type + 5; // 5 is bit tconbin
    if (*tconbin_type >= UPG_BIN_TYPE_MAX) {
        edp_err("bin num %d check err\n", *bin_num);
        goto err;
    }
    tconbin_size = (uint32_t *)(tconbin_type + 1);
    if (*imgbin_size + *tconbin_size > UPG_IMAGE_AND_TCON_BIN_MAX_LEN) {
        edp_err("head err type %x %x size %x %x\n", *imgbin_type, *tconbin_type, *imgbin_size, *tconbin_size);
        goto err;
    }
    checkSum = crc_16_checkSum((unsigned char *)&buffer[IMAGE_OFFSET_WITH_2_BIN], *imgbin_size + *tconbin_size);
    if (checkSum != *crc_check_sum) {
        edp_err("bin1 %d bin2 %d crc %x sum %x\n", *imgbin_size, *tconbin_size, *crc_check_sum, checkSum);
        goto err;
    }
    kfree(buffer);
    return true;
err:
    kfree(buffer);
    return false;
}

int check_bin_valid(const struct firmware *fw, unsigned short tcon_vendor,
                     unsigned short tcon_version, bool vendor_check_enable, bool main_flag)
{
    int i;
    uint8_t request_info[REQUEST_LEN] = { REQUEST_HEAD };

    // check update grade
    if (!check_upgrade_bin_crc(fw)) {
        edp_err("error: check upgrade bin crc error! stop upgrade!\n");
        return -EFAULT;
    }
    for (i = 1; i < REQUEST_LEN - 1 && i <= fw->size; i++)
        request_info[i] = fw->data[i - 1];

    request_info[REQUEST_LEN - 1] = crc_8_checkSum(request_info, REQUEST_LEN - 1); // update checksum
    if (vendor_check_enable) {
        edp_info("check vendor %x verion %x start!\n", tcon_vendor, tcon_version);
        return check_bin_vendor_match(request_info, tcon_vendor, tcon_version, main_flag);
    }
    return 0;
}

static int update_tconic_fw_base(const struct firmware *fw, uint8_t cmd, unsigned short tcon_vendor,
                             unsigned short tcon_version)
{
    int i;
    uint8_t request_info[REQUEST_LEN] = { cmd };
    unsigned long pos;
    uint8_t image_type;
    uint32_t image_bin_size;
    uint8_t tcon_type;
    uint32_t tcon_bin_size;

    if (!fw) {
        edp_err("firmware data is null");
        return -EFAULT;
    }

    for (i = 1; i < REQUEST_LEN - 1 && i <= fw->size; i++)
        request_info[i] = fw->data[i - 1];
    request_info[REQUEST_LEN - 1] = crc_8_checkSum(request_info, REQUEST_LEN - 1); // update checksum

    // request upgrade
    if (!request_upgrade(request_info)) {
        edp_err("error: request upgrade failed! stop upgrade!\n");
        return -EFAULT;
    }

    pos = REQUEST_LEN + 1; // data bin position
    image_type = request_info[16]; // request_info[16] is image_type
    image_bin_size =  *(uint32_t *)&request_info[17]; // request_info[17][18][19][20] is image_bin_size
    if (pack_and_send_bin(fw, image_bin_size, image_type, &pos) != 0) {
        edp_err("error: send image package failed! stop upgrade!\n");
        return -EFAULT;
    }

    tcon_type = request_info[21]; // request_info[21] is tcon_type
    tcon_bin_size = *(uint32_t *)&request_info[22]; // request_info[22][23][24][25] is tcon_bin_size
    if (pack_and_send_bin(fw, tcon_bin_size, tcon_type, &pos) != 0) {
        edp_err("error: send tcon package failed! stop upgrade!\n");
        return -EFAULT;
    }

    // check status
    return check_upgrade_status();
}

int update_tconic_fw_request(const struct firmware *fw, unsigned short tcon_vendor,
                             unsigned short tcon_version, bool main_flag)
{
    int cnt;
    uint32_t runType;

    if (main_flag) { // main partition update
        return update_tconic_fw_base(fw, MAIN_UPDATE_REAUEST_CMD, tcon_vendor, tcon_version);
    } else { // ext partition update
        runType = tcon_i2c_read_addr(PARTITIONS_START_ADDR);
        if ((runType >> 16) != 1) { // get high 16 bit
            edp_err("can not update extra bin,please start by main partitions\n");
            goto upd_err;
        }
        g_ext_update_status = UPDATE_DOING;
        for (cnt = 0; cnt < MAX_EXTRA_UPDATE_TRY_CNT; cnt++) {
            if (!update_tconic_fw_base(fw, EXTRA_UPDATE_REAUEST_CMD, tcon_vendor, tcon_version)) {
                break;
            } else {
                edp_err("update fail try again\n");
                continue;
            }
        }

        if (cnt >= MAX_EXTRA_UPDATE_TRY_CNT) {
            edp_err("update_tconic_fw_base fail!\n");
            goto upd_err;
        }
        g_ext_update_status = UPDATE_SUCESS;
        return 0;
upd_err:
        g_ext_update_status = UPDATE_FAIL;
        return -EFAULT;
    }
}

MODULE_AUTHOR("huawei");
MODULE_DESCRIPTION("huawei driver");
MODULE_LICENSE("GPL");
