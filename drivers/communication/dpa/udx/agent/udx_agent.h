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
#ifndef UDX_AGENT_H
#define UDX_AGENT_H

#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/wait.h>
#include <linux/kfifo.h>
#include <linux/mutex.h>
#include <linux/dma-buf.h>
#include <linux/semaphore.h>

#include <bsp_dmi.h>
#include <bsp_udx.h>
#include <bsp_print.h>

#include <bsp_udx_agent.h>


#define udx_agent_print(fmt, args...) do { \
    dpa_pr_err("[agent]" fmt, ##args); \
} while (0)

#define AGENT_NAME(task_node)   (task_node->agent_info->agent.name)

struct udx_agent_node {
    struct list_head list;

    struct device *dev;
    struct udx_agent agent;

    struct mutex task_list_mutex;
    unsigned long *task_id_map;
    struct list_head task_list;

    struct udx_service_impl service;
};

struct udx_agent_task_node {
    struct list_head list;

    struct udx_agent_node *agent_info;

    u32 task_id;
    u32 stream_id;      // dpa task id, for socket association

    struct list_head dma_buf_list;
    struct mutex dma_buf_list_mutex;

    u32 send_msg_buf_size;
    struct kfifo msg_fifo;
    wait_queue_head_t msg_fifo_waitq;

    int ioctl_ack_status;
    struct mutex ioctl_mutex;
    struct semaphore ioctl_ack_sem;

    struct work_struct release_work;

    void *private_data;
};

struct udx_agent_buf_node {
    struct list_head list;

    unsigned int buf_fd;
    unsigned int buf_id;
    unsigned int bufqueue_id;
    struct dma_buf *dma_buf;
    struct dma_buf_attachment *attachment;
};

struct udx_agent_work_info {
    int valid;
    struct udx_agent agent;
    struct work_struct work;
};

#pragma pack(push, 1)

#define UDX_AGENT_BUFFERQUEUE_NODE_NUM            (2)
struct udx_agent_ioctl_bufferqueue_info {
    union {
        struct {
            unsigned int fd;            // dma buf fd
            unsigned int offset;
        } attr;
        unsigned long long phy_addr;    // dma buf addr + offset
    } dma_buffer;
    unsigned int len;       // in bytes, include 4 words header
    unsigned int type;      // 0 - empty buffer; 1 - full buffer
    unsigned int index;     // output bufferqueue index
};

struct udx_agent_ioctl_bufmap_info {
    unsigned int buf_fd;
    unsigned int buf_id;
    unsigned int bufqueue_id;
};

/*
 * msg layout
 *
 * ioctl cmd
 * task_id
 * msg buffer
 */
struct udx_agent_msg_data {
    unsigned int agent_id;
    unsigned int task_id;
    unsigned int ioctl_cmd;
    unsigned int ack_status;
    char         buf[0];
};
struct udx_agent_msg {
    struct dmi_msg header;
    struct udx_agent_msg_data data;
};

struct udx_agent_bufmap_msg {
    unsigned int buf_fd;
    unsigned int buf_id;
    unsigned int bufqueue_id;
    unsigned long long buf_addr;
    unsigned int buf_size;
};
#pragma pack(pop)

enum udx_agent_filter_cmd {
    UDX_AGENT_CMD_SET_INPUT_BUFFERQUEUE = 1,    // arg = pointer to 'struct udx_agent_ioctl_bufferqueue_info'
    UDX_AGENT_CMD_SET_OUTPUT_BUFFERQUEUE,       // arg = pointer to 'struct udx_agent_ioctl_bufferqueue_info'
    UDX_AGENT_CMD_ATTACH_BUFFER,                // arg = buffer fd
    UDX_AGENT_CMD_MAP_BUFFER,                   // arg = buffer fd
    UDX_AGENT_CMD_PREPARE,                      // 5
    UDX_AGENT_CMD_START,
    UDX_AGENT_CMD_STOP,
    UDX_AGENT_CMD_RESET,
    UDX_AGENT_CMD_PAUSE,
    UDX_AGENT_CMD_RESUME,                       // 10

    UDX_AGENT_CMD_SET_SEND_MSG_BUFFER,          // arg = send msg buffer fd
    UDX_AGENT_CMD_SEND_MSG,

    UDX_AGENT_CMD_INIT,
    UDX_AGENT_CMD_FREE,
};

#define UDX_AGENT_IOCTL_CMD_SET_INPUT_BUFFERQUEUE \
    _IOW('u', UDX_AGENT_CMD_SET_INPUT_BUFFERQUEUE, \
    struct udx_agent_ioctl_bufferqueue_info[UDX_AGENT_BUFFERQUEUE_NODE_NUM])

#define UDX_AGENT_IOCTL_CMD_SET_OUTPUT_BUFFERQUEUE \
    _IOW('u', UDX_AGENT_CMD_SET_OUTPUT_BUFFERQUEUE, \
    struct udx_agent_ioctl_bufferqueue_info[UDX_AGENT_BUFFERQUEUE_NODE_NUM])

#define UDX_AGENT_IOCTL_CMD_ATTACH_BUFFER           _IOW('u', UDX_AGENT_CMD_ATTACH_BUFFER, unsigned long)
#define UDX_AGENT_IOCTL_CMD_MAP_BUFFER \
    _IOW('u', UDX_AGENT_CMD_MAP_BUFFER, struct udx_agent_ioctl_bufmap_info)
