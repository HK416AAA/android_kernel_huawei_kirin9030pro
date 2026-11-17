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
#ifndef __DSS_DEV_H__
#define __DSS_DEV_H__

#include <linux/mutex.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/poll.h>
#include <linux/list.h>
#include <linux/in.h>
#include <linux/socket.h>
#include "../buffer/udx_buffer_queue.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(push)
#pragma pack(4)

#define dss_print(fmt, args...) do { \
    dpa_pr_err("[dss]" fmt, ##args); \
} while (0)

typedef enum {
    DSS_OPEN_EVENT = 0,
    DSS_CLOSE_EVENT,
    DSS_READ_EVENT,
    DSS_WRITE_EVENT,
    DSS_LSEEK_EVENT,
    DSS_STAT_EVENT,
    DSS_CHMOD_EVENT,
    DSS_CHOWN_EVENT,
    DSS_FSTAT_EVENT,
    DSS_ACCESS_EVENT,
    DSS_UNLINK_EVENT,
    DSS_RENAME_EVENT,
    DSS_FTRUNCATE_EVENT,
    DSS_SET_FD_LIST_EVENT,
    DSS_SET_FILE_NAME_LIST_EVENT,
    DSS_EVENT_MAX,
} dss_event_type;

// A核与DPA之间通信的接口
typedef enum {
    DSS_MESSAGE,
    DSS_SUB_ID_MAX,
} dss_sub_id;

// filter drv
enum udx_filter_cmd {
    UDX_CMD_SET_INPUT_BUFFERQUEUE = 1,
    UDX_CMD_SET_OUTPUT_BUFFERQUEUE,
    UDX_CMD_ATTACH_BUFFER,
    UDX_CMD_MAP_BUFFER,
    UDX_CMD_PREPARE,
    UDX_CMD_START,
    UDX_CMD_STOP,
    UDX_CMD_RESET,
    UDX_CMD_PAUSE,
    UDX_CMD_RESUME,
};

#define UDX_IOCTL_CMD_SET_INPUT_BUFFERQUEUE \
    _IOW('u', UDX_CMD_SET_INPUT_BUFFERQUEUE, struct udx_http_ioctl_buffer[UDX_HTTP_BUFFER_NODE_NUM])
#define UDX_IOCTL_CMD_SET_OUTPUT_BUFFERQUEUE \
    _IOW('u', UDX_CMD_SET_OUTPUT_BUFFERQUEUE, struct udx_http_ioctl_buffer[UDX_HTTP_BUFFER_NODE_NUM])
#define UDX_IOCTL_CMD_ATTACH_BUFFER             _IOW('u', UDX_CMD_ATTACH_BUFFER, unsigned long)
#define UDX_IOCTL_CMD_MAP_BUFFER                _IOW('u', UDX_CMD_MAP_BUFFER, unsigned long)
#define UDX_IOCTL_CMD_PREPARE                   _IO('u', UDX_CMD_PREPARE)
#define UDX_IOCTL_CMD_START                     _IO('u', UDX_CMD_START)
#define UDX_IOCTL_CMD_STOP                      _IO('u', UDX_CMD_STOP)
#define UDX_IOCTL_CMD_RESET                     _IO('u', UDX_CMD_RESET)
#define UDX_IOCTL_CMD_PAUSE                     _IO('u', UDX_CMD_PAUSE)
#define UDX_IOCTL_CMD_RESUME                    _IO('u', UDX_CMD_RESUME)

enum udx_dss_filter_cmd {
    UDX_DSS_CMD_OPEN_SESSION = 100,
    UDX_DSS_CMD_START_SERVER,
    UDX_DSS_CMD_START_CLIENT,
    UDX_DSS_CMD_SEND_FILES_NAME,
    UDX_DSS_CMD_SEND_FILES_FD,
    UDX_DSS_CMD_STOP_SERVER,
    UDX_DSS_CMD_STOP_CLIENT,
    UDX_DSS_CMD_CLOSE_SESSION,
    UDX_DSS_CMD_SET_FD_LIST,
    UDX_DSS_CMD_SET_FILE_NAME_LIST,
    UDX_DSS_CMD_SET_STORAGE_PATH,
    UDX_DSS_CMD_GET_CAPABILITY,
    UDX_DSS_CMD_GET_FILE_FRAME,

