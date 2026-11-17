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

#ifndef __SMS_FILTER_H__
#define __SMS_FILTER_H__

#include <linux/netdevice.h>
#include <bsp_dmi.h>

#define SMS_MSG_TYPE_FILTER     1

#define SMS_FILTER_CPU_DFT_PORT     0
#define SMS_FILTER_DPA_STACK_PORT   6
#define SMS_FILTER_WAN_PORT         7
#define SMS_FILTER_WLAN_PORT        8


#pragma pack(1)

enum sms_filter_opt {
    FILTER_OPT_ADD_ENTRY = 0,
    FILTER_OPT_DEL_ENTRY,
    FILTER_GET_DPA_PORT,
    FILTER_RETURN_DPA_PORT,
    FILTER_GET_WLAN_PORT,
    FILTER_RETURN_WLAN_PORT,
    FILTER_GET_WAN_PORT,
    FILTER_RETURN_WAN_PORT,
    FILTER_ENABLE_CPU_PORT,
    FILTER_CFG_PORT_DONE,
    FILTER_PM_VOTE_EN,
    FILTER_PM_VOTE_DIS,

    FILTER_OPT_MAX
};

union sms_filter_inet_addr {
    unsigned int ip4;
    unsigned int ip6[4];
};

struct sms_filter_tuple {
    union sms_filter_inet_addr laddr;
    union sms_filter_inet_addr raddr;
    unsigned short lport;
    unsigned short rport;
    unsigned short l3_prot; /* 0:ipv4/ 1:v6 */
    unsigned short l4_prot; /* 0:tcp/ 1:udp */
};

struct sms_filter_msg {
    enum sms_filter_opt opt;
    unsigned int usr_para;
};

#pragma pack()


#endif /* __SMS_FILTER_H__ */

