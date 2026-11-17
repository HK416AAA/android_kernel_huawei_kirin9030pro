/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2025. All rights reserved.
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
#include "../file_ops/bsp_file_ops.h"
#include "syslog_file.h"
struct syslog_file_info g_file_info[SYSLOG_FILE_TYPE_CNT];

static int syslog_check_path(const char *path)
{
    if (strlen(path) >= SYSLOG_DIR_PTH_LEN) {
        dpa_pr_err("path too long, len=%d\n", (int)strlen(path));
        return BSP_ERROR;
    }

    if (strstr(path, "../")) {
        dpa_pr_err("path is not allowed, len=%s\n", path);
        return BSP_ERROR;
    }

    return BSP_OK;
}

int syslog_mkdir(const char *dir)
{
    int ret;
    unsigned long fs;
    int mode = SYSLOG_LOG_PHONE_DIR_AUTH;

    ret = syslog_check_path(dir);
    if (ret) {
        return ret;
    }

    fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);
    ret = bsp_file_mkdir(dir, mode);
    set_fs(fs);
    if (ret && ret != -EEXIST) {
        dpa_pr_err("sys_mkdir fail,ret=%d\n",ret);
        return ret;
    }

    return BSP_OK;
}

struct file *syslog_open(const char *path, int flags, int file_mode)
{
    unsigned long fs;
    struct file *fd = NULL;

    fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);
    fd = filp_open(path, flags, file_mode);
    set_fs(fs);
    /* 调用syslog_open的用户，只判断了是否为NULL，但linux返回的是错误码，因此这里需要转换一下 */
    if (IS_ERR_OR_NULL(fd)) {
        dpa_pr_err("get fd err, ret=0x%lx\n", PTR_ERR((const void *)fd));
        return NULL;
    }
    return fd;
}

int syslog_close(struct file *fd)
{
    int ret;
    unsigned long fs;

    fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);

    ret = filp_close(fd, NULL);

    set_fs(fs);

    return ret;
}

int syslog_write_sync(struct file *fd, const s8 *ptr, u32 size, u32 offset)
{
    int ret;
    unsigned long fs;
    loff_t pos = 0;

    fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);
    pos = vfs_llseek(fd, offset, SEEK_SET);
    ret = (int)kernel_write(fd, ptr, (size_t)size, &pos);
    (void)vfs_fsync(fd, 0);
    set_fs(fs);

    return ret;
}

static int syslog_lseek(struct file *fd, long offset, int whence)
{

    int ret;
    unsigned long old_fs;

    old_fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);

    ret = vfs_llseek(fd, offset, (u32)whence);

    set_fs(old_fs);

    return ret;
}
static int syslog_data_save(u32 index, struct file *fd, const void *address, u32 length, u32 max_size)
{
    u32 bytes;
    u32 offset = g_file_info[index].offset;
    // 从上次写的末尾位置开始写入
    u32 free_space = max_size - offset;

    // 空间不够，则从头开始存，覆盖旧的
    if (free_space <= 0 || free_space > max_size) {
        // 从文件头开始写
        free_space = max_size;
        offset = 0;
        g_file_info[index].offset = 0;
    }
    if (free_space < length) {
        bytes = (u32)syslog_write_sync(fd, address, free_space, offset);
        if (bytes != free_space) {
            return BSP_ERROR;
        }
        length = length - bytes;
        address = address + bytes;
        offset = 0;
        g_file_info[index].offset = 0;
    }
    bytes = (u32)syslog_write_sync(fd, address, length, offset);
    if (bytes != length) {
        return BSP_ERROR;
    }
    g_file_info[index].offset += bytes;

    return BSP_OK;
}
static int syslog_append_file(u32 index, const char *dir, const char *filename, const void *address, u32 length, u32 max_size)
{
    int ret = BSP_ERROR;
    struct file *fd = NULL;
    int len;
    if (length > max_size) {
        return BSP_ERROR;
    }
    if (dir == NULL) {
        return BSP_ERROR;
    }
    if (g_file_info[index].offset > max_size) {
        dpa_pr_err("syslog file offset error %u\n", g_file_info[index].offset);
        return ret;
    }
    ret = bsp_eaccess(dir);
    if (ret < 0) {
        return ret;
    }
    fd = syslog_open(filename, O_CREAT | O_RDWR, SYSLOG_LOG_FILE_AUTH);
    if (fd == NULL) {
        dpa_pr_err("fail to open %s,while mode is create\n", filename);
        return ret;
    }
    // 防止文件过长，回传不回来
    len = syslog_lseek(fd, 0, SEEK_END);
    if (len < 0) {
        dpa_pr_err("fail to seek ! ret = %d\n", len);
        goto out;
    } else if (len == 0) {
        // 防止文件被删除
        g_file_info[index].offset = 0;
    } else if (len > max_size) {
        // 文件过大，重新创建
        dpa_pr_err("file length error %d\n", len);
        (void)syslog_close(fd);
        fd = syslog_open(filename, O_CREAT | O_RDWR | O_TRUNC, SYSLOG_LOG_FILE_AUTH);
        if (fd == NULL) {
            dpa_pr_err("create again error\n");
            return BSP_ERROR;
        }
        g_file_info[index].offset = 0;
    }
    ret = syslog_data_save(index, fd, address, length, max_size);
out:
    (void)syslog_close(fd);
    return ret;
}

// 保存日志文件
int syslog_file_save(unsigned int index, const void *address, u32 length)
{
    if (index >= SYSLOG_FILE_TYPE_CNT) {
        return -1;
    }
    if (g_file_info[index].file_path_name == NULL ||  g_file_info[index].size == 0) {
        return -1;
    }
    if (address == NULL || length == 0 || length > g_file_info[index].size) {
        return -1;
    }

    return syslog_append_file(index, DPA_LOG_ROOT, g_file_info[index].file_path_name, address, length, g_file_info[index].size);
}
// 初始化日志文件信息
int syslog_file_init(void)
{
    int i;
    char file_tag_arry[SYSLOG_FILE_TYPE_CNT][SYSLOG_TAG_LEN] = { SYSLOG_FW_PRINT_TAG, SYSLOG_FW_RECORD_TAG, SYSLOG_HOST_RECORD_TAG };
    char file_name[SYSLOG_DIR_PTH_LEN];
    int ret;
    for (i = 0; i < SYSLOG_FILE_TYPE_CNT; i++) {
        g_file_info[i].size = SYSLOG_FILE_SIZE;
        g_file_info[i].offset = 0;
        ret = snprintf_s(file_name, SYSLOG_DIR_PTH_LEN, SYSLOG_DIR_PTH_LEN - 1, DPA_LOG_ROOT "%s", file_tag_arry[i]);
        if (ret < 0) {
            goto err;
        }
        file_name[ret] = '\0';
        ret++;
        g_file_info[i].file_path_name = kmalloc(ret, GFP_KERNEL);
        if (g_file_info[i].file_path_name == NULL ||
            strcpy_s(g_file_info[i].file_path_name, (size_t)ret, file_name) != EOK) {
            goto err;
        }
    }
    return 0;
err:
    for (;i > 0; i--) {
        if (g_file_info[i].file_path_name == NULL) {
            continue;
        }
        kfree(g_file_info[i].file_path_name);
        g_file_info[i].file_path_name = NULL;
        g_file_info[i].size = 0;
    }
    dpa_pr_err("syslog_file_init fail\n");
    return -1;
}