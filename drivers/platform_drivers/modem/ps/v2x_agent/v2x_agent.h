/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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

#ifndef __IOT_V2X_AGENT_H__
#define __IOT_V2X_AGENT_H__

#include <linux/cdev.h>
#include <linux/types.h>
#include <mdrv_fipc.h>

#define V2X_DEVICE_CLASS "v2x_class"
#define V2X_APP_MAX (2)
#define V2X_FIRST_MINOR 0
#define V2X_DEVICES_NUMBER 1
#define FIPC_BUFFER_CACHE_ALINED (128)
#define V2X_PIPE_BUFFER_SIZE (128 * 12 * 2)
#define FIPC_BUFFER_BD_SIZE (12)
#define V2X_DATA_BUFFER_OVERFLOW_SIZE (10 * 1024)
#define V2X_RING_BUFFER_OVERFLOW_SIZE (5 * FIPC_BUFFER_BD_SIZE)

#define CRYPTO_ENGINE_MONITOR_TIMEROUT (1 * 1000000) // 1s
#define V2X_DOWNLINK_MSG_UP (300) // CRYPTO_ENGINE调配阈值上限
#define V2X_DOWNLINK_MSG_FLOOR (250) // CRYPTO_ENGINE调配阈值下限

struct v2x_agent_fipc_handle {
    fipc_chn_t send_handle;
    void *send_va __attribute__((aligned(8)));
    dma_addr_t send_pa __attribute__((aligned(8)));
    unsigned int send_buffer_size;

    fipc_chn_t recv_handle;
    void *recv_va __attribute__((aligned(8)));
    dma_addr_t recv_pa __attribute__((aligned(8)));
    unsigned int recv_buffer_size;
};

struct fipc_operation {
    int (*get_uplink_rptr)(unsigned int *rptr);
    int (*send_uplink_data)(void *dma_addr, unsigned int data_size, int flags);

    int (*get_downlink_rptr)(unsigned int *rptr);
    int (*get_downlink_wptr)(unsigned int *wptr);
    int (*set_downlink_rptr)(unsigned int rptr);

    int (*fipc_recv_cb)(fipc_event event, void *arg, const fipc_eventinfo *event_info);
    int (*fipc_send_cb)(fipc_event event, void *arg, const fipc_eventinfo *event_info);
};

struct v2x_dev_info {
    struct cdev cdev;
    dev_t dev_no;
    struct class *v2x_class;
    struct device *device;
};

#define ZA_SIZE 32
#define PRIVATE_KEY_SIZE 32

struct crypto_gm_data_info {
    unsigned int verify_type; // 当前支持的算法类型，SIGNATURE_SM2 = 0,
    unsigned char private_key[PRIVATE_KEY_SIZE]; // 私钥数据
    unsigned char signature_za[ZA_SIZE]; // 签名ZA数据
};

#define V2X_BYPASS_VERSION (1)
#define V2X_BYPASS_TYPE (1)
#define V2X_VERIFY_TYPE (2)

struct v2x_bypass_info {
    unsigned short version;
    unsigned short type;
    unsigned int len;
};

typedef struct {
    uint8_t sign[2];
    uint8_t dataType;
    uint8_t ueId;
    uint32_t sequenceNumber;
} V2xAppDataInfo;

enum SVC_V2X_CMD_ID {
    V2X_CMD_ID_INVALID = 0x0,
    V2X_CMD_ID_SIGN,
    V2X_CMD_ID_IMPORT_KEY,
};

enum SVC_V2X_KEY_SAVE_TYPE {
    V2X_KEY_SAVE_STORAGE = 0x0,
    V2X_KEY_SAVE_MEMORY,
};

#define SM2_MSG_HASH_LEN 32
#define SM2_DATA_SIGN_LEN 64
#define SM2_PRIVATE_KEY_LEN 32
#define SM2_PUBLIC_KEY_LEN 64
#define SM2_ZA_LEN 32

struct v2x_key_pair_info {
    uint8_t privkey_buf[SM2_PRIVATE_KEY_LEN];
    uint8_t pubkey_buf[SM2_PUBLIC_KEY_LEN];
};

struct v2x_key_ree_info {
    uint32_t key_save_type;
    uint32_t key_id;
    struct v2x_key_pair_info key_pair;
};

struct v2x_sign_info_in {
    uint32_t key_save_type;
    uint32_t key_id;
    uint8_t msg_hash_buf[SM2_MSG_HASH_LEN];
};

struct v2x_sign_info_out {
    uint32_t sign_result;
    uint8_t out_sign_buf[SM2_DATA_SIGN_LEN];
};

