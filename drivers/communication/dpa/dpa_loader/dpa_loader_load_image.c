/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <linux/mm.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/semaphore.h>
#include <linux/slab.h>
#include <bsp_dpa_loader.h>
#include <securec.h>
#include <bsp_sec_call.h>
#include "dpa_loader_util.h"
#include "dpa_loader_dump.h"
#include "dpa_loader_err.h"
#include "dpa_loader_sec_call.h"
#include "dpa_loader_load_image.h"

#define DPA_RESET_CMD (0x44525354) // DRST，dpa reset缩写

struct loader_info {
    char *local_buf;
};

struct loader_info g_dpa_loader_loader_info;

static char *dpa_loader_get_local_buffer(u32 *size)
{
    if (size != NULL) {
        *size = DPA_LOADER_SECBOOT_BUFLEN;
    }
    return g_dpa_loader_loader_info.local_buf;
}

static int dpa_loader_get_vrl_size(u32 buffer_size, u32 *vrl_size)
{
    dpa_loader_dump_img_load_proc_start(DPA_LOADER_VERIFY_VRL_SIZE);
    *vrl_size = DPA_SECBOOT_VRL_SIZE;
    if (*vrl_size > buffer_size) {
        dpa_loader_print_err("fail to read vrl, buffer size 0x%x err\n", buffer_size);
        dpa_loader_dump_img_load_proc_end(DPA_LOADER_VERIFY_VRL_SIZE, DPA_LOADER_ERR_NO_MEMORY);
        return DPA_LOADER_ERR_NO_MEMORY;
    }
    dpa_loader_dump_img_load_proc_end(DPA_LOADER_VERIFY_VRL_SIZE, 0);
    return 0;
}

static struct file* dpa_loader_open_file(const char *file_path)
{
    struct file *fp;
    dpa_loader_dump_img_load_proc_start(DPA_LOADER_FILE_OPEN);
    fp = filp_open(file_path, O_RDONLY, 0);
    dpa_loader_dump_img_load_proc_end(DPA_LOADER_FILE_OPEN, DPA_LOADER_OK);
    if (IS_ERR_OR_NULL(fp)) {
        dpa_loader_dump_img_load_proc_end(DPA_LOADER_FILE_OPEN, (int)PTR_ERR(fp));
    }
    return fp;
}

static int dpa_loader_prepare(dpa_loader_img_id_e image)
{
    int ret;
    dpa_loader_dump_img_load_proc_start(DPA_LOADER_VERIFY_PREPARE);
    ret = dpa_loader_sec_prepare(image);
    dpa_loader_dump_img_load_proc_end(DPA_LOADER_VERIFY_PREPARE, ret);
    return ret;
}

static int dpa_loader_read_cert(const char *file_path, struct file *fp, loff_t *offset, char *buffer, u32 buffer_size)
{
    ssize_t read_size;

    dpa_loader_dump_img_load_proc_start(DPA_LOADER_LOAD_VRL);
    read_size = kernel_read(fp, buffer, buffer_size, offset);
    dpa_loader_dump_img_load_proc_end(DPA_LOADER_LOAD_VRL, (read_size != buffer_size) ? DPA_LOADER_ERR_READ_VRL : DPA_LOADER_OK); 
    if (read_size != buffer_size) {
        dpa_loader_print_err("fail to read file(%s) vrl, ret = %zd\n", file_path, read_size);
        return DPA_LOADER_ERR_READ_VRL;
    }
    return DPA_LOADER_OK;
}

static int dpa_loader_send_cert(dpa_loader_img_id_e image, char *buffer, u32 buffer_size)
{
    int ret;
    dpa_loader_dump_img_load_proc_start(DPA_LOADER_SEND_VRL);
    ret = dpa_loader_sec_copy_vrl(image, buffer, buffer_size);
    dpa_loader_dump_img_load_proc_end(DPA_LOADER_SEND_VRL, ret); 
    dpa_loader_print_info("copy vrl: image %d, size %u, ret = %d\n", image, buffer_size, ret);
    return ret;
}

