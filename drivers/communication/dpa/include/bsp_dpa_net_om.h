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

#ifndef __BSP_DPA_NET_OM_H__
#define __BSP_DPA_NET_OM_H__

#include <linux/list.h>

// 枚举名称需要同步到tools仓，不然hids上报名称会是msg_id
enum net_om_report_msg_type {
    /* msgid for trans debug info for hids */
    DPA_HOST_NET_OM_DFX_CONN_STATS_INFO= 0x9f380520,
    DPA_HOST_NET_OM_DFX_SOCK_INFO = 0x9f380521,
    DPA_HOST_NET_OM_TC_STATS = 0x9f380522,
    DPA_HOST_NET_OM_SMX_TX = 0x9f380523,
    DPA_HOST_NET_OM_DPA_ADD_TUPLE = 0x9f380524,
    DPA_HOST_NET_OM_DPA_DEL_TUPLE = 0x9f380525,
    DPA_HOST_NET_OM_HOST_DMI = 0x9f380526,
    DPA_HOST_NET_OM_SMS_RX = 0x9f380527,
    DPA_HOST_NET_OM_MAX = 0x9f38053f,
};

struct net_om_info {
    unsigned int ul_msg_id;
    void *data;
    unsigned int size;
    void (*func_cb)(void);
    struct list_head list;
};

#ifdef CONFIG_DPA_NET_OM
int bsp_dpa_net_report_register(struct net_om_info *info);
#else
static inline int bsp_dpa_net_report_register(struct net_om_info *info){return 0;}
#endif


#endif