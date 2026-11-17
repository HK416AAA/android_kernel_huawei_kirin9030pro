/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
#include <linux/in.h>
#include <linux/in6.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include <linux/icmp.h>
#include <linux/workqueue.h>
#include <linux/sched.h>
#include <linux/module.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>
#include <net/inet_sock.h>

#include "rnic_nll2_lp_interface.h"
#include "rnic_dsm_msg_pif.h"
#include "rnic_vnet.h"
#include "rnic_private.h"
#include "rnic_data.h"
#include "rnic_log.h"
#include "rnic_vnet_hdlr.h"
#include "rnic_vnet.h"
#include "rnic_qos.h"

STATIC unsigned int __read_mostly rnic_qos_sock_name_check = 1;
module_param(rnic_qos_sock_name_check, uint, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(rnic_qos_sock_name_check, "rnic_qos_sock_name_check");

STATIC unsigned int __read_mostly rnic_qos_rate_adjust_ref_rate_kbps = 1350;
module_param(rnic_qos_rate_adjust_ref_rate_kbps, uint, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(rnic_qos_rate_adjust_ref_rate_kbps, "rnic_qos_rate_adjust_ref_rate_kbps");

STATIC unsigned int __read_mostly rnic_qos_rate_adjust_desc_win_ms = 4000;
module_param(rnic_qos_rate_adjust_desc_win_ms, uint, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(rnic_qos_rate_adjust_desc_win_ms, "rnic_qos_rate_adjust_desc_win_ms");

STATIC unsigned int __read_mostly rnic_qos_rate_adjust_buf_win1_ms = 2800;
module_param(rnic_qos_rate_adjust_buf_win1_ms, uint, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(rnic_qos_rate_adjust_buf_win1_ms, "rnic_qos_rate_adjust_buf_win1_ms");

STATIC unsigned int __read_mostly rnic_qos_rate_adjust_buf_win2_ms = 3800;
module_param(rnic_qos_rate_adjust_buf_win2_ms, uint, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(rnic_qos_rate_adjust_buf_win2_ms, "rnic_qos_rate_adjust_buf_win2_ms");

STATIC unsigned int __read_mostly rnic_qos_rate_adjust_brk_win_ms = 10000;
module_param(rnic_qos_rate_adjust_brk_win_ms, uint, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(rnic_qos_rate_adjust_brk_win_ms, "rnic_qos_rate_adjust_brk_win_ms");

STATIC unsigned int __read_mostly rnic_qos_rate_adjust_esc_win_ms = 30000;
module_param(rnic_qos_rate_adjust_esc_win_ms, uint, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(rnic_qos_rate_adjust_esc_win_ms, "rnic_qos_rate_adjust_esc_win_ms");

#define RNIC_QOS_REF_U16_NV_NUM 0
#define RNIC_QOS_DESC_U16_NV_NUM 1
#define RNIC_QOS_BUF_W1_U16_NV_NUM 2
#define RNIC_QOS_BUF_W2_U16_NV_NUM 3
#define RNIC_QOS_BRK_WIN_U16_NV_NUM 4
#define RNIC_QOS_ESC_WIN_U16_NV_NUM 5

#define RNIC_QOS_SK_NAME_CHECK_U8_NV_NUM 0

/* Use integer arithmetic (unit: millibytes, 1 byte = 1000 millibytes) */
#define RNIC_QOS_KBITS_TO_MBYTES(_kbits) ((u64)(_kbits) * 1000 * 1000 / 8) /* kbits/s -> millibytes/s */
#define RNIC_QOS_BYTES_TO_MBYTES(_bytes) ((u64)(_bytes) * 1000)            /* bytes/s -> millibytes/s */
#define RNIC_QOS_MBYTES_TO_BYTES(_mbytes) ((_mbytes) / 1000)               /* millibytes/s -> bytes/s */
#define RNIC_QOS_MBYTES_TO_KBITS(_mbytes) ((_mbytes) * 8 / 1000 / 1000)    /* millibytes/s -> kbits/s */

#define RNIC_QOS_STATS_INTVL_MS         200
#define RNIC_QOS_STATS_PREPARE_COUNT    25
#define RNIC_QOS_STATS_INIT_RATE_MBYTES RNIC_QOS_KBITS_TO_MBYTES(900)

#define RNIC_QOS_TOKEN_UPDATE_INTVL_MS 10
#define RNIC_QOS_TOKEN_RATE_ALPHA      90
#define RNIC_QOS_TOKEN_BURST_MS        140
#define RNIC_QOS_TOKEN_RATE_CALC(_mbytes) ((_mbytes) * RNIC_QOS_TOKEN_RATE_ALPHA / 100)
#define RNIC_QOS_TOKEN_CAPACITY_CALC(_mbytes) ((_mbytes) * RNIC_QOS_TOKEN_BURST_MS / 1000)

#define RNIC_QOS_EWMA_BASE_ALPHA   80
#define RNIC_QOS_EWMA_ADJUST_ALPHA 70
#define RNIC_QOS_EWMA_TREND_ALPHA  80
#define RNIC_QOS_EWMA_RATE_ALPHA_CALC(_new, _old, _alpha) (((_new) * (100 - (_alpha)) + (_old) * (_alpha)) / 100)

#define RNIC_QOS_ADJ_DESC_WIN_MS   rnic_qos_rate_adjust_desc_win_ms
#define RNIC_QOS_ADJ_BUF_WIN1_MS   rnic_qos_rate_adjust_buf_win1_ms
#define RNIC_QOS_ADJ_BUF_WIN2_MS   rnic_qos_rate_adjust_buf_win2_ms
#define RNIC_QOS_ADJ_BRK_WIN_MS    rnic_qos_rate_adjust_brk_win_ms
#define RNIC_QOS_ADJ_ESC_WIN_MS    rnic_qos_rate_adjust_esc_win_ms
#define RNIC_QOS_ADJ_REF_RATE      RNIC_QOS_KBITS_TO_MBYTES(rnic_qos_rate_adjust_ref_rate_kbps)
#define RNIC_QOS_ADJ_TGT_RATE_HT_CALC(_mbytes) ((_mbytes) * 110 / 100)
#define RNIC_QOS_ADJ_TGT_RATE_LT_CALC(_mbytes) ((_mbytes) * 105 / 100)
#define RNIC_QOS_ADJ_DESC_RATE_CALC(_mbytes) ((_mbytes) * 70 / 100)
#define RNIC_QOS_ADJ_BUF_SIZE_CALC(_mbytes, _ms) (RNIC_QOS_MBYTES_TO_BYTES((_mbytes) * (_ms) / MSEC_PER_SEC))

enum rnic_qos_state_e {
	RNIC_QOS_STA_IDLE,
	RNIC_QOS_STA_ACTIVE,
	RNIC_QOS_STA_ESCAPE,
};

enum rnic_qos_adj_state_e {
	RNIC_QOS_ADJ_STA_IDLE,
	RNIC_QOS_ADJ_STA_ACTIVE,
};

enum rnic_qos_adj_enter_case_e {
	RNIC_QOS_ADJ_ENTER_CASE_INPUT,
	RNIC_QOS_ADJ_ENTER_CASE_INSTANT,
	RNIC_QOS_ADJ_ENTER_CASE_BUTT,
};

enum rnic_qos_adj_probe_case_e {
	RNIC_QOS_ADJ_PROBE_CASE_DESCENT,
	RNIC_QOS_ADJ_PROBE_CASE_TIMEOUT,
	RNIC_QOS_ADJ_PROBE_CASE_BUTT,
};

enum rnic_qos_adj_leave_case_e {
	RNIC_QOS_ADJ_LEAVE_CASE_TARGET,
	RNIC_QOS_ADJ_LEAVE_CASE_DESCENT,
	RNIC_QOS_ADJ_LEAVE_CASE_TIMEOUT,
	RNIC_QOS_ADJ_LEAVE_CASE_ESCAPE,
	RNIC_QOS_ADJ_LEAVE_CASE_BUTT
};

struct rnic_qos_ctx_s {
	struct rnic_handle_s *handle;
	u32 uid;
	spinlock_t lock;
	enum rnic_qos_state_e state;

	struct sk_buff_head skb_list;
	u32 buf_size;

	/* Token generation related parameters */
	u64 token_rate_mb; /* Token rate (millibytes/s) */
	u64 capacity_mb; /* Token bucket capacity (millibytes) */
	u64 tokens_mb;   /* Token quantity (millibytes) */
	ktime_t last_update_ts;  /* Last token update time */
	struct hrtimer token_timer;

	/* Rate statistics related parameters */
	bool input_stats_ready;
	u32 input_stats_count;
	u64 instant_rate_mb; /* Instantaneous input rate (millibytes/s) */
	u64 input_rate_mb; /* Current input rate (millibytes/s) */
	u64 input_mb;  /* The cumulative number of bytes input (millibytes) */
	u64 last_input_rate_mb; /*Last input rate (millibytes/s) (for trend calculations) */
	u64 last_input_mb;  /* Last input data (millibytes) */
	ktime_t last_input_ts; /* Last input time rate */
	s64 rate_chg_mb; /* rate change */
	s64 rate_chg_trend; /* Rate change trend (negative value indicates decrease)*/
	s64 last_rate_chg_trend; /* The last rate change trend (negative value indicates a decrease) */

	/* Adjust related parameters */
	enum rnic_qos_adj_state_e adj_state;
	u64 adj_tgt_rate_mb; /* Adjust target rate (millibytes/s) */
	u64 adj_tgt_rate_ht_mb; /* Adjust the target rate higher limit (millibytes/s) */
	u64 adj_tgt_rate_lt_mb; /* Adjust the target rate lower limit (millibytes/s) */
	bool adj_enter;
	bool adj_probe;
	ktime_t adj_enter_ts; /* Timestamp when adjustment started */
	ktime_t adj_esc_chk_ts;
	u64 adj_desc_rate_mb;
	u64 adj_buf_rate_mb;
	u32 adj_buf_size;
};

struct rnic_qos_ctx_s *rnic_qos_ctx_ptr = NULL;

STATIC u32 rnic_qos_queue_head_buftime(struct rnic_qos_ctx_s *qctx, ktime_t now)
{
	struct sk_buff *skb = skb_peek(&qctx->skb_list);
	return (skb != NULL) ? (u32)ktime_ms_delta(now, skb->tstamp) : 0;
}

STATIC enum rnic_qos_adj_enter_case_e rnic_qos_adj_judge_enter(struct rnic_qos_ctx_s *qctx)
{
	if (qctx->input_rate_mb >= qctx->adj_tgt_rate_ht_mb)
		return RNIC_QOS_ADJ_ENTER_CASE_INPUT;
	else if (qctx->instant_rate_mb >= qctx->adj_tgt_rate_ht_mb)
		return RNIC_QOS_ADJ_ENTER_CASE_INSTANT;
	return RNIC_QOS_ADJ_ENTER_CASE_BUTT;
}

STATIC enum rnic_qos_adj_probe_case_e rnic_qos_adj_judge_probe(struct rnic_qos_ctx_s *qctx, ktime_t now)
{
	if (qctx->instant_rate_mb <= qctx->adj_desc_rate_mb && qctx->rate_chg_trend < 0)
		return RNIC_QOS_ADJ_PROBE_CASE_DESCENT;
	else if (ktime_ms_delta(now, qctx->adj_enter_ts) >= RNIC_QOS_ADJ_DESC_WIN_MS)
		return RNIC_QOS_ADJ_PROBE_CASE_TIMEOUT;
	return RNIC_QOS_ADJ_PROBE_CASE_BUTT;
}

STATIC enum rnic_qos_adj_leave_case_e rnic_qos_adj_judge_leave(struct rnic_qos_ctx_s *qctx, ktime_t now)
{
	enum rnic_qos_adj_leave_case_e levae_case = RNIC_QOS_ADJ_LEAVE_CASE_BUTT;

	if (qctx->input_rate_mb <= qctx->adj_tgt_rate_lt_mb && qctx->rate_chg_trend <= 0) {
		levae_case = RNIC_QOS_ADJ_LEAVE_CASE_TARGET;
	} else {
		if (qctx->input_rate_mb <= qctx->adj_desc_rate_mb)
			levae_case = RNIC_QOS_ADJ_LEAVE_CASE_DESCENT;
		else if (ktime_ms_delta(now, qctx->adj_enter_ts) >= RNIC_QOS_ADJ_BRK_WIN_MS)
			levae_case = RNIC_QOS_ADJ_LEAVE_CASE_TIMEOUT;

		if (unlikely(ktime_ms_delta(now, qctx->adj_esc_chk_ts) >= RNIC_QOS_ADJ_ESC_WIN_MS))
			levae_case = RNIC_QOS_ADJ_LEAVE_CASE_ESCAPE;
	}

	return levae_case;
}

STATIC void rnic_qos_adj_print(struct rnic_qos_ctx_s *qctx, const char *str1, const char *str2)
{
	RNIC_DIAG_LOGH("[QOS_ADJ] <%s%s> inst_rt %llu input_rt %llu buf_rt %llu desc_rt %llu trend %lld cur_buf %u adj_buf %u",
			str1, str2,
			RNIC_QOS_MBYTES_TO_KBITS(qctx->instant_rate_mb),
			RNIC_QOS_MBYTES_TO_KBITS(qctx->input_rate_mb),
			RNIC_QOS_MBYTES_TO_KBITS(qctx->adj_buf_rate_mb),
			RNIC_QOS_MBYTES_TO_KBITS(qctx->adj_desc_rate_mb),
			RNIC_QOS_MBYTES_TO_KBITS(qctx->rate_chg_trend),
			qctx->buf_size, qctx->adj_buf_size);
}

STATIC void rnic_qos_adj_enter_proc(struct rnic_qos_ctx_s *qctx, ktime_t now)
{
	enum rnic_qos_adj_enter_case_e enter_case = rnic_qos_adj_judge_enter(qctx);
	char *case_str[] = {
		[RNIC_QOS_ADJ_ENTER_CASE_INPUT] = "input",
		[RNIC_QOS_ADJ_ENTER_CASE_INSTANT] = "instant",
	};

	if (enter_case == RNIC_QOS_ADJ_ENTER_CASE_BUTT)
		return;

	qctx->adj_enter = true;
	qctx->adj_probe = false;
	qctx->adj_enter_ts = now;
	if (qctx->adj_esc_chk_ts == 0)
		qctx->adj_esc_chk_ts = now;
	qctx->adj_buf_rate_mb = max(qctx->input_rate_mb, RNIC_QOS_ADJ_REF_RATE);
	qctx->adj_desc_rate_mb = RNIC_QOS_ADJ_DESC_RATE_CALC(qctx->input_rate_mb);
	qctx->adj_buf_size = 0;
	qctx->tokens_mb = 0;

	rnic_qos_adj_print(qctx, "enter_", case_str[enter_case]);
}

STATIC void rnic_qos_adj_probe_proc(struct rnic_qos_ctx_s *qctx, ktime_t now)
{
	enum rnic_qos_adj_probe_case_e probe_case = rnic_qos_adj_judge_probe(qctx, now);
	char *case_str[] = {
		[RNIC_QOS_ADJ_PROBE_CASE_DESCENT] = "desc",
		[RNIC_QOS_ADJ_PROBE_CASE_TIMEOUT] = "timeo",
	};

	if (probe_case == RNIC_QOS_ADJ_PROBE_CASE_BUTT)
		return;

	qctx->adj_probe = true;
	qctx->adj_buf_size = RNIC_QOS_ADJ_BUF_SIZE_CALC(qctx->adj_buf_rate_mb - qctx->token_rate_mb,
							(probe_case == RNIC_QOS_ADJ_PROBE_CASE_DESCENT ?
							 RNIC_QOS_ADJ_BUF_WIN1_MS : RNIC_QOS_ADJ_BUF_WIN2_MS));

	rnic_qos_adj_print(qctx, "probe_", case_str[probe_case]);
}

STATIC void rnic_qos_adj_leave_proc(struct rnic_qos_ctx_s *qctx, ktime_t now)
{
	enum rnic_qos_adj_leave_case_e leave_case = rnic_qos_adj_judge_leave(qctx, now);
	char *case_str[] = {
		[RNIC_QOS_ADJ_LEAVE_CASE_TARGET] = "target",
		[RNIC_QOS_ADJ_LEAVE_CASE_DESCENT] = "desc",
		[RNIC_QOS_ADJ_LEAVE_CASE_TIMEOUT] = "timeo",
		[RNIC_QOS_ADJ_LEAVE_CASE_ESCAPE] = "escape",
	};

	if (leave_case == RNIC_QOS_ADJ_LEAVE_CASE_BUTT)
		return;

	qctx->adj_enter = false;
	qctx->adj_probe = false;

	if (leave_case == RNIC_QOS_ADJ_LEAVE_CASE_TARGET) {
		qctx->adj_esc_chk_ts = 0;
	} else if (leave_case == RNIC_QOS_ADJ_LEAVE_CASE_ESCAPE) {
		qctx->state = RNIC_QOS_STA_ESCAPE;
	}

	rnic_qos_adj_print(qctx, "leave_", case_str[leave_case]);
}

STATIC void rnic_qos_try_to_adjust(struct rnic_qos_ctx_s *qctx, ktime_t now)
{
	if (!qctx->adj_enter) {
		rnic_qos_adj_enter_proc(qctx, now);
	} else {
		if (!qctx->adj_probe)
			rnic_qos_adj_probe_proc(qctx, now);
		rnic_qos_adj_leave_proc(qctx, now);
	}
}

STATIC bool rnic_qos_update_input_rate(struct rnic_qos_ctx_s *qctx, u32 packet_size, ktime_t now)
{
	u64 packet_mb = RNIC_QOS_BYTES_TO_MBYTES(packet_size);
	u64 input_mb_delta;
	u64 instant_rate_mb;
	u32 elapsed_ms;

	/* First input processing */
	if (unlikely(qctx->input_mb == 0)) {
		qctx->last_input_ts = now;
		qctx->input_mb = packet_mb;
		qctx->last_input_mb = 0;
		return false;
	}

	/* The accumulated number of bytes (millibytes) */
	qctx->input_mb += packet_mb;

	/* Calculate time diff (ms), Update rate at least 200ms */
	elapsed_ms = (u32)ktime_ms_delta(now, qctx->last_input_ts);
	if (elapsed_ms < RNIC_QOS_STATS_INTVL_MS)
		return false;

	input_mb_delta = qctx->input_mb - qctx->last_input_mb;
	/* Calculate instantaneous rate (millibytes/s) */
	/* Note: elapsed_ms transform to s (elapsed_ms / 1000.0) Use integer arithmetic  */
	instant_rate_mb = (input_mb_delta * MSEC_PER_SEC) / elapsed_ms;

	/* Update sampling times */
	if (!qctx->input_stats_ready && ++qctx->input_stats_count >= RNIC_QOS_STATS_PREPARE_COUNT)
		qctx->input_stats_ready = true;

	/* Save the last input rate for trend calculation */
	qctx->last_input_rate_mb = qctx->input_rate_mb;

	/* Use EWMA to smooth the rate (integer arithmetic simulation) */
	/* alpha=0.8: input_rate = instant_rate * (1 - alpha) + input_rate * alpha */
	qctx->input_rate_mb = RNIC_QOS_EWMA_RATE_ALPHA_CALC(instant_rate_mb, qctx->input_rate_mb,
					!qctx->adj_enter ? RNIC_QOS_EWMA_BASE_ALPHA : RNIC_QOS_EWMA_ADJUST_ALPHA);
	qctx->instant_rate_mb = instant_rate_mb;

	/* Update rate changes */
	if (qctx->last_input_rate_mb != 0) {
		/* Save the last rate change trend */
		qctx->last_rate_chg_trend = qctx->rate_chg_trend;

		/* Use EWMA to smooth the rate (integer arithmetic simulation) */
		/* alpha=0.8: rate_change = rate_change * (1 - alpha) + old_trend * alpha */
		qctx->rate_chg_mb = (s64)qctx->input_rate_mb - (s64)qctx->last_input_rate_mb;
		qctx->rate_chg_trend = RNIC_QOS_EWMA_RATE_ALPHA_CALC(
						qctx->rate_chg_mb, qctx->rate_chg_trend, RNIC_QOS_EWMA_TREND_ALPHA);
	}

	/* Reset sample rate */
	qctx->last_input_mb = qctx->input_mb;
	qctx->last_input_ts = now;

	RNIC_DIAG_LOGH("[QOS_STATS] <update> inst_rt %llu input_rt %llu trend %lld curr_buf %u buf_time %u",
			RNIC_QOS_MBYTES_TO_KBITS(instant_rate_mb),
			RNIC_QOS_MBYTES_TO_KBITS(qctx->input_rate_mb),
			RNIC_QOS_MBYTES_TO_KBITS(qctx->rate_chg_trend),
			qctx->buf_size, rnic_qos_queue_head_buftime(qctx, now));
	return true;
}

STATIC void rnic_qos_update_input_stats_and_adjust(struct rnic_qos_ctx_s *qctx, u32 packet_size, ktime_t now)
{
	if (rnic_qos_update_input_rate(qctx, packet_size, now)) {
		if (qctx->input_stats_ready)
			rnic_qos_try_to_adjust(qctx, now);
	}
}

STATIC void rnic_qos_update_token_bucket(struct rnic_qos_ctx_s *qctx, ktime_t now)
{
	u64 elapsed_us = ktime_us_delta(now, qctx->last_update_ts);

	qctx->tokens_mb += qctx->token_rate_mb * elapsed_us / USEC_PER_SEC;
	qctx->tokens_mb = min(qctx->tokens_mb, qctx->capacity_mb);
	qctx->last_update_ts = now;
}

STATIC void rnic_qos_send_data_nolock(struct rnic_qos_ctx_s *qctx, ktime_t now)
{
	struct rnic_handle_s *handle = qctx->handle;
	struct sk_buff *skb = NULL;
	struct sk_buff *tmp = NULL;

	rnic_qos_update_token_bucket(qctx, now);
	skb_queue_walk_safe(&qctx->skb_list, skb, tmp) {
		u32 packet_size = skb->len - ETH_HLEN;
		if (qctx->adj_enter) {
			u64 packet_mb = RNIC_QOS_BYTES_TO_MBYTES(packet_size);
			if (qctx->tokens_mb >= packet_mb) {
				qctx->tokens_mb -= packet_mb;
			} else {
				if (qctx->adj_probe && qctx->buf_size > qctx->adj_buf_size)
					goto send_direct;
				else
					return;
			}
		}

send_direct:
		__skb_unlink(skb, &qctx->skb_list);
		qctx->buf_size -= packet_size;
		handle->ops->tx_data(handle, skb);
	}
}

int rnic_qos_xmit(struct sk_buff *skb)
{
	struct rnic_qos_ctx_s *qctx = rnic_qos_ctx_ptr;
	u32 packet_size = skb->len - ETH_HLEN;
	ktime_t now = ktime_get();

	if (!(rnic_mem_flag(skb) & RNIC_MEMF_QOS) || unlikely(qctx == NULL))
		goto err_out;

	spin_lock_bh(&qctx->lock);
	if (unlikely(qctx->state == RNIC_QOS_STA_IDLE || qctx->state == RNIC_QOS_STA_ESCAPE))
		goto err_out_unlock;

	if (likely(qctx->adj_state == RNIC_QOS_ADJ_STA_IDLE)) {
		rnic_qos_update_input_rate(qctx, packet_size, now);
		goto err_out_unlock;
	}

	skb->tstamp = now;
	__skb_queue_tail(&qctx->skb_list, skb);
	qctx->buf_size += packet_size;
	rnic_qos_update_input_stats_and_adjust(qctx, packet_size, now);

	rnic_qos_send_data_nolock(qctx, now);
	spin_unlock_bh(&qctx->lock);
	return 0;

err_out_unlock:
	spin_unlock_bh(&qctx->lock);
err_out:
	return -EFAULT;
}

STATIC enum hrtimer_restart rnic_qos_token_update_handler(struct hrtimer *htimer)
{
	struct rnic_qos_ctx_s *qctx = container_of(htimer, struct rnic_qos_ctx_s, token_timer);
	ktime_t now = ktime_get();

	spin_lock_bh(&qctx->lock);
	rnic_qos_send_data_nolock(qctx, now);
	if (qctx->adj_state == RNIC_QOS_ADJ_STA_ACTIVE) {
		spin_unlock_bh(&qctx->lock);
		hrtimer_forward_now(&qctx->token_timer, ms_to_ktime(RNIC_QOS_TOKEN_UPDATE_INTVL_MS));
		return HRTIMER_RESTART;
	}
	spin_unlock_bh(&qctx->lock);
	return HRTIMER_NORESTART;
}

STATIC void rnic_qos_start_token_update_timer(struct rnic_qos_ctx_s *qctx)
{
	if (!hrtimer_active(&qctx->token_timer))
		hrtimer_start(&qctx->token_timer, ms_to_ktime(RNIC_QOS_TOKEN_UPDATE_INTVL_MS), HRTIMER_MODE_REL_SOFT);
}

STATIC void rnic_qos_stop_token_update_timer(struct rnic_qos_ctx_s *qctx)
{
	hrtimer_cancel(&qctx->token_timer);
}

STATIC void rnic_qos_input_stats_init(struct rnic_qos_ctx_s *qctx)
{
	qctx->instant_rate_mb = 0;
	qctx->input_mb = 0;
	qctx->input_rate_mb = RNIC_QOS_STATS_INIT_RATE_MBYTES;
	qctx->last_input_mb = 0;
	qctx->last_input_rate_mb = 0;
	qctx->last_input_ts = 0;

	qctx->rate_chg_mb = 0;
	qctx->rate_chg_trend = 0;
	qctx->last_rate_chg_trend = 0;

	qctx->input_stats_ready = false;
	qctx->input_stats_count = 0;
}

STATIC void rnic_qos_token_bucket_config(struct rnic_qos_ctx_s *qctx, u64 rate_mb)
{
	qctx->token_rate_mb = RNIC_QOS_TOKEN_RATE_CALC(rate_mb);
	qctx->capacity_mb = RNIC_QOS_TOKEN_CAPACITY_CALC(qctx->token_rate_mb);
	qctx->tokens_mb = qctx->capacity_mb;
	qctx->last_update_ts = rate_mb != 0 ? ktime_get() : 0;
}

STATIC void rnic_qos_adjust_config(struct rnic_qos_ctx_s *qctx, u16 tgt_rate_kbits)
{
	qctx->adj_state = tgt_rate_kbits != 0 ? RNIC_QOS_ADJ_STA_ACTIVE : RNIC_QOS_ADJ_STA_IDLE;
	qctx->adj_tgt_rate_mb = RNIC_QOS_KBITS_TO_MBYTES(tgt_rate_kbits);
	qctx->adj_tgt_rate_ht_mb = RNIC_QOS_ADJ_TGT_RATE_HT_CALC(qctx->adj_tgt_rate_mb);
	qctx->adj_tgt_rate_lt_mb = RNIC_QOS_ADJ_TGT_RATE_LT_CALC(qctx->adj_tgt_rate_mb);
	qctx->adj_enter = false;
	qctx->adj_probe = false;
	qctx->adj_enter_ts = 0;
	qctx->adj_esc_chk_ts = 0;
	qctx->adj_desc_rate_mb = 0;
	qctx->adj_buf_rate_mb = 0;
	qctx->adj_buf_size = 0;
}

STATIC void rnic_qos_flush_nolock(struct rnic_qos_ctx_s *qctx)
{
	struct rnic_handle_s *handle = qctx->handle;
	struct sk_buff *skb = NULL;

	while ((skb = __skb_dequeue(&qctx->skb_list)) != NULL)
		handle->ops->tx_data(handle, skb);
	qctx->buf_size = 0;
}

STATIC void rnic_qos_start_adjust(struct rnic_qos_ctx_s *qctx, u16 tgt_rate_kbits)
{
	rnic_qos_adjust_config(qctx, tgt_rate_kbits);
	rnic_qos_token_bucket_config(qctx, qctx->adj_tgt_rate_mb);
	rnic_qos_start_token_update_timer(qctx);
}

STATIC void rnic_qos_stop_adjust(struct rnic_qos_ctx_s *qctx)
{
	rnic_qos_adjust_config(qctx, 0);
	rnic_qos_token_bucket_config(qctx, 0);
	rnic_qos_stop_token_update_timer(qctx);
	rnic_qos_flush_nolock(qctx);
}

STATIC void rnic_qos_secnce_config(struct rnic_qos_ctx_s *qctx, bool active)
{
	rnic_qos_input_stats_init(qctx);
	qctx->state = active ? RNIC_QOS_STA_ACTIVE : RNIC_QOS_STA_IDLE;
}

STATIC void rnic_qos_rate_adjust_cfg(struct rnic_qos_ctx_s *qctx, const void *data)
{
	struct nll2_rnic_rate_adjust_ind_s *ind = (struct nll2_rnic_rate_adjust_ind_s *)data;

	RNIC_DIAG_LOGH("[QOS_CFG] <rate_adjust> rate_high_thr %d", ind->rate_high_thr);

	if (ind->msg_head.msg_length < sizeof(*ind))
		return;

	if (ind->adjust_flag) {
		/* start adjust */
		spin_lock_bh(&qctx->lock);
		rnic_qos_start_adjust(qctx, ind->rate_high_thr);
		spin_unlock_bh(&qctx->lock);
	} else {
		/* stop adjust */
		spin_lock_bh(&qctx->lock);
		rnic_qos_stop_adjust(qctx);
		spin_unlock_bh(&qctx->lock);
	}
}

STATIC void rnic_qos_state_cfg(struct rnic_qos_ctx_s *qctx, const void *data)
{
	struct nll2_rnic_voip_state_ind_s *ind = (struct nll2_rnic_voip_state_ind_s *)data;

	if (ind->msg_head.msg_length < sizeof(*ind))
		return;

	RNIC_DIAG_LOGH("[QOS_CFG] <qos_state> state %d uid %u", ind->voip_state, ind->app_uid);

	if (ind->voip_state == NLL2_RNIC_VOIP_START) {
		/* activate */
		spin_lock_bh(&qctx->lock);
		rnic_qos_secnce_config(qctx, true);
		spin_unlock_bh(&qctx->lock);
		qctx->uid = ind->app_uid;
	} else if (ind->voip_state ==NLL2_RNIC_VOIP_STOP) {
		/* deactivate */
		qctx->uid = U32_MAX;
		spin_lock_bh(&qctx->lock);
		rnic_qos_stop_adjust(qctx);
		rnic_qos_secnce_config(qctx, false);
		spin_unlock_bh(&qctx->lock);
	}
}

void rnic_qos_msglite_config(const void *data)
{
	struct rnic_qos_ctx_s *qctx = rnic_qos_ctx_ptr;
	struct rnic_nll2_msg_head_s *head = (struct rnic_nll2_msg_head_s *)data;

	if (unlikely(qctx == NULL))
		return;

	switch(head->msg_type) {
	case ID_NLL2_RNIC_VOIP_STATE_IND:
		rnic_qos_state_cfg(qctx, data);
		break;
	case ID_NLL2_RNIC_RATE_ADJUST_IND:
		rnic_qos_rate_adjust_cfg(qctx, data);
		break;
	default:
		break;
	}
}

void rnic_qos_nv_conifg(const void *cfg)
{
	const struct rnic_vnet_fea_cfg_s *vcfg = (const struct rnic_vnet_fea_cfg_s *)cfg;
	const struct rnic_qos_fea_cfg_s *qcfg = &vcfg->qos_cfg;

	rnic_qos_rate_adjust_ref_rate_kbps	= qcfg->u16_para[RNIC_QOS_REF_U16_NV_NUM];
	rnic_qos_rate_adjust_desc_win_ms	= qcfg->u16_para[RNIC_QOS_DESC_U16_NV_NUM];
	rnic_qos_rate_adjust_buf_win1_ms	= qcfg->u16_para[RNIC_QOS_BUF_W1_U16_NV_NUM];
	rnic_qos_rate_adjust_buf_win2_ms	= qcfg->u16_para[RNIC_QOS_BUF_W2_U16_NV_NUM];
	rnic_qos_rate_adjust_brk_win_ms		= qcfg->u16_para[RNIC_QOS_BRK_WIN_U16_NV_NUM];
	rnic_qos_rate_adjust_esc_win_ms		= qcfg->u16_para[RNIC_QOS_ESC_WIN_U16_NV_NUM];

	rnic_qos_sock_name_check		= qcfg->u8_para[RNIC_QOS_SK_NAME_CHECK_U8_NV_NUM];
}

bool rnic_qos_sock_matched(struct sock *sk)
{
	struct rnic_qos_ctx_s *qctx = rnic_qos_ctx_ptr;

	RNIC_LOGI("qos_uid %d, sk_uid %d, full_sk %d, proto %d, pid %d, name %s",
		  qctx->uid, (sk ? sk->sk_uid.val : -1), (sk ? sk_fullsock(sk) : -1), (sk ? sk->sk_protocol : -1),
		  current->pid, current->comm);

	if (unlikely(qctx == NULL))
		return false;

	if (sk->sk_uid.val != qctx->uid)
		return false;

	if (!(sk->sk_protocol == IPPROTO_UDP || sk->sk_protocol == IPPROTO_ICMP || sk->sk_protocol == IPPROTO_ICMPV6))
		return false;

	if (!!rnic_qos_sock_name_check) {
		const char *comm = current->comm;
		RNIC_LOGI("[2] pid %d comm %s", current->pid, comm);
		return (strncmp(comm, "voip", strlen("voip")) == 0);
	}

	return true;
}

void rnic_qos_init(struct rnic_handle_s *handle)
{
	struct rnic_qos_ctx_s *qctx = NULL;

	qctx = kzalloc(sizeof(*qctx), GFP_KERNEL);
	if (unlikely(qctx == NULL)) {
		RNIC_LOGE("alloc qos ctx failed");
		return;
	}

	qctx->handle = handle;
	qctx->uid = U32_MAX;
	spin_lock_init(&qctx->lock);
	skb_queue_head_init(&qctx->skb_list);
	hrtimer_init(&qctx->token_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL_SOFT);
	qctx->token_timer.function = rnic_qos_token_update_handler;
	rnic_qos_ctx_ptr = qctx;
}

void rnic_qos_deinit(void)
{
	struct rnic_qos_ctx_s *qctx = rnic_qos_ctx_ptr;

	if (qctx)
		kfree(qctx);

	rnic_qos_ctx_ptr = NULL;
}