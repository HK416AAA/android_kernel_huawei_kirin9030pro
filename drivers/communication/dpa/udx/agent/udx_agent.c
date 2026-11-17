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
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/cdev.h>
#include <linux/poll.h>
#include <linux/slab.h>
#include <linux/sysfs.h>
#include <linux/bitmap.h>
#include <linux/compat.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/kobject.h>
#include <linux/workqueue.h>
#include <linux/pm_wakeup.h>
#include <linux/dma-mapping.h>
#include <linux/platform_device.h>

#include <securec.h>

#include "udx_agent.h"

struct list_head    g_udx_agent_list;
struct mutex        g_udx_agent_list_mutex;
static int          g_udx_agent_dev_enable = 0;
struct udx_agent_work_info g_udx_agent_dmi_cb_work[UDX_AGENT_ID_MAX];

static struct platform_device g_udx_agent_device = {
    .name = "udx_agent",
    .id = -1,
};

__attribute__((weak)) long long udx_buffer_get_dma_buf_paddr(struct dma_buf *dmabuf)
{
    udx_agent_print("Warnning: stub function for %s\n", __FUNCTION__);
    return 0;
}

struct udx_agent_task_node *udx_get_instance(struct file *f)
{
    if (g_udx_agent_dev_enable) {
        return (struct udx_agent_task_node *)f->private_data;
    } else {
        return (struct udx_agent_task_node *)udx_service_get_instance(f);
    }
}

ssize_t udx_agent_fops_read(struct file *file, char __user *buf, size_t count, loff_t *off)
{
    ssize_t ret;
    unsigned char c;
    struct udx_agent_task_node *node;

    node = udx_get_instance(file);
    if (node == NULL) {
        udx_agent_print("Failed to get task node\n");
        return -EBADF;
    }

    if ((kfifo_len(&node->msg_fifo) == 0) && (file->f_flags & O_NONBLOCK))
        return -EAGAIN;

    ret = wait_event_interruptible(node->msg_fifo_waitq, kfifo_len(&node->msg_fifo) != 0);
    if (ret)
        return ret;

    while (ret < count && (kfifo_out(&node->msg_fifo, &c, sizeof(c)) == sizeof(c))) {
        if (put_user(c, buf++))
            return -EFAULT;
        ret++;
    }

    udx_agent_print("agent %s: task %d read %zd bytes ok\n", AGENT_NAME(node), node->task_id, ret);

    return ret;
}

ssize_t udx_agent_fops_write(struct file *file, const char __user *buf, size_t count, loff_t *off)
{
    struct udx_agent_task_node *node;

    node = udx_get_instance(file);
    if (node == NULL) {
        udx_agent_print("Failed to get task node\n");
        return -EBADF;
    }

    return count;
}

__poll_t udx_agent_fops_poll(struct file *file, poll_table *wait)
{
    struct udx_agent_task_node *node;

    node = udx_get_instance(file);
    if (node == NULL) {
        udx_agent_print("Failed to get task node\n");
        return EPOLLERR;
    }

    poll_wait(file, &node->msg_fifo_waitq, wait);
    if (kfifo_len(&node->msg_fifo))
        return EPOLLIN | EPOLLRDNORM;

    return 0;
}

loff_t udx_agent_fops_seek(struct file *file, loff_t offset, int whence)
{
    struct udx_agent_task_node *node;

    node = udx_get_instance(file);
    if (node == NULL) {
        udx_agent_print("Failed to get task node\n");
        return -EBADF;
    }

    udx_agent_print("agent %s: seek unsupported\n", AGENT_NAME(node));
    return no_llseek(file, offset, whence);
}

struct udx_agent_buf_node *udx_agent_buffer_get(struct udx_agent_task_node *node, int fd)
{
    struct udx_agent_buf_node *ret = NULL;

    struct list_head *pos, *tmp;
    struct udx_agent_buf_node *dma_buf_node;

    mutex_lock(&node->dma_buf_list_mutex);
    list_for_each_safe(pos, tmp, &node->dma_buf_list) {
        dma_buf_node = list_entry(pos, struct udx_agent_buf_node, list);
        if (dma_buf_node->buf_fd == fd) {
            ret = dma_buf_node;
            break;
        }
    }
    mutex_unlock(&node->dma_buf_list_mutex);

    return ret;
}