struct v2x_sign_info {
    struct v2x_sign_info_in sign_info_in;
    struct v2x_sign_info_out sign_info_out;
};

# define DATA_CMP_FAIL (1)
struct v2x_agent_info {
    struct v2x_dev_info v2x_dev;
    struct device *dev;
    struct workqueue_struct *wq;
    struct crypto_gm_data_info crypto_gm_data;
    struct v2x_key_ree_info key_info;
    struct v2x_sign_info sign_info;
    struct work_struct ltev_work;
    struct work_struct import_key_work;
    struct work_struct sign_work;
    struct semaphore sem_ltev;
    struct semaphore sem_downlink;
    struct fipc_operation ops;
    struct v2x_agent_fipc_handle *fipc_handle;
    void *downlink_data_buffer __attribute__((aligned(8)));
    dma_addr_t downlink_dma_addr __attribute__((aligned(8)));
    volatile unsigned int downlink_rptr;
    volatile unsigned int downlink_wptr;
    unsigned int downlink_intr_count;
    unsigned int downlink_ltev_count;

    void *uplink_data_buffer __attribute__((aligned(8)));
    dma_addr_t uplink_dma_addr __attribute__((aligned(8)));
    volatile unsigned int uplink_rptr;
    volatile unsigned int uplink_wptr;
    unsigned int uplink_intr_count;
    unsigned int uplink_opipe_map_buffer[V2X_PIPE_BUFFER_SIZE / FIPC_BUFFER_BD_SIZE];
    unsigned int uplink_opipe_map_index;

    unsigned int timer_intr_count;
    unsigned int crypto_engine_freq_high;
    unsigned int pm_status;
    unsigned int dev_status;
    unsigned int user_state;
    unsigned int test_flags;
    unsigned int test_buffer_size;
    void *test_buffer;
    unsigned int data_cmp_result;
};

enum v2x_agent_state {
    V2X_NO_USER = 0,
    V2X_APP_RUNNING = 1,
    V2X_LTEV_RUNNING = 2,
};

enum v2x_dev_state {
    V2X_DEV_CLOSE = 0,
    V2X_DEV_OPEN_ONECE = 1,
    V2X_DEV_OPEN_TWICE,
};

enum v2x_agent_test_flags {
    V2X_LOOP_TEST_MODE = (1 << 0),
    V2X_MEMCMP_TEST_MODE = (1 << 1),
    V2X_RANDON_LEN_MODE = (1 << 2),
    V2X_DSM_SEND_MODE = (1 << 3),
};

/* cmd枚举添加需同步修改teeos\drivers\crypto_gm\crypto_gm.c */
enum crypto_gm_op_cmd {
    CRYPTO_GM_CMD_MIN = 0x100,
    CRYPTO_GM_CMD_SET_PRIVKEY,     /* ------配置crypto_gm 私钥字段CMD------ */
    CRYPTO_GM_CMD_SET_SIGN_ZA,     /* ------配置crypto_gm 签名ZA字段CMD------ */

    CRYPTO_GM_CMD_MAX,
};

#define UP_BUFFER_PTR(ptr) (ptr + V2X_DATA_DOWNLINK_BUFFER_SIZE)
#define V2X_EICC_ALIGN_LEN_4(len) (((len) & 3)? (((len) >> 2) + 1) << 2 : (len))
#define get_timer_count_delta(begin, end) (((end) >= (begin)) ? ((end) - (begin)) : ((0xFFFFFFFF - (begin)) + (end)))
struct v2x_agent_info *bsp_v2x_agent_get_info(void);
struct v2x_agent_dump_t *v2x_agent_get_debug_info(void);
int v2x_agent_debugfs_init(void);
int v2x_agent_print_debug_info(void);

#define DATA_256                                                                                                      \
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, \
        0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24,   \
        0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,   \
        0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,   \
        0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a,   \
        0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c,   \
        0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e,   \
        0x7f, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90,   \
        0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 0xa0, 0xa1, 0xa2,   \
        0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,   \
        0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6,   \
        0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8,   \
        0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf, 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea,   \
        0xeb, 0xec, 0xed, 0xee, 0xef, 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc,   \
        0xfd, 0xfe, 0xff

#define DATA_1K DATA_256, DATA_256, DATA_256, DATA_256
#define DATA_4K DATA_1K, DATA_1K, DATA_1K, DATA_1K
#define DATA_16K DATA_4K, DATA_4K, DATA_4K, DATA_4K
#endif