static int dpa_loader_verify(dpa_loader_img_id_e image)
{
    int ret;
    dpa_loader_dump_img_load_proc_start(DPA_LOADER_IMG_VERIFY);
    ret = dpa_loader_sec_verify(image);
    dpa_loader_dump_img_load_proc_end(DPA_LOADER_IMG_VERIFY, ret);
    return ret;
}

int dpa_loader_sec_load_image(const char *file_path, dpa_loader_img_id_e image)
{
    int ret;
    ssize_t read_size;
    struct file *fp = NULL;
    loff_t offset_loff_t = 0;
    u32 buffer_size = 0;
    u32 vrl_size, ddr_offset;
    char *buffer = dpa_loader_get_local_buffer(&buffer_size);

    ret = dpa_loader_get_vrl_size(buffer_size, &vrl_size);
    if (ret) {
        return ret;
    }

    fp = dpa_loader_open_file(file_path);
    if (IS_ERR_OR_NULL(fp)) {
        return (int)PTR_ERR(fp);
    }

    ret = dpa_loader_prepare(image);

    ret = dpa_loader_read_cert(file_path, fp, &offset_loff_t, buffer, vrl_size);
    if (ret) {
        goto fail_read_file;
    }

    ret = dpa_loader_send_cert(image, buffer, vrl_size);

    ddr_offset = 0;
    dpa_loader_dump_img_load_proc_start(DPA_LOADER_LOAD_DATA);
    do {
        read_size = kernel_read(fp, buffer, buffer_size, &offset_loff_t);
        if (read_size == 0) {
            break;
        }
        if (read_size < 0) {
            dpa_loader_print_err("fail to read file(%s) data, ret = %zd\n", file_path, read_size);
            dpa_loader_dump_img_load_proc_end(DPA_LOADER_LOAD_DATA, DPA_LOADER_ERR_READ_DATA);
            goto fail_read_file;
        }
        dpa_loader_print_info("read data success\n");
        ret = dpa_loader_sec_copy_data(image, buffer, ddr_offset, read_size);
        dpa_loader_print_info("copy data: image %d, offset 0x%X, size 0x%zX, ret %d\n", image, ddr_offset, read_size, ret);
        ddr_offset += read_size;
    } while (read_size > 0);
    dpa_loader_dump_img_load_proc_end(DPA_LOADER_LOAD_DATA, ret);

fail_read_file:
    filp_close(fp, NULL);
    ret = dpa_loader_verify(image);
    return ret;
}

static int dpa_loader_sec_load_dpa_image(char *file_name, dpa_loader_img_id_e image, unsigned int retry_times)
{
    int ret;
    const char *file_path = dpa_loader_get_img_path(image);

    dpa_loader_dump_img_load_start(file_name, retry_times);
    ret = dpa_loader_sec_load_image((const char *)file_path, image);
    if (ret) {
        return ret;
    }
    dpa_loader_dump_img_load_end();
    return ret;
}

int bsp_dpa_loader_load_and_verify_image(dpa_loader_img_id_e image)
{
    int ret;
    unsigned int i;
    char file_name[DPA_MAX_IMG_NAME_LEN] = {0};

    ret = dpa_loader_get_img_name(image, file_name, sizeof(file_name));
    if (ret) {
        dpa_loader_print_err("get %d name failed,ret=0x%x\n", image, ret);
        return ret;
    }

    for (i = 0; i < DPA_LOADER_MAX_LOAD_RETRY_TIEMS; i++) {
        ret = dpa_loader_sec_load_dpa_image(file_name, image, i + 1);
        if (ret == 0) {
            dpa_loader_print_err("load and verify %s success\n", file_name);
            return ret;
        }
        dpa_loader_print_err("load image %s failed, ret = %d, retry_times = %d\n", file_name, ret, i + 1);
    }
    return ret;
}

