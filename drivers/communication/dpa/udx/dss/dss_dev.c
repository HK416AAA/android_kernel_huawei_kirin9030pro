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
#include "bsp_mem_layout.h"
#include "bsp_dmi.h"
#include "bsp_rproc.h"
#include "bsp_udx.h"
#include <dpa_reset.h>
#include "dss_dev.h"
#include "../buffer/udx_buffer.h"

#undef THIS_MODU
#define THIS_MODU mod_dss

struct dss_driver_data g_dss_data;
struct udx_dss_info g_udx_dss_info;

struct udx_dss_task_node *udx_dss_get_instance(struct file *f)
{
    return (struct udx_dss_task_node *)udx_service_get_instance(f);
}

ssize_t udx_dss_service_read(struct file *file, char __user *buf, size_t count, loff_t *off)
{
    ssize_t ret;
    unsigned char c;
    struct udx_dss_task_node *node;

    node = udx_dss_get_instance(file);
    if (node == NULL) {
        dss_print("Failed to get dss task node\n");
        return -EBADF;
    }

    if ((kfifo_len(&node->msg_fifo) == 0) && (file->f_flags & O_NONBLOCK))
        return -EAGAIN;

    ret = wait_event_interruptible(node->waitq, kfifo_len(&node->msg_fifo) != 0);
    dss_print("dss reading\n");
    if (ret)
        return ret;

    while (ret < count && (kfifo_out(&node->msg_fifo, &c, sizeof(c)) == sizeof(c))) {
        if (put_user(c, buf++))
            return -EFAULT;
        ret++;
    }

    return ret;
}

__poll_t udx_dss_service_poll(struct file *file, poll_table *wait)
{
    struct udx_dss_task_node *node;

    node = udx_dss_get_instance(file);
    if (node == NULL) {
        dss_print("Failed to get dss task node\n");
        return EPOLLERR;
    }

    poll_wait(file, &node->waitq, wait);
    dss_print("trigger poll return\n");
    if (kfifo_len(&node->msg_fifo))
        return EPOLLIN | EPOLLRDNORM;

    return 0;
}

