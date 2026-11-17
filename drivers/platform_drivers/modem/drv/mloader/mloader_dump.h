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
#ifndef _MLOADER_DUMP_H_
#define _MLOADER_DUMP_H_

#define MLOADER_IMG_LOAD_INFO_MAX 4

enum mloader_dump_stage {
    INIT_STAGE = 0,
    MSG_STAGE,
    LOAD_IMAGE_STAGE,
    NOTIFY_MCU_STAGE,
    BOOT_TIME_STAGE,
};

enum mloader_dump_proc {
    MLOADER_INIT_START = 0x1000, /* loader初始化流程 */
    MLOADER_LOADER_GET_DTS = MLOADER_INIT_START,
    MLOADER_LOADER_EARLY_INIT,
    MLOADER_PROBE_START,
    MLOADER_START,
    MLOADER_NV,
    MLOADER_CCPU_RESET,
    MLOADER_INIT_MAX_PROC, /* 不记录该proc */

    MLOADER_MSG_FROM_CP = 0x2000,
    MLOADER_MSG_TO_CP,
    MLOADER_MSG_MAX, /* 不记录该proc */

    MLOADER_LOAD_IMAGE_START = 0x3000, /* 镜像加载流程 */
    MLOADER_GET_FILE_PATH = MLOADER_LOAD_IMAGE_START,
    MLOADER_VERIFY_VRL_SIZE,
    MLOADER_FILE_OPEN,
    MLOADER_VERIFY_PREPARE,
    MLOADER_LOAD_VRL,
    MLOADER_SEND_VRL,
    MLOADER_LOAD_DATA,
    MLOADER_IMG_VERIFY,
    MLOADER_LOAD_IMAGE_MAX_PROC, /* 不记录该proc */

    MLOADER_NOTIFY_MCU_START = 0x4000, /* 通知MCU解复位 */ 
    MLOADER_NOTIFY_MCU_END,

    MLOADER_BOOT_TIME_START = 0x5000,
    MLOADER_BOOT_TIME_END,
};

struct mloader_dump_final_info {
    uint32_t result;
    uint32_t final_proc;
};

struct mloader_dump_node {
    uint32_t proc;
    uint32_t proc_result;
    uint32_t slice[2U]; // [0] start, [1] end
};

struct mloader_dump_init_node {
    struct mloader_dump_final_info final_info;
    struct mloader_dump_node nodes[MLOADER_INIT_MAX_PROC - MLOADER_INIT_START];
};

struct mloader_dump_msg_node {
    struct mloader_dump_node nodes[MLOADER_MSG_MAX - MLOADER_MSG_FROM_CP]; // 7*16
};

struct mloader_dump_boot_time_node {
    struct mloader_dump_node nodes[MLOADER_BOOT_TIME_END - MLOADER_BOOT_TIME_START]; // 7*16
};

struct mloader_dump_notify_mcu_node {
    struct mloader_dump_node nodes[MLOADER_NOTIFY_MCU_END - MLOADER_NOTIFY_MCU_START];
};

struct mloader_dump_load_img_node {
    char img_name[32];
    uint32_t load_retry_times;
    struct mloader_dump_final_info final_info;
    struct mloader_dump_node nodes[MLOADER_LOAD_IMAGE_MAX_PROC - MLOADER_LOAD_IMAGE_START]; // 5*16
};

struct mloader_dump_info {
    uint32_t magic;
    uint32_t load_img_trace;
    struct mloader_dump_init_node loader_init_info[1U];
    struct mloader_dump_msg_node msg_info[1U];
    struct mloader_dump_load_img_node img_load_info[MLOADER_IMG_LOAD_INFO_MAX];
    struct mloader_dump_notify_mcu_node notify_mcu_info[1U];
    struct mloader_dump_boot_time_node boot_time_info[1U];
};

void mloader_dump_driver_init_start(void);
void mloader_dump_driver_init_proc_start(enum mloader_dump_proc proc);
void mloader_dump_driver_init_proc_end(enum mloader_dump_proc proc, int32_t ret);
void mloader_dump_driver_init_end(void);
void mloader_dump_msg_start(enum mloader_dump_proc proc);
void mloader_dump_msg_end(enum mloader_dump_proc proc, int32_t ret);
void mloader_dump_img_load_start(const char *img_name, unsigned int retry_times);
void mloader_dump_img_load_proc_start(enum mloader_dump_proc proc);
void mloader_dump_img_load_proc_end(enum mloader_dump_proc proc, int32_t ret);
void mloader_dump_img_load_end(void);
void mloader_dump_notifier_mcu_start(void);
void mloader_dump_notifier_mcu_end(int32_t ret);
void mloader_dump_boot_time_start(void);
void mloader_dump_boot_time_end(void);
void mloader_dump_init(void);
void mloader_dump_clear_info(void);

#endif