static inline int dpa_loader_get_cert(char *buffer, u32 buffer_size, const char *img_data, u32 vrl_size)
{
    return memcpy_s(buffer, buffer_size, img_data, vrl_size);
}

int bsp_dpa_loader_copy_and_verify_image(dpa_loader_img_id_e image, const char *img_data,
    u32 img_size)
{
    int ret;
    ssize_t read_size;
    u32 buffer_size = 0;
    u32 vrl_size, ddr_offset, remainder, img_offset;
    char *buffer = dpa_loader_get_local_buffer(&buffer_size);

    if (img_data == NULL) {
        dpa_loader_print_err("buffer is null\n");
        return DPA_LOADER_ERR_ARG;
    }

    ret = dpa_loader_get_vrl_size(buffer_size, &vrl_size);
    if (ret) {
        return ret;
    }

    if (img_size <= vrl_size) {
        dpa_loader_print_err("img_size(0x%x) err\n", img_size);
        return DPA_LOADER_ERR_ARG;
    }

    ret = dpa_loader_prepare(image);
    if (ret) {
        dpa_loader_print_err("sec prepare err, ret=0x%x\n", ret);
    }

    ret = dpa_loader_get_cert(buffer, buffer_size, img_data, vrl_size);
    if (ret) {
        dpa_loader_print_err("get cert err,ret=0x%x\n", ret);
    }

    ret = dpa_loader_send_cert(image, buffer, vrl_size);
    if (ret) {
        dpa_loader_print_err("send cert err,ret=0x%x\n", ret);
    }

    ddr_offset = 0;
    remainder = img_size - vrl_size;
    img_offset = vrl_size;
    dpa_loader_dump_img_load_proc_start(DPA_LOADER_LOAD_DATA);
    do {
        read_size = (remainder >= buffer_size) ? buffer_size : remainder;
        ret = memcpy_s(buffer, buffer_size, img_data + img_offset, read_size);
        if (ret < 0) {
            dpa_loader_print_err("get img data failed,ret=0x%x\n", ret);
            break;
        }
        ret = dpa_loader_sec_copy_data(image, buffer, ddr_offset, read_size);
        dpa_loader_print_info("copy data: image %d, offset 0x%X, size 0x%zX, ret %d\n", image, ddr_offset, read_size, ret);
        ddr_offset += read_size;
        img_offset += read_size;
        remainder -= read_size;
    } while (remainder > 0);
    dpa_loader_dump_img_load_proc_end(DPA_LOADER_LOAD_DATA, ret);

    ret = dpa_loader_verify(image);
    if (ret) {
        dpa_loader_print_err("verify img %d failed, ret=0x%x\n", image, ret);
        return ret;
    }
    dpa_loader_print_err("verify %d ok\n", image);
    return ret;
}

int bsp_dpa_loader_reset(void)
{
    int ret;
    dpa_loader_dump_init_start(DPA_FIRMWARE_RESET);
    ret = bsp_sec_call(FUNC_MDRV_MODEM_SECBOOT_CMD, DPA_RESET_CMD);
    dpa_loader_dump_init_end(DPA_FIRMWARE_RESET, ret);
    if (ret) {
        dpa_loader_print_err("fail to assert dpa reset, ret = %d\n", ret);
        return ret;
    }
    return ret;
}

int dpa_loader_loader_init(void)
{
    int ret;

    g_dpa_loader_loader_info.local_buf = (char *)kzalloc(PAGE_ALIGN(DPA_LOADER_SECBOOT_BUFLEN), GFP_KERNEL);
    if (g_dpa_loader_loader_info.local_buf == NULL) {
        dpa_loader_print_err("fail to malloc loader buffer\n");
        return -ENOMEM;
    }

    ret = dpa_loader_verifier_init();
    if (ret) {
        return ret;
    }

    dpa_loader_print_err("dpa_loader loader init ok\n");
    return ret;
}