static int udx_dss_buffer_get_paddr(int fd, u64 *paddr, u32 *size, u32 offset)
{
    int ret = 0;
    u64 dma_buf_paddr = 0;
    struct dma_buf *dma_buf;

    dss_print("get dma buf paddr for fd %d\n", fd);
    dma_buf = dma_buf_get(fd);
    if (IS_ERR(dma_buf)) {
        ret = PTR_ERR(dma_buf);
        dss_print("Failed to get dma buf, err = %d\n", ret);
        return ret;
    }

    dma_buf_paddr = udx_buffer_get_dma_buf_paddr(dma_buf);
    if (dma_buf_paddr == 0) {
        ret = -EINVAL;
        dss_print("Failed to get dma buf paddr\n");
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

static long udx_dss_ioctl_set_input_bufferqueue(struct udx_dss_task_node *node, unsigned long arg,
    struct udx_dss_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dss_msg *pmsg;
    struct udx_dss_ioctl_buffer buf_info[UDX_DSS_BUFFER_NODE_NUM] = { 0 };

    if (copy_from_user(buf_info, (void *)arg, sizeof(buf_info)) != 0) {
        dss_print("Failed to copy from user\n");
        return -EFAULT;
    }

    ret = udx_dss_buffer_get_paddr(buf_info[0].dma_buffer.attr.fd, &buf_info[0].dma_buffer.phy_addr, NULL,
        buf_info[0].dma_buffer.attr.offset);
    if (ret) {
        return ret;
    }
    ret = udx_dss_buffer_get_paddr(buf_info[1].dma_buffer.attr.fd, &buf_info[1].dma_buffer.phy_addr, NULL,
        buf_info[1].dma_buffer.attr.offset);
    if (ret) {
        return ret;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(buf_info), GFP_KERNEL);
    if (pmsg == NULL) {
        dss_print("Failed to allocate memory for set in buffer msg\n");
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(buf_info);

    msg_data = (char *)(pmsg->buf);
    (void)memcpy_s(&msg_data[0], sizeof(buf_info), (void *)buf_info, sizeof(buf_info));
    dss_print("msg: input buffer 0 offset = 0x%X, size = 0x%X, type = %d\n", buf_info[0].dma_buffer.attr.offset,
        buf_info[0].len, buf_info[0].type);
    dss_print("msg: input buffer 1 offset = 0x%X, size = 0x%X, type = %d\n", buf_info[1].dma_buffer.attr.offset,
        buf_info[1].len, buf_info[1].type);

    return 0;
}

static long udx_dss_ioctl_set_output_bufferqueue(struct udx_dss_task_node *node, unsigned long arg,
    struct udx_dss_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dss_msg *pmsg;
    struct udx_dss_ioctl_buffer buf_info[UDX_DSS_BUFFER_NODE_NUM] = { 0 };

    if (copy_from_user(buf_info, (void *)arg, sizeof(buf_info)) != 0) {
        dss_print("Failed to copy from user\n");
        return -EFAULT;
    }

    ret = udx_dss_buffer_get_paddr(buf_info[0].dma_buffer.attr.fd, &buf_info[0].dma_buffer.phy_addr, NULL,
        buf_info[0].dma_buffer.attr.offset);
    if (ret) {
        return ret;
    }
    ret = udx_dss_buffer_get_paddr(buf_info[1].dma_buffer.attr.fd, &buf_info[1].dma_buffer.phy_addr, NULL,
        buf_info[1].dma_buffer.attr.offset);
    if (ret) {
        return ret;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(buf_info), GFP_KERNEL);
    if (pmsg == NULL) {
        dss_print("Failed to allocate memory for set out buffer msg\n");
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(buf_info);

    msg_data = (char *)(pmsg->buf);
    (void)memcpy_s(&msg_data[0], sizeof(buf_info), (void *)buf_info, sizeof(buf_info));
    dss_print("msg: output buffer 0 offset = 0x%X, size = 0x%X, type = %d\n", buf_info[0].dma_buffer.attr.offset,
        buf_info[0].len, buf_info[0].type);
    dss_print("msg: output buffer 1 offset = 0x%X, size = 0x%X, type = %d\n", buf_info[1].dma_buffer.attr.offset,
        buf_info[1].len, buf_info[1].type);

    return 0;
}

static long udx_dss_ioctl_attach_buffer(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    int ret;
    int buf_fd = arg;
    struct udx_dss_dma_buf_node *dma_buf_node;

    dma_buf_node = (struct udx_dss_dma_buf_node *)kzalloc(sizeof(*dma_buf_node), GFP_KERNEL);
    if (dma_buf_node == NULL) {
        dss_print("Failed to allocate memory for attach buffer msg\n");
        return -ENOMEM;
    }

    dss_print("attach buf fd = %d\n", buf_fd);
    dma_buf_node->dma_buf = dma_buf_get(buf_fd);
    if (IS_ERR(dma_buf_node->dma_buf)) {
        ret = PTR_ERR(dma_buf_node->dma_buf);
        dss_print("Failed to get dma buf, err = %d\n", ret);
        goto fail_to_get_dma_buf;
    }

    dma_buf_node->attachment = dma_buf_attach(dma_buf_node->dma_buf, g_udx_dss_info.dev);
    if (IS_ERR(dma_buf_node->attachment)) {
        ret = PTR_ERR(dma_buf_node->attachment);
        dss_print("Failed to attach dma buf, err = %d\n", ret);
        goto fail_to_attach_dma_buf;
    }

    list_add_tail(&dma_buf_node->list, &node->dma_buf_list);

    dss_print("msg: attach buffer ok\n");

    return 0;

fail_to_attach_dma_buf:
    dma_buf_put(dma_buf_node->dma_buf);

fail_to_get_dma_buf:
    kfree(dma_buf_node);

    return ret;
}

static long udx_dss_ioctl_map_buffer(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    int ret;
    struct udx_dss_ioctl_buffer_info buf_info = { 0 };
    char *msg_data = NULL;
    struct udx_dss_msg *pmsg = NULL;

    buf_info.buf_fd = arg;
    ret = udx_dss_buffer_get_paddr(buf_info.buf_fd, &buf_info.buf_addr, &buf_info.buf_size, 0);
    if (ret) {
        return ret;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(buf_info), GFP_KERNEL);
    if (pmsg == NULL) {
        dss_print("Failed to allocate memory for map buffer msg\n");
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(buf_info);

    msg_data = (char *)(pmsg->buf);
    (void)memcpy_s(&msg_data[0], sizeof(buf_info), &buf_info, sizeof(buf_info));

    dss_print("msg: map buffer ok\n");

    return 0;
}

#define UDX_DSS_WAKE_MAME_MAX 32
static long udx_dss_ioctl_open_session(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    int ret;
    char *msg_data;
    char wakesource_name[UDX_DSS_WAKE_MAME_MAX] = {0};
    struct udx_dss_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_dss_open_sesison_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dss_print("Failed to allocate memory for open session msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_dss_open_sesison_para));
    if (ret) {
        dss_print("Failed to copy from user\n");
        return -EFAULT;
    }
    dss_print("open session %d\n", ((struct udx_dss_open_sesison_para *)msg_data)->session_id);
    node->service_id = ((struct udx_dss_open_sesison_para *)msg_data)->session_id;
    pmsg->header.data.len = sizeof(struct udx_dss_open_sesison_para);
    *msg = pmsg;

    ret = snprintf_s(wakesource_name, sizeof(wakesource_name), sizeof(wakesource_name) - 1, "dss_%d", node->task_id);
    if (ret < 0) {
        dss_print("Failed to get wake source name\n");
        return -EFAULT;
    }
    dss_print("dss: open session ok\n");

    return 0;
}

static long udx_dss_ioctl_start_server(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dss_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_dss_start_server_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dss_print("Failed to allocate memory for start server msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_dss_start_server_para));
    if (ret) {
        dss_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_dss_start_server_para);
    *msg = pmsg;
    dss_print("dss: start server ok\n");
    node->server_flag = 1;

    return 0;
}

static long udx_dss_ioctl_start_client(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dss_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_dss_start_client_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dss_print("Failed to allocate memory for start client msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_dss_start_client_para));
    if (ret) {
        dss_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_dss_start_client_para);
    *msg = pmsg;
    dss_print("dss: start client ok\n");
    node->server_flag = 0;

    return 0;
}

static long udx_dss_ioctl_send_files_name(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    dss_print("dss: send files name ok\n");
    return 0;
}

static long udx_dss_ioctl_send_files_fd_cma(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    int ret;
    struct udx_dss_set_file_fd_para *msg_data;
    struct udx_dss_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;

    if (node->file_list_vaddr) {
        bsp_dpa_rsv_cma_free(node->file_list_len, node->file_list_vaddr, node->file_list_paddr);
        node->file_list_vaddr = NULL;
        node->file_list_len = 0;
        node->file_list_paddr = 0;
    }
    struct udx_dss_send_file_fd_para *file_fd_para = kzalloc(sizeof(struct udx_dss_send_file_fd_para), GFP_KERNEL);
    if (file_fd_para == NULL) {
        dss_print("Failed to allocate memory for set fd list msg header\n");
        return -ENOMEM;
    }
    ret = copy_from_user(file_fd_para, argp, sizeof(struct udx_dss_send_file_fd_para));
    if (ret || file_fd_para->file_list.num > DSS_MAX_FILE_CNT) {
        kfree(file_fd_para);
        dss_print("Failed to copy from user\n");
        return -EFAULT;
    }

    node->file_list_len = sizeof(struct udx_dss_send_file_fd_para) + file_fd_para->file_list.num * sizeof(file_ctx);
    node->file_list_vaddr = bsp_dpa_rsv_cma_alloc(node->file_list_len, &node->file_list_paddr);
    if (!node->file_list_vaddr) {
        kfree(file_fd_para);
        dss_print("Failed to alloc cma memory\n");
        return -ENOMEM;
    }
    ret = copy_from_user(node->file_list_vaddr, argp, node->file_list_len);
    if (ret) {
        dss_print("Failed to copy from user\n");
        kfree(file_fd_para);
        return -EFAULT;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_dss_set_file_fd_para), GFP_KERNEL);
    if (pmsg == NULL) {
        kfree(file_fd_para);
        dss_print("Failed to allocate memory for fd list msg\n");
        return -ENOMEM;
    }

    msg_data = (struct udx_dss_set_file_fd_para *)(pmsg->buf);
    msg_data->session_id = file_fd_para->session_id;
    msg_data->file_list_phy_addr = node->file_list_paddr;
    msg_data->file_list_len = node->file_list_len;
    kfree(file_fd_para);

    pmsg->header.data.len = sizeof(struct udx_dss_set_file_fd_para);
    *msg = pmsg;
    dss_print("msg: set fd list ok len = %lld\n", msg_data->file_list_len);

    return 0;
}

static long udx_dss_ioctl_stop_server(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dss_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_dss_stop_client_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dss_print("Failed to allocate memory for stop server msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_dss_stop_client_para));
    if (ret) {
        dss_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_dss_stop_client_para);
    *msg = pmsg;
    dss_print("dss: stop server ok\n");

    return 0;
}

static long udx_dss_ioctl_stop_client(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dss_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_dss_stop_client_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dss_print("Failed to allocate memory for stop client msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_dss_stop_client_para));
    if (ret) {
        dss_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_dss_stop_client_para);
    *msg = pmsg;
    dss_print("dss: stop client ok\n");

    return 0;
}

static long udx_dss_ioctl_close_session(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dss_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_dss_close_session_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dss_print("Failed to allocate memory for close session msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_dss_close_session_para));
    if (ret) {
        dss_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_dss_close_session_para);
    *msg = pmsg;
    dss_print("dss: close session ok\n");

    return 0;
}

static long udx_dss_ioctl_set_storage_path(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dss_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_dss_set_storage_path_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dss_print("Failed to allocate memory for set storage path msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_dss_set_storage_path_para));
    if (ret) {
        dss_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_dss_set_storage_path_para);
    *msg = pmsg;
    dss_print("dss: set storage path ok\n");

    return 0;
}

static long udx_dss_ioctl_get_capability(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_dss_msg *pmsg;
    void __user *argp = (void *)(uintptr_t)arg;
    pmsg = kzalloc(sizeof(**msg) + sizeof(struct udx_dss_get_capability_para), GFP_KERNEL);
    if (pmsg == NULL) {
        dss_print("Failed to allocate memory for get capability msg\n");
        return -ENOMEM;
    }
    msg_data = (char *)(pmsg->buf);
    ret = copy_from_user(&msg_data[0], argp, sizeof(struct udx_dss_get_capability_para));
    if (ret) {
        dss_print("Failed to copy from user\n");
        return -EFAULT;
    }
    pmsg->header.data.len = sizeof(struct udx_dss_get_capability_para);
    *msg = pmsg;
    ((struct udx_dss_get_capability_para *)msg_data)->capability = 1;
    ret = copy_to_user((void __user *)argp, msg_data, sizeof(struct udx_dss_get_capability_para));
    if (ret) {
        dss_print("Failed to copy to user\n");
        return -EFAULT;
    }
    dss_print("dss: get capability ok\n");

    return 0;
}

static long udx_dss_ioctl_get_file_frame(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    struct udx_dss_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dss_print("dss: get file frame ok\n");
    return 0;
}

static long udx_dss_ioctl_prepare(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    struct udx_dss_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dss_print("msg: prepare\n");
    return 0;
}

static long udx_dss_ioctl_start(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    struct udx_dss_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dss_print("msg: start\n");
    return 0;
}


static long udx_dss_ioctl_pause(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    struct udx_dss_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dss_print("msg: pause\n");
    return 0;
}

static long udx_dss_ioctl_resume(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    struct udx_dss_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dss_print("msg: resume\n");
    return 0;
}

static long udx_dss_ioctl_reset(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    struct udx_dss_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dss_print("msg: reset\n");
    return 0;
}

static long udx_dss_ioctl_stop(struct udx_dss_task_node *node, unsigned long arg, struct udx_dss_msg **msg)
{
    struct udx_dss_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    dss_print("msg: stop\n");
    return 0;
}

struct udx_dss_service_ioctl_ops {
    int cmd;
    long (*func)(struct udx_dss_task_node *, unsigned long, struct udx_dss_msg **);
};

static struct udx_dss_service_ioctl_ops g_udx_dss_ioctl_ops[] = {
    { UDX_CMD_SET_INPUT_BUFFERQUEUE, udx_dss_ioctl_set_input_bufferqueue },
    { UDX_CMD_SET_OUTPUT_BUFFERQUEUE, udx_dss_ioctl_set_output_bufferqueue },
    { UDX_CMD_ATTACH_BUFFER, udx_dss_ioctl_attach_buffer },
    { UDX_CMD_MAP_BUFFER, udx_dss_ioctl_map_buffer },
    { UDX_CMD_PREPARE, udx_dss_ioctl_prepare },
    { UDX_CMD_START, udx_dss_ioctl_start },
    { UDX_CMD_STOP, udx_dss_ioctl_stop },
    { UDX_CMD_RESET, udx_dss_ioctl_reset },
    { UDX_CMD_PAUSE, udx_dss_ioctl_pause },
    { UDX_CMD_RESUME, udx_dss_ioctl_resume },

    { UDX_DSS_CMD_OPEN_SESSION, udx_dss_ioctl_open_session },
    { UDX_DSS_CMD_START_SERVER, udx_dss_ioctl_start_server },
    { UDX_DSS_CMD_START_CLIENT, udx_dss_ioctl_start_client },
    { UDX_DSS_CMD_SEND_FILES_NAME, udx_dss_ioctl_send_files_name },
    { UDX_DSS_CMD_SEND_FILES_FD, udx_dss_ioctl_send_files_fd_cma },
    { UDX_DSS_CMD_STOP_SERVER, udx_dss_ioctl_stop_server },
    { UDX_DSS_CMD_STOP_CLIENT, udx_dss_ioctl_stop_client },
    { UDX_DSS_CMD_CLOSE_SESSION, udx_dss_ioctl_close_session },
    { UDX_DSS_CMD_SET_STORAGE_PATH, udx_dss_ioctl_set_storage_path},
    { UDX_DSS_CMD_GET_CAPABILITY, udx_dss_ioctl_get_capability},
    { UDX_DSS_CMD_GET_FILE_FRAME, udx_dss_ioctl_get_file_frame},
};

long udx_dss_service_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    u32 i;
    long ret;
    u32 found = 0;
    struct udx_dss_msg msg = { 0 };
    struct udx_dss_msg *pmsg = &msg;
    struct udx_dss_task_node *node;
    unsigned int cmd_nr = _IOC_NR(cmd);

    node = udx_dss_get_instance(file);
    if (node == NULL) {
        dss_print("Failed to get dss task node\n");
        return -EBADF;
    }
    dss_print("task id = %u\n", node->task_id);
    for (i = 0; i < sizeof(g_udx_dss_ioctl_ops) / sizeof(g_udx_dss_ioctl_ops[0]); i++) {
        if (g_udx_dss_ioctl_ops[i].cmd == cmd_nr) {
            found = 1;
            ret = g_udx_dss_ioctl_ops[i].func(node, arg, &pmsg);
        }
    }

    if (!found) {
        dss_print("Unsupported ioctl cmd %d\n", cmd);
        ret = -EINVAL;
        goto skip_send_msg;
    }

    if (!ret) {
        pmsg->header.type = DMI_SERVICE_TYPE_REQUEST;
        pmsg->header.dmi_id = DMI_SERVICE_DSHARE_SERVICE;
        pmsg->header.sub_id = (unsigned char)cmd_nr;
        pmsg->header.data.len += (sizeof(pmsg->task_id) + sizeof(pmsg->service_id));
        pmsg->task_id = node->task_id;
        pmsg->service_id = node->service_id;
        ret = bsp_dmi_client_request_comm_wake(&pmsg->header, sizeof(pmsg->header) + pmsg->header.data.len);
        if (ret) {
            dss_print("Failed to send msg to udx dss service, ret = %ld\n", ret);
            goto skip_send_msg;
        }
        dss_print("ioctl ok\n");
    }

skip_send_msg:
    if (pmsg != &msg) {
        kfree(pmsg);
    }

    return ret;
}

long udx_dss_service_ioctl_compat(struct file *file, unsigned int cmd, unsigned long arg)
{
    dss_print("ioctl compat ok\n");
    return udx_dss_service_ioctl(file, cmd, (unsigned long)compat_ptr(arg));
}

void *udx_dss_service_get_instance(void *private_data)
{
    int ret;
    struct udx_dss_task_node *node;

    node = (struct udx_dss_task_node *)kzalloc(sizeof(*node), GFP_KERNEL);
    if (node == NULL) {
        dss_print("Failed to allocate memory for dss task node\n");
        return node;
    }

    INIT_LIST_HEAD(&node->dma_buf_list);
    init_waitqueue_head(&node->waitq);

    ret = kfifo_alloc(&node->msg_fifo, PAGE_SIZE, GFP_KERNEL);
    if (ret) {
        kfree(node);
        dss_print("Failed to alloc kfifo, ret = %d\n", ret);
        return NULL;
    }

    mutex_lock(&g_udx_dss_info.task_list_mutex);

    node->task_id = find_first_zero_bit(g_udx_dss_info.task_id_map, UDX_DSS_TASK_NUM_MAX);
    if (node->task_id >= UDX_DSS_TASK_NUM_MAX) {
        goto err_find_task_id;
    }
    set_bit(node->task_id, g_udx_dss_info.task_id_map);
    list_add_tail(&node->list, &g_udx_dss_info.task_list);
    goto succeed;

err_find_task_id:
    dss_print("Failed to find a free task id\n");
    kfifo_free(&node->msg_fifo);
    kfree(node);
    node = NULL;

succeed:
    mutex_unlock(&g_udx_dss_info.task_list_mutex);
    dss_print("get dss task node\n");
    return (void *)node;
}

int udx_dss_service_open(struct inode *inode, struct file *file)
{
    file->private_data = udx_dss_service_get_instance(NULL);

    dss_print("open ok\n");
    return 0;
}

int udx_dss_send_direct_cmd(struct udx_dss_task_node *node, int cmd)
{
    int ret;
    struct udx_dss_msg msg = { 0 };
    msg.header.type = DMI_SERVICE_TYPE_REQUEST;
    msg.header.dmi_id = DMI_SERVICE_DSHARE_SERVICE;
    msg.header.sub_id = cmd;
    msg.header.data.len = (sizeof(node->task_id) + sizeof(node->service_id));
    msg.task_id = node->task_id;
    msg.service_id = node->service_id;
    ret = bsp_dmi_client_request_comm_wake(&msg.header, sizeof(msg.header) + msg.header.data.len);
    if (ret) {
        dss_print("Failed to send free msg to udx dss service, ret = %d\n", ret);
        return ret;
    }
    dss_print("send %d msg to udx dss service\n", cmd);
    return 0;
}

int udx_dss_service_release(struct inode *inode, struct file *file)
{
    u32 task_id;
    struct udx_dss_task_node *node;
    struct list_head *pos, *tmp;
    struct udx_dss_dma_buf_node *dma_buf_node;

    node = udx_dss_get_instance(file);
    if (node == NULL) {
        dss_print("Failed to get dss task node\n");
        return -EBADF;
    }

    udx_dss_send_direct_cmd(node, UDX_DSS_CMD_FREE); // 通知对端释放相关资源

    task_id = node->task_id;
    dss_print("task %u released begin\n", task_id);

    list_for_each_safe(pos, tmp, &node->dma_buf_list) {
        dma_buf_node = list_entry(pos, struct udx_dss_dma_buf_node, list);
        dma_buf_detach(dma_buf_node->dma_buf, dma_buf_node->attachment);
        dma_buf_put(dma_buf_node->dma_buf);
        kfree(dma_buf_node);
    }

    mutex_lock(&g_udx_dss_info.task_list_mutex);
    list_del(&node->list);
    clear_bit(node->task_id, g_udx_dss_info.task_id_map);
    mutex_unlock(&g_udx_dss_info.task_list_mutex);

    if (node->file_list_vaddr) {
        bsp_dpa_rsv_cma_free(node->file_list_len, node->file_list_vaddr, node->file_list_paddr);
        node->file_list_vaddr = NULL;
        node->file_list_len = 0;
        node->file_list_paddr = 0;
    }
    kfifo_free(&node->msg_fifo);
    kfree(node);

    dss_print("task %u released end\n", task_id);

    return 0;
}

int udx_dss_service_config(const char *name, int value, void *private_data)
{
    dss_print("service config, $%s = %d\n", name, value);

    return 0;
}

#define DSS_RPT_MSG_MAX_SIZE 1024
int udx_dss_dmi_service_callback(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    int found = 0;
    struct list_head *pos, *tmp;
    struct udx_dss_task_node *node;
    struct udx_dss_msg_data *pmsg_data = (struct udx_dss_msg_data *)(&msg->buf[0]);

    if (msg->len <= sizeof(struct udx_dss_msg_data) || msg->len > DSS_RPT_MSG_MAX_SIZE) {
        dss_print("recv msg len is invalid %d\n", msg->len);
        return -EINVAL;
    }

    mutex_lock(&g_udx_dss_info.task_list_mutex);

    list_for_each_safe(pos, tmp, &g_udx_dss_info.task_list) {
        node = list_entry(pos, struct udx_dss_task_node, list);
        if (node->task_id != pmsg_data->task_id) {
            continue;
        }
        dss_print("task %u service_id = %u\n", node->task_id, pmsg_data->service_id);
        print_hex_dump(KERN_ERR, "dpa_dss", DUMP_PREFIX_OFFSET, 16, 1, msg->buf, msg->len, false);
        kfifo_in(&node->msg_fifo, pmsg_data->buf, msg->len - sizeof(struct udx_dss_msg_data));
        wake_up_interruptible(&node->waitq);
        found = 1;
        break;
    }

    mutex_unlock(&g_udx_dss_info.task_list_mutex);
    if (found == 0) {
        dss_print("msg received for service_id %d but no taskid = %d found\n",
            pmsg_data->service_id, pmsg_data->task_id);
    }

    return 0;
}

static struct file_operations udx_dss_service_fops = {
    .read = udx_dss_service_read,
    .poll = udx_dss_service_poll,
    .unlocked_ioctl = udx_dss_service_ioctl,
#ifdef CONFIG_COMPAT
    .compat_ioctl = udx_dss_service_ioctl_compat,
#endif
    .open = udx_dss_service_open,
    .release = udx_dss_service_release,
};

static struct udx_service_impl g_udx_dss_service = {
    .fops = &udx_dss_service_fops,
    .get_instance = udx_dss_service_get_instance,
    .config = udx_dss_service_config,
};


int dss_send_request(dss_sub_id id, void *info, int len)
{
    int ret;
    if (id >= DSS_SUB_ID_MAX) {
        dss_print("dss_send_request invalid id %d.\n", id);
        return -ENOMEM;
    }
    struct dmi_msg *msg = kzalloc(DMI_SERVICE_DSHARE_SERVICE, sizeof(struct dmi_msg) + len);
    if (msg == NULL) {
        dss_print("dss_send_request kmalloc failed\n");
        return -ENOMEM;
    }
    msg->dmi_id = DMI_SERVICE_DSHARE_SERVICE;
    msg->sub_id = id;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_cb.cb = (unsigned long long)NULL;
    msg->dmi_cb.cb_data = (unsigned long long)NULL;
    msg->data.len = len;
    ret = memcpy_s(msg->data.buf, len, info, len);
    if (ret != EOK) {
        dss_print("memcpy_s failed\n");
        kfree(msg);
        return ret;
    }

    ret = bsp_dmi_client_request_comm_wake(msg, sizeof(struct dmi_msg) + len);
    if (ret) {
        kfree(msg);
        dss_print("bsp_dmi_client_request failed %d\n", ret);
        return ret;
    }
    kfree(msg);
    dss_print("dss_send_request success\n");
    return 0;
}

static int dss_subscribe_cb(char *priv, unsigned int id, struct dmi_msg_data *msg)
{
    dss_print("%s: recv msg %d\n", __func__, id);

    switch (id) {
        case DSS_MESSAGE: {
            udx_dss_dmi_service_callback(priv, id, msg);
            break;
        }
        default: {
            dss_print("unknown callback id %d\n", id);
            break;
        }
    }
    return 0;
}

struct dmi_client g_dss_client = {
    .dmi_id = DMI_SERVICE_DSHARE_SERVICE,
    .priv = (char*)&g_dss_client,
    .service_cb = dss_subscribe_cb,
};

int dss_report_dpa_reset(void)
{
    struct list_head *pos, *tmp;
    struct udx_dss_task_node *node = NULL;
    udx_dss_report_msg report_info = { 0 };
    report_info.filter_header.msg_size = sizeof(udx_dss_report_msg_data) + sizeof(struct filter_msg_header);
    report_info.filter_header.msg_type = UDX_DSS_MSG_TYPE_REPORT;
    mutex_lock(&g_udx_dss_info.task_list_mutex);
    list_for_each_safe(pos, tmp, &g_udx_dss_info.task_list) {
        node = list_entry(pos, struct udx_dss_task_node, list);
        if (node->server_flag == 1) {
            report_info.dss_msg_type = UDX_TRANS_MSG_FILE_RECEIVE_FAIL;
        } else {
            report_info.dss_msg_type = UDX_TRANS_MSG_FILE_SEND_FAIL;
        }
        report_info.trans_id = node->task_id;
        report_info.error_code = UDX_DSS_DPA_RESET_ERR;
        kfifo_in(&node->msg_fifo, &report_info, sizeof(report_info));
        wake_up_interruptible(&node->waitq);
    }
    mutex_unlock(&g_udx_dss_info.task_list_mutex);
    dss_print("dss_report_dpa_reset done\n");
    return 0;
}

int udx_dss_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    switch (enparam) {
        case DPA_RESET_BEFORE:
            dss_report_dpa_reset(); // 通知应用
            break;
        case DPA_RESET_AFTER:
            break;
        default:
            break;
    }
    return 0;
}

static int udx_dss_probe(struct platform_device *pdev)
{
    int ret = 0;

    g_udx_dss_info.dev = &pdev->dev;
    dma_set_coherent_mask(g_udx_dss_info.dev, DMA_BIT_MASK(32));

    INIT_LIST_HEAD(&g_udx_dss_info.task_list);
    mutex_init(&g_udx_dss_info.task_list_mutex);

    g_udx_dss_info.task_id_map = bitmap_zalloc(UDX_DSS_TASK_NUM_MAX, GFP_KERNEL);
    if (g_udx_dss_info.task_id_map == NULL) {
        dss_print("Failed to alloc bitmap\n");
        ret = -ENOMEM;
        goto fail_to_alloc_bitmap;
    }

    ret = bsp_dmi_client_register(&g_dss_client);
    if (ret) {
        dss_print("Failed to register dmi dss client, ret = %d\n", ret);
        goto fail_to_init_dmi_client;
    }

    ret = udx_service_register("dss", &g_udx_dss_service);
    if (ret) {
        dss_print("Failed to register dss service, ret = %d\n", ret);
        goto fail_to_init_dmi_client;
    }

    if (bsp_dpa_reset_register_cb("dss_reset", udx_dss_reset_cb, 0, DPA_RESET_CB_LEVEL_COMMON)) {
        dss_print("dss reset register failed\n");
        goto fail_to_init_dmi_client;
    }

    dss_print("udx dss init ok\n");

    return ret;

fail_to_init_dmi_client:
    bitmap_free(g_udx_dss_info.task_id_map);

fail_to_alloc_bitmap:
    return ret;
}

static struct platform_device g_udx_dss_device = {
    .name = "udx_dss",
    .id = -1,
};
static struct platform_driver g_udx_dss_driver = {
    .probe      = udx_dss_probe,
    .driver     = {
        .name     = "udx_dss",
        .owner    = THIS_MODULE,
        .probe_type = PROBE_FORCE_SYNCHRONOUS,
    },
};

int udx_dss_init(void)
{
    int ret;

    ret = platform_device_register(&g_udx_dss_device);
    if (ret) {
        dss_print("Failed to register udx dss device\n");
        return ret;
    }

    ret = platform_driver_register(&g_udx_dss_driver);
    if (ret) {
        dss_print("Failed to register udx dss driver\n");
        platform_device_unregister(&g_udx_dss_device);
    }

    return ret;
}
