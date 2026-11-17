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
#ifndef _DPA_LOADER_DUMP_H_
#define _DPA_LOADER_DUMP_H_

#define DPA_LOADER_IMG_LOAD_INFO_MAX 4

enum dpa_loader_dump_stage {
    INIT_STAGE = 0,
    LOAD_IMAGE_STAGE,
};

enum dpa_loader_dump_proc {
    DPA_LOADER_INIT_START = 0x1000,
    DPA_FIRMWARE_RESET = DPA_LOADER_INIT_START,
	DPA_LOADER_INIT_MAX_PROC, /* 不记录该proc */

    DPA_LOADER_LOAD_IMAGE_START = 0x2000, /* 镜像加载流程 */
    DPA_LOADER_VERIFY_VRL_SIZE = DPA_LOADER_LOAD_IMAGE_START,
    DPA_LOADER_FILE_OPEN,
    DPA_LOADER_VERIFY_PREPARE,
    DPA_LOADER_LOAD_VRL,
    DPA_LOADER_SEND_VRL,
    DPA_LOADER_LOAD_DATA,
    DPA_LOADER_IMG_VERIFY,
    DPA_LOADER_LOAD_IMAGE_MAX_PROC, /* 不记录该proc */
};

struct dpa_loader_dump_final_info {
    uint32_t result;
    uint32_t final_proc;
};

struct dpa_loader_dump_node {
    uint32_t proc;
    uint32_t proc_result;
    uint32_t slice[2U]; // [0] start, [1] end
};

struct mloader_dump_init_node {
    struct dpa_loader_dump_node nodes[DPA_LOADER_INIT_MAX_PROC - DPA_FIRMWARE_RESET];
};
struct dpa_loader_dump_load_img_node {
    char img_name[32];
    uint32_t load_retry_times;
    struct dpa_loader_dump_final_info final_info;
    struct dpa_loader_dump_node nodes[DPA_LOADER_LOAD_IMAGE_MAX_PROC - DPA_LOADER_LOAD_IMAGE_START]; // 5*16
};

struct dpa_loader_dump_info {
    uint32_t magic;
    uint32_t load_img_trace;
    struct mloader_dump_init_node loader_init_info[1U];
    struct dpa_loader_dump_load_img_node img_load_info[DPA_LOADER_IMG_LOAD_INFO_MAX];
};

void dpa_loader_dump_init_start(enum dpa_loader_dump_proc proc);
void dpa_loader_dump_init_end(enum dpa_loader_dump_proc proc, int32_t ret);
void dpa_loader_dump_img_load_start(const char *img_name, unsigned int retry_times);
void dpa_loader_dump_img_load_proc_start(enum dpa_loader_dump_proc proc);
void dpa_loader_dump_img_load_proc_end(enum dpa_loader_dump_proc proc, int32_t ret);
void dpa_loader_dump_img_load_end(void);
int dpa_loader_dump_init(void);
void dpa_loader_dump_clear_info(void);

#endif