static int udx_agent_buffer_get_paddr(int fd, u64 *paddr, u32 *size, u32 offset)
{
    int ret = 0;
    u64 dma_buf_paddr = 0;
    struct dma_buf *dma_buf;

    dma_buf = dma_buf_get(fd);
    if (IS_ERR(dma_buf)) {
        ret = PTR_ERR(dma_buf);
        udx_agent_print("Failed to get dma buf, fd = %d, err = %d\n", fd, ret);
        return ret;
    }

    dma_buf_paddr = udx_buffer_get_dma_buf_paddr(dma_buf);
    if (dma_buf_paddr == 0) {
        ret = -EINVAL;
        udx_agent_print("Failed to get dma buf paddr\n");
        goto err_get_dma_buf_paddr;
    }

    if (offset >= dma_buf->size) {
        ret = -EINVAL;
        udx_agent_print("offset is invalid, offset = %u, dma_buf size = %zu\n", offset, dma_buf->size);
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

static long udx_agent_ioctl_set_bufferqueue(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_agent_msg *pmsg;
    u32 size[UDX_AGENT_BUFFERQUEUE_NODE_NUM] = { 0 };
    struct udx_agent_ioctl_bufferqueue_info buf_info[UDX_AGENT_BUFFERQUEUE_NODE_NUM] = { 0 };

    if (copy_from_user((void *)buf_info, (void *)arg, sizeof(buf_info)) != 0) {
        udx_agent_print("agent %s: Failed to copy from user\n", AGENT_NAME(node));
        return -EFAULT;
    }

    ret = udx_agent_buffer_get_paddr(buf_info[0].dma_buffer.attr.fd, &buf_info[0].dma_buffer.phy_addr,
        &size[0], buf_info[0].dma_buffer.attr.offset);
    if (ret || (buf_info[0].len > size[0]) || (buf_info[0].len + buf_info[0].dma_buffer.attr.offset > size[0])) {
        return ret;
    }
    ret = udx_agent_buffer_get_paddr(buf_info[1].dma_buffer.attr.fd, &buf_info[1].dma_buffer.phy_addr,
        &size[1], buf_info[1].dma_buffer.attr.offset);
    if (ret || (buf_info[1].len > size[1]) || (buf_info[1].len + buf_info[1].dma_buffer.attr.offset > size[1])) {
        return ret;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(buf_info), GFP_KERNEL);
    if (pmsg == NULL) {
        udx_agent_print("agent %s: Failed to allocate memory for set buffer msg\n", AGENT_NAME(node));
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(buf_info);

    msg_data = (char *)(pmsg->data.buf);
    (void)memcpy_s(&msg_data[0], sizeof(buf_info), (void *)buf_info, sizeof(buf_info));
    udx_agent_print("agent %s: task %u, msg: bufferqueue 0 offset = 0x%X, size = 0x%X, type = %d\n",
        AGENT_NAME(node), node->task_id, buf_info[0].dma_buffer.attr.offset, buf_info[0].len, buf_info[0].type);
    udx_agent_print("agent %s: task %u, msg: bufferqueue 1 offset = 0x%X, size = 0x%X, type = %d\n",
        AGENT_NAME(node), node->task_id, buf_info[1].dma_buffer.attr.offset, buf_info[1].len, buf_info[1].type);

    return 0;
}

static long udx_agent_ioctl_attach_buffer(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    int ret = 0;
    struct udx_agent_buf_node *dma_buf_node;

    dma_buf_node = (struct udx_agent_buf_node *)kzalloc(sizeof(*dma_buf_node), GFP_KERNEL);
    if (dma_buf_node == NULL) {
        udx_agent_print("agent %s: Failed to allocate memory for attach buffer msg\n", AGENT_NAME(node));
        return -ENOMEM;
    }
    dma_buf_node->buf_fd = arg;

    dma_buf_node->dma_buf = dma_buf_get(dma_buf_node->buf_fd);
    if (IS_ERR(dma_buf_node->dma_buf)) {
        ret = PTR_ERR(dma_buf_node->dma_buf);
        udx_agent_print("agent %s: Failed to get dma buf, fd = %u, err = %d\n",
            AGENT_NAME(node), dma_buf_node->buf_fd, ret);
        goto fail_to_get_dma_buf;
    }

    dma_buf_node->attachment = dma_buf_attach(dma_buf_node->dma_buf, node->agent_info->dev);
    if (IS_ERR(dma_buf_node->attachment)) {
        ret = PTR_ERR(dma_buf_node->attachment);
        udx_agent_print("agent %s: Failed to attach dma buf, err = %d\n", AGENT_NAME(node), ret);
        goto fail_to_attach_dma_buf;
    }

    mutex_lock(&node->dma_buf_list_mutex);
    list_add_tail(&dma_buf_node->list, &node->dma_buf_list);
    mutex_unlock(&node->dma_buf_list_mutex);

    udx_agent_print("agent %s: task %u, msg: attach buffer ok\n", AGENT_NAME(node), node->task_id);

    return 0;

fail_to_attach_dma_buf:
    dma_buf_put(dma_buf_node->dma_buf);

fail_to_get_dma_buf:
    kfree(dma_buf_node);

    return ret;
}

static long udx_agent_ioctl_map_buffer(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_agent_msg *pmsg;
    struct udx_agent_buf_node *dma_buf_node;
    struct udx_agent_bufmap_msg buf_msg = { 0 };
    struct udx_agent_ioctl_bufmap_info bufmap_info = { 0 };

    if (copy_from_user((void *)&bufmap_info, (void *)arg, sizeof(bufmap_info)) != 0) {
        udx_agent_print("agent %s: Failed to copy from user\n", AGENT_NAME(node));
        return -EFAULT;
    }
    buf_msg.buf_fd = bufmap_info.buf_fd;
    buf_msg.buf_id = bufmap_info.buf_id;
    buf_msg.bufqueue_id = bufmap_info.bufqueue_id;

    ret = udx_agent_buffer_get_paddr(buf_msg.buf_fd, &buf_msg.buf_addr, &buf_msg.buf_size, 0);
    if (ret) {
        return ret;
    }

    dma_buf_node = udx_agent_buffer_get(node, buf_msg.buf_fd);
    if (!dma_buf_node) {
        udx_agent_print("agent %s: Failed to get buffer id\n", AGENT_NAME(node));
        return -EBADF;
    }
    dma_buf_node->buf_id = buf_msg.buf_id;
    dma_buf_node->bufqueue_id = buf_msg.bufqueue_id;

    pmsg = kzalloc(sizeof(**msg) + sizeof(buf_msg), GFP_KERNEL);
    if (pmsg == NULL) {
        udx_agent_print("agent %s: Failed to allocate memory for map buffer msg\n", AGENT_NAME(node));
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(buf_msg);

    msg_data = (char *)(pmsg->data.buf);
    (void)memcpy_s(&msg_data[0], sizeof(buf_msg), &buf_msg, sizeof(buf_msg));
    udx_agent_print("agent %s: task %u, buf_id = %u, msg: map buffer ok\n",
        AGENT_NAME(node), node->task_id, buf_msg.buf_id);

    return 0;
}

static long udx_agent_ioctl_prepare(struct udx_agent_task_node *node, unsigned long arg, struct udx_agent_msg **msg)
{
    struct udx_agent_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    udx_agent_print("agent %s: task %u, msg: prepare\n", AGENT_NAME(node), node->task_id);
    return 0;
}

static long udx_agent_ioctl_start(struct udx_agent_task_node *node, unsigned long arg, struct udx_agent_msg **msg)
{
    struct udx_agent_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    udx_agent_print("agent %s: task %u, msg: start\n", AGENT_NAME(node), node->task_id);
    return 0;
}

static long udx_agent_ioctl_stop(struct udx_agent_task_node *node, unsigned long arg, struct udx_agent_msg **msg)
{
    struct udx_agent_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    udx_agent_print("agent %s: task %u, msg: stop\n", AGENT_NAME(node), node->task_id);
    return 0;
}

static long udx_agent_ioctl_reset(struct udx_agent_task_node *node, unsigned long arg, struct udx_agent_msg **msg)
{
    struct udx_agent_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    udx_agent_print("agent %s: task %u, msg: reset\n", AGENT_NAME(node), node->task_id);
    return 0;
}

static long udx_agent_ioctl_pause(struct udx_agent_task_node *node, unsigned long arg, struct udx_agent_msg **msg)
{
    struct udx_agent_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    udx_agent_print("agent %s: task %u, msg: pause\n", AGENT_NAME(node), node->task_id);
    return 0;
}

static long udx_agent_ioctl_resume(struct udx_agent_task_node *node, unsigned long arg, struct udx_agent_msg **msg)
{
    struct udx_agent_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    udx_agent_print("agent %s: task %u, msg: resume\n", AGENT_NAME(node), node->task_id);
    return 0;
}

static long udx_agent_ioctl_set_send_msg_buffer(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    int ret;
    char *msg_data;
    struct udx_agent_msg *pmsg;
    struct udx_agent_bufmap_msg buf_msg = { 0 };

    buf_msg.buf_fd = arg;

    ret = udx_agent_buffer_get_paddr(buf_msg.buf_fd, &buf_msg.buf_addr, &buf_msg.buf_size, 0);
    if (ret) {
        return ret;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(buf_msg), GFP_KERNEL);
    if (pmsg == NULL) {
        udx_agent_print("agent %s: Failed to allocate memory for send msg buffer\n", AGENT_NAME(node));
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(buf_msg);

    msg_data = (char *)(pmsg->data.buf);
    (void)memcpy_s(&msg_data[0], sizeof(buf_msg), &buf_msg, sizeof(buf_msg));
    udx_agent_print("agent %s: task %u, buf_id = %u, msg: set send msg buffer ok\n",
        AGENT_NAME(node), node->task_id, buf_msg.buf_id);

    node->send_msg_buf_size = buf_msg.buf_size;

    return 0;
}

static long udx_agent_ioctl_send_msg(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    struct udx_agent_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    udx_agent_print("agent %s: task %u, msg: send msg\n", AGENT_NAME(node), node->task_id);
    return 0;
}

static long udx_http_ioctl_set_str_arg(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg, const char *cmd, int max_len)
{
    long ret = 0;
    char *str;
    int str_len;
    char *msg_data;
    struct udx_agent_msg *pmsg;

    str = strndup_user((const char __user *)arg, max_len);
    if (IS_ERR(str)) {
        udx_agent_print("agent %s: Failed to copy url from user, ret = %ld\n", AGENT_NAME(node), PTR_ERR(str));
        return PTR_ERR(str);
    }

    str_len = strnlen(str, max_len);
    if (str_len <= 0 || str_len >= max_len) {
        udx_agent_print("agent %s: Invalid %s len, len = %d\n", AGENT_NAME(node), cmd, str_len);
        ret = -EINVAL;
        goto free_str;
    }

    pmsg = kzalloc(sizeof(**msg) + str_len + 1, GFP_KERNEL);
    if (pmsg == NULL) {
        udx_agent_print("agent %s: Failed to allocate memory for set buffer msg\n", AGENT_NAME(node));
        ret = -ENOMEM;
        goto free_str;
    }
    *msg = pmsg;
    pmsg->header.data.len = str_len + 1;

    msg_data = (char *)(pmsg->data.buf);
    (void)memcpy_s(&msg_data[0], str_len + 1, str, str_len + 1);
    udx_agent_print("agent %s: task %u, msg: %s = %s\n", AGENT_NAME(node), node->task_id, cmd, str);

free_str:
    kfree(str);

    return ret;
}

static long udx_http_ioctl_get_stream_id(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    int ret;
    ret = put_user(node->stream_id, (unsigned long __user *)arg);
    udx_agent_print("task %u, msg: stream id = %d\n", node->task_id, node->stream_id);
    return ret;
}

static long udx_http_ioctl_set_url(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    return udx_http_ioctl_set_str_arg(node, arg, msg, "url", UDX_HTTP_URL_MAX_LEN);
}

static long udx_http_ioctl_set_method(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    u32 method = (u32)arg;

    char *msg_data;
    struct udx_agent_msg *pmsg;

    pmsg = kzalloc(sizeof(**msg) + sizeof(method), GFP_KERNEL);
    if (pmsg == NULL) {
        udx_agent_print("Failed to allocate memory for set buffer msg\n");
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(method);

    msg_data = (char *)(pmsg->data.buf);
    (void)memcpy_s(&msg_data[0], sizeof(method), &method, sizeof(method));
    udx_agent_print("task %u, msg: method = %u\n", node->task_id, method);

    return 0;
}

static long udx_http_ioctl_set_header(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    return udx_http_ioctl_set_str_arg(node, arg, msg, "header", UDX_HTTP_HEADER_MAX_LEN);
}

static long udx_http_ioctl_set_post_data(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    return udx_http_ioctl_set_str_arg(node, arg, msg, "post data", UDX_HTTP_POST_DATA_MAX_LEN);
}

static long udx_http_ioctl_set_timeout_ms(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    u32 timeout_ms = (u32)arg;

    char *msg_data;
    struct udx_agent_msg *pmsg;

    pmsg = kzalloc(sizeof(**msg) + sizeof(timeout_ms), GFP_KERNEL);
    if (pmsg == NULL) {
        udx_agent_print("Failed to allocate memory for set buffer msg\n");
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(timeout_ms);

    msg_data = (char *)(pmsg->data.buf);
    (void)memcpy_s(&msg_data[0], sizeof(timeout_ms), &timeout_ms, sizeof(timeout_ms));
    udx_agent_print("task %u, msg: timeout_ms = %u\n", node->task_id, timeout_ms);

    return 0;
}

static long udx_http_ioctl_seek(struct udx_agent_task_node *node, unsigned long arg, struct udx_agent_msg **msg)
{
    u64 offset = arg;

    char *msg_data;
    struct udx_agent_msg *pmsg;

    pmsg = kzalloc(sizeof(**msg) + sizeof(offset), GFP_KERNEL);
    if (pmsg == NULL) {
        udx_agent_print("Failed to allocate memory for set buffer msg\n");
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(offset);

    msg_data = (char *)(pmsg->data.buf);
    (void)memcpy_s(&msg_data[0], sizeof(offset), &offset, sizeof(offset));
    udx_agent_print("task %u, msg: offset = %llu\n", node->task_id, offset);

    return 0;
}

static long udx_http_ioctl_set_range(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    char *msg_data;
    struct udx_agent_msg *pmsg;
    struct udx_http_ioctl_range range_info = { 0 };

    if (copy_from_user((void *)&range_info, (void *)arg, sizeof(range_info)) != 0) {
        udx_agent_print("Failed to copy from user\n");
        return -EFAULT;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(range_info), GFP_KERNEL);
    if (pmsg == NULL) {
        udx_agent_print("Failed to allocate memory for set buffer msg\n");
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(range_info);

    msg_data = (char *)(pmsg->data.buf);
    (void)memcpy_s(&msg_data[0], sizeof(range_info), (void *)&range_info, sizeof(range_info));
    udx_agent_print("task %u, msg: set range, offset = 0x%llX, length = 0x%llX\n",
        node->task_id, range_info.offset, range_info.length);

    return 0;
}

static long udx_http_ioctl_set_report_policy(struct udx_agent_task_node *node, unsigned long arg,
    struct udx_agent_msg **msg)
{
    char *msg_data;
    struct udx_agent_msg *pmsg;
    struct udx_http_ioctl_report_policy policy_info = { 0 };

    if (copy_from_user((void *)&policy_info, (void *)arg, sizeof(policy_info)) != 0) {
        udx_agent_print("Failed to copy from user\n");
        return -EFAULT;
    }

    pmsg = kzalloc(sizeof(**msg) + sizeof(policy_info), GFP_KERNEL);
    if (pmsg == NULL) {
        udx_agent_print("Failed to allocate memory for set buffer msg\n");
        return -ENOMEM;
    }
    *msg = pmsg;
    pmsg->header.data.len = sizeof(policy_info);

    msg_data = (char *)(pmsg->data.buf);
    (void)memcpy_s(&msg_data[0], sizeof(policy_info), (void *)&policy_info, sizeof(policy_info));
    udx_agent_print("task %u, msg: set policy info, interval_ms = 0x%X, data_length = 0x%X\n",
        node->task_id, policy_info.interval_ms, policy_info.data_length);

    return 0;
}

static long udx_agent_ioctl_init(struct udx_agent_task_node *node, unsigned long arg, struct udx_agent_msg **msg)
{
    struct udx_agent_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    udx_agent_print("agent %s: task %u, msg: init\n", AGENT_NAME(node), node->task_id);
    return 0;
}

static long udx_agent_ioctl_free(struct udx_agent_task_node *node, unsigned long arg, struct udx_agent_msg **msg)
{
    struct udx_agent_msg *pmsg = *msg;
    pmsg->header.data.len = 0;
    udx_agent_print("agent %s: task %u, msg: free\n", AGENT_NAME(node), node->task_id);
    return 0;
}

static struct udx_agent_ioctl_ops g_udx_agent_ioctl_ops[] = {
    { UDX_AGENT_CMD_SET_INPUT_BUFFERQUEUE, 1, udx_agent_ioctl_set_bufferqueue },
    { UDX_AGENT_CMD_SET_OUTPUT_BUFFERQUEUE, 1, udx_agent_ioctl_set_bufferqueue },
    { UDX_AGENT_CMD_ATTACH_BUFFER, 1, udx_agent_ioctl_attach_buffer },
    { UDX_AGENT_CMD_MAP_BUFFER, 1, udx_agent_ioctl_map_buffer },
    { UDX_AGENT_CMD_PREPARE, 1, udx_agent_ioctl_prepare },
    { UDX_AGENT_CMD_START, 1, udx_agent_ioctl_start },
    { UDX_AGENT_CMD_STOP, 1, udx_agent_ioctl_stop },
    { UDX_AGENT_CMD_RESET, 1, udx_agent_ioctl_reset },
    { UDX_AGENT_CMD_PAUSE, 1, udx_agent_ioctl_pause },
    { UDX_AGENT_CMD_RESUME, 1, udx_agent_ioctl_resume },

    { UDX_AGENT_CMD_SET_SEND_MSG_BUFFER, 1, udx_agent_ioctl_set_send_msg_buffer },
    { UDX_AGENT_CMD_SEND_MSG, 1, udx_agent_ioctl_send_msg },

    { UDX_HTTP_CMD_GET_STREAM_ID, 0, udx_http_ioctl_get_stream_id },
    { UDX_HTTP_CMD_SET_URL, 1, udx_http_ioctl_set_url },
    { UDX_HTTP_CMD_SET_METHOD, 1, udx_http_ioctl_set_method },
    { UDX_HTTP_CMD_SET_HEADER, 1, udx_http_ioctl_set_header },
    { UDX_HTTP_CMD_SET_POST_DATA, 1, udx_http_ioctl_set_post_data },
    { UDX_HTTP_CMD_SET_CONNECTTIMEOUT_MS, 1, udx_http_ioctl_set_timeout_ms },
    { UDX_HTTP_CMD_SEEK, 1, udx_http_ioctl_seek },
    { UDX_HTTP_CMD_SET_RANGE, 1, udx_http_ioctl_set_range },
    { UDX_HTTP_CMD_SET_REPORT_POLICY, 1, udx_http_ioctl_set_report_policy },
};
static struct udx_agent_ioctl_ops g_udx_agent_ioctl_inner_ops[] = {
    { UDX_AGENT_CMD_INIT, 1, udx_agent_ioctl_init },
    { UDX_AGENT_CMD_FREE, 1, udx_agent_ioctl_free },
};

int udx_http_send_msg_sync(struct udx_agent_msg *pmsg, u32 cmd, struct udx_agent_task_node *node)
{
    int ret;

    pmsg->header.type   = DMI_SERVICE_TYPE_REQUEST;
    pmsg->header.dmi_id = DMI_SERVICE_UDX_AGENT;
    pmsg->header.sub_id = 0;
    pmsg->header.data.len += sizeof(struct udx_agent_msg_data);

    pmsg->data.agent_id     = node->agent_info->agent.id;
    pmsg->data.task_id      = node->task_id;
    pmsg->data.ioctl_cmd    = cmd;

    mutex_lock(&node->ioctl_mutex);

    sema_init(&node->ioctl_ack_sem, 0);

    ret = bsp_dmi_client_request_comm_wake(&pmsg->header, sizeof(pmsg->header) + pmsg->header.data.len);
    if (ret) {
        udx_agent_print("agent %s: Failed to send msg to udx service, ret = %d\n", AGENT_NAME(node), ret);
        mutex_unlock(&node->ioctl_mutex);
        return ret;
    }

    ret = down_interruptible(&node->ioctl_ack_sem);
    if (ret) {
        udx_agent_print("agent %s: Failed to wait ack, ret = %d\n", AGENT_NAME(node), ret);
    } else {
        ret = node->ioctl_ack_status;
    }

    mutex_unlock(&node->ioctl_mutex);

    return ret;
}

long udx_agent_do_ioctl(struct udx_agent_task_node *node, unsigned int cmd, unsigned long arg, int inner_enable)
{
    long ret;

    u32 i;
    struct udx_agent_msg msg = { 0 };
    struct udx_agent_msg *pmsg = &msg;
    unsigned int cmd_nr = _IOC_NR(cmd);
    struct udx_agent_ioctl_ops *ops = NULL;

    for (i = 0; i < sizeof(g_udx_agent_ioctl_ops) / sizeof(g_udx_agent_ioctl_ops[0]); i++) {
        if (g_udx_agent_ioctl_ops[i].cmd == cmd_nr) {
            ops = &g_udx_agent_ioctl_ops[i];
            break;
        }
    }
    for (i = 0; i < sizeof(g_udx_agent_ioctl_inner_ops) / sizeof(g_udx_agent_ioctl_inner_ops[0]); i++) {
        if (inner_enable && g_udx_agent_ioctl_inner_ops[i].cmd == cmd_nr) {
            ops = &g_udx_agent_ioctl_inner_ops[i];
            break;
        }
    }

    if (!ops) {
        udx_agent_print("Unsupported ioctl cmd %d, cmd_nr = %d\n", cmd, cmd_nr);
        ret = -EINVAL;
        goto skip_send_msg;
    }

    ret = ops->func(node, arg, &pmsg);
    if (!ret && ops->need_send_msg) {
        ret = udx_http_send_msg_sync(pmsg, cmd_nr, node);
        if (ret) {
            goto skip_send_msg;
        }
        udx_agent_print("ioctl send msg ok, cmd_nr = %d\n", cmd_nr);
    }

skip_send_msg:
    if (pmsg != &msg) {
        kfree(pmsg);
    }

    return ret;
}

long udx_agent_fops_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    struct udx_agent_task_node *node = udx_get_instance(file);
    if (node == NULL) {
        udx_agent_print("Failed to get task node\n");
        return -EBADF;
    }
    return udx_agent_do_ioctl(node, cmd, arg, 0);
}

long udx_agent_fops_ioctl_compat(struct file *file, unsigned int cmd, unsigned long arg)
{
    udx_agent_print("ioctl compat mode\n");
    return udx_agent_fops_ioctl(file, cmd, (unsigned long)compat_ptr(arg));
}

static int udx_agent_alloc_instance(struct udx_agent_task_node *task_node)
{
    int ret;
    struct udx_agent *agent = &task_node->agent_info->agent;

    INIT_LIST_HEAD(&task_node->dma_buf_list);
    mutex_init(&task_node->dma_buf_list_mutex);
    init_waitqueue_head(&task_node->msg_fifo_waitq);
    mutex_init(&task_node->ioctl_mutex);
    sema_init(&task_node->ioctl_ack_sem, 0);
    INIT_WORK(&task_node->release_work, udx_agent_task_release_work);

    ret = kfifo_alloc(&task_node->msg_fifo, agent->recv_msg_buf_size, GFP_KERNEL);
    if (ret) {
        udx_agent_print("agent %s: Failed to alloc kfifo, ret = %d\n", AGENT_NAME(task_node), ret);
        return ret;
    }

    return 0;
}

static void udx_agent_free_instance(struct udx_agent_task_node *task_node)
{
    struct list_head *pos, *tmp;
    struct udx_agent_buf_node *dma_buf_node;

    mutex_lock(&task_node->dma_buf_list_mutex);
    list_for_each_safe(pos, tmp, &task_node->dma_buf_list) {
        dma_buf_node = list_entry(pos, struct udx_agent_buf_node, list);
        dma_buf_detach(dma_buf_node->dma_buf, dma_buf_node->attachment);
        dma_buf_put(dma_buf_node->dma_buf);
        kfree(dma_buf_node);
    }
    mutex_unlock(&task_node->dma_buf_list_mutex);

    kfifo_free(&task_node->msg_fifo);
}


static int udx_agent_alloc_task_id(struct udx_agent_task_node *task_node)
{
    struct udx_agent *agent = &task_node->agent_info->agent;

    mutex_lock(&task_node->agent_info->task_list_mutex);
    task_node->task_id = find_first_zero_bit(task_node->agent_info->task_id_map, agent->max_task_count);
    if (task_node->task_id >= agent->max_task_count) {
        mutex_unlock(&task_node->agent_info->task_list_mutex);
        udx_agent_print("agent %s: Failed to find a free task id\n", AGENT_NAME(task_node));
        return -EMLINK;
    }
    set_bit(task_node->task_id, task_node->agent_info->task_id_map);
    list_add_tail(&task_node->list, &task_node->agent_info->task_list);
    mutex_unlock(&task_node->agent_info->task_list_mutex);

    return 0;
}

static void udx_agent_free_task_id(struct udx_agent_task_node *task_node)
{
    mutex_lock(&task_node->agent_info->task_list_mutex);
    list_del(&task_node->list);
    clear_bit(task_node->task_id, task_node->agent_info->task_id_map);
    mutex_unlock(&task_node->agent_info->task_list_mutex);
}

void *udx_agent_get_instance(void *private_data)
{
    int ret;
    struct udx_agent_task_node *task_node;

    task_node = (struct udx_agent_task_node *)kzalloc(sizeof(*task_node), GFP_KERNEL);
    if (task_node == NULL) {
        udx_agent_print("Failed to allocate memory for task node\n");
        return task_node;
    }
    task_node->agent_info = (struct udx_agent_node *)private_data;

    ret = udx_agent_alloc_instance(task_node);
    if (ret) {
        goto err_alloc_instance;
    }

    ret = udx_agent_alloc_task_id(task_node);
    if (ret) {
        goto err_alloc_task_id;
    }

    ret = udx_agent_do_ioctl(task_node, UDX_AGENT_IOCTL_CMD_INIT, 0, 1);
    if (task_node->agent_info->agent.id == UDX_AGENT_ID_HTTP) {
        task_node->stream_id = ret;
        ret = 0;
    }
    if (ret) {
        udx_agent_print("agent %s: Failed to init task, ret = %d\n", AGENT_NAME(task_node), ret);
        goto err_init_task;
    }

    udx_agent_print("agent %s: task %u created\n", AGENT_NAME(task_node), task_node->task_id);

    return (void *)task_node;

err_init_task:
    udx_agent_free_task_id(task_node);
err_alloc_task_id:
    udx_agent_free_instance(task_node);
err_alloc_instance:
    kfree(task_node);

    return NULL;
}

int udx_agent_fops_open(struct inode *inode, struct file *file)
{
    struct udx_agent_node *agent_node;

    agent_node = list_first_entry(&g_udx_agent_list, struct udx_agent_node, list);
    if (agent_node == NULL) {
        udx_agent_print("Failed to get agent node\n");
        return -EBADF;
    }

    file->private_data = udx_agent_get_instance(agent_node);

    udx_agent_print("open ok\n");

    return 0;
}

void udx_agent_task_release_work(struct work_struct *work)
{
    struct udx_agent_task_node *task_node = container_of(work, struct udx_agent_task_node, release_work);

    udx_agent_print("agent %s: task %u release start\n", AGENT_NAME(task_node), task_node->task_id);

    (void)udx_agent_do_ioctl(task_node, UDX_AGENT_IOCTL_CMD_FREE, 0, 1);

    udx_agent_free_task_id(task_node);

    udx_agent_free_instance(task_node);

    udx_agent_print("agent %s: task %u release done\n", AGENT_NAME(task_node), task_node->task_id);

    kfree(task_node);

    pm_relax(&g_udx_agent_device.dev);
}

int udx_agent_fops_release(struct inode *inode, struct file *file)
{
    struct udx_agent_task_node *task_node;

    task_node = udx_get_instance(file);
    if (task_node == NULL) {
        udx_agent_print("Failed to get task node\n");
        return -EBADF;
    }

    udx_agent_print("agent %s: task %u receive release msg\n", AGENT_NAME(task_node), task_node->task_id);

    pm_stay_awake(&g_udx_agent_device.dev);
    schedule_work(&task_node->release_work);

    return 0;
}

int udx_agent_config(const char *name, int value, void *private_data)
{
    struct udx_agent_node *agent_info = (struct udx_agent_node *)private_data;

    udx_agent_print("agent %s: config %s = %d\n", agent_info->agent.name, name, value);

    return 0;
}

void udx_agent_dmi_sub_id_reg(struct udx_agent_task_node *task_node, struct udx_agent_msg_data *pmsg_data, u32 msg_len)
{
    struct udx_agent *agent = (struct udx_agent *)pmsg_data->buf;

    if (msg_len != sizeof(*agent)) {
        udx_agent_print( "Failed to reg agent, invalid msg len %d\n", msg_len);
        return;
    }

    if (agent->id >= UDX_AGENT_ID_MAX) {
        udx_agent_print("Failed to reg agent, invalid agent id %d\n", agent->id);
        return;
    }

    if (g_udx_agent_dmi_cb_work[agent->id].valid) {
        udx_agent_print("agent '%s' has been registered\n", g_udx_agent_dmi_cb_work[agent->id].agent.name);
        return;
    }

    (void)memcpy_s((void *)&g_udx_agent_dmi_cb_work[agent->id].agent, sizeof(*agent), (void *)agent, sizeof(*agent));
    g_udx_agent_dmi_cb_work[agent->id].agent.name[UDX_AGENT_NAME_MAX_LEN - 1] = '\0';
    g_udx_agent_dmi_cb_work[agent->id].valid = 1;

    udx_agent_print("agent '%s' register begin\n", g_udx_agent_dmi_cb_work[agent->id].agent.name);

    pm_stay_awake(&g_udx_agent_device.dev);
    schedule_work(&g_udx_agent_dmi_cb_work[agent->id].work);
}

void udx_agent_dmi_sub_id_ack(struct udx_agent_task_node *task_node, struct udx_agent_msg_data *pmsg_data, u32 msg_len)
{
    udx_agent_print("agent %s: task %u ack received, cmd = %u, ret = %d\n",
        AGENT_NAME(task_node), pmsg_data->task_id, pmsg_data->ioctl_cmd, pmsg_data->ack_status);
    task_node->ioctl_ack_status = pmsg_data->ack_status;
    up(&task_node->ioctl_ack_sem);
}

void udx_agent_dmi_sub_id_msg(struct udx_agent_task_node *task_node, struct udx_agent_msg_data *pmsg_data, u32 msg_len)
{
    udx_agent_print("agent %s: task %u msg received, msg_len = %u\n",
        AGENT_NAME(task_node), pmsg_data->task_id, msg_len);

    if (msg_len) {
        kfifo_in(&task_node->msg_fifo, pmsg_data->buf, msg_len);
        wake_up_interruptible(&task_node->msg_fifo_waitq);
    }
}

struct udx_agent_dmi_cb_ops g_udx_agent_dmi_cb_ops[] = {
    { UDX_AGENT_DMI_SUB_ID_ACK, udx_agent_dmi_sub_id_ack },
    { UDX_AGENT_DMI_SUB_ID_MSG, udx_agent_dmi_sub_id_msg },
};

int udx_agent_dmi_service_callback(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    u32 i;
    u32 found = 0;
    struct list_head *agent_pos, *agent_tmp, *task_pos, *task_tmp;
    struct udx_agent_node *agent_node;
    struct udx_agent_task_node *task_node;
    struct udx_agent_msg_data *pmsg_data = (struct udx_agent_msg_data *)(&msg->buf[0]);

    if (msg->len < sizeof(struct udx_agent_msg_data)) {
        udx_agent_print("Invalid msg len %d\n", msg->len);
        return 0;
    }

    if (service_sub_id == UDX_AGENT_DMI_SUB_ID_REG) {
        udx_agent_dmi_sub_id_reg(NULL, pmsg_data, msg->len - sizeof(*pmsg_data));
        return 0;
    }

    mutex_lock(&g_udx_agent_list_mutex);

    list_for_each_safe(agent_pos, agent_tmp, &g_udx_agent_list) {
        agent_node = list_entry(agent_pos, struct udx_agent_node, list);
        if (agent_node->agent.id != pmsg_data->agent_id) {
            continue;
        }
        mutex_lock(&agent_node->task_list_mutex);
        list_for_each_safe(task_pos, task_tmp, &agent_node->task_list) {
            task_node = list_entry(task_pos, struct udx_agent_task_node, list);
            if (task_node->task_id == pmsg_data->task_id) {
                for (i = 0; i < sizeof(g_udx_agent_dmi_cb_ops) / sizeof(g_udx_agent_dmi_cb_ops[0]); i++) {
                    if (g_udx_agent_dmi_cb_ops[i].cmd == service_sub_id) {
                        g_udx_agent_dmi_cb_ops[i].func(task_node, pmsg_data, msg->len - sizeof(*pmsg_data));
                        found = 1;
                        break;
                    }
                }
                break;
            }
        }
        mutex_unlock(&agent_node->task_list_mutex);
        break;
    }
    mutex_unlock(&g_udx_agent_list_mutex);

    if (!found) {
        udx_agent_print("Failed to find task node, agent_id = %u, task_id = %u, msg_len = %u\n",
            pmsg_data->agent_id, pmsg_data->task_id, msg->len);
    }

    return 0;
}

static struct file_operations udx_agent_fops = {
    .read           = udx_agent_fops_read,
    .write          = udx_agent_fops_write,
    .poll           = udx_agent_fops_poll,
    .llseek         = udx_agent_fops_seek,
    .unlocked_ioctl = udx_agent_fops_ioctl,
#ifdef CONFIG_COMPAT
    .compat_ioctl   = udx_agent_fops_ioctl_compat,
#endif
//    .map          = udx_agent_fops_map,
    .open           = udx_agent_fops_open,
    .release        = udx_agent_fops_release,
};

static int udx_agent_register(struct udx_agent_node *agent_node)
{
    int ret;

    INIT_LIST_HEAD(&agent_node->task_list);
    mutex_init(&agent_node->task_list_mutex);
    agent_node->task_id_map = bitmap_zalloc(agent_node->agent.max_task_count, GFP_KERNEL);
    if (agent_node->task_id_map == NULL) {
        udx_agent_print("agent %s: Failed to alloc bitmap\n", agent_node->agent.name);
        return -ENOMEM;
    }

    dma_set_coherent_mask(agent_node->dev, DMA_BIT_MASK(agent_node->agent.dev_dma_bit_mask));

    agent_node->service.fops            = &udx_agent_fops;
    agent_node->service.get_instance    = udx_agent_get_instance;
    agent_node->service.config          = udx_agent_config;
    agent_node->service.private_data    = agent_node;
    ret = udx_service_register(agent_node->agent.name, &agent_node->service);
    if (ret) {
        bitmap_free(agent_node->task_id_map);
        udx_agent_print("agent %s: Failed to register agent service, ret = %d\n", agent_node->agent.name, ret);
        return ret;
    }

    mutex_lock(&g_udx_agent_list_mutex);
    list_add_tail(&agent_node->list, &g_udx_agent_list);
    mutex_unlock(&g_udx_agent_list_mutex);
    udx_agent_print("register agent '%s' ok\n", agent_node->agent.name);

    return 0;
}

int bsp_udx_agent_register(struct udx_agent *agent)
{
    int ret;
    struct cdev *cdev;
    struct udx_agent_node *agent_node;

    agent_node = (struct udx_agent_node *)kmalloc(sizeof(*agent_node), GFP_KERNEL);
    if (agent_node == NULL) {
        udx_agent_print("agent %s: Failed to alloc memory for agent info\n", agent->name);
        return -ENOMEM;
    }

    cdev = cdev_alloc();
    if (cdev == NULL) {
        udx_agent_print("agent %s: Failed to alloc cdev\n", agent->name);
        ret = -ENXIO;
        goto err_alloc_cdev;
    }
    cdev_init(cdev, NULL);
    agent_node->dev = udx_cdev_create(cdev, agent->name, NULL);
    if (agent_node->dev == NULL) {
        udx_agent_print("agent %s: Failed to create cdev\n", agent->name);
        ret = -ENXIO;
        goto err_create_cdev;
    }

    (void)memcpy_s((void *)&agent_node->agent, sizeof(*agent), (void *)agent, sizeof(*agent));
    agent_node->agent.name[UDX_AGENT_NAME_MAX_LEN - 1] = '\0';

    ret = udx_agent_register(agent_node);
    if (ret) {
        goto err_register_agent;
    }

    return 0;

err_register_agent:
    udx_cdev_del(cdev);
err_create_cdev:
    kfree(cdev);
err_alloc_cdev:
    kfree(agent_node);

    return ret;
}

void udx_agent_register_work(struct work_struct *work)
{
    int ret;
    struct udx_agent_work_info *work_info = container_of(work, struct udx_agent_work_info, work);

    ret = bsp_udx_agent_register(&work_info->agent);
    if (ret) {
        udx_agent_print("Failed to register agent %s, ret = %d\n", work_info->agent.name, ret);
    }

    pm_relax(&g_udx_agent_device.dev);
}

static int udx_agent_probe(struct platform_device *pdev)
{
    int ret = 0;
    unsigned int i;
    struct dmi_client udx_agent_dmi_client = { 0 };

    INIT_LIST_HEAD(&g_udx_agent_list);
    mutex_init(&g_udx_agent_list_mutex);

    for (i = 0; i < UDX_AGENT_ID_MAX; i++) {
        INIT_WORK(&g_udx_agent_dmi_cb_work[i].work, udx_agent_register_work);
    }

    ret = bsp_dmi_client_init(&udx_agent_dmi_client);
    if (ret) {
        udx_agent_print("Failed to init dmi udx agent client, ret = %d\n", ret);
        return ret;
    }

    udx_agent_dmi_client.dmi_id = DMI_SERVICE_UDX_AGENT;
    udx_agent_dmi_client.service_cb = udx_agent_dmi_service_callback;
    ret = bsp_dmi_client_register(&udx_agent_dmi_client);
    if (ret) {
        udx_agent_print("Failed to register dmi udx agent client, ret = %d\n", ret);
        return ret;
    }

    udx_agent_print("udx agent init ok\n");

    return ret;
}

static struct platform_driver g_udx_agent_driver = {
    .probe      = udx_agent_probe,
    .driver     = {
        .name     = "udx_agent",
        .owner    = THIS_MODULE,
        .probe_type = PROBE_FORCE_SYNCHRONOUS,
    },
};

int udx_agent_init(void)
{
    int ret;

    ret = platform_device_register(&g_udx_agent_device);
    if (ret) {
        udx_agent_print("Failed to register udx agent device\n");
        return ret;
    }

    ret = platform_driver_register(&g_udx_agent_driver);
    if (ret) {
        platform_device_unregister(&g_udx_agent_device);
        udx_agent_print("Failed to register udx agent driver\n");
    }

    return ret;
}

int udx_http_debug_enable(void)
{
    int ret;
    dev_t devid;
    struct device *dev;
    static struct cdev udx_agent_cdev;
    static struct class *udx_agent_class;

    if (g_udx_agent_dev_enable) {
        return 0;
    }

    ret = alloc_chrdev_region(&devid, 0, 1, "udx_agent");
    if (ret) {
        udx_agent_print("alloc_chrdev_region failed, ret = %d\n", ret);
        return ret;
    }

    cdev_init(&udx_agent_cdev, &udx_agent_fops);
    ret = cdev_add(&udx_agent_cdev, MKDEV(MAJOR(devid), 0), 1);
    if (ret) {
        udx_agent_print("cdev_add failed, ret = %d\n", ret);
        goto unregister_chrdev;
    }

    udx_agent_class = class_create(THIS_MODULE, "udx_agent_class");
    if (IS_ERR(udx_agent_class)) {
        udx_agent_print("class_create failed, ret = %ld\n", PTR_ERR(udx_agent_class));
        goto delete_chrdev;
    }

    dev = device_create(udx_agent_class, NULL, devid, NULL, "udx_agent");
    if (IS_ERR(dev)) {
        udx_agent_print("device_create failed, ret = %ld\n", PTR_ERR(dev));
        goto destroy_class;
    }

    g_udx_agent_dev_enable = 1;
    return 0;

destroy_class:
    class_destroy(udx_agent_class);

delete_chrdev:
    cdev_del(&udx_agent_cdev);

unregister_chrdev:
    unregister_chrdev_region(MKDEV(MAJOR(devid), 0), 1);

    return 0;
}

int show_udx_agent_info(void)
{
    int i;

    for (i = 0; i < UDX_AGENT_ID_MAX; i++) {
        if (!g_udx_agent_dmi_cb_work[i].valid)
            continue;

        udx_agent_print("Agent ID: %d\n", g_udx_agent_dmi_cb_work[i].agent.id);
        udx_agent_print("  Agent name: %s\n", g_udx_agent_dmi_cb_work[i].agent.name);
        udx_agent_print("  Agent dev dma mask: %d\n", g_udx_agent_dmi_cb_work[i].agent.dev_dma_bit_mask);
        udx_agent_print("  Agent max task count: %d\n", g_udx_agent_dmi_cb_work[i].agent.max_task_count);
        udx_agent_print("  Agent max dma buf count: %d\n", g_udx_agent_dmi_cb_work[i].agent.max_dma_buf_count);
        udx_agent_print("  Agent recv msg buf size: %d\n", g_udx_agent_dmi_cb_work[i].agent.recv_msg_buf_size);
    }

    return 0;
}

int show_udx_agent_task_info(void)
{
    struct udx_agent_node *agent_node;
    struct udx_agent_task_node *task_node;
    struct list_head *agent_pos, *agent_tmp, *task_pos, *task_tmp;

    mutex_lock(&g_udx_agent_list_mutex);

    list_for_each_safe(agent_pos, agent_tmp, &g_udx_agent_list) {
        agent_node = list_entry(agent_pos, struct udx_agent_node, list);

        list_for_each_safe(task_pos, task_tmp, &agent_node->task_list) {
            task_node = list_entry(task_pos, struct udx_agent_task_node, list);
            udx_agent_print("Agent %s, Task %d:\n", agent_node->agent.name, task_node->task_id);
            udx_agent_print("  Task stream ID: %d\n", task_node->stream_id);
            udx_agent_print("  Send msg buf size: %d\n", task_node->send_msg_buf_size);
            udx_agent_print("  Task kfifo len: %d\n", kfifo_len(&task_node->msg_fifo));
        }
    }

    mutex_unlock(&g_udx_agent_list_mutex);
    return 0;
}