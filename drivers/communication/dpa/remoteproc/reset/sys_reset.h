/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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

#ifndef SYS_RESET_H_
#define SYS_RESET_H_

#include <bsp_dmi.h>

#define SYS_RESET_FW_TIMEOUT 500

// dpa_host下发到fw的msg长度
#define SYS_RESET_MSG_LEN 4
#define SYS_RESET_ALIGN_SIZE 4

#define SYS_RESET_ERR_GEN(val) (0x80000000 | (val))

#define SYS_RESET_MODS_FAILCNT_MASK 0xFFFF
#define SYS_RESET_GET_SYS_TYPE(val) ((val) >> 24U)
#define SYS_RESET_GET_OPS_TYPE(val) (((val) >> 16U) & 0xFFU)
#define SYS_RESET_GET_FAILCNT(val) ((val) & SYS_RESET_MODS_FAILCNT_MASK)

#define SYS_RESET_DUMP_PASS 0xEEDD0000
#define SYS_RESET_DUMP_FAIL 0x0000EEDD

enum sys_reset_fw_status {
    SYS_RESET_DPA_FW_INIT,
    SYS_RESET_DPA_FW_DOING,
    SYS_RESET_DPA_FW_FINSH,
};

/**
 * @brief 子系统复位类型
 */
typedef enum {
    SYS_MODEM_RESET,
    SYS_WIFI_RESET,
    RESET_TYPE_MAX
} sys_reset_type_e;

enum sys_reset_err {
    SYS_RESET_INIT_DUMP_ERR,
    SYS_RESET_MSG_RECV_ERR,
    SYS_RESET_MSG_MALLOC_ERR,
    SYS_RESET_MSG_WAIT_FW_TIMEOUT,
    SYS_RESET_INPUT_ERR,
};

enum sys_reset_handle_stamp {
    SYS_RESET_GET_WAKELOCK,
    SYS_RESET_HANDLE_START,
    SYS_RESET_IPC_REQ,
    SYS_RESET_IPC_START,
    SYS_RESET_DMI_IPC_SET_FLAG,
    SYS_RESET_WAIT_DONE,
    SYS_RESET_RELEASE_WAKELOCK,
    SYS_RESET_DUMP_STAMP_MAX_NUM,
};

typedef struct {
    unsigned int dump_type;
    unsigned int slice;
    unsigned int result;
    unsigned int arg;
} sys_reset_dump_item_s;
#define SYS_RESET_DUMP_SINGLE_HANDLE_SIZE (SYS_RESET_DUMP_STAMP_MAX_NUM * sizeof(sys_reset_dump_item_s))
#define SYS_RESET_DUMP_SIZE (SYS_RESET_DUMP_SINGLE_HANDLE_SIZE * 4)

typedef struct sys_reset_mod_ctrl {
    unsigned int status;
    unsigned int result;
    struct completion wait_completion;
} sys_reset_mod_ctrl_s;

typedef struct {
    sys_reset_mod_ctrl_s sys_ctrl[RESET_TYPE_MAX];
    uintptr_t dump_addr;
} sys_reset_ctrl_s;

#endif // SYS_RESET_H_
