/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2025. All rights reserved.
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

#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/netfilter_ipv6.h>

#include "dpa_tc_interface.h"
#include "dpa_tc_util.h"

/*每条链上的最大表数量*/
#define MAX_PRO_NUMS (6)

/*为加速查找（netfilter中各表项挂载后，按照优先级数值从小达到排列），因此，如下各表项优先级填写时注意：
    所有表项的优先级数值建议按照从小到大排列，加速查找。
    无效表项放置在最后，使用INT_MIN填充，代表无效值。
*/

int g_ip4_netfilter[NF_INET_NUMHOOKS][MAX_PRO_NUMS] = {
    {NF_IP_PRI_RAW, NF_IP_PRI_CONNTRACK, NF_IP_PRI_MANGLE, NF_IP_PRI_NAT_DST, INT_MIN, INT_MIN},
    {NF_IP_PRI_MANGLE, NF_IP_PRI_FILTER, NF_IP_PRI_FILTER + 2, NF_IP_PRI_NAT_SRC, NF_IP_PRI_CONNTRACK_CONFIRM, INT_MIN},
    {NF_IP_PRI_MANGLE, NF_IP_PRI_FILTER, INT_MIN, INT_MIN, INT_MIN, INT_MIN},
    {NF_IP_PRI_RAW, NF_IP_PRI_CONNTRACK, NF_IP_PRI_MANGLE, NF_IP_PRI_NAT_DST, NF_IP_PRI_FILTER, NF_IP_PRI_FILTER + 2},
    {NF_IP_PRI_MANGLE, NF_IP_PRI_NAT_DST, NF_IP_PRI_CONNTRACK_CONFIRM, INT_MIN, INT_MIN, INT_MIN}};

int g_ip6_netfilter[NF_INET_NUMHOOKS][MAX_PRO_NUMS] = {
    {NF_IP6_PRI_RAW, NF_IP6_PRI_CONNTRACK, NF_IP6_PRI_MANGLE, NF_IP6_PRI_NAT_DST, INT_MIN, INT_MIN},
    {NF_IP6_PRI_MANGLE, NF_IP6_PRI_FILTER, NF_IP_PRI_FILTER + 2, NF_IP6_PRI_NAT_SRC, NF_IP6_PRI_LAST, INT_MIN},
    {NF_IP6_PRI_MANGLE, NF_IP6_PRI_FILTER, INT_MIN, INT_MIN, INT_MIN, INT_MIN},
    {NF_IP6_PRI_RAW, NF_IP6_PRI_CONNTRACK, NF_IP6_PRI_MANGLE, NF_IP6_PRI_NAT_DST, NF_IP6_PRI_FILTER, NF_IP_PRI_FILTER + 2},
    {NF_IP6_PRI_MANGLE, NF_IP6_PRI_NAT_DST, NF_IP6_PRI_LAST, INT_MIN, INT_MIN, INT_MIN}};

/*nf hook null callback func*/
static int okfn_null(struct net *n, struct sock *sk, struct sk_buff *skb)
{
    return 0;
}

static inline void tc_nf_hook_state_init(struct nf_hook_state *p, unsigned int hook, u_int8_t pf,
    struct net_device *indev, struct net_device *outdev, struct sock *sk, struct net *net)
{
    p->hook = hook;
    p->pf = pf;
    p->in = indev;
    p->out = outdev;
    p->sk = sk;
    p->net = net;
    p->okfn = okfn_null;
}

/* Caller must hold rcu_read_lock. */
static int tc_nf_hook_slow(
    struct sk_buff *skb, struct nf_hook_state *state, const struct nf_hook_entries *e, unsigned int s, int *pri_sets)
{
    unsigned int verdict;
    unsigned int n = e->num_hook_entries;
    struct nf_hook_ops **orig_ops = (struct nf_hook_ops **)&e->hooks[n];
    unsigned int p_index = 0;

    TC_PRINT_DEBUG("check hook %d entry begin", state->hook);

    for (; s < e->num_hook_entries && p_index < MAX_PRO_NUMS;) {
        // 如果优先级表已经遍历至无效项，则不再匹配，退出
        if (pri_sets[p_index] == INT_MIN) {
            break;
        }
        // 如果当前规则表优先级低于优先级表中当前项，则当前规则不处理，获取下一个规则处理
        if (orig_ops[s]->priority < pri_sets[p_index]) {
            s++;
            continue;
        } else if (orig_ops[s]->priority > pri_sets[p_index]) {  // 如果当前规则表优先级高于优先级表中当前项，则当前规则不处理，获取下一个优先级表项进行对比
            p_index++;
            continue;
        }

        /*当前规则表优先级等于优先级表中当前项，进行处理，处理完毕后获取下一个规则表进行处理*/
        TC_PRINT_DEBUG("check index %d pri %d ", s, orig_ops[s]->priority);
        verdict = nf_hook_entry_hookfn(&e->hooks[s], skb, state);
        switch (verdict & NF_VERDICT_MASK) {
            case NF_ACCEPT:
                break;
            case NF_DROP:
                TC_PRINT_WARN("return DROP ,check index %d pri %d ret %d\n", s, orig_ops[s]->priority, verdict & NF_VERDICT_MASK);
                return NF_DROP;
            default:
                TC_PRINT_WARN("return not ACCEPT or DROP ,check index %d pri %d ret %d\n", s, orig_ops[s]->priority, verdict & NF_VERDICT_MASK);
                return NF_ACCEPT;
        }
        s++;
    }
    TC_PRINT_DEBUG("check hook %d entry  end", state->hook);
    return NF_ACCEPT;
}

int tc_nf_hook(uint8_t pf, unsigned int hook, struct net *net, struct sock *sk, struct sk_buff *skb,
    struct net_device *in, struct net_device *out)
{
    struct nf_hook_entries *hook_head = NULL;
    int *pri_sets = NULL;
    int ret = NF_ACCEPT;

    if (unlikely(!skb)) {
        TC_PRINT_ERR("error, skb is null\n");
        return NF_ACCEPT;
    }
    if (unlikely(hook >= NF_INET_NUMHOOKS)) {
        TC_PRINT_ERR("error, hook %u overflow\n", hook);
        return NF_ACCEPT;
    }

    rcu_read_lock();
    switch (pf) {
        case NFPROTO_IPV4:
            hook_head = rcu_dereference(net->nf.hooks_ipv4[hook]);
            pri_sets = g_ip4_netfilter[hook];
            break;
        case NFPROTO_IPV6:
            hook_head = rcu_dereference(net->nf.hooks_ipv6[hook]);
            pri_sets = g_ip6_netfilter[hook];
            break;
        default:
            WARN_ON_ONCE(1);
            break;
    }

    if (hook_head) {
        struct nf_hook_state state;
        tc_nf_hook_state_init(&state, hook, pf, in, out, sk, net);
        ret = tc_nf_hook_slow(skb, &state, hook_head, 0, pri_sets);
    }
    rcu_read_unlock();

    return ret;
}