    UDX_DSS_CMD_FREE,
};

#define UDX_DSS_IOCTL_CMD_OPEN_SESSION _IOW('u', UDX_DSS_CMD_OPEN_SESSION, unsigned long)
#define UDX_DSS_IOCTL_CMD_START_SERVER _IOW('u', UDX_DSS_CMD_START_SERVER, unsigned long)
#define UDX_DSS_IOCTL_CMD_START_CLIENT _IOW('u', UDX_DSS_CMD_START_CLIENT, unsigned long)
#define UDX_DSS_IOCTL_CMD_SEND_FILES_NAME _IOW('u', UDX_DSS_CMD_SEND_FILES_NAME, unsigned long)
#define UDX_DSS_IOCTL_CMD_SEND_FILES_FD _IOW('u', UDX_DSS_CMD_SEND_FILES_FD, unsigned long)
#define UDX_DSS_IOCTL_CMD_STOP_SERVER _IOW('u', UDX_DSS_CMD_STOP_SERVER, unsigned long)
#define UDX_DSS_IOCTL_CMD_STOP_CLIENT _IOW('u', UDX_DSS_CMD_STOP_CLIENT, unsigned long)
#define UDX_DSS_IOCTL_CMD_CLOSE_SESSION _IOW('u', UDX_DSS_CMD_CLOSE_SESSION, unsigned long)
#define UDX_DSS_IOCTL_CMD_SET_FD_LIST _IOW('u', UDX_DSS_CMD_SET_FD_LIST, unsigned long)
#define UDX_DSS_IOCTL_CMD_SET_FILE_NAME_LIST _IOW('u', UDX_DSS_CMD_SET_FILE_NAME_LIST, unsigned long)
#define UDX_DSS_IOCTL_CMD_SET_STORAGE_PATH _IOW('u', UDX_DSS_CMD_SET_STORAGE_PATH, unsigned long)
#define UDX_DSS_IOCTL_CMD_GET_CAPABILITY _IOW('u', UDX_DSS_CMD_GET_CAPABILITY, unsigned long)

struct udx_dss_task_node {
    struct list_head list;
    u32 task_id;
    u32 task_state;
    u32 service_id;
    int trans_id;
    int server_flag;
    dma_addr_t file_list_paddr;
    void *file_list_vaddr;
    u64 file_list_len;
    struct list_head dma_buf_list;
    struct mutex dma_buf_list_mutex;
    struct kfifo msg_fifo;
    wait_queue_head_t waitq;
    void *private_data;
};

struct udx_dss_msg {
    struct dmi_msg header;
    u32 task_id;
    u32 service_id;
    u8  buf[0];
};

struct udx_dss_msg_data {
    u32 task_id;
    u32 service_id;
    u8 buf[0];
};

#define UDX_DSS_BUFFER_NODE_NUM            (2)
struct udx_dss_ioctl_buffer {
    union {
        struct {
            unsigned int fd;        // dma buf fd
            unsigned int offset;
        } attr;
        unsigned long long phy_addr;     // dma buf addr + offset
    } dma_buffer;
    unsigned int len;       // in bytes, include 4 words header
    unsigned int type;      // 0 - empty buffer; 1 - full buffer
};

struct udx_dss_ioctl_buffer_info {
    unsigned int buf_fd;
    unsigned int buf_id;
    unsigned long long buf_addr;
    unsigned int buf_size;
};

struct udx_dss_dma_buf_node {
    struct list_head list;
    struct dma_buf *dma_buf;
    struct dma_buf_attachment *attachment;
};