#define UDX_AGENT_IOCTL_CMD_PREPARE                 _IO('u', UDX_AGENT_CMD_PREPARE)
#define UDX_AGENT_IOCTL_CMD_START                   _IO('u', UDX_AGENT_CMD_START)
#define UDX_AGENT_IOCTL_CMD_STOP                    _IO('u', UDX_AGENT_CMD_STOP)
#define UDX_AGENT_IOCTL_CMD_RESET                   _IO('u', UDX_AGENT_CMD_RESET)
#define UDX_AGENT_IOCTL_CMD_PAUSE                   _IO('u', UDX_AGENT_CMD_PAUSE)
#define UDX_AGENT_IOCTL_CMD_RESUME                  _IO('u', UDX_AGENT_CMD_RESUME)
#define UDX_AGENT_IOCTL_CMD_SET_SEND_MSG_BUFFER     _IOW('u', UDX_AGENT_CMD_SET_SEND_MSG_BUFFER, unsigned long)
#define UDX_AGENT_IOCTL_CMD_SEND_MSG                _IO('u', UDX_AGENT_CMD_SEND_MSG)

#define UDX_AGENT_IOCTL_CMD_INIT                    _IO('u', UDX_AGENT_CMD_INIT)
#define UDX_AGENT_IOCTL_CMD_FREE                    _IO('u', UDX_AGENT_CMD_FREE)

struct udx_agent_ioctl_ops {
    int cmd;
    int need_send_msg;
    long (*func)(struct udx_agent_task_node *, unsigned long, struct udx_agent_msg **);
};

enum udx_agent_dmi_sub_id {
    UDX_AGENT_DMI_SUB_ID_REG = 0x1,
    UDX_AGENT_DMI_SUB_ID_ACK,
    UDX_AGENT_DMI_SUB_ID_MSG,
    UDX_AGENT_DMI_SUB_ID_MAX,
};
struct udx_agent_dmi_cb_ops {
    int cmd;
    void (*func)(struct udx_agent_task_node *task_node, struct udx_agent_msg_data *pmsg_data, u32 msg_len);
};


void udx_agent_task_release_work(struct work_struct *work);

// http only, delete in the future

#define UDX_HTTP_URL_MAX_LEN                (2 * 1024)
#define UDX_HTTP_TASK_NUM_MAX               (2 * 1024)
#define UDX_HTTP_HEADER_MAX_LEN             (2 * 1024)
#define UDX_HTTP_POST_DATA_MAX_LEN          (2 * 1024)
#define UDX_HTTP_DMA_BUF_ID_MAX             (1 * 1024)

#pragma pack(push, 1)

struct udx_http_ioctl_range {
    unsigned long long offset;
    unsigned long long length;
};

struct udx_http_ioctl_report_policy {
    unsigned int interval_ms;        // 0 - disable time report
    unsigned int data_length;        // 0 - disable data report
};

#pragma pack(pop)

enum udx_http_filter_cmd {
    UDX_HTTP_CMD_GET_STREAM_ID = 100,   // arg = &id
    UDX_HTTP_CMD_SET_URL,               // arg = "url"
    UDX_HTTP_CMD_SET_METHOD,            // arg = method(0 : GET, 1 : POST)
    UDX_HTTP_CMD_SET_HEADER,            // arg = "header"
    UDX_HTTP_CMD_SET_POST_DATA,         // arg = "post data"
    UDX_HTTP_CMD_SET_CONNECTTIMEOUT_MS, // arg = connect timeout(ms)
    UDX_HTTP_CMD_SEEK,                  // arg = seek offset
    UDX_HTTP_CMD_SET_RANGE,             // arg = pointer to 'struct udx_http_ioctl_range'
    UDX_HTTP_CMD_SET_REPORT_POLICY,     // arg = pointer to 'struct udx_http_ioctl_report_policy'
};

#define UDX_HTTP_IOCTL_CMD_GET_STREAM_ID            _IOR('u', UDX_HTTP_CMD_GET_STREAM_ID, unsigned long)
#define UDX_HTTP_IOCTL_CMD_SET_URL                  _IOW('u', UDX_HTTP_CMD_SET_URL, char *)
#define UDX_HTTP_IOCTL_CMD_SET_METHOD               _IOW('u', UDX_HTTP_CMD_SET_METHOD, unsigned long)
#define UDX_HTTP_IOCTL_CMD_SET_HEADER               _IOW('u', UDX_HTTP_CMD_SET_HEADER, char *)
#define UDX_HTTP_IOCTL_CMD_SET_POST_DATA            _IOW('u', UDX_HTTP_CMD_SET_POST_DATA, char *)
#define UDX_HTTP_IOCTL_CMD_SET_CONNECTTIMEOUT_MS    _IOW('u', UDX_HTTP_CMD_SET_CONNECTTIMEOUT_MS, unsigned long)
#define UDX_HTTP_IOCTL_CMD_SEEK                     _IOW('u', UDX_HTTP_CMD_SEEK, unsigned long)
#define UDX_HTTP_IOCTL_CMD_SET_RANGE                _IOW('u', UDX_HTTP_CMD_SET_RANGE, struct udx_http_ioctl_range)
#define UDX_HTTP_IOCTL_CMD_SET_REPORT_POLICY \
    _IOW('u', UDX_HTTP_CMD_SET_REPORT_POLICY, struct udx_http_ioctl_report_policy)
// http only end

#endif