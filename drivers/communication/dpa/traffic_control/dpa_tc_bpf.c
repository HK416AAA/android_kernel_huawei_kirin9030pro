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
#include <linux/types.h>
#include <linux/filter.h>
#include <linux/bpf-cgroup.h>
#include <linux/netdevice.h>
#include <linux/rculist.h>
#include <net/sock.h>

#include "dpa_tc_interface.h"
#include "dpa_tc_util.h"
#include "dpa_tc_hidis.h"

static int g_iface_map_exist = 0;
static char g_iface_stats_prog[] = "/sys/fs/bpf/netsys/progs/socket_iface_stats";

void bpf_obj_pin_priv_cb(const char __user *pathname, void *raw, int type)
{
    char buf[MAX_MAP_NAME_LEN] = {0};
    int len = 0;
    struct bpf_prog *prog = NULL;

    if (unlikely(!pathname )){
        TC_PRINT_ERR("error, para pathname is null\n");
        return ;
    }
    if (unlikely(!raw)){
        TC_PRINT_ERR("error, para raw is null\n");
        return ;
    }

    len = strncpy_from_user(buf, pathname, MAX_MAP_NAME_LEN - 1);
    if (unlikely(len < 0)){
        TC_PRINT_ERR("copy map path from user space failed\n");
        return ;
    }
    if (type == BPF_TYPE_PROG) {
        prog = raw;
        if (strnstr(buf, g_iface_stats_prog, len) != NULL) {
            TC_PRINT_ERR("BPF PROG %s match ok \n", g_iface_stats_prog);
            prog->aux->pin_stat = 1;
            g_iface_map_exist = 1;
        } else {
            prog->aux->pin_stat = 0;
        }
    } else if (type == BPF_TYPE_MAP) {
        tc_save_map((struct bpf_map *)raw, buf, len);
    }
    return;
}


static inline int tc_deliver_skb(struct sk_buff *skb, struct packet_type *pt_prev, struct net_device *orig_dev)
{
    struct sock *sk;
    struct sk_filter *filter;

    if (unlikely(skb_orphan_frags_rx(skb, GFP_ATOMIC)))
        return -ENOMEM;


    sk = pt_prev->af_packet_priv;

    // 获取socket上的bpf上下文
    filter = rcu_dereference(sk->sk_filter);

    // 判断是否为网卡流量统计的BPF
    if (filter && filter->prog && filter->prog->aux &&filter->prog->aux->pin_stat) {
	    int ret;
        refcount_inc(&skb->users);
        TC_PRINT_IFSTAT(skb);
        ret = pt_prev->func(skb, skb->dev, pt_prev, orig_dev);
        TC_PRINT_IFSTAT(skb);
        return ret;
    }

    return 0;
}

int tc_traverse_ptype(struct sk_buff *skb)
{
    if (unlikely(!skb)){
        TC_PRINT_ERR("error, skb is null!\n");
        return 0;
    }


    if (g_iface_map_exist) {
        struct packet_type *ptype;
        struct net_device *orig_dev = skb->dev;
        rcu_read_lock();
        list_for_each_entry_rcu(ptype, &ptype_all, list)
        {
            if (ptype)
                tc_deliver_skb(skb, ptype, orig_dev);
        }
        rcu_read_unlock();
    }

    return 0;
}

int dpa_tc_init(void)
{
    dpa_tc_statistics_reset();
    dpa_tc_hidis_report_register();
    bpf_obj_pin_priv_func_register((void *)bpf_obj_pin_priv_cb);
    
    TC_PRINT_ERR("dpa_traffic_ctrl_init ok\n");
    return 0;
}
