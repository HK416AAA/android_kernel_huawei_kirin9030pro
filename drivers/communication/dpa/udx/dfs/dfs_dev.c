/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
#include <linux/init.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/compat.h>
#include <linux/poll.h>
#include <linux/list.h>
#include <linux/kfifo.h>
#include <linux/dma-buf.h>
#include <linux/platform_device.h>
#include <securec.h>
#include "bsp_print.h"
#include "bsp_dmi.h"
#include "bsp_udx.h"
#include "bsp_mem_layout.h"
#include "dfs_dev.h"
#include "f2fs_intf.h"
#include "../buffer/udx_buffer.h"
#include "hmfs_intf.h"

#undef THIS_MODU
#define THIS_MODU mod_dfs

struct dfs_driver_data g_dfs_data;
struct udx_dfs_info g_udx_dfs_info;

struct udx_dfs_task_node *udx_dfs_get_instance(struct file *f)
{
    return (struct udx_dfs_task_node *)udx_service_get_instance(f);
}

struct udx_dfs_task_node *udx_dfs_get_instance_by_id(u32 task_id)
{
    int found = 0;
    struct list_head *pos, *tmp;
    struct udx_dfs_task_node *node = NULL;
    mutex_lock(&g_udx_dfs_info.task_list_mutex);
    list_for_each_safe(pos, tmp, &g_udx_dfs_info.task_list) {
        node = list_entry(pos, struct udx_dfs_task_node, list);
        if (node->task_id != task_id) {
            continue;
        }
        found = 1;
        break;
    }
    mutex_unlock(&g_udx_dfs_info.task_list_mutex);
    if (found == 0) {
        dfs_print("no taskid = %d found\n", task_id);
        return NULL;
    }

    return node;
}
ssize_t udx_dfs_service_read(struct file *file, char __user *buf, size_t count, loff_t *off)
{
    ssize_t ret;
    unsigned char c;
    struct udx_dfs_task_node *node;

    node = udx_dfs_get_instance(file);
    if (node == NULL) {
        dfs_print("Failed to get dfs task node\n");
        return -EBADF;
    }

    if ((kfifo_len(&node->msg_fifo) == 0) && (file->f_flags & O_NONBLOCK))
        return -EAGAIN;

    ret = wait_event_interruptible(node->waitq, kfifo_len(&node->msg_fifo) != 0);
    dfs_print("dfs reading\n");
    if (ret)
        return ret;

    while (ret < count && (kfifo_out(&node->msg_fifo, &c, sizeof(c)) == sizeof(c))) {
        if (put_user(c, buf++))
            return -EFAULT;
        ret++;
    }

    return ret;
}

__poll_t udx_dfs_service_poll(struct file *file, poll_table *wait)
{
    struct udx_dfs_task_node *node;

    node = udx_dfs_get_instance(file);
    if (node == NULL) {
        dfs_print("Failed to get dfs task node\n");
        return EPOLLERR;
    }

    poll_wait(file, &node->waitq, wait);
    dfs_print("trigger poll return\n");
    if (kfifo_len(&node->msg_fifo))
        return EPOLLIN | EPOLLRDNORM;

    return 0;
}

static int udx_dfs_buffer_get_paddr(int fd, u64 *paddr, u32 *size, u32 offset)
{
    int ret = 0;
    u64 dma_buf_paddr = 0;
    struct dma_buf *dma_buf;

    dma_buf = dma_buf_get(fd);
    if (IS_ERR(dma_buf)) {
        ret = PTR_ERR(dma_buf);
        dfs_print("Failed to get dma buf, err = %d\n", ret);
        return ret;
    }

    dma_buf_paddr = udx_buffer_get_dma_buf_paddr(dma_buf);
    if (dma_buf_paddr == 0) {
        ret = -EINVAL;
        dfs_print("Failed to get dma buf paddr\n");
        goto err_get_dma_buf_paddr;
    }

    *paddr = dma_buf_paddr + offset;
    if (size) {
        *size = dma_buf->size;
    }

err_get_dma_buf_paddr:
    dma_buf_put(dma_buf);

    return ret;
}

