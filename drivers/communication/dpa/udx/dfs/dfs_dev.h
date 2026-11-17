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
#ifndef __FILE_SERVICE_H__
#define __FILE_SERVICE_H__

#include <linux/mutex.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/poll.h>
#include <linux/list.h>
#include <linux/in.h>
#include "f2fs_intf.h"
#include "../buffer/udx_buffer_queue.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(push)
#pragma pack(4)

#define dfs_print(fmt, args...) do { \
    dpa_pr_err("[dfs]" fmt, ##args); \
} while (0)


#define FILE_MAX_DFA_INFO_LEN 4096

struct file_ctx_fd {
    int pid;
    int nsid;
    int32_t fd;
    uint64_t file_size;
};

#define FILE_PATH_MAX_LEN 256
struct fs_single_file_info {
    struct file_ctx_fd fd_info;
};

#define MAX_FILE_SINGLE_BURST 100
struct fs_file_info {
    unsigned int seq_no;
    int file_cnt;
#ifdef USE_FD
    pid_t pid;
#endif
    struct fs_single_file_info files[0];
};

typedef enum {
    FILE_READ_MODE,
    FILE_WRITE_MODE,
    FILE_APPEND_MODE,
} file_mode_t;

struct fs_dfa_query {
    int query_cnt;
    int ops; // read or write
    struct fs_single_file_info files[0];
};

struct file_crypto_meta {
    int ci_key_index;
    int ci_metadata[4]; /* fixed length: 4 */
};

struct file_lba_resp {
    int len; // file total len
    int max_pkt; // max pkt num
    int pkt_no; // pkt num
    int lba_array_len; // curr lba array len
    struct file_crypto_meta ci_info;
    struct file_lba_info lba_info[0];
};

struct file_lba_query {
    int sn;
    int query_cnt;
    int mode; // read or write
    struct fs_single_file_info files[0];
};

typedef enum {
    DFS_OPEN_EVENT = 0,
    DFS_CLOSE_EVENT,
    DFS_READ_EVENT,
    DFS_WRITE_EVENT,
    DFS_LSEEK_EVENT,
    DFS_STAT_EVENT,
    DFS_CHMOD_EVENT,
    DFS_CHOWN_EVENT,
    DFS_FSTAT_EVENT,
    DFS_ACCESS_EVENT,
    DFS_UNLINK_EVENT,
    DFS_RENAME_EVENT,
    DFS_FTRUNCATE_EVENT,
    DFS_SET_FD_LIST_EVENT,
    DFS_SET_FILE_NAME_LIST_EVENT,
    DFS_EVENT_MAX,
} dfs_event_type;

// A核与DPA之间通信的接口
typedef enum {
    DFS_FILE_LBA = 120,
    DFS_MESSAGE,
    DFS_FILE_SUB_ID_MAX,
} dfs_sub_id;

struct file_lba_data {
    int len; // file total len
    int max_pkt; // max pkt num
    int pkt_no; // pkt num
    int lba_array_len; // curr lba array len
    struct file_lba_info lba_info[0];
};

struct file_crypto_data {
    int ci_key_len;
    int ci_key_index;
    u32 ci_metadata;
    u8 ci_key[0];
};

#define MAX_SEQ_NO (10000)

// filter drv
enum udx_filter_cmd {
    UDX_CMD_SET_INPUT_BUFFERQUEUE = 1,   // arg = buffer fd
    UDX_CMD_SET_OUTPUT_BUFFERQUEUE,      // arg = buffer fd
    UDX_CMD_ATTACH_BUFFER,               // arg = buffer fd
    UDX_CMD_MAP_BUFFER,                  // arg = buffer fd
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

enum udx_dfs_filter_cmd {
    UDX_DFS_CMD_OPEN_SESSION = 100,          // arg = filename/fd
    UDX_DFS_CMD_OPEN,          // arg = filename/fd
    UDX_DFS_CMD_CLOSE,               // arg = fd
    UDX_DFS_CMD_READ,                // arg = addr/size
    UDX_DFS_CMD_WRITE,               // arg = addr/size
    UDX_DFS_CMD_LSEEK,               // arg = offset
    UDX_DFS_CMD_UNLINK,              // arg = filename
    UDX_DFS_CMD_RENAME,              // arg = oldname/newname
    UDX_DFS_CMD_SET_FD_LIST,         // arg = fdlist/num
    UDX_DFS_CMD_SET_FILE_NAME_LIST,  // arg = filenamelist/num

