/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
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
#ifndef __MODEM_AGING_H__
#define __MODEM_AGING_H__

#include <linux/netlink.h>
#include <net/genetlink.h>
#include <linux/skbuff.h>
#include <osl_types.h>
#include <osl_sem.h>
#include <mdrv_msg.h>
#include <bsp_print.h>
#include <bsp_msg.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#undef THIS_MODU
#define THIS_MODU mod_modem_aging

#define modem_aging_err(fmt, ...) (bsp_err("<%s> <%d> " fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__))

#define MODEM_AGING_GENL_NAME "mdm_aging_genl"
#define MODEM_AGING_GENL_VERSION 0x1

#define MODEM_AGING_GENL_RECV_MAX_LEN 0x1000

#define MODEM_AGING_RESP_RETRY_MAX_CNT     3
#define MODEM_AGING_RESP_RETRY_MSLEEP_TIME 1

enum modem_aging_genl_cmd {
    MODEM_AGING_GENL_CMD_NONE,
    MODEM_AGING_GENL_CMD_NV,
    MODEM_AGING_GENL_CMD_BUTT
};

struct modem_aging_conn_info {
    struct net *net;
    u32 port_id;
    osl_sem_id chan_sem;
    msg_chn_t msglite_chan;
};

typedef struct {
    struct genl_family family;
    struct modem_aging_conn_info con_info;
} modem_aging_genl_ctrl_s;

typedef struct {
    MDRV_MSG_HEAD
    char data[0];
} modem_aging_msg_head_s;

typedef struct {
    unsigned int cmd;
    unsigned short crc;
    unsigned short crc_rsv;
    char data[0];
} modem_aging_app_cmd_pkt_s;

typedef struct {
    unsigned int cmd;
    unsigned int result;
} modem_aging_resp_s;

// #define MODEM_AGING_GENL_DATA_SIZE (NLMSG_DEFAULT_SIZE - GENL_HDRLEN - sizeof(modem_aging_genl_unicast_msg_s))
// #define MODEM_AGING_GENL_UNICAST_MSG_ARGS_SIZE(_m) (sizeof(((modem_aging_genl_unicast_msg_s *)0)->_m))

int modem_aging_genl_rcv_handler(struct sk_buff *skb, struct genl_info *info);
int modem_aging_genl_send_data(unsigned char *buf, unsigned int len);
int modem_aging_msg_send(unsigned char *data, unsigned int len);
int modem_aging_init(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif /*  __MODEM_AGING_H__ */