static long udx_dfs_ioctl_set_input_bufferqueue(struct udx_dfs_task_node *node, unsigned long arg,
    struct udx_dfs_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dfs_msg *pmsg;
    struct udx_dfs_ioctl_buffer buf_info[UDX_DFS_BUFFER_NODE_NUM] = { 0 };

    if (copy_from_user(buf_info, (void *)arg, sizeof(buf_info)) != 0) {
        dfs_print("Failed to copy from user\n");
        return -EFAULT;
    }

    ret = udx_dfs_buffer_get_paddr(buf_info[0].dma_buffer.attr.fd, &buf_info[0].dma_buffer.phy_addr, NULL,
        buf_info[0].dma_buffer.attr.offset);
    if (ret) {
        return ret;
    }
    ret = udx_dfs_buffer_get_paddr(buf_info[1].dma_buffer.attr.fd, &buf_info[1].dma_buffer.phy_addr, NULL,
        buf_info[1].dma_buffer.attr.offset);
    if (ret) {
        return ret;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(buf_info), GFP_KERNEL);
    if (pmsg == NULL) {
        dfs_print("Failed to allocate memory for set buffer msg\n");
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(buf_info);

    msg_data = (char *)(pmsg->buf);
    (void)memcpy_s(&msg_data[0], sizeof(buf_info), (void *)buf_info, sizeof(buf_info));
    dfs_print("msg: input buffer 0 offset = 0x%X, size = 0x%X, type = %d\n", buf_info[0].dma_buffer.attr.offset,
        buf_info[0].len, buf_info[0].type);
    dfs_print("msg: input buffer 1 offset = 0x%X, size = 0x%X, type = %d\n", buf_info[1].dma_buffer.attr.offset,
        buf_info[1].len, buf_info[1].type);

    return 0;
}

static long udx_dfs_ioctl_set_output_bufferqueue(struct udx_dfs_task_node *node, unsigned long arg,
    struct udx_dfs_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dfs_msg *pmsg;
    struct udx_dfs_ioctl_buffer buf_info[UDX_DFS_BUFFER_NODE_NUM] = { 0 };

    if (copy_from_user(buf_info, (void *)arg, sizeof(buf_info)) != 0) {
        dfs_print("udx_dfs_ioctl_set_output_bufferqueue Failed to copy from user 0x%lx\n", arg);
        return -EFAULT;
    }

    ret = udx_dfs_buffer_get_paddr(buf_info[0].dma_buffer.attr.fd, &buf_info[0].dma_buffer.phy_addr, NULL,
        buf_info[0].dma_buffer.attr.offset);
    if (ret) {
        return ret;
    }
    ret = udx_dfs_buffer_get_paddr(buf_info[1].dma_buffer.attr.fd, &buf_info[1].dma_buffer.phy_addr, NULL,
        buf_info[1].dma_buffer.attr.offset);
    if (ret) {
        return ret;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(buf_info), GFP_KERNEL);
    if (pmsg == NULL) {
        dfs_print("Failed to allocate memory for set out buffer msg\n");
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(buf_info);

    msg_data = (char *)(pmsg->buf);
    (void)memcpy_s(&msg_data[0], sizeof(buf_info), (void *)buf_info, sizeof(buf_info));
    dfs_print("msg: output buffer 0 offset = 0x%X, size = 0x%X, type = %d\n", buf_info[0].dma_buffer.attr.offset,
        buf_info[0].len, buf_info[0].type);
    dfs_print("msg: output buffer 1 offset = 0x%X, size = 0x%X, type = %d\n", buf_info[1].dma_buffer.attr.offset,
        buf_info[1].len, buf_info[1].type);

    return 0;
}

static long udx_dfs_ioctl_attach_buffer(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    int ret;
    struct udx_dfs_dma_buf_node *dma_buf_node;

    dma_buf_node = (struct udx_dfs_dma_buf_node *)kzalloc(sizeof(*dma_buf_node), GFP_KERNEL);
    if (dma_buf_node == NULL) {
        dfs_print("Failed to allocate memory for attach buffer msg\n");
        return -ENOMEM;
    }

    dma_buf_node->dma_buf = dma_buf_get(arg);
    if (IS_ERR(dma_buf_node->dma_buf)) {
        ret = PTR_ERR(dma_buf_node->dma_buf);
        dfs_print("Failed to get dma buf, err = %d\n", ret);
        goto fail_to_get_dma_buf;
    }

    dma_buf_node->attachment = dma_buf_attach(dma_buf_node->dma_buf, g_udx_dfs_info.dev);
    if (IS_ERR(dma_buf_node->attachment)) {
        ret = PTR_ERR(dma_buf_node->attachment);
        dfs_print("Failed to attach dma buf, err = %d\n", ret);
        goto fail_to_attach_dma_buf;
    }

    list_add_tail(&dma_buf_node->list, &node->dma_buf_list);

    dfs_print("msg: attach buffer ok\n");

    return 0;

fail_to_attach_dma_buf:
    dma_buf_put(dma_buf_node->dma_buf);

fail_to_get_dma_buf:
    kfree(dma_buf_node);

    return ret;
}

static long udx_dfs_ioctl_map_buffer(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    int ret;
    struct udx_dfs_ioctl_buffer_info buf_info = { 0 };
    char *msg_data = NULL;
    struct udx_dfs_msg *pmsg = NULL;

    buf_info.buf_fd = arg;
    ret = udx_dfs_buffer_get_paddr(buf_info.buf_fd, &buf_info.buf_addr, &buf_info.buf_size, 0);
    if (ret) {
        return ret;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(buf_info), GFP_KERNEL);
    if (pmsg == NULL) {
        dfs_print("Failed to allocate memory for map buffer msg\n");
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(buf_info);

    msg_data = (char *)(pmsg->buf);
    (void)memcpy_s(&msg_data[0], sizeof(buf_info), &buf_info, sizeof(buf_info));

    dfs_print("msg: map buffer ok\n");

    return 0;
}


static long udx_dfs_ioctl_prepare(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    struct udx_dfs_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dfs_print("msg: prepare\n");
    return 0;
}

static long udx_dfs_ioctl_start(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    struct udx_dfs_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dfs_print("msg: start\n");
    return 0;
}


static long udx_dfs_ioctl_pause(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    struct udx_dfs_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dfs_print("msg: pause\n");
    return 0;
}

static long udx_dfs_ioctl_resume(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    struct udx_dfs_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dfs_print("msg: resume\n");
    return 0;
}

static long udx_dfs_ioctl_reset(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    struct udx_dfs_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dfs_print("msg: reset\n");
    return 0;
}

static long udx_dfs_ioctl_stop(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    struct udx_dfs_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dfs_print("msg: stop\n");
    return 0;
}

static long udx_dfs_ioctl_open_session(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dfs_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_file_open_session_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dfs_print("Failed to allocate memory for open session msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_file_open_session_para));
    if (ret) {
        dfs_print("Failed to copy from user\n");
        return -EFAULT;
    }
    dfs_print("open session id %d\n", ((struct udx_file_open_session_para *)msg_data)->session_id);
    node->service_id = ((struct udx_file_open_session_para *)msg_data)->session_id;
    pmsg->header.data.len = sizeof(struct udx_file_open_session_para);
    *msg = pmsg;
    dfs_print("msg: open session ok\n");

    return 0;
}

static long udx_dfs_ioctl_open(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dfs_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_file_open_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dfs_print("Failed to allocate memory for open msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_file_open_para));
    if (ret) {
        dfs_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_file_open_para);
    *msg = pmsg;
    dfs_print("msg: open file ok\n");

    return 0;
}

static long udx_dfs_ioctl_close(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dfs_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_file_close_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dfs_print("Failed to allocate memory for close msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_file_close_para));
    if (ret) {
        dfs_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_file_close_para);
    *msg = pmsg;
    dfs_print("msg: close file ok\n");

    return 0;
}

static long udx_dfs_ioctl_read(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    int ret;
    struct udx_file_read_para *msg_data;
    struct udx_dfs_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_file_read_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dfs_print("Failed to allocate memory for read msg\n");
        return -ENOMEM;
    }
    msg_data = (struct udx_file_read_para *)(pmsg->buf);
    ret = copy_from_user(msg_data, argp, sizeof(struct udx_file_read_para));
    if (ret) {
        dfs_print("Failed to copy from user\n");
        return -EFAULT;
    }

    ret = udx_dfs_buffer_get_paddr(msg_data->read_buffer.buffer.buf_desc.buffer_fd,
        &msg_data->read_buffer.buffer.buf_addr, &msg_data->count, 0);
    if (ret) {
        return ret;
    }
    pmsg->header.data.len = sizeof(struct udx_file_read_para);
    *msg = pmsg;
    dfs_print("msg: read file ok\n");
    // wait read done event
    return 0;
}

static long udx_dfs_ioctl_write(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    int ret;
    struct udx_file_write_para *msg_data;
    struct udx_dfs_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_file_write_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dfs_print("Failed to allocate memory for write msg\n");
        return -ENOMEM;
    }
    msg_data = (struct udx_file_write_para *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_file_write_para));
    if (ret) {
        dfs_print("Failed to copy from user\n");
        return -EFAULT;
    }
    ret = udx_dfs_buffer_get_paddr(msg_data->write_buffer.buffer.buf_desc.buffer_fd,
        &msg_data->write_buffer.buffer.buf_addr, &msg_data->count, 0);
    if (ret) {
        return ret;
    }
    pmsg->header.data.len = sizeof(struct udx_file_write_para);
    *msg = pmsg;
    dfs_print("msg: write file ok\n");
    // wait write done event
    return 0;
}

static long udx_dfs_ioctl_lseek(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dfs_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_file_lseek_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dfs_print("Failed to allocate memory for lseek msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_file_lseek_para));
    if (ret) {
        dfs_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_file_lseek_para);
    *msg = pmsg;
    dfs_print("msg: lseek file ok\n");

    return 0;
}


static long udx_dfs_ioctl_unlink(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dfs_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_file_unlink_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dfs_print("Failed to allocate memory for unlink msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_file_unlink_para));
    if (ret) {
        dfs_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_file_unlink_para);
    *msg = pmsg;
    dfs_print("msg: unlink file ok\n");

    return 0;
}

static long udx_dfs_ioctl_rename(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dfs_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_file_rename_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dfs_print("Failed to allocate memory for rename msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_file_rename_para));
    if (ret) {
        dfs_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_file_rename_para);
    *msg = pmsg;
    dfs_print("msg: rename file ok\n");

    return 0;
}

static long udx_dfs_ioctl_set_fd_list_cma(struct udx_dfs_task_node *node, unsigned long arg, struct udx_dfs_msg **msg)
{
    int ret;
    struct udx_dfs_set_file_fd_para *msg_data = NULL;
    struct udx_dfs_msg *pmsg = NULL;
    void __user *argp = (void *)(uintptr_t)arg;

    if (node->file_list_vaddr) {
        bsp_dpa_rsv_cma_free(node->file_list_len, node->file_list_vaddr, node->file_list_paddr);
        node->file_list_vaddr = NULL;
        node->file_list_len = 0;
        node->file_list_paddr = 0;
    }

    struct udx_file_set_file_fd_para *file_fd_para = kzalloc(sizeof(struct udx_file_set_file_fd_para), GFP_KERNEL);
    if (file_fd_para == NULL) {
        dfs_print("Failed to allocate memory for set fd list msg header\n");
        return -ENOMEM;
    }
    ret = copy_from_user(file_fd_para, argp, sizeof(struct udx_file_set_file_fd_para));
    if (ret || file_fd_para->file_list.num > DFS_MAX_FILE_CNT) {
        kfree(file_fd_para);
        dfs_print("Failed to copy from user\n");
        return -EFAULT;
    }

    node->file_list_len = sizeof(struct udx_file_set_file_fd_para) + file_fd_para->file_list.num * sizeof(file_ctx);
    node->file_list_vaddr = bsp_dpa_rsv_cma_alloc(node->file_list_len, &node->file_list_paddr);
    if (!node->file_list_vaddr) {
        kfree(file_fd_para);
        dfs_print("Failed to alloc cma memory\n");
        return -ENOMEM;
    }

    ret = copy_from_user(node->file_list_vaddr, argp, node->file_list_len);
    if (ret) {
        dfs_print("Failed to copy from user\n");
        kfree(file_fd_para);
        return -EFAULT;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_dfs_set_file_fd_para), GFP_KERNEL);
    if (pmsg == NULL) {
        kfree(file_fd_para);
        dfs_print("Failed to allocate memory for fd list msg\n");
        return -ENOMEM;
    }

    msg_data = (struct udx_dfs_set_file_fd_para *)(pmsg->buf);
    msg_data->session_id = file_fd_para->session_id;
    msg_data->file_list_phy_addr = node->file_list_paddr;
    msg_data->file_list_len = node->file_list_len;
    dfs_print("file list num %d, file list len %lld\n", file_fd_para->file_list.num, msg_data->file_list_len);
    kfree(file_fd_para);

    print_hex_dump(KERN_ERR, "dpa: dfs_set_fd_list ", DUMP_PREFIX_NONE, 16, 1,
        node->file_list_vaddr, node->file_list_len, true);
    pmsg->header.data.len = sizeof(struct udx_dfs_set_file_fd_para);
    *msg = pmsg;
    dfs_print("msg: set fd list ok len = %ld\n", sizeof(struct udx_dfs_set_file_fd_para));

    return 0;
}

struct udx_dfs_service_ioctl_ops {
    int cmd;
    long (*func)(struct udx_dfs_task_node *, unsigned long, struct udx_dfs_msg **);
};

static struct udx_dfs_service_ioctl_ops g_udx_dfs_ioctl_ops[] = {
    { UDX_CMD_SET_INPUT_BUFFERQUEUE, udx_dfs_ioctl_set_input_bufferqueue },
    { UDX_CMD_SET_OUTPUT_BUFFERQUEUE, udx_dfs_ioctl_set_output_bufferqueue },
    { UDX_CMD_ATTACH_BUFFER, udx_dfs_ioctl_attach_buffer },
    { UDX_CMD_MAP_BUFFER, udx_dfs_ioctl_map_buffer },
    { UDX_CMD_PREPARE, udx_dfs_ioctl_prepare },
    { UDX_CMD_START, udx_dfs_ioctl_start },
    { UDX_CMD_STOP, udx_dfs_ioctl_stop },
    { UDX_CMD_RESET, udx_dfs_ioctl_reset },
    { UDX_CMD_PAUSE, udx_dfs_ioctl_pause },
    { UDX_CMD_RESUME, udx_dfs_ioctl_resume },

    { UDX_DFS_CMD_OPEN_SESSION, udx_dfs_ioctl_open_session },
    { UDX_DFS_CMD_OPEN, udx_dfs_ioctl_open },
    { UDX_DFS_CMD_CLOSE, udx_dfs_ioctl_close },
    { UDX_DFS_CMD_READ, udx_dfs_ioctl_read },
    { UDX_DFS_CMD_WRITE, udx_dfs_ioctl_write },
    { UDX_DFS_CMD_LSEEK, udx_dfs_ioctl_lseek },
    { UDX_DFS_CMD_UNLINK, udx_dfs_ioctl_unlink },
    { UDX_DFS_CMD_RENAME, udx_dfs_ioctl_rename },
    { UDX_DFS_CMD_SET_FD_LIST, udx_dfs_ioctl_set_fd_list_cma}
};

long udx_dfs_service_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    u32 i;
    long ret;
    u32 found = 0;
    struct udx_dfs_msg msg = { 0 };
    struct udx_dfs_msg *pmsg = &msg;
    struct udx_dfs_task_node *node;
    unsigned int cmd_nr = _IOC_NR(cmd);

    node = udx_dfs_get_instance(file);
    if (node == NULL) {
        dfs_print("Failed to get dfs task node\n");
        return -EBADF;
    }
    dfs_print("task id = %u, cmd %u\n", node->task_id, cmd_nr);
    for (i = 0; i < sizeof(g_udx_dfs_ioctl_ops) / sizeof(g_udx_dfs_ioctl_ops[0]); i++) {
        if (g_udx_dfs_ioctl_ops[i].cmd == cmd_nr) {
            found = 1;
            ret = g_udx_dfs_ioctl_ops[i].func(node, arg, &pmsg);
        }
    }

    if (!found) {
        dfs_print("Unsupported ioctl cmd %d\n", cmd);
        ret = -EINVAL;
        goto skip_send_msg;
    }

    if (!ret) {
        pmsg->header.type = DMI_SERVICE_TYPE_REQUEST;
        pmsg->header.dmi_id = DMI_SERVICE_FILE_SERVICE;
        pmsg->header.sub_id = (unsigned char)cmd_nr;
        pmsg->header.data.len += (sizeof(pmsg->task_id) + sizeof(pmsg->service_id));
        pmsg->task_id = node->task_id;
        pmsg->service_id = node->service_id;
        ret = bsp_dmi_client_request_comm_wake(&pmsg->header, sizeof(pmsg->header) + pmsg->header.data.len);
        if (ret) {
            dfs_print("Failed to send msg to udx dfs service, ret = %ld\n", ret);
            goto skip_send_msg;
        }
        dfs_print("ioctl ok\n");
    }

skip_send_msg:
    if (pmsg != &msg) {
        kfree(pmsg);
    }

    return ret;
}

long udx_dfs_service_ioctl_compat(struct file *file, unsigned int cmd, unsigned long arg)
{
    dfs_print("ioctl compat ok\n");
    return udx_dfs_service_ioctl(file, cmd, (unsigned long)compat_ptr(arg));
}

void *udx_dfs_service_get_instance(void *private_data)
{
    int ret;
    struct udx_dfs_task_node *node;

    node = (struct udx_dfs_task_node *)kzalloc(sizeof(*node), GFP_KERNEL);
    if (node == NULL) {
        dfs_print("Failed to allocate memory for dfs task node\n");
        return node;
    }

    INIT_LIST_HEAD(&node->dma_buf_list);
    init_waitqueue_head(&node->waitq);

    ret = kfifo_alloc(&node->msg_fifo, PAGE_SIZE, GFP_KERNEL);
    if (ret) {
        kfree(node);
        dfs_print("Failed to alloc kfifo, ret = %d\n", ret);
        return NULL;
    }

    mutex_lock(&g_udx_dfs_info.task_list_mutex);

    node->task_id = find_first_zero_bit(g_udx_dfs_info.task_id_map, UDX_DFS_TASK_NUM_MAX);
    if (node->task_id >= UDX_DFS_TASK_NUM_MAX) {
        goto err_find_task_id;
    }
    set_bit(node->task_id, g_udx_dfs_info.task_id_map);
    list_add_tail(&node->list, &g_udx_dfs_info.task_list);
    goto succeed;

err_find_task_id:
    dfs_print("Failed to find a free task id\n");
    kfifo_free(&node->msg_fifo);
    kfree(node);
    node = NULL;

succeed:
    mutex_unlock(&g_udx_dfs_info.task_list_mutex);
    dfs_print("get dfs task node\n");
    return (void *)node;
}

int udx_dfs_service_open(struct inode *inode, struct file *file)
{
    file->private_data = udx_dfs_service_get_instance(NULL);

    dfs_print("open ok\n");
    return 0;
}

int udx_dfs_send_direct_cmd(struct udx_dfs_task_node *node, int cmd)
{
    int ret;
    struct udx_dfs_msg msg = { 0 };
    msg.header.type = DMI_SERVICE_TYPE_REQUEST;
    msg.header.dmi_id = DMI_SERVICE_FILE_SERVICE;
    msg.header.sub_id = cmd;
    msg.header.data.len = (sizeof(node->task_id) + sizeof(node->service_id));
    msg.task_id = node->task_id;
    msg.service_id = node->service_id;
    ret = bsp_dmi_client_request_comm_wake(&msg.header, sizeof(msg.header) + msg.header.data.len);
    if (ret) {
        dfs_print("Failed to send free msg to udx dfs service, ret = %d\n", ret);
        return ret;
    }
    return 0;
}

int udx_dfs_service_release(struct inode *inode, struct file *file)
{
    u32 task_id;
    struct udx_dfs_task_node *node;
    struct list_head *pos, *tmp;
    struct udx_dfs_dma_buf_node *dma_buf_node;

    node = udx_dfs_get_instance(file);
    if (node == NULL) {
        dfs_print("Failed to get dfs task node\n");
        return -EBADF;
    }

    (void)udx_dfs_send_direct_cmd(node, UDX_DFS_CMD_FREE); // 通知对端释放相关资源
    task_id = node->task_id;
    dfs_print("task %u released begin\n", task_id);

    list_for_each_safe(pos, tmp, &node->dma_buf_list) {
        dma_buf_node = list_entry(pos, struct udx_dfs_dma_buf_node, list);
        dma_buf_detach(dma_buf_node->dma_buf, dma_buf_node->attachment);
        dma_buf_put(dma_buf_node->dma_buf);
        kfree(dma_buf_node);
    }

    mutex_lock(&g_udx_dfs_info.task_list_mutex);
    list_del(&node->list);
    clear_bit(node->task_id, g_udx_dfs_info.task_id_map);
    mutex_unlock(&g_udx_dfs_info.task_list_mutex);

    if (node->file_list_vaddr) {
        bsp_dpa_rsv_cma_free(node->file_list_len, node->file_list_vaddr, node->file_list_paddr);
        node->file_list_vaddr = NULL;
        node->file_list_len = 0;
        node->file_list_paddr = 0;
    }
    if (node->lba_vaddr) {
        bsp_dpa_rsv_cma_free(node->lba_len, node->lba_vaddr, node->lba_paddr);
        node->lba_vaddr = NULL;
        node->lba_len = 0;
        node->lba_paddr = 0;
    }
    kfifo_free(&node->msg_fifo);
    kfree(node);

    dfs_print("task %u released end\n", task_id);

    return 0;
}

int udx_dfs_service_config(const char *name, int value, void *private_data)
{
    return 0;
}

#define DFS_RPT_MSG_MAX_SIZE 1024
int udx_dfs_dmi_service_callback(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    int found = 0;
    struct list_head *pos, *tmp;
    struct udx_dfs_task_node *node;
    struct udx_dfs_msg_data *pmsg_data = (struct udx_dfs_msg_data *)(&msg->buf[0]);

    if (msg->len <= sizeof(struct udx_dfs_msg_data) || msg->len > DFS_RPT_MSG_MAX_SIZE) {
        dfs_print("msg len is too small %d\n", msg->len);
        return -EINVAL;
    }

    mutex_lock(&g_udx_dfs_info.task_list_mutex);

    list_for_each_safe(pos, tmp, &g_udx_dfs_info.task_list) {
        node = list_entry(pos, struct udx_dfs_task_node, list);
        if (node->task_id != pmsg_data->task_id) {
            continue;
        }
        dfs_print("task %u service_id = %u\n", node->task_id, pmsg_data->service_id);
        print_hex_dump(KERN_ERR, "dpa: service_cb", DUMP_PREFIX_OFFSET, 16, 1, msg->buf, msg->len, false);
        kfifo_in(&node->msg_fifo, pmsg_data->buf, msg->len - sizeof(struct udx_dfs_msg_data));
        wake_up_interruptible(&node->waitq);
        found = 1;
        break;
    }

    mutex_unlock(&g_udx_dfs_info.task_list_mutex);
    if (found == 0) {
        dfs_print("msg received for service_id %d but no taskid = %d found\n",
            pmsg_data->service_id, pmsg_data->task_id);
    }
    return 0;
}

static struct file_operations udx_dfs_service_fops = {
    .read = udx_dfs_service_read,
    .poll = udx_dfs_service_poll,
    .unlocked_ioctl = udx_dfs_service_ioctl,
#ifdef CONFIG_COMPAT
    .compat_ioctl = udx_dfs_service_ioctl_compat,
#endif
    .open = udx_dfs_service_open,
    .release = udx_dfs_service_release,
};

static struct udx_service_impl g_udx_dfs_service = {
    .fops = &udx_dfs_service_fops,
    .get_instance = udx_dfs_service_get_instance,
    .config = udx_dfs_service_config,
};


int dfs_send_request(dfs_sub_id id, void *info, int len)
{
    int ret;
    if (id >= DFS_FILE_SUB_ID_MAX) {
        dfs_print("dfs_send_request invalid id %d.\n", id);
        return -ENOMEM;
    }
    struct dmi_msg *msg = kzalloc(DMI_SERVICE_FILE_SERVICE, sizeof(struct dmi_msg) + len);
    if (msg == NULL) {
        dfs_print("dfs_send_request kmalloc failed\n");
        return -ENOMEM;
    }
    msg->dmi_id = DMI_SERVICE_FILE_SERVICE;
    msg->sub_id = id;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_cb.cb = (unsigned long long)NULL;
    msg->dmi_cb.cb_data = (unsigned long long)NULL;
    msg->data.len = len;
    ret = memcpy_s(msg->data.buf, len, info, len);
    if (ret != EOK) {
        dfs_print("memcpy_s failed\n");
        kfree(msg);
        return ret;
    }

    ret = bsp_dmi_client_request_comm_wake(msg, sizeof(struct dmi_msg) + len);
    if (ret) {
        kfree(msg);
        dfs_print("bsp_dmi_client_request failed %d\n", ret);
        return ret;
    }
    kfree(msg);
    dfs_print("dfs_send_request success\n");
    return 0;
}

int dfs_send_dfa_info(struct udx_dfs_msg_data *msg_data, struct dpa_fiemap_data_s *fiemap_data,
    struct dpa_ci_data_t *ci_data)
{
    int ret = 0;
    int lba_len = sizeof(struct dpa_ci_data_t) + sizeof(struct dpa_fiemap_data_t) +
        fiemap_data->fm_mapped_extents * sizeof(struct dpa_fiemap_extent_t);
    struct udx_dfs_msg *msg = kzalloc(sizeof(struct udx_dfs_msg) + lba_len, GFP_KERNEL);
    if (msg == NULL) {
        dfs_print("dfs_send_dfa_info kmalloc failed\n");
        return -ENOMEM;
    }
    msg->header.dmi_id = DMI_SERVICE_FILE_SERVICE;
    msg->header.sub_id = DFS_FILE_LBA;
    msg->header.type = DMI_SERVICE_TYPE_REQUEST;
    msg->header.dmi_cb.cb = (unsigned long long)NULL;
    msg->header.dmi_cb.cb_data = (unsigned long long)NULL;
    msg->header.data.len = lba_len + sizeof(msg->task_id) + sizeof(msg->service_id);
    msg->task_id = msg_data->task_id;
    msg->service_id = msg_data->service_id;

    struct dpa_file_info *lba_data = (struct dpa_file_info *)msg->buf;
    if (ci_data == NULL) {
        ret = memset_s(&lba_data->ci_data, sizeof(struct dpa_ci_data_t), 0, sizeof(struct dpa_ci_data_t));
        if (ret != EOK) {
            dfs_print("cidata memset_s failed ret %d\n", ret);
            kfree(msg);
            return ret;
        }
    } else {
        ret = memcpy_s(&lba_data->ci_data, sizeof(struct dpa_ci_data_t), ci_data, sizeof(struct dpa_ci_data_t));
        if (ret != EOK) {
            dfs_print("cidata memcpy_s failed ret %d\n", ret);
            kfree(msg);
            return ret;
        }
    }
    lba_data->fiemap_data.fm_mapped_extents = fiemap_data->fm_mapped_extents;
    ret = memcpy_s(&lba_data->fiemap_data.fm_extents[0],
        fiemap_data->fm_mapped_extents * sizeof(struct dpa_fiemap_extent_t),
        fiemap_data->fm_extents, fiemap_data->fm_mapped_extents * sizeof(struct dpa_fiemap_extent_t));
    if (ret != EOK) {
        dfs_print("fiemap memcpy_s failed ret %d\n", ret);
        kfree(msg);
        return ret;
    }
    print_hex_dump(KERN_ERR, "dpa: dfs_send_dfa_info ", DUMP_PREFIX_NONE, 16, 1,
        msg, sizeof(struct udx_dfs_msg) + lba_len, true);
    ret = bsp_dmi_client_request_comm_wake((struct dmi_msg *)msg, sizeof(struct udx_dfs_msg) + lba_len);
    if (ret) {
        dfs_print("bsp_dmi_client_request failed %d\n", ret);
    }
    dfs_print("dfs_send_dfa_info done with ret %d\n", ret);
    kfree(msg);
    return ret;
}

struct lba_addr_info {
    uint64_t lba_data_addr;
    uint64_t lba_data_len;
};

int dfs_prepare_cma_dfa_info(struct udx_dfs_msg *msg, struct dpa_fiemap_data_s *fiemap_data,
    struct dpa_ci_data_t *ci_data)
{
    int ret = 0;
    struct lba_addr_info *lba_info = (struct lba_addr_info *)msg->buf;
    struct udx_dfs_task_node *node = udx_dfs_get_instance_by_id(msg->task_id);
    if (node == NULL) {
        dfs_print("get dfs task node failed\n");
        return -EBADF;
    }
    if (node->lba_vaddr) {
        bsp_dpa_rsv_cma_free(node->lba_len, node->lba_vaddr, node->lba_paddr);
        node->lba_vaddr = NULL;
        node->lba_len = 0;
        node->lba_paddr = 0;
    }
    node->lba_len = sizeof(struct dpa_ci_data_t) + sizeof(struct dpa_fiemap_data_t) +
        fiemap_data->fm_mapped_extents * sizeof(struct dpa_fiemap_extent_t);
    node->lba_vaddr = bsp_dpa_rsv_cma_alloc(node->lba_len, &node->lba_paddr);
    if (!node->lba_vaddr) {
        dfs_print("Failed to alloc cma memory\n");
        return -ENOMEM;
    }
    lba_info->lba_data_addr = (uint64_t)node->lba_paddr;
    lba_info->lba_data_len = node->lba_len;

    struct dpa_file_info *lba_data = (struct dpa_file_info *)node->lba_vaddr;
    if (ci_data == NULL) {
        ret = memset_s(&lba_data->ci_data, sizeof(struct dpa_ci_data_t), 0, sizeof(struct dpa_ci_data_t));
        if (ret != EOK) {
            dfs_print("cidata memset_s failed ret %d\n", ret);
            return ret;
        }
    } else {
        ret = memcpy_s(&lba_data->ci_data, sizeof(struct dpa_ci_data_t), ci_data, sizeof(struct dpa_ci_data_t));
        if (ret != EOK) {
            dfs_print("cidata memcpy_s failed ret %d\n", ret);
            return ret;
        }
    }
    lba_data->fiemap_data.fm_mapped_extents = fiemap_data->fm_mapped_extents;
    dfs_print("dfs_send_dfa_info lba len %lld, fm_ext %d\n", lba_info->lba_data_len, fiemap_data->fm_mapped_extents);
    ret = memcpy_s(&lba_data->fiemap_data.fm_extents[0],
        fiemap_data->fm_mapped_extents * sizeof(struct dpa_fiemap_extent_t),
        fiemap_data->fm_extents, fiemap_data->fm_mapped_extents * sizeof(struct dpa_fiemap_extent_t));
    if (ret != EOK) {
        dfs_print("fiemap memcpy_s failed ret %d\n", ret);
        return ret;
    }
    print_hex_dump(KERN_ERR, "dpa: dfs_send_dfa_info ", DUMP_PREFIX_NONE, 16, 1, lba_data,
        lba_info->lba_data_len, true);
    return 0;
}

int dfs_send_dfa_info_addr(struct udx_dfs_msg_data *msg_data, struct dpa_fiemap_data_s *fiemap_data,
    struct dpa_ci_data_t *ci_data)
{
    int ret = 0;
    int lba_len = sizeof(struct lba_addr_info);
    struct udx_dfs_msg *msg = kzalloc(sizeof(struct udx_dfs_msg) + lba_len, GFP_KERNEL);
    if (msg == NULL) {
        dfs_print("dfs_send_dfa_info kmalloc failed\n");
        return -ENOMEM;
    }
    msg->header.dmi_id = DMI_SERVICE_FILE_SERVICE;
    msg->header.sub_id = DFS_FILE_LBA;
    msg->header.type = DMI_SERVICE_TYPE_REQUEST;
    msg->header.dmi_cb.cb = (unsigned long long)NULL;
    msg->header.dmi_cb.cb_data = (unsigned long long)NULL;
    msg->header.data.len = lba_len + sizeof(msg->task_id) + sizeof(msg->service_id);
    msg->task_id = msg_data->task_id;
    msg->service_id = msg_data->service_id;

    ret = dfs_prepare_cma_dfa_info(msg, fiemap_data, ci_data);
    if (ret) {
        dfs_print("dfs_prepare_cma_dfa_info failed %d\n", ret);
        kfree(msg);
        return ret;
    }

    ret = bsp_dmi_client_request_comm_wake((struct dmi_msg *)msg, sizeof(struct udx_dfs_msg) + lba_len);
    if (ret) {
        dfs_print("bsp_dmi_client_request failed %d\n", ret);
    }
    dfs_print("dfs_send_dfa_info done with ret %d\n", ret);
    kfree(msg);
    return ret;
}

int dfs_dfa_info_native_query(struct dmi_msg_data *msg, unsigned int id)
{
#ifdef DFS_SUPPORT_NATIVE_LBA_QUERY
    int ret;
    int i;
    int ops
    struct file_info *finfo = NULL;
    struct udx_dfs_msg_data *msg_data = (struct udx_dfs_msg_data *)msg->buf;
    struct file_lba_query *query_msg = (struct file_lba_query *)msg_data->buf;
    if ((msg->len < sizeof(struct file_lba_query)) || (msg->len > FILE_MAX_DFA_INFO_LEN)) {
        dfs_print("invalid msg len %d\n", msg->len);
        return -EINVAL;
    } else if (msg->len != sizeof(struct udx_dfs_msg_data) + sizeof(struct file_lba_query) +
        query_msg->query_cnt * sizeof(struct fs_single_file_info)) {
        dfs_print("invalid data len %d\n", msg->len);
        return -EINVAL;
    }
    for (i = 0; i < query_msg->query_cnt; i++) {
        dfs_print("dfs_dfa_info_query for file %s\n", query_msg->files[i].filename);
        ops = (query_msg->mode == FILE_READ_MODE) ? DFA_READ : DFA_WRITE;
        finfo = dfa_dpa_get_file_info(query_msg->files[i].filename, query_msg->files[i].size, ops);
        if (finfo == NULL || finfo->lba_info == NULL) {
            dfs_print("get dfa info failed for file %s.\n", query_msg->files[i].filename);
            break;
        }
        ret = dfs_send_dfa_info(finfo, id);
        if (ret) {
            dfs_print("dfs_send_dfa_info failed for file %s.\n", query_msg->files[i].filename);
            return ret;
        }
        destroy_file_info(finfo);
    }
#endif
    return 0;
}

#define DFS_MAX_QUERY_CNT 1
int dfs_dfa_info_query(struct dmi_msg_data *msg, unsigned int id)
{
    int ret;
    int i;
    struct dpa_ci_data_t ci_data = { 0 };
    struct dpa_fiemap_data_s fiemap_data = { 0 };
    struct udx_dfs_msg_data *msg_data = (struct udx_dfs_msg_data *)msg->buf;
    struct file_lba_query *query_msg = (struct file_lba_query *)msg_data->buf;
    if ((msg->len < sizeof(struct file_lba_query)) || (query_msg->query_cnt > DFS_MAX_QUERY_CNT)) {
        dfs_print("invalid msg len %d\n", msg->len);
        return -EINVAL;
    }
    if (msg->len != sizeof(struct udx_dfs_msg_data) + sizeof(struct file_lba_query) +
        query_msg->query_cnt * sizeof(struct fs_single_file_info)) {
        dfs_print("invalid data len %d\n", msg->len);
        return -EINVAL;
    }
    for (i = 0; i < query_msg->query_cnt; i++) {
        dfs_print("dfs_dfa_info_query for file pid: %d, size:%lld, fd:%d\n",
            query_msg->files[i].fd_info.pid, query_msg->files[i].fd_info.file_size, query_msg->files[i].fd_info.fd);
        if (query_msg->mode == FILE_READ_MODE) {
            ret = dpa_fs_ioctl_fiemap_cidata(query_msg->files[i].fd_info.fd, query_msg->files[i].fd_info.pid,
                &fiemap_data, &ci_data);
            print_hex_dump(KERN_ERR, "dpa: fs_ioctl_fiemap ", DUMP_PREFIX_NONE, 16, 1, &fiemap_data,
                sizeof(struct dpa_fiemap_data_s), true);
            print_hex_dump(KERN_ERR, "dpa: fs_ioctl_ci ", DUMP_PREFIX_NONE, 16, 1, &ci_data,
                sizeof(struct dpa_ci_data_t), true);
            dfs_print("dfs_dfa_info_query dpa_fs_ioctl_fiemap_cidata ret = %d, fiemap_data ext=%d, addr =0x%lx\n", ret,
                fiemap_data.fm_mapped_extents, (uintptr_t)fiemap_data.fm_extents);
            if (ret != 0) {
                dfs_print("dfs_dfa_info_query dpa_fs_ioctl_fiemap_cidata failed ret %d\n", ret);
                return ret;
            }
        } else if (query_msg->mode == FILE_WRITE_MODE) {
            ret = dpa_fs_fallocate_fiemap(query_msg->files[i].fd_info.fd, query_msg->files[i].fd_info.pid,
                query_msg->files[i].fd_info.file_size, &fiemap_data, &ci_data);
            print_hex_dump(KERN_ERR, "dpa: fs_ioctl_fiemap ", DUMP_PREFIX_NONE, 16, 1, &fiemap_data,
                sizeof(struct dpa_fiemap_data_s), true);
            print_hex_dump(KERN_ERR, "dpa: fs_ioctl_ci ", DUMP_PREFIX_NONE, 16, 1, &ci_data,
                sizeof(struct dpa_ci_data_t), true);
            dfs_print("dfs_dfa_info_query dpa_fs_fallocate_fiemap ret = %d, fiemap_data ext=%d, addr =0x%lx\n", ret,
                fiemap_data.fm_mapped_extents, (uintptr_t)fiemap_data.fm_extents);
            if (ret != 0) {
                dfs_print("dfs_dfa_info_query dpa_fs_fallocate_fiemap failed ret %d\n", ret);
                return ret;
            }
        } else {
            dfs_print("dfs_dfa_info_query invalid mode %d\n", query_msg->mode);
            return -EINVAL;
        }

        ret = dfs_send_dfa_info_addr(msg_data, &fiemap_data, &ci_data);
        kfree(fiemap_data.fm_extents);
        if (ret) {
            dfs_print("dfs_send_dfa_info failed for file fd %d.\n", query_msg->files[i].fd_info.fd);
            return ret;
        }
    }
    return 0;
}

static int dfs_subscribe_cb(char *priv, unsigned int id, struct dmi_msg_data *msg)
{
    int ret;
    dfs_print("%s: recv msg %d\n", __func__, id);

    switch (id) {
        case DFS_FILE_LBA: {
            ret = dfs_dfa_info_query(msg, id);
            if (ret) {
                dfs_print("dfs_dfa_info_query failed\n");
                return ret;
            }
            break;
        }
        case DFS_MESSAGE: {
            udx_dfs_dmi_service_callback(priv, id, msg);
            break;
        }
        default: {
            dfs_print("unknown callback id %d\n", id);
            break;
        }
    }
    return 0;
}

struct dmi_client g_dfs_client = {
    .dmi_id = DMI_SERVICE_FILE_SERVICE,
    .priv = (char*)&g_dfs_client,
    .service_cb = dfs_subscribe_cb,
};

static int udx_dfs_probe(struct platform_device *pdev)
{
    int ret = 0;

    g_udx_dfs_info.dev = &pdev->dev;
    dma_set_coherent_mask(g_udx_dfs_info.dev, DMA_BIT_MASK(32));

    INIT_LIST_HEAD(&g_udx_dfs_info.task_list);
    mutex_init(&g_udx_dfs_info.task_list_mutex);

    g_udx_dfs_info.task_id_map = bitmap_zalloc(UDX_DFS_TASK_NUM_MAX, GFP_KERNEL);
    if (g_udx_dfs_info.task_id_map == NULL) {
        dfs_print("Failed to alloc bitmap\n");
        ret = -ENOMEM;
        goto fail_to_alloc_bitmap;
    }

    ret = bsp_dmi_client_register(&g_dfs_client);
    if (ret) {
        dfs_print("Failed to register dmi dfs client, ret = %d\n", ret);
        goto fail_to_init_dmi_client;
    }

    ret = udx_service_register("dfs", &g_udx_dfs_service);
    if (ret) {
        dfs_print("Failed to register dfs service, ret = %d\n", ret);
        goto fail_to_init_dmi_client;
    }

    dfs_print("udx dfs init ok\n");

    return ret;

fail_to_init_dmi_client:
    bitmap_free(g_udx_dfs_info.task_id_map);

fail_to_alloc_bitmap:
    return ret;
}

static struct platform_device g_udx_dfs_device = {
    .name = "udx_dfs",
    .id = -1,
};
static struct platform_driver g_udx_dfs_driver = {
    .probe      = udx_dfs_probe,
    .driver     = {
        .name     = "udx_dfs",
        .owner    = THIS_MODULE,
        .probe_type = PROBE_FORCE_SYNCHRONOUS,
    },
};

int udx_dfs_init(void)
{
    int ret;

    ret = platform_device_register(&g_udx_dfs_device);
    if (ret) {
        dfs_print("Failed to register udx dfs device\n");
        return ret;
    }

    ret = platform_driver_register(&g_udx_dfs_driver);
    if (ret) {
        dfs_print("Failed to register udx dfs driver\n");
        platform_device_unregister(&g_udx_dfs_device);
    }

    return ret;
}
