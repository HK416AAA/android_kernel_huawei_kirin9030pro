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
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS"
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

#ifndef DPA_PFA_INTERFACE_H
#define DPA_PFA_INTERFACE_H

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

enum pfa_ip_conntrack_status {
    IPS_PFA_FORWARD_BIT = 0,
    IPS_PFA_FORWARD = (1 << IPS_PFA_FORWARD_BIT),

    IPS_PFA_CONFIRMED_BIT = 1,
    IPS_PFA_CONFIRMED = (1 << IPS_PFA_CONFIRMED_BIT),
};

struct pfa_hook_ops {
    /* ip forward interface */
    void (* ipfw_entry_add)(void *n, void *skb);
    void (* ipfw_entry_del)(void *ct);
    int (* is_updateonly)(void *skb);
};

#ifdef CONFIG_DPA_API
void dpa_pfa_api_register(struct pfa_hook_ops *pfa_ops);
void pfa_ipfw_entry_add_ops(void *n, void *skb);
void pfa_ipfw_entry_del_ops(void *ct);
int pfa_is_updateonly_ops(void *skb);
#else
static inline void dpa_pfa_api_register(struct pfa_hook_ops *pfa_ops)
{
}

static inline void pfa_ipfw_entry_add_ops(void *n, void *skb)
{
}

static inline void pfa_ipfw_entry_del_ops(void *ct)
{
}

static inline int pfa_is_updateonly_ops(void *skb)
{
    return 0;
}
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* DPA_PFA_INTERFACE_H */
