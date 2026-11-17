/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
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
 */

#include <net/sock.h>
#include <linux/in.h>
#include <linux/cpu.h>
#include <linux/skbuff.h>
#include <linux/capability.h>
#include <linux/workqueue.h>
#include <linux/module.h>
#include "rnic_vnet.h"
#include "rnic_vnet_cfg.h"
#include "rnic_vnet_hdlr.h"
#include "rnic_log.h"
#include "rnic_private.h"
#include "rnic_vnet_rx_sched.h"

STATIC struct rnic_vnet_rx_wq_ctx_s *work_stats_ptr;

unsigned int rnic_rx_sched_enable = 1;
module_param(rnic_rx_sched_enable, uint, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(rnic_rx_sched_enable, "rnic rx sched enable");

void rnic_vnet_rx_data_add_list(struct sk_buff_head *rx_list, struct sk_buff *pskb)
{
	struct rnic_vnet_rx_wq_ctx_s *work_stats = work_stats_ptr;
	if (likely(work_stats != NULL && work_stats->enabled))
		__skb_queue_tail(&work_stats->rx_list, pskb);
	else
		__skb_queue_tail(rx_list, pskb);
}

int rnic_vnet_rx_wq_empty(void)
{
	struct rnic_vnet_rx_wq_ctx_s *work_stats = work_stats_ptr;
	return work_stats != NULL ? skb_queue_empty(&work_stats->rx_list) : 1;
}

void rnic_vnet_rx_start_kwork(void)
{
	struct rnic_vnet_rx_wq_ctx_s *work_stats = work_stats_ptr;

	spin_lock_bh(&work_stats->rx_pend_list.lock);
	skb_queue_splice_tail_init(&work_stats->rx_list, &work_stats->rx_pend_list);
	spin_unlock_bh(&work_stats->rx_pend_list.lock);

	queue_work(work_stats->wq, &work_stats->rx_work);
	work_stats->rx_works++;
}

u32 rnic_vnet_set_max_rx_qlen(u32 val)
{
	struct rnic_vnet_rx_wq_ctx_s *work_stats = work_stats_ptr;

	work_stats->max_rx_qlen = val;
	pr_err("rnic_vnet_set_max_rx_qlen val = %d\n", work_stats->max_rx_qlen);
	return 0;
}

STATIC void rnic_vnet_rx_work(struct work_struct *work)
{
	struct rnic_vnet_rx_wq_ctx_s *w_stats = work_stats_ptr;
	struct sk_buff *skb = NULL;
	struct sk_buff_head rx_wq_list;
	void (*gro_rcv_burst)(struct sk_buff_head *) = NULL;
	u32 cpu_total_num, pkt_num, cur_pkt_num;
	int cpu;

	skb_queue_head_init(&rx_wq_list);

	spin_lock_bh(&w_stats->rx_pend_list.lock);
	skb_queue_splice_tail_init(&w_stats->rx_pend_list, &rx_wq_list);
	spin_unlock_bh(&w_stats->rx_pend_list.lock);

	cpu_total_num = 0;
	for (cpu = 0; cpu < NR_CPUS; cpu++) {
		cpu_total_num += skb_queue_len(&per_cpu(softnet_data, cpu).input_pkt_queue);
		cpu_total_num += skb_queue_len(&per_cpu(softnet_data, cpu).process_queue);
	}

	cur_pkt_num = skb_queue_len(&w_stats->rx_list)
			+ skb_queue_len(&rx_wq_list)
			+ skb_queue_len(&w_stats->rx_pend_list);
	w_stats->rx_pend_pkts = cur_pkt_num + cpu_total_num;
	if (unlikely(w_stats->rx_pend_pkts > w_stats->max_rx_qlen)) {
		pkt_num = skb_queue_len(&rx_wq_list);
		w_stats->rx_queue_errs += pkt_num;
		skb_queue_purge(&rx_wq_list);
		return;
	}

	if (unlikely(skb_queue_empty(&rx_wq_list)))
		return;

	rcu_read_lock();
	gro_rcv_burst = rcu_dereference(rnic_gro_rcv_burst_entry);
	if (gro_rcv_burst != NULL)
		gro_rcv_burst(&rx_wq_list);
	rcu_read_unlock();

	while ((skb = __skb_dequeue(&rx_wq_list)) != NULL) {
#ifdef CONFIG_DRA_PAGE
		if (rnic_mem_flag_is_set(skb)) {
			skb = rnic_construct_skb_one(skb);
			if (unlikely(skb == NULL))
				continue;
		}
#endif
		rnic_vnet_deliver_skb(netdev_priv(skb->dev), skb);
	}
}

void rnic_vnet_rx_wq_init(void)
{
	struct rnic_vnet_rx_wq_ctx_s *work_stats = kzalloc(sizeof(*work_stats_ptr), GFP_KERNEL);

	skb_queue_head_init(&work_stats->rx_list);
	skb_queue_head_init(&work_stats->rx_pend_list);

	work_stats->wq = alloc_workqueue("rnic_rx_wq", WQ_HIGHPRI | WQ_MEM_RECLAIM | WQ_UNBOUND, 1);
	if (unlikely(!work_stats->wq)) {
		pr_err("rnic_vnet_rx_wq_init failed");
		kfree(work_stats);
		return;
	}

	work_stats->max_rx_qlen = RNIC_MAX_RX_QLEN;
	work_stats->enabled = rnic_rx_sched_enable;

	INIT_WORK(&work_stats->rx_work, rnic_vnet_rx_work);

	work_stats_ptr = work_stats;
}

u32 rnic_vnet_work_status(void)
{
	struct rnic_vnet_rx_wq_ctx_s *work_stats = work_stats_ptr;

	RNIC_LOGH("max_rx_qlen = %d", work_stats->max_rx_qlen);
	RNIC_LOGH("rx_pend_pkts = %d", work_stats->rx_pend_pkts);
	RNIC_LOGH("rx_queue_errs = %d", work_stats->rx_queue_errs);
	RNIC_LOGH("rx_work = %d", work_stats->rx_works);
	return 0;
}

void rnic_vnet_rx_wq_deinit(void)
{
	struct rnic_vnet_rx_wq_ctx_s *work_stats = work_stats_ptr;

	if (work_stats == NULL)
		return;

	if (work_stats->rx_work.func != NULL)
		cancel_work_sync(&work_stats->rx_work);
	if (work_stats->wq != NULL) {
		flush_workqueue(work_stats->wq);
		destroy_workqueue(work_stats->wq);
	}

	kfree(work_stats);
	work_stats_ptr = NULL;
}
