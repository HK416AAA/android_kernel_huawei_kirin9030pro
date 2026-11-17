/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: pin config
 * Author: common drivers
 */

#include "pin_config.h"
#include "oal_util.h"
#include "plat_debug.h"
#include "plat_firmware.h"

#define PACKAGE_HEADER_LEN      16
#define IMAGE_INFO_LEN          16

OAL_STATIC uint8_t *g_pin_config_data_buf = NULL;
OAL_STATIC uint32_t g_pin_config_data_len = 0;
OAL_STATIC uint32_t g_pin_config_load_addr = 0;
OAL_STATIC int32_t g_pin_config_buff_is_set = 0;

STATIC int32_t read_pin_cfg_image(os_kernel_file *fp, uint32_t offset, uint32_t len, uint32_t load_addr)
{
    uint8_t *buffer = NULL;
    int32_t rdlen;

    buffer = (uint8_t *)os_kzalloc_gfp(len);
    if (buffer == NULL) {
        return -ENOMEM;
    }

    fp->f_pos = offset;
    rdlen = oal_file_read_ext(fp, fp->f_pos, buffer, len);
    if (rdlen <= 0) {
        os_mem_kfree(buffer);
        return -EFAIL;
    }

    g_pin_config_data_buf = buffer;
    g_pin_config_data_len = len;
    g_pin_config_load_addr = load_addr;
    g_pin_config_buff_is_set = 1;

    return SUCC;
}

int32_t set_pin_config_buf(char *file_name, uint32_t id)
{
    int32_t rdlen, ret = -EFAIL;
    os_kernel_file *fp = NULL;
    mm_segment_t fs;
    uint32_t i, load_addr, data_offset, buff_len = 0;
    pin_cfg_package_header_t header;
    pin_cfg_image_info_t info;

    fs = get_fs();
    set_fs(KERNEL_DS);
    fp = filp_open(file_name, O_RDONLY, 0);
    if (IS_ERR(fp)) {
        ps_print_err("open file %s fail, fp=%p\n", file_name, fp);
        set_fs(fs);
        return -EFAIL;
    }

    /* 读取pin cfg文件头pin_cfg_package_header_t，确定cfg image个数 */
    rdlen = oal_file_read_ext(fp, fp->f_pos, (char *)&header, PACKAGE_HEADER_LEN);
    if (rdlen <= 0) {
        goto set_buf_end;
    }

    if (header.head_magic != PACKAGE_HEAD_MAGIC) {
        goto set_buf_end;
    }

    /* 读取各个cfg image文件头pin_cfg_package_header_t，确定image长度、加载地址和pin管脚配置数据 */
    fp->f_pos = PACKAGE_HEADER_LEN;
    for (i = 0; i < header.cfg_num; i++) {
        rdlen = oal_file_read_ext(fp, fp->f_pos, (char *)&info, IMAGE_INFO_LEN);
        if (rdlen > 0) {
            fp->f_pos += IMAGE_INFO_LEN;
        } else {
            goto set_buf_end;
        }

        if (info.product_id == id) {
            data_offset = info.addr;
            buff_len = info.length;
            load_addr = info.load_addr;
            break;
        }
    }

    if (buff_len == 0) {
        goto set_buf_end;
    }

    /* 读取对应product id的pin管脚配置数据，并保存到g_pin_config_data_buf中 */
    ret = read_pin_cfg_image(fp, data_offset, buff_len, load_addr);
    if (ret < 0) {
        ps_print_err("read pin cfg image, ret=%x\n", ret);
    }

set_buf_end:
    filp_close(fp, NULL);
    set_fs(fs);
    return ret;
}

uint8_t *get_pin_config_buf_addr(void)
{
    return g_pin_config_data_buf;
}

uint32_t get_pin_config_len(void)
{
    return g_pin_config_data_len;
}

uint32_t get_pin_config_load_addr(void)
{
    return g_pin_config_load_addr;
}

int32_t pin_config_buff_is_set(void)
{
    return g_pin_config_buff_is_set;
}

void pin_config_parameter_free(void)
{
    if (g_pin_config_data_buf != NULL) {
        os_mem_kfree(g_pin_config_data_buf);
        g_pin_config_data_buf = NULL;
    }
}