    UDX_DFS_CMD_FREE,
};

#define UDX_DFS_IOCTL_CMD_OPEN_SESSION _IOW('u', UDX_DFS_CMD_OPEN_SESSION, unsigned long)
#define UDX_DFS_IOCTL_CMD_OPEN _IOW('u', UDX_DFS_CMD_OPEN, unsigned long)
#define UDX_DFS_IOCTL_CMD_CLOSE _IOW('u', UDX_DFS_CMD_CLOSE, unsigned long)
#define UDX_DFS_IOCTL_CMD_READ _IOW('u', UDX_DFS_CMD_READ, unsigned long)
#define UDX_DFS_IOCTL_CMD_WRITE _IOW('u', UDX_DFS_CMD_WRITE, unsigned long)
#define UDX_DFS_IOCTL_CMD_LSEEK _IOW('u', UDX_DFS_CMD_LSEEK, unsigned long)
#define UDX_DFS_IOCTL_CMD_UNLINK _IOW('u', UDX_DFS_CMD_UNLINK, unsigned long)
#define UDX_DFS_IOCTL_CMD_RENAME _IOW('u', UDX_DFS_CMD_RENAME, unsigned long)
#define UDX_DFS_IOCTL_CMD_SET_FD_LIST _IOW('u', UDX_DFS_CMD_SET_FD_LIST, unsigned long)
#define UDX_DFS_IOCTL_CMD_SET_FILE_NAME_LIST _IOW('u', UDX_DFS_CMD_SET_FILE_NAME_LIST, unsigned long)

struct udx_dfs_task_node {
    struct list_head list;
    u32 task_id;
    u32 task_state;
    u32 service_id;
    dma_addr_t file_list_paddr;
    void *file_list_vaddr;
    u64 file_list_len;
    dma_addr_t lba_paddr;
    void *lba_vaddr;
    u64 lba_len;
    struct list_head dma_buf_list;
    struct mutex dma_buf_list_mutex;
    struct kfifo msg_fifo;
    wait_queue_head_t waitq;
    void *private_data;
};

struct udx_dfs_msg {
    struct dmi_msg header;
    u32 task_id;
    u32 service_id;
    u8  buf[0];
};

struct udx_dfs_msg_data {
    u32 task_id;
    u32 service_id;
    u8  buf[0];
};

#define UDX_DFS_BUFFER_NODE_NUM            (2)
struct udx_dfs_ioctl_buffer {
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

struct udx_dfs_ioctl_buffer_info {
    unsigned int buf_fd;
    unsigned int buf_id;
    unsigned long long buf_addr;
    unsigned int buf_size;
};
struct udx_dfs_dma_buf_node {
    struct list_head list;
    struct dma_buf *dma_buf;
    struct dma_buf_attachment *attachment;
};

struct dfs_driver_data {
    struct mutex lock;
    struct list_head file_list;
    struct list_head dfa_list;
};

#define UDX_DFS_TASK_NUM_MAX 8
struct udx_dfs_info {
    struct device *dev;
    struct mutex task_list_mutex;
    struct list_head task_list;
    unsigned long *task_id_map;
};

#define DFS_MAX_PATH_NAME 256

struct udx_file_open_session_para {
    int session_id;
};

struct udx_file_open_para {
    char pathname[DFS_MAX_PATH_NAME];
    int flags;
    int fd;
    int pid;
    uint64_t size;
};

struct udx_file_close_para {
    char pathname[DFS_MAX_PATH_NAME];
    int fd;
};

struct udx_file_read_para {
    udx_buffer_queue_item read_buffer;
    int fd;
    int count;
};

struct udx_file_write_para {
    udx_buffer_queue_item write_buffer;
    int fd;
    int count;
};

struct udx_file_lseek_para {
    int fd;
    int offset;
};

struct udx_file_unlink_para {
    char pathname[DFS_MAX_PATH_NAME];
};

struct udx_file_rename_para {
    char oldpath[DFS_MAX_PATH_NAME];
    char newpath[DFS_MAX_PATH_NAME];
    int pid;
};

#define DFS_MAX_FILE_CNT 500
#define DFS_MAX_FILE_PATH_LEN 256
typedef struct {
    char file_name[DFS_MAX_FILE_PATH_LEN]; /* used only in open task */
    int32_t fd;
    uint64_t file_size;
} file_ctx;

typedef struct {
    int trans_id;
    int num;
    int pid;
    int nsid;
    file_ctx ctx_list[0];
} file_ctx_list;

struct udx_file_set_file_fd_para {
    int session_id;
    file_ctx_list file_list;
};

struct udx_dfs_set_file_fd_para {
    int session_id;
    uint64_t file_list_phy_addr;
    uint64_t file_list_len;
};

#pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