struct dss_driver_data {
    struct mutex lock;
    struct list_head file_list;
    struct list_head dfa_list;
};

#define UDX_DSS_TASK_NUM_MAX 8
struct udx_dss_info {
    struct device *dev;
    struct mutex task_list_mutex;
    struct list_head task_list;
    unsigned long *task_id_map;
};

#define DSS_MAX_PATH_NAME 256
#define DSS_MAX_FILE_CNT 500
#define DSS_MAX_FILE_PATH_LEN 256

typedef struct {
    char file_name[DSS_MAX_FILE_PATH_LEN]; /* used only in open task */
    int32_t fd;
    int64_t file_size;
} file_ctx;

typedef struct {
    int trans_id;
    int num;
    int pid;
    int nsid;
    file_ctx ctx_list[0];
} file_ctx_list;

struct udx_dss_open_sesison_para {
    int32_t session_id;
};

struct udx_dss_start_server_para {
    int32_t session_id;
    struct sockaddr_in local_addr;
    unsigned int addr_len;
    uint8_t key[32];
    uint32_t key_len;
};

struct udx_dss_start_client_para {
    int32_t session_id;
    struct sockaddr_in srv_addr;
    unsigned int addr_len;
    uint8_t key[32];
    uint32_t key_len;
};

struct udx_dss_send_file_name_para {
    int session_id;
    uint32_t file_num;
    char file_path[0][DSS_MAX_FILE_PATH_LEN];
};

struct udx_dss_send_file_fd_para {
    int session_id;
    file_ctx_list file_list;
};

struct udx_dss_set_file_fd_para {
    int session_id;
    uint64_t file_list_phy_addr;
    uint64_t file_list_len;
};

struct udx_dss_stop_server_para {
    int32_t session_id;
};

struct udx_dss_stop_client_para {
    int32_t session_id;
};

struct udx_dss_close_session_para {
    int32_t session_id;
};

struct udx_dss_set_storage_path_para {
    int session_id;
    char path[256];
};

struct udx_dss_get_capability_para {
    int session_id;
    int capability;
};

typedef enum {
    UDX_TRANS_MSG_FILE_SEND_DATA,
    UDX_TRANS_MSG_FILE_LIST_RECEIVED,
    UDX_TRANS_MSG_FILE_RECEIVED, /* Receiver receive all the file data */
    UDX_TRANS_MSG_FILE_RECEIVE_FAIL,
    UDX_TRANS_MSG_FILE_RECEIVED_TO_FAIL,
    UDX_TRANS_MSG_FILE_SENT, /* Sender send TRANSFER DONE ACK frame and come to end */
    UDX_TRANS_MSG_FILE_SEND_FAIL,
    UDX_TRANS_MSG_IN_PROGRESS,
    UDX_TRANS_MSG_FILE_SEND_ACK,
    UDX_TRANS_MSG_END,
} udx_dss_trans_msg_type;

typedef enum {
    UDX_DSS_SEND_FAIL_ERR = 1,
    UDX_DSS_READ_FAIL_ERR,
    UDX_DSS_RECV_FAIL_ERR,
    UDX_DSS_WRITE_FAIL_ERR,
    UDX_DSS_DPA_RESET_ERR,
} udx_dss_report_error_code_e;

typedef enum {
    UDX_DSS_MSG_TYPE_REPORT,
    UDX_DSS_MSG_TYPE_RESPONSE,
    UDX_DSS_MSG_TYPE_MAX,
} dss_filter_msg_type;

struct filter_msg_header {
    unsigned int msg_size;
    unsigned int msg_type;
};

typedef struct {
    struct filter_msg_header filter_header;
    int dss_msg_type;
    int trans_id;
    uint64_t send_bytes;
    uint64_t total_bytes;
    int32_t error_code;
} udx_dss_report_msg;

typedef struct {
    int dss_msg_type;
    int trans_id;
    uint64_t send_bytes;
    uint64_t total_bytes;
    int32_t error_code;
} udx_dss_report_msg_data;

#pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
