/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
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
#ifndef __GSO_H__
#define __GSO_H__

#include <bsp_dmi.h>
#include <bsp_print.h>

#undef THIS_MODU
#define THIS_MODU mod_gso

#define GSO_ERR(fmt, ...) do { \
    dpa_pr_err(fmt, ##__VA_ARGS__); \
} while (0)

#define GSO_SG_BD_NR_MAX 16 // payload 45 segs;

#pragma pack(1)
struct sg_bd_info {
    unsigned long long data : 40;
    unsigned long long offset : 32;
    unsigned long long len : 16;
};
#pragma pack()

#define DPA_SMS_USER_INFO_SIZE 48
#define DPA_SMS_HEADER_SIZE 128
struct gso_bd_para {
    unsigned long long dra_addr;
    unsigned int offload_flag : 16;
    unsigned int src_nic : 16;
    unsigned int gso_segs : 7;
    unsigned int sg_bd_nr : 7;
    unsigned int dra_idx : 18;
    unsigned int ifindex;
    unsigned int gso_len;
    unsigned int gso_mss;
    char cb[DPA_SMS_USER_INFO_SIZE];
    char header[DPA_SMS_HEADER_SIZE];
};

#pragma pack(1)
struct gso_bd_desc {
    struct gso_bd_para para; // if need add bd info, must in struct gso_bd_para
    struct sg_bd_info sg_info[GSO_SG_BD_NR_MAX];
};
#pragma pack()

struct gso_stat {
    int version;
    unsigned int msg_send_success;
    unsigned int dra_map_fail;
    unsigned int nfrags_more_err;
    unsigned int msg_send_fail;
    unsigned int no_gso_size;
    unsigned int tcp_wfree;
    unsigned int reset_send_fail;
    unsigned int dmi_alloc_fail;
    unsigned int build_msg_fail;
    unsigned int send_msg_fail;
    unsigned int tx_unblock;
};

struct gso_ctrl {
    unsigned int type_print_cnt;
    unsigned int memcpy_fail;
};

#define GSO_RESET 11

struct gso_ctx {
    spinlock_t lock;
    unsigned int dpa_stat;
    struct gso_ctrl ctrl;
    struct gso_stat stat;
    struct net_om_info om_info;
    void (*unblock_cb)(void);
};

#endif /* __GSO_H__ */